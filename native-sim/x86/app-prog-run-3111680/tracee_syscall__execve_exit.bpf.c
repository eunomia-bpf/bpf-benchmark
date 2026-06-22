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

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_0(
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
	/* 0x15: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x2b: je     207 <syscall__execve_exit+0x207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_207;
	}
x86_l_31:
	/* 0x31: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_34:
	/* 0x34: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x4a: je     207 <syscall__execve_exit+0x207> */
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
	/* 0x57: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x6b: je     207 <syscall__execve_exit+0x207> */
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
	/* 0x78: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x8c: je     207 <syscall__execve_exit+0x207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_207;
	}
x86_l_92:
	/* 0x92: cmp    QWORD PTR [r13+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_9a:
	/* 0x9a: je     20e <syscall__execve_exit+0x20e> */
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
	/* 0xb0: mov    DWORD PTR [rbp+0x70],0x3b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337211ULL);
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
	/* 0x12e: mov    DWORD PTR [rsp+0x10],0x3b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476795ULL);
x86_l_136:
	/* 0x136: mov    WORD PTR [rsp+0x4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13b:
	/* 0x13b: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x151: je     207 <syscall__execve_exit+0x207> */
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
	/* 0x169: je     207 <syscall__execve_exit+0x207> */
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
	/* 0x1eb: jne    218 <syscall__execve_exit+0x218> */
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
	/* 0x1fc: jne    a10 <syscall__execve_exit+0xa10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2576ULL;
	}
x86_l_202:
	/* 0x202: jmp    11e7 <syscall__execve_exit+0x11e7> */
	return 4583ULL;
x86_l_207:
	/* 0x207: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_209:
	/* 0x209: jmp    11e7 <syscall__execve_exit+0x11e7> */
	return 4583ULL;
x86_l_20e:
	/* 0x20e: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_213:
	/* 0x213: jmp    11e7 <syscall__execve_exit+0x11e7> */
	return 4583ULL;
x86_l_218:
	/* 0x218: mov    rax,QWORD PTR [rbp+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_21f:
	/* 0x21f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_222:
	/* 0x222: je     3d2 <syscall__execve_exit+0x3d2> */
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
	/* 0x257: je     27d <syscall__execve_exit+0x27d> */
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
	/* 0x287: je     2a2 <syscall__execve_exit+0x2a2> */
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
	/* 0x2ac: je     2ca <syscall__execve_exit+0x2ca> */
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
	/* 0x2df: je     43f <syscall__execve_exit+0x43f> */
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
	/* 0x31a: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x342: je     364 <syscall__execve_exit+0x364> */
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
	/* 0x356: je     364 <syscall__execve_exit+0x364> */
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
	/* 0x362: jmp    366 <syscall__execve_exit+0x366> */
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
	/* 0x37b: jb     393 <syscall__execve_exit+0x393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_393;
	}
x86_l_37d:
	/* 0x37d: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_381:
	/* 0x381: je     388 <syscall__execve_exit+0x388> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_388;
	}
x86_l_383:
	/* 0x383: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_386:
	/* 0x386: jbe    393 <syscall__execve_exit+0x393> */
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
	/* 0x3ab: je     3ee <syscall__execve_exit+0x3ee> */
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
	/* 0x3c4: je     3fa <syscall__execve_exit+0x3fa> */
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
	/* 0x3d0: jmp    3fc <syscall__execve_exit+0x3fc> */
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
	/* 0x3e3: jne    259 <syscall__execve_exit+0x259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_259;
	}
x86_l_3e9:
	/* 0x3e9: jmp    27d <syscall__execve_exit+0x27d> */
	goto x86_l_27d;
x86_l_3ee:
	/* 0x3ee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f0:
	/* 0x3f0: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3f8:
	/* 0x3f8: jmp    40e <syscall__execve_exit+0x40e> */
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
	/* 0x419: jb     431 <syscall__execve_exit+0x431> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_431;
	}
x86_l_41b:
	/* 0x41b: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_41f:
	/* 0x41f: je     426 <syscall__execve_exit+0x426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_426;
	}
x86_l_421:
	/* 0x421: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_424:
	/* 0x424: jbe    431 <syscall__execve_exit+0x431> */
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
	/* 0x447: je     4ff <syscall__execve_exit+0x4ff> */
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
	/* 0x483: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x4ab: je     4ca <syscall__execve_exit+0x4ca> */
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
	/* 0x4bc: je     4ca <syscall__execve_exit+0x4ca> */
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
	/* 0x4c8: jmp    4cc <syscall__execve_exit+0x4cc> */
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
	/* 0x4da: jb     4f4 <syscall__execve_exit+0x4f4> */
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
	/* 0x4e5: je     4ec <syscall__execve_exit+0x4ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ec;
	}
x86_l_4e7:
	/* 0x4e7: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_4ea:
	/* 0x4ea: jbe    4f4 <syscall__execve_exit+0x4f4> */
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
	/* 0x507: je     5de <syscall__execve_exit+0x5de> */
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
	/* 0x589: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x5a9: je     5ca <syscall__execve_exit+0x5ca> */
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
	/* 0x5bc: je     5ca <syscall__execve_exit+0x5ca> */
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
	/* 0x5c8: jmp    5cc <syscall__execve_exit+0x5cc> */
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
	/* 0x5e6: je     6e0 <syscall__execve_exit+0x6e0> */
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
	/* 0x68b: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x6ab: je     6cc <syscall__execve_exit+0x6cc> */
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
	/* 0x6be: je     6cc <syscall__execve_exit+0x6cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1740ULL;
	}
x86_l_6c0:
	/* 0x6c0: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 1731ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_1(
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
	case 2586ULL: goto x86_l_a1a;
	case 2592ULL: goto x86_l_a20;
	case 2594ULL: goto x86_l_a22;
	case 2599ULL: goto x86_l_a27;
	case 2604ULL: goto x86_l_a2c;
	case 2609ULL: goto x86_l_a31;
	case 2614ULL: goto x86_l_a36;
	case 2618ULL: goto x86_l_a3a;
	case 2626ULL: goto x86_l_a42;
	case 2633ULL: goto x86_l_a49;
	case 2640ULL: goto x86_l_a50;
	case 2647ULL: goto x86_l_a57;
	case 2652ULL: goto x86_l_a5c;
	case 2654ULL: goto x86_l_a5e;
	case 2657ULL: goto x86_l_a61;
	case 2664ULL: goto x86_l_a68;
	case 2669ULL: goto x86_l_a6d;
	case 2674ULL: goto x86_l_a72;
	case 2681ULL: goto x86_l_a79;
	case 2685ULL: goto x86_l_a7d;
	case 2692ULL: goto x86_l_a84;
	case 2697ULL: goto x86_l_a89;
	case 2699ULL: goto x86_l_a8b;
	case 2701ULL: goto x86_l_a8d;
	case 2703ULL: goto x86_l_a8f;
	case 2706ULL: goto x86_l_a92;
	case 2713ULL: goto x86_l_a99;
	case 2715ULL: goto x86_l_a9b;
	case 2722ULL: goto x86_l_aa2;
	case 2729ULL: goto x86_l_aa9;
	case 2732ULL: goto x86_l_aac;
	case 2739ULL: goto x86_l_ab3;
	case 2745ULL: goto x86_l_ab9;
	case 2747ULL: goto x86_l_abb;
	case 2749ULL: goto x86_l_abd;
	case 2752ULL: goto x86_l_ac0;
	case 2755ULL: goto x86_l_ac3;
	case 2760ULL: goto x86_l_ac8;
	case 2766ULL: goto x86_l_ace;
	case 2770ULL: goto x86_l_ad2;
	case 2778ULL: goto x86_l_ada;
	case 2786ULL: goto x86_l_ae2;
	case 2790ULL: goto x86_l_ae6;
	case 2797ULL: goto x86_l_aed;
	case 2806ULL: goto x86_l_af6;
	case 2811ULL: goto x86_l_afb;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2826ULL: goto x86_l_b0a;
	case 2829ULL: goto x86_l_b0d;
	case 2831ULL: goto x86_l_b0f;
	case 2836ULL: goto x86_l_b14;
	case 2839ULL: goto x86_l_b17;
	case 2841ULL: goto x86_l_b19;
	case 2844ULL: goto x86_l_b1c;
	case 2850ULL: goto x86_l_b22;
	case 2852ULL: goto x86_l_b24;
	case 2856ULL: goto x86_l_b28;
	case 2863ULL: goto x86_l_b2f;
	case 2868ULL: goto x86_l_b34;
	case 2873ULL: goto x86_l_b39;
	case 2880ULL: goto x86_l_b40;
	case 2884ULL: goto x86_l_b44;
	case 2891ULL: goto x86_l_b4b;
	case 2896ULL: goto x86_l_b50;
	case 2901ULL: goto x86_l_b55;
	case 2903ULL: goto x86_l_b57;
	case 2907ULL: goto x86_l_b5b;
	case 2909ULL: goto x86_l_b5d;
	case 2911ULL: goto x86_l_b5f;
	case 2914ULL: goto x86_l_b62;
	case 2920ULL: goto x86_l_b68;
	case 2926ULL: goto x86_l_b6e;
	case 2928ULL: goto x86_l_b70;
	case 2933ULL: goto x86_l_b75;
	case 2938ULL: goto x86_l_b7a;
	case 2945ULL: goto x86_l_b81;
	case 2950ULL: goto x86_l_b86;
	case 2952ULL: goto x86_l_b88;
	case 2960ULL: goto x86_l_b90;
	case 2966ULL: goto x86_l_b96;
	case 2972ULL: goto x86_l_b9c;
	case 2978ULL: goto x86_l_ba2;
	case 2981ULL: goto x86_l_ba5;
	case 2987ULL: goto x86_l_bab;
	case 2993ULL: goto x86_l_bb1;
	case 3000ULL: goto x86_l_bb8;
	case 3008ULL: goto x86_l_bc0;
	case 3016ULL: goto x86_l_bc8;
	case 3020ULL: goto x86_l_bcc;
	case 3027ULL: goto x86_l_bd3;
	case 3036ULL: goto x86_l_bdc;
	case 3041ULL: goto x86_l_be1;
	case 3046ULL: goto x86_l_be6;
	case 3051ULL: goto x86_l_beb;
	case 3056ULL: goto x86_l_bf0;
	case 3059ULL: goto x86_l_bf3;
	case 3061ULL: goto x86_l_bf5;
	case 3066ULL: goto x86_l_bfa;
	case 3069ULL: goto x86_l_bfd;
	case 3071ULL: goto x86_l_bff;
	case 3074ULL: goto x86_l_c02;
	case 3080ULL: goto x86_l_c08;
	case 3082ULL: goto x86_l_c0a;
	case 3086ULL: goto x86_l_c0e;
	case 3093ULL: goto x86_l_c15;
	case 3098ULL: goto x86_l_c1a;
	case 3103ULL: goto x86_l_c1f;
	case 3110ULL: goto x86_l_c26;
	case 3114ULL: goto x86_l_c2a;
	case 3121ULL: goto x86_l_c31;
	case 3126ULL: goto x86_l_c36;
	case 3131ULL: goto x86_l_c3b;
	case 3133ULL: goto x86_l_c3d;
	case 3137ULL: goto x86_l_c41;
	case 3139ULL: goto x86_l_c43;
	case 3141ULL: goto x86_l_c45;
	case 3144ULL: goto x86_l_c48;
	case 3150ULL: goto x86_l_c4e;
	case 3156ULL: goto x86_l_c54;
	case 3158ULL: goto x86_l_c56;
	case 3163ULL: goto x86_l_c5b;
	case 3170ULL: goto x86_l_c62;
	case 3175ULL: goto x86_l_c67;
	case 3177ULL: goto x86_l_c69;
	case 3185ULL: goto x86_l_c71;
	case 3191ULL: goto x86_l_c77;
	case 3194ULL: goto x86_l_c7a;
	case 3201ULL: goto x86_l_c81;
	case 3203ULL: goto x86_l_c83;
	case 3211ULL: goto x86_l_c8b;
	case 3217ULL: goto x86_l_c91;
	case 3219ULL: goto x86_l_c93;
	case 3222ULL: goto x86_l_c96;
	case 3229ULL: goto x86_l_c9d;
	case 3233ULL: goto x86_l_ca1;
	case 3240ULL: goto x86_l_ca8;
	case 3245ULL: goto x86_l_cad;
	case 3250ULL: goto x86_l_cb2;
	case 3255ULL: goto x86_l_cb7;
	case 3257ULL: goto x86_l_cb9;
	case 3260ULL: goto x86_l_cbc;
	case 3262ULL: goto x86_l_cbe;
	case 3265ULL: goto x86_l_cc1;
	case 3272ULL: goto x86_l_cc8;
	case 3278ULL: goto x86_l_cce;
	case 3285ULL: goto x86_l_cd5;
	case 3289ULL: goto x86_l_cd9;
	case 3294ULL: goto x86_l_cde;
	case 3299ULL: goto x86_l_ce3;
	case 3304ULL: goto x86_l_ce8;
	case 3309ULL: goto x86_l_ced;
	case 3312ULL: goto x86_l_cf0;
	case 3314ULL: goto x86_l_cf2;
	case 3319ULL: goto x86_l_cf7;
	case 3324ULL: goto x86_l_cfc;
	case 3328ULL: goto x86_l_d00;
	case 3333ULL: goto x86_l_d05;
	case 3338ULL: goto x86_l_d0a;
	case 3343ULL: goto x86_l_d0f;
	case 3348ULL: goto x86_l_d14;
	case 3350ULL: goto x86_l_d16;
	case 3355ULL: goto x86_l_d1b;
	case 3359ULL: goto x86_l_d1f;
	case 3364ULL: goto x86_l_d24;
	case 3369ULL: goto x86_l_d29;
	case 3374ULL: goto x86_l_d2e;
	case 3379ULL: goto x86_l_d33;
	case 3381ULL: goto x86_l_d35;
	case 3384ULL: goto x86_l_d38;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6c3:
	/* 0x6c3: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c7:
	/* 0x6c7: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_6ca:
	/* 0x6ca: jmp    6ce <syscall__execve_exit+0x6ce> */
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
	/* 0x6e8: je     7d1 <syscall__execve_exit+0x7d1> */
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
	/* 0x778: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x798: je     7b8 <syscall__execve_exit+0x7b8> */
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
	/* 0x7aa: je     7b8 <syscall__execve_exit+0x7b8> */
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
	/* 0x7b6: jmp    7ba <syscall__execve_exit+0x7ba> */
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
	/* 0x7d9: je     864 <syscall__execve_exit+0x864> */
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
	/* 0x80b: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x82b: je     84b <syscall__execve_exit+0x84b> */
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
	/* 0x83d: je     84b <syscall__execve_exit+0x84b> */
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
	/* 0x849: jmp    84d <syscall__execve_exit+0x84d> */
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
	/* 0x86e: je     8da <syscall__execve_exit+0x8da> */
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
	/* 0x884: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x8a4: je     8c6 <syscall__execve_exit+0x8c6> */
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
	/* 0x8b8: je     8c6 <syscall__execve_exit+0x8c6> */
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
	/* 0x8c4: jmp    8c8 <syscall__execve_exit+0x8c8> */
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
	/* 0x8e4: je     947 <syscall__execve_exit+0x947> */
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
	/* 0x8f3: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x913: je     933 <syscall__execve_exit+0x933> */
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
	/* 0x925: je     933 <syscall__execve_exit+0x933> */
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
	/* 0x931: jmp    935 <syscall__execve_exit+0x935> */
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
	/* 0x951: je     9d8 <syscall__execve_exit+0x9d8> */
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
	/* 0x964: mov    rdi,QWORD PTR [rip+0x5747] */
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
	/* 0x984: je     9c5 <syscall__execve_exit+0x9c5> */
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
	/* 0x99f: jne    9b9 <syscall__execve_exit+0x9b9> */
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
	/* 0x9b7: je     9c5 <syscall__execve_exit+0x9c5> */
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
	/* 0x9c3: jmp    9c7 <syscall__execve_exit+0x9c7> */
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
	/* 0x9e2: je     9f0 <syscall__execve_exit+0x9f0> */
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
	/* 0xa0a: je     11e7 <syscall__execve_exit+0x11e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4583ULL;
	}
x86_l_a10:
	/* 0xa10: lea    rbx,[rbp+0x7d8a] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_a17:
	/* 0xa17: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a1a:
	/* 0xa1a: cmp    rax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32000ULL);
x86_l_a20:
	/* 0xa20: jb     a31 <syscall__execve_exit+0xa31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a31;
	}
x86_l_a22:
	/* 0xa22: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a27:
	/* 0xa27: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a2c:
	/* 0xa2c: jmp    b96 <syscall__execve_exit+0xb96> */
	goto x86_l_b96;
x86_l_a31:
	/* 0xa31: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a36:
	/* 0xa36: mov    rdx,QWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a3a:
	/* 0xa3a: mov    BYTE PTR [rbp+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_a42:
	/* 0xa42: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_a49:
	/* 0xa49: mov    WORD PTR [rbp+0x7d8c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_a50:
	/* 0xa50: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_a57:
	/* 0xa57: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a5c:
	/* 0xa5c: ja     ac0 <syscall__execve_exit+0xac0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ac0;
	}
x86_l_a5e:
	/* 0xa5e: add    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a61:
	/* 0xa61: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_a68:
	/* 0xa68: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_a6d:
	/* 0xa6d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_a72:
	/* 0xa72: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_a79:
	/* 0xa79: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_a7d:
	/* 0xa7d: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_a84:
	/* 0xa84: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_a89:
	/* 0xa89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a8b:
	/* 0xa8b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a8d:
	/* 0xa8d: jle    abd <syscall__execve_exit+0xabd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_abd;
	}
x86_l_a8f:
	/* 0xa8f: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a92:
	/* 0xa92: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_a99:
	/* 0xa99: ja     ac0 <syscall__execve_exit+0xac0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ac0;
	}
x86_l_a9b:
	/* 0xa9b: mov    DWORD PTR [rcx+rbp*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 138ULL);
x86_l_aa2:
	/* 0xaa2: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_aa9:
	/* 0xaa9: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_aac:
	/* 0xaac: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_ab3:
	/* 0xab3: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_ab9:
	/* 0xab9: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_abb:
	/* 0xabb: jmp    ac0 <syscall__execve_exit+0xac0> */
	goto x86_l_ac0;
x86_l_abd:
	/* 0xabd: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ac0:
	/* 0xac0: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ac3:
	/* 0xac3: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_ac8:
	/* 0xac8: ja     b96 <syscall__execve_exit+0xb96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b96;
	}
x86_l_ace:
	/* 0xace: mov    r13,QWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ad2:
	/* 0xad2: mov    BYTE PTR [rbp+rax*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519553ULL);
x86_l_ada:
	/* 0xada: movzx  r15d,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_ae2:
	/* 0xae2: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_ae6:
	/* 0xae6: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_aed:
	/* 0xaed: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_af6:
	/* 0xaf6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_afb:
	/* 0xafb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b00:
	/* 0xb00: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b05:
	/* 0xb05: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b0a:
	/* 0xb0a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b0d:
	/* 0xb0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0f:
	/* 0xb0f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b14:
	/* 0xb14: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_b17:
	/* 0xb17: je     b6e <syscall__execve_exit+0xb6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b6e;
	}
x86_l_b19:
	/* 0xb19: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b1c:
	/* 0xb1c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_b22:
	/* 0xb22: ja     b6e <syscall__execve_exit+0xb6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b6e;
	}
x86_l_b24:
	/* 0xb24: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_b28:
	/* 0xb28: add    rdx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_b2f:
	/* 0xb2f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_b34:
	/* 0xb34: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_b39:
	/* 0xb39: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_b40:
	/* 0xb40: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_b44:
	/* 0xb44: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_b4b:
	/* 0xb4b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b50:
	/* 0xb50: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_b55:
	/* 0xb55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b57:
	/* 0xb57: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b5b:
	/* 0xb5b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b5d:
	/* 0xb5d: jle    b6e <syscall__execve_exit+0xb6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_b6e;
	}
x86_l_b5f:
	/* 0xb5f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b62:
	/* 0xb62: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_b68:
	/* 0xb68: jbe    11f6 <syscall__execve_exit+0x11f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4598ULL;
	}
x86_l_b6e:
	/* 0xb6e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b70:
	/* 0xb70: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b75:
	/* 0xb75: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b7a:
	/* 0xb7a: cmp    r15d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31998ULL);
x86_l_b81:
	/* 0xb81: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b86:
	/* 0xb86: ja     b96 <syscall__execve_exit+0xb96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b96;
	}
x86_l_b88:
	/* 0xb88: mov    BYTE PTR [rbp+r15*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_b90:
	/* 0xb90: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_b96:
	/* 0xb96: test   BYTE PTR [r12+0x4],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869185ULL);
x86_l_b9c:
	/* 0xb9c: je     c77 <syscall__execve_exit+0xc77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c77;
	}
x86_l_ba2:
	/* 0xba2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ba5:
	/* 0xba5: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_bab:
	/* 0xbab: ja     c77 <syscall__execve_exit+0xc77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c77;
	}
x86_l_bb1:
	/* 0xbb1: mov    r13,QWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bb8:
	/* 0xbb8: mov    BYTE PTR [rbp+rax*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519554ULL);
x86_l_bc0:
	/* 0xbc0: movzx  r15d,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_bc8:
	/* 0xbc8: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_bcc:
	/* 0xbcc: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_bd3:
	/* 0xbd3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_bdc:
	/* 0xbdc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_be1:
	/* 0xbe1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_be6:
	/* 0xbe6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_beb:
	/* 0xbeb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf0:
	/* 0xbf0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_bf3:
	/* 0xbf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf5:
	/* 0xbf5: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bfa:
	/* 0xbfa: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_bfd:
	/* 0xbfd: je     c54 <syscall__execve_exit+0xc54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c54;
	}
x86_l_bff:
	/* 0xbff: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c02:
	/* 0xc02: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_c08:
	/* 0xc08: ja     c54 <syscall__execve_exit+0xc54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c54;
	}
x86_l_c0a:
	/* 0xc0a: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_c0e:
	/* 0xc0e: add    rdx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_c15:
	/* 0xc15: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_c1a:
	/* 0xc1a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_c1f:
	/* 0xc1f: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_c26:
	/* 0xc26: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_c2a:
	/* 0xc2a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_c31:
	/* 0xc31: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c36:
	/* 0xc36: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_c3b:
	/* 0xc3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c3d:
	/* 0xc3d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c41:
	/* 0xc41: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c43:
	/* 0xc43: jle    c54 <syscall__execve_exit+0xc54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c54;
	}
x86_l_c45:
	/* 0xc45: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c48:
	/* 0xc48: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_c4e:
	/* 0xc4e: jbe    34cb <syscall__execve_exit+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13515ULL;
	}
x86_l_c54:
	/* 0xc54: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c56:
	/* 0xc56: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c5b:
	/* 0xc5b: cmp    r15d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31998ULL);
x86_l_c62:
	/* 0xc62: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c67:
	/* 0xc67: ja     c77 <syscall__execve_exit+0xc77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c77;
	}
x86_l_c69:
	/* 0xc69: mov    BYTE PTR [rbp+r15*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_c71:
	/* 0xc71: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_c77:
	/* 0xc77: movzx  ebx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c7a:
	/* 0xc7a: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_c81:
	/* 0xc81: ja     cce <syscall__execve_exit+0xcce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_cce;
	}
x86_l_c83:
	/* 0xc83: mov    BYTE PTR [rbp+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_c8b:
	/* 0xc8b: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_c91:
	/* 0xc91: ja     cce <syscall__execve_exit+0xcce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_cce;
	}
x86_l_c93:
	/* 0xc93: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c96:
	/* 0xc96: add    rdx,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_c9d:
	/* 0xc9d: lea    rdi,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_ca1:
	/* 0xca1: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_ca8:
	/* 0xca8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_cad:
	/* 0xcad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cb2:
	/* 0xcb2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cb7:
	/* 0xcb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb9:
	/* 0xcb9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cbc:
	/* 0xcbc: js     cce <syscall__execve_exit+0xcce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_cce;
	}
x86_l_cbe:
	/* 0xcbe: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_cc1:
	/* 0xcc1: mov    WORD PTR [rbp+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_cc8:
	/* 0xcc8: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_cce:
	/* 0xcce: mov    rbx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_cd5:
	/* 0xcd5: lea    r15,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cd9:
	/* 0xcd9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cde:
	/* 0xcde: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ce3:
	/* 0xce3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ce8:
	/* 0xce8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ced:
	/* 0xced: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_cf0:
	/* 0xcf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf2:
	/* 0xcf2: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cf7:
	/* 0xcf7: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_cfc:
	/* 0xcfc: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d00:
	/* 0xd00: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d05:
	/* 0xd05: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d0a:
	/* 0xd0a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d0f:
	/* 0xd0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d14:
	/* 0xd14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d16:
	/* 0xd16: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d1b:
	/* 0xd1b: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_d1f:
	/* 0xd1f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d24:
	/* 0xd24: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d29:
	/* 0xd29: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d2e:
	/* 0xd2e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d33:
	/* 0xd33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d35:
	/* 0xd35: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_d38:
	/* 0xd38: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 3389ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3389ULL: goto x86_l_d3d;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3403ULL: goto x86_l_d4b;
	case 3408ULL: goto x86_l_d50;
	case 3413ULL: goto x86_l_d55;
	case 3415ULL: goto x86_l_d57;
	case 3419ULL: goto x86_l_d5b;
	case 3423ULL: goto x86_l_d5f;
	case 3427ULL: goto x86_l_d63;
	case 3432ULL: goto x86_l_d68;
	case 3437ULL: goto x86_l_d6d;
	case 3442ULL: goto x86_l_d72;
	case 3447ULL: goto x86_l_d77;
	case 3450ULL: goto x86_l_d7a;
	case 3452ULL: goto x86_l_d7c;
	case 3457ULL: goto x86_l_d81;
	case 3462ULL: goto x86_l_d86;
	case 3467ULL: goto x86_l_d8b;
	case 3472ULL: goto x86_l_d90;
	case 3477ULL: goto x86_l_d95;
	case 3480ULL: goto x86_l_d98;
	case 3482ULL: goto x86_l_d9a;
	case 3486ULL: goto x86_l_d9e;
	case 3490ULL: goto x86_l_da2;
	case 3494ULL: goto x86_l_da6;
	case 3498ULL: goto x86_l_daa;
	case 3503ULL: goto x86_l_daf;
	case 3508ULL: goto x86_l_db4;
	case 3513ULL: goto x86_l_db9;
	case 3518ULL: goto x86_l_dbe;
	case 3520ULL: goto x86_l_dc0;
	case 3524ULL: goto x86_l_dc4;
	case 3528ULL: goto x86_l_dc8;
	case 3533ULL: goto x86_l_dcd;
	case 3538ULL: goto x86_l_dd2;
	case 3543ULL: goto x86_l_dd7;
	case 3548ULL: goto x86_l_ddc;
	case 3551ULL: goto x86_l_ddf;
	case 3553ULL: goto x86_l_de1;
	case 3558ULL: goto x86_l_de6;
	case 3562ULL: goto x86_l_dea;
	case 3567ULL: goto x86_l_def;
	case 3572ULL: goto x86_l_df4;
	case 3577ULL: goto x86_l_df9;
	case 3582ULL: goto x86_l_dfe;
	case 3584ULL: goto x86_l_e00;
	case 3589ULL: goto x86_l_e05;
	case 3594ULL: goto x86_l_e0a;
	case 3599ULL: goto x86_l_e0f;
	case 3604ULL: goto x86_l_e14;
	case 3609ULL: goto x86_l_e19;
	case 3612ULL: goto x86_l_e1c;
	case 3614ULL: goto x86_l_e1e;
	case 3618ULL: goto x86_l_e22;
	case 3622ULL: goto x86_l_e26;
	case 3626ULL: goto x86_l_e2a;
	case 3630ULL: goto x86_l_e2e;
	case 3635ULL: goto x86_l_e33;
	case 3640ULL: goto x86_l_e38;
	case 3645ULL: goto x86_l_e3d;
	case 3650ULL: goto x86_l_e42;
	case 3652ULL: goto x86_l_e44;
	case 3656ULL: goto x86_l_e48;
	case 3660ULL: goto x86_l_e4c;
	case 3665ULL: goto x86_l_e51;
	case 3670ULL: goto x86_l_e56;
	case 3675ULL: goto x86_l_e5b;
	case 3680ULL: goto x86_l_e60;
	case 3683ULL: goto x86_l_e63;
	case 3685ULL: goto x86_l_e65;
	case 3690ULL: goto x86_l_e6a;
	case 3695ULL: goto x86_l_e6f;
	case 3700ULL: goto x86_l_e74;
	case 3705ULL: goto x86_l_e79;
	case 3710ULL: goto x86_l_e7e;
	case 3713ULL: goto x86_l_e81;
	case 3715ULL: goto x86_l_e83;
	case 3719ULL: goto x86_l_e87;
	case 3723ULL: goto x86_l_e8b;
	case 3727ULL: goto x86_l_e8f;
	case 3731ULL: goto x86_l_e93;
	case 3736ULL: goto x86_l_e98;
	case 3741ULL: goto x86_l_e9d;
	case 3746ULL: goto x86_l_ea2;
	case 3751ULL: goto x86_l_ea7;
	case 3753ULL: goto x86_l_ea9;
	case 3758ULL: goto x86_l_eae;
	case 3762ULL: goto x86_l_eb2;
	case 3767ULL: goto x86_l_eb7;
	case 3772ULL: goto x86_l_ebc;
	case 3777ULL: goto x86_l_ec1;
	case 3782ULL: goto x86_l_ec6;
	case 3784ULL: goto x86_l_ec8;
	case 3789ULL: goto x86_l_ecd;
	case 3793ULL: goto x86_l_ed1;
	case 3798ULL: goto x86_l_ed6;
	case 3803ULL: goto x86_l_edb;
	case 3808ULL: goto x86_l_ee0;
	case 3813ULL: goto x86_l_ee5;
	case 3816ULL: goto x86_l_ee8;
	case 3818ULL: goto x86_l_eea;
	case 3823ULL: goto x86_l_eef;
	case 3828ULL: goto x86_l_ef4;
	case 3833ULL: goto x86_l_ef9;
	case 3838ULL: goto x86_l_efe;
	case 3843ULL: goto x86_l_f03;
	case 3846ULL: goto x86_l_f06;
	case 3848ULL: goto x86_l_f08;
	case 3852ULL: goto x86_l_f0c;
	case 3856ULL: goto x86_l_f10;
	case 3860ULL: goto x86_l_f14;
	case 3864ULL: goto x86_l_f18;
	case 3869ULL: goto x86_l_f1d;
	case 3874ULL: goto x86_l_f22;
	case 3879ULL: goto x86_l_f27;
	case 3884ULL: goto x86_l_f2c;
	case 3886ULL: goto x86_l_f2e;
	case 3891ULL: goto x86_l_f33;
	case 3895ULL: goto x86_l_f37;
	case 3900ULL: goto x86_l_f3c;
	case 3905ULL: goto x86_l_f41;
	case 3910ULL: goto x86_l_f46;
	case 3915ULL: goto x86_l_f4b;
	case 3917ULL: goto x86_l_f4d;
	case 3922ULL: goto x86_l_f52;
	case 3924ULL: goto x86_l_f54;
	case 3929ULL: goto x86_l_f59;
	case 3934ULL: goto x86_l_f5e;
	case 3939ULL: goto x86_l_f63;
	case 3944ULL: goto x86_l_f68;
	case 3947ULL: goto x86_l_f6b;
	case 3949ULL: goto x86_l_f6d;
	case 3954ULL: goto x86_l_f72;
	case 3959ULL: goto x86_l_f77;
	case 3964ULL: goto x86_l_f7c;
	case 3969ULL: goto x86_l_f81;
	case 3974ULL: goto x86_l_f86;
	case 3977ULL: goto x86_l_f89;
	case 3979ULL: goto x86_l_f8b;
	case 3983ULL: goto x86_l_f8f;
	case 3987ULL: goto x86_l_f93;
	case 3991ULL: goto x86_l_f97;
	case 3995ULL: goto x86_l_f9b;
	case 4000ULL: goto x86_l_fa0;
	case 4005ULL: goto x86_l_fa5;
	case 4010ULL: goto x86_l_faa;
	case 4015ULL: goto x86_l_faf;
	case 4017ULL: goto x86_l_fb1;
	case 4021ULL: goto x86_l_fb5;
	case 4025ULL: goto x86_l_fb9;
	case 4029ULL: goto x86_l_fbd;
	case 4036ULL: goto x86_l_fc4;
	case 4041ULL: goto x86_l_fc9;
	case 4046ULL: goto x86_l_fce;
	case 4051ULL: goto x86_l_fd3;
	case 4055ULL: goto x86_l_fd7;
	case 4060ULL: goto x86_l_fdc;
	case 4063ULL: goto x86_l_fdf;
	case 4065ULL: goto x86_l_fe1;
	case 4070ULL: goto x86_l_fe6;
	case 4074ULL: goto x86_l_fea;
	case 4079ULL: goto x86_l_fef;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4094ULL: goto x86_l_ffe;
	case 4096ULL: goto x86_l_1000;
	case 4101ULL: goto x86_l_1005;
	case 4106ULL: goto x86_l_100a;
	case 4111ULL: goto x86_l_100f;
	case 4116ULL: goto x86_l_1014;
	case 4121ULL: goto x86_l_1019;
	case 4126ULL: goto x86_l_101e;
	case 4128ULL: goto x86_l_1020;
	case 4132ULL: goto x86_l_1024;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4143ULL: goto x86_l_102f;
	case 4147ULL: goto x86_l_1033;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4161ULL: goto x86_l_1041;
	case 4166ULL: goto x86_l_1046;
	case 4171ULL: goto x86_l_104b;
	case 4173ULL: goto x86_l_104d;
	case 4178ULL: goto x86_l_1052;
	case 4182ULL: goto x86_l_1056;
	case 4187ULL: goto x86_l_105b;
	case 4191ULL: goto x86_l_105f;
	case 4196ULL: goto x86_l_1064;
	case 4201ULL: goto x86_l_1069;
	case 4206ULL: goto x86_l_106e;
	case 4211ULL: goto x86_l_1073;
	case 4213ULL: goto x86_l_1075;
	case 4218ULL: goto x86_l_107a;
	case 4222ULL: goto x86_l_107e;
	case 4226ULL: goto x86_l_1082;
	case 4231ULL: goto x86_l_1087;
	case 4236ULL: goto x86_l_108c;
	case 4241ULL: goto x86_l_1091;
	case 4246ULL: goto x86_l_1096;
	case 4249ULL: goto x86_l_1099;
	case 4251ULL: goto x86_l_109b;
	case 4256ULL: goto x86_l_10a0;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4275ULL: goto x86_l_10b3;
	case 4280ULL: goto x86_l_10b8;
	case 4283ULL: goto x86_l_10bb;
	case 4285ULL: goto x86_l_10bd;
	case 4290ULL: goto x86_l_10c2;
	case 4292ULL: goto x86_l_10c4;
	case 4297ULL: goto x86_l_10c9;
	case 4305ULL: goto x86_l_10d1;
	case 4309ULL: goto x86_l_10d5;
	case 4317ULL: goto x86_l_10dd;
	case 4322ULL: goto x86_l_10e2;
	case 4327ULL: goto x86_l_10e7;
	case 4332ULL: goto x86_l_10ec;
	case 4334ULL: goto x86_l_10ee;
	case 4339ULL: goto x86_l_10f3;
	case 4344ULL: goto x86_l_10f8;
	case 4349ULL: goto x86_l_10fd;
	case 4354ULL: goto x86_l_1102;
	case 4357ULL: goto x86_l_1105;
	case 4359ULL: goto x86_l_1107;
	case 4364ULL: goto x86_l_110c;
	case 4369ULL: goto x86_l_1111;
	case 4374ULL: goto x86_l_1116;
	case 4379ULL: goto x86_l_111b;
	case 4384ULL: goto x86_l_1120;
	case 4386ULL: goto x86_l_1122;
	case 4391ULL: goto x86_l_1127;
	case 4396ULL: goto x86_l_112c;
	case 4401ULL: goto x86_l_1131;
	case 4406ULL: goto x86_l_1136;
	case 4409ULL: goto x86_l_1139;
	case 4414ULL: goto x86_l_113e;
	case 4416ULL: goto x86_l_1140;
	case 4419ULL: goto x86_l_1143;
	case 4423ULL: goto x86_l_1147;
	case 4428ULL: goto x86_l_114c;
	case 4433ULL: goto x86_l_1151;
	case 4438ULL: goto x86_l_1156;
	case 4441ULL: goto x86_l_1159;
	case 4443ULL: goto x86_l_115b;
	case 4448ULL: goto x86_l_1160;
	case 4453ULL: goto x86_l_1165;
	case 4458ULL: goto x86_l_116a;
	case 4463ULL: goto x86_l_116f;
	case 4466ULL: goto x86_l_1172;
	case 4468ULL: goto x86_l_1174;
	case 4473ULL: goto x86_l_1179;
	case 4477ULL: goto x86_l_117d;
	case 4485ULL: goto x86_l_1185;
	case 4487ULL: goto x86_l_1187;
	case 4494ULL: goto x86_l_118e;
	case 4499ULL: goto x86_l_1193;
	case 4504ULL: goto x86_l_1198;
	case 4509ULL: goto x86_l_119d;
	case 4512ULL: goto x86_l_11a0;
	case 4514ULL: goto x86_l_11a2;
	case 4516ULL: goto x86_l_11a4;
	case 4518ULL: goto x86_l_11a6;
	case 4522ULL: goto x86_l_11aa;
	case 4530ULL: goto x86_l_11b2;
	case 4535ULL: goto x86_l_11b7;
	case 4540ULL: goto x86_l_11bc;
	case 4543ULL: goto x86_l_11bf;
	case 4549ULL: goto x86_l_11c5;
	case 4553ULL: goto x86_l_11c9;
	case 4560ULL: goto x86_l_11d0;
	case 4565ULL: goto x86_l_11d5;
	case 4570ULL: goto x86_l_11da;
	case 4575ULL: goto x86_l_11df;
	case 4578ULL: goto x86_l_11e2;
	case 4581ULL: goto x86_l_11e5;
	case 4583ULL: goto x86_l_11e7;
	case 4590ULL: goto x86_l_11ee;
	case 4592ULL: goto x86_l_11f0;
	case 4593ULL: goto x86_l_11f1;
	case 4598ULL: goto x86_l_11f6;
	case 4602ULL: goto x86_l_11fa;
	case 4609ULL: goto x86_l_1201;
	case 4614ULL: goto x86_l_1206;
	case 4619ULL: goto x86_l_120b;
	case 4624ULL: goto x86_l_1210;
	case 4631ULL: goto x86_l_1217;
	case 4635ULL: goto x86_l_121b;
	case 4642ULL: goto x86_l_1222;
	case 4647ULL: goto x86_l_1227;
	case 4649ULL: goto x86_l_1229;
	case 4654ULL: goto x86_l_122e;
	case 4661ULL: goto x86_l_1235;
	case 4664ULL: goto x86_l_1238;
	case 4671ULL: goto x86_l_123f;
	case 4680ULL: goto x86_l_1248;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4694ULL: goto x86_l_1256;
	case 4699ULL: goto x86_l_125b;
	case 4704ULL: goto x86_l_1260;
	case 4706ULL: goto x86_l_1262;
	case 4711ULL: goto x86_l_1267;
	case 4713ULL: goto x86_l_1269;
	case 4716ULL: goto x86_l_126c;
	case 4722ULL: goto x86_l_1272;
	case 4725ULL: goto x86_l_1275;
	case 4731ULL: goto x86_l_127b;
	case 4737ULL: goto x86_l_1281;
	case 4742ULL: goto x86_l_1286;
	case 4746ULL: goto x86_l_128a;
	case 4753ULL: goto x86_l_1291;
	case 4758ULL: goto x86_l_1296;
	case 4763ULL: goto x86_l_129b;
	case 4770ULL: goto x86_l_12a2;
	case 4773ULL: goto x86_l_12a5;
	case 4780ULL: goto x86_l_12ac;
	case 4785ULL: goto x86_l_12b1;
	case 4790ULL: goto x86_l_12b6;
	case 4792ULL: goto x86_l_12b8;
	case 4796ULL: goto x86_l_12bc;
	case 4798ULL: goto x86_l_12be;
	case 4800ULL: goto x86_l_12c0;
	case 4806ULL: goto x86_l_12c6;
	case 4809ULL: goto x86_l_12c9;
	case 4815ULL: goto x86_l_12cf;
	case 4821ULL: goto x86_l_12d5;
	case 4826ULL: goto x86_l_12da;
	case 4830ULL: goto x86_l_12de;
	case 4837ULL: goto x86_l_12e5;
	case 4842ULL: goto x86_l_12ea;
	case 4847ULL: goto x86_l_12ef;
	case 4852ULL: goto x86_l_12f4;
	case 4860ULL: goto x86_l_12fc;
	case 4864ULL: goto x86_l_1300;
	case 4871ULL: goto x86_l_1307;
	case 4876ULL: goto x86_l_130c;
	case 4878ULL: goto x86_l_130e;
	case 4883ULL: goto x86_l_1313;
	case 4891ULL: goto x86_l_131b;
	case 4894ULL: goto x86_l_131e;
	case 4902ULL: goto x86_l_1326;
	case 4911ULL: goto x86_l_132f;
	case 4915ULL: goto x86_l_1333;
	case 4920ULL: goto x86_l_1338;
	case 4925ULL: goto x86_l_133d;
	case 4930ULL: goto x86_l_1342;
	case 4935ULL: goto x86_l_1347;
	case 4937ULL: goto x86_l_1349;
	case 4942ULL: goto x86_l_134e;
	case 4944ULL: goto x86_l_1350;
	case 4947ULL: goto x86_l_1353;
	case 4953ULL: goto x86_l_1359;
	case 4956ULL: goto x86_l_135c;
	case 4962ULL: goto x86_l_1362;
	case 4968ULL: goto x86_l_1368;
	case 4973ULL: goto x86_l_136d;
	case 4977ULL: goto x86_l_1371;
	case 4984ULL: goto x86_l_1378;
	case 4989ULL: goto x86_l_137d;
	case 4994ULL: goto x86_l_1382;
	case 5001ULL: goto x86_l_1389;
	case 5004ULL: goto x86_l_138c;
	case 5011ULL: goto x86_l_1393;
	case 5016ULL: goto x86_l_1398;
	case 5021ULL: goto x86_l_139d;
	case 5023ULL: goto x86_l_139f;
	case 5027ULL: goto x86_l_13a3;
	case 5029ULL: goto x86_l_13a5;
	case 5031ULL: goto x86_l_13a7;
	case 5037ULL: goto x86_l_13ad;
	case 5040ULL: goto x86_l_13b0;
	case 5046ULL: goto x86_l_13b6;
	case 5052ULL: goto x86_l_13bc;
	case 5057ULL: goto x86_l_13c1;
	case 5061ULL: goto x86_l_13c5;
	case 5068ULL: goto x86_l_13cc;
	case 5073ULL: goto x86_l_13d1;
	case 5078ULL: goto x86_l_13d6;
	case 5083ULL: goto x86_l_13db;
	case 5091ULL: goto x86_l_13e3;
	case 5095ULL: goto x86_l_13e7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d3d:
	/* 0xd3d: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_d41:
	/* 0xd41: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d46:
	/* 0xd46: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d4b:
	/* 0xd4b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d50:
	/* 0xd50: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d55:
	/* 0xd55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d57:
	/* 0xd57: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d5b:
	/* 0xd5b: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_d5f:
	/* 0xd5f: lea    r12,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0xd77: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d7a:
	/* 0xd7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7c:
	/* 0xd7c: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d81:
	/* 0xd81: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d86:
	/* 0xd86: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d8b:
	/* 0xd8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d90:
	/* 0xd90: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d95:
	/* 0xd95: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d98:
	/* 0xd98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d9a:
	/* 0xd9a: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d9e:
	/* 0xd9e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_da2:
	/* 0xda2: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_da6:
	/* 0xda6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_daa:
	/* 0xdaa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_daf:
	/* 0xdaf: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_db4:
	/* 0xdb4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_db9:
	/* 0xdb9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_dbe:
	/* 0xdbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc0:
	/* 0xdc0: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc4:
	/* 0xdc4: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_dc8:
	/* 0xdc8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dcd:
	/* 0xdcd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_dd2:
	/* 0xdd2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dd7:
	/* 0xdd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ddc:
	/* 0xddc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_ddf:
	/* 0xddf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de1:
	/* 0xde1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de6:
	/* 0xde6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_dea:
	/* 0xdea: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_def:
	/* 0xdef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_df4:
	/* 0xdf4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_df9:
	/* 0xdf9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dfe:
	/* 0xdfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e00:
	/* 0xe00: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e05:
	/* 0xe05: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e0a:
	/* 0xe0a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e0f:
	/* 0xe0f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e14:
	/* 0xe14: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e19:
	/* 0xe19: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e1c:
	/* 0xe1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e1e:
	/* 0xe1e: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e22:
	/* 0xe22: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_e26:
	/* 0xe26: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_e2a:
	/* 0xe2a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e2e:
	/* 0xe2e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e33:
	/* 0xe33: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e38:
	/* 0xe38: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e3d:
	/* 0xe3d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e42:
	/* 0xe42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e44:
	/* 0xe44: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e48:
	/* 0xe48: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e4c:
	/* 0xe4c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e51:
	/* 0xe51: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e56:
	/* 0xe56: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e5b:
	/* 0xe5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e60:
	/* 0xe60: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e63:
	/* 0xe63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e65:
	/* 0xe65: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e6a:
	/* 0xe6a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e6f:
	/* 0xe6f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e74:
	/* 0xe74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e79:
	/* 0xe79: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e7e:
	/* 0xe7e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e81:
	/* 0xe81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e83:
	/* 0xe83: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e87:
	/* 0xe87: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_e8b:
	/* 0xe8b: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_e8f:
	/* 0xe8f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e93:
	/* 0xe93: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e98:
	/* 0xe98: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e9d:
	/* 0xe9d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ea2:
	/* 0xea2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ea7:
	/* 0xea7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea9:
	/* 0xea9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eae:
	/* 0xeae: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_eb2:
	/* 0xeb2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb7:
	/* 0xeb7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ebc:
	/* 0xebc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ec1:
	/* 0xec1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ec6:
	/* 0xec6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec8:
	/* 0xec8: mov    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ecd:
	/* 0xecd: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ed1:
	/* 0xed1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ed6:
	/* 0xed6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_edb:
	/* 0xedb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ee0:
	/* 0xee0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ee5:
	/* 0xee5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_ee8:
	/* 0xee8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eea:
	/* 0xeea: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eef:
	/* 0xeef: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ef4:
	/* 0xef4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ef9:
	/* 0xef9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_efe:
	/* 0xefe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f03:
	/* 0xf03: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f06:
	/* 0xf06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f08:
	/* 0xf08: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f0c:
	/* 0xf0c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_f10:
	/* 0xf10: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f14:
	/* 0xf14: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f18:
	/* 0xf18: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f1d:
	/* 0xf1d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f22:
	/* 0xf22: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f27:
	/* 0xf27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f2c:
	/* 0xf2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2e:
	/* 0xf2e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f33:
	/* 0xf33: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_f37:
	/* 0xf37: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f3c:
	/* 0xf3c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f41:
	/* 0xf41: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f46:
	/* 0xf46: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f4b:
	/* 0xf4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4d:
	/* 0xf4d: cmp    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_f52:
	/* 0xf52: jne    fb9 <syscall__execve_exit+0xfb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fb9;
	}
x86_l_f54:
	/* 0xf54: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f59:
	/* 0xf59: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f5e:
	/* 0xf5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f63:
	/* 0xf63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f68:
	/* 0xf68: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f6b:
	/* 0xf6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6d:
	/* 0xf6d: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f72:
	/* 0xf72: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f77:
	/* 0xf77: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f7c:
	/* 0xf7c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f81:
	/* 0xf81: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f86:
	/* 0xf86: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f89:
	/* 0xf89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8b:
	/* 0xf8b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f8f:
	/* 0xf8f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_f93:
	/* 0xf93: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f97:
	/* 0xf97: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_f9b:
	/* 0xf9b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fa0:
	/* 0xfa0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_fa5:
	/* 0xfa5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_faa:
	/* 0xfaa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_faf:
	/* 0xfaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb1:
	/* 0xfb1: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fb5:
	/* 0xfb5: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fb9:
	/* 0xfb9: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fbd:
	/* 0xfbd: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_fc4:
	/* 0xfc4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fc9:
	/* 0xfc9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fce:
	/* 0xfce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fd3:
	/* 0xfd3: lea    r15,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fd7:
	/* 0xfd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fdc:
	/* 0xfdc: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_fdf:
	/* 0xfdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe1:
	/* 0xfe1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe6:
	/* 0xfe6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fea:
	/* 0xfea: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fef:
	/* 0xfef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ff4:
	/* 0xff4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ff9:
	/* 0xff9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ffe:
	/* 0xffe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1000:
	/* 0x1000: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1005:
	/* 0x1005: lea    rdi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_100a:
	/* 0x100a: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_100f:
	/* 0x100f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1014:
	/* 0x1014: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1019:
	/* 0x1019: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_101e:
	/* 0x101e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1020:
	/* 0x1020: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1024:
	/* 0x1024: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1028:
	/* 0x1028: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_102d:
	/* 0x102d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_102f:
	/* 0x102f: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1033:
	/* 0x1033: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1037:
	/* 0x1037: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_103c:
	/* 0x103c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1041:
	/* 0x1041: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1046:
	/* 0x1046: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_104b:
	/* 0x104b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_104d:
	/* 0x104d: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1052:
	/* 0x1052: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1056:
	/* 0x1056: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_105b:
	/* 0x105b: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_105f:
	/* 0x105f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1064:
	/* 0x1064: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1069:
	/* 0x1069: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_106e:
	/* 0x106e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1073:
	/* 0x1073: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1075:
	/* 0x1075: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_107a:
	/* 0x107a: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_107e:
	/* 0x107e: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1082:
	/* 0x1082: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1087:
	/* 0x1087: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_108c:
	/* 0x108c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1091:
	/* 0x1091: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1096:
	/* 0x1096: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1099:
	/* 0x1099: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109b:
	/* 0x109b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10a0:
	/* 0x10a0: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_10a4:
	/* 0x10a4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10a9:
	/* 0x10a9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10ae:
	/* 0x10ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10b3:
	/* 0x10b3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10b8:
	/* 0x10b8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_10bb:
	/* 0x10bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10bd:
	/* 0x10bd: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_10c2:
	/* 0x10c2: je     10c9 <syscall__execve_exit+0x10c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c9;
	}
x86_l_10c4:
	/* 0x10c4: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_10c9:
	/* 0x10c9: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_10d1:
	/* 0x10d1: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_10d5:
	/* 0x10d5: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_10dd:
	/* 0x10dd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_10e2:
	/* 0x10e2: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_10e7:
	/* 0x10e7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_10ec:
	/* 0x10ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ee:
	/* 0x10ee: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10f3:
	/* 0x10f3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10f8:
	/* 0x10f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10fd:
	/* 0x10fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1102:
	/* 0x1102: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1105:
	/* 0x1105: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1107:
	/* 0x1107: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_110c:
	/* 0x110c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1111:
	/* 0x1111: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1116:
	/* 0x1116: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_111b:
	/* 0x111b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1120:
	/* 0x1120: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1122:
	/* 0x1122: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1127:
	/* 0x1127: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_112c:
	/* 0x112c: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_1131:
	/* 0x1131: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1136:
	/* 0x1136: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1139:
	/* 0x1139: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_113e:
	/* 0x113e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1140:
	/* 0x1140: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1143:
	/* 0x1143: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1147:
	/* 0x1147: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_114c:
	/* 0x114c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1151:
	/* 0x1151: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1156:
	/* 0x1156: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1159:
	/* 0x1159: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_115b:
	/* 0x115b: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_1160:
	/* 0x1160: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1165:
	/* 0x1165: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_116a:
	/* 0x116a: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_116f:
	/* 0x116f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1172:
	/* 0x1172: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1174:
	/* 0x1174: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1179:
	/* 0x1179: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_117d:
	/* 0x117d: mov    rbx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1185:
	/* 0x1185: je     11aa <syscall__execve_exit+0x11aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11aa;
	}
x86_l_1187:
	/* 0x1187: mov    rsi,QWORD PTR [rip+0x5747] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_118e:
	/* 0x118e: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_1193:
	/* 0x1193: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1198:
	/* 0x1198: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_119d:
	/* 0x119d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11a0:
	/* 0x11a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a2:
	/* 0x11a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11a4:
	/* 0x11a4: js     11aa <syscall__execve_exit+0x11aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_11aa;
	}
x86_l_11a6:
	/* 0x11a6: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_11aa:
	/* 0x11aa: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_11b2:
	/* 0x11b2: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_11b7:
	/* 0x11b7: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_11bc:
	/* 0x11bc: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_11bf:
	/* 0x11bf: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_11c5:
	/* 0x11c5: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11c9:
	/* 0x11c9: mov    rsi,QWORD PTR [rip+0x5747] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_11d0:
	/* 0x11d0: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_11d5:
	/* 0x11d5: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_11da:
	/* 0x11da: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_11df:
	/* 0x11df: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11e2:
	/* 0x11e2: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_11e5:
	/* 0x11e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11e7:
	/* 0x11e7: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_11ee:
	/* 0x11ee: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_11f0:
	/* 0x11f0: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_11f1:
	/* 0x11f1: jmp    578c <syscall__execve_exit+0x578c> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_11f6:
	/* 0x11f6: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_11fa:
	/* 0x11fa: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1201:
	/* 0x1201: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1206:
	/* 0x1206: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_120b:
	/* 0x120b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1210:
	/* 0x1210: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1217:
	/* 0x1217: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_121b:
	/* 0x121b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1222:
	/* 0x1222: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1227:
	/* 0x1227: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1229:
	/* 0x1229: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_122e:
	/* 0x122e: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1235:
	/* 0x1235: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1238:
	/* 0x1238: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_123f:
	/* 0x123f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1248:
	/* 0x1248: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_124c:
	/* 0x124c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1251:
	/* 0x1251: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1256:
	/* 0x1256: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_125b:
	/* 0x125b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1260:
	/* 0x1260: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1262:
	/* 0x1262: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1267:
	/* 0x1267: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1269:
	/* 0x1269: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_126c:
	/* 0x126c: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_1272:
	/* 0x1272: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1275:
	/* 0x1275: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_127b:
	/* 0x127b: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1281:
	/* 0x1281: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1286:
	/* 0x1286: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_128a:
	/* 0x128a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1291:
	/* 0x1291: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1296:
	/* 0x1296: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_129b:
	/* 0x129b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_12a2:
	/* 0x12a2: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12a5:
	/* 0x12a5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_12ac:
	/* 0x12ac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12b1:
	/* 0x12b1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_12b6:
	/* 0x12b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b8:
	/* 0x12b8: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12bc:
	/* 0x12bc: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_12be:
	/* 0x12be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12c0:
	/* 0x12c0: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_12c6:
	/* 0x12c6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12c9:
	/* 0x12c9: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_12cf:
	/* 0x12cf: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_12d5:
	/* 0x12d5: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12da:
	/* 0x12da: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_12de:
	/* 0x12de: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_12e5:
	/* 0x12e5: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12ea:
	/* 0x12ea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12ef:
	/* 0x12ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12f4:
	/* 0x12f4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_12fc:
	/* 0x12fc: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1300:
	/* 0x1300: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1307:
	/* 0x1307: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_130c:
	/* 0x130c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130e:
	/* 0x130e: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1313:
	/* 0x1313: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_131b:
	/* 0x131b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_131e:
	/* 0x131e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1326:
	/* 0x1326: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_132f:
	/* 0x132f: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1333:
	/* 0x1333: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1338:
	/* 0x1338: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_133d:
	/* 0x133d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1342:
	/* 0x1342: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1347:
	/* 0x1347: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1349:
	/* 0x1349: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_134e:
	/* 0x134e: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1350:
	/* 0x1350: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1353:
	/* 0x1353: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_1359:
	/* 0x1359: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_135c:
	/* 0x135c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1362:
	/* 0x1362: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1368:
	/* 0x1368: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_136d:
	/* 0x136d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1371:
	/* 0x1371: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1378:
	/* 0x1378: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_137d:
	/* 0x137d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1382:
	/* 0x1382: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1389:
	/* 0x1389: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_138c:
	/* 0x138c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1393:
	/* 0x1393: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1398:
	/* 0x1398: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_139d:
	/* 0x139d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_139f:
	/* 0x139f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13a3:
	/* 0x13a3: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_13a5:
	/* 0x13a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13a7:
	/* 0x13a7: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_13ad:
	/* 0x13ad: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_13b0:
	/* 0x13b0: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_13b6:
	/* 0x13b6: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_13bc:
	/* 0x13bc: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13c1:
	/* 0x13c1: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_13c5:
	/* 0x13c5: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_13cc:
	/* 0x13cc: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13d1:
	/* 0x13d1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13d6:
	/* 0x13d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13db:
	/* 0x13db: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_13e3:
	/* 0x13e3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_13e7:
	/* 0x13e7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
	return 5102ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5102ULL: goto x86_l_13ee;
	case 5107ULL: goto x86_l_13f3;
	case 5109ULL: goto x86_l_13f5;
	case 5114ULL: goto x86_l_13fa;
	case 5122ULL: goto x86_l_1402;
	case 5125ULL: goto x86_l_1405;
	case 5133ULL: goto x86_l_140d;
	case 5142ULL: goto x86_l_1416;
	case 5146ULL: goto x86_l_141a;
	case 5151ULL: goto x86_l_141f;
	case 5156ULL: goto x86_l_1424;
	case 5161ULL: goto x86_l_1429;
	case 5166ULL: goto x86_l_142e;
	case 5168ULL: goto x86_l_1430;
	case 5173ULL: goto x86_l_1435;
	case 5175ULL: goto x86_l_1437;
	case 5178ULL: goto x86_l_143a;
	case 5184ULL: goto x86_l_1440;
	case 5187ULL: goto x86_l_1443;
	case 5193ULL: goto x86_l_1449;
	case 5199ULL: goto x86_l_144f;
	case 5204ULL: goto x86_l_1454;
	case 5208ULL: goto x86_l_1458;
	case 5215ULL: goto x86_l_145f;
	case 5220ULL: goto x86_l_1464;
	case 5225ULL: goto x86_l_1469;
	case 5232ULL: goto x86_l_1470;
	case 5235ULL: goto x86_l_1473;
	case 5242ULL: goto x86_l_147a;
	case 5247ULL: goto x86_l_147f;
	case 5252ULL: goto x86_l_1484;
	case 5254ULL: goto x86_l_1486;
	case 5258ULL: goto x86_l_148a;
	case 5260ULL: goto x86_l_148c;
	case 5262ULL: goto x86_l_148e;
	case 5268ULL: goto x86_l_1494;
	case 5271ULL: goto x86_l_1497;
	case 5277ULL: goto x86_l_149d;
	case 5283ULL: goto x86_l_14a3;
	case 5288ULL: goto x86_l_14a8;
	case 5292ULL: goto x86_l_14ac;
	case 5299ULL: goto x86_l_14b3;
	case 5304ULL: goto x86_l_14b8;
	case 5309ULL: goto x86_l_14bd;
	case 5314ULL: goto x86_l_14c2;
	case 5322ULL: goto x86_l_14ca;
	case 5326ULL: goto x86_l_14ce;
	case 5333ULL: goto x86_l_14d5;
	case 5338ULL: goto x86_l_14da;
	case 5340ULL: goto x86_l_14dc;
	case 5345ULL: goto x86_l_14e1;
	case 5353ULL: goto x86_l_14e9;
	case 5356ULL: goto x86_l_14ec;
	case 5364ULL: goto x86_l_14f4;
	case 5373ULL: goto x86_l_14fd;
	case 5377ULL: goto x86_l_1501;
	case 5382ULL: goto x86_l_1506;
	case 5387ULL: goto x86_l_150b;
	case 5392ULL: goto x86_l_1510;
	case 5397ULL: goto x86_l_1515;
	case 5399ULL: goto x86_l_1517;
	case 5404ULL: goto x86_l_151c;
	case 5406ULL: goto x86_l_151e;
	case 5409ULL: goto x86_l_1521;
	case 5415ULL: goto x86_l_1527;
	case 5418ULL: goto x86_l_152a;
	case 5424ULL: goto x86_l_1530;
	case 5430ULL: goto x86_l_1536;
	case 5435ULL: goto x86_l_153b;
	case 5439ULL: goto x86_l_153f;
	case 5446ULL: goto x86_l_1546;
	case 5451ULL: goto x86_l_154b;
	case 5456ULL: goto x86_l_1550;
	case 5463ULL: goto x86_l_1557;
	case 5466ULL: goto x86_l_155a;
	case 5473ULL: goto x86_l_1561;
	case 5478ULL: goto x86_l_1566;
	case 5483ULL: goto x86_l_156b;
	case 5485ULL: goto x86_l_156d;
	case 5489ULL: goto x86_l_1571;
	case 5491ULL: goto x86_l_1573;
	case 5493ULL: goto x86_l_1575;
	case 5499ULL: goto x86_l_157b;
	case 5502ULL: goto x86_l_157e;
	case 5508ULL: goto x86_l_1584;
	case 5514ULL: goto x86_l_158a;
	case 5519ULL: goto x86_l_158f;
	case 5523ULL: goto x86_l_1593;
	case 5530ULL: goto x86_l_159a;
	case 5535ULL: goto x86_l_159f;
	case 5540ULL: goto x86_l_15a4;
	case 5545ULL: goto x86_l_15a9;
	case 5553ULL: goto x86_l_15b1;
	case 5557ULL: goto x86_l_15b5;
	case 5564ULL: goto x86_l_15bc;
	case 5569ULL: goto x86_l_15c1;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5584ULL: goto x86_l_15d0;
	case 5587ULL: goto x86_l_15d3;
	case 5595ULL: goto x86_l_15db;
	case 5604ULL: goto x86_l_15e4;
	case 5608ULL: goto x86_l_15e8;
	case 5613ULL: goto x86_l_15ed;
	case 5618ULL: goto x86_l_15f2;
	case 5623ULL: goto x86_l_15f7;
	case 5628ULL: goto x86_l_15fc;
	case 5630ULL: goto x86_l_15fe;
	case 5635ULL: goto x86_l_1603;
	case 5637ULL: goto x86_l_1605;
	case 5640ULL: goto x86_l_1608;
	case 5646ULL: goto x86_l_160e;
	case 5649ULL: goto x86_l_1611;
	case 5655ULL: goto x86_l_1617;
	case 5661ULL: goto x86_l_161d;
	case 5666ULL: goto x86_l_1622;
	case 5670ULL: goto x86_l_1626;
	case 5677ULL: goto x86_l_162d;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5694ULL: goto x86_l_163e;
	case 5697ULL: goto x86_l_1641;
	case 5704ULL: goto x86_l_1648;
	case 5709ULL: goto x86_l_164d;
	case 5714ULL: goto x86_l_1652;
	case 5716ULL: goto x86_l_1654;
	case 5720ULL: goto x86_l_1658;
	case 5722ULL: goto x86_l_165a;
	case 5724ULL: goto x86_l_165c;
	case 5730ULL: goto x86_l_1662;
	case 5733ULL: goto x86_l_1665;
	case 5739ULL: goto x86_l_166b;
	case 5745ULL: goto x86_l_1671;
	case 5750ULL: goto x86_l_1676;
	case 5754ULL: goto x86_l_167a;
	case 5761ULL: goto x86_l_1681;
	case 5766ULL: goto x86_l_1686;
	case 5771ULL: goto x86_l_168b;
	case 5776ULL: goto x86_l_1690;
	case 5784ULL: goto x86_l_1698;
	case 5788ULL: goto x86_l_169c;
	case 5795ULL: goto x86_l_16a3;
	case 5800ULL: goto x86_l_16a8;
	case 5802ULL: goto x86_l_16aa;
	case 5807ULL: goto x86_l_16af;
	case 5815ULL: goto x86_l_16b7;
	case 5818ULL: goto x86_l_16ba;
	case 5826ULL: goto x86_l_16c2;
	case 5835ULL: goto x86_l_16cb;
	case 5839ULL: goto x86_l_16cf;
	case 5844ULL: goto x86_l_16d4;
	case 5849ULL: goto x86_l_16d9;
	case 5854ULL: goto x86_l_16de;
	case 5859ULL: goto x86_l_16e3;
	case 5861ULL: goto x86_l_16e5;
	case 5866ULL: goto x86_l_16ea;
	case 5868ULL: goto x86_l_16ec;
	case 5871ULL: goto x86_l_16ef;
	case 5877ULL: goto x86_l_16f5;
	case 5880ULL: goto x86_l_16f8;
	case 5886ULL: goto x86_l_16fe;
	case 5892ULL: goto x86_l_1704;
	case 5897ULL: goto x86_l_1709;
	case 5901ULL: goto x86_l_170d;
	case 5908ULL: goto x86_l_1714;
	case 5913ULL: goto x86_l_1719;
	case 5918ULL: goto x86_l_171e;
	case 5925ULL: goto x86_l_1725;
	case 5928ULL: goto x86_l_1728;
	case 5935ULL: goto x86_l_172f;
	case 5940ULL: goto x86_l_1734;
	case 5945ULL: goto x86_l_1739;
	case 5947ULL: goto x86_l_173b;
	case 5951ULL: goto x86_l_173f;
	case 5953ULL: goto x86_l_1741;
	case 5955ULL: goto x86_l_1743;
	case 5961ULL: goto x86_l_1749;
	case 5964ULL: goto x86_l_174c;
	case 5970ULL: goto x86_l_1752;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5985ULL: goto x86_l_1761;
	case 5992ULL: goto x86_l_1768;
	case 5997ULL: goto x86_l_176d;
	case 6002ULL: goto x86_l_1772;
	case 6007ULL: goto x86_l_1777;
	case 6015ULL: goto x86_l_177f;
	case 6019ULL: goto x86_l_1783;
	case 6026ULL: goto x86_l_178a;
	case 6031ULL: goto x86_l_178f;
	case 6033ULL: goto x86_l_1791;
	case 6038ULL: goto x86_l_1796;
	case 6046ULL: goto x86_l_179e;
	case 6049ULL: goto x86_l_17a1;
	case 6057ULL: goto x86_l_17a9;
	case 6066ULL: goto x86_l_17b2;
	case 6070ULL: goto x86_l_17b6;
	case 6075ULL: goto x86_l_17bb;
	case 6080ULL: goto x86_l_17c0;
	case 6085ULL: goto x86_l_17c5;
	case 6090ULL: goto x86_l_17ca;
	case 6092ULL: goto x86_l_17cc;
	case 6097ULL: goto x86_l_17d1;
	case 6099ULL: goto x86_l_17d3;
	case 6102ULL: goto x86_l_17d6;
	case 6108ULL: goto x86_l_17dc;
	case 6111ULL: goto x86_l_17df;
	case 6117ULL: goto x86_l_17e5;
	case 6123ULL: goto x86_l_17eb;
	case 6128ULL: goto x86_l_17f0;
	case 6132ULL: goto x86_l_17f4;
	case 6139ULL: goto x86_l_17fb;
	case 6144ULL: goto x86_l_1800;
	case 6149ULL: goto x86_l_1805;
	case 6156ULL: goto x86_l_180c;
	case 6159ULL: goto x86_l_180f;
	case 6166ULL: goto x86_l_1816;
	case 6171ULL: goto x86_l_181b;
	case 6176ULL: goto x86_l_1820;
	case 6178ULL: goto x86_l_1822;
	case 6182ULL: goto x86_l_1826;
	case 6184ULL: goto x86_l_1828;
	case 6186ULL: goto x86_l_182a;
	case 6192ULL: goto x86_l_1830;
	case 6195ULL: goto x86_l_1833;
	case 6201ULL: goto x86_l_1839;
	case 6207ULL: goto x86_l_183f;
	case 6212ULL: goto x86_l_1844;
	case 6216ULL: goto x86_l_1848;
	case 6223ULL: goto x86_l_184f;
	case 6228ULL: goto x86_l_1854;
	case 6233ULL: goto x86_l_1859;
	case 6238ULL: goto x86_l_185e;
	case 6246ULL: goto x86_l_1866;
	case 6250ULL: goto x86_l_186a;
	case 6257ULL: goto x86_l_1871;
	case 6262ULL: goto x86_l_1876;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6277ULL: goto x86_l_1885;
	case 6280ULL: goto x86_l_1888;
	case 6288ULL: goto x86_l_1890;
	case 6297ULL: goto x86_l_1899;
	case 6301ULL: goto x86_l_189d;
	case 6306ULL: goto x86_l_18a2;
	case 6311ULL: goto x86_l_18a7;
	case 6316ULL: goto x86_l_18ac;
	case 6321ULL: goto x86_l_18b1;
	case 6323ULL: goto x86_l_18b3;
	case 6328ULL: goto x86_l_18b8;
	case 6330ULL: goto x86_l_18ba;
	case 6333ULL: goto x86_l_18bd;
	case 6339ULL: goto x86_l_18c3;
	case 6342ULL: goto x86_l_18c6;
	case 6348ULL: goto x86_l_18cc;
	case 6354ULL: goto x86_l_18d2;
	case 6359ULL: goto x86_l_18d7;
	case 6363ULL: goto x86_l_18db;
	case 6370ULL: goto x86_l_18e2;
	case 6375ULL: goto x86_l_18e7;
	case 6380ULL: goto x86_l_18ec;
	case 6387ULL: goto x86_l_18f3;
	case 6390ULL: goto x86_l_18f6;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6407ULL: goto x86_l_1907;
	case 6409ULL: goto x86_l_1909;
	case 6413ULL: goto x86_l_190d;
	case 6415ULL: goto x86_l_190f;
	case 6417ULL: goto x86_l_1911;
	case 6423ULL: goto x86_l_1917;
	case 6426ULL: goto x86_l_191a;
	case 6432ULL: goto x86_l_1920;
	case 6438ULL: goto x86_l_1926;
	case 6443ULL: goto x86_l_192b;
	case 6447ULL: goto x86_l_192f;
	case 6454ULL: goto x86_l_1936;
	case 6459ULL: goto x86_l_193b;
	case 6464ULL: goto x86_l_1940;
	case 6469ULL: goto x86_l_1945;
	case 6477ULL: goto x86_l_194d;
	case 6481ULL: goto x86_l_1951;
	case 6488ULL: goto x86_l_1958;
	case 6493ULL: goto x86_l_195d;
	case 6495ULL: goto x86_l_195f;
	case 6500ULL: goto x86_l_1964;
	case 6508ULL: goto x86_l_196c;
	case 6511ULL: goto x86_l_196f;
	case 6519ULL: goto x86_l_1977;
	case 6528ULL: goto x86_l_1980;
	case 6532ULL: goto x86_l_1984;
	case 6537ULL: goto x86_l_1989;
	case 6542ULL: goto x86_l_198e;
	case 6547ULL: goto x86_l_1993;
	case 6552ULL: goto x86_l_1998;
	case 6554ULL: goto x86_l_199a;
	case 6559ULL: goto x86_l_199f;
	case 6561ULL: goto x86_l_19a1;
	case 6564ULL: goto x86_l_19a4;
	case 6570ULL: goto x86_l_19aa;
	case 6573ULL: goto x86_l_19ad;
	case 6579ULL: goto x86_l_19b3;
	case 6585ULL: goto x86_l_19b9;
	case 6590ULL: goto x86_l_19be;
	case 6594ULL: goto x86_l_19c2;
	case 6601ULL: goto x86_l_19c9;
	case 6606ULL: goto x86_l_19ce;
	case 6611ULL: goto x86_l_19d3;
	case 6618ULL: goto x86_l_19da;
	case 6621ULL: goto x86_l_19dd;
	case 6628ULL: goto x86_l_19e4;
	case 6633ULL: goto x86_l_19e9;
	case 6638ULL: goto x86_l_19ee;
	case 6640ULL: goto x86_l_19f0;
	case 6644ULL: goto x86_l_19f4;
	case 6646ULL: goto x86_l_19f6;
	case 6648ULL: goto x86_l_19f8;
	case 6654ULL: goto x86_l_19fe;
	case 6657ULL: goto x86_l_1a01;
	case 6663ULL: goto x86_l_1a07;
	case 6669ULL: goto x86_l_1a0d;
	case 6674ULL: goto x86_l_1a12;
	case 6678ULL: goto x86_l_1a16;
	case 6685ULL: goto x86_l_1a1d;
	case 6690ULL: goto x86_l_1a22;
	case 6695ULL: goto x86_l_1a27;
	case 6700ULL: goto x86_l_1a2c;
	case 6708ULL: goto x86_l_1a34;
	case 6712ULL: goto x86_l_1a38;
	case 6719ULL: goto x86_l_1a3f;
	case 6724ULL: goto x86_l_1a44;
	case 6726ULL: goto x86_l_1a46;
	case 6731ULL: goto x86_l_1a4b;
	case 6739ULL: goto x86_l_1a53;
	case 6742ULL: goto x86_l_1a56;
	case 6750ULL: goto x86_l_1a5e;
	case 6759ULL: goto x86_l_1a67;
	case 6763ULL: goto x86_l_1a6b;
	case 6768ULL: goto x86_l_1a70;
	case 6773ULL: goto x86_l_1a75;
	case 6778ULL: goto x86_l_1a7a;
	case 6783ULL: goto x86_l_1a7f;
	case 6785ULL: goto x86_l_1a81;
	case 6790ULL: goto x86_l_1a86;
	case 6792ULL: goto x86_l_1a88;
	case 6795ULL: goto x86_l_1a8b;
	case 6801ULL: goto x86_l_1a91;
	case 6804ULL: goto x86_l_1a94;
	case 6810ULL: goto x86_l_1a9a;
	case 6816ULL: goto x86_l_1aa0;
	case 6821ULL: goto x86_l_1aa5;
	case 6825ULL: goto x86_l_1aa9;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6842ULL: goto x86_l_1aba;
	case 6849ULL: goto x86_l_1ac1;
	case 6852ULL: goto x86_l_1ac4;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6871ULL: goto x86_l_1ad7;
	case 6875ULL: goto x86_l_1adb;
	case 6877ULL: goto x86_l_1add;
	case 6879ULL: goto x86_l_1adf;
	case 6885ULL: goto x86_l_1ae5;
	case 6888ULL: goto x86_l_1ae8;
	case 6894ULL: goto x86_l_1aee;
	case 6900ULL: goto x86_l_1af4;
	case 6905ULL: goto x86_l_1af9;
	case 6909ULL: goto x86_l_1afd;
	case 6916ULL: goto x86_l_1b04;
	case 6921ULL: goto x86_l_1b09;
	case 6926ULL: goto x86_l_1b0e;
	case 6931ULL: goto x86_l_1b13;
	case 6939ULL: goto x86_l_1b1b;
	case 6943ULL: goto x86_l_1b1f;
	case 6950ULL: goto x86_l_1b26;
	case 6955ULL: goto x86_l_1b2b;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6970ULL: goto x86_l_1b3a;
	case 6973ULL: goto x86_l_1b3d;
	case 6981ULL: goto x86_l_1b45;
	case 6990ULL: goto x86_l_1b4e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_13ee:
	/* 0x13ee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13f3:
	/* 0x13f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f5:
	/* 0x13f5: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_13fa:
	/* 0x13fa: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1402:
	/* 0x1402: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1405:
	/* 0x1405: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_140d:
	/* 0x140d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1416:
	/* 0x1416: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_141a:
	/* 0x141a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_141f:
	/* 0x141f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1424:
	/* 0x1424: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1429:
	/* 0x1429: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_142e:
	/* 0x142e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1430:
	/* 0x1430: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1435:
	/* 0x1435: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1437:
	/* 0x1437: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_143a:
	/* 0x143a: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_1440:
	/* 0x1440: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1443:
	/* 0x1443: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1449:
	/* 0x1449: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_144f:
	/* 0x144f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1454:
	/* 0x1454: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1458:
	/* 0x1458: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_145f:
	/* 0x145f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1464:
	/* 0x1464: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1469:
	/* 0x1469: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1470:
	/* 0x1470: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1473:
	/* 0x1473: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_147a:
	/* 0x147a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_147f:
	/* 0x147f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1484:
	/* 0x1484: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1486:
	/* 0x1486: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_148a:
	/* 0x148a: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_148c:
	/* 0x148c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_148e:
	/* 0x148e: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_1494:
	/* 0x1494: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1497:
	/* 0x1497: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_149d:
	/* 0x149d: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_14a3:
	/* 0x14a3: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14a8:
	/* 0x14a8: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_14ac:
	/* 0x14ac: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_14b3:
	/* 0x14b3: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14b8:
	/* 0x14b8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14bd:
	/* 0x14bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14c2:
	/* 0x14c2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_14ca:
	/* 0x14ca: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_14ce:
	/* 0x14ce: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_14d5:
	/* 0x14d5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14da:
	/* 0x14da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14dc:
	/* 0x14dc: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_14e1:
	/* 0x14e1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_14e9:
	/* 0x14e9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_14ec:
	/* 0x14ec: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_14f4:
	/* 0x14f4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_14fd:
	/* 0x14fd: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1501:
	/* 0x1501: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1506:
	/* 0x1506: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_150b:
	/* 0x150b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1510:
	/* 0x1510: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1515:
	/* 0x1515: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1517:
	/* 0x1517: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_151c:
	/* 0x151c: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_151e:
	/* 0x151e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1521:
	/* 0x1521: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_1527:
	/* 0x1527: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_152a:
	/* 0x152a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1530:
	/* 0x1530: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1536:
	/* 0x1536: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_153b:
	/* 0x153b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_153f:
	/* 0x153f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1546:
	/* 0x1546: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_154b:
	/* 0x154b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1550:
	/* 0x1550: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1557:
	/* 0x1557: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_155a:
	/* 0x155a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1561:
	/* 0x1561: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1566:
	/* 0x1566: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_156b:
	/* 0x156b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_156d:
	/* 0x156d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1571:
	/* 0x1571: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_1573:
	/* 0x1573: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1575:
	/* 0x1575: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_157b:
	/* 0x157b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_157e:
	/* 0x157e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1584:
	/* 0x1584: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_158a:
	/* 0x158a: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_158f:
	/* 0x158f: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1593:
	/* 0x1593: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_159a:
	/* 0x159a: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_159f:
	/* 0x159f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15a4:
	/* 0x15a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15a9:
	/* 0x15a9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_15b1:
	/* 0x15b1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_15b5:
	/* 0x15b5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_15bc:
	/* 0x15bc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15c1:
	/* 0x15c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c3:
	/* 0x15c3: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_15c8:
	/* 0x15c8: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_15d0:
	/* 0x15d0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_15d3:
	/* 0x15d3: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_15db:
	/* 0x15db: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_15e4:
	/* 0x15e4: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15e8:
	/* 0x15e8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15ed:
	/* 0x15ed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15f2:
	/* 0x15f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15f7:
	/* 0x15f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15fc:
	/* 0x15fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15fe:
	/* 0x15fe: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1603:
	/* 0x1603: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_1605:
	/* 0x1605: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1608:
	/* 0x1608: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_160e:
	/* 0x160e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1611:
	/* 0x1611: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1617:
	/* 0x1617: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_161d:
	/* 0x161d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1622:
	/* 0x1622: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1626:
	/* 0x1626: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_162d:
	/* 0x162d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1632:
	/* 0x1632: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1637:
	/* 0x1637: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_163e:
	/* 0x163e: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1641:
	/* 0x1641: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1648:
	/* 0x1648: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_164d:
	/* 0x164d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1652:
	/* 0x1652: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1654:
	/* 0x1654: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1658:
	/* 0x1658: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_165a:
	/* 0x165a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_165c:
	/* 0x165c: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_1662:
	/* 0x1662: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1665:
	/* 0x1665: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_166b:
	/* 0x166b: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1671:
	/* 0x1671: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1676:
	/* 0x1676: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_167a:
	/* 0x167a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1681:
	/* 0x1681: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1686:
	/* 0x1686: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_168b:
	/* 0x168b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1690:
	/* 0x1690: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1698:
	/* 0x1698: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_169c:
	/* 0x169c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_16a3:
	/* 0x16a3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16a8:
	/* 0x16a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16aa:
	/* 0x16aa: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_16af:
	/* 0x16af: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_16b7:
	/* 0x16b7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_16ba:
	/* 0x16ba: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_16c2:
	/* 0x16c2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_16cb:
	/* 0x16cb: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16cf:
	/* 0x16cf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16d4:
	/* 0x16d4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16d9:
	/* 0x16d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16de:
	/* 0x16de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16e3:
	/* 0x16e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e5:
	/* 0x16e5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16ea:
	/* 0x16ea: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_16ec:
	/* 0x16ec: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_16ef:
	/* 0x16ef: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_16f5:
	/* 0x16f5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16f8:
	/* 0x16f8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_16fe:
	/* 0x16fe: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1704:
	/* 0x1704: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1709:
	/* 0x1709: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_170d:
	/* 0x170d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1714:
	/* 0x1714: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1719:
	/* 0x1719: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_171e:
	/* 0x171e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1725:
	/* 0x1725: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1728:
	/* 0x1728: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_172f:
	/* 0x172f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1734:
	/* 0x1734: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1739:
	/* 0x1739: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173b:
	/* 0x173b: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_173f:
	/* 0x173f: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_1741:
	/* 0x1741: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1743:
	/* 0x1743: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_1749:
	/* 0x1749: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_174c:
	/* 0x174c: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1752:
	/* 0x1752: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1758:
	/* 0x1758: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_175d:
	/* 0x175d: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1761:
	/* 0x1761: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1768:
	/* 0x1768: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_176d:
	/* 0x176d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1772:
	/* 0x1772: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1777:
	/* 0x1777: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_177f:
	/* 0x177f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1783:
	/* 0x1783: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_178a:
	/* 0x178a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_178f:
	/* 0x178f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1791:
	/* 0x1791: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1796:
	/* 0x1796: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_179e:
	/* 0x179e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_17a1:
	/* 0x17a1: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_17a9:
	/* 0x17a9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17b2:
	/* 0x17b2: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17b6:
	/* 0x17b6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17bb:
	/* 0x17bb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17c0:
	/* 0x17c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c5:
	/* 0x17c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17ca:
	/* 0x17ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17cc:
	/* 0x17cc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d1:
	/* 0x17d1: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_17d3:
	/* 0x17d3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_17d6:
	/* 0x17d6: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_17dc:
	/* 0x17dc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17df:
	/* 0x17df: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_17e5:
	/* 0x17e5: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_17eb:
	/* 0x17eb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17f0:
	/* 0x17f0: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_17f4:
	/* 0x17f4: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_17fb:
	/* 0x17fb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1800:
	/* 0x1800: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1805:
	/* 0x1805: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_180c:
	/* 0x180c: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_180f:
	/* 0x180f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1816:
	/* 0x1816: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_181b:
	/* 0x181b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1820:
	/* 0x1820: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1822:
	/* 0x1822: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1826:
	/* 0x1826: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_1828:
	/* 0x1828: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_182a:
	/* 0x182a: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_1830:
	/* 0x1830: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1833:
	/* 0x1833: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1839:
	/* 0x1839: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_183f:
	/* 0x183f: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1844:
	/* 0x1844: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1848:
	/* 0x1848: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_184f:
	/* 0x184f: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1854:
	/* 0x1854: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1859:
	/* 0x1859: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_185e:
	/* 0x185e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1866:
	/* 0x1866: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_186a:
	/* 0x186a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1871:
	/* 0x1871: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1876:
	/* 0x1876: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1878:
	/* 0x1878: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_187d:
	/* 0x187d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1885:
	/* 0x1885: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1888:
	/* 0x1888: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1890:
	/* 0x1890: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1899:
	/* 0x1899: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_189d:
	/* 0x189d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18a2:
	/* 0x18a2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18a7:
	/* 0x18a7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18ac:
	/* 0x18ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18b1:
	/* 0x18b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b3:
	/* 0x18b3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18b8:
	/* 0x18b8: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_18ba:
	/* 0x18ba: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_18bd:
	/* 0x18bd: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_18c3:
	/* 0x18c3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18c6:
	/* 0x18c6: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_18cc:
	/* 0x18cc: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_18d2:
	/* 0x18d2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18d7:
	/* 0x18d7: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_18db:
	/* 0x18db: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_18e2:
	/* 0x18e2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_18e7:
	/* 0x18e7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_18ec:
	/* 0x18ec: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18f3:
	/* 0x18f3: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18f6:
	/* 0x18f6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_18fd:
	/* 0x18fd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1902:
	/* 0x1902: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1907:
	/* 0x1907: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1909:
	/* 0x1909: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_190d:
	/* 0x190d: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_190f:
	/* 0x190f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1911:
	/* 0x1911: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_1917:
	/* 0x1917: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_191a:
	/* 0x191a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1920:
	/* 0x1920: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1926:
	/* 0x1926: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_192b:
	/* 0x192b: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_192f:
	/* 0x192f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1936:
	/* 0x1936: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_193b:
	/* 0x193b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1940:
	/* 0x1940: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1945:
	/* 0x1945: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_194d:
	/* 0x194d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1951:
	/* 0x1951: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1958:
	/* 0x1958: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_195d:
	/* 0x195d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_195f:
	/* 0x195f: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1964:
	/* 0x1964: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_196c:
	/* 0x196c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_196f:
	/* 0x196f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1977:
	/* 0x1977: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1980:
	/* 0x1980: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1984:
	/* 0x1984: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1989:
	/* 0x1989: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_198e:
	/* 0x198e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1993:
	/* 0x1993: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1998:
	/* 0x1998: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199a:
	/* 0x199a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_199f:
	/* 0x199f: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_19a1:
	/* 0x19a1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_19a4:
	/* 0x19a4: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_19aa:
	/* 0x19aa: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19ad:
	/* 0x19ad: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_19b3:
	/* 0x19b3: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_19b9:
	/* 0x19b9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19be:
	/* 0x19be: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_19c2:
	/* 0x19c2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_19c9:
	/* 0x19c9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_19ce:
	/* 0x19ce: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_19d3:
	/* 0x19d3: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19da:
	/* 0x19da: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19dd:
	/* 0x19dd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_19e4:
	/* 0x19e4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19e9:
	/* 0x19e9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_19ee:
	/* 0x19ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f0:
	/* 0x19f0: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19f4:
	/* 0x19f4: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_19f6:
	/* 0x19f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19f8:
	/* 0x19f8: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_19fe:
	/* 0x19fe: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a01:
	/* 0x1a01: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1a07:
	/* 0x1a07: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1a0d:
	/* 0x1a0d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a12:
	/* 0x1a12: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1a16:
	/* 0x1a16: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1a1d:
	/* 0x1a1d: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a22:
	/* 0x1a22: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a27:
	/* 0x1a27: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a2c:
	/* 0x1a2c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a34:
	/* 0x1a34: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1a38:
	/* 0x1a38: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1a3f:
	/* 0x1a3f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a44:
	/* 0x1a44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a46:
	/* 0x1a46: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1a4b:
	/* 0x1a4b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1a53:
	/* 0x1a53: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1a56:
	/* 0x1a56: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1a5e:
	/* 0x1a5e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1a67:
	/* 0x1a67: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a6b:
	/* 0x1a6b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a70:
	/* 0x1a70: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a75:
	/* 0x1a75: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a7a:
	/* 0x1a7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a7f:
	/* 0x1a7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a81:
	/* 0x1a81: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a86:
	/* 0x1a86: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_1a88:
	/* 0x1a88: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1a8b:
	/* 0x1a8b: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_1a91:
	/* 0x1a91: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a94:
	/* 0x1a94: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1a9a:
	/* 0x1a9a: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1aa0:
	/* 0x1aa0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aa5:
	/* 0x1aa5: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1aa9:
	/* 0x1aa9: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1ab0:
	/* 0x1ab0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ab5:
	/* 0x1ab5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1aba:
	/* 0x1aba: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ac1:
	/* 0x1ac1: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ac4:
	/* 0x1ac4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1acb:
	/* 0x1acb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ad5:
	/* 0x1ad5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad7:
	/* 0x1ad7: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1adb:
	/* 0x1adb: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_1add:
	/* 0x1add: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1adf:
	/* 0x1adf: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_1ae5:
	/* 0x1ae5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ae8:
	/* 0x1ae8: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1aee:
	/* 0x1aee: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1af4:
	/* 0x1af4: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1af9:
	/* 0x1af9: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1afd:
	/* 0x1afd: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1b04:
	/* 0x1b04: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b09:
	/* 0x1b09: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b0e:
	/* 0x1b0e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b13:
	/* 0x1b13: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b1b:
	/* 0x1b1b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1b1f:
	/* 0x1b1f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1b26:
	/* 0x1b26: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b2b:
	/* 0x1b2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2d:
	/* 0x1b2d: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1b32:
	/* 0x1b32: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1b3a:
	/* 0x1b3a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1b3d:
	/* 0x1b3d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1b45:
	/* 0x1b45: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b4e:
	/* 0x1b4e: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
	return 6994ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6994ULL: goto x86_l_1b52;
	case 6999ULL: goto x86_l_1b57;
	case 7004ULL: goto x86_l_1b5c;
	case 7009ULL: goto x86_l_1b61;
	case 7014ULL: goto x86_l_1b66;
	case 7016ULL: goto x86_l_1b68;
	case 7021ULL: goto x86_l_1b6d;
	case 7023ULL: goto x86_l_1b6f;
	case 7026ULL: goto x86_l_1b72;
	case 7032ULL: goto x86_l_1b78;
	case 7035ULL: goto x86_l_1b7b;
	case 7041ULL: goto x86_l_1b81;
	case 7047ULL: goto x86_l_1b87;
	case 7052ULL: goto x86_l_1b8c;
	case 7056ULL: goto x86_l_1b90;
	case 7063ULL: goto x86_l_1b97;
	case 7068ULL: goto x86_l_1b9c;
	case 7073ULL: goto x86_l_1ba1;
	case 7080ULL: goto x86_l_1ba8;
	case 7083ULL: goto x86_l_1bab;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7100ULL: goto x86_l_1bbc;
	case 7102ULL: goto x86_l_1bbe;
	case 7106ULL: goto x86_l_1bc2;
	case 7108ULL: goto x86_l_1bc4;
	case 7110ULL: goto x86_l_1bc6;
	case 7116ULL: goto x86_l_1bcc;
	case 7119ULL: goto x86_l_1bcf;
	case 7125ULL: goto x86_l_1bd5;
	case 7131ULL: goto x86_l_1bdb;
	case 7136ULL: goto x86_l_1be0;
	case 7140ULL: goto x86_l_1be4;
	case 7147ULL: goto x86_l_1beb;
	case 7152ULL: goto x86_l_1bf0;
	case 7157ULL: goto x86_l_1bf5;
	case 7162ULL: goto x86_l_1bfa;
	case 7170ULL: goto x86_l_1c02;
	case 7174ULL: goto x86_l_1c06;
	case 7181ULL: goto x86_l_1c0d;
	case 7186ULL: goto x86_l_1c12;
	case 7188ULL: goto x86_l_1c14;
	case 7193ULL: goto x86_l_1c19;
	case 7201ULL: goto x86_l_1c21;
	case 7204ULL: goto x86_l_1c24;
	case 7212ULL: goto x86_l_1c2c;
	case 7221ULL: goto x86_l_1c35;
	case 7225ULL: goto x86_l_1c39;
	case 7230ULL: goto x86_l_1c3e;
	case 7235ULL: goto x86_l_1c43;
	case 7240ULL: goto x86_l_1c48;
	case 7245ULL: goto x86_l_1c4d;
	case 7247ULL: goto x86_l_1c4f;
	case 7252ULL: goto x86_l_1c54;
	case 7254ULL: goto x86_l_1c56;
	case 7257ULL: goto x86_l_1c59;
	case 7263ULL: goto x86_l_1c5f;
	case 7266ULL: goto x86_l_1c62;
	case 7272ULL: goto x86_l_1c68;
	case 7278ULL: goto x86_l_1c6e;
	case 7283ULL: goto x86_l_1c73;
	case 7287ULL: goto x86_l_1c77;
	case 7294ULL: goto x86_l_1c7e;
	case 7299ULL: goto x86_l_1c83;
	case 7304ULL: goto x86_l_1c88;
	case 7311ULL: goto x86_l_1c8f;
	case 7314ULL: goto x86_l_1c92;
	case 7321ULL: goto x86_l_1c99;
	case 7326ULL: goto x86_l_1c9e;
	case 7331ULL: goto x86_l_1ca3;
	case 7333ULL: goto x86_l_1ca5;
	case 7337ULL: goto x86_l_1ca9;
	case 7339ULL: goto x86_l_1cab;
	case 7341ULL: goto x86_l_1cad;
	case 7347ULL: goto x86_l_1cb3;
	case 7350ULL: goto x86_l_1cb6;
	case 7356ULL: goto x86_l_1cbc;
	case 7362ULL: goto x86_l_1cc2;
	case 7367ULL: goto x86_l_1cc7;
	case 7371ULL: goto x86_l_1ccb;
	case 7378ULL: goto x86_l_1cd2;
	case 7383ULL: goto x86_l_1cd7;
	case 7388ULL: goto x86_l_1cdc;
	case 7393ULL: goto x86_l_1ce1;
	case 7401ULL: goto x86_l_1ce9;
	case 7405ULL: goto x86_l_1ced;
	case 7412ULL: goto x86_l_1cf4;
	case 7417ULL: goto x86_l_1cf9;
	case 7419ULL: goto x86_l_1cfb;
	case 7424ULL: goto x86_l_1d00;
	case 7432ULL: goto x86_l_1d08;
	case 7435ULL: goto x86_l_1d0b;
	case 7443ULL: goto x86_l_1d13;
	case 7452ULL: goto x86_l_1d1c;
	case 7456ULL: goto x86_l_1d20;
	case 7461ULL: goto x86_l_1d25;
	case 7466ULL: goto x86_l_1d2a;
	case 7471ULL: goto x86_l_1d2f;
	case 7476ULL: goto x86_l_1d34;
	case 7478ULL: goto x86_l_1d36;
	case 7483ULL: goto x86_l_1d3b;
	case 7485ULL: goto x86_l_1d3d;
	case 7488ULL: goto x86_l_1d40;
	case 7494ULL: goto x86_l_1d46;
	case 7497ULL: goto x86_l_1d49;
	case 7503ULL: goto x86_l_1d4f;
	case 7509ULL: goto x86_l_1d55;
	case 7514ULL: goto x86_l_1d5a;
	case 7518ULL: goto x86_l_1d5e;
	case 7525ULL: goto x86_l_1d65;
	case 7530ULL: goto x86_l_1d6a;
	case 7535ULL: goto x86_l_1d6f;
	case 7542ULL: goto x86_l_1d76;
	case 7545ULL: goto x86_l_1d79;
	case 7552ULL: goto x86_l_1d80;
	case 7557ULL: goto x86_l_1d85;
	case 7562ULL: goto x86_l_1d8a;
	case 7564ULL: goto x86_l_1d8c;
	case 7568ULL: goto x86_l_1d90;
	case 7570ULL: goto x86_l_1d92;
	case 7572ULL: goto x86_l_1d94;
	case 7578ULL: goto x86_l_1d9a;
	case 7581ULL: goto x86_l_1d9d;
	case 7587ULL: goto x86_l_1da3;
	case 7593ULL: goto x86_l_1da9;
	case 7598ULL: goto x86_l_1dae;
	case 7602ULL: goto x86_l_1db2;
	case 7609ULL: goto x86_l_1db9;
	case 7614ULL: goto x86_l_1dbe;
	case 7619ULL: goto x86_l_1dc3;
	case 7624ULL: goto x86_l_1dc8;
	case 7632ULL: goto x86_l_1dd0;
	case 7636ULL: goto x86_l_1dd4;
	case 7643ULL: goto x86_l_1ddb;
	case 7648ULL: goto x86_l_1de0;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7663ULL: goto x86_l_1def;
	case 7666ULL: goto x86_l_1df2;
	case 7674ULL: goto x86_l_1dfa;
	case 7683ULL: goto x86_l_1e03;
	case 7687ULL: goto x86_l_1e07;
	case 7692ULL: goto x86_l_1e0c;
	case 7697ULL: goto x86_l_1e11;
	case 7702ULL: goto x86_l_1e16;
	case 7707ULL: goto x86_l_1e1b;
	case 7709ULL: goto x86_l_1e1d;
	case 7714ULL: goto x86_l_1e22;
	case 7716ULL: goto x86_l_1e24;
	case 7719ULL: goto x86_l_1e27;
	case 7725ULL: goto x86_l_1e2d;
	case 7728ULL: goto x86_l_1e30;
	case 7734ULL: goto x86_l_1e36;
	case 7740ULL: goto x86_l_1e3c;
	case 7745ULL: goto x86_l_1e41;
	case 7749ULL: goto x86_l_1e45;
	case 7756ULL: goto x86_l_1e4c;
	case 7761ULL: goto x86_l_1e51;
	case 7766ULL: goto x86_l_1e56;
	case 7773ULL: goto x86_l_1e5d;
	case 7776ULL: goto x86_l_1e60;
	case 7783ULL: goto x86_l_1e67;
	case 7788ULL: goto x86_l_1e6c;
	case 7793ULL: goto x86_l_1e71;
	case 7795ULL: goto x86_l_1e73;
	case 7799ULL: goto x86_l_1e77;
	case 7801ULL: goto x86_l_1e79;
	case 7803ULL: goto x86_l_1e7b;
	case 7809ULL: goto x86_l_1e81;
	case 7812ULL: goto x86_l_1e84;
	case 7818ULL: goto x86_l_1e8a;
	case 7824ULL: goto x86_l_1e90;
	case 7829ULL: goto x86_l_1e95;
	case 7833ULL: goto x86_l_1e99;
	case 7840ULL: goto x86_l_1ea0;
	case 7845ULL: goto x86_l_1ea5;
	case 7850ULL: goto x86_l_1eaa;
	case 7855ULL: goto x86_l_1eaf;
	case 7863ULL: goto x86_l_1eb7;
	case 7867ULL: goto x86_l_1ebb;
	case 7874ULL: goto x86_l_1ec2;
	case 7879ULL: goto x86_l_1ec7;
	case 7881ULL: goto x86_l_1ec9;
	case 7886ULL: goto x86_l_1ece;
	case 7894ULL: goto x86_l_1ed6;
	case 7897ULL: goto x86_l_1ed9;
	case 7905ULL: goto x86_l_1ee1;
	case 7914ULL: goto x86_l_1eea;
	case 7918ULL: goto x86_l_1eee;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7933ULL: goto x86_l_1efd;
	case 7938ULL: goto x86_l_1f02;
	case 7940ULL: goto x86_l_1f04;
	case 7945ULL: goto x86_l_1f09;
	case 7947ULL: goto x86_l_1f0b;
	case 7950ULL: goto x86_l_1f0e;
	case 7956ULL: goto x86_l_1f14;
	case 7959ULL: goto x86_l_1f17;
	case 7965ULL: goto x86_l_1f1d;
	case 7971ULL: goto x86_l_1f23;
	case 7976ULL: goto x86_l_1f28;
	case 7980ULL: goto x86_l_1f2c;
	case 7987ULL: goto x86_l_1f33;
	case 7992ULL: goto x86_l_1f38;
	case 7997ULL: goto x86_l_1f3d;
	case 8004ULL: goto x86_l_1f44;
	case 8007ULL: goto x86_l_1f47;
	case 8014ULL: goto x86_l_1f4e;
	case 8019ULL: goto x86_l_1f53;
	case 8024ULL: goto x86_l_1f58;
	case 8026ULL: goto x86_l_1f5a;
	case 8030ULL: goto x86_l_1f5e;
	case 8032ULL: goto x86_l_1f60;
	case 8034ULL: goto x86_l_1f62;
	case 8040ULL: goto x86_l_1f68;
	case 8043ULL: goto x86_l_1f6b;
	case 8049ULL: goto x86_l_1f71;
	case 8055ULL: goto x86_l_1f77;
	case 8060ULL: goto x86_l_1f7c;
	case 8064ULL: goto x86_l_1f80;
	case 8071ULL: goto x86_l_1f87;
	case 8076ULL: goto x86_l_1f8c;
	case 8081ULL: goto x86_l_1f91;
	case 8086ULL: goto x86_l_1f96;
	case 8094ULL: goto x86_l_1f9e;
	case 8098ULL: goto x86_l_1fa2;
	case 8105ULL: goto x86_l_1fa9;
	case 8110ULL: goto x86_l_1fae;
	case 8112ULL: goto x86_l_1fb0;
	case 8117ULL: goto x86_l_1fb5;
	case 8125ULL: goto x86_l_1fbd;
	case 8128ULL: goto x86_l_1fc0;
	case 8136ULL: goto x86_l_1fc8;
	case 8145ULL: goto x86_l_1fd1;
	case 8152ULL: goto x86_l_1fd8;
	case 8157ULL: goto x86_l_1fdd;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8172ULL: goto x86_l_1fec;
	case 8174ULL: goto x86_l_1fee;
	case 8179ULL: goto x86_l_1ff3;
	case 8181ULL: goto x86_l_1ff5;
	case 8184ULL: goto x86_l_1ff8;
	case 8190ULL: goto x86_l_1ffe;
	case 8193ULL: goto x86_l_2001;
	case 8199ULL: goto x86_l_2007;
	case 8205ULL: goto x86_l_200d;
	case 8210ULL: goto x86_l_2012;
	case 8214ULL: goto x86_l_2016;
	case 8221ULL: goto x86_l_201d;
	case 8226ULL: goto x86_l_2022;
	case 8231ULL: goto x86_l_2027;
	case 8238ULL: goto x86_l_202e;
	case 8241ULL: goto x86_l_2031;
	case 8248ULL: goto x86_l_2038;
	case 8253ULL: goto x86_l_203d;
	case 8258ULL: goto x86_l_2042;
	case 8260ULL: goto x86_l_2044;
	case 8264ULL: goto x86_l_2048;
	case 8266ULL: goto x86_l_204a;
	case 8268ULL: goto x86_l_204c;
	case 8274ULL: goto x86_l_2052;
	case 8277ULL: goto x86_l_2055;
	case 8283ULL: goto x86_l_205b;
	case 8289ULL: goto x86_l_2061;
	case 8294ULL: goto x86_l_2066;
	case 8298ULL: goto x86_l_206a;
	case 8305ULL: goto x86_l_2071;
	case 8310ULL: goto x86_l_2076;
	case 8315ULL: goto x86_l_207b;
	case 8320ULL: goto x86_l_2080;
	case 8328ULL: goto x86_l_2088;
	case 8332ULL: goto x86_l_208c;
	case 8339ULL: goto x86_l_2093;
	case 8344ULL: goto x86_l_2098;
	case 8346ULL: goto x86_l_209a;
	case 8351ULL: goto x86_l_209f;
	case 8359ULL: goto x86_l_20a7;
	case 8362ULL: goto x86_l_20aa;
	case 8370ULL: goto x86_l_20b2;
	case 8379ULL: goto x86_l_20bb;
	case 8386ULL: goto x86_l_20c2;
	case 8391ULL: goto x86_l_20c7;
	case 8396ULL: goto x86_l_20cc;
	case 8401ULL: goto x86_l_20d1;
	case 8406ULL: goto x86_l_20d6;
	case 8408ULL: goto x86_l_20d8;
	case 8413ULL: goto x86_l_20dd;
	case 8415ULL: goto x86_l_20df;
	case 8418ULL: goto x86_l_20e2;
	case 8424ULL: goto x86_l_20e8;
	case 8427ULL: goto x86_l_20eb;
	case 8433ULL: goto x86_l_20f1;
	case 8439ULL: goto x86_l_20f7;
	case 8444ULL: goto x86_l_20fc;
	case 8448ULL: goto x86_l_2100;
	case 8455ULL: goto x86_l_2107;
	case 8460ULL: goto x86_l_210c;
	case 8465ULL: goto x86_l_2111;
	case 8472ULL: goto x86_l_2118;
	case 8475ULL: goto x86_l_211b;
	case 8482ULL: goto x86_l_2122;
	case 8487ULL: goto x86_l_2127;
	case 8492ULL: goto x86_l_212c;
	case 8494ULL: goto x86_l_212e;
	case 8498ULL: goto x86_l_2132;
	case 8500ULL: goto x86_l_2134;
	case 8502ULL: goto x86_l_2136;
	case 8508ULL: goto x86_l_213c;
	case 8511ULL: goto x86_l_213f;
	case 8517ULL: goto x86_l_2145;
	case 8523ULL: goto x86_l_214b;
	case 8528ULL: goto x86_l_2150;
	case 8532ULL: goto x86_l_2154;
	case 8539ULL: goto x86_l_215b;
	case 8544ULL: goto x86_l_2160;
	case 8549ULL: goto x86_l_2165;
	case 8554ULL: goto x86_l_216a;
	case 8562ULL: goto x86_l_2172;
	case 8566ULL: goto x86_l_2176;
	case 8573ULL: goto x86_l_217d;
	case 8578ULL: goto x86_l_2182;
	case 8580ULL: goto x86_l_2184;
	case 8585ULL: goto x86_l_2189;
	case 8593ULL: goto x86_l_2191;
	case 8596ULL: goto x86_l_2194;
	case 8604ULL: goto x86_l_219c;
	case 8613ULL: goto x86_l_21a5;
	case 8620ULL: goto x86_l_21ac;
	case 8625ULL: goto x86_l_21b1;
	case 8630ULL: goto x86_l_21b6;
	case 8635ULL: goto x86_l_21bb;
	case 8640ULL: goto x86_l_21c0;
	case 8642ULL: goto x86_l_21c2;
	case 8647ULL: goto x86_l_21c7;
	case 8649ULL: goto x86_l_21c9;
	case 8652ULL: goto x86_l_21cc;
	case 8658ULL: goto x86_l_21d2;
	case 8661ULL: goto x86_l_21d5;
	case 8667ULL: goto x86_l_21db;
	case 8673ULL: goto x86_l_21e1;
	case 8678ULL: goto x86_l_21e6;
	case 8682ULL: goto x86_l_21ea;
	case 8689ULL: goto x86_l_21f1;
	case 8694ULL: goto x86_l_21f6;
	case 8699ULL: goto x86_l_21fb;
	case 8706ULL: goto x86_l_2202;
	case 8709ULL: goto x86_l_2205;
	case 8716ULL: goto x86_l_220c;
	case 8721ULL: goto x86_l_2211;
	case 8726ULL: goto x86_l_2216;
	case 8728ULL: goto x86_l_2218;
	case 8732ULL: goto x86_l_221c;
	case 8734ULL: goto x86_l_221e;
	case 8736ULL: goto x86_l_2220;
	case 8742ULL: goto x86_l_2226;
	case 8745ULL: goto x86_l_2229;
	case 8751ULL: goto x86_l_222f;
	case 8757ULL: goto x86_l_2235;
	case 8762ULL: goto x86_l_223a;
	case 8766ULL: goto x86_l_223e;
	case 8773ULL: goto x86_l_2245;
	case 8778ULL: goto x86_l_224a;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8796ULL: goto x86_l_225c;
	case 8800ULL: goto x86_l_2260;
	case 8807ULL: goto x86_l_2267;
	case 8812ULL: goto x86_l_226c;
	case 8814ULL: goto x86_l_226e;
	case 8819ULL: goto x86_l_2273;
	case 8827ULL: goto x86_l_227b;
	case 8830ULL: goto x86_l_227e;
	case 8838ULL: goto x86_l_2286;
	case 8847ULL: goto x86_l_228f;
	case 8854ULL: goto x86_l_2296;
	case 8859ULL: goto x86_l_229b;
	case 8864ULL: goto x86_l_22a0;
	case 8869ULL: goto x86_l_22a5;
	case 8874ULL: goto x86_l_22aa;
	case 8876ULL: goto x86_l_22ac;
	case 8881ULL: goto x86_l_22b1;
	case 8883ULL: goto x86_l_22b3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b52:
	/* 0x1b52: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b57:
	/* 0x1b57: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b5c:
	/* 0x1b5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b61:
	/* 0x1b61: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b66:
	/* 0x1b66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b68:
	/* 0x1b68: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b6d:
	/* 0x1b6d: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_1b6f:
	/* 0x1b6f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1b72:
	/* 0x1b72: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_1b78:
	/* 0x1b78: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b7b:
	/* 0x1b7b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1b81:
	/* 0x1b81: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1b87:
	/* 0x1b87: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b8c:
	/* 0x1b8c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1b90:
	/* 0x1b90: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1b97:
	/* 0x1b97: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1b9c:
	/* 0x1b9c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1ba1:
	/* 0x1ba1: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ba8:
	/* 0x1ba8: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1bab:
	/* 0x1bab: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1bb2:
	/* 0x1bb2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bb7:
	/* 0x1bb7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1bbc:
	/* 0x1bbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bbe:
	/* 0x1bbe: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1bc2:
	/* 0x1bc2: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_1bc4:
	/* 0x1bc4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bc6:
	/* 0x1bc6: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_1bcc:
	/* 0x1bcc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1bcf:
	/* 0x1bcf: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1bd5:
	/* 0x1bd5: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1bdb:
	/* 0x1bdb: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1be0:
	/* 0x1be0: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1be4:
	/* 0x1be4: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1beb:
	/* 0x1beb: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1bf0:
	/* 0x1bf0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bf5:
	/* 0x1bf5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bfa:
	/* 0x1bfa: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c02:
	/* 0x1c02: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1c06:
	/* 0x1c06: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1c0d:
	/* 0x1c0d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c12:
	/* 0x1c12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c14:
	/* 0x1c14: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1c19:
	/* 0x1c19: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1c21:
	/* 0x1c21: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1c24:
	/* 0x1c24: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1c2c:
	/* 0x1c2c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c35:
	/* 0x1c35: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c39:
	/* 0x1c39: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c3e:
	/* 0x1c3e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c43:
	/* 0x1c43: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c48:
	/* 0x1c48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c4d:
	/* 0x1c4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c4f:
	/* 0x1c4f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c54:
	/* 0x1c54: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_1c56:
	/* 0x1c56: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1c59:
	/* 0x1c59: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_1c5f:
	/* 0x1c5f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c62:
	/* 0x1c62: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1c68:
	/* 0x1c68: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1c6e:
	/* 0x1c6e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c73:
	/* 0x1c73: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1c77:
	/* 0x1c77: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1c83:
	/* 0x1c83: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1c88:
	/* 0x1c88: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c8f:
	/* 0x1c8f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c92:
	/* 0x1c92: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1c99:
	/* 0x1c99: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c9e:
	/* 0x1c9e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ca3:
	/* 0x1ca3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca5:
	/* 0x1ca5: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ca9:
	/* 0x1ca9: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_1cab:
	/* 0x1cab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cad:
	/* 0x1cad: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_1cb3:
	/* 0x1cb3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1cb6:
	/* 0x1cb6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1cbc:
	/* 0x1cbc: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1cc2:
	/* 0x1cc2: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cc7:
	/* 0x1cc7: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1ccb:
	/* 0x1ccb: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1cd2:
	/* 0x1cd2: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cd7:
	/* 0x1cd7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cdc:
	/* 0x1cdc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ce1:
	/* 0x1ce1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ce9:
	/* 0x1ce9: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1ced:
	/* 0x1ced: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1cf4:
	/* 0x1cf4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cf9:
	/* 0x1cf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cfb:
	/* 0x1cfb: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1d00:
	/* 0x1d00: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1d08:
	/* 0x1d08: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1d0b:
	/* 0x1d0b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1d13:
	/* 0x1d13: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d1c:
	/* 0x1d1c: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1d20:
	/* 0x1d20: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d25:
	/* 0x1d25: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d2a:
	/* 0x1d2a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d2f:
	/* 0x1d2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d34:
	/* 0x1d34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d36:
	/* 0x1d36: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d3b:
	/* 0x1d3b: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_1d3d:
	/* 0x1d3d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1d40:
	/* 0x1d40: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_1d46:
	/* 0x1d46: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d49:
	/* 0x1d49: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1d4f:
	/* 0x1d4f: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1d55:
	/* 0x1d55: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d5a:
	/* 0x1d5a: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1d5e:
	/* 0x1d5e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1d65:
	/* 0x1d65: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1d6a:
	/* 0x1d6a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1d6f:
	/* 0x1d6f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d76:
	/* 0x1d76: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1d79:
	/* 0x1d79: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1d80:
	/* 0x1d80: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d85:
	/* 0x1d85: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1d8a:
	/* 0x1d8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d8c:
	/* 0x1d8c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d90:
	/* 0x1d90: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_1d92:
	/* 0x1d92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d94:
	/* 0x1d94: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_1d9a:
	/* 0x1d9a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d9d:
	/* 0x1d9d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1da3:
	/* 0x1da3: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1da9:
	/* 0x1da9: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dae:
	/* 0x1dae: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1db2:
	/* 0x1db2: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1db9:
	/* 0x1db9: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1dbe:
	/* 0x1dbe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dc3:
	/* 0x1dc3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dc8:
	/* 0x1dc8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1dd0:
	/* 0x1dd0: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1dd4:
	/* 0x1dd4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ddb:
	/* 0x1ddb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1de0:
	/* 0x1de0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de2:
	/* 0x1de2: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1de7:
	/* 0x1de7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1def:
	/* 0x1def: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1df2:
	/* 0x1df2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1dfa:
	/* 0x1dfa: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e03:
	/* 0x1e03: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e07:
	/* 0x1e07: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e0c:
	/* 0x1e0c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e11:
	/* 0x1e11: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e16:
	/* 0x1e16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e1b:
	/* 0x1e1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e1d:
	/* 0x1e1d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e22:
	/* 0x1e22: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_1e24:
	/* 0x1e24: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1e27:
	/* 0x1e27: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_1e2d:
	/* 0x1e2d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e30:
	/* 0x1e30: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1e36:
	/* 0x1e36: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1e3c:
	/* 0x1e3c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e41:
	/* 0x1e41: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1e45:
	/* 0x1e45: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e51:
	/* 0x1e51: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e56:
	/* 0x1e56: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e5d:
	/* 0x1e5d: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e60:
	/* 0x1e60: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1e67:
	/* 0x1e67: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e6c:
	/* 0x1e6c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e71:
	/* 0x1e71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e73:
	/* 0x1e73: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e77:
	/* 0x1e77: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_1e79:
	/* 0x1e79: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e7b:
	/* 0x1e7b: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_1e81:
	/* 0x1e81: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e84:
	/* 0x1e84: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1e8a:
	/* 0x1e8a: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1e90:
	/* 0x1e90: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e95:
	/* 0x1e95: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1e99:
	/* 0x1e99: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ea0:
	/* 0x1ea0: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ea5:
	/* 0x1ea5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1eaa:
	/* 0x1eaa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1eaf:
	/* 0x1eaf: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1eb7:
	/* 0x1eb7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1ebb:
	/* 0x1ebb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ec2:
	/* 0x1ec2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ec7:
	/* 0x1ec7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec9:
	/* 0x1ec9: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1ece:
	/* 0x1ece: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1ed6:
	/* 0x1ed6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1ed9:
	/* 0x1ed9: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1ee1:
	/* 0x1ee1: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1eea:
	/* 0x1eea: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1eee:
	/* 0x1eee: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ef3:
	/* 0x1ef3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ef8:
	/* 0x1ef8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1efd:
	/* 0x1efd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f02:
	/* 0x1f02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f04:
	/* 0x1f04: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f09:
	/* 0x1f09: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1f0b:
	/* 0x1f0b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1f0e:
	/* 0x1f0e: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_1f14:
	/* 0x1f14: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f17:
	/* 0x1f17: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1f1d:
	/* 0x1f1d: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1f23:
	/* 0x1f23: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f28:
	/* 0x1f28: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1f2c:
	/* 0x1f2c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1f33:
	/* 0x1f33: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1f38:
	/* 0x1f38: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f3d:
	/* 0x1f3d: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f44:
	/* 0x1f44: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f47:
	/* 0x1f47: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1f4e:
	/* 0x1f4e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f53:
	/* 0x1f53: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1f58:
	/* 0x1f58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f5a:
	/* 0x1f5a: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f5e:
	/* 0x1f5e: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1f60:
	/* 0x1f60: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f62:
	/* 0x1f62: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_1f68:
	/* 0x1f68: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f6b:
	/* 0x1f6b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1f71:
	/* 0x1f71: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_1f77:
	/* 0x1f77: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f7c:
	/* 0x1f7c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1f80:
	/* 0x1f80: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1f87:
	/* 0x1f87: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f8c:
	/* 0x1f8c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f91:
	/* 0x1f91: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f96:
	/* 0x1f96: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f9e:
	/* 0x1f9e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1fa2:
	/* 0x1fa2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1fa9:
	/* 0x1fa9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fae:
	/* 0x1fae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb0:
	/* 0x1fb0: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1fb5:
	/* 0x1fb5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1fbd:
	/* 0x1fbd: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1fc0:
	/* 0x1fc0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1fc8:
	/* 0x1fc8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1fd1:
	/* 0x1fd1: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1fd8:
	/* 0x1fd8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fdd:
	/* 0x1fdd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1fe2:
	/* 0x1fe2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fe7:
	/* 0x1fe7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fec:
	/* 0x1fec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fee:
	/* 0x1fee: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ff3:
	/* 0x1ff3: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_1ff5:
	/* 0x1ff5: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1ff8:
	/* 0x1ff8: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_1ffe:
	/* 0x1ffe: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2001:
	/* 0x2001: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2007:
	/* 0x2007: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_200d:
	/* 0x200d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2012:
	/* 0x2012: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2016:
	/* 0x2016: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_201d:
	/* 0x201d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2022:
	/* 0x2022: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2027:
	/* 0x2027: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_202e:
	/* 0x202e: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2031:
	/* 0x2031: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2038:
	/* 0x2038: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_203d:
	/* 0x203d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2042:
	/* 0x2042: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2044:
	/* 0x2044: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2048:
	/* 0x2048: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_204a:
	/* 0x204a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_204c:
	/* 0x204c: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_2052:
	/* 0x2052: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2055:
	/* 0x2055: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_205b:
	/* 0x205b: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2061:
	/* 0x2061: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2066:
	/* 0x2066: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_206a:
	/* 0x206a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2071:
	/* 0x2071: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2076:
	/* 0x2076: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_207b:
	/* 0x207b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2080:
	/* 0x2080: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2088:
	/* 0x2088: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_208c:
	/* 0x208c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2093:
	/* 0x2093: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2098:
	/* 0x2098: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_209a:
	/* 0x209a: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_209f:
	/* 0x209f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_20a7:
	/* 0x20a7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_20aa:
	/* 0x20aa: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_20b2:
	/* 0x20b2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_20bb:
	/* 0x20bb: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_20c2:
	/* 0x20c2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20c7:
	/* 0x20c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20cc:
	/* 0x20cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20d1:
	/* 0x20d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20d6:
	/* 0x20d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20d8:
	/* 0x20d8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20dd:
	/* 0x20dd: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_20df:
	/* 0x20df: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_20e2:
	/* 0x20e2: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_20e8:
	/* 0x20e8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20eb:
	/* 0x20eb: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_20f1:
	/* 0x20f1: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_20f7:
	/* 0x20f7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20fc:
	/* 0x20fc: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2100:
	/* 0x2100: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2107:
	/* 0x2107: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_210c:
	/* 0x210c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2111:
	/* 0x2111: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2118:
	/* 0x2118: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_211b:
	/* 0x211b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2122:
	/* 0x2122: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2127:
	/* 0x2127: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_212c:
	/* 0x212c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_212e:
	/* 0x212e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2132:
	/* 0x2132: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_2134:
	/* 0x2134: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2136:
	/* 0x2136: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_213c:
	/* 0x213c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_213f:
	/* 0x213f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2145:
	/* 0x2145: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_214b:
	/* 0x214b: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2150:
	/* 0x2150: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2154:
	/* 0x2154: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_215b:
	/* 0x215b: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2160:
	/* 0x2160: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2165:
	/* 0x2165: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_216a:
	/* 0x216a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2172:
	/* 0x2172: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2176:
	/* 0x2176: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_217d:
	/* 0x217d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2182:
	/* 0x2182: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2184:
	/* 0x2184: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2189:
	/* 0x2189: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2191:
	/* 0x2191: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2194:
	/* 0x2194: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_219c:
	/* 0x219c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_21a5:
	/* 0x21a5: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_21ac:
	/* 0x21ac: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21b1:
	/* 0x21b1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21b6:
	/* 0x21b6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21bb:
	/* 0x21bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21c0:
	/* 0x21c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21c2:
	/* 0x21c2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21c7:
	/* 0x21c7: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_21c9:
	/* 0x21c9: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_21cc:
	/* 0x21cc: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_21d2:
	/* 0x21d2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21d5:
	/* 0x21d5: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_21db:
	/* 0x21db: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_21e1:
	/* 0x21e1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21e6:
	/* 0x21e6: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_21ea:
	/* 0x21ea: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_21f1:
	/* 0x21f1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_21f6:
	/* 0x21f6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_21fb:
	/* 0x21fb: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2202:
	/* 0x2202: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2205:
	/* 0x2205: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_220c:
	/* 0x220c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2211:
	/* 0x2211: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2216:
	/* 0x2216: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2218:
	/* 0x2218: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_221c:
	/* 0x221c: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_221e:
	/* 0x221e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2220:
	/* 0x2220: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_2226:
	/* 0x2226: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2229:
	/* 0x2229: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_222f:
	/* 0x222f: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2235:
	/* 0x2235: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_223a:
	/* 0x223a: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_223e:
	/* 0x223e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2245:
	/* 0x2245: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_224a:
	/* 0x224a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_224f:
	/* 0x224f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2254:
	/* 0x2254: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_225c:
	/* 0x225c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2260:
	/* 0x2260: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2267:
	/* 0x2267: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_226c:
	/* 0x226c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226e:
	/* 0x226e: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2273:
	/* 0x2273: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_227b:
	/* 0x227b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_227e:
	/* 0x227e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2286:
	/* 0x2286: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_228f:
	/* 0x228f: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2296:
	/* 0x2296: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_229b:
	/* 0x229b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22a0:
	/* 0x22a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22a5:
	/* 0x22a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22aa:
	/* 0x22aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ac:
	/* 0x22ac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b1:
	/* 0x22b1: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_22b3:
	/* 0x22b3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
	return 8886ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8886ULL: goto x86_l_22b6;
	case 8892ULL: goto x86_l_22bc;
	case 8895ULL: goto x86_l_22bf;
	case 8901ULL: goto x86_l_22c5;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8916ULL: goto x86_l_22d4;
	case 8923ULL: goto x86_l_22db;
	case 8928ULL: goto x86_l_22e0;
	case 8933ULL: goto x86_l_22e5;
	case 8940ULL: goto x86_l_22ec;
	case 8943ULL: goto x86_l_22ef;
	case 8950ULL: goto x86_l_22f6;
	case 8955ULL: goto x86_l_22fb;
	case 8960ULL: goto x86_l_2300;
	case 8962ULL: goto x86_l_2302;
	case 8966ULL: goto x86_l_2306;
	case 8968ULL: goto x86_l_2308;
	case 8970ULL: goto x86_l_230a;
	case 8976ULL: goto x86_l_2310;
	case 8979ULL: goto x86_l_2313;
	case 8985ULL: goto x86_l_2319;
	case 8991ULL: goto x86_l_231f;
	case 8996ULL: goto x86_l_2324;
	case 9000ULL: goto x86_l_2328;
	case 9007ULL: goto x86_l_232f;
	case 9012ULL: goto x86_l_2334;
	case 9017ULL: goto x86_l_2339;
	case 9022ULL: goto x86_l_233e;
	case 9030ULL: goto x86_l_2346;
	case 9034ULL: goto x86_l_234a;
	case 9041ULL: goto x86_l_2351;
	case 9046ULL: goto x86_l_2356;
	case 9048ULL: goto x86_l_2358;
	case 9053ULL: goto x86_l_235d;
	case 9061ULL: goto x86_l_2365;
	case 9064ULL: goto x86_l_2368;
	case 9072ULL: goto x86_l_2370;
	case 9081ULL: goto x86_l_2379;
	case 9088ULL: goto x86_l_2380;
	case 9093ULL: goto x86_l_2385;
	case 9098ULL: goto x86_l_238a;
	case 9103ULL: goto x86_l_238f;
	case 9108ULL: goto x86_l_2394;
	case 9110ULL: goto x86_l_2396;
	case 9115ULL: goto x86_l_239b;
	case 9117ULL: goto x86_l_239d;
	case 9120ULL: goto x86_l_23a0;
	case 9126ULL: goto x86_l_23a6;
	case 9129ULL: goto x86_l_23a9;
	case 9135ULL: goto x86_l_23af;
	case 9141ULL: goto x86_l_23b5;
	case 9146ULL: goto x86_l_23ba;
	case 9150ULL: goto x86_l_23be;
	case 9157ULL: goto x86_l_23c5;
	case 9162ULL: goto x86_l_23ca;
	case 9167ULL: goto x86_l_23cf;
	case 9174ULL: goto x86_l_23d6;
	case 9177ULL: goto x86_l_23d9;
	case 9184ULL: goto x86_l_23e0;
	case 9189ULL: goto x86_l_23e5;
	case 9194ULL: goto x86_l_23ea;
	case 9196ULL: goto x86_l_23ec;
	case 9200ULL: goto x86_l_23f0;
	case 9202ULL: goto x86_l_23f2;
	case 9204ULL: goto x86_l_23f4;
	case 9210ULL: goto x86_l_23fa;
	case 9213ULL: goto x86_l_23fd;
	case 9219ULL: goto x86_l_2403;
	case 9225ULL: goto x86_l_2409;
	case 9230ULL: goto x86_l_240e;
	case 9234ULL: goto x86_l_2412;
	case 9241ULL: goto x86_l_2419;
	case 9246ULL: goto x86_l_241e;
	case 9251ULL: goto x86_l_2423;
	case 9256ULL: goto x86_l_2428;
	case 9264ULL: goto x86_l_2430;
	case 9268ULL: goto x86_l_2434;
	case 9275ULL: goto x86_l_243b;
	case 9280ULL: goto x86_l_2440;
	case 9282ULL: goto x86_l_2442;
	case 9287ULL: goto x86_l_2447;
	case 9295ULL: goto x86_l_244f;
	case 9298ULL: goto x86_l_2452;
	case 9306ULL: goto x86_l_245a;
	case 9315ULL: goto x86_l_2463;
	case 9322ULL: goto x86_l_246a;
	case 9327ULL: goto x86_l_246f;
	case 9332ULL: goto x86_l_2474;
	case 9337ULL: goto x86_l_2479;
	case 9342ULL: goto x86_l_247e;
	case 9344ULL: goto x86_l_2480;
	case 9349ULL: goto x86_l_2485;
	case 9351ULL: goto x86_l_2487;
	case 9354ULL: goto x86_l_248a;
	case 9360ULL: goto x86_l_2490;
	case 9363ULL: goto x86_l_2493;
	case 9369ULL: goto x86_l_2499;
	case 9375ULL: goto x86_l_249f;
	case 9380ULL: goto x86_l_24a4;
	case 9384ULL: goto x86_l_24a8;
	case 9391ULL: goto x86_l_24af;
	case 9396ULL: goto x86_l_24b4;
	case 9401ULL: goto x86_l_24b9;
	case 9408ULL: goto x86_l_24c0;
	case 9411ULL: goto x86_l_24c3;
	case 9418ULL: goto x86_l_24ca;
	case 9423ULL: goto x86_l_24cf;
	case 9428ULL: goto x86_l_24d4;
	case 9430ULL: goto x86_l_24d6;
	case 9434ULL: goto x86_l_24da;
	case 9436ULL: goto x86_l_24dc;
	case 9438ULL: goto x86_l_24de;
	case 9444ULL: goto x86_l_24e4;
	case 9447ULL: goto x86_l_24e7;
	case 9453ULL: goto x86_l_24ed;
	case 9459ULL: goto x86_l_24f3;
	case 9464ULL: goto x86_l_24f8;
	case 9468ULL: goto x86_l_24fc;
	case 9475ULL: goto x86_l_2503;
	case 9480ULL: goto x86_l_2508;
	case 9485ULL: goto x86_l_250d;
	case 9490ULL: goto x86_l_2512;
	case 9498ULL: goto x86_l_251a;
	case 9502ULL: goto x86_l_251e;
	case 9509ULL: goto x86_l_2525;
	case 9514ULL: goto x86_l_252a;
	case 9516ULL: goto x86_l_252c;
	case 9521ULL: goto x86_l_2531;
	case 9529ULL: goto x86_l_2539;
	case 9532ULL: goto x86_l_253c;
	case 9540ULL: goto x86_l_2544;
	case 9549ULL: goto x86_l_254d;
	case 9556ULL: goto x86_l_2554;
	case 9561ULL: goto x86_l_2559;
	case 9566ULL: goto x86_l_255e;
	case 9571ULL: goto x86_l_2563;
	case 9576ULL: goto x86_l_2568;
	case 9578ULL: goto x86_l_256a;
	case 9583ULL: goto x86_l_256f;
	case 9585ULL: goto x86_l_2571;
	case 9588ULL: goto x86_l_2574;
	case 9594ULL: goto x86_l_257a;
	case 9597ULL: goto x86_l_257d;
	case 9603ULL: goto x86_l_2583;
	case 9609ULL: goto x86_l_2589;
	case 9614ULL: goto x86_l_258e;
	case 9618ULL: goto x86_l_2592;
	case 9625ULL: goto x86_l_2599;
	case 9630ULL: goto x86_l_259e;
	case 9635ULL: goto x86_l_25a3;
	case 9642ULL: goto x86_l_25aa;
	case 9645ULL: goto x86_l_25ad;
	case 9652ULL: goto x86_l_25b4;
	case 9657ULL: goto x86_l_25b9;
	case 9662ULL: goto x86_l_25be;
	case 9664ULL: goto x86_l_25c0;
	case 9668ULL: goto x86_l_25c4;
	case 9670ULL: goto x86_l_25c6;
	case 9672ULL: goto x86_l_25c8;
	case 9678ULL: goto x86_l_25ce;
	case 9681ULL: goto x86_l_25d1;
	case 9687ULL: goto x86_l_25d7;
	case 9693ULL: goto x86_l_25dd;
	case 9698ULL: goto x86_l_25e2;
	case 9702ULL: goto x86_l_25e6;
	case 9709ULL: goto x86_l_25ed;
	case 9714ULL: goto x86_l_25f2;
	case 9719ULL: goto x86_l_25f7;
	case 9724ULL: goto x86_l_25fc;
	case 9732ULL: goto x86_l_2604;
	case 9736ULL: goto x86_l_2608;
	case 9743ULL: goto x86_l_260f;
	case 9748ULL: goto x86_l_2614;
	case 9750ULL: goto x86_l_2616;
	case 9755ULL: goto x86_l_261b;
	case 9763ULL: goto x86_l_2623;
	case 9766ULL: goto x86_l_2626;
	case 9774ULL: goto x86_l_262e;
	case 9783ULL: goto x86_l_2637;
	case 9790ULL: goto x86_l_263e;
	case 9795ULL: goto x86_l_2643;
	case 9800ULL: goto x86_l_2648;
	case 9805ULL: goto x86_l_264d;
	case 9810ULL: goto x86_l_2652;
	case 9812ULL: goto x86_l_2654;
	case 9817ULL: goto x86_l_2659;
	case 9819ULL: goto x86_l_265b;
	case 9822ULL: goto x86_l_265e;
	case 9828ULL: goto x86_l_2664;
	case 9831ULL: goto x86_l_2667;
	case 9837ULL: goto x86_l_266d;
	case 9843ULL: goto x86_l_2673;
	case 9848ULL: goto x86_l_2678;
	case 9852ULL: goto x86_l_267c;
	case 9859ULL: goto x86_l_2683;
	case 9864ULL: goto x86_l_2688;
	case 9869ULL: goto x86_l_268d;
	case 9876ULL: goto x86_l_2694;
	case 9879ULL: goto x86_l_2697;
	case 9886ULL: goto x86_l_269e;
	case 9891ULL: goto x86_l_26a3;
	case 9896ULL: goto x86_l_26a8;
	case 9898ULL: goto x86_l_26aa;
	case 9902ULL: goto x86_l_26ae;
	case 9904ULL: goto x86_l_26b0;
	case 9906ULL: goto x86_l_26b2;
	case 9912ULL: goto x86_l_26b8;
	case 9915ULL: goto x86_l_26bb;
	case 9921ULL: goto x86_l_26c1;
	case 9927ULL: goto x86_l_26c7;
	case 9932ULL: goto x86_l_26cc;
	case 9936ULL: goto x86_l_26d0;
	case 9943ULL: goto x86_l_26d7;
	case 9948ULL: goto x86_l_26dc;
	case 9953ULL: goto x86_l_26e1;
	case 9958ULL: goto x86_l_26e6;
	case 9966ULL: goto x86_l_26ee;
	case 9970ULL: goto x86_l_26f2;
	case 9977ULL: goto x86_l_26f9;
	case 9982ULL: goto x86_l_26fe;
	case 9984ULL: goto x86_l_2700;
	case 9989ULL: goto x86_l_2705;
	case 9997ULL: goto x86_l_270d;
	case 10000ULL: goto x86_l_2710;
	case 10008ULL: goto x86_l_2718;
	case 10017ULL: goto x86_l_2721;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10034ULL: goto x86_l_2732;
	case 10039ULL: goto x86_l_2737;
	case 10044ULL: goto x86_l_273c;
	case 10046ULL: goto x86_l_273e;
	case 10051ULL: goto x86_l_2743;
	case 10053ULL: goto x86_l_2745;
	case 10056ULL: goto x86_l_2748;
	case 10062ULL: goto x86_l_274e;
	case 10065ULL: goto x86_l_2751;
	case 10071ULL: goto x86_l_2757;
	case 10077ULL: goto x86_l_275d;
	case 10082ULL: goto x86_l_2762;
	case 10086ULL: goto x86_l_2766;
	case 10093ULL: goto x86_l_276d;
	case 10098ULL: goto x86_l_2772;
	case 10103ULL: goto x86_l_2777;
	case 10110ULL: goto x86_l_277e;
	case 10113ULL: goto x86_l_2781;
	case 10120ULL: goto x86_l_2788;
	case 10125ULL: goto x86_l_278d;
	case 10130ULL: goto x86_l_2792;
	case 10132ULL: goto x86_l_2794;
	case 10136ULL: goto x86_l_2798;
	case 10138ULL: goto x86_l_279a;
	case 10140ULL: goto x86_l_279c;
	case 10146ULL: goto x86_l_27a2;
	case 10149ULL: goto x86_l_27a5;
	case 10155ULL: goto x86_l_27ab;
	case 10161ULL: goto x86_l_27b1;
	case 10166ULL: goto x86_l_27b6;
	case 10170ULL: goto x86_l_27ba;
	case 10177ULL: goto x86_l_27c1;
	case 10182ULL: goto x86_l_27c6;
	case 10187ULL: goto x86_l_27cb;
	case 10192ULL: goto x86_l_27d0;
	case 10200ULL: goto x86_l_27d8;
	case 10204ULL: goto x86_l_27dc;
	case 10211ULL: goto x86_l_27e3;
	case 10216ULL: goto x86_l_27e8;
	case 10218ULL: goto x86_l_27ea;
	case 10223ULL: goto x86_l_27ef;
	case 10231ULL: goto x86_l_27f7;
	case 10234ULL: goto x86_l_27fa;
	case 10242ULL: goto x86_l_2802;
	case 10251ULL: goto x86_l_280b;
	case 10258ULL: goto x86_l_2812;
	case 10263ULL: goto x86_l_2817;
	case 10268ULL: goto x86_l_281c;
	case 10273ULL: goto x86_l_2821;
	case 10278ULL: goto x86_l_2826;
	case 10280ULL: goto x86_l_2828;
	case 10285ULL: goto x86_l_282d;
	case 10287ULL: goto x86_l_282f;
	case 10290ULL: goto x86_l_2832;
	case 10296ULL: goto x86_l_2838;
	case 10299ULL: goto x86_l_283b;
	case 10305ULL: goto x86_l_2841;
	case 10311ULL: goto x86_l_2847;
	case 10316ULL: goto x86_l_284c;
	case 10320ULL: goto x86_l_2850;
	case 10327ULL: goto x86_l_2857;
	case 10332ULL: goto x86_l_285c;
	case 10337ULL: goto x86_l_2861;
	case 10344ULL: goto x86_l_2868;
	case 10347ULL: goto x86_l_286b;
	case 10354ULL: goto x86_l_2872;
	case 10359ULL: goto x86_l_2877;
	case 10364ULL: goto x86_l_287c;
	case 10366ULL: goto x86_l_287e;
	case 10370ULL: goto x86_l_2882;
	case 10372ULL: goto x86_l_2884;
	case 10374ULL: goto x86_l_2886;
	case 10380ULL: goto x86_l_288c;
	case 10383ULL: goto x86_l_288f;
	case 10389ULL: goto x86_l_2895;
	case 10395ULL: goto x86_l_289b;
	case 10400ULL: goto x86_l_28a0;
	case 10404ULL: goto x86_l_28a4;
	case 10411ULL: goto x86_l_28ab;
	case 10416ULL: goto x86_l_28b0;
	case 10421ULL: goto x86_l_28b5;
	case 10426ULL: goto x86_l_28ba;
	case 10434ULL: goto x86_l_28c2;
	case 10438ULL: goto x86_l_28c6;
	case 10445ULL: goto x86_l_28cd;
	case 10450ULL: goto x86_l_28d2;
	case 10452ULL: goto x86_l_28d4;
	case 10457ULL: goto x86_l_28d9;
	case 10465ULL: goto x86_l_28e1;
	case 10468ULL: goto x86_l_28e4;
	case 10476ULL: goto x86_l_28ec;
	case 10485ULL: goto x86_l_28f5;
	case 10492ULL: goto x86_l_28fc;
	case 10497ULL: goto x86_l_2901;
	case 10502ULL: goto x86_l_2906;
	case 10507ULL: goto x86_l_290b;
	case 10512ULL: goto x86_l_2910;
	case 10514ULL: goto x86_l_2912;
	case 10519ULL: goto x86_l_2917;
	case 10521ULL: goto x86_l_2919;
	case 10524ULL: goto x86_l_291c;
	case 10530ULL: goto x86_l_2922;
	case 10533ULL: goto x86_l_2925;
	case 10539ULL: goto x86_l_292b;
	case 10545ULL: goto x86_l_2931;
	case 10550ULL: goto x86_l_2936;
	case 10554ULL: goto x86_l_293a;
	case 10561ULL: goto x86_l_2941;
	case 10566ULL: goto x86_l_2946;
	case 10571ULL: goto x86_l_294b;
	case 10578ULL: goto x86_l_2952;
	case 10581ULL: goto x86_l_2955;
	case 10588ULL: goto x86_l_295c;
	case 10593ULL: goto x86_l_2961;
	case 10598ULL: goto x86_l_2966;
	case 10600ULL: goto x86_l_2968;
	case 10604ULL: goto x86_l_296c;
	case 10606ULL: goto x86_l_296e;
	case 10608ULL: goto x86_l_2970;
	case 10614ULL: goto x86_l_2976;
	case 10617ULL: goto x86_l_2979;
	case 10623ULL: goto x86_l_297f;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10638ULL: goto x86_l_298e;
	case 10645ULL: goto x86_l_2995;
	case 10650ULL: goto x86_l_299a;
	case 10655ULL: goto x86_l_299f;
	case 10660ULL: goto x86_l_29a4;
	case 10668ULL: goto x86_l_29ac;
	case 10672ULL: goto x86_l_29b0;
	case 10679ULL: goto x86_l_29b7;
	case 10684ULL: goto x86_l_29bc;
	case 10686ULL: goto x86_l_29be;
	case 10691ULL: goto x86_l_29c3;
	case 10699ULL: goto x86_l_29cb;
	case 10702ULL: goto x86_l_29ce;
	case 10710ULL: goto x86_l_29d6;
	case 10719ULL: goto x86_l_29df;
	case 10726ULL: goto x86_l_29e6;
	case 10731ULL: goto x86_l_29eb;
	case 10736ULL: goto x86_l_29f0;
	case 10741ULL: goto x86_l_29f5;
	case 10746ULL: goto x86_l_29fa;
	case 10748ULL: goto x86_l_29fc;
	case 10753ULL: goto x86_l_2a01;
	case 10755ULL: goto x86_l_2a03;
	case 10758ULL: goto x86_l_2a06;
	case 10764ULL: goto x86_l_2a0c;
	case 10767ULL: goto x86_l_2a0f;
	case 10773ULL: goto x86_l_2a15;
	case 10779ULL: goto x86_l_2a1b;
	case 10784ULL: goto x86_l_2a20;
	case 10788ULL: goto x86_l_2a24;
	case 10795ULL: goto x86_l_2a2b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22b6:
	/* 0x22b6: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_22bc:
	/* 0x22bc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22bf:
	/* 0x22bf: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_22c5:
	/* 0x22c5: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_22cb:
	/* 0x22cb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22d0:
	/* 0x22d0: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_22d4:
	/* 0x22d4: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_22db:
	/* 0x22db: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_22e0:
	/* 0x22e0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_22e5:
	/* 0x22e5: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_22ec:
	/* 0x22ec: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22ef:
	/* 0x22ef: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_22f6:
	/* 0x22f6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22fb:
	/* 0x22fb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2300:
	/* 0x2300: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2302:
	/* 0x2302: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2306:
	/* 0x2306: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_2308:
	/* 0x2308: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_230a:
	/* 0x230a: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_2310:
	/* 0x2310: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2313:
	/* 0x2313: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2319:
	/* 0x2319: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_231f:
	/* 0x231f: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2324:
	/* 0x2324: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2328:
	/* 0x2328: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_232f:
	/* 0x232f: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2334:
	/* 0x2334: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2339:
	/* 0x2339: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_233e:
	/* 0x233e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2346:
	/* 0x2346: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_234a:
	/* 0x234a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2351:
	/* 0x2351: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2356:
	/* 0x2356: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2358:
	/* 0x2358: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_235d:
	/* 0x235d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2365:
	/* 0x2365: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2368:
	/* 0x2368: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2370:
	/* 0x2370: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2379:
	/* 0x2379: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2380:
	/* 0x2380: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2385:
	/* 0x2385: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_238a:
	/* 0x238a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_238f:
	/* 0x238f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2394:
	/* 0x2394: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2396:
	/* 0x2396: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_239b:
	/* 0x239b: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_239d:
	/* 0x239d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_23a0:
	/* 0x23a0: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_23a6:
	/* 0x23a6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23a9:
	/* 0x23a9: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_23af:
	/* 0x23af: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_23b5:
	/* 0x23b5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ba:
	/* 0x23ba: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_23be:
	/* 0x23be: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_23c5:
	/* 0x23c5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_23ca:
	/* 0x23ca: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_23cf:
	/* 0x23cf: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_23d6:
	/* 0x23d6: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23d9:
	/* 0x23d9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_23e0:
	/* 0x23e0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23e5:
	/* 0x23e5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_23ea:
	/* 0x23ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ec:
	/* 0x23ec: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_23f0:
	/* 0x23f0: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_23f2:
	/* 0x23f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23f4:
	/* 0x23f4: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_23fa:
	/* 0x23fa: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23fd:
	/* 0x23fd: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2403:
	/* 0x2403: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2409:
	/* 0x2409: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_240e:
	/* 0x240e: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2412:
	/* 0x2412: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2419:
	/* 0x2419: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_241e:
	/* 0x241e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2423:
	/* 0x2423: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2428:
	/* 0x2428: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2430:
	/* 0x2430: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2434:
	/* 0x2434: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_243b:
	/* 0x243b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2440:
	/* 0x2440: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2442:
	/* 0x2442: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2447:
	/* 0x2447: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_244f:
	/* 0x244f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2452:
	/* 0x2452: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_245a:
	/* 0x245a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2463:
	/* 0x2463: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_246a:
	/* 0x246a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_246f:
	/* 0x246f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2474:
	/* 0x2474: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2479:
	/* 0x2479: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_247e:
	/* 0x247e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2480:
	/* 0x2480: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2485:
	/* 0x2485: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_2487:
	/* 0x2487: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_248a:
	/* 0x248a: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_2490:
	/* 0x2490: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2493:
	/* 0x2493: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2499:
	/* 0x2499: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_249f:
	/* 0x249f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24a4:
	/* 0x24a4: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_24a8:
	/* 0x24a8: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_24af:
	/* 0x24af: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_24b4:
	/* 0x24b4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_24b9:
	/* 0x24b9: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_24c0:
	/* 0x24c0: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24c3:
	/* 0x24c3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_24ca:
	/* 0x24ca: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24cf:
	/* 0x24cf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_24d4:
	/* 0x24d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d6:
	/* 0x24d6: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_24da:
	/* 0x24da: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_24dc:
	/* 0x24dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24de:
	/* 0x24de: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_24e4:
	/* 0x24e4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24e7:
	/* 0x24e7: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_24ed:
	/* 0x24ed: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_24f3:
	/* 0x24f3: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24f8:
	/* 0x24f8: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_24fc:
	/* 0x24fc: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2503:
	/* 0x2503: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2508:
	/* 0x2508: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_250d:
	/* 0x250d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2512:
	/* 0x2512: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_251a:
	/* 0x251a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_251e:
	/* 0x251e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2525:
	/* 0x2525: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_252a:
	/* 0x252a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_252c:
	/* 0x252c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2531:
	/* 0x2531: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2539:
	/* 0x2539: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_253c:
	/* 0x253c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2544:
	/* 0x2544: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_254d:
	/* 0x254d: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2554:
	/* 0x2554: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2559:
	/* 0x2559: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_255e:
	/* 0x255e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2563:
	/* 0x2563: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2568:
	/* 0x2568: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_256a:
	/* 0x256a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_256f:
	/* 0x256f: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_2571:
	/* 0x2571: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2574:
	/* 0x2574: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_257a:
	/* 0x257a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_257d:
	/* 0x257d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2583:
	/* 0x2583: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2589:
	/* 0x2589: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_258e:
	/* 0x258e: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2592:
	/* 0x2592: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2599:
	/* 0x2599: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_259e:
	/* 0x259e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_25a3:
	/* 0x25a3: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_25aa:
	/* 0x25aa: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25ad:
	/* 0x25ad: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_25b4:
	/* 0x25b4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25b9:
	/* 0x25b9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_25be:
	/* 0x25be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25c0:
	/* 0x25c0: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25c4:
	/* 0x25c4: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_25c6:
	/* 0x25c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25c8:
	/* 0x25c8: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_25ce:
	/* 0x25ce: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25d1:
	/* 0x25d1: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_25d7:
	/* 0x25d7: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_25dd:
	/* 0x25dd: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25e2:
	/* 0x25e2: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_25e6:
	/* 0x25e6: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_25ed:
	/* 0x25ed: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25f2:
	/* 0x25f2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_25f7:
	/* 0x25f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25fc:
	/* 0x25fc: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2604:
	/* 0x2604: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2608:
	/* 0x2608: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_260f:
	/* 0x260f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2614:
	/* 0x2614: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2616:
	/* 0x2616: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_261b:
	/* 0x261b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2623:
	/* 0x2623: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2626:
	/* 0x2626: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_262e:
	/* 0x262e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2637:
	/* 0x2637: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_263e:
	/* 0x263e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2643:
	/* 0x2643: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2648:
	/* 0x2648: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_264d:
	/* 0x264d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2652:
	/* 0x2652: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2654:
	/* 0x2654: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2659:
	/* 0x2659: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_265b:
	/* 0x265b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_265e:
	/* 0x265e: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_2664:
	/* 0x2664: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2667:
	/* 0x2667: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_266d:
	/* 0x266d: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2673:
	/* 0x2673: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2678:
	/* 0x2678: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_267c:
	/* 0x267c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2683:
	/* 0x2683: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2688:
	/* 0x2688: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_268d:
	/* 0x268d: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2694:
	/* 0x2694: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2697:
	/* 0x2697: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_269e:
	/* 0x269e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26a3:
	/* 0x26a3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_26a8:
	/* 0x26a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26aa:
	/* 0x26aa: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_26ae:
	/* 0x26ae: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_26b0:
	/* 0x26b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26b2:
	/* 0x26b2: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_26b8:
	/* 0x26b8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26bb:
	/* 0x26bb: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_26c1:
	/* 0x26c1: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_26c7:
	/* 0x26c7: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26cc:
	/* 0x26cc: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_26d0:
	/* 0x26d0: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_26d7:
	/* 0x26d7: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_26dc:
	/* 0x26dc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26e1:
	/* 0x26e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26e6:
	/* 0x26e6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_26ee:
	/* 0x26ee: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_26f2:
	/* 0x26f2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_26f9:
	/* 0x26f9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26fe:
	/* 0x26fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2700:
	/* 0x2700: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2705:
	/* 0x2705: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_270d:
	/* 0x270d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2710:
	/* 0x2710: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2718:
	/* 0x2718: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2721:
	/* 0x2721: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2728:
	/* 0x2728: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_272d:
	/* 0x272d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2732:
	/* 0x2732: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2737:
	/* 0x2737: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_273c:
	/* 0x273c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_273e:
	/* 0x273e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2743:
	/* 0x2743: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_2745:
	/* 0x2745: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2748:
	/* 0x2748: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_274e:
	/* 0x274e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2751:
	/* 0x2751: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2757:
	/* 0x2757: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_275d:
	/* 0x275d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2762:
	/* 0x2762: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2766:
	/* 0x2766: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_276d:
	/* 0x276d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2772:
	/* 0x2772: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2777:
	/* 0x2777: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_277e:
	/* 0x277e: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2781:
	/* 0x2781: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2788:
	/* 0x2788: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_278d:
	/* 0x278d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2792:
	/* 0x2792: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2794:
	/* 0x2794: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2798:
	/* 0x2798: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_279a:
	/* 0x279a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_279c:
	/* 0x279c: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_27a2:
	/* 0x27a2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27a5:
	/* 0x27a5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_27ab:
	/* 0x27ab: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_27b1:
	/* 0x27b1: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27b6:
	/* 0x27b6: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_27ba:
	/* 0x27ba: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_27c1:
	/* 0x27c1: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_27c6:
	/* 0x27c6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_27cb:
	/* 0x27cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27d0:
	/* 0x27d0: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_27d8:
	/* 0x27d8: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_27dc:
	/* 0x27dc: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_27e3:
	/* 0x27e3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_27e8:
	/* 0x27e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ea:
	/* 0x27ea: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_27ef:
	/* 0x27ef: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_27f7:
	/* 0x27f7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_27fa:
	/* 0x27fa: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2802:
	/* 0x2802: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_280b:
	/* 0x280b: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2812:
	/* 0x2812: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2817:
	/* 0x2817: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_281c:
	/* 0x281c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2821:
	/* 0x2821: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2826:
	/* 0x2826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2828:
	/* 0x2828: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_282d:
	/* 0x282d: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_282f:
	/* 0x282f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2832:
	/* 0x2832: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_2838:
	/* 0x2838: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_283b:
	/* 0x283b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2841:
	/* 0x2841: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2847:
	/* 0x2847: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_284c:
	/* 0x284c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2850:
	/* 0x2850: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2857:
	/* 0x2857: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_285c:
	/* 0x285c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2861:
	/* 0x2861: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2868:
	/* 0x2868: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_286b:
	/* 0x286b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2872:
	/* 0x2872: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2877:
	/* 0x2877: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_287c:
	/* 0x287c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287e:
	/* 0x287e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2882:
	/* 0x2882: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_2884:
	/* 0x2884: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2886:
	/* 0x2886: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_288c:
	/* 0x288c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_288f:
	/* 0x288f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2895:
	/* 0x2895: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_289b:
	/* 0x289b: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28a0:
	/* 0x28a0: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_28a4:
	/* 0x28a4: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_28ab:
	/* 0x28ab: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_28b0:
	/* 0x28b0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28b5:
	/* 0x28b5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28ba:
	/* 0x28ba: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_28c2:
	/* 0x28c2: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_28c6:
	/* 0x28c6: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_28cd:
	/* 0x28cd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28d2:
	/* 0x28d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d4:
	/* 0x28d4: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_28d9:
	/* 0x28d9: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_28e1:
	/* 0x28e1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_28e4:
	/* 0x28e4: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_28ec:
	/* 0x28ec: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_28f5:
	/* 0x28f5: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_28fc:
	/* 0x28fc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2901:
	/* 0x2901: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2906:
	/* 0x2906: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_290b:
	/* 0x290b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2910:
	/* 0x2910: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2912:
	/* 0x2912: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2917:
	/* 0x2917: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_2919:
	/* 0x2919: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_291c:
	/* 0x291c: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_2922:
	/* 0x2922: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2925:
	/* 0x2925: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_292b:
	/* 0x292b: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2931:
	/* 0x2931: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2936:
	/* 0x2936: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_293a:
	/* 0x293a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2941:
	/* 0x2941: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2946:
	/* 0x2946: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_294b:
	/* 0x294b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2952:
	/* 0x2952: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2955:
	/* 0x2955: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_295c:
	/* 0x295c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2961:
	/* 0x2961: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2966:
	/* 0x2966: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2968:
	/* 0x2968: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_296c:
	/* 0x296c: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_296e:
	/* 0x296e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2970:
	/* 0x2970: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_2976:
	/* 0x2976: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2979:
	/* 0x2979: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_297f:
	/* 0x297f: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2985:
	/* 0x2985: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_298a:
	/* 0x298a: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_298e:
	/* 0x298e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2995:
	/* 0x2995: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_299a:
	/* 0x299a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_299f:
	/* 0x299f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29a4:
	/* 0x29a4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_29ac:
	/* 0x29ac: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_29b0:
	/* 0x29b0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_29b7:
	/* 0x29b7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29bc:
	/* 0x29bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29be:
	/* 0x29be: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_29c3:
	/* 0x29c3: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_29cb:
	/* 0x29cb: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_29ce:
	/* 0x29ce: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_29d6:
	/* 0x29d6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_29df:
	/* 0x29df: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_29e6:
	/* 0x29e6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29eb:
	/* 0x29eb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29f0:
	/* 0x29f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29f5:
	/* 0x29f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29fa:
	/* 0x29fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29fc:
	/* 0x29fc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a01:
	/* 0x2a01: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_2a03:
	/* 0x2a03: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2a06:
	/* 0x2a06: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_2a0c:
	/* 0x2a0c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a0f:
	/* 0x2a0f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2a15:
	/* 0x2a15: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2a1b:
	/* 0x2a1b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a20:
	/* 0x2a20: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2a24:
	/* 0x2a24: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2a2b:
	/* 0x2a2b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
	return 10800ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10800ULL: goto x86_l_2a30;
	case 10805ULL: goto x86_l_2a35;
	case 10812ULL: goto x86_l_2a3c;
	case 10815ULL: goto x86_l_2a3f;
	case 10822ULL: goto x86_l_2a46;
	case 10827ULL: goto x86_l_2a4b;
	case 10832ULL: goto x86_l_2a50;
	case 10834ULL: goto x86_l_2a52;
	case 10838ULL: goto x86_l_2a56;
	case 10840ULL: goto x86_l_2a58;
	case 10842ULL: goto x86_l_2a5a;
	case 10848ULL: goto x86_l_2a60;
	case 10851ULL: goto x86_l_2a63;
	case 10857ULL: goto x86_l_2a69;
	case 10863ULL: goto x86_l_2a6f;
	case 10868ULL: goto x86_l_2a74;
	case 10872ULL: goto x86_l_2a78;
	case 10879ULL: goto x86_l_2a7f;
	case 10884ULL: goto x86_l_2a84;
	case 10889ULL: goto x86_l_2a89;
	case 10894ULL: goto x86_l_2a8e;
	case 10902ULL: goto x86_l_2a96;
	case 10906ULL: goto x86_l_2a9a;
	case 10913ULL: goto x86_l_2aa1;
	case 10918ULL: goto x86_l_2aa6;
	case 10920ULL: goto x86_l_2aa8;
	case 10925ULL: goto x86_l_2aad;
	case 10933ULL: goto x86_l_2ab5;
	case 10936ULL: goto x86_l_2ab8;
	case 10944ULL: goto x86_l_2ac0;
	case 10953ULL: goto x86_l_2ac9;
	case 10960ULL: goto x86_l_2ad0;
	case 10965ULL: goto x86_l_2ad5;
	case 10970ULL: goto x86_l_2ada;
	case 10975ULL: goto x86_l_2adf;
	case 10980ULL: goto x86_l_2ae4;
	case 10982ULL: goto x86_l_2ae6;
	case 10987ULL: goto x86_l_2aeb;
	case 10989ULL: goto x86_l_2aed;
	case 10992ULL: goto x86_l_2af0;
	case 10998ULL: goto x86_l_2af6;
	case 11001ULL: goto x86_l_2af9;
	case 11007ULL: goto x86_l_2aff;
	case 11013ULL: goto x86_l_2b05;
	case 11018ULL: goto x86_l_2b0a;
	case 11022ULL: goto x86_l_2b0e;
	case 11029ULL: goto x86_l_2b15;
	case 11034ULL: goto x86_l_2b1a;
	case 11039ULL: goto x86_l_2b1f;
	case 11046ULL: goto x86_l_2b26;
	case 11049ULL: goto x86_l_2b29;
	case 11056ULL: goto x86_l_2b30;
	case 11061ULL: goto x86_l_2b35;
	case 11066ULL: goto x86_l_2b3a;
	case 11068ULL: goto x86_l_2b3c;
	case 11072ULL: goto x86_l_2b40;
	case 11074ULL: goto x86_l_2b42;
	case 11076ULL: goto x86_l_2b44;
	case 11082ULL: goto x86_l_2b4a;
	case 11085ULL: goto x86_l_2b4d;
	case 11091ULL: goto x86_l_2b53;
	case 11097ULL: goto x86_l_2b59;
	case 11102ULL: goto x86_l_2b5e;
	case 11106ULL: goto x86_l_2b62;
	case 11113ULL: goto x86_l_2b69;
	case 11118ULL: goto x86_l_2b6e;
	case 11123ULL: goto x86_l_2b73;
	case 11128ULL: goto x86_l_2b78;
	case 11136ULL: goto x86_l_2b80;
	case 11140ULL: goto x86_l_2b84;
	case 11147ULL: goto x86_l_2b8b;
	case 11152ULL: goto x86_l_2b90;
	case 11154ULL: goto x86_l_2b92;
	case 11159ULL: goto x86_l_2b97;
	case 11167ULL: goto x86_l_2b9f;
	case 11170ULL: goto x86_l_2ba2;
	case 11178ULL: goto x86_l_2baa;
	case 11187ULL: goto x86_l_2bb3;
	case 11194ULL: goto x86_l_2bba;
	case 11199ULL: goto x86_l_2bbf;
	case 11204ULL: goto x86_l_2bc4;
	case 11209ULL: goto x86_l_2bc9;
	case 11214ULL: goto x86_l_2bce;
	case 11216ULL: goto x86_l_2bd0;
	case 11221ULL: goto x86_l_2bd5;
	case 11223ULL: goto x86_l_2bd7;
	case 11226ULL: goto x86_l_2bda;
	case 11232ULL: goto x86_l_2be0;
	case 11235ULL: goto x86_l_2be3;
	case 11241ULL: goto x86_l_2be9;
	case 11247ULL: goto x86_l_2bef;
	case 11252ULL: goto x86_l_2bf4;
	case 11256ULL: goto x86_l_2bf8;
	case 11263ULL: goto x86_l_2bff;
	case 11268ULL: goto x86_l_2c04;
	case 11273ULL: goto x86_l_2c09;
	case 11280ULL: goto x86_l_2c10;
	case 11283ULL: goto x86_l_2c13;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11300ULL: goto x86_l_2c24;
	case 11302ULL: goto x86_l_2c26;
	case 11306ULL: goto x86_l_2c2a;
	case 11308ULL: goto x86_l_2c2c;
	case 11310ULL: goto x86_l_2c2e;
	case 11316ULL: goto x86_l_2c34;
	case 11319ULL: goto x86_l_2c37;
	case 11325ULL: goto x86_l_2c3d;
	case 11331ULL: goto x86_l_2c43;
	case 11336ULL: goto x86_l_2c48;
	case 11340ULL: goto x86_l_2c4c;
	case 11347ULL: goto x86_l_2c53;
	case 11352ULL: goto x86_l_2c58;
	case 11357ULL: goto x86_l_2c5d;
	case 11362ULL: goto x86_l_2c62;
	case 11370ULL: goto x86_l_2c6a;
	case 11374ULL: goto x86_l_2c6e;
	case 11381ULL: goto x86_l_2c75;
	case 11386ULL: goto x86_l_2c7a;
	case 11388ULL: goto x86_l_2c7c;
	case 11393ULL: goto x86_l_2c81;
	case 11401ULL: goto x86_l_2c89;
	case 11404ULL: goto x86_l_2c8c;
	case 11412ULL: goto x86_l_2c94;
	case 11421ULL: goto x86_l_2c9d;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11438ULL: goto x86_l_2cae;
	case 11443ULL: goto x86_l_2cb3;
	case 11448ULL: goto x86_l_2cb8;
	case 11450ULL: goto x86_l_2cba;
	case 11455ULL: goto x86_l_2cbf;
	case 11457ULL: goto x86_l_2cc1;
	case 11460ULL: goto x86_l_2cc4;
	case 11466ULL: goto x86_l_2cca;
	case 11469ULL: goto x86_l_2ccd;
	case 11475ULL: goto x86_l_2cd3;
	case 11481ULL: goto x86_l_2cd9;
	case 11486ULL: goto x86_l_2cde;
	case 11490ULL: goto x86_l_2ce2;
	case 11497ULL: goto x86_l_2ce9;
	case 11502ULL: goto x86_l_2cee;
	case 11507ULL: goto x86_l_2cf3;
	case 11514ULL: goto x86_l_2cfa;
	case 11517ULL: goto x86_l_2cfd;
	case 11524ULL: goto x86_l_2d04;
	case 11529ULL: goto x86_l_2d09;
	case 11534ULL: goto x86_l_2d0e;
	case 11536ULL: goto x86_l_2d10;
	case 11540ULL: goto x86_l_2d14;
	case 11542ULL: goto x86_l_2d16;
	case 11544ULL: goto x86_l_2d18;
	case 11550ULL: goto x86_l_2d1e;
	case 11553ULL: goto x86_l_2d21;
	case 11559ULL: goto x86_l_2d27;
	case 11565ULL: goto x86_l_2d2d;
	case 11570ULL: goto x86_l_2d32;
	case 11574ULL: goto x86_l_2d36;
	case 11581ULL: goto x86_l_2d3d;
	case 11586ULL: goto x86_l_2d42;
	case 11591ULL: goto x86_l_2d47;
	case 11596ULL: goto x86_l_2d4c;
	case 11604ULL: goto x86_l_2d54;
	case 11608ULL: goto x86_l_2d58;
	case 11615ULL: goto x86_l_2d5f;
	case 11620ULL: goto x86_l_2d64;
	case 11622ULL: goto x86_l_2d66;
	case 11627ULL: goto x86_l_2d6b;
	case 11635ULL: goto x86_l_2d73;
	case 11638ULL: goto x86_l_2d76;
	case 11646ULL: goto x86_l_2d7e;
	case 11655ULL: goto x86_l_2d87;
	case 11662ULL: goto x86_l_2d8e;
	case 11667ULL: goto x86_l_2d93;
	case 11672ULL: goto x86_l_2d98;
	case 11677ULL: goto x86_l_2d9d;
	case 11682ULL: goto x86_l_2da2;
	case 11684ULL: goto x86_l_2da4;
	case 11689ULL: goto x86_l_2da9;
	case 11691ULL: goto x86_l_2dab;
	case 11694ULL: goto x86_l_2dae;
	case 11700ULL: goto x86_l_2db4;
	case 11703ULL: goto x86_l_2db7;
	case 11709ULL: goto x86_l_2dbd;
	case 11715ULL: goto x86_l_2dc3;
	case 11720ULL: goto x86_l_2dc8;
	case 11724ULL: goto x86_l_2dcc;
	case 11731ULL: goto x86_l_2dd3;
	case 11736ULL: goto x86_l_2dd8;
	case 11741ULL: goto x86_l_2ddd;
	case 11748ULL: goto x86_l_2de4;
	case 11751ULL: goto x86_l_2de7;
	case 11758ULL: goto x86_l_2dee;
	case 11763ULL: goto x86_l_2df3;
	case 11768ULL: goto x86_l_2df8;
	case 11770ULL: goto x86_l_2dfa;
	case 11774ULL: goto x86_l_2dfe;
	case 11776ULL: goto x86_l_2e00;
	case 11778ULL: goto x86_l_2e02;
	case 11784ULL: goto x86_l_2e08;
	case 11787ULL: goto x86_l_2e0b;
	case 11793ULL: goto x86_l_2e11;
	case 11799ULL: goto x86_l_2e17;
	case 11804ULL: goto x86_l_2e1c;
	case 11808ULL: goto x86_l_2e20;
	case 11815ULL: goto x86_l_2e27;
	case 11820ULL: goto x86_l_2e2c;
	case 11825ULL: goto x86_l_2e31;
	case 11830ULL: goto x86_l_2e36;
	case 11838ULL: goto x86_l_2e3e;
	case 11842ULL: goto x86_l_2e42;
	case 11849ULL: goto x86_l_2e49;
	case 11854ULL: goto x86_l_2e4e;
	case 11856ULL: goto x86_l_2e50;
	case 11861ULL: goto x86_l_2e55;
	case 11869ULL: goto x86_l_2e5d;
	case 11872ULL: goto x86_l_2e60;
	case 11880ULL: goto x86_l_2e68;
	case 11889ULL: goto x86_l_2e71;
	case 11896ULL: goto x86_l_2e78;
	case 11901ULL: goto x86_l_2e7d;
	case 11906ULL: goto x86_l_2e82;
	case 11911ULL: goto x86_l_2e87;
	case 11916ULL: goto x86_l_2e8c;
	case 11918ULL: goto x86_l_2e8e;
	case 11923ULL: goto x86_l_2e93;
	case 11925ULL: goto x86_l_2e95;
	case 11928ULL: goto x86_l_2e98;
	case 11934ULL: goto x86_l_2e9e;
	case 11937ULL: goto x86_l_2ea1;
	case 11943ULL: goto x86_l_2ea7;
	case 11949ULL: goto x86_l_2ead;
	case 11954ULL: goto x86_l_2eb2;
	case 11958ULL: goto x86_l_2eb6;
	case 11965ULL: goto x86_l_2ebd;
	case 11970ULL: goto x86_l_2ec2;
	case 11975ULL: goto x86_l_2ec7;
	case 11982ULL: goto x86_l_2ece;
	case 11985ULL: goto x86_l_2ed1;
	case 11992ULL: goto x86_l_2ed8;
	case 11997ULL: goto x86_l_2edd;
	case 12002ULL: goto x86_l_2ee2;
	case 12004ULL: goto x86_l_2ee4;
	case 12008ULL: goto x86_l_2ee8;
	case 12010ULL: goto x86_l_2eea;
	case 12012ULL: goto x86_l_2eec;
	case 12018ULL: goto x86_l_2ef2;
	case 12021ULL: goto x86_l_2ef5;
	case 12027ULL: goto x86_l_2efb;
	case 12033ULL: goto x86_l_2f01;
	case 12038ULL: goto x86_l_2f06;
	case 12042ULL: goto x86_l_2f0a;
	case 12049ULL: goto x86_l_2f11;
	case 12054ULL: goto x86_l_2f16;
	case 12059ULL: goto x86_l_2f1b;
	case 12064ULL: goto x86_l_2f20;
	case 12072ULL: goto x86_l_2f28;
	case 12076ULL: goto x86_l_2f2c;
	case 12083ULL: goto x86_l_2f33;
	case 12088ULL: goto x86_l_2f38;
	case 12090ULL: goto x86_l_2f3a;
	case 12095ULL: goto x86_l_2f3f;
	case 12103ULL: goto x86_l_2f47;
	case 12106ULL: goto x86_l_2f4a;
	case 12114ULL: goto x86_l_2f52;
	case 12123ULL: goto x86_l_2f5b;
	case 12130ULL: goto x86_l_2f62;
	case 12135ULL: goto x86_l_2f67;
	case 12140ULL: goto x86_l_2f6c;
	case 12145ULL: goto x86_l_2f71;
	case 12150ULL: goto x86_l_2f76;
	case 12152ULL: goto x86_l_2f78;
	case 12157ULL: goto x86_l_2f7d;
	case 12159ULL: goto x86_l_2f7f;
	case 12162ULL: goto x86_l_2f82;
	case 12168ULL: goto x86_l_2f88;
	case 12171ULL: goto x86_l_2f8b;
	case 12177ULL: goto x86_l_2f91;
	case 12183ULL: goto x86_l_2f97;
	case 12188ULL: goto x86_l_2f9c;
	case 12192ULL: goto x86_l_2fa0;
	case 12199ULL: goto x86_l_2fa7;
	case 12204ULL: goto x86_l_2fac;
	case 12209ULL: goto x86_l_2fb1;
	case 12216ULL: goto x86_l_2fb8;
	case 12219ULL: goto x86_l_2fbb;
	case 12226ULL: goto x86_l_2fc2;
	case 12231ULL: goto x86_l_2fc7;
	case 12236ULL: goto x86_l_2fcc;
	case 12238ULL: goto x86_l_2fce;
	case 12242ULL: goto x86_l_2fd2;
	case 12244ULL: goto x86_l_2fd4;
	case 12246ULL: goto x86_l_2fd6;
	case 12252ULL: goto x86_l_2fdc;
	case 12255ULL: goto x86_l_2fdf;
	case 12261ULL: goto x86_l_2fe5;
	case 12267ULL: goto x86_l_2feb;
	case 12272ULL: goto x86_l_2ff0;
	case 12276ULL: goto x86_l_2ff4;
	case 12283ULL: goto x86_l_2ffb;
	case 12288ULL: goto x86_l_3000;
	case 12293ULL: goto x86_l_3005;
	case 12298ULL: goto x86_l_300a;
	case 12306ULL: goto x86_l_3012;
	case 12310ULL: goto x86_l_3016;
	case 12317ULL: goto x86_l_301d;
	case 12322ULL: goto x86_l_3022;
	case 12324ULL: goto x86_l_3024;
	case 12329ULL: goto x86_l_3029;
	case 12337ULL: goto x86_l_3031;
	case 12340ULL: goto x86_l_3034;
	case 12348ULL: goto x86_l_303c;
	case 12357ULL: goto x86_l_3045;
	case 12364ULL: goto x86_l_304c;
	case 12369ULL: goto x86_l_3051;
	case 12374ULL: goto x86_l_3056;
	case 12379ULL: goto x86_l_305b;
	case 12384ULL: goto x86_l_3060;
	case 12386ULL: goto x86_l_3062;
	case 12391ULL: goto x86_l_3067;
	case 12393ULL: goto x86_l_3069;
	case 12396ULL: goto x86_l_306c;
	case 12402ULL: goto x86_l_3072;
	case 12405ULL: goto x86_l_3075;
	case 12411ULL: goto x86_l_307b;
	case 12417ULL: goto x86_l_3081;
	case 12422ULL: goto x86_l_3086;
	case 12426ULL: goto x86_l_308a;
	case 12433ULL: goto x86_l_3091;
	case 12438ULL: goto x86_l_3096;
	case 12443ULL: goto x86_l_309b;
	case 12450ULL: goto x86_l_30a2;
	case 12453ULL: goto x86_l_30a5;
	case 12460ULL: goto x86_l_30ac;
	case 12465ULL: goto x86_l_30b1;
	case 12470ULL: goto x86_l_30b6;
	case 12472ULL: goto x86_l_30b8;
	case 12476ULL: goto x86_l_30bc;
	case 12478ULL: goto x86_l_30be;
	case 12480ULL: goto x86_l_30c0;
	case 12486ULL: goto x86_l_30c6;
	case 12489ULL: goto x86_l_30c9;
	case 12495ULL: goto x86_l_30cf;
	case 12501ULL: goto x86_l_30d5;
	case 12506ULL: goto x86_l_30da;
	case 12510ULL: goto x86_l_30de;
	case 12517ULL: goto x86_l_30e5;
	case 12522ULL: goto x86_l_30ea;
	case 12527ULL: goto x86_l_30ef;
	case 12532ULL: goto x86_l_30f4;
	case 12540ULL: goto x86_l_30fc;
	case 12544ULL: goto x86_l_3100;
	case 12551ULL: goto x86_l_3107;
	case 12556ULL: goto x86_l_310c;
	case 12558ULL: goto x86_l_310e;
	case 12563ULL: goto x86_l_3113;
	case 12571ULL: goto x86_l_311b;
	case 12574ULL: goto x86_l_311e;
	case 12582ULL: goto x86_l_3126;
	case 12591ULL: goto x86_l_312f;
	case 12598ULL: goto x86_l_3136;
	case 12603ULL: goto x86_l_313b;
	case 12608ULL: goto x86_l_3140;
	case 12613ULL: goto x86_l_3145;
	case 12618ULL: goto x86_l_314a;
	case 12620ULL: goto x86_l_314c;
	case 12625ULL: goto x86_l_3151;
	case 12627ULL: goto x86_l_3153;
	case 12630ULL: goto x86_l_3156;
	case 12636ULL: goto x86_l_315c;
	case 12639ULL: goto x86_l_315f;
	case 12645ULL: goto x86_l_3165;
	case 12651ULL: goto x86_l_316b;
	case 12656ULL: goto x86_l_3170;
	case 12660ULL: goto x86_l_3174;
	case 12667ULL: goto x86_l_317b;
	case 12672ULL: goto x86_l_3180;
	case 12677ULL: goto x86_l_3185;
	case 12684ULL: goto x86_l_318c;
	case 12687ULL: goto x86_l_318f;
	case 12694ULL: goto x86_l_3196;
	case 12699ULL: goto x86_l_319b;
	case 12704ULL: goto x86_l_31a0;
	case 12706ULL: goto x86_l_31a2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a30:
	/* 0x2a30: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2a35:
	/* 0x2a35: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a3c:
	/* 0x2a3c: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a3f:
	/* 0x2a3f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2a46:
	/* 0x2a46: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a4b:
	/* 0x2a4b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2a50:
	/* 0x2a50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a52:
	/* 0x2a52: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a56:
	/* 0x2a56: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_2a58:
	/* 0x2a58: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a5a:
	/* 0x2a5a: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_2a60:
	/* 0x2a60: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a63:
	/* 0x2a63: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2a69:
	/* 0x2a69: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2a6f:
	/* 0x2a6f: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a74:
	/* 0x2a74: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2a78:
	/* 0x2a78: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2a7f:
	/* 0x2a7f: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a84:
	/* 0x2a84: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a89:
	/* 0x2a89: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a8e:
	/* 0x2a8e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a96:
	/* 0x2a96: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2a9a:
	/* 0x2a9a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2aa1:
	/* 0x2aa1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2aa6:
	/* 0x2aa6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa8:
	/* 0x2aa8: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2aad:
	/* 0x2aad: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2ab5:
	/* 0x2ab5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2ab8:
	/* 0x2ab8: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2ac0:
	/* 0x2ac0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ac9:
	/* 0x2ac9: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2ad0:
	/* 0x2ad0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ad5:
	/* 0x2ad5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ada:
	/* 0x2ada: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2adf:
	/* 0x2adf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ae4:
	/* 0x2ae4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae6:
	/* 0x2ae6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aeb:
	/* 0x2aeb: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_2aed:
	/* 0x2aed: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2af0:
	/* 0x2af0: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_2af6:
	/* 0x2af6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2af9:
	/* 0x2af9: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2aff:
	/* 0x2aff: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2b05:
	/* 0x2b05: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b0a:
	/* 0x2b0a: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2b0e:
	/* 0x2b0e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2b15:
	/* 0x2b15: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2b1a:
	/* 0x2b1a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2b1f:
	/* 0x2b1f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b26:
	/* 0x2b26: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b29:
	/* 0x2b29: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2b30:
	/* 0x2b30: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b35:
	/* 0x2b35: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2b3a:
	/* 0x2b3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b3c:
	/* 0x2b3c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b40:
	/* 0x2b40: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_2b42:
	/* 0x2b42: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b44:
	/* 0x2b44: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_2b4a:
	/* 0x2b4a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b4d:
	/* 0x2b4d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2b53:
	/* 0x2b53: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2b59:
	/* 0x2b59: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b5e:
	/* 0x2b5e: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2b62:
	/* 0x2b62: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b69:
	/* 0x2b69: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b6e:
	/* 0x2b6e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b73:
	/* 0x2b73: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b78:
	/* 0x2b78: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b80:
	/* 0x2b80: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2b84:
	/* 0x2b84: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b8b:
	/* 0x2b8b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b90:
	/* 0x2b90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b92:
	/* 0x2b92: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2b97:
	/* 0x2b97: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2b9f:
	/* 0x2b9f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2ba2:
	/* 0x2ba2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2baa:
	/* 0x2baa: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2bb3:
	/* 0x2bb3: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2bba:
	/* 0x2bba: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bbf:
	/* 0x2bbf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2bc4:
	/* 0x2bc4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bc9:
	/* 0x2bc9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bce:
	/* 0x2bce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bd0:
	/* 0x2bd0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bd5:
	/* 0x2bd5: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_2bd7:
	/* 0x2bd7: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2bda:
	/* 0x2bda: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_2be0:
	/* 0x2be0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2be3:
	/* 0x2be3: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2be9:
	/* 0x2be9: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2bef:
	/* 0x2bef: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bf4:
	/* 0x2bf4: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2bf8:
	/* 0x2bf8: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2bff:
	/* 0x2bff: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2c04:
	/* 0x2c04: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2c09:
	/* 0x2c09: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c10:
	/* 0x2c10: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c13:
	/* 0x2c13: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2c1a:
	/* 0x2c1a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c1f:
	/* 0x2c1f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2c24:
	/* 0x2c24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c26:
	/* 0x2c26: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c2a:
	/* 0x2c2a: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_2c2c:
	/* 0x2c2c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c2e:
	/* 0x2c2e: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_2c34:
	/* 0x2c34: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c37:
	/* 0x2c37: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2c3d:
	/* 0x2c3d: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2c43:
	/* 0x2c43: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c48:
	/* 0x2c48: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2c4c:
	/* 0x2c4c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2c53:
	/* 0x2c53: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c58:
	/* 0x2c58: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c5d:
	/* 0x2c5d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c62:
	/* 0x2c62: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c6a:
	/* 0x2c6a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2c6e:
	/* 0x2c6e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2c75:
	/* 0x2c75: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c7a:
	/* 0x2c7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c7c:
	/* 0x2c7c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2c81:
	/* 0x2c81: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2c89:
	/* 0x2c89: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2c8c:
	/* 0x2c8c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c94:
	/* 0x2c94: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c9d:
	/* 0x2c9d: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2ca4:
	/* 0x2ca4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca9:
	/* 0x2ca9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2cae:
	/* 0x2cae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cb3:
	/* 0x2cb3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cb8:
	/* 0x2cb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cba:
	/* 0x2cba: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cbf:
	/* 0x2cbf: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_2cc1:
	/* 0x2cc1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2cc4:
	/* 0x2cc4: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_2cca:
	/* 0x2cca: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ccd:
	/* 0x2ccd: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2cd3:
	/* 0x2cd3: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2cd9:
	/* 0x2cd9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cde:
	/* 0x2cde: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2ce2:
	/* 0x2ce2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2ce9:
	/* 0x2ce9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2cee:
	/* 0x2cee: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2cf3:
	/* 0x2cf3: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2cfa:
	/* 0x2cfa: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2cfd:
	/* 0x2cfd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2d04:
	/* 0x2d04: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d09:
	/* 0x2d09: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d0e:
	/* 0x2d0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d10:
	/* 0x2d10: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d14:
	/* 0x2d14: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_2d16:
	/* 0x2d16: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d18:
	/* 0x2d18: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_2d1e:
	/* 0x2d1e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d21:
	/* 0x2d21: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2d27:
	/* 0x2d27: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2d2d:
	/* 0x2d2d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d32:
	/* 0x2d32: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2d36:
	/* 0x2d36: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2d3d:
	/* 0x2d3d: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d42:
	/* 0x2d42: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d47:
	/* 0x2d47: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d4c:
	/* 0x2d4c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d54:
	/* 0x2d54: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2d58:
	/* 0x2d58: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2d5f:
	/* 0x2d5f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d64:
	/* 0x2d64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d66:
	/* 0x2d66: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2d6b:
	/* 0x2d6b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2d73:
	/* 0x2d73: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2d76:
	/* 0x2d76: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2d7e:
	/* 0x2d7e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d87:
	/* 0x2d87: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2d8e:
	/* 0x2d8e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d93:
	/* 0x2d93: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d98:
	/* 0x2d98: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d9d:
	/* 0x2d9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2da2:
	/* 0x2da2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da4:
	/* 0x2da4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2da9:
	/* 0x2da9: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_2dab:
	/* 0x2dab: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2dae:
	/* 0x2dae: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_2db4:
	/* 0x2db4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2db7:
	/* 0x2db7: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2dbd:
	/* 0x2dbd: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2dc3:
	/* 0x2dc3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dc8:
	/* 0x2dc8: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2dcc:
	/* 0x2dcc: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2dd3:
	/* 0x2dd3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2dd8:
	/* 0x2dd8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2ddd:
	/* 0x2ddd: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2de4:
	/* 0x2de4: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2de7:
	/* 0x2de7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2dee:
	/* 0x2dee: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2df3:
	/* 0x2df3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2df8:
	/* 0x2df8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dfa:
	/* 0x2dfa: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2dfe:
	/* 0x2dfe: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_2e00:
	/* 0x2e00: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e02:
	/* 0x2e02: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_2e08:
	/* 0x2e08: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e0b:
	/* 0x2e0b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2e11:
	/* 0x2e11: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2e17:
	/* 0x2e17: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e1c:
	/* 0x2e1c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2e20:
	/* 0x2e20: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2e27:
	/* 0x2e27: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2e2c:
	/* 0x2e2c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e31:
	/* 0x2e31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e36:
	/* 0x2e36: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e3e:
	/* 0x2e3e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e42:
	/* 0x2e42: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2e49:
	/* 0x2e49: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e4e:
	/* 0x2e4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e50:
	/* 0x2e50: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2e55:
	/* 0x2e55: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2e5d:
	/* 0x2e5d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2e60:
	/* 0x2e60: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2e68:
	/* 0x2e68: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2e71:
	/* 0x2e71: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2e78:
	/* 0x2e78: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e7d:
	/* 0x2e7d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e82:
	/* 0x2e82: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e87:
	/* 0x2e87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e8c:
	/* 0x2e8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8e:
	/* 0x2e8e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e93:
	/* 0x2e93: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_2e95:
	/* 0x2e95: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2e98:
	/* 0x2e98: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_2e9e:
	/* 0x2e9e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ea1:
	/* 0x2ea1: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2ea7:
	/* 0x2ea7: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2ead:
	/* 0x2ead: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eb2:
	/* 0x2eb2: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2eb6:
	/* 0x2eb6: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2ebd:
	/* 0x2ebd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2ec2:
	/* 0x2ec2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2ec7:
	/* 0x2ec7: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ece:
	/* 0x2ece: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ed1:
	/* 0x2ed1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2ed8:
	/* 0x2ed8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2edd:
	/* 0x2edd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2ee2:
	/* 0x2ee2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ee4:
	/* 0x2ee4: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ee8:
	/* 0x2ee8: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_2eea:
	/* 0x2eea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2eec:
	/* 0x2eec: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_2ef2:
	/* 0x2ef2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ef5:
	/* 0x2ef5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2efb:
	/* 0x2efb: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2f01:
	/* 0x2f01: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f06:
	/* 0x2f06: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2f0a:
	/* 0x2f0a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2f11:
	/* 0x2f11: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f16:
	/* 0x2f16: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f1b:
	/* 0x2f1b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f20:
	/* 0x2f20: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f28:
	/* 0x2f28: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2f2c:
	/* 0x2f2c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2f33:
	/* 0x2f33: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f38:
	/* 0x2f38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f3a:
	/* 0x2f3a: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2f3f:
	/* 0x2f3f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2f47:
	/* 0x2f47: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2f4a:
	/* 0x2f4a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2f52:
	/* 0x2f52: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f5b:
	/* 0x2f5b: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2f62:
	/* 0x2f62: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f67:
	/* 0x2f67: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f6c:
	/* 0x2f6c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f71:
	/* 0x2f71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f76:
	/* 0x2f76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f78:
	/* 0x2f78: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f7d:
	/* 0x2f7d: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_2f7f:
	/* 0x2f7f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2f82:
	/* 0x2f82: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_2f88:
	/* 0x2f88: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f8b:
	/* 0x2f8b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2f91:
	/* 0x2f91: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2f97:
	/* 0x2f97: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f9c:
	/* 0x2f9c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2fa0:
	/* 0x2fa0: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2fa7:
	/* 0x2fa7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2fac:
	/* 0x2fac: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2fb1:
	/* 0x2fb1: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2fb8:
	/* 0x2fb8: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2fbb:
	/* 0x2fbb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2fc2:
	/* 0x2fc2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fc7:
	/* 0x2fc7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2fcc:
	/* 0x2fcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fce:
	/* 0x2fce: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2fd2:
	/* 0x2fd2: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_2fd4:
	/* 0x2fd4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fd6:
	/* 0x2fd6: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_2fdc:
	/* 0x2fdc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fdf:
	/* 0x2fdf: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2fe5:
	/* 0x2fe5: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_2feb:
	/* 0x2feb: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ff0:
	/* 0x2ff0: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2ff4:
	/* 0x2ff4: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2ffb:
	/* 0x2ffb: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3000:
	/* 0x3000: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3005:
	/* 0x3005: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_300a:
	/* 0x300a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3012:
	/* 0x3012: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3016:
	/* 0x3016: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_301d:
	/* 0x301d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3022:
	/* 0x3022: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3024:
	/* 0x3024: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3029:
	/* 0x3029: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3031:
	/* 0x3031: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3034:
	/* 0x3034: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_303c:
	/* 0x303c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3045:
	/* 0x3045: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_304c:
	/* 0x304c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3051:
	/* 0x3051: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3056:
	/* 0x3056: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_305b:
	/* 0x305b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3060:
	/* 0x3060: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3062:
	/* 0x3062: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3067:
	/* 0x3067: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_3069:
	/* 0x3069: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_306c:
	/* 0x306c: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_3072:
	/* 0x3072: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3075:
	/* 0x3075: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_307b:
	/* 0x307b: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_3081:
	/* 0x3081: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3086:
	/* 0x3086: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_308a:
	/* 0x308a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3091:
	/* 0x3091: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3096:
	/* 0x3096: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_309b:
	/* 0x309b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_30a2:
	/* 0x30a2: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30a5:
	/* 0x30a5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_30ac:
	/* 0x30ac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30b1:
	/* 0x30b1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_30b6:
	/* 0x30b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30b8:
	/* 0x30b8: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_30bc:
	/* 0x30bc: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_30be:
	/* 0x30be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30c0:
	/* 0x30c0: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_30c6:
	/* 0x30c6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30c9:
	/* 0x30c9: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_30cf:
	/* 0x30cf: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_30d5:
	/* 0x30d5: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30da:
	/* 0x30da: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_30de:
	/* 0x30de: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_30e5:
	/* 0x30e5: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_30ea:
	/* 0x30ea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_30ef:
	/* 0x30ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30f4:
	/* 0x30f4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_30fc:
	/* 0x30fc: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3100:
	/* 0x3100: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3107:
	/* 0x3107: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_310c:
	/* 0x310c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310e:
	/* 0x310e: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3113:
	/* 0x3113: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_311b:
	/* 0x311b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_311e:
	/* 0x311e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3126:
	/* 0x3126: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_312f:
	/* 0x312f: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3136:
	/* 0x3136: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_313b:
	/* 0x313b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3140:
	/* 0x3140: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3145:
	/* 0x3145: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_314a:
	/* 0x314a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314c:
	/* 0x314c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3151:
	/* 0x3151: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_3153:
	/* 0x3153: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3156:
	/* 0x3156: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_315c:
	/* 0x315c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_315f:
	/* 0x315f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3165:
	/* 0x3165: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_316b:
	/* 0x316b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3170:
	/* 0x3170: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3174:
	/* 0x3174: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_317b:
	/* 0x317b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3180:
	/* 0x3180: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3185:
	/* 0x3185: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_318c:
	/* 0x318c: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_318f:
	/* 0x318f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3196:
	/* 0x3196: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_319b:
	/* 0x319b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_31a0:
	/* 0x31a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31a2:
	/* 0x31a2: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
	return 12710ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12710ULL: goto x86_l_31a6;
	case 12712ULL: goto x86_l_31a8;
	case 12714ULL: goto x86_l_31aa;
	case 12720ULL: goto x86_l_31b0;
	case 12723ULL: goto x86_l_31b3;
	case 12729ULL: goto x86_l_31b9;
	case 12735ULL: goto x86_l_31bf;
	case 12740ULL: goto x86_l_31c4;
	case 12744ULL: goto x86_l_31c8;
	case 12751ULL: goto x86_l_31cf;
	case 12756ULL: goto x86_l_31d4;
	case 12761ULL: goto x86_l_31d9;
	case 12766ULL: goto x86_l_31de;
	case 12774ULL: goto x86_l_31e6;
	case 12778ULL: goto x86_l_31ea;
	case 12785ULL: goto x86_l_31f1;
	case 12790ULL: goto x86_l_31f6;
	case 12792ULL: goto x86_l_31f8;
	case 12797ULL: goto x86_l_31fd;
	case 12805ULL: goto x86_l_3205;
	case 12808ULL: goto x86_l_3208;
	case 12816ULL: goto x86_l_3210;
	case 12825ULL: goto x86_l_3219;
	case 12832ULL: goto x86_l_3220;
	case 12837ULL: goto x86_l_3225;
	case 12842ULL: goto x86_l_322a;
	case 12847ULL: goto x86_l_322f;
	case 12852ULL: goto x86_l_3234;
	case 12854ULL: goto x86_l_3236;
	case 12859ULL: goto x86_l_323b;
	case 12861ULL: goto x86_l_323d;
	case 12864ULL: goto x86_l_3240;
	case 12870ULL: goto x86_l_3246;
	case 12873ULL: goto x86_l_3249;
	case 12879ULL: goto x86_l_324f;
	case 12885ULL: goto x86_l_3255;
	case 12890ULL: goto x86_l_325a;
	case 12894ULL: goto x86_l_325e;
	case 12901ULL: goto x86_l_3265;
	case 12906ULL: goto x86_l_326a;
	case 12911ULL: goto x86_l_326f;
	case 12918ULL: goto x86_l_3276;
	case 12921ULL: goto x86_l_3279;
	case 12928ULL: goto x86_l_3280;
	case 12933ULL: goto x86_l_3285;
	case 12938ULL: goto x86_l_328a;
	case 12940ULL: goto x86_l_328c;
	case 12944ULL: goto x86_l_3290;
	case 12946ULL: goto x86_l_3292;
	case 12948ULL: goto x86_l_3294;
	case 12954ULL: goto x86_l_329a;
	case 12957ULL: goto x86_l_329d;
	case 12963ULL: goto x86_l_32a3;
	case 12969ULL: goto x86_l_32a9;
	case 12974ULL: goto x86_l_32ae;
	case 12978ULL: goto x86_l_32b2;
	case 12985ULL: goto x86_l_32b9;
	case 12990ULL: goto x86_l_32be;
	case 12995ULL: goto x86_l_32c3;
	case 13000ULL: goto x86_l_32c8;
	case 13008ULL: goto x86_l_32d0;
	case 13012ULL: goto x86_l_32d4;
	case 13019ULL: goto x86_l_32db;
	case 13024ULL: goto x86_l_32e0;
	case 13026ULL: goto x86_l_32e2;
	case 13031ULL: goto x86_l_32e7;
	case 13039ULL: goto x86_l_32ef;
	case 13042ULL: goto x86_l_32f2;
	case 13050ULL: goto x86_l_32fa;
	case 13059ULL: goto x86_l_3303;
	case 13066ULL: goto x86_l_330a;
	case 13071ULL: goto x86_l_330f;
	case 13076ULL: goto x86_l_3314;
	case 13081ULL: goto x86_l_3319;
	case 13086ULL: goto x86_l_331e;
	case 13089ULL: goto x86_l_3321;
	case 13091ULL: goto x86_l_3323;
	case 13096ULL: goto x86_l_3328;
	case 13098ULL: goto x86_l_332a;
	case 13101ULL: goto x86_l_332d;
	case 13107ULL: goto x86_l_3333;
	case 13110ULL: goto x86_l_3336;
	case 13116ULL: goto x86_l_333c;
	case 13122ULL: goto x86_l_3342;
	case 13127ULL: goto x86_l_3347;
	case 13131ULL: goto x86_l_334b;
	case 13138ULL: goto x86_l_3352;
	case 13143ULL: goto x86_l_3357;
	case 13148ULL: goto x86_l_335c;
	case 13155ULL: goto x86_l_3363;
	case 13158ULL: goto x86_l_3366;
	case 13165ULL: goto x86_l_336d;
	case 13170ULL: goto x86_l_3372;
	case 13175ULL: goto x86_l_3377;
	case 13177ULL: goto x86_l_3379;
	case 13181ULL: goto x86_l_337d;
	case 13183ULL: goto x86_l_337f;
	case 13185ULL: goto x86_l_3381;
	case 13191ULL: goto x86_l_3387;
	case 13194ULL: goto x86_l_338a;
	case 13200ULL: goto x86_l_3390;
	case 13206ULL: goto x86_l_3396;
	case 13211ULL: goto x86_l_339b;
	case 13215ULL: goto x86_l_339f;
	case 13222ULL: goto x86_l_33a6;
	case 13227ULL: goto x86_l_33ab;
	case 13232ULL: goto x86_l_33b0;
	case 13237ULL: goto x86_l_33b5;
	case 13245ULL: goto x86_l_33bd;
	case 13249ULL: goto x86_l_33c1;
	case 13256ULL: goto x86_l_33c8;
	case 13261ULL: goto x86_l_33cd;
	case 13263ULL: goto x86_l_33cf;
	case 13268ULL: goto x86_l_33d4;
	case 13276ULL: goto x86_l_33dc;
	case 13279ULL: goto x86_l_33df;
	case 13287ULL: goto x86_l_33e7;
	case 13298ULL: goto x86_l_33f2;
	case 13301ULL: goto x86_l_33f5;
	case 13307ULL: goto x86_l_33fb;
	case 13309ULL: goto x86_l_33fd;
	case 13314ULL: goto x86_l_3402;
	case 13318ULL: goto x86_l_3406;
	case 13321ULL: goto x86_l_3409;
	case 13326ULL: goto x86_l_340e;
	case 13330ULL: goto x86_l_3412;
	case 13337ULL: goto x86_l_3419;
	case 13345ULL: goto x86_l_3421;
	case 13350ULL: goto x86_l_3426;
	case 13355ULL: goto x86_l_342b;
	case 13362ULL: goto x86_l_3432;
	case 13365ULL: goto x86_l_3435;
	case 13372ULL: goto x86_l_343c;
	case 13377ULL: goto x86_l_3441;
	case 13379ULL: goto x86_l_3443;
	case 13386ULL: goto x86_l_344a;
	case 13388ULL: goto x86_l_344c;
	case 13390ULL: goto x86_l_344e;
	case 13396ULL: goto x86_l_3454;
	case 13399ULL: goto x86_l_3457;
	case 13405ULL: goto x86_l_345d;
	case 13410ULL: goto x86_l_3462;
	case 13415ULL: goto x86_l_3467;
	case 13421ULL: goto x86_l_346d;
	case 13426ULL: goto x86_l_3472;
	case 13430ULL: goto x86_l_3476;
	case 13437ULL: goto x86_l_347d;
	case 13445ULL: goto x86_l_3485;
	case 13450ULL: goto x86_l_348a;
	case 13455ULL: goto x86_l_348f;
	case 13463ULL: goto x86_l_3497;
	case 13467ULL: goto x86_l_349b;
	case 13474ULL: goto x86_l_34a2;
	case 13479ULL: goto x86_l_34a7;
	case 13481ULL: goto x86_l_34a9;
	case 13489ULL: goto x86_l_34b1;
	case 13497ULL: goto x86_l_34b9;
	case 13500ULL: goto x86_l_34bc;
	case 13508ULL: goto x86_l_34c4;
	case 13510ULL: goto x86_l_34c6;
	case 13515ULL: goto x86_l_34cb;
	case 13519ULL: goto x86_l_34cf;
	case 13526ULL: goto x86_l_34d6;
	case 13531ULL: goto x86_l_34db;
	case 13536ULL: goto x86_l_34e0;
	case 13541ULL: goto x86_l_34e5;
	case 13548ULL: goto x86_l_34ec;
	case 13552ULL: goto x86_l_34f0;
	case 13559ULL: goto x86_l_34f7;
	case 13564ULL: goto x86_l_34fc;
	case 13566ULL: goto x86_l_34fe;
	case 13571ULL: goto x86_l_3503;
	case 13578ULL: goto x86_l_350a;
	case 13581ULL: goto x86_l_350d;
	case 13588ULL: goto x86_l_3514;
	case 13597ULL: goto x86_l_351d;
	case 13601ULL: goto x86_l_3521;
	case 13606ULL: goto x86_l_3526;
	case 13611ULL: goto x86_l_352b;
	case 13616ULL: goto x86_l_3530;
	case 13621ULL: goto x86_l_3535;
	case 13623ULL: goto x86_l_3537;
	case 13628ULL: goto x86_l_353c;
	case 13630ULL: goto x86_l_353e;
	case 13633ULL: goto x86_l_3541;
	case 13639ULL: goto x86_l_3547;
	case 13642ULL: goto x86_l_354a;
	case 13648ULL: goto x86_l_3550;
	case 13654ULL: goto x86_l_3556;
	case 13659ULL: goto x86_l_355b;
	case 13663ULL: goto x86_l_355f;
	case 13670ULL: goto x86_l_3566;
	case 13675ULL: goto x86_l_356b;
	case 13680ULL: goto x86_l_3570;
	case 13687ULL: goto x86_l_3577;
	case 13690ULL: goto x86_l_357a;
	case 13697ULL: goto x86_l_3581;
	case 13702ULL: goto x86_l_3586;
	case 13707ULL: goto x86_l_358b;
	case 13709ULL: goto x86_l_358d;
	case 13713ULL: goto x86_l_3591;
	case 13715ULL: goto x86_l_3593;
	case 13717ULL: goto x86_l_3595;
	case 13723ULL: goto x86_l_359b;
	case 13726ULL: goto x86_l_359e;
	case 13732ULL: goto x86_l_35a4;
	case 13738ULL: goto x86_l_35aa;
	case 13743ULL: goto x86_l_35af;
	case 13747ULL: goto x86_l_35b3;
	case 13754ULL: goto x86_l_35ba;
	case 13759ULL: goto x86_l_35bf;
	case 13764ULL: goto x86_l_35c4;
	case 13769ULL: goto x86_l_35c9;
	case 13777ULL: goto x86_l_35d1;
	case 13781ULL: goto x86_l_35d5;
	case 13788ULL: goto x86_l_35dc;
	case 13793ULL: goto x86_l_35e1;
	case 13795ULL: goto x86_l_35e3;
	case 13800ULL: goto x86_l_35e8;
	case 13808ULL: goto x86_l_35f0;
	case 13811ULL: goto x86_l_35f3;
	case 13819ULL: goto x86_l_35fb;
	case 13828ULL: goto x86_l_3604;
	case 13832ULL: goto x86_l_3608;
	case 13837ULL: goto x86_l_360d;
	case 13842ULL: goto x86_l_3612;
	case 13847ULL: goto x86_l_3617;
	case 13852ULL: goto x86_l_361c;
	case 13854ULL: goto x86_l_361e;
	case 13859ULL: goto x86_l_3623;
	case 13861ULL: goto x86_l_3625;
	case 13864ULL: goto x86_l_3628;
	case 13870ULL: goto x86_l_362e;
	case 13873ULL: goto x86_l_3631;
	case 13879ULL: goto x86_l_3637;
	case 13885ULL: goto x86_l_363d;
	case 13890ULL: goto x86_l_3642;
	case 13894ULL: goto x86_l_3646;
	case 13901ULL: goto x86_l_364d;
	case 13906ULL: goto x86_l_3652;
	case 13911ULL: goto x86_l_3657;
	case 13918ULL: goto x86_l_365e;
	case 13921ULL: goto x86_l_3661;
	case 13928ULL: goto x86_l_3668;
	case 13933ULL: goto x86_l_366d;
	case 13938ULL: goto x86_l_3672;
	case 13940ULL: goto x86_l_3674;
	case 13944ULL: goto x86_l_3678;
	case 13946ULL: goto x86_l_367a;
	case 13948ULL: goto x86_l_367c;
	case 13954ULL: goto x86_l_3682;
	case 13957ULL: goto x86_l_3685;
	case 13963ULL: goto x86_l_368b;
	case 13969ULL: goto x86_l_3691;
	case 13974ULL: goto x86_l_3696;
	case 13978ULL: goto x86_l_369a;
	case 13985ULL: goto x86_l_36a1;
	case 13990ULL: goto x86_l_36a6;
	case 13995ULL: goto x86_l_36ab;
	case 14000ULL: goto x86_l_36b0;
	case 14008ULL: goto x86_l_36b8;
	case 14012ULL: goto x86_l_36bc;
	case 14019ULL: goto x86_l_36c3;
	case 14024ULL: goto x86_l_36c8;
	case 14026ULL: goto x86_l_36ca;
	case 14031ULL: goto x86_l_36cf;
	case 14039ULL: goto x86_l_36d7;
	case 14042ULL: goto x86_l_36da;
	case 14050ULL: goto x86_l_36e2;
	case 14059ULL: goto x86_l_36eb;
	case 14063ULL: goto x86_l_36ef;
	case 14068ULL: goto x86_l_36f4;
	case 14073ULL: goto x86_l_36f9;
	case 14078ULL: goto x86_l_36fe;
	case 14083ULL: goto x86_l_3703;
	case 14085ULL: goto x86_l_3705;
	case 14090ULL: goto x86_l_370a;
	case 14092ULL: goto x86_l_370c;
	case 14095ULL: goto x86_l_370f;
	case 14101ULL: goto x86_l_3715;
	case 14104ULL: goto x86_l_3718;
	case 14110ULL: goto x86_l_371e;
	case 14116ULL: goto x86_l_3724;
	case 14121ULL: goto x86_l_3729;
	case 14125ULL: goto x86_l_372d;
	case 14132ULL: goto x86_l_3734;
	case 14137ULL: goto x86_l_3739;
	case 14142ULL: goto x86_l_373e;
	case 14149ULL: goto x86_l_3745;
	case 14152ULL: goto x86_l_3748;
	case 14159ULL: goto x86_l_374f;
	case 14164ULL: goto x86_l_3754;
	case 14169ULL: goto x86_l_3759;
	case 14171ULL: goto x86_l_375b;
	case 14175ULL: goto x86_l_375f;
	case 14177ULL: goto x86_l_3761;
	case 14179ULL: goto x86_l_3763;
	case 14185ULL: goto x86_l_3769;
	case 14188ULL: goto x86_l_376c;
	case 14194ULL: goto x86_l_3772;
	case 14200ULL: goto x86_l_3778;
	case 14205ULL: goto x86_l_377d;
	case 14209ULL: goto x86_l_3781;
	case 14216ULL: goto x86_l_3788;
	case 14221ULL: goto x86_l_378d;
	case 14226ULL: goto x86_l_3792;
	case 14231ULL: goto x86_l_3797;
	case 14239ULL: goto x86_l_379f;
	case 14243ULL: goto x86_l_37a3;
	case 14250ULL: goto x86_l_37aa;
	case 14255ULL: goto x86_l_37af;
	case 14257ULL: goto x86_l_37b1;
	case 14262ULL: goto x86_l_37b6;
	case 14270ULL: goto x86_l_37be;
	case 14273ULL: goto x86_l_37c1;
	case 14281ULL: goto x86_l_37c9;
	case 14290ULL: goto x86_l_37d2;
	case 14294ULL: goto x86_l_37d6;
	case 14299ULL: goto x86_l_37db;
	case 14304ULL: goto x86_l_37e0;
	case 14309ULL: goto x86_l_37e5;
	case 14314ULL: goto x86_l_37ea;
	case 14316ULL: goto x86_l_37ec;
	case 14321ULL: goto x86_l_37f1;
	case 14323ULL: goto x86_l_37f3;
	case 14326ULL: goto x86_l_37f6;
	case 14332ULL: goto x86_l_37fc;
	case 14335ULL: goto x86_l_37ff;
	case 14341ULL: goto x86_l_3805;
	case 14347ULL: goto x86_l_380b;
	case 14352ULL: goto x86_l_3810;
	case 14356ULL: goto x86_l_3814;
	case 14363ULL: goto x86_l_381b;
	case 14368ULL: goto x86_l_3820;
	case 14373ULL: goto x86_l_3825;
	case 14380ULL: goto x86_l_382c;
	case 14383ULL: goto x86_l_382f;
	case 14390ULL: goto x86_l_3836;
	case 14395ULL: goto x86_l_383b;
	case 14400ULL: goto x86_l_3840;
	case 14402ULL: goto x86_l_3842;
	case 14406ULL: goto x86_l_3846;
	case 14408ULL: goto x86_l_3848;
	case 14410ULL: goto x86_l_384a;
	case 14416ULL: goto x86_l_3850;
	case 14419ULL: goto x86_l_3853;
	case 14425ULL: goto x86_l_3859;
	case 14431ULL: goto x86_l_385f;
	case 14436ULL: goto x86_l_3864;
	case 14440ULL: goto x86_l_3868;
	case 14447ULL: goto x86_l_386f;
	case 14452ULL: goto x86_l_3874;
	case 14457ULL: goto x86_l_3879;
	case 14462ULL: goto x86_l_387e;
	case 14470ULL: goto x86_l_3886;
	case 14474ULL: goto x86_l_388a;
	case 14481ULL: goto x86_l_3891;
	case 14486ULL: goto x86_l_3896;
	case 14488ULL: goto x86_l_3898;
	case 14493ULL: goto x86_l_389d;
	case 14501ULL: goto x86_l_38a5;
	case 14504ULL: goto x86_l_38a8;
	case 14512ULL: goto x86_l_38b0;
	case 14521ULL: goto x86_l_38b9;
	case 14525ULL: goto x86_l_38bd;
	case 14530ULL: goto x86_l_38c2;
	case 14535ULL: goto x86_l_38c7;
	case 14540ULL: goto x86_l_38cc;
	case 14545ULL: goto x86_l_38d1;
	case 14547ULL: goto x86_l_38d3;
	case 14552ULL: goto x86_l_38d8;
	case 14554ULL: goto x86_l_38da;
	case 14557ULL: goto x86_l_38dd;
	case 14563ULL: goto x86_l_38e3;
	case 14566ULL: goto x86_l_38e6;
	case 14572ULL: goto x86_l_38ec;
	case 14578ULL: goto x86_l_38f2;
	case 14583ULL: goto x86_l_38f7;
	case 14587ULL: goto x86_l_38fb;
	case 14594ULL: goto x86_l_3902;
	case 14599ULL: goto x86_l_3907;
	case 14604ULL: goto x86_l_390c;
	case 14611ULL: goto x86_l_3913;
	case 14614ULL: goto x86_l_3916;
	default: return 0xffffffffffffffffULL;
	}
x86_l_31a6:
	/* 0x31a6: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_31a8:
	/* 0x31a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31aa:
	/* 0x31aa: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_31b0:
	/* 0x31b0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31b3:
	/* 0x31b3: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_31b9:
	/* 0x31b9: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_31bf:
	/* 0x31bf: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31c4:
	/* 0x31c4: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_31c8:
	/* 0x31c8: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_31cf:
	/* 0x31cf: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_31d4:
	/* 0x31d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_31d9:
	/* 0x31d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31de:
	/* 0x31de: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_31e6:
	/* 0x31e6: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_31ea:
	/* 0x31ea: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_31f1:
	/* 0x31f1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_31f6:
	/* 0x31f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31f8:
	/* 0x31f8: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_31fd:
	/* 0x31fd: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3205:
	/* 0x3205: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3208:
	/* 0x3208: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3210:
	/* 0x3210: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3219:
	/* 0x3219: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3220:
	/* 0x3220: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3225:
	/* 0x3225: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_322a:
	/* 0x322a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_322f:
	/* 0x322f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3234:
	/* 0x3234: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3236:
	/* 0x3236: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_323b:
	/* 0x323b: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_323d:
	/* 0x323d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3240:
	/* 0x3240: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_3246:
	/* 0x3246: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3249:
	/* 0x3249: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_324f:
	/* 0x324f: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_3255:
	/* 0x3255: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_325a:
	/* 0x325a: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_325e:
	/* 0x325e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3265:
	/* 0x3265: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_326a:
	/* 0x326a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_326f:
	/* 0x326f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3276:
	/* 0x3276: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3279:
	/* 0x3279: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3280:
	/* 0x3280: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3285:
	/* 0x3285: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_328a:
	/* 0x328a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_328c:
	/* 0x328c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3290:
	/* 0x3290: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_3292:
	/* 0x3292: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3294:
	/* 0x3294: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_329a:
	/* 0x329a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_329d:
	/* 0x329d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_32a3:
	/* 0x32a3: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_32a9:
	/* 0x32a9: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32ae:
	/* 0x32ae: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_32b2:
	/* 0x32b2: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_32b9:
	/* 0x32b9: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_32be:
	/* 0x32be: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_32c3:
	/* 0x32c3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32c8:
	/* 0x32c8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_32d0:
	/* 0x32d0: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_32d4:
	/* 0x32d4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_32db:
	/* 0x32db: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_32e0:
	/* 0x32e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e2:
	/* 0x32e2: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_32e7:
	/* 0x32e7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_32ef:
	/* 0x32ef: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_32f2:
	/* 0x32f2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_32fa:
	/* 0x32fa: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3303:
	/* 0x3303: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_330a:
	/* 0x330a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_330f:
	/* 0x330f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3314:
	/* 0x3314: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3319:
	/* 0x3319: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_331e:
	/* 0x331e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3321:
	/* 0x3321: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3323:
	/* 0x3323: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3328:
	/* 0x3328: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_332a:
	/* 0x332a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_332d:
	/* 0x332d: je     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2928ULL;
	}
x86_l_3333:
	/* 0x3333: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3336:
	/* 0x3336: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_333c:
	/* 0x333c: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_3342:
	/* 0x3342: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3347:
	/* 0x3347: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_334b:
	/* 0x334b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3352:
	/* 0x3352: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3357:
	/* 0x3357: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_335c:
	/* 0x335c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3363:
	/* 0x3363: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3366:
	/* 0x3366: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_336d:
	/* 0x336d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3372:
	/* 0x3372: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3377:
	/* 0x3377: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3379:
	/* 0x3379: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_337d:
	/* 0x337d: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_337f:
	/* 0x337f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3381:
	/* 0x3381: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_3387:
	/* 0x3387: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_338a:
	/* 0x338a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3390:
	/* 0x3390: ja     b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2928ULL;
	}
x86_l_3396:
	/* 0x3396: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_339b:
	/* 0x339b: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_339f:
	/* 0x339f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_33a6:
	/* 0x33a6: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_33ab:
	/* 0x33ab: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_33b0:
	/* 0x33b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33b5:
	/* 0x33b5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_33bd:
	/* 0x33bd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_33c1:
	/* 0x33c1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_33c8:
	/* 0x33c8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_33cd:
	/* 0x33cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33cf:
	/* 0x33cf: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_33d4:
	/* 0x33d4: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_33dc:
	/* 0x33dc: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_33df:
	/* 0x33df: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_33e7:
	/* 0x33e7: mov    DWORD PTR [rsp+0x94],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635658186286ULL);
x86_l_33f2:
	/* 0x33f2: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_33f5:
	/* 0x33f5: cmp    ecx,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27901ULL);
x86_l_33fb:
	/* 0x33fb: jb     3406 <syscall__execve_exit+0x3406> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3406;
	}
x86_l_33fd:
	/* 0x33fd: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_3402:
	/* 0x3402: mov    ax,0x6cfc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 27900ULL);
x86_l_3406:
	/* 0x3406: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3409:
	/* 0x3409: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_340e:
	/* 0x340e: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3412:
	/* 0x3412: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3419:
	/* 0x3419: lea    rdx,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_3421:
	/* 0x3421: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3426:
	/* 0x3426: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_342b:
	/* 0x342b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3432:
	/* 0x3432: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3435:
	/* 0x3435: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_343c:
	/* 0x343c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3441:
	/* 0x3441: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3443:
	/* 0x3443: mov    DWORD PTR [rsp+0x84],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_344a:
	/* 0x344a: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_344c:
	/* 0x344c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_344e:
	/* 0x344e: jle    b70 <syscall__execve_exit+0xb70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2928ULL;
	}
x86_l_3454:
	/* 0x3454: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3457:
	/* 0x3457: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_345d:
	/* 0x345d: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3462:
	/* 0x3462: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3467:
	/* 0x3467: ja     b7a <syscall__execve_exit+0xb7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2938ULL;
	}
x86_l_346d:
	/* 0x346d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3472:
	/* 0x3472: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3476:
	/* 0x3476: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_347d:
	/* 0x347d: lea    rdx,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_3485:
	/* 0x3485: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_348a:
	/* 0x348a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_348f:
	/* 0x348f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3497:
	/* 0x3497: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_349b:
	/* 0x349b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_34a2:
	/* 0x34a2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34a7:
	/* 0x34a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34a9:
	/* 0x34a9: movzx  eax,WORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 132ULL);
x86_l_34b1:
	/* 0x34b1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_34b9:
	/* 0x34b9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_34bc:
	/* 0x34bc: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_34c4:
	/* 0x34c4: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_34c6:
	/* 0x34c6: jmp    b7a <syscall__execve_exit+0xb7a> */
	return 2938ULL;
x86_l_34cb:
	/* 0x34cb: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_34cf:
	/* 0x34cf: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_34d6:
	/* 0x34d6: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_34db:
	/* 0x34db: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34e0:
	/* 0x34e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34e5:
	/* 0x34e5: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_34ec:
	/* 0x34ec: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_34f0:
	/* 0x34f0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_34f7:
	/* 0x34f7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34fc:
	/* 0x34fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34fe:
	/* 0x34fe: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3503:
	/* 0x3503: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_350a:
	/* 0x350a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_350d:
	/* 0x350d: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3514:
	/* 0x3514: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_351d:
	/* 0x351d: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3521:
	/* 0x3521: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3526:
	/* 0x3526: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_352b:
	/* 0x352b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3530:
	/* 0x3530: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3535:
	/* 0x3535: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3537:
	/* 0x3537: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_353c:
	/* 0x353c: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_353e:
	/* 0x353e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3541:
	/* 0x3541: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_3547:
	/* 0x3547: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_354a:
	/* 0x354a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3550:
	/* 0x3550: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3556:
	/* 0x3556: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_355b:
	/* 0x355b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_355f:
	/* 0x355f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3566:
	/* 0x3566: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_356b:
	/* 0x356b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3570:
	/* 0x3570: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3577:
	/* 0x3577: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_357a:
	/* 0x357a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3581:
	/* 0x3581: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3586:
	/* 0x3586: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_358b:
	/* 0x358b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_358d:
	/* 0x358d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3591:
	/* 0x3591: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_3593:
	/* 0x3593: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3595:
	/* 0x3595: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_359b:
	/* 0x359b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_359e:
	/* 0x359e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_35a4:
	/* 0x35a4: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_35aa:
	/* 0x35aa: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35af:
	/* 0x35af: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_35b3:
	/* 0x35b3: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_35ba:
	/* 0x35ba: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_35bf:
	/* 0x35bf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_35c4:
	/* 0x35c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35c9:
	/* 0x35c9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_35d1:
	/* 0x35d1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_35d5:
	/* 0x35d5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_35dc:
	/* 0x35dc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_35e1:
	/* 0x35e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35e3:
	/* 0x35e3: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_35e8:
	/* 0x35e8: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_35f0:
	/* 0x35f0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_35f3:
	/* 0x35f3: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_35fb:
	/* 0x35fb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3604:
	/* 0x3604: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3608:
	/* 0x3608: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_360d:
	/* 0x360d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3612:
	/* 0x3612: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3617:
	/* 0x3617: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_361c:
	/* 0x361c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_361e:
	/* 0x361e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3623:
	/* 0x3623: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_3625:
	/* 0x3625: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3628:
	/* 0x3628: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_362e:
	/* 0x362e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3631:
	/* 0x3631: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3637:
	/* 0x3637: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_363d:
	/* 0x363d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3642:
	/* 0x3642: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3646:
	/* 0x3646: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_364d:
	/* 0x364d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3652:
	/* 0x3652: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3657:
	/* 0x3657: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_365e:
	/* 0x365e: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3661:
	/* 0x3661: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3668:
	/* 0x3668: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_366d:
	/* 0x366d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3672:
	/* 0x3672: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3674:
	/* 0x3674: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3678:
	/* 0x3678: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_367a:
	/* 0x367a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_367c:
	/* 0x367c: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_3682:
	/* 0x3682: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3685:
	/* 0x3685: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_368b:
	/* 0x368b: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3691:
	/* 0x3691: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3696:
	/* 0x3696: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_369a:
	/* 0x369a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_36a1:
	/* 0x36a1: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_36a6:
	/* 0x36a6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_36ab:
	/* 0x36ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36b0:
	/* 0x36b0: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_36b8:
	/* 0x36b8: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_36bc:
	/* 0x36bc: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_36c3:
	/* 0x36c3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_36c8:
	/* 0x36c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36ca:
	/* 0x36ca: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_36cf:
	/* 0x36cf: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_36d7:
	/* 0x36d7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_36da:
	/* 0x36da: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_36e2:
	/* 0x36e2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_36eb:
	/* 0x36eb: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36ef:
	/* 0x36ef: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36f4:
	/* 0x36f4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_36f9:
	/* 0x36f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36fe:
	/* 0x36fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3703:
	/* 0x3703: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3705:
	/* 0x3705: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_370a:
	/* 0x370a: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_370c:
	/* 0x370c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_370f:
	/* 0x370f: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_3715:
	/* 0x3715: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3718:
	/* 0x3718: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_371e:
	/* 0x371e: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3724:
	/* 0x3724: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3729:
	/* 0x3729: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_372d:
	/* 0x372d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3734:
	/* 0x3734: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3739:
	/* 0x3739: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_373e:
	/* 0x373e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3745:
	/* 0x3745: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3748:
	/* 0x3748: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_374f:
	/* 0x374f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3754:
	/* 0x3754: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3759:
	/* 0x3759: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_375b:
	/* 0x375b: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_375f:
	/* 0x375f: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_3761:
	/* 0x3761: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3763:
	/* 0x3763: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_3769:
	/* 0x3769: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_376c:
	/* 0x376c: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3772:
	/* 0x3772: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3778:
	/* 0x3778: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_377d:
	/* 0x377d: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3781:
	/* 0x3781: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3788:
	/* 0x3788: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_378d:
	/* 0x378d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3792:
	/* 0x3792: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3797:
	/* 0x3797: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_379f:
	/* 0x379f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_37a3:
	/* 0x37a3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_37aa:
	/* 0x37aa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_37af:
	/* 0x37af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37b1:
	/* 0x37b1: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_37b6:
	/* 0x37b6: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_37be:
	/* 0x37be: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_37c1:
	/* 0x37c1: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_37c9:
	/* 0x37c9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_37d2:
	/* 0x37d2: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37d6:
	/* 0x37d6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37db:
	/* 0x37db: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37e0:
	/* 0x37e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37e5:
	/* 0x37e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37ea:
	/* 0x37ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37ec:
	/* 0x37ec: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37f1:
	/* 0x37f1: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_37f3:
	/* 0x37f3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_37f6:
	/* 0x37f6: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_37fc:
	/* 0x37fc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37ff:
	/* 0x37ff: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3805:
	/* 0x3805: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_380b:
	/* 0x380b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3810:
	/* 0x3810: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3814:
	/* 0x3814: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_381b:
	/* 0x381b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3820:
	/* 0x3820: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3825:
	/* 0x3825: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_382c:
	/* 0x382c: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_382f:
	/* 0x382f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3836:
	/* 0x3836: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_383b:
	/* 0x383b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3840:
	/* 0x3840: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3842:
	/* 0x3842: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3846:
	/* 0x3846: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_3848:
	/* 0x3848: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_384a:
	/* 0x384a: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_3850:
	/* 0x3850: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3853:
	/* 0x3853: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3859:
	/* 0x3859: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_385f:
	/* 0x385f: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3864:
	/* 0x3864: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3868:
	/* 0x3868: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_386f:
	/* 0x386f: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3874:
	/* 0x3874: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3879:
	/* 0x3879: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_387e:
	/* 0x387e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3886:
	/* 0x3886: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_388a:
	/* 0x388a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3891:
	/* 0x3891: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3896:
	/* 0x3896: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3898:
	/* 0x3898: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_389d:
	/* 0x389d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_38a5:
	/* 0x38a5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_38a8:
	/* 0x38a8: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_38b0:
	/* 0x38b0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_38b9:
	/* 0x38b9: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_38bd:
	/* 0x38bd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38c2:
	/* 0x38c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_38c7:
	/* 0x38c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38cc:
	/* 0x38cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38d1:
	/* 0x38d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38d3:
	/* 0x38d3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38d8:
	/* 0x38d8: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_38da:
	/* 0x38da: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_38dd:
	/* 0x38dd: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_38e3:
	/* 0x38e3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38e6:
	/* 0x38e6: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_38ec:
	/* 0x38ec: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_38f2:
	/* 0x38f2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38f7:
	/* 0x38f7: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_38fb:
	/* 0x38fb: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3902:
	/* 0x3902: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3907:
	/* 0x3907: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_390c:
	/* 0x390c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3913:
	/* 0x3913: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3916:
	/* 0x3916: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
	return 14621ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14621ULL: goto x86_l_391d;
	case 14626ULL: goto x86_l_3922;
	case 14631ULL: goto x86_l_3927;
	case 14633ULL: goto x86_l_3929;
	case 14637ULL: goto x86_l_392d;
	case 14639ULL: goto x86_l_392f;
	case 14641ULL: goto x86_l_3931;
	case 14647ULL: goto x86_l_3937;
	case 14650ULL: goto x86_l_393a;
	case 14656ULL: goto x86_l_3940;
	case 14662ULL: goto x86_l_3946;
	case 14667ULL: goto x86_l_394b;
	case 14671ULL: goto x86_l_394f;
	case 14678ULL: goto x86_l_3956;
	case 14683ULL: goto x86_l_395b;
	case 14688ULL: goto x86_l_3960;
	case 14693ULL: goto x86_l_3965;
	case 14701ULL: goto x86_l_396d;
	case 14705ULL: goto x86_l_3971;
	case 14712ULL: goto x86_l_3978;
	case 14717ULL: goto x86_l_397d;
	case 14719ULL: goto x86_l_397f;
	case 14724ULL: goto x86_l_3984;
	case 14732ULL: goto x86_l_398c;
	case 14735ULL: goto x86_l_398f;
	case 14743ULL: goto x86_l_3997;
	case 14752ULL: goto x86_l_39a0;
	case 14756ULL: goto x86_l_39a4;
	case 14761ULL: goto x86_l_39a9;
	case 14766ULL: goto x86_l_39ae;
	case 14771ULL: goto x86_l_39b3;
	case 14776ULL: goto x86_l_39b8;
	case 14778ULL: goto x86_l_39ba;
	case 14783ULL: goto x86_l_39bf;
	case 14785ULL: goto x86_l_39c1;
	case 14788ULL: goto x86_l_39c4;
	case 14794ULL: goto x86_l_39ca;
	case 14797ULL: goto x86_l_39cd;
	case 14803ULL: goto x86_l_39d3;
	case 14809ULL: goto x86_l_39d9;
	case 14814ULL: goto x86_l_39de;
	case 14818ULL: goto x86_l_39e2;
	case 14825ULL: goto x86_l_39e9;
	case 14830ULL: goto x86_l_39ee;
	case 14835ULL: goto x86_l_39f3;
	case 14842ULL: goto x86_l_39fa;
	case 14845ULL: goto x86_l_39fd;
	case 14852ULL: goto x86_l_3a04;
	case 14857ULL: goto x86_l_3a09;
	case 14862ULL: goto x86_l_3a0e;
	case 14864ULL: goto x86_l_3a10;
	case 14868ULL: goto x86_l_3a14;
	case 14870ULL: goto x86_l_3a16;
	case 14872ULL: goto x86_l_3a18;
	case 14878ULL: goto x86_l_3a1e;
	case 14881ULL: goto x86_l_3a21;
	case 14887ULL: goto x86_l_3a27;
	case 14893ULL: goto x86_l_3a2d;
	case 14898ULL: goto x86_l_3a32;
	case 14902ULL: goto x86_l_3a36;
	case 14909ULL: goto x86_l_3a3d;
	case 14914ULL: goto x86_l_3a42;
	case 14919ULL: goto x86_l_3a47;
	case 14924ULL: goto x86_l_3a4c;
	case 14932ULL: goto x86_l_3a54;
	case 14936ULL: goto x86_l_3a58;
	case 14943ULL: goto x86_l_3a5f;
	case 14948ULL: goto x86_l_3a64;
	case 14950ULL: goto x86_l_3a66;
	case 14955ULL: goto x86_l_3a6b;
	case 14963ULL: goto x86_l_3a73;
	case 14966ULL: goto x86_l_3a76;
	case 14974ULL: goto x86_l_3a7e;
	case 14983ULL: goto x86_l_3a87;
	case 14987ULL: goto x86_l_3a8b;
	case 14992ULL: goto x86_l_3a90;
	case 14997ULL: goto x86_l_3a95;
	case 15002ULL: goto x86_l_3a9a;
	case 15007ULL: goto x86_l_3a9f;
	case 15009ULL: goto x86_l_3aa1;
	case 15014ULL: goto x86_l_3aa6;
	case 15016ULL: goto x86_l_3aa8;
	case 15019ULL: goto x86_l_3aab;
	case 15025ULL: goto x86_l_3ab1;
	case 15028ULL: goto x86_l_3ab4;
	case 15034ULL: goto x86_l_3aba;
	case 15040ULL: goto x86_l_3ac0;
	case 15045ULL: goto x86_l_3ac5;
	case 15049ULL: goto x86_l_3ac9;
	case 15056ULL: goto x86_l_3ad0;
	case 15061ULL: goto x86_l_3ad5;
	case 15066ULL: goto x86_l_3ada;
	case 15073ULL: goto x86_l_3ae1;
	case 15076ULL: goto x86_l_3ae4;
	case 15083ULL: goto x86_l_3aeb;
	case 15088ULL: goto x86_l_3af0;
	case 15093ULL: goto x86_l_3af5;
	case 15095ULL: goto x86_l_3af7;
	case 15099ULL: goto x86_l_3afb;
	case 15101ULL: goto x86_l_3afd;
	case 15103ULL: goto x86_l_3aff;
	case 15109ULL: goto x86_l_3b05;
	case 15112ULL: goto x86_l_3b08;
	case 15118ULL: goto x86_l_3b0e;
	case 15124ULL: goto x86_l_3b14;
	case 15129ULL: goto x86_l_3b19;
	case 15133ULL: goto x86_l_3b1d;
	case 15140ULL: goto x86_l_3b24;
	case 15145ULL: goto x86_l_3b29;
	case 15150ULL: goto x86_l_3b2e;
	case 15155ULL: goto x86_l_3b33;
	case 15163ULL: goto x86_l_3b3b;
	case 15167ULL: goto x86_l_3b3f;
	case 15174ULL: goto x86_l_3b46;
	case 15179ULL: goto x86_l_3b4b;
	case 15181ULL: goto x86_l_3b4d;
	case 15186ULL: goto x86_l_3b52;
	case 15194ULL: goto x86_l_3b5a;
	case 15197ULL: goto x86_l_3b5d;
	case 15205ULL: goto x86_l_3b65;
	case 15214ULL: goto x86_l_3b6e;
	case 15218ULL: goto x86_l_3b72;
	case 15223ULL: goto x86_l_3b77;
	case 15228ULL: goto x86_l_3b7c;
	case 15233ULL: goto x86_l_3b81;
	case 15238ULL: goto x86_l_3b86;
	case 15240ULL: goto x86_l_3b88;
	case 15245ULL: goto x86_l_3b8d;
	case 15247ULL: goto x86_l_3b8f;
	case 15250ULL: goto x86_l_3b92;
	case 15256ULL: goto x86_l_3b98;
	case 15259ULL: goto x86_l_3b9b;
	case 15265ULL: goto x86_l_3ba1;
	case 15271ULL: goto x86_l_3ba7;
	case 15276ULL: goto x86_l_3bac;
	case 15280ULL: goto x86_l_3bb0;
	case 15287ULL: goto x86_l_3bb7;
	case 15292ULL: goto x86_l_3bbc;
	case 15297ULL: goto x86_l_3bc1;
	case 15304ULL: goto x86_l_3bc8;
	case 15307ULL: goto x86_l_3bcb;
	case 15314ULL: goto x86_l_3bd2;
	case 15319ULL: goto x86_l_3bd7;
	case 15324ULL: goto x86_l_3bdc;
	case 15326ULL: goto x86_l_3bde;
	case 15330ULL: goto x86_l_3be2;
	case 15332ULL: goto x86_l_3be4;
	case 15334ULL: goto x86_l_3be6;
	case 15340ULL: goto x86_l_3bec;
	case 15343ULL: goto x86_l_3bef;
	case 15349ULL: goto x86_l_3bf5;
	case 15355ULL: goto x86_l_3bfb;
	case 15360ULL: goto x86_l_3c00;
	case 15364ULL: goto x86_l_3c04;
	case 15371ULL: goto x86_l_3c0b;
	case 15376ULL: goto x86_l_3c10;
	case 15381ULL: goto x86_l_3c15;
	case 15386ULL: goto x86_l_3c1a;
	case 15394ULL: goto x86_l_3c22;
	case 15398ULL: goto x86_l_3c26;
	case 15405ULL: goto x86_l_3c2d;
	case 15410ULL: goto x86_l_3c32;
	case 15412ULL: goto x86_l_3c34;
	case 15417ULL: goto x86_l_3c39;
	case 15425ULL: goto x86_l_3c41;
	case 15428ULL: goto x86_l_3c44;
	case 15436ULL: goto x86_l_3c4c;
	case 15445ULL: goto x86_l_3c55;
	case 15449ULL: goto x86_l_3c59;
	case 15454ULL: goto x86_l_3c5e;
	case 15459ULL: goto x86_l_3c63;
	case 15464ULL: goto x86_l_3c68;
	case 15469ULL: goto x86_l_3c6d;
	case 15471ULL: goto x86_l_3c6f;
	case 15476ULL: goto x86_l_3c74;
	case 15478ULL: goto x86_l_3c76;
	case 15481ULL: goto x86_l_3c79;
	case 15487ULL: goto x86_l_3c7f;
	case 15490ULL: goto x86_l_3c82;
	case 15496ULL: goto x86_l_3c88;
	case 15502ULL: goto x86_l_3c8e;
	case 15507ULL: goto x86_l_3c93;
	case 15511ULL: goto x86_l_3c97;
	case 15518ULL: goto x86_l_3c9e;
	case 15523ULL: goto x86_l_3ca3;
	case 15528ULL: goto x86_l_3ca8;
	case 15535ULL: goto x86_l_3caf;
	case 15538ULL: goto x86_l_3cb2;
	case 15545ULL: goto x86_l_3cb9;
	case 15550ULL: goto x86_l_3cbe;
	case 15555ULL: goto x86_l_3cc3;
	case 15557ULL: goto x86_l_3cc5;
	case 15561ULL: goto x86_l_3cc9;
	case 15563ULL: goto x86_l_3ccb;
	case 15565ULL: goto x86_l_3ccd;
	case 15571ULL: goto x86_l_3cd3;
	case 15574ULL: goto x86_l_3cd6;
	case 15580ULL: goto x86_l_3cdc;
	case 15586ULL: goto x86_l_3ce2;
	case 15591ULL: goto x86_l_3ce7;
	case 15595ULL: goto x86_l_3ceb;
	case 15602ULL: goto x86_l_3cf2;
	case 15607ULL: goto x86_l_3cf7;
	case 15612ULL: goto x86_l_3cfc;
	case 15617ULL: goto x86_l_3d01;
	case 15625ULL: goto x86_l_3d09;
	case 15629ULL: goto x86_l_3d0d;
	case 15636ULL: goto x86_l_3d14;
	case 15641ULL: goto x86_l_3d19;
	case 15643ULL: goto x86_l_3d1b;
	case 15648ULL: goto x86_l_3d20;
	case 15656ULL: goto x86_l_3d28;
	case 15659ULL: goto x86_l_3d2b;
	case 15667ULL: goto x86_l_3d33;
	case 15676ULL: goto x86_l_3d3c;
	case 15680ULL: goto x86_l_3d40;
	case 15685ULL: goto x86_l_3d45;
	case 15690ULL: goto x86_l_3d4a;
	case 15695ULL: goto x86_l_3d4f;
	case 15700ULL: goto x86_l_3d54;
	case 15702ULL: goto x86_l_3d56;
	case 15707ULL: goto x86_l_3d5b;
	case 15709ULL: goto x86_l_3d5d;
	case 15712ULL: goto x86_l_3d60;
	case 15718ULL: goto x86_l_3d66;
	case 15721ULL: goto x86_l_3d69;
	case 15727ULL: goto x86_l_3d6f;
	case 15733ULL: goto x86_l_3d75;
	case 15738ULL: goto x86_l_3d7a;
	case 15742ULL: goto x86_l_3d7e;
	case 15749ULL: goto x86_l_3d85;
	case 15754ULL: goto x86_l_3d8a;
	case 15759ULL: goto x86_l_3d8f;
	case 15766ULL: goto x86_l_3d96;
	case 15769ULL: goto x86_l_3d99;
	case 15776ULL: goto x86_l_3da0;
	case 15781ULL: goto x86_l_3da5;
	case 15786ULL: goto x86_l_3daa;
	case 15788ULL: goto x86_l_3dac;
	case 15792ULL: goto x86_l_3db0;
	case 15794ULL: goto x86_l_3db2;
	case 15796ULL: goto x86_l_3db4;
	case 15802ULL: goto x86_l_3dba;
	case 15805ULL: goto x86_l_3dbd;
	case 15811ULL: goto x86_l_3dc3;
	case 15817ULL: goto x86_l_3dc9;
	case 15822ULL: goto x86_l_3dce;
	case 15826ULL: goto x86_l_3dd2;
	case 15833ULL: goto x86_l_3dd9;
	case 15838ULL: goto x86_l_3dde;
	case 15843ULL: goto x86_l_3de3;
	case 15848ULL: goto x86_l_3de8;
	case 15856ULL: goto x86_l_3df0;
	case 15860ULL: goto x86_l_3df4;
	case 15867ULL: goto x86_l_3dfb;
	case 15872ULL: goto x86_l_3e00;
	case 15874ULL: goto x86_l_3e02;
	case 15879ULL: goto x86_l_3e07;
	case 15887ULL: goto x86_l_3e0f;
	case 15890ULL: goto x86_l_3e12;
	case 15898ULL: goto x86_l_3e1a;
	case 15907ULL: goto x86_l_3e23;
	case 15911ULL: goto x86_l_3e27;
	case 15916ULL: goto x86_l_3e2c;
	case 15921ULL: goto x86_l_3e31;
	case 15926ULL: goto x86_l_3e36;
	case 15931ULL: goto x86_l_3e3b;
	case 15933ULL: goto x86_l_3e3d;
	case 15938ULL: goto x86_l_3e42;
	case 15940ULL: goto x86_l_3e44;
	case 15943ULL: goto x86_l_3e47;
	case 15949ULL: goto x86_l_3e4d;
	case 15952ULL: goto x86_l_3e50;
	case 15958ULL: goto x86_l_3e56;
	case 15964ULL: goto x86_l_3e5c;
	case 15969ULL: goto x86_l_3e61;
	case 15973ULL: goto x86_l_3e65;
	case 15980ULL: goto x86_l_3e6c;
	case 15985ULL: goto x86_l_3e71;
	case 15990ULL: goto x86_l_3e76;
	case 15997ULL: goto x86_l_3e7d;
	case 16000ULL: goto x86_l_3e80;
	case 16007ULL: goto x86_l_3e87;
	case 16012ULL: goto x86_l_3e8c;
	case 16017ULL: goto x86_l_3e91;
	case 16019ULL: goto x86_l_3e93;
	case 16023ULL: goto x86_l_3e97;
	case 16025ULL: goto x86_l_3e99;
	case 16027ULL: goto x86_l_3e9b;
	case 16033ULL: goto x86_l_3ea1;
	case 16036ULL: goto x86_l_3ea4;
	case 16042ULL: goto x86_l_3eaa;
	case 16048ULL: goto x86_l_3eb0;
	case 16053ULL: goto x86_l_3eb5;
	case 16057ULL: goto x86_l_3eb9;
	case 16064ULL: goto x86_l_3ec0;
	case 16069ULL: goto x86_l_3ec5;
	case 16074ULL: goto x86_l_3eca;
	case 16079ULL: goto x86_l_3ecf;
	case 16087ULL: goto x86_l_3ed7;
	case 16091ULL: goto x86_l_3edb;
	case 16098ULL: goto x86_l_3ee2;
	case 16103ULL: goto x86_l_3ee7;
	case 16105ULL: goto x86_l_3ee9;
	case 16110ULL: goto x86_l_3eee;
	case 16118ULL: goto x86_l_3ef6;
	case 16121ULL: goto x86_l_3ef9;
	case 16129ULL: goto x86_l_3f01;
	case 16138ULL: goto x86_l_3f0a;
	case 16142ULL: goto x86_l_3f0e;
	case 16147ULL: goto x86_l_3f13;
	case 16152ULL: goto x86_l_3f18;
	case 16157ULL: goto x86_l_3f1d;
	case 16162ULL: goto x86_l_3f22;
	case 16164ULL: goto x86_l_3f24;
	case 16169ULL: goto x86_l_3f29;
	case 16171ULL: goto x86_l_3f2b;
	case 16174ULL: goto x86_l_3f2e;
	case 16180ULL: goto x86_l_3f34;
	case 16183ULL: goto x86_l_3f37;
	case 16189ULL: goto x86_l_3f3d;
	case 16195ULL: goto x86_l_3f43;
	case 16200ULL: goto x86_l_3f48;
	case 16204ULL: goto x86_l_3f4c;
	case 16211ULL: goto x86_l_3f53;
	case 16216ULL: goto x86_l_3f58;
	case 16221ULL: goto x86_l_3f5d;
	case 16228ULL: goto x86_l_3f64;
	case 16231ULL: goto x86_l_3f67;
	case 16238ULL: goto x86_l_3f6e;
	case 16243ULL: goto x86_l_3f73;
	case 16248ULL: goto x86_l_3f78;
	case 16250ULL: goto x86_l_3f7a;
	case 16254ULL: goto x86_l_3f7e;
	case 16256ULL: goto x86_l_3f80;
	case 16258ULL: goto x86_l_3f82;
	case 16264ULL: goto x86_l_3f88;
	case 16267ULL: goto x86_l_3f8b;
	case 16273ULL: goto x86_l_3f91;
	case 16279ULL: goto x86_l_3f97;
	case 16284ULL: goto x86_l_3f9c;
	case 16288ULL: goto x86_l_3fa0;
	case 16295ULL: goto x86_l_3fa7;
	case 16300ULL: goto x86_l_3fac;
	case 16305ULL: goto x86_l_3fb1;
	case 16310ULL: goto x86_l_3fb6;
	case 16318ULL: goto x86_l_3fbe;
	case 16322ULL: goto x86_l_3fc2;
	case 16329ULL: goto x86_l_3fc9;
	case 16334ULL: goto x86_l_3fce;
	case 16336ULL: goto x86_l_3fd0;
	case 16341ULL: goto x86_l_3fd5;
	case 16349ULL: goto x86_l_3fdd;
	case 16352ULL: goto x86_l_3fe0;
	case 16360ULL: goto x86_l_3fe8;
	case 16369ULL: goto x86_l_3ff1;
	case 16373ULL: goto x86_l_3ff5;
	case 16378ULL: goto x86_l_3ffa;
	case 16383ULL: goto x86_l_3fff;
	case 16388ULL: goto x86_l_4004;
	case 16393ULL: goto x86_l_4009;
	case 16395ULL: goto x86_l_400b;
	case 16400ULL: goto x86_l_4010;
	case 16402ULL: goto x86_l_4012;
	case 16405ULL: goto x86_l_4015;
	case 16411ULL: goto x86_l_401b;
	case 16414ULL: goto x86_l_401e;
	case 16420ULL: goto x86_l_4024;
	case 16426ULL: goto x86_l_402a;
	case 16431ULL: goto x86_l_402f;
	case 16435ULL: goto x86_l_4033;
	case 16442ULL: goto x86_l_403a;
	case 16447ULL: goto x86_l_403f;
	case 16452ULL: goto x86_l_4044;
	case 16459ULL: goto x86_l_404b;
	case 16462ULL: goto x86_l_404e;
	case 16469ULL: goto x86_l_4055;
	case 16474ULL: goto x86_l_405a;
	case 16479ULL: goto x86_l_405f;
	case 16481ULL: goto x86_l_4061;
	case 16485ULL: goto x86_l_4065;
	case 16487ULL: goto x86_l_4067;
	case 16489ULL: goto x86_l_4069;
	case 16495ULL: goto x86_l_406f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_391d:
	/* 0x391d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3922:
	/* 0x3922: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3927:
	/* 0x3927: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3929:
	/* 0x3929: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_392d:
	/* 0x392d: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_392f:
	/* 0x392f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3931:
	/* 0x3931: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_3937:
	/* 0x3937: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_393a:
	/* 0x393a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3940:
	/* 0x3940: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3946:
	/* 0x3946: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_394b:
	/* 0x394b: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_394f:
	/* 0x394f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3956:
	/* 0x3956: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_395b:
	/* 0x395b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3960:
	/* 0x3960: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3965:
	/* 0x3965: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_396d:
	/* 0x396d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3971:
	/* 0x3971: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3978:
	/* 0x3978: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_397d:
	/* 0x397d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_397f:
	/* 0x397f: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3984:
	/* 0x3984: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_398c:
	/* 0x398c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_398f:
	/* 0x398f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3997:
	/* 0x3997: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_39a0:
	/* 0x39a0: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39a4:
	/* 0x39a4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39a9:
	/* 0x39a9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_39ae:
	/* 0x39ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39b3:
	/* 0x39b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39b8:
	/* 0x39b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39ba:
	/* 0x39ba: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39bf:
	/* 0x39bf: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_39c1:
	/* 0x39c1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_39c4:
	/* 0x39c4: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_39ca:
	/* 0x39ca: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_39cd:
	/* 0x39cd: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_39d3:
	/* 0x39d3: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_39d9:
	/* 0x39d9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39de:
	/* 0x39de: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_39e2:
	/* 0x39e2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_39e9:
	/* 0x39e9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_39ee:
	/* 0x39ee: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_39f3:
	/* 0x39f3: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_39fa:
	/* 0x39fa: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_39fd:
	/* 0x39fd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3a04:
	/* 0x3a04: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a09:
	/* 0x3a09: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3a0e:
	/* 0x3a0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a10:
	/* 0x3a10: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a14:
	/* 0x3a14: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_3a16:
	/* 0x3a16: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a18:
	/* 0x3a18: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_3a1e:
	/* 0x3a1e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a21:
	/* 0x3a21: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3a27:
	/* 0x3a27: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3a2d:
	/* 0x3a2d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a32:
	/* 0x3a32: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3a36:
	/* 0x3a36: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3a3d:
	/* 0x3a3d: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a42:
	/* 0x3a42: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3a47:
	/* 0x3a47: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a4c:
	/* 0x3a4c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a54:
	/* 0x3a54: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3a58:
	/* 0x3a58: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3a5f:
	/* 0x3a5f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3a64:
	/* 0x3a64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a66:
	/* 0x3a66: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3a6b:
	/* 0x3a6b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3a73:
	/* 0x3a73: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3a76:
	/* 0x3a76: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3a7e:
	/* 0x3a7e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3a87:
	/* 0x3a87: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3a8b:
	/* 0x3a8b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a90:
	/* 0x3a90: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a95:
	/* 0x3a95: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a9a:
	/* 0x3a9a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a9f:
	/* 0x3a9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3aa1:
	/* 0x3aa1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aa6:
	/* 0x3aa6: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_3aa8:
	/* 0x3aa8: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3aab:
	/* 0x3aab: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_3ab1:
	/* 0x3ab1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ab4:
	/* 0x3ab4: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3aba:
	/* 0x3aba: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3ac0:
	/* 0x3ac0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ac5:
	/* 0x3ac5: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3ac9:
	/* 0x3ac9: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3ad0:
	/* 0x3ad0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3ad5:
	/* 0x3ad5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3ada:
	/* 0x3ada: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ae1:
	/* 0x3ae1: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3ae4:
	/* 0x3ae4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3aeb:
	/* 0x3aeb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3af0:
	/* 0x3af0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3af5:
	/* 0x3af5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3af7:
	/* 0x3af7: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3afb:
	/* 0x3afb: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_3afd:
	/* 0x3afd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3aff:
	/* 0x3aff: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_3b05:
	/* 0x3b05: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b08:
	/* 0x3b08: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3b0e:
	/* 0x3b0e: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3b14:
	/* 0x3b14: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b19:
	/* 0x3b19: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3b1d:
	/* 0x3b1d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3b24:
	/* 0x3b24: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b29:
	/* 0x3b29: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b2e:
	/* 0x3b2e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b33:
	/* 0x3b33: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b3b:
	/* 0x3b3b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3b3f:
	/* 0x3b3f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3b46:
	/* 0x3b46: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b4b:
	/* 0x3b4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b4d:
	/* 0x3b4d: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3b52:
	/* 0x3b52: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3b5a:
	/* 0x3b5a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3b5d:
	/* 0x3b5d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3b65:
	/* 0x3b65: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3b6e:
	/* 0x3b6e: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3b72:
	/* 0x3b72: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b77:
	/* 0x3b77: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b7c:
	/* 0x3b7c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b81:
	/* 0x3b81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b86:
	/* 0x3b86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b88:
	/* 0x3b88: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b8d:
	/* 0x3b8d: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_3b8f:
	/* 0x3b8f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3b92:
	/* 0x3b92: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_3b98:
	/* 0x3b98: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b9b:
	/* 0x3b9b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3ba1:
	/* 0x3ba1: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3ba7:
	/* 0x3ba7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bac:
	/* 0x3bac: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3bb0:
	/* 0x3bb0: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3bb7:
	/* 0x3bb7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3bbc:
	/* 0x3bbc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3bc1:
	/* 0x3bc1: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3bc8:
	/* 0x3bc8: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3bcb:
	/* 0x3bcb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3bd2:
	/* 0x3bd2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bd7:
	/* 0x3bd7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3bdc:
	/* 0x3bdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bde:
	/* 0x3bde: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3be2:
	/* 0x3be2: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_3be4:
	/* 0x3be4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3be6:
	/* 0x3be6: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_3bec:
	/* 0x3bec: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3bef:
	/* 0x3bef: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3bf5:
	/* 0x3bf5: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3bfb:
	/* 0x3bfb: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c00:
	/* 0x3c00: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3c04:
	/* 0x3c04: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3c0b:
	/* 0x3c0b: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3c10:
	/* 0x3c10: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c15:
	/* 0x3c15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c1a:
	/* 0x3c1a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c22:
	/* 0x3c22: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3c26:
	/* 0x3c26: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3c2d:
	/* 0x3c2d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c32:
	/* 0x3c32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c34:
	/* 0x3c34: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3c39:
	/* 0x3c39: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3c41:
	/* 0x3c41: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3c44:
	/* 0x3c44: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3c4c:
	/* 0x3c4c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3c55:
	/* 0x3c55: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3c59:
	/* 0x3c59: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c5e:
	/* 0x3c5e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c63:
	/* 0x3c63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c68:
	/* 0x3c68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c6d:
	/* 0x3c6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c6f:
	/* 0x3c6f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c74:
	/* 0x3c74: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_3c76:
	/* 0x3c76: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3c79:
	/* 0x3c79: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_3c7f:
	/* 0x3c7f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c82:
	/* 0x3c82: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3c88:
	/* 0x3c88: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3c8e:
	/* 0x3c8e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c93:
	/* 0x3c93: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3c97:
	/* 0x3c97: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c9e:
	/* 0x3c9e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3ca3:
	/* 0x3ca3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3ca8:
	/* 0x3ca8: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3caf:
	/* 0x3caf: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3cb2:
	/* 0x3cb2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3cb9:
	/* 0x3cb9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cbe:
	/* 0x3cbe: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3cc3:
	/* 0x3cc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cc5:
	/* 0x3cc5: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3cc9:
	/* 0x3cc9: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_3ccb:
	/* 0x3ccb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ccd:
	/* 0x3ccd: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_3cd3:
	/* 0x3cd3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3cd6:
	/* 0x3cd6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3cdc:
	/* 0x3cdc: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3ce2:
	/* 0x3ce2: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ce7:
	/* 0x3ce7: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3ceb:
	/* 0x3ceb: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3cf2:
	/* 0x3cf2: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3cf7:
	/* 0x3cf7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3cfc:
	/* 0x3cfc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d01:
	/* 0x3d01: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d09:
	/* 0x3d09: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3d0d:
	/* 0x3d0d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3d14:
	/* 0x3d14: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d19:
	/* 0x3d19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d1b:
	/* 0x3d1b: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3d20:
	/* 0x3d20: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3d28:
	/* 0x3d28: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3d2b:
	/* 0x3d2b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3d33:
	/* 0x3d33: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3d3c:
	/* 0x3d3c: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3d40:
	/* 0x3d40: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d45:
	/* 0x3d45: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3d4a:
	/* 0x3d4a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d4f:
	/* 0x3d4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d54:
	/* 0x3d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d56:
	/* 0x3d56: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d5b:
	/* 0x3d5b: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_3d5d:
	/* 0x3d5d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3d60:
	/* 0x3d60: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_3d66:
	/* 0x3d66: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d69:
	/* 0x3d69: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3d6f:
	/* 0x3d6f: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3d75:
	/* 0x3d75: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d7a:
	/* 0x3d7a: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3d7e:
	/* 0x3d7e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3d85:
	/* 0x3d85: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3d8a:
	/* 0x3d8a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3d8f:
	/* 0x3d8f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d96:
	/* 0x3d96: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d99:
	/* 0x3d99: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3da0:
	/* 0x3da0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3da5:
	/* 0x3da5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3daa:
	/* 0x3daa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dac:
	/* 0x3dac: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3db0:
	/* 0x3db0: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_3db2:
	/* 0x3db2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3db4:
	/* 0x3db4: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_3dba:
	/* 0x3dba: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3dbd:
	/* 0x3dbd: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3dc3:
	/* 0x3dc3: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3dc9:
	/* 0x3dc9: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dce:
	/* 0x3dce: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3dd2:
	/* 0x3dd2: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3dd9:
	/* 0x3dd9: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3dde:
	/* 0x3dde: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3de3:
	/* 0x3de3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3de8:
	/* 0x3de8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3df0:
	/* 0x3df0: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3df4:
	/* 0x3df4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3dfb:
	/* 0x3dfb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e00:
	/* 0x3e00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e02:
	/* 0x3e02: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3e07:
	/* 0x3e07: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3e0f:
	/* 0x3e0f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3e12:
	/* 0x3e12: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3e1a:
	/* 0x3e1a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3e23:
	/* 0x3e23: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3e27:
	/* 0x3e27: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e2c:
	/* 0x3e2c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3e31:
	/* 0x3e31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e36:
	/* 0x3e36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e3b:
	/* 0x3e3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e3d:
	/* 0x3e3d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e42:
	/* 0x3e42: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_3e44:
	/* 0x3e44: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3e47:
	/* 0x3e47: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_3e4d:
	/* 0x3e4d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e50:
	/* 0x3e50: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3e56:
	/* 0x3e56: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3e5c:
	/* 0x3e5c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e61:
	/* 0x3e61: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3e65:
	/* 0x3e65: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3e6c:
	/* 0x3e6c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3e71:
	/* 0x3e71: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3e76:
	/* 0x3e76: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e7d:
	/* 0x3e7d: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3e80:
	/* 0x3e80: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3e87:
	/* 0x3e87: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e8c:
	/* 0x3e8c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3e91:
	/* 0x3e91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e93:
	/* 0x3e93: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3e97:
	/* 0x3e97: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_3e99:
	/* 0x3e99: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e9b:
	/* 0x3e9b: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_3ea1:
	/* 0x3ea1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ea4:
	/* 0x3ea4: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3eaa:
	/* 0x3eaa: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3eb0:
	/* 0x3eb0: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3eb5:
	/* 0x3eb5: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3eb9:
	/* 0x3eb9: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3ec0:
	/* 0x3ec0: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ec5:
	/* 0x3ec5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3eca:
	/* 0x3eca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ecf:
	/* 0x3ecf: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ed7:
	/* 0x3ed7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3edb:
	/* 0x3edb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3ee2:
	/* 0x3ee2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ee7:
	/* 0x3ee7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ee9:
	/* 0x3ee9: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3eee:
	/* 0x3eee: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3ef6:
	/* 0x3ef6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3ef9:
	/* 0x3ef9: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3f01:
	/* 0x3f01: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3f0a:
	/* 0x3f0a: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3f0e:
	/* 0x3f0e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f13:
	/* 0x3f13: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f18:
	/* 0x3f18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f1d:
	/* 0x3f1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f22:
	/* 0x3f22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f24:
	/* 0x3f24: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f29:
	/* 0x3f29: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_3f2b:
	/* 0x3f2b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3f2e:
	/* 0x3f2e: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_3f34:
	/* 0x3f34: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f37:
	/* 0x3f37: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3f3d:
	/* 0x3f3d: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3f43:
	/* 0x3f43: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f48:
	/* 0x3f48: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3f4c:
	/* 0x3f4c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3f53:
	/* 0x3f53: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3f58:
	/* 0x3f58: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3f5d:
	/* 0x3f5d: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3f64:
	/* 0x3f64: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3f67:
	/* 0x3f67: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3f6e:
	/* 0x3f6e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f73:
	/* 0x3f73: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3f78:
	/* 0x3f78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f7a:
	/* 0x3f7a: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3f7e:
	/* 0x3f7e: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_3f80:
	/* 0x3f80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f82:
	/* 0x3f82: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_3f88:
	/* 0x3f88: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f8b:
	/* 0x3f8b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3f91:
	/* 0x3f91: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_3f97:
	/* 0x3f97: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f9c:
	/* 0x3f9c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3fa0:
	/* 0x3fa0: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3fa7:
	/* 0x3fa7: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3fac:
	/* 0x3fac: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3fb1:
	/* 0x3fb1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3fb6:
	/* 0x3fb6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3fbe:
	/* 0x3fbe: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3fc2:
	/* 0x3fc2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3fc9:
	/* 0x3fc9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3fce:
	/* 0x3fce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fd0:
	/* 0x3fd0: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3fd5:
	/* 0x3fd5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3fdd:
	/* 0x3fdd: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3fe0:
	/* 0x3fe0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3fe8:
	/* 0x3fe8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ff1:
	/* 0x3ff1: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ff5:
	/* 0x3ff5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ffa:
	/* 0x3ffa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3fff:
	/* 0x3fff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4004:
	/* 0x4004: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4009:
	/* 0x4009: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_400b:
	/* 0x400b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4010:
	/* 0x4010: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_4012:
	/* 0x4012: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4015:
	/* 0x4015: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_401b:
	/* 0x401b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_401e:
	/* 0x401e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4024:
	/* 0x4024: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_402a:
	/* 0x402a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_402f:
	/* 0x402f: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4033:
	/* 0x4033: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_403a:
	/* 0x403a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_403f:
	/* 0x403f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4044:
	/* 0x4044: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_404b:
	/* 0x404b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_404e:
	/* 0x404e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4055:
	/* 0x4055: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_405a:
	/* 0x405a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_405f:
	/* 0x405f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4061:
	/* 0x4061: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4065:
	/* 0x4065: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_4067:
	/* 0x4067: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4069:
	/* 0x4069: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_406f:
	/* 0x406f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
	return 16498ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16498ULL: goto x86_l_4072;
	case 16504ULL: goto x86_l_4078;
	case 16510ULL: goto x86_l_407e;
	case 16515ULL: goto x86_l_4083;
	case 16519ULL: goto x86_l_4087;
	case 16526ULL: goto x86_l_408e;
	case 16531ULL: goto x86_l_4093;
	case 16536ULL: goto x86_l_4098;
	case 16541ULL: goto x86_l_409d;
	case 16549ULL: goto x86_l_40a5;
	case 16553ULL: goto x86_l_40a9;
	case 16560ULL: goto x86_l_40b0;
	case 16565ULL: goto x86_l_40b5;
	case 16567ULL: goto x86_l_40b7;
	case 16572ULL: goto x86_l_40bc;
	case 16580ULL: goto x86_l_40c4;
	case 16583ULL: goto x86_l_40c7;
	case 16591ULL: goto x86_l_40cf;
	case 16600ULL: goto x86_l_40d8;
	case 16604ULL: goto x86_l_40dc;
	case 16609ULL: goto x86_l_40e1;
	case 16614ULL: goto x86_l_40e6;
	case 16619ULL: goto x86_l_40eb;
	case 16624ULL: goto x86_l_40f0;
	case 16626ULL: goto x86_l_40f2;
	case 16631ULL: goto x86_l_40f7;
	case 16633ULL: goto x86_l_40f9;
	case 16636ULL: goto x86_l_40fc;
	case 16642ULL: goto x86_l_4102;
	case 16645ULL: goto x86_l_4105;
	case 16651ULL: goto x86_l_410b;
	case 16657ULL: goto x86_l_4111;
	case 16662ULL: goto x86_l_4116;
	case 16666ULL: goto x86_l_411a;
	case 16673ULL: goto x86_l_4121;
	case 16678ULL: goto x86_l_4126;
	case 16683ULL: goto x86_l_412b;
	case 16690ULL: goto x86_l_4132;
	case 16693ULL: goto x86_l_4135;
	case 16700ULL: goto x86_l_413c;
	case 16705ULL: goto x86_l_4141;
	case 16710ULL: goto x86_l_4146;
	case 16712ULL: goto x86_l_4148;
	case 16716ULL: goto x86_l_414c;
	case 16718ULL: goto x86_l_414e;
	case 16720ULL: goto x86_l_4150;
	case 16726ULL: goto x86_l_4156;
	case 16729ULL: goto x86_l_4159;
	case 16735ULL: goto x86_l_415f;
	case 16741ULL: goto x86_l_4165;
	case 16746ULL: goto x86_l_416a;
	case 16750ULL: goto x86_l_416e;
	case 16757ULL: goto x86_l_4175;
	case 16762ULL: goto x86_l_417a;
	case 16767ULL: goto x86_l_417f;
	case 16772ULL: goto x86_l_4184;
	case 16780ULL: goto x86_l_418c;
	case 16784ULL: goto x86_l_4190;
	case 16791ULL: goto x86_l_4197;
	case 16796ULL: goto x86_l_419c;
	case 16798ULL: goto x86_l_419e;
	case 16803ULL: goto x86_l_41a3;
	case 16811ULL: goto x86_l_41ab;
	case 16814ULL: goto x86_l_41ae;
	case 16822ULL: goto x86_l_41b6;
	case 16831ULL: goto x86_l_41bf;
	case 16835ULL: goto x86_l_41c3;
	case 16840ULL: goto x86_l_41c8;
	case 16845ULL: goto x86_l_41cd;
	case 16850ULL: goto x86_l_41d2;
	case 16855ULL: goto x86_l_41d7;
	case 16857ULL: goto x86_l_41d9;
	case 16862ULL: goto x86_l_41de;
	case 16864ULL: goto x86_l_41e0;
	case 16867ULL: goto x86_l_41e3;
	case 16873ULL: goto x86_l_41e9;
	case 16876ULL: goto x86_l_41ec;
	case 16882ULL: goto x86_l_41f2;
	case 16888ULL: goto x86_l_41f8;
	case 16893ULL: goto x86_l_41fd;
	case 16897ULL: goto x86_l_4201;
	case 16904ULL: goto x86_l_4208;
	case 16909ULL: goto x86_l_420d;
	case 16914ULL: goto x86_l_4212;
	case 16921ULL: goto x86_l_4219;
	case 16924ULL: goto x86_l_421c;
	case 16931ULL: goto x86_l_4223;
	case 16936ULL: goto x86_l_4228;
	case 16941ULL: goto x86_l_422d;
	case 16943ULL: goto x86_l_422f;
	case 16947ULL: goto x86_l_4233;
	case 16949ULL: goto x86_l_4235;
	case 16951ULL: goto x86_l_4237;
	case 16957ULL: goto x86_l_423d;
	case 16960ULL: goto x86_l_4240;
	case 16966ULL: goto x86_l_4246;
	case 16972ULL: goto x86_l_424c;
	case 16977ULL: goto x86_l_4251;
	case 16981ULL: goto x86_l_4255;
	case 16988ULL: goto x86_l_425c;
	case 16993ULL: goto x86_l_4261;
	case 16998ULL: goto x86_l_4266;
	case 17003ULL: goto x86_l_426b;
	case 17011ULL: goto x86_l_4273;
	case 17015ULL: goto x86_l_4277;
	case 17022ULL: goto x86_l_427e;
	case 17027ULL: goto x86_l_4283;
	case 17029ULL: goto x86_l_4285;
	case 17034ULL: goto x86_l_428a;
	case 17042ULL: goto x86_l_4292;
	case 17045ULL: goto x86_l_4295;
	case 17053ULL: goto x86_l_429d;
	case 17062ULL: goto x86_l_42a6;
	case 17069ULL: goto x86_l_42ad;
	case 17074ULL: goto x86_l_42b2;
	case 17079ULL: goto x86_l_42b7;
	case 17084ULL: goto x86_l_42bc;
	case 17089ULL: goto x86_l_42c1;
	case 17091ULL: goto x86_l_42c3;
	case 17096ULL: goto x86_l_42c8;
	case 17098ULL: goto x86_l_42ca;
	case 17101ULL: goto x86_l_42cd;
	case 17107ULL: goto x86_l_42d3;
	case 17110ULL: goto x86_l_42d6;
	case 17116ULL: goto x86_l_42dc;
	case 17122ULL: goto x86_l_42e2;
	case 17127ULL: goto x86_l_42e7;
	case 17131ULL: goto x86_l_42eb;
	case 17138ULL: goto x86_l_42f2;
	case 17143ULL: goto x86_l_42f7;
	case 17148ULL: goto x86_l_42fc;
	case 17155ULL: goto x86_l_4303;
	case 17158ULL: goto x86_l_4306;
	case 17165ULL: goto x86_l_430d;
	case 17170ULL: goto x86_l_4312;
	case 17175ULL: goto x86_l_4317;
	case 17177ULL: goto x86_l_4319;
	case 17181ULL: goto x86_l_431d;
	case 17183ULL: goto x86_l_431f;
	case 17185ULL: goto x86_l_4321;
	case 17191ULL: goto x86_l_4327;
	case 17194ULL: goto x86_l_432a;
	case 17200ULL: goto x86_l_4330;
	case 17206ULL: goto x86_l_4336;
	case 17211ULL: goto x86_l_433b;
	case 17215ULL: goto x86_l_433f;
	case 17222ULL: goto x86_l_4346;
	case 17227ULL: goto x86_l_434b;
	case 17232ULL: goto x86_l_4350;
	case 17237ULL: goto x86_l_4355;
	case 17245ULL: goto x86_l_435d;
	case 17249ULL: goto x86_l_4361;
	case 17256ULL: goto x86_l_4368;
	case 17261ULL: goto x86_l_436d;
	case 17263ULL: goto x86_l_436f;
	case 17268ULL: goto x86_l_4374;
	case 17276ULL: goto x86_l_437c;
	case 17279ULL: goto x86_l_437f;
	case 17287ULL: goto x86_l_4387;
	case 17296ULL: goto x86_l_4390;
	case 17303ULL: goto x86_l_4397;
	case 17308ULL: goto x86_l_439c;
	case 17313ULL: goto x86_l_43a1;
	case 17318ULL: goto x86_l_43a6;
	case 17323ULL: goto x86_l_43ab;
	case 17325ULL: goto x86_l_43ad;
	case 17330ULL: goto x86_l_43b2;
	case 17332ULL: goto x86_l_43b4;
	case 17335ULL: goto x86_l_43b7;
	case 17341ULL: goto x86_l_43bd;
	case 17344ULL: goto x86_l_43c0;
	case 17350ULL: goto x86_l_43c6;
	case 17356ULL: goto x86_l_43cc;
	case 17361ULL: goto x86_l_43d1;
	case 17365ULL: goto x86_l_43d5;
	case 17372ULL: goto x86_l_43dc;
	case 17377ULL: goto x86_l_43e1;
	case 17382ULL: goto x86_l_43e6;
	case 17389ULL: goto x86_l_43ed;
	case 17392ULL: goto x86_l_43f0;
	case 17399ULL: goto x86_l_43f7;
	case 17404ULL: goto x86_l_43fc;
	case 17409ULL: goto x86_l_4401;
	case 17411ULL: goto x86_l_4403;
	case 17415ULL: goto x86_l_4407;
	case 17417ULL: goto x86_l_4409;
	case 17419ULL: goto x86_l_440b;
	case 17425ULL: goto x86_l_4411;
	case 17428ULL: goto x86_l_4414;
	case 17434ULL: goto x86_l_441a;
	case 17440ULL: goto x86_l_4420;
	case 17445ULL: goto x86_l_4425;
	case 17449ULL: goto x86_l_4429;
	case 17456ULL: goto x86_l_4430;
	case 17461ULL: goto x86_l_4435;
	case 17466ULL: goto x86_l_443a;
	case 17471ULL: goto x86_l_443f;
	case 17479ULL: goto x86_l_4447;
	case 17483ULL: goto x86_l_444b;
	case 17490ULL: goto x86_l_4452;
	case 17495ULL: goto x86_l_4457;
	case 17497ULL: goto x86_l_4459;
	case 17502ULL: goto x86_l_445e;
	case 17510ULL: goto x86_l_4466;
	case 17513ULL: goto x86_l_4469;
	case 17521ULL: goto x86_l_4471;
	case 17530ULL: goto x86_l_447a;
	case 17537ULL: goto x86_l_4481;
	case 17542ULL: goto x86_l_4486;
	case 17547ULL: goto x86_l_448b;
	case 17552ULL: goto x86_l_4490;
	case 17557ULL: goto x86_l_4495;
	case 17559ULL: goto x86_l_4497;
	case 17564ULL: goto x86_l_449c;
	case 17566ULL: goto x86_l_449e;
	case 17569ULL: goto x86_l_44a1;
	case 17575ULL: goto x86_l_44a7;
	case 17578ULL: goto x86_l_44aa;
	case 17584ULL: goto x86_l_44b0;
	case 17590ULL: goto x86_l_44b6;
	case 17595ULL: goto x86_l_44bb;
	case 17599ULL: goto x86_l_44bf;
	case 17606ULL: goto x86_l_44c6;
	case 17611ULL: goto x86_l_44cb;
	case 17616ULL: goto x86_l_44d0;
	case 17623ULL: goto x86_l_44d7;
	case 17626ULL: goto x86_l_44da;
	case 17633ULL: goto x86_l_44e1;
	case 17638ULL: goto x86_l_44e6;
	case 17643ULL: goto x86_l_44eb;
	case 17645ULL: goto x86_l_44ed;
	case 17649ULL: goto x86_l_44f1;
	case 17651ULL: goto x86_l_44f3;
	case 17653ULL: goto x86_l_44f5;
	case 17659ULL: goto x86_l_44fb;
	case 17662ULL: goto x86_l_44fe;
	case 17668ULL: goto x86_l_4504;
	case 17674ULL: goto x86_l_450a;
	case 17679ULL: goto x86_l_450f;
	case 17683ULL: goto x86_l_4513;
	case 17690ULL: goto x86_l_451a;
	case 17695ULL: goto x86_l_451f;
	case 17700ULL: goto x86_l_4524;
	case 17705ULL: goto x86_l_4529;
	case 17713ULL: goto x86_l_4531;
	case 17717ULL: goto x86_l_4535;
	case 17724ULL: goto x86_l_453c;
	case 17729ULL: goto x86_l_4541;
	case 17731ULL: goto x86_l_4543;
	case 17736ULL: goto x86_l_4548;
	case 17744ULL: goto x86_l_4550;
	case 17747ULL: goto x86_l_4553;
	case 17755ULL: goto x86_l_455b;
	case 17764ULL: goto x86_l_4564;
	case 17771ULL: goto x86_l_456b;
	case 17776ULL: goto x86_l_4570;
	case 17781ULL: goto x86_l_4575;
	case 17786ULL: goto x86_l_457a;
	case 17791ULL: goto x86_l_457f;
	case 17793ULL: goto x86_l_4581;
	case 17798ULL: goto x86_l_4586;
	case 17800ULL: goto x86_l_4588;
	case 17803ULL: goto x86_l_458b;
	case 17809ULL: goto x86_l_4591;
	case 17812ULL: goto x86_l_4594;
	case 17818ULL: goto x86_l_459a;
	case 17824ULL: goto x86_l_45a0;
	case 17829ULL: goto x86_l_45a5;
	case 17833ULL: goto x86_l_45a9;
	case 17840ULL: goto x86_l_45b0;
	case 17845ULL: goto x86_l_45b5;
	case 17850ULL: goto x86_l_45ba;
	case 17857ULL: goto x86_l_45c1;
	case 17860ULL: goto x86_l_45c4;
	case 17867ULL: goto x86_l_45cb;
	case 17872ULL: goto x86_l_45d0;
	case 17877ULL: goto x86_l_45d5;
	case 17879ULL: goto x86_l_45d7;
	case 17883ULL: goto x86_l_45db;
	case 17885ULL: goto x86_l_45dd;
	case 17887ULL: goto x86_l_45df;
	case 17893ULL: goto x86_l_45e5;
	case 17896ULL: goto x86_l_45e8;
	case 17902ULL: goto x86_l_45ee;
	case 17908ULL: goto x86_l_45f4;
	case 17913ULL: goto x86_l_45f9;
	case 17917ULL: goto x86_l_45fd;
	case 17924ULL: goto x86_l_4604;
	case 17929ULL: goto x86_l_4609;
	case 17934ULL: goto x86_l_460e;
	case 17939ULL: goto x86_l_4613;
	case 17947ULL: goto x86_l_461b;
	case 17951ULL: goto x86_l_461f;
	case 17958ULL: goto x86_l_4626;
	case 17963ULL: goto x86_l_462b;
	case 17965ULL: goto x86_l_462d;
	case 17970ULL: goto x86_l_4632;
	case 17978ULL: goto x86_l_463a;
	case 17981ULL: goto x86_l_463d;
	case 17989ULL: goto x86_l_4645;
	case 17998ULL: goto x86_l_464e;
	case 18005ULL: goto x86_l_4655;
	case 18010ULL: goto x86_l_465a;
	case 18015ULL: goto x86_l_465f;
	case 18020ULL: goto x86_l_4664;
	case 18025ULL: goto x86_l_4669;
	case 18027ULL: goto x86_l_466b;
	case 18032ULL: goto x86_l_4670;
	case 18034ULL: goto x86_l_4672;
	case 18037ULL: goto x86_l_4675;
	case 18043ULL: goto x86_l_467b;
	case 18046ULL: goto x86_l_467e;
	case 18052ULL: goto x86_l_4684;
	case 18058ULL: goto x86_l_468a;
	case 18063ULL: goto x86_l_468f;
	case 18067ULL: goto x86_l_4693;
	case 18074ULL: goto x86_l_469a;
	case 18079ULL: goto x86_l_469f;
	case 18084ULL: goto x86_l_46a4;
	case 18091ULL: goto x86_l_46ab;
	case 18094ULL: goto x86_l_46ae;
	case 18101ULL: goto x86_l_46b5;
	case 18106ULL: goto x86_l_46ba;
	case 18111ULL: goto x86_l_46bf;
	case 18113ULL: goto x86_l_46c1;
	case 18117ULL: goto x86_l_46c5;
	case 18119ULL: goto x86_l_46c7;
	case 18121ULL: goto x86_l_46c9;
	case 18127ULL: goto x86_l_46cf;
	case 18130ULL: goto x86_l_46d2;
	case 18136ULL: goto x86_l_46d8;
	case 18142ULL: goto x86_l_46de;
	case 18147ULL: goto x86_l_46e3;
	case 18151ULL: goto x86_l_46e7;
	case 18158ULL: goto x86_l_46ee;
	case 18163ULL: goto x86_l_46f3;
	case 18168ULL: goto x86_l_46f8;
	case 18173ULL: goto x86_l_46fd;
	case 18181ULL: goto x86_l_4705;
	case 18185ULL: goto x86_l_4709;
	case 18192ULL: goto x86_l_4710;
	case 18197ULL: goto x86_l_4715;
	case 18199ULL: goto x86_l_4717;
	case 18204ULL: goto x86_l_471c;
	case 18212ULL: goto x86_l_4724;
	case 18215ULL: goto x86_l_4727;
	case 18223ULL: goto x86_l_472f;
	case 18232ULL: goto x86_l_4738;
	case 18239ULL: goto x86_l_473f;
	case 18244ULL: goto x86_l_4744;
	case 18249ULL: goto x86_l_4749;
	case 18254ULL: goto x86_l_474e;
	case 18259ULL: goto x86_l_4753;
	case 18261ULL: goto x86_l_4755;
	case 18266ULL: goto x86_l_475a;
	case 18268ULL: goto x86_l_475c;
	case 18271ULL: goto x86_l_475f;
	case 18277ULL: goto x86_l_4765;
	case 18280ULL: goto x86_l_4768;
	case 18286ULL: goto x86_l_476e;
	case 18292ULL: goto x86_l_4774;
	case 18297ULL: goto x86_l_4779;
	case 18301ULL: goto x86_l_477d;
	case 18308ULL: goto x86_l_4784;
	case 18313ULL: goto x86_l_4789;
	case 18318ULL: goto x86_l_478e;
	case 18325ULL: goto x86_l_4795;
	case 18328ULL: goto x86_l_4798;
	case 18335ULL: goto x86_l_479f;
	case 18340ULL: goto x86_l_47a4;
	case 18345ULL: goto x86_l_47a9;
	case 18347ULL: goto x86_l_47ab;
	case 18351ULL: goto x86_l_47af;
	case 18353ULL: goto x86_l_47b1;
	case 18355ULL: goto x86_l_47b3;
	case 18361ULL: goto x86_l_47b9;
	case 18364ULL: goto x86_l_47bc;
	case 18370ULL: goto x86_l_47c2;
	case 18376ULL: goto x86_l_47c8;
	case 18381ULL: goto x86_l_47cd;
	case 18385ULL: goto x86_l_47d1;
	case 18392ULL: goto x86_l_47d8;
	case 18397ULL: goto x86_l_47dd;
	case 18402ULL: goto x86_l_47e2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4072:
	/* 0x4072: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4078:
	/* 0x4078: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_407e:
	/* 0x407e: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4083:
	/* 0x4083: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4087:
	/* 0x4087: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_408e:
	/* 0x408e: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4093:
	/* 0x4093: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4098:
	/* 0x4098: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_409d:
	/* 0x409d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_40a5:
	/* 0x40a5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_40a9:
	/* 0x40a9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_40b0:
	/* 0x40b0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_40b5:
	/* 0x40b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40b7:
	/* 0x40b7: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_40bc:
	/* 0x40bc: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_40c4:
	/* 0x40c4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_40c7:
	/* 0x40c7: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_40cf:
	/* 0x40cf: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_40d8:
	/* 0x40d8: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_40dc:
	/* 0x40dc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40e1:
	/* 0x40e1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_40e6:
	/* 0x40e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_40eb:
	/* 0x40eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40f0:
	/* 0x40f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40f2:
	/* 0x40f2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40f7:
	/* 0x40f7: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_40f9:
	/* 0x40f9: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_40fc:
	/* 0x40fc: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_4102:
	/* 0x4102: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4105:
	/* 0x4105: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_410b:
	/* 0x410b: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4111:
	/* 0x4111: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4116:
	/* 0x4116: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_411a:
	/* 0x411a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4121:
	/* 0x4121: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4126:
	/* 0x4126: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_412b:
	/* 0x412b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4132:
	/* 0x4132: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4135:
	/* 0x4135: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_413c:
	/* 0x413c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4141:
	/* 0x4141: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4146:
	/* 0x4146: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4148:
	/* 0x4148: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_414c:
	/* 0x414c: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_414e:
	/* 0x414e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4150:
	/* 0x4150: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_4156:
	/* 0x4156: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4159:
	/* 0x4159: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_415f:
	/* 0x415f: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4165:
	/* 0x4165: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_416a:
	/* 0x416a: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_416e:
	/* 0x416e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4175:
	/* 0x4175: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_417a:
	/* 0x417a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_417f:
	/* 0x417f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4184:
	/* 0x4184: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_418c:
	/* 0x418c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4190:
	/* 0x4190: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4197:
	/* 0x4197: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_419c:
	/* 0x419c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_419e:
	/* 0x419e: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_41a3:
	/* 0x41a3: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_41ab:
	/* 0x41ab: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_41ae:
	/* 0x41ae: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_41b6:
	/* 0x41b6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_41bf:
	/* 0x41bf: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_41c3:
	/* 0x41c3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41c8:
	/* 0x41c8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_41cd:
	/* 0x41cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41d2:
	/* 0x41d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41d7:
	/* 0x41d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41d9:
	/* 0x41d9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41de:
	/* 0x41de: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_41e0:
	/* 0x41e0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_41e3:
	/* 0x41e3: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_41e9:
	/* 0x41e9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41ec:
	/* 0x41ec: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_41f2:
	/* 0x41f2: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_41f8:
	/* 0x41f8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41fd:
	/* 0x41fd: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4201:
	/* 0x4201: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4208:
	/* 0x4208: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_420d:
	/* 0x420d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4212:
	/* 0x4212: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4219:
	/* 0x4219: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_421c:
	/* 0x421c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4223:
	/* 0x4223: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4228:
	/* 0x4228: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_422d:
	/* 0x422d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_422f:
	/* 0x422f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4233:
	/* 0x4233: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_4235:
	/* 0x4235: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4237:
	/* 0x4237: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_423d:
	/* 0x423d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4240:
	/* 0x4240: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4246:
	/* 0x4246: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_424c:
	/* 0x424c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4251:
	/* 0x4251: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4255:
	/* 0x4255: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_425c:
	/* 0x425c: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4261:
	/* 0x4261: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4266:
	/* 0x4266: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_426b:
	/* 0x426b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4273:
	/* 0x4273: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4277:
	/* 0x4277: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_427e:
	/* 0x427e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4283:
	/* 0x4283: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4285:
	/* 0x4285: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_428a:
	/* 0x428a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4292:
	/* 0x4292: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4295:
	/* 0x4295: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_429d:
	/* 0x429d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_42a6:
	/* 0x42a6: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_42ad:
	/* 0x42ad: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42b2:
	/* 0x42b2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_42b7:
	/* 0x42b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_42bc:
	/* 0x42bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42c1:
	/* 0x42c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42c3:
	/* 0x42c3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42c8:
	/* 0x42c8: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_42ca:
	/* 0x42ca: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_42cd:
	/* 0x42cd: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_42d3:
	/* 0x42d3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_42d6:
	/* 0x42d6: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_42dc:
	/* 0x42dc: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_42e2:
	/* 0x42e2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42e7:
	/* 0x42e7: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_42eb:
	/* 0x42eb: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_42f2:
	/* 0x42f2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_42f7:
	/* 0x42f7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_42fc:
	/* 0x42fc: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4303:
	/* 0x4303: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4306:
	/* 0x4306: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_430d:
	/* 0x430d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4312:
	/* 0x4312: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4317:
	/* 0x4317: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4319:
	/* 0x4319: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_431d:
	/* 0x431d: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_431f:
	/* 0x431f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4321:
	/* 0x4321: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_4327:
	/* 0x4327: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_432a:
	/* 0x432a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4330:
	/* 0x4330: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4336:
	/* 0x4336: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_433b:
	/* 0x433b: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_433f:
	/* 0x433f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4346:
	/* 0x4346: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_434b:
	/* 0x434b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4350:
	/* 0x4350: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4355:
	/* 0x4355: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_435d:
	/* 0x435d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4361:
	/* 0x4361: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4368:
	/* 0x4368: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_436d:
	/* 0x436d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_436f:
	/* 0x436f: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4374:
	/* 0x4374: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_437c:
	/* 0x437c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_437f:
	/* 0x437f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4387:
	/* 0x4387: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4390:
	/* 0x4390: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4397:
	/* 0x4397: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_439c:
	/* 0x439c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_43a1:
	/* 0x43a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_43a6:
	/* 0x43a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43ab:
	/* 0x43ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43ad:
	/* 0x43ad: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43b2:
	/* 0x43b2: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_43b4:
	/* 0x43b4: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_43b7:
	/* 0x43b7: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_43bd:
	/* 0x43bd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_43c0:
	/* 0x43c0: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_43c6:
	/* 0x43c6: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_43cc:
	/* 0x43cc: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43d1:
	/* 0x43d1: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_43d5:
	/* 0x43d5: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_43dc:
	/* 0x43dc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_43e1:
	/* 0x43e1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_43e6:
	/* 0x43e6: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_43ed:
	/* 0x43ed: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_43f0:
	/* 0x43f0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_43f7:
	/* 0x43f7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43fc:
	/* 0x43fc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4401:
	/* 0x4401: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4403:
	/* 0x4403: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4407:
	/* 0x4407: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_4409:
	/* 0x4409: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_440b:
	/* 0x440b: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_4411:
	/* 0x4411: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4414:
	/* 0x4414: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_441a:
	/* 0x441a: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4420:
	/* 0x4420: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4425:
	/* 0x4425: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4429:
	/* 0x4429: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4430:
	/* 0x4430: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4435:
	/* 0x4435: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_443a:
	/* 0x443a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_443f:
	/* 0x443f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4447:
	/* 0x4447: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_444b:
	/* 0x444b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4452:
	/* 0x4452: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4457:
	/* 0x4457: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4459:
	/* 0x4459: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_445e:
	/* 0x445e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4466:
	/* 0x4466: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4469:
	/* 0x4469: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4471:
	/* 0x4471: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_447a:
	/* 0x447a: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4481:
	/* 0x4481: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4486:
	/* 0x4486: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_448b:
	/* 0x448b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4490:
	/* 0x4490: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4495:
	/* 0x4495: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4497:
	/* 0x4497: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_449c:
	/* 0x449c: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_449e:
	/* 0x449e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_44a1:
	/* 0x44a1: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_44a7:
	/* 0x44a7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_44aa:
	/* 0x44aa: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_44b0:
	/* 0x44b0: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_44b6:
	/* 0x44b6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44bb:
	/* 0x44bb: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_44bf:
	/* 0x44bf: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_44c6:
	/* 0x44c6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_44cb:
	/* 0x44cb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_44d0:
	/* 0x44d0: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_44d7:
	/* 0x44d7: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_44da:
	/* 0x44da: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_44e1:
	/* 0x44e1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44e6:
	/* 0x44e6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_44eb:
	/* 0x44eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44ed:
	/* 0x44ed: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_44f1:
	/* 0x44f1: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_44f3:
	/* 0x44f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44f5:
	/* 0x44f5: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_44fb:
	/* 0x44fb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_44fe:
	/* 0x44fe: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4504:
	/* 0x4504: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_450a:
	/* 0x450a: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_450f:
	/* 0x450f: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4513:
	/* 0x4513: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_451a:
	/* 0x451a: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_451f:
	/* 0x451f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4524:
	/* 0x4524: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4529:
	/* 0x4529: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4531:
	/* 0x4531: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4535:
	/* 0x4535: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_453c:
	/* 0x453c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4541:
	/* 0x4541: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4543:
	/* 0x4543: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4548:
	/* 0x4548: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4550:
	/* 0x4550: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4553:
	/* 0x4553: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_455b:
	/* 0x455b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4564:
	/* 0x4564: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_456b:
	/* 0x456b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4570:
	/* 0x4570: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4575:
	/* 0x4575: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_457a:
	/* 0x457a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_457f:
	/* 0x457f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4581:
	/* 0x4581: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4586:
	/* 0x4586: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_4588:
	/* 0x4588: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_458b:
	/* 0x458b: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_4591:
	/* 0x4591: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4594:
	/* 0x4594: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_459a:
	/* 0x459a: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_45a0:
	/* 0x45a0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45a5:
	/* 0x45a5: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_45a9:
	/* 0x45a9: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_45b0:
	/* 0x45b0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_45b5:
	/* 0x45b5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_45ba:
	/* 0x45ba: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_45c1:
	/* 0x45c1: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_45c4:
	/* 0x45c4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_45cb:
	/* 0x45cb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45d0:
	/* 0x45d0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_45d5:
	/* 0x45d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45d7:
	/* 0x45d7: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_45db:
	/* 0x45db: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_45dd:
	/* 0x45dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45df:
	/* 0x45df: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_45e5:
	/* 0x45e5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_45e8:
	/* 0x45e8: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_45ee:
	/* 0x45ee: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_45f4:
	/* 0x45f4: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45f9:
	/* 0x45f9: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_45fd:
	/* 0x45fd: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4604:
	/* 0x4604: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4609:
	/* 0x4609: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_460e:
	/* 0x460e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4613:
	/* 0x4613: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_461b:
	/* 0x461b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_461f:
	/* 0x461f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4626:
	/* 0x4626: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_462b:
	/* 0x462b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_462d:
	/* 0x462d: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4632:
	/* 0x4632: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_463a:
	/* 0x463a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_463d:
	/* 0x463d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4645:
	/* 0x4645: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_464e:
	/* 0x464e: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4655:
	/* 0x4655: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_465a:
	/* 0x465a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_465f:
	/* 0x465f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4664:
	/* 0x4664: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4669:
	/* 0x4669: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_466b:
	/* 0x466b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4670:
	/* 0x4670: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_4672:
	/* 0x4672: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4675:
	/* 0x4675: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_467b:
	/* 0x467b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_467e:
	/* 0x467e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4684:
	/* 0x4684: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_468a:
	/* 0x468a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_468f:
	/* 0x468f: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4693:
	/* 0x4693: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_469a:
	/* 0x469a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_469f:
	/* 0x469f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_46a4:
	/* 0x46a4: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_46ab:
	/* 0x46ab: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_46ae:
	/* 0x46ae: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_46b5:
	/* 0x46b5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46ba:
	/* 0x46ba: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_46bf:
	/* 0x46bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46c1:
	/* 0x46c1: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_46c5:
	/* 0x46c5: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_46c7:
	/* 0x46c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46c9:
	/* 0x46c9: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_46cf:
	/* 0x46cf: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_46d2:
	/* 0x46d2: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_46d8:
	/* 0x46d8: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_46de:
	/* 0x46de: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46e3:
	/* 0x46e3: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_46e7:
	/* 0x46e7: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_46ee:
	/* 0x46ee: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_46f3:
	/* 0x46f3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_46f8:
	/* 0x46f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_46fd:
	/* 0x46fd: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4705:
	/* 0x4705: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4709:
	/* 0x4709: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4710:
	/* 0x4710: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4715:
	/* 0x4715: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4717:
	/* 0x4717: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_471c:
	/* 0x471c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4724:
	/* 0x4724: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4727:
	/* 0x4727: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_472f:
	/* 0x472f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4738:
	/* 0x4738: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_473f:
	/* 0x473f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4744:
	/* 0x4744: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4749:
	/* 0x4749: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_474e:
	/* 0x474e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4753:
	/* 0x4753: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4755:
	/* 0x4755: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_475a:
	/* 0x475a: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_475c:
	/* 0x475c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_475f:
	/* 0x475f: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_4765:
	/* 0x4765: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4768:
	/* 0x4768: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_476e:
	/* 0x476e: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4774:
	/* 0x4774: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4779:
	/* 0x4779: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_477d:
	/* 0x477d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4784:
	/* 0x4784: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4789:
	/* 0x4789: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_478e:
	/* 0x478e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4795:
	/* 0x4795: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4798:
	/* 0x4798: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_479f:
	/* 0x479f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47a4:
	/* 0x47a4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_47a9:
	/* 0x47a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47ab:
	/* 0x47ab: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_47af:
	/* 0x47af: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_47b1:
	/* 0x47b1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47b3:
	/* 0x47b3: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_47b9:
	/* 0x47b9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_47bc:
	/* 0x47bc: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_47c2:
	/* 0x47c2: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_47c8:
	/* 0x47c8: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47cd:
	/* 0x47cd: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_47d1:
	/* 0x47d1: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_47d8:
	/* 0x47d8: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_47dd:
	/* 0x47dd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_47e2:
	/* 0x47e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 18407ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18407ULL: goto x86_l_47e7;
	case 18415ULL: goto x86_l_47ef;
	case 18419ULL: goto x86_l_47f3;
	case 18426ULL: goto x86_l_47fa;
	case 18431ULL: goto x86_l_47ff;
	case 18433ULL: goto x86_l_4801;
	case 18438ULL: goto x86_l_4806;
	case 18446ULL: goto x86_l_480e;
	case 18449ULL: goto x86_l_4811;
	case 18457ULL: goto x86_l_4819;
	case 18466ULL: goto x86_l_4822;
	case 18473ULL: goto x86_l_4829;
	case 18478ULL: goto x86_l_482e;
	case 18483ULL: goto x86_l_4833;
	case 18488ULL: goto x86_l_4838;
	case 18493ULL: goto x86_l_483d;
	case 18495ULL: goto x86_l_483f;
	case 18500ULL: goto x86_l_4844;
	case 18502ULL: goto x86_l_4846;
	case 18505ULL: goto x86_l_4849;
	case 18511ULL: goto x86_l_484f;
	case 18514ULL: goto x86_l_4852;
	case 18520ULL: goto x86_l_4858;
	case 18526ULL: goto x86_l_485e;
	case 18531ULL: goto x86_l_4863;
	case 18535ULL: goto x86_l_4867;
	case 18542ULL: goto x86_l_486e;
	case 18547ULL: goto x86_l_4873;
	case 18552ULL: goto x86_l_4878;
	case 18559ULL: goto x86_l_487f;
	case 18562ULL: goto x86_l_4882;
	case 18569ULL: goto x86_l_4889;
	case 18574ULL: goto x86_l_488e;
	case 18579ULL: goto x86_l_4893;
	case 18581ULL: goto x86_l_4895;
	case 18585ULL: goto x86_l_4899;
	case 18587ULL: goto x86_l_489b;
	case 18589ULL: goto x86_l_489d;
	case 18595ULL: goto x86_l_48a3;
	case 18598ULL: goto x86_l_48a6;
	case 18604ULL: goto x86_l_48ac;
	case 18610ULL: goto x86_l_48b2;
	case 18615ULL: goto x86_l_48b7;
	case 18619ULL: goto x86_l_48bb;
	case 18626ULL: goto x86_l_48c2;
	case 18631ULL: goto x86_l_48c7;
	case 18636ULL: goto x86_l_48cc;
	case 18641ULL: goto x86_l_48d1;
	case 18649ULL: goto x86_l_48d9;
	case 18653ULL: goto x86_l_48dd;
	case 18660ULL: goto x86_l_48e4;
	case 18665ULL: goto x86_l_48e9;
	case 18667ULL: goto x86_l_48eb;
	case 18672ULL: goto x86_l_48f0;
	case 18680ULL: goto x86_l_48f8;
	case 18683ULL: goto x86_l_48fb;
	case 18691ULL: goto x86_l_4903;
	case 18700ULL: goto x86_l_490c;
	case 18707ULL: goto x86_l_4913;
	case 18712ULL: goto x86_l_4918;
	case 18717ULL: goto x86_l_491d;
	case 18722ULL: goto x86_l_4922;
	case 18727ULL: goto x86_l_4927;
	case 18729ULL: goto x86_l_4929;
	case 18734ULL: goto x86_l_492e;
	case 18736ULL: goto x86_l_4930;
	case 18739ULL: goto x86_l_4933;
	case 18745ULL: goto x86_l_4939;
	case 18748ULL: goto x86_l_493c;
	case 18754ULL: goto x86_l_4942;
	case 18760ULL: goto x86_l_4948;
	case 18765ULL: goto x86_l_494d;
	case 18769ULL: goto x86_l_4951;
	case 18776ULL: goto x86_l_4958;
	case 18781ULL: goto x86_l_495d;
	case 18786ULL: goto x86_l_4962;
	case 18793ULL: goto x86_l_4969;
	case 18796ULL: goto x86_l_496c;
	case 18803ULL: goto x86_l_4973;
	case 18808ULL: goto x86_l_4978;
	case 18813ULL: goto x86_l_497d;
	case 18815ULL: goto x86_l_497f;
	case 18819ULL: goto x86_l_4983;
	case 18821ULL: goto x86_l_4985;
	case 18823ULL: goto x86_l_4987;
	case 18829ULL: goto x86_l_498d;
	case 18832ULL: goto x86_l_4990;
	case 18838ULL: goto x86_l_4996;
	case 18844ULL: goto x86_l_499c;
	case 18849ULL: goto x86_l_49a1;
	case 18853ULL: goto x86_l_49a5;
	case 18860ULL: goto x86_l_49ac;
	case 18865ULL: goto x86_l_49b1;
	case 18870ULL: goto x86_l_49b6;
	case 18875ULL: goto x86_l_49bb;
	case 18883ULL: goto x86_l_49c3;
	case 18887ULL: goto x86_l_49c7;
	case 18894ULL: goto x86_l_49ce;
	case 18899ULL: goto x86_l_49d3;
	case 18901ULL: goto x86_l_49d5;
	case 18906ULL: goto x86_l_49da;
	case 18914ULL: goto x86_l_49e2;
	case 18917ULL: goto x86_l_49e5;
	case 18925ULL: goto x86_l_49ed;
	case 18934ULL: goto x86_l_49f6;
	case 18941ULL: goto x86_l_49fd;
	case 18946ULL: goto x86_l_4a02;
	case 18951ULL: goto x86_l_4a07;
	case 18956ULL: goto x86_l_4a0c;
	case 18961ULL: goto x86_l_4a11;
	case 18963ULL: goto x86_l_4a13;
	case 18968ULL: goto x86_l_4a18;
	case 18970ULL: goto x86_l_4a1a;
	case 18973ULL: goto x86_l_4a1d;
	case 18979ULL: goto x86_l_4a23;
	case 18982ULL: goto x86_l_4a26;
	case 18988ULL: goto x86_l_4a2c;
	case 18994ULL: goto x86_l_4a32;
	case 18999ULL: goto x86_l_4a37;
	case 19003ULL: goto x86_l_4a3b;
	case 19010ULL: goto x86_l_4a42;
	case 19015ULL: goto x86_l_4a47;
	case 19020ULL: goto x86_l_4a4c;
	case 19027ULL: goto x86_l_4a53;
	case 19030ULL: goto x86_l_4a56;
	case 19037ULL: goto x86_l_4a5d;
	case 19042ULL: goto x86_l_4a62;
	case 19047ULL: goto x86_l_4a67;
	case 19049ULL: goto x86_l_4a69;
	case 19053ULL: goto x86_l_4a6d;
	case 19055ULL: goto x86_l_4a6f;
	case 19057ULL: goto x86_l_4a71;
	case 19063ULL: goto x86_l_4a77;
	case 19066ULL: goto x86_l_4a7a;
	case 19072ULL: goto x86_l_4a80;
	case 19078ULL: goto x86_l_4a86;
	case 19083ULL: goto x86_l_4a8b;
	case 19087ULL: goto x86_l_4a8f;
	case 19094ULL: goto x86_l_4a96;
	case 19099ULL: goto x86_l_4a9b;
	case 19104ULL: goto x86_l_4aa0;
	case 19109ULL: goto x86_l_4aa5;
	case 19117ULL: goto x86_l_4aad;
	case 19121ULL: goto x86_l_4ab1;
	case 19128ULL: goto x86_l_4ab8;
	case 19133ULL: goto x86_l_4abd;
	case 19135ULL: goto x86_l_4abf;
	case 19140ULL: goto x86_l_4ac4;
	case 19148ULL: goto x86_l_4acc;
	case 19151ULL: goto x86_l_4acf;
	case 19159ULL: goto x86_l_4ad7;
	case 19168ULL: goto x86_l_4ae0;
	case 19175ULL: goto x86_l_4ae7;
	case 19180ULL: goto x86_l_4aec;
	case 19185ULL: goto x86_l_4af1;
	case 19190ULL: goto x86_l_4af6;
	case 19195ULL: goto x86_l_4afb;
	case 19197ULL: goto x86_l_4afd;
	case 19202ULL: goto x86_l_4b02;
	case 19204ULL: goto x86_l_4b04;
	case 19207ULL: goto x86_l_4b07;
	case 19213ULL: goto x86_l_4b0d;
	case 19216ULL: goto x86_l_4b10;
	case 19222ULL: goto x86_l_4b16;
	case 19228ULL: goto x86_l_4b1c;
	case 19233ULL: goto x86_l_4b21;
	case 19237ULL: goto x86_l_4b25;
	case 19244ULL: goto x86_l_4b2c;
	case 19249ULL: goto x86_l_4b31;
	case 19254ULL: goto x86_l_4b36;
	case 19261ULL: goto x86_l_4b3d;
	case 19264ULL: goto x86_l_4b40;
	case 19271ULL: goto x86_l_4b47;
	case 19276ULL: goto x86_l_4b4c;
	case 19281ULL: goto x86_l_4b51;
	case 19283ULL: goto x86_l_4b53;
	case 19287ULL: goto x86_l_4b57;
	case 19289ULL: goto x86_l_4b59;
	case 19291ULL: goto x86_l_4b5b;
	case 19297ULL: goto x86_l_4b61;
	case 19300ULL: goto x86_l_4b64;
	case 19306ULL: goto x86_l_4b6a;
	case 19312ULL: goto x86_l_4b70;
	case 19317ULL: goto x86_l_4b75;
	case 19321ULL: goto x86_l_4b79;
	case 19328ULL: goto x86_l_4b80;
	case 19333ULL: goto x86_l_4b85;
	case 19338ULL: goto x86_l_4b8a;
	case 19343ULL: goto x86_l_4b8f;
	case 19351ULL: goto x86_l_4b97;
	case 19355ULL: goto x86_l_4b9b;
	case 19362ULL: goto x86_l_4ba2;
	case 19367ULL: goto x86_l_4ba7;
	case 19369ULL: goto x86_l_4ba9;
	case 19374ULL: goto x86_l_4bae;
	case 19382ULL: goto x86_l_4bb6;
	case 19385ULL: goto x86_l_4bb9;
	case 19393ULL: goto x86_l_4bc1;
	case 19402ULL: goto x86_l_4bca;
	case 19409ULL: goto x86_l_4bd1;
	case 19414ULL: goto x86_l_4bd6;
	case 19419ULL: goto x86_l_4bdb;
	case 19424ULL: goto x86_l_4be0;
	case 19429ULL: goto x86_l_4be5;
	case 19431ULL: goto x86_l_4be7;
	case 19436ULL: goto x86_l_4bec;
	case 19438ULL: goto x86_l_4bee;
	case 19441ULL: goto x86_l_4bf1;
	case 19447ULL: goto x86_l_4bf7;
	case 19450ULL: goto x86_l_4bfa;
	case 19456ULL: goto x86_l_4c00;
	case 19462ULL: goto x86_l_4c06;
	case 19467ULL: goto x86_l_4c0b;
	case 19471ULL: goto x86_l_4c0f;
	case 19478ULL: goto x86_l_4c16;
	case 19483ULL: goto x86_l_4c1b;
	case 19488ULL: goto x86_l_4c20;
	case 19495ULL: goto x86_l_4c27;
	case 19498ULL: goto x86_l_4c2a;
	case 19505ULL: goto x86_l_4c31;
	case 19510ULL: goto x86_l_4c36;
	case 19515ULL: goto x86_l_4c3b;
	case 19517ULL: goto x86_l_4c3d;
	case 19521ULL: goto x86_l_4c41;
	case 19523ULL: goto x86_l_4c43;
	case 19525ULL: goto x86_l_4c45;
	case 19531ULL: goto x86_l_4c4b;
	case 19534ULL: goto x86_l_4c4e;
	case 19540ULL: goto x86_l_4c54;
	case 19546ULL: goto x86_l_4c5a;
	case 19551ULL: goto x86_l_4c5f;
	case 19555ULL: goto x86_l_4c63;
	case 19562ULL: goto x86_l_4c6a;
	case 19567ULL: goto x86_l_4c6f;
	case 19572ULL: goto x86_l_4c74;
	case 19577ULL: goto x86_l_4c79;
	case 19585ULL: goto x86_l_4c81;
	case 19589ULL: goto x86_l_4c85;
	case 19596ULL: goto x86_l_4c8c;
	case 19601ULL: goto x86_l_4c91;
	case 19603ULL: goto x86_l_4c93;
	case 19608ULL: goto x86_l_4c98;
	case 19616ULL: goto x86_l_4ca0;
	case 19619ULL: goto x86_l_4ca3;
	case 19627ULL: goto x86_l_4cab;
	case 19636ULL: goto x86_l_4cb4;
	case 19643ULL: goto x86_l_4cbb;
	case 19648ULL: goto x86_l_4cc0;
	case 19653ULL: goto x86_l_4cc5;
	case 19658ULL: goto x86_l_4cca;
	case 19663ULL: goto x86_l_4ccf;
	case 19665ULL: goto x86_l_4cd1;
	case 19670ULL: goto x86_l_4cd6;
	case 19672ULL: goto x86_l_4cd8;
	case 19675ULL: goto x86_l_4cdb;
	case 19681ULL: goto x86_l_4ce1;
	case 19684ULL: goto x86_l_4ce4;
	case 19690ULL: goto x86_l_4cea;
	case 19696ULL: goto x86_l_4cf0;
	case 19701ULL: goto x86_l_4cf5;
	case 19705ULL: goto x86_l_4cf9;
	case 19712ULL: goto x86_l_4d00;
	case 19717ULL: goto x86_l_4d05;
	case 19722ULL: goto x86_l_4d0a;
	case 19729ULL: goto x86_l_4d11;
	case 19732ULL: goto x86_l_4d14;
	case 19739ULL: goto x86_l_4d1b;
	case 19744ULL: goto x86_l_4d20;
	case 19749ULL: goto x86_l_4d25;
	case 19751ULL: goto x86_l_4d27;
	case 19755ULL: goto x86_l_4d2b;
	case 19757ULL: goto x86_l_4d2d;
	case 19759ULL: goto x86_l_4d2f;
	case 19765ULL: goto x86_l_4d35;
	case 19768ULL: goto x86_l_4d38;
	case 19774ULL: goto x86_l_4d3e;
	case 19780ULL: goto x86_l_4d44;
	case 19785ULL: goto x86_l_4d49;
	case 19789ULL: goto x86_l_4d4d;
	case 19796ULL: goto x86_l_4d54;
	case 19801ULL: goto x86_l_4d59;
	case 19806ULL: goto x86_l_4d5e;
	case 19811ULL: goto x86_l_4d63;
	case 19819ULL: goto x86_l_4d6b;
	case 19823ULL: goto x86_l_4d6f;
	case 19830ULL: goto x86_l_4d76;
	case 19835ULL: goto x86_l_4d7b;
	case 19837ULL: goto x86_l_4d7d;
	case 19842ULL: goto x86_l_4d82;
	case 19850ULL: goto x86_l_4d8a;
	case 19853ULL: goto x86_l_4d8d;
	case 19861ULL: goto x86_l_4d95;
	case 19870ULL: goto x86_l_4d9e;
	case 19877ULL: goto x86_l_4da5;
	case 19882ULL: goto x86_l_4daa;
	case 19887ULL: goto x86_l_4daf;
	case 19892ULL: goto x86_l_4db4;
	case 19897ULL: goto x86_l_4db9;
	case 19899ULL: goto x86_l_4dbb;
	case 19904ULL: goto x86_l_4dc0;
	case 19906ULL: goto x86_l_4dc2;
	case 19909ULL: goto x86_l_4dc5;
	case 19915ULL: goto x86_l_4dcb;
	case 19918ULL: goto x86_l_4dce;
	case 19924ULL: goto x86_l_4dd4;
	case 19930ULL: goto x86_l_4dda;
	case 19935ULL: goto x86_l_4ddf;
	case 19939ULL: goto x86_l_4de3;
	case 19946ULL: goto x86_l_4dea;
	case 19951ULL: goto x86_l_4def;
	case 19956ULL: goto x86_l_4df4;
	case 19963ULL: goto x86_l_4dfb;
	case 19966ULL: goto x86_l_4dfe;
	case 19973ULL: goto x86_l_4e05;
	case 19978ULL: goto x86_l_4e0a;
	case 19983ULL: goto x86_l_4e0f;
	case 19985ULL: goto x86_l_4e11;
	case 19989ULL: goto x86_l_4e15;
	case 19991ULL: goto x86_l_4e17;
	case 19993ULL: goto x86_l_4e19;
	case 19999ULL: goto x86_l_4e1f;
	case 20002ULL: goto x86_l_4e22;
	case 20008ULL: goto x86_l_4e28;
	case 20014ULL: goto x86_l_4e2e;
	case 20019ULL: goto x86_l_4e33;
	case 20023ULL: goto x86_l_4e37;
	case 20030ULL: goto x86_l_4e3e;
	case 20035ULL: goto x86_l_4e43;
	case 20040ULL: goto x86_l_4e48;
	case 20045ULL: goto x86_l_4e4d;
	case 20053ULL: goto x86_l_4e55;
	case 20057ULL: goto x86_l_4e59;
	case 20064ULL: goto x86_l_4e60;
	case 20069ULL: goto x86_l_4e65;
	case 20071ULL: goto x86_l_4e67;
	case 20076ULL: goto x86_l_4e6c;
	case 20084ULL: goto x86_l_4e74;
	case 20087ULL: goto x86_l_4e77;
	case 20095ULL: goto x86_l_4e7f;
	case 20104ULL: goto x86_l_4e88;
	case 20111ULL: goto x86_l_4e8f;
	case 20116ULL: goto x86_l_4e94;
	case 20121ULL: goto x86_l_4e99;
	case 20126ULL: goto x86_l_4e9e;
	case 20131ULL: goto x86_l_4ea3;
	case 20133ULL: goto x86_l_4ea5;
	case 20138ULL: goto x86_l_4eaa;
	case 20140ULL: goto x86_l_4eac;
	case 20143ULL: goto x86_l_4eaf;
	case 20149ULL: goto x86_l_4eb5;
	case 20152ULL: goto x86_l_4eb8;
	case 20158ULL: goto x86_l_4ebe;
	case 20164ULL: goto x86_l_4ec4;
	case 20169ULL: goto x86_l_4ec9;
	case 20173ULL: goto x86_l_4ecd;
	case 20180ULL: goto x86_l_4ed4;
	case 20185ULL: goto x86_l_4ed9;
	case 20190ULL: goto x86_l_4ede;
	case 20197ULL: goto x86_l_4ee5;
	case 20200ULL: goto x86_l_4ee8;
	case 20207ULL: goto x86_l_4eef;
	case 20212ULL: goto x86_l_4ef4;
	case 20217ULL: goto x86_l_4ef9;
	case 20219ULL: goto x86_l_4efb;
	case 20223ULL: goto x86_l_4eff;
	case 20225ULL: goto x86_l_4f01;
	case 20227ULL: goto x86_l_4f03;
	case 20233ULL: goto x86_l_4f09;
	case 20236ULL: goto x86_l_4f0c;
	case 20242ULL: goto x86_l_4f12;
	case 20248ULL: goto x86_l_4f18;
	case 20253ULL: goto x86_l_4f1d;
	case 20257ULL: goto x86_l_4f21;
	case 20264ULL: goto x86_l_4f28;
	case 20269ULL: goto x86_l_4f2d;
	case 20274ULL: goto x86_l_4f32;
	case 20279ULL: goto x86_l_4f37;
	case 20287ULL: goto x86_l_4f3f;
	case 20291ULL: goto x86_l_4f43;
	case 20298ULL: goto x86_l_4f4a;
	case 20303ULL: goto x86_l_4f4f;
	case 20305ULL: goto x86_l_4f51;
	case 20310ULL: goto x86_l_4f56;
	case 20318ULL: goto x86_l_4f5e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_47e7:
	/* 0x47e7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_47ef:
	/* 0x47ef: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_47f3:
	/* 0x47f3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_47fa:
	/* 0x47fa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_47ff:
	/* 0x47ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4801:
	/* 0x4801: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4806:
	/* 0x4806: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_480e:
	/* 0x480e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4811:
	/* 0x4811: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4819:
	/* 0x4819: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4822:
	/* 0x4822: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4829:
	/* 0x4829: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_482e:
	/* 0x482e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4833:
	/* 0x4833: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4838:
	/* 0x4838: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_483d:
	/* 0x483d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_483f:
	/* 0x483f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4844:
	/* 0x4844: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_4846:
	/* 0x4846: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4849:
	/* 0x4849: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_484f:
	/* 0x484f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4852:
	/* 0x4852: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4858:
	/* 0x4858: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_485e:
	/* 0x485e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4863:
	/* 0x4863: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4867:
	/* 0x4867: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_486e:
	/* 0x486e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4873:
	/* 0x4873: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4878:
	/* 0x4878: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_487f:
	/* 0x487f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4882:
	/* 0x4882: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4889:
	/* 0x4889: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_488e:
	/* 0x488e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4893:
	/* 0x4893: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4895:
	/* 0x4895: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4899:
	/* 0x4899: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_489b:
	/* 0x489b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_489d:
	/* 0x489d: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_48a3:
	/* 0x48a3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_48a6:
	/* 0x48a6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_48ac:
	/* 0x48ac: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_48b2:
	/* 0x48b2: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48b7:
	/* 0x48b7: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_48bb:
	/* 0x48bb: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_48c2:
	/* 0x48c2: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_48c7:
	/* 0x48c7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_48cc:
	/* 0x48cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_48d1:
	/* 0x48d1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_48d9:
	/* 0x48d9: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_48dd:
	/* 0x48dd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_48e4:
	/* 0x48e4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_48e9:
	/* 0x48e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48eb:
	/* 0x48eb: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_48f0:
	/* 0x48f0: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_48f8:
	/* 0x48f8: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_48fb:
	/* 0x48fb: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4903:
	/* 0x4903: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_490c:
	/* 0x490c: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_4913:
	/* 0x4913: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4918:
	/* 0x4918: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_491d:
	/* 0x491d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4922:
	/* 0x4922: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4927:
	/* 0x4927: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4929:
	/* 0x4929: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_492e:
	/* 0x492e: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_4930:
	/* 0x4930: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4933:
	/* 0x4933: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_4939:
	/* 0x4939: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_493c:
	/* 0x493c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4942:
	/* 0x4942: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4948:
	/* 0x4948: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_494d:
	/* 0x494d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4951:
	/* 0x4951: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4958:
	/* 0x4958: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_495d:
	/* 0x495d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4962:
	/* 0x4962: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4969:
	/* 0x4969: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_496c:
	/* 0x496c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4973:
	/* 0x4973: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4978:
	/* 0x4978: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_497d:
	/* 0x497d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_497f:
	/* 0x497f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4983:
	/* 0x4983: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_4985:
	/* 0x4985: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4987:
	/* 0x4987: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_498d:
	/* 0x498d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4990:
	/* 0x4990: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4996:
	/* 0x4996: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_499c:
	/* 0x499c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49a1:
	/* 0x49a1: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_49a5:
	/* 0x49a5: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_49ac:
	/* 0x49ac: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_49b1:
	/* 0x49b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_49b6:
	/* 0x49b6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_49bb:
	/* 0x49bb: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_49c3:
	/* 0x49c3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_49c7:
	/* 0x49c7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_49ce:
	/* 0x49ce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_49d3:
	/* 0x49d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49d5:
	/* 0x49d5: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_49da:
	/* 0x49da: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_49e2:
	/* 0x49e2: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_49e5:
	/* 0x49e5: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_49ed:
	/* 0x49ed: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_49f6:
	/* 0x49f6: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_49fd:
	/* 0x49fd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a02:
	/* 0x4a02: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4a07:
	/* 0x4a07: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4a0c:
	/* 0x4a0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a11:
	/* 0x4a11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a13:
	/* 0x4a13: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a18:
	/* 0x4a18: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_4a1a:
	/* 0x4a1a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4a1d:
	/* 0x4a1d: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_4a23:
	/* 0x4a23: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4a26:
	/* 0x4a26: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4a2c:
	/* 0x4a2c: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4a32:
	/* 0x4a32: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a37:
	/* 0x4a37: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4a3b:
	/* 0x4a3b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4a42:
	/* 0x4a42: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4a47:
	/* 0x4a47: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4a4c:
	/* 0x4a4c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4a53:
	/* 0x4a53: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4a56:
	/* 0x4a56: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4a5d:
	/* 0x4a5d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a62:
	/* 0x4a62: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4a67:
	/* 0x4a67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a69:
	/* 0x4a69: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4a6d:
	/* 0x4a6d: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_4a6f:
	/* 0x4a6f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a71:
	/* 0x4a71: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_4a77:
	/* 0x4a77: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4a7a:
	/* 0x4a7a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4a80:
	/* 0x4a80: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4a86:
	/* 0x4a86: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a8b:
	/* 0x4a8b: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4a8f:
	/* 0x4a8f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4a96:
	/* 0x4a96: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4a9b:
	/* 0x4a9b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4aa0:
	/* 0x4aa0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4aa5:
	/* 0x4aa5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4aad:
	/* 0x4aad: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4ab1:
	/* 0x4ab1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4ab8:
	/* 0x4ab8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4abd:
	/* 0x4abd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4abf:
	/* 0x4abf: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4ac4:
	/* 0x4ac4: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4acc:
	/* 0x4acc: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4acf:
	/* 0x4acf: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4ad7:
	/* 0x4ad7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4ae0:
	/* 0x4ae0: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_4ae7:
	/* 0x4ae7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4aec:
	/* 0x4aec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4af1:
	/* 0x4af1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4af6:
	/* 0x4af6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4afb:
	/* 0x4afb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4afd:
	/* 0x4afd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b02:
	/* 0x4b02: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_4b04:
	/* 0x4b04: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4b07:
	/* 0x4b07: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_4b0d:
	/* 0x4b0d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b10:
	/* 0x4b10: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4b16:
	/* 0x4b16: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4b1c:
	/* 0x4b1c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b21:
	/* 0x4b21: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4b25:
	/* 0x4b25: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4b2c:
	/* 0x4b2c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4b31:
	/* 0x4b31: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4b36:
	/* 0x4b36: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4b3d:
	/* 0x4b3d: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4b40:
	/* 0x4b40: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4b47:
	/* 0x4b47: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b4c:
	/* 0x4b4c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4b51:
	/* 0x4b51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b53:
	/* 0x4b53: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4b57:
	/* 0x4b57: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_4b59:
	/* 0x4b59: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b5b:
	/* 0x4b5b: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_4b61:
	/* 0x4b61: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b64:
	/* 0x4b64: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4b6a:
	/* 0x4b6a: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4b70:
	/* 0x4b70: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b75:
	/* 0x4b75: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4b79:
	/* 0x4b79: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4b80:
	/* 0x4b80: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4b85:
	/* 0x4b85: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4b8a:
	/* 0x4b8a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b8f:
	/* 0x4b8f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4b97:
	/* 0x4b97: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4b9b:
	/* 0x4b9b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4ba2:
	/* 0x4ba2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4ba7:
	/* 0x4ba7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ba9:
	/* 0x4ba9: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4bae:
	/* 0x4bae: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4bb6:
	/* 0x4bb6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4bb9:
	/* 0x4bb9: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4bc1:
	/* 0x4bc1: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4bca:
	/* 0x4bca: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_4bd1:
	/* 0x4bd1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bd6:
	/* 0x4bd6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4bdb:
	/* 0x4bdb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4be0:
	/* 0x4be0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4be5:
	/* 0x4be5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4be7:
	/* 0x4be7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bec:
	/* 0x4bec: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_4bee:
	/* 0x4bee: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4bf1:
	/* 0x4bf1: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_4bf7:
	/* 0x4bf7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4bfa:
	/* 0x4bfa: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4c00:
	/* 0x4c00: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4c06:
	/* 0x4c06: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c0b:
	/* 0x4c0b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4c0f:
	/* 0x4c0f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4c16:
	/* 0x4c16: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4c1b:
	/* 0x4c1b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4c20:
	/* 0x4c20: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4c27:
	/* 0x4c27: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4c2a:
	/* 0x4c2a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4c31:
	/* 0x4c31: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c36:
	/* 0x4c36: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4c3b:
	/* 0x4c3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c3d:
	/* 0x4c3d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c41:
	/* 0x4c41: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_4c43:
	/* 0x4c43: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c45:
	/* 0x4c45: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_4c4b:
	/* 0x4c4b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4c4e:
	/* 0x4c4e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4c54:
	/* 0x4c54: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4c5a:
	/* 0x4c5a: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c5f:
	/* 0x4c5f: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4c63:
	/* 0x4c63: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4c6a:
	/* 0x4c6a: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c6f:
	/* 0x4c6f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4c74:
	/* 0x4c74: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4c79:
	/* 0x4c79: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4c81:
	/* 0x4c81: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4c85:
	/* 0x4c85: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4c8c:
	/* 0x4c8c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4c91:
	/* 0x4c91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c93:
	/* 0x4c93: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4c98:
	/* 0x4c98: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4ca0:
	/* 0x4ca0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4ca3:
	/* 0x4ca3: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4cab:
	/* 0x4cab: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4cb4:
	/* 0x4cb4: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_4cbb:
	/* 0x4cbb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4cc0:
	/* 0x4cc0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4cc5:
	/* 0x4cc5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4cca:
	/* 0x4cca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ccf:
	/* 0x4ccf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cd1:
	/* 0x4cd1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4cd6:
	/* 0x4cd6: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_4cd8:
	/* 0x4cd8: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4cdb:
	/* 0x4cdb: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_4ce1:
	/* 0x4ce1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ce4:
	/* 0x4ce4: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4cea:
	/* 0x4cea: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4cf0:
	/* 0x4cf0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cf5:
	/* 0x4cf5: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4cf9:
	/* 0x4cf9: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4d00:
	/* 0x4d00: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4d05:
	/* 0x4d05: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4d0a:
	/* 0x4d0a: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4d11:
	/* 0x4d11: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4d14:
	/* 0x4d14: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4d1b:
	/* 0x4d1b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d20:
	/* 0x4d20: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4d25:
	/* 0x4d25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d27:
	/* 0x4d27: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4d2b:
	/* 0x4d2b: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_4d2d:
	/* 0x4d2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d2f:
	/* 0x4d2f: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_4d35:
	/* 0x4d35: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4d38:
	/* 0x4d38: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4d3e:
	/* 0x4d3e: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4d44:
	/* 0x4d44: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d49:
	/* 0x4d49: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4d4d:
	/* 0x4d4d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4d54:
	/* 0x4d54: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4d59:
	/* 0x4d59: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4d5e:
	/* 0x4d5e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d63:
	/* 0x4d63: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4d6b:
	/* 0x4d6b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4d6f:
	/* 0x4d6f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4d76:
	/* 0x4d76: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4d7b:
	/* 0x4d7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d7d:
	/* 0x4d7d: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4d82:
	/* 0x4d82: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4d8a:
	/* 0x4d8a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4d8d:
	/* 0x4d8d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4d95:
	/* 0x4d95: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4d9e:
	/* 0x4d9e: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_4da5:
	/* 0x4da5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4daa:
	/* 0x4daa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4daf:
	/* 0x4daf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4db4:
	/* 0x4db4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4db9:
	/* 0x4db9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dbb:
	/* 0x4dbb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4dc0:
	/* 0x4dc0: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_4dc2:
	/* 0x4dc2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4dc5:
	/* 0x4dc5: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_4dcb:
	/* 0x4dcb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4dce:
	/* 0x4dce: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4dd4:
	/* 0x4dd4: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4dda:
	/* 0x4dda: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ddf:
	/* 0x4ddf: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4de3:
	/* 0x4de3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4dea:
	/* 0x4dea: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4def:
	/* 0x4def: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4df4:
	/* 0x4df4: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4dfb:
	/* 0x4dfb: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4dfe:
	/* 0x4dfe: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4e05:
	/* 0x4e05: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e0a:
	/* 0x4e0a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4e0f:
	/* 0x4e0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e11:
	/* 0x4e11: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4e15:
	/* 0x4e15: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_4e17:
	/* 0x4e17: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e19:
	/* 0x4e19: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_4e1f:
	/* 0x4e1f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4e22:
	/* 0x4e22: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4e28:
	/* 0x4e28: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4e2e:
	/* 0x4e2e: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e33:
	/* 0x4e33: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4e37:
	/* 0x4e37: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4e3e:
	/* 0x4e3e: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4e43:
	/* 0x4e43: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4e48:
	/* 0x4e48: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4e4d:
	/* 0x4e4d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4e55:
	/* 0x4e55: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4e59:
	/* 0x4e59: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4e60:
	/* 0x4e60: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4e65:
	/* 0x4e65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e67:
	/* 0x4e67: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4e6c:
	/* 0x4e6c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4e74:
	/* 0x4e74: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4e77:
	/* 0x4e77: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4e7f:
	/* 0x4e7f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4e88:
	/* 0x4e88: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_4e8f:
	/* 0x4e8f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e94:
	/* 0x4e94: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4e99:
	/* 0x4e99: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4e9e:
	/* 0x4e9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ea3:
	/* 0x4ea3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ea5:
	/* 0x4ea5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4eaa:
	/* 0x4eaa: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_4eac:
	/* 0x4eac: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4eaf:
	/* 0x4eaf: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_4eb5:
	/* 0x4eb5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4eb8:
	/* 0x4eb8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4ebe:
	/* 0x4ebe: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4ec4:
	/* 0x4ec4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ec9:
	/* 0x4ec9: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4ecd:
	/* 0x4ecd: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4ed4:
	/* 0x4ed4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4ed9:
	/* 0x4ed9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4ede:
	/* 0x4ede: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4ee5:
	/* 0x4ee5: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4ee8:
	/* 0x4ee8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4eef:
	/* 0x4eef: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ef4:
	/* 0x4ef4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4ef9:
	/* 0x4ef9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4efb:
	/* 0x4efb: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4eff:
	/* 0x4eff: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_4f01:
	/* 0x4f01: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f03:
	/* 0x4f03: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_4f09:
	/* 0x4f09: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f0c:
	/* 0x4f0c: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4f12:
	/* 0x4f12: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4f18:
	/* 0x4f18: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f1d:
	/* 0x4f1d: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4f21:
	/* 0x4f21: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4f28:
	/* 0x4f28: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4f2d:
	/* 0x4f2d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4f32:
	/* 0x4f32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f37:
	/* 0x4f37: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4f3f:
	/* 0x4f3f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4f43:
	/* 0x4f43: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4f4a:
	/* 0x4f4a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4f4f:
	/* 0x4f4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f51:
	/* 0x4f51: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4f56:
	/* 0x4f56: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4f5e:
	/* 0x4f5e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
	return 20321ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20321ULL: goto x86_l_4f61;
	case 20329ULL: goto x86_l_4f69;
	case 20338ULL: goto x86_l_4f72;
	case 20345ULL: goto x86_l_4f79;
	case 20350ULL: goto x86_l_4f7e;
	case 20355ULL: goto x86_l_4f83;
	case 20360ULL: goto x86_l_4f88;
	case 20365ULL: goto x86_l_4f8d;
	case 20367ULL: goto x86_l_4f8f;
	case 20372ULL: goto x86_l_4f94;
	case 20374ULL: goto x86_l_4f96;
	case 20377ULL: goto x86_l_4f99;
	case 20383ULL: goto x86_l_4f9f;
	case 20386ULL: goto x86_l_4fa2;
	case 20392ULL: goto x86_l_4fa8;
	case 20398ULL: goto x86_l_4fae;
	case 20403ULL: goto x86_l_4fb3;
	case 20407ULL: goto x86_l_4fb7;
	case 20414ULL: goto x86_l_4fbe;
	case 20419ULL: goto x86_l_4fc3;
	case 20424ULL: goto x86_l_4fc8;
	case 20431ULL: goto x86_l_4fcf;
	case 20434ULL: goto x86_l_4fd2;
	case 20441ULL: goto x86_l_4fd9;
	case 20446ULL: goto x86_l_4fde;
	case 20451ULL: goto x86_l_4fe3;
	case 20453ULL: goto x86_l_4fe5;
	case 20457ULL: goto x86_l_4fe9;
	case 20459ULL: goto x86_l_4feb;
	case 20461ULL: goto x86_l_4fed;
	case 20467ULL: goto x86_l_4ff3;
	case 20470ULL: goto x86_l_4ff6;
	case 20476ULL: goto x86_l_4ffc;
	case 20482ULL: goto x86_l_5002;
	case 20487ULL: goto x86_l_5007;
	case 20491ULL: goto x86_l_500b;
	case 20498ULL: goto x86_l_5012;
	case 20503ULL: goto x86_l_5017;
	case 20508ULL: goto x86_l_501c;
	case 20513ULL: goto x86_l_5021;
	case 20521ULL: goto x86_l_5029;
	case 20525ULL: goto x86_l_502d;
	case 20532ULL: goto x86_l_5034;
	case 20537ULL: goto x86_l_5039;
	case 20539ULL: goto x86_l_503b;
	case 20544ULL: goto x86_l_5040;
	case 20552ULL: goto x86_l_5048;
	case 20555ULL: goto x86_l_504b;
	case 20563ULL: goto x86_l_5053;
	case 20572ULL: goto x86_l_505c;
	case 20579ULL: goto x86_l_5063;
	case 20584ULL: goto x86_l_5068;
	case 20589ULL: goto x86_l_506d;
	case 20594ULL: goto x86_l_5072;
	case 20599ULL: goto x86_l_5077;
	case 20601ULL: goto x86_l_5079;
	case 20606ULL: goto x86_l_507e;
	case 20608ULL: goto x86_l_5080;
	case 20611ULL: goto x86_l_5083;
	case 20617ULL: goto x86_l_5089;
	case 20620ULL: goto x86_l_508c;
	case 20626ULL: goto x86_l_5092;
	case 20632ULL: goto x86_l_5098;
	case 20637ULL: goto x86_l_509d;
	case 20641ULL: goto x86_l_50a1;
	case 20648ULL: goto x86_l_50a8;
	case 20653ULL: goto x86_l_50ad;
	case 20658ULL: goto x86_l_50b2;
	case 20665ULL: goto x86_l_50b9;
	case 20668ULL: goto x86_l_50bc;
	case 20675ULL: goto x86_l_50c3;
	case 20680ULL: goto x86_l_50c8;
	case 20685ULL: goto x86_l_50cd;
	case 20687ULL: goto x86_l_50cf;
	case 20691ULL: goto x86_l_50d3;
	case 20693ULL: goto x86_l_50d5;
	case 20695ULL: goto x86_l_50d7;
	case 20701ULL: goto x86_l_50dd;
	case 20704ULL: goto x86_l_50e0;
	case 20710ULL: goto x86_l_50e6;
	case 20716ULL: goto x86_l_50ec;
	case 20721ULL: goto x86_l_50f1;
	case 20725ULL: goto x86_l_50f5;
	case 20732ULL: goto x86_l_50fc;
	case 20737ULL: goto x86_l_5101;
	case 20742ULL: goto x86_l_5106;
	case 20747ULL: goto x86_l_510b;
	case 20755ULL: goto x86_l_5113;
	case 20759ULL: goto x86_l_5117;
	case 20766ULL: goto x86_l_511e;
	case 20771ULL: goto x86_l_5123;
	case 20773ULL: goto x86_l_5125;
	case 20778ULL: goto x86_l_512a;
	case 20786ULL: goto x86_l_5132;
	case 20789ULL: goto x86_l_5135;
	case 20797ULL: goto x86_l_513d;
	case 20806ULL: goto x86_l_5146;
	case 20813ULL: goto x86_l_514d;
	case 20818ULL: goto x86_l_5152;
	case 20823ULL: goto x86_l_5157;
	case 20828ULL: goto x86_l_515c;
	case 20833ULL: goto x86_l_5161;
	case 20835ULL: goto x86_l_5163;
	case 20840ULL: goto x86_l_5168;
	case 20842ULL: goto x86_l_516a;
	case 20845ULL: goto x86_l_516d;
	case 20851ULL: goto x86_l_5173;
	case 20854ULL: goto x86_l_5176;
	case 20860ULL: goto x86_l_517c;
	case 20866ULL: goto x86_l_5182;
	case 20871ULL: goto x86_l_5187;
	case 20875ULL: goto x86_l_518b;
	case 20882ULL: goto x86_l_5192;
	case 20887ULL: goto x86_l_5197;
	case 20892ULL: goto x86_l_519c;
	case 20899ULL: goto x86_l_51a3;
	case 20902ULL: goto x86_l_51a6;
	case 20909ULL: goto x86_l_51ad;
	case 20914ULL: goto x86_l_51b2;
	case 20919ULL: goto x86_l_51b7;
	case 20921ULL: goto x86_l_51b9;
	case 20925ULL: goto x86_l_51bd;
	case 20927ULL: goto x86_l_51bf;
	case 20929ULL: goto x86_l_51c1;
	case 20935ULL: goto x86_l_51c7;
	case 20938ULL: goto x86_l_51ca;
	case 20944ULL: goto x86_l_51d0;
	case 20950ULL: goto x86_l_51d6;
	case 20955ULL: goto x86_l_51db;
	case 20959ULL: goto x86_l_51df;
	case 20966ULL: goto x86_l_51e6;
	case 20971ULL: goto x86_l_51eb;
	case 20976ULL: goto x86_l_51f0;
	case 20981ULL: goto x86_l_51f5;
	case 20989ULL: goto x86_l_51fd;
	case 20993ULL: goto x86_l_5201;
	case 21000ULL: goto x86_l_5208;
	case 21005ULL: goto x86_l_520d;
	case 21007ULL: goto x86_l_520f;
	case 21012ULL: goto x86_l_5214;
	case 21020ULL: goto x86_l_521c;
	case 21023ULL: goto x86_l_521f;
	case 21031ULL: goto x86_l_5227;
	case 21040ULL: goto x86_l_5230;
	case 21047ULL: goto x86_l_5237;
	case 21052ULL: goto x86_l_523c;
	case 21057ULL: goto x86_l_5241;
	case 21062ULL: goto x86_l_5246;
	case 21067ULL: goto x86_l_524b;
	case 21069ULL: goto x86_l_524d;
	case 21074ULL: goto x86_l_5252;
	case 21076ULL: goto x86_l_5254;
	case 21079ULL: goto x86_l_5257;
	case 21085ULL: goto x86_l_525d;
	case 21088ULL: goto x86_l_5260;
	case 21094ULL: goto x86_l_5266;
	case 21100ULL: goto x86_l_526c;
	case 21105ULL: goto x86_l_5271;
	case 21109ULL: goto x86_l_5275;
	case 21116ULL: goto x86_l_527c;
	case 21121ULL: goto x86_l_5281;
	case 21126ULL: goto x86_l_5286;
	case 21133ULL: goto x86_l_528d;
	case 21136ULL: goto x86_l_5290;
	case 21143ULL: goto x86_l_5297;
	case 21148ULL: goto x86_l_529c;
	case 21153ULL: goto x86_l_52a1;
	case 21155ULL: goto x86_l_52a3;
	case 21159ULL: goto x86_l_52a7;
	case 21161ULL: goto x86_l_52a9;
	case 21163ULL: goto x86_l_52ab;
	case 21169ULL: goto x86_l_52b1;
	case 21172ULL: goto x86_l_52b4;
	case 21178ULL: goto x86_l_52ba;
	case 21184ULL: goto x86_l_52c0;
	case 21189ULL: goto x86_l_52c5;
	case 21193ULL: goto x86_l_52c9;
	case 21200ULL: goto x86_l_52d0;
	case 21205ULL: goto x86_l_52d5;
	case 21210ULL: goto x86_l_52da;
	case 21215ULL: goto x86_l_52df;
	case 21223ULL: goto x86_l_52e7;
	case 21227ULL: goto x86_l_52eb;
	case 21234ULL: goto x86_l_52f2;
	case 21239ULL: goto x86_l_52f7;
	case 21241ULL: goto x86_l_52f9;
	case 21246ULL: goto x86_l_52fe;
	case 21254ULL: goto x86_l_5306;
	case 21257ULL: goto x86_l_5309;
	case 21265ULL: goto x86_l_5311;
	case 21274ULL: goto x86_l_531a;
	case 21281ULL: goto x86_l_5321;
	case 21286ULL: goto x86_l_5326;
	case 21291ULL: goto x86_l_532b;
	case 21296ULL: goto x86_l_5330;
	case 21301ULL: goto x86_l_5335;
	case 21303ULL: goto x86_l_5337;
	case 21308ULL: goto x86_l_533c;
	case 21310ULL: goto x86_l_533e;
	case 21313ULL: goto x86_l_5341;
	case 21319ULL: goto x86_l_5347;
	case 21322ULL: goto x86_l_534a;
	case 21328ULL: goto x86_l_5350;
	case 21334ULL: goto x86_l_5356;
	case 21339ULL: goto x86_l_535b;
	case 21343ULL: goto x86_l_535f;
	case 21350ULL: goto x86_l_5366;
	case 21355ULL: goto x86_l_536b;
	case 21360ULL: goto x86_l_5370;
	case 21367ULL: goto x86_l_5377;
	case 21370ULL: goto x86_l_537a;
	case 21377ULL: goto x86_l_5381;
	case 21382ULL: goto x86_l_5386;
	case 21387ULL: goto x86_l_538b;
	case 21389ULL: goto x86_l_538d;
	case 21393ULL: goto x86_l_5391;
	case 21395ULL: goto x86_l_5393;
	case 21397ULL: goto x86_l_5395;
	case 21403ULL: goto x86_l_539b;
	case 21406ULL: goto x86_l_539e;
	case 21412ULL: goto x86_l_53a4;
	case 21418ULL: goto x86_l_53aa;
	case 21423ULL: goto x86_l_53af;
	case 21427ULL: goto x86_l_53b3;
	case 21434ULL: goto x86_l_53ba;
	case 21439ULL: goto x86_l_53bf;
	case 21444ULL: goto x86_l_53c4;
	case 21449ULL: goto x86_l_53c9;
	case 21457ULL: goto x86_l_53d1;
	case 21461ULL: goto x86_l_53d5;
	case 21468ULL: goto x86_l_53dc;
	case 21473ULL: goto x86_l_53e1;
	case 21475ULL: goto x86_l_53e3;
	case 21480ULL: goto x86_l_53e8;
	case 21488ULL: goto x86_l_53f0;
	case 21491ULL: goto x86_l_53f3;
	case 21499ULL: goto x86_l_53fb;
	case 21508ULL: goto x86_l_5404;
	case 21515ULL: goto x86_l_540b;
	case 21520ULL: goto x86_l_5410;
	case 21525ULL: goto x86_l_5415;
	case 21530ULL: goto x86_l_541a;
	case 21535ULL: goto x86_l_541f;
	case 21537ULL: goto x86_l_5421;
	case 21542ULL: goto x86_l_5426;
	case 21544ULL: goto x86_l_5428;
	case 21547ULL: goto x86_l_542b;
	case 21553ULL: goto x86_l_5431;
	case 21556ULL: goto x86_l_5434;
	case 21562ULL: goto x86_l_543a;
	case 21568ULL: goto x86_l_5440;
	case 21573ULL: goto x86_l_5445;
	case 21577ULL: goto x86_l_5449;
	case 21584ULL: goto x86_l_5450;
	case 21589ULL: goto x86_l_5455;
	case 21594ULL: goto x86_l_545a;
	case 21601ULL: goto x86_l_5461;
	case 21604ULL: goto x86_l_5464;
	case 21611ULL: goto x86_l_546b;
	case 21616ULL: goto x86_l_5470;
	case 21621ULL: goto x86_l_5475;
	case 21623ULL: goto x86_l_5477;
	case 21627ULL: goto x86_l_547b;
	case 21629ULL: goto x86_l_547d;
	case 21631ULL: goto x86_l_547f;
	case 21637ULL: goto x86_l_5485;
	case 21640ULL: goto x86_l_5488;
	case 21646ULL: goto x86_l_548e;
	case 21652ULL: goto x86_l_5494;
	case 21657ULL: goto x86_l_5499;
	case 21661ULL: goto x86_l_549d;
	case 21668ULL: goto x86_l_54a4;
	case 21673ULL: goto x86_l_54a9;
	case 21678ULL: goto x86_l_54ae;
	case 21683ULL: goto x86_l_54b3;
	case 21691ULL: goto x86_l_54bb;
	case 21695ULL: goto x86_l_54bf;
	case 21702ULL: goto x86_l_54c6;
	case 21707ULL: goto x86_l_54cb;
	case 21709ULL: goto x86_l_54cd;
	case 21714ULL: goto x86_l_54d2;
	case 21722ULL: goto x86_l_54da;
	case 21725ULL: goto x86_l_54dd;
	case 21733ULL: goto x86_l_54e5;
	case 21742ULL: goto x86_l_54ee;
	case 21749ULL: goto x86_l_54f5;
	case 21754ULL: goto x86_l_54fa;
	case 21759ULL: goto x86_l_54ff;
	case 21764ULL: goto x86_l_5504;
	case 21769ULL: goto x86_l_5509;
	case 21771ULL: goto x86_l_550b;
	case 21776ULL: goto x86_l_5510;
	case 21778ULL: goto x86_l_5512;
	case 21781ULL: goto x86_l_5515;
	case 21787ULL: goto x86_l_551b;
	case 21790ULL: goto x86_l_551e;
	case 21796ULL: goto x86_l_5524;
	case 21802ULL: goto x86_l_552a;
	case 21807ULL: goto x86_l_552f;
	case 21811ULL: goto x86_l_5533;
	case 21818ULL: goto x86_l_553a;
	case 21823ULL: goto x86_l_553f;
	case 21828ULL: goto x86_l_5544;
	case 21835ULL: goto x86_l_554b;
	case 21838ULL: goto x86_l_554e;
	case 21845ULL: goto x86_l_5555;
	case 21850ULL: goto x86_l_555a;
	case 21855ULL: goto x86_l_555f;
	case 21857ULL: goto x86_l_5561;
	case 21861ULL: goto x86_l_5565;
	case 21863ULL: goto x86_l_5567;
	case 21865ULL: goto x86_l_5569;
	case 21871ULL: goto x86_l_556f;
	case 21874ULL: goto x86_l_5572;
	case 21880ULL: goto x86_l_5578;
	case 21886ULL: goto x86_l_557e;
	case 21891ULL: goto x86_l_5583;
	case 21895ULL: goto x86_l_5587;
	case 21902ULL: goto x86_l_558e;
	case 21907ULL: goto x86_l_5593;
	case 21912ULL: goto x86_l_5598;
	case 21917ULL: goto x86_l_559d;
	case 21925ULL: goto x86_l_55a5;
	case 21929ULL: goto x86_l_55a9;
	case 21936ULL: goto x86_l_55b0;
	case 21941ULL: goto x86_l_55b5;
	case 21943ULL: goto x86_l_55b7;
	case 21948ULL: goto x86_l_55bc;
	case 21956ULL: goto x86_l_55c4;
	case 21959ULL: goto x86_l_55c7;
	case 21967ULL: goto x86_l_55cf;
	case 21976ULL: goto x86_l_55d8;
	case 21983ULL: goto x86_l_55df;
	case 21988ULL: goto x86_l_55e4;
	case 21993ULL: goto x86_l_55e9;
	case 21998ULL: goto x86_l_55ee;
	case 22003ULL: goto x86_l_55f3;
	case 22006ULL: goto x86_l_55f6;
	case 22008ULL: goto x86_l_55f8;
	case 22013ULL: goto x86_l_55fd;
	case 22015ULL: goto x86_l_55ff;
	case 22018ULL: goto x86_l_5602;
	case 22024ULL: goto x86_l_5608;
	case 22027ULL: goto x86_l_560b;
	case 22033ULL: goto x86_l_5611;
	case 22039ULL: goto x86_l_5617;
	case 22044ULL: goto x86_l_561c;
	case 22048ULL: goto x86_l_5620;
	case 22055ULL: goto x86_l_5627;
	case 22060ULL: goto x86_l_562c;
	case 22065ULL: goto x86_l_5631;
	case 22072ULL: goto x86_l_5638;
	case 22075ULL: goto x86_l_563b;
	case 22082ULL: goto x86_l_5642;
	case 22087ULL: goto x86_l_5647;
	case 22092ULL: goto x86_l_564c;
	case 22094ULL: goto x86_l_564e;
	case 22098ULL: goto x86_l_5652;
	case 22100ULL: goto x86_l_5654;
	case 22102ULL: goto x86_l_5656;
	case 22108ULL: goto x86_l_565c;
	case 22111ULL: goto x86_l_565f;
	case 22117ULL: goto x86_l_5665;
	case 22123ULL: goto x86_l_566b;
	case 22128ULL: goto x86_l_5670;
	case 22132ULL: goto x86_l_5674;
	case 22139ULL: goto x86_l_567b;
	case 22144ULL: goto x86_l_5680;
	case 22149ULL: goto x86_l_5685;
	case 22154ULL: goto x86_l_568a;
	case 22162ULL: goto x86_l_5692;
	case 22166ULL: goto x86_l_5696;
	case 22173ULL: goto x86_l_569d;
	case 22178ULL: goto x86_l_56a2;
	case 22180ULL: goto x86_l_56a4;
	case 22185ULL: goto x86_l_56a9;
	case 22193ULL: goto x86_l_56b1;
	case 22196ULL: goto x86_l_56b4;
	case 22204ULL: goto x86_l_56bc;
	case 22212ULL: goto x86_l_56c4;
	case 22215ULL: goto x86_l_56c7;
	case 22221ULL: goto x86_l_56cd;
	case 22223ULL: goto x86_l_56cf;
	case 22228ULL: goto x86_l_56d4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4f61:
	/* 0x4f61: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4f69:
	/* 0x4f69: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4f72:
	/* 0x4f72: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_4f79:
	/* 0x4f79: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f7e:
	/* 0x4f7e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4f83:
	/* 0x4f83: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f88:
	/* 0x4f88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f8d:
	/* 0x4f8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f8f:
	/* 0x4f8f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f94:
	/* 0x4f94: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_4f96:
	/* 0x4f96: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4f99:
	/* 0x4f99: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_4f9f:
	/* 0x4f9f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4fa2:
	/* 0x4fa2: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4fa8:
	/* 0x4fa8: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_4fae:
	/* 0x4fae: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fb3:
	/* 0x4fb3: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4fb7:
	/* 0x4fb7: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4fbe:
	/* 0x4fbe: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4fc3:
	/* 0x4fc3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4fc8:
	/* 0x4fc8: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4fcf:
	/* 0x4fcf: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4fd2:
	/* 0x4fd2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4fd9:
	/* 0x4fd9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4fde:
	/* 0x4fde: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4fe3:
	/* 0x4fe3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fe5:
	/* 0x4fe5: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4fe9:
	/* 0x4fe9: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_4feb:
	/* 0x4feb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fed:
	/* 0x4fed: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_4ff3:
	/* 0x4ff3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ff6:
	/* 0x4ff6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4ffc:
	/* 0x4ffc: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_5002:
	/* 0x5002: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5007:
	/* 0x5007: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_500b:
	/* 0x500b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5012:
	/* 0x5012: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5017:
	/* 0x5017: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_501c:
	/* 0x501c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5021:
	/* 0x5021: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5029:
	/* 0x5029: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_502d:
	/* 0x502d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5034:
	/* 0x5034: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5039:
	/* 0x5039: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_503b:
	/* 0x503b: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5040:
	/* 0x5040: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5048:
	/* 0x5048: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_504b:
	/* 0x504b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5053:
	/* 0x5053: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_505c:
	/* 0x505c: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_5063:
	/* 0x5063: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5068:
	/* 0x5068: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_506d:
	/* 0x506d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5072:
	/* 0x5072: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5077:
	/* 0x5077: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5079:
	/* 0x5079: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_507e:
	/* 0x507e: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_5080:
	/* 0x5080: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5083:
	/* 0x5083: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_5089:
	/* 0x5089: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_508c:
	/* 0x508c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5092:
	/* 0x5092: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_5098:
	/* 0x5098: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_509d:
	/* 0x509d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_50a1:
	/* 0x50a1: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_50a8:
	/* 0x50a8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_50ad:
	/* 0x50ad: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_50b2:
	/* 0x50b2: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_50b9:
	/* 0x50b9: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_50bc:
	/* 0x50bc: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_50c3:
	/* 0x50c3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50c8:
	/* 0x50c8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_50cd:
	/* 0x50cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50cf:
	/* 0x50cf: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_50d3:
	/* 0x50d3: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_50d5:
	/* 0x50d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50d7:
	/* 0x50d7: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_50dd:
	/* 0x50dd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_50e0:
	/* 0x50e0: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_50e6:
	/* 0x50e6: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_50ec:
	/* 0x50ec: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50f1:
	/* 0x50f1: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_50f5:
	/* 0x50f5: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_50fc:
	/* 0x50fc: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5101:
	/* 0x5101: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5106:
	/* 0x5106: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_510b:
	/* 0x510b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5113:
	/* 0x5113: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5117:
	/* 0x5117: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_511e:
	/* 0x511e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5123:
	/* 0x5123: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5125:
	/* 0x5125: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_512a:
	/* 0x512a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5132:
	/* 0x5132: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5135:
	/* 0x5135: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_513d:
	/* 0x513d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5146:
	/* 0x5146: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_514d:
	/* 0x514d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5152:
	/* 0x5152: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5157:
	/* 0x5157: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_515c:
	/* 0x515c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5161:
	/* 0x5161: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5163:
	/* 0x5163: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5168:
	/* 0x5168: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_516a:
	/* 0x516a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_516d:
	/* 0x516d: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_5173:
	/* 0x5173: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5176:
	/* 0x5176: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_517c:
	/* 0x517c: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_5182:
	/* 0x5182: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5187:
	/* 0x5187: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_518b:
	/* 0x518b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5192:
	/* 0x5192: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5197:
	/* 0x5197: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_519c:
	/* 0x519c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_51a3:
	/* 0x51a3: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_51a6:
	/* 0x51a6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_51ad:
	/* 0x51ad: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51b2:
	/* 0x51b2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_51b7:
	/* 0x51b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51b9:
	/* 0x51b9: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_51bd:
	/* 0x51bd: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_51bf:
	/* 0x51bf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51c1:
	/* 0x51c1: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_51c7:
	/* 0x51c7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_51ca:
	/* 0x51ca: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_51d0:
	/* 0x51d0: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_51d6:
	/* 0x51d6: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51db:
	/* 0x51db: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_51df:
	/* 0x51df: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_51e6:
	/* 0x51e6: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_51eb:
	/* 0x51eb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_51f0:
	/* 0x51f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_51f5:
	/* 0x51f5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_51fd:
	/* 0x51fd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5201:
	/* 0x5201: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5208:
	/* 0x5208: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_520d:
	/* 0x520d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_520f:
	/* 0x520f: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5214:
	/* 0x5214: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_521c:
	/* 0x521c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_521f:
	/* 0x521f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5227:
	/* 0x5227: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5230:
	/* 0x5230: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_5237:
	/* 0x5237: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_523c:
	/* 0x523c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5241:
	/* 0x5241: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5246:
	/* 0x5246: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_524b:
	/* 0x524b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_524d:
	/* 0x524d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5252:
	/* 0x5252: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_5254:
	/* 0x5254: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5257:
	/* 0x5257: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_525d:
	/* 0x525d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5260:
	/* 0x5260: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5266:
	/* 0x5266: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_526c:
	/* 0x526c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5271:
	/* 0x5271: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5275:
	/* 0x5275: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_527c:
	/* 0x527c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5281:
	/* 0x5281: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5286:
	/* 0x5286: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_528d:
	/* 0x528d: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5290:
	/* 0x5290: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5297:
	/* 0x5297: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_529c:
	/* 0x529c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_52a1:
	/* 0x52a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52a3:
	/* 0x52a3: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_52a7:
	/* 0x52a7: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_52a9:
	/* 0x52a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52ab:
	/* 0x52ab: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_52b1:
	/* 0x52b1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_52b4:
	/* 0x52b4: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_52ba:
	/* 0x52ba: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_52c0:
	/* 0x52c0: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52c5:
	/* 0x52c5: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_52c9:
	/* 0x52c9: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_52d0:
	/* 0x52d0: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_52d5:
	/* 0x52d5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_52da:
	/* 0x52da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_52df:
	/* 0x52df: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_52e7:
	/* 0x52e7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_52eb:
	/* 0x52eb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_52f2:
	/* 0x52f2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_52f7:
	/* 0x52f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52f9:
	/* 0x52f9: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_52fe:
	/* 0x52fe: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5306:
	/* 0x5306: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5309:
	/* 0x5309: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5311:
	/* 0x5311: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_531a:
	/* 0x531a: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_5321:
	/* 0x5321: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5326:
	/* 0x5326: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_532b:
	/* 0x532b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5330:
	/* 0x5330: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5335:
	/* 0x5335: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5337:
	/* 0x5337: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_533c:
	/* 0x533c: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_533e:
	/* 0x533e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5341:
	/* 0x5341: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_5347:
	/* 0x5347: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_534a:
	/* 0x534a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5350:
	/* 0x5350: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_5356:
	/* 0x5356: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_535b:
	/* 0x535b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_535f:
	/* 0x535f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5366:
	/* 0x5366: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_536b:
	/* 0x536b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5370:
	/* 0x5370: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5377:
	/* 0x5377: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_537a:
	/* 0x537a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5381:
	/* 0x5381: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5386:
	/* 0x5386: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_538b:
	/* 0x538b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_538d:
	/* 0x538d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5391:
	/* 0x5391: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_5393:
	/* 0x5393: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5395:
	/* 0x5395: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_539b:
	/* 0x539b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_539e:
	/* 0x539e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_53a4:
	/* 0x53a4: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_53aa:
	/* 0x53aa: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53af:
	/* 0x53af: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_53b3:
	/* 0x53b3: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_53ba:
	/* 0x53ba: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_53bf:
	/* 0x53bf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_53c4:
	/* 0x53c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_53c9:
	/* 0x53c9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_53d1:
	/* 0x53d1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_53d5:
	/* 0x53d5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_53dc:
	/* 0x53dc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_53e1:
	/* 0x53e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53e3:
	/* 0x53e3: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_53e8:
	/* 0x53e8: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_53f0:
	/* 0x53f0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_53f3:
	/* 0x53f3: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_53fb:
	/* 0x53fb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5404:
	/* 0x5404: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_540b:
	/* 0x540b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5410:
	/* 0x5410: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5415:
	/* 0x5415: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_541a:
	/* 0x541a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_541f:
	/* 0x541f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5421:
	/* 0x5421: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5426:
	/* 0x5426: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_5428:
	/* 0x5428: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_542b:
	/* 0x542b: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_5431:
	/* 0x5431: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5434:
	/* 0x5434: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_543a:
	/* 0x543a: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_5440:
	/* 0x5440: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5445:
	/* 0x5445: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5449:
	/* 0x5449: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5450:
	/* 0x5450: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5455:
	/* 0x5455: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_545a:
	/* 0x545a: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5461:
	/* 0x5461: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5464:
	/* 0x5464: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_546b:
	/* 0x546b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5470:
	/* 0x5470: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5475:
	/* 0x5475: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5477:
	/* 0x5477: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_547b:
	/* 0x547b: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_547d:
	/* 0x547d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_547f:
	/* 0x547f: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_5485:
	/* 0x5485: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5488:
	/* 0x5488: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_548e:
	/* 0x548e: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_5494:
	/* 0x5494: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5499:
	/* 0x5499: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_549d:
	/* 0x549d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_54a4:
	/* 0x54a4: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_54a9:
	/* 0x54a9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_54ae:
	/* 0x54ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_54b3:
	/* 0x54b3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_54bb:
	/* 0x54bb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_54bf:
	/* 0x54bf: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_54c6:
	/* 0x54c6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_54cb:
	/* 0x54cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54cd:
	/* 0x54cd: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_54d2:
	/* 0x54d2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_54da:
	/* 0x54da: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_54dd:
	/* 0x54dd: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_54e5:
	/* 0x54e5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_54ee:
	/* 0x54ee: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_54f5:
	/* 0x54f5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54fa:
	/* 0x54fa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_54ff:
	/* 0x54ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5504:
	/* 0x5504: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5509:
	/* 0x5509: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_550b:
	/* 0x550b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5510:
	/* 0x5510: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_5512:
	/* 0x5512: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5515:
	/* 0x5515: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_551b:
	/* 0x551b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_551e:
	/* 0x551e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5524:
	/* 0x5524: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_552a:
	/* 0x552a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_552f:
	/* 0x552f: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5533:
	/* 0x5533: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_553a:
	/* 0x553a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_553f:
	/* 0x553f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5544:
	/* 0x5544: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_554b:
	/* 0x554b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_554e:
	/* 0x554e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5555:
	/* 0x5555: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_555a:
	/* 0x555a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_555f:
	/* 0x555f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5561:
	/* 0x5561: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5565:
	/* 0x5565: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_5567:
	/* 0x5567: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5569:
	/* 0x5569: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_556f:
	/* 0x556f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5572:
	/* 0x5572: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5578:
	/* 0x5578: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_557e:
	/* 0x557e: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5583:
	/* 0x5583: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5587:
	/* 0x5587: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_558e:
	/* 0x558e: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5593:
	/* 0x5593: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5598:
	/* 0x5598: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_559d:
	/* 0x559d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_55a5:
	/* 0x55a5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_55a9:
	/* 0x55a9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_55b0:
	/* 0x55b0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_55b5:
	/* 0x55b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55b7:
	/* 0x55b7: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_55bc:
	/* 0x55bc: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_55c4:
	/* 0x55c4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_55c7:
	/* 0x55c7: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_55cf:
	/* 0x55cf: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_55d8:
	/* 0x55d8: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_55df:
	/* 0x55df: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55e4:
	/* 0x55e4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_55e9:
	/* 0x55e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_55ee:
	/* 0x55ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55f3:
	/* 0x55f3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_55f6:
	/* 0x55f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55f8:
	/* 0x55f8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55fd:
	/* 0x55fd: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_55ff:
	/* 0x55ff: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5602:
	/* 0x5602: je     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_5608:
	/* 0x5608: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_560b:
	/* 0x560b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5611:
	/* 0x5611: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_5617:
	/* 0x5617: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_561c:
	/* 0x561c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5620:
	/* 0x5620: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5627:
	/* 0x5627: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_562c:
	/* 0x562c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5631:
	/* 0x5631: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5638:
	/* 0x5638: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_563b:
	/* 0x563b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5642:
	/* 0x5642: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5647:
	/* 0x5647: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_564c:
	/* 0x564c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_564e:
	/* 0x564e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5652:
	/* 0x5652: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_5654:
	/* 0x5654: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5656:
	/* 0x5656: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_565c:
	/* 0x565c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_565f:
	/* 0x565f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5665:
	/* 0x5665: ja     c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3158ULL;
	}
x86_l_566b:
	/* 0x566b: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5670:
	/* 0x5670: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5674:
	/* 0x5674: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_567b:
	/* 0x567b: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5680:
	/* 0x5680: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5685:
	/* 0x5685: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_568a:
	/* 0x568a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5692:
	/* 0x5692: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5696:
	/* 0x5696: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_569d:
	/* 0x569d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_56a2:
	/* 0x56a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56a4:
	/* 0x56a4: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_56a9:
	/* 0x56a9: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_56b1:
	/* 0x56b1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_56b4:
	/* 0x56b4: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_56bc:
	/* 0x56bc: mov    DWORD PTR [rsp+0x10],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68722503214ULL);
x86_l_56c4:
	/* 0x56c4: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_56c7:
	/* 0x56c7: cmp    ecx,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27901ULL);
x86_l_56cd:
	/* 0x56cd: jb     56d8 <syscall__execve_exit+0x56d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 22232ULL;
	}
x86_l_56cf:
	/* 0x56cf: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_56d4:
	/* 0x56d4: mov    ax,0x6cfc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 27900ULL);
	return 22232ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22232ULL: goto x86_l_56d8;
	case 22235ULL: goto x86_l_56db;
	case 22240ULL: goto x86_l_56e0;
	case 22244ULL: goto x86_l_56e4;
	case 22251ULL: goto x86_l_56eb;
	case 22256ULL: goto x86_l_56f0;
	case 22261ULL: goto x86_l_56f5;
	case 22266ULL: goto x86_l_56fa;
	case 22273ULL: goto x86_l_5701;
	case 22276ULL: goto x86_l_5704;
	case 22283ULL: goto x86_l_570b;
	case 22288ULL: goto x86_l_5710;
	case 22290ULL: goto x86_l_5712;
	case 22294ULL: goto x86_l_5716;
	case 22296ULL: goto x86_l_5718;
	case 22298ULL: goto x86_l_571a;
	case 22304ULL: goto x86_l_5720;
	case 22307ULL: goto x86_l_5723;
	case 22313ULL: goto x86_l_5729;
	case 22318ULL: goto x86_l_572e;
	case 22324ULL: goto x86_l_5734;
	case 22329ULL: goto x86_l_5739;
	case 22333ULL: goto x86_l_573d;
	case 22340ULL: goto x86_l_5744;
	case 22345ULL: goto x86_l_5749;
	case 22350ULL: goto x86_l_574e;
	case 22355ULL: goto x86_l_5753;
	case 22363ULL: goto x86_l_575b;
	case 22367ULL: goto x86_l_575f;
	case 22374ULL: goto x86_l_5766;
	case 22379ULL: goto x86_l_576b;
	case 22381ULL: goto x86_l_576d;
	case 22386ULL: goto x86_l_5772;
	case 22394ULL: goto x86_l_577a;
	case 22397ULL: goto x86_l_577d;
	case 22405ULL: goto x86_l_5785;
	case 22407ULL: goto x86_l_5787;
	default: return 0xffffffffffffffffULL;
	}
x86_l_56d8:
	/* 0x56d8: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_56db:
	/* 0x56db: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56e0:
	/* 0x56e0: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_56e4:
	/* 0x56e4: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_56eb:
	/* 0x56eb: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56f0:
	/* 0x56f0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_56f5:
	/* 0x56f5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_56fa:
	/* 0x56fa: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5701:
	/* 0x5701: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5704:
	/* 0x5704: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_570b:
	/* 0x570b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5710:
	/* 0x5710: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5712:
	/* 0x5712: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5716:
	/* 0x5716: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_5718:
	/* 0x5718: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_571a:
	/* 0x571a: jle    c56 <syscall__execve_exit+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3158ULL;
	}
x86_l_5720:
	/* 0x5720: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5723:
	/* 0x5723: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5729:
	/* 0x5729: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_572e:
	/* 0x572e: ja     c5b <syscall__execve_exit+0xc5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3163ULL;
	}
x86_l_5734:
	/* 0x5734: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5739:
	/* 0x5739: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_573d:
	/* 0x573d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5744:
	/* 0x5744: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5749:
	/* 0x5749: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_574e:
	/* 0x574e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5753:
	/* 0x5753: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_575b:
	/* 0x575b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_575f:
	/* 0x575f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5766:
	/* 0x5766: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_576b:
	/* 0x576b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_576d:
	/* 0x576d: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5772:
	/* 0x5772: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_577a:
	/* 0x577a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_577d:
	/* 0x577d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5785:
	/* 0x5785: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_5787:
	/* 0x5787: jmp    c5b <syscall__execve_exit+0xc5b> */
	return 3163ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_syscall__execve_exit_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 18580U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1728ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1731ULL && __x86_pc <= 3384ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3389ULL && __x86_pc <= 5095ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5102ULL && __x86_pc <= 6990ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6994ULL && __x86_pc <= 8883ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8886ULL && __x86_pc <= 10795ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10800ULL && __x86_pc <= 12706ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12710ULL && __x86_pc <= 14614ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14621ULL && __x86_pc <= 16495ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16498ULL && __x86_pc <= 18402ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 18407ULL && __x86_pc <= 20318ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 20321ULL && __x86_pc <= 22228ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 22232ULL && __x86_pc <= 22407ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_12(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

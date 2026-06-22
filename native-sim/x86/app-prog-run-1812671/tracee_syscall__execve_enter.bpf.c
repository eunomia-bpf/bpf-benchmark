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

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 21ULL: goto x86_l_15;
	case 26ULL: goto x86_l_1a;
	case 33ULL: goto x86_l_21;
	case 38ULL: goto x86_l_26;
	case 40ULL: goto x86_l_28;
	case 43ULL: goto x86_l_2b;
	case 49ULL: goto x86_l_31;
	case 52ULL: goto x86_l_34;
	case 57ULL: goto x86_l_39;
	case 64ULL: goto x86_l_40;
	case 69ULL: goto x86_l_45;
	case 71ULL: goto x86_l_47;
	case 74ULL: goto x86_l_4a;
	case 80ULL: goto x86_l_50;
	case 83ULL: goto x86_l_53;
	case 87ULL: goto x86_l_57;
	case 92ULL: goto x86_l_5c;
	case 99ULL: goto x86_l_63;
	case 102ULL: goto x86_l_66;
	case 104ULL: goto x86_l_68;
	case 107ULL: goto x86_l_6b;
	case 113ULL: goto x86_l_71;
	case 116ULL: goto x86_l_74;
	case 120ULL: goto x86_l_78;
	case 125ULL: goto x86_l_7d;
	case 132ULL: goto x86_l_84;
	case 135ULL: goto x86_l_87;
	case 137ULL: goto x86_l_89;
	case 140ULL: goto x86_l_8c;
	case 146ULL: goto x86_l_92;
	case 154ULL: goto x86_l_9a;
	case 160ULL: goto x86_l_a0;
	case 168ULL: goto x86_l_a8;
	case 171ULL: goto x86_l_ab;
	case 178ULL: goto x86_l_b2;
	case 181ULL: goto x86_l_b5;
	case 189ULL: goto x86_l_bd;
	case 199ULL: goto x86_l_c7;
	case 207ULL: goto x86_l_cf;
	case 218ULL: goto x86_l_da;
	case 229ULL: goto x86_l_e5;
	case 240ULL: goto x86_l_f0;
	case 251ULL: goto x86_l_fb;
	case 262ULL: goto x86_l_106;
	case 273ULL: goto x86_l_111;
	case 284ULL: goto x86_l_11c;
	case 295ULL: goto x86_l_127;
	case 306ULL: goto x86_l_132;
	case 311ULL: goto x86_l_137;
	case 319ULL: goto x86_l_13f;
	case 324ULL: goto x86_l_144;
	case 329ULL: goto x86_l_149;
	case 336ULL: goto x86_l_150;
	case 341ULL: goto x86_l_155;
	case 343ULL: goto x86_l_157;
	case 346ULL: goto x86_l_15a;
	case 352ULL: goto x86_l_160;
	case 357ULL: goto x86_l_165;
	case 362ULL: goto x86_l_16a;
	case 365ULL: goto x86_l_16d;
	case 367ULL: goto x86_l_16f;
	case 370ULL: goto x86_l_172;
	case 376ULL: goto x86_l_178;
	case 380ULL: goto x86_l_17c;
	case 387ULL: goto x86_l_183;
	case 390ULL: goto x86_l_186;
	case 397ULL: goto x86_l_18d;
	case 404ULL: goto x86_l_194;
	case 408ULL: goto x86_l_198;
	case 415ULL: goto x86_l_19f;
	case 419ULL: goto x86_l_1a3;
	case 426ULL: goto x86_l_1aa;
	case 430ULL: goto x86_l_1ae;
	case 437ULL: goto x86_l_1b5;
	case 441ULL: goto x86_l_1b9;
	case 448ULL: goto x86_l_1c0;
	case 452ULL: goto x86_l_1c4;
	case 456ULL: goto x86_l_1c8;
	case 463ULL: goto x86_l_1cf;
	case 470ULL: goto x86_l_1d6;
	case 474ULL: goto x86_l_1da;
	case 478ULL: goto x86_l_1de;
	case 483ULL: goto x86_l_1e3;
	case 488ULL: goto x86_l_1e8;
	case 496ULL: goto x86_l_1f0;
	case 498ULL: goto x86_l_1f2;
	case 500ULL: goto x86_l_1f4;
	case 502ULL: goto x86_l_1f6;
	case 505ULL: goto x86_l_1f9;
	case 512ULL: goto x86_l_200;
	case 518ULL: goto x86_l_206;
	case 523ULL: goto x86_l_20b;
	case 525ULL: goto x86_l_20d;
	case 530ULL: goto x86_l_212;
	case 535ULL: goto x86_l_217;
	case 540ULL: goto x86_l_21c;
	case 548ULL: goto x86_l_224;
	case 555ULL: goto x86_l_22b;
	case 558ULL: goto x86_l_22e;
	case 564ULL: goto x86_l_234;
	case 572ULL: goto x86_l_23c;
	case 575ULL: goto x86_l_23f;
	case 577ULL: goto x86_l_241;
	case 580ULL: goto x86_l_244;
	case 584ULL: goto x86_l_248;
	case 587ULL: goto x86_l_24b;
	case 590ULL: goto x86_l_24e;
	case 597ULL: goto x86_l_255;
	case 600ULL: goto x86_l_258;
	case 607ULL: goto x86_l_25f;
	case 610ULL: goto x86_l_262;
	case 612ULL: goto x86_l_264;
	case 614ULL: goto x86_l_266;
	case 619ULL: goto x86_l_26b;
	case 626ULL: goto x86_l_272;
	case 629ULL: goto x86_l_275;
	case 632ULL: goto x86_l_278;
	case 635ULL: goto x86_l_27b;
	case 642ULL: goto x86_l_282;
	case 645ULL: goto x86_l_285;
	case 648ULL: goto x86_l_288;
	case 655ULL: goto x86_l_28f;
	case 658ULL: goto x86_l_292;
	case 660ULL: goto x86_l_294;
	case 664ULL: goto x86_l_298;
	case 667ULL: goto x86_l_29b;
	case 670ULL: goto x86_l_29e;
	case 673ULL: goto x86_l_2a1;
	case 680ULL: goto x86_l_2a8;
	case 683ULL: goto x86_l_2ab;
	case 686ULL: goto x86_l_2ae;
	case 693ULL: goto x86_l_2b5;
	case 696ULL: goto x86_l_2b8;
	case 698ULL: goto x86_l_2ba;
	case 701ULL: goto x86_l_2bd;
	case 709ULL: goto x86_l_2c5;
	case 713ULL: goto x86_l_2c9;
	case 716ULL: goto x86_l_2cc;
	case 723ULL: goto x86_l_2d3;
	case 726ULL: goto x86_l_2d6;
	case 729ULL: goto x86_l_2d9;
	case 734ULL: goto x86_l_2de;
	case 741ULL: goto x86_l_2e5;
	case 744ULL: goto x86_l_2e8;
	case 749ULL: goto x86_l_2ed;
	case 755ULL: goto x86_l_2f3;
	case 763ULL: goto x86_l_2fb;
	case 770ULL: goto x86_l_302;
	case 778ULL: goto x86_l_30a;
	case 785ULL: goto x86_l_311;
	case 793ULL: goto x86_l_319;
	case 800ULL: goto x86_l_320;
	case 805ULL: goto x86_l_325;
	case 810ULL: goto x86_l_32a;
	case 815ULL: goto x86_l_32f;
	case 822ULL: goto x86_l_336;
	case 827ULL: goto x86_l_33b;
	case 829ULL: goto x86_l_33d;
	case 832ULL: goto x86_l_340;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 848ULL: goto x86_l_350;
	case 851ULL: goto x86_l_353;
	case 853ULL: goto x86_l_355;
	case 858ULL: goto x86_l_35a;
	case 863ULL: goto x86_l_35f;
	case 866ULL: goto x86_l_362;
	case 868ULL: goto x86_l_364;
	case 871ULL: goto x86_l_367;
	case 873ULL: goto x86_l_369;
	case 876ULL: goto x86_l_36c;
	case 880ULL: goto x86_l_370;
	case 883ULL: goto x86_l_373;
	case 885ULL: goto x86_l_375;
	case 887ULL: goto x86_l_377;
	case 892ULL: goto x86_l_37c;
	case 900ULL: goto x86_l_384;
	case 905ULL: goto x86_l_389;
	case 908ULL: goto x86_l_38c;
	case 911ULL: goto x86_l_38f;
	case 913ULL: goto x86_l_391;
	case 917ULL: goto x86_l_395;
	case 919ULL: goto x86_l_397;
	case 922ULL: goto x86_l_39a;
	case 924ULL: goto x86_l_39c;
	case 932ULL: goto x86_l_3a4;
	case 935ULL: goto x86_l_3a7;
	case 938ULL: goto x86_l_3aa;
	case 943ULL: goto x86_l_3af;
	case 950ULL: goto x86_l_3b6;
	case 953ULL: goto x86_l_3b9;
	case 955ULL: goto x86_l_3bb;
	case 958ULL: goto x86_l_3be;
	case 963ULL: goto x86_l_3c3;
	case 968ULL: goto x86_l_3c8;
	case 971ULL: goto x86_l_3cb;
	case 973ULL: goto x86_l_3cd;
	case 976ULL: goto x86_l_3d0;
	case 978ULL: goto x86_l_3d2;
	case 981ULL: goto x86_l_3d5;
	case 985ULL: goto x86_l_3d9;
	case 988ULL: goto x86_l_3dc;
	case 990ULL: goto x86_l_3de;
	case 997ULL: goto x86_l_3e5;
	case 1004ULL: goto x86_l_3ec;
	case 1007ULL: goto x86_l_3ef;
	case 1013ULL: goto x86_l_3f5;
	case 1018ULL: goto x86_l_3fa;
	case 1020ULL: goto x86_l_3fc;
	case 1028ULL: goto x86_l_404;
	case 1030ULL: goto x86_l_406;
	case 1032ULL: goto x86_l_408;
	case 1040ULL: goto x86_l_410;
	case 1045ULL: goto x86_l_415;
	case 1048ULL: goto x86_l_418;
	case 1051ULL: goto x86_l_41b;
	case 1056ULL: goto x86_l_420;
	case 1059ULL: goto x86_l_423;
	case 1061ULL: goto x86_l_425;
	case 1065ULL: goto x86_l_429;
	case 1067ULL: goto x86_l_42b;
	case 1070ULL: goto x86_l_42e;
	case 1072ULL: goto x86_l_430;
	case 1080ULL: goto x86_l_438;
	case 1083ULL: goto x86_l_43b;
	case 1086ULL: goto x86_l_43e;
	case 1089ULL: goto x86_l_441;
	case 1092ULL: goto x86_l_444;
	case 1100ULL: goto x86_l_44c;
	case 1106ULL: goto x86_l_452;
	case 1111ULL: goto x86_l_457;
	case 1113ULL: goto x86_l_459;
	case 1117ULL: goto x86_l_45d;
	case 1124ULL: goto x86_l_464;
	case 1131ULL: goto x86_l_46b;
	case 1136ULL: goto x86_l_470;
	case 1143ULL: goto x86_l_477;
	case 1150ULL: goto x86_l_47e;
	case 1155ULL: goto x86_l_483;
	case 1160ULL: goto x86_l_488;
	case 1165ULL: goto x86_l_48d;
	case 1172ULL: goto x86_l_494;
	case 1177ULL: goto x86_l_499;
	case 1179ULL: goto x86_l_49b;
	case 1183ULL: goto x86_l_49f;
	case 1188ULL: goto x86_l_4a4;
	case 1195ULL: goto x86_l_4ab;
	case 1198ULL: goto x86_l_4ae;
	case 1200ULL: goto x86_l_4b0;
	case 1205ULL: goto x86_l_4b5;
	case 1210ULL: goto x86_l_4ba;
	case 1213ULL: goto x86_l_4bd;
	case 1215ULL: goto x86_l_4bf;
	case 1218ULL: goto x86_l_4c2;
	case 1220ULL: goto x86_l_4c4;
	case 1223ULL: goto x86_l_4c7;
	case 1227ULL: goto x86_l_4cb;
	case 1230ULL: goto x86_l_4ce;
	case 1232ULL: goto x86_l_4d0;
	case 1234ULL: goto x86_l_4d2;
	case 1237ULL: goto x86_l_4d5;
	case 1242ULL: goto x86_l_4da;
	case 1245ULL: goto x86_l_4dd;
	case 1248ULL: goto x86_l_4e0;
	case 1250ULL: goto x86_l_4e2;
	case 1256ULL: goto x86_l_4e8;
	case 1258ULL: goto x86_l_4ea;
	case 1264ULL: goto x86_l_4f0;
	case 1266ULL: goto x86_l_4f2;
	case 1270ULL: goto x86_l_4f6;
	case 1276ULL: goto x86_l_4fc;
	case 1278ULL: goto x86_l_4fe;
	case 1281ULL: goto x86_l_501;
	case 1283ULL: goto x86_l_503;
	case 1288ULL: goto x86_l_508;
	case 1291ULL: goto x86_l_50b;
	case 1294ULL: goto x86_l_50e;
	case 1297ULL: goto x86_l_511;
	case 1305ULL: goto x86_l_519;
	case 1311ULL: goto x86_l_51f;
	case 1316ULL: goto x86_l_524;
	case 1323ULL: goto x86_l_52b;
	case 1328ULL: goto x86_l_530;
	case 1333ULL: goto x86_l_535;
	case 1338ULL: goto x86_l_53a;
	case 1340ULL: goto x86_l_53c;
	case 1345ULL: goto x86_l_541;
	case 1349ULL: goto x86_l_545;
	case 1354ULL: goto x86_l_54a;
	case 1359ULL: goto x86_l_54f;
	case 1364ULL: goto x86_l_554;
	case 1366ULL: goto x86_l_556;
	case 1371ULL: goto x86_l_55b;
	case 1376ULL: goto x86_l_560;
	case 1381ULL: goto x86_l_565;
	case 1386ULL: goto x86_l_56a;
	case 1388ULL: goto x86_l_56c;
	case 1392ULL: goto x86_l_570;
	case 1396ULL: goto x86_l_574;
	case 1403ULL: goto x86_l_57b;
	case 1410ULL: goto x86_l_582;
	case 1413ULL: goto x86_l_585;
	case 1419ULL: goto x86_l_58b;
	case 1424ULL: goto x86_l_590;
	case 1431ULL: goto x86_l_597;
	case 1436ULL: goto x86_l_59c;
	case 1438ULL: goto x86_l_59e;
	case 1445ULL: goto x86_l_5a5;
	case 1448ULL: goto x86_l_5a8;
	case 1450ULL: goto x86_l_5aa;
	case 1454ULL: goto x86_l_5ae;
	case 1459ULL: goto x86_l_5b3;
	case 1462ULL: goto x86_l_5b6;
	case 1464ULL: goto x86_l_5b8;
	case 1467ULL: goto x86_l_5bb;
	case 1469ULL: goto x86_l_5bd;
	case 1472ULL: goto x86_l_5c0;
	case 1476ULL: goto x86_l_5c4;
	case 1479ULL: goto x86_l_5c7;
	case 1481ULL: goto x86_l_5c9;
	case 1483ULL: goto x86_l_5cb;
	case 1486ULL: goto x86_l_5ce;
	case 1489ULL: goto x86_l_5d1;
	case 1492ULL: goto x86_l_5d4;
	case 1495ULL: goto x86_l_5d7;
	case 1503ULL: goto x86_l_5df;
	case 1509ULL: goto x86_l_5e5;
	case 1516ULL: goto x86_l_5ec;
	case 1520ULL: goto x86_l_5f0;
	case 1525ULL: goto x86_l_5f5;
	case 1530ULL: goto x86_l_5fa;
	case 1535ULL: goto x86_l_5ff;
	case 1537ULL: goto x86_l_601;
	case 1542ULL: goto x86_l_606;
	case 1547ULL: goto x86_l_60b;
	case 1552ULL: goto x86_l_610;
	case 1557ULL: goto x86_l_615;
	case 1560ULL: goto x86_l_618;
	case 1562ULL: goto x86_l_61a;
	case 1566ULL: goto x86_l_61e;
	case 1570ULL: goto x86_l_622;
	case 1574ULL: goto x86_l_626;
	case 1578ULL: goto x86_l_62a;
	case 1583ULL: goto x86_l_62f;
	case 1588ULL: goto x86_l_634;
	case 1593ULL: goto x86_l_639;
	case 1595ULL: goto x86_l_63b;
	case 1600ULL: goto x86_l_640;
	case 1604ULL: goto x86_l_644;
	case 1609ULL: goto x86_l_649;
	case 1614ULL: goto x86_l_64e;
	case 1619ULL: goto x86_l_653;
	case 1621ULL: goto x86_l_655;
	case 1625ULL: goto x86_l_659;
	case 1629ULL: goto x86_l_65d;
	case 1636ULL: goto x86_l_664;
	case 1643ULL: goto x86_l_66b;
	case 1646ULL: goto x86_l_66e;
	case 1652ULL: goto x86_l_674;
	case 1657ULL: goto x86_l_679;
	case 1664ULL: goto x86_l_680;
	case 1669ULL: goto x86_l_685;
	case 1671ULL: goto x86_l_687;
	case 1678ULL: goto x86_l_68e;
	case 1681ULL: goto x86_l_691;
	case 1683ULL: goto x86_l_693;
	case 1687ULL: goto x86_l_697;
	case 1692ULL: goto x86_l_69c;
	case 1695ULL: goto x86_l_69f;
	case 1697ULL: goto x86_l_6a1;
	case 1700ULL: goto x86_l_6a4;
	case 1702ULL: goto x86_l_6a6;
	case 1705ULL: goto x86_l_6a9;
	case 1709ULL: goto x86_l_6ad;
	case 1712ULL: goto x86_l_6b0;
	case 1714ULL: goto x86_l_6b2;
	case 1716ULL: goto x86_l_6b4;
	case 1719ULL: goto x86_l_6b7;
	case 1722ULL: goto x86_l_6ba;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_15:
	/* 0x15: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a:
	/* 0x1a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_21:
	/* 0x21: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26:
	/* 0x26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28:
	/* 0x28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: je     20b <syscall__execve_enter+0x20b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b;
	}
x86_l_31:
	/* 0x31: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_34:
	/* 0x34: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_39:
	/* 0x39: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_40:
	/* 0x40: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45:
	/* 0x45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47:
	/* 0x47: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a:
	/* 0x4a: je     20b <syscall__execve_enter+0x20b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b;
	}
x86_l_50:
	/* 0x50: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: lea    r15,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_57:
	/* 0x57: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c:
	/* 0x5c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
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
	/* 0x6b: je     20b <syscall__execve_enter+0x20b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b;
	}
x86_l_71:
	/* 0x71: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_74:
	/* 0x74: lea    rbp,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_78:
	/* 0x78: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7d:
	/* 0x7d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_84:
	/* 0x84: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_87:
	/* 0x87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89:
	/* 0x89: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8c:
	/* 0x8c: je     20b <syscall__execve_enter+0x20b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b;
	}
x86_l_92:
	/* 0x92: cmp    BYTE PTR [r13+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_9a:
	/* 0x9a: je     212 <syscall__execve_enter+0x212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_212;
	}
x86_l_a0:
	/* 0xa0: mov    QWORD PTR [rsp+0x98],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a8:
	/* 0xa8: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ab:
	/* 0xab: mov    rax,QWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b2:
	/* 0xb2: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b5:
	/* 0xb5: mov    DWORD PTR [r14+0x70],0x3b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337211ULL);
x86_l_bd:
	/* 0xbd: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_c7:
	/* 0xc7: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_cf:
	/* 0xcf: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_da:
	/* 0xda: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_e5:
	/* 0xe5: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_f0:
	/* 0xf0: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_fb:
	/* 0xfb: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_106:
	/* 0x106: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_111:
	/* 0x111: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_11c:
	/* 0x11c: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_127:
	/* 0x127: mov    QWORD PTR [r14+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_132:
	/* 0x132: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_137:
	/* 0x137: mov    DWORD PTR [rsp+0x10],0x3b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476795ULL);
x86_l_13f:
	/* 0x13f: mov    WORD PTR [rsp+0xc],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_144:
	/* 0x144: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_149:
	/* 0x149: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_150:
	/* 0x150: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_155:
	/* 0x155: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157:
	/* 0x157: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15a:
	/* 0x15a: je     20b <syscall__execve_enter+0x20b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b;
	}
x86_l_160:
	/* 0x160: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_165:
	/* 0x165: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16a:
	/* 0x16a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_16d:
	/* 0x16d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_16f:
	/* 0x16f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_172:
	/* 0x172: je     20b <syscall__execve_enter+0x20b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b;
	}
x86_l_178:
	/* 0x178: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17c:
	/* 0x17c: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_183:
	/* 0x183: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_186:
	/* 0x186: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_18d:
	/* 0x18d: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_194:
	/* 0x194: mov    rdx,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_198:
	/* 0x198: mov    QWORD PTR [r14+0x7e10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_19f:
	/* 0x19f: mov    rdx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a3:
	/* 0x1a3: mov    QWORD PTR [r14+0x7e08],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_1aa:
	/* 0x1aa: mov    rdx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ae:
	/* 0x1ae: mov    QWORD PTR [r14+0x7e00],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_1b5:
	/* 0x1b5: mov    rdx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b9:
	/* 0x1b9: mov    QWORD PTR [r14+0x7df8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_1c0:
	/* 0x1c0: mov    rdx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c4:
	/* 0x1c4: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c8:
	/* 0x1c8: mov    QWORD PTR [r14+0x7df0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_1cf:
	/* 0x1cf: mov    QWORD PTR [r14+0x7de8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_1d6:
	/* 0x1d6: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1da:
	/* 0x1da: cmp    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1de:
	/* 0x1de: mov    QWORD PTR [rsp+0x68],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e3:
	/* 0x1e3: mov    QWORD PTR [rsp+0x70],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e8:
	/* 0x1e8: mov    QWORD PTR [rsp+0xb0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1f0:
	/* 0x1f0: jne    21c <syscall__execve_enter+0x21c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21c;
	}
x86_l_1f2:
	/* 0x1f2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f4:
	/* 0x1f4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f6:
	/* 0x1f6: and    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1f9:
	/* 0x1f9: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_200:
	/* 0x200: jne    9c7 <syscall__execve_enter+0x9c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2503ULL;
	}
x86_l_206:
	/* 0x206: jmp    104b <syscall__execve_enter+0x104b> */
	return 4171ULL;
x86_l_20b:
	/* 0x20b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20d:
	/* 0x20d: jmp    104b <syscall__execve_enter+0x104b> */
	return 4171ULL;
x86_l_212:
	/* 0x212: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_217:
	/* 0x217: jmp    104b <syscall__execve_enter+0x104b> */
	return 4171ULL;
x86_l_21c:
	/* 0x21c: mov    QWORD PTR [rsp+0x80],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_224:
	/* 0x224: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_22b:
	/* 0x22b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22e:
	/* 0x22e: je     3de <syscall__execve_enter+0x3de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3de;
	}
x86_l_234:
	/* 0x234: movzx  ecx,BYTE PTR [r13+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_23c:
	/* 0x23c: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_23f:
	/* 0x23f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_241:
	/* 0x241: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_244:
	/* 0x244: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_248:
	/* 0x248: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_24b:
	/* 0x24b: neg    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_24e:
	/* 0x24e: xor    rbp,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_255:
	/* 0x255: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_258:
	/* 0x258: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_25f:
	/* 0x25f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_262:
	/* 0x262: je     288 <syscall__execve_enter+0x288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_288;
	}
x86_l_264:
	/* 0x264: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_266:
	/* 0x266: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_26b:
	/* 0x26b: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_272:
	/* 0x272: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_275:
	/* 0x275: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_278:
	/* 0x278: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_27b:
	/* 0x27b: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_282:
	/* 0x282: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_285:
	/* 0x285: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_288:
	/* 0x288: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_28f:
	/* 0x28f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_292:
	/* 0x292: je     2ae <syscall__execve_enter+0x2ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ae;
	}
x86_l_294:
	/* 0x294: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_298:
	/* 0x298: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_29b:
	/* 0x29b: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_29e:
	/* 0x29e: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_2a1:
	/* 0x2a1: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_2a8:
	/* 0x2a8: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2ab:
	/* 0x2ab: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2ae:
	/* 0x2ae: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_2b5:
	/* 0x2b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b8:
	/* 0x2b8: je     2d9 <syscall__execve_enter+0x2d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d9;
	}
x86_l_2ba:
	/* 0x2ba: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2bd:
	/* 0x2bd: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2c5:
	/* 0x2c5: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2c9:
	/* 0x2c9: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_2cc:
	/* 0x2cc: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_2d3:
	/* 0x2d3: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2d6:
	/* 0x2d6: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2d9:
	/* 0x2d9: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_2de:
	/* 0x2de: mov    rcx,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_2e5:
	/* 0x2e5: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2e8:
	/* 0x2e8: mov    WORD PTR [rsp+0x5e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_2ed:
	/* 0x2ed: je     444 <syscall__execve_enter+0x444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_444;
	}
x86_l_2f3:
	/* 0x2f3: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2fb:
	/* 0x2fb: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_302:
	/* 0x302: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_30a:
	/* 0x30a: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_311:
	/* 0x311: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_319:
	/* 0x319: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_320:
	/* 0x320: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_325:
	/* 0x325: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32a:
	/* 0x32a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32f:
	/* 0x32f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_336:
	/* 0x336: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33b:
	/* 0x33b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33d:
	/* 0x33d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_340:
	/* 0x340: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_344:
	/* 0x344: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_349:
	/* 0x349: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_350:
	/* 0x350: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_353:
	/* 0x353: je     375 <syscall__execve_enter+0x375> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_375;
	}
x86_l_355:
	/* 0x355: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35a:
	/* 0x35a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35f:
	/* 0x35f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_362:
	/* 0x362: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_364:
	/* 0x364: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_367:
	/* 0x367: je     375 <syscall__execve_enter+0x375> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_375;
	}
x86_l_369:
	/* 0x369: mov    rbx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36c:
	/* 0x36c: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_370:
	/* 0x370: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_373:
	/* 0x373: jmp    377 <syscall__execve_enter+0x377> */
	goto x86_l_377;
x86_l_375:
	/* 0x375: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_377:
	/* 0x377: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_37c:
	/* 0x37c: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_384:
	/* 0x384: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_389:
	/* 0x389: dec    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_38c:
	/* 0x38c: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_38f:
	/* 0x38f: jb     3a7 <syscall__execve_enter+0x3a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3a7;
	}
x86_l_391:
	/* 0x391: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_395:
	/* 0x395: je     39c <syscall__execve_enter+0x39c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39c;
	}
x86_l_397:
	/* 0x397: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_39a:
	/* 0x39a: jbe    3a7 <syscall__execve_enter+0x3a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3a7;
	}
x86_l_39c:
	/* 0x39c: and    r13,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_3a4:
	/* 0x3a4: or     rbx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_3a7:
	/* 0x3a7: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3aa:
	/* 0x3aa: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3af:
	/* 0x3af: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3b6:
	/* 0x3b6: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_3b9:
	/* 0x3b9: je     3fa <syscall__execve_enter+0x3fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fa;
	}
x86_l_3bb:
	/* 0x3bb: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_3be:
	/* 0x3be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c3:
	/* 0x3c3: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c8:
	/* 0x3c8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3cb:
	/* 0x3cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cd:
	/* 0x3cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d0:
	/* 0x3d0: je     406 <syscall__execve_enter+0x406> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_406;
	}
x86_l_3d2:
	/* 0x3d2: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d5:
	/* 0x3d5: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d9:
	/* 0x3d9: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_3dc:
	/* 0x3dc: jmp    408 <syscall__execve_enter+0x408> */
	goto x86_l_408;
x86_l_3de:
	/* 0x3de: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3e5:
	/* 0x3e5: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_3ec:
	/* 0x3ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ef:
	/* 0x3ef: jne    264 <syscall__execve_enter+0x264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_264;
	}
x86_l_3f5:
	/* 0x3f5: jmp    288 <syscall__execve_enter+0x288> */
	goto x86_l_288;
x86_l_3fa:
	/* 0x3fa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fc:
	/* 0x3fc: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_404:
	/* 0x404: jmp    418 <syscall__execve_enter+0x418> */
	goto x86_l_418;
x86_l_406:
	/* 0x406: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_408:
	/* 0x408: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_410:
	/* 0x410: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_415:
	/* 0x415: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_418:
	/* 0x418: not    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_41b:
	/* 0x41b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_420:
	/* 0x420: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_423:
	/* 0x423: jb     43b <syscall__execve_enter+0x43b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_43b;
	}
x86_l_425:
	/* 0x425: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_429:
	/* 0x429: je     430 <syscall__execve_enter+0x430> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430;
	}
x86_l_42b:
	/* 0x42b: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_42e:
	/* 0x42e: jbe    43b <syscall__execve_enter+0x43b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_43b;
	}
x86_l_430:
	/* 0x430: and    r15,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_438:
	/* 0x438: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_43b:
	/* 0x43b: or     rbx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_43e:
	/* 0x43e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_441:
	/* 0x441: and    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_444:
	/* 0x444: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_44c:
	/* 0x44c: je     4ea <syscall__execve_enter+0x4ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ea;
	}
x86_l_452:
	/* 0x452: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_457:
	/* 0x457: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_459:
	/* 0x459: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_45d:
	/* 0x45d: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_464:
	/* 0x464: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_46b:
	/* 0x46b: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_470:
	/* 0x470: mov    r13,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_477:
	/* 0x477: mov    r12,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_47e:
	/* 0x47e: movzx  eax,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_483:
	/* 0x483: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_488:
	/* 0x488: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_48d:
	/* 0x48d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_494:
	/* 0x494: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_499:
	/* 0x499: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49b:
	/* 0x49b: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_49f:
	/* 0x49f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a4:
	/* 0x4a4: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_4ab:
	/* 0x4ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4ae:
	/* 0x4ae: je     4d0 <syscall__execve_enter+0x4d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d0;
	}
x86_l_4b0:
	/* 0x4b0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4b5:
	/* 0x4b5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ba:
	/* 0x4ba: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4bd:
	/* 0x4bd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4bf:
	/* 0x4bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c2:
	/* 0x4c2: je     4d0 <syscall__execve_enter+0x4d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d0;
	}
x86_l_4c4:
	/* 0x4c4: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c7:
	/* 0x4c7: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cb:
	/* 0x4cb: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_4ce:
	/* 0x4ce: jmp    4d2 <syscall__execve_enter+0x4d2> */
	goto x86_l_4d2;
x86_l_4d0:
	/* 0x4d0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d2:
	/* 0x4d2: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_4d5:
	/* 0x4d5: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4da:
	/* 0x4da: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_4dd:
	/* 0x4dd: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_4e0:
	/* 0x4e0: jae    4f2 <syscall__execve_enter+0x4f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4f2;
	}
x86_l_4e2:
	/* 0x4e2: movzx  r13d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_4e8:
	/* 0x4e8: jmp    50b <syscall__execve_enter+0x50b> */
	goto x86_l_50b;
x86_l_4ea:
	/* 0x4ea: movzx  r13d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_4f0:
	/* 0x4f0: jmp    511 <syscall__execve_enter+0x511> */
	goto x86_l_511;
x86_l_4f2:
	/* 0x4f2: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_4f6:
	/* 0x4f6: movzx  r13d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_4fc:
	/* 0x4fc: je     503 <syscall__execve_enter+0x503> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_503;
	}
x86_l_4fe:
	/* 0x4fe: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_501:
	/* 0x501: jbe    50b <syscall__execve_enter+0x50b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_50b;
	}
x86_l_503:
	/* 0x503: and    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 96ULL);
x86_l_508:
	/* 0x508: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_50b:
	/* 0x50b: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_50e:
	/* 0x50e: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_511:
	/* 0x511: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_519:
	/* 0x519: je     5d7 <syscall__execve_enter+0x5d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d7;
	}
x86_l_51f:
	/* 0x51f: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_524:
	/* 0x524: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_52b:
	/* 0x52b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_530:
	/* 0x530: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_535:
	/* 0x535: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53a:
	/* 0x53a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53c:
	/* 0x53c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_541:
	/* 0x541: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_545:
	/* 0x545: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54a:
	/* 0x54a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54f:
	/* 0x54f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_554:
	/* 0x554: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_556:
	/* 0x556: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_55b:
	/* 0x55b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_560:
	/* 0x560: lea    rdi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_565:
	/* 0x565: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_56a:
	/* 0x56a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56c:
	/* 0x56c: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_570:
	/* 0x570: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_574:
	/* 0x574: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_57b:
	/* 0x57b: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_582:
	/* 0x582: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_585:
	/* 0x585: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_58b:
	/* 0x58b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_590:
	/* 0x590: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_597:
	/* 0x597: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59c:
	/* 0x59c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59e:
	/* 0x59e: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_5a5:
	/* 0x5a5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a8:
	/* 0x5a8: je     5c9 <syscall__execve_enter+0x5c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c9;
	}
x86_l_5aa:
	/* 0x5aa: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_5ae:
	/* 0x5ae: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5b3:
	/* 0x5b3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5b6:
	/* 0x5b6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5b8:
	/* 0x5b8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5bb:
	/* 0x5bb: je     5c9 <syscall__execve_enter+0x5c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c9;
	}
x86_l_5bd:
	/* 0x5bd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c0:
	/* 0x5c0: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c4:
	/* 0x5c4: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_5c7:
	/* 0x5c7: jmp    5cb <syscall__execve_enter+0x5cb> */
	goto x86_l_5cb;
x86_l_5c9:
	/* 0x5c9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cb:
	/* 0x5cb: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_5ce:
	/* 0x5ce: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_5d1:
	/* 0x5d1: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_5d4:
	/* 0x5d4: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_5d7:
	/* 0x5d7: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_5df:
	/* 0x5df: je     6c0 <syscall__execve_enter+0x6c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1728ULL;
	}
x86_l_5e5:
	/* 0x5e5: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_5ec:
	/* 0x5ec: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5f0:
	/* 0x5f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f5:
	/* 0x5f5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5fa:
	/* 0x5fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ff:
	/* 0x5ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_601:
	/* 0x601: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_606:
	/* 0x606: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60b:
	/* 0x60b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_610:
	/* 0x610: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_615:
	/* 0x615: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_618:
	/* 0x618: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61a:
	/* 0x61a: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61e:
	/* 0x61e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_622:
	/* 0x622: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_626:
	/* 0x626: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_62a:
	/* 0x62a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_62f:
	/* 0x62f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_634:
	/* 0x634: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_639:
	/* 0x639: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63b:
	/* 0x63b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_640:
	/* 0x640: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_644:
	/* 0x644: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_649:
	/* 0x649: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64e:
	/* 0x64e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_653:
	/* 0x653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_655:
	/* 0x655: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_659:
	/* 0x659: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_65d:
	/* 0x65d: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_664:
	/* 0x664: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_66b:
	/* 0x66b: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_66e:
	/* 0x66e: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_674:
	/* 0x674: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_679:
	/* 0x679: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_680:
	/* 0x680: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_685:
	/* 0x685: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_687:
	/* 0x687: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_68e:
	/* 0x68e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_691:
	/* 0x691: je     6b2 <syscall__execve_enter+0x6b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6b2;
	}
x86_l_693:
	/* 0x693: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_697:
	/* 0x697: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_69c:
	/* 0x69c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_69f:
	/* 0x69f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6a1:
	/* 0x6a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a4:
	/* 0x6a4: je     6b2 <syscall__execve_enter+0x6b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6b2;
	}
x86_l_6a6:
	/* 0x6a6: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a9:
	/* 0x6a9: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ad:
	/* 0x6ad: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_6b0:
	/* 0x6b0: jmp    6b4 <syscall__execve_enter+0x6b4> */
	goto x86_l_6b4;
x86_l_6b2:
	/* 0x6b2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b4:
	/* 0x6b4: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_6b7:
	/* 0x6b7: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_6ba:
	/* 0x6ba: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
	return 1725ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1725ULL: goto x86_l_6bd;
	case 1728ULL: goto x86_l_6c0;
	case 1736ULL: goto x86_l_6c8;
	case 1742ULL: goto x86_l_6ce;
	case 1747ULL: goto x86_l_6d3;
	case 1754ULL: goto x86_l_6da;
	case 1759ULL: goto x86_l_6df;
	case 1764ULL: goto x86_l_6e4;
	case 1769ULL: goto x86_l_6e9;
	case 1771ULL: goto x86_l_6eb;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1793ULL: goto x86_l_701;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1811ULL: goto x86_l_713;
	case 1816ULL: goto x86_l_718;
	case 1818ULL: goto x86_l_71a;
	case 1822ULL: goto x86_l_71e;
	case 1827ULL: goto x86_l_723;
	case 1830ULL: goto x86_l_726;
	case 1835ULL: goto x86_l_72b;
	case 1838ULL: goto x86_l_72e;
	case 1840ULL: goto x86_l_730;
	case 1847ULL: goto x86_l_737;
	case 1854ULL: goto x86_l_73e;
	case 1857ULL: goto x86_l_741;
	case 1863ULL: goto x86_l_747;
	case 1868ULL: goto x86_l_74c;
	case 1875ULL: goto x86_l_753;
	case 1880ULL: goto x86_l_758;
	case 1882ULL: goto x86_l_75a;
	case 1889ULL: goto x86_l_761;
	case 1892ULL: goto x86_l_764;
	case 1894ULL: goto x86_l_766;
	case 1899ULL: goto x86_l_76b;
	case 1902ULL: goto x86_l_76e;
	case 1905ULL: goto x86_l_771;
	case 1907ULL: goto x86_l_773;
	case 1910ULL: goto x86_l_776;
	case 1912ULL: goto x86_l_778;
	case 1915ULL: goto x86_l_77b;
	case 1919ULL: goto x86_l_77f;
	case 1922ULL: goto x86_l_782;
	case 1924ULL: goto x86_l_784;
	case 1926ULL: goto x86_l_786;
	case 1929ULL: goto x86_l_789;
	case 1932ULL: goto x86_l_78c;
	case 1935ULL: goto x86_l_78f;
	case 1938ULL: goto x86_l_792;
	case 1944ULL: goto x86_l_798;
	case 1952ULL: goto x86_l_7a0;
	case 1954ULL: goto x86_l_7a2;
	case 1958ULL: goto x86_l_7a6;
	case 1963ULL: goto x86_l_7ab;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1973ULL: goto x86_l_7b5;
	case 1980ULL: goto x86_l_7bc;
	case 1987ULL: goto x86_l_7c3;
	case 1990ULL: goto x86_l_7c6;
	case 1996ULL: goto x86_l_7cc;
	case 2001ULL: goto x86_l_7d1;
	case 2008ULL: goto x86_l_7d8;
	case 2013ULL: goto x86_l_7dd;
	case 2015ULL: goto x86_l_7df;
	case 2022ULL: goto x86_l_7e6;
	case 2025ULL: goto x86_l_7e9;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2035ULL: goto x86_l_7f3;
	case 2038ULL: goto x86_l_7f6;
	case 2040ULL: goto x86_l_7f8;
	case 2043ULL: goto x86_l_7fb;
	case 2045ULL: goto x86_l_7fd;
	case 2048ULL: goto x86_l_800;
	case 2052ULL: goto x86_l_804;
	case 2055ULL: goto x86_l_807;
	case 2057ULL: goto x86_l_809;
	case 2059ULL: goto x86_l_80b;
	case 2062ULL: goto x86_l_80e;
	case 2065ULL: goto x86_l_811;
	case 2068ULL: goto x86_l_814;
	case 2071ULL: goto x86_l_817;
	case 2077ULL: goto x86_l_81d;
	case 2084ULL: goto x86_l_824;
	case 2087ULL: goto x86_l_827;
	case 2089ULL: goto x86_l_829;
	case 2093ULL: goto x86_l_82d;
	case 2097ULL: goto x86_l_831;
	case 2104ULL: goto x86_l_838;
	case 2107ULL: goto x86_l_83b;
	case 2113ULL: goto x86_l_841;
	case 2118ULL: goto x86_l_846;
	case 2125ULL: goto x86_l_84d;
	case 2130ULL: goto x86_l_852;
	case 2132ULL: goto x86_l_854;
	case 2139ULL: goto x86_l_85b;
	case 2142ULL: goto x86_l_85e;
	case 2144ULL: goto x86_l_860;
	case 2149ULL: goto x86_l_865;
	case 2154ULL: goto x86_l_86a;
	case 2157ULL: goto x86_l_86d;
	case 2159ULL: goto x86_l_86f;
	case 2162ULL: goto x86_l_872;
	case 2164ULL: goto x86_l_874;
	case 2167ULL: goto x86_l_877;
	case 2171ULL: goto x86_l_87b;
	case 2174ULL: goto x86_l_87e;
	case 2176ULL: goto x86_l_880;
	case 2178ULL: goto x86_l_882;
	case 2181ULL: goto x86_l_885;
	case 2184ULL: goto x86_l_888;
	case 2187ULL: goto x86_l_88b;
	case 2190ULL: goto x86_l_88e;
	case 2197ULL: goto x86_l_895;
	case 2200ULL: goto x86_l_898;
	case 2202ULL: goto x86_l_89a;
	case 2209ULL: goto x86_l_8a1;
	case 2212ULL: goto x86_l_8a4;
	case 2218ULL: goto x86_l_8aa;
	case 2223ULL: goto x86_l_8af;
	case 2230ULL: goto x86_l_8b6;
	case 2235ULL: goto x86_l_8bb;
	case 2237ULL: goto x86_l_8bd;
	case 2244ULL: goto x86_l_8c4;
	case 2247ULL: goto x86_l_8c7;
	case 2249ULL: goto x86_l_8c9;
	case 2254ULL: goto x86_l_8ce;
	case 2257ULL: goto x86_l_8d1;
	case 2265ULL: goto x86_l_8d9;
	case 2267ULL: goto x86_l_8db;
	case 2270ULL: goto x86_l_8de;
	case 2272ULL: goto x86_l_8e0;
	case 2275ULL: goto x86_l_8e3;
	case 2279ULL: goto x86_l_8e7;
	case 2282ULL: goto x86_l_8ea;
	case 2284ULL: goto x86_l_8ec;
	case 2286ULL: goto x86_l_8ee;
	case 2289ULL: goto x86_l_8f1;
	case 2292ULL: goto x86_l_8f4;
	case 2295ULL: goto x86_l_8f7;
	case 2298ULL: goto x86_l_8fa;
	case 2305ULL: goto x86_l_901;
	case 2308ULL: goto x86_l_904;
	case 2314ULL: goto x86_l_90a;
	case 2321ULL: goto x86_l_911;
	case 2324ULL: goto x86_l_914;
	case 2330ULL: goto x86_l_91a;
	case 2335ULL: goto x86_l_91f;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2349ULL: goto x86_l_92d;
	case 2356ULL: goto x86_l_934;
	case 2359ULL: goto x86_l_937;
	case 2361ULL: goto x86_l_939;
	case 2364ULL: goto x86_l_93c;
	case 2372ULL: goto x86_l_944;
	case 2376ULL: goto x86_l_948;
	case 2381ULL: goto x86_l_94d;
	case 2384ULL: goto x86_l_950;
	case 2386ULL: goto x86_l_952;
	case 2389ULL: goto x86_l_955;
	case 2391ULL: goto x86_l_957;
	case 2399ULL: goto x86_l_95f;
	case 2403ULL: goto x86_l_963;
	case 2408ULL: goto x86_l_968;
	case 2411ULL: goto x86_l_96b;
	case 2413ULL: goto x86_l_96d;
	case 2416ULL: goto x86_l_970;
	case 2418ULL: goto x86_l_972;
	case 2421ULL: goto x86_l_975;
	case 2425ULL: goto x86_l_979;
	case 2428ULL: goto x86_l_97c;
	case 2430ULL: goto x86_l_97e;
	case 2432ULL: goto x86_l_980;
	case 2435ULL: goto x86_l_983;
	case 2438ULL: goto x86_l_986;
	case 2441ULL: goto x86_l_989;
	case 2444ULL: goto x86_l_98c;
	case 2451ULL: goto x86_l_993;
	case 2454ULL: goto x86_l_996;
	case 2456ULL: goto x86_l_998;
	case 2464ULL: goto x86_l_9a0;
	case 2468ULL: goto x86_l_9a4;
	case 2471ULL: goto x86_l_9a7;
	case 2473ULL: goto x86_l_9a9;
	case 2480ULL: goto x86_l_9b0;
	case 2487ULL: goto x86_l_9b7;
	case 2490ULL: goto x86_l_9ba;
	case 2497ULL: goto x86_l_9c1;
	case 2503ULL: goto x86_l_9c7;
	case 2510ULL: goto x86_l_9ce;
	case 2513ULL: goto x86_l_9d1;
	case 2519ULL: goto x86_l_9d7;
	case 2521ULL: goto x86_l_9d9;
	case 2526ULL: goto x86_l_9de;
	case 2531ULL: goto x86_l_9e3;
	case 2536ULL: goto x86_l_9e8;
	case 2541ULL: goto x86_l_9ed;
	case 2545ULL: goto x86_l_9f1;
	case 2554ULL: goto x86_l_9fa;
	case 2562ULL: goto x86_l_a02;
	case 2570ULL: goto x86_l_a0a;
	case 2576ULL: goto x86_l_a10;
	case 2581ULL: goto x86_l_a15;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2596ULL: goto x86_l_a24;
	case 2600ULL: goto x86_l_a28;
	case 2607ULL: goto x86_l_a2f;
	case 2612ULL: goto x86_l_a34;
	case 2614ULL: goto x86_l_a36;
	case 2616ULL: goto x86_l_a38;
	case 2618ULL: goto x86_l_a3a;
	case 2621ULL: goto x86_l_a3d;
	case 2628ULL: goto x86_l_a44;
	case 2630ULL: goto x86_l_a46;
	case 2638ULL: goto x86_l_a4e;
	case 2646ULL: goto x86_l_a56;
	case 2649ULL: goto x86_l_a59;
	case 2657ULL: goto x86_l_a61;
	case 2664ULL: goto x86_l_a68;
	case 2666ULL: goto x86_l_a6a;
	case 2668ULL: goto x86_l_a6c;
	case 2671ULL: goto x86_l_a6f;
	case 2674ULL: goto x86_l_a72;
	case 2679ULL: goto x86_l_a77;
	case 2685ULL: goto x86_l_a7d;
	case 2689ULL: goto x86_l_a81;
	case 2698ULL: goto x86_l_a8a;
	case 2706ULL: goto x86_l_a92;
	case 2710ULL: goto x86_l_a96;
	case 2718ULL: goto x86_l_a9e;
	case 2727ULL: goto x86_l_aa7;
	case 2732ULL: goto x86_l_aac;
	case 2737ULL: goto x86_l_ab1;
	case 2742ULL: goto x86_l_ab6;
	case 2745ULL: goto x86_l_ab9;
	case 2747ULL: goto x86_l_abb;
	case 2753ULL: goto x86_l_ac1;
	case 2755ULL: goto x86_l_ac3;
	case 2758ULL: goto x86_l_ac6;
	case 2763ULL: goto x86_l_acb;
	case 2765ULL: goto x86_l_acd;
	case 2770ULL: goto x86_l_ad2;
	case 2778ULL: goto x86_l_ada;
	case 2782ULL: goto x86_l_ade;
	case 2789ULL: goto x86_l_ae5;
	case 2794ULL: goto x86_l_aea;
	case 2799ULL: goto x86_l_aef;
	case 2801ULL: goto x86_l_af1;
	case 2805ULL: goto x86_l_af5;
	case 2807ULL: goto x86_l_af7;
	case 2809ULL: goto x86_l_af9;
	case 2812ULL: goto x86_l_afc;
	case 2817ULL: goto x86_l_b01;
	case 2823ULL: goto x86_l_b07;
	case 2825ULL: goto x86_l_b09;
	case 2830ULL: goto x86_l_b0e;
	case 2837ULL: goto x86_l_b15;
	case 2842ULL: goto x86_l_b1a;
	case 2844ULL: goto x86_l_b1c;
	case 2852ULL: goto x86_l_b24;
	case 2859ULL: goto x86_l_b2b;
	case 2865ULL: goto x86_l_b31;
	case 2871ULL: goto x86_l_b37;
	case 2874ULL: goto x86_l_b3a;
	case 2880ULL: goto x86_l_b40;
	case 2886ULL: goto x86_l_b46;
	case 2893ULL: goto x86_l_b4d;
	case 2902ULL: goto x86_l_b56;
	case 2910ULL: goto x86_l_b5e;
	case 2914ULL: goto x86_l_b62;
	case 2922ULL: goto x86_l_b6a;
	case 2931ULL: goto x86_l_b73;
	case 2936ULL: goto x86_l_b78;
	case 2941ULL: goto x86_l_b7d;
	case 2946ULL: goto x86_l_b82;
	case 2949ULL: goto x86_l_b85;
	case 2951ULL: goto x86_l_b87;
	case 2957ULL: goto x86_l_b8d;
	case 2959ULL: goto x86_l_b8f;
	case 2962ULL: goto x86_l_b92;
	case 2967ULL: goto x86_l_b97;
	case 2969ULL: goto x86_l_b99;
	case 2974ULL: goto x86_l_b9e;
	case 2982ULL: goto x86_l_ba6;
	case 2986ULL: goto x86_l_baa;
	case 2993ULL: goto x86_l_bb1;
	case 2998ULL: goto x86_l_bb6;
	case 3003ULL: goto x86_l_bbb;
	case 3005ULL: goto x86_l_bbd;
	case 3009ULL: goto x86_l_bc1;
	case 3011ULL: goto x86_l_bc3;
	case 3013ULL: goto x86_l_bc5;
	case 3016ULL: goto x86_l_bc8;
	case 3021ULL: goto x86_l_bcd;
	case 3027ULL: goto x86_l_bd3;
	case 3029ULL: goto x86_l_bd5;
	case 3036ULL: goto x86_l_bdc;
	case 3038ULL: goto x86_l_bde;
	case 3046ULL: goto x86_l_be6;
	case 3053ULL: goto x86_l_bed;
	case 3060ULL: goto x86_l_bf4;
	case 3064ULL: goto x86_l_bf8;
	case 3069ULL: goto x86_l_bfd;
	case 3074ULL: goto x86_l_c02;
	case 3079ULL: goto x86_l_c07;
	case 3082ULL: goto x86_l_c0a;
	case 3084ULL: goto x86_l_c0c;
	case 3089ULL: goto x86_l_c11;
	case 3097ULL: goto x86_l_c19;
	case 3101ULL: goto x86_l_c1d;
	case 3106ULL: goto x86_l_c22;
	case 3111ULL: goto x86_l_c27;
	case 3116ULL: goto x86_l_c2c;
	case 3118ULL: goto x86_l_c2e;
	case 3123ULL: goto x86_l_c33;
	case 3127ULL: goto x86_l_c37;
	case 3132ULL: goto x86_l_c3c;
	case 3137ULL: goto x86_l_c41;
	case 3142ULL: goto x86_l_c46;
	case 3144ULL: goto x86_l_c48;
	case 3149ULL: goto x86_l_c4d;
	case 3153ULL: goto x86_l_c51;
	case 3158ULL: goto x86_l_c56;
	case 3163ULL: goto x86_l_c5b;
	case 3168ULL: goto x86_l_c60;
	case 3170ULL: goto x86_l_c62;
	case 3174ULL: goto x86_l_c66;
	case 3178ULL: goto x86_l_c6a;
	case 3182ULL: goto x86_l_c6e;
	case 3187ULL: goto x86_l_c73;
	case 3192ULL: goto x86_l_c78;
	case 3197ULL: goto x86_l_c7d;
	case 3200ULL: goto x86_l_c80;
	case 3202ULL: goto x86_l_c82;
	case 3207ULL: goto x86_l_c87;
	case 3212ULL: goto x86_l_c8c;
	case 3217ULL: goto x86_l_c91;
	case 3222ULL: goto x86_l_c96;
	case 3225ULL: goto x86_l_c99;
	case 3227ULL: goto x86_l_c9b;
	case 3231ULL: goto x86_l_c9f;
	case 3235ULL: goto x86_l_ca3;
	case 3239ULL: goto x86_l_ca7;
	case 3243ULL: goto x86_l_cab;
	case 3248ULL: goto x86_l_cb0;
	case 3253ULL: goto x86_l_cb5;
	case 3258ULL: goto x86_l_cba;
	case 3260ULL: goto x86_l_cbc;
	case 3264ULL: goto x86_l_cc0;
	case 3268ULL: goto x86_l_cc4;
	case 3273ULL: goto x86_l_cc9;
	case 3278ULL: goto x86_l_cce;
	case 3283ULL: goto x86_l_cd3;
	case 3286ULL: goto x86_l_cd6;
	case 3288ULL: goto x86_l_cd8;
	case 3293ULL: goto x86_l_cdd;
	case 3297ULL: goto x86_l_ce1;
	case 3302ULL: goto x86_l_ce6;
	case 3307ULL: goto x86_l_ceb;
	case 3312ULL: goto x86_l_cf0;
	case 3314ULL: goto x86_l_cf2;
	case 3319ULL: goto x86_l_cf7;
	case 3324ULL: goto x86_l_cfc;
	case 3329ULL: goto x86_l_d01;
	case 3334ULL: goto x86_l_d06;
	case 3337ULL: goto x86_l_d09;
	case 3339ULL: goto x86_l_d0b;
	case 3343ULL: goto x86_l_d0f;
	case 3347ULL: goto x86_l_d13;
	case 3351ULL: goto x86_l_d17;
	case 3355ULL: goto x86_l_d1b;
	case 3360ULL: goto x86_l_d20;
	case 3365ULL: goto x86_l_d25;
	case 3370ULL: goto x86_l_d2a;
	case 3372ULL: goto x86_l_d2c;
	case 3376ULL: goto x86_l_d30;
	case 3380ULL: goto x86_l_d34;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6bd:
	/* 0x6bd: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_6c0:
	/* 0x6c0: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_6c8:
	/* 0x6c8: je     798 <syscall__execve_enter+0x798> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_798;
	}
x86_l_6ce:
	/* 0x6ce: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_6d3:
	/* 0x6d3: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_6da:
	/* 0x6da: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6df:
	/* 0x6df: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6e4:
	/* 0x6e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6e9:
	/* 0x6e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6eb:
	/* 0x6eb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f0:
	/* 0x6f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6f5:
	/* 0x6f5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6fa:
	/* 0x6fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ff:
	/* 0x6ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_701:
	/* 0x701: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_706:
	/* 0x706: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_70b:
	/* 0x70b: lea    r12,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_710:
	/* 0x710: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_713:
	/* 0x713: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_718:
	/* 0x718: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71a:
	/* 0x71a: lea    r15,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_71e:
	/* 0x71e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_723:
	/* 0x723: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_726:
	/* 0x726: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_72b:
	/* 0x72b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_72e:
	/* 0x72e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_730:
	/* 0x730: mov    rbx,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_737:
	/* 0x737: mov    r12,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_73e:
	/* 0x73e: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_741:
	/* 0x741: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_747:
	/* 0x747: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_74c:
	/* 0x74c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_753:
	/* 0x753: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_758:
	/* 0x758: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75a:
	/* 0x75a: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_761:
	/* 0x761: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_764:
	/* 0x764: je     784 <syscall__execve_enter+0x784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_784;
	}
x86_l_766:
	/* 0x766: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_76b:
	/* 0x76b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_76e:
	/* 0x76e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_771:
	/* 0x771: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_773:
	/* 0x773: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_776:
	/* 0x776: je     784 <syscall__execve_enter+0x784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_784;
	}
x86_l_778:
	/* 0x778: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77b:
	/* 0x77b: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_77f:
	/* 0x77f: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_782:
	/* 0x782: jmp    786 <syscall__execve_enter+0x786> */
	goto x86_l_786;
x86_l_784:
	/* 0x784: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_786:
	/* 0x786: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_789:
	/* 0x789: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_78c:
	/* 0x78c: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_78f:
	/* 0x78f: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_792:
	/* 0x792: movzx  r13d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_798:
	/* 0x798: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_7a0:
	/* 0x7a0: je     81d <syscall__execve_enter+0x81d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_81d;
	}
x86_l_7a2:
	/* 0x7a2: lea    r15,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_7a6:
	/* 0x7a6: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_7ab:
	/* 0x7ab: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7ae:
	/* 0x7ae: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_7b3:
	/* 0x7b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b5:
	/* 0x7b5: mov    rbx,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_7bc:
	/* 0x7bc: mov    r12,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_7c3:
	/* 0x7c3: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_7c6:
	/* 0x7c6: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7cc:
	/* 0x7cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7d1:
	/* 0x7d1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_7d8:
	/* 0x7d8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7dd:
	/* 0x7dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7df:
	/* 0x7df: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_7e6:
	/* 0x7e6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7e9:
	/* 0x7e9: je     809 <syscall__execve_enter+0x809> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_809;
	}
x86_l_7eb:
	/* 0x7eb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7f0:
	/* 0x7f0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_7f3:
	/* 0x7f3: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_7f6:
	/* 0x7f6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7f8:
	/* 0x7f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7fb:
	/* 0x7fb: je     809 <syscall__execve_enter+0x809> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_809;
	}
x86_l_7fd:
	/* 0x7fd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_800:
	/* 0x800: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_804:
	/* 0x804: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_807:
	/* 0x807: jmp    80b <syscall__execve_enter+0x80b> */
	goto x86_l_80b;
x86_l_809:
	/* 0x809: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_80b:
	/* 0x80b: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_80e:
	/* 0x80e: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_811:
	/* 0x811: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_814:
	/* 0x814: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_817:
	/* 0x817: movzx  r13d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_81d:
	/* 0x81d: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_824:
	/* 0x824: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_827:
	/* 0x827: je     88e <syscall__execve_enter+0x88e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_88e;
	}
x86_l_829:
	/* 0x829: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_82d:
	/* 0x82d: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_831:
	/* 0x831: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_838:
	/* 0x838: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_83b:
	/* 0x83b: mov    WORD PTR [rsp+0xc],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_841:
	/* 0x841: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_846:
	/* 0x846: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_84d:
	/* 0x84d: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_852:
	/* 0x852: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_854:
	/* 0x854: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_85b:
	/* 0x85b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_85e:
	/* 0x85e: je     880 <syscall__execve_enter+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_880;
	}
x86_l_860:
	/* 0x860: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_865:
	/* 0x865: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_86a:
	/* 0x86a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_86d:
	/* 0x86d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_86f:
	/* 0x86f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_872:
	/* 0x872: je     880 <syscall__execve_enter+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_880;
	}
x86_l_874:
	/* 0x874: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_877:
	/* 0x877: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_87b:
	/* 0x87b: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_87e:
	/* 0x87e: jmp    882 <syscall__execve_enter+0x882> */
	goto x86_l_882;
x86_l_880:
	/* 0x880: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_882:
	/* 0x882: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_885:
	/* 0x885: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_888:
	/* 0x888: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_88b:
	/* 0x88b: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_88e:
	/* 0x88e: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_895:
	/* 0x895: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_898:
	/* 0x898: je     8fa <syscall__execve_enter+0x8fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8fa;
	}
x86_l_89a:
	/* 0x89a: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_8a1:
	/* 0x8a1: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_8a4:
	/* 0x8a4: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8aa:
	/* 0x8aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8af:
	/* 0x8af: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_8b6:
	/* 0x8b6: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8bb:
	/* 0x8bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8bd:
	/* 0x8bd: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_8c4:
	/* 0x8c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8c7:
	/* 0x8c7: je     8ec <syscall__execve_enter+0x8ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ec;
	}
x86_l_8c9:
	/* 0x8c9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8ce:
	/* 0x8ce: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_8d1:
	/* 0x8d1: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8d9:
	/* 0x8d9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_8db:
	/* 0x8db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8de:
	/* 0x8de: je     8ec <syscall__execve_enter+0x8ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ec;
	}
x86_l_8e0:
	/* 0x8e0: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8e3:
	/* 0x8e3: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8e7:
	/* 0x8e7: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_8ea:
	/* 0x8ea: jmp    8ee <syscall__execve_enter+0x8ee> */
	goto x86_l_8ee;
x86_l_8ec:
	/* 0x8ec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ee:
	/* 0x8ee: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_8f1:
	/* 0x8f1: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_8f4:
	/* 0x8f4: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_8f7:
	/* 0x8f7: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_8fa:
	/* 0x8fa: mov    r15,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_901:
	/* 0x901: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_904:
	/* 0x904: je     98c <syscall__execve_enter+0x98c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98c;
	}
x86_l_90a:
	/* 0x90a: mov    r12,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_911:
	/* 0x911: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_914:
	/* 0x914: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_91a:
	/* 0x91a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_91f:
	/* 0x91f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_926:
	/* 0x926: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_92b:
	/* 0x92b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92d:
	/* 0x92d: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_934:
	/* 0x934: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_937:
	/* 0x937: je     97e <syscall__execve_enter+0x97e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_97e;
	}
x86_l_939:
	/* 0x939: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_93c:
	/* 0x93c: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_944:
	/* 0x944: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_948:
	/* 0x948: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_94d:
	/* 0x94d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_950:
	/* 0x950: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_952:
	/* 0x952: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_955:
	/* 0x955: jne    972 <syscall__execve_enter+0x972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_972;
	}
x86_l_957:
	/* 0x957: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_95f:
	/* 0x95f: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_963:
	/* 0x963: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_968:
	/* 0x968: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_96b:
	/* 0x96b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96d:
	/* 0x96d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_970:
	/* 0x970: je     97e <syscall__execve_enter+0x97e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_97e;
	}
x86_l_972:
	/* 0x972: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_975:
	/* 0x975: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_979:
	/* 0x979: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_97c:
	/* 0x97c: jmp    980 <syscall__execve_enter+0x980> */
	goto x86_l_980;
x86_l_97e:
	/* 0x97e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_980:
	/* 0x980: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_983:
	/* 0x983: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_986:
	/* 0x986: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_989:
	/* 0x989: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_98c:
	/* 0x98c: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_993:
	/* 0x993: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_996:
	/* 0x996: je     9a7 <syscall__execve_enter+0x9a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9a7;
	}
x86_l_998:
	/* 0x998: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9a0:
	/* 0x9a0: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_9a4:
	/* 0x9a4: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_9a7:
	/* 0x9a7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9a9:
	/* 0x9a9: and    rbp,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_9b0:
	/* 0x9b0: mov    rcx,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9b7:
	/* 0x9b7: and    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_9ba:
	/* 0x9ba: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9c1:
	/* 0x9c1: je     104b <syscall__execve_enter+0x104b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4171ULL;
	}
x86_l_9c7:
	/* 0x9c7: lea    rbx,[r14+0x7d8a] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_9ce:
	/* 0x9ce: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_9d1:
	/* 0x9d1: cmp    rax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32000ULL);
x86_l_9d7:
	/* 0x9d7: jb     9e8 <syscall__execve_enter+0x9e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9e8;
	}
x86_l_9d9:
	/* 0x9d9: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9de:
	/* 0x9de: mov    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9e3:
	/* 0x9e3: jmp    b2b <syscall__execve_enter+0xb2b> */
	goto x86_l_b2b;
x86_l_9e8:
	/* 0x9e8: mov    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9ed:
	/* 0x9ed: mov    rdx,QWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9f1:
	/* 0x9f1: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_9fa:
	/* 0x9fa: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_a02:
	/* 0xa02: mov    WORD PTR [r14+0x7d8c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_a0a:
	/* 0xa0a: cmp    ecx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27899ULL);
x86_l_a10:
	/* 0xa10: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a15:
	/* 0xa15: ja     a6f <syscall__execve_enter+0xa6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a6f;
	}
x86_l_a17:
	/* 0xa17: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_a1c:
	/* 0xa1c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_a24:
	/* 0xa24: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_a28:
	/* 0xa28: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_a2f:
	/* 0xa2f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_a34:
	/* 0xa34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a36:
	/* 0xa36: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a38:
	/* 0xa38: jle    a6c <syscall__execve_enter+0xa6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_a6c;
	}
x86_l_a3a:
	/* 0xa3a: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a3d:
	/* 0xa3d: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_a44:
	/* 0xa44: ja     a6f <syscall__execve_enter+0xa6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a6f;
	}
x86_l_a46:
	/* 0xa46: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_a4e:
	/* 0xa4e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_a56:
	/* 0xa56: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_a59:
	/* 0xa59: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_a61:
	/* 0xa61: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_a68:
	/* 0xa68: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_a6a:
	/* 0xa6a: jmp    a6f <syscall__execve_enter+0xa6f> */
	goto x86_l_a6f;
x86_l_a6c:
	/* 0xa6c: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a6f:
	/* 0xa6f: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_a72:
	/* 0xa72: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_a77:
	/* 0xa77: ja     b2b <syscall__execve_enter+0xb2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b2b;
	}
x86_l_a7d:
	/* 0xa7d: mov    r13,QWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a81:
	/* 0xa81: mov    BYTE PTR [r14+rax*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519553ULL);
x86_l_a8a:
	/* 0xa8a: movzx  r15d,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_a92:
	/* 0xa92: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_a96:
	/* 0xa96: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_a9e:
	/* 0xa9e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_aa7:
	/* 0xaa7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_aac:
	/* 0xaac: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ab1:
	/* 0xab1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ab6:
	/* 0xab6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ab9:
	/* 0xab9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abb:
	/* 0xabb: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_ac1:
	/* 0xac1: je     b07 <syscall__execve_enter+0xb07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b07;
	}
x86_l_ac3:
	/* 0xac3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ac6:
	/* 0xac6: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_acb:
	/* 0xacb: ja     b07 <syscall__execve_enter+0xb07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b07;
	}
x86_l_acd:
	/* 0xacd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_ad2:
	/* 0xad2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_ada:
	/* 0xada: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_ade:
	/* 0xade: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_ae5:
	/* 0xae5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aea:
	/* 0xaea: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_aef:
	/* 0xaef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af1:
	/* 0xaf1: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_af5:
	/* 0xaf5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_af7:
	/* 0xaf7: jle    b07 <syscall__execve_enter+0xb07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_b07;
	}
x86_l_af9:
	/* 0xaf9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_afc:
	/* 0xafc: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_b01:
	/* 0xb01: jbe    105a <syscall__execve_enter+0x105a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4186ULL;
	}
x86_l_b07:
	/* 0xb07: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b09:
	/* 0xb09: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b0e:
	/* 0xb0e: cmp    r15d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31998ULL);
x86_l_b15:
	/* 0xb15: mov    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b1a:
	/* 0xb1a: ja     b2b <syscall__execve_enter+0xb2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b2b;
	}
x86_l_b1c:
	/* 0xb1c: mov    BYTE PTR [r14+r15*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_b24:
	/* 0xb24: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_b2b:
	/* 0xb2b: test   BYTE PTR [r12+0x4],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869185ULL);
x86_l_b31:
	/* 0xb31: je     bed <syscall__execve_enter+0xbed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bed;
	}
x86_l_b37:
	/* 0xb37: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b3a:
	/* 0xb3a: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_b40:
	/* 0xb40: ja     bed <syscall__execve_enter+0xbed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bed;
	}
x86_l_b46:
	/* 0xb46: mov    r13,QWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b4d:
	/* 0xb4d: mov    BYTE PTR [r14+rax*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519554ULL);
x86_l_b56:
	/* 0xb56: movzx  r15d,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_b5e:
	/* 0xb5e: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_b62:
	/* 0xb62: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_b6a:
	/* 0xb6a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_b73:
	/* 0xb73: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b78:
	/* 0xb78: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b7d:
	/* 0xb7d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b82:
	/* 0xb82: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b85:
	/* 0xb85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b87:
	/* 0xb87: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_b8d:
	/* 0xb8d: je     bd3 <syscall__execve_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bd3;
	}
x86_l_b8f:
	/* 0xb8f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b92:
	/* 0xb92: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_b97:
	/* 0xb97: ja     bd3 <syscall__execve_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bd3;
	}
x86_l_b99:
	/* 0xb99: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_b9e:
	/* 0xb9e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_ba6:
	/* 0xba6: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_baa:
	/* 0xbaa: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_bb1:
	/* 0xbb1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bb6:
	/* 0xbb6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_bbb:
	/* 0xbbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbd:
	/* 0xbbd: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_bc1:
	/* 0xbc1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bc3:
	/* 0xbc3: jle    bd3 <syscall__execve_enter+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_bd3;
	}
x86_l_bc5:
	/* 0xbc5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_bc8:
	/* 0xbc8: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_bcd:
	/* 0xbcd: jbe    2bce <syscall__execve_enter+0x2bce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11214ULL;
	}
x86_l_bd3:
	/* 0xbd3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd5:
	/* 0xbd5: cmp    r15d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31998ULL);
x86_l_bdc:
	/* 0xbdc: ja     bed <syscall__execve_enter+0xbed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bed;
	}
x86_l_bde:
	/* 0xbde: mov    BYTE PTR [r14+r15*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_be6:
	/* 0xbe6: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_bed:
	/* 0xbed: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_bf4:
	/* 0xbf4: lea    r12,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bf8:
	/* 0xbf8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bfd:
	/* 0xbfd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c02:
	/* 0xc02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c07:
	/* 0xc07: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_c0a:
	/* 0xc0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c0c:
	/* 0xc0c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c11:
	/* 0xc11: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c19:
	/* 0xc19: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c1d:
	/* 0xc1d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c22:
	/* 0xc22: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c27:
	/* 0xc27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c2c:
	/* 0xc2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2e:
	/* 0xc2e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c33:
	/* 0xc33: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_c37:
	/* 0xc37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c3c:
	/* 0xc3c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c41:
	/* 0xc41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c46:
	/* 0xc46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c48:
	/* 0xc48: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c4d:
	/* 0xc4d: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c51:
	/* 0xc51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c56:
	/* 0xc56: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c5b:
	/* 0xc5b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c60:
	/* 0xc60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c62:
	/* 0xc62: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c66:
	/* 0xc66: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_c6a:
	/* 0xc6a: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c6e:
	/* 0xc6e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c73:
	/* 0xc73: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c78:
	/* 0xc78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c7d:
	/* 0xc7d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_c80:
	/* 0xc80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c82:
	/* 0xc82: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c87:
	/* 0xc87: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c8c:
	/* 0xc8c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c91:
	/* 0xc91: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c96:
	/* 0xc96: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c99:
	/* 0xc99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9b:
	/* 0xc9b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c9f:
	/* 0xc9f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_ca3:
	/* 0xca3: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_ca7:
	/* 0xca7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_cab:
	/* 0xcab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cb0:
	/* 0xcb0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cb5:
	/* 0xcb5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cba:
	/* 0xcba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cbc:
	/* 0xcbc: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cc0:
	/* 0xcc0: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_cc4:
	/* 0xcc4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cc9:
	/* 0xcc9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cce:
	/* 0xcce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cd3:
	/* 0xcd3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_cd6:
	/* 0xcd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd8:
	/* 0xcd8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cdd:
	/* 0xcdd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ce1:
	/* 0xce1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ce6:
	/* 0xce6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ceb:
	/* 0xceb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cf0:
	/* 0xcf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf2:
	/* 0xcf2: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cf7:
	/* 0xcf7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cfc:
	/* 0xcfc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d01:
	/* 0xd01: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d06:
	/* 0xd06: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d09:
	/* 0xd09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d0b:
	/* 0xd0b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d0f:
	/* 0xd0f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_d13:
	/* 0xd13: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_d17:
	/* 0xd17: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d1b:
	/* 0xd1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d20:
	/* 0xd20: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d25:
	/* 0xd25: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d2a:
	/* 0xd2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2c:
	/* 0xd2c: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d30:
	/* 0xd30: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d34:
	/* 0xd34: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 3385ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3385ULL: goto x86_l_d39;
	case 3390ULL: goto x86_l_d3e;
	case 3395ULL: goto x86_l_d43;
	case 3398ULL: goto x86_l_d46;
	case 3400ULL: goto x86_l_d48;
	case 3405ULL: goto x86_l_d4d;
	case 3410ULL: goto x86_l_d52;
	case 3415ULL: goto x86_l_d57;
	case 3420ULL: goto x86_l_d5c;
	case 3423ULL: goto x86_l_d5f;
	case 3425ULL: goto x86_l_d61;
	case 3429ULL: goto x86_l_d65;
	case 3433ULL: goto x86_l_d69;
	case 3437ULL: goto x86_l_d6d;
	case 3441ULL: goto x86_l_d71;
	case 3446ULL: goto x86_l_d76;
	case 3451ULL: goto x86_l_d7b;
	case 3456ULL: goto x86_l_d80;
	case 3458ULL: goto x86_l_d82;
	case 3463ULL: goto x86_l_d87;
	case 3467ULL: goto x86_l_d8b;
	case 3472ULL: goto x86_l_d90;
	case 3477ULL: goto x86_l_d95;
	case 3482ULL: goto x86_l_d9a;
	case 3484ULL: goto x86_l_d9c;
	case 3489ULL: goto x86_l_da1;
	case 3493ULL: goto x86_l_da5;
	case 3498ULL: goto x86_l_daa;
	case 3503ULL: goto x86_l_daf;
	case 3508ULL: goto x86_l_db4;
	case 3511ULL: goto x86_l_db7;
	case 3513ULL: goto x86_l_db9;
	case 3518ULL: goto x86_l_dbe;
	case 3523ULL: goto x86_l_dc3;
	case 3528ULL: goto x86_l_dc8;
	case 3533ULL: goto x86_l_dcd;
	case 3536ULL: goto x86_l_dd0;
	case 3538ULL: goto x86_l_dd2;
	case 3542ULL: goto x86_l_dd6;
	case 3546ULL: goto x86_l_dda;
	case 3550ULL: goto x86_l_dde;
	case 3554ULL: goto x86_l_de2;
	case 3559ULL: goto x86_l_de7;
	case 3564ULL: goto x86_l_dec;
	case 3569ULL: goto x86_l_df1;
	case 3571ULL: goto x86_l_df3;
	case 3576ULL: goto x86_l_df8;
	case 3580ULL: goto x86_l_dfc;
	case 3585ULL: goto x86_l_e01;
	case 3590ULL: goto x86_l_e06;
	case 3595ULL: goto x86_l_e0b;
	case 3597ULL: goto x86_l_e0d;
	case 3602ULL: goto x86_l_e12;
	case 3604ULL: goto x86_l_e14;
	case 3609ULL: goto x86_l_e19;
	case 3614ULL: goto x86_l_e1e;
	case 3619ULL: goto x86_l_e23;
	case 3622ULL: goto x86_l_e26;
	case 3624ULL: goto x86_l_e28;
	case 3629ULL: goto x86_l_e2d;
	case 3634ULL: goto x86_l_e32;
	case 3639ULL: goto x86_l_e37;
	case 3644ULL: goto x86_l_e3c;
	case 3647ULL: goto x86_l_e3f;
	case 3649ULL: goto x86_l_e41;
	case 3653ULL: goto x86_l_e45;
	case 3657ULL: goto x86_l_e49;
	case 3661ULL: goto x86_l_e4d;
	case 3665ULL: goto x86_l_e51;
	case 3670ULL: goto x86_l_e56;
	case 3675ULL: goto x86_l_e5b;
	case 3680ULL: goto x86_l_e60;
	case 3682ULL: goto x86_l_e62;
	case 3686ULL: goto x86_l_e66;
	case 3690ULL: goto x86_l_e6a;
	case 3694ULL: goto x86_l_e6e;
	case 3698ULL: goto x86_l_e72;
	case 3705ULL: goto x86_l_e79;
	case 3710ULL: goto x86_l_e7e;
	case 3715ULL: goto x86_l_e83;
	case 3720ULL: goto x86_l_e88;
	case 3723ULL: goto x86_l_e8b;
	case 3725ULL: goto x86_l_e8d;
	case 3730ULL: goto x86_l_e92;
	case 3734ULL: goto x86_l_e96;
	case 3739ULL: goto x86_l_e9b;
	case 3744ULL: goto x86_l_ea0;
	case 3749ULL: goto x86_l_ea5;
	case 3751ULL: goto x86_l_ea7;
	case 3756ULL: goto x86_l_eac;
	case 3761ULL: goto x86_l_eb1;
	case 3766ULL: goto x86_l_eb6;
	case 3771ULL: goto x86_l_ebb;
	case 3773ULL: goto x86_l_ebd;
	case 3777ULL: goto x86_l_ec1;
	case 3781ULL: goto x86_l_ec5;
	case 3786ULL: goto x86_l_eca;
	case 3788ULL: goto x86_l_ecc;
	case 3792ULL: goto x86_l_ed0;
	case 3796ULL: goto x86_l_ed4;
	case 3801ULL: goto x86_l_ed9;
	case 3806ULL: goto x86_l_ede;
	case 3811ULL: goto x86_l_ee3;
	case 3813ULL: goto x86_l_ee5;
	case 3818ULL: goto x86_l_eea;
	case 3822ULL: goto x86_l_eee;
	case 3830ULL: goto x86_l_ef6;
	case 3834ULL: goto x86_l_efa;
	case 3839ULL: goto x86_l_eff;
	case 3844ULL: goto x86_l_f04;
	case 3849ULL: goto x86_l_f09;
	case 3851ULL: goto x86_l_f0b;
	case 3856ULL: goto x86_l_f10;
	case 3860ULL: goto x86_l_f14;
	case 3864ULL: goto x86_l_f18;
	case 3869ULL: goto x86_l_f1d;
	case 3874ULL: goto x86_l_f22;
	case 3879ULL: goto x86_l_f27;
	case 3882ULL: goto x86_l_f2a;
	case 3884ULL: goto x86_l_f2c;
	case 3889ULL: goto x86_l_f31;
	case 3893ULL: goto x86_l_f35;
	case 3898ULL: goto x86_l_f3a;
	case 3903ULL: goto x86_l_f3f;
	case 3908ULL: goto x86_l_f44;
	case 3911ULL: goto x86_l_f47;
	case 3913ULL: goto x86_l_f49;
	case 3918ULL: goto x86_l_f4e;
	case 3920ULL: goto x86_l_f50;
	case 3925ULL: goto x86_l_f55;
	case 3929ULL: goto x86_l_f59;
	case 3937ULL: goto x86_l_f61;
	case 3945ULL: goto x86_l_f69;
	case 3950ULL: goto x86_l_f6e;
	case 3955ULL: goto x86_l_f73;
	case 3957ULL: goto x86_l_f75;
	case 3962ULL: goto x86_l_f7a;
	case 3967ULL: goto x86_l_f7f;
	case 3972ULL: goto x86_l_f84;
	case 3975ULL: goto x86_l_f87;
	case 3977ULL: goto x86_l_f89;
	case 3982ULL: goto x86_l_f8e;
	case 3987ULL: goto x86_l_f93;
	case 3992ULL: goto x86_l_f98;
	case 3997ULL: goto x86_l_f9d;
	case 3999ULL: goto x86_l_f9f;
	case 4004ULL: goto x86_l_fa4;
	case 4009ULL: goto x86_l_fa9;
	case 4014ULL: goto x86_l_fae;
	case 4017ULL: goto x86_l_fb1;
	case 4022ULL: goto x86_l_fb6;
	case 4024ULL: goto x86_l_fb8;
	case 4027ULL: goto x86_l_fbb;
	case 4031ULL: goto x86_l_fbf;
	case 4036ULL: goto x86_l_fc4;
	case 4041ULL: goto x86_l_fc9;
	case 4044ULL: goto x86_l_fcc;
	case 4046ULL: goto x86_l_fce;
	case 4051ULL: goto x86_l_fd3;
	case 4056ULL: goto x86_l_fd8;
	case 4061ULL: goto x86_l_fdd;
	case 4064ULL: goto x86_l_fe0;
	case 4066ULL: goto x86_l_fe2;
	case 4071ULL: goto x86_l_fe7;
	case 4075ULL: goto x86_l_feb;
	case 4083ULL: goto x86_l_ff3;
	case 4085ULL: goto x86_l_ff5;
	case 4090ULL: goto x86_l_ffa;
	case 4097ULL: goto x86_l_1001;
	case 4102ULL: goto x86_l_1006;
	case 4105ULL: goto x86_l_1009;
	case 4107ULL: goto x86_l_100b;
	case 4109ULL: goto x86_l_100d;
	case 4111ULL: goto x86_l_100f;
	case 4115ULL: goto x86_l_1013;
	case 4123ULL: goto x86_l_101b;
	case 4128ULL: goto x86_l_1020;
	case 4133ULL: goto x86_l_1025;
	case 4136ULL: goto x86_l_1028;
	case 4142ULL: goto x86_l_102e;
	case 4146ULL: goto x86_l_1032;
	case 4151ULL: goto x86_l_1037;
	case 4158ULL: goto x86_l_103e;
	case 4163ULL: goto x86_l_1043;
	case 4166ULL: goto x86_l_1046;
	case 4169ULL: goto x86_l_1049;
	case 4171ULL: goto x86_l_104b;
	case 4178ULL: goto x86_l_1052;
	case 4180ULL: goto x86_l_1054;
	case 4181ULL: goto x86_l_1055;
	case 4186ULL: goto x86_l_105a;
	case 4191ULL: goto x86_l_105f;
	case 4199ULL: goto x86_l_1067;
	case 4203ULL: goto x86_l_106b;
	case 4210ULL: goto x86_l_1072;
	case 4215ULL: goto x86_l_1077;
	case 4220ULL: goto x86_l_107c;
	case 4222ULL: goto x86_l_107e;
	case 4227ULL: goto x86_l_1083;
	case 4235ULL: goto x86_l_108b;
	case 4238ULL: goto x86_l_108e;
	case 4246ULL: goto x86_l_1096;
	case 4255ULL: goto x86_l_109f;
	case 4259ULL: goto x86_l_10a3;
	case 4264ULL: goto x86_l_10a8;
	case 4269ULL: goto x86_l_10ad;
	case 4274ULL: goto x86_l_10b2;
	case 4276ULL: goto x86_l_10b4;
	case 4278ULL: goto x86_l_10b6;
	case 4284ULL: goto x86_l_10bc;
	case 4290ULL: goto x86_l_10c2;
	case 4293ULL: goto x86_l_10c5;
	case 4298ULL: goto x86_l_10ca;
	case 4304ULL: goto x86_l_10d0;
	case 4309ULL: goto x86_l_10d5;
	case 4317ULL: goto x86_l_10dd;
	case 4321ULL: goto x86_l_10e1;
	case 4328ULL: goto x86_l_10e8;
	case 4333ULL: goto x86_l_10ed;
	case 4338ULL: goto x86_l_10f2;
	case 4340ULL: goto x86_l_10f4;
	case 4344ULL: goto x86_l_10f8;
	case 4346ULL: goto x86_l_10fa;
	case 4348ULL: goto x86_l_10fc;
	case 4354ULL: goto x86_l_1102;
	case 4357ULL: goto x86_l_1105;
	case 4362ULL: goto x86_l_110a;
	case 4368ULL: goto x86_l_1110;
	case 4373ULL: goto x86_l_1115;
	case 4381ULL: goto x86_l_111d;
	case 4385ULL: goto x86_l_1121;
	case 4392ULL: goto x86_l_1128;
	case 4397ULL: goto x86_l_112d;
	case 4402ULL: goto x86_l_1132;
	case 4404ULL: goto x86_l_1134;
	case 4409ULL: goto x86_l_1139;
	case 4417ULL: goto x86_l_1141;
	case 4420ULL: goto x86_l_1144;
	case 4428ULL: goto x86_l_114c;
	case 4437ULL: goto x86_l_1155;
	case 4441ULL: goto x86_l_1159;
	case 4446ULL: goto x86_l_115e;
	case 4451ULL: goto x86_l_1163;
	case 4456ULL: goto x86_l_1168;
	case 4458ULL: goto x86_l_116a;
	case 4460ULL: goto x86_l_116c;
	case 4466ULL: goto x86_l_1172;
	case 4472ULL: goto x86_l_1178;
	case 4475ULL: goto x86_l_117b;
	case 4480ULL: goto x86_l_1180;
	case 4486ULL: goto x86_l_1186;
	case 4491ULL: goto x86_l_118b;
	case 4499ULL: goto x86_l_1193;
	case 4503ULL: goto x86_l_1197;
	case 4510ULL: goto x86_l_119e;
	case 4515ULL: goto x86_l_11a3;
	case 4520ULL: goto x86_l_11a8;
	case 4522ULL: goto x86_l_11aa;
	case 4526ULL: goto x86_l_11ae;
	case 4528ULL: goto x86_l_11b0;
	case 4530ULL: goto x86_l_11b2;
	case 4536ULL: goto x86_l_11b8;
	case 4539ULL: goto x86_l_11bb;
	case 4544ULL: goto x86_l_11c0;
	case 4550ULL: goto x86_l_11c6;
	case 4555ULL: goto x86_l_11cb;
	case 4563ULL: goto x86_l_11d3;
	case 4567ULL: goto x86_l_11d7;
	case 4574ULL: goto x86_l_11de;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4586ULL: goto x86_l_11ea;
	case 4591ULL: goto x86_l_11ef;
	case 4599ULL: goto x86_l_11f7;
	case 4602ULL: goto x86_l_11fa;
	case 4610ULL: goto x86_l_1202;
	case 4619ULL: goto x86_l_120b;
	case 4623ULL: goto x86_l_120f;
	case 4628ULL: goto x86_l_1214;
	case 4633ULL: goto x86_l_1219;
	case 4638ULL: goto x86_l_121e;
	case 4640ULL: goto x86_l_1220;
	case 4642ULL: goto x86_l_1222;
	case 4648ULL: goto x86_l_1228;
	case 4654ULL: goto x86_l_122e;
	case 4657ULL: goto x86_l_1231;
	case 4662ULL: goto x86_l_1236;
	case 4668ULL: goto x86_l_123c;
	case 4673ULL: goto x86_l_1241;
	case 4681ULL: goto x86_l_1249;
	case 4685ULL: goto x86_l_124d;
	case 4692ULL: goto x86_l_1254;
	case 4697ULL: goto x86_l_1259;
	case 4702ULL: goto x86_l_125e;
	case 4704ULL: goto x86_l_1260;
	case 4708ULL: goto x86_l_1264;
	case 4710ULL: goto x86_l_1266;
	case 4712ULL: goto x86_l_1268;
	case 4718ULL: goto x86_l_126e;
	case 4721ULL: goto x86_l_1271;
	case 4726ULL: goto x86_l_1276;
	case 4732ULL: goto x86_l_127c;
	case 4737ULL: goto x86_l_1281;
	case 4745ULL: goto x86_l_1289;
	case 4749ULL: goto x86_l_128d;
	case 4756ULL: goto x86_l_1294;
	case 4761ULL: goto x86_l_1299;
	case 4766ULL: goto x86_l_129e;
	case 4768ULL: goto x86_l_12a0;
	case 4773ULL: goto x86_l_12a5;
	case 4781ULL: goto x86_l_12ad;
	case 4784ULL: goto x86_l_12b0;
	case 4792ULL: goto x86_l_12b8;
	case 4801ULL: goto x86_l_12c1;
	case 4805ULL: goto x86_l_12c5;
	case 4810ULL: goto x86_l_12ca;
	case 4815ULL: goto x86_l_12cf;
	case 4820ULL: goto x86_l_12d4;
	case 4822ULL: goto x86_l_12d6;
	case 4824ULL: goto x86_l_12d8;
	case 4830ULL: goto x86_l_12de;
	case 4836ULL: goto x86_l_12e4;
	case 4839ULL: goto x86_l_12e7;
	case 4844ULL: goto x86_l_12ec;
	case 4850ULL: goto x86_l_12f2;
	case 4855ULL: goto x86_l_12f7;
	case 4863ULL: goto x86_l_12ff;
	case 4867ULL: goto x86_l_1303;
	case 4874ULL: goto x86_l_130a;
	case 4879ULL: goto x86_l_130f;
	case 4884ULL: goto x86_l_1314;
	case 4886ULL: goto x86_l_1316;
	case 4890ULL: goto x86_l_131a;
	case 4892ULL: goto x86_l_131c;
	case 4894ULL: goto x86_l_131e;
	case 4900ULL: goto x86_l_1324;
	case 4903ULL: goto x86_l_1327;
	case 4908ULL: goto x86_l_132c;
	case 4914ULL: goto x86_l_1332;
	case 4919ULL: goto x86_l_1337;
	case 4927ULL: goto x86_l_133f;
	case 4931ULL: goto x86_l_1343;
	case 4938ULL: goto x86_l_134a;
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4950ULL: goto x86_l_1356;
	case 4955ULL: goto x86_l_135b;
	case 4963ULL: goto x86_l_1363;
	case 4966ULL: goto x86_l_1366;
	case 4974ULL: goto x86_l_136e;
	case 4983ULL: goto x86_l_1377;
	case 4987ULL: goto x86_l_137b;
	case 4992ULL: goto x86_l_1380;
	case 4997ULL: goto x86_l_1385;
	case 5002ULL: goto x86_l_138a;
	case 5004ULL: goto x86_l_138c;
	case 5006ULL: goto x86_l_138e;
	case 5012ULL: goto x86_l_1394;
	case 5018ULL: goto x86_l_139a;
	case 5021ULL: goto x86_l_139d;
	case 5026ULL: goto x86_l_13a2;
	case 5032ULL: goto x86_l_13a8;
	case 5037ULL: goto x86_l_13ad;
	case 5045ULL: goto x86_l_13b5;
	case 5049ULL: goto x86_l_13b9;
	case 5056ULL: goto x86_l_13c0;
	case 5061ULL: goto x86_l_13c5;
	case 5066ULL: goto x86_l_13ca;
	case 5068ULL: goto x86_l_13cc;
	case 5072ULL: goto x86_l_13d0;
	case 5074ULL: goto x86_l_13d2;
	case 5076ULL: goto x86_l_13d4;
	case 5082ULL: goto x86_l_13da;
	case 5085ULL: goto x86_l_13dd;
	case 5090ULL: goto x86_l_13e2;
	case 5096ULL: goto x86_l_13e8;
	case 5101ULL: goto x86_l_13ed;
	case 5109ULL: goto x86_l_13f5;
	case 5113ULL: goto x86_l_13f9;
	case 5120ULL: goto x86_l_1400;
	case 5125ULL: goto x86_l_1405;
	case 5130ULL: goto x86_l_140a;
	case 5132ULL: goto x86_l_140c;
	case 5137ULL: goto x86_l_1411;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d39:
	/* 0xd39: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d3e:
	/* 0xd3e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d43:
	/* 0xd43: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_d46:
	/* 0xd46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d48:
	/* 0xd48: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d4d:
	/* 0xd4d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d52:
	/* 0xd52: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d57:
	/* 0xd57: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d5c:
	/* 0xd5c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_d5f:
	/* 0xd5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d61:
	/* 0xd61: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d65:
	/* 0xd65: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_d69:
	/* 0xd69: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_d6d:
	/* 0xd6d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d71:
	/* 0xd71: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d76:
	/* 0xd76: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d7b:
	/* 0xd7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d80:
	/* 0xd80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d82:
	/* 0xd82: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d87:
	/* 0xd87: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_d8b:
	/* 0xd8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d90:
	/* 0xd90: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d95:
	/* 0xd95: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d9a:
	/* 0xd9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d9c:
	/* 0xd9c: mov    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_da1:
	/* 0xda1: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_da5:
	/* 0xda5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_daa:
	/* 0xdaa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_daf:
	/* 0xdaf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_db4:
	/* 0xdb4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_db7:
	/* 0xdb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db9:
	/* 0xdb9: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dbe:
	/* 0xdbe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dc3:
	/* 0xdc3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc8:
	/* 0xdc8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_dcd:
	/* 0xdcd: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_dd0:
	/* 0xdd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd2:
	/* 0xdd2: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dd6:
	/* 0xdd6: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_dda:
	/* 0xdda: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_dde:
	/* 0xdde: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_de2:
	/* 0xde2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_de7:
	/* 0xde7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dec:
	/* 0xdec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_df1:
	/* 0xdf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df3:
	/* 0xdf3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_df8:
	/* 0xdf8: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_dfc:
	/* 0xdfc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e01:
	/* 0xe01: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e06:
	/* 0xe06: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e0b:
	/* 0xe0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0d:
	/* 0xe0d: cmp    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_e12:
	/* 0xe12: jne    e6a <syscall__execve_enter+0xe6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e6a;
	}
x86_l_e14:
	/* 0xe14: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e19:
	/* 0xe19: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e1e:
	/* 0xe1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e23:
	/* 0xe23: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e26:
	/* 0xe26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e28:
	/* 0xe28: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e2d:
	/* 0xe2d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e32:
	/* 0xe32: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e37:
	/* 0xe37: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e3c:
	/* 0xe3c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e3f:
	/* 0xe3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e41:
	/* 0xe41: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e45:
	/* 0xe45: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_e49:
	/* 0xe49: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_e4d:
	/* 0xe4d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e51:
	/* 0xe51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e56:
	/* 0xe56: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e5b:
	/* 0xe5b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e60:
	/* 0xe60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e62:
	/* 0xe62: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e66:
	/* 0xe66: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e6a:
	/* 0xe6a: lea    r15,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e6e:
	/* 0xe6e: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e72:
	/* 0xe72: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e79:
	/* 0xe79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e7e:
	/* 0xe7e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e83:
	/* 0xe83: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e88:
	/* 0xe88: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e8b:
	/* 0xe8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8d:
	/* 0xe8d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e92:
	/* 0xe92: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e96:
	/* 0xe96: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e9b:
	/* 0xe9b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ea0:
	/* 0xea0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ea5:
	/* 0xea5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea7:
	/* 0xea7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eac:
	/* 0xeac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb1:
	/* 0xeb1: lea    rdi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_eb6:
	/* 0xeb6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ebb:
	/* 0xebb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ebd:
	/* 0xebd: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ec1:
	/* 0xec1: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ec5:
	/* 0xec5: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_eca:
	/* 0xeca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ecc:
	/* 0xecc: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ed0:
	/* 0xed0: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ed4:
	/* 0xed4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ed9:
	/* 0xed9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ede:
	/* 0xede: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ee3:
	/* 0xee3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee5:
	/* 0xee5: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eea:
	/* 0xeea: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eee:
	/* 0xeee: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ef6:
	/* 0xef6: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_efa:
	/* 0xefa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eff:
	/* 0xeff: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f04:
	/* 0xf04: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f09:
	/* 0xf09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f0b:
	/* 0xf0b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f10:
	/* 0xf10: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f14:
	/* 0xf14: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_f18:
	/* 0xf18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f1d:
	/* 0xf1d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f22:
	/* 0xf22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f27:
	/* 0xf27: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_f2a:
	/* 0xf2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2c:
	/* 0xf2c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f31:
	/* 0xf31: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f35:
	/* 0xf35: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f3a:
	/* 0xf3a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f3f:
	/* 0xf3f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f44:
	/* 0xf44: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_f47:
	/* 0xf47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f49:
	/* 0xf49: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_f4e:
	/* 0xf4e: je     f55 <syscall__execve_enter+0xf55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f55;
	}
x86_l_f50:
	/* 0xf50: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_f55:
	/* 0xf55: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_f59:
	/* 0xf59: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_f61:
	/* 0xf61: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_f69:
	/* 0xf69: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_f6e:
	/* 0xf6e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_f73:
	/* 0xf73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f75:
	/* 0xf75: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f7a:
	/* 0xf7a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f7f:
	/* 0xf7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f84:
	/* 0xf84: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f87:
	/* 0xf87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f89:
	/* 0xf89: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f8e:
	/* 0xf8e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f93:
	/* 0xf93: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f98:
	/* 0xf98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f9d:
	/* 0xf9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9f:
	/* 0xf9f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fa4:
	/* 0xfa4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fa9:
	/* 0xfa9: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fae:
	/* 0xfae: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_fb1:
	/* 0xfb1: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_fb6:
	/* 0xfb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb8:
	/* 0xfb8: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_fbb:
	/* 0xfbb: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_fbf:
	/* 0xfbf: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_fc4:
	/* 0xfc4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_fc9:
	/* 0xfc9: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_fcc:
	/* 0xfcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fce:
	/* 0xfce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fd3:
	/* 0xfd3: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_fd8:
	/* 0xfd8: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_fdd:
	/* 0xfdd: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_fe0:
	/* 0xfe0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe2:
	/* 0xfe2: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_fe7:
	/* 0xfe7: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_feb:
	/* 0xfeb: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_ff3:
	/* 0xff3: je     1013 <syscall__execve_enter+0x1013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1013;
	}
x86_l_ff5:
	/* 0xff5: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_ffa:
	/* 0xffa: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_1001:
	/* 0x1001: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1006:
	/* 0x1006: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1009:
	/* 0x1009: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_100b:
	/* 0x100b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_100d:
	/* 0x100d: js     1013 <syscall__execve_enter+0x1013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1013;
	}
x86_l_100f:
	/* 0x100f: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1013:
	/* 0x1013: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_101b:
	/* 0x101b: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_1020:
	/* 0x1020: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1025:
	/* 0x1025: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1028:
	/* 0x1028: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_102e:
	/* 0x102e: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1032:
	/* 0x1032: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1037:
	/* 0x1037: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_103e:
	/* 0x103e: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1043:
	/* 0x1043: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1046:
	/* 0x1046: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1049:
	/* 0x1049: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_104b:
	/* 0x104b: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_1052:
	/* 0x1052: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1054:
	/* 0x1054: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1055:
	/* 0x1055: jmp    4737 <syscall__execve_enter+0x4737> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_105a:
	/* 0x105a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_105f:
	/* 0x105f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1067:
	/* 0x1067: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_106b:
	/* 0x106b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1072:
	/* 0x1072: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1077:
	/* 0x1077: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_107c:
	/* 0x107c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_107e:
	/* 0x107e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1083:
	/* 0x1083: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_108b:
	/* 0x108b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_108e:
	/* 0x108e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1096:
	/* 0x1096: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_109f:
	/* 0x109f: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10a3:
	/* 0x10a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10a8:
	/* 0x10a8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10ad:
	/* 0x10ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10b2:
	/* 0x10b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b4:
	/* 0x10b4: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_10b6:
	/* 0x10b6: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10bc:
	/* 0x10bc: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_10c2:
	/* 0x10c2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_10c5:
	/* 0x10c5: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_10ca:
	/* 0x10ca: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_10d0:
	/* 0x10d0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_10d5:
	/* 0x10d5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_10dd:
	/* 0x10dd: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_10e1:
	/* 0x10e1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_10e8:
	/* 0x10e8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10ed:
	/* 0x10ed: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_10f2:
	/* 0x10f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f4:
	/* 0x10f4: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_10f8:
	/* 0x10f8: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_10fa:
	/* 0x10fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10fc:
	/* 0x10fc: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1102:
	/* 0x1102: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1105:
	/* 0x1105: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_110a:
	/* 0x110a: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1110:
	/* 0x1110: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1115:
	/* 0x1115: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_111d:
	/* 0x111d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1121:
	/* 0x1121: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1128:
	/* 0x1128: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_112d:
	/* 0x112d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1132:
	/* 0x1132: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1134:
	/* 0x1134: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1139:
	/* 0x1139: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1141:
	/* 0x1141: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1144:
	/* 0x1144: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_114c:
	/* 0x114c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1155:
	/* 0x1155: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1159:
	/* 0x1159: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_115e:
	/* 0x115e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1163:
	/* 0x1163: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1168:
	/* 0x1168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116a:
	/* 0x116a: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_116c:
	/* 0x116c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1172:
	/* 0x1172: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1178:
	/* 0x1178: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_117b:
	/* 0x117b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1180:
	/* 0x1180: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1186:
	/* 0x1186: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_118b:
	/* 0x118b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1193:
	/* 0x1193: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1197:
	/* 0x1197: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_119e:
	/* 0x119e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11a3:
	/* 0x11a3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_11a8:
	/* 0x11a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11aa:
	/* 0x11aa: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_11ae:
	/* 0x11ae: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_11b0:
	/* 0x11b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11b2:
	/* 0x11b2: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_11b8:
	/* 0x11b8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_11bb:
	/* 0x11bb: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_11c0:
	/* 0x11c0: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_11c6:
	/* 0x11c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11cb:
	/* 0x11cb: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_11d3:
	/* 0x11d3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_11d7:
	/* 0x11d7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_11de:
	/* 0x11de: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_11e3:
	/* 0x11e3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11e8:
	/* 0x11e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ea:
	/* 0x11ea: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_11ef:
	/* 0x11ef: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_11f7:
	/* 0x11f7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_11fa:
	/* 0x11fa: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1202:
	/* 0x1202: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_120b:
	/* 0x120b: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_120f:
	/* 0x120f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1214:
	/* 0x1214: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1219:
	/* 0x1219: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_121e:
	/* 0x121e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1220:
	/* 0x1220: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1222:
	/* 0x1222: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1228:
	/* 0x1228: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_122e:
	/* 0x122e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1231:
	/* 0x1231: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1236:
	/* 0x1236: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_123c:
	/* 0x123c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1241:
	/* 0x1241: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1249:
	/* 0x1249: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_124d:
	/* 0x124d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1254:
	/* 0x1254: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1259:
	/* 0x1259: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_125e:
	/* 0x125e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1260:
	/* 0x1260: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1264:
	/* 0x1264: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1266:
	/* 0x1266: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1268:
	/* 0x1268: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_126e:
	/* 0x126e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1271:
	/* 0x1271: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1276:
	/* 0x1276: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_127c:
	/* 0x127c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1281:
	/* 0x1281: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1289:
	/* 0x1289: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_128d:
	/* 0x128d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1294:
	/* 0x1294: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1299:
	/* 0x1299: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_129e:
	/* 0x129e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a0:
	/* 0x12a0: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_12a5:
	/* 0x12a5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_12ad:
	/* 0x12ad: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_12b0:
	/* 0x12b0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_12b8:
	/* 0x12b8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12c1:
	/* 0x12c1: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12c5:
	/* 0x12c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ca:
	/* 0x12ca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12cf:
	/* 0x12cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12d4:
	/* 0x12d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d6:
	/* 0x12d6: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_12d8:
	/* 0x12d8: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12de:
	/* 0x12de: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_12e4:
	/* 0x12e4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12e7:
	/* 0x12e7: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_12ec:
	/* 0x12ec: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_12f2:
	/* 0x12f2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_12f7:
	/* 0x12f7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_12ff:
	/* 0x12ff: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1303:
	/* 0x1303: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_130a:
	/* 0x130a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_130f:
	/* 0x130f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1314:
	/* 0x1314: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1316:
	/* 0x1316: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_131a:
	/* 0x131a: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_131c:
	/* 0x131c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_131e:
	/* 0x131e: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1324:
	/* 0x1324: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1327:
	/* 0x1327: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_132c:
	/* 0x132c: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1332:
	/* 0x1332: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1337:
	/* 0x1337: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_133f:
	/* 0x133f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1343:
	/* 0x1343: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_134a:
	/* 0x134a: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_134f:
	/* 0x134f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1354:
	/* 0x1354: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1356:
	/* 0x1356: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_135b:
	/* 0x135b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1363:
	/* 0x1363: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1366:
	/* 0x1366: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_136e:
	/* 0x136e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1377:
	/* 0x1377: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_137b:
	/* 0x137b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1380:
	/* 0x1380: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1385:
	/* 0x1385: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_138a:
	/* 0x138a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138c:
	/* 0x138c: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_138e:
	/* 0x138e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1394:
	/* 0x1394: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_139a:
	/* 0x139a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_139d:
	/* 0x139d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_13a2:
	/* 0x13a2: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_13a8:
	/* 0x13a8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_13ad:
	/* 0x13ad: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_13b5:
	/* 0x13b5: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_13b9:
	/* 0x13b9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_13c0:
	/* 0x13c0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13c5:
	/* 0x13c5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_13ca:
	/* 0x13ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13cc:
	/* 0x13cc: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_13d0:
	/* 0x13d0: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_13d2:
	/* 0x13d2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13d4:
	/* 0x13d4: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_13da:
	/* 0x13da: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_13dd:
	/* 0x13dd: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_13e2:
	/* 0x13e2: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_13e8:
	/* 0x13e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13ed:
	/* 0x13ed: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_13f5:
	/* 0x13f5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_13f9:
	/* 0x13f9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1400:
	/* 0x1400: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1405:
	/* 0x1405: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_140a:
	/* 0x140a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_140c:
	/* 0x140c: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1411:
	/* 0x1411: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
	return 5145ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5145ULL: goto x86_l_1419;
	case 5148ULL: goto x86_l_141c;
	case 5156ULL: goto x86_l_1424;
	case 5165ULL: goto x86_l_142d;
	case 5169ULL: goto x86_l_1431;
	case 5174ULL: goto x86_l_1436;
	case 5179ULL: goto x86_l_143b;
	case 5184ULL: goto x86_l_1440;
	case 5186ULL: goto x86_l_1442;
	case 5188ULL: goto x86_l_1444;
	case 5194ULL: goto x86_l_144a;
	case 5200ULL: goto x86_l_1450;
	case 5203ULL: goto x86_l_1453;
	case 5208ULL: goto x86_l_1458;
	case 5214ULL: goto x86_l_145e;
	case 5219ULL: goto x86_l_1463;
	case 5227ULL: goto x86_l_146b;
	case 5231ULL: goto x86_l_146f;
	case 5238ULL: goto x86_l_1476;
	case 5243ULL: goto x86_l_147b;
	case 5248ULL: goto x86_l_1480;
	case 5250ULL: goto x86_l_1482;
	case 5254ULL: goto x86_l_1486;
	case 5256ULL: goto x86_l_1488;
	case 5258ULL: goto x86_l_148a;
	case 5264ULL: goto x86_l_1490;
	case 5267ULL: goto x86_l_1493;
	case 5272ULL: goto x86_l_1498;
	case 5278ULL: goto x86_l_149e;
	case 5283ULL: goto x86_l_14a3;
	case 5291ULL: goto x86_l_14ab;
	case 5295ULL: goto x86_l_14af;
	case 5302ULL: goto x86_l_14b6;
	case 5307ULL: goto x86_l_14bb;
	case 5312ULL: goto x86_l_14c0;
	case 5314ULL: goto x86_l_14c2;
	case 5319ULL: goto x86_l_14c7;
	case 5327ULL: goto x86_l_14cf;
	case 5330ULL: goto x86_l_14d2;
	case 5338ULL: goto x86_l_14da;
	case 5347ULL: goto x86_l_14e3;
	case 5351ULL: goto x86_l_14e7;
	case 5356ULL: goto x86_l_14ec;
	case 5361ULL: goto x86_l_14f1;
	case 5366ULL: goto x86_l_14f6;
	case 5368ULL: goto x86_l_14f8;
	case 5370ULL: goto x86_l_14fa;
	case 5376ULL: goto x86_l_1500;
	case 5382ULL: goto x86_l_1506;
	case 5385ULL: goto x86_l_1509;
	case 5390ULL: goto x86_l_150e;
	case 5396ULL: goto x86_l_1514;
	case 5401ULL: goto x86_l_1519;
	case 5409ULL: goto x86_l_1521;
	case 5413ULL: goto x86_l_1525;
	case 5420ULL: goto x86_l_152c;
	case 5425ULL: goto x86_l_1531;
	case 5430ULL: goto x86_l_1536;
	case 5432ULL: goto x86_l_1538;
	case 5436ULL: goto x86_l_153c;
	case 5438ULL: goto x86_l_153e;
	case 5440ULL: goto x86_l_1540;
	case 5446ULL: goto x86_l_1546;
	case 5449ULL: goto x86_l_1549;
	case 5454ULL: goto x86_l_154e;
	case 5460ULL: goto x86_l_1554;
	case 5465ULL: goto x86_l_1559;
	case 5473ULL: goto x86_l_1561;
	case 5477ULL: goto x86_l_1565;
	case 5484ULL: goto x86_l_156c;
	case 5489ULL: goto x86_l_1571;
	case 5494ULL: goto x86_l_1576;
	case 5496ULL: goto x86_l_1578;
	case 5501ULL: goto x86_l_157d;
	case 5509ULL: goto x86_l_1585;
	case 5512ULL: goto x86_l_1588;
	case 5520ULL: goto x86_l_1590;
	case 5529ULL: goto x86_l_1599;
	case 5533ULL: goto x86_l_159d;
	case 5538ULL: goto x86_l_15a2;
	case 5543ULL: goto x86_l_15a7;
	case 5548ULL: goto x86_l_15ac;
	case 5550ULL: goto x86_l_15ae;
	case 5552ULL: goto x86_l_15b0;
	case 5558ULL: goto x86_l_15b6;
	case 5564ULL: goto x86_l_15bc;
	case 5567ULL: goto x86_l_15bf;
	case 5572ULL: goto x86_l_15c4;
	case 5578ULL: goto x86_l_15ca;
	case 5583ULL: goto x86_l_15cf;
	case 5591ULL: goto x86_l_15d7;
	case 5595ULL: goto x86_l_15db;
	case 5602ULL: goto x86_l_15e2;
	case 5607ULL: goto x86_l_15e7;
	case 5612ULL: goto x86_l_15ec;
	case 5614ULL: goto x86_l_15ee;
	case 5618ULL: goto x86_l_15f2;
	case 5620ULL: goto x86_l_15f4;
	case 5622ULL: goto x86_l_15f6;
	case 5628ULL: goto x86_l_15fc;
	case 5631ULL: goto x86_l_15ff;
	case 5636ULL: goto x86_l_1604;
	case 5642ULL: goto x86_l_160a;
	case 5647ULL: goto x86_l_160f;
	case 5655ULL: goto x86_l_1617;
	case 5659ULL: goto x86_l_161b;
	case 5666ULL: goto x86_l_1622;
	case 5671ULL: goto x86_l_1627;
	case 5676ULL: goto x86_l_162c;
	case 5678ULL: goto x86_l_162e;
	case 5683ULL: goto x86_l_1633;
	case 5691ULL: goto x86_l_163b;
	case 5694ULL: goto x86_l_163e;
	case 5702ULL: goto x86_l_1646;
	case 5711ULL: goto x86_l_164f;
	case 5715ULL: goto x86_l_1653;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5730ULL: goto x86_l_1662;
	case 5732ULL: goto x86_l_1664;
	case 5734ULL: goto x86_l_1666;
	case 5740ULL: goto x86_l_166c;
	case 5746ULL: goto x86_l_1672;
	case 5749ULL: goto x86_l_1675;
	case 5754ULL: goto x86_l_167a;
	case 5760ULL: goto x86_l_1680;
	case 5765ULL: goto x86_l_1685;
	case 5773ULL: goto x86_l_168d;
	case 5777ULL: goto x86_l_1691;
	case 5784ULL: goto x86_l_1698;
	case 5789ULL: goto x86_l_169d;
	case 5794ULL: goto x86_l_16a2;
	case 5796ULL: goto x86_l_16a4;
	case 5800ULL: goto x86_l_16a8;
	case 5802ULL: goto x86_l_16aa;
	case 5804ULL: goto x86_l_16ac;
	case 5810ULL: goto x86_l_16b2;
	case 5813ULL: goto x86_l_16b5;
	case 5818ULL: goto x86_l_16ba;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5837ULL: goto x86_l_16cd;
	case 5841ULL: goto x86_l_16d1;
	case 5848ULL: goto x86_l_16d8;
	case 5853ULL: goto x86_l_16dd;
	case 5858ULL: goto x86_l_16e2;
	case 5860ULL: goto x86_l_16e4;
	case 5865ULL: goto x86_l_16e9;
	case 5873ULL: goto x86_l_16f1;
	case 5876ULL: goto x86_l_16f4;
	case 5884ULL: goto x86_l_16fc;
	case 5893ULL: goto x86_l_1705;
	case 5897ULL: goto x86_l_1709;
	case 5902ULL: goto x86_l_170e;
	case 5907ULL: goto x86_l_1713;
	case 5912ULL: goto x86_l_1718;
	case 5914ULL: goto x86_l_171a;
	case 5916ULL: goto x86_l_171c;
	case 5922ULL: goto x86_l_1722;
	case 5928ULL: goto x86_l_1728;
	case 5931ULL: goto x86_l_172b;
	case 5936ULL: goto x86_l_1730;
	case 5942ULL: goto x86_l_1736;
	case 5947ULL: goto x86_l_173b;
	case 5955ULL: goto x86_l_1743;
	case 5959ULL: goto x86_l_1747;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5978ULL: goto x86_l_175a;
	case 5982ULL: goto x86_l_175e;
	case 5984ULL: goto x86_l_1760;
	case 5986ULL: goto x86_l_1762;
	case 5992ULL: goto x86_l_1768;
	case 5995ULL: goto x86_l_176b;
	case 6000ULL: goto x86_l_1770;
	case 6006ULL: goto x86_l_1776;
	case 6011ULL: goto x86_l_177b;
	case 6019ULL: goto x86_l_1783;
	case 6023ULL: goto x86_l_1787;
	case 6030ULL: goto x86_l_178e;
	case 6035ULL: goto x86_l_1793;
	case 6040ULL: goto x86_l_1798;
	case 6042ULL: goto x86_l_179a;
	case 6047ULL: goto x86_l_179f;
	case 6055ULL: goto x86_l_17a7;
	case 6058ULL: goto x86_l_17aa;
	case 6066ULL: goto x86_l_17b2;
	case 6075ULL: goto x86_l_17bb;
	case 6079ULL: goto x86_l_17bf;
	case 6084ULL: goto x86_l_17c4;
	case 6089ULL: goto x86_l_17c9;
	case 6094ULL: goto x86_l_17ce;
	case 6096ULL: goto x86_l_17d0;
	case 6098ULL: goto x86_l_17d2;
	case 6104ULL: goto x86_l_17d8;
	case 6110ULL: goto x86_l_17de;
	case 6113ULL: goto x86_l_17e1;
	case 6118ULL: goto x86_l_17e6;
	case 6124ULL: goto x86_l_17ec;
	case 6129ULL: goto x86_l_17f1;
	case 6137ULL: goto x86_l_17f9;
	case 6141ULL: goto x86_l_17fd;
	case 6148ULL: goto x86_l_1804;
	case 6153ULL: goto x86_l_1809;
	case 6158ULL: goto x86_l_180e;
	case 6160ULL: goto x86_l_1810;
	case 6164ULL: goto x86_l_1814;
	case 6166ULL: goto x86_l_1816;
	case 6168ULL: goto x86_l_1818;
	case 6174ULL: goto x86_l_181e;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6188ULL: goto x86_l_182c;
	case 6193ULL: goto x86_l_1831;
	case 6201ULL: goto x86_l_1839;
	case 6205ULL: goto x86_l_183d;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6222ULL: goto x86_l_184e;
	case 6224ULL: goto x86_l_1850;
	case 6229ULL: goto x86_l_1855;
	case 6237ULL: goto x86_l_185d;
	case 6240ULL: goto x86_l_1860;
	case 6248ULL: goto x86_l_1868;
	case 6257ULL: goto x86_l_1871;
	case 6261ULL: goto x86_l_1875;
	case 6266ULL: goto x86_l_187a;
	case 6271ULL: goto x86_l_187f;
	case 6276ULL: goto x86_l_1884;
	case 6278ULL: goto x86_l_1886;
	case 6280ULL: goto x86_l_1888;
	case 6286ULL: goto x86_l_188e;
	case 6292ULL: goto x86_l_1894;
	case 6295ULL: goto x86_l_1897;
	case 6300ULL: goto x86_l_189c;
	case 6306ULL: goto x86_l_18a2;
	case 6311ULL: goto x86_l_18a7;
	case 6319ULL: goto x86_l_18af;
	case 6323ULL: goto x86_l_18b3;
	case 6330ULL: goto x86_l_18ba;
	case 6335ULL: goto x86_l_18bf;
	case 6340ULL: goto x86_l_18c4;
	case 6342ULL: goto x86_l_18c6;
	case 6346ULL: goto x86_l_18ca;
	case 6348ULL: goto x86_l_18cc;
	case 6350ULL: goto x86_l_18ce;
	case 6356ULL: goto x86_l_18d4;
	case 6359ULL: goto x86_l_18d7;
	case 6364ULL: goto x86_l_18dc;
	case 6370ULL: goto x86_l_18e2;
	case 6375ULL: goto x86_l_18e7;
	case 6383ULL: goto x86_l_18ef;
	case 6387ULL: goto x86_l_18f3;
	case 6394ULL: goto x86_l_18fa;
	case 6399ULL: goto x86_l_18ff;
	case 6404ULL: goto x86_l_1904;
	case 6406ULL: goto x86_l_1906;
	case 6411ULL: goto x86_l_190b;
	case 6419ULL: goto x86_l_1913;
	case 6422ULL: goto x86_l_1916;
	case 6430ULL: goto x86_l_191e;
	case 6439ULL: goto x86_l_1927;
	case 6443ULL: goto x86_l_192b;
	case 6448ULL: goto x86_l_1930;
	case 6453ULL: goto x86_l_1935;
	case 6458ULL: goto x86_l_193a;
	case 6460ULL: goto x86_l_193c;
	case 6462ULL: goto x86_l_193e;
	case 6468ULL: goto x86_l_1944;
	case 6474ULL: goto x86_l_194a;
	case 6477ULL: goto x86_l_194d;
	case 6482ULL: goto x86_l_1952;
	case 6488ULL: goto x86_l_1958;
	case 6493ULL: goto x86_l_195d;
	case 6501ULL: goto x86_l_1965;
	case 6505ULL: goto x86_l_1969;
	case 6512ULL: goto x86_l_1970;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6524ULL: goto x86_l_197c;
	case 6528ULL: goto x86_l_1980;
	case 6530ULL: goto x86_l_1982;
	case 6532ULL: goto x86_l_1984;
	case 6538ULL: goto x86_l_198a;
	case 6541ULL: goto x86_l_198d;
	case 6546ULL: goto x86_l_1992;
	case 6552ULL: goto x86_l_1998;
	case 6557ULL: goto x86_l_199d;
	case 6565ULL: goto x86_l_19a5;
	case 6569ULL: goto x86_l_19a9;
	case 6576ULL: goto x86_l_19b0;
	case 6581ULL: goto x86_l_19b5;
	case 6586ULL: goto x86_l_19ba;
	case 6588ULL: goto x86_l_19bc;
	case 6593ULL: goto x86_l_19c1;
	case 6601ULL: goto x86_l_19c9;
	case 6604ULL: goto x86_l_19cc;
	case 6612ULL: goto x86_l_19d4;
	case 6621ULL: goto x86_l_19dd;
	case 6625ULL: goto x86_l_19e1;
	case 6630ULL: goto x86_l_19e6;
	case 6635ULL: goto x86_l_19eb;
	case 6640ULL: goto x86_l_19f0;
	case 6642ULL: goto x86_l_19f2;
	case 6644ULL: goto x86_l_19f4;
	case 6650ULL: goto x86_l_19fa;
	case 6656ULL: goto x86_l_1a00;
	case 6659ULL: goto x86_l_1a03;
	case 6664ULL: goto x86_l_1a08;
	case 6670ULL: goto x86_l_1a0e;
	case 6675ULL: goto x86_l_1a13;
	case 6683ULL: goto x86_l_1a1b;
	case 6687ULL: goto x86_l_1a1f;
	case 6694ULL: goto x86_l_1a26;
	case 6699ULL: goto x86_l_1a2b;
	case 6704ULL: goto x86_l_1a30;
	case 6706ULL: goto x86_l_1a32;
	case 6710ULL: goto x86_l_1a36;
	case 6712ULL: goto x86_l_1a38;
	case 6714ULL: goto x86_l_1a3a;
	case 6720ULL: goto x86_l_1a40;
	case 6723ULL: goto x86_l_1a43;
	case 6728ULL: goto x86_l_1a48;
	case 6734ULL: goto x86_l_1a4e;
	case 6739ULL: goto x86_l_1a53;
	case 6747ULL: goto x86_l_1a5b;
	case 6751ULL: goto x86_l_1a5f;
	case 6758ULL: goto x86_l_1a66;
	case 6763ULL: goto x86_l_1a6b;
	case 6768ULL: goto x86_l_1a70;
	case 6770ULL: goto x86_l_1a72;
	case 6775ULL: goto x86_l_1a77;
	case 6783ULL: goto x86_l_1a7f;
	case 6786ULL: goto x86_l_1a82;
	case 6794ULL: goto x86_l_1a8a;
	case 6803ULL: goto x86_l_1a93;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6817ULL: goto x86_l_1aa1;
	case 6822ULL: goto x86_l_1aa6;
	case 6824ULL: goto x86_l_1aa8;
	case 6826ULL: goto x86_l_1aaa;
	case 6832ULL: goto x86_l_1ab0;
	case 6838ULL: goto x86_l_1ab6;
	case 6841ULL: goto x86_l_1ab9;
	case 6846ULL: goto x86_l_1abe;
	case 6852ULL: goto x86_l_1ac4;
	case 6857ULL: goto x86_l_1ac9;
	case 6865ULL: goto x86_l_1ad1;
	case 6869ULL: goto x86_l_1ad5;
	case 6876ULL: goto x86_l_1adc;
	case 6881ULL: goto x86_l_1ae1;
	case 6886ULL: goto x86_l_1ae6;
	case 6888ULL: goto x86_l_1ae8;
	case 6892ULL: goto x86_l_1aec;
	case 6894ULL: goto x86_l_1aee;
	case 6896ULL: goto x86_l_1af0;
	case 6902ULL: goto x86_l_1af6;
	case 6905ULL: goto x86_l_1af9;
	case 6910ULL: goto x86_l_1afe;
	case 6916ULL: goto x86_l_1b04;
	case 6921ULL: goto x86_l_1b09;
	case 6929ULL: goto x86_l_1b11;
	case 6933ULL: goto x86_l_1b15;
	case 6940ULL: goto x86_l_1b1c;
	case 6945ULL: goto x86_l_1b21;
	case 6950ULL: goto x86_l_1b26;
	case 6952ULL: goto x86_l_1b28;
	case 6957ULL: goto x86_l_1b2d;
	case 6965ULL: goto x86_l_1b35;
	case 6968ULL: goto x86_l_1b38;
	case 6976ULL: goto x86_l_1b40;
	case 6985ULL: goto x86_l_1b49;
	case 6992ULL: goto x86_l_1b50;
	case 6997ULL: goto x86_l_1b55;
	case 7002ULL: goto x86_l_1b5a;
	case 7007ULL: goto x86_l_1b5f;
	case 7009ULL: goto x86_l_1b61;
	case 7011ULL: goto x86_l_1b63;
	case 7017ULL: goto x86_l_1b69;
	case 7023ULL: goto x86_l_1b6f;
	case 7026ULL: goto x86_l_1b72;
	case 7031ULL: goto x86_l_1b77;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1419:
	/* 0x1419: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_141c:
	/* 0x141c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1424:
	/* 0x1424: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_142d:
	/* 0x142d: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1431:
	/* 0x1431: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1436:
	/* 0x1436: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_143b:
	/* 0x143b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1440:
	/* 0x1440: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1442:
	/* 0x1442: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_1444:
	/* 0x1444: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_144a:
	/* 0x144a: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1450:
	/* 0x1450: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1453:
	/* 0x1453: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1458:
	/* 0x1458: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_145e:
	/* 0x145e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1463:
	/* 0x1463: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_146b:
	/* 0x146b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_146f:
	/* 0x146f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1476:
	/* 0x1476: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_147b:
	/* 0x147b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1480:
	/* 0x1480: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1482:
	/* 0x1482: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1486:
	/* 0x1486: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_1488:
	/* 0x1488: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_148a:
	/* 0x148a: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1490:
	/* 0x1490: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1493:
	/* 0x1493: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1498:
	/* 0x1498: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_149e:
	/* 0x149e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14a3:
	/* 0x14a3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_14ab:
	/* 0x14ab: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_14af:
	/* 0x14af: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_14b6:
	/* 0x14b6: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_14bb:
	/* 0x14bb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14c0:
	/* 0x14c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c2:
	/* 0x14c2: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_14c7:
	/* 0x14c7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_14cf:
	/* 0x14cf: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_14d2:
	/* 0x14d2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_14da:
	/* 0x14da: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_14e3:
	/* 0x14e3: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14e7:
	/* 0x14e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14ec:
	/* 0x14ec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14f1:
	/* 0x14f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14f6:
	/* 0x14f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f8:
	/* 0x14f8: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_14fa:
	/* 0x14fa: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1500:
	/* 0x1500: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1506:
	/* 0x1506: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1509:
	/* 0x1509: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_150e:
	/* 0x150e: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1514:
	/* 0x1514: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1519:
	/* 0x1519: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1521:
	/* 0x1521: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1525:
	/* 0x1525: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_152c:
	/* 0x152c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1531:
	/* 0x1531: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1536:
	/* 0x1536: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1538:
	/* 0x1538: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_153c:
	/* 0x153c: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_153e:
	/* 0x153e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1540:
	/* 0x1540: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1546:
	/* 0x1546: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1549:
	/* 0x1549: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_154e:
	/* 0x154e: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1554:
	/* 0x1554: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1559:
	/* 0x1559: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1561:
	/* 0x1561: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1565:
	/* 0x1565: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_156c:
	/* 0x156c: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1571:
	/* 0x1571: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1576:
	/* 0x1576: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1578:
	/* 0x1578: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_157d:
	/* 0x157d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1585:
	/* 0x1585: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1588:
	/* 0x1588: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1590:
	/* 0x1590: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1599:
	/* 0x1599: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_159d:
	/* 0x159d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15a2:
	/* 0x15a2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15a7:
	/* 0x15a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15ac:
	/* 0x15ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ae:
	/* 0x15ae: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_15b0:
	/* 0x15b0: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_15b6:
	/* 0x15b6: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_15bc:
	/* 0x15bc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15bf:
	/* 0x15bf: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_15c4:
	/* 0x15c4: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_15ca:
	/* 0x15ca: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_15cf:
	/* 0x15cf: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_15d7:
	/* 0x15d7: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_15db:
	/* 0x15db: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_15e2:
	/* 0x15e2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15e7:
	/* 0x15e7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_15ec:
	/* 0x15ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ee:
	/* 0x15ee: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_15f2:
	/* 0x15f2: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_15f4:
	/* 0x15f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15f6:
	/* 0x15f6: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_15fc:
	/* 0x15fc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15ff:
	/* 0x15ff: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1604:
	/* 0x1604: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_160a:
	/* 0x160a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_160f:
	/* 0x160f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1617:
	/* 0x1617: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_161b:
	/* 0x161b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1622:
	/* 0x1622: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1627:
	/* 0x1627: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_162c:
	/* 0x162c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162e:
	/* 0x162e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1633:
	/* 0x1633: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_163b:
	/* 0x163b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_163e:
	/* 0x163e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1646:
	/* 0x1646: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_164f:
	/* 0x164f: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1653:
	/* 0x1653: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1658:
	/* 0x1658: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_165d:
	/* 0x165d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1662:
	/* 0x1662: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1664:
	/* 0x1664: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_1666:
	/* 0x1666: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_166c:
	/* 0x166c: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1672:
	/* 0x1672: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1675:
	/* 0x1675: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_167a:
	/* 0x167a: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1680:
	/* 0x1680: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1685:
	/* 0x1685: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_168d:
	/* 0x168d: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1691:
	/* 0x1691: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1698:
	/* 0x1698: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_169d:
	/* 0x169d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_16a2:
	/* 0x16a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a4:
	/* 0x16a4: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_16a8:
	/* 0x16a8: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_16aa:
	/* 0x16aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16ac:
	/* 0x16ac: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_16b2:
	/* 0x16b2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16b5:
	/* 0x16b5: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_16ba:
	/* 0x16ba: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_16c0:
	/* 0x16c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16c5:
	/* 0x16c5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_16cd:
	/* 0x16cd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_16d1:
	/* 0x16d1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_16d8:
	/* 0x16d8: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_16dd:
	/* 0x16dd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16e2:
	/* 0x16e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e4:
	/* 0x16e4: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_16e9:
	/* 0x16e9: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_16f1:
	/* 0x16f1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_16f4:
	/* 0x16f4: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_16fc:
	/* 0x16fc: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1705:
	/* 0x1705: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1709:
	/* 0x1709: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_170e:
	/* 0x170e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1713:
	/* 0x1713: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1718:
	/* 0x1718: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_171a:
	/* 0x171a: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_171c:
	/* 0x171c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1722:
	/* 0x1722: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1728:
	/* 0x1728: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_172b:
	/* 0x172b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1730:
	/* 0x1730: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1736:
	/* 0x1736: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_173b:
	/* 0x173b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1743:
	/* 0x1743: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1747:
	/* 0x1747: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_174e:
	/* 0x174e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1753:
	/* 0x1753: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1758:
	/* 0x1758: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175a:
	/* 0x175a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_175e:
	/* 0x175e: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_1760:
	/* 0x1760: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1762:
	/* 0x1762: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1768:
	/* 0x1768: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_176b:
	/* 0x176b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1770:
	/* 0x1770: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1776:
	/* 0x1776: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_177b:
	/* 0x177b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1783:
	/* 0x1783: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1787:
	/* 0x1787: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_178e:
	/* 0x178e: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1793:
	/* 0x1793: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1798:
	/* 0x1798: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179a:
	/* 0x179a: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_179f:
	/* 0x179f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_17a7:
	/* 0x17a7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_17aa:
	/* 0x17aa: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_17b2:
	/* 0x17b2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17bb:
	/* 0x17bb: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_17bf:
	/* 0x17bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c4:
	/* 0x17c4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17c9:
	/* 0x17c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17ce:
	/* 0x17ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d0:
	/* 0x17d0: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_17d2:
	/* 0x17d2: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17d8:
	/* 0x17d8: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_17de:
	/* 0x17de: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17e1:
	/* 0x17e1: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_17e6:
	/* 0x17e6: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_17ec:
	/* 0x17ec: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_17f1:
	/* 0x17f1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17f9:
	/* 0x17f9: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_17fd:
	/* 0x17fd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1804:
	/* 0x1804: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1809:
	/* 0x1809: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_180e:
	/* 0x180e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1810:
	/* 0x1810: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1814:
	/* 0x1814: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_1816:
	/* 0x1816: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1818:
	/* 0x1818: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_181e:
	/* 0x181e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1821:
	/* 0x1821: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1826:
	/* 0x1826: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_182c:
	/* 0x182c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1831:
	/* 0x1831: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1839:
	/* 0x1839: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_183d:
	/* 0x183d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1844:
	/* 0x1844: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1849:
	/* 0x1849: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_184e:
	/* 0x184e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1850:
	/* 0x1850: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1855:
	/* 0x1855: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_185d:
	/* 0x185d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1860:
	/* 0x1860: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1868:
	/* 0x1868: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1871:
	/* 0x1871: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1875:
	/* 0x1875: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_187a:
	/* 0x187a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_187f:
	/* 0x187f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1884:
	/* 0x1884: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1886:
	/* 0x1886: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_1888:
	/* 0x1888: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_188e:
	/* 0x188e: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1894:
	/* 0x1894: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1897:
	/* 0x1897: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_189c:
	/* 0x189c: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_18a2:
	/* 0x18a2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_18a7:
	/* 0x18a7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18af:
	/* 0x18af: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_18b3:
	/* 0x18b3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_18ba:
	/* 0x18ba: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18bf:
	/* 0x18bf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_18c4:
	/* 0x18c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c6:
	/* 0x18c6: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_18ca:
	/* 0x18ca: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_18cc:
	/* 0x18cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18ce:
	/* 0x18ce: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_18d4:
	/* 0x18d4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18d7:
	/* 0x18d7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_18dc:
	/* 0x18dc: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_18e2:
	/* 0x18e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18e7:
	/* 0x18e7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18ef:
	/* 0x18ef: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_18f3:
	/* 0x18f3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_18fa:
	/* 0x18fa: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_18ff:
	/* 0x18ff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1904:
	/* 0x1904: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1906:
	/* 0x1906: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_190b:
	/* 0x190b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1913:
	/* 0x1913: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1916:
	/* 0x1916: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_191e:
	/* 0x191e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1927:
	/* 0x1927: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_192b:
	/* 0x192b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1930:
	/* 0x1930: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1935:
	/* 0x1935: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_193a:
	/* 0x193a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193c:
	/* 0x193c: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_193e:
	/* 0x193e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1944:
	/* 0x1944: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_194a:
	/* 0x194a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_194d:
	/* 0x194d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1952:
	/* 0x1952: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1958:
	/* 0x1958: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_195d:
	/* 0x195d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1965:
	/* 0x1965: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1969:
	/* 0x1969: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1970:
	/* 0x1970: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1975:
	/* 0x1975: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_197a:
	/* 0x197a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_197c:
	/* 0x197c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1980:
	/* 0x1980: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_1982:
	/* 0x1982: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1984:
	/* 0x1984: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_198a:
	/* 0x198a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_198d:
	/* 0x198d: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1992:
	/* 0x1992: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1998:
	/* 0x1998: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_199d:
	/* 0x199d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19a5:
	/* 0x19a5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_19a9:
	/* 0x19a9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_19b0:
	/* 0x19b0: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_19b5:
	/* 0x19b5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19ba:
	/* 0x19ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19bc:
	/* 0x19bc: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_19c1:
	/* 0x19c1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_19c9:
	/* 0x19c9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_19cc:
	/* 0x19cc: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_19d4:
	/* 0x19d4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_19dd:
	/* 0x19dd: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_19e1:
	/* 0x19e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19e6:
	/* 0x19e6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19eb:
	/* 0x19eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19f0:
	/* 0x19f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f2:
	/* 0x19f2: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_19f4:
	/* 0x19f4: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_19fa:
	/* 0x19fa: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1a00:
	/* 0x1a00: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a03:
	/* 0x1a03: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1a08:
	/* 0x1a08: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1a0e:
	/* 0x1a0e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1a13:
	/* 0x1a13: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a1b:
	/* 0x1a1b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1a1f:
	/* 0x1a1f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1a26:
	/* 0x1a26: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a2b:
	/* 0x1a2b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a30:
	/* 0x1a30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a32:
	/* 0x1a32: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a36:
	/* 0x1a36: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_1a38:
	/* 0x1a38: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a3a:
	/* 0x1a3a: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1a40:
	/* 0x1a40: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a43:
	/* 0x1a43: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1a48:
	/* 0x1a48: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1a4e:
	/* 0x1a4e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a53:
	/* 0x1a53: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a5b:
	/* 0x1a5b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1a5f:
	/* 0x1a5f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1a66:
	/* 0x1a66: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a6b:
	/* 0x1a6b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a70:
	/* 0x1a70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a72:
	/* 0x1a72: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1a77:
	/* 0x1a77: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1a7f:
	/* 0x1a7f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1a82:
	/* 0x1a82: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1a8a:
	/* 0x1a8a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1a93:
	/* 0x1a93: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1a97:
	/* 0x1a97: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a9c:
	/* 0x1a9c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1aa1:
	/* 0x1aa1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aa6:
	/* 0x1aa6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa8:
	/* 0x1aa8: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1aaa:
	/* 0x1aaa: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ab0:
	/* 0x1ab0: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1ab6:
	/* 0x1ab6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ab9:
	/* 0x1ab9: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1abe:
	/* 0x1abe: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1ac4:
	/* 0x1ac4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1ac9:
	/* 0x1ac9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ad1:
	/* 0x1ad1: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1ad5:
	/* 0x1ad5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1adc:
	/* 0x1adc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ae1:
	/* 0x1ae1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ae6:
	/* 0x1ae6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae8:
	/* 0x1ae8: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1aec:
	/* 0x1aec: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1aee:
	/* 0x1aee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1af0:
	/* 0x1af0: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1af6:
	/* 0x1af6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1af9:
	/* 0x1af9: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1afe:
	/* 0x1afe: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1b04:
	/* 0x1b04: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b09:
	/* 0x1b09: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b11:
	/* 0x1b11: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1b15:
	/* 0x1b15: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1b1c:
	/* 0x1b1c: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b21:
	/* 0x1b21: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b26:
	/* 0x1b26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b28:
	/* 0x1b28: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1b2d:
	/* 0x1b2d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1b35:
	/* 0x1b35: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1b38:
	/* 0x1b38: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1b40:
	/* 0x1b40: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b49:
	/* 0x1b49: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1b50:
	/* 0x1b50: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b55:
	/* 0x1b55: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b5a:
	/* 0x1b5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b5f:
	/* 0x1b5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b61:
	/* 0x1b61: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_1b63:
	/* 0x1b63: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b69:
	/* 0x1b69: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1b6f:
	/* 0x1b6f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b72:
	/* 0x1b72: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1b77:
	/* 0x1b77: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
	return 7037ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7037ULL: goto x86_l_1b7d;
	case 7042ULL: goto x86_l_1b82;
	case 7050ULL: goto x86_l_1b8a;
	case 7054ULL: goto x86_l_1b8e;
	case 7061ULL: goto x86_l_1b95;
	case 7066ULL: goto x86_l_1b9a;
	case 7071ULL: goto x86_l_1b9f;
	case 7073ULL: goto x86_l_1ba1;
	case 7077ULL: goto x86_l_1ba5;
	case 7079ULL: goto x86_l_1ba7;
	case 7081ULL: goto x86_l_1ba9;
	case 7087ULL: goto x86_l_1baf;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7101ULL: goto x86_l_1bbd;
	case 7106ULL: goto x86_l_1bc2;
	case 7114ULL: goto x86_l_1bca;
	case 7118ULL: goto x86_l_1bce;
	case 7125ULL: goto x86_l_1bd5;
	case 7130ULL: goto x86_l_1bda;
	case 7135ULL: goto x86_l_1bdf;
	case 7137ULL: goto x86_l_1be1;
	case 7142ULL: goto x86_l_1be6;
	case 7150ULL: goto x86_l_1bee;
	case 7153ULL: goto x86_l_1bf1;
	case 7161ULL: goto x86_l_1bf9;
	case 7170ULL: goto x86_l_1c02;
	case 7177ULL: goto x86_l_1c09;
	case 7182ULL: goto x86_l_1c0e;
	case 7187ULL: goto x86_l_1c13;
	case 7192ULL: goto x86_l_1c18;
	case 7194ULL: goto x86_l_1c1a;
	case 7196ULL: goto x86_l_1c1c;
	case 7202ULL: goto x86_l_1c22;
	case 7208ULL: goto x86_l_1c28;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7222ULL: goto x86_l_1c36;
	case 7227ULL: goto x86_l_1c3b;
	case 7235ULL: goto x86_l_1c43;
	case 7239ULL: goto x86_l_1c47;
	case 7246ULL: goto x86_l_1c4e;
	case 7251ULL: goto x86_l_1c53;
	case 7256ULL: goto x86_l_1c58;
	case 7258ULL: goto x86_l_1c5a;
	case 7262ULL: goto x86_l_1c5e;
	case 7264ULL: goto x86_l_1c60;
	case 7266ULL: goto x86_l_1c62;
	case 7272ULL: goto x86_l_1c68;
	case 7275ULL: goto x86_l_1c6b;
	case 7280ULL: goto x86_l_1c70;
	case 7286ULL: goto x86_l_1c76;
	case 7291ULL: goto x86_l_1c7b;
	case 7299ULL: goto x86_l_1c83;
	case 7303ULL: goto x86_l_1c87;
	case 7310ULL: goto x86_l_1c8e;
	case 7315ULL: goto x86_l_1c93;
	case 7320ULL: goto x86_l_1c98;
	case 7322ULL: goto x86_l_1c9a;
	case 7327ULL: goto x86_l_1c9f;
	case 7335ULL: goto x86_l_1ca7;
	case 7338ULL: goto x86_l_1caa;
	case 7346ULL: goto x86_l_1cb2;
	case 7355ULL: goto x86_l_1cbb;
	case 7362ULL: goto x86_l_1cc2;
	case 7367ULL: goto x86_l_1cc7;
	case 7372ULL: goto x86_l_1ccc;
	case 7377ULL: goto x86_l_1cd1;
	case 7379ULL: goto x86_l_1cd3;
	case 7381ULL: goto x86_l_1cd5;
	case 7387ULL: goto x86_l_1cdb;
	case 7393ULL: goto x86_l_1ce1;
	case 7396ULL: goto x86_l_1ce4;
	case 7401ULL: goto x86_l_1ce9;
	case 7407ULL: goto x86_l_1cef;
	case 7412ULL: goto x86_l_1cf4;
	case 7420ULL: goto x86_l_1cfc;
	case 7424ULL: goto x86_l_1d00;
	case 7431ULL: goto x86_l_1d07;
	case 7436ULL: goto x86_l_1d0c;
	case 7441ULL: goto x86_l_1d11;
	case 7443ULL: goto x86_l_1d13;
	case 7447ULL: goto x86_l_1d17;
	case 7449ULL: goto x86_l_1d19;
	case 7451ULL: goto x86_l_1d1b;
	case 7457ULL: goto x86_l_1d21;
	case 7460ULL: goto x86_l_1d24;
	case 7465ULL: goto x86_l_1d29;
	case 7471ULL: goto x86_l_1d2f;
	case 7476ULL: goto x86_l_1d34;
	case 7484ULL: goto x86_l_1d3c;
	case 7488ULL: goto x86_l_1d40;
	case 7495ULL: goto x86_l_1d47;
	case 7500ULL: goto x86_l_1d4c;
	case 7505ULL: goto x86_l_1d51;
	case 7507ULL: goto x86_l_1d53;
	case 7512ULL: goto x86_l_1d58;
	case 7520ULL: goto x86_l_1d60;
	case 7523ULL: goto x86_l_1d63;
	case 7531ULL: goto x86_l_1d6b;
	case 7540ULL: goto x86_l_1d74;
	case 7547ULL: goto x86_l_1d7b;
	case 7552ULL: goto x86_l_1d80;
	case 7557ULL: goto x86_l_1d85;
	case 7562ULL: goto x86_l_1d8a;
	case 7564ULL: goto x86_l_1d8c;
	case 7566ULL: goto x86_l_1d8e;
	case 7572ULL: goto x86_l_1d94;
	case 7578ULL: goto x86_l_1d9a;
	case 7581ULL: goto x86_l_1d9d;
	case 7586ULL: goto x86_l_1da2;
	case 7592ULL: goto x86_l_1da8;
	case 7597ULL: goto x86_l_1dad;
	case 7605ULL: goto x86_l_1db5;
	case 7609ULL: goto x86_l_1db9;
	case 7616ULL: goto x86_l_1dc0;
	case 7621ULL: goto x86_l_1dc5;
	case 7626ULL: goto x86_l_1dca;
	case 7628ULL: goto x86_l_1dcc;
	case 7632ULL: goto x86_l_1dd0;
	case 7634ULL: goto x86_l_1dd2;
	case 7636ULL: goto x86_l_1dd4;
	case 7642ULL: goto x86_l_1dda;
	case 7645ULL: goto x86_l_1ddd;
	case 7650ULL: goto x86_l_1de2;
	case 7656ULL: goto x86_l_1de8;
	case 7661ULL: goto x86_l_1ded;
	case 7669ULL: goto x86_l_1df5;
	case 7673ULL: goto x86_l_1df9;
	case 7680ULL: goto x86_l_1e00;
	case 7685ULL: goto x86_l_1e05;
	case 7690ULL: goto x86_l_1e0a;
	case 7692ULL: goto x86_l_1e0c;
	case 7697ULL: goto x86_l_1e11;
	case 7705ULL: goto x86_l_1e19;
	case 7708ULL: goto x86_l_1e1c;
	case 7716ULL: goto x86_l_1e24;
	case 7725ULL: goto x86_l_1e2d;
	case 7732ULL: goto x86_l_1e34;
	case 7737ULL: goto x86_l_1e39;
	case 7742ULL: goto x86_l_1e3e;
	case 7747ULL: goto x86_l_1e43;
	case 7749ULL: goto x86_l_1e45;
	case 7751ULL: goto x86_l_1e47;
	case 7757ULL: goto x86_l_1e4d;
	case 7763ULL: goto x86_l_1e53;
	case 7766ULL: goto x86_l_1e56;
	case 7771ULL: goto x86_l_1e5b;
	case 7777ULL: goto x86_l_1e61;
	case 7782ULL: goto x86_l_1e66;
	case 7790ULL: goto x86_l_1e6e;
	case 7794ULL: goto x86_l_1e72;
	case 7801ULL: goto x86_l_1e79;
	case 7806ULL: goto x86_l_1e7e;
	case 7811ULL: goto x86_l_1e83;
	case 7813ULL: goto x86_l_1e85;
	case 7817ULL: goto x86_l_1e89;
	case 7819ULL: goto x86_l_1e8b;
	case 7821ULL: goto x86_l_1e8d;
	case 7827ULL: goto x86_l_1e93;
	case 7830ULL: goto x86_l_1e96;
	case 7835ULL: goto x86_l_1e9b;
	case 7841ULL: goto x86_l_1ea1;
	case 7846ULL: goto x86_l_1ea6;
	case 7854ULL: goto x86_l_1eae;
	case 7858ULL: goto x86_l_1eb2;
	case 7865ULL: goto x86_l_1eb9;
	case 7870ULL: goto x86_l_1ebe;
	case 7875ULL: goto x86_l_1ec3;
	case 7877ULL: goto x86_l_1ec5;
	case 7882ULL: goto x86_l_1eca;
	case 7890ULL: goto x86_l_1ed2;
	case 7893ULL: goto x86_l_1ed5;
	case 7901ULL: goto x86_l_1edd;
	case 7910ULL: goto x86_l_1ee6;
	case 7917ULL: goto x86_l_1eed;
	case 7922ULL: goto x86_l_1ef2;
	case 7927ULL: goto x86_l_1ef7;
	case 7932ULL: goto x86_l_1efc;
	case 7934ULL: goto x86_l_1efe;
	case 7936ULL: goto x86_l_1f00;
	case 7942ULL: goto x86_l_1f06;
	case 7948ULL: goto x86_l_1f0c;
	case 7951ULL: goto x86_l_1f0f;
	case 7956ULL: goto x86_l_1f14;
	case 7962ULL: goto x86_l_1f1a;
	case 7967ULL: goto x86_l_1f1f;
	case 7975ULL: goto x86_l_1f27;
	case 7979ULL: goto x86_l_1f2b;
	case 7986ULL: goto x86_l_1f32;
	case 7991ULL: goto x86_l_1f37;
	case 7996ULL: goto x86_l_1f3c;
	case 7998ULL: goto x86_l_1f3e;
	case 8002ULL: goto x86_l_1f42;
	case 8004ULL: goto x86_l_1f44;
	case 8006ULL: goto x86_l_1f46;
	case 8012ULL: goto x86_l_1f4c;
	case 8015ULL: goto x86_l_1f4f;
	case 8020ULL: goto x86_l_1f54;
	case 8026ULL: goto x86_l_1f5a;
	case 8031ULL: goto x86_l_1f5f;
	case 8039ULL: goto x86_l_1f67;
	case 8043ULL: goto x86_l_1f6b;
	case 8050ULL: goto x86_l_1f72;
	case 8055ULL: goto x86_l_1f77;
	case 8060ULL: goto x86_l_1f7c;
	case 8062ULL: goto x86_l_1f7e;
	case 8067ULL: goto x86_l_1f83;
	case 8075ULL: goto x86_l_1f8b;
	case 8078ULL: goto x86_l_1f8e;
	case 8086ULL: goto x86_l_1f96;
	case 8095ULL: goto x86_l_1f9f;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8112ULL: goto x86_l_1fb0;
	case 8117ULL: goto x86_l_1fb5;
	case 8119ULL: goto x86_l_1fb7;
	case 8121ULL: goto x86_l_1fb9;
	case 8127ULL: goto x86_l_1fbf;
	case 8133ULL: goto x86_l_1fc5;
	case 8136ULL: goto x86_l_1fc8;
	case 8141ULL: goto x86_l_1fcd;
	case 8147ULL: goto x86_l_1fd3;
	case 8152ULL: goto x86_l_1fd8;
	case 8160ULL: goto x86_l_1fe0;
	case 8164ULL: goto x86_l_1fe4;
	case 8171ULL: goto x86_l_1feb;
	case 8176ULL: goto x86_l_1ff0;
	case 8181ULL: goto x86_l_1ff5;
	case 8183ULL: goto x86_l_1ff7;
	case 8187ULL: goto x86_l_1ffb;
	case 8189ULL: goto x86_l_1ffd;
	case 8191ULL: goto x86_l_1fff;
	case 8197ULL: goto x86_l_2005;
	case 8200ULL: goto x86_l_2008;
	case 8205ULL: goto x86_l_200d;
	case 8211ULL: goto x86_l_2013;
	case 8216ULL: goto x86_l_2018;
	case 8224ULL: goto x86_l_2020;
	case 8228ULL: goto x86_l_2024;
	case 8235ULL: goto x86_l_202b;
	case 8240ULL: goto x86_l_2030;
	case 8245ULL: goto x86_l_2035;
	case 8247ULL: goto x86_l_2037;
	case 8252ULL: goto x86_l_203c;
	case 8260ULL: goto x86_l_2044;
	case 8263ULL: goto x86_l_2047;
	case 8271ULL: goto x86_l_204f;
	case 8280ULL: goto x86_l_2058;
	case 8287ULL: goto x86_l_205f;
	case 8292ULL: goto x86_l_2064;
	case 8297ULL: goto x86_l_2069;
	case 8302ULL: goto x86_l_206e;
	case 8304ULL: goto x86_l_2070;
	case 8306ULL: goto x86_l_2072;
	case 8312ULL: goto x86_l_2078;
	case 8318ULL: goto x86_l_207e;
	case 8321ULL: goto x86_l_2081;
	case 8326ULL: goto x86_l_2086;
	case 8332ULL: goto x86_l_208c;
	case 8337ULL: goto x86_l_2091;
	case 8345ULL: goto x86_l_2099;
	case 8349ULL: goto x86_l_209d;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8366ULL: goto x86_l_20ae;
	case 8368ULL: goto x86_l_20b0;
	case 8372ULL: goto x86_l_20b4;
	case 8374ULL: goto x86_l_20b6;
	case 8376ULL: goto x86_l_20b8;
	case 8382ULL: goto x86_l_20be;
	case 8385ULL: goto x86_l_20c1;
	case 8390ULL: goto x86_l_20c6;
	case 8396ULL: goto x86_l_20cc;
	case 8401ULL: goto x86_l_20d1;
	case 8409ULL: goto x86_l_20d9;
	case 8413ULL: goto x86_l_20dd;
	case 8420ULL: goto x86_l_20e4;
	case 8425ULL: goto x86_l_20e9;
	case 8430ULL: goto x86_l_20ee;
	case 8432ULL: goto x86_l_20f0;
	case 8437ULL: goto x86_l_20f5;
	case 8445ULL: goto x86_l_20fd;
	case 8448ULL: goto x86_l_2100;
	case 8456ULL: goto x86_l_2108;
	case 8465ULL: goto x86_l_2111;
	case 8472ULL: goto x86_l_2118;
	case 8477ULL: goto x86_l_211d;
	case 8482ULL: goto x86_l_2122;
	case 8487ULL: goto x86_l_2127;
	case 8489ULL: goto x86_l_2129;
	case 8491ULL: goto x86_l_212b;
	case 8497ULL: goto x86_l_2131;
	case 8503ULL: goto x86_l_2137;
	case 8506ULL: goto x86_l_213a;
	case 8511ULL: goto x86_l_213f;
	case 8517ULL: goto x86_l_2145;
	case 8522ULL: goto x86_l_214a;
	case 8530ULL: goto x86_l_2152;
	case 8534ULL: goto x86_l_2156;
	case 8541ULL: goto x86_l_215d;
	case 8546ULL: goto x86_l_2162;
	case 8551ULL: goto x86_l_2167;
	case 8553ULL: goto x86_l_2169;
	case 8557ULL: goto x86_l_216d;
	case 8559ULL: goto x86_l_216f;
	case 8561ULL: goto x86_l_2171;
	case 8567ULL: goto x86_l_2177;
	case 8570ULL: goto x86_l_217a;
	case 8575ULL: goto x86_l_217f;
	case 8581ULL: goto x86_l_2185;
	case 8586ULL: goto x86_l_218a;
	case 8594ULL: goto x86_l_2192;
	case 8598ULL: goto x86_l_2196;
	case 8605ULL: goto x86_l_219d;
	case 8610ULL: goto x86_l_21a2;
	case 8615ULL: goto x86_l_21a7;
	case 8617ULL: goto x86_l_21a9;
	case 8622ULL: goto x86_l_21ae;
	case 8630ULL: goto x86_l_21b6;
	case 8633ULL: goto x86_l_21b9;
	case 8641ULL: goto x86_l_21c1;
	case 8650ULL: goto x86_l_21ca;
	case 8657ULL: goto x86_l_21d1;
	case 8662ULL: goto x86_l_21d6;
	case 8667ULL: goto x86_l_21db;
	case 8672ULL: goto x86_l_21e0;
	case 8674ULL: goto x86_l_21e2;
	case 8676ULL: goto x86_l_21e4;
	case 8682ULL: goto x86_l_21ea;
	case 8688ULL: goto x86_l_21f0;
	case 8691ULL: goto x86_l_21f3;
	case 8696ULL: goto x86_l_21f8;
	case 8702ULL: goto x86_l_21fe;
	case 8707ULL: goto x86_l_2203;
	case 8715ULL: goto x86_l_220b;
	case 8719ULL: goto x86_l_220f;
	case 8726ULL: goto x86_l_2216;
	case 8731ULL: goto x86_l_221b;
	case 8736ULL: goto x86_l_2220;
	case 8738ULL: goto x86_l_2222;
	case 8742ULL: goto x86_l_2226;
	case 8744ULL: goto x86_l_2228;
	case 8746ULL: goto x86_l_222a;
	case 8752ULL: goto x86_l_2230;
	case 8755ULL: goto x86_l_2233;
	case 8760ULL: goto x86_l_2238;
	case 8766ULL: goto x86_l_223e;
	case 8771ULL: goto x86_l_2243;
	case 8779ULL: goto x86_l_224b;
	case 8783ULL: goto x86_l_224f;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8800ULL: goto x86_l_2260;
	case 8802ULL: goto x86_l_2262;
	case 8807ULL: goto x86_l_2267;
	case 8815ULL: goto x86_l_226f;
	case 8818ULL: goto x86_l_2272;
	case 8826ULL: goto x86_l_227a;
	case 8835ULL: goto x86_l_2283;
	case 8842ULL: goto x86_l_228a;
	case 8847ULL: goto x86_l_228f;
	case 8852ULL: goto x86_l_2294;
	case 8857ULL: goto x86_l_2299;
	case 8859ULL: goto x86_l_229b;
	case 8861ULL: goto x86_l_229d;
	case 8867ULL: goto x86_l_22a3;
	case 8873ULL: goto x86_l_22a9;
	case 8876ULL: goto x86_l_22ac;
	case 8881ULL: goto x86_l_22b1;
	case 8887ULL: goto x86_l_22b7;
	case 8892ULL: goto x86_l_22bc;
	case 8900ULL: goto x86_l_22c4;
	case 8904ULL: goto x86_l_22c8;
	case 8911ULL: goto x86_l_22cf;
	case 8916ULL: goto x86_l_22d4;
	case 8921ULL: goto x86_l_22d9;
	case 8923ULL: goto x86_l_22db;
	case 8927ULL: goto x86_l_22df;
	case 8929ULL: goto x86_l_22e1;
	case 8931ULL: goto x86_l_22e3;
	case 8937ULL: goto x86_l_22e9;
	case 8940ULL: goto x86_l_22ec;
	case 8945ULL: goto x86_l_22f1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b7d:
	/* 0x1b7d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1b82:
	/* 0x1b82: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b8a:
	/* 0x1b8a: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1b8e:
	/* 0x1b8e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1b95:
	/* 0x1b95: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b9a:
	/* 0x1b9a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1b9f:
	/* 0x1b9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba1:
	/* 0x1ba1: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ba5:
	/* 0x1ba5: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_1ba7:
	/* 0x1ba7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ba9:
	/* 0x1ba9: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1baf:
	/* 0x1baf: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1bb2:
	/* 0x1bb2: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1bb7:
	/* 0x1bb7: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1bbd:
	/* 0x1bbd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bc2:
	/* 0x1bc2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1bca:
	/* 0x1bca: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1bce:
	/* 0x1bce: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1bd5:
	/* 0x1bd5: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1bda:
	/* 0x1bda: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bdf:
	/* 0x1bdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be1:
	/* 0x1be1: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1be6:
	/* 0x1be6: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1bee:
	/* 0x1bee: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1bf1:
	/* 0x1bf1: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1bf9:
	/* 0x1bf9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c02:
	/* 0x1c02: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1c09:
	/* 0x1c09: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c0e:
	/* 0x1c0e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c13:
	/* 0x1c13: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c18:
	/* 0x1c18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c1a:
	/* 0x1c1a: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_1c1c:
	/* 0x1c1c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c22:
	/* 0x1c22: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1c28:
	/* 0x1c28: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c2b:
	/* 0x1c2b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1c30:
	/* 0x1c30: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1c36:
	/* 0x1c36: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1c3b:
	/* 0x1c3b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c43:
	/* 0x1c43: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1c47:
	/* 0x1c47: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1c4e:
	/* 0x1c4e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c53:
	/* 0x1c53: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1c58:
	/* 0x1c58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c5a:
	/* 0x1c5a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c5e:
	/* 0x1c5e: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_1c60:
	/* 0x1c60: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c62:
	/* 0x1c62: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1c68:
	/* 0x1c68: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c6b:
	/* 0x1c6b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1c70:
	/* 0x1c70: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1c76:
	/* 0x1c76: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c7b:
	/* 0x1c7b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c83:
	/* 0x1c83: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1c87:
	/* 0x1c87: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1c8e:
	/* 0x1c8e: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c93:
	/* 0x1c93: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c98:
	/* 0x1c98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9a:
	/* 0x1c9a: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1c9f:
	/* 0x1c9f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1ca7:
	/* 0x1ca7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1caa:
	/* 0x1caa: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1cb2:
	/* 0x1cb2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1cbb:
	/* 0x1cbb: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1cc2:
	/* 0x1cc2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cc7:
	/* 0x1cc7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ccc:
	/* 0x1ccc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cd1:
	/* 0x1cd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd3:
	/* 0x1cd3: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_1cd5:
	/* 0x1cd5: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1cdb:
	/* 0x1cdb: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1ce1:
	/* 0x1ce1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ce4:
	/* 0x1ce4: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1ce9:
	/* 0x1ce9: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1cef:
	/* 0x1cef: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1cf4:
	/* 0x1cf4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1cfc:
	/* 0x1cfc: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1d00:
	/* 0x1d00: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1d07:
	/* 0x1d07: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d0c:
	/* 0x1d0c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1d11:
	/* 0x1d11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d13:
	/* 0x1d13: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d17:
	/* 0x1d17: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_1d19:
	/* 0x1d19: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d1b:
	/* 0x1d1b: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1d21:
	/* 0x1d21: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d24:
	/* 0x1d24: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1d29:
	/* 0x1d29: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1d2f:
	/* 0x1d2f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d34:
	/* 0x1d34: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d3c:
	/* 0x1d3c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1d40:
	/* 0x1d40: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1d47:
	/* 0x1d47: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d4c:
	/* 0x1d4c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d51:
	/* 0x1d51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d53:
	/* 0x1d53: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1d58:
	/* 0x1d58: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1d60:
	/* 0x1d60: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1d63:
	/* 0x1d63: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1d6b:
	/* 0x1d6b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d74:
	/* 0x1d74: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1d7b:
	/* 0x1d7b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d80:
	/* 0x1d80: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d85:
	/* 0x1d85: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d8a:
	/* 0x1d8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d8c:
	/* 0x1d8c: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_1d8e:
	/* 0x1d8e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d94:
	/* 0x1d94: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1d9a:
	/* 0x1d9a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d9d:
	/* 0x1d9d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1da2:
	/* 0x1da2: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1da8:
	/* 0x1da8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1dad:
	/* 0x1dad: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1db5:
	/* 0x1db5: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1db9:
	/* 0x1db9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1dc0:
	/* 0x1dc0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dc5:
	/* 0x1dc5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1dca:
	/* 0x1dca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dcc:
	/* 0x1dcc: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1dd0:
	/* 0x1dd0: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_1dd2:
	/* 0x1dd2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dd4:
	/* 0x1dd4: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1dda:
	/* 0x1dda: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ddd:
	/* 0x1ddd: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1de2:
	/* 0x1de2: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1de8:
	/* 0x1de8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ded:
	/* 0x1ded: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1df5:
	/* 0x1df5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1df9:
	/* 0x1df9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1e00:
	/* 0x1e00: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e05:
	/* 0x1e05: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e0a:
	/* 0x1e0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0c:
	/* 0x1e0c: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1e11:
	/* 0x1e11: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1e19:
	/* 0x1e19: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1e1c:
	/* 0x1e1c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e24:
	/* 0x1e24: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e2d:
	/* 0x1e2d: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1e34:
	/* 0x1e34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e39:
	/* 0x1e39: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e3e:
	/* 0x1e3e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e43:
	/* 0x1e43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e45:
	/* 0x1e45: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_1e47:
	/* 0x1e47: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e4d:
	/* 0x1e4d: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1e53:
	/* 0x1e53: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e56:
	/* 0x1e56: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1e5b:
	/* 0x1e5b: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1e61:
	/* 0x1e61: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e66:
	/* 0x1e66: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e6e:
	/* 0x1e6e: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1e72:
	/* 0x1e72: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1e79:
	/* 0x1e79: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e7e:
	/* 0x1e7e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e83:
	/* 0x1e83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e85:
	/* 0x1e85: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e89:
	/* 0x1e89: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_1e8b:
	/* 0x1e8b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e8d:
	/* 0x1e8d: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1e93:
	/* 0x1e93: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e96:
	/* 0x1e96: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1e9b:
	/* 0x1e9b: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1ea1:
	/* 0x1ea1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ea6:
	/* 0x1ea6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1eae:
	/* 0x1eae: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1eb2:
	/* 0x1eb2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1eb9:
	/* 0x1eb9: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ebe:
	/* 0x1ebe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ec3:
	/* 0x1ec3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec5:
	/* 0x1ec5: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1eca:
	/* 0x1eca: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1ed2:
	/* 0x1ed2: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1ed5:
	/* 0x1ed5: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1edd:
	/* 0x1edd: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ee6:
	/* 0x1ee6: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1eed:
	/* 0x1eed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ef2:
	/* 0x1ef2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ef7:
	/* 0x1ef7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1efc:
	/* 0x1efc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1efe:
	/* 0x1efe: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_1f00:
	/* 0x1f00: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f06:
	/* 0x1f06: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1f0c:
	/* 0x1f0c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f0f:
	/* 0x1f0f: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1f14:
	/* 0x1f14: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1f1a:
	/* 0x1f1a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f1f:
	/* 0x1f1f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f27:
	/* 0x1f27: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1f2b:
	/* 0x1f2b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1f32:
	/* 0x1f32: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f37:
	/* 0x1f37: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1f3c:
	/* 0x1f3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f3e:
	/* 0x1f3e: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f42:
	/* 0x1f42: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_1f44:
	/* 0x1f44: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f46:
	/* 0x1f46: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1f4c:
	/* 0x1f4c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f4f:
	/* 0x1f4f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1f54:
	/* 0x1f54: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1f5a:
	/* 0x1f5a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f5f:
	/* 0x1f5f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f67:
	/* 0x1f67: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1f6b:
	/* 0x1f6b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1f72:
	/* 0x1f72: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f77:
	/* 0x1f77: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f7c:
	/* 0x1f7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f7e:
	/* 0x1f7e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1f83:
	/* 0x1f83: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1f8b:
	/* 0x1f8b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1f8e:
	/* 0x1f8e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1f96:
	/* 0x1f96: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f9f:
	/* 0x1f9f: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1fa6:
	/* 0x1fa6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fab:
	/* 0x1fab: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fb0:
	/* 0x1fb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fb5:
	/* 0x1fb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb7:
	/* 0x1fb7: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_1fb9:
	/* 0x1fb9: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1fbf:
	/* 0x1fbf: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1fc5:
	/* 0x1fc5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fc8:
	/* 0x1fc8: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1fcd:
	/* 0x1fcd: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1fd3:
	/* 0x1fd3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1fd8:
	/* 0x1fd8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fe0:
	/* 0x1fe0: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1fe4:
	/* 0x1fe4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1feb:
	/* 0x1feb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ff0:
	/* 0x1ff0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ff5:
	/* 0x1ff5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff7:
	/* 0x1ff7: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ffb:
	/* 0x1ffb: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_1ffd:
	/* 0x1ffd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fff:
	/* 0x1fff: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2005:
	/* 0x2005: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2008:
	/* 0x2008: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_200d:
	/* 0x200d: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2013:
	/* 0x2013: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2018:
	/* 0x2018: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2020:
	/* 0x2020: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2024:
	/* 0x2024: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_202b:
	/* 0x202b: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2030:
	/* 0x2030: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2035:
	/* 0x2035: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2037:
	/* 0x2037: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_203c:
	/* 0x203c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2044:
	/* 0x2044: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2047:
	/* 0x2047: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_204f:
	/* 0x204f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2058:
	/* 0x2058: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_205f:
	/* 0x205f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2064:
	/* 0x2064: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2069:
	/* 0x2069: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_206e:
	/* 0x206e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2070:
	/* 0x2070: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_2072:
	/* 0x2072: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2078:
	/* 0x2078: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_207e:
	/* 0x207e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2081:
	/* 0x2081: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2086:
	/* 0x2086: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_208c:
	/* 0x208c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2091:
	/* 0x2091: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2099:
	/* 0x2099: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_209d:
	/* 0x209d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_20a4:
	/* 0x20a4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20a9:
	/* 0x20a9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_20ae:
	/* 0x20ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b0:
	/* 0x20b0: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_20b4:
	/* 0x20b4: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_20b6:
	/* 0x20b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20b8:
	/* 0x20b8: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_20be:
	/* 0x20be: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20c1:
	/* 0x20c1: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_20c6:
	/* 0x20c6: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_20cc:
	/* 0x20cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20d1:
	/* 0x20d1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_20d9:
	/* 0x20d9: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_20dd:
	/* 0x20dd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_20e4:
	/* 0x20e4: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_20e9:
	/* 0x20e9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20ee:
	/* 0x20ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f0:
	/* 0x20f0: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_20f5:
	/* 0x20f5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_20fd:
	/* 0x20fd: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2100:
	/* 0x2100: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2108:
	/* 0x2108: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2111:
	/* 0x2111: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2118:
	/* 0x2118: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_211d:
	/* 0x211d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2122:
	/* 0x2122: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2127:
	/* 0x2127: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2129:
	/* 0x2129: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_212b:
	/* 0x212b: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2131:
	/* 0x2131: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_2137:
	/* 0x2137: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_213a:
	/* 0x213a: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_213f:
	/* 0x213f: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2145:
	/* 0x2145: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_214a:
	/* 0x214a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2152:
	/* 0x2152: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2156:
	/* 0x2156: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_215d:
	/* 0x215d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2162:
	/* 0x2162: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2167:
	/* 0x2167: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2169:
	/* 0x2169: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_216d:
	/* 0x216d: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_216f:
	/* 0x216f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2171:
	/* 0x2171: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2177:
	/* 0x2177: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_217a:
	/* 0x217a: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_217f:
	/* 0x217f: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2185:
	/* 0x2185: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_218a:
	/* 0x218a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2192:
	/* 0x2192: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2196:
	/* 0x2196: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_219d:
	/* 0x219d: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_21a2:
	/* 0x21a2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21a7:
	/* 0x21a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a9:
	/* 0x21a9: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_21ae:
	/* 0x21ae: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_21b6:
	/* 0x21b6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_21b9:
	/* 0x21b9: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_21c1:
	/* 0x21c1: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_21ca:
	/* 0x21ca: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_21d1:
	/* 0x21d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21d6:
	/* 0x21d6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21db:
	/* 0x21db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21e0:
	/* 0x21e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e2:
	/* 0x21e2: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_21e4:
	/* 0x21e4: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_21ea:
	/* 0x21ea: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_21f0:
	/* 0x21f0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21f3:
	/* 0x21f3: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_21f8:
	/* 0x21f8: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_21fe:
	/* 0x21fe: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2203:
	/* 0x2203: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_220b:
	/* 0x220b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_220f:
	/* 0x220f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2216:
	/* 0x2216: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_221b:
	/* 0x221b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2220:
	/* 0x2220: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2222:
	/* 0x2222: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2226:
	/* 0x2226: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_2228:
	/* 0x2228: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_222a:
	/* 0x222a: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2230:
	/* 0x2230: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2233:
	/* 0x2233: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2238:
	/* 0x2238: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_223e:
	/* 0x223e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2243:
	/* 0x2243: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_224b:
	/* 0x224b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_224f:
	/* 0x224f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2256:
	/* 0x2256: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_225b:
	/* 0x225b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2260:
	/* 0x2260: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2262:
	/* 0x2262: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2267:
	/* 0x2267: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_226f:
	/* 0x226f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2272:
	/* 0x2272: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_227a:
	/* 0x227a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2283:
	/* 0x2283: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_228a:
	/* 0x228a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_228f:
	/* 0x228f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2294:
	/* 0x2294: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2299:
	/* 0x2299: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_229b:
	/* 0x229b: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_229d:
	/* 0x229d: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_22a3:
	/* 0x22a3: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_22a9:
	/* 0x22a9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22ac:
	/* 0x22ac: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_22b1:
	/* 0x22b1: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_22b7:
	/* 0x22b7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_22bc:
	/* 0x22bc: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_22c4:
	/* 0x22c4: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_22c8:
	/* 0x22c8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_22cf:
	/* 0x22cf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22d4:
	/* 0x22d4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_22d9:
	/* 0x22d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22db:
	/* 0x22db: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_22df:
	/* 0x22df: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_22e1:
	/* 0x22e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22e3:
	/* 0x22e3: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_22e9:
	/* 0x22e9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22ec:
	/* 0x22ec: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_22f1:
	/* 0x22f1: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
	return 8951ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8951ULL: goto x86_l_22f7;
	case 8956ULL: goto x86_l_22fc;
	case 8964ULL: goto x86_l_2304;
	case 8968ULL: goto x86_l_2308;
	case 8975ULL: goto x86_l_230f;
	case 8980ULL: goto x86_l_2314;
	case 8985ULL: goto x86_l_2319;
	case 8987ULL: goto x86_l_231b;
	case 8992ULL: goto x86_l_2320;
	case 9000ULL: goto x86_l_2328;
	case 9003ULL: goto x86_l_232b;
	case 9011ULL: goto x86_l_2333;
	case 9020ULL: goto x86_l_233c;
	case 9027ULL: goto x86_l_2343;
	case 9032ULL: goto x86_l_2348;
	case 9037ULL: goto x86_l_234d;
	case 9042ULL: goto x86_l_2352;
	case 9044ULL: goto x86_l_2354;
	case 9046ULL: goto x86_l_2356;
	case 9052ULL: goto x86_l_235c;
	case 9058ULL: goto x86_l_2362;
	case 9061ULL: goto x86_l_2365;
	case 9066ULL: goto x86_l_236a;
	case 9072ULL: goto x86_l_2370;
	case 9077ULL: goto x86_l_2375;
	case 9085ULL: goto x86_l_237d;
	case 9089ULL: goto x86_l_2381;
	case 9096ULL: goto x86_l_2388;
	case 9101ULL: goto x86_l_238d;
	case 9106ULL: goto x86_l_2392;
	case 9108ULL: goto x86_l_2394;
	case 9112ULL: goto x86_l_2398;
	case 9114ULL: goto x86_l_239a;
	case 9116ULL: goto x86_l_239c;
	case 9122ULL: goto x86_l_23a2;
	case 9125ULL: goto x86_l_23a5;
	case 9130ULL: goto x86_l_23aa;
	case 9136ULL: goto x86_l_23b0;
	case 9141ULL: goto x86_l_23b5;
	case 9149ULL: goto x86_l_23bd;
	case 9153ULL: goto x86_l_23c1;
	case 9160ULL: goto x86_l_23c8;
	case 9165ULL: goto x86_l_23cd;
	case 9170ULL: goto x86_l_23d2;
	case 9172ULL: goto x86_l_23d4;
	case 9177ULL: goto x86_l_23d9;
	case 9185ULL: goto x86_l_23e1;
	case 9188ULL: goto x86_l_23e4;
	case 9196ULL: goto x86_l_23ec;
	case 9205ULL: goto x86_l_23f5;
	case 9212ULL: goto x86_l_23fc;
	case 9217ULL: goto x86_l_2401;
	case 9222ULL: goto x86_l_2406;
	case 9227ULL: goto x86_l_240b;
	case 9229ULL: goto x86_l_240d;
	case 9231ULL: goto x86_l_240f;
	case 9237ULL: goto x86_l_2415;
	case 9243ULL: goto x86_l_241b;
	case 9246ULL: goto x86_l_241e;
	case 9251ULL: goto x86_l_2423;
	case 9257ULL: goto x86_l_2429;
	case 9262ULL: goto x86_l_242e;
	case 9270ULL: goto x86_l_2436;
	case 9274ULL: goto x86_l_243a;
	case 9281ULL: goto x86_l_2441;
	case 9286ULL: goto x86_l_2446;
	case 9291ULL: goto x86_l_244b;
	case 9293ULL: goto x86_l_244d;
	case 9297ULL: goto x86_l_2451;
	case 9299ULL: goto x86_l_2453;
	case 9301ULL: goto x86_l_2455;
	case 9307ULL: goto x86_l_245b;
	case 9310ULL: goto x86_l_245e;
	case 9315ULL: goto x86_l_2463;
	case 9321ULL: goto x86_l_2469;
	case 9326ULL: goto x86_l_246e;
	case 9334ULL: goto x86_l_2476;
	case 9338ULL: goto x86_l_247a;
	case 9345ULL: goto x86_l_2481;
	case 9350ULL: goto x86_l_2486;
	case 9355ULL: goto x86_l_248b;
	case 9357ULL: goto x86_l_248d;
	case 9362ULL: goto x86_l_2492;
	case 9370ULL: goto x86_l_249a;
	case 9373ULL: goto x86_l_249d;
	case 9381ULL: goto x86_l_24a5;
	case 9390ULL: goto x86_l_24ae;
	case 9397ULL: goto x86_l_24b5;
	case 9402ULL: goto x86_l_24ba;
	case 9407ULL: goto x86_l_24bf;
	case 9412ULL: goto x86_l_24c4;
	case 9414ULL: goto x86_l_24c6;
	case 9416ULL: goto x86_l_24c8;
	case 9422ULL: goto x86_l_24ce;
	case 9428ULL: goto x86_l_24d4;
	case 9431ULL: goto x86_l_24d7;
	case 9436ULL: goto x86_l_24dc;
	case 9442ULL: goto x86_l_24e2;
	case 9447ULL: goto x86_l_24e7;
	case 9455ULL: goto x86_l_24ef;
	case 9459ULL: goto x86_l_24f3;
	case 9466ULL: goto x86_l_24fa;
	case 9471ULL: goto x86_l_24ff;
	case 9476ULL: goto x86_l_2504;
	case 9478ULL: goto x86_l_2506;
	case 9482ULL: goto x86_l_250a;
	case 9484ULL: goto x86_l_250c;
	case 9486ULL: goto x86_l_250e;
	case 9492ULL: goto x86_l_2514;
	case 9495ULL: goto x86_l_2517;
	case 9500ULL: goto x86_l_251c;
	case 9506ULL: goto x86_l_2522;
	case 9511ULL: goto x86_l_2527;
	case 9519ULL: goto x86_l_252f;
	case 9523ULL: goto x86_l_2533;
	case 9530ULL: goto x86_l_253a;
	case 9535ULL: goto x86_l_253f;
	case 9540ULL: goto x86_l_2544;
	case 9542ULL: goto x86_l_2546;
	case 9547ULL: goto x86_l_254b;
	case 9555ULL: goto x86_l_2553;
	case 9558ULL: goto x86_l_2556;
	case 9566ULL: goto x86_l_255e;
	case 9575ULL: goto x86_l_2567;
	case 9582ULL: goto x86_l_256e;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9597ULL: goto x86_l_257d;
	case 9599ULL: goto x86_l_257f;
	case 9601ULL: goto x86_l_2581;
	case 9607ULL: goto x86_l_2587;
	case 9613ULL: goto x86_l_258d;
	case 9616ULL: goto x86_l_2590;
	case 9621ULL: goto x86_l_2595;
	case 9627ULL: goto x86_l_259b;
	case 9632ULL: goto x86_l_25a0;
	case 9640ULL: goto x86_l_25a8;
	case 9644ULL: goto x86_l_25ac;
	case 9651ULL: goto x86_l_25b3;
	case 9656ULL: goto x86_l_25b8;
	case 9661ULL: goto x86_l_25bd;
	case 9663ULL: goto x86_l_25bf;
	case 9667ULL: goto x86_l_25c3;
	case 9669ULL: goto x86_l_25c5;
	case 9671ULL: goto x86_l_25c7;
	case 9677ULL: goto x86_l_25cd;
	case 9680ULL: goto x86_l_25d0;
	case 9685ULL: goto x86_l_25d5;
	case 9691ULL: goto x86_l_25db;
	case 9696ULL: goto x86_l_25e0;
	case 9704ULL: goto x86_l_25e8;
	case 9708ULL: goto x86_l_25ec;
	case 9715ULL: goto x86_l_25f3;
	case 9720ULL: goto x86_l_25f8;
	case 9725ULL: goto x86_l_25fd;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9740ULL: goto x86_l_260c;
	case 9743ULL: goto x86_l_260f;
	case 9751ULL: goto x86_l_2617;
	case 9760ULL: goto x86_l_2620;
	case 9767ULL: goto x86_l_2627;
	case 9772ULL: goto x86_l_262c;
	case 9777ULL: goto x86_l_2631;
	case 9782ULL: goto x86_l_2636;
	case 9784ULL: goto x86_l_2638;
	case 9786ULL: goto x86_l_263a;
	case 9792ULL: goto x86_l_2640;
	case 9798ULL: goto x86_l_2646;
	case 9801ULL: goto x86_l_2649;
	case 9806ULL: goto x86_l_264e;
	case 9812ULL: goto x86_l_2654;
	case 9817ULL: goto x86_l_2659;
	case 9825ULL: goto x86_l_2661;
	case 9829ULL: goto x86_l_2665;
	case 9836ULL: goto x86_l_266c;
	case 9841ULL: goto x86_l_2671;
	case 9846ULL: goto x86_l_2676;
	case 9848ULL: goto x86_l_2678;
	case 9852ULL: goto x86_l_267c;
	case 9854ULL: goto x86_l_267e;
	case 9856ULL: goto x86_l_2680;
	case 9862ULL: goto x86_l_2686;
	case 9865ULL: goto x86_l_2689;
	case 9870ULL: goto x86_l_268e;
	case 9876ULL: goto x86_l_2694;
	case 9881ULL: goto x86_l_2699;
	case 9889ULL: goto x86_l_26a1;
	case 9893ULL: goto x86_l_26a5;
	case 9900ULL: goto x86_l_26ac;
	case 9905ULL: goto x86_l_26b1;
	case 9910ULL: goto x86_l_26b6;
	case 9912ULL: goto x86_l_26b8;
	case 9917ULL: goto x86_l_26bd;
	case 9925ULL: goto x86_l_26c5;
	case 9928ULL: goto x86_l_26c8;
	case 9936ULL: goto x86_l_26d0;
	case 9945ULL: goto x86_l_26d9;
	case 9952ULL: goto x86_l_26e0;
	case 9957ULL: goto x86_l_26e5;
	case 9962ULL: goto x86_l_26ea;
	case 9967ULL: goto x86_l_26ef;
	case 9969ULL: goto x86_l_26f1;
	case 9971ULL: goto x86_l_26f3;
	case 9977ULL: goto x86_l_26f9;
	case 9983ULL: goto x86_l_26ff;
	case 9986ULL: goto x86_l_2702;
	case 9991ULL: goto x86_l_2707;
	case 9997ULL: goto x86_l_270d;
	case 10002ULL: goto x86_l_2712;
	case 10010ULL: goto x86_l_271a;
	case 10014ULL: goto x86_l_271e;
	case 10021ULL: goto x86_l_2725;
	case 10026ULL: goto x86_l_272a;
	case 10031ULL: goto x86_l_272f;
	case 10033ULL: goto x86_l_2731;
	case 10037ULL: goto x86_l_2735;
	case 10039ULL: goto x86_l_2737;
	case 10041ULL: goto x86_l_2739;
	case 10047ULL: goto x86_l_273f;
	case 10050ULL: goto x86_l_2742;
	case 10055ULL: goto x86_l_2747;
	case 10061ULL: goto x86_l_274d;
	case 10066ULL: goto x86_l_2752;
	case 10074ULL: goto x86_l_275a;
	case 10078ULL: goto x86_l_275e;
	case 10085ULL: goto x86_l_2765;
	case 10090ULL: goto x86_l_276a;
	case 10095ULL: goto x86_l_276f;
	case 10097ULL: goto x86_l_2771;
	case 10102ULL: goto x86_l_2776;
	case 10110ULL: goto x86_l_277e;
	case 10113ULL: goto x86_l_2781;
	case 10121ULL: goto x86_l_2789;
	case 10130ULL: goto x86_l_2792;
	case 10137ULL: goto x86_l_2799;
	case 10142ULL: goto x86_l_279e;
	case 10147ULL: goto x86_l_27a3;
	case 10152ULL: goto x86_l_27a8;
	case 10154ULL: goto x86_l_27aa;
	case 10156ULL: goto x86_l_27ac;
	case 10162ULL: goto x86_l_27b2;
	case 10168ULL: goto x86_l_27b8;
	case 10171ULL: goto x86_l_27bb;
	case 10176ULL: goto x86_l_27c0;
	case 10182ULL: goto x86_l_27c6;
	case 10187ULL: goto x86_l_27cb;
	case 10195ULL: goto x86_l_27d3;
	case 10199ULL: goto x86_l_27d7;
	case 10206ULL: goto x86_l_27de;
	case 10211ULL: goto x86_l_27e3;
	case 10216ULL: goto x86_l_27e8;
	case 10218ULL: goto x86_l_27ea;
	case 10222ULL: goto x86_l_27ee;
	case 10224ULL: goto x86_l_27f0;
	case 10226ULL: goto x86_l_27f2;
	case 10232ULL: goto x86_l_27f8;
	case 10235ULL: goto x86_l_27fb;
	case 10240ULL: goto x86_l_2800;
	case 10246ULL: goto x86_l_2806;
	case 10251ULL: goto x86_l_280b;
	case 10259ULL: goto x86_l_2813;
	case 10263ULL: goto x86_l_2817;
	case 10270ULL: goto x86_l_281e;
	case 10275ULL: goto x86_l_2823;
	case 10280ULL: goto x86_l_2828;
	case 10282ULL: goto x86_l_282a;
	case 10287ULL: goto x86_l_282f;
	case 10295ULL: goto x86_l_2837;
	case 10298ULL: goto x86_l_283a;
	case 10306ULL: goto x86_l_2842;
	case 10315ULL: goto x86_l_284b;
	case 10322ULL: goto x86_l_2852;
	case 10327ULL: goto x86_l_2857;
	case 10332ULL: goto x86_l_285c;
	case 10337ULL: goto x86_l_2861;
	case 10339ULL: goto x86_l_2863;
	case 10341ULL: goto x86_l_2865;
	case 10347ULL: goto x86_l_286b;
	case 10353ULL: goto x86_l_2871;
	case 10356ULL: goto x86_l_2874;
	case 10361ULL: goto x86_l_2879;
	case 10367ULL: goto x86_l_287f;
	case 10372ULL: goto x86_l_2884;
	case 10380ULL: goto x86_l_288c;
	case 10384ULL: goto x86_l_2890;
	case 10391ULL: goto x86_l_2897;
	case 10396ULL: goto x86_l_289c;
	case 10401ULL: goto x86_l_28a1;
	case 10403ULL: goto x86_l_28a3;
	case 10407ULL: goto x86_l_28a7;
	case 10409ULL: goto x86_l_28a9;
	case 10411ULL: goto x86_l_28ab;
	case 10417ULL: goto x86_l_28b1;
	case 10420ULL: goto x86_l_28b4;
	case 10425ULL: goto x86_l_28b9;
	case 10431ULL: goto x86_l_28bf;
	case 10436ULL: goto x86_l_28c4;
	case 10444ULL: goto x86_l_28cc;
	case 10448ULL: goto x86_l_28d0;
	case 10455ULL: goto x86_l_28d7;
	case 10460ULL: goto x86_l_28dc;
	case 10465ULL: goto x86_l_28e1;
	case 10467ULL: goto x86_l_28e3;
	case 10472ULL: goto x86_l_28e8;
	case 10480ULL: goto x86_l_28f0;
	case 10483ULL: goto x86_l_28f3;
	case 10491ULL: goto x86_l_28fb;
	case 10500ULL: goto x86_l_2904;
	case 10507ULL: goto x86_l_290b;
	case 10512ULL: goto x86_l_2910;
	case 10517ULL: goto x86_l_2915;
	case 10522ULL: goto x86_l_291a;
	case 10524ULL: goto x86_l_291c;
	case 10526ULL: goto x86_l_291e;
	case 10532ULL: goto x86_l_2924;
	case 10538ULL: goto x86_l_292a;
	case 10541ULL: goto x86_l_292d;
	case 10546ULL: goto x86_l_2932;
	case 10552ULL: goto x86_l_2938;
	case 10557ULL: goto x86_l_293d;
	case 10565ULL: goto x86_l_2945;
	case 10569ULL: goto x86_l_2949;
	case 10576ULL: goto x86_l_2950;
	case 10581ULL: goto x86_l_2955;
	case 10586ULL: goto x86_l_295a;
	case 10588ULL: goto x86_l_295c;
	case 10592ULL: goto x86_l_2960;
	case 10594ULL: goto x86_l_2962;
	case 10596ULL: goto x86_l_2964;
	case 10602ULL: goto x86_l_296a;
	case 10605ULL: goto x86_l_296d;
	case 10610ULL: goto x86_l_2972;
	case 10616ULL: goto x86_l_2978;
	case 10621ULL: goto x86_l_297d;
	case 10629ULL: goto x86_l_2985;
	case 10633ULL: goto x86_l_2989;
	case 10640ULL: goto x86_l_2990;
	case 10645ULL: goto x86_l_2995;
	case 10650ULL: goto x86_l_299a;
	case 10652ULL: goto x86_l_299c;
	case 10657ULL: goto x86_l_29a1;
	case 10665ULL: goto x86_l_29a9;
	case 10668ULL: goto x86_l_29ac;
	case 10676ULL: goto x86_l_29b4;
	case 10685ULL: goto x86_l_29bd;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10702ULL: goto x86_l_29ce;
	case 10707ULL: goto x86_l_29d3;
	case 10709ULL: goto x86_l_29d5;
	case 10711ULL: goto x86_l_29d7;
	case 10717ULL: goto x86_l_29dd;
	case 10723ULL: goto x86_l_29e3;
	case 10726ULL: goto x86_l_29e6;
	case 10731ULL: goto x86_l_29eb;
	case 10737ULL: goto x86_l_29f1;
	case 10742ULL: goto x86_l_29f6;
	case 10750ULL: goto x86_l_29fe;
	case 10754ULL: goto x86_l_2a02;
	case 10761ULL: goto x86_l_2a09;
	case 10766ULL: goto x86_l_2a0e;
	case 10771ULL: goto x86_l_2a13;
	case 10773ULL: goto x86_l_2a15;
	case 10777ULL: goto x86_l_2a19;
	case 10779ULL: goto x86_l_2a1b;
	case 10781ULL: goto x86_l_2a1d;
	case 10787ULL: goto x86_l_2a23;
	case 10790ULL: goto x86_l_2a26;
	case 10795ULL: goto x86_l_2a2b;
	case 10801ULL: goto x86_l_2a31;
	case 10806ULL: goto x86_l_2a36;
	case 10814ULL: goto x86_l_2a3e;
	case 10818ULL: goto x86_l_2a42;
	case 10825ULL: goto x86_l_2a49;
	case 10830ULL: goto x86_l_2a4e;
	case 10835ULL: goto x86_l_2a53;
	case 10837ULL: goto x86_l_2a55;
	case 10842ULL: goto x86_l_2a5a;
	case 10850ULL: goto x86_l_2a62;
	case 10853ULL: goto x86_l_2a65;
	case 10861ULL: goto x86_l_2a6d;
	case 10870ULL: goto x86_l_2a76;
	case 10877ULL: goto x86_l_2a7d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22f7:
	/* 0x22f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22fc:
	/* 0x22fc: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2304:
	/* 0x2304: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2308:
	/* 0x2308: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_230f:
	/* 0x230f: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2314:
	/* 0x2314: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2319:
	/* 0x2319: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_231b:
	/* 0x231b: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2320:
	/* 0x2320: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2328:
	/* 0x2328: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_232b:
	/* 0x232b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2333:
	/* 0x2333: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_233c:
	/* 0x233c: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2343:
	/* 0x2343: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2348:
	/* 0x2348: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_234d:
	/* 0x234d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2352:
	/* 0x2352: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2354:
	/* 0x2354: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_2356:
	/* 0x2356: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_235c:
	/* 0x235c: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_2362:
	/* 0x2362: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2365:
	/* 0x2365: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_236a:
	/* 0x236a: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2370:
	/* 0x2370: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2375:
	/* 0x2375: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_237d:
	/* 0x237d: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2381:
	/* 0x2381: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2388:
	/* 0x2388: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_238d:
	/* 0x238d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2392:
	/* 0x2392: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2394:
	/* 0x2394: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2398:
	/* 0x2398: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_239a:
	/* 0x239a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_239c:
	/* 0x239c: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_23a2:
	/* 0x23a2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23a5:
	/* 0x23a5: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_23aa:
	/* 0x23aa: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_23b0:
	/* 0x23b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23b5:
	/* 0x23b5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_23bd:
	/* 0x23bd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_23c1:
	/* 0x23c1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_23c8:
	/* 0x23c8: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23cd:
	/* 0x23cd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23d2:
	/* 0x23d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d4:
	/* 0x23d4: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_23d9:
	/* 0x23d9: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_23e1:
	/* 0x23e1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_23e4:
	/* 0x23e4: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_23ec:
	/* 0x23ec: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_23f5:
	/* 0x23f5: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_23fc:
	/* 0x23fc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2401:
	/* 0x2401: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2406:
	/* 0x2406: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_240b:
	/* 0x240b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_240d:
	/* 0x240d: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_240f:
	/* 0x240f: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2415:
	/* 0x2415: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_241b:
	/* 0x241b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_241e:
	/* 0x241e: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2423:
	/* 0x2423: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2429:
	/* 0x2429: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_242e:
	/* 0x242e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2436:
	/* 0x2436: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_243a:
	/* 0x243a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2441:
	/* 0x2441: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2446:
	/* 0x2446: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_244b:
	/* 0x244b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244d:
	/* 0x244d: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2451:
	/* 0x2451: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_2453:
	/* 0x2453: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2455:
	/* 0x2455: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_245b:
	/* 0x245b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_245e:
	/* 0x245e: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2463:
	/* 0x2463: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2469:
	/* 0x2469: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_246e:
	/* 0x246e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2476:
	/* 0x2476: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_247a:
	/* 0x247a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2481:
	/* 0x2481: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2486:
	/* 0x2486: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_248b:
	/* 0x248b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_248d:
	/* 0x248d: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2492:
	/* 0x2492: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_249a:
	/* 0x249a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_249d:
	/* 0x249d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_24a5:
	/* 0x24a5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_24ae:
	/* 0x24ae: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_24b5:
	/* 0x24b5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24ba:
	/* 0x24ba: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24bf:
	/* 0x24bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24c4:
	/* 0x24c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24c6:
	/* 0x24c6: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_24c8:
	/* 0x24c8: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_24ce:
	/* 0x24ce: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_24d4:
	/* 0x24d4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24d7:
	/* 0x24d7: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_24dc:
	/* 0x24dc: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_24e2:
	/* 0x24e2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_24e7:
	/* 0x24e7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_24ef:
	/* 0x24ef: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_24f3:
	/* 0x24f3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_24fa:
	/* 0x24fa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24ff:
	/* 0x24ff: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2504:
	/* 0x2504: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2506:
	/* 0x2506: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_250a:
	/* 0x250a: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_250c:
	/* 0x250c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_250e:
	/* 0x250e: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2514:
	/* 0x2514: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2517:
	/* 0x2517: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_251c:
	/* 0x251c: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2522:
	/* 0x2522: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2527:
	/* 0x2527: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_252f:
	/* 0x252f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2533:
	/* 0x2533: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_253a:
	/* 0x253a: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_253f:
	/* 0x253f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2544:
	/* 0x2544: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2546:
	/* 0x2546: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_254b:
	/* 0x254b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2553:
	/* 0x2553: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2556:
	/* 0x2556: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_255e:
	/* 0x255e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2567:
	/* 0x2567: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_256e:
	/* 0x256e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2573:
	/* 0x2573: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2578:
	/* 0x2578: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_257d:
	/* 0x257d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_257f:
	/* 0x257f: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_2581:
	/* 0x2581: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2587:
	/* 0x2587: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_258d:
	/* 0x258d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2590:
	/* 0x2590: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2595:
	/* 0x2595: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_259b:
	/* 0x259b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_25a0:
	/* 0x25a0: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_25a8:
	/* 0x25a8: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_25ac:
	/* 0x25ac: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_25b3:
	/* 0x25b3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25b8:
	/* 0x25b8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_25bd:
	/* 0x25bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25bf:
	/* 0x25bf: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_25c3:
	/* 0x25c3: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_25c5:
	/* 0x25c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25c7:
	/* 0x25c7: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_25cd:
	/* 0x25cd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25d0:
	/* 0x25d0: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_25d5:
	/* 0x25d5: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_25db:
	/* 0x25db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25e0:
	/* 0x25e0: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_25e8:
	/* 0x25e8: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_25ec:
	/* 0x25ec: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_25f3:
	/* 0x25f3: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_25f8:
	/* 0x25f8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_25fd:
	/* 0x25fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ff:
	/* 0x25ff: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2604:
	/* 0x2604: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_260c:
	/* 0x260c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_260f:
	/* 0x260f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2617:
	/* 0x2617: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2620:
	/* 0x2620: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2627:
	/* 0x2627: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_262c:
	/* 0x262c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2631:
	/* 0x2631: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2636:
	/* 0x2636: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2638:
	/* 0x2638: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_263a:
	/* 0x263a: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2640:
	/* 0x2640: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_2646:
	/* 0x2646: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2649:
	/* 0x2649: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_264e:
	/* 0x264e: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2654:
	/* 0x2654: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2659:
	/* 0x2659: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2661:
	/* 0x2661: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2665:
	/* 0x2665: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_266c:
	/* 0x266c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2671:
	/* 0x2671: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2676:
	/* 0x2676: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2678:
	/* 0x2678: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_267c:
	/* 0x267c: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_267e:
	/* 0x267e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2680:
	/* 0x2680: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2686:
	/* 0x2686: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2689:
	/* 0x2689: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_268e:
	/* 0x268e: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2694:
	/* 0x2694: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2699:
	/* 0x2699: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_26a1:
	/* 0x26a1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_26a5:
	/* 0x26a5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_26ac:
	/* 0x26ac: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_26b1:
	/* 0x26b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26b6:
	/* 0x26b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b8:
	/* 0x26b8: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_26bd:
	/* 0x26bd: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_26c5:
	/* 0x26c5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_26c8:
	/* 0x26c8: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_26d0:
	/* 0x26d0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_26d9:
	/* 0x26d9: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_26e0:
	/* 0x26e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26e5:
	/* 0x26e5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26ea:
	/* 0x26ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26ef:
	/* 0x26ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f1:
	/* 0x26f1: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_26f3:
	/* 0x26f3: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_26f9:
	/* 0x26f9: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_26ff:
	/* 0x26ff: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2702:
	/* 0x2702: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2707:
	/* 0x2707: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_270d:
	/* 0x270d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2712:
	/* 0x2712: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_271a:
	/* 0x271a: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_271e:
	/* 0x271e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2725:
	/* 0x2725: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_272a:
	/* 0x272a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_272f:
	/* 0x272f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2731:
	/* 0x2731: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2735:
	/* 0x2735: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_2737:
	/* 0x2737: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2739:
	/* 0x2739: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_273f:
	/* 0x273f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2742:
	/* 0x2742: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2747:
	/* 0x2747: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_274d:
	/* 0x274d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2752:
	/* 0x2752: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_275a:
	/* 0x275a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_275e:
	/* 0x275e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2765:
	/* 0x2765: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_276a:
	/* 0x276a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_276f:
	/* 0x276f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2771:
	/* 0x2771: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2776:
	/* 0x2776: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_277e:
	/* 0x277e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2781:
	/* 0x2781: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2789:
	/* 0x2789: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2792:
	/* 0x2792: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2799:
	/* 0x2799: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_279e:
	/* 0x279e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27a3:
	/* 0x27a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27a8:
	/* 0x27a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27aa:
	/* 0x27aa: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_27ac:
	/* 0x27ac: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_27b2:
	/* 0x27b2: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_27b8:
	/* 0x27b8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27bb:
	/* 0x27bb: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_27c0:
	/* 0x27c0: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_27c6:
	/* 0x27c6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_27cb:
	/* 0x27cb: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_27d3:
	/* 0x27d3: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_27d7:
	/* 0x27d7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_27de:
	/* 0x27de: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27e3:
	/* 0x27e3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_27e8:
	/* 0x27e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ea:
	/* 0x27ea: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_27ee:
	/* 0x27ee: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_27f0:
	/* 0x27f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27f2:
	/* 0x27f2: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_27f8:
	/* 0x27f8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27fb:
	/* 0x27fb: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2800:
	/* 0x2800: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2806:
	/* 0x2806: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_280b:
	/* 0x280b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2813:
	/* 0x2813: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2817:
	/* 0x2817: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_281e:
	/* 0x281e: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2823:
	/* 0x2823: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2828:
	/* 0x2828: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_282a:
	/* 0x282a: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_282f:
	/* 0x282f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2837:
	/* 0x2837: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_283a:
	/* 0x283a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2842:
	/* 0x2842: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_284b:
	/* 0x284b: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2852:
	/* 0x2852: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2857:
	/* 0x2857: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_285c:
	/* 0x285c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2861:
	/* 0x2861: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2863:
	/* 0x2863: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_2865:
	/* 0x2865: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_286b:
	/* 0x286b: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_2871:
	/* 0x2871: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2874:
	/* 0x2874: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2879:
	/* 0x2879: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_287f:
	/* 0x287f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2884:
	/* 0x2884: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_288c:
	/* 0x288c: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2890:
	/* 0x2890: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2897:
	/* 0x2897: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_289c:
	/* 0x289c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_28a1:
	/* 0x28a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28a3:
	/* 0x28a3: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_28a7:
	/* 0x28a7: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_28a9:
	/* 0x28a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28ab:
	/* 0x28ab: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_28b1:
	/* 0x28b1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28b4:
	/* 0x28b4: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_28b9:
	/* 0x28b9: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_28bf:
	/* 0x28bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28c4:
	/* 0x28c4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_28cc:
	/* 0x28cc: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_28d0:
	/* 0x28d0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_28d7:
	/* 0x28d7: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_28dc:
	/* 0x28dc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28e1:
	/* 0x28e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28e3:
	/* 0x28e3: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_28e8:
	/* 0x28e8: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_28f0:
	/* 0x28f0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_28f3:
	/* 0x28f3: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_28fb:
	/* 0x28fb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2904:
	/* 0x2904: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_290b:
	/* 0x290b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2910:
	/* 0x2910: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2915:
	/* 0x2915: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_291a:
	/* 0x291a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_291c:
	/* 0x291c: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_291e:
	/* 0x291e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2924:
	/* 0x2924: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_292a:
	/* 0x292a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_292d:
	/* 0x292d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2932:
	/* 0x2932: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2938:
	/* 0x2938: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_293d:
	/* 0x293d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2945:
	/* 0x2945: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2949:
	/* 0x2949: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2950:
	/* 0x2950: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2955:
	/* 0x2955: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_295a:
	/* 0x295a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_295c:
	/* 0x295c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2960:
	/* 0x2960: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_2962:
	/* 0x2962: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2964:
	/* 0x2964: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_296a:
	/* 0x296a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_296d:
	/* 0x296d: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2972:
	/* 0x2972: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2978:
	/* 0x2978: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_297d:
	/* 0x297d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2985:
	/* 0x2985: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2989:
	/* 0x2989: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2990:
	/* 0x2990: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2995:
	/* 0x2995: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_299a:
	/* 0x299a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_299c:
	/* 0x299c: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_29a1:
	/* 0x29a1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_29a9:
	/* 0x29a9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_29ac:
	/* 0x29ac: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_29b4:
	/* 0x29b4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_29bd:
	/* 0x29bd: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_29c4:
	/* 0x29c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29c9:
	/* 0x29c9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29ce:
	/* 0x29ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29d3:
	/* 0x29d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d5:
	/* 0x29d5: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_29d7:
	/* 0x29d7: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_29dd:
	/* 0x29dd: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_29e3:
	/* 0x29e3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29e6:
	/* 0x29e6: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_29eb:
	/* 0x29eb: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_29f1:
	/* 0x29f1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_29f6:
	/* 0x29f6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_29fe:
	/* 0x29fe: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2a02:
	/* 0x2a02: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2a09:
	/* 0x2a09: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a0e:
	/* 0x2a0e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2a13:
	/* 0x2a13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a15:
	/* 0x2a15: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2a19:
	/* 0x2a19: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_2a1b:
	/* 0x2a1b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a1d:
	/* 0x2a1d: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2a23:
	/* 0x2a23: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a26:
	/* 0x2a26: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2a2b:
	/* 0x2a2b: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2a31:
	/* 0x2a31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a36:
	/* 0x2a36: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a3e:
	/* 0x2a3e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2a42:
	/* 0x2a42: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2a49:
	/* 0x2a49: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2a4e:
	/* 0x2a4e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a53:
	/* 0x2a53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a55:
	/* 0x2a55: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2a5a:
	/* 0x2a5a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2a62:
	/* 0x2a62: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2a65:
	/* 0x2a65: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2a6d:
	/* 0x2a6d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2a76:
	/* 0x2a76: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_2a7d:
	/* 0x2a7d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 10882ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10882ULL: goto x86_l_2a82;
	case 10887ULL: goto x86_l_2a87;
	case 10892ULL: goto x86_l_2a8c;
	case 10895ULL: goto x86_l_2a8f;
	case 10897ULL: goto x86_l_2a91;
	case 10899ULL: goto x86_l_2a93;
	case 10905ULL: goto x86_l_2a99;
	case 10911ULL: goto x86_l_2a9f;
	case 10914ULL: goto x86_l_2aa2;
	case 10919ULL: goto x86_l_2aa7;
	case 10925ULL: goto x86_l_2aad;
	case 10930ULL: goto x86_l_2ab2;
	case 10938ULL: goto x86_l_2aba;
	case 10942ULL: goto x86_l_2abe;
	case 10949ULL: goto x86_l_2ac5;
	case 10954ULL: goto x86_l_2aca;
	case 10959ULL: goto x86_l_2acf;
	case 10961ULL: goto x86_l_2ad1;
	case 10965ULL: goto x86_l_2ad5;
	case 10967ULL: goto x86_l_2ad7;
	case 10969ULL: goto x86_l_2ad9;
	case 10975ULL: goto x86_l_2adf;
	case 10978ULL: goto x86_l_2ae2;
	case 10983ULL: goto x86_l_2ae7;
	case 10989ULL: goto x86_l_2aed;
	case 10994ULL: goto x86_l_2af2;
	case 11002ULL: goto x86_l_2afa;
	case 11006ULL: goto x86_l_2afe;
	case 11013ULL: goto x86_l_2b05;
	case 11018ULL: goto x86_l_2b0a;
	case 11023ULL: goto x86_l_2b0f;
	case 11025ULL: goto x86_l_2b11;
	case 11030ULL: goto x86_l_2b16;
	case 11038ULL: goto x86_l_2b1e;
	case 11041ULL: goto x86_l_2b21;
	case 11049ULL: goto x86_l_2b29;
	case 11060ULL: goto x86_l_2b34;
	case 11063ULL: goto x86_l_2b37;
	case 11068ULL: goto x86_l_2b3c;
	case 11070ULL: goto x86_l_2b3e;
	case 11075ULL: goto x86_l_2b43;
	case 11080ULL: goto x86_l_2b48;
	case 11088ULL: goto x86_l_2b50;
	case 11092ULL: goto x86_l_2b54;
	case 11099ULL: goto x86_l_2b5b;
	case 11107ULL: goto x86_l_2b63;
	case 11112ULL: goto x86_l_2b68;
	case 11114ULL: goto x86_l_2b6a;
	case 11118ULL: goto x86_l_2b6e;
	case 11120ULL: goto x86_l_2b70;
	case 11122ULL: goto x86_l_2b72;
	case 11128ULL: goto x86_l_2b78;
	case 11131ULL: goto x86_l_2b7b;
	case 11136ULL: goto x86_l_2b80;
	case 11141ULL: goto x86_l_2b85;
	case 11147ULL: goto x86_l_2b8b;
	case 11152ULL: goto x86_l_2b90;
	case 11160ULL: goto x86_l_2b98;
	case 11164ULL: goto x86_l_2b9c;
	case 11171ULL: goto x86_l_2ba3;
	case 11176ULL: goto x86_l_2ba8;
	case 11181ULL: goto x86_l_2bad;
	case 11183ULL: goto x86_l_2baf;
	case 11188ULL: goto x86_l_2bb4;
	case 11196ULL: goto x86_l_2bbc;
	case 11199ULL: goto x86_l_2bbf;
	case 11207ULL: goto x86_l_2bc7;
	case 11209ULL: goto x86_l_2bc9;
	case 11214ULL: goto x86_l_2bce;
	case 11219ULL: goto x86_l_2bd3;
	case 11227ULL: goto x86_l_2bdb;
	case 11231ULL: goto x86_l_2bdf;
	case 11238ULL: goto x86_l_2be6;
	case 11243ULL: goto x86_l_2beb;
	case 11248ULL: goto x86_l_2bf0;
	case 11250ULL: goto x86_l_2bf2;
	case 11255ULL: goto x86_l_2bf7;
	case 11263ULL: goto x86_l_2bff;
	case 11266ULL: goto x86_l_2c02;
	case 11274ULL: goto x86_l_2c0a;
	case 11283ULL: goto x86_l_2c13;
	case 11287ULL: goto x86_l_2c17;
	case 11292ULL: goto x86_l_2c1c;
	case 11297ULL: goto x86_l_2c21;
	case 11302ULL: goto x86_l_2c26;
	case 11304ULL: goto x86_l_2c28;
	case 11306ULL: goto x86_l_2c2a;
	case 11312ULL: goto x86_l_2c30;
	case 11318ULL: goto x86_l_2c36;
	case 11321ULL: goto x86_l_2c39;
	case 11326ULL: goto x86_l_2c3e;
	case 11332ULL: goto x86_l_2c44;
	case 11337ULL: goto x86_l_2c49;
	case 11345ULL: goto x86_l_2c51;
	case 11349ULL: goto x86_l_2c55;
	case 11356ULL: goto x86_l_2c5c;
	case 11361ULL: goto x86_l_2c61;
	case 11366ULL: goto x86_l_2c66;
	case 11368ULL: goto x86_l_2c68;
	case 11372ULL: goto x86_l_2c6c;
	case 11374ULL: goto x86_l_2c6e;
	case 11376ULL: goto x86_l_2c70;
	case 11382ULL: goto x86_l_2c76;
	case 11385ULL: goto x86_l_2c79;
	case 11390ULL: goto x86_l_2c7e;
	case 11396ULL: goto x86_l_2c84;
	case 11401ULL: goto x86_l_2c89;
	case 11409ULL: goto x86_l_2c91;
	case 11413ULL: goto x86_l_2c95;
	case 11420ULL: goto x86_l_2c9c;
	case 11425ULL: goto x86_l_2ca1;
	case 11430ULL: goto x86_l_2ca6;
	case 11432ULL: goto x86_l_2ca8;
	case 11437ULL: goto x86_l_2cad;
	case 11445ULL: goto x86_l_2cb5;
	case 11448ULL: goto x86_l_2cb8;
	case 11456ULL: goto x86_l_2cc0;
	case 11465ULL: goto x86_l_2cc9;
	case 11469ULL: goto x86_l_2ccd;
	case 11474ULL: goto x86_l_2cd2;
	case 11479ULL: goto x86_l_2cd7;
	case 11484ULL: goto x86_l_2cdc;
	case 11486ULL: goto x86_l_2cde;
	case 11488ULL: goto x86_l_2ce0;
	case 11494ULL: goto x86_l_2ce6;
	case 11500ULL: goto x86_l_2cec;
	case 11503ULL: goto x86_l_2cef;
	case 11508ULL: goto x86_l_2cf4;
	case 11514ULL: goto x86_l_2cfa;
	case 11519ULL: goto x86_l_2cff;
	case 11527ULL: goto x86_l_2d07;
	case 11531ULL: goto x86_l_2d0b;
	case 11538ULL: goto x86_l_2d12;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11550ULL: goto x86_l_2d1e;
	case 11554ULL: goto x86_l_2d22;
	case 11556ULL: goto x86_l_2d24;
	case 11558ULL: goto x86_l_2d26;
	case 11564ULL: goto x86_l_2d2c;
	case 11567ULL: goto x86_l_2d2f;
	case 11572ULL: goto x86_l_2d34;
	case 11578ULL: goto x86_l_2d3a;
	case 11583ULL: goto x86_l_2d3f;
	case 11591ULL: goto x86_l_2d47;
	case 11595ULL: goto x86_l_2d4b;
	case 11602ULL: goto x86_l_2d52;
	case 11607ULL: goto x86_l_2d57;
	case 11612ULL: goto x86_l_2d5c;
	case 11614ULL: goto x86_l_2d5e;
	case 11619ULL: goto x86_l_2d63;
	case 11627ULL: goto x86_l_2d6b;
	case 11630ULL: goto x86_l_2d6e;
	case 11638ULL: goto x86_l_2d76;
	case 11647ULL: goto x86_l_2d7f;
	case 11651ULL: goto x86_l_2d83;
	case 11656ULL: goto x86_l_2d88;
	case 11661ULL: goto x86_l_2d8d;
	case 11666ULL: goto x86_l_2d92;
	case 11668ULL: goto x86_l_2d94;
	case 11670ULL: goto x86_l_2d96;
	case 11676ULL: goto x86_l_2d9c;
	case 11682ULL: goto x86_l_2da2;
	case 11685ULL: goto x86_l_2da5;
	case 11690ULL: goto x86_l_2daa;
	case 11696ULL: goto x86_l_2db0;
	case 11701ULL: goto x86_l_2db5;
	case 11709ULL: goto x86_l_2dbd;
	case 11713ULL: goto x86_l_2dc1;
	case 11720ULL: goto x86_l_2dc8;
	case 11725ULL: goto x86_l_2dcd;
	case 11730ULL: goto x86_l_2dd2;
	case 11732ULL: goto x86_l_2dd4;
	case 11736ULL: goto x86_l_2dd8;
	case 11738ULL: goto x86_l_2dda;
	case 11740ULL: goto x86_l_2ddc;
	case 11746ULL: goto x86_l_2de2;
	case 11749ULL: goto x86_l_2de5;
	case 11754ULL: goto x86_l_2dea;
	case 11760ULL: goto x86_l_2df0;
	case 11765ULL: goto x86_l_2df5;
	case 11773ULL: goto x86_l_2dfd;
	case 11777ULL: goto x86_l_2e01;
	case 11784ULL: goto x86_l_2e08;
	case 11789ULL: goto x86_l_2e0d;
	case 11794ULL: goto x86_l_2e12;
	case 11796ULL: goto x86_l_2e14;
	case 11801ULL: goto x86_l_2e19;
	case 11809ULL: goto x86_l_2e21;
	case 11812ULL: goto x86_l_2e24;
	case 11820ULL: goto x86_l_2e2c;
	case 11829ULL: goto x86_l_2e35;
	case 11833ULL: goto x86_l_2e39;
	case 11838ULL: goto x86_l_2e3e;
	case 11843ULL: goto x86_l_2e43;
	case 11848ULL: goto x86_l_2e48;
	case 11850ULL: goto x86_l_2e4a;
	case 11852ULL: goto x86_l_2e4c;
	case 11858ULL: goto x86_l_2e52;
	case 11864ULL: goto x86_l_2e58;
	case 11867ULL: goto x86_l_2e5b;
	case 11872ULL: goto x86_l_2e60;
	case 11878ULL: goto x86_l_2e66;
	case 11883ULL: goto x86_l_2e6b;
	case 11891ULL: goto x86_l_2e73;
	case 11895ULL: goto x86_l_2e77;
	case 11902ULL: goto x86_l_2e7e;
	case 11907ULL: goto x86_l_2e83;
	case 11912ULL: goto x86_l_2e88;
	case 11914ULL: goto x86_l_2e8a;
	case 11918ULL: goto x86_l_2e8e;
	case 11920ULL: goto x86_l_2e90;
	case 11922ULL: goto x86_l_2e92;
	case 11928ULL: goto x86_l_2e98;
	case 11931ULL: goto x86_l_2e9b;
	case 11936ULL: goto x86_l_2ea0;
	case 11942ULL: goto x86_l_2ea6;
	case 11947ULL: goto x86_l_2eab;
	case 11955ULL: goto x86_l_2eb3;
	case 11959ULL: goto x86_l_2eb7;
	case 11966ULL: goto x86_l_2ebe;
	case 11971ULL: goto x86_l_2ec3;
	case 11976ULL: goto x86_l_2ec8;
	case 11978ULL: goto x86_l_2eca;
	case 11983ULL: goto x86_l_2ecf;
	case 11991ULL: goto x86_l_2ed7;
	case 11994ULL: goto x86_l_2eda;
	case 12002ULL: goto x86_l_2ee2;
	case 12011ULL: goto x86_l_2eeb;
	case 12015ULL: goto x86_l_2eef;
	case 12020ULL: goto x86_l_2ef4;
	case 12025ULL: goto x86_l_2ef9;
	case 12030ULL: goto x86_l_2efe;
	case 12032ULL: goto x86_l_2f00;
	case 12034ULL: goto x86_l_2f02;
	case 12040ULL: goto x86_l_2f08;
	case 12046ULL: goto x86_l_2f0e;
	case 12049ULL: goto x86_l_2f11;
	case 12054ULL: goto x86_l_2f16;
	case 12060ULL: goto x86_l_2f1c;
	case 12065ULL: goto x86_l_2f21;
	case 12073ULL: goto x86_l_2f29;
	case 12077ULL: goto x86_l_2f2d;
	case 12084ULL: goto x86_l_2f34;
	case 12089ULL: goto x86_l_2f39;
	case 12094ULL: goto x86_l_2f3e;
	case 12096ULL: goto x86_l_2f40;
	case 12100ULL: goto x86_l_2f44;
	case 12102ULL: goto x86_l_2f46;
	case 12104ULL: goto x86_l_2f48;
	case 12110ULL: goto x86_l_2f4e;
	case 12113ULL: goto x86_l_2f51;
	case 12118ULL: goto x86_l_2f56;
	case 12124ULL: goto x86_l_2f5c;
	case 12129ULL: goto x86_l_2f61;
	case 12137ULL: goto x86_l_2f69;
	case 12141ULL: goto x86_l_2f6d;
	case 12148ULL: goto x86_l_2f74;
	case 12153ULL: goto x86_l_2f79;
	case 12158ULL: goto x86_l_2f7e;
	case 12160ULL: goto x86_l_2f80;
	case 12165ULL: goto x86_l_2f85;
	case 12173ULL: goto x86_l_2f8d;
	case 12176ULL: goto x86_l_2f90;
	case 12184ULL: goto x86_l_2f98;
	case 12193ULL: goto x86_l_2fa1;
	case 12197ULL: goto x86_l_2fa5;
	case 12202ULL: goto x86_l_2faa;
	case 12207ULL: goto x86_l_2faf;
	case 12212ULL: goto x86_l_2fb4;
	case 12214ULL: goto x86_l_2fb6;
	case 12216ULL: goto x86_l_2fb8;
	case 12222ULL: goto x86_l_2fbe;
	case 12228ULL: goto x86_l_2fc4;
	case 12231ULL: goto x86_l_2fc7;
	case 12236ULL: goto x86_l_2fcc;
	case 12242ULL: goto x86_l_2fd2;
	case 12247ULL: goto x86_l_2fd7;
	case 12255ULL: goto x86_l_2fdf;
	case 12259ULL: goto x86_l_2fe3;
	case 12266ULL: goto x86_l_2fea;
	case 12271ULL: goto x86_l_2fef;
	case 12276ULL: goto x86_l_2ff4;
	case 12278ULL: goto x86_l_2ff6;
	case 12282ULL: goto x86_l_2ffa;
	case 12284ULL: goto x86_l_2ffc;
	case 12286ULL: goto x86_l_2ffe;
	case 12292ULL: goto x86_l_3004;
	case 12295ULL: goto x86_l_3007;
	case 12300ULL: goto x86_l_300c;
	case 12306ULL: goto x86_l_3012;
	case 12311ULL: goto x86_l_3017;
	case 12319ULL: goto x86_l_301f;
	case 12323ULL: goto x86_l_3023;
	case 12330ULL: goto x86_l_302a;
	case 12335ULL: goto x86_l_302f;
	case 12340ULL: goto x86_l_3034;
	case 12342ULL: goto x86_l_3036;
	case 12347ULL: goto x86_l_303b;
	case 12355ULL: goto x86_l_3043;
	case 12358ULL: goto x86_l_3046;
	case 12366ULL: goto x86_l_304e;
	case 12375ULL: goto x86_l_3057;
	case 12379ULL: goto x86_l_305b;
	case 12384ULL: goto x86_l_3060;
	case 12389ULL: goto x86_l_3065;
	case 12394ULL: goto x86_l_306a;
	case 12396ULL: goto x86_l_306c;
	case 12398ULL: goto x86_l_306e;
	case 12404ULL: goto x86_l_3074;
	case 12410ULL: goto x86_l_307a;
	case 12413ULL: goto x86_l_307d;
	case 12418ULL: goto x86_l_3082;
	case 12424ULL: goto x86_l_3088;
	case 12429ULL: goto x86_l_308d;
	case 12437ULL: goto x86_l_3095;
	case 12441ULL: goto x86_l_3099;
	case 12448ULL: goto x86_l_30a0;
	case 12453ULL: goto x86_l_30a5;
	case 12458ULL: goto x86_l_30aa;
	case 12460ULL: goto x86_l_30ac;
	case 12464ULL: goto x86_l_30b0;
	case 12466ULL: goto x86_l_30b2;
	case 12468ULL: goto x86_l_30b4;
	case 12474ULL: goto x86_l_30ba;
	case 12477ULL: goto x86_l_30bd;
	case 12482ULL: goto x86_l_30c2;
	case 12488ULL: goto x86_l_30c8;
	case 12493ULL: goto x86_l_30cd;
	case 12501ULL: goto x86_l_30d5;
	case 12505ULL: goto x86_l_30d9;
	case 12512ULL: goto x86_l_30e0;
	case 12517ULL: goto x86_l_30e5;
	case 12522ULL: goto x86_l_30ea;
	case 12524ULL: goto x86_l_30ec;
	case 12529ULL: goto x86_l_30f1;
	case 12537ULL: goto x86_l_30f9;
	case 12540ULL: goto x86_l_30fc;
	case 12548ULL: goto x86_l_3104;
	case 12557ULL: goto x86_l_310d;
	case 12561ULL: goto x86_l_3111;
	case 12566ULL: goto x86_l_3116;
	case 12571ULL: goto x86_l_311b;
	case 12576ULL: goto x86_l_3120;
	case 12578ULL: goto x86_l_3122;
	case 12580ULL: goto x86_l_3124;
	case 12586ULL: goto x86_l_312a;
	case 12592ULL: goto x86_l_3130;
	case 12595ULL: goto x86_l_3133;
	case 12600ULL: goto x86_l_3138;
	case 12606ULL: goto x86_l_313e;
	case 12611ULL: goto x86_l_3143;
	case 12619ULL: goto x86_l_314b;
	case 12623ULL: goto x86_l_314f;
	case 12630ULL: goto x86_l_3156;
	case 12635ULL: goto x86_l_315b;
	case 12640ULL: goto x86_l_3160;
	case 12642ULL: goto x86_l_3162;
	case 12646ULL: goto x86_l_3166;
	case 12648ULL: goto x86_l_3168;
	case 12650ULL: goto x86_l_316a;
	case 12656ULL: goto x86_l_3170;
	case 12659ULL: goto x86_l_3173;
	case 12664ULL: goto x86_l_3178;
	case 12670ULL: goto x86_l_317e;
	case 12675ULL: goto x86_l_3183;
	case 12683ULL: goto x86_l_318b;
	case 12687ULL: goto x86_l_318f;
	case 12694ULL: goto x86_l_3196;
	case 12699ULL: goto x86_l_319b;
	case 12704ULL: goto x86_l_31a0;
	case 12706ULL: goto x86_l_31a2;
	case 12711ULL: goto x86_l_31a7;
	case 12719ULL: goto x86_l_31af;
	case 12722ULL: goto x86_l_31b2;
	case 12730ULL: goto x86_l_31ba;
	case 12739ULL: goto x86_l_31c3;
	case 12743ULL: goto x86_l_31c7;
	case 12748ULL: goto x86_l_31cc;
	case 12753ULL: goto x86_l_31d1;
	case 12758ULL: goto x86_l_31d6;
	case 12760ULL: goto x86_l_31d8;
	case 12762ULL: goto x86_l_31da;
	case 12768ULL: goto x86_l_31e0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a82:
	/* 0x2a82: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a87:
	/* 0x2a87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a8c:
	/* 0x2a8c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2a8f:
	/* 0x2a8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a91:
	/* 0x2a91: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_2a93:
	/* 0x2a93: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2a99:
	/* 0x2a99: je     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_2a9f:
	/* 0x2a9f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2aa2:
	/* 0x2aa2: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2aa7:
	/* 0x2aa7: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2aad:
	/* 0x2aad: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2ab2:
	/* 0x2ab2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2aba:
	/* 0x2aba: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2abe:
	/* 0x2abe: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2ac5:
	/* 0x2ac5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aca:
	/* 0x2aca: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2acf:
	/* 0x2acf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ad1:
	/* 0x2ad1: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2ad5:
	/* 0x2ad5: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_2ad7:
	/* 0x2ad7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ad9:
	/* 0x2ad9: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2adf:
	/* 0x2adf: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ae2:
	/* 0x2ae2: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2ae7:
	/* 0x2ae7: ja     b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2aed:
	/* 0x2aed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2af2:
	/* 0x2af2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2afa:
	/* 0x2afa: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2afe:
	/* 0x2afe: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b05:
	/* 0x2b05: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2b0a:
	/* 0x2b0a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b0f:
	/* 0x2b0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b11:
	/* 0x2b11: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2b16:
	/* 0x2b16: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2b1e:
	/* 0x2b1e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2b21:
	/* 0x2b21: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2b29:
	/* 0x2b29: mov    DWORD PTR [rsp+0xa4],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704377663022ULL);
x86_l_2b34:
	/* 0x2b34: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2b37:
	/* 0x2b37: cmp    eax,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27901ULL);
x86_l_2b3c:
	/* 0x2b3c: jb     2b43 <syscall__execve_enter+0x2b43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2b43;
	}
x86_l_2b3e:
	/* 0x2b3e: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_2b43:
	/* 0x2b43: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2b48:
	/* 0x2b48: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b50:
	/* 0x2b50: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2b54:
	/* 0x2b54: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2b5b:
	/* 0x2b5b: lea    rdx,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_2b63:
	/* 0x2b63: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2b68:
	/* 0x2b68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b6a:
	/* 0x2b6a: mov    DWORD PTR [rsp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2b6e:
	/* 0x2b6e: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_2b70:
	/* 0x2b70: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b72:
	/* 0x2b72: jle    b09 <syscall__execve_enter+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2b78:
	/* 0x2b78: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b7b:
	/* 0x2b7b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2b80:
	/* 0x2b80: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2b85:
	/* 0x2b85: ja     b0e <syscall__execve_enter+0xb0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2830ULL;
	}
x86_l_2b8b:
	/* 0x2b8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b90:
	/* 0x2b90: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b98:
	/* 0x2b98: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2b9c:
	/* 0x2b9c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2ba3:
	/* 0x2ba3: lea    rdx,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2ba8:
	/* 0x2ba8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2bad:
	/* 0x2bad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2baf:
	/* 0x2baf: movzx  eax,WORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 124ULL);
x86_l_2bb4:
	/* 0x2bb4: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2bbc:
	/* 0x2bbc: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2bbf:
	/* 0x2bbf: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2bc7:
	/* 0x2bc7: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_2bc9:
	/* 0x2bc9: jmp    b0e <syscall__execve_enter+0xb0e> */
	return 2830ULL;
x86_l_2bce:
	/* 0x2bce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bd3:
	/* 0x2bd3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2bdb:
	/* 0x2bdb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2bdf:
	/* 0x2bdf: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2be6:
	/* 0x2be6: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2beb:
	/* 0x2beb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2bf0:
	/* 0x2bf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf2:
	/* 0x2bf2: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2bf7:
	/* 0x2bf7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2bff:
	/* 0x2bff: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2c02:
	/* 0x2c02: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c0a:
	/* 0x2c0a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c13:
	/* 0x2c13: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c17:
	/* 0x2c17: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c1c:
	/* 0x2c1c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c21:
	/* 0x2c21: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c26:
	/* 0x2c26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c28:
	/* 0x2c28: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_2c2a:
	/* 0x2c2a: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c30:
	/* 0x2c30: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_2c36:
	/* 0x2c36: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c39:
	/* 0x2c39: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2c3e:
	/* 0x2c3e: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2c44:
	/* 0x2c44: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2c49:
	/* 0x2c49: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c51:
	/* 0x2c51: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2c55:
	/* 0x2c55: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c61:
	/* 0x2c61: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2c66:
	/* 0x2c66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c68:
	/* 0x2c68: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2c6c:
	/* 0x2c6c: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_2c6e:
	/* 0x2c6e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c70:
	/* 0x2c70: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_2c76:
	/* 0x2c76: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c79:
	/* 0x2c79: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2c7e:
	/* 0x2c7e: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2c84:
	/* 0x2c84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c89:
	/* 0x2c89: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c91:
	/* 0x2c91: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2c95:
	/* 0x2c95: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2c9c:
	/* 0x2c9c: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2ca1:
	/* 0x2ca1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ca6:
	/* 0x2ca6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ca8:
	/* 0x2ca8: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2cad:
	/* 0x2cad: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2cb5:
	/* 0x2cb5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2cb8:
	/* 0x2cb8: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2cc0:
	/* 0x2cc0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2cc9:
	/* 0x2cc9: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ccd:
	/* 0x2ccd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cd2:
	/* 0x2cd2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cd7:
	/* 0x2cd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cdc:
	/* 0x2cdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cde:
	/* 0x2cde: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_2ce0:
	/* 0x2ce0: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ce6:
	/* 0x2ce6: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_2cec:
	/* 0x2cec: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2cef:
	/* 0x2cef: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2cf4:
	/* 0x2cf4: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2cfa:
	/* 0x2cfa: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2cff:
	/* 0x2cff: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d07:
	/* 0x2d07: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2d0b:
	/* 0x2d0b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2d12:
	/* 0x2d12: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d17:
	/* 0x2d17: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d1c:
	/* 0x2d1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1e:
	/* 0x2d1e: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2d22:
	/* 0x2d22: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_2d24:
	/* 0x2d24: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d26:
	/* 0x2d26: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_2d2c:
	/* 0x2d2c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d2f:
	/* 0x2d2f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2d34:
	/* 0x2d34: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2d3a:
	/* 0x2d3a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d3f:
	/* 0x2d3f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d47:
	/* 0x2d47: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2d4b:
	/* 0x2d4b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2d52:
	/* 0x2d52: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2d57:
	/* 0x2d57: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d5c:
	/* 0x2d5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d5e:
	/* 0x2d5e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2d63:
	/* 0x2d63: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2d6b:
	/* 0x2d6b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2d6e:
	/* 0x2d6e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2d76:
	/* 0x2d76: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d7f:
	/* 0x2d7f: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d83:
	/* 0x2d83: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d88:
	/* 0x2d88: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d8d:
	/* 0x2d8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d92:
	/* 0x2d92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d94:
	/* 0x2d94: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_2d96:
	/* 0x2d96: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d9c:
	/* 0x2d9c: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_2da2:
	/* 0x2da2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2da5:
	/* 0x2da5: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2daa:
	/* 0x2daa: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2db0:
	/* 0x2db0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2db5:
	/* 0x2db5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2dbd:
	/* 0x2dbd: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2dc1:
	/* 0x2dc1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2dc8:
	/* 0x2dc8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dcd:
	/* 0x2dcd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2dd2:
	/* 0x2dd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd4:
	/* 0x2dd4: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2dd8:
	/* 0x2dd8: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_2dda:
	/* 0x2dda: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ddc:
	/* 0x2ddc: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_2de2:
	/* 0x2de2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2de5:
	/* 0x2de5: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2dea:
	/* 0x2dea: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2df0:
	/* 0x2df0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2df5:
	/* 0x2df5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2dfd:
	/* 0x2dfd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e01:
	/* 0x2e01: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2e08:
	/* 0x2e08: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e0d:
	/* 0x2e0d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e12:
	/* 0x2e12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e14:
	/* 0x2e14: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2e19:
	/* 0x2e19: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2e21:
	/* 0x2e21: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2e24:
	/* 0x2e24: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2e2c:
	/* 0x2e2c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2e35:
	/* 0x2e35: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e39:
	/* 0x2e39: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e3e:
	/* 0x2e3e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e43:
	/* 0x2e43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e48:
	/* 0x2e48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e4a:
	/* 0x2e4a: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_2e4c:
	/* 0x2e4c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2e52:
	/* 0x2e52: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_2e58:
	/* 0x2e58: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e5b:
	/* 0x2e5b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2e60:
	/* 0x2e60: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2e66:
	/* 0x2e66: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2e6b:
	/* 0x2e6b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e73:
	/* 0x2e73: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2e77:
	/* 0x2e77: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2e7e:
	/* 0x2e7e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e83:
	/* 0x2e83: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2e88:
	/* 0x2e88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8a:
	/* 0x2e8a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e8e:
	/* 0x2e8e: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_2e90:
	/* 0x2e90: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e92:
	/* 0x2e92: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_2e98:
	/* 0x2e98: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e9b:
	/* 0x2e9b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2ea0:
	/* 0x2ea0: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2ea6:
	/* 0x2ea6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2eab:
	/* 0x2eab: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2eb3:
	/* 0x2eb3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2eb7:
	/* 0x2eb7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2ebe:
	/* 0x2ebe: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2ec3:
	/* 0x2ec3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ec8:
	/* 0x2ec8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eca:
	/* 0x2eca: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2ecf:
	/* 0x2ecf: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2ed7:
	/* 0x2ed7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2eda:
	/* 0x2eda: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2ee2:
	/* 0x2ee2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2eeb:
	/* 0x2eeb: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2eef:
	/* 0x2eef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ef4:
	/* 0x2ef4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ef9:
	/* 0x2ef9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2efe:
	/* 0x2efe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f00:
	/* 0x2f00: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_2f02:
	/* 0x2f02: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f08:
	/* 0x2f08: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_2f0e:
	/* 0x2f0e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f11:
	/* 0x2f11: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2f16:
	/* 0x2f16: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2f1c:
	/* 0x2f1c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2f21:
	/* 0x2f21: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f29:
	/* 0x2f29: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2f2d:
	/* 0x2f2d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2f34:
	/* 0x2f34: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f39:
	/* 0x2f39: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f3e:
	/* 0x2f3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f40:
	/* 0x2f40: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2f44:
	/* 0x2f44: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_2f46:
	/* 0x2f46: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f48:
	/* 0x2f48: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_2f4e:
	/* 0x2f4e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f51:
	/* 0x2f51: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2f56:
	/* 0x2f56: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2f5c:
	/* 0x2f5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f61:
	/* 0x2f61: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f69:
	/* 0x2f69: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2f6d:
	/* 0x2f6d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2f74:
	/* 0x2f74: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2f79:
	/* 0x2f79: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f7e:
	/* 0x2f7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f80:
	/* 0x2f80: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2f85:
	/* 0x2f85: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2f8d:
	/* 0x2f8d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2f90:
	/* 0x2f90: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2f98:
	/* 0x2f98: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2fa1:
	/* 0x2fa1: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fa5:
	/* 0x2fa5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2faa:
	/* 0x2faa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2faf:
	/* 0x2faf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fb4:
	/* 0x2fb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb6:
	/* 0x2fb6: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_2fb8:
	/* 0x2fb8: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2fbe:
	/* 0x2fbe: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_2fc4:
	/* 0x2fc4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fc7:
	/* 0x2fc7: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2fcc:
	/* 0x2fcc: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2fd2:
	/* 0x2fd2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2fd7:
	/* 0x2fd7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2fdf:
	/* 0x2fdf: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2fe3:
	/* 0x2fe3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2fea:
	/* 0x2fea: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fef:
	/* 0x2fef: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2ff4:
	/* 0x2ff4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ff6:
	/* 0x2ff6: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2ffa:
	/* 0x2ffa: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_2ffc:
	/* 0x2ffc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ffe:
	/* 0x2ffe: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3004:
	/* 0x3004: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3007:
	/* 0x3007: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_300c:
	/* 0x300c: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3012:
	/* 0x3012: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3017:
	/* 0x3017: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_301f:
	/* 0x301f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3023:
	/* 0x3023: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_302a:
	/* 0x302a: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_302f:
	/* 0x302f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3034:
	/* 0x3034: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3036:
	/* 0x3036: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_303b:
	/* 0x303b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3043:
	/* 0x3043: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3046:
	/* 0x3046: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_304e:
	/* 0x304e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3057:
	/* 0x3057: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_305b:
	/* 0x305b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3060:
	/* 0x3060: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3065:
	/* 0x3065: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_306a:
	/* 0x306a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_306c:
	/* 0x306c: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_306e:
	/* 0x306e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3074:
	/* 0x3074: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_307a:
	/* 0x307a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_307d:
	/* 0x307d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3082:
	/* 0x3082: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3088:
	/* 0x3088: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_308d:
	/* 0x308d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3095:
	/* 0x3095: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3099:
	/* 0x3099: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_30a0:
	/* 0x30a0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30a5:
	/* 0x30a5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_30aa:
	/* 0x30aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ac:
	/* 0x30ac: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_30b0:
	/* 0x30b0: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_30b2:
	/* 0x30b2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30b4:
	/* 0x30b4: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_30ba:
	/* 0x30ba: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30bd:
	/* 0x30bd: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_30c2:
	/* 0x30c2: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_30c8:
	/* 0x30c8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30cd:
	/* 0x30cd: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_30d5:
	/* 0x30d5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_30d9:
	/* 0x30d9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_30e0:
	/* 0x30e0: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_30e5:
	/* 0x30e5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_30ea:
	/* 0x30ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ec:
	/* 0x30ec: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_30f1:
	/* 0x30f1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_30f9:
	/* 0x30f9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_30fc:
	/* 0x30fc: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3104:
	/* 0x3104: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_310d:
	/* 0x310d: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3111:
	/* 0x3111: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3116:
	/* 0x3116: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_311b:
	/* 0x311b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3120:
	/* 0x3120: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3122:
	/* 0x3122: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_3124:
	/* 0x3124: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_312a:
	/* 0x312a: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3130:
	/* 0x3130: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3133:
	/* 0x3133: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3138:
	/* 0x3138: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_313e:
	/* 0x313e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3143:
	/* 0x3143: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_314b:
	/* 0x314b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_314f:
	/* 0x314f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3156:
	/* 0x3156: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_315b:
	/* 0x315b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3160:
	/* 0x3160: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3162:
	/* 0x3162: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3166:
	/* 0x3166: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_3168:
	/* 0x3168: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_316a:
	/* 0x316a: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3170:
	/* 0x3170: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3173:
	/* 0x3173: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3178:
	/* 0x3178: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_317e:
	/* 0x317e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3183:
	/* 0x3183: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_318b:
	/* 0x318b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_318f:
	/* 0x318f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3196:
	/* 0x3196: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_319b:
	/* 0x319b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_31a0:
	/* 0x31a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31a2:
	/* 0x31a2: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_31a7:
	/* 0x31a7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_31af:
	/* 0x31af: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_31b2:
	/* 0x31b2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_31ba:
	/* 0x31ba: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_31c3:
	/* 0x31c3: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_31c7:
	/* 0x31c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31cc:
	/* 0x31cc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31d1:
	/* 0x31d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31d6:
	/* 0x31d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d8:
	/* 0x31d8: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_31da:
	/* 0x31da: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_31e0:
	/* 0x31e0: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
	return 12774ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12774ULL: goto x86_l_31e6;
	case 12777ULL: goto x86_l_31e9;
	case 12782ULL: goto x86_l_31ee;
	case 12788ULL: goto x86_l_31f4;
	case 12793ULL: goto x86_l_31f9;
	case 12801ULL: goto x86_l_3201;
	case 12805ULL: goto x86_l_3205;
	case 12812ULL: goto x86_l_320c;
	case 12817ULL: goto x86_l_3211;
	case 12822ULL: goto x86_l_3216;
	case 12824ULL: goto x86_l_3218;
	case 12828ULL: goto x86_l_321c;
	case 12830ULL: goto x86_l_321e;
	case 12832ULL: goto x86_l_3220;
	case 12838ULL: goto x86_l_3226;
	case 12841ULL: goto x86_l_3229;
	case 12846ULL: goto x86_l_322e;
	case 12852ULL: goto x86_l_3234;
	case 12857ULL: goto x86_l_3239;
	case 12865ULL: goto x86_l_3241;
	case 12869ULL: goto x86_l_3245;
	case 12876ULL: goto x86_l_324c;
	case 12881ULL: goto x86_l_3251;
	case 12886ULL: goto x86_l_3256;
	case 12888ULL: goto x86_l_3258;
	case 12893ULL: goto x86_l_325d;
	case 12901ULL: goto x86_l_3265;
	case 12904ULL: goto x86_l_3268;
	case 12912ULL: goto x86_l_3270;
	case 12921ULL: goto x86_l_3279;
	case 12925ULL: goto x86_l_327d;
	case 12930ULL: goto x86_l_3282;
	case 12935ULL: goto x86_l_3287;
	case 12940ULL: goto x86_l_328c;
	case 12942ULL: goto x86_l_328e;
	case 12944ULL: goto x86_l_3290;
	case 12950ULL: goto x86_l_3296;
	case 12956ULL: goto x86_l_329c;
	case 12959ULL: goto x86_l_329f;
	case 12964ULL: goto x86_l_32a4;
	case 12970ULL: goto x86_l_32aa;
	case 12975ULL: goto x86_l_32af;
	case 12983ULL: goto x86_l_32b7;
	case 12987ULL: goto x86_l_32bb;
	case 12994ULL: goto x86_l_32c2;
	case 12999ULL: goto x86_l_32c7;
	case 13004ULL: goto x86_l_32cc;
	case 13006ULL: goto x86_l_32ce;
	case 13010ULL: goto x86_l_32d2;
	case 13012ULL: goto x86_l_32d4;
	case 13014ULL: goto x86_l_32d6;
	case 13020ULL: goto x86_l_32dc;
	case 13023ULL: goto x86_l_32df;
	case 13028ULL: goto x86_l_32e4;
	case 13034ULL: goto x86_l_32ea;
	case 13039ULL: goto x86_l_32ef;
	case 13047ULL: goto x86_l_32f7;
	case 13051ULL: goto x86_l_32fb;
	case 13058ULL: goto x86_l_3302;
	case 13063ULL: goto x86_l_3307;
	case 13068ULL: goto x86_l_330c;
	case 13070ULL: goto x86_l_330e;
	case 13075ULL: goto x86_l_3313;
	case 13083ULL: goto x86_l_331b;
	case 13086ULL: goto x86_l_331e;
	case 13094ULL: goto x86_l_3326;
	case 13103ULL: goto x86_l_332f;
	case 13107ULL: goto x86_l_3333;
	case 13112ULL: goto x86_l_3338;
	case 13117ULL: goto x86_l_333d;
	case 13122ULL: goto x86_l_3342;
	case 13124ULL: goto x86_l_3344;
	case 13126ULL: goto x86_l_3346;
	case 13132ULL: goto x86_l_334c;
	case 13138ULL: goto x86_l_3352;
	case 13141ULL: goto x86_l_3355;
	case 13146ULL: goto x86_l_335a;
	case 13152ULL: goto x86_l_3360;
	case 13157ULL: goto x86_l_3365;
	case 13165ULL: goto x86_l_336d;
	case 13169ULL: goto x86_l_3371;
	case 13176ULL: goto x86_l_3378;
	case 13181ULL: goto x86_l_337d;
	case 13186ULL: goto x86_l_3382;
	case 13188ULL: goto x86_l_3384;
	case 13192ULL: goto x86_l_3388;
	case 13194ULL: goto x86_l_338a;
	case 13196ULL: goto x86_l_338c;
	case 13202ULL: goto x86_l_3392;
	case 13205ULL: goto x86_l_3395;
	case 13210ULL: goto x86_l_339a;
	case 13216ULL: goto x86_l_33a0;
	case 13221ULL: goto x86_l_33a5;
	case 13229ULL: goto x86_l_33ad;
	case 13233ULL: goto x86_l_33b1;
	case 13240ULL: goto x86_l_33b8;
	case 13245ULL: goto x86_l_33bd;
	case 13250ULL: goto x86_l_33c2;
	case 13252ULL: goto x86_l_33c4;
	case 13257ULL: goto x86_l_33c9;
	case 13265ULL: goto x86_l_33d1;
	case 13268ULL: goto x86_l_33d4;
	case 13276ULL: goto x86_l_33dc;
	case 13285ULL: goto x86_l_33e5;
	case 13289ULL: goto x86_l_33e9;
	case 13294ULL: goto x86_l_33ee;
	case 13299ULL: goto x86_l_33f3;
	case 13304ULL: goto x86_l_33f8;
	case 13306ULL: goto x86_l_33fa;
	case 13308ULL: goto x86_l_33fc;
	case 13314ULL: goto x86_l_3402;
	case 13320ULL: goto x86_l_3408;
	case 13323ULL: goto x86_l_340b;
	case 13328ULL: goto x86_l_3410;
	case 13334ULL: goto x86_l_3416;
	case 13339ULL: goto x86_l_341b;
	case 13347ULL: goto x86_l_3423;
	case 13351ULL: goto x86_l_3427;
	case 13358ULL: goto x86_l_342e;
	case 13363ULL: goto x86_l_3433;
	case 13368ULL: goto x86_l_3438;
	case 13370ULL: goto x86_l_343a;
	case 13374ULL: goto x86_l_343e;
	case 13376ULL: goto x86_l_3440;
	case 13378ULL: goto x86_l_3442;
	case 13384ULL: goto x86_l_3448;
	case 13387ULL: goto x86_l_344b;
	case 13392ULL: goto x86_l_3450;
	case 13398ULL: goto x86_l_3456;
	case 13403ULL: goto x86_l_345b;
	case 13411ULL: goto x86_l_3463;
	case 13415ULL: goto x86_l_3467;
	case 13422ULL: goto x86_l_346e;
	case 13427ULL: goto x86_l_3473;
	case 13432ULL: goto x86_l_3478;
	case 13434ULL: goto x86_l_347a;
	case 13439ULL: goto x86_l_347f;
	case 13447ULL: goto x86_l_3487;
	case 13450ULL: goto x86_l_348a;
	case 13458ULL: goto x86_l_3492;
	case 13467ULL: goto x86_l_349b;
	case 13471ULL: goto x86_l_349f;
	case 13476ULL: goto x86_l_34a4;
	case 13481ULL: goto x86_l_34a9;
	case 13486ULL: goto x86_l_34ae;
	case 13488ULL: goto x86_l_34b0;
	case 13490ULL: goto x86_l_34b2;
	case 13496ULL: goto x86_l_34b8;
	case 13502ULL: goto x86_l_34be;
	case 13505ULL: goto x86_l_34c1;
	case 13510ULL: goto x86_l_34c6;
	case 13516ULL: goto x86_l_34cc;
	case 13521ULL: goto x86_l_34d1;
	case 13529ULL: goto x86_l_34d9;
	case 13533ULL: goto x86_l_34dd;
	case 13540ULL: goto x86_l_34e4;
	case 13545ULL: goto x86_l_34e9;
	case 13550ULL: goto x86_l_34ee;
	case 13552ULL: goto x86_l_34f0;
	case 13556ULL: goto x86_l_34f4;
	case 13558ULL: goto x86_l_34f6;
	case 13560ULL: goto x86_l_34f8;
	case 13566ULL: goto x86_l_34fe;
	case 13569ULL: goto x86_l_3501;
	case 13574ULL: goto x86_l_3506;
	case 13580ULL: goto x86_l_350c;
	case 13585ULL: goto x86_l_3511;
	case 13593ULL: goto x86_l_3519;
	case 13597ULL: goto x86_l_351d;
	case 13604ULL: goto x86_l_3524;
	case 13609ULL: goto x86_l_3529;
	case 13614ULL: goto x86_l_352e;
	case 13616ULL: goto x86_l_3530;
	case 13621ULL: goto x86_l_3535;
	case 13629ULL: goto x86_l_353d;
	case 13632ULL: goto x86_l_3540;
	case 13640ULL: goto x86_l_3548;
	case 13649ULL: goto x86_l_3551;
	case 13653ULL: goto x86_l_3555;
	case 13658ULL: goto x86_l_355a;
	case 13663ULL: goto x86_l_355f;
	case 13668ULL: goto x86_l_3564;
	case 13670ULL: goto x86_l_3566;
	case 13672ULL: goto x86_l_3568;
	case 13678ULL: goto x86_l_356e;
	case 13684ULL: goto x86_l_3574;
	case 13687ULL: goto x86_l_3577;
	case 13692ULL: goto x86_l_357c;
	case 13698ULL: goto x86_l_3582;
	case 13703ULL: goto x86_l_3587;
	case 13711ULL: goto x86_l_358f;
	case 13715ULL: goto x86_l_3593;
	case 13722ULL: goto x86_l_359a;
	case 13727ULL: goto x86_l_359f;
	case 13732ULL: goto x86_l_35a4;
	case 13734ULL: goto x86_l_35a6;
	case 13738ULL: goto x86_l_35aa;
	case 13740ULL: goto x86_l_35ac;
	case 13742ULL: goto x86_l_35ae;
	case 13748ULL: goto x86_l_35b4;
	case 13751ULL: goto x86_l_35b7;
	case 13756ULL: goto x86_l_35bc;
	case 13762ULL: goto x86_l_35c2;
	case 13767ULL: goto x86_l_35c7;
	case 13775ULL: goto x86_l_35cf;
	case 13779ULL: goto x86_l_35d3;
	case 13786ULL: goto x86_l_35da;
	case 13791ULL: goto x86_l_35df;
	case 13796ULL: goto x86_l_35e4;
	case 13798ULL: goto x86_l_35e6;
	case 13803ULL: goto x86_l_35eb;
	case 13811ULL: goto x86_l_35f3;
	case 13814ULL: goto x86_l_35f6;
	case 13822ULL: goto x86_l_35fe;
	case 13831ULL: goto x86_l_3607;
	case 13835ULL: goto x86_l_360b;
	case 13840ULL: goto x86_l_3610;
	case 13845ULL: goto x86_l_3615;
	case 13850ULL: goto x86_l_361a;
	case 13852ULL: goto x86_l_361c;
	case 13854ULL: goto x86_l_361e;
	case 13860ULL: goto x86_l_3624;
	case 13866ULL: goto x86_l_362a;
	case 13869ULL: goto x86_l_362d;
	case 13874ULL: goto x86_l_3632;
	case 13880ULL: goto x86_l_3638;
	case 13885ULL: goto x86_l_363d;
	case 13893ULL: goto x86_l_3645;
	case 13897ULL: goto x86_l_3649;
	case 13904ULL: goto x86_l_3650;
	case 13909ULL: goto x86_l_3655;
	case 13914ULL: goto x86_l_365a;
	case 13916ULL: goto x86_l_365c;
	case 13920ULL: goto x86_l_3660;
	case 13922ULL: goto x86_l_3662;
	case 13924ULL: goto x86_l_3664;
	case 13930ULL: goto x86_l_366a;
	case 13933ULL: goto x86_l_366d;
	case 13938ULL: goto x86_l_3672;
	case 13944ULL: goto x86_l_3678;
	case 13949ULL: goto x86_l_367d;
	case 13957ULL: goto x86_l_3685;
	case 13961ULL: goto x86_l_3689;
	case 13968ULL: goto x86_l_3690;
	case 13973ULL: goto x86_l_3695;
	case 13978ULL: goto x86_l_369a;
	case 13980ULL: goto x86_l_369c;
	case 13985ULL: goto x86_l_36a1;
	case 13993ULL: goto x86_l_36a9;
	case 13996ULL: goto x86_l_36ac;
	case 14004ULL: goto x86_l_36b4;
	case 14013ULL: goto x86_l_36bd;
	case 14020ULL: goto x86_l_36c4;
	case 14025ULL: goto x86_l_36c9;
	case 14030ULL: goto x86_l_36ce;
	case 14035ULL: goto x86_l_36d3;
	case 14037ULL: goto x86_l_36d5;
	case 14039ULL: goto x86_l_36d7;
	case 14045ULL: goto x86_l_36dd;
	case 14051ULL: goto x86_l_36e3;
	case 14054ULL: goto x86_l_36e6;
	case 14059ULL: goto x86_l_36eb;
	case 14065ULL: goto x86_l_36f1;
	case 14070ULL: goto x86_l_36f6;
	case 14078ULL: goto x86_l_36fe;
	case 14082ULL: goto x86_l_3702;
	case 14089ULL: goto x86_l_3709;
	case 14094ULL: goto x86_l_370e;
	case 14099ULL: goto x86_l_3713;
	case 14101ULL: goto x86_l_3715;
	case 14105ULL: goto x86_l_3719;
	case 14107ULL: goto x86_l_371b;
	case 14109ULL: goto x86_l_371d;
	case 14115ULL: goto x86_l_3723;
	case 14118ULL: goto x86_l_3726;
	case 14123ULL: goto x86_l_372b;
	case 14129ULL: goto x86_l_3731;
	case 14134ULL: goto x86_l_3736;
	case 14142ULL: goto x86_l_373e;
	case 14146ULL: goto x86_l_3742;
	case 14153ULL: goto x86_l_3749;
	case 14158ULL: goto x86_l_374e;
	case 14163ULL: goto x86_l_3753;
	case 14165ULL: goto x86_l_3755;
	case 14170ULL: goto x86_l_375a;
	case 14178ULL: goto x86_l_3762;
	case 14181ULL: goto x86_l_3765;
	case 14189ULL: goto x86_l_376d;
	case 14198ULL: goto x86_l_3776;
	case 14205ULL: goto x86_l_377d;
	case 14210ULL: goto x86_l_3782;
	case 14215ULL: goto x86_l_3787;
	case 14220ULL: goto x86_l_378c;
	case 14222ULL: goto x86_l_378e;
	case 14224ULL: goto x86_l_3790;
	case 14230ULL: goto x86_l_3796;
	case 14236ULL: goto x86_l_379c;
	case 14239ULL: goto x86_l_379f;
	case 14244ULL: goto x86_l_37a4;
	case 14250ULL: goto x86_l_37aa;
	case 14255ULL: goto x86_l_37af;
	case 14263ULL: goto x86_l_37b7;
	case 14267ULL: goto x86_l_37bb;
	case 14274ULL: goto x86_l_37c2;
	case 14279ULL: goto x86_l_37c7;
	case 14284ULL: goto x86_l_37cc;
	case 14286ULL: goto x86_l_37ce;
	case 14290ULL: goto x86_l_37d2;
	case 14292ULL: goto x86_l_37d4;
	case 14294ULL: goto x86_l_37d6;
	case 14300ULL: goto x86_l_37dc;
	case 14303ULL: goto x86_l_37df;
	case 14308ULL: goto x86_l_37e4;
	case 14314ULL: goto x86_l_37ea;
	case 14319ULL: goto x86_l_37ef;
	case 14327ULL: goto x86_l_37f7;
	case 14331ULL: goto x86_l_37fb;
	case 14338ULL: goto x86_l_3802;
	case 14343ULL: goto x86_l_3807;
	case 14348ULL: goto x86_l_380c;
	case 14350ULL: goto x86_l_380e;
	case 14355ULL: goto x86_l_3813;
	case 14363ULL: goto x86_l_381b;
	case 14366ULL: goto x86_l_381e;
	case 14374ULL: goto x86_l_3826;
	case 14383ULL: goto x86_l_382f;
	case 14390ULL: goto x86_l_3836;
	case 14395ULL: goto x86_l_383b;
	case 14400ULL: goto x86_l_3840;
	case 14405ULL: goto x86_l_3845;
	case 14407ULL: goto x86_l_3847;
	case 14409ULL: goto x86_l_3849;
	case 14415ULL: goto x86_l_384f;
	case 14421ULL: goto x86_l_3855;
	case 14424ULL: goto x86_l_3858;
	case 14429ULL: goto x86_l_385d;
	case 14435ULL: goto x86_l_3863;
	case 14440ULL: goto x86_l_3868;
	case 14448ULL: goto x86_l_3870;
	case 14452ULL: goto x86_l_3874;
	case 14459ULL: goto x86_l_387b;
	case 14464ULL: goto x86_l_3880;
	case 14469ULL: goto x86_l_3885;
	case 14471ULL: goto x86_l_3887;
	case 14475ULL: goto x86_l_388b;
	case 14477ULL: goto x86_l_388d;
	case 14479ULL: goto x86_l_388f;
	case 14485ULL: goto x86_l_3895;
	case 14488ULL: goto x86_l_3898;
	case 14493ULL: goto x86_l_389d;
	case 14499ULL: goto x86_l_38a3;
	case 14504ULL: goto x86_l_38a8;
	case 14512ULL: goto x86_l_38b0;
	case 14516ULL: goto x86_l_38b4;
	case 14523ULL: goto x86_l_38bb;
	case 14528ULL: goto x86_l_38c0;
	case 14533ULL: goto x86_l_38c5;
	case 14535ULL: goto x86_l_38c7;
	case 14540ULL: goto x86_l_38cc;
	case 14548ULL: goto x86_l_38d4;
	case 14551ULL: goto x86_l_38d7;
	case 14559ULL: goto x86_l_38df;
	case 14568ULL: goto x86_l_38e8;
	case 14575ULL: goto x86_l_38ef;
	case 14580ULL: goto x86_l_38f4;
	case 14585ULL: goto x86_l_38f9;
	case 14590ULL: goto x86_l_38fe;
	case 14592ULL: goto x86_l_3900;
	case 14594ULL: goto x86_l_3902;
	case 14600ULL: goto x86_l_3908;
	case 14606ULL: goto x86_l_390e;
	case 14609ULL: goto x86_l_3911;
	case 14614ULL: goto x86_l_3916;
	case 14620ULL: goto x86_l_391c;
	case 14625ULL: goto x86_l_3921;
	case 14633ULL: goto x86_l_3929;
	case 14637ULL: goto x86_l_392d;
	case 14644ULL: goto x86_l_3934;
	case 14649ULL: goto x86_l_3939;
	case 14654ULL: goto x86_l_393e;
	case 14656ULL: goto x86_l_3940;
	case 14660ULL: goto x86_l_3944;
	case 14662ULL: goto x86_l_3946;
	case 14664ULL: goto x86_l_3948;
	default: return 0xffffffffffffffffULL;
	}
x86_l_31e6:
	/* 0x31e6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31e9:
	/* 0x31e9: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_31ee:
	/* 0x31ee: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_31f4:
	/* 0x31f4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_31f9:
	/* 0x31f9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3201:
	/* 0x3201: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3205:
	/* 0x3205: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_320c:
	/* 0x320c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3211:
	/* 0x3211: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3216:
	/* 0x3216: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3218:
	/* 0x3218: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_321c:
	/* 0x321c: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_321e:
	/* 0x321e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3220:
	/* 0x3220: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3226:
	/* 0x3226: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3229:
	/* 0x3229: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_322e:
	/* 0x322e: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3234:
	/* 0x3234: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3239:
	/* 0x3239: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3241:
	/* 0x3241: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3245:
	/* 0x3245: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_324c:
	/* 0x324c: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3251:
	/* 0x3251: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3256:
	/* 0x3256: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3258:
	/* 0x3258: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_325d:
	/* 0x325d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3265:
	/* 0x3265: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3268:
	/* 0x3268: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3270:
	/* 0x3270: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3279:
	/* 0x3279: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_327d:
	/* 0x327d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3282:
	/* 0x3282: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3287:
	/* 0x3287: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_328c:
	/* 0x328c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_328e:
	/* 0x328e: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_3290:
	/* 0x3290: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3296:
	/* 0x3296: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_329c:
	/* 0x329c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_329f:
	/* 0x329f: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_32a4:
	/* 0x32a4: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_32aa:
	/* 0x32aa: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_32af:
	/* 0x32af: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_32b7:
	/* 0x32b7: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_32bb:
	/* 0x32bb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_32c2:
	/* 0x32c2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32c7:
	/* 0x32c7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_32cc:
	/* 0x32cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ce:
	/* 0x32ce: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_32d2:
	/* 0x32d2: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_32d4:
	/* 0x32d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32d6:
	/* 0x32d6: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_32dc:
	/* 0x32dc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32df:
	/* 0x32df: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_32e4:
	/* 0x32e4: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_32ea:
	/* 0x32ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32ef:
	/* 0x32ef: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_32f7:
	/* 0x32f7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_32fb:
	/* 0x32fb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3302:
	/* 0x3302: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3307:
	/* 0x3307: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_330c:
	/* 0x330c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_330e:
	/* 0x330e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3313:
	/* 0x3313: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_331b:
	/* 0x331b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_331e:
	/* 0x331e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3326:
	/* 0x3326: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_332f:
	/* 0x332f: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3333:
	/* 0x3333: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3338:
	/* 0x3338: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_333d:
	/* 0x333d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3342:
	/* 0x3342: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3344:
	/* 0x3344: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_3346:
	/* 0x3346: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_334c:
	/* 0x334c: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3352:
	/* 0x3352: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3355:
	/* 0x3355: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_335a:
	/* 0x335a: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3360:
	/* 0x3360: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3365:
	/* 0x3365: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_336d:
	/* 0x336d: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3371:
	/* 0x3371: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3378:
	/* 0x3378: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_337d:
	/* 0x337d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3382:
	/* 0x3382: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3384:
	/* 0x3384: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3388:
	/* 0x3388: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_338a:
	/* 0x338a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_338c:
	/* 0x338c: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3392:
	/* 0x3392: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3395:
	/* 0x3395: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_339a:
	/* 0x339a: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_33a0:
	/* 0x33a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33a5:
	/* 0x33a5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_33ad:
	/* 0x33ad: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_33b1:
	/* 0x33b1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_33b8:
	/* 0x33b8: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_33bd:
	/* 0x33bd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_33c2:
	/* 0x33c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33c4:
	/* 0x33c4: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_33c9:
	/* 0x33c9: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_33d1:
	/* 0x33d1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_33d4:
	/* 0x33d4: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_33dc:
	/* 0x33dc: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_33e5:
	/* 0x33e5: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_33e9:
	/* 0x33e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33ee:
	/* 0x33ee: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33f3:
	/* 0x33f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33f8:
	/* 0x33f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33fa:
	/* 0x33fa: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_33fc:
	/* 0x33fc: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3402:
	/* 0x3402: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3408:
	/* 0x3408: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_340b:
	/* 0x340b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3410:
	/* 0x3410: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3416:
	/* 0x3416: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_341b:
	/* 0x341b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3423:
	/* 0x3423: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3427:
	/* 0x3427: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_342e:
	/* 0x342e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3433:
	/* 0x3433: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3438:
	/* 0x3438: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_343a:
	/* 0x343a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_343e:
	/* 0x343e: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_3440:
	/* 0x3440: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3442:
	/* 0x3442: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3448:
	/* 0x3448: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_344b:
	/* 0x344b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3450:
	/* 0x3450: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3456:
	/* 0x3456: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_345b:
	/* 0x345b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3463:
	/* 0x3463: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3467:
	/* 0x3467: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_346e:
	/* 0x346e: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3473:
	/* 0x3473: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3478:
	/* 0x3478: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_347a:
	/* 0x347a: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_347f:
	/* 0x347f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3487:
	/* 0x3487: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_348a:
	/* 0x348a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3492:
	/* 0x3492: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_349b:
	/* 0x349b: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_349f:
	/* 0x349f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34a4:
	/* 0x34a4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34a9:
	/* 0x34a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34ae:
	/* 0x34ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34b0:
	/* 0x34b0: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_34b2:
	/* 0x34b2: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_34b8:
	/* 0x34b8: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_34be:
	/* 0x34be: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34c1:
	/* 0x34c1: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_34c6:
	/* 0x34c6: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_34cc:
	/* 0x34cc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_34d1:
	/* 0x34d1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_34d9:
	/* 0x34d9: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_34dd:
	/* 0x34dd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_34e4:
	/* 0x34e4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34e9:
	/* 0x34e9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_34ee:
	/* 0x34ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f0:
	/* 0x34f0: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_34f4:
	/* 0x34f4: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_34f6:
	/* 0x34f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34f8:
	/* 0x34f8: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_34fe:
	/* 0x34fe: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3501:
	/* 0x3501: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3506:
	/* 0x3506: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_350c:
	/* 0x350c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3511:
	/* 0x3511: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3519:
	/* 0x3519: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_351d:
	/* 0x351d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3524:
	/* 0x3524: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3529:
	/* 0x3529: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_352e:
	/* 0x352e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3530:
	/* 0x3530: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3535:
	/* 0x3535: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_353d:
	/* 0x353d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3540:
	/* 0x3540: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3548:
	/* 0x3548: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3551:
	/* 0x3551: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3555:
	/* 0x3555: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_355a:
	/* 0x355a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_355f:
	/* 0x355f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3564:
	/* 0x3564: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3566:
	/* 0x3566: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_3568:
	/* 0x3568: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_356e:
	/* 0x356e: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3574:
	/* 0x3574: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3577:
	/* 0x3577: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_357c:
	/* 0x357c: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3582:
	/* 0x3582: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3587:
	/* 0x3587: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_358f:
	/* 0x358f: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3593:
	/* 0x3593: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_359a:
	/* 0x359a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_359f:
	/* 0x359f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35a4:
	/* 0x35a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35a6:
	/* 0x35a6: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_35aa:
	/* 0x35aa: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_35ac:
	/* 0x35ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35ae:
	/* 0x35ae: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_35b4:
	/* 0x35b4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35b7:
	/* 0x35b7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_35bc:
	/* 0x35bc: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_35c2:
	/* 0x35c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35c7:
	/* 0x35c7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_35cf:
	/* 0x35cf: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_35d3:
	/* 0x35d3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_35da:
	/* 0x35da: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_35df:
	/* 0x35df: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_35e4:
	/* 0x35e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35e6:
	/* 0x35e6: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_35eb:
	/* 0x35eb: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_35f3:
	/* 0x35f3: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_35f6:
	/* 0x35f6: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_35fe:
	/* 0x35fe: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3607:
	/* 0x3607: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_360b:
	/* 0x360b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3610:
	/* 0x3610: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3615:
	/* 0x3615: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_361a:
	/* 0x361a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_361c:
	/* 0x361c: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_361e:
	/* 0x361e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3624:
	/* 0x3624: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_362a:
	/* 0x362a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_362d:
	/* 0x362d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3632:
	/* 0x3632: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3638:
	/* 0x3638: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_363d:
	/* 0x363d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3645:
	/* 0x3645: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3649:
	/* 0x3649: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3650:
	/* 0x3650: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3655:
	/* 0x3655: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_365a:
	/* 0x365a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_365c:
	/* 0x365c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3660:
	/* 0x3660: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_3662:
	/* 0x3662: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3664:
	/* 0x3664: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_366a:
	/* 0x366a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_366d:
	/* 0x366d: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3672:
	/* 0x3672: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3678:
	/* 0x3678: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_367d:
	/* 0x367d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3685:
	/* 0x3685: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3689:
	/* 0x3689: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3690:
	/* 0x3690: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3695:
	/* 0x3695: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_369a:
	/* 0x369a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_369c:
	/* 0x369c: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_36a1:
	/* 0x36a1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_36a9:
	/* 0x36a9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_36ac:
	/* 0x36ac: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_36b4:
	/* 0x36b4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_36bd:
	/* 0x36bd: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_36c4:
	/* 0x36c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36c9:
	/* 0x36c9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36ce:
	/* 0x36ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36d3:
	/* 0x36d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36d5:
	/* 0x36d5: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_36d7:
	/* 0x36d7: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_36dd:
	/* 0x36dd: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_36e3:
	/* 0x36e3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_36e6:
	/* 0x36e6: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_36eb:
	/* 0x36eb: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_36f1:
	/* 0x36f1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_36f6:
	/* 0x36f6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_36fe:
	/* 0x36fe: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3702:
	/* 0x3702: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3709:
	/* 0x3709: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_370e:
	/* 0x370e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3713:
	/* 0x3713: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3715:
	/* 0x3715: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3719:
	/* 0x3719: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_371b:
	/* 0x371b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_371d:
	/* 0x371d: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3723:
	/* 0x3723: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3726:
	/* 0x3726: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_372b:
	/* 0x372b: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3731:
	/* 0x3731: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3736:
	/* 0x3736: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_373e:
	/* 0x373e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3742:
	/* 0x3742: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3749:
	/* 0x3749: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_374e:
	/* 0x374e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3753:
	/* 0x3753: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3755:
	/* 0x3755: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_375a:
	/* 0x375a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3762:
	/* 0x3762: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3765:
	/* 0x3765: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_376d:
	/* 0x376d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3776:
	/* 0x3776: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_377d:
	/* 0x377d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3782:
	/* 0x3782: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3787:
	/* 0x3787: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_378c:
	/* 0x378c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_378e:
	/* 0x378e: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_3790:
	/* 0x3790: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3796:
	/* 0x3796: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_379c:
	/* 0x379c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_379f:
	/* 0x379f: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_37a4:
	/* 0x37a4: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_37aa:
	/* 0x37aa: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_37af:
	/* 0x37af: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_37b7:
	/* 0x37b7: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_37bb:
	/* 0x37bb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_37c2:
	/* 0x37c2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37c7:
	/* 0x37c7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_37cc:
	/* 0x37cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37ce:
	/* 0x37ce: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_37d2:
	/* 0x37d2: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_37d4:
	/* 0x37d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37d6:
	/* 0x37d6: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_37dc:
	/* 0x37dc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37df:
	/* 0x37df: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_37e4:
	/* 0x37e4: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_37ea:
	/* 0x37ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37ef:
	/* 0x37ef: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_37f7:
	/* 0x37f7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_37fb:
	/* 0x37fb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3802:
	/* 0x3802: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3807:
	/* 0x3807: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_380c:
	/* 0x380c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_380e:
	/* 0x380e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3813:
	/* 0x3813: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_381b:
	/* 0x381b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_381e:
	/* 0x381e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3826:
	/* 0x3826: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_382f:
	/* 0x382f: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3836:
	/* 0x3836: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_383b:
	/* 0x383b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3840:
	/* 0x3840: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3845:
	/* 0x3845: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3847:
	/* 0x3847: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_3849:
	/* 0x3849: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_384f:
	/* 0x384f: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3855:
	/* 0x3855: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3858:
	/* 0x3858: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_385d:
	/* 0x385d: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3863:
	/* 0x3863: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3868:
	/* 0x3868: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3870:
	/* 0x3870: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3874:
	/* 0x3874: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_387b:
	/* 0x387b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3880:
	/* 0x3880: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3885:
	/* 0x3885: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3887:
	/* 0x3887: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_388b:
	/* 0x388b: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_388d:
	/* 0x388d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_388f:
	/* 0x388f: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3895:
	/* 0x3895: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3898:
	/* 0x3898: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_389d:
	/* 0x389d: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_38a3:
	/* 0x38a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38a8:
	/* 0x38a8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_38b0:
	/* 0x38b0: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_38b4:
	/* 0x38b4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_38bb:
	/* 0x38bb: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_38c0:
	/* 0x38c0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38c5:
	/* 0x38c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38c7:
	/* 0x38c7: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_38cc:
	/* 0x38cc: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_38d4:
	/* 0x38d4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_38d7:
	/* 0x38d7: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_38df:
	/* 0x38df: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_38e8:
	/* 0x38e8: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_38ef:
	/* 0x38ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38f4:
	/* 0x38f4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38f9:
	/* 0x38f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38fe:
	/* 0x38fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3900:
	/* 0x3900: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_3902:
	/* 0x3902: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3908:
	/* 0x3908: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_390e:
	/* 0x390e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3911:
	/* 0x3911: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3916:
	/* 0x3916: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_391c:
	/* 0x391c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3921:
	/* 0x3921: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3929:
	/* 0x3929: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_392d:
	/* 0x392d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3934:
	/* 0x3934: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3939:
	/* 0x3939: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_393e:
	/* 0x393e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3940:
	/* 0x3940: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3944:
	/* 0x3944: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_3946:
	/* 0x3946: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3948:
	/* 0x3948: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
	return 14670ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14670ULL: goto x86_l_394e;
	case 14673ULL: goto x86_l_3951;
	case 14678ULL: goto x86_l_3956;
	case 14684ULL: goto x86_l_395c;
	case 14689ULL: goto x86_l_3961;
	case 14697ULL: goto x86_l_3969;
	case 14701ULL: goto x86_l_396d;
	case 14708ULL: goto x86_l_3974;
	case 14713ULL: goto x86_l_3979;
	case 14718ULL: goto x86_l_397e;
	case 14720ULL: goto x86_l_3980;
	case 14725ULL: goto x86_l_3985;
	case 14733ULL: goto x86_l_398d;
	case 14736ULL: goto x86_l_3990;
	case 14744ULL: goto x86_l_3998;
	case 14753ULL: goto x86_l_39a1;
	case 14760ULL: goto x86_l_39a8;
	case 14765ULL: goto x86_l_39ad;
	case 14770ULL: goto x86_l_39b2;
	case 14775ULL: goto x86_l_39b7;
	case 14777ULL: goto x86_l_39b9;
	case 14779ULL: goto x86_l_39bb;
	case 14785ULL: goto x86_l_39c1;
	case 14791ULL: goto x86_l_39c7;
	case 14794ULL: goto x86_l_39ca;
	case 14799ULL: goto x86_l_39cf;
	case 14805ULL: goto x86_l_39d5;
	case 14810ULL: goto x86_l_39da;
	case 14818ULL: goto x86_l_39e2;
	case 14822ULL: goto x86_l_39e6;
	case 14829ULL: goto x86_l_39ed;
	case 14834ULL: goto x86_l_39f2;
	case 14839ULL: goto x86_l_39f7;
	case 14841ULL: goto x86_l_39f9;
	case 14845ULL: goto x86_l_39fd;
	case 14847ULL: goto x86_l_39ff;
	case 14849ULL: goto x86_l_3a01;
	case 14855ULL: goto x86_l_3a07;
	case 14858ULL: goto x86_l_3a0a;
	case 14863ULL: goto x86_l_3a0f;
	case 14869ULL: goto x86_l_3a15;
	case 14874ULL: goto x86_l_3a1a;
	case 14882ULL: goto x86_l_3a22;
	case 14886ULL: goto x86_l_3a26;
	case 14893ULL: goto x86_l_3a2d;
	case 14898ULL: goto x86_l_3a32;
	case 14903ULL: goto x86_l_3a37;
	case 14905ULL: goto x86_l_3a39;
	case 14910ULL: goto x86_l_3a3e;
	case 14918ULL: goto x86_l_3a46;
	case 14921ULL: goto x86_l_3a49;
	case 14929ULL: goto x86_l_3a51;
	case 14938ULL: goto x86_l_3a5a;
	case 14945ULL: goto x86_l_3a61;
	case 14950ULL: goto x86_l_3a66;
	case 14955ULL: goto x86_l_3a6b;
	case 14960ULL: goto x86_l_3a70;
	case 14962ULL: goto x86_l_3a72;
	case 14964ULL: goto x86_l_3a74;
	case 14970ULL: goto x86_l_3a7a;
	case 14976ULL: goto x86_l_3a80;
	case 14979ULL: goto x86_l_3a83;
	case 14984ULL: goto x86_l_3a88;
	case 14990ULL: goto x86_l_3a8e;
	case 14995ULL: goto x86_l_3a93;
	case 15003ULL: goto x86_l_3a9b;
	case 15007ULL: goto x86_l_3a9f;
	case 15014ULL: goto x86_l_3aa6;
	case 15019ULL: goto x86_l_3aab;
	case 15024ULL: goto x86_l_3ab0;
	case 15026ULL: goto x86_l_3ab2;
	case 15030ULL: goto x86_l_3ab6;
	case 15032ULL: goto x86_l_3ab8;
	case 15034ULL: goto x86_l_3aba;
	case 15040ULL: goto x86_l_3ac0;
	case 15043ULL: goto x86_l_3ac3;
	case 15048ULL: goto x86_l_3ac8;
	case 15054ULL: goto x86_l_3ace;
	case 15059ULL: goto x86_l_3ad3;
	case 15067ULL: goto x86_l_3adb;
	case 15071ULL: goto x86_l_3adf;
	case 15078ULL: goto x86_l_3ae6;
	case 15083ULL: goto x86_l_3aeb;
	case 15088ULL: goto x86_l_3af0;
	case 15090ULL: goto x86_l_3af2;
	case 15095ULL: goto x86_l_3af7;
	case 15103ULL: goto x86_l_3aff;
	case 15106ULL: goto x86_l_3b02;
	case 15114ULL: goto x86_l_3b0a;
	case 15123ULL: goto x86_l_3b13;
	case 15130ULL: goto x86_l_3b1a;
	case 15135ULL: goto x86_l_3b1f;
	case 15140ULL: goto x86_l_3b24;
	case 15145ULL: goto x86_l_3b29;
	case 15147ULL: goto x86_l_3b2b;
	case 15149ULL: goto x86_l_3b2d;
	case 15155ULL: goto x86_l_3b33;
	case 15161ULL: goto x86_l_3b39;
	case 15164ULL: goto x86_l_3b3c;
	case 15169ULL: goto x86_l_3b41;
	case 15175ULL: goto x86_l_3b47;
	case 15180ULL: goto x86_l_3b4c;
	case 15188ULL: goto x86_l_3b54;
	case 15192ULL: goto x86_l_3b58;
	case 15199ULL: goto x86_l_3b5f;
	case 15204ULL: goto x86_l_3b64;
	case 15209ULL: goto x86_l_3b69;
	case 15211ULL: goto x86_l_3b6b;
	case 15215ULL: goto x86_l_3b6f;
	case 15217ULL: goto x86_l_3b71;
	case 15219ULL: goto x86_l_3b73;
	case 15225ULL: goto x86_l_3b79;
	case 15228ULL: goto x86_l_3b7c;
	case 15233ULL: goto x86_l_3b81;
	case 15239ULL: goto x86_l_3b87;
	case 15244ULL: goto x86_l_3b8c;
	case 15252ULL: goto x86_l_3b94;
	case 15256ULL: goto x86_l_3b98;
	case 15263ULL: goto x86_l_3b9f;
	case 15268ULL: goto x86_l_3ba4;
	case 15273ULL: goto x86_l_3ba9;
	case 15275ULL: goto x86_l_3bab;
	case 15280ULL: goto x86_l_3bb0;
	case 15288ULL: goto x86_l_3bb8;
	case 15291ULL: goto x86_l_3bbb;
	case 15299ULL: goto x86_l_3bc3;
	case 15308ULL: goto x86_l_3bcc;
	case 15315ULL: goto x86_l_3bd3;
	case 15320ULL: goto x86_l_3bd8;
	case 15325ULL: goto x86_l_3bdd;
	case 15330ULL: goto x86_l_3be2;
	case 15332ULL: goto x86_l_3be4;
	case 15334ULL: goto x86_l_3be6;
	case 15340ULL: goto x86_l_3bec;
	case 15346ULL: goto x86_l_3bf2;
	case 15349ULL: goto x86_l_3bf5;
	case 15354ULL: goto x86_l_3bfa;
	case 15360ULL: goto x86_l_3c00;
	case 15365ULL: goto x86_l_3c05;
	case 15373ULL: goto x86_l_3c0d;
	case 15377ULL: goto x86_l_3c11;
	case 15384ULL: goto x86_l_3c18;
	case 15389ULL: goto x86_l_3c1d;
	case 15394ULL: goto x86_l_3c22;
	case 15396ULL: goto x86_l_3c24;
	case 15400ULL: goto x86_l_3c28;
	case 15402ULL: goto x86_l_3c2a;
	case 15404ULL: goto x86_l_3c2c;
	case 15410ULL: goto x86_l_3c32;
	case 15413ULL: goto x86_l_3c35;
	case 15418ULL: goto x86_l_3c3a;
	case 15424ULL: goto x86_l_3c40;
	case 15429ULL: goto x86_l_3c45;
	case 15437ULL: goto x86_l_3c4d;
	case 15441ULL: goto x86_l_3c51;
	case 15448ULL: goto x86_l_3c58;
	case 15453ULL: goto x86_l_3c5d;
	case 15458ULL: goto x86_l_3c62;
	case 15460ULL: goto x86_l_3c64;
	case 15465ULL: goto x86_l_3c69;
	case 15473ULL: goto x86_l_3c71;
	case 15476ULL: goto x86_l_3c74;
	case 15484ULL: goto x86_l_3c7c;
	case 15493ULL: goto x86_l_3c85;
	case 15500ULL: goto x86_l_3c8c;
	case 15505ULL: goto x86_l_3c91;
	case 15510ULL: goto x86_l_3c96;
	case 15515ULL: goto x86_l_3c9b;
	case 15517ULL: goto x86_l_3c9d;
	case 15519ULL: goto x86_l_3c9f;
	case 15525ULL: goto x86_l_3ca5;
	case 15531ULL: goto x86_l_3cab;
	case 15534ULL: goto x86_l_3cae;
	case 15539ULL: goto x86_l_3cb3;
	case 15545ULL: goto x86_l_3cb9;
	case 15550ULL: goto x86_l_3cbe;
	case 15558ULL: goto x86_l_3cc6;
	case 15562ULL: goto x86_l_3cca;
	case 15569ULL: goto x86_l_3cd1;
	case 15574ULL: goto x86_l_3cd6;
	case 15579ULL: goto x86_l_3cdb;
	case 15581ULL: goto x86_l_3cdd;
	case 15585ULL: goto x86_l_3ce1;
	case 15587ULL: goto x86_l_3ce3;
	case 15589ULL: goto x86_l_3ce5;
	case 15595ULL: goto x86_l_3ceb;
	case 15598ULL: goto x86_l_3cee;
	case 15603ULL: goto x86_l_3cf3;
	case 15609ULL: goto x86_l_3cf9;
	case 15614ULL: goto x86_l_3cfe;
	case 15622ULL: goto x86_l_3d06;
	case 15626ULL: goto x86_l_3d0a;
	case 15633ULL: goto x86_l_3d11;
	case 15638ULL: goto x86_l_3d16;
	case 15643ULL: goto x86_l_3d1b;
	case 15645ULL: goto x86_l_3d1d;
	case 15650ULL: goto x86_l_3d22;
	case 15658ULL: goto x86_l_3d2a;
	case 15661ULL: goto x86_l_3d2d;
	case 15669ULL: goto x86_l_3d35;
	case 15678ULL: goto x86_l_3d3e;
	case 15685ULL: goto x86_l_3d45;
	case 15690ULL: goto x86_l_3d4a;
	case 15695ULL: goto x86_l_3d4f;
	case 15700ULL: goto x86_l_3d54;
	case 15702ULL: goto x86_l_3d56;
	case 15704ULL: goto x86_l_3d58;
	case 15710ULL: goto x86_l_3d5e;
	case 15716ULL: goto x86_l_3d64;
	case 15719ULL: goto x86_l_3d67;
	case 15724ULL: goto x86_l_3d6c;
	case 15730ULL: goto x86_l_3d72;
	case 15735ULL: goto x86_l_3d77;
	case 15743ULL: goto x86_l_3d7f;
	case 15747ULL: goto x86_l_3d83;
	case 15754ULL: goto x86_l_3d8a;
	case 15759ULL: goto x86_l_3d8f;
	case 15764ULL: goto x86_l_3d94;
	case 15766ULL: goto x86_l_3d96;
	case 15770ULL: goto x86_l_3d9a;
	case 15772ULL: goto x86_l_3d9c;
	case 15774ULL: goto x86_l_3d9e;
	case 15780ULL: goto x86_l_3da4;
	case 15783ULL: goto x86_l_3da7;
	case 15788ULL: goto x86_l_3dac;
	case 15794ULL: goto x86_l_3db2;
	case 15799ULL: goto x86_l_3db7;
	case 15807ULL: goto x86_l_3dbf;
	case 15811ULL: goto x86_l_3dc3;
	case 15818ULL: goto x86_l_3dca;
	case 15823ULL: goto x86_l_3dcf;
	case 15828ULL: goto x86_l_3dd4;
	case 15830ULL: goto x86_l_3dd6;
	case 15835ULL: goto x86_l_3ddb;
	case 15843ULL: goto x86_l_3de3;
	case 15846ULL: goto x86_l_3de6;
	case 15854ULL: goto x86_l_3dee;
	case 15863ULL: goto x86_l_3df7;
	case 15870ULL: goto x86_l_3dfe;
	case 15875ULL: goto x86_l_3e03;
	case 15880ULL: goto x86_l_3e08;
	case 15885ULL: goto x86_l_3e0d;
	case 15887ULL: goto x86_l_3e0f;
	case 15889ULL: goto x86_l_3e11;
	case 15895ULL: goto x86_l_3e17;
	case 15901ULL: goto x86_l_3e1d;
	case 15904ULL: goto x86_l_3e20;
	case 15909ULL: goto x86_l_3e25;
	case 15915ULL: goto x86_l_3e2b;
	case 15920ULL: goto x86_l_3e30;
	case 15928ULL: goto x86_l_3e38;
	case 15932ULL: goto x86_l_3e3c;
	case 15939ULL: goto x86_l_3e43;
	case 15944ULL: goto x86_l_3e48;
	case 15949ULL: goto x86_l_3e4d;
	case 15951ULL: goto x86_l_3e4f;
	case 15955ULL: goto x86_l_3e53;
	case 15957ULL: goto x86_l_3e55;
	case 15959ULL: goto x86_l_3e57;
	case 15965ULL: goto x86_l_3e5d;
	case 15968ULL: goto x86_l_3e60;
	case 15973ULL: goto x86_l_3e65;
	case 15979ULL: goto x86_l_3e6b;
	case 15984ULL: goto x86_l_3e70;
	case 15992ULL: goto x86_l_3e78;
	case 15996ULL: goto x86_l_3e7c;
	case 16003ULL: goto x86_l_3e83;
	case 16008ULL: goto x86_l_3e88;
	case 16013ULL: goto x86_l_3e8d;
	case 16015ULL: goto x86_l_3e8f;
	case 16020ULL: goto x86_l_3e94;
	case 16028ULL: goto x86_l_3e9c;
	case 16031ULL: goto x86_l_3e9f;
	case 16039ULL: goto x86_l_3ea7;
	case 16048ULL: goto x86_l_3eb0;
	case 16055ULL: goto x86_l_3eb7;
	case 16060ULL: goto x86_l_3ebc;
	case 16065ULL: goto x86_l_3ec1;
	case 16070ULL: goto x86_l_3ec6;
	case 16072ULL: goto x86_l_3ec8;
	case 16074ULL: goto x86_l_3eca;
	case 16080ULL: goto x86_l_3ed0;
	case 16086ULL: goto x86_l_3ed6;
	case 16089ULL: goto x86_l_3ed9;
	case 16094ULL: goto x86_l_3ede;
	case 16100ULL: goto x86_l_3ee4;
	case 16105ULL: goto x86_l_3ee9;
	case 16113ULL: goto x86_l_3ef1;
	case 16117ULL: goto x86_l_3ef5;
	case 16124ULL: goto x86_l_3efc;
	case 16129ULL: goto x86_l_3f01;
	case 16134ULL: goto x86_l_3f06;
	case 16136ULL: goto x86_l_3f08;
	case 16140ULL: goto x86_l_3f0c;
	case 16142ULL: goto x86_l_3f0e;
	case 16144ULL: goto x86_l_3f10;
	case 16150ULL: goto x86_l_3f16;
	case 16153ULL: goto x86_l_3f19;
	case 16158ULL: goto x86_l_3f1e;
	case 16164ULL: goto x86_l_3f24;
	case 16169ULL: goto x86_l_3f29;
	case 16177ULL: goto x86_l_3f31;
	case 16181ULL: goto x86_l_3f35;
	case 16188ULL: goto x86_l_3f3c;
	case 16193ULL: goto x86_l_3f41;
	case 16198ULL: goto x86_l_3f46;
	case 16200ULL: goto x86_l_3f48;
	case 16205ULL: goto x86_l_3f4d;
	case 16213ULL: goto x86_l_3f55;
	case 16216ULL: goto x86_l_3f58;
	case 16224ULL: goto x86_l_3f60;
	case 16233ULL: goto x86_l_3f69;
	case 16240ULL: goto x86_l_3f70;
	case 16245ULL: goto x86_l_3f75;
	case 16250ULL: goto x86_l_3f7a;
	case 16255ULL: goto x86_l_3f7f;
	case 16257ULL: goto x86_l_3f81;
	case 16259ULL: goto x86_l_3f83;
	case 16265ULL: goto x86_l_3f89;
	case 16271ULL: goto x86_l_3f8f;
	case 16274ULL: goto x86_l_3f92;
	case 16279ULL: goto x86_l_3f97;
	case 16285ULL: goto x86_l_3f9d;
	case 16290ULL: goto x86_l_3fa2;
	case 16298ULL: goto x86_l_3faa;
	case 16302ULL: goto x86_l_3fae;
	case 16309ULL: goto x86_l_3fb5;
	case 16314ULL: goto x86_l_3fba;
	case 16319ULL: goto x86_l_3fbf;
	case 16321ULL: goto x86_l_3fc1;
	case 16325ULL: goto x86_l_3fc5;
	case 16327ULL: goto x86_l_3fc7;
	case 16329ULL: goto x86_l_3fc9;
	case 16335ULL: goto x86_l_3fcf;
	case 16338ULL: goto x86_l_3fd2;
	case 16343ULL: goto x86_l_3fd7;
	case 16349ULL: goto x86_l_3fdd;
	case 16354ULL: goto x86_l_3fe2;
	case 16362ULL: goto x86_l_3fea;
	case 16366ULL: goto x86_l_3fee;
	case 16373ULL: goto x86_l_3ff5;
	case 16378ULL: goto x86_l_3ffa;
	case 16383ULL: goto x86_l_3fff;
	case 16385ULL: goto x86_l_4001;
	case 16390ULL: goto x86_l_4006;
	case 16398ULL: goto x86_l_400e;
	case 16401ULL: goto x86_l_4011;
	case 16409ULL: goto x86_l_4019;
	case 16418ULL: goto x86_l_4022;
	case 16425ULL: goto x86_l_4029;
	case 16430ULL: goto x86_l_402e;
	case 16435ULL: goto x86_l_4033;
	case 16440ULL: goto x86_l_4038;
	case 16442ULL: goto x86_l_403a;
	case 16444ULL: goto x86_l_403c;
	case 16450ULL: goto x86_l_4042;
	case 16456ULL: goto x86_l_4048;
	case 16459ULL: goto x86_l_404b;
	case 16464ULL: goto x86_l_4050;
	case 16470ULL: goto x86_l_4056;
	case 16475ULL: goto x86_l_405b;
	case 16483ULL: goto x86_l_4063;
	case 16487ULL: goto x86_l_4067;
	case 16494ULL: goto x86_l_406e;
	case 16499ULL: goto x86_l_4073;
	case 16504ULL: goto x86_l_4078;
	case 16506ULL: goto x86_l_407a;
	case 16510ULL: goto x86_l_407e;
	case 16512ULL: goto x86_l_4080;
	case 16514ULL: goto x86_l_4082;
	case 16520ULL: goto x86_l_4088;
	case 16523ULL: goto x86_l_408b;
	case 16528ULL: goto x86_l_4090;
	case 16534ULL: goto x86_l_4096;
	case 16539ULL: goto x86_l_409b;
	case 16547ULL: goto x86_l_40a3;
	case 16551ULL: goto x86_l_40a7;
	case 16558ULL: goto x86_l_40ae;
	case 16563ULL: goto x86_l_40b3;
	case 16568ULL: goto x86_l_40b8;
	case 16570ULL: goto x86_l_40ba;
	case 16575ULL: goto x86_l_40bf;
	case 16583ULL: goto x86_l_40c7;
	case 16586ULL: goto x86_l_40ca;
	default: return 0xffffffffffffffffULL;
	}
x86_l_394e:
	/* 0x394e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3951:
	/* 0x3951: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3956:
	/* 0x3956: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_395c:
	/* 0x395c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3961:
	/* 0x3961: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3969:
	/* 0x3969: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_396d:
	/* 0x396d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3974:
	/* 0x3974: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3979:
	/* 0x3979: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_397e:
	/* 0x397e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3980:
	/* 0x3980: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3985:
	/* 0x3985: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_398d:
	/* 0x398d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3990:
	/* 0x3990: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3998:
	/* 0x3998: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_39a1:
	/* 0x39a1: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_39a8:
	/* 0x39a8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39ad:
	/* 0x39ad: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39b2:
	/* 0x39b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39b7:
	/* 0x39b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39b9:
	/* 0x39b9: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_39bb:
	/* 0x39bb: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_39c1:
	/* 0x39c1: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_39c7:
	/* 0x39c7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_39ca:
	/* 0x39ca: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_39cf:
	/* 0x39cf: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_39d5:
	/* 0x39d5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_39da:
	/* 0x39da: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_39e2:
	/* 0x39e2: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_39e6:
	/* 0x39e6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_39ed:
	/* 0x39ed: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39f2:
	/* 0x39f2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_39f7:
	/* 0x39f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39f9:
	/* 0x39f9: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_39fd:
	/* 0x39fd: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_39ff:
	/* 0x39ff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a01:
	/* 0x3a01: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3a07:
	/* 0x3a07: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a0a:
	/* 0x3a0a: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3a0f:
	/* 0x3a0f: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3a15:
	/* 0x3a15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a1a:
	/* 0x3a1a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a22:
	/* 0x3a22: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3a26:
	/* 0x3a26: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3a2d:
	/* 0x3a2d: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3a32:
	/* 0x3a32: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3a37:
	/* 0x3a37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a39:
	/* 0x3a39: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3a3e:
	/* 0x3a3e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3a46:
	/* 0x3a46: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3a49:
	/* 0x3a49: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3a51:
	/* 0x3a51: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3a5a:
	/* 0x3a5a: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3a61:
	/* 0x3a61: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a66:
	/* 0x3a66: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a6b:
	/* 0x3a6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a70:
	/* 0x3a70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a72:
	/* 0x3a72: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_3a74:
	/* 0x3a74: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3a7a:
	/* 0x3a7a: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3a80:
	/* 0x3a80: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a83:
	/* 0x3a83: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3a88:
	/* 0x3a88: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3a8e:
	/* 0x3a8e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3a93:
	/* 0x3a93: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a9b:
	/* 0x3a9b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3a9f:
	/* 0x3a9f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3aa6:
	/* 0x3aa6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aab:
	/* 0x3aab: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3ab0:
	/* 0x3ab0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ab2:
	/* 0x3ab2: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3ab6:
	/* 0x3ab6: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_3ab8:
	/* 0x3ab8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3aba:
	/* 0x3aba: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3ac0:
	/* 0x3ac0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ac3:
	/* 0x3ac3: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3ac8:
	/* 0x3ac8: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3ace:
	/* 0x3ace: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ad3:
	/* 0x3ad3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3adb:
	/* 0x3adb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3adf:
	/* 0x3adf: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3ae6:
	/* 0x3ae6: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3aeb:
	/* 0x3aeb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3af0:
	/* 0x3af0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3af2:
	/* 0x3af2: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3af7:
	/* 0x3af7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3aff:
	/* 0x3aff: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3b02:
	/* 0x3b02: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3b0a:
	/* 0x3b0a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3b13:
	/* 0x3b13: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3b1a:
	/* 0x3b1a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b1f:
	/* 0x3b1f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b24:
	/* 0x3b24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b29:
	/* 0x3b29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b2b:
	/* 0x3b2b: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_3b2d:
	/* 0x3b2d: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3b33:
	/* 0x3b33: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3b39:
	/* 0x3b39: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b3c:
	/* 0x3b3c: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3b41:
	/* 0x3b41: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3b47:
	/* 0x3b47: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3b4c:
	/* 0x3b4c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b54:
	/* 0x3b54: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3b58:
	/* 0x3b58: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b5f:
	/* 0x3b5f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b64:
	/* 0x3b64: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3b69:
	/* 0x3b69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b6b:
	/* 0x3b6b: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3b6f:
	/* 0x3b6f: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_3b71:
	/* 0x3b71: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b73:
	/* 0x3b73: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3b79:
	/* 0x3b79: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b7c:
	/* 0x3b7c: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3b81:
	/* 0x3b81: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3b87:
	/* 0x3b87: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b8c:
	/* 0x3b8c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b94:
	/* 0x3b94: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3b98:
	/* 0x3b98: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3b9f:
	/* 0x3b9f: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3ba4:
	/* 0x3ba4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ba9:
	/* 0x3ba9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bab:
	/* 0x3bab: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3bb0:
	/* 0x3bb0: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3bb8:
	/* 0x3bb8: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3bbb:
	/* 0x3bbb: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3bc3:
	/* 0x3bc3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3bcc:
	/* 0x3bcc: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3bd3:
	/* 0x3bd3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3bd8:
	/* 0x3bd8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bdd:
	/* 0x3bdd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3be2:
	/* 0x3be2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be4:
	/* 0x3be4: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_3be6:
	/* 0x3be6: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3bec:
	/* 0x3bec: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3bf2:
	/* 0x3bf2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3bf5:
	/* 0x3bf5: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3bfa:
	/* 0x3bfa: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3c00:
	/* 0x3c00: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3c05:
	/* 0x3c05: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c0d:
	/* 0x3c0d: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3c11:
	/* 0x3c11: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c18:
	/* 0x3c18: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c1d:
	/* 0x3c1d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3c22:
	/* 0x3c22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c24:
	/* 0x3c24: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3c28:
	/* 0x3c28: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_3c2a:
	/* 0x3c2a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c2c:
	/* 0x3c2c: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3c32:
	/* 0x3c32: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c35:
	/* 0x3c35: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3c3a:
	/* 0x3c3a: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3c40:
	/* 0x3c40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c45:
	/* 0x3c45: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c4d:
	/* 0x3c4d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3c51:
	/* 0x3c51: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3c58:
	/* 0x3c58: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3c5d:
	/* 0x3c5d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c62:
	/* 0x3c62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c64:
	/* 0x3c64: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3c69:
	/* 0x3c69: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3c71:
	/* 0x3c71: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3c74:
	/* 0x3c74: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3c7c:
	/* 0x3c7c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3c85:
	/* 0x3c85: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3c8c:
	/* 0x3c8c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c91:
	/* 0x3c91: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c96:
	/* 0x3c96: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c9b:
	/* 0x3c9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c9d:
	/* 0x3c9d: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_3c9f:
	/* 0x3c9f: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ca5:
	/* 0x3ca5: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3cab:
	/* 0x3cab: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3cae:
	/* 0x3cae: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3cb3:
	/* 0x3cb3: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3cb9:
	/* 0x3cb9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3cbe:
	/* 0x3cbe: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3cc6:
	/* 0x3cc6: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3cca:
	/* 0x3cca: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3cd1:
	/* 0x3cd1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cd6:
	/* 0x3cd6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3cdb:
	/* 0x3cdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cdd:
	/* 0x3cdd: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3ce1:
	/* 0x3ce1: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_3ce3:
	/* 0x3ce3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ce5:
	/* 0x3ce5: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3ceb:
	/* 0x3ceb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3cee:
	/* 0x3cee: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3cf3:
	/* 0x3cf3: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3cf9:
	/* 0x3cf9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3cfe:
	/* 0x3cfe: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d06:
	/* 0x3d06: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3d0a:
	/* 0x3d0a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3d11:
	/* 0x3d11: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3d16:
	/* 0x3d16: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d1b:
	/* 0x3d1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d1d:
	/* 0x3d1d: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3d22:
	/* 0x3d22: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3d2a:
	/* 0x3d2a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3d2d:
	/* 0x3d2d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3d35:
	/* 0x3d35: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3d3e:
	/* 0x3d3e: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_3d45:
	/* 0x3d45: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d4a:
	/* 0x3d4a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d4f:
	/* 0x3d4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d54:
	/* 0x3d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d56:
	/* 0x3d56: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_3d58:
	/* 0x3d58: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3d5e:
	/* 0x3d5e: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3d64:
	/* 0x3d64: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d67:
	/* 0x3d67: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3d6c:
	/* 0x3d6c: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3d72:
	/* 0x3d72: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3d77:
	/* 0x3d77: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d7f:
	/* 0x3d7f: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3d83:
	/* 0x3d83: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3d8a:
	/* 0x3d8a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d8f:
	/* 0x3d8f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3d94:
	/* 0x3d94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d96:
	/* 0x3d96: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3d9a:
	/* 0x3d9a: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_3d9c:
	/* 0x3d9c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d9e:
	/* 0x3d9e: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3da4:
	/* 0x3da4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3da7:
	/* 0x3da7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3dac:
	/* 0x3dac: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3db2:
	/* 0x3db2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3db7:
	/* 0x3db7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3dbf:
	/* 0x3dbf: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3dc3:
	/* 0x3dc3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3dca:
	/* 0x3dca: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3dcf:
	/* 0x3dcf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3dd4:
	/* 0x3dd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dd6:
	/* 0x3dd6: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3ddb:
	/* 0x3ddb: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3de3:
	/* 0x3de3: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3de6:
	/* 0x3de6: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3dee:
	/* 0x3dee: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3df7:
	/* 0x3df7: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3dfe:
	/* 0x3dfe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e03:
	/* 0x3e03: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e08:
	/* 0x3e08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e0d:
	/* 0x3e0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e0f:
	/* 0x3e0f: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_3e11:
	/* 0x3e11: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3e17:
	/* 0x3e17: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3e1d:
	/* 0x3e1d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e20:
	/* 0x3e20: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3e25:
	/* 0x3e25: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3e2b:
	/* 0x3e2b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3e30:
	/* 0x3e30: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e38:
	/* 0x3e38: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3e3c:
	/* 0x3e3c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3e43:
	/* 0x3e43: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e48:
	/* 0x3e48: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3e4d:
	/* 0x3e4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e4f:
	/* 0x3e4f: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3e53:
	/* 0x3e53: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_3e55:
	/* 0x3e55: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e57:
	/* 0x3e57: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3e5d:
	/* 0x3e5d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e60:
	/* 0x3e60: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3e65:
	/* 0x3e65: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3e6b:
	/* 0x3e6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e70:
	/* 0x3e70: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e78:
	/* 0x3e78: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3e7c:
	/* 0x3e7c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3e83:
	/* 0x3e83: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3e88:
	/* 0x3e88: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e8d:
	/* 0x3e8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e8f:
	/* 0x3e8f: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3e94:
	/* 0x3e94: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3e9c:
	/* 0x3e9c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3e9f:
	/* 0x3e9f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3ea7:
	/* 0x3ea7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3eb0:
	/* 0x3eb0: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_3eb7:
	/* 0x3eb7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ebc:
	/* 0x3ebc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ec1:
	/* 0x3ec1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ec6:
	/* 0x3ec6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ec8:
	/* 0x3ec8: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_3eca:
	/* 0x3eca: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ed0:
	/* 0x3ed0: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3ed6:
	/* 0x3ed6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ed9:
	/* 0x3ed9: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3ede:
	/* 0x3ede: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3ee4:
	/* 0x3ee4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3ee9:
	/* 0x3ee9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ef1:
	/* 0x3ef1: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3ef5:
	/* 0x3ef5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3efc:
	/* 0x3efc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f01:
	/* 0x3f01: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3f06:
	/* 0x3f06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f08:
	/* 0x3f08: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3f0c:
	/* 0x3f0c: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_3f0e:
	/* 0x3f0e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f10:
	/* 0x3f10: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3f16:
	/* 0x3f16: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f19:
	/* 0x3f19: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3f1e:
	/* 0x3f1e: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3f24:
	/* 0x3f24: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f29:
	/* 0x3f29: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3f31:
	/* 0x3f31: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3f35:
	/* 0x3f35: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3f3c:
	/* 0x3f3c: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3f41:
	/* 0x3f41: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3f46:
	/* 0x3f46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f48:
	/* 0x3f48: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3f4d:
	/* 0x3f4d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3f55:
	/* 0x3f55: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3f58:
	/* 0x3f58: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3f60:
	/* 0x3f60: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3f69:
	/* 0x3f69: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_3f70:
	/* 0x3f70: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f75:
	/* 0x3f75: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f7a:
	/* 0x3f7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f7f:
	/* 0x3f7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f81:
	/* 0x3f81: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_3f83:
	/* 0x3f83: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3f89:
	/* 0x3f89: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3f8f:
	/* 0x3f8f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f92:
	/* 0x3f92: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3f97:
	/* 0x3f97: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3f9d:
	/* 0x3f9d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3fa2:
	/* 0x3fa2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3faa:
	/* 0x3faa: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3fae:
	/* 0x3fae: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3fb5:
	/* 0x3fb5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fba:
	/* 0x3fba: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3fbf:
	/* 0x3fbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fc1:
	/* 0x3fc1: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3fc5:
	/* 0x3fc5: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_3fc7:
	/* 0x3fc7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3fc9:
	/* 0x3fc9: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3fcf:
	/* 0x3fcf: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3fd2:
	/* 0x3fd2: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3fd7:
	/* 0x3fd7: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3fdd:
	/* 0x3fdd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3fe2:
	/* 0x3fe2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3fea:
	/* 0x3fea: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3fee:
	/* 0x3fee: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3ff5:
	/* 0x3ff5: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3ffa:
	/* 0x3ffa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3fff:
	/* 0x3fff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4001:
	/* 0x4001: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4006:
	/* 0x4006: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_400e:
	/* 0x400e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4011:
	/* 0x4011: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4019:
	/* 0x4019: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4022:
	/* 0x4022: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_4029:
	/* 0x4029: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_402e:
	/* 0x402e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4033:
	/* 0x4033: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4038:
	/* 0x4038: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_403a:
	/* 0x403a: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_403c:
	/* 0x403c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4042:
	/* 0x4042: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_4048:
	/* 0x4048: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_404b:
	/* 0x404b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4050:
	/* 0x4050: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4056:
	/* 0x4056: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_405b:
	/* 0x405b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4063:
	/* 0x4063: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4067:
	/* 0x4067: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_406e:
	/* 0x406e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4073:
	/* 0x4073: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4078:
	/* 0x4078: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_407a:
	/* 0x407a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_407e:
	/* 0x407e: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_4080:
	/* 0x4080: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4082:
	/* 0x4082: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_4088:
	/* 0x4088: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_408b:
	/* 0x408b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4090:
	/* 0x4090: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4096:
	/* 0x4096: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_409b:
	/* 0x409b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_40a3:
	/* 0x40a3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_40a7:
	/* 0x40a7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_40ae:
	/* 0x40ae: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_40b3:
	/* 0x40b3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_40b8:
	/* 0x40b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40ba:
	/* 0x40ba: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_40bf:
	/* 0x40bf: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_40c7:
	/* 0x40c7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_40ca:
	/* 0x40ca: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
	return 16594ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16594ULL: goto x86_l_40d2;
	case 16603ULL: goto x86_l_40db;
	case 16610ULL: goto x86_l_40e2;
	case 16615ULL: goto x86_l_40e7;
	case 16620ULL: goto x86_l_40ec;
	case 16625ULL: goto x86_l_40f1;
	case 16627ULL: goto x86_l_40f3;
	case 16629ULL: goto x86_l_40f5;
	case 16635ULL: goto x86_l_40fb;
	case 16641ULL: goto x86_l_4101;
	case 16644ULL: goto x86_l_4104;
	case 16649ULL: goto x86_l_4109;
	case 16655ULL: goto x86_l_410f;
	case 16660ULL: goto x86_l_4114;
	case 16668ULL: goto x86_l_411c;
	case 16672ULL: goto x86_l_4120;
	case 16679ULL: goto x86_l_4127;
	case 16684ULL: goto x86_l_412c;
	case 16689ULL: goto x86_l_4131;
	case 16691ULL: goto x86_l_4133;
	case 16695ULL: goto x86_l_4137;
	case 16697ULL: goto x86_l_4139;
	case 16699ULL: goto x86_l_413b;
	case 16705ULL: goto x86_l_4141;
	case 16708ULL: goto x86_l_4144;
	case 16713ULL: goto x86_l_4149;
	case 16719ULL: goto x86_l_414f;
	case 16724ULL: goto x86_l_4154;
	case 16732ULL: goto x86_l_415c;
	case 16736ULL: goto x86_l_4160;
	case 16743ULL: goto x86_l_4167;
	case 16748ULL: goto x86_l_416c;
	case 16753ULL: goto x86_l_4171;
	case 16755ULL: goto x86_l_4173;
	case 16760ULL: goto x86_l_4178;
	case 16768ULL: goto x86_l_4180;
	case 16771ULL: goto x86_l_4183;
	case 16779ULL: goto x86_l_418b;
	case 16788ULL: goto x86_l_4194;
	case 16795ULL: goto x86_l_419b;
	case 16800ULL: goto x86_l_41a0;
	case 16805ULL: goto x86_l_41a5;
	case 16810ULL: goto x86_l_41aa;
	case 16812ULL: goto x86_l_41ac;
	case 16814ULL: goto x86_l_41ae;
	case 16820ULL: goto x86_l_41b4;
	case 16826ULL: goto x86_l_41ba;
	case 16829ULL: goto x86_l_41bd;
	case 16834ULL: goto x86_l_41c2;
	case 16840ULL: goto x86_l_41c8;
	case 16845ULL: goto x86_l_41cd;
	case 16853ULL: goto x86_l_41d5;
	case 16857ULL: goto x86_l_41d9;
	case 16864ULL: goto x86_l_41e0;
	case 16869ULL: goto x86_l_41e5;
	case 16874ULL: goto x86_l_41ea;
	case 16876ULL: goto x86_l_41ec;
	case 16880ULL: goto x86_l_41f0;
	case 16882ULL: goto x86_l_41f2;
	case 16884ULL: goto x86_l_41f4;
	case 16890ULL: goto x86_l_41fa;
	case 16893ULL: goto x86_l_41fd;
	case 16898ULL: goto x86_l_4202;
	case 16904ULL: goto x86_l_4208;
	case 16909ULL: goto x86_l_420d;
	case 16917ULL: goto x86_l_4215;
	case 16921ULL: goto x86_l_4219;
	case 16928ULL: goto x86_l_4220;
	case 16933ULL: goto x86_l_4225;
	case 16938ULL: goto x86_l_422a;
	case 16940ULL: goto x86_l_422c;
	case 16945ULL: goto x86_l_4231;
	case 16953ULL: goto x86_l_4239;
	case 16956ULL: goto x86_l_423c;
	case 16964ULL: goto x86_l_4244;
	case 16973ULL: goto x86_l_424d;
	case 16980ULL: goto x86_l_4254;
	case 16985ULL: goto x86_l_4259;
	case 16990ULL: goto x86_l_425e;
	case 16995ULL: goto x86_l_4263;
	case 16997ULL: goto x86_l_4265;
	case 16999ULL: goto x86_l_4267;
	case 17005ULL: goto x86_l_426d;
	case 17011ULL: goto x86_l_4273;
	case 17014ULL: goto x86_l_4276;
	case 17019ULL: goto x86_l_427b;
	case 17025ULL: goto x86_l_4281;
	case 17030ULL: goto x86_l_4286;
	case 17038ULL: goto x86_l_428e;
	case 17042ULL: goto x86_l_4292;
	case 17049ULL: goto x86_l_4299;
	case 17054ULL: goto x86_l_429e;
	case 17059ULL: goto x86_l_42a3;
	case 17061ULL: goto x86_l_42a5;
	case 17065ULL: goto x86_l_42a9;
	case 17067ULL: goto x86_l_42ab;
	case 17069ULL: goto x86_l_42ad;
	case 17075ULL: goto x86_l_42b3;
	case 17078ULL: goto x86_l_42b6;
	case 17083ULL: goto x86_l_42bb;
	case 17089ULL: goto x86_l_42c1;
	case 17094ULL: goto x86_l_42c6;
	case 17102ULL: goto x86_l_42ce;
	case 17106ULL: goto x86_l_42d2;
	case 17113ULL: goto x86_l_42d9;
	case 17118ULL: goto x86_l_42de;
	case 17123ULL: goto x86_l_42e3;
	case 17125ULL: goto x86_l_42e5;
	case 17130ULL: goto x86_l_42ea;
	case 17138ULL: goto x86_l_42f2;
	case 17141ULL: goto x86_l_42f5;
	case 17149ULL: goto x86_l_42fd;
	case 17158ULL: goto x86_l_4306;
	case 17165ULL: goto x86_l_430d;
	case 17170ULL: goto x86_l_4312;
	case 17175ULL: goto x86_l_4317;
	case 17180ULL: goto x86_l_431c;
	case 17182ULL: goto x86_l_431e;
	case 17184ULL: goto x86_l_4320;
	case 17190ULL: goto x86_l_4326;
	case 17196ULL: goto x86_l_432c;
	case 17199ULL: goto x86_l_432f;
	case 17204ULL: goto x86_l_4334;
	case 17210ULL: goto x86_l_433a;
	case 17215ULL: goto x86_l_433f;
	case 17223ULL: goto x86_l_4347;
	case 17227ULL: goto x86_l_434b;
	case 17234ULL: goto x86_l_4352;
	case 17239ULL: goto x86_l_4357;
	case 17244ULL: goto x86_l_435c;
	case 17246ULL: goto x86_l_435e;
	case 17250ULL: goto x86_l_4362;
	case 17252ULL: goto x86_l_4364;
	case 17254ULL: goto x86_l_4366;
	case 17260ULL: goto x86_l_436c;
	case 17263ULL: goto x86_l_436f;
	case 17268ULL: goto x86_l_4374;
	case 17274ULL: goto x86_l_437a;
	case 17279ULL: goto x86_l_437f;
	case 17287ULL: goto x86_l_4387;
	case 17291ULL: goto x86_l_438b;
	case 17298ULL: goto x86_l_4392;
	case 17303ULL: goto x86_l_4397;
	case 17308ULL: goto x86_l_439c;
	case 17310ULL: goto x86_l_439e;
	case 17315ULL: goto x86_l_43a3;
	case 17323ULL: goto x86_l_43ab;
	case 17326ULL: goto x86_l_43ae;
	case 17334ULL: goto x86_l_43b6;
	case 17343ULL: goto x86_l_43bf;
	case 17350ULL: goto x86_l_43c6;
	case 17355ULL: goto x86_l_43cb;
	case 17360ULL: goto x86_l_43d0;
	case 17365ULL: goto x86_l_43d5;
	case 17367ULL: goto x86_l_43d7;
	case 17369ULL: goto x86_l_43d9;
	case 17375ULL: goto x86_l_43df;
	case 17381ULL: goto x86_l_43e5;
	case 17384ULL: goto x86_l_43e8;
	case 17389ULL: goto x86_l_43ed;
	case 17395ULL: goto x86_l_43f3;
	case 17400ULL: goto x86_l_43f8;
	case 17408ULL: goto x86_l_4400;
	case 17412ULL: goto x86_l_4404;
	case 17419ULL: goto x86_l_440b;
	case 17424ULL: goto x86_l_4410;
	case 17429ULL: goto x86_l_4415;
	case 17431ULL: goto x86_l_4417;
	case 17435ULL: goto x86_l_441b;
	case 17437ULL: goto x86_l_441d;
	case 17439ULL: goto x86_l_441f;
	case 17445ULL: goto x86_l_4425;
	case 17448ULL: goto x86_l_4428;
	case 17453ULL: goto x86_l_442d;
	case 17459ULL: goto x86_l_4433;
	case 17464ULL: goto x86_l_4438;
	case 17472ULL: goto x86_l_4440;
	case 17476ULL: goto x86_l_4444;
	case 17483ULL: goto x86_l_444b;
	case 17488ULL: goto x86_l_4450;
	case 17493ULL: goto x86_l_4455;
	case 17495ULL: goto x86_l_4457;
	case 17500ULL: goto x86_l_445c;
	case 17508ULL: goto x86_l_4464;
	case 17511ULL: goto x86_l_4467;
	case 17519ULL: goto x86_l_446f;
	case 17528ULL: goto x86_l_4478;
	case 17535ULL: goto x86_l_447f;
	case 17540ULL: goto x86_l_4484;
	case 17545ULL: goto x86_l_4489;
	case 17550ULL: goto x86_l_448e;
	case 17552ULL: goto x86_l_4490;
	case 17554ULL: goto x86_l_4492;
	case 17560ULL: goto x86_l_4498;
	case 17566ULL: goto x86_l_449e;
	case 17569ULL: goto x86_l_44a1;
	case 17574ULL: goto x86_l_44a6;
	case 17580ULL: goto x86_l_44ac;
	case 17585ULL: goto x86_l_44b1;
	case 17593ULL: goto x86_l_44b9;
	case 17597ULL: goto x86_l_44bd;
	case 17604ULL: goto x86_l_44c4;
	case 17609ULL: goto x86_l_44c9;
	case 17614ULL: goto x86_l_44ce;
	case 17616ULL: goto x86_l_44d0;
	case 17620ULL: goto x86_l_44d4;
	case 17622ULL: goto x86_l_44d6;
	case 17624ULL: goto x86_l_44d8;
	case 17630ULL: goto x86_l_44de;
	case 17633ULL: goto x86_l_44e1;
	case 17638ULL: goto x86_l_44e6;
	case 17644ULL: goto x86_l_44ec;
	case 17649ULL: goto x86_l_44f1;
	case 17657ULL: goto x86_l_44f9;
	case 17661ULL: goto x86_l_44fd;
	case 17668ULL: goto x86_l_4504;
	case 17673ULL: goto x86_l_4509;
	case 17678ULL: goto x86_l_450e;
	case 17680ULL: goto x86_l_4510;
	case 17685ULL: goto x86_l_4515;
	case 17693ULL: goto x86_l_451d;
	case 17696ULL: goto x86_l_4520;
	case 17704ULL: goto x86_l_4528;
	case 17713ULL: goto x86_l_4531;
	case 17720ULL: goto x86_l_4538;
	case 17725ULL: goto x86_l_453d;
	case 17730ULL: goto x86_l_4542;
	case 17735ULL: goto x86_l_4547;
	case 17737ULL: goto x86_l_4549;
	case 17739ULL: goto x86_l_454b;
	case 17745ULL: goto x86_l_4551;
	case 17751ULL: goto x86_l_4557;
	case 17754ULL: goto x86_l_455a;
	case 17759ULL: goto x86_l_455f;
	case 17765ULL: goto x86_l_4565;
	case 17770ULL: goto x86_l_456a;
	case 17778ULL: goto x86_l_4572;
	case 17782ULL: goto x86_l_4576;
	case 17789ULL: goto x86_l_457d;
	case 17794ULL: goto x86_l_4582;
	case 17799ULL: goto x86_l_4587;
	case 17801ULL: goto x86_l_4589;
	case 17805ULL: goto x86_l_458d;
	case 17807ULL: goto x86_l_458f;
	case 17809ULL: goto x86_l_4591;
	case 17815ULL: goto x86_l_4597;
	case 17818ULL: goto x86_l_459a;
	case 17823ULL: goto x86_l_459f;
	case 17829ULL: goto x86_l_45a5;
	case 17834ULL: goto x86_l_45aa;
	case 17842ULL: goto x86_l_45b2;
	case 17846ULL: goto x86_l_45b6;
	case 17853ULL: goto x86_l_45bd;
	case 17858ULL: goto x86_l_45c2;
	case 17863ULL: goto x86_l_45c7;
	case 17865ULL: goto x86_l_45c9;
	case 17870ULL: goto x86_l_45ce;
	case 17878ULL: goto x86_l_45d6;
	case 17881ULL: goto x86_l_45d9;
	case 17889ULL: goto x86_l_45e1;
	case 17898ULL: goto x86_l_45ea;
	case 17905ULL: goto x86_l_45f1;
	case 17910ULL: goto x86_l_45f6;
	case 17915ULL: goto x86_l_45fb;
	case 17920ULL: goto x86_l_4600;
	case 17923ULL: goto x86_l_4603;
	case 17925ULL: goto x86_l_4605;
	case 17927ULL: goto x86_l_4607;
	case 17933ULL: goto x86_l_460d;
	case 17939ULL: goto x86_l_4613;
	case 17942ULL: goto x86_l_4616;
	case 17947ULL: goto x86_l_461b;
	case 17953ULL: goto x86_l_4621;
	case 17958ULL: goto x86_l_4626;
	case 17966ULL: goto x86_l_462e;
	case 17970ULL: goto x86_l_4632;
	case 17977ULL: goto x86_l_4639;
	case 17982ULL: goto x86_l_463e;
	case 17987ULL: goto x86_l_4643;
	case 17989ULL: goto x86_l_4645;
	case 17993ULL: goto x86_l_4649;
	case 17995ULL: goto x86_l_464b;
	case 17997ULL: goto x86_l_464d;
	case 18003ULL: goto x86_l_4653;
	case 18006ULL: goto x86_l_4656;
	case 18011ULL: goto x86_l_465b;
	case 18017ULL: goto x86_l_4661;
	case 18022ULL: goto x86_l_4666;
	case 18030ULL: goto x86_l_466e;
	case 18034ULL: goto x86_l_4672;
	case 18041ULL: goto x86_l_4679;
	case 18046ULL: goto x86_l_467e;
	case 18051ULL: goto x86_l_4683;
	case 18053ULL: goto x86_l_4685;
	case 18058ULL: goto x86_l_468a;
	case 18066ULL: goto x86_l_4692;
	case 18069ULL: goto x86_l_4695;
	case 18077ULL: goto x86_l_469d;
	case 18085ULL: goto x86_l_46a5;
	case 18088ULL: goto x86_l_46a8;
	case 18093ULL: goto x86_l_46ad;
	case 18095ULL: goto x86_l_46af;
	case 18100ULL: goto x86_l_46b4;
	case 18105ULL: goto x86_l_46b9;
	case 18113ULL: goto x86_l_46c1;
	case 18117ULL: goto x86_l_46c5;
	case 18124ULL: goto x86_l_46cc;
	case 18129ULL: goto x86_l_46d1;
	case 18134ULL: goto x86_l_46d6;
	case 18136ULL: goto x86_l_46d8;
	case 18140ULL: goto x86_l_46dc;
	case 18142ULL: goto x86_l_46de;
	case 18144ULL: goto x86_l_46e0;
	case 18150ULL: goto x86_l_46e6;
	case 18153ULL: goto x86_l_46e9;
	case 18158ULL: goto x86_l_46ee;
	case 18164ULL: goto x86_l_46f4;
	case 18169ULL: goto x86_l_46f9;
	case 18177ULL: goto x86_l_4701;
	case 18181ULL: goto x86_l_4705;
	case 18188ULL: goto x86_l_470c;
	case 18193ULL: goto x86_l_4711;
	case 18198ULL: goto x86_l_4716;
	case 18200ULL: goto x86_l_4718;
	case 18205ULL: goto x86_l_471d;
	case 18213ULL: goto x86_l_4725;
	case 18216ULL: goto x86_l_4728;
	case 18224ULL: goto x86_l_4730;
	case 18226ULL: goto x86_l_4732;
	default: return 0xffffffffffffffffULL;
	}
x86_l_40d2:
	/* 0x40d2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_40db:
	/* 0x40db: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_40e2:
	/* 0x40e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_40e7:
	/* 0x40e7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40ec:
	/* 0x40ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40f1:
	/* 0x40f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40f3:
	/* 0x40f3: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_40f5:
	/* 0x40f5: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_40fb:
	/* 0x40fb: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_4101:
	/* 0x4101: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4104:
	/* 0x4104: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4109:
	/* 0x4109: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_410f:
	/* 0x410f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4114:
	/* 0x4114: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_411c:
	/* 0x411c: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4120:
	/* 0x4120: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4127:
	/* 0x4127: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_412c:
	/* 0x412c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4131:
	/* 0x4131: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4133:
	/* 0x4133: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4137:
	/* 0x4137: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_4139:
	/* 0x4139: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_413b:
	/* 0x413b: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_4141:
	/* 0x4141: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4144:
	/* 0x4144: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4149:
	/* 0x4149: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_414f:
	/* 0x414f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4154:
	/* 0x4154: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_415c:
	/* 0x415c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4160:
	/* 0x4160: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4167:
	/* 0x4167: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_416c:
	/* 0x416c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4171:
	/* 0x4171: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4173:
	/* 0x4173: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4178:
	/* 0x4178: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4180:
	/* 0x4180: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4183:
	/* 0x4183: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_418b:
	/* 0x418b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4194:
	/* 0x4194: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_419b:
	/* 0x419b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41a0:
	/* 0x41a0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41a5:
	/* 0x41a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41aa:
	/* 0x41aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41ac:
	/* 0x41ac: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_41ae:
	/* 0x41ae: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_41b4:
	/* 0x41b4: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_41ba:
	/* 0x41ba: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41bd:
	/* 0x41bd: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_41c2:
	/* 0x41c2: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_41c8:
	/* 0x41c8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_41cd:
	/* 0x41cd: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_41d5:
	/* 0x41d5: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_41d9:
	/* 0x41d9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_41e0:
	/* 0x41e0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41e5:
	/* 0x41e5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_41ea:
	/* 0x41ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41ec:
	/* 0x41ec: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_41f0:
	/* 0x41f0: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_41f2:
	/* 0x41f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41f4:
	/* 0x41f4: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_41fa:
	/* 0x41fa: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41fd:
	/* 0x41fd: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4202:
	/* 0x4202: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4208:
	/* 0x4208: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_420d:
	/* 0x420d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4215:
	/* 0x4215: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4219:
	/* 0x4219: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4220:
	/* 0x4220: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4225:
	/* 0x4225: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_422a:
	/* 0x422a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_422c:
	/* 0x422c: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4231:
	/* 0x4231: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4239:
	/* 0x4239: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_423c:
	/* 0x423c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4244:
	/* 0x4244: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_424d:
	/* 0x424d: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_4254:
	/* 0x4254: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4259:
	/* 0x4259: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_425e:
	/* 0x425e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4263:
	/* 0x4263: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4265:
	/* 0x4265: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_4267:
	/* 0x4267: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_426d:
	/* 0x426d: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_4273:
	/* 0x4273: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4276:
	/* 0x4276: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_427b:
	/* 0x427b: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4281:
	/* 0x4281: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4286:
	/* 0x4286: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_428e:
	/* 0x428e: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4292:
	/* 0x4292: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4299:
	/* 0x4299: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_429e:
	/* 0x429e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_42a3:
	/* 0x42a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42a5:
	/* 0x42a5: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_42a9:
	/* 0x42a9: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_42ab:
	/* 0x42ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42ad:
	/* 0x42ad: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_42b3:
	/* 0x42b3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_42b6:
	/* 0x42b6: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_42bb:
	/* 0x42bb: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_42c1:
	/* 0x42c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_42c6:
	/* 0x42c6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_42ce:
	/* 0x42ce: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_42d2:
	/* 0x42d2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_42d9:
	/* 0x42d9: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_42de:
	/* 0x42de: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_42e3:
	/* 0x42e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42e5:
	/* 0x42e5: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_42ea:
	/* 0x42ea: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_42f2:
	/* 0x42f2: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_42f5:
	/* 0x42f5: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_42fd:
	/* 0x42fd: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4306:
	/* 0x4306: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_430d:
	/* 0x430d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4312:
	/* 0x4312: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4317:
	/* 0x4317: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_431c:
	/* 0x431c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_431e:
	/* 0x431e: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_4320:
	/* 0x4320: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4326:
	/* 0x4326: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_432c:
	/* 0x432c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_432f:
	/* 0x432f: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4334:
	/* 0x4334: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_433a:
	/* 0x433a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_433f:
	/* 0x433f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4347:
	/* 0x4347: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_434b:
	/* 0x434b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4352:
	/* 0x4352: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4357:
	/* 0x4357: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_435c:
	/* 0x435c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_435e:
	/* 0x435e: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4362:
	/* 0x4362: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_4364:
	/* 0x4364: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4366:
	/* 0x4366: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_436c:
	/* 0x436c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_436f:
	/* 0x436f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4374:
	/* 0x4374: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_437a:
	/* 0x437a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_437f:
	/* 0x437f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4387:
	/* 0x4387: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_438b:
	/* 0x438b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4392:
	/* 0x4392: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4397:
	/* 0x4397: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_439c:
	/* 0x439c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_439e:
	/* 0x439e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_43a3:
	/* 0x43a3: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_43ab:
	/* 0x43ab: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_43ae:
	/* 0x43ae: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_43b6:
	/* 0x43b6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_43bf:
	/* 0x43bf: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_43c6:
	/* 0x43c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_43cb:
	/* 0x43cb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43d0:
	/* 0x43d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43d5:
	/* 0x43d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43d7:
	/* 0x43d7: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_43d9:
	/* 0x43d9: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_43df:
	/* 0x43df: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_43e5:
	/* 0x43e5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_43e8:
	/* 0x43e8: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_43ed:
	/* 0x43ed: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_43f3:
	/* 0x43f3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_43f8:
	/* 0x43f8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4400:
	/* 0x4400: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4404:
	/* 0x4404: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_440b:
	/* 0x440b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4410:
	/* 0x4410: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4415:
	/* 0x4415: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4417:
	/* 0x4417: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_441b:
	/* 0x441b: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_441d:
	/* 0x441d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_441f:
	/* 0x441f: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_4425:
	/* 0x4425: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4428:
	/* 0x4428: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_442d:
	/* 0x442d: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4433:
	/* 0x4433: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4438:
	/* 0x4438: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4440:
	/* 0x4440: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4444:
	/* 0x4444: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_444b:
	/* 0x444b: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4450:
	/* 0x4450: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4455:
	/* 0x4455: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4457:
	/* 0x4457: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_445c:
	/* 0x445c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4464:
	/* 0x4464: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4467:
	/* 0x4467: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_446f:
	/* 0x446f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4478:
	/* 0x4478: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_447f:
	/* 0x447f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4484:
	/* 0x4484: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4489:
	/* 0x4489: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_448e:
	/* 0x448e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4490:
	/* 0x4490: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_4492:
	/* 0x4492: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4498:
	/* 0x4498: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_449e:
	/* 0x449e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_44a1:
	/* 0x44a1: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_44a6:
	/* 0x44a6: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_44ac:
	/* 0x44ac: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_44b1:
	/* 0x44b1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_44b9:
	/* 0x44b9: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_44bd:
	/* 0x44bd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_44c4:
	/* 0x44c4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44c9:
	/* 0x44c9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_44ce:
	/* 0x44ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44d0:
	/* 0x44d0: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_44d4:
	/* 0x44d4: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_44d6:
	/* 0x44d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44d8:
	/* 0x44d8: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_44de:
	/* 0x44de: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_44e1:
	/* 0x44e1: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_44e6:
	/* 0x44e6: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_44ec:
	/* 0x44ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_44f1:
	/* 0x44f1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_44f9:
	/* 0x44f9: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_44fd:
	/* 0x44fd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4504:
	/* 0x4504: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4509:
	/* 0x4509: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_450e:
	/* 0x450e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4510:
	/* 0x4510: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4515:
	/* 0x4515: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_451d:
	/* 0x451d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4520:
	/* 0x4520: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4528:
	/* 0x4528: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4531:
	/* 0x4531: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_4538:
	/* 0x4538: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_453d:
	/* 0x453d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4542:
	/* 0x4542: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4547:
	/* 0x4547: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4549:
	/* 0x4549: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_454b:
	/* 0x454b: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4551:
	/* 0x4551: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_4557:
	/* 0x4557: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_455a:
	/* 0x455a: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_455f:
	/* 0x455f: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4565:
	/* 0x4565: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_456a:
	/* 0x456a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4572:
	/* 0x4572: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4576:
	/* 0x4576: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_457d:
	/* 0x457d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4582:
	/* 0x4582: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4587:
	/* 0x4587: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4589:
	/* 0x4589: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_458d:
	/* 0x458d: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_458f:
	/* 0x458f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4591:
	/* 0x4591: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_4597:
	/* 0x4597: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_459a:
	/* 0x459a: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_459f:
	/* 0x459f: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_45a5:
	/* 0x45a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_45aa:
	/* 0x45aa: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_45b2:
	/* 0x45b2: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_45b6:
	/* 0x45b6: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_45bd:
	/* 0x45bd: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_45c2:
	/* 0x45c2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_45c7:
	/* 0x45c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45c9:
	/* 0x45c9: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_45ce:
	/* 0x45ce: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_45d6:
	/* 0x45d6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_45d9:
	/* 0x45d9: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_45e1:
	/* 0x45e1: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_45ea:
	/* 0x45ea: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_45f1:
	/* 0x45f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_45f6:
	/* 0x45f6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45fb:
	/* 0x45fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4600:
	/* 0x4600: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4603:
	/* 0x4603: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4605:
	/* 0x4605: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_4607:
	/* 0x4607: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_460d:
	/* 0x460d: je     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_4613:
	/* 0x4613: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4616:
	/* 0x4616: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_461b:
	/* 0x461b: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4621:
	/* 0x4621: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4626:
	/* 0x4626: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_462e:
	/* 0x462e: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4632:
	/* 0x4632: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4639:
	/* 0x4639: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_463e:
	/* 0x463e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4643:
	/* 0x4643: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4645:
	/* 0x4645: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4649:
	/* 0x4649: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_464b:
	/* 0x464b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_464d:
	/* 0x464d: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_4653:
	/* 0x4653: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4656:
	/* 0x4656: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_465b:
	/* 0x465b: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4661:
	/* 0x4661: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4666:
	/* 0x4666: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_466e:
	/* 0x466e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4672:
	/* 0x4672: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4679:
	/* 0x4679: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_467e:
	/* 0x467e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4683:
	/* 0x4683: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4685:
	/* 0x4685: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_468a:
	/* 0x468a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4692:
	/* 0x4692: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4695:
	/* 0x4695: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_469d:
	/* 0x469d: mov    DWORD PTR [rsp+0x10],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68722503214ULL);
x86_l_46a5:
	/* 0x46a5: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_46a8:
	/* 0x46a8: cmp    eax,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27901ULL);
x86_l_46ad:
	/* 0x46ad: jb     46b4 <syscall__execve_enter+0x46b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_46b4;
	}
x86_l_46af:
	/* 0x46af: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_46b4:
	/* 0x46b4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_46b9:
	/* 0x46b9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_46c1:
	/* 0x46c1: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_46c5:
	/* 0x46c5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_46cc:
	/* 0x46cc: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46d1:
	/* 0x46d1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_46d6:
	/* 0x46d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46d8:
	/* 0x46d8: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_46dc:
	/* 0x46dc: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_46de:
	/* 0x46de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46e0:
	/* 0x46e0: jle    bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_46e6:
	/* 0x46e6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_46e9:
	/* 0x46e9: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_46ee:
	/* 0x46ee: ja     bd5 <syscall__execve_enter+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_46f4:
	/* 0x46f4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_46f9:
	/* 0x46f9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4701:
	/* 0x4701: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4705:
	/* 0x4705: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_470c:
	/* 0x470c: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4711:
	/* 0x4711: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4716:
	/* 0x4716: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4718:
	/* 0x4718: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_471d:
	/* 0x471d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4725:
	/* 0x4725: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4728:
	/* 0x4728: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4730:
	/* 0x4730: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_4732:
	/* 0x4732: jmp    bd5 <syscall__execve_enter+0xbd5> */
	return 3029ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_syscall__execve_enter_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 15140U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1722ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1725ULL && __x86_pc <= 3380ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3385ULL && __x86_pc <= 5137ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5145ULL && __x86_pc <= 7031ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7037ULL && __x86_pc <= 8945ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8951ULL && __x86_pc <= 10877ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10882ULL && __x86_pc <= 12768ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12774ULL && __x86_pc <= 14664ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14670ULL && __x86_pc <= 16586ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16594ULL && __x86_pc <= 18226ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_9(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

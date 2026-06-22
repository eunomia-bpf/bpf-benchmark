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
	/* 0x1a: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x2b: je     20b <syscall__execve_exit+0x20b> */
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
	/* 0x39: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x4a: je     20b <syscall__execve_exit+0x20b> */
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
	/* 0x5c: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x6b: je     20b <syscall__execve_exit+0x20b> */
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
	/* 0x7d: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x8c: je     20b <syscall__execve_exit+0x20b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b;
	}
x86_l_92:
	/* 0x92: cmp    QWORD PTR [r13+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_9a:
	/* 0x9a: je     212 <syscall__execve_exit+0x212> */
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
	/* 0x149: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x15a: je     20b <syscall__execve_exit+0x20b> */
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
	/* 0x172: je     20b <syscall__execve_exit+0x20b> */
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
	/* 0x1f0: jne    21c <syscall__execve_exit+0x21c> */
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
	/* 0x200: jne    9c7 <syscall__execve_exit+0x9c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2503ULL;
	}
x86_l_206:
	/* 0x206: jmp    10a5 <syscall__execve_exit+0x10a5> */
	return 4261ULL;
x86_l_20b:
	/* 0x20b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20d:
	/* 0x20d: jmp    10a5 <syscall__execve_exit+0x10a5> */
	return 4261ULL;
x86_l_212:
	/* 0x212: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_217:
	/* 0x217: jmp    10a5 <syscall__execve_exit+0x10a5> */
	return 4261ULL;
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
	/* 0x22e: je     3de <syscall__execve_exit+0x3de> */
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
	/* 0x262: je     288 <syscall__execve_exit+0x288> */
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
	/* 0x292: je     2ae <syscall__execve_exit+0x2ae> */
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
	/* 0x2b8: je     2d9 <syscall__execve_exit+0x2d9> */
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
	/* 0x2ed: je     444 <syscall__execve_exit+0x444> */
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
	/* 0x32f: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x353: je     375 <syscall__execve_exit+0x375> */
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
	/* 0x367: je     375 <syscall__execve_exit+0x375> */
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
	/* 0x373: jmp    377 <syscall__execve_exit+0x377> */
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
	/* 0x38f: jb     3a7 <syscall__execve_exit+0x3a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3a7;
	}
x86_l_391:
	/* 0x391: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_395:
	/* 0x395: je     39c <syscall__execve_exit+0x39c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39c;
	}
x86_l_397:
	/* 0x397: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_39a:
	/* 0x39a: jbe    3a7 <syscall__execve_exit+0x3a7> */
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
	/* 0x3b9: je     3fa <syscall__execve_exit+0x3fa> */
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
	/* 0x3d0: je     406 <syscall__execve_exit+0x406> */
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
	/* 0x3dc: jmp    408 <syscall__execve_exit+0x408> */
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
	/* 0x3ef: jne    264 <syscall__execve_exit+0x264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_264;
	}
x86_l_3f5:
	/* 0x3f5: jmp    288 <syscall__execve_exit+0x288> */
	goto x86_l_288;
x86_l_3fa:
	/* 0x3fa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fc:
	/* 0x3fc: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_404:
	/* 0x404: jmp    418 <syscall__execve_exit+0x418> */
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
	/* 0x423: jb     43b <syscall__execve_exit+0x43b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_43b;
	}
x86_l_425:
	/* 0x425: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_429:
	/* 0x429: je     430 <syscall__execve_exit+0x430> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430;
	}
x86_l_42b:
	/* 0x42b: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_42e:
	/* 0x42e: jbe    43b <syscall__execve_exit+0x43b> */
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
	/* 0x44c: je     4ea <syscall__execve_exit+0x4ea> */
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
	/* 0x48d: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x4ae: je     4d0 <syscall__execve_exit+0x4d0> */
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
	/* 0x4c2: je     4d0 <syscall__execve_exit+0x4d0> */
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
	/* 0x4ce: jmp    4d2 <syscall__execve_exit+0x4d2> */
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
	/* 0x4e0: jae    4f2 <syscall__execve_exit+0x4f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4f2;
	}
x86_l_4e2:
	/* 0x4e2: movzx  r13d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_4e8:
	/* 0x4e8: jmp    50b <syscall__execve_exit+0x50b> */
	goto x86_l_50b;
x86_l_4ea:
	/* 0x4ea: movzx  r13d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_4f0:
	/* 0x4f0: jmp    511 <syscall__execve_exit+0x511> */
	goto x86_l_511;
x86_l_4f2:
	/* 0x4f2: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_4f6:
	/* 0x4f6: movzx  r13d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_4fc:
	/* 0x4fc: je     503 <syscall__execve_exit+0x503> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_503;
	}
x86_l_4fe:
	/* 0x4fe: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_501:
	/* 0x501: jbe    50b <syscall__execve_exit+0x50b> */
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
	/* 0x519: je     5d7 <syscall__execve_exit+0x5d7> */
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
	/* 0x590: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x5a8: je     5c9 <syscall__execve_exit+0x5c9> */
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
	/* 0x5bb: je     5c9 <syscall__execve_exit+0x5c9> */
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
	/* 0x5c7: jmp    5cb <syscall__execve_exit+0x5cb> */
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
	/* 0x5df: je     6c0 <syscall__execve_exit+0x6c0> */
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
	/* 0x679: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x691: je     6b2 <syscall__execve_exit+0x6b2> */
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
	/* 0x6a4: je     6b2 <syscall__execve_exit+0x6b2> */
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
	/* 0x6b0: jmp    6b4 <syscall__execve_exit+0x6b4> */
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

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_1(
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
	case 3041ULL: goto x86_l_be1;
	case 3043ULL: goto x86_l_be3;
	case 3051ULL: goto x86_l_beb;
	case 3058ULL: goto x86_l_bf2;
	case 3061ULL: goto x86_l_bf5;
	case 3068ULL: goto x86_l_bfc;
	case 3070ULL: goto x86_l_bfe;
	case 3079ULL: goto x86_l_c07;
	case 3085ULL: goto x86_l_c0d;
	case 3087ULL: goto x86_l_c0f;
	case 3090ULL: goto x86_l_c12;
	case 3097ULL: goto x86_l_c19;
	case 3101ULL: goto x86_l_c1d;
	case 3108ULL: goto x86_l_c24;
	case 3113ULL: goto x86_l_c29;
	case 3118ULL: goto x86_l_c2e;
	case 3120ULL: goto x86_l_c30;
	case 3123ULL: goto x86_l_c33;
	case 3125ULL: goto x86_l_c35;
	case 3128ULL: goto x86_l_c38;
	case 3136ULL: goto x86_l_c40;
	case 3143ULL: goto x86_l_c47;
	case 3150ULL: goto x86_l_c4e;
	case 3154ULL: goto x86_l_c52;
	case 3159ULL: goto x86_l_c57;
	case 3164ULL: goto x86_l_c5c;
	case 3169ULL: goto x86_l_c61;
	case 3172ULL: goto x86_l_c64;
	case 3174ULL: goto x86_l_c66;
	case 3179ULL: goto x86_l_c6b;
	case 3187ULL: goto x86_l_c73;
	case 3191ULL: goto x86_l_c77;
	case 3196ULL: goto x86_l_c7c;
	case 3201ULL: goto x86_l_c81;
	case 3206ULL: goto x86_l_c86;
	case 3208ULL: goto x86_l_c88;
	case 3213ULL: goto x86_l_c8d;
	case 3217ULL: goto x86_l_c91;
	case 3222ULL: goto x86_l_c96;
	case 3227ULL: goto x86_l_c9b;
	case 3232ULL: goto x86_l_ca0;
	case 3234ULL: goto x86_l_ca2;
	case 3239ULL: goto x86_l_ca7;
	case 3243ULL: goto x86_l_cab;
	case 3248ULL: goto x86_l_cb0;
	case 3253ULL: goto x86_l_cb5;
	case 3258ULL: goto x86_l_cba;
	case 3260ULL: goto x86_l_cbc;
	case 3264ULL: goto x86_l_cc0;
	case 3268ULL: goto x86_l_cc4;
	case 3272ULL: goto x86_l_cc8;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3287ULL: goto x86_l_cd7;
	case 3290ULL: goto x86_l_cda;
	case 3292ULL: goto x86_l_cdc;
	case 3297ULL: goto x86_l_ce1;
	case 3302ULL: goto x86_l_ce6;
	case 3307ULL: goto x86_l_ceb;
	case 3312ULL: goto x86_l_cf0;
	case 3315ULL: goto x86_l_cf3;
	case 3317ULL: goto x86_l_cf5;
	case 3321ULL: goto x86_l_cf9;
	case 3325ULL: goto x86_l_cfd;
	case 3329ULL: goto x86_l_d01;
	case 3333ULL: goto x86_l_d05;
	case 3338ULL: goto x86_l_d0a;
	case 3343ULL: goto x86_l_d0f;
	case 3348ULL: goto x86_l_d14;
	case 3350ULL: goto x86_l_d16;
	case 3354ULL: goto x86_l_d1a;
	case 3358ULL: goto x86_l_d1e;
	case 3363ULL: goto x86_l_d23;
	case 3368ULL: goto x86_l_d28;
	case 3373ULL: goto x86_l_d2d;
	case 3376ULL: goto x86_l_d30;
	case 3378ULL: goto x86_l_d32;
	case 3383ULL: goto x86_l_d37;
	case 3387ULL: goto x86_l_d3b;
	case 3392ULL: goto x86_l_d40;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6bd:
	/* 0x6bd: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_6c0:
	/* 0x6c0: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_6c8:
	/* 0x6c8: je     798 <syscall__execve_exit+0x798> */
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
	/* 0x74c: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x764: je     784 <syscall__execve_exit+0x784> */
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
	/* 0x776: je     784 <syscall__execve_exit+0x784> */
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
	/* 0x782: jmp    786 <syscall__execve_exit+0x786> */
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
	/* 0x7a0: je     81d <syscall__execve_exit+0x81d> */
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
	/* 0x7d1: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x7e9: je     809 <syscall__execve_exit+0x809> */
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
	/* 0x7fb: je     809 <syscall__execve_exit+0x809> */
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
	/* 0x807: jmp    80b <syscall__execve_exit+0x80b> */
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
	/* 0x827: je     88e <syscall__execve_exit+0x88e> */
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
	/* 0x846: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x85e: je     880 <syscall__execve_exit+0x880> */
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
	/* 0x872: je     880 <syscall__execve_exit+0x880> */
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
	/* 0x87e: jmp    882 <syscall__execve_exit+0x882> */
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
	/* 0x898: je     8fa <syscall__execve_exit+0x8fa> */
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
	/* 0x8af: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x8c7: je     8ec <syscall__execve_exit+0x8ec> */
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
	/* 0x8de: je     8ec <syscall__execve_exit+0x8ec> */
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
	/* 0x8ea: jmp    8ee <syscall__execve_exit+0x8ee> */
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
	/* 0x904: je     98c <syscall__execve_exit+0x98c> */
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
	/* 0x91f: mov    rdi,QWORD PTR [rip+0x4757] */
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
	/* 0x937: je     97e <syscall__execve_exit+0x97e> */
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
	/* 0x955: jne    972 <syscall__execve_exit+0x972> */
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
	/* 0x970: je     97e <syscall__execve_exit+0x97e> */
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
	/* 0x97c: jmp    980 <syscall__execve_exit+0x980> */
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
	/* 0x996: je     9a7 <syscall__execve_exit+0x9a7> */
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
	/* 0x9c1: je     10a5 <syscall__execve_exit+0x10a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4261ULL;
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
	/* 0x9d7: jb     9e8 <syscall__execve_exit+0x9e8> */
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
	/* 0x9e3: jmp    b2b <syscall__execve_exit+0xb2b> */
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
	/* 0xa15: ja     a6f <syscall__execve_exit+0xa6f> */
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
	/* 0xa38: jle    a6c <syscall__execve_exit+0xa6c> */
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
	/* 0xa44: ja     a6f <syscall__execve_exit+0xa6f> */
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
	/* 0xa6a: jmp    a6f <syscall__execve_exit+0xa6f> */
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
	/* 0xa77: ja     b2b <syscall__execve_exit+0xb2b> */
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
	/* 0xac1: je     b07 <syscall__execve_exit+0xb07> */
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
	/* 0xacb: ja     b07 <syscall__execve_exit+0xb07> */
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
	/* 0xaf7: jle    b07 <syscall__execve_exit+0xb07> */
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
	/* 0xb01: jbe    10b4 <syscall__execve_exit+0x10b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4276ULL;
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
	/* 0xb1a: ja     b2b <syscall__execve_exit+0xb2b> */
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
	/* 0xb31: je     bf2 <syscall__execve_exit+0xbf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf2;
	}
x86_l_b37:
	/* 0xb37: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b3a:
	/* 0xb3a: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_b40:
	/* 0xb40: ja     bf2 <syscall__execve_exit+0xbf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bf2;
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
	/* 0xb8d: je     bd3 <syscall__execve_exit+0xbd3> */
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
	/* 0xb97: ja     bd3 <syscall__execve_exit+0xbd3> */
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
	/* 0xbc3: jle    bd3 <syscall__execve_exit+0xbd3> */
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
	/* 0xbcd: jbe    2c28 <syscall__execve_exit+0x2c28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11304ULL;
	}
x86_l_bd3:
	/* 0xbd3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd5:
	/* 0xbd5: cmp    r15d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31998ULL);
x86_l_bdc:
	/* 0xbdc: mov    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_be1:
	/* 0xbe1: ja     bf2 <syscall__execve_exit+0xbf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bf2;
	}
x86_l_be3:
	/* 0xbe3: mov    BYTE PTR [r14+r15*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_beb:
	/* 0xbeb: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_bf2:
	/* 0xbf2: movzx  ebx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_bf5:
	/* 0xbf5: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_bfc:
	/* 0xbfc: ja     c47 <syscall__execve_exit+0xc47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c47;
	}
x86_l_bfe:
	/* 0xbfe: mov    BYTE PTR [r14+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_c07:
	/* 0xc07: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_c0d:
	/* 0xc0d: ja     c47 <syscall__execve_exit+0xc47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c47;
	}
x86_l_c0f:
	/* 0xc0f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c12:
	/* 0xc12: add    rdx,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_c19:
	/* 0xc19: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_c1d:
	/* 0xc1d: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_c24:
	/* 0xc24: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c29:
	/* 0xc29: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c2e:
	/* 0xc2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c30:
	/* 0xc30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c33:
	/* 0xc33: js     c47 <syscall__execve_exit+0xc47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_c47;
	}
x86_l_c35:
	/* 0xc35: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_c38:
	/* 0xc38: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_c40:
	/* 0xc40: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_c47:
	/* 0xc47: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_c4e:
	/* 0xc4e: lea    r12,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c52:
	/* 0xc52: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c57:
	/* 0xc57: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c5c:
	/* 0xc5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c61:
	/* 0xc61: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_c64:
	/* 0xc64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c66:
	/* 0xc66: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c6b:
	/* 0xc6b: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c73:
	/* 0xc73: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c77:
	/* 0xc77: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c7c:
	/* 0xc7c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c81:
	/* 0xc81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c86:
	/* 0xc86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c88:
	/* 0xc88: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c8d:
	/* 0xc8d: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_c91:
	/* 0xc91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c96:
	/* 0xc96: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c9b:
	/* 0xc9b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ca0:
	/* 0xca0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca2:
	/* 0xca2: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ca7:
	/* 0xca7: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
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
	/* 0xcc0: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_cc4:
	/* 0xcc4: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cc8:
	/* 0xcc8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ccd:
	/* 0xccd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cd2:
	/* 0xcd2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cd7:
	/* 0xcd7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_cda:
	/* 0xcda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cdc:
	/* 0xcdc: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ce1:
	/* 0xce1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ce6:
	/* 0xce6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ceb:
	/* 0xceb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cf0:
	/* 0xcf0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_cf3:
	/* 0xcf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf5:
	/* 0xcf5: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cf9:
	/* 0xcf9: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_cfd:
	/* 0xcfd: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_d01:
	/* 0xd01: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d05:
	/* 0xd05: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d0a:
	/* 0xd0a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d0f:
	/* 0xd0f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d14:
	/* 0xd14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d16:
	/* 0xd16: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d1a:
	/* 0xd1a: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_d1e:
	/* 0xd1e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d23:
	/* 0xd23: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d28:
	/* 0xd28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d2d:
	/* 0xd2d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d30:
	/* 0xd30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d32:
	/* 0xd32: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d37:
	/* 0xd37: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d3b:
	/* 0xd3b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d40:
	/* 0xd40: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 3397ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3397ULL: goto x86_l_d45;
	case 3402ULL: goto x86_l_d4a;
	case 3404ULL: goto x86_l_d4c;
	case 3409ULL: goto x86_l_d51;
	case 3414ULL: goto x86_l_d56;
	case 3419ULL: goto x86_l_d5b;
	case 3424ULL: goto x86_l_d60;
	case 3427ULL: goto x86_l_d63;
	case 3429ULL: goto x86_l_d65;
	case 3433ULL: goto x86_l_d69;
	case 3437ULL: goto x86_l_d6d;
	case 3441ULL: goto x86_l_d71;
	case 3445ULL: goto x86_l_d75;
	case 3450ULL: goto x86_l_d7a;
	case 3455ULL: goto x86_l_d7f;
	case 3460ULL: goto x86_l_d84;
	case 3462ULL: goto x86_l_d86;
	case 3466ULL: goto x86_l_d8a;
	case 3470ULL: goto x86_l_d8e;
	case 3475ULL: goto x86_l_d93;
	case 3480ULL: goto x86_l_d98;
	case 3485ULL: goto x86_l_d9d;
	case 3488ULL: goto x86_l_da0;
	case 3490ULL: goto x86_l_da2;
	case 3495ULL: goto x86_l_da7;
	case 3500ULL: goto x86_l_dac;
	case 3505ULL: goto x86_l_db1;
	case 3510ULL: goto x86_l_db6;
	case 3513ULL: goto x86_l_db9;
	case 3515ULL: goto x86_l_dbb;
	case 3519ULL: goto x86_l_dbf;
	case 3523ULL: goto x86_l_dc3;
	case 3527ULL: goto x86_l_dc7;
	case 3531ULL: goto x86_l_dcb;
	case 3536ULL: goto x86_l_dd0;
	case 3541ULL: goto x86_l_dd5;
	case 3546ULL: goto x86_l_dda;
	case 3548ULL: goto x86_l_ddc;
	case 3553ULL: goto x86_l_de1;
	case 3557ULL: goto x86_l_de5;
	case 3562ULL: goto x86_l_dea;
	case 3567ULL: goto x86_l_def;
	case 3572ULL: goto x86_l_df4;
	case 3574ULL: goto x86_l_df6;
	case 3579ULL: goto x86_l_dfb;
	case 3583ULL: goto x86_l_dff;
	case 3588ULL: goto x86_l_e04;
	case 3593ULL: goto x86_l_e09;
	case 3598ULL: goto x86_l_e0e;
	case 3601ULL: goto x86_l_e11;
	case 3603ULL: goto x86_l_e13;
	case 3608ULL: goto x86_l_e18;
	case 3613ULL: goto x86_l_e1d;
	case 3618ULL: goto x86_l_e22;
	case 3623ULL: goto x86_l_e27;
	case 3626ULL: goto x86_l_e2a;
	case 3628ULL: goto x86_l_e2c;
	case 3632ULL: goto x86_l_e30;
	case 3636ULL: goto x86_l_e34;
	case 3640ULL: goto x86_l_e38;
	case 3644ULL: goto x86_l_e3c;
	case 3649ULL: goto x86_l_e41;
	case 3654ULL: goto x86_l_e46;
	case 3659ULL: goto x86_l_e4b;
	case 3661ULL: goto x86_l_e4d;
	case 3666ULL: goto x86_l_e52;
	case 3670ULL: goto x86_l_e56;
	case 3675ULL: goto x86_l_e5b;
	case 3680ULL: goto x86_l_e60;
	case 3685ULL: goto x86_l_e65;
	case 3687ULL: goto x86_l_e67;
	case 3692ULL: goto x86_l_e6c;
	case 3694ULL: goto x86_l_e6e;
	case 3699ULL: goto x86_l_e73;
	case 3704ULL: goto x86_l_e78;
	case 3709ULL: goto x86_l_e7d;
	case 3712ULL: goto x86_l_e80;
	case 3714ULL: goto x86_l_e82;
	case 3719ULL: goto x86_l_e87;
	case 3724ULL: goto x86_l_e8c;
	case 3729ULL: goto x86_l_e91;
	case 3734ULL: goto x86_l_e96;
	case 3737ULL: goto x86_l_e99;
	case 3739ULL: goto x86_l_e9b;
	case 3743ULL: goto x86_l_e9f;
	case 3747ULL: goto x86_l_ea3;
	case 3751ULL: goto x86_l_ea7;
	case 3755ULL: goto x86_l_eab;
	case 3760ULL: goto x86_l_eb0;
	case 3765ULL: goto x86_l_eb5;
	case 3770ULL: goto x86_l_eba;
	case 3772ULL: goto x86_l_ebc;
	case 3776ULL: goto x86_l_ec0;
	case 3780ULL: goto x86_l_ec4;
	case 3784ULL: goto x86_l_ec8;
	case 3788ULL: goto x86_l_ecc;
	case 3795ULL: goto x86_l_ed3;
	case 3800ULL: goto x86_l_ed8;
	case 3805ULL: goto x86_l_edd;
	case 3810ULL: goto x86_l_ee2;
	case 3813ULL: goto x86_l_ee5;
	case 3815ULL: goto x86_l_ee7;
	case 3820ULL: goto x86_l_eec;
	case 3824ULL: goto x86_l_ef0;
	case 3829ULL: goto x86_l_ef5;
	case 3834ULL: goto x86_l_efa;
	case 3839ULL: goto x86_l_eff;
	case 3841ULL: goto x86_l_f01;
	case 3846ULL: goto x86_l_f06;
	case 3851ULL: goto x86_l_f0b;
	case 3856ULL: goto x86_l_f10;
	case 3861ULL: goto x86_l_f15;
	case 3863ULL: goto x86_l_f17;
	case 3867ULL: goto x86_l_f1b;
	case 3871ULL: goto x86_l_f1f;
	case 3876ULL: goto x86_l_f24;
	case 3878ULL: goto x86_l_f26;
	case 3882ULL: goto x86_l_f2a;
	case 3886ULL: goto x86_l_f2e;
	case 3891ULL: goto x86_l_f33;
	case 3896ULL: goto x86_l_f38;
	case 3901ULL: goto x86_l_f3d;
	case 3903ULL: goto x86_l_f3f;
	case 3908ULL: goto x86_l_f44;
	case 3912ULL: goto x86_l_f48;
	case 3920ULL: goto x86_l_f50;
	case 3924ULL: goto x86_l_f54;
	case 3929ULL: goto x86_l_f59;
	case 3934ULL: goto x86_l_f5e;
	case 3939ULL: goto x86_l_f63;
	case 3941ULL: goto x86_l_f65;
	case 3946ULL: goto x86_l_f6a;
	case 3950ULL: goto x86_l_f6e;
	case 3954ULL: goto x86_l_f72;
	case 3959ULL: goto x86_l_f77;
	case 3964ULL: goto x86_l_f7c;
	case 3969ULL: goto x86_l_f81;
	case 3972ULL: goto x86_l_f84;
	case 3974ULL: goto x86_l_f86;
	case 3979ULL: goto x86_l_f8b;
	case 3983ULL: goto x86_l_f8f;
	case 3988ULL: goto x86_l_f94;
	case 3993ULL: goto x86_l_f99;
	case 3998ULL: goto x86_l_f9e;
	case 4001ULL: goto x86_l_fa1;
	case 4003ULL: goto x86_l_fa3;
	case 4008ULL: goto x86_l_fa8;
	case 4010ULL: goto x86_l_faa;
	case 4015ULL: goto x86_l_faf;
	case 4019ULL: goto x86_l_fb3;
	case 4027ULL: goto x86_l_fbb;
	case 4035ULL: goto x86_l_fc3;
	case 4040ULL: goto x86_l_fc8;
	case 4045ULL: goto x86_l_fcd;
	case 4047ULL: goto x86_l_fcf;
	case 4052ULL: goto x86_l_fd4;
	case 4057ULL: goto x86_l_fd9;
	case 4062ULL: goto x86_l_fde;
	case 4065ULL: goto x86_l_fe1;
	case 4067ULL: goto x86_l_fe3;
	case 4072ULL: goto x86_l_fe8;
	case 4077ULL: goto x86_l_fed;
	case 4082ULL: goto x86_l_ff2;
	case 4087ULL: goto x86_l_ff7;
	case 4089ULL: goto x86_l_ff9;
	case 4094ULL: goto x86_l_ffe;
	case 4099ULL: goto x86_l_1003;
	case 4104ULL: goto x86_l_1008;
	case 4107ULL: goto x86_l_100b;
	case 4112ULL: goto x86_l_1010;
	case 4114ULL: goto x86_l_1012;
	case 4117ULL: goto x86_l_1015;
	case 4121ULL: goto x86_l_1019;
	case 4126ULL: goto x86_l_101e;
	case 4131ULL: goto x86_l_1023;
	case 4134ULL: goto x86_l_1026;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4146ULL: goto x86_l_1032;
	case 4151ULL: goto x86_l_1037;
	case 4154ULL: goto x86_l_103a;
	case 4156ULL: goto x86_l_103c;
	case 4161ULL: goto x86_l_1041;
	case 4165ULL: goto x86_l_1045;
	case 4173ULL: goto x86_l_104d;
	case 4175ULL: goto x86_l_104f;
	case 4180ULL: goto x86_l_1054;
	case 4187ULL: goto x86_l_105b;
	case 4192ULL: goto x86_l_1060;
	case 4195ULL: goto x86_l_1063;
	case 4197ULL: goto x86_l_1065;
	case 4199ULL: goto x86_l_1067;
	case 4201ULL: goto x86_l_1069;
	case 4205ULL: goto x86_l_106d;
	case 4213ULL: goto x86_l_1075;
	case 4218ULL: goto x86_l_107a;
	case 4223ULL: goto x86_l_107f;
	case 4226ULL: goto x86_l_1082;
	case 4232ULL: goto x86_l_1088;
	case 4236ULL: goto x86_l_108c;
	case 4241ULL: goto x86_l_1091;
	case 4248ULL: goto x86_l_1098;
	case 4253ULL: goto x86_l_109d;
	case 4256ULL: goto x86_l_10a0;
	case 4259ULL: goto x86_l_10a3;
	case 4261ULL: goto x86_l_10a5;
	case 4268ULL: goto x86_l_10ac;
	case 4270ULL: goto x86_l_10ae;
	case 4271ULL: goto x86_l_10af;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4289ULL: goto x86_l_10c1;
	case 4293ULL: goto x86_l_10c5;
	case 4300ULL: goto x86_l_10cc;
	case 4305ULL: goto x86_l_10d1;
	case 4310ULL: goto x86_l_10d6;
	case 4312ULL: goto x86_l_10d8;
	case 4317ULL: goto x86_l_10dd;
	case 4325ULL: goto x86_l_10e5;
	case 4328ULL: goto x86_l_10e8;
	case 4336ULL: goto x86_l_10f0;
	case 4345ULL: goto x86_l_10f9;
	case 4349ULL: goto x86_l_10fd;
	case 4354ULL: goto x86_l_1102;
	case 4359ULL: goto x86_l_1107;
	case 4364ULL: goto x86_l_110c;
	case 4366ULL: goto x86_l_110e;
	case 4368ULL: goto x86_l_1110;
	case 4374ULL: goto x86_l_1116;
	case 4380ULL: goto x86_l_111c;
	case 4383ULL: goto x86_l_111f;
	case 4388ULL: goto x86_l_1124;
	case 4394ULL: goto x86_l_112a;
	case 4399ULL: goto x86_l_112f;
	case 4407ULL: goto x86_l_1137;
	case 4411ULL: goto x86_l_113b;
	case 4418ULL: goto x86_l_1142;
	case 4423ULL: goto x86_l_1147;
	case 4428ULL: goto x86_l_114c;
	case 4430ULL: goto x86_l_114e;
	case 4434ULL: goto x86_l_1152;
	case 4436ULL: goto x86_l_1154;
	case 4438ULL: goto x86_l_1156;
	case 4444ULL: goto x86_l_115c;
	case 4447ULL: goto x86_l_115f;
	case 4452ULL: goto x86_l_1164;
	case 4458ULL: goto x86_l_116a;
	case 4463ULL: goto x86_l_116f;
	case 4471ULL: goto x86_l_1177;
	case 4475ULL: goto x86_l_117b;
	case 4482ULL: goto x86_l_1182;
	case 4487ULL: goto x86_l_1187;
	case 4492ULL: goto x86_l_118c;
	case 4494ULL: goto x86_l_118e;
	case 4499ULL: goto x86_l_1193;
	case 4507ULL: goto x86_l_119b;
	case 4510ULL: goto x86_l_119e;
	case 4518ULL: goto x86_l_11a6;
	case 4527ULL: goto x86_l_11af;
	case 4531ULL: goto x86_l_11b3;
	case 4536ULL: goto x86_l_11b8;
	case 4541ULL: goto x86_l_11bd;
	case 4546ULL: goto x86_l_11c2;
	case 4548ULL: goto x86_l_11c4;
	case 4550ULL: goto x86_l_11c6;
	case 4556ULL: goto x86_l_11cc;
	case 4562ULL: goto x86_l_11d2;
	case 4565ULL: goto x86_l_11d5;
	case 4570ULL: goto x86_l_11da;
	case 4576ULL: goto x86_l_11e0;
	case 4581ULL: goto x86_l_11e5;
	case 4589ULL: goto x86_l_11ed;
	case 4593ULL: goto x86_l_11f1;
	case 4600ULL: goto x86_l_11f8;
	case 4605ULL: goto x86_l_11fd;
	case 4610ULL: goto x86_l_1202;
	case 4612ULL: goto x86_l_1204;
	case 4616ULL: goto x86_l_1208;
	case 4618ULL: goto x86_l_120a;
	case 4620ULL: goto x86_l_120c;
	case 4626ULL: goto x86_l_1212;
	case 4629ULL: goto x86_l_1215;
	case 4634ULL: goto x86_l_121a;
	case 4640ULL: goto x86_l_1220;
	case 4645ULL: goto x86_l_1225;
	case 4653ULL: goto x86_l_122d;
	case 4657ULL: goto x86_l_1231;
	case 4664ULL: goto x86_l_1238;
	case 4669ULL: goto x86_l_123d;
	case 4674ULL: goto x86_l_1242;
	case 4676ULL: goto x86_l_1244;
	case 4681ULL: goto x86_l_1249;
	case 4689ULL: goto x86_l_1251;
	case 4692ULL: goto x86_l_1254;
	case 4700ULL: goto x86_l_125c;
	case 4709ULL: goto x86_l_1265;
	case 4713ULL: goto x86_l_1269;
	case 4718ULL: goto x86_l_126e;
	case 4723ULL: goto x86_l_1273;
	case 4728ULL: goto x86_l_1278;
	case 4730ULL: goto x86_l_127a;
	case 4732ULL: goto x86_l_127c;
	case 4738ULL: goto x86_l_1282;
	case 4744ULL: goto x86_l_1288;
	case 4747ULL: goto x86_l_128b;
	case 4752ULL: goto x86_l_1290;
	case 4758ULL: goto x86_l_1296;
	case 4763ULL: goto x86_l_129b;
	case 4771ULL: goto x86_l_12a3;
	case 4775ULL: goto x86_l_12a7;
	case 4782ULL: goto x86_l_12ae;
	case 4787ULL: goto x86_l_12b3;
	case 4792ULL: goto x86_l_12b8;
	case 4794ULL: goto x86_l_12ba;
	case 4798ULL: goto x86_l_12be;
	case 4800ULL: goto x86_l_12c0;
	case 4802ULL: goto x86_l_12c2;
	case 4808ULL: goto x86_l_12c8;
	case 4811ULL: goto x86_l_12cb;
	case 4816ULL: goto x86_l_12d0;
	case 4822ULL: goto x86_l_12d6;
	case 4827ULL: goto x86_l_12db;
	case 4835ULL: goto x86_l_12e3;
	case 4839ULL: goto x86_l_12e7;
	case 4846ULL: goto x86_l_12ee;
	case 4851ULL: goto x86_l_12f3;
	case 4856ULL: goto x86_l_12f8;
	case 4858ULL: goto x86_l_12fa;
	case 4863ULL: goto x86_l_12ff;
	case 4871ULL: goto x86_l_1307;
	case 4874ULL: goto x86_l_130a;
	case 4882ULL: goto x86_l_1312;
	case 4891ULL: goto x86_l_131b;
	case 4895ULL: goto x86_l_131f;
	case 4900ULL: goto x86_l_1324;
	case 4905ULL: goto x86_l_1329;
	case 4910ULL: goto x86_l_132e;
	case 4912ULL: goto x86_l_1330;
	case 4914ULL: goto x86_l_1332;
	case 4920ULL: goto x86_l_1338;
	case 4926ULL: goto x86_l_133e;
	case 4929ULL: goto x86_l_1341;
	case 4934ULL: goto x86_l_1346;
	case 4940ULL: goto x86_l_134c;
	case 4945ULL: goto x86_l_1351;
	case 4953ULL: goto x86_l_1359;
	case 4957ULL: goto x86_l_135d;
	case 4964ULL: goto x86_l_1364;
	case 4969ULL: goto x86_l_1369;
	case 4974ULL: goto x86_l_136e;
	case 4976ULL: goto x86_l_1370;
	case 4980ULL: goto x86_l_1374;
	case 4982ULL: goto x86_l_1376;
	case 4984ULL: goto x86_l_1378;
	case 4990ULL: goto x86_l_137e;
	case 4993ULL: goto x86_l_1381;
	case 4998ULL: goto x86_l_1386;
	case 5004ULL: goto x86_l_138c;
	case 5009ULL: goto x86_l_1391;
	case 5017ULL: goto x86_l_1399;
	case 5021ULL: goto x86_l_139d;
	case 5028ULL: goto x86_l_13a4;
	case 5033ULL: goto x86_l_13a9;
	case 5038ULL: goto x86_l_13ae;
	case 5040ULL: goto x86_l_13b0;
	case 5045ULL: goto x86_l_13b5;
	case 5053ULL: goto x86_l_13bd;
	case 5056ULL: goto x86_l_13c0;
	case 5064ULL: goto x86_l_13c8;
	case 5073ULL: goto x86_l_13d1;
	case 5077ULL: goto x86_l_13d5;
	case 5082ULL: goto x86_l_13da;
	case 5087ULL: goto x86_l_13df;
	case 5092ULL: goto x86_l_13e4;
	case 5094ULL: goto x86_l_13e6;
	case 5096ULL: goto x86_l_13e8;
	case 5102ULL: goto x86_l_13ee;
	case 5108ULL: goto x86_l_13f4;
	case 5111ULL: goto x86_l_13f7;
	case 5116ULL: goto x86_l_13fc;
	case 5122ULL: goto x86_l_1402;
	case 5127ULL: goto x86_l_1407;
	case 5135ULL: goto x86_l_140f;
	case 5139ULL: goto x86_l_1413;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d45:
	/* 0xd45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d4a:
	/* 0xd4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4c:
	/* 0xd4c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d51:
	/* 0xd51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d56:
	/* 0xd56: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d5b:
	/* 0xd5b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d60:
	/* 0xd60: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d63:
	/* 0xd63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d65:
	/* 0xd65: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d69:
	/* 0xd69: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_d6d:
	/* 0xd6d: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_d71:
	/* 0xd71: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d75:
	/* 0xd75: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d7a:
	/* 0xd7a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d7f:
	/* 0xd7f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d84:
	/* 0xd84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d86:
	/* 0xd86: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d8a:
	/* 0xd8a: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d8e:
	/* 0xd8e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d93:
	/* 0xd93: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d98:
	/* 0xd98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d9d:
	/* 0xd9d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_da0:
	/* 0xda0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da2:
	/* 0xda2: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_da7:
	/* 0xda7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dac:
	/* 0xdac: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db1:
	/* 0xdb1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_db6:
	/* 0xdb6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_db9:
	/* 0xdb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dbb:
	/* 0xdbb: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dbf:
	/* 0xdbf: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_dc3:
	/* 0xdc3: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_dc7:
	/* 0xdc7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_dcb:
	/* 0xdcb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dd0:
	/* 0xdd0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dd5:
	/* 0xdd5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dda:
	/* 0xdda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ddc:
	/* 0xddc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de1:
	/* 0xde1: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_de5:
	/* 0xde5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dea:
	/* 0xdea: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_def:
	/* 0xdef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_df4:
	/* 0xdf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df6:
	/* 0xdf6: mov    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dfb:
	/* 0xdfb: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dff:
	/* 0xdff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e04:
	/* 0xe04: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e09:
	/* 0xe09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e0e:
	/* 0xe0e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e11:
	/* 0xe11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e13:
	/* 0xe13: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e18:
	/* 0xe18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e1d:
	/* 0xe1d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e22:
	/* 0xe22: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e27:
	/* 0xe27: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e2a:
	/* 0xe2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2c:
	/* 0xe2c: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e30:
	/* 0xe30: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_e34:
	/* 0xe34: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_e38:
	/* 0xe38: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e3c:
	/* 0xe3c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e41:
	/* 0xe41: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e46:
	/* 0xe46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e4b:
	/* 0xe4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4d:
	/* 0xe4d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e52:
	/* 0xe52: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_e56:
	/* 0xe56: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e5b:
	/* 0xe5b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e60:
	/* 0xe60: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e65:
	/* 0xe65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e67:
	/* 0xe67: cmp    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_e6c:
	/* 0xe6c: jne    ec4 <syscall__execve_exit+0xec4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ec4;
	}
x86_l_e6e:
	/* 0xe6e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e73:
	/* 0xe73: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e78:
	/* 0xe78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e7d:
	/* 0xe7d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e80:
	/* 0xe80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e82:
	/* 0xe82: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e87:
	/* 0xe87: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e8c:
	/* 0xe8c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e91:
	/* 0xe91: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e96:
	/* 0xe96: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e99:
	/* 0xe99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e9b:
	/* 0xe9b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e9f:
	/* 0xe9f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_ea3:
	/* 0xea3: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ea7:
	/* 0xea7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_eab:
	/* 0xeab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eb0:
	/* 0xeb0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb5:
	/* 0xeb5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_eba:
	/* 0xeba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ebc:
	/* 0xebc: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ec0:
	/* 0xec0: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ec4:
	/* 0xec4: lea    r15,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ec8:
	/* 0xec8: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ecc:
	/* 0xecc: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ed3:
	/* 0xed3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ed8:
	/* 0xed8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_edd:
	/* 0xedd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ee2:
	/* 0xee2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ee5:
	/* 0xee5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee7:
	/* 0xee7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eec:
	/* 0xeec: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ef0:
	/* 0xef0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ef5:
	/* 0xef5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_efa:
	/* 0xefa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_eff:
	/* 0xeff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f01:
	/* 0xf01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f06:
	/* 0xf06: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f0b:
	/* 0xf0b: lea    rdi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f10:
	/* 0xf10: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f15:
	/* 0xf15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f17:
	/* 0xf17: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f1b:
	/* 0xf1b: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_f1f:
	/* 0xf1f: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_f24:
	/* 0xf24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f26:
	/* 0xf26: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f2a:
	/* 0xf2a: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f2e:
	/* 0xf2e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f33:
	/* 0xf33: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f38:
	/* 0xf38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f3d:
	/* 0xf3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3f:
	/* 0xf3f: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f44:
	/* 0xf44: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f48:
	/* 0xf48: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_f50:
	/* 0xf50: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_f54:
	/* 0xf54: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f59:
	/* 0xf59: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f5e:
	/* 0xf5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f63:
	/* 0xf63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f65:
	/* 0xf65: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f6a:
	/* 0xf6a: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f6e:
	/* 0xf6e: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_f72:
	/* 0xf72: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f77:
	/* 0xf77: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f7c:
	/* 0xf7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f81:
	/* 0xf81: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_f84:
	/* 0xf84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f86:
	/* 0xf86: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f8b:
	/* 0xf8b: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f8f:
	/* 0xf8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f94:
	/* 0xf94: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f99:
	/* 0xf99: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f9e:
	/* 0xf9e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_fa1:
	/* 0xfa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa3:
	/* 0xfa3: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_fa8:
	/* 0xfa8: je     faf <syscall__execve_exit+0xfaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_faf;
	}
x86_l_faa:
	/* 0xfaa: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_faf:
	/* 0xfaf: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_fb3:
	/* 0xfb3: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_fbb:
	/* 0xfbb: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_fc3:
	/* 0xfc3: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_fc8:
	/* 0xfc8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_fcd:
	/* 0xfcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fcf:
	/* 0xfcf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fd4:
	/* 0xfd4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fd9:
	/* 0xfd9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fde:
	/* 0xfde: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_fe1:
	/* 0xfe1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe3:
	/* 0xfe3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe8:
	/* 0xfe8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fed:
	/* 0xfed: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ff2:
	/* 0xff2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ff7:
	/* 0xff7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff9:
	/* 0xff9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ffe:
	/* 0xffe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1003:
	/* 0x1003: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1008:
	/* 0x1008: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_100b:
	/* 0x100b: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1010:
	/* 0x1010: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1012:
	/* 0x1012: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1015:
	/* 0x1015: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1019:
	/* 0x1019: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_101e:
	/* 0x101e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1023:
	/* 0x1023: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1026:
	/* 0x1026: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1028:
	/* 0x1028: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_102d:
	/* 0x102d: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1032:
	/* 0x1032: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_1037:
	/* 0x1037: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_103a:
	/* 0x103a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_103c:
	/* 0x103c: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1041:
	/* 0x1041: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_1045:
	/* 0x1045: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_104d:
	/* 0x104d: je     106d <syscall__execve_exit+0x106d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106d;
	}
x86_l_104f:
	/* 0x104f: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1054:
	/* 0x1054: mov    rsi,QWORD PTR [rip+0x4757] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_105b:
	/* 0x105b: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1060:
	/* 0x1060: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1063:
	/* 0x1063: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1065:
	/* 0x1065: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1067:
	/* 0x1067: js     106d <syscall__execve_exit+0x106d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_106d;
	}
x86_l_1069:
	/* 0x1069: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_106d:
	/* 0x106d: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1075:
	/* 0x1075: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_107a:
	/* 0x107a: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_107f:
	/* 0x107f: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1082:
	/* 0x1082: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_1088:
	/* 0x1088: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_108c:
	/* 0x108c: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1091:
	/* 0x1091: mov    rsi,QWORD PTR [rip+0x4757] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_1098:
	/* 0x1098: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_109d:
	/* 0x109d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10a0:
	/* 0x10a0: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_10a3:
	/* 0x10a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a5:
	/* 0x10a5: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_10ac:
	/* 0x10ac: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_10ae:
	/* 0x10ae: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_10af:
	/* 0x10af: jmp    4791 <syscall__execve_exit+0x4791> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_10b4:
	/* 0x10b4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10b9:
	/* 0x10b9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_10c1:
	/* 0x10c1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_10c5:
	/* 0x10c5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_10cc:
	/* 0x10cc: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_10d1:
	/* 0x10d1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10d6:
	/* 0x10d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d8:
	/* 0x10d8: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_10dd:
	/* 0x10dd: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_10e5:
	/* 0x10e5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_10e8:
	/* 0x10e8: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_10f0:
	/* 0x10f0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10f9:
	/* 0x10f9: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10fd:
	/* 0x10fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1102:
	/* 0x1102: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1107:
	/* 0x1107: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_110c:
	/* 0x110c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_110e:
	/* 0x110e: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1110:
	/* 0x1110: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1116:
	/* 0x1116: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_111c:
	/* 0x111c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_111f:
	/* 0x111f: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1124:
	/* 0x1124: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_112a:
	/* 0x112a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_112f:
	/* 0x112f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1137:
	/* 0x1137: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_113b:
	/* 0x113b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1142:
	/* 0x1142: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1147:
	/* 0x1147: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_114c:
	/* 0x114c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_114e:
	/* 0x114e: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1152:
	/* 0x1152: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1154:
	/* 0x1154: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1156:
	/* 0x1156: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_115c:
	/* 0x115c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_115f:
	/* 0x115f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1164:
	/* 0x1164: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_116a:
	/* 0x116a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_116f:
	/* 0x116f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1177:
	/* 0x1177: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_117b:
	/* 0x117b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1182:
	/* 0x1182: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1187:
	/* 0x1187: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_118c:
	/* 0x118c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118e:
	/* 0x118e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1193:
	/* 0x1193: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_119b:
	/* 0x119b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_119e:
	/* 0x119e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_11a6:
	/* 0x11a6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_11af:
	/* 0x11af: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11b3:
	/* 0x11b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11b8:
	/* 0x11b8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11bd:
	/* 0x11bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11c2:
	/* 0x11c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c4:
	/* 0x11c4: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_11c6:
	/* 0x11c6: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_11cc:
	/* 0x11cc: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_11d2:
	/* 0x11d2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_11d5:
	/* 0x11d5: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_11da:
	/* 0x11da: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_11e0:
	/* 0x11e0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_11e5:
	/* 0x11e5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_11ed:
	/* 0x11ed: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_11f1:
	/* 0x11f1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_11f8:
	/* 0x11f8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11fd:
	/* 0x11fd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1202:
	/* 0x1202: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1204:
	/* 0x1204: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1208:
	/* 0x1208: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_120a:
	/* 0x120a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_120c:
	/* 0x120c: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1212:
	/* 0x1212: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1215:
	/* 0x1215: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_121a:
	/* 0x121a: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1220:
	/* 0x1220: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1225:
	/* 0x1225: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_122d:
	/* 0x122d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1231:
	/* 0x1231: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1238:
	/* 0x1238: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_123d:
	/* 0x123d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1242:
	/* 0x1242: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1244:
	/* 0x1244: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1249:
	/* 0x1249: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1251:
	/* 0x1251: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1254:
	/* 0x1254: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_125c:
	/* 0x125c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1265:
	/* 0x1265: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1269:
	/* 0x1269: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_126e:
	/* 0x126e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1273:
	/* 0x1273: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1278:
	/* 0x1278: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127a:
	/* 0x127a: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_127c:
	/* 0x127c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1282:
	/* 0x1282: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1288:
	/* 0x1288: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_128b:
	/* 0x128b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1290:
	/* 0x1290: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1296:
	/* 0x1296: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_129b:
	/* 0x129b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_12a3:
	/* 0x12a3: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_12a7:
	/* 0x12a7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_12ae:
	/* 0x12ae: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12b3:
	/* 0x12b3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_12b8:
	/* 0x12b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ba:
	/* 0x12ba: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_12be:
	/* 0x12be: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_12c0:
	/* 0x12c0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12c2:
	/* 0x12c2: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_12c8:
	/* 0x12c8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12cb:
	/* 0x12cb: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_12d0:
	/* 0x12d0: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_12d6:
	/* 0x12d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12db:
	/* 0x12db: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_12e3:
	/* 0x12e3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_12e7:
	/* 0x12e7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_12ee:
	/* 0x12ee: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_12f3:
	/* 0x12f3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12f8:
	/* 0x12f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12fa:
	/* 0x12fa: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_12ff:
	/* 0x12ff: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1307:
	/* 0x1307: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_130a:
	/* 0x130a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1312:
	/* 0x1312: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_131b:
	/* 0x131b: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_131f:
	/* 0x131f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1324:
	/* 0x1324: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1329:
	/* 0x1329: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_132e:
	/* 0x132e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1330:
	/* 0x1330: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_1332:
	/* 0x1332: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1338:
	/* 0x1338: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_133e:
	/* 0x133e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1341:
	/* 0x1341: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1346:
	/* 0x1346: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_134c:
	/* 0x134c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1351:
	/* 0x1351: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1359:
	/* 0x1359: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_135d:
	/* 0x135d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1364:
	/* 0x1364: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1369:
	/* 0x1369: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_136e:
	/* 0x136e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1370:
	/* 0x1370: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1374:
	/* 0x1374: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_1376:
	/* 0x1376: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1378:
	/* 0x1378: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_137e:
	/* 0x137e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1381:
	/* 0x1381: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1386:
	/* 0x1386: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_138c:
	/* 0x138c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1391:
	/* 0x1391: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1399:
	/* 0x1399: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_139d:
	/* 0x139d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_13a4:
	/* 0x13a4: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_13a9:
	/* 0x13a9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13ae:
	/* 0x13ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b0:
	/* 0x13b0: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_13b5:
	/* 0x13b5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_13bd:
	/* 0x13bd: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_13c0:
	/* 0x13c0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_13c8:
	/* 0x13c8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_13d1:
	/* 0x13d1: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13d5:
	/* 0x13d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13da:
	/* 0x13da: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13df:
	/* 0x13df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13e4:
	/* 0x13e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e6:
	/* 0x13e6: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_13e8:
	/* 0x13e8: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_13ee:
	/* 0x13ee: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_13f4:
	/* 0x13f4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_13f7:
	/* 0x13f7: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_13fc:
	/* 0x13fc: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1402:
	/* 0x1402: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1407:
	/* 0x1407: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_140f:
	/* 0x140f: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1413:
	/* 0x1413: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
	return 5146ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5146ULL: goto x86_l_141a;
	case 5151ULL: goto x86_l_141f;
	case 5156ULL: goto x86_l_1424;
	case 5158ULL: goto x86_l_1426;
	case 5162ULL: goto x86_l_142a;
	case 5164ULL: goto x86_l_142c;
	case 5166ULL: goto x86_l_142e;
	case 5172ULL: goto x86_l_1434;
	case 5175ULL: goto x86_l_1437;
	case 5180ULL: goto x86_l_143c;
	case 5186ULL: goto x86_l_1442;
	case 5191ULL: goto x86_l_1447;
	case 5199ULL: goto x86_l_144f;
	case 5203ULL: goto x86_l_1453;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5220ULL: goto x86_l_1464;
	case 5222ULL: goto x86_l_1466;
	case 5227ULL: goto x86_l_146b;
	case 5235ULL: goto x86_l_1473;
	case 5238ULL: goto x86_l_1476;
	case 5246ULL: goto x86_l_147e;
	case 5255ULL: goto x86_l_1487;
	case 5259ULL: goto x86_l_148b;
	case 5264ULL: goto x86_l_1490;
	case 5269ULL: goto x86_l_1495;
	case 5274ULL: goto x86_l_149a;
	case 5276ULL: goto x86_l_149c;
	case 5278ULL: goto x86_l_149e;
	case 5284ULL: goto x86_l_14a4;
	case 5290ULL: goto x86_l_14aa;
	case 5293ULL: goto x86_l_14ad;
	case 5298ULL: goto x86_l_14b2;
	case 5304ULL: goto x86_l_14b8;
	case 5309ULL: goto x86_l_14bd;
	case 5317ULL: goto x86_l_14c5;
	case 5321ULL: goto x86_l_14c9;
	case 5328ULL: goto x86_l_14d0;
	case 5333ULL: goto x86_l_14d5;
	case 5338ULL: goto x86_l_14da;
	case 5340ULL: goto x86_l_14dc;
	case 5344ULL: goto x86_l_14e0;
	case 5346ULL: goto x86_l_14e2;
	case 5348ULL: goto x86_l_14e4;
	case 5354ULL: goto x86_l_14ea;
	case 5357ULL: goto x86_l_14ed;
	case 5362ULL: goto x86_l_14f2;
	case 5368ULL: goto x86_l_14f8;
	case 5373ULL: goto x86_l_14fd;
	case 5381ULL: goto x86_l_1505;
	case 5385ULL: goto x86_l_1509;
	case 5392ULL: goto x86_l_1510;
	case 5397ULL: goto x86_l_1515;
	case 5402ULL: goto x86_l_151a;
	case 5404ULL: goto x86_l_151c;
	case 5409ULL: goto x86_l_1521;
	case 5417ULL: goto x86_l_1529;
	case 5420ULL: goto x86_l_152c;
	case 5428ULL: goto x86_l_1534;
	case 5437ULL: goto x86_l_153d;
	case 5441ULL: goto x86_l_1541;
	case 5446ULL: goto x86_l_1546;
	case 5451ULL: goto x86_l_154b;
	case 5456ULL: goto x86_l_1550;
	case 5458ULL: goto x86_l_1552;
	case 5460ULL: goto x86_l_1554;
	case 5466ULL: goto x86_l_155a;
	case 5472ULL: goto x86_l_1560;
	case 5475ULL: goto x86_l_1563;
	case 5480ULL: goto x86_l_1568;
	case 5486ULL: goto x86_l_156e;
	case 5491ULL: goto x86_l_1573;
	case 5499ULL: goto x86_l_157b;
	case 5503ULL: goto x86_l_157f;
	case 5510ULL: goto x86_l_1586;
	case 5515ULL: goto x86_l_158b;
	case 5520ULL: goto x86_l_1590;
	case 5522ULL: goto x86_l_1592;
	case 5526ULL: goto x86_l_1596;
	case 5528ULL: goto x86_l_1598;
	case 5530ULL: goto x86_l_159a;
	case 5536ULL: goto x86_l_15a0;
	case 5539ULL: goto x86_l_15a3;
	case 5544ULL: goto x86_l_15a8;
	case 5550ULL: goto x86_l_15ae;
	case 5555ULL: goto x86_l_15b3;
	case 5563ULL: goto x86_l_15bb;
	case 5567ULL: goto x86_l_15bf;
	case 5574ULL: goto x86_l_15c6;
	case 5579ULL: goto x86_l_15cb;
	case 5584ULL: goto x86_l_15d0;
	case 5586ULL: goto x86_l_15d2;
	case 5591ULL: goto x86_l_15d7;
	case 5599ULL: goto x86_l_15df;
	case 5602ULL: goto x86_l_15e2;
	case 5610ULL: goto x86_l_15ea;
	case 5619ULL: goto x86_l_15f3;
	case 5623ULL: goto x86_l_15f7;
	case 5628ULL: goto x86_l_15fc;
	case 5633ULL: goto x86_l_1601;
	case 5638ULL: goto x86_l_1606;
	case 5640ULL: goto x86_l_1608;
	case 5642ULL: goto x86_l_160a;
	case 5648ULL: goto x86_l_1610;
	case 5654ULL: goto x86_l_1616;
	case 5657ULL: goto x86_l_1619;
	case 5662ULL: goto x86_l_161e;
	case 5668ULL: goto x86_l_1624;
	case 5673ULL: goto x86_l_1629;
	case 5681ULL: goto x86_l_1631;
	case 5685ULL: goto x86_l_1635;
	case 5692ULL: goto x86_l_163c;
	case 5697ULL: goto x86_l_1641;
	case 5702ULL: goto x86_l_1646;
	case 5704ULL: goto x86_l_1648;
	case 5708ULL: goto x86_l_164c;
	case 5710ULL: goto x86_l_164e;
	case 5712ULL: goto x86_l_1650;
	case 5718ULL: goto x86_l_1656;
	case 5721ULL: goto x86_l_1659;
	case 5726ULL: goto x86_l_165e;
	case 5732ULL: goto x86_l_1664;
	case 5737ULL: goto x86_l_1669;
	case 5745ULL: goto x86_l_1671;
	case 5749ULL: goto x86_l_1675;
	case 5756ULL: goto x86_l_167c;
	case 5761ULL: goto x86_l_1681;
	case 5766ULL: goto x86_l_1686;
	case 5768ULL: goto x86_l_1688;
	case 5773ULL: goto x86_l_168d;
	case 5781ULL: goto x86_l_1695;
	case 5784ULL: goto x86_l_1698;
	case 5792ULL: goto x86_l_16a0;
	case 5801ULL: goto x86_l_16a9;
	case 5805ULL: goto x86_l_16ad;
	case 5810ULL: goto x86_l_16b2;
	case 5815ULL: goto x86_l_16b7;
	case 5820ULL: goto x86_l_16bc;
	case 5822ULL: goto x86_l_16be;
	case 5824ULL: goto x86_l_16c0;
	case 5830ULL: goto x86_l_16c6;
	case 5836ULL: goto x86_l_16cc;
	case 5839ULL: goto x86_l_16cf;
	case 5844ULL: goto x86_l_16d4;
	case 5850ULL: goto x86_l_16da;
	case 5855ULL: goto x86_l_16df;
	case 5863ULL: goto x86_l_16e7;
	case 5867ULL: goto x86_l_16eb;
	case 5874ULL: goto x86_l_16f2;
	case 5879ULL: goto x86_l_16f7;
	case 5884ULL: goto x86_l_16fc;
	case 5886ULL: goto x86_l_16fe;
	case 5890ULL: goto x86_l_1702;
	case 5892ULL: goto x86_l_1704;
	case 5894ULL: goto x86_l_1706;
	case 5900ULL: goto x86_l_170c;
	case 5903ULL: goto x86_l_170f;
	case 5908ULL: goto x86_l_1714;
	case 5914ULL: goto x86_l_171a;
	case 5919ULL: goto x86_l_171f;
	case 5927ULL: goto x86_l_1727;
	case 5931ULL: goto x86_l_172b;
	case 5938ULL: goto x86_l_1732;
	case 5943ULL: goto x86_l_1737;
	case 5948ULL: goto x86_l_173c;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5963ULL: goto x86_l_174b;
	case 5966ULL: goto x86_l_174e;
	case 5974ULL: goto x86_l_1756;
	case 5983ULL: goto x86_l_175f;
	case 5987ULL: goto x86_l_1763;
	case 5992ULL: goto x86_l_1768;
	case 5997ULL: goto x86_l_176d;
	case 6002ULL: goto x86_l_1772;
	case 6004ULL: goto x86_l_1774;
	case 6006ULL: goto x86_l_1776;
	case 6012ULL: goto x86_l_177c;
	case 6018ULL: goto x86_l_1782;
	case 6021ULL: goto x86_l_1785;
	case 6026ULL: goto x86_l_178a;
	case 6032ULL: goto x86_l_1790;
	case 6037ULL: goto x86_l_1795;
	case 6045ULL: goto x86_l_179d;
	case 6049ULL: goto x86_l_17a1;
	case 6056ULL: goto x86_l_17a8;
	case 6061ULL: goto x86_l_17ad;
	case 6066ULL: goto x86_l_17b2;
	case 6068ULL: goto x86_l_17b4;
	case 6072ULL: goto x86_l_17b8;
	case 6074ULL: goto x86_l_17ba;
	case 6076ULL: goto x86_l_17bc;
	case 6082ULL: goto x86_l_17c2;
	case 6085ULL: goto x86_l_17c5;
	case 6090ULL: goto x86_l_17ca;
	case 6096ULL: goto x86_l_17d0;
	case 6101ULL: goto x86_l_17d5;
	case 6109ULL: goto x86_l_17dd;
	case 6113ULL: goto x86_l_17e1;
	case 6120ULL: goto x86_l_17e8;
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
	case 6186ULL: goto x86_l_182a;
	case 6188ULL: goto x86_l_182c;
	case 6194ULL: goto x86_l_1832;
	case 6200ULL: goto x86_l_1838;
	case 6203ULL: goto x86_l_183b;
	case 6208ULL: goto x86_l_1840;
	case 6214ULL: goto x86_l_1846;
	case 6219ULL: goto x86_l_184b;
	case 6227ULL: goto x86_l_1853;
	case 6231ULL: goto x86_l_1857;
	case 6238ULL: goto x86_l_185e;
	case 6243ULL: goto x86_l_1863;
	case 6248ULL: goto x86_l_1868;
	case 6250ULL: goto x86_l_186a;
	case 6254ULL: goto x86_l_186e;
	case 6256ULL: goto x86_l_1870;
	case 6258ULL: goto x86_l_1872;
	case 6264ULL: goto x86_l_1878;
	case 6267ULL: goto x86_l_187b;
	case 6272ULL: goto x86_l_1880;
	case 6278ULL: goto x86_l_1886;
	case 6283ULL: goto x86_l_188b;
	case 6291ULL: goto x86_l_1893;
	case 6295ULL: goto x86_l_1897;
	case 6302ULL: goto x86_l_189e;
	case 6307ULL: goto x86_l_18a3;
	case 6312ULL: goto x86_l_18a8;
	case 6314ULL: goto x86_l_18aa;
	case 6319ULL: goto x86_l_18af;
	case 6327ULL: goto x86_l_18b7;
	case 6330ULL: goto x86_l_18ba;
	case 6338ULL: goto x86_l_18c2;
	case 6347ULL: goto x86_l_18cb;
	case 6351ULL: goto x86_l_18cf;
	case 6356ULL: goto x86_l_18d4;
	case 6361ULL: goto x86_l_18d9;
	case 6366ULL: goto x86_l_18de;
	case 6368ULL: goto x86_l_18e0;
	case 6370ULL: goto x86_l_18e2;
	case 6376ULL: goto x86_l_18e8;
	case 6382ULL: goto x86_l_18ee;
	case 6385ULL: goto x86_l_18f1;
	case 6390ULL: goto x86_l_18f6;
	case 6396ULL: goto x86_l_18fc;
	case 6401ULL: goto x86_l_1901;
	case 6409ULL: goto x86_l_1909;
	case 6413ULL: goto x86_l_190d;
	case 6420ULL: goto x86_l_1914;
	case 6425ULL: goto x86_l_1919;
	case 6430ULL: goto x86_l_191e;
	case 6432ULL: goto x86_l_1920;
	case 6436ULL: goto x86_l_1924;
	case 6438ULL: goto x86_l_1926;
	case 6440ULL: goto x86_l_1928;
	case 6446ULL: goto x86_l_192e;
	case 6449ULL: goto x86_l_1931;
	case 6454ULL: goto x86_l_1936;
	case 6460ULL: goto x86_l_193c;
	case 6465ULL: goto x86_l_1941;
	case 6473ULL: goto x86_l_1949;
	case 6477ULL: goto x86_l_194d;
	case 6484ULL: goto x86_l_1954;
	case 6489ULL: goto x86_l_1959;
	case 6494ULL: goto x86_l_195e;
	case 6496ULL: goto x86_l_1960;
	case 6501ULL: goto x86_l_1965;
	case 6509ULL: goto x86_l_196d;
	case 6512ULL: goto x86_l_1970;
	case 6520ULL: goto x86_l_1978;
	case 6529ULL: goto x86_l_1981;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6543ULL: goto x86_l_198f;
	case 6548ULL: goto x86_l_1994;
	case 6550ULL: goto x86_l_1996;
	case 6552ULL: goto x86_l_1998;
	case 6558ULL: goto x86_l_199e;
	case 6564ULL: goto x86_l_19a4;
	case 6567ULL: goto x86_l_19a7;
	case 6572ULL: goto x86_l_19ac;
	case 6578ULL: goto x86_l_19b2;
	case 6583ULL: goto x86_l_19b7;
	case 6591ULL: goto x86_l_19bf;
	case 6595ULL: goto x86_l_19c3;
	case 6602ULL: goto x86_l_19ca;
	case 6607ULL: goto x86_l_19cf;
	case 6612ULL: goto x86_l_19d4;
	case 6614ULL: goto x86_l_19d6;
	case 6618ULL: goto x86_l_19da;
	case 6620ULL: goto x86_l_19dc;
	case 6622ULL: goto x86_l_19de;
	case 6628ULL: goto x86_l_19e4;
	case 6631ULL: goto x86_l_19e7;
	case 6636ULL: goto x86_l_19ec;
	case 6642ULL: goto x86_l_19f2;
	case 6647ULL: goto x86_l_19f7;
	case 6655ULL: goto x86_l_19ff;
	case 6659ULL: goto x86_l_1a03;
	case 6666ULL: goto x86_l_1a0a;
	case 6671ULL: goto x86_l_1a0f;
	case 6676ULL: goto x86_l_1a14;
	case 6678ULL: goto x86_l_1a16;
	case 6683ULL: goto x86_l_1a1b;
	case 6691ULL: goto x86_l_1a23;
	case 6694ULL: goto x86_l_1a26;
	case 6702ULL: goto x86_l_1a2e;
	case 6711ULL: goto x86_l_1a37;
	case 6715ULL: goto x86_l_1a3b;
	case 6720ULL: goto x86_l_1a40;
	case 6725ULL: goto x86_l_1a45;
	case 6730ULL: goto x86_l_1a4a;
	case 6732ULL: goto x86_l_1a4c;
	case 6734ULL: goto x86_l_1a4e;
	case 6740ULL: goto x86_l_1a54;
	case 6746ULL: goto x86_l_1a5a;
	case 6749ULL: goto x86_l_1a5d;
	case 6754ULL: goto x86_l_1a62;
	case 6760ULL: goto x86_l_1a68;
	case 6765ULL: goto x86_l_1a6d;
	case 6773ULL: goto x86_l_1a75;
	case 6777ULL: goto x86_l_1a79;
	case 6784ULL: goto x86_l_1a80;
	case 6789ULL: goto x86_l_1a85;
	case 6794ULL: goto x86_l_1a8a;
	case 6796ULL: goto x86_l_1a8c;
	case 6800ULL: goto x86_l_1a90;
	case 6802ULL: goto x86_l_1a92;
	case 6804ULL: goto x86_l_1a94;
	case 6810ULL: goto x86_l_1a9a;
	case 6813ULL: goto x86_l_1a9d;
	case 6818ULL: goto x86_l_1aa2;
	case 6824ULL: goto x86_l_1aa8;
	case 6829ULL: goto x86_l_1aad;
	case 6837ULL: goto x86_l_1ab5;
	case 6841ULL: goto x86_l_1ab9;
	case 6848ULL: goto x86_l_1ac0;
	case 6853ULL: goto x86_l_1ac5;
	case 6858ULL: goto x86_l_1aca;
	case 6860ULL: goto x86_l_1acc;
	case 6865ULL: goto x86_l_1ad1;
	case 6873ULL: goto x86_l_1ad9;
	case 6876ULL: goto x86_l_1adc;
	case 6884ULL: goto x86_l_1ae4;
	case 6893ULL: goto x86_l_1aed;
	case 6897ULL: goto x86_l_1af1;
	case 6902ULL: goto x86_l_1af6;
	case 6907ULL: goto x86_l_1afb;
	case 6912ULL: goto x86_l_1b00;
	case 6914ULL: goto x86_l_1b02;
	case 6916ULL: goto x86_l_1b04;
	case 6922ULL: goto x86_l_1b0a;
	case 6928ULL: goto x86_l_1b10;
	case 6931ULL: goto x86_l_1b13;
	case 6936ULL: goto x86_l_1b18;
	case 6942ULL: goto x86_l_1b1e;
	case 6947ULL: goto x86_l_1b23;
	case 6955ULL: goto x86_l_1b2b;
	case 6959ULL: goto x86_l_1b2f;
	case 6966ULL: goto x86_l_1b36;
	case 6971ULL: goto x86_l_1b3b;
	case 6976ULL: goto x86_l_1b40;
	case 6978ULL: goto x86_l_1b42;
	case 6982ULL: goto x86_l_1b46;
	case 6984ULL: goto x86_l_1b48;
	case 6986ULL: goto x86_l_1b4a;
	case 6992ULL: goto x86_l_1b50;
	case 6995ULL: goto x86_l_1b53;
	case 7000ULL: goto x86_l_1b58;
	case 7006ULL: goto x86_l_1b5e;
	case 7011ULL: goto x86_l_1b63;
	case 7019ULL: goto x86_l_1b6b;
	case 7023ULL: goto x86_l_1b6f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_141a:
	/* 0x141a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_141f:
	/* 0x141f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1424:
	/* 0x1424: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1426:
	/* 0x1426: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_142a:
	/* 0x142a: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_142c:
	/* 0x142c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_142e:
	/* 0x142e: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1434:
	/* 0x1434: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1437:
	/* 0x1437: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_143c:
	/* 0x143c: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1442:
	/* 0x1442: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1447:
	/* 0x1447: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_144f:
	/* 0x144f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1453:
	/* 0x1453: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_145a:
	/* 0x145a: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_145f:
	/* 0x145f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1464:
	/* 0x1464: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1466:
	/* 0x1466: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_146b:
	/* 0x146b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1473:
	/* 0x1473: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1476:
	/* 0x1476: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_147e:
	/* 0x147e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1487:
	/* 0x1487: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_148b:
	/* 0x148b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1490:
	/* 0x1490: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1495:
	/* 0x1495: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_149a:
	/* 0x149a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149c:
	/* 0x149c: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_149e:
	/* 0x149e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_14a4:
	/* 0x14a4: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_14aa:
	/* 0x14aa: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_14ad:
	/* 0x14ad: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_14b2:
	/* 0x14b2: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_14b8:
	/* 0x14b8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_14bd:
	/* 0x14bd: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_14c5:
	/* 0x14c5: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_14c9:
	/* 0x14c9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_14d0:
	/* 0x14d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14d5:
	/* 0x14d5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_14da:
	/* 0x14da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14dc:
	/* 0x14dc: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_14e0:
	/* 0x14e0: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_14e2:
	/* 0x14e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14e4:
	/* 0x14e4: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_14ea:
	/* 0x14ea: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_14ed:
	/* 0x14ed: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_14f2:
	/* 0x14f2: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_14f8:
	/* 0x14f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14fd:
	/* 0x14fd: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1505:
	/* 0x1505: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1509:
	/* 0x1509: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1510:
	/* 0x1510: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1515:
	/* 0x1515: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_151a:
	/* 0x151a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151c:
	/* 0x151c: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1521:
	/* 0x1521: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1529:
	/* 0x1529: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_152c:
	/* 0x152c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1534:
	/* 0x1534: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_153d:
	/* 0x153d: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1541:
	/* 0x1541: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1546:
	/* 0x1546: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_154b:
	/* 0x154b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1550:
	/* 0x1550: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1552:
	/* 0x1552: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_1554:
	/* 0x1554: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_155a:
	/* 0x155a: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1560:
	/* 0x1560: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1563:
	/* 0x1563: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1568:
	/* 0x1568: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_156e:
	/* 0x156e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1573:
	/* 0x1573: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_157b:
	/* 0x157b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_157f:
	/* 0x157f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1586:
	/* 0x1586: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_158b:
	/* 0x158b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1590:
	/* 0x1590: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1592:
	/* 0x1592: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1596:
	/* 0x1596: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_1598:
	/* 0x1598: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_159a:
	/* 0x159a: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_15a0:
	/* 0x15a0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15a3:
	/* 0x15a3: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_15a8:
	/* 0x15a8: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_15ae:
	/* 0x15ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15b3:
	/* 0x15b3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_15bb:
	/* 0x15bb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_15bf:
	/* 0x15bf: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_15c6:
	/* 0x15c6: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_15cb:
	/* 0x15cb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15d0:
	/* 0x15d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d2:
	/* 0x15d2: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_15d7:
	/* 0x15d7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_15df:
	/* 0x15df: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_15e2:
	/* 0x15e2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_15ea:
	/* 0x15ea: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_15f3:
	/* 0x15f3: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15f7:
	/* 0x15f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15fc:
	/* 0x15fc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1601:
	/* 0x1601: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1606:
	/* 0x1606: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1608:
	/* 0x1608: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_160a:
	/* 0x160a: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1610:
	/* 0x1610: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1616:
	/* 0x1616: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1619:
	/* 0x1619: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_161e:
	/* 0x161e: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1624:
	/* 0x1624: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1629:
	/* 0x1629: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1631:
	/* 0x1631: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1635:
	/* 0x1635: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_163c:
	/* 0x163c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1641:
	/* 0x1641: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1646:
	/* 0x1646: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1648:
	/* 0x1648: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_164c:
	/* 0x164c: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_164e:
	/* 0x164e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1650:
	/* 0x1650: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1656:
	/* 0x1656: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1659:
	/* 0x1659: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_165e:
	/* 0x165e: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1664:
	/* 0x1664: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1669:
	/* 0x1669: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1671:
	/* 0x1671: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1675:
	/* 0x1675: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_167c:
	/* 0x167c: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1681:
	/* 0x1681: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1686:
	/* 0x1686: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1688:
	/* 0x1688: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_168d:
	/* 0x168d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1695:
	/* 0x1695: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1698:
	/* 0x1698: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_16a0:
	/* 0x16a0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_16a9:
	/* 0x16a9: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16ad:
	/* 0x16ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16b2:
	/* 0x16b2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16b7:
	/* 0x16b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16bc:
	/* 0x16bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16be:
	/* 0x16be: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_16c0:
	/* 0x16c0: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_16c6:
	/* 0x16c6: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_16cc:
	/* 0x16cc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16cf:
	/* 0x16cf: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_16d4:
	/* 0x16d4: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_16da:
	/* 0x16da: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_16df:
	/* 0x16df: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_16e7:
	/* 0x16e7: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_16eb:
	/* 0x16eb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_16f2:
	/* 0x16f2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16f7:
	/* 0x16f7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_16fc:
	/* 0x16fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16fe:
	/* 0x16fe: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1702:
	/* 0x1702: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_1704:
	/* 0x1704: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1706:
	/* 0x1706: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_170c:
	/* 0x170c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_170f:
	/* 0x170f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1714:
	/* 0x1714: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_171a:
	/* 0x171a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_171f:
	/* 0x171f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1727:
	/* 0x1727: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_172b:
	/* 0x172b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1732:
	/* 0x1732: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1737:
	/* 0x1737: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_173c:
	/* 0x173c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173e:
	/* 0x173e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1743:
	/* 0x1743: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_174b:
	/* 0x174b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_174e:
	/* 0x174e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1756:
	/* 0x1756: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_175f:
	/* 0x175f: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1763:
	/* 0x1763: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1768:
	/* 0x1768: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_176d:
	/* 0x176d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1772:
	/* 0x1772: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1774:
	/* 0x1774: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_1776:
	/* 0x1776: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_177c:
	/* 0x177c: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1782:
	/* 0x1782: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1785:
	/* 0x1785: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_178a:
	/* 0x178a: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1790:
	/* 0x1790: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1795:
	/* 0x1795: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_179d:
	/* 0x179d: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_17a1:
	/* 0x17a1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_17a8:
	/* 0x17a8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17ad:
	/* 0x17ad: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_17b2:
	/* 0x17b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b4:
	/* 0x17b4: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17b8:
	/* 0x17b8: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_17ba:
	/* 0x17ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17bc:
	/* 0x17bc: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_17c2:
	/* 0x17c2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17c5:
	/* 0x17c5: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_17ca:
	/* 0x17ca: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_17d0:
	/* 0x17d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17d5:
	/* 0x17d5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17dd:
	/* 0x17dd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_17e1:
	/* 0x17e1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_17e8:
	/* 0x17e8: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17ed:
	/* 0x17ed: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17f2:
	/* 0x17f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f4:
	/* 0x17f4: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
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
	/* 0x1815: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1819:
	/* 0x1819: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_181e:
	/* 0x181e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1823:
	/* 0x1823: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1828:
	/* 0x1828: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182a:
	/* 0x182a: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_182c:
	/* 0x182c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1832:
	/* 0x1832: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1838:
	/* 0x1838: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_183b:
	/* 0x183b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1840:
	/* 0x1840: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1846:
	/* 0x1846: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_184b:
	/* 0x184b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1853:
	/* 0x1853: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1857:
	/* 0x1857: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_185e:
	/* 0x185e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1863:
	/* 0x1863: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1868:
	/* 0x1868: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_186a:
	/* 0x186a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_186e:
	/* 0x186e: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_1870:
	/* 0x1870: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1872:
	/* 0x1872: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1878:
	/* 0x1878: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_187b:
	/* 0x187b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1880:
	/* 0x1880: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1886:
	/* 0x1886: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_188b:
	/* 0x188b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1893:
	/* 0x1893: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1897:
	/* 0x1897: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_189e:
	/* 0x189e: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_18a3:
	/* 0x18a3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18a8:
	/* 0x18a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18aa:
	/* 0x18aa: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_18af:
	/* 0x18af: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_18b7:
	/* 0x18b7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_18ba:
	/* 0x18ba: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_18c2:
	/* 0x18c2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_18cb:
	/* 0x18cb: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_18cf:
	/* 0x18cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18d4:
	/* 0x18d4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18d9:
	/* 0x18d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18de:
	/* 0x18de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e0:
	/* 0x18e0: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_18e2:
	/* 0x18e2: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_18e8:
	/* 0x18e8: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_18ee:
	/* 0x18ee: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18f1:
	/* 0x18f1: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_18f6:
	/* 0x18f6: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_18fc:
	/* 0x18fc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1901:
	/* 0x1901: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1909:
	/* 0x1909: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_190d:
	/* 0x190d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1914:
	/* 0x1914: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1919:
	/* 0x1919: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_191e:
	/* 0x191e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1920:
	/* 0x1920: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1924:
	/* 0x1924: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_1926:
	/* 0x1926: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1928:
	/* 0x1928: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_192e:
	/* 0x192e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1931:
	/* 0x1931: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1936:
	/* 0x1936: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_193c:
	/* 0x193c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1941:
	/* 0x1941: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1949:
	/* 0x1949: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_194d:
	/* 0x194d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1954:
	/* 0x1954: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1959:
	/* 0x1959: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_195e:
	/* 0x195e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1960:
	/* 0x1960: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1965:
	/* 0x1965: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_196d:
	/* 0x196d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1970:
	/* 0x1970: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1978:
	/* 0x1978: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1981:
	/* 0x1981: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1985:
	/* 0x1985: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_198a:
	/* 0x198a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_198f:
	/* 0x198f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1994:
	/* 0x1994: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1996:
	/* 0x1996: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_1998:
	/* 0x1998: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_199e:
	/* 0x199e: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_19a4:
	/* 0x19a4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19a7:
	/* 0x19a7: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_19ac:
	/* 0x19ac: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_19b2:
	/* 0x19b2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_19b7:
	/* 0x19b7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19bf:
	/* 0x19bf: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_19c3:
	/* 0x19c3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_19ca:
	/* 0x19ca: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19cf:
	/* 0x19cf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_19d4:
	/* 0x19d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d6:
	/* 0x19d6: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_19da:
	/* 0x19da: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_19dc:
	/* 0x19dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19de:
	/* 0x19de: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_19e4:
	/* 0x19e4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19e7:
	/* 0x19e7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_19ec:
	/* 0x19ec: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_19f2:
	/* 0x19f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19f7:
	/* 0x19f7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19ff:
	/* 0x19ff: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1a03:
	/* 0x1a03: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1a0a:
	/* 0x1a0a: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a0f:
	/* 0x1a0f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a14:
	/* 0x1a14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a16:
	/* 0x1a16: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1a1b:
	/* 0x1a1b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1a23:
	/* 0x1a23: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1a26:
	/* 0x1a26: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1a2e:
	/* 0x1a2e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1a37:
	/* 0x1a37: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1a3b:
	/* 0x1a3b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a40:
	/* 0x1a40: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a45:
	/* 0x1a45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a4a:
	/* 0x1a4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4c:
	/* 0x1a4c: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_1a4e:
	/* 0x1a4e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1a54:
	/* 0x1a54: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1a5a:
	/* 0x1a5a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a5d:
	/* 0x1a5d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1a62:
	/* 0x1a62: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1a68:
	/* 0x1a68: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1a6d:
	/* 0x1a6d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a75:
	/* 0x1a75: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1a79:
	/* 0x1a79: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1a80:
	/* 0x1a80: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a85:
	/* 0x1a85: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a8a:
	/* 0x1a8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8c:
	/* 0x1a8c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a90:
	/* 0x1a90: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_1a92:
	/* 0x1a92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a94:
	/* 0x1a94: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1a9a:
	/* 0x1a9a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a9d:
	/* 0x1a9d: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1aa2:
	/* 0x1aa2: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1aa8:
	/* 0x1aa8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aad:
	/* 0x1aad: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ab5:
	/* 0x1ab5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1ab9:
	/* 0x1ab9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ac0:
	/* 0x1ac0: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ac5:
	/* 0x1ac5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aca:
	/* 0x1aca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1acc:
	/* 0x1acc: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1ad1:
	/* 0x1ad1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1ad9:
	/* 0x1ad9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1adc:
	/* 0x1adc: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1aed:
	/* 0x1aed: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1af1:
	/* 0x1af1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1af6:
	/* 0x1af6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1afb:
	/* 0x1afb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b00:
	/* 0x1b00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b02:
	/* 0x1b02: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1b04:
	/* 0x1b04: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b0a:
	/* 0x1b0a: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1b10:
	/* 0x1b10: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b13:
	/* 0x1b13: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1b18:
	/* 0x1b18: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1b1e:
	/* 0x1b1e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1b23:
	/* 0x1b23: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b2b:
	/* 0x1b2b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1b2f:
	/* 0x1b2f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1b36:
	/* 0x1b36: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b3b:
	/* 0x1b3b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1b40:
	/* 0x1b40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b42:
	/* 0x1b42: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b46:
	/* 0x1b46: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1b48:
	/* 0x1b48: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b4a:
	/* 0x1b4a: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1b50:
	/* 0x1b50: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b53:
	/* 0x1b53: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1b58:
	/* 0x1b58: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1b5e:
	/* 0x1b5e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b63:
	/* 0x1b63: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b6b:
	/* 0x1b6b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1b6f:
	/* 0x1b6f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
	return 7030ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7030ULL: goto x86_l_1b76;
	case 7035ULL: goto x86_l_1b7b;
	case 7040ULL: goto x86_l_1b80;
	case 7042ULL: goto x86_l_1b82;
	case 7047ULL: goto x86_l_1b87;
	case 7055ULL: goto x86_l_1b8f;
	case 7058ULL: goto x86_l_1b92;
	case 7066ULL: goto x86_l_1b9a;
	case 7075ULL: goto x86_l_1ba3;
	case 7082ULL: goto x86_l_1baa;
	case 7087ULL: goto x86_l_1baf;
	case 7092ULL: goto x86_l_1bb4;
	case 7097ULL: goto x86_l_1bb9;
	case 7099ULL: goto x86_l_1bbb;
	case 7101ULL: goto x86_l_1bbd;
	case 7107ULL: goto x86_l_1bc3;
	case 7113ULL: goto x86_l_1bc9;
	case 7116ULL: goto x86_l_1bcc;
	case 7121ULL: goto x86_l_1bd1;
	case 7127ULL: goto x86_l_1bd7;
	case 7132ULL: goto x86_l_1bdc;
	case 7140ULL: goto x86_l_1be4;
	case 7144ULL: goto x86_l_1be8;
	case 7151ULL: goto x86_l_1bef;
	case 7156ULL: goto x86_l_1bf4;
	case 7161ULL: goto x86_l_1bf9;
	case 7163ULL: goto x86_l_1bfb;
	case 7167ULL: goto x86_l_1bff;
	case 7169ULL: goto x86_l_1c01;
	case 7171ULL: goto x86_l_1c03;
	case 7177ULL: goto x86_l_1c09;
	case 7180ULL: goto x86_l_1c0c;
	case 7185ULL: goto x86_l_1c11;
	case 7191ULL: goto x86_l_1c17;
	case 7196ULL: goto x86_l_1c1c;
	case 7204ULL: goto x86_l_1c24;
	case 7208ULL: goto x86_l_1c28;
	case 7215ULL: goto x86_l_1c2f;
	case 7220ULL: goto x86_l_1c34;
	case 7225ULL: goto x86_l_1c39;
	case 7227ULL: goto x86_l_1c3b;
	case 7232ULL: goto x86_l_1c40;
	case 7240ULL: goto x86_l_1c48;
	case 7243ULL: goto x86_l_1c4b;
	case 7251ULL: goto x86_l_1c53;
	case 7260ULL: goto x86_l_1c5c;
	case 7267ULL: goto x86_l_1c63;
	case 7272ULL: goto x86_l_1c68;
	case 7277ULL: goto x86_l_1c6d;
	case 7282ULL: goto x86_l_1c72;
	case 7284ULL: goto x86_l_1c74;
	case 7286ULL: goto x86_l_1c76;
	case 7292ULL: goto x86_l_1c7c;
	case 7298ULL: goto x86_l_1c82;
	case 7301ULL: goto x86_l_1c85;
	case 7306ULL: goto x86_l_1c8a;
	case 7312ULL: goto x86_l_1c90;
	case 7317ULL: goto x86_l_1c95;
	case 7325ULL: goto x86_l_1c9d;
	case 7329ULL: goto x86_l_1ca1;
	case 7336ULL: goto x86_l_1ca8;
	case 7341ULL: goto x86_l_1cad;
	case 7346ULL: goto x86_l_1cb2;
	case 7348ULL: goto x86_l_1cb4;
	case 7352ULL: goto x86_l_1cb8;
	case 7354ULL: goto x86_l_1cba;
	case 7356ULL: goto x86_l_1cbc;
	case 7362ULL: goto x86_l_1cc2;
	case 7365ULL: goto x86_l_1cc5;
	case 7370ULL: goto x86_l_1cca;
	case 7376ULL: goto x86_l_1cd0;
	case 7381ULL: goto x86_l_1cd5;
	case 7389ULL: goto x86_l_1cdd;
	case 7393ULL: goto x86_l_1ce1;
	case 7400ULL: goto x86_l_1ce8;
	case 7405ULL: goto x86_l_1ced;
	case 7410ULL: goto x86_l_1cf2;
	case 7412ULL: goto x86_l_1cf4;
	case 7417ULL: goto x86_l_1cf9;
	case 7425ULL: goto x86_l_1d01;
	case 7428ULL: goto x86_l_1d04;
	case 7436ULL: goto x86_l_1d0c;
	case 7445ULL: goto x86_l_1d15;
	case 7452ULL: goto x86_l_1d1c;
	case 7457ULL: goto x86_l_1d21;
	case 7462ULL: goto x86_l_1d26;
	case 7467ULL: goto x86_l_1d2b;
	case 7469ULL: goto x86_l_1d2d;
	case 7471ULL: goto x86_l_1d2f;
	case 7477ULL: goto x86_l_1d35;
	case 7483ULL: goto x86_l_1d3b;
	case 7486ULL: goto x86_l_1d3e;
	case 7491ULL: goto x86_l_1d43;
	case 7497ULL: goto x86_l_1d49;
	case 7502ULL: goto x86_l_1d4e;
	case 7510ULL: goto x86_l_1d56;
	case 7514ULL: goto x86_l_1d5a;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7531ULL: goto x86_l_1d6b;
	case 7533ULL: goto x86_l_1d6d;
	case 7537ULL: goto x86_l_1d71;
	case 7539ULL: goto x86_l_1d73;
	case 7541ULL: goto x86_l_1d75;
	case 7547ULL: goto x86_l_1d7b;
	case 7550ULL: goto x86_l_1d7e;
	case 7555ULL: goto x86_l_1d83;
	case 7561ULL: goto x86_l_1d89;
	case 7566ULL: goto x86_l_1d8e;
	case 7574ULL: goto x86_l_1d96;
	case 7578ULL: goto x86_l_1d9a;
	case 7585ULL: goto x86_l_1da1;
	case 7590ULL: goto x86_l_1da6;
	case 7595ULL: goto x86_l_1dab;
	case 7597ULL: goto x86_l_1dad;
	case 7602ULL: goto x86_l_1db2;
	case 7610ULL: goto x86_l_1dba;
	case 7613ULL: goto x86_l_1dbd;
	case 7621ULL: goto x86_l_1dc5;
	case 7630ULL: goto x86_l_1dce;
	case 7637ULL: goto x86_l_1dd5;
	case 7642ULL: goto x86_l_1dda;
	case 7647ULL: goto x86_l_1ddf;
	case 7652ULL: goto x86_l_1de4;
	case 7654ULL: goto x86_l_1de6;
	case 7656ULL: goto x86_l_1de8;
	case 7662ULL: goto x86_l_1dee;
	case 7668ULL: goto x86_l_1df4;
	case 7671ULL: goto x86_l_1df7;
	case 7676ULL: goto x86_l_1dfc;
	case 7682ULL: goto x86_l_1e02;
	case 7687ULL: goto x86_l_1e07;
	case 7695ULL: goto x86_l_1e0f;
	case 7699ULL: goto x86_l_1e13;
	case 7706ULL: goto x86_l_1e1a;
	case 7711ULL: goto x86_l_1e1f;
	case 7716ULL: goto x86_l_1e24;
	case 7718ULL: goto x86_l_1e26;
	case 7722ULL: goto x86_l_1e2a;
	case 7724ULL: goto x86_l_1e2c;
	case 7726ULL: goto x86_l_1e2e;
	case 7732ULL: goto x86_l_1e34;
	case 7735ULL: goto x86_l_1e37;
	case 7740ULL: goto x86_l_1e3c;
	case 7746ULL: goto x86_l_1e42;
	case 7751ULL: goto x86_l_1e47;
	case 7759ULL: goto x86_l_1e4f;
	case 7763ULL: goto x86_l_1e53;
	case 7770ULL: goto x86_l_1e5a;
	case 7775ULL: goto x86_l_1e5f;
	case 7780ULL: goto x86_l_1e64;
	case 7782ULL: goto x86_l_1e66;
	case 7787ULL: goto x86_l_1e6b;
	case 7795ULL: goto x86_l_1e73;
	case 7798ULL: goto x86_l_1e76;
	case 7806ULL: goto x86_l_1e7e;
	case 7815ULL: goto x86_l_1e87;
	case 7822ULL: goto x86_l_1e8e;
	case 7827ULL: goto x86_l_1e93;
	case 7832ULL: goto x86_l_1e98;
	case 7837ULL: goto x86_l_1e9d;
	case 7839ULL: goto x86_l_1e9f;
	case 7841ULL: goto x86_l_1ea1;
	case 7847ULL: goto x86_l_1ea7;
	case 7853ULL: goto x86_l_1ead;
	case 7856ULL: goto x86_l_1eb0;
	case 7861ULL: goto x86_l_1eb5;
	case 7867ULL: goto x86_l_1ebb;
	case 7872ULL: goto x86_l_1ec0;
	case 7880ULL: goto x86_l_1ec8;
	case 7884ULL: goto x86_l_1ecc;
	case 7891ULL: goto x86_l_1ed3;
	case 7896ULL: goto x86_l_1ed8;
	case 7901ULL: goto x86_l_1edd;
	case 7903ULL: goto x86_l_1edf;
	case 7907ULL: goto x86_l_1ee3;
	case 7909ULL: goto x86_l_1ee5;
	case 7911ULL: goto x86_l_1ee7;
	case 7917ULL: goto x86_l_1eed;
	case 7920ULL: goto x86_l_1ef0;
	case 7925ULL: goto x86_l_1ef5;
	case 7931ULL: goto x86_l_1efb;
	case 7936ULL: goto x86_l_1f00;
	case 7944ULL: goto x86_l_1f08;
	case 7948ULL: goto x86_l_1f0c;
	case 7955ULL: goto x86_l_1f13;
	case 7960ULL: goto x86_l_1f18;
	case 7965ULL: goto x86_l_1f1d;
	case 7967ULL: goto x86_l_1f1f;
	case 7972ULL: goto x86_l_1f24;
	case 7980ULL: goto x86_l_1f2c;
	case 7983ULL: goto x86_l_1f2f;
	case 7991ULL: goto x86_l_1f37;
	case 8000ULL: goto x86_l_1f40;
	case 8007ULL: goto x86_l_1f47;
	case 8012ULL: goto x86_l_1f4c;
	case 8017ULL: goto x86_l_1f51;
	case 8022ULL: goto x86_l_1f56;
	case 8024ULL: goto x86_l_1f58;
	case 8026ULL: goto x86_l_1f5a;
	case 8032ULL: goto x86_l_1f60;
	case 8038ULL: goto x86_l_1f66;
	case 8041ULL: goto x86_l_1f69;
	case 8046ULL: goto x86_l_1f6e;
	case 8052ULL: goto x86_l_1f74;
	case 8057ULL: goto x86_l_1f79;
	case 8065ULL: goto x86_l_1f81;
	case 8069ULL: goto x86_l_1f85;
	case 8076ULL: goto x86_l_1f8c;
	case 8081ULL: goto x86_l_1f91;
	case 8086ULL: goto x86_l_1f96;
	case 8088ULL: goto x86_l_1f98;
	case 8092ULL: goto x86_l_1f9c;
	case 8094ULL: goto x86_l_1f9e;
	case 8096ULL: goto x86_l_1fa0;
	case 8102ULL: goto x86_l_1fa6;
	case 8105ULL: goto x86_l_1fa9;
	case 8110ULL: goto x86_l_1fae;
	case 8116ULL: goto x86_l_1fb4;
	case 8121ULL: goto x86_l_1fb9;
	case 8129ULL: goto x86_l_1fc1;
	case 8133ULL: goto x86_l_1fc5;
	case 8140ULL: goto x86_l_1fcc;
	case 8145ULL: goto x86_l_1fd1;
	case 8150ULL: goto x86_l_1fd6;
	case 8152ULL: goto x86_l_1fd8;
	case 8157ULL: goto x86_l_1fdd;
	case 8165ULL: goto x86_l_1fe5;
	case 8168ULL: goto x86_l_1fe8;
	case 8176ULL: goto x86_l_1ff0;
	case 8185ULL: goto x86_l_1ff9;
	case 8192ULL: goto x86_l_2000;
	case 8197ULL: goto x86_l_2005;
	case 8202ULL: goto x86_l_200a;
	case 8207ULL: goto x86_l_200f;
	case 8209ULL: goto x86_l_2011;
	case 8211ULL: goto x86_l_2013;
	case 8217ULL: goto x86_l_2019;
	case 8223ULL: goto x86_l_201f;
	case 8226ULL: goto x86_l_2022;
	case 8231ULL: goto x86_l_2027;
	case 8237ULL: goto x86_l_202d;
	case 8242ULL: goto x86_l_2032;
	case 8250ULL: goto x86_l_203a;
	case 8254ULL: goto x86_l_203e;
	case 8261ULL: goto x86_l_2045;
	case 8266ULL: goto x86_l_204a;
	case 8271ULL: goto x86_l_204f;
	case 8273ULL: goto x86_l_2051;
	case 8277ULL: goto x86_l_2055;
	case 8279ULL: goto x86_l_2057;
	case 8281ULL: goto x86_l_2059;
	case 8287ULL: goto x86_l_205f;
	case 8290ULL: goto x86_l_2062;
	case 8295ULL: goto x86_l_2067;
	case 8301ULL: goto x86_l_206d;
	case 8306ULL: goto x86_l_2072;
	case 8314ULL: goto x86_l_207a;
	case 8318ULL: goto x86_l_207e;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8335ULL: goto x86_l_208f;
	case 8337ULL: goto x86_l_2091;
	case 8342ULL: goto x86_l_2096;
	case 8350ULL: goto x86_l_209e;
	case 8353ULL: goto x86_l_20a1;
	case 8361ULL: goto x86_l_20a9;
	case 8370ULL: goto x86_l_20b2;
	case 8377ULL: goto x86_l_20b9;
	case 8382ULL: goto x86_l_20be;
	case 8387ULL: goto x86_l_20c3;
	case 8392ULL: goto x86_l_20c8;
	case 8394ULL: goto x86_l_20ca;
	case 8396ULL: goto x86_l_20cc;
	case 8402ULL: goto x86_l_20d2;
	case 8408ULL: goto x86_l_20d8;
	case 8411ULL: goto x86_l_20db;
	case 8416ULL: goto x86_l_20e0;
	case 8422ULL: goto x86_l_20e6;
	case 8427ULL: goto x86_l_20eb;
	case 8435ULL: goto x86_l_20f3;
	case 8439ULL: goto x86_l_20f7;
	case 8446ULL: goto x86_l_20fe;
	case 8451ULL: goto x86_l_2103;
	case 8456ULL: goto x86_l_2108;
	case 8458ULL: goto x86_l_210a;
	case 8462ULL: goto x86_l_210e;
	case 8464ULL: goto x86_l_2110;
	case 8466ULL: goto x86_l_2112;
	case 8472ULL: goto x86_l_2118;
	case 8475ULL: goto x86_l_211b;
	case 8480ULL: goto x86_l_2120;
	case 8486ULL: goto x86_l_2126;
	case 8491ULL: goto x86_l_212b;
	case 8499ULL: goto x86_l_2133;
	case 8503ULL: goto x86_l_2137;
	case 8510ULL: goto x86_l_213e;
	case 8515ULL: goto x86_l_2143;
	case 8520ULL: goto x86_l_2148;
	case 8522ULL: goto x86_l_214a;
	case 8527ULL: goto x86_l_214f;
	case 8535ULL: goto x86_l_2157;
	case 8538ULL: goto x86_l_215a;
	case 8546ULL: goto x86_l_2162;
	case 8555ULL: goto x86_l_216b;
	case 8562ULL: goto x86_l_2172;
	case 8567ULL: goto x86_l_2177;
	case 8572ULL: goto x86_l_217c;
	case 8577ULL: goto x86_l_2181;
	case 8579ULL: goto x86_l_2183;
	case 8581ULL: goto x86_l_2185;
	case 8587ULL: goto x86_l_218b;
	case 8593ULL: goto x86_l_2191;
	case 8596ULL: goto x86_l_2194;
	case 8601ULL: goto x86_l_2199;
	case 8607ULL: goto x86_l_219f;
	case 8612ULL: goto x86_l_21a4;
	case 8620ULL: goto x86_l_21ac;
	case 8624ULL: goto x86_l_21b0;
	case 8631ULL: goto x86_l_21b7;
	case 8636ULL: goto x86_l_21bc;
	case 8641ULL: goto x86_l_21c1;
	case 8643ULL: goto x86_l_21c3;
	case 8647ULL: goto x86_l_21c7;
	case 8649ULL: goto x86_l_21c9;
	case 8651ULL: goto x86_l_21cb;
	case 8657ULL: goto x86_l_21d1;
	case 8660ULL: goto x86_l_21d4;
	case 8665ULL: goto x86_l_21d9;
	case 8671ULL: goto x86_l_21df;
	case 8676ULL: goto x86_l_21e4;
	case 8684ULL: goto x86_l_21ec;
	case 8688ULL: goto x86_l_21f0;
	case 8695ULL: goto x86_l_21f7;
	case 8700ULL: goto x86_l_21fc;
	case 8705ULL: goto x86_l_2201;
	case 8707ULL: goto x86_l_2203;
	case 8712ULL: goto x86_l_2208;
	case 8720ULL: goto x86_l_2210;
	case 8723ULL: goto x86_l_2213;
	case 8731ULL: goto x86_l_221b;
	case 8740ULL: goto x86_l_2224;
	case 8747ULL: goto x86_l_222b;
	case 8752ULL: goto x86_l_2230;
	case 8757ULL: goto x86_l_2235;
	case 8762ULL: goto x86_l_223a;
	case 8764ULL: goto x86_l_223c;
	case 8766ULL: goto x86_l_223e;
	case 8772ULL: goto x86_l_2244;
	case 8778ULL: goto x86_l_224a;
	case 8781ULL: goto x86_l_224d;
	case 8786ULL: goto x86_l_2252;
	case 8792ULL: goto x86_l_2258;
	case 8797ULL: goto x86_l_225d;
	case 8805ULL: goto x86_l_2265;
	case 8809ULL: goto x86_l_2269;
	case 8816ULL: goto x86_l_2270;
	case 8821ULL: goto x86_l_2275;
	case 8826ULL: goto x86_l_227a;
	case 8828ULL: goto x86_l_227c;
	case 8832ULL: goto x86_l_2280;
	case 8834ULL: goto x86_l_2282;
	case 8836ULL: goto x86_l_2284;
	case 8842ULL: goto x86_l_228a;
	case 8845ULL: goto x86_l_228d;
	case 8850ULL: goto x86_l_2292;
	case 8856ULL: goto x86_l_2298;
	case 8861ULL: goto x86_l_229d;
	case 8869ULL: goto x86_l_22a5;
	case 8873ULL: goto x86_l_22a9;
	case 8880ULL: goto x86_l_22b0;
	case 8885ULL: goto x86_l_22b5;
	case 8890ULL: goto x86_l_22ba;
	case 8892ULL: goto x86_l_22bc;
	case 8897ULL: goto x86_l_22c1;
	case 8905ULL: goto x86_l_22c9;
	case 8908ULL: goto x86_l_22cc;
	case 8916ULL: goto x86_l_22d4;
	case 8925ULL: goto x86_l_22dd;
	case 8932ULL: goto x86_l_22e4;
	case 8937ULL: goto x86_l_22e9;
	case 8942ULL: goto x86_l_22ee;
	case 8947ULL: goto x86_l_22f3;
	case 8949ULL: goto x86_l_22f5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b76:
	/* 0x1b76: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b7b:
	/* 0x1b7b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b80:
	/* 0x1b80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b82:
	/* 0x1b82: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1b87:
	/* 0x1b87: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1b8f:
	/* 0x1b8f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1b92:
	/* 0x1b92: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1b9a:
	/* 0x1b9a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ba3:
	/* 0x1ba3: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1baa:
	/* 0x1baa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1baf:
	/* 0x1baf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bb4:
	/* 0x1bb4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bb9:
	/* 0x1bb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bbb:
	/* 0x1bbb: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_1bbd:
	/* 0x1bbd: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1bc3:
	/* 0x1bc3: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1bc9:
	/* 0x1bc9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1bcc:
	/* 0x1bcc: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1bd1:
	/* 0x1bd1: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1bd7:
	/* 0x1bd7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1bdc:
	/* 0x1bdc: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1be4:
	/* 0x1be4: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1be8:
	/* 0x1be8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1bef:
	/* 0x1bef: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bf4:
	/* 0x1bf4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1bf9:
	/* 0x1bf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bfb:
	/* 0x1bfb: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1bff:
	/* 0x1bff: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_1c01:
	/* 0x1c01: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c03:
	/* 0x1c03: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1c09:
	/* 0x1c09: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c0c:
	/* 0x1c0c: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1c11:
	/* 0x1c11: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1c17:
	/* 0x1c17: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c1c:
	/* 0x1c1c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c24:
	/* 0x1c24: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1c28:
	/* 0x1c28: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1c2f:
	/* 0x1c2f: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c34:
	/* 0x1c34: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c39:
	/* 0x1c39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c3b:
	/* 0x1c3b: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1c40:
	/* 0x1c40: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1c48:
	/* 0x1c48: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1c4b:
	/* 0x1c4b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1c53:
	/* 0x1c53: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c5c:
	/* 0x1c5c: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1c63:
	/* 0x1c63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c68:
	/* 0x1c68: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c6d:
	/* 0x1c6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c72:
	/* 0x1c72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c74:
	/* 0x1c74: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_1c76:
	/* 0x1c76: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c7c:
	/* 0x1c7c: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1c82:
	/* 0x1c82: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c85:
	/* 0x1c85: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1c8a:
	/* 0x1c8a: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1c90:
	/* 0x1c90: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1c95:
	/* 0x1c95: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c9d:
	/* 0x1c9d: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1ca1:
	/* 0x1ca1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1ca8:
	/* 0x1ca8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cad:
	/* 0x1cad: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1cb2:
	/* 0x1cb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb4:
	/* 0x1cb4: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1cb8:
	/* 0x1cb8: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_1cba:
	/* 0x1cba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cbc:
	/* 0x1cbc: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1cc2:
	/* 0x1cc2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1cc5:
	/* 0x1cc5: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1cca:
	/* 0x1cca: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1cd0:
	/* 0x1cd0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cd5:
	/* 0x1cd5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1cdd:
	/* 0x1cdd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1ce1:
	/* 0x1ce1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ce8:
	/* 0x1ce8: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ced:
	/* 0x1ced: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cf2:
	/* 0x1cf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf4:
	/* 0x1cf4: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1cf9:
	/* 0x1cf9: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1d01:
	/* 0x1d01: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1d04:
	/* 0x1d04: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1d0c:
	/* 0x1d0c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d15:
	/* 0x1d15: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1d1c:
	/* 0x1d1c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d21:
	/* 0x1d21: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d26:
	/* 0x1d26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d2b:
	/* 0x1d2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d2d:
	/* 0x1d2d: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_1d2f:
	/* 0x1d2f: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d35:
	/* 0x1d35: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1d3b:
	/* 0x1d3b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d3e:
	/* 0x1d3e: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1d43:
	/* 0x1d43: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1d49:
	/* 0x1d49: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1d4e:
	/* 0x1d4e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d56:
	/* 0x1d56: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1d5a:
	/* 0x1d5a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1d61:
	/* 0x1d61: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d66:
	/* 0x1d66: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1d6b:
	/* 0x1d6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6d:
	/* 0x1d6d: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d71:
	/* 0x1d71: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_1d73:
	/* 0x1d73: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d75:
	/* 0x1d75: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1d7b:
	/* 0x1d7b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d7e:
	/* 0x1d7e: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1d83:
	/* 0x1d83: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1d89:
	/* 0x1d89: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d8e:
	/* 0x1d8e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d96:
	/* 0x1d96: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1d9a:
	/* 0x1d9a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1da1:
	/* 0x1da1: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1da6:
	/* 0x1da6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dab:
	/* 0x1dab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dad:
	/* 0x1dad: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1db2:
	/* 0x1db2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1dba:
	/* 0x1dba: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1dbd:
	/* 0x1dbd: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1dc5:
	/* 0x1dc5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1dce:
	/* 0x1dce: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1dd5:
	/* 0x1dd5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dda:
	/* 0x1dda: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ddf:
	/* 0x1ddf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1de4:
	/* 0x1de4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de6:
	/* 0x1de6: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_1de8:
	/* 0x1de8: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1dee:
	/* 0x1dee: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1df4:
	/* 0x1df4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1df7:
	/* 0x1df7: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1dfc:
	/* 0x1dfc: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1e02:
	/* 0x1e02: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e07:
	/* 0x1e07: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e0f:
	/* 0x1e0f: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1e13:
	/* 0x1e13: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1e1a:
	/* 0x1e1a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e1f:
	/* 0x1e1f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e24:
	/* 0x1e24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e26:
	/* 0x1e26: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e2a:
	/* 0x1e2a: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_1e2c:
	/* 0x1e2c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e2e:
	/* 0x1e2e: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1e34:
	/* 0x1e34: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e37:
	/* 0x1e37: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1e3c:
	/* 0x1e3c: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1e42:
	/* 0x1e42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e47:
	/* 0x1e47: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e4f:
	/* 0x1e4f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1e53:
	/* 0x1e53: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1e5a:
	/* 0x1e5a: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e5f:
	/* 0x1e5f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e64:
	/* 0x1e64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e66:
	/* 0x1e66: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1e6b:
	/* 0x1e6b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1e73:
	/* 0x1e73: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1e76:
	/* 0x1e76: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e7e:
	/* 0x1e7e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e87:
	/* 0x1e87: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1e8e:
	/* 0x1e8e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e93:
	/* 0x1e93: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e98:
	/* 0x1e98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e9d:
	/* 0x1e9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e9f:
	/* 0x1e9f: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_1ea1:
	/* 0x1ea1: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ea7:
	/* 0x1ea7: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1ead:
	/* 0x1ead: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1eb0:
	/* 0x1eb0: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1eb5:
	/* 0x1eb5: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1ebb:
	/* 0x1ebb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1ec0:
	/* 0x1ec0: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ec8:
	/* 0x1ec8: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1ecc:
	/* 0x1ecc: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1ed3:
	/* 0x1ed3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ed8:
	/* 0x1ed8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1edd:
	/* 0x1edd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1edf:
	/* 0x1edf: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ee3:
	/* 0x1ee3: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_1ee5:
	/* 0x1ee5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ee7:
	/* 0x1ee7: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1eed:
	/* 0x1eed: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ef0:
	/* 0x1ef0: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1ef5:
	/* 0x1ef5: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1efb:
	/* 0x1efb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f00:
	/* 0x1f00: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f08:
	/* 0x1f08: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1f0c:
	/* 0x1f0c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1f13:
	/* 0x1f13: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f18:
	/* 0x1f18: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f1d:
	/* 0x1f1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f1f:
	/* 0x1f1f: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1f24:
	/* 0x1f24: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1f2c:
	/* 0x1f2c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1f2f:
	/* 0x1f2f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1f37:
	/* 0x1f37: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f40:
	/* 0x1f40: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1f47:
	/* 0x1f47: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f4c:
	/* 0x1f4c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f51:
	/* 0x1f51: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f56:
	/* 0x1f56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f58:
	/* 0x1f58: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_1f5a:
	/* 0x1f5a: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f60:
	/* 0x1f60: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_1f66:
	/* 0x1f66: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f69:
	/* 0x1f69: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1f6e:
	/* 0x1f6e: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1f74:
	/* 0x1f74: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f79:
	/* 0x1f79: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f81:
	/* 0x1f81: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1f85:
	/* 0x1f85: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1f8c:
	/* 0x1f8c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f91:
	/* 0x1f91: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1f96:
	/* 0x1f96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f98:
	/* 0x1f98: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f9c:
	/* 0x1f9c: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_1f9e:
	/* 0x1f9e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fa0:
	/* 0x1fa0: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_1fa6:
	/* 0x1fa6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fa9:
	/* 0x1fa9: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1fae:
	/* 0x1fae: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_1fb4:
	/* 0x1fb4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fb9:
	/* 0x1fb9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fc1:
	/* 0x1fc1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1fc5:
	/* 0x1fc5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1fcc:
	/* 0x1fcc: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1fd1:
	/* 0x1fd1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fd6:
	/* 0x1fd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd8:
	/* 0x1fd8: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1fdd:
	/* 0x1fdd: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1fe5:
	/* 0x1fe5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1fe8:
	/* 0x1fe8: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1ff0:
	/* 0x1ff0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ff9:
	/* 0x1ff9: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2000:
	/* 0x2000: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2005:
	/* 0x2005: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_200a:
	/* 0x200a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_200f:
	/* 0x200f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2011:
	/* 0x2011: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_2013:
	/* 0x2013: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2019:
	/* 0x2019: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_201f:
	/* 0x201f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2022:
	/* 0x2022: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2027:
	/* 0x2027: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_202d:
	/* 0x202d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2032:
	/* 0x2032: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_203a:
	/* 0x203a: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_203e:
	/* 0x203e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2045:
	/* 0x2045: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_204a:
	/* 0x204a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_204f:
	/* 0x204f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2051:
	/* 0x2051: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2055:
	/* 0x2055: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_2057:
	/* 0x2057: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2059:
	/* 0x2059: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_205f:
	/* 0x205f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2062:
	/* 0x2062: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2067:
	/* 0x2067: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_206d:
	/* 0x206d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2072:
	/* 0x2072: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_207a:
	/* 0x207a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_207e:
	/* 0x207e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2085:
	/* 0x2085: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_208a:
	/* 0x208a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_208f:
	/* 0x208f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2091:
	/* 0x2091: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2096:
	/* 0x2096: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_209e:
	/* 0x209e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_20a1:
	/* 0x20a1: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_20a9:
	/* 0x20a9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_20b2:
	/* 0x20b2: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_20b9:
	/* 0x20b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20be:
	/* 0x20be: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20c3:
	/* 0x20c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20c8:
	/* 0x20c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ca:
	/* 0x20ca: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_20cc:
	/* 0x20cc: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_20d2:
	/* 0x20d2: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_20d8:
	/* 0x20d8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20db:
	/* 0x20db: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_20e0:
	/* 0x20e0: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_20e6:
	/* 0x20e6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_20eb:
	/* 0x20eb: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_20f3:
	/* 0x20f3: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_20f7:
	/* 0x20f7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_20fe:
	/* 0x20fe: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2103:
	/* 0x2103: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2108:
	/* 0x2108: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_210a:
	/* 0x210a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_210e:
	/* 0x210e: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_2110:
	/* 0x2110: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2112:
	/* 0x2112: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2118:
	/* 0x2118: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_211b:
	/* 0x211b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2120:
	/* 0x2120: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2126:
	/* 0x2126: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_212b:
	/* 0x212b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2133:
	/* 0x2133: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2137:
	/* 0x2137: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_213e:
	/* 0x213e: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2143:
	/* 0x2143: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2148:
	/* 0x2148: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_214a:
	/* 0x214a: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_214f:
	/* 0x214f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2157:
	/* 0x2157: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_215a:
	/* 0x215a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2162:
	/* 0x2162: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_216b:
	/* 0x216b: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2172:
	/* 0x2172: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2177:
	/* 0x2177: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_217c:
	/* 0x217c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2181:
	/* 0x2181: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2183:
	/* 0x2183: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_2185:
	/* 0x2185: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_218b:
	/* 0x218b: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_2191:
	/* 0x2191: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2194:
	/* 0x2194: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2199:
	/* 0x2199: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_219f:
	/* 0x219f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_21a4:
	/* 0x21a4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_21ac:
	/* 0x21ac: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_21b0:
	/* 0x21b0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_21b7:
	/* 0x21b7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21bc:
	/* 0x21bc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_21c1:
	/* 0x21c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21c3:
	/* 0x21c3: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_21c7:
	/* 0x21c7: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_21c9:
	/* 0x21c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21cb:
	/* 0x21cb: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_21d1:
	/* 0x21d1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21d4:
	/* 0x21d4: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_21d9:
	/* 0x21d9: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_21df:
	/* 0x21df: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21e4:
	/* 0x21e4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_21ec:
	/* 0x21ec: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_21f0:
	/* 0x21f0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_21f7:
	/* 0x21f7: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_21fc:
	/* 0x21fc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2201:
	/* 0x2201: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2203:
	/* 0x2203: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2208:
	/* 0x2208: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2210:
	/* 0x2210: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2213:
	/* 0x2213: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_221b:
	/* 0x221b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2224:
	/* 0x2224: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_222b:
	/* 0x222b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2230:
	/* 0x2230: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2235:
	/* 0x2235: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_223a:
	/* 0x223a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223c:
	/* 0x223c: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_223e:
	/* 0x223e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2244:
	/* 0x2244: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_224a:
	/* 0x224a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_224d:
	/* 0x224d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2252:
	/* 0x2252: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2258:
	/* 0x2258: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_225d:
	/* 0x225d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2265:
	/* 0x2265: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2269:
	/* 0x2269: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2270:
	/* 0x2270: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2275:
	/* 0x2275: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_227a:
	/* 0x227a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_227c:
	/* 0x227c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2280:
	/* 0x2280: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_2282:
	/* 0x2282: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2284:
	/* 0x2284: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_228a:
	/* 0x228a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_228d:
	/* 0x228d: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2292:
	/* 0x2292: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2298:
	/* 0x2298: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_229d:
	/* 0x229d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_22a5:
	/* 0x22a5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_22a9:
	/* 0x22a9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_22b0:
	/* 0x22b0: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_22b5:
	/* 0x22b5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22ba:
	/* 0x22ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22bc:
	/* 0x22bc: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_22c1:
	/* 0x22c1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_22c9:
	/* 0x22c9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_22cc:
	/* 0x22cc: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_22d4:
	/* 0x22d4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_22dd:
	/* 0x22dd: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_22e4:
	/* 0x22e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22e9:
	/* 0x22e9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ee:
	/* 0x22ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22f3:
	/* 0x22f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f5:
	/* 0x22f5: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
	return 8951ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8951ULL: goto x86_l_22f7;
	case 8957ULL: goto x86_l_22fd;
	case 8963ULL: goto x86_l_2303;
	case 8966ULL: goto x86_l_2306;
	case 8971ULL: goto x86_l_230b;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8990ULL: goto x86_l_231e;
	case 8994ULL: goto x86_l_2322;
	case 9001ULL: goto x86_l_2329;
	case 9006ULL: goto x86_l_232e;
	case 9011ULL: goto x86_l_2333;
	case 9013ULL: goto x86_l_2335;
	case 9017ULL: goto x86_l_2339;
	case 9019ULL: goto x86_l_233b;
	case 9021ULL: goto x86_l_233d;
	case 9027ULL: goto x86_l_2343;
	case 9030ULL: goto x86_l_2346;
	case 9035ULL: goto x86_l_234b;
	case 9041ULL: goto x86_l_2351;
	case 9046ULL: goto x86_l_2356;
	case 9054ULL: goto x86_l_235e;
	case 9058ULL: goto x86_l_2362;
	case 9065ULL: goto x86_l_2369;
	case 9070ULL: goto x86_l_236e;
	case 9075ULL: goto x86_l_2373;
	case 9077ULL: goto x86_l_2375;
	case 9082ULL: goto x86_l_237a;
	case 9090ULL: goto x86_l_2382;
	case 9093ULL: goto x86_l_2385;
	case 9101ULL: goto x86_l_238d;
	case 9110ULL: goto x86_l_2396;
	case 9117ULL: goto x86_l_239d;
	case 9122ULL: goto x86_l_23a2;
	case 9127ULL: goto x86_l_23a7;
	case 9132ULL: goto x86_l_23ac;
	case 9134ULL: goto x86_l_23ae;
	case 9136ULL: goto x86_l_23b0;
	case 9142ULL: goto x86_l_23b6;
	case 9148ULL: goto x86_l_23bc;
	case 9151ULL: goto x86_l_23bf;
	case 9156ULL: goto x86_l_23c4;
	case 9162ULL: goto x86_l_23ca;
	case 9167ULL: goto x86_l_23cf;
	case 9175ULL: goto x86_l_23d7;
	case 9179ULL: goto x86_l_23db;
	case 9186ULL: goto x86_l_23e2;
	case 9191ULL: goto x86_l_23e7;
	case 9196ULL: goto x86_l_23ec;
	case 9198ULL: goto x86_l_23ee;
	case 9202ULL: goto x86_l_23f2;
	case 9204ULL: goto x86_l_23f4;
	case 9206ULL: goto x86_l_23f6;
	case 9212ULL: goto x86_l_23fc;
	case 9215ULL: goto x86_l_23ff;
	case 9220ULL: goto x86_l_2404;
	case 9226ULL: goto x86_l_240a;
	case 9231ULL: goto x86_l_240f;
	case 9239ULL: goto x86_l_2417;
	case 9243ULL: goto x86_l_241b;
	case 9250ULL: goto x86_l_2422;
	case 9255ULL: goto x86_l_2427;
	case 9260ULL: goto x86_l_242c;
	case 9262ULL: goto x86_l_242e;
	case 9267ULL: goto x86_l_2433;
	case 9275ULL: goto x86_l_243b;
	case 9278ULL: goto x86_l_243e;
	case 9286ULL: goto x86_l_2446;
	case 9295ULL: goto x86_l_244f;
	case 9302ULL: goto x86_l_2456;
	case 9307ULL: goto x86_l_245b;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9319ULL: goto x86_l_2467;
	case 9321ULL: goto x86_l_2469;
	case 9327ULL: goto x86_l_246f;
	case 9333ULL: goto x86_l_2475;
	case 9336ULL: goto x86_l_2478;
	case 9341ULL: goto x86_l_247d;
	case 9347ULL: goto x86_l_2483;
	case 9352ULL: goto x86_l_2488;
	case 9360ULL: goto x86_l_2490;
	case 9364ULL: goto x86_l_2494;
	case 9371ULL: goto x86_l_249b;
	case 9376ULL: goto x86_l_24a0;
	case 9381ULL: goto x86_l_24a5;
	case 9383ULL: goto x86_l_24a7;
	case 9387ULL: goto x86_l_24ab;
	case 9389ULL: goto x86_l_24ad;
	case 9391ULL: goto x86_l_24af;
	case 9397ULL: goto x86_l_24b5;
	case 9400ULL: goto x86_l_24b8;
	case 9405ULL: goto x86_l_24bd;
	case 9411ULL: goto x86_l_24c3;
	case 9416ULL: goto x86_l_24c8;
	case 9424ULL: goto x86_l_24d0;
	case 9428ULL: goto x86_l_24d4;
	case 9435ULL: goto x86_l_24db;
	case 9440ULL: goto x86_l_24e0;
	case 9445ULL: goto x86_l_24e5;
	case 9447ULL: goto x86_l_24e7;
	case 9452ULL: goto x86_l_24ec;
	case 9460ULL: goto x86_l_24f4;
	case 9463ULL: goto x86_l_24f7;
	case 9471ULL: goto x86_l_24ff;
	case 9480ULL: goto x86_l_2508;
	case 9487ULL: goto x86_l_250f;
	case 9492ULL: goto x86_l_2514;
	case 9497ULL: goto x86_l_2519;
	case 9502ULL: goto x86_l_251e;
	case 9504ULL: goto x86_l_2520;
	case 9506ULL: goto x86_l_2522;
	case 9512ULL: goto x86_l_2528;
	case 9518ULL: goto x86_l_252e;
	case 9521ULL: goto x86_l_2531;
	case 9526ULL: goto x86_l_2536;
	case 9532ULL: goto x86_l_253c;
	case 9537ULL: goto x86_l_2541;
	case 9545ULL: goto x86_l_2549;
	case 9549ULL: goto x86_l_254d;
	case 9556ULL: goto x86_l_2554;
	case 9561ULL: goto x86_l_2559;
	case 9566ULL: goto x86_l_255e;
	case 9568ULL: goto x86_l_2560;
	case 9572ULL: goto x86_l_2564;
	case 9574ULL: goto x86_l_2566;
	case 9576ULL: goto x86_l_2568;
	case 9582ULL: goto x86_l_256e;
	case 9585ULL: goto x86_l_2571;
	case 9590ULL: goto x86_l_2576;
	case 9596ULL: goto x86_l_257c;
	case 9601ULL: goto x86_l_2581;
	case 9609ULL: goto x86_l_2589;
	case 9613ULL: goto x86_l_258d;
	case 9620ULL: goto x86_l_2594;
	case 9625ULL: goto x86_l_2599;
	case 9630ULL: goto x86_l_259e;
	case 9632ULL: goto x86_l_25a0;
	case 9637ULL: goto x86_l_25a5;
	case 9645ULL: goto x86_l_25ad;
	case 9648ULL: goto x86_l_25b0;
	case 9656ULL: goto x86_l_25b8;
	case 9665ULL: goto x86_l_25c1;
	case 9672ULL: goto x86_l_25c8;
	case 9677ULL: goto x86_l_25cd;
	case 9682ULL: goto x86_l_25d2;
	case 9687ULL: goto x86_l_25d7;
	case 9689ULL: goto x86_l_25d9;
	case 9691ULL: goto x86_l_25db;
	case 9697ULL: goto x86_l_25e1;
	case 9703ULL: goto x86_l_25e7;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9730ULL: goto x86_l_2602;
	case 9734ULL: goto x86_l_2606;
	case 9741ULL: goto x86_l_260d;
	case 9746ULL: goto x86_l_2612;
	case 9751ULL: goto x86_l_2617;
	case 9753ULL: goto x86_l_2619;
	case 9757ULL: goto x86_l_261d;
	case 9759ULL: goto x86_l_261f;
	case 9761ULL: goto x86_l_2621;
	case 9767ULL: goto x86_l_2627;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9781ULL: goto x86_l_2635;
	case 9786ULL: goto x86_l_263a;
	case 9794ULL: goto x86_l_2642;
	case 9798ULL: goto x86_l_2646;
	case 9805ULL: goto x86_l_264d;
	case 9810ULL: goto x86_l_2652;
	case 9815ULL: goto x86_l_2657;
	case 9817ULL: goto x86_l_2659;
	case 9822ULL: goto x86_l_265e;
	case 9830ULL: goto x86_l_2666;
	case 9833ULL: goto x86_l_2669;
	case 9841ULL: goto x86_l_2671;
	case 9850ULL: goto x86_l_267a;
	case 9857ULL: goto x86_l_2681;
	case 9862ULL: goto x86_l_2686;
	case 9867ULL: goto x86_l_268b;
	case 9872ULL: goto x86_l_2690;
	case 9874ULL: goto x86_l_2692;
	case 9876ULL: goto x86_l_2694;
	case 9882ULL: goto x86_l_269a;
	case 9888ULL: goto x86_l_26a0;
	case 9891ULL: goto x86_l_26a3;
	case 9896ULL: goto x86_l_26a8;
	case 9902ULL: goto x86_l_26ae;
	case 9907ULL: goto x86_l_26b3;
	case 9915ULL: goto x86_l_26bb;
	case 9919ULL: goto x86_l_26bf;
	case 9926ULL: goto x86_l_26c6;
	case 9931ULL: goto x86_l_26cb;
	case 9936ULL: goto x86_l_26d0;
	case 9938ULL: goto x86_l_26d2;
	case 9942ULL: goto x86_l_26d6;
	case 9944ULL: goto x86_l_26d8;
	case 9946ULL: goto x86_l_26da;
	case 9952ULL: goto x86_l_26e0;
	case 9955ULL: goto x86_l_26e3;
	case 9960ULL: goto x86_l_26e8;
	case 9966ULL: goto x86_l_26ee;
	case 9971ULL: goto x86_l_26f3;
	case 9979ULL: goto x86_l_26fb;
	case 9983ULL: goto x86_l_26ff;
	case 9990ULL: goto x86_l_2706;
	case 9995ULL: goto x86_l_270b;
	case 10000ULL: goto x86_l_2710;
	case 10002ULL: goto x86_l_2712;
	case 10007ULL: goto x86_l_2717;
	case 10015ULL: goto x86_l_271f;
	case 10018ULL: goto x86_l_2722;
	case 10026ULL: goto x86_l_272a;
	case 10035ULL: goto x86_l_2733;
	case 10042ULL: goto x86_l_273a;
	case 10047ULL: goto x86_l_273f;
	case 10052ULL: goto x86_l_2744;
	case 10057ULL: goto x86_l_2749;
	case 10059ULL: goto x86_l_274b;
	case 10061ULL: goto x86_l_274d;
	case 10067ULL: goto x86_l_2753;
	case 10073ULL: goto x86_l_2759;
	case 10076ULL: goto x86_l_275c;
	case 10081ULL: goto x86_l_2761;
	case 10087ULL: goto x86_l_2767;
	case 10092ULL: goto x86_l_276c;
	case 10100ULL: goto x86_l_2774;
	case 10104ULL: goto x86_l_2778;
	case 10111ULL: goto x86_l_277f;
	case 10116ULL: goto x86_l_2784;
	case 10121ULL: goto x86_l_2789;
	case 10123ULL: goto x86_l_278b;
	case 10127ULL: goto x86_l_278f;
	case 10129ULL: goto x86_l_2791;
	case 10131ULL: goto x86_l_2793;
	case 10137ULL: goto x86_l_2799;
	case 10140ULL: goto x86_l_279c;
	case 10145ULL: goto x86_l_27a1;
	case 10151ULL: goto x86_l_27a7;
	case 10156ULL: goto x86_l_27ac;
	case 10164ULL: goto x86_l_27b4;
	case 10168ULL: goto x86_l_27b8;
	case 10175ULL: goto x86_l_27bf;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10187ULL: goto x86_l_27cb;
	case 10192ULL: goto x86_l_27d0;
	case 10200ULL: goto x86_l_27d8;
	case 10203ULL: goto x86_l_27db;
	case 10211ULL: goto x86_l_27e3;
	case 10220ULL: goto x86_l_27ec;
	case 10227ULL: goto x86_l_27f3;
	case 10232ULL: goto x86_l_27f8;
	case 10237ULL: goto x86_l_27fd;
	case 10242ULL: goto x86_l_2802;
	case 10244ULL: goto x86_l_2804;
	case 10246ULL: goto x86_l_2806;
	case 10252ULL: goto x86_l_280c;
	case 10258ULL: goto x86_l_2812;
	case 10261ULL: goto x86_l_2815;
	case 10266ULL: goto x86_l_281a;
	case 10272ULL: goto x86_l_2820;
	case 10277ULL: goto x86_l_2825;
	case 10285ULL: goto x86_l_282d;
	case 10289ULL: goto x86_l_2831;
	case 10296ULL: goto x86_l_2838;
	case 10301ULL: goto x86_l_283d;
	case 10306ULL: goto x86_l_2842;
	case 10308ULL: goto x86_l_2844;
	case 10312ULL: goto x86_l_2848;
	case 10314ULL: goto x86_l_284a;
	case 10316ULL: goto x86_l_284c;
	case 10322ULL: goto x86_l_2852;
	case 10325ULL: goto x86_l_2855;
	case 10330ULL: goto x86_l_285a;
	case 10336ULL: goto x86_l_2860;
	case 10341ULL: goto x86_l_2865;
	case 10349ULL: goto x86_l_286d;
	case 10353ULL: goto x86_l_2871;
	case 10360ULL: goto x86_l_2878;
	case 10365ULL: goto x86_l_287d;
	case 10370ULL: goto x86_l_2882;
	case 10372ULL: goto x86_l_2884;
	case 10377ULL: goto x86_l_2889;
	case 10385ULL: goto x86_l_2891;
	case 10388ULL: goto x86_l_2894;
	case 10396ULL: goto x86_l_289c;
	case 10405ULL: goto x86_l_28a5;
	case 10412ULL: goto x86_l_28ac;
	case 10417ULL: goto x86_l_28b1;
	case 10422ULL: goto x86_l_28b6;
	case 10427ULL: goto x86_l_28bb;
	case 10429ULL: goto x86_l_28bd;
	case 10431ULL: goto x86_l_28bf;
	case 10437ULL: goto x86_l_28c5;
	case 10443ULL: goto x86_l_28cb;
	case 10446ULL: goto x86_l_28ce;
	case 10451ULL: goto x86_l_28d3;
	case 10457ULL: goto x86_l_28d9;
	case 10462ULL: goto x86_l_28de;
	case 10470ULL: goto x86_l_28e6;
	case 10474ULL: goto x86_l_28ea;
	case 10481ULL: goto x86_l_28f1;
	case 10486ULL: goto x86_l_28f6;
	case 10491ULL: goto x86_l_28fb;
	case 10493ULL: goto x86_l_28fd;
	case 10497ULL: goto x86_l_2901;
	case 10499ULL: goto x86_l_2903;
	case 10501ULL: goto x86_l_2905;
	case 10507ULL: goto x86_l_290b;
	case 10510ULL: goto x86_l_290e;
	case 10515ULL: goto x86_l_2913;
	case 10521ULL: goto x86_l_2919;
	case 10526ULL: goto x86_l_291e;
	case 10534ULL: goto x86_l_2926;
	case 10538ULL: goto x86_l_292a;
	case 10545ULL: goto x86_l_2931;
	case 10550ULL: goto x86_l_2936;
	case 10555ULL: goto x86_l_293b;
	case 10557ULL: goto x86_l_293d;
	case 10562ULL: goto x86_l_2942;
	case 10570ULL: goto x86_l_294a;
	case 10573ULL: goto x86_l_294d;
	case 10581ULL: goto x86_l_2955;
	case 10590ULL: goto x86_l_295e;
	case 10597ULL: goto x86_l_2965;
	case 10602ULL: goto x86_l_296a;
	case 10607ULL: goto x86_l_296f;
	case 10612ULL: goto x86_l_2974;
	case 10614ULL: goto x86_l_2976;
	case 10616ULL: goto x86_l_2978;
	case 10622ULL: goto x86_l_297e;
	case 10628ULL: goto x86_l_2984;
	case 10631ULL: goto x86_l_2987;
	case 10636ULL: goto x86_l_298c;
	case 10642ULL: goto x86_l_2992;
	case 10647ULL: goto x86_l_2997;
	case 10655ULL: goto x86_l_299f;
	case 10659ULL: goto x86_l_29a3;
	case 10666ULL: goto x86_l_29aa;
	case 10671ULL: goto x86_l_29af;
	case 10676ULL: goto x86_l_29b4;
	case 10678ULL: goto x86_l_29b6;
	case 10682ULL: goto x86_l_29ba;
	case 10684ULL: goto x86_l_29bc;
	case 10686ULL: goto x86_l_29be;
	case 10692ULL: goto x86_l_29c4;
	case 10695ULL: goto x86_l_29c7;
	case 10700ULL: goto x86_l_29cc;
	case 10706ULL: goto x86_l_29d2;
	case 10711ULL: goto x86_l_29d7;
	case 10719ULL: goto x86_l_29df;
	case 10723ULL: goto x86_l_29e3;
	case 10730ULL: goto x86_l_29ea;
	case 10735ULL: goto x86_l_29ef;
	case 10740ULL: goto x86_l_29f4;
	case 10742ULL: goto x86_l_29f6;
	case 10747ULL: goto x86_l_29fb;
	case 10755ULL: goto x86_l_2a03;
	case 10758ULL: goto x86_l_2a06;
	case 10766ULL: goto x86_l_2a0e;
	case 10775ULL: goto x86_l_2a17;
	case 10782ULL: goto x86_l_2a1e;
	case 10787ULL: goto x86_l_2a23;
	case 10792ULL: goto x86_l_2a28;
	case 10797ULL: goto x86_l_2a2d;
	case 10799ULL: goto x86_l_2a2f;
	case 10801ULL: goto x86_l_2a31;
	case 10807ULL: goto x86_l_2a37;
	case 10813ULL: goto x86_l_2a3d;
	case 10816ULL: goto x86_l_2a40;
	case 10821ULL: goto x86_l_2a45;
	case 10827ULL: goto x86_l_2a4b;
	case 10832ULL: goto x86_l_2a50;
	case 10840ULL: goto x86_l_2a58;
	case 10844ULL: goto x86_l_2a5c;
	case 10851ULL: goto x86_l_2a63;
	case 10856ULL: goto x86_l_2a68;
	case 10861ULL: goto x86_l_2a6d;
	case 10863ULL: goto x86_l_2a6f;
	case 10867ULL: goto x86_l_2a73;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22f7:
	/* 0x22f7: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_22fd:
	/* 0x22fd: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_2303:
	/* 0x2303: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2306:
	/* 0x2306: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_230b:
	/* 0x230b: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2311:
	/* 0x2311: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2316:
	/* 0x2316: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_231e:
	/* 0x231e: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2322:
	/* 0x2322: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2329:
	/* 0x2329: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_232e:
	/* 0x232e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2333:
	/* 0x2333: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2335:
	/* 0x2335: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2339:
	/* 0x2339: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_233b:
	/* 0x233b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_233d:
	/* 0x233d: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2343:
	/* 0x2343: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2346:
	/* 0x2346: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_234b:
	/* 0x234b: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2351:
	/* 0x2351: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2356:
	/* 0x2356: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_235e:
	/* 0x235e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2362:
	/* 0x2362: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2369:
	/* 0x2369: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_236e:
	/* 0x236e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2373:
	/* 0x2373: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2375:
	/* 0x2375: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_237a:
	/* 0x237a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2382:
	/* 0x2382: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2385:
	/* 0x2385: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_238d:
	/* 0x238d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2396:
	/* 0x2396: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_239d:
	/* 0x239d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23a2:
	/* 0x23a2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23a7:
	/* 0x23a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23ac:
	/* 0x23ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ae:
	/* 0x23ae: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_23b0:
	/* 0x23b0: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_23b6:
	/* 0x23b6: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_23bc:
	/* 0x23bc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23bf:
	/* 0x23bf: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_23c4:
	/* 0x23c4: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_23ca:
	/* 0x23ca: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_23cf:
	/* 0x23cf: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_23d7:
	/* 0x23d7: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_23db:
	/* 0x23db: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_23e2:
	/* 0x23e2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23e7:
	/* 0x23e7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_23ec:
	/* 0x23ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ee:
	/* 0x23ee: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23f2:
	/* 0x23f2: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_23f4:
	/* 0x23f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23f6:
	/* 0x23f6: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_23fc:
	/* 0x23fc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23ff:
	/* 0x23ff: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2404:
	/* 0x2404: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_240a:
	/* 0x240a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_240f:
	/* 0x240f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2417:
	/* 0x2417: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_241b:
	/* 0x241b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2422:
	/* 0x2422: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2427:
	/* 0x2427: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_242c:
	/* 0x242c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_242e:
	/* 0x242e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2433:
	/* 0x2433: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_243b:
	/* 0x243b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_243e:
	/* 0x243e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2446:
	/* 0x2446: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_244f:
	/* 0x244f: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2456:
	/* 0x2456: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_245b:
	/* 0x245b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2460:
	/* 0x2460: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2465:
	/* 0x2465: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2467:
	/* 0x2467: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_2469:
	/* 0x2469: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_246f:
	/* 0x246f: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_2475:
	/* 0x2475: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2478:
	/* 0x2478: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_247d:
	/* 0x247d: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2483:
	/* 0x2483: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2488:
	/* 0x2488: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2490:
	/* 0x2490: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2494:
	/* 0x2494: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_249b:
	/* 0x249b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24a0:
	/* 0x24a0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_24a5:
	/* 0x24a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a7:
	/* 0x24a7: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_24ab:
	/* 0x24ab: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_24ad:
	/* 0x24ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24af:
	/* 0x24af: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_24b5:
	/* 0x24b5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24b8:
	/* 0x24b8: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_24bd:
	/* 0x24bd: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_24c3:
	/* 0x24c3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24c8:
	/* 0x24c8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_24d0:
	/* 0x24d0: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_24d4:
	/* 0x24d4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_24db:
	/* 0x24db: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_24e0:
	/* 0x24e0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_24e5:
	/* 0x24e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e7:
	/* 0x24e7: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_24ec:
	/* 0x24ec: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_24f4:
	/* 0x24f4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_24f7:
	/* 0x24f7: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_24ff:
	/* 0x24ff: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2508:
	/* 0x2508: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_250f:
	/* 0x250f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2514:
	/* 0x2514: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2519:
	/* 0x2519: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_251e:
	/* 0x251e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2520:
	/* 0x2520: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_2522:
	/* 0x2522: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2528:
	/* 0x2528: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_252e:
	/* 0x252e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2531:
	/* 0x2531: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2536:
	/* 0x2536: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_253c:
	/* 0x253c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2541:
	/* 0x2541: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2549:
	/* 0x2549: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_254d:
	/* 0x254d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2554:
	/* 0x2554: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2559:
	/* 0x2559: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_255e:
	/* 0x255e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2560:
	/* 0x2560: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2564:
	/* 0x2564: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_2566:
	/* 0x2566: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2568:
	/* 0x2568: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_256e:
	/* 0x256e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2571:
	/* 0x2571: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2576:
	/* 0x2576: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_257c:
	/* 0x257c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2581:
	/* 0x2581: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2589:
	/* 0x2589: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_258d:
	/* 0x258d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2594:
	/* 0x2594: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2599:
	/* 0x2599: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_259e:
	/* 0x259e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a0:
	/* 0x25a0: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_25a5:
	/* 0x25a5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_25ad:
	/* 0x25ad: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_25b0:
	/* 0x25b0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_25b8:
	/* 0x25b8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_25c1:
	/* 0x25c1: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_25c8:
	/* 0x25c8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25cd:
	/* 0x25cd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25d2:
	/* 0x25d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25d7:
	/* 0x25d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d9:
	/* 0x25d9: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_25db:
	/* 0x25db: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_25e1:
	/* 0x25e1: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_25e7:
	/* 0x25e7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25ea:
	/* 0x25ea: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_25ef:
	/* 0x25ef: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_25f5:
	/* 0x25f5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_25fa:
	/* 0x25fa: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2602:
	/* 0x2602: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2606:
	/* 0x2606: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_260d:
	/* 0x260d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2612:
	/* 0x2612: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2617:
	/* 0x2617: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2619:
	/* 0x2619: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_261d:
	/* 0x261d: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_261f:
	/* 0x261f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2621:
	/* 0x2621: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2627:
	/* 0x2627: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_262a:
	/* 0x262a: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_262f:
	/* 0x262f: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2635:
	/* 0x2635: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_263a:
	/* 0x263a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2642:
	/* 0x2642: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2646:
	/* 0x2646: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_264d:
	/* 0x264d: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2652:
	/* 0x2652: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2657:
	/* 0x2657: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2659:
	/* 0x2659: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_265e:
	/* 0x265e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2666:
	/* 0x2666: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2669:
	/* 0x2669: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2671:
	/* 0x2671: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_267a:
	/* 0x267a: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2681:
	/* 0x2681: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2686:
	/* 0x2686: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_268b:
	/* 0x268b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2690:
	/* 0x2690: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2692:
	/* 0x2692: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_2694:
	/* 0x2694: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_269a:
	/* 0x269a: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_26a0:
	/* 0x26a0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26a3:
	/* 0x26a3: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_26a8:
	/* 0x26a8: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_26ae:
	/* 0x26ae: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_26b3:
	/* 0x26b3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_26bb:
	/* 0x26bb: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_26bf:
	/* 0x26bf: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_26c6:
	/* 0x26c6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26cb:
	/* 0x26cb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_26d0:
	/* 0x26d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d2:
	/* 0x26d2: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_26d6:
	/* 0x26d6: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_26d8:
	/* 0x26d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26da:
	/* 0x26da: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_26e0:
	/* 0x26e0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26e3:
	/* 0x26e3: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_26e8:
	/* 0x26e8: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_26ee:
	/* 0x26ee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26f3:
	/* 0x26f3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_26fb:
	/* 0x26fb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_26ff:
	/* 0x26ff: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2706:
	/* 0x2706: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_270b:
	/* 0x270b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2710:
	/* 0x2710: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2712:
	/* 0x2712: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2717:
	/* 0x2717: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_271f:
	/* 0x271f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2722:
	/* 0x2722: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_272a:
	/* 0x272a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2733:
	/* 0x2733: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_273a:
	/* 0x273a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_273f:
	/* 0x273f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2744:
	/* 0x2744: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2749:
	/* 0x2749: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_274b:
	/* 0x274b: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_274d:
	/* 0x274d: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2753:
	/* 0x2753: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_2759:
	/* 0x2759: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_275c:
	/* 0x275c: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2761:
	/* 0x2761: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2767:
	/* 0x2767: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_276c:
	/* 0x276c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2774:
	/* 0x2774: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2778:
	/* 0x2778: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_277f:
	/* 0x277f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2784:
	/* 0x2784: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2789:
	/* 0x2789: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_278b:
	/* 0x278b: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_278f:
	/* 0x278f: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_2791:
	/* 0x2791: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2793:
	/* 0x2793: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2799:
	/* 0x2799: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_279c:
	/* 0x279c: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_27a1:
	/* 0x27a1: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_27a7:
	/* 0x27a7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27ac:
	/* 0x27ac: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_27b4:
	/* 0x27b4: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_27b8:
	/* 0x27b8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_27bf:
	/* 0x27bf: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_27c4:
	/* 0x27c4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_27c9:
	/* 0x27c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27cb:
	/* 0x27cb: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_27d0:
	/* 0x27d0: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_27d8:
	/* 0x27d8: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_27db:
	/* 0x27db: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_27e3:
	/* 0x27e3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_27ec:
	/* 0x27ec: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_27f3:
	/* 0x27f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27f8:
	/* 0x27f8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27fd:
	/* 0x27fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2802:
	/* 0x2802: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2804:
	/* 0x2804: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_2806:
	/* 0x2806: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_280c:
	/* 0x280c: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_2812:
	/* 0x2812: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2815:
	/* 0x2815: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_281a:
	/* 0x281a: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2820:
	/* 0x2820: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2825:
	/* 0x2825: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_282d:
	/* 0x282d: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2831:
	/* 0x2831: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2838:
	/* 0x2838: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_283d:
	/* 0x283d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2842:
	/* 0x2842: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2844:
	/* 0x2844: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2848:
	/* 0x2848: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_284a:
	/* 0x284a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_284c:
	/* 0x284c: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2852:
	/* 0x2852: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2855:
	/* 0x2855: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_285a:
	/* 0x285a: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2860:
	/* 0x2860: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2865:
	/* 0x2865: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_286d:
	/* 0x286d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2871:
	/* 0x2871: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2878:
	/* 0x2878: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_287d:
	/* 0x287d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2882:
	/* 0x2882: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2884:
	/* 0x2884: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2889:
	/* 0x2889: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2891:
	/* 0x2891: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2894:
	/* 0x2894: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_289c:
	/* 0x289c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_28a5:
	/* 0x28a5: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_28ac:
	/* 0x28ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28b1:
	/* 0x28b1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28b6:
	/* 0x28b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28bb:
	/* 0x28bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28bd:
	/* 0x28bd: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_28bf:
	/* 0x28bf: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_28c5:
	/* 0x28c5: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_28cb:
	/* 0x28cb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28ce:
	/* 0x28ce: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_28d3:
	/* 0x28d3: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_28d9:
	/* 0x28d9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_28de:
	/* 0x28de: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_28e6:
	/* 0x28e6: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_28ea:
	/* 0x28ea: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_28f1:
	/* 0x28f1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28f6:
	/* 0x28f6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_28fb:
	/* 0x28fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28fd:
	/* 0x28fd: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2901:
	/* 0x2901: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_2903:
	/* 0x2903: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2905:
	/* 0x2905: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_290b:
	/* 0x290b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_290e:
	/* 0x290e: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2913:
	/* 0x2913: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2919:
	/* 0x2919: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_291e:
	/* 0x291e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2926:
	/* 0x2926: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_292a:
	/* 0x292a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2931:
	/* 0x2931: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2936:
	/* 0x2936: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_293b:
	/* 0x293b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_293d:
	/* 0x293d: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2942:
	/* 0x2942: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_294a:
	/* 0x294a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_294d:
	/* 0x294d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2955:
	/* 0x2955: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_295e:
	/* 0x295e: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2965:
	/* 0x2965: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_296a:
	/* 0x296a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_296f:
	/* 0x296f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2974:
	/* 0x2974: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2976:
	/* 0x2976: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_2978:
	/* 0x2978: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_297e:
	/* 0x297e: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_2984:
	/* 0x2984: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2987:
	/* 0x2987: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_298c:
	/* 0x298c: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2992:
	/* 0x2992: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2997:
	/* 0x2997: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_299f:
	/* 0x299f: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_29a3:
	/* 0x29a3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_29aa:
	/* 0x29aa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29af:
	/* 0x29af: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_29b4:
	/* 0x29b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b6:
	/* 0x29b6: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_29ba:
	/* 0x29ba: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_29bc:
	/* 0x29bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29be:
	/* 0x29be: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_29c4:
	/* 0x29c4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29c7:
	/* 0x29c7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_29cc:
	/* 0x29cc: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_29d2:
	/* 0x29d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29d7:
	/* 0x29d7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_29df:
	/* 0x29df: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_29e3:
	/* 0x29e3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_29ea:
	/* 0x29ea: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_29ef:
	/* 0x29ef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29f4:
	/* 0x29f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f6:
	/* 0x29f6: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_29fb:
	/* 0x29fb: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2a03:
	/* 0x2a03: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2a06:
	/* 0x2a06: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2a0e:
	/* 0x2a0e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2a17:
	/* 0x2a17: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2a1e:
	/* 0x2a1e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a23:
	/* 0x2a23: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a28:
	/* 0x2a28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a2d:
	/* 0x2a2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a2f:
	/* 0x2a2f: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_2a31:
	/* 0x2a31: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2a37:
	/* 0x2a37: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_2a3d:
	/* 0x2a3d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a40:
	/* 0x2a40: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2a45:
	/* 0x2a45: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2a4b:
	/* 0x2a4b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2a50:
	/* 0x2a50: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a58:
	/* 0x2a58: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2a5c:
	/* 0x2a5c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2a63:
	/* 0x2a63: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a68:
	/* 0x2a68: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2a6d:
	/* 0x2a6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a6f:
	/* 0x2a6f: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2a73:
	/* 0x2a73: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
	return 10869ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10869ULL: goto x86_l_2a75;
	case 10871ULL: goto x86_l_2a77;
	case 10877ULL: goto x86_l_2a7d;
	case 10880ULL: goto x86_l_2a80;
	case 10885ULL: goto x86_l_2a85;
	case 10891ULL: goto x86_l_2a8b;
	case 10896ULL: goto x86_l_2a90;
	case 10904ULL: goto x86_l_2a98;
	case 10908ULL: goto x86_l_2a9c;
	case 10915ULL: goto x86_l_2aa3;
	case 10920ULL: goto x86_l_2aa8;
	case 10925ULL: goto x86_l_2aad;
	case 10927ULL: goto x86_l_2aaf;
	case 10932ULL: goto x86_l_2ab4;
	case 10940ULL: goto x86_l_2abc;
	case 10943ULL: goto x86_l_2abf;
	case 10951ULL: goto x86_l_2ac7;
	case 10960ULL: goto x86_l_2ad0;
	case 10967ULL: goto x86_l_2ad7;
	case 10972ULL: goto x86_l_2adc;
	case 10977ULL: goto x86_l_2ae1;
	case 10982ULL: goto x86_l_2ae6;
	case 10985ULL: goto x86_l_2ae9;
	case 10987ULL: goto x86_l_2aeb;
	case 10989ULL: goto x86_l_2aed;
	case 10995ULL: goto x86_l_2af3;
	case 11001ULL: goto x86_l_2af9;
	case 11004ULL: goto x86_l_2afc;
	case 11009ULL: goto x86_l_2b01;
	case 11015ULL: goto x86_l_2b07;
	case 11020ULL: goto x86_l_2b0c;
	case 11028ULL: goto x86_l_2b14;
	case 11032ULL: goto x86_l_2b18;
	case 11039ULL: goto x86_l_2b1f;
	case 11044ULL: goto x86_l_2b24;
	case 11049ULL: goto x86_l_2b29;
	case 11051ULL: goto x86_l_2b2b;
	case 11055ULL: goto x86_l_2b2f;
	case 11057ULL: goto x86_l_2b31;
	case 11059ULL: goto x86_l_2b33;
	case 11065ULL: goto x86_l_2b39;
	case 11068ULL: goto x86_l_2b3c;
	case 11073ULL: goto x86_l_2b41;
	case 11079ULL: goto x86_l_2b47;
	case 11084ULL: goto x86_l_2b4c;
	case 11092ULL: goto x86_l_2b54;
	case 11096ULL: goto x86_l_2b58;
	case 11103ULL: goto x86_l_2b5f;
	case 11108ULL: goto x86_l_2b64;
	case 11113ULL: goto x86_l_2b69;
	case 11115ULL: goto x86_l_2b6b;
	case 11120ULL: goto x86_l_2b70;
	case 11128ULL: goto x86_l_2b78;
	case 11131ULL: goto x86_l_2b7b;
	case 11139ULL: goto x86_l_2b83;
	case 11150ULL: goto x86_l_2b8e;
	case 11153ULL: goto x86_l_2b91;
	case 11158ULL: goto x86_l_2b96;
	case 11160ULL: goto x86_l_2b98;
	case 11165ULL: goto x86_l_2b9d;
	case 11170ULL: goto x86_l_2ba2;
	case 11178ULL: goto x86_l_2baa;
	case 11182ULL: goto x86_l_2bae;
	case 11189ULL: goto x86_l_2bb5;
	case 11197ULL: goto x86_l_2bbd;
	case 11202ULL: goto x86_l_2bc2;
	case 11204ULL: goto x86_l_2bc4;
	case 11208ULL: goto x86_l_2bc8;
	case 11210ULL: goto x86_l_2bca;
	case 11212ULL: goto x86_l_2bcc;
	case 11218ULL: goto x86_l_2bd2;
	case 11221ULL: goto x86_l_2bd5;
	case 11226ULL: goto x86_l_2bda;
	case 11231ULL: goto x86_l_2bdf;
	case 11237ULL: goto x86_l_2be5;
	case 11242ULL: goto x86_l_2bea;
	case 11250ULL: goto x86_l_2bf2;
	case 11254ULL: goto x86_l_2bf6;
	case 11261ULL: goto x86_l_2bfd;
	case 11266ULL: goto x86_l_2c02;
	case 11271ULL: goto x86_l_2c07;
	case 11273ULL: goto x86_l_2c09;
	case 11278ULL: goto x86_l_2c0e;
	case 11286ULL: goto x86_l_2c16;
	case 11289ULL: goto x86_l_2c19;
	case 11297ULL: goto x86_l_2c21;
	case 11299ULL: goto x86_l_2c23;
	case 11304ULL: goto x86_l_2c28;
	case 11309ULL: goto x86_l_2c2d;
	case 11317ULL: goto x86_l_2c35;
	case 11321ULL: goto x86_l_2c39;
	case 11328ULL: goto x86_l_2c40;
	case 11333ULL: goto x86_l_2c45;
	case 11338ULL: goto x86_l_2c4a;
	case 11340ULL: goto x86_l_2c4c;
	case 11345ULL: goto x86_l_2c51;
	case 11353ULL: goto x86_l_2c59;
	case 11356ULL: goto x86_l_2c5c;
	case 11364ULL: goto x86_l_2c64;
	case 11373ULL: goto x86_l_2c6d;
	case 11377ULL: goto x86_l_2c71;
	case 11382ULL: goto x86_l_2c76;
	case 11387ULL: goto x86_l_2c7b;
	case 11392ULL: goto x86_l_2c80;
	case 11394ULL: goto x86_l_2c82;
	case 11396ULL: goto x86_l_2c84;
	case 11402ULL: goto x86_l_2c8a;
	case 11408ULL: goto x86_l_2c90;
	case 11411ULL: goto x86_l_2c93;
	case 11416ULL: goto x86_l_2c98;
	case 11422ULL: goto x86_l_2c9e;
	case 11427ULL: goto x86_l_2ca3;
	case 11435ULL: goto x86_l_2cab;
	case 11439ULL: goto x86_l_2caf;
	case 11446ULL: goto x86_l_2cb6;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11458ULL: goto x86_l_2cc2;
	case 11462ULL: goto x86_l_2cc6;
	case 11464ULL: goto x86_l_2cc8;
	case 11466ULL: goto x86_l_2cca;
	case 11472ULL: goto x86_l_2cd0;
	case 11475ULL: goto x86_l_2cd3;
	case 11480ULL: goto x86_l_2cd8;
	case 11486ULL: goto x86_l_2cde;
	case 11491ULL: goto x86_l_2ce3;
	case 11499ULL: goto x86_l_2ceb;
	case 11503ULL: goto x86_l_2cef;
	case 11510ULL: goto x86_l_2cf6;
	case 11515ULL: goto x86_l_2cfb;
	case 11520ULL: goto x86_l_2d00;
	case 11522ULL: goto x86_l_2d02;
	case 11527ULL: goto x86_l_2d07;
	case 11535ULL: goto x86_l_2d0f;
	case 11538ULL: goto x86_l_2d12;
	case 11546ULL: goto x86_l_2d1a;
	case 11555ULL: goto x86_l_2d23;
	case 11559ULL: goto x86_l_2d27;
	case 11564ULL: goto x86_l_2d2c;
	case 11569ULL: goto x86_l_2d31;
	case 11574ULL: goto x86_l_2d36;
	case 11576ULL: goto x86_l_2d38;
	case 11578ULL: goto x86_l_2d3a;
	case 11584ULL: goto x86_l_2d40;
	case 11590ULL: goto x86_l_2d46;
	case 11593ULL: goto x86_l_2d49;
	case 11598ULL: goto x86_l_2d4e;
	case 11604ULL: goto x86_l_2d54;
	case 11609ULL: goto x86_l_2d59;
	case 11617ULL: goto x86_l_2d61;
	case 11621ULL: goto x86_l_2d65;
	case 11628ULL: goto x86_l_2d6c;
	case 11633ULL: goto x86_l_2d71;
	case 11638ULL: goto x86_l_2d76;
	case 11640ULL: goto x86_l_2d78;
	case 11644ULL: goto x86_l_2d7c;
	case 11646ULL: goto x86_l_2d7e;
	case 11648ULL: goto x86_l_2d80;
	case 11654ULL: goto x86_l_2d86;
	case 11657ULL: goto x86_l_2d89;
	case 11662ULL: goto x86_l_2d8e;
	case 11668ULL: goto x86_l_2d94;
	case 11673ULL: goto x86_l_2d99;
	case 11681ULL: goto x86_l_2da1;
	case 11685ULL: goto x86_l_2da5;
	case 11692ULL: goto x86_l_2dac;
	case 11697ULL: goto x86_l_2db1;
	case 11702ULL: goto x86_l_2db6;
	case 11704ULL: goto x86_l_2db8;
	case 11709ULL: goto x86_l_2dbd;
	case 11717ULL: goto x86_l_2dc5;
	case 11720ULL: goto x86_l_2dc8;
	case 11728ULL: goto x86_l_2dd0;
	case 11737ULL: goto x86_l_2dd9;
	case 11741ULL: goto x86_l_2ddd;
	case 11746ULL: goto x86_l_2de2;
	case 11751ULL: goto x86_l_2de7;
	case 11756ULL: goto x86_l_2dec;
	case 11758ULL: goto x86_l_2dee;
	case 11760ULL: goto x86_l_2df0;
	case 11766ULL: goto x86_l_2df6;
	case 11772ULL: goto x86_l_2dfc;
	case 11775ULL: goto x86_l_2dff;
	case 11780ULL: goto x86_l_2e04;
	case 11786ULL: goto x86_l_2e0a;
	case 11791ULL: goto x86_l_2e0f;
	case 11799ULL: goto x86_l_2e17;
	case 11803ULL: goto x86_l_2e1b;
	case 11810ULL: goto x86_l_2e22;
	case 11815ULL: goto x86_l_2e27;
	case 11820ULL: goto x86_l_2e2c;
	case 11822ULL: goto x86_l_2e2e;
	case 11826ULL: goto x86_l_2e32;
	case 11828ULL: goto x86_l_2e34;
	case 11830ULL: goto x86_l_2e36;
	case 11836ULL: goto x86_l_2e3c;
	case 11839ULL: goto x86_l_2e3f;
	case 11844ULL: goto x86_l_2e44;
	case 11850ULL: goto x86_l_2e4a;
	case 11855ULL: goto x86_l_2e4f;
	case 11863ULL: goto x86_l_2e57;
	case 11867ULL: goto x86_l_2e5b;
	case 11874ULL: goto x86_l_2e62;
	case 11879ULL: goto x86_l_2e67;
	case 11884ULL: goto x86_l_2e6c;
	case 11886ULL: goto x86_l_2e6e;
	case 11891ULL: goto x86_l_2e73;
	case 11899ULL: goto x86_l_2e7b;
	case 11902ULL: goto x86_l_2e7e;
	case 11910ULL: goto x86_l_2e86;
	case 11919ULL: goto x86_l_2e8f;
	case 11923ULL: goto x86_l_2e93;
	case 11928ULL: goto x86_l_2e98;
	case 11933ULL: goto x86_l_2e9d;
	case 11938ULL: goto x86_l_2ea2;
	case 11940ULL: goto x86_l_2ea4;
	case 11942ULL: goto x86_l_2ea6;
	case 11948ULL: goto x86_l_2eac;
	case 11954ULL: goto x86_l_2eb2;
	case 11957ULL: goto x86_l_2eb5;
	case 11962ULL: goto x86_l_2eba;
	case 11968ULL: goto x86_l_2ec0;
	case 11973ULL: goto x86_l_2ec5;
	case 11981ULL: goto x86_l_2ecd;
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
	case 12026ULL: goto x86_l_2efa;
	case 12032ULL: goto x86_l_2f00;
	case 12037ULL: goto x86_l_2f05;
	case 12045ULL: goto x86_l_2f0d;
	case 12049ULL: goto x86_l_2f11;
	case 12056ULL: goto x86_l_2f18;
	case 12061ULL: goto x86_l_2f1d;
	case 12066ULL: goto x86_l_2f22;
	case 12068ULL: goto x86_l_2f24;
	case 12073ULL: goto x86_l_2f29;
	case 12081ULL: goto x86_l_2f31;
	case 12084ULL: goto x86_l_2f34;
	case 12092ULL: goto x86_l_2f3c;
	case 12101ULL: goto x86_l_2f45;
	case 12105ULL: goto x86_l_2f49;
	case 12110ULL: goto x86_l_2f4e;
	case 12115ULL: goto x86_l_2f53;
	case 12120ULL: goto x86_l_2f58;
	case 12122ULL: goto x86_l_2f5a;
	case 12124ULL: goto x86_l_2f5c;
	case 12130ULL: goto x86_l_2f62;
	case 12136ULL: goto x86_l_2f68;
	case 12139ULL: goto x86_l_2f6b;
	case 12144ULL: goto x86_l_2f70;
	case 12150ULL: goto x86_l_2f76;
	case 12155ULL: goto x86_l_2f7b;
	case 12163ULL: goto x86_l_2f83;
	case 12167ULL: goto x86_l_2f87;
	case 12174ULL: goto x86_l_2f8e;
	case 12179ULL: goto x86_l_2f93;
	case 12184ULL: goto x86_l_2f98;
	case 12186ULL: goto x86_l_2f9a;
	case 12190ULL: goto x86_l_2f9e;
	case 12192ULL: goto x86_l_2fa0;
	case 12194ULL: goto x86_l_2fa2;
	case 12200ULL: goto x86_l_2fa8;
	case 12203ULL: goto x86_l_2fab;
	case 12208ULL: goto x86_l_2fb0;
	case 12214ULL: goto x86_l_2fb6;
	case 12219ULL: goto x86_l_2fbb;
	case 12227ULL: goto x86_l_2fc3;
	case 12231ULL: goto x86_l_2fc7;
	case 12238ULL: goto x86_l_2fce;
	case 12243ULL: goto x86_l_2fd3;
	case 12248ULL: goto x86_l_2fd8;
	case 12250ULL: goto x86_l_2fda;
	case 12255ULL: goto x86_l_2fdf;
	case 12263ULL: goto x86_l_2fe7;
	case 12266ULL: goto x86_l_2fea;
	case 12274ULL: goto x86_l_2ff2;
	case 12283ULL: goto x86_l_2ffb;
	case 12287ULL: goto x86_l_2fff;
	case 12292ULL: goto x86_l_3004;
	case 12297ULL: goto x86_l_3009;
	case 12302ULL: goto x86_l_300e;
	case 12304ULL: goto x86_l_3010;
	case 12306ULL: goto x86_l_3012;
	case 12312ULL: goto x86_l_3018;
	case 12318ULL: goto x86_l_301e;
	case 12321ULL: goto x86_l_3021;
	case 12326ULL: goto x86_l_3026;
	case 12332ULL: goto x86_l_302c;
	case 12337ULL: goto x86_l_3031;
	case 12345ULL: goto x86_l_3039;
	case 12349ULL: goto x86_l_303d;
	case 12356ULL: goto x86_l_3044;
	case 12361ULL: goto x86_l_3049;
	case 12366ULL: goto x86_l_304e;
	case 12368ULL: goto x86_l_3050;
	case 12372ULL: goto x86_l_3054;
	case 12374ULL: goto x86_l_3056;
	case 12376ULL: goto x86_l_3058;
	case 12382ULL: goto x86_l_305e;
	case 12385ULL: goto x86_l_3061;
	case 12390ULL: goto x86_l_3066;
	case 12396ULL: goto x86_l_306c;
	case 12401ULL: goto x86_l_3071;
	case 12409ULL: goto x86_l_3079;
	case 12413ULL: goto x86_l_307d;
	case 12420ULL: goto x86_l_3084;
	case 12425ULL: goto x86_l_3089;
	case 12430ULL: goto x86_l_308e;
	case 12432ULL: goto x86_l_3090;
	case 12437ULL: goto x86_l_3095;
	case 12445ULL: goto x86_l_309d;
	case 12448ULL: goto x86_l_30a0;
	case 12456ULL: goto x86_l_30a8;
	case 12465ULL: goto x86_l_30b1;
	case 12469ULL: goto x86_l_30b5;
	case 12474ULL: goto x86_l_30ba;
	case 12479ULL: goto x86_l_30bf;
	case 12484ULL: goto x86_l_30c4;
	case 12486ULL: goto x86_l_30c6;
	case 12488ULL: goto x86_l_30c8;
	case 12494ULL: goto x86_l_30ce;
	case 12500ULL: goto x86_l_30d4;
	case 12503ULL: goto x86_l_30d7;
	case 12508ULL: goto x86_l_30dc;
	case 12514ULL: goto x86_l_30e2;
	case 12519ULL: goto x86_l_30e7;
	case 12527ULL: goto x86_l_30ef;
	case 12531ULL: goto x86_l_30f3;
	case 12538ULL: goto x86_l_30fa;
	case 12543ULL: goto x86_l_30ff;
	case 12548ULL: goto x86_l_3104;
	case 12550ULL: goto x86_l_3106;
	case 12554ULL: goto x86_l_310a;
	case 12556ULL: goto x86_l_310c;
	case 12558ULL: goto x86_l_310e;
	case 12564ULL: goto x86_l_3114;
	case 12567ULL: goto x86_l_3117;
	case 12572ULL: goto x86_l_311c;
	case 12578ULL: goto x86_l_3122;
	case 12583ULL: goto x86_l_3127;
	case 12591ULL: goto x86_l_312f;
	case 12595ULL: goto x86_l_3133;
	case 12602ULL: goto x86_l_313a;
	case 12607ULL: goto x86_l_313f;
	case 12612ULL: goto x86_l_3144;
	case 12614ULL: goto x86_l_3146;
	case 12619ULL: goto x86_l_314b;
	case 12627ULL: goto x86_l_3153;
	case 12630ULL: goto x86_l_3156;
	case 12638ULL: goto x86_l_315e;
	case 12647ULL: goto x86_l_3167;
	case 12651ULL: goto x86_l_316b;
	case 12656ULL: goto x86_l_3170;
	case 12661ULL: goto x86_l_3175;
	case 12666ULL: goto x86_l_317a;
	case 12668ULL: goto x86_l_317c;
	case 12670ULL: goto x86_l_317e;
	case 12676ULL: goto x86_l_3184;
	case 12682ULL: goto x86_l_318a;
	case 12685ULL: goto x86_l_318d;
	case 12690ULL: goto x86_l_3192;
	case 12696ULL: goto x86_l_3198;
	case 12701ULL: goto x86_l_319d;
	case 12709ULL: goto x86_l_31a5;
	case 12713ULL: goto x86_l_31a9;
	case 12720ULL: goto x86_l_31b0;
	case 12725ULL: goto x86_l_31b5;
	case 12730ULL: goto x86_l_31ba;
	case 12732ULL: goto x86_l_31bc;
	case 12736ULL: goto x86_l_31c0;
	case 12738ULL: goto x86_l_31c2;
	case 12740ULL: goto x86_l_31c4;
	case 12746ULL: goto x86_l_31ca;
	case 12749ULL: goto x86_l_31cd;
	case 12754ULL: goto x86_l_31d2;
	case 12760ULL: goto x86_l_31d8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a75:
	/* 0x2a75: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a77:
	/* 0x2a77: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2a7d:
	/* 0x2a7d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a80:
	/* 0x2a80: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2a85:
	/* 0x2a85: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2a8b:
	/* 0x2a8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a90:
	/* 0x2a90: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a98:
	/* 0x2a98: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2a9c:
	/* 0x2a9c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2aa3:
	/* 0x2aa3: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2aa8:
	/* 0x2aa8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2aad:
	/* 0x2aad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aaf:
	/* 0x2aaf: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2ab4:
	/* 0x2ab4: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2abc:
	/* 0x2abc: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2abf:
	/* 0x2abf: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2ac7:
	/* 0x2ac7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ad0:
	/* 0x2ad0: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_2ad7:
	/* 0x2ad7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2adc:
	/* 0x2adc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ae1:
	/* 0x2ae1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ae6:
	/* 0x2ae6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2ae9:
	/* 0x2ae9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aeb:
	/* 0x2aeb: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_2aed:
	/* 0x2aed: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2af3:
	/* 0x2af3: je     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2825ULL;
	}
x86_l_2af9:
	/* 0x2af9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2afc:
	/* 0x2afc: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2b01:
	/* 0x2b01: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2b07:
	/* 0x2b07: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2b0c:
	/* 0x2b0c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b14:
	/* 0x2b14: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2b18:
	/* 0x2b18: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2b1f:
	/* 0x2b1f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b24:
	/* 0x2b24: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2b29:
	/* 0x2b29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b2b:
	/* 0x2b2b: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2b2f:
	/* 0x2b2f: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_2b31:
	/* 0x2b31: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b33:
	/* 0x2b33: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2b39:
	/* 0x2b39: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b3c:
	/* 0x2b3c: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2b41:
	/* 0x2b41: ja     b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2825ULL;
	}
x86_l_2b47:
	/* 0x2b47: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b4c:
	/* 0x2b4c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b54:
	/* 0x2b54: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2b58:
	/* 0x2b58: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b5f:
	/* 0x2b5f: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2b64:
	/* 0x2b64: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b69:
	/* 0x2b69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b6b:
	/* 0x2b6b: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2b70:
	/* 0x2b70: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2b78:
	/* 0x2b78: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2b7b:
	/* 0x2b7b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2b83:
	/* 0x2b83: mov    DWORD PTR [rsp+0xa4],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704377663022ULL);
x86_l_2b8e:
	/* 0x2b8e: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2b91:
	/* 0x2b91: cmp    eax,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27901ULL);
x86_l_2b96:
	/* 0x2b96: jb     2b9d <syscall__execve_exit+0x2b9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2b9d;
	}
x86_l_2b98:
	/* 0x2b98: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_2b9d:
	/* 0x2b9d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2ba2:
	/* 0x2ba2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2baa:
	/* 0x2baa: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2bae:
	/* 0x2bae: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2bb5:
	/* 0x2bb5: lea    rdx,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_2bbd:
	/* 0x2bbd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2bc2:
	/* 0x2bc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc4:
	/* 0x2bc4: mov    DWORD PTR [rsp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2bc8:
	/* 0x2bc8: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_2bca:
	/* 0x2bca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bcc:
	/* 0x2bcc: jle    b09 <syscall__execve_exit+0xb09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2825ULL;
	}
x86_l_2bd2:
	/* 0x2bd2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2bd5:
	/* 0x2bd5: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2bda:
	/* 0x2bda: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2bdf:
	/* 0x2bdf: ja     b0e <syscall__execve_exit+0xb0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2830ULL;
	}
x86_l_2be5:
	/* 0x2be5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bea:
	/* 0x2bea: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2bf2:
	/* 0x2bf2: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2bf6:
	/* 0x2bf6: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2bfd:
	/* 0x2bfd: lea    rdx,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2c02:
	/* 0x2c02: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c07:
	/* 0x2c07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c09:
	/* 0x2c09: movzx  eax,WORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 124ULL);
x86_l_2c0e:
	/* 0x2c0e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2c16:
	/* 0x2c16: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2c19:
	/* 0x2c19: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c21:
	/* 0x2c21: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_2c23:
	/* 0x2c23: jmp    b0e <syscall__execve_exit+0xb0e> */
	return 2830ULL;
x86_l_2c28:
	/* 0x2c28: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c2d:
	/* 0x2c2d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c35:
	/* 0x2c35: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2c39:
	/* 0x2c39: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2c40:
	/* 0x2c40: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2c45:
	/* 0x2c45: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c4a:
	/* 0x2c4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c4c:
	/* 0x2c4c: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2c51:
	/* 0x2c51: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2c59:
	/* 0x2c59: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c64:
	/* 0x2c64: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c6d:
	/* 0x2c6d: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c71:
	/* 0x2c71: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c76:
	/* 0x2c76: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c7b:
	/* 0x2c7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c80:
	/* 0x2c80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c82:
	/* 0x2c82: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_2c84:
	/* 0x2c84: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c8a:
	/* 0x2c8a: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_2c90:
	/* 0x2c90: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c93:
	/* 0x2c93: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2c98:
	/* 0x2c98: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2c9e:
	/* 0x2c9e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2ca3:
	/* 0x2ca3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2cab:
	/* 0x2cab: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2caf:
	/* 0x2caf: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2cb6:
	/* 0x2cb6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cbb:
	/* 0x2cbb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2cc0:
	/* 0x2cc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc2:
	/* 0x2cc2: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2cc6:
	/* 0x2cc6: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_2cc8:
	/* 0x2cc8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cca:
	/* 0x2cca: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_2cd0:
	/* 0x2cd0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2cd3:
	/* 0x2cd3: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2cd8:
	/* 0x2cd8: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2cde:
	/* 0x2cde: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ce3:
	/* 0x2ce3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ceb:
	/* 0x2ceb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2cef:
	/* 0x2cef: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2cf6:
	/* 0x2cf6: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2cfb:
	/* 0x2cfb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d00:
	/* 0x2d00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d02:
	/* 0x2d02: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2d07:
	/* 0x2d07: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2d0f:
	/* 0x2d0f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2d12:
	/* 0x2d12: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2d1a:
	/* 0x2d1a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d23:
	/* 0x2d23: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d27:
	/* 0x2d27: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d2c:
	/* 0x2d2c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d31:
	/* 0x2d31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d36:
	/* 0x2d36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d38:
	/* 0x2d38: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_2d3a:
	/* 0x2d3a: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d40:
	/* 0x2d40: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_2d46:
	/* 0x2d46: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d49:
	/* 0x2d49: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2d4e:
	/* 0x2d4e: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2d54:
	/* 0x2d54: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2d59:
	/* 0x2d59: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d61:
	/* 0x2d61: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2d65:
	/* 0x2d65: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2d6c:
	/* 0x2d6c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d71:
	/* 0x2d71: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d76:
	/* 0x2d76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d78:
	/* 0x2d78: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2d7c:
	/* 0x2d7c: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_2d7e:
	/* 0x2d7e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d80:
	/* 0x2d80: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_2d86:
	/* 0x2d86: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d89:
	/* 0x2d89: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2d8e:
	/* 0x2d8e: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2d94:
	/* 0x2d94: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d99:
	/* 0x2d99: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2da1:
	/* 0x2da1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2da5:
	/* 0x2da5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2dac:
	/* 0x2dac: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2db1:
	/* 0x2db1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2db6:
	/* 0x2db6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db8:
	/* 0x2db8: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2dbd:
	/* 0x2dbd: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2dc5:
	/* 0x2dc5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2dc8:
	/* 0x2dc8: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2dd0:
	/* 0x2dd0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2dd9:
	/* 0x2dd9: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ddd:
	/* 0x2ddd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2de2:
	/* 0x2de2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2de7:
	/* 0x2de7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dec:
	/* 0x2dec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dee:
	/* 0x2dee: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_2df0:
	/* 0x2df0: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2df6:
	/* 0x2df6: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_2dfc:
	/* 0x2dfc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2dff:
	/* 0x2dff: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2e04:
	/* 0x2e04: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2e0a:
	/* 0x2e0a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2e0f:
	/* 0x2e0f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e17:
	/* 0x2e17: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2e1b:
	/* 0x2e1b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2e22:
	/* 0x2e22: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e27:
	/* 0x2e27: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2e2c:
	/* 0x2e2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2e:
	/* 0x2e2e: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e32:
	/* 0x2e32: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_2e34:
	/* 0x2e34: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e36:
	/* 0x2e36: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_2e3c:
	/* 0x2e3c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e3f:
	/* 0x2e3f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2e44:
	/* 0x2e44: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2e4a:
	/* 0x2e4a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e4f:
	/* 0x2e4f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e57:
	/* 0x2e57: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e5b:
	/* 0x2e5b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2e62:
	/* 0x2e62: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e67:
	/* 0x2e67: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e6c:
	/* 0x2e6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6e:
	/* 0x2e6e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2e73:
	/* 0x2e73: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2e7b:
	/* 0x2e7b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2e7e:
	/* 0x2e7e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2e86:
	/* 0x2e86: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2e8f:
	/* 0x2e8f: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e93:
	/* 0x2e93: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e98:
	/* 0x2e98: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e9d:
	/* 0x2e9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea2:
	/* 0x2ea2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea4:
	/* 0x2ea4: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_2ea6:
	/* 0x2ea6: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2eac:
	/* 0x2eac: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_2eb2:
	/* 0x2eb2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2eb5:
	/* 0x2eb5: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2eba:
	/* 0x2eba: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2ec0:
	/* 0x2ec0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2ec5:
	/* 0x2ec5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ecd:
	/* 0x2ecd: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
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
	/* 0x2ee4: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2ee8:
	/* 0x2ee8: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_2eea:
	/* 0x2eea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2eec:
	/* 0x2eec: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_2ef2:
	/* 0x2ef2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ef5:
	/* 0x2ef5: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2efa:
	/* 0x2efa: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2f00:
	/* 0x2f00: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f05:
	/* 0x2f05: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f0d:
	/* 0x2f0d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2f11:
	/* 0x2f11: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2f18:
	/* 0x2f18: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2f1d:
	/* 0x2f1d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f22:
	/* 0x2f22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f24:
	/* 0x2f24: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2f29:
	/* 0x2f29: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2f31:
	/* 0x2f31: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2f34:
	/* 0x2f34: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2f3c:
	/* 0x2f3c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f45:
	/* 0x2f45: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f49:
	/* 0x2f49: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f4e:
	/* 0x2f4e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f53:
	/* 0x2f53: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f58:
	/* 0x2f58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f5a:
	/* 0x2f5a: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_2f5c:
	/* 0x2f5c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f62:
	/* 0x2f62: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_2f68:
	/* 0x2f68: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f6b:
	/* 0x2f6b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2f70:
	/* 0x2f70: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2f76:
	/* 0x2f76: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2f7b:
	/* 0x2f7b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f83:
	/* 0x2f83: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2f87:
	/* 0x2f87: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2f8e:
	/* 0x2f8e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f93:
	/* 0x2f93: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f98:
	/* 0x2f98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9a:
	/* 0x2f9a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2f9e:
	/* 0x2f9e: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_2fa0:
	/* 0x2fa0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fa2:
	/* 0x2fa2: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_2fa8:
	/* 0x2fa8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fab:
	/* 0x2fab: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2fb0:
	/* 0x2fb0: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_2fb6:
	/* 0x2fb6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fbb:
	/* 0x2fbb: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2fc3:
	/* 0x2fc3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2fc7:
	/* 0x2fc7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2fce:
	/* 0x2fce: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2fd3:
	/* 0x2fd3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2fd8:
	/* 0x2fd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fda:
	/* 0x2fda: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2fdf:
	/* 0x2fdf: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2fe7:
	/* 0x2fe7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2fea:
	/* 0x2fea: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2ff2:
	/* 0x2ff2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ffb:
	/* 0x2ffb: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fff:
	/* 0x2fff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3004:
	/* 0x3004: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3009:
	/* 0x3009: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_300e:
	/* 0x300e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3010:
	/* 0x3010: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_3012:
	/* 0x3012: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3018:
	/* 0x3018: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_301e:
	/* 0x301e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3021:
	/* 0x3021: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3026:
	/* 0x3026: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_302c:
	/* 0x302c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3031:
	/* 0x3031: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3039:
	/* 0x3039: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_303d:
	/* 0x303d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3044:
	/* 0x3044: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3049:
	/* 0x3049: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_304e:
	/* 0x304e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3050:
	/* 0x3050: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3054:
	/* 0x3054: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_3056:
	/* 0x3056: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3058:
	/* 0x3058: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_305e:
	/* 0x305e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3061:
	/* 0x3061: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3066:
	/* 0x3066: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_306c:
	/* 0x306c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3071:
	/* 0x3071: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3079:
	/* 0x3079: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_307d:
	/* 0x307d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3084:
	/* 0x3084: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3089:
	/* 0x3089: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_308e:
	/* 0x308e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3090:
	/* 0x3090: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3095:
	/* 0x3095: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_309d:
	/* 0x309d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_30a0:
	/* 0x30a0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_30a8:
	/* 0x30a8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_30b1:
	/* 0x30b1: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_30b5:
	/* 0x30b5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30ba:
	/* 0x30ba: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30bf:
	/* 0x30bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30c4:
	/* 0x30c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30c6:
	/* 0x30c6: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_30c8:
	/* 0x30c8: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_30ce:
	/* 0x30ce: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_30d4:
	/* 0x30d4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30d7:
	/* 0x30d7: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_30dc:
	/* 0x30dc: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_30e2:
	/* 0x30e2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_30e7:
	/* 0x30e7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_30ef:
	/* 0x30ef: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_30f3:
	/* 0x30f3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_30fa:
	/* 0x30fa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30ff:
	/* 0x30ff: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3104:
	/* 0x3104: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3106:
	/* 0x3106: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_310a:
	/* 0x310a: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_310c:
	/* 0x310c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_310e:
	/* 0x310e: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3114:
	/* 0x3114: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3117:
	/* 0x3117: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_311c:
	/* 0x311c: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3122:
	/* 0x3122: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3127:
	/* 0x3127: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_312f:
	/* 0x312f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3133:
	/* 0x3133: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_313a:
	/* 0x313a: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_313f:
	/* 0x313f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3144:
	/* 0x3144: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3146:
	/* 0x3146: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_314b:
	/* 0x314b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3153:
	/* 0x3153: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3156:
	/* 0x3156: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_315e:
	/* 0x315e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3167:
	/* 0x3167: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_316b:
	/* 0x316b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3170:
	/* 0x3170: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3175:
	/* 0x3175: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_317a:
	/* 0x317a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_317c:
	/* 0x317c: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_317e:
	/* 0x317e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3184:
	/* 0x3184: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_318a:
	/* 0x318a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_318d:
	/* 0x318d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3192:
	/* 0x3192: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3198:
	/* 0x3198: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_319d:
	/* 0x319d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_31a5:
	/* 0x31a5: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_31a9:
	/* 0x31a9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_31b0:
	/* 0x31b0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31b5:
	/* 0x31b5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_31ba:
	/* 0x31ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31bc:
	/* 0x31bc: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_31c0:
	/* 0x31c0: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_31c2:
	/* 0x31c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31c4:
	/* 0x31c4: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_31ca:
	/* 0x31ca: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31cd:
	/* 0x31cd: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_31d2:
	/* 0x31d2: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_31d8:
	/* 0x31d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 12765ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12765ULL: goto x86_l_31dd;
	case 12773ULL: goto x86_l_31e5;
	case 12777ULL: goto x86_l_31e9;
	case 12784ULL: goto x86_l_31f0;
	case 12789ULL: goto x86_l_31f5;
	case 12794ULL: goto x86_l_31fa;
	case 12796ULL: goto x86_l_31fc;
	case 12801ULL: goto x86_l_3201;
	case 12809ULL: goto x86_l_3209;
	case 12812ULL: goto x86_l_320c;
	case 12820ULL: goto x86_l_3214;
	case 12829ULL: goto x86_l_321d;
	case 12833ULL: goto x86_l_3221;
	case 12838ULL: goto x86_l_3226;
	case 12843ULL: goto x86_l_322b;
	case 12848ULL: goto x86_l_3230;
	case 12850ULL: goto x86_l_3232;
	case 12852ULL: goto x86_l_3234;
	case 12858ULL: goto x86_l_323a;
	case 12864ULL: goto x86_l_3240;
	case 12867ULL: goto x86_l_3243;
	case 12872ULL: goto x86_l_3248;
	case 12878ULL: goto x86_l_324e;
	case 12883ULL: goto x86_l_3253;
	case 12891ULL: goto x86_l_325b;
	case 12895ULL: goto x86_l_325f;
	case 12902ULL: goto x86_l_3266;
	case 12907ULL: goto x86_l_326b;
	case 12912ULL: goto x86_l_3270;
	case 12914ULL: goto x86_l_3272;
	case 12918ULL: goto x86_l_3276;
	case 12920ULL: goto x86_l_3278;
	case 12922ULL: goto x86_l_327a;
	case 12928ULL: goto x86_l_3280;
	case 12931ULL: goto x86_l_3283;
	case 12936ULL: goto x86_l_3288;
	case 12942ULL: goto x86_l_328e;
	case 12947ULL: goto x86_l_3293;
	case 12955ULL: goto x86_l_329b;
	case 12959ULL: goto x86_l_329f;
	case 12966ULL: goto x86_l_32a6;
	case 12971ULL: goto x86_l_32ab;
	case 12976ULL: goto x86_l_32b0;
	case 12978ULL: goto x86_l_32b2;
	case 12983ULL: goto x86_l_32b7;
	case 12991ULL: goto x86_l_32bf;
	case 12994ULL: goto x86_l_32c2;
	case 13002ULL: goto x86_l_32ca;
	case 13011ULL: goto x86_l_32d3;
	case 13015ULL: goto x86_l_32d7;
	case 13020ULL: goto x86_l_32dc;
	case 13025ULL: goto x86_l_32e1;
	case 13030ULL: goto x86_l_32e6;
	case 13032ULL: goto x86_l_32e8;
	case 13034ULL: goto x86_l_32ea;
	case 13040ULL: goto x86_l_32f0;
	case 13046ULL: goto x86_l_32f6;
	case 13049ULL: goto x86_l_32f9;
	case 13054ULL: goto x86_l_32fe;
	case 13060ULL: goto x86_l_3304;
	case 13065ULL: goto x86_l_3309;
	case 13073ULL: goto x86_l_3311;
	case 13077ULL: goto x86_l_3315;
	case 13084ULL: goto x86_l_331c;
	case 13089ULL: goto x86_l_3321;
	case 13094ULL: goto x86_l_3326;
	case 13096ULL: goto x86_l_3328;
	case 13100ULL: goto x86_l_332c;
	case 13102ULL: goto x86_l_332e;
	case 13104ULL: goto x86_l_3330;
	case 13110ULL: goto x86_l_3336;
	case 13113ULL: goto x86_l_3339;
	case 13118ULL: goto x86_l_333e;
	case 13124ULL: goto x86_l_3344;
	case 13129ULL: goto x86_l_3349;
	case 13137ULL: goto x86_l_3351;
	case 13141ULL: goto x86_l_3355;
	case 13148ULL: goto x86_l_335c;
	case 13153ULL: goto x86_l_3361;
	case 13158ULL: goto x86_l_3366;
	case 13160ULL: goto x86_l_3368;
	case 13165ULL: goto x86_l_336d;
	case 13173ULL: goto x86_l_3375;
	case 13176ULL: goto x86_l_3378;
	case 13184ULL: goto x86_l_3380;
	case 13193ULL: goto x86_l_3389;
	case 13197ULL: goto x86_l_338d;
	case 13202ULL: goto x86_l_3392;
	case 13207ULL: goto x86_l_3397;
	case 13212ULL: goto x86_l_339c;
	case 13214ULL: goto x86_l_339e;
	case 13216ULL: goto x86_l_33a0;
	case 13222ULL: goto x86_l_33a6;
	case 13228ULL: goto x86_l_33ac;
	case 13231ULL: goto x86_l_33af;
	case 13236ULL: goto x86_l_33b4;
	case 13242ULL: goto x86_l_33ba;
	case 13247ULL: goto x86_l_33bf;
	case 13255ULL: goto x86_l_33c7;
	case 13259ULL: goto x86_l_33cb;
	case 13266ULL: goto x86_l_33d2;
	case 13271ULL: goto x86_l_33d7;
	case 13276ULL: goto x86_l_33dc;
	case 13278ULL: goto x86_l_33de;
	case 13282ULL: goto x86_l_33e2;
	case 13284ULL: goto x86_l_33e4;
	case 13286ULL: goto x86_l_33e6;
	case 13292ULL: goto x86_l_33ec;
	case 13295ULL: goto x86_l_33ef;
	case 13300ULL: goto x86_l_33f4;
	case 13306ULL: goto x86_l_33fa;
	case 13311ULL: goto x86_l_33ff;
	case 13319ULL: goto x86_l_3407;
	case 13323ULL: goto x86_l_340b;
	case 13330ULL: goto x86_l_3412;
	case 13335ULL: goto x86_l_3417;
	case 13340ULL: goto x86_l_341c;
	case 13342ULL: goto x86_l_341e;
	case 13347ULL: goto x86_l_3423;
	case 13355ULL: goto x86_l_342b;
	case 13358ULL: goto x86_l_342e;
	case 13366ULL: goto x86_l_3436;
	case 13375ULL: goto x86_l_343f;
	case 13379ULL: goto x86_l_3443;
	case 13384ULL: goto x86_l_3448;
	case 13389ULL: goto x86_l_344d;
	case 13394ULL: goto x86_l_3452;
	case 13396ULL: goto x86_l_3454;
	case 13398ULL: goto x86_l_3456;
	case 13404ULL: goto x86_l_345c;
	case 13410ULL: goto x86_l_3462;
	case 13413ULL: goto x86_l_3465;
	case 13418ULL: goto x86_l_346a;
	case 13424ULL: goto x86_l_3470;
	case 13429ULL: goto x86_l_3475;
	case 13437ULL: goto x86_l_347d;
	case 13441ULL: goto x86_l_3481;
	case 13448ULL: goto x86_l_3488;
	case 13453ULL: goto x86_l_348d;
	case 13458ULL: goto x86_l_3492;
	case 13460ULL: goto x86_l_3494;
	case 13464ULL: goto x86_l_3498;
	case 13466ULL: goto x86_l_349a;
	case 13468ULL: goto x86_l_349c;
	case 13474ULL: goto x86_l_34a2;
	case 13477ULL: goto x86_l_34a5;
	case 13482ULL: goto x86_l_34aa;
	case 13488ULL: goto x86_l_34b0;
	case 13493ULL: goto x86_l_34b5;
	case 13501ULL: goto x86_l_34bd;
	case 13505ULL: goto x86_l_34c1;
	case 13512ULL: goto x86_l_34c8;
	case 13517ULL: goto x86_l_34cd;
	case 13522ULL: goto x86_l_34d2;
	case 13524ULL: goto x86_l_34d4;
	case 13529ULL: goto x86_l_34d9;
	case 13537ULL: goto x86_l_34e1;
	case 13540ULL: goto x86_l_34e4;
	case 13548ULL: goto x86_l_34ec;
	case 13557ULL: goto x86_l_34f5;
	case 13561ULL: goto x86_l_34f9;
	case 13566ULL: goto x86_l_34fe;
	case 13571ULL: goto x86_l_3503;
	case 13576ULL: goto x86_l_3508;
	case 13578ULL: goto x86_l_350a;
	case 13580ULL: goto x86_l_350c;
	case 13586ULL: goto x86_l_3512;
	case 13592ULL: goto x86_l_3518;
	case 13595ULL: goto x86_l_351b;
	case 13600ULL: goto x86_l_3520;
	case 13606ULL: goto x86_l_3526;
	case 13611ULL: goto x86_l_352b;
	case 13619ULL: goto x86_l_3533;
	case 13623ULL: goto x86_l_3537;
	case 13630ULL: goto x86_l_353e;
	case 13635ULL: goto x86_l_3543;
	case 13640ULL: goto x86_l_3548;
	case 13642ULL: goto x86_l_354a;
	case 13646ULL: goto x86_l_354e;
	case 13648ULL: goto x86_l_3550;
	case 13650ULL: goto x86_l_3552;
	case 13656ULL: goto x86_l_3558;
	case 13659ULL: goto x86_l_355b;
	case 13664ULL: goto x86_l_3560;
	case 13670ULL: goto x86_l_3566;
	case 13675ULL: goto x86_l_356b;
	case 13683ULL: goto x86_l_3573;
	case 13687ULL: goto x86_l_3577;
	case 13694ULL: goto x86_l_357e;
	case 13699ULL: goto x86_l_3583;
	case 13704ULL: goto x86_l_3588;
	case 13706ULL: goto x86_l_358a;
	case 13711ULL: goto x86_l_358f;
	case 13719ULL: goto x86_l_3597;
	case 13722ULL: goto x86_l_359a;
	case 13730ULL: goto x86_l_35a2;
	case 13739ULL: goto x86_l_35ab;
	case 13743ULL: goto x86_l_35af;
	case 13748ULL: goto x86_l_35b4;
	case 13753ULL: goto x86_l_35b9;
	case 13758ULL: goto x86_l_35be;
	case 13760ULL: goto x86_l_35c0;
	case 13762ULL: goto x86_l_35c2;
	case 13768ULL: goto x86_l_35c8;
	case 13774ULL: goto x86_l_35ce;
	case 13777ULL: goto x86_l_35d1;
	case 13782ULL: goto x86_l_35d6;
	case 13788ULL: goto x86_l_35dc;
	case 13793ULL: goto x86_l_35e1;
	case 13801ULL: goto x86_l_35e9;
	case 13805ULL: goto x86_l_35ed;
	case 13812ULL: goto x86_l_35f4;
	case 13817ULL: goto x86_l_35f9;
	case 13822ULL: goto x86_l_35fe;
	case 13824ULL: goto x86_l_3600;
	case 13828ULL: goto x86_l_3604;
	case 13830ULL: goto x86_l_3606;
	case 13832ULL: goto x86_l_3608;
	case 13838ULL: goto x86_l_360e;
	case 13841ULL: goto x86_l_3611;
	case 13846ULL: goto x86_l_3616;
	case 13852ULL: goto x86_l_361c;
	case 13857ULL: goto x86_l_3621;
	case 13865ULL: goto x86_l_3629;
	case 13869ULL: goto x86_l_362d;
	case 13876ULL: goto x86_l_3634;
	case 13881ULL: goto x86_l_3639;
	case 13886ULL: goto x86_l_363e;
	case 13888ULL: goto x86_l_3640;
	case 13893ULL: goto x86_l_3645;
	case 13901ULL: goto x86_l_364d;
	case 13904ULL: goto x86_l_3650;
	case 13912ULL: goto x86_l_3658;
	case 13921ULL: goto x86_l_3661;
	case 13925ULL: goto x86_l_3665;
	case 13930ULL: goto x86_l_366a;
	case 13935ULL: goto x86_l_366f;
	case 13940ULL: goto x86_l_3674;
	case 13942ULL: goto x86_l_3676;
	case 13944ULL: goto x86_l_3678;
	case 13950ULL: goto x86_l_367e;
	case 13956ULL: goto x86_l_3684;
	case 13959ULL: goto x86_l_3687;
	case 13964ULL: goto x86_l_368c;
	case 13970ULL: goto x86_l_3692;
	case 13975ULL: goto x86_l_3697;
	case 13983ULL: goto x86_l_369f;
	case 13987ULL: goto x86_l_36a3;
	case 13994ULL: goto x86_l_36aa;
	case 13999ULL: goto x86_l_36af;
	case 14004ULL: goto x86_l_36b4;
	case 14006ULL: goto x86_l_36b6;
	case 14010ULL: goto x86_l_36ba;
	case 14012ULL: goto x86_l_36bc;
	case 14014ULL: goto x86_l_36be;
	case 14020ULL: goto x86_l_36c4;
	case 14023ULL: goto x86_l_36c7;
	case 14028ULL: goto x86_l_36cc;
	case 14034ULL: goto x86_l_36d2;
	case 14039ULL: goto x86_l_36d7;
	case 14047ULL: goto x86_l_36df;
	case 14051ULL: goto x86_l_36e3;
	case 14058ULL: goto x86_l_36ea;
	case 14063ULL: goto x86_l_36ef;
	case 14068ULL: goto x86_l_36f4;
	case 14070ULL: goto x86_l_36f6;
	case 14075ULL: goto x86_l_36fb;
	case 14083ULL: goto x86_l_3703;
	case 14086ULL: goto x86_l_3706;
	case 14094ULL: goto x86_l_370e;
	case 14103ULL: goto x86_l_3717;
	case 14110ULL: goto x86_l_371e;
	case 14115ULL: goto x86_l_3723;
	case 14120ULL: goto x86_l_3728;
	case 14125ULL: goto x86_l_372d;
	case 14127ULL: goto x86_l_372f;
	case 14129ULL: goto x86_l_3731;
	case 14135ULL: goto x86_l_3737;
	case 14141ULL: goto x86_l_373d;
	case 14144ULL: goto x86_l_3740;
	case 14149ULL: goto x86_l_3745;
	case 14155ULL: goto x86_l_374b;
	case 14160ULL: goto x86_l_3750;
	case 14168ULL: goto x86_l_3758;
	case 14172ULL: goto x86_l_375c;
	case 14179ULL: goto x86_l_3763;
	case 14184ULL: goto x86_l_3768;
	case 14189ULL: goto x86_l_376d;
	case 14191ULL: goto x86_l_376f;
	case 14195ULL: goto x86_l_3773;
	case 14197ULL: goto x86_l_3775;
	case 14199ULL: goto x86_l_3777;
	case 14205ULL: goto x86_l_377d;
	case 14208ULL: goto x86_l_3780;
	case 14213ULL: goto x86_l_3785;
	case 14219ULL: goto x86_l_378b;
	case 14224ULL: goto x86_l_3790;
	case 14232ULL: goto x86_l_3798;
	case 14236ULL: goto x86_l_379c;
	case 14243ULL: goto x86_l_37a3;
	case 14248ULL: goto x86_l_37a8;
	case 14253ULL: goto x86_l_37ad;
	case 14255ULL: goto x86_l_37af;
	case 14260ULL: goto x86_l_37b4;
	case 14268ULL: goto x86_l_37bc;
	case 14271ULL: goto x86_l_37bf;
	case 14279ULL: goto x86_l_37c7;
	case 14288ULL: goto x86_l_37d0;
	case 14295ULL: goto x86_l_37d7;
	case 14300ULL: goto x86_l_37dc;
	case 14305ULL: goto x86_l_37e1;
	case 14310ULL: goto x86_l_37e6;
	case 14312ULL: goto x86_l_37e8;
	case 14314ULL: goto x86_l_37ea;
	case 14320ULL: goto x86_l_37f0;
	case 14326ULL: goto x86_l_37f6;
	case 14329ULL: goto x86_l_37f9;
	case 14334ULL: goto x86_l_37fe;
	case 14340ULL: goto x86_l_3804;
	case 14345ULL: goto x86_l_3809;
	case 14353ULL: goto x86_l_3811;
	case 14357ULL: goto x86_l_3815;
	case 14364ULL: goto x86_l_381c;
	case 14369ULL: goto x86_l_3821;
	case 14374ULL: goto x86_l_3826;
	case 14376ULL: goto x86_l_3828;
	case 14380ULL: goto x86_l_382c;
	case 14382ULL: goto x86_l_382e;
	case 14384ULL: goto x86_l_3830;
	case 14390ULL: goto x86_l_3836;
	case 14393ULL: goto x86_l_3839;
	case 14398ULL: goto x86_l_383e;
	case 14404ULL: goto x86_l_3844;
	case 14409ULL: goto x86_l_3849;
	case 14417ULL: goto x86_l_3851;
	case 14421ULL: goto x86_l_3855;
	case 14428ULL: goto x86_l_385c;
	case 14433ULL: goto x86_l_3861;
	case 14438ULL: goto x86_l_3866;
	case 14440ULL: goto x86_l_3868;
	case 14445ULL: goto x86_l_386d;
	case 14453ULL: goto x86_l_3875;
	case 14456ULL: goto x86_l_3878;
	case 14464ULL: goto x86_l_3880;
	case 14473ULL: goto x86_l_3889;
	case 14480ULL: goto x86_l_3890;
	case 14485ULL: goto x86_l_3895;
	case 14490ULL: goto x86_l_389a;
	case 14495ULL: goto x86_l_389f;
	case 14497ULL: goto x86_l_38a1;
	case 14499ULL: goto x86_l_38a3;
	case 14505ULL: goto x86_l_38a9;
	case 14511ULL: goto x86_l_38af;
	case 14514ULL: goto x86_l_38b2;
	case 14519ULL: goto x86_l_38b7;
	case 14525ULL: goto x86_l_38bd;
	case 14530ULL: goto x86_l_38c2;
	case 14538ULL: goto x86_l_38ca;
	case 14542ULL: goto x86_l_38ce;
	case 14549ULL: goto x86_l_38d5;
	case 14554ULL: goto x86_l_38da;
	case 14559ULL: goto x86_l_38df;
	case 14561ULL: goto x86_l_38e1;
	case 14565ULL: goto x86_l_38e5;
	case 14567ULL: goto x86_l_38e7;
	case 14569ULL: goto x86_l_38e9;
	case 14575ULL: goto x86_l_38ef;
	case 14578ULL: goto x86_l_38f2;
	case 14583ULL: goto x86_l_38f7;
	case 14589ULL: goto x86_l_38fd;
	case 14594ULL: goto x86_l_3902;
	case 14602ULL: goto x86_l_390a;
	case 14606ULL: goto x86_l_390e;
	case 14613ULL: goto x86_l_3915;
	case 14618ULL: goto x86_l_391a;
	case 14623ULL: goto x86_l_391f;
	case 14625ULL: goto x86_l_3921;
	case 14630ULL: goto x86_l_3926;
	case 14638ULL: goto x86_l_392e;
	case 14641ULL: goto x86_l_3931;
	case 14649ULL: goto x86_l_3939;
	case 14658ULL: goto x86_l_3942;
	case 14665ULL: goto x86_l_3949;
	case 14670ULL: goto x86_l_394e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_31dd:
	/* 0x31dd: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_31e5:
	/* 0x31e5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_31e9:
	/* 0x31e9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_31f0:
	/* 0x31f0: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_31f5:
	/* 0x31f5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_31fa:
	/* 0x31fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31fc:
	/* 0x31fc: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3201:
	/* 0x3201: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3209:
	/* 0x3209: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_320c:
	/* 0x320c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3214:
	/* 0x3214: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_321d:
	/* 0x321d: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3221:
	/* 0x3221: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3226:
	/* 0x3226: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_322b:
	/* 0x322b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3230:
	/* 0x3230: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3232:
	/* 0x3232: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_3234:
	/* 0x3234: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_323a:
	/* 0x323a: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3240:
	/* 0x3240: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3243:
	/* 0x3243: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3248:
	/* 0x3248: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_324e:
	/* 0x324e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3253:
	/* 0x3253: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_325b:
	/* 0x325b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_325f:
	/* 0x325f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3266:
	/* 0x3266: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_326b:
	/* 0x326b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3270:
	/* 0x3270: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3272:
	/* 0x3272: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3276:
	/* 0x3276: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_3278:
	/* 0x3278: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_327a:
	/* 0x327a: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3280:
	/* 0x3280: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3283:
	/* 0x3283: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3288:
	/* 0x3288: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_328e:
	/* 0x328e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3293:
	/* 0x3293: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_329b:
	/* 0x329b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_329f:
	/* 0x329f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_32a6:
	/* 0x32a6: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_32ab:
	/* 0x32ab: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_32b0:
	/* 0x32b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b2:
	/* 0x32b2: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_32b7:
	/* 0x32b7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_32bf:
	/* 0x32bf: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_32c2:
	/* 0x32c2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_32ca:
	/* 0x32ca: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_32d3:
	/* 0x32d3: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_32d7:
	/* 0x32d7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32dc:
	/* 0x32dc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32e1:
	/* 0x32e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32e6:
	/* 0x32e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e8:
	/* 0x32e8: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_32ea:
	/* 0x32ea: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_32f0:
	/* 0x32f0: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_32f6:
	/* 0x32f6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32f9:
	/* 0x32f9: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_32fe:
	/* 0x32fe: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3304:
	/* 0x3304: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3309:
	/* 0x3309: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3311:
	/* 0x3311: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3315:
	/* 0x3315: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_331c:
	/* 0x331c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3321:
	/* 0x3321: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3326:
	/* 0x3326: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3328:
	/* 0x3328: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_332c:
	/* 0x332c: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_332e:
	/* 0x332e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3330:
	/* 0x3330: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3336:
	/* 0x3336: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3339:
	/* 0x3339: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_333e:
	/* 0x333e: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3344:
	/* 0x3344: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3349:
	/* 0x3349: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3351:
	/* 0x3351: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3355:
	/* 0x3355: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_335c:
	/* 0x335c: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3361:
	/* 0x3361: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3366:
	/* 0x3366: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3368:
	/* 0x3368: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_336d:
	/* 0x336d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3375:
	/* 0x3375: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3378:
	/* 0x3378: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3380:
	/* 0x3380: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3389:
	/* 0x3389: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_338d:
	/* 0x338d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3392:
	/* 0x3392: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3397:
	/* 0x3397: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_339c:
	/* 0x339c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_339e:
	/* 0x339e: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_33a0:
	/* 0x33a0: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_33a6:
	/* 0x33a6: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_33ac:
	/* 0x33ac: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33af:
	/* 0x33af: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_33b4:
	/* 0x33b4: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_33ba:
	/* 0x33ba: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_33bf:
	/* 0x33bf: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_33c7:
	/* 0x33c7: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_33cb:
	/* 0x33cb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_33d2:
	/* 0x33d2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33d7:
	/* 0x33d7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_33dc:
	/* 0x33dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33de:
	/* 0x33de: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_33e2:
	/* 0x33e2: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_33e4:
	/* 0x33e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33e6:
	/* 0x33e6: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_33ec:
	/* 0x33ec: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33ef:
	/* 0x33ef: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_33f4:
	/* 0x33f4: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_33fa:
	/* 0x33fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33ff:
	/* 0x33ff: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3407:
	/* 0x3407: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_340b:
	/* 0x340b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3412:
	/* 0x3412: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3417:
	/* 0x3417: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_341c:
	/* 0x341c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_341e:
	/* 0x341e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3423:
	/* 0x3423: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_342b:
	/* 0x342b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_342e:
	/* 0x342e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3436:
	/* 0x3436: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_343f:
	/* 0x343f: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3443:
	/* 0x3443: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3448:
	/* 0x3448: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_344d:
	/* 0x344d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3452:
	/* 0x3452: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3454:
	/* 0x3454: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_3456:
	/* 0x3456: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_345c:
	/* 0x345c: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3462:
	/* 0x3462: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3465:
	/* 0x3465: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_346a:
	/* 0x346a: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3470:
	/* 0x3470: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3475:
	/* 0x3475: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_347d:
	/* 0x347d: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3481:
	/* 0x3481: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3488:
	/* 0x3488: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_348d:
	/* 0x348d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3492:
	/* 0x3492: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3494:
	/* 0x3494: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3498:
	/* 0x3498: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_349a:
	/* 0x349a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_349c:
	/* 0x349c: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_34a2:
	/* 0x34a2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34a5:
	/* 0x34a5: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_34aa:
	/* 0x34aa: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_34b0:
	/* 0x34b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34b5:
	/* 0x34b5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_34bd:
	/* 0x34bd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_34c1:
	/* 0x34c1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_34c8:
	/* 0x34c8: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_34cd:
	/* 0x34cd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34d2:
	/* 0x34d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34d4:
	/* 0x34d4: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_34d9:
	/* 0x34d9: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_34e1:
	/* 0x34e1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_34e4:
	/* 0x34e4: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_34ec:
	/* 0x34ec: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_34f5:
	/* 0x34f5: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_34f9:
	/* 0x34f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34fe:
	/* 0x34fe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3503:
	/* 0x3503: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3508:
	/* 0x3508: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_350a:
	/* 0x350a: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_350c:
	/* 0x350c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3512:
	/* 0x3512: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3518:
	/* 0x3518: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_351b:
	/* 0x351b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3520:
	/* 0x3520: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3526:
	/* 0x3526: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_352b:
	/* 0x352b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3533:
	/* 0x3533: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3537:
	/* 0x3537: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_353e:
	/* 0x353e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3543:
	/* 0x3543: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3548:
	/* 0x3548: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_354a:
	/* 0x354a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_354e:
	/* 0x354e: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_3550:
	/* 0x3550: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3552:
	/* 0x3552: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3558:
	/* 0x3558: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_355b:
	/* 0x355b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3560:
	/* 0x3560: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3566:
	/* 0x3566: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_356b:
	/* 0x356b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3573:
	/* 0x3573: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3577:
	/* 0x3577: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_357e:
	/* 0x357e: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3583:
	/* 0x3583: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3588:
	/* 0x3588: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_358a:
	/* 0x358a: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_358f:
	/* 0x358f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3597:
	/* 0x3597: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_359a:
	/* 0x359a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_35a2:
	/* 0x35a2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_35ab:
	/* 0x35ab: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_35af:
	/* 0x35af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35b4:
	/* 0x35b4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35b9:
	/* 0x35b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35be:
	/* 0x35be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35c0:
	/* 0x35c0: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_35c2:
	/* 0x35c2: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_35c8:
	/* 0x35c8: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_35ce:
	/* 0x35ce: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35d1:
	/* 0x35d1: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_35d6:
	/* 0x35d6: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_35dc:
	/* 0x35dc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_35e1:
	/* 0x35e1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_35e9:
	/* 0x35e9: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_35ed:
	/* 0x35ed: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_35f4:
	/* 0x35f4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35f9:
	/* 0x35f9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35fe:
	/* 0x35fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3600:
	/* 0x3600: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3604:
	/* 0x3604: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_3606:
	/* 0x3606: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3608:
	/* 0x3608: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_360e:
	/* 0x360e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3611:
	/* 0x3611: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3616:
	/* 0x3616: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_361c:
	/* 0x361c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3621:
	/* 0x3621: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3629:
	/* 0x3629: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_362d:
	/* 0x362d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3634:
	/* 0x3634: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3639:
	/* 0x3639: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_363e:
	/* 0x363e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3640:
	/* 0x3640: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3645:
	/* 0x3645: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_364d:
	/* 0x364d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3650:
	/* 0x3650: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3658:
	/* 0x3658: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3661:
	/* 0x3661: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3665:
	/* 0x3665: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_366a:
	/* 0x366a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_366f:
	/* 0x366f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3674:
	/* 0x3674: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3676:
	/* 0x3676: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_3678:
	/* 0x3678: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_367e:
	/* 0x367e: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3684:
	/* 0x3684: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3687:
	/* 0x3687: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_368c:
	/* 0x368c: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3692:
	/* 0x3692: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3697:
	/* 0x3697: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_369f:
	/* 0x369f: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_36a3:
	/* 0x36a3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_36aa:
	/* 0x36aa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36af:
	/* 0x36af: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_36b4:
	/* 0x36b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36b6:
	/* 0x36b6: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_36ba:
	/* 0x36ba: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_36bc:
	/* 0x36bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36be:
	/* 0x36be: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_36c4:
	/* 0x36c4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_36c7:
	/* 0x36c7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_36cc:
	/* 0x36cc: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_36d2:
	/* 0x36d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36d7:
	/* 0x36d7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_36df:
	/* 0x36df: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_36e3:
	/* 0x36e3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_36ea:
	/* 0x36ea: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_36ef:
	/* 0x36ef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_36f4:
	/* 0x36f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36f6:
	/* 0x36f6: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_36fb:
	/* 0x36fb: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3703:
	/* 0x3703: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3706:
	/* 0x3706: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_370e:
	/* 0x370e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3717:
	/* 0x3717: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_371e:
	/* 0x371e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3723:
	/* 0x3723: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3728:
	/* 0x3728: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_372d:
	/* 0x372d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_372f:
	/* 0x372f: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_3731:
	/* 0x3731: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3737:
	/* 0x3737: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_373d:
	/* 0x373d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3740:
	/* 0x3740: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3745:
	/* 0x3745: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_374b:
	/* 0x374b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3750:
	/* 0x3750: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3758:
	/* 0x3758: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_375c:
	/* 0x375c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3763:
	/* 0x3763: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3768:
	/* 0x3768: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_376d:
	/* 0x376d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_376f:
	/* 0x376f: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3773:
	/* 0x3773: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_3775:
	/* 0x3775: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3777:
	/* 0x3777: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_377d:
	/* 0x377d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3780:
	/* 0x3780: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3785:
	/* 0x3785: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_378b:
	/* 0x378b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3790:
	/* 0x3790: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3798:
	/* 0x3798: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_379c:
	/* 0x379c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_37a3:
	/* 0x37a3: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_37a8:
	/* 0x37a8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_37ad:
	/* 0x37ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37af:
	/* 0x37af: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_37b4:
	/* 0x37b4: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_37bc:
	/* 0x37bc: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_37bf:
	/* 0x37bf: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_37c7:
	/* 0x37c7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_37d0:
	/* 0x37d0: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_37d7:
	/* 0x37d7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37dc:
	/* 0x37dc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37e1:
	/* 0x37e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37e6:
	/* 0x37e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37e8:
	/* 0x37e8: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_37ea:
	/* 0x37ea: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_37f0:
	/* 0x37f0: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_37f6:
	/* 0x37f6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37f9:
	/* 0x37f9: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_37fe:
	/* 0x37fe: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3804:
	/* 0x3804: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3809:
	/* 0x3809: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3811:
	/* 0x3811: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3815:
	/* 0x3815: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_381c:
	/* 0x381c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3821:
	/* 0x3821: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3826:
	/* 0x3826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3828:
	/* 0x3828: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_382c:
	/* 0x382c: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_382e:
	/* 0x382e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3830:
	/* 0x3830: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3836:
	/* 0x3836: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3839:
	/* 0x3839: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_383e:
	/* 0x383e: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3844:
	/* 0x3844: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3849:
	/* 0x3849: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3851:
	/* 0x3851: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3855:
	/* 0x3855: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_385c:
	/* 0x385c: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3861:
	/* 0x3861: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3866:
	/* 0x3866: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3868:
	/* 0x3868: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_386d:
	/* 0x386d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3875:
	/* 0x3875: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3878:
	/* 0x3878: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3880:
	/* 0x3880: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3889:
	/* 0x3889: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3890:
	/* 0x3890: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3895:
	/* 0x3895: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_389a:
	/* 0x389a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_389f:
	/* 0x389f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38a1:
	/* 0x38a1: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_38a3:
	/* 0x38a3: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_38a9:
	/* 0x38a9: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_38af:
	/* 0x38af: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38b2:
	/* 0x38b2: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_38b7:
	/* 0x38b7: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_38bd:
	/* 0x38bd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_38c2:
	/* 0x38c2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_38ca:
	/* 0x38ca: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_38ce:
	/* 0x38ce: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_38d5:
	/* 0x38d5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38da:
	/* 0x38da: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_38df:
	/* 0x38df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38e1:
	/* 0x38e1: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_38e5:
	/* 0x38e5: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_38e7:
	/* 0x38e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38e9:
	/* 0x38e9: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_38ef:
	/* 0x38ef: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38f2:
	/* 0x38f2: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_38f7:
	/* 0x38f7: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_38fd:
	/* 0x38fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3902:
	/* 0x3902: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_390a:
	/* 0x390a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_390e:
	/* 0x390e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3915:
	/* 0x3915: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_391a:
	/* 0x391a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_391f:
	/* 0x391f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3921:
	/* 0x3921: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3926:
	/* 0x3926: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_392e:
	/* 0x392e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3931:
	/* 0x3931: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3939:
	/* 0x3939: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3942:
	/* 0x3942: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3949:
	/* 0x3949: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_394e:
	/* 0x394e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 14675ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14675ULL: goto x86_l_3953;
	case 14680ULL: goto x86_l_3958;
	case 14682ULL: goto x86_l_395a;
	case 14684ULL: goto x86_l_395c;
	case 14690ULL: goto x86_l_3962;
	case 14696ULL: goto x86_l_3968;
	case 14699ULL: goto x86_l_396b;
	case 14704ULL: goto x86_l_3970;
	case 14710ULL: goto x86_l_3976;
	case 14715ULL: goto x86_l_397b;
	case 14723ULL: goto x86_l_3983;
	case 14727ULL: goto x86_l_3987;
	case 14734ULL: goto x86_l_398e;
	case 14739ULL: goto x86_l_3993;
	case 14744ULL: goto x86_l_3998;
	case 14746ULL: goto x86_l_399a;
	case 14750ULL: goto x86_l_399e;
	case 14752ULL: goto x86_l_39a0;
	case 14754ULL: goto x86_l_39a2;
	case 14760ULL: goto x86_l_39a8;
	case 14763ULL: goto x86_l_39ab;
	case 14768ULL: goto x86_l_39b0;
	case 14774ULL: goto x86_l_39b6;
	case 14779ULL: goto x86_l_39bb;
	case 14787ULL: goto x86_l_39c3;
	case 14791ULL: goto x86_l_39c7;
	case 14798ULL: goto x86_l_39ce;
	case 14803ULL: goto x86_l_39d3;
	case 14808ULL: goto x86_l_39d8;
	case 14810ULL: goto x86_l_39da;
	case 14815ULL: goto x86_l_39df;
	case 14823ULL: goto x86_l_39e7;
	case 14826ULL: goto x86_l_39ea;
	case 14834ULL: goto x86_l_39f2;
	case 14843ULL: goto x86_l_39fb;
	case 14850ULL: goto x86_l_3a02;
	case 14855ULL: goto x86_l_3a07;
	case 14860ULL: goto x86_l_3a0c;
	case 14865ULL: goto x86_l_3a11;
	case 14867ULL: goto x86_l_3a13;
	case 14869ULL: goto x86_l_3a15;
	case 14875ULL: goto x86_l_3a1b;
	case 14881ULL: goto x86_l_3a21;
	case 14884ULL: goto x86_l_3a24;
	case 14889ULL: goto x86_l_3a29;
	case 14895ULL: goto x86_l_3a2f;
	case 14900ULL: goto x86_l_3a34;
	case 14908ULL: goto x86_l_3a3c;
	case 14912ULL: goto x86_l_3a40;
	case 14919ULL: goto x86_l_3a47;
	case 14924ULL: goto x86_l_3a4c;
	case 14929ULL: goto x86_l_3a51;
	case 14931ULL: goto x86_l_3a53;
	case 14935ULL: goto x86_l_3a57;
	case 14937ULL: goto x86_l_3a59;
	case 14939ULL: goto x86_l_3a5b;
	case 14945ULL: goto x86_l_3a61;
	case 14948ULL: goto x86_l_3a64;
	case 14953ULL: goto x86_l_3a69;
	case 14959ULL: goto x86_l_3a6f;
	case 14964ULL: goto x86_l_3a74;
	case 14972ULL: goto x86_l_3a7c;
	case 14976ULL: goto x86_l_3a80;
	case 14983ULL: goto x86_l_3a87;
	case 14988ULL: goto x86_l_3a8c;
	case 14993ULL: goto x86_l_3a91;
	case 14995ULL: goto x86_l_3a93;
	case 15000ULL: goto x86_l_3a98;
	case 15008ULL: goto x86_l_3aa0;
	case 15011ULL: goto x86_l_3aa3;
	case 15019ULL: goto x86_l_3aab;
	case 15028ULL: goto x86_l_3ab4;
	case 15035ULL: goto x86_l_3abb;
	case 15040ULL: goto x86_l_3ac0;
	case 15045ULL: goto x86_l_3ac5;
	case 15050ULL: goto x86_l_3aca;
	case 15052ULL: goto x86_l_3acc;
	case 15054ULL: goto x86_l_3ace;
	case 15060ULL: goto x86_l_3ad4;
	case 15066ULL: goto x86_l_3ada;
	case 15069ULL: goto x86_l_3add;
	case 15074ULL: goto x86_l_3ae2;
	case 15080ULL: goto x86_l_3ae8;
	case 15085ULL: goto x86_l_3aed;
	case 15093ULL: goto x86_l_3af5;
	case 15097ULL: goto x86_l_3af9;
	case 15104ULL: goto x86_l_3b00;
	case 15109ULL: goto x86_l_3b05;
	case 15114ULL: goto x86_l_3b0a;
	case 15116ULL: goto x86_l_3b0c;
	case 15120ULL: goto x86_l_3b10;
	case 15122ULL: goto x86_l_3b12;
	case 15124ULL: goto x86_l_3b14;
	case 15130ULL: goto x86_l_3b1a;
	case 15133ULL: goto x86_l_3b1d;
	case 15138ULL: goto x86_l_3b22;
	case 15144ULL: goto x86_l_3b28;
	case 15149ULL: goto x86_l_3b2d;
	case 15157ULL: goto x86_l_3b35;
	case 15161ULL: goto x86_l_3b39;
	case 15168ULL: goto x86_l_3b40;
	case 15173ULL: goto x86_l_3b45;
	case 15178ULL: goto x86_l_3b4a;
	case 15180ULL: goto x86_l_3b4c;
	case 15185ULL: goto x86_l_3b51;
	case 15193ULL: goto x86_l_3b59;
	case 15196ULL: goto x86_l_3b5c;
	case 15204ULL: goto x86_l_3b64;
	case 15213ULL: goto x86_l_3b6d;
	case 15220ULL: goto x86_l_3b74;
	case 15225ULL: goto x86_l_3b79;
	case 15230ULL: goto x86_l_3b7e;
	case 15235ULL: goto x86_l_3b83;
	case 15237ULL: goto x86_l_3b85;
	case 15239ULL: goto x86_l_3b87;
	case 15245ULL: goto x86_l_3b8d;
	case 15251ULL: goto x86_l_3b93;
	case 15254ULL: goto x86_l_3b96;
	case 15259ULL: goto x86_l_3b9b;
	case 15265ULL: goto x86_l_3ba1;
	case 15270ULL: goto x86_l_3ba6;
	case 15278ULL: goto x86_l_3bae;
	case 15282ULL: goto x86_l_3bb2;
	case 15289ULL: goto x86_l_3bb9;
	case 15294ULL: goto x86_l_3bbe;
	case 15299ULL: goto x86_l_3bc3;
	case 15301ULL: goto x86_l_3bc5;
	case 15305ULL: goto x86_l_3bc9;
	case 15307ULL: goto x86_l_3bcb;
	case 15309ULL: goto x86_l_3bcd;
	case 15315ULL: goto x86_l_3bd3;
	case 15318ULL: goto x86_l_3bd6;
	case 15323ULL: goto x86_l_3bdb;
	case 15329ULL: goto x86_l_3be1;
	case 15334ULL: goto x86_l_3be6;
	case 15342ULL: goto x86_l_3bee;
	case 15346ULL: goto x86_l_3bf2;
	case 15353ULL: goto x86_l_3bf9;
	case 15358ULL: goto x86_l_3bfe;
	case 15363ULL: goto x86_l_3c03;
	case 15365ULL: goto x86_l_3c05;
	case 15370ULL: goto x86_l_3c0a;
	case 15378ULL: goto x86_l_3c12;
	case 15381ULL: goto x86_l_3c15;
	case 15389ULL: goto x86_l_3c1d;
	case 15398ULL: goto x86_l_3c26;
	case 15405ULL: goto x86_l_3c2d;
	case 15410ULL: goto x86_l_3c32;
	case 15415ULL: goto x86_l_3c37;
	case 15420ULL: goto x86_l_3c3c;
	case 15422ULL: goto x86_l_3c3e;
	case 15424ULL: goto x86_l_3c40;
	case 15430ULL: goto x86_l_3c46;
	case 15436ULL: goto x86_l_3c4c;
	case 15439ULL: goto x86_l_3c4f;
	case 15444ULL: goto x86_l_3c54;
	case 15450ULL: goto x86_l_3c5a;
	case 15455ULL: goto x86_l_3c5f;
	case 15463ULL: goto x86_l_3c67;
	case 15467ULL: goto x86_l_3c6b;
	case 15474ULL: goto x86_l_3c72;
	case 15479ULL: goto x86_l_3c77;
	case 15484ULL: goto x86_l_3c7c;
	case 15486ULL: goto x86_l_3c7e;
	case 15490ULL: goto x86_l_3c82;
	case 15492ULL: goto x86_l_3c84;
	case 15494ULL: goto x86_l_3c86;
	case 15500ULL: goto x86_l_3c8c;
	case 15503ULL: goto x86_l_3c8f;
	case 15508ULL: goto x86_l_3c94;
	case 15514ULL: goto x86_l_3c9a;
	case 15519ULL: goto x86_l_3c9f;
	case 15527ULL: goto x86_l_3ca7;
	case 15531ULL: goto x86_l_3cab;
	case 15538ULL: goto x86_l_3cb2;
	case 15543ULL: goto x86_l_3cb7;
	case 15548ULL: goto x86_l_3cbc;
	case 15550ULL: goto x86_l_3cbe;
	case 15555ULL: goto x86_l_3cc3;
	case 15563ULL: goto x86_l_3ccb;
	case 15566ULL: goto x86_l_3cce;
	case 15574ULL: goto x86_l_3cd6;
	case 15583ULL: goto x86_l_3cdf;
	case 15590ULL: goto x86_l_3ce6;
	case 15595ULL: goto x86_l_3ceb;
	case 15600ULL: goto x86_l_3cf0;
	case 15605ULL: goto x86_l_3cf5;
	case 15607ULL: goto x86_l_3cf7;
	case 15609ULL: goto x86_l_3cf9;
	case 15615ULL: goto x86_l_3cff;
	case 15621ULL: goto x86_l_3d05;
	case 15624ULL: goto x86_l_3d08;
	case 15629ULL: goto x86_l_3d0d;
	case 15635ULL: goto x86_l_3d13;
	case 15640ULL: goto x86_l_3d18;
	case 15648ULL: goto x86_l_3d20;
	case 15652ULL: goto x86_l_3d24;
	case 15659ULL: goto x86_l_3d2b;
	case 15664ULL: goto x86_l_3d30;
	case 15669ULL: goto x86_l_3d35;
	case 15671ULL: goto x86_l_3d37;
	case 15675ULL: goto x86_l_3d3b;
	case 15677ULL: goto x86_l_3d3d;
	case 15679ULL: goto x86_l_3d3f;
	case 15685ULL: goto x86_l_3d45;
	case 15688ULL: goto x86_l_3d48;
	case 15693ULL: goto x86_l_3d4d;
	case 15699ULL: goto x86_l_3d53;
	case 15704ULL: goto x86_l_3d58;
	case 15712ULL: goto x86_l_3d60;
	case 15716ULL: goto x86_l_3d64;
	case 15723ULL: goto x86_l_3d6b;
	case 15728ULL: goto x86_l_3d70;
	case 15733ULL: goto x86_l_3d75;
	case 15735ULL: goto x86_l_3d77;
	case 15740ULL: goto x86_l_3d7c;
	case 15748ULL: goto x86_l_3d84;
	case 15751ULL: goto x86_l_3d87;
	case 15759ULL: goto x86_l_3d8f;
	case 15768ULL: goto x86_l_3d98;
	case 15775ULL: goto x86_l_3d9f;
	case 15780ULL: goto x86_l_3da4;
	case 15785ULL: goto x86_l_3da9;
	case 15790ULL: goto x86_l_3dae;
	case 15792ULL: goto x86_l_3db0;
	case 15794ULL: goto x86_l_3db2;
	case 15800ULL: goto x86_l_3db8;
	case 15806ULL: goto x86_l_3dbe;
	case 15809ULL: goto x86_l_3dc1;
	case 15814ULL: goto x86_l_3dc6;
	case 15820ULL: goto x86_l_3dcc;
	case 15825ULL: goto x86_l_3dd1;
	case 15833ULL: goto x86_l_3dd9;
	case 15837ULL: goto x86_l_3ddd;
	case 15844ULL: goto x86_l_3de4;
	case 15849ULL: goto x86_l_3de9;
	case 15854ULL: goto x86_l_3dee;
	case 15856ULL: goto x86_l_3df0;
	case 15860ULL: goto x86_l_3df4;
	case 15862ULL: goto x86_l_3df6;
	case 15864ULL: goto x86_l_3df8;
	case 15870ULL: goto x86_l_3dfe;
	case 15873ULL: goto x86_l_3e01;
	case 15878ULL: goto x86_l_3e06;
	case 15884ULL: goto x86_l_3e0c;
	case 15889ULL: goto x86_l_3e11;
	case 15897ULL: goto x86_l_3e19;
	case 15901ULL: goto x86_l_3e1d;
	case 15908ULL: goto x86_l_3e24;
	case 15913ULL: goto x86_l_3e29;
	case 15918ULL: goto x86_l_3e2e;
	case 15920ULL: goto x86_l_3e30;
	case 15925ULL: goto x86_l_3e35;
	case 15933ULL: goto x86_l_3e3d;
	case 15936ULL: goto x86_l_3e40;
	case 15944ULL: goto x86_l_3e48;
	case 15953ULL: goto x86_l_3e51;
	case 15960ULL: goto x86_l_3e58;
	case 15965ULL: goto x86_l_3e5d;
	case 15970ULL: goto x86_l_3e62;
	case 15975ULL: goto x86_l_3e67;
	case 15977ULL: goto x86_l_3e69;
	case 15979ULL: goto x86_l_3e6b;
	case 15985ULL: goto x86_l_3e71;
	case 15991ULL: goto x86_l_3e77;
	case 15994ULL: goto x86_l_3e7a;
	case 15999ULL: goto x86_l_3e7f;
	case 16005ULL: goto x86_l_3e85;
	case 16010ULL: goto x86_l_3e8a;
	case 16018ULL: goto x86_l_3e92;
	case 16022ULL: goto x86_l_3e96;
	case 16029ULL: goto x86_l_3e9d;
	case 16034ULL: goto x86_l_3ea2;
	case 16039ULL: goto x86_l_3ea7;
	case 16041ULL: goto x86_l_3ea9;
	case 16045ULL: goto x86_l_3ead;
	case 16047ULL: goto x86_l_3eaf;
	case 16049ULL: goto x86_l_3eb1;
	case 16055ULL: goto x86_l_3eb7;
	case 16058ULL: goto x86_l_3eba;
	case 16063ULL: goto x86_l_3ebf;
	case 16069ULL: goto x86_l_3ec5;
	case 16074ULL: goto x86_l_3eca;
	case 16082ULL: goto x86_l_3ed2;
	case 16086ULL: goto x86_l_3ed6;
	case 16093ULL: goto x86_l_3edd;
	case 16098ULL: goto x86_l_3ee2;
	case 16103ULL: goto x86_l_3ee7;
	case 16105ULL: goto x86_l_3ee9;
	case 16110ULL: goto x86_l_3eee;
	case 16118ULL: goto x86_l_3ef6;
	case 16121ULL: goto x86_l_3ef9;
	case 16129ULL: goto x86_l_3f01;
	case 16138ULL: goto x86_l_3f0a;
	case 16145ULL: goto x86_l_3f11;
	case 16150ULL: goto x86_l_3f16;
	case 16155ULL: goto x86_l_3f1b;
	case 16160ULL: goto x86_l_3f20;
	case 16162ULL: goto x86_l_3f22;
	case 16164ULL: goto x86_l_3f24;
	case 16170ULL: goto x86_l_3f2a;
	case 16176ULL: goto x86_l_3f30;
	case 16179ULL: goto x86_l_3f33;
	case 16184ULL: goto x86_l_3f38;
	case 16190ULL: goto x86_l_3f3e;
	case 16195ULL: goto x86_l_3f43;
	case 16203ULL: goto x86_l_3f4b;
	case 16207ULL: goto x86_l_3f4f;
	case 16214ULL: goto x86_l_3f56;
	case 16219ULL: goto x86_l_3f5b;
	case 16224ULL: goto x86_l_3f60;
	case 16226ULL: goto x86_l_3f62;
	case 16230ULL: goto x86_l_3f66;
	case 16232ULL: goto x86_l_3f68;
	case 16234ULL: goto x86_l_3f6a;
	case 16240ULL: goto x86_l_3f70;
	case 16243ULL: goto x86_l_3f73;
	case 16248ULL: goto x86_l_3f78;
	case 16254ULL: goto x86_l_3f7e;
	case 16259ULL: goto x86_l_3f83;
	case 16267ULL: goto x86_l_3f8b;
	case 16271ULL: goto x86_l_3f8f;
	case 16278ULL: goto x86_l_3f96;
	case 16283ULL: goto x86_l_3f9b;
	case 16288ULL: goto x86_l_3fa0;
	case 16290ULL: goto x86_l_3fa2;
	case 16295ULL: goto x86_l_3fa7;
	case 16303ULL: goto x86_l_3faf;
	case 16306ULL: goto x86_l_3fb2;
	case 16314ULL: goto x86_l_3fba;
	case 16323ULL: goto x86_l_3fc3;
	case 16330ULL: goto x86_l_3fca;
	case 16335ULL: goto x86_l_3fcf;
	case 16340ULL: goto x86_l_3fd4;
	case 16345ULL: goto x86_l_3fd9;
	case 16347ULL: goto x86_l_3fdb;
	case 16349ULL: goto x86_l_3fdd;
	case 16355ULL: goto x86_l_3fe3;
	case 16361ULL: goto x86_l_3fe9;
	case 16364ULL: goto x86_l_3fec;
	case 16369ULL: goto x86_l_3ff1;
	case 16375ULL: goto x86_l_3ff7;
	case 16380ULL: goto x86_l_3ffc;
	case 16388ULL: goto x86_l_4004;
	case 16392ULL: goto x86_l_4008;
	case 16399ULL: goto x86_l_400f;
	case 16404ULL: goto x86_l_4014;
	case 16409ULL: goto x86_l_4019;
	case 16411ULL: goto x86_l_401b;
	case 16415ULL: goto x86_l_401f;
	case 16417ULL: goto x86_l_4021;
	case 16419ULL: goto x86_l_4023;
	case 16425ULL: goto x86_l_4029;
	case 16428ULL: goto x86_l_402c;
	case 16433ULL: goto x86_l_4031;
	case 16439ULL: goto x86_l_4037;
	case 16444ULL: goto x86_l_403c;
	case 16452ULL: goto x86_l_4044;
	case 16456ULL: goto x86_l_4048;
	case 16463ULL: goto x86_l_404f;
	case 16468ULL: goto x86_l_4054;
	case 16473ULL: goto x86_l_4059;
	case 16475ULL: goto x86_l_405b;
	case 16480ULL: goto x86_l_4060;
	case 16488ULL: goto x86_l_4068;
	case 16491ULL: goto x86_l_406b;
	case 16499ULL: goto x86_l_4073;
	case 16508ULL: goto x86_l_407c;
	case 16515ULL: goto x86_l_4083;
	case 16520ULL: goto x86_l_4088;
	case 16525ULL: goto x86_l_408d;
	case 16530ULL: goto x86_l_4092;
	case 16532ULL: goto x86_l_4094;
	case 16534ULL: goto x86_l_4096;
	case 16540ULL: goto x86_l_409c;
	case 16546ULL: goto x86_l_40a2;
	case 16549ULL: goto x86_l_40a5;
	case 16554ULL: goto x86_l_40aa;
	case 16560ULL: goto x86_l_40b0;
	case 16565ULL: goto x86_l_40b5;
	case 16573ULL: goto x86_l_40bd;
	case 16577ULL: goto x86_l_40c1;
	case 16584ULL: goto x86_l_40c8;
	case 16589ULL: goto x86_l_40cd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3953:
	/* 0x3953: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3958:
	/* 0x3958: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_395a:
	/* 0x395a: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_395c:
	/* 0x395c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3962:
	/* 0x3962: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3968:
	/* 0x3968: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_396b:
	/* 0x396b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3970:
	/* 0x3970: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3976:
	/* 0x3976: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_397b:
	/* 0x397b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3983:
	/* 0x3983: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3987:
	/* 0x3987: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_398e:
	/* 0x398e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3993:
	/* 0x3993: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3998:
	/* 0x3998: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_399a:
	/* 0x399a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_399e:
	/* 0x399e: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_39a0:
	/* 0x39a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39a2:
	/* 0x39a2: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_39a8:
	/* 0x39a8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_39ab:
	/* 0x39ab: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_39b0:
	/* 0x39b0: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_39b6:
	/* 0x39b6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39bb:
	/* 0x39bb: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_39c3:
	/* 0x39c3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_39c7:
	/* 0x39c7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_39ce:
	/* 0x39ce: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_39d3:
	/* 0x39d3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_39d8:
	/* 0x39d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39da:
	/* 0x39da: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_39df:
	/* 0x39df: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_39e7:
	/* 0x39e7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_39ea:
	/* 0x39ea: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_39f2:
	/* 0x39f2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_39fb:
	/* 0x39fb: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3a02:
	/* 0x3a02: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a07:
	/* 0x3a07: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a0c:
	/* 0x3a0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a11:
	/* 0x3a11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a13:
	/* 0x3a13: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_3a15:
	/* 0x3a15: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3a1b:
	/* 0x3a1b: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3a21:
	/* 0x3a21: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a24:
	/* 0x3a24: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3a29:
	/* 0x3a29: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3a2f:
	/* 0x3a2f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3a34:
	/* 0x3a34: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a3c:
	/* 0x3a3c: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3a40:
	/* 0x3a40: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3a47:
	/* 0x3a47: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a4c:
	/* 0x3a4c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3a51:
	/* 0x3a51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a53:
	/* 0x3a53: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3a57:
	/* 0x3a57: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_3a59:
	/* 0x3a59: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a5b:
	/* 0x3a5b: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3a61:
	/* 0x3a61: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a64:
	/* 0x3a64: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3a69:
	/* 0x3a69: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3a6f:
	/* 0x3a6f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a74:
	/* 0x3a74: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a7c:
	/* 0x3a7c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3a80:
	/* 0x3a80: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3a87:
	/* 0x3a87: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3a8c:
	/* 0x3a8c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3a91:
	/* 0x3a91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a93:
	/* 0x3a93: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3a98:
	/* 0x3a98: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3aa0:
	/* 0x3aa0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3aa3:
	/* 0x3aa3: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3aab:
	/* 0x3aab: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ab4:
	/* 0x3ab4: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3abb:
	/* 0x3abb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ac0:
	/* 0x3ac0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ac5:
	/* 0x3ac5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3aca:
	/* 0x3aca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3acc:
	/* 0x3acc: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_3ace:
	/* 0x3ace: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ad4:
	/* 0x3ad4: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3ada:
	/* 0x3ada: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3add:
	/* 0x3add: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3ae2:
	/* 0x3ae2: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3ae8:
	/* 0x3ae8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3aed:
	/* 0x3aed: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3af5:
	/* 0x3af5: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3af9:
	/* 0x3af9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b00:
	/* 0x3b00: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b05:
	/* 0x3b05: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3b0a:
	/* 0x3b0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b0c:
	/* 0x3b0c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3b10:
	/* 0x3b10: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_3b12:
	/* 0x3b12: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b14:
	/* 0x3b14: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3b1a:
	/* 0x3b1a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b1d:
	/* 0x3b1d: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3b22:
	/* 0x3b22: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3b28:
	/* 0x3b28: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b2d:
	/* 0x3b2d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b35:
	/* 0x3b35: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3b39:
	/* 0x3b39: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3b40:
	/* 0x3b40: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3b45:
	/* 0x3b45: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b4a:
	/* 0x3b4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b4c:
	/* 0x3b4c: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3b51:
	/* 0x3b51: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3b59:
	/* 0x3b59: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3b5c:
	/* 0x3b5c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3b64:
	/* 0x3b64: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3b6d:
	/* 0x3b6d: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3b74:
	/* 0x3b74: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b79:
	/* 0x3b79: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b7e:
	/* 0x3b7e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b83:
	/* 0x3b83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b85:
	/* 0x3b85: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_3b87:
	/* 0x3b87: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3b8d:
	/* 0x3b8d: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3b93:
	/* 0x3b93: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b96:
	/* 0x3b96: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3b9b:
	/* 0x3b9b: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3ba1:
	/* 0x3ba1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3ba6:
	/* 0x3ba6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3bae:
	/* 0x3bae: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3bb2:
	/* 0x3bb2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3bb9:
	/* 0x3bb9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bbe:
	/* 0x3bbe: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3bc3:
	/* 0x3bc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bc5:
	/* 0x3bc5: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3bc9:
	/* 0x3bc9: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_3bcb:
	/* 0x3bcb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3bcd:
	/* 0x3bcd: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3bd3:
	/* 0x3bd3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3bd6:
	/* 0x3bd6: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3bdb:
	/* 0x3bdb: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3be1:
	/* 0x3be1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3be6:
	/* 0x3be6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3bee:
	/* 0x3bee: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3bf2:
	/* 0x3bf2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3bf9:
	/* 0x3bf9: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3bfe:
	/* 0x3bfe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c03:
	/* 0x3c03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c05:
	/* 0x3c05: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3c0a:
	/* 0x3c0a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3c12:
	/* 0x3c12: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3c15:
	/* 0x3c15: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3c1d:
	/* 0x3c1d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3c26:
	/* 0x3c26: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3c2d:
	/* 0x3c2d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c32:
	/* 0x3c32: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c37:
	/* 0x3c37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c3c:
	/* 0x3c3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c3e:
	/* 0x3c3e: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_3c40:
	/* 0x3c40: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3c46:
	/* 0x3c46: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3c4c:
	/* 0x3c4c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c4f:
	/* 0x3c4f: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3c54:
	/* 0x3c54: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3c5a:
	/* 0x3c5a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3c5f:
	/* 0x3c5f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c67:
	/* 0x3c67: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3c6b:
	/* 0x3c6b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c72:
	/* 0x3c72: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c77:
	/* 0x3c77: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3c7c:
	/* 0x3c7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c7e:
	/* 0x3c7e: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3c82:
	/* 0x3c82: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_3c84:
	/* 0x3c84: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c86:
	/* 0x3c86: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3c8c:
	/* 0x3c8c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c8f:
	/* 0x3c8f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3c94:
	/* 0x3c94: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3c9a:
	/* 0x3c9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c9f:
	/* 0x3c9f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ca7:
	/* 0x3ca7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3cab:
	/* 0x3cab: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3cb2:
	/* 0x3cb2: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3cb7:
	/* 0x3cb7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3cbc:
	/* 0x3cbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cbe:
	/* 0x3cbe: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3cc3:
	/* 0x3cc3: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3ccb:
	/* 0x3ccb: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3cce:
	/* 0x3cce: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3cd6:
	/* 0x3cd6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3cdf:
	/* 0x3cdf: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3ce6:
	/* 0x3ce6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ceb:
	/* 0x3ceb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cf0:
	/* 0x3cf0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cf5:
	/* 0x3cf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cf7:
	/* 0x3cf7: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_3cf9:
	/* 0x3cf9: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3cff:
	/* 0x3cff: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3d05:
	/* 0x3d05: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d08:
	/* 0x3d08: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3d0d:
	/* 0x3d0d: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3d13:
	/* 0x3d13: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3d18:
	/* 0x3d18: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d20:
	/* 0x3d20: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3d24:
	/* 0x3d24: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3d2b:
	/* 0x3d2b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d30:
	/* 0x3d30: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3d35:
	/* 0x3d35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d37:
	/* 0x3d37: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3d3b:
	/* 0x3d3b: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_3d3d:
	/* 0x3d3d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d3f:
	/* 0x3d3f: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3d45:
	/* 0x3d45: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d48:
	/* 0x3d48: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3d4d:
	/* 0x3d4d: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3d53:
	/* 0x3d53: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d58:
	/* 0x3d58: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d60:
	/* 0x3d60: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3d64:
	/* 0x3d64: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3d6b:
	/* 0x3d6b: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3d70:
	/* 0x3d70: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d75:
	/* 0x3d75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d77:
	/* 0x3d77: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3d7c:
	/* 0x3d7c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3d84:
	/* 0x3d84: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3d87:
	/* 0x3d87: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3d8f:
	/* 0x3d8f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3d98:
	/* 0x3d98: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_3d9f:
	/* 0x3d9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3da4:
	/* 0x3da4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3da9:
	/* 0x3da9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dae:
	/* 0x3dae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3db0:
	/* 0x3db0: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_3db2:
	/* 0x3db2: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3db8:
	/* 0x3db8: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3dbe:
	/* 0x3dbe: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3dc1:
	/* 0x3dc1: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3dc6:
	/* 0x3dc6: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3dcc:
	/* 0x3dcc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3dd1:
	/* 0x3dd1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3dd9:
	/* 0x3dd9: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3ddd:
	/* 0x3ddd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3de4:
	/* 0x3de4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3de9:
	/* 0x3de9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3dee:
	/* 0x3dee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3df0:
	/* 0x3df0: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3df4:
	/* 0x3df4: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_3df6:
	/* 0x3df6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3df8:
	/* 0x3df8: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3dfe:
	/* 0x3dfe: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e01:
	/* 0x3e01: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3e06:
	/* 0x3e06: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3e0c:
	/* 0x3e0c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e11:
	/* 0x3e11: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e19:
	/* 0x3e19: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3e1d:
	/* 0x3e1d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3e24:
	/* 0x3e24: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3e29:
	/* 0x3e29: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e2e:
	/* 0x3e2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e30:
	/* 0x3e30: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3e35:
	/* 0x3e35: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3e3d:
	/* 0x3e3d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3e40:
	/* 0x3e40: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3e48:
	/* 0x3e48: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3e51:
	/* 0x3e51: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3e58:
	/* 0x3e58: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e5d:
	/* 0x3e5d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e62:
	/* 0x3e62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e67:
	/* 0x3e67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e69:
	/* 0x3e69: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_3e6b:
	/* 0x3e6b: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3e71:
	/* 0x3e71: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3e77:
	/* 0x3e77: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e7a:
	/* 0x3e7a: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3e7f:
	/* 0x3e7f: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3e85:
	/* 0x3e85: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3e8a:
	/* 0x3e8a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e92:
	/* 0x3e92: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3e96:
	/* 0x3e96: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3e9d:
	/* 0x3e9d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ea2:
	/* 0x3ea2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3ea7:
	/* 0x3ea7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ea9:
	/* 0x3ea9: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3ead:
	/* 0x3ead: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_3eaf:
	/* 0x3eaf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3eb1:
	/* 0x3eb1: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3eb7:
	/* 0x3eb7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3eba:
	/* 0x3eba: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3ebf:
	/* 0x3ebf: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3ec5:
	/* 0x3ec5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3eca:
	/* 0x3eca: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ed2:
	/* 0x3ed2: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3ed6:
	/* 0x3ed6: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3edd:
	/* 0x3edd: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3ee2:
	/* 0x3ee2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ee7:
	/* 0x3ee7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ee9:
	/* 0x3ee9: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
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
	/* 0x3f0a: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_3f11:
	/* 0x3f11: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f16:
	/* 0x3f16: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f1b:
	/* 0x3f1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f20:
	/* 0x3f20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f22:
	/* 0x3f22: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_3f24:
	/* 0x3f24: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3f2a:
	/* 0x3f2a: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3f30:
	/* 0x3f30: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f33:
	/* 0x3f33: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3f38:
	/* 0x3f38: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3f3e:
	/* 0x3f3e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3f43:
	/* 0x3f43: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3f4b:
	/* 0x3f4b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3f4f:
	/* 0x3f4f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3f56:
	/* 0x3f56: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f5b:
	/* 0x3f5b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3f60:
	/* 0x3f60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f62:
	/* 0x3f62: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3f66:
	/* 0x3f66: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_3f68:
	/* 0x3f68: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f6a:
	/* 0x3f6a: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_3f70:
	/* 0x3f70: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f73:
	/* 0x3f73: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3f78:
	/* 0x3f78: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3f7e:
	/* 0x3f7e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f83:
	/* 0x3f83: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3f8b:
	/* 0x3f8b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3f8f:
	/* 0x3f8f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3f96:
	/* 0x3f96: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3f9b:
	/* 0x3f9b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3fa0:
	/* 0x3fa0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fa2:
	/* 0x3fa2: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3fa7:
	/* 0x3fa7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3faf:
	/* 0x3faf: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3fb2:
	/* 0x3fb2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3fba:
	/* 0x3fba: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3fc3:
	/* 0x3fc3: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_3fca:
	/* 0x3fca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3fcf:
	/* 0x3fcf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fd4:
	/* 0x3fd4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fd9:
	/* 0x3fd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fdb:
	/* 0x3fdb: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_3fdd:
	/* 0x3fdd: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3fe3:
	/* 0x3fe3: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_3fe9:
	/* 0x3fe9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3fec:
	/* 0x3fec: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3ff1:
	/* 0x3ff1: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_3ff7:
	/* 0x3ff7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3ffc:
	/* 0x3ffc: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4004:
	/* 0x4004: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4008:
	/* 0x4008: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_400f:
	/* 0x400f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4014:
	/* 0x4014: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4019:
	/* 0x4019: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_401b:
	/* 0x401b: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_401f:
	/* 0x401f: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_4021:
	/* 0x4021: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4023:
	/* 0x4023: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_4029:
	/* 0x4029: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_402c:
	/* 0x402c: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4031:
	/* 0x4031: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4037:
	/* 0x4037: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_403c:
	/* 0x403c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4044:
	/* 0x4044: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4048:
	/* 0x4048: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_404f:
	/* 0x404f: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4054:
	/* 0x4054: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4059:
	/* 0x4059: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_405b:
	/* 0x405b: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4060:
	/* 0x4060: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4068:
	/* 0x4068: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_406b:
	/* 0x406b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4073:
	/* 0x4073: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_407c:
	/* 0x407c: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_4083:
	/* 0x4083: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4088:
	/* 0x4088: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_408d:
	/* 0x408d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4092:
	/* 0x4092: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4094:
	/* 0x4094: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_4096:
	/* 0x4096: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_409c:
	/* 0x409c: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_40a2:
	/* 0x40a2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_40a5:
	/* 0x40a5: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_40aa:
	/* 0x40aa: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_40b0:
	/* 0x40b0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_40b5:
	/* 0x40b5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_40bd:
	/* 0x40bd: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_40c1:
	/* 0x40c1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_40c8:
	/* 0x40c8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40cd:
	/* 0x40cd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
	return 16594ULL;
}

static __noinline __u64 tracee_syscall__execve_exit_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16594ULL: goto x86_l_40d2;
	case 16596ULL: goto x86_l_40d4;
	case 16600ULL: goto x86_l_40d8;
	case 16602ULL: goto x86_l_40da;
	case 16604ULL: goto x86_l_40dc;
	case 16610ULL: goto x86_l_40e2;
	case 16613ULL: goto x86_l_40e5;
	case 16618ULL: goto x86_l_40ea;
	case 16624ULL: goto x86_l_40f0;
	case 16629ULL: goto x86_l_40f5;
	case 16637ULL: goto x86_l_40fd;
	case 16641ULL: goto x86_l_4101;
	case 16648ULL: goto x86_l_4108;
	case 16653ULL: goto x86_l_410d;
	case 16658ULL: goto x86_l_4112;
	case 16660ULL: goto x86_l_4114;
	case 16665ULL: goto x86_l_4119;
	case 16673ULL: goto x86_l_4121;
	case 16676ULL: goto x86_l_4124;
	case 16684ULL: goto x86_l_412c;
	case 16693ULL: goto x86_l_4135;
	case 16700ULL: goto x86_l_413c;
	case 16705ULL: goto x86_l_4141;
	case 16710ULL: goto x86_l_4146;
	case 16715ULL: goto x86_l_414b;
	case 16717ULL: goto x86_l_414d;
	case 16719ULL: goto x86_l_414f;
	case 16725ULL: goto x86_l_4155;
	case 16731ULL: goto x86_l_415b;
	case 16734ULL: goto x86_l_415e;
	case 16739ULL: goto x86_l_4163;
	case 16745ULL: goto x86_l_4169;
	case 16750ULL: goto x86_l_416e;
	case 16758ULL: goto x86_l_4176;
	case 16762ULL: goto x86_l_417a;
	case 16769ULL: goto x86_l_4181;
	case 16774ULL: goto x86_l_4186;
	case 16779ULL: goto x86_l_418b;
	case 16781ULL: goto x86_l_418d;
	case 16785ULL: goto x86_l_4191;
	case 16787ULL: goto x86_l_4193;
	case 16789ULL: goto x86_l_4195;
	case 16795ULL: goto x86_l_419b;
	case 16798ULL: goto x86_l_419e;
	case 16803ULL: goto x86_l_41a3;
	case 16809ULL: goto x86_l_41a9;
	case 16814ULL: goto x86_l_41ae;
	case 16822ULL: goto x86_l_41b6;
	case 16826ULL: goto x86_l_41ba;
	case 16833ULL: goto x86_l_41c1;
	case 16838ULL: goto x86_l_41c6;
	case 16843ULL: goto x86_l_41cb;
	case 16845ULL: goto x86_l_41cd;
	case 16850ULL: goto x86_l_41d2;
	case 16858ULL: goto x86_l_41da;
	case 16861ULL: goto x86_l_41dd;
	case 16869ULL: goto x86_l_41e5;
	case 16878ULL: goto x86_l_41ee;
	case 16885ULL: goto x86_l_41f5;
	case 16890ULL: goto x86_l_41fa;
	case 16895ULL: goto x86_l_41ff;
	case 16900ULL: goto x86_l_4204;
	case 16902ULL: goto x86_l_4206;
	case 16904ULL: goto x86_l_4208;
	case 16910ULL: goto x86_l_420e;
	case 16916ULL: goto x86_l_4214;
	case 16919ULL: goto x86_l_4217;
	case 16924ULL: goto x86_l_421c;
	case 16930ULL: goto x86_l_4222;
	case 16935ULL: goto x86_l_4227;
	case 16943ULL: goto x86_l_422f;
	case 16947ULL: goto x86_l_4233;
	case 16954ULL: goto x86_l_423a;
	case 16959ULL: goto x86_l_423f;
	case 16964ULL: goto x86_l_4244;
	case 16966ULL: goto x86_l_4246;
	case 16970ULL: goto x86_l_424a;
	case 16972ULL: goto x86_l_424c;
	case 16974ULL: goto x86_l_424e;
	case 16980ULL: goto x86_l_4254;
	case 16983ULL: goto x86_l_4257;
	case 16988ULL: goto x86_l_425c;
	case 16994ULL: goto x86_l_4262;
	case 16999ULL: goto x86_l_4267;
	case 17007ULL: goto x86_l_426f;
	case 17011ULL: goto x86_l_4273;
	case 17018ULL: goto x86_l_427a;
	case 17023ULL: goto x86_l_427f;
	case 17028ULL: goto x86_l_4284;
	case 17030ULL: goto x86_l_4286;
	case 17035ULL: goto x86_l_428b;
	case 17043ULL: goto x86_l_4293;
	case 17046ULL: goto x86_l_4296;
	case 17054ULL: goto x86_l_429e;
	case 17063ULL: goto x86_l_42a7;
	case 17070ULL: goto x86_l_42ae;
	case 17075ULL: goto x86_l_42b3;
	case 17080ULL: goto x86_l_42b8;
	case 17085ULL: goto x86_l_42bd;
	case 17087ULL: goto x86_l_42bf;
	case 17089ULL: goto x86_l_42c1;
	case 17095ULL: goto x86_l_42c7;
	case 17101ULL: goto x86_l_42cd;
	case 17104ULL: goto x86_l_42d0;
	case 17109ULL: goto x86_l_42d5;
	case 17115ULL: goto x86_l_42db;
	case 17120ULL: goto x86_l_42e0;
	case 17128ULL: goto x86_l_42e8;
	case 17132ULL: goto x86_l_42ec;
	case 17139ULL: goto x86_l_42f3;
	case 17144ULL: goto x86_l_42f8;
	case 17149ULL: goto x86_l_42fd;
	case 17151ULL: goto x86_l_42ff;
	case 17155ULL: goto x86_l_4303;
	case 17157ULL: goto x86_l_4305;
	case 17159ULL: goto x86_l_4307;
	case 17165ULL: goto x86_l_430d;
	case 17168ULL: goto x86_l_4310;
	case 17173ULL: goto x86_l_4315;
	case 17179ULL: goto x86_l_431b;
	case 17184ULL: goto x86_l_4320;
	case 17192ULL: goto x86_l_4328;
	case 17196ULL: goto x86_l_432c;
	case 17203ULL: goto x86_l_4333;
	case 17208ULL: goto x86_l_4338;
	case 17213ULL: goto x86_l_433d;
	case 17215ULL: goto x86_l_433f;
	case 17220ULL: goto x86_l_4344;
	case 17228ULL: goto x86_l_434c;
	case 17231ULL: goto x86_l_434f;
	case 17239ULL: goto x86_l_4357;
	case 17248ULL: goto x86_l_4360;
	case 17255ULL: goto x86_l_4367;
	case 17260ULL: goto x86_l_436c;
	case 17265ULL: goto x86_l_4371;
	case 17270ULL: goto x86_l_4376;
	case 17272ULL: goto x86_l_4378;
	case 17274ULL: goto x86_l_437a;
	case 17280ULL: goto x86_l_4380;
	case 17286ULL: goto x86_l_4386;
	case 17289ULL: goto x86_l_4389;
	case 17294ULL: goto x86_l_438e;
	case 17300ULL: goto x86_l_4394;
	case 17305ULL: goto x86_l_4399;
	case 17313ULL: goto x86_l_43a1;
	case 17317ULL: goto x86_l_43a5;
	case 17324ULL: goto x86_l_43ac;
	case 17329ULL: goto x86_l_43b1;
	case 17334ULL: goto x86_l_43b6;
	case 17336ULL: goto x86_l_43b8;
	case 17340ULL: goto x86_l_43bc;
	case 17342ULL: goto x86_l_43be;
	case 17344ULL: goto x86_l_43c0;
	case 17350ULL: goto x86_l_43c6;
	case 17353ULL: goto x86_l_43c9;
	case 17358ULL: goto x86_l_43ce;
	case 17364ULL: goto x86_l_43d4;
	case 17369ULL: goto x86_l_43d9;
	case 17377ULL: goto x86_l_43e1;
	case 17381ULL: goto x86_l_43e5;
	case 17388ULL: goto x86_l_43ec;
	case 17393ULL: goto x86_l_43f1;
	case 17398ULL: goto x86_l_43f6;
	case 17400ULL: goto x86_l_43f8;
	case 17405ULL: goto x86_l_43fd;
	case 17413ULL: goto x86_l_4405;
	case 17416ULL: goto x86_l_4408;
	case 17424ULL: goto x86_l_4410;
	case 17433ULL: goto x86_l_4419;
	case 17440ULL: goto x86_l_4420;
	case 17445ULL: goto x86_l_4425;
	case 17450ULL: goto x86_l_442a;
	case 17455ULL: goto x86_l_442f;
	case 17457ULL: goto x86_l_4431;
	case 17459ULL: goto x86_l_4433;
	case 17465ULL: goto x86_l_4439;
	case 17471ULL: goto x86_l_443f;
	case 17474ULL: goto x86_l_4442;
	case 17479ULL: goto x86_l_4447;
	case 17485ULL: goto x86_l_444d;
	case 17490ULL: goto x86_l_4452;
	case 17498ULL: goto x86_l_445a;
	case 17502ULL: goto x86_l_445e;
	case 17509ULL: goto x86_l_4465;
	case 17514ULL: goto x86_l_446a;
	case 17519ULL: goto x86_l_446f;
	case 17521ULL: goto x86_l_4471;
	case 17525ULL: goto x86_l_4475;
	case 17527ULL: goto x86_l_4477;
	case 17529ULL: goto x86_l_4479;
	case 17535ULL: goto x86_l_447f;
	case 17538ULL: goto x86_l_4482;
	case 17543ULL: goto x86_l_4487;
	case 17549ULL: goto x86_l_448d;
	case 17554ULL: goto x86_l_4492;
	case 17562ULL: goto x86_l_449a;
	case 17566ULL: goto x86_l_449e;
	case 17573ULL: goto x86_l_44a5;
	case 17578ULL: goto x86_l_44aa;
	case 17583ULL: goto x86_l_44af;
	case 17585ULL: goto x86_l_44b1;
	case 17590ULL: goto x86_l_44b6;
	case 17598ULL: goto x86_l_44be;
	case 17601ULL: goto x86_l_44c1;
	case 17609ULL: goto x86_l_44c9;
	case 17618ULL: goto x86_l_44d2;
	case 17625ULL: goto x86_l_44d9;
	case 17630ULL: goto x86_l_44de;
	case 17635ULL: goto x86_l_44e3;
	case 17640ULL: goto x86_l_44e8;
	case 17642ULL: goto x86_l_44ea;
	case 17644ULL: goto x86_l_44ec;
	case 17650ULL: goto x86_l_44f2;
	case 17656ULL: goto x86_l_44f8;
	case 17659ULL: goto x86_l_44fb;
	case 17664ULL: goto x86_l_4500;
	case 17670ULL: goto x86_l_4506;
	case 17675ULL: goto x86_l_450b;
	case 17683ULL: goto x86_l_4513;
	case 17687ULL: goto x86_l_4517;
	case 17694ULL: goto x86_l_451e;
	case 17699ULL: goto x86_l_4523;
	case 17704ULL: goto x86_l_4528;
	case 17706ULL: goto x86_l_452a;
	case 17710ULL: goto x86_l_452e;
	case 17712ULL: goto x86_l_4530;
	case 17714ULL: goto x86_l_4532;
	case 17720ULL: goto x86_l_4538;
	case 17723ULL: goto x86_l_453b;
	case 17728ULL: goto x86_l_4540;
	case 17734ULL: goto x86_l_4546;
	case 17739ULL: goto x86_l_454b;
	case 17747ULL: goto x86_l_4553;
	case 17751ULL: goto x86_l_4557;
	case 17758ULL: goto x86_l_455e;
	case 17763ULL: goto x86_l_4563;
	case 17768ULL: goto x86_l_4568;
	case 17770ULL: goto x86_l_456a;
	case 17775ULL: goto x86_l_456f;
	case 17783ULL: goto x86_l_4577;
	case 17786ULL: goto x86_l_457a;
	case 17794ULL: goto x86_l_4582;
	case 17803ULL: goto x86_l_458b;
	case 17810ULL: goto x86_l_4592;
	case 17815ULL: goto x86_l_4597;
	case 17820ULL: goto x86_l_459c;
	case 17825ULL: goto x86_l_45a1;
	case 17827ULL: goto x86_l_45a3;
	case 17829ULL: goto x86_l_45a5;
	case 17835ULL: goto x86_l_45ab;
	case 17841ULL: goto x86_l_45b1;
	case 17844ULL: goto x86_l_45b4;
	case 17849ULL: goto x86_l_45b9;
	case 17855ULL: goto x86_l_45bf;
	case 17860ULL: goto x86_l_45c4;
	case 17868ULL: goto x86_l_45cc;
	case 17872ULL: goto x86_l_45d0;
	case 17879ULL: goto x86_l_45d7;
	case 17884ULL: goto x86_l_45dc;
	case 17889ULL: goto x86_l_45e1;
	case 17891ULL: goto x86_l_45e3;
	case 17895ULL: goto x86_l_45e7;
	case 17897ULL: goto x86_l_45e9;
	case 17899ULL: goto x86_l_45eb;
	case 17905ULL: goto x86_l_45f1;
	case 17908ULL: goto x86_l_45f4;
	case 17913ULL: goto x86_l_45f9;
	case 17919ULL: goto x86_l_45ff;
	case 17924ULL: goto x86_l_4604;
	case 17932ULL: goto x86_l_460c;
	case 17936ULL: goto x86_l_4610;
	case 17943ULL: goto x86_l_4617;
	case 17948ULL: goto x86_l_461c;
	case 17953ULL: goto x86_l_4621;
	case 17955ULL: goto x86_l_4623;
	case 17960ULL: goto x86_l_4628;
	case 17968ULL: goto x86_l_4630;
	case 17971ULL: goto x86_l_4633;
	case 17979ULL: goto x86_l_463b;
	case 17988ULL: goto x86_l_4644;
	case 17995ULL: goto x86_l_464b;
	case 18000ULL: goto x86_l_4650;
	case 18005ULL: goto x86_l_4655;
	case 18010ULL: goto x86_l_465a;
	case 18013ULL: goto x86_l_465d;
	case 18015ULL: goto x86_l_465f;
	case 18017ULL: goto x86_l_4661;
	case 18023ULL: goto x86_l_4667;
	case 18029ULL: goto x86_l_466d;
	case 18032ULL: goto x86_l_4670;
	case 18037ULL: goto x86_l_4675;
	case 18043ULL: goto x86_l_467b;
	case 18048ULL: goto x86_l_4680;
	case 18056ULL: goto x86_l_4688;
	case 18060ULL: goto x86_l_468c;
	case 18067ULL: goto x86_l_4693;
	case 18072ULL: goto x86_l_4698;
	case 18077ULL: goto x86_l_469d;
	case 18079ULL: goto x86_l_469f;
	case 18083ULL: goto x86_l_46a3;
	case 18085ULL: goto x86_l_46a5;
	case 18087ULL: goto x86_l_46a7;
	case 18093ULL: goto x86_l_46ad;
	case 18096ULL: goto x86_l_46b0;
	case 18101ULL: goto x86_l_46b5;
	case 18107ULL: goto x86_l_46bb;
	case 18112ULL: goto x86_l_46c0;
	case 18120ULL: goto x86_l_46c8;
	case 18124ULL: goto x86_l_46cc;
	case 18131ULL: goto x86_l_46d3;
	case 18136ULL: goto x86_l_46d8;
	case 18141ULL: goto x86_l_46dd;
	case 18143ULL: goto x86_l_46df;
	case 18148ULL: goto x86_l_46e4;
	case 18156ULL: goto x86_l_46ec;
	case 18159ULL: goto x86_l_46ef;
	case 18167ULL: goto x86_l_46f7;
	case 18175ULL: goto x86_l_46ff;
	case 18178ULL: goto x86_l_4702;
	case 18183ULL: goto x86_l_4707;
	case 18185ULL: goto x86_l_4709;
	case 18190ULL: goto x86_l_470e;
	case 18195ULL: goto x86_l_4713;
	case 18203ULL: goto x86_l_471b;
	case 18207ULL: goto x86_l_471f;
	case 18214ULL: goto x86_l_4726;
	case 18219ULL: goto x86_l_472b;
	case 18224ULL: goto x86_l_4730;
	case 18226ULL: goto x86_l_4732;
	case 18230ULL: goto x86_l_4736;
	case 18232ULL: goto x86_l_4738;
	case 18234ULL: goto x86_l_473a;
	case 18240ULL: goto x86_l_4740;
	case 18243ULL: goto x86_l_4743;
	case 18248ULL: goto x86_l_4748;
	case 18254ULL: goto x86_l_474e;
	case 18259ULL: goto x86_l_4753;
	case 18267ULL: goto x86_l_475b;
	case 18271ULL: goto x86_l_475f;
	case 18278ULL: goto x86_l_4766;
	case 18283ULL: goto x86_l_476b;
	case 18288ULL: goto x86_l_4770;
	case 18290ULL: goto x86_l_4772;
	case 18295ULL: goto x86_l_4777;
	case 18303ULL: goto x86_l_477f;
	case 18306ULL: goto x86_l_4782;
	case 18314ULL: goto x86_l_478a;
	case 18316ULL: goto x86_l_478c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_40d2:
	/* 0x40d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40d4:
	/* 0x40d4: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_40d8:
	/* 0x40d8: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_40da:
	/* 0x40da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40dc:
	/* 0x40dc: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_40e2:
	/* 0x40e2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_40e5:
	/* 0x40e5: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_40ea:
	/* 0x40ea: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_40f0:
	/* 0x40f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_40f5:
	/* 0x40f5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_40fd:
	/* 0x40fd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4101:
	/* 0x4101: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4108:
	/* 0x4108: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_410d:
	/* 0x410d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4112:
	/* 0x4112: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4114:
	/* 0x4114: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4119:
	/* 0x4119: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4121:
	/* 0x4121: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4124:
	/* 0x4124: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_412c:
	/* 0x412c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4135:
	/* 0x4135: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_413c:
	/* 0x413c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4141:
	/* 0x4141: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4146:
	/* 0x4146: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_414b:
	/* 0x414b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_414d:
	/* 0x414d: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_414f:
	/* 0x414f: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4155:
	/* 0x4155: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_415b:
	/* 0x415b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_415e:
	/* 0x415e: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4163:
	/* 0x4163: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4169:
	/* 0x4169: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_416e:
	/* 0x416e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4176:
	/* 0x4176: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_417a:
	/* 0x417a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4181:
	/* 0x4181: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4186:
	/* 0x4186: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_418b:
	/* 0x418b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_418d:
	/* 0x418d: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4191:
	/* 0x4191: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_4193:
	/* 0x4193: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4195:
	/* 0x4195: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_419b:
	/* 0x419b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_419e:
	/* 0x419e: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_41a3:
	/* 0x41a3: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_41a9:
	/* 0x41a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41ae:
	/* 0x41ae: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_41b6:
	/* 0x41b6: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_41ba:
	/* 0x41ba: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_41c1:
	/* 0x41c1: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_41c6:
	/* 0x41c6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_41cb:
	/* 0x41cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41cd:
	/* 0x41cd: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_41d2:
	/* 0x41d2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_41da:
	/* 0x41da: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_41dd:
	/* 0x41dd: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_41e5:
	/* 0x41e5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_41ee:
	/* 0x41ee: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_41f5:
	/* 0x41f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41fa:
	/* 0x41fa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41ff:
	/* 0x41ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4204:
	/* 0x4204: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4206:
	/* 0x4206: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_4208:
	/* 0x4208: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_420e:
	/* 0x420e: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_4214:
	/* 0x4214: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4217:
	/* 0x4217: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_421c:
	/* 0x421c: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4222:
	/* 0x4222: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4227:
	/* 0x4227: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_422f:
	/* 0x422f: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4233:
	/* 0x4233: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_423a:
	/* 0x423a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_423f:
	/* 0x423f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4244:
	/* 0x4244: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4246:
	/* 0x4246: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_424a:
	/* 0x424a: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_424c:
	/* 0x424c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_424e:
	/* 0x424e: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_4254:
	/* 0x4254: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4257:
	/* 0x4257: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_425c:
	/* 0x425c: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4262:
	/* 0x4262: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4267:
	/* 0x4267: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_426f:
	/* 0x426f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4273:
	/* 0x4273: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_427a:
	/* 0x427a: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_427f:
	/* 0x427f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4284:
	/* 0x4284: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4286:
	/* 0x4286: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_428b:
	/* 0x428b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4293:
	/* 0x4293: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4296:
	/* 0x4296: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_429e:
	/* 0x429e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_42a7:
	/* 0x42a7: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_42ae:
	/* 0x42ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_42b3:
	/* 0x42b3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42b8:
	/* 0x42b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42bd:
	/* 0x42bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42bf:
	/* 0x42bf: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_42c1:
	/* 0x42c1: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_42c7:
	/* 0x42c7: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_42cd:
	/* 0x42cd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_42d0:
	/* 0x42d0: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_42d5:
	/* 0x42d5: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_42db:
	/* 0x42db: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_42e0:
	/* 0x42e0: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_42e8:
	/* 0x42e8: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_42ec:
	/* 0x42ec: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_42f3:
	/* 0x42f3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42f8:
	/* 0x42f8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_42fd:
	/* 0x42fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42ff:
	/* 0x42ff: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4303:
	/* 0x4303: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_4305:
	/* 0x4305: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4307:
	/* 0x4307: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_430d:
	/* 0x430d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4310:
	/* 0x4310: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4315:
	/* 0x4315: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_431b:
	/* 0x431b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4320:
	/* 0x4320: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4328:
	/* 0x4328: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_432c:
	/* 0x432c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4333:
	/* 0x4333: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4338:
	/* 0x4338: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_433d:
	/* 0x433d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_433f:
	/* 0x433f: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4344:
	/* 0x4344: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_434c:
	/* 0x434c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_434f:
	/* 0x434f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4357:
	/* 0x4357: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4360:
	/* 0x4360: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_4367:
	/* 0x4367: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_436c:
	/* 0x436c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4371:
	/* 0x4371: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4376:
	/* 0x4376: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4378:
	/* 0x4378: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_437a:
	/* 0x437a: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4380:
	/* 0x4380: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_4386:
	/* 0x4386: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4389:
	/* 0x4389: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_438e:
	/* 0x438e: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4394:
	/* 0x4394: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4399:
	/* 0x4399: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_43a1:
	/* 0x43a1: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_43a5:
	/* 0x43a5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_43ac:
	/* 0x43ac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43b1:
	/* 0x43b1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_43b6:
	/* 0x43b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43b8:
	/* 0x43b8: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_43bc:
	/* 0x43bc: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_43be:
	/* 0x43be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_43c0:
	/* 0x43c0: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_43c6:
	/* 0x43c6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_43c9:
	/* 0x43c9: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_43ce:
	/* 0x43ce: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_43d4:
	/* 0x43d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_43d9:
	/* 0x43d9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_43e1:
	/* 0x43e1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_43e5:
	/* 0x43e5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_43ec:
	/* 0x43ec: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_43f1:
	/* 0x43f1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_43f6:
	/* 0x43f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43f8:
	/* 0x43f8: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_43fd:
	/* 0x43fd: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4405:
	/* 0x4405: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4408:
	/* 0x4408: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4410:
	/* 0x4410: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4419:
	/* 0x4419: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_4420:
	/* 0x4420: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4425:
	/* 0x4425: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_442a:
	/* 0x442a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_442f:
	/* 0x442f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4431:
	/* 0x4431: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_4433:
	/* 0x4433: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4439:
	/* 0x4439: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_443f:
	/* 0x443f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4442:
	/* 0x4442: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4447:
	/* 0x4447: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_444d:
	/* 0x444d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4452:
	/* 0x4452: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_445a:
	/* 0x445a: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_445e:
	/* 0x445e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4465:
	/* 0x4465: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_446a:
	/* 0x446a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_446f:
	/* 0x446f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4471:
	/* 0x4471: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4475:
	/* 0x4475: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_4477:
	/* 0x4477: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4479:
	/* 0x4479: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_447f:
	/* 0x447f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4482:
	/* 0x4482: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4487:
	/* 0x4487: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_448d:
	/* 0x448d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4492:
	/* 0x4492: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_449a:
	/* 0x449a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_449e:
	/* 0x449e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_44a5:
	/* 0x44a5: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_44aa:
	/* 0x44aa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_44af:
	/* 0x44af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44b1:
	/* 0x44b1: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_44b6:
	/* 0x44b6: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_44be:
	/* 0x44be: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_44c1:
	/* 0x44c1: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_44c9:
	/* 0x44c9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_44d2:
	/* 0x44d2: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_44d9:
	/* 0x44d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_44de:
	/* 0x44de: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44e3:
	/* 0x44e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44e8:
	/* 0x44e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44ea:
	/* 0x44ea: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_44ec:
	/* 0x44ec: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_44f2:
	/* 0x44f2: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_44f8:
	/* 0x44f8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_44fb:
	/* 0x44fb: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4500:
	/* 0x4500: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4506:
	/* 0x4506: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_450b:
	/* 0x450b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4513:
	/* 0x4513: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4517:
	/* 0x4517: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_451e:
	/* 0x451e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4523:
	/* 0x4523: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4528:
	/* 0x4528: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_452a:
	/* 0x452a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_452e:
	/* 0x452e: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_4530:
	/* 0x4530: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4532:
	/* 0x4532: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_4538:
	/* 0x4538: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_453b:
	/* 0x453b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4540:
	/* 0x4540: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_4546:
	/* 0x4546: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_454b:
	/* 0x454b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4553:
	/* 0x4553: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4557:
	/* 0x4557: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_455e:
	/* 0x455e: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4563:
	/* 0x4563: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4568:
	/* 0x4568: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_456a:
	/* 0x456a: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_456f:
	/* 0x456f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4577:
	/* 0x4577: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_457a:
	/* 0x457a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4582:
	/* 0x4582: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_458b:
	/* 0x458b: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_4592:
	/* 0x4592: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4597:
	/* 0x4597: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_459c:
	/* 0x459c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45a1:
	/* 0x45a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45a3:
	/* 0x45a3: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_45a5:
	/* 0x45a5: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_45ab:
	/* 0x45ab: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_45b1:
	/* 0x45b1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_45b4:
	/* 0x45b4: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_45b9:
	/* 0x45b9: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_45bf:
	/* 0x45bf: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_45c4:
	/* 0x45c4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_45cc:
	/* 0x45cc: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_45d0:
	/* 0x45d0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_45d7:
	/* 0x45d7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45dc:
	/* 0x45dc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_45e1:
	/* 0x45e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45e3:
	/* 0x45e3: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_45e7:
	/* 0x45e7: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_45e9:
	/* 0x45e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45eb:
	/* 0x45eb: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_45f1:
	/* 0x45f1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_45f4:
	/* 0x45f4: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_45f9:
	/* 0x45f9: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_45ff:
	/* 0x45ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4604:
	/* 0x4604: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_460c:
	/* 0x460c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4610:
	/* 0x4610: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4617:
	/* 0x4617: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_461c:
	/* 0x461c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4621:
	/* 0x4621: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4623:
	/* 0x4623: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4628:
	/* 0x4628: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4630:
	/* 0x4630: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4633:
	/* 0x4633: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_463b:
	/* 0x463b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4644:
	/* 0x4644: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_464b:
	/* 0x464b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4650:
	/* 0x4650: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4655:
	/* 0x4655: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_465a:
	/* 0x465a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_465d:
	/* 0x465d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_465f:
	/* 0x465f: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_4661:
	/* 0x4661: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4667:
	/* 0x4667: je     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3029ULL;
	}
x86_l_466d:
	/* 0x466d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4670:
	/* 0x4670: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4675:
	/* 0x4675: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_467b:
	/* 0x467b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4680:
	/* 0x4680: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4688:
	/* 0x4688: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_468c:
	/* 0x468c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4693:
	/* 0x4693: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4698:
	/* 0x4698: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_469d:
	/* 0x469d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_469f:
	/* 0x469f: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_46a3:
	/* 0x46a3: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_46a5:
	/* 0x46a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46a7:
	/* 0x46a7: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_46ad:
	/* 0x46ad: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_46b0:
	/* 0x46b0: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_46b5:
	/* 0x46b5: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_46bb:
	/* 0x46bb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_46c0:
	/* 0x46c0: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_46c8:
	/* 0x46c8: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_46cc:
	/* 0x46cc: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_46d3:
	/* 0x46d3: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_46d8:
	/* 0x46d8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_46dd:
	/* 0x46dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46df:
	/* 0x46df: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_46e4:
	/* 0x46e4: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_46ec:
	/* 0x46ec: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_46ef:
	/* 0x46ef: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_46f7:
	/* 0x46f7: mov    DWORD PTR [rsp+0x10],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68722503214ULL);
x86_l_46ff:
	/* 0x46ff: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_4702:
	/* 0x4702: cmp    eax,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27901ULL);
x86_l_4707:
	/* 0x4707: jb     470e <syscall__execve_exit+0x470e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_470e;
	}
x86_l_4709:
	/* 0x4709: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_470e:
	/* 0x470e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4713:
	/* 0x4713: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_471b:
	/* 0x471b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_471f:
	/* 0x471f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4726:
	/* 0x4726: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_472b:
	/* 0x472b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4730:
	/* 0x4730: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4732:
	/* 0x4732: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4736:
	/* 0x4736: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_4738:
	/* 0x4738: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_473a:
	/* 0x473a: jle    bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3029ULL;
	}
x86_l_4740:
	/* 0x4740: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4743:
	/* 0x4743: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4748:
	/* 0x4748: ja     bd5 <syscall__execve_exit+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3029ULL;
	}
x86_l_474e:
	/* 0x474e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4753:
	/* 0x4753: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_475b:
	/* 0x475b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_475f:
	/* 0x475f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4766:
	/* 0x4766: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_476b:
	/* 0x476b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4770:
	/* 0x4770: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4772:
	/* 0x4772: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4777:
	/* 0x4777: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_477f:
	/* 0x477f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4782:
	/* 0x4782: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_478a:
	/* 0x478a: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_478c:
	/* 0x478c: jmp    bd5 <syscall__execve_exit+0xbd5> */
	return 3029ULL;
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
	for (__u32 __x86_iter = 0; __x86_iter < 15216U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1722ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1725ULL && __x86_pc <= 3392ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3397ULL && __x86_pc <= 5139ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5146ULL && __x86_pc <= 7023ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7030ULL && __x86_pc <= 8949ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8951ULL && __x86_pc <= 10867ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10869ULL && __x86_pc <= 12760ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12765ULL && __x86_pc <= 14670ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14675ULL && __x86_pc <= 16589ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16594ULL && __x86_pc <= 18316ULL)
			__x86_pc = tracee_syscall__execve_exit_x86_chunk_9(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

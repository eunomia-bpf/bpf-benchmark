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
	/* 0x2b: je     20b <syscall__execveat_enter+0x20b> */
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
	/* 0x4a: je     20b <syscall__execveat_enter+0x20b> */
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
	/* 0x6b: je     20b <syscall__execveat_enter+0x20b> */
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
	/* 0x8c: je     20b <syscall__execveat_enter+0x20b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b;
	}
x86_l_92:
	/* 0x92: cmp    BYTE PTR [r13+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_9a:
	/* 0x9a: je     212 <syscall__execveat_enter+0x212> */
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
	/* 0xb5: mov    DWORD PTR [r14+0x70],0x142 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337474ULL);
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
	/* 0x137: mov    DWORD PTR [rsp+0x10],0x142 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719477058ULL);
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
	/* 0x15a: je     20b <syscall__execveat_enter+0x20b> */
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
	/* 0x172: je     20b <syscall__execveat_enter+0x20b> */
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
	/* 0x1f0: jne    21c <syscall__execveat_enter+0x21c> */
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
	/* 0x200: jne    9c7 <syscall__execveat_enter+0x9c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2503ULL;
	}
x86_l_206:
	/* 0x206: jmp    1104 <syscall__execveat_enter+0x1104> */
	return 4356ULL;
x86_l_20b:
	/* 0x20b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20d:
	/* 0x20d: jmp    1104 <syscall__execveat_enter+0x1104> */
	return 4356ULL;
x86_l_212:
	/* 0x212: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_217:
	/* 0x217: jmp    1104 <syscall__execveat_enter+0x1104> */
	return 4356ULL;
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
	/* 0x22e: je     3de <syscall__execveat_enter+0x3de> */
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
	/* 0x262: je     288 <syscall__execveat_enter+0x288> */
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
	/* 0x292: je     2ae <syscall__execveat_enter+0x2ae> */
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
	/* 0x2b8: je     2d9 <syscall__execveat_enter+0x2d9> */
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
	/* 0x2ed: je     444 <syscall__execveat_enter+0x444> */
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
	/* 0x353: je     375 <syscall__execveat_enter+0x375> */
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
	/* 0x367: je     375 <syscall__execveat_enter+0x375> */
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
	/* 0x373: jmp    377 <syscall__execveat_enter+0x377> */
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
	/* 0x38f: jb     3a7 <syscall__execveat_enter+0x3a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3a7;
	}
x86_l_391:
	/* 0x391: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_395:
	/* 0x395: je     39c <syscall__execveat_enter+0x39c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39c;
	}
x86_l_397:
	/* 0x397: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_39a:
	/* 0x39a: jbe    3a7 <syscall__execveat_enter+0x3a7> */
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
	/* 0x3b9: je     3fa <syscall__execveat_enter+0x3fa> */
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
	/* 0x3d0: je     406 <syscall__execveat_enter+0x406> */
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
	/* 0x3dc: jmp    408 <syscall__execveat_enter+0x408> */
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
	/* 0x3ef: jne    264 <syscall__execveat_enter+0x264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_264;
	}
x86_l_3f5:
	/* 0x3f5: jmp    288 <syscall__execveat_enter+0x288> */
	goto x86_l_288;
x86_l_3fa:
	/* 0x3fa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fc:
	/* 0x3fc: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_404:
	/* 0x404: jmp    418 <syscall__execveat_enter+0x418> */
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
	/* 0x423: jb     43b <syscall__execveat_enter+0x43b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_43b;
	}
x86_l_425:
	/* 0x425: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_429:
	/* 0x429: je     430 <syscall__execveat_enter+0x430> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430;
	}
x86_l_42b:
	/* 0x42b: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_42e:
	/* 0x42e: jbe    43b <syscall__execveat_enter+0x43b> */
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
	/* 0x44c: je     4ea <syscall__execveat_enter+0x4ea> */
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
	/* 0x4ae: je     4d0 <syscall__execveat_enter+0x4d0> */
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
	/* 0x4c2: je     4d0 <syscall__execveat_enter+0x4d0> */
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
	/* 0x4ce: jmp    4d2 <syscall__execveat_enter+0x4d2> */
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
	/* 0x4e0: jae    4f2 <syscall__execveat_enter+0x4f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4f2;
	}
x86_l_4e2:
	/* 0x4e2: movzx  r13d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_4e8:
	/* 0x4e8: jmp    50b <syscall__execveat_enter+0x50b> */
	goto x86_l_50b;
x86_l_4ea:
	/* 0x4ea: movzx  r13d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_4f0:
	/* 0x4f0: jmp    511 <syscall__execveat_enter+0x511> */
	goto x86_l_511;
x86_l_4f2:
	/* 0x4f2: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_4f6:
	/* 0x4f6: movzx  r13d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_4fc:
	/* 0x4fc: je     503 <syscall__execveat_enter+0x503> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_503;
	}
x86_l_4fe:
	/* 0x4fe: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_501:
	/* 0x501: jbe    50b <syscall__execveat_enter+0x50b> */
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
	/* 0x519: je     5d7 <syscall__execveat_enter+0x5d7> */
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
	/* 0x5a8: je     5c9 <syscall__execveat_enter+0x5c9> */
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
	/* 0x5bb: je     5c9 <syscall__execveat_enter+0x5c9> */
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
	/* 0x5c7: jmp    5cb <syscall__execveat_enter+0x5cb> */
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
	/* 0x5df: je     6c0 <syscall__execveat_enter+0x6c0> */
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
	/* 0x691: je     6b2 <syscall__execveat_enter+0x6b2> */
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
	/* 0x6a4: je     6b2 <syscall__execveat_enter+0x6b2> */
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
	/* 0x6b0: jmp    6b4 <syscall__execveat_enter+0x6b4> */
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

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_1(
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
	case 2514ULL: goto x86_l_9d2;
	case 2521ULL: goto x86_l_9d9;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2547ULL: goto x86_l_9f3;
	case 2554ULL: goto x86_l_9fa;
	case 2559ULL: goto x86_l_9ff;
	case 2564ULL: goto x86_l_a04;
	case 2566ULL: goto x86_l_a06;
	case 2570ULL: goto x86_l_a0a;
	case 2574ULL: goto x86_l_a0e;
	case 2581ULL: goto x86_l_a15;
	case 2586ULL: goto x86_l_a1a;
	case 2591ULL: goto x86_l_a1f;
	case 2593ULL: goto x86_l_a21;
	case 2596ULL: goto x86_l_a24;
	case 2598ULL: goto x86_l_a26;
	case 2602ULL: goto x86_l_a2a;
	case 2610ULL: goto x86_l_a32;
	case 2617ULL: goto x86_l_a39;
	case 2619ULL: goto x86_l_a3b;
	case 2623ULL: goto x86_l_a3f;
	case 2627ULL: goto x86_l_a43;
	case 2632ULL: goto x86_l_a48;
	case 2638ULL: goto x86_l_a4e;
	case 2642ULL: goto x86_l_a52;
	case 2651ULL: goto x86_l_a5b;
	case 2659ULL: goto x86_l_a63;
	case 2667ULL: goto x86_l_a6b;
	case 2673ULL: goto x86_l_a71;
	case 2675ULL: goto x86_l_a73;
	case 2680ULL: goto x86_l_a78;
	case 2688ULL: goto x86_l_a80;
	case 2692ULL: goto x86_l_a84;
	case 2699ULL: goto x86_l_a8b;
	case 2704ULL: goto x86_l_a90;
	case 2706ULL: goto x86_l_a92;
	case 2708ULL: goto x86_l_a94;
	case 2710ULL: goto x86_l_a96;
	case 2713ULL: goto x86_l_a99;
	case 2720ULL: goto x86_l_aa0;
	case 2722ULL: goto x86_l_aa2;
	case 2730ULL: goto x86_l_aaa;
	case 2738ULL: goto x86_l_ab2;
	case 2741ULL: goto x86_l_ab5;
	case 2749ULL: goto x86_l_abd;
	case 2756ULL: goto x86_l_ac4;
	case 2758ULL: goto x86_l_ac6;
	case 2760ULL: goto x86_l_ac8;
	case 2763ULL: goto x86_l_acb;
	case 2766ULL: goto x86_l_ace;
	case 2771ULL: goto x86_l_ad3;
	case 2777ULL: goto x86_l_ad9;
	case 2784ULL: goto x86_l_ae0;
	case 2793ULL: goto x86_l_ae9;
	case 2801ULL: goto x86_l_af1;
	case 2805ULL: goto x86_l_af5;
	case 2813ULL: goto x86_l_afd;
	case 2822ULL: goto x86_l_b06;
	case 2827ULL: goto x86_l_b0b;
	case 2832ULL: goto x86_l_b10;
	case 2837ULL: goto x86_l_b15;
	case 2840ULL: goto x86_l_b18;
	case 2842ULL: goto x86_l_b1a;
	case 2848ULL: goto x86_l_b20;
	case 2850ULL: goto x86_l_b22;
	case 2853ULL: goto x86_l_b25;
	case 2858ULL: goto x86_l_b2a;
	case 2860ULL: goto x86_l_b2c;
	case 2865ULL: goto x86_l_b31;
	case 2873ULL: goto x86_l_b39;
	case 2877ULL: goto x86_l_b3d;
	case 2884ULL: goto x86_l_b44;
	case 2889ULL: goto x86_l_b49;
	case 2894ULL: goto x86_l_b4e;
	case 2896ULL: goto x86_l_b50;
	case 2900ULL: goto x86_l_b54;
	case 2902ULL: goto x86_l_b56;
	case 2904ULL: goto x86_l_b58;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2918ULL: goto x86_l_b66;
	case 2920ULL: goto x86_l_b68;
	case 2925ULL: goto x86_l_b6d;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2939ULL: goto x86_l_b7b;
	case 2947ULL: goto x86_l_b83;
	case 2954ULL: goto x86_l_b8a;
	case 2960ULL: goto x86_l_b90;
	case 2966ULL: goto x86_l_b96;
	case 2969ULL: goto x86_l_b99;
	case 2975ULL: goto x86_l_b9f;
	case 2981ULL: goto x86_l_ba5;
	case 2988ULL: goto x86_l_bac;
	case 2997ULL: goto x86_l_bb5;
	case 3005ULL: goto x86_l_bbd;
	case 3009ULL: goto x86_l_bc1;
	case 3017ULL: goto x86_l_bc9;
	case 3026ULL: goto x86_l_bd2;
	case 3031ULL: goto x86_l_bd7;
	case 3036ULL: goto x86_l_bdc;
	case 3041ULL: goto x86_l_be1;
	case 3044ULL: goto x86_l_be4;
	case 3046ULL: goto x86_l_be6;
	case 3052ULL: goto x86_l_bec;
	case 3054ULL: goto x86_l_bee;
	case 3057ULL: goto x86_l_bf1;
	case 3062ULL: goto x86_l_bf6;
	case 3064ULL: goto x86_l_bf8;
	case 3069ULL: goto x86_l_bfd;
	case 3077ULL: goto x86_l_c05;
	case 3081ULL: goto x86_l_c09;
	case 3088ULL: goto x86_l_c10;
	case 3093ULL: goto x86_l_c15;
	case 3098ULL: goto x86_l_c1a;
	case 3100ULL: goto x86_l_c1c;
	case 3104ULL: goto x86_l_c20;
	case 3106ULL: goto x86_l_c22;
	case 3108ULL: goto x86_l_c24;
	case 3111ULL: goto x86_l_c27;
	case 3116ULL: goto x86_l_c2c;
	case 3122ULL: goto x86_l_c32;
	case 3124ULL: goto x86_l_c34;
	case 3131ULL: goto x86_l_c3b;
	case 3136ULL: goto x86_l_c40;
	case 3138ULL: goto x86_l_c42;
	case 3146ULL: goto x86_l_c4a;
	case 3153ULL: goto x86_l_c51;
	case 3156ULL: goto x86_l_c54;
	case 3163ULL: goto x86_l_c5b;
	case 3165ULL: goto x86_l_c5d;
	case 3174ULL: goto x86_l_c66;
	case 3180ULL: goto x86_l_c6c;
	case 3182ULL: goto x86_l_c6e;
	case 3185ULL: goto x86_l_c71;
	case 3192ULL: goto x86_l_c78;
	case 3196ULL: goto x86_l_c7c;
	case 3203ULL: goto x86_l_c83;
	case 3208ULL: goto x86_l_c88;
	case 3213ULL: goto x86_l_c8d;
	case 3215ULL: goto x86_l_c8f;
	case 3218ULL: goto x86_l_c92;
	case 3220ULL: goto x86_l_c94;
	case 3223ULL: goto x86_l_c97;
	case 3231ULL: goto x86_l_c9f;
	case 3238ULL: goto x86_l_ca6;
	case 3245ULL: goto x86_l_cad;
	case 3249ULL: goto x86_l_cb1;
	case 3254ULL: goto x86_l_cb6;
	case 3259ULL: goto x86_l_cbb;
	case 3264ULL: goto x86_l_cc0;
	case 3267ULL: goto x86_l_cc3;
	case 3269ULL: goto x86_l_cc5;
	case 3274ULL: goto x86_l_cca;
	case 3282ULL: goto x86_l_cd2;
	case 3286ULL: goto x86_l_cd6;
	case 3291ULL: goto x86_l_cdb;
	case 3296ULL: goto x86_l_ce0;
	case 3301ULL: goto x86_l_ce5;
	case 3303ULL: goto x86_l_ce7;
	case 3308ULL: goto x86_l_cec;
	case 3312ULL: goto x86_l_cf0;
	case 3317ULL: goto x86_l_cf5;
	case 3322ULL: goto x86_l_cfa;
	case 3327ULL: goto x86_l_cff;
	case 3329ULL: goto x86_l_d01;
	case 3334ULL: goto x86_l_d06;
	case 3338ULL: goto x86_l_d0a;
	case 3343ULL: goto x86_l_d0f;
	case 3348ULL: goto x86_l_d14;
	case 3353ULL: goto x86_l_d19;
	case 3355ULL: goto x86_l_d1b;
	case 3359ULL: goto x86_l_d1f;
	case 3363ULL: goto x86_l_d23;
	case 3367ULL: goto x86_l_d27;
	case 3372ULL: goto x86_l_d2c;
	case 3377ULL: goto x86_l_d31;
	case 3382ULL: goto x86_l_d36;
	case 3385ULL: goto x86_l_d39;
	case 3387ULL: goto x86_l_d3b;
	case 3392ULL: goto x86_l_d40;
	case 3397ULL: goto x86_l_d45;
	case 3402ULL: goto x86_l_d4a;
	case 3407ULL: goto x86_l_d4f;
	case 3410ULL: goto x86_l_d52;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6bd:
	/* 0x6bd: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_6c0:
	/* 0x6c0: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_6c8:
	/* 0x6c8: je     798 <syscall__execveat_enter+0x798> */
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
	/* 0x764: je     784 <syscall__execveat_enter+0x784> */
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
	/* 0x776: je     784 <syscall__execveat_enter+0x784> */
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
	/* 0x782: jmp    786 <syscall__execveat_enter+0x786> */
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
	/* 0x7a0: je     81d <syscall__execveat_enter+0x81d> */
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
	/* 0x7e9: je     809 <syscall__execveat_enter+0x809> */
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
	/* 0x7fb: je     809 <syscall__execveat_enter+0x809> */
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
	/* 0x807: jmp    80b <syscall__execveat_enter+0x80b> */
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
	/* 0x827: je     88e <syscall__execveat_enter+0x88e> */
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
	/* 0x85e: je     880 <syscall__execveat_enter+0x880> */
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
	/* 0x872: je     880 <syscall__execveat_enter+0x880> */
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
	/* 0x87e: jmp    882 <syscall__execveat_enter+0x882> */
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
	/* 0x898: je     8fa <syscall__execveat_enter+0x8fa> */
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
	/* 0x8c7: je     8ec <syscall__execveat_enter+0x8ec> */
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
	/* 0x8de: je     8ec <syscall__execveat_enter+0x8ec> */
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
	/* 0x8ea: jmp    8ee <syscall__execveat_enter+0x8ee> */
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
	/* 0x904: je     98c <syscall__execveat_enter+0x98c> */
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
	/* 0x937: je     97e <syscall__execveat_enter+0x97e> */
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
	/* 0x955: jne    972 <syscall__execveat_enter+0x972> */
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
	/* 0x970: je     97e <syscall__execveat_enter+0x97e> */
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
	/* 0x97c: jmp    980 <syscall__execveat_enter+0x980> */
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
	/* 0x996: je     9a7 <syscall__execveat_enter+0x9a7> */
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
	/* 0x9c1: je     1104 <syscall__execveat_enter+0x1104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4356ULL;
	}
x86_l_9c7:
	/* 0x9c7: lea    rbx,[r14+0x7d8a] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_9ce:
	/* 0x9ce: movzx  r15d,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_9d2:
	/* 0x9d2: cmp    r15,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 32000ULL);
x86_l_9d9:
	/* 0x9d9: jb     9ea <syscall__execveat_enter+0x9ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9ea;
	}
x86_l_9db:
	/* 0x9db: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9e0:
	/* 0x9e0: mov    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9e5:
	/* 0x9e5: jmp    b8a <syscall__execveat_enter+0xb8a> */
	goto x86_l_b8a;
x86_l_9ea:
	/* 0x9ea: mov    BYTE PTR [r14+r15*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 588410519552ULL);
x86_l_9f3:
	/* 0x9f3: cmp    r15d,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31995ULL);
x86_l_9fa:
	/* 0x9fa: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9ff:
	/* 0x9ff: mov    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a04:
	/* 0xa04: ja     a3b <syscall__execveat_enter+0xa3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a3b;
	}
x86_l_a06:
	/* 0xa06: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a0a:
	/* 0xa0a: lea    rdi,[r15+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_a0e:
	/* 0xa0e: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_a15:
	/* 0xa15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a1a:
	/* 0xa1a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a1f:
	/* 0xa1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a21:
	/* 0xa21: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a24:
	/* 0xa24: js     a3b <syscall__execveat_enter+0xa3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a3b;
	}
x86_l_a26:
	/* 0xa26: add    r15d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_a2a:
	/* 0xa2a: mov    WORD PTR [r14+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_a32:
	/* 0xa32: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_a39:
	/* 0xa39: jmp    a3f <syscall__execveat_enter+0xa3f> */
	goto x86_l_a3f;
x86_l_a3b:
	/* 0xa3b: movzx  r15d,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a3f:
	/* 0xa3f: movzx  eax,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_a43:
	/* 0xa43: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_a48:
	/* 0xa48: jae    b8a <syscall__execveat_enter+0xb8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b8a;
	}
x86_l_a4e:
	/* 0xa4e: mov    rdx,QWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a52:
	/* 0xa52: mov    BYTE PTR [r14+rax*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519553ULL);
x86_l_a5b:
	/* 0xa5b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_a63:
	/* 0xa63: mov    WORD PTR [r14+0x7d8e],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32142ULL);
x86_l_a6b:
	/* 0xa6b: cmp    ecx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27899ULL);
x86_l_a71:
	/* 0xa71: ja     acb <syscall__execveat_enter+0xacb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_acb;
	}
x86_l_a73:
	/* 0xa73: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_a78:
	/* 0xa78: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_a80:
	/* 0xa80: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_a84:
	/* 0xa84: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_a8b:
	/* 0xa8b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_a90:
	/* 0xa90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a92:
	/* 0xa92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a94:
	/* 0xa94: jle    ac8 <syscall__execveat_enter+0xac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_ac8;
	}
x86_l_a96:
	/* 0xa96: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a99:
	/* 0xa99: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_aa0:
	/* 0xaa0: ja     acb <syscall__execveat_enter+0xacb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_acb;
	}
x86_l_aa2:
	/* 0xaa2: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_aaa:
	/* 0xaaa: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_ab2:
	/* 0xab2: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_ab5:
	/* 0xab5: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_abd:
	/* 0xabd: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_ac4:
	/* 0xac4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ac6:
	/* 0xac6: jmp    acb <syscall__execveat_enter+0xacb> */
	goto x86_l_acb;
x86_l_ac8:
	/* 0xac8: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_acb:
	/* 0xacb: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ace:
	/* 0xace: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_ad3:
	/* 0xad3: ja     b8a <syscall__execveat_enter+0xb8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b8a;
	}
x86_l_ad9:
	/* 0xad9: mov    r13,QWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ae0:
	/* 0xae0: mov    BYTE PTR [r14+rax*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519554ULL);
x86_l_ae9:
	/* 0xae9: movzx  r15d,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_af1:
	/* 0xaf1: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_af5:
	/* 0xaf5: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_afd:
	/* 0xafd: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_b06:
	/* 0xb06: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b0b:
	/* 0xb0b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b10:
	/* 0xb10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b15:
	/* 0xb15: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b18:
	/* 0xb18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b1a:
	/* 0xb1a: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_b20:
	/* 0xb20: je     b66 <syscall__execveat_enter+0xb66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b66;
	}
x86_l_b22:
	/* 0xb22: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b25:
	/* 0xb25: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_b2a:
	/* 0xb2a: ja     b66 <syscall__execveat_enter+0xb66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b66;
	}
x86_l_b2c:
	/* 0xb2c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_b31:
	/* 0xb31: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_b39:
	/* 0xb39: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_b3d:
	/* 0xb3d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_b44:
	/* 0xb44: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b49:
	/* 0xb49: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_b4e:
	/* 0xb4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b50:
	/* 0xb50: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b54:
	/* 0xb54: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b56:
	/* 0xb56: jle    b66 <syscall__execveat_enter+0xb66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_b66;
	}
x86_l_b58:
	/* 0xb58: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b5b:
	/* 0xb5b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_b60:
	/* 0xb60: jbe    2c7c <syscall__execveat_enter+0x2c7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11388ULL;
	}
x86_l_b66:
	/* 0xb66: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b68:
	/* 0xb68: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b6d:
	/* 0xb6d: cmp    r15d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31998ULL);
x86_l_b74:
	/* 0xb74: mov    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b79:
	/* 0xb79: ja     b8a <syscall__execveat_enter+0xb8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b8a;
	}
x86_l_b7b:
	/* 0xb7b: mov    BYTE PTR [r14+r15*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_b83:
	/* 0xb83: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_b8a:
	/* 0xb8a: test   BYTE PTR [r12+0x4],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869185ULL);
x86_l_b90:
	/* 0xb90: je     c51 <syscall__execveat_enter+0xc51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c51;
	}
x86_l_b96:
	/* 0xb96: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b99:
	/* 0xb99: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_b9f:
	/* 0xb9f: ja     c51 <syscall__execveat_enter+0xc51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c51;
	}
x86_l_ba5:
	/* 0xba5: mov    r13,QWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_bac:
	/* 0xbac: mov    BYTE PTR [r14+rax*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519555ULL);
x86_l_bb5:
	/* 0xbb5: movzx  r15d,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_bbd:
	/* 0xbbd: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_bc1:
	/* 0xbc1: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_bc9:
	/* 0xbc9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_bd2:
	/* 0xbd2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bd7:
	/* 0xbd7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bdc:
	/* 0xbdc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_be1:
	/* 0xbe1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_be4:
	/* 0xbe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be6:
	/* 0xbe6: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_bec:
	/* 0xbec: je     c32 <syscall__execveat_enter+0xc32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c32;
	}
x86_l_bee:
	/* 0xbee: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_bf1:
	/* 0xbf1: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_bf6:
	/* 0xbf6: ja     c32 <syscall__execveat_enter+0xc32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c32;
	}
x86_l_bf8:
	/* 0xbf8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_bfd:
	/* 0xbfd: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_c05:
	/* 0xc05: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_c09:
	/* 0xc09: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_c10:
	/* 0xc10: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c15:
	/* 0xc15: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_c1a:
	/* 0xc1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1c:
	/* 0xc1c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_c20:
	/* 0xc20: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c22:
	/* 0xc22: jle    c32 <syscall__execveat_enter+0xc32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c32;
	}
x86_l_c24:
	/* 0xc24: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c27:
	/* 0xc27: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_c2c:
	/* 0xc2c: jbe    1113 <syscall__execveat_enter+0x1113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4371ULL;
	}
x86_l_c32:
	/* 0xc32: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c34:
	/* 0xc34: cmp    r15d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31998ULL);
x86_l_c3b:
	/* 0xc3b: mov    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c40:
	/* 0xc40: ja     c51 <syscall__execveat_enter+0xc51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c51;
	}
x86_l_c42:
	/* 0xc42: mov    BYTE PTR [r14+r15*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_c4a:
	/* 0xc4a: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_c51:
	/* 0xc51: movzx  ebx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c54:
	/* 0xc54: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_c5b:
	/* 0xc5b: ja     ca6 <syscall__execveat_enter+0xca6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ca6;
	}
x86_l_c5d:
	/* 0xc5d: mov    BYTE PTR [r14+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_c66:
	/* 0xc66: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_c6c:
	/* 0xc6c: ja     ca6 <syscall__execveat_enter+0xca6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ca6;
	}
x86_l_c6e:
	/* 0xc6e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c71:
	/* 0xc71: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_c78:
	/* 0xc78: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_c7c:
	/* 0xc7c: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_c83:
	/* 0xc83: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c88:
	/* 0xc88: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c8d:
	/* 0xc8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c8f:
	/* 0xc8f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c92:
	/* 0xc92: js     ca6 <syscall__execveat_enter+0xca6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_ca6;
	}
x86_l_c94:
	/* 0xc94: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_c97:
	/* 0xc97: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_c9f:
	/* 0xc9f: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_ca6:
	/* 0xca6: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_cad:
	/* 0xcad: lea    r12,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cb1:
	/* 0xcb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cb6:
	/* 0xcb6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cbb:
	/* 0xcbb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cc0:
	/* 0xcc0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_cc3:
	/* 0xcc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc5:
	/* 0xcc5: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cca:
	/* 0xcca: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_cd2:
	/* 0xcd2: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cd6:
	/* 0xcd6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cdb:
	/* 0xcdb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ce0:
	/* 0xce0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ce5:
	/* 0xce5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce7:
	/* 0xce7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cec:
	/* 0xcec: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_cf0:
	/* 0xcf0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cf5:
	/* 0xcf5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cfa:
	/* 0xcfa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cff:
	/* 0xcff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d01:
	/* 0xd01: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d06:
	/* 0xd06: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_d0a:
	/* 0xd0a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d0f:
	/* 0xd0f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d14:
	/* 0xd14: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d19:
	/* 0xd19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1b:
	/* 0xd1b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d1f:
	/* 0xd1f: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_d23:
	/* 0xd23: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d27:
	/* 0xd27: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d2c:
	/* 0xd2c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d31:
	/* 0xd31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d36:
	/* 0xd36: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_d39:
	/* 0xd39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d3b:
	/* 0xd3b: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d40:
	/* 0xd40: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d45:
	/* 0xd45: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d4a:
	/* 0xd4a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d4f:
	/* 0xd4f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d52:
	/* 0xd52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 3412ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3412ULL: goto x86_l_d54;
	case 3416ULL: goto x86_l_d58;
	case 3420ULL: goto x86_l_d5c;
	case 3424ULL: goto x86_l_d60;
	case 3428ULL: goto x86_l_d64;
	case 3433ULL: goto x86_l_d69;
	case 3438ULL: goto x86_l_d6e;
	case 3443ULL: goto x86_l_d73;
	case 3445ULL: goto x86_l_d75;
	case 3449ULL: goto x86_l_d79;
	case 3453ULL: goto x86_l_d7d;
	case 3458ULL: goto x86_l_d82;
	case 3463ULL: goto x86_l_d87;
	case 3468ULL: goto x86_l_d8c;
	case 3471ULL: goto x86_l_d8f;
	case 3473ULL: goto x86_l_d91;
	case 3478ULL: goto x86_l_d96;
	case 3482ULL: goto x86_l_d9a;
	case 3487ULL: goto x86_l_d9f;
	case 3492ULL: goto x86_l_da4;
	case 3497ULL: goto x86_l_da9;
	case 3499ULL: goto x86_l_dab;
	case 3504ULL: goto x86_l_db0;
	case 3509ULL: goto x86_l_db5;
	case 3514ULL: goto x86_l_dba;
	case 3519ULL: goto x86_l_dbf;
	case 3522ULL: goto x86_l_dc2;
	case 3524ULL: goto x86_l_dc4;
	case 3528ULL: goto x86_l_dc8;
	case 3532ULL: goto x86_l_dcc;
	case 3536ULL: goto x86_l_dd0;
	case 3540ULL: goto x86_l_dd4;
	case 3545ULL: goto x86_l_dd9;
	case 3550ULL: goto x86_l_dde;
	case 3555ULL: goto x86_l_de3;
	case 3557ULL: goto x86_l_de5;
	case 3561ULL: goto x86_l_de9;
	case 3565ULL: goto x86_l_ded;
	case 3570ULL: goto x86_l_df2;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3583ULL: goto x86_l_dff;
	case 3585ULL: goto x86_l_e01;
	case 3590ULL: goto x86_l_e06;
	case 3595ULL: goto x86_l_e0b;
	case 3600ULL: goto x86_l_e10;
	case 3605ULL: goto x86_l_e15;
	case 3608ULL: goto x86_l_e18;
	case 3610ULL: goto x86_l_e1a;
	case 3614ULL: goto x86_l_e1e;
	case 3618ULL: goto x86_l_e22;
	case 3622ULL: goto x86_l_e26;
	case 3626ULL: goto x86_l_e2a;
	case 3631ULL: goto x86_l_e2f;
	case 3636ULL: goto x86_l_e34;
	case 3641ULL: goto x86_l_e39;
	case 3643ULL: goto x86_l_e3b;
	case 3648ULL: goto x86_l_e40;
	case 3652ULL: goto x86_l_e44;
	case 3657ULL: goto x86_l_e49;
	case 3662ULL: goto x86_l_e4e;
	case 3667ULL: goto x86_l_e53;
	case 3669ULL: goto x86_l_e55;
	case 3674ULL: goto x86_l_e5a;
	case 3678ULL: goto x86_l_e5e;
	case 3683ULL: goto x86_l_e63;
	case 3688ULL: goto x86_l_e68;
	case 3693ULL: goto x86_l_e6d;
	case 3696ULL: goto x86_l_e70;
	case 3698ULL: goto x86_l_e72;
	case 3703ULL: goto x86_l_e77;
	case 3708ULL: goto x86_l_e7c;
	case 3713ULL: goto x86_l_e81;
	case 3718ULL: goto x86_l_e86;
	case 3721ULL: goto x86_l_e89;
	case 3723ULL: goto x86_l_e8b;
	case 3727ULL: goto x86_l_e8f;
	case 3731ULL: goto x86_l_e93;
	case 3735ULL: goto x86_l_e97;
	case 3739ULL: goto x86_l_e9b;
	case 3744ULL: goto x86_l_ea0;
	case 3749ULL: goto x86_l_ea5;
	case 3754ULL: goto x86_l_eaa;
	case 3756ULL: goto x86_l_eac;
	case 3761ULL: goto x86_l_eb1;
	case 3765ULL: goto x86_l_eb5;
	case 3770ULL: goto x86_l_eba;
	case 3775ULL: goto x86_l_ebf;
	case 3780ULL: goto x86_l_ec4;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3789ULL: goto x86_l_ecd;
	case 3794ULL: goto x86_l_ed2;
	case 3799ULL: goto x86_l_ed7;
	case 3804ULL: goto x86_l_edc;
	case 3807ULL: goto x86_l_edf;
	case 3809ULL: goto x86_l_ee1;
	case 3814ULL: goto x86_l_ee6;
	case 3819ULL: goto x86_l_eeb;
	case 3824ULL: goto x86_l_ef0;
	case 3829ULL: goto x86_l_ef5;
	case 3832ULL: goto x86_l_ef8;
	case 3834ULL: goto x86_l_efa;
	case 3838ULL: goto x86_l_efe;
	case 3842ULL: goto x86_l_f02;
	case 3846ULL: goto x86_l_f06;
	case 3850ULL: goto x86_l_f0a;
	case 3855ULL: goto x86_l_f0f;
	case 3860ULL: goto x86_l_f14;
	case 3865ULL: goto x86_l_f19;
	case 3867ULL: goto x86_l_f1b;
	case 3871ULL: goto x86_l_f1f;
	case 3875ULL: goto x86_l_f23;
	case 3879ULL: goto x86_l_f27;
	case 3883ULL: goto x86_l_f2b;
	case 3890ULL: goto x86_l_f32;
	case 3895ULL: goto x86_l_f37;
	case 3900ULL: goto x86_l_f3c;
	case 3905ULL: goto x86_l_f41;
	case 3908ULL: goto x86_l_f44;
	case 3910ULL: goto x86_l_f46;
	case 3915ULL: goto x86_l_f4b;
	case 3919ULL: goto x86_l_f4f;
	case 3924ULL: goto x86_l_f54;
	case 3929ULL: goto x86_l_f59;
	case 3934ULL: goto x86_l_f5e;
	case 3936ULL: goto x86_l_f60;
	case 3941ULL: goto x86_l_f65;
	case 3946ULL: goto x86_l_f6a;
	case 3951ULL: goto x86_l_f6f;
	case 3956ULL: goto x86_l_f74;
	case 3958ULL: goto x86_l_f76;
	case 3962ULL: goto x86_l_f7a;
	case 3966ULL: goto x86_l_f7e;
	case 3971ULL: goto x86_l_f83;
	case 3973ULL: goto x86_l_f85;
	case 3977ULL: goto x86_l_f89;
	case 3981ULL: goto x86_l_f8d;
	case 3986ULL: goto x86_l_f92;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 3998ULL: goto x86_l_f9e;
	case 4003ULL: goto x86_l_fa3;
	case 4007ULL: goto x86_l_fa7;
	case 4015ULL: goto x86_l_faf;
	case 4019ULL: goto x86_l_fb3;
	case 4024ULL: goto x86_l_fb8;
	case 4029ULL: goto x86_l_fbd;
	case 4034ULL: goto x86_l_fc2;
	case 4036ULL: goto x86_l_fc4;
	case 4041ULL: goto x86_l_fc9;
	case 4045ULL: goto x86_l_fcd;
	case 4049ULL: goto x86_l_fd1;
	case 4054ULL: goto x86_l_fd6;
	case 4059ULL: goto x86_l_fdb;
	case 4064ULL: goto x86_l_fe0;
	case 4067ULL: goto x86_l_fe3;
	case 4069ULL: goto x86_l_fe5;
	case 4074ULL: goto x86_l_fea;
	case 4078ULL: goto x86_l_fee;
	case 4083ULL: goto x86_l_ff3;
	case 4088ULL: goto x86_l_ff8;
	case 4093ULL: goto x86_l_ffd;
	case 4096ULL: goto x86_l_1000;
	case 4098ULL: goto x86_l_1002;
	case 4103ULL: goto x86_l_1007;
	case 4105ULL: goto x86_l_1009;
	case 4110ULL: goto x86_l_100e;
	case 4114ULL: goto x86_l_1012;
	case 4122ULL: goto x86_l_101a;
	case 4130ULL: goto x86_l_1022;
	case 4135ULL: goto x86_l_1027;
	case 4140ULL: goto x86_l_102c;
	case 4142ULL: goto x86_l_102e;
	case 4147ULL: goto x86_l_1033;
	case 4152ULL: goto x86_l_1038;
	case 4157ULL: goto x86_l_103d;
	case 4160ULL: goto x86_l_1040;
	case 4162ULL: goto x86_l_1042;
	case 4167ULL: goto x86_l_1047;
	case 4172ULL: goto x86_l_104c;
	case 4177ULL: goto x86_l_1051;
	case 4182ULL: goto x86_l_1056;
	case 4184ULL: goto x86_l_1058;
	case 4189ULL: goto x86_l_105d;
	case 4194ULL: goto x86_l_1062;
	case 4199ULL: goto x86_l_1067;
	case 4202ULL: goto x86_l_106a;
	case 4207ULL: goto x86_l_106f;
	case 4209ULL: goto x86_l_1071;
	case 4212ULL: goto x86_l_1074;
	case 4216ULL: goto x86_l_1078;
	case 4221ULL: goto x86_l_107d;
	case 4226ULL: goto x86_l_1082;
	case 4229ULL: goto x86_l_1085;
	case 4231ULL: goto x86_l_1087;
	case 4236ULL: goto x86_l_108c;
	case 4241ULL: goto x86_l_1091;
	case 4246ULL: goto x86_l_1096;
	case 4249ULL: goto x86_l_1099;
	case 4251ULL: goto x86_l_109b;
	case 4256ULL: goto x86_l_10a0;
	case 4260ULL: goto x86_l_10a4;
	case 4268ULL: goto x86_l_10ac;
	case 4270ULL: goto x86_l_10ae;
	case 4275ULL: goto x86_l_10b3;
	case 4282ULL: goto x86_l_10ba;
	case 4287ULL: goto x86_l_10bf;
	case 4290ULL: goto x86_l_10c2;
	case 4292ULL: goto x86_l_10c4;
	case 4294ULL: goto x86_l_10c6;
	case 4296ULL: goto x86_l_10c8;
	case 4300ULL: goto x86_l_10cc;
	case 4308ULL: goto x86_l_10d4;
	case 4313ULL: goto x86_l_10d9;
	case 4318ULL: goto x86_l_10de;
	case 4321ULL: goto x86_l_10e1;
	case 4327ULL: goto x86_l_10e7;
	case 4331ULL: goto x86_l_10eb;
	case 4336ULL: goto x86_l_10f0;
	case 4343ULL: goto x86_l_10f7;
	case 4348ULL: goto x86_l_10fc;
	case 4351ULL: goto x86_l_10ff;
	case 4354ULL: goto x86_l_1102;
	case 4356ULL: goto x86_l_1104;
	case 4363ULL: goto x86_l_110b;
	case 4365ULL: goto x86_l_110d;
	case 4366ULL: goto x86_l_110e;
	case 4371ULL: goto x86_l_1113;
	case 4376ULL: goto x86_l_1118;
	case 4384ULL: goto x86_l_1120;
	case 4388ULL: goto x86_l_1124;
	case 4395ULL: goto x86_l_112b;
	case 4400ULL: goto x86_l_1130;
	case 4405ULL: goto x86_l_1135;
	case 4407ULL: goto x86_l_1137;
	case 4412ULL: goto x86_l_113c;
	case 4420ULL: goto x86_l_1144;
	case 4423ULL: goto x86_l_1147;
	case 4431ULL: goto x86_l_114f;
	case 4440ULL: goto x86_l_1158;
	case 4444ULL: goto x86_l_115c;
	case 4449ULL: goto x86_l_1161;
	case 4454ULL: goto x86_l_1166;
	case 4459ULL: goto x86_l_116b;
	case 4461ULL: goto x86_l_116d;
	case 4463ULL: goto x86_l_116f;
	case 4469ULL: goto x86_l_1175;
	case 4475ULL: goto x86_l_117b;
	case 4478ULL: goto x86_l_117e;
	case 4483ULL: goto x86_l_1183;
	case 4489ULL: goto x86_l_1189;
	case 4494ULL: goto x86_l_118e;
	case 4502ULL: goto x86_l_1196;
	case 4506ULL: goto x86_l_119a;
	case 4513ULL: goto x86_l_11a1;
	case 4518ULL: goto x86_l_11a6;
	case 4523ULL: goto x86_l_11ab;
	case 4525ULL: goto x86_l_11ad;
	case 4529ULL: goto x86_l_11b1;
	case 4531ULL: goto x86_l_11b3;
	case 4533ULL: goto x86_l_11b5;
	case 4539ULL: goto x86_l_11bb;
	case 4542ULL: goto x86_l_11be;
	case 4547ULL: goto x86_l_11c3;
	case 4553ULL: goto x86_l_11c9;
	case 4558ULL: goto x86_l_11ce;
	case 4566ULL: goto x86_l_11d6;
	case 4570ULL: goto x86_l_11da;
	case 4577ULL: goto x86_l_11e1;
	case 4582ULL: goto x86_l_11e6;
	case 4587ULL: goto x86_l_11eb;
	case 4589ULL: goto x86_l_11ed;
	case 4594ULL: goto x86_l_11f2;
	case 4602ULL: goto x86_l_11fa;
	case 4605ULL: goto x86_l_11fd;
	case 4613ULL: goto x86_l_1205;
	case 4622ULL: goto x86_l_120e;
	case 4626ULL: goto x86_l_1212;
	case 4631ULL: goto x86_l_1217;
	case 4636ULL: goto x86_l_121c;
	case 4641ULL: goto x86_l_1221;
	case 4643ULL: goto x86_l_1223;
	case 4645ULL: goto x86_l_1225;
	case 4651ULL: goto x86_l_122b;
	case 4657ULL: goto x86_l_1231;
	case 4660ULL: goto x86_l_1234;
	case 4665ULL: goto x86_l_1239;
	case 4671ULL: goto x86_l_123f;
	case 4676ULL: goto x86_l_1244;
	case 4684ULL: goto x86_l_124c;
	case 4688ULL: goto x86_l_1250;
	case 4695ULL: goto x86_l_1257;
	case 4700ULL: goto x86_l_125c;
	case 4705ULL: goto x86_l_1261;
	case 4707ULL: goto x86_l_1263;
	case 4711ULL: goto x86_l_1267;
	case 4713ULL: goto x86_l_1269;
	case 4715ULL: goto x86_l_126b;
	case 4721ULL: goto x86_l_1271;
	case 4724ULL: goto x86_l_1274;
	case 4729ULL: goto x86_l_1279;
	case 4735ULL: goto x86_l_127f;
	case 4740ULL: goto x86_l_1284;
	case 4748ULL: goto x86_l_128c;
	case 4752ULL: goto x86_l_1290;
	case 4759ULL: goto x86_l_1297;
	case 4764ULL: goto x86_l_129c;
	case 4769ULL: goto x86_l_12a1;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4784ULL: goto x86_l_12b0;
	case 4787ULL: goto x86_l_12b3;
	case 4795ULL: goto x86_l_12bb;
	case 4804ULL: goto x86_l_12c4;
	case 4808ULL: goto x86_l_12c8;
	case 4813ULL: goto x86_l_12cd;
	case 4818ULL: goto x86_l_12d2;
	case 4823ULL: goto x86_l_12d7;
	case 4825ULL: goto x86_l_12d9;
	case 4827ULL: goto x86_l_12db;
	case 4833ULL: goto x86_l_12e1;
	case 4839ULL: goto x86_l_12e7;
	case 4842ULL: goto x86_l_12ea;
	case 4847ULL: goto x86_l_12ef;
	case 4853ULL: goto x86_l_12f5;
	case 4858ULL: goto x86_l_12fa;
	case 4866ULL: goto x86_l_1302;
	case 4870ULL: goto x86_l_1306;
	case 4877ULL: goto x86_l_130d;
	case 4882ULL: goto x86_l_1312;
	case 4887ULL: goto x86_l_1317;
	case 4889ULL: goto x86_l_1319;
	case 4893ULL: goto x86_l_131d;
	case 4895ULL: goto x86_l_131f;
	case 4897ULL: goto x86_l_1321;
	case 4903ULL: goto x86_l_1327;
	case 4906ULL: goto x86_l_132a;
	case 4911ULL: goto x86_l_132f;
	case 4917ULL: goto x86_l_1335;
	case 4922ULL: goto x86_l_133a;
	case 4930ULL: goto x86_l_1342;
	case 4934ULL: goto x86_l_1346;
	case 4941ULL: goto x86_l_134d;
	case 4946ULL: goto x86_l_1352;
	case 4951ULL: goto x86_l_1357;
	case 4953ULL: goto x86_l_1359;
	case 4958ULL: goto x86_l_135e;
	case 4966ULL: goto x86_l_1366;
	case 4969ULL: goto x86_l_1369;
	case 4977ULL: goto x86_l_1371;
	case 4986ULL: goto x86_l_137a;
	case 4990ULL: goto x86_l_137e;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5005ULL: goto x86_l_138d;
	case 5007ULL: goto x86_l_138f;
	case 5009ULL: goto x86_l_1391;
	case 5015ULL: goto x86_l_1397;
	case 5021ULL: goto x86_l_139d;
	case 5024ULL: goto x86_l_13a0;
	case 5029ULL: goto x86_l_13a5;
	case 5035ULL: goto x86_l_13ab;
	case 5040ULL: goto x86_l_13b0;
	case 5048ULL: goto x86_l_13b8;
	case 5052ULL: goto x86_l_13bc;
	case 5059ULL: goto x86_l_13c3;
	case 5064ULL: goto x86_l_13c8;
	case 5069ULL: goto x86_l_13cd;
	case 5071ULL: goto x86_l_13cf;
	case 5075ULL: goto x86_l_13d3;
	case 5077ULL: goto x86_l_13d5;
	case 5079ULL: goto x86_l_13d7;
	case 5085ULL: goto x86_l_13dd;
	case 5088ULL: goto x86_l_13e0;
	case 5093ULL: goto x86_l_13e5;
	case 5099ULL: goto x86_l_13eb;
	case 5104ULL: goto x86_l_13f0;
	case 5112ULL: goto x86_l_13f8;
	case 5116ULL: goto x86_l_13fc;
	case 5123ULL: goto x86_l_1403;
	case 5128ULL: goto x86_l_1408;
	case 5133ULL: goto x86_l_140d;
	case 5135ULL: goto x86_l_140f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d54:
	/* 0xd54: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d58:
	/* 0xd58: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_d5c:
	/* 0xd5c: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_d60:
	/* 0xd60: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d64:
	/* 0xd64: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d69:
	/* 0xd69: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d6e:
	/* 0xd6e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d73:
	/* 0xd73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d75:
	/* 0xd75: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d79:
	/* 0xd79: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_d7d:
	/* 0xd7d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d82:
	/* 0xd82: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d87:
	/* 0xd87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d8c:
	/* 0xd8c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d8f:
	/* 0xd8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d91:
	/* 0xd91: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d96:
	/* 0xd96: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d9a:
	/* 0xd9a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d9f:
	/* 0xd9f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_da4:
	/* 0xda4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_da9:
	/* 0xda9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dab:
	/* 0xdab: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db0:
	/* 0xdb0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_db5:
	/* 0xdb5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dba:
	/* 0xdba: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_dbf:
	/* 0xdbf: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_dc2:
	/* 0xdc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc4:
	/* 0xdc4: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc8:
	/* 0xdc8: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_dcc:
	/* 0xdcc: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_dd0:
	/* 0xdd0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_dd4:
	/* 0xdd4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dd9:
	/* 0xdd9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dde:
	/* 0xdde: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_de3:
	/* 0xde3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de5:
	/* 0xde5: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de9:
	/* 0xde9: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ded:
	/* 0xded: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_df2:
	/* 0xdf2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_df7:
	/* 0xdf7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dfc:
	/* 0xdfc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_dff:
	/* 0xdff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e01:
	/* 0xe01: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e06:
	/* 0xe06: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e0b:
	/* 0xe0b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e10:
	/* 0xe10: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e15:
	/* 0xe15: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e18:
	/* 0xe18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e1a:
	/* 0xe1a: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e1e:
	/* 0xe1e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_e22:
	/* 0xe22: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_e26:
	/* 0xe26: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e2a:
	/* 0xe2a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e2f:
	/* 0xe2f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e34:
	/* 0xe34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e39:
	/* 0xe39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e3b:
	/* 0xe3b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e40:
	/* 0xe40: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_e44:
	/* 0xe44: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e49:
	/* 0xe49: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e4e:
	/* 0xe4e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e53:
	/* 0xe53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e55:
	/* 0xe55: mov    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e5a:
	/* 0xe5a: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e5e:
	/* 0xe5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e63:
	/* 0xe63: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e68:
	/* 0xe68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e6d:
	/* 0xe6d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e70:
	/* 0xe70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e72:
	/* 0xe72: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e77:
	/* 0xe77: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e7c:
	/* 0xe7c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e81:
	/* 0xe81: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e86:
	/* 0xe86: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e89:
	/* 0xe89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8b:
	/* 0xe8b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e8f:
	/* 0xe8f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_e93:
	/* 0xe93: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_e97:
	/* 0xe97: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e9b:
	/* 0xe9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ea0:
	/* 0xea0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ea5:
	/* 0xea5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_eaa:
	/* 0xeaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eac:
	/* 0xeac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb1:
	/* 0xeb1: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_eb5:
	/* 0xeb5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eba:
	/* 0xeba: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ebf:
	/* 0xebf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ec4:
	/* 0xec4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec6:
	/* 0xec6: cmp    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_ecb:
	/* 0xecb: jne    f23 <syscall__execveat_enter+0xf23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f23;
	}
x86_l_ecd:
	/* 0xecd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ed2:
	/* 0xed2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ed7:
	/* 0xed7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_edc:
	/* 0xedc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_edf:
	/* 0xedf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee1:
	/* 0xee1: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ee6:
	/* 0xee6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eeb:
	/* 0xeeb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ef0:
	/* 0xef0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ef5:
	/* 0xef5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_ef8:
	/* 0xef8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_efa:
	/* 0xefa: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_efe:
	/* 0xefe: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_f02:
	/* 0xf02: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f06:
	/* 0xf06: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_f0a:
	/* 0xf0a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f0f:
	/* 0xf0f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f14:
	/* 0xf14: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f19:
	/* 0xf19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f1b:
	/* 0xf1b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f1f:
	/* 0xf1f: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f23:
	/* 0xf23: lea    r15,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f27:
	/* 0xf27: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f2b:
	/* 0xf2b: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f32:
	/* 0xf32: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f37:
	/* 0xf37: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f3c:
	/* 0xf3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f41:
	/* 0xf41: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f44:
	/* 0xf44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f46:
	/* 0xf46: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f4b:
	/* 0xf4b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f4f:
	/* 0xf4f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f54:
	/* 0xf54: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f59:
	/* 0xf59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f5e:
	/* 0xf5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f60:
	/* 0xf60: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f65:
	/* 0xf65: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f6a:
	/* 0xf6a: lea    rdi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f6f:
	/* 0xf6f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f74:
	/* 0xf74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f76:
	/* 0xf76: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f7a:
	/* 0xf7a: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_f7e:
	/* 0xf7e: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_f83:
	/* 0xf83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f85:
	/* 0xf85: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f89:
	/* 0xf89: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f8d:
	/* 0xf8d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f92:
	/* 0xf92: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f97:
	/* 0xf97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f9c:
	/* 0xf9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9e:
	/* 0xf9e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fa3:
	/* 0xfa3: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fa7:
	/* 0xfa7: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_faf:
	/* 0xfaf: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_fb3:
	/* 0xfb3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fb8:
	/* 0xfb8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fbd:
	/* 0xfbd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fc2:
	/* 0xfc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc4:
	/* 0xfc4: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fc9:
	/* 0xfc9: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_fcd:
	/* 0xfcd: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_fd1:
	/* 0xfd1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fd6:
	/* 0xfd6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fdb:
	/* 0xfdb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fe0:
	/* 0xfe0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_fe3:
	/* 0xfe3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe5:
	/* 0xfe5: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fea:
	/* 0xfea: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_fee:
	/* 0xfee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ff3:
	/* 0xff3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ff8:
	/* 0xff8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ffd:
	/* 0xffd: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1000:
	/* 0x1000: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1002:
	/* 0x1002: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_1007:
	/* 0x1007: je     100e <syscall__execveat_enter+0x100e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_100e;
	}
x86_l_1009:
	/* 0x1009: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_100e:
	/* 0x100e: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1012:
	/* 0x1012: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_101a:
	/* 0x101a: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_1022:
	/* 0x1022: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1027:
	/* 0x1027: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_102c:
	/* 0x102c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_102e:
	/* 0x102e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1033:
	/* 0x1033: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1038:
	/* 0x1038: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_103d:
	/* 0x103d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1040:
	/* 0x1040: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1042:
	/* 0x1042: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1047:
	/* 0x1047: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_104c:
	/* 0x104c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1051:
	/* 0x1051: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1056:
	/* 0x1056: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1058:
	/* 0x1058: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_105d:
	/* 0x105d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1062:
	/* 0x1062: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1067:
	/* 0x1067: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_106a:
	/* 0x106a: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_106f:
	/* 0x106f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1071:
	/* 0x1071: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1074:
	/* 0x1074: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1078:
	/* 0x1078: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_107d:
	/* 0x107d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1082:
	/* 0x1082: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1085:
	/* 0x1085: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1087:
	/* 0x1087: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_108c:
	/* 0x108c: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1091:
	/* 0x1091: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_1096:
	/* 0x1096: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1099:
	/* 0x1099: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109b:
	/* 0x109b: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_10a0:
	/* 0x10a0: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_10a4:
	/* 0x10a4: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10ac:
	/* 0x10ac: je     10cc <syscall__execveat_enter+0x10cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10cc;
	}
x86_l_10ae:
	/* 0x10ae: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_10b3:
	/* 0x10b3: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_10ba:
	/* 0x10ba: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_10bf:
	/* 0x10bf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10c2:
	/* 0x10c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c4:
	/* 0x10c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10c6:
	/* 0x10c6: js     10cc <syscall__execveat_enter+0x10cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10cc;
	}
x86_l_10c8:
	/* 0x10c8: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_10cc:
	/* 0x10cc: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_10d4:
	/* 0x10d4: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_10d9:
	/* 0x10d9: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_10de:
	/* 0x10de: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_10e1:
	/* 0x10e1: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_10e7:
	/* 0x10e7: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_10eb:
	/* 0x10eb: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_10f0:
	/* 0x10f0: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_10f7:
	/* 0x10f7: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_10fc:
	/* 0x10fc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10ff:
	/* 0x10ff: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1102:
	/* 0x1102: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1104:
	/* 0x1104: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_110b:
	/* 0x110b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_110d:
	/* 0x110d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_110e:
	/* 0x110e: jmp    47f0 <syscall__execveat_enter+0x47f0> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1113:
	/* 0x1113: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1118:
	/* 0x1118: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1120:
	/* 0x1120: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1124:
	/* 0x1124: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_112b:
	/* 0x112b: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1130:
	/* 0x1130: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1135:
	/* 0x1135: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1137:
	/* 0x1137: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_113c:
	/* 0x113c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1144:
	/* 0x1144: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1147:
	/* 0x1147: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_114f:
	/* 0x114f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1158:
	/* 0x1158: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_115c:
	/* 0x115c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1161:
	/* 0x1161: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1166:
	/* 0x1166: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_116b:
	/* 0x116b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116d:
	/* 0x116d: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_116f:
	/* 0x116f: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1175:
	/* 0x1175: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_117b:
	/* 0x117b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_117e:
	/* 0x117e: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1183:
	/* 0x1183: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_1189:
	/* 0x1189: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_118e:
	/* 0x118e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1196:
	/* 0x1196: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_119a:
	/* 0x119a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_11a1:
	/* 0x11a1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11a6:
	/* 0x11a6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_11ab:
	/* 0x11ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ad:
	/* 0x11ad: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_11b1:
	/* 0x11b1: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_11b3:
	/* 0x11b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11b5:
	/* 0x11b5: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_11bb:
	/* 0x11bb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_11be:
	/* 0x11be: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_11c3:
	/* 0x11c3: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_11c9:
	/* 0x11c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11ce:
	/* 0x11ce: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_11d6:
	/* 0x11d6: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_11da:
	/* 0x11da: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_11e1:
	/* 0x11e1: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_11e6:
	/* 0x11e6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11eb:
	/* 0x11eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ed:
	/* 0x11ed: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_11f2:
	/* 0x11f2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_11fa:
	/* 0x11fa: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_11fd:
	/* 0x11fd: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1205:
	/* 0x1205: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_120e:
	/* 0x120e: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1212:
	/* 0x1212: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1217:
	/* 0x1217: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_121c:
	/* 0x121c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1221:
	/* 0x1221: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1223:
	/* 0x1223: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1225:
	/* 0x1225: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_122b:
	/* 0x122b: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1231:
	/* 0x1231: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1234:
	/* 0x1234: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1239:
	/* 0x1239: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_123f:
	/* 0x123f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1244:
	/* 0x1244: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_124c:
	/* 0x124c: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1250:
	/* 0x1250: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1257:
	/* 0x1257: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_125c:
	/* 0x125c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1261:
	/* 0x1261: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1263:
	/* 0x1263: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1267:
	/* 0x1267: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1269:
	/* 0x1269: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_126b:
	/* 0x126b: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_1271:
	/* 0x1271: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1274:
	/* 0x1274: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1279:
	/* 0x1279: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_127f:
	/* 0x127f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1284:
	/* 0x1284: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_128c:
	/* 0x128c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1290:
	/* 0x1290: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1297:
	/* 0x1297: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_129c:
	/* 0x129c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12a1:
	/* 0x12a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a3:
	/* 0x12a3: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_12a8:
	/* 0x12a8: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_12b0:
	/* 0x12b0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_12b3:
	/* 0x12b3: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_12bb:
	/* 0x12bb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12c4:
	/* 0x12c4: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12c8:
	/* 0x12c8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12cd:
	/* 0x12cd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12d2:
	/* 0x12d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12d7:
	/* 0x12d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d9:
	/* 0x12d9: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_12db:
	/* 0x12db: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12e1:
	/* 0x12e1: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_12e7:
	/* 0x12e7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12ea:
	/* 0x12ea: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_12ef:
	/* 0x12ef: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_12f5:
	/* 0x12f5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_12fa:
	/* 0x12fa: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1302:
	/* 0x1302: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1306:
	/* 0x1306: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_130d:
	/* 0x130d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1312:
	/* 0x1312: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1317:
	/* 0x1317: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1319:
	/* 0x1319: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_131d:
	/* 0x131d: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_131f:
	/* 0x131f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1321:
	/* 0x1321: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_1327:
	/* 0x1327: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_132a:
	/* 0x132a: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_132f:
	/* 0x132f: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_1335:
	/* 0x1335: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_133a:
	/* 0x133a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1342:
	/* 0x1342: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1346:
	/* 0x1346: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_134d:
	/* 0x134d: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1352:
	/* 0x1352: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1357:
	/* 0x1357: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1359:
	/* 0x1359: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_135e:
	/* 0x135e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1366:
	/* 0x1366: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1369:
	/* 0x1369: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1371:
	/* 0x1371: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_137a:
	/* 0x137a: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_137e:
	/* 0x137e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1383:
	/* 0x1383: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1388:
	/* 0x1388: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_138d:
	/* 0x138d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138f:
	/* 0x138f: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_1391:
	/* 0x1391: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1397:
	/* 0x1397: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_139d:
	/* 0x139d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_13a0:
	/* 0x13a0: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_13a5:
	/* 0x13a5: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_13ab:
	/* 0x13ab: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_13b0:
	/* 0x13b0: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_13b8:
	/* 0x13b8: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_13bc:
	/* 0x13bc: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_13c3:
	/* 0x13c3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13c8:
	/* 0x13c8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_13cd:
	/* 0x13cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13cf:
	/* 0x13cf: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_13d3:
	/* 0x13d3: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_13d5:
	/* 0x13d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13d7:
	/* 0x13d7: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_13dd:
	/* 0x13dd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_13e0:
	/* 0x13e0: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_13e5:
	/* 0x13e5: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_13eb:
	/* 0x13eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13f0:
	/* 0x13f0: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_13f8:
	/* 0x13f8: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_13fc:
	/* 0x13fc: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1403:
	/* 0x1403: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1408:
	/* 0x1408: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_140d:
	/* 0x140d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_140f:
	/* 0x140f: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
	return 5140ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5140ULL: goto x86_l_1414;
	case 5148ULL: goto x86_l_141c;
	case 5151ULL: goto x86_l_141f;
	case 5159ULL: goto x86_l_1427;
	case 5168ULL: goto x86_l_1430;
	case 5172ULL: goto x86_l_1434;
	case 5177ULL: goto x86_l_1439;
	case 5182ULL: goto x86_l_143e;
	case 5187ULL: goto x86_l_1443;
	case 5189ULL: goto x86_l_1445;
	case 5191ULL: goto x86_l_1447;
	case 5197ULL: goto x86_l_144d;
	case 5203ULL: goto x86_l_1453;
	case 5206ULL: goto x86_l_1456;
	case 5211ULL: goto x86_l_145b;
	case 5217ULL: goto x86_l_1461;
	case 5222ULL: goto x86_l_1466;
	case 5230ULL: goto x86_l_146e;
	case 5234ULL: goto x86_l_1472;
	case 5241ULL: goto x86_l_1479;
	case 5246ULL: goto x86_l_147e;
	case 5251ULL: goto x86_l_1483;
	case 5253ULL: goto x86_l_1485;
	case 5257ULL: goto x86_l_1489;
	case 5259ULL: goto x86_l_148b;
	case 5261ULL: goto x86_l_148d;
	case 5267ULL: goto x86_l_1493;
	case 5270ULL: goto x86_l_1496;
	case 5275ULL: goto x86_l_149b;
	case 5281ULL: goto x86_l_14a1;
	case 5286ULL: goto x86_l_14a6;
	case 5294ULL: goto x86_l_14ae;
	case 5298ULL: goto x86_l_14b2;
	case 5305ULL: goto x86_l_14b9;
	case 5310ULL: goto x86_l_14be;
	case 5315ULL: goto x86_l_14c3;
	case 5317ULL: goto x86_l_14c5;
	case 5322ULL: goto x86_l_14ca;
	case 5330ULL: goto x86_l_14d2;
	case 5333ULL: goto x86_l_14d5;
	case 5341ULL: goto x86_l_14dd;
	case 5350ULL: goto x86_l_14e6;
	case 5354ULL: goto x86_l_14ea;
	case 5359ULL: goto x86_l_14ef;
	case 5364ULL: goto x86_l_14f4;
	case 5369ULL: goto x86_l_14f9;
	case 5371ULL: goto x86_l_14fb;
	case 5373ULL: goto x86_l_14fd;
	case 5379ULL: goto x86_l_1503;
	case 5385ULL: goto x86_l_1509;
	case 5388ULL: goto x86_l_150c;
	case 5393ULL: goto x86_l_1511;
	case 5399ULL: goto x86_l_1517;
	case 5404ULL: goto x86_l_151c;
	case 5412ULL: goto x86_l_1524;
	case 5416ULL: goto x86_l_1528;
	case 5423ULL: goto x86_l_152f;
	case 5428ULL: goto x86_l_1534;
	case 5433ULL: goto x86_l_1539;
	case 5435ULL: goto x86_l_153b;
	case 5439ULL: goto x86_l_153f;
	case 5441ULL: goto x86_l_1541;
	case 5443ULL: goto x86_l_1543;
	case 5449ULL: goto x86_l_1549;
	case 5452ULL: goto x86_l_154c;
	case 5457ULL: goto x86_l_1551;
	case 5463ULL: goto x86_l_1557;
	case 5468ULL: goto x86_l_155c;
	case 5476ULL: goto x86_l_1564;
	case 5480ULL: goto x86_l_1568;
	case 5487ULL: goto x86_l_156f;
	case 5492ULL: goto x86_l_1574;
	case 5497ULL: goto x86_l_1579;
	case 5499ULL: goto x86_l_157b;
	case 5504ULL: goto x86_l_1580;
	case 5512ULL: goto x86_l_1588;
	case 5515ULL: goto x86_l_158b;
	case 5523ULL: goto x86_l_1593;
	case 5532ULL: goto x86_l_159c;
	case 5536ULL: goto x86_l_15a0;
	case 5541ULL: goto x86_l_15a5;
	case 5546ULL: goto x86_l_15aa;
	case 5551ULL: goto x86_l_15af;
	case 5553ULL: goto x86_l_15b1;
	case 5555ULL: goto x86_l_15b3;
	case 5561ULL: goto x86_l_15b9;
	case 5567ULL: goto x86_l_15bf;
	case 5570ULL: goto x86_l_15c2;
	case 5575ULL: goto x86_l_15c7;
	case 5581ULL: goto x86_l_15cd;
	case 5586ULL: goto x86_l_15d2;
	case 5594ULL: goto x86_l_15da;
	case 5598ULL: goto x86_l_15de;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5615ULL: goto x86_l_15ef;
	case 5617ULL: goto x86_l_15f1;
	case 5621ULL: goto x86_l_15f5;
	case 5623ULL: goto x86_l_15f7;
	case 5625ULL: goto x86_l_15f9;
	case 5631ULL: goto x86_l_15ff;
	case 5634ULL: goto x86_l_1602;
	case 5639ULL: goto x86_l_1607;
	case 5645ULL: goto x86_l_160d;
	case 5650ULL: goto x86_l_1612;
	case 5658ULL: goto x86_l_161a;
	case 5662ULL: goto x86_l_161e;
	case 5669ULL: goto x86_l_1625;
	case 5674ULL: goto x86_l_162a;
	case 5679ULL: goto x86_l_162f;
	case 5681ULL: goto x86_l_1631;
	case 5686ULL: goto x86_l_1636;
	case 5694ULL: goto x86_l_163e;
	case 5697ULL: goto x86_l_1641;
	case 5705ULL: goto x86_l_1649;
	case 5714ULL: goto x86_l_1652;
	case 5718ULL: goto x86_l_1656;
	case 5723ULL: goto x86_l_165b;
	case 5728ULL: goto x86_l_1660;
	case 5733ULL: goto x86_l_1665;
	case 5735ULL: goto x86_l_1667;
	case 5737ULL: goto x86_l_1669;
	case 5743ULL: goto x86_l_166f;
	case 5749ULL: goto x86_l_1675;
	case 5752ULL: goto x86_l_1678;
	case 5757ULL: goto x86_l_167d;
	case 5763ULL: goto x86_l_1683;
	case 5768ULL: goto x86_l_1688;
	case 5776ULL: goto x86_l_1690;
	case 5780ULL: goto x86_l_1694;
	case 5787ULL: goto x86_l_169b;
	case 5792ULL: goto x86_l_16a0;
	case 5797ULL: goto x86_l_16a5;
	case 5799ULL: goto x86_l_16a7;
	case 5803ULL: goto x86_l_16ab;
	case 5805ULL: goto x86_l_16ad;
	case 5807ULL: goto x86_l_16af;
	case 5813ULL: goto x86_l_16b5;
	case 5816ULL: goto x86_l_16b8;
	case 5821ULL: goto x86_l_16bd;
	case 5827ULL: goto x86_l_16c3;
	case 5832ULL: goto x86_l_16c8;
	case 5840ULL: goto x86_l_16d0;
	case 5844ULL: goto x86_l_16d4;
	case 5851ULL: goto x86_l_16db;
	case 5856ULL: goto x86_l_16e0;
	case 5861ULL: goto x86_l_16e5;
	case 5863ULL: goto x86_l_16e7;
	case 5868ULL: goto x86_l_16ec;
	case 5876ULL: goto x86_l_16f4;
	case 5879ULL: goto x86_l_16f7;
	case 5887ULL: goto x86_l_16ff;
	case 5896ULL: goto x86_l_1708;
	case 5900ULL: goto x86_l_170c;
	case 5905ULL: goto x86_l_1711;
	case 5910ULL: goto x86_l_1716;
	case 5915ULL: goto x86_l_171b;
	case 5917ULL: goto x86_l_171d;
	case 5919ULL: goto x86_l_171f;
	case 5925ULL: goto x86_l_1725;
	case 5931ULL: goto x86_l_172b;
	case 5934ULL: goto x86_l_172e;
	case 5939ULL: goto x86_l_1733;
	case 5945ULL: goto x86_l_1739;
	case 5950ULL: goto x86_l_173e;
	case 5958ULL: goto x86_l_1746;
	case 5962ULL: goto x86_l_174a;
	case 5969ULL: goto x86_l_1751;
	case 5974ULL: goto x86_l_1756;
	case 5979ULL: goto x86_l_175b;
	case 5981ULL: goto x86_l_175d;
	case 5985ULL: goto x86_l_1761;
	case 5987ULL: goto x86_l_1763;
	case 5989ULL: goto x86_l_1765;
	case 5995ULL: goto x86_l_176b;
	case 5998ULL: goto x86_l_176e;
	case 6003ULL: goto x86_l_1773;
	case 6009ULL: goto x86_l_1779;
	case 6014ULL: goto x86_l_177e;
	case 6022ULL: goto x86_l_1786;
	case 6026ULL: goto x86_l_178a;
	case 6033ULL: goto x86_l_1791;
	case 6038ULL: goto x86_l_1796;
	case 6043ULL: goto x86_l_179b;
	case 6045ULL: goto x86_l_179d;
	case 6050ULL: goto x86_l_17a2;
	case 6058ULL: goto x86_l_17aa;
	case 6061ULL: goto x86_l_17ad;
	case 6069ULL: goto x86_l_17b5;
	case 6078ULL: goto x86_l_17be;
	case 6082ULL: goto x86_l_17c2;
	case 6087ULL: goto x86_l_17c7;
	case 6092ULL: goto x86_l_17cc;
	case 6097ULL: goto x86_l_17d1;
	case 6099ULL: goto x86_l_17d3;
	case 6101ULL: goto x86_l_17d5;
	case 6107ULL: goto x86_l_17db;
	case 6113ULL: goto x86_l_17e1;
	case 6116ULL: goto x86_l_17e4;
	case 6121ULL: goto x86_l_17e9;
	case 6127ULL: goto x86_l_17ef;
	case 6132ULL: goto x86_l_17f4;
	case 6140ULL: goto x86_l_17fc;
	case 6144ULL: goto x86_l_1800;
	case 6151ULL: goto x86_l_1807;
	case 6156ULL: goto x86_l_180c;
	case 6161ULL: goto x86_l_1811;
	case 6163ULL: goto x86_l_1813;
	case 6167ULL: goto x86_l_1817;
	case 6169ULL: goto x86_l_1819;
	case 6171ULL: goto x86_l_181b;
	case 6177ULL: goto x86_l_1821;
	case 6180ULL: goto x86_l_1824;
	case 6185ULL: goto x86_l_1829;
	case 6191ULL: goto x86_l_182f;
	case 6196ULL: goto x86_l_1834;
	case 6204ULL: goto x86_l_183c;
	case 6208ULL: goto x86_l_1840;
	case 6215ULL: goto x86_l_1847;
	case 6220ULL: goto x86_l_184c;
	case 6225ULL: goto x86_l_1851;
	case 6227ULL: goto x86_l_1853;
	case 6232ULL: goto x86_l_1858;
	case 6240ULL: goto x86_l_1860;
	case 6243ULL: goto x86_l_1863;
	case 6251ULL: goto x86_l_186b;
	case 6260ULL: goto x86_l_1874;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6274ULL: goto x86_l_1882;
	case 6279ULL: goto x86_l_1887;
	case 6281ULL: goto x86_l_1889;
	case 6283ULL: goto x86_l_188b;
	case 6289ULL: goto x86_l_1891;
	case 6295ULL: goto x86_l_1897;
	case 6298ULL: goto x86_l_189a;
	case 6303ULL: goto x86_l_189f;
	case 6309ULL: goto x86_l_18a5;
	case 6314ULL: goto x86_l_18aa;
	case 6322ULL: goto x86_l_18b2;
	case 6326ULL: goto x86_l_18b6;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6345ULL: goto x86_l_18c9;
	case 6349ULL: goto x86_l_18cd;
	case 6351ULL: goto x86_l_18cf;
	case 6353ULL: goto x86_l_18d1;
	case 6359ULL: goto x86_l_18d7;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6373ULL: goto x86_l_18e5;
	case 6378ULL: goto x86_l_18ea;
	case 6386ULL: goto x86_l_18f2;
	case 6390ULL: goto x86_l_18f6;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6407ULL: goto x86_l_1907;
	case 6409ULL: goto x86_l_1909;
	case 6414ULL: goto x86_l_190e;
	case 6422ULL: goto x86_l_1916;
	case 6425ULL: goto x86_l_1919;
	case 6433ULL: goto x86_l_1921;
	case 6442ULL: goto x86_l_192a;
	case 6446ULL: goto x86_l_192e;
	case 6451ULL: goto x86_l_1933;
	case 6456ULL: goto x86_l_1938;
	case 6461ULL: goto x86_l_193d;
	case 6463ULL: goto x86_l_193f;
	case 6465ULL: goto x86_l_1941;
	case 6471ULL: goto x86_l_1947;
	case 6477ULL: goto x86_l_194d;
	case 6480ULL: goto x86_l_1950;
	case 6485ULL: goto x86_l_1955;
	case 6491ULL: goto x86_l_195b;
	case 6496ULL: goto x86_l_1960;
	case 6504ULL: goto x86_l_1968;
	case 6508ULL: goto x86_l_196c;
	case 6515ULL: goto x86_l_1973;
	case 6520ULL: goto x86_l_1978;
	case 6525ULL: goto x86_l_197d;
	case 6527ULL: goto x86_l_197f;
	case 6531ULL: goto x86_l_1983;
	case 6533ULL: goto x86_l_1985;
	case 6535ULL: goto x86_l_1987;
	case 6541ULL: goto x86_l_198d;
	case 6544ULL: goto x86_l_1990;
	case 6549ULL: goto x86_l_1995;
	case 6555ULL: goto x86_l_199b;
	case 6560ULL: goto x86_l_19a0;
	case 6568ULL: goto x86_l_19a8;
	case 6572ULL: goto x86_l_19ac;
	case 6579ULL: goto x86_l_19b3;
	case 6584ULL: goto x86_l_19b8;
	case 6589ULL: goto x86_l_19bd;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6604ULL: goto x86_l_19cc;
	case 6607ULL: goto x86_l_19cf;
	case 6615ULL: goto x86_l_19d7;
	case 6624ULL: goto x86_l_19e0;
	case 6628ULL: goto x86_l_19e4;
	case 6633ULL: goto x86_l_19e9;
	case 6638ULL: goto x86_l_19ee;
	case 6643ULL: goto x86_l_19f3;
	case 6645ULL: goto x86_l_19f5;
	case 6647ULL: goto x86_l_19f7;
	case 6653ULL: goto x86_l_19fd;
	case 6659ULL: goto x86_l_1a03;
	case 6662ULL: goto x86_l_1a06;
	case 6667ULL: goto x86_l_1a0b;
	case 6673ULL: goto x86_l_1a11;
	case 6678ULL: goto x86_l_1a16;
	case 6686ULL: goto x86_l_1a1e;
	case 6690ULL: goto x86_l_1a22;
	case 6697ULL: goto x86_l_1a29;
	case 6702ULL: goto x86_l_1a2e;
	case 6707ULL: goto x86_l_1a33;
	case 6709ULL: goto x86_l_1a35;
	case 6713ULL: goto x86_l_1a39;
	case 6715ULL: goto x86_l_1a3b;
	case 6717ULL: goto x86_l_1a3d;
	case 6723ULL: goto x86_l_1a43;
	case 6726ULL: goto x86_l_1a46;
	case 6731ULL: goto x86_l_1a4b;
	case 6737ULL: goto x86_l_1a51;
	case 6742ULL: goto x86_l_1a56;
	case 6750ULL: goto x86_l_1a5e;
	case 6754ULL: goto x86_l_1a62;
	case 6761ULL: goto x86_l_1a69;
	case 6766ULL: goto x86_l_1a6e;
	case 6771ULL: goto x86_l_1a73;
	case 6773ULL: goto x86_l_1a75;
	case 6778ULL: goto x86_l_1a7a;
	case 6786ULL: goto x86_l_1a82;
	case 6789ULL: goto x86_l_1a85;
	case 6797ULL: goto x86_l_1a8d;
	case 6806ULL: goto x86_l_1a96;
	case 6810ULL: goto x86_l_1a9a;
	case 6815ULL: goto x86_l_1a9f;
	case 6820ULL: goto x86_l_1aa4;
	case 6825ULL: goto x86_l_1aa9;
	case 6827ULL: goto x86_l_1aab;
	case 6829ULL: goto x86_l_1aad;
	case 6835ULL: goto x86_l_1ab3;
	case 6841ULL: goto x86_l_1ab9;
	case 6844ULL: goto x86_l_1abc;
	case 6849ULL: goto x86_l_1ac1;
	case 6855ULL: goto x86_l_1ac7;
	case 6860ULL: goto x86_l_1acc;
	case 6868ULL: goto x86_l_1ad4;
	case 6872ULL: goto x86_l_1ad8;
	case 6879ULL: goto x86_l_1adf;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6891ULL: goto x86_l_1aeb;
	case 6895ULL: goto x86_l_1aef;
	case 6897ULL: goto x86_l_1af1;
	case 6899ULL: goto x86_l_1af3;
	case 6905ULL: goto x86_l_1af9;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6919ULL: goto x86_l_1b07;
	case 6924ULL: goto x86_l_1b0c;
	case 6932ULL: goto x86_l_1b14;
	case 6936ULL: goto x86_l_1b18;
	case 6943ULL: goto x86_l_1b1f;
	case 6948ULL: goto x86_l_1b24;
	case 6953ULL: goto x86_l_1b29;
	case 6955ULL: goto x86_l_1b2b;
	case 6960ULL: goto x86_l_1b30;
	case 6968ULL: goto x86_l_1b38;
	case 6971ULL: goto x86_l_1b3b;
	case 6979ULL: goto x86_l_1b43;
	case 6988ULL: goto x86_l_1b4c;
	case 6992ULL: goto x86_l_1b50;
	case 6997ULL: goto x86_l_1b55;
	case 7002ULL: goto x86_l_1b5a;
	case 7007ULL: goto x86_l_1b5f;
	case 7009ULL: goto x86_l_1b61;
	case 7011ULL: goto x86_l_1b63;
	case 7017ULL: goto x86_l_1b69;
	case 7023ULL: goto x86_l_1b6f;
	case 7026ULL: goto x86_l_1b72;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1414:
	/* 0x1414: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_141c:
	/* 0x141c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_141f:
	/* 0x141f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1427:
	/* 0x1427: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1430:
	/* 0x1430: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1434:
	/* 0x1434: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1439:
	/* 0x1439: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_143e:
	/* 0x143e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1443:
	/* 0x1443: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1445:
	/* 0x1445: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_1447:
	/* 0x1447: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_144d:
	/* 0x144d: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1453:
	/* 0x1453: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1456:
	/* 0x1456: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_145b:
	/* 0x145b: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_1461:
	/* 0x1461: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1466:
	/* 0x1466: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_146e:
	/* 0x146e: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1472:
	/* 0x1472: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1479:
	/* 0x1479: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_147e:
	/* 0x147e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1483:
	/* 0x1483: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1485:
	/* 0x1485: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1489:
	/* 0x1489: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_148b:
	/* 0x148b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_148d:
	/* 0x148d: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_1493:
	/* 0x1493: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1496:
	/* 0x1496: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_149b:
	/* 0x149b: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_14a1:
	/* 0x14a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14a6:
	/* 0x14a6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_14ae:
	/* 0x14ae: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_14b2:
	/* 0x14b2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_14b9:
	/* 0x14b9: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_14be:
	/* 0x14be: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14c3:
	/* 0x14c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c5:
	/* 0x14c5: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_14ca:
	/* 0x14ca: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_14d2:
	/* 0x14d2: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_14d5:
	/* 0x14d5: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_14dd:
	/* 0x14dd: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_14e6:
	/* 0x14e6: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14ea:
	/* 0x14ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14ef:
	/* 0x14ef: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14f4:
	/* 0x14f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14f9:
	/* 0x14f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14fb:
	/* 0x14fb: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_14fd:
	/* 0x14fd: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1503:
	/* 0x1503: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1509:
	/* 0x1509: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_150c:
	/* 0x150c: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1511:
	/* 0x1511: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_1517:
	/* 0x1517: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_151c:
	/* 0x151c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1524:
	/* 0x1524: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1528:
	/* 0x1528: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_152f:
	/* 0x152f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1534:
	/* 0x1534: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1539:
	/* 0x1539: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153b:
	/* 0x153b: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_153f:
	/* 0x153f: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_1541:
	/* 0x1541: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1543:
	/* 0x1543: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_1549:
	/* 0x1549: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_154c:
	/* 0x154c: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1551:
	/* 0x1551: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_1557:
	/* 0x1557: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_155c:
	/* 0x155c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1564:
	/* 0x1564: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1568:
	/* 0x1568: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_156f:
	/* 0x156f: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1574:
	/* 0x1574: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1579:
	/* 0x1579: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157b:
	/* 0x157b: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1580:
	/* 0x1580: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1588:
	/* 0x1588: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_158b:
	/* 0x158b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1593:
	/* 0x1593: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_159c:
	/* 0x159c: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15a0:
	/* 0x15a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15a5:
	/* 0x15a5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15aa:
	/* 0x15aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15af:
	/* 0x15af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b1:
	/* 0x15b1: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_15b3:
	/* 0x15b3: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_15b9:
	/* 0x15b9: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_15bf:
	/* 0x15bf: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15c2:
	/* 0x15c2: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_15c7:
	/* 0x15c7: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_15cd:
	/* 0x15cd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_15d2:
	/* 0x15d2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_15da:
	/* 0x15da: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_15de:
	/* 0x15de: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_15e5:
	/* 0x15e5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15ea:
	/* 0x15ea: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_15ef:
	/* 0x15ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f1:
	/* 0x15f1: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_15f5:
	/* 0x15f5: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_15f7:
	/* 0x15f7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15f9:
	/* 0x15f9: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_15ff:
	/* 0x15ff: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1602:
	/* 0x1602: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1607:
	/* 0x1607: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_160d:
	/* 0x160d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1612:
	/* 0x1612: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_161a:
	/* 0x161a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_161e:
	/* 0x161e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1625:
	/* 0x1625: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_162a:
	/* 0x162a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_162f:
	/* 0x162f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1631:
	/* 0x1631: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1636:
	/* 0x1636: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_163e:
	/* 0x163e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1641:
	/* 0x1641: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1649:
	/* 0x1649: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1652:
	/* 0x1652: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1656:
	/* 0x1656: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_165b:
	/* 0x165b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1660:
	/* 0x1660: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1665:
	/* 0x1665: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1667:
	/* 0x1667: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_1669:
	/* 0x1669: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_166f:
	/* 0x166f: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1675:
	/* 0x1675: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1678:
	/* 0x1678: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_167d:
	/* 0x167d: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_1683:
	/* 0x1683: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1688:
	/* 0x1688: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1690:
	/* 0x1690: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1694:
	/* 0x1694: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_169b:
	/* 0x169b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16a0:
	/* 0x16a0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_16a5:
	/* 0x16a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a7:
	/* 0x16a7: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_16ab:
	/* 0x16ab: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_16ad:
	/* 0x16ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16af:
	/* 0x16af: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_16b5:
	/* 0x16b5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16b8:
	/* 0x16b8: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_16bd:
	/* 0x16bd: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_16c3:
	/* 0x16c3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16c8:
	/* 0x16c8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_16d0:
	/* 0x16d0: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_16d4:
	/* 0x16d4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_16db:
	/* 0x16db: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_16e0:
	/* 0x16e0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16e5:
	/* 0x16e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e7:
	/* 0x16e7: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_16ec:
	/* 0x16ec: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_16f4:
	/* 0x16f4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_16f7:
	/* 0x16f7: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_16ff:
	/* 0x16ff: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1708:
	/* 0x1708: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_170c:
	/* 0x170c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1711:
	/* 0x1711: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1716:
	/* 0x1716: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_171b:
	/* 0x171b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_171d:
	/* 0x171d: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_171f:
	/* 0x171f: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1725:
	/* 0x1725: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_172b:
	/* 0x172b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_172e:
	/* 0x172e: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1733:
	/* 0x1733: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_1739:
	/* 0x1739: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_173e:
	/* 0x173e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1746:
	/* 0x1746: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_174a:
	/* 0x174a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1751:
	/* 0x1751: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1756:
	/* 0x1756: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_175b:
	/* 0x175b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175d:
	/* 0x175d: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1761:
	/* 0x1761: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_1763:
	/* 0x1763: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1765:
	/* 0x1765: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_176b:
	/* 0x176b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_176e:
	/* 0x176e: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1773:
	/* 0x1773: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_1779:
	/* 0x1779: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_177e:
	/* 0x177e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1786:
	/* 0x1786: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_178a:
	/* 0x178a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1791:
	/* 0x1791: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1796:
	/* 0x1796: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_179b:
	/* 0x179b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179d:
	/* 0x179d: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_17a2:
	/* 0x17a2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_17aa:
	/* 0x17aa: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_17ad:
	/* 0x17ad: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_17b5:
	/* 0x17b5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17be:
	/* 0x17be: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17c2:
	/* 0x17c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c7:
	/* 0x17c7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17cc:
	/* 0x17cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17d1:
	/* 0x17d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d3:
	/* 0x17d3: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_17d5:
	/* 0x17d5: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17db:
	/* 0x17db: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_17e1:
	/* 0x17e1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17e4:
	/* 0x17e4: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_17e9:
	/* 0x17e9: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_17ef:
	/* 0x17ef: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_17f4:
	/* 0x17f4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17fc:
	/* 0x17fc: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1800:
	/* 0x1800: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1807:
	/* 0x1807: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_180c:
	/* 0x180c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1811:
	/* 0x1811: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1813:
	/* 0x1813: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1817:
	/* 0x1817: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_1819:
	/* 0x1819: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_181b:
	/* 0x181b: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_1821:
	/* 0x1821: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1824:
	/* 0x1824: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1829:
	/* 0x1829: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_182f:
	/* 0x182f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1834:
	/* 0x1834: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_183c:
	/* 0x183c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1840:
	/* 0x1840: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1847:
	/* 0x1847: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_184c:
	/* 0x184c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1851:
	/* 0x1851: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1853:
	/* 0x1853: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1858:
	/* 0x1858: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1860:
	/* 0x1860: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1863:
	/* 0x1863: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_186b:
	/* 0x186b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1874:
	/* 0x1874: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1878:
	/* 0x1878: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_187d:
	/* 0x187d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1882:
	/* 0x1882: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1887:
	/* 0x1887: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1889:
	/* 0x1889: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_188b:
	/* 0x188b: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1891:
	/* 0x1891: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1897:
	/* 0x1897: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_189a:
	/* 0x189a: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_189f:
	/* 0x189f: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_18a5:
	/* 0x18a5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_18aa:
	/* 0x18aa: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18b2:
	/* 0x18b2: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_18b6:
	/* 0x18b6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_18bd:
	/* 0x18bd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18c2:
	/* 0x18c2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_18c7:
	/* 0x18c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c9:
	/* 0x18c9: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_18cd:
	/* 0x18cd: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_18cf:
	/* 0x18cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18d1:
	/* 0x18d1: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_18d7:
	/* 0x18d7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18da:
	/* 0x18da: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_18df:
	/* 0x18df: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_18e5:
	/* 0x18e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18ea:
	/* 0x18ea: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18f2:
	/* 0x18f2: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_18f6:
	/* 0x18f6: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_18fd:
	/* 0x18fd: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1902:
	/* 0x1902: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1907:
	/* 0x1907: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1909:
	/* 0x1909: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_190e:
	/* 0x190e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1916:
	/* 0x1916: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1919:
	/* 0x1919: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1921:
	/* 0x1921: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_192a:
	/* 0x192a: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_192e:
	/* 0x192e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1933:
	/* 0x1933: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1938:
	/* 0x1938: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_193d:
	/* 0x193d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193f:
	/* 0x193f: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_1941:
	/* 0x1941: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1947:
	/* 0x1947: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_194d:
	/* 0x194d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1950:
	/* 0x1950: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1955:
	/* 0x1955: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_195b:
	/* 0x195b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1960:
	/* 0x1960: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1968:
	/* 0x1968: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_196c:
	/* 0x196c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1973:
	/* 0x1973: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1978:
	/* 0x1978: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_197d:
	/* 0x197d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_197f:
	/* 0x197f: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1983:
	/* 0x1983: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_1985:
	/* 0x1985: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1987:
	/* 0x1987: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_198d:
	/* 0x198d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1990:
	/* 0x1990: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1995:
	/* 0x1995: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_199b:
	/* 0x199b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19a0:
	/* 0x19a0: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19a8:
	/* 0x19a8: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_19ac:
	/* 0x19ac: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_19b3:
	/* 0x19b3: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_19b8:
	/* 0x19b8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19bd:
	/* 0x19bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19bf:
	/* 0x19bf: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_19c4:
	/* 0x19c4: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_19cc:
	/* 0x19cc: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_19cf:
	/* 0x19cf: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_19d7:
	/* 0x19d7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_19e0:
	/* 0x19e0: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_19e4:
	/* 0x19e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19e9:
	/* 0x19e9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19ee:
	/* 0x19ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19f3:
	/* 0x19f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f5:
	/* 0x19f5: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_19f7:
	/* 0x19f7: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_19fd:
	/* 0x19fd: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1a03:
	/* 0x1a03: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a06:
	/* 0x1a06: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1a0b:
	/* 0x1a0b: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_1a11:
	/* 0x1a11: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1a16:
	/* 0x1a16: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a1e:
	/* 0x1a1e: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1a22:
	/* 0x1a22: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1a29:
	/* 0x1a29: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a2e:
	/* 0x1a2e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a33:
	/* 0x1a33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a35:
	/* 0x1a35: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a39:
	/* 0x1a39: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_1a3b:
	/* 0x1a3b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a3d:
	/* 0x1a3d: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_1a43:
	/* 0x1a43: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a46:
	/* 0x1a46: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1a4b:
	/* 0x1a4b: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_1a51:
	/* 0x1a51: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a56:
	/* 0x1a56: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a5e:
	/* 0x1a5e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1a62:
	/* 0x1a62: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1a69:
	/* 0x1a69: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a6e:
	/* 0x1a6e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a73:
	/* 0x1a73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a75:
	/* 0x1a75: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1a7a:
	/* 0x1a7a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1a82:
	/* 0x1a82: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1a85:
	/* 0x1a85: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1a8d:
	/* 0x1a8d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1a96:
	/* 0x1a96: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1a9a:
	/* 0x1a9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a9f:
	/* 0x1a9f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1aa4:
	/* 0x1aa4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aa9:
	/* 0x1aa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aab:
	/* 0x1aab: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_1aad:
	/* 0x1aad: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ab3:
	/* 0x1ab3: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1ab9:
	/* 0x1ab9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1abc:
	/* 0x1abc: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1ac1:
	/* 0x1ac1: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_1ac7:
	/* 0x1ac7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1acc:
	/* 0x1acc: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ad4:
	/* 0x1ad4: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1ad8:
	/* 0x1ad8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1adf:
	/* 0x1adf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ae9:
	/* 0x1ae9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aeb:
	/* 0x1aeb: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1aef:
	/* 0x1aef: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_1af1:
	/* 0x1af1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1af3:
	/* 0x1af3: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_1af9:
	/* 0x1af9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1afc:
	/* 0x1afc: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1b01:
	/* 0x1b01: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_1b07:
	/* 0x1b07: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b0c:
	/* 0x1b0c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b14:
	/* 0x1b14: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1b18:
	/* 0x1b18: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1b1f:
	/* 0x1b1f: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b24:
	/* 0x1b24: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b29:
	/* 0x1b29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2b:
	/* 0x1b2b: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_1b30:
	/* 0x1b30: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1b38:
	/* 0x1b38: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1b3b:
	/* 0x1b3b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1b43:
	/* 0x1b43: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b4c:
	/* 0x1b4c: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
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
	/* 0x1b61: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1b63:
	/* 0x1b63: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b69:
	/* 0x1b69: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1b6f:
	/* 0x1b6f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b72:
	/* 0x1b72: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
	return 7031ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7031ULL: goto x86_l_1b77;
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
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b77:
	/* 0x1b77: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x1ba5: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1ba7:
	/* 0x1ba7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ba9:
	/* 0x1ba9: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_1baf:
	/* 0x1baf: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1bb2:
	/* 0x1bb2: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1bb7:
	/* 0x1bb7: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x1c02: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
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
	/* 0x1c1a: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_1c1c:
	/* 0x1c1c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c22:
	/* 0x1c22: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1c28:
	/* 0x1c28: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c2b:
	/* 0x1c2b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1c30:
	/* 0x1c30: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x1c5e: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_1c60:
	/* 0x1c60: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c62:
	/* 0x1c62: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_1c68:
	/* 0x1c68: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c6b:
	/* 0x1c6b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1c70:
	/* 0x1c70: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x1cbb: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
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
	/* 0x1cd3: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_1cd5:
	/* 0x1cd5: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1cdb:
	/* 0x1cdb: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1ce1:
	/* 0x1ce1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ce4:
	/* 0x1ce4: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1ce9:
	/* 0x1ce9: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x1d17: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_1d19:
	/* 0x1d19: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d1b:
	/* 0x1d1b: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_1d21:
	/* 0x1d21: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d24:
	/* 0x1d24: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1d29:
	/* 0x1d29: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x1d74: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
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
	/* 0x1d8c: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_1d8e:
	/* 0x1d8e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d94:
	/* 0x1d94: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1d9a:
	/* 0x1d9a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d9d:
	/* 0x1d9d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1da2:
	/* 0x1da2: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x1dd0: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_1dd2:
	/* 0x1dd2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dd4:
	/* 0x1dd4: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_1dda:
	/* 0x1dda: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ddd:
	/* 0x1ddd: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1de2:
	/* 0x1de2: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x1e2d: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
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
	/* 0x1e45: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_1e47:
	/* 0x1e47: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e4d:
	/* 0x1e4d: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1e53:
	/* 0x1e53: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e56:
	/* 0x1e56: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1e5b:
	/* 0x1e5b: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x1e89: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_1e8b:
	/* 0x1e8b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e8d:
	/* 0x1e8d: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_1e93:
	/* 0x1e93: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e96:
	/* 0x1e96: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1e9b:
	/* 0x1e9b: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x1ee6: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
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
	/* 0x1efe: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_1f00:
	/* 0x1f00: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f06:
	/* 0x1f06: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1f0c:
	/* 0x1f0c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f0f:
	/* 0x1f0f: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1f14:
	/* 0x1f14: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x1f42: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_1f44:
	/* 0x1f44: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f46:
	/* 0x1f46: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_1f4c:
	/* 0x1f4c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f4f:
	/* 0x1f4f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1f54:
	/* 0x1f54: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x1f9f: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
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
	/* 0x1fb7: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_1fb9:
	/* 0x1fb9: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1fbf:
	/* 0x1fbf: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_1fc5:
	/* 0x1fc5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fc8:
	/* 0x1fc8: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1fcd:
	/* 0x1fcd: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x1ffb: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_1ffd:
	/* 0x1ffd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fff:
	/* 0x1fff: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_2005:
	/* 0x2005: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2008:
	/* 0x2008: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_200d:
	/* 0x200d: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2058: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
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
	/* 0x2070: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_2072:
	/* 0x2072: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2078:
	/* 0x2078: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_207e:
	/* 0x207e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2081:
	/* 0x2081: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2086:
	/* 0x2086: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x20b4: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_20b6:
	/* 0x20b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20b8:
	/* 0x20b8: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_20be:
	/* 0x20be: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20c1:
	/* 0x20c1: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_20c6:
	/* 0x20c6: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2111: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
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
	/* 0x2129: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_212b:
	/* 0x212b: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2131:
	/* 0x2131: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_2137:
	/* 0x2137: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_213a:
	/* 0x213a: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_213f:
	/* 0x213f: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x216d: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_216f:
	/* 0x216f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2171:
	/* 0x2171: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_2177:
	/* 0x2177: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_217a:
	/* 0x217a: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_217f:
	/* 0x217f: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x21ca: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
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
	/* 0x21e2: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_21e4:
	/* 0x21e4: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_21ea:
	/* 0x21ea: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_21f0:
	/* 0x21f0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21f3:
	/* 0x21f3: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_21f8:
	/* 0x21f8: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2226: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_2228:
	/* 0x2228: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_222a:
	/* 0x222a: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_2230:
	/* 0x2230: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2233:
	/* 0x2233: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2238:
	/* 0x2238: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2283: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
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
	/* 0x229b: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_229d:
	/* 0x229d: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_22a3:
	/* 0x22a3: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_22a9:
	/* 0x22a9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22ac:
	/* 0x22ac: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_22b1:
	/* 0x22b1: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x22df: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_22e1:
	/* 0x22e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22e3:
	/* 0x22e3: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_22e9:
	/* 0x22e9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22ec:
	/* 0x22ec: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
	return 8945ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8945ULL: goto x86_l_22f1;
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
	default: return 0xffffffffffffffffULL;
	}
x86_l_22f1:
	/* 0x22f1: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x233c: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
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
	/* 0x2354: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_2356:
	/* 0x2356: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_235c:
	/* 0x235c: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_2362:
	/* 0x2362: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2365:
	/* 0x2365: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_236a:
	/* 0x236a: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2398: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_239a:
	/* 0x239a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_239c:
	/* 0x239c: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_23a2:
	/* 0x23a2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23a5:
	/* 0x23a5: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_23aa:
	/* 0x23aa: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x23f5: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
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
	/* 0x240d: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_240f:
	/* 0x240f: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2415:
	/* 0x2415: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_241b:
	/* 0x241b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_241e:
	/* 0x241e: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2423:
	/* 0x2423: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2451: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_2453:
	/* 0x2453: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2455:
	/* 0x2455: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_245b:
	/* 0x245b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_245e:
	/* 0x245e: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2463:
	/* 0x2463: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x24ae: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
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
	/* 0x24c6: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_24c8:
	/* 0x24c8: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_24ce:
	/* 0x24ce: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_24d4:
	/* 0x24d4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24d7:
	/* 0x24d7: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_24dc:
	/* 0x24dc: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x250a: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_250c:
	/* 0x250c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_250e:
	/* 0x250e: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_2514:
	/* 0x2514: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2517:
	/* 0x2517: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_251c:
	/* 0x251c: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2567: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
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
	/* 0x257f: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_2581:
	/* 0x2581: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2587:
	/* 0x2587: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_258d:
	/* 0x258d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2590:
	/* 0x2590: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2595:
	/* 0x2595: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x25c3: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_25c5:
	/* 0x25c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25c7:
	/* 0x25c7: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_25cd:
	/* 0x25cd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25d0:
	/* 0x25d0: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_25d5:
	/* 0x25d5: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2620: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
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
	/* 0x2638: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_263a:
	/* 0x263a: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2640:
	/* 0x2640: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_2646:
	/* 0x2646: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2649:
	/* 0x2649: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_264e:
	/* 0x264e: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x267c: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_267e:
	/* 0x267e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2680:
	/* 0x2680: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_2686:
	/* 0x2686: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2689:
	/* 0x2689: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_268e:
	/* 0x268e: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x26d9: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
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
	/* 0x26f1: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_26f3:
	/* 0x26f3: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_26f9:
	/* 0x26f9: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_26ff:
	/* 0x26ff: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2702:
	/* 0x2702: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2707:
	/* 0x2707: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2735: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_2737:
	/* 0x2737: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2739:
	/* 0x2739: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_273f:
	/* 0x273f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2742:
	/* 0x2742: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2747:
	/* 0x2747: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2792: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
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
	/* 0x27aa: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_27ac:
	/* 0x27ac: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_27b2:
	/* 0x27b2: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_27b8:
	/* 0x27b8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27bb:
	/* 0x27bb: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_27c0:
	/* 0x27c0: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x27ee: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_27f0:
	/* 0x27f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27f2:
	/* 0x27f2: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_27f8:
	/* 0x27f8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27fb:
	/* 0x27fb: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2800:
	/* 0x2800: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x284b: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
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
	/* 0x2863: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_2865:
	/* 0x2865: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_286b:
	/* 0x286b: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_2871:
	/* 0x2871: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2874:
	/* 0x2874: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2879:
	/* 0x2879: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x28a7: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_28a9:
	/* 0x28a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28ab:
	/* 0x28ab: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_28b1:
	/* 0x28b1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28b4:
	/* 0x28b4: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_28b9:
	/* 0x28b9: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2904: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
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
	/* 0x291c: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_291e:
	/* 0x291e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2924:
	/* 0x2924: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_292a:
	/* 0x292a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_292d:
	/* 0x292d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2932:
	/* 0x2932: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2960: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_2962:
	/* 0x2962: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2964:
	/* 0x2964: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_296a:
	/* 0x296a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_296d:
	/* 0x296d: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2972:
	/* 0x2972: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x29bd: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
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
	/* 0x29d5: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_29d7:
	/* 0x29d7: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_29dd:
	/* 0x29dd: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_29e3:
	/* 0x29e3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29e6:
	/* 0x29e6: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_29eb:
	/* 0x29eb: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2a19: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_2a1b:
	/* 0x2a1b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a1d:
	/* 0x2a1d: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_2a23:
	/* 0x2a23: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a26:
	/* 0x2a26: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2a2b:
	/* 0x2a2b: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
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
	/* 0x2a76: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
	return 10877ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10877ULL: goto x86_l_2a7d;
	case 10882ULL: goto x86_l_2a82;
	case 10887ULL: goto x86_l_2a87;
	case 10892ULL: goto x86_l_2a8c;
	case 10894ULL: goto x86_l_2a8e;
	case 10896ULL: goto x86_l_2a90;
	case 10902ULL: goto x86_l_2a96;
	case 10908ULL: goto x86_l_2a9c;
	case 10911ULL: goto x86_l_2a9f;
	case 10916ULL: goto x86_l_2aa4;
	case 10922ULL: goto x86_l_2aaa;
	case 10927ULL: goto x86_l_2aaf;
	case 10935ULL: goto x86_l_2ab7;
	case 10939ULL: goto x86_l_2abb;
	case 10946ULL: goto x86_l_2ac2;
	case 10951ULL: goto x86_l_2ac7;
	case 10956ULL: goto x86_l_2acc;
	case 10958ULL: goto x86_l_2ace;
	case 10962ULL: goto x86_l_2ad2;
	case 10964ULL: goto x86_l_2ad4;
	case 10966ULL: goto x86_l_2ad6;
	case 10972ULL: goto x86_l_2adc;
	case 10975ULL: goto x86_l_2adf;
	case 10980ULL: goto x86_l_2ae4;
	case 10986ULL: goto x86_l_2aea;
	case 10991ULL: goto x86_l_2aef;
	case 10999ULL: goto x86_l_2af7;
	case 11003ULL: goto x86_l_2afb;
	case 11010ULL: goto x86_l_2b02;
	case 11015ULL: goto x86_l_2b07;
	case 11020ULL: goto x86_l_2b0c;
	case 11022ULL: goto x86_l_2b0e;
	case 11027ULL: goto x86_l_2b13;
	case 11035ULL: goto x86_l_2b1b;
	case 11038ULL: goto x86_l_2b1e;
	case 11046ULL: goto x86_l_2b26;
	case 11055ULL: goto x86_l_2b2f;
	case 11062ULL: goto x86_l_2b36;
	case 11067ULL: goto x86_l_2b3b;
	case 11072ULL: goto x86_l_2b40;
	case 11077ULL: goto x86_l_2b45;
	case 11080ULL: goto x86_l_2b48;
	case 11082ULL: goto x86_l_2b4a;
	case 11084ULL: goto x86_l_2b4c;
	case 11090ULL: goto x86_l_2b52;
	case 11096ULL: goto x86_l_2b58;
	case 11099ULL: goto x86_l_2b5b;
	case 11104ULL: goto x86_l_2b60;
	case 11110ULL: goto x86_l_2b66;
	case 11115ULL: goto x86_l_2b6b;
	case 11123ULL: goto x86_l_2b73;
	case 11127ULL: goto x86_l_2b77;
	case 11134ULL: goto x86_l_2b7e;
	case 11139ULL: goto x86_l_2b83;
	case 11144ULL: goto x86_l_2b88;
	case 11146ULL: goto x86_l_2b8a;
	case 11150ULL: goto x86_l_2b8e;
	case 11152ULL: goto x86_l_2b90;
	case 11154ULL: goto x86_l_2b92;
	case 11160ULL: goto x86_l_2b98;
	case 11163ULL: goto x86_l_2b9b;
	case 11168ULL: goto x86_l_2ba0;
	case 11174ULL: goto x86_l_2ba6;
	case 11179ULL: goto x86_l_2bab;
	case 11187ULL: goto x86_l_2bb3;
	case 11191ULL: goto x86_l_2bb7;
	case 11198ULL: goto x86_l_2bbe;
	case 11203ULL: goto x86_l_2bc3;
	case 11208ULL: goto x86_l_2bc8;
	case 11210ULL: goto x86_l_2bca;
	case 11215ULL: goto x86_l_2bcf;
	case 11223ULL: goto x86_l_2bd7;
	case 11226ULL: goto x86_l_2bda;
	case 11234ULL: goto x86_l_2be2;
	case 11242ULL: goto x86_l_2bea;
	case 11245ULL: goto x86_l_2bed;
	case 11250ULL: goto x86_l_2bf2;
	case 11252ULL: goto x86_l_2bf4;
	case 11257ULL: goto x86_l_2bf9;
	case 11262ULL: goto x86_l_2bfe;
	case 11270ULL: goto x86_l_2c06;
	case 11274ULL: goto x86_l_2c0a;
	case 11281ULL: goto x86_l_2c11;
	case 11286ULL: goto x86_l_2c16;
	case 11291ULL: goto x86_l_2c1b;
	case 11293ULL: goto x86_l_2c1d;
	case 11297ULL: goto x86_l_2c21;
	case 11299ULL: goto x86_l_2c23;
	case 11301ULL: goto x86_l_2c25;
	case 11307ULL: goto x86_l_2c2b;
	case 11310ULL: goto x86_l_2c2e;
	case 11315ULL: goto x86_l_2c33;
	case 11321ULL: goto x86_l_2c39;
	case 11326ULL: goto x86_l_2c3e;
	case 11334ULL: goto x86_l_2c46;
	case 11338ULL: goto x86_l_2c4a;
	case 11345ULL: goto x86_l_2c51;
	case 11350ULL: goto x86_l_2c56;
	case 11355ULL: goto x86_l_2c5b;
	case 11357ULL: goto x86_l_2c5d;
	case 11362ULL: goto x86_l_2c62;
	case 11370ULL: goto x86_l_2c6a;
	case 11373ULL: goto x86_l_2c6d;
	case 11381ULL: goto x86_l_2c75;
	case 11383ULL: goto x86_l_2c77;
	case 11388ULL: goto x86_l_2c7c;
	case 11393ULL: goto x86_l_2c81;
	case 11401ULL: goto x86_l_2c89;
	case 11405ULL: goto x86_l_2c8d;
	case 11412ULL: goto x86_l_2c94;
	case 11417ULL: goto x86_l_2c99;
	case 11422ULL: goto x86_l_2c9e;
	case 11424ULL: goto x86_l_2ca0;
	case 11429ULL: goto x86_l_2ca5;
	case 11437ULL: goto x86_l_2cad;
	case 11440ULL: goto x86_l_2cb0;
	case 11448ULL: goto x86_l_2cb8;
	case 11457ULL: goto x86_l_2cc1;
	case 11461ULL: goto x86_l_2cc5;
	case 11466ULL: goto x86_l_2cca;
	case 11471ULL: goto x86_l_2ccf;
	case 11476ULL: goto x86_l_2cd4;
	case 11478ULL: goto x86_l_2cd6;
	case 11480ULL: goto x86_l_2cd8;
	case 11486ULL: goto x86_l_2cde;
	case 11492ULL: goto x86_l_2ce4;
	case 11495ULL: goto x86_l_2ce7;
	case 11500ULL: goto x86_l_2cec;
	case 11506ULL: goto x86_l_2cf2;
	case 11511ULL: goto x86_l_2cf7;
	case 11519ULL: goto x86_l_2cff;
	case 11523ULL: goto x86_l_2d03;
	case 11530ULL: goto x86_l_2d0a;
	case 11535ULL: goto x86_l_2d0f;
	case 11540ULL: goto x86_l_2d14;
	case 11542ULL: goto x86_l_2d16;
	case 11546ULL: goto x86_l_2d1a;
	case 11548ULL: goto x86_l_2d1c;
	case 11550ULL: goto x86_l_2d1e;
	case 11556ULL: goto x86_l_2d24;
	case 11559ULL: goto x86_l_2d27;
	case 11564ULL: goto x86_l_2d2c;
	case 11570ULL: goto x86_l_2d32;
	case 11575ULL: goto x86_l_2d37;
	case 11583ULL: goto x86_l_2d3f;
	case 11587ULL: goto x86_l_2d43;
	case 11594ULL: goto x86_l_2d4a;
	case 11599ULL: goto x86_l_2d4f;
	case 11604ULL: goto x86_l_2d54;
	case 11606ULL: goto x86_l_2d56;
	case 11611ULL: goto x86_l_2d5b;
	case 11619ULL: goto x86_l_2d63;
	case 11622ULL: goto x86_l_2d66;
	case 11630ULL: goto x86_l_2d6e;
	case 11639ULL: goto x86_l_2d77;
	case 11643ULL: goto x86_l_2d7b;
	case 11648ULL: goto x86_l_2d80;
	case 11653ULL: goto x86_l_2d85;
	case 11658ULL: goto x86_l_2d8a;
	case 11660ULL: goto x86_l_2d8c;
	case 11662ULL: goto x86_l_2d8e;
	case 11668ULL: goto x86_l_2d94;
	case 11674ULL: goto x86_l_2d9a;
	case 11677ULL: goto x86_l_2d9d;
	case 11682ULL: goto x86_l_2da2;
	case 11688ULL: goto x86_l_2da8;
	case 11693ULL: goto x86_l_2dad;
	case 11701ULL: goto x86_l_2db5;
	case 11705ULL: goto x86_l_2db9;
	case 11712ULL: goto x86_l_2dc0;
	case 11717ULL: goto x86_l_2dc5;
	case 11722ULL: goto x86_l_2dca;
	case 11724ULL: goto x86_l_2dcc;
	case 11728ULL: goto x86_l_2dd0;
	case 11730ULL: goto x86_l_2dd2;
	case 11732ULL: goto x86_l_2dd4;
	case 11738ULL: goto x86_l_2dda;
	case 11741ULL: goto x86_l_2ddd;
	case 11746ULL: goto x86_l_2de2;
	case 11752ULL: goto x86_l_2de8;
	case 11757ULL: goto x86_l_2ded;
	case 11765ULL: goto x86_l_2df5;
	case 11769ULL: goto x86_l_2df9;
	case 11776ULL: goto x86_l_2e00;
	case 11781ULL: goto x86_l_2e05;
	case 11786ULL: goto x86_l_2e0a;
	case 11788ULL: goto x86_l_2e0c;
	case 11793ULL: goto x86_l_2e11;
	case 11801ULL: goto x86_l_2e19;
	case 11804ULL: goto x86_l_2e1c;
	case 11812ULL: goto x86_l_2e24;
	case 11821ULL: goto x86_l_2e2d;
	case 11825ULL: goto x86_l_2e31;
	case 11830ULL: goto x86_l_2e36;
	case 11835ULL: goto x86_l_2e3b;
	case 11840ULL: goto x86_l_2e40;
	case 11842ULL: goto x86_l_2e42;
	case 11844ULL: goto x86_l_2e44;
	case 11850ULL: goto x86_l_2e4a;
	case 11856ULL: goto x86_l_2e50;
	case 11859ULL: goto x86_l_2e53;
	case 11864ULL: goto x86_l_2e58;
	case 11870ULL: goto x86_l_2e5e;
	case 11875ULL: goto x86_l_2e63;
	case 11883ULL: goto x86_l_2e6b;
	case 11887ULL: goto x86_l_2e6f;
	case 11894ULL: goto x86_l_2e76;
	case 11899ULL: goto x86_l_2e7b;
	case 11904ULL: goto x86_l_2e80;
	case 11906ULL: goto x86_l_2e82;
	case 11910ULL: goto x86_l_2e86;
	case 11912ULL: goto x86_l_2e88;
	case 11914ULL: goto x86_l_2e8a;
	case 11920ULL: goto x86_l_2e90;
	case 11923ULL: goto x86_l_2e93;
	case 11928ULL: goto x86_l_2e98;
	case 11934ULL: goto x86_l_2e9e;
	case 11939ULL: goto x86_l_2ea3;
	case 11947ULL: goto x86_l_2eab;
	case 11951ULL: goto x86_l_2eaf;
	case 11958ULL: goto x86_l_2eb6;
	case 11963ULL: goto x86_l_2ebb;
	case 11968ULL: goto x86_l_2ec0;
	case 11970ULL: goto x86_l_2ec2;
	case 11975ULL: goto x86_l_2ec7;
	case 11983ULL: goto x86_l_2ecf;
	case 11986ULL: goto x86_l_2ed2;
	case 11994ULL: goto x86_l_2eda;
	case 12003ULL: goto x86_l_2ee3;
	case 12007ULL: goto x86_l_2ee7;
	case 12012ULL: goto x86_l_2eec;
	case 12017ULL: goto x86_l_2ef1;
	case 12022ULL: goto x86_l_2ef6;
	case 12024ULL: goto x86_l_2ef8;
	case 12026ULL: goto x86_l_2efa;
	case 12032ULL: goto x86_l_2f00;
	case 12038ULL: goto x86_l_2f06;
	case 12041ULL: goto x86_l_2f09;
	case 12046ULL: goto x86_l_2f0e;
	case 12052ULL: goto x86_l_2f14;
	case 12057ULL: goto x86_l_2f19;
	case 12065ULL: goto x86_l_2f21;
	case 12069ULL: goto x86_l_2f25;
	case 12076ULL: goto x86_l_2f2c;
	case 12081ULL: goto x86_l_2f31;
	case 12086ULL: goto x86_l_2f36;
	case 12088ULL: goto x86_l_2f38;
	case 12092ULL: goto x86_l_2f3c;
	case 12094ULL: goto x86_l_2f3e;
	case 12096ULL: goto x86_l_2f40;
	case 12102ULL: goto x86_l_2f46;
	case 12105ULL: goto x86_l_2f49;
	case 12110ULL: goto x86_l_2f4e;
	case 12116ULL: goto x86_l_2f54;
	case 12121ULL: goto x86_l_2f59;
	case 12129ULL: goto x86_l_2f61;
	case 12133ULL: goto x86_l_2f65;
	case 12140ULL: goto x86_l_2f6c;
	case 12145ULL: goto x86_l_2f71;
	case 12150ULL: goto x86_l_2f76;
	case 12152ULL: goto x86_l_2f78;
	case 12157ULL: goto x86_l_2f7d;
	case 12165ULL: goto x86_l_2f85;
	case 12168ULL: goto x86_l_2f88;
	case 12176ULL: goto x86_l_2f90;
	case 12185ULL: goto x86_l_2f99;
	case 12189ULL: goto x86_l_2f9d;
	case 12194ULL: goto x86_l_2fa2;
	case 12199ULL: goto x86_l_2fa7;
	case 12204ULL: goto x86_l_2fac;
	case 12206ULL: goto x86_l_2fae;
	case 12208ULL: goto x86_l_2fb0;
	case 12214ULL: goto x86_l_2fb6;
	case 12220ULL: goto x86_l_2fbc;
	case 12223ULL: goto x86_l_2fbf;
	case 12228ULL: goto x86_l_2fc4;
	case 12234ULL: goto x86_l_2fca;
	case 12239ULL: goto x86_l_2fcf;
	case 12247ULL: goto x86_l_2fd7;
	case 12251ULL: goto x86_l_2fdb;
	case 12258ULL: goto x86_l_2fe2;
	case 12263ULL: goto x86_l_2fe7;
	case 12268ULL: goto x86_l_2fec;
	case 12270ULL: goto x86_l_2fee;
	case 12274ULL: goto x86_l_2ff2;
	case 12276ULL: goto x86_l_2ff4;
	case 12278ULL: goto x86_l_2ff6;
	case 12284ULL: goto x86_l_2ffc;
	case 12287ULL: goto x86_l_2fff;
	case 12292ULL: goto x86_l_3004;
	case 12298ULL: goto x86_l_300a;
	case 12303ULL: goto x86_l_300f;
	case 12311ULL: goto x86_l_3017;
	case 12315ULL: goto x86_l_301b;
	case 12322ULL: goto x86_l_3022;
	case 12327ULL: goto x86_l_3027;
	case 12332ULL: goto x86_l_302c;
	case 12334ULL: goto x86_l_302e;
	case 12339ULL: goto x86_l_3033;
	case 12347ULL: goto x86_l_303b;
	case 12350ULL: goto x86_l_303e;
	case 12358ULL: goto x86_l_3046;
	case 12367ULL: goto x86_l_304f;
	case 12371ULL: goto x86_l_3053;
	case 12376ULL: goto x86_l_3058;
	case 12381ULL: goto x86_l_305d;
	case 12386ULL: goto x86_l_3062;
	case 12388ULL: goto x86_l_3064;
	case 12390ULL: goto x86_l_3066;
	case 12396ULL: goto x86_l_306c;
	case 12402ULL: goto x86_l_3072;
	case 12405ULL: goto x86_l_3075;
	case 12410ULL: goto x86_l_307a;
	case 12416ULL: goto x86_l_3080;
	case 12421ULL: goto x86_l_3085;
	case 12429ULL: goto x86_l_308d;
	case 12433ULL: goto x86_l_3091;
	case 12440ULL: goto x86_l_3098;
	case 12445ULL: goto x86_l_309d;
	case 12450ULL: goto x86_l_30a2;
	case 12452ULL: goto x86_l_30a4;
	case 12456ULL: goto x86_l_30a8;
	case 12458ULL: goto x86_l_30aa;
	case 12460ULL: goto x86_l_30ac;
	case 12466ULL: goto x86_l_30b2;
	case 12469ULL: goto x86_l_30b5;
	case 12474ULL: goto x86_l_30ba;
	case 12480ULL: goto x86_l_30c0;
	case 12485ULL: goto x86_l_30c5;
	case 12493ULL: goto x86_l_30cd;
	case 12497ULL: goto x86_l_30d1;
	case 12504ULL: goto x86_l_30d8;
	case 12509ULL: goto x86_l_30dd;
	case 12514ULL: goto x86_l_30e2;
	case 12516ULL: goto x86_l_30e4;
	case 12521ULL: goto x86_l_30e9;
	case 12529ULL: goto x86_l_30f1;
	case 12532ULL: goto x86_l_30f4;
	case 12540ULL: goto x86_l_30fc;
	case 12549ULL: goto x86_l_3105;
	case 12553ULL: goto x86_l_3109;
	case 12558ULL: goto x86_l_310e;
	case 12563ULL: goto x86_l_3113;
	case 12568ULL: goto x86_l_3118;
	case 12570ULL: goto x86_l_311a;
	case 12572ULL: goto x86_l_311c;
	case 12578ULL: goto x86_l_3122;
	case 12584ULL: goto x86_l_3128;
	case 12587ULL: goto x86_l_312b;
	case 12592ULL: goto x86_l_3130;
	case 12598ULL: goto x86_l_3136;
	case 12603ULL: goto x86_l_313b;
	case 12611ULL: goto x86_l_3143;
	case 12615ULL: goto x86_l_3147;
	case 12622ULL: goto x86_l_314e;
	case 12627ULL: goto x86_l_3153;
	case 12632ULL: goto x86_l_3158;
	case 12634ULL: goto x86_l_315a;
	case 12638ULL: goto x86_l_315e;
	case 12640ULL: goto x86_l_3160;
	case 12642ULL: goto x86_l_3162;
	case 12648ULL: goto x86_l_3168;
	case 12651ULL: goto x86_l_316b;
	case 12656ULL: goto x86_l_3170;
	case 12662ULL: goto x86_l_3176;
	case 12667ULL: goto x86_l_317b;
	case 12675ULL: goto x86_l_3183;
	case 12679ULL: goto x86_l_3187;
	case 12686ULL: goto x86_l_318e;
	case 12691ULL: goto x86_l_3193;
	case 12696ULL: goto x86_l_3198;
	case 12698ULL: goto x86_l_319a;
	case 12703ULL: goto x86_l_319f;
	case 12711ULL: goto x86_l_31a7;
	case 12714ULL: goto x86_l_31aa;
	case 12722ULL: goto x86_l_31b2;
	case 12731ULL: goto x86_l_31bb;
	case 12735ULL: goto x86_l_31bf;
	case 12740ULL: goto x86_l_31c4;
	case 12745ULL: goto x86_l_31c9;
	case 12750ULL: goto x86_l_31ce;
	case 12752ULL: goto x86_l_31d0;
	case 12754ULL: goto x86_l_31d2;
	case 12760ULL: goto x86_l_31d8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a7d:
	/* 0x2a7d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a82:
	/* 0x2a82: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a87:
	/* 0x2a87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a8c:
	/* 0x2a8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a8e:
	/* 0x2a8e: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_2a90:
	/* 0x2a90: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2a96:
	/* 0x2a96: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_2a9c:
	/* 0x2a9c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a9f:
	/* 0x2a9f: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2aa4:
	/* 0x2aa4: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_2aaa:
	/* 0x2aaa: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2aaf:
	/* 0x2aaf: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ab7:
	/* 0x2ab7: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2abb:
	/* 0x2abb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2ac2:
	/* 0x2ac2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ac7:
	/* 0x2ac7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2acc:
	/* 0x2acc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ace:
	/* 0x2ace: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2ad2:
	/* 0x2ad2: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_2ad4:
	/* 0x2ad4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ad6:
	/* 0x2ad6: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_2adc:
	/* 0x2adc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2adf:
	/* 0x2adf: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2ae4:
	/* 0x2ae4: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_2aea:
	/* 0x2aea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2aef:
	/* 0x2aef: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2af7:
	/* 0x2af7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2afb:
	/* 0x2afb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b02:
	/* 0x2b02: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2b07:
	/* 0x2b07: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b0c:
	/* 0x2b0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b0e:
	/* 0x2b0e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2b13:
	/* 0x2b13: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2b1b:
	/* 0x2b1b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2b1e:
	/* 0x2b1e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2b26:
	/* 0x2b26: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2b2f:
	/* 0x2b2f: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_2b36:
	/* 0x2b36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b3b:
	/* 0x2b3b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b40:
	/* 0x2b40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b45:
	/* 0x2b45: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b48:
	/* 0x2b48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4a:
	/* 0x2b4a: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_2b4c:
	/* 0x2b4c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2b52:
	/* 0x2b52: je     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3124ULL;
	}
x86_l_2b58:
	/* 0x2b58: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b5b:
	/* 0x2b5b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2b60:
	/* 0x2b60: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_2b66:
	/* 0x2b66: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2b6b:
	/* 0x2b6b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b73:
	/* 0x2b73: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2b77:
	/* 0x2b77: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2b7e:
	/* 0x2b7e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b83:
	/* 0x2b83: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2b88:
	/* 0x2b88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b8a:
	/* 0x2b8a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2b8e:
	/* 0x2b8e: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_2b90:
	/* 0x2b90: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b92:
	/* 0x2b92: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_2b98:
	/* 0x2b98: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b9b:
	/* 0x2b9b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2ba0:
	/* 0x2ba0: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_2ba6:
	/* 0x2ba6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bab:
	/* 0x2bab: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2bb3:
	/* 0x2bb3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2bb7:
	/* 0x2bb7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2bbe:
	/* 0x2bbe: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2bc3:
	/* 0x2bc3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2bc8:
	/* 0x2bc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bca:
	/* 0x2bca: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2bcf:
	/* 0x2bcf: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2bd7:
	/* 0x2bd7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2bda:
	/* 0x2bda: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2be2:
	/* 0x2be2: mov    DWORD PTR [rsp+0x10],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68722503214ULL);
x86_l_2bea:
	/* 0x2bea: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2bed:
	/* 0x2bed: cmp    eax,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27901ULL);
x86_l_2bf2:
	/* 0x2bf2: jb     2bf9 <syscall__execveat_enter+0x2bf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2bf9;
	}
x86_l_2bf4:
	/* 0x2bf4: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_2bf9:
	/* 0x2bf9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2bfe:
	/* 0x2bfe: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c06:
	/* 0x2c06: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2c0a:
	/* 0x2c0a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2c11:
	/* 0x2c11: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c16:
	/* 0x2c16: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2c1b:
	/* 0x2c1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1d:
	/* 0x2c1d: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2c21:
	/* 0x2c21: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_2c23:
	/* 0x2c23: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c25:
	/* 0x2c25: jle    c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3124ULL;
	}
x86_l_2c2b:
	/* 0x2c2b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c2e:
	/* 0x2c2e: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2c33:
	/* 0x2c33: ja     c34 <syscall__execveat_enter+0xc34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3124ULL;
	}
x86_l_2c39:
	/* 0x2c39: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c3e:
	/* 0x2c3e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c46:
	/* 0x2c46: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2c4a:
	/* 0x2c4a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2c51:
	/* 0x2c51: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2c56:
	/* 0x2c56: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c5b:
	/* 0x2c5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c5d:
	/* 0x2c5d: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2c62:
	/* 0x2c62: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2c6a:
	/* 0x2c6a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2c6d:
	/* 0x2c6d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c75:
	/* 0x2c75: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_2c77:
	/* 0x2c77: jmp    c34 <syscall__execveat_enter+0xc34> */
	return 3124ULL;
x86_l_2c7c:
	/* 0x2c7c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c81:
	/* 0x2c81: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c89:
	/* 0x2c89: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2c8d:
	/* 0x2c8d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2c94:
	/* 0x2c94: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2c99:
	/* 0x2c99: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c9e:
	/* 0x2c9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ca0:
	/* 0x2ca0: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2ca5:
	/* 0x2ca5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2cad:
	/* 0x2cad: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2cb0:
	/* 0x2cb0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2cb8:
	/* 0x2cb8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2cc1:
	/* 0x2cc1: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cc5:
	/* 0x2cc5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cca:
	/* 0x2cca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ccf:
	/* 0x2ccf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cd4:
	/* 0x2cd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cd6:
	/* 0x2cd6: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_2cd8:
	/* 0x2cd8: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2cde:
	/* 0x2cde: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_2ce4:
	/* 0x2ce4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ce7:
	/* 0x2ce7: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2cec:
	/* 0x2cec: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_2cf2:
	/* 0x2cf2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2cf7:
	/* 0x2cf7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2cff:
	/* 0x2cff: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2d03:
	/* 0x2d03: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2d0a:
	/* 0x2d0a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d0f:
	/* 0x2d0f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d14:
	/* 0x2d14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d16:
	/* 0x2d16: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2d1a:
	/* 0x2d1a: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_2d1c:
	/* 0x2d1c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d1e:
	/* 0x2d1e: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_2d24:
	/* 0x2d24: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d27:
	/* 0x2d27: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2d2c:
	/* 0x2d2c: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_2d32:
	/* 0x2d32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d37:
	/* 0x2d37: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d3f:
	/* 0x2d3f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2d43:
	/* 0x2d43: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2d4a:
	/* 0x2d4a: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2d4f:
	/* 0x2d4f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d54:
	/* 0x2d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d56:
	/* 0x2d56: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2d5b:
	/* 0x2d5b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2d63:
	/* 0x2d63: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2d66:
	/* 0x2d66: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2d6e:
	/* 0x2d6e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d77:
	/* 0x2d77: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d7b:
	/* 0x2d7b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d80:
	/* 0x2d80: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d85:
	/* 0x2d85: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d8a:
	/* 0x2d8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d8c:
	/* 0x2d8c: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_2d8e:
	/* 0x2d8e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d94:
	/* 0x2d94: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_2d9a:
	/* 0x2d9a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d9d:
	/* 0x2d9d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2da2:
	/* 0x2da2: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_2da8:
	/* 0x2da8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2dad:
	/* 0x2dad: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2db5:
	/* 0x2db5: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2db9:
	/* 0x2db9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2dc0:
	/* 0x2dc0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dc5:
	/* 0x2dc5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2dca:
	/* 0x2dca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dcc:
	/* 0x2dcc: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2dd0:
	/* 0x2dd0: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_2dd2:
	/* 0x2dd2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dd4:
	/* 0x2dd4: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_2dda:
	/* 0x2dda: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ddd:
	/* 0x2ddd: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2de2:
	/* 0x2de2: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_2de8:
	/* 0x2de8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ded:
	/* 0x2ded: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2df5:
	/* 0x2df5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2df9:
	/* 0x2df9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2e00:
	/* 0x2e00: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e05:
	/* 0x2e05: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e0a:
	/* 0x2e0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e0c:
	/* 0x2e0c: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2e11:
	/* 0x2e11: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2e19:
	/* 0x2e19: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2e1c:
	/* 0x2e1c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2e24:
	/* 0x2e24: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2e2d:
	/* 0x2e2d: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e31:
	/* 0x2e31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e36:
	/* 0x2e36: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e3b:
	/* 0x2e3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e40:
	/* 0x2e40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e42:
	/* 0x2e42: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_2e44:
	/* 0x2e44: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2e4a:
	/* 0x2e4a: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_2e50:
	/* 0x2e50: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e53:
	/* 0x2e53: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2e58:
	/* 0x2e58: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_2e5e:
	/* 0x2e5e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2e63:
	/* 0x2e63: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e6b:
	/* 0x2e6b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2e6f:
	/* 0x2e6f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2e76:
	/* 0x2e76: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e7b:
	/* 0x2e7b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2e80:
	/* 0x2e80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e82:
	/* 0x2e82: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e86:
	/* 0x2e86: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_2e88:
	/* 0x2e88: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e8a:
	/* 0x2e8a: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_2e90:
	/* 0x2e90: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e93:
	/* 0x2e93: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2e98:
	/* 0x2e98: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_2e9e:
	/* 0x2e9e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ea3:
	/* 0x2ea3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2eab:
	/* 0x2eab: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2eaf:
	/* 0x2eaf: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2eb6:
	/* 0x2eb6: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2ebb:
	/* 0x2ebb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ec0:
	/* 0x2ec0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec2:
	/* 0x2ec2: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2ec7:
	/* 0x2ec7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2ecf:
	/* 0x2ecf: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2ed2:
	/* 0x2ed2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2eda:
	/* 0x2eda: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ee3:
	/* 0x2ee3: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ee7:
	/* 0x2ee7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2eec:
	/* 0x2eec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ef1:
	/* 0x2ef1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ef6:
	/* 0x2ef6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef8:
	/* 0x2ef8: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_2efa:
	/* 0x2efa: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f00:
	/* 0x2f00: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_2f06:
	/* 0x2f06: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f09:
	/* 0x2f09: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2f0e:
	/* 0x2f0e: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_2f14:
	/* 0x2f14: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2f19:
	/* 0x2f19: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f21:
	/* 0x2f21: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2f25:
	/* 0x2f25: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2f2c:
	/* 0x2f2c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f31:
	/* 0x2f31: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f36:
	/* 0x2f36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f38:
	/* 0x2f38: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2f3c:
	/* 0x2f3c: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_2f3e:
	/* 0x2f3e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f40:
	/* 0x2f40: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_2f46:
	/* 0x2f46: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f49:
	/* 0x2f49: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2f4e:
	/* 0x2f4e: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_2f54:
	/* 0x2f54: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f59:
	/* 0x2f59: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f61:
	/* 0x2f61: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2f65:
	/* 0x2f65: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2f6c:
	/* 0x2f6c: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2f71:
	/* 0x2f71: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f76:
	/* 0x2f76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f78:
	/* 0x2f78: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2f7d:
	/* 0x2f7d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2f85:
	/* 0x2f85: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2f88:
	/* 0x2f88: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2f90:
	/* 0x2f90: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f99:
	/* 0x2f99: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f9d:
	/* 0x2f9d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fa2:
	/* 0x2fa2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fa7:
	/* 0x2fa7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fac:
	/* 0x2fac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fae:
	/* 0x2fae: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_2fb0:
	/* 0x2fb0: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2fb6:
	/* 0x2fb6: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_2fbc:
	/* 0x2fbc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fbf:
	/* 0x2fbf: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2fc4:
	/* 0x2fc4: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_2fca:
	/* 0x2fca: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2fcf:
	/* 0x2fcf: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2fd7:
	/* 0x2fd7: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2fdb:
	/* 0x2fdb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2fe2:
	/* 0x2fe2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fe7:
	/* 0x2fe7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2fec:
	/* 0x2fec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fee:
	/* 0x2fee: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2ff2:
	/* 0x2ff2: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_2ff4:
	/* 0x2ff4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ff6:
	/* 0x2ff6: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_2ffc:
	/* 0x2ffc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fff:
	/* 0x2fff: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3004:
	/* 0x3004: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_300a:
	/* 0x300a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_300f:
	/* 0x300f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3017:
	/* 0x3017: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_301b:
	/* 0x301b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3022:
	/* 0x3022: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3027:
	/* 0x3027: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_302c:
	/* 0x302c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_302e:
	/* 0x302e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3033:
	/* 0x3033: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_303b:
	/* 0x303b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_303e:
	/* 0x303e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3046:
	/* 0x3046: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_304f:
	/* 0x304f: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3053:
	/* 0x3053: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3058:
	/* 0x3058: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_305d:
	/* 0x305d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3062:
	/* 0x3062: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3064:
	/* 0x3064: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_3066:
	/* 0x3066: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_306c:
	/* 0x306c: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3072:
	/* 0x3072: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3075:
	/* 0x3075: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_307a:
	/* 0x307a: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3080:
	/* 0x3080: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3085:
	/* 0x3085: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_308d:
	/* 0x308d: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3091:
	/* 0x3091: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3098:
	/* 0x3098: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_309d:
	/* 0x309d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_30a2:
	/* 0x30a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30a4:
	/* 0x30a4: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_30a8:
	/* 0x30a8: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_30aa:
	/* 0x30aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30ac:
	/* 0x30ac: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_30b2:
	/* 0x30b2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30b5:
	/* 0x30b5: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_30ba:
	/* 0x30ba: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_30c0:
	/* 0x30c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30c5:
	/* 0x30c5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_30cd:
	/* 0x30cd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_30d1:
	/* 0x30d1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_30d8:
	/* 0x30d8: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_30dd:
	/* 0x30dd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_30e2:
	/* 0x30e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30e4:
	/* 0x30e4: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_30e9:
	/* 0x30e9: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_30f1:
	/* 0x30f1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_30f4:
	/* 0x30f4: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_30fc:
	/* 0x30fc: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3105:
	/* 0x3105: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3109:
	/* 0x3109: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_310e:
	/* 0x310e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3113:
	/* 0x3113: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3118:
	/* 0x3118: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_311a:
	/* 0x311a: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_311c:
	/* 0x311c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3122:
	/* 0x3122: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3128:
	/* 0x3128: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_312b:
	/* 0x312b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3130:
	/* 0x3130: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3136:
	/* 0x3136: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_313b:
	/* 0x313b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3143:
	/* 0x3143: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3147:
	/* 0x3147: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_314e:
	/* 0x314e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3153:
	/* 0x3153: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3158:
	/* 0x3158: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_315a:
	/* 0x315a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_315e:
	/* 0x315e: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_3160:
	/* 0x3160: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3162:
	/* 0x3162: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_3168:
	/* 0x3168: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_316b:
	/* 0x316b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3170:
	/* 0x3170: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3176:
	/* 0x3176: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_317b:
	/* 0x317b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3183:
	/* 0x3183: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3187:
	/* 0x3187: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_318e:
	/* 0x318e: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3193:
	/* 0x3193: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3198:
	/* 0x3198: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_319a:
	/* 0x319a: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_319f:
	/* 0x319f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_31a7:
	/* 0x31a7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_31aa:
	/* 0x31aa: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_31b2:
	/* 0x31b2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_31bb:
	/* 0x31bb: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_31bf:
	/* 0x31bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31c4:
	/* 0x31c4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31c9:
	/* 0x31c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31ce:
	/* 0x31ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d0:
	/* 0x31d0: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_31d2:
	/* 0x31d2: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_31d8:
	/* 0x31d8: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
	return 12766ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12766ULL: goto x86_l_31de;
	case 12769ULL: goto x86_l_31e1;
	case 12774ULL: goto x86_l_31e6;
	case 12780ULL: goto x86_l_31ec;
	case 12785ULL: goto x86_l_31f1;
	case 12793ULL: goto x86_l_31f9;
	case 12797ULL: goto x86_l_31fd;
	case 12804ULL: goto x86_l_3204;
	case 12809ULL: goto x86_l_3209;
	case 12814ULL: goto x86_l_320e;
	case 12816ULL: goto x86_l_3210;
	case 12820ULL: goto x86_l_3214;
	case 12822ULL: goto x86_l_3216;
	case 12824ULL: goto x86_l_3218;
	case 12830ULL: goto x86_l_321e;
	case 12833ULL: goto x86_l_3221;
	case 12838ULL: goto x86_l_3226;
	case 12844ULL: goto x86_l_322c;
	case 12849ULL: goto x86_l_3231;
	case 12857ULL: goto x86_l_3239;
	case 12861ULL: goto x86_l_323d;
	case 12868ULL: goto x86_l_3244;
	case 12873ULL: goto x86_l_3249;
	case 12878ULL: goto x86_l_324e;
	case 12880ULL: goto x86_l_3250;
	case 12885ULL: goto x86_l_3255;
	case 12893ULL: goto x86_l_325d;
	case 12896ULL: goto x86_l_3260;
	case 12904ULL: goto x86_l_3268;
	case 12913ULL: goto x86_l_3271;
	case 12917ULL: goto x86_l_3275;
	case 12922ULL: goto x86_l_327a;
	case 12927ULL: goto x86_l_327f;
	case 12932ULL: goto x86_l_3284;
	case 12934ULL: goto x86_l_3286;
	case 12936ULL: goto x86_l_3288;
	case 12942ULL: goto x86_l_328e;
	case 12948ULL: goto x86_l_3294;
	case 12951ULL: goto x86_l_3297;
	case 12956ULL: goto x86_l_329c;
	case 12962ULL: goto x86_l_32a2;
	case 12967ULL: goto x86_l_32a7;
	case 12975ULL: goto x86_l_32af;
	case 12979ULL: goto x86_l_32b3;
	case 12986ULL: goto x86_l_32ba;
	case 12991ULL: goto x86_l_32bf;
	case 12996ULL: goto x86_l_32c4;
	case 12998ULL: goto x86_l_32c6;
	case 13002ULL: goto x86_l_32ca;
	case 13004ULL: goto x86_l_32cc;
	case 13006ULL: goto x86_l_32ce;
	case 13012ULL: goto x86_l_32d4;
	case 13015ULL: goto x86_l_32d7;
	case 13020ULL: goto x86_l_32dc;
	case 13026ULL: goto x86_l_32e2;
	case 13031ULL: goto x86_l_32e7;
	case 13039ULL: goto x86_l_32ef;
	case 13043ULL: goto x86_l_32f3;
	case 13050ULL: goto x86_l_32fa;
	case 13055ULL: goto x86_l_32ff;
	case 13060ULL: goto x86_l_3304;
	case 13062ULL: goto x86_l_3306;
	case 13067ULL: goto x86_l_330b;
	case 13075ULL: goto x86_l_3313;
	case 13078ULL: goto x86_l_3316;
	case 13086ULL: goto x86_l_331e;
	case 13095ULL: goto x86_l_3327;
	case 13099ULL: goto x86_l_332b;
	case 13104ULL: goto x86_l_3330;
	case 13109ULL: goto x86_l_3335;
	case 13114ULL: goto x86_l_333a;
	case 13116ULL: goto x86_l_333c;
	case 13118ULL: goto x86_l_333e;
	case 13124ULL: goto x86_l_3344;
	case 13130ULL: goto x86_l_334a;
	case 13133ULL: goto x86_l_334d;
	case 13138ULL: goto x86_l_3352;
	case 13144ULL: goto x86_l_3358;
	case 13149ULL: goto x86_l_335d;
	case 13157ULL: goto x86_l_3365;
	case 13161ULL: goto x86_l_3369;
	case 13168ULL: goto x86_l_3370;
	case 13173ULL: goto x86_l_3375;
	case 13178ULL: goto x86_l_337a;
	case 13180ULL: goto x86_l_337c;
	case 13184ULL: goto x86_l_3380;
	case 13186ULL: goto x86_l_3382;
	case 13188ULL: goto x86_l_3384;
	case 13194ULL: goto x86_l_338a;
	case 13197ULL: goto x86_l_338d;
	case 13202ULL: goto x86_l_3392;
	case 13208ULL: goto x86_l_3398;
	case 13213ULL: goto x86_l_339d;
	case 13221ULL: goto x86_l_33a5;
	case 13225ULL: goto x86_l_33a9;
	case 13232ULL: goto x86_l_33b0;
	case 13237ULL: goto x86_l_33b5;
	case 13242ULL: goto x86_l_33ba;
	case 13244ULL: goto x86_l_33bc;
	case 13249ULL: goto x86_l_33c1;
	case 13257ULL: goto x86_l_33c9;
	case 13260ULL: goto x86_l_33cc;
	case 13268ULL: goto x86_l_33d4;
	case 13277ULL: goto x86_l_33dd;
	case 13281ULL: goto x86_l_33e1;
	case 13286ULL: goto x86_l_33e6;
	case 13291ULL: goto x86_l_33eb;
	case 13296ULL: goto x86_l_33f0;
	case 13298ULL: goto x86_l_33f2;
	case 13300ULL: goto x86_l_33f4;
	case 13306ULL: goto x86_l_33fa;
	case 13312ULL: goto x86_l_3400;
	case 13315ULL: goto x86_l_3403;
	case 13320ULL: goto x86_l_3408;
	case 13326ULL: goto x86_l_340e;
	case 13331ULL: goto x86_l_3413;
	case 13339ULL: goto x86_l_341b;
	case 13343ULL: goto x86_l_341f;
	case 13350ULL: goto x86_l_3426;
	case 13355ULL: goto x86_l_342b;
	case 13360ULL: goto x86_l_3430;
	case 13362ULL: goto x86_l_3432;
	case 13366ULL: goto x86_l_3436;
	case 13368ULL: goto x86_l_3438;
	case 13370ULL: goto x86_l_343a;
	case 13376ULL: goto x86_l_3440;
	case 13379ULL: goto x86_l_3443;
	case 13384ULL: goto x86_l_3448;
	case 13390ULL: goto x86_l_344e;
	case 13395ULL: goto x86_l_3453;
	case 13403ULL: goto x86_l_345b;
	case 13407ULL: goto x86_l_345f;
	case 13414ULL: goto x86_l_3466;
	case 13419ULL: goto x86_l_346b;
	case 13424ULL: goto x86_l_3470;
	case 13426ULL: goto x86_l_3472;
	case 13431ULL: goto x86_l_3477;
	case 13439ULL: goto x86_l_347f;
	case 13442ULL: goto x86_l_3482;
	case 13450ULL: goto x86_l_348a;
	case 13459ULL: goto x86_l_3493;
	case 13463ULL: goto x86_l_3497;
	case 13468ULL: goto x86_l_349c;
	case 13473ULL: goto x86_l_34a1;
	case 13478ULL: goto x86_l_34a6;
	case 13480ULL: goto x86_l_34a8;
	case 13482ULL: goto x86_l_34aa;
	case 13488ULL: goto x86_l_34b0;
	case 13494ULL: goto x86_l_34b6;
	case 13497ULL: goto x86_l_34b9;
	case 13502ULL: goto x86_l_34be;
	case 13508ULL: goto x86_l_34c4;
	case 13513ULL: goto x86_l_34c9;
	case 13521ULL: goto x86_l_34d1;
	case 13525ULL: goto x86_l_34d5;
	case 13532ULL: goto x86_l_34dc;
	case 13537ULL: goto x86_l_34e1;
	case 13542ULL: goto x86_l_34e6;
	case 13544ULL: goto x86_l_34e8;
	case 13548ULL: goto x86_l_34ec;
	case 13550ULL: goto x86_l_34ee;
	case 13552ULL: goto x86_l_34f0;
	case 13558ULL: goto x86_l_34f6;
	case 13561ULL: goto x86_l_34f9;
	case 13566ULL: goto x86_l_34fe;
	case 13572ULL: goto x86_l_3504;
	case 13577ULL: goto x86_l_3509;
	case 13585ULL: goto x86_l_3511;
	case 13589ULL: goto x86_l_3515;
	case 13596ULL: goto x86_l_351c;
	case 13601ULL: goto x86_l_3521;
	case 13606ULL: goto x86_l_3526;
	case 13608ULL: goto x86_l_3528;
	case 13613ULL: goto x86_l_352d;
	case 13621ULL: goto x86_l_3535;
	case 13624ULL: goto x86_l_3538;
	case 13632ULL: goto x86_l_3540;
	case 13641ULL: goto x86_l_3549;
	case 13645ULL: goto x86_l_354d;
	case 13650ULL: goto x86_l_3552;
	case 13655ULL: goto x86_l_3557;
	case 13660ULL: goto x86_l_355c;
	case 13662ULL: goto x86_l_355e;
	case 13664ULL: goto x86_l_3560;
	case 13670ULL: goto x86_l_3566;
	case 13676ULL: goto x86_l_356c;
	case 13679ULL: goto x86_l_356f;
	case 13684ULL: goto x86_l_3574;
	case 13690ULL: goto x86_l_357a;
	case 13695ULL: goto x86_l_357f;
	case 13703ULL: goto x86_l_3587;
	case 13707ULL: goto x86_l_358b;
	case 13714ULL: goto x86_l_3592;
	case 13719ULL: goto x86_l_3597;
	case 13724ULL: goto x86_l_359c;
	case 13726ULL: goto x86_l_359e;
	case 13730ULL: goto x86_l_35a2;
	case 13732ULL: goto x86_l_35a4;
	case 13734ULL: goto x86_l_35a6;
	case 13740ULL: goto x86_l_35ac;
	case 13743ULL: goto x86_l_35af;
	case 13748ULL: goto x86_l_35b4;
	case 13754ULL: goto x86_l_35ba;
	case 13759ULL: goto x86_l_35bf;
	case 13767ULL: goto x86_l_35c7;
	case 13771ULL: goto x86_l_35cb;
	case 13778ULL: goto x86_l_35d2;
	case 13783ULL: goto x86_l_35d7;
	case 13788ULL: goto x86_l_35dc;
	case 13790ULL: goto x86_l_35de;
	case 13795ULL: goto x86_l_35e3;
	case 13803ULL: goto x86_l_35eb;
	case 13806ULL: goto x86_l_35ee;
	case 13814ULL: goto x86_l_35f6;
	case 13823ULL: goto x86_l_35ff;
	case 13827ULL: goto x86_l_3603;
	case 13832ULL: goto x86_l_3608;
	case 13837ULL: goto x86_l_360d;
	case 13842ULL: goto x86_l_3612;
	case 13844ULL: goto x86_l_3614;
	case 13846ULL: goto x86_l_3616;
	case 13852ULL: goto x86_l_361c;
	case 13858ULL: goto x86_l_3622;
	case 13861ULL: goto x86_l_3625;
	case 13866ULL: goto x86_l_362a;
	case 13872ULL: goto x86_l_3630;
	case 13877ULL: goto x86_l_3635;
	case 13885ULL: goto x86_l_363d;
	case 13889ULL: goto x86_l_3641;
	case 13896ULL: goto x86_l_3648;
	case 13901ULL: goto x86_l_364d;
	case 13906ULL: goto x86_l_3652;
	case 13908ULL: goto x86_l_3654;
	case 13912ULL: goto x86_l_3658;
	case 13914ULL: goto x86_l_365a;
	case 13916ULL: goto x86_l_365c;
	case 13922ULL: goto x86_l_3662;
	case 13925ULL: goto x86_l_3665;
	case 13930ULL: goto x86_l_366a;
	case 13936ULL: goto x86_l_3670;
	case 13941ULL: goto x86_l_3675;
	case 13949ULL: goto x86_l_367d;
	case 13953ULL: goto x86_l_3681;
	case 13960ULL: goto x86_l_3688;
	case 13965ULL: goto x86_l_368d;
	case 13970ULL: goto x86_l_3692;
	case 13972ULL: goto x86_l_3694;
	case 13977ULL: goto x86_l_3699;
	case 13985ULL: goto x86_l_36a1;
	case 13988ULL: goto x86_l_36a4;
	case 13996ULL: goto x86_l_36ac;
	case 14005ULL: goto x86_l_36b5;
	case 14009ULL: goto x86_l_36b9;
	case 14014ULL: goto x86_l_36be;
	case 14019ULL: goto x86_l_36c3;
	case 14024ULL: goto x86_l_36c8;
	case 14026ULL: goto x86_l_36ca;
	case 14028ULL: goto x86_l_36cc;
	case 14034ULL: goto x86_l_36d2;
	case 14040ULL: goto x86_l_36d8;
	case 14043ULL: goto x86_l_36db;
	case 14048ULL: goto x86_l_36e0;
	case 14054ULL: goto x86_l_36e6;
	case 14059ULL: goto x86_l_36eb;
	case 14067ULL: goto x86_l_36f3;
	case 14071ULL: goto x86_l_36f7;
	case 14078ULL: goto x86_l_36fe;
	case 14083ULL: goto x86_l_3703;
	case 14088ULL: goto x86_l_3708;
	case 14090ULL: goto x86_l_370a;
	case 14094ULL: goto x86_l_370e;
	case 14096ULL: goto x86_l_3710;
	case 14098ULL: goto x86_l_3712;
	case 14104ULL: goto x86_l_3718;
	case 14107ULL: goto x86_l_371b;
	case 14112ULL: goto x86_l_3720;
	case 14118ULL: goto x86_l_3726;
	case 14123ULL: goto x86_l_372b;
	case 14131ULL: goto x86_l_3733;
	case 14135ULL: goto x86_l_3737;
	case 14142ULL: goto x86_l_373e;
	case 14147ULL: goto x86_l_3743;
	case 14152ULL: goto x86_l_3748;
	case 14154ULL: goto x86_l_374a;
	case 14159ULL: goto x86_l_374f;
	case 14167ULL: goto x86_l_3757;
	case 14170ULL: goto x86_l_375a;
	case 14178ULL: goto x86_l_3762;
	case 14187ULL: goto x86_l_376b;
	case 14194ULL: goto x86_l_3772;
	case 14199ULL: goto x86_l_3777;
	case 14204ULL: goto x86_l_377c;
	case 14209ULL: goto x86_l_3781;
	case 14211ULL: goto x86_l_3783;
	case 14213ULL: goto x86_l_3785;
	case 14219ULL: goto x86_l_378b;
	case 14225ULL: goto x86_l_3791;
	case 14228ULL: goto x86_l_3794;
	case 14233ULL: goto x86_l_3799;
	case 14239ULL: goto x86_l_379f;
	case 14244ULL: goto x86_l_37a4;
	case 14252ULL: goto x86_l_37ac;
	case 14256ULL: goto x86_l_37b0;
	case 14263ULL: goto x86_l_37b7;
	case 14268ULL: goto x86_l_37bc;
	case 14273ULL: goto x86_l_37c1;
	case 14275ULL: goto x86_l_37c3;
	case 14279ULL: goto x86_l_37c7;
	case 14281ULL: goto x86_l_37c9;
	case 14283ULL: goto x86_l_37cb;
	case 14289ULL: goto x86_l_37d1;
	case 14292ULL: goto x86_l_37d4;
	case 14297ULL: goto x86_l_37d9;
	case 14303ULL: goto x86_l_37df;
	case 14308ULL: goto x86_l_37e4;
	case 14316ULL: goto x86_l_37ec;
	case 14320ULL: goto x86_l_37f0;
	case 14327ULL: goto x86_l_37f7;
	case 14332ULL: goto x86_l_37fc;
	case 14337ULL: goto x86_l_3801;
	case 14339ULL: goto x86_l_3803;
	case 14344ULL: goto x86_l_3808;
	case 14352ULL: goto x86_l_3810;
	case 14355ULL: goto x86_l_3813;
	case 14363ULL: goto x86_l_381b;
	case 14372ULL: goto x86_l_3824;
	case 14379ULL: goto x86_l_382b;
	case 14384ULL: goto x86_l_3830;
	case 14389ULL: goto x86_l_3835;
	case 14394ULL: goto x86_l_383a;
	case 14396ULL: goto x86_l_383c;
	case 14398ULL: goto x86_l_383e;
	case 14404ULL: goto x86_l_3844;
	case 14410ULL: goto x86_l_384a;
	case 14413ULL: goto x86_l_384d;
	case 14418ULL: goto x86_l_3852;
	case 14424ULL: goto x86_l_3858;
	case 14429ULL: goto x86_l_385d;
	case 14437ULL: goto x86_l_3865;
	case 14441ULL: goto x86_l_3869;
	case 14448ULL: goto x86_l_3870;
	case 14453ULL: goto x86_l_3875;
	case 14458ULL: goto x86_l_387a;
	case 14460ULL: goto x86_l_387c;
	case 14464ULL: goto x86_l_3880;
	case 14466ULL: goto x86_l_3882;
	case 14468ULL: goto x86_l_3884;
	case 14474ULL: goto x86_l_388a;
	case 14477ULL: goto x86_l_388d;
	case 14482ULL: goto x86_l_3892;
	case 14488ULL: goto x86_l_3898;
	case 14493ULL: goto x86_l_389d;
	case 14501ULL: goto x86_l_38a5;
	case 14505ULL: goto x86_l_38a9;
	case 14512ULL: goto x86_l_38b0;
	case 14517ULL: goto x86_l_38b5;
	case 14522ULL: goto x86_l_38ba;
	case 14524ULL: goto x86_l_38bc;
	case 14529ULL: goto x86_l_38c1;
	case 14537ULL: goto x86_l_38c9;
	case 14540ULL: goto x86_l_38cc;
	case 14548ULL: goto x86_l_38d4;
	case 14557ULL: goto x86_l_38dd;
	case 14564ULL: goto x86_l_38e4;
	case 14569ULL: goto x86_l_38e9;
	case 14574ULL: goto x86_l_38ee;
	case 14579ULL: goto x86_l_38f3;
	case 14581ULL: goto x86_l_38f5;
	case 14583ULL: goto x86_l_38f7;
	case 14589ULL: goto x86_l_38fd;
	case 14595ULL: goto x86_l_3903;
	case 14598ULL: goto x86_l_3906;
	case 14603ULL: goto x86_l_390b;
	case 14609ULL: goto x86_l_3911;
	case 14614ULL: goto x86_l_3916;
	case 14622ULL: goto x86_l_391e;
	case 14626ULL: goto x86_l_3922;
	case 14633ULL: goto x86_l_3929;
	case 14638ULL: goto x86_l_392e;
	case 14643ULL: goto x86_l_3933;
	case 14645ULL: goto x86_l_3935;
	case 14649ULL: goto x86_l_3939;
	case 14651ULL: goto x86_l_393b;
	case 14653ULL: goto x86_l_393d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_31de:
	/* 0x31de: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31e1:
	/* 0x31e1: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_31e6:
	/* 0x31e6: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_31ec:
	/* 0x31ec: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_31f1:
	/* 0x31f1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_31f9:
	/* 0x31f9: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_31fd:
	/* 0x31fd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3204:
	/* 0x3204: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3209:
	/* 0x3209: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_320e:
	/* 0x320e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3210:
	/* 0x3210: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3214:
	/* 0x3214: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_3216:
	/* 0x3216: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3218:
	/* 0x3218: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_321e:
	/* 0x321e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3221:
	/* 0x3221: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3226:
	/* 0x3226: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_322c:
	/* 0x322c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3231:
	/* 0x3231: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3239:
	/* 0x3239: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_323d:
	/* 0x323d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3244:
	/* 0x3244: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3249:
	/* 0x3249: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_324e:
	/* 0x324e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3250:
	/* 0x3250: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3255:
	/* 0x3255: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_325d:
	/* 0x325d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3260:
	/* 0x3260: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3268:
	/* 0x3268: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3271:
	/* 0x3271: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3275:
	/* 0x3275: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_327a:
	/* 0x327a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_327f:
	/* 0x327f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3284:
	/* 0x3284: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3286:
	/* 0x3286: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_3288:
	/* 0x3288: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_328e:
	/* 0x328e: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3294:
	/* 0x3294: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3297:
	/* 0x3297: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_329c:
	/* 0x329c: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_32a2:
	/* 0x32a2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_32a7:
	/* 0x32a7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_32af:
	/* 0x32af: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_32b3:
	/* 0x32b3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_32ba:
	/* 0x32ba: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32bf:
	/* 0x32bf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_32c4:
	/* 0x32c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32c6:
	/* 0x32c6: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_32ca:
	/* 0x32ca: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_32cc:
	/* 0x32cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32ce:
	/* 0x32ce: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_32d4:
	/* 0x32d4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32d7:
	/* 0x32d7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_32dc:
	/* 0x32dc: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_32e2:
	/* 0x32e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32e7:
	/* 0x32e7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_32ef:
	/* 0x32ef: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_32f3:
	/* 0x32f3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_32fa:
	/* 0x32fa: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_32ff:
	/* 0x32ff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3304:
	/* 0x3304: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3306:
	/* 0x3306: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_330b:
	/* 0x330b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3313:
	/* 0x3313: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3316:
	/* 0x3316: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_331e:
	/* 0x331e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3327:
	/* 0x3327: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_332b:
	/* 0x332b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3330:
	/* 0x3330: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3335:
	/* 0x3335: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_333a:
	/* 0x333a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_333c:
	/* 0x333c: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_333e:
	/* 0x333e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3344:
	/* 0x3344: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_334a:
	/* 0x334a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_334d:
	/* 0x334d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3352:
	/* 0x3352: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3358:
	/* 0x3358: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_335d:
	/* 0x335d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3365:
	/* 0x3365: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3369:
	/* 0x3369: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3370:
	/* 0x3370: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3375:
	/* 0x3375: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_337a:
	/* 0x337a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_337c:
	/* 0x337c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3380:
	/* 0x3380: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_3382:
	/* 0x3382: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3384:
	/* 0x3384: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_338a:
	/* 0x338a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_338d:
	/* 0x338d: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3392:
	/* 0x3392: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3398:
	/* 0x3398: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_339d:
	/* 0x339d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_33a5:
	/* 0x33a5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_33a9:
	/* 0x33a9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_33b0:
	/* 0x33b0: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_33b5:
	/* 0x33b5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_33ba:
	/* 0x33ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33bc:
	/* 0x33bc: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_33c1:
	/* 0x33c1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_33c9:
	/* 0x33c9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_33cc:
	/* 0x33cc: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_33d4:
	/* 0x33d4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_33dd:
	/* 0x33dd: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_33e1:
	/* 0x33e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33e6:
	/* 0x33e6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33eb:
	/* 0x33eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33f0:
	/* 0x33f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33f2:
	/* 0x33f2: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_33f4:
	/* 0x33f4: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_33fa:
	/* 0x33fa: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3400:
	/* 0x3400: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3403:
	/* 0x3403: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3408:
	/* 0x3408: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_340e:
	/* 0x340e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3413:
	/* 0x3413: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_341b:
	/* 0x341b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_341f:
	/* 0x341f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3426:
	/* 0x3426: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_342b:
	/* 0x342b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3430:
	/* 0x3430: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3432:
	/* 0x3432: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3436:
	/* 0x3436: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_3438:
	/* 0x3438: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_343a:
	/* 0x343a: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_3440:
	/* 0x3440: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3443:
	/* 0x3443: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3448:
	/* 0x3448: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_344e:
	/* 0x344e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3453:
	/* 0x3453: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_345b:
	/* 0x345b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_345f:
	/* 0x345f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3466:
	/* 0x3466: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_346b:
	/* 0x346b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3470:
	/* 0x3470: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3472:
	/* 0x3472: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3477:
	/* 0x3477: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_347f:
	/* 0x347f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3482:
	/* 0x3482: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_348a:
	/* 0x348a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3493:
	/* 0x3493: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3497:
	/* 0x3497: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_349c:
	/* 0x349c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34a1:
	/* 0x34a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34a6:
	/* 0x34a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34a8:
	/* 0x34a8: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_34aa:
	/* 0x34aa: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_34b0:
	/* 0x34b0: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_34b6:
	/* 0x34b6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34b9:
	/* 0x34b9: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_34be:
	/* 0x34be: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_34c4:
	/* 0x34c4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_34c9:
	/* 0x34c9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_34d1:
	/* 0x34d1: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_34d5:
	/* 0x34d5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_34dc:
	/* 0x34dc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34e1:
	/* 0x34e1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_34e6:
	/* 0x34e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34e8:
	/* 0x34e8: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_34ec:
	/* 0x34ec: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_34ee:
	/* 0x34ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34f0:
	/* 0x34f0: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_34f6:
	/* 0x34f6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34f9:
	/* 0x34f9: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_34fe:
	/* 0x34fe: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3504:
	/* 0x3504: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3509:
	/* 0x3509: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3511:
	/* 0x3511: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3515:
	/* 0x3515: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_351c:
	/* 0x351c: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3521:
	/* 0x3521: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3526:
	/* 0x3526: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3528:
	/* 0x3528: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_352d:
	/* 0x352d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3535:
	/* 0x3535: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3538:
	/* 0x3538: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3540:
	/* 0x3540: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3549:
	/* 0x3549: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_354d:
	/* 0x354d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3552:
	/* 0x3552: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3557:
	/* 0x3557: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_355c:
	/* 0x355c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_355e:
	/* 0x355e: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_3560:
	/* 0x3560: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3566:
	/* 0x3566: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_356c:
	/* 0x356c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_356f:
	/* 0x356f: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3574:
	/* 0x3574: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_357a:
	/* 0x357a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_357f:
	/* 0x357f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3587:
	/* 0x3587: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_358b:
	/* 0x358b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3592:
	/* 0x3592: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3597:
	/* 0x3597: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_359c:
	/* 0x359c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_359e:
	/* 0x359e: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_35a2:
	/* 0x35a2: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_35a4:
	/* 0x35a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35a6:
	/* 0x35a6: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_35ac:
	/* 0x35ac: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35af:
	/* 0x35af: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_35b4:
	/* 0x35b4: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_35ba:
	/* 0x35ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35bf:
	/* 0x35bf: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_35c7:
	/* 0x35c7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_35cb:
	/* 0x35cb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_35d2:
	/* 0x35d2: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_35d7:
	/* 0x35d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_35dc:
	/* 0x35dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35de:
	/* 0x35de: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_35e3:
	/* 0x35e3: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_35eb:
	/* 0x35eb: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_35ee:
	/* 0x35ee: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_35f6:
	/* 0x35f6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_35ff:
	/* 0x35ff: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3603:
	/* 0x3603: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3608:
	/* 0x3608: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_360d:
	/* 0x360d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3612:
	/* 0x3612: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3614:
	/* 0x3614: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_3616:
	/* 0x3616: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_361c:
	/* 0x361c: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3622:
	/* 0x3622: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3625:
	/* 0x3625: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_362a:
	/* 0x362a: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3630:
	/* 0x3630: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3635:
	/* 0x3635: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_363d:
	/* 0x363d: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3641:
	/* 0x3641: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3648:
	/* 0x3648: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_364d:
	/* 0x364d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3652:
	/* 0x3652: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3654:
	/* 0x3654: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3658:
	/* 0x3658: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_365a:
	/* 0x365a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_365c:
	/* 0x365c: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_3662:
	/* 0x3662: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3665:
	/* 0x3665: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_366a:
	/* 0x366a: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3670:
	/* 0x3670: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3675:
	/* 0x3675: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_367d:
	/* 0x367d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3681:
	/* 0x3681: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3688:
	/* 0x3688: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_368d:
	/* 0x368d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3692:
	/* 0x3692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3694:
	/* 0x3694: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3699:
	/* 0x3699: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_36a1:
	/* 0x36a1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_36a4:
	/* 0x36a4: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_36ac:
	/* 0x36ac: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_36b5:
	/* 0x36b5: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_36b9:
	/* 0x36b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36be:
	/* 0x36be: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36c3:
	/* 0x36c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36c8:
	/* 0x36c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36ca:
	/* 0x36ca: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_36cc:
	/* 0x36cc: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_36d2:
	/* 0x36d2: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_36d8:
	/* 0x36d8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_36db:
	/* 0x36db: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_36e0:
	/* 0x36e0: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_36e6:
	/* 0x36e6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_36eb:
	/* 0x36eb: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_36f3:
	/* 0x36f3: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_36f7:
	/* 0x36f7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_36fe:
	/* 0x36fe: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3703:
	/* 0x3703: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3708:
	/* 0x3708: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_370a:
	/* 0x370a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_370e:
	/* 0x370e: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_3710:
	/* 0x3710: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3712:
	/* 0x3712: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_3718:
	/* 0x3718: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_371b:
	/* 0x371b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3720:
	/* 0x3720: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3726:
	/* 0x3726: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_372b:
	/* 0x372b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3733:
	/* 0x3733: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3737:
	/* 0x3737: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_373e:
	/* 0x373e: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3743:
	/* 0x3743: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3748:
	/* 0x3748: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_374a:
	/* 0x374a: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_374f:
	/* 0x374f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3757:
	/* 0x3757: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_375a:
	/* 0x375a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3762:
	/* 0x3762: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_376b:
	/* 0x376b: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3772:
	/* 0x3772: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3777:
	/* 0x3777: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_377c:
	/* 0x377c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3781:
	/* 0x3781: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3783:
	/* 0x3783: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_3785:
	/* 0x3785: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_378b:
	/* 0x378b: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3791:
	/* 0x3791: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3794:
	/* 0x3794: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3799:
	/* 0x3799: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_379f:
	/* 0x379f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_37a4:
	/* 0x37a4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_37ac:
	/* 0x37ac: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_37b0:
	/* 0x37b0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_37b7:
	/* 0x37b7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37bc:
	/* 0x37bc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_37c1:
	/* 0x37c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37c3:
	/* 0x37c3: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_37c7:
	/* 0x37c7: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_37c9:
	/* 0x37c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37cb:
	/* 0x37cb: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_37d1:
	/* 0x37d1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37d4:
	/* 0x37d4: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_37d9:
	/* 0x37d9: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_37df:
	/* 0x37df: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37e4:
	/* 0x37e4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_37ec:
	/* 0x37ec: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_37f0:
	/* 0x37f0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_37f7:
	/* 0x37f7: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_37fc:
	/* 0x37fc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3801:
	/* 0x3801: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3803:
	/* 0x3803: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3808:
	/* 0x3808: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3810:
	/* 0x3810: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3813:
	/* 0x3813: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_381b:
	/* 0x381b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3824:
	/* 0x3824: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_382b:
	/* 0x382b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3830:
	/* 0x3830: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3835:
	/* 0x3835: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_383a:
	/* 0x383a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_383c:
	/* 0x383c: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_383e:
	/* 0x383e: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3844:
	/* 0x3844: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_384a:
	/* 0x384a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_384d:
	/* 0x384d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3852:
	/* 0x3852: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3858:
	/* 0x3858: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_385d:
	/* 0x385d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3865:
	/* 0x3865: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3869:
	/* 0x3869: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3870:
	/* 0x3870: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3875:
	/* 0x3875: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_387a:
	/* 0x387a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_387c:
	/* 0x387c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3880:
	/* 0x3880: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_3882:
	/* 0x3882: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3884:
	/* 0x3884: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_388a:
	/* 0x388a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_388d:
	/* 0x388d: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3892:
	/* 0x3892: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3898:
	/* 0x3898: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_389d:
	/* 0x389d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_38a5:
	/* 0x38a5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_38a9:
	/* 0x38a9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_38b0:
	/* 0x38b0: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_38b5:
	/* 0x38b5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38ba:
	/* 0x38ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38bc:
	/* 0x38bc: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_38c1:
	/* 0x38c1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_38c9:
	/* 0x38c9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_38cc:
	/* 0x38cc: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_38d4:
	/* 0x38d4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_38dd:
	/* 0x38dd: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_38e4:
	/* 0x38e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38e9:
	/* 0x38e9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38ee:
	/* 0x38ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38f3:
	/* 0x38f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38f5:
	/* 0x38f5: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_38f7:
	/* 0x38f7: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_38fd:
	/* 0x38fd: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3903:
	/* 0x3903: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3906:
	/* 0x3906: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_390b:
	/* 0x390b: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3911:
	/* 0x3911: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3916:
	/* 0x3916: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_391e:
	/* 0x391e: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3922:
	/* 0x3922: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3929:
	/* 0x3929: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_392e:
	/* 0x392e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3933:
	/* 0x3933: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3935:
	/* 0x3935: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3939:
	/* 0x3939: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_393b:
	/* 0x393b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_393d:
	/* 0x393d: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
	return 14659ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14659ULL: goto x86_l_3943;
	case 14662ULL: goto x86_l_3946;
	case 14667ULL: goto x86_l_394b;
	case 14673ULL: goto x86_l_3951;
	case 14678ULL: goto x86_l_3956;
	case 14686ULL: goto x86_l_395e;
	case 14690ULL: goto x86_l_3962;
	case 14697ULL: goto x86_l_3969;
	case 14702ULL: goto x86_l_396e;
	case 14707ULL: goto x86_l_3973;
	case 14709ULL: goto x86_l_3975;
	case 14714ULL: goto x86_l_397a;
	case 14722ULL: goto x86_l_3982;
	case 14725ULL: goto x86_l_3985;
	case 14733ULL: goto x86_l_398d;
	case 14742ULL: goto x86_l_3996;
	case 14749ULL: goto x86_l_399d;
	case 14754ULL: goto x86_l_39a2;
	case 14759ULL: goto x86_l_39a7;
	case 14764ULL: goto x86_l_39ac;
	case 14766ULL: goto x86_l_39ae;
	case 14768ULL: goto x86_l_39b0;
	case 14774ULL: goto x86_l_39b6;
	case 14780ULL: goto x86_l_39bc;
	case 14783ULL: goto x86_l_39bf;
	case 14788ULL: goto x86_l_39c4;
	case 14794ULL: goto x86_l_39ca;
	case 14799ULL: goto x86_l_39cf;
	case 14807ULL: goto x86_l_39d7;
	case 14811ULL: goto x86_l_39db;
	case 14818ULL: goto x86_l_39e2;
	case 14823ULL: goto x86_l_39e7;
	case 14828ULL: goto x86_l_39ec;
	case 14830ULL: goto x86_l_39ee;
	case 14834ULL: goto x86_l_39f2;
	case 14836ULL: goto x86_l_39f4;
	case 14838ULL: goto x86_l_39f6;
	case 14844ULL: goto x86_l_39fc;
	case 14847ULL: goto x86_l_39ff;
	case 14852ULL: goto x86_l_3a04;
	case 14858ULL: goto x86_l_3a0a;
	case 14863ULL: goto x86_l_3a0f;
	case 14871ULL: goto x86_l_3a17;
	case 14875ULL: goto x86_l_3a1b;
	case 14882ULL: goto x86_l_3a22;
	case 14887ULL: goto x86_l_3a27;
	case 14892ULL: goto x86_l_3a2c;
	case 14894ULL: goto x86_l_3a2e;
	case 14899ULL: goto x86_l_3a33;
	case 14907ULL: goto x86_l_3a3b;
	case 14910ULL: goto x86_l_3a3e;
	case 14918ULL: goto x86_l_3a46;
	case 14927ULL: goto x86_l_3a4f;
	case 14934ULL: goto x86_l_3a56;
	case 14939ULL: goto x86_l_3a5b;
	case 14944ULL: goto x86_l_3a60;
	case 14949ULL: goto x86_l_3a65;
	case 14951ULL: goto x86_l_3a67;
	case 14953ULL: goto x86_l_3a69;
	case 14959ULL: goto x86_l_3a6f;
	case 14965ULL: goto x86_l_3a75;
	case 14968ULL: goto x86_l_3a78;
	case 14973ULL: goto x86_l_3a7d;
	case 14979ULL: goto x86_l_3a83;
	case 14984ULL: goto x86_l_3a88;
	case 14992ULL: goto x86_l_3a90;
	case 14996ULL: goto x86_l_3a94;
	case 15003ULL: goto x86_l_3a9b;
	case 15008ULL: goto x86_l_3aa0;
	case 15013ULL: goto x86_l_3aa5;
	case 15015ULL: goto x86_l_3aa7;
	case 15019ULL: goto x86_l_3aab;
	case 15021ULL: goto x86_l_3aad;
	case 15023ULL: goto x86_l_3aaf;
	case 15029ULL: goto x86_l_3ab5;
	case 15032ULL: goto x86_l_3ab8;
	case 15037ULL: goto x86_l_3abd;
	case 15043ULL: goto x86_l_3ac3;
	case 15048ULL: goto x86_l_3ac8;
	case 15056ULL: goto x86_l_3ad0;
	case 15060ULL: goto x86_l_3ad4;
	case 15067ULL: goto x86_l_3adb;
	case 15072ULL: goto x86_l_3ae0;
	case 15077ULL: goto x86_l_3ae5;
	case 15079ULL: goto x86_l_3ae7;
	case 15084ULL: goto x86_l_3aec;
	case 15092ULL: goto x86_l_3af4;
	case 15095ULL: goto x86_l_3af7;
	case 15103ULL: goto x86_l_3aff;
	case 15112ULL: goto x86_l_3b08;
	case 15119ULL: goto x86_l_3b0f;
	case 15124ULL: goto x86_l_3b14;
	case 15129ULL: goto x86_l_3b19;
	case 15134ULL: goto x86_l_3b1e;
	case 15136ULL: goto x86_l_3b20;
	case 15138ULL: goto x86_l_3b22;
	case 15144ULL: goto x86_l_3b28;
	case 15150ULL: goto x86_l_3b2e;
	case 15153ULL: goto x86_l_3b31;
	case 15158ULL: goto x86_l_3b36;
	case 15164ULL: goto x86_l_3b3c;
	case 15169ULL: goto x86_l_3b41;
	case 15177ULL: goto x86_l_3b49;
	case 15181ULL: goto x86_l_3b4d;
	case 15188ULL: goto x86_l_3b54;
	case 15193ULL: goto x86_l_3b59;
	case 15198ULL: goto x86_l_3b5e;
	case 15200ULL: goto x86_l_3b60;
	case 15204ULL: goto x86_l_3b64;
	case 15206ULL: goto x86_l_3b66;
	case 15208ULL: goto x86_l_3b68;
	case 15214ULL: goto x86_l_3b6e;
	case 15217ULL: goto x86_l_3b71;
	case 15222ULL: goto x86_l_3b76;
	case 15228ULL: goto x86_l_3b7c;
	case 15233ULL: goto x86_l_3b81;
	case 15241ULL: goto x86_l_3b89;
	case 15245ULL: goto x86_l_3b8d;
	case 15252ULL: goto x86_l_3b94;
	case 15257ULL: goto x86_l_3b99;
	case 15262ULL: goto x86_l_3b9e;
	case 15264ULL: goto x86_l_3ba0;
	case 15269ULL: goto x86_l_3ba5;
	case 15277ULL: goto x86_l_3bad;
	case 15280ULL: goto x86_l_3bb0;
	case 15288ULL: goto x86_l_3bb8;
	case 15297ULL: goto x86_l_3bc1;
	case 15304ULL: goto x86_l_3bc8;
	case 15309ULL: goto x86_l_3bcd;
	case 15314ULL: goto x86_l_3bd2;
	case 15319ULL: goto x86_l_3bd7;
	case 15321ULL: goto x86_l_3bd9;
	case 15323ULL: goto x86_l_3bdb;
	case 15329ULL: goto x86_l_3be1;
	case 15335ULL: goto x86_l_3be7;
	case 15338ULL: goto x86_l_3bea;
	case 15343ULL: goto x86_l_3bef;
	case 15349ULL: goto x86_l_3bf5;
	case 15354ULL: goto x86_l_3bfa;
	case 15362ULL: goto x86_l_3c02;
	case 15366ULL: goto x86_l_3c06;
	case 15373ULL: goto x86_l_3c0d;
	case 15378ULL: goto x86_l_3c12;
	case 15383ULL: goto x86_l_3c17;
	case 15385ULL: goto x86_l_3c19;
	case 15389ULL: goto x86_l_3c1d;
	case 15391ULL: goto x86_l_3c1f;
	case 15393ULL: goto x86_l_3c21;
	case 15399ULL: goto x86_l_3c27;
	case 15402ULL: goto x86_l_3c2a;
	case 15407ULL: goto x86_l_3c2f;
	case 15413ULL: goto x86_l_3c35;
	case 15418ULL: goto x86_l_3c3a;
	case 15426ULL: goto x86_l_3c42;
	case 15430ULL: goto x86_l_3c46;
	case 15437ULL: goto x86_l_3c4d;
	case 15442ULL: goto x86_l_3c52;
	case 15447ULL: goto x86_l_3c57;
	case 15449ULL: goto x86_l_3c59;
	case 15454ULL: goto x86_l_3c5e;
	case 15462ULL: goto x86_l_3c66;
	case 15465ULL: goto x86_l_3c69;
	case 15473ULL: goto x86_l_3c71;
	case 15482ULL: goto x86_l_3c7a;
	case 15489ULL: goto x86_l_3c81;
	case 15494ULL: goto x86_l_3c86;
	case 15499ULL: goto x86_l_3c8b;
	case 15504ULL: goto x86_l_3c90;
	case 15506ULL: goto x86_l_3c92;
	case 15508ULL: goto x86_l_3c94;
	case 15514ULL: goto x86_l_3c9a;
	case 15520ULL: goto x86_l_3ca0;
	case 15523ULL: goto x86_l_3ca3;
	case 15528ULL: goto x86_l_3ca8;
	case 15534ULL: goto x86_l_3cae;
	case 15539ULL: goto x86_l_3cb3;
	case 15547ULL: goto x86_l_3cbb;
	case 15551ULL: goto x86_l_3cbf;
	case 15558ULL: goto x86_l_3cc6;
	case 15563ULL: goto x86_l_3ccb;
	case 15568ULL: goto x86_l_3cd0;
	case 15570ULL: goto x86_l_3cd2;
	case 15574ULL: goto x86_l_3cd6;
	case 15576ULL: goto x86_l_3cd8;
	case 15578ULL: goto x86_l_3cda;
	case 15584ULL: goto x86_l_3ce0;
	case 15587ULL: goto x86_l_3ce3;
	case 15592ULL: goto x86_l_3ce8;
	case 15598ULL: goto x86_l_3cee;
	case 15603ULL: goto x86_l_3cf3;
	case 15611ULL: goto x86_l_3cfb;
	case 15615ULL: goto x86_l_3cff;
	case 15622ULL: goto x86_l_3d06;
	case 15627ULL: goto x86_l_3d0b;
	case 15632ULL: goto x86_l_3d10;
	case 15634ULL: goto x86_l_3d12;
	case 15639ULL: goto x86_l_3d17;
	case 15647ULL: goto x86_l_3d1f;
	case 15650ULL: goto x86_l_3d22;
	case 15658ULL: goto x86_l_3d2a;
	case 15667ULL: goto x86_l_3d33;
	case 15674ULL: goto x86_l_3d3a;
	case 15679ULL: goto x86_l_3d3f;
	case 15684ULL: goto x86_l_3d44;
	case 15689ULL: goto x86_l_3d49;
	case 15691ULL: goto x86_l_3d4b;
	case 15693ULL: goto x86_l_3d4d;
	case 15699ULL: goto x86_l_3d53;
	case 15705ULL: goto x86_l_3d59;
	case 15708ULL: goto x86_l_3d5c;
	case 15713ULL: goto x86_l_3d61;
	case 15719ULL: goto x86_l_3d67;
	case 15724ULL: goto x86_l_3d6c;
	case 15732ULL: goto x86_l_3d74;
	case 15736ULL: goto x86_l_3d78;
	case 15743ULL: goto x86_l_3d7f;
	case 15748ULL: goto x86_l_3d84;
	case 15753ULL: goto x86_l_3d89;
	case 15755ULL: goto x86_l_3d8b;
	case 15759ULL: goto x86_l_3d8f;
	case 15761ULL: goto x86_l_3d91;
	case 15763ULL: goto x86_l_3d93;
	case 15769ULL: goto x86_l_3d99;
	case 15772ULL: goto x86_l_3d9c;
	case 15777ULL: goto x86_l_3da1;
	case 15783ULL: goto x86_l_3da7;
	case 15788ULL: goto x86_l_3dac;
	case 15796ULL: goto x86_l_3db4;
	case 15800ULL: goto x86_l_3db8;
	case 15807ULL: goto x86_l_3dbf;
	case 15812ULL: goto x86_l_3dc4;
	case 15817ULL: goto x86_l_3dc9;
	case 15819ULL: goto x86_l_3dcb;
	case 15824ULL: goto x86_l_3dd0;
	case 15832ULL: goto x86_l_3dd8;
	case 15835ULL: goto x86_l_3ddb;
	case 15843ULL: goto x86_l_3de3;
	case 15852ULL: goto x86_l_3dec;
	case 15859ULL: goto x86_l_3df3;
	case 15864ULL: goto x86_l_3df8;
	case 15869ULL: goto x86_l_3dfd;
	case 15874ULL: goto x86_l_3e02;
	case 15876ULL: goto x86_l_3e04;
	case 15878ULL: goto x86_l_3e06;
	case 15884ULL: goto x86_l_3e0c;
	case 15890ULL: goto x86_l_3e12;
	case 15893ULL: goto x86_l_3e15;
	case 15898ULL: goto x86_l_3e1a;
	case 15904ULL: goto x86_l_3e20;
	case 15909ULL: goto x86_l_3e25;
	case 15917ULL: goto x86_l_3e2d;
	case 15921ULL: goto x86_l_3e31;
	case 15928ULL: goto x86_l_3e38;
	case 15933ULL: goto x86_l_3e3d;
	case 15938ULL: goto x86_l_3e42;
	case 15940ULL: goto x86_l_3e44;
	case 15944ULL: goto x86_l_3e48;
	case 15946ULL: goto x86_l_3e4a;
	case 15948ULL: goto x86_l_3e4c;
	case 15954ULL: goto x86_l_3e52;
	case 15957ULL: goto x86_l_3e55;
	case 15962ULL: goto x86_l_3e5a;
	case 15968ULL: goto x86_l_3e60;
	case 15973ULL: goto x86_l_3e65;
	case 15981ULL: goto x86_l_3e6d;
	case 15985ULL: goto x86_l_3e71;
	case 15992ULL: goto x86_l_3e78;
	case 15997ULL: goto x86_l_3e7d;
	case 16002ULL: goto x86_l_3e82;
	case 16004ULL: goto x86_l_3e84;
	case 16009ULL: goto x86_l_3e89;
	case 16017ULL: goto x86_l_3e91;
	case 16020ULL: goto x86_l_3e94;
	case 16028ULL: goto x86_l_3e9c;
	case 16037ULL: goto x86_l_3ea5;
	case 16044ULL: goto x86_l_3eac;
	case 16049ULL: goto x86_l_3eb1;
	case 16054ULL: goto x86_l_3eb6;
	case 16059ULL: goto x86_l_3ebb;
	case 16061ULL: goto x86_l_3ebd;
	case 16063ULL: goto x86_l_3ebf;
	case 16069ULL: goto x86_l_3ec5;
	case 16075ULL: goto x86_l_3ecb;
	case 16078ULL: goto x86_l_3ece;
	case 16083ULL: goto x86_l_3ed3;
	case 16089ULL: goto x86_l_3ed9;
	case 16094ULL: goto x86_l_3ede;
	case 16102ULL: goto x86_l_3ee6;
	case 16106ULL: goto x86_l_3eea;
	case 16113ULL: goto x86_l_3ef1;
	case 16118ULL: goto x86_l_3ef6;
	case 16123ULL: goto x86_l_3efb;
	case 16125ULL: goto x86_l_3efd;
	case 16129ULL: goto x86_l_3f01;
	case 16131ULL: goto x86_l_3f03;
	case 16133ULL: goto x86_l_3f05;
	case 16139ULL: goto x86_l_3f0b;
	case 16142ULL: goto x86_l_3f0e;
	case 16147ULL: goto x86_l_3f13;
	case 16153ULL: goto x86_l_3f19;
	case 16158ULL: goto x86_l_3f1e;
	case 16166ULL: goto x86_l_3f26;
	case 16170ULL: goto x86_l_3f2a;
	case 16177ULL: goto x86_l_3f31;
	case 16182ULL: goto x86_l_3f36;
	case 16187ULL: goto x86_l_3f3b;
	case 16189ULL: goto x86_l_3f3d;
	case 16194ULL: goto x86_l_3f42;
	case 16202ULL: goto x86_l_3f4a;
	case 16205ULL: goto x86_l_3f4d;
	case 16213ULL: goto x86_l_3f55;
	case 16222ULL: goto x86_l_3f5e;
	case 16229ULL: goto x86_l_3f65;
	case 16234ULL: goto x86_l_3f6a;
	case 16239ULL: goto x86_l_3f6f;
	case 16244ULL: goto x86_l_3f74;
	case 16246ULL: goto x86_l_3f76;
	case 16248ULL: goto x86_l_3f78;
	case 16254ULL: goto x86_l_3f7e;
	case 16260ULL: goto x86_l_3f84;
	case 16263ULL: goto x86_l_3f87;
	case 16268ULL: goto x86_l_3f8c;
	case 16274ULL: goto x86_l_3f92;
	case 16279ULL: goto x86_l_3f97;
	case 16287ULL: goto x86_l_3f9f;
	case 16291ULL: goto x86_l_3fa3;
	case 16298ULL: goto x86_l_3faa;
	case 16303ULL: goto x86_l_3faf;
	case 16308ULL: goto x86_l_3fb4;
	case 16310ULL: goto x86_l_3fb6;
	case 16314ULL: goto x86_l_3fba;
	case 16316ULL: goto x86_l_3fbc;
	case 16318ULL: goto x86_l_3fbe;
	case 16324ULL: goto x86_l_3fc4;
	case 16327ULL: goto x86_l_3fc7;
	case 16332ULL: goto x86_l_3fcc;
	case 16338ULL: goto x86_l_3fd2;
	case 16343ULL: goto x86_l_3fd7;
	case 16351ULL: goto x86_l_3fdf;
	case 16355ULL: goto x86_l_3fe3;
	case 16362ULL: goto x86_l_3fea;
	case 16367ULL: goto x86_l_3fef;
	case 16372ULL: goto x86_l_3ff4;
	case 16374ULL: goto x86_l_3ff6;
	case 16379ULL: goto x86_l_3ffb;
	case 16387ULL: goto x86_l_4003;
	case 16390ULL: goto x86_l_4006;
	case 16398ULL: goto x86_l_400e;
	case 16407ULL: goto x86_l_4017;
	case 16414ULL: goto x86_l_401e;
	case 16419ULL: goto x86_l_4023;
	case 16424ULL: goto x86_l_4028;
	case 16429ULL: goto x86_l_402d;
	case 16431ULL: goto x86_l_402f;
	case 16433ULL: goto x86_l_4031;
	case 16439ULL: goto x86_l_4037;
	case 16445ULL: goto x86_l_403d;
	case 16448ULL: goto x86_l_4040;
	case 16453ULL: goto x86_l_4045;
	case 16459ULL: goto x86_l_404b;
	case 16464ULL: goto x86_l_4050;
	case 16472ULL: goto x86_l_4058;
	case 16476ULL: goto x86_l_405c;
	case 16483ULL: goto x86_l_4063;
	case 16488ULL: goto x86_l_4068;
	case 16493ULL: goto x86_l_406d;
	case 16495ULL: goto x86_l_406f;
	case 16499ULL: goto x86_l_4073;
	case 16501ULL: goto x86_l_4075;
	case 16503ULL: goto x86_l_4077;
	case 16509ULL: goto x86_l_407d;
	case 16512ULL: goto x86_l_4080;
	case 16517ULL: goto x86_l_4085;
	case 16523ULL: goto x86_l_408b;
	case 16528ULL: goto x86_l_4090;
	case 16536ULL: goto x86_l_4098;
	case 16540ULL: goto x86_l_409c;
	case 16547ULL: goto x86_l_40a3;
	case 16552ULL: goto x86_l_40a8;
	case 16557ULL: goto x86_l_40ad;
	case 16559ULL: goto x86_l_40af;
	case 16564ULL: goto x86_l_40b4;
	case 16572ULL: goto x86_l_40bc;
	case 16575ULL: goto x86_l_40bf;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3943:
	/* 0x3943: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3946:
	/* 0x3946: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_394b:
	/* 0x394b: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3951:
	/* 0x3951: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3956:
	/* 0x3956: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_395e:
	/* 0x395e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3962:
	/* 0x3962: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3969:
	/* 0x3969: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_396e:
	/* 0x396e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3973:
	/* 0x3973: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3975:
	/* 0x3975: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_397a:
	/* 0x397a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3982:
	/* 0x3982: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3985:
	/* 0x3985: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_398d:
	/* 0x398d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3996:
	/* 0x3996: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_399d:
	/* 0x399d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39a2:
	/* 0x39a2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39a7:
	/* 0x39a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39ac:
	/* 0x39ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39ae:
	/* 0x39ae: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_39b0:
	/* 0x39b0: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_39b6:
	/* 0x39b6: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_39bc:
	/* 0x39bc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_39bf:
	/* 0x39bf: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_39c4:
	/* 0x39c4: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_39ca:
	/* 0x39ca: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_39cf:
	/* 0x39cf: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_39d7:
	/* 0x39d7: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_39db:
	/* 0x39db: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_39e2:
	/* 0x39e2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39e7:
	/* 0x39e7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_39ec:
	/* 0x39ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39ee:
	/* 0x39ee: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_39f2:
	/* 0x39f2: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_39f4:
	/* 0x39f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39f6:
	/* 0x39f6: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_39fc:
	/* 0x39fc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_39ff:
	/* 0x39ff: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3a04:
	/* 0x3a04: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3a0a:
	/* 0x3a0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a0f:
	/* 0x3a0f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a17:
	/* 0x3a17: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3a1b:
	/* 0x3a1b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3a22:
	/* 0x3a22: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3a27:
	/* 0x3a27: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3a2c:
	/* 0x3a2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a2e:
	/* 0x3a2e: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3a33:
	/* 0x3a33: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3a3b:
	/* 0x3a3b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3a3e:
	/* 0x3a3e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3a46:
	/* 0x3a46: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3a4f:
	/* 0x3a4f: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3a56:
	/* 0x3a56: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a5b:
	/* 0x3a5b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a60:
	/* 0x3a60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a65:
	/* 0x3a65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a67:
	/* 0x3a67: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_3a69:
	/* 0x3a69: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3a6f:
	/* 0x3a6f: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3a75:
	/* 0x3a75: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a78:
	/* 0x3a78: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3a7d:
	/* 0x3a7d: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3a83:
	/* 0x3a83: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3a88:
	/* 0x3a88: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a90:
	/* 0x3a90: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3a94:
	/* 0x3a94: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3a9b:
	/* 0x3a9b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aa0:
	/* 0x3aa0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3aa5:
	/* 0x3aa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3aa7:
	/* 0x3aa7: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3aab:
	/* 0x3aab: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_3aad:
	/* 0x3aad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3aaf:
	/* 0x3aaf: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_3ab5:
	/* 0x3ab5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ab8:
	/* 0x3ab8: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3abd:
	/* 0x3abd: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3ac3:
	/* 0x3ac3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ac8:
	/* 0x3ac8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ad0:
	/* 0x3ad0: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3ad4:
	/* 0x3ad4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3adb:
	/* 0x3adb: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3ae0:
	/* 0x3ae0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ae5:
	/* 0x3ae5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ae7:
	/* 0x3ae7: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3aec:
	/* 0x3aec: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3af4:
	/* 0x3af4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3af7:
	/* 0x3af7: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3aff:
	/* 0x3aff: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3b08:
	/* 0x3b08: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3b0f:
	/* 0x3b0f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b14:
	/* 0x3b14: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b19:
	/* 0x3b19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b1e:
	/* 0x3b1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b20:
	/* 0x3b20: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_3b22:
	/* 0x3b22: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3b28:
	/* 0x3b28: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3b2e:
	/* 0x3b2e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b31:
	/* 0x3b31: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3b36:
	/* 0x3b36: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3b3c:
	/* 0x3b3c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3b41:
	/* 0x3b41: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b49:
	/* 0x3b49: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3b4d:
	/* 0x3b4d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b54:
	/* 0x3b54: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b59:
	/* 0x3b59: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3b5e:
	/* 0x3b5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b60:
	/* 0x3b60: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3b64:
	/* 0x3b64: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_3b66:
	/* 0x3b66: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b68:
	/* 0x3b68: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_3b6e:
	/* 0x3b6e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b71:
	/* 0x3b71: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3b76:
	/* 0x3b76: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3b7c:
	/* 0x3b7c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b81:
	/* 0x3b81: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b89:
	/* 0x3b89: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3b8d:
	/* 0x3b8d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3b94:
	/* 0x3b94: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3b99:
	/* 0x3b99: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b9e:
	/* 0x3b9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ba0:
	/* 0x3ba0: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3ba5:
	/* 0x3ba5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3bad:
	/* 0x3bad: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3bb0:
	/* 0x3bb0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3bb8:
	/* 0x3bb8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3bc1:
	/* 0x3bc1: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3bc8:
	/* 0x3bc8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3bcd:
	/* 0x3bcd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bd2:
	/* 0x3bd2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bd7:
	/* 0x3bd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bd9:
	/* 0x3bd9: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_3bdb:
	/* 0x3bdb: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3be1:
	/* 0x3be1: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3be7:
	/* 0x3be7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3bea:
	/* 0x3bea: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3bef:
	/* 0x3bef: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3bf5:
	/* 0x3bf5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3bfa:
	/* 0x3bfa: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c02:
	/* 0x3c02: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3c06:
	/* 0x3c06: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c0d:
	/* 0x3c0d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c12:
	/* 0x3c12: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3c17:
	/* 0x3c17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c19:
	/* 0x3c19: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3c1d:
	/* 0x3c1d: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_3c1f:
	/* 0x3c1f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c21:
	/* 0x3c21: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_3c27:
	/* 0x3c27: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c2a:
	/* 0x3c2a: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3c2f:
	/* 0x3c2f: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3c35:
	/* 0x3c35: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c3a:
	/* 0x3c3a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c42:
	/* 0x3c42: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3c46:
	/* 0x3c46: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3c4d:
	/* 0x3c4d: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3c52:
	/* 0x3c52: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c57:
	/* 0x3c57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c59:
	/* 0x3c59: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3c5e:
	/* 0x3c5e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3c66:
	/* 0x3c66: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3c69:
	/* 0x3c69: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3c71:
	/* 0x3c71: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3c7a:
	/* 0x3c7a: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3c81:
	/* 0x3c81: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c86:
	/* 0x3c86: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c8b:
	/* 0x3c8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c90:
	/* 0x3c90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c92:
	/* 0x3c92: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_3c94:
	/* 0x3c94: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3c9a:
	/* 0x3c9a: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3ca0:
	/* 0x3ca0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ca3:
	/* 0x3ca3: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3ca8:
	/* 0x3ca8: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3cae:
	/* 0x3cae: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3cb3:
	/* 0x3cb3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3cbb:
	/* 0x3cbb: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3cbf:
	/* 0x3cbf: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3cc6:
	/* 0x3cc6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ccb:
	/* 0x3ccb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3cd0:
	/* 0x3cd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cd2:
	/* 0x3cd2: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3cd6:
	/* 0x3cd6: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_3cd8:
	/* 0x3cd8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3cda:
	/* 0x3cda: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_3ce0:
	/* 0x3ce0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ce3:
	/* 0x3ce3: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3ce8:
	/* 0x3ce8: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3cee:
	/* 0x3cee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3cf3:
	/* 0x3cf3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3cfb:
	/* 0x3cfb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3cff:
	/* 0x3cff: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3d06:
	/* 0x3d06: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3d0b:
	/* 0x3d0b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d10:
	/* 0x3d10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d12:
	/* 0x3d12: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3d17:
	/* 0x3d17: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3d1f:
	/* 0x3d1f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3d22:
	/* 0x3d22: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3d2a:
	/* 0x3d2a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3d33:
	/* 0x3d33: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3d3a:
	/* 0x3d3a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d3f:
	/* 0x3d3f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d44:
	/* 0x3d44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d49:
	/* 0x3d49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d4b:
	/* 0x3d4b: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_3d4d:
	/* 0x3d4d: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3d53:
	/* 0x3d53: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3d59:
	/* 0x3d59: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d5c:
	/* 0x3d5c: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3d61:
	/* 0x3d61: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3d67:
	/* 0x3d67: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3d6c:
	/* 0x3d6c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d74:
	/* 0x3d74: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3d78:
	/* 0x3d78: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3d7f:
	/* 0x3d7f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d84:
	/* 0x3d84: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3d89:
	/* 0x3d89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d8b:
	/* 0x3d8b: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3d8f:
	/* 0x3d8f: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_3d91:
	/* 0x3d91: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d93:
	/* 0x3d93: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_3d99:
	/* 0x3d99: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d9c:
	/* 0x3d9c: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3da1:
	/* 0x3da1: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3da7:
	/* 0x3da7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3dac:
	/* 0x3dac: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3db4:
	/* 0x3db4: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3db8:
	/* 0x3db8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3dbf:
	/* 0x3dbf: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3dc4:
	/* 0x3dc4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3dc9:
	/* 0x3dc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dcb:
	/* 0x3dcb: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3dd0:
	/* 0x3dd0: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3dd8:
	/* 0x3dd8: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3ddb:
	/* 0x3ddb: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3de3:
	/* 0x3de3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3dec:
	/* 0x3dec: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_3df3:
	/* 0x3df3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3df8:
	/* 0x3df8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dfd:
	/* 0x3dfd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e02:
	/* 0x3e02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e04:
	/* 0x3e04: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_3e06:
	/* 0x3e06: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3e0c:
	/* 0x3e0c: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3e12:
	/* 0x3e12: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e15:
	/* 0x3e15: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3e1a:
	/* 0x3e1a: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3e20:
	/* 0x3e20: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3e25:
	/* 0x3e25: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e2d:
	/* 0x3e2d: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3e31:
	/* 0x3e31: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3e38:
	/* 0x3e38: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e3d:
	/* 0x3e3d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3e42:
	/* 0x3e42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e44:
	/* 0x3e44: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3e48:
	/* 0x3e48: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_3e4a:
	/* 0x3e4a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e4c:
	/* 0x3e4c: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_3e52:
	/* 0x3e52: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e55:
	/* 0x3e55: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3e5a:
	/* 0x3e5a: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3e60:
	/* 0x3e60: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e65:
	/* 0x3e65: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e6d:
	/* 0x3e6d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3e71:
	/* 0x3e71: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3e78:
	/* 0x3e78: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3e7d:
	/* 0x3e7d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e82:
	/* 0x3e82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e84:
	/* 0x3e84: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3e89:
	/* 0x3e89: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3e91:
	/* 0x3e91: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3e94:
	/* 0x3e94: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3e9c:
	/* 0x3e9c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ea5:
	/* 0x3ea5: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3eac:
	/* 0x3eac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3eb1:
	/* 0x3eb1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3eb6:
	/* 0x3eb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ebb:
	/* 0x3ebb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ebd:
	/* 0x3ebd: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_3ebf:
	/* 0x3ebf: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ec5:
	/* 0x3ec5: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3ecb:
	/* 0x3ecb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ece:
	/* 0x3ece: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3ed3:
	/* 0x3ed3: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3ed9:
	/* 0x3ed9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3ede:
	/* 0x3ede: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ee6:
	/* 0x3ee6: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3eea:
	/* 0x3eea: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3ef1:
	/* 0x3ef1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ef6:
	/* 0x3ef6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3efb:
	/* 0x3efb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3efd:
	/* 0x3efd: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3f01:
	/* 0x3f01: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_3f03:
	/* 0x3f03: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f05:
	/* 0x3f05: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_3f0b:
	/* 0x3f0b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f0e:
	/* 0x3f0e: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3f13:
	/* 0x3f13: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
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
	/* 0x3f31: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3f36:
	/* 0x3f36: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3f3b:
	/* 0x3f3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f3d:
	/* 0x3f3d: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3f42:
	/* 0x3f42: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3f4a:
	/* 0x3f4a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3f4d:
	/* 0x3f4d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3f55:
	/* 0x3f55: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3f5e:
	/* 0x3f5e: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_3f65:
	/* 0x3f65: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f6a:
	/* 0x3f6a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f6f:
	/* 0x3f6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f74:
	/* 0x3f74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f76:
	/* 0x3f76: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_3f78:
	/* 0x3f78: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3f7e:
	/* 0x3f7e: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_3f84:
	/* 0x3f84: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f87:
	/* 0x3f87: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3f8c:
	/* 0x3f8c: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3f92:
	/* 0x3f92: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3f97:
	/* 0x3f97: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3f9f:
	/* 0x3f9f: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3fa3:
	/* 0x3fa3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3faa:
	/* 0x3faa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3faf:
	/* 0x3faf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3fb4:
	/* 0x3fb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fb6:
	/* 0x3fb6: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3fba:
	/* 0x3fba: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_3fbc:
	/* 0x3fbc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3fbe:
	/* 0x3fbe: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_3fc4:
	/* 0x3fc4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3fc7:
	/* 0x3fc7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3fcc:
	/* 0x3fcc: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_3fd2:
	/* 0x3fd2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3fd7:
	/* 0x3fd7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3fdf:
	/* 0x3fdf: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3fe3:
	/* 0x3fe3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3fea:
	/* 0x3fea: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3fef:
	/* 0x3fef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ff4:
	/* 0x3ff4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ff6:
	/* 0x3ff6: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3ffb:
	/* 0x3ffb: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4003:
	/* 0x4003: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4006:
	/* 0x4006: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_400e:
	/* 0x400e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4017:
	/* 0x4017: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_401e:
	/* 0x401e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4023:
	/* 0x4023: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4028:
	/* 0x4028: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_402d:
	/* 0x402d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_402f:
	/* 0x402f: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_4031:
	/* 0x4031: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4037:
	/* 0x4037: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_403d:
	/* 0x403d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4040:
	/* 0x4040: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4045:
	/* 0x4045: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_404b:
	/* 0x404b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4050:
	/* 0x4050: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4058:
	/* 0x4058: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_405c:
	/* 0x405c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4063:
	/* 0x4063: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4068:
	/* 0x4068: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_406d:
	/* 0x406d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_406f:
	/* 0x406f: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4073:
	/* 0x4073: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_4075:
	/* 0x4075: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4077:
	/* 0x4077: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_407d:
	/* 0x407d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4080:
	/* 0x4080: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4085:
	/* 0x4085: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_408b:
	/* 0x408b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4090:
	/* 0x4090: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4098:
	/* 0x4098: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_409c:
	/* 0x409c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_40a3:
	/* 0x40a3: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_40a8:
	/* 0x40a8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_40ad:
	/* 0x40ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40af:
	/* 0x40af: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_40b4:
	/* 0x40b4: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_40bc:
	/* 0x40bc: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_40bf:
	/* 0x40bf: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
	return 16583ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16583ULL: goto x86_l_40c7;
	case 16592ULL: goto x86_l_40d0;
	case 16599ULL: goto x86_l_40d7;
	case 16604ULL: goto x86_l_40dc;
	case 16609ULL: goto x86_l_40e1;
	case 16614ULL: goto x86_l_40e6;
	case 16616ULL: goto x86_l_40e8;
	case 16618ULL: goto x86_l_40ea;
	case 16624ULL: goto x86_l_40f0;
	case 16630ULL: goto x86_l_40f6;
	case 16633ULL: goto x86_l_40f9;
	case 16638ULL: goto x86_l_40fe;
	case 16644ULL: goto x86_l_4104;
	case 16649ULL: goto x86_l_4109;
	case 16657ULL: goto x86_l_4111;
	case 16661ULL: goto x86_l_4115;
	case 16668ULL: goto x86_l_411c;
	case 16673ULL: goto x86_l_4121;
	case 16678ULL: goto x86_l_4126;
	case 16680ULL: goto x86_l_4128;
	case 16684ULL: goto x86_l_412c;
	case 16686ULL: goto x86_l_412e;
	case 16688ULL: goto x86_l_4130;
	case 16694ULL: goto x86_l_4136;
	case 16697ULL: goto x86_l_4139;
	case 16702ULL: goto x86_l_413e;
	case 16708ULL: goto x86_l_4144;
	case 16713ULL: goto x86_l_4149;
	case 16721ULL: goto x86_l_4151;
	case 16725ULL: goto x86_l_4155;
	case 16732ULL: goto x86_l_415c;
	case 16737ULL: goto x86_l_4161;
	case 16742ULL: goto x86_l_4166;
	case 16744ULL: goto x86_l_4168;
	case 16749ULL: goto x86_l_416d;
	case 16757ULL: goto x86_l_4175;
	case 16760ULL: goto x86_l_4178;
	case 16768ULL: goto x86_l_4180;
	case 16777ULL: goto x86_l_4189;
	case 16784ULL: goto x86_l_4190;
	case 16789ULL: goto x86_l_4195;
	case 16794ULL: goto x86_l_419a;
	case 16799ULL: goto x86_l_419f;
	case 16801ULL: goto x86_l_41a1;
	case 16803ULL: goto x86_l_41a3;
	case 16809ULL: goto x86_l_41a9;
	case 16815ULL: goto x86_l_41af;
	case 16818ULL: goto x86_l_41b2;
	case 16823ULL: goto x86_l_41b7;
	case 16829ULL: goto x86_l_41bd;
	case 16834ULL: goto x86_l_41c2;
	case 16842ULL: goto x86_l_41ca;
	case 16846ULL: goto x86_l_41ce;
	case 16853ULL: goto x86_l_41d5;
	case 16858ULL: goto x86_l_41da;
	case 16863ULL: goto x86_l_41df;
	case 16865ULL: goto x86_l_41e1;
	case 16869ULL: goto x86_l_41e5;
	case 16871ULL: goto x86_l_41e7;
	case 16873ULL: goto x86_l_41e9;
	case 16879ULL: goto x86_l_41ef;
	case 16882ULL: goto x86_l_41f2;
	case 16887ULL: goto x86_l_41f7;
	case 16893ULL: goto x86_l_41fd;
	case 16898ULL: goto x86_l_4202;
	case 16906ULL: goto x86_l_420a;
	case 16910ULL: goto x86_l_420e;
	case 16917ULL: goto x86_l_4215;
	case 16922ULL: goto x86_l_421a;
	case 16927ULL: goto x86_l_421f;
	case 16929ULL: goto x86_l_4221;
	case 16934ULL: goto x86_l_4226;
	case 16942ULL: goto x86_l_422e;
	case 16945ULL: goto x86_l_4231;
	case 16953ULL: goto x86_l_4239;
	case 16962ULL: goto x86_l_4242;
	case 16969ULL: goto x86_l_4249;
	case 16974ULL: goto x86_l_424e;
	case 16979ULL: goto x86_l_4253;
	case 16984ULL: goto x86_l_4258;
	case 16986ULL: goto x86_l_425a;
	case 16988ULL: goto x86_l_425c;
	case 16994ULL: goto x86_l_4262;
	case 17000ULL: goto x86_l_4268;
	case 17003ULL: goto x86_l_426b;
	case 17008ULL: goto x86_l_4270;
	case 17014ULL: goto x86_l_4276;
	case 17019ULL: goto x86_l_427b;
	case 17027ULL: goto x86_l_4283;
	case 17031ULL: goto x86_l_4287;
	case 17038ULL: goto x86_l_428e;
	case 17043ULL: goto x86_l_4293;
	case 17048ULL: goto x86_l_4298;
	case 17050ULL: goto x86_l_429a;
	case 17054ULL: goto x86_l_429e;
	case 17056ULL: goto x86_l_42a0;
	case 17058ULL: goto x86_l_42a2;
	case 17064ULL: goto x86_l_42a8;
	case 17067ULL: goto x86_l_42ab;
	case 17072ULL: goto x86_l_42b0;
	case 17078ULL: goto x86_l_42b6;
	case 17083ULL: goto x86_l_42bb;
	case 17091ULL: goto x86_l_42c3;
	case 17095ULL: goto x86_l_42c7;
	case 17102ULL: goto x86_l_42ce;
	case 17107ULL: goto x86_l_42d3;
	case 17112ULL: goto x86_l_42d8;
	case 17114ULL: goto x86_l_42da;
	case 17119ULL: goto x86_l_42df;
	case 17127ULL: goto x86_l_42e7;
	case 17130ULL: goto x86_l_42ea;
	case 17138ULL: goto x86_l_42f2;
	case 17147ULL: goto x86_l_42fb;
	case 17154ULL: goto x86_l_4302;
	case 17159ULL: goto x86_l_4307;
	case 17164ULL: goto x86_l_430c;
	case 17169ULL: goto x86_l_4311;
	case 17171ULL: goto x86_l_4313;
	case 17173ULL: goto x86_l_4315;
	case 17179ULL: goto x86_l_431b;
	case 17185ULL: goto x86_l_4321;
	case 17188ULL: goto x86_l_4324;
	case 17193ULL: goto x86_l_4329;
	case 17199ULL: goto x86_l_432f;
	case 17204ULL: goto x86_l_4334;
	case 17212ULL: goto x86_l_433c;
	case 17216ULL: goto x86_l_4340;
	case 17223ULL: goto x86_l_4347;
	case 17228ULL: goto x86_l_434c;
	case 17233ULL: goto x86_l_4351;
	case 17235ULL: goto x86_l_4353;
	case 17239ULL: goto x86_l_4357;
	case 17241ULL: goto x86_l_4359;
	case 17243ULL: goto x86_l_435b;
	case 17249ULL: goto x86_l_4361;
	case 17252ULL: goto x86_l_4364;
	case 17257ULL: goto x86_l_4369;
	case 17263ULL: goto x86_l_436f;
	case 17268ULL: goto x86_l_4374;
	case 17276ULL: goto x86_l_437c;
	case 17280ULL: goto x86_l_4380;
	case 17287ULL: goto x86_l_4387;
	case 17292ULL: goto x86_l_438c;
	case 17297ULL: goto x86_l_4391;
	case 17299ULL: goto x86_l_4393;
	case 17304ULL: goto x86_l_4398;
	case 17312ULL: goto x86_l_43a0;
	case 17315ULL: goto x86_l_43a3;
	case 17323ULL: goto x86_l_43ab;
	case 17332ULL: goto x86_l_43b4;
	case 17339ULL: goto x86_l_43bb;
	case 17344ULL: goto x86_l_43c0;
	case 17349ULL: goto x86_l_43c5;
	case 17354ULL: goto x86_l_43ca;
	case 17356ULL: goto x86_l_43cc;
	case 17358ULL: goto x86_l_43ce;
	case 17364ULL: goto x86_l_43d4;
	case 17370ULL: goto x86_l_43da;
	case 17373ULL: goto x86_l_43dd;
	case 17378ULL: goto x86_l_43e2;
	case 17384ULL: goto x86_l_43e8;
	case 17389ULL: goto x86_l_43ed;
	case 17397ULL: goto x86_l_43f5;
	case 17401ULL: goto x86_l_43f9;
	case 17408ULL: goto x86_l_4400;
	case 17413ULL: goto x86_l_4405;
	case 17418ULL: goto x86_l_440a;
	case 17420ULL: goto x86_l_440c;
	case 17424ULL: goto x86_l_4410;
	case 17426ULL: goto x86_l_4412;
	case 17428ULL: goto x86_l_4414;
	case 17434ULL: goto x86_l_441a;
	case 17437ULL: goto x86_l_441d;
	case 17442ULL: goto x86_l_4422;
	case 17448ULL: goto x86_l_4428;
	case 17453ULL: goto x86_l_442d;
	case 17461ULL: goto x86_l_4435;
	case 17465ULL: goto x86_l_4439;
	case 17472ULL: goto x86_l_4440;
	case 17477ULL: goto x86_l_4445;
	case 17482ULL: goto x86_l_444a;
	case 17484ULL: goto x86_l_444c;
	case 17489ULL: goto x86_l_4451;
	case 17497ULL: goto x86_l_4459;
	case 17500ULL: goto x86_l_445c;
	case 17508ULL: goto x86_l_4464;
	case 17517ULL: goto x86_l_446d;
	case 17524ULL: goto x86_l_4474;
	case 17529ULL: goto x86_l_4479;
	case 17534ULL: goto x86_l_447e;
	case 17539ULL: goto x86_l_4483;
	case 17541ULL: goto x86_l_4485;
	case 17543ULL: goto x86_l_4487;
	case 17549ULL: goto x86_l_448d;
	case 17555ULL: goto x86_l_4493;
	case 17558ULL: goto x86_l_4496;
	case 17563ULL: goto x86_l_449b;
	case 17569ULL: goto x86_l_44a1;
	case 17574ULL: goto x86_l_44a6;
	case 17582ULL: goto x86_l_44ae;
	case 17586ULL: goto x86_l_44b2;
	case 17593ULL: goto x86_l_44b9;
	case 17598ULL: goto x86_l_44be;
	case 17603ULL: goto x86_l_44c3;
	case 17605ULL: goto x86_l_44c5;
	case 17609ULL: goto x86_l_44c9;
	case 17611ULL: goto x86_l_44cb;
	case 17613ULL: goto x86_l_44cd;
	case 17619ULL: goto x86_l_44d3;
	case 17622ULL: goto x86_l_44d6;
	case 17627ULL: goto x86_l_44db;
	case 17633ULL: goto x86_l_44e1;
	case 17638ULL: goto x86_l_44e6;
	case 17646ULL: goto x86_l_44ee;
	case 17650ULL: goto x86_l_44f2;
	case 17657ULL: goto x86_l_44f9;
	case 17662ULL: goto x86_l_44fe;
	case 17667ULL: goto x86_l_4503;
	case 17669ULL: goto x86_l_4505;
	case 17674ULL: goto x86_l_450a;
	case 17682ULL: goto x86_l_4512;
	case 17685ULL: goto x86_l_4515;
	case 17693ULL: goto x86_l_451d;
	case 17702ULL: goto x86_l_4526;
	case 17709ULL: goto x86_l_452d;
	case 17714ULL: goto x86_l_4532;
	case 17719ULL: goto x86_l_4537;
	case 17724ULL: goto x86_l_453c;
	case 17726ULL: goto x86_l_453e;
	case 17728ULL: goto x86_l_4540;
	case 17734ULL: goto x86_l_4546;
	case 17740ULL: goto x86_l_454c;
	case 17743ULL: goto x86_l_454f;
	case 17748ULL: goto x86_l_4554;
	case 17754ULL: goto x86_l_455a;
	case 17759ULL: goto x86_l_455f;
	case 17767ULL: goto x86_l_4567;
	case 17771ULL: goto x86_l_456b;
	case 17778ULL: goto x86_l_4572;
	case 17783ULL: goto x86_l_4577;
	case 17788ULL: goto x86_l_457c;
	case 17790ULL: goto x86_l_457e;
	case 17794ULL: goto x86_l_4582;
	case 17796ULL: goto x86_l_4584;
	case 17798ULL: goto x86_l_4586;
	case 17804ULL: goto x86_l_458c;
	case 17807ULL: goto x86_l_458f;
	case 17812ULL: goto x86_l_4594;
	case 17818ULL: goto x86_l_459a;
	case 17823ULL: goto x86_l_459f;
	case 17831ULL: goto x86_l_45a7;
	case 17835ULL: goto x86_l_45ab;
	case 17842ULL: goto x86_l_45b2;
	case 17847ULL: goto x86_l_45b7;
	case 17852ULL: goto x86_l_45bc;
	case 17854ULL: goto x86_l_45be;
	case 17859ULL: goto x86_l_45c3;
	case 17867ULL: goto x86_l_45cb;
	case 17870ULL: goto x86_l_45ce;
	case 17878ULL: goto x86_l_45d6;
	case 17887ULL: goto x86_l_45df;
	case 17894ULL: goto x86_l_45e6;
	case 17899ULL: goto x86_l_45eb;
	case 17904ULL: goto x86_l_45f0;
	case 17909ULL: goto x86_l_45f5;
	case 17911ULL: goto x86_l_45f7;
	case 17913ULL: goto x86_l_45f9;
	case 17919ULL: goto x86_l_45ff;
	case 17925ULL: goto x86_l_4605;
	case 17928ULL: goto x86_l_4608;
	case 17933ULL: goto x86_l_460d;
	case 17939ULL: goto x86_l_4613;
	case 17944ULL: goto x86_l_4618;
	case 17952ULL: goto x86_l_4620;
	case 17956ULL: goto x86_l_4624;
	case 17963ULL: goto x86_l_462b;
	case 17968ULL: goto x86_l_4630;
	case 17973ULL: goto x86_l_4635;
	case 17975ULL: goto x86_l_4637;
	case 17979ULL: goto x86_l_463b;
	case 17981ULL: goto x86_l_463d;
	case 17983ULL: goto x86_l_463f;
	case 17989ULL: goto x86_l_4645;
	case 17992ULL: goto x86_l_4648;
	case 17997ULL: goto x86_l_464d;
	case 18003ULL: goto x86_l_4653;
	case 18008ULL: goto x86_l_4658;
	case 18016ULL: goto x86_l_4660;
	case 18020ULL: goto x86_l_4664;
	case 18027ULL: goto x86_l_466b;
	case 18032ULL: goto x86_l_4670;
	case 18037ULL: goto x86_l_4675;
	case 18039ULL: goto x86_l_4677;
	case 18044ULL: goto x86_l_467c;
	case 18052ULL: goto x86_l_4684;
	case 18055ULL: goto x86_l_4687;
	case 18063ULL: goto x86_l_468f;
	case 18072ULL: goto x86_l_4698;
	case 18079ULL: goto x86_l_469f;
	case 18084ULL: goto x86_l_46a4;
	case 18089ULL: goto x86_l_46a9;
	case 18094ULL: goto x86_l_46ae;
	case 18097ULL: goto x86_l_46b1;
	case 18099ULL: goto x86_l_46b3;
	case 18101ULL: goto x86_l_46b5;
	case 18107ULL: goto x86_l_46bb;
	case 18113ULL: goto x86_l_46c1;
	case 18116ULL: goto x86_l_46c4;
	case 18121ULL: goto x86_l_46c9;
	case 18127ULL: goto x86_l_46cf;
	case 18132ULL: goto x86_l_46d4;
	case 18140ULL: goto x86_l_46dc;
	case 18144ULL: goto x86_l_46e0;
	case 18151ULL: goto x86_l_46e7;
	case 18156ULL: goto x86_l_46ec;
	case 18161ULL: goto x86_l_46f1;
	case 18163ULL: goto x86_l_46f3;
	case 18167ULL: goto x86_l_46f7;
	case 18169ULL: goto x86_l_46f9;
	case 18171ULL: goto x86_l_46fb;
	case 18177ULL: goto x86_l_4701;
	case 18180ULL: goto x86_l_4704;
	case 18185ULL: goto x86_l_4709;
	case 18191ULL: goto x86_l_470f;
	case 18196ULL: goto x86_l_4714;
	case 18204ULL: goto x86_l_471c;
	case 18208ULL: goto x86_l_4720;
	case 18215ULL: goto x86_l_4727;
	case 18220ULL: goto x86_l_472c;
	case 18225ULL: goto x86_l_4731;
	case 18227ULL: goto x86_l_4733;
	case 18232ULL: goto x86_l_4738;
	case 18240ULL: goto x86_l_4740;
	case 18243ULL: goto x86_l_4743;
	case 18251ULL: goto x86_l_474b;
	case 18262ULL: goto x86_l_4756;
	case 18265ULL: goto x86_l_4759;
	case 18270ULL: goto x86_l_475e;
	case 18272ULL: goto x86_l_4760;
	case 18277ULL: goto x86_l_4765;
	case 18282ULL: goto x86_l_476a;
	case 18290ULL: goto x86_l_4772;
	case 18294ULL: goto x86_l_4776;
	case 18301ULL: goto x86_l_477d;
	case 18309ULL: goto x86_l_4785;
	case 18314ULL: goto x86_l_478a;
	case 18316ULL: goto x86_l_478c;
	case 18320ULL: goto x86_l_4790;
	case 18322ULL: goto x86_l_4792;
	case 18324ULL: goto x86_l_4794;
	case 18330ULL: goto x86_l_479a;
	case 18333ULL: goto x86_l_479d;
	case 18338ULL: goto x86_l_47a2;
	case 18343ULL: goto x86_l_47a7;
	case 18349ULL: goto x86_l_47ad;
	case 18354ULL: goto x86_l_47b2;
	case 18362ULL: goto x86_l_47ba;
	case 18366ULL: goto x86_l_47be;
	case 18373ULL: goto x86_l_47c5;
	case 18378ULL: goto x86_l_47ca;
	case 18383ULL: goto x86_l_47cf;
	case 18385ULL: goto x86_l_47d1;
	case 18390ULL: goto x86_l_47d6;
	case 18398ULL: goto x86_l_47de;
	case 18401ULL: goto x86_l_47e1;
	case 18409ULL: goto x86_l_47e9;
	case 18411ULL: goto x86_l_47eb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_40c7:
	/* 0x40c7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_40d0:
	/* 0x40d0: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_40d7:
	/* 0x40d7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_40dc:
	/* 0x40dc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40e1:
	/* 0x40e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40e6:
	/* 0x40e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40e8:
	/* 0x40e8: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_40ea:
	/* 0x40ea: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_40f0:
	/* 0x40f0: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_40f6:
	/* 0x40f6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_40f9:
	/* 0x40f9: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_40fe:
	/* 0x40fe: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_4104:
	/* 0x4104: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4109:
	/* 0x4109: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4111:
	/* 0x4111: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4115:
	/* 0x4115: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_411c:
	/* 0x411c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4121:
	/* 0x4121: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4126:
	/* 0x4126: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4128:
	/* 0x4128: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_412c:
	/* 0x412c: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_412e:
	/* 0x412e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4130:
	/* 0x4130: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_4136:
	/* 0x4136: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4139:
	/* 0x4139: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_413e:
	/* 0x413e: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_4144:
	/* 0x4144: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4149:
	/* 0x4149: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4151:
	/* 0x4151: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4155:
	/* 0x4155: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_415c:
	/* 0x415c: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4161:
	/* 0x4161: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4166:
	/* 0x4166: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4168:
	/* 0x4168: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_416d:
	/* 0x416d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4175:
	/* 0x4175: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4178:
	/* 0x4178: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4180:
	/* 0x4180: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4189:
	/* 0x4189: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_4190:
	/* 0x4190: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4195:
	/* 0x4195: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_419a:
	/* 0x419a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_419f:
	/* 0x419f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41a1:
	/* 0x41a1: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_41a3:
	/* 0x41a3: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_41a9:
	/* 0x41a9: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_41af:
	/* 0x41af: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41b2:
	/* 0x41b2: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_41b7:
	/* 0x41b7: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_41bd:
	/* 0x41bd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_41c2:
	/* 0x41c2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_41ca:
	/* 0x41ca: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_41ce:
	/* 0x41ce: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_41d5:
	/* 0x41d5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41da:
	/* 0x41da: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_41df:
	/* 0x41df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41e1:
	/* 0x41e1: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_41e5:
	/* 0x41e5: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_41e7:
	/* 0x41e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41e9:
	/* 0x41e9: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_41ef:
	/* 0x41ef: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41f2:
	/* 0x41f2: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_41f7:
	/* 0x41f7: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_41fd:
	/* 0x41fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4202:
	/* 0x4202: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_420a:
	/* 0x420a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_420e:
	/* 0x420e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4215:
	/* 0x4215: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_421a:
	/* 0x421a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_421f:
	/* 0x421f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4221:
	/* 0x4221: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4226:
	/* 0x4226: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_422e:
	/* 0x422e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4231:
	/* 0x4231: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4239:
	/* 0x4239: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4242:
	/* 0x4242: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_4249:
	/* 0x4249: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_424e:
	/* 0x424e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4253:
	/* 0x4253: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4258:
	/* 0x4258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_425a:
	/* 0x425a: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_425c:
	/* 0x425c: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4262:
	/* 0x4262: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_4268:
	/* 0x4268: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_426b:
	/* 0x426b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4270:
	/* 0x4270: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_4276:
	/* 0x4276: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_427b:
	/* 0x427b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4283:
	/* 0x4283: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4287:
	/* 0x4287: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_428e:
	/* 0x428e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4293:
	/* 0x4293: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4298:
	/* 0x4298: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_429a:
	/* 0x429a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_429e:
	/* 0x429e: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_42a0:
	/* 0x42a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42a2:
	/* 0x42a2: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_42a8:
	/* 0x42a8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_42ab:
	/* 0x42ab: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_42b0:
	/* 0x42b0: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_42b6:
	/* 0x42b6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_42bb:
	/* 0x42bb: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_42c3:
	/* 0x42c3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_42c7:
	/* 0x42c7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_42ce:
	/* 0x42ce: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_42d3:
	/* 0x42d3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_42d8:
	/* 0x42d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42da:
	/* 0x42da: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_42df:
	/* 0x42df: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_42e7:
	/* 0x42e7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_42ea:
	/* 0x42ea: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_42f2:
	/* 0x42f2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_42fb:
	/* 0x42fb: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_4302:
	/* 0x4302: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4307:
	/* 0x4307: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_430c:
	/* 0x430c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4311:
	/* 0x4311: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4313:
	/* 0x4313: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_4315:
	/* 0x4315: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_431b:
	/* 0x431b: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_4321:
	/* 0x4321: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4324:
	/* 0x4324: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4329:
	/* 0x4329: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_432f:
	/* 0x432f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4334:
	/* 0x4334: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_433c:
	/* 0x433c: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4340:
	/* 0x4340: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4347:
	/* 0x4347: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_434c:
	/* 0x434c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4351:
	/* 0x4351: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4353:
	/* 0x4353: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4357:
	/* 0x4357: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_4359:
	/* 0x4359: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_435b:
	/* 0x435b: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_4361:
	/* 0x4361: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4364:
	/* 0x4364: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4369:
	/* 0x4369: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_436f:
	/* 0x436f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4374:
	/* 0x4374: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_437c:
	/* 0x437c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4380:
	/* 0x4380: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4387:
	/* 0x4387: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_438c:
	/* 0x438c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4391:
	/* 0x4391: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4393:
	/* 0x4393: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4398:
	/* 0x4398: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_43a0:
	/* 0x43a0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_43a3:
	/* 0x43a3: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_43ab:
	/* 0x43ab: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_43b4:
	/* 0x43b4: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_43bb:
	/* 0x43bb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_43c0:
	/* 0x43c0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43c5:
	/* 0x43c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43ca:
	/* 0x43ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43cc:
	/* 0x43cc: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_43ce:
	/* 0x43ce: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_43d4:
	/* 0x43d4: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_43da:
	/* 0x43da: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_43dd:
	/* 0x43dd: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_43e2:
	/* 0x43e2: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_43e8:
	/* 0x43e8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_43ed:
	/* 0x43ed: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_43f5:
	/* 0x43f5: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_43f9:
	/* 0x43f9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4400:
	/* 0x4400: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4405:
	/* 0x4405: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_440a:
	/* 0x440a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_440c:
	/* 0x440c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4410:
	/* 0x4410: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_4412:
	/* 0x4412: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4414:
	/* 0x4414: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_441a:
	/* 0x441a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_441d:
	/* 0x441d: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4422:
	/* 0x4422: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_4428:
	/* 0x4428: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_442d:
	/* 0x442d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4435:
	/* 0x4435: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4439:
	/* 0x4439: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4440:
	/* 0x4440: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4445:
	/* 0x4445: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_444a:
	/* 0x444a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_444c:
	/* 0x444c: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4451:
	/* 0x4451: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4459:
	/* 0x4459: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_445c:
	/* 0x445c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4464:
	/* 0x4464: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_446d:
	/* 0x446d: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_4474:
	/* 0x4474: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4479:
	/* 0x4479: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_447e:
	/* 0x447e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4483:
	/* 0x4483: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4485:
	/* 0x4485: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_4487:
	/* 0x4487: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_448d:
	/* 0x448d: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_4493:
	/* 0x4493: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4496:
	/* 0x4496: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_449b:
	/* 0x449b: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_44a1:
	/* 0x44a1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_44a6:
	/* 0x44a6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_44ae:
	/* 0x44ae: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_44b2:
	/* 0x44b2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_44b9:
	/* 0x44b9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44be:
	/* 0x44be: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_44c3:
	/* 0x44c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44c5:
	/* 0x44c5: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_44c9:
	/* 0x44c9: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_44cb:
	/* 0x44cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44cd:
	/* 0x44cd: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_44d3:
	/* 0x44d3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_44d6:
	/* 0x44d6: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_44db:
	/* 0x44db: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_44e1:
	/* 0x44e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_44e6:
	/* 0x44e6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_44ee:
	/* 0x44ee: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_44f2:
	/* 0x44f2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_44f9:
	/* 0x44f9: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_44fe:
	/* 0x44fe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4503:
	/* 0x4503: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4505:
	/* 0x4505: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_450a:
	/* 0x450a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4512:
	/* 0x4512: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4515:
	/* 0x4515: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_451d:
	/* 0x451d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4526:
	/* 0x4526: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_452d:
	/* 0x452d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4532:
	/* 0x4532: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4537:
	/* 0x4537: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_453c:
	/* 0x453c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_453e:
	/* 0x453e: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_4540:
	/* 0x4540: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4546:
	/* 0x4546: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_454c:
	/* 0x454c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_454f:
	/* 0x454f: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4554:
	/* 0x4554: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_455a:
	/* 0x455a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_455f:
	/* 0x455f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4567:
	/* 0x4567: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_456b:
	/* 0x456b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4572:
	/* 0x4572: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4577:
	/* 0x4577: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_457c:
	/* 0x457c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_457e:
	/* 0x457e: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4582:
	/* 0x4582: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_4584:
	/* 0x4584: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4586:
	/* 0x4586: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_458c:
	/* 0x458c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_458f:
	/* 0x458f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4594:
	/* 0x4594: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_459a:
	/* 0x459a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_459f:
	/* 0x459f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_45a7:
	/* 0x45a7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_45ab:
	/* 0x45ab: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_45b2:
	/* 0x45b2: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_45b7:
	/* 0x45b7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_45bc:
	/* 0x45bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45be:
	/* 0x45be: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_45c3:
	/* 0x45c3: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_45cb:
	/* 0x45cb: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_45ce:
	/* 0x45ce: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_45d6:
	/* 0x45d6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_45df:
	/* 0x45df: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_45e6:
	/* 0x45e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_45eb:
	/* 0x45eb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45f0:
	/* 0x45f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45f5:
	/* 0x45f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45f7:
	/* 0x45f7: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_45f9:
	/* 0x45f9: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_45ff:
	/* 0x45ff: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_4605:
	/* 0x4605: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4608:
	/* 0x4608: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_460d:
	/* 0x460d: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_4613:
	/* 0x4613: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4618:
	/* 0x4618: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4620:
	/* 0x4620: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4624:
	/* 0x4624: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_462b:
	/* 0x462b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4630:
	/* 0x4630: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4635:
	/* 0x4635: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4637:
	/* 0x4637: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_463b:
	/* 0x463b: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_463d:
	/* 0x463d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_463f:
	/* 0x463f: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_4645:
	/* 0x4645: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4648:
	/* 0x4648: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_464d:
	/* 0x464d: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_4653:
	/* 0x4653: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4658:
	/* 0x4658: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4660:
	/* 0x4660: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4664:
	/* 0x4664: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_466b:
	/* 0x466b: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4670:
	/* 0x4670: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4675:
	/* 0x4675: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4677:
	/* 0x4677: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_467c:
	/* 0x467c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4684:
	/* 0x4684: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4687:
	/* 0x4687: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_468f:
	/* 0x468f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4698:
	/* 0x4698: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_469f:
	/* 0x469f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_46a4:
	/* 0x46a4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46a9:
	/* 0x46a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46ae:
	/* 0x46ae: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_46b1:
	/* 0x46b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46b3:
	/* 0x46b3: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_46b5:
	/* 0x46b5: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_46bb:
	/* 0x46bb: je     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2920ULL;
	}
x86_l_46c1:
	/* 0x46c1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_46c4:
	/* 0x46c4: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_46c9:
	/* 0x46c9: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_46cf:
	/* 0x46cf: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_46d4:
	/* 0x46d4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_46dc:
	/* 0x46dc: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_46e0:
	/* 0x46e0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_46e7:
	/* 0x46e7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46ec:
	/* 0x46ec: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_46f1:
	/* 0x46f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46f3:
	/* 0x46f3: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_46f7:
	/* 0x46f7: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_46f9:
	/* 0x46f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46fb:
	/* 0x46fb: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_4701:
	/* 0x4701: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4704:
	/* 0x4704: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4709:
	/* 0x4709: ja     b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2920ULL;
	}
x86_l_470f:
	/* 0x470f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4714:
	/* 0x4714: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_471c:
	/* 0x471c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4720:
	/* 0x4720: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4727:
	/* 0x4727: lea    rdx,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_472c:
	/* 0x472c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4731:
	/* 0x4731: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4733:
	/* 0x4733: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4738:
	/* 0x4738: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4740:
	/* 0x4740: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4743:
	/* 0x4743: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_474b:
	/* 0x474b: mov    DWORD PTR [rsp+0xa4],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704377663022ULL);
x86_l_4756:
	/* 0x4756: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_4759:
	/* 0x4759: cmp    eax,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27901ULL);
x86_l_475e:
	/* 0x475e: jb     4765 <syscall__execveat_enter+0x4765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4765;
	}
x86_l_4760:
	/* 0x4760: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_4765:
	/* 0x4765: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_476a:
	/* 0x476a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4772:
	/* 0x4772: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_4776:
	/* 0x4776: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_477d:
	/* 0x477d: lea    rdx,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_4785:
	/* 0x4785: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_478a:
	/* 0x478a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_478c:
	/* 0x478c: mov    DWORD PTR [rsp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_4790:
	/* 0x4790: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_4792:
	/* 0x4792: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4794:
	/* 0x4794: jle    b68 <syscall__execveat_enter+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2920ULL;
	}
x86_l_479a:
	/* 0x479a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_479d:
	/* 0x479d: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_47a2:
	/* 0x47a2: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_47a7:
	/* 0x47a7: ja     b6d <syscall__execveat_enter+0xb6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2925ULL;
	}
x86_l_47ad:
	/* 0x47ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_47b2:
	/* 0x47b2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_47ba:
	/* 0x47ba: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_47be:
	/* 0x47be: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_47c5:
	/* 0x47c5: lea    rdx,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_47ca:
	/* 0x47ca: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_47cf:
	/* 0x47cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47d1:
	/* 0x47d1: movzx  eax,WORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 124ULL);
x86_l_47d6:
	/* 0x47d6: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_47de:
	/* 0x47de: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_47e1:
	/* 0x47e1: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_47e9:
	/* 0x47e9: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_47eb:
	/* 0x47eb: jmp    b6d <syscall__execveat_enter+0xb6d> */
	return 2925ULL;
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
	for (__u32 __x86_iter = 0; __x86_iter < 15292U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1722ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1725ULL && __x86_pc <= 3410ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3412ULL && __x86_pc <= 5135ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5140ULL && __x86_pc <= 7026ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7031ULL && __x86_pc <= 8940ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8945ULL && __x86_pc <= 10870ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10877ULL && __x86_pc <= 12760ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12766ULL && __x86_pc <= 14653ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14659ULL && __x86_pc <= 16575ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16583ULL && __x86_pc <= 18411ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_9(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

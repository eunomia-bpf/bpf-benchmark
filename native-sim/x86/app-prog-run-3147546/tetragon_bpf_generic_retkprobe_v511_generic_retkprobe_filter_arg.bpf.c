extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
extern char filter_map;
extern char heap_ro_zero;
extern char process_call_heap;
extern char retkprobe_calls;
extern char retprobe_map;
extern char string_maps_0;
extern char string_maps_1;
extern char string_maps_10;
extern char string_maps_2;
extern char string_maps_3;
extern char string_maps_4;
extern char string_maps_5;
extern char string_maps_6;
extern char string_maps_7;
extern char string_maps_8;
extern char string_maps_9;
extern char string_maps_heap;
extern char string_postfix_maps;
extern char string_postfix_maps_heap;
extern char string_prefix_maps;
extern char string_prefix_maps_heap;
extern char substring_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 24ULL: goto x86_l_18;
	case 31ULL: goto x86_l_1f;
	case 39ULL: goto x86_l_27;
	case 44ULL: goto x86_l_2c;
	case 46ULL: goto x86_l_2e;
	case 49ULL: goto x86_l_31;
	case 55ULL: goto x86_l_37;
	case 58ULL: goto x86_l_3a;
	case 65ULL: goto x86_l_41;
	case 72ULL: goto x86_l_48;
	case 79ULL: goto x86_l_4f;
	case 84ULL: goto x86_l_54;
	case 86ULL: goto x86_l_56;
	case 89ULL: goto x86_l_59;
	case 95ULL: goto x86_l_5f;
	case 103ULL: goto x86_l_67;
	case 109ULL: goto x86_l_6d;
	case 112ULL: goto x86_l_70;
	case 120ULL: goto x86_l_78;
	case 123ULL: goto x86_l_7b;
	case 126ULL: goto x86_l_7e;
	case 135ULL: goto x86_l_87;
	case 137ULL: goto x86_l_89;
	case 139ULL: goto x86_l_8b;
	case 143ULL: goto x86_l_8f;
	case 147ULL: goto x86_l_93;
	case 151ULL: goto x86_l_97;
	case 154ULL: goto x86_l_9a;
	case 161ULL: goto x86_l_a1;
	case 166ULL: goto x86_l_a6;
	case 168ULL: goto x86_l_a8;
	case 172ULL: goto x86_l_ac;
	case 178ULL: goto x86_l_b2;
	case 181ULL: goto x86_l_b5;
	case 187ULL: goto x86_l_bb;
	case 195ULL: goto x86_l_c3;
	case 198ULL: goto x86_l_c6;
	case 200ULL: goto x86_l_c8;
	case 203ULL: goto x86_l_cb;
	case 209ULL: goto x86_l_d1;
	case 211ULL: goto x86_l_d3;
	case 217ULL: goto x86_l_d9;
	case 220ULL: goto x86_l_dc;
	case 226ULL: goto x86_l_e2;
	case 228ULL: goto x86_l_e4;
	case 231ULL: goto x86_l_e7;
	case 237ULL: goto x86_l_ed;
	case 240ULL: goto x86_l_f0;
	case 246ULL: goto x86_l_f6;
	case 249ULL: goto x86_l_f9;
	case 255ULL: goto x86_l_ff;
	case 258ULL: goto x86_l_102;
	case 264ULL: goto x86_l_108;
	case 266ULL: goto x86_l_10a;
	case 271ULL: goto x86_l_10f;
	case 275ULL: goto x86_l_113;
	case 283ULL: goto x86_l_11b;
	case 286ULL: goto x86_l_11e;
	case 291ULL: goto x86_l_123;
	case 296ULL: goto x86_l_128;
	case 304ULL: goto x86_l_130;
	case 308ULL: goto x86_l_134;
	case 313ULL: goto x86_l_139;
	case 318ULL: goto x86_l_13e;
	case 323ULL: goto x86_l_143;
	case 330ULL: goto x86_l_14a;
	case 337ULL: goto x86_l_151;
	case 342ULL: goto x86_l_156;
	case 347ULL: goto x86_l_15b;
	case 350ULL: goto x86_l_15e;
	case 355ULL: goto x86_l_163;
	case 357ULL: goto x86_l_165;
	case 364ULL: goto x86_l_16c;
	case 369ULL: goto x86_l_171;
	case 374ULL: goto x86_l_176;
	case 377ULL: goto x86_l_179;
	case 382ULL: goto x86_l_17e;
	case 384ULL: goto x86_l_180;
	case 386ULL: goto x86_l_182;
	case 393ULL: goto x86_l_189;
	case 395ULL: goto x86_l_18b;
	case 396ULL: goto x86_l_18c;
	case 401ULL: goto x86_l_191;
	case 403ULL: goto x86_l_193;
	case 411ULL: goto x86_l_19b;
	case 413ULL: goto x86_l_19d;
	case 418ULL: goto x86_l_1a2;
	case 426ULL: goto x86_l_1aa;
	case 428ULL: goto x86_l_1ac;
	case 433ULL: goto x86_l_1b1;
	case 441ULL: goto x86_l_1b9;
	case 443ULL: goto x86_l_1bb;
	case 448ULL: goto x86_l_1c0;
	case 456ULL: goto x86_l_1c8;
	case 458ULL: goto x86_l_1ca;
	case 463ULL: goto x86_l_1cf;
	case 471ULL: goto x86_l_1d7;
	case 473ULL: goto x86_l_1d9;
	case 478ULL: goto x86_l_1de;
	case 486ULL: goto x86_l_1e6;
	case 488ULL: goto x86_l_1e8;
	case 495ULL: goto x86_l_1ef;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 512ULL: goto x86_l_200;
	case 515ULL: goto x86_l_203;
	case 520ULL: goto x86_l_208;
	case 522ULL: goto x86_l_20a;
	case 526ULL: goto x86_l_20e;
	case 531ULL: goto x86_l_213;
	case 533ULL: goto x86_l_215;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 550ULL: goto x86_l_226;
	case 555ULL: goto x86_l_22b;
	case 560ULL: goto x86_l_230;
	case 562ULL: goto x86_l_232;
	case 565ULL: goto x86_l_235;
	case 571ULL: goto x86_l_23b;
	case 578ULL: goto x86_l_242;
	case 583ULL: goto x86_l_247;
	case 588ULL: goto x86_l_24c;
	case 590ULL: goto x86_l_24e;
	case 595ULL: goto x86_l_253;
	case 597ULL: goto x86_l_255;
	case 600ULL: goto x86_l_258;
	case 603ULL: goto x86_l_25b;
	case 606ULL: goto x86_l_25e;
	case 614ULL: goto x86_l_266;
	case 620ULL: goto x86_l_26c;
	case 623ULL: goto x86_l_26f;
	case 627ULL: goto x86_l_273;
	case 633ULL: goto x86_l_279;
	case 641ULL: goto x86_l_281;
	case 646ULL: goto x86_l_286;
	case 653ULL: goto x86_l_28d;
	case 659ULL: goto x86_l_293;
	case 662ULL: goto x86_l_296;
	case 669ULL: goto x86_l_29d;
	case 674ULL: goto x86_l_2a2;
	case 677ULL: goto x86_l_2a5;
	case 683ULL: goto x86_l_2ab;
	case 686ULL: goto x86_l_2ae;
	case 690ULL: goto x86_l_2b2;
	case 694ULL: goto x86_l_2b6;
	case 700ULL: goto x86_l_2bc;
	case 709ULL: goto x86_l_2c5;
	case 715ULL: goto x86_l_2cb;
	case 723ULL: goto x86_l_2d3;
	case 729ULL: goto x86_l_2d9;
	case 733ULL: goto x86_l_2dd;
	case 740ULL: goto x86_l_2e4;
	case 745ULL: goto x86_l_2e9;
	case 748ULL: goto x86_l_2ec;
	case 750ULL: goto x86_l_2ee;
	case 753ULL: goto x86_l_2f1;
	case 755ULL: goto x86_l_2f3;
	case 758ULL: goto x86_l_2f6;
	case 761ULL: goto x86_l_2f9;
	case 767ULL: goto x86_l_2ff;
	case 770ULL: goto x86_l_302;
	case 776ULL: goto x86_l_308;
	case 781ULL: goto x86_l_30d;
	case 784ULL: goto x86_l_310;
	case 786ULL: goto x86_l_312;
	case 789ULL: goto x86_l_315;
	case 792ULL: goto x86_l_318;
	case 794ULL: goto x86_l_31a;
	case 797ULL: goto x86_l_31d;
	case 800ULL: goto x86_l_320;
	case 806ULL: goto x86_l_326;
	case 809ULL: goto x86_l_329;
	case 815ULL: goto x86_l_32f;
	case 819ULL: goto x86_l_333;
	case 824ULL: goto x86_l_338;
	case 827ULL: goto x86_l_33b;
	case 833ULL: goto x86_l_341;
	case 836ULL: goto x86_l_344;
	case 839ULL: goto x86_l_347;
	case 845ULL: goto x86_l_34d;
	case 848ULL: goto x86_l_350;
	case 851ULL: goto x86_l_353;
	case 857ULL: goto x86_l_359;
	case 862ULL: goto x86_l_35e;
	case 865ULL: goto x86_l_361;
	case 871ULL: goto x86_l_367;
	case 874ULL: goto x86_l_36a;
	case 876ULL: goto x86_l_36c;
	case 879ULL: goto x86_l_36f;
	case 885ULL: goto x86_l_375;
	case 888ULL: goto x86_l_378;
	case 894ULL: goto x86_l_37e;
	case 897ULL: goto x86_l_381;
	case 903ULL: goto x86_l_387;
	case 906ULL: goto x86_l_38a;
	case 912ULL: goto x86_l_390;
	case 914ULL: goto x86_l_392;
	case 924ULL: goto x86_l_39c;
	case 928ULL: goto x86_l_3a0;
	case 934ULL: goto x86_l_3a6;
	case 939ULL: goto x86_l_3ab;
	case 943ULL: goto x86_l_3af;
	case 949ULL: goto x86_l_3b5;
	case 959ULL: goto x86_l_3bf;
	case 963ULL: goto x86_l_3c3;
	case 969ULL: goto x86_l_3c9;
	case 972ULL: goto x86_l_3cc;
	case 978ULL: goto x86_l_3d2;
	case 980ULL: goto x86_l_3d4;
	case 985ULL: goto x86_l_3d9;
	case 989ULL: goto x86_l_3dd;
	case 995ULL: goto x86_l_3e3;
	case 1000ULL: goto x86_l_3e8;
	case 1003ULL: goto x86_l_3eb;
	case 1009ULL: goto x86_l_3f1;
	case 1012ULL: goto x86_l_3f4;
	case 1015ULL: goto x86_l_3f7;
	case 1021ULL: goto x86_l_3fd;
	case 1026ULL: goto x86_l_402;
	case 1028ULL: goto x86_l_404;
	case 1034ULL: goto x86_l_40a;
	case 1039ULL: goto x86_l_40f;
	case 1042ULL: goto x86_l_412;
	case 1045ULL: goto x86_l_415;
	case 1051ULL: goto x86_l_41b;
	case 1054ULL: goto x86_l_41e;
	case 1060ULL: goto x86_l_424;
	case 1063ULL: goto x86_l_427;
	case 1069ULL: goto x86_l_42d;
	case 1074ULL: goto x86_l_432;
	case 1077ULL: goto x86_l_435;
	case 1079ULL: goto x86_l_437;
	case 1082ULL: goto x86_l_43a;
	case 1084ULL: goto x86_l_43c;
	case 1087ULL: goto x86_l_43f;
	case 1093ULL: goto x86_l_445;
	case 1102ULL: goto x86_l_44e;
	case 1111ULL: goto x86_l_457;
	case 1120ULL: goto x86_l_460;
	case 1129ULL: goto x86_l_469;
	case 1138ULL: goto x86_l_472;
	case 1141ULL: goto x86_l_475;
	case 1147ULL: goto x86_l_47b;
	case 1150ULL: goto x86_l_47e;
	case 1156ULL: goto x86_l_484;
	case 1159ULL: goto x86_l_487;
	case 1164ULL: goto x86_l_48c;
	case 1167ULL: goto x86_l_48f;
	case 1173ULL: goto x86_l_495;
	case 1178ULL: goto x86_l_49a;
	case 1182ULL: goto x86_l_49e;
	case 1186ULL: goto x86_l_4a2;
	case 1189ULL: goto x86_l_4a5;
	case 1195ULL: goto x86_l_4ab;
	case 1198ULL: goto x86_l_4ae;
	case 1201ULL: goto x86_l_4b1;
	case 1207ULL: goto x86_l_4b7;
	case 1210ULL: goto x86_l_4ba;
	case 1216ULL: goto x86_l_4c0;
	case 1221ULL: goto x86_l_4c5;
	case 1224ULL: goto x86_l_4c8;
	case 1230ULL: goto x86_l_4ce;
	case 1235ULL: goto x86_l_4d3;
	case 1238ULL: goto x86_l_4d6;
	case 1244ULL: goto x86_l_4dc;
	case 1247ULL: goto x86_l_4df;
	case 1253ULL: goto x86_l_4e5;
	case 1256ULL: goto x86_l_4e8;
	case 1259ULL: goto x86_l_4eb;
	case 1265ULL: goto x86_l_4f1;
	case 1268ULL: goto x86_l_4f4;
	case 1274ULL: goto x86_l_4fa;
	case 1279ULL: goto x86_l_4ff;
	case 1282ULL: goto x86_l_502;
	case 1288ULL: goto x86_l_508;
	case 1291ULL: goto x86_l_50b;
	case 1297ULL: goto x86_l_511;
	case 1301ULL: goto x86_l_515;
	case 1306ULL: goto x86_l_51a;
	case 1310ULL: goto x86_l_51e;
	case 1313ULL: goto x86_l_521;
	case 1319ULL: goto x86_l_527;
	case 1322ULL: goto x86_l_52a;
	case 1325ULL: goto x86_l_52d;
	case 1331ULL: goto x86_l_533;
	case 1339ULL: goto x86_l_53b;
	case 1345ULL: goto x86_l_541;
	case 1349ULL: goto x86_l_545;
	case 1355ULL: goto x86_l_54b;
	case 1359ULL: goto x86_l_54f;
	case 1365ULL: goto x86_l_555;
	case 1368ULL: goto x86_l_558;
	case 1371ULL: goto x86_l_55b;
	case 1374ULL: goto x86_l_55e;
	case 1377ULL: goto x86_l_561;
	case 1379ULL: goto x86_l_563;
	case 1382ULL: goto x86_l_566;
	case 1384ULL: goto x86_l_568;
	case 1387ULL: goto x86_l_56b;
	case 1389ULL: goto x86_l_56d;
	case 1391ULL: goto x86_l_56f;
	case 1394ULL: goto x86_l_572;
	case 1397ULL: goto x86_l_575;
	case 1399ULL: goto x86_l_577;
	case 1401ULL: goto x86_l_579;
	case 1404ULL: goto x86_l_57c;
	case 1408ULL: goto x86_l_580;
	case 1412ULL: goto x86_l_584;
	case 1418ULL: goto x86_l_58a;
	case 1422ULL: goto x86_l_58e;
	case 1429ULL: goto x86_l_595;
	case 1433ULL: goto x86_l_599;
	case 1436ULL: goto x86_l_59c;
	case 1441ULL: goto x86_l_5a1;
	case 1445ULL: goto x86_l_5a5;
	case 1447ULL: goto x86_l_5a7;
	case 1450ULL: goto x86_l_5aa;
	case 1453ULL: goto x86_l_5ad;
	case 1455ULL: goto x86_l_5af;
	case 1457ULL: goto x86_l_5b1;
	case 1463ULL: goto x86_l_5b7;
	case 1466ULL: goto x86_l_5ba;
	case 1472ULL: goto x86_l_5c0;
	case 1474ULL: goto x86_l_5c2;
	case 1479ULL: goto x86_l_5c7;
	case 1483ULL: goto x86_l_5cb;
	case 1489ULL: goto x86_l_5d1;
	case 1494ULL: goto x86_l_5d6;
	case 1498ULL: goto x86_l_5da;
	case 1504ULL: goto x86_l_5e0;
	case 1514ULL: goto x86_l_5ea;
	case 1518ULL: goto x86_l_5ee;
	case 1524ULL: goto x86_l_5f4;
	case 1531ULL: goto x86_l_5fb;
	case 1537ULL: goto x86_l_601;
	case 1543ULL: goto x86_l_607;
	case 1551ULL: goto x86_l_60f;
	case 1554ULL: goto x86_l_612;
	case 1559ULL: goto x86_l_617;
	case 1564ULL: goto x86_l_61c;
	case 1569ULL: goto x86_l_621;
	case 1573ULL: goto x86_l_625;
	case 1577ULL: goto x86_l_629;
	case 1581ULL: goto x86_l_62d;
	case 1586ULL: goto x86_l_632;
	case 1588ULL: goto x86_l_634;
	case 1593ULL: goto x86_l_639;
	case 1595ULL: goto x86_l_63b;
	case 1601ULL: goto x86_l_641;
	case 1606ULL: goto x86_l_646;
	case 1611ULL: goto x86_l_64b;
	case 1616ULL: goto x86_l_650;
	case 1618ULL: goto x86_l_652;
	case 1624ULL: goto x86_l_658;
	case 1629ULL: goto x86_l_65d;
	case 1632ULL: goto x86_l_660;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1646ULL: goto x86_l_66e;
	case 1652ULL: goto x86_l_674;
	case 1657ULL: goto x86_l_679;
	case 1659ULL: goto x86_l_67b;
	case 1665ULL: goto x86_l_681;
	case 1667ULL: goto x86_l_683;
	case 1673ULL: goto x86_l_689;
	case 1676ULL: goto x86_l_68c;
	case 1682ULL: goto x86_l_692;
	case 1687ULL: goto x86_l_697;
	case 1689ULL: goto x86_l_699;
	case 1695ULL: goto x86_l_69f;
	case 1697ULL: goto x86_l_6a1;
	case 1703ULL: goto x86_l_6a7;
	case 1706ULL: goto x86_l_6aa;
	case 1712ULL: goto x86_l_6b0;
	case 1717ULL: goto x86_l_6b5;
	case 1719ULL: goto x86_l_6b7;
	case 1725ULL: goto x86_l_6bd;
	case 1727ULL: goto x86_l_6bf;
	case 1729ULL: goto x86_l_6c1;
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
	/* 0xd: mov    DWORD PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_18:
	/* 0x18: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_27:
	/* 0x27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     180 <generic_retkprobe_filter_arg+0x180> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_180;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    r15d,DWORD PTR [rax+0x5f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_41:
	/* 0x41: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_48:
	/* 0x48: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_4f:
	/* 0x4f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_54:
	/* 0x54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56:
	/* 0x56: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59:
	/* 0x59: je     165 <generic_retkprobe_filter_arg+0x165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_165;
	}
x86_l_5f:
	/* 0x5f: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_67:
	/* 0x67: je     165 <generic_retkprobe_filter_arg+0x165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_165;
	}
x86_l_6d:
	/* 0x6d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_70:
	/* 0x70: mov    QWORD PTR [rsp+0xa8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_78:
	/* 0x78: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_7b:
	/* 0x7b: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_7e:
	/* 0x7e: cmp    BYTE PTR [r14+rax*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699072ULL);
x86_l_87:
	/* 0x87: je     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb;
	}
x86_l_89:
	/* 0x89: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8b:
	/* 0x8b: mov    ecx,DWORD PTR [rdi+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_8f:
	/* 0x8f: lea    r11,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_93:
	/* 0x93: add    r11,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_97:
	/* 0x97: mov    r9d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R11, X86_WIDTH_32);
x86_l_9a:
	/* 0x9a: and    r9d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_a1:
	/* 0xa1: cmp    DWORD PTR [rdi+r9*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 25ULL);
x86_l_a6:
	/* 0xa6: jae    10f <generic_retkprobe_filter_arg+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_10f;
	}
x86_l_a8:
	/* 0xa8: cmp    r9,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 1ULL);
x86_l_ac:
	/* 0xac: je     165 <generic_retkprobe_filter_arg+0x165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_165;
	}
x86_l_b2:
	/* 0xb2: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_b5:
	/* 0xb5: jne    143 <generic_retkprobe_filter_arg+0x143> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_143;
	}
x86_l_bb:
	/* 0xbb: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c3:
	/* 0xc3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c6:
	/* 0xc6: jg     e4 <generic_retkprobe_filter_arg+0xe4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_e4;
	}
x86_l_c8:
	/* 0xc8: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_cb:
	/* 0xcb: je     191 <generic_retkprobe_filter_arg+0x191> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_191;
	}
x86_l_d1:
	/* 0xd1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d3:
	/* 0xd3: je     19d <generic_retkprobe_filter_arg+0x19d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19d;
	}
x86_l_d9:
	/* 0xd9: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dc:
	/* 0xdc: je     1ac <generic_retkprobe_filter_arg+0x1ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ac;
	}
x86_l_e2:
	/* 0xe2: jmp    ff <generic_retkprobe_filter_arg+0xff> */
	goto x86_l_ff;
x86_l_e4:
	/* 0xe4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e7:
	/* 0xe7: je     1bb <generic_retkprobe_filter_arg+0x1bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bb;
	}
x86_l_ed:
	/* 0xed: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f0:
	/* 0xf0: je     1ca <generic_retkprobe_filter_arg+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ca;
	}
x86_l_f6:
	/* 0xf6: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f9:
	/* 0xf9: je     1d9 <generic_retkprobe_filter_arg+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d9;
	}
x86_l_ff:
	/* 0xff: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_102:
	/* 0x102: jg     20a <generic_retkprobe_filter_arg+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_20a;
	}
x86_l_108:
	/* 0x108: inc    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10a:
	/* 0x10a: jmp    1e8 <generic_retkprobe_filter_arg+0x1e8> */
	goto x86_l_1e8;
x86_l_10f:
	/* 0x10f: lea    rax,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_113:
	/* 0x113: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_11b:
	/* 0x11b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11e:
	/* 0x11e: lea    rax,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_123:
	/* 0x123: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_128:
	/* 0x128: mov    QWORD PTR [rsp+0xa0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_130:
	/* 0x130: mov    QWORD PTR [rsp],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_134:
	/* 0x134: mov    QWORD PTR [rsp+0x8],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_139:
	/* 0x139: mov    QWORD PTR [rsp+0x10],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13e:
	/* 0x13e: jmp    279 <generic_retkprobe_filter_arg+0x279> */
	goto x86_l_279;
x86_l_143:
	/* 0x143: mov    DWORD PTR [r14+0x5f04],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_14a:
	/* 0x14a: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_151:
	/* 0x151: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_156:
	/* 0x156: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_15b:
	/* 0x15b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15e:
	/* 0x15e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_163:
	/* 0x163: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_165:
	/* 0x165: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_16c:
	/* 0x16c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_171:
	/* 0x171: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_176:
	/* 0x176: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_179:
	/* 0x179: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_17e:
	/* 0x17e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_180:
	/* 0x180: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_182:
	/* 0x182: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_189:
	/* 0x189: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_18b:
	/* 0x18b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_18c:
	/* 0x18c: jmp    365f <native_bpf_strncasestr+0x72> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_191:
	/* 0x191: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_193:
	/* 0x193: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_19b:
	/* 0x19b: jne    1e8 <generic_retkprobe_filter_arg+0x1e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e8;
	}
x86_l_19d:
	/* 0x19d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a2:
	/* 0x1a2: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_1aa:
	/* 0x1aa: jne    1e8 <generic_retkprobe_filter_arg+0x1e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e8;
	}
x86_l_1ac:
	/* 0x1ac: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b1:
	/* 0x1b1: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_1b9:
	/* 0x1b9: jne    1e8 <generic_retkprobe_filter_arg+0x1e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e8;
	}
x86_l_1bb:
	/* 0x1bb: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1c0:
	/* 0x1c0: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_1c8:
	/* 0x1c8: jne    1e8 <generic_retkprobe_filter_arg+0x1e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e8;
	}
x86_l_1ca:
	/* 0x1ca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cf:
	/* 0x1cf: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_1d7:
	/* 0x1d7: jne    1e8 <generic_retkprobe_filter_arg+0x1e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e8;
	}
x86_l_1d9:
	/* 0x1d9: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_1de:
	/* 0x1de: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_1e6:
	/* 0x1e6: je     20a <generic_retkprobe_filter_arg+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20a;
	}
x86_l_1e8:
	/* 0x1e8: mov    DWORD PTR [r14+0x5f00],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_1ef:
	/* 0x1ef: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_1f6:
	/* 0x1f6: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1fb:
	/* 0x1fb: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_200:
	/* 0x200: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_203:
	/* 0x203: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_208:
	/* 0x208: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a:
	/* 0x20a: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_20e:
	/* 0x20e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_213:
	/* 0x213: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_215:
	/* 0x215: mov    QWORD PTR [rsp+0x38],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21a:
	/* 0x21a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21f:
	/* 0x21f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_226:
	/* 0x226: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22b:
	/* 0x22b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_230:
	/* 0x230: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_232:
	/* 0x232: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_235:
	/* 0x235: je     180 <generic_retkprobe_filter_arg+0x180> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_180;
	}
x86_l_23b:
	/* 0x23b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_242:
	/* 0x242: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_247:
	/* 0x247: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_24c:
	/* 0x24c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e:
	/* 0x24e: jmp    180 <generic_retkprobe_filter_arg+0x180> */
	goto x86_l_180;
x86_l_253:
	/* 0x253: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_255:
	/* 0x255: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_258:
	/* 0x258: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_25b:
	/* 0x25b: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_25e:
	/* 0x25e: mov    rbx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_266:
	/* 0x266: je     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb;
	}
x86_l_26c:
	/* 0x26c: inc    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_26f:
	/* 0x26f: cmp    r15,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 5ULL);
x86_l_273:
	/* 0x273: je     a8 <generic_retkprobe_filter_arg+0xa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a8;
	}
x86_l_279:
	/* 0x279: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_281:
	/* 0x281: mov    r12d,DWORD PTR [rax+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_286:
	/* 0x286: test   r12d,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1023ULL);
x86_l_28d:
	/* 0x28d: je     a8 <generic_retkprobe_filter_arg+0xa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a8;
	}
x86_l_293:
	/* 0x293: add    r12d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_296:
	/* 0x296: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_29d:
	/* 0x29d: mov    eax,DWORD PTR [rdi+r12*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_2a2:
	/* 0x2a2: cmp    eax,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2a5:
	/* 0x2a5: je     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb;
	}
x86_l_2ab:
	/* 0x2ab: add    r12,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ae:
	/* 0x2ae: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b2:
	/* 0x2b2: cmp    rcx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4ULL);
x86_l_2b6:
	/* 0x2b6: ja     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bb;
	}
x86_l_2bc:
	/* 0x2bc: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_2c5:
	/* 0x2c5: jne    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bb;
	}
x86_l_2cb:
	/* 0x2cb: mov    rcx,QWORD PTR [r14+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_2d3:
	/* 0x2d3: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2d9:
	/* 0x2d9: lea    r13,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2dd:
	/* 0x2dd: add    r13,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2e4:
	/* 0x2e4: mov    ecx,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e9:
	/* 0x2e9: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_2ec:
	/* 0x2ec: jle    30d <generic_retkprobe_filter_arg+0x30d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_30d;
	}
x86_l_2ee:
	/* 0x2ee: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_2f1:
	/* 0x2f1: jg     338 <generic_retkprobe_filter_arg+0x338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_338;
	}
x86_l_2f3:
	/* 0x2f3: lea    edx,[rcx-0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551588ULL);
x86_l_2f6:
	/* 0x2f6: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_2f9:
	/* 0x2f9: jb     37e <generic_retkprobe_filter_arg+0x37e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37e;
	}
x86_l_2ff:
	/* 0x2ff: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_302:
	/* 0x302: je     5a1 <generic_retkprobe_filter_arg+0x5a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a1;
	}
x86_l_308:
	/* 0x308: jmp    26c <generic_retkprobe_filter_arg+0x26c> */
	goto x86_l_26c;
x86_l_30d:
	/* 0x30d: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_310:
	/* 0x310: jle    35e <generic_retkprobe_filter_arg+0x35e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_35e;
	}
x86_l_312:
	/* 0x312: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_315:
	/* 0x315: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_318:
	/* 0x318: jb     37e <generic_retkprobe_filter_arg+0x37e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37e;
	}
x86_l_31a:
	/* 0x31a: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_31d:
	/* 0x31d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_320:
	/* 0x320: jb     5a1 <generic_retkprobe_filter_arg+0x5a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5a1;
	}
x86_l_326:
	/* 0x326: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_329:
	/* 0x329: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26c;
	}
x86_l_32f:
	/* 0x32f: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_333:
	/* 0x333: jmp    5a1 <generic_retkprobe_filter_arg+0x5a1> */
	goto x86_l_5a1;
x86_l_338:
	/* 0x338: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_33b:
	/* 0x33b: jg     4ff <generic_retkprobe_filter_arg+0x4ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4ff;
	}
x86_l_341:
	/* 0x341: lea    edx,[rcx-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_344:
	/* 0x344: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_347:
	/* 0x347: jb     49a <generic_retkprobe_filter_arg+0x49a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_49a;
	}
x86_l_34d:
	/* 0x34d: lea    edx,[rcx-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_350:
	/* 0x350: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_353:
	/* 0x353: jb     445 <generic_retkprobe_filter_arg+0x445> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_445;
	}
x86_l_359:
	/* 0x359: jmp    26c <generic_retkprobe_filter_arg+0x26c> */
	goto x86_l_26c;
x86_l_35e:
	/* 0x35e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_361:
	/* 0x361: jg     432 <generic_retkprobe_filter_arg+0x432> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_432;
	}
x86_l_367:
	/* 0x367: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_36a:
	/* 0x36a: je     37e <generic_retkprobe_filter_arg+0x37e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e;
	}
x86_l_36c:
	/* 0x36c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_36f:
	/* 0x36f: je     b34 <generic_retkprobe_filter_arg+0xb34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2868ULL;
	}
x86_l_375:
	/* 0x375: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_378:
	/* 0x378: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26c;
	}
x86_l_37e:
	/* 0x37e: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_381:
	/* 0x381: jle    40f <generic_retkprobe_filter_arg+0x40f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_40f;
	}
x86_l_387:
	/* 0x387: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_38a:
	/* 0x38a: ja     6c9 <generic_retkprobe_filter_arg+0x6c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1737ULL;
	}
x86_l_390:
	/* 0x390: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_392:
	/* 0x392: movabs rsi,0x1e00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 128849018880ULL);
x86_l_39c:
	/* 0x39c: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3a0:
	/* 0x3a0: jb     4d3 <generic_retkprobe_filter_arg+0x4d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4d3;
	}
x86_l_3a6:
	/* 0x3a6: mov    esi,0x60000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1610612736ULL);
x86_l_3ab:
	/* 0x3ab: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3af:
	/* 0x3af: jb     90a <generic_retkprobe_filter_arg+0x90a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2314ULL;
	}
x86_l_3b5:
	/* 0x3b5: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_3bf:
	/* 0x3bf: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3c3:
	/* 0x3c3: jae    6c9 <generic_retkprobe_filter_arg+0x6c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 1737ULL;
	}
x86_l_3c9:
	/* 0x3c9: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_3cc:
	/* 0x3cc: ja     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bb;
	}
x86_l_3d2:
	/* 0x3d2: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3d4:
	/* 0x3d4: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_3d9:
	/* 0x3d9: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_3dd:
	/* 0x3dd: jae    1050 <generic_retkprobe_filter_arg+0x1050> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4176ULL;
	}
x86_l_3e3:
	/* 0x3e3: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e8:
	/* 0x3e8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3eb:
	/* 0x3eb: jle    15a5 <generic_retkprobe_filter_arg+0x15a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5541ULL;
	}
x86_l_3f1:
	/* 0x3f1: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3f4:
	/* 0x3f4: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3f7:
	/* 0x3f7: jae    1d1f <generic_retkprobe_filter_arg+0x1d1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7455ULL;
	}
x86_l_3fd:
	/* 0x3fd: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_402:
	/* 0x402: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_404:
	/* 0x404: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_253;
	}
x86_l_40a:
	/* 0x40a: jmp    1e46 <generic_retkprobe_filter_arg+0x1e46> */
	return 7750ULL;
x86_l_40f:
	/* 0x40f: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_412:
	/* 0x412: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_415:
	/* 0x415: jb     bb3 <generic_retkprobe_filter_arg+0xbb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2995ULL;
	}
x86_l_41b:
	/* 0x41b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_41e:
	/* 0x41e: je     6d5 <generic_retkprobe_filter_arg+0x6d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1749ULL;
	}
x86_l_424:
	/* 0x424: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_427:
	/* 0x427: je     6d5 <generic_retkprobe_filter_arg+0x6d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1749ULL;
	}
x86_l_42d:
	/* 0x42d: jmp    26c <generic_retkprobe_filter_arg+0x26c> */
	goto x86_l_26c;
x86_l_432:
	/* 0x432: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_435:
	/* 0x435: je     445 <generic_retkprobe_filter_arg+0x445> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_445;
	}
x86_l_437:
	/* 0x437: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_43a:
	/* 0x43a: je     49a <generic_retkprobe_filter_arg+0x49a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49a;
	}
x86_l_43c:
	/* 0x43c: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_43f:
	/* 0x43f: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26c;
	}
x86_l_445:
	/* 0x445: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_44e:
	/* 0x44e: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_457:
	/* 0x457: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_460:
	/* 0x460: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_469:
	/* 0x469: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_472:
	/* 0x472: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_475:
	/* 0x475: jg     714 <generic_retkprobe_filter_arg+0x714> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1812ULL;
	}
x86_l_47b:
	/* 0x47b: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_47e:
	/* 0x47e: je     d15 <generic_retkprobe_filter_arg+0xd15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3349ULL;
	}
x86_l_484:
	/* 0x484: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_487:
	/* 0x487: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_48c:
	/* 0x48c: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_48f:
	/* 0x48f: je     d17 <generic_retkprobe_filter_arg+0xd17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3351ULL;
	}
x86_l_495:
	/* 0x495: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	goto x86_l_25b;
x86_l_49a:
	/* 0x49a: mov    ebp,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49e:
	/* 0x49e: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4a2:
	/* 0x4a2: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_4a5:
	/* 0x4a5: jg     799 <generic_retkprobe_filter_arg+0x799> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1945ULL;
	}
x86_l_4ab:
	/* 0x4ab: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_4ae:
	/* 0x4ae: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4b1:
	/* 0x4b1: jb     f6e <generic_retkprobe_filter_arg+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3950ULL;
	}
x86_l_4b7:
	/* 0x4b7: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4ba:
	/* 0x4ba: je     ed7 <generic_retkprobe_filter_arg+0xed7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3799ULL;
	}
x86_l_4c0:
	/* 0x4c0: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_4c5:
	/* 0x4c5: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_4c8:
	/* 0x4c8: je     7b9 <generic_retkprobe_filter_arg+0x7b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1977ULL;
	}
x86_l_4ce:
	/* 0x4ce: jmp    357d <generic_retkprobe_filter_arg+0x357d> */
	return 13693ULL;
x86_l_4d3:
	/* 0x4d3: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_4d6:
	/* 0x4d6: jle    b23 <generic_retkprobe_filter_arg+0xb23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2851ULL;
	}
x86_l_4dc:
	/* 0x4dc: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_4df:
	/* 0x4df: jg     e8f <generic_retkprobe_filter_arg+0xe8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3727ULL;
	}
x86_l_4e5:
	/* 0x4e5: lea    edx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_4e8:
	/* 0x4e8: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4eb:
	/* 0x4eb: jb     c41 <generic_retkprobe_filter_arg+0xc41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3137ULL;
	}
x86_l_4f1:
	/* 0x4f1: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_4f4:
	/* 0x4f4: je     bc9 <generic_retkprobe_filter_arg+0xbc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3017ULL;
	}
x86_l_4fa:
	/* 0x4fa: jmp    bb <generic_retkprobe_filter_arg+0xbb> */
	goto x86_l_bb;
x86_l_4ff:
	/* 0x4ff: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_502:
	/* 0x502: je     5a1 <generic_retkprobe_filter_arg+0x5a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a1;
	}
x86_l_508:
	/* 0x508: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_50b:
	/* 0x50b: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26c;
	}
x86_l_511:
	/* 0x511: lea    rsi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_515:
	/* 0x515: movzx  r8d,BYTE PTR [r13+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_51a:
	/* 0x51a: movzx  ebp,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_51e:
	/* 0x51e: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_521:
	/* 0x521: jg     1332 <generic_retkprobe_filter_arg+0x1332> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4914ULL;
	}
x86_l_527:
	/* 0x527: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_52a:
	/* 0x52a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_52d:
	/* 0x52d: jae    189f <generic_retkprobe_filter_arg+0x189f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6303ULL;
	}
x86_l_533:
	/* 0x533: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_53b:
	/* 0x53b: mov    r10d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 256ULL);
x86_l_541:
	/* 0x541: cmp    bpl,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 144ULL);
x86_l_545:
	/* 0x545: ja     1671 <generic_retkprobe_filter_arg+0x1671> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5745ULL;
	}
x86_l_54b:
	/* 0x54b: movzx  eax,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_54f:
	/* 0x54f: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_555:
	/* 0x555: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_558:
	/* 0x558: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_55b:
	/* 0x55b: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_55e:
	/* 0x55e: mov    eax,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_561:
	/* 0x561: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_563:
	/* 0x563: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_566:
	/* 0x566: je     56f <generic_retkprobe_filter_arg+0x56f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56f;
	}
x86_l_568:
	/* 0x568: mov    r10d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RBP, X86_WIDTH_32);
x86_l_56b:
	/* 0x56b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_56d:
	/* 0x56d: je     58a <generic_retkprobe_filter_arg+0x58a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58a;
	}
x86_l_56f:
	/* 0x56f: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_572:
	/* 0x572: movzx  ecx,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_575:
	/* 0x575: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_577:
	/* 0x577: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_579:
	/* 0x579: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_57c:
	/* 0x57c: movzx  r10d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_580:
	/* 0x580: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_584:
	/* 0x584: ja     1671 <generic_retkprobe_filter_arg+0x1671> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5745ULL;
	}
x86_l_58a:
	/* 0x58a: movzx  eax,r10b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R10, X86_WIDTH_32, X86_WIDTH_8);
x86_l_58e:
	/* 0x58e: imul   r13d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R13, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_595:
	/* 0x595: shr    r13d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_599:
	/* 0x599: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_59c:
	/* 0x59c: jmp    24c0 <generic_retkprobe_filter_arg+0x24c0> */
	return 9408ULL;
x86_l_5a1:
	/* 0x5a1: mov    ebp,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a5:
	/* 0x5a5: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_5a7:
	/* 0x5a7: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_5aa:
	/* 0x5aa: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_5ad:
	/* 0x5ad: je     5b7 <generic_retkprobe_filter_arg+0x5b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b7;
	}
x86_l_5af:
	/* 0x5af: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_5b1:
	/* 0x5b1: je     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb;
	}
x86_l_5b7:
	/* 0x5b7: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_5ba:
	/* 0x5ba: ja     8e7 <generic_retkprobe_filter_arg+0x8e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2279ULL;
	}
x86_l_5c0:
	/* 0x5c0: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_5c2:
	/* 0x5c2: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_5c7:
	/* 0x5c7: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_5cb:
	/* 0x5cb: jb     a82 <generic_retkprobe_filter_arg+0xa82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2690ULL;
	}
x86_l_5d1:
	/* 0x5d1: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_5d6:
	/* 0x5d6: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_5da:
	/* 0x5da: jb     950 <generic_retkprobe_filter_arg+0x950> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2384ULL;
	}
x86_l_5e0:
	/* 0x5e0: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_5ea:
	/* 0x5ea: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_5ee:
	/* 0x5ee: jae    8e7 <generic_retkprobe_filter_arg+0x8e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2279ULL;
	}
x86_l_5f4:
	/* 0x5f4: mov    WORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5fb:
	/* 0x5fb: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_601:
	/* 0x601: ja     903 <generic_retkprobe_filter_arg+0x903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2307ULL;
	}
x86_l_607:
	/* 0x607: lea    rcx,[rbp*1+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 8ULL);
x86_l_60f:
	/* 0x60f: add    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_612:
	/* 0x612: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_617:
	/* 0x617: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_61c:
	/* 0x61c: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_621:
	/* 0x621: mov    ecx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_625:
	/* 0x625: lea    rdx,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_629:
	/* 0x629: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_62d:
	/* 0x62d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_632:
	/* 0x632: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_634:
	/* 0x634: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_639:
	/* 0x639: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_63b:
	/* 0x63b: je     31d1 <generic_retkprobe_filter_arg+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12753ULL;
	}
x86_l_641:
	/* 0x641: movzx  eax,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_646:
	/* 0x646: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_64b:
	/* 0x64b: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_650:
	/* 0x650: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_652:
	/* 0x652: je     31d3 <generic_retkprobe_filter_arg+0x31d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12755ULL;
	}
x86_l_658:
	/* 0x658: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_65d:
	/* 0x65d: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_660:
	/* 0x660: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_664:
	/* 0x664: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_669:
	/* 0x669: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66e:
	/* 0x66e: jb     903 <generic_retkprobe_filter_arg+0x903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2307ULL;
	}
x86_l_674:
	/* 0x674: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_679:
	/* 0x679: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_67b:
	/* 0x67b: je     903 <generic_retkprobe_filter_arg+0x903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2307ULL;
	}
x86_l_681:
	/* 0x681: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_683:
	/* 0x683: je     31e1 <generic_retkprobe_filter_arg+0x31e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12769ULL;
	}
x86_l_689:
	/* 0x689: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_68c:
	/* 0x68c: jb     903 <generic_retkprobe_filter_arg+0x903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2307ULL;
	}
x86_l_692:
	/* 0x692: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_697:
	/* 0x697: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_699:
	/* 0x699: je     903 <generic_retkprobe_filter_arg+0x903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2307ULL;
	}
x86_l_69f:
	/* 0x69f: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_6a1:
	/* 0x6a1: je     31e1 <generic_retkprobe_filter_arg+0x31e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12769ULL;
	}
x86_l_6a7:
	/* 0x6a7: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_6aa:
	/* 0x6aa: jb     31d1 <generic_retkprobe_filter_arg+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12753ULL;
	}
x86_l_6b0:
	/* 0x6b0: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_6b5:
	/* 0x6b5: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_6b7:
	/* 0x6b7: je     31d1 <generic_retkprobe_filter_arg+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12753ULL;
	}
x86_l_6bd:
	/* 0x6bd: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6bf:
	/* 0x6bf: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6c1:
	/* 0x6c1: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
	return 1732ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1732ULL: goto x86_l_6c4;
	case 1737ULL: goto x86_l_6c9;
	case 1740ULL: goto x86_l_6cc;
	case 1743ULL: goto x86_l_6cf;
	case 1749ULL: goto x86_l_6d5;
	case 1752ULL: goto x86_l_6d8;
	case 1758ULL: goto x86_l_6de;
	case 1760ULL: goto x86_l_6e0;
	case 1765ULL: goto x86_l_6e5;
	case 1769ULL: goto x86_l_6e9;
	case 1771ULL: goto x86_l_6eb;
	case 1776ULL: goto x86_l_6f0;
	case 1779ULL: goto x86_l_6f3;
	case 1785ULL: goto x86_l_6f9;
	case 1788ULL: goto x86_l_6fc;
	case 1791ULL: goto x86_l_6ff;
	case 1797ULL: goto x86_l_705;
	case 1801ULL: goto x86_l_709;
	case 1807ULL: goto x86_l_70f;
	case 1812ULL: goto x86_l_714;
	case 1815ULL: goto x86_l_717;
	case 1821ULL: goto x86_l_71d;
	case 1824ULL: goto x86_l_720;
	case 1829ULL: goto x86_l_725;
	case 1832ULL: goto x86_l_728;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1848ULL: goto x86_l_738;
	case 1852ULL: goto x86_l_73c;
	case 1858ULL: goto x86_l_742;
	case 1868ULL: goto x86_l_74c;
	case 1872ULL: goto x86_l_750;
	case 1878ULL: goto x86_l_756;
	case 1881ULL: goto x86_l_759;
	case 1887ULL: goto x86_l_75f;
	case 1892ULL: goto x86_l_764;
	case 1897ULL: goto x86_l_769;
	case 1900ULL: goto x86_l_76c;
	case 1906ULL: goto x86_l_772;
	case 1911ULL: goto x86_l_777;
	case 1914ULL: goto x86_l_77a;
	case 1920ULL: goto x86_l_780;
	case 1924ULL: goto x86_l_784;
	case 1926ULL: goto x86_l_786;
	case 1932ULL: goto x86_l_78c;
	case 1934ULL: goto x86_l_78e;
	case 1940ULL: goto x86_l_794;
	case 1945ULL: goto x86_l_799;
	case 1948ULL: goto x86_l_79c;
	case 1954ULL: goto x86_l_7a2;
	case 1957ULL: goto x86_l_7a5;
	case 1963ULL: goto x86_l_7ab;
	case 1968ULL: goto x86_l_7b0;
	case 1971ULL: goto x86_l_7b3;
	case 1977ULL: goto x86_l_7b9;
	case 1982ULL: goto x86_l_7be;
	case 1986ULL: goto x86_l_7c2;
	case 1994ULL: goto x86_l_7ca;
	case 1999ULL: goto x86_l_7cf;
	case 2004ULL: goto x86_l_7d4;
	case 2011ULL: goto x86_l_7db;
	case 2013ULL: goto x86_l_7dd;
	case 2015ULL: goto x86_l_7df;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2029ULL: goto x86_l_7ed;
	case 2035ULL: goto x86_l_7f3;
	case 2040ULL: goto x86_l_7f8;
	case 2045ULL: goto x86_l_7fd;
	case 2050ULL: goto x86_l_802;
	case 2057ULL: goto x86_l_809;
	case 2059ULL: goto x86_l_80b;
	case 2062ULL: goto x86_l_80e;
	case 2068ULL: goto x86_l_814;
	case 2071ULL: goto x86_l_817;
	case 2074ULL: goto x86_l_81a;
	case 2079ULL: goto x86_l_81f;
	case 2082ULL: goto x86_l_822;
	case 2085ULL: goto x86_l_825;
	case 2087ULL: goto x86_l_827;
	case 2090ULL: goto x86_l_82a;
	case 2093ULL: goto x86_l_82d;
	case 2098ULL: goto x86_l_832;
	case 2101ULL: goto x86_l_835;
	case 2104ULL: goto x86_l_838;
	case 2109ULL: goto x86_l_83d;
	case 2113ULL: goto x86_l_841;
	case 2119ULL: goto x86_l_847;
	case 2122ULL: goto x86_l_84a;
	case 2126ULL: goto x86_l_84e;
	case 2132ULL: goto x86_l_854;
	case 2135ULL: goto x86_l_857;
	case 2139ULL: goto x86_l_85b;
	case 2141ULL: goto x86_l_85d;
	case 2143ULL: goto x86_l_85f;
	case 2146ULL: goto x86_l_862;
	case 2150ULL: goto x86_l_866;
	case 2157ULL: goto x86_l_86d;
	case 2162ULL: goto x86_l_872;
	case 2166ULL: goto x86_l_876;
	case 2169ULL: goto x86_l_879;
	case 2171ULL: goto x86_l_87b;
	case 2175ULL: goto x86_l_87f;
	case 2182ULL: goto x86_l_886;
	case 2187ULL: goto x86_l_88b;
	case 2191ULL: goto x86_l_88f;
	case 2194ULL: goto x86_l_892;
	case 2196ULL: goto x86_l_894;
	case 2200ULL: goto x86_l_898;
	case 2207ULL: goto x86_l_89f;
	case 2212ULL: goto x86_l_8a4;
	case 2216ULL: goto x86_l_8a8;
	case 2219ULL: goto x86_l_8ab;
	case 2221ULL: goto x86_l_8ad;
	case 2225ULL: goto x86_l_8b1;
	case 2227ULL: goto x86_l_8b3;
	case 2231ULL: goto x86_l_8b7;
	case 2238ULL: goto x86_l_8be;
	case 2243ULL: goto x86_l_8c3;
	case 2246ULL: goto x86_l_8c6;
	case 2250ULL: goto x86_l_8ca;
	case 2254ULL: goto x86_l_8ce;
	case 2257ULL: goto x86_l_8d1;
	case 2259ULL: goto x86_l_8d3;
	case 2264ULL: goto x86_l_8d8;
	case 2269ULL: goto x86_l_8dd;
	case 2274ULL: goto x86_l_8e2;
	case 2279ULL: goto x86_l_8e7;
	case 2282ULL: goto x86_l_8ea;
	case 2285ULL: goto x86_l_8ed;
	case 2287ULL: goto x86_l_8ef;
	case 2295ULL: goto x86_l_8f7;
	case 2301ULL: goto x86_l_8fd;
	case 2307ULL: goto x86_l_903;
	case 2309ULL: goto x86_l_905;
	case 2314ULL: goto x86_l_90a;
	case 2317ULL: goto x86_l_90d;
	case 2323ULL: goto x86_l_913;
	case 2325ULL: goto x86_l_915;
	case 2330ULL: goto x86_l_91a;
	case 2334ULL: goto x86_l_91e;
	case 2340ULL: goto x86_l_924;
	case 2345ULL: goto x86_l_929;
	case 2348ULL: goto x86_l_92c;
	case 2354ULL: goto x86_l_932;
	case 2357ULL: goto x86_l_935;
	case 2360ULL: goto x86_l_938;
	case 2366ULL: goto x86_l_93e;
	case 2371ULL: goto x86_l_943;
	case 2373ULL: goto x86_l_945;
	case 2379ULL: goto x86_l_94b;
	case 2384ULL: goto x86_l_950;
	case 2389ULL: goto x86_l_955;
	case 2393ULL: goto x86_l_959;
	case 2401ULL: goto x86_l_961;
	case 2406ULL: goto x86_l_966;
	case 2411ULL: goto x86_l_96b;
	case 2418ULL: goto x86_l_972;
	case 2420ULL: goto x86_l_974;
	case 2422ULL: goto x86_l_976;
	case 2428ULL: goto x86_l_97c;
	case 2433ULL: goto x86_l_981;
	case 2436ULL: goto x86_l_984;
	case 2442ULL: goto x86_l_98a;
	case 2447ULL: goto x86_l_98f;
	case 2452ULL: goto x86_l_994;
	case 2457ULL: goto x86_l_999;
	case 2464ULL: goto x86_l_9a0;
	case 2466ULL: goto x86_l_9a2;
	case 2469ULL: goto x86_l_9a5;
	case 2475ULL: goto x86_l_9ab;
	case 2478ULL: goto x86_l_9ae;
	case 2481ULL: goto x86_l_9b1;
	case 2486ULL: goto x86_l_9b6;
	case 2489ULL: goto x86_l_9b9;
	case 2492ULL: goto x86_l_9bc;
	case 2494ULL: goto x86_l_9be;
	case 2497ULL: goto x86_l_9c1;
	case 2500ULL: goto x86_l_9c4;
	case 2505ULL: goto x86_l_9c9;
	case 2508ULL: goto x86_l_9cc;
	case 2511ULL: goto x86_l_9cf;
	case 2516ULL: goto x86_l_9d4;
	case 2520ULL: goto x86_l_9d8;
	case 2526ULL: goto x86_l_9de;
	case 2529ULL: goto x86_l_9e1;
	case 2533ULL: goto x86_l_9e5;
	case 2539ULL: goto x86_l_9eb;
	case 2542ULL: goto x86_l_9ee;
	case 2546ULL: goto x86_l_9f2;
	case 2548ULL: goto x86_l_9f4;
	case 2550ULL: goto x86_l_9f6;
	case 2553ULL: goto x86_l_9f9;
	case 2557ULL: goto x86_l_9fd;
	case 2564ULL: goto x86_l_a04;
	case 2570ULL: goto x86_l_a0a;
	case 2574ULL: goto x86_l_a0e;
	case 2577ULL: goto x86_l_a11;
	case 2579ULL: goto x86_l_a13;
	case 2583ULL: goto x86_l_a17;
	case 2590ULL: goto x86_l_a1e;
	case 2596ULL: goto x86_l_a24;
	case 2600ULL: goto x86_l_a28;
	case 2603ULL: goto x86_l_a2b;
	case 2605ULL: goto x86_l_a2d;
	case 2609ULL: goto x86_l_a31;
	case 2616ULL: goto x86_l_a38;
	case 2622ULL: goto x86_l_a3e;
	case 2626ULL: goto x86_l_a42;
	case 2629ULL: goto x86_l_a45;
	case 2631ULL: goto x86_l_a47;
	case 2635ULL: goto x86_l_a4b;
	case 2637ULL: goto x86_l_a4d;
	case 2641ULL: goto x86_l_a51;
	case 2648ULL: goto x86_l_a58;
	case 2654ULL: goto x86_l_a5e;
	case 2657ULL: goto x86_l_a61;
	case 2661ULL: goto x86_l_a65;
	case 2665ULL: goto x86_l_a69;
	case 2668ULL: goto x86_l_a6c;
	case 2670ULL: goto x86_l_a6e;
	case 2675ULL: goto x86_l_a73;
	case 2680ULL: goto x86_l_a78;
	case 2685ULL: goto x86_l_a7d;
	case 2690ULL: goto x86_l_a82;
	case 2695ULL: goto x86_l_a87;
	case 2700ULL: goto x86_l_a8c;
	case 2704ULL: goto x86_l_a90;
	case 2712ULL: goto x86_l_a98;
	case 2717ULL: goto x86_l_a9d;
	case 2722ULL: goto x86_l_aa2;
	case 2729ULL: goto x86_l_aa9;
	case 2731ULL: goto x86_l_aab;
	case 2733ULL: goto x86_l_aad;
	case 2739ULL: goto x86_l_ab3;
	case 2742ULL: goto x86_l_ab6;
	case 2747ULL: goto x86_l_abb;
	case 2750ULL: goto x86_l_abe;
	case 2756ULL: goto x86_l_ac4;
	case 2761ULL: goto x86_l_ac9;
	case 2766ULL: goto x86_l_ace;
	case 2773ULL: goto x86_l_ad5;
	case 2775ULL: goto x86_l_ad7;
	case 2778ULL: goto x86_l_ada;
	case 2784ULL: goto x86_l_ae0;
	case 2787ULL: goto x86_l_ae3;
	case 2792ULL: goto x86_l_ae8;
	case 2796ULL: goto x86_l_aec;
	case 2802ULL: goto x86_l_af2;
	case 2807ULL: goto x86_l_af7;
	case 2810ULL: goto x86_l_afa;
	case 2817ULL: goto x86_l_b01;
	case 2819ULL: goto x86_l_b03;
	case 2822ULL: goto x86_l_b06;
	case 2826ULL: goto x86_l_b0a;
	case 2831ULL: goto x86_l_b0f;
	case 2833ULL: goto x86_l_b11;
	case 2835ULL: goto x86_l_b13;
	case 2840ULL: goto x86_l_b18;
	case 2843ULL: goto x86_l_b1b;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2854ULL: goto x86_l_b26;
	case 2857ULL: goto x86_l_b29;
	case 2863ULL: goto x86_l_b2f;
	case 2868ULL: goto x86_l_b34;
	case 2872ULL: goto x86_l_b38;
	case 2876ULL: goto x86_l_b3c;
	case 2879ULL: goto x86_l_b3f;
	case 2885ULL: goto x86_l_b45;
	case 2888ULL: goto x86_l_b48;
	case 2891ULL: goto x86_l_b4b;
	case 2897ULL: goto x86_l_b51;
	case 2902ULL: goto x86_l_b56;
	case 2905ULL: goto x86_l_b59;
	case 2911ULL: goto x86_l_b5f;
	case 2916ULL: goto x86_l_b64;
	case 2919ULL: goto x86_l_b67;
	case 2925ULL: goto x86_l_b6d;
	case 2930ULL: goto x86_l_b72;
	case 2933ULL: goto x86_l_b75;
	case 2939ULL: goto x86_l_b7b;
	case 2942ULL: goto x86_l_b7e;
	case 2948ULL: goto x86_l_b84;
	case 2951ULL: goto x86_l_b87;
	case 2957ULL: goto x86_l_b8d;
	case 2962ULL: goto x86_l_b92;
	case 2965ULL: goto x86_l_b95;
	case 2971ULL: goto x86_l_b9b;
	case 2975ULL: goto x86_l_b9f;
	case 2981ULL: goto x86_l_ba5;
	case 2986ULL: goto x86_l_baa;
	case 2989ULL: goto x86_l_bad;
	case 2995ULL: goto x86_l_bb3;
	case 2998ULL: goto x86_l_bb6;
	case 3004ULL: goto x86_l_bbc;
	case 3006ULL: goto x86_l_bbe;
	case 3011ULL: goto x86_l_bc3;
	case 3015ULL: goto x86_l_bc7;
	case 3017ULL: goto x86_l_bc9;
	case 3022ULL: goto x86_l_bce;
	case 3025ULL: goto x86_l_bd1;
	case 3027ULL: goto x86_l_bd3;
	case 3030ULL: goto x86_l_bd6;
	case 3033ULL: goto x86_l_bd9;
	case 3039ULL: goto x86_l_bdf;
	case 3043ULL: goto x86_l_be3;
	case 3049ULL: goto x86_l_be9;
	case 3054ULL: goto x86_l_bee;
	case 3059ULL: goto x86_l_bf3;
	case 3063ULL: goto x86_l_bf7;
	case 3065ULL: goto x86_l_bf9;
	case 3075ULL: goto x86_l_c03;
	case 3079ULL: goto x86_l_c07;
	case 3085ULL: goto x86_l_c0d;
	case 3090ULL: goto x86_l_c12;
	case 3093ULL: goto x86_l_c15;
	case 3099ULL: goto x86_l_c1b;
	case 3102ULL: goto x86_l_c1e;
	case 3108ULL: goto x86_l_c24;
	case 3111ULL: goto x86_l_c27;
	case 3113ULL: goto x86_l_c29;
	case 3116ULL: goto x86_l_c2c;
	case 3122ULL: goto x86_l_c32;
	case 3126ULL: goto x86_l_c36;
	case 3132ULL: goto x86_l_c3c;
	case 3137ULL: goto x86_l_c41;
	case 3143ULL: goto x86_l_c47;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3157ULL: goto x86_l_c55;
	case 3164ULL: goto x86_l_c5c;
	case 3166ULL: goto x86_l_c5e;
	case 3169ULL: goto x86_l_c61;
	case 3175ULL: goto x86_l_c67;
	case 3178ULL: goto x86_l_c6a;
	case 3182ULL: goto x86_l_c6e;
	case 3187ULL: goto x86_l_c73;
	case 3192ULL: goto x86_l_c78;
	case 3197ULL: goto x86_l_c7d;
	case 3199ULL: goto x86_l_c7f;
	case 3204ULL: goto x86_l_c84;
	case 3207ULL: goto x86_l_c87;
	case 3213ULL: goto x86_l_c8d;
	case 3216ULL: goto x86_l_c90;
	case 3220ULL: goto x86_l_c94;
	case 3225ULL: goto x86_l_c99;
	case 3230ULL: goto x86_l_c9e;
	case 3236ULL: goto x86_l_ca4;
	case 3241ULL: goto x86_l_ca9;
	case 3247ULL: goto x86_l_caf;
	case 3251ULL: goto x86_l_cb3;
	case 3256ULL: goto x86_l_cb8;
	case 3261ULL: goto x86_l_cbd;
	case 3268ULL: goto x86_l_cc4;
	case 3270ULL: goto x86_l_cc6;
	case 3273ULL: goto x86_l_cc9;
	case 3279ULL: goto x86_l_ccf;
	case 3282ULL: goto x86_l_cd2;
	case 3286ULL: goto x86_l_cd6;
	case 3291ULL: goto x86_l_cdb;
	case 3296ULL: goto x86_l_ce0;
	case 3301ULL: goto x86_l_ce5;
	case 3306ULL: goto x86_l_cea;
	case 3311ULL: goto x86_l_cef;
	case 3316ULL: goto x86_l_cf4;
	case 3321ULL: goto x86_l_cf9;
	case 3326ULL: goto x86_l_cfe;
	case 3330ULL: goto x86_l_d02;
	case 3335ULL: goto x86_l_d07;
	case 3339ULL: goto x86_l_d0b;
	case 3344ULL: goto x86_l_d10;
	case 3349ULL: goto x86_l_d15;
	case 3351ULL: goto x86_l_d17;
	case 3354ULL: goto x86_l_d1a;
	case 3356ULL: goto x86_l_d1c;
	case 3359ULL: goto x86_l_d1f;
	case 3361ULL: goto x86_l_d21;
	case 3364ULL: goto x86_l_d24;
	case 3367ULL: goto x86_l_d27;
	case 3373ULL: goto x86_l_d2d;
	case 3376ULL: goto x86_l_d30;
	case 3381ULL: goto x86_l_d35;
	case 3384ULL: goto x86_l_d38;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6c4:
	/* 0x6c4: jmp    31d3 <generic_retkprobe_filter_arg+0x31d3> */
	return 12755ULL;
x86_l_6c9:
	/* 0x6c9: lea    edx,[rcx-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_6cc:
	/* 0x6cc: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_6cf:
	/* 0x6cf: jae    baa <generic_retkprobe_filter_arg+0xbaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_baa;
	}
x86_l_6d5:
	/* 0x6d5: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_6d8:
	/* 0x6d8: ja     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 187ULL;
	}
x86_l_6de:
	/* 0x6de: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_6e0:
	/* 0x6e0: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_6e5:
	/* 0x6e5: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_6e9:
	/* 0x6e9: jae    733 <generic_retkprobe_filter_arg+0x733> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_733;
	}
x86_l_6eb:
	/* 0x6eb: mov    edx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f0:
	/* 0x6f0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6f3:
	/* 0x6f3: jle    b72 <generic_retkprobe_filter_arg+0xb72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_b72;
	}
x86_l_6f9:
	/* 0x6f9: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_6fc:
	/* 0x6fc: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_6ff:
	/* 0x6ff: jae    1038 <generic_retkprobe_filter_arg+0x1038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4152ULL;
	}
x86_l_705:
	/* 0x705: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_709:
	/* 0x709: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 595ULL;
	}
x86_l_70f:
	/* 0x70f: jmp    2180 <generic_retkprobe_filter_arg+0x2180> */
	return 8576ULL;
x86_l_714:
	/* 0x714: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_717:
	/* 0x717: je     cea <generic_retkprobe_filter_arg+0xcea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cea;
	}
x86_l_71d:
	/* 0x71d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_720:
	/* 0x720: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_725:
	/* 0x725: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_728:
	/* 0x728: je     d17 <generic_retkprobe_filter_arg+0xd17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d17;
	}
x86_l_72e:
	/* 0x72e: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_733:
	/* 0x733: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_738:
	/* 0x738: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_73c:
	/* 0x73c: jb     ca9 <generic_retkprobe_filter_arg+0xca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ca9;
	}
x86_l_742:
	/* 0x742: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_74c:
	/* 0x74c: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_750:
	/* 0x750: jae    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 187ULL;
	}
x86_l_756:
	/* 0x756: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_759:
	/* 0x759: jne    12fd <generic_retkprobe_filter_arg+0x12fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4861ULL;
	}
x86_l_75f:
	/* 0x75f: mov    esi,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_764:
	/* 0x764: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_769:
	/* 0x769: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_76c:
	/* 0x76c: ja     1ec7 <generic_retkprobe_filter_arg+0x1ec7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7879ULL;
	}
x86_l_772:
	/* 0x772: mov    eax,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5122ULL);
x86_l_777:
	/* 0x777: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_77a:
	/* 0x77a: jae    1ec7 <generic_retkprobe_filter_arg+0x1ec7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7879ULL;
	}
x86_l_780:
	/* 0x780: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_784:
	/* 0x784: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_786:
	/* 0x786: jg     1ed7 <generic_retkprobe_filter_arg+0x1ed7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7895ULL;
	}
x86_l_78c:
	/* 0x78c: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_78e:
	/* 0x78e: jle    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 620ULL;
	}
x86_l_794:
	/* 0x794: jmp    1ed7 <generic_retkprobe_filter_arg+0x1ed7> */
	return 7895ULL;
x86_l_799:
	/* 0x799: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_79c:
	/* 0x79c: jg     d9b <generic_retkprobe_filter_arg+0xd9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3483ULL;
	}
x86_l_7a2:
	/* 0x7a2: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_7a5:
	/* 0x7a5: je     ed7 <generic_retkprobe_filter_arg+0xed7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3799ULL;
	}
x86_l_7ab:
	/* 0x7ab: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_7b0:
	/* 0x7b0: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_7b3:
	/* 0x7b3: jne    357d <generic_retkprobe_filter_arg+0x357d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13693ULL;
	}
x86_l_7b9:
	/* 0x7b9: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7be:
	/* 0x7be: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7c2:
	/* 0x7c2: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_7ca:
	/* 0x7ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7cf:
	/* 0x7cf: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7d4:
	/* 0x7d4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_7db:
	/* 0x7db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7dd:
	/* 0x7dd: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_7df:
	/* 0x7df: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13677ULL;
	}
x86_l_7e5:
	/* 0x7e5: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_7ea:
	/* 0x7ea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7ed:
	/* 0x7ed: je     356f <generic_retkprobe_filter_arg+0x356f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13679ULL;
	}
x86_l_7f3:
	/* 0x7f3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7f8:
	/* 0x7f8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7fd:
	/* 0x7fd: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_802:
	/* 0x802: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_809:
	/* 0x809: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80b:
	/* 0x80b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_80e:
	/* 0x80e: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13677ULL;
	}
x86_l_814:
	/* 0x814: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_817:
	/* 0x817: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_81a:
	/* 0x81a: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_81f:
	/* 0x81f: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_822:
	/* 0x822: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_825:
	/* 0x825: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_827:
	/* 0x827: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_82a:
	/* 0x82a: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_82d:
	/* 0x82d: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_832:
	/* 0x832: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_835:
	/* 0x835: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_838:
	/* 0x838: mov    QWORD PTR [rsp+0x68],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_83d:
	/* 0x83d: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_841:
	/* 0x841: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_847:
	/* 0x847: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_84a:
	/* 0x84a: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_84e:
	/* 0x84e: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_854:
	/* 0x854: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_857:
	/* 0x857: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_85b:
	/* 0x85b: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_85d:
	/* 0x85d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_85f:
	/* 0x85f: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_862:
	/* 0x862: lea    r13d,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_866:
	/* 0x866: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_86d:
	/* 0x86d: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_872:
	/* 0x872: mov    BYTE PTR [rdi-0x3],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_876:
	/* 0x876: cmp    r10,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RBX, X86_WIDTH_64);
x86_l_879:
	/* 0x879: je     8d3 <generic_retkprobe_filter_arg+0x8d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8d3;
	}
x86_l_87b:
	/* 0x87b: lea    r13d,[r11+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_87f:
	/* 0x87f: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_886:
	/* 0x886: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_88b:
	/* 0x88b: mov    BYTE PTR [rdi-0x2],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_88f:
	/* 0x88f: cmp    r8,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RBX, X86_WIDTH_64);
x86_l_892:
	/* 0x892: je     8d3 <generic_retkprobe_filter_arg+0x8d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8d3;
	}
x86_l_894:
	/* 0x894: lea    r13d,[r9+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_898:
	/* 0x898: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_89f:
	/* 0x89f: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_8a4:
	/* 0x8a4: mov    BYTE PTR [rdi-0x1],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_8a8:
	/* 0x8a8: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_8ab:
	/* 0x8ab: je     8d3 <generic_retkprobe_filter_arg+0x8d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8d3;
	}
x86_l_8ad:
	/* 0x8ad: cmp    rbx,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_8b1:
	/* 0x8b1: je     8d3 <generic_retkprobe_filter_arg+0x8d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8d3;
	}
x86_l_8b3:
	/* 0x8b3: lea    r13d,[rdx+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_8b7:
	/* 0x8b7: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8be:
	/* 0x8be: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_8c3:
	/* 0x8c3: mov    BYTE PTR [rdi],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c6:
	/* 0x8c6: add    rbx,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_8ca:
	/* 0x8ca: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_8ce:
	/* 0x8ce: cmp    rax,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_8d1:
	/* 0x8d1: jne    862 <generic_retkprobe_filter_arg+0x862> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_862;
	}
x86_l_8d3:
	/* 0x8d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8d8:
	/* 0x8d8: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8dd:
	/* 0x8dd: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8e2:
	/* 0x8e2: jmp    1a18 <generic_retkprobe_filter_arg+0x1a18> */
	return 6680ULL;
x86_l_8e7:
	/* 0x8e7: add    eax,0xfffffffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967293ULL);
x86_l_8ea:
	/* 0x8ea: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8ed:
	/* 0x8ed: jae    903 <generic_retkprobe_filter_arg+0x903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_903;
	}
x86_l_8ef:
	/* 0x8ef: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_8f7:
	/* 0x8f7: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_8fd:
	/* 0x8fd: jbe    1142 <generic_retkprobe_filter_arg+0x1142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4418ULL;
	}
x86_l_903:
	/* 0x903: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_905:
	/* 0x905: jmp    31e1 <generic_retkprobe_filter_arg+0x31e1> */
	return 12769ULL;
x86_l_90a:
	/* 0x90a: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_90d:
	/* 0x90d: ja     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 187ULL;
	}
x86_l_913:
	/* 0x913: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_915:
	/* 0x915: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_91a:
	/* 0x91a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_91e:
	/* 0x91e: jae    1083 <generic_retkprobe_filter_arg+0x1083> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4227ULL;
	}
x86_l_924:
	/* 0x924: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_929:
	/* 0x929: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_92c:
	/* 0x92c: jle    15c9 <generic_retkprobe_filter_arg+0x15c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5577ULL;
	}
x86_l_932:
	/* 0x932: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_935:
	/* 0x935: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_938:
	/* 0x938: jae    1d3a <generic_retkprobe_filter_arg+0x1d3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7482ULL;
	}
x86_l_93e:
	/* 0x93e: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_943:
	/* 0x943: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_945:
	/* 0x945: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 595ULL;
	}
x86_l_94b:
	/* 0x94b: jmp    1e8d <generic_retkprobe_filter_arg+0x1e8d> */
	return 7821ULL;
x86_l_950:
	/* 0x950: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_955:
	/* 0x955: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_959:
	/* 0x959: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_961:
	/* 0x961: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_966:
	/* 0x966: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_96b:
	/* 0x96b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_972:
	/* 0x972: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_974:
	/* 0x974: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_976:
	/* 0x976: je     31d1 <generic_retkprobe_filter_arg+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12753ULL;
	}
x86_l_97c:
	/* 0x97c: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_981:
	/* 0x981: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_984:
	/* 0x984: je     31d3 <generic_retkprobe_filter_arg+0x31d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12755ULL;
	}
x86_l_98a:
	/* 0x98a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_98f:
	/* 0x98f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_994:
	/* 0x994: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_999:
	/* 0x999: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_9a0:
	/* 0x9a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a2:
	/* 0x9a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9a5:
	/* 0x9a5: je     31d1 <generic_retkprobe_filter_arg+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12753ULL;
	}
x86_l_9ab:
	/* 0x9ab: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_9ae:
	/* 0x9ae: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_9b1:
	/* 0x9b1: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_9b6:
	/* 0x9b6: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_9b9:
	/* 0x9b9: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_9bc:
	/* 0x9bc: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9be:
	/* 0x9be: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_9c1:
	/* 0x9c1: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_9c4:
	/* 0x9c4: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_9c9:
	/* 0x9c9: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_9cc:
	/* 0x9cc: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_9cf:
	/* 0x9cf: mov    QWORD PTR [rsp+0x68],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9d4:
	/* 0x9d4: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_9d8:
	/* 0x9d8: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_9de:
	/* 0x9de: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_9e1:
	/* 0x9e1: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_9e5:
	/* 0x9e5: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_9eb:
	/* 0x9eb: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_9ee:
	/* 0x9ee: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_9f2:
	/* 0x9f2: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_9f4:
	/* 0x9f4: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f6:
	/* 0x9f6: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_9f9:
	/* 0x9f9: lea    r13d,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_9fd:
	/* 0x9fd: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a04:
	/* 0xa04: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_a0a:
	/* 0xa0a: mov    BYTE PTR [rdi-0x3],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_a0e:
	/* 0xa0e: cmp    r10,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RBX, X86_WIDTH_64);
x86_l_a11:
	/* 0xa11: je     a6e <generic_retkprobe_filter_arg+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_a13:
	/* 0xa13: lea    r13d,[r11+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_a17:
	/* 0xa17: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a1e:
	/* 0xa1e: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_a24:
	/* 0xa24: mov    BYTE PTR [rdi-0x2],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_a28:
	/* 0xa28: cmp    r8,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RBX, X86_WIDTH_64);
x86_l_a2b:
	/* 0xa2b: je     a6e <generic_retkprobe_filter_arg+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_a2d:
	/* 0xa2d: lea    r13d,[r9+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_a31:
	/* 0xa31: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a38:
	/* 0xa38: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_a3e:
	/* 0xa3e: mov    BYTE PTR [rdi-0x1],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_a42:
	/* 0xa42: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_a45:
	/* 0xa45: je     a6e <generic_retkprobe_filter_arg+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_a47:
	/* 0xa47: cmp    rbx,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_a4b:
	/* 0xa4b: je     a6e <generic_retkprobe_filter_arg+0xa6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a6e;
	}
x86_l_a4d:
	/* 0xa4d: lea    r13d,[rdx+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_a51:
	/* 0xa51: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a58:
	/* 0xa58: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_a5e:
	/* 0xa5e: mov    BYTE PTR [rdi],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a61:
	/* 0xa61: add    rbx,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_a65:
	/* 0xa65: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a69:
	/* 0xa69: cmp    rax,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_a6c:
	/* 0xa6c: jne    9f9 <generic_retkprobe_filter_arg+0x9f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9f9;
	}
x86_l_a6e:
	/* 0xa6e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a73:
	/* 0xa73: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a78:
	/* 0xa78: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a7d:
	/* 0xa7d: jmp    31c5 <generic_retkprobe_filter_arg+0x31c5> */
	return 12741ULL;
x86_l_a82:
	/* 0xa82: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a87:
	/* 0xa87: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a8c:
	/* 0xa8c: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a90:
	/* 0xa90: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_a98:
	/* 0xa98: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a9d:
	/* 0xa9d: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_aa2:
	/* 0xaa2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_aa9:
	/* 0xaa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aab:
	/* 0xaab: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_aad:
	/* 0xaad: je     31d1 <generic_retkprobe_filter_arg+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12753ULL;
	}
x86_l_ab3:
	/* 0xab3: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_ab6:
	/* 0xab6: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_abb:
	/* 0xabb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_abe:
	/* 0xabe: je     31d3 <generic_retkprobe_filter_arg+0x31d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12755ULL;
	}
x86_l_ac4:
	/* 0xac4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ac9:
	/* 0xac9: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ace:
	/* 0xace: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_ad5:
	/* 0xad5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad7:
	/* 0xad7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ada:
	/* 0xada: je     31d1 <generic_retkprobe_filter_arg+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12753ULL;
	}
x86_l_ae0:
	/* 0xae0: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_ae3:
	/* 0xae3: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ae8:
	/* 0xae8: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_aec:
	/* 0xaec: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_af2:
	/* 0xaf2: mov    eax,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_af7:
	/* 0xaf7: cmovae ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_afa:
	/* 0xafa: lea    eax,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_b01:
	/* 0xb01: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b03:
	/* 0xb03: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b06:
	/* 0xb06: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_b0a:
	/* 0xb0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b0f:
	/* 0xb0f: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_b11:
	/* 0xb11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b13:
	/* 0xb13: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b18:
	/* 0xb18: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_b1b:
	/* 0xb1b: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_b1e:
	/* 0xb1e: jmp    31c5 <generic_retkprobe_filter_arg+0x31c5> */
	return 12741ULL;
x86_l_b23:
	/* 0xb23: lea    edx,[rax-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_b26:
	/* 0xb26: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_b29:
	/* 0xb29: jb     bc9 <generic_retkprobe_filter_arg+0xbc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_bc9;
	}
x86_l_b2f:
	/* 0xb2f: jmp    bb <generic_retkprobe_filter_arg+0xbb> */
	return 187ULL;
x86_l_b34:
	/* 0xb34: mov    ebp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b38:
	/* 0xb38: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b3c:
	/* 0xb3c: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_b3f:
	/* 0xb3f: jg     11a5 <generic_retkprobe_filter_arg+0x11a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4517ULL;
	}
x86_l_b45:
	/* 0xb45: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_b48:
	/* 0xb48: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b4b:
	/* 0xb4b: jb     1a27 <generic_retkprobe_filter_arg+0x1a27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6695ULL;
	}
x86_l_b51:
	/* 0xb51: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b56:
	/* 0xb56: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_b59:
	/* 0xb59: je     1985 <generic_retkprobe_filter_arg+0x1985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6533ULL;
	}
x86_l_b5f:
	/* 0xb5f: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_b64:
	/* 0xb64: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_b67:
	/* 0xb67: je     11ca <generic_retkprobe_filter_arg+0x11ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4554ULL;
	}
x86_l_b6d:
	/* 0xb6d: jmp    357d <generic_retkprobe_filter_arg+0x357d> */
	return 13693ULL;
x86_l_b72:
	/* 0xb72: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b75:
	/* 0xb75: je     148c <generic_retkprobe_filter_arg+0x148c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5260ULL;
	}
x86_l_b7b:
	/* 0xb7b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b7e:
	/* 0xb7e: jne    2180 <generic_retkprobe_filter_arg+0x2180> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8576ULL;
	}
x86_l_b84:
	/* 0xb84: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_b87:
	/* 0xb87: ja     2176 <generic_retkprobe_filter_arg+0x2176> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8566ULL;
	}
x86_l_b8d:
	/* 0xb8d: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_b92:
	/* 0xb92: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_b95:
	/* 0xb95: jae    2176 <generic_retkprobe_filter_arg+0x2176> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8566ULL;
	}
x86_l_b9b:
	/* 0xb9b: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b9f:
	/* 0xb9f: jl     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 620ULL;
	}
x86_l_ba5:
	/* 0xba5: jmp    2180 <generic_retkprobe_filter_arg+0x2180> */
	return 8576ULL;
x86_l_baa:
	/* 0xbaa: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_bad:
	/* 0xbad: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_bb3:
	/* 0xbb3: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_bb6:
	/* 0xbb6: ja     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 187ULL;
	}
x86_l_bbc:
	/* 0xbbc: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_bbe:
	/* 0xbbe: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_bc3:
	/* 0xbc3: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_bc7:
	/* 0xbc7: jae    bee <generic_retkprobe_filter_arg+0xbee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_bee;
	}
x86_l_bc9:
	/* 0xbc9: mov    rdx,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bce:
	/* 0xbce: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bd1:
	/* 0xbd1: jle    c12 <generic_retkprobe_filter_arg+0xc12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c12;
	}
x86_l_bd3:
	/* 0xbd3: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_bd6:
	/* 0xbd6: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_bd9:
	/* 0xbd9: jae    e77 <generic_retkprobe_filter_arg+0xe77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3703ULL;
	}
x86_l_bdf:
	/* 0xbdf: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be3:
	/* 0xbe3: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 595ULL;
	}
x86_l_be9:
	/* 0xbe9: jmp    1ca1 <generic_retkprobe_filter_arg+0x1ca1> */
	return 7329ULL;
x86_l_bee:
	/* 0xbee: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_bf3:
	/* 0xbf3: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_bf7:
	/* 0xbf7: jb     c41 <generic_retkprobe_filter_arg+0xc41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c41;
	}
x86_l_bf9:
	/* 0xbf9: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_c03:
	/* 0xc03: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_c07:
	/* 0xc07: jb     e9b <generic_retkprobe_filter_arg+0xe9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3739ULL;
	}
x86_l_c0d:
	/* 0xc0d: jmp    bb <generic_retkprobe_filter_arg+0xbb> */
	return 187ULL;
x86_l_c12:
	/* 0xc12: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c15:
	/* 0xc15: je     1125 <generic_retkprobe_filter_arg+0x1125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4389ULL;
	}
x86_l_c1b:
	/* 0xc1b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c1e:
	/* 0xc1e: jne    1ca1 <generic_retkprobe_filter_arg+0x1ca1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7329ULL;
	}
x86_l_c24:
	/* 0xc24: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_c27:
	/* 0xc27: je     c32 <generic_retkprobe_filter_arg+0xc32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c32;
	}
x86_l_c29:
	/* 0xc29: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_c2c:
	/* 0xc2c: jne    1c97 <generic_retkprobe_filter_arg+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7319ULL;
	}
x86_l_c32:
	/* 0xc32: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c36:
	/* 0xc36: jl     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 620ULL;
	}
x86_l_c3c:
	/* 0xc3c: jmp    1ca1 <generic_retkprobe_filter_arg+0x1ca1> */
	return 7329ULL;
x86_l_c41:
	/* 0xc41: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_c47:
	/* 0xc47: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c4b:
	/* 0xc4b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c50:
	/* 0xc50: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c55:
	/* 0xc55: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_c5c:
	/* 0xc5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5e:
	/* 0xc5e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c61:
	/* 0xc61: je     20e8 <generic_retkprobe_filter_arg+0x20e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8424ULL;
	}
x86_l_c67:
	/* 0xc67: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c6a:
	/* 0xc6a: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c6e:
	/* 0xc6e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c73:
	/* 0xc73: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c78:
	/* 0xc78: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c7d:
	/* 0xc7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7f:
	/* 0xc7f: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c84:
	/* 0xc84: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_c87:
	/* 0xc87: je     17c3 <generic_retkprobe_filter_arg+0x17c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6083ULL;
	}
x86_l_c8d:
	/* 0xc8d: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_c90:
	/* 0xc90: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c94:
	/* 0xc94: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c99:
	/* 0xc99: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c9e:
	/* 0xc9e: je     17ab <generic_retkprobe_filter_arg+0x17ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6059ULL;
	}
x86_l_ca4:
	/* 0xca4: jmp    17b9 <generic_retkprobe_filter_arg+0x17b9> */
	return 6073ULL;
x86_l_ca9:
	/* 0xca9: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_caf:
	/* 0xcaf: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_cb3:
	/* 0xcb3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cb8:
	/* 0xcb8: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cbd:
	/* 0xcbd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_cc4:
	/* 0xcc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc6:
	/* 0xcc6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cc9:
	/* 0xcc9: je     20e8 <generic_retkprobe_filter_arg+0x20e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8424ULL;
	}
x86_l_ccf:
	/* 0xccf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_cd2:
	/* 0xcd2: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cd6:
	/* 0xcd6: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cdb:
	/* 0xcdb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ce0:
	/* 0xce0: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ce5:
	/* 0xce5: jmp    1b7e <generic_retkprobe_filter_arg+0x1b7e> */
	return 7038ULL;
x86_l_cea:
	/* 0xcea: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_cef:
	/* 0xcef: mov    WORD PTR [rsp+0x5e],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_cf4:
	/* 0xcf4: movzx  edx,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_cf9:
	/* 0xcf9: mov    WORD PTR [rsp+0x58],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cfe:
	/* 0xcfe: mov    rdx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d02:
	/* 0xd02: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d07:
	/* 0xd07: mov    rdx,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d0b:
	/* 0xd0b: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d10:
	/* 0xd10: lea    r13,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d15:
	/* 0xd15: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d17:
	/* 0xd17: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_d1a:
	/* 0xd1a: jle    d43 <generic_retkprobe_filter_arg+0xd43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3395ULL;
	}
x86_l_d1c:
	/* 0xd1c: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_d1f:
	/* 0xd1f: jg     d76 <generic_retkprobe_filter_arg+0xd76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3446ULL;
	}
x86_l_d21:
	/* 0xd21: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_d24:
	/* 0xd24: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d27:
	/* 0xd27: jb     136e <generic_retkprobe_filter_arg+0x136e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4974ULL;
	}
x86_l_d2d:
	/* 0xd2d: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_d30:
	/* 0xd30: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_d35:
	/* 0xd35: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d38:
	/* 0xd38: jb     1364 <generic_retkprobe_filter_arg+0x1364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4964ULL;
	}
	return 3390ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3390ULL: goto x86_l_d3e;
	case 3395ULL: goto x86_l_d43;
	case 3398ULL: goto x86_l_d46;
	case 3404ULL: goto x86_l_d4c;
	case 3407ULL: goto x86_l_d4f;
	case 3413ULL: goto x86_l_d55;
	case 3416ULL: goto x86_l_d58;
	case 3422ULL: goto x86_l_d5e;
	case 3427ULL: goto x86_l_d63;
	case 3430ULL: goto x86_l_d66;
	case 3436ULL: goto x86_l_d6c;
	case 3441ULL: goto x86_l_d71;
	case 3446ULL: goto x86_l_d76;
	case 3449ULL: goto x86_l_d79;
	case 3455ULL: goto x86_l_d7f;
	case 3458ULL: goto x86_l_d82;
	case 3464ULL: goto x86_l_d88;
	case 3469ULL: goto x86_l_d8d;
	case 3472ULL: goto x86_l_d90;
	case 3478ULL: goto x86_l_d96;
	case 3483ULL: goto x86_l_d9b;
	case 3486ULL: goto x86_l_d9e;
	case 3492ULL: goto x86_l_da4;
	case 3497ULL: goto x86_l_da9;
	case 3500ULL: goto x86_l_dac;
	case 3506ULL: goto x86_l_db2;
	case 3511ULL: goto x86_l_db7;
	case 3513ULL: goto x86_l_db9;
	case 3516ULL: goto x86_l_dbc;
	case 3521ULL: goto x86_l_dc1;
	case 3525ULL: goto x86_l_dc5;
	case 3530ULL: goto x86_l_dca;
	case 3535ULL: goto x86_l_dcf;
	case 3542ULL: goto x86_l_dd6;
	case 3544ULL: goto x86_l_dd8;
	case 3547ULL: goto x86_l_ddb;
	case 3553ULL: goto x86_l_de1;
	case 3555ULL: goto x86_l_de3;
	case 3560ULL: goto x86_l_de8;
	case 3562ULL: goto x86_l_dea;
	case 3567ULL: goto x86_l_def;
	case 3569ULL: goto x86_l_df1;
	case 3571ULL: goto x86_l_df3;
	case 3574ULL: goto x86_l_df6;
	case 3577ULL: goto x86_l_df9;
	case 3580ULL: goto x86_l_dfc;
	case 3582ULL: goto x86_l_dfe;
	case 3584ULL: goto x86_l_e00;
	case 3588ULL: goto x86_l_e04;
	case 3591ULL: goto x86_l_e07;
	case 3593ULL: goto x86_l_e09;
	case 3597ULL: goto x86_l_e0d;
	case 3599ULL: goto x86_l_e0f;
	case 3601ULL: goto x86_l_e11;
	case 3606ULL: goto x86_l_e16;
	case 3610ULL: goto x86_l_e1a;
	case 3613ULL: goto x86_l_e1d;
	case 3617ULL: goto x86_l_e21;
	case 3621ULL: goto x86_l_e25;
	case 3625ULL: goto x86_l_e29;
	case 3629ULL: goto x86_l_e2d;
	case 3632ULL: goto x86_l_e30;
	case 3636ULL: goto x86_l_e34;
	case 3640ULL: goto x86_l_e38;
	case 3644ULL: goto x86_l_e3c;
	case 3648ULL: goto x86_l_e40;
	case 3650ULL: goto x86_l_e42;
	case 3653ULL: goto x86_l_e45;
	case 3656ULL: goto x86_l_e48;
	case 3658ULL: goto x86_l_e4a;
	case 3660ULL: goto x86_l_e4c;
	case 3662ULL: goto x86_l_e4e;
	case 3668ULL: goto x86_l_e54;
	case 3672ULL: goto x86_l_e58;
	case 3677ULL: goto x86_l_e5d;
	case 3679ULL: goto x86_l_e5f;
	case 3683ULL: goto x86_l_e63;
	case 3686ULL: goto x86_l_e66;
	case 3690ULL: goto x86_l_e6a;
	case 3696ULL: goto x86_l_e70;
	case 3698ULL: goto x86_l_e72;
	case 3703ULL: goto x86_l_e77;
	case 3706ULL: goto x86_l_e7a;
	case 3712ULL: goto x86_l_e80;
	case 3716ULL: goto x86_l_e84;
	case 3722ULL: goto x86_l_e8a;
	case 3727ULL: goto x86_l_e8f;
	case 3730ULL: goto x86_l_e92;
	case 3733ULL: goto x86_l_e95;
	case 3739ULL: goto x86_l_e9b;
	case 3742ULL: goto x86_l_e9e;
	case 3748ULL: goto x86_l_ea4;
	case 3753ULL: goto x86_l_ea9;
	case 3758ULL: goto x86_l_eae;
	case 3761ULL: goto x86_l_eb1;
	case 3763ULL: goto x86_l_eb3;
	case 3766ULL: goto x86_l_eb6;
	case 3772ULL: goto x86_l_ebc;
	case 3776ULL: goto x86_l_ec0;
	case 3779ULL: goto x86_l_ec3;
	case 3785ULL: goto x86_l_ec9;
	case 3788ULL: goto x86_l_ecc;
	case 3794ULL: goto x86_l_ed2;
	case 3799ULL: goto x86_l_ed7;
	case 3804ULL: goto x86_l_edc;
	case 3809ULL: goto x86_l_ee1;
	case 3813ULL: goto x86_l_ee5;
	case 3821ULL: goto x86_l_eed;
	case 3826ULL: goto x86_l_ef2;
	case 3831ULL: goto x86_l_ef7;
	case 3838ULL: goto x86_l_efe;
	case 3840ULL: goto x86_l_f00;
	case 3842ULL: goto x86_l_f02;
	case 3848ULL: goto x86_l_f08;
	case 3851ULL: goto x86_l_f0b;
	case 3856ULL: goto x86_l_f10;
	case 3859ULL: goto x86_l_f13;
	case 3865ULL: goto x86_l_f19;
	case 3870ULL: goto x86_l_f1e;
	case 3875ULL: goto x86_l_f23;
	case 3882ULL: goto x86_l_f2a;
	case 3884ULL: goto x86_l_f2c;
	case 3887ULL: goto x86_l_f2f;
	case 3893ULL: goto x86_l_f35;
	case 3899ULL: goto x86_l_f3b;
	case 3904ULL: goto x86_l_f40;
	case 3907ULL: goto x86_l_f43;
	case 3914ULL: goto x86_l_f4a;
	case 3916ULL: goto x86_l_f4c;
	case 3919ULL: goto x86_l_f4f;
	case 3923ULL: goto x86_l_f53;
	case 3926ULL: goto x86_l_f56;
	case 3931ULL: goto x86_l_f5b;
	case 3936ULL: goto x86_l_f60;
	case 3938ULL: goto x86_l_f62;
	case 3940ULL: goto x86_l_f64;
	case 3945ULL: goto x86_l_f69;
	case 3950ULL: goto x86_l_f6e;
	case 3958ULL: goto x86_l_f76;
	case 3964ULL: goto x86_l_f7c;
	case 3970ULL: goto x86_l_f82;
	case 3973ULL: goto x86_l_f85;
	case 3978ULL: goto x86_l_f8a;
	case 3983ULL: goto x86_l_f8f;
	case 3989ULL: goto x86_l_f95;
	case 3993ULL: goto x86_l_f99;
	case 3999ULL: goto x86_l_f9f;
	case 4002ULL: goto x86_l_fa2;
	case 4005ULL: goto x86_l_fa5;
	case 4008ULL: goto x86_l_fa8;
	case 4010ULL: goto x86_l_faa;
	case 4013ULL: goto x86_l_fad;
	case 4015ULL: goto x86_l_faf;
	case 4017ULL: goto x86_l_fb1;
	case 4019ULL: goto x86_l_fb3;
	case 4021ULL: goto x86_l_fb5;
	case 4023ULL: goto x86_l_fb7;
	case 4026ULL: goto x86_l_fba;
	case 4028ULL: goto x86_l_fbc;
	case 4030ULL: goto x86_l_fbe;
	case 4032ULL: goto x86_l_fc0;
	case 4035ULL: goto x86_l_fc3;
	case 4038ULL: goto x86_l_fc6;
	case 4042ULL: goto x86_l_fca;
	case 4048ULL: goto x86_l_fd0;
	case 4050ULL: goto x86_l_fd2;
	case 4053ULL: goto x86_l_fd5;
	case 4059ULL: goto x86_l_fdb;
	case 4062ULL: goto x86_l_fde;
	case 4064ULL: goto x86_l_fe0;
	case 4069ULL: goto x86_l_fe5;
	case 4072ULL: goto x86_l_fe8;
	case 4078ULL: goto x86_l_fee;
	case 4081ULL: goto x86_l_ff1;
	case 4087ULL: goto x86_l_ff7;
	case 4092ULL: goto x86_l_ffc;
	case 4095ULL: goto x86_l_fff;
	case 4101ULL: goto x86_l_1005;
	case 4106ULL: goto x86_l_100a;
	case 4111ULL: goto x86_l_100f;
	case 4116ULL: goto x86_l_1014;
	case 4119ULL: goto x86_l_1017;
	case 4121ULL: goto x86_l_1019;
	case 4124ULL: goto x86_l_101c;
	case 4130ULL: goto x86_l_1022;
	case 4134ULL: goto x86_l_1026;
	case 4137ULL: goto x86_l_1029;
	case 4141ULL: goto x86_l_102d;
	case 4144ULL: goto x86_l_1030;
	case 4147ULL: goto x86_l_1033;
	case 4152ULL: goto x86_l_1038;
	case 4155ULL: goto x86_l_103b;
	case 4161ULL: goto x86_l_1041;
	case 4165ULL: goto x86_l_1045;
	case 4171ULL: goto x86_l_104b;
	case 4176ULL: goto x86_l_1050;
	case 4181ULL: goto x86_l_1055;
	case 4185ULL: goto x86_l_1059;
	case 4191ULL: goto x86_l_105f;
	case 4201ULL: goto x86_l_1069;
	case 4205ULL: goto x86_l_106d;
	case 4211ULL: goto x86_l_1073;
	case 4214ULL: goto x86_l_1076;
	case 4220ULL: goto x86_l_107c;
	case 4225ULL: goto x86_l_1081;
	case 4227ULL: goto x86_l_1083;
	case 4232ULL: goto x86_l_1088;
	case 4236ULL: goto x86_l_108c;
	case 4242ULL: goto x86_l_1092;
	case 4252ULL: goto x86_l_109c;
	case 4256ULL: goto x86_l_10a0;
	case 4262ULL: goto x86_l_10a6;
	case 4265ULL: goto x86_l_10a9;
	case 4271ULL: goto x86_l_10af;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4283ULL: goto x86_l_10bb;
	case 4288ULL: goto x86_l_10c0;
	case 4294ULL: goto x86_l_10c6;
	case 4299ULL: goto x86_l_10cb;
	case 4302ULL: goto x86_l_10ce;
	case 4308ULL: goto x86_l_10d4;
	case 4313ULL: goto x86_l_10d9;
	case 4315ULL: goto x86_l_10db;
	case 4320ULL: goto x86_l_10e0;
	case 4326ULL: goto x86_l_10e6;
	case 4329ULL: goto x86_l_10e9;
	case 4335ULL: goto x86_l_10ef;
	case 4340ULL: goto x86_l_10f4;
	case 4342ULL: goto x86_l_10f6;
	case 4347ULL: goto x86_l_10fb;
	case 4353ULL: goto x86_l_1101;
	case 4356ULL: goto x86_l_1104;
	case 4362ULL: goto x86_l_110a;
	case 4367ULL: goto x86_l_110f;
	case 4373ULL: goto x86_l_1115;
	case 4378ULL: goto x86_l_111a;
	case 4384ULL: goto x86_l_1120;
	case 4389ULL: goto x86_l_1125;
	case 4392ULL: goto x86_l_1128;
	case 4394ULL: goto x86_l_112a;
	case 4397ULL: goto x86_l_112d;
	case 4403ULL: goto x86_l_1133;
	case 4407ULL: goto x86_l_1137;
	case 4413ULL: goto x86_l_113d;
	case 4418ULL: goto x86_l_1142;
	case 4421ULL: goto x86_l_1145;
	case 4426ULL: goto x86_l_114a;
	case 4431ULL: goto x86_l_114f;
	case 4437ULL: goto x86_l_1155;
	case 4441ULL: goto x86_l_1159;
	case 4447ULL: goto x86_l_115f;
	case 4450ULL: goto x86_l_1162;
	case 4453ULL: goto x86_l_1165;
	case 4456ULL: goto x86_l_1168;
	case 4458ULL: goto x86_l_116a;
	case 4461ULL: goto x86_l_116d;
	case 4463ULL: goto x86_l_116f;
	case 4465ULL: goto x86_l_1171;
	case 4467ULL: goto x86_l_1173;
	case 4469ULL: goto x86_l_1175;
	case 4471ULL: goto x86_l_1177;
	case 4474ULL: goto x86_l_117a;
	case 4476ULL: goto x86_l_117c;
	case 4478ULL: goto x86_l_117e;
	case 4480ULL: goto x86_l_1180;
	case 4483ULL: goto x86_l_1183;
	case 4486ULL: goto x86_l_1186;
	case 4490ULL: goto x86_l_118a;
	case 4496ULL: goto x86_l_1190;
	case 4498ULL: goto x86_l_1192;
	case 4501ULL: goto x86_l_1195;
	case 4507ULL: goto x86_l_119b;
	case 4510ULL: goto x86_l_119e;
	case 4512ULL: goto x86_l_11a0;
	case 4517ULL: goto x86_l_11a5;
	case 4520ULL: goto x86_l_11a8;
	case 4525ULL: goto x86_l_11ad;
	case 4531ULL: goto x86_l_11b3;
	case 4534ULL: goto x86_l_11b6;
	case 4540ULL: goto x86_l_11bc;
	case 4545ULL: goto x86_l_11c1;
	case 4548ULL: goto x86_l_11c4;
	case 4554ULL: goto x86_l_11ca;
	case 4559ULL: goto x86_l_11cf;
	case 4563ULL: goto x86_l_11d3;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4581ULL: goto x86_l_11e5;
	case 4588ULL: goto x86_l_11ec;
	case 4590ULL: goto x86_l_11ee;
	case 4592ULL: goto x86_l_11f0;
	case 4598ULL: goto x86_l_11f6;
	case 4601ULL: goto x86_l_11f9;
	case 4606ULL: goto x86_l_11fe;
	case 4609ULL: goto x86_l_1201;
	case 4615ULL: goto x86_l_1207;
	case 4620ULL: goto x86_l_120c;
	case 4625ULL: goto x86_l_1211;
	case 4632ULL: goto x86_l_1218;
	case 4634ULL: goto x86_l_121a;
	case 4637ULL: goto x86_l_121d;
	case 4643ULL: goto x86_l_1223;
	case 4646ULL: goto x86_l_1226;
	case 4651ULL: goto x86_l_122b;
	case 4654ULL: goto x86_l_122e;
	case 4659ULL: goto x86_l_1233;
	case 4662ULL: goto x86_l_1236;
	case 4665ULL: goto x86_l_1239;
	case 4667ULL: goto x86_l_123b;
	case 4670ULL: goto x86_l_123e;
	case 4673ULL: goto x86_l_1241;
	case 4678ULL: goto x86_l_1246;
	case 4681ULL: goto x86_l_1249;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4693ULL: goto x86_l_1255;
	case 4699ULL: goto x86_l_125b;
	case 4702ULL: goto x86_l_125e;
	case 4706ULL: goto x86_l_1262;
	case 4712ULL: goto x86_l_1268;
	case 4715ULL: goto x86_l_126b;
	case 4719ULL: goto x86_l_126f;
	case 4721ULL: goto x86_l_1271;
	case 4723ULL: goto x86_l_1273;
	case 4728ULL: goto x86_l_1278;
	case 4732ULL: goto x86_l_127c;
	case 4739ULL: goto x86_l_1283;
	case 4744ULL: goto x86_l_1288;
	case 4748ULL: goto x86_l_128c;
	case 4751ULL: goto x86_l_128f;
	case 4753ULL: goto x86_l_1291;
	case 4757ULL: goto x86_l_1295;
	case 4764ULL: goto x86_l_129c;
	case 4769ULL: goto x86_l_12a1;
	case 4773ULL: goto x86_l_12a5;
	case 4776ULL: goto x86_l_12a8;
	case 4778ULL: goto x86_l_12aa;
	case 4782ULL: goto x86_l_12ae;
	case 4789ULL: goto x86_l_12b5;
	case 4794ULL: goto x86_l_12ba;
	case 4798ULL: goto x86_l_12be;
	case 4801ULL: goto x86_l_12c1;
	case 4803ULL: goto x86_l_12c3;
	case 4807ULL: goto x86_l_12c7;
	case 4809ULL: goto x86_l_12c9;
	case 4813ULL: goto x86_l_12cd;
	case 4820ULL: goto x86_l_12d4;
	case 4825ULL: goto x86_l_12d9;
	case 4828ULL: goto x86_l_12dc;
	case 4832ULL: goto x86_l_12e0;
	case 4836ULL: goto x86_l_12e4;
	case 4839ULL: goto x86_l_12e7;
	case 4841ULL: goto x86_l_12e9;
	case 4846ULL: goto x86_l_12ee;
	case 4851ULL: goto x86_l_12f3;
	case 4856ULL: goto x86_l_12f8;
	case 4861ULL: goto x86_l_12fd;
	case 4866ULL: goto x86_l_1302;
	case 4871ULL: goto x86_l_1307;
	case 4874ULL: goto x86_l_130a;
	case 4880ULL: goto x86_l_1310;
	case 4885ULL: goto x86_l_1315;
	case 4888ULL: goto x86_l_1318;
	case 4894ULL: goto x86_l_131e;
	case 4898ULL: goto x86_l_1322;
	case 4900ULL: goto x86_l_1324;
	case 4904ULL: goto x86_l_1328;
	case 4906ULL: goto x86_l_132a;
	case 4909ULL: goto x86_l_132d;
	case 4914ULL: goto x86_l_1332;
	case 4917ULL: goto x86_l_1335;
	case 4923ULL: goto x86_l_133b;
	case 4926ULL: goto x86_l_133e;
	case 4931ULL: goto x86_l_1343;
	case 4934ULL: goto x86_l_1346;
	case 4940ULL: goto x86_l_134c;
	case 4945ULL: goto x86_l_1351;
	case 4948ULL: goto x86_l_1354;
	case 4950ULL: goto x86_l_1356;
	case 4955ULL: goto x86_l_135b;
	case 4958ULL: goto x86_l_135e;
	case 4964ULL: goto x86_l_1364;
	case 4967ULL: goto x86_l_1367;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d3e:
	/* 0xd3e: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_d43:
	/* 0xd43: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_d46:
	/* 0xd46: jle    fe5 <generic_retkprobe_filter_arg+0xfe5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_fe5;
	}
x86_l_d4c:
	/* 0xd4c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_d4f:
	/* 0xd4f: jg     1351 <generic_retkprobe_filter_arg+0x1351> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1351;
	}
x86_l_d55:
	/* 0xd55: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_d58:
	/* 0xd58: je     1364 <generic_retkprobe_filter_arg+0x1364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1364;
	}
x86_l_d5e:
	/* 0xd5e: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_d63:
	/* 0xd63: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_d66:
	/* 0xd66: jne    25b <generic_retkprobe_filter_arg+0x25b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 603ULL;
	}
x86_l_d6c:
	/* 0xd6c: movzx  ebx,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_d71:
	/* 0xd71: jmp    1b43 <generic_retkprobe_filter_arg+0x1b43> */
	return 6979ULL;
x86_l_d76:
	/* 0xd76: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_d79:
	/* 0xd79: jg     13af <generic_retkprobe_filter_arg+0x13af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5039ULL;
	}
x86_l_d7f:
	/* 0xd7f: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_d82:
	/* 0xd82: je     13ec <generic_retkprobe_filter_arg+0x13ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5100ULL;
	}
x86_l_d88:
	/* 0xd88: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_d8d:
	/* 0xd8d: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_d90:
	/* 0xd90: je     13df <generic_retkprobe_filter_arg+0x13df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5087ULL;
	}
x86_l_d96:
	/* 0xd96: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_d9b:
	/* 0xd9b: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_d9e:
	/* 0xd9e: je     14b2 <generic_retkprobe_filter_arg+0x14b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5298ULL;
	}
x86_l_da4:
	/* 0xda4: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_da9:
	/* 0xda9: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_dac:
	/* 0xdac: jne    357d <generic_retkprobe_filter_arg+0x357d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13693ULL;
	}
x86_l_db2:
	/* 0xdb2: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_db7:
	/* 0xdb7: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_db9:
	/* 0xdb9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dbc:
	/* 0xdbc: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_dc1:
	/* 0xdc1: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_dc5:
	/* 0xdc5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dca:
	/* 0xdca: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_dcf:
	/* 0xdcf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_dd6:
	/* 0xdd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd8:
	/* 0xdd8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ddb:
	/* 0xddb: je     20fd <generic_retkprobe_filter_arg+0x20fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8445ULL;
	}
x86_l_de1:
	/* 0xde1: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_de3:
	/* 0xde3: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de8:
	/* 0xde8: je     e54 <generic_retkprobe_filter_arg+0xe54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e54;
	}
x86_l_dea:
	/* 0xdea: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_def:
	/* 0xdef: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_df1:
	/* 0xdf1: jmp    dfe <generic_retkprobe_filter_arg+0xdfe> */
	goto x86_l_dfe;
x86_l_df3:
	/* 0xdf3: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_df6:
	/* 0xdf6: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_df9:
	/* 0xdf9: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_dfc:
	/* 0xdfc: je     e54 <generic_retkprobe_filter_arg+0xe54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e54;
	}
x86_l_dfe:
	/* 0xdfe: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e00:
	/* 0xe00: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_e04:
	/* 0xe04: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_e07:
	/* 0xe07: jae    df3 <generic_retkprobe_filter_arg+0xdf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_df3;
	}
x86_l_e09:
	/* 0xe09: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_e0d:
	/* 0xe0d: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_e0f:
	/* 0xe0f: je     e4c <generic_retkprobe_filter_arg+0xe4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e4c;
	}
x86_l_e11:
	/* 0xe11: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_e16:
	/* 0xe16: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_e1a:
	/* 0xe1a: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_e1d:
	/* 0xe1d: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_e21:
	/* 0xe21: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_e25:
	/* 0xe25: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_e29:
	/* 0xe29: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_e2d:
	/* 0xe2d: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_e30:
	/* 0xe30: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_e34:
	/* 0xe34: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_e38:
	/* 0xe38: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_e3c:
	/* 0xe3c: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_e40:
	/* 0xe40: ja     df3 <generic_retkprobe_filter_arg+0xdf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_df3;
	}
x86_l_e42:
	/* 0xe42: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e45:
	/* 0xe45: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_e48:
	/* 0xe48: je     e00 <generic_retkprobe_filter_arg+0xe00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e00;
	}
x86_l_e4a:
	/* 0xe4a: jmp    df3 <generic_retkprobe_filter_arg+0xdf3> */
	goto x86_l_df3;
x86_l_e4c:
	/* 0xe4c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e4e:
	/* 0xe4e: jns    243f <generic_retkprobe_filter_arg+0x243f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9279ULL;
	}
x86_l_e54:
	/* 0xe54: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_e58:
	/* 0xe58: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_e5d:
	/* 0xe5d: jae    e70 <generic_retkprobe_filter_arg+0xe70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e70;
	}
x86_l_e5f:
	/* 0xe5f: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_e63:
	/* 0xe63: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e66:
	/* 0xe66: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_e6a:
	/* 0xe6a: jne    dbc <generic_retkprobe_filter_arg+0xdbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_dbc;
	}
x86_l_e70:
	/* 0xe70: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e72:
	/* 0xe72: jmp    2444 <generic_retkprobe_filter_arg+0x2444> */
	return 9284ULL;
x86_l_e77:
	/* 0xe77: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_e7a:
	/* 0xe7a: jne    1ca1 <generic_retkprobe_filter_arg+0x1ca1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7329ULL;
	}
x86_l_e80:
	/* 0xe80: test   QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e84:
	/* 0xe84: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_e8a:
	/* 0xe8a: jmp    1ca1 <generic_retkprobe_filter_arg+0x1ca1> */
	return 7329ULL;
x86_l_e8f:
	/* 0xe8f: lea    edx,[rax-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_e92:
	/* 0xe92: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_e95:
	/* 0xe95: jae    17cb <generic_retkprobe_filter_arg+0x17cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6091ULL;
	}
x86_l_e9b:
	/* 0xe9b: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_e9e:
	/* 0xe9e: jne    100a <generic_retkprobe_filter_arg+0x100a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_100a;
	}
x86_l_ea4:
	/* 0xea4: mov    rsi,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ea9:
	/* 0xea9: mov    rdx,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eae:
	/* 0xeae: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_eb1:
	/* 0xeb1: je     ebc <generic_retkprobe_filter_arg+0xebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ebc;
	}
x86_l_eb3:
	/* 0xeb3: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_eb6:
	/* 0xeb6: jne    1a9e <generic_retkprobe_filter_arg+0x1a9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6814ULL;
	}
x86_l_ebc:
	/* 0xebc: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ec0:
	/* 0xec0: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ec3:
	/* 0xec3: jg     1ab0 <generic_retkprobe_filter_arg+0x1ab0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6832ULL;
	}
x86_l_ec9:
	/* 0xec9: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_ecc:
	/* 0xecc: jle    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 620ULL;
	}
x86_l_ed2:
	/* 0xed2: jmp    1ab0 <generic_retkprobe_filter_arg+0x1ab0> */
	return 6832ULL;
x86_l_ed7:
	/* 0xed7: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_edc:
	/* 0xedc: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ee1:
	/* 0xee1: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ee5:
	/* 0xee5: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_eed:
	/* 0xeed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ef2:
	/* 0xef2: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ef7:
	/* 0xef7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_efe:
	/* 0xefe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f00:
	/* 0xf00: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_f02:
	/* 0xf02: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13677ULL;
	}
x86_l_f08:
	/* 0xf08: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_f0b:
	/* 0xf0b: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_f10:
	/* 0xf10: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f13:
	/* 0xf13: je     356f <generic_retkprobe_filter_arg+0x356f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13679ULL;
	}
x86_l_f19:
	/* 0xf19: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f1e:
	/* 0xf1e: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f23:
	/* 0xf23: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_f2a:
	/* 0xf2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2c:
	/* 0xf2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f2f:
	/* 0xf2f: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13677ULL;
	}
x86_l_f35:
	/* 0xf35: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_f3b:
	/* 0xf3b: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_f40:
	/* 0xf40: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_f43:
	/* 0xf43: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_f4a:
	/* 0xf4a: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f4c:
	/* 0xf4c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f4f:
	/* 0xf4f: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_f53:
	/* 0xf53: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_f56:
	/* 0xf56: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f5b:
	/* 0xf5b: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f60:
	/* 0xf60: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_f62:
	/* 0xf62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f64:
	/* 0xf64: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f69:
	/* 0xf69: jmp    1a12 <generic_retkprobe_filter_arg+0x1a12> */
	return 6674ULL;
x86_l_f6e:
	/* 0xf6e: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_f76:
	/* 0xf76: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_f7c:
	/* 0xf7c: ja     298c <generic_retkprobe_filter_arg+0x298c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10636ULL;
	}
x86_l_f82:
	/* 0xf82: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f85:
	/* 0xf85: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_f8a:
	/* 0xf8a: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f8f:
	/* 0xf8f: ja     1c24 <generic_retkprobe_filter_arg+0x1c24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7204ULL;
	}
x86_l_f95:
	/* 0xf95: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f99:
	/* 0xf99: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_f9f:
	/* 0xf9f: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_fa2:
	/* 0xfa2: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_fa5:
	/* 0xfa5: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_fa8:
	/* 0xfa8: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_faa:
	/* 0xfaa: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_fad:
	/* 0xfad: je     fb7 <generic_retkprobe_filter_arg+0xfb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fb7;
	}
x86_l_faf:
	/* 0xfaf: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_fb1:
	/* 0xfb1: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_fb3:
	/* 0xfb3: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_fb5:
	/* 0xfb5: je     fd2 <generic_retkprobe_filter_arg+0xfd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fd2;
	}
x86_l_fb7:
	/* 0xfb7: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_fba:
	/* 0xfba: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_fbc:
	/* 0xfbc: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_fbe:
	/* 0xfbe: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_fc0:
	/* 0xfc0: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_fc3:
	/* 0xfc3: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_fc6:
	/* 0xfc6: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_fca:
	/* 0xfca: ja     1c5b <generic_retkprobe_filter_arg+0x1c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7259ULL;
	}
x86_l_fd0:
	/* 0xfd0: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_fd2:
	/* 0xfd2: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_fd5:
	/* 0xfd5: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_fdb:
	/* 0xfdb: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_fde:
	/* 0xfde: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_fe0:
	/* 0xfe0: jmp    28c7 <generic_retkprobe_filter_arg+0x28c7> */
	return 10439ULL;
x86_l_fe5:
	/* 0xfe5: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_fe8:
	/* 0xfe8: je     13ec <generic_retkprobe_filter_arg+0x13ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5100ULL;
	}
x86_l_fee:
	/* 0xfee: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_ff1:
	/* 0xff1: je     13df <generic_retkprobe_filter_arg+0x13df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5087ULL;
	}
x86_l_ff7:
	/* 0xff7: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_ffc:
	/* 0xffc: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_fff:
	/* 0xfff: je     136e <generic_retkprobe_filter_arg+0x136e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4974ULL;
	}
x86_l_1005:
	/* 0x1005: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_100a:
	/* 0x100a: mov    rsi,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_100f:
	/* 0x100f: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1014:
	/* 0x1014: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1017:
	/* 0x1017: je     1022 <generic_retkprobe_filter_arg+0x1022> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1022;
	}
x86_l_1019:
	/* 0x1019: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_101c:
	/* 0x101c: jne    1af1 <generic_retkprobe_filter_arg+0x1af1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6897ULL;
	}
x86_l_1022:
	/* 0x1022: mov    rdx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1026:
	/* 0x1026: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1029:
	/* 0x1029: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_102d:
	/* 0x102d: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1030:
	/* 0x1030: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_1033:
	/* 0x1033: jmp    1b02 <generic_retkprobe_filter_arg+0x1b02> */
	return 6914ULL;
x86_l_1038:
	/* 0x1038: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_103b:
	/* 0x103b: jne    2180 <generic_retkprobe_filter_arg+0x2180> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8576ULL;
	}
x86_l_1041:
	/* 0x1041: test   DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1045:
	/* 0x1045: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_104b:
	/* 0x104b: jmp    2180 <generic_retkprobe_filter_arg+0x2180> */
	return 8576ULL;
x86_l_1050:
	/* 0x1050: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_1055:
	/* 0x1055: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1059:
	/* 0x1059: jb     15ed <generic_retkprobe_filter_arg+0x15ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5613ULL;
	}
x86_l_105f:
	/* 0x105f: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_1069:
	/* 0x1069: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_106d:
	/* 0x106d: jae    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 187ULL;
	}
x86_l_1073:
	/* 0x1073: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_1076:
	/* 0x1076: jne    1d8e <generic_retkprobe_filter_arg+0x1d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7566ULL;
	}
x86_l_107c:
	/* 0x107c: movzx  eax,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1081:
	/* 0x1081: jmp    10b4 <generic_retkprobe_filter_arg+0x10b4> */
	goto x86_l_10b4;
x86_l_1083:
	/* 0x1083: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_1088:
	/* 0x1088: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_108c:
	/* 0x108c: jb     162f <generic_retkprobe_filter_arg+0x162f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5679ULL;
	}
x86_l_1092:
	/* 0x1092: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_109c:
	/* 0x109c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_10a0:
	/* 0x10a0: jae    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 187ULL;
	}
x86_l_10a6:
	/* 0x10a6: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_10a9:
	/* 0x10a9: jne    1d9a <generic_retkprobe_filter_arg+0x1d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7578ULL;
	}
x86_l_10af:
	/* 0x10af: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_10b4:
	/* 0x10b4: cmp    DWORD PTR [r12+0x10],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10b9:
	/* 0x10b9: ja     10c6 <generic_retkprobe_filter_arg+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_10c6;
	}
x86_l_10bb:
	/* 0x10bb: cmp    DWORD PTR [r12+0x14],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_10c0:
	/* 0x10c0: jae    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 620ULL;
	}
x86_l_10c6:
	/* 0x10c6: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10cb:
	/* 0x10cb: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_10ce:
	/* 0x10ce: jb     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 187ULL;
	}
x86_l_10d4:
	/* 0x10d4: cmp    DWORD PTR [r12+0x18],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10d9:
	/* 0x10d9: ja     10e6 <generic_retkprobe_filter_arg+0x10e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_10e6;
	}
x86_l_10db:
	/* 0x10db: cmp    DWORD PTR [r12+0x1c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_10e0:
	/* 0x10e0: jae    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 620ULL;
	}
x86_l_10e6:
	/* 0x10e6: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_10e9:
	/* 0x10e9: jb     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 187ULL;
	}
x86_l_10ef:
	/* 0x10ef: cmp    DWORD PTR [r12+0x20],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10f4:
	/* 0x10f4: ja     1101 <generic_retkprobe_filter_arg+0x1101> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1101;
	}
x86_l_10f6:
	/* 0x10f6: cmp    DWORD PTR [r12+0x24],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_10fb:
	/* 0x10fb: jae    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 620ULL;
	}
x86_l_1101:
	/* 0x1101: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_1104:
	/* 0x1104: jb     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 187ULL;
	}
x86_l_110a:
	/* 0x110a: cmp    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_110f:
	/* 0x110f: ja     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 187ULL;
	}
x86_l_1115:
	/* 0x1115: cmp    DWORD PTR [r12+0x2c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_111a:
	/* 0x111a: jae    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 620ULL;
	}
x86_l_1120:
	/* 0x1120: jmp    bb <generic_retkprobe_filter_arg+0xbb> */
	return 187ULL;
x86_l_1125:
	/* 0x1125: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1128:
	/* 0x1128: je     1133 <generic_retkprobe_filter_arg+0x1133> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1133;
	}
x86_l_112a:
	/* 0x112a: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_112d:
	/* 0x112d: jne    1c8b <generic_retkprobe_filter_arg+0x1c8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7307ULL;
	}
x86_l_1133:
	/* 0x1133: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1137:
	/* 0x1137: jg     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 620ULL;
	}
x86_l_113d:
	/* 0x113d: jmp    1ca1 <generic_retkprobe_filter_arg+0x1ca1> */
	return 7329ULL;
x86_l_1142:
	/* 0x1142: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1145:
	/* 0x1145: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_114a:
	/* 0x114a: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_114f:
	/* 0x114f: ja     16c7 <generic_retkprobe_filter_arg+0x16c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5831ULL;
	}
x86_l_1155:
	/* 0x1155: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1159:
	/* 0x1159: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_115f:
	/* 0x115f: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1162:
	/* 0x1162: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1165:
	/* 0x1165: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1168:
	/* 0x1168: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_116a:
	/* 0x116a: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_116d:
	/* 0x116d: je     1177 <generic_retkprobe_filter_arg+0x1177> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1177;
	}
x86_l_116f:
	/* 0x116f: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1171:
	/* 0x1171: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1173:
	/* 0x1173: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1175:
	/* 0x1175: je     1192 <generic_retkprobe_filter_arg+0x1192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1192;
	}
x86_l_1177:
	/* 0x1177: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_117a:
	/* 0x117a: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_117c:
	/* 0x117c: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_117e:
	/* 0x117e: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1180:
	/* 0x1180: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1183:
	/* 0x1183: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1186:
	/* 0x1186: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_118a:
	/* 0x118a: ja     16fe <generic_retkprobe_filter_arg+0x16fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5886ULL;
	}
x86_l_1190:
	/* 0x1190: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1192:
	/* 0x1192: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1195:
	/* 0x1195: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_119b:
	/* 0x119b: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_119e:
	/* 0x119e: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_11a0:
	/* 0x11a0: jmp    2296 <generic_retkprobe_filter_arg+0x2296> */
	return 8854ULL;
x86_l_11a5:
	/* 0x11a5: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_11a8:
	/* 0x11a8: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ad:
	/* 0x11ad: jg     1812 <generic_retkprobe_filter_arg+0x1812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6162ULL;
	}
x86_l_11b3:
	/* 0x11b3: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_11b6:
	/* 0x11b6: je     1985 <generic_retkprobe_filter_arg+0x1985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6533ULL;
	}
x86_l_11bc:
	/* 0x11bc: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_11c1:
	/* 0x11c1: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_11c4:
	/* 0x11c4: jne    357d <generic_retkprobe_filter_arg+0x357d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13693ULL;
	}
x86_l_11ca:
	/* 0x11ca: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11cf:
	/* 0x11cf: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11d3:
	/* 0x11d3: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_11db:
	/* 0x11db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11e0:
	/* 0x11e0: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11e5:
	/* 0x11e5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_11ec:
	/* 0x11ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ee:
	/* 0x11ee: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_11f0:
	/* 0x11f0: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13677ULL;
	}
x86_l_11f6:
	/* 0x11f6: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_11f9:
	/* 0x11f9: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_11fe:
	/* 0x11fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1201:
	/* 0x1201: je     356f <generic_retkprobe_filter_arg+0x356f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13679ULL;
	}
x86_l_1207:
	/* 0x1207: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_120c:
	/* 0x120c: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1211:
	/* 0x1211: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_1218:
	/* 0x1218: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_121a:
	/* 0x121a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_121d:
	/* 0x121d: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13677ULL;
	}
x86_l_1223:
	/* 0x1223: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1226:
	/* 0x1226: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_122b:
	/* 0x122b: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_122e:
	/* 0x122e: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_1233:
	/* 0x1233: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_1236:
	/* 0x1236: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1239:
	/* 0x1239: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_123b:
	/* 0x123b: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_123e:
	/* 0x123e: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1241:
	/* 0x1241: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1246:
	/* 0x1246: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1249:
	/* 0x1249: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_124c:
	/* 0x124c: mov    QWORD PTR [rsp+0x68],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1251:
	/* 0x1251: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_1255:
	/* 0x1255: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_125b:
	/* 0x125b: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_125e:
	/* 0x125e: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1262:
	/* 0x1262: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_1268:
	/* 0x1268: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_126b:
	/* 0x126b: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_126f:
	/* 0x126f: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1271:
	/* 0x1271: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1273:
	/* 0x1273: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1278:
	/* 0x1278: lea    r13d,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_127c:
	/* 0x127c: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1283:
	/* 0x1283: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_1288:
	/* 0x1288: mov    BYTE PTR [rdi-0x3],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_128c:
	/* 0x128c: cmp    r10,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RBX, X86_WIDTH_64);
x86_l_128f:
	/* 0x128f: je     12e9 <generic_retkprobe_filter_arg+0x12e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12e9;
	}
x86_l_1291:
	/* 0x1291: lea    r13d,[r11+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1295:
	/* 0x1295: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_129c:
	/* 0x129c: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_12a1:
	/* 0x12a1: mov    BYTE PTR [rdi-0x2],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_12a5:
	/* 0x12a5: cmp    r8,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RBX, X86_WIDTH_64);
x86_l_12a8:
	/* 0x12a8: je     12e9 <generic_retkprobe_filter_arg+0x12e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12e9;
	}
x86_l_12aa:
	/* 0x12aa: lea    r13d,[r9+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_12ae:
	/* 0x12ae: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12b5:
	/* 0x12b5: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_12ba:
	/* 0x12ba: mov    BYTE PTR [rdi-0x1],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_12be:
	/* 0x12be: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_12c1:
	/* 0x12c1: je     12e9 <generic_retkprobe_filter_arg+0x12e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12e9;
	}
x86_l_12c3:
	/* 0x12c3: cmp    rbx,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_12c7:
	/* 0x12c7: je     12e9 <generic_retkprobe_filter_arg+0x12e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12e9;
	}
x86_l_12c9:
	/* 0x12c9: lea    r13d,[rdx+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_12cd:
	/* 0x12cd: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12d4:
	/* 0x12d4: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_12d9:
	/* 0x12d9: mov    BYTE PTR [rdi],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12dc:
	/* 0x12dc: add    rbx,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_12e0:
	/* 0x12e0: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_12e4:
	/* 0x12e4: cmp    rax,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_12e7:
	/* 0x12e7: jne    1278 <generic_retkprobe_filter_arg+0x1278> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1278;
	}
x86_l_12e9:
	/* 0x12e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12ee:
	/* 0x12ee: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12f3:
	/* 0x12f3: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_12f8:
	/* 0x12f8: jmp    1a18 <generic_retkprobe_filter_arg+0x1a18> */
	return 6680ULL;
x86_l_12fd:
	/* 0x12fd: mov    esi,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1302:
	/* 0x1302: mov    eax,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1307:
	/* 0x1307: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_130a:
	/* 0x130a: ja     1f21 <generic_retkprobe_filter_arg+0x1f21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7969ULL;
	}
x86_l_1310:
	/* 0x1310: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1315:
	/* 0x1315: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1318:
	/* 0x1318: jae    1f21 <generic_retkprobe_filter_arg+0x1f21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7969ULL;
	}
x86_l_131e:
	/* 0x131e: mov    edx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1322:
	/* 0x1322: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1324:
	/* 0x1324: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_1328:
	/* 0x1328: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_132a:
	/* 0x132a: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_132d:
	/* 0x132d: jmp    1f30 <generic_retkprobe_filter_arg+0x1f30> */
	return 7984ULL;
x86_l_1332:
	/* 0x1332: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_1335:
	/* 0x1335: je     1943 <generic_retkprobe_filter_arg+0x1943> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6467ULL;
	}
x86_l_133b:
	/* 0x133b: mov    r13d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_32);
x86_l_133e:
	/* 0x133e: mov    QWORD PTR [rsp+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1343:
	/* 0x1343: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1346:
	/* 0x1346: je     18b0 <generic_retkprobe_filter_arg+0x18b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6320ULL;
	}
x86_l_134c:
	/* 0x134c: jmp    bb <generic_retkprobe_filter_arg+0xbb> */
	return 187ULL;
x86_l_1351:
	/* 0x1351: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_1354:
	/* 0x1354: je     136e <generic_retkprobe_filter_arg+0x136e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4974ULL;
	}
x86_l_1356:
	/* 0x1356: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_135b:
	/* 0x135b: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_135e:
	/* 0x135e: jne    25b <generic_retkprobe_filter_arg+0x25b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 603ULL;
	}
x86_l_1364:
	/* 0x1364: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1367:
	/* 0x1367: movzx  ebp,WORD PTR [r13+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
	return 4972ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4972ULL: goto x86_l_136c;
	case 4974ULL: goto x86_l_136e;
	case 4977ULL: goto x86_l_1371;
	case 4982ULL: goto x86_l_1376;
	case 4984ULL: goto x86_l_1378;
	case 4987ULL: goto x86_l_137b;
	case 4990ULL: goto x86_l_137e;
	case 4992ULL: goto x86_l_1380;
	case 4995ULL: goto x86_l_1383;
	case 5001ULL: goto x86_l_1389;
	case 5004ULL: goto x86_l_138c;
	case 5007ULL: goto x86_l_138f;
	case 5013ULL: goto x86_l_1395;
	case 5016ULL: goto x86_l_1398;
	case 5019ULL: goto x86_l_139b;
	case 5025ULL: goto x86_l_13a1;
	case 5028ULL: goto x86_l_13a4;
	case 5034ULL: goto x86_l_13aa;
	case 5039ULL: goto x86_l_13af;
	case 5042ULL: goto x86_l_13b2;
	case 5048ULL: goto x86_l_13b8;
	case 5053ULL: goto x86_l_13bd;
	case 5056ULL: goto x86_l_13c0;
	case 5062ULL: goto x86_l_13c6;
	case 5065ULL: goto x86_l_13c9;
	case 5071ULL: goto x86_l_13cf;
	case 5074ULL: goto x86_l_13d2;
	case 5080ULL: goto x86_l_13d8;
	case 5082ULL: goto x86_l_13da;
	case 5087ULL: goto x86_l_13df;
	case 5091ULL: goto x86_l_13e3;
	case 5094ULL: goto x86_l_13e6;
	case 5098ULL: goto x86_l_13ea;
	case 5100ULL: goto x86_l_13ec;
	case 5104ULL: goto x86_l_13f0;
	case 5107ULL: goto x86_l_13f3;
	case 5111ULL: goto x86_l_13f7;
	case 5114ULL: goto x86_l_13fa;
	case 5118ULL: goto x86_l_13fe;
	case 5120ULL: goto x86_l_1400;
	case 5122ULL: goto x86_l_1402;
	case 5125ULL: goto x86_l_1405;
	case 5127ULL: goto x86_l_1407;
	case 5130ULL: goto x86_l_140a;
	case 5136ULL: goto x86_l_1410;
	case 5141ULL: goto x86_l_1415;
	case 5144ULL: goto x86_l_1418;
	case 5150ULL: goto x86_l_141e;
	case 5155ULL: goto x86_l_1423;
	case 5158ULL: goto x86_l_1426;
	case 5164ULL: goto x86_l_142c;
	case 5169ULL: goto x86_l_1431;
	case 5172ULL: goto x86_l_1434;
	case 5178ULL: goto x86_l_143a;
	case 5182ULL: goto x86_l_143e;
	case 5185ULL: goto x86_l_1441;
	case 5191ULL: goto x86_l_1447;
	case 5194ULL: goto x86_l_144a;
	case 5200ULL: goto x86_l_1450;
	case 5203ULL: goto x86_l_1453;
	case 5208ULL: goto x86_l_1458;
	case 5212ULL: goto x86_l_145c;
	case 5217ULL: goto x86_l_1461;
	case 5222ULL: goto x86_l_1466;
	case 5229ULL: goto x86_l_146d;
	case 5231ULL: goto x86_l_146f;
	case 5234ULL: goto x86_l_1472;
	case 5240ULL: goto x86_l_1478;
	case 5243ULL: goto x86_l_147b;
	case 5251ULL: goto x86_l_1483;
	case 5255ULL: goto x86_l_1487;
	case 5260ULL: goto x86_l_148c;
	case 5263ULL: goto x86_l_148f;
	case 5269ULL: goto x86_l_1495;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5283ULL: goto x86_l_14a3;
	case 5287ULL: goto x86_l_14a7;
	case 5293ULL: goto x86_l_14ad;
	case 5298ULL: goto x86_l_14b2;
	case 5303ULL: goto x86_l_14b7;
	case 5305ULL: goto x86_l_14b9;
	case 5308ULL: goto x86_l_14bc;
	case 5313ULL: goto x86_l_14c1;
	case 5317ULL: goto x86_l_14c5;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5334ULL: goto x86_l_14d6;
	case 5336ULL: goto x86_l_14d8;
	case 5339ULL: goto x86_l_14db;
	case 5345ULL: goto x86_l_14e1;
	case 5347ULL: goto x86_l_14e3;
	case 5352ULL: goto x86_l_14e8;
	case 5357ULL: goto x86_l_14ed;
	case 5359ULL: goto x86_l_14ef;
	case 5364ULL: goto x86_l_14f4;
	case 5366ULL: goto x86_l_14f6;
	case 5368ULL: goto x86_l_14f8;
	case 5371ULL: goto x86_l_14fb;
	case 5374ULL: goto x86_l_14fe;
	case 5377ULL: goto x86_l_1501;
	case 5379ULL: goto x86_l_1503;
	case 5381ULL: goto x86_l_1505;
	case 5385ULL: goto x86_l_1509;
	case 5388ULL: goto x86_l_150c;
	case 5390ULL: goto x86_l_150e;
	case 5394ULL: goto x86_l_1512;
	case 5397ULL: goto x86_l_1515;
	case 5399ULL: goto x86_l_1517;
	case 5403ULL: goto x86_l_151b;
	case 5405ULL: goto x86_l_151d;
	case 5409ULL: goto x86_l_1521;
	case 5413ULL: goto x86_l_1525;
	case 5416ULL: goto x86_l_1528;
	case 5418ULL: goto x86_l_152a;
	case 5420ULL: goto x86_l_152c;
	case 5422ULL: goto x86_l_152e;
	case 5428ULL: goto x86_l_1534;
	case 5432ULL: goto x86_l_1538;
	case 5437ULL: goto x86_l_153d;
	case 5443ULL: goto x86_l_1543;
	case 5447ULL: goto x86_l_1547;
	case 5450ULL: goto x86_l_154a;
	case 5454ULL: goto x86_l_154e;
	case 5460ULL: goto x86_l_1554;
	case 5465ULL: goto x86_l_1559;
	case 5468ULL: goto x86_l_155c;
	case 5471ULL: goto x86_l_155f;
	case 5477ULL: goto x86_l_1565;
	case 5483ULL: goto x86_l_156b;
	case 5487ULL: goto x86_l_156f;
	case 5492ULL: goto x86_l_1574;
	case 5499ULL: goto x86_l_157b;
	case 5504ULL: goto x86_l_1580;
	case 5506ULL: goto x86_l_1582;
	case 5509ULL: goto x86_l_1585;
	case 5515ULL: goto x86_l_158b;
	case 5518ULL: goto x86_l_158e;
	case 5521ULL: goto x86_l_1591;
	case 5526ULL: goto x86_l_1596;
	case 5531ULL: goto x86_l_159b;
	case 5536ULL: goto x86_l_15a0;
	case 5541ULL: goto x86_l_15a5;
	case 5544ULL: goto x86_l_15a8;
	case 5550ULL: goto x86_l_15ae;
	case 5553ULL: goto x86_l_15b1;
	case 5559ULL: goto x86_l_15b7;
	case 5564ULL: goto x86_l_15bc;
	case 5566ULL: goto x86_l_15be;
	case 5572ULL: goto x86_l_15c4;
	case 5577ULL: goto x86_l_15c9;
	case 5580ULL: goto x86_l_15cc;
	case 5586ULL: goto x86_l_15d2;
	case 5589ULL: goto x86_l_15d5;
	case 5595ULL: goto x86_l_15db;
	case 5600ULL: goto x86_l_15e0;
	case 5602ULL: goto x86_l_15e2;
	case 5608ULL: goto x86_l_15e8;
	case 5613ULL: goto x86_l_15ed;
	case 5619ULL: goto x86_l_15f3;
	case 5623ULL: goto x86_l_15f7;
	case 5628ULL: goto x86_l_15fc;
	case 5633ULL: goto x86_l_1601;
	case 5640ULL: goto x86_l_1608;
	case 5642ULL: goto x86_l_160a;
	case 5645ULL: goto x86_l_160d;
	case 5651ULL: goto x86_l_1613;
	case 5654ULL: goto x86_l_1616;
	case 5659ULL: goto x86_l_161b;
	case 5664ULL: goto x86_l_1620;
	case 5669ULL: goto x86_l_1625;
	case 5674ULL: goto x86_l_162a;
	case 5679ULL: goto x86_l_162f;
	case 5685ULL: goto x86_l_1635;
	case 5689ULL: goto x86_l_1639;
	case 5694ULL: goto x86_l_163e;
	case 5699ULL: goto x86_l_1643;
	case 5706ULL: goto x86_l_164a;
	case 5708ULL: goto x86_l_164c;
	case 5711ULL: goto x86_l_164f;
	case 5717ULL: goto x86_l_1655;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5730ULL: goto x86_l_1662;
	case 5735ULL: goto x86_l_1667;
	case 5740ULL: goto x86_l_166c;
	case 5745ULL: goto x86_l_1671;
	case 5752ULL: goto x86_l_1678;
	case 5758ULL: goto x86_l_167e;
	case 5761ULL: goto x86_l_1681;
	case 5767ULL: goto x86_l_1687;
	case 5769ULL: goto x86_l_1689;
	case 5775ULL: goto x86_l_168f;
	case 5778ULL: goto x86_l_1692;
	case 5784ULL: goto x86_l_1698;
	case 5790ULL: goto x86_l_169e;
	case 5795ULL: goto x86_l_16a3;
	case 5798ULL: goto x86_l_16a6;
	case 5800ULL: goto x86_l_16a8;
	case 5805ULL: goto x86_l_16ad;
	case 5808ULL: goto x86_l_16b0;
	case 5813ULL: goto x86_l_16b5;
	case 5816ULL: goto x86_l_16b8;
	case 5818ULL: goto x86_l_16ba;
	case 5823ULL: goto x86_l_16bf;
	case 5826ULL: goto x86_l_16c2;
	case 5831ULL: goto x86_l_16c7;
	case 5836ULL: goto x86_l_16cc;
	case 5841ULL: goto x86_l_16d1;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5853ULL: goto x86_l_16dd;
	case 5855ULL: goto x86_l_16df;
	case 5860ULL: goto x86_l_16e4;
	case 5865ULL: goto x86_l_16e9;
	case 5867ULL: goto x86_l_16eb;
	case 5869ULL: goto x86_l_16ed;
	case 5874ULL: goto x86_l_16f2;
	case 5877ULL: goto x86_l_16f5;
	case 5880ULL: goto x86_l_16f8;
	case 5886ULL: goto x86_l_16fe;
	case 5892ULL: goto x86_l_1704;
	case 5898ULL: goto x86_l_170a;
	case 5901ULL: goto x86_l_170d;
	case 5907ULL: goto x86_l_1713;
	case 5909ULL: goto x86_l_1715;
	case 5915ULL: goto x86_l_171b;
	case 5918ULL: goto x86_l_171e;
	case 5924ULL: goto x86_l_1724;
	case 5929ULL: goto x86_l_1729;
	case 5934ULL: goto x86_l_172e;
	case 5937ULL: goto x86_l_1731;
	case 5940ULL: goto x86_l_1734;
	case 5945ULL: goto x86_l_1739;
	case 5949ULL: goto x86_l_173d;
	case 5954ULL: goto x86_l_1742;
	case 5961ULL: goto x86_l_1749;
	case 5966ULL: goto x86_l_174e;
	case 5968ULL: goto x86_l_1750;
	case 5971ULL: goto x86_l_1753;
	case 5977ULL: goto x86_l_1759;
	case 5980ULL: goto x86_l_175c;
	case 5988ULL: goto x86_l_1764;
	case 5992ULL: goto x86_l_1768;
	case 5997ULL: goto x86_l_176d;
	case 6001ULL: goto x86_l_1771;
	case 6005ULL: goto x86_l_1775;
	case 6012ULL: goto x86_l_177c;
	case 6017ULL: goto x86_l_1781;
	case 6022ULL: goto x86_l_1786;
	case 6024ULL: goto x86_l_1788;
	case 6029ULL: goto x86_l_178d;
	case 6032ULL: goto x86_l_1790;
	case 6035ULL: goto x86_l_1793;
	case 6037ULL: goto x86_l_1795;
	case 6040ULL: goto x86_l_1798;
	case 6043ULL: goto x86_l_179b;
	case 6047ULL: goto x86_l_179f;
	case 6052ULL: goto x86_l_17a4;
	case 6057ULL: goto x86_l_17a9;
	case 6059ULL: goto x86_l_17ab;
	case 6062ULL: goto x86_l_17ae;
	case 6065ULL: goto x86_l_17b1;
	case 6068ULL: goto x86_l_17b4;
	case 6073ULL: goto x86_l_17b9;
	case 6075ULL: goto x86_l_17bb;
	case 6078ULL: goto x86_l_17be;
	case 6083ULL: goto x86_l_17c3;
	case 6086ULL: goto x86_l_17c6;
	case 6091ULL: goto x86_l_17cb;
	case 6094ULL: goto x86_l_17ce;
	case 6100ULL: goto x86_l_17d4;
	case 6105ULL: goto x86_l_17d9;
	case 6108ULL: goto x86_l_17dc;
	case 6110ULL: goto x86_l_17de;
	case 6119ULL: goto x86_l_17e7;
	case 6125ULL: goto x86_l_17ed;
	case 6129ULL: goto x86_l_17f1;
	case 6137ULL: goto x86_l_17f9;
	case 6142ULL: goto x86_l_17fe;
	case 6144ULL: goto x86_l_1800;
	case 6154ULL: goto x86_l_180a;
	case 6157ULL: goto x86_l_180d;
	case 6162ULL: goto x86_l_1812;
	case 6165ULL: goto x86_l_1815;
	case 6171ULL: goto x86_l_181b;
	case 6176ULL: goto x86_l_1820;
	case 6179ULL: goto x86_l_1823;
	case 6185ULL: goto x86_l_1829;
	case 6191ULL: goto x86_l_182f;
	case 6195ULL: goto x86_l_1833;
	case 6199ULL: goto x86_l_1837;
	case 6204ULL: goto x86_l_183c;
	case 6209ULL: goto x86_l_1841;
	case 6216ULL: goto x86_l_1848;
	case 6218ULL: goto x86_l_184a;
	case 6221ULL: goto x86_l_184d;
	case 6227ULL: goto x86_l_1853;
	case 6232ULL: goto x86_l_1858;
	case 6235ULL: goto x86_l_185b;
	case 6238ULL: goto x86_l_185e;
	case 6243ULL: goto x86_l_1863;
	case 6245ULL: goto x86_l_1865;
	case 6251ULL: goto x86_l_186b;
	case 6255ULL: goto x86_l_186f;
	case 6259ULL: goto x86_l_1873;
	case 6264ULL: goto x86_l_1878;
	case 6268ULL: goto x86_l_187c;
	case 6273ULL: goto x86_l_1881;
	case 6278ULL: goto x86_l_1886;
	case 6284ULL: goto x86_l_188c;
	case 6289ULL: goto x86_l_1891;
	case 6296ULL: goto x86_l_1898;
	case 6298ULL: goto x86_l_189a;
	case 6303ULL: goto x86_l_189f;
	case 6306ULL: goto x86_l_18a2;
	case 6311ULL: goto x86_l_18a7;
	case 6314ULL: goto x86_l_18aa;
	case 6320ULL: goto x86_l_18b0;
	case 6325ULL: goto x86_l_18b5;
	case 6329ULL: goto x86_l_18b9;
	case 6337ULL: goto x86_l_18c1;
	case 6342ULL: goto x86_l_18c6;
	case 6347ULL: goto x86_l_18cb;
	case 6354ULL: goto x86_l_18d2;
	case 6356ULL: goto x86_l_18d4;
	case 6359ULL: goto x86_l_18d7;
	case 6365ULL: goto x86_l_18dd;
	case 6370ULL: goto x86_l_18e2;
	case 6373ULL: goto x86_l_18e5;
	case 6379ULL: goto x86_l_18eb;
	case 6382ULL: goto x86_l_18ee;
	case 6387ULL: goto x86_l_18f3;
	case 6392ULL: goto x86_l_18f8;
	case 6399ULL: goto x86_l_18ff;
	case 6401ULL: goto x86_l_1901;
	case 6404ULL: goto x86_l_1904;
	case 6410ULL: goto x86_l_190a;
	case 6412ULL: goto x86_l_190c;
	case 6415ULL: goto x86_l_190f;
	case 6417ULL: goto x86_l_1911;
	case 6420ULL: goto x86_l_1914;
	case 6424ULL: goto x86_l_1918;
	case 6427ULL: goto x86_l_191b;
	case 6432ULL: goto x86_l_1920;
	case 6437ULL: goto x86_l_1925;
	case 6439ULL: goto x86_l_1927;
	case 6441ULL: goto x86_l_1929;
	case 6446ULL: goto x86_l_192e;
	case 6449ULL: goto x86_l_1931;
	case 6452ULL: goto x86_l_1934;
	case 6454ULL: goto x86_l_1936;
	case 6456ULL: goto x86_l_1938;
	case 6459ULL: goto x86_l_193b;
	case 6462ULL: goto x86_l_193e;
	case 6467ULL: goto x86_l_1943;
	case 6472ULL: goto x86_l_1948;
	case 6478ULL: goto x86_l_194e;
	case 6482ULL: goto x86_l_1952;
	case 6487ULL: goto x86_l_1957;
	case 6492ULL: goto x86_l_195c;
	case 6499ULL: goto x86_l_1963;
	case 6501ULL: goto x86_l_1965;
	case 6504ULL: goto x86_l_1968;
	case 6510ULL: goto x86_l_196e;
	case 6513ULL: goto x86_l_1971;
	case 6518ULL: goto x86_l_1976;
	case 6523ULL: goto x86_l_197b;
	case 6528ULL: goto x86_l_1980;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6542ULL: goto x86_l_198e;
	case 6550ULL: goto x86_l_1996;
	case 6555ULL: goto x86_l_199b;
	case 6560ULL: goto x86_l_19a0;
	case 6567ULL: goto x86_l_19a7;
	case 6569ULL: goto x86_l_19a9;
	case 6571ULL: goto x86_l_19ab;
	case 6577ULL: goto x86_l_19b1;
	case 6580ULL: goto x86_l_19b4;
	case 6585ULL: goto x86_l_19b9;
	case 6588ULL: goto x86_l_19bc;
	case 6594ULL: goto x86_l_19c2;
	case 6599ULL: goto x86_l_19c7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_136c:
	/* 0x136c: jmp    1376 <generic_retkprobe_filter_arg+0x1376> */
	goto x86_l_1376;
x86_l_136e:
	/* 0x136e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1371:
	/* 0x1371: movzx  ebp,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1376:
	/* 0x1376: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1378:
	/* 0x1378: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_137b:
	/* 0x137b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_137e:
	/* 0x137e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1380:
	/* 0x1380: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1383:
	/* 0x1383: jg     1407 <generic_retkprobe_filter_arg+0x1407> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1407;
	}
x86_l_1389:
	/* 0x1389: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_138c:
	/* 0x138c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_138f:
	/* 0x138f: jb     143a <generic_retkprobe_filter_arg+0x143a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_143a;
	}
x86_l_1395:
	/* 0x1395: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_1398:
	/* 0x1398: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_139b:
	/* 0x139b: jb     1565 <generic_retkprobe_filter_arg+0x1565> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1565;
	}
x86_l_13a1:
	/* 0x13a1: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_13a4:
	/* 0x13a4: je     1b43 <generic_retkprobe_filter_arg+0x1b43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6979ULL;
	}
x86_l_13aa:
	/* 0x13aa: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_13af:
	/* 0x13af: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_13b2:
	/* 0x13b2: je     1b3e <generic_retkprobe_filter_arg+0x1b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6974ULL;
	}
x86_l_13b8:
	/* 0x13b8: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_13bd:
	/* 0x13bd: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_13c0:
	/* 0x13c0: jne    25b <generic_retkprobe_filter_arg+0x25b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 603ULL;
	}
x86_l_13c6:
	/* 0x13c6: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_13c9:
	/* 0x13c9: jne    208f <generic_retkprobe_filter_arg+0x208f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8335ULL;
	}
x86_l_13cf:
	/* 0x13cf: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_13d2:
	/* 0x13d2: jne    209b <generic_retkprobe_filter_arg+0x209b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8347ULL;
	}
x86_l_13d8:
	/* 0x13d8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13da:
	/* 0x13da: jmp    20ad <generic_retkprobe_filter_arg+0x20ad> */
	return 8365ULL;
x86_l_13df:
	/* 0x13df: mov    rsi,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13e3:
	/* 0x13e3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_13e6:
	/* 0x13e6: mov    r8,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13ea:
	/* 0x13ea: jmp    13f7 <generic_retkprobe_filter_arg+0x13f7> */
	goto x86_l_13f7;
x86_l_13ec:
	/* 0x13ec: mov    rsi,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13f0:
	/* 0x13f0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_13f3:
	/* 0x13f3: mov    r8,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13f7:
	/* 0x13f7: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_13fa:
	/* 0x13fa: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_13fe:
	/* 0x13fe: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1400:
	/* 0x1400: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1402:
	/* 0x1402: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1405:
	/* 0x1405: jle    1389 <generic_retkprobe_filter_arg+0x1389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1389;
	}
x86_l_1407:
	/* 0x1407: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_140a:
	/* 0x140a: ja     1559 <generic_retkprobe_filter_arg+0x1559> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1559;
	}
x86_l_1410:
	/* 0x1410: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_1415:
	/* 0x1415: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1418:
	/* 0x1418: jb     16a3 <generic_retkprobe_filter_arg+0x16a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16a3;
	}
x86_l_141e:
	/* 0x141e: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_1423:
	/* 0x1423: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1426:
	/* 0x1426: jb     16b5 <generic_retkprobe_filter_arg+0x16b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16b5;
	}
x86_l_142c:
	/* 0x142c: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_1431:
	/* 0x1431: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1434:
	/* 0x1434: jae    1559 <generic_retkprobe_filter_arg+0x1559> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1559;
	}
x86_l_143a:
	/* 0x143a: movzx  eax,WORD PTR [rdx+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_143e:
	/* 0x143e: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1441:
	/* 0x1441: je     172e <generic_retkprobe_filter_arg+0x172e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_172e;
	}
x86_l_1447:
	/* 0x1447: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_144a:
	/* 0x144a: jne    17b9 <generic_retkprobe_filter_arg+0x17b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_17b9;
	}
x86_l_1450:
	/* 0x1450: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_1453:
	/* 0x1453: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1458:
	/* 0x1458: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_145c:
	/* 0x145c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1461:
	/* 0x1461: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1466:
	/* 0x1466: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_146d:
	/* 0x146d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146f:
	/* 0x146f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1472:
	/* 0x1472: je     1c00 <generic_retkprobe_filter_arg+0x1c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7168ULL;
	}
x86_l_1478:
	/* 0x1478: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_147b:
	/* 0x147b: mov    DWORD PTR [rsp+0x70],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337184ULL);
x86_l_1483:
	/* 0x1483: mov    DWORD PTR [rsp+0x74],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_1487:
	/* 0x1487: jmp    177c <generic_retkprobe_filter_arg+0x177c> */
	goto x86_l_177c;
x86_l_148c:
	/* 0x148c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_148f:
	/* 0x148f: ja     216a <generic_retkprobe_filter_arg+0x216a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8554ULL;
	}
x86_l_1495:
	/* 0x1495: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_149a:
	/* 0x149a: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_149d:
	/* 0x149d: jae    216a <generic_retkprobe_filter_arg+0x216a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8554ULL;
	}
x86_l_14a3:
	/* 0x14a3: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a7:
	/* 0x14a7: jg     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 620ULL;
	}
x86_l_14ad:
	/* 0x14ad: jmp    2180 <generic_retkprobe_filter_arg+0x2180> */
	return 8576ULL;
x86_l_14b2:
	/* 0x14b2: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14b7:
	/* 0x14b7: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14b9:
	/* 0x14b9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14bc:
	/* 0x14bc: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_14c1:
	/* 0x14c1: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14c5:
	/* 0x14c5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14ca:
	/* 0x14ca: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14cf:
	/* 0x14cf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_14d6:
	/* 0x14d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d8:
	/* 0x14d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14db:
	/* 0x14db: je     2032 <generic_retkprobe_filter_arg+0x2032> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8242ULL;
	}
x86_l_14e1:
	/* 0x14e1: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_14e3:
	/* 0x14e3: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14e8:
	/* 0x14e8: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14ed:
	/* 0x14ed: je     1534 <generic_retkprobe_filter_arg+0x1534> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1534;
	}
x86_l_14ef:
	/* 0x14ef: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14f4:
	/* 0x14f4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14f6:
	/* 0x14f6: jmp    1503 <generic_retkprobe_filter_arg+0x1503> */
	goto x86_l_1503;
x86_l_14f8:
	/* 0x14f8: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_14fb:
	/* 0x14fb: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_14fe:
	/* 0x14fe: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1501:
	/* 0x1501: je     1534 <generic_retkprobe_filter_arg+0x1534> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1534;
	}
x86_l_1503:
	/* 0x1503: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1505:
	/* 0x1505: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1509:
	/* 0x1509: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_150c:
	/* 0x150c: jae    14f8 <generic_retkprobe_filter_arg+0x14f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_14f8;
	}
x86_l_150e:
	/* 0x150e: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1512:
	/* 0x1512: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_1515:
	/* 0x1515: je     152c <generic_retkprobe_filter_arg+0x152c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_152c;
	}
x86_l_1517:
	/* 0x1517: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_151b:
	/* 0x151b: ja     14f8 <generic_retkprobe_filter_arg+0x14f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_14f8;
	}
x86_l_151d:
	/* 0x151d: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1521:
	/* 0x1521: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1525:
	/* 0x1525: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1528:
	/* 0x1528: je     1505 <generic_retkprobe_filter_arg+0x1505> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1505;
	}
x86_l_152a:
	/* 0x152a: jmp    14f8 <generic_retkprobe_filter_arg+0x14f8> */
	goto x86_l_14f8;
x86_l_152c:
	/* 0x152c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_152e:
	/* 0x152e: jns    2275 <generic_retkprobe_filter_arg+0x2275> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 8821ULL;
	}
x86_l_1534:
	/* 0x1534: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1538:
	/* 0x1538: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_153d:
	/* 0x153d: jae    2027 <generic_retkprobe_filter_arg+0x2027> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8231ULL;
	}
x86_l_1543:
	/* 0x1543: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1547:
	/* 0x1547: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_154a:
	/* 0x154a: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_154e:
	/* 0x154e: jne    14bc <generic_retkprobe_filter_arg+0x14bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14bc;
	}
x86_l_1554:
	/* 0x1554: jmp    2027 <generic_retkprobe_filter_arg+0x2027> */
	return 8231ULL;
x86_l_1559:
	/* 0x1559: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_155c:
	/* 0x155c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_155f:
	/* 0x155f: jae    25b <generic_retkprobe_filter_arg+0x25b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 603ULL;
	}
x86_l_1565:
	/* 0x1565: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_156b:
	/* 0x156b: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_156f:
	/* 0x156f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1574:
	/* 0x1574: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_157b:
	/* 0x157b: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1580:
	/* 0x1580: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1582:
	/* 0x1582: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1585:
	/* 0x1585: je     20e8 <generic_retkprobe_filter_arg+0x20e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8424ULL;
	}
x86_l_158b:
	/* 0x158b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_158e:
	/* 0x158e: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1591:
	/* 0x1591: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1596:
	/* 0x1596: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_159b:
	/* 0x159b: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15a0:
	/* 0x15a0: jmp    1b7e <generic_retkprobe_filter_arg+0x1b7e> */
	return 7038ULL;
x86_l_15a5:
	/* 0x15a5: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15a8:
	/* 0x15a8: je     1e39 <generic_retkprobe_filter_arg+0x1e39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7737ULL;
	}
x86_l_15ae:
	/* 0x15ae: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15b1:
	/* 0x15b1: jne    1e46 <generic_retkprobe_filter_arg+0x1e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7750ULL;
	}
x86_l_15b7:
	/* 0x15b7: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_15bc:
	/* 0x15bc: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_15be:
	/* 0x15be: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_15c4:
	/* 0x15c4: jmp    1e46 <generic_retkprobe_filter_arg+0x1e46> */
	return 7750ULL;
x86_l_15c9:
	/* 0x15c9: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15cc:
	/* 0x15cc: je     1e80 <generic_retkprobe_filter_arg+0x1e80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7808ULL;
	}
x86_l_15d2:
	/* 0x15d2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15d5:
	/* 0x15d5: jne    1e8d <generic_retkprobe_filter_arg+0x1e8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7821ULL;
	}
x86_l_15db:
	/* 0x15db: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15e0:
	/* 0x15e0: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_15e2:
	/* 0x15e2: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_15e8:
	/* 0x15e8: jmp    1e8d <generic_retkprobe_filter_arg+0x1e8d> */
	return 7821ULL;
x86_l_15ed:
	/* 0x15ed: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_15f3:
	/* 0x15f3: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_15f7:
	/* 0x15f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15fc:
	/* 0x15fc: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1601:
	/* 0x1601: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1608:
	/* 0x1608: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_160a:
	/* 0x160a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_160d:
	/* 0x160d: je     20e8 <generic_retkprobe_filter_arg+0x20e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8424ULL;
	}
x86_l_1613:
	/* 0x1613: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1616:
	/* 0x1616: movzx  eax,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_161b:
	/* 0x161b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1620:
	/* 0x1620: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1625:
	/* 0x1625: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_162a:
	/* 0x162a: jmp    1b7e <generic_retkprobe_filter_arg+0x1b7e> */
	return 7038ULL;
x86_l_162f:
	/* 0x162f: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1635:
	/* 0x1635: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1639:
	/* 0x1639: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_163e:
	/* 0x163e: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1643:
	/* 0x1643: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_164a:
	/* 0x164a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_164c:
	/* 0x164c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_164f:
	/* 0x164f: je     20e8 <generic_retkprobe_filter_arg+0x20e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8424ULL;
	}
x86_l_1655:
	/* 0x1655: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1658:
	/* 0x1658: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_165d:
	/* 0x165d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1662:
	/* 0x1662: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1667:
	/* 0x1667: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_166c:
	/* 0x166c: jmp    1b7e <generic_retkprobe_filter_arg+0x1b7e> */
	return 7038ULL;
x86_l_1671:
	/* 0x1671: lea    eax,[r10-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_1678:
	/* 0x1678: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_167e:
	/* 0x167e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1681:
	/* 0x1681: jg     1e1c <generic_retkprobe_filter_arg+0x1e1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7708ULL;
	}
x86_l_1687:
	/* 0x1687: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1689:
	/* 0x1689: je     24b2 <generic_retkprobe_filter_arg+0x24b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9394ULL;
	}
x86_l_168f:
	/* 0x168f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1692:
	/* 0x1692: jne    24aa <generic_retkprobe_filter_arg+0x24aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9386ULL;
	}
x86_l_1698:
	/* 0x1698: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_169e:
	/* 0x169e: jmp    24c0 <generic_retkprobe_filter_arg+0x24c0> */
	return 9408ULL;
x86_l_16a3:
	/* 0x16a3: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_16a6:
	/* 0x16a6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16a8:
	/* 0x16a8: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_16ad:
	/* 0x16ad: setb   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_B);
x86_l_16b0:
	/* 0x16b0: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_16b5:
	/* 0x16b5: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_16b8:
	/* 0x16b8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16ba:
	/* 0x16ba: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_16bf:
	/* 0x16bf: setae  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_AE);
x86_l_16c2:
	/* 0x16c2: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_16c7:
	/* 0x16c7: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_16cc:
	/* 0x16cc: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_16d1:
	/* 0x16d1: jb     16fe <generic_retkprobe_filter_arg+0x16fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16fe;
	}
x86_l_16d3:
	/* 0x16d3: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_16d8:
	/* 0x16d8: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_16dd:
	/* 0x16dd: jb     16fe <generic_retkprobe_filter_arg+0x16fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16fe;
	}
x86_l_16df:
	/* 0x16df: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_16e4:
	/* 0x16e4: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_16e9:
	/* 0x16e9: jb     16fe <generic_retkprobe_filter_arg+0x16fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16fe;
	}
x86_l_16eb:
	/* 0x16eb: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16ed:
	/* 0x16ed: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_16f2:
	/* 0x16f2: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_16f5:
	/* 0x16f5: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_16f8:
	/* 0x16f8: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_16fe:
	/* 0x16fe: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_1704:
	/* 0x1704: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_170a:
	/* 0x170a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_170d:
	/* 0x170d: jg     1d55 <generic_retkprobe_filter_arg+0x1d55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7509ULL;
	}
x86_l_1713:
	/* 0x1713: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1715:
	/* 0x1715: je     228a <generic_retkprobe_filter_arg+0x228a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8842ULL;
	}
x86_l_171b:
	/* 0x171b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_171e:
	/* 0x171e: jne    2283 <generic_retkprobe_filter_arg+0x2283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8835ULL;
	}
x86_l_1724:
	/* 0x1724: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1729:
	/* 0x1729: jmp    2296 <generic_retkprobe_filter_arg+0x2296> */
	return 8854ULL;
x86_l_172e:
	/* 0x172e: mov    rbp,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_1731:
	/* 0x1731: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_1734:
	/* 0x1734: mov    eax,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1739:
	/* 0x1739: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_173d:
	/* 0x173d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1742:
	/* 0x1742: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_1749:
	/* 0x1749: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_174e:
	/* 0x174e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1750:
	/* 0x1750: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1753:
	/* 0x1753: je     1c00 <generic_retkprobe_filter_arg+0x1c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7168ULL;
	}
x86_l_1759:
	/* 0x1759: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_175c:
	/* 0x175c: mov    DWORD PTR [rsp+0x70],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337280ULL);
x86_l_1764:
	/* 0x1764: mov    DWORD PTR [rsp+0x74],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_1768:
	/* 0x1768: mov    DWORD PTR [rsp+0x78],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_176d:
	/* 0x176d: mov    DWORD PTR [rsp+0x7c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1771:
	/* 0x1771: shr    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1775:
	/* 0x1775: mov    DWORD PTR [rsp+0x80],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_177c:
	/* 0x177c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1781:
	/* 0x1781: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1786:
	/* 0x1786: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1788:
	/* 0x1788: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_178d:
	/* 0x178d: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_1790:
	/* 0x1790: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1793:
	/* 0x1793: jb     17c3 <generic_retkprobe_filter_arg+0x17c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_17c3;
	}
x86_l_1795:
	/* 0x1795: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_1798:
	/* 0x1798: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_179b:
	/* 0x179b: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_179f:
	/* 0x179f: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17a4:
	/* 0x17a4: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17a9:
	/* 0x17a9: ja     17b9 <generic_retkprobe_filter_arg+0x17b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_17b9;
	}
x86_l_17ab:
	/* 0x17ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17ae:
	/* 0x17ae: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_17b1:
	/* 0x17b1: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_17b4:
	/* 0x17b4: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_17b9:
	/* 0x17b9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17bb:
	/* 0x17bb: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_17be:
	/* 0x17be: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_17c3:
	/* 0x17c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17c6:
	/* 0x17c6: jmp    1c0b <generic_retkprobe_filter_arg+0x1c0b> */
	return 7179ULL;
x86_l_17cb:
	/* 0x17cb: cmp    eax,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_17ce:
	/* 0x17ce: jne    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 187ULL;
	}
x86_l_17d4:
	/* 0x17d4: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d9:
	/* 0x17d9: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_17dc:
	/* 0x17dc: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_17de:
	/* 0x17de: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_17e7:
	/* 0x17e7: jne    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 187ULL;
	}
x86_l_17ed:
	/* 0x17ed: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17f1:
	/* 0x17f1: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_17f9:
	/* 0x17f9: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_17fe:
	/* 0x17fe: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1800:
	/* 0x1800: andn   rax,rcx,QWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ANDN_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 144ULL);
x86_l_180a:
	/* 0x180a: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_180d:
	/* 0x180d: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_1812:
	/* 0x1812: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1815:
	/* 0x1815: je     1f92 <generic_retkprobe_filter_arg+0x1f92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8082ULL;
	}
x86_l_181b:
	/* 0x181b: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1820:
	/* 0x1820: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_1823:
	/* 0x1823: jne    357d <generic_retkprobe_filter_arg+0x357d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13693ULL;
	}
x86_l_1829:
	/* 0x1829: mov    r13d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16ULL);
x86_l_182f:
	/* 0x182f: mov    eax,DWORD PTR [r12+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1833:
	/* 0x1833: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1837:
	/* 0x1837: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_183c:
	/* 0x183c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1841:
	/* 0x1841: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1848:
	/* 0x1848: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184a:
	/* 0x184a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_184d:
	/* 0x184d: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13677ULL;
	}
x86_l_1853:
	/* 0x1853: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1858:
	/* 0x1858: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_185b:
	/* 0x185b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_185e:
	/* 0x185e: call   0 <generic_retkprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 6243ULL);
	__x86_sim_call_depth++;
	return 13805ULL;
x86_l_1863:
	/* 0x1863: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1865:
	/* 0x1865: jns    2bf5 <generic_retkprobe_filter_arg+0x2bf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11253ULL;
	}
x86_l_186b:
	/* 0x186b: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_186f:
	/* 0x186f: lea    eax,[r13-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_1873:
	/* 0x1873: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1878:
	/* 0x1878: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_187c:
	/* 0x187c: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1881:
	/* 0x1881: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1886:
	/* 0x1886: jae    298c <generic_retkprobe_filter_arg+0x298c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10636ULL;
	}
x86_l_188c:
	/* 0x188c: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1891:
	/* 0x1891: cmp    r13,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 416ULL);
x86_l_1898:
	/* 0x1898: jne    182f <generic_retkprobe_filter_arg+0x182f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_182f;
	}
x86_l_189a:
	/* 0x189a: jmp    357d <generic_retkprobe_filter_arg+0x357d> */
	return 13693ULL;
x86_l_189f:
	/* 0x189f: mov    r13d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_32);
x86_l_18a2:
	/* 0x18a2: mov    QWORD PTR [rsp+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18a7:
	/* 0x18a7: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_18aa:
	/* 0x18aa: jne    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 187ULL;
	}
x86_l_18b0:
	/* 0x18b0: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18b5:
	/* 0x18b5: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18b9:
	/* 0x18b9: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_18c1:
	/* 0x18c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18c6:
	/* 0x18c6: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18cb:
	/* 0x18cb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_18d2:
	/* 0x18d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18d4:
	/* 0x18d4: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_18d7:
	/* 0x18d7: je     1bc8 <generic_retkprobe_filter_arg+0x1bc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7112ULL;
	}
x86_l_18dd:
	/* 0x18dd: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_18e2:
	/* 0x18e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18e5:
	/* 0x18e5: je     1bca <generic_retkprobe_filter_arg+0x1bca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7114ULL;
	}
x86_l_18eb:
	/* 0x18eb: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_18ee:
	/* 0x18ee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18f3:
	/* 0x18f3: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18f8:
	/* 0x18f8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_18ff:
	/* 0x18ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1901:
	/* 0x1901: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1904:
	/* 0x1904: je     1bc8 <generic_retkprobe_filter_arg+0x1bc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7112ULL;
	}
x86_l_190a:
	/* 0x190a: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_190c:
	/* 0x190c: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_190f:
	/* 0x190f: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1911:
	/* 0x1911: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1914:
	/* 0x1914: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1918:
	/* 0x1918: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_191b:
	/* 0x191b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1920:
	/* 0x1920: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1925:
	/* 0x1925: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1927:
	/* 0x1927: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1929:
	/* 0x1929: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_192e:
	/* 0x192e: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1931:
	/* 0x1931: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1934:
	/* 0x1934: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1936:
	/* 0x1936: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1938:
	/* 0x1938: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_193b:
	/* 0x193b: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_193e:
	/* 0x193e: jmp    1bca <generic_retkprobe_filter_arg+0x1bca> */
	return 7114ULL;
x86_l_1943:
	/* 0x1943: movzx  ebx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1948:
	/* 0x1948: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_194e:
	/* 0x194e: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1952:
	/* 0x1952: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1957:
	/* 0x1957: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_195c:
	/* 0x195c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1963:
	/* 0x1963: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1965:
	/* 0x1965: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1968:
	/* 0x1968: je     20e8 <generic_retkprobe_filter_arg+0x20e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8424ULL;
	}
x86_l_196e:
	/* 0x196e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1971:
	/* 0x1971: mov    QWORD PTR [rsp+0x38],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1976:
	/* 0x1976: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_197b:
	/* 0x197b: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1980:
	/* 0x1980: jmp    1b7e <generic_retkprobe_filter_arg+0x1b7e> */
	return 7038ULL;
x86_l_1985:
	/* 0x1985: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_198a:
	/* 0x198a: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_198e:
	/* 0x198e: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1996:
	/* 0x1996: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_199b:
	/* 0x199b: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19a0:
	/* 0x19a0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_19a7:
	/* 0x19a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a9:
	/* 0x19a9: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_19ab:
	/* 0x19ab: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13677ULL;
	}
x86_l_19b1:
	/* 0x19b1: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_19b4:
	/* 0x19b4: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_19b9:
	/* 0x19b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19bc:
	/* 0x19bc: je     356f <generic_retkprobe_filter_arg+0x356f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13679ULL;
	}
x86_l_19c2:
	/* 0x19c2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19c7:
	/* 0x19c7: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
	return 6604ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6604ULL: goto x86_l_19cc;
	case 6611ULL: goto x86_l_19d3;
	case 6613ULL: goto x86_l_19d5;
	case 6616ULL: goto x86_l_19d8;
	case 6622ULL: goto x86_l_19de;
	case 6628ULL: goto x86_l_19e4;
	case 6633ULL: goto x86_l_19e9;
	case 6636ULL: goto x86_l_19ec;
	case 6643ULL: goto x86_l_19f3;
	case 6645ULL: goto x86_l_19f5;
	case 6648ULL: goto x86_l_19f8;
	case 6652ULL: goto x86_l_19fc;
	case 6655ULL: goto x86_l_19ff;
	case 6660ULL: goto x86_l_1a04;
	case 6665ULL: goto x86_l_1a09;
	case 6667ULL: goto x86_l_1a0b;
	case 6669ULL: goto x86_l_1a0d;
	case 6674ULL: goto x86_l_1a12;
	case 6677ULL: goto x86_l_1a15;
	case 6680ULL: goto x86_l_1a18;
	case 6682ULL: goto x86_l_1a1a;
	case 6684ULL: goto x86_l_1a1c;
	case 6687ULL: goto x86_l_1a1f;
	case 6690ULL: goto x86_l_1a22;
	case 6695ULL: goto x86_l_1a27;
	case 6703ULL: goto x86_l_1a2f;
	case 6709ULL: goto x86_l_1a35;
	case 6715ULL: goto x86_l_1a3b;
	case 6718ULL: goto x86_l_1a3e;
	case 6723ULL: goto x86_l_1a43;
	case 6728ULL: goto x86_l_1a48;
	case 6734ULL: goto x86_l_1a4e;
	case 6738ULL: goto x86_l_1a52;
	case 6744ULL: goto x86_l_1a58;
	case 6747ULL: goto x86_l_1a5b;
	case 6750ULL: goto x86_l_1a5e;
	case 6753ULL: goto x86_l_1a61;
	case 6755ULL: goto x86_l_1a63;
	case 6758ULL: goto x86_l_1a66;
	case 6760ULL: goto x86_l_1a68;
	case 6762ULL: goto x86_l_1a6a;
	case 6764ULL: goto x86_l_1a6c;
	case 6766ULL: goto x86_l_1a6e;
	case 6768ULL: goto x86_l_1a70;
	case 6771ULL: goto x86_l_1a73;
	case 6773ULL: goto x86_l_1a75;
	case 6775ULL: goto x86_l_1a77;
	case 6777ULL: goto x86_l_1a79;
	case 6780ULL: goto x86_l_1a7c;
	case 6783ULL: goto x86_l_1a7f;
	case 6787ULL: goto x86_l_1a83;
	case 6793ULL: goto x86_l_1a89;
	case 6795ULL: goto x86_l_1a8b;
	case 6798ULL: goto x86_l_1a8e;
	case 6804ULL: goto x86_l_1a94;
	case 6807ULL: goto x86_l_1a97;
	case 6809ULL: goto x86_l_1a99;
	case 6814ULL: goto x86_l_1a9e;
	case 6818ULL: goto x86_l_1aa2;
	case 6821ULL: goto x86_l_1aa5;
	case 6823ULL: goto x86_l_1aa7;
	case 6826ULL: goto x86_l_1aaa;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6840ULL: goto x86_l_1ab8;
	case 6846ULL: goto x86_l_1abe;
	case 6851ULL: goto x86_l_1ac3;
	case 6856ULL: goto x86_l_1ac8;
	case 6859ULL: goto x86_l_1acb;
	case 6861ULL: goto x86_l_1acd;
	case 6864ULL: goto x86_l_1ad0;
	case 6870ULL: goto x86_l_1ad6;
	case 6873ULL: goto x86_l_1ad9;
	case 6877ULL: goto x86_l_1add;
	case 6883ULL: goto x86_l_1ae3;
	case 6886ULL: goto x86_l_1ae6;
	case 6892ULL: goto x86_l_1aec;
	case 6897ULL: goto x86_l_1af1;
	case 6901ULL: goto x86_l_1af5;
	case 6904ULL: goto x86_l_1af8;
	case 6908ULL: goto x86_l_1afc;
	case 6911ULL: goto x86_l_1aff;
	case 6914ULL: goto x86_l_1b02;
	case 6917ULL: goto x86_l_1b05;
	case 6922ULL: goto x86_l_1b0a;
	case 6925ULL: goto x86_l_1b0d;
	case 6931ULL: goto x86_l_1b13;
	case 6936ULL: goto x86_l_1b18;
	case 6941ULL: goto x86_l_1b1d;
	case 6944ULL: goto x86_l_1b20;
	case 6946ULL: goto x86_l_1b22;
	case 6949ULL: goto x86_l_1b25;
	case 6955ULL: goto x86_l_1b2b;
	case 6958ULL: goto x86_l_1b2e;
	case 6962ULL: goto x86_l_1b32;
	case 6965ULL: goto x86_l_1b35;
	case 6969ULL: goto x86_l_1b39;
	case 6974ULL: goto x86_l_1b3e;
	case 6979ULL: goto x86_l_1b43;
	case 6985ULL: goto x86_l_1b49;
	case 6989ULL: goto x86_l_1b4d;
	case 6994ULL: goto x86_l_1b52;
	case 7001ULL: goto x86_l_1b59;
	case 7006ULL: goto x86_l_1b5e;
	case 7008ULL: goto x86_l_1b60;
	case 7011ULL: goto x86_l_1b63;
	case 7017ULL: goto x86_l_1b69;
	case 7020ULL: goto x86_l_1b6c;
	case 7023ULL: goto x86_l_1b6f;
	case 7028ULL: goto x86_l_1b74;
	case 7033ULL: goto x86_l_1b79;
	case 7038ULL: goto x86_l_1b7e;
	case 7040ULL: goto x86_l_1b80;
	case 7045ULL: goto x86_l_1b85;
	case 7047ULL: goto x86_l_1b87;
	case 7050ULL: goto x86_l_1b8a;
	case 7056ULL: goto x86_l_1b90;
	case 7061ULL: goto x86_l_1b95;
	case 7064ULL: goto x86_l_1b98;
	case 7068ULL: goto x86_l_1b9c;
	case 7073ULL: goto x86_l_1ba1;
	case 7078ULL: goto x86_l_1ba6;
	case 7080ULL: goto x86_l_1ba8;
	case 7083ULL: goto x86_l_1bab;
	case 7086ULL: goto x86_l_1bae;
	case 7088ULL: goto x86_l_1bb0;
	case 7093ULL: goto x86_l_1bb5;
	case 7096ULL: goto x86_l_1bb8;
	case 7098ULL: goto x86_l_1bba;
	case 7101ULL: goto x86_l_1bbd;
	case 7104ULL: goto x86_l_1bc0;
	case 7107ULL: goto x86_l_1bc3;
	case 7112ULL: goto x86_l_1bc8;
	case 7114ULL: goto x86_l_1bca;
	case 7119ULL: goto x86_l_1bcf;
	case 7123ULL: goto x86_l_1bd3;
	case 7129ULL: goto x86_l_1bd9;
	case 7139ULL: goto x86_l_1be3;
	case 7143ULL: goto x86_l_1be7;
	case 7147ULL: goto x86_l_1beb;
	case 7152ULL: goto x86_l_1bf0;
	case 7157ULL: goto x86_l_1bf5;
	case 7163ULL: goto x86_l_1bfb;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7176ULL: goto x86_l_1c08;
	case 7179ULL: goto x86_l_1c0b;
	case 7182ULL: goto x86_l_1c0e;
	case 7186ULL: goto x86_l_1c12;
	case 7191ULL: goto x86_l_1c17;
	case 7196ULL: goto x86_l_1c1c;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7209ULL: goto x86_l_1c29;
	case 7214ULL: goto x86_l_1c2e;
	case 7216ULL: goto x86_l_1c30;
	case 7221ULL: goto x86_l_1c35;
	case 7226ULL: goto x86_l_1c3a;
	case 7228ULL: goto x86_l_1c3c;
	case 7233ULL: goto x86_l_1c41;
	case 7238ULL: goto x86_l_1c46;
	case 7240ULL: goto x86_l_1c48;
	case 7242ULL: goto x86_l_1c4a;
	case 7247ULL: goto x86_l_1c4f;
	case 7250ULL: goto x86_l_1c52;
	case 7253ULL: goto x86_l_1c55;
	case 7259ULL: goto x86_l_1c5b;
	case 7265ULL: goto x86_l_1c61;
	case 7271ULL: goto x86_l_1c67;
	case 7274ULL: goto x86_l_1c6a;
	case 7280ULL: goto x86_l_1c70;
	case 7282ULL: goto x86_l_1c72;
	case 7288ULL: goto x86_l_1c78;
	case 7291ULL: goto x86_l_1c7b;
	case 7297ULL: goto x86_l_1c81;
	case 7302ULL: goto x86_l_1c86;
	case 7307ULL: goto x86_l_1c8b;
	case 7311ULL: goto x86_l_1c8f;
	case 7317ULL: goto x86_l_1c95;
	case 7319ULL: goto x86_l_1c97;
	case 7323ULL: goto x86_l_1c9b;
	case 7329ULL: goto x86_l_1ca1;
	case 7334ULL: goto x86_l_1ca6;
	case 7337ULL: goto x86_l_1ca9;
	case 7343ULL: goto x86_l_1caf;
	case 7348ULL: goto x86_l_1cb4;
	case 7351ULL: goto x86_l_1cb7;
	case 7353ULL: goto x86_l_1cb9;
	case 7356ULL: goto x86_l_1cbc;
	case 7359ULL: goto x86_l_1cbf;
	case 7361ULL: goto x86_l_1cc1;
	case 7365ULL: goto x86_l_1cc5;
	case 7369ULL: goto x86_l_1cc9;
	case 7375ULL: goto x86_l_1ccf;
	case 7380ULL: goto x86_l_1cd4;
	case 7383ULL: goto x86_l_1cd7;
	case 7389ULL: goto x86_l_1cdd;
	case 7392ULL: goto x86_l_1ce0;
	case 7398ULL: goto x86_l_1ce6;
	case 7401ULL: goto x86_l_1ce9;
	case 7403ULL: goto x86_l_1ceb;
	case 7406ULL: goto x86_l_1cee;
	case 7412ULL: goto x86_l_1cf4;
	case 7416ULL: goto x86_l_1cf8;
	case 7422ULL: goto x86_l_1cfe;
	case 7427ULL: goto x86_l_1d03;
	case 7430ULL: goto x86_l_1d06;
	case 7434ULL: goto x86_l_1d0a;
	case 7440ULL: goto x86_l_1d10;
	case 7444ULL: goto x86_l_1d14;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7458ULL: goto x86_l_1d22;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7471ULL: goto x86_l_1d2f;
	case 7477ULL: goto x86_l_1d35;
	case 7482ULL: goto x86_l_1d3a;
	case 7485ULL: goto x86_l_1d3d;
	case 7491ULL: goto x86_l_1d43;
	case 7496ULL: goto x86_l_1d48;
	case 7498ULL: goto x86_l_1d4a;
	case 7504ULL: goto x86_l_1d50;
	case 7509ULL: goto x86_l_1d55;
	case 7512ULL: goto x86_l_1d58;
	case 7518ULL: goto x86_l_1d5e;
	case 7521ULL: goto x86_l_1d61;
	case 7527ULL: goto x86_l_1d67;
	case 7532ULL: goto x86_l_1d6c;
	case 7537ULL: goto x86_l_1d71;
	case 7540ULL: goto x86_l_1d74;
	case 7542ULL: goto x86_l_1d76;
	case 7545ULL: goto x86_l_1d79;
	case 7551ULL: goto x86_l_1d7f;
	case 7555ULL: goto x86_l_1d83;
	case 7561ULL: goto x86_l_1d89;
	case 7566ULL: goto x86_l_1d8e;
	case 7571ULL: goto x86_l_1d93;
	case 7576ULL: goto x86_l_1d98;
	case 7578ULL: goto x86_l_1d9a;
	case 7583ULL: goto x86_l_1d9f;
	case 7588ULL: goto x86_l_1da4;
	case 7593ULL: goto x86_l_1da9;
	case 7597ULL: goto x86_l_1dad;
	case 7602ULL: goto x86_l_1db2;
	case 7605ULL: goto x86_l_1db5;
	case 7608ULL: goto x86_l_1db8;
	case 7611ULL: goto x86_l_1dbb;
	case 7617ULL: goto x86_l_1dc1;
	case 7622ULL: goto x86_l_1dc6;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7635ULL: goto x86_l_1dd3;
	case 7638ULL: goto x86_l_1dd6;
	case 7641ULL: goto x86_l_1dd9;
	case 7644ULL: goto x86_l_1ddc;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7659ULL: goto x86_l_1deb;
	case 7664ULL: goto x86_l_1df0;
	case 7668ULL: goto x86_l_1df4;
	case 7671ULL: goto x86_l_1df7;
	case 7674ULL: goto x86_l_1dfa;
	case 7677ULL: goto x86_l_1dfd;
	case 7683ULL: goto x86_l_1e03;
	case 7688ULL: goto x86_l_1e08;
	case 7691ULL: goto x86_l_1e0b;
	case 7696ULL: goto x86_l_1e10;
	case 7699ULL: goto x86_l_1e13;
	case 7701ULL: goto x86_l_1e15;
	case 7703ULL: goto x86_l_1e17;
	case 7708ULL: goto x86_l_1e1c;
	case 7711ULL: goto x86_l_1e1f;
	case 7717ULL: goto x86_l_1e25;
	case 7720ULL: goto x86_l_1e28;
	case 7726ULL: goto x86_l_1e2e;
	case 7732ULL: goto x86_l_1e34;
	case 7737ULL: goto x86_l_1e39;
	case 7742ULL: goto x86_l_1e3e;
	case 7744ULL: goto x86_l_1e40;
	case 7750ULL: goto x86_l_1e46;
	case 7755ULL: goto x86_l_1e4b;
	case 7758ULL: goto x86_l_1e4e;
	case 7764ULL: goto x86_l_1e54;
	case 7769ULL: goto x86_l_1e59;
	case 7772ULL: goto x86_l_1e5c;
	case 7778ULL: goto x86_l_1e62;
	case 7781ULL: goto x86_l_1e65;
	case 7784ULL: goto x86_l_1e68;
	case 7790ULL: goto x86_l_1e6e;
	case 7795ULL: goto x86_l_1e73;
	case 7797ULL: goto x86_l_1e75;
	case 7803ULL: goto x86_l_1e7b;
	case 7808ULL: goto x86_l_1e80;
	case 7813ULL: goto x86_l_1e85;
	case 7815ULL: goto x86_l_1e87;
	case 7821ULL: goto x86_l_1e8d;
	case 7826ULL: goto x86_l_1e92;
	case 7829ULL: goto x86_l_1e95;
	case 7835ULL: goto x86_l_1e9b;
	case 7840ULL: goto x86_l_1ea0;
	case 7843ULL: goto x86_l_1ea3;
	case 7849ULL: goto x86_l_1ea9;
	case 7852ULL: goto x86_l_1eac;
	case 7855ULL: goto x86_l_1eaf;
	case 7861ULL: goto x86_l_1eb5;
	case 7866ULL: goto x86_l_1eba;
	case 7868ULL: goto x86_l_1ebc;
	case 7874ULL: goto x86_l_1ec2;
	case 7879ULL: goto x86_l_1ec7;
	case 7883ULL: goto x86_l_1ecb;
	case 7885ULL: goto x86_l_1ecd;
	case 7887ULL: goto x86_l_1ecf;
	case 7889ULL: goto x86_l_1ed1;
	case 7895ULL: goto x86_l_1ed7;
	case 7900ULL: goto x86_l_1edc;
	case 7903ULL: goto x86_l_1edf;
	case 7909ULL: goto x86_l_1ee5;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7922ULL: goto x86_l_1ef2;
	case 7928ULL: goto x86_l_1ef8;
	case 7934ULL: goto x86_l_1efe;
	case 7938ULL: goto x86_l_1f02;
	case 7944ULL: goto x86_l_1f08;
	case 7946ULL: goto x86_l_1f0a;
	case 7950ULL: goto x86_l_1f0e;
	case 7956ULL: goto x86_l_1f14;
	case 7958ULL: goto x86_l_1f16;
	case 7964ULL: goto x86_l_1f1c;
	case 7969ULL: goto x86_l_1f21;
	case 7973ULL: goto x86_l_1f25;
	case 7975ULL: goto x86_l_1f27;
	case 7979ULL: goto x86_l_1f2b;
	case 7981ULL: goto x86_l_1f2d;
	case 7984ULL: goto x86_l_1f30;
	case 7987ULL: goto x86_l_1f33;
	case 7992ULL: goto x86_l_1f38;
	case 7995ULL: goto x86_l_1f3b;
	case 8001ULL: goto x86_l_1f41;
	case 8006ULL: goto x86_l_1f46;
	case 8011ULL: goto x86_l_1f4b;
	case 8014ULL: goto x86_l_1f4e;
	case 8020ULL: goto x86_l_1f54;
	case 8026ULL: goto x86_l_1f5a;
	case 8030ULL: goto x86_l_1f5e;
	case 8036ULL: goto x86_l_1f64;
	case 8039ULL: goto x86_l_1f67;
	case 8043ULL: goto x86_l_1f6b;
	case 8045ULL: goto x86_l_1f6d;
	case 8049ULL: goto x86_l_1f71;
	case 8054ULL: goto x86_l_1f76;
	case 8057ULL: goto x86_l_1f79;
	case 8063ULL: goto x86_l_1f7f;
	case 8066ULL: goto x86_l_1f82;
	case 8072ULL: goto x86_l_1f88;
	case 8077ULL: goto x86_l_1f8d;
	case 8082ULL: goto x86_l_1f92;
	case 8084ULL: goto x86_l_1f94;
	case 8087ULL: goto x86_l_1f97;
	case 8092ULL: goto x86_l_1f9c;
	case 8096ULL: goto x86_l_1fa0;
	case 8101ULL: goto x86_l_1fa5;
	case 8106ULL: goto x86_l_1faa;
	case 8113ULL: goto x86_l_1fb1;
	case 8115ULL: goto x86_l_1fb3;
	case 8118ULL: goto x86_l_1fb6;
	case 8120ULL: goto x86_l_1fb8;
	case 8122ULL: goto x86_l_1fba;
	case 8127ULL: goto x86_l_1fbf;
	case 8132ULL: goto x86_l_1fc4;
	case 8134ULL: goto x86_l_1fc6;
	case 8139ULL: goto x86_l_1fcb;
	case 8141ULL: goto x86_l_1fcd;
	case 8143ULL: goto x86_l_1fcf;
	case 8146ULL: goto x86_l_1fd2;
	case 8149ULL: goto x86_l_1fd5;
	case 8152ULL: goto x86_l_1fd8;
	case 8154ULL: goto x86_l_1fda;
	case 8156ULL: goto x86_l_1fdc;
	case 8160ULL: goto x86_l_1fe0;
	case 8163ULL: goto x86_l_1fe3;
	case 8165ULL: goto x86_l_1fe5;
	case 8169ULL: goto x86_l_1fe9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_19cc:
	/* 0x19cc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_19d3:
	/* 0x19d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d5:
	/* 0x19d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19d8:
	/* 0x19d8: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13677ULL;
	}
x86_l_19de:
	/* 0x19de: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_19e4:
	/* 0x19e4: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_19e9:
	/* 0x19e9: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_19ec:
	/* 0x19ec: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_19f3:
	/* 0x19f3: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19f5:
	/* 0x19f5: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_19f8:
	/* 0x19f8: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_19fc:
	/* 0x19fc: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_19ff:
	/* 0x19ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a04:
	/* 0x1a04: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a09:
	/* 0x1a09: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1a0b:
	/* 0x1a0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0d:
	/* 0x1a0d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a12:
	/* 0x1a12: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1a15:
	/* 0x1a15: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1a18:
	/* 0x1a18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a1a:
	/* 0x1a1a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a1c:
	/* 0x1a1c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a1f:
	/* 0x1a1f: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_1a22:
	/* 0x1a22: jmp    356f <generic_retkprobe_filter_arg+0x356f> */
	return 13679ULL;
x86_l_1a27:
	/* 0x1a27: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1a2f:
	/* 0x1a2f: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_1a35:
	/* 0x1a35: ja     298c <generic_retkprobe_filter_arg+0x298c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10636ULL;
	}
x86_l_1a3b:
	/* 0x1a3b: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1a3e:
	/* 0x1a3e: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1a43:
	/* 0x1a43: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a48:
	/* 0x1a48: ja     26ca <generic_retkprobe_filter_arg+0x26ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9930ULL;
	}
x86_l_1a4e:
	/* 0x1a4e: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a52:
	/* 0x1a52: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1a58:
	/* 0x1a58: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1a5b:
	/* 0x1a5b: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1a5e:
	/* 0x1a5e: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1a61:
	/* 0x1a61: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1a63:
	/* 0x1a63: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1a66:
	/* 0x1a66: je     1a70 <generic_retkprobe_filter_arg+0x1a70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a70;
	}
x86_l_1a68:
	/* 0x1a68: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1a6a:
	/* 0x1a6a: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1a6c:
	/* 0x1a6c: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1a6e:
	/* 0x1a6e: je     1a8b <generic_retkprobe_filter_arg+0x1a8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a8b;
	}
x86_l_1a70:
	/* 0x1a70: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a73:
	/* 0x1a73: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1a75:
	/* 0x1a75: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1a77:
	/* 0x1a77: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1a79:
	/* 0x1a79: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1a7c:
	/* 0x1a7c: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1a7f:
	/* 0x1a7f: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1a83:
	/* 0x1a83: ja     2701 <generic_retkprobe_filter_arg+0x2701> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9985ULL;
	}
x86_l_1a89:
	/* 0x1a89: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1a8b:
	/* 0x1a8b: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a8e:
	/* 0x1a8e: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1a94:
	/* 0x1a94: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1a97:
	/* 0x1a97: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1a99:
	/* 0x1a99: jmp    2f73 <generic_retkprobe_filter_arg+0x2f73> */
	return 12147ULL;
x86_l_1a9e:
	/* 0x1a9e: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa2:
	/* 0x1aa2: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1aa5:
	/* 0x1aa5: ja     1ab0 <generic_retkprobe_filter_arg+0x1ab0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ab0;
	}
x86_l_1aa7:
	/* 0x1aa7: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1aaa:
	/* 0x1aaa: jbe    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 620ULL;
	}
x86_l_1ab0:
	/* 0x1ab0: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ab5:
	/* 0x1ab5: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1ab8:
	/* 0x1ab8: jb     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 187ULL;
	}
x86_l_1abe:
	/* 0x1abe: mov    rdi,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ac3:
	/* 0x1ac3: mov    rsi,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ac8:
	/* 0x1ac8: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1acb:
	/* 0x1acb: je     1ad6 <generic_retkprobe_filter_arg+0x1ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ad6;
	}
x86_l_1acd:
	/* 0x1acd: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1ad0:
	/* 0x1ad0: jne    2109 <generic_retkprobe_filter_arg+0x2109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8457ULL;
	}
x86_l_1ad6:
	/* 0x1ad6: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ad9:
	/* 0x1ad9: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1add:
	/* 0x1add: jg     211b <generic_retkprobe_filter_arg+0x211b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8475ULL;
	}
x86_l_1ae3:
	/* 0x1ae3: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_1ae6:
	/* 0x1ae6: jle    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 620ULL;
	}
x86_l_1aec:
	/* 0x1aec: jmp    211b <generic_retkprobe_filter_arg+0x211b> */
	return 8475ULL;
x86_l_1af1:
	/* 0x1af1: mov    rdx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af5:
	/* 0x1af5: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1af8:
	/* 0x1af8: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1afc:
	/* 0x1afc: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1aff:
	/* 0x1aff: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1b02:
	/* 0x1b02: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1b05:
	/* 0x1b05: mov    esi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b0a:
	/* 0x1b0a: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_1b0d:
	/* 0x1b0d: jb     2ded <generic_retkprobe_filter_arg+0x2ded> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11757ULL;
	}
x86_l_1b13:
	/* 0x1b13: mov    r8,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b18:
	/* 0x1b18: mov    rdi,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b1d:
	/* 0x1b1d: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1b20:
	/* 0x1b20: je     1b2b <generic_retkprobe_filter_arg+0x1b2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b2b;
	}
x86_l_1b22:
	/* 0x1b22: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1b25:
	/* 0x1b25: jne    2047 <generic_retkprobe_filter_arg+0x2047> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8263ULL;
	}
x86_l_1b2b:
	/* 0x1b2b: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_1b2e:
	/* 0x1b2e: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1b32:
	/* 0x1b32: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1b35:
	/* 0x1b35: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1b39:
	/* 0x1b39: jmp    2055 <generic_retkprobe_filter_arg+0x2055> */
	return 8277ULL;
x86_l_1b3e:
	/* 0x1b3e: movzx  ebx,WORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1b43:
	/* 0x1b43: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1b49:
	/* 0x1b49: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1b4d:
	/* 0x1b4d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b52:
	/* 0x1b52: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1b59:
	/* 0x1b59: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1b5e:
	/* 0x1b5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b60:
	/* 0x1b60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b63:
	/* 0x1b63: je     20e8 <generic_retkprobe_filter_arg+0x20e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8424ULL;
	}
x86_l_1b69:
	/* 0x1b69: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b6c:
	/* 0x1b6c: movzx  eax,bx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1b6f:
	/* 0x1b6f: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b74:
	/* 0x1b74: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b79:
	/* 0x1b79: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b7e:
	/* 0x1b7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b80:
	/* 0x1b80: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b85:
	/* 0x1b85: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b87:
	/* 0x1b87: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1b8a:
	/* 0x1b8a: ja     2157 <generic_retkprobe_filter_arg+0x2157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8535ULL;
	}
x86_l_1b90:
	/* 0x1b90: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1b95:
	/* 0x1b95: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1b98:
	/* 0x1b98: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b9c:
	/* 0x1b9c: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ba1:
	/* 0x1ba1: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ba6:
	/* 0x1ba6: jae    1bb0 <generic_retkprobe_filter_arg+0x1bb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1bb0;
	}
x86_l_1ba8:
	/* 0x1ba8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bab:
	/* 0x1bab: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1bae:
	/* 0x1bae: jmp    1bc0 <generic_retkprobe_filter_arg+0x1bc0> */
	goto x86_l_1bc0;
x86_l_1bb0:
	/* 0x1bb0: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1bb5:
	/* 0x1bb5: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1bb8:
	/* 0x1bb8: jae    1bc0 <generic_retkprobe_filter_arg+0x1bc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1bc0;
	}
x86_l_1bba:
	/* 0x1bba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bbd:
	/* 0x1bbd: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1bc0:
	/* 0x1bc0: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1bc3:
	/* 0x1bc3: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_1bc8:
	/* 0x1bc8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bca:
	/* 0x1bca: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1bcf:
	/* 0x1bcf: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_1bd3:
	/* 0x1bd3: ja     20ea <generic_retkprobe_filter_arg+0x20ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8426ULL;
	}
x86_l_1bd9:
	/* 0x1bd9: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_1be3:
	/* 0x1be3: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1be7:
	/* 0x1be7: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1beb:
	/* 0x1beb: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bf0:
	/* 0x1bf0: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bf5:
	/* 0x1bf5: jb     3204 <generic_retkprobe_filter_arg+0x3204> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12804ULL;
	}
x86_l_1bfb:
	/* 0x1bfb: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_1c00:
	/* 0x1c00: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c05:
	/* 0x1c05: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1c08:
	/* 0x1c08: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1c0b:
	/* 0x1c0b: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1c0e:
	/* 0x1c0e: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c12:
	/* 0x1c12: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c17:
	/* 0x1c17: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c1c:
	/* 0x1c1c: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1c1f:
	/* 0x1c1f: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_1c24:
	/* 0x1c24: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1c29:
	/* 0x1c29: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1c2e:
	/* 0x1c2e: jb     1c5b <generic_retkprobe_filter_arg+0x1c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1c5b;
	}
x86_l_1c30:
	/* 0x1c30: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_1c35:
	/* 0x1c35: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_1c3a:
	/* 0x1c3a: jb     1c5b <generic_retkprobe_filter_arg+0x1c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1c5b;
	}
x86_l_1c3c:
	/* 0x1c3c: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_1c41:
	/* 0x1c41: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_1c46:
	/* 0x1c46: jb     1c5b <generic_retkprobe_filter_arg+0x1c5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1c5b;
	}
x86_l_1c48:
	/* 0x1c48: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c4a:
	/* 0x1c4a: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_1c4f:
	/* 0x1c4f: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_1c52:
	/* 0x1c52: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_1c55:
	/* 0x1c55: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_1c5b:
	/* 0x1c5b: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_1c61:
	/* 0x1c61: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_1c67:
	/* 0x1c67: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c6a:
	/* 0x1c6a: jg     1f76 <generic_retkprobe_filter_arg+0x1f76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f76;
	}
x86_l_1c70:
	/* 0x1c70: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c72:
	/* 0x1c72: je     28bb <generic_retkprobe_filter_arg+0x28bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10427ULL;
	}
x86_l_1c78:
	/* 0x1c78: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c7b:
	/* 0x1c7b: jne    28b4 <generic_retkprobe_filter_arg+0x28b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10420ULL;
	}
x86_l_1c81:
	/* 0x1c81: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1c86:
	/* 0x1c86: jmp    28c7 <generic_retkprobe_filter_arg+0x28c7> */
	return 10439ULL;
x86_l_1c8b:
	/* 0x1c8b: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c8f:
	/* 0x1c8f: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_1c95:
	/* 0x1c95: jmp    1ca1 <generic_retkprobe_filter_arg+0x1ca1> */
	goto x86_l_1ca1;
x86_l_1c97:
	/* 0x1c97: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c9b:
	/* 0x1c9b: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_1ca1:
	/* 0x1ca1: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ca6:
	/* 0x1ca6: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1ca9:
	/* 0x1ca9: jb     35dc <generic_retkprobe_filter_arg+0x35dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13788ULL;
	}
x86_l_1caf:
	/* 0x1caf: mov    rsi,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cb4:
	/* 0x1cb4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1cb7:
	/* 0x1cb7: jle    1cd4 <generic_retkprobe_filter_arg+0x1cd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1cd4;
	}
x86_l_1cb9:
	/* 0x1cb9: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1cbc:
	/* 0x1cbc: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1cbf:
	/* 0x1cbf: jae    1d03 <generic_retkprobe_filter_arg+0x1d03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d03;
	}
x86_l_1cc1:
	/* 0x1cc1: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc5:
	/* 0x1cc5: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc9:
	/* 0x1cc9: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 595ULL;
	}
x86_l_1ccf:
	/* 0x1ccf: jmp    27d4 <generic_retkprobe_filter_arg+0x27d4> */
	return 10196ULL;
x86_l_1cd4:
	/* 0x1cd4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cd7:
	/* 0x1cd7: je     1d71 <generic_retkprobe_filter_arg+0x1d71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d71;
	}
x86_l_1cdd:
	/* 0x1cdd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ce0:
	/* 0x1ce0: jne    27d4 <generic_retkprobe_filter_arg+0x27d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10196ULL;
	}
x86_l_1ce6:
	/* 0x1ce6: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1ce9:
	/* 0x1ce9: je     1cf4 <generic_retkprobe_filter_arg+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cf4;
	}
x86_l_1ceb:
	/* 0x1ceb: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1cee:
	/* 0x1cee: jne    27ca <generic_retkprobe_filter_arg+0x27ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10186ULL;
	}
x86_l_1cf4:
	/* 0x1cf4: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cf8:
	/* 0x1cf8: jl     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 620ULL;
	}
x86_l_1cfe:
	/* 0x1cfe: jmp    27d4 <generic_retkprobe_filter_arg+0x27d4> */
	return 10196ULL;
x86_l_1d03:
	/* 0x1d03: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d06:
	/* 0x1d06: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d0a:
	/* 0x1d0a: jne    27d4 <generic_retkprobe_filter_arg+0x27d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10196ULL;
	}
x86_l_1d10:
	/* 0x1d10: test   QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d14:
	/* 0x1d14: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_1d1a:
	/* 0x1d1a: jmp    27d4 <generic_retkprobe_filter_arg+0x27d4> */
	return 10196ULL;
x86_l_1d1f:
	/* 0x1d1f: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d22:
	/* 0x1d22: jne    1e46 <generic_retkprobe_filter_arg+0x1e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e46;
	}
x86_l_1d28:
	/* 0x1d28: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1d2d:
	/* 0x1d2d: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1d2f:
	/* 0x1d2f: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_1d35:
	/* 0x1d35: jmp    1e46 <generic_retkprobe_filter_arg+0x1e46> */
	goto x86_l_1e46;
x86_l_1d3a:
	/* 0x1d3a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d3d:
	/* 0x1d3d: jne    1e8d <generic_retkprobe_filter_arg+0x1e8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e8d;
	}
x86_l_1d43:
	/* 0x1d43: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d48:
	/* 0x1d48: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1d4a:
	/* 0x1d4a: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_1d50:
	/* 0x1d50: jmp    1e8d <generic_retkprobe_filter_arg+0x1e8d> */
	goto x86_l_1e8d;
x86_l_1d55:
	/* 0x1d55: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1d58:
	/* 0x1d58: je     2291 <generic_retkprobe_filter_arg+0x2291> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8849ULL;
	}
x86_l_1d5e:
	/* 0x1d5e: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1d61:
	/* 0x1d61: jne    2283 <generic_retkprobe_filter_arg+0x2283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8835ULL;
	}
x86_l_1d67:
	/* 0x1d67: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_1d6c:
	/* 0x1d6c: jmp    2296 <generic_retkprobe_filter_arg+0x2296> */
	return 8854ULL;
x86_l_1d71:
	/* 0x1d71: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1d74:
	/* 0x1d74: je     1d7f <generic_retkprobe_filter_arg+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d7f;
	}
x86_l_1d76:
	/* 0x1d76: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1d79:
	/* 0x1d79: jne    27be <generic_retkprobe_filter_arg+0x27be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10174ULL;
	}
x86_l_1d7f:
	/* 0x1d7f: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d83:
	/* 0x1d83: jg     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 620ULL;
	}
x86_l_1d89:
	/* 0x1d89: jmp    27d4 <generic_retkprobe_filter_arg+0x27d4> */
	return 10196ULL;
x86_l_1d8e:
	/* 0x1d8e: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d93:
	/* 0x1d93: movzx  ecx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1d98:
	/* 0x1d98: jmp    1da4 <generic_retkprobe_filter_arg+0x1da4> */
	goto x86_l_1da4;
x86_l_1d9a:
	/* 0x1d9a: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d9f:
	/* 0x1d9f: movzx  ecx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1da4:
	/* 0x1da4: cmp    DWORD PTR [r12+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1da9:
	/* 0x1da9: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1dad:
	/* 0x1dad: cmp    DWORD PTR [r12+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1db2:
	/* 0x1db2: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_1db5:
	/* 0x1db5: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1db8:
	/* 0x1db8: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1dbb:
	/* 0x1dbb: jb     2ded <generic_retkprobe_filter_arg+0x2ded> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11757ULL;
	}
x86_l_1dc1:
	/* 0x1dc1: cmp    DWORD PTR [r12+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dc6:
	/* 0x1dc6: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1dca:
	/* 0x1dca: cmp    DWORD PTR [r12+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1dcf:
	/* 0x1dcf: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1dd3:
	/* 0x1dd3: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1dd6:
	/* 0x1dd6: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1dd9:
	/* 0x1dd9: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1ddc:
	/* 0x1ddc: jb     2de9 <generic_retkprobe_filter_arg+0x2de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11753ULL;
	}
x86_l_1de2:
	/* 0x1de2: cmp    DWORD PTR [r12+0x20],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1de7:
	/* 0x1de7: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1deb:
	/* 0x1deb: cmp    DWORD PTR [r12+0x24],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1df0:
	/* 0x1df0: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1df4:
	/* 0x1df4: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1df7:
	/* 0x1df7: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1dfa:
	/* 0x1dfa: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1dfd:
	/* 0x1dfd: jb     2de9 <generic_retkprobe_filter_arg+0x2de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11753ULL;
	}
x86_l_1e03:
	/* 0x1e03: cmp    DWORD PTR [r12+0x28],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e08:
	/* 0x1e08: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_1e0b:
	/* 0x1e0b: cmp    DWORD PTR [r12+0x2c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1e10:
	/* 0x1e10: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_1e13:
	/* 0x1e13: and    cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e15:
	/* 0x1e15: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e17:
	/* 0x1e17: jmp    2de9 <generic_retkprobe_filter_arg+0x2de9> */
	return 11753ULL;
x86_l_1e1c:
	/* 0x1e1c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1e1f:
	/* 0x1e1f: je     24ba <generic_retkprobe_filter_arg+0x24ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9402ULL;
	}
x86_l_1e25:
	/* 0x1e25: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1e28:
	/* 0x1e28: jne    24aa <generic_retkprobe_filter_arg+0x24aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9386ULL;
	}
x86_l_1e2e:
	/* 0x1e2e: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_1e34:
	/* 0x1e34: jmp    24c0 <generic_retkprobe_filter_arg+0x24c0> */
	return 9408ULL;
x86_l_1e39:
	/* 0x1e39: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e3e:
	/* 0x1e3e: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1e40:
	/* 0x1e40: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_1e46:
	/* 0x1e46: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e4b:
	/* 0x1e4b: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1e4e:
	/* 0x1e4e: jb     35dc <generic_retkprobe_filter_arg+0x35dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13788ULL;
	}
x86_l_1e54:
	/* 0x1e54: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e59:
	/* 0x1e59: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e5c:
	/* 0x1e5c: jle    222d <generic_retkprobe_filter_arg+0x222d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8749ULL;
	}
x86_l_1e62:
	/* 0x1e62: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1e65:
	/* 0x1e65: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e68:
	/* 0x1e68: jae    284d <generic_retkprobe_filter_arg+0x284d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10317ULL;
	}
x86_l_1e6e:
	/* 0x1e6e: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e73:
	/* 0x1e73: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1e75:
	/* 0x1e75: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 595ULL;
	}
x86_l_1e7b:
	/* 0x1e7b: jmp    2ad8 <generic_retkprobe_filter_arg+0x2ad8> */
	return 10968ULL;
x86_l_1e80:
	/* 0x1e80: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e85:
	/* 0x1e85: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1e87:
	/* 0x1e87: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_1e8d:
	/* 0x1e8d: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e92:
	/* 0x1e92: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1e95:
	/* 0x1e95: jb     35dc <generic_retkprobe_filter_arg+0x35dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13788ULL;
	}
x86_l_1e9b:
	/* 0x1e9b: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1ea0:
	/* 0x1ea0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ea3:
	/* 0x1ea3: jle    2251 <generic_retkprobe_filter_arg+0x2251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8785ULL;
	}
x86_l_1ea9:
	/* 0x1ea9: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1eac:
	/* 0x1eac: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1eaf:
	/* 0x1eaf: jae    2868 <generic_retkprobe_filter_arg+0x2868> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10344ULL;
	}
x86_l_1eb5:
	/* 0x1eb5: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1eba:
	/* 0x1eba: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1ebc:
	/* 0x1ebc: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 595ULL;
	}
x86_l_1ec2:
	/* 0x1ec2: jmp    2b1a <generic_retkprobe_filter_arg+0x2b1a> */
	return 11034ULL;
x86_l_1ec7:
	/* 0x1ec7: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ecb:
	/* 0x1ecb: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1ecd:
	/* 0x1ecd: ja     1ed7 <generic_retkprobe_filter_arg+0x1ed7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ed7;
	}
x86_l_1ecf:
	/* 0x1ecf: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1ed1:
	/* 0x1ed1: jbe    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 620ULL;
	}
x86_l_1ed7:
	/* 0x1ed7: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1edc:
	/* 0x1edc: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1edf:
	/* 0x1edf: jb     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 187ULL;
	}
x86_l_1ee5:
	/* 0x1ee5: mov    edi,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1eea:
	/* 0x1eea: mov    esi,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1eef:
	/* 0x1eef: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1ef2:
	/* 0x1ef2: ja     2675 <generic_retkprobe_filter_arg+0x2675> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9845ULL;
	}
x86_l_1ef8:
	/* 0x1ef8: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_1efe:
	/* 0x1efe: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_1f02:
	/* 0x1f02: jae    2675 <generic_retkprobe_filter_arg+0x2675> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9845ULL;
	}
x86_l_1f08:
	/* 0x1f08: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_1f0a:
	/* 0x1f0a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f0e:
	/* 0x1f0e: jg     2685 <generic_retkprobe_filter_arg+0x2685> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9861ULL;
	}
x86_l_1f14:
	/* 0x1f14: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_1f16:
	/* 0x1f16: jle    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 620ULL;
	}
x86_l_1f1c:
	/* 0x1f1c: jmp    2685 <generic_retkprobe_filter_arg+0x2685> */
	return 9861ULL;
x86_l_1f21:
	/* 0x1f21: mov    edx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f25:
	/* 0x1f25: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1f27:
	/* 0x1f27: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1f2b:
	/* 0x1f2b: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1f2d:
	/* 0x1f2d: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1f30:
	/* 0x1f30: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f33:
	/* 0x1f33: mov    esi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f38:
	/* 0x1f38: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1f3b:
	/* 0x1f3b: jb     2ded <generic_retkprobe_filter_arg+0x2ded> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11757ULL;
	}
x86_l_1f41:
	/* 0x1f41: mov    r8d,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f46:
	/* 0x1f46: mov    edi,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f4b:
	/* 0x1f4b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1f4e:
	/* 0x1f4e: ja     2452 <generic_retkprobe_filter_arg+0x2452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9298ULL;
	}
x86_l_1f54:
	/* 0x1f54: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_1f5a:
	/* 0x1f5a: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_1f5e:
	/* 0x1f5e: jae    2452 <generic_retkprobe_filter_arg+0x2452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9298ULL;
	}
x86_l_1f64:
	/* 0x1f64: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_1f67:
	/* 0x1f67: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1f6b:
	/* 0x1f6b: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_1f6d:
	/* 0x1f6d: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1f71:
	/* 0x1f71: jmp    245f <generic_retkprobe_filter_arg+0x245f> */
	return 9311ULL;
x86_l_1f76:
	/* 0x1f76: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1f79:
	/* 0x1f79: je     28c2 <generic_retkprobe_filter_arg+0x28c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10434ULL;
	}
x86_l_1f7f:
	/* 0x1f7f: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1f82:
	/* 0x1f82: jne    28b4 <generic_retkprobe_filter_arg+0x28b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10420ULL;
	}
x86_l_1f88:
	/* 0x1f88: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_1f8d:
	/* 0x1f8d: jmp    28c7 <generic_retkprobe_filter_arg+0x28c7> */
	return 10439ULL;
x86_l_1f92:
	/* 0x1f92: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f94:
	/* 0x1f94: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f97:
	/* 0x1f97: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_1f9c:
	/* 0x1f9c: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1fa0:
	/* 0x1fa0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fa5:
	/* 0x1fa5: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1faa:
	/* 0x1faa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1fb1:
	/* 0x1fb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb3:
	/* 0x1fb3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fb6:
	/* 0x1fb6: je     2032 <generic_retkprobe_filter_arg+0x2032> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8242ULL;
	}
x86_l_1fb8:
	/* 0x1fb8: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1fba:
	/* 0x1fba: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fbf:
	/* 0x1fbf: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fc4:
	/* 0x1fc4: je     200b <generic_retkprobe_filter_arg+0x200b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8203ULL;
	}
x86_l_1fc6:
	/* 0x1fc6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fcb:
	/* 0x1fcb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fcd:
	/* 0x1fcd: jmp    1fda <generic_retkprobe_filter_arg+0x1fda> */
	goto x86_l_1fda;
x86_l_1fcf:
	/* 0x1fcf: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1fd2:
	/* 0x1fd2: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1fd5:
	/* 0x1fd5: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1fd8:
	/* 0x1fd8: je     200b <generic_retkprobe_filter_arg+0x200b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8203ULL;
	}
x86_l_1fda:
	/* 0x1fda: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fdc:
	/* 0x1fdc: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1fe0:
	/* 0x1fe0: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1fe3:
	/* 0x1fe3: jae    1fcf <generic_retkprobe_filter_arg+0x1fcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fcf;
	}
x86_l_1fe5:
	/* 0x1fe5: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1fe9:
	/* 0x1fe9: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
	return 8172ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8172ULL: goto x86_l_1fec;
	case 8174ULL: goto x86_l_1fee;
	case 8178ULL: goto x86_l_1ff2;
	case 8180ULL: goto x86_l_1ff4;
	case 8184ULL: goto x86_l_1ff8;
	case 8188ULL: goto x86_l_1ffc;
	case 8191ULL: goto x86_l_1fff;
	case 8193ULL: goto x86_l_2001;
	case 8195ULL: goto x86_l_2003;
	case 8197ULL: goto x86_l_2005;
	case 8203ULL: goto x86_l_200b;
	case 8207ULL: goto x86_l_200f;
	case 8212ULL: goto x86_l_2014;
	case 8214ULL: goto x86_l_2016;
	case 8218ULL: goto x86_l_201a;
	case 8221ULL: goto x86_l_201d;
	case 8225ULL: goto x86_l_2021;
	case 8231ULL: goto x86_l_2027;
	case 8233ULL: goto x86_l_2029;
	case 8237ULL: goto x86_l_202d;
	case 8242ULL: goto x86_l_2032;
	case 8244ULL: goto x86_l_2034;
	case 8249ULL: goto x86_l_2039;
	case 8254ULL: goto x86_l_203e;
	case 8258ULL: goto x86_l_2042;
	case 8263ULL: goto x86_l_2047;
	case 8266ULL: goto x86_l_204a;
	case 8270ULL: goto x86_l_204e;
	case 8273ULL: goto x86_l_2051;
	case 8277ULL: goto x86_l_2055;
	case 8280ULL: goto x86_l_2058;
	case 8283ULL: goto x86_l_205b;
	case 8286ULL: goto x86_l_205e;
	case 8292ULL: goto x86_l_2064;
	case 8297ULL: goto x86_l_2069;
	case 8302ULL: goto x86_l_206e;
	case 8305ULL: goto x86_l_2071;
	case 8307ULL: goto x86_l_2073;
	case 8310ULL: goto x86_l_2076;
	case 8316ULL: goto x86_l_207c;
	case 8319ULL: goto x86_l_207f;
	case 8323ULL: goto x86_l_2083;
	case 8326ULL: goto x86_l_2086;
	case 8330ULL: goto x86_l_208a;
	case 8335ULL: goto x86_l_208f;
	case 8337ULL: goto x86_l_2091;
	case 8340ULL: goto x86_l_2094;
	case 8342ULL: goto x86_l_2096;
	case 8345ULL: goto x86_l_2099;
	case 8347ULL: goto x86_l_209b;
	case 8351ULL: goto x86_l_209f;
	case 8354ULL: goto x86_l_20a2;
	case 8356ULL: goto x86_l_20a4;
	case 8359ULL: goto x86_l_20a7;
	case 8365ULL: goto x86_l_20ad;
	case 8371ULL: goto x86_l_20b3;
	case 8375ULL: goto x86_l_20b7;
	case 8380ULL: goto x86_l_20bc;
	case 8387ULL: goto x86_l_20c3;
	case 8392ULL: goto x86_l_20c8;
	case 8394ULL: goto x86_l_20ca;
	case 8397ULL: goto x86_l_20cd;
	case 8399ULL: goto x86_l_20cf;
	case 8402ULL: goto x86_l_20d2;
	case 8404ULL: goto x86_l_20d4;
	case 8409ULL: goto x86_l_20d9;
	case 8414ULL: goto x86_l_20de;
	case 8419ULL: goto x86_l_20e3;
	case 8424ULL: goto x86_l_20e8;
	case 8426ULL: goto x86_l_20ea;
	case 8430ULL: goto x86_l_20ee;
	case 8435ULL: goto x86_l_20f3;
	case 8440ULL: goto x86_l_20f8;
	case 8445ULL: goto x86_l_20fd;
	case 8447ULL: goto x86_l_20ff;
	case 8452ULL: goto x86_l_2104;
	case 8457ULL: goto x86_l_2109;
	case 8460ULL: goto x86_l_210c;
	case 8464ULL: goto x86_l_2110;
	case 8466ULL: goto x86_l_2112;
	case 8469ULL: goto x86_l_2115;
	case 8475ULL: goto x86_l_211b;
	case 8478ULL: goto x86_l_211e;
	case 8484ULL: goto x86_l_2124;
	case 8489ULL: goto x86_l_2129;
	case 8494ULL: goto x86_l_212e;
	case 8497ULL: goto x86_l_2131;
	case 8499ULL: goto x86_l_2133;
	case 8502ULL: goto x86_l_2136;
	case 8508ULL: goto x86_l_213c;
	case 8511ULL: goto x86_l_213f;
	case 8515ULL: goto x86_l_2143;
	case 8521ULL: goto x86_l_2149;
	case 8524ULL: goto x86_l_214c;
	case 8530ULL: goto x86_l_2152;
	case 8535ULL: goto x86_l_2157;
	case 8539ULL: goto x86_l_215b;
	case 8544ULL: goto x86_l_2160;
	case 8549ULL: goto x86_l_2165;
	case 8554ULL: goto x86_l_216a;
	case 8558ULL: goto x86_l_216e;
	case 8564ULL: goto x86_l_2174;
	case 8566ULL: goto x86_l_2176;
	case 8570ULL: goto x86_l_217a;
	case 8576ULL: goto x86_l_2180;
	case 8581ULL: goto x86_l_2185;
	case 8584ULL: goto x86_l_2188;
	case 8590ULL: goto x86_l_218e;
	case 8595ULL: goto x86_l_2193;
	case 8598ULL: goto x86_l_2196;
	case 8600ULL: goto x86_l_2198;
	case 8603ULL: goto x86_l_219b;
	case 8606ULL: goto x86_l_219e;
	case 8608ULL: goto x86_l_21a0;
	case 8612ULL: goto x86_l_21a4;
	case 8616ULL: goto x86_l_21a8;
	case 8622ULL: goto x86_l_21ae;
	case 8627ULL: goto x86_l_21b3;
	case 8630ULL: goto x86_l_21b6;
	case 8632ULL: goto x86_l_21b8;
	case 8635ULL: goto x86_l_21bb;
	case 8641ULL: goto x86_l_21c1;
	case 8644ULL: goto x86_l_21c4;
	case 8650ULL: goto x86_l_21ca;
	case 8656ULL: goto x86_l_21d0;
	case 8660ULL: goto x86_l_21d4;
	case 8666ULL: goto x86_l_21da;
	case 8670ULL: goto x86_l_21de;
	case 8676ULL: goto x86_l_21e4;
	case 8681ULL: goto x86_l_21e9;
	case 8684ULL: goto x86_l_21ec;
	case 8688ULL: goto x86_l_21f0;
	case 8694ULL: goto x86_l_21f6;
	case 8698ULL: goto x86_l_21fa;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	case 8712ULL: goto x86_l_2208;
	case 8718ULL: goto x86_l_220e;
	case 8724ULL: goto x86_l_2214;
	case 8728ULL: goto x86_l_2218;
	case 8734ULL: goto x86_l_221e;
	case 8738ULL: goto x86_l_2222;
	case 8744ULL: goto x86_l_2228;
	case 8749ULL: goto x86_l_222d;
	case 8752ULL: goto x86_l_2230;
	case 8758ULL: goto x86_l_2236;
	case 8761ULL: goto x86_l_2239;
	case 8767ULL: goto x86_l_223f;
	case 8772ULL: goto x86_l_2244;
	case 8774ULL: goto x86_l_2246;
	case 8780ULL: goto x86_l_224c;
	case 8785ULL: goto x86_l_2251;
	case 8788ULL: goto x86_l_2254;
	case 8794ULL: goto x86_l_225a;
	case 8797ULL: goto x86_l_225d;
	case 8803ULL: goto x86_l_2263;
	case 8808ULL: goto x86_l_2268;
	case 8810ULL: goto x86_l_226a;
	case 8816ULL: goto x86_l_2270;
	case 8821ULL: goto x86_l_2275;
	case 8826ULL: goto x86_l_227a;
	case 8830ULL: goto x86_l_227e;
	case 8835ULL: goto x86_l_2283;
	case 8840ULL: goto x86_l_2288;
	case 8842ULL: goto x86_l_228a;
	case 8847ULL: goto x86_l_228f;
	case 8849ULL: goto x86_l_2291;
	case 8854ULL: goto x86_l_2296;
	case 8856ULL: goto x86_l_2298;
	case 8859ULL: goto x86_l_229b;
	case 8864ULL: goto x86_l_22a0;
	case 8867ULL: goto x86_l_22a3;
	case 8873ULL: goto x86_l_22a9;
	case 8877ULL: goto x86_l_22ad;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	case 8894ULL: goto x86_l_22be;
	case 8901ULL: goto x86_l_22c5;
	case 8906ULL: goto x86_l_22ca;
	case 8909ULL: goto x86_l_22cd;
	case 8911ULL: goto x86_l_22cf;
	case 8914ULL: goto x86_l_22d2;
	case 8919ULL: goto x86_l_22d7;
	case 8926ULL: goto x86_l_22de;
	case 8929ULL: goto x86_l_22e1;
	case 8931ULL: goto x86_l_22e3;
	case 8936ULL: goto x86_l_22e8;
	case 8939ULL: goto x86_l_22eb;
	case 8945ULL: goto x86_l_22f1;
	case 8950ULL: goto x86_l_22f6;
	case 8953ULL: goto x86_l_22f9;
	case 8957ULL: goto x86_l_22fd;
	case 8962ULL: goto x86_l_2302;
	case 8967ULL: goto x86_l_2307;
	case 8973ULL: goto x86_l_230d;
	case 8981ULL: goto x86_l_2315;
	case 8986ULL: goto x86_l_231a;
	case 8990ULL: goto x86_l_231e;
	case 8997ULL: goto x86_l_2325;
	case 9000ULL: goto x86_l_2328;
	case 9002ULL: goto x86_l_232a;
	case 9007ULL: goto x86_l_232f;
	case 9010ULL: goto x86_l_2332;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9021ULL: goto x86_l_233d;
	case 9023ULL: goto x86_l_233f;
	case 9028ULL: goto x86_l_2344;
	case 9030ULL: goto x86_l_2346;
	case 9035ULL: goto x86_l_234b;
	case 9037ULL: goto x86_l_234d;
	case 9042ULL: goto x86_l_2352;
	case 9046ULL: goto x86_l_2356;
	case 9049ULL: goto x86_l_2359;
	case 9055ULL: goto x86_l_235f;
	case 9060ULL: goto x86_l_2364;
	case 9068ULL: goto x86_l_236c;
	case 9070ULL: goto x86_l_236e;
	case 9075ULL: goto x86_l_2373;
	case 9078ULL: goto x86_l_2376;
	case 9082ULL: goto x86_l_237a;
	case 9087ULL: goto x86_l_237f;
	case 9089ULL: goto x86_l_2381;
	case 9091ULL: goto x86_l_2383;
	case 9096ULL: goto x86_l_2388;
	case 9098ULL: goto x86_l_238a;
	case 9103ULL: goto x86_l_238f;
	case 9105ULL: goto x86_l_2391;
	case 9110ULL: goto x86_l_2396;
	case 9114ULL: goto x86_l_239a;
	case 9118ULL: goto x86_l_239e;
	case 9124ULL: goto x86_l_23a4;
	case 9129ULL: goto x86_l_23a9;
	case 9137ULL: goto x86_l_23b1;
	case 9139ULL: goto x86_l_23b3;
	case 9144ULL: goto x86_l_23b8;
	case 9147ULL: goto x86_l_23bb;
	case 9151ULL: goto x86_l_23bf;
	case 9156ULL: goto x86_l_23c4;
	case 9161ULL: goto x86_l_23c9;
	case 9163ULL: goto x86_l_23cb;
	case 9166ULL: goto x86_l_23ce;
	case 9172ULL: goto x86_l_23d4;
	case 9175ULL: goto x86_l_23d7;
	case 9181ULL: goto x86_l_23dd;
	case 9184ULL: goto x86_l_23e0;
	case 9190ULL: goto x86_l_23e6;
	case 9193ULL: goto x86_l_23e9;
	case 9199ULL: goto x86_l_23ef;
	case 9204ULL: goto x86_l_23f4;
	case 9209ULL: goto x86_l_23f9;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9224ULL: goto x86_l_2408;
	case 9230ULL: goto x86_l_240e;
	case 9233ULL: goto x86_l_2411;
	case 9239ULL: goto x86_l_2417;
	case 9242ULL: goto x86_l_241a;
	case 9248ULL: goto x86_l_2420;
	case 9251ULL: goto x86_l_2423;
	case 9257ULL: goto x86_l_2429;
	case 9262ULL: goto x86_l_242e;
	case 9267ULL: goto x86_l_2433;
	case 9274ULL: goto x86_l_243a;
	case 9279ULL: goto x86_l_243f;
	case 9284ULL: goto x86_l_2444;
	case 9288ULL: goto x86_l_2448;
	case 9293ULL: goto x86_l_244d;
	case 9298ULL: goto x86_l_2452;
	case 9301ULL: goto x86_l_2455;
	case 9305ULL: goto x86_l_2459;
	case 9307ULL: goto x86_l_245b;
	case 9311ULL: goto x86_l_245f;
	case 9314ULL: goto x86_l_2462;
	case 9317ULL: goto x86_l_2465;
	case 9320ULL: goto x86_l_2468;
	case 9326ULL: goto x86_l_246e;
	case 9331ULL: goto x86_l_2473;
	case 9336ULL: goto x86_l_2478;
	case 9339ULL: goto x86_l_247b;
	case 9345ULL: goto x86_l_2481;
	case 9351ULL: goto x86_l_2487;
	case 9355ULL: goto x86_l_248b;
	case 9361ULL: goto x86_l_2491;
	case 9364ULL: goto x86_l_2494;
	case 9368ULL: goto x86_l_2498;
	case 9370ULL: goto x86_l_249a;
	case 9374ULL: goto x86_l_249e;
	case 9379ULL: goto x86_l_24a3;
	case 9381ULL: goto x86_l_24a5;
	case 9386ULL: goto x86_l_24aa;
	case 9392ULL: goto x86_l_24b0;
	case 9394ULL: goto x86_l_24b2;
	case 9400ULL: goto x86_l_24b8;
	case 9402ULL: goto x86_l_24ba;
	case 9408ULL: goto x86_l_24c0;
	case 9411ULL: goto x86_l_24c3;
	case 9414ULL: goto x86_l_24c6;
	case 9419ULL: goto x86_l_24cb;
	case 9422ULL: goto x86_l_24ce;
	case 9428ULL: goto x86_l_24d4;
	case 9432ULL: goto x86_l_24d8;
	case 9437ULL: goto x86_l_24dd;
	case 9445ULL: goto x86_l_24e5;
	case 9450ULL: goto x86_l_24ea;
	case 9455ULL: goto x86_l_24ef;
	case 9460ULL: goto x86_l_24f4;
	case 9467ULL: goto x86_l_24fb;
	case 9472ULL: goto x86_l_2500;
	case 9475ULL: goto x86_l_2503;
	case 9477ULL: goto x86_l_2505;
	case 9480ULL: goto x86_l_2508;
	case 9485ULL: goto x86_l_250d;
	case 9492ULL: goto x86_l_2514;
	case 9495ULL: goto x86_l_2517;
	case 9497ULL: goto x86_l_2519;
	case 9500ULL: goto x86_l_251c;
	case 9506ULL: goto x86_l_2522;
	case 9511ULL: goto x86_l_2527;
	case 9514ULL: goto x86_l_252a;
	case 9518ULL: goto x86_l_252e;
	case 9523ULL: goto x86_l_2533;
	case 9528ULL: goto x86_l_2538;
	case 9534ULL: goto x86_l_253e;
	case 9537ULL: goto x86_l_2541;
	case 9540ULL: goto x86_l_2544;
	case 9543ULL: goto x86_l_2547;
	case 9547ULL: goto x86_l_254b;
	case 9555ULL: goto x86_l_2553;
	case 9557ULL: goto x86_l_2555;
	case 9560ULL: goto x86_l_2558;
	case 9568ULL: goto x86_l_2560;
	case 9570ULL: goto x86_l_2562;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9584ULL: goto x86_l_2570;
	case 9589ULL: goto x86_l_2575;
	case 9592ULL: goto x86_l_2578;
	case 9594ULL: goto x86_l_257a;
	case 9599ULL: goto x86_l_257f;
	case 9602ULL: goto x86_l_2582;
	case 9604ULL: goto x86_l_2584;
	case 9612ULL: goto x86_l_258c;
	case 9616ULL: goto x86_l_2590;
	case 9619ULL: goto x86_l_2593;
	case 9625ULL: goto x86_l_2599;
	case 9630ULL: goto x86_l_259e;
	case 9632ULL: goto x86_l_25a0;
	case 9637ULL: goto x86_l_25a5;
	case 9641ULL: goto x86_l_25a9;
	case 9645ULL: goto x86_l_25ad;
	case 9650ULL: goto x86_l_25b2;
	case 9655ULL: goto x86_l_25b7;
	case 9658ULL: goto x86_l_25ba;
	case 9660ULL: goto x86_l_25bc;
	case 9665ULL: goto x86_l_25c1;
	case 9668ULL: goto x86_l_25c4;
	case 9670ULL: goto x86_l_25c6;
	case 9678ULL: goto x86_l_25ce;
	case 9682ULL: goto x86_l_25d2;
	case 9686ULL: goto x86_l_25d6;
	case 9692ULL: goto x86_l_25dc;
	case 9697ULL: goto x86_l_25e1;
	case 9700ULL: goto x86_l_25e4;
	case 9702ULL: goto x86_l_25e6;
	case 9706ULL: goto x86_l_25ea;
	case 9710ULL: goto x86_l_25ee;
	case 9713ULL: goto x86_l_25f1;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9729ULL: goto x86_l_2601;
	case 9732ULL: goto x86_l_2604;
	case 9738ULL: goto x86_l_260a;
	case 9741ULL: goto x86_l_260d;
	case 9747ULL: goto x86_l_2613;
	case 9750ULL: goto x86_l_2616;
	case 9756ULL: goto x86_l_261c;
	case 9759ULL: goto x86_l_261f;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9782ULL: goto x86_l_2636;
	case 9787ULL: goto x86_l_263b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1fec:
	/* 0x1fec: je     2003 <generic_retkprobe_filter_arg+0x2003> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2003;
	}
x86_l_1fee:
	/* 0x1fee: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1ff2:
	/* 0x1ff2: ja     1fcf <generic_retkprobe_filter_arg+0x1fcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8143ULL;
	}
x86_l_1ff4:
	/* 0x1ff4: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1ff8:
	/* 0x1ff8: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1ffc:
	/* 0x1ffc: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1fff:
	/* 0x1fff: je     1fdc <generic_retkprobe_filter_arg+0x1fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8156ULL;
	}
x86_l_2001:
	/* 0x2001: jmp    1fcf <generic_retkprobe_filter_arg+0x1fcf> */
	return 8143ULL;
x86_l_2003:
	/* 0x2003: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2005:
	/* 0x2005: jns    2275 <generic_retkprobe_filter_arg+0x2275> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2275;
	}
x86_l_200b:
	/* 0x200b: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_200f:
	/* 0x200f: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_2014:
	/* 0x2014: jae    2027 <generic_retkprobe_filter_arg+0x2027> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2027;
	}
x86_l_2016:
	/* 0x2016: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_201a:
	/* 0x201a: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_201d:
	/* 0x201d: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_2021:
	/* 0x2021: jne    1f97 <generic_retkprobe_filter_arg+0x1f97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8087ULL;
	}
x86_l_2027:
	/* 0x2027: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2029:
	/* 0x2029: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_202d:
	/* 0x202d: jmp    357d <generic_retkprobe_filter_arg+0x357d> */
	return 13693ULL;
x86_l_2032:
	/* 0x2032: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2034:
	/* 0x2034: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2039:
	/* 0x2039: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_203e:
	/* 0x203e: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2042:
	/* 0x2042: jmp    357d <generic_retkprobe_filter_arg+0x357d> */
	return 13693ULL;
x86_l_2047:
	/* 0x2047: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_204a:
	/* 0x204a: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_204e:
	/* 0x204e: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2051:
	/* 0x2051: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2055:
	/* 0x2055: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2058:
	/* 0x2058: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_205b:
	/* 0x205b: cmp    esi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 41ULL);
x86_l_205e:
	/* 0x205e: jb     2de9 <generic_retkprobe_filter_arg+0x2de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11753ULL;
	}
x86_l_2064:
	/* 0x2064: mov    r8,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2069:
	/* 0x2069: mov    rdi,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_206e:
	/* 0x206e: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2071:
	/* 0x2071: je     207c <generic_retkprobe_filter_arg+0x207c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_207c;
	}
x86_l_2073:
	/* 0x2073: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2076:
	/* 0x2076: jne    2731 <generic_retkprobe_filter_arg+0x2731> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10033ULL;
	}
x86_l_207c:
	/* 0x207c: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_207f:
	/* 0x207f: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2083:
	/* 0x2083: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2086:
	/* 0x2086: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_208a:
	/* 0x208a: jmp    273f <generic_retkprobe_filter_arg+0x273f> */
	return 10047ULL;
x86_l_208f:
	/* 0x208f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2091:
	/* 0x2091: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2094:
	/* 0x2094: jne    209f <generic_retkprobe_filter_arg+0x209f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_209f;
	}
x86_l_2096:
	/* 0x2096: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2099:
	/* 0x2099: je     209f <generic_retkprobe_filter_arg+0x209f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_209f;
	}
x86_l_209b:
	/* 0x209b: movzx  ebx,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_209f:
	/* 0x209f: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_20a2:
	/* 0x20a2: je     20ad <generic_retkprobe_filter_arg+0x20ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20ad;
	}
x86_l_20a4:
	/* 0x20a4: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_20a7:
	/* 0x20a7: jne    24a3 <generic_retkprobe_filter_arg+0x24a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24a3;
	}
x86_l_20ad:
	/* 0x20ad: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_20b3:
	/* 0x20b3: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_20b7:
	/* 0x20b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20bc:
	/* 0x20bc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_20c3:
	/* 0x20c3: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_20c8:
	/* 0x20c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ca:
	/* 0x20ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20cd:
	/* 0x20cd: je     20e8 <generic_retkprobe_filter_arg+0x20e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e8;
	}
x86_l_20cf:
	/* 0x20cf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_20d2:
	/* 0x20d2: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_20d4:
	/* 0x20d4: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_20d9:
	/* 0x20d9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20de:
	/* 0x20de: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20e3:
	/* 0x20e3: jmp    1b7e <generic_retkprobe_filter_arg+0x1b7e> */
	return 7038ULL;
x86_l_20e8:
	/* 0x20e8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20ea:
	/* 0x20ea: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ee:
	/* 0x20ee: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20f3:
	/* 0x20f3: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20f8:
	/* 0x20f8: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_20fd:
	/* 0x20fd: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20ff:
	/* 0x20ff: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2104:
	/* 0x2104: jmp    2444 <generic_retkprobe_filter_arg+0x2444> */
	goto x86_l_2444;
x86_l_2109:
	/* 0x2109: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_210c:
	/* 0x210c: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2110:
	/* 0x2110: ja     211b <generic_retkprobe_filter_arg+0x211b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_211b;
	}
x86_l_2112:
	/* 0x2112: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_2115:
	/* 0x2115: jbe    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 620ULL;
	}
x86_l_211b:
	/* 0x211b: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_211e:
	/* 0x211e: jb     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 187ULL;
	}
x86_l_2124:
	/* 0x2124: mov    rdi,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2129:
	/* 0x2129: mov    rsi,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_212e:
	/* 0x212e: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2131:
	/* 0x2131: je     213c <generic_retkprobe_filter_arg+0x213c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_213c;
	}
x86_l_2133:
	/* 0x2133: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2136:
	/* 0x2136: jne    2774 <generic_retkprobe_filter_arg+0x2774> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10100ULL;
	}
x86_l_213c:
	/* 0x213c: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_213f:
	/* 0x213f: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2143:
	/* 0x2143: jg     2786 <generic_retkprobe_filter_arg+0x2786> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10118ULL;
	}
x86_l_2149:
	/* 0x2149: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_214c:
	/* 0x214c: jle    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 620ULL;
	}
x86_l_2152:
	/* 0x2152: jmp    2786 <generic_retkprobe_filter_arg+0x2786> */
	return 10118ULL;
x86_l_2157:
	/* 0x2157: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_215b:
	/* 0x215b: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2160:
	/* 0x2160: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2165:
	/* 0x2165: jmp    1bc0 <generic_retkprobe_filter_arg+0x1bc0> */
	return 7104ULL;
x86_l_216a:
	/* 0x216a: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_216e:
	/* 0x216e: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_2174:
	/* 0x2174: jmp    2180 <generic_retkprobe_filter_arg+0x2180> */
	goto x86_l_2180;
x86_l_2176:
	/* 0x2176: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_217a:
	/* 0x217a: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_2180:
	/* 0x2180: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2185:
	/* 0x2185: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2188:
	/* 0x2188: jb     35dc <generic_retkprobe_filter_arg+0x35dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13788ULL;
	}
x86_l_218e:
	/* 0x218e: mov    esi,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2193:
	/* 0x2193: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2196:
	/* 0x2196: jle    21b3 <generic_retkprobe_filter_arg+0x21b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_21b3;
	}
x86_l_2198:
	/* 0x2198: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_219b:
	/* 0x219b: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_219e:
	/* 0x219e: jae    21e9 <generic_retkprobe_filter_arg+0x21e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_21e9;
	}
x86_l_21a0:
	/* 0x21a0: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21a4:
	/* 0x21a4: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21a8:
	/* 0x21a8: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 595ULL;
	}
x86_l_21ae:
	/* 0x21ae: jmp    2c66 <generic_retkprobe_filter_arg+0x2c66> */
	return 11366ULL;
x86_l_21b3:
	/* 0x21b3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21b6:
	/* 0x21b6: je     2205 <generic_retkprobe_filter_arg+0x2205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2205;
	}
x86_l_21b8:
	/* 0x21b8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21bb:
	/* 0x21bb: jne    2c66 <generic_retkprobe_filter_arg+0x2c66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11366ULL;
	}
x86_l_21c1:
	/* 0x21c1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_21c4:
	/* 0x21c4: ja     2c5c <generic_retkprobe_filter_arg+0x2c5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11356ULL;
	}
x86_l_21ca:
	/* 0x21ca: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_21d0:
	/* 0x21d0: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_21d4:
	/* 0x21d4: jae    2c5c <generic_retkprobe_filter_arg+0x2c5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11356ULL;
	}
x86_l_21da:
	/* 0x21da: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21de:
	/* 0x21de: jl     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 620ULL;
	}
x86_l_21e4:
	/* 0x21e4: jmp    2c66 <generic_retkprobe_filter_arg+0x2c66> */
	return 11366ULL;
x86_l_21e9:
	/* 0x21e9: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_21ec:
	/* 0x21ec: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21f0:
	/* 0x21f0: jne    2c66 <generic_retkprobe_filter_arg+0x2c66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11366ULL;
	}
x86_l_21f6:
	/* 0x21f6: test   DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21fa:
	/* 0x21fa: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_2200:
	/* 0x2200: jmp    2c66 <generic_retkprobe_filter_arg+0x2c66> */
	return 11366ULL;
x86_l_2205:
	/* 0x2205: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2208:
	/* 0x2208: ja     2c50 <generic_retkprobe_filter_arg+0x2c50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11344ULL;
	}
x86_l_220e:
	/* 0x220e: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2214:
	/* 0x2214: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2218:
	/* 0x2218: jae    2c50 <generic_retkprobe_filter_arg+0x2c50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11344ULL;
	}
x86_l_221e:
	/* 0x221e: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2222:
	/* 0x2222: jg     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 620ULL;
	}
x86_l_2228:
	/* 0x2228: jmp    2c66 <generic_retkprobe_filter_arg+0x2c66> */
	return 11366ULL;
x86_l_222d:
	/* 0x222d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2230:
	/* 0x2230: je     2acb <generic_retkprobe_filter_arg+0x2acb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10955ULL;
	}
x86_l_2236:
	/* 0x2236: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2239:
	/* 0x2239: jne    2ad8 <generic_retkprobe_filter_arg+0x2ad8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10968ULL;
	}
x86_l_223f:
	/* 0x223f: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2244:
	/* 0x2244: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2246:
	/* 0x2246: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_224c:
	/* 0x224c: jmp    2ad8 <generic_retkprobe_filter_arg+0x2ad8> */
	return 10968ULL;
x86_l_2251:
	/* 0x2251: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2254:
	/* 0x2254: je     2b0d <generic_retkprobe_filter_arg+0x2b0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11021ULL;
	}
x86_l_225a:
	/* 0x225a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_225d:
	/* 0x225d: jne    2b1a <generic_retkprobe_filter_arg+0x2b1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11034ULL;
	}
x86_l_2263:
	/* 0x2263: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2268:
	/* 0x2268: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_226a:
	/* 0x226a: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_2270:
	/* 0x2270: jmp    2b1a <generic_retkprobe_filter_arg+0x2b1a> */
	return 11034ULL;
x86_l_2275:
	/* 0x2275: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_227a:
	/* 0x227a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_227e:
	/* 0x227e: jmp    357d <generic_retkprobe_filter_arg+0x357d> */
	return 13693ULL;
x86_l_2283:
	/* 0x2283: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2288:
	/* 0x2288: jmp    2296 <generic_retkprobe_filter_arg+0x2296> */
	goto x86_l_2296;
x86_l_228a:
	/* 0x228a: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_228f:
	/* 0x228f: jmp    2296 <generic_retkprobe_filter_arg+0x2296> */
	goto x86_l_2296;
x86_l_2291:
	/* 0x2291: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2296:
	/* 0x2296: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2298:
	/* 0x2298: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_229b:
	/* 0x229b: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_22a0:
	/* 0x22a0: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_22a3:
	/* 0x22a3: je     31d1 <generic_retkprobe_filter_arg+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12753ULL;
	}
x86_l_22a9:
	/* 0x22a9: mov    DWORD PTR [rsp+0x64],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_22ad:
	/* 0x22ad: mov    DWORD PTR [rsp+0x88],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_22b4:
	/* 0x22b4: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_22b9:
	/* 0x22b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22be:
	/* 0x22be: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_22c5:
	/* 0x22c5: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22ca:
	/* 0x22ca: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_22cd:
	/* 0x22cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22cf:
	/* 0x22cf: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_22d2:
	/* 0x22d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22d7:
	/* 0x22d7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_22de:
	/* 0x22de: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_22e1:
	/* 0x22e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e3:
	/* 0x22e3: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22e8:
	/* 0x22e8: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_22eb:
	/* 0x22eb: je     31d1 <generic_retkprobe_filter_arg+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12753ULL;
	}
x86_l_22f1:
	/* 0x22f1: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_22f6:
	/* 0x22f6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22f9:
	/* 0x22f9: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22fd:
	/* 0x22fd: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2302:
	/* 0x2302: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2307:
	/* 0x2307: je     31e1 <generic_retkprobe_filter_arg+0x31e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12769ULL;
	}
x86_l_230d:
	/* 0x230d: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2315:
	/* 0x2315: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_231a:
	/* 0x231a: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_231e:
	/* 0x231e: mov    ebx,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2325:
	/* 0x2325: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2328:
	/* 0x2328: jg     236e <generic_retkprobe_filter_arg+0x236e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_236e;
	}
x86_l_232a:
	/* 0x232a: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_232f:
	/* 0x232f: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2332:
	/* 0x2332: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2336:
	/* 0x2336: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_233b:
	/* 0x233b: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_233d:
	/* 0x233d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_233f:
	/* 0x233f: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2344:
	/* 0x2344: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2346:
	/* 0x2346: mov    r13d,DWORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_234b:
	/* 0x234b: jbe    23b3 <generic_retkprobe_filter_arg+0x23b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_23b3;
	}
x86_l_234d:
	/* 0x234d: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2352:
	/* 0x2352: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2356:
	/* 0x2356: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2359:
	/* 0x2359: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_235f:
	/* 0x235f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2364:
	/* 0x2364: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_236c:
	/* 0x236c: jmp    23b1 <generic_retkprobe_filter_arg+0x23b1> */
	goto x86_l_23b1;
x86_l_236e:
	/* 0x236e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2373:
	/* 0x2373: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2376:
	/* 0x2376: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_237a:
	/* 0x237a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_237f:
	/* 0x237f: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2381:
	/* 0x2381: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2383:
	/* 0x2383: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2388:
	/* 0x2388: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_238a:
	/* 0x238a: mov    r13d,DWORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_238f:
	/* 0x238f: jbe    23b3 <generic_retkprobe_filter_arg+0x23b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_23b3;
	}
x86_l_2391:
	/* 0x2391: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2396:
	/* 0x2396: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_239a:
	/* 0x239a: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_239e:
	/* 0x239e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23a4:
	/* 0x23a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23a9:
	/* 0x23a9: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_23b1:
	/* 0x23b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b3:
	/* 0x23b3: mov    DWORD PTR [rsp+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23b8:
	/* 0x23b8: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_23bb:
	/* 0x23bb: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23bf:
	/* 0x23bf: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23c4:
	/* 0x23c4: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23c9:
	/* 0x23c9: jle    2405 <generic_retkprobe_filter_arg+0x2405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2405;
	}
x86_l_23cb:
	/* 0x23cb: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_23ce:
	/* 0x23ce: jg     2883 <generic_retkprobe_filter_arg+0x2883> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10371ULL;
	}
x86_l_23d4:
	/* 0x23d4: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_23d7:
	/* 0x23d7: je     2f1f <generic_retkprobe_filter_arg+0x2f1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12063ULL;
	}
x86_l_23dd:
	/* 0x23dd: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_23e0:
	/* 0x23e0: je     2ee6 <generic_retkprobe_filter_arg+0x2ee6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12006ULL;
	}
x86_l_23e6:
	/* 0x23e6: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_23e9:
	/* 0x23e9: jne    903 <generic_retkprobe_filter_arg+0x903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2307ULL;
	}
x86_l_23ef:
	/* 0x23ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23f4:
	/* 0x23f4: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23f9:
	/* 0x23f9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2400:
	/* 0x2400: jmp    2f43 <generic_retkprobe_filter_arg+0x2f43> */
	return 12099ULL;
x86_l_2405:
	/* 0x2405: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2408:
	/* 0x2408: jle    2b4f <generic_retkprobe_filter_arg+0x2b4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11087ULL;
	}
x86_l_240e:
	/* 0x240e: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_2411:
	/* 0x2411: je     2f0c <generic_retkprobe_filter_arg+0x2f0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12044ULL;
	}
x86_l_2417:
	/* 0x2417: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_241a:
	/* 0x241a: je     2ed3 <generic_retkprobe_filter_arg+0x2ed3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11987ULL;
	}
x86_l_2420:
	/* 0x2420: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2423:
	/* 0x2423: jne    903 <generic_retkprobe_filter_arg+0x903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2307ULL;
	}
x86_l_2429:
	/* 0x2429: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_242e:
	/* 0x242e: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2433:
	/* 0x2433: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_243a:
	/* 0x243a: jmp    2f43 <generic_retkprobe_filter_arg+0x2f43> */
	return 12099ULL;
x86_l_243f:
	/* 0x243f: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2444:
	/* 0x2444: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2448:
	/* 0x2448: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_244d:
	/* 0x244d: jmp    357d <generic_retkprobe_filter_arg+0x357d> */
	return 13693ULL;
x86_l_2452:
	/* 0x2452: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2455:
	/* 0x2455: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2459:
	/* 0x2459: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_245b:
	/* 0x245b: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_245f:
	/* 0x245f: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2462:
	/* 0x2462: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2465:
	/* 0x2465: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_2468:
	/* 0x2468: jb     2de9 <generic_retkprobe_filter_arg+0x2de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11753ULL;
	}
x86_l_246e:
	/* 0x246e: mov    r8d,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2473:
	/* 0x2473: mov    edi,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2478:
	/* 0x2478: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_247b:
	/* 0x247b: ja     2ba7 <generic_retkprobe_filter_arg+0x2ba7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11175ULL;
	}
x86_l_2481:
	/* 0x2481: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_2487:
	/* 0x2487: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_248b:
	/* 0x248b: jae    2ba7 <generic_retkprobe_filter_arg+0x2ba7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11175ULL;
	}
x86_l_2491:
	/* 0x2491: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2494:
	/* 0x2494: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2498:
	/* 0x2498: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_249a:
	/* 0x249a: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_249e:
	/* 0x249e: jmp    2bb4 <generic_retkprobe_filter_arg+0x2bb4> */
	return 11188ULL;
x86_l_24a3:
	/* 0x24a3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24a5:
	/* 0x24a5: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_24aa:
	/* 0x24aa: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_24b0:
	/* 0x24b0: jmp    24c0 <generic_retkprobe_filter_arg+0x24c0> */
	goto x86_l_24c0;
x86_l_24b2:
	/* 0x24b2: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_24b8:
	/* 0x24b8: jmp    24c0 <generic_retkprobe_filter_arg+0x24c0> */
	goto x86_l_24c0;
x86_l_24ba:
	/* 0x24ba: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_24c0:
	/* 0x24c0: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_24c3:
	/* 0x24c3: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_24c6:
	/* 0x24c6: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_24cb:
	/* 0x24cb: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_24ce:
	/* 0x24ce: je     2d3f <generic_retkprobe_filter_arg+0x2d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11583ULL;
	}
x86_l_24d4:
	/* 0x24d4: mov    DWORD PTR [rsp+0x64],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_24d8:
	/* 0x24d8: mov    QWORD PTR [rsp+0x68],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_24dd:
	/* 0x24dd: mov    BYTE PTR [rsp+0x88],r8b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_24e5:
	/* 0x24e5: mov    QWORD PTR [rsp+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24ea:
	/* 0x24ea: mov    QWORD PTR [rsp+0x20],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24ef:
	/* 0x24ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24f4:
	/* 0x24f4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_24fb:
	/* 0x24fb: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2500:
	/* 0x2500: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2503:
	/* 0x2503: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2505:
	/* 0x2505: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2508:
	/* 0x2508: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_250d:
	/* 0x250d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2514:
	/* 0x2514: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2517:
	/* 0x2517: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2519:
	/* 0x2519: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_251c:
	/* 0x251c: je     31d1 <generic_retkprobe_filter_arg+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12753ULL;
	}
x86_l_2522:
	/* 0x2522: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_2527:
	/* 0x2527: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_252a:
	/* 0x252a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_252e:
	/* 0x252e: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2533:
	/* 0x2533: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2538:
	/* 0x2538: je     31e1 <generic_retkprobe_filter_arg+0x31e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12769ULL;
	}
x86_l_253e:
	/* 0x253e: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2541:
	/* 0x2541: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2544:
	/* 0x2544: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_2547:
	/* 0x2547: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_254b:
	/* 0x254b: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2553:
	/* 0x2553: jg     25a0 <generic_retkprobe_filter_arg+0x25a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_25a0;
	}
x86_l_2555:
	/* 0x2555: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2558:
	/* 0x2558: movzx  ecx,BYTE PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 136ULL);
x86_l_2560:
	/* 0x2560: mov    BYTE PTR [rax],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2562:
	/* 0x2562: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2566:
	/* 0x2566: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_256b:
	/* 0x256b: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2570:
	/* 0x2570: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2575:
	/* 0x2575: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_2578:
	/* 0x2578: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_257a:
	/* 0x257a: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_257f:
	/* 0x257f: sub    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2582:
	/* 0x2582: jbe    25e6 <generic_retkprobe_filter_arg+0x25e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_25e6;
	}
x86_l_2584:
	/* 0x2584: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_258c:
	/* 0x258c: lea    rdi,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2590:
	/* 0x2590: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2593:
	/* 0x2593: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2599:
	/* 0x2599: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_259e:
	/* 0x259e: jmp    25e1 <generic_retkprobe_filter_arg+0x25e1> */
	goto x86_l_25e1;
x86_l_25a0:
	/* 0x25a0: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25a5:
	/* 0x25a5: mov    WORD PTR [rcx],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25a9:
	/* 0x25a9: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_25ad:
	/* 0x25ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25b2:
	/* 0x25b2: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25b7:
	/* 0x25b7: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_25ba:
	/* 0x25ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25bc:
	/* 0x25bc: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25c1:
	/* 0x25c1: sub    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25c4:
	/* 0x25c4: jbe    25e6 <generic_retkprobe_filter_arg+0x25e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_25e6;
	}
x86_l_25c6:
	/* 0x25c6: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_25ce:
	/* 0x25ce: lea    rdi,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_25d2:
	/* 0x25d2: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_25d6:
	/* 0x25d6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25dc:
	/* 0x25dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25e1:
	/* 0x25e1: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_25e4:
	/* 0x25e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25e6:
	/* 0x25e6: mov    eax,DWORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_25ea:
	/* 0x25ea: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25ee:
	/* 0x25ee: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_25f1:
	/* 0x25f1: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25f5:
	/* 0x25f5: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25fa:
	/* 0x25fa: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25ff:
	/* 0x25ff: jle    263b <generic_retkprobe_filter_arg+0x263b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_263b;
	}
x86_l_2601:
	/* 0x2601: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_2604:
	/* 0x2604: jg     2a7e <generic_retkprobe_filter_arg+0x2a7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10878ULL;
	}
x86_l_260a:
	/* 0x260a: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_260d:
	/* 0x260d: je     318a <generic_retkprobe_filter_arg+0x318a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12682ULL;
	}
x86_l_2613:
	/* 0x2613: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2616:
	/* 0x2616: je     3151 <generic_retkprobe_filter_arg+0x3151> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12625ULL;
	}
x86_l_261c:
	/* 0x261c: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_261f:
	/* 0x261f: jne    2d3f <generic_retkprobe_filter_arg+0x2d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11583ULL;
	}
x86_l_2625:
	/* 0x2625: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_262a:
	/* 0x262a: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_262f:
	/* 0x262f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2636:
	/* 0x2636: jmp    31ae <generic_retkprobe_filter_arg+0x31ae> */
	return 12718ULL;
x86_l_263b:
	/* 0x263b: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
	return 9790ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9790ULL: goto x86_l_263e;
	case 9796ULL: goto x86_l_2644;
	case 9799ULL: goto x86_l_2647;
	case 9805ULL: goto x86_l_264d;
	case 9808ULL: goto x86_l_2650;
	case 9814ULL: goto x86_l_2656;
	case 9817ULL: goto x86_l_2659;
	case 9823ULL: goto x86_l_265f;
	case 9828ULL: goto x86_l_2664;
	case 9833ULL: goto x86_l_2669;
	case 9840ULL: goto x86_l_2670;
	case 9845ULL: goto x86_l_2675;
	case 9847ULL: goto x86_l_2677;
	case 9851ULL: goto x86_l_267b;
	case 9853ULL: goto x86_l_267d;
	case 9855ULL: goto x86_l_267f;
	case 9861ULL: goto x86_l_2685;
	case 9864ULL: goto x86_l_2688;
	case 9870ULL: goto x86_l_268e;
	case 9875ULL: goto x86_l_2693;
	case 9880ULL: goto x86_l_2698;
	case 9883ULL: goto x86_l_269b;
	case 9889ULL: goto x86_l_26a1;
	case 9895ULL: goto x86_l_26a7;
	case 9899ULL: goto x86_l_26ab;
	case 9905ULL: goto x86_l_26b1;
	case 9907ULL: goto x86_l_26b3;
	case 9911ULL: goto x86_l_26b7;
	case 9917ULL: goto x86_l_26bd;
	case 9919ULL: goto x86_l_26bf;
	case 9925ULL: goto x86_l_26c5;
	case 9930ULL: goto x86_l_26ca;
	case 9935ULL: goto x86_l_26cf;
	case 9940ULL: goto x86_l_26d4;
	case 9942ULL: goto x86_l_26d6;
	case 9947ULL: goto x86_l_26db;
	case 9952ULL: goto x86_l_26e0;
	case 9954ULL: goto x86_l_26e2;
	case 9959ULL: goto x86_l_26e7;
	case 9964ULL: goto x86_l_26ec;
	case 9966ULL: goto x86_l_26ee;
	case 9968ULL: goto x86_l_26f0;
	case 9973ULL: goto x86_l_26f5;
	case 9976ULL: goto x86_l_26f8;
	case 9979ULL: goto x86_l_26fb;
	case 9985ULL: goto x86_l_2701;
	case 9991ULL: goto x86_l_2707;
	case 9997ULL: goto x86_l_270d;
	case 10000ULL: goto x86_l_2710;
	case 10006ULL: goto x86_l_2716;
	case 10008ULL: goto x86_l_2718;
	case 10014ULL: goto x86_l_271e;
	case 10017ULL: goto x86_l_2721;
	case 10023ULL: goto x86_l_2727;
	case 10028ULL: goto x86_l_272c;
	case 10033ULL: goto x86_l_2731;
	case 10036ULL: goto x86_l_2734;
	case 10040ULL: goto x86_l_2738;
	case 10043ULL: goto x86_l_273b;
	case 10047ULL: goto x86_l_273f;
	case 10050ULL: goto x86_l_2742;
	case 10053ULL: goto x86_l_2745;
	case 10056ULL: goto x86_l_2748;
	case 10062ULL: goto x86_l_274e;
	case 10067ULL: goto x86_l_2753;
	case 10072ULL: goto x86_l_2758;
	case 10075ULL: goto x86_l_275b;
	case 10077ULL: goto x86_l_275d;
	case 10080ULL: goto x86_l_2760;
	case 10086ULL: goto x86_l_2766;
	case 10089ULL: goto x86_l_2769;
	case 10092ULL: goto x86_l_276c;
	case 10095ULL: goto x86_l_276f;
	case 10100ULL: goto x86_l_2774;
	case 10103ULL: goto x86_l_2777;
	case 10107ULL: goto x86_l_277b;
	case 10109ULL: goto x86_l_277d;
	case 10112ULL: goto x86_l_2780;
	case 10118ULL: goto x86_l_2786;
	case 10121ULL: goto x86_l_2789;
	case 10127ULL: goto x86_l_278f;
	case 10132ULL: goto x86_l_2794;
	case 10137ULL: goto x86_l_2799;
	case 10140ULL: goto x86_l_279c;
	case 10142ULL: goto x86_l_279e;
	case 10145ULL: goto x86_l_27a1;
	case 10151ULL: goto x86_l_27a7;
	case 10154ULL: goto x86_l_27aa;
	case 10160ULL: goto x86_l_27b0;
	case 10163ULL: goto x86_l_27b3;
	case 10169ULL: goto x86_l_27b9;
	case 10174ULL: goto x86_l_27be;
	case 10178ULL: goto x86_l_27c2;
	case 10184ULL: goto x86_l_27c8;
	case 10186ULL: goto x86_l_27ca;
	case 10190ULL: goto x86_l_27ce;
	case 10196ULL: goto x86_l_27d4;
	case 10199ULL: goto x86_l_27d7;
	case 10205ULL: goto x86_l_27dd;
	case 10210ULL: goto x86_l_27e2;
	case 10213ULL: goto x86_l_27e5;
	case 10215ULL: goto x86_l_27e7;
	case 10218ULL: goto x86_l_27ea;
	case 10221ULL: goto x86_l_27ed;
	case 10223ULL: goto x86_l_27ef;
	case 10227ULL: goto x86_l_27f3;
	case 10231ULL: goto x86_l_27f7;
	case 10237ULL: goto x86_l_27fd;
	case 10242ULL: goto x86_l_2802;
	case 10245ULL: goto x86_l_2805;
	case 10251ULL: goto x86_l_280b;
	case 10254ULL: goto x86_l_280e;
	case 10260ULL: goto x86_l_2814;
	case 10263ULL: goto x86_l_2817;
	case 10265ULL: goto x86_l_2819;
	case 10268ULL: goto x86_l_281c;
	case 10274ULL: goto x86_l_2822;
	case 10278ULL: goto x86_l_2826;
	case 10284ULL: goto x86_l_282c;
	case 10289ULL: goto x86_l_2831;
	case 10292ULL: goto x86_l_2834;
	case 10296ULL: goto x86_l_2838;
	case 10302ULL: goto x86_l_283e;
	case 10306ULL: goto x86_l_2842;
	case 10312ULL: goto x86_l_2848;
	case 10317ULL: goto x86_l_284d;
	case 10320ULL: goto x86_l_2850;
	case 10326ULL: goto x86_l_2856;
	case 10331ULL: goto x86_l_285b;
	case 10333ULL: goto x86_l_285d;
	case 10339ULL: goto x86_l_2863;
	case 10344ULL: goto x86_l_2868;
	case 10347ULL: goto x86_l_286b;
	case 10353ULL: goto x86_l_2871;
	case 10358ULL: goto x86_l_2876;
	case 10360ULL: goto x86_l_2878;
	case 10366ULL: goto x86_l_287e;
	case 10371ULL: goto x86_l_2883;
	case 10374ULL: goto x86_l_2886;
	case 10380ULL: goto x86_l_288c;
	case 10383ULL: goto x86_l_288f;
	case 10389ULL: goto x86_l_2895;
	case 10392ULL: goto x86_l_2898;
	case 10398ULL: goto x86_l_289e;
	case 10403ULL: goto x86_l_28a3;
	case 10408ULL: goto x86_l_28a8;
	case 10415ULL: goto x86_l_28af;
	case 10420ULL: goto x86_l_28b4;
	case 10425ULL: goto x86_l_28b9;
	case 10427ULL: goto x86_l_28bb;
	case 10432ULL: goto x86_l_28c0;
	case 10434ULL: goto x86_l_28c2;
	case 10439ULL: goto x86_l_28c7;
	case 10441ULL: goto x86_l_28c9;
	case 10444ULL: goto x86_l_28cc;
	case 10449ULL: goto x86_l_28d1;
	case 10452ULL: goto x86_l_28d4;
	case 10458ULL: goto x86_l_28da;
	case 10462ULL: goto x86_l_28de;
	case 10466ULL: goto x86_l_28e2;
	case 10474ULL: goto x86_l_28ea;
	case 10479ULL: goto x86_l_28ef;
	case 10486ULL: goto x86_l_28f6;
	case 10491ULL: goto x86_l_28fb;
	case 10494ULL: goto x86_l_28fe;
	case 10496ULL: goto x86_l_2900;
	case 10499ULL: goto x86_l_2903;
	case 10504ULL: goto x86_l_2908;
	case 10511ULL: goto x86_l_290f;
	case 10514ULL: goto x86_l_2912;
	case 10516ULL: goto x86_l_2914;
	case 10521ULL: goto x86_l_2919;
	case 10524ULL: goto x86_l_291c;
	case 10530ULL: goto x86_l_2922;
	case 10535ULL: goto x86_l_2927;
	case 10538ULL: goto x86_l_292a;
	case 10542ULL: goto x86_l_292e;
	case 10547ULL: goto x86_l_2933;
	case 10552ULL: goto x86_l_2938;
	case 10558ULL: goto x86_l_293e;
	case 10561ULL: goto x86_l_2941;
	case 10565ULL: goto x86_l_2945;
	case 10568ULL: goto x86_l_2948;
	case 10570ULL: goto x86_l_294a;
	case 10575ULL: goto x86_l_294f;
	case 10578ULL: goto x86_l_2952;
	case 10582ULL: goto x86_l_2956;
	case 10587ULL: goto x86_l_295b;
	case 10592ULL: goto x86_l_2960;
	case 10594ULL: goto x86_l_2962;
	case 10596ULL: goto x86_l_2964;
	case 10604ULL: goto x86_l_296c;
	case 10606ULL: goto x86_l_296e;
	case 10608ULL: goto x86_l_2970;
	case 10613ULL: goto x86_l_2975;
	case 10617ULL: goto x86_l_2979;
	case 10620ULL: goto x86_l_297c;
	case 10626ULL: goto x86_l_2982;
	case 10631ULL: goto x86_l_2987;
	case 10634ULL: goto x86_l_298a;
	case 10636ULL: goto x86_l_298c;
	case 10638ULL: goto x86_l_298e;
	case 10643ULL: goto x86_l_2993;
	case 10648ULL: goto x86_l_2998;
	case 10651ULL: goto x86_l_299b;
	case 10655ULL: goto x86_l_299f;
	case 10660ULL: goto x86_l_29a4;
	case 10665ULL: goto x86_l_29a9;
	case 10667ULL: goto x86_l_29ab;
	case 10669ULL: goto x86_l_29ad;
	case 10677ULL: goto x86_l_29b5;
	case 10679ULL: goto x86_l_29b7;
	case 10681ULL: goto x86_l_29b9;
	case 10686ULL: goto x86_l_29be;
	case 10690ULL: goto x86_l_29c2;
	case 10694ULL: goto x86_l_29c6;
	case 10700ULL: goto x86_l_29cc;
	case 10705ULL: goto x86_l_29d1;
	case 10708ULL: goto x86_l_29d4;
	case 10710ULL: goto x86_l_29d6;
	case 10714ULL: goto x86_l_29da;
	case 10718ULL: goto x86_l_29de;
	case 10721ULL: goto x86_l_29e1;
	case 10726ULL: goto x86_l_29e6;
	case 10731ULL: goto x86_l_29eb;
	case 10733ULL: goto x86_l_29ed;
	case 10736ULL: goto x86_l_29f0;
	case 10742ULL: goto x86_l_29f6;
	case 10745ULL: goto x86_l_29f9;
	case 10751ULL: goto x86_l_29ff;
	case 10754ULL: goto x86_l_2a02;
	case 10760ULL: goto x86_l_2a08;
	case 10763ULL: goto x86_l_2a0b;
	case 10769ULL: goto x86_l_2a11;
	case 10774ULL: goto x86_l_2a16;
	case 10779ULL: goto x86_l_2a1b;
	case 10786ULL: goto x86_l_2a22;
	case 10791ULL: goto x86_l_2a27;
	case 10794ULL: goto x86_l_2a2a;
	case 10800ULL: goto x86_l_2a30;
	case 10803ULL: goto x86_l_2a33;
	case 10809ULL: goto x86_l_2a39;
	case 10812ULL: goto x86_l_2a3c;
	case 10818ULL: goto x86_l_2a42;
	case 10821ULL: goto x86_l_2a45;
	case 10827ULL: goto x86_l_2a4b;
	case 10832ULL: goto x86_l_2a50;
	case 10837ULL: goto x86_l_2a55;
	case 10844ULL: goto x86_l_2a5c;
	case 10849ULL: goto x86_l_2a61;
	case 10852ULL: goto x86_l_2a64;
	case 10854ULL: goto x86_l_2a66;
	case 10857ULL: goto x86_l_2a69;
	case 10863ULL: goto x86_l_2a6f;
	case 10867ULL: goto x86_l_2a73;
	case 10873ULL: goto x86_l_2a79;
	case 10878ULL: goto x86_l_2a7e;
	case 10881ULL: goto x86_l_2a81;
	case 10887ULL: goto x86_l_2a87;
	case 10890ULL: goto x86_l_2a8a;
	case 10896ULL: goto x86_l_2a90;
	case 10899ULL: goto x86_l_2a93;
	case 10905ULL: goto x86_l_2a99;
	case 10910ULL: goto x86_l_2a9e;
	case 10915ULL: goto x86_l_2aa3;
	case 10922ULL: goto x86_l_2aaa;
	case 10927ULL: goto x86_l_2aaf;
	case 10930ULL: goto x86_l_2ab2;
	case 10936ULL: goto x86_l_2ab8;
	case 10939ULL: goto x86_l_2abb;
	case 10945ULL: goto x86_l_2ac1;
	case 10950ULL: goto x86_l_2ac6;
	case 10955ULL: goto x86_l_2acb;
	case 10960ULL: goto x86_l_2ad0;
	case 10962ULL: goto x86_l_2ad2;
	case 10968ULL: goto x86_l_2ad8;
	case 10971ULL: goto x86_l_2adb;
	case 10977ULL: goto x86_l_2ae1;
	case 10982ULL: goto x86_l_2ae6;
	case 10985ULL: goto x86_l_2ae9;
	case 10991ULL: goto x86_l_2aef;
	case 10994ULL: goto x86_l_2af2;
	case 10997ULL: goto x86_l_2af5;
	case 11003ULL: goto x86_l_2afb;
	case 11008ULL: goto x86_l_2b00;
	case 11010ULL: goto x86_l_2b02;
	case 11016ULL: goto x86_l_2b08;
	case 11021ULL: goto x86_l_2b0d;
	case 11026ULL: goto x86_l_2b12;
	case 11028ULL: goto x86_l_2b14;
	case 11034ULL: goto x86_l_2b1a;
	case 11037ULL: goto x86_l_2b1d;
	case 11043ULL: goto x86_l_2b23;
	case 11048ULL: goto x86_l_2b28;
	case 11051ULL: goto x86_l_2b2b;
	case 11057ULL: goto x86_l_2b31;
	case 11060ULL: goto x86_l_2b34;
	case 11063ULL: goto x86_l_2b37;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11076ULL: goto x86_l_2b44;
	case 11082ULL: goto x86_l_2b4a;
	case 11087ULL: goto x86_l_2b4f;
	case 11089ULL: goto x86_l_2b51;
	case 11095ULL: goto x86_l_2b57;
	case 11098ULL: goto x86_l_2b5a;
	case 11104ULL: goto x86_l_2b60;
	case 11109ULL: goto x86_l_2b65;
	case 11114ULL: goto x86_l_2b6a;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11129ULL: goto x86_l_2b79;
	case 11135ULL: goto x86_l_2b7f;
	case 11138ULL: goto x86_l_2b82;
	case 11144ULL: goto x86_l_2b88;
	case 11147ULL: goto x86_l_2b8b;
	case 11153ULL: goto x86_l_2b91;
	case 11158ULL: goto x86_l_2b96;
	case 11163ULL: goto x86_l_2b9b;
	case 11170ULL: goto x86_l_2ba2;
	case 11175ULL: goto x86_l_2ba7;
	case 11178ULL: goto x86_l_2baa;
	case 11182ULL: goto x86_l_2bae;
	case 11184ULL: goto x86_l_2bb0;
	case 11188ULL: goto x86_l_2bb4;
	case 11191ULL: goto x86_l_2bb7;
	case 11194ULL: goto x86_l_2bba;
	case 11197ULL: goto x86_l_2bbd;
	case 11203ULL: goto x86_l_2bc3;
	case 11208ULL: goto x86_l_2bc8;
	case 11213ULL: goto x86_l_2bcd;
	case 11216ULL: goto x86_l_2bd0;
	case 11222ULL: goto x86_l_2bd6;
	case 11228ULL: goto x86_l_2bdc;
	case 11232ULL: goto x86_l_2be0;
	case 11238ULL: goto x86_l_2be6;
	case 11240ULL: goto x86_l_2be8;
	case 11243ULL: goto x86_l_2beb;
	case 11245ULL: goto x86_l_2bed;
	case 11248ULL: goto x86_l_2bf0;
	case 11253ULL: goto x86_l_2bf5;
	case 11258ULL: goto x86_l_2bfa;
	case 11263ULL: goto x86_l_2bff;
	case 11265ULL: goto x86_l_2c01;
	case 11269ULL: goto x86_l_2c05;
	case 11271ULL: goto x86_l_2c07;
	case 11273ULL: goto x86_l_2c09;
	case 11279ULL: goto x86_l_2c0f;
	case 11282ULL: goto x86_l_2c12;
	case 11288ULL: goto x86_l_2c18;
	case 11293ULL: goto x86_l_2c1d;
	case 11298ULL: goto x86_l_2c22;
	case 11301ULL: goto x86_l_2c25;
	case 11307ULL: goto x86_l_2c2b;
	case 11313ULL: goto x86_l_2c31;
	case 11317ULL: goto x86_l_2c35;
	case 11323ULL: goto x86_l_2c3b;
	case 11325ULL: goto x86_l_2c3d;
	case 11331ULL: goto x86_l_2c43;
	case 11333ULL: goto x86_l_2c45;
	case 11339ULL: goto x86_l_2c4b;
	case 11344ULL: goto x86_l_2c50;
	case 11348ULL: goto x86_l_2c54;
	case 11354ULL: goto x86_l_2c5a;
	case 11356ULL: goto x86_l_2c5c;
	case 11360ULL: goto x86_l_2c60;
	case 11366ULL: goto x86_l_2c66;
	case 11369ULL: goto x86_l_2c69;
	case 11375ULL: goto x86_l_2c6f;
	case 11380ULL: goto x86_l_2c74;
	case 11383ULL: goto x86_l_2c77;
	case 11385ULL: goto x86_l_2c79;
	case 11388ULL: goto x86_l_2c7c;
	case 11391ULL: goto x86_l_2c7f;
	case 11393ULL: goto x86_l_2c81;
	case 11397ULL: goto x86_l_2c85;
	case 11401ULL: goto x86_l_2c89;
	case 11407ULL: goto x86_l_2c8f;
	case 11412ULL: goto x86_l_2c94;
	case 11415ULL: goto x86_l_2c97;
	case 11417ULL: goto x86_l_2c99;
	case 11420ULL: goto x86_l_2c9c;
	case 11426ULL: goto x86_l_2ca2;
	case 11429ULL: goto x86_l_2ca5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_263e:
	/* 0x263e: jle    2d1c <generic_retkprobe_filter_arg+0x2d1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11548ULL;
	}
x86_l_2644:
	/* 0x2644: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2647:
	/* 0x2647: je     3177 <generic_retkprobe_filter_arg+0x3177> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12663ULL;
	}
x86_l_264d:
	/* 0x264d: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2650:
	/* 0x2650: je     313e <generic_retkprobe_filter_arg+0x313e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12606ULL;
	}
x86_l_2656:
	/* 0x2656: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2659:
	/* 0x2659: jne    2d3f <generic_retkprobe_filter_arg+0x2d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11583ULL;
	}
x86_l_265f:
	/* 0x265f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2664:
	/* 0x2664: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2669:
	/* 0x2669: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2670:
	/* 0x2670: jmp    31ae <generic_retkprobe_filter_arg+0x31ae> */
	return 12718ULL;
x86_l_2675:
	/* 0x2675: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2677:
	/* 0x2677: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_267b:
	/* 0x267b: ja     2685 <generic_retkprobe_filter_arg+0x2685> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2685;
	}
x86_l_267d:
	/* 0x267d: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_267f:
	/* 0x267f: jbe    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 620ULL;
	}
x86_l_2685:
	/* 0x2685: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2688:
	/* 0x2688: jb     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 187ULL;
	}
x86_l_268e:
	/* 0x268e: mov    edi,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2693:
	/* 0x2693: mov    esi,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2698:
	/* 0x2698: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_269b:
	/* 0x269b: ja     2bff <generic_retkprobe_filter_arg+0x2bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2bff;
	}
x86_l_26a1:
	/* 0x26a1: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_26a7:
	/* 0x26a7: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_26ab:
	/* 0x26ab: jae    2bff <generic_retkprobe_filter_arg+0x2bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2bff;
	}
x86_l_26b1:
	/* 0x26b1: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_26b3:
	/* 0x26b3: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26b7:
	/* 0x26b7: jg     2c0f <generic_retkprobe_filter_arg+0x2c0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2c0f;
	}
x86_l_26bd:
	/* 0x26bd: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_26bf:
	/* 0x26bf: jle    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 620ULL;
	}
x86_l_26c5:
	/* 0x26c5: jmp    2c0f <generic_retkprobe_filter_arg+0x2c0f> */
	goto x86_l_2c0f;
x86_l_26ca:
	/* 0x26ca: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_26cf:
	/* 0x26cf: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_26d4:
	/* 0x26d4: jb     2701 <generic_retkprobe_filter_arg+0x2701> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2701;
	}
x86_l_26d6:
	/* 0x26d6: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_26db:
	/* 0x26db: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_26e0:
	/* 0x26e0: jb     2701 <generic_retkprobe_filter_arg+0x2701> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2701;
	}
x86_l_26e2:
	/* 0x26e2: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_26e7:
	/* 0x26e7: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_26ec:
	/* 0x26ec: jb     2701 <generic_retkprobe_filter_arg+0x2701> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2701;
	}
x86_l_26ee:
	/* 0x26ee: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26f0:
	/* 0x26f0: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_26f5:
	/* 0x26f5: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_26f8:
	/* 0x26f8: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_26fb:
	/* 0x26fb: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_2701:
	/* 0x2701: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_2707:
	/* 0x2707: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_270d:
	/* 0x270d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2710:
	/* 0x2710: jg     2aaf <generic_retkprobe_filter_arg+0x2aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2aaf;
	}
x86_l_2716:
	/* 0x2716: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2718:
	/* 0x2718: je     2f67 <generic_retkprobe_filter_arg+0x2f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12135ULL;
	}
x86_l_271e:
	/* 0x271e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2721:
	/* 0x2721: jne    2f60 <generic_retkprobe_filter_arg+0x2f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12128ULL;
	}
x86_l_2727:
	/* 0x2727: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_272c:
	/* 0x272c: jmp    2f73 <generic_retkprobe_filter_arg+0x2f73> */
	return 12147ULL;
x86_l_2731:
	/* 0x2731: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_2734:
	/* 0x2734: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2738:
	/* 0x2738: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_273b:
	/* 0x273b: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_273f:
	/* 0x273f: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2742:
	/* 0x2742: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2745:
	/* 0x2745: cmp    esi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 57ULL);
x86_l_2748:
	/* 0x2748: jb     2de9 <generic_retkprobe_filter_arg+0x2de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11753ULL;
	}
x86_l_274e:
	/* 0x274e: mov    rdi,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2753:
	/* 0x2753: mov    rsi,QWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2758:
	/* 0x2758: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_275b:
	/* 0x275b: je     2766 <generic_retkprobe_filter_arg+0x2766> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2766;
	}
x86_l_275d:
	/* 0x275d: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2760:
	/* 0x2760: jne    2d0e <generic_retkprobe_filter_arg+0x2d0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11534ULL;
	}
x86_l_2766:
	/* 0x2766: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2769:
	/* 0x2769: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_276c:
	/* 0x276c: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_276f:
	/* 0x276f: jmp    2bed <generic_retkprobe_filter_arg+0x2bed> */
	goto x86_l_2bed;
x86_l_2774:
	/* 0x2774: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2777:
	/* 0x2777: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_277b:
	/* 0x277b: ja     2786 <generic_retkprobe_filter_arg+0x2786> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2786;
	}
x86_l_277d:
	/* 0x277d: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_2780:
	/* 0x2780: jbe    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 620ULL;
	}
x86_l_2786:
	/* 0x2786: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_2789:
	/* 0x2789: jb     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 187ULL;
	}
x86_l_278f:
	/* 0x278f: mov    rsi,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2794:
	/* 0x2794: mov    rdx,QWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2799:
	/* 0x2799: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_279c:
	/* 0x279c: je     27a7 <generic_retkprobe_filter_arg+0x27a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27a7;
	}
x86_l_279e:
	/* 0x279e: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_27a1:
	/* 0x27a1: jne    2d55 <generic_retkprobe_filter_arg+0x2d55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11605ULL;
	}
x86_l_27a7:
	/* 0x27a7: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_27aa:
	/* 0x27aa: jg     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 187ULL;
	}
x86_l_27b0:
	/* 0x27b0: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_27b3:
	/* 0x27b3: jle    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 620ULL;
	}
x86_l_27b9:
	/* 0x27b9: jmp    bb <generic_retkprobe_filter_arg+0xbb> */
	return 187ULL;
x86_l_27be:
	/* 0x27be: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27c2:
	/* 0x27c2: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_27c8:
	/* 0x27c8: jmp    27d4 <generic_retkprobe_filter_arg+0x27d4> */
	goto x86_l_27d4;
x86_l_27ca:
	/* 0x27ca: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ce:
	/* 0x27ce: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_27d4:
	/* 0x27d4: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_27d7:
	/* 0x27d7: jb     35dc <generic_retkprobe_filter_arg+0x35dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13788ULL;
	}
x86_l_27dd:
	/* 0x27dd: mov    rsi,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27e2:
	/* 0x27e2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_27e5:
	/* 0x27e5: jle    2802 <generic_retkprobe_filter_arg+0x2802> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2802;
	}
x86_l_27e7:
	/* 0x27e7: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_27ea:
	/* 0x27ea: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_27ed:
	/* 0x27ed: jae    2831 <generic_retkprobe_filter_arg+0x2831> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2831;
	}
x86_l_27ef:
	/* 0x27ef: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27f3:
	/* 0x27f3: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27f7:
	/* 0x27f7: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 595ULL;
	}
x86_l_27fd:
	/* 0x27fd: jmp    2e10 <generic_retkprobe_filter_arg+0x2e10> */
	return 11792ULL;
x86_l_2802:
	/* 0x2802: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2805:
	/* 0x2805: je     2a61 <generic_retkprobe_filter_arg+0x2a61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a61;
	}
x86_l_280b:
	/* 0x280b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_280e:
	/* 0x280e: jne    2e10 <generic_retkprobe_filter_arg+0x2e10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11792ULL;
	}
x86_l_2814:
	/* 0x2814: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2817:
	/* 0x2817: je     2822 <generic_retkprobe_filter_arg+0x2822> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2822;
	}
x86_l_2819:
	/* 0x2819: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_281c:
	/* 0x281c: jne    2e06 <generic_retkprobe_filter_arg+0x2e06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11782ULL;
	}
x86_l_2822:
	/* 0x2822: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2826:
	/* 0x2826: jl     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 620ULL;
	}
x86_l_282c:
	/* 0x282c: jmp    2e10 <generic_retkprobe_filter_arg+0x2e10> */
	return 11792ULL;
x86_l_2831:
	/* 0x2831: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2834:
	/* 0x2834: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2838:
	/* 0x2838: jne    2e10 <generic_retkprobe_filter_arg+0x2e10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11792ULL;
	}
x86_l_283e:
	/* 0x283e: test   QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2842:
	/* 0x2842: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_2848:
	/* 0x2848: jmp    2e10 <generic_retkprobe_filter_arg+0x2e10> */
	return 11792ULL;
x86_l_284d:
	/* 0x284d: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2850:
	/* 0x2850: jne    2ad8 <generic_retkprobe_filter_arg+0x2ad8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ad8;
	}
x86_l_2856:
	/* 0x2856: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_285b:
	/* 0x285b: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_285d:
	/* 0x285d: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_2863:
	/* 0x2863: jmp    2ad8 <generic_retkprobe_filter_arg+0x2ad8> */
	goto x86_l_2ad8;
x86_l_2868:
	/* 0x2868: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_286b:
	/* 0x286b: jne    2b1a <generic_retkprobe_filter_arg+0x2b1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b1a;
	}
x86_l_2871:
	/* 0x2871: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2876:
	/* 0x2876: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2878:
	/* 0x2878: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_287e:
	/* 0x287e: jmp    2b1a <generic_retkprobe_filter_arg+0x2b1a> */
	goto x86_l_2b1a;
x86_l_2883:
	/* 0x2883: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_2886:
	/* 0x2886: je     2f32 <generic_retkprobe_filter_arg+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12082ULL;
	}
x86_l_288c:
	/* 0x288c: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_288f:
	/* 0x288f: je     2ef9 <generic_retkprobe_filter_arg+0x2ef9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12025ULL;
	}
x86_l_2895:
	/* 0x2895: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2898:
	/* 0x2898: jne    903 <generic_retkprobe_filter_arg+0x903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2307ULL;
	}
x86_l_289e:
	/* 0x289e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28a3:
	/* 0x28a3: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_28a8:
	/* 0x28a8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_28af:
	/* 0x28af: jmp    2f43 <generic_retkprobe_filter_arg+0x2f43> */
	return 12099ULL;
x86_l_28b4:
	/* 0x28b4: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_28b9:
	/* 0x28b9: jmp    28c7 <generic_retkprobe_filter_arg+0x28c7> */
	goto x86_l_28c7;
x86_l_28bb:
	/* 0x28bb: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_28c0:
	/* 0x28c0: jmp    28c7 <generic_retkprobe_filter_arg+0x28c7> */
	goto x86_l_28c7;
x86_l_28c2:
	/* 0x28c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28c7:
	/* 0x28c7: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_28c9:
	/* 0x28c9: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_28cc:
	/* 0x28cc: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_28d1:
	/* 0x28d1: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_28d4:
	/* 0x28d4: je     298c <generic_retkprobe_filter_arg+0x298c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_298c;
	}
x86_l_28da:
	/* 0x28da: mov    DWORD PTR [rsp+0x64],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_28de:
	/* 0x28de: mov    DWORD PTR [rsp+0x68],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_28e2:
	/* 0x28e2: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_28ea:
	/* 0x28ea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28ef:
	/* 0x28ef: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_28f6:
	/* 0x28f6: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28fb:
	/* 0x28fb: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_28fe:
	/* 0x28fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2900:
	/* 0x2900: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2903:
	/* 0x2903: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2908:
	/* 0x2908: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_290f:
	/* 0x290f: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2912:
	/* 0x2912: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2914:
	/* 0x2914: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2919:
	/* 0x2919: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_291c:
	/* 0x291c: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13677ULL;
	}
x86_l_2922:
	/* 0x2922: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_2927:
	/* 0x2927: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_292a:
	/* 0x292a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_292e:
	/* 0x292e: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2933:
	/* 0x2933: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2938:
	/* 0x2938: je     357d <generic_retkprobe_filter_arg+0x357d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13693ULL;
	}
x86_l_293e:
	/* 0x293e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2941:
	/* 0x2941: mov    ebx,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2945:
	/* 0x2945: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2948:
	/* 0x2948: jg     2993 <generic_retkprobe_filter_arg+0x2993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2993;
	}
x86_l_294a:
	/* 0x294a: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_294f:
	/* 0x294f: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2952:
	/* 0x2952: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2956:
	/* 0x2956: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_295b:
	/* 0x295b: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2960:
	/* 0x2960: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2962:
	/* 0x2962: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2964:
	/* 0x2964: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_296c:
	/* 0x296c: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_296e:
	/* 0x296e: jbe    29d6 <generic_retkprobe_filter_arg+0x29d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_29d6;
	}
x86_l_2970:
	/* 0x2970: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2975:
	/* 0x2975: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2979:
	/* 0x2979: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_297c:
	/* 0x297c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2982:
	/* 0x2982: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2987:
	/* 0x2987: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_298a:
	/* 0x298a: jmp    29d4 <generic_retkprobe_filter_arg+0x29d4> */
	goto x86_l_29d4;
x86_l_298c:
	/* 0x298c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_298e:
	/* 0x298e: jmp    357d <generic_retkprobe_filter_arg+0x357d> */
	return 13693ULL;
x86_l_2993:
	/* 0x2993: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2998:
	/* 0x2998: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_299b:
	/* 0x299b: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_299f:
	/* 0x299f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29a4:
	/* 0x29a4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29a9:
	/* 0x29a9: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_29ab:
	/* 0x29ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ad:
	/* 0x29ad: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_29b5:
	/* 0x29b5: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29b7:
	/* 0x29b7: jbe    29d6 <generic_retkprobe_filter_arg+0x29d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_29d6;
	}
x86_l_29b9:
	/* 0x29b9: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29be:
	/* 0x29be: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_29c2:
	/* 0x29c2: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_29c6:
	/* 0x29c6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29cc:
	/* 0x29cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29d1:
	/* 0x29d1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_29d4:
	/* 0x29d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d6:
	/* 0x29d6: mov    eax,DWORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_29da:
	/* 0x29da: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_29de:
	/* 0x29de: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_29e1:
	/* 0x29e1: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29e6:
	/* 0x29e6: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29eb:
	/* 0x29eb: jle    2a27 <generic_retkprobe_filter_arg+0x2a27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2a27;
	}
x86_l_29ed:
	/* 0x29ed: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_29f0:
	/* 0x29f0: jg     2b76 <generic_retkprobe_filter_arg+0x2b76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b76;
	}
x86_l_29f6:
	/* 0x29f6: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_29f9:
	/* 0x29f9: je     326c <generic_retkprobe_filter_arg+0x326c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12908ULL;
	}
x86_l_29ff:
	/* 0x29ff: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2a02:
	/* 0x2a02: je     3233 <generic_retkprobe_filter_arg+0x3233> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12851ULL;
	}
x86_l_2a08:
	/* 0x2a08: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2a0b:
	/* 0x2a0b: jne    2027 <generic_retkprobe_filter_arg+0x2027> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8231ULL;
	}
x86_l_2a11:
	/* 0x2a11: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a16:
	/* 0x2a16: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a1b:
	/* 0x2a1b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2a22:
	/* 0x2a22: jmp    3290 <generic_retkprobe_filter_arg+0x3290> */
	return 12944ULL;
x86_l_2a27:
	/* 0x2a27: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2a2a:
	/* 0x2a2a: jle    2db4 <generic_retkprobe_filter_arg+0x2db4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11700ULL;
	}
x86_l_2a30:
	/* 0x2a30: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_2a33:
	/* 0x2a33: je     3259 <generic_retkprobe_filter_arg+0x3259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12889ULL;
	}
x86_l_2a39:
	/* 0x2a39: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2a3c:
	/* 0x2a3c: je     3220 <generic_retkprobe_filter_arg+0x3220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12832ULL;
	}
x86_l_2a42:
	/* 0x2a42: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2a45:
	/* 0x2a45: jne    2027 <generic_retkprobe_filter_arg+0x2027> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8231ULL;
	}
x86_l_2a4b:
	/* 0x2a4b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a50:
	/* 0x2a50: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a55:
	/* 0x2a55: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2a5c:
	/* 0x2a5c: jmp    3290 <generic_retkprobe_filter_arg+0x3290> */
	return 12944ULL;
x86_l_2a61:
	/* 0x2a61: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2a64:
	/* 0x2a64: je     2a6f <generic_retkprobe_filter_arg+0x2a6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a6f;
	}
x86_l_2a66:
	/* 0x2a66: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2a69:
	/* 0x2a69: jne    2dfa <generic_retkprobe_filter_arg+0x2dfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11770ULL;
	}
x86_l_2a6f:
	/* 0x2a6f: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a73:
	/* 0x2a73: jg     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 620ULL;
	}
x86_l_2a79:
	/* 0x2a79: jmp    2e10 <generic_retkprobe_filter_arg+0x2e10> */
	return 11792ULL;
x86_l_2a7e:
	/* 0x2a7e: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_2a81:
	/* 0x2a81: je     319d <generic_retkprobe_filter_arg+0x319d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12701ULL;
	}
x86_l_2a87:
	/* 0x2a87: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_2a8a:
	/* 0x2a8a: je     3164 <generic_retkprobe_filter_arg+0x3164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12644ULL;
	}
x86_l_2a90:
	/* 0x2a90: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2a93:
	/* 0x2a93: jne    2d3f <generic_retkprobe_filter_arg+0x2d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11583ULL;
	}
x86_l_2a99:
	/* 0x2a99: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a9e:
	/* 0x2a9e: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2aa3:
	/* 0x2aa3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_2aaa:
	/* 0x2aaa: jmp    31ae <generic_retkprobe_filter_arg+0x31ae> */
	return 12718ULL;
x86_l_2aaf:
	/* 0x2aaf: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2ab2:
	/* 0x2ab2: je     2f6e <generic_retkprobe_filter_arg+0x2f6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12142ULL;
	}
x86_l_2ab8:
	/* 0x2ab8: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2abb:
	/* 0x2abb: jne    2f60 <generic_retkprobe_filter_arg+0x2f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12128ULL;
	}
x86_l_2ac1:
	/* 0x2ac1: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2ac6:
	/* 0x2ac6: jmp    2f73 <generic_retkprobe_filter_arg+0x2f73> */
	return 12147ULL;
x86_l_2acb:
	/* 0x2acb: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2ad0:
	/* 0x2ad0: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2ad2:
	/* 0x2ad2: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_2ad8:
	/* 0x2ad8: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2adb:
	/* 0x2adb: jb     35dc <generic_retkprobe_filter_arg+0x35dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13788ULL;
	}
x86_l_2ae1:
	/* 0x2ae1: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ae6:
	/* 0x2ae6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ae9:
	/* 0x2ae9: jle    2d6c <generic_retkprobe_filter_arg+0x2d6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11628ULL;
	}
x86_l_2aef:
	/* 0x2aef: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2af2:
	/* 0x2af2: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2af5:
	/* 0x2af5: jae    2e8a <generic_retkprobe_filter_arg+0x2e8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11914ULL;
	}
x86_l_2afb:
	/* 0x2afb: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2b00:
	/* 0x2b00: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2b02:
	/* 0x2b02: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 595ULL;
	}
x86_l_2b08:
	/* 0x2b08: jmp    32ba <generic_retkprobe_filter_arg+0x32ba> */
	return 12986ULL;
x86_l_2b0d:
	/* 0x2b0d: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b12:
	/* 0x2b12: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2b14:
	/* 0x2b14: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_2b1a:
	/* 0x2b1a: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2b1d:
	/* 0x2b1d: jb     35dc <generic_retkprobe_filter_arg+0x35dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13788ULL;
	}
x86_l_2b23:
	/* 0x2b23: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b28:
	/* 0x2b28: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b2b:
	/* 0x2b2b: jle    2d90 <generic_retkprobe_filter_arg+0x2d90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11664ULL;
	}
x86_l_2b31:
	/* 0x2b31: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2b34:
	/* 0x2b34: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2b37:
	/* 0x2b37: jae    2ea5 <generic_retkprobe_filter_arg+0x2ea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11941ULL;
	}
x86_l_2b3d:
	/* 0x2b3d: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b42:
	/* 0x2b42: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2b44:
	/* 0x2b44: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 595ULL;
	}
x86_l_2b4a:
	/* 0x2b4a: jmp    3303 <generic_retkprobe_filter_arg+0x3303> */
	return 13059ULL;
x86_l_2b4f:
	/* 0x2b4f: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_2b51:
	/* 0x2b51: je     2ec0 <generic_retkprobe_filter_arg+0x2ec0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11968ULL;
	}
x86_l_2b57:
	/* 0x2b57: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2b5a:
	/* 0x2b5a: jne    903 <generic_retkprobe_filter_arg+0x903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2307ULL;
	}
x86_l_2b60:
	/* 0x2b60: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b65:
	/* 0x2b65: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b6a:
	/* 0x2b6a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2b71:
	/* 0x2b71: jmp    2f43 <generic_retkprobe_filter_arg+0x2f43> */
	return 12099ULL;
x86_l_2b76:
	/* 0x2b76: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_2b79:
	/* 0x2b79: je     327f <generic_retkprobe_filter_arg+0x327f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12927ULL;
	}
x86_l_2b7f:
	/* 0x2b7f: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_2b82:
	/* 0x2b82: je     3246 <generic_retkprobe_filter_arg+0x3246> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12870ULL;
	}
x86_l_2b88:
	/* 0x2b88: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2b8b:
	/* 0x2b8b: jne    2027 <generic_retkprobe_filter_arg+0x2027> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8231ULL;
	}
x86_l_2b91:
	/* 0x2b91: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b96:
	/* 0x2b96: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b9b:
	/* 0x2b9b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_2ba2:
	/* 0x2ba2: jmp    3290 <generic_retkprobe_filter_arg+0x3290> */
	return 12944ULL;
x86_l_2ba7:
	/* 0x2ba7: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2baa:
	/* 0x2baa: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2bae:
	/* 0x2bae: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2bb0:
	/* 0x2bb0: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2bb4:
	/* 0x2bb4: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2bb7:
	/* 0x2bb7: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2bba:
	/* 0x2bba: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_2bbd:
	/* 0x2bbd: jb     2de9 <generic_retkprobe_filter_arg+0x2de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11753ULL;
	}
x86_l_2bc3:
	/* 0x2bc3: mov    edi,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2bc8:
	/* 0x2bc8: mov    esi,DWORD PTR [r12+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2bcd:
	/* 0x2bcd: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2bd0:
	/* 0x2bd0: ja     2ddb <generic_retkprobe_filter_arg+0x2ddb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11739ULL;
	}
x86_l_2bd6:
	/* 0x2bd6: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2bdc:
	/* 0x2bdc: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2be0:
	/* 0x2be0: jae    2ddb <generic_retkprobe_filter_arg+0x2ddb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11739ULL;
	}
x86_l_2be6:
	/* 0x2be6: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2be8:
	/* 0x2be8: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_2beb:
	/* 0x2beb: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2bed:
	/* 0x2bed: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_2bf0:
	/* 0x2bf0: jmp    2de5 <generic_retkprobe_filter_arg+0x2de5> */
	return 11749ULL;
x86_l_2bf5:
	/* 0x2bf5: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2bfa:
	/* 0x2bfa: jmp    356f <generic_retkprobe_filter_arg+0x356f> */
	return 13679ULL;
x86_l_2bff:
	/* 0x2bff: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2c01:
	/* 0x2c01: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c05:
	/* 0x2c05: ja     2c0f <generic_retkprobe_filter_arg+0x2c0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c0f;
	}
x86_l_2c07:
	/* 0x2c07: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_2c09:
	/* 0x2c09: jbe    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 620ULL;
	}
x86_l_2c0f:
	/* 0x2c0f: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2c12:
	/* 0x2c12: jb     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 187ULL;
	}
x86_l_2c18:
	/* 0x2c18: mov    esi,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c1d:
	/* 0x2c1d: mov    edx,DWORD PTR [r12+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2c22:
	/* 0x2c22: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2c25:
	/* 0x2c25: ja     30f9 <generic_retkprobe_filter_arg+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12537ULL;
	}
x86_l_2c2b:
	/* 0x2c2b: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2c31:
	/* 0x2c31: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2c35:
	/* 0x2c35: jae    30f9 <generic_retkprobe_filter_arg+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12537ULL;
	}
x86_l_2c3b:
	/* 0x2c3b: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2c3d:
	/* 0x2c3d: jg     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 187ULL;
	}
x86_l_2c43:
	/* 0x2c43: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2c45:
	/* 0x2c45: jle    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 620ULL;
	}
x86_l_2c4b:
	/* 0x2c4b: jmp    bb <generic_retkprobe_filter_arg+0xbb> */
	return 187ULL;
x86_l_2c50:
	/* 0x2c50: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c54:
	/* 0x2c54: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_2c5a:
	/* 0x2c5a: jmp    2c66 <generic_retkprobe_filter_arg+0x2c66> */
	goto x86_l_2c66;
x86_l_2c5c:
	/* 0x2c5c: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c60:
	/* 0x2c60: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_2c66:
	/* 0x2c66: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2c69:
	/* 0x2c69: jb     35dc <generic_retkprobe_filter_arg+0x35dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13788ULL;
	}
x86_l_2c6f:
	/* 0x2c6f: mov    esi,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c74:
	/* 0x2c74: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c77:
	/* 0x2c77: jle    2c94 <generic_retkprobe_filter_arg+0x2c94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2c94;
	}
x86_l_2c79:
	/* 0x2c79: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2c7c:
	/* 0x2c7c: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2c7f:
	/* 0x2c7f: jae    2cca <generic_retkprobe_filter_arg+0x2cca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11466ULL;
	}
x86_l_2c81:
	/* 0x2c81: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c85:
	/* 0x2c85: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c89:
	/* 0x2c89: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 595ULL;
	}
x86_l_2c8f:
	/* 0x2c8f: jmp    3391 <generic_retkprobe_filter_arg+0x3391> */
	return 13201ULL;
x86_l_2c94:
	/* 0x2c94: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c97:
	/* 0x2c97: je     2ce6 <generic_retkprobe_filter_arg+0x2ce6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11494ULL;
	}
x86_l_2c99:
	/* 0x2c99: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c9c:
	/* 0x2c9c: jne    3391 <generic_retkprobe_filter_arg+0x3391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13201ULL;
	}
x86_l_2ca2:
	/* 0x2ca2: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2ca5:
	/* 0x2ca5: ja     3387 <generic_retkprobe_filter_arg+0x3387> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13191ULL;
	}
	return 11435ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11435ULL: goto x86_l_2cab;
	case 11441ULL: goto x86_l_2cb1;
	case 11445ULL: goto x86_l_2cb5;
	case 11451ULL: goto x86_l_2cbb;
	case 11455ULL: goto x86_l_2cbf;
	case 11461ULL: goto x86_l_2cc5;
	case 11466ULL: goto x86_l_2cca;
	case 11469ULL: goto x86_l_2ccd;
	case 11473ULL: goto x86_l_2cd1;
	case 11479ULL: goto x86_l_2cd7;
	case 11483ULL: goto x86_l_2cdb;
	case 11489ULL: goto x86_l_2ce1;
	case 11494ULL: goto x86_l_2ce6;
	case 11497ULL: goto x86_l_2ce9;
	case 11503ULL: goto x86_l_2cef;
	case 11509ULL: goto x86_l_2cf5;
	case 11513ULL: goto x86_l_2cf9;
	case 11519ULL: goto x86_l_2cff;
	case 11523ULL: goto x86_l_2d03;
	case 11529ULL: goto x86_l_2d09;
	case 11534ULL: goto x86_l_2d0e;
	case 11537ULL: goto x86_l_2d11;
	case 11540ULL: goto x86_l_2d14;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11550ULL: goto x86_l_2d1e;
	case 11556ULL: goto x86_l_2d24;
	case 11559ULL: goto x86_l_2d27;
	case 11561ULL: goto x86_l_2d29;
	case 11566ULL: goto x86_l_2d2e;
	case 11571ULL: goto x86_l_2d33;
	case 11578ULL: goto x86_l_2d3a;
	case 11583ULL: goto x86_l_2d3f;
	case 11585ULL: goto x86_l_2d41;
	case 11590ULL: goto x86_l_2d46;
	case 11594ULL: goto x86_l_2d4a;
	case 11600ULL: goto x86_l_2d50;
	case 11605ULL: goto x86_l_2d55;
	case 11608ULL: goto x86_l_2d58;
	case 11614ULL: goto x86_l_2d5e;
	case 11617ULL: goto x86_l_2d61;
	case 11623ULL: goto x86_l_2d67;
	case 11628ULL: goto x86_l_2d6c;
	case 11631ULL: goto x86_l_2d6f;
	case 11637ULL: goto x86_l_2d75;
	case 11640ULL: goto x86_l_2d78;
	case 11646ULL: goto x86_l_2d7e;
	case 11651ULL: goto x86_l_2d83;
	case 11653ULL: goto x86_l_2d85;
	case 11659ULL: goto x86_l_2d8b;
	case 11664ULL: goto x86_l_2d90;
	case 11667ULL: goto x86_l_2d93;
	case 11673ULL: goto x86_l_2d99;
	case 11676ULL: goto x86_l_2d9c;
	case 11682ULL: goto x86_l_2da2;
	case 11687ULL: goto x86_l_2da7;
	case 11689ULL: goto x86_l_2da9;
	case 11695ULL: goto x86_l_2daf;
	case 11700ULL: goto x86_l_2db4;
	case 11702ULL: goto x86_l_2db6;
	case 11708ULL: goto x86_l_2dbc;
	case 11711ULL: goto x86_l_2dbf;
	case 11717ULL: goto x86_l_2dc5;
	case 11722ULL: goto x86_l_2dca;
	case 11727ULL: goto x86_l_2dcf;
	case 11734ULL: goto x86_l_2dd6;
	case 11739ULL: goto x86_l_2ddb;
	case 11741ULL: goto x86_l_2ddd;
	case 11744ULL: goto x86_l_2de0;
	case 11746ULL: goto x86_l_2de2;
	case 11749ULL: goto x86_l_2de5;
	case 11751ULL: goto x86_l_2de7;
	case 11753ULL: goto x86_l_2de9;
	case 11757ULL: goto x86_l_2ded;
	case 11759ULL: goto x86_l_2def;
	case 11765ULL: goto x86_l_2df5;
	case 11770ULL: goto x86_l_2dfa;
	case 11774ULL: goto x86_l_2dfe;
	case 11780ULL: goto x86_l_2e04;
	case 11782ULL: goto x86_l_2e06;
	case 11786ULL: goto x86_l_2e0a;
	case 11792ULL: goto x86_l_2e10;
	case 11795ULL: goto x86_l_2e13;
	case 11801ULL: goto x86_l_2e19;
	case 11806ULL: goto x86_l_2e1e;
	case 11809ULL: goto x86_l_2e21;
	case 11811ULL: goto x86_l_2e23;
	case 11814ULL: goto x86_l_2e26;
	case 11817ULL: goto x86_l_2e29;
	case 11819ULL: goto x86_l_2e2b;
	case 11822ULL: goto x86_l_2e2e;
	case 11828ULL: goto x86_l_2e34;
	case 11831ULL: goto x86_l_2e37;
	case 11837ULL: goto x86_l_2e3d;
	case 11841ULL: goto x86_l_2e41;
	case 11847ULL: goto x86_l_2e47;
	case 11852ULL: goto x86_l_2e4c;
	case 11855ULL: goto x86_l_2e4f;
	case 11861ULL: goto x86_l_2e55;
	case 11864ULL: goto x86_l_2e58;
	case 11870ULL: goto x86_l_2e5e;
	case 11873ULL: goto x86_l_2e61;
	case 11875ULL: goto x86_l_2e63;
	case 11878ULL: goto x86_l_2e66;
	case 11884ULL: goto x86_l_2e6c;
	case 11888ULL: goto x86_l_2e70;
	case 11894ULL: goto x86_l_2e76;
	case 11899ULL: goto x86_l_2e7b;
	case 11903ULL: goto x86_l_2e7f;
	case 11909ULL: goto x86_l_2e85;
	case 11914ULL: goto x86_l_2e8a;
	case 11917ULL: goto x86_l_2e8d;
	case 11923ULL: goto x86_l_2e93;
	case 11928ULL: goto x86_l_2e98;
	case 11930ULL: goto x86_l_2e9a;
	case 11936ULL: goto x86_l_2ea0;
	case 11941ULL: goto x86_l_2ea5;
	case 11944ULL: goto x86_l_2ea8;
	case 11950ULL: goto x86_l_2eae;
	case 11955ULL: goto x86_l_2eb3;
	case 11957ULL: goto x86_l_2eb5;
	case 11963ULL: goto x86_l_2ebb;
	case 11968ULL: goto x86_l_2ec0;
	case 11973ULL: goto x86_l_2ec5;
	case 11980ULL: goto x86_l_2ecc;
	case 11985ULL: goto x86_l_2ed1;
	case 11987ULL: goto x86_l_2ed3;
	case 11992ULL: goto x86_l_2ed8;
	case 11997ULL: goto x86_l_2edd;
	case 12004ULL: goto x86_l_2ee4;
	case 12006ULL: goto x86_l_2ee6;
	case 12011ULL: goto x86_l_2eeb;
	case 12016ULL: goto x86_l_2ef0;
	case 12023ULL: goto x86_l_2ef7;
	case 12025ULL: goto x86_l_2ef9;
	case 12030ULL: goto x86_l_2efe;
	case 12035ULL: goto x86_l_2f03;
	case 12042ULL: goto x86_l_2f0a;
	case 12044ULL: goto x86_l_2f0c;
	case 12049ULL: goto x86_l_2f11;
	case 12054ULL: goto x86_l_2f16;
	case 12061ULL: goto x86_l_2f1d;
	case 12063ULL: goto x86_l_2f1f;
	case 12068ULL: goto x86_l_2f24;
	case 12073ULL: goto x86_l_2f29;
	case 12080ULL: goto x86_l_2f30;
	case 12082ULL: goto x86_l_2f32;
	case 12087ULL: goto x86_l_2f37;
	case 12092ULL: goto x86_l_2f3c;
	case 12099ULL: goto x86_l_2f43;
	case 12101ULL: goto x86_l_2f45;
	case 12104ULL: goto x86_l_2f48;
	case 12110ULL: goto x86_l_2f4e;
	case 12113ULL: goto x86_l_2f51;
	case 12118ULL: goto x86_l_2f56;
	case 12123ULL: goto x86_l_2f5b;
	case 12128ULL: goto x86_l_2f60;
	case 12133ULL: goto x86_l_2f65;
	case 12135ULL: goto x86_l_2f67;
	case 12140ULL: goto x86_l_2f6c;
	case 12142ULL: goto x86_l_2f6e;
	case 12147ULL: goto x86_l_2f73;
	case 12149ULL: goto x86_l_2f75;
	case 12152ULL: goto x86_l_2f78;
	case 12157ULL: goto x86_l_2f7d;
	case 12160ULL: goto x86_l_2f80;
	case 12166ULL: goto x86_l_2f86;
	case 12173ULL: goto x86_l_2f8d;
	case 12177ULL: goto x86_l_2f91;
	case 12182ULL: goto x86_l_2f96;
	case 12187ULL: goto x86_l_2f9b;
	case 12194ULL: goto x86_l_2fa2;
	case 12199ULL: goto x86_l_2fa7;
	case 12202ULL: goto x86_l_2faa;
	case 12204ULL: goto x86_l_2fac;
	case 12207ULL: goto x86_l_2faf;
	case 12212ULL: goto x86_l_2fb4;
	case 12219ULL: goto x86_l_2fbb;
	case 12222ULL: goto x86_l_2fbe;
	case 12224ULL: goto x86_l_2fc0;
	case 12229ULL: goto x86_l_2fc5;
	case 12232ULL: goto x86_l_2fc8;
	case 12238ULL: goto x86_l_2fce;
	case 12243ULL: goto x86_l_2fd3;
	case 12246ULL: goto x86_l_2fd6;
	case 12250ULL: goto x86_l_2fda;
	case 12255ULL: goto x86_l_2fdf;
	case 12260ULL: goto x86_l_2fe4;
	case 12266ULL: goto x86_l_2fea;
	case 12269ULL: goto x86_l_2fed;
	case 12273ULL: goto x86_l_2ff1;
	case 12276ULL: goto x86_l_2ff4;
	case 12278ULL: goto x86_l_2ff6;
	case 12283ULL: goto x86_l_2ffb;
	case 12286ULL: goto x86_l_2ffe;
	case 12290ULL: goto x86_l_3002;
	case 12295ULL: goto x86_l_3007;
	case 12300ULL: goto x86_l_300c;
	case 12302ULL: goto x86_l_300e;
	case 12304ULL: goto x86_l_3010;
	case 12309ULL: goto x86_l_3015;
	case 12311ULL: goto x86_l_3017;
	case 12313ULL: goto x86_l_3019;
	case 12318ULL: goto x86_l_301e;
	case 12322ULL: goto x86_l_3022;
	case 12325ULL: goto x86_l_3025;
	case 12331ULL: goto x86_l_302b;
	case 12336ULL: goto x86_l_3030;
	case 12339ULL: goto x86_l_3033;
	case 12341ULL: goto x86_l_3035;
	case 12346ULL: goto x86_l_303a;
	case 12349ULL: goto x86_l_303d;
	case 12353ULL: goto x86_l_3041;
	case 12358ULL: goto x86_l_3046;
	case 12363ULL: goto x86_l_304b;
	case 12365ULL: goto x86_l_304d;
	case 12367ULL: goto x86_l_304f;
	case 12372ULL: goto x86_l_3054;
	case 12374ULL: goto x86_l_3056;
	case 12376ULL: goto x86_l_3058;
	case 12381ULL: goto x86_l_305d;
	case 12385ULL: goto x86_l_3061;
	case 12389ULL: goto x86_l_3065;
	case 12395ULL: goto x86_l_306b;
	case 12400ULL: goto x86_l_3070;
	case 12403ULL: goto x86_l_3073;
	case 12405ULL: goto x86_l_3075;
	case 12412ULL: goto x86_l_307c;
	case 12416ULL: goto x86_l_3080;
	case 12419ULL: goto x86_l_3083;
	case 12421ULL: goto x86_l_3085;
	case 12424ULL: goto x86_l_3088;
	case 12430ULL: goto x86_l_308e;
	case 12433ULL: goto x86_l_3091;
	case 12439ULL: goto x86_l_3097;
	case 12442ULL: goto x86_l_309a;
	case 12448ULL: goto x86_l_30a0;
	case 12451ULL: goto x86_l_30a3;
	case 12457ULL: goto x86_l_30a9;
	case 12462ULL: goto x86_l_30ae;
	case 12467ULL: goto x86_l_30b3;
	case 12474ULL: goto x86_l_30ba;
	case 12479ULL: goto x86_l_30bf;
	case 12482ULL: goto x86_l_30c2;
	case 12488ULL: goto x86_l_30c8;
	case 12491ULL: goto x86_l_30cb;
	case 12497ULL: goto x86_l_30d1;
	case 12500ULL: goto x86_l_30d4;
	case 12506ULL: goto x86_l_30da;
	case 12509ULL: goto x86_l_30dd;
	case 12515ULL: goto x86_l_30e3;
	case 12520ULL: goto x86_l_30e8;
	case 12525ULL: goto x86_l_30ed;
	case 12532ULL: goto x86_l_30f4;
	case 12537ULL: goto x86_l_30f9;
	case 12539ULL: goto x86_l_30fb;
	case 12545ULL: goto x86_l_3101;
	case 12547ULL: goto x86_l_3103;
	case 12553ULL: goto x86_l_3109;
	case 12558ULL: goto x86_l_310e;
	case 12561ULL: goto x86_l_3111;
	case 12563ULL: goto x86_l_3113;
	case 12566ULL: goto x86_l_3116;
	case 12572ULL: goto x86_l_311c;
	case 12576ULL: goto x86_l_3120;
	case 12582ULL: goto x86_l_3126;
	case 12587ULL: goto x86_l_312b;
	case 12592ULL: goto x86_l_3130;
	case 12599ULL: goto x86_l_3137;
	case 12604ULL: goto x86_l_313c;
	case 12606ULL: goto x86_l_313e;
	case 12611ULL: goto x86_l_3143;
	case 12616ULL: goto x86_l_3148;
	case 12623ULL: goto x86_l_314f;
	case 12625ULL: goto x86_l_3151;
	case 12630ULL: goto x86_l_3156;
	case 12635ULL: goto x86_l_315b;
	case 12642ULL: goto x86_l_3162;
	case 12644ULL: goto x86_l_3164;
	case 12649ULL: goto x86_l_3169;
	case 12654ULL: goto x86_l_316e;
	case 12661ULL: goto x86_l_3175;
	case 12663ULL: goto x86_l_3177;
	case 12668ULL: goto x86_l_317c;
	case 12673ULL: goto x86_l_3181;
	case 12680ULL: goto x86_l_3188;
	case 12682ULL: goto x86_l_318a;
	case 12687ULL: goto x86_l_318f;
	case 12692ULL: goto x86_l_3194;
	case 12699ULL: goto x86_l_319b;
	case 12701ULL: goto x86_l_319d;
	case 12706ULL: goto x86_l_31a2;
	case 12711ULL: goto x86_l_31a7;
	case 12718ULL: goto x86_l_31ae;
	case 12720ULL: goto x86_l_31b0;
	case 12723ULL: goto x86_l_31b3;
	case 12725ULL: goto x86_l_31b5;
	case 12728ULL: goto x86_l_31b8;
	case 12733ULL: goto x86_l_31bd;
	case 12741ULL: goto x86_l_31c5;
	case 12743ULL: goto x86_l_31c7;
	case 12745ULL: goto x86_l_31c9;
	case 12748ULL: goto x86_l_31cc;
	case 12751ULL: goto x86_l_31cf;
	case 12753ULL: goto x86_l_31d1;
	case 12755ULL: goto x86_l_31d3;
	case 12759ULL: goto x86_l_31d7;
	case 12764ULL: goto x86_l_31dc;
	case 12769ULL: goto x86_l_31e1;
	case 12774ULL: goto x86_l_31e6;
	case 12778ULL: goto x86_l_31ea;
	case 12784ULL: goto x86_l_31f0;
	case 12794ULL: goto x86_l_31fa;
	case 12798ULL: goto x86_l_31fe;
	case 12804ULL: goto x86_l_3204;
	case 12808ULL: goto x86_l_3208;
	case 12813ULL: goto x86_l_320d;
	case 12818ULL: goto x86_l_3212;
	case 12825ULL: goto x86_l_3219;
	case 12830ULL: goto x86_l_321e;
	case 12832ULL: goto x86_l_3220;
	case 12837ULL: goto x86_l_3225;
	case 12842ULL: goto x86_l_322a;
	case 12849ULL: goto x86_l_3231;
	case 12851ULL: goto x86_l_3233;
	case 12856ULL: goto x86_l_3238;
	case 12861ULL: goto x86_l_323d;
	case 12868ULL: goto x86_l_3244;
	case 12870ULL: goto x86_l_3246;
	case 12875ULL: goto x86_l_324b;
	case 12880ULL: goto x86_l_3250;
	case 12887ULL: goto x86_l_3257;
	case 12889ULL: goto x86_l_3259;
	case 12894ULL: goto x86_l_325e;
	case 12899ULL: goto x86_l_3263;
	case 12906ULL: goto x86_l_326a;
	case 12908ULL: goto x86_l_326c;
	case 12913ULL: goto x86_l_3271;
	case 12918ULL: goto x86_l_3276;
	case 12925ULL: goto x86_l_327d;
	case 12927ULL: goto x86_l_327f;
	case 12932ULL: goto x86_l_3284;
	case 12937ULL: goto x86_l_3289;
	case 12944ULL: goto x86_l_3290;
	case 12946ULL: goto x86_l_3292;
	case 12949ULL: goto x86_l_3295;
	case 12955ULL: goto x86_l_329b;
	case 12958ULL: goto x86_l_329e;
	case 12963ULL: goto x86_l_32a3;
	case 12968ULL: goto x86_l_32a8;
	case 12973ULL: goto x86_l_32ad;
	case 12978ULL: goto x86_l_32b2;
	case 12980ULL: goto x86_l_32b4;
	case 12986ULL: goto x86_l_32ba;
	case 12989ULL: goto x86_l_32bd;
	case 12995ULL: goto x86_l_32c3;
	case 13000ULL: goto x86_l_32c8;
	case 13003ULL: goto x86_l_32cb;
	case 13009ULL: goto x86_l_32d1;
	case 13012ULL: goto x86_l_32d4;
	case 13015ULL: goto x86_l_32d7;
	case 13021ULL: goto x86_l_32dd;
	case 13024ULL: goto x86_l_32e0;
	case 13030ULL: goto x86_l_32e6;
	case 13033ULL: goto x86_l_32e9;
	case 13039ULL: goto x86_l_32ef;
	case 13044ULL: goto x86_l_32f4;
	case 13046ULL: goto x86_l_32f6;
	case 13051ULL: goto x86_l_32fb;
	case 13053ULL: goto x86_l_32fd;
	case 13059ULL: goto x86_l_3303;
	case 13062ULL: goto x86_l_3306;
	case 13068ULL: goto x86_l_330c;
	case 13073ULL: goto x86_l_3311;
	case 13076ULL: goto x86_l_3314;
	case 13082ULL: goto x86_l_331a;
	case 13085ULL: goto x86_l_331d;
	case 13088ULL: goto x86_l_3320;
	case 13094ULL: goto x86_l_3326;
	case 13097ULL: goto x86_l_3329;
	case 13103ULL: goto x86_l_332f;
	case 13106ULL: goto x86_l_3332;
	case 13112ULL: goto x86_l_3338;
	case 13117ULL: goto x86_l_333d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2cab:
	/* 0x2cab: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2cb1:
	/* 0x2cb1: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2cb5:
	/* 0x2cb5: jae    3387 <generic_retkprobe_filter_arg+0x3387> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13191ULL;
	}
x86_l_2cbb:
	/* 0x2cbb: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cbf:
	/* 0x2cbf: jl     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 620ULL;
	}
x86_l_2cc5:
	/* 0x2cc5: jmp    3391 <generic_retkprobe_filter_arg+0x3391> */
	return 13201ULL;
x86_l_2cca:
	/* 0x2cca: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2ccd:
	/* 0x2ccd: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cd1:
	/* 0x2cd1: jne    3391 <generic_retkprobe_filter_arg+0x3391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13201ULL;
	}
x86_l_2cd7:
	/* 0x2cd7: test   DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cdb:
	/* 0x2cdb: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_2ce1:
	/* 0x2ce1: jmp    3391 <generic_retkprobe_filter_arg+0x3391> */
	return 13201ULL;
x86_l_2ce6:
	/* 0x2ce6: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2ce9:
	/* 0x2ce9: ja     337b <generic_retkprobe_filter_arg+0x337b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13179ULL;
	}
x86_l_2cef:
	/* 0x2cef: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2cf5:
	/* 0x2cf5: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2cf9:
	/* 0x2cf9: jae    337b <generic_retkprobe_filter_arg+0x337b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13179ULL;
	}
x86_l_2cff:
	/* 0x2cff: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d03:
	/* 0x2d03: jg     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 620ULL;
	}
x86_l_2d09:
	/* 0x2d09: jmp    3391 <generic_retkprobe_filter_arg+0x3391> */
	return 13201ULL;
x86_l_2d0e:
	/* 0x2d0e: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2d11:
	/* 0x2d11: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2d14:
	/* 0x2d14: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_2d17:
	/* 0x2d17: jmp    2de2 <generic_retkprobe_filter_arg+0x2de2> */
	goto x86_l_2de2;
x86_l_2d1c:
	/* 0x2d1c: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_2d1e:
	/* 0x2d1e: je     312b <generic_retkprobe_filter_arg+0x312b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_312b;
	}
x86_l_2d24:
	/* 0x2d24: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2d27:
	/* 0x2d27: jne    2d3f <generic_retkprobe_filter_arg+0x2d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d3f;
	}
x86_l_2d29:
	/* 0x2d29: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d2e:
	/* 0x2d2e: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d33:
	/* 0x2d33: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2d3a:
	/* 0x2d3a: jmp    31ae <generic_retkprobe_filter_arg+0x31ae> */
	goto x86_l_31ae;
x86_l_2d3f:
	/* 0x2d3f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d41:
	/* 0x2d41: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d46:
	/* 0x2d46: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2d4a:
	/* 0x2d4a: jbe    31f0 <generic_retkprobe_filter_arg+0x31f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_31f0;
	}
x86_l_2d50:
	/* 0x2d50: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_2d55:
	/* 0x2d55: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2d58:
	/* 0x2d58: ja     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 187ULL;
	}
x86_l_2d5e:
	/* 0x2d5e: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2d61:
	/* 0x2d61: jbe    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 620ULL;
	}
x86_l_2d67:
	/* 0x2d67: jmp    bb <generic_retkprobe_filter_arg+0xbb> */
	return 187ULL;
x86_l_2d6c:
	/* 0x2d6c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d6f:
	/* 0x2d6f: je     32ad <generic_retkprobe_filter_arg+0x32ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ad;
	}
x86_l_2d75:
	/* 0x2d75: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d78:
	/* 0x2d78: jne    32ba <generic_retkprobe_filter_arg+0x32ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32ba;
	}
x86_l_2d7e:
	/* 0x2d7e: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2d83:
	/* 0x2d83: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2d85:
	/* 0x2d85: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_2d8b:
	/* 0x2d8b: jmp    32ba <generic_retkprobe_filter_arg+0x32ba> */
	goto x86_l_32ba;
x86_l_2d90:
	/* 0x2d90: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d93:
	/* 0x2d93: je     32f6 <generic_retkprobe_filter_arg+0x32f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32f6;
	}
x86_l_2d99:
	/* 0x2d99: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d9c:
	/* 0x2d9c: jne    3303 <generic_retkprobe_filter_arg+0x3303> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3303;
	}
x86_l_2da2:
	/* 0x2da2: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2da7:
	/* 0x2da7: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2da9:
	/* 0x2da9: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_2daf:
	/* 0x2daf: jmp    3303 <generic_retkprobe_filter_arg+0x3303> */
	goto x86_l_3303;
x86_l_2db4:
	/* 0x2db4: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_2db6:
	/* 0x2db6: je     320d <generic_retkprobe_filter_arg+0x320d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_320d;
	}
x86_l_2dbc:
	/* 0x2dbc: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2dbf:
	/* 0x2dbf: jne    2027 <generic_retkprobe_filter_arg+0x2027> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8231ULL;
	}
x86_l_2dc5:
	/* 0x2dc5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2dca:
	/* 0x2dca: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2dcf:
	/* 0x2dcf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2dd6:
	/* 0x2dd6: jmp    3290 <generic_retkprobe_filter_arg+0x3290> */
	goto x86_l_3290;
x86_l_2ddb:
	/* 0x2ddb: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2ddd:
	/* 0x2ddd: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2de0:
	/* 0x2de0: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2de2:
	/* 0x2de2: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_2de5:
	/* 0x2de5: and    dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2de7:
	/* 0x2de7: or     al,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2de9:
	/* 0x2de9: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ded:
	/* 0x2ded: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2def:
	/* 0x2def: je     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 620ULL;
	}
x86_l_2df5:
	/* 0x2df5: jmp    bb <generic_retkprobe_filter_arg+0xbb> */
	return 187ULL;
x86_l_2dfa:
	/* 0x2dfa: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dfe:
	/* 0x2dfe: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_2e04:
	/* 0x2e04: jmp    2e10 <generic_retkprobe_filter_arg+0x2e10> */
	goto x86_l_2e10;
x86_l_2e06:
	/* 0x2e06: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e0a:
	/* 0x2e0a: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_2e10:
	/* 0x2e10: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2e13:
	/* 0x2e13: jb     35dc <generic_retkprobe_filter_arg+0x35dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13788ULL;
	}
x86_l_2e19:
	/* 0x2e19: mov    rdx,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e1e:
	/* 0x2e1e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e21:
	/* 0x2e21: jle    2e4c <generic_retkprobe_filter_arg+0x2e4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e4c;
	}
x86_l_2e23:
	/* 0x2e23: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2e26:
	/* 0x2e26: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2e29:
	/* 0x2e29: jb     2e7b <generic_retkprobe_filter_arg+0x2e7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2e7b;
	}
x86_l_2e2b:
	/* 0x2e2b: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2e2e:
	/* 0x2e2e: je     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 620ULL;
	}
x86_l_2e34:
	/* 0x2e34: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2e37:
	/* 0x2e37: jne    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 187ULL;
	}
x86_l_2e3d:
	/* 0x2e3d: test   QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e41:
	/* 0x2e41: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_2e47:
	/* 0x2e47: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	return 13788ULL;
x86_l_2e4c:
	/* 0x2e4c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e4f:
	/* 0x2e4f: je     310e <generic_retkprobe_filter_arg+0x310e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_310e;
	}
x86_l_2e55:
	/* 0x2e55: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e58:
	/* 0x2e58: jne    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 187ULL;
	}
x86_l_2e5e:
	/* 0x2e5e: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2e61:
	/* 0x2e61: je     2e6c <generic_retkprobe_filter_arg+0x2e6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e6c;
	}
x86_l_2e63:
	/* 0x2e63: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2e66:
	/* 0x2e66: jne    34b3 <generic_retkprobe_filter_arg+0x34b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13491ULL;
	}
x86_l_2e6c:
	/* 0x2e6c: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e70:
	/* 0x2e70: jl     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 620ULL;
	}
x86_l_2e76:
	/* 0x2e76: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	return 13788ULL;
x86_l_2e7b:
	/* 0x2e7b: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e7f:
	/* 0x2e7f: jne    35dc <generic_retkprobe_filter_arg+0x35dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13788ULL;
	}
x86_l_2e85:
	/* 0x2e85: jmp    253 <generic_retkprobe_filter_arg+0x253> */
	return 595ULL;
x86_l_2e8a:
	/* 0x2e8a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2e8d:
	/* 0x2e8d: jne    32ba <generic_retkprobe_filter_arg+0x32ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32ba;
	}
x86_l_2e93:
	/* 0x2e93: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2e98:
	/* 0x2e98: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2e9a:
	/* 0x2e9a: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_2ea0:
	/* 0x2ea0: jmp    32ba <generic_retkprobe_filter_arg+0x32ba> */
	goto x86_l_32ba;
x86_l_2ea5:
	/* 0x2ea5: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2ea8:
	/* 0x2ea8: jne    3303 <generic_retkprobe_filter_arg+0x3303> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3303;
	}
x86_l_2eae:
	/* 0x2eae: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2eb3:
	/* 0x2eb3: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2eb5:
	/* 0x2eb5: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_2ebb:
	/* 0x2ebb: jmp    3303 <generic_retkprobe_filter_arg+0x3303> */
	goto x86_l_3303;
x86_l_2ec0:
	/* 0x2ec0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ec5:
	/* 0x2ec5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2ecc:
	/* 0x2ecc: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ed1:
	/* 0x2ed1: jmp    2f43 <generic_retkprobe_filter_arg+0x2f43> */
	goto x86_l_2f43;
x86_l_2ed3:
	/* 0x2ed3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ed8:
	/* 0x2ed8: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2edd:
	/* 0x2edd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_2ee4:
	/* 0x2ee4: jmp    2f43 <generic_retkprobe_filter_arg+0x2f43> */
	goto x86_l_2f43;
x86_l_2ee6:
	/* 0x2ee6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2eeb:
	/* 0x2eeb: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ef0:
	/* 0x2ef0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2ef7:
	/* 0x2ef7: jmp    2f43 <generic_retkprobe_filter_arg+0x2f43> */
	goto x86_l_2f43;
x86_l_2ef9:
	/* 0x2ef9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2efe:
	/* 0x2efe: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f03:
	/* 0x2f03: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_2f0a:
	/* 0x2f0a: jmp    2f43 <generic_retkprobe_filter_arg+0x2f43> */
	goto x86_l_2f43;
x86_l_2f0c:
	/* 0x2f0c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f11:
	/* 0x2f11: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f16:
	/* 0x2f16: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2f1d:
	/* 0x2f1d: jmp    2f43 <generic_retkprobe_filter_arg+0x2f43> */
	goto x86_l_2f43;
x86_l_2f1f:
	/* 0x2f1f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f24:
	/* 0x2f24: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f29:
	/* 0x2f29: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2f30:
	/* 0x2f30: jmp    2f43 <generic_retkprobe_filter_arg+0x2f43> */
	goto x86_l_2f43;
x86_l_2f32:
	/* 0x2f32: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f37:
	/* 0x2f37: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f3c:
	/* 0x2f3c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_2f43:
	/* 0x2f43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f45:
	/* 0x2f45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f48:
	/* 0x2f48: je     31d1 <generic_retkprobe_filter_arg+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31d1;
	}
x86_l_2f4e:
	/* 0x2f4e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2f51:
	/* 0x2f51: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f56:
	/* 0x2f56: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f5b:
	/* 0x2f5b: jmp    31c5 <generic_retkprobe_filter_arg+0x31c5> */
	goto x86_l_31c5;
x86_l_2f60:
	/* 0x2f60: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2f65:
	/* 0x2f65: jmp    2f73 <generic_retkprobe_filter_arg+0x2f73> */
	goto x86_l_2f73;
x86_l_2f67:
	/* 0x2f67: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2f6c:
	/* 0x2f6c: jmp    2f73 <generic_retkprobe_filter_arg+0x2f73> */
	goto x86_l_2f73;
x86_l_2f6e:
	/* 0x2f6e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f73:
	/* 0x2f73: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2f75:
	/* 0x2f75: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2f78:
	/* 0x2f78: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2f7d:
	/* 0x2f7d: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2f80:
	/* 0x2f80: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13677ULL;
	}
x86_l_2f86:
	/* 0x2f86: mov    DWORD PTR [rsp+0x88],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2f8d:
	/* 0x2f8d: mov    DWORD PTR [rsp+0x64],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_2f91:
	/* 0x2f91: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2f96:
	/* 0x2f96: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f9b:
	/* 0x2f9b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2fa2:
	/* 0x2fa2: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2fa7:
	/* 0x2fa7: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2faa:
	/* 0x2faa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fac:
	/* 0x2fac: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2faf:
	/* 0x2faf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fb4:
	/* 0x2fb4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2fbb:
	/* 0x2fbb: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2fbe:
	/* 0x2fbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fc0:
	/* 0x2fc0: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fc5:
	/* 0x2fc5: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2fc8:
	/* 0x2fc8: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13677ULL;
	}
x86_l_2fce:
	/* 0x2fce: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_2fd3:
	/* 0x2fd3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2fd6:
	/* 0x2fd6: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fda:
	/* 0x2fda: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fdf:
	/* 0x2fdf: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fe4:
	/* 0x2fe4: je     357d <generic_retkprobe_filter_arg+0x357d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13693ULL;
	}
x86_l_2fea:
	/* 0x2fea: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2fed:
	/* 0x2fed: mov    ebx,DWORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_2ff1:
	/* 0x2ff1: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2ff4:
	/* 0x2ff4: jg     3035 <generic_retkprobe_filter_arg+0x3035> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3035;
	}
x86_l_2ff6:
	/* 0x2ff6: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ffb:
	/* 0x2ffb: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ffe:
	/* 0x2ffe: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3002:
	/* 0x3002: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3007:
	/* 0x3007: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_300c:
	/* 0x300c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_300e:
	/* 0x300e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3010:
	/* 0x3010: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3015:
	/* 0x3015: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3017:
	/* 0x3017: jbe    3075 <generic_retkprobe_filter_arg+0x3075> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3075;
	}
x86_l_3019:
	/* 0x3019: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_301e:
	/* 0x301e: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3022:
	/* 0x3022: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3025:
	/* 0x3025: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_302b:
	/* 0x302b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3030:
	/* 0x3030: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3033:
	/* 0x3033: jmp    3073 <generic_retkprobe_filter_arg+0x3073> */
	goto x86_l_3073;
x86_l_3035:
	/* 0x3035: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_303a:
	/* 0x303a: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_303d:
	/* 0x303d: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3041:
	/* 0x3041: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3046:
	/* 0x3046: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_304b:
	/* 0x304b: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_304d:
	/* 0x304d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_304f:
	/* 0x304f: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3054:
	/* 0x3054: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3056:
	/* 0x3056: jbe    3075 <generic_retkprobe_filter_arg+0x3075> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3075;
	}
x86_l_3058:
	/* 0x3058: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_305d:
	/* 0x305d: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3061:
	/* 0x3061: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3065:
	/* 0x3065: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_306b:
	/* 0x306b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3070:
	/* 0x3070: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3073:
	/* 0x3073: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3075:
	/* 0x3075: mov    eax,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_307c:
	/* 0x307c: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3080:
	/* 0x3080: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3083:
	/* 0x3083: jle    30bf <generic_retkprobe_filter_arg+0x30bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_30bf;
	}
x86_l_3085:
	/* 0x3085: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_3088:
	/* 0x3088: jg     334a <generic_retkprobe_filter_arg+0x334a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13130ULL;
	}
x86_l_308e:
	/* 0x308e: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_3091:
	/* 0x3091: je     3530 <generic_retkprobe_filter_arg+0x3530> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13616ULL;
	}
x86_l_3097:
	/* 0x3097: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_309a:
	/* 0x309a: je     34f7 <generic_retkprobe_filter_arg+0x34f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13559ULL;
	}
x86_l_30a0:
	/* 0x30a0: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_30a3:
	/* 0x30a3: jne    356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13677ULL;
	}
x86_l_30a9:
	/* 0x30a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30ae:
	/* 0x30ae: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_30b3:
	/* 0x30b3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_30ba:
	/* 0x30ba: jmp    3554 <generic_retkprobe_filter_arg+0x3554> */
	return 13652ULL;
x86_l_30bf:
	/* 0x30bf: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_30c2:
	/* 0x30c2: jle    3436 <generic_retkprobe_filter_arg+0x3436> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 13366ULL;
	}
x86_l_30c8:
	/* 0x30c8: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_30cb:
	/* 0x30cb: je     351d <generic_retkprobe_filter_arg+0x351d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13597ULL;
	}
x86_l_30d1:
	/* 0x30d1: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_30d4:
	/* 0x30d4: je     34e4 <generic_retkprobe_filter_arg+0x34e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13540ULL;
	}
x86_l_30da:
	/* 0x30da: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_30dd:
	/* 0x30dd: jne    356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13677ULL;
	}
x86_l_30e3:
	/* 0x30e3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30e8:
	/* 0x30e8: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_30ed:
	/* 0x30ed: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_30f4:
	/* 0x30f4: jmp    3554 <generic_retkprobe_filter_arg+0x3554> */
	return 13652ULL;
x86_l_30f9:
	/* 0x30f9: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_30fb:
	/* 0x30fb: ja     bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 187ULL;
	}
x86_l_3101:
	/* 0x3101: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_3103:
	/* 0x3103: jbe    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 620ULL;
	}
x86_l_3109:
	/* 0x3109: jmp    bb <generic_retkprobe_filter_arg+0xbb> */
	return 187ULL;
x86_l_310e:
	/* 0x310e: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_3111:
	/* 0x3111: je     311c <generic_retkprobe_filter_arg+0x311c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_311c;
	}
x86_l_3113:
	/* 0x3113: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_3116:
	/* 0x3116: jne    34c2 <generic_retkprobe_filter_arg+0x34c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13506ULL;
	}
x86_l_311c:
	/* 0x311c: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3120:
	/* 0x3120: jg     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 620ULL;
	}
x86_l_3126:
	/* 0x3126: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	return 13788ULL;
x86_l_312b:
	/* 0x312b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3130:
	/* 0x3130: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_3137:
	/* 0x3137: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_313c:
	/* 0x313c: jmp    31ae <generic_retkprobe_filter_arg+0x31ae> */
	goto x86_l_31ae;
x86_l_313e:
	/* 0x313e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3143:
	/* 0x3143: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3148:
	/* 0x3148: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_314f:
	/* 0x314f: jmp    31ae <generic_retkprobe_filter_arg+0x31ae> */
	goto x86_l_31ae;
x86_l_3151:
	/* 0x3151: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3156:
	/* 0x3156: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_315b:
	/* 0x315b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_3162:
	/* 0x3162: jmp    31ae <generic_retkprobe_filter_arg+0x31ae> */
	goto x86_l_31ae;
x86_l_3164:
	/* 0x3164: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3169:
	/* 0x3169: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_316e:
	/* 0x316e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_3175:
	/* 0x3175: jmp    31ae <generic_retkprobe_filter_arg+0x31ae> */
	goto x86_l_31ae;
x86_l_3177:
	/* 0x3177: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_317c:
	/* 0x317c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3181:
	/* 0x3181: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3188:
	/* 0x3188: jmp    31ae <generic_retkprobe_filter_arg+0x31ae> */
	goto x86_l_31ae;
x86_l_318a:
	/* 0x318a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_318f:
	/* 0x318f: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3194:
	/* 0x3194: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_319b:
	/* 0x319b: jmp    31ae <generic_retkprobe_filter_arg+0x31ae> */
	goto x86_l_31ae;
x86_l_319d:
	/* 0x319d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31a2:
	/* 0x31a2: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_31a7:
	/* 0x31a7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_31ae:
	/* 0x31ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b0:
	/* 0x31b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31b3:
	/* 0x31b3: je     31d1 <generic_retkprobe_filter_arg+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31d1;
	}
x86_l_31b5:
	/* 0x31b5: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_31b8:
	/* 0x31b8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31bd:
	/* 0x31bd: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_31c5:
	/* 0x31c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c7:
	/* 0x31c7: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31c9:
	/* 0x31c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31cc:
	/* 0x31cc: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_31cf:
	/* 0x31cf: jmp    31d3 <generic_retkprobe_filter_arg+0x31d3> */
	goto x86_l_31d3;
x86_l_31d1:
	/* 0x31d1: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31d3:
	/* 0x31d3: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31d7:
	/* 0x31d7: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31dc:
	/* 0x31dc: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31e1:
	/* 0x31e1: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_31e6:
	/* 0x31e6: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_31ea:
	/* 0x31ea: ja     25b <generic_retkprobe_filter_arg+0x25b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 603ULL;
	}
x86_l_31f0:
	/* 0x31f0: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_31fa:
	/* 0x31fa: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_31fe:
	/* 0x31fe: jae    25b <generic_retkprobe_filter_arg+0x25b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 603ULL;
	}
x86_l_3204:
	/* 0x3204: xor    rbx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_3208:
	/* 0x3208: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_320d:
	/* 0x320d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3212:
	/* 0x3212: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_3219:
	/* 0x3219: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_321e:
	/* 0x321e: jmp    3290 <generic_retkprobe_filter_arg+0x3290> */
	goto x86_l_3290;
x86_l_3220:
	/* 0x3220: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3225:
	/* 0x3225: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_322a:
	/* 0x322a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_3231:
	/* 0x3231: jmp    3290 <generic_retkprobe_filter_arg+0x3290> */
	goto x86_l_3290;
x86_l_3233:
	/* 0x3233: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3238:
	/* 0x3238: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_323d:
	/* 0x323d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_3244:
	/* 0x3244: jmp    3290 <generic_retkprobe_filter_arg+0x3290> */
	goto x86_l_3290;
x86_l_3246:
	/* 0x3246: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_324b:
	/* 0x324b: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3250:
	/* 0x3250: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_3257:
	/* 0x3257: jmp    3290 <generic_retkprobe_filter_arg+0x3290> */
	goto x86_l_3290;
x86_l_3259:
	/* 0x3259: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_325e:
	/* 0x325e: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3263:
	/* 0x3263: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_326a:
	/* 0x326a: jmp    3290 <generic_retkprobe_filter_arg+0x3290> */
	goto x86_l_3290;
x86_l_326c:
	/* 0x326c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3271:
	/* 0x3271: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3276:
	/* 0x3276: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_327d:
	/* 0x327d: jmp    3290 <generic_retkprobe_filter_arg+0x3290> */
	goto x86_l_3290;
x86_l_327f:
	/* 0x327f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3284:
	/* 0x3284: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3289:
	/* 0x3289: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_3290:
	/* 0x3290: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3292:
	/* 0x3292: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3295:
	/* 0x3295: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13677ULL;
	}
x86_l_329b:
	/* 0x329b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_329e:
	/* 0x329e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32a3:
	/* 0x32a3: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32a8:
	/* 0x32a8: jmp    1a18 <generic_retkprobe_filter_arg+0x1a18> */
	return 6680ULL;
x86_l_32ad:
	/* 0x32ad: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_32b2:
	/* 0x32b2: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_32b4:
	/* 0x32b4: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_32ba:
	/* 0x32ba: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_32bd:
	/* 0x32bd: jb     35dc <generic_retkprobe_filter_arg+0x35dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13788ULL;
	}
x86_l_32c3:
	/* 0x32c3: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_32c8:
	/* 0x32c8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_32cb:
	/* 0x32cb: jle    345d <generic_retkprobe_filter_arg+0x345d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 13405ULL;
	}
x86_l_32d1:
	/* 0x32d1: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_32d4:
	/* 0x32d4: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_32d7:
	/* 0x32d7: jb     349a <generic_retkprobe_filter_arg+0x349a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13466ULL;
	}
x86_l_32dd:
	/* 0x32dd: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_32e0:
	/* 0x32e0: je     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 620ULL;
	}
x86_l_32e6:
	/* 0x32e6: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_32e9:
	/* 0x32e9: jne    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 187ULL;
	}
x86_l_32ef:
	/* 0x32ef: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_32f4:
	/* 0x32f4: jmp    333d <generic_retkprobe_filter_arg+0x333d> */
	goto x86_l_333d;
x86_l_32f6:
	/* 0x32f6: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32fb:
	/* 0x32fb: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_32fd:
	/* 0x32fd: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_3303:
	/* 0x3303: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_3306:
	/* 0x3306: jb     35dc <generic_retkprobe_filter_arg+0x35dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13788ULL;
	}
x86_l_330c:
	/* 0x330c: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3311:
	/* 0x3311: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3314:
	/* 0x3314: jle    3476 <generic_retkprobe_filter_arg+0x3476> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 13430ULL;
	}
x86_l_331a:
	/* 0x331a: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_331d:
	/* 0x331d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3320:
	/* 0x3320: jb     34a1 <generic_retkprobe_filter_arg+0x34a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13473ULL;
	}
x86_l_3326:
	/* 0x3326: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3329:
	/* 0x3329: je     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 620ULL;
	}
x86_l_332f:
	/* 0x332f: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3332:
	/* 0x3332: jne    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 187ULL;
	}
x86_l_3338:
	/* 0x3338: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_333d:
	/* 0x333d: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
	return 13119ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13119ULL: goto x86_l_333f;
	case 13125ULL: goto x86_l_3345;
	case 13130ULL: goto x86_l_334a;
	case 13133ULL: goto x86_l_334d;
	case 13139ULL: goto x86_l_3353;
	case 13142ULL: goto x86_l_3356;
	case 13148ULL: goto x86_l_335c;
	case 13151ULL: goto x86_l_335f;
	case 13157ULL: goto x86_l_3365;
	case 13162ULL: goto x86_l_336a;
	case 13167ULL: goto x86_l_336f;
	case 13174ULL: goto x86_l_3376;
	case 13179ULL: goto x86_l_337b;
	case 13183ULL: goto x86_l_337f;
	case 13189ULL: goto x86_l_3385;
	case 13191ULL: goto x86_l_3387;
	case 13195ULL: goto x86_l_338b;
	case 13201ULL: goto x86_l_3391;
	case 13204ULL: goto x86_l_3394;
	case 13210ULL: goto x86_l_339a;
	case 13215ULL: goto x86_l_339f;
	case 13218ULL: goto x86_l_33a2;
	case 13220ULL: goto x86_l_33a4;
	case 13223ULL: goto x86_l_33a7;
	case 13226ULL: goto x86_l_33aa;
	case 13228ULL: goto x86_l_33ac;
	case 13231ULL: goto x86_l_33af;
	case 13237ULL: goto x86_l_33b5;
	case 13240ULL: goto x86_l_33b8;
	case 13246ULL: goto x86_l_33be;
	case 13250ULL: goto x86_l_33c2;
	case 13256ULL: goto x86_l_33c8;
	case 13261ULL: goto x86_l_33cd;
	case 13264ULL: goto x86_l_33d0;
	case 13266ULL: goto x86_l_33d2;
	case 13269ULL: goto x86_l_33d5;
	case 13275ULL: goto x86_l_33db;
	case 13278ULL: goto x86_l_33de;
	case 13284ULL: goto x86_l_33e4;
	case 13289ULL: goto x86_l_33e9;
	case 13292ULL: goto x86_l_33ec;
	case 13298ULL: goto x86_l_33f2;
	case 13302ULL: goto x86_l_33f6;
	case 13308ULL: goto x86_l_33fc;
	case 13313ULL: goto x86_l_3401;
	case 13317ULL: goto x86_l_3405;
	case 13323ULL: goto x86_l_340b;
	case 13328ULL: goto x86_l_3410;
	case 13331ULL: goto x86_l_3413;
	case 13337ULL: goto x86_l_3419;
	case 13342ULL: goto x86_l_341e;
	case 13345ULL: goto x86_l_3421;
	case 13351ULL: goto x86_l_3427;
	case 13355ULL: goto x86_l_342b;
	case 13361ULL: goto x86_l_3431;
	case 13366ULL: goto x86_l_3436;
	case 13368ULL: goto x86_l_3438;
	case 13374ULL: goto x86_l_343e;
	case 13377ULL: goto x86_l_3441;
	case 13383ULL: goto x86_l_3447;
	case 13388ULL: goto x86_l_344c;
	case 13393ULL: goto x86_l_3451;
	case 13400ULL: goto x86_l_3458;
	case 13405ULL: goto x86_l_345d;
	case 13408ULL: goto x86_l_3460;
	case 13414ULL: goto x86_l_3466;
	case 13417ULL: goto x86_l_3469;
	case 13423ULL: goto x86_l_346f;
	case 13428ULL: goto x86_l_3474;
	case 13430ULL: goto x86_l_3476;
	case 13433ULL: goto x86_l_3479;
	case 13439ULL: goto x86_l_347f;
	case 13442ULL: goto x86_l_3482;
	case 13448ULL: goto x86_l_3488;
	case 13453ULL: goto x86_l_348d;
	case 13455ULL: goto x86_l_348f;
	case 13461ULL: goto x86_l_3495;
	case 13466ULL: goto x86_l_349a;
	case 13471ULL: goto x86_l_349f;
	case 13473ULL: goto x86_l_34a1;
	case 13478ULL: goto x86_l_34a6;
	case 13480ULL: goto x86_l_34a8;
	case 13486ULL: goto x86_l_34ae;
	case 13491ULL: goto x86_l_34b3;
	case 13495ULL: goto x86_l_34b7;
	case 13501ULL: goto x86_l_34bd;
	case 13506ULL: goto x86_l_34c2;
	case 13510ULL: goto x86_l_34c6;
	case 13516ULL: goto x86_l_34cc;
	case 13521ULL: goto x86_l_34d1;
	case 13526ULL: goto x86_l_34d6;
	case 13533ULL: goto x86_l_34dd;
	case 13538ULL: goto x86_l_34e2;
	case 13540ULL: goto x86_l_34e4;
	case 13545ULL: goto x86_l_34e9;
	case 13550ULL: goto x86_l_34ee;
	case 13557ULL: goto x86_l_34f5;
	case 13559ULL: goto x86_l_34f7;
	case 13564ULL: goto x86_l_34fc;
	case 13569ULL: goto x86_l_3501;
	case 13576ULL: goto x86_l_3508;
	case 13578ULL: goto x86_l_350a;
	case 13583ULL: goto x86_l_350f;
	case 13588ULL: goto x86_l_3514;
	case 13595ULL: goto x86_l_351b;
	case 13597ULL: goto x86_l_351d;
	case 13602ULL: goto x86_l_3522;
	case 13607ULL: goto x86_l_3527;
	case 13614ULL: goto x86_l_352e;
	case 13616ULL: goto x86_l_3530;
	case 13621ULL: goto x86_l_3535;
	case 13626ULL: goto x86_l_353a;
	case 13633ULL: goto x86_l_3541;
	case 13635ULL: goto x86_l_3543;
	case 13640ULL: goto x86_l_3548;
	case 13645ULL: goto x86_l_354d;
	case 13652ULL: goto x86_l_3554;
	case 13654ULL: goto x86_l_3556;
	case 13657ULL: goto x86_l_3559;
	case 13659ULL: goto x86_l_355b;
	case 13662ULL: goto x86_l_355e;
	case 13667ULL: goto x86_l_3563;
	case 13672ULL: goto x86_l_3568;
	case 13677ULL: goto x86_l_356d;
	case 13679ULL: goto x86_l_356f;
	case 13683ULL: goto x86_l_3573;
	case 13688ULL: goto x86_l_3578;
	case 13693ULL: goto x86_l_357d;
	case 13698ULL: goto x86_l_3582;
	case 13702ULL: goto x86_l_3586;
	case 13708ULL: goto x86_l_358c;
	case 13718ULL: goto x86_l_3596;
	case 13722ULL: goto x86_l_359a;
	case 13728ULL: goto x86_l_35a0;
	case 13730ULL: goto x86_l_35a2;
	case 13733ULL: goto x86_l_35a5;
	case 13736ULL: goto x86_l_35a8;
	case 13739ULL: goto x86_l_35ab;
	case 13744ULL: goto x86_l_35b0;
	case 13749ULL: goto x86_l_35b5;
	case 13751ULL: goto x86_l_35b7;
	case 13756ULL: goto x86_l_35bc;
	case 13758ULL: goto x86_l_35be;
	case 13764ULL: goto x86_l_35c4;
	case 13766ULL: goto x86_l_35c6;
	case 13770ULL: goto x86_l_35ca;
	case 13776ULL: goto x86_l_35d0;
	case 13778ULL: goto x86_l_35d2;
	case 13782ULL: goto x86_l_35d6;
	case 13788ULL: goto x86_l_35dc;
	case 13791ULL: goto x86_l_35df;
	case 13794ULL: goto x86_l_35e2;
	case 13800ULL: goto x86_l_35e8;
	case 13805ULL: goto x86_l_35ed;
	case 13810ULL: goto x86_l_35f2;
	case 13813ULL: goto x86_l_35f5;
	case 13815ULL: goto x86_l_35f7;
	case 13816ULL: goto x86_l_35f8;
	case 13818ULL: goto x86_l_35fa;
	case 13820ULL: goto x86_l_35fc;
	case 13823ULL: goto x86_l_35ff;
	case 13826ULL: goto x86_l_3602;
	case 13829ULL: goto x86_l_3605;
	case 13831ULL: goto x86_l_3607;
	case 13834ULL: goto x86_l_360a;
	case 13838ULL: goto x86_l_360e;
	case 13841ULL: goto x86_l_3611;
	case 13843ULL: goto x86_l_3613;
	case 13848ULL: goto x86_l_3618;
	case 13851ULL: goto x86_l_361b;
	case 13853ULL: goto x86_l_361d;
	case 13858ULL: goto x86_l_3622;
	case 13862ULL: goto x86_l_3626;
	case 13865ULL: goto x86_l_3629;
	case 13868ULL: goto x86_l_362c;
	case 13872ULL: goto x86_l_3630;
	case 13876ULL: goto x86_l_3634;
	case 13880ULL: goto x86_l_3638;
	case 13883ULL: goto x86_l_363b;
	case 13887ULL: goto x86_l_363f;
	case 13891ULL: goto x86_l_3643;
	case 13895ULL: goto x86_l_3647;
	case 13898ULL: goto x86_l_364a;
	case 13900ULL: goto x86_l_364c;
	case 13904ULL: goto x86_l_3650;
	case 13908ULL: goto x86_l_3654;
	case 13911ULL: goto x86_l_3657;
	case 13913ULL: goto x86_l_3659;
	case 13915ULL: goto x86_l_365b;
	case 13917ULL: goto x86_l_365d;
	case 13918ULL: goto x86_l_365e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_333f:
	/* 0x333f: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_3345:
	/* 0x3345: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	goto x86_l_35dc;
x86_l_334a:
	/* 0x334a: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_334d:
	/* 0x334d: je     3543 <generic_retkprobe_filter_arg+0x3543> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3543;
	}
x86_l_3353:
	/* 0x3353: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_3356:
	/* 0x3356: je     350a <generic_retkprobe_filter_arg+0x350a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_350a;
	}
x86_l_335c:
	/* 0x335c: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_335f:
	/* 0x335f: jne    356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_356d;
	}
x86_l_3365:
	/* 0x3365: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_336a:
	/* 0x336a: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_336f:
	/* 0x336f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_3376:
	/* 0x3376: jmp    3554 <generic_retkprobe_filter_arg+0x3554> */
	goto x86_l_3554;
x86_l_337b:
	/* 0x337b: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_337f:
	/* 0x337f: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_3385:
	/* 0x3385: jmp    3391 <generic_retkprobe_filter_arg+0x3391> */
	goto x86_l_3391;
x86_l_3387:
	/* 0x3387: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_338b:
	/* 0x338b: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_3391:
	/* 0x3391: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_3394:
	/* 0x3394: jb     35dc <generic_retkprobe_filter_arg+0x35dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_35dc;
	}
x86_l_339a:
	/* 0x339a: mov    edx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_339f:
	/* 0x339f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_33a2:
	/* 0x33a2: jle    33cd <generic_retkprobe_filter_arg+0x33cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_33cd;
	}
x86_l_33a4:
	/* 0x33a4: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_33a7:
	/* 0x33a7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_33aa:
	/* 0x33aa: jb     3401 <generic_retkprobe_filter_arg+0x3401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3401;
	}
x86_l_33ac:
	/* 0x33ac: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_33af:
	/* 0x33af: je     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 620ULL;
	}
x86_l_33b5:
	/* 0x33b5: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_33b8:
	/* 0x33b8: jne    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 187ULL;
	}
x86_l_33be:
	/* 0x33be: test   DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33c2:
	/* 0x33c2: jne    26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 620ULL;
	}
x86_l_33c8:
	/* 0x33c8: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	goto x86_l_35dc;
x86_l_33cd:
	/* 0x33cd: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33d0:
	/* 0x33d0: je     3410 <generic_retkprobe_filter_arg+0x3410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3410;
	}
x86_l_33d2:
	/* 0x33d2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_33d5:
	/* 0x33d5: jne    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 187ULL;
	}
x86_l_33db:
	/* 0x33db: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_33de:
	/* 0x33de: ja     35c6 <generic_retkprobe_filter_arg+0x35c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_35c6;
	}
x86_l_33e4:
	/* 0x33e4: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_33e9:
	/* 0x33e9: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_33ec:
	/* 0x33ec: jae    35c6 <generic_retkprobe_filter_arg+0x35c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_35c6;
	}
x86_l_33f2:
	/* 0x33f2: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33f6:
	/* 0x33f6: jl     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 620ULL;
	}
x86_l_33fc:
	/* 0x33fc: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	goto x86_l_35dc;
x86_l_3401:
	/* 0x3401: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3405:
	/* 0x3405: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 595ULL;
	}
x86_l_340b:
	/* 0x340b: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	goto x86_l_35dc;
x86_l_3410:
	/* 0x3410: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_3413:
	/* 0x3413: ja     35d2 <generic_retkprobe_filter_arg+0x35d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_35d2;
	}
x86_l_3419:
	/* 0x3419: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_341e:
	/* 0x341e: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_3421:
	/* 0x3421: jae    35d2 <generic_retkprobe_filter_arg+0x35d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_35d2;
	}
x86_l_3427:
	/* 0x3427: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_342b:
	/* 0x342b: jg     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 620ULL;
	}
x86_l_3431:
	/* 0x3431: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	goto x86_l_35dc;
x86_l_3436:
	/* 0x3436: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_3438:
	/* 0x3438: je     34d1 <generic_retkprobe_filter_arg+0x34d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34d1;
	}
x86_l_343e:
	/* 0x343e: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3441:
	/* 0x3441: jne    356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_356d;
	}
x86_l_3447:
	/* 0x3447: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_344c:
	/* 0x344c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3451:
	/* 0x3451: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_3458:
	/* 0x3458: jmp    3554 <generic_retkprobe_filter_arg+0x3554> */
	goto x86_l_3554;
x86_l_345d:
	/* 0x345d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3460:
	/* 0x3460: je     35b0 <generic_retkprobe_filter_arg+0x35b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35b0;
	}
x86_l_3466:
	/* 0x3466: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3469:
	/* 0x3469: jne    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 187ULL;
	}
x86_l_346f:
	/* 0x346f: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3474:
	/* 0x3474: jmp    348d <generic_retkprobe_filter_arg+0x348d> */
	goto x86_l_348d;
x86_l_3476:
	/* 0x3476: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3479:
	/* 0x3479: je     35b7 <generic_retkprobe_filter_arg+0x35b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35b7;
	}
x86_l_347f:
	/* 0x347f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3482:
	/* 0x3482: jne    bb <generic_retkprobe_filter_arg+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 187ULL;
	}
x86_l_3488:
	/* 0x3488: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_348d:
	/* 0x348d: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_348f:
	/* 0x348f: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_3495:
	/* 0x3495: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	goto x86_l_35dc;
x86_l_349a:
	/* 0x349a: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_349f:
	/* 0x349f: jmp    34a6 <generic_retkprobe_filter_arg+0x34a6> */
	goto x86_l_34a6;
x86_l_34a1:
	/* 0x34a1: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34a6:
	/* 0x34a6: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_34a8:
	/* 0x34a8: je     253 <generic_retkprobe_filter_arg+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 595ULL;
	}
x86_l_34ae:
	/* 0x34ae: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	goto x86_l_35dc;
x86_l_34b3:
	/* 0x34b3: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34b7:
	/* 0x34b7: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_34bd:
	/* 0x34bd: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	goto x86_l_35dc;
x86_l_34c2:
	/* 0x34c2: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34c6:
	/* 0x34c6: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_34cc:
	/* 0x34cc: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	goto x86_l_35dc;
x86_l_34d1:
	/* 0x34d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34d6:
	/* 0x34d6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_34dd:
	/* 0x34dd: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_34e2:
	/* 0x34e2: jmp    3554 <generic_retkprobe_filter_arg+0x3554> */
	goto x86_l_3554;
x86_l_34e4:
	/* 0x34e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34e9:
	/* 0x34e9: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_34ee:
	/* 0x34ee: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_34f5:
	/* 0x34f5: jmp    3554 <generic_retkprobe_filter_arg+0x3554> */
	goto x86_l_3554;
x86_l_34f7:
	/* 0x34f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34fc:
	/* 0x34fc: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3501:
	/* 0x3501: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_3508:
	/* 0x3508: jmp    3554 <generic_retkprobe_filter_arg+0x3554> */
	goto x86_l_3554;
x86_l_350a:
	/* 0x350a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_350f:
	/* 0x350f: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3514:
	/* 0x3514: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_351b:
	/* 0x351b: jmp    3554 <generic_retkprobe_filter_arg+0x3554> */
	goto x86_l_3554;
x86_l_351d:
	/* 0x351d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3522:
	/* 0x3522: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3527:
	/* 0x3527: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_352e:
	/* 0x352e: jmp    3554 <generic_retkprobe_filter_arg+0x3554> */
	goto x86_l_3554;
x86_l_3530:
	/* 0x3530: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3535:
	/* 0x3535: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_353a:
	/* 0x353a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3541:
	/* 0x3541: jmp    3554 <generic_retkprobe_filter_arg+0x3554> */
	goto x86_l_3554;
x86_l_3543:
	/* 0x3543: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3548:
	/* 0x3548: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_354d:
	/* 0x354d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_3554:
	/* 0x3554: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3556:
	/* 0x3556: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3559:
	/* 0x3559: je     356d <generic_retkprobe_filter_arg+0x356d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_356d;
	}
x86_l_355b:
	/* 0x355b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_355e:
	/* 0x355e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3563:
	/* 0x3563: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3568:
	/* 0x3568: jmp    1a18 <generic_retkprobe_filter_arg+0x1a18> */
	return 6680ULL;
x86_l_356d:
	/* 0x356d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_356f:
	/* 0x356f: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3573:
	/* 0x3573: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3578:
	/* 0x3578: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_357d:
	/* 0x357d: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3582:
	/* 0x3582: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_3586:
	/* 0x3586: ja     25b <generic_retkprobe_filter_arg+0x25b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 603ULL;
	}
x86_l_358c:
	/* 0x358c: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_3596:
	/* 0x3596: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_359a:
	/* 0x359a: jae    25b <generic_retkprobe_filter_arg+0x25b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 603ULL;
	}
x86_l_35a0:
	/* 0x35a0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35a2:
	/* 0x35a2: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_35a5:
	/* 0x35a5: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_35a8:
	/* 0x35a8: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_35ab:
	/* 0x35ab: jmp    25b <generic_retkprobe_filter_arg+0x25b> */
	return 603ULL;
x86_l_35b0:
	/* 0x35b0: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_35b5:
	/* 0x35b5: jmp    35bc <generic_retkprobe_filter_arg+0x35bc> */
	goto x86_l_35bc;
x86_l_35b7:
	/* 0x35b7: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35bc:
	/* 0x35bc: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_35be:
	/* 0x35be: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_35c4:
	/* 0x35c4: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	goto x86_l_35dc;
x86_l_35c6:
	/* 0x35c6: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35ca:
	/* 0x35ca: jb     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 620ULL;
	}
x86_l_35d0:
	/* 0x35d0: jmp    35dc <generic_retkprobe_filter_arg+0x35dc> */
	goto x86_l_35dc;
x86_l_35d2:
	/* 0x35d2: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35d6:
	/* 0x35d6: ja     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 620ULL;
	}
x86_l_35dc:
	/* 0x35dc: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_35df:
	/* 0x35df: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_35e2:
	/* 0x35e2: je     26c <generic_retkprobe_filter_arg+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 620ULL;
	}
x86_l_35e8:
	/* 0x35e8: jmp    bb <generic_retkprobe_filter_arg+0xbb> */
	return 187ULL;
x86_l_35ed:
	/* 0x35ed: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_35f2:
	/* 0x35f2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_35f5:
	/* 0x35f5: je     365e <native_bpf_strncasestr+0x71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_365e;
	}
x86_l_35f7:
	/* 0x35f7: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_35f8:
	/* 0x35f8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35fa:
	/* 0x35fa: jmp    3607 <native_bpf_strncasestr+0x1a> */
	goto x86_l_3607;
x86_l_35fc:
	/* 0x35fc: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_35ff:
	/* 0x35ff: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3602:
	/* 0x3602: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3605:
	/* 0x3605: je     365d <native_bpf_strncasestr+0x70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_365d;
	}
x86_l_3607:
	/* 0x3607: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_360a:
	/* 0x360a: lea    r9,[rcx+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_360e:
	/* 0x360e: cmp    r9,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RDX, X86_WIDTH_64);
x86_l_3611:
	/* 0x3611: jae    35fc <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_35fc;
	}
x86_l_3613:
	/* 0x3613: movsx  r9d,BYTE PTR [rsi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_3618:
	/* 0x3618: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_361b:
	/* 0x361b: je     365b <native_bpf_strncasestr+0x6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_365b;
	}
x86_l_361d:
	/* 0x361d: movsx  r10d,BYTE PTR [rdi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_3622:
	/* 0x3622: lea    r11d,[r10-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_3626:
	/* 0x3626: mov    ebx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R10, X86_WIDTH_32);
x86_l_3629:
	/* 0x3629: or     ebx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_362c:
	/* 0x362c: cmp    r11d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 26ULL);
x86_l_3630:
	/* 0x3630: cmovae ebx,r10d */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R10, X86_WIDTH_32, X86_CC_AE);
x86_l_3634:
	/* 0x3634: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_3638:
	/* 0x3638: mov    r11d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_32);
x86_l_363b:
	/* 0x363b: or     r11d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_363f:
	/* 0x363f: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_3643:
	/* 0x3643: cmovae r11d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_3647:
	/* 0x3647: cmp    ebx,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R11, X86_WIDTH_32);
x86_l_364a:
	/* 0x364a: jne    35fc <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_35fc;
	}
x86_l_364c:
	/* 0x364c: lea    r9,[r8+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3650:
	/* 0x3650: cmp    r8,0x63 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 99ULL);
x86_l_3654:
	/* 0x3654: mov    r8,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_64);
x86_l_3657:
	/* 0x3657: jb     360a <native_bpf_strncasestr+0x1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_360a;
	}
x86_l_3659:
	/* 0x3659: jmp    35fc <native_bpf_strncasestr+0xf> */
	goto x86_l_35fc;
x86_l_365b:
	/* 0x365b: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_365d:
	/* 0x365d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_365e:
	/* 0x365e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 13052U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1729ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1732ULL && __x86_pc <= 3384ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3390ULL && __x86_pc <= 4967ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4972ULL && __x86_pc <= 6599ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6604ULL && __x86_pc <= 8169ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8172ULL && __x86_pc <= 9787ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9790ULL && __x86_pc <= 11429ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11435ULL && __x86_pc <= 13117ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13119ULL && __x86_pc <= 13918ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v511_generic_retkprobe_filter_arg_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

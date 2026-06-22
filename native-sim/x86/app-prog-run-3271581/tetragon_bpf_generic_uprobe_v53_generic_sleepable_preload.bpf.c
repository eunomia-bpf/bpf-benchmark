extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_0(
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
	case 77ULL: goto x86_l_4d;
	case 84ULL: goto x86_l_54;
	case 89ULL: goto x86_l_59;
	case 93ULL: goto x86_l_5d;
	case 98ULL: goto x86_l_62;
	case 102ULL: goto x86_l_66;
	case 106ULL: goto x86_l_6a;
	case 111ULL: goto x86_l_6f;
	case 115ULL: goto x86_l_73;
	case 119ULL: goto x86_l_77;
	case 127ULL: goto x86_l_7f;
	case 131ULL: goto x86_l_83;
	case 135ULL: goto x86_l_87;
	case 143ULL: goto x86_l_8f;
	case 147ULL: goto x86_l_93;
	case 152ULL: goto x86_l_98;
	case 156ULL: goto x86_l_9c;
	case 164ULL: goto x86_l_a4;
	case 168ULL: goto x86_l_a8;
	case 173ULL: goto x86_l_ad;
	case 177ULL: goto x86_l_b1;
	case 185ULL: goto x86_l_b9;
	case 189ULL: goto x86_l_bd;
	case 194ULL: goto x86_l_c2;
	case 198ULL: goto x86_l_c6;
	case 203ULL: goto x86_l_cb;
	case 207ULL: goto x86_l_cf;
	case 212ULL: goto x86_l_d4;
	case 215ULL: goto x86_l_d7;
	case 220ULL: goto x86_l_dc;
	case 222ULL: goto x86_l_de;
	case 225ULL: goto x86_l_e1;
	case 230ULL: goto x86_l_e6;
	case 232ULL: goto x86_l_e8;
	case 235ULL: goto x86_l_eb;
	case 240ULL: goto x86_l_f0;
	case 246ULL: goto x86_l_f6;
	case 249ULL: goto x86_l_f9;
	case 254ULL: goto x86_l_fe;
	case 260ULL: goto x86_l_104;
	case 263ULL: goto x86_l_107;
	case 268ULL: goto x86_l_10c;
	case 274ULL: goto x86_l_112;
	case 276ULL: goto x86_l_114;
	case 283ULL: goto x86_l_11b;
	case 284ULL: goto x86_l_11c;
	case 286ULL: goto x86_l_11e;
	case 288ULL: goto x86_l_120;
	case 290ULL: goto x86_l_122;
	case 292ULL: goto x86_l_124;
	case 293ULL: goto x86_l_125;
	case 298ULL: goto x86_l_12a;
	case 300ULL: goto x86_l_12c;
	case 306ULL: goto x86_l_132;
	case 309ULL: goto x86_l_135;
	case 312ULL: goto x86_l_138;
	case 318ULL: goto x86_l_13e;
	case 321ULL: goto x86_l_141;
	case 327ULL: goto x86_l_147;
	case 330ULL: goto x86_l_14a;
	case 336ULL: goto x86_l_150;
	case 339ULL: goto x86_l_153;
	case 345ULL: goto x86_l_159;
	case 349ULL: goto x86_l_15d;
	case 354ULL: goto x86_l_162;
	case 356ULL: goto x86_l_164;
	case 362ULL: goto x86_l_16a;
	case 365ULL: goto x86_l_16d;
	case 368ULL: goto x86_l_170;
	case 374ULL: goto x86_l_176;
	case 377ULL: goto x86_l_179;
	case 383ULL: goto x86_l_17f;
	case 386ULL: goto x86_l_182;
	case 392ULL: goto x86_l_188;
	case 395ULL: goto x86_l_18b;
	case 401ULL: goto x86_l_191;
	case 405ULL: goto x86_l_195;
	case 410ULL: goto x86_l_19a;
	case 412ULL: goto x86_l_19c;
	case 418ULL: goto x86_l_1a2;
	case 421ULL: goto x86_l_1a5;
	case 424ULL: goto x86_l_1a8;
	case 430ULL: goto x86_l_1ae;
	case 433ULL: goto x86_l_1b1;
	case 439ULL: goto x86_l_1b7;
	case 442ULL: goto x86_l_1ba;
	case 448ULL: goto x86_l_1c0;
	case 451ULL: goto x86_l_1c3;
	case 457ULL: goto x86_l_1c9;
	case 461ULL: goto x86_l_1cd;
	case 466ULL: goto x86_l_1d2;
	case 468ULL: goto x86_l_1d4;
	case 474ULL: goto x86_l_1da;
	case 477ULL: goto x86_l_1dd;
	case 480ULL: goto x86_l_1e0;
	case 486ULL: goto x86_l_1e6;
	case 489ULL: goto x86_l_1e9;
	case 495ULL: goto x86_l_1ef;
	case 498ULL: goto x86_l_1f2;
	case 504ULL: goto x86_l_1f8;
	case 507ULL: goto x86_l_1fb;
	case 513ULL: goto x86_l_201;
	case 517ULL: goto x86_l_205;
	case 522ULL: goto x86_l_20a;
	case 524ULL: goto x86_l_20c;
	case 530ULL: goto x86_l_212;
	case 533ULL: goto x86_l_215;
	case 536ULL: goto x86_l_218;
	case 542ULL: goto x86_l_21e;
	case 545ULL: goto x86_l_221;
	case 551ULL: goto x86_l_227;
	case 554ULL: goto x86_l_22a;
	case 560ULL: goto x86_l_230;
	case 563ULL: goto x86_l_233;
	case 569ULL: goto x86_l_239;
	case 573ULL: goto x86_l_23d;
	case 578ULL: goto x86_l_242;
	case 585ULL: goto x86_l_249;
	case 592ULL: goto x86_l_250;
	case 598ULL: goto x86_l_256;
	case 600ULL: goto x86_l_258;
	case 603ULL: goto x86_l_25b;
	case 609ULL: goto x86_l_261;
	case 612ULL: goto x86_l_264;
	case 618ULL: goto x86_l_26a;
	case 621ULL: goto x86_l_26d;
	case 627ULL: goto x86_l_273;
	case 632ULL: goto x86_l_278;
	case 635ULL: goto x86_l_27b;
	case 641ULL: goto x86_l_281;
	case 646ULL: goto x86_l_286;
	case 649ULL: goto x86_l_289;
	case 655ULL: goto x86_l_28f;
	case 658ULL: goto x86_l_292;
	case 664ULL: goto x86_l_298;
	case 669ULL: goto x86_l_29d;
	case 674ULL: goto x86_l_2a2;
	case 681ULL: goto x86_l_2a9;
	case 688ULL: goto x86_l_2b0;
	case 694ULL: goto x86_l_2b6;
	case 696ULL: goto x86_l_2b8;
	case 699ULL: goto x86_l_2bb;
	case 705ULL: goto x86_l_2c1;
	case 708ULL: goto x86_l_2c4;
	case 714ULL: goto x86_l_2ca;
	case 717ULL: goto x86_l_2cd;
	case 723ULL: goto x86_l_2d3;
	case 728ULL: goto x86_l_2d8;
	case 731ULL: goto x86_l_2db;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 745ULL: goto x86_l_2e9;
	case 751ULL: goto x86_l_2ef;
	case 756ULL: goto x86_l_2f4;
	case 759ULL: goto x86_l_2f7;
	case 765ULL: goto x86_l_2fd;
	case 770ULL: goto x86_l_302;
	case 777ULL: goto x86_l_309;
	case 784ULL: goto x86_l_310;
	case 790ULL: goto x86_l_316;
	case 792ULL: goto x86_l_318;
	case 795ULL: goto x86_l_31b;
	case 801ULL: goto x86_l_321;
	case 804ULL: goto x86_l_324;
	case 810ULL: goto x86_l_32a;
	case 813ULL: goto x86_l_32d;
	case 819ULL: goto x86_l_333;
	case 824ULL: goto x86_l_338;
	case 827ULL: goto x86_l_33b;
	case 833ULL: goto x86_l_341;
	case 838ULL: goto x86_l_346;
	case 841ULL: goto x86_l_349;
	case 847ULL: goto x86_l_34f;
	case 852ULL: goto x86_l_354;
	case 855ULL: goto x86_l_357;
	case 861ULL: goto x86_l_35d;
	case 866ULL: goto x86_l_362;
	case 873ULL: goto x86_l_369;
	case 880ULL: goto x86_l_370;
	case 886ULL: goto x86_l_376;
	case 888ULL: goto x86_l_378;
	case 891ULL: goto x86_l_37b;
	case 897ULL: goto x86_l_381;
	case 900ULL: goto x86_l_384;
	case 906ULL: goto x86_l_38a;
	case 909ULL: goto x86_l_38d;
	case 915ULL: goto x86_l_393;
	case 920ULL: goto x86_l_398;
	case 923ULL: goto x86_l_39b;
	case 929ULL: goto x86_l_3a1;
	case 934ULL: goto x86_l_3a6;
	case 937ULL: goto x86_l_3a9;
	case 943ULL: goto x86_l_3af;
	case 948ULL: goto x86_l_3b4;
	case 951ULL: goto x86_l_3b7;
	case 957ULL: goto x86_l_3bd;
	case 962ULL: goto x86_l_3c2;
	case 969ULL: goto x86_l_3c9;
	case 976ULL: goto x86_l_3d0;
	case 982ULL: goto x86_l_3d6;
	case 984ULL: goto x86_l_3d8;
	case 987ULL: goto x86_l_3db;
	case 993ULL: goto x86_l_3e1;
	case 996ULL: goto x86_l_3e4;
	case 1002ULL: goto x86_l_3ea;
	case 1005ULL: goto x86_l_3ed;
	case 1011ULL: goto x86_l_3f3;
	case 1016ULL: goto x86_l_3f8;
	case 1019ULL: goto x86_l_3fb;
	case 1025ULL: goto x86_l_401;
	case 1030ULL: goto x86_l_406;
	case 1033ULL: goto x86_l_409;
	case 1039ULL: goto x86_l_40f;
	case 1044ULL: goto x86_l_414;
	case 1047ULL: goto x86_l_417;
	case 1053ULL: goto x86_l_41d;
	case 1058ULL: goto x86_l_422;
	case 1061ULL: goto x86_l_425;
	case 1067ULL: goto x86_l_42b;
	case 1070ULL: goto x86_l_42e;
	case 1076ULL: goto x86_l_434;
	case 1079ULL: goto x86_l_437;
	case 1081ULL: goto x86_l_439;
	case 1087ULL: goto x86_l_43f;
	case 1092ULL: goto x86_l_444;
	case 1095ULL: goto x86_l_447;
	case 1101ULL: goto x86_l_44d;
	case 1106ULL: goto x86_l_452;
	case 1109ULL: goto x86_l_455;
	case 1115ULL: goto x86_l_45b;
	case 1118ULL: goto x86_l_45e;
	case 1124ULL: goto x86_l_464;
	case 1126ULL: goto x86_l_466;
	case 1132ULL: goto x86_l_46c;
	case 1137ULL: goto x86_l_471;
	case 1140ULL: goto x86_l_474;
	case 1146ULL: goto x86_l_47a;
	case 1151ULL: goto x86_l_47f;
	case 1154ULL: goto x86_l_482;
	case 1160ULL: goto x86_l_488;
	case 1163ULL: goto x86_l_48b;
	case 1169ULL: goto x86_l_491;
	case 1171ULL: goto x86_l_493;
	case 1177ULL: goto x86_l_499;
	case 1182ULL: goto x86_l_49e;
	case 1185ULL: goto x86_l_4a1;
	case 1191ULL: goto x86_l_4a7;
	case 1196ULL: goto x86_l_4ac;
	case 1199ULL: goto x86_l_4af;
	case 1205ULL: goto x86_l_4b5;
	case 1208ULL: goto x86_l_4b8;
	case 1214ULL: goto x86_l_4be;
	case 1216ULL: goto x86_l_4c0;
	case 1222ULL: goto x86_l_4c6;
	case 1227ULL: goto x86_l_4cb;
	case 1230ULL: goto x86_l_4ce;
	case 1236ULL: goto x86_l_4d4;
	case 1241ULL: goto x86_l_4d9;
	case 1244ULL: goto x86_l_4dc;
	case 1250ULL: goto x86_l_4e2;
	case 1253ULL: goto x86_l_4e5;
	case 1259ULL: goto x86_l_4eb;
	case 1261ULL: goto x86_l_4ed;
	case 1267ULL: goto x86_l_4f3;
	case 1270ULL: goto x86_l_4f6;
	case 1275ULL: goto x86_l_4fb;
	case 1281ULL: goto x86_l_501;
	case 1286ULL: goto x86_l_506;
	case 1288ULL: goto x86_l_508;
	case 1294ULL: goto x86_l_50e;
	case 1297ULL: goto x86_l_511;
	case 1303ULL: goto x86_l_517;
	case 1307ULL: goto x86_l_51b;
	case 1312ULL: goto x86_l_520;
	case 1314ULL: goto x86_l_522;
	case 1320ULL: goto x86_l_528;
	case 1323ULL: goto x86_l_52b;
	case 1329ULL: goto x86_l_531;
	case 1333ULL: goto x86_l_535;
	case 1338ULL: goto x86_l_53a;
	case 1340ULL: goto x86_l_53c;
	case 1346ULL: goto x86_l_542;
	case 1349ULL: goto x86_l_545;
	case 1355ULL: goto x86_l_54b;
	case 1359ULL: goto x86_l_54f;
	case 1364ULL: goto x86_l_554;
	case 1366ULL: goto x86_l_556;
	case 1372ULL: goto x86_l_55c;
	case 1375ULL: goto x86_l_55f;
	case 1381ULL: goto x86_l_565;
	case 1385ULL: goto x86_l_569;
	case 1390ULL: goto x86_l_56e;
	case 1392ULL: goto x86_l_570;
	case 1398ULL: goto x86_l_576;
	case 1401ULL: goto x86_l_579;
	case 1407ULL: goto x86_l_57f;
	case 1411ULL: goto x86_l_583;
	case 1416ULL: goto x86_l_588;
	case 1419ULL: goto x86_l_58b;
	case 1425ULL: goto x86_l_591;
	case 1433ULL: goto x86_l_599;
	case 1436ULL: goto x86_l_59c;
	case 1442ULL: goto x86_l_5a2;
	case 1445ULL: goto x86_l_5a5;
	case 1448ULL: goto x86_l_5a8;
	case 1454ULL: goto x86_l_5ae;
	case 1459ULL: goto x86_l_5b3;
	case 1462ULL: goto x86_l_5b6;
	case 1468ULL: goto x86_l_5bc;
	case 1476ULL: goto x86_l_5c4;
	case 1479ULL: goto x86_l_5c7;
	case 1485ULL: goto x86_l_5cd;
	case 1488ULL: goto x86_l_5d0;
	case 1491ULL: goto x86_l_5d3;
	case 1497ULL: goto x86_l_5d9;
	case 1502ULL: goto x86_l_5de;
	case 1505ULL: goto x86_l_5e1;
	case 1511ULL: goto x86_l_5e7;
	case 1519ULL: goto x86_l_5ef;
	case 1522ULL: goto x86_l_5f2;
	case 1528ULL: goto x86_l_5f8;
	case 1531ULL: goto x86_l_5fb;
	case 1534ULL: goto x86_l_5fe;
	case 1540ULL: goto x86_l_604;
	case 1545ULL: goto x86_l_609;
	case 1548ULL: goto x86_l_60c;
	case 1554ULL: goto x86_l_612;
	case 1562ULL: goto x86_l_61a;
	case 1565ULL: goto x86_l_61d;
	case 1571ULL: goto x86_l_623;
	case 1574ULL: goto x86_l_626;
	case 1577ULL: goto x86_l_629;
	case 1583ULL: goto x86_l_62f;
	case 1588ULL: goto x86_l_634;
	case 1591ULL: goto x86_l_637;
	case 1597ULL: goto x86_l_63d;
	case 1605ULL: goto x86_l_645;
	case 1608ULL: goto x86_l_648;
	case 1614ULL: goto x86_l_64e;
	case 1617ULL: goto x86_l_651;
	case 1620ULL: goto x86_l_654;
	case 1626ULL: goto x86_l_65a;
	case 1631ULL: goto x86_l_65f;
	case 1634ULL: goto x86_l_662;
	case 1640ULL: goto x86_l_668;
	case 1648ULL: goto x86_l_670;
	case 1651ULL: goto x86_l_673;
	case 1657ULL: goto x86_l_679;
	case 1662ULL: goto x86_l_67e;
	case 1665ULL: goto x86_l_681;
	case 1671ULL: goto x86_l_687;
	case 1676ULL: goto x86_l_68c;
	case 1679ULL: goto x86_l_68f;
	case 1685ULL: goto x86_l_695;
	case 1693ULL: goto x86_l_69d;
	case 1696ULL: goto x86_l_6a0;
	case 1702ULL: goto x86_l_6a6;
	case 1707ULL: goto x86_l_6ab;
	case 1710ULL: goto x86_l_6ae;
	case 1716ULL: goto x86_l_6b4;
	case 1721ULL: goto x86_l_6b9;
	case 1724ULL: goto x86_l_6bc;
	case 1730ULL: goto x86_l_6c2;
	case 1738ULL: goto x86_l_6ca;
	case 1741ULL: goto x86_l_6cd;
	case 1747ULL: goto x86_l_6d3;
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
	/* 0xa: sub    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 168ULL);
x86_l_11:
	/* 0x11: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
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
	/* 0x38: je     112 <generic_sleepable_preload+0x112> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_112;
	}
x86_l_3e:
	/* 0x3e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: lea    rax,[r14+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_48:
	/* 0x48: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4d:
	/* 0x4d: lea    rax,[r14+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_54:
	/* 0x54: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_59:
	/* 0x59: lea    rax,[r14+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5d:
	/* 0x5d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_62:
	/* 0x62: lea    r12,[r14+0x68] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_66:
	/* 0x66: lea    rax,[r14+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6a:
	/* 0x6a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6f:
	/* 0x6f: lea    rbp,[r14+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_73:
	/* 0x73: lea    rax,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_77:
	/* 0x77: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_7f:
	/* 0x7f: lea    r13,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_83:
	/* 0x83: lea    rax,[r14+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_87:
	/* 0x87: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8f:
	/* 0x8f: lea    rax,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_93:
	/* 0x93: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_98:
	/* 0x98: lea    rax,[r14+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9c:
	/* 0x9c: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_a4:
	/* 0xa4: lea    rax,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a8:
	/* 0xa8: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ad:
	/* 0xad: lea    rax,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b1:
	/* 0xb1: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b9:
	/* 0xb9: lea    rax,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bd:
	/* 0xbd: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c2:
	/* 0xc2: lea    rax,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c6:
	/* 0xc6: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_cb:
	/* 0xcb: lea    rax,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf:
	/* 0xcf: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d4:
	/* 0xd4: mov    eax,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d7:
	/* 0xd7: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_dc:
	/* 0xdc: jne    12a <generic_sleepable_preload+0x12a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12a;
	}
x86_l_de:
	/* 0xde: mov    eax,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e1:
	/* 0xe1: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_e6:
	/* 0xe6: jne    162 <generic_sleepable_preload+0x162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_162;
	}
x86_l_e8:
	/* 0xe8: mov    eax,DWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_eb:
	/* 0xeb: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_f0:
	/* 0xf0: jne    19a <generic_sleepable_preload+0x19a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19a;
	}
x86_l_f6:
	/* 0xf6: mov    eax,DWORD PTR [rbx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f9:
	/* 0xf9: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_fe:
	/* 0xfe: jne    1d2 <generic_sleepable_preload+0x1d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d2;
	}
x86_l_104:
	/* 0x104: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_107:
	/* 0x107: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_10c:
	/* 0x10c: jne    20a <generic_sleepable_preload+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20a;
	}
x86_l_112:
	/* 0x112: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_114:
	/* 0x114: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_11b:
	/* 0x11b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_11c:
	/* 0x11c: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_11e:
	/* 0x11e: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_120:
	/* 0x120: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_122:
	/* 0x122: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_124:
	/* 0x124: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_125:
	/* 0x125: jmp    3568 <generic_sleepable_preload+0x3568> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_12a:
	/* 0x12a: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_12c:
	/* 0x12c: js     242 <generic_sleepable_preload+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_242;
	}
x86_l_132:
	/* 0x132: mov    eax,DWORD PTR [rbx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_135:
	/* 0x135: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_138:
	/* 0x138: jle    506 <generic_sleepable_preload+0x506> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_506;
	}
x86_l_13e:
	/* 0x13e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_141:
	/* 0x141: je     740 <generic_sleepable_preload+0x740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1856ULL;
	}
x86_l_147:
	/* 0x147: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_14a:
	/* 0x14a: je     76f <generic_sleepable_preload+0x76f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1903ULL;
	}
x86_l_150:
	/* 0x150: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_153:
	/* 0x153: jne    7a6 <generic_sleepable_preload+0x7a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1958ULL;
	}
x86_l_159:
	/* 0x159: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15d:
	/* 0x15d: jmp    7a1 <generic_sleepable_preload+0x7a1> */
	return 1953ULL;
x86_l_162:
	/* 0x162: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_164:
	/* 0x164: js     2a2 <generic_sleepable_preload+0x2a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a2;
	}
x86_l_16a:
	/* 0x16a: mov    eax,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_16d:
	/* 0x16d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_170:
	/* 0x170: jle    520 <generic_sleepable_preload+0x520> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_520;
	}
x86_l_176:
	/* 0x176: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_179:
	/* 0x179: je     747 <generic_sleepable_preload+0x747> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1863ULL;
	}
x86_l_17f:
	/* 0x17f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_182:
	/* 0x182: je     775 <generic_sleepable_preload+0x775> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1909ULL;
	}
x86_l_188:
	/* 0x188: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18b:
	/* 0x18b: jne    aa9 <generic_sleepable_preload+0xaa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2729ULL;
	}
x86_l_191:
	/* 0x191: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_195:
	/* 0x195: jmp    aa4 <generic_sleepable_preload+0xaa4> */
	return 2724ULL;
x86_l_19a:
	/* 0x19a: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_19c:
	/* 0x19c: js     302 <generic_sleepable_preload+0x302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_302;
	}
x86_l_1a2:
	/* 0x1a2: mov    eax,DWORD PTR [rbx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a5:
	/* 0x1a5: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a8:
	/* 0x1a8: jle    53a <generic_sleepable_preload+0x53a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_53a;
	}
x86_l_1ae:
	/* 0x1ae: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b1:
	/* 0x1b1: je     751 <generic_sleepable_preload+0x751> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1873ULL;
	}
x86_l_1b7:
	/* 0x1b7: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1ba:
	/* 0x1ba: je     77e <generic_sleepable_preload+0x77e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1918ULL;
	}
x86_l_1c0:
	/* 0x1c0: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c3:
	/* 0x1c3: jne    dbe <generic_sleepable_preload+0xdbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3518ULL;
	}
x86_l_1c9:
	/* 0x1c9: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cd:
	/* 0x1cd: jmp    db9 <generic_sleepable_preload+0xdb9> */
	return 3513ULL;
x86_l_1d2:
	/* 0x1d2: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1d4:
	/* 0x1d4: js     362 <generic_sleepable_preload+0x362> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_362;
	}
x86_l_1da:
	/* 0x1da: mov    eax,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1dd:
	/* 0x1dd: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e0:
	/* 0x1e0: jle    554 <generic_sleepable_preload+0x554> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_554;
	}
x86_l_1e6:
	/* 0x1e6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e9:
	/* 0x1e9: je     75b <generic_sleepable_preload+0x75b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1883ULL;
	}
x86_l_1ef:
	/* 0x1ef: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1f2:
	/* 0x1f2: je     787 <generic_sleepable_preload+0x787> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1927ULL;
	}
x86_l_1f8:
	/* 0x1f8: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fb:
	/* 0x1fb: jne    10d3 <generic_sleepable_preload+0x10d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4307ULL;
	}
x86_l_201:
	/* 0x201: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_205:
	/* 0x205: jmp    10ce <generic_sleepable_preload+0x10ce> */
	return 4302ULL;
x86_l_20a:
	/* 0x20a: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_20c:
	/* 0x20c: js     3c2 <generic_sleepable_preload+0x3c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c2;
	}
x86_l_212:
	/* 0x212: mov    eax,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_215:
	/* 0x215: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_218:
	/* 0x218: jle    56e <generic_sleepable_preload+0x56e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_56e;
	}
x86_l_21e:
	/* 0x21e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_221:
	/* 0x221: je     765 <generic_sleepable_preload+0x765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1893ULL;
	}
x86_l_227:
	/* 0x227: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_22a:
	/* 0x22a: je     790 <generic_sleepable_preload+0x790> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1936ULL;
	}
x86_l_230:
	/* 0x230: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_233:
	/* 0x233: jne    13e8 <generic_sleepable_preload+0x13e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5096ULL;
	}
x86_l_239:
	/* 0x239: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23d:
	/* 0x23d: jmp    13e3 <generic_sleepable_preload+0x13e3> */
	return 5091ULL;
x86_l_242:
	/* 0x242: movzx  eax,BYTE PTR [rbx+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_249:
	/* 0x249: movzx  ecx,WORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_250:
	/* 0x250: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_256:
	/* 0x256: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_258:
	/* 0x258: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_25b:
	/* 0x25b: jle    422 <generic_sleepable_preload+0x422> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_422;
	}
x86_l_261:
	/* 0x261: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_264:
	/* 0x264: jle    588 <generic_sleepable_preload+0x588> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_588;
	}
x86_l_26a:
	/* 0x26a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_26d:
	/* 0x26d: jle    18f4 <generic_sleepable_preload+0x18f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6388ULL;
	}
x86_l_273:
	/* 0x273: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_278:
	/* 0x278: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_27b:
	/* 0x27b: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6406ULL;
	}
x86_l_281:
	/* 0x281: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_286:
	/* 0x286: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_289:
	/* 0x289: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6406ULL;
	}
x86_l_28f:
	/* 0x28f: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_292:
	/* 0x292: jne    1919 <generic_sleepable_preload+0x1919> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6425ULL;
	}
x86_l_298:
	/* 0x298: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_29d:
	/* 0x29d: jmp    1906 <generic_sleepable_preload+0x1906> */
	return 6406ULL;
x86_l_2a2:
	/* 0x2a2: movzx  eax,BYTE PTR [rbx+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_2a9:
	/* 0x2a9: movzx  ecx,WORD PTR [rbx+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_2b0:
	/* 0x2b0: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_2b6:
	/* 0x2b6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b8:
	/* 0x2b8: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_2bb:
	/* 0x2bb: jle    452 <generic_sleepable_preload+0x452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_452;
	}
x86_l_2c1:
	/* 0x2c1: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2c4:
	/* 0x2c4: jle    5b3 <generic_sleepable_preload+0x5b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5b3;
	}
x86_l_2ca:
	/* 0x2ca: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2cd:
	/* 0x2cd: jle    1c28 <generic_sleepable_preload+0x1c28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7208ULL;
	}
x86_l_2d3:
	/* 0x2d3: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d8:
	/* 0x2d8: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_2db:
	/* 0x2db: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_2e1:
	/* 0x2e1: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e6:
	/* 0x2e6: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_2e9:
	/* 0x2e9: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_2ef:
	/* 0x2ef: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2f4:
	/* 0x2f4: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2f7:
	/* 0x2f7: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_2fd:
	/* 0x2fd: jmp    2027 <generic_sleepable_preload+0x2027> */
	return 8231ULL;
x86_l_302:
	/* 0x302: movzx  eax,BYTE PTR [rbx+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_309:
	/* 0x309: movzx  ecx,WORD PTR [rbx+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_310:
	/* 0x310: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_316:
	/* 0x316: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_318:
	/* 0x318: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_31b:
	/* 0x31b: jle    47f <generic_sleepable_preload+0x47f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_47f;
	}
x86_l_321:
	/* 0x321: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_324:
	/* 0x324: jle    5de <generic_sleepable_preload+0x5de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5de;
	}
x86_l_32a:
	/* 0x32a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_32d:
	/* 0x32d: jle    1c47 <generic_sleepable_preload+0x1c47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7239ULL;
	}
x86_l_333:
	/* 0x333: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_338:
	/* 0x338: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_33b:
	/* 0x33b: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_341:
	/* 0x341: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_346:
	/* 0x346: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_349:
	/* 0x349: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_34f:
	/* 0x34f: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_354:
	/* 0x354: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_357:
	/* 0x357: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_35d:
	/* 0x35d: jmp    236b <generic_sleepable_preload+0x236b> */
	return 9067ULL;
x86_l_362:
	/* 0x362: movzx  eax,BYTE PTR [rbx+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_369:
	/* 0x369: movzx  ecx,WORD PTR [rbx+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_370:
	/* 0x370: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_376:
	/* 0x376: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_378:
	/* 0x378: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_37b:
	/* 0x37b: jle    4ac <generic_sleepable_preload+0x4ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4ac;
	}
x86_l_381:
	/* 0x381: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_384:
	/* 0x384: jle    609 <generic_sleepable_preload+0x609> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_609;
	}
x86_l_38a:
	/* 0x38a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_38d:
	/* 0x38d: jle    1c66 <generic_sleepable_preload+0x1c66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7270ULL;
	}
x86_l_393:
	/* 0x393: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_398:
	/* 0x398: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_39b:
	/* 0x39b: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_3a1:
	/* 0x3a1: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3a6:
	/* 0x3a6: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_3a9:
	/* 0x3a9: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_3af:
	/* 0x3af: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3b4:
	/* 0x3b4: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_3b7:
	/* 0x3b7: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_3bd:
	/* 0x3bd: jmp    26af <generic_sleepable_preload+0x26af> */
	return 9903ULL;
x86_l_3c2:
	/* 0x3c2: movzx  eax,BYTE PTR [rbx+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_3c9:
	/* 0x3c9: movzx  ecx,WORD PTR [rbx+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_3d0:
	/* 0x3d0: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_3d6:
	/* 0x3d6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d8:
	/* 0x3d8: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3db:
	/* 0x3db: jle    4d9 <generic_sleepable_preload+0x4d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d9;
	}
x86_l_3e1:
	/* 0x3e1: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3e4:
	/* 0x3e4: jle    634 <generic_sleepable_preload+0x634> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_634;
	}
x86_l_3ea:
	/* 0x3ea: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3ed:
	/* 0x3ed: jle    1c85 <generic_sleepable_preload+0x1c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7301ULL;
	}
x86_l_3f3:
	/* 0x3f3: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3f8:
	/* 0x3f8: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3fb:
	/* 0x3fb: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7319ULL;
	}
x86_l_401:
	/* 0x401: mov    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_406:
	/* 0x406: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_409:
	/* 0x409: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7319ULL;
	}
x86_l_40f:
	/* 0x40f: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_414:
	/* 0x414: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_417:
	/* 0x417: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7319ULL;
	}
x86_l_41d:
	/* 0x41d: jmp    1caa <generic_sleepable_preload+0x1caa> */
	return 7338ULL;
x86_l_422:
	/* 0x422: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_425:
	/* 0x425: jg     65f <generic_sleepable_preload+0x65f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_65f;
	}
x86_l_42b:
	/* 0x42b: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_42e:
	/* 0x42e: jg     179b <generic_sleepable_preload+0x179b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6043ULL;
	}
x86_l_434:
	/* 0x434: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_437:
	/* 0x437: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_439:
	/* 0x439: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6406ULL;
	}
x86_l_43f:
	/* 0x43f: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_444:
	/* 0x444: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_447:
	/* 0x447: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6406ULL;
	}
x86_l_44d:
	/* 0x44d: jmp    1919 <generic_sleepable_preload+0x1919> */
	return 6425ULL;
x86_l_452:
	/* 0x452: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_455:
	/* 0x455: jg     68c <generic_sleepable_preload+0x68c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_68c;
	}
x86_l_45b:
	/* 0x45b: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_45e:
	/* 0x45e: jg     17bc <generic_sleepable_preload+0x17bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6076ULL;
	}
x86_l_464:
	/* 0x464: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_466:
	/* 0x466: je     2011 <generic_sleepable_preload+0x2011> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8209ULL;
	}
x86_l_46c:
	/* 0x46c: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_471:
	/* 0x471: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_474:
	/* 0x474: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_47a:
	/* 0x47a: jmp    2027 <generic_sleepable_preload+0x2027> */
	return 8231ULL;
x86_l_47f:
	/* 0x47f: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_482:
	/* 0x482: jg     6b9 <generic_sleepable_preload+0x6b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6b9;
	}
x86_l_488:
	/* 0x488: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_48b:
	/* 0x48b: jg     17dd <generic_sleepable_preload+0x17dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6109ULL;
	}
x86_l_491:
	/* 0x491: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_493:
	/* 0x493: je     2355 <generic_sleepable_preload+0x2355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9045ULL;
	}
x86_l_499:
	/* 0x499: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_49e:
	/* 0x49e: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4a1:
	/* 0x4a1: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_4a7:
	/* 0x4a7: jmp    236b <generic_sleepable_preload+0x236b> */
	return 9067ULL;
x86_l_4ac:
	/* 0x4ac: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4af:
	/* 0x4af: jg     6e6 <generic_sleepable_preload+0x6e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1766ULL;
	}
x86_l_4b5:
	/* 0x4b5: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4b8:
	/* 0x4b8: jg     17fe <generic_sleepable_preload+0x17fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6142ULL;
	}
x86_l_4be:
	/* 0x4be: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4c0:
	/* 0x4c0: je     2699 <generic_sleepable_preload+0x2699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9881ULL;
	}
x86_l_4c6:
	/* 0x4c6: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4cb:
	/* 0x4cb: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4ce:
	/* 0x4ce: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_4d4:
	/* 0x4d4: jmp    26af <generic_sleepable_preload+0x26af> */
	return 9903ULL;
x86_l_4d9:
	/* 0x4d9: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4dc:
	/* 0x4dc: jg     713 <generic_sleepable_preload+0x713> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1811ULL;
	}
x86_l_4e2:
	/* 0x4e2: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4e5:
	/* 0x4e5: jg     181f <generic_sleepable_preload+0x181f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6175ULL;
	}
x86_l_4eb:
	/* 0x4eb: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4ed:
	/* 0x4ed: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7319ULL;
	}
x86_l_4f3:
	/* 0x4f3: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4f6:
	/* 0x4f6: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4fb:
	/* 0x4fb: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7319ULL;
	}
x86_l_501:
	/* 0x501: jmp    1caa <generic_sleepable_preload+0x1caa> */
	return 7338ULL;
x86_l_506:
	/* 0x506: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_508:
	/* 0x508: je     799 <generic_sleepable_preload+0x799> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1945ULL;
	}
x86_l_50e:
	/* 0x50e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_511:
	/* 0x511: jne    7a6 <generic_sleepable_preload+0x7a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1958ULL;
	}
x86_l_517:
	/* 0x517: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51b:
	/* 0x51b: jmp    7a1 <generic_sleepable_preload+0x7a1> */
	return 1953ULL;
x86_l_520:
	/* 0x520: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_522:
	/* 0x522: je     a9c <generic_sleepable_preload+0xa9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2716ULL;
	}
x86_l_528:
	/* 0x528: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_52b:
	/* 0x52b: jne    aa9 <generic_sleepable_preload+0xaa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2729ULL;
	}
x86_l_531:
	/* 0x531: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_535:
	/* 0x535: jmp    aa4 <generic_sleepable_preload+0xaa4> */
	return 2724ULL;
x86_l_53a:
	/* 0x53a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_53c:
	/* 0x53c: je     db1 <generic_sleepable_preload+0xdb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3505ULL;
	}
x86_l_542:
	/* 0x542: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_545:
	/* 0x545: jne    dbe <generic_sleepable_preload+0xdbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3518ULL;
	}
x86_l_54b:
	/* 0x54b: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54f:
	/* 0x54f: jmp    db9 <generic_sleepable_preload+0xdb9> */
	return 3513ULL;
x86_l_554:
	/* 0x554: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_556:
	/* 0x556: je     10c6 <generic_sleepable_preload+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4294ULL;
	}
x86_l_55c:
	/* 0x55c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_55f:
	/* 0x55f: jne    10d3 <generic_sleepable_preload+0x10d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4307ULL;
	}
x86_l_565:
	/* 0x565: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_569:
	/* 0x569: jmp    10ce <generic_sleepable_preload+0x10ce> */
	return 4302ULL;
x86_l_56e:
	/* 0x56e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_570:
	/* 0x570: je     13db <generic_sleepable_preload+0x13db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5083ULL;
	}
x86_l_576:
	/* 0x576: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_579:
	/* 0x579: jne    13e8 <generic_sleepable_preload+0x13e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5096ULL;
	}
x86_l_57f:
	/* 0x57f: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_583:
	/* 0x583: jmp    13e3 <generic_sleepable_preload+0x13e3> */
	return 5091ULL;
x86_l_588:
	/* 0x588: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_58b:
	/* 0x58b: jg     16f1 <generic_sleepable_preload+0x16f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5873ULL;
	}
x86_l_591:
	/* 0x591: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_599:
	/* 0x599: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59c:
	/* 0x59c: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6406ULL;
	}
x86_l_5a2:
	/* 0x5a2: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_5a5:
	/* 0x5a5: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5a8:
	/* 0x5a8: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6406ULL;
	}
x86_l_5ae:
	/* 0x5ae: jmp    1919 <generic_sleepable_preload+0x1919> */
	return 6425ULL;
x86_l_5b3:
	/* 0x5b3: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5b6:
	/* 0x5b6: jg     1713 <generic_sleepable_preload+0x1713> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5907ULL;
	}
x86_l_5bc:
	/* 0x5bc: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5c4:
	/* 0x5c4: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c7:
	/* 0x5c7: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_5cd:
	/* 0x5cd: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_5d0:
	/* 0x5d0: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5d3:
	/* 0x5d3: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_5d9:
	/* 0x5d9: jmp    2027 <generic_sleepable_preload+0x2027> */
	return 8231ULL;
x86_l_5de:
	/* 0x5de: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5e1:
	/* 0x5e1: jg     1735 <generic_sleepable_preload+0x1735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5941ULL;
	}
x86_l_5e7:
	/* 0x5e7: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5ef:
	/* 0x5ef: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f2:
	/* 0x5f2: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_5f8:
	/* 0x5f8: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_5fb:
	/* 0x5fb: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5fe:
	/* 0x5fe: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_604:
	/* 0x604: jmp    236b <generic_sleepable_preload+0x236b> */
	return 9067ULL;
x86_l_609:
	/* 0x609: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_60c:
	/* 0x60c: jg     1757 <generic_sleepable_preload+0x1757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5975ULL;
	}
x86_l_612:
	/* 0x612: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_61a:
	/* 0x61a: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_61d:
	/* 0x61d: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_623:
	/* 0x623: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_626:
	/* 0x626: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_629:
	/* 0x629: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_62f:
	/* 0x62f: jmp    26af <generic_sleepable_preload+0x26af> */
	return 9903ULL;
x86_l_634:
	/* 0x634: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_637:
	/* 0x637: jg     1779 <generic_sleepable_preload+0x1779> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6009ULL;
	}
x86_l_63d:
	/* 0x63d: mov    r14,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_645:
	/* 0x645: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_648:
	/* 0x648: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7319ULL;
	}
x86_l_64e:
	/* 0x64e: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_651:
	/* 0x651: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_654:
	/* 0x654: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7319ULL;
	}
x86_l_65a:
	/* 0x65a: jmp    1caa <generic_sleepable_preload+0x1caa> */
	return 7338ULL;
x86_l_65f:
	/* 0x65f: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_662:
	/* 0x662: jg     1840 <generic_sleepable_preload+0x1840> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6208ULL;
	}
x86_l_668:
	/* 0x668: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_670:
	/* 0x670: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_673:
	/* 0x673: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6406ULL;
	}
x86_l_679:
	/* 0x679: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_67e:
	/* 0x67e: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_681:
	/* 0x681: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6406ULL;
	}
x86_l_687:
	/* 0x687: jmp    1919 <generic_sleepable_preload+0x1919> */
	return 6425ULL;
x86_l_68c:
	/* 0x68c: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_68f:
	/* 0x68f: jg     1864 <generic_sleepable_preload+0x1864> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6244ULL;
	}
x86_l_695:
	/* 0x695: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_69d:
	/* 0x69d: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_6a0:
	/* 0x6a0: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_6a6:
	/* 0x6a6: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6ab:
	/* 0x6ab: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6ae:
	/* 0x6ae: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_6b4:
	/* 0x6b4: jmp    2027 <generic_sleepable_preload+0x2027> */
	return 8231ULL;
x86_l_6b9:
	/* 0x6b9: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6bc:
	/* 0x6bc: jg     1888 <generic_sleepable_preload+0x1888> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6280ULL;
	}
x86_l_6c2:
	/* 0x6c2: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6ca:
	/* 0x6ca: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_6cd:
	/* 0x6cd: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_6d3:
	/* 0x6d3: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
	return 1752ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1752ULL: goto x86_l_6d8;
	case 1755ULL: goto x86_l_6db;
	case 1761ULL: goto x86_l_6e1;
	case 1766ULL: goto x86_l_6e6;
	case 1769ULL: goto x86_l_6e9;
	case 1775ULL: goto x86_l_6ef;
	case 1783ULL: goto x86_l_6f7;
	case 1786ULL: goto x86_l_6fa;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	case 1800ULL: goto x86_l_708;
	case 1806ULL: goto x86_l_70e;
	case 1811ULL: goto x86_l_713;
	case 1814ULL: goto x86_l_716;
	case 1820ULL: goto x86_l_71c;
	case 1828ULL: goto x86_l_724;
	case 1831ULL: goto x86_l_727;
	case 1837ULL: goto x86_l_72d;
	case 1842ULL: goto x86_l_732;
	case 1845ULL: goto x86_l_735;
	case 1851ULL: goto x86_l_73b;
	case 1856ULL: goto x86_l_740;
	case 1861ULL: goto x86_l_745;
	case 1863ULL: goto x86_l_747;
	case 1868ULL: goto x86_l_74c;
	case 1873ULL: goto x86_l_751;
	case 1878ULL: goto x86_l_756;
	case 1883ULL: goto x86_l_75b;
	case 1888ULL: goto x86_l_760;
	case 1893ULL: goto x86_l_765;
	case 1898ULL: goto x86_l_76a;
	case 1903ULL: goto x86_l_76f;
	case 1907ULL: goto x86_l_773;
	case 1909ULL: goto x86_l_775;
	case 1913ULL: goto x86_l_779;
	case 1918ULL: goto x86_l_77e;
	case 1922ULL: goto x86_l_782;
	case 1927ULL: goto x86_l_787;
	case 1931ULL: goto x86_l_78b;
	case 1936ULL: goto x86_l_790;
	case 1940ULL: goto x86_l_794;
	case 1945ULL: goto x86_l_799;
	case 1950ULL: goto x86_l_79e;
	case 1953ULL: goto x86_l_7a1;
	case 1958ULL: goto x86_l_7a6;
	case 1963ULL: goto x86_l_7ab;
	case 1969ULL: goto x86_l_7b1;
	case 1972ULL: goto x86_l_7b4;
	case 1975ULL: goto x86_l_7b7;
	case 1980ULL: goto x86_l_7bc;
	case 1985ULL: goto x86_l_7c1;
	case 1987ULL: goto x86_l_7c3;
	case 1992ULL: goto x86_l_7c8;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2012ULL: goto x86_l_7dc;
	case 2014ULL: goto x86_l_7de;
	case 2016ULL: goto x86_l_7e0;
	case 2022ULL: goto x86_l_7e6;
	case 2027ULL: goto x86_l_7eb;
	case 2033ULL: goto x86_l_7f1;
	case 2036ULL: goto x86_l_7f4;
	case 2041ULL: goto x86_l_7f9;
	case 2046ULL: goto x86_l_7fe;
	case 2051ULL: goto x86_l_803;
	case 2053ULL: goto x86_l_805;
	case 2058ULL: goto x86_l_80a;
	case 2063ULL: goto x86_l_80f;
	case 2068ULL: goto x86_l_814;
	case 2073ULL: goto x86_l_819;
	case 2078ULL: goto x86_l_81e;
	case 2080ULL: goto x86_l_820;
	case 2082ULL: goto x86_l_822;
	case 2088ULL: goto x86_l_828;
	case 2096ULL: goto x86_l_830;
	case 2102ULL: goto x86_l_836;
	case 2108ULL: goto x86_l_83c;
	case 2113ULL: goto x86_l_841;
	case 2118ULL: goto x86_l_846;
	case 2126ULL: goto x86_l_84e;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2138ULL: goto x86_l_85a;
	case 2143ULL: goto x86_l_85f;
	case 2148ULL: goto x86_l_864;
	case 2153ULL: goto x86_l_869;
	case 2155ULL: goto x86_l_86b;
	case 2157ULL: goto x86_l_86d;
	case 2163ULL: goto x86_l_873;
	case 2171ULL: goto x86_l_87b;
	case 2177ULL: goto x86_l_881;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2193ULL: goto x86_l_891;
	case 2201ULL: goto x86_l_899;
	case 2203ULL: goto x86_l_89b;
	case 2208ULL: goto x86_l_8a0;
	case 2213ULL: goto x86_l_8a5;
	case 2218ULL: goto x86_l_8aa;
	case 2223ULL: goto x86_l_8af;
	case 2228ULL: goto x86_l_8b4;
	case 2230ULL: goto x86_l_8b6;
	case 2232ULL: goto x86_l_8b8;
	case 2238ULL: goto x86_l_8be;
	case 2246ULL: goto x86_l_8c6;
	case 2252ULL: goto x86_l_8cc;
	case 2258ULL: goto x86_l_8d2;
	case 2263ULL: goto x86_l_8d7;
	case 2268ULL: goto x86_l_8dc;
	case 2276ULL: goto x86_l_8e4;
	case 2278ULL: goto x86_l_8e6;
	case 2283ULL: goto x86_l_8eb;
	case 2288ULL: goto x86_l_8f0;
	case 2293ULL: goto x86_l_8f5;
	case 2298ULL: goto x86_l_8fa;
	case 2303ULL: goto x86_l_8ff;
	case 2305ULL: goto x86_l_901;
	case 2307ULL: goto x86_l_903;
	case 2313ULL: goto x86_l_909;
	case 2321ULL: goto x86_l_911;
	case 2327ULL: goto x86_l_917;
	case 2333ULL: goto x86_l_91d;
	case 2338ULL: goto x86_l_922;
	case 2343ULL: goto x86_l_927;
	case 2351ULL: goto x86_l_92f;
	case 2353ULL: goto x86_l_931;
	case 2358ULL: goto x86_l_936;
	case 2363ULL: goto x86_l_93b;
	case 2368ULL: goto x86_l_940;
	case 2373ULL: goto x86_l_945;
	case 2378ULL: goto x86_l_94a;
	case 2380ULL: goto x86_l_94c;
	case 2382ULL: goto x86_l_94e;
	case 2388ULL: goto x86_l_954;
	case 2396ULL: goto x86_l_95c;
	case 2402ULL: goto x86_l_962;
	case 2408ULL: goto x86_l_968;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2426ULL: goto x86_l_97a;
	case 2428ULL: goto x86_l_97c;
	case 2433ULL: goto x86_l_981;
	case 2438ULL: goto x86_l_986;
	case 2443ULL: goto x86_l_98b;
	case 2448ULL: goto x86_l_990;
	case 2453ULL: goto x86_l_995;
	case 2455ULL: goto x86_l_997;
	case 2457ULL: goto x86_l_999;
	case 2463ULL: goto x86_l_99f;
	case 2471ULL: goto x86_l_9a7;
	case 2477ULL: goto x86_l_9ad;
	case 2483ULL: goto x86_l_9b3;
	case 2488ULL: goto x86_l_9b8;
	case 2493ULL: goto x86_l_9bd;
	case 2501ULL: goto x86_l_9c5;
	case 2503ULL: goto x86_l_9c7;
	case 2508ULL: goto x86_l_9cc;
	case 2513ULL: goto x86_l_9d1;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2530ULL: goto x86_l_9e2;
	case 2532ULL: goto x86_l_9e4;
	case 2538ULL: goto x86_l_9ea;
	case 2546ULL: goto x86_l_9f2;
	case 2552ULL: goto x86_l_9f8;
	case 2558ULL: goto x86_l_9fe;
	case 2563ULL: goto x86_l_a03;
	case 2568ULL: goto x86_l_a08;
	case 2576ULL: goto x86_l_a10;
	case 2578ULL: goto x86_l_a12;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2593ULL: goto x86_l_a21;
	case 2598ULL: goto x86_l_a26;
	case 2603ULL: goto x86_l_a2b;
	case 2605ULL: goto x86_l_a2d;
	case 2607ULL: goto x86_l_a2f;
	case 2613ULL: goto x86_l_a35;
	case 2621ULL: goto x86_l_a3d;
	case 2623ULL: goto x86_l_a3f;
	case 2629ULL: goto x86_l_a45;
	case 2634ULL: goto x86_l_a4a;
	case 2639ULL: goto x86_l_a4f;
	case 2647ULL: goto x86_l_a57;
	case 2649ULL: goto x86_l_a59;
	case 2654ULL: goto x86_l_a5e;
	case 2659ULL: goto x86_l_a63;
	case 2664ULL: goto x86_l_a68;
	case 2669ULL: goto x86_l_a6d;
	case 2674ULL: goto x86_l_a72;
	case 2676ULL: goto x86_l_a74;
	case 2678ULL: goto x86_l_a76;
	case 2684ULL: goto x86_l_a7c;
	case 2686ULL: goto x86_l_a7e;
	case 2690ULL: goto x86_l_a82;
	case 2698ULL: goto x86_l_a8a;
	case 2703ULL: goto x86_l_a8f;
	case 2711ULL: goto x86_l_a97;
	case 2716ULL: goto x86_l_a9c;
	case 2721ULL: goto x86_l_aa1;
	case 2724ULL: goto x86_l_aa4;
	case 2729ULL: goto x86_l_aa9;
	case 2737ULL: goto x86_l_ab1;
	case 2743ULL: goto x86_l_ab7;
	case 2749ULL: goto x86_l_abd;
	case 2752ULL: goto x86_l_ac0;
	case 2757ULL: goto x86_l_ac5;
	case 2765ULL: goto x86_l_acd;
	case 2767ULL: goto x86_l_acf;
	case 2772ULL: goto x86_l_ad4;
	case 2777ULL: goto x86_l_ad9;
	case 2782ULL: goto x86_l_ade;
	case 2787ULL: goto x86_l_ae3;
	case 2792ULL: goto x86_l_ae8;
	case 2794ULL: goto x86_l_aea;
	case 2796ULL: goto x86_l_aec;
	case 2802ULL: goto x86_l_af2;
	case 2810ULL: goto x86_l_afa;
	case 2816ULL: goto x86_l_b00;
	case 2822ULL: goto x86_l_b06;
	case 2827ULL: goto x86_l_b0b;
	case 2832ULL: goto x86_l_b10;
	case 2840ULL: goto x86_l_b18;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2852ULL: goto x86_l_b24;
	case 2857ULL: goto x86_l_b29;
	case 2862ULL: goto x86_l_b2e;
	case 2867ULL: goto x86_l_b33;
	case 2869ULL: goto x86_l_b35;
	case 2871ULL: goto x86_l_b37;
	case 2877ULL: goto x86_l_b3d;
	case 2885ULL: goto x86_l_b45;
	case 2891ULL: goto x86_l_b4b;
	case 2897ULL: goto x86_l_b51;
	case 2902ULL: goto x86_l_b56;
	case 2907ULL: goto x86_l_b5b;
	case 2915ULL: goto x86_l_b63;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2942ULL: goto x86_l_b7e;
	case 2944ULL: goto x86_l_b80;
	case 2946ULL: goto x86_l_b82;
	case 2952ULL: goto x86_l_b88;
	case 2960ULL: goto x86_l_b90;
	case 2966ULL: goto x86_l_b96;
	case 2972ULL: goto x86_l_b9c;
	case 2977ULL: goto x86_l_ba1;
	case 2982ULL: goto x86_l_ba6;
	case 2990ULL: goto x86_l_bae;
	case 2992ULL: goto x86_l_bb0;
	case 2997ULL: goto x86_l_bb5;
	case 3002ULL: goto x86_l_bba;
	case 3007ULL: goto x86_l_bbf;
	case 3012ULL: goto x86_l_bc4;
	case 3017ULL: goto x86_l_bc9;
	case 3019ULL: goto x86_l_bcb;
	case 3021ULL: goto x86_l_bcd;
	case 3027ULL: goto x86_l_bd3;
	case 3035ULL: goto x86_l_bdb;
	case 3041ULL: goto x86_l_be1;
	case 3047ULL: goto x86_l_be7;
	case 3052ULL: goto x86_l_bec;
	case 3057ULL: goto x86_l_bf1;
	case 3065ULL: goto x86_l_bf9;
	case 3067ULL: goto x86_l_bfb;
	case 3072ULL: goto x86_l_c00;
	case 3077ULL: goto x86_l_c05;
	case 3082ULL: goto x86_l_c0a;
	case 3087ULL: goto x86_l_c0f;
	case 3092ULL: goto x86_l_c14;
	case 3094ULL: goto x86_l_c16;
	case 3096ULL: goto x86_l_c18;
	case 3102ULL: goto x86_l_c1e;
	case 3110ULL: goto x86_l_c26;
	case 3116ULL: goto x86_l_c2c;
	case 3122ULL: goto x86_l_c32;
	case 3127ULL: goto x86_l_c37;
	case 3132ULL: goto x86_l_c3c;
	case 3140ULL: goto x86_l_c44;
	case 3142ULL: goto x86_l_c46;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3157ULL: goto x86_l_c55;
	case 3162ULL: goto x86_l_c5a;
	case 3167ULL: goto x86_l_c5f;
	case 3169ULL: goto x86_l_c61;
	case 3171ULL: goto x86_l_c63;
	case 3177ULL: goto x86_l_c69;
	case 3185ULL: goto x86_l_c71;
	case 3191ULL: goto x86_l_c77;
	case 3197ULL: goto x86_l_c7d;
	case 3202ULL: goto x86_l_c82;
	case 3207ULL: goto x86_l_c87;
	case 3215ULL: goto x86_l_c8f;
	case 3217ULL: goto x86_l_c91;
	case 3222ULL: goto x86_l_c96;
	case 3227ULL: goto x86_l_c9b;
	case 3232ULL: goto x86_l_ca0;
	case 3237ULL: goto x86_l_ca5;
	case 3242ULL: goto x86_l_caa;
	case 3244ULL: goto x86_l_cac;
	case 3246ULL: goto x86_l_cae;
	case 3252ULL: goto x86_l_cb4;
	case 3260ULL: goto x86_l_cbc;
	case 3266ULL: goto x86_l_cc2;
	case 3272ULL: goto x86_l_cc8;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3290ULL: goto x86_l_cda;
	case 3292ULL: goto x86_l_cdc;
	case 3297ULL: goto x86_l_ce1;
	case 3302ULL: goto x86_l_ce6;
	case 3307ULL: goto x86_l_ceb;
	case 3312ULL: goto x86_l_cf0;
	case 3317ULL: goto x86_l_cf5;
	case 3319ULL: goto x86_l_cf7;
	case 3321ULL: goto x86_l_cf9;
	case 3327ULL: goto x86_l_cff;
	case 3335ULL: goto x86_l_d07;
	case 3341ULL: goto x86_l_d0d;
	case 3347ULL: goto x86_l_d13;
	case 3352ULL: goto x86_l_d18;
	case 3357ULL: goto x86_l_d1d;
	case 3365ULL: goto x86_l_d25;
	case 3367ULL: goto x86_l_d27;
	case 3372ULL: goto x86_l_d2c;
	case 3377ULL: goto x86_l_d31;
	case 3382ULL: goto x86_l_d36;
	case 3387ULL: goto x86_l_d3b;
	case 3392ULL: goto x86_l_d40;
	case 3394ULL: goto x86_l_d42;
	case 3396ULL: goto x86_l_d44;
	case 3402ULL: goto x86_l_d4a;
	case 3410ULL: goto x86_l_d52;
	case 3412ULL: goto x86_l_d54;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3428ULL: goto x86_l_d64;
	case 3436ULL: goto x86_l_d6c;
	case 3438ULL: goto x86_l_d6e;
	case 3443ULL: goto x86_l_d73;
	case 3448ULL: goto x86_l_d78;
	case 3453ULL: goto x86_l_d7d;
	case 3458ULL: goto x86_l_d82;
	case 3463ULL: goto x86_l_d87;
	case 3465ULL: goto x86_l_d89;
	case 3467ULL: goto x86_l_d8b;
	case 3473ULL: goto x86_l_d91;
	case 3475ULL: goto x86_l_d93;
	case 3479ULL: goto x86_l_d97;
	case 3487ULL: goto x86_l_d9f;
	case 3492ULL: goto x86_l_da4;
	case 3500ULL: goto x86_l_dac;
	case 3505ULL: goto x86_l_db1;
	case 3510ULL: goto x86_l_db6;
	case 3513ULL: goto x86_l_db9;
	case 3518ULL: goto x86_l_dbe;
	case 3526ULL: goto x86_l_dc6;
	case 3532ULL: goto x86_l_dcc;
	case 3538ULL: goto x86_l_dd2;
	case 3541ULL: goto x86_l_dd5;
	case 3546ULL: goto x86_l_dda;
	case 3554ULL: goto x86_l_de2;
	case 3556ULL: goto x86_l_de4;
	case 3561ULL: goto x86_l_de9;
	case 3566ULL: goto x86_l_dee;
	case 3571ULL: goto x86_l_df3;
	case 3576ULL: goto x86_l_df8;
	case 3581ULL: goto x86_l_dfd;
	case 3583ULL: goto x86_l_dff;
	case 3585ULL: goto x86_l_e01;
	case 3591ULL: goto x86_l_e07;
	case 3599ULL: goto x86_l_e0f;
	case 3605ULL: goto x86_l_e15;
	case 3611ULL: goto x86_l_e1b;
	case 3616ULL: goto x86_l_e20;
	case 3621ULL: goto x86_l_e25;
	case 3629ULL: goto x86_l_e2d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6d8:
	/* 0x6d8: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6db:
	/* 0x6db: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_6e1:
	/* 0x6e1: jmp    236b <generic_sleepable_preload+0x236b> */
	return 9067ULL;
x86_l_6e6:
	/* 0x6e6: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6e9:
	/* 0x6e9: jg     18ac <generic_sleepable_preload+0x18ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6316ULL;
	}
x86_l_6ef:
	/* 0x6ef: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6f7:
	/* 0x6f7: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_6fa:
	/* 0x6fa: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_700:
	/* 0x700: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_705:
	/* 0x705: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_708:
	/* 0x708: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_70e:
	/* 0x70e: jmp    26af <generic_sleepable_preload+0x26af> */
	return 9903ULL;
x86_l_713:
	/* 0x713: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_716:
	/* 0x716: jg     18d0 <generic_sleepable_preload+0x18d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6352ULL;
	}
x86_l_71c:
	/* 0x71c: mov    r14,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_724:
	/* 0x724: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_727:
	/* 0x727: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7319ULL;
	}
x86_l_72d:
	/* 0x72d: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_732:
	/* 0x732: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_735:
	/* 0x735: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7319ULL;
	}
x86_l_73b:
	/* 0x73b: jmp    1caa <generic_sleepable_preload+0x1caa> */
	return 7338ULL;
x86_l_740:
	/* 0x740: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_745:
	/* 0x745: jmp    79e <generic_sleepable_preload+0x79e> */
	goto x86_l_79e;
x86_l_747:
	/* 0x747: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_74c:
	/* 0x74c: jmp    aa1 <generic_sleepable_preload+0xaa1> */
	goto x86_l_aa1;
x86_l_751:
	/* 0x751: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_756:
	/* 0x756: jmp    db6 <generic_sleepable_preload+0xdb6> */
	goto x86_l_db6;
x86_l_75b:
	/* 0x75b: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_760:
	/* 0x760: jmp    10cb <generic_sleepable_preload+0x10cb> */
	return 4299ULL;
x86_l_765:
	/* 0x765: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_76a:
	/* 0x76a: jmp    13e0 <generic_sleepable_preload+0x13e0> */
	return 5088ULL;
x86_l_76f:
	/* 0x76f: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_773:
	/* 0x773: jmp    7a1 <generic_sleepable_preload+0x7a1> */
	goto x86_l_7a1;
x86_l_775:
	/* 0x775: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_779:
	/* 0x779: jmp    aa4 <generic_sleepable_preload+0xaa4> */
	goto x86_l_aa4;
x86_l_77e:
	/* 0x77e: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_782:
	/* 0x782: jmp    db9 <generic_sleepable_preload+0xdb9> */
	goto x86_l_db9;
x86_l_787:
	/* 0x787: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_78b:
	/* 0x78b: jmp    10ce <generic_sleepable_preload+0x10ce> */
	return 4302ULL;
x86_l_790:
	/* 0x790: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_794:
	/* 0x794: jmp    13e3 <generic_sleepable_preload+0x13e3> */
	return 5091ULL;
x86_l_799:
	/* 0x799: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_79e:
	/* 0x79e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a1:
	/* 0x7a1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7a6:
	/* 0x7a6: cmp    WORD PTR [rbx+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_7ab:
	/* 0x7ab: je     a7c <generic_sleepable_preload+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7c;
	}
x86_l_7b1:
	/* 0x7b1: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7b4:
	/* 0x7b4: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_7b7:
	/* 0x7b7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7bc:
	/* 0x7bc: cmp    WORD PTR [rbx+0x74],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_7c1:
	/* 0x7c1: je     7e6 <generic_sleepable_preload+0x7e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e6;
	}
x86_l_7c3:
	/* 0x7c3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7c8:
	/* 0x7c8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_7cd:
	/* 0x7cd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7d2:
	/* 0x7d2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d7:
	/* 0x7d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7dc:
	/* 0x7dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7de:
	/* 0x7de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7e0:
	/* 0x7e0: js     a8f <generic_sleepable_preload+0xa8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a8f;
	}
x86_l_7e6:
	/* 0x7e6: cmp    WORD PTR [rbx+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_7eb:
	/* 0x7eb: je     a7c <generic_sleepable_preload+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7c;
	}
x86_l_7f1:
	/* 0x7f1: mov    ecx,DWORD PTR [rbx+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7f4:
	/* 0x7f4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_7f9:
	/* 0x7f9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7fe:
	/* 0x7fe: cmp    WORD PTR [rbx+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_803:
	/* 0x803: je     828 <generic_sleepable_preload+0x828> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_828;
	}
x86_l_805:
	/* 0x805: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_80a:
	/* 0x80a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_80f:
	/* 0x80f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_814:
	/* 0x814: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_819:
	/* 0x819: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_81e:
	/* 0x81e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_820:
	/* 0x820: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_822:
	/* 0x822: js     1fbc <generic_sleepable_preload+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8124ULL;
	}
x86_l_828:
	/* 0x828: cmp    WORD PTR [rbx+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_830:
	/* 0x830: je     a7c <generic_sleepable_preload+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7c;
	}
x86_l_836:
	/* 0x836: mov    ecx,DWORD PTR [rbx+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_83c:
	/* 0x83c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_841:
	/* 0x841: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_846:
	/* 0x846: cmp    WORD PTR [rbx+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_84e:
	/* 0x84e: je     873 <generic_sleepable_preload+0x873> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_873;
	}
x86_l_850:
	/* 0x850: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_855:
	/* 0x855: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_85a:
	/* 0x85a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_85f:
	/* 0x85f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_864:
	/* 0x864: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_869:
	/* 0x869: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86b:
	/* 0x86b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_86d:
	/* 0x86d: js     29dd <generic_sleepable_preload+0x29dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10717ULL;
	}
x86_l_873:
	/* 0x873: cmp    WORD PTR [rbx+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_87b:
	/* 0x87b: je     a7c <generic_sleepable_preload+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7c;
	}
x86_l_881:
	/* 0x881: mov    ecx,DWORD PTR [rbx+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_887:
	/* 0x887: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_88c:
	/* 0x88c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_891:
	/* 0x891: cmp    WORD PTR [rbx+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_899:
	/* 0x899: je     8be <generic_sleepable_preload+0x8be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8be;
	}
x86_l_89b:
	/* 0x89b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a0:
	/* 0x8a0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8a5:
	/* 0x8a5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8aa:
	/* 0x8aa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8af:
	/* 0x8af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8b4:
	/* 0x8b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b6:
	/* 0x8b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8b8:
	/* 0x8b8: js     2a59 <generic_sleepable_preload+0x2a59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10841ULL;
	}
x86_l_8be:
	/* 0x8be: cmp    WORD PTR [rbx+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_8c6:
	/* 0x8c6: je     a7c <generic_sleepable_preload+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7c;
	}
x86_l_8cc:
	/* 0x8cc: mov    ecx,DWORD PTR [rbx+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8d2:
	/* 0x8d2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_8d7:
	/* 0x8d7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8dc:
	/* 0x8dc: cmp    WORD PTR [rbx+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_8e4:
	/* 0x8e4: je     909 <generic_sleepable_preload+0x909> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_909;
	}
x86_l_8e6:
	/* 0x8e6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8eb:
	/* 0x8eb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8f0:
	/* 0x8f0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8f5:
	/* 0x8f5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x903: js     2ad5 <generic_sleepable_preload+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10965ULL;
	}
x86_l_909:
	/* 0x909: cmp    WORD PTR [rbx+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_911:
	/* 0x911: je     a7c <generic_sleepable_preload+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7c;
	}
x86_l_917:
	/* 0x917: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_91d:
	/* 0x91d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_922:
	/* 0x922: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_927:
	/* 0x927: cmp    WORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_92f:
	/* 0x92f: je     954 <generic_sleepable_preload+0x954> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_954;
	}
x86_l_931:
	/* 0x931: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_936:
	/* 0x936: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_93b:
	/* 0x93b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_940:
	/* 0x940: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_945:
	/* 0x945: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_94a:
	/* 0x94a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94c:
	/* 0x94c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_94e:
	/* 0x94e: js     2b51 <generic_sleepable_preload+0x2b51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11089ULL;
	}
x86_l_954:
	/* 0x954: cmp    WORD PTR [rbx+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_95c:
	/* 0x95c: je     a7c <generic_sleepable_preload+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7c;
	}
x86_l_962:
	/* 0x962: mov    ecx,DWORD PTR [rbx+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_968:
	/* 0x968: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_96d:
	/* 0x96d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_972:
	/* 0x972: cmp    WORD PTR [rbx+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_97a:
	/* 0x97a: je     99f <generic_sleepable_preload+0x99f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_99f;
	}
x86_l_97c:
	/* 0x97c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_981:
	/* 0x981: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_986:
	/* 0x986: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_98b:
	/* 0x98b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_990:
	/* 0x990: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_995:
	/* 0x995: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_997:
	/* 0x997: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_999:
	/* 0x999: js     2bca <generic_sleepable_preload+0x2bca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11210ULL;
	}
x86_l_99f:
	/* 0x99f: cmp    WORD PTR [rbx+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_9a7:
	/* 0x9a7: je     a7c <generic_sleepable_preload+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7c;
	}
x86_l_9ad:
	/* 0x9ad: mov    ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_9b3:
	/* 0x9b3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_9b8:
	/* 0x9b8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9bd:
	/* 0x9bd: cmp    WORD PTR [rbx+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_9c5:
	/* 0x9c5: je     9ea <generic_sleepable_preload+0x9ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9ea;
	}
x86_l_9c7:
	/* 0x9c7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9cc:
	/* 0x9cc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_9d1:
	/* 0x9d1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9d6:
	/* 0x9d6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9db:
	/* 0x9db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9e0:
	/* 0x9e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e2:
	/* 0x9e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9e4:
	/* 0x9e4: js     33c4 <generic_sleepable_preload+0x33c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13252ULL;
	}
x86_l_9ea:
	/* 0x9ea: cmp    WORD PTR [rbx+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_9f2:
	/* 0x9f2: je     a7c <generic_sleepable_preload+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7c;
	}
x86_l_9f8:
	/* 0x9f8: mov    ecx,DWORD PTR [rbx+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9fe:
	/* 0x9fe: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a03:
	/* 0xa03: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a08:
	/* 0xa08: cmp    WORD PTR [rbx+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_a10:
	/* 0xa10: je     a35 <generic_sleepable_preload+0xa35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a35;
	}
x86_l_a12:
	/* 0xa12: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a17:
	/* 0xa17: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a1c:
	/* 0xa1c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a21:
	/* 0xa21: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a26:
	/* 0xa26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a2b:
	/* 0xa2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2d:
	/* 0xa2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a2f:
	/* 0xa2f: js     34b8 <generic_sleepable_preload+0x34b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13496ULL;
	}
x86_l_a35:
	/* 0xa35: cmp    WORD PTR [rbx+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_a3d:
	/* 0xa3d: je     a7c <generic_sleepable_preload+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7c;
	}
x86_l_a3f:
	/* 0xa3f: mov    ecx,DWORD PTR [rbx+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_a45:
	/* 0xa45: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a4a:
	/* 0xa4a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a4f:
	/* 0xa4f: cmp    WORD PTR [rbx+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_a57:
	/* 0xa57: je     a7c <generic_sleepable_preload+0xa7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7c;
	}
x86_l_a59:
	/* 0xa59: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a5e:
	/* 0xa5e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a63:
	/* 0xa63: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a68:
	/* 0xa68: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a6d:
	/* 0xa6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a72:
	/* 0xa72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a74:
	/* 0xa74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a76:
	/* 0xa76: js     3534 <generic_sleepable_preload+0x3534> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13620ULL;
	}
x86_l_a7c:
	/* 0xa7c: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_a7e:
	/* 0xa7e: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_a82:
	/* 0xa82: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_a8a:
	/* 0xa8a: jmp    2bda <generic_sleepable_preload+0x2bda> */
	return 11226ULL;
x86_l_a8f:
	/* 0xa8f: mov    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_a97:
	/* 0xa97: jmp    2bd2 <generic_sleepable_preload+0x2bd2> */
	return 11218ULL;
x86_l_a9c:
	/* 0xa9c: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_aa1:
	/* 0xaa1: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aa4:
	/* 0xaa4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aa9:
	/* 0xaa9: cmp    WORD PTR [rbx+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_ab1:
	/* 0xab1: je     d91 <generic_sleepable_preload+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d91;
	}
x86_l_ab7:
	/* 0xab7: mov    eax,DWORD PTR [rbx+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_abd:
	/* 0xabd: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ac0:
	/* 0xac0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ac5:
	/* 0xac5: cmp    WORD PTR [rbx+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_acd:
	/* 0xacd: je     af2 <generic_sleepable_preload+0xaf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_af2;
	}
x86_l_acf:
	/* 0xacf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ad4:
	/* 0xad4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ad9:
	/* 0xad9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ade:
	/* 0xade: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ae3:
	/* 0xae3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ae8:
	/* 0xae8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aea:
	/* 0xaea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_aec:
	/* 0xaec: js     da4 <generic_sleepable_preload+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_da4;
	}
x86_l_af2:
	/* 0xaf2: cmp    WORD PTR [rbx+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_afa:
	/* 0xafa: je     d91 <generic_sleepable_preload+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d91;
	}
x86_l_b00:
	/* 0xb00: mov    ecx,DWORD PTR [rbx+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_b06:
	/* 0xb06: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b0b:
	/* 0xb0b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b10:
	/* 0xb10: cmp    WORD PTR [rbx+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_b18:
	/* 0xb18: je     b3d <generic_sleepable_preload+0xb3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b3d;
	}
x86_l_b1a:
	/* 0xb1a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b1f:
	/* 0xb1f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b24:
	/* 0xb24: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b29:
	/* 0xb29: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b2e:
	/* 0xb2e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b33:
	/* 0xb33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b35:
	/* 0xb35: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b37:
	/* 0xb37: js     1fc9 <generic_sleepable_preload+0x1fc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8137ULL;
	}
x86_l_b3d:
	/* 0xb3d: cmp    WORD PTR [rbx+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_b45:
	/* 0xb45: je     d91 <generic_sleepable_preload+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d91;
	}
x86_l_b4b:
	/* 0xb4b: mov    ecx,DWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_b51:
	/* 0xb51: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b56:
	/* 0xb56: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b5b:
	/* 0xb5b: cmp    WORD PTR [rbx+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_b63:
	/* 0xb63: je     b88 <generic_sleepable_preload+0xb88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b88;
	}
x86_l_b65:
	/* 0xb65: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b6a:
	/* 0xb6a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b6f:
	/* 0xb6f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b74:
	/* 0xb74: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b79:
	/* 0xb79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b7e:
	/* 0xb7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b80:
	/* 0xb80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b82:
	/* 0xb82: js     29ea <generic_sleepable_preload+0x29ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10730ULL;
	}
x86_l_b88:
	/* 0xb88: cmp    WORD PTR [rbx+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_b90:
	/* 0xb90: je     d91 <generic_sleepable_preload+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d91;
	}
x86_l_b96:
	/* 0xb96: mov    ecx,DWORD PTR [rbx+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_b9c:
	/* 0xb9c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ba1:
	/* 0xba1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ba6:
	/* 0xba6: cmp    WORD PTR [rbx+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_bae:
	/* 0xbae: je     bd3 <generic_sleepable_preload+0xbd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bd3;
	}
x86_l_bb0:
	/* 0xbb0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bb5:
	/* 0xbb5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_bba:
	/* 0xbba: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bbf:
	/* 0xbbf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bc4:
	/* 0xbc4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bc9:
	/* 0xbc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bcb:
	/* 0xbcb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bcd:
	/* 0xbcd: js     2a66 <generic_sleepable_preload+0x2a66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10854ULL;
	}
x86_l_bd3:
	/* 0xbd3: cmp    WORD PTR [rbx+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_bdb:
	/* 0xbdb: je     d91 <generic_sleepable_preload+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d91;
	}
x86_l_be1:
	/* 0xbe1: mov    ecx,DWORD PTR [rbx+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_be7:
	/* 0xbe7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_bec:
	/* 0xbec: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bf1:
	/* 0xbf1: cmp    WORD PTR [rbx+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_bf9:
	/* 0xbf9: je     c1e <generic_sleepable_preload+0xc1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c1e;
	}
x86_l_bfb:
	/* 0xbfb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c00:
	/* 0xc00: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c05:
	/* 0xc05: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c0a:
	/* 0xc0a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c0f:
	/* 0xc0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c14:
	/* 0xc14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c16:
	/* 0xc16: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c18:
	/* 0xc18: js     2ae2 <generic_sleepable_preload+0x2ae2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10978ULL;
	}
x86_l_c1e:
	/* 0xc1e: cmp    WORD PTR [rbx+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_c26:
	/* 0xc26: je     d91 <generic_sleepable_preload+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d91;
	}
x86_l_c2c:
	/* 0xc2c: mov    ecx,DWORD PTR [rbx+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_c32:
	/* 0xc32: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c37:
	/* 0xc37: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c3c:
	/* 0xc3c: cmp    WORD PTR [rbx+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_c44:
	/* 0xc44: je     c69 <generic_sleepable_preload+0xc69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c69;
	}
x86_l_c46:
	/* 0xc46: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c4b:
	/* 0xc4b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c50:
	/* 0xc50: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c55:
	/* 0xc55: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c5a:
	/* 0xc5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c5f:
	/* 0xc5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c61:
	/* 0xc61: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c63:
	/* 0xc63: js     2b5b <generic_sleepable_preload+0x2b5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11099ULL;
	}
x86_l_c69:
	/* 0xc69: cmp    WORD PTR [rbx+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_c71:
	/* 0xc71: je     d91 <generic_sleepable_preload+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d91;
	}
x86_l_c77:
	/* 0xc77: mov    ecx,DWORD PTR [rbx+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_c7d:
	/* 0xc7d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c82:
	/* 0xc82: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c87:
	/* 0xc87: cmp    WORD PTR [rbx+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_c8f:
	/* 0xc8f: je     cb4 <generic_sleepable_preload+0xcb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cb4;
	}
x86_l_c91:
	/* 0xc91: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c96:
	/* 0xc96: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c9b:
	/* 0xc9b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ca0:
	/* 0xca0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ca5:
	/* 0xca5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_caa:
	/* 0xcaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cac:
	/* 0xcac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cae:
	/* 0xcae: js     2c97 <generic_sleepable_preload+0x2c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11415ULL;
	}
x86_l_cb4:
	/* 0xcb4: cmp    WORD PTR [rbx+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_cbc:
	/* 0xcbc: je     d91 <generic_sleepable_preload+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d91;
	}
x86_l_cc2:
	/* 0xcc2: mov    ecx,DWORD PTR [rbx+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_cc8:
	/* 0xcc8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ccd:
	/* 0xccd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd2:
	/* 0xcd2: cmp    WORD PTR [rbx+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_cda:
	/* 0xcda: je     cff <generic_sleepable_preload+0xcff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cff;
	}
x86_l_cdc:
	/* 0xcdc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ce1:
	/* 0xce1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ce6:
	/* 0xce6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ceb:
	/* 0xceb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf0:
	/* 0xcf0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cf5:
	/* 0xcf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf7:
	/* 0xcf7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cf9:
	/* 0xcf9: js     33d9 <generic_sleepable_preload+0x33d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13273ULL;
	}
x86_l_cff:
	/* 0xcff: cmp    WORD PTR [rbx+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_d07:
	/* 0xd07: je     d91 <generic_sleepable_preload+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d91;
	}
x86_l_d0d:
	/* 0xd0d: mov    ecx,DWORD PTR [rbx+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_d13:
	/* 0xd13: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d18:
	/* 0xd18: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1d:
	/* 0xd1d: cmp    WORD PTR [rbx+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_d25:
	/* 0xd25: je     d4a <generic_sleepable_preload+0xd4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d4a;
	}
x86_l_d27:
	/* 0xd27: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d2c:
	/* 0xd2c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d31:
	/* 0xd31: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d36:
	/* 0xd36: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d3b:
	/* 0xd3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d40:
	/* 0xd40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d42:
	/* 0xd42: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d44:
	/* 0xd44: js     34c5 <generic_sleepable_preload+0x34c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13509ULL;
	}
x86_l_d4a:
	/* 0xd4a: cmp    WORD PTR [rbx+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_d52:
	/* 0xd52: je     d91 <generic_sleepable_preload+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d91;
	}
x86_l_d54:
	/* 0xd54: mov    ecx,DWORD PTR [rbx+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_d5a:
	/* 0xd5a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d5f:
	/* 0xd5f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d64:
	/* 0xd64: cmp    WORD PTR [rbx+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_d6c:
	/* 0xd6c: je     d91 <generic_sleepable_preload+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d91;
	}
x86_l_d6e:
	/* 0xd6e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d73:
	/* 0xd73: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d78:
	/* 0xd78: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d7d:
	/* 0xd7d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d82:
	/* 0xd82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d87:
	/* 0xd87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d89:
	/* 0xd89: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d8b:
	/* 0xd8b: js     3541 <generic_sleepable_preload+0x3541> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13633ULL;
	}
x86_l_d91:
	/* 0xd91: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_d93:
	/* 0xd93: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d97:
	/* 0xd97: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_d9f:
	/* 0xd9f: jmp    2ca7 <generic_sleepable_preload+0x2ca7> */
	return 11431ULL;
x86_l_da4:
	/* 0xda4: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_dac:
	/* 0xdac: jmp    2c9f <generic_sleepable_preload+0x2c9f> */
	return 11423ULL;
x86_l_db1:
	/* 0xdb1: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_db6:
	/* 0xdb6: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db9:
	/* 0xdb9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dbe:
	/* 0xdbe: cmp    WORD PTR [rbx+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_dc6:
	/* 0xdc6: je     10a6 <generic_sleepable_preload+0x10a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4262ULL;
	}
x86_l_dcc:
	/* 0xdcc: mov    eax,DWORD PTR [rbx+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_dd2:
	/* 0xdd2: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_dd5:
	/* 0xdd5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dda:
	/* 0xdda: cmp    WORD PTR [rbx+0x114],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1185410973696ULL);
x86_l_de2:
	/* 0xde2: je     e07 <generic_sleepable_preload+0xe07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e07;
	}
x86_l_de4:
	/* 0xde4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de9:
	/* 0xde9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_dee:
	/* 0xdee: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_df3:
	/* 0xdf3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df8:
	/* 0xdf8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dfd:
	/* 0xdfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dff:
	/* 0xdff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e01:
	/* 0xe01: js     10b9 <generic_sleepable_preload+0x10b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4281ULL;
	}
x86_l_e07:
	/* 0xe07: cmp    WORD PTR [rbx+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_e0f:
	/* 0xe0f: je     10a6 <generic_sleepable_preload+0x10a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4262ULL;
	}
x86_l_e15:
	/* 0xe15: mov    ecx,DWORD PTR [rbx+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_e1b:
	/* 0xe1b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e20:
	/* 0xe20: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e25:
	/* 0xe25: cmp    WORD PTR [rbx+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_e2d:
	/* 0xe2d: je     e52 <generic_sleepable_preload+0xe52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3666ULL;
	}
	return 3631ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3631ULL: goto x86_l_e2f;
	case 3636ULL: goto x86_l_e34;
	case 3641ULL: goto x86_l_e39;
	case 3646ULL: goto x86_l_e3e;
	case 3651ULL: goto x86_l_e43;
	case 3656ULL: goto x86_l_e48;
	case 3658ULL: goto x86_l_e4a;
	case 3660ULL: goto x86_l_e4c;
	case 3666ULL: goto x86_l_e52;
	case 3674ULL: goto x86_l_e5a;
	case 3680ULL: goto x86_l_e60;
	case 3686ULL: goto x86_l_e66;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3704ULL: goto x86_l_e78;
	case 3706ULL: goto x86_l_e7a;
	case 3711ULL: goto x86_l_e7f;
	case 3716ULL: goto x86_l_e84;
	case 3721ULL: goto x86_l_e89;
	case 3726ULL: goto x86_l_e8e;
	case 3731ULL: goto x86_l_e93;
	case 3733ULL: goto x86_l_e95;
	case 3735ULL: goto x86_l_e97;
	case 3741ULL: goto x86_l_e9d;
	case 3749ULL: goto x86_l_ea5;
	case 3755ULL: goto x86_l_eab;
	case 3761ULL: goto x86_l_eb1;
	case 3766ULL: goto x86_l_eb6;
	case 3771ULL: goto x86_l_ebb;
	case 3779ULL: goto x86_l_ec3;
	case 3781ULL: goto x86_l_ec5;
	case 3786ULL: goto x86_l_eca;
	case 3791ULL: goto x86_l_ecf;
	case 3796ULL: goto x86_l_ed4;
	case 3801ULL: goto x86_l_ed9;
	case 3806ULL: goto x86_l_ede;
	case 3808ULL: goto x86_l_ee0;
	case 3810ULL: goto x86_l_ee2;
	case 3816ULL: goto x86_l_ee8;
	case 3824ULL: goto x86_l_ef0;
	case 3830ULL: goto x86_l_ef6;
	case 3836ULL: goto x86_l_efc;
	case 3841ULL: goto x86_l_f01;
	case 3846ULL: goto x86_l_f06;
	case 3854ULL: goto x86_l_f0e;
	case 3856ULL: goto x86_l_f10;
	case 3861ULL: goto x86_l_f15;
	case 3866ULL: goto x86_l_f1a;
	case 3871ULL: goto x86_l_f1f;
	case 3876ULL: goto x86_l_f24;
	case 3881ULL: goto x86_l_f29;
	case 3883ULL: goto x86_l_f2b;
	case 3885ULL: goto x86_l_f2d;
	case 3891ULL: goto x86_l_f33;
	case 3899ULL: goto x86_l_f3b;
	case 3905ULL: goto x86_l_f41;
	case 3911ULL: goto x86_l_f47;
	case 3916ULL: goto x86_l_f4c;
	case 3921ULL: goto x86_l_f51;
	case 3929ULL: goto x86_l_f59;
	case 3931ULL: goto x86_l_f5b;
	case 3936ULL: goto x86_l_f60;
	case 3941ULL: goto x86_l_f65;
	case 3946ULL: goto x86_l_f6a;
	case 3951ULL: goto x86_l_f6f;
	case 3956ULL: goto x86_l_f74;
	case 3958ULL: goto x86_l_f76;
	case 3960ULL: goto x86_l_f78;
	case 3966ULL: goto x86_l_f7e;
	case 3974ULL: goto x86_l_f86;
	case 3980ULL: goto x86_l_f8c;
	case 3986ULL: goto x86_l_f92;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 4004ULL: goto x86_l_fa4;
	case 4006ULL: goto x86_l_fa6;
	case 4011ULL: goto x86_l_fab;
	case 4016ULL: goto x86_l_fb0;
	case 4021ULL: goto x86_l_fb5;
	case 4026ULL: goto x86_l_fba;
	case 4031ULL: goto x86_l_fbf;
	case 4033ULL: goto x86_l_fc1;
	case 4035ULL: goto x86_l_fc3;
	case 4041ULL: goto x86_l_fc9;
	case 4049ULL: goto x86_l_fd1;
	case 4055ULL: goto x86_l_fd7;
	case 4061ULL: goto x86_l_fdd;
	case 4066ULL: goto x86_l_fe2;
	case 4071ULL: goto x86_l_fe7;
	case 4079ULL: goto x86_l_fef;
	case 4081ULL: goto x86_l_ff1;
	case 4086ULL: goto x86_l_ff6;
	case 4091ULL: goto x86_l_ffb;
	case 4096ULL: goto x86_l_1000;
	case 4101ULL: goto x86_l_1005;
	case 4106ULL: goto x86_l_100a;
	case 4108ULL: goto x86_l_100c;
	case 4110ULL: goto x86_l_100e;
	case 4116ULL: goto x86_l_1014;
	case 4124ULL: goto x86_l_101c;
	case 4130ULL: goto x86_l_1022;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4146ULL: goto x86_l_1032;
	case 4154ULL: goto x86_l_103a;
	case 4156ULL: goto x86_l_103c;
	case 4161ULL: goto x86_l_1041;
	case 4166ULL: goto x86_l_1046;
	case 4171ULL: goto x86_l_104b;
	case 4176ULL: goto x86_l_1050;
	case 4181ULL: goto x86_l_1055;
	case 4183ULL: goto x86_l_1057;
	case 4185ULL: goto x86_l_1059;
	case 4191ULL: goto x86_l_105f;
	case 4199ULL: goto x86_l_1067;
	case 4201ULL: goto x86_l_1069;
	case 4207ULL: goto x86_l_106f;
	case 4212ULL: goto x86_l_1074;
	case 4217ULL: goto x86_l_1079;
	case 4225ULL: goto x86_l_1081;
	case 4227ULL: goto x86_l_1083;
	case 4232ULL: goto x86_l_1088;
	case 4237ULL: goto x86_l_108d;
	case 4242ULL: goto x86_l_1092;
	case 4247ULL: goto x86_l_1097;
	case 4252ULL: goto x86_l_109c;
	case 4254ULL: goto x86_l_109e;
	case 4256ULL: goto x86_l_10a0;
	case 4262ULL: goto x86_l_10a6;
	case 4264ULL: goto x86_l_10a8;
	case 4268ULL: goto x86_l_10ac;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4289ULL: goto x86_l_10c1;
	case 4294ULL: goto x86_l_10c6;
	case 4299ULL: goto x86_l_10cb;
	case 4302ULL: goto x86_l_10ce;
	case 4307ULL: goto x86_l_10d3;
	case 4315ULL: goto x86_l_10db;
	case 4321ULL: goto x86_l_10e1;
	case 4327ULL: goto x86_l_10e7;
	case 4330ULL: goto x86_l_10ea;
	case 4335ULL: goto x86_l_10ef;
	case 4343ULL: goto x86_l_10f7;
	case 4345ULL: goto x86_l_10f9;
	case 4350ULL: goto x86_l_10fe;
	case 4355ULL: goto x86_l_1103;
	case 4360ULL: goto x86_l_1108;
	case 4365ULL: goto x86_l_110d;
	case 4370ULL: goto x86_l_1112;
	case 4372ULL: goto x86_l_1114;
	case 4374ULL: goto x86_l_1116;
	case 4380ULL: goto x86_l_111c;
	case 4388ULL: goto x86_l_1124;
	case 4394ULL: goto x86_l_112a;
	case 4400ULL: goto x86_l_1130;
	case 4405ULL: goto x86_l_1135;
	case 4410ULL: goto x86_l_113a;
	case 4418ULL: goto x86_l_1142;
	case 4420ULL: goto x86_l_1144;
	case 4425ULL: goto x86_l_1149;
	case 4430ULL: goto x86_l_114e;
	case 4435ULL: goto x86_l_1153;
	case 4440ULL: goto x86_l_1158;
	case 4445ULL: goto x86_l_115d;
	case 4447ULL: goto x86_l_115f;
	case 4449ULL: goto x86_l_1161;
	case 4455ULL: goto x86_l_1167;
	case 4463ULL: goto x86_l_116f;
	case 4469ULL: goto x86_l_1175;
	case 4475ULL: goto x86_l_117b;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4493ULL: goto x86_l_118d;
	case 4495ULL: goto x86_l_118f;
	case 4500ULL: goto x86_l_1194;
	case 4505ULL: goto x86_l_1199;
	case 4510ULL: goto x86_l_119e;
	case 4515ULL: goto x86_l_11a3;
	case 4520ULL: goto x86_l_11a8;
	case 4522ULL: goto x86_l_11aa;
	case 4524ULL: goto x86_l_11ac;
	case 4530ULL: goto x86_l_11b2;
	case 4538ULL: goto x86_l_11ba;
	case 4544ULL: goto x86_l_11c0;
	case 4550ULL: goto x86_l_11c6;
	case 4555ULL: goto x86_l_11cb;
	case 4560ULL: goto x86_l_11d0;
	case 4568ULL: goto x86_l_11d8;
	case 4570ULL: goto x86_l_11da;
	case 4575ULL: goto x86_l_11df;
	case 4580ULL: goto x86_l_11e4;
	case 4585ULL: goto x86_l_11e9;
	case 4590ULL: goto x86_l_11ee;
	case 4595ULL: goto x86_l_11f3;
	case 4597ULL: goto x86_l_11f5;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4613ULL: goto x86_l_1205;
	case 4619ULL: goto x86_l_120b;
	case 4625ULL: goto x86_l_1211;
	case 4630ULL: goto x86_l_1216;
	case 4635ULL: goto x86_l_121b;
	case 4643ULL: goto x86_l_1223;
	case 4645ULL: goto x86_l_1225;
	case 4650ULL: goto x86_l_122a;
	case 4655ULL: goto x86_l_122f;
	case 4660ULL: goto x86_l_1234;
	case 4665ULL: goto x86_l_1239;
	case 4670ULL: goto x86_l_123e;
	case 4672ULL: goto x86_l_1240;
	case 4674ULL: goto x86_l_1242;
	case 4680ULL: goto x86_l_1248;
	case 4688ULL: goto x86_l_1250;
	case 4694ULL: goto x86_l_1256;
	case 4700ULL: goto x86_l_125c;
	case 4705ULL: goto x86_l_1261;
	case 4710ULL: goto x86_l_1266;
	case 4718ULL: goto x86_l_126e;
	case 4720ULL: goto x86_l_1270;
	case 4725ULL: goto x86_l_1275;
	case 4730ULL: goto x86_l_127a;
	case 4735ULL: goto x86_l_127f;
	case 4740ULL: goto x86_l_1284;
	case 4745ULL: goto x86_l_1289;
	case 4747ULL: goto x86_l_128b;
	case 4749ULL: goto x86_l_128d;
	case 4755ULL: goto x86_l_1293;
	case 4763ULL: goto x86_l_129b;
	case 4769ULL: goto x86_l_12a1;
	case 4775ULL: goto x86_l_12a7;
	case 4780ULL: goto x86_l_12ac;
	case 4785ULL: goto x86_l_12b1;
	case 4793ULL: goto x86_l_12b9;
	case 4795ULL: goto x86_l_12bb;
	case 4800ULL: goto x86_l_12c0;
	case 4805ULL: goto x86_l_12c5;
	case 4810ULL: goto x86_l_12ca;
	case 4815ULL: goto x86_l_12cf;
	case 4820ULL: goto x86_l_12d4;
	case 4822ULL: goto x86_l_12d6;
	case 4824ULL: goto x86_l_12d8;
	case 4830ULL: goto x86_l_12de;
	case 4838ULL: goto x86_l_12e6;
	case 4844ULL: goto x86_l_12ec;
	case 4850ULL: goto x86_l_12f2;
	case 4855ULL: goto x86_l_12f7;
	case 4860ULL: goto x86_l_12fc;
	case 4868ULL: goto x86_l_1304;
	case 4870ULL: goto x86_l_1306;
	case 4875ULL: goto x86_l_130b;
	case 4880ULL: goto x86_l_1310;
	case 4885ULL: goto x86_l_1315;
	case 4890ULL: goto x86_l_131a;
	case 4895ULL: goto x86_l_131f;
	case 4897ULL: goto x86_l_1321;
	case 4899ULL: goto x86_l_1323;
	case 4905ULL: goto x86_l_1329;
	case 4913ULL: goto x86_l_1331;
	case 4919ULL: goto x86_l_1337;
	case 4925ULL: goto x86_l_133d;
	case 4930ULL: goto x86_l_1342;
	case 4935ULL: goto x86_l_1347;
	case 4943ULL: goto x86_l_134f;
	case 4945ULL: goto x86_l_1351;
	case 4950ULL: goto x86_l_1356;
	case 4955ULL: goto x86_l_135b;
	case 4960ULL: goto x86_l_1360;
	case 4965ULL: goto x86_l_1365;
	case 4970ULL: goto x86_l_136a;
	case 4972ULL: goto x86_l_136c;
	case 4974ULL: goto x86_l_136e;
	case 4980ULL: goto x86_l_1374;
	case 4988ULL: goto x86_l_137c;
	case 4990ULL: goto x86_l_137e;
	case 4996ULL: goto x86_l_1384;
	case 5001ULL: goto x86_l_1389;
	case 5006ULL: goto x86_l_138e;
	case 5014ULL: goto x86_l_1396;
	case 5016ULL: goto x86_l_1398;
	case 5021ULL: goto x86_l_139d;
	case 5026ULL: goto x86_l_13a2;
	case 5031ULL: goto x86_l_13a7;
	case 5036ULL: goto x86_l_13ac;
	case 5041ULL: goto x86_l_13b1;
	case 5043ULL: goto x86_l_13b3;
	case 5045ULL: goto x86_l_13b5;
	case 5051ULL: goto x86_l_13bb;
	case 5053ULL: goto x86_l_13bd;
	case 5057ULL: goto x86_l_13c1;
	case 5065ULL: goto x86_l_13c9;
	case 5070ULL: goto x86_l_13ce;
	case 5078ULL: goto x86_l_13d6;
	case 5083ULL: goto x86_l_13db;
	case 5088ULL: goto x86_l_13e0;
	case 5091ULL: goto x86_l_13e3;
	case 5096ULL: goto x86_l_13e8;
	case 5098ULL: goto x86_l_13ea;
	case 5101ULL: goto x86_l_13ed;
	case 5109ULL: goto x86_l_13f5;
	case 5115ULL: goto x86_l_13fb;
	case 5121ULL: goto x86_l_1401;
	case 5124ULL: goto x86_l_1404;
	case 5129ULL: goto x86_l_1409;
	case 5137ULL: goto x86_l_1411;
	case 5139ULL: goto x86_l_1413;
	case 5144ULL: goto x86_l_1418;
	case 5149ULL: goto x86_l_141d;
	case 5154ULL: goto x86_l_1422;
	case 5159ULL: goto x86_l_1427;
	case 5164ULL: goto x86_l_142c;
	case 5166ULL: goto x86_l_142e;
	case 5168ULL: goto x86_l_1430;
	case 5174ULL: goto x86_l_1436;
	case 5182ULL: goto x86_l_143e;
	case 5188ULL: goto x86_l_1444;
	case 5194ULL: goto x86_l_144a;
	case 5199ULL: goto x86_l_144f;
	case 5204ULL: goto x86_l_1454;
	case 5212ULL: goto x86_l_145c;
	case 5214ULL: goto x86_l_145e;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5229ULL: goto x86_l_146d;
	case 5234ULL: goto x86_l_1472;
	case 5239ULL: goto x86_l_1477;
	case 5241ULL: goto x86_l_1479;
	case 5243ULL: goto x86_l_147b;
	case 5249ULL: goto x86_l_1481;
	case 5257ULL: goto x86_l_1489;
	case 5263ULL: goto x86_l_148f;
	case 5269ULL: goto x86_l_1495;
	case 5274ULL: goto x86_l_149a;
	case 5279ULL: goto x86_l_149f;
	case 5287ULL: goto x86_l_14a7;
	case 5289ULL: goto x86_l_14a9;
	case 5294ULL: goto x86_l_14ae;
	case 5299ULL: goto x86_l_14b3;
	case 5304ULL: goto x86_l_14b8;
	case 5309ULL: goto x86_l_14bd;
	case 5314ULL: goto x86_l_14c2;
	case 5316ULL: goto x86_l_14c4;
	case 5318ULL: goto x86_l_14c6;
	case 5324ULL: goto x86_l_14cc;
	case 5332ULL: goto x86_l_14d4;
	case 5338ULL: goto x86_l_14da;
	case 5344ULL: goto x86_l_14e0;
	case 5349ULL: goto x86_l_14e5;
	case 5354ULL: goto x86_l_14ea;
	case 5362ULL: goto x86_l_14f2;
	case 5364ULL: goto x86_l_14f4;
	case 5369ULL: goto x86_l_14f9;
	case 5374ULL: goto x86_l_14fe;
	case 5379ULL: goto x86_l_1503;
	case 5384ULL: goto x86_l_1508;
	case 5389ULL: goto x86_l_150d;
	case 5391ULL: goto x86_l_150f;
	case 5393ULL: goto x86_l_1511;
	case 5399ULL: goto x86_l_1517;
	case 5407ULL: goto x86_l_151f;
	case 5413ULL: goto x86_l_1525;
	case 5419ULL: goto x86_l_152b;
	case 5424ULL: goto x86_l_1530;
	case 5429ULL: goto x86_l_1535;
	case 5437ULL: goto x86_l_153d;
	case 5439ULL: goto x86_l_153f;
	case 5444ULL: goto x86_l_1544;
	case 5449ULL: goto x86_l_1549;
	case 5454ULL: goto x86_l_154e;
	case 5459ULL: goto x86_l_1553;
	case 5464ULL: goto x86_l_1558;
	case 5466ULL: goto x86_l_155a;
	case 5468ULL: goto x86_l_155c;
	case 5474ULL: goto x86_l_1562;
	case 5482ULL: goto x86_l_156a;
	case 5488ULL: goto x86_l_1570;
	case 5494ULL: goto x86_l_1576;
	case 5499ULL: goto x86_l_157b;
	case 5504ULL: goto x86_l_1580;
	case 5512ULL: goto x86_l_1588;
	case 5514ULL: goto x86_l_158a;
	case 5519ULL: goto x86_l_158f;
	case 5524ULL: goto x86_l_1594;
	case 5529ULL: goto x86_l_1599;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e2f:
	/* 0xe2f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e34:
	/* 0xe34: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e39:
	/* 0xe39: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e3e:
	/* 0xe3e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e43:
	/* 0xe43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e48:
	/* 0xe48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4a:
	/* 0xe4a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e4c:
	/* 0xe4c: js     1fd6 <generic_sleepable_preload+0x1fd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8150ULL;
	}
x86_l_e52:
	/* 0xe52: cmp    WORD PTR [rbx+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_e5a:
	/* 0xe5a: je     10a6 <generic_sleepable_preload+0x10a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a6;
	}
x86_l_e60:
	/* 0xe60: mov    ecx,DWORD PTR [rbx+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_e66:
	/* 0xe66: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e6b:
	/* 0xe6b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e70:
	/* 0xe70: cmp    WORD PTR [rbx+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_e78:
	/* 0xe78: je     e9d <generic_sleepable_preload+0xe9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e9d;
	}
x86_l_e7a:
	/* 0xe7a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e7f:
	/* 0xe7f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e84:
	/* 0xe84: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e89:
	/* 0xe89: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8e:
	/* 0xe8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e93:
	/* 0xe93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e95:
	/* 0xe95: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e97:
	/* 0xe97: js     29f7 <generic_sleepable_preload+0x29f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10743ULL;
	}
x86_l_e9d:
	/* 0xe9d: cmp    WORD PTR [rbx+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_ea5:
	/* 0xea5: je     10a6 <generic_sleepable_preload+0x10a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a6;
	}
x86_l_eab:
	/* 0xeab: mov    ecx,DWORD PTR [rbx+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_eb1:
	/* 0xeb1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_eb6:
	/* 0xeb6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ebb:
	/* 0xebb: cmp    WORD PTR [rbx+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_ec3:
	/* 0xec3: je     ee8 <generic_sleepable_preload+0xee8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ee8;
	}
x86_l_ec5:
	/* 0xec5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eca:
	/* 0xeca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ecf:
	/* 0xecf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ed4:
	/* 0xed4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ed9:
	/* 0xed9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ede:
	/* 0xede: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee0:
	/* 0xee0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ee2:
	/* 0xee2: js     2a73 <generic_sleepable_preload+0x2a73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10867ULL;
	}
x86_l_ee8:
	/* 0xee8: cmp    WORD PTR [rbx+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_ef0:
	/* 0xef0: je     10a6 <generic_sleepable_preload+0x10a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a6;
	}
x86_l_ef6:
	/* 0xef6: mov    ecx,DWORD PTR [rbx+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_efc:
	/* 0xefc: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f01:
	/* 0xf01: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f06:
	/* 0xf06: cmp    WORD PTR [rbx+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_f0e:
	/* 0xf0e: je     f33 <generic_sleepable_preload+0xf33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f33;
	}
x86_l_f10:
	/* 0xf10: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f15:
	/* 0xf15: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f1a:
	/* 0xf1a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f1f:
	/* 0xf1f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f24:
	/* 0xf24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f29:
	/* 0xf29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2b:
	/* 0xf2b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f2d:
	/* 0xf2d: js     2aef <generic_sleepable_preload+0x2aef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10991ULL;
	}
x86_l_f33:
	/* 0xf33: cmp    WORD PTR [rbx+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_f3b:
	/* 0xf3b: je     10a6 <generic_sleepable_preload+0x10a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a6;
	}
x86_l_f41:
	/* 0xf41: mov    ecx,DWORD PTR [rbx+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_f47:
	/* 0xf47: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f4c:
	/* 0xf4c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f51:
	/* 0xf51: cmp    WORD PTR [rbx+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_f59:
	/* 0xf59: je     f7e <generic_sleepable_preload+0xf7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f7e;
	}
x86_l_f5b:
	/* 0xf5b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f60:
	/* 0xf60: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f65:
	/* 0xf65: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f6a:
	/* 0xf6a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f6f:
	/* 0xf6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f74:
	/* 0xf74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f76:
	/* 0xf76: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f78:
	/* 0xf78: js     2b68 <generic_sleepable_preload+0x2b68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11112ULL;
	}
x86_l_f7e:
	/* 0xf7e: cmp    WORD PTR [rbx+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_f86:
	/* 0xf86: je     10a6 <generic_sleepable_preload+0x10a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a6;
	}
x86_l_f8c:
	/* 0xf8c: mov    ecx,DWORD PTR [rbx+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_f92:
	/* 0xf92: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f97:
	/* 0xf97: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f9c:
	/* 0xf9c: cmp    WORD PTR [rbx+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_fa4:
	/* 0xfa4: je     fc9 <generic_sleepable_preload+0xfc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fc9;
	}
x86_l_fa6:
	/* 0xfa6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fab:
	/* 0xfab: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_fb0:
	/* 0xfb0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_fb5:
	/* 0xfb5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fba:
	/* 0xfba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fbf:
	/* 0xfbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc1:
	/* 0xfc1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fc3:
	/* 0xfc3: js     2d92 <generic_sleepable_preload+0x2d92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11666ULL;
	}
x86_l_fc9:
	/* 0xfc9: cmp    WORD PTR [rbx+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_fd1:
	/* 0xfd1: je     10a6 <generic_sleepable_preload+0x10a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a6;
	}
x86_l_fd7:
	/* 0xfd7: mov    ecx,DWORD PTR [rbx+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_fdd:
	/* 0xfdd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_fe2:
	/* 0xfe2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe7:
	/* 0xfe7: cmp    WORD PTR [rbx+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_fef:
	/* 0xfef: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1014;
	}
x86_l_ff1:
	/* 0xff1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ff6:
	/* 0xff6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ffb:
	/* 0xffb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1000:
	/* 0x1000: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1005:
	/* 0x1005: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_100a:
	/* 0x100a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_100c:
	/* 0x100c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_100e:
	/* 0x100e: js     33ee <generic_sleepable_preload+0x33ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13294ULL;
	}
x86_l_1014:
	/* 0x1014: cmp    WORD PTR [rbx+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_101c:
	/* 0x101c: je     10a6 <generic_sleepable_preload+0x10a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a6;
	}
x86_l_1022:
	/* 0x1022: mov    ecx,DWORD PTR [rbx+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_1028:
	/* 0x1028: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_102d:
	/* 0x102d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1032:
	/* 0x1032: cmp    WORD PTR [rbx+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_103a:
	/* 0x103a: je     105f <generic_sleepable_preload+0x105f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_105f;
	}
x86_l_103c:
	/* 0x103c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1041:
	/* 0x1041: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1046:
	/* 0x1046: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_104b:
	/* 0x104b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1050:
	/* 0x1050: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1055:
	/* 0x1055: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1057:
	/* 0x1057: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1059:
	/* 0x1059: js     34d2 <generic_sleepable_preload+0x34d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13522ULL;
	}
x86_l_105f:
	/* 0x105f: cmp    WORD PTR [rbx+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_1067:
	/* 0x1067: je     10a6 <generic_sleepable_preload+0x10a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a6;
	}
x86_l_1069:
	/* 0x1069: mov    ecx,DWORD PTR [rbx+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_106f:
	/* 0x106f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1074:
	/* 0x1074: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1079:
	/* 0x1079: cmp    WORD PTR [rbx+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_1081:
	/* 0x1081: je     10a6 <generic_sleepable_preload+0x10a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a6;
	}
x86_l_1083:
	/* 0x1083: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1088:
	/* 0x1088: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_108d:
	/* 0x108d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1092:
	/* 0x1092: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1097:
	/* 0x1097: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_109c:
	/* 0x109c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109e:
	/* 0x109e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10a0:
	/* 0x10a0: js     354e <generic_sleepable_preload+0x354e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13646ULL;
	}
x86_l_10a6:
	/* 0x10a6: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_10a8:
	/* 0x10a8: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10ac:
	/* 0x10ac: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_10b4:
	/* 0x10b4: jmp    2da2 <generic_sleepable_preload+0x2da2> */
	return 11682ULL;
x86_l_10b9:
	/* 0x10b9: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_10c1:
	/* 0x10c1: jmp    2d9a <generic_sleepable_preload+0x2d9a> */
	return 11674ULL;
x86_l_10c6:
	/* 0x10c6: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_10cb:
	/* 0x10cb: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ce:
	/* 0x10ce: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10d3:
	/* 0x10d3: cmp    WORD PTR [rbx+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_10db:
	/* 0x10db: je     13bb <generic_sleepable_preload+0x13bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bb;
	}
x86_l_10e1:
	/* 0x10e1: mov    eax,DWORD PTR [rbx+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_10e7:
	/* 0x10e7: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_10ea:
	/* 0x10ea: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10ef:
	/* 0x10ef: cmp    WORD PTR [rbx+0x164],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1529008357376ULL);
x86_l_10f7:
	/* 0x10f7: je     111c <generic_sleepable_preload+0x111c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_111c;
	}
x86_l_10f9:
	/* 0x10f9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10fe:
	/* 0x10fe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1103:
	/* 0x1103: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1108:
	/* 0x1108: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_110d:
	/* 0x110d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1112:
	/* 0x1112: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1114:
	/* 0x1114: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1116:
	/* 0x1116: js     13ce <generic_sleepable_preload+0x13ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_13ce;
	}
x86_l_111c:
	/* 0x111c: cmp    WORD PTR [rbx+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_1124:
	/* 0x1124: je     13bb <generic_sleepable_preload+0x13bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bb;
	}
x86_l_112a:
	/* 0x112a: mov    ecx,DWORD PTR [rbx+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_1130:
	/* 0x1130: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1135:
	/* 0x1135: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_113a:
	/* 0x113a: cmp    WORD PTR [rbx+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_1142:
	/* 0x1142: je     1167 <generic_sleepable_preload+0x1167> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1167;
	}
x86_l_1144:
	/* 0x1144: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1149:
	/* 0x1149: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_114e:
	/* 0x114e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1153:
	/* 0x1153: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1158:
	/* 0x1158: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_115d:
	/* 0x115d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_115f:
	/* 0x115f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1161:
	/* 0x1161: js     1fe3 <generic_sleepable_preload+0x1fe3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8163ULL;
	}
x86_l_1167:
	/* 0x1167: cmp    WORD PTR [rbx+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_116f:
	/* 0x116f: je     13bb <generic_sleepable_preload+0x13bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bb;
	}
x86_l_1175:
	/* 0x1175: mov    ecx,DWORD PTR [rbx+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_117b:
	/* 0x117b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1180:
	/* 0x1180: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1185:
	/* 0x1185: cmp    WORD PTR [rbx+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_118d:
	/* 0x118d: je     11b2 <generic_sleepable_preload+0x11b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b2;
	}
x86_l_118f:
	/* 0x118f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1194:
	/* 0x1194: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1199:
	/* 0x1199: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_119e:
	/* 0x119e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11a3:
	/* 0x11a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11a8:
	/* 0x11a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11aa:
	/* 0x11aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11ac:
	/* 0x11ac: js     2a04 <generic_sleepable_preload+0x2a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10756ULL;
	}
x86_l_11b2:
	/* 0x11b2: cmp    WORD PTR [rbx+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_11ba:
	/* 0x11ba: je     13bb <generic_sleepable_preload+0x13bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bb;
	}
x86_l_11c0:
	/* 0x11c0: mov    ecx,DWORD PTR [rbx+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_11c6:
	/* 0x11c6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_11cb:
	/* 0x11cb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11d0:
	/* 0x11d0: cmp    WORD PTR [rbx+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_11d8:
	/* 0x11d8: je     11fd <generic_sleepable_preload+0x11fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11fd;
	}
x86_l_11da:
	/* 0x11da: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11df:
	/* 0x11df: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_11e4:
	/* 0x11e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_11e9:
	/* 0x11e9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11ee:
	/* 0x11ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11f3:
	/* 0x11f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f5:
	/* 0x11f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11f7:
	/* 0x11f7: js     2a80 <generic_sleepable_preload+0x2a80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10880ULL;
	}
x86_l_11fd:
	/* 0x11fd: cmp    WORD PTR [rbx+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_1205:
	/* 0x1205: je     13bb <generic_sleepable_preload+0x13bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bb;
	}
x86_l_120b:
	/* 0x120b: mov    ecx,DWORD PTR [rbx+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_1211:
	/* 0x1211: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1216:
	/* 0x1216: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_121b:
	/* 0x121b: cmp    WORD PTR [rbx+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_1223:
	/* 0x1223: je     1248 <generic_sleepable_preload+0x1248> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1248;
	}
x86_l_1225:
	/* 0x1225: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_122a:
	/* 0x122a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_122f:
	/* 0x122f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1234:
	/* 0x1234: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1239:
	/* 0x1239: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_123e:
	/* 0x123e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1240:
	/* 0x1240: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1242:
	/* 0x1242: js     2afc <generic_sleepable_preload+0x2afc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11004ULL;
	}
x86_l_1248:
	/* 0x1248: cmp    WORD PTR [rbx+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_1250:
	/* 0x1250: je     13bb <generic_sleepable_preload+0x13bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bb;
	}
x86_l_1256:
	/* 0x1256: mov    ecx,DWORD PTR [rbx+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_125c:
	/* 0x125c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1261:
	/* 0x1261: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1266:
	/* 0x1266: cmp    WORD PTR [rbx+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_126e:
	/* 0x126e: je     1293 <generic_sleepable_preload+0x1293> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1293;
	}
x86_l_1270:
	/* 0x1270: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1275:
	/* 0x1275: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_127a:
	/* 0x127a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_127f:
	/* 0x127f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1284:
	/* 0x1284: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1289:
	/* 0x1289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128b:
	/* 0x128b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_128d:
	/* 0x128d: js     2b75 <generic_sleepable_preload+0x2b75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11125ULL;
	}
x86_l_1293:
	/* 0x1293: cmp    WORD PTR [rbx+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_129b:
	/* 0x129b: je     13bb <generic_sleepable_preload+0x13bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bb;
	}
x86_l_12a1:
	/* 0x12a1: mov    ecx,DWORD PTR [rbx+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_12a7:
	/* 0x12a7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_12ac:
	/* 0x12ac: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12b1:
	/* 0x12b1: cmp    WORD PTR [rbx+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_12b9:
	/* 0x12b9: je     12de <generic_sleepable_preload+0x12de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12de;
	}
x86_l_12bb:
	/* 0x12bb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12c0:
	/* 0x12c0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_12c5:
	/* 0x12c5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12ca:
	/* 0x12ca: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12cf:
	/* 0x12cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12d4:
	/* 0x12d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d6:
	/* 0x12d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12d8:
	/* 0x12d8: js     2e8d <generic_sleepable_preload+0x2e8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11917ULL;
	}
x86_l_12de:
	/* 0x12de: cmp    WORD PTR [rbx+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_12e6:
	/* 0x12e6: je     13bb <generic_sleepable_preload+0x13bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bb;
	}
x86_l_12ec:
	/* 0x12ec: mov    ecx,DWORD PTR [rbx+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_12f2:
	/* 0x12f2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_12f7:
	/* 0x12f7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12fc:
	/* 0x12fc: cmp    WORD PTR [rbx+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_1304:
	/* 0x1304: je     1329 <generic_sleepable_preload+0x1329> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1329;
	}
x86_l_1306:
	/* 0x1306: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_130b:
	/* 0x130b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1310:
	/* 0x1310: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1315:
	/* 0x1315: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_131a:
	/* 0x131a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_131f:
	/* 0x131f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1321:
	/* 0x1321: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1323:
	/* 0x1323: js     3403 <generic_sleepable_preload+0x3403> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13315ULL;
	}
x86_l_1329:
	/* 0x1329: cmp    WORD PTR [rbx+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_1331:
	/* 0x1331: je     13bb <generic_sleepable_preload+0x13bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bb;
	}
x86_l_1337:
	/* 0x1337: mov    ecx,DWORD PTR [rbx+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_133d:
	/* 0x133d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1342:
	/* 0x1342: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1347:
	/* 0x1347: cmp    WORD PTR [rbx+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_134f:
	/* 0x134f: je     1374 <generic_sleepable_preload+0x1374> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1374;
	}
x86_l_1351:
	/* 0x1351: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1356:
	/* 0x1356: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_135b:
	/* 0x135b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1360:
	/* 0x1360: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1365:
	/* 0x1365: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_136a:
	/* 0x136a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_136c:
	/* 0x136c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_136e:
	/* 0x136e: js     34df <generic_sleepable_preload+0x34df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13535ULL;
	}
x86_l_1374:
	/* 0x1374: cmp    WORD PTR [rbx+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_137c:
	/* 0x137c: je     13bb <generic_sleepable_preload+0x13bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bb;
	}
x86_l_137e:
	/* 0x137e: mov    ecx,DWORD PTR [rbx+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_1384:
	/* 0x1384: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1389:
	/* 0x1389: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_138e:
	/* 0x138e: cmp    WORD PTR [rbx+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_1396:
	/* 0x1396: je     13bb <generic_sleepable_preload+0x13bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bb;
	}
x86_l_1398:
	/* 0x1398: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_139d:
	/* 0x139d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_13a2:
	/* 0x13a2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_13a7:
	/* 0x13a7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13ac:
	/* 0x13ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13b1:
	/* 0x13b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b3:
	/* 0x13b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13b5:
	/* 0x13b5: js     355b <generic_sleepable_preload+0x355b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13659ULL;
	}
x86_l_13bb:
	/* 0x13bb: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_13bd:
	/* 0x13bd: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13c1:
	/* 0x13c1: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_13c9:
	/* 0x13c9: jmp    2e9d <generic_sleepable_preload+0x2e9d> */
	return 11933ULL;
x86_l_13ce:
	/* 0x13ce: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_13d6:
	/* 0x13d6: jmp    2e95 <generic_sleepable_preload+0x2e95> */
	return 11925ULL;
x86_l_13db:
	/* 0x13db: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13e0:
	/* 0x13e0: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e3:
	/* 0x13e3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13e8:
	/* 0x13e8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13ea:
	/* 0x13ea: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_13ed:
	/* 0x13ed: cmp    WORD PTR [rbx+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_13f5:
	/* 0x13f5: je     2f90 <generic_sleepable_preload+0x2f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12176ULL;
	}
x86_l_13fb:
	/* 0x13fb: mov    eax,DWORD PTR [rbx+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_1401:
	/* 0x1401: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1404:
	/* 0x1404: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1409:
	/* 0x1409: cmp    WORD PTR [rbx+0x1b4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1872605741056ULL);
x86_l_1411:
	/* 0x1411: je     1436 <generic_sleepable_preload+0x1436> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1436;
	}
x86_l_1413:
	/* 0x1413: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1418:
	/* 0x1418: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_141d:
	/* 0x141d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1422:
	/* 0x1422: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1427:
	/* 0x1427: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_142c:
	/* 0x142c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142e:
	/* 0x142e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1430:
	/* 0x1430: js     16e7 <generic_sleepable_preload+0x16e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5863ULL;
	}
x86_l_1436:
	/* 0x1436: cmp    WORD PTR [rbx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_143e:
	/* 0x143e: je     2f90 <generic_sleepable_preload+0x2f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12176ULL;
	}
x86_l_1444:
	/* 0x1444: mov    ecx,DWORD PTR [rbx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_144a:
	/* 0x144a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_144f:
	/* 0x144f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1454:
	/* 0x1454: cmp    WORD PTR [rbx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_145c:
	/* 0x145c: je     1481 <generic_sleepable_preload+0x1481> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1481;
	}
x86_l_145e:
	/* 0x145e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1463:
	/* 0x1463: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1468:
	/* 0x1468: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_146d:
	/* 0x146d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1472:
	/* 0x1472: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1477:
	/* 0x1477: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1479:
	/* 0x1479: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_147b:
	/* 0x147b: js     1ff0 <generic_sleepable_preload+0x1ff0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8176ULL;
	}
x86_l_1481:
	/* 0x1481: cmp    WORD PTR [rbx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_1489:
	/* 0x1489: je     2f90 <generic_sleepable_preload+0x2f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12176ULL;
	}
x86_l_148f:
	/* 0x148f: mov    ecx,DWORD PTR [rbx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_1495:
	/* 0x1495: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_149a:
	/* 0x149a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_149f:
	/* 0x149f: cmp    WORD PTR [rbx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_14a7:
	/* 0x14a7: je     14cc <generic_sleepable_preload+0x14cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14cc;
	}
x86_l_14a9:
	/* 0x14a9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ae:
	/* 0x14ae: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_14b3:
	/* 0x14b3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14b8:
	/* 0x14b8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14bd:
	/* 0x14bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14c2:
	/* 0x14c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c4:
	/* 0x14c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14c6:
	/* 0x14c6: js     2a11 <generic_sleepable_preload+0x2a11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10769ULL;
	}
x86_l_14cc:
	/* 0x14cc: cmp    WORD PTR [rbx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_14d4:
	/* 0x14d4: je     2f90 <generic_sleepable_preload+0x2f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12176ULL;
	}
x86_l_14da:
	/* 0x14da: mov    ecx,DWORD PTR [rbx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_14e0:
	/* 0x14e0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_14e5:
	/* 0x14e5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ea:
	/* 0x14ea: cmp    WORD PTR [rbx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_14f2:
	/* 0x14f2: je     1517 <generic_sleepable_preload+0x1517> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1517;
	}
x86_l_14f4:
	/* 0x14f4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14f9:
	/* 0x14f9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_14fe:
	/* 0x14fe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1503:
	/* 0x1503: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1508:
	/* 0x1508: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_150d:
	/* 0x150d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_150f:
	/* 0x150f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1511:
	/* 0x1511: js     2a8d <generic_sleepable_preload+0x2a8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10893ULL;
	}
x86_l_1517:
	/* 0x1517: cmp    WORD PTR [rbx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_151f:
	/* 0x151f: je     2f90 <generic_sleepable_preload+0x2f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12176ULL;
	}
x86_l_1525:
	/* 0x1525: mov    ecx,DWORD PTR [rbx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_152b:
	/* 0x152b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1530:
	/* 0x1530: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1535:
	/* 0x1535: cmp    WORD PTR [rbx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_153d:
	/* 0x153d: je     1562 <generic_sleepable_preload+0x1562> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1562;
	}
x86_l_153f:
	/* 0x153f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1544:
	/* 0x1544: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1549:
	/* 0x1549: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_154e:
	/* 0x154e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1553:
	/* 0x1553: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1558:
	/* 0x1558: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_155a:
	/* 0x155a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_155c:
	/* 0x155c: js     2b09 <generic_sleepable_preload+0x2b09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11017ULL;
	}
x86_l_1562:
	/* 0x1562: cmp    WORD PTR [rbx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_156a:
	/* 0x156a: je     2f90 <generic_sleepable_preload+0x2f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12176ULL;
	}
x86_l_1570:
	/* 0x1570: mov    ecx,DWORD PTR [rbx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_1576:
	/* 0x1576: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_157b:
	/* 0x157b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1580:
	/* 0x1580: cmp    WORD PTR [rbx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_1588:
	/* 0x1588: je     15ad <generic_sleepable_preload+0x15ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5549ULL;
	}
x86_l_158a:
	/* 0x158a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_158f:
	/* 0x158f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1594:
	/* 0x1594: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1599:
	/* 0x1599: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 5534ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5534ULL: goto x86_l_159e;
	case 5539ULL: goto x86_l_15a3;
	case 5541ULL: goto x86_l_15a5;
	case 5543ULL: goto x86_l_15a7;
	case 5549ULL: goto x86_l_15ad;
	case 5557ULL: goto x86_l_15b5;
	case 5563ULL: goto x86_l_15bb;
	case 5569ULL: goto x86_l_15c1;
	case 5574ULL: goto x86_l_15c6;
	case 5579ULL: goto x86_l_15cb;
	case 5587ULL: goto x86_l_15d3;
	case 5589ULL: goto x86_l_15d5;
	case 5594ULL: goto x86_l_15da;
	case 5599ULL: goto x86_l_15df;
	case 5604ULL: goto x86_l_15e4;
	case 5609ULL: goto x86_l_15e9;
	case 5614ULL: goto x86_l_15ee;
	case 5616ULL: goto x86_l_15f0;
	case 5618ULL: goto x86_l_15f2;
	case 5624ULL: goto x86_l_15f8;
	case 5632ULL: goto x86_l_1600;
	case 5638ULL: goto x86_l_1606;
	case 5644ULL: goto x86_l_160c;
	case 5649ULL: goto x86_l_1611;
	case 5654ULL: goto x86_l_1616;
	case 5662ULL: goto x86_l_161e;
	case 5664ULL: goto x86_l_1620;
	case 5669ULL: goto x86_l_1625;
	case 5674ULL: goto x86_l_162a;
	case 5679ULL: goto x86_l_162f;
	case 5684ULL: goto x86_l_1634;
	case 5689ULL: goto x86_l_1639;
	case 5691ULL: goto x86_l_163b;
	case 5693ULL: goto x86_l_163d;
	case 5699ULL: goto x86_l_1643;
	case 5707ULL: goto x86_l_164b;
	case 5713ULL: goto x86_l_1651;
	case 5719ULL: goto x86_l_1657;
	case 5724ULL: goto x86_l_165c;
	case 5729ULL: goto x86_l_1661;
	case 5737ULL: goto x86_l_1669;
	case 5739ULL: goto x86_l_166b;
	case 5744ULL: goto x86_l_1670;
	case 5749ULL: goto x86_l_1675;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5764ULL: goto x86_l_1684;
	case 5766ULL: goto x86_l_1686;
	case 5768ULL: goto x86_l_1688;
	case 5774ULL: goto x86_l_168e;
	case 5782ULL: goto x86_l_1696;
	case 5788ULL: goto x86_l_169c;
	case 5794ULL: goto x86_l_16a2;
	case 5799ULL: goto x86_l_16a7;
	case 5804ULL: goto x86_l_16ac;
	case 5812ULL: goto x86_l_16b4;
	case 5818ULL: goto x86_l_16ba;
	case 5823ULL: goto x86_l_16bf;
	case 5828ULL: goto x86_l_16c4;
	case 5833ULL: goto x86_l_16c9;
	case 5838ULL: goto x86_l_16ce;
	case 5843ULL: goto x86_l_16d3;
	case 5845ULL: goto x86_l_16d5;
	case 5847ULL: goto x86_l_16d7;
	case 5853ULL: goto x86_l_16dd;
	case 5858ULL: goto x86_l_16e2;
	case 5863ULL: goto x86_l_16e7;
	case 5868ULL: goto x86_l_16ec;
	case 5873ULL: goto x86_l_16f1;
	case 5881ULL: goto x86_l_16f9;
	case 5884ULL: goto x86_l_16fc;
	case 5890ULL: goto x86_l_1702;
	case 5893ULL: goto x86_l_1705;
	case 5896ULL: goto x86_l_1708;
	case 5902ULL: goto x86_l_170e;
	case 5907ULL: goto x86_l_1713;
	case 5915ULL: goto x86_l_171b;
	case 5918ULL: goto x86_l_171e;
	case 5924ULL: goto x86_l_1724;
	case 5927ULL: goto x86_l_1727;
	case 5930ULL: goto x86_l_172a;
	case 5936ULL: goto x86_l_1730;
	case 5941ULL: goto x86_l_1735;
	case 5949ULL: goto x86_l_173d;
	case 5952ULL: goto x86_l_1740;
	case 5958ULL: goto x86_l_1746;
	case 5961ULL: goto x86_l_1749;
	case 5964ULL: goto x86_l_174c;
	case 5970ULL: goto x86_l_1752;
	case 5975ULL: goto x86_l_1757;
	case 5983ULL: goto x86_l_175f;
	case 5986ULL: goto x86_l_1762;
	case 5992ULL: goto x86_l_1768;
	case 5995ULL: goto x86_l_176b;
	case 5998ULL: goto x86_l_176e;
	case 6004ULL: goto x86_l_1774;
	case 6009ULL: goto x86_l_1779;
	case 6017ULL: goto x86_l_1781;
	case 6020ULL: goto x86_l_1784;
	case 6026ULL: goto x86_l_178a;
	case 6029ULL: goto x86_l_178d;
	case 6032ULL: goto x86_l_1790;
	case 6038ULL: goto x86_l_1796;
	case 6043ULL: goto x86_l_179b;
	case 6048ULL: goto x86_l_17a0;
	case 6051ULL: goto x86_l_17a3;
	case 6057ULL: goto x86_l_17a9;
	case 6062ULL: goto x86_l_17ae;
	case 6065ULL: goto x86_l_17b1;
	case 6071ULL: goto x86_l_17b7;
	case 6076ULL: goto x86_l_17bc;
	case 6081ULL: goto x86_l_17c1;
	case 6084ULL: goto x86_l_17c4;
	case 6090ULL: goto x86_l_17ca;
	case 6095ULL: goto x86_l_17cf;
	case 6098ULL: goto x86_l_17d2;
	case 6104ULL: goto x86_l_17d8;
	case 6109ULL: goto x86_l_17dd;
	case 6114ULL: goto x86_l_17e2;
	case 6117ULL: goto x86_l_17e5;
	case 6123ULL: goto x86_l_17eb;
	case 6128ULL: goto x86_l_17f0;
	case 6131ULL: goto x86_l_17f3;
	case 6137ULL: goto x86_l_17f9;
	case 6142ULL: goto x86_l_17fe;
	case 6147ULL: goto x86_l_1803;
	case 6150ULL: goto x86_l_1806;
	case 6156ULL: goto x86_l_180c;
	case 6161ULL: goto x86_l_1811;
	case 6164ULL: goto x86_l_1814;
	case 6170ULL: goto x86_l_181a;
	case 6175ULL: goto x86_l_181f;
	case 6180ULL: goto x86_l_1824;
	case 6183ULL: goto x86_l_1827;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6197ULL: goto x86_l_1835;
	case 6203ULL: goto x86_l_183b;
	case 6208ULL: goto x86_l_1840;
	case 6216ULL: goto x86_l_1848;
	case 6219ULL: goto x86_l_184b;
	case 6225ULL: goto x86_l_1851;
	case 6230ULL: goto x86_l_1856;
	case 6233ULL: goto x86_l_1859;
	case 6239ULL: goto x86_l_185f;
	case 6244ULL: goto x86_l_1864;
	case 6252ULL: goto x86_l_186c;
	case 6255ULL: goto x86_l_186f;
	case 6261ULL: goto x86_l_1875;
	case 6266ULL: goto x86_l_187a;
	case 6269ULL: goto x86_l_187d;
	case 6275ULL: goto x86_l_1883;
	case 6280ULL: goto x86_l_1888;
	case 6288ULL: goto x86_l_1890;
	case 6291ULL: goto x86_l_1893;
	case 6297ULL: goto x86_l_1899;
	case 6302ULL: goto x86_l_189e;
	case 6305ULL: goto x86_l_18a1;
	case 6311ULL: goto x86_l_18a7;
	case 6316ULL: goto x86_l_18ac;
	case 6324ULL: goto x86_l_18b4;
	case 6327ULL: goto x86_l_18b7;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6341ULL: goto x86_l_18c5;
	case 6347ULL: goto x86_l_18cb;
	case 6352ULL: goto x86_l_18d0;
	case 6360ULL: goto x86_l_18d8;
	case 6363ULL: goto x86_l_18db;
	case 6369ULL: goto x86_l_18e1;
	case 6374ULL: goto x86_l_18e6;
	case 6377ULL: goto x86_l_18e9;
	case 6383ULL: goto x86_l_18ef;
	case 6388ULL: goto x86_l_18f4;
	case 6393ULL: goto x86_l_18f9;
	case 6396ULL: goto x86_l_18fc;
	case 6398ULL: goto x86_l_18fe;
	case 6401ULL: goto x86_l_1901;
	case 6404ULL: goto x86_l_1904;
	case 6406ULL: goto x86_l_1906;
	case 6409ULL: goto x86_l_1909;
	case 6411ULL: goto x86_l_190b;
	case 6413ULL: goto x86_l_190d;
	case 6418ULL: goto x86_l_1912;
	case 6420ULL: goto x86_l_1914;
	case 6425ULL: goto x86_l_1919;
	case 6430ULL: goto x86_l_191e;
	case 6434ULL: goto x86_l_1922;
	case 6442ULL: goto x86_l_192a;
	case 6444ULL: goto x86_l_192c;
	case 6448ULL: goto x86_l_1930;
	case 6453ULL: goto x86_l_1935;
	case 6459ULL: goto x86_l_193b;
	case 6462ULL: goto x86_l_193e;
	case 6465ULL: goto x86_l_1941;
	case 6470ULL: goto x86_l_1946;
	case 6475ULL: goto x86_l_194b;
	case 6477ULL: goto x86_l_194d;
	case 6482ULL: goto x86_l_1952;
	case 6487ULL: goto x86_l_1957;
	case 6492ULL: goto x86_l_195c;
	case 6497ULL: goto x86_l_1961;
	case 6502ULL: goto x86_l_1966;
	case 6504ULL: goto x86_l_1968;
	case 6506ULL: goto x86_l_196a;
	case 6512ULL: goto x86_l_1970;
	case 6517ULL: goto x86_l_1975;
	case 6523ULL: goto x86_l_197b;
	case 6526ULL: goto x86_l_197e;
	case 6531ULL: goto x86_l_1983;
	case 6536ULL: goto x86_l_1988;
	case 6541ULL: goto x86_l_198d;
	case 6543ULL: goto x86_l_198f;
	case 6548ULL: goto x86_l_1994;
	case 6553ULL: goto x86_l_1999;
	case 6558ULL: goto x86_l_199e;
	case 6563ULL: goto x86_l_19a3;
	case 6568ULL: goto x86_l_19a8;
	case 6570ULL: goto x86_l_19aa;
	case 6572ULL: goto x86_l_19ac;
	case 6578ULL: goto x86_l_19b2;
	case 6586ULL: goto x86_l_19ba;
	case 6592ULL: goto x86_l_19c0;
	case 6598ULL: goto x86_l_19c6;
	case 6603ULL: goto x86_l_19cb;
	case 6608ULL: goto x86_l_19d0;
	case 6616ULL: goto x86_l_19d8;
	case 6618ULL: goto x86_l_19da;
	case 6623ULL: goto x86_l_19df;
	case 6628ULL: goto x86_l_19e4;
	case 6633ULL: goto x86_l_19e9;
	case 6638ULL: goto x86_l_19ee;
	case 6643ULL: goto x86_l_19f3;
	case 6645ULL: goto x86_l_19f5;
	case 6647ULL: goto x86_l_19f7;
	case 6653ULL: goto x86_l_19fd;
	case 6661ULL: goto x86_l_1a05;
	case 6667ULL: goto x86_l_1a0b;
	case 6673ULL: goto x86_l_1a11;
	case 6678ULL: goto x86_l_1a16;
	case 6683ULL: goto x86_l_1a1b;
	case 6691ULL: goto x86_l_1a23;
	case 6693ULL: goto x86_l_1a25;
	case 6698ULL: goto x86_l_1a2a;
	case 6703ULL: goto x86_l_1a2f;
	case 6708ULL: goto x86_l_1a34;
	case 6713ULL: goto x86_l_1a39;
	case 6718ULL: goto x86_l_1a3e;
	case 6720ULL: goto x86_l_1a40;
	case 6722ULL: goto x86_l_1a42;
	case 6728ULL: goto x86_l_1a48;
	case 6736ULL: goto x86_l_1a50;
	case 6742ULL: goto x86_l_1a56;
	case 6748ULL: goto x86_l_1a5c;
	case 6753ULL: goto x86_l_1a61;
	case 6758ULL: goto x86_l_1a66;
	case 6766ULL: goto x86_l_1a6e;
	case 6768ULL: goto x86_l_1a70;
	case 6773ULL: goto x86_l_1a75;
	case 6778ULL: goto x86_l_1a7a;
	case 6783ULL: goto x86_l_1a7f;
	case 6788ULL: goto x86_l_1a84;
	case 6793ULL: goto x86_l_1a89;
	case 6795ULL: goto x86_l_1a8b;
	case 6797ULL: goto x86_l_1a8d;
	case 6803ULL: goto x86_l_1a93;
	case 6811ULL: goto x86_l_1a9b;
	case 6817ULL: goto x86_l_1aa1;
	case 6823ULL: goto x86_l_1aa7;
	case 6828ULL: goto x86_l_1aac;
	case 6833ULL: goto x86_l_1ab1;
	case 6841ULL: goto x86_l_1ab9;
	case 6843ULL: goto x86_l_1abb;
	case 6848ULL: goto x86_l_1ac0;
	case 6853ULL: goto x86_l_1ac5;
	case 6858ULL: goto x86_l_1aca;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6870ULL: goto x86_l_1ad6;
	case 6872ULL: goto x86_l_1ad8;
	case 6878ULL: goto x86_l_1ade;
	case 6886ULL: goto x86_l_1ae6;
	case 6892ULL: goto x86_l_1aec;
	case 6898ULL: goto x86_l_1af2;
	case 6903ULL: goto x86_l_1af7;
	case 6908ULL: goto x86_l_1afc;
	case 6916ULL: goto x86_l_1b04;
	case 6918ULL: goto x86_l_1b06;
	case 6923ULL: goto x86_l_1b0b;
	case 6928ULL: goto x86_l_1b10;
	case 6933ULL: goto x86_l_1b15;
	case 6938ULL: goto x86_l_1b1a;
	case 6943ULL: goto x86_l_1b1f;
	case 6945ULL: goto x86_l_1b21;
	case 6947ULL: goto x86_l_1b23;
	case 6953ULL: goto x86_l_1b29;
	case 6961ULL: goto x86_l_1b31;
	case 6967ULL: goto x86_l_1b37;
	case 6973ULL: goto x86_l_1b3d;
	case 6978ULL: goto x86_l_1b42;
	case 6983ULL: goto x86_l_1b47;
	case 6991ULL: goto x86_l_1b4f;
	case 6993ULL: goto x86_l_1b51;
	case 6998ULL: goto x86_l_1b56;
	case 7003ULL: goto x86_l_1b5b;
	case 7008ULL: goto x86_l_1b60;
	case 7013ULL: goto x86_l_1b65;
	case 7018ULL: goto x86_l_1b6a;
	case 7020ULL: goto x86_l_1b6c;
	case 7022ULL: goto x86_l_1b6e;
	case 7028ULL: goto x86_l_1b74;
	case 7036ULL: goto x86_l_1b7c;
	case 7042ULL: goto x86_l_1b82;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7058ULL: goto x86_l_1b92;
	case 7066ULL: goto x86_l_1b9a;
	case 7068ULL: goto x86_l_1b9c;
	case 7073ULL: goto x86_l_1ba1;
	case 7078ULL: goto x86_l_1ba6;
	case 7083ULL: goto x86_l_1bab;
	case 7088ULL: goto x86_l_1bb0;
	case 7093ULL: goto x86_l_1bb5;
	case 7095ULL: goto x86_l_1bb7;
	case 7097ULL: goto x86_l_1bb9;
	case 7103ULL: goto x86_l_1bbf;
	case 7111ULL: goto x86_l_1bc7;
	case 7117ULL: goto x86_l_1bcd;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7133ULL: goto x86_l_1bdd;
	case 7141ULL: goto x86_l_1be5;
	case 7147ULL: goto x86_l_1beb;
	case 7152ULL: goto x86_l_1bf0;
	case 7157ULL: goto x86_l_1bf5;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7172ULL: goto x86_l_1c04;
	case 7174ULL: goto x86_l_1c06;
	case 7176ULL: goto x86_l_1c08;
	case 7182ULL: goto x86_l_1c0e;
	case 7190ULL: goto x86_l_1c16;
	case 7195ULL: goto x86_l_1c1b;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7213ULL: goto x86_l_1c2d;
	case 7216ULL: goto x86_l_1c30;
	case 7222ULL: goto x86_l_1c36;
	case 7225ULL: goto x86_l_1c39;
	case 7228ULL: goto x86_l_1c3c;
	case 7234ULL: goto x86_l_1c42;
	case 7239ULL: goto x86_l_1c47;
	case 7244ULL: goto x86_l_1c4c;
	case 7247ULL: goto x86_l_1c4f;
	case 7253ULL: goto x86_l_1c55;
	case 7256ULL: goto x86_l_1c58;
	case 7259ULL: goto x86_l_1c5b;
	case 7265ULL: goto x86_l_1c61;
	case 7270ULL: goto x86_l_1c66;
	case 7275ULL: goto x86_l_1c6b;
	case 7278ULL: goto x86_l_1c6e;
	case 7284ULL: goto x86_l_1c74;
	case 7287ULL: goto x86_l_1c77;
	case 7290ULL: goto x86_l_1c7a;
	case 7296ULL: goto x86_l_1c80;
	case 7301ULL: goto x86_l_1c85;
	case 7306ULL: goto x86_l_1c8a;
	case 7309ULL: goto x86_l_1c8d;
	case 7311ULL: goto x86_l_1c8f;
	case 7314ULL: goto x86_l_1c92;
	case 7317ULL: goto x86_l_1c95;
	case 7319ULL: goto x86_l_1c97;
	case 7322ULL: goto x86_l_1c9a;
	case 7324ULL: goto x86_l_1c9c;
	case 7326ULL: goto x86_l_1c9e;
	case 7331ULL: goto x86_l_1ca3;
	case 7333ULL: goto x86_l_1ca5;
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7347ULL: goto x86_l_1cb3;
	case 7349ULL: goto x86_l_1cb5;
	case 7352ULL: goto x86_l_1cb8;
	case 7360ULL: goto x86_l_1cc0;
	case 7366ULL: goto x86_l_1cc6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_159e:
	/* 0x159e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15a3:
	/* 0x15a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a5:
	/* 0x15a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15a7:
	/* 0x15a7: js     2b82 <generic_sleepable_preload+0x2b82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11138ULL;
	}
x86_l_15ad:
	/* 0x15ad: cmp    WORD PTR [rbx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_15b5:
	/* 0x15b5: je     2f90 <generic_sleepable_preload+0x2f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12176ULL;
	}
x86_l_15bb:
	/* 0x15bb: mov    ecx,DWORD PTR [rbx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_15c1:
	/* 0x15c1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_15c6:
	/* 0x15c6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15cb:
	/* 0x15cb: cmp    WORD PTR [rbx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_15d3:
	/* 0x15d3: je     15f8 <generic_sleepable_preload+0x15f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15f8;
	}
x86_l_15d5:
	/* 0x15d5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15da:
	/* 0x15da: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_15df:
	/* 0x15df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15e4:
	/* 0x15e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15e9:
	/* 0x15e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15ee:
	/* 0x15ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f0:
	/* 0x15f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15f2:
	/* 0x15f2: js     2f88 <generic_sleepable_preload+0x2f88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12168ULL;
	}
x86_l_15f8:
	/* 0x15f8: cmp    WORD PTR [rbx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_1600:
	/* 0x1600: je     2f90 <generic_sleepable_preload+0x2f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12176ULL;
	}
x86_l_1606:
	/* 0x1606: mov    ecx,DWORD PTR [rbx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_160c:
	/* 0x160c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1611:
	/* 0x1611: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1616:
	/* 0x1616: cmp    WORD PTR [rbx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_161e:
	/* 0x161e: je     1643 <generic_sleepable_preload+0x1643> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1643;
	}
x86_l_1620:
	/* 0x1620: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1625:
	/* 0x1625: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_162a:
	/* 0x162a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_162f:
	/* 0x162f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1634:
	/* 0x1634: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1639:
	/* 0x1639: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163b:
	/* 0x163b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_163d:
	/* 0x163d: js     3418 <generic_sleepable_preload+0x3418> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13336ULL;
	}
x86_l_1643:
	/* 0x1643: cmp    WORD PTR [rbx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_164b:
	/* 0x164b: je     2f90 <generic_sleepable_preload+0x2f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12176ULL;
	}
x86_l_1651:
	/* 0x1651: mov    ecx,DWORD PTR [rbx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_1657:
	/* 0x1657: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_165c:
	/* 0x165c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1661:
	/* 0x1661: cmp    WORD PTR [rbx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_1669:
	/* 0x1669: je     168e <generic_sleepable_preload+0x168e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_168e;
	}
x86_l_166b:
	/* 0x166b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1670:
	/* 0x1670: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1675:
	/* 0x1675: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_167a:
	/* 0x167a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_167f:
	/* 0x167f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1684:
	/* 0x1684: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1686:
	/* 0x1686: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1688:
	/* 0x1688: js     34ec <generic_sleepable_preload+0x34ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13548ULL;
	}
x86_l_168e:
	/* 0x168e: cmp    WORD PTR [rbx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_1696:
	/* 0x1696: je     2f90 <generic_sleepable_preload+0x2f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12176ULL;
	}
x86_l_169c:
	/* 0x169c: mov    ecx,DWORD PTR [rbx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_16a2:
	/* 0x16a2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_16a7:
	/* 0x16a7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16ac:
	/* 0x16ac: cmp    WORD PTR [rbx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_16b4:
	/* 0x16b4: je     2f90 <generic_sleepable_preload+0x2f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12176ULL;
	}
x86_l_16ba:
	/* 0x16ba: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16bf:
	/* 0x16bf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_16c4:
	/* 0x16c4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16c9:
	/* 0x16c9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16ce:
	/* 0x16ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16d3:
	/* 0x16d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d5:
	/* 0x16d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16d7:
	/* 0x16d7: jns    2f90 <generic_sleepable_preload+0x2f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12176ULL;
	}
x86_l_16dd:
	/* 0x16dd: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_16e2:
	/* 0x16e2: jmp    2f8d <generic_sleepable_preload+0x2f8d> */
	return 12173ULL;
x86_l_16e7:
	/* 0x16e7: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_16ec:
	/* 0x16ec: jmp    2f8d <generic_sleepable_preload+0x2f8d> */
	return 12173ULL;
x86_l_16f1:
	/* 0x16f1: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_16f9:
	/* 0x16f9: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_16fc:
	/* 0x16fc: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1906;
	}
x86_l_1702:
	/* 0x1702: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1705:
	/* 0x1705: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1708:
	/* 0x1708: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1906;
	}
x86_l_170e:
	/* 0x170e: jmp    1919 <generic_sleepable_preload+0x1919> */
	goto x86_l_1919;
x86_l_1713:
	/* 0x1713: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_171b:
	/* 0x171b: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_171e:
	/* 0x171e: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_1724:
	/* 0x1724: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1727:
	/* 0x1727: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_172a:
	/* 0x172a: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_1730:
	/* 0x1730: jmp    2027 <generic_sleepable_preload+0x2027> */
	return 8231ULL;
x86_l_1735:
	/* 0x1735: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_173d:
	/* 0x173d: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1740:
	/* 0x1740: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_1746:
	/* 0x1746: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1749:
	/* 0x1749: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_174c:
	/* 0x174c: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_1752:
	/* 0x1752: jmp    236b <generic_sleepable_preload+0x236b> */
	return 9067ULL;
x86_l_1757:
	/* 0x1757: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_175f:
	/* 0x175f: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1762:
	/* 0x1762: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_1768:
	/* 0x1768: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_176b:
	/* 0x176b: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_176e:
	/* 0x176e: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_1774:
	/* 0x1774: jmp    26af <generic_sleepable_preload+0x26af> */
	return 9903ULL;
x86_l_1779:
	/* 0x1779: mov    r14,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1781:
	/* 0x1781: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1784:
	/* 0x1784: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c97;
	}
x86_l_178a:
	/* 0x178a: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_178d:
	/* 0x178d: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1790:
	/* 0x1790: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c97;
	}
x86_l_1796:
	/* 0x1796: jmp    1caa <generic_sleepable_preload+0x1caa> */
	goto x86_l_1caa;
x86_l_179b:
	/* 0x179b: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_17a0:
	/* 0x17a0: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_17a3:
	/* 0x17a3: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1906;
	}
x86_l_17a9:
	/* 0x17a9: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17ae:
	/* 0x17ae: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_17b1:
	/* 0x17b1: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1906;
	}
x86_l_17b7:
	/* 0x17b7: jmp    1919 <generic_sleepable_preload+0x1919> */
	goto x86_l_1919;
x86_l_17bc:
	/* 0x17bc: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_17c1:
	/* 0x17c1: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_17c4:
	/* 0x17c4: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_17ca:
	/* 0x17ca: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17cf:
	/* 0x17cf: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_17d2:
	/* 0x17d2: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_17d8:
	/* 0x17d8: jmp    2027 <generic_sleepable_preload+0x2027> */
	return 8231ULL;
x86_l_17dd:
	/* 0x17dd: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_17e2:
	/* 0x17e2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_17e5:
	/* 0x17e5: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_17eb:
	/* 0x17eb: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17f0:
	/* 0x17f0: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_17f3:
	/* 0x17f3: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_17f9:
	/* 0x17f9: jmp    236b <generic_sleepable_preload+0x236b> */
	return 9067ULL;
x86_l_17fe:
	/* 0x17fe: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1803:
	/* 0x1803: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1806:
	/* 0x1806: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_180c:
	/* 0x180c: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1811:
	/* 0x1811: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1814:
	/* 0x1814: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_181a:
	/* 0x181a: jmp    26af <generic_sleepable_preload+0x26af> */
	return 9903ULL;
x86_l_181f:
	/* 0x181f: mov    r14,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1824:
	/* 0x1824: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1827:
	/* 0x1827: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c97;
	}
x86_l_182d:
	/* 0x182d: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1832:
	/* 0x1832: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1835:
	/* 0x1835: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c97;
	}
x86_l_183b:
	/* 0x183b: jmp    1caa <generic_sleepable_preload+0x1caa> */
	goto x86_l_1caa;
x86_l_1840:
	/* 0x1840: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1848:
	/* 0x1848: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_184b:
	/* 0x184b: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1906;
	}
x86_l_1851:
	/* 0x1851: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1856:
	/* 0x1856: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1859:
	/* 0x1859: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1906;
	}
x86_l_185f:
	/* 0x185f: jmp    1919 <generic_sleepable_preload+0x1919> */
	goto x86_l_1919;
x86_l_1864:
	/* 0x1864: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_186c:
	/* 0x186c: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_186f:
	/* 0x186f: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_1875:
	/* 0x1875: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_187a:
	/* 0x187a: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_187d:
	/* 0x187d: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_1883:
	/* 0x1883: jmp    2027 <generic_sleepable_preload+0x2027> */
	return 8231ULL;
x86_l_1888:
	/* 0x1888: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1890:
	/* 0x1890: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1893:
	/* 0x1893: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_1899:
	/* 0x1899: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_189e:
	/* 0x189e: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_18a1:
	/* 0x18a1: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_18a7:
	/* 0x18a7: jmp    236b <generic_sleepable_preload+0x236b> */
	return 9067ULL;
x86_l_18ac:
	/* 0x18ac: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_18b4:
	/* 0x18b4: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_18b7:
	/* 0x18b7: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_18bd:
	/* 0x18bd: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_18c2:
	/* 0x18c2: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_18c5:
	/* 0x18c5: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_18cb:
	/* 0x18cb: jmp    26af <generic_sleepable_preload+0x26af> */
	return 9903ULL;
x86_l_18d0:
	/* 0x18d0: mov    r14,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_18d8:
	/* 0x18d8: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_18db:
	/* 0x18db: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c97;
	}
x86_l_18e1:
	/* 0x18e1: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_18e6:
	/* 0x18e6: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_18e9:
	/* 0x18e9: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c97;
	}
x86_l_18ef:
	/* 0x18ef: jmp    1caa <generic_sleepable_preload+0x1caa> */
	goto x86_l_1caa;
x86_l_18f4:
	/* 0x18f4: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18f9:
	/* 0x18f9: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_18fc:
	/* 0x18fc: je     1906 <generic_sleepable_preload+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1906;
	}
x86_l_18fe:
	/* 0x18fe: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1901:
	/* 0x1901: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1904:
	/* 0x1904: jne    1919 <generic_sleepable_preload+0x1919> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1919;
	}
x86_l_1906:
	/* 0x1906: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1909:
	/* 0x1909: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_190b:
	/* 0x190b: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_190d:
	/* 0x190d: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_1912:
	/* 0x1912: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1914:
	/* 0x1914: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_1919:
	/* 0x1919: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_191e:
	/* 0x191e: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1922:
	/* 0x1922: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_192a:
	/* 0x192a: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_192c:
	/* 0x192c: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1930:
	/* 0x1930: cmp    WORD PTR [rbx+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1935:
	/* 0x1935: je     3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12324ULL;
	}
x86_l_193b:
	/* 0x193b: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_193e:
	/* 0x193e: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1941:
	/* 0x1941: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1946:
	/* 0x1946: cmp    WORD PTR [rbx+0x74],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_194b:
	/* 0x194b: je     1970 <generic_sleepable_preload+0x1970> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1970;
	}
x86_l_194d:
	/* 0x194d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1952:
	/* 0x1952: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1957:
	/* 0x1957: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_195c:
	/* 0x195c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1961:
	/* 0x1961: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1966:
	/* 0x1966: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1968:
	/* 0x1968: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_196a:
	/* 0x196a: js     1c1b <generic_sleepable_preload+0x1c1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c1b;
	}
x86_l_1970:
	/* 0x1970: cmp    WORD PTR [rbx+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1975:
	/* 0x1975: je     3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12324ULL;
	}
x86_l_197b:
	/* 0x197b: mov    ecx,DWORD PTR [rbx+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_197e:
	/* 0x197e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1983:
	/* 0x1983: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1988:
	/* 0x1988: cmp    WORD PTR [rbx+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_198d:
	/* 0x198d: je     19b2 <generic_sleepable_preload+0x19b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19b2;
	}
x86_l_198f:
	/* 0x198f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1994:
	/* 0x1994: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1999:
	/* 0x1999: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_199e:
	/* 0x199e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19a3:
	/* 0x19a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19a8:
	/* 0x19a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19aa:
	/* 0x19aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19ac:
	/* 0x19ac: js     1ffa <generic_sleepable_preload+0x1ffa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8186ULL;
	}
x86_l_19b2:
	/* 0x19b2: cmp    WORD PTR [rbx+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_19ba:
	/* 0x19ba: je     3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12324ULL;
	}
x86_l_19c0:
	/* 0x19c0: mov    ecx,DWORD PTR [rbx+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_19c6:
	/* 0x19c6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_19cb:
	/* 0x19cb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d0:
	/* 0x19d0: cmp    WORD PTR [rbx+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_19d8:
	/* 0x19d8: je     19fd <generic_sleepable_preload+0x19fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19fd;
	}
x86_l_19da:
	/* 0x19da: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19df:
	/* 0x19df: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19e4:
	/* 0x19e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19e9:
	/* 0x19e9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19ee:
	/* 0x19ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19f3:
	/* 0x19f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f5:
	/* 0x19f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19f7:
	/* 0x19f7: js     2a1b <generic_sleepable_preload+0x2a1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10779ULL;
	}
x86_l_19fd:
	/* 0x19fd: cmp    WORD PTR [rbx+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1a05:
	/* 0x1a05: je     3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12324ULL;
	}
x86_l_1a0b:
	/* 0x1a0b: mov    ecx,DWORD PTR [rbx+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a11:
	/* 0x1a11: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1a16:
	/* 0x1a16: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a1b:
	/* 0x1a1b: cmp    WORD PTR [rbx+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1a23:
	/* 0x1a23: je     1a48 <generic_sleepable_preload+0x1a48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a48;
	}
x86_l_1a25:
	/* 0x1a25: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a2a:
	/* 0x1a2a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a2f:
	/* 0x1a2f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a34:
	/* 0x1a34: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a39:
	/* 0x1a39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a3e:
	/* 0x1a3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a40:
	/* 0x1a40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a42:
	/* 0x1a42: js     2a97 <generic_sleepable_preload+0x2a97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10903ULL;
	}
x86_l_1a48:
	/* 0x1a48: cmp    WORD PTR [rbx+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1a50:
	/* 0x1a50: je     3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12324ULL;
	}
x86_l_1a56:
	/* 0x1a56: mov    ecx,DWORD PTR [rbx+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1a5c:
	/* 0x1a5c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1a61:
	/* 0x1a61: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a66:
	/* 0x1a66: cmp    WORD PTR [rbx+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1a6e:
	/* 0x1a6e: je     1a93 <generic_sleepable_preload+0x1a93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a93;
	}
x86_l_1a70:
	/* 0x1a70: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a75:
	/* 0x1a75: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a7a:
	/* 0x1a7a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a7f:
	/* 0x1a7f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a84:
	/* 0x1a84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a89:
	/* 0x1a89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8b:
	/* 0x1a8b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a8d:
	/* 0x1a8d: js     2b13 <generic_sleepable_preload+0x2b13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11027ULL;
	}
x86_l_1a93:
	/* 0x1a93: cmp    WORD PTR [rbx+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1a9b:
	/* 0x1a9b: je     3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12324ULL;
	}
x86_l_1aa1:
	/* 0x1aa1: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1aa7:
	/* 0x1aa7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1aac:
	/* 0x1aac: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ab1:
	/* 0x1ab1: cmp    WORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1ab9:
	/* 0x1ab9: je     1ade <generic_sleepable_preload+0x1ade> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ade;
	}
x86_l_1abb:
	/* 0x1abb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ac5:
	/* 0x1ac5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1aca:
	/* 0x1aca: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1acf:
	/* 0x1acf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ad4:
	/* 0x1ad4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad6:
	/* 0x1ad6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ad8:
	/* 0x1ad8: js     2b8c <generic_sleepable_preload+0x2b8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11148ULL;
	}
x86_l_1ade:
	/* 0x1ade: cmp    WORD PTR [rbx+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1ae6:
	/* 0x1ae6: je     3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12324ULL;
	}
x86_l_1aec:
	/* 0x1aec: mov    ecx,DWORD PTR [rbx+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1af2:
	/* 0x1af2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1af7:
	/* 0x1af7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1afc:
	/* 0x1afc: cmp    WORD PTR [rbx+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1b04:
	/* 0x1b04: je     1b29 <generic_sleepable_preload+0x1b29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b29;
	}
x86_l_1b06:
	/* 0x1b06: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b0b:
	/* 0x1b0b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b10:
	/* 0x1b10: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b15:
	/* 0x1b15: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b1a:
	/* 0x1b1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b1f:
	/* 0x1b1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b21:
	/* 0x1b21: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b23:
	/* 0x1b23: js     3014 <generic_sleepable_preload+0x3014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12308ULL;
	}
x86_l_1b29:
	/* 0x1b29: cmp    WORD PTR [rbx+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1b31:
	/* 0x1b31: je     3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12324ULL;
	}
x86_l_1b37:
	/* 0x1b37: mov    ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1b3d:
	/* 0x1b3d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b42:
	/* 0x1b42: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b47:
	/* 0x1b47: cmp    WORD PTR [rbx+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1b4f:
	/* 0x1b4f: je     1b74 <generic_sleepable_preload+0x1b74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b74;
	}
x86_l_1b51:
	/* 0x1b51: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b56:
	/* 0x1b56: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b5b:
	/* 0x1b5b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b60:
	/* 0x1b60: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b65:
	/* 0x1b65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b6a:
	/* 0x1b6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b6c:
	/* 0x1b6c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b6e:
	/* 0x1b6e: js     3425 <generic_sleepable_preload+0x3425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13349ULL;
	}
x86_l_1b74:
	/* 0x1b74: cmp    WORD PTR [rbx+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1b7c:
	/* 0x1b7c: je     3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12324ULL;
	}
x86_l_1b82:
	/* 0x1b82: mov    ecx,DWORD PTR [rbx+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1b88:
	/* 0x1b88: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b8d:
	/* 0x1b8d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b92:
	/* 0x1b92: cmp    WORD PTR [rbx+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1b9a:
	/* 0x1b9a: je     1bbf <generic_sleepable_preload+0x1bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bbf;
	}
x86_l_1b9c:
	/* 0x1b9c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ba1:
	/* 0x1ba1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ba6:
	/* 0x1ba6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1bab:
	/* 0x1bab: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bb0:
	/* 0x1bb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bb5:
	/* 0x1bb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb7:
	/* 0x1bb7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bb9:
	/* 0x1bb9: js     34f6 <generic_sleepable_preload+0x34f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13558ULL;
	}
x86_l_1bbf:
	/* 0x1bbf: cmp    WORD PTR [rbx+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1bc7:
	/* 0x1bc7: je     3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12324ULL;
	}
x86_l_1bcd:
	/* 0x1bcd: mov    ecx,DWORD PTR [rbx+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1bd3:
	/* 0x1bd3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1bd8:
	/* 0x1bd8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bdd:
	/* 0x1bdd: cmp    WORD PTR [rbx+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1be5:
	/* 0x1be5: je     3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12324ULL;
	}
x86_l_1beb:
	/* 0x1beb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bf0:
	/* 0x1bf0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1bf5:
	/* 0x1bf5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1bfa:
	/* 0x1bfa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bff:
	/* 0x1bff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c04:
	/* 0x1c04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c06:
	/* 0x1c06: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c08:
	/* 0x1c08: jns    3024 <generic_sleepable_preload+0x3024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12324ULL;
	}
x86_l_1c0e:
	/* 0x1c0e: mov    DWORD PTR [rsp+0x18],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215114ULL);
x86_l_1c16:
	/* 0x1c16: jmp    301c <generic_sleepable_preload+0x301c> */
	return 12316ULL;
x86_l_1c1b:
	/* 0x1c1b: mov    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_1c23:
	/* 0x1c23: jmp    301c <generic_sleepable_preload+0x301c> */
	return 12316ULL;
x86_l_1c28:
	/* 0x1c28: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c2d:
	/* 0x1c2d: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1c30:
	/* 0x1c30: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_1c36:
	/* 0x1c36: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1c39:
	/* 0x1c39: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1c3c:
	/* 0x1c3c: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_1c42:
	/* 0x1c42: jmp    2027 <generic_sleepable_preload+0x2027> */
	return 8231ULL;
x86_l_1c47:
	/* 0x1c47: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c4c:
	/* 0x1c4c: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1c4f:
	/* 0x1c4f: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_1c55:
	/* 0x1c55: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1c58:
	/* 0x1c58: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1c5b:
	/* 0x1c5b: je     2358 <generic_sleepable_preload+0x2358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9048ULL;
	}
x86_l_1c61:
	/* 0x1c61: jmp    236b <generic_sleepable_preload+0x236b> */
	return 9067ULL;
x86_l_1c66:
	/* 0x1c66: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c6b:
	/* 0x1c6b: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1c6e:
	/* 0x1c6e: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_1c74:
	/* 0x1c74: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1c77:
	/* 0x1c77: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1c7a:
	/* 0x1c7a: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9884ULL;
	}
x86_l_1c80:
	/* 0x1c80: jmp    26af <generic_sleepable_preload+0x26af> */
	return 9903ULL;
x86_l_1c85:
	/* 0x1c85: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c8a:
	/* 0x1c8a: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1c8d:
	/* 0x1c8d: je     1c97 <generic_sleepable_preload+0x1c97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c97;
	}
x86_l_1c8f:
	/* 0x1c8f: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_1c92:
	/* 0x1c92: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1c95:
	/* 0x1c95: jne    1caa <generic_sleepable_preload+0x1caa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1caa;
	}
x86_l_1c97:
	/* 0x1c97: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1c9a:
	/* 0x1c9a: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_1c9c:
	/* 0x1c9c: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1c9e:
	/* 0x1c9e: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_1ca3:
	/* 0x1ca3: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ca5:
	/* 0x1ca5: bzhi   rcx,QWORD PTR [r14],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_1caa:
	/* 0x1caa: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1caf:
	/* 0x1caf: mov    r14d,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1cb3:
	/* 0x1cb3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cb5:
	/* 0x1cb5: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_1cb8:
	/* 0x1cb8: cmp    WORD PTR [rbx+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_1cc0:
	/* 0x1cc0: je     30f9 <generic_sleepable_preload+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12537ULL;
	}
x86_l_1cc6:
	/* 0x1cc6: mov    eax,DWORD PTR [rbx+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
	return 7372ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7372ULL: goto x86_l_1ccc;
	case 7375ULL: goto x86_l_1ccf;
	case 7380ULL: goto x86_l_1cd4;
	case 7388ULL: goto x86_l_1cdc;
	case 7390ULL: goto x86_l_1cde;
	case 7395ULL: goto x86_l_1ce3;
	case 7400ULL: goto x86_l_1ce8;
	case 7405ULL: goto x86_l_1ced;
	case 7410ULL: goto x86_l_1cf2;
	case 7415ULL: goto x86_l_1cf7;
	case 7417ULL: goto x86_l_1cf9;
	case 7419ULL: goto x86_l_1cfb;
	case 7425ULL: goto x86_l_1d01;
	case 7433ULL: goto x86_l_1d09;
	case 7439ULL: goto x86_l_1d0f;
	case 7445ULL: goto x86_l_1d15;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7463ULL: goto x86_l_1d27;
	case 7465ULL: goto x86_l_1d29;
	case 7470ULL: goto x86_l_1d2e;
	case 7475ULL: goto x86_l_1d33;
	case 7480ULL: goto x86_l_1d38;
	case 7485ULL: goto x86_l_1d3d;
	case 7490ULL: goto x86_l_1d42;
	case 7492ULL: goto x86_l_1d44;
	case 7494ULL: goto x86_l_1d46;
	case 7500ULL: goto x86_l_1d4c;
	case 7508ULL: goto x86_l_1d54;
	case 7514ULL: goto x86_l_1d5a;
	case 7520ULL: goto x86_l_1d60;
	case 7525ULL: goto x86_l_1d65;
	case 7530ULL: goto x86_l_1d6a;
	case 7538ULL: goto x86_l_1d72;
	case 7540ULL: goto x86_l_1d74;
	case 7545ULL: goto x86_l_1d79;
	case 7550ULL: goto x86_l_1d7e;
	case 7555ULL: goto x86_l_1d83;
	case 7560ULL: goto x86_l_1d88;
	case 7565ULL: goto x86_l_1d8d;
	case 7567ULL: goto x86_l_1d8f;
	case 7569ULL: goto x86_l_1d91;
	case 7575ULL: goto x86_l_1d97;
	case 7583ULL: goto x86_l_1d9f;
	case 7589ULL: goto x86_l_1da5;
	case 7595ULL: goto x86_l_1dab;
	case 7600ULL: goto x86_l_1db0;
	case 7605ULL: goto x86_l_1db5;
	case 7613ULL: goto x86_l_1dbd;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7625ULL: goto x86_l_1dc9;
	case 7630ULL: goto x86_l_1dce;
	case 7635ULL: goto x86_l_1dd3;
	case 7640ULL: goto x86_l_1dd8;
	case 7642ULL: goto x86_l_1dda;
	case 7644ULL: goto x86_l_1ddc;
	case 7650ULL: goto x86_l_1de2;
	case 7658ULL: goto x86_l_1dea;
	case 7664ULL: goto x86_l_1df0;
	case 7670ULL: goto x86_l_1df6;
	case 7675ULL: goto x86_l_1dfb;
	case 7680ULL: goto x86_l_1e00;
	case 7688ULL: goto x86_l_1e08;
	case 7690ULL: goto x86_l_1e0a;
	case 7695ULL: goto x86_l_1e0f;
	case 7700ULL: goto x86_l_1e14;
	case 7705ULL: goto x86_l_1e19;
	case 7710ULL: goto x86_l_1e1e;
	case 7715ULL: goto x86_l_1e23;
	case 7717ULL: goto x86_l_1e25;
	case 7719ULL: goto x86_l_1e27;
	case 7725ULL: goto x86_l_1e2d;
	case 7733ULL: goto x86_l_1e35;
	case 7739ULL: goto x86_l_1e3b;
	case 7745ULL: goto x86_l_1e41;
	case 7750ULL: goto x86_l_1e46;
	case 7755ULL: goto x86_l_1e4b;
	case 7763ULL: goto x86_l_1e53;
	case 7765ULL: goto x86_l_1e55;
	case 7770ULL: goto x86_l_1e5a;
	case 7775ULL: goto x86_l_1e5f;
	case 7780ULL: goto x86_l_1e64;
	case 7785ULL: goto x86_l_1e69;
	case 7790ULL: goto x86_l_1e6e;
	case 7792ULL: goto x86_l_1e70;
	case 7794ULL: goto x86_l_1e72;
	case 7800ULL: goto x86_l_1e78;
	case 7808ULL: goto x86_l_1e80;
	case 7814ULL: goto x86_l_1e86;
	case 7820ULL: goto x86_l_1e8c;
	case 7825ULL: goto x86_l_1e91;
	case 7830ULL: goto x86_l_1e96;
	case 7838ULL: goto x86_l_1e9e;
	case 7840ULL: goto x86_l_1ea0;
	case 7845ULL: goto x86_l_1ea5;
	case 7850ULL: goto x86_l_1eaa;
	case 7855ULL: goto x86_l_1eaf;
	case 7860ULL: goto x86_l_1eb4;
	case 7865ULL: goto x86_l_1eb9;
	case 7867ULL: goto x86_l_1ebb;
	case 7869ULL: goto x86_l_1ebd;
	case 7875ULL: goto x86_l_1ec3;
	case 7883ULL: goto x86_l_1ecb;
	case 7889ULL: goto x86_l_1ed1;
	case 7895ULL: goto x86_l_1ed7;
	case 7900ULL: goto x86_l_1edc;
	case 7905ULL: goto x86_l_1ee1;
	case 7913ULL: goto x86_l_1ee9;
	case 7915ULL: goto x86_l_1eeb;
	case 7920ULL: goto x86_l_1ef0;
	case 7925ULL: goto x86_l_1ef5;
	case 7930ULL: goto x86_l_1efa;
	case 7935ULL: goto x86_l_1eff;
	case 7940ULL: goto x86_l_1f04;
	case 7942ULL: goto x86_l_1f06;
	case 7944ULL: goto x86_l_1f08;
	case 7950ULL: goto x86_l_1f0e;
	case 7958ULL: goto x86_l_1f16;
	case 7964ULL: goto x86_l_1f1c;
	case 7970ULL: goto x86_l_1f22;
	case 7975ULL: goto x86_l_1f27;
	case 7980ULL: goto x86_l_1f2c;
	case 7988ULL: goto x86_l_1f34;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8015ULL: goto x86_l_1f4f;
	case 8017ULL: goto x86_l_1f51;
	case 8019ULL: goto x86_l_1f53;
	case 8025ULL: goto x86_l_1f59;
	case 8033ULL: goto x86_l_1f61;
	case 8039ULL: goto x86_l_1f67;
	case 8045ULL: goto x86_l_1f6d;
	case 8050ULL: goto x86_l_1f72;
	case 8055ULL: goto x86_l_1f77;
	case 8063ULL: goto x86_l_1f7f;
	case 8069ULL: goto x86_l_1f85;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8084ULL: goto x86_l_1f94;
	case 8089ULL: goto x86_l_1f99;
	case 8094ULL: goto x86_l_1f9e;
	case 8096ULL: goto x86_l_1fa0;
	case 8098ULL: goto x86_l_1fa2;
	case 8104ULL: goto x86_l_1fa8;
	case 8109ULL: goto x86_l_1fad;
	case 8114ULL: goto x86_l_1fb2;
	case 8119ULL: goto x86_l_1fb7;
	case 8124ULL: goto x86_l_1fbc;
	case 8132ULL: goto x86_l_1fc4;
	case 8137ULL: goto x86_l_1fc9;
	case 8145ULL: goto x86_l_1fd1;
	case 8150ULL: goto x86_l_1fd6;
	case 8158ULL: goto x86_l_1fde;
	case 8163ULL: goto x86_l_1fe3;
	case 8171ULL: goto x86_l_1feb;
	case 8176ULL: goto x86_l_1ff0;
	case 8181ULL: goto x86_l_1ff5;
	case 8186ULL: goto x86_l_1ffa;
	case 8194ULL: goto x86_l_2002;
	case 8199ULL: goto x86_l_2007;
	case 8204ULL: goto x86_l_200c;
	case 8209ULL: goto x86_l_2011;
	case 8212ULL: goto x86_l_2014;
	case 8215ULL: goto x86_l_2017;
	case 8217ULL: goto x86_l_2019;
	case 8219ULL: goto x86_l_201b;
	case 8224ULL: goto x86_l_2020;
	case 8226ULL: goto x86_l_2022;
	case 8231ULL: goto x86_l_2027;
	case 8236ULL: goto x86_l_202c;
	case 8240ULL: goto x86_l_2030;
	case 8248ULL: goto x86_l_2038;
	case 8250ULL: goto x86_l_203a;
	case 8254ULL: goto x86_l_203e;
	case 8262ULL: goto x86_l_2046;
	case 8268ULL: goto x86_l_204c;
	case 8274ULL: goto x86_l_2052;
	case 8277ULL: goto x86_l_2055;
	case 8282ULL: goto x86_l_205a;
	case 8290ULL: goto x86_l_2062;
	case 8292ULL: goto x86_l_2064;
	case 8297ULL: goto x86_l_2069;
	case 8302ULL: goto x86_l_206e;
	case 8307ULL: goto x86_l_2073;
	case 8312ULL: goto x86_l_2078;
	case 8317ULL: goto x86_l_207d;
	case 8319ULL: goto x86_l_207f;
	case 8321ULL: goto x86_l_2081;
	case 8327ULL: goto x86_l_2087;
	case 8335ULL: goto x86_l_208f;
	case 8341ULL: goto x86_l_2095;
	case 8347ULL: goto x86_l_209b;
	case 8352ULL: goto x86_l_20a0;
	case 8357ULL: goto x86_l_20a5;
	case 8365ULL: goto x86_l_20ad;
	case 8367ULL: goto x86_l_20af;
	case 8372ULL: goto x86_l_20b4;
	case 8377ULL: goto x86_l_20b9;
	case 8382ULL: goto x86_l_20be;
	case 8387ULL: goto x86_l_20c3;
	case 8392ULL: goto x86_l_20c8;
	case 8394ULL: goto x86_l_20ca;
	case 8396ULL: goto x86_l_20cc;
	case 8402ULL: goto x86_l_20d2;
	case 8410ULL: goto x86_l_20da;
	case 8416ULL: goto x86_l_20e0;
	case 8422ULL: goto x86_l_20e6;
	case 8427ULL: goto x86_l_20eb;
	case 8432ULL: goto x86_l_20f0;
	case 8440ULL: goto x86_l_20f8;
	case 8442ULL: goto x86_l_20fa;
	case 8447ULL: goto x86_l_20ff;
	case 8452ULL: goto x86_l_2104;
	case 8457ULL: goto x86_l_2109;
	case 8462ULL: goto x86_l_210e;
	case 8467ULL: goto x86_l_2113;
	case 8469ULL: goto x86_l_2115;
	case 8471ULL: goto x86_l_2117;
	case 8477ULL: goto x86_l_211d;
	case 8485ULL: goto x86_l_2125;
	case 8491ULL: goto x86_l_212b;
	case 8497ULL: goto x86_l_2131;
	case 8502ULL: goto x86_l_2136;
	case 8507ULL: goto x86_l_213b;
	case 8515ULL: goto x86_l_2143;
	case 8517ULL: goto x86_l_2145;
	case 8522ULL: goto x86_l_214a;
	case 8527ULL: goto x86_l_214f;
	case 8532ULL: goto x86_l_2154;
	case 8537ULL: goto x86_l_2159;
	case 8542ULL: goto x86_l_215e;
	case 8544ULL: goto x86_l_2160;
	case 8546ULL: goto x86_l_2162;
	case 8552ULL: goto x86_l_2168;
	case 8560ULL: goto x86_l_2170;
	case 8566ULL: goto x86_l_2176;
	case 8572ULL: goto x86_l_217c;
	case 8577ULL: goto x86_l_2181;
	case 8582ULL: goto x86_l_2186;
	case 8590ULL: goto x86_l_218e;
	case 8592ULL: goto x86_l_2190;
	case 8597ULL: goto x86_l_2195;
	case 8602ULL: goto x86_l_219a;
	case 8607ULL: goto x86_l_219f;
	case 8612ULL: goto x86_l_21a4;
	case 8617ULL: goto x86_l_21a9;
	case 8619ULL: goto x86_l_21ab;
	case 8621ULL: goto x86_l_21ad;
	case 8627ULL: goto x86_l_21b3;
	case 8635ULL: goto x86_l_21bb;
	case 8641ULL: goto x86_l_21c1;
	case 8647ULL: goto x86_l_21c7;
	case 8652ULL: goto x86_l_21cc;
	case 8657ULL: goto x86_l_21d1;
	case 8665ULL: goto x86_l_21d9;
	case 8667ULL: goto x86_l_21db;
	case 8672ULL: goto x86_l_21e0;
	case 8677ULL: goto x86_l_21e5;
	case 8682ULL: goto x86_l_21ea;
	case 8687ULL: goto x86_l_21ef;
	case 8692ULL: goto x86_l_21f4;
	case 8694ULL: goto x86_l_21f6;
	case 8696ULL: goto x86_l_21f8;
	case 8702ULL: goto x86_l_21fe;
	case 8710ULL: goto x86_l_2206;
	case 8716ULL: goto x86_l_220c;
	case 8722ULL: goto x86_l_2212;
	case 8727ULL: goto x86_l_2217;
	case 8732ULL: goto x86_l_221c;
	case 8740ULL: goto x86_l_2224;
	case 8742ULL: goto x86_l_2226;
	case 8747ULL: goto x86_l_222b;
	case 8752ULL: goto x86_l_2230;
	case 8757ULL: goto x86_l_2235;
	case 8762ULL: goto x86_l_223a;
	case 8767ULL: goto x86_l_223f;
	case 8769ULL: goto x86_l_2241;
	case 8771ULL: goto x86_l_2243;
	case 8777ULL: goto x86_l_2249;
	case 8785ULL: goto x86_l_2251;
	case 8791ULL: goto x86_l_2257;
	case 8797ULL: goto x86_l_225d;
	case 8802ULL: goto x86_l_2262;
	case 8807ULL: goto x86_l_2267;
	case 8815ULL: goto x86_l_226f;
	case 8817ULL: goto x86_l_2271;
	case 8822ULL: goto x86_l_2276;
	case 8827ULL: goto x86_l_227b;
	case 8832ULL: goto x86_l_2280;
	case 8837ULL: goto x86_l_2285;
	case 8842ULL: goto x86_l_228a;
	case 8844ULL: goto x86_l_228c;
	case 8846ULL: goto x86_l_228e;
	case 8852ULL: goto x86_l_2294;
	case 8860ULL: goto x86_l_229c;
	case 8866ULL: goto x86_l_22a2;
	case 8872ULL: goto x86_l_22a8;
	case 8877ULL: goto x86_l_22ad;
	case 8882ULL: goto x86_l_22b2;
	case 8890ULL: goto x86_l_22ba;
	case 8892ULL: goto x86_l_22bc;
	case 8897ULL: goto x86_l_22c1;
	case 8902ULL: goto x86_l_22c6;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	case 8919ULL: goto x86_l_22d7;
	case 8921ULL: goto x86_l_22d9;
	case 8927ULL: goto x86_l_22df;
	case 8935ULL: goto x86_l_22e7;
	case 8941ULL: goto x86_l_22ed;
	case 8947ULL: goto x86_l_22f3;
	case 8952ULL: goto x86_l_22f8;
	case 8957ULL: goto x86_l_22fd;
	case 8965ULL: goto x86_l_2305;
	case 8971ULL: goto x86_l_230b;
	case 8976ULL: goto x86_l_2310;
	case 8981ULL: goto x86_l_2315;
	case 8986ULL: goto x86_l_231a;
	case 8991ULL: goto x86_l_231f;
	case 8996ULL: goto x86_l_2324;
	case 8998ULL: goto x86_l_2326;
	case 9000ULL: goto x86_l_2328;
	case 9006ULL: goto x86_l_232e;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9027ULL: goto x86_l_2343;
	case 9032ULL: goto x86_l_2348;
	case 9040ULL: goto x86_l_2350;
	case 9045ULL: goto x86_l_2355;
	case 9048ULL: goto x86_l_2358;
	case 9051ULL: goto x86_l_235b;
	case 9053ULL: goto x86_l_235d;
	case 9055ULL: goto x86_l_235f;
	case 9060ULL: goto x86_l_2364;
	case 9062ULL: goto x86_l_2366;
	case 9067ULL: goto x86_l_236b;
	case 9072ULL: goto x86_l_2370;
	case 9076ULL: goto x86_l_2374;
	case 9084ULL: goto x86_l_237c;
	case 9086ULL: goto x86_l_237e;
	case 9090ULL: goto x86_l_2382;
	case 9098ULL: goto x86_l_238a;
	case 9104ULL: goto x86_l_2390;
	case 9110ULL: goto x86_l_2396;
	case 9113ULL: goto x86_l_2399;
	case 9118ULL: goto x86_l_239e;
	case 9126ULL: goto x86_l_23a6;
	case 9128ULL: goto x86_l_23a8;
	case 9133ULL: goto x86_l_23ad;
	case 9138ULL: goto x86_l_23b2;
	case 9143ULL: goto x86_l_23b7;
	case 9148ULL: goto x86_l_23bc;
	case 9153ULL: goto x86_l_23c1;
	case 9155ULL: goto x86_l_23c3;
	case 9157ULL: goto x86_l_23c5;
	case 9163ULL: goto x86_l_23cb;
	case 9171ULL: goto x86_l_23d3;
	case 9177ULL: goto x86_l_23d9;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9193ULL: goto x86_l_23e9;
	case 9201ULL: goto x86_l_23f1;
	case 9203ULL: goto x86_l_23f3;
	case 9208ULL: goto x86_l_23f8;
	case 9213ULL: goto x86_l_23fd;
	case 9218ULL: goto x86_l_2402;
	case 9223ULL: goto x86_l_2407;
	case 9228ULL: goto x86_l_240c;
	case 9230ULL: goto x86_l_240e;
	case 9232ULL: goto x86_l_2410;
	case 9238ULL: goto x86_l_2416;
	case 9246ULL: goto x86_l_241e;
	case 9252ULL: goto x86_l_2424;
	case 9258ULL: goto x86_l_242a;
	case 9263ULL: goto x86_l_242f;
	case 9268ULL: goto x86_l_2434;
	case 9276ULL: goto x86_l_243c;
	case 9278ULL: goto x86_l_243e;
	case 9283ULL: goto x86_l_2443;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ccc:
	/* 0x1ccc: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ccf:
	/* 0x1ccf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd4:
	/* 0x1cd4: cmp    WORD PTR [rbx+0x1b4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1872605741056ULL);
x86_l_1cdc:
	/* 0x1cdc: je     1d01 <generic_sleepable_preload+0x1d01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d01;
	}
x86_l_1cde:
	/* 0x1cde: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ce3:
	/* 0x1ce3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ce8:
	/* 0x1ce8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ced:
	/* 0x1ced: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cf2:
	/* 0x1cf2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cf7:
	/* 0x1cf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf9:
	/* 0x1cf9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cfb:
	/* 0x1cfb: js     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1fb2;
	}
x86_l_1d01:
	/* 0x1d01: cmp    WORD PTR [rbx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_1d09:
	/* 0x1d09: je     30f9 <generic_sleepable_preload+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12537ULL;
	}
x86_l_1d0f:
	/* 0x1d0f: mov    ecx,DWORD PTR [rbx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_1d15:
	/* 0x1d15: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1d1a:
	/* 0x1d1a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d1f:
	/* 0x1d1f: cmp    WORD PTR [rbx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_1d27:
	/* 0x1d27: je     1d4c <generic_sleepable_preload+0x1d4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d4c;
	}
x86_l_1d29:
	/* 0x1d29: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d2e:
	/* 0x1d2e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d33:
	/* 0x1d33: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d38:
	/* 0x1d38: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d3d:
	/* 0x1d3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d42:
	/* 0x1d42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d44:
	/* 0x1d44: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d46:
	/* 0x1d46: js     2007 <generic_sleepable_preload+0x2007> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2007;
	}
x86_l_1d4c:
	/* 0x1d4c: cmp    WORD PTR [rbx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_1d54:
	/* 0x1d54: je     30f9 <generic_sleepable_preload+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12537ULL;
	}
x86_l_1d5a:
	/* 0x1d5a: mov    ecx,DWORD PTR [rbx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_1d60:
	/* 0x1d60: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1d65:
	/* 0x1d65: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d6a:
	/* 0x1d6a: cmp    WORD PTR [rbx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_1d72:
	/* 0x1d72: je     1d97 <generic_sleepable_preload+0x1d97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d97;
	}
x86_l_1d74:
	/* 0x1d74: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d79:
	/* 0x1d79: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d7e:
	/* 0x1d7e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d83:
	/* 0x1d83: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d88:
	/* 0x1d88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d8d:
	/* 0x1d8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d8f:
	/* 0x1d8f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d91:
	/* 0x1d91: js     2a28 <generic_sleepable_preload+0x2a28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10792ULL;
	}
x86_l_1d97:
	/* 0x1d97: cmp    WORD PTR [rbx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_1d9f:
	/* 0x1d9f: je     30f9 <generic_sleepable_preload+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12537ULL;
	}
x86_l_1da5:
	/* 0x1da5: mov    ecx,DWORD PTR [rbx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_1dab:
	/* 0x1dab: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1db0:
	/* 0x1db0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1db5:
	/* 0x1db5: cmp    WORD PTR [rbx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_1dbd:
	/* 0x1dbd: je     1de2 <generic_sleepable_preload+0x1de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1de2;
	}
x86_l_1dbf:
	/* 0x1dbf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dc4:
	/* 0x1dc4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1dc9:
	/* 0x1dc9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1dce:
	/* 0x1dce: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dd3:
	/* 0x1dd3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dd8:
	/* 0x1dd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dda:
	/* 0x1dda: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ddc:
	/* 0x1ddc: js     2aa4 <generic_sleepable_preload+0x2aa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10916ULL;
	}
x86_l_1de2:
	/* 0x1de2: cmp    WORD PTR [rbx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_1dea:
	/* 0x1dea: je     30f9 <generic_sleepable_preload+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12537ULL;
	}
x86_l_1df0:
	/* 0x1df0: mov    ecx,DWORD PTR [rbx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_1df6:
	/* 0x1df6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1dfb:
	/* 0x1dfb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e00:
	/* 0x1e00: cmp    WORD PTR [rbx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_1e08:
	/* 0x1e08: je     1e2d <generic_sleepable_preload+0x1e2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e2d;
	}
x86_l_1e0a:
	/* 0x1e0a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e0f:
	/* 0x1e0f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e14:
	/* 0x1e14: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e19:
	/* 0x1e19: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e1e:
	/* 0x1e1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e23:
	/* 0x1e23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e25:
	/* 0x1e25: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e27:
	/* 0x1e27: js     2b20 <generic_sleepable_preload+0x2b20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11040ULL;
	}
x86_l_1e2d:
	/* 0x1e2d: cmp    WORD PTR [rbx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_1e35:
	/* 0x1e35: je     30f9 <generic_sleepable_preload+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12537ULL;
	}
x86_l_1e3b:
	/* 0x1e3b: mov    ecx,DWORD PTR [rbx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_1e41:
	/* 0x1e41: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e46:
	/* 0x1e46: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e4b:
	/* 0x1e4b: cmp    WORD PTR [rbx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_1e53:
	/* 0x1e53: je     1e78 <generic_sleepable_preload+0x1e78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e78;
	}
x86_l_1e55:
	/* 0x1e55: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e5a:
	/* 0x1e5a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e5f:
	/* 0x1e5f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e64:
	/* 0x1e64: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e69:
	/* 0x1e69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e6e:
	/* 0x1e6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e70:
	/* 0x1e70: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e72:
	/* 0x1e72: js     2b99 <generic_sleepable_preload+0x2b99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11161ULL;
	}
x86_l_1e78:
	/* 0x1e78: cmp    WORD PTR [rbx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_1e80:
	/* 0x1e80: je     30f9 <generic_sleepable_preload+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12537ULL;
	}
x86_l_1e86:
	/* 0x1e86: mov    ecx,DWORD PTR [rbx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_1e8c:
	/* 0x1e8c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e91:
	/* 0x1e91: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e96:
	/* 0x1e96: cmp    WORD PTR [rbx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_1e9e:
	/* 0x1e9e: je     1ec3 <generic_sleepable_preload+0x1ec3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ec3;
	}
x86_l_1ea0:
	/* 0x1ea0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ea5:
	/* 0x1ea5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1eaa:
	/* 0x1eaa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1eaf:
	/* 0x1eaf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eb4:
	/* 0x1eb4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eb9:
	/* 0x1eb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ebb:
	/* 0x1ebb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ebd:
	/* 0x1ebd: js     30f1 <generic_sleepable_preload+0x30f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12529ULL;
	}
x86_l_1ec3:
	/* 0x1ec3: cmp    WORD PTR [rbx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_1ecb:
	/* 0x1ecb: je     30f9 <generic_sleepable_preload+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12537ULL;
	}
x86_l_1ed1:
	/* 0x1ed1: mov    ecx,DWORD PTR [rbx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_1ed7:
	/* 0x1ed7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1edc:
	/* 0x1edc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ee1:
	/* 0x1ee1: cmp    WORD PTR [rbx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_1ee9:
	/* 0x1ee9: je     1f0e <generic_sleepable_preload+0x1f0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f0e;
	}
x86_l_1eeb:
	/* 0x1eeb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ef0:
	/* 0x1ef0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ef5:
	/* 0x1ef5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1efa:
	/* 0x1efa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eff:
	/* 0x1eff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f04:
	/* 0x1f04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f06:
	/* 0x1f06: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f08:
	/* 0x1f08: js     3444 <generic_sleepable_preload+0x3444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13380ULL;
	}
x86_l_1f0e:
	/* 0x1f0e: cmp    WORD PTR [rbx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_1f16:
	/* 0x1f16: je     30f9 <generic_sleepable_preload+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12537ULL;
	}
x86_l_1f1c:
	/* 0x1f1c: mov    ecx,DWORD PTR [rbx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_1f22:
	/* 0x1f22: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1f27:
	/* 0x1f27: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f2c:
	/* 0x1f2c: cmp    WORD PTR [rbx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_1f34:
	/* 0x1f34: je     1f59 <generic_sleepable_preload+0x1f59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f59;
	}
x86_l_1f36:
	/* 0x1f36: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f3b:
	/* 0x1f3b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f40:
	/* 0x1f40: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f45:
	/* 0x1f45: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f4a:
	/* 0x1f4a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f4f:
	/* 0x1f4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f51:
	/* 0x1f51: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f53:
	/* 0x1f53: js     3503 <generic_sleepable_preload+0x3503> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13571ULL;
	}
x86_l_1f59:
	/* 0x1f59: cmp    WORD PTR [rbx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_1f61:
	/* 0x1f61: je     30f9 <generic_sleepable_preload+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12537ULL;
	}
x86_l_1f67:
	/* 0x1f67: mov    ecx,DWORD PTR [rbx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_1f6d:
	/* 0x1f6d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1f72:
	/* 0x1f72: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f77:
	/* 0x1f77: cmp    WORD PTR [rbx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_1f7f:
	/* 0x1f7f: je     30f9 <generic_sleepable_preload+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12537ULL;
	}
x86_l_1f85:
	/* 0x1f85: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f8a:
	/* 0x1f8a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f8f:
	/* 0x1f8f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f94:
	/* 0x1f94: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f99:
	/* 0x1f99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f9e:
	/* 0x1f9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa0:
	/* 0x1fa0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fa2:
	/* 0x1fa2: jns    30f9 <generic_sleepable_preload+0x30f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12537ULL;
	}
x86_l_1fa8:
	/* 0x1fa8: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_1fad:
	/* 0x1fad: jmp    30f6 <generic_sleepable_preload+0x30f6> */
	return 12534ULL;
x86_l_1fb2:
	/* 0x1fb2: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1fb7:
	/* 0x1fb7: jmp    30f6 <generic_sleepable_preload+0x30f6> */
	return 12534ULL;
x86_l_1fbc:
	/* 0x1fbc: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_1fc4:
	/* 0x1fc4: jmp    2bd2 <generic_sleepable_preload+0x2bd2> */
	return 11218ULL;
x86_l_1fc9:
	/* 0x1fc9: mov    DWORD PTR [rsp+0x14],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345922ULL);
x86_l_1fd1:
	/* 0x1fd1: jmp    2c9f <generic_sleepable_preload+0x2c9f> */
	return 11423ULL;
x86_l_1fd6:
	/* 0x1fd6: mov    DWORD PTR [rsp+0x14],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345922ULL);
x86_l_1fde:
	/* 0x1fde: jmp    2d9a <generic_sleepable_preload+0x2d9a> */
	return 11674ULL;
x86_l_1fe3:
	/* 0x1fe3: mov    DWORD PTR [rsp+0x14],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345922ULL);
x86_l_1feb:
	/* 0x1feb: jmp    2e95 <generic_sleepable_preload+0x2e95> */
	return 11925ULL;
x86_l_1ff0:
	/* 0x1ff0: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1ff5:
	/* 0x1ff5: jmp    2f8d <generic_sleepable_preload+0x2f8d> */
	return 12173ULL;
x86_l_1ffa:
	/* 0x1ffa: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_2002:
	/* 0x2002: jmp    301c <generic_sleepable_preload+0x301c> */
	return 12316ULL;
x86_l_2007:
	/* 0x2007: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_200c:
	/* 0x200c: jmp    30f6 <generic_sleepable_preload+0x30f6> */
	return 12534ULL;
x86_l_2011:
	/* 0x2011: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2014:
	/* 0x2014: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2017:
	/* 0x2017: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_2019:
	/* 0x2019: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_201b:
	/* 0x201b: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_2020:
	/* 0x2020: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2022:
	/* 0x2022: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_2027:
	/* 0x2027: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_202c:
	/* 0x202c: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2030:
	/* 0x2030: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2038:
	/* 0x2038: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_203a:
	/* 0x203a: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_203e:
	/* 0x203e: cmp    WORD PTR [rbx+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_2046:
	/* 0x2046: je     31b2 <generic_sleepable_preload+0x31b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12722ULL;
	}
x86_l_204c:
	/* 0x204c: mov    eax,DWORD PTR [rbx+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2052:
	/* 0x2052: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2055:
	/* 0x2055: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_205a:
	/* 0x205a: cmp    WORD PTR [rbx+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_2062:
	/* 0x2062: je     2087 <generic_sleepable_preload+0x2087> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2087;
	}
x86_l_2064:
	/* 0x2064: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2069:
	/* 0x2069: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_206e:
	/* 0x206e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2073:
	/* 0x2073: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2078:
	/* 0x2078: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_207d:
	/* 0x207d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_207f:
	/* 0x207f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2081:
	/* 0x2081: js     233b <generic_sleepable_preload+0x233b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_233b;
	}
x86_l_2087:
	/* 0x2087: cmp    WORD PTR [rbx+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_208f:
	/* 0x208f: je     31b2 <generic_sleepable_preload+0x31b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12722ULL;
	}
x86_l_2095:
	/* 0x2095: mov    ecx,DWORD PTR [rbx+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_209b:
	/* 0x209b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_20a0:
	/* 0x20a0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20a5:
	/* 0x20a5: cmp    WORD PTR [rbx+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_20ad:
	/* 0x20ad: je     20d2 <generic_sleepable_preload+0x20d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20d2;
	}
x86_l_20af:
	/* 0x20af: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20b4:
	/* 0x20b4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20b9:
	/* 0x20b9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20be:
	/* 0x20be: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20c3:
	/* 0x20c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20c8:
	/* 0x20c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ca:
	/* 0x20ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20cc:
	/* 0x20cc: js     2348 <generic_sleepable_preload+0x2348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2348;
	}
x86_l_20d2:
	/* 0x20d2: cmp    WORD PTR [rbx+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_20da:
	/* 0x20da: je     31b2 <generic_sleepable_preload+0x31b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12722ULL;
	}
x86_l_20e0:
	/* 0x20e0: mov    ecx,DWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_20e6:
	/* 0x20e6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_20eb:
	/* 0x20eb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20f0:
	/* 0x20f0: cmp    WORD PTR [rbx+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_20f8:
	/* 0x20f8: je     211d <generic_sleepable_preload+0x211d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_211d;
	}
x86_l_20fa:
	/* 0x20fa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20ff:
	/* 0x20ff: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2104:
	/* 0x2104: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2109:
	/* 0x2109: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_210e:
	/* 0x210e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2113:
	/* 0x2113: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2115:
	/* 0x2115: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2117:
	/* 0x2117: js     2a32 <generic_sleepable_preload+0x2a32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10802ULL;
	}
x86_l_211d:
	/* 0x211d: cmp    WORD PTR [rbx+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_2125:
	/* 0x2125: je     31b2 <generic_sleepable_preload+0x31b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12722ULL;
	}
x86_l_212b:
	/* 0x212b: mov    ecx,DWORD PTR [rbx+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2131:
	/* 0x2131: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2136:
	/* 0x2136: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_213b:
	/* 0x213b: cmp    WORD PTR [rbx+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2143:
	/* 0x2143: je     2168 <generic_sleepable_preload+0x2168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2168;
	}
x86_l_2145:
	/* 0x2145: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_214a:
	/* 0x214a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_214f:
	/* 0x214f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2154:
	/* 0x2154: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2159:
	/* 0x2159: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_215e:
	/* 0x215e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2160:
	/* 0x2160: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2162:
	/* 0x2162: js     2aae <generic_sleepable_preload+0x2aae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10926ULL;
	}
x86_l_2168:
	/* 0x2168: cmp    WORD PTR [rbx+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2170:
	/* 0x2170: je     31b2 <generic_sleepable_preload+0x31b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12722ULL;
	}
x86_l_2176:
	/* 0x2176: mov    ecx,DWORD PTR [rbx+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_217c:
	/* 0x217c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2181:
	/* 0x2181: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2186:
	/* 0x2186: cmp    WORD PTR [rbx+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_218e:
	/* 0x218e: je     21b3 <generic_sleepable_preload+0x21b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21b3;
	}
x86_l_2190:
	/* 0x2190: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2195:
	/* 0x2195: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_219a:
	/* 0x219a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_219f:
	/* 0x219f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21a4:
	/* 0x21a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21a9:
	/* 0x21a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ab:
	/* 0x21ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21ad:
	/* 0x21ad: js     2b2a <generic_sleepable_preload+0x2b2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11050ULL;
	}
x86_l_21b3:
	/* 0x21b3: cmp    WORD PTR [rbx+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_21bb:
	/* 0x21bb: je     31b2 <generic_sleepable_preload+0x31b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12722ULL;
	}
x86_l_21c1:
	/* 0x21c1: mov    ecx,DWORD PTR [rbx+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_21c7:
	/* 0x21c7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_21cc:
	/* 0x21cc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21d1:
	/* 0x21d1: cmp    WORD PTR [rbx+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_21d9:
	/* 0x21d9: je     21fe <generic_sleepable_preload+0x21fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21fe;
	}
x86_l_21db:
	/* 0x21db: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21e0:
	/* 0x21e0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21e5:
	/* 0x21e5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21ea:
	/* 0x21ea: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21ef:
	/* 0x21ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21f4:
	/* 0x21f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f6:
	/* 0x21f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21f8:
	/* 0x21f8: js     2ba3 <generic_sleepable_preload+0x2ba3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11171ULL;
	}
x86_l_21fe:
	/* 0x21fe: cmp    WORD PTR [rbx+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2206:
	/* 0x2206: je     31b2 <generic_sleepable_preload+0x31b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12722ULL;
	}
x86_l_220c:
	/* 0x220c: mov    ecx,DWORD PTR [rbx+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2212:
	/* 0x2212: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2217:
	/* 0x2217: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_221c:
	/* 0x221c: cmp    WORD PTR [rbx+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2224:
	/* 0x2224: je     2249 <generic_sleepable_preload+0x2249> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2249;
	}
x86_l_2226:
	/* 0x2226: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_222b:
	/* 0x222b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2230:
	/* 0x2230: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2235:
	/* 0x2235: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_223a:
	/* 0x223a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_223f:
	/* 0x223f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2241:
	/* 0x2241: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2243:
	/* 0x2243: js     31a2 <generic_sleepable_preload+0x31a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12706ULL;
	}
x86_l_2249:
	/* 0x2249: cmp    WORD PTR [rbx+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2251:
	/* 0x2251: je     31b2 <generic_sleepable_preload+0x31b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12722ULL;
	}
x86_l_2257:
	/* 0x2257: mov    ecx,DWORD PTR [rbx+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_225d:
	/* 0x225d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2262:
	/* 0x2262: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2267:
	/* 0x2267: cmp    WORD PTR [rbx+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_226f:
	/* 0x226f: je     2294 <generic_sleepable_preload+0x2294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2294;
	}
x86_l_2271:
	/* 0x2271: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2276:
	/* 0x2276: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_227b:
	/* 0x227b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2280:
	/* 0x2280: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2285:
	/* 0x2285: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_228a:
	/* 0x228a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_228c:
	/* 0x228c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_228e:
	/* 0x228e: js     345b <generic_sleepable_preload+0x345b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13403ULL;
	}
x86_l_2294:
	/* 0x2294: cmp    WORD PTR [rbx+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_229c:
	/* 0x229c: je     31b2 <generic_sleepable_preload+0x31b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12722ULL;
	}
x86_l_22a2:
	/* 0x22a2: mov    ecx,DWORD PTR [rbx+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_22a8:
	/* 0x22a8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_22ad:
	/* 0x22ad: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22b2:
	/* 0x22b2: cmp    WORD PTR [rbx+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_22ba:
	/* 0x22ba: je     22df <generic_sleepable_preload+0x22df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22df;
	}
x86_l_22bc:
	/* 0x22bc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22c1:
	/* 0x22c1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_22c6:
	/* 0x22c6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22cb:
	/* 0x22cb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22d0:
	/* 0x22d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22d5:
	/* 0x22d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d7:
	/* 0x22d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22d9:
	/* 0x22d9: js     350d <generic_sleepable_preload+0x350d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13581ULL;
	}
x86_l_22df:
	/* 0x22df: cmp    WORD PTR [rbx+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_22e7:
	/* 0x22e7: je     31b2 <generic_sleepable_preload+0x31b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12722ULL;
	}
x86_l_22ed:
	/* 0x22ed: mov    ecx,DWORD PTR [rbx+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_22f3:
	/* 0x22f3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_22f8:
	/* 0x22f8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22fd:
	/* 0x22fd: cmp    WORD PTR [rbx+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2305:
	/* 0x2305: je     31b2 <generic_sleepable_preload+0x31b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12722ULL;
	}
x86_l_230b:
	/* 0x230b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2310:
	/* 0x2310: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2315:
	/* 0x2315: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_231a:
	/* 0x231a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_231f:
	/* 0x231f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2324:
	/* 0x2324: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2326:
	/* 0x2326: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2328:
	/* 0x2328: jns    31b2 <generic_sleepable_preload+0x31b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12722ULL;
	}
x86_l_232e:
	/* 0x232e: mov    DWORD PTR [rsp+0x14],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345930ULL);
x86_l_2336:
	/* 0x2336: jmp    31aa <generic_sleepable_preload+0x31aa> */
	return 12714ULL;
x86_l_233b:
	/* 0x233b: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_2343:
	/* 0x2343: jmp    31aa <generic_sleepable_preload+0x31aa> */
	return 12714ULL;
x86_l_2348:
	/* 0x2348: mov    DWORD PTR [rsp+0x14],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345922ULL);
x86_l_2350:
	/* 0x2350: jmp    31aa <generic_sleepable_preload+0x31aa> */
	return 12714ULL;
x86_l_2355:
	/* 0x2355: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2358:
	/* 0x2358: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_235b:
	/* 0x235b: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_235d:
	/* 0x235d: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_235f:
	/* 0x235f: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_2364:
	/* 0x2364: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2366:
	/* 0x2366: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_236b:
	/* 0x236b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2370:
	/* 0x2370: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2374:
	/* 0x2374: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_237c:
	/* 0x237c: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_237e:
	/* 0x237e: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2382:
	/* 0x2382: cmp    WORD PTR [rbx+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_238a:
	/* 0x238a: je     3268 <generic_sleepable_preload+0x3268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12904ULL;
	}
x86_l_2390:
	/* 0x2390: mov    eax,DWORD PTR [rbx+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2396:
	/* 0x2396: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2399:
	/* 0x2399: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_239e:
	/* 0x239e: cmp    WORD PTR [rbx+0x114],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1185410973696ULL);
x86_l_23a6:
	/* 0x23a6: je     23cb <generic_sleepable_preload+0x23cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23cb;
	}
x86_l_23a8:
	/* 0x23a8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ad:
	/* 0x23ad: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23b2:
	/* 0x23b2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23b7:
	/* 0x23b7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23bc:
	/* 0x23bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23c1:
	/* 0x23c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c3:
	/* 0x23c3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23c5:
	/* 0x23c5: js     267f <generic_sleepable_preload+0x267f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9855ULL;
	}
x86_l_23cb:
	/* 0x23cb: cmp    WORD PTR [rbx+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_23d3:
	/* 0x23d3: je     3268 <generic_sleepable_preload+0x3268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12904ULL;
	}
x86_l_23d9:
	/* 0x23d9: mov    ecx,DWORD PTR [rbx+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_23df:
	/* 0x23df: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_23e4:
	/* 0x23e4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23e9:
	/* 0x23e9: cmp    WORD PTR [rbx+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_23f1:
	/* 0x23f1: je     2416 <generic_sleepable_preload+0x2416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2416;
	}
x86_l_23f3:
	/* 0x23f3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23f8:
	/* 0x23f8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23fd:
	/* 0x23fd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2402:
	/* 0x2402: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2407:
	/* 0x2407: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_240c:
	/* 0x240c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_240e:
	/* 0x240e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2410:
	/* 0x2410: js     268c <generic_sleepable_preload+0x268c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9868ULL;
	}
x86_l_2416:
	/* 0x2416: cmp    WORD PTR [rbx+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_241e:
	/* 0x241e: je     3268 <generic_sleepable_preload+0x3268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12904ULL;
	}
x86_l_2424:
	/* 0x2424: mov    ecx,DWORD PTR [rbx+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_242a:
	/* 0x242a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_242f:
	/* 0x242f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2434:
	/* 0x2434: cmp    WORD PTR [rbx+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_243c:
	/* 0x243c: je     2461 <generic_sleepable_preload+0x2461> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9313ULL;
	}
x86_l_243e:
	/* 0x243e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2443:
	/* 0x2443: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
	return 9288ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9288ULL: goto x86_l_2448;
	case 9293ULL: goto x86_l_244d;
	case 9298ULL: goto x86_l_2452;
	case 9303ULL: goto x86_l_2457;
	case 9305ULL: goto x86_l_2459;
	case 9307ULL: goto x86_l_245b;
	case 9313ULL: goto x86_l_2461;
	case 9321ULL: goto x86_l_2469;
	case 9327ULL: goto x86_l_246f;
	case 9333ULL: goto x86_l_2475;
	case 9338ULL: goto x86_l_247a;
	case 9343ULL: goto x86_l_247f;
	case 9351ULL: goto x86_l_2487;
	case 9353ULL: goto x86_l_2489;
	case 9358ULL: goto x86_l_248e;
	case 9363ULL: goto x86_l_2493;
	case 9368ULL: goto x86_l_2498;
	case 9373ULL: goto x86_l_249d;
	case 9378ULL: goto x86_l_24a2;
	case 9380ULL: goto x86_l_24a4;
	case 9382ULL: goto x86_l_24a6;
	case 9388ULL: goto x86_l_24ac;
	case 9396ULL: goto x86_l_24b4;
	case 9402ULL: goto x86_l_24ba;
	case 9408ULL: goto x86_l_24c0;
	case 9413ULL: goto x86_l_24c5;
	case 9418ULL: goto x86_l_24ca;
	case 9426ULL: goto x86_l_24d2;
	case 9428ULL: goto x86_l_24d4;
	case 9433ULL: goto x86_l_24d9;
	case 9438ULL: goto x86_l_24de;
	case 9443ULL: goto x86_l_24e3;
	case 9448ULL: goto x86_l_24e8;
	case 9453ULL: goto x86_l_24ed;
	case 9455ULL: goto x86_l_24ef;
	case 9457ULL: goto x86_l_24f1;
	case 9463ULL: goto x86_l_24f7;
	case 9471ULL: goto x86_l_24ff;
	case 9477ULL: goto x86_l_2505;
	case 9483ULL: goto x86_l_250b;
	case 9488ULL: goto x86_l_2510;
	case 9493ULL: goto x86_l_2515;
	case 9501ULL: goto x86_l_251d;
	case 9503ULL: goto x86_l_251f;
	case 9508ULL: goto x86_l_2524;
	case 9513ULL: goto x86_l_2529;
	case 9518ULL: goto x86_l_252e;
	case 9523ULL: goto x86_l_2533;
	case 9528ULL: goto x86_l_2538;
	case 9530ULL: goto x86_l_253a;
	case 9532ULL: goto x86_l_253c;
	case 9538ULL: goto x86_l_2542;
	case 9546ULL: goto x86_l_254a;
	case 9552ULL: goto x86_l_2550;
	case 9558ULL: goto x86_l_2556;
	case 9563ULL: goto x86_l_255b;
	case 9568ULL: goto x86_l_2560;
	case 9576ULL: goto x86_l_2568;
	case 9578ULL: goto x86_l_256a;
	case 9583ULL: goto x86_l_256f;
	case 9588ULL: goto x86_l_2574;
	case 9593ULL: goto x86_l_2579;
	case 9598ULL: goto x86_l_257e;
	case 9603ULL: goto x86_l_2583;
	case 9605ULL: goto x86_l_2585;
	case 9607ULL: goto x86_l_2587;
	case 9613ULL: goto x86_l_258d;
	case 9621ULL: goto x86_l_2595;
	case 9627ULL: goto x86_l_259b;
	case 9633ULL: goto x86_l_25a1;
	case 9638ULL: goto x86_l_25a6;
	case 9643ULL: goto x86_l_25ab;
	case 9651ULL: goto x86_l_25b3;
	case 9653ULL: goto x86_l_25b5;
	case 9658ULL: goto x86_l_25ba;
	case 9663ULL: goto x86_l_25bf;
	case 9668ULL: goto x86_l_25c4;
	case 9673ULL: goto x86_l_25c9;
	case 9678ULL: goto x86_l_25ce;
	case 9680ULL: goto x86_l_25d0;
	case 9682ULL: goto x86_l_25d2;
	case 9688ULL: goto x86_l_25d8;
	case 9696ULL: goto x86_l_25e0;
	case 9702ULL: goto x86_l_25e6;
	case 9708ULL: goto x86_l_25ec;
	case 9713ULL: goto x86_l_25f1;
	case 9718ULL: goto x86_l_25f6;
	case 9726ULL: goto x86_l_25fe;
	case 9728ULL: goto x86_l_2600;
	case 9733ULL: goto x86_l_2605;
	case 9738ULL: goto x86_l_260a;
	case 9743ULL: goto x86_l_260f;
	case 9748ULL: goto x86_l_2614;
	case 9753ULL: goto x86_l_2619;
	case 9755ULL: goto x86_l_261b;
	case 9757ULL: goto x86_l_261d;
	case 9763ULL: goto x86_l_2623;
	case 9771ULL: goto x86_l_262b;
	case 9777ULL: goto x86_l_2631;
	case 9783ULL: goto x86_l_2637;
	case 9788ULL: goto x86_l_263c;
	case 9793ULL: goto x86_l_2641;
	case 9801ULL: goto x86_l_2649;
	case 9807ULL: goto x86_l_264f;
	case 9812ULL: goto x86_l_2654;
	case 9817ULL: goto x86_l_2659;
	case 9822ULL: goto x86_l_265e;
	case 9827ULL: goto x86_l_2663;
	case 9832ULL: goto x86_l_2668;
	case 9834ULL: goto x86_l_266a;
	case 9836ULL: goto x86_l_266c;
	case 9842ULL: goto x86_l_2672;
	case 9850ULL: goto x86_l_267a;
	case 9855ULL: goto x86_l_267f;
	case 9863ULL: goto x86_l_2687;
	case 9868ULL: goto x86_l_268c;
	case 9876ULL: goto x86_l_2694;
	case 9881ULL: goto x86_l_2699;
	case 9884ULL: goto x86_l_269c;
	case 9887ULL: goto x86_l_269f;
	case 9889ULL: goto x86_l_26a1;
	case 9891ULL: goto x86_l_26a3;
	case 9896ULL: goto x86_l_26a8;
	case 9898ULL: goto x86_l_26aa;
	case 9903ULL: goto x86_l_26af;
	case 9908ULL: goto x86_l_26b4;
	case 9912ULL: goto x86_l_26b8;
	case 9920ULL: goto x86_l_26c0;
	case 9922ULL: goto x86_l_26c2;
	case 9926ULL: goto x86_l_26c6;
	case 9934ULL: goto x86_l_26ce;
	case 9940ULL: goto x86_l_26d4;
	case 9946ULL: goto x86_l_26da;
	case 9949ULL: goto x86_l_26dd;
	case 9954ULL: goto x86_l_26e2;
	case 9962ULL: goto x86_l_26ea;
	case 9964ULL: goto x86_l_26ec;
	case 9969ULL: goto x86_l_26f1;
	case 9974ULL: goto x86_l_26f6;
	case 9979ULL: goto x86_l_26fb;
	case 9984ULL: goto x86_l_2700;
	case 9989ULL: goto x86_l_2705;
	case 9991ULL: goto x86_l_2707;
	case 9993ULL: goto x86_l_2709;
	case 9999ULL: goto x86_l_270f;
	case 10007ULL: goto x86_l_2717;
	case 10013ULL: goto x86_l_271d;
	case 10019ULL: goto x86_l_2723;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10037ULL: goto x86_l_2735;
	case 10039ULL: goto x86_l_2737;
	case 10044ULL: goto x86_l_273c;
	case 10049ULL: goto x86_l_2741;
	case 10054ULL: goto x86_l_2746;
	case 10059ULL: goto x86_l_274b;
	case 10064ULL: goto x86_l_2750;
	case 10066ULL: goto x86_l_2752;
	case 10068ULL: goto x86_l_2754;
	case 10074ULL: goto x86_l_275a;
	case 10082ULL: goto x86_l_2762;
	case 10088ULL: goto x86_l_2768;
	case 10094ULL: goto x86_l_276e;
	case 10099ULL: goto x86_l_2773;
	case 10104ULL: goto x86_l_2778;
	case 10112ULL: goto x86_l_2780;
	case 10114ULL: goto x86_l_2782;
	case 10119ULL: goto x86_l_2787;
	case 10124ULL: goto x86_l_278c;
	case 10129ULL: goto x86_l_2791;
	case 10134ULL: goto x86_l_2796;
	case 10139ULL: goto x86_l_279b;
	case 10141ULL: goto x86_l_279d;
	case 10143ULL: goto x86_l_279f;
	case 10149ULL: goto x86_l_27a5;
	case 10157ULL: goto x86_l_27ad;
	case 10163ULL: goto x86_l_27b3;
	case 10169ULL: goto x86_l_27b9;
	case 10174ULL: goto x86_l_27be;
	case 10179ULL: goto x86_l_27c3;
	case 10187ULL: goto x86_l_27cb;
	case 10189ULL: goto x86_l_27cd;
	case 10194ULL: goto x86_l_27d2;
	case 10199ULL: goto x86_l_27d7;
	case 10204ULL: goto x86_l_27dc;
	case 10209ULL: goto x86_l_27e1;
	case 10214ULL: goto x86_l_27e6;
	case 10216ULL: goto x86_l_27e8;
	case 10218ULL: goto x86_l_27ea;
	case 10224ULL: goto x86_l_27f0;
	case 10232ULL: goto x86_l_27f8;
	case 10238ULL: goto x86_l_27fe;
	case 10244ULL: goto x86_l_2804;
	case 10249ULL: goto x86_l_2809;
	case 10254ULL: goto x86_l_280e;
	case 10262ULL: goto x86_l_2816;
	case 10264ULL: goto x86_l_2818;
	case 10269ULL: goto x86_l_281d;
	case 10274ULL: goto x86_l_2822;
	case 10279ULL: goto x86_l_2827;
	case 10284ULL: goto x86_l_282c;
	case 10289ULL: goto x86_l_2831;
	case 10291ULL: goto x86_l_2833;
	case 10293ULL: goto x86_l_2835;
	case 10299ULL: goto x86_l_283b;
	case 10307ULL: goto x86_l_2843;
	case 10313ULL: goto x86_l_2849;
	case 10319ULL: goto x86_l_284f;
	case 10324ULL: goto x86_l_2854;
	case 10329ULL: goto x86_l_2859;
	case 10337ULL: goto x86_l_2861;
	case 10339ULL: goto x86_l_2863;
	case 10344ULL: goto x86_l_2868;
	case 10349ULL: goto x86_l_286d;
	case 10354ULL: goto x86_l_2872;
	case 10359ULL: goto x86_l_2877;
	case 10364ULL: goto x86_l_287c;
	case 10366ULL: goto x86_l_287e;
	case 10368ULL: goto x86_l_2880;
	case 10374ULL: goto x86_l_2886;
	case 10382ULL: goto x86_l_288e;
	case 10388ULL: goto x86_l_2894;
	case 10394ULL: goto x86_l_289a;
	case 10399ULL: goto x86_l_289f;
	case 10404ULL: goto x86_l_28a4;
	case 10412ULL: goto x86_l_28ac;
	case 10414ULL: goto x86_l_28ae;
	case 10419ULL: goto x86_l_28b3;
	case 10424ULL: goto x86_l_28b8;
	case 10429ULL: goto x86_l_28bd;
	case 10434ULL: goto x86_l_28c2;
	case 10439ULL: goto x86_l_28c7;
	case 10441ULL: goto x86_l_28c9;
	case 10443ULL: goto x86_l_28cb;
	case 10449ULL: goto x86_l_28d1;
	case 10457ULL: goto x86_l_28d9;
	case 10463ULL: goto x86_l_28df;
	case 10469ULL: goto x86_l_28e5;
	case 10474ULL: goto x86_l_28ea;
	case 10479ULL: goto x86_l_28ef;
	case 10487ULL: goto x86_l_28f7;
	case 10489ULL: goto x86_l_28f9;
	case 10494ULL: goto x86_l_28fe;
	case 10499ULL: goto x86_l_2903;
	case 10504ULL: goto x86_l_2908;
	case 10509ULL: goto x86_l_290d;
	case 10514ULL: goto x86_l_2912;
	case 10516ULL: goto x86_l_2914;
	case 10518ULL: goto x86_l_2916;
	case 10524ULL: goto x86_l_291c;
	case 10532ULL: goto x86_l_2924;
	case 10538ULL: goto x86_l_292a;
	case 10544ULL: goto x86_l_2930;
	case 10549ULL: goto x86_l_2935;
	case 10554ULL: goto x86_l_293a;
	case 10562ULL: goto x86_l_2942;
	case 10564ULL: goto x86_l_2944;
	case 10569ULL: goto x86_l_2949;
	case 10574ULL: goto x86_l_294e;
	case 10579ULL: goto x86_l_2953;
	case 10584ULL: goto x86_l_2958;
	case 10589ULL: goto x86_l_295d;
	case 10591ULL: goto x86_l_295f;
	case 10593ULL: goto x86_l_2961;
	case 10599ULL: goto x86_l_2967;
	case 10607ULL: goto x86_l_296f;
	case 10613ULL: goto x86_l_2975;
	case 10619ULL: goto x86_l_297b;
	case 10624ULL: goto x86_l_2980;
	case 10629ULL: goto x86_l_2985;
	case 10637ULL: goto x86_l_298d;
	case 10643ULL: goto x86_l_2993;
	case 10648ULL: goto x86_l_2998;
	case 10653ULL: goto x86_l_299d;
	case 10658ULL: goto x86_l_29a2;
	case 10663ULL: goto x86_l_29a7;
	case 10668ULL: goto x86_l_29ac;
	case 10670ULL: goto x86_l_29ae;
	case 10672ULL: goto x86_l_29b0;
	case 10678ULL: goto x86_l_29b6;
	case 10686ULL: goto x86_l_29be;
	case 10691ULL: goto x86_l_29c3;
	case 10699ULL: goto x86_l_29cb;
	case 10704ULL: goto x86_l_29d0;
	case 10712ULL: goto x86_l_29d8;
	case 10717ULL: goto x86_l_29dd;
	case 10725ULL: goto x86_l_29e5;
	case 10730ULL: goto x86_l_29ea;
	case 10738ULL: goto x86_l_29f2;
	case 10743ULL: goto x86_l_29f7;
	case 10751ULL: goto x86_l_29ff;
	case 10756ULL: goto x86_l_2a04;
	case 10764ULL: goto x86_l_2a0c;
	case 10769ULL: goto x86_l_2a11;
	case 10774ULL: goto x86_l_2a16;
	case 10779ULL: goto x86_l_2a1b;
	case 10787ULL: goto x86_l_2a23;
	case 10792ULL: goto x86_l_2a28;
	case 10797ULL: goto x86_l_2a2d;
	case 10802ULL: goto x86_l_2a32;
	case 10810ULL: goto x86_l_2a3a;
	case 10815ULL: goto x86_l_2a3f;
	case 10823ULL: goto x86_l_2a47;
	case 10828ULL: goto x86_l_2a4c;
	case 10836ULL: goto x86_l_2a54;
	case 10841ULL: goto x86_l_2a59;
	case 10849ULL: goto x86_l_2a61;
	case 10854ULL: goto x86_l_2a66;
	case 10862ULL: goto x86_l_2a6e;
	case 10867ULL: goto x86_l_2a73;
	case 10875ULL: goto x86_l_2a7b;
	case 10880ULL: goto x86_l_2a80;
	case 10888ULL: goto x86_l_2a88;
	case 10893ULL: goto x86_l_2a8d;
	case 10898ULL: goto x86_l_2a92;
	case 10903ULL: goto x86_l_2a97;
	case 10911ULL: goto x86_l_2a9f;
	case 10916ULL: goto x86_l_2aa4;
	case 10921ULL: goto x86_l_2aa9;
	case 10926ULL: goto x86_l_2aae;
	case 10934ULL: goto x86_l_2ab6;
	case 10939ULL: goto x86_l_2abb;
	case 10947ULL: goto x86_l_2ac3;
	case 10952ULL: goto x86_l_2ac8;
	case 10960ULL: goto x86_l_2ad0;
	case 10965ULL: goto x86_l_2ad5;
	case 10973ULL: goto x86_l_2add;
	case 10978ULL: goto x86_l_2ae2;
	case 10986ULL: goto x86_l_2aea;
	case 10991ULL: goto x86_l_2aef;
	case 10999ULL: goto x86_l_2af7;
	case 11004ULL: goto x86_l_2afc;
	case 11012ULL: goto x86_l_2b04;
	case 11017ULL: goto x86_l_2b09;
	case 11022ULL: goto x86_l_2b0e;
	case 11027ULL: goto x86_l_2b13;
	case 11035ULL: goto x86_l_2b1b;
	case 11040ULL: goto x86_l_2b20;
	case 11045ULL: goto x86_l_2b25;
	case 11050ULL: goto x86_l_2b2a;
	case 11058ULL: goto x86_l_2b32;
	case 11063ULL: goto x86_l_2b37;
	case 11071ULL: goto x86_l_2b3f;
	case 11076ULL: goto x86_l_2b44;
	case 11084ULL: goto x86_l_2b4c;
	case 11089ULL: goto x86_l_2b51;
	case 11097ULL: goto x86_l_2b59;
	case 11099ULL: goto x86_l_2b5b;
	case 11107ULL: goto x86_l_2b63;
	case 11112ULL: goto x86_l_2b68;
	case 11120ULL: goto x86_l_2b70;
	case 11125ULL: goto x86_l_2b75;
	case 11133ULL: goto x86_l_2b7d;
	case 11138ULL: goto x86_l_2b82;
	case 11143ULL: goto x86_l_2b87;
	case 11148ULL: goto x86_l_2b8c;
	case 11156ULL: goto x86_l_2b94;
	case 11161ULL: goto x86_l_2b99;
	case 11166ULL: goto x86_l_2b9e;
	case 11171ULL: goto x86_l_2ba3;
	case 11179ULL: goto x86_l_2bab;
	case 11184ULL: goto x86_l_2bb0;
	case 11192ULL: goto x86_l_2bb8;
	case 11197ULL: goto x86_l_2bbd;
	case 11205ULL: goto x86_l_2bc5;
	case 11210ULL: goto x86_l_2bca;
	case 11218ULL: goto x86_l_2bd2;
	case 11226ULL: goto x86_l_2bda;
	case 11230ULL: goto x86_l_2bde;
	case 11235ULL: goto x86_l_2be3;
	case 11240ULL: goto x86_l_2be8;
	case 11245ULL: goto x86_l_2bed;
	case 11250ULL: goto x86_l_2bf2;
	case 11253ULL: goto x86_l_2bf5;
	case 11255ULL: goto x86_l_2bf7;
	case 11259ULL: goto x86_l_2bfb;
	case 11265ULL: goto x86_l_2c01;
	case 11270ULL: goto x86_l_2c06;
	case 11275ULL: goto x86_l_2c0b;
	case 11280ULL: goto x86_l_2c10;
	case 11282ULL: goto x86_l_2c12;
	case 11287ULL: goto x86_l_2c17;
	case 11295ULL: goto x86_l_2c1f;
	case 11302ULL: goto x86_l_2c26;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2448:
	/* 0x2448: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_244d:
	/* 0x244d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2452:
	/* 0x2452: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2457:
	/* 0x2457: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2459:
	/* 0x2459: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_245b:
	/* 0x245b: js     2a3f <generic_sleepable_preload+0x2a3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a3f;
	}
x86_l_2461:
	/* 0x2461: cmp    WORD PTR [rbx+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2469:
	/* 0x2469: je     3268 <generic_sleepable_preload+0x3268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12904ULL;
	}
x86_l_246f:
	/* 0x246f: mov    ecx,DWORD PTR [rbx+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2475:
	/* 0x2475: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_247a:
	/* 0x247a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_247f:
	/* 0x247f: cmp    WORD PTR [rbx+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2487:
	/* 0x2487: je     24ac <generic_sleepable_preload+0x24ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24ac;
	}
x86_l_2489:
	/* 0x2489: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_248e:
	/* 0x248e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2493:
	/* 0x2493: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2498:
	/* 0x2498: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_249d:
	/* 0x249d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24a2:
	/* 0x24a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a4:
	/* 0x24a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24a6:
	/* 0x24a6: js     2abb <generic_sleepable_preload+0x2abb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2abb;
	}
x86_l_24ac:
	/* 0x24ac: cmp    WORD PTR [rbx+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_24b4:
	/* 0x24b4: je     3268 <generic_sleepable_preload+0x3268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12904ULL;
	}
x86_l_24ba:
	/* 0x24ba: mov    ecx,DWORD PTR [rbx+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_24c0:
	/* 0x24c0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_24c5:
	/* 0x24c5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24ca:
	/* 0x24ca: cmp    WORD PTR [rbx+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_24d2:
	/* 0x24d2: je     24f7 <generic_sleepable_preload+0x24f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f7;
	}
x86_l_24d4:
	/* 0x24d4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24d9:
	/* 0x24d9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24de:
	/* 0x24de: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24e3:
	/* 0x24e3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24e8:
	/* 0x24e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24ed:
	/* 0x24ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ef:
	/* 0x24ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24f1:
	/* 0x24f1: js     2b37 <generic_sleepable_preload+0x2b37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b37;
	}
x86_l_24f7:
	/* 0x24f7: cmp    WORD PTR [rbx+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_24ff:
	/* 0x24ff: je     3268 <generic_sleepable_preload+0x3268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12904ULL;
	}
x86_l_2505:
	/* 0x2505: mov    ecx,DWORD PTR [rbx+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_250b:
	/* 0x250b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2510:
	/* 0x2510: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2515:
	/* 0x2515: cmp    WORD PTR [rbx+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_251d:
	/* 0x251d: je     2542 <generic_sleepable_preload+0x2542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2542;
	}
x86_l_251f:
	/* 0x251f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2524:
	/* 0x2524: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2529:
	/* 0x2529: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_252e:
	/* 0x252e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2533:
	/* 0x2533: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2538:
	/* 0x2538: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253a:
	/* 0x253a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_253c:
	/* 0x253c: js     2bb0 <generic_sleepable_preload+0x2bb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2bb0;
	}
x86_l_2542:
	/* 0x2542: cmp    WORD PTR [rbx+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_254a:
	/* 0x254a: je     3268 <generic_sleepable_preload+0x3268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12904ULL;
	}
x86_l_2550:
	/* 0x2550: mov    ecx,DWORD PTR [rbx+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2556:
	/* 0x2556: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_255b:
	/* 0x255b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2560:
	/* 0x2560: cmp    WORD PTR [rbx+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2568:
	/* 0x2568: je     258d <generic_sleepable_preload+0x258d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_258d;
	}
x86_l_256a:
	/* 0x256a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_256f:
	/* 0x256f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2574:
	/* 0x2574: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2579:
	/* 0x2579: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_257e:
	/* 0x257e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2583:
	/* 0x2583: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2585:
	/* 0x2585: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2587:
	/* 0x2587: js     3258 <generic_sleepable_preload+0x3258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12888ULL;
	}
x86_l_258d:
	/* 0x258d: cmp    WORD PTR [rbx+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2595:
	/* 0x2595: je     3268 <generic_sleepable_preload+0x3268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12904ULL;
	}
x86_l_259b:
	/* 0x259b: mov    ecx,DWORD PTR [rbx+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_25a1:
	/* 0x25a1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_25a6:
	/* 0x25a6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25ab:
	/* 0x25ab: cmp    WORD PTR [rbx+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_25b3:
	/* 0x25b3: je     25d8 <generic_sleepable_preload+0x25d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25d8;
	}
x86_l_25b5:
	/* 0x25b5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25ba:
	/* 0x25ba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_25bf:
	/* 0x25bf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25c4:
	/* 0x25c4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25c9:
	/* 0x25c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25ce:
	/* 0x25ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d0:
	/* 0x25d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25d2:
	/* 0x25d2: js     347a <generic_sleepable_preload+0x347a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13434ULL;
	}
x86_l_25d8:
	/* 0x25d8: cmp    WORD PTR [rbx+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_25e0:
	/* 0x25e0: je     3268 <generic_sleepable_preload+0x3268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12904ULL;
	}
x86_l_25e6:
	/* 0x25e6: mov    ecx,DWORD PTR [rbx+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_25ec:
	/* 0x25ec: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_25f1:
	/* 0x25f1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25f6:
	/* 0x25f6: cmp    WORD PTR [rbx+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_25fe:
	/* 0x25fe: je     2623 <generic_sleepable_preload+0x2623> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2623;
	}
x86_l_2600:
	/* 0x2600: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2605:
	/* 0x2605: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_260a:
	/* 0x260a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_260f:
	/* 0x260f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2614:
	/* 0x2614: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2619:
	/* 0x2619: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_261b:
	/* 0x261b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_261d:
	/* 0x261d: js     351a <generic_sleepable_preload+0x351a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13594ULL;
	}
x86_l_2623:
	/* 0x2623: cmp    WORD PTR [rbx+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_262b:
	/* 0x262b: je     3268 <generic_sleepable_preload+0x3268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12904ULL;
	}
x86_l_2631:
	/* 0x2631: mov    ecx,DWORD PTR [rbx+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2637:
	/* 0x2637: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_263c:
	/* 0x263c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2641:
	/* 0x2641: cmp    WORD PTR [rbx+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_2649:
	/* 0x2649: je     3268 <generic_sleepable_preload+0x3268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12904ULL;
	}
x86_l_264f:
	/* 0x264f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2654:
	/* 0x2654: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2659:
	/* 0x2659: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_265e:
	/* 0x265e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2663:
	/* 0x2663: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2668:
	/* 0x2668: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_266a:
	/* 0x266a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_266c:
	/* 0x266c: jns    3268 <generic_sleepable_preload+0x3268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12904ULL;
	}
x86_l_2672:
	/* 0x2672: mov    DWORD PTR [rsp+0x14],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345930ULL);
x86_l_267a:
	/* 0x267a: jmp    3260 <generic_sleepable_preload+0x3260> */
	return 12896ULL;
x86_l_267f:
	/* 0x267f: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_2687:
	/* 0x2687: jmp    3260 <generic_sleepable_preload+0x3260> */
	return 12896ULL;
x86_l_268c:
	/* 0x268c: mov    DWORD PTR [rsp+0x14],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345922ULL);
x86_l_2694:
	/* 0x2694: jmp    3260 <generic_sleepable_preload+0x3260> */
	return 12896ULL;
x86_l_2699:
	/* 0x2699: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_269c:
	/* 0x269c: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_269f:
	/* 0x269f: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_26a1:
	/* 0x26a1: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_26a3:
	/* 0x26a3: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_26a8:
	/* 0x26a8: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_26aa:
	/* 0x26aa: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_26af:
	/* 0x26af: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26b4:
	/* 0x26b4: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26b8:
	/* 0x26b8: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_26c0:
	/* 0x26c0: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_26c2:
	/* 0x26c2: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26c6:
	/* 0x26c6: cmp    WORD PTR [rbx+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_26ce:
	/* 0x26ce: je     331e <generic_sleepable_preload+0x331e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13086ULL;
	}
x86_l_26d4:
	/* 0x26d4: mov    eax,DWORD PTR [rbx+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_26da:
	/* 0x26da: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26dd:
	/* 0x26dd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26e2:
	/* 0x26e2: cmp    WORD PTR [rbx+0x164],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1529008357376ULL);
x86_l_26ea:
	/* 0x26ea: je     270f <generic_sleepable_preload+0x270f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_270f;
	}
x86_l_26ec:
	/* 0x26ec: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26f1:
	/* 0x26f1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26f6:
	/* 0x26f6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26fb:
	/* 0x26fb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2700:
	/* 0x2700: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2705:
	/* 0x2705: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2707:
	/* 0x2707: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2709:
	/* 0x2709: js     29c3 <generic_sleepable_preload+0x29c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29c3;
	}
x86_l_270f:
	/* 0x270f: cmp    WORD PTR [rbx+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_2717:
	/* 0x2717: je     331e <generic_sleepable_preload+0x331e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13086ULL;
	}
x86_l_271d:
	/* 0x271d: mov    ecx,DWORD PTR [rbx+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_2723:
	/* 0x2723: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2728:
	/* 0x2728: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_272d:
	/* 0x272d: cmp    WORD PTR [rbx+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_2735:
	/* 0x2735: je     275a <generic_sleepable_preload+0x275a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_275a;
	}
x86_l_2737:
	/* 0x2737: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_273c:
	/* 0x273c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2741:
	/* 0x2741: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2746:
	/* 0x2746: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_274b:
	/* 0x274b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2750:
	/* 0x2750: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2752:
	/* 0x2752: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2754:
	/* 0x2754: js     29d0 <generic_sleepable_preload+0x29d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29d0;
	}
x86_l_275a:
	/* 0x275a: cmp    WORD PTR [rbx+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_2762:
	/* 0x2762: je     331e <generic_sleepable_preload+0x331e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13086ULL;
	}
x86_l_2768:
	/* 0x2768: mov    ecx,DWORD PTR [rbx+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_276e:
	/* 0x276e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2773:
	/* 0x2773: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2778:
	/* 0x2778: cmp    WORD PTR [rbx+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_2780:
	/* 0x2780: je     27a5 <generic_sleepable_preload+0x27a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27a5;
	}
x86_l_2782:
	/* 0x2782: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2787:
	/* 0x2787: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_278c:
	/* 0x278c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2791:
	/* 0x2791: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2796:
	/* 0x2796: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_279b:
	/* 0x279b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_279d:
	/* 0x279d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_279f:
	/* 0x279f: js     2a4c <generic_sleepable_preload+0x2a4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a4c;
	}
x86_l_27a5:
	/* 0x27a5: cmp    WORD PTR [rbx+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_27ad:
	/* 0x27ad: je     331e <generic_sleepable_preload+0x331e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13086ULL;
	}
x86_l_27b3:
	/* 0x27b3: mov    ecx,DWORD PTR [rbx+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_27b9:
	/* 0x27b9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_27be:
	/* 0x27be: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27c3:
	/* 0x27c3: cmp    WORD PTR [rbx+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_27cb:
	/* 0x27cb: je     27f0 <generic_sleepable_preload+0x27f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27f0;
	}
x86_l_27cd:
	/* 0x27cd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27d2:
	/* 0x27d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27d7:
	/* 0x27d7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27dc:
	/* 0x27dc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27e1:
	/* 0x27e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27e6:
	/* 0x27e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e8:
	/* 0x27e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27ea:
	/* 0x27ea: js     2ac8 <generic_sleepable_preload+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ac8;
	}
x86_l_27f0:
	/* 0x27f0: cmp    WORD PTR [rbx+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_27f8:
	/* 0x27f8: je     331e <generic_sleepable_preload+0x331e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13086ULL;
	}
x86_l_27fe:
	/* 0x27fe: mov    ecx,DWORD PTR [rbx+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_2804:
	/* 0x2804: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2809:
	/* 0x2809: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_280e:
	/* 0x280e: cmp    WORD PTR [rbx+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_2816:
	/* 0x2816: je     283b <generic_sleepable_preload+0x283b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_283b;
	}
x86_l_2818:
	/* 0x2818: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_281d:
	/* 0x281d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2822:
	/* 0x2822: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2827:
	/* 0x2827: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_282c:
	/* 0x282c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2831:
	/* 0x2831: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2833:
	/* 0x2833: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2835:
	/* 0x2835: js     2b44 <generic_sleepable_preload+0x2b44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b44;
	}
x86_l_283b:
	/* 0x283b: cmp    WORD PTR [rbx+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_2843:
	/* 0x2843: je     331e <generic_sleepable_preload+0x331e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13086ULL;
	}
x86_l_2849:
	/* 0x2849: mov    ecx,DWORD PTR [rbx+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_284f:
	/* 0x284f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2854:
	/* 0x2854: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2859:
	/* 0x2859: cmp    WORD PTR [rbx+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_2861:
	/* 0x2861: je     2886 <generic_sleepable_preload+0x2886> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2886;
	}
x86_l_2863:
	/* 0x2863: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2868:
	/* 0x2868: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_286d:
	/* 0x286d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2872:
	/* 0x2872: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2877:
	/* 0x2877: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_287c:
	/* 0x287c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287e:
	/* 0x287e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2880:
	/* 0x2880: js     2bbd <generic_sleepable_preload+0x2bbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2bbd;
	}
x86_l_2886:
	/* 0x2886: cmp    WORD PTR [rbx+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_288e:
	/* 0x288e: je     331e <generic_sleepable_preload+0x331e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13086ULL;
	}
x86_l_2894:
	/* 0x2894: mov    ecx,DWORD PTR [rbx+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_289a:
	/* 0x289a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_289f:
	/* 0x289f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28a4:
	/* 0x28a4: cmp    WORD PTR [rbx+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_28ac:
	/* 0x28ac: je     28d1 <generic_sleepable_preload+0x28d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28d1;
	}
x86_l_28ae:
	/* 0x28ae: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28b3:
	/* 0x28b3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28b8:
	/* 0x28b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28bd:
	/* 0x28bd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28c2:
	/* 0x28c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28c7:
	/* 0x28c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c9:
	/* 0x28c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28cb:
	/* 0x28cb: js     330e <generic_sleepable_preload+0x330e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13070ULL;
	}
x86_l_28d1:
	/* 0x28d1: cmp    WORD PTR [rbx+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_28d9:
	/* 0x28d9: je     331e <generic_sleepable_preload+0x331e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13086ULL;
	}
x86_l_28df:
	/* 0x28df: mov    ecx,DWORD PTR [rbx+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_28e5:
	/* 0x28e5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_28ea:
	/* 0x28ea: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28ef:
	/* 0x28ef: cmp    WORD PTR [rbx+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_28f7:
	/* 0x28f7: je     291c <generic_sleepable_preload+0x291c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_291c;
	}
x86_l_28f9:
	/* 0x28f9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28fe:
	/* 0x28fe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2903:
	/* 0x2903: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2908:
	/* 0x2908: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_290d:
	/* 0x290d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2912:
	/* 0x2912: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2914:
	/* 0x2914: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2916:
	/* 0x2916: js     3499 <generic_sleepable_preload+0x3499> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13465ULL;
	}
x86_l_291c:
	/* 0x291c: cmp    WORD PTR [rbx+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_2924:
	/* 0x2924: je     331e <generic_sleepable_preload+0x331e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13086ULL;
	}
x86_l_292a:
	/* 0x292a: mov    ecx,DWORD PTR [rbx+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_2930:
	/* 0x2930: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2935:
	/* 0x2935: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_293a:
	/* 0x293a: cmp    WORD PTR [rbx+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_2942:
	/* 0x2942: je     2967 <generic_sleepable_preload+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2967;
	}
x86_l_2944:
	/* 0x2944: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2949:
	/* 0x2949: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_294e:
	/* 0x294e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2953:
	/* 0x2953: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2958:
	/* 0x2958: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_295d:
	/* 0x295d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_295f:
	/* 0x295f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2961:
	/* 0x2961: js     3527 <generic_sleepable_preload+0x3527> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13607ULL;
	}
x86_l_2967:
	/* 0x2967: cmp    WORD PTR [rbx+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_296f:
	/* 0x296f: je     331e <generic_sleepable_preload+0x331e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13086ULL;
	}
x86_l_2975:
	/* 0x2975: mov    ecx,DWORD PTR [rbx+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_297b:
	/* 0x297b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2980:
	/* 0x2980: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2985:
	/* 0x2985: cmp    WORD PTR [rbx+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_298d:
	/* 0x298d: je     331e <generic_sleepable_preload+0x331e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13086ULL;
	}
x86_l_2993:
	/* 0x2993: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2998:
	/* 0x2998: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_299d:
	/* 0x299d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29a2:
	/* 0x29a2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29a7:
	/* 0x29a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29ac:
	/* 0x29ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ae:
	/* 0x29ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29b0:
	/* 0x29b0: jns    331e <generic_sleepable_preload+0x331e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13086ULL;
	}
x86_l_29b6:
	/* 0x29b6: mov    DWORD PTR [rsp+0x14],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345930ULL);
x86_l_29be:
	/* 0x29be: jmp    3316 <generic_sleepable_preload+0x3316> */
	return 13078ULL;
x86_l_29c3:
	/* 0x29c3: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_29cb:
	/* 0x29cb: jmp    3316 <generic_sleepable_preload+0x3316> */
	return 13078ULL;
x86_l_29d0:
	/* 0x29d0: mov    DWORD PTR [rsp+0x14],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345922ULL);
x86_l_29d8:
	/* 0x29d8: jmp    3316 <generic_sleepable_preload+0x3316> */
	return 13078ULL;
x86_l_29dd:
	/* 0x29dd: mov    DWORD PTR [rsp+0x18],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215107ULL);
x86_l_29e5:
	/* 0x29e5: jmp    2bd2 <generic_sleepable_preload+0x2bd2> */
	goto x86_l_2bd2;
x86_l_29ea:
	/* 0x29ea: mov    DWORD PTR [rsp+0x14],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345923ULL);
x86_l_29f2:
	/* 0x29f2: jmp    2c9f <generic_sleepable_preload+0x2c9f> */
	return 11423ULL;
x86_l_29f7:
	/* 0x29f7: mov    DWORD PTR [rsp+0x14],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345923ULL);
x86_l_29ff:
	/* 0x29ff: jmp    2d9a <generic_sleepable_preload+0x2d9a> */
	return 11674ULL;
x86_l_2a04:
	/* 0x2a04: mov    DWORD PTR [rsp+0x14],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345923ULL);
x86_l_2a0c:
	/* 0x2a0c: jmp    2e95 <generic_sleepable_preload+0x2e95> */
	return 11925ULL;
x86_l_2a11:
	/* 0x2a11: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2a16:
	/* 0x2a16: jmp    2f8d <generic_sleepable_preload+0x2f8d> */
	return 12173ULL;
x86_l_2a1b:
	/* 0x2a1b: mov    DWORD PTR [rsp+0x18],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215107ULL);
x86_l_2a23:
	/* 0x2a23: jmp    301c <generic_sleepable_preload+0x301c> */
	return 12316ULL;
x86_l_2a28:
	/* 0x2a28: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2a2d:
	/* 0x2a2d: jmp    30f6 <generic_sleepable_preload+0x30f6> */
	return 12534ULL;
x86_l_2a32:
	/* 0x2a32: mov    DWORD PTR [rsp+0x14],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345923ULL);
x86_l_2a3a:
	/* 0x2a3a: jmp    31aa <generic_sleepable_preload+0x31aa> */
	return 12714ULL;
x86_l_2a3f:
	/* 0x2a3f: mov    DWORD PTR [rsp+0x14],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345923ULL);
x86_l_2a47:
	/* 0x2a47: jmp    3260 <generic_sleepable_preload+0x3260> */
	return 12896ULL;
x86_l_2a4c:
	/* 0x2a4c: mov    DWORD PTR [rsp+0x14],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345923ULL);
x86_l_2a54:
	/* 0x2a54: jmp    3316 <generic_sleepable_preload+0x3316> */
	return 13078ULL;
x86_l_2a59:
	/* 0x2a59: mov    DWORD PTR [rsp+0x18],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215108ULL);
x86_l_2a61:
	/* 0x2a61: jmp    2bd2 <generic_sleepable_preload+0x2bd2> */
	goto x86_l_2bd2;
x86_l_2a66:
	/* 0x2a66: mov    DWORD PTR [rsp+0x14],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345924ULL);
x86_l_2a6e:
	/* 0x2a6e: jmp    2c9f <generic_sleepable_preload+0x2c9f> */
	return 11423ULL;
x86_l_2a73:
	/* 0x2a73: mov    DWORD PTR [rsp+0x14],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345924ULL);
x86_l_2a7b:
	/* 0x2a7b: jmp    2d9a <generic_sleepable_preload+0x2d9a> */
	return 11674ULL;
x86_l_2a80:
	/* 0x2a80: mov    DWORD PTR [rsp+0x14],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345924ULL);
x86_l_2a88:
	/* 0x2a88: jmp    2e95 <generic_sleepable_preload+0x2e95> */
	return 11925ULL;
x86_l_2a8d:
	/* 0x2a8d: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2a92:
	/* 0x2a92: jmp    2f8d <generic_sleepable_preload+0x2f8d> */
	return 12173ULL;
x86_l_2a97:
	/* 0x2a97: mov    DWORD PTR [rsp+0x18],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215108ULL);
x86_l_2a9f:
	/* 0x2a9f: jmp    301c <generic_sleepable_preload+0x301c> */
	return 12316ULL;
x86_l_2aa4:
	/* 0x2aa4: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2aa9:
	/* 0x2aa9: jmp    30f6 <generic_sleepable_preload+0x30f6> */
	return 12534ULL;
x86_l_2aae:
	/* 0x2aae: mov    DWORD PTR [rsp+0x14],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345924ULL);
x86_l_2ab6:
	/* 0x2ab6: jmp    31aa <generic_sleepable_preload+0x31aa> */
	return 12714ULL;
x86_l_2abb:
	/* 0x2abb: mov    DWORD PTR [rsp+0x14],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345924ULL);
x86_l_2ac3:
	/* 0x2ac3: jmp    3260 <generic_sleepable_preload+0x3260> */
	return 12896ULL;
x86_l_2ac8:
	/* 0x2ac8: mov    DWORD PTR [rsp+0x14],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345924ULL);
x86_l_2ad0:
	/* 0x2ad0: jmp    3316 <generic_sleepable_preload+0x3316> */
	return 13078ULL;
x86_l_2ad5:
	/* 0x2ad5: mov    DWORD PTR [rsp+0x18],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215109ULL);
x86_l_2add:
	/* 0x2add: jmp    2bd2 <generic_sleepable_preload+0x2bd2> */
	goto x86_l_2bd2;
x86_l_2ae2:
	/* 0x2ae2: mov    DWORD PTR [rsp+0x14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345925ULL);
x86_l_2aea:
	/* 0x2aea: jmp    2c9f <generic_sleepable_preload+0x2c9f> */
	return 11423ULL;
x86_l_2aef:
	/* 0x2aef: mov    DWORD PTR [rsp+0x14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345925ULL);
x86_l_2af7:
	/* 0x2af7: jmp    2d9a <generic_sleepable_preload+0x2d9a> */
	return 11674ULL;
x86_l_2afc:
	/* 0x2afc: mov    DWORD PTR [rsp+0x14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345925ULL);
x86_l_2b04:
	/* 0x2b04: jmp    2e95 <generic_sleepable_preload+0x2e95> */
	return 11925ULL;
x86_l_2b09:
	/* 0x2b09: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2b0e:
	/* 0x2b0e: jmp    2f8d <generic_sleepable_preload+0x2f8d> */
	return 12173ULL;
x86_l_2b13:
	/* 0x2b13: mov    DWORD PTR [rsp+0x18],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215109ULL);
x86_l_2b1b:
	/* 0x2b1b: jmp    301c <generic_sleepable_preload+0x301c> */
	return 12316ULL;
x86_l_2b20:
	/* 0x2b20: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2b25:
	/* 0x2b25: jmp    30f6 <generic_sleepable_preload+0x30f6> */
	return 12534ULL;
x86_l_2b2a:
	/* 0x2b2a: mov    DWORD PTR [rsp+0x14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345925ULL);
x86_l_2b32:
	/* 0x2b32: jmp    31aa <generic_sleepable_preload+0x31aa> */
	return 12714ULL;
x86_l_2b37:
	/* 0x2b37: mov    DWORD PTR [rsp+0x14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345925ULL);
x86_l_2b3f:
	/* 0x2b3f: jmp    3260 <generic_sleepable_preload+0x3260> */
	return 12896ULL;
x86_l_2b44:
	/* 0x2b44: mov    DWORD PTR [rsp+0x14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345925ULL);
x86_l_2b4c:
	/* 0x2b4c: jmp    3316 <generic_sleepable_preload+0x3316> */
	return 13078ULL;
x86_l_2b51:
	/* 0x2b51: mov    DWORD PTR [rsp+0x18],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215110ULL);
x86_l_2b59:
	/* 0x2b59: jmp    2bd2 <generic_sleepable_preload+0x2bd2> */
	goto x86_l_2bd2;
x86_l_2b5b:
	/* 0x2b5b: mov    DWORD PTR [rsp+0x14],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_2b63:
	/* 0x2b63: jmp    2c9f <generic_sleepable_preload+0x2c9f> */
	return 11423ULL;
x86_l_2b68:
	/* 0x2b68: mov    DWORD PTR [rsp+0x14],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_2b70:
	/* 0x2b70: jmp    2d9a <generic_sleepable_preload+0x2d9a> */
	return 11674ULL;
x86_l_2b75:
	/* 0x2b75: mov    DWORD PTR [rsp+0x14],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_2b7d:
	/* 0x2b7d: jmp    2e95 <generic_sleepable_preload+0x2e95> */
	return 11925ULL;
x86_l_2b82:
	/* 0x2b82: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2b87:
	/* 0x2b87: jmp    2f8d <generic_sleepable_preload+0x2f8d> */
	return 12173ULL;
x86_l_2b8c:
	/* 0x2b8c: mov    DWORD PTR [rsp+0x18],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215110ULL);
x86_l_2b94:
	/* 0x2b94: jmp    301c <generic_sleepable_preload+0x301c> */
	return 12316ULL;
x86_l_2b99:
	/* 0x2b99: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2b9e:
	/* 0x2b9e: jmp    30f6 <generic_sleepable_preload+0x30f6> */
	return 12534ULL;
x86_l_2ba3:
	/* 0x2ba3: mov    DWORD PTR [rsp+0x14],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_2bab:
	/* 0x2bab: jmp    31aa <generic_sleepable_preload+0x31aa> */
	return 12714ULL;
x86_l_2bb0:
	/* 0x2bb0: mov    DWORD PTR [rsp+0x14],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_2bb8:
	/* 0x2bb8: jmp    3260 <generic_sleepable_preload+0x3260> */
	return 12896ULL;
x86_l_2bbd:
	/* 0x2bbd: mov    DWORD PTR [rsp+0x14],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_2bc5:
	/* 0x2bc5: jmp    3316 <generic_sleepable_preload+0x3316> */
	return 13078ULL;
x86_l_2bca:
	/* 0x2bca: mov    DWORD PTR [rsp+0x18],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215111ULL);
x86_l_2bd2:
	/* 0x2bd2: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2bda:
	/* 0x2bda: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2bde:
	/* 0x2bde: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2be3:
	/* 0x2be3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2be8:
	/* 0x2be8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bed:
	/* 0x2bed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bf2:
	/* 0x2bf2: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2bf5:
	/* 0x2bf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf7:
	/* 0x2bf7: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2bfb:
	/* 0x2bfb: jne    de <generic_sleepable_preload+0xde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 222ULL;
	}
x86_l_2c01:
	/* 0x2c01: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c06:
	/* 0x2c06: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c0b:
	/* 0x2c0b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2c10:
	/* 0x2c10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c12:
	/* 0x2c12: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c17:
	/* 0x2c17: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2c1f:
	/* 0x2c1f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2c26:
	/* 0x2c26: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
	return 11307ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11307ULL: goto x86_l_2c2b;
	case 11312ULL: goto x86_l_2c30;
	case 11314ULL: goto x86_l_2c32;
	case 11317ULL: goto x86_l_2c35;
	case 11323ULL: goto x86_l_2c3b;
	case 11326ULL: goto x86_l_2c3e;
	case 11331ULL: goto x86_l_2c43;
	case 11334ULL: goto x86_l_2c46;
	case 11341ULL: goto x86_l_2c4d;
	case 11343ULL: goto x86_l_2c4f;
	case 11346ULL: goto x86_l_2c52;
	case 11351ULL: goto x86_l_2c57;
	case 11356ULL: goto x86_l_2c5c;
	case 11359ULL: goto x86_l_2c5f;
	case 11362ULL: goto x86_l_2c62;
	case 11364ULL: goto x86_l_2c64;
	case 11366ULL: goto x86_l_2c66;
	case 11371ULL: goto x86_l_2c6b;
	case 11374ULL: goto x86_l_2c6e;
	case 11377ULL: goto x86_l_2c71;
	case 11382ULL: goto x86_l_2c76;
	case 11385ULL: goto x86_l_2c79;
	case 11388ULL: goto x86_l_2c7c;
	case 11390ULL: goto x86_l_2c7e;
	case 11393ULL: goto x86_l_2c81;
	case 11399ULL: goto x86_l_2c87;
	case 11404ULL: goto x86_l_2c8c;
	case 11410ULL: goto x86_l_2c92;
	case 11415ULL: goto x86_l_2c97;
	case 11423ULL: goto x86_l_2c9f;
	case 11431ULL: goto x86_l_2ca7;
	case 11435ULL: goto x86_l_2cab;
	case 11440ULL: goto x86_l_2cb0;
	case 11445ULL: goto x86_l_2cb5;
	case 11450ULL: goto x86_l_2cba;
	case 11455ULL: goto x86_l_2cbf;
	case 11458ULL: goto x86_l_2cc2;
	case 11460ULL: goto x86_l_2cc4;
	case 11464ULL: goto x86_l_2cc8;
	case 11470ULL: goto x86_l_2cce;
	case 11475ULL: goto x86_l_2cd3;
	case 11480ULL: goto x86_l_2cd8;
	case 11485ULL: goto x86_l_2cdd;
	case 11487ULL: goto x86_l_2cdf;
	case 11492ULL: goto x86_l_2ce4;
	case 11500ULL: goto x86_l_2cec;
	case 11507ULL: goto x86_l_2cf3;
	case 11512ULL: goto x86_l_2cf8;
	case 11517ULL: goto x86_l_2cfd;
	case 11519ULL: goto x86_l_2cff;
	case 11522ULL: goto x86_l_2d02;
	case 11528ULL: goto x86_l_2d08;
	case 11531ULL: goto x86_l_2d0b;
	case 11536ULL: goto x86_l_2d10;
	case 11539ULL: goto x86_l_2d13;
	case 11546ULL: goto x86_l_2d1a;
	case 11548ULL: goto x86_l_2d1c;
	case 11551ULL: goto x86_l_2d1f;
	case 11556ULL: goto x86_l_2d24;
	case 11561ULL: goto x86_l_2d29;
	case 11564ULL: goto x86_l_2d2c;
	case 11567ULL: goto x86_l_2d2f;
	case 11569ULL: goto x86_l_2d31;
	case 11571ULL: goto x86_l_2d33;
	case 11576ULL: goto x86_l_2d38;
	case 11579ULL: goto x86_l_2d3b;
	case 11582ULL: goto x86_l_2d3e;
	case 11587ULL: goto x86_l_2d43;
	case 11590ULL: goto x86_l_2d46;
	case 11593ULL: goto x86_l_2d49;
	case 11595ULL: goto x86_l_2d4b;
	case 11598ULL: goto x86_l_2d4e;
	case 11604ULL: goto x86_l_2d54;
	case 11609ULL: goto x86_l_2d59;
	case 11615ULL: goto x86_l_2d5f;
	case 11618ULL: goto x86_l_2d62;
	case 11622ULL: goto x86_l_2d66;
	case 11627ULL: goto x86_l_2d6b;
	case 11632ULL: goto x86_l_2d70;
	case 11634ULL: goto x86_l_2d72;
	case 11637ULL: goto x86_l_2d75;
	case 11642ULL: goto x86_l_2d7a;
	case 11644ULL: goto x86_l_2d7c;
	case 11647ULL: goto x86_l_2d7f;
	case 11649ULL: goto x86_l_2d81;
	case 11654ULL: goto x86_l_2d86;
	case 11658ULL: goto x86_l_2d8a;
	case 11661ULL: goto x86_l_2d8d;
	case 11666ULL: goto x86_l_2d92;
	case 11674ULL: goto x86_l_2d9a;
	case 11682ULL: goto x86_l_2da2;
	case 11686ULL: goto x86_l_2da6;
	case 11691ULL: goto x86_l_2dab;
	case 11696ULL: goto x86_l_2db0;
	case 11701ULL: goto x86_l_2db5;
	case 11706ULL: goto x86_l_2dba;
	case 11709ULL: goto x86_l_2dbd;
	case 11711ULL: goto x86_l_2dbf;
	case 11715ULL: goto x86_l_2dc3;
	case 11721ULL: goto x86_l_2dc9;
	case 11726ULL: goto x86_l_2dce;
	case 11731ULL: goto x86_l_2dd3;
	case 11736ULL: goto x86_l_2dd8;
	case 11738ULL: goto x86_l_2dda;
	case 11743ULL: goto x86_l_2ddf;
	case 11751ULL: goto x86_l_2de7;
	case 11758ULL: goto x86_l_2dee;
	case 11763ULL: goto x86_l_2df3;
	case 11768ULL: goto x86_l_2df8;
	case 11770ULL: goto x86_l_2dfa;
	case 11773ULL: goto x86_l_2dfd;
	case 11779ULL: goto x86_l_2e03;
	case 11782ULL: goto x86_l_2e06;
	case 11787ULL: goto x86_l_2e0b;
	case 11790ULL: goto x86_l_2e0e;
	case 11797ULL: goto x86_l_2e15;
	case 11799ULL: goto x86_l_2e17;
	case 11802ULL: goto x86_l_2e1a;
	case 11807ULL: goto x86_l_2e1f;
	case 11812ULL: goto x86_l_2e24;
	case 11815ULL: goto x86_l_2e27;
	case 11818ULL: goto x86_l_2e2a;
	case 11820ULL: goto x86_l_2e2c;
	case 11822ULL: goto x86_l_2e2e;
	case 11827ULL: goto x86_l_2e33;
	case 11830ULL: goto x86_l_2e36;
	case 11833ULL: goto x86_l_2e39;
	case 11838ULL: goto x86_l_2e3e;
	case 11841ULL: goto x86_l_2e41;
	case 11844ULL: goto x86_l_2e44;
	case 11846ULL: goto x86_l_2e46;
	case 11849ULL: goto x86_l_2e49;
	case 11855ULL: goto x86_l_2e4f;
	case 11860ULL: goto x86_l_2e54;
	case 11866ULL: goto x86_l_2e5a;
	case 11869ULL: goto x86_l_2e5d;
	case 11873ULL: goto x86_l_2e61;
	case 11878ULL: goto x86_l_2e66;
	case 11883ULL: goto x86_l_2e6b;
	case 11885ULL: goto x86_l_2e6d;
	case 11888ULL: goto x86_l_2e70;
	case 11893ULL: goto x86_l_2e75;
	case 11895ULL: goto x86_l_2e77;
	case 11898ULL: goto x86_l_2e7a;
	case 11900ULL: goto x86_l_2e7c;
	case 11905ULL: goto x86_l_2e81;
	case 11909ULL: goto x86_l_2e85;
	case 11912ULL: goto x86_l_2e88;
	case 11917ULL: goto x86_l_2e8d;
	case 11925ULL: goto x86_l_2e95;
	case 11933ULL: goto x86_l_2e9d;
	case 11937ULL: goto x86_l_2ea1;
	case 11942ULL: goto x86_l_2ea6;
	case 11947ULL: goto x86_l_2eab;
	case 11952ULL: goto x86_l_2eb0;
	case 11957ULL: goto x86_l_2eb5;
	case 11960ULL: goto x86_l_2eb8;
	case 11962ULL: goto x86_l_2eba;
	case 11966ULL: goto x86_l_2ebe;
	case 11972ULL: goto x86_l_2ec4;
	case 11977ULL: goto x86_l_2ec9;
	case 11982ULL: goto x86_l_2ece;
	case 11987ULL: goto x86_l_2ed3;
	case 11989ULL: goto x86_l_2ed5;
	case 11994ULL: goto x86_l_2eda;
	case 12002ULL: goto x86_l_2ee2;
	case 12009ULL: goto x86_l_2ee9;
	case 12014ULL: goto x86_l_2eee;
	case 12019ULL: goto x86_l_2ef3;
	case 12021ULL: goto x86_l_2ef5;
	case 12024ULL: goto x86_l_2ef8;
	case 12030ULL: goto x86_l_2efe;
	case 12033ULL: goto x86_l_2f01;
	case 12038ULL: goto x86_l_2f06;
	case 12041ULL: goto x86_l_2f09;
	case 12048ULL: goto x86_l_2f10;
	case 12050ULL: goto x86_l_2f12;
	case 12053ULL: goto x86_l_2f15;
	case 12058ULL: goto x86_l_2f1a;
	case 12063ULL: goto x86_l_2f1f;
	case 12066ULL: goto x86_l_2f22;
	case 12069ULL: goto x86_l_2f25;
	case 12071ULL: goto x86_l_2f27;
	case 12073ULL: goto x86_l_2f29;
	case 12078ULL: goto x86_l_2f2e;
	case 12081ULL: goto x86_l_2f31;
	case 12084ULL: goto x86_l_2f34;
	case 12089ULL: goto x86_l_2f39;
	case 12092ULL: goto x86_l_2f3c;
	case 12095ULL: goto x86_l_2f3f;
	case 12097ULL: goto x86_l_2f41;
	case 12100ULL: goto x86_l_2f44;
	case 12106ULL: goto x86_l_2f4a;
	case 12111ULL: goto x86_l_2f4f;
	case 12117ULL: goto x86_l_2f55;
	case 12120ULL: goto x86_l_2f58;
	case 12124ULL: goto x86_l_2f5c;
	case 12129ULL: goto x86_l_2f61;
	case 12134ULL: goto x86_l_2f66;
	case 12136ULL: goto x86_l_2f68;
	case 12139ULL: goto x86_l_2f6b;
	case 12144ULL: goto x86_l_2f70;
	case 12146ULL: goto x86_l_2f72;
	case 12149ULL: goto x86_l_2f75;
	case 12151ULL: goto x86_l_2f77;
	case 12156ULL: goto x86_l_2f7c;
	case 12160ULL: goto x86_l_2f80;
	case 12163ULL: goto x86_l_2f83;
	case 12168ULL: goto x86_l_2f88;
	case 12173ULL: goto x86_l_2f8d;
	case 12176ULL: goto x86_l_2f90;
	case 12179ULL: goto x86_l_2f93;
	case 12184ULL: goto x86_l_2f98;
	case 12189ULL: goto x86_l_2f9d;
	case 12194ULL: goto x86_l_2fa2;
	case 12199ULL: goto x86_l_2fa7;
	case 12202ULL: goto x86_l_2faa;
	case 12204ULL: goto x86_l_2fac;
	case 12207ULL: goto x86_l_2faf;
	case 12213ULL: goto x86_l_2fb5;
	case 12218ULL: goto x86_l_2fba;
	case 12223ULL: goto x86_l_2fbf;
	case 12225ULL: goto x86_l_2fc1;
	case 12230ULL: goto x86_l_2fc6;
	case 12238ULL: goto x86_l_2fce;
	case 12245ULL: goto x86_l_2fd5;
	case 12250ULL: goto x86_l_2fda;
	case 12255ULL: goto x86_l_2fdf;
	case 12257ULL: goto x86_l_2fe1;
	case 12260ULL: goto x86_l_2fe4;
	case 12266ULL: goto x86_l_2fea;
	case 12269ULL: goto x86_l_2fed;
	case 12276ULL: goto x86_l_2ff4;
	case 12278ULL: goto x86_l_2ff6;
	case 12283ULL: goto x86_l_2ffb;
	case 12288ULL: goto x86_l_3000;
	case 12291ULL: goto x86_l_3003;
	case 12294ULL: goto x86_l_3006;
	case 12296ULL: goto x86_l_3008;
	case 12298ULL: goto x86_l_300a;
	case 12303ULL: goto x86_l_300f;
	case 12308ULL: goto x86_l_3014;
	case 12316ULL: goto x86_l_301c;
	case 12324ULL: goto x86_l_3024;
	case 12328ULL: goto x86_l_3028;
	case 12334ULL: goto x86_l_302e;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12349ULL: goto x86_l_303d;
	case 12351ULL: goto x86_l_303f;
	case 12356ULL: goto x86_l_3044;
	case 12364ULL: goto x86_l_304c;
	case 12371ULL: goto x86_l_3053;
	case 12376ULL: goto x86_l_3058;
	case 12381ULL: goto x86_l_305d;
	case 12383ULL: goto x86_l_305f;
	case 12386ULL: goto x86_l_3062;
	case 12392ULL: goto x86_l_3068;
	case 12395ULL: goto x86_l_306b;
	case 12400ULL: goto x86_l_3070;
	case 12403ULL: goto x86_l_3073;
	case 12410ULL: goto x86_l_307a;
	case 12412ULL: goto x86_l_307c;
	case 12415ULL: goto x86_l_307f;
	case 12420ULL: goto x86_l_3084;
	case 12425ULL: goto x86_l_3089;
	case 12428ULL: goto x86_l_308c;
	case 12431ULL: goto x86_l_308f;
	case 12433ULL: goto x86_l_3091;
	case 12435ULL: goto x86_l_3093;
	case 12440ULL: goto x86_l_3098;
	case 12443ULL: goto x86_l_309b;
	case 12446ULL: goto x86_l_309e;
	case 12451ULL: goto x86_l_30a3;
	case 12454ULL: goto x86_l_30a6;
	case 12457ULL: goto x86_l_30a9;
	case 12459ULL: goto x86_l_30ab;
	case 12462ULL: goto x86_l_30ae;
	case 12468ULL: goto x86_l_30b4;
	case 12473ULL: goto x86_l_30b9;
	case 12475ULL: goto x86_l_30bb;
	case 12478ULL: goto x86_l_30be;
	case 12482ULL: goto x86_l_30c2;
	case 12487ULL: goto x86_l_30c7;
	case 12492ULL: goto x86_l_30cc;
	case 12494ULL: goto x86_l_30ce;
	case 12497ULL: goto x86_l_30d1;
	case 12502ULL: goto x86_l_30d6;
	case 12504ULL: goto x86_l_30d8;
	case 12507ULL: goto x86_l_30db;
	case 12509ULL: goto x86_l_30dd;
	case 12511ULL: goto x86_l_30df;
	case 12515ULL: goto x86_l_30e3;
	case 12517ULL: goto x86_l_30e5;
	case 12522ULL: goto x86_l_30ea;
	case 12527ULL: goto x86_l_30ef;
	case 12529ULL: goto x86_l_30f1;
	case 12534ULL: goto x86_l_30f6;
	case 12537ULL: goto x86_l_30f9;
	case 12541ULL: goto x86_l_30fd;
	case 12547ULL: goto x86_l_3103;
	case 12552ULL: goto x86_l_3108;
	case 12557ULL: goto x86_l_310d;
	case 12559ULL: goto x86_l_310f;
	case 12564ULL: goto x86_l_3114;
	case 12572ULL: goto x86_l_311c;
	case 12579ULL: goto x86_l_3123;
	case 12584ULL: goto x86_l_3128;
	case 12589ULL: goto x86_l_312d;
	case 12591ULL: goto x86_l_312f;
	case 12594ULL: goto x86_l_3132;
	case 12600ULL: goto x86_l_3138;
	case 12603ULL: goto x86_l_313b;
	case 12610ULL: goto x86_l_3142;
	case 12612ULL: goto x86_l_3144;
	case 12617ULL: goto x86_l_3149;
	case 12622ULL: goto x86_l_314e;
	case 12625ULL: goto x86_l_3151;
	case 12628ULL: goto x86_l_3154;
	case 12630ULL: goto x86_l_3156;
	case 12632ULL: goto x86_l_3158;
	case 12637ULL: goto x86_l_315d;
	case 12640ULL: goto x86_l_3160;
	case 12643ULL: goto x86_l_3163;
	case 12645ULL: goto x86_l_3165;
	case 12648ULL: goto x86_l_3168;
	case 12654ULL: goto x86_l_316e;
	case 12657ULL: goto x86_l_3171;
	case 12659ULL: goto x86_l_3173;
	case 12662ULL: goto x86_l_3176;
	case 12666ULL: goto x86_l_317a;
	case 12671ULL: goto x86_l_317f;
	case 12674ULL: goto x86_l_3182;
	case 12676ULL: goto x86_l_3184;
	case 12679ULL: goto x86_l_3187;
	case 12684ULL: goto x86_l_318c;
	case 12686ULL: goto x86_l_318e;
	case 12689ULL: goto x86_l_3191;
	case 12691ULL: goto x86_l_3193;
	case 12696ULL: goto x86_l_3198;
	case 12699ULL: goto x86_l_319b;
	case 12701ULL: goto x86_l_319d;
	case 12706ULL: goto x86_l_31a2;
	case 12714ULL: goto x86_l_31aa;
	case 12722ULL: goto x86_l_31b2;
	case 12726ULL: goto x86_l_31b6;
	case 12732ULL: goto x86_l_31bc;
	case 12737ULL: goto x86_l_31c1;
	case 12742ULL: goto x86_l_31c6;
	case 12747ULL: goto x86_l_31cb;
	case 12749ULL: goto x86_l_31cd;
	case 12754ULL: goto x86_l_31d2;
	case 12762ULL: goto x86_l_31da;
	case 12769ULL: goto x86_l_31e1;
	case 12774ULL: goto x86_l_31e6;
	case 12779ULL: goto x86_l_31eb;
	case 12781ULL: goto x86_l_31ed;
	case 12784ULL: goto x86_l_31f0;
	case 12790ULL: goto x86_l_31f6;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12801ULL: goto x86_l_3201;
	case 12808ULL: goto x86_l_3208;
	case 12810ULL: goto x86_l_320a;
	case 12813ULL: goto x86_l_320d;
	case 12818ULL: goto x86_l_3212;
	case 12823ULL: goto x86_l_3217;
	case 12826ULL: goto x86_l_321a;
	case 12829ULL: goto x86_l_321d;
	case 12831ULL: goto x86_l_321f;
	case 12833ULL: goto x86_l_3221;
	case 12838ULL: goto x86_l_3226;
	case 12841ULL: goto x86_l_3229;
	case 12844ULL: goto x86_l_322c;
	case 12849ULL: goto x86_l_3231;
	case 12852ULL: goto x86_l_3234;
	case 12855ULL: goto x86_l_3237;
	case 12857ULL: goto x86_l_3239;
	case 12860ULL: goto x86_l_323c;
	case 12866ULL: goto x86_l_3242;
	case 12871ULL: goto x86_l_3247;
	case 12877ULL: goto x86_l_324d;
	case 12881ULL: goto x86_l_3251;
	case 12883ULL: goto x86_l_3253;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2c2b:
	/* 0x2c2b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c30:
	/* 0x2c30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c32:
	/* 0x2c32: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c35:
	/* 0x2c35: je     de <generic_sleepable_preload+0xde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 222ULL;
	}
x86_l_2c3b:
	/* 0x2c3b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2c3e:
	/* 0x2c3e: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c43:
	/* 0x2c43: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_2c46:
	/* 0x2c46: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2c4d:
	/* 0x2c4d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c4f:
	/* 0x2c4f: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_2c52:
	/* 0x2c52: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c57:
	/* 0x2c57: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2c5f:
	/* 0x2c5f: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2c62:
	/* 0x2c62: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c64:
	/* 0x2c64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c66:
	/* 0x2c66: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c6b:
	/* 0x2c6b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2c6e:
	/* 0x2c6e: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_2c71:
	/* 0x2c71: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c76:
	/* 0x2c76: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2c79:
	/* 0x2c79: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2c7c:
	/* 0x2c7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c7e:
	/* 0x2c7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c81:
	/* 0x2c81: je     de <generic_sleepable_preload+0xde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 222ULL;
	}
x86_l_2c87:
	/* 0x2c87: cmp    BYTE PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2c8c:
	/* 0x2c8c: jne    30bb <generic_sleepable_preload+0x30bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30bb;
	}
x86_l_2c92:
	/* 0x2c92: jmp    30df <generic_sleepable_preload+0x30df> */
	goto x86_l_30df;
x86_l_2c97:
	/* 0x2c97: mov    DWORD PTR [rsp+0x14],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345927ULL);
x86_l_2c9f:
	/* 0x2c9f: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2ca7:
	/* 0x2ca7: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cab:
	/* 0x2cab: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cb0:
	/* 0x2cb0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2cb5:
	/* 0x2cb5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cba:
	/* 0x2cba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cbf:
	/* 0x2cbf: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2cc2:
	/* 0x2cc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc4:
	/* 0x2cc4: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2cc8:
	/* 0x2cc8: jne    e8 <generic_sleepable_preload+0xe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 232ULL;
	}
x86_l_2cce:
	/* 0x2cce: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cd3:
	/* 0x2cd3: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cd8:
	/* 0x2cd8: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2cdd:
	/* 0x2cdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cdf:
	/* 0x2cdf: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ce4:
	/* 0x2ce4: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2cec:
	/* 0x2cec: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2cf3:
	/* 0x2cf3: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2cf8:
	/* 0x2cf8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cfd:
	/* 0x2cfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cff:
	/* 0x2cff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d02:
	/* 0x2d02: je     e8 <generic_sleepable_preload+0xe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 232ULL;
	}
x86_l_2d08:
	/* 0x2d08: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2d0b:
	/* 0x2d0b: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d10:
	/* 0x2d10: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_2d13:
	/* 0x2d13: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2d1a:
	/* 0x2d1a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d1c:
	/* 0x2d1c: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_2d1f:
	/* 0x2d1f: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d24:
	/* 0x2d24: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d29:
	/* 0x2d29: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2d2c:
	/* 0x2d2c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2d2f:
	/* 0x2d2f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d31:
	/* 0x2d31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d33:
	/* 0x2d33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d38:
	/* 0x2d38: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2d3b:
	/* 0x2d3b: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_2d3e:
	/* 0x2d3e: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d43:
	/* 0x2d43: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2d46:
	/* 0x2d46: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2d49:
	/* 0x2d49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4b:
	/* 0x2d4b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d4e:
	/* 0x2d4e: je     e8 <generic_sleepable_preload+0xe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 232ULL;
	}
x86_l_2d54:
	/* 0x2d54: cmp    BYTE PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2d59:
	/* 0x2d59: je     324d <generic_sleepable_preload+0x324d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_324d;
	}
x86_l_2d5f:
	/* 0x2d5f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d62:
	/* 0x2d62: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d66:
	/* 0x2d66: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d6b:
	/* 0x2d6b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d70:
	/* 0x2d70: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d72:
	/* 0x2d72: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2d75:
	/* 0x2d75: call   2d7a <generic_sleepable_preload+0x2d7a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2d7a:
	/* 0x2d7a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2d7c:
	/* 0x2d7c: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_2d7f:
	/* 0x2d7f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2d81:
	/* 0x2d81: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2d86:
	/* 0x2d86: mov    edx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2d8a:
	/* 0x2d8a: cmovs  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_2d8d:
	/* 0x2d8d: jmp    3251 <generic_sleepable_preload+0x3251> */
	goto x86_l_3251;
x86_l_2d92:
	/* 0x2d92: mov    DWORD PTR [rsp+0x14],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345927ULL);
x86_l_2d9a:
	/* 0x2d9a: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2da2:
	/* 0x2da2: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2da6:
	/* 0x2da6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dab:
	/* 0x2dab: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2db0:
	/* 0x2db0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2db5:
	/* 0x2db5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dba:
	/* 0x2dba: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2dbd:
	/* 0x2dbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dbf:
	/* 0x2dbf: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2dc3:
	/* 0x2dc3: jne    f6 <generic_sleepable_preload+0xf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 246ULL;
	}
x86_l_2dc9:
	/* 0x2dc9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dce:
	/* 0x2dce: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2dd3:
	/* 0x2dd3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2dd8:
	/* 0x2dd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dda:
	/* 0x2dda: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ddf:
	/* 0x2ddf: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2de7:
	/* 0x2de7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2dee:
	/* 0x2dee: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2df3:
	/* 0x2df3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2df8:
	/* 0x2df8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dfa:
	/* 0x2dfa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2dfd:
	/* 0x2dfd: je     f6 <generic_sleepable_preload+0xf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 246ULL;
	}
x86_l_2e03:
	/* 0x2e03: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2e06:
	/* 0x2e06: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e0b:
	/* 0x2e0b: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_2e0e:
	/* 0x2e0e: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2e15:
	/* 0x2e15: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e17:
	/* 0x2e17: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_2e1a:
	/* 0x2e1a: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e1f:
	/* 0x2e1f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e24:
	/* 0x2e24: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2e27:
	/* 0x2e27: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2e2a:
	/* 0x2e2a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e2c:
	/* 0x2e2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2e:
	/* 0x2e2e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e33:
	/* 0x2e33: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2e36:
	/* 0x2e36: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_2e39:
	/* 0x2e39: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e3e:
	/* 0x2e3e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2e41:
	/* 0x2e41: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2e44:
	/* 0x2e44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e46:
	/* 0x2e46: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e49:
	/* 0x2e49: je     f6 <generic_sleepable_preload+0xf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 246ULL;
	}
x86_l_2e4f:
	/* 0x2e4f: cmp    BYTE PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2e54:
	/* 0x2e54: je     3303 <generic_sleepable_preload+0x3303> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13059ULL;
	}
x86_l_2e5a:
	/* 0x2e5a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2e5d:
	/* 0x2e5d: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2e61:
	/* 0x2e61: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2e66:
	/* 0x2e66: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e6b:
	/* 0x2e6b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e6d:
	/* 0x2e6d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2e70:
	/* 0x2e70: call   2e75 <generic_sleepable_preload+0x2e75> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2e75:
	/* 0x2e75: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2e77:
	/* 0x2e77: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_2e7a:
	/* 0x2e7a: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2e7c:
	/* 0x2e7c: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2e81:
	/* 0x2e81: mov    edx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2e85:
	/* 0x2e85: cmovs  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_2e88:
	/* 0x2e88: jmp    3307 <generic_sleepable_preload+0x3307> */
	return 13063ULL;
x86_l_2e8d:
	/* 0x2e8d: mov    DWORD PTR [rsp+0x14],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345927ULL);
x86_l_2e95:
	/* 0x2e95: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2e9d:
	/* 0x2e9d: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ea1:
	/* 0x2ea1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ea6:
	/* 0x2ea6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2eab:
	/* 0x2eab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2eb0:
	/* 0x2eb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eb5:
	/* 0x2eb5: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2eb8:
	/* 0x2eb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eba:
	/* 0x2eba: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_2ebe:
	/* 0x2ebe: jne    104 <generic_sleepable_preload+0x104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 260ULL;
	}
x86_l_2ec4:
	/* 0x2ec4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ec9:
	/* 0x2ec9: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ece:
	/* 0x2ece: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2ed3:
	/* 0x2ed3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ed5:
	/* 0x2ed5: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2eda:
	/* 0x2eda: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2ee2:
	/* 0x2ee2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2ee9:
	/* 0x2ee9: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2eee:
	/* 0x2eee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ef3:
	/* 0x2ef3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef5:
	/* 0x2ef5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ef8:
	/* 0x2ef8: je     104 <generic_sleepable_preload+0x104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 260ULL;
	}
x86_l_2efe:
	/* 0x2efe: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2f01:
	/* 0x2f01: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f06:
	/* 0x2f06: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_2f09:
	/* 0x2f09: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2f10:
	/* 0x2f10: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f12:
	/* 0x2f12: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_2f15:
	/* 0x2f15: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f1a:
	/* 0x2f1a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f1f:
	/* 0x2f1f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2f22:
	/* 0x2f22: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2f25:
	/* 0x2f25: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f27:
	/* 0x2f27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f29:
	/* 0x2f29: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f2e:
	/* 0x2f2e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2f31:
	/* 0x2f31: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_2f34:
	/* 0x2f34: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f39:
	/* 0x2f39: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2f3c:
	/* 0x2f3c: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2f3f:
	/* 0x2f3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f41:
	/* 0x2f41: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f44:
	/* 0x2f44: je     104 <generic_sleepable_preload+0x104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 260ULL;
	}
x86_l_2f4a:
	/* 0x2f4a: cmp    BYTE PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2f4f:
	/* 0x2f4f: je     33b9 <generic_sleepable_preload+0x33b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13241ULL;
	}
x86_l_2f55:
	/* 0x2f55: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2f58:
	/* 0x2f58: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2f5c:
	/* 0x2f5c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f61:
	/* 0x2f61: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f66:
	/* 0x2f66: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f68:
	/* 0x2f68: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2f6b:
	/* 0x2f6b: call   2f70 <generic_sleepable_preload+0x2f70> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2f70:
	/* 0x2f70: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2f72:
	/* 0x2f72: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_2f75:
	/* 0x2f75: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2f77:
	/* 0x2f77: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2f7c:
	/* 0x2f7c: mov    edx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2f80:
	/* 0x2f80: cmovs  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_2f83:
	/* 0x2f83: jmp    33bd <generic_sleepable_preload+0x33bd> */
	return 13245ULL;
x86_l_2f88:
	/* 0x2f88: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_2f8d:
	/* 0x2f8d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f90:
	/* 0x2f90: mov    ebx,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2f93:
	/* 0x2f93: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f98:
	/* 0x2f98: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f9d:
	/* 0x2f9d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fa2:
	/* 0x2fa2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fa7:
	/* 0x2fa7: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2faa:
	/* 0x2faa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fac:
	/* 0x2fac: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2faf:
	/* 0x2faf: jne    112 <generic_sleepable_preload+0x112> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 274ULL;
	}
x86_l_2fb5:
	/* 0x2fb5: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fba:
	/* 0x2fba: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2fbf:
	/* 0x2fbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fc1:
	/* 0x2fc1: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fc6:
	/* 0x2fc6: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2fce:
	/* 0x2fce: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2fd5:
	/* 0x2fd5: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2fda:
	/* 0x2fda: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fdf:
	/* 0x2fdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe1:
	/* 0x2fe1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2fe4:
	/* 0x2fe4: je     112 <generic_sleepable_preload+0x112> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 274ULL;
	}
x86_l_2fea:
	/* 0x2fea: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2fed:
	/* 0x2fed: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2ff4:
	/* 0x2ff4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ff6:
	/* 0x2ff6: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ffb:
	/* 0x2ffb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3000:
	/* 0x3000: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3003:
	/* 0x3003: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3006:
	/* 0x3006: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3008:
	/* 0x3008: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_300a:
	/* 0x300a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_300f:
	/* 0x300f: jmp    315d <generic_sleepable_preload+0x315d> */
	goto x86_l_315d;
x86_l_3014:
	/* 0x3014: mov    DWORD PTR [rsp+0x18],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215111ULL);
x86_l_301c:
	/* 0x301c: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_3024:
	/* 0x3024: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3028:
	/* 0x3028: jne    de <generic_sleepable_preload+0xde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 222ULL;
	}
x86_l_302e:
	/* 0x302e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3033:
	/* 0x3033: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3038:
	/* 0x3038: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_303d:
	/* 0x303d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_303f:
	/* 0x303f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3044:
	/* 0x3044: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_304c:
	/* 0x304c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3053:
	/* 0x3053: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3058:
	/* 0x3058: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_305d:
	/* 0x305d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_305f:
	/* 0x305f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3062:
	/* 0x3062: je     de <generic_sleepable_preload+0xde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 222ULL;
	}
x86_l_3068:
	/* 0x3068: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_306b:
	/* 0x306b: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3070:
	/* 0x3070: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_3073:
	/* 0x3073: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_307a:
	/* 0x307a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_307c:
	/* 0x307c: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_307f:
	/* 0x307f: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3084:
	/* 0x3084: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3089:
	/* 0x3089: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_308c:
	/* 0x308c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_308f:
	/* 0x308f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3091:
	/* 0x3091: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3093:
	/* 0x3093: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3098:
	/* 0x3098: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_309b:
	/* 0x309b: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_309e:
	/* 0x309e: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30a3:
	/* 0x30a3: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_30a6:
	/* 0x30a6: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_30a9:
	/* 0x30a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ab:
	/* 0x30ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30ae:
	/* 0x30ae: je     de <generic_sleepable_preload+0xde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 222ULL;
	}
x86_l_30b4:
	/* 0x30b4: cmp    BYTE PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_30b9:
	/* 0x30b9: je     30df <generic_sleepable_preload+0x30df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30df;
	}
x86_l_30bb:
	/* 0x30bb: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_30be:
	/* 0x30be: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_30c2:
	/* 0x30c2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_30c7:
	/* 0x30c7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30cc:
	/* 0x30cc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30ce:
	/* 0x30ce: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_30d1:
	/* 0x30d1: call   30d6 <generic_sleepable_preload+0x30d6> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_30d6:
	/* 0x30d6: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_30d8:
	/* 0x30d8: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_30db:
	/* 0x30db: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_30dd:
	/* 0x30dd: js     30ea <generic_sleepable_preload+0x30ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_30ea;
	}
x86_l_30df:
	/* 0x30df: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30e3:
	/* 0x30e3: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30e5:
	/* 0x30e5: jmp    de <generic_sleepable_preload+0xde> */
	return 222ULL;
x86_l_30ea:
	/* 0x30ea: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_30ef:
	/* 0x30ef: jmp    30e3 <generic_sleepable_preload+0x30e3> */
	goto x86_l_30e3;
x86_l_30f1:
	/* 0x30f1: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_30f6:
	/* 0x30f6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30f9:
	/* 0x30f9: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_30fd:
	/* 0x30fd: jne    112 <generic_sleepable_preload+0x112> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 274ULL;
	}
x86_l_3103:
	/* 0x3103: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3108:
	/* 0x3108: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_310d:
	/* 0x310d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310f:
	/* 0x310f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3114:
	/* 0x3114: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_311c:
	/* 0x311c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3123:
	/* 0x3123: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3128:
	/* 0x3128: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_312d:
	/* 0x312d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_312f:
	/* 0x312f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3132:
	/* 0x3132: je     112 <generic_sleepable_preload+0x112> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 274ULL;
	}
x86_l_3138:
	/* 0x3138: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_313b:
	/* 0x313b: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3142:
	/* 0x3142: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3144:
	/* 0x3144: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3149:
	/* 0x3149: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_314e:
	/* 0x314e: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3151:
	/* 0x3151: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3154:
	/* 0x3154: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3156:
	/* 0x3156: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3158:
	/* 0x3158: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_315d:
	/* 0x315d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3160:
	/* 0x3160: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3163:
	/* 0x3163: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3165:
	/* 0x3165: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3168:
	/* 0x3168: je     112 <generic_sleepable_preload+0x112> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 274ULL;
	}
x86_l_316e:
	/* 0x316e: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_3171:
	/* 0x3171: je     319b <generic_sleepable_preload+0x319b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_319b;
	}
x86_l_3173:
	/* 0x3173: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3176:
	/* 0x3176: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_317a:
	/* 0x317a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_317f:
	/* 0x317f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3182:
	/* 0x3182: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3184:
	/* 0x3184: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3187:
	/* 0x3187: call   318c <generic_sleepable_preload+0x318c> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_318c:
	/* 0x318c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_318e:
	/* 0x318e: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3191:
	/* 0x3191: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3193:
	/* 0x3193: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3198:
	/* 0x3198: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_319b:
	/* 0x319b: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_319d:
	/* 0x319d: jmp    112 <generic_sleepable_preload+0x112> */
	return 274ULL;
x86_l_31a2:
	/* 0x31a2: mov    DWORD PTR [rsp+0x14],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345927ULL);
x86_l_31aa:
	/* 0x31aa: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_31b2:
	/* 0x31b2: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_31b6:
	/* 0x31b6: jne    e8 <generic_sleepable_preload+0xe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 232ULL;
	}
x86_l_31bc:
	/* 0x31bc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31c1:
	/* 0x31c1: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31c6:
	/* 0x31c6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_31cb:
	/* 0x31cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31cd:
	/* 0x31cd: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31d2:
	/* 0x31d2: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_31da:
	/* 0x31da: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_31e1:
	/* 0x31e1: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_31e6:
	/* 0x31e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31eb:
	/* 0x31eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ed:
	/* 0x31ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31f0:
	/* 0x31f0: je     e8 <generic_sleepable_preload+0xe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 232ULL;
	}
x86_l_31f6:
	/* 0x31f6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_31f9:
	/* 0x31f9: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31fe:
	/* 0x31fe: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_3201:
	/* 0x3201: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3208:
	/* 0x3208: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_320a:
	/* 0x320a: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_320d:
	/* 0x320d: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3212:
	/* 0x3212: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3217:
	/* 0x3217: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_321a:
	/* 0x321a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_321d:
	/* 0x321d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_321f:
	/* 0x321f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3221:
	/* 0x3221: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3226:
	/* 0x3226: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3229:
	/* 0x3229: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_322c:
	/* 0x322c: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3231:
	/* 0x3231: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3234:
	/* 0x3234: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_3237:
	/* 0x3237: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3239:
	/* 0x3239: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_323c:
	/* 0x323c: je     e8 <generic_sleepable_preload+0xe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 232ULL;
	}
x86_l_3242:
	/* 0x3242: cmp    BYTE PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3247:
	/* 0x3247: jne    2d5f <generic_sleepable_preload+0x2d5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d5f;
	}
x86_l_324d:
	/* 0x324d: mov    edx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3251:
	/* 0x3251: mov    DWORD PTR [rax],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3253:
	/* 0x3253: jmp    e8 <generic_sleepable_preload+0xe8> */
	return 232ULL;
	return 12888ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12888ULL: goto x86_l_3258;
	case 12896ULL: goto x86_l_3260;
	case 12904ULL: goto x86_l_3268;
	case 12908ULL: goto x86_l_326c;
	case 12914ULL: goto x86_l_3272;
	case 12919ULL: goto x86_l_3277;
	case 12924ULL: goto x86_l_327c;
	case 12929ULL: goto x86_l_3281;
	case 12931ULL: goto x86_l_3283;
	case 12936ULL: goto x86_l_3288;
	case 12944ULL: goto x86_l_3290;
	case 12951ULL: goto x86_l_3297;
	case 12956ULL: goto x86_l_329c;
	case 12961ULL: goto x86_l_32a1;
	case 12963ULL: goto x86_l_32a3;
	case 12966ULL: goto x86_l_32a6;
	case 12972ULL: goto x86_l_32ac;
	case 12975ULL: goto x86_l_32af;
	case 12980ULL: goto x86_l_32b4;
	case 12983ULL: goto x86_l_32b7;
	case 12990ULL: goto x86_l_32be;
	case 12992ULL: goto x86_l_32c0;
	case 12995ULL: goto x86_l_32c3;
	case 13000ULL: goto x86_l_32c8;
	case 13005ULL: goto x86_l_32cd;
	case 13008ULL: goto x86_l_32d0;
	case 13011ULL: goto x86_l_32d3;
	case 13013ULL: goto x86_l_32d5;
	case 13015ULL: goto x86_l_32d7;
	case 13020ULL: goto x86_l_32dc;
	case 13023ULL: goto x86_l_32df;
	case 13026ULL: goto x86_l_32e2;
	case 13031ULL: goto x86_l_32e7;
	case 13034ULL: goto x86_l_32ea;
	case 13037ULL: goto x86_l_32ed;
	case 13039ULL: goto x86_l_32ef;
	case 13042ULL: goto x86_l_32f2;
	case 13048ULL: goto x86_l_32f8;
	case 13053ULL: goto x86_l_32fd;
	case 13059ULL: goto x86_l_3303;
	case 13063ULL: goto x86_l_3307;
	case 13065ULL: goto x86_l_3309;
	case 13070ULL: goto x86_l_330e;
	case 13078ULL: goto x86_l_3316;
	case 13086ULL: goto x86_l_331e;
	case 13090ULL: goto x86_l_3322;
	case 13096ULL: goto x86_l_3328;
	case 13101ULL: goto x86_l_332d;
	case 13106ULL: goto x86_l_3332;
	case 13111ULL: goto x86_l_3337;
	case 13113ULL: goto x86_l_3339;
	case 13118ULL: goto x86_l_333e;
	case 13126ULL: goto x86_l_3346;
	case 13133ULL: goto x86_l_334d;
	case 13138ULL: goto x86_l_3352;
	case 13143ULL: goto x86_l_3357;
	case 13145ULL: goto x86_l_3359;
	case 13148ULL: goto x86_l_335c;
	case 13154ULL: goto x86_l_3362;
	case 13157ULL: goto x86_l_3365;
	case 13162ULL: goto x86_l_336a;
	case 13165ULL: goto x86_l_336d;
	case 13172ULL: goto x86_l_3374;
	case 13174ULL: goto x86_l_3376;
	case 13177ULL: goto x86_l_3379;
	case 13182ULL: goto x86_l_337e;
	case 13187ULL: goto x86_l_3383;
	case 13190ULL: goto x86_l_3386;
	case 13193ULL: goto x86_l_3389;
	case 13195ULL: goto x86_l_338b;
	case 13197ULL: goto x86_l_338d;
	case 13202ULL: goto x86_l_3392;
	case 13205ULL: goto x86_l_3395;
	case 13208ULL: goto x86_l_3398;
	case 13213ULL: goto x86_l_339d;
	case 13216ULL: goto x86_l_33a0;
	case 13219ULL: goto x86_l_33a3;
	case 13221ULL: goto x86_l_33a5;
	case 13224ULL: goto x86_l_33a8;
	case 13230ULL: goto x86_l_33ae;
	case 13235ULL: goto x86_l_33b3;
	case 13241ULL: goto x86_l_33b9;
	case 13245ULL: goto x86_l_33bd;
	case 13247ULL: goto x86_l_33bf;
	case 13252ULL: goto x86_l_33c4;
	case 13260ULL: goto x86_l_33cc;
	case 13268ULL: goto x86_l_33d4;
	case 13273ULL: goto x86_l_33d9;
	case 13281ULL: goto x86_l_33e1;
	case 13289ULL: goto x86_l_33e9;
	case 13294ULL: goto x86_l_33ee;
	case 13302ULL: goto x86_l_33f6;
	case 13310ULL: goto x86_l_33fe;
	case 13315ULL: goto x86_l_3403;
	case 13323ULL: goto x86_l_340b;
	case 13331ULL: goto x86_l_3413;
	case 13336ULL: goto x86_l_3418;
	case 13339ULL: goto x86_l_341b;
	case 13344ULL: goto x86_l_3420;
	case 13349ULL: goto x86_l_3425;
	case 13357ULL: goto x86_l_342d;
	case 13365ULL: goto x86_l_3435;
	case 13369ULL: goto x86_l_3439;
	case 13375ULL: goto x86_l_343f;
	case 13380ULL: goto x86_l_3444;
	case 13383ULL: goto x86_l_3447;
	case 13388ULL: goto x86_l_344c;
	case 13392ULL: goto x86_l_3450;
	case 13398ULL: goto x86_l_3456;
	case 13403ULL: goto x86_l_345b;
	case 13411ULL: goto x86_l_3463;
	case 13419ULL: goto x86_l_346b;
	case 13423ULL: goto x86_l_346f;
	case 13429ULL: goto x86_l_3475;
	case 13434ULL: goto x86_l_347a;
	case 13442ULL: goto x86_l_3482;
	case 13450ULL: goto x86_l_348a;
	case 13454ULL: goto x86_l_348e;
	case 13460ULL: goto x86_l_3494;
	case 13465ULL: goto x86_l_3499;
	case 13473ULL: goto x86_l_34a1;
	case 13481ULL: goto x86_l_34a9;
	case 13485ULL: goto x86_l_34ad;
	case 13491ULL: goto x86_l_34b3;
	case 13496ULL: goto x86_l_34b8;
	case 13504ULL: goto x86_l_34c0;
	case 13509ULL: goto x86_l_34c5;
	case 13517ULL: goto x86_l_34cd;
	case 13522ULL: goto x86_l_34d2;
	case 13530ULL: goto x86_l_34da;
	case 13535ULL: goto x86_l_34df;
	case 13543ULL: goto x86_l_34e7;
	case 13548ULL: goto x86_l_34ec;
	case 13553ULL: goto x86_l_34f1;
	case 13558ULL: goto x86_l_34f6;
	case 13566ULL: goto x86_l_34fe;
	case 13571ULL: goto x86_l_3503;
	case 13576ULL: goto x86_l_3508;
	case 13581ULL: goto x86_l_350d;
	case 13589ULL: goto x86_l_3515;
	case 13594ULL: goto x86_l_351a;
	case 13602ULL: goto x86_l_3522;
	case 13607ULL: goto x86_l_3527;
	case 13615ULL: goto x86_l_352f;
	case 13620ULL: goto x86_l_3534;
	case 13628ULL: goto x86_l_353c;
	case 13633ULL: goto x86_l_3541;
	case 13641ULL: goto x86_l_3549;
	case 13646ULL: goto x86_l_354e;
	case 13654ULL: goto x86_l_3556;
	case 13659ULL: goto x86_l_355b;
	case 13667ULL: goto x86_l_3563;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3258:
	/* 0x3258: mov    DWORD PTR [rsp+0x14],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345927ULL);
x86_l_3260:
	/* 0x3260: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3268:
	/* 0x3268: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_326c:
	/* 0x326c: jne    f6 <generic_sleepable_preload+0xf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 246ULL;
	}
x86_l_3272:
	/* 0x3272: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3277:
	/* 0x3277: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_327c:
	/* 0x327c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3281:
	/* 0x3281: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3283:
	/* 0x3283: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3288:
	/* 0x3288: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_3290:
	/* 0x3290: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3297:
	/* 0x3297: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_329c:
	/* 0x329c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32a1:
	/* 0x32a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a3:
	/* 0x32a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32a6:
	/* 0x32a6: je     f6 <generic_sleepable_preload+0xf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 246ULL;
	}
x86_l_32ac:
	/* 0x32ac: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_32af:
	/* 0x32af: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32b4:
	/* 0x32b4: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_32b7:
	/* 0x32b7: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_32be:
	/* 0x32be: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32c0:
	/* 0x32c0: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_32c3:
	/* 0x32c3: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32c8:
	/* 0x32c8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_32cd:
	/* 0x32cd: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_32d0:
	/* 0x32d0: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_32d3:
	/* 0x32d3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32d5:
	/* 0x32d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32d7:
	/* 0x32d7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32dc:
	/* 0x32dc: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_32df:
	/* 0x32df: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_32e2:
	/* 0x32e2: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32e7:
	/* 0x32e7: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_32ea:
	/* 0x32ea: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_32ed:
	/* 0x32ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ef:
	/* 0x32ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32f2:
	/* 0x32f2: je     f6 <generic_sleepable_preload+0xf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 246ULL;
	}
x86_l_32f8:
	/* 0x32f8: cmp    BYTE PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_32fd:
	/* 0x32fd: jne    2e5a <generic_sleepable_preload+0x2e5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11866ULL;
	}
x86_l_3303:
	/* 0x3303: mov    edx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3307:
	/* 0x3307: mov    DWORD PTR [rax],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3309:
	/* 0x3309: jmp    f6 <generic_sleepable_preload+0xf6> */
	return 246ULL;
x86_l_330e:
	/* 0x330e: mov    DWORD PTR [rsp+0x14],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345927ULL);
x86_l_3316:
	/* 0x3316: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_331e:
	/* 0x331e: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3322:
	/* 0x3322: jne    104 <generic_sleepable_preload+0x104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 260ULL;
	}
x86_l_3328:
	/* 0x3328: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_332d:
	/* 0x332d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3332:
	/* 0x3332: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3337:
	/* 0x3337: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3339:
	/* 0x3339: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_333e:
	/* 0x333e: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_3346:
	/* 0x3346: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_334d:
	/* 0x334d: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3352:
	/* 0x3352: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3357:
	/* 0x3357: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3359:
	/* 0x3359: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_335c:
	/* 0x335c: je     104 <generic_sleepable_preload+0x104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 260ULL;
	}
x86_l_3362:
	/* 0x3362: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3365:
	/* 0x3365: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_336a:
	/* 0x336a: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_336d:
	/* 0x336d: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3374:
	/* 0x3374: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3376:
	/* 0x3376: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_3379:
	/* 0x3379: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_337e:
	/* 0x337e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3383:
	/* 0x3383: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3386:
	/* 0x3386: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3389:
	/* 0x3389: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_338b:
	/* 0x338b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_338d:
	/* 0x338d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3392:
	/* 0x3392: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3395:
	/* 0x3395: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_3398:
	/* 0x3398: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_339d:
	/* 0x339d: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_33a0:
	/* 0x33a0: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_33a3:
	/* 0x33a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33a5:
	/* 0x33a5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33a8:
	/* 0x33a8: je     104 <generic_sleepable_preload+0x104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 260ULL;
	}
x86_l_33ae:
	/* 0x33ae: cmp    BYTE PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_33b3:
	/* 0x33b3: jne    2f55 <generic_sleepable_preload+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12117ULL;
	}
x86_l_33b9:
	/* 0x33b9: mov    edx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_33bd:
	/* 0x33bd: mov    DWORD PTR [rax],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33bf:
	/* 0x33bf: jmp    104 <generic_sleepable_preload+0x104> */
	return 260ULL;
x86_l_33c4:
	/* 0x33c4: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_33cc:
	/* 0x33cc: mov    DWORD PTR [rsp+0x18],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215112ULL);
x86_l_33d4:
	/* 0x33d4: jmp    2bda <generic_sleepable_preload+0x2bda> */
	return 11226ULL;
x86_l_33d9:
	/* 0x33d9: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_33e1:
	/* 0x33e1: mov    DWORD PTR [rsp+0x14],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345928ULL);
x86_l_33e9:
	/* 0x33e9: jmp    2ca7 <generic_sleepable_preload+0x2ca7> */
	return 11431ULL;
x86_l_33ee:
	/* 0x33ee: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_33f6:
	/* 0x33f6: mov    DWORD PTR [rsp+0x14],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345928ULL);
x86_l_33fe:
	/* 0x33fe: jmp    2da2 <generic_sleepable_preload+0x2da2> */
	return 11682ULL;
x86_l_3403:
	/* 0x3403: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_340b:
	/* 0x340b: mov    DWORD PTR [rsp+0x14],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345928ULL);
x86_l_3413:
	/* 0x3413: jmp    2e9d <generic_sleepable_preload+0x2e9d> */
	return 11933ULL;
x86_l_3418:
	/* 0x3418: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_341b:
	/* 0x341b: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_3420:
	/* 0x3420: jmp    2f90 <generic_sleepable_preload+0x2f90> */
	return 12176ULL;
x86_l_3425:
	/* 0x3425: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_342d:
	/* 0x342d: mov    DWORD PTR [rsp+0x18],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215112ULL);
x86_l_3435:
	/* 0x3435: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3439:
	/* 0x3439: jne    de <generic_sleepable_preload+0xde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 222ULL;
	}
x86_l_343f:
	/* 0x343f: jmp    302e <generic_sleepable_preload+0x302e> */
	return 12334ULL;
x86_l_3444:
	/* 0x3444: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3447:
	/* 0x3447: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_344c:
	/* 0x344c: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_3450:
	/* 0x3450: jne    112 <generic_sleepable_preload+0x112> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 274ULL;
	}
x86_l_3456:
	/* 0x3456: jmp    3103 <generic_sleepable_preload+0x3103> */
	return 12547ULL;
x86_l_345b:
	/* 0x345b: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3463:
	/* 0x3463: mov    DWORD PTR [rsp+0x14],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345928ULL);
x86_l_346b:
	/* 0x346b: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_346f:
	/* 0x346f: jne    e8 <generic_sleepable_preload+0xe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 232ULL;
	}
x86_l_3475:
	/* 0x3475: jmp    31bc <generic_sleepable_preload+0x31bc> */
	return 12732ULL;
x86_l_347a:
	/* 0x347a: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3482:
	/* 0x3482: mov    DWORD PTR [rsp+0x14],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345928ULL);
x86_l_348a:
	/* 0x348a: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_348e:
	/* 0x348e: jne    f6 <generic_sleepable_preload+0xf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 246ULL;
	}
x86_l_3494:
	/* 0x3494: jmp    3272 <generic_sleepable_preload+0x3272> */
	goto x86_l_3272;
x86_l_3499:
	/* 0x3499: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_34a1:
	/* 0x34a1: mov    DWORD PTR [rsp+0x14],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345928ULL);
x86_l_34a9:
	/* 0x34a9: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_34ad:
	/* 0x34ad: jne    104 <generic_sleepable_preload+0x104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 260ULL;
	}
x86_l_34b3:
	/* 0x34b3: jmp    3328 <generic_sleepable_preload+0x3328> */
	goto x86_l_3328;
x86_l_34b8:
	/* 0x34b8: mov    DWORD PTR [rsp+0x18],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215113ULL);
x86_l_34c0:
	/* 0x34c0: jmp    2bd2 <generic_sleepable_preload+0x2bd2> */
	return 11218ULL;
x86_l_34c5:
	/* 0x34c5: mov    DWORD PTR [rsp+0x14],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345929ULL);
x86_l_34cd:
	/* 0x34cd: jmp    2c9f <generic_sleepable_preload+0x2c9f> */
	return 11423ULL;
x86_l_34d2:
	/* 0x34d2: mov    DWORD PTR [rsp+0x14],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345929ULL);
x86_l_34da:
	/* 0x34da: jmp    2d9a <generic_sleepable_preload+0x2d9a> */
	return 11674ULL;
x86_l_34df:
	/* 0x34df: mov    DWORD PTR [rsp+0x14],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345929ULL);
x86_l_34e7:
	/* 0x34e7: jmp    2e95 <generic_sleepable_preload+0x2e95> */
	return 11925ULL;
x86_l_34ec:
	/* 0x34ec: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_34f1:
	/* 0x34f1: jmp    2f8d <generic_sleepable_preload+0x2f8d> */
	return 12173ULL;
x86_l_34f6:
	/* 0x34f6: mov    DWORD PTR [rsp+0x18],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215113ULL);
x86_l_34fe:
	/* 0x34fe: jmp    301c <generic_sleepable_preload+0x301c> */
	return 12316ULL;
x86_l_3503:
	/* 0x3503: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_3508:
	/* 0x3508: jmp    30f6 <generic_sleepable_preload+0x30f6> */
	return 12534ULL;
x86_l_350d:
	/* 0x350d: mov    DWORD PTR [rsp+0x14],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345929ULL);
x86_l_3515:
	/* 0x3515: jmp    31aa <generic_sleepable_preload+0x31aa> */
	return 12714ULL;
x86_l_351a:
	/* 0x351a: mov    DWORD PTR [rsp+0x14],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345929ULL);
x86_l_3522:
	/* 0x3522: jmp    3260 <generic_sleepable_preload+0x3260> */
	goto x86_l_3260;
x86_l_3527:
	/* 0x3527: mov    DWORD PTR [rsp+0x14],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345929ULL);
x86_l_352f:
	/* 0x352f: jmp    3316 <generic_sleepable_preload+0x3316> */
	goto x86_l_3316;
x86_l_3534:
	/* 0x3534: mov    DWORD PTR [rsp+0x18],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215114ULL);
x86_l_353c:
	/* 0x353c: jmp    2bd2 <generic_sleepable_preload+0x2bd2> */
	return 11218ULL;
x86_l_3541:
	/* 0x3541: mov    DWORD PTR [rsp+0x14],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345930ULL);
x86_l_3549:
	/* 0x3549: jmp    2c9f <generic_sleepable_preload+0x2c9f> */
	return 11423ULL;
x86_l_354e:
	/* 0x354e: mov    DWORD PTR [rsp+0x14],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345930ULL);
x86_l_3556:
	/* 0x3556: jmp    2d9a <generic_sleepable_preload+0x2d9a> */
	return 11674ULL;
x86_l_355b:
	/* 0x355b: mov    DWORD PTR [rsp+0x14],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345930ULL);
x86_l_3563:
	/* 0x3563: jmp    2e95 <generic_sleepable_preload+0x2e95> */
	return 11925ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11360U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1747ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1752ULL && __x86_pc <= 3629ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3631ULL && __x86_pc <= 5529ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5534ULL && __x86_pc <= 7366ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7372ULL && __x86_pc <= 9283ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9288ULL && __x86_pc <= 11302ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11307ULL && __x86_pc <= 12883ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12888ULL && __x86_pc <= 13667ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_v53_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

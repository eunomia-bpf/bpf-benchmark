extern char buffer_heap_map;
extern char config_map;
extern char fdinstall_map;
extern char process_call_heap;
extern char sleepable_preload;
extern char tg_ipv6_ext_heap;
extern char uprobe_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_0(
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
	case 69ULL: goto x86_l_45;
	case 76ULL: goto x86_l_4c;
	case 82ULL: goto x86_l_52;
	case 93ULL: goto x86_l_5d;
	case 100ULL: goto x86_l_64;
	case 108ULL: goto x86_l_6c;
	case 113ULL: goto x86_l_71;
	case 115ULL: goto x86_l_73;
	case 118ULL: goto x86_l_76;
	case 124ULL: goto x86_l_7c;
	case 127ULL: goto x86_l_7f;
	case 134ULL: goto x86_l_86;
	case 141ULL: goto x86_l_8d;
	case 146ULL: goto x86_l_92;
	case 148ULL: goto x86_l_94;
	case 152ULL: goto x86_l_98;
	case 158ULL: goto x86_l_9e;
	case 161ULL: goto x86_l_a1;
	case 167ULL: goto x86_l_a7;
	case 175ULL: goto x86_l_af;
	case 179ULL: goto x86_l_b3;
	case 182ULL: goto x86_l_b6;
	case 187ULL: goto x86_l_bb;
	case 190ULL: goto x86_l_be;
	case 194ULL: goto x86_l_c2;
	case 199ULL: goto x86_l_c7;
	case 211ULL: goto x86_l_d3;
	case 215ULL: goto x86_l_d7;
	case 223ULL: goto x86_l_df;
	case 229ULL: goto x86_l_e5;
	case 239ULL: goto x86_l_ef;
	case 243ULL: goto x86_l_f3;
	case 249ULL: goto x86_l_f9;
	case 256ULL: goto x86_l_100;
	case 262ULL: goto x86_l_106;
	case 265ULL: goto x86_l_109;
	case 267ULL: goto x86_l_10b;
	case 271ULL: goto x86_l_10f;
	case 273ULL: goto x86_l_111;
	case 278ULL: goto x86_l_116;
	case 282ULL: goto x86_l_11a;
	case 285ULL: goto x86_l_11d;
	case 293ULL: goto x86_l_125;
	case 298ULL: goto x86_l_12a;
	case 303ULL: goto x86_l_12f;
	case 311ULL: goto x86_l_137;
	case 314ULL: goto x86_l_13a;
	case 317ULL: goto x86_l_13d;
	case 320ULL: goto x86_l_140;
	case 324ULL: goto x86_l_144;
	case 332ULL: goto x86_l_14c;
	case 334ULL: goto x86_l_14e;
	case 337ULL: goto x86_l_151;
	case 343ULL: goto x86_l_157;
	case 346ULL: goto x86_l_15a;
	case 351ULL: goto x86_l_15f;
	case 356ULL: goto x86_l_164;
	case 361ULL: goto x86_l_169;
	case 366ULL: goto x86_l_16e;
	case 368ULL: goto x86_l_170;
	case 375ULL: goto x86_l_177;
	case 380ULL: goto x86_l_17c;
	case 385ULL: goto x86_l_181;
	case 390ULL: goto x86_l_186;
	case 392ULL: goto x86_l_188;
	case 395ULL: goto x86_l_18b;
	case 400ULL: goto x86_l_190;
	case 406ULL: goto x86_l_196;
	case 409ULL: goto x86_l_199;
	case 412ULL: goto x86_l_19c;
	case 418ULL: goto x86_l_1a2;
	case 421ULL: goto x86_l_1a5;
	case 427ULL: goto x86_l_1ab;
	case 430ULL: goto x86_l_1ae;
	case 436ULL: goto x86_l_1b4;
	case 439ULL: goto x86_l_1b7;
	case 445ULL: goto x86_l_1bd;
	case 448ULL: goto x86_l_1c0;
	case 454ULL: goto x86_l_1c6;
	case 457ULL: goto x86_l_1c9;
	case 463ULL: goto x86_l_1cf;
	case 468ULL: goto x86_l_1d4;
	case 471ULL: goto x86_l_1d7;
	case 480ULL: goto x86_l_1e0;
	case 485ULL: goto x86_l_1e5;
	case 488ULL: goto x86_l_1e8;
	case 493ULL: goto x86_l_1ed;
	case 500ULL: goto x86_l_1f4;
	case 505ULL: goto x86_l_1f9;
	case 508ULL: goto x86_l_1fc;
	case 513ULL: goto x86_l_201;
	case 516ULL: goto x86_l_204;
	case 521ULL: goto x86_l_209;
	case 523ULL: goto x86_l_20b;
	case 526ULL: goto x86_l_20e;
	case 533ULL: goto x86_l_215;
	case 539ULL: goto x86_l_21b;
	case 548ULL: goto x86_l_224;
	case 553ULL: goto x86_l_229;
	case 555ULL: goto x86_l_22b;
	case 560ULL: goto x86_l_230;
	case 567ULL: goto x86_l_237;
	case 572ULL: goto x86_l_23c;
	case 577ULL: goto x86_l_241;
	case 579ULL: goto x86_l_243;
	case 582ULL: goto x86_l_246;
	case 584ULL: goto x86_l_248;
	case 586ULL: goto x86_l_24a;
	case 591ULL: goto x86_l_24f;
	case 599ULL: goto x86_l_257;
	case 602ULL: goto x86_l_25a;
	case 604ULL: goto x86_l_25c;
	case 608ULL: goto x86_l_260;
	case 613ULL: goto x86_l_265;
	case 618ULL: goto x86_l_26a;
	case 623ULL: goto x86_l_26f;
	case 628ULL: goto x86_l_274;
	case 633ULL: goto x86_l_279;
	case 636ULL: goto x86_l_27c;
	case 638ULL: goto x86_l_27e;
	case 643ULL: goto x86_l_283;
	case 646ULL: goto x86_l_286;
	case 652ULL: goto x86_l_28c;
	case 654ULL: goto x86_l_28e;
	case 664ULL: goto x86_l_298;
	case 668ULL: goto x86_l_29c;
	case 674ULL: goto x86_l_2a2;
	case 681ULL: goto x86_l_2a9;
	case 688ULL: goto x86_l_2b0;
	case 691ULL: goto x86_l_2b3;
	case 696ULL: goto x86_l_2b8;
	case 698ULL: goto x86_l_2ba;
	case 701ULL: goto x86_l_2bd;
	case 707ULL: goto x86_l_2c3;
	case 710ULL: goto x86_l_2c6;
	case 717ULL: goto x86_l_2cd;
	case 723ULL: goto x86_l_2d3;
	case 735ULL: goto x86_l_2df;
	case 742ULL: goto x86_l_2e6;
	case 745ULL: goto x86_l_2e9;
	case 750ULL: goto x86_l_2ee;
	case 752ULL: goto x86_l_2f0;
	case 755ULL: goto x86_l_2f3;
	case 761ULL: goto x86_l_2f9;
	case 764ULL: goto x86_l_2fc;
	case 769ULL: goto x86_l_301;
	case 777ULL: goto x86_l_309;
	case 785ULL: goto x86_l_311;
	case 793ULL: goto x86_l_319;
	case 796ULL: goto x86_l_31c;
	case 800ULL: goto x86_l_320;
	case 808ULL: goto x86_l_328;
	case 813ULL: goto x86_l_32d;
	case 815ULL: goto x86_l_32f;
	case 821ULL: goto x86_l_335;
	case 824ULL: goto x86_l_338;
	case 831ULL: goto x86_l_33f;
	case 839ULL: goto x86_l_347;
	case 844ULL: goto x86_l_34c;
	case 849ULL: goto x86_l_351;
	case 851ULL: goto x86_l_353;
	case 856ULL: goto x86_l_358;
	case 859ULL: goto x86_l_35b;
	case 867ULL: goto x86_l_363;
	case 871ULL: goto x86_l_367;
	case 875ULL: goto x86_l_36b;
	case 881ULL: goto x86_l_371;
	case 886ULL: goto x86_l_376;
	case 889ULL: goto x86_l_379;
	case 891ULL: goto x86_l_37b;
	case 893ULL: goto x86_l_37d;
	case 901ULL: goto x86_l_385;
	case 905ULL: goto x86_l_389;
	case 910ULL: goto x86_l_38e;
	case 915ULL: goto x86_l_393;
	case 920ULL: goto x86_l_398;
	case 925ULL: goto x86_l_39d;
	case 928ULL: goto x86_l_3a0;
	case 936ULL: goto x86_l_3a8;
	case 938ULL: goto x86_l_3aa;
	case 943ULL: goto x86_l_3af;
	case 947ULL: goto x86_l_3b3;
	case 952ULL: goto x86_l_3b8;
	case 957ULL: goto x86_l_3bd;
	case 962ULL: goto x86_l_3c2;
	case 967ULL: goto x86_l_3c7;
	case 971ULL: goto x86_l_3cb;
	case 976ULL: goto x86_l_3d0;
	case 978ULL: goto x86_l_3d2;
	case 983ULL: goto x86_l_3d7;
	case 991ULL: goto x86_l_3df;
	case 996ULL: goto x86_l_3e4;
	case 1001ULL: goto x86_l_3e9;
	case 1006ULL: goto x86_l_3ee;
	case 1011ULL: goto x86_l_3f3;
	case 1013ULL: goto x86_l_3f5;
	case 1016ULL: goto x86_l_3f8;
	case 1021ULL: goto x86_l_3fd;
	case 1030ULL: goto x86_l_406;
	case 1038ULL: goto x86_l_40e;
	case 1044ULL: goto x86_l_414;
	case 1047ULL: goto x86_l_417;
	case 1052ULL: goto x86_l_41c;
	case 1057ULL: goto x86_l_421;
	case 1066ULL: goto x86_l_42a;
	case 1069ULL: goto x86_l_42d;
	case 1071ULL: goto x86_l_42f;
	case 1074ULL: goto x86_l_432;
	case 1080ULL: goto x86_l_438;
	case 1083ULL: goto x86_l_43b;
	case 1089ULL: goto x86_l_441;
	case 1097ULL: goto x86_l_449;
	case 1102ULL: goto x86_l_44e;
	case 1108ULL: goto x86_l_454;
	case 1111ULL: goto x86_l_457;
	case 1117ULL: goto x86_l_45d;
	case 1120ULL: goto x86_l_460;
	case 1126ULL: goto x86_l_466;
	case 1129ULL: goto x86_l_469;
	case 1135ULL: goto x86_l_46f;
	case 1138ULL: goto x86_l_472;
	case 1141ULL: goto x86_l_475;
	case 1146ULL: goto x86_l_47a;
	case 1152ULL: goto x86_l_480;
	case 1155ULL: goto x86_l_483;
	case 1158ULL: goto x86_l_486;
	case 1164ULL: goto x86_l_48c;
	case 1167ULL: goto x86_l_48f;
	case 1173ULL: goto x86_l_495;
	case 1178ULL: goto x86_l_49a;
	case 1181ULL: goto x86_l_49d;
	case 1187ULL: goto x86_l_4a3;
	case 1190ULL: goto x86_l_4a6;
	case 1192ULL: goto x86_l_4a8;
	case 1195ULL: goto x86_l_4ab;
	case 1201ULL: goto x86_l_4b1;
	case 1213ULL: goto x86_l_4bd;
	case 1221ULL: goto x86_l_4c5;
	case 1226ULL: goto x86_l_4ca;
	case 1228ULL: goto x86_l_4cc;
	case 1236ULL: goto x86_l_4d4;
	case 1239ULL: goto x86_l_4d7;
	case 1242ULL: goto x86_l_4da;
	case 1250ULL: goto x86_l_4e2;
	case 1254ULL: goto x86_l_4e6;
	case 1258ULL: goto x86_l_4ea;
	case 1260ULL: goto x86_l_4ec;
	case 1268ULL: goto x86_l_4f4;
	case 1275ULL: goto x86_l_4fb;
	case 1280ULL: goto x86_l_500;
	case 1285ULL: goto x86_l_505;
	case 1287ULL: goto x86_l_507;
	case 1290ULL: goto x86_l_50a;
	case 1292ULL: goto x86_l_50c;
	case 1295ULL: goto x86_l_50f;
	case 1302ULL: goto x86_l_516;
	case 1309ULL: goto x86_l_51d;
	case 1314ULL: goto x86_l_522;
	case 1316ULL: goto x86_l_524;
	case 1319ULL: goto x86_l_527;
	case 1321ULL: goto x86_l_529;
	case 1324ULL: goto x86_l_52c;
	case 1327ULL: goto x86_l_52f;
	case 1330ULL: goto x86_l_532;
	case 1335ULL: goto x86_l_537;
	case 1337ULL: goto x86_l_539;
	case 1344ULL: goto x86_l_540;
	case 1351ULL: goto x86_l_547;
	case 1356ULL: goto x86_l_54c;
	case 1361ULL: goto x86_l_551;
	case 1364ULL: goto x86_l_554;
	case 1369ULL: goto x86_l_559;
	case 1371ULL: goto x86_l_55b;
	case 1382ULL: goto x86_l_566;
	case 1389ULL: goto x86_l_56d;
	case 1394ULL: goto x86_l_572;
	case 1399ULL: goto x86_l_577;
	case 1402ULL: goto x86_l_57a;
	case 1407ULL: goto x86_l_57f;
	case 1409ULL: goto x86_l_581;
	case 1411ULL: goto x86_l_583;
	case 1418ULL: goto x86_l_58a;
	case 1420ULL: goto x86_l_58c;
	case 1421ULL: goto x86_l_58d;
	case 1426ULL: goto x86_l_592;
	case 1429ULL: goto x86_l_595;
	case 1435ULL: goto x86_l_59b;
	case 1438ULL: goto x86_l_59e;
	case 1443ULL: goto x86_l_5a3;
	case 1449ULL: goto x86_l_5a9;
	case 1452ULL: goto x86_l_5ac;
	case 1455ULL: goto x86_l_5af;
	case 1461ULL: goto x86_l_5b5;
	case 1464ULL: goto x86_l_5b8;
	case 1470ULL: goto x86_l_5be;
	case 1475ULL: goto x86_l_5c3;
	case 1478ULL: goto x86_l_5c6;
	case 1484ULL: goto x86_l_5cc;
	case 1487ULL: goto x86_l_5cf;
	case 1493ULL: goto x86_l_5d5;
	case 1495ULL: goto x86_l_5d7;
	case 1501ULL: goto x86_l_5dd;
	case 1504ULL: goto x86_l_5e0;
	case 1510ULL: goto x86_l_5e6;
	case 1515ULL: goto x86_l_5eb;
	case 1518ULL: goto x86_l_5ee;
	case 1524ULL: goto x86_l_5f4;
	case 1529ULL: goto x86_l_5f9;
	case 1534ULL: goto x86_l_5fe;
	case 1539ULL: goto x86_l_603;
	case 1544ULL: goto x86_l_608;
	case 1549ULL: goto x86_l_60d;
	case 1554ULL: goto x86_l_612;
	case 1556ULL: goto x86_l_614;
	case 1561ULL: goto x86_l_619;
	case 1564ULL: goto x86_l_61c;
	case 1572ULL: goto x86_l_624;
	case 1574ULL: goto x86_l_626;
	case 1576ULL: goto x86_l_628;
	case 1581ULL: goto x86_l_62d;
	case 1589ULL: goto x86_l_635;
	case 1594ULL: goto x86_l_63a;
	case 1599ULL: goto x86_l_63f;
	case 1604ULL: goto x86_l_644;
	case 1607ULL: goto x86_l_647;
	case 1612ULL: goto x86_l_64c;
	case 1614ULL: goto x86_l_64e;
	case 1622ULL: goto x86_l_656;
	case 1627ULL: goto x86_l_65b;
	case 1632ULL: goto x86_l_660;
	case 1637ULL: goto x86_l_665;
	case 1642ULL: goto x86_l_66a;
	case 1650ULL: goto x86_l_672;
	case 1655ULL: goto x86_l_677;
	case 1657ULL: goto x86_l_679;
	case 1665ULL: goto x86_l_681;
	case 1669ULL: goto x86_l_685;
	case 1677ULL: goto x86_l_68d;
	case 1685ULL: goto x86_l_695;
	case 1692ULL: goto x86_l_69c;
	case 1697ULL: goto x86_l_6a1;
	case 1702ULL: goto x86_l_6a6;
	case 1705ULL: goto x86_l_6a9;
	case 1710ULL: goto x86_l_6ae;
	case 1712ULL: goto x86_l_6b0;
	case 1714ULL: goto x86_l_6b2;
	case 1719ULL: goto x86_l_6b7;
	case 1722ULL: goto x86_l_6ba;
	case 1728ULL: goto x86_l_6c0;
	case 1731ULL: goto x86_l_6c3;
	case 1734ULL: goto x86_l_6c6;
	case 1739ULL: goto x86_l_6cb;
	case 1741ULL: goto x86_l_6cd;
	case 1744ULL: goto x86_l_6d0;
	case 1746ULL: goto x86_l_6d2;
	case 1749ULL: goto x86_l_6d5;
	case 1755ULL: goto x86_l_6db;
	case 1760ULL: goto x86_l_6e0;
	case 1763ULL: goto x86_l_6e3;
	case 1768ULL: goto x86_l_6e8;
	case 1774ULL: goto x86_l_6ee;
	case 1780ULL: goto x86_l_6f4;
	case 1785ULL: goto x86_l_6f9;
	case 1788ULL: goto x86_l_6fc;
	case 1794ULL: goto x86_l_702;
	case 1797ULL: goto x86_l_705;
	case 1803ULL: goto x86_l_70b;
	case 1806ULL: goto x86_l_70e;
	case 1811ULL: goto x86_l_713;
	case 1817ULL: goto x86_l_719;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 232ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_18:
	/* 0x18: mov    rdi,QWORD PTR [rip+0x217] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
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
	/* 0x31: je     581 <generic_uprobe_process_event+0x581> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_581;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    r12d,DWORD PTR [rax+0x5eec] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24300ULL);
x86_l_41:
	/* 0x41: mov    r13d,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_45:
	/* 0x45: cmp    r13,0x2327 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8999ULL);
x86_l_4c:
	/* 0x4c: ja     4e2 <generic_uprobe_process_event+0x4e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e2;
	}
x86_l_52:
	/* 0x52: mov    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_5d:
	/* 0x5d: mov    rdi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_64:
	/* 0x64: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_6c:
	/* 0x6c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_71:
	/* 0x71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73:
	/* 0x73: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_76:
	/* 0x76: je     4e2 <generic_uprobe_process_event+0x4e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e2;
	}
x86_l_7c:
	/* 0x7c: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_7f:
	/* 0x7f: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_86:
	/* 0x86: mov    rdi,QWORD PTR [rip+0x217] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_8d:
	/* 0x8d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_92:
	/* 0x92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94:
	/* 0x94: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_98:
	/* 0x98: jg     4e2 <generic_uprobe_process_event+0x4e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4e2;
	}
x86_l_9e:
	/* 0x9e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a1:
	/* 0xa1: je     4e2 <generic_uprobe_process_event+0x4e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e2;
	}
x86_l_a7:
	/* 0xa7: mov    QWORD PTR [rsp+0xe0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_af:
	/* 0xaf: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_b3:
	/* 0xb3: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_b6:
	/* 0xb6: mov    QWORD PTR [rsp+0x68],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bb:
	/* 0xbb: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_be:
	/* 0xbe: mov    ebp,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_c2:
	/* 0xc2: movsxd r12,DWORD PTR [rax+rcx*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RCX, 2, X86_WIDTH_32), 24ULL);
x86_l_c7:
	/* 0xc7: mov    DWORD PTR [r15+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_d3:
	/* 0xd3: cmp    rbp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 40ULL);
x86_l_d7:
	/* 0xd7: mov    QWORD PTR [rsp+0x90],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_df:
	/* 0xdf: ja     1ed <generic_uprobe_process_event+0x1ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ed;
	}
x86_l_e5:
	/* 0xe5: movabs rcx,0x1c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1932500565234ULL);
x86_l_ef:
	/* 0xef: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_f3:
	/* 0xf3: jae    1ed <generic_uprobe_process_event+0x1ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1ed;
	}
x86_l_f9:
	/* 0xf9: test   r12d,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 256ULL);
x86_l_100:
	/* 0x100: jne    21b <generic_uprobe_process_event+0x21b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21b;
	}
x86_l_106:
	/* 0x106: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_109:
	/* 0x109: js     12a <generic_uprobe_process_event+0x12a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_12a;
	}
x86_l_10b:
	/* 0x10b: test   r12b,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 64ULL);
x86_l_10f:
	/* 0x10f: jne    181 <generic_uprobe_process_event+0x181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_181;
	}
x86_l_111:
	/* 0x111: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_116:
	/* 0x116: mov    eax,DWORD PTR [rax+rcx*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 64ULL);
x86_l_11a:
	/* 0x11a: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_11d:
	/* 0x11d: mov    r13,QWORD PTR [r15+rax*8+0x5e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24144ULL);
x86_l_125:
	/* 0x125: jmp    283 <generic_uprobe_process_event+0x283> */
	goto x86_l_283;
x86_l_12a:
	/* 0x12a: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_12f:
	/* 0x12f: movzx  ecx,BYTE PTR [rax+rdx*4+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 2, X86_WIDTH_8), 706ULL);
x86_l_137:
	/* 0x137: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_13a:
	/* 0x13a: mov    r15b,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 64ULL);
x86_l_13d:
	/* 0x13d: sub    r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_140:
	/* 0x140: cmp    DWORD PTR [rax+0x54],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_144:
	/* 0x144: movzx  edx,WORD PTR [rax+rdx*4+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 2, X86_WIDTH_16), 704ULL);
x86_l_14c:
	/* 0x14c: je     190 <generic_uprobe_process_event+0x190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_190;
	}
x86_l_14e:
	/* 0x14e: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_151:
	/* 0x151: je     1e5 <generic_uprobe_process_event+0x1e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e5;
	}
x86_l_157:
	/* 0x157: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_15a:
	/* 0x15a: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15f:
	/* 0x15f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_164:
	/* 0x164: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_169:
	/* 0x169: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16e:
	/* 0x16e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170:
	/* 0x170: shlx   rax,QWORD PTR [rsp+0x28],r15 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R15)), ((40ULL << 32) | X86_ALU_SHL));
x86_l_177:
	/* 0x177: sarx   r13,rax,r15 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R13, X86_RAX, X86_WIDTH_64, X86_R15, X86_ALU_SAR);
x86_l_17c:
	/* 0x17c: jmp    283 <generic_uprobe_process_event+0x283> */
	goto x86_l_283;
x86_l_181:
	/* 0x181: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_186:
	/* 0x186: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_188:
	/* 0x188: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_18b:
	/* 0x18b: jmp    283 <generic_uprobe_process_event+0x283> */
	goto x86_l_283;
x86_l_190:
	/* 0x190: rorx   eax,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_196:
	/* 0x196: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_199:
	/* 0x199: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_19c:
	/* 0x19c: jle    5c3 <generic_uprobe_process_event+0x5c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5c3;
	}
x86_l_1a2:
	/* 0x1a2: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1a5:
	/* 0x1a5: jle    750 <generic_uprobe_process_event+0x750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1872ULL;
	}
x86_l_1ab:
	/* 0x1ab: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1ae:
	/* 0x1ae: jle    867 <generic_uprobe_process_event+0x867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2151ULL;
	}
x86_l_1b4:
	/* 0x1b4: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1b7:
	/* 0x1b7: je     971 <generic_uprobe_process_event+0x971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2417ULL;
	}
x86_l_1bd:
	/* 0x1bd: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1c0:
	/* 0x1c0: je     910 <generic_uprobe_process_event+0x910> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2320ULL;
	}
x86_l_1c6:
	/* 0x1c6: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1c9:
	/* 0x1c9: jne    283 <generic_uprobe_process_event+0x283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_283;
	}
x86_l_1cf:
	/* 0x1cf: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_1d4:
	/* 0x1d4: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1d7:
	/* 0x1d7: bzhi   r13,QWORD PTR [rbx+0x98],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 152ULL);
x86_l_1e0:
	/* 0x1e0: jmp    283 <generic_uprobe_process_event+0x283> */
	goto x86_l_283;
x86_l_1e5:
	/* 0x1e5: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e8:
	/* 0x1e8: jmp    283 <generic_uprobe_process_event+0x283> */
	goto x86_l_283;
x86_l_1ed:
	/* 0x1ed: mov    rsi,QWORD PTR [rip+0x217] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_1f4:
	/* 0x1f4: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1f9:
	/* 0x1f9: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1fc:
	/* 0x1fc: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_201:
	/* 0x201: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_204:
	/* 0x204: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_209:
	/* 0x209: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b:
	/* 0x20b: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_20e:
	/* 0x20e: test   r12d,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 256ULL);
x86_l_215:
	/* 0x215: je     106 <generic_uprobe_process_event+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106;
	}
x86_l_21b:
	/* 0x21b: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_224:
	/* 0x224: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_229:
	/* 0x229: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22b:
	/* 0x22b: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_230:
	/* 0x230: mov    rdi,QWORD PTR [rip+0x217] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_237:
	/* 0x237: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23c:
	/* 0x23c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_241:
	/* 0x241: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_243:
	/* 0x243: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_246:
	/* 0x246: je     27e <generic_uprobe_process_event+0x27e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e;
	}
x86_l_248:
	/* 0x248: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24a:
	/* 0x24a: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_24f:
	/* 0x24f: mov    DWORD PTR [r15+rdx*4+0x5ea0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 24224ULL);
x86_l_257:
	/* 0x257: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_25a:
	/* 0x25a: jne    27e <generic_uprobe_process_event+0x27e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27e;
	}
x86_l_25c:
	/* 0x25c: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_260:
	/* 0x260: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_265:
	/* 0x265: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26a:
	/* 0x26a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26f:
	/* 0x26f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_274:
	/* 0x274: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_279:
	/* 0x279: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_27c:
	/* 0x27c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e:
	/* 0x27e: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_283:
	/* 0x283: cmp    ebp,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 42ULL);
x86_l_286:
	/* 0x286: ja     44e <generic_uprobe_process_event+0x44e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_44e;
	}
x86_l_28c:
	/* 0x28c: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_28e:
	/* 0x28e: movabs rcx,0x42001018000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 4535502340096ULL);
x86_l_298:
	/* 0x298: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_29c:
	/* 0x29c: jae    44e <generic_uprobe_process_event+0x44e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_44e;
	}
x86_l_2a2:
	/* 0x2a2: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a9:
	/* 0x2a9: mov    rdi,QWORD PTR [rip+0x217] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_2b0:
	/* 0x2b0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2b3:
	/* 0x2b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b8:
	/* 0x2b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba:
	/* 0x2ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bd:
	/* 0x2bd: je     4ca <generic_uprobe_process_event+0x4ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ca;
	}
x86_l_2c3:
	/* 0x2c3: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2c6:
	/* 0x2c6: cmp    DWORD PTR [rax+0x6410],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110019882254336ULL);
x86_l_2cd:
	/* 0x2cd: je     41c <generic_uprobe_process_event+0x41c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41c;
	}
x86_l_2d3:
	/* 0x2d3: mov    DWORD PTR [r12+0x6410],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110019882254336ULL);
x86_l_2df:
	/* 0x2df: mov    rdi,QWORD PTR [rip+0x217] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_2e6:
	/* 0x2e6: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2e9:
	/* 0x2e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ee:
	/* 0x2ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f0:
	/* 0x2f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f3:
	/* 0x2f3: je     4ca <generic_uprobe_process_event+0x4ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ca;
	}
x86_l_2f9:
	/* 0x2f9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2fc:
	/* 0x2fc: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_301:
	/* 0x301: mov    eax,DWORD PTR [r12+rcx*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 24224ULL);
x86_l_309:
	/* 0x309: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_311:
	/* 0x311: mov    DWORD PTR [r12+r13*1+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 144ULL);
x86_l_319:
	/* 0x319: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_31c:
	/* 0x31c: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_320:
	/* 0x320: mov    QWORD PTR [r12+rcx*8+0x5e78],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_328:
	/* 0x328: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_32d:
	/* 0x32d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32f:
	/* 0x32f: jne    4d4 <generic_uprobe_process_event+0x4d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4d4;
	}
x86_l_335:
	/* 0x335: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_338:
	/* 0x338: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_33f:
	/* 0x33f: mov    eax,DWORD PTR [r12+0x6414] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25620ULL);
x86_l_347:
	/* 0x347: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34c:
	/* 0x34c: mov    ebx,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4095ULL);
x86_l_351:
	/* 0x351: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_353:
	/* 0x353: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_358:
	/* 0x358: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_35b:
	/* 0x35b: mov    r13,QWORD PTR [r12+0x6430] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25648ULL);
x86_l_363:
	/* 0x363: lea    rdi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_367:
	/* 0x367: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_36b:
	/* 0x36b: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_371:
	/* 0x371: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_376:
	/* 0x376: add    r15,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_379:
	/* 0x379: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_37b:
	/* 0x37b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37d:
	/* 0x37d: mov    DWORD PTR [r12+rbp*1+0x90],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_385:
	/* 0x385: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_389:
	/* 0x389: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_38e:
	/* 0x38e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_393:
	/* 0x393: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_398:
	/* 0x398: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39d:
	/* 0x39d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3a0:
	/* 0x3a0: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3a8:
	/* 0x3a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3aa:
	/* 0x3aa: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3af:
	/* 0x3af: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_3b3:
	/* 0x3b3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b8:
	/* 0x3b8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3bd:
	/* 0x3bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c2:
	/* 0x3c2: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3c7:
	/* 0x3c7: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_3cb:
	/* 0x3cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d0:
	/* 0x3d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d2:
	/* 0x3d2: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d7:
	/* 0x3d7: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3df:
	/* 0x3df: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3e4:
	/* 0x3e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e9:
	/* 0x3e9: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ee:
	/* 0x3ee: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3f3:
	/* 0x3f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f5:
	/* 0x3f5: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_3f8:
	/* 0x3f8: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fd:
	/* 0x3fd: mov    DWORD PTR [rsi+r15*1+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 17179869184ULL);
x86_l_406:
	/* 0x406: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_40e:
	/* 0x40e: mov    WORD PTR [rsi+r15*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 8ULL);
x86_l_414:
	/* 0x414: add    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_417:
	/* 0x417: jmp    4d4 <generic_uprobe_process_event+0x4d4> */
	goto x86_l_4d4;
x86_l_41c:
	/* 0x41c: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_421:
	/* 0x421: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_42a:
	/* 0x42a: cmp    ebp,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 23ULL);
x86_l_42d:
	/* 0x42d: jg     49a <generic_uprobe_process_event+0x49a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_49a;
	}
x86_l_42f:
	/* 0x42f: cmp    ebp,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 15ULL);
x86_l_432:
	/* 0x432: je     5f9 <generic_uprobe_process_event+0x5f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f9;
	}
x86_l_438:
	/* 0x438: cmp    ebp,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_43b:
	/* 0x43b: jne    4ca <generic_uprobe_process_event+0x4ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4ca;
	}
x86_l_441:
	/* 0x441: lea    r15,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_449:
	/* 0x449: jmp    65b <generic_uprobe_process_event+0x65b> */
	goto x86_l_65b;
x86_l_44e:
	/* 0x44e: mov    r15d,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 144ULL);
x86_l_454:
	/* 0x454: cmp    ebp,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 22ULL);
x86_l_457:
	/* 0x457: jg     592 <generic_uprobe_process_event+0x592> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_592;
	}
x86_l_45d:
	/* 0x45d: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_460:
	/* 0x460: jle    6b7 <generic_uprobe_process_event+0x6b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6b7;
	}
x86_l_466:
	/* 0x466: cmp    ebp,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 17ULL);
x86_l_469:
	/* 0x469: jg     6f9 <generic_uprobe_process_event+0x6f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6f9;
	}
x86_l_46f:
	/* 0x46f: lea    eax,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_472:
	/* 0x472: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_475:
	/* 0x475: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_47a:
	/* 0x47a: jb     7ed <generic_uprobe_process_event+0x7ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2029ULL;
	}
x86_l_480:
	/* 0x480: lea    eax,[rbp-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_483:
	/* 0x483: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_486:
	/* 0x486: jb     6ee <generic_uprobe_process_event+0x6ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6ee;
	}
x86_l_48c:
	/* 0x48c: cmp    ebp,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 17ULL);
x86_l_48f:
	/* 0x48f: je     9aa <generic_uprobe_process_event+0x9aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2474ULL;
	}
x86_l_495:
	/* 0x495: jmp    8d7 <generic_uprobe_process_event+0x8d7> */
	return 2263ULL;
x86_l_49a:
	/* 0x49a: cmp    ebp,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_49d:
	/* 0x49d: je     62d <generic_uprobe_process_event+0x62d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_62d;
	}
x86_l_4a3:
	/* 0x4a3: cmp    ebp,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 42ULL);
x86_l_4a6:
	/* 0x4a6: jne    4ca <generic_uprobe_process_event+0x4ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4ca;
	}
x86_l_4a8:
	/* 0x4a8: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_4ab:
	/* 0x4ab: add    rax,0x6420 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 25632ULL);
x86_l_4b1:
	/* 0x4b1: mov    QWORD PTR [r12+0x6420],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 110088601731072ULL);
x86_l_4bd:
	/* 0x4bd: mov    QWORD PTR [r12+0x6428],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25640ULL);
x86_l_4c5:
	/* 0x4c5: jmp    685 <generic_uprobe_process_event+0x685> */
	goto x86_l_685;
x86_l_4ca:
	/* 0x4ca: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4cc:
	/* 0x4cc: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4d4:
	/* 0x4d4: add    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4d7:
	/* 0x4d7: mov    r13d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_32);
x86_l_4da:
	/* 0x4da: mov    r12,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_4e2:
	/* 0x4e2: mov    DWORD PTR [r14+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4e6:
	/* 0x4e6: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_4ea:
	/* 0x4ea: jg     55b <generic_uprobe_process_event+0x55b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_55b;
	}
x86_l_4ec:
	/* 0x4ec: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4f4:
	/* 0x4f4: mov    rdi,QWORD PTR [rip+0x217] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_4fb:
	/* 0x4fb: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_500:
	/* 0x500: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_505:
	/* 0x505: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_507:
	/* 0x507: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50a:
	/* 0x50a: je     55b <generic_uprobe_process_event+0x55b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55b;
	}
x86_l_50c:
	/* 0x50c: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_50f:
	/* 0x50f: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_516:
	/* 0x516: mov    rdi,QWORD PTR [rip+0x20d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_51d:
	/* 0x51d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_522:
	/* 0x522: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_524:
	/* 0x524: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_527:
	/* 0x527: je     55b <generic_uprobe_process_event+0x55b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55b;
	}
x86_l_529:
	/* 0x529: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_52c:
	/* 0x52c: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_52f:
	/* 0x52f: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_532:
	/* 0x532: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_537:
	/* 0x537: je     55b <generic_uprobe_process_event+0x55b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55b;
	}
x86_l_539:
	/* 0x539: mov    DWORD PTR [r14+0x5eec],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24300ULL);
x86_l_540:
	/* 0x540: mov    rsi,QWORD PTR [rip+0x217] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_547:
	/* 0x547: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_54c:
	/* 0x54c: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_551:
	/* 0x551: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_554:
	/* 0x554: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_559:
	/* 0x559: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55b:
	/* 0x55b: mov    DWORD PTR [r14+0x5eec],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104367705292800ULL);
x86_l_566:
	/* 0x566: mov    rsi,QWORD PTR [rip+0x217] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_56d:
	/* 0x56d: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_572:
	/* 0x572: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_577:
	/* 0x577: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_57a:
	/* 0x57a: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_57f:
	/* 0x57f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_581:
	/* 0x581: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_583:
	/* 0x583: add    rsp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_58a:
	/* 0x58a: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_58c:
	/* 0x58c: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_58d:
	/* 0x58d: jmp    2feb <generic_uprobe_process_event+0x2feb> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_592:
	/* 0x592: cmp    ebp,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 32ULL);
x86_l_595:
	/* 0x595: jle    6e0 <generic_uprobe_process_event+0x6e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6e0;
	}
x86_l_59b:
	/* 0x59b: cmp    ebp,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 38ULL);
x86_l_59e:
	/* 0x59e: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5a3:
	/* 0x5a3: jg     727 <generic_uprobe_process_event+0x727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1831ULL;
	}
x86_l_5a9:
	/* 0x5a9: lea    eax,[rbp-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_5ac:
	/* 0x5ac: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5af:
	/* 0x5af: jb     7ed <generic_uprobe_process_event+0x7ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2029ULL;
	}
x86_l_5b5:
	/* 0x5b5: cmp    ebp,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 37ULL);
x86_l_5b8:
	/* 0x5b8: je     9aa <generic_uprobe_process_event+0x9aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2474ULL;
	}
x86_l_5be:
	/* 0x5be: jmp    8d7 <generic_uprobe_process_event+0x8d7> */
	return 2263ULL;
x86_l_5c3:
	/* 0x5c3: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5c6:
	/* 0x5c6: jg     77e <generic_uprobe_process_event+0x77e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1918ULL;
	}
x86_l_5cc:
	/* 0x5cc: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5cf:
	/* 0x5cf: jg     81d <generic_uprobe_process_event+0x81d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2077ULL;
	}
x86_l_5d5:
	/* 0x5d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d7:
	/* 0x5d7: je     926 <generic_uprobe_process_event+0x926> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2342ULL;
	}
x86_l_5dd:
	/* 0x5dd: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5e0:
	/* 0x5e0: jne    283 <generic_uprobe_process_event+0x283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_283;
	}
x86_l_5e6:
	/* 0x5e6: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_5eb:
	/* 0x5eb: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5ee:
	/* 0x5ee: bzhi   r13,QWORD PTR [rbx+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 8ULL);
x86_l_5f4:
	/* 0x5f4: jmp    283 <generic_uprobe_process_event+0x283> */
	goto x86_l_283;
x86_l_5f9:
	/* 0x5f9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5fe:
	/* 0x5fe: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_603:
	/* 0x603: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_608:
	/* 0x608: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_60d:
	/* 0x60d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_612:
	/* 0x612: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_614:
	/* 0x614: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_619:
	/* 0x619: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_61c:
	/* 0x61c: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_624:
	/* 0x624: jne    68d <generic_uprobe_process_event+0x68d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_68d;
	}
x86_l_626:
	/* 0x626: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_628:
	/* 0x628: jmp    4d4 <generic_uprobe_process_event+0x4d4> */
	goto x86_l_4d4;
x86_l_62d:
	/* 0x62d: lea    r15,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_635:
	/* 0x635: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_63a:
	/* 0x63a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_63f:
	/* 0x63f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_644:
	/* 0x644: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_647:
	/* 0x647: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64c:
	/* 0x64c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64e:
	/* 0x64e: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_656:
	/* 0x656: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_65b:
	/* 0x65b: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_660:
	/* 0x660: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_665:
	/* 0x665: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_66a:
	/* 0x66a: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_672:
	/* 0x672: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_677:
	/* 0x677: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_679:
	/* 0x679: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_681:
	/* 0x681: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_685:
	/* 0x685: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_68d:
	/* 0x68d: mov    QWORD PTR [r12+0x6430],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25648ULL);
x86_l_695:
	/* 0x695: mov    rsi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_69c:
	/* 0x69c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6a1:
	/* 0x6a1: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_6a6:
	/* 0x6a6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6a9:
	/* 0x6a9: mov    edx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_6ae:
	/* 0x6ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b0:
	/* 0x6b0: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b2:
	/* 0x6b2: jmp    4d4 <generic_uprobe_process_event+0x4d4> */
	goto x86_l_4d4;
x86_l_6b7:
	/* 0x6b7: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_6ba:
	/* 0x6ba: jg     7ac <generic_uprobe_process_event+0x7ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1964ULL;
	}
x86_l_6c0:
	/* 0x6c0: lea    eax,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_6c3:
	/* 0x6c3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6c6:
	/* 0x6c6: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6cb:
	/* 0x6cb: jb     6ee <generic_uprobe_process_event+0x6ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6ee;
	}
x86_l_6cd:
	/* 0x6cd: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_6d0:
	/* 0x6d0: je     6ee <generic_uprobe_process_event+0x6ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6ee;
	}
x86_l_6d2:
	/* 0x6d2: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_6d5:
	/* 0x6d5: je     7ed <generic_uprobe_process_event+0x7ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2029ULL;
	}
x86_l_6db:
	/* 0x6db: jmp    8d7 <generic_uprobe_process_event+0x8d7> */
	return 2263ULL;
x86_l_6e0:
	/* 0x6e0: cmp    ebp,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_6e3:
	/* 0x6e3: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6e8:
	/* 0x6e8: jle    7d1 <generic_uprobe_process_event+0x7d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2001ULL;
	}
x86_l_6ee:
	/* 0x6ee: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_6f4:
	/* 0x6f4: jmp    9aa <generic_uprobe_process_event+0x9aa> */
	return 2474ULL;
x86_l_6f9:
	/* 0x6f9: cmp    ebp,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 19ULL);
x86_l_6fc:
	/* 0x6fc: jle    8ac <generic_uprobe_process_event+0x8ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2220ULL;
	}
x86_l_702:
	/* 0x702: cmp    ebp,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 20ULL);
x86_l_705:
	/* 0x705: je     99f <generic_uprobe_process_event+0x99f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2463ULL;
	}
x86_l_70b:
	/* 0x70b: cmp    ebp,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 21ULL);
x86_l_70e:
	/* 0x70e: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_713:
	/* 0x713: je     997 <generic_uprobe_process_event+0x997> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2455ULL;
	}
x86_l_719:
	/* 0x719: cmp    ebp,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 22ULL);
	return 1820ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1820ULL: goto x86_l_71c;
	case 1826ULL: goto x86_l_722;
	case 1831ULL: goto x86_l_727;
	case 1834ULL: goto x86_l_72a;
	case 1840ULL: goto x86_l_730;
	case 1843ULL: goto x86_l_733;
	case 1849ULL: goto x86_l_739;
	case 1852ULL: goto x86_l_73c;
	case 1858ULL: goto x86_l_742;
	case 1861ULL: goto x86_l_745;
	case 1867ULL: goto x86_l_74b;
	case 1872ULL: goto x86_l_750;
	case 1875ULL: goto x86_l_753;
	case 1881ULL: goto x86_l_759;
	case 1884ULL: goto x86_l_75c;
	case 1890ULL: goto x86_l_762;
	case 1893ULL: goto x86_l_765;
	case 1899ULL: goto x86_l_76b;
	case 1904ULL: goto x86_l_770;
	case 1907ULL: goto x86_l_773;
	case 1913ULL: goto x86_l_779;
	case 1918ULL: goto x86_l_77e;
	case 1921ULL: goto x86_l_781;
	case 1927ULL: goto x86_l_787;
	case 1930ULL: goto x86_l_78a;
	case 1936ULL: goto x86_l_790;
	case 1939ULL: goto x86_l_793;
	case 1945ULL: goto x86_l_799;
	case 1950ULL: goto x86_l_79e;
	case 1953ULL: goto x86_l_7a1;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1967ULL: goto x86_l_7af;
	case 1972ULL: goto x86_l_7b4;
	case 1978ULL: goto x86_l_7ba;
	case 1981ULL: goto x86_l_7bd;
	case 1987ULL: goto x86_l_7c3;
	case 1990ULL: goto x86_l_7c6;
	case 1996ULL: goto x86_l_7cc;
	case 2001ULL: goto x86_l_7d1;
	case 2004ULL: goto x86_l_7d4;
	case 2006ULL: goto x86_l_7d6;
	case 2009ULL: goto x86_l_7d9;
	case 2015ULL: goto x86_l_7df;
	case 2018ULL: goto x86_l_7e2;
	case 2024ULL: goto x86_l_7e8;
	case 2029ULL: goto x86_l_7ed;
	case 2035ULL: goto x86_l_7f3;
	case 2040ULL: goto x86_l_7f8;
	case 2043ULL: goto x86_l_7fb;
	case 2049ULL: goto x86_l_801;
	case 2052ULL: goto x86_l_804;
	case 2058ULL: goto x86_l_80a;
	case 2063ULL: goto x86_l_80f;
	case 2066ULL: goto x86_l_812;
	case 2072ULL: goto x86_l_818;
	case 2077ULL: goto x86_l_81d;
	case 2080ULL: goto x86_l_820;
	case 2086ULL: goto x86_l_826;
	case 2089ULL: goto x86_l_829;
	case 2095ULL: goto x86_l_82f;
	case 2100ULL: goto x86_l_834;
	case 2103ULL: goto x86_l_837;
	case 2109ULL: goto x86_l_83d;
	case 2114ULL: goto x86_l_842;
	case 2117ULL: goto x86_l_845;
	case 2123ULL: goto x86_l_84b;
	case 2126ULL: goto x86_l_84e;
	case 2132ULL: goto x86_l_854;
	case 2137ULL: goto x86_l_859;
	case 2140ULL: goto x86_l_85c;
	case 2146ULL: goto x86_l_862;
	case 2151ULL: goto x86_l_867;
	case 2154ULL: goto x86_l_86a;
	case 2160ULL: goto x86_l_870;
	case 2163ULL: goto x86_l_873;
	case 2169ULL: goto x86_l_879;
	case 2174ULL: goto x86_l_87e;
	case 2177ULL: goto x86_l_881;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2191ULL: goto x86_l_88f;
	case 2193ULL: goto x86_l_891;
	case 2196ULL: goto x86_l_894;
	case 2198ULL: goto x86_l_896;
	case 2204ULL: goto x86_l_89c;
	case 2209ULL: goto x86_l_8a1;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2223ULL: goto x86_l_8af;
	case 2226ULL: goto x86_l_8b2;
	case 2231ULL: goto x86_l_8b7;
	case 2237ULL: goto x86_l_8bd;
	case 2240ULL: goto x86_l_8c0;
	case 2242ULL: goto x86_l_8c2;
	case 2248ULL: goto x86_l_8c8;
	case 2253ULL: goto x86_l_8cd;
	case 2256ULL: goto x86_l_8d0;
	case 2258ULL: goto x86_l_8d2;
	case 2261ULL: goto x86_l_8d5;
	case 2263ULL: goto x86_l_8d7;
	case 2266ULL: goto x86_l_8da;
	case 2271ULL: goto x86_l_8df;
	case 2277ULL: goto x86_l_8e5;
	case 2282ULL: goto x86_l_8ea;
	case 2287ULL: goto x86_l_8ef;
	case 2290ULL: goto x86_l_8f2;
	case 2296ULL: goto x86_l_8f8;
	case 2301ULL: goto x86_l_8fd;
	case 2306ULL: goto x86_l_902;
	case 2309ULL: goto x86_l_905;
	case 2315ULL: goto x86_l_90b;
	case 2320ULL: goto x86_l_910;
	case 2325ULL: goto x86_l_915;
	case 2328ULL: goto x86_l_918;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2350ULL: goto x86_l_92e;
	case 2355ULL: goto x86_l_933;
	case 2360ULL: goto x86_l_938;
	case 2365ULL: goto x86_l_93d;
	case 2368ULL: goto x86_l_940;
	case 2374ULL: goto x86_l_946;
	case 2379ULL: goto x86_l_94b;
	case 2384ULL: goto x86_l_950;
	case 2387ULL: goto x86_l_953;
	case 2393ULL: goto x86_l_959;
	case 2398ULL: goto x86_l_95e;
	case 2403ULL: goto x86_l_963;
	case 2406ULL: goto x86_l_966;
	case 2412ULL: goto x86_l_96c;
	case 2417ULL: goto x86_l_971;
	case 2422ULL: goto x86_l_976;
	case 2425ULL: goto x86_l_979;
	case 2431ULL: goto x86_l_97f;
	case 2436ULL: goto x86_l_984;
	case 2441ULL: goto x86_l_989;
	case 2444ULL: goto x86_l_98c;
	case 2450ULL: goto x86_l_992;
	case 2455ULL: goto x86_l_997;
	case 2461ULL: goto x86_l_99d;
	case 2463ULL: goto x86_l_99f;
	case 2469ULL: goto x86_l_9a5;
	case 2474ULL: goto x86_l_9aa;
	case 2485ULL: goto x86_l_9b5;
	case 2492ULL: goto x86_l_9bc;
	case 2500ULL: goto x86_l_9c4;
	case 2505ULL: goto x86_l_9c9;
	case 2507ULL: goto x86_l_9cb;
	case 2509ULL: goto x86_l_9cd;
	case 2512ULL: goto x86_l_9d0;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2526ULL: goto x86_l_9de;
	case 2534ULL: goto x86_l_9e6;
	case 2540ULL: goto x86_l_9ec;
	case 2548ULL: goto x86_l_9f4;
	case 2556ULL: goto x86_l_9fc;
	case 2563ULL: goto x86_l_a03;
	case 2567ULL: goto x86_l_a07;
	case 2575ULL: goto x86_l_a0f;
	case 2580ULL: goto x86_l_a14;
	case 2582ULL: goto x86_l_a16;
	case 2588ULL: goto x86_l_a1c;
	case 2591ULL: goto x86_l_a1f;
	case 2598ULL: goto x86_l_a26;
	case 2601ULL: goto x86_l_a29;
	case 2606ULL: goto x86_l_a2e;
	case 2615ULL: goto x86_l_a37;
	case 2618ULL: goto x86_l_a3a;
	case 2626ULL: goto x86_l_a42;
	case 2628ULL: goto x86_l_a44;
	case 2631ULL: goto x86_l_a47;
	case 2633ULL: goto x86_l_a49;
	case 2636ULL: goto x86_l_a4c;
	case 2638ULL: goto x86_l_a4e;
	case 2641ULL: goto x86_l_a51;
	case 2646ULL: goto x86_l_a56;
	case 2649ULL: goto x86_l_a59;
	case 2655ULL: goto x86_l_a5f;
	case 2658ULL: goto x86_l_a62;
	case 2660ULL: goto x86_l_a64;
	case 2672ULL: goto x86_l_a70;
	case 2680ULL: goto x86_l_a78;
	case 2688ULL: goto x86_l_a80;
	case 2693ULL: goto x86_l_a85;
	case 2698ULL: goto x86_l_a8a;
	case 2703ULL: goto x86_l_a8f;
	case 2708ULL: goto x86_l_a94;
	case 2713ULL: goto x86_l_a99;
	case 2718ULL: goto x86_l_a9e;
	case 2720ULL: goto x86_l_aa0;
	case 2725ULL: goto x86_l_aa5;
	case 2730ULL: goto x86_l_aaa;
	case 2733ULL: goto x86_l_aad;
	case 2739ULL: goto x86_l_ab3;
	case 2743ULL: goto x86_l_ab7;
	case 2751ULL: goto x86_l_abf;
	case 2758ULL: goto x86_l_ac6;
	case 2763ULL: goto x86_l_acb;
	case 2768ULL: goto x86_l_ad0;
	case 2770ULL: goto x86_l_ad2;
	case 2773ULL: goto x86_l_ad5;
	case 2776ULL: goto x86_l_ad8;
	case 2782ULL: goto x86_l_ade;
	case 2785ULL: goto x86_l_ae1;
	case 2793ULL: goto x86_l_ae9;
	case 2799ULL: goto x86_l_aef;
	case 2802ULL: goto x86_l_af2;
	case 2808ULL: goto x86_l_af8;
	case 2811ULL: goto x86_l_afb;
	case 2817ULL: goto x86_l_b01;
	case 2822ULL: goto x86_l_b06;
	case 2825ULL: goto x86_l_b09;
	case 2831ULL: goto x86_l_b0f;
	case 2834ULL: goto x86_l_b12;
	case 2840ULL: goto x86_l_b18;
	case 2843ULL: goto x86_l_b1b;
	case 2851ULL: goto x86_l_b23;
	case 2856ULL: goto x86_l_b28;
	case 2861ULL: goto x86_l_b2d;
	case 2864ULL: goto x86_l_b30;
	case 2869ULL: goto x86_l_b35;
	case 2874ULL: goto x86_l_b3a;
	case 2879ULL: goto x86_l_b3f;
	case 2882ULL: goto x86_l_b42;
	case 2887ULL: goto x86_l_b47;
	case 2889ULL: goto x86_l_b49;
	case 2893ULL: goto x86_l_b4d;
	case 2898ULL: goto x86_l_b52;
	case 2903ULL: goto x86_l_b57;
	case 2908ULL: goto x86_l_b5c;
	case 2913ULL: goto x86_l_b61;
	case 2916ULL: goto x86_l_b64;
	case 2921ULL: goto x86_l_b69;
	case 2923ULL: goto x86_l_b6b;
	case 2927ULL: goto x86_l_b6f;
	case 2931ULL: goto x86_l_b73;
	case 2936ULL: goto x86_l_b78;
	case 2947ULL: goto x86_l_b83;
	case 2954ULL: goto x86_l_b8a;
	case 2962ULL: goto x86_l_b92;
	case 2967ULL: goto x86_l_b97;
	case 2969ULL: goto x86_l_b99;
	case 2972ULL: goto x86_l_b9c;
	case 2978ULL: goto x86_l_ba2;
	case 2981ULL: goto x86_l_ba5;
	case 2986ULL: goto x86_l_baa;
	case 2992ULL: goto x86_l_bb0;
	case 3000ULL: goto x86_l_bb8;
	case 3005ULL: goto x86_l_bbd;
	case 3007ULL: goto x86_l_bbf;
	case 3014ULL: goto x86_l_bc6;
	case 3022ULL: goto x86_l_bce;
	case 3027ULL: goto x86_l_bd3;
	case 3032ULL: goto x86_l_bd8;
	case 3037ULL: goto x86_l_bdd;
	case 3039ULL: goto x86_l_bdf;
	case 3047ULL: goto x86_l_be7;
	case 3052ULL: goto x86_l_bec;
	case 3056ULL: goto x86_l_bf0;
	case 3064ULL: goto x86_l_bf8;
	case 3069ULL: goto x86_l_bfd;
	case 3074ULL: goto x86_l_c02;
	case 3079ULL: goto x86_l_c07;
	case 3087ULL: goto x86_l_c0f;
	case 3092ULL: goto x86_l_c14;
	case 3100ULL: goto x86_l_c1c;
	case 3102ULL: goto x86_l_c1e;
	case 3110ULL: goto x86_l_c26;
	case 3114ULL: goto x86_l_c2a;
	case 3119ULL: goto x86_l_c2f;
	case 3124ULL: goto x86_l_c34;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3136ULL: goto x86_l_c40;
	case 3142ULL: goto x86_l_c46;
	case 3147ULL: goto x86_l_c4b;
	case 3149ULL: goto x86_l_c4d;
	case 3157ULL: goto x86_l_c55;
	case 3159ULL: goto x86_l_c57;
	case 3163ULL: goto x86_l_c5b;
	case 3168ULL: goto x86_l_c60;
	case 3173ULL: goto x86_l_c65;
	case 3178ULL: goto x86_l_c6a;
	case 3183ULL: goto x86_l_c6f;
	case 3185ULL: goto x86_l_c71;
	case 3190ULL: goto x86_l_c76;
	case 3198ULL: goto x86_l_c7e;
	case 3200ULL: goto x86_l_c80;
	case 3203ULL: goto x86_l_c83;
	case 3210ULL: goto x86_l_c8a;
	case 3220ULL: goto x86_l_c94;
	case 3227ULL: goto x86_l_c9b;
	case 3237ULL: goto x86_l_ca5;
	case 3242ULL: goto x86_l_caa;
	case 3251ULL: goto x86_l_cb3;
	case 3260ULL: goto x86_l_cbc;
	case 3265ULL: goto x86_l_cc1;
	case 3274ULL: goto x86_l_cca;
	case 3283ULL: goto x86_l_cd3;
	case 3292ULL: goto x86_l_cdc;
	case 3300ULL: goto x86_l_ce4;
	case 3305ULL: goto x86_l_ce9;
	case 3309ULL: goto x86_l_ced;
	case 3314ULL: goto x86_l_cf2;
	case 3318ULL: goto x86_l_cf6;
	case 3323ULL: goto x86_l_cfb;
	case 3328ULL: goto x86_l_d00;
	case 3333ULL: goto x86_l_d05;
	case 3338ULL: goto x86_l_d0a;
	case 3343ULL: goto x86_l_d0f;
	case 3348ULL: goto x86_l_d14;
	case 3353ULL: goto x86_l_d19;
	case 3356ULL: goto x86_l_d1c;
	case 3358ULL: goto x86_l_d1e;
	case 3363ULL: goto x86_l_d23;
	case 3368ULL: goto x86_l_d28;
	case 3376ULL: goto x86_l_d30;
	case 3379ULL: goto x86_l_d33;
	case 3384ULL: goto x86_l_d38;
	case 3386ULL: goto x86_l_d3a;
	case 3391ULL: goto x86_l_d3f;
	case 3396ULL: goto x86_l_d44;
	case 3404ULL: goto x86_l_d4c;
	case 3407ULL: goto x86_l_d4f;
	case 3412ULL: goto x86_l_d54;
	case 3414ULL: goto x86_l_d56;
	case 3419ULL: goto x86_l_d5b;
	case 3424ULL: goto x86_l_d60;
	case 3429ULL: goto x86_l_d65;
	case 3432ULL: goto x86_l_d68;
	case 3437ULL: goto x86_l_d6d;
	case 3439ULL: goto x86_l_d6f;
	case 3444ULL: goto x86_l_d74;
	case 3449ULL: goto x86_l_d79;
	case 3454ULL: goto x86_l_d7e;
	case 3459ULL: goto x86_l_d83;
	case 3464ULL: goto x86_l_d88;
	case 3466ULL: goto x86_l_d8a;
	case 3471ULL: goto x86_l_d8f;
	case 3473ULL: goto x86_l_d91;
	case 3478ULL: goto x86_l_d96;
	case 3483ULL: goto x86_l_d9b;
	case 3491ULL: goto x86_l_da3;
	case 3494ULL: goto x86_l_da6;
	case 3499ULL: goto x86_l_dab;
	case 3504ULL: goto x86_l_db0;
	case 3510ULL: goto x86_l_db6;
	case 3512ULL: goto x86_l_db8;
	case 3517ULL: goto x86_l_dbd;
	case 3520ULL: goto x86_l_dc0;
	case 3524ULL: goto x86_l_dc4;
	case 3530ULL: goto x86_l_dca;
	case 3533ULL: goto x86_l_dcd;
	case 3535ULL: goto x86_l_dcf;
	case 3539ULL: goto x86_l_dd3;
	case 3542ULL: goto x86_l_dd6;
	case 3544ULL: goto x86_l_dd8;
	case 3547ULL: goto x86_l_ddb;
	case 3549ULL: goto x86_l_ddd;
	case 3552ULL: goto x86_l_de0;
	case 3557ULL: goto x86_l_de5;
	case 3560ULL: goto x86_l_de8;
	case 3565ULL: goto x86_l_ded;
	case 3570ULL: goto x86_l_df2;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3585ULL: goto x86_l_e01;
	case 3588ULL: goto x86_l_e04;
	case 3590ULL: goto x86_l_e06;
	case 3595ULL: goto x86_l_e0b;
	case 3601ULL: goto x86_l_e11;
	case 3605ULL: goto x86_l_e15;
	case 3608ULL: goto x86_l_e18;
	case 3613ULL: goto x86_l_e1d;
	case 3618ULL: goto x86_l_e22;
	case 3623ULL: goto x86_l_e27;
	case 3626ULL: goto x86_l_e2a;
	case 3628ULL: goto x86_l_e2c;
	case 3632ULL: goto x86_l_e30;
	case 3638ULL: goto x86_l_e36;
	case 3643ULL: goto x86_l_e3b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_71c:
	/* 0x71c: je     8df <generic_uprobe_process_event+0x8df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8df;
	}
x86_l_722:
	/* 0x722: jmp    8d7 <generic_uprobe_process_event+0x8d7> */
	goto x86_l_8d7;
x86_l_727:
	/* 0x727: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_72a:
	/* 0x72a: jle    8cd <generic_uprobe_process_event+0x8cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_8cd;
	}
x86_l_730:
	/* 0x730: cmp    ebp,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 41ULL);
x86_l_733:
	/* 0x733: je     8a1 <generic_uprobe_process_event+0x8a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8a1;
	}
x86_l_739:
	/* 0x739: cmp    ebp,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 42ULL);
x86_l_73c:
	/* 0x73c: je     9aa <generic_uprobe_process_event+0x9aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9aa;
	}
x86_l_742:
	/* 0x742: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_745:
	/* 0x745: je     8c2 <generic_uprobe_process_event+0x8c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8c2;
	}
x86_l_74b:
	/* 0x74b: jmp    8d7 <generic_uprobe_process_event+0x8d7> */
	goto x86_l_8d7;
x86_l_750:
	/* 0x750: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_753:
	/* 0x753: jg     7f8 <generic_uprobe_process_event+0x7f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_7f8;
	}
x86_l_759:
	/* 0x759: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_75c:
	/* 0x75c: je     8ea <generic_uprobe_process_event+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ea;
	}
x86_l_762:
	/* 0x762: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_765:
	/* 0x765: jne    283 <generic_uprobe_process_event+0x283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 643ULL;
	}
x86_l_76b:
	/* 0x76b: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_770:
	/* 0x770: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_773:
	/* 0x773: bzhi   r13,QWORD PTR [rbx+0x48],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 72ULL);
x86_l_779:
	/* 0x779: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_77e:
	/* 0x77e: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_781:
	/* 0x781: jg     842 <generic_uprobe_process_event+0x842> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_842;
	}
x86_l_787:
	/* 0x787: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_78a:
	/* 0x78a: je     938 <generic_uprobe_process_event+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_938;
	}
x86_l_790:
	/* 0x790: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_793:
	/* 0x793: jne    283 <generic_uprobe_process_event+0x283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 643ULL;
	}
x86_l_799:
	/* 0x799: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_79e:
	/* 0x79e: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7a1:
	/* 0x7a1: bzhi   r13,QWORD PTR [rbx+0x28],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 40ULL);
x86_l_7a7:
	/* 0x7a7: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_7ac:
	/* 0x7ac: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_7af:
	/* 0x7af: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7b4:
	/* 0x7b4: jg     88c <generic_uprobe_process_event+0x88c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_88c;
	}
x86_l_7ba:
	/* 0x7ba: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_7bd:
	/* 0x7bd: je     8a1 <generic_uprobe_process_event+0x8a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8a1;
	}
x86_l_7c3:
	/* 0x7c3: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_7c6:
	/* 0x7c6: je     9aa <generic_uprobe_process_event+0x9aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9aa;
	}
x86_l_7cc:
	/* 0x7cc: jmp    8d7 <generic_uprobe_process_event+0x8d7> */
	goto x86_l_8d7;
x86_l_7d1:
	/* 0x7d1: cmp    ebp,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 23ULL);
x86_l_7d4:
	/* 0x7d4: je     7ed <generic_uprobe_process_event+0x7ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7ed;
	}
x86_l_7d6:
	/* 0x7d6: cmp    ebp,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 26ULL);
x86_l_7d9:
	/* 0x7d9: je     896 <generic_uprobe_process_event+0x896> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_896;
	}
x86_l_7df:
	/* 0x7df: cmp    ebp,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 27ULL);
x86_l_7e2:
	/* 0x7e2: je     896 <generic_uprobe_process_event+0x896> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_896;
	}
x86_l_7e8:
	/* 0x7e8: jmp    8d7 <generic_uprobe_process_event+0x8d7> */
	goto x86_l_8d7;
x86_l_7ed:
	/* 0x7ed: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_7f3:
	/* 0x7f3: jmp    9aa <generic_uprobe_process_event+0x9aa> */
	goto x86_l_9aa;
x86_l_7f8:
	/* 0x7f8: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_7fb:
	/* 0x7fb: je     8fd <generic_uprobe_process_event+0x8fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8fd;
	}
x86_l_801:
	/* 0x801: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_804:
	/* 0x804: jne    283 <generic_uprobe_process_event+0x283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 643ULL;
	}
x86_l_80a:
	/* 0x80a: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_80f:
	/* 0x80f: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_812:
	/* 0x812: bzhi   r13,QWORD PTR [rbx+0x58],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 88ULL);
x86_l_818:
	/* 0x818: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_81d:
	/* 0x81d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_820:
	/* 0x820: je     94b <generic_uprobe_process_event+0x94b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_94b;
	}
x86_l_826:
	/* 0x826: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_829:
	/* 0x829: jne    283 <generic_uprobe_process_event+0x283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 643ULL;
	}
x86_l_82f:
	/* 0x82f: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_834:
	/* 0x834: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_837:
	/* 0x837: bzhi   r13,QWORD PTR [rbx+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 24ULL);
x86_l_83d:
	/* 0x83d: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_842:
	/* 0x842: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_845:
	/* 0x845: je     95e <generic_uprobe_process_event+0x95e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_95e;
	}
x86_l_84b:
	/* 0x84b: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_84e:
	/* 0x84e: jne    283 <generic_uprobe_process_event+0x283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 643ULL;
	}
x86_l_854:
	/* 0x854: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_859:
	/* 0x859: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_85c:
	/* 0x85c: bzhi   r13,QWORD PTR [rbx+0x38],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 56ULL);
x86_l_862:
	/* 0x862: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_867:
	/* 0x867: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_86a:
	/* 0x86a: je     984 <generic_uprobe_process_event+0x984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_984;
	}
x86_l_870:
	/* 0x870: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_873:
	/* 0x873: jne    283 <generic_uprobe_process_event+0x283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 643ULL;
	}
x86_l_879:
	/* 0x879: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_87e:
	/* 0x87e: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_881:
	/* 0x881: bzhi   r13,QWORD PTR [rbx+0x68],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 104ULL);
x86_l_887:
	/* 0x887: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_88c:
	/* 0x88c: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_88f:
	/* 0x88f: je     8a1 <generic_uprobe_process_event+0x8a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8a1;
	}
x86_l_891:
	/* 0x891: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_894:
	/* 0x894: jne    8d7 <generic_uprobe_process_event+0x8d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8d7;
	}
x86_l_896:
	/* 0x896: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_89c:
	/* 0x89c: jmp    9aa <generic_uprobe_process_event+0x9aa> */
	goto x86_l_9aa;
x86_l_8a1:
	/* 0x8a1: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_8a7:
	/* 0x8a7: jmp    9aa <generic_uprobe_process_event+0x9aa> */
	goto x86_l_9aa;
x86_l_8ac:
	/* 0x8ac: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_8af:
	/* 0x8af: cmp    ebp,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 18ULL);
x86_l_8b2:
	/* 0x8b2: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8b7:
	/* 0x8b7: je     9aa <generic_uprobe_process_event+0x9aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9aa;
	}
x86_l_8bd:
	/* 0x8bd: cmp    ebp,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 19ULL);
x86_l_8c0:
	/* 0x8c0: jne    8d7 <generic_uprobe_process_event+0x8d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8d7;
	}
x86_l_8c2:
	/* 0x8c2: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_8c8:
	/* 0x8c8: jmp    9aa <generic_uprobe_process_event+0x9aa> */
	goto x86_l_9aa;
x86_l_8cd:
	/* 0x8cd: cmp    ebp,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 39ULL);
x86_l_8d0:
	/* 0x8d0: je     8df <generic_uprobe_process_event+0x8df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8df;
	}
x86_l_8d2:
	/* 0x8d2: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_8d5:
	/* 0x8d5: je     8c2 <generic_uprobe_process_event+0x8c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8c2;
	}
x86_l_8d7:
	/* 0x8d7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8da:
	/* 0x8da: jmp    9aa <generic_uprobe_process_event+0x9aa> */
	goto x86_l_9aa;
x86_l_8df:
	/* 0x8df: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_8e5:
	/* 0x8e5: jmp    9aa <generic_uprobe_process_event+0x9aa> */
	goto x86_l_9aa;
x86_l_8ea:
	/* 0x8ea: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_8ef:
	/* 0x8ef: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_8f2:
	/* 0x8f2: bzhi   r13,QWORD PTR [rbx+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 64ULL);
x86_l_8f8:
	/* 0x8f8: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_8fd:
	/* 0x8fd: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_902:
	/* 0x902: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_905:
	/* 0x905: bzhi   r13,QWORD PTR [rbx+0x50],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 80ULL);
x86_l_90b:
	/* 0x90b: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_910:
	/* 0x910: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_915:
	/* 0x915: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_918:
	/* 0x918: bzhi   r13,QWORD PTR [rbx+0x80],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 128ULL);
x86_l_921:
	/* 0x921: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_926:
	/* 0x926: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_92b:
	/* 0x92b: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_92e:
	/* 0x92e: bzhi   r13,QWORD PTR [rbx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_933:
	/* 0x933: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_938:
	/* 0x938: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_93d:
	/* 0x93d: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_940:
	/* 0x940: bzhi   r13,QWORD PTR [rbx+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 32ULL);
x86_l_946:
	/* 0x946: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_94b:
	/* 0x94b: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_950:
	/* 0x950: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_953:
	/* 0x953: bzhi   r13,QWORD PTR [rbx+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 16ULL);
x86_l_959:
	/* 0x959: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_95e:
	/* 0x95e: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_963:
	/* 0x963: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_966:
	/* 0x966: bzhi   r13,QWORD PTR [rbx+0x30],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 48ULL);
x86_l_96c:
	/* 0x96c: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_971:
	/* 0x971: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_976:
	/* 0x976: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_979:
	/* 0x979: bzhi   r13,QWORD PTR [rbx+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 112ULL);
x86_l_97f:
	/* 0x97f: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_984:
	/* 0x984: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_989:
	/* 0x989: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_98c:
	/* 0x98c: bzhi   r13,QWORD PTR [rbx+0x60],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 96ULL);
x86_l_992:
	/* 0x992: jmp    283 <generic_uprobe_process_event+0x283> */
	return 643ULL;
x86_l_997:
	/* 0x997: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_99d:
	/* 0x99d: jmp    9aa <generic_uprobe_process_event+0x9aa> */
	goto x86_l_9aa;
x86_l_99f:
	/* 0x99f: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_9a5:
	/* 0x9a5: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9aa:
	/* 0x9aa: mov    DWORD PTR [rsp+0xcc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_9b5:
	/* 0x9b5: mov    rdi,QWORD PTR [rip+0x21a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_9bc:
	/* 0x9bc: lea    rsi,[rsp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_9c4:
	/* 0x9c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9c9:
	/* 0x9c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9cb:
	/* 0x9cb: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9cd:
	/* 0x9cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9d0:
	/* 0x9d0: je     4cc <generic_uprobe_process_event+0x4cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1228ULL;
	}
x86_l_9d6:
	/* 0x9d6: mov    ecx,0x3ffb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16379ULL);
x86_l_9db:
	/* 0x9db: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_9de:
	/* 0x9de: cmp    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 144ULL);
x86_l_9e6:
	/* 0x9e6: jbe    4cc <generic_uprobe_process_event+0x4cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1228ULL;
	}
x86_l_9ec:
	/* 0x9ec: mov    edx,DWORD PTR [rax+r12*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 24224ULL);
x86_l_9f4:
	/* 0x9f4: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9fc:
	/* 0x9fc: mov    DWORD PTR [rax+rcx*1+0x90],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_a03:
	/* 0xa03: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a07:
	/* 0xa07: mov    QWORD PTR [rax+r12*8+0x5e78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_a0f:
	/* 0xa0f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a14:
	/* 0xa14: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_a16:
	/* 0xa16: jne    4cc <generic_uprobe_process_event+0x4cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1228ULL;
	}
x86_l_a1c:
	/* 0xa1c: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_a1f:
	/* 0xa1f: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_a26:
	/* 0xa26: add    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a29:
	/* 0xa29: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a2e:
	/* 0xa2e: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_a37:
	/* 0xa37: cmp    ebp,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 23ULL);
x86_l_a3a:
	/* 0xa3a: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a42:
	/* 0xa42: jg     a56 <generic_uprobe_process_event+0xa56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a56;
	}
x86_l_a44:
	/* 0xa44: cmp    ebp,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 15ULL);
x86_l_a47:
	/* 0xa47: je     a85 <generic_uprobe_process_event+0xa85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a85;
	}
x86_l_a49:
	/* 0xa49: cmp    ebp,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_a4c:
	/* 0xa4c: jne    ab3 <generic_uprobe_process_event+0xab3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ab3;
	}
x86_l_a4e:
	/* 0xa4e: mov    r12,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSP, X86_WIDTH_64);
x86_l_a51:
	/* 0xa51: jmp    b52 <generic_uprobe_process_event+0xb52> */
	goto x86_l_b52;
x86_l_a56:
	/* 0xa56: cmp    ebp,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_a59:
	/* 0xa59: je     b2d <generic_uprobe_process_event+0xb2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b2d;
	}
x86_l_a5f:
	/* 0xa5f: cmp    ebp,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 42ULL);
x86_l_a62:
	/* 0xa62: jne    ab3 <generic_uprobe_process_event+0xab3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ab3;
	}
x86_l_a64:
	/* 0xa64: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_a70:
	/* 0xa70: mov    QWORD PTR [rsp+0xa8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a78:
	/* 0xa78: lea    rax,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a80:
	/* 0xa80: jmp    b73 <generic_uprobe_process_event+0xb73> */
	goto x86_l_b73;
x86_l_a85:
	/* 0xa85: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a8a:
	/* 0xa8a: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a8f:
	/* 0xa8f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a94:
	/* 0xa94: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a99:
	/* 0xa99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a9e:
	/* 0xa9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa0:
	/* 0xaa0: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_aa5:
	/* 0xaa5: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aaa:
	/* 0xaaa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aad:
	/* 0xaad: jne    b78 <generic_uprobe_process_event+0xb78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b78;
	}
x86_l_ab3:
	/* 0xab3: mov    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab7:
	/* 0xab7: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_abf:
	/* 0xabf: mov    rdi,QWORD PTR [rip+0x21a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_ac6:
	/* 0xac6: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_acb:
	/* 0xacb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ad0:
	/* 0xad0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad2:
	/* 0xad2: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ad5:
	/* 0xad5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ad8:
	/* 0xad8: je     fa3 <generic_uprobe_process_event+0xfa3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4003ULL;
	}
x86_l_ade:
	/* 0xade: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_ae1:
	/* 0xae1: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ae9:
	/* 0xae9: jle    1173 <generic_uprobe_process_event+0x1173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4467ULL;
	}
x86_l_aef:
	/* 0xaef: cmp    ebp,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 30ULL);
x86_l_af2:
	/* 0xaf2: jg     12cc <generic_uprobe_process_event+0x12cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4812ULL;
	}
x86_l_af8:
	/* 0xaf8: cmp    ebp,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_afb:
	/* 0xafb: jg     154a <generic_uprobe_process_event+0x154a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5450ULL;
	}
x86_l_b01:
	/* 0xb01: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b06:
	/* 0xb06: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_b09:
	/* 0xb09: je     1903 <generic_uprobe_process_event+0x1903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6403ULL;
	}
x86_l_b0f:
	/* 0xb0f: cmp    ebp,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 17ULL);
x86_l_b12:
	/* 0xb12: je     1847 <generic_uprobe_process_event+0x1847> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6215ULL;
	}
x86_l_b18:
	/* 0xb18: cmp    ebp,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_b1b:
	/* 0xb1b: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b23:
	/* 0xb23: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b28:
	/* 0xb28: jmp    132d <generic_uprobe_process_event+0x132d> */
	return 4909ULL;
x86_l_b2d:
	/* 0xb2d: mov    r12,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSP, X86_WIDTH_64);
x86_l_b30:
	/* 0xb30: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b35:
	/* 0xb35: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b3a:
	/* 0xb3a: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b3f:
	/* 0xb3f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_b42:
	/* 0xb42: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b47:
	/* 0xb47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b49:
	/* 0xb49: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b4d:
	/* 0xb4d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b52:
	/* 0xb52: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b57:
	/* 0xb57: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b5c:
	/* 0xb5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b61:
	/* 0xb61: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b64:
	/* 0xb64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b69:
	/* 0xb69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b6b:
	/* 0xb6b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b6f:
	/* 0xb6f: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_b73:
	/* 0xb73: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b78:
	/* 0xb78: mov    DWORD PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_b83:
	/* 0xb83: mov    rdi,QWORD PTR [rip+0x21a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_b8a:
	/* 0xb8a: lea    rsi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_b92:
	/* 0xb92: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b97:
	/* 0xb97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b99:
	/* 0xb99: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b9c:
	/* 0xb9c: je     de5 <generic_uprobe_process_event+0xde5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_de5;
	}
x86_l_ba2:
	/* 0xba2: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_ba5:
	/* 0xba5: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_baa:
	/* 0xbaa: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_bb0:
	/* 0xbb0: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_bb8:
	/* 0xbb8: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_bbd:
	/* 0xbbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbf:
	/* 0xbbf: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_bc6:
	/* 0xbc6: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bce:
	/* 0xbce: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bd3:
	/* 0xbd3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bd8:
	/* 0xbd8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bdd:
	/* 0xbdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bdf:
	/* 0xbdf: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_be7:
	/* 0xbe7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bec:
	/* 0xbec: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bf0:
	/* 0xbf0: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_bf8:
	/* 0xbf8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bfd:
	/* 0xbfd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c02:
	/* 0xc02: lea    rcx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c07:
	/* 0xc07: mov    QWORD PTR [rsp+0xd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_c0f:
	/* 0xc0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c14:
	/* 0xc14: mov    QWORD PTR [rsp+0xd0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_c1c:
	/* 0xc1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1e:
	/* 0xc1e: mov    r15,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_c26:
	/* 0xc26: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c2a:
	/* 0xc2a: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c2f:
	/* 0xc2f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c34:
	/* 0xc34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c39:
	/* 0xc39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c3e:
	/* 0xc3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c40:
	/* 0xc40: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_c46:
	/* 0xc46: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_c4b:
	/* 0xc4b: je     c57 <generic_uprobe_process_event+0xc57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c57;
	}
x86_l_c4d:
	/* 0xc4d: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c55:
	/* 0xc55: jmp    caa <generic_uprobe_process_event+0xcaa> */
	goto x86_l_caa;
x86_l_c57:
	/* 0xc57: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c5b:
	/* 0xc5b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c60:
	/* 0xc60: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c65:
	/* 0xc65: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c6a:
	/* 0xc6a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c6f:
	/* 0xc6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c71:
	/* 0xc71: cmp    QWORD PTR [rsp+0x28],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c76:
	/* 0xc76: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c7e:
	/* 0xc7e: je     caa <generic_uprobe_process_event+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_caa;
	}
x86_l_c80:
	/* 0xc80: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_c83:
	/* 0xc83: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_c8a:
	/* 0xc8a: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_c94:
	/* 0xc94: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_c9b:
	/* 0xc9b: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_ca5:
	/* 0xca5: mov    ebp,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4086ULL);
x86_l_caa:
	/* 0xcaa: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_cb3:
	/* 0xcb3: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_cbc:
	/* 0xcbc: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cc1:
	/* 0xcc1: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_cca:
	/* 0xcca: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_cd3:
	/* 0xcd3: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_cdc:
	/* 0xcdc: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ce4:
	/* 0xce4: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ce9:
	/* 0xce9: mov    DWORD PTR [rsp+0x60],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ced:
	/* 0xced: mov    BYTE PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_cf2:
	/* 0xcf2: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_cf6:
	/* 0xcf6: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cfb:
	/* 0xcfb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d00:
	/* 0xd00: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d05:
	/* 0xd05: lea    r13,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d0a:
	/* 0xd0a: lea    r15,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d0f:
	/* 0xd0f: lea    rbp,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d14:
	/* 0xd14: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d19:
	/* 0xd19: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d1c:
	/* 0xd1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1e:
	/* 0xd1e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d23:
	/* 0xd23: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d28:
	/* 0xd28: mov    rdx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_d30:
	/* 0xd30: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_d33:
	/* 0xd33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d38:
	/* 0xd38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d3a:
	/* 0xd3a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d3f:
	/* 0xd3f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d44:
	/* 0xd44: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_d4c:
	/* 0xd4c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_d4f:
	/* 0xd4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d54:
	/* 0xd54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d56:
	/* 0xd56: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d5b:
	/* 0xd5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d60:
	/* 0xd60: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d65:
	/* 0xd65: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_d68:
	/* 0xd68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d6d:
	/* 0xd6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d6f:
	/* 0xd6f: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d74:
	/* 0xd74: lea    rax,[r12-0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551584ULL);
x86_l_d79:
	/* 0xd79: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d7e:
	/* 0xd7e: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d83:
	/* 0xd83: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_d88:
	/* 0xd88: jne    ded <generic_uprobe_process_event+0xded> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ded;
	}
x86_l_d8a:
	/* 0xd8a: cmp    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_d8f:
	/* 0xd8f: jne    ded <generic_uprobe_process_event+0xded> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ded;
	}
x86_l_d91:
	/* 0xd91: mov    BYTE PTR [rsp+0x64],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729601ULL);
x86_l_d96:
	/* 0xd96: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d9b:
	/* 0xd9b: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_da3:
	/* 0xda3: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_da6:
	/* 0xda6: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_dab:
	/* 0xdab: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db0:
	/* 0xdb0: je     f0f <generic_uprobe_process_event+0xf0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3855ULL;
	}
x86_l_db6:
	/* 0xdb6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_db8:
	/* 0xdb8: cmp    BYTE PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_dbd:
	/* 0xdbd: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_dc0:
	/* 0xdc0: mov    edx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_dc4:
	/* 0xdc4: mov    r13d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4096ULL);
x86_l_dca:
	/* 0xdca: sub    r13d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_dcd:
	/* 0xdcd: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_dcf:
	/* 0xdcf: cmovle r13d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_dd3:
	/* 0xdd3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dd6:
	/* 0xdd6: je     de5 <generic_uprobe_process_event+0xde5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_de5;
	}
x86_l_dd8:
	/* 0xdd8: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_ddb:
	/* 0xddb: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ddd:
	/* 0xddd: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_de0:
	/* 0xde0: jmp    f14 <generic_uprobe_process_event+0xf14> */
	return 3860ULL;
x86_l_de5:
	/* 0xde5: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_de8:
	/* 0xde8: jmp    fb5 <generic_uprobe_process_event+0xfb5> */
	return 4021ULL;
x86_l_ded:
	/* 0xded: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_df2:
	/* 0xdf2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_df7:
	/* 0xdf7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dfc:
	/* 0xdfc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e01:
	/* 0xe01: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e04:
	/* 0xe04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e06:
	/* 0xe06: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_e0b:
	/* 0xe0b: je     fec <generic_uprobe_process_event+0xfec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4076ULL;
	}
x86_l_e11:
	/* 0xe11: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e15:
	/* 0xe15: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_e18:
	/* 0xe18: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e1d:
	/* 0xe1d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e22:
	/* 0xe22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e27:
	/* 0xe27: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_e2a:
	/* 0xe2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2c:
	/* 0xe2c: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e30:
	/* 0xe30: je     fec <generic_uprobe_process_event+0xfec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4076ULL;
	}
x86_l_e36:
	/* 0xe36: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e3b:
	/* 0xe3b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
	return 3648ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3648ULL: goto x86_l_e40;
	case 3653ULL: goto x86_l_e45;
	case 3658ULL: goto x86_l_e4a;
	case 3661ULL: goto x86_l_e4d;
	case 3663ULL: goto x86_l_e4f;
	case 3667ULL: goto x86_l_e53;
	case 3672ULL: goto x86_l_e58;
	case 3677ULL: goto x86_l_e5d;
	case 3682ULL: goto x86_l_e62;
	case 3687ULL: goto x86_l_e67;
	case 3690ULL: goto x86_l_e6a;
	case 3692ULL: goto x86_l_e6c;
	case 3697ULL: goto x86_l_e71;
	case 3702ULL: goto x86_l_e76;
	case 3706ULL: goto x86_l_e7a;
	case 3709ULL: goto x86_l_e7d;
	case 3714ULL: goto x86_l_e82;
	case 3716ULL: goto x86_l_e84;
	case 3718ULL: goto x86_l_e86;
	case 3721ULL: goto x86_l_e89;
	case 3724ULL: goto x86_l_e8c;
	case 3729ULL: goto x86_l_e91;
	case 3731ULL: goto x86_l_e93;
	case 3734ULL: goto x86_l_e96;
	case 3738ULL: goto x86_l_e9a;
	case 3740ULL: goto x86_l_e9c;
	case 3744ULL: goto x86_l_ea0;
	case 3746ULL: goto x86_l_ea2;
	case 3749ULL: goto x86_l_ea5;
	case 3751ULL: goto x86_l_ea7;
	case 3755ULL: goto x86_l_eab;
	case 3758ULL: goto x86_l_eae;
	case 3764ULL: goto x86_l_eb4;
	case 3770ULL: goto x86_l_eba;
	case 3776ULL: goto x86_l_ec0;
	case 3779ULL: goto x86_l_ec3;
	case 3781ULL: goto x86_l_ec5;
	case 3786ULL: goto x86_l_eca;
	case 3788ULL: goto x86_l_ecc;
	case 3791ULL: goto x86_l_ecf;
	case 3795ULL: goto x86_l_ed3;
	case 3798ULL: goto x86_l_ed6;
	case 3801ULL: goto x86_l_ed9;
	case 3804ULL: goto x86_l_edc;
	case 3809ULL: goto x86_l_ee1;
	case 3811ULL: goto x86_l_ee3;
	case 3816ULL: goto x86_l_ee8;
	case 3819ULL: goto x86_l_eeb;
	case 3825ULL: goto x86_l_ef1;
	case 3830ULL: goto x86_l_ef6;
	case 3835ULL: goto x86_l_efb;
	case 3840ULL: goto x86_l_f00;
	case 3845ULL: goto x86_l_f05;
	case 3850ULL: goto x86_l_f0a;
	case 3855ULL: goto x86_l_f0f;
	case 3857ULL: goto x86_l_f11;
	case 3860ULL: goto x86_l_f14;
	case 3864ULL: goto x86_l_f18;
	case 3871ULL: goto x86_l_f1f;
	case 3876ULL: goto x86_l_f24;
	case 3879ULL: goto x86_l_f27;
	case 3881ULL: goto x86_l_f29;
	case 3884ULL: goto x86_l_f2c;
	case 3889ULL: goto x86_l_f31;
	case 3894ULL: goto x86_l_f36;
	case 3899ULL: goto x86_l_f3b;
	case 3907ULL: goto x86_l_f43;
	case 3912ULL: goto x86_l_f48;
	case 3914ULL: goto x86_l_f4a;
	case 3919ULL: goto x86_l_f4f;
	case 3923ULL: goto x86_l_f53;
	case 3928ULL: goto x86_l_f58;
	case 3933ULL: goto x86_l_f5d;
	case 3938ULL: goto x86_l_f62;
	case 3943ULL: goto x86_l_f67;
	case 3947ULL: goto x86_l_f6b;
	case 3952ULL: goto x86_l_f70;
	case 3954ULL: goto x86_l_f72;
	case 3959ULL: goto x86_l_f77;
	case 3962ULL: goto x86_l_f7a;
	case 3967ULL: goto x86_l_f7f;
	case 3972ULL: goto x86_l_f84;
	case 3977ULL: goto x86_l_f89;
	case 3982ULL: goto x86_l_f8e;
	case 3984ULL: goto x86_l_f90;
	case 3989ULL: goto x86_l_f95;
	case 3993ULL: goto x86_l_f99;
	case 3999ULL: goto x86_l_f9f;
	case 4003ULL: goto x86_l_fa3;
	case 4011ULL: goto x86_l_fab;
	case 4016ULL: goto x86_l_fb0;
	case 4019ULL: goto x86_l_fb3;
	case 4021ULL: goto x86_l_fb5;
	case 4028ULL: goto x86_l_fbc;
	case 4032ULL: goto x86_l_fc0;
	case 4035ULL: goto x86_l_fc3;
	case 4040ULL: goto x86_l_fc8;
	case 4052ULL: goto x86_l_fd4;
	case 4060ULL: goto x86_l_fdc;
	case 4071ULL: goto x86_l_fe7;
	case 4076ULL: goto x86_l_fec;
	case 4081ULL: goto x86_l_ff1;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4094ULL: goto x86_l_ffe;
	case 4099ULL: goto x86_l_1003;
	case 4101ULL: goto x86_l_1005;
	case 4106ULL: goto x86_l_100a;
	case 4110ULL: goto x86_l_100e;
	case 4116ULL: goto x86_l_1014;
	case 4120ULL: goto x86_l_1018;
	case 4125ULL: goto x86_l_101d;
	case 4130ULL: goto x86_l_1022;
	case 4133ULL: goto x86_l_1025;
	case 4138ULL: goto x86_l_102a;
	case 4141ULL: goto x86_l_102d;
	case 4143ULL: goto x86_l_102f;
	case 4147ULL: goto x86_l_1033;
	case 4152ULL: goto x86_l_1038;
	case 4157ULL: goto x86_l_103d;
	case 4162ULL: goto x86_l_1042;
	case 4167ULL: goto x86_l_1047;
	case 4172ULL: goto x86_l_104c;
	case 4174ULL: goto x86_l_104e;
	case 4179ULL: goto x86_l_1053;
	case 4185ULL: goto x86_l_1059;
	case 4190ULL: goto x86_l_105e;
	case 4195ULL: goto x86_l_1063;
	case 4200ULL: goto x86_l_1068;
	case 4205ULL: goto x86_l_106d;
	case 4207ULL: goto x86_l_106f;
	case 4212ULL: goto x86_l_1074;
	case 4218ULL: goto x86_l_107a;
	case 4222ULL: goto x86_l_107e;
	case 4225ULL: goto x86_l_1081;
	case 4230ULL: goto x86_l_1086;
	case 4235ULL: goto x86_l_108b;
	case 4240ULL: goto x86_l_1090;
	case 4243ULL: goto x86_l_1093;
	case 4245ULL: goto x86_l_1095;
	case 4249ULL: goto x86_l_1099;
	case 4255ULL: goto x86_l_109f;
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
	case 4447ULL: goto x86_l_115f;
	case 4452ULL: goto x86_l_1164;
	case 4457ULL: goto x86_l_1169;
	case 4462ULL: goto x86_l_116e;
	case 4467ULL: goto x86_l_1173;
	case 4472ULL: goto x86_l_1178;
	case 4475ULL: goto x86_l_117b;
	case 4481ULL: goto x86_l_1181;
	case 4484ULL: goto x86_l_1184;
	case 4487ULL: goto x86_l_1187;
	case 4493ULL: goto x86_l_118d;
	case 4496ULL: goto x86_l_1190;
	case 4499ULL: goto x86_l_1193;
	case 4505ULL: goto x86_l_1199;
	case 4508ULL: goto x86_l_119c;
	case 4516ULL: goto x86_l_11a4;
	case 4521ULL: goto x86_l_11a9;
	case 4527ULL: goto x86_l_11af;
	case 4531ULL: goto x86_l_11b3;
	case 4536ULL: goto x86_l_11b8;
	case 4540ULL: goto x86_l_11bc;
	case 4544ULL: goto x86_l_11c0;
	case 4548ULL: goto x86_l_11c4;
	case 4553ULL: goto x86_l_11c9;
	case 4558ULL: goto x86_l_11ce;
	case 4563ULL: goto x86_l_11d3;
	case 4565ULL: goto x86_l_11d5;
	case 4569ULL: goto x86_l_11d9;
	case 4573ULL: goto x86_l_11dd;
	case 4578ULL: goto x86_l_11e2;
	case 4583ULL: goto x86_l_11e7;
	case 4588ULL: goto x86_l_11ec;
	case 4590ULL: goto x86_l_11ee;
	case 4594ULL: goto x86_l_11f2;
	case 4601ULL: goto x86_l_11f9;
	case 4606ULL: goto x86_l_11fe;
	case 4611ULL: goto x86_l_1203;
	case 4616ULL: goto x86_l_1208;
	case 4618ULL: goto x86_l_120a;
	case 4622ULL: goto x86_l_120e;
	case 4629ULL: goto x86_l_1215;
	case 4634ULL: goto x86_l_121a;
	case 4639ULL: goto x86_l_121f;
	case 4644ULL: goto x86_l_1224;
	case 4646ULL: goto x86_l_1226;
	case 4650ULL: goto x86_l_122a;
	case 4657ULL: goto x86_l_1231;
	case 4662ULL: goto x86_l_1236;
	case 4667ULL: goto x86_l_123b;
	case 4672ULL: goto x86_l_1240;
	case 4674ULL: goto x86_l_1242;
	case 4678ULL: goto x86_l_1246;
	case 4685ULL: goto x86_l_124d;
	case 4690ULL: goto x86_l_1252;
	case 4695ULL: goto x86_l_1257;
	case 4700ULL: goto x86_l_125c;
	case 4702ULL: goto x86_l_125e;
	case 4706ULL: goto x86_l_1262;
	case 4713ULL: goto x86_l_1269;
	case 4721ULL: goto x86_l_1271;
	case 4729ULL: goto x86_l_1279;
	case 4737ULL: goto x86_l_1281;
	case 4742ULL: goto x86_l_1286;
	case 4745ULL: goto x86_l_1289;
	case 4751ULL: goto x86_l_128f;
	case 4754ULL: goto x86_l_1292;
	case 4760ULL: goto x86_l_1298;
	case 4764ULL: goto x86_l_129c;
	case 4769ULL: goto x86_l_12a1;
	case 4774ULL: goto x86_l_12a6;
	case 4779ULL: goto x86_l_12ab;
	case 4784ULL: goto x86_l_12b0;
	case 4786ULL: goto x86_l_12b2;
	case 4791ULL: goto x86_l_12b7;
	case 4796ULL: goto x86_l_12bc;
	case 4799ULL: goto x86_l_12bf;
	case 4804ULL: goto x86_l_12c4;
	case 4807ULL: goto x86_l_12c7;
	case 4812ULL: goto x86_l_12cc;
	case 4817ULL: goto x86_l_12d1;
	case 4820ULL: goto x86_l_12d4;
	case 4826ULL: goto x86_l_12da;
	case 4829ULL: goto x86_l_12dd;
	case 4832ULL: goto x86_l_12e0;
	case 4835ULL: goto x86_l_12e3;
	case 4841ULL: goto x86_l_12e9;
	case 4844ULL: goto x86_l_12ec;
	case 4850ULL: goto x86_l_12f2;
	case 4855ULL: goto x86_l_12f7;
	case 4860ULL: goto x86_l_12fc;
	case 4865ULL: goto x86_l_1301;
	case 4870ULL: goto x86_l_1306;
	case 4872ULL: goto x86_l_1308;
	case 4875ULL: goto x86_l_130b;
	case 4880ULL: goto x86_l_1310;
	case 4883ULL: goto x86_l_1313;
	case 4889ULL: goto x86_l_1319;
	case 4892ULL: goto x86_l_131c;
	case 4898ULL: goto x86_l_1322;
	case 4901ULL: goto x86_l_1325;
	case 4909ULL: goto x86_l_132d;
	case 4914ULL: goto x86_l_1332;
	case 4920ULL: goto x86_l_1338;
	case 4926ULL: goto x86_l_133e;
	case 4929ULL: goto x86_l_1341;
	case 4934ULL: goto x86_l_1346;
	case 4937ULL: goto x86_l_1349;
	case 4942ULL: goto x86_l_134e;
	case 4947ULL: goto x86_l_1353;
	case 4952ULL: goto x86_l_1358;
	case 4954ULL: goto x86_l_135a;
	case 4959ULL: goto x86_l_135f;
	case 4962ULL: goto x86_l_1362;
	case 4967ULL: goto x86_l_1367;
	case 4972ULL: goto x86_l_136c;
	case 4975ULL: goto x86_l_136f;
	case 4980ULL: goto x86_l_1374;
	case 4985ULL: goto x86_l_1379;
	case 4990ULL: goto x86_l_137e;
	case 4992ULL: goto x86_l_1380;
	case 4997ULL: goto x86_l_1385;
	case 5001ULL: goto x86_l_1389;
	case 5007ULL: goto x86_l_138f;
	case 5011ULL: goto x86_l_1393;
	case 5016ULL: goto x86_l_1398;
	case 5021ULL: goto x86_l_139d;
	case 5024ULL: goto x86_l_13a0;
	case 5029ULL: goto x86_l_13a5;
	case 5032ULL: goto x86_l_13a8;
	case 5034ULL: goto x86_l_13aa;
	case 5038ULL: goto x86_l_13ae;
	case 5043ULL: goto x86_l_13b3;
	case 5048ULL: goto x86_l_13b8;
	case 5053ULL: goto x86_l_13bd;
	case 5058ULL: goto x86_l_13c2;
	case 5063ULL: goto x86_l_13c7;
	case 5065ULL: goto x86_l_13c9;
	case 5070ULL: goto x86_l_13ce;
	case 5076ULL: goto x86_l_13d4;
	case 5081ULL: goto x86_l_13d9;
	case 5086ULL: goto x86_l_13de;
	case 5091ULL: goto x86_l_13e3;
	case 5096ULL: goto x86_l_13e8;
	case 5101ULL: goto x86_l_13ed;
	case 5103ULL: goto x86_l_13ef;
	case 5108ULL: goto x86_l_13f4;
	case 5114ULL: goto x86_l_13fa;
	case 5118ULL: goto x86_l_13fe;
	case 5121ULL: goto x86_l_1401;
	case 5126ULL: goto x86_l_1406;
	case 5131ULL: goto x86_l_140b;
	case 5136ULL: goto x86_l_1410;
	case 5139ULL: goto x86_l_1413;
	case 5141ULL: goto x86_l_1415;
	case 5145ULL: goto x86_l_1419;
	case 5151ULL: goto x86_l_141f;
	case 5156ULL: goto x86_l_1424;
	case 5161ULL: goto x86_l_1429;
	case 5166ULL: goto x86_l_142e;
	case 5171ULL: goto x86_l_1433;
	case 5174ULL: goto x86_l_1436;
	case 5176ULL: goto x86_l_1438;
	case 5180ULL: goto x86_l_143c;
	case 5185ULL: goto x86_l_1441;
	case 5190ULL: goto x86_l_1446;
	case 5195ULL: goto x86_l_144b;
	case 5200ULL: goto x86_l_1450;
	case 5203ULL: goto x86_l_1453;
	case 5205ULL: goto x86_l_1455;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5219ULL: goto x86_l_1463;
	case 5222ULL: goto x86_l_1466;
	case 5227ULL: goto x86_l_146b;
	case 5229ULL: goto x86_l_146d;
	case 5231ULL: goto x86_l_146f;
	case 5234ULL: goto x86_l_1472;
	case 5237ULL: goto x86_l_1475;
	case 5242ULL: goto x86_l_147a;
	case 5244ULL: goto x86_l_147c;
	case 5247ULL: goto x86_l_147f;
	case 5251ULL: goto x86_l_1483;
	case 5253ULL: goto x86_l_1485;
	case 5257ULL: goto x86_l_1489;
	case 5259ULL: goto x86_l_148b;
	case 5262ULL: goto x86_l_148e;
	case 5264ULL: goto x86_l_1490;
	case 5268ULL: goto x86_l_1494;
	case 5271ULL: goto x86_l_1497;
	case 5276ULL: goto x86_l_149c;
	case 5282ULL: goto x86_l_14a2;
	case 5288ULL: goto x86_l_14a8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e40:
	/* 0xe40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e45:
	/* 0xe45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e4a:
	/* 0xe4a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_e4d:
	/* 0xe4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4f:
	/* 0xe4f: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_e53:
	/* 0xe53: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e58:
	/* 0xe58: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_e5d:
	/* 0xe5d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e62:
	/* 0xe62: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_e67:
	/* 0xe67: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e6a:
	/* 0xe6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e6c:
	/* 0xe6c: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e71:
	/* 0xe71: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e76:
	/* 0xe76: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e7a:
	/* 0xe7a: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_e7d:
	/* 0xe7d: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e82:
	/* 0xe82: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e84:
	/* 0xe84: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_e86:
	/* 0xe86: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_e89:
	/* 0xe89: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_e8c:
	/* 0xe8c: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_e91:
	/* 0xe91: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e93:
	/* 0xe93: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_e96:
	/* 0xe96: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_e9a:
	/* 0xe9a: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_e9c:
	/* 0xe9c: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_ea0:
	/* 0xea0: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ea2:
	/* 0xea2: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_ea5:
	/* 0xea5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_ea7:
	/* 0xea7: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_eab:
	/* 0xeab: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_eae:
	/* 0xeae: jb     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3478ULL;
	}
x86_l_eb4:
	/* 0xeb4: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_eba:
	/* 0xeba: ja     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3478ULL;
	}
x86_l_ec0:
	/* 0xec0: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_ec3:
	/* 0xec3: jbe    eca <generic_uprobe_process_event+0xeca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_eca;
	}
x86_l_ec5:
	/* 0xec5: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_eca:
	/* 0xeca: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ecc:
	/* 0xecc: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_ecf:
	/* 0xecf: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_ed3:
	/* 0xed3: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ed6:
	/* 0xed6: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ed9:
	/* 0xed9: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_edc:
	/* 0xedc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ee1:
	/* 0xee1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee3:
	/* 0xee3: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ee8:
	/* 0xee8: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_eeb:
	/* 0xeeb: jbe    d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3478ULL;
	}
x86_l_ef1:
	/* 0xef1: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ef6:
	/* 0xef6: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_efb:
	/* 0xefb: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f00:
	/* 0xf00: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f05:
	/* 0xf05: lea    r15,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f0a:
	/* 0xf0a: jmp    1047 <generic_uprobe_process_event+0x1047> */
	goto x86_l_1047;
x86_l_f0f:
	/* 0xf0f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f11:
	/* 0xf11: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f14:
	/* 0xf14: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f18:
	/* 0xf18: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f1f:
	/* 0xf1f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f24:
	/* 0xf24: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_f27:
	/* 0xf27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f29:
	/* 0xf29: mov    DWORD PTR [r15],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f2c:
	/* 0xf2c: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f31:
	/* 0xf31: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f36:
	/* 0xf36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f3b:
	/* 0xf3b: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_f43:
	/* 0xf43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f48:
	/* 0xf48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4a:
	/* 0xf4a: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f4f:
	/* 0xf4f: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_f53:
	/* 0xf53: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f58:
	/* 0xf58: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f5d:
	/* 0xf5d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f62:
	/* 0xf62: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f67:
	/* 0xf67: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_f6b:
	/* 0xf6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f70:
	/* 0xf70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f72:
	/* 0xf72: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f77:
	/* 0xf77: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f7a:
	/* 0xf7a: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_f7f:
	/* 0xf7f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f84:
	/* 0xf84: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f89:
	/* 0xf89: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f8e:
	/* 0xf8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f90:
	/* 0xf90: mov    DWORD PTR [r15+r13*1+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_f95:
	/* 0xf95: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_f99:
	/* 0xf99: mov    WORD PTR [r15+r13*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_f9f:
	/* 0xf9f: add    r13d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_fa3:
	/* 0xfa3: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_fab:
	/* 0xfab: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fb0:
	/* 0xfb0: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_fb3:
	/* 0xfb3: js     fc8 <generic_uprobe_process_event+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_fc8;
	}
x86_l_fb5:
	/* 0xfb5: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_fbc:
	/* 0xfbc: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_fc0:
	/* 0xfc0: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_fc3:
	/* 0xfc3: jmp    4cc <generic_uprobe_process_event+0x4cc> */
	return 1228ULL;
x86_l_fc8:
	/* 0xfc8: mov    DWORD PTR [rax+r12*4+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 104045582745599ULL);
x86_l_fd4:
	/* 0xfd4: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_fdc:
	/* 0xfdc: mov    DWORD PTR [rax+rcx*1+0x90],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 622770257919ULL);
x86_l_fe7:
	/* 0xfe7: jmp    4cc <generic_uprobe_process_event+0x4cc> */
	return 1228ULL;
x86_l_fec:
	/* 0xfec: lea    rdx,[r12-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_ff1:
	/* 0xff1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ff4:
	/* 0xff4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ff9:
	/* 0xff9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ffe:
	/* 0xffe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1003:
	/* 0x1003: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1005:
	/* 0x1005: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_100a:
	/* 0x100a: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_100e:
	/* 0x100e: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_1014:
	/* 0x1014: add    r12,0xfffffffffffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551608ULL);
x86_l_1018:
	/* 0x1018: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_101d:
	/* 0x101d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1022:
	/* 0x1022: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1025:
	/* 0x1025: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_102a:
	/* 0x102a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_102d:
	/* 0x102d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_102f:
	/* 0x102f: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1033:
	/* 0x1033: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1038:
	/* 0x1038: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_103d:
	/* 0x103d: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1042:
	/* 0x1042: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1047:
	/* 0x1047: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_104c:
	/* 0x104c: jne    1059 <generic_uprobe_process_event+0x1059> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1059;
	}
x86_l_104e:
	/* 0x104e: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1053:
	/* 0x1053: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_1059:
	/* 0x1059: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_105e:
	/* 0x105e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1063:
	/* 0x1063: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1068:
	/* 0x1068: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_106d:
	/* 0x106d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_106f:
	/* 0x106f: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_1074:
	/* 0x1074: je     1367 <generic_uprobe_process_event+0x1367> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1367;
	}
x86_l_107a:
	/* 0x107a: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_107e:
	/* 0x107e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1081:
	/* 0x1081: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1086:
	/* 0x1086: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_108b:
	/* 0x108b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1090:
	/* 0x1090: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1093:
	/* 0x1093: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1095:
	/* 0x1095: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1099:
	/* 0x1099: je     1367 <generic_uprobe_process_event+0x1367> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1367;
	}
x86_l_109f:
	/* 0x109f: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
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
	/* 0x10b3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_10b6:
	/* 0x10b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b8:
	/* 0x10b8: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_10bc:
	/* 0x10bc: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
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
	/* 0x10d0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
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
	/* 0x10df: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
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
	/* 0x10f5: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
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
	/* 0x1117: jb     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3478ULL;
	}
x86_l_111d:
	/* 0x111d: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_1123:
	/* 0x1123: ja     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3478ULL;
	}
x86_l_1129:
	/* 0x1129: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_112c:
	/* 0x112c: jbe    1133 <generic_uprobe_process_event+0x1133> */
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
	/* 0x1154: jbe    d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3478ULL;
	}
x86_l_115a:
	/* 0x115a: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_115f:
	/* 0x115f: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1164:
	/* 0x1164: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1169:
	/* 0x1169: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_116e:
	/* 0x116e: jmp    13c2 <generic_uprobe_process_event+0x13c2> */
	goto x86_l_13c2;
x86_l_1173:
	/* 0x1173: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1178:
	/* 0x1178: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_117b:
	/* 0x117b: jle    1310 <generic_uprobe_process_event+0x1310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1310;
	}
x86_l_1181:
	/* 0x1181: lea    ecx,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_1184:
	/* 0x1184: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1187:
	/* 0x1187: jb     1338 <generic_uprobe_process_event+0x1338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1338;
	}
x86_l_118d:
	/* 0x118d: lea    eax,[rbp-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_1190:
	/* 0x1190: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1193:
	/* 0x1193: jb     14fd <generic_uprobe_process_event+0x14fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5373ULL;
	}
x86_l_1199:
	/* 0x1199: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_119c:
	/* 0x119c: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11a4:
	/* 0x11a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11a9:
	/* 0x11a9: jne    fb0 <generic_uprobe_process_event+0xfb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fb0;
	}
x86_l_11af:
	/* 0x11af: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11b3:
	/* 0x11b3: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11b8:
	/* 0x11b8: mov    QWORD PTR [r15+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11bc:
	/* 0x11bc: lea    rdi,[r15+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_11c0:
	/* 0x11c0: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11c4:
	/* 0x11c4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11c9:
	/* 0x11c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11ce:
	/* 0x11ce: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_11d3:
	/* 0x11d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d5:
	/* 0x11d5: lea    rdi,[r15+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_11d9:
	/* 0x11d9: lea    rdx,[r13+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_11dd:
	/* 0x11dd: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11e2:
	/* 0x11e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11e7:
	/* 0x11e7: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_11ec:
	/* 0x11ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ee:
	/* 0x11ee: lea    rdi,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11f2:
	/* 0x11f2: lea    rdx,[r13+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_11f9:
	/* 0x11f9: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11fe:
	/* 0x11fe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1203:
	/* 0x1203: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1208:
	/* 0x1208: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_120a:
	/* 0x120a: lea    rdi,[r15+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_120e:
	/* 0x120e: lea    rdx,[r13+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_1215:
	/* 0x1215: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_121a:
	/* 0x121a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_121f:
	/* 0x121f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1224:
	/* 0x1224: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1226:
	/* 0x1226: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_122a:
	/* 0x122a: lea    rdx,[r13+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_1231:
	/* 0x1231: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1236:
	/* 0x1236: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_123b:
	/* 0x123b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1240:
	/* 0x1240: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1242:
	/* 0x1242: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1246:
	/* 0x1246: lea    rdx,[r13+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_124d:
	/* 0x124d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1252:
	/* 0x1252: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1257:
	/* 0x1257: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_125c:
	/* 0x125c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_125e:
	/* 0x125e: lea    r12,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1262:
	/* 0x1262: mov    QWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1269:
	/* 0x1269: mov    QWORD PTR [r15+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1271:
	/* 0x1271: mov    QWORD PTR [r15+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1279:
	/* 0x1279: mov    QWORD PTR [r15+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1281:
	/* 0x1281: movzx  eax,WORD PTR [r15+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1286:
	/* 0x1286: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1289:
	/* 0x1289: je     1c22 <generic_uprobe_process_event+0x1c22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7202ULL;
	}
x86_l_128f:
	/* 0x128f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1292:
	/* 0x1292: jne    1c54 <generic_uprobe_process_event+0x1c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7252ULL;
	}
x86_l_1298:
	/* 0x1298: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_129c:
	/* 0x129c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12a1:
	/* 0x12a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12a6:
	/* 0x12a6: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12ab:
	/* 0x12ab: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12b0:
	/* 0x12b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b2:
	/* 0x12b2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12b7:
	/* 0x12b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12bc:
	/* 0x12bc: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_12bf:
	/* 0x12bf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12c4:
	/* 0x12c4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_12c7:
	/* 0x12c7: jmp    1c52 <generic_uprobe_process_event+0x1c52> */
	return 7250ULL;
x86_l_12cc:
	/* 0x12cc: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12d1:
	/* 0x12d1: cmp    ebp,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 38ULL);
x86_l_12d4:
	/* 0x12d4: jg     156c <generic_uprobe_process_event+0x156c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5484ULL;
	}
x86_l_12da:
	/* 0x12da: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_12dd:
	/* 0x12dd: lea    eax,[rbp-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_12e0:
	/* 0x12e0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12e3:
	/* 0x12e3: jae    162e <generic_uprobe_process_event+0x162e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5678ULL;
	}
x86_l_12e9:
	/* 0x12e9: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_12ec:
	/* 0x12ec: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_12f2:
	/* 0x12f2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12f7:
	/* 0x12f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12fc:
	/* 0x12fc: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1301:
	/* 0x1301: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1306:
	/* 0x1306: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1308:
	/* 0x1308: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_130b:
	/* 0x130b: jmp    fab <generic_uprobe_process_event+0xfab> */
	goto x86_l_fab;
x86_l_1310:
	/* 0x1310: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1313:
	/* 0x1313: jg     1521 <generic_uprobe_process_event+0x1521> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5409ULL;
	}
x86_l_1319:
	/* 0x1319: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_131c:
	/* 0x131c: je     14fd <generic_uprobe_process_event+0x14fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5373ULL;
	}
x86_l_1322:
	/* 0x1322: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1325:
	/* 0x1325: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_132d:
	/* 0x132d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1332:
	/* 0x1332: jne    fb0 <generic_uprobe_process_event+0xfb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fb0;
	}
x86_l_1338:
	/* 0x1338: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_133e:
	/* 0x133e: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1341:
	/* 0x1341: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1346:
	/* 0x1346: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1349:
	/* 0x1349: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_134e:
	/* 0x134e: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1353:
	/* 0x1353: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1358:
	/* 0x1358: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135a:
	/* 0x135a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_135f:
	/* 0x135f: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1362:
	/* 0x1362: jmp    fb0 <generic_uprobe_process_event+0xfb0> */
	goto x86_l_fb0;
x86_l_1367:
	/* 0x1367: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_136c:
	/* 0x136c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_136f:
	/* 0x136f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1374:
	/* 0x1374: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1379:
	/* 0x1379: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_137e:
	/* 0x137e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1380:
	/* 0x1380: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1385:
	/* 0x1385: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1389:
	/* 0x1389: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_138f:
	/* 0x138f: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1393:
	/* 0x1393: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1398:
	/* 0x1398: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_139d:
	/* 0x139d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_13a0:
	/* 0x13a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13a5:
	/* 0x13a5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_13a8:
	/* 0x13a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13aa:
	/* 0x13aa: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ae:
	/* 0x13ae: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13b3:
	/* 0x13b3: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13b8:
	/* 0x13b8: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_13bd:
	/* 0x13bd: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13c2:
	/* 0x13c2: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_13c7:
	/* 0x13c7: jne    13d4 <generic_uprobe_process_event+0x13d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13d4;
	}
x86_l_13c9:
	/* 0x13c9: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_13ce:
	/* 0x13ce: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_13d4:
	/* 0x13d4: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13d9:
	/* 0x13d9: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13de:
	/* 0x13de: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13e3:
	/* 0x13e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13e8:
	/* 0x13e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13ed:
	/* 0x13ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ef:
	/* 0x13ef: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_13f4:
	/* 0x13f4: je     19c8 <generic_uprobe_process_event+0x19c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6600ULL;
	}
x86_l_13fa:
	/* 0x13fa: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13fe:
	/* 0x13fe: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1401:
	/* 0x1401: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1406:
	/* 0x1406: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_140b:
	/* 0x140b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1410:
	/* 0x1410: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1413:
	/* 0x1413: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1415:
	/* 0x1415: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1419:
	/* 0x1419: je     19c8 <generic_uprobe_process_event+0x19c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6600ULL;
	}
x86_l_141f:
	/* 0x141f: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1424:
	/* 0x1424: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1429:
	/* 0x1429: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_142e:
	/* 0x142e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1433:
	/* 0x1433: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1436:
	/* 0x1436: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1438:
	/* 0x1438: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_143c:
	/* 0x143c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1441:
	/* 0x1441: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1446:
	/* 0x1446: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_144b:
	/* 0x144b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1450:
	/* 0x1450: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1453:
	/* 0x1453: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1455:
	/* 0x1455: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_145a:
	/* 0x145a: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_145f:
	/* 0x145f: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1463:
	/* 0x1463: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1466:
	/* 0x1466: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_146b:
	/* 0x146b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_146d:
	/* 0x146d: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_146f:
	/* 0x146f: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1472:
	/* 0x1472: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1475:
	/* 0x1475: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_147a:
	/* 0x147a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_147c:
	/* 0x147c: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_147f:
	/* 0x147f: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_1483:
	/* 0x1483: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1485:
	/* 0x1485: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_1489:
	/* 0x1489: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_148b:
	/* 0x148b: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_148e:
	/* 0x148e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1490:
	/* 0x1490: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1494:
	/* 0x1494: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1497:
	/* 0x1497: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_149c:
	/* 0x149c: jb     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3478ULL;
	}
x86_l_14a2:
	/* 0x14a2: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_14a8:
	/* 0x14a8: ja     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3478ULL;
	}
	return 5294ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5294ULL: goto x86_l_14ae;
	case 5297ULL: goto x86_l_14b1;
	case 5299ULL: goto x86_l_14b3;
	case 5304ULL: goto x86_l_14b8;
	case 5306ULL: goto x86_l_14ba;
	case 5309ULL: goto x86_l_14bd;
	case 5313ULL: goto x86_l_14c1;
	case 5316ULL: goto x86_l_14c4;
	case 5319ULL: goto x86_l_14c7;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5329ULL: goto x86_l_14d1;
	case 5334ULL: goto x86_l_14d6;
	case 5337ULL: goto x86_l_14d9;
	case 5342ULL: goto x86_l_14de;
	case 5348ULL: goto x86_l_14e4;
	case 5353ULL: goto x86_l_14e9;
	case 5358ULL: goto x86_l_14ee;
	case 5363ULL: goto x86_l_14f3;
	case 5368ULL: goto x86_l_14f8;
	case 5373ULL: goto x86_l_14fd;
	case 5376ULL: goto x86_l_1500;
	case 5382ULL: goto x86_l_1506;
	case 5387ULL: goto x86_l_150b;
	case 5392ULL: goto x86_l_1510;
	case 5397ULL: goto x86_l_1515;
	case 5402ULL: goto x86_l_151a;
	case 5404ULL: goto x86_l_151c;
	case 5409ULL: goto x86_l_1521;
	case 5412ULL: goto x86_l_1524;
	case 5418ULL: goto x86_l_152a;
	case 5421ULL: goto x86_l_152d;
	case 5429ULL: goto x86_l_1535;
	case 5434ULL: goto x86_l_153a;
	case 5439ULL: goto x86_l_153f;
	case 5445ULL: goto x86_l_1545;
	case 5450ULL: goto x86_l_154a;
	case 5453ULL: goto x86_l_154d;
	case 5459ULL: goto x86_l_1553;
	case 5464ULL: goto x86_l_1558;
	case 5469ULL: goto x86_l_155d;
	case 5472ULL: goto x86_l_1560;
	case 5477ULL: goto x86_l_1565;
	case 5479ULL: goto x86_l_1567;
	case 5484ULL: goto x86_l_156c;
	case 5489ULL: goto x86_l_1571;
	case 5492ULL: goto x86_l_1574;
	case 5495ULL: goto x86_l_1577;
	case 5501ULL: goto x86_l_157d;
	case 5504ULL: goto x86_l_1580;
	case 5507ULL: goto x86_l_1583;
	case 5512ULL: goto x86_l_1588;
	case 5517ULL: goto x86_l_158d;
	case 5522ULL: goto x86_l_1592;
	case 5528ULL: goto x86_l_1598;
	case 5532ULL: goto x86_l_159c;
	case 5537ULL: goto x86_l_15a1;
	case 5545ULL: goto x86_l_15a9;
	case 5553ULL: goto x86_l_15b1;
	case 5560ULL: goto x86_l_15b8;
	case 5565ULL: goto x86_l_15bd;
	case 5570ULL: goto x86_l_15c2;
	case 5575ULL: goto x86_l_15c7;
	case 5578ULL: goto x86_l_15ca;
	case 5580ULL: goto x86_l_15cc;
	case 5583ULL: goto x86_l_15cf;
	case 5589ULL: goto x86_l_15d5;
	case 5594ULL: goto x86_l_15da;
	case 5597ULL: goto x86_l_15dd;
	case 5600ULL: goto x86_l_15e0;
	case 5606ULL: goto x86_l_15e6;
	case 5609ULL: goto x86_l_15e9;
	case 5615ULL: goto x86_l_15ef;
	case 5620ULL: goto x86_l_15f4;
	case 5625ULL: goto x86_l_15f9;
	case 5630ULL: goto x86_l_15fe;
	case 5635ULL: goto x86_l_1603;
	case 5640ULL: goto x86_l_1608;
	case 5642ULL: goto x86_l_160a;
	case 5646ULL: goto x86_l_160e;
	case 5651ULL: goto x86_l_1613;
	case 5655ULL: goto x86_l_1617;
	case 5659ULL: goto x86_l_161b;
	case 5663ULL: goto x86_l_161f;
	case 5668ULL: goto x86_l_1624;
	case 5673ULL: goto x86_l_1629;
	case 5678ULL: goto x86_l_162e;
	case 5681ULL: goto x86_l_1631;
	case 5684ULL: goto x86_l_1634;
	case 5689ULL: goto x86_l_1639;
	case 5695ULL: goto x86_l_163f;
	case 5699ULL: goto x86_l_1643;
	case 5702ULL: goto x86_l_1646;
	case 5705ULL: goto x86_l_1649;
	case 5708ULL: goto x86_l_164c;
	case 5711ULL: goto x86_l_164f;
	case 5717ULL: goto x86_l_1655;
	case 5722ULL: goto x86_l_165a;
	case 5726ULL: goto x86_l_165e;
	case 5728ULL: goto x86_l_1660;
	case 5733ULL: goto x86_l_1665;
	case 5735ULL: goto x86_l_1667;
	case 5738ULL: goto x86_l_166a;
	case 5741ULL: goto x86_l_166d;
	case 5743ULL: goto x86_l_166f;
	case 5747ULL: goto x86_l_1673;
	case 5752ULL: goto x86_l_1678;
	case 5754ULL: goto x86_l_167a;
	case 5758ULL: goto x86_l_167e;
	case 5761ULL: goto x86_l_1681;
	case 5766ULL: goto x86_l_1686;
	case 5771ULL: goto x86_l_168b;
	case 5774ULL: goto x86_l_168e;
	case 5779ULL: goto x86_l_1693;
	case 5783ULL: goto x86_l_1697;
	case 5788ULL: goto x86_l_169c;
	case 5792ULL: goto x86_l_16a0;
	case 5799ULL: goto x86_l_16a7;
	case 5804ULL: goto x86_l_16ac;
	case 5809ULL: goto x86_l_16b1;
	case 5814ULL: goto x86_l_16b6;
	case 5816ULL: goto x86_l_16b8;
	case 5820ULL: goto x86_l_16bc;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5834ULL: goto x86_l_16ca;
	case 5839ULL: goto x86_l_16cf;
	case 5841ULL: goto x86_l_16d1;
	case 5845ULL: goto x86_l_16d5;
	case 5852ULL: goto x86_l_16dc;
	case 5857ULL: goto x86_l_16e1;
	case 5862ULL: goto x86_l_16e6;
	case 5867ULL: goto x86_l_16eb;
	case 5869ULL: goto x86_l_16ed;
	case 5873ULL: goto x86_l_16f1;
	case 5880ULL: goto x86_l_16f8;
	case 5885ULL: goto x86_l_16fd;
	case 5890ULL: goto x86_l_1702;
	case 5895ULL: goto x86_l_1707;
	case 5897ULL: goto x86_l_1709;
	case 5906ULL: goto x86_l_1712;
	case 5913ULL: goto x86_l_1719;
	case 5918ULL: goto x86_l_171e;
	case 5923ULL: goto x86_l_1723;
	case 5928ULL: goto x86_l_1728;
	case 5933ULL: goto x86_l_172d;
	case 5935ULL: goto x86_l_172f;
	case 5942ULL: goto x86_l_1736;
	case 5947ULL: goto x86_l_173b;
	case 5952ULL: goto x86_l_1740;
	case 5957ULL: goto x86_l_1745;
	case 5962ULL: goto x86_l_174a;
	case 5964ULL: goto x86_l_174c;
	case 5970ULL: goto x86_l_1752;
	case 5975ULL: goto x86_l_1757;
	case 5983ULL: goto x86_l_175f;
	case 5988ULL: goto x86_l_1764;
	case 5993ULL: goto x86_l_1769;
	case 5998ULL: goto x86_l_176e;
	case 6001ULL: goto x86_l_1771;
	case 6003ULL: goto x86_l_1773;
	case 6011ULL: goto x86_l_177b;
	case 6014ULL: goto x86_l_177e;
	case 6017ULL: goto x86_l_1781;
	case 6023ULL: goto x86_l_1787;
	case 6026ULL: goto x86_l_178a;
	case 6032ULL: goto x86_l_1790;
	case 6037ULL: goto x86_l_1795;
	case 6045ULL: goto x86_l_179d;
	case 6050ULL: goto x86_l_17a2;
	case 6055ULL: goto x86_l_17a7;
	case 6060ULL: goto x86_l_17ac;
	case 6062ULL: goto x86_l_17ae;
	case 6070ULL: goto x86_l_17b6;
	case 6075ULL: goto x86_l_17bb;
	case 6079ULL: goto x86_l_17bf;
	case 6085ULL: goto x86_l_17c5;
	case 6090ULL: goto x86_l_17ca;
	case 6097ULL: goto x86_l_17d1;
	case 6105ULL: goto x86_l_17d9;
	case 6113ULL: goto x86_l_17e1;
	case 6121ULL: goto x86_l_17e9;
	case 6126ULL: goto x86_l_17ee;
	case 6131ULL: goto x86_l_17f3;
	case 6135ULL: goto x86_l_17f7;
	case 6140ULL: goto x86_l_17fc;
	case 6142ULL: goto x86_l_17fe;
	case 6146ULL: goto x86_l_1802;
	case 6151ULL: goto x86_l_1807;
	case 6156ULL: goto x86_l_180c;
	case 6159ULL: goto x86_l_180f;
	case 6164ULL: goto x86_l_1814;
	case 6167ULL: goto x86_l_1817;
	case 6169ULL: goto x86_l_1819;
	case 6176ULL: goto x86_l_1820;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6199ULL: goto x86_l_1837;
	case 6201ULL: goto x86_l_1839;
	case 6210ULL: goto x86_l_1842;
	case 6215ULL: goto x86_l_1847;
	case 6224ULL: goto x86_l_1850;
	case 6229ULL: goto x86_l_1855;
	case 6231ULL: goto x86_l_1857;
	case 6235ULL: goto x86_l_185b;
	case 6240ULL: goto x86_l_1860;
	case 6245ULL: goto x86_l_1865;
	case 6248ULL: goto x86_l_1868;
	case 6253ULL: goto x86_l_186d;
	case 6258ULL: goto x86_l_1872;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6271ULL: goto x86_l_187f;
	case 6275ULL: goto x86_l_1883;
	case 6279ULL: goto x86_l_1887;
	case 6286ULL: goto x86_l_188e;
	case 6291ULL: goto x86_l_1893;
	case 6296ULL: goto x86_l_1898;
	case 6298ULL: goto x86_l_189a;
	case 6301ULL: goto x86_l_189d;
	case 6307ULL: goto x86_l_18a3;
	case 6310ULL: goto x86_l_18a6;
	case 6313ULL: goto x86_l_18a9;
	case 6318ULL: goto x86_l_18ae;
	case 6323ULL: goto x86_l_18b3;
	case 6328ULL: goto x86_l_18b8;
	case 6331ULL: goto x86_l_18bb;
	case 6336ULL: goto x86_l_18c0;
	case 6338ULL: goto x86_l_18c2;
	case 6345ULL: goto x86_l_18c9;
	case 6349ULL: goto x86_l_18cd;
	case 6353ULL: goto x86_l_18d1;
	case 6358ULL: goto x86_l_18d6;
	case 6361ULL: goto x86_l_18d9;
	case 6363ULL: goto x86_l_18db;
	case 6371ULL: goto x86_l_18e3;
	case 6374ULL: goto x86_l_18e6;
	case 6378ULL: goto x86_l_18ea;
	case 6382ULL: goto x86_l_18ee;
	case 6387ULL: goto x86_l_18f3;
	case 6392ULL: goto x86_l_18f8;
	case 6394ULL: goto x86_l_18fa;
	case 6398ULL: goto x86_l_18fe;
	case 6403ULL: goto x86_l_1903;
	case 6408ULL: goto x86_l_1908;
	case 6411ULL: goto x86_l_190b;
	case 6416ULL: goto x86_l_1910;
	case 6421ULL: goto x86_l_1915;
	case 6426ULL: goto x86_l_191a;
	case 6429ULL: goto x86_l_191d;
	case 6431ULL: goto x86_l_191f;
	case 6436ULL: goto x86_l_1924;
	case 6441ULL: goto x86_l_1929;
	case 6446ULL: goto x86_l_192e;
	case 6451ULL: goto x86_l_1933;
	case 6454ULL: goto x86_l_1936;
	case 6459ULL: goto x86_l_193b;
	case 6461ULL: goto x86_l_193d;
	case 6469ULL: goto x86_l_1945;
	case 6472ULL: goto x86_l_1948;
	case 6476ULL: goto x86_l_194c;
	case 6481ULL: goto x86_l_1951;
	case 6485ULL: goto x86_l_1955;
	case 6490ULL: goto x86_l_195a;
	case 6495ULL: goto x86_l_195f;
	case 6500ULL: goto x86_l_1964;
	case 6502ULL: goto x86_l_1966;
	case 6505ULL: goto x86_l_1969;
	case 6508ULL: goto x86_l_196c;
	case 6510ULL: goto x86_l_196e;
	case 6514ULL: goto x86_l_1972;
	case 6519ULL: goto x86_l_1977;
	case 6521ULL: goto x86_l_1979;
	case 6525ULL: goto x86_l_197d;
	case 6528ULL: goto x86_l_1980;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6542ULL: goto x86_l_198e;
	case 6547ULL: goto x86_l_1993;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6561ULL: goto x86_l_19a1;
	case 6566ULL: goto x86_l_19a6;
	case 6568ULL: goto x86_l_19a8;
	case 6571ULL: goto x86_l_19ab;
	case 6574ULL: goto x86_l_19ae;
	case 6580ULL: goto x86_l_19b4;
	case 6584ULL: goto x86_l_19b8;
	case 6589ULL: goto x86_l_19bd;
	case 6591ULL: goto x86_l_19bf;
	case 6595ULL: goto x86_l_19c3;
	case 6600ULL: goto x86_l_19c8;
	case 6605ULL: goto x86_l_19cd;
	case 6608ULL: goto x86_l_19d0;
	case 6613ULL: goto x86_l_19d5;
	case 6618ULL: goto x86_l_19da;
	case 6623ULL: goto x86_l_19df;
	case 6625ULL: goto x86_l_19e1;
	case 6630ULL: goto x86_l_19e6;
	case 6634ULL: goto x86_l_19ea;
	case 6639ULL: goto x86_l_19ef;
	case 6644ULL: goto x86_l_19f4;
	case 6650ULL: goto x86_l_19fa;
	case 6654ULL: goto x86_l_19fe;
	case 6659ULL: goto x86_l_1a03;
	case 6664ULL: goto x86_l_1a08;
	case 6669ULL: goto x86_l_1a0d;
	case 6672ULL: goto x86_l_1a10;
	case 6674ULL: goto x86_l_1a12;
	case 6678ULL: goto x86_l_1a16;
	case 6683ULL: goto x86_l_1a1b;
	case 6688ULL: goto x86_l_1a20;
	case 6693ULL: goto x86_l_1a25;
	case 6698ULL: goto x86_l_1a2a;
	case 6703ULL: goto x86_l_1a2f;
	case 6708ULL: goto x86_l_1a34;
	case 6710ULL: goto x86_l_1a36;
	case 6715ULL: goto x86_l_1a3b;
	case 6721ULL: goto x86_l_1a41;
	case 6726ULL: goto x86_l_1a46;
	case 6731ULL: goto x86_l_1a4b;
	case 6736ULL: goto x86_l_1a50;
	case 6741ULL: goto x86_l_1a55;
	case 6743ULL: goto x86_l_1a57;
	case 6748ULL: goto x86_l_1a5c;
	case 6754ULL: goto x86_l_1a62;
	case 6758ULL: goto x86_l_1a66;
	case 6761ULL: goto x86_l_1a69;
	case 6766ULL: goto x86_l_1a6e;
	case 6771ULL: goto x86_l_1a73;
	case 6776ULL: goto x86_l_1a78;
	case 6779ULL: goto x86_l_1a7b;
	case 6781ULL: goto x86_l_1a7d;
	case 6785ULL: goto x86_l_1a81;
	case 6791ULL: goto x86_l_1a87;
	case 6796ULL: goto x86_l_1a8c;
	case 6801ULL: goto x86_l_1a91;
	case 6806ULL: goto x86_l_1a96;
	case 6811ULL: goto x86_l_1a9b;
	case 6814ULL: goto x86_l_1a9e;
	case 6816ULL: goto x86_l_1aa0;
	case 6820ULL: goto x86_l_1aa4;
	case 6825ULL: goto x86_l_1aa9;
	case 6830ULL: goto x86_l_1aae;
	case 6835ULL: goto x86_l_1ab3;
	case 6840ULL: goto x86_l_1ab8;
	case 6843ULL: goto x86_l_1abb;
	case 6845ULL: goto x86_l_1abd;
	case 6850ULL: goto x86_l_1ac2;
	case 6855ULL: goto x86_l_1ac7;
	case 6859ULL: goto x86_l_1acb;
	case 6862ULL: goto x86_l_1ace;
	case 6867ULL: goto x86_l_1ad3;
	case 6869ULL: goto x86_l_1ad5;
	case 6871ULL: goto x86_l_1ad7;
	case 6874ULL: goto x86_l_1ada;
	case 6877ULL: goto x86_l_1add;
	case 6882ULL: goto x86_l_1ae2;
	case 6884ULL: goto x86_l_1ae4;
	case 6887ULL: goto x86_l_1ae7;
	case 6891ULL: goto x86_l_1aeb;
	case 6893ULL: goto x86_l_1aed;
	case 6897ULL: goto x86_l_1af1;
	case 6899ULL: goto x86_l_1af3;
	case 6902ULL: goto x86_l_1af6;
	case 6904ULL: goto x86_l_1af8;
	case 6908ULL: goto x86_l_1afc;
	case 6911ULL: goto x86_l_1aff;
	case 6916ULL: goto x86_l_1b04;
	case 6922ULL: goto x86_l_1b0a;
	case 6928ULL: goto x86_l_1b10;
	case 6934ULL: goto x86_l_1b16;
	case 6937ULL: goto x86_l_1b19;
	case 6939ULL: goto x86_l_1b1b;
	case 6944ULL: goto x86_l_1b20;
	case 6946ULL: goto x86_l_1b22;
	case 6949ULL: goto x86_l_1b25;
	case 6953ULL: goto x86_l_1b29;
	case 6956ULL: goto x86_l_1b2c;
	case 6959ULL: goto x86_l_1b2f;
	case 6962ULL: goto x86_l_1b32;
	case 6967ULL: goto x86_l_1b37;
	case 6969ULL: goto x86_l_1b39;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14ae:
	/* 0x14ae: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_14b1:
	/* 0x14b1: jbe    14b8 <generic_uprobe_process_event+0x14b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_14b8;
	}
x86_l_14b3:
	/* 0x14b3: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_14b8:
	/* 0x14b8: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ba:
	/* 0x14ba: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_14bd:
	/* 0x14bd: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_14c1:
	/* 0x14c1: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_14c4:
	/* 0x14c4: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_14c7:
	/* 0x14c7: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_14ca:
	/* 0x14ca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14cf:
	/* 0x14cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d1:
	/* 0x14d1: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_14d6:
	/* 0x14d6: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_14d9:
	/* 0x14d9: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14de:
	/* 0x14de: jbe    d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3478ULL;
	}
x86_l_14e4:
	/* 0x14e4: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14e9:
	/* 0x14e9: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14ee:
	/* 0x14ee: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_14f3:
	/* 0x14f3: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14f8:
	/* 0x14f8: jmp    1a2a <generic_uprobe_process_event+0x1a2a> */
	goto x86_l_1a2a;
x86_l_14fd:
	/* 0x14fd: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1500:
	/* 0x1500: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1506:
	/* 0x1506: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_150b:
	/* 0x150b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1510:
	/* 0x1510: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1515:
	/* 0x1515: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_151a:
	/* 0x151a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151c:
	/* 0x151c: jmp    fa3 <generic_uprobe_process_event+0xfa3> */
	return 4003ULL;
x86_l_1521:
	/* 0x1521: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1524:
	/* 0x1524: je     1693 <generic_uprobe_process_event+0x1693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1693;
	}
x86_l_152a:
	/* 0x152a: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_152d:
	/* 0x152d: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1535:
	/* 0x1535: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_153a:
	/* 0x153a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_153f:
	/* 0x153f: je     1945 <generic_uprobe_process_event+0x1945> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1945;
	}
x86_l_1545:
	/* 0x1545: jmp    fb0 <generic_uprobe_process_event+0xfb0> */
	return 4016ULL;
x86_l_154a:
	/* 0x154a: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_154d:
	/* 0x154d: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1553:
	/* 0x1553: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1558:
	/* 0x1558: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_155d:
	/* 0x155d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1560:
	/* 0x1560: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1565:
	/* 0x1565: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1567:
	/* 0x1567: jmp    fa3 <generic_uprobe_process_event+0xfa3> */
	return 4003ULL;
x86_l_156c:
	/* 0x156c: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1571:
	/* 0x1571: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1574:
	/* 0x1574: cmp    ebp,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 39ULL);
x86_l_1577:
	/* 0x1577: je     1985 <generic_uprobe_process_event+0x1985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1985;
	}
x86_l_157d:
	/* 0x157d: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_1580:
	/* 0x1580: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1583:
	/* 0x1583: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1588:
	/* 0x1588: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_158d:
	/* 0x158d: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1592:
	/* 0x1592: jne    fb0 <generic_uprobe_process_event+0xfb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4016ULL;
	}
x86_l_1598:
	/* 0x1598: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_159c:
	/* 0x159c: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15a1:
	/* 0x15a1: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_15a9:
	/* 0x15a9: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_15b1:
	/* 0x15b1: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b8:
	/* 0x15b8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_15bd:
	/* 0x15bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15c2:
	/* 0x15c2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_15c7:
	/* 0x15c7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_15ca:
	/* 0x15ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15cc:
	/* 0x15cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15cf:
	/* 0x15cf: js     1cec <generic_uprobe_process_event+0x1cec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7404ULL;
	}
x86_l_15d5:
	/* 0x15d5: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15da:
	/* 0x15da: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15dd:
	/* 0x15dd: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_15e0:
	/* 0x15e0: je     1ca2 <generic_uprobe_process_event+0x1ca2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7330ULL;
	}
x86_l_15e6:
	/* 0x15e6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15e9:
	/* 0x15e9: jne    1cdd <generic_uprobe_process_event+0x1cdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7389ULL;
	}
x86_l_15ef:
	/* 0x15ef: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15f4:
	/* 0x15f4: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15f9:
	/* 0x15f9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15fe:
	/* 0x15fe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1603:
	/* 0x1603: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1608:
	/* 0x1608: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_160a:
	/* 0x160a: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_160e:
	/* 0x160e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1613:
	/* 0x1613: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1617:
	/* 0x1617: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_161b:
	/* 0x161b: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_161f:
	/* 0x161f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1624:
	/* 0x1624: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1629:
	/* 0x1629: jmp    1cd3 <generic_uprobe_process_event+0x1cd3> */
	return 7379ULL;
x86_l_162e:
	/* 0x162e: cmp    ebp,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 38ULL);
x86_l_1631:
	/* 0x1631: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1634:
	/* 0x1634: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1639:
	/* 0x1639: jne    fb0 <generic_uprobe_process_event+0xfb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4016ULL;
	}
x86_l_163f:
	/* 0x163f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1643:
	/* 0x1643: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1646:
	/* 0x1646: mov    rbp,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_64);
x86_l_1649:
	/* 0x1649: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_164c:
	/* 0x164c: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_164f:
	/* 0x164f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1655:
	/* 0x1655: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_165a:
	/* 0x165a: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_165e:
	/* 0x165e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1660:
	/* 0x1660: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1665:
	/* 0x1665: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1667:
	/* 0x1667: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_166a:
	/* 0x166a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_166d:
	/* 0x166d: js     167e <generic_uprobe_process_event+0x167e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_167e;
	}
x86_l_166f:
	/* 0x166f: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1673:
	/* 0x1673: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1678:
	/* 0x1678: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_167a:
	/* 0x167a: add    r13,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_167e:
	/* 0x167e: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1681:
	/* 0x1681: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1686:
	/* 0x1686: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_168b:
	/* 0x168b: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_168e:
	/* 0x168e: jmp    fb0 <generic_uprobe_process_event+0xfb0> */
	return 4016ULL;
x86_l_1693:
	/* 0x1693: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1697:
	/* 0x1697: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_169c:
	/* 0x169c: lea    rdi,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16a0:
	/* 0x16a0: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_16a7:
	/* 0x16a7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16ac:
	/* 0x16ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16b1:
	/* 0x16b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16b6:
	/* 0x16b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16b8:
	/* 0x16b8: lea    rdi,[r15+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_16bc:
	/* 0x16bc: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16c0:
	/* 0x16c0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16c5:
	/* 0x16c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16ca:
	/* 0x16ca: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16cf:
	/* 0x16cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d1:
	/* 0x16d1: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16d5:
	/* 0x16d5: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_16dc:
	/* 0x16dc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16e1:
	/* 0x16e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16e6:
	/* 0x16e6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16eb:
	/* 0x16eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ed:
	/* 0x16ed: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_16f1:
	/* 0x16f1: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16f8:
	/* 0x16f8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16fd:
	/* 0x16fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1702:
	/* 0x1702: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1707:
	/* 0x1707: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1709:
	/* 0x1709: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1712:
	/* 0x1712: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1719:
	/* 0x1719: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_171e:
	/* 0x171e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1723:
	/* 0x1723: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1728:
	/* 0x1728: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_172d:
	/* 0x172d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_172f:
	/* 0x172f: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1736:
	/* 0x1736: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_173b:
	/* 0x173b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1740:
	/* 0x1740: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1745:
	/* 0x1745: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_174a:
	/* 0x174a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_174c:
	/* 0x174c: movzx  r12d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_1752:
	/* 0x1752: add    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_1757:
	/* 0x1757: lea    rdi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_175f:
	/* 0x175f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1764:
	/* 0x1764: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1769:
	/* 0x1769: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_176e:
	/* 0x176e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1771:
	/* 0x1771: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1773:
	/* 0x1773: movzx  eax,BYTE PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 156ULL);
x86_l_177b:
	/* 0x177b: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_177e:
	/* 0x177e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1781:
	/* 0x1781: je     1b71 <generic_uprobe_process_event+0x1b71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7025ULL;
	}
x86_l_1787:
	/* 0x1787: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_178a:
	/* 0x178a: jne    2ab0 <generic_uprobe_process_event+0x2ab0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10928ULL;
	}
x86_l_1790:
	/* 0x1790: lea    rdx,[r12+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1795:
	/* 0x1795: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_179d:
	/* 0x179d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17a2:
	/* 0x17a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17a7:
	/* 0x17a7: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_17ac:
	/* 0x17ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ae:
	/* 0x17ae: movzx  eax,BYTE PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 176ULL);
x86_l_17b6:
	/* 0x17b6: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17bb:
	/* 0x17bb: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_17bf:
	/* 0x17bf: mov    WORD PTR [rdi+0x26],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_17c5:
	/* 0x17c5: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17ca:
	/* 0x17ca: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17d1:
	/* 0x17d1: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_17d9:
	/* 0x17d9: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17e1:
	/* 0x17e1: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_17e9:
	/* 0x17e9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17ee:
	/* 0x17ee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17f3:
	/* 0x17f3: lea    rbp,[rdi+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17f7:
	/* 0x17f7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17fc:
	/* 0x17fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17fe:
	/* 0x17fe: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1802:
	/* 0x1802: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1807:
	/* 0x1807: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_180c:
	/* 0x180c: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_180f:
	/* 0x180f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1814:
	/* 0x1814: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1817:
	/* 0x1817: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1819:
	/* 0x1819: lea    rdx,[r13+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_1820:
	/* 0x1820: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1828:
	/* 0x1828: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_182d:
	/* 0x182d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1832:
	/* 0x1832: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1837:
	/* 0x1837: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1839:
	/* 0x1839: movzx  r12d,BYTE PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 176ULL);
x86_l_1842:
	/* 0x1842: jmp    2952 <generic_uprobe_process_event+0x2952> */
	return 10578ULL;
x86_l_1847:
	/* 0x1847: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1850:
	/* 0x1850: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1855:
	/* 0x1855: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1857:
	/* 0x1857: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_185b:
	/* 0x185b: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1860:
	/* 0x1860: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1865:
	/* 0x1865: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1868:
	/* 0x1868: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_186d:
	/* 0x186d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1872:
	/* 0x1872: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1878:
	/* 0x1878: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_187d:
	/* 0x187d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187f:
	/* 0x187f: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1883:
	/* 0x1883: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1887:
	/* 0x1887: mov    rdi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_188e:
	/* 0x188e: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1893:
	/* 0x1893: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1898:
	/* 0x1898: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_189a:
	/* 0x189a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_189d:
	/* 0x189d: je     1b65 <generic_uprobe_process_event+0x1b65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7013ULL;
	}
x86_l_18a3:
	/* 0x18a3: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_18a6:
	/* 0x18a6: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18a9:
	/* 0x18a9: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18ae:
	/* 0x18ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18b3:
	/* 0x18b3: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18b8:
	/* 0x18b8: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_18bb:
	/* 0x18bb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18c0:
	/* 0x18c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c2:
	/* 0x18c2: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18c9:
	/* 0x18c9: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18cd:
	/* 0x18cd: lea    rsi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18d1:
	/* 0x18d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18d6:
	/* 0x18d6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_18d9:
	/* 0x18d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18db:
	/* 0x18db: lea    rdi,[r13*1+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_18e3:
	/* 0x18e3: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18e6:
	/* 0x18e6: lea    rdx,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_18ea:
	/* 0x18ea: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_18ee:
	/* 0x18ee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18f3:
	/* 0x18f3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18f8:
	/* 0x18f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18fa:
	/* 0x18fa: add    r13,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_18fe:
	/* 0x18fe: jmp    2ab6 <generic_uprobe_process_event+0x2ab6> */
	return 10934ULL;
x86_l_1903:
	/* 0x1903: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1908:
	/* 0x1908: mov    r12,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSP, X86_WIDTH_64);
x86_l_190b:
	/* 0x190b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1910:
	/* 0x1910: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1915:
	/* 0x1915: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_191a:
	/* 0x191a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_191d:
	/* 0x191d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_191f:
	/* 0x191f: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1924:
	/* 0x1924: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1929:
	/* 0x1929: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_192e:
	/* 0x192e: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1933:
	/* 0x1933: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1936:
	/* 0x1936: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_193b:
	/* 0x193b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193d:
	/* 0x193d: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1945:
	/* 0x1945: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1948:
	/* 0x1948: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_194c:
	/* 0x194c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1951:
	/* 0x1951: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1955:
	/* 0x1955: mov    ecx,0x91 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 145ULL);
x86_l_195a:
	/* 0x195a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_195f:
	/* 0x195f: mov    esi,0x91 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 145ULL);
x86_l_1964:
	/* 0x1964: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1966:
	/* 0x1966: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1969:
	/* 0x1969: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_196c:
	/* 0x196c: js     197d <generic_uprobe_process_event+0x197d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_197d;
	}
x86_l_196e:
	/* 0x196e: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1972:
	/* 0x1972: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1977:
	/* 0x1977: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1979:
	/* 0x1979: add    r13,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_197d:
	/* 0x197d: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1980:
	/* 0x1980: jmp    2abe <generic_uprobe_process_event+0x2abe> */
	return 10942ULL;
x86_l_1985:
	/* 0x1985: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_198a:
	/* 0x198a: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_198e:
	/* 0x198e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1993:
	/* 0x1993: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1997:
	/* 0x1997: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_199c:
	/* 0x199c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_19a1:
	/* 0x19a1: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_19a6:
	/* 0x19a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a8:
	/* 0x19a8: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_19ab:
	/* 0x19ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19ae:
	/* 0x19ae: js     1cf2 <generic_uprobe_process_event+0x1cf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7410ULL;
	}
x86_l_19b4:
	/* 0x19b4: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_19b8:
	/* 0x19b8: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19bd:
	/* 0x19bd: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19bf:
	/* 0x19bf: add    r13,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_19c3:
	/* 0x19c3: jmp    1cf2 <generic_uprobe_process_event+0x1cf2> */
	return 7410ULL;
x86_l_19c8:
	/* 0x19c8: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19cd:
	/* 0x19cd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19d0:
	/* 0x19d0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19d5:
	/* 0x19d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19da:
	/* 0x19da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19df:
	/* 0x19df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e1:
	/* 0x19e1: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19e6:
	/* 0x19e6: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_19ea:
	/* 0x19ea: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19ef:
	/* 0x19ef: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19f4:
	/* 0x19f4: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_19fa:
	/* 0x19fa: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_19fe:
	/* 0x19fe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a03:
	/* 0x1a03: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a08:
	/* 0x1a08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a0d:
	/* 0x1a0d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1a10:
	/* 0x1a10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a12:
	/* 0x1a12: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a16:
	/* 0x1a16: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a1b:
	/* 0x1a1b: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a20:
	/* 0x1a20: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a25:
	/* 0x1a25: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a2a:
	/* 0x1a2a: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1a2f:
	/* 0x1a2f: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a34:
	/* 0x1a34: jne    1a41 <generic_uprobe_process_event+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a41;
	}
x86_l_1a36:
	/* 0x1a36: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1a3b:
	/* 0x1a3b: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_1a41:
	/* 0x1a41: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1a46:
	/* 0x1a46: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a4b:
	/* 0x1a4b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a50:
	/* 0x1a50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a55:
	/* 0x1a55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a57:
	/* 0x1a57: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_1a5c:
	/* 0x1a5c: je     1d09 <generic_uprobe_process_event+0x1d09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7433ULL;
	}
x86_l_1a62:
	/* 0x1a62: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a66:
	/* 0x1a66: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a69:
	/* 0x1a69: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a6e:
	/* 0x1a6e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a73:
	/* 0x1a73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a78:
	/* 0x1a78: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1a7b:
	/* 0x1a7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a7d:
	/* 0x1a7d: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a81:
	/* 0x1a81: je     1d09 <generic_uprobe_process_event+0x1d09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7433ULL;
	}
x86_l_1a87:
	/* 0x1a87: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1a8c:
	/* 0x1a8c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a91:
	/* 0x1a91: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a96:
	/* 0x1a96: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1a9e:
	/* 0x1a9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa0:
	/* 0x1aa0: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1aa4:
	/* 0x1aa4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aa9:
	/* 0x1aa9: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1aae:
	/* 0x1aae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ab3:
	/* 0x1ab3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ab8:
	/* 0x1ab8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1abb:
	/* 0x1abb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1abd:
	/* 0x1abd: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ac2:
	/* 0x1ac2: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ac7:
	/* 0x1ac7: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1acb:
	/* 0x1acb: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1ace:
	/* 0x1ace: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ad3:
	/* 0x1ad3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ad5:
	/* 0x1ad5: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1ad7:
	/* 0x1ad7: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ada:
	/* 0x1ada: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1add:
	/* 0x1add: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1ae2:
	/* 0x1ae2: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ae4:
	/* 0x1ae4: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1ae7:
	/* 0x1ae7: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_1aeb:
	/* 0x1aeb: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1aed:
	/* 0x1aed: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_1af1:
	/* 0x1af1: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1af3:
	/* 0x1af3: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_1af6:
	/* 0x1af6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1af8:
	/* 0x1af8: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1afc:
	/* 0x1afc: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1aff:
	/* 0x1aff: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b04:
	/* 0x1b04: jb     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3478ULL;
	}
x86_l_1b0a:
	/* 0x1b0a: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_1b10:
	/* 0x1b10: ja     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3478ULL;
	}
x86_l_1b16:
	/* 0x1b16: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1b19:
	/* 0x1b19: jbe    1b20 <generic_uprobe_process_event+0x1b20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1b20;
	}
x86_l_1b1b:
	/* 0x1b1b: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1b20:
	/* 0x1b20: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b22:
	/* 0x1b22: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1b25:
	/* 0x1b25: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_1b29:
	/* 0x1b29: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b2c:
	/* 0x1b2c: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b2f:
	/* 0x1b2f: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b32:
	/* 0x1b32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b37:
	/* 0x1b37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b39:
	/* 0x1b39: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
	return 6974ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6974ULL: goto x86_l_1b3e;
	case 6977ULL: goto x86_l_1b41;
	case 6982ULL: goto x86_l_1b46;
	case 6988ULL: goto x86_l_1b4c;
	case 6993ULL: goto x86_l_1b51;
	case 6998ULL: goto x86_l_1b56;
	case 7003ULL: goto x86_l_1b5b;
	case 7008ULL: goto x86_l_1b60;
	case 7013ULL: goto x86_l_1b65;
	case 7020ULL: goto x86_l_1b6c;
	case 7025ULL: goto x86_l_1b71;
	case 7030ULL: goto x86_l_1b76;
	case 7038ULL: goto x86_l_1b7e;
	case 7044ULL: goto x86_l_1b84;
	case 7051ULL: goto x86_l_1b8b;
	case 7056ULL: goto x86_l_1b90;
	case 7061ULL: goto x86_l_1b95;
	case 7069ULL: goto x86_l_1b9d;
	case 7072ULL: goto x86_l_1ba0;
	case 7077ULL: goto x86_l_1ba5;
	case 7079ULL: goto x86_l_1ba7;
	case 7082ULL: goto x86_l_1baa;
	case 7088ULL: goto x86_l_1bb0;
	case 7091ULL: goto x86_l_1bb3;
	case 7095ULL: goto x86_l_1bb7;
	case 7099ULL: goto x86_l_1bbb;
	case 7103ULL: goto x86_l_1bbf;
	case 7106ULL: goto x86_l_1bc2;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7119ULL: goto x86_l_1bcf;
	case 7124ULL: goto x86_l_1bd4;
	case 7129ULL: goto x86_l_1bd9;
	case 7132ULL: goto x86_l_1bdc;
	case 7137ULL: goto x86_l_1be1;
	case 7139ULL: goto x86_l_1be3;
	case 7142ULL: goto x86_l_1be6;
	case 7148ULL: goto x86_l_1bec;
	case 7152ULL: goto x86_l_1bf0;
	case 7155ULL: goto x86_l_1bf3;
	case 7161ULL: goto x86_l_1bf9;
	case 7163ULL: goto x86_l_1bfb;
	case 7169ULL: goto x86_l_1c01;
	case 7172ULL: goto x86_l_1c04;
	case 7178ULL: goto x86_l_1c0a;
	case 7181ULL: goto x86_l_1c0d;
	case 7187ULL: goto x86_l_1c13;
	case 7193ULL: goto x86_l_1c19;
	case 7197ULL: goto x86_l_1c1d;
	case 7202ULL: goto x86_l_1c22;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7221ULL: goto x86_l_1c35;
	case 7226ULL: goto x86_l_1c3a;
	case 7228ULL: goto x86_l_1c3c;
	case 7232ULL: goto x86_l_1c40;
	case 7237ULL: goto x86_l_1c45;
	case 7242ULL: goto x86_l_1c4a;
	case 7245ULL: goto x86_l_1c4d;
	case 7250ULL: goto x86_l_1c52;
	case 7252ULL: goto x86_l_1c54;
	case 7257ULL: goto x86_l_1c59;
	case 7261ULL: goto x86_l_1c5d;
	case 7265ULL: goto x86_l_1c61;
	case 7269ULL: goto x86_l_1c65;
	case 7274ULL: goto x86_l_1c6a;
	case 7279ULL: goto x86_l_1c6f;
	case 7284ULL: goto x86_l_1c74;
	case 7287ULL: goto x86_l_1c77;
	case 7289ULL: goto x86_l_1c79;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7303ULL: goto x86_l_1c87;
	case 7308ULL: goto x86_l_1c8c;
	case 7311ULL: goto x86_l_1c8f;
	case 7313ULL: goto x86_l_1c91;
	case 7318ULL: goto x86_l_1c96;
	case 7325ULL: goto x86_l_1c9d;
	case 7330ULL: goto x86_l_1ca2;
	case 7335ULL: goto x86_l_1ca7;
	case 7339ULL: goto x86_l_1cab;
	case 7344ULL: goto x86_l_1cb0;
	case 7349ULL: goto x86_l_1cb5;
	case 7354ULL: goto x86_l_1cba;
	case 7359ULL: goto x86_l_1cbf;
	case 7361ULL: goto x86_l_1cc1;
	case 7365ULL: goto x86_l_1cc5;
	case 7369ULL: goto x86_l_1cc9;
	case 7374ULL: goto x86_l_1cce;
	case 7379ULL: goto x86_l_1cd3;
	case 7384ULL: goto x86_l_1cd8;
	case 7387ULL: goto x86_l_1cdb;
	case 7389ULL: goto x86_l_1cdd;
	case 7394ULL: goto x86_l_1ce2;
	case 7398ULL: goto x86_l_1ce6;
	case 7404ULL: goto x86_l_1cec;
	case 7410ULL: goto x86_l_1cf2;
	case 7413ULL: goto x86_l_1cf5;
	case 7418ULL: goto x86_l_1cfa;
	case 7423ULL: goto x86_l_1cff;
	case 7428ULL: goto x86_l_1d04;
	case 7433ULL: goto x86_l_1d09;
	case 7438ULL: goto x86_l_1d0e;
	case 7441ULL: goto x86_l_1d11;
	case 7446ULL: goto x86_l_1d16;
	case 7451ULL: goto x86_l_1d1b;
	case 7456ULL: goto x86_l_1d20;
	case 7458ULL: goto x86_l_1d22;
	case 7463ULL: goto x86_l_1d27;
	case 7467ULL: goto x86_l_1d2b;
	case 7472ULL: goto x86_l_1d30;
	case 7477ULL: goto x86_l_1d35;
	case 7483ULL: goto x86_l_1d3b;
	case 7487ULL: goto x86_l_1d3f;
	case 7492ULL: goto x86_l_1d44;
	case 7497ULL: goto x86_l_1d49;
	case 7502ULL: goto x86_l_1d4e;
	case 7505ULL: goto x86_l_1d51;
	case 7507ULL: goto x86_l_1d53;
	case 7511ULL: goto x86_l_1d57;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7531ULL: goto x86_l_1d6b;
	case 7536ULL: goto x86_l_1d70;
	case 7541ULL: goto x86_l_1d75;
	case 7543ULL: goto x86_l_1d77;
	case 7548ULL: goto x86_l_1d7c;
	case 7554ULL: goto x86_l_1d82;
	case 7559ULL: goto x86_l_1d87;
	case 7564ULL: goto x86_l_1d8c;
	case 7569ULL: goto x86_l_1d91;
	case 7574ULL: goto x86_l_1d96;
	case 7576ULL: goto x86_l_1d98;
	case 7581ULL: goto x86_l_1d9d;
	case 7587ULL: goto x86_l_1da3;
	case 7591ULL: goto x86_l_1da7;
	case 7594ULL: goto x86_l_1daa;
	case 7599ULL: goto x86_l_1daf;
	case 7604ULL: goto x86_l_1db4;
	case 7609ULL: goto x86_l_1db9;
	case 7612ULL: goto x86_l_1dbc;
	case 7614ULL: goto x86_l_1dbe;
	case 7618ULL: goto x86_l_1dc2;
	case 7624ULL: goto x86_l_1dc8;
	case 7629ULL: goto x86_l_1dcd;
	case 7634ULL: goto x86_l_1dd2;
	case 7639ULL: goto x86_l_1dd7;
	case 7644ULL: goto x86_l_1ddc;
	case 7647ULL: goto x86_l_1ddf;
	case 7649ULL: goto x86_l_1de1;
	case 7653ULL: goto x86_l_1de5;
	case 7658ULL: goto x86_l_1dea;
	case 7663ULL: goto x86_l_1def;
	case 7668ULL: goto x86_l_1df4;
	case 7673ULL: goto x86_l_1df9;
	case 7676ULL: goto x86_l_1dfc;
	case 7678ULL: goto x86_l_1dfe;
	case 7683ULL: goto x86_l_1e03;
	case 7688ULL: goto x86_l_1e08;
	case 7692ULL: goto x86_l_1e0c;
	case 7695ULL: goto x86_l_1e0f;
	case 7700ULL: goto x86_l_1e14;
	case 7702ULL: goto x86_l_1e16;
	case 7704ULL: goto x86_l_1e18;
	case 7707ULL: goto x86_l_1e1b;
	case 7710ULL: goto x86_l_1e1e;
	case 7715ULL: goto x86_l_1e23;
	case 7717ULL: goto x86_l_1e25;
	case 7720ULL: goto x86_l_1e28;
	case 7724ULL: goto x86_l_1e2c;
	case 7726ULL: goto x86_l_1e2e;
	case 7730ULL: goto x86_l_1e32;
	case 7732ULL: goto x86_l_1e34;
	case 7735ULL: goto x86_l_1e37;
	case 7737ULL: goto x86_l_1e39;
	case 7741ULL: goto x86_l_1e3d;
	case 7744ULL: goto x86_l_1e40;
	case 7749ULL: goto x86_l_1e45;
	case 7755ULL: goto x86_l_1e4b;
	case 7761ULL: goto x86_l_1e51;
	case 7767ULL: goto x86_l_1e57;
	case 7770ULL: goto x86_l_1e5a;
	case 7772ULL: goto x86_l_1e5c;
	case 7777ULL: goto x86_l_1e61;
	case 7779ULL: goto x86_l_1e63;
	case 7782ULL: goto x86_l_1e66;
	case 7786ULL: goto x86_l_1e6a;
	case 7789ULL: goto x86_l_1e6d;
	case 7792ULL: goto x86_l_1e70;
	case 7795ULL: goto x86_l_1e73;
	case 7800ULL: goto x86_l_1e78;
	case 7802ULL: goto x86_l_1e7a;
	case 7807ULL: goto x86_l_1e7f;
	case 7810ULL: goto x86_l_1e82;
	case 7815ULL: goto x86_l_1e87;
	case 7821ULL: goto x86_l_1e8d;
	case 7826ULL: goto x86_l_1e92;
	case 7831ULL: goto x86_l_1e97;
	case 7836ULL: goto x86_l_1e9c;
	case 7841ULL: goto x86_l_1ea1;
	case 7846ULL: goto x86_l_1ea6;
	case 7849ULL: goto x86_l_1ea9;
	case 7855ULL: goto x86_l_1eaf;
	case 7858ULL: goto x86_l_1eb2;
	case 7860ULL: goto x86_l_1eb4;
	case 7865ULL: goto x86_l_1eb9;
	case 7871ULL: goto x86_l_1ebf;
	case 7877ULL: goto x86_l_1ec5;
	case 7881ULL: goto x86_l_1ec9;
	case 7886ULL: goto x86_l_1ece;
	case 7890ULL: goto x86_l_1ed2;
	case 7897ULL: goto x86_l_1ed9;
	case 7902ULL: goto x86_l_1ede;
	case 7907ULL: goto x86_l_1ee3;
	case 7910ULL: goto x86_l_1ee6;
	case 7915ULL: goto x86_l_1eeb;
	case 7920ULL: goto x86_l_1ef0;
	case 7925ULL: goto x86_l_1ef5;
	case 7927ULL: goto x86_l_1ef7;
	case 7932ULL: goto x86_l_1efc;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7946ULL: goto x86_l_1f0a;
	case 7952ULL: goto x86_l_1f10;
	case 7956ULL: goto x86_l_1f14;
	case 7961ULL: goto x86_l_1f19;
	case 7966ULL: goto x86_l_1f1e;
	case 7971ULL: goto x86_l_1f23;
	case 7974ULL: goto x86_l_1f26;
	case 7976ULL: goto x86_l_1f28;
	case 7980ULL: goto x86_l_1f2c;
	case 7985ULL: goto x86_l_1f31;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8012ULL: goto x86_l_1f4c;
	case 8017ULL: goto x86_l_1f51;
	case 8023ULL: goto x86_l_1f57;
	case 8028ULL: goto x86_l_1f5c;
	case 8033ULL: goto x86_l_1f61;
	case 8038ULL: goto x86_l_1f66;
	case 8043ULL: goto x86_l_1f6b;
	case 8045ULL: goto x86_l_1f6d;
	case 8050ULL: goto x86_l_1f72;
	case 8056ULL: goto x86_l_1f78;
	case 8060ULL: goto x86_l_1f7c;
	case 8063ULL: goto x86_l_1f7f;
	case 8068ULL: goto x86_l_1f84;
	case 8073ULL: goto x86_l_1f89;
	case 8078ULL: goto x86_l_1f8e;
	case 8081ULL: goto x86_l_1f91;
	case 8083ULL: goto x86_l_1f93;
	case 8087ULL: goto x86_l_1f97;
	case 8093ULL: goto x86_l_1f9d;
	case 8098ULL: goto x86_l_1fa2;
	case 8103ULL: goto x86_l_1fa7;
	case 8108ULL: goto x86_l_1fac;
	case 8113ULL: goto x86_l_1fb1;
	case 8116ULL: goto x86_l_1fb4;
	case 8118ULL: goto x86_l_1fb6;
	case 8122ULL: goto x86_l_1fba;
	case 8127ULL: goto x86_l_1fbf;
	case 8132ULL: goto x86_l_1fc4;
	case 8137ULL: goto x86_l_1fc9;
	case 8142ULL: goto x86_l_1fce;
	case 8145ULL: goto x86_l_1fd1;
	case 8147ULL: goto x86_l_1fd3;
	case 8152ULL: goto x86_l_1fd8;
	case 8157ULL: goto x86_l_1fdd;
	case 8161ULL: goto x86_l_1fe1;
	case 8164ULL: goto x86_l_1fe4;
	case 8169ULL: goto x86_l_1fe9;
	case 8171ULL: goto x86_l_1feb;
	case 8173ULL: goto x86_l_1fed;
	case 8176ULL: goto x86_l_1ff0;
	case 8179ULL: goto x86_l_1ff3;
	case 8184ULL: goto x86_l_1ff8;
	case 8186ULL: goto x86_l_1ffa;
	case 8189ULL: goto x86_l_1ffd;
	case 8193ULL: goto x86_l_2001;
	case 8195ULL: goto x86_l_2003;
	case 8199ULL: goto x86_l_2007;
	case 8201ULL: goto x86_l_2009;
	case 8204ULL: goto x86_l_200c;
	case 8206ULL: goto x86_l_200e;
	case 8210ULL: goto x86_l_2012;
	case 8213ULL: goto x86_l_2015;
	case 8218ULL: goto x86_l_201a;
	case 8224ULL: goto x86_l_2020;
	case 8230ULL: goto x86_l_2026;
	case 8236ULL: goto x86_l_202c;
	case 8239ULL: goto x86_l_202f;
	case 8241ULL: goto x86_l_2031;
	case 8246ULL: goto x86_l_2036;
	case 8248ULL: goto x86_l_2038;
	case 8251ULL: goto x86_l_203b;
	case 8255ULL: goto x86_l_203f;
	case 8258ULL: goto x86_l_2042;
	case 8261ULL: goto x86_l_2045;
	case 8264ULL: goto x86_l_2048;
	case 8269ULL: goto x86_l_204d;
	case 8271ULL: goto x86_l_204f;
	case 8276ULL: goto x86_l_2054;
	case 8279ULL: goto x86_l_2057;
	case 8284ULL: goto x86_l_205c;
	case 8290ULL: goto x86_l_2062;
	case 8295ULL: goto x86_l_2067;
	case 8300ULL: goto x86_l_206c;
	case 8305ULL: goto x86_l_2071;
	case 8310ULL: goto x86_l_2076;
	case 8315ULL: goto x86_l_207b;
	case 8319ULL: goto x86_l_207f;
	case 8326ULL: goto x86_l_2086;
	case 8330ULL: goto x86_l_208a;
	case 8334ULL: goto x86_l_208e;
	case 8338ULL: goto x86_l_2092;
	case 8343ULL: goto x86_l_2097;
	case 8347ULL: goto x86_l_209b;
	case 8353ULL: goto x86_l_20a1;
	case 8363ULL: goto x86_l_20ab;
	case 8367ULL: goto x86_l_20af;
	case 8373ULL: goto x86_l_20b5;
	case 8377ULL: goto x86_l_20b9;
	case 8380ULL: goto x86_l_20bc;
	case 8388ULL: goto x86_l_20c4;
	case 8391ULL: goto x86_l_20c7;
	case 8396ULL: goto x86_l_20cc;
	case 8401ULL: goto x86_l_20d1;
	case 8405ULL: goto x86_l_20d5;
	case 8408ULL: goto x86_l_20d8;
	case 8411ULL: goto x86_l_20db;
	case 8416ULL: goto x86_l_20e0;
	case 8418ULL: goto x86_l_20e2;
	case 8421ULL: goto x86_l_20e5;
	case 8427ULL: goto x86_l_20eb;
	case 8431ULL: goto x86_l_20ef;
	case 8434ULL: goto x86_l_20f2;
	case 8436ULL: goto x86_l_20f4;
	case 8438ULL: goto x86_l_20f6;
	case 8440ULL: goto x86_l_20f8;
	case 8443ULL: goto x86_l_20fb;
	case 8445ULL: goto x86_l_20fd;
	case 8448ULL: goto x86_l_2100;
	case 8450ULL: goto x86_l_2102;
	case 8456ULL: goto x86_l_2108;
	case 8460ULL: goto x86_l_210c;
	case 8462ULL: goto x86_l_210e;
	case 8465ULL: goto x86_l_2111;
	case 8467ULL: goto x86_l_2113;
	case 8470ULL: goto x86_l_2116;
	case 8472ULL: goto x86_l_2118;
	case 8477ULL: goto x86_l_211d;
	case 8479ULL: goto x86_l_211f;
	case 8485ULL: goto x86_l_2125;
	case 8489ULL: goto x86_l_2129;
	case 8491ULL: goto x86_l_212b;
	case 8495ULL: goto x86_l_212f;
	case 8502ULL: goto x86_l_2136;
	case 8506ULL: goto x86_l_213a;
	case 8508ULL: goto x86_l_213c;
	case 8512ULL: goto x86_l_2140;
	case 8517ULL: goto x86_l_2145;
	case 8521ULL: goto x86_l_2149;
	case 8528ULL: goto x86_l_2150;
	case 8532ULL: goto x86_l_2154;
	case 8534ULL: goto x86_l_2156;
	case 8538ULL: goto x86_l_215a;
	case 8542ULL: goto x86_l_215e;
	case 8546ULL: goto x86_l_2162;
	case 8551ULL: goto x86_l_2167;
	case 8555ULL: goto x86_l_216b;
	case 8561ULL: goto x86_l_2171;
	case 8571ULL: goto x86_l_217b;
	case 8575ULL: goto x86_l_217f;
	case 8581ULL: goto x86_l_2185;
	case 8585ULL: goto x86_l_2189;
	case 8588ULL: goto x86_l_218c;
	case 8596ULL: goto x86_l_2194;
	case 8599ULL: goto x86_l_2197;
	case 8604ULL: goto x86_l_219c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b3e:
	/* 0x1b3e: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1b41:
	/* 0x1b41: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b46:
	/* 0x1b46: jbe    d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3478ULL;
	}
x86_l_1b4c:
	/* 0x1b4c: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1b51:
	/* 0x1b51: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b56:
	/* 0x1b56: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b5b:
	/* 0x1b5b: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b60:
	/* 0x1b60: jmp    1d6b <generic_uprobe_process_event+0x1d6b> */
	goto x86_l_1d6b;
x86_l_1b65:
	/* 0x1b65: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1b6c:
	/* 0x1b6c: jmp    2ab6 <generic_uprobe_process_event+0x2ab6> */
	return 10934ULL;
x86_l_1b71:
	/* 0x1b71: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b76:
	/* 0x1b76: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1b7e:
	/* 0x1b7e: movzx  r15d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_1b84:
	/* 0x1b84: mov    rdi,QWORD PTR [rip+0x21a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1b8b:
	/* 0x1b8b: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b90:
	/* 0x1b90: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b95:
	/* 0x1b95: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b9d:
	/* 0x1b9d: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ba0:
	/* 0x1ba0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ba5:
	/* 0x1ba5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba7:
	/* 0x1ba7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1baa:
	/* 0x1baa: je     28f9 <generic_uprobe_process_event+0x28f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10489ULL;
	}
x86_l_1bb0:
	/* 0x1bb0: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1bb3:
	/* 0x1bb3: mov    WORD PTR [rax],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb7:
	/* 0x1bb7: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1bbb:
	/* 0x1bbb: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1bbf:
	/* 0x1bbf: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1bc2:
	/* 0x1bc2: add    r15,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1bc6:
	/* 0x1bc6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bcb:
	/* 0x1bcb: lea    rdx,[rax+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1bcf:
	/* 0x1bcf: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1bd4:
	/* 0x1bd4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bd9:
	/* 0x1bd9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1bdc:
	/* 0x1bdc: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1be1:
	/* 0x1be1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be3:
	/* 0x1be3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1be6:
	/* 0x1be6: js     28f9 <generic_uprobe_process_event+0x28f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10489ULL;
	}
x86_l_1bec:
	/* 0x1bec: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1bf0:
	/* 0x1bf0: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1bf3:
	/* 0x1bf3: jg     1ea6 <generic_uprobe_process_event+0x1ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ea6;
	}
x86_l_1bf9:
	/* 0x1bf9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bfb:
	/* 0x1bfb: je     1ece <generic_uprobe_process_event+0x1ece> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ece;
	}
x86_l_1c01:
	/* 0x1c01: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1c04:
	/* 0x1c04: je     1ece <generic_uprobe_process_event+0x1ece> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ece;
	}
x86_l_1c0a:
	/* 0x1c0a: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1c0d:
	/* 0x1c0d: jne    213c <generic_uprobe_process_event+0x213c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_213c;
	}
x86_l_1c13:
	/* 0x1c13: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1c19:
	/* 0x1c19: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1c1d:
	/* 0x1c1d: jmp    208a <generic_uprobe_process_event+0x208a> */
	goto x86_l_208a;
x86_l_1c22:
	/* 0x1c22: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c26:
	/* 0x1c26: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1c2b:
	/* 0x1c2b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c30:
	/* 0x1c30: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c35:
	/* 0x1c35: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c3a:
	/* 0x1c3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c3c:
	/* 0x1c3c: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c40:
	/* 0x1c40: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1c45:
	/* 0x1c45: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c4a:
	/* 0x1c4a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1c4d:
	/* 0x1c4d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c52:
	/* 0x1c52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c54:
	/* 0x1c54: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c59:
	/* 0x1c59: lea    rdi,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c5d:
	/* 0x1c5d: lea    r12,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c61:
	/* 0x1c61: add    r13,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1c65:
	/* 0x1c65: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c6a:
	/* 0x1c6a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c6f:
	/* 0x1c6f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1c74:
	/* 0x1c74: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1c77:
	/* 0x1c77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c79:
	/* 0x1c79: lea    rdi,[r15+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1c7d:
	/* 0x1c7d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c82:
	/* 0x1c82: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c87:
	/* 0x1c87: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1c8c:
	/* 0x1c8c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c8f:
	/* 0x1c8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c91:
	/* 0x1c91: movzx  eax,WORD PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1c96:
	/* 0x1c96: movbe  WORD PTR [r15+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1c9d:
	/* 0x1c9d: jmp    2ab0 <generic_uprobe_process_event+0x2ab0> */
	return 10928ULL;
x86_l_1ca2:
	/* 0x1ca2: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ca7:
	/* 0x1ca7: lea    rdi,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cab:
	/* 0x1cab: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cb0:
	/* 0x1cb0: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1cb5:
	/* 0x1cb5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cba:
	/* 0x1cba: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1cbf:
	/* 0x1cbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc1:
	/* 0x1cc1: lea    rdi,[rbx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1cc5:
	/* 0x1cc5: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1cc9:
	/* 0x1cc9: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1cce:
	/* 0x1cce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cd3:
	/* 0x1cd3: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1cd8:
	/* 0x1cd8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1cdb:
	/* 0x1cdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cdd:
	/* 0x1cdd: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ce2:
	/* 0x1ce2: movzx  eax,WORD PTR [rcx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1ce6:
	/* 0x1ce6: movbe  WORD PTR [rcx+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1cec:
	/* 0x1cec: mov    r13d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 24ULL);
x86_l_1cf2:
	/* 0x1cf2: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1cf5:
	/* 0x1cf5: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1cfa:
	/* 0x1cfa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cff:
	/* 0x1cff: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d04:
	/* 0x1d04: jmp    fb0 <generic_uprobe_process_event+0xfb0> */
	return 4016ULL;
x86_l_1d09:
	/* 0x1d09: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d0e:
	/* 0x1d0e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d11:
	/* 0x1d11: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d16:
	/* 0x1d16: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d1b:
	/* 0x1d1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d20:
	/* 0x1d20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d22:
	/* 0x1d22: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d27:
	/* 0x1d27: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1d2b:
	/* 0x1d2b: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d30:
	/* 0x1d30: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d35:
	/* 0x1d35: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_1d3b:
	/* 0x1d3b: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1d3f:
	/* 0x1d3f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d44:
	/* 0x1d44: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d49:
	/* 0x1d49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d4e:
	/* 0x1d4e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d51:
	/* 0x1d51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d53:
	/* 0x1d53: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d57:
	/* 0x1d57: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d5c:
	/* 0x1d5c: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d61:
	/* 0x1d61: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d66:
	/* 0x1d66: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d6b:
	/* 0x1d6b: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1d70:
	/* 0x1d70: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d75:
	/* 0x1d75: jne    1d82 <generic_uprobe_process_event+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d82;
	}
x86_l_1d77:
	/* 0x1d77: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1d7c:
	/* 0x1d7c: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_1d82:
	/* 0x1d82: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d87:
	/* 0x1d87: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d8c:
	/* 0x1d8c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d91:
	/* 0x1d91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d96:
	/* 0x1d96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d98:
	/* 0x1d98: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_1d9d:
	/* 0x1d9d: je     1ede <generic_uprobe_process_event+0x1ede> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ede;
	}
x86_l_1da3:
	/* 0x1da3: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1da7:
	/* 0x1da7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1daa:
	/* 0x1daa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1daf:
	/* 0x1daf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1db4:
	/* 0x1db4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1db9:
	/* 0x1db9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1dbc:
	/* 0x1dbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dbe:
	/* 0x1dbe: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dc2:
	/* 0x1dc2: je     1ede <generic_uprobe_process_event+0x1ede> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ede;
	}
x86_l_1dc8:
	/* 0x1dc8: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1dcd:
	/* 0x1dcd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1dd2:
	/* 0x1dd2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dd7:
	/* 0x1dd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ddc:
	/* 0x1ddc: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1ddf:
	/* 0x1ddf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de1:
	/* 0x1de1: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1de5:
	/* 0x1de5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dea:
	/* 0x1dea: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1def:
	/* 0x1def: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1df4:
	/* 0x1df4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1df9:
	/* 0x1df9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1dfc:
	/* 0x1dfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dfe:
	/* 0x1dfe: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e03:
	/* 0x1e03: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e08:
	/* 0x1e08: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1e0c:
	/* 0x1e0c: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1e0f:
	/* 0x1e0f: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e14:
	/* 0x1e14: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e16:
	/* 0x1e16: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1e18:
	/* 0x1e18: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e1b:
	/* 0x1e1b: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1e1e:
	/* 0x1e1e: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1e23:
	/* 0x1e23: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e25:
	/* 0x1e25: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1e28:
	/* 0x1e28: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_1e2c:
	/* 0x1e2c: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1e2e:
	/* 0x1e2e: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_1e32:
	/* 0x1e32: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e34:
	/* 0x1e34: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_1e37:
	/* 0x1e37: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e39:
	/* 0x1e39: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e3d:
	/* 0x1e3d: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1e40:
	/* 0x1e40: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e45:
	/* 0x1e45: jb     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3478ULL;
	}
x86_l_1e4b:
	/* 0x1e4b: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_1e51:
	/* 0x1e51: ja     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3478ULL;
	}
x86_l_1e57:
	/* 0x1e57: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1e5a:
	/* 0x1e5a: jbe    1e61 <generic_uprobe_process_event+0x1e61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e61;
	}
x86_l_1e5c:
	/* 0x1e5c: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1e61:
	/* 0x1e61: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e63:
	/* 0x1e63: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1e66:
	/* 0x1e66: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_1e6a:
	/* 0x1e6a: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e6d:
	/* 0x1e6d: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e70:
	/* 0x1e70: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e73:
	/* 0x1e73: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e78:
	/* 0x1e78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e7a:
	/* 0x1e7a: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e7f:
	/* 0x1e7f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1e82:
	/* 0x1e82: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e87:
	/* 0x1e87: jbe    d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3478ULL;
	}
x86_l_1e8d:
	/* 0x1e8d: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1e92:
	/* 0x1e92: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e97:
	/* 0x1e97: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e9c:
	/* 0x1e9c: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ea1:
	/* 0x1ea1: jmp    1f40 <generic_uprobe_process_event+0x1f40> */
	goto x86_l_1f40;
x86_l_1ea6:
	/* 0x1ea6: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_1ea9:
	/* 0x1ea9: je     207b <generic_uprobe_process_event+0x207b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_207b;
	}
x86_l_1eaf:
	/* 0x1eaf: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1eb2:
	/* 0x1eb2: je     1ece <generic_uprobe_process_event+0x1ece> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ece;
	}
x86_l_1eb4:
	/* 0x1eb4: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_1eb9:
	/* 0x1eb9: jne    213c <generic_uprobe_process_event+0x213c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_213c;
	}
x86_l_1ebf:
	/* 0x1ebf: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_1ec5:
	/* 0x1ec5: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_1ec9:
	/* 0x1ec9: jmp    208a <generic_uprobe_process_event+0x208a> */
	goto x86_l_208a;
x86_l_1ece:
	/* 0x1ece: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_1ed2:
	/* 0x1ed2: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_1ed9:
	/* 0x1ed9: jmp    2086 <generic_uprobe_process_event+0x2086> */
	goto x86_l_2086;
x86_l_1ede:
	/* 0x1ede: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ee3:
	/* 0x1ee3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1ee6:
	/* 0x1ee6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1eeb:
	/* 0x1eeb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ef0:
	/* 0x1ef0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ef5:
	/* 0x1ef5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef7:
	/* 0x1ef7: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1efc:
	/* 0x1efc: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1f00:
	/* 0x1f00: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f05:
	/* 0x1f05: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f0a:
	/* 0x1f0a: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_1f10:
	/* 0x1f10: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1f14:
	/* 0x1f14: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f19:
	/* 0x1f19: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f1e:
	/* 0x1f1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f23:
	/* 0x1f23: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f26:
	/* 0x1f26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f28:
	/* 0x1f28: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f2c:
	/* 0x1f2c: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f31:
	/* 0x1f31: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f36:
	/* 0x1f36: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f3b:
	/* 0x1f3b: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f40:
	/* 0x1f40: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1f45:
	/* 0x1f45: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f4a:
	/* 0x1f4a: jne    1f57 <generic_uprobe_process_event+0x1f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f57;
	}
x86_l_1f4c:
	/* 0x1f4c: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1f51:
	/* 0x1f51: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_1f57:
	/* 0x1f57: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f5c:
	/* 0x1f5c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f61:
	/* 0x1f61: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f66:
	/* 0x1f66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f6b:
	/* 0x1f6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f6d:
	/* 0x1f6d: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_1f72:
	/* 0x1f72: je     2221 <generic_uprobe_process_event+0x2221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8737ULL;
	}
x86_l_1f78:
	/* 0x1f78: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f7c:
	/* 0x1f7c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1f7f:
	/* 0x1f7f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f84:
	/* 0x1f84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f89:
	/* 0x1f89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f8e:
	/* 0x1f8e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1f91:
	/* 0x1f91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f93:
	/* 0x1f93: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f97:
	/* 0x1f97: je     2221 <generic_uprobe_process_event+0x2221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8737ULL;
	}
x86_l_1f9d:
	/* 0x1f9d: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1fa2:
	/* 0x1fa2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1fa7:
	/* 0x1fa7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fac:
	/* 0x1fac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fb1:
	/* 0x1fb1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1fb4:
	/* 0x1fb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb6:
	/* 0x1fb6: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1fba:
	/* 0x1fba: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fbf:
	/* 0x1fbf: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1fc4:
	/* 0x1fc4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fc9:
	/* 0x1fc9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1fce:
	/* 0x1fce: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1fd1:
	/* 0x1fd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd3:
	/* 0x1fd3: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1fd8:
	/* 0x1fd8: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1fdd:
	/* 0x1fdd: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1fe1:
	/* 0x1fe1: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1fe4:
	/* 0x1fe4: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1fe9:
	/* 0x1fe9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1feb:
	/* 0x1feb: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1fed:
	/* 0x1fed: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ff0:
	/* 0x1ff0: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1ff3:
	/* 0x1ff3: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1ff8:
	/* 0x1ff8: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ffa:
	/* 0x1ffa: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1ffd:
	/* 0x1ffd: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2001:
	/* 0x2001: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2003:
	/* 0x2003: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2007:
	/* 0x2007: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2009:
	/* 0x2009: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_200c:
	/* 0x200c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_200e:
	/* 0x200e: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2012:
	/* 0x2012: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2015:
	/* 0x2015: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_201a:
	/* 0x201a: jb     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3478ULL;
	}
x86_l_2020:
	/* 0x2020: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2026:
	/* 0x2026: ja     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3478ULL;
	}
x86_l_202c:
	/* 0x202c: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_202f:
	/* 0x202f: jbe    2036 <generic_uprobe_process_event+0x2036> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2036;
	}
x86_l_2031:
	/* 0x2031: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2036:
	/* 0x2036: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2038:
	/* 0x2038: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_203b:
	/* 0x203b: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_203f:
	/* 0x203f: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2042:
	/* 0x2042: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2045:
	/* 0x2045: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2048:
	/* 0x2048: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_204d:
	/* 0x204d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204f:
	/* 0x204f: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2054:
	/* 0x2054: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2057:
	/* 0x2057: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_205c:
	/* 0x205c: jbe    d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3478ULL;
	}
x86_l_2062:
	/* 0x2062: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2067:
	/* 0x2067: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_206c:
	/* 0x206c: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2071:
	/* 0x2071: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2076:
	/* 0x2076: jmp    2283 <generic_uprobe_process_event+0x2283> */
	return 8835ULL;
x86_l_207b:
	/* 0x207b: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_207f:
	/* 0x207f: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2086:
	/* 0x2086: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_208a:
	/* 0x208a: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_208e:
	/* 0x208e: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2092:
	/* 0x2092: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2097:
	/* 0x2097: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_209b:
	/* 0x209b: ja     2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10952ULL;
	}
x86_l_20a1:
	/* 0x20a1: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_20ab:
	/* 0x20ab: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_20af:
	/* 0x20af: jae    2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10952ULL;
	}
x86_l_20b5:
	/* 0x20b5: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_20b9:
	/* 0x20b9: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_20bc:
	/* 0x20bc: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_20c4:
	/* 0x20c4: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20c7:
	/* 0x20c7: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_20cc:
	/* 0x20cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20d1:
	/* 0x20d1: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20d5:
	/* 0x20d5: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20d8:
	/* 0x20d8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_20db:
	/* 0x20db: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_20e0:
	/* 0x20e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e2:
	/* 0x20e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20e5:
	/* 0x20e5: js     28f9 <generic_uprobe_process_event+0x28f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10489ULL;
	}
x86_l_20eb:
	/* 0x20eb: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_20ef:
	/* 0x20ef: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_20f2:
	/* 0x20f2: jg     210e <generic_uprobe_process_event+0x210e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_210e;
	}
x86_l_20f4:
	/* 0x20f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20f6:
	/* 0x20f6: je     212b <generic_uprobe_process_event+0x212b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_212b;
	}
x86_l_20f8:
	/* 0x20f8: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_20fb:
	/* 0x20fb: je     212b <generic_uprobe_process_event+0x212b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_212b;
	}
x86_l_20fd:
	/* 0x20fd: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2100:
	/* 0x2100: jne    2156 <generic_uprobe_process_event+0x2156> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2156;
	}
x86_l_2102:
	/* 0x2102: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2108:
	/* 0x2108: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_210c:
	/* 0x210c: jmp    215a <generic_uprobe_process_event+0x215a> */
	goto x86_l_215a;
x86_l_210e:
	/* 0x210e: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2111:
	/* 0x2111: je     2145 <generic_uprobe_process_event+0x2145> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2145;
	}
x86_l_2113:
	/* 0x2113: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2116:
	/* 0x2116: je     212b <generic_uprobe_process_event+0x212b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_212b;
	}
x86_l_2118:
	/* 0x2118: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_211d:
	/* 0x211d: jne    2156 <generic_uprobe_process_event+0x2156> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2156;
	}
x86_l_211f:
	/* 0x211f: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2125:
	/* 0x2125: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2129:
	/* 0x2129: jmp    215a <generic_uprobe_process_event+0x215a> */
	goto x86_l_215a;
x86_l_212b:
	/* 0x212b: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_212f:
	/* 0x212f: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2136:
	/* 0x2136: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_213a:
	/* 0x213a: jmp    215a <generic_uprobe_process_event+0x215a> */
	goto x86_l_215a;
x86_l_213c:
	/* 0x213c: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2140:
	/* 0x2140: jmp    208a <generic_uprobe_process_event+0x208a> */
	goto x86_l_208a;
x86_l_2145:
	/* 0x2145: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2149:
	/* 0x2149: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2150:
	/* 0x2150: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2154:
	/* 0x2154: jmp    215a <generic_uprobe_process_event+0x215a> */
	goto x86_l_215a;
x86_l_2156:
	/* 0x2156: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_215a:
	/* 0x215a: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_215e:
	/* 0x215e: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2162:
	/* 0x2162: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2167:
	/* 0x2167: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_216b:
	/* 0x216b: ja     2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10952ULL;
	}
x86_l_2171:
	/* 0x2171: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_217b:
	/* 0x217b: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_217f:
	/* 0x217f: jae    2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10952ULL;
	}
x86_l_2185:
	/* 0x2185: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2189:
	/* 0x2189: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_218c:
	/* 0x218c: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2194:
	/* 0x2194: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2197:
	/* 0x2197: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_219c:
	/* 0x219c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 8609ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8609ULL: goto x86_l_21a1;
	case 8613ULL: goto x86_l_21a5;
	case 8616ULL: goto x86_l_21a8;
	case 8619ULL: goto x86_l_21ab;
	case 8624ULL: goto x86_l_21b0;
	case 8626ULL: goto x86_l_21b2;
	case 8629ULL: goto x86_l_21b5;
	case 8635ULL: goto x86_l_21bb;
	case 8639ULL: goto x86_l_21bf;
	case 8642ULL: goto x86_l_21c2;
	case 8644ULL: goto x86_l_21c4;
	case 8646ULL: goto x86_l_21c6;
	case 8648ULL: goto x86_l_21c8;
	case 8651ULL: goto x86_l_21cb;
	case 8653ULL: goto x86_l_21cd;
	case 8656ULL: goto x86_l_21d0;
	case 8662ULL: goto x86_l_21d6;
	case 8668ULL: goto x86_l_21dc;
	case 8672ULL: goto x86_l_21e0;
	case 8677ULL: goto x86_l_21e5;
	case 8680ULL: goto x86_l_21e8;
	case 8686ULL: goto x86_l_21ee;
	case 8689ULL: goto x86_l_21f1;
	case 8691ULL: goto x86_l_21f3;
	case 8696ULL: goto x86_l_21f8;
	case 8702ULL: goto x86_l_21fe;
	case 8708ULL: goto x86_l_2204;
	case 8712ULL: goto x86_l_2208;
	case 8717ULL: goto x86_l_220d;
	case 8721ULL: goto x86_l_2211;
	case 8728ULL: goto x86_l_2218;
	case 8732ULL: goto x86_l_221c;
	case 8737ULL: goto x86_l_2221;
	case 8742ULL: goto x86_l_2226;
	case 8745ULL: goto x86_l_2229;
	case 8750ULL: goto x86_l_222e;
	case 8755ULL: goto x86_l_2233;
	case 8760ULL: goto x86_l_2238;
	case 8762ULL: goto x86_l_223a;
	case 8767ULL: goto x86_l_223f;
	case 8771ULL: goto x86_l_2243;
	case 8776ULL: goto x86_l_2248;
	case 8781ULL: goto x86_l_224d;
	case 8787ULL: goto x86_l_2253;
	case 8791ULL: goto x86_l_2257;
	case 8796ULL: goto x86_l_225c;
	case 8801ULL: goto x86_l_2261;
	case 8806ULL: goto x86_l_2266;
	case 8809ULL: goto x86_l_2269;
	case 8811ULL: goto x86_l_226b;
	case 8815ULL: goto x86_l_226f;
	case 8820ULL: goto x86_l_2274;
	case 8825ULL: goto x86_l_2279;
	case 8830ULL: goto x86_l_227e;
	case 8835ULL: goto x86_l_2283;
	case 8840ULL: goto x86_l_2288;
	case 8845ULL: goto x86_l_228d;
	case 8847ULL: goto x86_l_228f;
	case 8852ULL: goto x86_l_2294;
	case 8858ULL: goto x86_l_229a;
	case 8863ULL: goto x86_l_229f;
	case 8868ULL: goto x86_l_22a4;
	case 8873ULL: goto x86_l_22a9;
	case 8878ULL: goto x86_l_22ae;
	case 8880ULL: goto x86_l_22b0;
	case 8885ULL: goto x86_l_22b5;
	case 8891ULL: goto x86_l_22bb;
	case 8895ULL: goto x86_l_22bf;
	case 8898ULL: goto x86_l_22c2;
	case 8903ULL: goto x86_l_22c7;
	case 8908ULL: goto x86_l_22cc;
	case 8913ULL: goto x86_l_22d1;
	case 8916ULL: goto x86_l_22d4;
	case 8918ULL: goto x86_l_22d6;
	case 8922ULL: goto x86_l_22da;
	case 8928ULL: goto x86_l_22e0;
	case 8933ULL: goto x86_l_22e5;
	case 8938ULL: goto x86_l_22ea;
	case 8943ULL: goto x86_l_22ef;
	case 8948ULL: goto x86_l_22f4;
	case 8951ULL: goto x86_l_22f7;
	case 8953ULL: goto x86_l_22f9;
	case 8957ULL: goto x86_l_22fd;
	case 8962ULL: goto x86_l_2302;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8977ULL: goto x86_l_2311;
	case 8980ULL: goto x86_l_2314;
	case 8982ULL: goto x86_l_2316;
	case 8987ULL: goto x86_l_231b;
	case 8992ULL: goto x86_l_2320;
	case 8996ULL: goto x86_l_2324;
	case 8999ULL: goto x86_l_2327;
	case 9004ULL: goto x86_l_232c;
	case 9006ULL: goto x86_l_232e;
	case 9008ULL: goto x86_l_2330;
	case 9011ULL: goto x86_l_2333;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9021ULL: goto x86_l_233d;
	case 9024ULL: goto x86_l_2340;
	case 9028ULL: goto x86_l_2344;
	case 9030ULL: goto x86_l_2346;
	case 9034ULL: goto x86_l_234a;
	case 9036ULL: goto x86_l_234c;
	case 9039ULL: goto x86_l_234f;
	case 9041ULL: goto x86_l_2351;
	case 9045ULL: goto x86_l_2355;
	case 9048ULL: goto x86_l_2358;
	case 9053ULL: goto x86_l_235d;
	case 9059ULL: goto x86_l_2363;
	case 9065ULL: goto x86_l_2369;
	case 9071ULL: goto x86_l_236f;
	case 9074ULL: goto x86_l_2372;
	case 9076ULL: goto x86_l_2374;
	case 9081ULL: goto x86_l_2379;
	case 9083ULL: goto x86_l_237b;
	case 9086ULL: goto x86_l_237e;
	case 9090ULL: goto x86_l_2382;
	case 9093ULL: goto x86_l_2385;
	case 9096ULL: goto x86_l_2388;
	case 9099ULL: goto x86_l_238b;
	case 9104ULL: goto x86_l_2390;
	case 9106ULL: goto x86_l_2392;
	case 9111ULL: goto x86_l_2397;
	case 9114ULL: goto x86_l_239a;
	case 9119ULL: goto x86_l_239f;
	case 9125ULL: goto x86_l_23a5;
	case 9130ULL: goto x86_l_23aa;
	case 9135ULL: goto x86_l_23af;
	case 9140ULL: goto x86_l_23b4;
	case 9145ULL: goto x86_l_23b9;
	case 9150ULL: goto x86_l_23be;
	case 9154ULL: goto x86_l_23c2;
	case 9161ULL: goto x86_l_23c9;
	case 9165ULL: goto x86_l_23cd;
	case 9167ULL: goto x86_l_23cf;
	case 9171ULL: goto x86_l_23d3;
	case 9175ULL: goto x86_l_23d7;
	case 9179ULL: goto x86_l_23db;
	case 9184ULL: goto x86_l_23e0;
	case 9188ULL: goto x86_l_23e4;
	case 9194ULL: goto x86_l_23ea;
	case 9204ULL: goto x86_l_23f4;
	case 9208ULL: goto x86_l_23f8;
	case 9214ULL: goto x86_l_23fe;
	case 9218ULL: goto x86_l_2402;
	case 9221ULL: goto x86_l_2405;
	case 9229ULL: goto x86_l_240d;
	case 9232ULL: goto x86_l_2410;
	case 9237ULL: goto x86_l_2415;
	case 9242ULL: goto x86_l_241a;
	case 9246ULL: goto x86_l_241e;
	case 9249ULL: goto x86_l_2421;
	case 9252ULL: goto x86_l_2424;
	case 9257ULL: goto x86_l_2429;
	case 9259ULL: goto x86_l_242b;
	case 9262ULL: goto x86_l_242e;
	case 9268ULL: goto x86_l_2434;
	case 9272ULL: goto x86_l_2438;
	case 9275ULL: goto x86_l_243b;
	case 9277ULL: goto x86_l_243d;
	case 9279ULL: goto x86_l_243f;
	case 9281ULL: goto x86_l_2441;
	case 9284ULL: goto x86_l_2444;
	case 9286ULL: goto x86_l_2446;
	case 9289ULL: goto x86_l_2449;
	case 9291ULL: goto x86_l_244b;
	case 9297ULL: goto x86_l_2451;
	case 9301ULL: goto x86_l_2455;
	case 9303ULL: goto x86_l_2457;
	case 9306ULL: goto x86_l_245a;
	case 9308ULL: goto x86_l_245c;
	case 9311ULL: goto x86_l_245f;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9320ULL: goto x86_l_2468;
	case 9326ULL: goto x86_l_246e;
	case 9330ULL: goto x86_l_2472;
	case 9332ULL: goto x86_l_2474;
	case 9336ULL: goto x86_l_2478;
	case 9343ULL: goto x86_l_247f;
	case 9347ULL: goto x86_l_2483;
	case 9349ULL: goto x86_l_2485;
	case 9353ULL: goto x86_l_2489;
	case 9360ULL: goto x86_l_2490;
	case 9364ULL: goto x86_l_2494;
	case 9366ULL: goto x86_l_2496;
	case 9370ULL: goto x86_l_249a;
	case 9374ULL: goto x86_l_249e;
	case 9378ULL: goto x86_l_24a2;
	case 9383ULL: goto x86_l_24a7;
	case 9387ULL: goto x86_l_24ab;
	case 9393ULL: goto x86_l_24b1;
	case 9403ULL: goto x86_l_24bb;
	case 9407ULL: goto x86_l_24bf;
	case 9413ULL: goto x86_l_24c5;
	case 9417ULL: goto x86_l_24c9;
	case 9420ULL: goto x86_l_24cc;
	case 9428ULL: goto x86_l_24d4;
	case 9431ULL: goto x86_l_24d7;
	case 9436ULL: goto x86_l_24dc;
	case 9441ULL: goto x86_l_24e1;
	case 9445ULL: goto x86_l_24e5;
	case 9448ULL: goto x86_l_24e8;
	case 9451ULL: goto x86_l_24eb;
	case 9456ULL: goto x86_l_24f0;
	case 9458ULL: goto x86_l_24f2;
	case 9461ULL: goto x86_l_24f5;
	case 9467ULL: goto x86_l_24fb;
	case 9471ULL: goto x86_l_24ff;
	case 9474ULL: goto x86_l_2502;
	case 9476ULL: goto x86_l_2504;
	case 9478ULL: goto x86_l_2506;
	case 9480ULL: goto x86_l_2508;
	case 9483ULL: goto x86_l_250b;
	case 9485ULL: goto x86_l_250d;
	case 9488ULL: goto x86_l_2510;
	case 9494ULL: goto x86_l_2516;
	case 9500ULL: goto x86_l_251c;
	case 9504ULL: goto x86_l_2520;
	case 9509ULL: goto x86_l_2525;
	case 9512ULL: goto x86_l_2528;
	case 9518ULL: goto x86_l_252e;
	case 9521ULL: goto x86_l_2531;
	case 9523ULL: goto x86_l_2533;
	case 9528ULL: goto x86_l_2538;
	case 9534ULL: goto x86_l_253e;
	case 9540ULL: goto x86_l_2544;
	case 9544ULL: goto x86_l_2548;
	case 9549ULL: goto x86_l_254d;
	case 9553ULL: goto x86_l_2551;
	case 9560ULL: goto x86_l_2558;
	case 9564ULL: goto x86_l_255c;
	case 9569ULL: goto x86_l_2561;
	case 9574ULL: goto x86_l_2566;
	case 9577ULL: goto x86_l_2569;
	case 9582ULL: goto x86_l_256e;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9594ULL: goto x86_l_257a;
	case 9599ULL: goto x86_l_257f;
	case 9603ULL: goto x86_l_2583;
	case 9608ULL: goto x86_l_2588;
	case 9613ULL: goto x86_l_258d;
	case 9619ULL: goto x86_l_2593;
	case 9623ULL: goto x86_l_2597;
	case 9628ULL: goto x86_l_259c;
	case 9633ULL: goto x86_l_25a1;
	case 9638ULL: goto x86_l_25a6;
	case 9641ULL: goto x86_l_25a9;
	case 9643ULL: goto x86_l_25ab;
	case 9647ULL: goto x86_l_25af;
	case 9652ULL: goto x86_l_25b4;
	case 9657ULL: goto x86_l_25b9;
	case 9662ULL: goto x86_l_25be;
	case 9667ULL: goto x86_l_25c3;
	case 9672ULL: goto x86_l_25c8;
	case 9677ULL: goto x86_l_25cd;
	case 9679ULL: goto x86_l_25cf;
	case 9684ULL: goto x86_l_25d4;
	case 9690ULL: goto x86_l_25da;
	case 9695ULL: goto x86_l_25df;
	case 9700ULL: goto x86_l_25e4;
	case 9705ULL: goto x86_l_25e9;
	case 9710ULL: goto x86_l_25ee;
	case 9712ULL: goto x86_l_25f0;
	case 9717ULL: goto x86_l_25f5;
	case 9723ULL: goto x86_l_25fb;
	case 9727ULL: goto x86_l_25ff;
	case 9730ULL: goto x86_l_2602;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9745ULL: goto x86_l_2611;
	case 9748ULL: goto x86_l_2614;
	case 9750ULL: goto x86_l_2616;
	case 9754ULL: goto x86_l_261a;
	case 9760ULL: goto x86_l_2620;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9780ULL: goto x86_l_2634;
	case 9783ULL: goto x86_l_2637;
	case 9785ULL: goto x86_l_2639;
	case 9789ULL: goto x86_l_263d;
	case 9794ULL: goto x86_l_2642;
	case 9799ULL: goto x86_l_2647;
	case 9804ULL: goto x86_l_264c;
	case 9809ULL: goto x86_l_2651;
	case 9812ULL: goto x86_l_2654;
	case 9814ULL: goto x86_l_2656;
	case 9819ULL: goto x86_l_265b;
	case 9824ULL: goto x86_l_2660;
	case 9828ULL: goto x86_l_2664;
	case 9831ULL: goto x86_l_2667;
	case 9836ULL: goto x86_l_266c;
	case 9838ULL: goto x86_l_266e;
	case 9840ULL: goto x86_l_2670;
	case 9843ULL: goto x86_l_2673;
	case 9846ULL: goto x86_l_2676;
	case 9851ULL: goto x86_l_267b;
	case 9853ULL: goto x86_l_267d;
	case 9856ULL: goto x86_l_2680;
	case 9860ULL: goto x86_l_2684;
	case 9862ULL: goto x86_l_2686;
	case 9866ULL: goto x86_l_268a;
	case 9868ULL: goto x86_l_268c;
	case 9871ULL: goto x86_l_268f;
	case 9873ULL: goto x86_l_2691;
	case 9877ULL: goto x86_l_2695;
	case 9880ULL: goto x86_l_2698;
	case 9885ULL: goto x86_l_269d;
	case 9891ULL: goto x86_l_26a3;
	case 9897ULL: goto x86_l_26a9;
	case 9903ULL: goto x86_l_26af;
	case 9906ULL: goto x86_l_26b2;
	case 9908ULL: goto x86_l_26b4;
	case 9913ULL: goto x86_l_26b9;
	case 9915ULL: goto x86_l_26bb;
	case 9918ULL: goto x86_l_26be;
	case 9922ULL: goto x86_l_26c2;
	case 9925ULL: goto x86_l_26c5;
	case 9928ULL: goto x86_l_26c8;
	case 9931ULL: goto x86_l_26cb;
	case 9936ULL: goto x86_l_26d0;
	case 9938ULL: goto x86_l_26d2;
	case 9943ULL: goto x86_l_26d7;
	case 9946ULL: goto x86_l_26da;
	case 9951ULL: goto x86_l_26df;
	case 9957ULL: goto x86_l_26e5;
	case 9962ULL: goto x86_l_26ea;
	case 9967ULL: goto x86_l_26ef;
	case 9972ULL: goto x86_l_26f4;
	case 9977ULL: goto x86_l_26f9;
	case 9982ULL: goto x86_l_26fe;
	case 9986ULL: goto x86_l_2702;
	case 9993ULL: goto x86_l_2709;
	case 9997ULL: goto x86_l_270d;
	case 9999ULL: goto x86_l_270f;
	case 10003ULL: goto x86_l_2713;
	case 10007ULL: goto x86_l_2717;
	case 10011ULL: goto x86_l_271b;
	case 10016ULL: goto x86_l_2720;
	case 10020ULL: goto x86_l_2724;
	case 10026ULL: goto x86_l_272a;
	case 10036ULL: goto x86_l_2734;
	case 10040ULL: goto x86_l_2738;
	case 10046ULL: goto x86_l_273e;
	case 10050ULL: goto x86_l_2742;
	case 10053ULL: goto x86_l_2745;
	case 10061ULL: goto x86_l_274d;
	case 10064ULL: goto x86_l_2750;
	case 10069ULL: goto x86_l_2755;
	case 10074ULL: goto x86_l_275a;
	case 10078ULL: goto x86_l_275e;
	case 10081ULL: goto x86_l_2761;
	case 10084ULL: goto x86_l_2764;
	case 10089ULL: goto x86_l_2769;
	case 10091ULL: goto x86_l_276b;
	case 10094ULL: goto x86_l_276e;
	case 10100ULL: goto x86_l_2774;
	case 10104ULL: goto x86_l_2778;
	case 10107ULL: goto x86_l_277b;
	case 10109ULL: goto x86_l_277d;
	case 10111ULL: goto x86_l_277f;
	case 10113ULL: goto x86_l_2781;
	case 10116ULL: goto x86_l_2784;
	case 10118ULL: goto x86_l_2786;
	case 10121ULL: goto x86_l_2789;
	case 10123ULL: goto x86_l_278b;
	case 10129ULL: goto x86_l_2791;
	case 10133ULL: goto x86_l_2795;
	case 10135ULL: goto x86_l_2797;
	case 10138ULL: goto x86_l_279a;
	case 10140ULL: goto x86_l_279c;
	case 10143ULL: goto x86_l_279f;
	case 10145ULL: goto x86_l_27a1;
	case 10150ULL: goto x86_l_27a6;
	case 10152ULL: goto x86_l_27a8;
	case 10158ULL: goto x86_l_27ae;
	case 10162ULL: goto x86_l_27b2;
	case 10164ULL: goto x86_l_27b4;
	case 10168ULL: goto x86_l_27b8;
	case 10175ULL: goto x86_l_27bf;
	default: return 0xffffffffffffffffULL;
	}
x86_l_21a1:
	/* 0x21a1: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21a5:
	/* 0x21a5: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21a8:
	/* 0x21a8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_21ab:
	/* 0x21ab: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_21b0:
	/* 0x21b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b2:
	/* 0x21b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21b5:
	/* 0x21b5: js     28f9 <generic_uprobe_process_event+0x28f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10489ULL;
	}
x86_l_21bb:
	/* 0x21bb: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_21bf:
	/* 0x21bf: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_21c2:
	/* 0x21c2: jg     21e5 <generic_uprobe_process_event+0x21e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21e5;
	}
x86_l_21c4:
	/* 0x21c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21c6:
	/* 0x21c6: je     220d <generic_uprobe_process_event+0x220d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220d;
	}
x86_l_21c8:
	/* 0x21c8: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_21cb:
	/* 0x21cb: je     220d <generic_uprobe_process_event+0x220d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220d;
	}
x86_l_21cd:
	/* 0x21cd: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_21d0:
	/* 0x21d0: jne    23cf <generic_uprobe_process_event+0x23cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23cf;
	}
x86_l_21d6:
	/* 0x21d6: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_21dc:
	/* 0x21dc: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_21e0:
	/* 0x21e0: jmp    23d3 <generic_uprobe_process_event+0x23d3> */
	goto x86_l_23d3;
x86_l_21e5:
	/* 0x21e5: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_21e8:
	/* 0x21e8: je     23be <generic_uprobe_process_event+0x23be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23be;
	}
x86_l_21ee:
	/* 0x21ee: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_21f1:
	/* 0x21f1: je     220d <generic_uprobe_process_event+0x220d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220d;
	}
x86_l_21f3:
	/* 0x21f3: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_21f8:
	/* 0x21f8: jne    23cf <generic_uprobe_process_event+0x23cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23cf;
	}
x86_l_21fe:
	/* 0x21fe: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2204:
	/* 0x2204: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2208:
	/* 0x2208: jmp    23d3 <generic_uprobe_process_event+0x23d3> */
	goto x86_l_23d3;
x86_l_220d:
	/* 0x220d: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2211:
	/* 0x2211: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2218:
	/* 0x2218: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_221c:
	/* 0x221c: jmp    23d3 <generic_uprobe_process_event+0x23d3> */
	goto x86_l_23d3;
x86_l_2221:
	/* 0x2221: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2226:
	/* 0x2226: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2229:
	/* 0x2229: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_222e:
	/* 0x222e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2233:
	/* 0x2233: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2238:
	/* 0x2238: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223a:
	/* 0x223a: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_223f:
	/* 0x223f: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2243:
	/* 0x2243: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2248:
	/* 0x2248: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_224d:
	/* 0x224d: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_2253:
	/* 0x2253: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2257:
	/* 0x2257: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_225c:
	/* 0x225c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2261:
	/* 0x2261: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2266:
	/* 0x2266: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2269:
	/* 0x2269: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226b:
	/* 0x226b: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_226f:
	/* 0x226f: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2274:
	/* 0x2274: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2279:
	/* 0x2279: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_227e:
	/* 0x227e: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2283:
	/* 0x2283: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2288:
	/* 0x2288: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_228d:
	/* 0x228d: jne    229a <generic_uprobe_process_event+0x229a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_229a;
	}
x86_l_228f:
	/* 0x228f: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2294:
	/* 0x2294: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_229a:
	/* 0x229a: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_229f:
	/* 0x229f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22a4:
	/* 0x22a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22a9:
	/* 0x22a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22ae:
	/* 0x22ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22b0:
	/* 0x22b0: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_22b5:
	/* 0x22b5: je     2561 <generic_uprobe_process_event+0x2561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2561;
	}
x86_l_22bb:
	/* 0x22bb: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22bf:
	/* 0x22bf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22c2:
	/* 0x22c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22c7:
	/* 0x22c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22cc:
	/* 0x22cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22d1:
	/* 0x22d1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_22d4:
	/* 0x22d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d6:
	/* 0x22d6: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22da:
	/* 0x22da: je     2561 <generic_uprobe_process_event+0x2561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2561;
	}
x86_l_22e0:
	/* 0x22e0: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_22e5:
	/* 0x22e5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22ea:
	/* 0x22ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22ef:
	/* 0x22ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22f4:
	/* 0x22f4: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_22f7:
	/* 0x22f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f9:
	/* 0x22f9: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_22fd:
	/* 0x22fd: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2302:
	/* 0x2302: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2307:
	/* 0x2307: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_230c:
	/* 0x230c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2311:
	/* 0x2311: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2314:
	/* 0x2314: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2316:
	/* 0x2316: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_231b:
	/* 0x231b: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2320:
	/* 0x2320: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2324:
	/* 0x2324: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2327:
	/* 0x2327: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_232c:
	/* 0x232c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_232e:
	/* 0x232e: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2330:
	/* 0x2330: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2333:
	/* 0x2333: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2336:
	/* 0x2336: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_233b:
	/* 0x233b: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_233d:
	/* 0x233d: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2340:
	/* 0x2340: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2344:
	/* 0x2344: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2346:
	/* 0x2346: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_234a:
	/* 0x234a: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_234c:
	/* 0x234c: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_234f:
	/* 0x234f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2351:
	/* 0x2351: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2355:
	/* 0x2355: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2358:
	/* 0x2358: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_235d:
	/* 0x235d: jb     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3478ULL;
	}
x86_l_2363:
	/* 0x2363: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2369:
	/* 0x2369: ja     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3478ULL;
	}
x86_l_236f:
	/* 0x236f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2372:
	/* 0x2372: jbe    2379 <generic_uprobe_process_event+0x2379> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2379;
	}
x86_l_2374:
	/* 0x2374: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2379:
	/* 0x2379: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_237b:
	/* 0x237b: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_237e:
	/* 0x237e: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2382:
	/* 0x2382: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2385:
	/* 0x2385: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2388:
	/* 0x2388: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_238b:
	/* 0x238b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2390:
	/* 0x2390: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2392:
	/* 0x2392: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2397:
	/* 0x2397: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_239a:
	/* 0x239a: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_239f:
	/* 0x239f: jbe    d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3478ULL;
	}
x86_l_23a5:
	/* 0x23a5: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_23aa:
	/* 0x23aa: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_23af:
	/* 0x23af: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_23b4:
	/* 0x23b4: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_23b9:
	/* 0x23b9: jmp    25c3 <generic_uprobe_process_event+0x25c3> */
	goto x86_l_25c3;
x86_l_23be:
	/* 0x23be: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_23c2:
	/* 0x23c2: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_23c9:
	/* 0x23c9: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_23cd:
	/* 0x23cd: jmp    23d3 <generic_uprobe_process_event+0x23d3> */
	goto x86_l_23d3;
x86_l_23cf:
	/* 0x23cf: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_23d3:
	/* 0x23d3: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23d7:
	/* 0x23d7: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23db:
	/* 0x23db: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_23e0:
	/* 0x23e0: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_23e4:
	/* 0x23e4: ja     2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10952ULL;
	}
x86_l_23ea:
	/* 0x23ea: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_23f4:
	/* 0x23f4: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_23f8:
	/* 0x23f8: jae    2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10952ULL;
	}
x86_l_23fe:
	/* 0x23fe: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2402:
	/* 0x2402: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2405:
	/* 0x2405: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_240d:
	/* 0x240d: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2410:
	/* 0x2410: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2415:
	/* 0x2415: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_241a:
	/* 0x241a: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_241e:
	/* 0x241e: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2421:
	/* 0x2421: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2424:
	/* 0x2424: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2429:
	/* 0x2429: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_242b:
	/* 0x242b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_242e:
	/* 0x242e: js     28f9 <generic_uprobe_process_event+0x28f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10489ULL;
	}
x86_l_2434:
	/* 0x2434: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2438:
	/* 0x2438: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_243b:
	/* 0x243b: jg     2457 <generic_uprobe_process_event+0x2457> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2457;
	}
x86_l_243d:
	/* 0x243d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_243f:
	/* 0x243f: je     2474 <generic_uprobe_process_event+0x2474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2474;
	}
x86_l_2441:
	/* 0x2441: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2444:
	/* 0x2444: je     2474 <generic_uprobe_process_event+0x2474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2474;
	}
x86_l_2446:
	/* 0x2446: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2449:
	/* 0x2449: jne    2496 <generic_uprobe_process_event+0x2496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2496;
	}
x86_l_244b:
	/* 0x244b: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2451:
	/* 0x2451: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2455:
	/* 0x2455: jmp    249a <generic_uprobe_process_event+0x249a> */
	goto x86_l_249a;
x86_l_2457:
	/* 0x2457: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_245a:
	/* 0x245a: je     2485 <generic_uprobe_process_event+0x2485> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2485;
	}
x86_l_245c:
	/* 0x245c: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_245f:
	/* 0x245f: je     2474 <generic_uprobe_process_event+0x2474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2474;
	}
x86_l_2461:
	/* 0x2461: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2466:
	/* 0x2466: jne    2496 <generic_uprobe_process_event+0x2496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2496;
	}
x86_l_2468:
	/* 0x2468: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_246e:
	/* 0x246e: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2472:
	/* 0x2472: jmp    249a <generic_uprobe_process_event+0x249a> */
	goto x86_l_249a;
x86_l_2474:
	/* 0x2474: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2478:
	/* 0x2478: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_247f:
	/* 0x247f: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2483:
	/* 0x2483: jmp    249a <generic_uprobe_process_event+0x249a> */
	goto x86_l_249a;
x86_l_2485:
	/* 0x2485: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2489:
	/* 0x2489: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2490:
	/* 0x2490: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2494:
	/* 0x2494: jmp    249a <generic_uprobe_process_event+0x249a> */
	goto x86_l_249a;
x86_l_2496:
	/* 0x2496: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_249a:
	/* 0x249a: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_249e:
	/* 0x249e: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24a2:
	/* 0x24a2: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_24a7:
	/* 0x24a7: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_24ab:
	/* 0x24ab: ja     2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10952ULL;
	}
x86_l_24b1:
	/* 0x24b1: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_24bb:
	/* 0x24bb: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_24bf:
	/* 0x24bf: jae    2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10952ULL;
	}
x86_l_24c5:
	/* 0x24c5: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_24c9:
	/* 0x24c9: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_24cc:
	/* 0x24cc: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_24d4:
	/* 0x24d4: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24d7:
	/* 0x24d7: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_24dc:
	/* 0x24dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24e1:
	/* 0x24e1: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24e5:
	/* 0x24e5: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24e8:
	/* 0x24e8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_24eb:
	/* 0x24eb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_24f0:
	/* 0x24f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f2:
	/* 0x24f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24f5:
	/* 0x24f5: js     28f9 <generic_uprobe_process_event+0x28f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10489ULL;
	}
x86_l_24fb:
	/* 0x24fb: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_24ff:
	/* 0x24ff: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2502:
	/* 0x2502: jg     2525 <generic_uprobe_process_event+0x2525> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2525;
	}
x86_l_2504:
	/* 0x2504: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2506:
	/* 0x2506: je     254d <generic_uprobe_process_event+0x254d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_254d;
	}
x86_l_2508:
	/* 0x2508: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_250b:
	/* 0x250b: je     254d <generic_uprobe_process_event+0x254d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_254d;
	}
x86_l_250d:
	/* 0x250d: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2510:
	/* 0x2510: jne    270f <generic_uprobe_process_event+0x270f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_270f;
	}
x86_l_2516:
	/* 0x2516: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_251c:
	/* 0x251c: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2520:
	/* 0x2520: jmp    2713 <generic_uprobe_process_event+0x2713> */
	goto x86_l_2713;
x86_l_2525:
	/* 0x2525: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2528:
	/* 0x2528: je     26fe <generic_uprobe_process_event+0x26fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26fe;
	}
x86_l_252e:
	/* 0x252e: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2531:
	/* 0x2531: je     254d <generic_uprobe_process_event+0x254d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_254d;
	}
x86_l_2533:
	/* 0x2533: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2538:
	/* 0x2538: jne    270f <generic_uprobe_process_event+0x270f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_270f;
	}
x86_l_253e:
	/* 0x253e: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2544:
	/* 0x2544: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2548:
	/* 0x2548: jmp    2713 <generic_uprobe_process_event+0x2713> */
	goto x86_l_2713;
x86_l_254d:
	/* 0x254d: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2551:
	/* 0x2551: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2558:
	/* 0x2558: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_255c:
	/* 0x255c: jmp    2713 <generic_uprobe_process_event+0x2713> */
	goto x86_l_2713;
x86_l_2561:
	/* 0x2561: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2566:
	/* 0x2566: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2569:
	/* 0x2569: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_256e:
	/* 0x256e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2573:
	/* 0x2573: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2578:
	/* 0x2578: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_257a:
	/* 0x257a: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_257f:
	/* 0x257f: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2583:
	/* 0x2583: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2588:
	/* 0x2588: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_258d:
	/* 0x258d: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_2593:
	/* 0x2593: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2597:
	/* 0x2597: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_259c:
	/* 0x259c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25a1:
	/* 0x25a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25a6:
	/* 0x25a6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_25a9:
	/* 0x25a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ab:
	/* 0x25ab: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25af:
	/* 0x25af: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_25b4:
	/* 0x25b4: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25b9:
	/* 0x25b9: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25be:
	/* 0x25be: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25c3:
	/* 0x25c3: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_25c8:
	/* 0x25c8: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25cd:
	/* 0x25cd: jne    25da <generic_uprobe_process_event+0x25da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25da;
	}
x86_l_25cf:
	/* 0x25cf: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_25d4:
	/* 0x25d4: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_25da:
	/* 0x25da: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_25df:
	/* 0x25df: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25e4:
	/* 0x25e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25e9:
	/* 0x25e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25ee:
	/* 0x25ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f0:
	/* 0x25f0: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_25f5:
	/* 0x25f5: je     2ad5 <generic_uprobe_process_event+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10965ULL;
	}
x86_l_25fb:
	/* 0x25fb: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25ff:
	/* 0x25ff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2602:
	/* 0x2602: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2607:
	/* 0x2607: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_260c:
	/* 0x260c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2611:
	/* 0x2611: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2614:
	/* 0x2614: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2616:
	/* 0x2616: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_261a:
	/* 0x261a: je     2ad5 <generic_uprobe_process_event+0x2ad5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10965ULL;
	}
x86_l_2620:
	/* 0x2620: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2625:
	/* 0x2625: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_262a:
	/* 0x262a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_262f:
	/* 0x262f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2634:
	/* 0x2634: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2637:
	/* 0x2637: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2639:
	/* 0x2639: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_263d:
	/* 0x263d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2642:
	/* 0x2642: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2647:
	/* 0x2647: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_264c:
	/* 0x264c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2651:
	/* 0x2651: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2654:
	/* 0x2654: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2656:
	/* 0x2656: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_265b:
	/* 0x265b: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2660:
	/* 0x2660: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2664:
	/* 0x2664: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2667:
	/* 0x2667: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_266c:
	/* 0x266c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_266e:
	/* 0x266e: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2670:
	/* 0x2670: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2673:
	/* 0x2673: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2676:
	/* 0x2676: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_267b:
	/* 0x267b: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_267d:
	/* 0x267d: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2680:
	/* 0x2680: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2684:
	/* 0x2684: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2686:
	/* 0x2686: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_268a:
	/* 0x268a: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_268c:
	/* 0x268c: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_268f:
	/* 0x268f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2691:
	/* 0x2691: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2695:
	/* 0x2695: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2698:
	/* 0x2698: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_269d:
	/* 0x269d: jb     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3478ULL;
	}
x86_l_26a3:
	/* 0x26a3: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_26a9:
	/* 0x26a9: ja     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3478ULL;
	}
x86_l_26af:
	/* 0x26af: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_26b2:
	/* 0x26b2: jbe    26b9 <generic_uprobe_process_event+0x26b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_26b9;
	}
x86_l_26b4:
	/* 0x26b4: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_26b9:
	/* 0x26b9: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26bb:
	/* 0x26bb: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_26be:
	/* 0x26be: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_26c2:
	/* 0x26c2: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_26c5:
	/* 0x26c5: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26c8:
	/* 0x26c8: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26cb:
	/* 0x26cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26d0:
	/* 0x26d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d2:
	/* 0x26d2: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_26d7:
	/* 0x26d7: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_26da:
	/* 0x26da: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26df:
	/* 0x26df: jbe    d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3478ULL;
	}
x86_l_26e5:
	/* 0x26e5: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_26ea:
	/* 0x26ea: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26ef:
	/* 0x26ef: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_26f4:
	/* 0x26f4: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26f9:
	/* 0x26f9: jmp    2b37 <generic_uprobe_process_event+0x2b37> */
	return 11063ULL;
x86_l_26fe:
	/* 0x26fe: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2702:
	/* 0x2702: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2709:
	/* 0x2709: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_270d:
	/* 0x270d: jmp    2713 <generic_uprobe_process_event+0x2713> */
	goto x86_l_2713;
x86_l_270f:
	/* 0x270f: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2713:
	/* 0x2713: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2717:
	/* 0x2717: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_271b:
	/* 0x271b: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2720:
	/* 0x2720: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_2724:
	/* 0x2724: ja     2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10952ULL;
	}
x86_l_272a:
	/* 0x272a: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2734:
	/* 0x2734: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2738:
	/* 0x2738: jae    2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10952ULL;
	}
x86_l_273e:
	/* 0x273e: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2742:
	/* 0x2742: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2745:
	/* 0x2745: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_274d:
	/* 0x274d: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2750:
	/* 0x2750: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2755:
	/* 0x2755: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_275a:
	/* 0x275a: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_275e:
	/* 0x275e: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2761:
	/* 0x2761: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2764:
	/* 0x2764: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2769:
	/* 0x2769: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_276b:
	/* 0x276b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_276e:
	/* 0x276e: js     28f9 <generic_uprobe_process_event+0x28f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10489ULL;
	}
x86_l_2774:
	/* 0x2774: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2778:
	/* 0x2778: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_277b:
	/* 0x277b: jg     2797 <generic_uprobe_process_event+0x2797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2797;
	}
x86_l_277d:
	/* 0x277d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_277f:
	/* 0x277f: je     27b4 <generic_uprobe_process_event+0x27b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27b4;
	}
x86_l_2781:
	/* 0x2781: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2784:
	/* 0x2784: je     27b4 <generic_uprobe_process_event+0x27b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27b4;
	}
x86_l_2786:
	/* 0x2786: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2789:
	/* 0x2789: jne    27d6 <generic_uprobe_process_event+0x27d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10198ULL;
	}
x86_l_278b:
	/* 0x278b: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2791:
	/* 0x2791: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2795:
	/* 0x2795: jmp    27da <generic_uprobe_process_event+0x27da> */
	return 10202ULL;
x86_l_2797:
	/* 0x2797: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_279a:
	/* 0x279a: je     27c5 <generic_uprobe_process_event+0x27c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10181ULL;
	}
x86_l_279c:
	/* 0x279c: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_279f:
	/* 0x279f: je     27b4 <generic_uprobe_process_event+0x27b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27b4;
	}
x86_l_27a1:
	/* 0x27a1: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_27a6:
	/* 0x27a6: jne    27d6 <generic_uprobe_process_event+0x27d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10198ULL;
	}
x86_l_27a8:
	/* 0x27a8: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_27ae:
	/* 0x27ae: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_27b2:
	/* 0x27b2: jmp    27da <generic_uprobe_process_event+0x27da> */
	return 10202ULL;
x86_l_27b4:
	/* 0x27b4: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_27b8:
	/* 0x27b8: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_27bf:
	/* 0x27bf: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
	return 10179ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10179ULL: goto x86_l_27c3;
	case 10181ULL: goto x86_l_27c5;
	case 10185ULL: goto x86_l_27c9;
	case 10192ULL: goto x86_l_27d0;
	case 10196ULL: goto x86_l_27d4;
	case 10198ULL: goto x86_l_27d6;
	case 10202ULL: goto x86_l_27da;
	case 10206ULL: goto x86_l_27de;
	case 10210ULL: goto x86_l_27e2;
	case 10215ULL: goto x86_l_27e7;
	case 10219ULL: goto x86_l_27eb;
	case 10225ULL: goto x86_l_27f1;
	case 10235ULL: goto x86_l_27fb;
	case 10239ULL: goto x86_l_27ff;
	case 10245ULL: goto x86_l_2805;
	case 10249ULL: goto x86_l_2809;
	case 10252ULL: goto x86_l_280c;
	case 10260ULL: goto x86_l_2814;
	case 10263ULL: goto x86_l_2817;
	case 10268ULL: goto x86_l_281c;
	case 10273ULL: goto x86_l_2821;
	case 10277ULL: goto x86_l_2825;
	case 10280ULL: goto x86_l_2828;
	case 10283ULL: goto x86_l_282b;
	case 10288ULL: goto x86_l_2830;
	case 10290ULL: goto x86_l_2832;
	case 10293ULL: goto x86_l_2835;
	case 10299ULL: goto x86_l_283b;
	case 10303ULL: goto x86_l_283f;
	case 10306ULL: goto x86_l_2842;
	case 10308ULL: goto x86_l_2844;
	case 10310ULL: goto x86_l_2846;
	case 10312ULL: goto x86_l_2848;
	case 10315ULL: goto x86_l_284b;
	case 10317ULL: goto x86_l_284d;
	case 10320ULL: goto x86_l_2850;
	case 10322ULL: goto x86_l_2852;
	case 10328ULL: goto x86_l_2858;
	case 10332ULL: goto x86_l_285c;
	case 10334ULL: goto x86_l_285e;
	case 10337ULL: goto x86_l_2861;
	case 10339ULL: goto x86_l_2863;
	case 10342ULL: goto x86_l_2866;
	case 10344ULL: goto x86_l_2868;
	case 10349ULL: goto x86_l_286d;
	case 10351ULL: goto x86_l_286f;
	case 10357ULL: goto x86_l_2875;
	case 10361ULL: goto x86_l_2879;
	case 10363ULL: goto x86_l_287b;
	case 10367ULL: goto x86_l_287f;
	case 10374ULL: goto x86_l_2886;
	case 10378ULL: goto x86_l_288a;
	case 10380ULL: goto x86_l_288c;
	case 10384ULL: goto x86_l_2890;
	case 10391ULL: goto x86_l_2897;
	case 10395ULL: goto x86_l_289b;
	case 10397ULL: goto x86_l_289d;
	case 10401ULL: goto x86_l_28a1;
	case 10405ULL: goto x86_l_28a5;
	case 10409ULL: goto x86_l_28a9;
	case 10414ULL: goto x86_l_28ae;
	case 10418ULL: goto x86_l_28b2;
	case 10424ULL: goto x86_l_28b8;
	case 10434ULL: goto x86_l_28c2;
	case 10438ULL: goto x86_l_28c6;
	case 10444ULL: goto x86_l_28cc;
	case 10448ULL: goto x86_l_28d0;
	case 10451ULL: goto x86_l_28d3;
	case 10459ULL: goto x86_l_28db;
	case 10462ULL: goto x86_l_28de;
	case 10467ULL: goto x86_l_28e3;
	case 10472ULL: goto x86_l_28e8;
	case 10476ULL: goto x86_l_28ec;
	case 10479ULL: goto x86_l_28ef;
	case 10482ULL: goto x86_l_28f2;
	case 10487ULL: goto x86_l_28f7;
	case 10489ULL: goto x86_l_28f9;
	case 10492ULL: goto x86_l_28fc;
	case 10500ULL: goto x86_l_2904;
	case 10504ULL: goto x86_l_2908;
	case 10509ULL: goto x86_l_290d;
	case 10514ULL: goto x86_l_2912;
	case 10521ULL: goto x86_l_2919;
	case 10526ULL: goto x86_l_291e;
	case 10530ULL: goto x86_l_2922;
	case 10535ULL: goto x86_l_2927;
	case 10540ULL: goto x86_l_292c;
	case 10543ULL: goto x86_l_292f;
	case 10548ULL: goto x86_l_2934;
	case 10550ULL: goto x86_l_2936;
	case 10554ULL: goto x86_l_293a;
	case 10558ULL: goto x86_l_293e;
	case 10563ULL: goto x86_l_2943;
	case 10568ULL: goto x86_l_2948;
	case 10573ULL: goto x86_l_294d;
	case 10576ULL: goto x86_l_2950;
	case 10578ULL: goto x86_l_2952;
	case 10582ULL: goto x86_l_2956;
	case 10584ULL: goto x86_l_2958;
	case 10588ULL: goto x86_l_295c;
	case 10591ULL: goto x86_l_295f;
	case 10597ULL: goto x86_l_2965;
	case 10602ULL: goto x86_l_296a;
	case 10611ULL: goto x86_l_2973;
	case 10615ULL: goto x86_l_2977;
	case 10620ULL: goto x86_l_297c;
	case 10624ULL: goto x86_l_2980;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10639ULL: goto x86_l_298f;
	case 10641ULL: goto x86_l_2991;
	case 10645ULL: goto x86_l_2995;
	case 10649ULL: goto x86_l_2999;
	case 10653ULL: goto x86_l_299d;
	case 10658ULL: goto x86_l_29a2;
	case 10663ULL: goto x86_l_29a7;
	case 10665ULL: goto x86_l_29a9;
	case 10670ULL: goto x86_l_29ae;
	case 10679ULL: goto x86_l_29b7;
	case 10683ULL: goto x86_l_29bb;
	case 10688ULL: goto x86_l_29c0;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10702ULL: goto x86_l_29ce;
	case 10707ULL: goto x86_l_29d3;
	case 10709ULL: goto x86_l_29d5;
	case 10713ULL: goto x86_l_29d9;
	case 10717ULL: goto x86_l_29dd;
	case 10721ULL: goto x86_l_29e1;
	case 10726ULL: goto x86_l_29e6;
	case 10731ULL: goto x86_l_29eb;
	case 10736ULL: goto x86_l_29f0;
	case 10738ULL: goto x86_l_29f2;
	case 10740ULL: goto x86_l_29f4;
	case 10745ULL: goto x86_l_29f9;
	case 10752ULL: goto x86_l_2a00;
	case 10757ULL: goto x86_l_2a05;
	case 10761ULL: goto x86_l_2a09;
	case 10765ULL: goto x86_l_2a0d;
	case 10771ULL: goto x86_l_2a13;
	case 10777ULL: goto x86_l_2a19;
	case 10784ULL: goto x86_l_2a20;
	case 10789ULL: goto x86_l_2a25;
	case 10794ULL: goto x86_l_2a2a;
	case 10799ULL: goto x86_l_2a2f;
	case 10805ULL: goto x86_l_2a35;
	case 10810ULL: goto x86_l_2a3a;
	case 10813ULL: goto x86_l_2a3d;
	case 10815ULL: goto x86_l_2a3f;
	case 10820ULL: goto x86_l_2a44;
	case 10823ULL: goto x86_l_2a47;
	case 10825ULL: goto x86_l_2a49;
	case 10829ULL: goto x86_l_2a4d;
	case 10837ULL: goto x86_l_2a55;
	case 10842ULL: goto x86_l_2a5a;
	case 10847ULL: goto x86_l_2a5f;
	case 10852ULL: goto x86_l_2a64;
	case 10856ULL: goto x86_l_2a68;
	case 10861ULL: goto x86_l_2a6d;
	case 10863ULL: goto x86_l_2a6f;
	case 10868ULL: goto x86_l_2a74;
	case 10876ULL: goto x86_l_2a7c;
	case 10880ULL: goto x86_l_2a80;
	case 10885ULL: goto x86_l_2a85;
	case 10889ULL: goto x86_l_2a89;
	case 10894ULL: goto x86_l_2a8e;
	case 10899ULL: goto x86_l_2a93;
	case 10901ULL: goto x86_l_2a95;
	case 10905ULL: goto x86_l_2a99;
	case 10909ULL: goto x86_l_2a9d;
	case 10913ULL: goto x86_l_2aa1;
	case 10918ULL: goto x86_l_2aa6;
	case 10921ULL: goto x86_l_2aa9;
	case 10926ULL: goto x86_l_2aae;
	case 10928ULL: goto x86_l_2ab0;
	case 10934ULL: goto x86_l_2ab6;
	case 10942ULL: goto x86_l_2abe;
	case 10947ULL: goto x86_l_2ac3;
	case 10952ULL: goto x86_l_2ac8;
	case 10960ULL: goto x86_l_2ad0;
	case 10965ULL: goto x86_l_2ad5;
	case 10970ULL: goto x86_l_2ada;
	case 10973ULL: goto x86_l_2add;
	case 10978ULL: goto x86_l_2ae2;
	case 10983ULL: goto x86_l_2ae7;
	case 10988ULL: goto x86_l_2aec;
	case 10990ULL: goto x86_l_2aee;
	case 10995ULL: goto x86_l_2af3;
	case 10999ULL: goto x86_l_2af7;
	case 11004ULL: goto x86_l_2afc;
	case 11009ULL: goto x86_l_2b01;
	case 11015ULL: goto x86_l_2b07;
	case 11019ULL: goto x86_l_2b0b;
	case 11024ULL: goto x86_l_2b10;
	case 11029ULL: goto x86_l_2b15;
	case 11034ULL: goto x86_l_2b1a;
	case 11037ULL: goto x86_l_2b1d;
	case 11039ULL: goto x86_l_2b1f;
	case 11043ULL: goto x86_l_2b23;
	case 11048ULL: goto x86_l_2b28;
	case 11053ULL: goto x86_l_2b2d;
	case 11058ULL: goto x86_l_2b32;
	case 11063ULL: goto x86_l_2b37;
	case 11068ULL: goto x86_l_2b3c;
	case 11073ULL: goto x86_l_2b41;
	case 11075ULL: goto x86_l_2b43;
	case 11080ULL: goto x86_l_2b48;
	case 11086ULL: goto x86_l_2b4e;
	case 11091ULL: goto x86_l_2b53;
	case 11096ULL: goto x86_l_2b58;
	case 11101ULL: goto x86_l_2b5d;
	case 11106ULL: goto x86_l_2b62;
	case 11108ULL: goto x86_l_2b64;
	case 11113ULL: goto x86_l_2b69;
	case 11119ULL: goto x86_l_2b6f;
	case 11123ULL: goto x86_l_2b73;
	case 11126ULL: goto x86_l_2b76;
	case 11131ULL: goto x86_l_2b7b;
	case 11136ULL: goto x86_l_2b80;
	case 11141ULL: goto x86_l_2b85;
	case 11144ULL: goto x86_l_2b88;
	case 11146ULL: goto x86_l_2b8a;
	case 11150ULL: goto x86_l_2b8e;
	case 11156ULL: goto x86_l_2b94;
	case 11161ULL: goto x86_l_2b99;
	case 11166ULL: goto x86_l_2b9e;
	case 11171ULL: goto x86_l_2ba3;
	case 11176ULL: goto x86_l_2ba8;
	case 11179ULL: goto x86_l_2bab;
	case 11181ULL: goto x86_l_2bad;
	case 11185ULL: goto x86_l_2bb1;
	case 11190ULL: goto x86_l_2bb6;
	case 11195ULL: goto x86_l_2bbb;
	case 11200ULL: goto x86_l_2bc0;
	case 11205ULL: goto x86_l_2bc5;
	case 11208ULL: goto x86_l_2bc8;
	case 11210ULL: goto x86_l_2bca;
	case 11215ULL: goto x86_l_2bcf;
	case 11220ULL: goto x86_l_2bd4;
	case 11224ULL: goto x86_l_2bd8;
	case 11227ULL: goto x86_l_2bdb;
	case 11232ULL: goto x86_l_2be0;
	case 11234ULL: goto x86_l_2be2;
	case 11236ULL: goto x86_l_2be4;
	case 11239ULL: goto x86_l_2be7;
	case 11242ULL: goto x86_l_2bea;
	case 11247ULL: goto x86_l_2bef;
	case 11249ULL: goto x86_l_2bf1;
	case 11252ULL: goto x86_l_2bf4;
	case 11256ULL: goto x86_l_2bf8;
	case 11258ULL: goto x86_l_2bfa;
	case 11262ULL: goto x86_l_2bfe;
	case 11264ULL: goto x86_l_2c00;
	case 11267ULL: goto x86_l_2c03;
	case 11269ULL: goto x86_l_2c05;
	case 11273ULL: goto x86_l_2c09;
	case 11276ULL: goto x86_l_2c0c;
	case 11281ULL: goto x86_l_2c11;
	case 11287ULL: goto x86_l_2c17;
	case 11293ULL: goto x86_l_2c1d;
	case 11299ULL: goto x86_l_2c23;
	case 11302ULL: goto x86_l_2c26;
	case 11304ULL: goto x86_l_2c28;
	case 11309ULL: goto x86_l_2c2d;
	case 11311ULL: goto x86_l_2c2f;
	case 11314ULL: goto x86_l_2c32;
	case 11318ULL: goto x86_l_2c36;
	case 11321ULL: goto x86_l_2c39;
	case 11324ULL: goto x86_l_2c3c;
	case 11327ULL: goto x86_l_2c3f;
	case 11332ULL: goto x86_l_2c44;
	case 11334ULL: goto x86_l_2c46;
	case 11339ULL: goto x86_l_2c4b;
	case 11342ULL: goto x86_l_2c4e;
	case 11347ULL: goto x86_l_2c53;
	case 11353ULL: goto x86_l_2c59;
	case 11358ULL: goto x86_l_2c5e;
	case 11363ULL: goto x86_l_2c63;
	case 11368ULL: goto x86_l_2c68;
	case 11373ULL: goto x86_l_2c6d;
	case 11375ULL: goto x86_l_2c6f;
	case 11380ULL: goto x86_l_2c74;
	case 11383ULL: goto x86_l_2c77;
	case 11388ULL: goto x86_l_2c7c;
	case 11393ULL: goto x86_l_2c81;
	case 11398ULL: goto x86_l_2c86;
	case 11400ULL: goto x86_l_2c88;
	case 11405ULL: goto x86_l_2c8d;
	case 11409ULL: goto x86_l_2c91;
	case 11414ULL: goto x86_l_2c96;
	case 11419ULL: goto x86_l_2c9b;
	case 11425ULL: goto x86_l_2ca1;
	case 11429ULL: goto x86_l_2ca5;
	case 11434ULL: goto x86_l_2caa;
	case 11439ULL: goto x86_l_2caf;
	case 11444ULL: goto x86_l_2cb4;
	case 11447ULL: goto x86_l_2cb7;
	case 11449ULL: goto x86_l_2cb9;
	case 11453ULL: goto x86_l_2cbd;
	case 11458ULL: goto x86_l_2cc2;
	case 11463ULL: goto x86_l_2cc7;
	case 11468ULL: goto x86_l_2ccc;
	case 11473ULL: goto x86_l_2cd1;
	case 11478ULL: goto x86_l_2cd6;
	case 11483ULL: goto x86_l_2cdb;
	case 11485ULL: goto x86_l_2cdd;
	case 11490ULL: goto x86_l_2ce2;
	case 11496ULL: goto x86_l_2ce8;
	case 11501ULL: goto x86_l_2ced;
	case 11506ULL: goto x86_l_2cf2;
	case 11511ULL: goto x86_l_2cf7;
	case 11516ULL: goto x86_l_2cfc;
	case 11518ULL: goto x86_l_2cfe;
	case 11523ULL: goto x86_l_2d03;
	case 11529ULL: goto x86_l_2d09;
	case 11533ULL: goto x86_l_2d0d;
	case 11536ULL: goto x86_l_2d10;
	case 11541ULL: goto x86_l_2d15;
	case 11546ULL: goto x86_l_2d1a;
	case 11551ULL: goto x86_l_2d1f;
	case 11554ULL: goto x86_l_2d22;
	case 11556ULL: goto x86_l_2d24;
	case 11560ULL: goto x86_l_2d28;
	case 11566ULL: goto x86_l_2d2e;
	case 11571ULL: goto x86_l_2d33;
	case 11576ULL: goto x86_l_2d38;
	case 11581ULL: goto x86_l_2d3d;
	case 11586ULL: goto x86_l_2d42;
	case 11589ULL: goto x86_l_2d45;
	case 11591ULL: goto x86_l_2d47;
	case 11595ULL: goto x86_l_2d4b;
	case 11600ULL: goto x86_l_2d50;
	case 11605ULL: goto x86_l_2d55;
	case 11610ULL: goto x86_l_2d5a;
	case 11615ULL: goto x86_l_2d5f;
	case 11618ULL: goto x86_l_2d62;
	case 11620ULL: goto x86_l_2d64;
	case 11625ULL: goto x86_l_2d69;
	case 11630ULL: goto x86_l_2d6e;
	case 11634ULL: goto x86_l_2d72;
	case 11637ULL: goto x86_l_2d75;
	case 11642ULL: goto x86_l_2d7a;
	case 11644ULL: goto x86_l_2d7c;
	case 11646ULL: goto x86_l_2d7e;
	case 11649ULL: goto x86_l_2d81;
	case 11652ULL: goto x86_l_2d84;
	case 11657ULL: goto x86_l_2d89;
	case 11659ULL: goto x86_l_2d8b;
	case 11662ULL: goto x86_l_2d8e;
	case 11666ULL: goto x86_l_2d92;
	case 11668ULL: goto x86_l_2d94;
	case 11672ULL: goto x86_l_2d98;
	case 11674ULL: goto x86_l_2d9a;
	case 11677ULL: goto x86_l_2d9d;
	case 11679ULL: goto x86_l_2d9f;
	case 11683ULL: goto x86_l_2da3;
	case 11686ULL: goto x86_l_2da6;
	case 11691ULL: goto x86_l_2dab;
	case 11697ULL: goto x86_l_2db1;
	case 11703ULL: goto x86_l_2db7;
	case 11709ULL: goto x86_l_2dbd;
	case 11712ULL: goto x86_l_2dc0;
	case 11714ULL: goto x86_l_2dc2;
	case 11719ULL: goto x86_l_2dc7;
	case 11721ULL: goto x86_l_2dc9;
	case 11724ULL: goto x86_l_2dcc;
	case 11728ULL: goto x86_l_2dd0;
	case 11731ULL: goto x86_l_2dd3;
	case 11734ULL: goto x86_l_2dd6;
	case 11737ULL: goto x86_l_2dd9;
	case 11742ULL: goto x86_l_2dde;
	case 11744ULL: goto x86_l_2de0;
	case 11749ULL: goto x86_l_2de5;
	case 11752ULL: goto x86_l_2de8;
	case 11757ULL: goto x86_l_2ded;
	case 11763ULL: goto x86_l_2df3;
	case 11768ULL: goto x86_l_2df8;
	case 11773ULL: goto x86_l_2dfd;
	case 11778ULL: goto x86_l_2e02;
	case 11783ULL: goto x86_l_2e07;
	case 11785ULL: goto x86_l_2e09;
	case 11790ULL: goto x86_l_2e0e;
	case 11793ULL: goto x86_l_2e11;
	case 11798ULL: goto x86_l_2e16;
	default: return 0xffffffffffffffffULL;
	}
x86_l_27c3:
	/* 0x27c3: jmp    27da <generic_uprobe_process_event+0x27da> */
	goto x86_l_27da;
x86_l_27c5:
	/* 0x27c5: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_27c9:
	/* 0x27c9: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_27d0:
	/* 0x27d0: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_27d4:
	/* 0x27d4: jmp    27da <generic_uprobe_process_event+0x27da> */
	goto x86_l_27da;
x86_l_27d6:
	/* 0x27d6: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_27da:
	/* 0x27da: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27de:
	/* 0x27de: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27e2:
	/* 0x27e2: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_27e7:
	/* 0x27e7: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_27eb:
	/* 0x27eb: ja     2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ac8;
	}
x86_l_27f1:
	/* 0x27f1: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_27fb:
	/* 0x27fb: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_27ff:
	/* 0x27ff: jae    2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2ac8;
	}
x86_l_2805:
	/* 0x2805: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2809:
	/* 0x2809: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_280c:
	/* 0x280c: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2814:
	/* 0x2814: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2817:
	/* 0x2817: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_281c:
	/* 0x281c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2821:
	/* 0x2821: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2825:
	/* 0x2825: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2828:
	/* 0x2828: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_282b:
	/* 0x282b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2830:
	/* 0x2830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2832:
	/* 0x2832: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2835:
	/* 0x2835: js     28f9 <generic_uprobe_process_event+0x28f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_28f9;
	}
x86_l_283b:
	/* 0x283b: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_283f:
	/* 0x283f: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2842:
	/* 0x2842: jg     285e <generic_uprobe_process_event+0x285e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_285e;
	}
x86_l_2844:
	/* 0x2844: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2846:
	/* 0x2846: je     287b <generic_uprobe_process_event+0x287b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287b;
	}
x86_l_2848:
	/* 0x2848: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_284b:
	/* 0x284b: je     287b <generic_uprobe_process_event+0x287b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287b;
	}
x86_l_284d:
	/* 0x284d: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2850:
	/* 0x2850: jne    289d <generic_uprobe_process_event+0x289d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_289d;
	}
x86_l_2852:
	/* 0x2852: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2858:
	/* 0x2858: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_285c:
	/* 0x285c: jmp    28a1 <generic_uprobe_process_event+0x28a1> */
	goto x86_l_28a1;
x86_l_285e:
	/* 0x285e: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2861:
	/* 0x2861: je     288c <generic_uprobe_process_event+0x288c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_288c;
	}
x86_l_2863:
	/* 0x2863: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2866:
	/* 0x2866: je     287b <generic_uprobe_process_event+0x287b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287b;
	}
x86_l_2868:
	/* 0x2868: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_286d:
	/* 0x286d: jne    289d <generic_uprobe_process_event+0x289d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_289d;
	}
x86_l_286f:
	/* 0x286f: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2875:
	/* 0x2875: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2879:
	/* 0x2879: jmp    28a1 <generic_uprobe_process_event+0x28a1> */
	goto x86_l_28a1;
x86_l_287b:
	/* 0x287b: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_287f:
	/* 0x287f: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2886:
	/* 0x2886: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_288a:
	/* 0x288a: jmp    28a1 <generic_uprobe_process_event+0x28a1> */
	goto x86_l_28a1;
x86_l_288c:
	/* 0x288c: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2890:
	/* 0x2890: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2897:
	/* 0x2897: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_289b:
	/* 0x289b: jmp    28a1 <generic_uprobe_process_event+0x28a1> */
	goto x86_l_28a1;
x86_l_289d:
	/* 0x289d: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_28a1:
	/* 0x28a1: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_28a5:
	/* 0x28a5: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28a9:
	/* 0x28a9: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_28ae:
	/* 0x28ae: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_28b2:
	/* 0x28b2: ja     2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ac8;
	}
x86_l_28b8:
	/* 0x28b8: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_28c2:
	/* 0x28c2: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_28c6:
	/* 0x28c6: jae    2ac8 <generic_uprobe_process_event+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2ac8;
	}
x86_l_28cc:
	/* 0x28cc: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_28d0:
	/* 0x28d0: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_28d3:
	/* 0x28d3: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_28db:
	/* 0x28db: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28de:
	/* 0x28de: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_28e3:
	/* 0x28e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28e8:
	/* 0x28e8: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28ec:
	/* 0x28ec: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28ef:
	/* 0x28ef: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_28f2:
	/* 0x28f2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_28f7:
	/* 0x28f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f9:
	/* 0x28f9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28fc:
	/* 0x28fc: mov    BYTE PTR [rsp+0xb0],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2904:
	/* 0x2904: movzx  eax,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2908:
	/* 0x2908: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_290d:
	/* 0x290d: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2912:
	/* 0x2912: mov    WORD PTR [r15+0x26],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757258ULL);
x86_l_2919:
	/* 0x2919: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_291e:
	/* 0x291e: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2922:
	/* 0x2922: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2927:
	/* 0x2927: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_292c:
	/* 0x292c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_292f:
	/* 0x292f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2934:
	/* 0x2934: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2936:
	/* 0x2936: lea    rdi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_293a:
	/* 0x293a: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_293e:
	/* 0x293e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2943:
	/* 0x2943: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2948:
	/* 0x2948: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_294d:
	/* 0x294d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2950:
	/* 0x2950: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2952:
	/* 0x2952: cmp    r12b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 17ULL);
x86_l_2956:
	/* 0x2956: je     29a9 <generic_uprobe_process_event+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29a9;
	}
x86_l_2958:
	/* 0x2958: movzx  eax,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_295c:
	/* 0x295c: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_295f:
	/* 0x295f: jne    29f4 <generic_uprobe_process_event+0x29f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29f4;
	}
x86_l_2965:
	/* 0x2965: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_296a:
	/* 0x296a: movzx  r12d,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_2973:
	/* 0x2973: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2977:
	/* 0x2977: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_297c:
	/* 0x297c: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2980:
	/* 0x2980: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2985:
	/* 0x2985: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_298a:
	/* 0x298a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_298f:
	/* 0x298f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2991:
	/* 0x2991: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2995:
	/* 0x2995: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2999:
	/* 0x2999: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_299d:
	/* 0x299d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_29a2:
	/* 0x29a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29a7:
	/* 0x29a7: jmp    29eb <generic_uprobe_process_event+0x29eb> */
	goto x86_l_29eb;
x86_l_29a9:
	/* 0x29a9: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29ae:
	/* 0x29ae: movzx  r12d,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_29b7:
	/* 0x29b7: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_29bb:
	/* 0x29bb: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29c0:
	/* 0x29c0: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29c4:
	/* 0x29c4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_29c9:
	/* 0x29c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29ce:
	/* 0x29ce: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_29d3:
	/* 0x29d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d5:
	/* 0x29d5: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_29d9:
	/* 0x29d9: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_29dd:
	/* 0x29dd: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_29e1:
	/* 0x29e1: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_29e6:
	/* 0x29e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29eb:
	/* 0x29eb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_29f0:
	/* 0x29f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f2:
	/* 0x29f2: jmp    2a00 <generic_uprobe_process_event+0x2a00> */
	goto x86_l_2a00;
x86_l_29f4:
	/* 0x29f4: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29f9:
	/* 0x29f9: mov    DWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2a00:
	/* 0x2a00: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a05:
	/* 0x2a05: movzx  eax,WORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_2a09:
	/* 0x2a09: movzx  ecx,WORD PTR [rdx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2a0d:
	/* 0x2a0d: movbe  WORD PTR [rdx+0x20],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_2a13:
	/* 0x2a13: movbe  WORD PTR [rdx+0x22],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2a19:
	/* 0x2a19: add    r13,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_2a20:
	/* 0x2a20: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a25:
	/* 0x2a25: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a2a:
	/* 0x2a2a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a2f:
	/* 0x2a2f: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2a35:
	/* 0x2a35: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a3a:
	/* 0x2a3a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2a3d:
	/* 0x2a3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a3f:
	/* 0x2a3f: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a44:
	/* 0x2a44: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2a47:
	/* 0x2a47: je     2ab0 <generic_uprobe_process_event+0x2ab0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ab0;
	}
x86_l_2a49:
	/* 0x2a49: add    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2a4d:
	/* 0x2a4d: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2a55:
	/* 0x2a55: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a5a:
	/* 0x2a5a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a5f:
	/* 0x2a5f: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a64:
	/* 0x2a64: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2a68:
	/* 0x2a68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a6d:
	/* 0x2a6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a6f:
	/* 0x2a6f: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a74:
	/* 0x2a74: mov    r13,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2a7c:
	/* 0x2a7c: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_2a80:
	/* 0x2a80: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a85:
	/* 0x2a85: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a89:
	/* 0x2a89: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a8e:
	/* 0x2a8e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a93:
	/* 0x2a93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a95:
	/* 0x2a95: add    rbp,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_2a99:
	/* 0x2a99: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_2a9d:
	/* 0x2a9d: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2aa1:
	/* 0x2aa1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2aa6:
	/* 0x2aa6: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2aa9:
	/* 0x2aa9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2aae:
	/* 0x2aae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ab0:
	/* 0x2ab0: mov    r13d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 64ULL);
x86_l_2ab6:
	/* 0x2ab6: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2abe:
	/* 0x2abe: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2ac3:
	/* 0x2ac3: jmp    fab <generic_uprobe_process_event+0xfab> */
	return 4011ULL;
x86_l_2ac8:
	/* 0x2ac8: mov    WORD PTR [rsp+0xb8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2ad0:
	/* 0x2ad0: jmp    28fc <generic_uprobe_process_event+0x28fc> */
	goto x86_l_28fc;
x86_l_2ad5:
	/* 0x2ad5: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ada:
	/* 0x2ada: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2add:
	/* 0x2add: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ae2:
	/* 0x2ae2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ae7:
	/* 0x2ae7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aec:
	/* 0x2aec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aee:
	/* 0x2aee: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2af3:
	/* 0x2af3: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2af7:
	/* 0x2af7: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2afc:
	/* 0x2afc: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b01:
	/* 0x2b01: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_2b07:
	/* 0x2b07: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2b0b:
	/* 0x2b0b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b10:
	/* 0x2b10: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b15:
	/* 0x2b15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b1a:
	/* 0x2b1a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b1d:
	/* 0x2b1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b1f:
	/* 0x2b1f: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b23:
	/* 0x2b23: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b28:
	/* 0x2b28: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b2d:
	/* 0x2b2d: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b32:
	/* 0x2b32: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b37:
	/* 0x2b37: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2b3c:
	/* 0x2b3c: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b41:
	/* 0x2b41: jne    2b4e <generic_uprobe_process_event+0x2b4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b4e;
	}
x86_l_2b43:
	/* 0x2b43: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2b48:
	/* 0x2b48: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_2b4e:
	/* 0x2b4e: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2b53:
	/* 0x2b53: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b58:
	/* 0x2b58: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b5d:
	/* 0x2b5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b62:
	/* 0x2b62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b64:
	/* 0x2b64: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_2b69:
	/* 0x2b69: je     2c6f <generic_uprobe_process_event+0x2c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c6f;
	}
x86_l_2b6f:
	/* 0x2b6f: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b73:
	/* 0x2b73: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b76:
	/* 0x2b76: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b7b:
	/* 0x2b7b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b80:
	/* 0x2b80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b85:
	/* 0x2b85: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2b88:
	/* 0x2b88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b8a:
	/* 0x2b8a: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b8e:
	/* 0x2b8e: je     2c6f <generic_uprobe_process_event+0x2c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c6f;
	}
x86_l_2b94:
	/* 0x2b94: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2b99:
	/* 0x2b99: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b9e:
	/* 0x2b9e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ba3:
	/* 0x2ba3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ba8:
	/* 0x2ba8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2bab:
	/* 0x2bab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bad:
	/* 0x2bad: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2bb1:
	/* 0x2bb1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bb6:
	/* 0x2bb6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2bbb:
	/* 0x2bbb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bc0:
	/* 0x2bc0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2bc5:
	/* 0x2bc5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2bc8:
	/* 0x2bc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bca:
	/* 0x2bca: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2bcf:
	/* 0x2bcf: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2bd4:
	/* 0x2bd4: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2bd8:
	/* 0x2bd8: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2bdb:
	/* 0x2bdb: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2be0:
	/* 0x2be0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2be2:
	/* 0x2be2: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2be4:
	/* 0x2be4: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2be7:
	/* 0x2be7: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2bea:
	/* 0x2bea: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2bef:
	/* 0x2bef: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bf1:
	/* 0x2bf1: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2bf4:
	/* 0x2bf4: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2bf8:
	/* 0x2bf8: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2bfa:
	/* 0x2bfa: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2bfe:
	/* 0x2bfe: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2c00:
	/* 0x2c00: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2c03:
	/* 0x2c03: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c05:
	/* 0x2c05: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2c09:
	/* 0x2c09: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2c0c:
	/* 0x2c0c: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c11:
	/* 0x2c11: jb     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3478ULL;
	}
x86_l_2c17:
	/* 0x2c17: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2c1d:
	/* 0x2c1d: ja     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3478ULL;
	}
x86_l_2c23:
	/* 0x2c23: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2c26:
	/* 0x2c26: jbe    2c2d <generic_uprobe_process_event+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2c2d;
	}
x86_l_2c28:
	/* 0x2c28: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2c2d:
	/* 0x2c2d: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c2f:
	/* 0x2c2f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2c32:
	/* 0x2c32: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2c36:
	/* 0x2c36: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c39:
	/* 0x2c39: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c3c:
	/* 0x2c3c: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c3f:
	/* 0x2c3f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c44:
	/* 0x2c44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c46:
	/* 0x2c46: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2c4b:
	/* 0x2c4b: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2c4e:
	/* 0x2c4e: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c53:
	/* 0x2c53: jbe    d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3478ULL;
	}
x86_l_2c59:
	/* 0x2c59: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2c5e:
	/* 0x2c5e: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c63:
	/* 0x2c63: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c68:
	/* 0x2c68: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c6d:
	/* 0x2c6d: jmp    2cd1 <generic_uprobe_process_event+0x2cd1> */
	goto x86_l_2cd1;
x86_l_2c6f:
	/* 0x2c6f: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c74:
	/* 0x2c74: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c77:
	/* 0x2c77: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c7c:
	/* 0x2c7c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c81:
	/* 0x2c81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c86:
	/* 0x2c86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c88:
	/* 0x2c88: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c8d:
	/* 0x2c8d: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2c91:
	/* 0x2c91: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c96:
	/* 0x2c96: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c9b:
	/* 0x2c9b: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_2ca1:
	/* 0x2ca1: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2ca5:
	/* 0x2ca5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2caa:
	/* 0x2caa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2caf:
	/* 0x2caf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cb4:
	/* 0x2cb4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2cb7:
	/* 0x2cb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb9:
	/* 0x2cb9: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cbd:
	/* 0x2cbd: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2cc2:
	/* 0x2cc2: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cc7:
	/* 0x2cc7: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2ccc:
	/* 0x2ccc: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2cd1:
	/* 0x2cd1: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2cd6:
	/* 0x2cd6: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cdb:
	/* 0x2cdb: jne    2ce8 <generic_uprobe_process_event+0x2ce8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ce8;
	}
x86_l_2cdd:
	/* 0x2cdd: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2ce2:
	/* 0x2ce2: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_2ce8:
	/* 0x2ce8: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2ced:
	/* 0x2ced: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2cf2:
	/* 0x2cf2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cf7:
	/* 0x2cf7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cfc:
	/* 0x2cfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cfe:
	/* 0x2cfe: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_2d03:
	/* 0x2d03: je     2e09 <generic_uprobe_process_event+0x2e09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e09;
	}
x86_l_2d09:
	/* 0x2d09: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d0d:
	/* 0x2d0d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d10:
	/* 0x2d10: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d15:
	/* 0x2d15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d1a:
	/* 0x2d1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d1f:
	/* 0x2d1f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2d22:
	/* 0x2d22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d24:
	/* 0x2d24: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d28:
	/* 0x2d28: je     2e09 <generic_uprobe_process_event+0x2e09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e09;
	}
x86_l_2d2e:
	/* 0x2d2e: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2d33:
	/* 0x2d33: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d38:
	/* 0x2d38: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d3d:
	/* 0x2d3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d42:
	/* 0x2d42: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2d45:
	/* 0x2d45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d47:
	/* 0x2d47: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2d4b:
	/* 0x2d4b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d50:
	/* 0x2d50: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2d55:
	/* 0x2d55: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d5a:
	/* 0x2d5a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2d5f:
	/* 0x2d5f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2d62:
	/* 0x2d62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d64:
	/* 0x2d64: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d69:
	/* 0x2d69: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2d6e:
	/* 0x2d6e: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2d72:
	/* 0x2d72: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2d75:
	/* 0x2d75: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2d7a:
	/* 0x2d7a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d7c:
	/* 0x2d7c: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2d7e:
	/* 0x2d7e: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d81:
	/* 0x2d81: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2d84:
	/* 0x2d84: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2d89:
	/* 0x2d89: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d8b:
	/* 0x2d8b: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2d8e:
	/* 0x2d8e: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2d92:
	/* 0x2d92: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2d94:
	/* 0x2d94: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2d98:
	/* 0x2d98: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d9a:
	/* 0x2d9a: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2d9d:
	/* 0x2d9d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d9f:
	/* 0x2d9f: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2da3:
	/* 0x2da3: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2da6:
	/* 0x2da6: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dab:
	/* 0x2dab: jb     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3478ULL;
	}
x86_l_2db1:
	/* 0x2db1: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2db7:
	/* 0x2db7: ja     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3478ULL;
	}
x86_l_2dbd:
	/* 0x2dbd: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2dc0:
	/* 0x2dc0: jbe    2dc7 <generic_uprobe_process_event+0x2dc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2dc7;
	}
x86_l_2dc2:
	/* 0x2dc2: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2dc7:
	/* 0x2dc7: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dc9:
	/* 0x2dc9: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2dcc:
	/* 0x2dcc: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2dd0:
	/* 0x2dd0: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2dd3:
	/* 0x2dd3: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2dd6:
	/* 0x2dd6: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2dd9:
	/* 0x2dd9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dde:
	/* 0x2dde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de0:
	/* 0x2de0: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2de5:
	/* 0x2de5: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2de8:
	/* 0x2de8: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ded:
	/* 0x2ded: jbe    d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3478ULL;
	}
x86_l_2df3:
	/* 0x2df3: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2df8:
	/* 0x2df8: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2dfd:
	/* 0x2dfd: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e02:
	/* 0x2e02: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e07:
	/* 0x2e07: jmp    2e6b <generic_uprobe_process_event+0x2e6b> */
	return 11883ULL;
x86_l_2e09:
	/* 0x2e09: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e0e:
	/* 0x2e0e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e11:
	/* 0x2e11: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e16:
	/* 0x2e16: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 11803ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11803ULL: goto x86_l_2e1b;
	case 11808ULL: goto x86_l_2e20;
	case 11810ULL: goto x86_l_2e22;
	case 11815ULL: goto x86_l_2e27;
	case 11819ULL: goto x86_l_2e2b;
	case 11824ULL: goto x86_l_2e30;
	case 11829ULL: goto x86_l_2e35;
	case 11835ULL: goto x86_l_2e3b;
	case 11839ULL: goto x86_l_2e3f;
	case 11844ULL: goto x86_l_2e44;
	case 11849ULL: goto x86_l_2e49;
	case 11854ULL: goto x86_l_2e4e;
	case 11857ULL: goto x86_l_2e51;
	case 11859ULL: goto x86_l_2e53;
	case 11863ULL: goto x86_l_2e57;
	case 11868ULL: goto x86_l_2e5c;
	case 11873ULL: goto x86_l_2e61;
	case 11878ULL: goto x86_l_2e66;
	case 11883ULL: goto x86_l_2e6b;
	case 11888ULL: goto x86_l_2e70;
	case 11893ULL: goto x86_l_2e75;
	case 11895ULL: goto x86_l_2e77;
	case 11900ULL: goto x86_l_2e7c;
	case 11906ULL: goto x86_l_2e82;
	case 11911ULL: goto x86_l_2e87;
	case 11916ULL: goto x86_l_2e8c;
	case 11921ULL: goto x86_l_2e91;
	case 11926ULL: goto x86_l_2e96;
	case 11928ULL: goto x86_l_2e98;
	case 11933ULL: goto x86_l_2e9d;
	case 11939ULL: goto x86_l_2ea3;
	case 11943ULL: goto x86_l_2ea7;
	case 11946ULL: goto x86_l_2eaa;
	case 11951ULL: goto x86_l_2eaf;
	case 11956ULL: goto x86_l_2eb4;
	case 11961ULL: goto x86_l_2eb9;
	case 11964ULL: goto x86_l_2ebc;
	case 11966ULL: goto x86_l_2ebe;
	case 11970ULL: goto x86_l_2ec2;
	case 11976ULL: goto x86_l_2ec8;
	case 11981ULL: goto x86_l_2ecd;
	case 11986ULL: goto x86_l_2ed2;
	case 11991ULL: goto x86_l_2ed7;
	case 11996ULL: goto x86_l_2edc;
	case 11999ULL: goto x86_l_2edf;
	case 12001ULL: goto x86_l_2ee1;
	case 12005ULL: goto x86_l_2ee5;
	case 12010ULL: goto x86_l_2eea;
	case 12015ULL: goto x86_l_2eef;
	case 12020ULL: goto x86_l_2ef4;
	case 12025ULL: goto x86_l_2ef9;
	case 12028ULL: goto x86_l_2efc;
	case 12030ULL: goto x86_l_2efe;
	case 12035ULL: goto x86_l_2f03;
	case 12040ULL: goto x86_l_2f08;
	case 12044ULL: goto x86_l_2f0c;
	case 12047ULL: goto x86_l_2f0f;
	case 12052ULL: goto x86_l_2f14;
	case 12054ULL: goto x86_l_2f16;
	case 12056ULL: goto x86_l_2f18;
	case 12059ULL: goto x86_l_2f1b;
	case 12062ULL: goto x86_l_2f1e;
	case 12067ULL: goto x86_l_2f23;
	case 12069ULL: goto x86_l_2f25;
	case 12072ULL: goto x86_l_2f28;
	case 12076ULL: goto x86_l_2f2c;
	case 12078ULL: goto x86_l_2f2e;
	case 12082ULL: goto x86_l_2f32;
	case 12084ULL: goto x86_l_2f34;
	case 12087ULL: goto x86_l_2f37;
	case 12089ULL: goto x86_l_2f39;
	case 12093ULL: goto x86_l_2f3d;
	case 12096ULL: goto x86_l_2f40;
	case 12101ULL: goto x86_l_2f45;
	case 12107ULL: goto x86_l_2f4b;
	case 12113ULL: goto x86_l_2f51;
	case 12119ULL: goto x86_l_2f57;
	case 12122ULL: goto x86_l_2f5a;
	case 12124ULL: goto x86_l_2f5c;
	case 12129ULL: goto x86_l_2f61;
	case 12131ULL: goto x86_l_2f63;
	case 12134ULL: goto x86_l_2f66;
	case 12138ULL: goto x86_l_2f6a;
	case 12141ULL: goto x86_l_2f6d;
	case 12144ULL: goto x86_l_2f70;
	case 12147ULL: goto x86_l_2f73;
	case 12152ULL: goto x86_l_2f78;
	case 12154ULL: goto x86_l_2f7a;
	case 12159ULL: goto x86_l_2f7f;
	case 12162ULL: goto x86_l_2f82;
	case 12167ULL: goto x86_l_2f87;
	case 12173ULL: goto x86_l_2f8d;
	case 12178ULL: goto x86_l_2f92;
	case 12183ULL: goto x86_l_2f97;
	case 12188ULL: goto x86_l_2f9c;
	case 12193ULL: goto x86_l_2fa1;
	case 12196ULL: goto x86_l_2fa4;
	case 12201ULL: goto x86_l_2fa9;
	case 12206ULL: goto x86_l_2fae;
	case 12211ULL: goto x86_l_2fb3;
	case 12213ULL: goto x86_l_2fb5;
	case 12218ULL: goto x86_l_2fba;
	case 12222ULL: goto x86_l_2fbe;
	case 12227ULL: goto x86_l_2fc3;
	case 12232ULL: goto x86_l_2fc8;
	case 12238ULL: goto x86_l_2fce;
	case 12242ULL: goto x86_l_2fd2;
	case 12247ULL: goto x86_l_2fd7;
	case 12252ULL: goto x86_l_2fdc;
	case 12257ULL: goto x86_l_2fe1;
	case 12260ULL: goto x86_l_2fe4;
	case 12262ULL: goto x86_l_2fe6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2e1b:
	/* 0x2e1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e20:
	/* 0x2e20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e22:
	/* 0x2e22: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e27:
	/* 0x2e27: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2e2b:
	/* 0x2e2b: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e30:
	/* 0x2e30: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e35:
	/* 0x2e35: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_2e3b:
	/* 0x2e3b: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2e3f:
	/* 0x2e3f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e44:
	/* 0x2e44: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e49:
	/* 0x2e49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e4e:
	/* 0x2e4e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e51:
	/* 0x2e51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e53:
	/* 0x2e53: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e57:
	/* 0x2e57: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e5c:
	/* 0x2e5c: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e61:
	/* 0x2e61: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e66:
	/* 0x2e66: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e6b:
	/* 0x2e6b: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2e70:
	/* 0x2e70: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e75:
	/* 0x2e75: jne    2e82 <generic_uprobe_process_event+0x2e82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e82;
	}
x86_l_2e77:
	/* 0x2e77: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2e7c:
	/* 0x2e7c: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_2e82:
	/* 0x2e82: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e87:
	/* 0x2e87: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e8c:
	/* 0x2e8c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e91:
	/* 0x2e91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e96:
	/* 0x2e96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e98:
	/* 0x2e98: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_2e9d:
	/* 0x2e9d: je     2f9c <generic_uprobe_process_event+0x2f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f9c;
	}
x86_l_2ea3:
	/* 0x2ea3: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ea7:
	/* 0x2ea7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2eaa:
	/* 0x2eaa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2eaf:
	/* 0x2eaf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2eb4:
	/* 0x2eb4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eb9:
	/* 0x2eb9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2ebc:
	/* 0x2ebc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ebe:
	/* 0x2ebe: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec2:
	/* 0x2ec2: je     2f9c <generic_uprobe_process_event+0x2f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f9c;
	}
x86_l_2ec8:
	/* 0x2ec8: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2ecd:
	/* 0x2ecd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ed2:
	/* 0x2ed2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ed7:
	/* 0x2ed7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2edc:
	/* 0x2edc: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2edf:
	/* 0x2edf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ee1:
	/* 0x2ee1: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2ee5:
	/* 0x2ee5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2eea:
	/* 0x2eea: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2eef:
	/* 0x2eef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ef4:
	/* 0x2ef4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ef9:
	/* 0x2ef9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2efc:
	/* 0x2efc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2efe:
	/* 0x2efe: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f03:
	/* 0x2f03: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2f08:
	/* 0x2f08: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2f0c:
	/* 0x2f0c: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2f0f:
	/* 0x2f0f: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2f14:
	/* 0x2f14: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f16:
	/* 0x2f16: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2f18:
	/* 0x2f18: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f1b:
	/* 0x2f1b: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2f1e:
	/* 0x2f1e: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2f23:
	/* 0x2f23: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f25:
	/* 0x2f25: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2f28:
	/* 0x2f28: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2f2c:
	/* 0x2f2c: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2f2e:
	/* 0x2f2e: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2f32:
	/* 0x2f32: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2f34:
	/* 0x2f34: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2f37:
	/* 0x2f37: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f39:
	/* 0x2f39: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2f3d:
	/* 0x2f3d: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2f40:
	/* 0x2f40: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f45:
	/* 0x2f45: jb     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3478ULL;
	}
x86_l_2f4b:
	/* 0x2f4b: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2f51:
	/* 0x2f51: ja     d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3478ULL;
	}
x86_l_2f57:
	/* 0x2f57: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2f5a:
	/* 0x2f5a: jbe    2f61 <generic_uprobe_process_event+0x2f61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f61;
	}
x86_l_2f5c:
	/* 0x2f5c: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2f61:
	/* 0x2f61: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f63:
	/* 0x2f63: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2f66:
	/* 0x2f66: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2f6a:
	/* 0x2f6a: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2f6d:
	/* 0x2f6d: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f70:
	/* 0x2f70: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f73:
	/* 0x2f73: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f78:
	/* 0x2f78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f7a:
	/* 0x2f7a: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2f7f:
	/* 0x2f7f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2f82:
	/* 0x2f82: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f87:
	/* 0x2f87: jbe    d96 <generic_uprobe_process_event+0xd96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3478ULL;
	}
x86_l_2f8d:
	/* 0x2f8d: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2f92:
	/* 0x2f92: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f97:
	/* 0x2f97: jmp    d96 <generic_uprobe_process_event+0xd96> */
	return 3478ULL;
x86_l_2f9c:
	/* 0x2f9c: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fa1:
	/* 0x2fa1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fa4:
	/* 0x2fa4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fa9:
	/* 0x2fa9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fae:
	/* 0x2fae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fb3:
	/* 0x2fb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb5:
	/* 0x2fb5: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2fba:
	/* 0x2fba: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2fbe:
	/* 0x2fbe: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fc3:
	/* 0x2fc3: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2fc8:
	/* 0x2fc8: je     d91 <generic_uprobe_process_event+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3473ULL;
	}
x86_l_2fce:
	/* 0x2fce: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2fd2:
	/* 0x2fd2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fd7:
	/* 0x2fd7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fdc:
	/* 0x2fdc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fe1:
	/* 0x2fe1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2fe4:
	/* 0x2fe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe6:
	/* 0x2fe6: jmp    d96 <generic_uprobe_process_event+0xd96> */
	return 3478ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11200U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1817ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1820ULL && __x86_pc <= 3643ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3648ULL && __x86_pc <= 5288ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5294ULL && __x86_pc <= 6969ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6974ULL && __x86_pc <= 8604ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8609ULL && __x86_pc <= 10175ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10179ULL && __x86_pc <= 11798ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11803ULL && __x86_pc <= 12262ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

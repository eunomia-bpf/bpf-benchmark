extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
extern char filter_map;
extern char heap_ro_zero;
extern char process_call_heap;
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
extern char uprobe_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_0(
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
	case 141ULL: goto x86_l_8d;
	case 143ULL: goto x86_l_8f;
	case 148ULL: goto x86_l_94;
	case 152ULL: goto x86_l_98;
	case 156ULL: goto x86_l_9c;
	case 160ULL: goto x86_l_a0;
	case 164ULL: goto x86_l_a4;
	case 169ULL: goto x86_l_a9;
	case 173ULL: goto x86_l_ad;
	case 176ULL: goto x86_l_b0;
	case 180ULL: goto x86_l_b4;
	case 182ULL: goto x86_l_b6;
	case 188ULL: goto x86_l_bc;
	case 192ULL: goto x86_l_c0;
	case 195ULL: goto x86_l_c3;
	case 197ULL: goto x86_l_c5;
	case 202ULL: goto x86_l_ca;
	case 206ULL: goto x86_l_ce;
	case 209ULL: goto x86_l_d1;
	case 211ULL: goto x86_l_d3;
	case 217ULL: goto x86_l_d9;
	case 221ULL: goto x86_l_dd;
	case 224ULL: goto x86_l_e0;
	case 226ULL: goto x86_l_e2;
	case 231ULL: goto x86_l_e7;
	case 235ULL: goto x86_l_eb;
	case 238ULL: goto x86_l_ee;
	case 241ULL: goto x86_l_f1;
	case 247ULL: goto x86_l_f7;
	case 252ULL: goto x86_l_fc;
	case 254ULL: goto x86_l_fe;
	case 258ULL: goto x86_l_102;
	case 264ULL: goto x86_l_108;
	case 266ULL: goto x86_l_10a;
	case 272ULL: goto x86_l_110;
	case 280ULL: goto x86_l_118;
	case 283ULL: goto x86_l_11b;
	case 285ULL: goto x86_l_11d;
	case 288ULL: goto x86_l_120;
	case 294ULL: goto x86_l_126;
	case 296ULL: goto x86_l_128;
	case 302ULL: goto x86_l_12e;
	case 305ULL: goto x86_l_131;
	case 311ULL: goto x86_l_137;
	case 313ULL: goto x86_l_139;
	case 316ULL: goto x86_l_13c;
	case 322ULL: goto x86_l_142;
	case 325ULL: goto x86_l_145;
	case 331ULL: goto x86_l_14b;
	case 334ULL: goto x86_l_14e;
	case 340ULL: goto x86_l_154;
	case 343ULL: goto x86_l_157;
	case 349ULL: goto x86_l_15d;
	case 351ULL: goto x86_l_15f;
	case 356ULL: goto x86_l_164;
	case 360ULL: goto x86_l_168;
	case 368ULL: goto x86_l_170;
	case 371ULL: goto x86_l_173;
	case 379ULL: goto x86_l_17b;
	case 384ULL: goto x86_l_180;
	case 392ULL: goto x86_l_188;
	case 397ULL: goto x86_l_18d;
	case 402ULL: goto x86_l_192;
	case 407ULL: goto x86_l_197;
	case 412ULL: goto x86_l_19c;
	case 419ULL: goto x86_l_1a3;
	case 426ULL: goto x86_l_1aa;
	case 431ULL: goto x86_l_1af;
	case 436ULL: goto x86_l_1b4;
	case 439ULL: goto x86_l_1b7;
	case 444ULL: goto x86_l_1bc;
	case 446ULL: goto x86_l_1be;
	case 453ULL: goto x86_l_1c5;
	case 458ULL: goto x86_l_1ca;
	case 463ULL: goto x86_l_1cf;
	case 466ULL: goto x86_l_1d2;
	case 471ULL: goto x86_l_1d7;
	case 473ULL: goto x86_l_1d9;
	case 475ULL: goto x86_l_1db;
	case 482ULL: goto x86_l_1e2;
	case 484ULL: goto x86_l_1e4;
	case 485ULL: goto x86_l_1e5;
	case 490ULL: goto x86_l_1ea;
	case 492ULL: goto x86_l_1ec;
	case 500ULL: goto x86_l_1f4;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 515ULL: goto x86_l_203;
	case 517ULL: goto x86_l_205;
	case 522ULL: goto x86_l_20a;
	case 530ULL: goto x86_l_212;
	case 532ULL: goto x86_l_214;
	case 537ULL: goto x86_l_219;
	case 545ULL: goto x86_l_221;
	case 547ULL: goto x86_l_223;
	case 552ULL: goto x86_l_228;
	case 560ULL: goto x86_l_230;
	case 562ULL: goto x86_l_232;
	case 567ULL: goto x86_l_237;
	case 575ULL: goto x86_l_23f;
	case 577ULL: goto x86_l_241;
	case 584ULL: goto x86_l_248;
	case 591ULL: goto x86_l_24f;
	case 596ULL: goto x86_l_254;
	case 601ULL: goto x86_l_259;
	case 604ULL: goto x86_l_25c;
	case 609ULL: goto x86_l_261;
	case 611ULL: goto x86_l_263;
	case 615ULL: goto x86_l_267;
	case 620ULL: goto x86_l_26c;
	case 622ULL: goto x86_l_26e;
	case 627ULL: goto x86_l_273;
	case 632ULL: goto x86_l_278;
	case 639ULL: goto x86_l_27f;
	case 644ULL: goto x86_l_284;
	case 649ULL: goto x86_l_289;
	case 651ULL: goto x86_l_28b;
	case 654ULL: goto x86_l_28e;
	case 660ULL: goto x86_l_294;
	case 667ULL: goto x86_l_29b;
	case 672ULL: goto x86_l_2a0;
	case 677ULL: goto x86_l_2a5;
	case 679ULL: goto x86_l_2a7;
	case 684ULL: goto x86_l_2ac;
	case 686ULL: goto x86_l_2ae;
	case 691ULL: goto x86_l_2b3;
	case 696ULL: goto x86_l_2b8;
	case 699ULL: goto x86_l_2bb;
	case 702ULL: goto x86_l_2be;
	case 710ULL: goto x86_l_2c6;
	case 716ULL: goto x86_l_2cc;
	case 719ULL: goto x86_l_2cf;
	case 723ULL: goto x86_l_2d3;
	case 729ULL: goto x86_l_2d9;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 749ULL: goto x86_l_2ed;
	case 755ULL: goto x86_l_2f3;
	case 758ULL: goto x86_l_2f6;
	case 765ULL: goto x86_l_2fd;
	case 770ULL: goto x86_l_302;
	case 773ULL: goto x86_l_305;
	case 779ULL: goto x86_l_30b;
	case 782ULL: goto x86_l_30e;
	case 786ULL: goto x86_l_312;
	case 790ULL: goto x86_l_316;
	case 796ULL: goto x86_l_31c;
	case 805ULL: goto x86_l_325;
	case 811ULL: goto x86_l_32b;
	case 819ULL: goto x86_l_333;
	case 825ULL: goto x86_l_339;
	case 829ULL: goto x86_l_33d;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 844ULL: goto x86_l_34c;
	case 846ULL: goto x86_l_34e;
	case 849ULL: goto x86_l_351;
	case 851ULL: goto x86_l_353;
	case 854ULL: goto x86_l_356;
	case 857ULL: goto x86_l_359;
	case 863ULL: goto x86_l_35f;
	case 866ULL: goto x86_l_362;
	case 872ULL: goto x86_l_368;
	case 877ULL: goto x86_l_36d;
	case 880ULL: goto x86_l_370;
	case 882ULL: goto x86_l_372;
	case 885ULL: goto x86_l_375;
	case 888ULL: goto x86_l_378;
	case 890ULL: goto x86_l_37a;
	case 893ULL: goto x86_l_37d;
	case 896ULL: goto x86_l_380;
	case 902ULL: goto x86_l_386;
	case 905ULL: goto x86_l_389;
	case 911ULL: goto x86_l_38f;
	case 915ULL: goto x86_l_393;
	case 920ULL: goto x86_l_398;
	case 923ULL: goto x86_l_39b;
	case 929ULL: goto x86_l_3a1;
	case 932ULL: goto x86_l_3a4;
	case 935ULL: goto x86_l_3a7;
	case 941ULL: goto x86_l_3ad;
	case 944ULL: goto x86_l_3b0;
	case 947ULL: goto x86_l_3b3;
	case 953ULL: goto x86_l_3b9;
	case 958ULL: goto x86_l_3be;
	case 961ULL: goto x86_l_3c1;
	case 967ULL: goto x86_l_3c7;
	case 970ULL: goto x86_l_3ca;
	case 972ULL: goto x86_l_3cc;
	case 975ULL: goto x86_l_3cf;
	case 981ULL: goto x86_l_3d5;
	case 984ULL: goto x86_l_3d8;
	case 990ULL: goto x86_l_3de;
	case 993ULL: goto x86_l_3e1;
	case 999ULL: goto x86_l_3e7;
	case 1002ULL: goto x86_l_3ea;
	case 1008ULL: goto x86_l_3f0;
	case 1010ULL: goto x86_l_3f2;
	case 1020ULL: goto x86_l_3fc;
	case 1024ULL: goto x86_l_400;
	case 1030ULL: goto x86_l_406;
	case 1035ULL: goto x86_l_40b;
	case 1039ULL: goto x86_l_40f;
	case 1045ULL: goto x86_l_415;
	case 1055ULL: goto x86_l_41f;
	case 1059ULL: goto x86_l_423;
	case 1065ULL: goto x86_l_429;
	case 1068ULL: goto x86_l_42c;
	case 1074ULL: goto x86_l_432;
	case 1076ULL: goto x86_l_434;
	case 1081ULL: goto x86_l_439;
	case 1085ULL: goto x86_l_43d;
	case 1091ULL: goto x86_l_443;
	case 1096ULL: goto x86_l_448;
	case 1099ULL: goto x86_l_44b;
	case 1105ULL: goto x86_l_451;
	case 1108ULL: goto x86_l_454;
	case 1111ULL: goto x86_l_457;
	case 1117ULL: goto x86_l_45d;
	case 1122ULL: goto x86_l_462;
	case 1124ULL: goto x86_l_464;
	case 1130ULL: goto x86_l_46a;
	case 1135ULL: goto x86_l_46f;
	case 1138ULL: goto x86_l_472;
	case 1141ULL: goto x86_l_475;
	case 1147ULL: goto x86_l_47b;
	case 1150ULL: goto x86_l_47e;
	case 1156ULL: goto x86_l_484;
	case 1159ULL: goto x86_l_487;
	case 1165ULL: goto x86_l_48d;
	case 1170ULL: goto x86_l_492;
	case 1173ULL: goto x86_l_495;
	case 1175ULL: goto x86_l_497;
	case 1178ULL: goto x86_l_49a;
	case 1180ULL: goto x86_l_49c;
	case 1183ULL: goto x86_l_49f;
	case 1189ULL: goto x86_l_4a5;
	case 1198ULL: goto x86_l_4ae;
	case 1207ULL: goto x86_l_4b7;
	case 1216ULL: goto x86_l_4c0;
	case 1225ULL: goto x86_l_4c9;
	case 1234ULL: goto x86_l_4d2;
	case 1237ULL: goto x86_l_4d5;
	case 1243ULL: goto x86_l_4db;
	case 1246ULL: goto x86_l_4de;
	case 1252ULL: goto x86_l_4e4;
	case 1255ULL: goto x86_l_4e7;
	case 1260ULL: goto x86_l_4ec;
	case 1263ULL: goto x86_l_4ef;
	case 1269ULL: goto x86_l_4f5;
	case 1274ULL: goto x86_l_4fa;
	case 1278ULL: goto x86_l_4fe;
	case 1282ULL: goto x86_l_502;
	case 1285ULL: goto x86_l_505;
	case 1291ULL: goto x86_l_50b;
	case 1294ULL: goto x86_l_50e;
	case 1297ULL: goto x86_l_511;
	case 1303ULL: goto x86_l_517;
	case 1306ULL: goto x86_l_51a;
	case 1312ULL: goto x86_l_520;
	case 1317ULL: goto x86_l_525;
	case 1320ULL: goto x86_l_528;
	case 1326ULL: goto x86_l_52e;
	case 1331ULL: goto x86_l_533;
	case 1334ULL: goto x86_l_536;
	case 1340ULL: goto x86_l_53c;
	case 1343ULL: goto x86_l_53f;
	case 1349ULL: goto x86_l_545;
	case 1352ULL: goto x86_l_548;
	case 1355ULL: goto x86_l_54b;
	case 1361ULL: goto x86_l_551;
	case 1364ULL: goto x86_l_554;
	case 1370ULL: goto x86_l_55a;
	case 1375ULL: goto x86_l_55f;
	case 1378ULL: goto x86_l_562;
	case 1384ULL: goto x86_l_568;
	case 1387ULL: goto x86_l_56b;
	case 1393ULL: goto x86_l_571;
	case 1397ULL: goto x86_l_575;
	case 1402ULL: goto x86_l_57a;
	case 1406ULL: goto x86_l_57e;
	case 1409ULL: goto x86_l_581;
	case 1415ULL: goto x86_l_587;
	case 1418ULL: goto x86_l_58a;
	case 1421ULL: goto x86_l_58d;
	case 1427ULL: goto x86_l_593;
	case 1438ULL: goto x86_l_59e;
	case 1444ULL: goto x86_l_5a4;
	case 1448ULL: goto x86_l_5a8;
	case 1454ULL: goto x86_l_5ae;
	case 1458ULL: goto x86_l_5b2;
	case 1464ULL: goto x86_l_5b8;
	case 1467ULL: goto x86_l_5bb;
	case 1470ULL: goto x86_l_5be;
	case 1473ULL: goto x86_l_5c1;
	case 1476ULL: goto x86_l_5c4;
	case 1478ULL: goto x86_l_5c6;
	case 1481ULL: goto x86_l_5c9;
	case 1483ULL: goto x86_l_5cb;
	case 1486ULL: goto x86_l_5ce;
	case 1488ULL: goto x86_l_5d0;
	case 1490ULL: goto x86_l_5d2;
	case 1493ULL: goto x86_l_5d5;
	case 1496ULL: goto x86_l_5d8;
	case 1498ULL: goto x86_l_5da;
	case 1500ULL: goto x86_l_5dc;
	case 1503ULL: goto x86_l_5df;
	case 1507ULL: goto x86_l_5e3;
	case 1511ULL: goto x86_l_5e7;
	case 1517ULL: goto x86_l_5ed;
	case 1521ULL: goto x86_l_5f1;
	case 1528ULL: goto x86_l_5f8;
	case 1532ULL: goto x86_l_5fc;
	case 1535ULL: goto x86_l_5ff;
	case 1540ULL: goto x86_l_604;
	case 1544ULL: goto x86_l_608;
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1552ULL: goto x86_l_610;
	case 1554ULL: goto x86_l_612;
	case 1556ULL: goto x86_l_614;
	case 1562ULL: goto x86_l_61a;
	case 1565ULL: goto x86_l_61d;
	case 1571ULL: goto x86_l_623;
	case 1573ULL: goto x86_l_625;
	case 1578ULL: goto x86_l_62a;
	case 1582ULL: goto x86_l_62e;
	case 1588ULL: goto x86_l_634;
	case 1593ULL: goto x86_l_639;
	case 1597ULL: goto x86_l_63d;
	case 1603ULL: goto x86_l_643;
	case 1613ULL: goto x86_l_64d;
	case 1617ULL: goto x86_l_651;
	case 1623ULL: goto x86_l_657;
	case 1630ULL: goto x86_l_65e;
	case 1636ULL: goto x86_l_664;
	case 1642ULL: goto x86_l_66a;
	case 1645ULL: goto x86_l_66d;
	case 1648ULL: goto x86_l_670;
	case 1652ULL: goto x86_l_674;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1671ULL: goto x86_l_687;
	case 1673ULL: goto x86_l_689;
	case 1677ULL: goto x86_l_68d;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1688ULL: goto x86_l_698;
	case 1693ULL: goto x86_l_69d;
	case 1695ULL: goto x86_l_69f;
	case 1701ULL: goto x86_l_6a5;
	case 1706ULL: goto x86_l_6aa;
	case 1711ULL: goto x86_l_6af;
	case 1716ULL: goto x86_l_6b4;
	case 1718ULL: goto x86_l_6b6;
	case 1724ULL: goto x86_l_6bc;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_18:
	/* 0x18: mov    rdi,QWORD PTR [rip+0x1ee97] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
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
	/* 0x31: je     1d9 <generic_uprobe_filter_arg+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d9;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    r12d,DWORD PTR [rax+0x5f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_41:
	/* 0x41: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_48:
	/* 0x48: mov    rdi,QWORD PTR [rip+0x1ee97] */
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
	/* 0x59: je     1be <generic_uprobe_filter_arg+0x1be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1be;
	}
x86_l_5f:
	/* 0x5f: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_67:
	/* 0x67: je     1be <generic_uprobe_filter_arg+0x1be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1be;
	}
x86_l_6d:
	/* 0x6d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_70:
	/* 0x70: mov    QWORD PTR [rsp+0xb8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_78:
	/* 0x78: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_7b:
	/* 0x7b: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_7e:
	/* 0x7e: cmp    BYTE PTR [r14+rax*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699072ULL);
x86_l_87:
	/* 0x87: je     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_110;
	}
x86_l_8d:
	/* 0x8d: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8f:
	/* 0x8f: mov    ecx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_94:
	/* 0x94: lea    rdx,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_98:
	/* 0x98: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_9c:
	/* 0x9c: lea    rax,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_a0:
	/* 0xa0: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a4:
	/* 0xa4: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_a9:
	/* 0xa9: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_ad:
	/* 0xad: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b0:
	/* 0xb0: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_b4:
	/* 0xb4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_b6:
	/* 0xb6: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_bc:
	/* 0xbc: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_c0:
	/* 0xc0: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c3:
	/* 0xc3: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_c5:
	/* 0xc5: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_ca:
	/* 0xca: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_ce:
	/* 0xce: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d1:
	/* 0xd1: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d3:
	/* 0xd3: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_d9:
	/* 0xd9: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_dd:
	/* 0xdd: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e0:
	/* 0xe0: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_e2:
	/* 0xe2: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_e7:
	/* 0xe7: mov    r9d,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_eb:
	/* 0xeb: add    r9,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ee:
	/* 0xee: mov    edi,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R9, X86_WIDTH_32);
x86_l_f1:
	/* 0xf1: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_f7:
	/* 0xf7: cmp    DWORD PTR [r15+rdi*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 25ULL);
x86_l_fc:
	/* 0xfc: jae    164 <generic_uprobe_filter_arg+0x164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_164;
	}
x86_l_fe:
	/* 0xfe: cmp    rdi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_64, 1ULL);
x86_l_102:
	/* 0x102: je     1be <generic_uprobe_filter_arg+0x1be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1be;
	}
x86_l_108:
	/* 0x108: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_10a:
	/* 0x10a: jne    19c <generic_uprobe_filter_arg+0x19c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19c;
	}
x86_l_110:
	/* 0x110: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_118:
	/* 0x118: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11b:
	/* 0x11b: jg     139 <generic_uprobe_filter_arg+0x139> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_139;
	}
x86_l_11d:
	/* 0x11d: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_120:
	/* 0x120: je     1ea <generic_uprobe_filter_arg+0x1ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ea;
	}
x86_l_126:
	/* 0x126: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_128:
	/* 0x128: je     1f6 <generic_uprobe_filter_arg+0x1f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f6;
	}
x86_l_12e:
	/* 0x12e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_131:
	/* 0x131: je     205 <generic_uprobe_filter_arg+0x205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_205;
	}
x86_l_137:
	/* 0x137: jmp    154 <generic_uprobe_filter_arg+0x154> */
	goto x86_l_154;
x86_l_139:
	/* 0x139: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13c:
	/* 0x13c: je     214 <generic_uprobe_filter_arg+0x214> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214;
	}
x86_l_142:
	/* 0x142: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_145:
	/* 0x145: je     223 <generic_uprobe_filter_arg+0x223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223;
	}
x86_l_14b:
	/* 0x14b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14e:
	/* 0x14e: je     232 <generic_uprobe_filter_arg+0x232> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_232;
	}
x86_l_154:
	/* 0x154: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_157:
	/* 0x157: jg     263 <generic_uprobe_filter_arg+0x263> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_263;
	}
x86_l_15d:
	/* 0x15d: inc    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_15f:
	/* 0x15f: jmp    241 <generic_uprobe_filter_arg+0x241> */
	goto x86_l_241;
x86_l_164:
	/* 0x164: lea    rax,[r15+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_168:
	/* 0x168: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_170:
	/* 0x170: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_173:
	/* 0x173: lea    rax,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_17b:
	/* 0x17b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_180:
	/* 0x180: mov    QWORD PTR [rsp+0xb0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_188:
	/* 0x188: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18d:
	/* 0x18d: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_192:
	/* 0x192: mov    QWORD PTR [rsp+0x78],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_197:
	/* 0x197: jmp    2d9 <generic_uprobe_filter_arg+0x2d9> */
	goto x86_l_2d9;
x86_l_19c:
	/* 0x19c: mov    DWORD PTR [r14+0x5f04],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_1a3:
	/* 0x1a3: mov    rsi,QWORD PTR [rip+0x1ee97] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_1aa:
	/* 0x1aa: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1af:
	/* 0x1af: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1b4:
	/* 0x1b4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b7:
	/* 0x1b7: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1bc:
	/* 0x1bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be:
	/* 0x1be: mov    rsi,QWORD PTR [rip+0x1ee97] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_1c5:
	/* 0x1c5: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1ca:
	/* 0x1ca: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1cf:
	/* 0x1cf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d2:
	/* 0x1d2: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1d7:
	/* 0x1d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9:
	/* 0x1d9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1db:
	/* 0x1db: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_1e2:
	/* 0x1e2: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1e4:
	/* 0x1e4: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1e5:
	/* 0x1e5: jmp    3850 <native_bpf_strncasestr+0x72> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1ea:
	/* 0x1ea: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ec:
	/* 0x1ec: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_1f4:
	/* 0x1f4: jne    241 <generic_uprobe_filter_arg+0x241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_241;
	}
x86_l_1f6:
	/* 0x1f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fb:
	/* 0x1fb: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_203:
	/* 0x203: jne    241 <generic_uprobe_filter_arg+0x241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_241;
	}
x86_l_205:
	/* 0x205: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_20a:
	/* 0x20a: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_212:
	/* 0x212: jne    241 <generic_uprobe_filter_arg+0x241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_241;
	}
x86_l_214:
	/* 0x214: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_219:
	/* 0x219: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_221:
	/* 0x221: jne    241 <generic_uprobe_filter_arg+0x241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_241;
	}
x86_l_223:
	/* 0x223: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_228:
	/* 0x228: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_230:
	/* 0x230: jne    241 <generic_uprobe_filter_arg+0x241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_241;
	}
x86_l_232:
	/* 0x232: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_237:
	/* 0x237: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_23f:
	/* 0x23f: je     263 <generic_uprobe_filter_arg+0x263> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_263;
	}
x86_l_241:
	/* 0x241: mov    DWORD PTR [r14+0x5f00],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_248:
	/* 0x248: mov    rsi,QWORD PTR [rip+0x1ee9a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_24f:
	/* 0x24f: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_254:
	/* 0x254: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_259:
	/* 0x259: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_25c:
	/* 0x25c: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_261:
	/* 0x261: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_263:
	/* 0x263: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_267:
	/* 0x267: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_26c:
	/* 0x26c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e:
	/* 0x26e: mov    QWORD PTR [rsp+0x40],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_273:
	/* 0x273: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_278:
	/* 0x278: mov    rdi,QWORD PTR [rip+0x1ee9a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_27f:
	/* 0x27f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_284:
	/* 0x284: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_289:
	/* 0x289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b:
	/* 0x28b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28e:
	/* 0x28e: je     1d9 <generic_uprobe_filter_arg+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d9;
	}
x86_l_294:
	/* 0x294: mov    rdi,QWORD PTR [rip+0x1ee9a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_29b:
	/* 0x29b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a0:
	/* 0x2a0: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2a5:
	/* 0x2a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7:
	/* 0x2a7: jmp    1d9 <generic_uprobe_filter_arg+0x1d9> */
	goto x86_l_1d9;
x86_l_2ac:
	/* 0x2ac: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ae:
	/* 0x2ae: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b3:
	/* 0x2b3: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b8:
	/* 0x2b8: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_2bb:
	/* 0x2bb: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2be:
	/* 0x2be: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2c6:
	/* 0x2c6: je     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_110;
	}
x86_l_2cc:
	/* 0x2cc: inc    r11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2cf:
	/* 0x2cf: cmp    r11,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 5ULL);
x86_l_2d3:
	/* 0x2d3: je     fe <generic_uprobe_filter_arg+0xfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fe;
	}
x86_l_2d9:
	/* 0x2d9: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2e1:
	/* 0x2e1: mov    r12d,DWORD PTR [rax+r11*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 2), 4ULL);
x86_l_2e6:
	/* 0x2e6: test   r12d,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1023ULL);
x86_l_2ed:
	/* 0x2ed: je     fe <generic_uprobe_filter_arg+0xfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fe;
	}
x86_l_2f3:
	/* 0x2f3: add    r12d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2f6:
	/* 0x2f6: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_2fd:
	/* 0x2fd: mov    eax,DWORD PTR [r15+r12*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_302:
	/* 0x302: cmp    eax,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_305:
	/* 0x305: je     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_110;
	}
x86_l_30b:
	/* 0x30b: add    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30e:
	/* 0x30e: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_312:
	/* 0x312: cmp    rcx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4ULL);
x86_l_316:
	/* 0x316: ja     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_110;
	}
x86_l_31c:
	/* 0x31c: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_325:
	/* 0x325: jne    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_110;
	}
x86_l_32b:
	/* 0x32b: mov    rcx,QWORD PTR [r14+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_333:
	/* 0x333: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_339:
	/* 0x339: lea    r13,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_33d:
	/* 0x33d: add    r13,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_344:
	/* 0x344: mov    ecx,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_349:
	/* 0x349: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_34c:
	/* 0x34c: jle    36d <generic_uprobe_filter_arg+0x36d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_36d;
	}
x86_l_34e:
	/* 0x34e: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_351:
	/* 0x351: jg     398 <generic_uprobe_filter_arg+0x398> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_398;
	}
x86_l_353:
	/* 0x353: lea    edx,[rcx-0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551588ULL);
x86_l_356:
	/* 0x356: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_359:
	/* 0x359: jb     3de <generic_uprobe_filter_arg+0x3de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3de;
	}
x86_l_35f:
	/* 0x35f: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_362:
	/* 0x362: je     604 <generic_uprobe_filter_arg+0x604> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_604;
	}
x86_l_368:
	/* 0x368: jmp    2cc <generic_uprobe_filter_arg+0x2cc> */
	goto x86_l_2cc;
x86_l_36d:
	/* 0x36d: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_370:
	/* 0x370: jle    3be <generic_uprobe_filter_arg+0x3be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3be;
	}
x86_l_372:
	/* 0x372: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_375:
	/* 0x375: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_378:
	/* 0x378: jb     3de <generic_uprobe_filter_arg+0x3de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3de;
	}
x86_l_37a:
	/* 0x37a: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_37d:
	/* 0x37d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_380:
	/* 0x380: jb     604 <generic_uprobe_filter_arg+0x604> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_604;
	}
x86_l_386:
	/* 0x386: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_389:
	/* 0x389: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cc;
	}
x86_l_38f:
	/* 0x38f: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_393:
	/* 0x393: jmp    604 <generic_uprobe_filter_arg+0x604> */
	goto x86_l_604;
x86_l_398:
	/* 0x398: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_39b:
	/* 0x39b: jg     55f <generic_uprobe_filter_arg+0x55f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_55f;
	}
x86_l_3a1:
	/* 0x3a1: lea    edx,[rcx-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_3a4:
	/* 0x3a4: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3a7:
	/* 0x3a7: jb     4fa <generic_uprobe_filter_arg+0x4fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4fa;
	}
x86_l_3ad:
	/* 0x3ad: lea    edx,[rcx-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_3b0:
	/* 0x3b0: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3b3:
	/* 0x3b3: jb     4a5 <generic_uprobe_filter_arg+0x4a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4a5;
	}
x86_l_3b9:
	/* 0x3b9: jmp    2cc <generic_uprobe_filter_arg+0x2cc> */
	goto x86_l_2cc;
x86_l_3be:
	/* 0x3be: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3c1:
	/* 0x3c1: jg     492 <generic_uprobe_filter_arg+0x492> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_492;
	}
x86_l_3c7:
	/* 0x3c7: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3ca:
	/* 0x3ca: je     3de <generic_uprobe_filter_arg+0x3de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3de;
	}
x86_l_3cc:
	/* 0x3cc: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3cf:
	/* 0x3cf: je     bc1 <generic_uprobe_filter_arg+0xbc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3009ULL;
	}
x86_l_3d5:
	/* 0x3d5: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3d8:
	/* 0x3d8: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cc;
	}
x86_l_3de:
	/* 0x3de: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_3e1:
	/* 0x3e1: jle    46f <generic_uprobe_filter_arg+0x46f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_46f;
	}
x86_l_3e7:
	/* 0x3e7: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_3ea:
	/* 0x3ea: ja     72c <generic_uprobe_filter_arg+0x72c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1836ULL;
	}
x86_l_3f0:
	/* 0x3f0: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_3f2:
	/* 0x3f2: movabs rsi,0x1e00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 128849018880ULL);
x86_l_3fc:
	/* 0x3fc: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_400:
	/* 0x400: jb     533 <generic_uprobe_filter_arg+0x533> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_533;
	}
x86_l_406:
	/* 0x406: mov    esi,0x60000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1610612736ULL);
x86_l_40b:
	/* 0x40b: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_40f:
	/* 0x40f: jb     987 <generic_uprobe_filter_arg+0x987> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2439ULL;
	}
x86_l_415:
	/* 0x415: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_41f:
	/* 0x41f: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_423:
	/* 0x423: jae    72c <generic_uprobe_filter_arg+0x72c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 1836ULL;
	}
x86_l_429:
	/* 0x429: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_42c:
	/* 0x42c: ja     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_110;
	}
x86_l_432:
	/* 0x432: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_434:
	/* 0x434: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_439:
	/* 0x439: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_43d:
	/* 0x43d: jae    10fc <generic_uprobe_filter_arg+0x10fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4348ULL;
	}
x86_l_443:
	/* 0x443: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_448:
	/* 0x448: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_44b:
	/* 0x44b: jle    1676 <generic_uprobe_filter_arg+0x1676> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5750ULL;
	}
x86_l_451:
	/* 0x451: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_454:
	/* 0x454: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_457:
	/* 0x457: jae    1e65 <generic_uprobe_filter_arg+0x1e65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7781ULL;
	}
x86_l_45d:
	/* 0x45d: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_462:
	/* 0x462: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_464:
	/* 0x464: jne    1fa9 <generic_uprobe_filter_arg+0x1fa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8105ULL;
	}
x86_l_46a:
	/* 0x46a: jmp    366e <generic_uprobe_filter_arg+0x366e> */
	return 13934ULL;
x86_l_46f:
	/* 0x46f: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_472:
	/* 0x472: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_475:
	/* 0x475: jb     c40 <generic_uprobe_filter_arg+0xc40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3136ULL;
	}
x86_l_47b:
	/* 0x47b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_47e:
	/* 0x47e: je     738 <generic_uprobe_filter_arg+0x738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1848ULL;
	}
x86_l_484:
	/* 0x484: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_487:
	/* 0x487: je     738 <generic_uprobe_filter_arg+0x738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1848ULL;
	}
x86_l_48d:
	/* 0x48d: jmp    2cc <generic_uprobe_filter_arg+0x2cc> */
	goto x86_l_2cc;
x86_l_492:
	/* 0x492: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_495:
	/* 0x495: je     4a5 <generic_uprobe_filter_arg+0x4a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a5;
	}
x86_l_497:
	/* 0x497: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_49a:
	/* 0x49a: je     4fa <generic_uprobe_filter_arg+0x4fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fa;
	}
x86_l_49c:
	/* 0x49c: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_49f:
	/* 0x49f: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cc;
	}
x86_l_4a5:
	/* 0x4a5: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_4ae:
	/* 0x4ae: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_4b7:
	/* 0x4b7: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_4c0:
	/* 0x4c0: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4c9:
	/* 0x4c9: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_4d2:
	/* 0x4d2: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_4d5:
	/* 0x4d5: jg     777 <generic_uprobe_filter_arg+0x777> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1911ULL;
	}
x86_l_4db:
	/* 0x4db: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4de:
	/* 0x4de: je     db0 <generic_uprobe_filter_arg+0xdb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3504ULL;
	}
x86_l_4e4:
	/* 0x4e4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4e7:
	/* 0x4e7: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_4ec:
	/* 0x4ec: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_4ef:
	/* 0x4ef: je     db2 <generic_uprobe_filter_arg+0xdb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3506ULL;
	}
x86_l_4f5:
	/* 0x4f5: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	goto x86_l_2bb;
x86_l_4fa:
	/* 0x4fa: mov    ebp,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fe:
	/* 0x4fe: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_502:
	/* 0x502: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_505:
	/* 0x505: jg     7fc <generic_uprobe_filter_arg+0x7fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2044ULL;
	}
x86_l_50b:
	/* 0x50b: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_50e:
	/* 0x50e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_511:
	/* 0x511: jb     1017 <generic_uprobe_filter_arg+0x1017> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4119ULL;
	}
x86_l_517:
	/* 0x517: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_51a:
	/* 0x51a: je     f78 <generic_uprobe_filter_arg+0xf78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3960ULL;
	}
x86_l_520:
	/* 0x520: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_525:
	/* 0x525: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_528:
	/* 0x528: je     81c <generic_uprobe_filter_arg+0x81c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2076ULL;
	}
x86_l_52e:
	/* 0x52e: jmp    3746 <generic_uprobe_filter_arg+0x3746> */
	return 14150ULL;
x86_l_533:
	/* 0x533: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_536:
	/* 0x536: jle    bb0 <generic_uprobe_filter_arg+0xbb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2992ULL;
	}
x86_l_53c:
	/* 0x53c: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_53f:
	/* 0x53f: jg     f30 <generic_uprobe_filter_arg+0xf30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3888ULL;
	}
x86_l_545:
	/* 0x545: lea    edx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_548:
	/* 0x548: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_54b:
	/* 0x54b: jb     cce <generic_uprobe_filter_arg+0xcce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3278ULL;
	}
x86_l_551:
	/* 0x551: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_554:
	/* 0x554: je     c56 <generic_uprobe_filter_arg+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3158ULL;
	}
x86_l_55a:
	/* 0x55a: jmp    110 <generic_uprobe_filter_arg+0x110> */
	goto x86_l_110;
x86_l_55f:
	/* 0x55f: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_562:
	/* 0x562: je     604 <generic_uprobe_filter_arg+0x604> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_604;
	}
x86_l_568:
	/* 0x568: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_56b:
	/* 0x56b: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cc;
	}
x86_l_571:
	/* 0x571: lea    rsi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_575:
	/* 0x575: movzx  r8d,BYTE PTR [r13+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_57a:
	/* 0x57a: movzx  ebp,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_57e:
	/* 0x57e: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_581:
	/* 0x581: jg     13eb <generic_uprobe_filter_arg+0x13eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5099ULL;
	}
x86_l_587:
	/* 0x587: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_58a:
	/* 0x58a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_58d:
	/* 0x58d: jae    19ae <generic_uprobe_filter_arg+0x19ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6574ULL;
	}
x86_l_593:
	/* 0x593: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_59e:
	/* 0x59e: mov    r10d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 256ULL);
x86_l_5a4:
	/* 0x5a4: cmp    bpl,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 144ULL);
x86_l_5a8:
	/* 0x5a8: ja     1750 <generic_uprobe_filter_arg+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5968ULL;
	}
x86_l_5ae:
	/* 0x5ae: movzx  eax,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5b2:
	/* 0x5b2: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_5b8:
	/* 0x5b8: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_5bb:
	/* 0x5bb: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_5be:
	/* 0x5be: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_5c1:
	/* 0x5c1: mov    eax,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_5c4:
	/* 0x5c4: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5c6:
	/* 0x5c6: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_5c9:
	/* 0x5c9: je     5d2 <generic_uprobe_filter_arg+0x5d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d2;
	}
x86_l_5cb:
	/* 0x5cb: mov    r10d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RBP, X86_WIDTH_32);
x86_l_5ce:
	/* 0x5ce: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_5d0:
	/* 0x5d0: je     5ed <generic_uprobe_filter_arg+0x5ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ed;
	}
x86_l_5d2:
	/* 0x5d2: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5d5:
	/* 0x5d5: movzx  ecx,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5d8:
	/* 0x5d8: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5da:
	/* 0x5da: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_5dc:
	/* 0x5dc: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_5df:
	/* 0x5df: movzx  r10d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5e3:
	/* 0x5e3: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_5e7:
	/* 0x5e7: ja     1750 <generic_uprobe_filter_arg+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5968ULL;
	}
x86_l_5ed:
	/* 0x5ed: movzx  eax,r10b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R10, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5f1:
	/* 0x5f1: imul   r13d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R13, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_5f8:
	/* 0x5f8: shr    r13d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_5fc:
	/* 0x5fc: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_5ff:
	/* 0x5ff: jmp    2632 <generic_uprobe_filter_arg+0x2632> */
	return 9778ULL;
x86_l_604:
	/* 0x604: mov    ebp,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_608:
	/* 0x608: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_60a:
	/* 0x60a: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_60d:
	/* 0x60d: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_610:
	/* 0x610: je     61a <generic_uprobe_filter_arg+0x61a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61a;
	}
x86_l_612:
	/* 0x612: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_614:
	/* 0x614: je     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_110;
	}
x86_l_61a:
	/* 0x61a: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_61d:
	/* 0x61d: ja     952 <generic_uprobe_filter_arg+0x952> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2386ULL;
	}
x86_l_623:
	/* 0x623: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_625:
	/* 0x625: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_62a:
	/* 0x62a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_62e:
	/* 0x62e: jb     b07 <generic_uprobe_filter_arg+0xb07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2823ULL;
	}
x86_l_634:
	/* 0x634: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_639:
	/* 0x639: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_63d:
	/* 0x63d: jb     9cd <generic_uprobe_filter_arg+0x9cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2509ULL;
	}
x86_l_643:
	/* 0x643: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_64d:
	/* 0x64d: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_651:
	/* 0x651: jae    952 <generic_uprobe_filter_arg+0x952> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2386ULL;
	}
x86_l_657:
	/* 0x657: mov    WORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_65e:
	/* 0x65e: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_664:
	/* 0x664: ja     971 <generic_uprobe_filter_arg+0x971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2417ULL;
	}
x86_l_66a:
	/* 0x66a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_66d:
	/* 0x66d: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_670:
	/* 0x670: lea    rcx,[rsi+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_674:
	/* 0x674: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_678:
	/* 0x678: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_67d:
	/* 0x67d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_682:
	/* 0x682: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_687:
	/* 0x687: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_689:
	/* 0x689: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_68d:
	/* 0x68d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_691:
	/* 0x691: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_696:
	/* 0x696: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_698:
	/* 0x698: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_69d:
	/* 0x69d: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_69f:
	/* 0x69f: je     1cfc <generic_uprobe_filter_arg+0x1cfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7420ULL;
	}
x86_l_6a5:
	/* 0x6a5: movzx  eax,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_6aa:
	/* 0x6aa: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_6af:
	/* 0x6af: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_6b4:
	/* 0x6b4: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6b6:
	/* 0x6b6: je     1cfe <generic_uprobe_filter_arg+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7422ULL;
	}
x86_l_6bc:
	/* 0x6bc: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 1729ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1729ULL: goto x86_l_6c1;
	case 1732ULL: goto x86_l_6c4;
	case 1737ULL: goto x86_l_6c9;
	case 1742ULL: goto x86_l_6ce;
	case 1745ULL: goto x86_l_6d1;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1758ULL: goto x86_l_6de;
	case 1764ULL: goto x86_l_6e4;
	case 1766ULL: goto x86_l_6e6;
	case 1772ULL: goto x86_l_6ec;
	case 1775ULL: goto x86_l_6ef;
	case 1781ULL: goto x86_l_6f5;
	case 1786ULL: goto x86_l_6fa;
	case 1788ULL: goto x86_l_6fc;
	case 1794ULL: goto x86_l_702;
	case 1796ULL: goto x86_l_704;
	case 1802ULL: goto x86_l_70a;
	case 1805ULL: goto x86_l_70d;
	case 1811ULL: goto x86_l_713;
	case 1816ULL: goto x86_l_718;
	case 1818ULL: goto x86_l_71a;
	case 1824ULL: goto x86_l_720;
	case 1826ULL: goto x86_l_722;
	case 1828ULL: goto x86_l_724;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1839ULL: goto x86_l_72f;
	case 1842ULL: goto x86_l_732;
	case 1848ULL: goto x86_l_738;
	case 1851ULL: goto x86_l_73b;
	case 1857ULL: goto x86_l_741;
	case 1859ULL: goto x86_l_743;
	case 1864ULL: goto x86_l_748;
	case 1868ULL: goto x86_l_74c;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1878ULL: goto x86_l_756;
	case 1884ULL: goto x86_l_75c;
	case 1887ULL: goto x86_l_75f;
	case 1890ULL: goto x86_l_762;
	case 1896ULL: goto x86_l_768;
	case 1900ULL: goto x86_l_76c;
	case 1906ULL: goto x86_l_772;
	case 1911ULL: goto x86_l_777;
	case 1914ULL: goto x86_l_77a;
	case 1920ULL: goto x86_l_780;
	case 1923ULL: goto x86_l_783;
	case 1928ULL: goto x86_l_788;
	case 1931ULL: goto x86_l_78b;
	case 1937ULL: goto x86_l_791;
	case 1942ULL: goto x86_l_796;
	case 1947ULL: goto x86_l_79b;
	case 1951ULL: goto x86_l_79f;
	case 1957ULL: goto x86_l_7a5;
	case 1967ULL: goto x86_l_7af;
	case 1971ULL: goto x86_l_7b3;
	case 1977ULL: goto x86_l_7b9;
	case 1980ULL: goto x86_l_7bc;
	case 1986ULL: goto x86_l_7c2;
	case 1991ULL: goto x86_l_7c7;
	case 1996ULL: goto x86_l_7cc;
	case 1999ULL: goto x86_l_7cf;
	case 2005ULL: goto x86_l_7d5;
	case 2010ULL: goto x86_l_7da;
	case 2013ULL: goto x86_l_7dd;
	case 2019ULL: goto x86_l_7e3;
	case 2023ULL: goto x86_l_7e7;
	case 2025ULL: goto x86_l_7e9;
	case 2031ULL: goto x86_l_7ef;
	case 2033ULL: goto x86_l_7f1;
	case 2039ULL: goto x86_l_7f7;
	case 2044ULL: goto x86_l_7fc;
	case 2047ULL: goto x86_l_7ff;
	case 2053ULL: goto x86_l_805;
	case 2056ULL: goto x86_l_808;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2070ULL: goto x86_l_816;
	case 2076ULL: goto x86_l_81c;
	case 2081ULL: goto x86_l_821;
	case 2086ULL: goto x86_l_826;
	case 2090ULL: goto x86_l_82a;
	case 2101ULL: goto x86_l_835;
	case 2106ULL: goto x86_l_83a;
	case 2111ULL: goto x86_l_83f;
	case 2118ULL: goto x86_l_846;
	case 2120ULL: goto x86_l_848;
	case 2122ULL: goto x86_l_84a;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2136ULL: goto x86_l_858;
	case 2142ULL: goto x86_l_85e;
	case 2147ULL: goto x86_l_863;
	case 2152ULL: goto x86_l_868;
	case 2157ULL: goto x86_l_86d;
	case 2164ULL: goto x86_l_874;
	case 2166ULL: goto x86_l_876;
	case 2169ULL: goto x86_l_879;
	case 2175ULL: goto x86_l_87f;
	case 2178ULL: goto x86_l_882;
	case 2181ULL: goto x86_l_885;
	case 2186ULL: goto x86_l_88a;
	case 2189ULL: goto x86_l_88d;
	case 2192ULL: goto x86_l_890;
	case 2194ULL: goto x86_l_892;
	case 2197ULL: goto x86_l_895;
	case 2200ULL: goto x86_l_898;
	case 2205ULL: goto x86_l_89d;
	case 2208ULL: goto x86_l_8a0;
	case 2211ULL: goto x86_l_8a3;
	case 2216ULL: goto x86_l_8a8;
	case 2220ULL: goto x86_l_8ac;
	case 2226ULL: goto x86_l_8b2;
	case 2229ULL: goto x86_l_8b5;
	case 2233ULL: goto x86_l_8b9;
	case 2239ULL: goto x86_l_8bf;
	case 2242ULL: goto x86_l_8c2;
	case 2246ULL: goto x86_l_8c6;
	case 2248ULL: goto x86_l_8c8;
	case 2250ULL: goto x86_l_8ca;
	case 2253ULL: goto x86_l_8cd;
	case 2257ULL: goto x86_l_8d1;
	case 2264ULL: goto x86_l_8d8;
	case 2269ULL: goto x86_l_8dd;
	case 2273ULL: goto x86_l_8e1;
	case 2276ULL: goto x86_l_8e4;
	case 2278ULL: goto x86_l_8e6;
	case 2282ULL: goto x86_l_8ea;
	case 2289ULL: goto x86_l_8f1;
	case 2294ULL: goto x86_l_8f6;
	case 2298ULL: goto x86_l_8fa;
	case 2301ULL: goto x86_l_8fd;
	case 2303ULL: goto x86_l_8ff;
	case 2307ULL: goto x86_l_903;
	case 2314ULL: goto x86_l_90a;
	case 2319ULL: goto x86_l_90f;
	case 2323ULL: goto x86_l_913;
	case 2326ULL: goto x86_l_916;
	case 2328ULL: goto x86_l_918;
	case 2332ULL: goto x86_l_91c;
	case 2334ULL: goto x86_l_91e;
	case 2338ULL: goto x86_l_922;
	case 2345ULL: goto x86_l_929;
	case 2350ULL: goto x86_l_92e;
	case 2353ULL: goto x86_l_931;
	case 2357ULL: goto x86_l_935;
	case 2361ULL: goto x86_l_939;
	case 2364ULL: goto x86_l_93c;
	case 2366ULL: goto x86_l_93e;
	case 2371ULL: goto x86_l_943;
	case 2376ULL: goto x86_l_948;
	case 2381ULL: goto x86_l_94d;
	case 2386ULL: goto x86_l_952;
	case 2389ULL: goto x86_l_955;
	case 2392ULL: goto x86_l_958;
	case 2394ULL: goto x86_l_95a;
	case 2405ULL: goto x86_l_965;
	case 2411ULL: goto x86_l_96b;
	case 2417ULL: goto x86_l_971;
	case 2419ULL: goto x86_l_973;
	case 2424ULL: goto x86_l_978;
	case 2428ULL: goto x86_l_97c;
	case 2434ULL: goto x86_l_982;
	case 2439ULL: goto x86_l_987;
	case 2442ULL: goto x86_l_98a;
	case 2448ULL: goto x86_l_990;
	case 2450ULL: goto x86_l_992;
	case 2455ULL: goto x86_l_997;
	case 2459ULL: goto x86_l_99b;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2473ULL: goto x86_l_9a9;
	case 2479ULL: goto x86_l_9af;
	case 2482ULL: goto x86_l_9b2;
	case 2485ULL: goto x86_l_9b5;
	case 2491ULL: goto x86_l_9bb;
	case 2496ULL: goto x86_l_9c0;
	case 2498ULL: goto x86_l_9c2;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2519ULL: goto x86_l_9d7;
	case 2523ULL: goto x86_l_9db;
	case 2534ULL: goto x86_l_9e6;
	case 2539ULL: goto x86_l_9eb;
	case 2544ULL: goto x86_l_9f0;
	case 2551ULL: goto x86_l_9f7;
	case 2553ULL: goto x86_l_9f9;
	case 2555ULL: goto x86_l_9fb;
	case 2561ULL: goto x86_l_a01;
	case 2566ULL: goto x86_l_a06;
	case 2569ULL: goto x86_l_a09;
	case 2575ULL: goto x86_l_a0f;
	case 2580ULL: goto x86_l_a14;
	case 2585ULL: goto x86_l_a19;
	case 2590ULL: goto x86_l_a1e;
	case 2597ULL: goto x86_l_a25;
	case 2599ULL: goto x86_l_a27;
	case 2602ULL: goto x86_l_a2a;
	case 2608ULL: goto x86_l_a30;
	case 2611ULL: goto x86_l_a33;
	case 2614ULL: goto x86_l_a36;
	case 2619ULL: goto x86_l_a3b;
	case 2622ULL: goto x86_l_a3e;
	case 2625ULL: goto x86_l_a41;
	case 2627ULL: goto x86_l_a43;
	case 2630ULL: goto x86_l_a46;
	case 2633ULL: goto x86_l_a49;
	case 2638ULL: goto x86_l_a4e;
	case 2641ULL: goto x86_l_a51;
	case 2644ULL: goto x86_l_a54;
	case 2649ULL: goto x86_l_a59;
	case 2653ULL: goto x86_l_a5d;
	case 2659ULL: goto x86_l_a63;
	case 2662ULL: goto x86_l_a66;
	case 2666ULL: goto x86_l_a6a;
	case 2672ULL: goto x86_l_a70;
	case 2675ULL: goto x86_l_a73;
	case 2679ULL: goto x86_l_a77;
	case 2681ULL: goto x86_l_a79;
	case 2683ULL: goto x86_l_a7b;
	case 2686ULL: goto x86_l_a7e;
	case 2690ULL: goto x86_l_a82;
	case 2697ULL: goto x86_l_a89;
	case 2703ULL: goto x86_l_a8f;
	case 2707ULL: goto x86_l_a93;
	case 2710ULL: goto x86_l_a96;
	case 2712ULL: goto x86_l_a98;
	case 2716ULL: goto x86_l_a9c;
	case 2723ULL: goto x86_l_aa3;
	case 2729ULL: goto x86_l_aa9;
	case 2733ULL: goto x86_l_aad;
	case 2736ULL: goto x86_l_ab0;
	case 2738ULL: goto x86_l_ab2;
	case 2742ULL: goto x86_l_ab6;
	case 2749ULL: goto x86_l_abd;
	case 2755ULL: goto x86_l_ac3;
	case 2759ULL: goto x86_l_ac7;
	case 2762ULL: goto x86_l_aca;
	case 2764ULL: goto x86_l_acc;
	case 2768ULL: goto x86_l_ad0;
	case 2770ULL: goto x86_l_ad2;
	case 2774ULL: goto x86_l_ad6;
	case 2781ULL: goto x86_l_add;
	case 2787ULL: goto x86_l_ae3;
	case 2790ULL: goto x86_l_ae6;
	case 2794ULL: goto x86_l_aea;
	case 2798ULL: goto x86_l_aee;
	case 2801ULL: goto x86_l_af1;
	case 2803ULL: goto x86_l_af3;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2823ULL: goto x86_l_b07;
	case 2828ULL: goto x86_l_b0c;
	case 2833ULL: goto x86_l_b11;
	case 2838ULL: goto x86_l_b16;
	case 2842ULL: goto x86_l_b1a;
	case 2853ULL: goto x86_l_b25;
	case 2858ULL: goto x86_l_b2a;
	case 2863ULL: goto x86_l_b2f;
	case 2870ULL: goto x86_l_b36;
	case 2872ULL: goto x86_l_b38;
	case 2874ULL: goto x86_l_b3a;
	case 2880ULL: goto x86_l_b40;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2891ULL: goto x86_l_b4b;
	case 2897ULL: goto x86_l_b51;
	case 2902ULL: goto x86_l_b56;
	case 2907ULL: goto x86_l_b5b;
	case 2914ULL: goto x86_l_b62;
	case 2916ULL: goto x86_l_b64;
	case 2919ULL: goto x86_l_b67;
	case 2925ULL: goto x86_l_b6d;
	case 2928ULL: goto x86_l_b70;
	case 2933ULL: goto x86_l_b75;
	case 2937ULL: goto x86_l_b79;
	case 2943ULL: goto x86_l_b7f;
	case 2948ULL: goto x86_l_b84;
	case 2951ULL: goto x86_l_b87;
	case 2958ULL: goto x86_l_b8e;
	case 2960ULL: goto x86_l_b90;
	case 2963ULL: goto x86_l_b93;
	case 2967ULL: goto x86_l_b97;
	case 2972ULL: goto x86_l_b9c;
	case 2974ULL: goto x86_l_b9e;
	case 2976ULL: goto x86_l_ba0;
	case 2981ULL: goto x86_l_ba5;
	case 2984ULL: goto x86_l_ba8;
	case 2987ULL: goto x86_l_bab;
	case 2992ULL: goto x86_l_bb0;
	case 2995ULL: goto x86_l_bb3;
	case 2998ULL: goto x86_l_bb6;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3013ULL: goto x86_l_bc5;
	case 3017ULL: goto x86_l_bc9;
	case 3020ULL: goto x86_l_bcc;
	case 3026ULL: goto x86_l_bd2;
	case 3029ULL: goto x86_l_bd5;
	case 3032ULL: goto x86_l_bd8;
	case 3038ULL: goto x86_l_bde;
	case 3043ULL: goto x86_l_be3;
	case 3046ULL: goto x86_l_be6;
	case 3052ULL: goto x86_l_bec;
	case 3057ULL: goto x86_l_bf1;
	case 3060ULL: goto x86_l_bf4;
	case 3066ULL: goto x86_l_bfa;
	case 3071ULL: goto x86_l_bff;
	case 3074ULL: goto x86_l_c02;
	case 3080ULL: goto x86_l_c08;
	case 3083ULL: goto x86_l_c0b;
	case 3089ULL: goto x86_l_c11;
	case 3092ULL: goto x86_l_c14;
	case 3098ULL: goto x86_l_c1a;
	case 3103ULL: goto x86_l_c1f;
	case 3106ULL: goto x86_l_c22;
	case 3112ULL: goto x86_l_c28;
	case 3116ULL: goto x86_l_c2c;
	case 3122ULL: goto x86_l_c32;
	case 3127ULL: goto x86_l_c37;
	case 3130ULL: goto x86_l_c3a;
	case 3136ULL: goto x86_l_c40;
	case 3139ULL: goto x86_l_c43;
	case 3145ULL: goto x86_l_c49;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3156ULL: goto x86_l_c54;
	case 3158ULL: goto x86_l_c56;
	case 3163ULL: goto x86_l_c5b;
	case 3166ULL: goto x86_l_c5e;
	case 3168ULL: goto x86_l_c60;
	case 3171ULL: goto x86_l_c63;
	case 3174ULL: goto x86_l_c66;
	case 3180ULL: goto x86_l_c6c;
	case 3184ULL: goto x86_l_c70;
	case 3190ULL: goto x86_l_c76;
	case 3195ULL: goto x86_l_c7b;
	case 3200ULL: goto x86_l_c80;
	case 3204ULL: goto x86_l_c84;
	case 3206ULL: goto x86_l_c86;
	case 3216ULL: goto x86_l_c90;
	case 3220ULL: goto x86_l_c94;
	case 3226ULL: goto x86_l_c9a;
	case 3231ULL: goto x86_l_c9f;
	case 3234ULL: goto x86_l_ca2;
	case 3240ULL: goto x86_l_ca8;
	case 3243ULL: goto x86_l_cab;
	case 3249ULL: goto x86_l_cb1;
	case 3252ULL: goto x86_l_cb4;
	case 3254ULL: goto x86_l_cb6;
	case 3257ULL: goto x86_l_cb9;
	case 3263ULL: goto x86_l_cbf;
	case 3267ULL: goto x86_l_cc3;
	case 3273ULL: goto x86_l_cc9;
	case 3278ULL: goto x86_l_cce;
	case 3281ULL: goto x86_l_cd1;
	case 3284ULL: goto x86_l_cd4;
	case 3290ULL: goto x86_l_cda;
	case 3297ULL: goto x86_l_ce1;
	case 3302ULL: goto x86_l_ce6;
	case 3307ULL: goto x86_l_ceb;
	case 3314ULL: goto x86_l_cf2;
	case 3316ULL: goto x86_l_cf4;
	case 3319ULL: goto x86_l_cf7;
	case 3325ULL: goto x86_l_cfd;
	case 3328ULL: goto x86_l_d00;
	case 3331ULL: goto x86_l_d03;
	case 3336ULL: goto x86_l_d08;
	case 3341ULL: goto x86_l_d0d;
	case 3346ULL: goto x86_l_d12;
	case 3348ULL: goto x86_l_d14;
	case 3353ULL: goto x86_l_d19;
	case 3356ULL: goto x86_l_d1c;
	case 3362ULL: goto x86_l_d22;
	case 3365ULL: goto x86_l_d25;
	case 3370ULL: goto x86_l_d2a;
	case 3375ULL: goto x86_l_d2f;
	case 3378ULL: goto x86_l_d32;
	case 3384ULL: goto x86_l_d38;
	case 3389ULL: goto x86_l_d3d;
	case 3392ULL: goto x86_l_d40;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6c1:
	/* 0x6c1: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_6c4:
	/* 0x6c4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c9:
	/* 0x6c9: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ce:
	/* 0x6ce: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_6d1:
	/* 0x6d1: jb     971 <generic_uprobe_filter_arg+0x971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_971;
	}
x86_l_6d7:
	/* 0x6d7: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6dc:
	/* 0x6dc: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_6de:
	/* 0x6de: je     971 <generic_uprobe_filter_arg+0x971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_971;
	}
x86_l_6e4:
	/* 0x6e4: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_6e6:
	/* 0x6e6: je     33a1 <generic_uprobe_filter_arg+0x33a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13217ULL;
	}
x86_l_6ec:
	/* 0x6ec: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6ef:
	/* 0x6ef: jb     971 <generic_uprobe_filter_arg+0x971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_971;
	}
x86_l_6f5:
	/* 0x6f5: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6fa:
	/* 0x6fa: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_6fc:
	/* 0x6fc: je     971 <generic_uprobe_filter_arg+0x971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_971;
	}
x86_l_702:
	/* 0x702: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_704:
	/* 0x704: je     33a1 <generic_uprobe_filter_arg+0x33a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13217ULL;
	}
x86_l_70a:
	/* 0x70a: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_70d:
	/* 0x70d: jb     3779 <generic_uprobe_filter_arg+0x3779> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14201ULL;
	}
x86_l_713:
	/* 0x713: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_718:
	/* 0x718: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_71a:
	/* 0x71a: je     3779 <generic_uprobe_filter_arg+0x3779> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14201ULL;
	}
x86_l_720:
	/* 0x720: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_722:
	/* 0x722: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_724:
	/* 0x724: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_727:
	/* 0x727: jmp    377b <generic_uprobe_filter_arg+0x377b> */
	return 14203ULL;
x86_l_72c:
	/* 0x72c: lea    edx,[rcx-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_72f:
	/* 0x72f: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_732:
	/* 0x732: jae    c37 <generic_uprobe_filter_arg+0xc37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_c37;
	}
x86_l_738:
	/* 0x738: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_73b:
	/* 0x73b: ja     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 272ULL;
	}
x86_l_741:
	/* 0x741: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_743:
	/* 0x743: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_748:
	/* 0x748: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_74c:
	/* 0x74c: jae    796 <generic_uprobe_filter_arg+0x796> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_796;
	}
x86_l_74e:
	/* 0x74e: mov    edx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_753:
	/* 0x753: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_756:
	/* 0x756: jle    bff <generic_uprobe_filter_arg+0xbff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_bff;
	}
x86_l_75c:
	/* 0x75c: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_75f:
	/* 0x75f: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_762:
	/* 0x762: jae    10e4 <generic_uprobe_filter_arg+0x10e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4324ULL;
	}
x86_l_768:
	/* 0x768: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76c:
	/* 0x76c: jne    22ec <generic_uprobe_filter_arg+0x22ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8940ULL;
	}
x86_l_772:
	/* 0x772: jmp    366e <generic_uprobe_filter_arg+0x366e> */
	return 13934ULL;
x86_l_777:
	/* 0x777: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_77a:
	/* 0x77a: je     d85 <generic_uprobe_filter_arg+0xd85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3461ULL;
	}
x86_l_780:
	/* 0x780: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_783:
	/* 0x783: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_788:
	/* 0x788: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_78b:
	/* 0x78b: je     db2 <generic_uprobe_filter_arg+0xdb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3506ULL;
	}
x86_l_791:
	/* 0x791: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_796:
	/* 0x796: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_79b:
	/* 0x79b: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_79f:
	/* 0x79f: jb     d3d <generic_uprobe_filter_arg+0xd3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d3d;
	}
x86_l_7a5:
	/* 0x7a5: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_7af:
	/* 0x7af: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_7b3:
	/* 0x7b3: jae    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 272ULL;
	}
x86_l_7b9:
	/* 0x7b9: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_7bc:
	/* 0x7bc: jne    13b6 <generic_uprobe_filter_arg+0x13b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5046ULL;
	}
x86_l_7c2:
	/* 0x7c2: mov    esi,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c7:
	/* 0x7c7: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7cc:
	/* 0x7cc: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_7cf:
	/* 0x7cf: ja     202a <generic_uprobe_filter_arg+0x202a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8234ULL;
	}
x86_l_7d5:
	/* 0x7d5: mov    eax,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5122ULL);
x86_l_7da:
	/* 0x7da: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_7dd:
	/* 0x7dd: jae    202a <generic_uprobe_filter_arg+0x202a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8234ULL;
	}
x86_l_7e3:
	/* 0x7e3: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e7:
	/* 0x7e7: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_7e9:
	/* 0x7e9: jg     203a <generic_uprobe_filter_arg+0x203a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8250ULL;
	}
x86_l_7ef:
	/* 0x7ef: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_7f1:
	/* 0x7f1: jle    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_7f7:
	/* 0x7f7: jmp    203a <generic_uprobe_filter_arg+0x203a> */
	return 8250ULL;
x86_l_7fc:
	/* 0x7fc: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_7ff:
	/* 0x7ff: jg     e36 <generic_uprobe_filter_arg+0xe36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3638ULL;
	}
x86_l_805:
	/* 0x805: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_808:
	/* 0x808: je     f78 <generic_uprobe_filter_arg+0xf78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3960ULL;
	}
x86_l_80e:
	/* 0x80e: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_813:
	/* 0x813: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_816:
	/* 0x816: jne    3746 <generic_uprobe_filter_arg+0x3746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14150ULL;
	}
x86_l_81c:
	/* 0x81c: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_821:
	/* 0x821: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_826:
	/* 0x826: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_82a:
	/* 0x82a: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_835:
	/* 0x835: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_83a:
	/* 0x83a: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_83f:
	/* 0x83f: mov    rdi,QWORD PTR [rip+0x1eea1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_846:
	/* 0x846: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_848:
	/* 0x848: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_84a:
	/* 0x84a: je     3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14133ULL;
	}
x86_l_850:
	/* 0x850: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_855:
	/* 0x855: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_858:
	/* 0x858: je     3737 <generic_uprobe_filter_arg+0x3737> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14135ULL;
	}
x86_l_85e:
	/* 0x85e: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_863:
	/* 0x863: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_868:
	/* 0x868: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_86d:
	/* 0x86d: mov    rdi,QWORD PTR [rip+0x1eea1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_874:
	/* 0x874: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_876:
	/* 0x876: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_879:
	/* 0x879: je     3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14133ULL;
	}
x86_l_87f:
	/* 0x87f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_882:
	/* 0x882: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_885:
	/* 0x885: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_88a:
	/* 0x88a: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_88d:
	/* 0x88d: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_890:
	/* 0x890: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_892:
	/* 0x892: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_895:
	/* 0x895: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_898:
	/* 0x898: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_89d:
	/* 0x89d: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8a0:
	/* 0x8a0: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_8a3:
	/* 0x8a3: mov    QWORD PTR [rsp+0x70],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8a8:
	/* 0x8a8: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_8ac:
	/* 0x8ac: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_8b2:
	/* 0x8b2: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8b5:
	/* 0x8b5: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_8b9:
	/* 0x8b9: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_8bf:
	/* 0x8bf: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8c2:
	/* 0x8c2: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_8c6:
	/* 0x8c6: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_8c8:
	/* 0x8c8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ca:
	/* 0x8ca: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_8cd:
	/* 0x8cd: lea    r13d,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_8d1:
	/* 0x8d1: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8d8:
	/* 0x8d8: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_8dd:
	/* 0x8dd: mov    BYTE PTR [rdi-0x3],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_8e1:
	/* 0x8e1: cmp    r10,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RBX, X86_WIDTH_64);
x86_l_8e4:
	/* 0x8e4: je     93e <generic_uprobe_filter_arg+0x93e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_93e;
	}
x86_l_8e6:
	/* 0x8e6: lea    r13d,[r11+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_8ea:
	/* 0x8ea: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8f1:
	/* 0x8f1: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_8f6:
	/* 0x8f6: mov    BYTE PTR [rdi-0x2],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_8fa:
	/* 0x8fa: cmp    r8,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RBX, X86_WIDTH_64);
x86_l_8fd:
	/* 0x8fd: je     93e <generic_uprobe_filter_arg+0x93e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_93e;
	}
x86_l_8ff:
	/* 0x8ff: lea    r13d,[r9+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_903:
	/* 0x903: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_90a:
	/* 0x90a: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_90f:
	/* 0x90f: mov    BYTE PTR [rdi-0x1],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_913:
	/* 0x913: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_916:
	/* 0x916: je     93e <generic_uprobe_filter_arg+0x93e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_93e;
	}
x86_l_918:
	/* 0x918: cmp    rbx,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_91c:
	/* 0x91c: je     93e <generic_uprobe_filter_arg+0x93e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_93e;
	}
x86_l_91e:
	/* 0x91e: lea    r13d,[rdx+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_922:
	/* 0x922: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_929:
	/* 0x929: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_92e:
	/* 0x92e: mov    BYTE PTR [rdi],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_931:
	/* 0x931: add    rbx,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_935:
	/* 0x935: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_939:
	/* 0x939: cmp    rax,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_93c:
	/* 0x93c: jne    8cd <generic_uprobe_filter_arg+0x8cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8cd;
	}
x86_l_93e:
	/* 0x93e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_943:
	/* 0x943: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_948:
	/* 0x948: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_94d:
	/* 0x94d: jmp    1b3e <generic_uprobe_filter_arg+0x1b3e> */
	return 6974ULL;
x86_l_952:
	/* 0x952: add    eax,0xfffffffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967293ULL);
x86_l_955:
	/* 0x955: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_958:
	/* 0x958: jae    971 <generic_uprobe_filter_arg+0x971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_971;
	}
x86_l_95a:
	/* 0x95a: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_965:
	/* 0x965: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_96b:
	/* 0x96b: jbe    11ee <generic_uprobe_filter_arg+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4590ULL;
	}
x86_l_971:
	/* 0x971: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_973:
	/* 0x973: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_978:
	/* 0x978: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_97c:
	/* 0x97c: jbe    33b0 <generic_uprobe_filter_arg+0x33b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13232ULL;
	}
x86_l_982:
	/* 0x982: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_987:
	/* 0x987: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_98a:
	/* 0x98a: ja     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 272ULL;
	}
x86_l_990:
	/* 0x990: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_992:
	/* 0x992: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_997:
	/* 0x997: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_99b:
	/* 0x99b: jae    112f <generic_uprobe_filter_arg+0x112f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4399ULL;
	}
x86_l_9a1:
	/* 0x9a1: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9a6:
	/* 0x9a6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9a9:
	/* 0x9a9: jle    169a <generic_uprobe_filter_arg+0x169a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5786ULL;
	}
x86_l_9af:
	/* 0x9af: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_9b2:
	/* 0x9b2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_9b5:
	/* 0x9b5: jae    1e80 <generic_uprobe_filter_arg+0x1e80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7808ULL;
	}
x86_l_9bb:
	/* 0x9bb: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_9c0:
	/* 0x9c0: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_9c2:
	/* 0x9c2: jne    1ff0 <generic_uprobe_filter_arg+0x1ff0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8176ULL;
	}
x86_l_9c8:
	/* 0x9c8: jmp    366e <generic_uprobe_filter_arg+0x366e> */
	return 13934ULL;
x86_l_9cd:
	/* 0x9cd: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9d2:
	/* 0x9d2: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9d7:
	/* 0x9d7: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9db:
	/* 0x9db: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_9e6:
	/* 0x9e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9eb:
	/* 0x9eb: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9f0:
	/* 0x9f0: mov    rdi,QWORD PTR [rip+0x1eea1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_9f7:
	/* 0x9f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f9:
	/* 0x9f9: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_9fb:
	/* 0x9fb: je     3390 <generic_uprobe_filter_arg+0x3390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13200ULL;
	}
x86_l_a01:
	/* 0xa01: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_a06:
	/* 0xa06: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a09:
	/* 0xa09: je     3392 <generic_uprobe_filter_arg+0x3392> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13202ULL;
	}
x86_l_a0f:
	/* 0xa0f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a14:
	/* 0xa14: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a19:
	/* 0xa19: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a1e:
	/* 0xa1e: mov    rdi,QWORD PTR [rip+0x1eea1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_a25:
	/* 0xa25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a27:
	/* 0xa27: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a2a:
	/* 0xa2a: je     3390 <generic_uprobe_filter_arg+0x3390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13200ULL;
	}
x86_l_a30:
	/* 0xa30: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_a33:
	/* 0xa33: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_a36:
	/* 0xa36: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_a3b:
	/* 0xa3b: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_a3e:
	/* 0xa3e: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_a41:
	/* 0xa41: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a43:
	/* 0xa43: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_a46:
	/* 0xa46: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_a49:
	/* 0xa49: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a4e:
	/* 0xa4e: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a51:
	/* 0xa51: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_a54:
	/* 0xa54: mov    QWORD PTR [rsp+0x70],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a59:
	/* 0xa59: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_a5d:
	/* 0xa5d: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_a63:
	/* 0xa63: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a66:
	/* 0xa66: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_a6a:
	/* 0xa6a: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_a70:
	/* 0xa70: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a73:
	/* 0xa73: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_a77:
	/* 0xa77: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_a79:
	/* 0xa79: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a7b:
	/* 0xa7b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_a7e:
	/* 0xa7e: lea    r13d,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_a82:
	/* 0xa82: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a89:
	/* 0xa89: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_a8f:
	/* 0xa8f: mov    BYTE PTR [rdi-0x3],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_a93:
	/* 0xa93: cmp    r10,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RBX, X86_WIDTH_64);
x86_l_a96:
	/* 0xa96: je     af3 <generic_uprobe_filter_arg+0xaf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_af3;
	}
x86_l_a98:
	/* 0xa98: lea    r13d,[r11+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_a9c:
	/* 0xa9c: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_aa3:
	/* 0xaa3: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_aa9:
	/* 0xaa9: mov    BYTE PTR [rdi-0x2],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_aad:
	/* 0xaad: cmp    r8,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RBX, X86_WIDTH_64);
x86_l_ab0:
	/* 0xab0: je     af3 <generic_uprobe_filter_arg+0xaf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_af3;
	}
x86_l_ab2:
	/* 0xab2: lea    r13d,[r9+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_ab6:
	/* 0xab6: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_abd:
	/* 0xabd: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_ac3:
	/* 0xac3: mov    BYTE PTR [rdi-0x1],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_ac7:
	/* 0xac7: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_aca:
	/* 0xaca: je     af3 <generic_uprobe_filter_arg+0xaf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_af3;
	}
x86_l_acc:
	/* 0xacc: cmp    rbx,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_ad0:
	/* 0xad0: je     af3 <generic_uprobe_filter_arg+0xaf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_af3;
	}
x86_l_ad2:
	/* 0xad2: lea    r13d,[rdx+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_ad6:
	/* 0xad6: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_add:
	/* 0xadd: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_ae3:
	/* 0xae3: mov    BYTE PTR [rdi],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae6:
	/* 0xae6: add    rbx,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_aea:
	/* 0xaea: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_aee:
	/* 0xaee: cmp    rax,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_af1:
	/* 0xaf1: jne    a7e <generic_uprobe_filter_arg+0xa7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a7e;
	}
x86_l_af3:
	/* 0xaf3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_af8:
	/* 0xaf8: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_afd:
	/* 0xafd: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b02:
	/* 0xb02: jmp    3384 <generic_uprobe_filter_arg+0x3384> */
	return 13188ULL;
x86_l_b07:
	/* 0xb07: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b0c:
	/* 0xb0c: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b11:
	/* 0xb11: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b16:
	/* 0xb16: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b1a:
	/* 0xb1a: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_b25:
	/* 0xb25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b2a:
	/* 0xb2a: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b2f:
	/* 0xb2f: mov    rdi,QWORD PTR [rip+0x1eea1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_b36:
	/* 0xb36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b38:
	/* 0xb38: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_b3a:
	/* 0xb3a: je     3390 <generic_uprobe_filter_arg+0x3390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13200ULL;
	}
x86_l_b40:
	/* 0xb40: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_b43:
	/* 0xb43: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_b48:
	/* 0xb48: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b4b:
	/* 0xb4b: je     3392 <generic_uprobe_filter_arg+0x3392> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13202ULL;
	}
x86_l_b51:
	/* 0xb51: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b56:
	/* 0xb56: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b5b:
	/* 0xb5b: mov    rdi,QWORD PTR [rip+0x1eea1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_b62:
	/* 0xb62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b64:
	/* 0xb64: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b67:
	/* 0xb67: je     3390 <generic_uprobe_filter_arg+0x3390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13200ULL;
	}
x86_l_b6d:
	/* 0xb6d: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_b70:
	/* 0xb70: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b75:
	/* 0xb75: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_b79:
	/* 0xb79: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_b7f:
	/* 0xb7f: mov    eax,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_b84:
	/* 0xb84: cmovae ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_b87:
	/* 0xb87: lea    eax,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_b8e:
	/* 0xb8e: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b90:
	/* 0xb90: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b93:
	/* 0xb93: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_b97:
	/* 0xb97: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b9c:
	/* 0xb9c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_b9e:
	/* 0xb9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba0:
	/* 0xba0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ba5:
	/* 0xba5: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_ba8:
	/* 0xba8: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_bab:
	/* 0xbab: jmp    3384 <generic_uprobe_filter_arg+0x3384> */
	return 13188ULL;
x86_l_bb0:
	/* 0xbb0: lea    edx,[rax-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_bb3:
	/* 0xbb3: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_bb6:
	/* 0xbb6: jb     c56 <generic_uprobe_filter_arg+0xc56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c56;
	}
x86_l_bbc:
	/* 0xbbc: jmp    110 <generic_uprobe_filter_arg+0x110> */
	return 272ULL;
x86_l_bc1:
	/* 0xbc1: mov    ebp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bc5:
	/* 0xbc5: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_bc9:
	/* 0xbc9: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_bcc:
	/* 0xbcc: jg     1256 <generic_uprobe_filter_arg+0x1256> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4694ULL;
	}
x86_l_bd2:
	/* 0xbd2: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_bd5:
	/* 0xbd5: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bd8:
	/* 0xbd8: jb     1b4d <generic_uprobe_filter_arg+0x1b4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6989ULL;
	}
x86_l_bde:
	/* 0xbde: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_be3:
	/* 0xbe3: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_be6:
	/* 0xbe6: je     1aa3 <generic_uprobe_filter_arg+0x1aa3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6819ULL;
	}
x86_l_bec:
	/* 0xbec: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_bf1:
	/* 0xbf1: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_bf4:
	/* 0xbf4: je     127b <generic_uprobe_filter_arg+0x127b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4731ULL;
	}
x86_l_bfa:
	/* 0xbfa: jmp    3746 <generic_uprobe_filter_arg+0x3746> */
	return 14150ULL;
x86_l_bff:
	/* 0xbff: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c02:
	/* 0xc02: je     1551 <generic_uprobe_filter_arg+0x1551> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5457ULL;
	}
x86_l_c08:
	/* 0xc08: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c0b:
	/* 0xc0b: jne    22ec <generic_uprobe_filter_arg+0x22ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8940ULL;
	}
x86_l_c11:
	/* 0xc11: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_c14:
	/* 0xc14: ja     22e2 <generic_uprobe_filter_arg+0x22e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8930ULL;
	}
x86_l_c1a:
	/* 0xc1a: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_c1f:
	/* 0xc1f: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_c22:
	/* 0xc22: jae    22e2 <generic_uprobe_filter_arg+0x22e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8930ULL;
	}
x86_l_c28:
	/* 0xc28: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c2c:
	/* 0xc2c: jl     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_c32:
	/* 0xc32: jmp    22ec <generic_uprobe_filter_arg+0x22ec> */
	return 8940ULL;
x86_l_c37:
	/* 0xc37: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_c3a:
	/* 0xc3a: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_c40:
	/* 0xc40: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_c43:
	/* 0xc43: ja     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 272ULL;
	}
x86_l_c49:
	/* 0xc49: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_c4b:
	/* 0xc4b: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_c50:
	/* 0xc50: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_c54:
	/* 0xc54: jae    c7b <generic_uprobe_filter_arg+0xc7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_c7b;
	}
x86_l_c56:
	/* 0xc56: mov    rdx,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c5b:
	/* 0xc5b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c5e:
	/* 0xc5e: jle    c9f <generic_uprobe_filter_arg+0xc9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c9f;
	}
x86_l_c60:
	/* 0xc60: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_c63:
	/* 0xc63: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c66:
	/* 0xc66: jae    f18 <generic_uprobe_filter_arg+0xf18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3864ULL;
	}
x86_l_c6c:
	/* 0xc6c: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c70:
	/* 0xc70: jne    1de5 <generic_uprobe_filter_arg+0x1de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7653ULL;
	}
x86_l_c76:
	/* 0xc76: jmp    366e <generic_uprobe_filter_arg+0x366e> */
	return 13934ULL;
x86_l_c7b:
	/* 0xc7b: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_c80:
	/* 0xc80: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_c84:
	/* 0xc84: jb     cce <generic_uprobe_filter_arg+0xcce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cce;
	}
x86_l_c86:
	/* 0xc86: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_c90:
	/* 0xc90: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_c94:
	/* 0xc94: jb     f3c <generic_uprobe_filter_arg+0xf3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3900ULL;
	}
x86_l_c9a:
	/* 0xc9a: jmp    110 <generic_uprobe_filter_arg+0x110> */
	return 272ULL;
x86_l_c9f:
	/* 0xc9f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ca2:
	/* 0xca2: je     11d1 <generic_uprobe_filter_arg+0x11d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4561ULL;
	}
x86_l_ca8:
	/* 0xca8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cab:
	/* 0xcab: jne    1de5 <generic_uprobe_filter_arg+0x1de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7653ULL;
	}
x86_l_cb1:
	/* 0xcb1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_cb4:
	/* 0xcb4: je     cbf <generic_uprobe_filter_arg+0xcbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cbf;
	}
x86_l_cb6:
	/* 0xcb6: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_cb9:
	/* 0xcb9: jne    1ddb <generic_uprobe_filter_arg+0x1ddb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7643ULL;
	}
x86_l_cbf:
	/* 0xcbf: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc3:
	/* 0xcc3: jl     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_cc9:
	/* 0xcc9: jmp    1de5 <generic_uprobe_filter_arg+0x1de5> */
	return 7653ULL;
x86_l_cce:
	/* 0xcce: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_cd1:
	/* 0xcd1: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_cd4:
	/* 0xcd4: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_cda:
	/* 0xcda: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ce1:
	/* 0xce1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ce6:
	/* 0xce6: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ceb:
	/* 0xceb: mov    rdi,QWORD PTR [rip+0x1eea1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_cf2:
	/* 0xcf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf4:
	/* 0xcf4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cf7:
	/* 0xcf7: je     2ac <generic_uprobe_filter_arg+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 684ULL;
	}
x86_l_cfd:
	/* 0xcfd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d00:
	/* 0xd00: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d03:
	/* 0xd03: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d08:
	/* 0xd08: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d0d:
	/* 0xd0d: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d12:
	/* 0xd12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d14:
	/* 0xd14: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d19:
	/* 0xd19: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_d1c:
	/* 0xd1c: je     17a6 <generic_uprobe_filter_arg+0x17a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6054ULL;
	}
x86_l_d22:
	/* 0xd22: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_d25:
	/* 0xd25: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d2a:
	/* 0xd2a: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d2f:
	/* 0xd2f: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_d32:
	/* 0xd32: je     18bb <generic_uprobe_filter_arg+0x18bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6331ULL;
	}
x86_l_d38:
	/* 0xd38: jmp    18c9 <generic_uprobe_filter_arg+0x18c9> */
	return 6345ULL;
x86_l_d3d:
	/* 0xd3d: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_d40:
	/* 0xd40: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
	return 3395ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3395ULL: goto x86_l_d43;
	case 3401ULL: goto x86_l_d49;
	case 3408ULL: goto x86_l_d50;
	case 3413ULL: goto x86_l_d55;
	case 3418ULL: goto x86_l_d5a;
	case 3425ULL: goto x86_l_d61;
	case 3427ULL: goto x86_l_d63;
	case 3430ULL: goto x86_l_d66;
	case 3436ULL: goto x86_l_d6c;
	case 3439ULL: goto x86_l_d6f;
	case 3441ULL: goto x86_l_d71;
	case 3446ULL: goto x86_l_d76;
	case 3451ULL: goto x86_l_d7b;
	case 3456ULL: goto x86_l_d80;
	case 3461ULL: goto x86_l_d85;
	case 3466ULL: goto x86_l_d8a;
	case 3471ULL: goto x86_l_d8f;
	case 3476ULL: goto x86_l_d94;
	case 3481ULL: goto x86_l_d99;
	case 3485ULL: goto x86_l_d9d;
	case 3490ULL: goto x86_l_da2;
	case 3494ULL: goto x86_l_da6;
	case 3499ULL: goto x86_l_dab;
	case 3504ULL: goto x86_l_db0;
	case 3506ULL: goto x86_l_db2;
	case 3509ULL: goto x86_l_db5;
	case 3511ULL: goto x86_l_db7;
	case 3514ULL: goto x86_l_dba;
	case 3516ULL: goto x86_l_dbc;
	case 3519ULL: goto x86_l_dbf;
	case 3522ULL: goto x86_l_dc2;
	case 3528ULL: goto x86_l_dc8;
	case 3531ULL: goto x86_l_dcb;
	case 3536ULL: goto x86_l_dd0;
	case 3539ULL: goto x86_l_dd3;
	case 3545ULL: goto x86_l_dd9;
	case 3550ULL: goto x86_l_dde;
	case 3553ULL: goto x86_l_de1;
	case 3559ULL: goto x86_l_de7;
	case 3562ULL: goto x86_l_dea;
	case 3568ULL: goto x86_l_df0;
	case 3571ULL: goto x86_l_df3;
	case 3577ULL: goto x86_l_df9;
	case 3582ULL: goto x86_l_dfe;
	case 3585ULL: goto x86_l_e01;
	case 3591ULL: goto x86_l_e07;
	case 3596ULL: goto x86_l_e0c;
	case 3601ULL: goto x86_l_e11;
	case 3604ULL: goto x86_l_e14;
	case 3610ULL: goto x86_l_e1a;
	case 3613ULL: goto x86_l_e1d;
	case 3619ULL: goto x86_l_e23;
	case 3624ULL: goto x86_l_e28;
	case 3627ULL: goto x86_l_e2b;
	case 3633ULL: goto x86_l_e31;
	case 3638ULL: goto x86_l_e36;
	case 3641ULL: goto x86_l_e39;
	case 3647ULL: goto x86_l_e3f;
	case 3652ULL: goto x86_l_e44;
	case 3655ULL: goto x86_l_e47;
	case 3661ULL: goto x86_l_e4d;
	case 3666ULL: goto x86_l_e52;
	case 3668ULL: goto x86_l_e54;
	case 3671ULL: goto x86_l_e57;
	case 3674ULL: goto x86_l_e5a;
	case 3679ULL: goto x86_l_e5f;
	case 3683ULL: goto x86_l_e63;
	case 3688ULL: goto x86_l_e68;
	case 3693ULL: goto x86_l_e6d;
	case 3700ULL: goto x86_l_e74;
	case 3702ULL: goto x86_l_e76;
	case 3705ULL: goto x86_l_e79;
	case 3711ULL: goto x86_l_e7f;
	case 3713ULL: goto x86_l_e81;
	case 3716ULL: goto x86_l_e84;
	case 3721ULL: goto x86_l_e89;
	case 3723ULL: goto x86_l_e8b;
	case 3728ULL: goto x86_l_e90;
	case 3730ULL: goto x86_l_e92;
	case 3732ULL: goto x86_l_e94;
	case 3735ULL: goto x86_l_e97;
	case 3738ULL: goto x86_l_e9a;
	case 3741ULL: goto x86_l_e9d;
	case 3743ULL: goto x86_l_e9f;
	case 3745ULL: goto x86_l_ea1;
	case 3749ULL: goto x86_l_ea5;
	case 3752ULL: goto x86_l_ea8;
	case 3754ULL: goto x86_l_eaa;
	case 3758ULL: goto x86_l_eae;
	case 3760ULL: goto x86_l_eb0;
	case 3762ULL: goto x86_l_eb2;
	case 3767ULL: goto x86_l_eb7;
	case 3771ULL: goto x86_l_ebb;
	case 3774ULL: goto x86_l_ebe;
	case 3778ULL: goto x86_l_ec2;
	case 3782ULL: goto x86_l_ec6;
	case 3786ULL: goto x86_l_eca;
	case 3790ULL: goto x86_l_ece;
	case 3793ULL: goto x86_l_ed1;
	case 3797ULL: goto x86_l_ed5;
	case 3801ULL: goto x86_l_ed9;
	case 3805ULL: goto x86_l_edd;
	case 3809ULL: goto x86_l_ee1;
	case 3811ULL: goto x86_l_ee3;
	case 3814ULL: goto x86_l_ee6;
	case 3817ULL: goto x86_l_ee9;
	case 3819ULL: goto x86_l_eeb;
	case 3821ULL: goto x86_l_eed;
	case 3823ULL: goto x86_l_eef;
	case 3829ULL: goto x86_l_ef5;
	case 3833ULL: goto x86_l_ef9;
	case 3838ULL: goto x86_l_efe;
	case 3840ULL: goto x86_l_f00;
	case 3844ULL: goto x86_l_f04;
	case 3847ULL: goto x86_l_f07;
	case 3851ULL: goto x86_l_f0b;
	case 3857ULL: goto x86_l_f11;
	case 3859ULL: goto x86_l_f13;
	case 3864ULL: goto x86_l_f18;
	case 3867ULL: goto x86_l_f1b;
	case 3873ULL: goto x86_l_f21;
	case 3877ULL: goto x86_l_f25;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3891ULL: goto x86_l_f33;
	case 3894ULL: goto x86_l_f36;
	case 3900ULL: goto x86_l_f3c;
	case 3903ULL: goto x86_l_f3f;
	case 3909ULL: goto x86_l_f45;
	case 3914ULL: goto x86_l_f4a;
	case 3919ULL: goto x86_l_f4f;
	case 3922ULL: goto x86_l_f52;
	case 3924ULL: goto x86_l_f54;
	case 3927ULL: goto x86_l_f57;
	case 3933ULL: goto x86_l_f5d;
	case 3937ULL: goto x86_l_f61;
	case 3940ULL: goto x86_l_f64;
	case 3946ULL: goto x86_l_f6a;
	case 3949ULL: goto x86_l_f6d;
	case 3955ULL: goto x86_l_f73;
	case 3960ULL: goto x86_l_f78;
	case 3965ULL: goto x86_l_f7d;
	case 3970ULL: goto x86_l_f82;
	case 3975ULL: goto x86_l_f87;
	case 3979ULL: goto x86_l_f8b;
	case 3990ULL: goto x86_l_f96;
	case 3995ULL: goto x86_l_f9b;
	case 4000ULL: goto x86_l_fa0;
	case 4007ULL: goto x86_l_fa7;
	case 4009ULL: goto x86_l_fa9;
	case 4011ULL: goto x86_l_fab;
	case 4017ULL: goto x86_l_fb1;
	case 4020ULL: goto x86_l_fb4;
	case 4025ULL: goto x86_l_fb9;
	case 4028ULL: goto x86_l_fbc;
	case 4034ULL: goto x86_l_fc2;
	case 4039ULL: goto x86_l_fc7;
	case 4044ULL: goto x86_l_fcc;
	case 4051ULL: goto x86_l_fd3;
	case 4053ULL: goto x86_l_fd5;
	case 4056ULL: goto x86_l_fd8;
	case 4062ULL: goto x86_l_fde;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4076ULL: goto x86_l_fec;
	case 4083ULL: goto x86_l_ff3;
	case 4085ULL: goto x86_l_ff5;
	case 4088ULL: goto x86_l_ff8;
	case 4092ULL: goto x86_l_ffc;
	case 4095ULL: goto x86_l_fff;
	case 4100ULL: goto x86_l_1004;
	case 4105ULL: goto x86_l_1009;
	case 4107ULL: goto x86_l_100b;
	case 4109ULL: goto x86_l_100d;
	case 4114ULL: goto x86_l_1012;
	case 4119ULL: goto x86_l_1017;
	case 4130ULL: goto x86_l_1022;
	case 4136ULL: goto x86_l_1028;
	case 4142ULL: goto x86_l_102e;
	case 4145ULL: goto x86_l_1031;
	case 4150ULL: goto x86_l_1036;
	case 4155ULL: goto x86_l_103b;
	case 4161ULL: goto x86_l_1041;
	case 4165ULL: goto x86_l_1045;
	case 4171ULL: goto x86_l_104b;
	case 4174ULL: goto x86_l_104e;
	case 4177ULL: goto x86_l_1051;
	case 4180ULL: goto x86_l_1054;
	case 4182ULL: goto x86_l_1056;
	case 4185ULL: goto x86_l_1059;
	case 4187ULL: goto x86_l_105b;
	case 4189ULL: goto x86_l_105d;
	case 4191ULL: goto x86_l_105f;
	case 4193ULL: goto x86_l_1061;
	case 4195ULL: goto x86_l_1063;
	case 4198ULL: goto x86_l_1066;
	case 4200ULL: goto x86_l_1068;
	case 4202ULL: goto x86_l_106a;
	case 4204ULL: goto x86_l_106c;
	case 4207ULL: goto x86_l_106f;
	case 4210ULL: goto x86_l_1072;
	case 4214ULL: goto x86_l_1076;
	case 4220ULL: goto x86_l_107c;
	case 4222ULL: goto x86_l_107e;
	case 4225ULL: goto x86_l_1081;
	case 4231ULL: goto x86_l_1087;
	case 4234ULL: goto x86_l_108a;
	case 4236ULL: goto x86_l_108c;
	case 4241ULL: goto x86_l_1091;
	case 4244ULL: goto x86_l_1094;
	case 4250ULL: goto x86_l_109a;
	case 4253ULL: goto x86_l_109d;
	case 4259ULL: goto x86_l_10a3;
	case 4264ULL: goto x86_l_10a8;
	case 4267ULL: goto x86_l_10ab;
	case 4273ULL: goto x86_l_10b1;
	case 4278ULL: goto x86_l_10b6;
	case 4283ULL: goto x86_l_10bb;
	case 4288ULL: goto x86_l_10c0;
	case 4291ULL: goto x86_l_10c3;
	case 4293ULL: goto x86_l_10c5;
	case 4296ULL: goto x86_l_10c8;
	case 4302ULL: goto x86_l_10ce;
	case 4306ULL: goto x86_l_10d2;
	case 4309ULL: goto x86_l_10d5;
	case 4313ULL: goto x86_l_10d9;
	case 4316ULL: goto x86_l_10dc;
	case 4319ULL: goto x86_l_10df;
	case 4324ULL: goto x86_l_10e4;
	case 4327ULL: goto x86_l_10e7;
	case 4333ULL: goto x86_l_10ed;
	case 4337ULL: goto x86_l_10f1;
	case 4343ULL: goto x86_l_10f7;
	case 4348ULL: goto x86_l_10fc;
	case 4353ULL: goto x86_l_1101;
	case 4357ULL: goto x86_l_1105;
	case 4363ULL: goto x86_l_110b;
	case 4373ULL: goto x86_l_1115;
	case 4377ULL: goto x86_l_1119;
	case 4383ULL: goto x86_l_111f;
	case 4386ULL: goto x86_l_1122;
	case 4392ULL: goto x86_l_1128;
	case 4397ULL: goto x86_l_112d;
	case 4399ULL: goto x86_l_112f;
	case 4404ULL: goto x86_l_1134;
	case 4408ULL: goto x86_l_1138;
	case 4414ULL: goto x86_l_113e;
	case 4424ULL: goto x86_l_1148;
	case 4428ULL: goto x86_l_114c;
	case 4434ULL: goto x86_l_1152;
	case 4437ULL: goto x86_l_1155;
	case 4443ULL: goto x86_l_115b;
	case 4448ULL: goto x86_l_1160;
	case 4453ULL: goto x86_l_1165;
	case 4455ULL: goto x86_l_1167;
	case 4460ULL: goto x86_l_116c;
	case 4466ULL: goto x86_l_1172;
	case 4471ULL: goto x86_l_1177;
	case 4474ULL: goto x86_l_117a;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4487ULL: goto x86_l_1187;
	case 4492ULL: goto x86_l_118c;
	case 4498ULL: goto x86_l_1192;
	case 4501ULL: goto x86_l_1195;
	case 4507ULL: goto x86_l_119b;
	case 4512ULL: goto x86_l_11a0;
	case 4514ULL: goto x86_l_11a2;
	case 4519ULL: goto x86_l_11a7;
	case 4525ULL: goto x86_l_11ad;
	case 4528ULL: goto x86_l_11b0;
	case 4534ULL: goto x86_l_11b6;
	case 4539ULL: goto x86_l_11bb;
	case 4545ULL: goto x86_l_11c1;
	case 4550ULL: goto x86_l_11c6;
	case 4556ULL: goto x86_l_11cc;
	case 4561ULL: goto x86_l_11d1;
	case 4564ULL: goto x86_l_11d4;
	case 4566ULL: goto x86_l_11d6;
	case 4569ULL: goto x86_l_11d9;
	case 4575ULL: goto x86_l_11df;
	case 4579ULL: goto x86_l_11e3;
	case 4585ULL: goto x86_l_11e9;
	case 4590ULL: goto x86_l_11ee;
	case 4593ULL: goto x86_l_11f1;
	case 4598ULL: goto x86_l_11f6;
	case 4603ULL: goto x86_l_11fb;
	case 4608ULL: goto x86_l_1200;
	case 4614ULL: goto x86_l_1206;
	case 4618ULL: goto x86_l_120a;
	case 4624ULL: goto x86_l_1210;
	case 4627ULL: goto x86_l_1213;
	case 4630ULL: goto x86_l_1216;
	case 4633ULL: goto x86_l_1219;
	case 4635ULL: goto x86_l_121b;
	case 4638ULL: goto x86_l_121e;
	case 4640ULL: goto x86_l_1220;
	case 4642ULL: goto x86_l_1222;
	case 4644ULL: goto x86_l_1224;
	case 4646ULL: goto x86_l_1226;
	case 4648ULL: goto x86_l_1228;
	case 4651ULL: goto x86_l_122b;
	case 4653ULL: goto x86_l_122d;
	case 4655ULL: goto x86_l_122f;
	case 4657ULL: goto x86_l_1231;
	case 4660ULL: goto x86_l_1234;
	case 4663ULL: goto x86_l_1237;
	case 4667ULL: goto x86_l_123b;
	case 4673ULL: goto x86_l_1241;
	case 4675ULL: goto x86_l_1243;
	case 4678ULL: goto x86_l_1246;
	case 4684ULL: goto x86_l_124c;
	case 4687ULL: goto x86_l_124f;
	case 4689ULL: goto x86_l_1251;
	case 4694ULL: goto x86_l_1256;
	case 4697ULL: goto x86_l_1259;
	case 4702ULL: goto x86_l_125e;
	case 4708ULL: goto x86_l_1264;
	case 4711ULL: goto x86_l_1267;
	case 4717ULL: goto x86_l_126d;
	case 4722ULL: goto x86_l_1272;
	case 4725ULL: goto x86_l_1275;
	case 4731ULL: goto x86_l_127b;
	case 4736ULL: goto x86_l_1280;
	case 4741ULL: goto x86_l_1285;
	case 4745ULL: goto x86_l_1289;
	case 4756ULL: goto x86_l_1294;
	case 4761ULL: goto x86_l_1299;
	case 4766ULL: goto x86_l_129e;
	case 4773ULL: goto x86_l_12a5;
	case 4775ULL: goto x86_l_12a7;
	case 4777ULL: goto x86_l_12a9;
	case 4783ULL: goto x86_l_12af;
	case 4786ULL: goto x86_l_12b2;
	case 4791ULL: goto x86_l_12b7;
	case 4794ULL: goto x86_l_12ba;
	case 4800ULL: goto x86_l_12c0;
	case 4805ULL: goto x86_l_12c5;
	case 4810ULL: goto x86_l_12ca;
	case 4817ULL: goto x86_l_12d1;
	case 4819ULL: goto x86_l_12d3;
	case 4822ULL: goto x86_l_12d6;
	case 4828ULL: goto x86_l_12dc;
	case 4831ULL: goto x86_l_12df;
	case 4836ULL: goto x86_l_12e4;
	case 4839ULL: goto x86_l_12e7;
	case 4844ULL: goto x86_l_12ec;
	case 4847ULL: goto x86_l_12ef;
	case 4850ULL: goto x86_l_12f2;
	case 4852ULL: goto x86_l_12f4;
	case 4855ULL: goto x86_l_12f7;
	case 4858ULL: goto x86_l_12fa;
	case 4863ULL: goto x86_l_12ff;
	case 4866ULL: goto x86_l_1302;
	case 4869ULL: goto x86_l_1305;
	case 4874ULL: goto x86_l_130a;
	case 4878ULL: goto x86_l_130e;
	case 4884ULL: goto x86_l_1314;
	case 4887ULL: goto x86_l_1317;
	case 4891ULL: goto x86_l_131b;
	case 4897ULL: goto x86_l_1321;
	case 4900ULL: goto x86_l_1324;
	case 4904ULL: goto x86_l_1328;
	case 4906ULL: goto x86_l_132a;
	case 4908ULL: goto x86_l_132c;
	case 4913ULL: goto x86_l_1331;
	case 4917ULL: goto x86_l_1335;
	case 4924ULL: goto x86_l_133c;
	case 4929ULL: goto x86_l_1341;
	case 4933ULL: goto x86_l_1345;
	case 4936ULL: goto x86_l_1348;
	case 4938ULL: goto x86_l_134a;
	case 4942ULL: goto x86_l_134e;
	case 4949ULL: goto x86_l_1355;
	case 4954ULL: goto x86_l_135a;
	case 4958ULL: goto x86_l_135e;
	case 4961ULL: goto x86_l_1361;
	case 4963ULL: goto x86_l_1363;
	case 4967ULL: goto x86_l_1367;
	case 4974ULL: goto x86_l_136e;
	case 4979ULL: goto x86_l_1373;
	case 4983ULL: goto x86_l_1377;
	case 4986ULL: goto x86_l_137a;
	case 4988ULL: goto x86_l_137c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d43:
	/* 0xd43: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_d49:
	/* 0xd49: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d50:
	/* 0xd50: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d55:
	/* 0xd55: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d5a:
	/* 0xd5a: mov    rdi,QWORD PTR [rip+0x1eea1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_d61:
	/* 0xd61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d63:
	/* 0xd63: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d66:
	/* 0xd66: je     2ac <generic_uprobe_filter_arg+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 684ULL;
	}
x86_l_d6c:
	/* 0xd6c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d6f:
	/* 0xd6f: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d71:
	/* 0xd71: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d76:
	/* 0xd76: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d7b:
	/* 0xd7b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d80:
	/* 0xd80: jmp    1cb3 <generic_uprobe_filter_arg+0x1cb3> */
	return 7347ULL;
x86_l_d85:
	/* 0xd85: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d8a:
	/* 0xd8a: mov    WORD PTR [rsp+0x66],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 102ULL);
x86_l_d8f:
	/* 0xd8f: movzx  edx,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_d94:
	/* 0xd94: mov    WORD PTR [rsp+0x60],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d99:
	/* 0xd99: mov    rdx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d9d:
	/* 0xd9d: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_da2:
	/* 0xda2: mov    rdx,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_da6:
	/* 0xda6: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_dab:
	/* 0xdab: lea    r13,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_db0:
	/* 0xdb0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_db2:
	/* 0xdb2: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_db5:
	/* 0xdb5: jle    dde <generic_uprobe_filter_arg+0xdde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_dde;
	}
x86_l_db7:
	/* 0xdb7: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_dba:
	/* 0xdba: jg     e11 <generic_uprobe_filter_arg+0xe11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_e11;
	}
x86_l_dbc:
	/* 0xdbc: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_dbf:
	/* 0xdbf: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dc2:
	/* 0xdc2: jb     1427 <generic_uprobe_filter_arg+0x1427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5159ULL;
	}
x86_l_dc8:
	/* 0xdc8: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_dcb:
	/* 0xdcb: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_dd0:
	/* 0xdd0: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dd3:
	/* 0xdd3: jb     141d <generic_uprobe_filter_arg+0x141d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5149ULL;
	}
x86_l_dd9:
	/* 0xdd9: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_dde:
	/* 0xdde: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_de1:
	/* 0xde1: jle    1091 <generic_uprobe_filter_arg+0x1091> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1091;
	}
x86_l_de7:
	/* 0xde7: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_dea:
	/* 0xdea: jg     140a <generic_uprobe_filter_arg+0x140a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5130ULL;
	}
x86_l_df0:
	/* 0xdf0: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_df3:
	/* 0xdf3: je     141d <generic_uprobe_filter_arg+0x141d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5149ULL;
	}
x86_l_df9:
	/* 0xdf9: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_dfe:
	/* 0xdfe: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_e01:
	/* 0xe01: jne    2bb <generic_uprobe_filter_arg+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 699ULL;
	}
x86_l_e07:
	/* 0xe07: movzx  ebx,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_e0c:
	/* 0xe0c: jmp    1c72 <generic_uprobe_filter_arg+0x1c72> */
	return 7282ULL;
x86_l_e11:
	/* 0xe11: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_e14:
	/* 0xe14: jg     1468 <generic_uprobe_filter_arg+0x1468> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5224ULL;
	}
x86_l_e1a:
	/* 0xe1a: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_e1d:
	/* 0xe1d: je     14a5 <generic_uprobe_filter_arg+0x14a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5285ULL;
	}
x86_l_e23:
	/* 0xe23: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_e28:
	/* 0xe28: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_e2b:
	/* 0xe2b: je     1498 <generic_uprobe_filter_arg+0x1498> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5272ULL;
	}
x86_l_e31:
	/* 0xe31: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_e36:
	/* 0xe36: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_e39:
	/* 0xe39: je     1577 <generic_uprobe_filter_arg+0x1577> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5495ULL;
	}
x86_l_e3f:
	/* 0xe3f: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_e44:
	/* 0xe44: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_e47:
	/* 0xe47: jne    3746 <generic_uprobe_filter_arg+0x3746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14150ULL;
	}
x86_l_e4d:
	/* 0xe4d: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e52:
	/* 0xe52: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e54:
	/* 0xe54: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e57:
	/* 0xe57: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_e5a:
	/* 0xe5a: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_e5f:
	/* 0xe5f: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e63:
	/* 0xe63: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e68:
	/* 0xe68: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e6d:
	/* 0xe6d: mov    rdi,QWORD PTR [rip+0x1eea1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_e74:
	/* 0xe74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e76:
	/* 0xe76: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e79:
	/* 0xe79: je     2265 <generic_uprobe_filter_arg+0x2265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8805ULL;
	}
x86_l_e7f:
	/* 0xe7f: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_e81:
	/* 0xe81: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_e84:
	/* 0xe84: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e89:
	/* 0xe89: je     ef5 <generic_uprobe_filter_arg+0xef5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ef5;
	}
x86_l_e8b:
	/* 0xe8b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e90:
	/* 0xe90: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e92:
	/* 0xe92: jmp    e9f <generic_uprobe_filter_arg+0xe9f> */
	goto x86_l_e9f;
x86_l_e94:
	/* 0xe94: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e97:
	/* 0xe97: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e9a:
	/* 0xe9a: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_e9d:
	/* 0xe9d: je     ef5 <generic_uprobe_filter_arg+0xef5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ef5;
	}
x86_l_e9f:
	/* 0xe9f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ea1:
	/* 0xea1: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_ea5:
	/* 0xea5: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_ea8:
	/* 0xea8: jae    e94 <generic_uprobe_filter_arg+0xe94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e94;
	}
x86_l_eaa:
	/* 0xeaa: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_eae:
	/* 0xeae: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_eb0:
	/* 0xeb0: je     eed <generic_uprobe_filter_arg+0xeed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eed;
	}
x86_l_eb2:
	/* 0xeb2: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_eb7:
	/* 0xeb7: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_ebb:
	/* 0xebb: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_ebe:
	/* 0xebe: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_ec2:
	/* 0xec2: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_ec6:
	/* 0xec6: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_eca:
	/* 0xeca: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_ece:
	/* 0xece: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_ed1:
	/* 0xed1: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_ed5:
	/* 0xed5: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_ed9:
	/* 0xed9: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_edd:
	/* 0xedd: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_ee1:
	/* 0xee1: ja     e94 <generic_uprobe_filter_arg+0xe94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e94;
	}
x86_l_ee3:
	/* 0xee3: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ee6:
	/* 0xee6: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_ee9:
	/* 0xee9: je     ea1 <generic_uprobe_filter_arg+0xea1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ea1;
	}
x86_l_eeb:
	/* 0xeeb: jmp    e94 <generic_uprobe_filter_arg+0xe94> */
	goto x86_l_e94;
x86_l_eed:
	/* 0xeed: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_eef:
	/* 0xeef: jns    25b0 <generic_uprobe_filter_arg+0x25b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9648ULL;
	}
x86_l_ef5:
	/* 0xef5: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ef9:
	/* 0xef9: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_efe:
	/* 0xefe: jae    f11 <generic_uprobe_filter_arg+0xf11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f11;
	}
x86_l_f00:
	/* 0xf00: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_f04:
	/* 0xf04: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_f07:
	/* 0xf07: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_f0b:
	/* 0xf0b: jne    e57 <generic_uprobe_filter_arg+0xe57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e57;
	}
x86_l_f11:
	/* 0xf11: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f13:
	/* 0xf13: jmp    25b5 <generic_uprobe_filter_arg+0x25b5> */
	return 9653ULL;
x86_l_f18:
	/* 0xf18: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_f1b:
	/* 0xf1b: jne    1de5 <generic_uprobe_filter_arg+0x1de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7653ULL;
	}
x86_l_f21:
	/* 0xf21: test   QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f25:
	/* 0xf25: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_f2b:
	/* 0xf2b: jmp    1de5 <generic_uprobe_filter_arg+0x1de5> */
	return 7653ULL;
x86_l_f30:
	/* 0xf30: lea    edx,[rax-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_f33:
	/* 0xf33: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_f36:
	/* 0xf36: jae    18d3 <generic_uprobe_filter_arg+0x18d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6355ULL;
	}
x86_l_f3c:
	/* 0xf3c: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_f3f:
	/* 0xf3f: jne    10b6 <generic_uprobe_filter_arg+0x10b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10b6;
	}
x86_l_f45:
	/* 0xf45: mov    rsi,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f4a:
	/* 0xf4a: mov    rdx,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f4f:
	/* 0xf4f: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f52:
	/* 0xf52: je     f5d <generic_uprobe_filter_arg+0xf5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f5d;
	}
x86_l_f54:
	/* 0xf54: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_f57:
	/* 0xf57: jne    1bcc <generic_uprobe_filter_arg+0x1bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7116ULL;
	}
x86_l_f5d:
	/* 0xf5d: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f61:
	/* 0xf61: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f64:
	/* 0xf64: jg     1bde <generic_uprobe_filter_arg+0x1bde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7134ULL;
	}
x86_l_f6a:
	/* 0xf6a: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_f6d:
	/* 0xf6d: jle    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_f73:
	/* 0xf73: jmp    1bde <generic_uprobe_filter_arg+0x1bde> */
	return 7134ULL;
x86_l_f78:
	/* 0xf78: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f7d:
	/* 0xf7d: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f82:
	/* 0xf82: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f87:
	/* 0xf87: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f8b:
	/* 0xf8b: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_f96:
	/* 0xf96: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f9b:
	/* 0xf9b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fa0:
	/* 0xfa0: mov    rdi,QWORD PTR [rip+0x1eeaf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_fa7:
	/* 0xfa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa9:
	/* 0xfa9: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_fab:
	/* 0xfab: je     3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14133ULL;
	}
x86_l_fb1:
	/* 0xfb1: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_fb4:
	/* 0xfb4: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_fb9:
	/* 0xfb9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fbc:
	/* 0xfbc: je     3737 <generic_uprobe_filter_arg+0x3737> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14135ULL;
	}
x86_l_fc2:
	/* 0xfc2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fc7:
	/* 0xfc7: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fcc:
	/* 0xfcc: mov    rdi,QWORD PTR [rip+0x1eeaf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_fd3:
	/* 0xfd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd5:
	/* 0xfd5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fd8:
	/* 0xfd8: je     3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14133ULL;
	}
x86_l_fde:
	/* 0xfde: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_fe4:
	/* 0xfe4: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_fe9:
	/* 0xfe9: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_fec:
	/* 0xfec: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_ff3:
	/* 0xff3: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ff5:
	/* 0xff5: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_ff8:
	/* 0xff8: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_ffc:
	/* 0xffc: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_fff:
	/* 0xfff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1004:
	/* 0x1004: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1009:
	/* 0x1009: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_100b:
	/* 0x100b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_100d:
	/* 0x100d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1012:
	/* 0x1012: jmp    1b38 <generic_uprobe_filter_arg+0x1b38> */
	return 6968ULL;
x86_l_1017:
	/* 0x1017: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1022:
	/* 0x1022: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_1028:
	/* 0x1028: ja     2b10 <generic_uprobe_filter_arg+0x2b10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11024ULL;
	}
x86_l_102e:
	/* 0x102e: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1031:
	/* 0x1031: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1036:
	/* 0x1036: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_103b:
	/* 0x103b: ja     1d68 <generic_uprobe_filter_arg+0x1d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7528ULL;
	}
x86_l_1041:
	/* 0x1041: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1045:
	/* 0x1045: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_104b:
	/* 0x104b: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_104e:
	/* 0x104e: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1051:
	/* 0x1051: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1054:
	/* 0x1054: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1056:
	/* 0x1056: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1059:
	/* 0x1059: je     1063 <generic_uprobe_filter_arg+0x1063> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1063;
	}
x86_l_105b:
	/* 0x105b: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_105d:
	/* 0x105d: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_105f:
	/* 0x105f: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1061:
	/* 0x1061: je     107e <generic_uprobe_filter_arg+0x107e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_107e;
	}
x86_l_1063:
	/* 0x1063: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1066:
	/* 0x1066: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1068:
	/* 0x1068: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_106a:
	/* 0x106a: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_106c:
	/* 0x106c: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_106f:
	/* 0x106f: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1072:
	/* 0x1072: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1076:
	/* 0x1076: ja     1d9f <generic_uprobe_filter_arg+0x1d9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7583ULL;
	}
x86_l_107c:
	/* 0x107c: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_107e:
	/* 0x107e: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1081:
	/* 0x1081: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1087:
	/* 0x1087: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_108a:
	/* 0x108a: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_108c:
	/* 0x108c: jmp    2a45 <generic_uprobe_filter_arg+0x2a45> */
	return 10821ULL;
x86_l_1091:
	/* 0x1091: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1094:
	/* 0x1094: je     14a5 <generic_uprobe_filter_arg+0x14a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5285ULL;
	}
x86_l_109a:
	/* 0x109a: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_109d:
	/* 0x109d: je     1498 <generic_uprobe_filter_arg+0x1498> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5272ULL;
	}
x86_l_10a3:
	/* 0x10a3: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_10a8:
	/* 0x10a8: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_10ab:
	/* 0x10ab: je     1427 <generic_uprobe_filter_arg+0x1427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5159ULL;
	}
x86_l_10b1:
	/* 0x10b1: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_10b6:
	/* 0x10b6: mov    rsi,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10bb:
	/* 0x10bb: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10c0:
	/* 0x10c0: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_10c3:
	/* 0x10c3: je     10ce <generic_uprobe_filter_arg+0x10ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10ce;
	}
x86_l_10c5:
	/* 0x10c5: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_10c8:
	/* 0x10c8: jne    1c20 <generic_uprobe_filter_arg+0x1c20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7200ULL;
	}
x86_l_10ce:
	/* 0x10ce: mov    rdx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10d2:
	/* 0x10d2: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_10d5:
	/* 0x10d5: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_10d9:
	/* 0x10d9: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_10dc:
	/* 0x10dc: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_10df:
	/* 0x10df: jmp    1c31 <generic_uprobe_filter_arg+0x1c31> */
	return 7217ULL;
x86_l_10e4:
	/* 0x10e4: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_10e7:
	/* 0x10e7: jne    22ec <generic_uprobe_filter_arg+0x22ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8940ULL;
	}
x86_l_10ed:
	/* 0x10ed: test   DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f1:
	/* 0x10f1: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_10f7:
	/* 0x10f7: jmp    22ec <generic_uprobe_filter_arg+0x22ec> */
	return 8940ULL;
x86_l_10fc:
	/* 0x10fc: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_1101:
	/* 0x1101: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1105:
	/* 0x1105: jb     16be <generic_uprobe_filter_arg+0x16be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5822ULL;
	}
x86_l_110b:
	/* 0x110b: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_1115:
	/* 0x1115: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1119:
	/* 0x1119: jae    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 272ULL;
	}
x86_l_111f:
	/* 0x111f: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_1122:
	/* 0x1122: jne    1ed4 <generic_uprobe_filter_arg+0x1ed4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7892ULL;
	}
x86_l_1128:
	/* 0x1128: movzx  eax,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_112d:
	/* 0x112d: jmp    1160 <generic_uprobe_filter_arg+0x1160> */
	goto x86_l_1160;
x86_l_112f:
	/* 0x112f: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_1134:
	/* 0x1134: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1138:
	/* 0x1138: jb     1707 <generic_uprobe_filter_arg+0x1707> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5895ULL;
	}
x86_l_113e:
	/* 0x113e: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_1148:
	/* 0x1148: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_114c:
	/* 0x114c: jae    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 272ULL;
	}
x86_l_1152:
	/* 0x1152: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_1155:
	/* 0x1155: jne    1ee0 <generic_uprobe_filter_arg+0x1ee0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7904ULL;
	}
x86_l_115b:
	/* 0x115b: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1160:
	/* 0x1160: cmp    DWORD PTR [r12+0x10],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1165:
	/* 0x1165: ja     1172 <generic_uprobe_filter_arg+0x1172> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1172;
	}
x86_l_1167:
	/* 0x1167: cmp    DWORD PTR [r12+0x14],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_116c:
	/* 0x116c: jae    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 716ULL;
	}
x86_l_1172:
	/* 0x1172: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1177:
	/* 0x1177: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_117a:
	/* 0x117a: jb     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 272ULL;
	}
x86_l_1180:
	/* 0x1180: cmp    DWORD PTR [r12+0x18],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1185:
	/* 0x1185: ja     1192 <generic_uprobe_filter_arg+0x1192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1192;
	}
x86_l_1187:
	/* 0x1187: cmp    DWORD PTR [r12+0x1c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_118c:
	/* 0x118c: jae    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 716ULL;
	}
x86_l_1192:
	/* 0x1192: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_1195:
	/* 0x1195: jb     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 272ULL;
	}
x86_l_119b:
	/* 0x119b: cmp    DWORD PTR [r12+0x20],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11a0:
	/* 0x11a0: ja     11ad <generic_uprobe_filter_arg+0x11ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11ad;
	}
x86_l_11a2:
	/* 0x11a2: cmp    DWORD PTR [r12+0x24],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_11a7:
	/* 0x11a7: jae    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 716ULL;
	}
x86_l_11ad:
	/* 0x11ad: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_11b0:
	/* 0x11b0: jb     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 272ULL;
	}
x86_l_11b6:
	/* 0x11b6: cmp    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11bb:
	/* 0x11bb: ja     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 272ULL;
	}
x86_l_11c1:
	/* 0x11c1: cmp    DWORD PTR [r12+0x2c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_11c6:
	/* 0x11c6: jae    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 716ULL;
	}
x86_l_11cc:
	/* 0x11cc: jmp    110 <generic_uprobe_filter_arg+0x110> */
	return 272ULL;
x86_l_11d1:
	/* 0x11d1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_11d4:
	/* 0x11d4: je     11df <generic_uprobe_filter_arg+0x11df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11df;
	}
x86_l_11d6:
	/* 0x11d6: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_11d9:
	/* 0x11d9: jne    1dcf <generic_uprobe_filter_arg+0x1dcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7631ULL;
	}
x86_l_11df:
	/* 0x11df: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11e3:
	/* 0x11e3: jg     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_11e9:
	/* 0x11e9: jmp    1de5 <generic_uprobe_filter_arg+0x1de5> */
	return 7653ULL;
x86_l_11ee:
	/* 0x11ee: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11f1:
	/* 0x11f1: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_11f6:
	/* 0x11f6: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11fb:
	/* 0x11fb: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1200:
	/* 0x1200: ja     17c1 <generic_uprobe_filter_arg+0x17c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6081ULL;
	}
x86_l_1206:
	/* 0x1206: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_120a:
	/* 0x120a: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1210:
	/* 0x1210: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1213:
	/* 0x1213: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1216:
	/* 0x1216: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1219:
	/* 0x1219: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_121b:
	/* 0x121b: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_121e:
	/* 0x121e: je     1228 <generic_uprobe_filter_arg+0x1228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1228;
	}
x86_l_1220:
	/* 0x1220: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1222:
	/* 0x1222: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1224:
	/* 0x1224: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1226:
	/* 0x1226: je     1243 <generic_uprobe_filter_arg+0x1243> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1243;
	}
x86_l_1228:
	/* 0x1228: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_122b:
	/* 0x122b: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_122d:
	/* 0x122d: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_122f:
	/* 0x122f: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1231:
	/* 0x1231: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1234:
	/* 0x1234: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1237:
	/* 0x1237: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_123b:
	/* 0x123b: ja     17f8 <generic_uprobe_filter_arg+0x17f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6136ULL;
	}
x86_l_1241:
	/* 0x1241: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1243:
	/* 0x1243: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1246:
	/* 0x1246: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_124c:
	/* 0x124c: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_124f:
	/* 0x124f: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1251:
	/* 0x1251: jmp    2405 <generic_uprobe_filter_arg+0x2405> */
	return 9221ULL;
x86_l_1256:
	/* 0x1256: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1259:
	/* 0x1259: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_125e:
	/* 0x125e: jg     191a <generic_uprobe_filter_arg+0x191a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6426ULL;
	}
x86_l_1264:
	/* 0x1264: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1267:
	/* 0x1267: je     1aa3 <generic_uprobe_filter_arg+0x1aa3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6819ULL;
	}
x86_l_126d:
	/* 0x126d: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1272:
	/* 0x1272: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1275:
	/* 0x1275: jne    3746 <generic_uprobe_filter_arg+0x3746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14150ULL;
	}
x86_l_127b:
	/* 0x127b: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1280:
	/* 0x1280: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1285:
	/* 0x1285: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1289:
	/* 0x1289: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1294:
	/* 0x1294: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1299:
	/* 0x1299: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_129e:
	/* 0x129e: mov    rdi,QWORD PTR [rip+0x1eeaf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_12a5:
	/* 0x12a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a7:
	/* 0x12a7: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_12a9:
	/* 0x12a9: je     3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14133ULL;
	}
x86_l_12af:
	/* 0x12af: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_12b2:
	/* 0x12b2: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_12b7:
	/* 0x12b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12ba:
	/* 0x12ba: je     3737 <generic_uprobe_filter_arg+0x3737> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14135ULL;
	}
x86_l_12c0:
	/* 0x12c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12c5:
	/* 0x12c5: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12ca:
	/* 0x12ca: mov    rdi,QWORD PTR [rip+0x1eeaf] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_12d1:
	/* 0x12d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d3:
	/* 0x12d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12d6:
	/* 0x12d6: je     3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14133ULL;
	}
x86_l_12dc:
	/* 0x12dc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12df:
	/* 0x12df: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12e4:
	/* 0x12e4: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_12e7:
	/* 0x12e7: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_12ec:
	/* 0x12ec: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_12ef:
	/* 0x12ef: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_12f2:
	/* 0x12f2: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12f4:
	/* 0x12f4: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_12f7:
	/* 0x12f7: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_12fa:
	/* 0x12fa: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_12ff:
	/* 0x12ff: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1302:
	/* 0x1302: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_1305:
	/* 0x1305: mov    QWORD PTR [rsp+0x70],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_130a:
	/* 0x130a: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_130e:
	/* 0x130e: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1314:
	/* 0x1314: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1317:
	/* 0x1317: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_131b:
	/* 0x131b: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_1321:
	/* 0x1321: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1324:
	/* 0x1324: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1328:
	/* 0x1328: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_132a:
	/* 0x132a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_132c:
	/* 0x132c: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1331:
	/* 0x1331: lea    r13d,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1335:
	/* 0x1335: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_133c:
	/* 0x133c: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_1341:
	/* 0x1341: mov    BYTE PTR [rdi-0x3],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1345:
	/* 0x1345: cmp    r10,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RBX, X86_WIDTH_64);
x86_l_1348:
	/* 0x1348: je     13a2 <generic_uprobe_filter_arg+0x13a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5026ULL;
	}
x86_l_134a:
	/* 0x134a: lea    r13d,[r11+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_134e:
	/* 0x134e: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1355:
	/* 0x1355: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_135a:
	/* 0x135a: mov    BYTE PTR [rdi-0x2],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_135e:
	/* 0x135e: cmp    r8,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RBX, X86_WIDTH_64);
x86_l_1361:
	/* 0x1361: je     13a2 <generic_uprobe_filter_arg+0x13a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5026ULL;
	}
x86_l_1363:
	/* 0x1363: lea    r13d,[r9+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1367:
	/* 0x1367: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_136e:
	/* 0x136e: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_1373:
	/* 0x1373: mov    BYTE PTR [rdi-0x1],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1377:
	/* 0x1377: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_137a:
	/* 0x137a: je     13a2 <generic_uprobe_filter_arg+0x13a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5026ULL;
	}
x86_l_137c:
	/* 0x137c: cmp    rbx,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551492ULL);
	return 4992ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4992ULL: goto x86_l_1380;
	case 4994ULL: goto x86_l_1382;
	case 4998ULL: goto x86_l_1386;
	case 5005ULL: goto x86_l_138d;
	case 5010ULL: goto x86_l_1392;
	case 5013ULL: goto x86_l_1395;
	case 5017ULL: goto x86_l_1399;
	case 5021ULL: goto x86_l_139d;
	case 5024ULL: goto x86_l_13a0;
	case 5026ULL: goto x86_l_13a2;
	case 5031ULL: goto x86_l_13a7;
	case 5036ULL: goto x86_l_13ac;
	case 5041ULL: goto x86_l_13b1;
	case 5046ULL: goto x86_l_13b6;
	case 5051ULL: goto x86_l_13bb;
	case 5056ULL: goto x86_l_13c0;
	case 5059ULL: goto x86_l_13c3;
	case 5065ULL: goto x86_l_13c9;
	case 5070ULL: goto x86_l_13ce;
	case 5073ULL: goto x86_l_13d1;
	case 5079ULL: goto x86_l_13d7;
	case 5083ULL: goto x86_l_13db;
	case 5085ULL: goto x86_l_13dd;
	case 5089ULL: goto x86_l_13e1;
	case 5091ULL: goto x86_l_13e3;
	case 5094ULL: goto x86_l_13e6;
	case 5099ULL: goto x86_l_13eb;
	case 5102ULL: goto x86_l_13ee;
	case 5108ULL: goto x86_l_13f4;
	case 5111ULL: goto x86_l_13f7;
	case 5116ULL: goto x86_l_13fc;
	case 5119ULL: goto x86_l_13ff;
	case 5125ULL: goto x86_l_1405;
	case 5130ULL: goto x86_l_140a;
	case 5133ULL: goto x86_l_140d;
	case 5135ULL: goto x86_l_140f;
	case 5140ULL: goto x86_l_1414;
	case 5143ULL: goto x86_l_1417;
	case 5149ULL: goto x86_l_141d;
	case 5152ULL: goto x86_l_1420;
	case 5157ULL: goto x86_l_1425;
	case 5159ULL: goto x86_l_1427;
	case 5162ULL: goto x86_l_142a;
	case 5167ULL: goto x86_l_142f;
	case 5169ULL: goto x86_l_1431;
	case 5172ULL: goto x86_l_1434;
	case 5175ULL: goto x86_l_1437;
	case 5177ULL: goto x86_l_1439;
	case 5180ULL: goto x86_l_143c;
	case 5186ULL: goto x86_l_1442;
	case 5189ULL: goto x86_l_1445;
	case 5192ULL: goto x86_l_1448;
	case 5198ULL: goto x86_l_144e;
	case 5201ULL: goto x86_l_1451;
	case 5204ULL: goto x86_l_1454;
	case 5210ULL: goto x86_l_145a;
	case 5213ULL: goto x86_l_145d;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5227ULL: goto x86_l_146b;
	case 5233ULL: goto x86_l_1471;
	case 5238ULL: goto x86_l_1476;
	case 5241ULL: goto x86_l_1479;
	case 5247ULL: goto x86_l_147f;
	case 5250ULL: goto x86_l_1482;
	case 5256ULL: goto x86_l_1488;
	case 5259ULL: goto x86_l_148b;
	case 5265ULL: goto x86_l_1491;
	case 5267ULL: goto x86_l_1493;
	case 5272ULL: goto x86_l_1498;
	case 5276ULL: goto x86_l_149c;
	case 5279ULL: goto x86_l_149f;
	case 5283ULL: goto x86_l_14a3;
	case 5285ULL: goto x86_l_14a5;
	case 5289ULL: goto x86_l_14a9;
	case 5292ULL: goto x86_l_14ac;
	case 5296ULL: goto x86_l_14b0;
	case 5299ULL: goto x86_l_14b3;
	case 5303ULL: goto x86_l_14b7;
	case 5305ULL: goto x86_l_14b9;
	case 5307ULL: goto x86_l_14bb;
	case 5310ULL: goto x86_l_14be;
	case 5312ULL: goto x86_l_14c0;
	case 5315ULL: goto x86_l_14c3;
	case 5321ULL: goto x86_l_14c9;
	case 5326ULL: goto x86_l_14ce;
	case 5329ULL: goto x86_l_14d1;
	case 5335ULL: goto x86_l_14d7;
	case 5340ULL: goto x86_l_14dc;
	case 5343ULL: goto x86_l_14df;
	case 5349ULL: goto x86_l_14e5;
	case 5354ULL: goto x86_l_14ea;
	case 5357ULL: goto x86_l_14ed;
	case 5363ULL: goto x86_l_14f3;
	case 5367ULL: goto x86_l_14f7;
	case 5370ULL: goto x86_l_14fa;
	case 5376ULL: goto x86_l_1500;
	case 5379ULL: goto x86_l_1503;
	case 5385ULL: goto x86_l_1509;
	case 5388ULL: goto x86_l_150c;
	case 5393ULL: goto x86_l_1511;
	case 5398ULL: goto x86_l_1516;
	case 5402ULL: goto x86_l_151a;
	case 5407ULL: goto x86_l_151f;
	case 5412ULL: goto x86_l_1524;
	case 5419ULL: goto x86_l_152b;
	case 5421ULL: goto x86_l_152d;
	case 5424ULL: goto x86_l_1530;
	case 5430ULL: goto x86_l_1536;
	case 5433ULL: goto x86_l_1539;
	case 5444ULL: goto x86_l_1544;
	case 5452ULL: goto x86_l_154c;
	case 5457ULL: goto x86_l_1551;
	case 5460ULL: goto x86_l_1554;
	case 5466ULL: goto x86_l_155a;
	case 5471ULL: goto x86_l_155f;
	case 5474ULL: goto x86_l_1562;
	case 5480ULL: goto x86_l_1568;
	case 5484ULL: goto x86_l_156c;
	case 5490ULL: goto x86_l_1572;
	case 5495ULL: goto x86_l_1577;
	case 5500ULL: goto x86_l_157c;
	case 5502ULL: goto x86_l_157e;
	case 5505ULL: goto x86_l_1581;
	case 5508ULL: goto x86_l_1584;
	case 5513ULL: goto x86_l_1589;
	case 5517ULL: goto x86_l_158d;
	case 5522ULL: goto x86_l_1592;
	case 5527ULL: goto x86_l_1597;
	case 5534ULL: goto x86_l_159e;
	case 5536ULL: goto x86_l_15a0;
	case 5539ULL: goto x86_l_15a3;
	case 5545ULL: goto x86_l_15a9;
	case 5547ULL: goto x86_l_15ab;
	case 5552ULL: goto x86_l_15b0;
	case 5555ULL: goto x86_l_15b3;
	case 5560ULL: goto x86_l_15b8;
	case 5562ULL: goto x86_l_15ba;
	case 5567ULL: goto x86_l_15bf;
	case 5569ULL: goto x86_l_15c1;
	case 5571ULL: goto x86_l_15c3;
	case 5574ULL: goto x86_l_15c6;
	case 5577ULL: goto x86_l_15c9;
	case 5580ULL: goto x86_l_15cc;
	case 5582ULL: goto x86_l_15ce;
	case 5584ULL: goto x86_l_15d0;
	case 5588ULL: goto x86_l_15d4;
	case 5591ULL: goto x86_l_15d7;
	case 5593ULL: goto x86_l_15d9;
	case 5597ULL: goto x86_l_15dd;
	case 5600ULL: goto x86_l_15e0;
	case 5602ULL: goto x86_l_15e2;
	case 5606ULL: goto x86_l_15e6;
	case 5608ULL: goto x86_l_15e8;
	case 5612ULL: goto x86_l_15ec;
	case 5616ULL: goto x86_l_15f0;
	case 5619ULL: goto x86_l_15f3;
	case 5621ULL: goto x86_l_15f5;
	case 5623ULL: goto x86_l_15f7;
	case 5625ULL: goto x86_l_15f9;
	case 5631ULL: goto x86_l_15ff;
	case 5635ULL: goto x86_l_1603;
	case 5640ULL: goto x86_l_1608;
	case 5646ULL: goto x86_l_160e;
	case 5650ULL: goto x86_l_1612;
	case 5653ULL: goto x86_l_1615;
	case 5657ULL: goto x86_l_1619;
	case 5663ULL: goto x86_l_161f;
	case 5668ULL: goto x86_l_1624;
	case 5671ULL: goto x86_l_1627;
	case 5674ULL: goto x86_l_162a;
	case 5680ULL: goto x86_l_1630;
	case 5683ULL: goto x86_l_1633;
	case 5689ULL: goto x86_l_1639;
	case 5693ULL: goto x86_l_163d;
	case 5698ULL: goto x86_l_1642;
	case 5705ULL: goto x86_l_1649;
	case 5710ULL: goto x86_l_164e;
	case 5712ULL: goto x86_l_1650;
	case 5715ULL: goto x86_l_1653;
	case 5721ULL: goto x86_l_1659;
	case 5724ULL: goto x86_l_165c;
	case 5727ULL: goto x86_l_165f;
	case 5735ULL: goto x86_l_1667;
	case 5740ULL: goto x86_l_166c;
	case 5745ULL: goto x86_l_1671;
	case 5750ULL: goto x86_l_1676;
	case 5753ULL: goto x86_l_1679;
	case 5759ULL: goto x86_l_167f;
	case 5762ULL: goto x86_l_1682;
	case 5768ULL: goto x86_l_1688;
	case 5773ULL: goto x86_l_168d;
	case 5775ULL: goto x86_l_168f;
	case 5781ULL: goto x86_l_1695;
	case 5786ULL: goto x86_l_169a;
	case 5789ULL: goto x86_l_169d;
	case 5795ULL: goto x86_l_16a3;
	case 5798ULL: goto x86_l_16a6;
	case 5804ULL: goto x86_l_16ac;
	case 5809ULL: goto x86_l_16b1;
	case 5811ULL: goto x86_l_16b3;
	case 5817ULL: goto x86_l_16b9;
	case 5822ULL: goto x86_l_16be;
	case 5825ULL: goto x86_l_16c1;
	case 5828ULL: goto x86_l_16c4;
	case 5834ULL: goto x86_l_16ca;
	case 5841ULL: goto x86_l_16d1;
	case 5846ULL: goto x86_l_16d6;
	case 5851ULL: goto x86_l_16db;
	case 5858ULL: goto x86_l_16e2;
	case 5860ULL: goto x86_l_16e4;
	case 5863ULL: goto x86_l_16e7;
	case 5869ULL: goto x86_l_16ed;
	case 5872ULL: goto x86_l_16f0;
	case 5875ULL: goto x86_l_16f3;
	case 5880ULL: goto x86_l_16f8;
	case 5885ULL: goto x86_l_16fd;
	case 5890ULL: goto x86_l_1702;
	case 5895ULL: goto x86_l_1707;
	case 5898ULL: goto x86_l_170a;
	case 5901ULL: goto x86_l_170d;
	case 5907ULL: goto x86_l_1713;
	case 5914ULL: goto x86_l_171a;
	case 5919ULL: goto x86_l_171f;
	case 5924ULL: goto x86_l_1724;
	case 5931ULL: goto x86_l_172b;
	case 5933ULL: goto x86_l_172d;
	case 5936ULL: goto x86_l_1730;
	case 5942ULL: goto x86_l_1736;
	case 5945ULL: goto x86_l_1739;
	case 5948ULL: goto x86_l_173c;
	case 5953ULL: goto x86_l_1741;
	case 5958ULL: goto x86_l_1746;
	case 5963ULL: goto x86_l_174b;
	case 5968ULL: goto x86_l_1750;
	case 5975ULL: goto x86_l_1757;
	case 5981ULL: goto x86_l_175d;
	case 5984ULL: goto x86_l_1760;
	case 5990ULL: goto x86_l_1766;
	case 5992ULL: goto x86_l_1768;
	case 5998ULL: goto x86_l_176e;
	case 6001ULL: goto x86_l_1771;
	case 6007ULL: goto x86_l_1777;
	case 6013ULL: goto x86_l_177d;
	case 6018ULL: goto x86_l_1782;
	case 6021ULL: goto x86_l_1785;
	case 6023ULL: goto x86_l_1787;
	case 6028ULL: goto x86_l_178c;
	case 6031ULL: goto x86_l_178f;
	case 6036ULL: goto x86_l_1794;
	case 6039ULL: goto x86_l_1797;
	case 6041ULL: goto x86_l_1799;
	case 6046ULL: goto x86_l_179e;
	case 6049ULL: goto x86_l_17a1;
	case 6054ULL: goto x86_l_17a6;
	case 6057ULL: goto x86_l_17a9;
	case 6060ULL: goto x86_l_17ac;
	case 6065ULL: goto x86_l_17b1;
	case 6070ULL: goto x86_l_17b6;
	case 6073ULL: goto x86_l_17b9;
	case 6076ULL: goto x86_l_17bc;
	case 6081ULL: goto x86_l_17c1;
	case 6086ULL: goto x86_l_17c6;
	case 6091ULL: goto x86_l_17cb;
	case 6093ULL: goto x86_l_17cd;
	case 6098ULL: goto x86_l_17d2;
	case 6103ULL: goto x86_l_17d7;
	case 6105ULL: goto x86_l_17d9;
	case 6110ULL: goto x86_l_17de;
	case 6115ULL: goto x86_l_17e3;
	case 6117ULL: goto x86_l_17e5;
	case 6119ULL: goto x86_l_17e7;
	case 6124ULL: goto x86_l_17ec;
	case 6127ULL: goto x86_l_17ef;
	case 6130ULL: goto x86_l_17f2;
	case 6136ULL: goto x86_l_17f8;
	case 6142ULL: goto x86_l_17fe;
	case 6148ULL: goto x86_l_1804;
	case 6151ULL: goto x86_l_1807;
	case 6157ULL: goto x86_l_180d;
	case 6159ULL: goto x86_l_180f;
	case 6165ULL: goto x86_l_1815;
	case 6168ULL: goto x86_l_1818;
	case 6174ULL: goto x86_l_181e;
	case 6179ULL: goto x86_l_1823;
	case 6184ULL: goto x86_l_1828;
	case 6187ULL: goto x86_l_182b;
	case 6190ULL: goto x86_l_182e;
	case 6195ULL: goto x86_l_1833;
	case 6200ULL: goto x86_l_1838;
	case 6204ULL: goto x86_l_183c;
	case 6209ULL: goto x86_l_1841;
	case 6216ULL: goto x86_l_1848;
	case 6221ULL: goto x86_l_184d;
	case 6223ULL: goto x86_l_184f;
	case 6226ULL: goto x86_l_1852;
	case 6232ULL: goto x86_l_1858;
	case 6235ULL: goto x86_l_185b;
	case 6246ULL: goto x86_l_1866;
	case 6253ULL: goto x86_l_186d;
	case 6261ULL: goto x86_l_1875;
	case 6268ULL: goto x86_l_187c;
	case 6272ULL: goto x86_l_1880;
	case 6279ULL: goto x86_l_1887;
	case 6284ULL: goto x86_l_188c;
	case 6289ULL: goto x86_l_1891;
	case 6291ULL: goto x86_l_1893;
	case 6296ULL: goto x86_l_1898;
	case 6299ULL: goto x86_l_189b;
	case 6302ULL: goto x86_l_189e;
	case 6308ULL: goto x86_l_18a4;
	case 6311ULL: goto x86_l_18a7;
	case 6314ULL: goto x86_l_18aa;
	case 6319ULL: goto x86_l_18af;
	case 6324ULL: goto x86_l_18b4;
	case 6329ULL: goto x86_l_18b9;
	case 6331ULL: goto x86_l_18bb;
	case 6334ULL: goto x86_l_18be;
	case 6337ULL: goto x86_l_18c1;
	case 6340ULL: goto x86_l_18c4;
	case 6345ULL: goto x86_l_18c9;
	case 6347ULL: goto x86_l_18cb;
	case 6350ULL: goto x86_l_18ce;
	case 6355ULL: goto x86_l_18d3;
	case 6358ULL: goto x86_l_18d6;
	case 6364ULL: goto x86_l_18dc;
	case 6369ULL: goto x86_l_18e1;
	case 6372ULL: goto x86_l_18e4;
	case 6374ULL: goto x86_l_18e6;
	case 6383ULL: goto x86_l_18ef;
	case 6389ULL: goto x86_l_18f5;
	case 6393ULL: goto x86_l_18f9;
	case 6401ULL: goto x86_l_1901;
	case 6406ULL: goto x86_l_1906;
	case 6408ULL: goto x86_l_1908;
	case 6418ULL: goto x86_l_1912;
	case 6421ULL: goto x86_l_1915;
	case 6426ULL: goto x86_l_191a;
	case 6429ULL: goto x86_l_191d;
	case 6435ULL: goto x86_l_1923;
	case 6440ULL: goto x86_l_1928;
	case 6443ULL: goto x86_l_192b;
	case 6449ULL: goto x86_l_1931;
	case 6455ULL: goto x86_l_1937;
	case 6458ULL: goto x86_l_193a;
	case 6462ULL: goto x86_l_193e;
	case 6466ULL: goto x86_l_1942;
	case 6471ULL: goto x86_l_1947;
	case 6476ULL: goto x86_l_194c;
	case 6483ULL: goto x86_l_1953;
	case 6485ULL: goto x86_l_1955;
	case 6488ULL: goto x86_l_1958;
	case 6494ULL: goto x86_l_195e;
	case 6499ULL: goto x86_l_1963;
	case 6502ULL: goto x86_l_1966;
	case 6505ULL: goto x86_l_1969;
	case 6510ULL: goto x86_l_196e;
	case 6512ULL: goto x86_l_1970;
	case 6518ULL: goto x86_l_1976;
	case 6522ULL: goto x86_l_197a;
	case 6526ULL: goto x86_l_197e;
	case 6531ULL: goto x86_l_1983;
	case 6536ULL: goto x86_l_1988;
	case 6541ULL: goto x86_l_198d;
	case 6544ULL: goto x86_l_1990;
	case 6550ULL: goto x86_l_1996;
	case 6555ULL: goto x86_l_199b;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6569ULL: goto x86_l_19a9;
	case 6574ULL: goto x86_l_19ae;
	case 6577ULL: goto x86_l_19b1;
	case 6582ULL: goto x86_l_19b6;
	case 6585ULL: goto x86_l_19b9;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6601ULL: goto x86_l_19c9;
	case 6605ULL: goto x86_l_19cd;
	case 6616ULL: goto x86_l_19d8;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6633ULL: goto x86_l_19e9;
	case 6635ULL: goto x86_l_19eb;
	case 6638ULL: goto x86_l_19ee;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1380:
	/* 0x1380: je     13a2 <generic_uprobe_filter_arg+0x13a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13a2;
	}
x86_l_1382:
	/* 0x1382: lea    r13d,[rdx+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1386:
	/* 0x1386: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_138d:
	/* 0x138d: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_1392:
	/* 0x1392: mov    BYTE PTR [rdi],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1395:
	/* 0x1395: add    rbx,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1399:
	/* 0x1399: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_139d:
	/* 0x139d: cmp    rax,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_13a0:
	/* 0x13a0: jne    1331 <generic_uprobe_filter_arg+0x1331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4913ULL;
	}
x86_l_13a2:
	/* 0x13a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13a7:
	/* 0x13a7: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13ac:
	/* 0x13ac: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13b1:
	/* 0x13b1: jmp    1b3e <generic_uprobe_filter_arg+0x1b3e> */
	return 6974ULL;
x86_l_13b6:
	/* 0x13b6: mov    esi,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13bb:
	/* 0x13bb: mov    eax,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_13c0:
	/* 0x13c0: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_13c3:
	/* 0x13c3: ja     2085 <generic_uprobe_filter_arg+0x2085> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8325ULL;
	}
x86_l_13c9:
	/* 0x13c9: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_13ce:
	/* 0x13ce: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_13d1:
	/* 0x13d1: jae    2085 <generic_uprobe_filter_arg+0x2085> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8325ULL;
	}
x86_l_13d7:
	/* 0x13d7: mov    edx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13db:
	/* 0x13db: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_13dd:
	/* 0x13dd: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_13e1:
	/* 0x13e1: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_13e3:
	/* 0x13e3: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_13e6:
	/* 0x13e6: jmp    2094 <generic_uprobe_filter_arg+0x2094> */
	return 8340ULL;
x86_l_13eb:
	/* 0x13eb: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_13ee:
	/* 0x13ee: je     1a5a <generic_uprobe_filter_arg+0x1a5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6746ULL;
	}
x86_l_13f4:
	/* 0x13f4: mov    r13d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_32);
x86_l_13f7:
	/* 0x13f7: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13fc:
	/* 0x13fc: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_13ff:
	/* 0x13ff: je     19bf <generic_uprobe_filter_arg+0x19bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19bf;
	}
x86_l_1405:
	/* 0x1405: jmp    110 <generic_uprobe_filter_arg+0x110> */
	return 272ULL;
x86_l_140a:
	/* 0x140a: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_140d:
	/* 0x140d: je     1427 <generic_uprobe_filter_arg+0x1427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1427;
	}
x86_l_140f:
	/* 0x140f: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1414:
	/* 0x1414: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1417:
	/* 0x1417: jne    2bb <generic_uprobe_filter_arg+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 699ULL;
	}
x86_l_141d:
	/* 0x141d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1420:
	/* 0x1420: movzx  ebp,WORD PTR [r13+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1425:
	/* 0x1425: jmp    142f <generic_uprobe_filter_arg+0x142f> */
	goto x86_l_142f;
x86_l_1427:
	/* 0x1427: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_142a:
	/* 0x142a: movzx  ebp,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_142f:
	/* 0x142f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1431:
	/* 0x1431: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1434:
	/* 0x1434: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1437:
	/* 0x1437: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1439:
	/* 0x1439: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_143c:
	/* 0x143c: jg     14c0 <generic_uprobe_filter_arg+0x14c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_14c0;
	}
x86_l_1442:
	/* 0x1442: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_1445:
	/* 0x1445: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1448:
	/* 0x1448: jb     14f3 <generic_uprobe_filter_arg+0x14f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_14f3;
	}
x86_l_144e:
	/* 0x144e: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_1451:
	/* 0x1451: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1454:
	/* 0x1454: jb     1630 <generic_uprobe_filter_arg+0x1630> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1630;
	}
x86_l_145a:
	/* 0x145a: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_145d:
	/* 0x145d: je     1c72 <generic_uprobe_filter_arg+0x1c72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7282ULL;
	}
x86_l_1463:
	/* 0x1463: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_1468:
	/* 0x1468: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_146b:
	/* 0x146b: je     1c6d <generic_uprobe_filter_arg+0x1c6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7277ULL;
	}
x86_l_1471:
	/* 0x1471: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1476:
	/* 0x1476: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_1479:
	/* 0x1479: jne    2bb <generic_uprobe_filter_arg+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 699ULL;
	}
x86_l_147f:
	/* 0x147f: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1482:
	/* 0x1482: jne    2202 <generic_uprobe_filter_arg+0x2202> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8706ULL;
	}
x86_l_1488:
	/* 0x1488: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_148b:
	/* 0x148b: jne    220e <generic_uprobe_filter_arg+0x220e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8718ULL;
	}
x86_l_1491:
	/* 0x1491: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1493:
	/* 0x1493: jmp    2220 <generic_uprobe_filter_arg+0x2220> */
	return 8736ULL;
x86_l_1498:
	/* 0x1498: mov    rsi,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_149c:
	/* 0x149c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_149f:
	/* 0x149f: mov    r8,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14a3:
	/* 0x14a3: jmp    14b0 <generic_uprobe_filter_arg+0x14b0> */
	goto x86_l_14b0;
x86_l_14a5:
	/* 0x14a5: mov    rsi,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a9:
	/* 0x14a9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_14ac:
	/* 0x14ac: mov    r8,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14b0:
	/* 0x14b0: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_14b3:
	/* 0x14b3: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_14b7:
	/* 0x14b7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14b9:
	/* 0x14b9: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14bb:
	/* 0x14bb: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_14be:
	/* 0x14be: jle    1442 <generic_uprobe_filter_arg+0x1442> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1442;
	}
x86_l_14c0:
	/* 0x14c0: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_14c3:
	/* 0x14c3: ja     1624 <generic_uprobe_filter_arg+0x1624> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1624;
	}
x86_l_14c9:
	/* 0x14c9: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_14ce:
	/* 0x14ce: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_14d1:
	/* 0x14d1: jb     1782 <generic_uprobe_filter_arg+0x1782> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1782;
	}
x86_l_14d7:
	/* 0x14d7: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_14dc:
	/* 0x14dc: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_14df:
	/* 0x14df: jb     1794 <generic_uprobe_filter_arg+0x1794> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1794;
	}
x86_l_14e5:
	/* 0x14e5: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_14ea:
	/* 0x14ea: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_14ed:
	/* 0x14ed: jae    1624 <generic_uprobe_filter_arg+0x1624> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1624;
	}
x86_l_14f3:
	/* 0x14f3: movzx  eax,WORD PTR [rdx+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_14f7:
	/* 0x14f7: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_14fa:
	/* 0x14fa: je     1828 <generic_uprobe_filter_arg+0x1828> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1828;
	}
x86_l_1500:
	/* 0x1500: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1503:
	/* 0x1503: jne    18c9 <generic_uprobe_filter_arg+0x18c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18c9;
	}
x86_l_1509:
	/* 0x1509: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_150c:
	/* 0x150c: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1511:
	/* 0x1511: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1516:
	/* 0x1516: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_151a:
	/* 0x151a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_151f:
	/* 0x151f: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1524:
	/* 0x1524: mov    rdi,QWORD PTR [rip+0x1eeab] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_152b:
	/* 0x152b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_152d:
	/* 0x152d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1530:
	/* 0x1530: je     1d58 <generic_uprobe_filter_arg+0x1d58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7512ULL;
	}
x86_l_1536:
	/* 0x1536: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1539:
	/* 0x1539: mov    DWORD PTR [rsp+0x80],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813920ULL);
x86_l_1544:
	/* 0x1544: mov    DWORD PTR [rsp+0x84],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_154c:
	/* 0x154c: jmp    1887 <generic_uprobe_filter_arg+0x1887> */
	goto x86_l_1887;
x86_l_1551:
	/* 0x1551: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1554:
	/* 0x1554: ja     22d6 <generic_uprobe_filter_arg+0x22d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8918ULL;
	}
x86_l_155a:
	/* 0x155a: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_155f:
	/* 0x155f: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1562:
	/* 0x1562: jae    22d6 <generic_uprobe_filter_arg+0x22d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8918ULL;
	}
x86_l_1568:
	/* 0x1568: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_156c:
	/* 0x156c: jg     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_1572:
	/* 0x1572: jmp    22ec <generic_uprobe_filter_arg+0x22ec> */
	return 8940ULL;
x86_l_1577:
	/* 0x1577: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_157c:
	/* 0x157c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_157e:
	/* 0x157e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1581:
	/* 0x1581: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_1584:
	/* 0x1584: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_1589:
	/* 0x1589: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_158d:
	/* 0x158d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1592:
	/* 0x1592: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1597:
	/* 0x1597: mov    rdi,QWORD PTR [rip+0x1eeab] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_159e:
	/* 0x159e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a0:
	/* 0x15a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15a3:
	/* 0x15a3: je     21a1 <generic_uprobe_filter_arg+0x21a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8609ULL;
	}
x86_l_15a9:
	/* 0x15a9: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_15ab:
	/* 0x15ab: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15b0:
	/* 0x15b0: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_15b3:
	/* 0x15b3: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15b8:
	/* 0x15b8: je     15ff <generic_uprobe_filter_arg+0x15ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ff;
	}
x86_l_15ba:
	/* 0x15ba: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15bf:
	/* 0x15bf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15c1:
	/* 0x15c1: jmp    15ce <generic_uprobe_filter_arg+0x15ce> */
	goto x86_l_15ce;
x86_l_15c3:
	/* 0x15c3: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15c6:
	/* 0x15c6: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15c9:
	/* 0x15c9: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_15cc:
	/* 0x15cc: je     15ff <generic_uprobe_filter_arg+0x15ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ff;
	}
x86_l_15ce:
	/* 0x15ce: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15d0:
	/* 0x15d0: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_15d4:
	/* 0x15d4: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_15d7:
	/* 0x15d7: jae    15c3 <generic_uprobe_filter_arg+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_15c3;
	}
x86_l_15d9:
	/* 0x15d9: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_15dd:
	/* 0x15dd: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_15e0:
	/* 0x15e0: je     15f7 <generic_uprobe_filter_arg+0x15f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15f7;
	}
x86_l_15e2:
	/* 0x15e2: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_15e6:
	/* 0x15e6: ja     15c3 <generic_uprobe_filter_arg+0x15c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15c3;
	}
x86_l_15e8:
	/* 0x15e8: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_15ec:
	/* 0x15ec: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_15f0:
	/* 0x15f0: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_15f3:
	/* 0x15f3: je     15d0 <generic_uprobe_filter_arg+0x15d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15d0;
	}
x86_l_15f5:
	/* 0x15f5: jmp    15c3 <generic_uprobe_filter_arg+0x15c3> */
	goto x86_l_15c3;
x86_l_15f7:
	/* 0x15f7: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_15f9:
	/* 0x15f9: jns    23e3 <generic_uprobe_filter_arg+0x23e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9187ULL;
	}
x86_l_15ff:
	/* 0x15ff: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1603:
	/* 0x1603: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1608:
	/* 0x1608: jae    2195 <generic_uprobe_filter_arg+0x2195> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8597ULL;
	}
x86_l_160e:
	/* 0x160e: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1612:
	/* 0x1612: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1615:
	/* 0x1615: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_1619:
	/* 0x1619: jne    1581 <generic_uprobe_filter_arg+0x1581> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1581;
	}
x86_l_161f:
	/* 0x161f: jmp    2195 <generic_uprobe_filter_arg+0x2195> */
	return 8597ULL;
x86_l_1624:
	/* 0x1624: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_1627:
	/* 0x1627: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_162a:
	/* 0x162a: jae    2bb <generic_uprobe_filter_arg+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 699ULL;
	}
x86_l_1630:
	/* 0x1630: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_1633:
	/* 0x1633: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1639:
	/* 0x1639: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_163d:
	/* 0x163d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1642:
	/* 0x1642: mov    rdi,QWORD PTR [rip+0x1eeb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1649:
	/* 0x1649: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_164e:
	/* 0x164e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1650:
	/* 0x1650: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1653:
	/* 0x1653: je     2ac <generic_uprobe_filter_arg+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 684ULL;
	}
x86_l_1659:
	/* 0x1659: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_165c:
	/* 0x165c: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_165f:
	/* 0x165f: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1667:
	/* 0x1667: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_166c:
	/* 0x166c: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1671:
	/* 0x1671: jmp    1cb3 <generic_uprobe_filter_arg+0x1cb3> */
	return 7347ULL;
x86_l_1676:
	/* 0x1676: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1679:
	/* 0x1679: je     1f9c <generic_uprobe_filter_arg+0x1f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8092ULL;
	}
x86_l_167f:
	/* 0x167f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1682:
	/* 0x1682: jne    1fa9 <generic_uprobe_filter_arg+0x1fa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8105ULL;
	}
x86_l_1688:
	/* 0x1688: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_168d:
	/* 0x168d: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_168f:
	/* 0x168f: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_1695:
	/* 0x1695: jmp    1fa9 <generic_uprobe_filter_arg+0x1fa9> */
	return 8105ULL;
x86_l_169a:
	/* 0x169a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_169d:
	/* 0x169d: je     1fe3 <generic_uprobe_filter_arg+0x1fe3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8163ULL;
	}
x86_l_16a3:
	/* 0x16a3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16a6:
	/* 0x16a6: jne    1ff0 <generic_uprobe_filter_arg+0x1ff0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8176ULL;
	}
x86_l_16ac:
	/* 0x16ac: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16b1:
	/* 0x16b1: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_16b3:
	/* 0x16b3: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_16b9:
	/* 0x16b9: jmp    1ff0 <generic_uprobe_filter_arg+0x1ff0> */
	return 8176ULL;
x86_l_16be:
	/* 0x16be: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_16c1:
	/* 0x16c1: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_16c4:
	/* 0x16c4: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_16ca:
	/* 0x16ca: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_16d1:
	/* 0x16d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16d6:
	/* 0x16d6: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16db:
	/* 0x16db: mov    rdi,QWORD PTR [rip+0x1eeb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_16e2:
	/* 0x16e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e4:
	/* 0x16e4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16e7:
	/* 0x16e7: je     2ac <generic_uprobe_filter_arg+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 684ULL;
	}
x86_l_16ed:
	/* 0x16ed: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_16f0:
	/* 0x16f0: movzx  eax,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_16f3:
	/* 0x16f3: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16f8:
	/* 0x16f8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16fd:
	/* 0x16fd: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1702:
	/* 0x1702: jmp    1cb3 <generic_uprobe_filter_arg+0x1cb3> */
	return 7347ULL;
x86_l_1707:
	/* 0x1707: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_170a:
	/* 0x170a: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_170d:
	/* 0x170d: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1713:
	/* 0x1713: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_171a:
	/* 0x171a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_171f:
	/* 0x171f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1724:
	/* 0x1724: mov    rdi,QWORD PTR [rip+0x1eeb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_172b:
	/* 0x172b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_172d:
	/* 0x172d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1730:
	/* 0x1730: je     2ac <generic_uprobe_filter_arg+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 684ULL;
	}
x86_l_1736:
	/* 0x1736: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1739:
	/* 0x1739: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_173c:
	/* 0x173c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1741:
	/* 0x1741: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1746:
	/* 0x1746: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_174b:
	/* 0x174b: jmp    1cb3 <generic_uprobe_filter_arg+0x1cb3> */
	return 7347ULL;
x86_l_1750:
	/* 0x1750: lea    eax,[r10-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_1757:
	/* 0x1757: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_175d:
	/* 0x175d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1760:
	/* 0x1760: jg     1f62 <generic_uprobe_filter_arg+0x1f62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8034ULL;
	}
x86_l_1766:
	/* 0x1766: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1768:
	/* 0x1768: je     2624 <generic_uprobe_filter_arg+0x2624> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9764ULL;
	}
x86_l_176e:
	/* 0x176e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1771:
	/* 0x1771: jne    261c <generic_uprobe_filter_arg+0x261c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9756ULL;
	}
x86_l_1777:
	/* 0x1777: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_177d:
	/* 0x177d: jmp    2632 <generic_uprobe_filter_arg+0x2632> */
	return 9778ULL;
x86_l_1782:
	/* 0x1782: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1785:
	/* 0x1785: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1787:
	/* 0x1787: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_178c:
	/* 0x178c: setb   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_B);
x86_l_178f:
	/* 0x178f: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_1794:
	/* 0x1794: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1797:
	/* 0x1797: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1799:
	/* 0x1799: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_179e:
	/* 0x179e: setae  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_AE);
x86_l_17a1:
	/* 0x17a1: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_17a6:
	/* 0x17a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17a9:
	/* 0x17a9: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_17ac:
	/* 0x17ac: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17b1:
	/* 0x17b1: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17b6:
	/* 0x17b6: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_17b9:
	/* 0x17b9: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_17bc:
	/* 0x17bc: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_17c1:
	/* 0x17c1: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_17c6:
	/* 0x17c6: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_17cb:
	/* 0x17cb: jb     17f8 <generic_uprobe_filter_arg+0x17f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_17f8;
	}
x86_l_17cd:
	/* 0x17cd: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_17d2:
	/* 0x17d2: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_17d7:
	/* 0x17d7: jb     17f8 <generic_uprobe_filter_arg+0x17f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_17f8;
	}
x86_l_17d9:
	/* 0x17d9: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_17de:
	/* 0x17de: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_17e3:
	/* 0x17e3: jb     17f8 <generic_uprobe_filter_arg+0x17f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_17f8;
	}
x86_l_17e5:
	/* 0x17e5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17e7:
	/* 0x17e7: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_17ec:
	/* 0x17ec: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_17ef:
	/* 0x17ef: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_17f2:
	/* 0x17f2: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_17f8:
	/* 0x17f8: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_17fe:
	/* 0x17fe: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_1804:
	/* 0x1804: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1807:
	/* 0x1807: jg     1e9b <generic_uprobe_filter_arg+0x1e9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7835ULL;
	}
x86_l_180d:
	/* 0x180d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_180f:
	/* 0x180f: je     23f9 <generic_uprobe_filter_arg+0x23f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9209ULL;
	}
x86_l_1815:
	/* 0x1815: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1818:
	/* 0x1818: jne    23f2 <generic_uprobe_filter_arg+0x23f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9202ULL;
	}
x86_l_181e:
	/* 0x181e: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1823:
	/* 0x1823: jmp    2405 <generic_uprobe_filter_arg+0x2405> */
	return 9221ULL;
x86_l_1828:
	/* 0x1828: mov    rbx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R8, X86_WIDTH_64);
x86_l_182b:
	/* 0x182b: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_182e:
	/* 0x182e: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1833:
	/* 0x1833: mov    eax,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1838:
	/* 0x1838: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_183c:
	/* 0x183c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1841:
	/* 0x1841: mov    rdi,QWORD PTR [rip+0x1eeb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_1848:
	/* 0x1848: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_184d:
	/* 0x184d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184f:
	/* 0x184f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1852:
	/* 0x1852: je     1d58 <generic_uprobe_filter_arg+0x1d58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7512ULL;
	}
x86_l_1858:
	/* 0x1858: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_185b:
	/* 0x185b: mov    DWORD PTR [rsp+0x80],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755814016ULL);
x86_l_1866:
	/* 0x1866: mov    DWORD PTR [rsp+0x84],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_186d:
	/* 0x186d: mov    DWORD PTR [rsp+0x88],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1875:
	/* 0x1875: mov    DWORD PTR [rsp+0x8c],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_187c:
	/* 0x187c: shr    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1880:
	/* 0x1880: mov    DWORD PTR [rsp+0x90],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1887:
	/* 0x1887: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_188c:
	/* 0x188c: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1891:
	/* 0x1891: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1893:
	/* 0x1893: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1898:
	/* 0x1898: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_189b:
	/* 0x189b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_189e:
	/* 0x189e: jb     1f7f <generic_uprobe_filter_arg+0x1f7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8063ULL;
	}
x86_l_18a4:
	/* 0x18a4: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_18a7:
	/* 0x18a7: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_18aa:
	/* 0x18aa: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18af:
	/* 0x18af: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18b4:
	/* 0x18b4: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18b9:
	/* 0x18b9: ja     18c9 <generic_uprobe_filter_arg+0x18c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18c9;
	}
x86_l_18bb:
	/* 0x18bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18be:
	/* 0x18be: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_18c1:
	/* 0x18c1: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_18c4:
	/* 0x18c4: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_18c9:
	/* 0x18c9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18cb:
	/* 0x18cb: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_18ce:
	/* 0x18ce: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_18d3:
	/* 0x18d3: cmp    eax,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_18d6:
	/* 0x18d6: jne    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_18dc:
	/* 0x18dc: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18e1:
	/* 0x18e1: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_18e4:
	/* 0x18e4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_18e6:
	/* 0x18e6: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_18ef:
	/* 0x18ef: jne    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_18f5:
	/* 0x18f5: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18f9:
	/* 0x18f9: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_1901:
	/* 0x1901: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1906:
	/* 0x1906: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1908:
	/* 0x1908: andn   rax,rcx,QWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ANDN_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 144ULL);
x86_l_1912:
	/* 0x1912: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_1915:
	/* 0x1915: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_191a:
	/* 0x191a: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_191d:
	/* 0x191d: je     20f6 <generic_uprobe_filter_arg+0x20f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8438ULL;
	}
x86_l_1923:
	/* 0x1923: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1928:
	/* 0x1928: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_192b:
	/* 0x192b: jne    3746 <generic_uprobe_filter_arg+0x3746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14150ULL;
	}
x86_l_1931:
	/* 0x1931: mov    r13d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16ULL);
x86_l_1937:
	/* 0x1937: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_193a:
	/* 0x193a: mov    eax,DWORD PTR [r12+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_193e:
	/* 0x193e: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1942:
	/* 0x1942: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1947:
	/* 0x1947: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_194c:
	/* 0x194c: mov    rdi,QWORD PTR [rip+0x1eeb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1953:
	/* 0x1953: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1955:
	/* 0x1955: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1958:
	/* 0x1958: je     2d8d <generic_uprobe_filter_arg+0x2d8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11661ULL;
	}
x86_l_195e:
	/* 0x195e: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1963:
	/* 0x1963: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1966:
	/* 0x1966: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1969:
	/* 0x1969: call   0 <generic_uprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 6510ULL);
	__x86_sim_call_depth++;
	return 14302ULL;
x86_l_196e:
	/* 0x196e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1970:
	/* 0x1970: jns    2d91 <generic_uprobe_filter_arg+0x2d91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11665ULL;
	}
x86_l_1976:
	/* 0x1976: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_197a:
	/* 0x197a: lea    eax,[r13-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_197e:
	/* 0x197e: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1983:
	/* 0x1983: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1988:
	/* 0x1988: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_198d:
	/* 0x198d: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_1990:
	/* 0x1990: jae    2ecd <generic_uprobe_filter_arg+0x2ecd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11981ULL;
	}
x86_l_1996:
	/* 0x1996: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_199b:
	/* 0x199b: cmp    r13,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 416ULL);
x86_l_19a2:
	/* 0x19a2: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19a7:
	/* 0x19a7: jne    1937 <generic_uprobe_filter_arg+0x1937> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1937;
	}
x86_l_19a9:
	/* 0x19a9: jmp    3746 <generic_uprobe_filter_arg+0x3746> */
	return 14150ULL;
x86_l_19ae:
	/* 0x19ae: mov    r13d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_32);
x86_l_19b1:
	/* 0x19b1: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19b6:
	/* 0x19b6: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_19b9:
	/* 0x19b9: jne    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_19bf:
	/* 0x19bf: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19c4:
	/* 0x19c4: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19c9:
	/* 0x19c9: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19cd:
	/* 0x19cd: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_19d8:
	/* 0x19d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19dd:
	/* 0x19dd: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19e2:
	/* 0x19e2: mov    rdi,QWORD PTR [rip+0x1eeb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_19e9:
	/* 0x19e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19eb:
	/* 0x19eb: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_19ee:
	/* 0x19ee: je     1d1f <generic_uprobe_filter_arg+0x1d1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7455ULL;
	}
	return 6644ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6652ULL: goto x86_l_19fc;
	case 6658ULL: goto x86_l_1a02;
	case 6661ULL: goto x86_l_1a05;
	case 6666ULL: goto x86_l_1a0a;
	case 6671ULL: goto x86_l_1a0f;
	case 6678ULL: goto x86_l_1a16;
	case 6680ULL: goto x86_l_1a18;
	case 6683ULL: goto x86_l_1a1b;
	case 6689ULL: goto x86_l_1a21;
	case 6691ULL: goto x86_l_1a23;
	case 6694ULL: goto x86_l_1a26;
	case 6696ULL: goto x86_l_1a28;
	case 6699ULL: goto x86_l_1a2b;
	case 6703ULL: goto x86_l_1a2f;
	case 6706ULL: goto x86_l_1a32;
	case 6711ULL: goto x86_l_1a37;
	case 6716ULL: goto x86_l_1a3c;
	case 6718ULL: goto x86_l_1a3e;
	case 6720ULL: goto x86_l_1a40;
	case 6725ULL: goto x86_l_1a45;
	case 6728ULL: goto x86_l_1a48;
	case 6731ULL: goto x86_l_1a4b;
	case 6733ULL: goto x86_l_1a4d;
	case 6735ULL: goto x86_l_1a4f;
	case 6738ULL: goto x86_l_1a52;
	case 6741ULL: goto x86_l_1a55;
	case 6746ULL: goto x86_l_1a5a;
	case 6749ULL: goto x86_l_1a5d;
	case 6752ULL: goto x86_l_1a60;
	case 6755ULL: goto x86_l_1a63;
	case 6761ULL: goto x86_l_1a69;
	case 6768ULL: goto x86_l_1a70;
	case 6773ULL: goto x86_l_1a75;
	case 6778ULL: goto x86_l_1a7a;
	case 6785ULL: goto x86_l_1a81;
	case 6787ULL: goto x86_l_1a83;
	case 6790ULL: goto x86_l_1a86;
	case 6796ULL: goto x86_l_1a8c;
	case 6799ULL: goto x86_l_1a8f;
	case 6804ULL: goto x86_l_1a94;
	case 6809ULL: goto x86_l_1a99;
	case 6814ULL: goto x86_l_1a9e;
	case 6819ULL: goto x86_l_1aa3;
	case 6824ULL: goto x86_l_1aa8;
	case 6829ULL: goto x86_l_1aad;
	case 6833ULL: goto x86_l_1ab1;
	case 6844ULL: goto x86_l_1abc;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6861ULL: goto x86_l_1acd;
	case 6863ULL: goto x86_l_1acf;
	case 6865ULL: goto x86_l_1ad1;
	case 6871ULL: goto x86_l_1ad7;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6882ULL: goto x86_l_1ae2;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6898ULL: goto x86_l_1af2;
	case 6905ULL: goto x86_l_1af9;
	case 6907ULL: goto x86_l_1afb;
	case 6910ULL: goto x86_l_1afe;
	case 6916ULL: goto x86_l_1b04;
	case 6922ULL: goto x86_l_1b0a;
	case 6927ULL: goto x86_l_1b0f;
	case 6930ULL: goto x86_l_1b12;
	case 6937ULL: goto x86_l_1b19;
	case 6939ULL: goto x86_l_1b1b;
	case 6942ULL: goto x86_l_1b1e;
	case 6946ULL: goto x86_l_1b22;
	case 6949ULL: goto x86_l_1b25;
	case 6954ULL: goto x86_l_1b2a;
	case 6959ULL: goto x86_l_1b2f;
	case 6961ULL: goto x86_l_1b31;
	case 6963ULL: goto x86_l_1b33;
	case 6968ULL: goto x86_l_1b38;
	case 6971ULL: goto x86_l_1b3b;
	case 6974ULL: goto x86_l_1b3e;
	case 6976ULL: goto x86_l_1b40;
	case 6978ULL: goto x86_l_1b42;
	case 6981ULL: goto x86_l_1b45;
	case 6984ULL: goto x86_l_1b48;
	case 6989ULL: goto x86_l_1b4d;
	case 7000ULL: goto x86_l_1b58;
	case 7006ULL: goto x86_l_1b5e;
	case 7012ULL: goto x86_l_1b64;
	case 7015ULL: goto x86_l_1b67;
	case 7020ULL: goto x86_l_1b6c;
	case 7025ULL: goto x86_l_1b71;
	case 7030ULL: goto x86_l_1b76;
	case 7036ULL: goto x86_l_1b7c;
	case 7040ULL: goto x86_l_1b80;
	case 7046ULL: goto x86_l_1b86;
	case 7049ULL: goto x86_l_1b89;
	case 7052ULL: goto x86_l_1b8c;
	case 7055ULL: goto x86_l_1b8f;
	case 7057ULL: goto x86_l_1b91;
	case 7060ULL: goto x86_l_1b94;
	case 7062ULL: goto x86_l_1b96;
	case 7064ULL: goto x86_l_1b98;
	case 7066ULL: goto x86_l_1b9a;
	case 7068ULL: goto x86_l_1b9c;
	case 7070ULL: goto x86_l_1b9e;
	case 7073ULL: goto x86_l_1ba1;
	case 7075ULL: goto x86_l_1ba3;
	case 7077ULL: goto x86_l_1ba5;
	case 7079ULL: goto x86_l_1ba7;
	case 7082ULL: goto x86_l_1baa;
	case 7085ULL: goto x86_l_1bad;
	case 7089ULL: goto x86_l_1bb1;
	case 7095ULL: goto x86_l_1bb7;
	case 7097ULL: goto x86_l_1bb9;
	case 7100ULL: goto x86_l_1bbc;
	case 7106ULL: goto x86_l_1bc2;
	case 7109ULL: goto x86_l_1bc5;
	case 7111ULL: goto x86_l_1bc7;
	case 7116ULL: goto x86_l_1bcc;
	case 7120ULL: goto x86_l_1bd0;
	case 7123ULL: goto x86_l_1bd3;
	case 7125ULL: goto x86_l_1bd5;
	case 7128ULL: goto x86_l_1bd8;
	case 7134ULL: goto x86_l_1bde;
	case 7139ULL: goto x86_l_1be3;
	case 7142ULL: goto x86_l_1be6;
	case 7148ULL: goto x86_l_1bec;
	case 7153ULL: goto x86_l_1bf1;
	case 7158ULL: goto x86_l_1bf6;
	case 7161ULL: goto x86_l_1bf9;
	case 7163ULL: goto x86_l_1bfb;
	case 7166ULL: goto x86_l_1bfe;
	case 7172ULL: goto x86_l_1c04;
	case 7175ULL: goto x86_l_1c07;
	case 7180ULL: goto x86_l_1c0c;
	case 7186ULL: goto x86_l_1c12;
	case 7189ULL: goto x86_l_1c15;
	case 7195ULL: goto x86_l_1c1b;
	case 7200ULL: goto x86_l_1c20;
	case 7204ULL: goto x86_l_1c24;
	case 7207ULL: goto x86_l_1c27;
	case 7211ULL: goto x86_l_1c2b;
	case 7214ULL: goto x86_l_1c2e;
	case 7217ULL: goto x86_l_1c31;
	case 7220ULL: goto x86_l_1c34;
	case 7225ULL: goto x86_l_1c39;
	case 7228ULL: goto x86_l_1c3c;
	case 7234ULL: goto x86_l_1c42;
	case 7239ULL: goto x86_l_1c47;
	case 7244ULL: goto x86_l_1c4c;
	case 7247ULL: goto x86_l_1c4f;
	case 7249ULL: goto x86_l_1c51;
	case 7252ULL: goto x86_l_1c54;
	case 7258ULL: goto x86_l_1c5a;
	case 7261ULL: goto x86_l_1c5d;
	case 7265ULL: goto x86_l_1c61;
	case 7268ULL: goto x86_l_1c64;
	case 7272ULL: goto x86_l_1c68;
	case 7277ULL: goto x86_l_1c6d;
	case 7282ULL: goto x86_l_1c72;
	case 7285ULL: goto x86_l_1c75;
	case 7291ULL: goto x86_l_1c7b;
	case 7295ULL: goto x86_l_1c7f;
	case 7300ULL: goto x86_l_1c84;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7314ULL: goto x86_l_1c92;
	case 7317ULL: goto x86_l_1c95;
	case 7323ULL: goto x86_l_1c9b;
	case 7326ULL: goto x86_l_1c9e;
	case 7329ULL: goto x86_l_1ca1;
	case 7337ULL: goto x86_l_1ca9;
	case 7342ULL: goto x86_l_1cae;
	case 7347ULL: goto x86_l_1cb3;
	case 7349ULL: goto x86_l_1cb5;
	case 7354ULL: goto x86_l_1cba;
	case 7356ULL: goto x86_l_1cbc;
	case 7359ULL: goto x86_l_1cbf;
	case 7365ULL: goto x86_l_1cc5;
	case 7370ULL: goto x86_l_1cca;
	case 7373ULL: goto x86_l_1ccd;
	case 7378ULL: goto x86_l_1cd2;
	case 7383ULL: goto x86_l_1cd7;
	case 7386ULL: goto x86_l_1cda;
	case 7388ULL: goto x86_l_1cdc;
	case 7391ULL: goto x86_l_1cdf;
	case 7394ULL: goto x86_l_1ce2;
	case 7396ULL: goto x86_l_1ce4;
	case 7401ULL: goto x86_l_1ce9;
	case 7404ULL: goto x86_l_1cec;
	case 7406ULL: goto x86_l_1cee;
	case 7409ULL: goto x86_l_1cf1;
	case 7412ULL: goto x86_l_1cf4;
	case 7415ULL: goto x86_l_1cf7;
	case 7420ULL: goto x86_l_1cfc;
	case 7422ULL: goto x86_l_1cfe;
	case 7427ULL: goto x86_l_1d03;
	case 7432ULL: goto x86_l_1d08;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7444ULL: goto x86_l_1d14;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7457ULL: goto x86_l_1d21;
	case 7462ULL: goto x86_l_1d26;
	case 7466ULL: goto x86_l_1d2a;
	case 7472ULL: goto x86_l_1d30;
	case 7482ULL: goto x86_l_1d3a;
	case 7486ULL: goto x86_l_1d3e;
	case 7491ULL: goto x86_l_1d43;
	case 7496ULL: goto x86_l_1d48;
	case 7501ULL: goto x86_l_1d4d;
	case 7507ULL: goto x86_l_1d53;
	case 7512ULL: goto x86_l_1d58;
	case 7517ULL: goto x86_l_1d5d;
	case 7520ULL: goto x86_l_1d60;
	case 7523ULL: goto x86_l_1d63;
	case 7528ULL: goto x86_l_1d68;
	case 7533ULL: goto x86_l_1d6d;
	case 7538ULL: goto x86_l_1d72;
	case 7540ULL: goto x86_l_1d74;
	case 7545ULL: goto x86_l_1d79;
	case 7550ULL: goto x86_l_1d7e;
	case 7552ULL: goto x86_l_1d80;
	case 7557ULL: goto x86_l_1d85;
	case 7562ULL: goto x86_l_1d8a;
	case 7564ULL: goto x86_l_1d8c;
	case 7566ULL: goto x86_l_1d8e;
	case 7571ULL: goto x86_l_1d93;
	case 7574ULL: goto x86_l_1d96;
	case 7577ULL: goto x86_l_1d99;
	case 7583ULL: goto x86_l_1d9f;
	case 7589ULL: goto x86_l_1da5;
	case 7595ULL: goto x86_l_1dab;
	case 7598ULL: goto x86_l_1dae;
	case 7604ULL: goto x86_l_1db4;
	case 7606ULL: goto x86_l_1db6;
	case 7612ULL: goto x86_l_1dbc;
	case 7615ULL: goto x86_l_1dbf;
	case 7621ULL: goto x86_l_1dc5;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7635ULL: goto x86_l_1dd3;
	case 7641ULL: goto x86_l_1dd9;
	case 7643ULL: goto x86_l_1ddb;
	case 7647ULL: goto x86_l_1ddf;
	case 7653ULL: goto x86_l_1de5;
	case 7658ULL: goto x86_l_1dea;
	case 7661ULL: goto x86_l_1ded;
	case 7667ULL: goto x86_l_1df3;
	case 7672ULL: goto x86_l_1df8;
	case 7675ULL: goto x86_l_1dfb;
	case 7677ULL: goto x86_l_1dfd;
	case 7680ULL: goto x86_l_1e00;
	case 7683ULL: goto x86_l_1e03;
	case 7685ULL: goto x86_l_1e05;
	case 7689ULL: goto x86_l_1e09;
	case 7694ULL: goto x86_l_1e0e;
	case 7700ULL: goto x86_l_1e14;
	case 7705ULL: goto x86_l_1e19;
	case 7708ULL: goto x86_l_1e1c;
	case 7714ULL: goto x86_l_1e22;
	case 7717ULL: goto x86_l_1e25;
	case 7723ULL: goto x86_l_1e2b;
	case 7726ULL: goto x86_l_1e2e;
	case 7728ULL: goto x86_l_1e30;
	case 7731ULL: goto x86_l_1e33;
	case 7737ULL: goto x86_l_1e39;
	case 7741ULL: goto x86_l_1e3d;
	case 7747ULL: goto x86_l_1e43;
	case 7752ULL: goto x86_l_1e48;
	case 7755ULL: goto x86_l_1e4b;
	case 7760ULL: goto x86_l_1e50;
	case 7766ULL: goto x86_l_1e56;
	case 7770ULL: goto x86_l_1e5a;
	case 7776ULL: goto x86_l_1e60;
	case 7781ULL: goto x86_l_1e65;
	case 7784ULL: goto x86_l_1e68;
	case 7790ULL: goto x86_l_1e6e;
	case 7795ULL: goto x86_l_1e73;
	case 7797ULL: goto x86_l_1e75;
	case 7803ULL: goto x86_l_1e7b;
	case 7808ULL: goto x86_l_1e80;
	case 7811ULL: goto x86_l_1e83;
	case 7817ULL: goto x86_l_1e89;
	case 7822ULL: goto x86_l_1e8e;
	case 7824ULL: goto x86_l_1e90;
	case 7830ULL: goto x86_l_1e96;
	case 7835ULL: goto x86_l_1e9b;
	case 7838ULL: goto x86_l_1e9e;
	case 7844ULL: goto x86_l_1ea4;
	case 7847ULL: goto x86_l_1ea7;
	case 7853ULL: goto x86_l_1ead;
	case 7858ULL: goto x86_l_1eb2;
	case 7863ULL: goto x86_l_1eb7;
	case 7866ULL: goto x86_l_1eba;
	case 7868ULL: goto x86_l_1ebc;
	case 7871ULL: goto x86_l_1ebf;
	case 7877ULL: goto x86_l_1ec5;
	case 7881ULL: goto x86_l_1ec9;
	case 7887ULL: goto x86_l_1ecf;
	case 7892ULL: goto x86_l_1ed4;
	case 7897ULL: goto x86_l_1ed9;
	case 7902ULL: goto x86_l_1ede;
	case 7904ULL: goto x86_l_1ee0;
	case 7909ULL: goto x86_l_1ee5;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7931ULL: goto x86_l_1efb;
	case 7934ULL: goto x86_l_1efe;
	case 7937ULL: goto x86_l_1f01;
	case 7943ULL: goto x86_l_1f07;
	case 7948ULL: goto x86_l_1f0c;
	case 7952ULL: goto x86_l_1f10;
	case 7957ULL: goto x86_l_1f15;
	case 7961ULL: goto x86_l_1f19;
	case 7964ULL: goto x86_l_1f1c;
	case 7967ULL: goto x86_l_1f1f;
	case 7970ULL: goto x86_l_1f22;
	case 7976ULL: goto x86_l_1f28;
	case 7981ULL: goto x86_l_1f2d;
	case 7985ULL: goto x86_l_1f31;
	case 7990ULL: goto x86_l_1f36;
	case 7994ULL: goto x86_l_1f3a;
	case 7997ULL: goto x86_l_1f3d;
	case 8000ULL: goto x86_l_1f40;
	case 8003ULL: goto x86_l_1f43;
	case 8009ULL: goto x86_l_1f49;
	case 8014ULL: goto x86_l_1f4e;
	case 8017ULL: goto x86_l_1f51;
	case 8022ULL: goto x86_l_1f56;
	case 8025ULL: goto x86_l_1f59;
	case 8027ULL: goto x86_l_1f5b;
	case 8029ULL: goto x86_l_1f5d;
	case 8034ULL: goto x86_l_1f62;
	case 8037ULL: goto x86_l_1f65;
	case 8043ULL: goto x86_l_1f6b;
	case 8046ULL: goto x86_l_1f6e;
	case 8052ULL: goto x86_l_1f74;
	case 8058ULL: goto x86_l_1f7a;
	case 8063ULL: goto x86_l_1f7f;
	case 8066ULL: goto x86_l_1f82;
	case 8069ULL: goto x86_l_1f85;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8084ULL: goto x86_l_1f94;
	case 8087ULL: goto x86_l_1f97;
	case 8092ULL: goto x86_l_1f9c;
	case 8097ULL: goto x86_l_1fa1;
	case 8099ULL: goto x86_l_1fa3;
	case 8105ULL: goto x86_l_1fa9;
	case 8110ULL: goto x86_l_1fae;
	case 8113ULL: goto x86_l_1fb1;
	case 8119ULL: goto x86_l_1fb7;
	case 8124ULL: goto x86_l_1fbc;
	case 8127ULL: goto x86_l_1fbf;
	case 8133ULL: goto x86_l_1fc5;
	case 8136ULL: goto x86_l_1fc8;
	case 8139ULL: goto x86_l_1fcb;
	case 8145ULL: goto x86_l_1fd1;
	case 8150ULL: goto x86_l_1fd6;
	case 8152ULL: goto x86_l_1fd8;
	case 8158ULL: goto x86_l_1fde;
	case 8163ULL: goto x86_l_1fe3;
	case 8168ULL: goto x86_l_1fe8;
	case 8170ULL: goto x86_l_1fea;
	case 8176ULL: goto x86_l_1ff0;
	case 8181ULL: goto x86_l_1ff5;
	case 8184ULL: goto x86_l_1ff8;
	case 8190ULL: goto x86_l_1ffe;
	case 8195ULL: goto x86_l_2003;
	case 8198ULL: goto x86_l_2006;
	case 8204ULL: goto x86_l_200c;
	case 8207ULL: goto x86_l_200f;
	case 8210ULL: goto x86_l_2012;
	case 8216ULL: goto x86_l_2018;
	case 8221ULL: goto x86_l_201d;
	case 8223ULL: goto x86_l_201f;
	case 8229ULL: goto x86_l_2025;
	case 8234ULL: goto x86_l_202a;
	case 8238ULL: goto x86_l_202e;
	case 8240ULL: goto x86_l_2030;
	default: return 0xffffffffffffffffULL;
	}
x86_l_19f4:
	/* 0x19f4: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_19f9:
	/* 0x19f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19fc:
	/* 0x19fc: je     1d21 <generic_uprobe_filter_arg+0x1d21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d21;
	}
x86_l_1a02:
	/* 0x1a02: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1a05:
	/* 0x1a05: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a0a:
	/* 0x1a0a: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a0f:
	/* 0x1a0f: mov    rdi,QWORD PTR [rip+0x1eeb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1a16:
	/* 0x1a16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a18:
	/* 0x1a18: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a1b:
	/* 0x1a1b: je     1d1f <generic_uprobe_filter_arg+0x1d1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d1f;
	}
x86_l_1a21:
	/* 0x1a21: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1a23:
	/* 0x1a23: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1a26:
	/* 0x1a26: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a28:
	/* 0x1a28: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1a2b:
	/* 0x1a2b: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a2f:
	/* 0x1a2f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1a32:
	/* 0x1a32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a37:
	/* 0x1a37: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a3c:
	/* 0x1a3c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1a3e:
	/* 0x1a3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a40:
	/* 0x1a40: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a45:
	/* 0x1a45: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1a48:
	/* 0x1a48: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1a4b:
	/* 0x1a4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4d:
	/* 0x1a4d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a4f:
	/* 0x1a4f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a52:
	/* 0x1a52: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_1a55:
	/* 0x1a55: jmp    1d21 <generic_uprobe_filter_arg+0x1d21> */
	goto x86_l_1d21;
x86_l_1a5a:
	/* 0x1a5a: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1a5d:
	/* 0x1a5d: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_1a60:
	/* 0x1a60: movzx  ebx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a63:
	/* 0x1a63: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1a69:
	/* 0x1a69: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a70:
	/* 0x1a70: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a75:
	/* 0x1a75: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a7a:
	/* 0x1a7a: mov    rdi,QWORD PTR [rip+0x1eeb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1a81:
	/* 0x1a81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a83:
	/* 0x1a83: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a86:
	/* 0x1a86: je     2ac <generic_uprobe_filter_arg+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 684ULL;
	}
x86_l_1a8c:
	/* 0x1a8c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1a8f:
	/* 0x1a8f: mov    QWORD PTR [rsp+0x40],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a94:
	/* 0x1a94: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a99:
	/* 0x1a99: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a9e:
	/* 0x1a9e: jmp    1cb3 <generic_uprobe_filter_arg+0x1cb3> */
	goto x86_l_1cb3;
x86_l_1aa3:
	/* 0x1aa3: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aa8:
	/* 0x1aa8: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1aad:
	/* 0x1aad: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ab1:
	/* 0x1ab1: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1abc:
	/* 0x1abc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ac1:
	/* 0x1ac1: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ac6:
	/* 0x1ac6: mov    rdi,QWORD PTR [rip+0x1eeb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1acd:
	/* 0x1acd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1acf:
	/* 0x1acf: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1ad1:
	/* 0x1ad1: je     3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14133ULL;
	}
x86_l_1ad7:
	/* 0x1ad7: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1ada:
	/* 0x1ada: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1adf:
	/* 0x1adf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ae2:
	/* 0x1ae2: je     3737 <generic_uprobe_filter_arg+0x3737> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14135ULL;
	}
x86_l_1ae8:
	/* 0x1ae8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1aed:
	/* 0x1aed: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1af2:
	/* 0x1af2: mov    rdi,QWORD PTR [rip+0x1eeb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1af9:
	/* 0x1af9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1afb:
	/* 0x1afb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1afe:
	/* 0x1afe: je     3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14133ULL;
	}
x86_l_1b04:
	/* 0x1b04: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_1b0a:
	/* 0x1b0a: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_1b0f:
	/* 0x1b0f: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_1b12:
	/* 0x1b12: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_1b19:
	/* 0x1b19: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b1b:
	/* 0x1b1b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b1e:
	/* 0x1b1e: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1b22:
	/* 0x1b22: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1b25:
	/* 0x1b25: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b2a:
	/* 0x1b2a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b2f:
	/* 0x1b2f: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1b31:
	/* 0x1b31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b33:
	/* 0x1b33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b38:
	/* 0x1b38: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1b3b:
	/* 0x1b3b: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1b3e:
	/* 0x1b3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b40:
	/* 0x1b40: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b42:
	/* 0x1b42: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b45:
	/* 0x1b45: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_1b48:
	/* 0x1b48: jmp    3737 <generic_uprobe_filter_arg+0x3737> */
	return 14135ULL;
x86_l_1b4d:
	/* 0x1b4d: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1b58:
	/* 0x1b58: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_1b5e:
	/* 0x1b5e: ja     2b10 <generic_uprobe_filter_arg+0x2b10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11024ULL;
	}
x86_l_1b64:
	/* 0x1b64: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1b67:
	/* 0x1b67: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1b6c:
	/* 0x1b6c: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b71:
	/* 0x1b71: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b76:
	/* 0x1b76: ja     2845 <generic_uprobe_filter_arg+0x2845> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10309ULL;
	}
x86_l_1b7c:
	/* 0x1b7c: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b80:
	/* 0x1b80: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1b86:
	/* 0x1b86: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1b89:
	/* 0x1b89: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1b8c:
	/* 0x1b8c: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1b8f:
	/* 0x1b8f: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1b91:
	/* 0x1b91: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1b94:
	/* 0x1b94: je     1b9e <generic_uprobe_filter_arg+0x1b9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b9e;
	}
x86_l_1b96:
	/* 0x1b96: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1b98:
	/* 0x1b98: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1b9a:
	/* 0x1b9a: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1b9c:
	/* 0x1b9c: je     1bb9 <generic_uprobe_filter_arg+0x1bb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bb9;
	}
x86_l_1b9e:
	/* 0x1b9e: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ba1:
	/* 0x1ba1: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1ba3:
	/* 0x1ba3: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ba5:
	/* 0x1ba5: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1ba7:
	/* 0x1ba7: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1baa:
	/* 0x1baa: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1bad:
	/* 0x1bad: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1bb1:
	/* 0x1bb1: ja     287c <generic_uprobe_filter_arg+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10364ULL;
	}
x86_l_1bb7:
	/* 0x1bb7: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1bb9:
	/* 0x1bb9: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1bbc:
	/* 0x1bbc: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1bc2:
	/* 0x1bc2: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1bc5:
	/* 0x1bc5: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1bc7:
	/* 0x1bc7: jmp    3131 <generic_uprobe_filter_arg+0x3131> */
	return 12593ULL;
x86_l_1bcc:
	/* 0x1bcc: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bd0:
	/* 0x1bd0: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1bd3:
	/* 0x1bd3: ja     1bde <generic_uprobe_filter_arg+0x1bde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bde;
	}
x86_l_1bd5:
	/* 0x1bd5: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1bd8:
	/* 0x1bd8: jbe    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_1bde:
	/* 0x1bde: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1be3:
	/* 0x1be3: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1be6:
	/* 0x1be6: jb     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 272ULL;
	}
x86_l_1bec:
	/* 0x1bec: mov    rdi,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bf1:
	/* 0x1bf1: mov    rsi,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bf6:
	/* 0x1bf6: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1bf9:
	/* 0x1bf9: je     1c04 <generic_uprobe_filter_arg+0x1c04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c04;
	}
x86_l_1bfb:
	/* 0x1bfb: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1bfe:
	/* 0x1bfe: jne    2274 <generic_uprobe_filter_arg+0x2274> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8820ULL;
	}
x86_l_1c04:
	/* 0x1c04: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1c07:
	/* 0x1c07: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c0c:
	/* 0x1c0c: jg     2287 <generic_uprobe_filter_arg+0x2287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8839ULL;
	}
x86_l_1c12:
	/* 0x1c12: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_1c15:
	/* 0x1c15: jle    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_1c1b:
	/* 0x1c1b: jmp    2287 <generic_uprobe_filter_arg+0x2287> */
	return 8839ULL;
x86_l_1c20:
	/* 0x1c20: mov    rdx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c24:
	/* 0x1c24: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1c27:
	/* 0x1c27: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1c2b:
	/* 0x1c2b: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1c2e:
	/* 0x1c2e: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1c31:
	/* 0x1c31: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1c34:
	/* 0x1c34: mov    esi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c39:
	/* 0x1c39: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_1c3c:
	/* 0x1c3c: jb     2fab <generic_uprobe_filter_arg+0x2fab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12203ULL;
	}
x86_l_1c42:
	/* 0x1c42: mov    r8,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c47:
	/* 0x1c47: mov    rdi,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c4c:
	/* 0x1c4c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c4f:
	/* 0x1c4f: je     1c5a <generic_uprobe_filter_arg+0x1c5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c5a;
	}
x86_l_1c51:
	/* 0x1c51: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1c54:
	/* 0x1c54: jne    21ba <generic_uprobe_filter_arg+0x21ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8634ULL;
	}
x86_l_1c5a:
	/* 0x1c5a: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_1c5d:
	/* 0x1c5d: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1c61:
	/* 0x1c61: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1c64:
	/* 0x1c64: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1c68:
	/* 0x1c68: jmp    21c8 <generic_uprobe_filter_arg+0x21c8> */
	return 8648ULL;
x86_l_1c6d:
	/* 0x1c6d: movzx  ebx,WORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1c72:
	/* 0x1c72: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_1c75:
	/* 0x1c75: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1c7b:
	/* 0x1c7b: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1c7f:
	/* 0x1c7f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c84:
	/* 0x1c84: mov    rdi,QWORD PTR [rip+0x1eeb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1c8b:
	/* 0x1c8b: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1c90:
	/* 0x1c90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c92:
	/* 0x1c92: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c95:
	/* 0x1c95: je     2ac <generic_uprobe_filter_arg+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 684ULL;
	}
x86_l_1c9b:
	/* 0x1c9b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1c9e:
	/* 0x1c9e: movzx  eax,bx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1ca1:
	/* 0x1ca1: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ca9:
	/* 0x1ca9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cae:
	/* 0x1cae: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cb3:
	/* 0x1cb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb5:
	/* 0x1cb5: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cba:
	/* 0x1cba: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cbc:
	/* 0x1cbc: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1cbf:
	/* 0x1cbf: ja     22c4 <generic_uprobe_filter_arg+0x22c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8900ULL;
	}
x86_l_1cc5:
	/* 0x1cc5: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1cca:
	/* 0x1cca: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1ccd:
	/* 0x1ccd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd2:
	/* 0x1cd2: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cd7:
	/* 0x1cd7: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_1cda:
	/* 0x1cda: jae    1ce4 <generic_uprobe_filter_arg+0x1ce4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1ce4;
	}
x86_l_1cdc:
	/* 0x1cdc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cdf:
	/* 0x1cdf: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1ce2:
	/* 0x1ce2: jmp    1cf4 <generic_uprobe_filter_arg+0x1cf4> */
	goto x86_l_1cf4;
x86_l_1ce4:
	/* 0x1ce4: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1ce9:
	/* 0x1ce9: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1cec:
	/* 0x1cec: jae    1cf4 <generic_uprobe_filter_arg+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1cf4;
	}
x86_l_1cee:
	/* 0x1cee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cf1:
	/* 0x1cf1: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1cf4:
	/* 0x1cf4: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1cf7:
	/* 0x1cf7: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_1cfc:
	/* 0x1cfc: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cfe:
	/* 0x1cfe: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d03:
	/* 0x1d03: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d08:
	/* 0x1d08: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_1d0b:
	/* 0x1d0b: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d10:
	/* 0x1d10: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_1d14:
	/* 0x1d14: jbe    33b0 <generic_uprobe_filter_arg+0x33b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13232ULL;
	}
x86_l_1d1a:
	/* 0x1d1a: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_1d1f:
	/* 0x1d1f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d21:
	/* 0x1d21: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d26:
	/* 0x1d26: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_1d2a:
	/* 0x1d2a: ja     2c33 <generic_uprobe_filter_arg+0x2c33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11315ULL;
	}
x86_l_1d30:
	/* 0x1d30: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_1d3a:
	/* 0x1d3a: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1d3e:
	/* 0x1d3e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d43:
	/* 0x1d43: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d48:
	/* 0x1d48: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d4d:
	/* 0x1d4d: jb     33c4 <generic_uprobe_filter_arg+0x33c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13252ULL;
	}
x86_l_1d53:
	/* 0x1d53: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_1d58:
	/* 0x1d58: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d5d:
	/* 0x1d5d: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1d60:
	/* 0x1d60: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1d63:
	/* 0x1d63: jmp    1f82 <generic_uprobe_filter_arg+0x1f82> */
	goto x86_l_1f82;
x86_l_1d68:
	/* 0x1d68: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1d6d:
	/* 0x1d6d: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1d72:
	/* 0x1d72: jb     1d9f <generic_uprobe_filter_arg+0x1d9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d9f;
	}
x86_l_1d74:
	/* 0x1d74: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_1d79:
	/* 0x1d79: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_1d7e:
	/* 0x1d7e: jb     1d9f <generic_uprobe_filter_arg+0x1d9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d9f;
	}
x86_l_1d80:
	/* 0x1d80: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_1d85:
	/* 0x1d85: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_1d8a:
	/* 0x1d8a: jb     1d9f <generic_uprobe_filter_arg+0x1d9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d9f;
	}
x86_l_1d8c:
	/* 0x1d8c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d8e:
	/* 0x1d8e: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_1d93:
	/* 0x1d93: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_1d96:
	/* 0x1d96: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_1d99:
	/* 0x1d99: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_1d9f:
	/* 0x1d9f: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_1da5:
	/* 0x1da5: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_1dab:
	/* 0x1dab: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1dae:
	/* 0x1dae: jg     20da <generic_uprobe_filter_arg+0x20da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8410ULL;
	}
x86_l_1db4:
	/* 0x1db4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1db6:
	/* 0x1db6: je     2a39 <generic_uprobe_filter_arg+0x2a39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10809ULL;
	}
x86_l_1dbc:
	/* 0x1dbc: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dbf:
	/* 0x1dbf: jne    2a32 <generic_uprobe_filter_arg+0x2a32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10802ULL;
	}
x86_l_1dc5:
	/* 0x1dc5: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1dca:
	/* 0x1dca: jmp    2a45 <generic_uprobe_filter_arg+0x2a45> */
	return 10821ULL;
x86_l_1dcf:
	/* 0x1dcf: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dd3:
	/* 0x1dd3: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_1dd9:
	/* 0x1dd9: jmp    1de5 <generic_uprobe_filter_arg+0x1de5> */
	goto x86_l_1de5;
x86_l_1ddb:
	/* 0x1ddb: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ddf:
	/* 0x1ddf: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_1de5:
	/* 0x1de5: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dea:
	/* 0x1dea: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1ded:
	/* 0x1ded: jb     37cd <generic_uprobe_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14285ULL;
	}
x86_l_1df3:
	/* 0x1df3: mov    rsi,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1df8:
	/* 0x1df8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1dfb:
	/* 0x1dfb: jle    1e19 <generic_uprobe_filter_arg+0x1e19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e19;
	}
x86_l_1dfd:
	/* 0x1dfd: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1e00:
	/* 0x1e00: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1e03:
	/* 0x1e03: jae    1e48 <generic_uprobe_filter_arg+0x1e48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1e48;
	}
x86_l_1e05:
	/* 0x1e05: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e09:
	/* 0x1e09: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e0e:
	/* 0x1e0e: jne    2950 <generic_uprobe_filter_arg+0x2950> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10576ULL;
	}
x86_l_1e14:
	/* 0x1e14: jmp    366e <generic_uprobe_filter_arg+0x366e> */
	return 13934ULL;
x86_l_1e19:
	/* 0x1e19: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e1c:
	/* 0x1e1c: je     1eb7 <generic_uprobe_filter_arg+0x1eb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eb7;
	}
x86_l_1e22:
	/* 0x1e22: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e25:
	/* 0x1e25: jne    2950 <generic_uprobe_filter_arg+0x2950> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10576ULL;
	}
x86_l_1e2b:
	/* 0x1e2b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1e2e:
	/* 0x1e2e: je     1e39 <generic_uprobe_filter_arg+0x1e39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e39;
	}
x86_l_1e30:
	/* 0x1e30: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1e33:
	/* 0x1e33: jne    2946 <generic_uprobe_filter_arg+0x2946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10566ULL;
	}
x86_l_1e39:
	/* 0x1e39: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e3d:
	/* 0x1e3d: jl     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_1e43:
	/* 0x1e43: jmp    2950 <generic_uprobe_filter_arg+0x2950> */
	return 10576ULL;
x86_l_1e48:
	/* 0x1e48: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1e4b:
	/* 0x1e4b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e50:
	/* 0x1e50: jne    2950 <generic_uprobe_filter_arg+0x2950> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10576ULL;
	}
x86_l_1e56:
	/* 0x1e56: test   QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e5a:
	/* 0x1e5a: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_1e60:
	/* 0x1e60: jmp    2950 <generic_uprobe_filter_arg+0x2950> */
	return 10576ULL;
x86_l_1e65:
	/* 0x1e65: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1e68:
	/* 0x1e68: jne    1fa9 <generic_uprobe_filter_arg+0x1fa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fa9;
	}
x86_l_1e6e:
	/* 0x1e6e: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e73:
	/* 0x1e73: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1e75:
	/* 0x1e75: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_1e7b:
	/* 0x1e7b: jmp    1fa9 <generic_uprobe_filter_arg+0x1fa9> */
	goto x86_l_1fa9;
x86_l_1e80:
	/* 0x1e80: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1e83:
	/* 0x1e83: jne    1ff0 <generic_uprobe_filter_arg+0x1ff0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ff0;
	}
x86_l_1e89:
	/* 0x1e89: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e8e:
	/* 0x1e8e: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1e90:
	/* 0x1e90: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_1e96:
	/* 0x1e96: jmp    1ff0 <generic_uprobe_filter_arg+0x1ff0> */
	goto x86_l_1ff0;
x86_l_1e9b:
	/* 0x1e9b: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1e9e:
	/* 0x1e9e: je     2400 <generic_uprobe_filter_arg+0x2400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9216ULL;
	}
x86_l_1ea4:
	/* 0x1ea4: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1ea7:
	/* 0x1ea7: jne    23f2 <generic_uprobe_filter_arg+0x23f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9202ULL;
	}
x86_l_1ead:
	/* 0x1ead: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_1eb2:
	/* 0x1eb2: jmp    2405 <generic_uprobe_filter_arg+0x2405> */
	return 9221ULL;
x86_l_1eb7:
	/* 0x1eb7: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1eba:
	/* 0x1eba: je     1ec5 <generic_uprobe_filter_arg+0x1ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ec5;
	}
x86_l_1ebc:
	/* 0x1ebc: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1ebf:
	/* 0x1ebf: jne    293a <generic_uprobe_filter_arg+0x293a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10554ULL;
	}
x86_l_1ec5:
	/* 0x1ec5: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ec9:
	/* 0x1ec9: jg     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_1ecf:
	/* 0x1ecf: jmp    2950 <generic_uprobe_filter_arg+0x2950> */
	return 10576ULL;
x86_l_1ed4:
	/* 0x1ed4: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ed9:
	/* 0x1ed9: movzx  ecx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1ede:
	/* 0x1ede: jmp    1eea <generic_uprobe_filter_arg+0x1eea> */
	goto x86_l_1eea;
x86_l_1ee0:
	/* 0x1ee0: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ee5:
	/* 0x1ee5: movzx  ecx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1eea:
	/* 0x1eea: cmp    DWORD PTR [r12+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1eef:
	/* 0x1eef: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1ef3:
	/* 0x1ef3: cmp    DWORD PTR [r12+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1ef8:
	/* 0x1ef8: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_1efb:
	/* 0x1efb: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1efe:
	/* 0x1efe: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1f01:
	/* 0x1f01: jb     2fab <generic_uprobe_filter_arg+0x2fab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12203ULL;
	}
x86_l_1f07:
	/* 0x1f07: cmp    DWORD PTR [r12+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f0c:
	/* 0x1f0c: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1f10:
	/* 0x1f10: cmp    DWORD PTR [r12+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f15:
	/* 0x1f15: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1f19:
	/* 0x1f19: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f1c:
	/* 0x1f1c: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f1f:
	/* 0x1f1f: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1f22:
	/* 0x1f22: jb     2fa6 <generic_uprobe_filter_arg+0x2fa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12198ULL;
	}
x86_l_1f28:
	/* 0x1f28: cmp    DWORD PTR [r12+0x20],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f2d:
	/* 0x1f2d: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1f31:
	/* 0x1f31: cmp    DWORD PTR [r12+0x24],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f36:
	/* 0x1f36: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1f3a:
	/* 0x1f3a: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f3d:
	/* 0x1f3d: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f40:
	/* 0x1f40: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1f43:
	/* 0x1f43: jb     2fa6 <generic_uprobe_filter_arg+0x2fa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12198ULL;
	}
x86_l_1f49:
	/* 0x1f49: cmp    DWORD PTR [r12+0x28],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f4e:
	/* 0x1f4e: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_1f51:
	/* 0x1f51: cmp    DWORD PTR [r12+0x2c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1f56:
	/* 0x1f56: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_1f59:
	/* 0x1f59: and    cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f5b:
	/* 0x1f5b: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f5d:
	/* 0x1f5d: jmp    2fa6 <generic_uprobe_filter_arg+0x2fa6> */
	return 12198ULL;
x86_l_1f62:
	/* 0x1f62: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1f65:
	/* 0x1f65: je     262c <generic_uprobe_filter_arg+0x262c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9772ULL;
	}
x86_l_1f6b:
	/* 0x1f6b: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1f6e:
	/* 0x1f6e: jne    261c <generic_uprobe_filter_arg+0x261c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9756ULL;
	}
x86_l_1f74:
	/* 0x1f74: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_1f7a:
	/* 0x1f7a: jmp    2632 <generic_uprobe_filter_arg+0x2632> */
	return 9778ULL;
x86_l_1f7f:
	/* 0x1f7f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f82:
	/* 0x1f82: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1f85:
	/* 0x1f85: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f8a:
	/* 0x1f8a: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f8f:
	/* 0x1f8f: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f94:
	/* 0x1f94: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f97:
	/* 0x1f97: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_1f9c:
	/* 0x1f9c: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1fa1:
	/* 0x1fa1: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1fa3:
	/* 0x1fa3: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_1fa9:
	/* 0x1fa9: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fae:
	/* 0x1fae: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1fb1:
	/* 0x1fb1: jb     37cd <generic_uprobe_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14285ULL;
	}
x86_l_1fb7:
	/* 0x1fb7: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1fbc:
	/* 0x1fbc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1fbf:
	/* 0x1fbf: jle    239b <generic_uprobe_filter_arg+0x239b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9115ULL;
	}
x86_l_1fc5:
	/* 0x1fc5: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1fc8:
	/* 0x1fc8: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1fcb:
	/* 0x1fcb: jae    29cb <generic_uprobe_filter_arg+0x29cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10699ULL;
	}
x86_l_1fd1:
	/* 0x1fd1: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1fd6:
	/* 0x1fd6: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1fd8:
	/* 0x1fd8: jne    2c70 <generic_uprobe_filter_arg+0x2c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11376ULL;
	}
x86_l_1fde:
	/* 0x1fde: jmp    366e <generic_uprobe_filter_arg+0x366e> */
	return 13934ULL;
x86_l_1fe3:
	/* 0x1fe3: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fe8:
	/* 0x1fe8: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1fea:
	/* 0x1fea: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_1ff0:
	/* 0x1ff0: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ff5:
	/* 0x1ff5: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1ff8:
	/* 0x1ff8: jb     37cd <generic_uprobe_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14285ULL;
	}
x86_l_1ffe:
	/* 0x1ffe: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2003:
	/* 0x2003: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2006:
	/* 0x2006: jle    23bf <generic_uprobe_filter_arg+0x23bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9151ULL;
	}
x86_l_200c:
	/* 0x200c: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_200f:
	/* 0x200f: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2012:
	/* 0x2012: jae    29e6 <generic_uprobe_filter_arg+0x29e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10726ULL;
	}
x86_l_2018:
	/* 0x2018: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_201d:
	/* 0x201d: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_201f:
	/* 0x201f: jne    2cb2 <generic_uprobe_filter_arg+0x2cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11442ULL;
	}
x86_l_2025:
	/* 0x2025: jmp    366e <generic_uprobe_filter_arg+0x366e> */
	return 13934ULL;
x86_l_202a:
	/* 0x202a: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_202e:
	/* 0x202e: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2030:
	/* 0x2030: ja     203a <generic_uprobe_filter_arg+0x203a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8250ULL;
	}
	return 8242ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8242ULL: goto x86_l_2032;
	case 8244ULL: goto x86_l_2034;
	case 8250ULL: goto x86_l_203a;
	case 8255ULL: goto x86_l_203f;
	case 8258ULL: goto x86_l_2042;
	case 8264ULL: goto x86_l_2048;
	case 8269ULL: goto x86_l_204d;
	case 8274ULL: goto x86_l_2052;
	case 8277ULL: goto x86_l_2055;
	case 8283ULL: goto x86_l_205b;
	case 8289ULL: goto x86_l_2061;
	case 8293ULL: goto x86_l_2065;
	case 8299ULL: goto x86_l_206b;
	case 8301ULL: goto x86_l_206d;
	case 8306ULL: goto x86_l_2072;
	case 8312ULL: goto x86_l_2078;
	case 8314ULL: goto x86_l_207a;
	case 8320ULL: goto x86_l_2080;
	case 8325ULL: goto x86_l_2085;
	case 8329ULL: goto x86_l_2089;
	case 8331ULL: goto x86_l_208b;
	case 8335ULL: goto x86_l_208f;
	case 8337ULL: goto x86_l_2091;
	case 8340ULL: goto x86_l_2094;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8351ULL: goto x86_l_209f;
	case 8357ULL: goto x86_l_20a5;
	case 8362ULL: goto x86_l_20aa;
	case 8367ULL: goto x86_l_20af;
	case 8370ULL: goto x86_l_20b2;
	case 8376ULL: goto x86_l_20b8;
	case 8382ULL: goto x86_l_20be;
	case 8386ULL: goto x86_l_20c2;
	case 8392ULL: goto x86_l_20c8;
	case 8395ULL: goto x86_l_20cb;
	case 8399ULL: goto x86_l_20cf;
	case 8401ULL: goto x86_l_20d1;
	case 8405ULL: goto x86_l_20d5;
	case 8410ULL: goto x86_l_20da;
	case 8413ULL: goto x86_l_20dd;
	case 8419ULL: goto x86_l_20e3;
	case 8422ULL: goto x86_l_20e6;
	case 8428ULL: goto x86_l_20ec;
	case 8433ULL: goto x86_l_20f1;
	case 8438ULL: goto x86_l_20f6;
	case 8440ULL: goto x86_l_20f8;
	case 8443ULL: goto x86_l_20fb;
	case 8446ULL: goto x86_l_20fe;
	case 8451ULL: goto x86_l_2103;
	case 8455ULL: goto x86_l_2107;
	case 8460ULL: goto x86_l_210c;
	case 8465ULL: goto x86_l_2111;
	case 8472ULL: goto x86_l_2118;
	case 8474ULL: goto x86_l_211a;
	case 8477ULL: goto x86_l_211d;
	case 8483ULL: goto x86_l_2123;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8493ULL: goto x86_l_212d;
	case 8498ULL: goto x86_l_2132;
	case 8500ULL: goto x86_l_2134;
	case 8505ULL: goto x86_l_2139;
	case 8507ULL: goto x86_l_213b;
	case 8509ULL: goto x86_l_213d;
	case 8512ULL: goto x86_l_2140;
	case 8515ULL: goto x86_l_2143;
	case 8518ULL: goto x86_l_2146;
	case 8520ULL: goto x86_l_2148;
	case 8522ULL: goto x86_l_214a;
	case 8526ULL: goto x86_l_214e;
	case 8529ULL: goto x86_l_2151;
	case 8531ULL: goto x86_l_2153;
	case 8535ULL: goto x86_l_2157;
	case 8538ULL: goto x86_l_215a;
	case 8540ULL: goto x86_l_215c;
	case 8544ULL: goto x86_l_2160;
	case 8546ULL: goto x86_l_2162;
	case 8550ULL: goto x86_l_2166;
	case 8554ULL: goto x86_l_216a;
	case 8557ULL: goto x86_l_216d;
	case 8559ULL: goto x86_l_216f;
	case 8561ULL: goto x86_l_2171;
	case 8563ULL: goto x86_l_2173;
	case 8569ULL: goto x86_l_2179;
	case 8573ULL: goto x86_l_217d;
	case 8578ULL: goto x86_l_2182;
	case 8580ULL: goto x86_l_2184;
	case 8584ULL: goto x86_l_2188;
	case 8587ULL: goto x86_l_218b;
	case 8591ULL: goto x86_l_218f;
	case 8597ULL: goto x86_l_2195;
	case 8599ULL: goto x86_l_2197;
	case 8604ULL: goto x86_l_219c;
	case 8609ULL: goto x86_l_21a1;
	case 8611ULL: goto x86_l_21a3;
	case 8616ULL: goto x86_l_21a8;
	case 8619ULL: goto x86_l_21ab;
	case 8624ULL: goto x86_l_21b0;
	case 8629ULL: goto x86_l_21b5;
	case 8634ULL: goto x86_l_21ba;
	case 8637ULL: goto x86_l_21bd;
	case 8641ULL: goto x86_l_21c1;
	case 8644ULL: goto x86_l_21c4;
	case 8648ULL: goto x86_l_21c8;
	case 8651ULL: goto x86_l_21cb;
	case 8654ULL: goto x86_l_21ce;
	case 8657ULL: goto x86_l_21d1;
	case 8663ULL: goto x86_l_21d7;
	case 8668ULL: goto x86_l_21dc;
	case 8673ULL: goto x86_l_21e1;
	case 8676ULL: goto x86_l_21e4;
	case 8678ULL: goto x86_l_21e6;
	case 8681ULL: goto x86_l_21e9;
	case 8687ULL: goto x86_l_21ef;
	case 8690ULL: goto x86_l_21f2;
	case 8694ULL: goto x86_l_21f6;
	case 8697ULL: goto x86_l_21f9;
	case 8701ULL: goto x86_l_21fd;
	case 8706ULL: goto x86_l_2202;
	case 8708ULL: goto x86_l_2204;
	case 8711ULL: goto x86_l_2207;
	case 8713ULL: goto x86_l_2209;
	case 8716ULL: goto x86_l_220c;
	case 8718ULL: goto x86_l_220e;
	case 8722ULL: goto x86_l_2212;
	case 8725ULL: goto x86_l_2215;
	case 8727ULL: goto x86_l_2217;
	case 8730ULL: goto x86_l_221a;
	case 8736ULL: goto x86_l_2220;
	case 8739ULL: goto x86_l_2223;
	case 8745ULL: goto x86_l_2229;
	case 8749ULL: goto x86_l_222d;
	case 8754ULL: goto x86_l_2232;
	case 8761ULL: goto x86_l_2239;
	case 8766ULL: goto x86_l_223e;
	case 8768ULL: goto x86_l_2240;
	case 8771ULL: goto x86_l_2243;
	case 8777ULL: goto x86_l_2249;
	case 8780ULL: goto x86_l_224c;
	case 8782ULL: goto x86_l_224e;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8800ULL: goto x86_l_2260;
	case 8805ULL: goto x86_l_2265;
	case 8807ULL: goto x86_l_2267;
	case 8810ULL: goto x86_l_226a;
	case 8815ULL: goto x86_l_226f;
	case 8820ULL: goto x86_l_2274;
	case 8823ULL: goto x86_l_2277;
	case 8828ULL: goto x86_l_227c;
	case 8830ULL: goto x86_l_227e;
	case 8833ULL: goto x86_l_2281;
	case 8839ULL: goto x86_l_2287;
	case 8842ULL: goto x86_l_228a;
	case 8848ULL: goto x86_l_2290;
	case 8853ULL: goto x86_l_2295;
	case 8858ULL: goto x86_l_229a;
	case 8861ULL: goto x86_l_229d;
	case 8863ULL: goto x86_l_229f;
	case 8866ULL: goto x86_l_22a2;
	case 8872ULL: goto x86_l_22a8;
	case 8875ULL: goto x86_l_22ab;
	case 8880ULL: goto x86_l_22b0;
	case 8886ULL: goto x86_l_22b6;
	case 8889ULL: goto x86_l_22b9;
	case 8895ULL: goto x86_l_22bf;
	case 8900ULL: goto x86_l_22c4;
	case 8905ULL: goto x86_l_22c9;
	case 8910ULL: goto x86_l_22ce;
	case 8913ULL: goto x86_l_22d1;
	case 8918ULL: goto x86_l_22d6;
	case 8922ULL: goto x86_l_22da;
	case 8928ULL: goto x86_l_22e0;
	case 8930ULL: goto x86_l_22e2;
	case 8934ULL: goto x86_l_22e6;
	case 8940ULL: goto x86_l_22ec;
	case 8945ULL: goto x86_l_22f1;
	case 8948ULL: goto x86_l_22f4;
	case 8954ULL: goto x86_l_22fa;
	case 8959ULL: goto x86_l_22ff;
	case 8962ULL: goto x86_l_2302;
	case 8964ULL: goto x86_l_2304;
	case 8967ULL: goto x86_l_2307;
	case 8970ULL: goto x86_l_230a;
	case 8972ULL: goto x86_l_230c;
	case 8976ULL: goto x86_l_2310;
	case 8981ULL: goto x86_l_2315;
	case 8987ULL: goto x86_l_231b;
	case 8992ULL: goto x86_l_2320;
	case 8995ULL: goto x86_l_2323;
	case 8997ULL: goto x86_l_2325;
	case 9000ULL: goto x86_l_2328;
	case 9006ULL: goto x86_l_232e;
	case 9009ULL: goto x86_l_2331;
	case 9015ULL: goto x86_l_2337;
	case 9021ULL: goto x86_l_233d;
	case 9025ULL: goto x86_l_2341;
	case 9031ULL: goto x86_l_2347;
	case 9035ULL: goto x86_l_234b;
	case 9041ULL: goto x86_l_2351;
	case 9046ULL: goto x86_l_2356;
	case 9049ULL: goto x86_l_2359;
	case 9054ULL: goto x86_l_235e;
	case 9060ULL: goto x86_l_2364;
	case 9064ULL: goto x86_l_2368;
	case 9070ULL: goto x86_l_236e;
	case 9075ULL: goto x86_l_2373;
	case 9078ULL: goto x86_l_2376;
	case 9084ULL: goto x86_l_237c;
	case 9090ULL: goto x86_l_2382;
	case 9094ULL: goto x86_l_2386;
	case 9100ULL: goto x86_l_238c;
	case 9104ULL: goto x86_l_2390;
	case 9110ULL: goto x86_l_2396;
	case 9115ULL: goto x86_l_239b;
	case 9118ULL: goto x86_l_239e;
	case 9124ULL: goto x86_l_23a4;
	case 9127ULL: goto x86_l_23a7;
	case 9133ULL: goto x86_l_23ad;
	case 9138ULL: goto x86_l_23b2;
	case 9140ULL: goto x86_l_23b4;
	case 9146ULL: goto x86_l_23ba;
	case 9151ULL: goto x86_l_23bf;
	case 9154ULL: goto x86_l_23c2;
	case 9160ULL: goto x86_l_23c8;
	case 9163ULL: goto x86_l_23cb;
	case 9169ULL: goto x86_l_23d1;
	case 9174ULL: goto x86_l_23d6;
	case 9176ULL: goto x86_l_23d8;
	case 9182ULL: goto x86_l_23de;
	case 9187ULL: goto x86_l_23e3;
	case 9192ULL: goto x86_l_23e8;
	case 9197ULL: goto x86_l_23ed;
	case 9202ULL: goto x86_l_23f2;
	case 9207ULL: goto x86_l_23f7;
	case 9209ULL: goto x86_l_23f9;
	case 9214ULL: goto x86_l_23fe;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9223ULL: goto x86_l_2407;
	case 9226ULL: goto x86_l_240a;
	case 9231ULL: goto x86_l_240f;
	case 9234ULL: goto x86_l_2412;
	case 9240ULL: goto x86_l_2418;
	case 9244ULL: goto x86_l_241c;
	case 9251ULL: goto x86_l_2423;
	case 9256ULL: goto x86_l_2428;
	case 9261ULL: goto x86_l_242d;
	case 9268ULL: goto x86_l_2434;
	case 9273ULL: goto x86_l_2439;
	case 9276ULL: goto x86_l_243c;
	case 9278ULL: goto x86_l_243e;
	case 9281ULL: goto x86_l_2441;
	case 9286ULL: goto x86_l_2446;
	case 9293ULL: goto x86_l_244d;
	case 9296ULL: goto x86_l_2450;
	case 9298ULL: goto x86_l_2452;
	case 9303ULL: goto x86_l_2457;
	case 9306ULL: goto x86_l_245a;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9320ULL: goto x86_l_2468;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9335ULL: goto x86_l_2477;
	case 9341ULL: goto x86_l_247d;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9358ULL: goto x86_l_248e;
	case 9365ULL: goto x86_l_2495;
	case 9368ULL: goto x86_l_2498;
	case 9370ULL: goto x86_l_249a;
	case 9375ULL: goto x86_l_249f;
	case 9378ULL: goto x86_l_24a2;
	case 9382ULL: goto x86_l_24a6;
	case 9387ULL: goto x86_l_24ab;
	case 9389ULL: goto x86_l_24ad;
	case 9391ULL: goto x86_l_24af;
	case 9396ULL: goto x86_l_24b4;
	case 9398ULL: goto x86_l_24b6;
	case 9403ULL: goto x86_l_24bb;
	case 9405ULL: goto x86_l_24bd;
	case 9410ULL: goto x86_l_24c2;
	case 9414ULL: goto x86_l_24c6;
	case 9417ULL: goto x86_l_24c9;
	case 9423ULL: goto x86_l_24cf;
	case 9428ULL: goto x86_l_24d4;
	case 9436ULL: goto x86_l_24dc;
	case 9438ULL: goto x86_l_24de;
	case 9443ULL: goto x86_l_24e3;
	case 9446ULL: goto x86_l_24e6;
	case 9450ULL: goto x86_l_24ea;
	case 9455ULL: goto x86_l_24ef;
	case 9457ULL: goto x86_l_24f1;
	case 9459ULL: goto x86_l_24f3;
	case 9464ULL: goto x86_l_24f8;
	case 9466ULL: goto x86_l_24fa;
	case 9471ULL: goto x86_l_24ff;
	case 9473ULL: goto x86_l_2501;
	case 9478ULL: goto x86_l_2506;
	case 9482ULL: goto x86_l_250a;
	case 9486ULL: goto x86_l_250e;
	case 9492ULL: goto x86_l_2514;
	case 9497ULL: goto x86_l_2519;
	case 9505ULL: goto x86_l_2521;
	case 9507ULL: goto x86_l_2523;
	case 9512ULL: goto x86_l_2528;
	case 9515ULL: goto x86_l_252b;
	case 9520ULL: goto x86_l_2530;
	case 9525ULL: goto x86_l_2535;
	case 9530ULL: goto x86_l_253a;
	case 9532ULL: goto x86_l_253c;
	case 9535ULL: goto x86_l_253f;
	case 9541ULL: goto x86_l_2545;
	case 9544ULL: goto x86_l_2548;
	case 9550ULL: goto x86_l_254e;
	case 9553ULL: goto x86_l_2551;
	case 9559ULL: goto x86_l_2557;
	case 9562ULL: goto x86_l_255a;
	case 9568ULL: goto x86_l_2560;
	case 9573ULL: goto x86_l_2565;
	case 9578ULL: goto x86_l_256a;
	case 9585ULL: goto x86_l_2571;
	case 9590ULL: goto x86_l_2576;
	case 9593ULL: goto x86_l_2579;
	case 9599ULL: goto x86_l_257f;
	case 9602ULL: goto x86_l_2582;
	case 9608ULL: goto x86_l_2588;
	case 9611ULL: goto x86_l_258b;
	case 9617ULL: goto x86_l_2591;
	case 9620ULL: goto x86_l_2594;
	case 9626ULL: goto x86_l_259a;
	case 9631ULL: goto x86_l_259f;
	case 9636ULL: goto x86_l_25a4;
	case 9643ULL: goto x86_l_25ab;
	case 9648ULL: goto x86_l_25b0;
	case 9653ULL: goto x86_l_25b5;
	case 9658ULL: goto x86_l_25ba;
	case 9663ULL: goto x86_l_25bf;
	case 9668ULL: goto x86_l_25c4;
	case 9671ULL: goto x86_l_25c7;
	case 9675ULL: goto x86_l_25cb;
	case 9677ULL: goto x86_l_25cd;
	case 9681ULL: goto x86_l_25d1;
	case 9684ULL: goto x86_l_25d4;
	case 9687ULL: goto x86_l_25d7;
	case 9690ULL: goto x86_l_25da;
	case 9696ULL: goto x86_l_25e0;
	case 9701ULL: goto x86_l_25e5;
	case 9706ULL: goto x86_l_25ea;
	case 9709ULL: goto x86_l_25ed;
	case 9715ULL: goto x86_l_25f3;
	case 9721ULL: goto x86_l_25f9;
	case 9725ULL: goto x86_l_25fd;
	case 9731ULL: goto x86_l_2603;
	case 9734ULL: goto x86_l_2606;
	case 9738ULL: goto x86_l_260a;
	case 9740ULL: goto x86_l_260c;
	case 9744ULL: goto x86_l_2610;
	case 9749ULL: goto x86_l_2615;
	case 9751ULL: goto x86_l_2617;
	case 9756ULL: goto x86_l_261c;
	case 9762ULL: goto x86_l_2622;
	case 9764ULL: goto x86_l_2624;
	case 9770ULL: goto x86_l_262a;
	case 9772ULL: goto x86_l_262c;
	case 9778ULL: goto x86_l_2632;
	case 9781ULL: goto x86_l_2635;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9792ULL: goto x86_l_2640;
	case 9798ULL: goto x86_l_2646;
	case 9802ULL: goto x86_l_264a;
	case 9807ULL: goto x86_l_264f;
	case 9815ULL: goto x86_l_2657;
	case 9820ULL: goto x86_l_265c;
	case 9825ULL: goto x86_l_2661;
	case 9830ULL: goto x86_l_2666;
	case 9835ULL: goto x86_l_266b;
	case 9842ULL: goto x86_l_2672;
	case 9847ULL: goto x86_l_2677;
	case 9850ULL: goto x86_l_267a;
	case 9852ULL: goto x86_l_267c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2032:
	/* 0x2032: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2034:
	/* 0x2034: jbe    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_203a:
	/* 0x203a: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_203f:
	/* 0x203f: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2042:
	/* 0x2042: jb     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 272ULL;
	}
x86_l_2048:
	/* 0x2048: mov    edi,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_204d:
	/* 0x204d: mov    esi,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2052:
	/* 0x2052: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2055:
	/* 0x2055: ja     27ee <generic_uprobe_filter_arg+0x27ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10222ULL;
	}
x86_l_205b:
	/* 0x205b: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2061:
	/* 0x2061: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2065:
	/* 0x2065: jae    27ee <generic_uprobe_filter_arg+0x27ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10222ULL;
	}
x86_l_206b:
	/* 0x206b: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_206d:
	/* 0x206d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2072:
	/* 0x2072: jg     27ff <generic_uprobe_filter_arg+0x27ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10239ULL;
	}
x86_l_2078:
	/* 0x2078: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_207a:
	/* 0x207a: jle    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_2080:
	/* 0x2080: jmp    27ff <generic_uprobe_filter_arg+0x27ff> */
	return 10239ULL;
x86_l_2085:
	/* 0x2085: mov    edx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2089:
	/* 0x2089: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_208b:
	/* 0x208b: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_208f:
	/* 0x208f: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_2091:
	/* 0x2091: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_2094:
	/* 0x2094: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_2097:
	/* 0x2097: mov    esi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_209c:
	/* 0x209c: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_209f:
	/* 0x209f: jb     2fab <generic_uprobe_filter_arg+0x2fab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12203ULL;
	}
x86_l_20a5:
	/* 0x20a5: mov    r8d,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20aa:
	/* 0x20aa: mov    edi,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20af:
	/* 0x20af: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_20b2:
	/* 0x20b2: ja     25c4 <generic_uprobe_filter_arg+0x25c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_25c4;
	}
x86_l_20b8:
	/* 0x20b8: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_20be:
	/* 0x20be: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_20c2:
	/* 0x20c2: jae    25c4 <generic_uprobe_filter_arg+0x25c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_25c4;
	}
x86_l_20c8:
	/* 0x20c8: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_20cb:
	/* 0x20cb: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_20cf:
	/* 0x20cf: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_20d1:
	/* 0x20d1: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_20d5:
	/* 0x20d5: jmp    25d1 <generic_uprobe_filter_arg+0x25d1> */
	goto x86_l_25d1;
x86_l_20da:
	/* 0x20da: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_20dd:
	/* 0x20dd: je     2a40 <generic_uprobe_filter_arg+0x2a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10816ULL;
	}
x86_l_20e3:
	/* 0x20e3: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_20e6:
	/* 0x20e6: jne    2a32 <generic_uprobe_filter_arg+0x2a32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10802ULL;
	}
x86_l_20ec:
	/* 0x20ec: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_20f1:
	/* 0x20f1: jmp    2a45 <generic_uprobe_filter_arg+0x2a45> */
	return 10821ULL;
x86_l_20f6:
	/* 0x20f6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20f8:
	/* 0x20f8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20fb:
	/* 0x20fb: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_20fe:
	/* 0x20fe: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_2103:
	/* 0x2103: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2107:
	/* 0x2107: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_210c:
	/* 0x210c: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2111:
	/* 0x2111: mov    rdi,QWORD PTR [rip+0x1eeb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_2118:
	/* 0x2118: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_211a:
	/* 0x211a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_211d:
	/* 0x211d: je     21a1 <generic_uprobe_filter_arg+0x21a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21a1;
	}
x86_l_2123:
	/* 0x2123: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_2125:
	/* 0x2125: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_212a:
	/* 0x212a: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_212d:
	/* 0x212d: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2132:
	/* 0x2132: je     2179 <generic_uprobe_filter_arg+0x2179> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2179;
	}
x86_l_2134:
	/* 0x2134: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2139:
	/* 0x2139: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_213b:
	/* 0x213b: jmp    2148 <generic_uprobe_filter_arg+0x2148> */
	goto x86_l_2148;
x86_l_213d:
	/* 0x213d: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2140:
	/* 0x2140: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2143:
	/* 0x2143: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2146:
	/* 0x2146: je     2179 <generic_uprobe_filter_arg+0x2179> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2179;
	}
x86_l_2148:
	/* 0x2148: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_214a:
	/* 0x214a: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_214e:
	/* 0x214e: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2151:
	/* 0x2151: jae    213d <generic_uprobe_filter_arg+0x213d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_213d;
	}
x86_l_2153:
	/* 0x2153: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_2157:
	/* 0x2157: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_215a:
	/* 0x215a: je     2171 <generic_uprobe_filter_arg+0x2171> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2171;
	}
x86_l_215c:
	/* 0x215c: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_2160:
	/* 0x2160: ja     213d <generic_uprobe_filter_arg+0x213d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_213d;
	}
x86_l_2162:
	/* 0x2162: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2166:
	/* 0x2166: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_216a:
	/* 0x216a: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_216d:
	/* 0x216d: je     214a <generic_uprobe_filter_arg+0x214a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214a;
	}
x86_l_216f:
	/* 0x216f: jmp    213d <generic_uprobe_filter_arg+0x213d> */
	goto x86_l_213d;
x86_l_2171:
	/* 0x2171: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2173:
	/* 0x2173: jns    23e3 <generic_uprobe_filter_arg+0x23e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_23e3;
	}
x86_l_2179:
	/* 0x2179: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_217d:
	/* 0x217d: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_2182:
	/* 0x2182: jae    2195 <generic_uprobe_filter_arg+0x2195> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2195;
	}
x86_l_2184:
	/* 0x2184: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2188:
	/* 0x2188: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_218b:
	/* 0x218b: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_218f:
	/* 0x218f: jne    20fb <generic_uprobe_filter_arg+0x20fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20fb;
	}
x86_l_2195:
	/* 0x2195: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2197:
	/* 0x2197: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_219c:
	/* 0x219c: jmp    3746 <generic_uprobe_filter_arg+0x3746> */
	return 14150ULL;
x86_l_21a1:
	/* 0x21a1: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21a3:
	/* 0x21a3: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21a8:
	/* 0x21a8: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_21ab:
	/* 0x21ab: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_21b0:
	/* 0x21b0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21b5:
	/* 0x21b5: jmp    3746 <generic_uprobe_filter_arg+0x3746> */
	return 14150ULL;
x86_l_21ba:
	/* 0x21ba: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_21bd:
	/* 0x21bd: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_21c1:
	/* 0x21c1: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_21c4:
	/* 0x21c4: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_21c8:
	/* 0x21c8: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_21cb:
	/* 0x21cb: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_21ce:
	/* 0x21ce: cmp    esi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 41ULL);
x86_l_21d1:
	/* 0x21d1: jb     2fa6 <generic_uprobe_filter_arg+0x2fa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12198ULL;
	}
x86_l_21d7:
	/* 0x21d7: mov    r8,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21dc:
	/* 0x21dc: mov    rdi,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21e1:
	/* 0x21e1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_21e4:
	/* 0x21e4: je     21ef <generic_uprobe_filter_arg+0x21ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21ef;
	}
x86_l_21e6:
	/* 0x21e6: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_21e9:
	/* 0x21e9: jne    28ac <generic_uprobe_filter_arg+0x28ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10412ULL;
	}
x86_l_21ef:
	/* 0x21ef: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_21f2:
	/* 0x21f2: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_21f6:
	/* 0x21f6: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_21f9:
	/* 0x21f9: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_21fd:
	/* 0x21fd: jmp    28ba <generic_uprobe_filter_arg+0x28ba> */
	return 10426ULL;
x86_l_2202:
	/* 0x2202: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2204:
	/* 0x2204: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2207:
	/* 0x2207: jne    2212 <generic_uprobe_filter_arg+0x2212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2212;
	}
x86_l_2209:
	/* 0x2209: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_220c:
	/* 0x220c: je     2212 <generic_uprobe_filter_arg+0x2212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2212;
	}
x86_l_220e:
	/* 0x220e: movzx  ebx,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_2212:
	/* 0x2212: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2215:
	/* 0x2215: je     2220 <generic_uprobe_filter_arg+0x2220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2220;
	}
x86_l_2217:
	/* 0x2217: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_221a:
	/* 0x221a: jne    2615 <generic_uprobe_filter_arg+0x2615> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2615;
	}
x86_l_2220:
	/* 0x2220: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_2223:
	/* 0x2223: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2229:
	/* 0x2229: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_222d:
	/* 0x222d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2232:
	/* 0x2232: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2239:
	/* 0x2239: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_223e:
	/* 0x223e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2240:
	/* 0x2240: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2243:
	/* 0x2243: je     2ac <generic_uprobe_filter_arg+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 684ULL;
	}
x86_l_2249:
	/* 0x2249: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_224c:
	/* 0x224c: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_224e:
	/* 0x224e: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2256:
	/* 0x2256: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_225b:
	/* 0x225b: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2260:
	/* 0x2260: jmp    1cb3 <generic_uprobe_filter_arg+0x1cb3> */
	return 7347ULL;
x86_l_2265:
	/* 0x2265: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2267:
	/* 0x2267: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_226a:
	/* 0x226a: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_226f:
	/* 0x226f: jmp    25b5 <generic_uprobe_filter_arg+0x25b5> */
	goto x86_l_25b5;
x86_l_2274:
	/* 0x2274: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2277:
	/* 0x2277: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_227c:
	/* 0x227c: ja     2287 <generic_uprobe_filter_arg+0x2287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2287;
	}
x86_l_227e:
	/* 0x227e: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_2281:
	/* 0x2281: jbe    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_2287:
	/* 0x2287: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_228a:
	/* 0x228a: jb     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 272ULL;
	}
x86_l_2290:
	/* 0x2290: mov    rdi,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2295:
	/* 0x2295: mov    rsi,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_229a:
	/* 0x229a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_229d:
	/* 0x229d: je     22a8 <generic_uprobe_filter_arg+0x22a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a8;
	}
x86_l_229f:
	/* 0x229f: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_22a2:
	/* 0x22a2: jne    28ef <generic_uprobe_filter_arg+0x28ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10479ULL;
	}
x86_l_22a8:
	/* 0x22a8: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_22ab:
	/* 0x22ab: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22b0:
	/* 0x22b0: jg     2902 <generic_uprobe_filter_arg+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10498ULL;
	}
x86_l_22b6:
	/* 0x22b6: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_22b9:
	/* 0x22b9: jle    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_22bf:
	/* 0x22bf: jmp    2902 <generic_uprobe_filter_arg+0x2902> */
	return 10498ULL;
x86_l_22c4:
	/* 0x22c4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22c9:
	/* 0x22c9: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ce:
	/* 0x22ce: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_22d1:
	/* 0x22d1: jmp    1cf4 <generic_uprobe_filter_arg+0x1cf4> */
	return 7412ULL;
x86_l_22d6:
	/* 0x22d6: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22da:
	/* 0x22da: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_22e0:
	/* 0x22e0: jmp    22ec <generic_uprobe_filter_arg+0x22ec> */
	goto x86_l_22ec;
x86_l_22e2:
	/* 0x22e2: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e6:
	/* 0x22e6: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_22ec:
	/* 0x22ec: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22f1:
	/* 0x22f1: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_22f4:
	/* 0x22f4: jb     37cd <generic_uprobe_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14285ULL;
	}
x86_l_22fa:
	/* 0x22fa: mov    esi,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_22ff:
	/* 0x22ff: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2302:
	/* 0x2302: jle    2320 <generic_uprobe_filter_arg+0x2320> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2320;
	}
x86_l_2304:
	/* 0x2304: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2307:
	/* 0x2307: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_230a:
	/* 0x230a: jae    2356 <generic_uprobe_filter_arg+0x2356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2356;
	}
x86_l_230c:
	/* 0x230c: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2310:
	/* 0x2310: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2315:
	/* 0x2315: jne    2e15 <generic_uprobe_filter_arg+0x2e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11797ULL;
	}
x86_l_231b:
	/* 0x231b: jmp    366e <generic_uprobe_filter_arg+0x366e> */
	return 13934ULL;
x86_l_2320:
	/* 0x2320: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2323:
	/* 0x2323: je     2373 <generic_uprobe_filter_arg+0x2373> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2373;
	}
x86_l_2325:
	/* 0x2325: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2328:
	/* 0x2328: jne    2e15 <generic_uprobe_filter_arg+0x2e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11797ULL;
	}
x86_l_232e:
	/* 0x232e: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2331:
	/* 0x2331: ja     2e0b <generic_uprobe_filter_arg+0x2e0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11787ULL;
	}
x86_l_2337:
	/* 0x2337: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_233d:
	/* 0x233d: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2341:
	/* 0x2341: jae    2e0b <generic_uprobe_filter_arg+0x2e0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11787ULL;
	}
x86_l_2347:
	/* 0x2347: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_234b:
	/* 0x234b: jl     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_2351:
	/* 0x2351: jmp    2e15 <generic_uprobe_filter_arg+0x2e15> */
	return 11797ULL;
x86_l_2356:
	/* 0x2356: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2359:
	/* 0x2359: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_235e:
	/* 0x235e: jne    2e15 <generic_uprobe_filter_arg+0x2e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11797ULL;
	}
x86_l_2364:
	/* 0x2364: test   DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2368:
	/* 0x2368: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_236e:
	/* 0x236e: jmp    2e15 <generic_uprobe_filter_arg+0x2e15> */
	return 11797ULL;
x86_l_2373:
	/* 0x2373: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2376:
	/* 0x2376: ja     2dff <generic_uprobe_filter_arg+0x2dff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11775ULL;
	}
x86_l_237c:
	/* 0x237c: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2382:
	/* 0x2382: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2386:
	/* 0x2386: jae    2dff <generic_uprobe_filter_arg+0x2dff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11775ULL;
	}
x86_l_238c:
	/* 0x238c: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2390:
	/* 0x2390: jg     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_2396:
	/* 0x2396: jmp    2e15 <generic_uprobe_filter_arg+0x2e15> */
	return 11797ULL;
x86_l_239b:
	/* 0x239b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_239e:
	/* 0x239e: je     2c63 <generic_uprobe_filter_arg+0x2c63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11363ULL;
	}
x86_l_23a4:
	/* 0x23a4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23a7:
	/* 0x23a7: jne    2c70 <generic_uprobe_filter_arg+0x2c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11376ULL;
	}
x86_l_23ad:
	/* 0x23ad: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_23b2:
	/* 0x23b2: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_23b4:
	/* 0x23b4: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_23ba:
	/* 0x23ba: jmp    2c70 <generic_uprobe_filter_arg+0x2c70> */
	return 11376ULL;
x86_l_23bf:
	/* 0x23bf: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23c2:
	/* 0x23c2: je     2ca5 <generic_uprobe_filter_arg+0x2ca5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11429ULL;
	}
x86_l_23c8:
	/* 0x23c8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23cb:
	/* 0x23cb: jne    2cb2 <generic_uprobe_filter_arg+0x2cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11442ULL;
	}
x86_l_23d1:
	/* 0x23d1: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23d6:
	/* 0x23d6: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_23d8:
	/* 0x23d8: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_23de:
	/* 0x23de: jmp    2cb2 <generic_uprobe_filter_arg+0x2cb2> */
	return 11442ULL;
x86_l_23e3:
	/* 0x23e3: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_23e8:
	/* 0x23e8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ed:
	/* 0x23ed: jmp    3746 <generic_uprobe_filter_arg+0x3746> */
	return 14150ULL;
x86_l_23f2:
	/* 0x23f2: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_23f7:
	/* 0x23f7: jmp    2405 <generic_uprobe_filter_arg+0x2405> */
	goto x86_l_2405;
x86_l_23f9:
	/* 0x23f9: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_23fe:
	/* 0x23fe: jmp    2405 <generic_uprobe_filter_arg+0x2405> */
	goto x86_l_2405;
x86_l_2400:
	/* 0x2400: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2405:
	/* 0x2405: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2407:
	/* 0x2407: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_240a:
	/* 0x240a: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_240f:
	/* 0x240f: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2412:
	/* 0x2412: je     3390 <generic_uprobe_filter_arg+0x3390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13200ULL;
	}
x86_l_2418:
	/* 0x2418: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_241c:
	/* 0x241c: mov    DWORD PTR [rsp+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2423:
	/* 0x2423: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2428:
	/* 0x2428: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_242d:
	/* 0x242d: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2434:
	/* 0x2434: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2439:
	/* 0x2439: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_243c:
	/* 0x243c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_243e:
	/* 0x243e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2441:
	/* 0x2441: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2446:
	/* 0x2446: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_244d:
	/* 0x244d: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2450:
	/* 0x2450: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2452:
	/* 0x2452: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2457:
	/* 0x2457: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_245a:
	/* 0x245a: je     3390 <generic_uprobe_filter_arg+0x3390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13200ULL;
	}
x86_l_2460:
	/* 0x2460: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_2465:
	/* 0x2465: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2468:
	/* 0x2468: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_246d:
	/* 0x246d: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2472:
	/* 0x2472: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2477:
	/* 0x2477: je     33a1 <generic_uprobe_filter_arg+0x33a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13217ULL;
	}
x86_l_247d:
	/* 0x247d: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2485:
	/* 0x2485: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_248a:
	/* 0x248a: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_248e:
	/* 0x248e: mov    ebx,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2495:
	/* 0x2495: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2498:
	/* 0x2498: jg     24de <generic_uprobe_filter_arg+0x24de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_24de;
	}
x86_l_249a:
	/* 0x249a: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_249f:
	/* 0x249f: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24a2:
	/* 0x24a2: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_24a6:
	/* 0x24a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24ab:
	/* 0x24ab: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_24ad:
	/* 0x24ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24af:
	/* 0x24af: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24b4:
	/* 0x24b4: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_24b6:
	/* 0x24b6: mov    r13d,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_24bb:
	/* 0x24bb: jbe    2523 <generic_uprobe_filter_arg+0x2523> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2523;
	}
x86_l_24bd:
	/* 0x24bd: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24c2:
	/* 0x24c2: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_24c6:
	/* 0x24c6: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_24c9:
	/* 0x24c9: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24cf:
	/* 0x24cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24d4:
	/* 0x24d4: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_24dc:
	/* 0x24dc: jmp    2521 <generic_uprobe_filter_arg+0x2521> */
	goto x86_l_2521;
x86_l_24de:
	/* 0x24de: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24e3:
	/* 0x24e3: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24e6:
	/* 0x24e6: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_24ea:
	/* 0x24ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24ef:
	/* 0x24ef: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_24f1:
	/* 0x24f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f3:
	/* 0x24f3: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24f8:
	/* 0x24f8: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_24fa:
	/* 0x24fa: mov    r13d,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_24ff:
	/* 0x24ff: jbe    2523 <generic_uprobe_filter_arg+0x2523> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2523;
	}
x86_l_2501:
	/* 0x2501: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2506:
	/* 0x2506: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_250a:
	/* 0x250a: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_250e:
	/* 0x250e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2514:
	/* 0x2514: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2519:
	/* 0x2519: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2521:
	/* 0x2521: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2523:
	/* 0x2523: mov    DWORD PTR [rsp+0x40],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2528:
	/* 0x2528: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_252b:
	/* 0x252b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2530:
	/* 0x2530: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2535:
	/* 0x2535: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_253a:
	/* 0x253a: jle    2576 <generic_uprobe_filter_arg+0x2576> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2576;
	}
x86_l_253c:
	/* 0x253c: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_253f:
	/* 0x253f: jg     2a01 <generic_uprobe_filter_arg+0x2a01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10753ULL;
	}
x86_l_2545:
	/* 0x2545: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2548:
	/* 0x2548: je     30dd <generic_uprobe_filter_arg+0x30dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12509ULL;
	}
x86_l_254e:
	/* 0x254e: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2551:
	/* 0x2551: je     30a4 <generic_uprobe_filter_arg+0x30a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12452ULL;
	}
x86_l_2557:
	/* 0x2557: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_255a:
	/* 0x255a: jne    971 <generic_uprobe_filter_arg+0x971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2417ULL;
	}
x86_l_2560:
	/* 0x2560: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2565:
	/* 0x2565: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_256a:
	/* 0x256a: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2571:
	/* 0x2571: jmp    3101 <generic_uprobe_filter_arg+0x3101> */
	return 12545ULL;
x86_l_2576:
	/* 0x2576: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2579:
	/* 0x2579: jle    2ce7 <generic_uprobe_filter_arg+0x2ce7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11495ULL;
	}
x86_l_257f:
	/* 0x257f: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_2582:
	/* 0x2582: je     30ca <generic_uprobe_filter_arg+0x30ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12490ULL;
	}
x86_l_2588:
	/* 0x2588: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_258b:
	/* 0x258b: je     3091 <generic_uprobe_filter_arg+0x3091> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12433ULL;
	}
x86_l_2591:
	/* 0x2591: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2594:
	/* 0x2594: jne    971 <generic_uprobe_filter_arg+0x971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2417ULL;
	}
x86_l_259a:
	/* 0x259a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_259f:
	/* 0x259f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25a4:
	/* 0x25a4: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_25ab:
	/* 0x25ab: jmp    3101 <generic_uprobe_filter_arg+0x3101> */
	return 12545ULL;
x86_l_25b0:
	/* 0x25b0: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_25b5:
	/* 0x25b5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25ba:
	/* 0x25ba: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25bf:
	/* 0x25bf: jmp    3746 <generic_uprobe_filter_arg+0x3746> */
	return 14150ULL;
x86_l_25c4:
	/* 0x25c4: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_25c7:
	/* 0x25c7: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_25cb:
	/* 0x25cb: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_25cd:
	/* 0x25cd: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_25d1:
	/* 0x25d1: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_25d4:
	/* 0x25d4: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_25d7:
	/* 0x25d7: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_25da:
	/* 0x25da: jb     2fa6 <generic_uprobe_filter_arg+0x2fa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12198ULL;
	}
x86_l_25e0:
	/* 0x25e0: mov    r8d,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25e5:
	/* 0x25e5: mov    edi,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_25ea:
	/* 0x25ea: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_25ed:
	/* 0x25ed: ja     2d3f <generic_uprobe_filter_arg+0x2d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11583ULL;
	}
x86_l_25f3:
	/* 0x25f3: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_25f9:
	/* 0x25f9: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_25fd:
	/* 0x25fd: jae    2d3f <generic_uprobe_filter_arg+0x2d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11583ULL;
	}
x86_l_2603:
	/* 0x2603: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2606:
	/* 0x2606: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_260a:
	/* 0x260a: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_260c:
	/* 0x260c: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_2610:
	/* 0x2610: jmp    2d4c <generic_uprobe_filter_arg+0x2d4c> */
	return 11596ULL;
x86_l_2615:
	/* 0x2615: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2617:
	/* 0x2617: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_261c:
	/* 0x261c: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_2622:
	/* 0x2622: jmp    2632 <generic_uprobe_filter_arg+0x2632> */
	goto x86_l_2632;
x86_l_2624:
	/* 0x2624: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_262a:
	/* 0x262a: jmp    2632 <generic_uprobe_filter_arg+0x2632> */
	goto x86_l_2632;
x86_l_262c:
	/* 0x262c: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_2632:
	/* 0x2632: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_2635:
	/* 0x2635: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2638:
	/* 0x2638: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_263d:
	/* 0x263d: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2640:
	/* 0x2640: je     2efc <generic_uprobe_filter_arg+0x2efc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12028ULL;
	}
x86_l_2646:
	/* 0x2646: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_264a:
	/* 0x264a: mov    QWORD PTR [rsp+0x70],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_264f:
	/* 0x264f: mov    BYTE PTR [rsp+0x98],r8b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2657:
	/* 0x2657: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_265c:
	/* 0x265c: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2661:
	/* 0x2661: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2666:
	/* 0x2666: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_266b:
	/* 0x266b: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2672:
	/* 0x2672: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2677:
	/* 0x2677: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_267a:
	/* 0x267a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_267c:
	/* 0x267c: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
	return 9855ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9855ULL: goto x86_l_267f;
	case 9860ULL: goto x86_l_2684;
	case 9867ULL: goto x86_l_268b;
	case 9870ULL: goto x86_l_268e;
	case 9872ULL: goto x86_l_2690;
	case 9875ULL: goto x86_l_2693;
	case 9881ULL: goto x86_l_2699;
	case 9886ULL: goto x86_l_269e;
	case 9889ULL: goto x86_l_26a1;
	case 9894ULL: goto x86_l_26a6;
	case 9899ULL: goto x86_l_26ab;
	case 9904ULL: goto x86_l_26b0;
	case 9910ULL: goto x86_l_26b6;
	case 9913ULL: goto x86_l_26b9;
	case 9916ULL: goto x86_l_26bc;
	case 9919ULL: goto x86_l_26bf;
	case 9923ULL: goto x86_l_26c3;
	case 9931ULL: goto x86_l_26cb;
	case 9933ULL: goto x86_l_26cd;
	case 9936ULL: goto x86_l_26d0;
	case 9944ULL: goto x86_l_26d8;
	case 9946ULL: goto x86_l_26da;
	case 9950ULL: goto x86_l_26de;
	case 9955ULL: goto x86_l_26e3;
	case 9960ULL: goto x86_l_26e8;
	case 9965ULL: goto x86_l_26ed;
	case 9968ULL: goto x86_l_26f0;
	case 9970ULL: goto x86_l_26f2;
	case 9975ULL: goto x86_l_26f7;
	case 9978ULL: goto x86_l_26fa;
	case 9980ULL: goto x86_l_26fc;
	case 9988ULL: goto x86_l_2704;
	case 9992ULL: goto x86_l_2708;
	case 9995ULL: goto x86_l_270b;
	case 10001ULL: goto x86_l_2711;
	case 10006ULL: goto x86_l_2716;
	case 10008ULL: goto x86_l_2718;
	case 10013ULL: goto x86_l_271d;
	case 10017ULL: goto x86_l_2721;
	case 10021ULL: goto x86_l_2725;
	case 10026ULL: goto x86_l_272a;
	case 10031ULL: goto x86_l_272f;
	case 10034ULL: goto x86_l_2732;
	case 10036ULL: goto x86_l_2734;
	case 10041ULL: goto x86_l_2739;
	case 10044ULL: goto x86_l_273c;
	case 10046ULL: goto x86_l_273e;
	case 10054ULL: goto x86_l_2746;
	case 10058ULL: goto x86_l_274a;
	case 10062ULL: goto x86_l_274e;
	case 10068ULL: goto x86_l_2754;
	case 10073ULL: goto x86_l_2759;
	case 10076ULL: goto x86_l_275c;
	case 10078ULL: goto x86_l_275e;
	case 10082ULL: goto x86_l_2762;
	case 10086ULL: goto x86_l_2766;
	case 10089ULL: goto x86_l_2769;
	case 10094ULL: goto x86_l_276e;
	case 10099ULL: goto x86_l_2773;
	case 10104ULL: goto x86_l_2778;
	case 10106ULL: goto x86_l_277a;
	case 10109ULL: goto x86_l_277d;
	case 10115ULL: goto x86_l_2783;
	case 10118ULL: goto x86_l_2786;
	case 10124ULL: goto x86_l_278c;
	case 10127ULL: goto x86_l_278f;
	case 10133ULL: goto x86_l_2795;
	case 10136ULL: goto x86_l_2798;
	case 10142ULL: goto x86_l_279e;
	case 10147ULL: goto x86_l_27a3;
	case 10152ULL: goto x86_l_27a8;
	case 10159ULL: goto x86_l_27af;
	case 10164ULL: goto x86_l_27b4;
	case 10167ULL: goto x86_l_27b7;
	case 10173ULL: goto x86_l_27bd;
	case 10176ULL: goto x86_l_27c0;
	case 10182ULL: goto x86_l_27c6;
	case 10185ULL: goto x86_l_27c9;
	case 10191ULL: goto x86_l_27cf;
	case 10194ULL: goto x86_l_27d2;
	case 10200ULL: goto x86_l_27d8;
	case 10205ULL: goto x86_l_27dd;
	case 10210ULL: goto x86_l_27e2;
	case 10217ULL: goto x86_l_27e9;
	case 10222ULL: goto x86_l_27ee;
	case 10224ULL: goto x86_l_27f0;
	case 10229ULL: goto x86_l_27f5;
	case 10231ULL: goto x86_l_27f7;
	case 10233ULL: goto x86_l_27f9;
	case 10239ULL: goto x86_l_27ff;
	case 10242ULL: goto x86_l_2802;
	case 10248ULL: goto x86_l_2808;
	case 10253ULL: goto x86_l_280d;
	case 10258ULL: goto x86_l_2812;
	case 10261ULL: goto x86_l_2815;
	case 10267ULL: goto x86_l_281b;
	case 10273ULL: goto x86_l_2821;
	case 10277ULL: goto x86_l_2825;
	case 10283ULL: goto x86_l_282b;
	case 10285ULL: goto x86_l_282d;
	case 10290ULL: goto x86_l_2832;
	case 10296ULL: goto x86_l_2838;
	case 10298ULL: goto x86_l_283a;
	case 10304ULL: goto x86_l_2840;
	case 10309ULL: goto x86_l_2845;
	case 10314ULL: goto x86_l_284a;
	case 10319ULL: goto x86_l_284f;
	case 10321ULL: goto x86_l_2851;
	case 10326ULL: goto x86_l_2856;
	case 10331ULL: goto x86_l_285b;
	case 10333ULL: goto x86_l_285d;
	case 10338ULL: goto x86_l_2862;
	case 10343ULL: goto x86_l_2867;
	case 10345ULL: goto x86_l_2869;
	case 10347ULL: goto x86_l_286b;
	case 10352ULL: goto x86_l_2870;
	case 10355ULL: goto x86_l_2873;
	case 10358ULL: goto x86_l_2876;
	case 10364ULL: goto x86_l_287c;
	case 10370ULL: goto x86_l_2882;
	case 10376ULL: goto x86_l_2888;
	case 10379ULL: goto x86_l_288b;
	case 10385ULL: goto x86_l_2891;
	case 10387ULL: goto x86_l_2893;
	case 10393ULL: goto x86_l_2899;
	case 10396ULL: goto x86_l_289c;
	case 10402ULL: goto x86_l_28a2;
	case 10407ULL: goto x86_l_28a7;
	case 10412ULL: goto x86_l_28ac;
	case 10415ULL: goto x86_l_28af;
	case 10419ULL: goto x86_l_28b3;
	case 10422ULL: goto x86_l_28b6;
	case 10426ULL: goto x86_l_28ba;
	case 10429ULL: goto x86_l_28bd;
	case 10432ULL: goto x86_l_28c0;
	case 10435ULL: goto x86_l_28c3;
	case 10441ULL: goto x86_l_28c9;
	case 10446ULL: goto x86_l_28ce;
	case 10451ULL: goto x86_l_28d3;
	case 10454ULL: goto x86_l_28d6;
	case 10456ULL: goto x86_l_28d8;
	case 10459ULL: goto x86_l_28db;
	case 10465ULL: goto x86_l_28e1;
	case 10468ULL: goto x86_l_28e4;
	case 10471ULL: goto x86_l_28e7;
	case 10474ULL: goto x86_l_28ea;
	case 10479ULL: goto x86_l_28ef;
	case 10482ULL: goto x86_l_28f2;
	case 10487ULL: goto x86_l_28f7;
	case 10489ULL: goto x86_l_28f9;
	case 10492ULL: goto x86_l_28fc;
	case 10498ULL: goto x86_l_2902;
	case 10501ULL: goto x86_l_2905;
	case 10507ULL: goto x86_l_290b;
	case 10512ULL: goto x86_l_2910;
	case 10517ULL: goto x86_l_2915;
	case 10520ULL: goto x86_l_2918;
	case 10522ULL: goto x86_l_291a;
	case 10525ULL: goto x86_l_291d;
	case 10531ULL: goto x86_l_2923;
	case 10534ULL: goto x86_l_2926;
	case 10540ULL: goto x86_l_292c;
	case 10543ULL: goto x86_l_292f;
	case 10549ULL: goto x86_l_2935;
	case 10554ULL: goto x86_l_293a;
	case 10558ULL: goto x86_l_293e;
	case 10564ULL: goto x86_l_2944;
	case 10566ULL: goto x86_l_2946;
	case 10570ULL: goto x86_l_294a;
	case 10576ULL: goto x86_l_2950;
	case 10579ULL: goto x86_l_2953;
	case 10585ULL: goto x86_l_2959;
	case 10590ULL: goto x86_l_295e;
	case 10593ULL: goto x86_l_2961;
	case 10595ULL: goto x86_l_2963;
	case 10598ULL: goto x86_l_2966;
	case 10601ULL: goto x86_l_2969;
	case 10603ULL: goto x86_l_296b;
	case 10607ULL: goto x86_l_296f;
	case 10612ULL: goto x86_l_2974;
	case 10618ULL: goto x86_l_297a;
	case 10623ULL: goto x86_l_297f;
	case 10626ULL: goto x86_l_2982;
	case 10632ULL: goto x86_l_2988;
	case 10635ULL: goto x86_l_298b;
	case 10641ULL: goto x86_l_2991;
	case 10644ULL: goto x86_l_2994;
	case 10646ULL: goto x86_l_2996;
	case 10649ULL: goto x86_l_2999;
	case 10655ULL: goto x86_l_299f;
	case 10659ULL: goto x86_l_29a3;
	case 10665ULL: goto x86_l_29a9;
	case 10670ULL: goto x86_l_29ae;
	case 10673ULL: goto x86_l_29b1;
	case 10678ULL: goto x86_l_29b6;
	case 10684ULL: goto x86_l_29bc;
	case 10688ULL: goto x86_l_29c0;
	case 10694ULL: goto x86_l_29c6;
	case 10699ULL: goto x86_l_29cb;
	case 10702ULL: goto x86_l_29ce;
	case 10708ULL: goto x86_l_29d4;
	case 10713ULL: goto x86_l_29d9;
	case 10715ULL: goto x86_l_29db;
	case 10721ULL: goto x86_l_29e1;
	case 10726ULL: goto x86_l_29e6;
	case 10729ULL: goto x86_l_29e9;
	case 10735ULL: goto x86_l_29ef;
	case 10740ULL: goto x86_l_29f4;
	case 10742ULL: goto x86_l_29f6;
	case 10748ULL: goto x86_l_29fc;
	case 10753ULL: goto x86_l_2a01;
	case 10756ULL: goto x86_l_2a04;
	case 10762ULL: goto x86_l_2a0a;
	case 10765ULL: goto x86_l_2a0d;
	case 10771ULL: goto x86_l_2a13;
	case 10774ULL: goto x86_l_2a16;
	case 10780ULL: goto x86_l_2a1c;
	case 10785ULL: goto x86_l_2a21;
	case 10790ULL: goto x86_l_2a26;
	case 10797ULL: goto x86_l_2a2d;
	case 10802ULL: goto x86_l_2a32;
	case 10807ULL: goto x86_l_2a37;
	case 10809ULL: goto x86_l_2a39;
	case 10814ULL: goto x86_l_2a3e;
	case 10816ULL: goto x86_l_2a40;
	case 10821ULL: goto x86_l_2a45;
	case 10823ULL: goto x86_l_2a47;
	case 10826ULL: goto x86_l_2a4a;
	case 10831ULL: goto x86_l_2a4f;
	case 10834ULL: goto x86_l_2a52;
	case 10840ULL: goto x86_l_2a58;
	case 10844ULL: goto x86_l_2a5c;
	case 10848ULL: goto x86_l_2a60;
	case 10856ULL: goto x86_l_2a68;
	case 10861ULL: goto x86_l_2a6d;
	case 10866ULL: goto x86_l_2a72;
	case 10873ULL: goto x86_l_2a79;
	case 10878ULL: goto x86_l_2a7e;
	case 10881ULL: goto x86_l_2a81;
	case 10883ULL: goto x86_l_2a83;
	case 10886ULL: goto x86_l_2a86;
	case 10891ULL: goto x86_l_2a8b;
	case 10898ULL: goto x86_l_2a92;
	case 10901ULL: goto x86_l_2a95;
	case 10903ULL: goto x86_l_2a97;
	case 10908ULL: goto x86_l_2a9c;
	case 10911ULL: goto x86_l_2a9f;
	case 10917ULL: goto x86_l_2aa5;
	case 10922ULL: goto x86_l_2aaa;
	case 10925ULL: goto x86_l_2aad;
	case 10930ULL: goto x86_l_2ab2;
	case 10935ULL: goto x86_l_2ab7;
	case 10940ULL: goto x86_l_2abc;
	case 10946ULL: goto x86_l_2ac2;
	case 10949ULL: goto x86_l_2ac5;
	case 10953ULL: goto x86_l_2ac9;
	case 10956ULL: goto x86_l_2acc;
	case 10958ULL: goto x86_l_2ace;
	case 10963ULL: goto x86_l_2ad3;
	case 10966ULL: goto x86_l_2ad6;
	case 10970ULL: goto x86_l_2ada;
	case 10975ULL: goto x86_l_2adf;
	case 10980ULL: goto x86_l_2ae4;
	case 10982ULL: goto x86_l_2ae6;
	case 10984ULL: goto x86_l_2ae8;
	case 10992ULL: goto x86_l_2af0;
	case 10994ULL: goto x86_l_2af2;
	case 10996ULL: goto x86_l_2af4;
	case 11001ULL: goto x86_l_2af9;
	case 11005ULL: goto x86_l_2afd;
	case 11008ULL: goto x86_l_2b00;
	case 11014ULL: goto x86_l_2b06;
	case 11019ULL: goto x86_l_2b0b;
	case 11022ULL: goto x86_l_2b0e;
	case 11024ULL: goto x86_l_2b10;
	case 11026ULL: goto x86_l_2b12;
	case 11031ULL: goto x86_l_2b17;
	case 11036ULL: goto x86_l_2b1c;
	case 11039ULL: goto x86_l_2b1f;
	case 11043ULL: goto x86_l_2b23;
	case 11048ULL: goto x86_l_2b28;
	case 11053ULL: goto x86_l_2b2d;
	case 11055ULL: goto x86_l_2b2f;
	case 11057ULL: goto x86_l_2b31;
	case 11065ULL: goto x86_l_2b39;
	case 11067ULL: goto x86_l_2b3b;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11078ULL: goto x86_l_2b46;
	case 11082ULL: goto x86_l_2b4a;
	case 11088ULL: goto x86_l_2b50;
	case 11093ULL: goto x86_l_2b55;
	case 11096ULL: goto x86_l_2b58;
	case 11098ULL: goto x86_l_2b5a;
	case 11102ULL: goto x86_l_2b5e;
	case 11106ULL: goto x86_l_2b62;
	case 11109ULL: goto x86_l_2b65;
	case 11114ULL: goto x86_l_2b6a;
	case 11119ULL: goto x86_l_2b6f;
	case 11121ULL: goto x86_l_2b71;
	case 11124ULL: goto x86_l_2b74;
	case 11130ULL: goto x86_l_2b7a;
	case 11133ULL: goto x86_l_2b7d;
	case 11139ULL: goto x86_l_2b83;
	case 11142ULL: goto x86_l_2b86;
	case 11148ULL: goto x86_l_2b8c;
	case 11151ULL: goto x86_l_2b8f;
	case 11157ULL: goto x86_l_2b95;
	case 11162ULL: goto x86_l_2b9a;
	case 11167ULL: goto x86_l_2b9f;
	case 11174ULL: goto x86_l_2ba6;
	case 11179ULL: goto x86_l_2bab;
	case 11182ULL: goto x86_l_2bae;
	case 11188ULL: goto x86_l_2bb4;
	case 11191ULL: goto x86_l_2bb7;
	case 11197ULL: goto x86_l_2bbd;
	case 11200ULL: goto x86_l_2bc0;
	case 11206ULL: goto x86_l_2bc6;
	case 11209ULL: goto x86_l_2bc9;
	case 11215ULL: goto x86_l_2bcf;
	case 11220ULL: goto x86_l_2bd4;
	case 11225ULL: goto x86_l_2bd9;
	case 11232ULL: goto x86_l_2be0;
	case 11237ULL: goto x86_l_2be5;
	case 11240ULL: goto x86_l_2be8;
	case 11242ULL: goto x86_l_2bea;
	case 11245ULL: goto x86_l_2bed;
	case 11251ULL: goto x86_l_2bf3;
	case 11255ULL: goto x86_l_2bf7;
	case 11261ULL: goto x86_l_2bfd;
	case 11266ULL: goto x86_l_2c02;
	case 11269ULL: goto x86_l_2c05;
	case 11275ULL: goto x86_l_2c0b;
	case 11278ULL: goto x86_l_2c0e;
	case 11284ULL: goto x86_l_2c14;
	case 11287ULL: goto x86_l_2c17;
	case 11293ULL: goto x86_l_2c1d;
	case 11298ULL: goto x86_l_2c22;
	case 11303ULL: goto x86_l_2c27;
	case 11310ULL: goto x86_l_2c2e;
	case 11315ULL: goto x86_l_2c33;
	case 11320ULL: goto x86_l_2c38;
	case 11325ULL: goto x86_l_2c3d;
	case 11330ULL: goto x86_l_2c42;
	case 11335ULL: goto x86_l_2c47;
	case 11338ULL: goto x86_l_2c4a;
	case 11344ULL: goto x86_l_2c50;
	case 11347ULL: goto x86_l_2c53;
	case 11353ULL: goto x86_l_2c59;
	case 11358ULL: goto x86_l_2c5e;
	case 11363ULL: goto x86_l_2c63;
	case 11368ULL: goto x86_l_2c68;
	case 11370ULL: goto x86_l_2c6a;
	case 11376ULL: goto x86_l_2c70;
	case 11379ULL: goto x86_l_2c73;
	case 11385ULL: goto x86_l_2c79;
	case 11390ULL: goto x86_l_2c7e;
	case 11393ULL: goto x86_l_2c81;
	case 11399ULL: goto x86_l_2c87;
	case 11402ULL: goto x86_l_2c8a;
	case 11405ULL: goto x86_l_2c8d;
	case 11411ULL: goto x86_l_2c93;
	case 11416ULL: goto x86_l_2c98;
	case 11418ULL: goto x86_l_2c9a;
	case 11424ULL: goto x86_l_2ca0;
	case 11429ULL: goto x86_l_2ca5;
	case 11434ULL: goto x86_l_2caa;
	case 11436ULL: goto x86_l_2cac;
	case 11442ULL: goto x86_l_2cb2;
	case 11445ULL: goto x86_l_2cb5;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11459ULL: goto x86_l_2cc3;
	case 11465ULL: goto x86_l_2cc9;
	case 11468ULL: goto x86_l_2ccc;
	case 11471ULL: goto x86_l_2ccf;
	case 11477ULL: goto x86_l_2cd5;
	case 11482ULL: goto x86_l_2cda;
	case 11484ULL: goto x86_l_2cdc;
	case 11490ULL: goto x86_l_2ce2;
	case 11495ULL: goto x86_l_2ce7;
	case 11497ULL: goto x86_l_2ce9;
	case 11503ULL: goto x86_l_2cef;
	case 11506ULL: goto x86_l_2cf2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_267f:
	/* 0x267f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2684:
	/* 0x2684: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_268b:
	/* 0x268b: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_268e:
	/* 0x268e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2690:
	/* 0x2690: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_2693:
	/* 0x2693: je     3390 <generic_uprobe_filter_arg+0x3390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13200ULL;
	}
x86_l_2699:
	/* 0x2699: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_269e:
	/* 0x269e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26a1:
	/* 0x26a1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26a6:
	/* 0x26a6: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26ab:
	/* 0x26ab: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26b0:
	/* 0x26b0: je     33a1 <generic_uprobe_filter_arg+0x33a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13217ULL;
	}
x86_l_26b6:
	/* 0x26b6: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_26b9:
	/* 0x26b9: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_26bc:
	/* 0x26bc: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_26bf:
	/* 0x26bf: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_26c3:
	/* 0x26c3: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_26cb:
	/* 0x26cb: jg     2718 <generic_uprobe_filter_arg+0x2718> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2718;
	}
x86_l_26cd:
	/* 0x26cd: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_26d0:
	/* 0x26d0: movzx  ecx,BYTE PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 152ULL);
x86_l_26d8:
	/* 0x26d8: mov    BYTE PTR [rax],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26da:
	/* 0x26da: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_26de:
	/* 0x26de: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26e3:
	/* 0x26e3: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26e8:
	/* 0x26e8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26ed:
	/* 0x26ed: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_26f0:
	/* 0x26f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f2:
	/* 0x26f2: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_26f7:
	/* 0x26f7: sub    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_26fa:
	/* 0x26fa: jbe    275e <generic_uprobe_filter_arg+0x275e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_275e;
	}
x86_l_26fc:
	/* 0x26fc: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2704:
	/* 0x2704: lea    rdi,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2708:
	/* 0x2708: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_270b:
	/* 0x270b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2711:
	/* 0x2711: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2716:
	/* 0x2716: jmp    2759 <generic_uprobe_filter_arg+0x2759> */
	goto x86_l_2759;
x86_l_2718:
	/* 0x2718: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_271d:
	/* 0x271d: mov    WORD PTR [rcx],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2721:
	/* 0x2721: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2725:
	/* 0x2725: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_272a:
	/* 0x272a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_272f:
	/* 0x272f: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_2732:
	/* 0x2732: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2734:
	/* 0x2734: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2739:
	/* 0x2739: sub    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_273c:
	/* 0x273c: jbe    275e <generic_uprobe_filter_arg+0x275e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_275e;
	}
x86_l_273e:
	/* 0x273e: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2746:
	/* 0x2746: lea    rdi,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_274a:
	/* 0x274a: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_274e:
	/* 0x274e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2754:
	/* 0x2754: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2759:
	/* 0x2759: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_275c:
	/* 0x275c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_275e:
	/* 0x275e: mov    eax,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2762:
	/* 0x2762: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2766:
	/* 0x2766: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2769:
	/* 0x2769: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_276e:
	/* 0x276e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2773:
	/* 0x2773: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2778:
	/* 0x2778: jle    27b4 <generic_uprobe_filter_arg+0x27b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_27b4;
	}
x86_l_277a:
	/* 0x277a: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_277d:
	/* 0x277d: jg     2c02 <generic_uprobe_filter_arg+0x2c02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2c02;
	}
x86_l_2783:
	/* 0x2783: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2786:
	/* 0x2786: je     3349 <generic_uprobe_filter_arg+0x3349> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13129ULL;
	}
x86_l_278c:
	/* 0x278c: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_278f:
	/* 0x278f: je     3310 <generic_uprobe_filter_arg+0x3310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13072ULL;
	}
x86_l_2795:
	/* 0x2795: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_2798:
	/* 0x2798: jne    2efc <generic_uprobe_filter_arg+0x2efc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12028ULL;
	}
x86_l_279e:
	/* 0x279e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27a3:
	/* 0x27a3: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27a8:
	/* 0x27a8: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_27af:
	/* 0x27af: jmp    336d <generic_uprobe_filter_arg+0x336d> */
	return 13165ULL;
x86_l_27b4:
	/* 0x27b4: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_27b7:
	/* 0x27b7: jle    2ed9 <generic_uprobe_filter_arg+0x2ed9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11993ULL;
	}
x86_l_27bd:
	/* 0x27bd: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_27c0:
	/* 0x27c0: je     3336 <generic_uprobe_filter_arg+0x3336> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13110ULL;
	}
x86_l_27c6:
	/* 0x27c6: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_27c9:
	/* 0x27c9: je     32fd <generic_uprobe_filter_arg+0x32fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13053ULL;
	}
x86_l_27cf:
	/* 0x27cf: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_27d2:
	/* 0x27d2: jne    2efc <generic_uprobe_filter_arg+0x2efc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12028ULL;
	}
x86_l_27d8:
	/* 0x27d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27dd:
	/* 0x27dd: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27e2:
	/* 0x27e2: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_27e9:
	/* 0x27e9: jmp    336d <generic_uprobe_filter_arg+0x336d> */
	return 13165ULL;
x86_l_27ee:
	/* 0x27ee: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_27f0:
	/* 0x27f0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27f5:
	/* 0x27f5: ja     27ff <generic_uprobe_filter_arg+0x27ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_27ff;
	}
x86_l_27f7:
	/* 0x27f7: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_27f9:
	/* 0x27f9: jbe    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_27ff:
	/* 0x27ff: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2802:
	/* 0x2802: jb     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 272ULL;
	}
x86_l_2808:
	/* 0x2808: mov    edi,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_280d:
	/* 0x280d: mov    esi,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2812:
	/* 0x2812: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2815:
	/* 0x2815: ja     2dad <generic_uprobe_filter_arg+0x2dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11693ULL;
	}
x86_l_281b:
	/* 0x281b: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2821:
	/* 0x2821: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2825:
	/* 0x2825: jae    2dad <generic_uprobe_filter_arg+0x2dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11693ULL;
	}
x86_l_282b:
	/* 0x282b: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_282d:
	/* 0x282d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2832:
	/* 0x2832: jg     2dbe <generic_uprobe_filter_arg+0x2dbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11710ULL;
	}
x86_l_2838:
	/* 0x2838: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_283a:
	/* 0x283a: jle    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_2840:
	/* 0x2840: jmp    2dbe <generic_uprobe_filter_arg+0x2dbe> */
	return 11710ULL;
x86_l_2845:
	/* 0x2845: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_284a:
	/* 0x284a: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_284f:
	/* 0x284f: jb     287c <generic_uprobe_filter_arg+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_287c;
	}
x86_l_2851:
	/* 0x2851: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_2856:
	/* 0x2856: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_285b:
	/* 0x285b: jb     287c <generic_uprobe_filter_arg+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_287c;
	}
x86_l_285d:
	/* 0x285d: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_2862:
	/* 0x2862: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_2867:
	/* 0x2867: jb     287c <generic_uprobe_filter_arg+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_287c;
	}
x86_l_2869:
	/* 0x2869: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_286b:
	/* 0x286b: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_2870:
	/* 0x2870: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_2873:
	/* 0x2873: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_2876:
	/* 0x2876: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_287c:
	/* 0x287c: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_2882:
	/* 0x2882: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_2888:
	/* 0x2888: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_288b:
	/* 0x288b: jg     2c47 <generic_uprobe_filter_arg+0x2c47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2c47;
	}
x86_l_2891:
	/* 0x2891: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2893:
	/* 0x2893: je     3125 <generic_uprobe_filter_arg+0x3125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12581ULL;
	}
x86_l_2899:
	/* 0x2899: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_289c:
	/* 0x289c: jne    311e <generic_uprobe_filter_arg+0x311e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12574ULL;
	}
x86_l_28a2:
	/* 0x28a2: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_28a7:
	/* 0x28a7: jmp    3131 <generic_uprobe_filter_arg+0x3131> */
	return 12593ULL;
x86_l_28ac:
	/* 0x28ac: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_28af:
	/* 0x28af: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_28b3:
	/* 0x28b3: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_28b6:
	/* 0x28b6: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_28ba:
	/* 0x28ba: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_28bd:
	/* 0x28bd: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_28c0:
	/* 0x28c0: cmp    esi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 57ULL);
x86_l_28c3:
	/* 0x28c3: jb     2fa6 <generic_uprobe_filter_arg+0x2fa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12198ULL;
	}
x86_l_28c9:
	/* 0x28c9: mov    rdi,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28ce:
	/* 0x28ce: mov    rsi,QWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_28d3:
	/* 0x28d3: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_28d6:
	/* 0x28d6: je     28e1 <generic_uprobe_filter_arg+0x28e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28e1;
	}
x86_l_28d8:
	/* 0x28d8: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_28db:
	/* 0x28db: jne    2ebf <generic_uprobe_filter_arg+0x2ebf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11967ULL;
	}
x86_l_28e1:
	/* 0x28e1: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_28e4:
	/* 0x28e4: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_28e7:
	/* 0x28e7: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_28ea:
	/* 0x28ea: jmp    2d85 <generic_uprobe_filter_arg+0x2d85> */
	return 11653ULL;
x86_l_28ef:
	/* 0x28ef: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_28f2:
	/* 0x28f2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28f7:
	/* 0x28f7: ja     2902 <generic_uprobe_filter_arg+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2902;
	}
x86_l_28f9:
	/* 0x28f9: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_28fc:
	/* 0x28fc: jbe    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_2902:
	/* 0x2902: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_2905:
	/* 0x2905: jb     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 272ULL;
	}
x86_l_290b:
	/* 0x290b: mov    rsi,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2910:
	/* 0x2910: mov    rdx,QWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2915:
	/* 0x2915: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2918:
	/* 0x2918: je     2923 <generic_uprobe_filter_arg+0x2923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2923;
	}
x86_l_291a:
	/* 0x291a: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_291d:
	/* 0x291d: jne    2f12 <generic_uprobe_filter_arg+0x2f12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12050ULL;
	}
x86_l_2923:
	/* 0x2923: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2926:
	/* 0x2926: jg     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 272ULL;
	}
x86_l_292c:
	/* 0x292c: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_292f:
	/* 0x292f: jle    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_2935:
	/* 0x2935: jmp    110 <generic_uprobe_filter_arg+0x110> */
	return 272ULL;
x86_l_293a:
	/* 0x293a: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_293e:
	/* 0x293e: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_2944:
	/* 0x2944: jmp    2950 <generic_uprobe_filter_arg+0x2950> */
	goto x86_l_2950;
x86_l_2946:
	/* 0x2946: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_294a:
	/* 0x294a: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_2950:
	/* 0x2950: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2953:
	/* 0x2953: jb     37cd <generic_uprobe_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14285ULL;
	}
x86_l_2959:
	/* 0x2959: mov    rsi,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_295e:
	/* 0x295e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2961:
	/* 0x2961: jle    297f <generic_uprobe_filter_arg+0x297f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_297f;
	}
x86_l_2963:
	/* 0x2963: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2966:
	/* 0x2966: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2969:
	/* 0x2969: jae    29ae <generic_uprobe_filter_arg+0x29ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_29ae;
	}
x86_l_296b:
	/* 0x296b: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_296f:
	/* 0x296f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2974:
	/* 0x2974: jne    2fce <generic_uprobe_filter_arg+0x2fce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12238ULL;
	}
x86_l_297a:
	/* 0x297a: jmp    366e <generic_uprobe_filter_arg+0x366e> */
	return 13934ULL;
x86_l_297f:
	/* 0x297f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2982:
	/* 0x2982: je     2be5 <generic_uprobe_filter_arg+0x2be5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2be5;
	}
x86_l_2988:
	/* 0x2988: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_298b:
	/* 0x298b: jne    2fce <generic_uprobe_filter_arg+0x2fce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12238ULL;
	}
x86_l_2991:
	/* 0x2991: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2994:
	/* 0x2994: je     299f <generic_uprobe_filter_arg+0x299f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_299f;
	}
x86_l_2996:
	/* 0x2996: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2999:
	/* 0x2999: jne    2fc4 <generic_uprobe_filter_arg+0x2fc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12228ULL;
	}
x86_l_299f:
	/* 0x299f: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29a3:
	/* 0x29a3: jl     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_29a9:
	/* 0x29a9: jmp    2fce <generic_uprobe_filter_arg+0x2fce> */
	return 12238ULL;
x86_l_29ae:
	/* 0x29ae: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_29b1:
	/* 0x29b1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29b6:
	/* 0x29b6: jne    2fce <generic_uprobe_filter_arg+0x2fce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12238ULL;
	}
x86_l_29bc:
	/* 0x29bc: test   QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29c0:
	/* 0x29c0: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_29c6:
	/* 0x29c6: jmp    2fce <generic_uprobe_filter_arg+0x2fce> */
	return 12238ULL;
x86_l_29cb:
	/* 0x29cb: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_29ce:
	/* 0x29ce: jne    2c70 <generic_uprobe_filter_arg+0x2c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c70;
	}
x86_l_29d4:
	/* 0x29d4: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_29d9:
	/* 0x29d9: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_29db:
	/* 0x29db: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_29e1:
	/* 0x29e1: jmp    2c70 <generic_uprobe_filter_arg+0x2c70> */
	goto x86_l_2c70;
x86_l_29e6:
	/* 0x29e6: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_29e9:
	/* 0x29e9: jne    2cb2 <generic_uprobe_filter_arg+0x2cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cb2;
	}
x86_l_29ef:
	/* 0x29ef: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29f4:
	/* 0x29f4: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_29f6:
	/* 0x29f6: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_29fc:
	/* 0x29fc: jmp    2cb2 <generic_uprobe_filter_arg+0x2cb2> */
	goto x86_l_2cb2;
x86_l_2a01:
	/* 0x2a01: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_2a04:
	/* 0x2a04: je     30f0 <generic_uprobe_filter_arg+0x30f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12528ULL;
	}
x86_l_2a0a:
	/* 0x2a0a: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_2a0d:
	/* 0x2a0d: je     30b7 <generic_uprobe_filter_arg+0x30b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12471ULL;
	}
x86_l_2a13:
	/* 0x2a13: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2a16:
	/* 0x2a16: jne    971 <generic_uprobe_filter_arg+0x971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2417ULL;
	}
x86_l_2a1c:
	/* 0x2a1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a21:
	/* 0x2a21: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a26:
	/* 0x2a26: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_2a2d:
	/* 0x2a2d: jmp    3101 <generic_uprobe_filter_arg+0x3101> */
	return 12545ULL;
x86_l_2a32:
	/* 0x2a32: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2a37:
	/* 0x2a37: jmp    2a45 <generic_uprobe_filter_arg+0x2a45> */
	goto x86_l_2a45;
x86_l_2a39:
	/* 0x2a39: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2a3e:
	/* 0x2a3e: jmp    2a45 <generic_uprobe_filter_arg+0x2a45> */
	goto x86_l_2a45;
x86_l_2a40:
	/* 0x2a40: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a45:
	/* 0x2a45: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2a47:
	/* 0x2a47: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2a4a:
	/* 0x2a4a: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2a4f:
	/* 0x2a4f: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2a52:
	/* 0x2a52: je     2b10 <generic_uprobe_filter_arg+0x2b10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b10;
	}
x86_l_2a58:
	/* 0x2a58: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2a5c:
	/* 0x2a5c: mov    DWORD PTR [rsp+0x70],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2a60:
	/* 0x2a60: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2a68:
	/* 0x2a68: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a6d:
	/* 0x2a6d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a72:
	/* 0x2a72: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2a79:
	/* 0x2a79: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a7e:
	/* 0x2a7e: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2a81:
	/* 0x2a81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a83:
	/* 0x2a83: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2a86:
	/* 0x2a86: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a8b:
	/* 0x2a8b: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2a92:
	/* 0x2a92: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2a95:
	/* 0x2a95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a97:
	/* 0x2a97: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a9c:
	/* 0x2a9c: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2a9f:
	/* 0x2a9f: je     3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14133ULL;
	}
x86_l_2aa5:
	/* 0x2aa5: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_2aaa:
	/* 0x2aaa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2aad:
	/* 0x2aad: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ab2:
	/* 0x2ab2: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ab7:
	/* 0x2ab7: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2abc:
	/* 0x2abc: je     3746 <generic_uprobe_filter_arg+0x3746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14150ULL;
	}
x86_l_2ac2:
	/* 0x2ac2: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2ac5:
	/* 0x2ac5: mov    ebx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2ac9:
	/* 0x2ac9: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2acc:
	/* 0x2acc: jg     2b17 <generic_uprobe_filter_arg+0x2b17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b17;
	}
x86_l_2ace:
	/* 0x2ace: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ad3:
	/* 0x2ad3: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad6:
	/* 0x2ad6: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2ada:
	/* 0x2ada: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2adf:
	/* 0x2adf: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ae4:
	/* 0x2ae4: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2ae6:
	/* 0x2ae6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae8:
	/* 0x2ae8: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2af0:
	/* 0x2af0: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2af2:
	/* 0x2af2: jbe    2b5a <generic_uprobe_filter_arg+0x2b5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2b5a;
	}
x86_l_2af4:
	/* 0x2af4: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2af9:
	/* 0x2af9: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2afd:
	/* 0x2afd: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2b00:
	/* 0x2b00: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b06:
	/* 0x2b06: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b0b:
	/* 0x2b0b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b0e:
	/* 0x2b0e: jmp    2b58 <generic_uprobe_filter_arg+0x2b58> */
	goto x86_l_2b58;
x86_l_2b10:
	/* 0x2b10: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b12:
	/* 0x2b12: jmp    3746 <generic_uprobe_filter_arg+0x3746> */
	return 14150ULL;
x86_l_2b17:
	/* 0x2b17: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b1c:
	/* 0x2b1c: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b1f:
	/* 0x2b1f: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2b23:
	/* 0x2b23: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b28:
	/* 0x2b28: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b2d:
	/* 0x2b2d: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2b2f:
	/* 0x2b2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b31:
	/* 0x2b31: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2b39:
	/* 0x2b39: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b3b:
	/* 0x2b3b: jbe    2b5a <generic_uprobe_filter_arg+0x2b5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2b5a;
	}
x86_l_2b3d:
	/* 0x2b3d: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b42:
	/* 0x2b42: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2b46:
	/* 0x2b46: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2b4a:
	/* 0x2b4a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b50:
	/* 0x2b50: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b55:
	/* 0x2b55: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b58:
	/* 0x2b58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5a:
	/* 0x2b5a: mov    eax,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2b5e:
	/* 0x2b5e: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b62:
	/* 0x2b62: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2b65:
	/* 0x2b65: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b6a:
	/* 0x2b6a: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b6f:
	/* 0x2b6f: jle    2bab <generic_uprobe_filter_arg+0x2bab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2bab;
	}
x86_l_2b71:
	/* 0x2b71: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2b74:
	/* 0x2b74: jg     2d0e <generic_uprobe_filter_arg+0x2d0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11534ULL;
	}
x86_l_2b7a:
	/* 0x2b7a: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2b7d:
	/* 0x2b7d: je     342c <generic_uprobe_filter_arg+0x342c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13356ULL;
	}
x86_l_2b83:
	/* 0x2b83: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2b86:
	/* 0x2b86: je     33f3 <generic_uprobe_filter_arg+0x33f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13299ULL;
	}
x86_l_2b8c:
	/* 0x2b8c: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2b8f:
	/* 0x2b8f: jne    2195 <generic_uprobe_filter_arg+0x2195> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8597ULL;
	}
x86_l_2b95:
	/* 0x2b95: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b9a:
	/* 0x2b9a: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b9f:
	/* 0x2b9f: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2ba6:
	/* 0x2ba6: jmp    3450 <generic_uprobe_filter_arg+0x3450> */
	return 13392ULL;
x86_l_2bab:
	/* 0x2bab: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2bae:
	/* 0x2bae: jle    2f71 <generic_uprobe_filter_arg+0x2f71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12145ULL;
	}
x86_l_2bb4:
	/* 0x2bb4: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_2bb7:
	/* 0x2bb7: je     3419 <generic_uprobe_filter_arg+0x3419> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13337ULL;
	}
x86_l_2bbd:
	/* 0x2bbd: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2bc0:
	/* 0x2bc0: je     33e0 <generic_uprobe_filter_arg+0x33e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13280ULL;
	}
x86_l_2bc6:
	/* 0x2bc6: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2bc9:
	/* 0x2bc9: jne    2195 <generic_uprobe_filter_arg+0x2195> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8597ULL;
	}
x86_l_2bcf:
	/* 0x2bcf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bd4:
	/* 0x2bd4: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bd9:
	/* 0x2bd9: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2be0:
	/* 0x2be0: jmp    3450 <generic_uprobe_filter_arg+0x3450> */
	return 13392ULL;
x86_l_2be5:
	/* 0x2be5: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2be8:
	/* 0x2be8: je     2bf3 <generic_uprobe_filter_arg+0x2bf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bf3;
	}
x86_l_2bea:
	/* 0x2bea: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2bed:
	/* 0x2bed: jne    2fb8 <generic_uprobe_filter_arg+0x2fb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12216ULL;
	}
x86_l_2bf3:
	/* 0x2bf3: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf7:
	/* 0x2bf7: jg     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_2bfd:
	/* 0x2bfd: jmp    2fce <generic_uprobe_filter_arg+0x2fce> */
	return 12238ULL;
x86_l_2c02:
	/* 0x2c02: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_2c05:
	/* 0x2c05: je     335c <generic_uprobe_filter_arg+0x335c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13148ULL;
	}
x86_l_2c0b:
	/* 0x2c0b: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_2c0e:
	/* 0x2c0e: je     3323 <generic_uprobe_filter_arg+0x3323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13091ULL;
	}
x86_l_2c14:
	/* 0x2c14: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2c17:
	/* 0x2c17: jne    2efc <generic_uprobe_filter_arg+0x2efc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12028ULL;
	}
x86_l_2c1d:
	/* 0x2c1d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c22:
	/* 0x2c22: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c27:
	/* 0x2c27: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_2c2e:
	/* 0x2c2e: jmp    336d <generic_uprobe_filter_arg+0x336d> */
	return 13165ULL;
x86_l_2c33:
	/* 0x2c33: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c38:
	/* 0x2c38: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c3d:
	/* 0x2c3d: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c42:
	/* 0x2c42: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_2c47:
	/* 0x2c47: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2c4a:
	/* 0x2c4a: je     312c <generic_uprobe_filter_arg+0x312c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12588ULL;
	}
x86_l_2c50:
	/* 0x2c50: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2c53:
	/* 0x2c53: jne    311e <generic_uprobe_filter_arg+0x311e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12574ULL;
	}
x86_l_2c59:
	/* 0x2c59: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2c5e:
	/* 0x2c5e: jmp    3131 <generic_uprobe_filter_arg+0x3131> */
	return 12593ULL;
x86_l_2c63:
	/* 0x2c63: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2c68:
	/* 0x2c68: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2c6a:
	/* 0x2c6a: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_2c70:
	/* 0x2c70: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2c73:
	/* 0x2c73: jb     37cd <generic_uprobe_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14285ULL;
	}
x86_l_2c79:
	/* 0x2c79: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c7e:
	/* 0x2c7e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c81:
	/* 0x2c81: jle    2f29 <generic_uprobe_filter_arg+0x2f29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12073ULL;
	}
x86_l_2c87:
	/* 0x2c87: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2c8a:
	/* 0x2c8a: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2c8d:
	/* 0x2c8d: jae    3048 <generic_uprobe_filter_arg+0x3048> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12360ULL;
	}
x86_l_2c93:
	/* 0x2c93: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2c98:
	/* 0x2c98: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2c9a:
	/* 0x2c9a: jne    347a <generic_uprobe_filter_arg+0x347a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13434ULL;
	}
x86_l_2ca0:
	/* 0x2ca0: jmp    366e <generic_uprobe_filter_arg+0x366e> */
	return 13934ULL;
x86_l_2ca5:
	/* 0x2ca5: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2caa:
	/* 0x2caa: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2cac:
	/* 0x2cac: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_2cb2:
	/* 0x2cb2: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2cb5:
	/* 0x2cb5: jb     37cd <generic_uprobe_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14285ULL;
	}
x86_l_2cbb:
	/* 0x2cbb: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cc0:
	/* 0x2cc0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2cc3:
	/* 0x2cc3: jle    2f4d <generic_uprobe_filter_arg+0x2f4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12109ULL;
	}
x86_l_2cc9:
	/* 0x2cc9: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2ccc:
	/* 0x2ccc: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2ccf:
	/* 0x2ccf: jae    3063 <generic_uprobe_filter_arg+0x3063> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12387ULL;
	}
x86_l_2cd5:
	/* 0x2cd5: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2cda:
	/* 0x2cda: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2cdc:
	/* 0x2cdc: jne    34c3 <generic_uprobe_filter_arg+0x34c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13507ULL;
	}
x86_l_2ce2:
	/* 0x2ce2: jmp    366e <generic_uprobe_filter_arg+0x366e> */
	return 13934ULL;
x86_l_2ce7:
	/* 0x2ce7: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_2ce9:
	/* 0x2ce9: je     307e <generic_uprobe_filter_arg+0x307e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12414ULL;
	}
x86_l_2cef:
	/* 0x2cef: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2cf2:
	/* 0x2cf2: jne    971 <generic_uprobe_filter_arg+0x971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2417ULL;
	}
	return 11512ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11512ULL: goto x86_l_2cf8;
	case 11517ULL: goto x86_l_2cfd;
	case 11522ULL: goto x86_l_2d02;
	case 11529ULL: goto x86_l_2d09;
	case 11534ULL: goto x86_l_2d0e;
	case 11537ULL: goto x86_l_2d11;
	case 11543ULL: goto x86_l_2d17;
	case 11546ULL: goto x86_l_2d1a;
	case 11552ULL: goto x86_l_2d20;
	case 11555ULL: goto x86_l_2d23;
	case 11561ULL: goto x86_l_2d29;
	case 11566ULL: goto x86_l_2d2e;
	case 11571ULL: goto x86_l_2d33;
	case 11578ULL: goto x86_l_2d3a;
	case 11583ULL: goto x86_l_2d3f;
	case 11586ULL: goto x86_l_2d42;
	case 11590ULL: goto x86_l_2d46;
	case 11592ULL: goto x86_l_2d48;
	case 11596ULL: goto x86_l_2d4c;
	case 11599ULL: goto x86_l_2d4f;
	case 11602ULL: goto x86_l_2d52;
	case 11605ULL: goto x86_l_2d55;
	case 11611ULL: goto x86_l_2d5b;
	case 11616ULL: goto x86_l_2d60;
	case 11621ULL: goto x86_l_2d65;
	case 11624ULL: goto x86_l_2d68;
	case 11630ULL: goto x86_l_2d6e;
	case 11636ULL: goto x86_l_2d74;
	case 11640ULL: goto x86_l_2d78;
	case 11646ULL: goto x86_l_2d7e;
	case 11648ULL: goto x86_l_2d80;
	case 11651ULL: goto x86_l_2d83;
	case 11653ULL: goto x86_l_2d85;
	case 11656ULL: goto x86_l_2d88;
	case 11661ULL: goto x86_l_2d8d;
	case 11663ULL: goto x86_l_2d8f;
	case 11665ULL: goto x86_l_2d91;
	case 11670ULL: goto x86_l_2d96;
	case 11675ULL: goto x86_l_2d9b;
	case 11680ULL: goto x86_l_2da0;
	case 11683ULL: goto x86_l_2da3;
	case 11688ULL: goto x86_l_2da8;
	case 11693ULL: goto x86_l_2dad;
	case 11695ULL: goto x86_l_2daf;
	case 11700ULL: goto x86_l_2db4;
	case 11702ULL: goto x86_l_2db6;
	case 11704ULL: goto x86_l_2db8;
	case 11710ULL: goto x86_l_2dbe;
	case 11713ULL: goto x86_l_2dc1;
	case 11719ULL: goto x86_l_2dc7;
	case 11724ULL: goto x86_l_2dcc;
	case 11729ULL: goto x86_l_2dd1;
	case 11732ULL: goto x86_l_2dd4;
	case 11738ULL: goto x86_l_2dda;
	case 11744ULL: goto x86_l_2de0;
	case 11748ULL: goto x86_l_2de4;
	case 11754ULL: goto x86_l_2dea;
	case 11756ULL: goto x86_l_2dec;
	case 11762ULL: goto x86_l_2df2;
	case 11764ULL: goto x86_l_2df4;
	case 11770ULL: goto x86_l_2dfa;
	case 11775ULL: goto x86_l_2dff;
	case 11779ULL: goto x86_l_2e03;
	case 11785ULL: goto x86_l_2e09;
	case 11787ULL: goto x86_l_2e0b;
	case 11791ULL: goto x86_l_2e0f;
	case 11797ULL: goto x86_l_2e15;
	case 11800ULL: goto x86_l_2e18;
	case 11806ULL: goto x86_l_2e1e;
	case 11811ULL: goto x86_l_2e23;
	case 11814ULL: goto x86_l_2e26;
	case 11816ULL: goto x86_l_2e28;
	case 11819ULL: goto x86_l_2e2b;
	case 11822ULL: goto x86_l_2e2e;
	case 11824ULL: goto x86_l_2e30;
	case 11828ULL: goto x86_l_2e34;
	case 11833ULL: goto x86_l_2e39;
	case 11839ULL: goto x86_l_2e3f;
	case 11844ULL: goto x86_l_2e44;
	case 11847ULL: goto x86_l_2e47;
	case 11849ULL: goto x86_l_2e49;
	case 11852ULL: goto x86_l_2e4c;
	case 11858ULL: goto x86_l_2e52;
	case 11861ULL: goto x86_l_2e55;
	case 11867ULL: goto x86_l_2e5b;
	case 11873ULL: goto x86_l_2e61;
	case 11877ULL: goto x86_l_2e65;
	case 11883ULL: goto x86_l_2e6b;
	case 11887ULL: goto x86_l_2e6f;
	case 11893ULL: goto x86_l_2e75;
	case 11898ULL: goto x86_l_2e7a;
	case 11901ULL: goto x86_l_2e7d;
	case 11906ULL: goto x86_l_2e82;
	case 11912ULL: goto x86_l_2e88;
	case 11916ULL: goto x86_l_2e8c;
	case 11922ULL: goto x86_l_2e92;
	case 11927ULL: goto x86_l_2e97;
	case 11930ULL: goto x86_l_2e9a;
	case 11936ULL: goto x86_l_2ea0;
	case 11942ULL: goto x86_l_2ea6;
	case 11946ULL: goto x86_l_2eaa;
	case 11952ULL: goto x86_l_2eb0;
	case 11956ULL: goto x86_l_2eb4;
	case 11962ULL: goto x86_l_2eba;
	case 11967ULL: goto x86_l_2ebf;
	case 11970ULL: goto x86_l_2ec2;
	case 11973ULL: goto x86_l_2ec5;
	case 11976ULL: goto x86_l_2ec8;
	case 11981ULL: goto x86_l_2ecd;
	case 11983ULL: goto x86_l_2ecf;
	case 11988ULL: goto x86_l_2ed4;
	case 11993ULL: goto x86_l_2ed9;
	case 11995ULL: goto x86_l_2edb;
	case 12001ULL: goto x86_l_2ee1;
	case 12004ULL: goto x86_l_2ee4;
	case 12006ULL: goto x86_l_2ee6;
	case 12011ULL: goto x86_l_2eeb;
	case 12016ULL: goto x86_l_2ef0;
	case 12023ULL: goto x86_l_2ef7;
	case 12028ULL: goto x86_l_2efc;
	case 12030ULL: goto x86_l_2efe;
	case 12035ULL: goto x86_l_2f03;
	case 12039ULL: goto x86_l_2f07;
	case 12045ULL: goto x86_l_2f0d;
	case 12050ULL: goto x86_l_2f12;
	case 12053ULL: goto x86_l_2f15;
	case 12059ULL: goto x86_l_2f1b;
	case 12062ULL: goto x86_l_2f1e;
	case 12068ULL: goto x86_l_2f24;
	case 12073ULL: goto x86_l_2f29;
	case 12076ULL: goto x86_l_2f2c;
	case 12082ULL: goto x86_l_2f32;
	case 12085ULL: goto x86_l_2f35;
	case 12091ULL: goto x86_l_2f3b;
	case 12096ULL: goto x86_l_2f40;
	case 12098ULL: goto x86_l_2f42;
	case 12104ULL: goto x86_l_2f48;
	case 12109ULL: goto x86_l_2f4d;
	case 12112ULL: goto x86_l_2f50;
	case 12118ULL: goto x86_l_2f56;
	case 12121ULL: goto x86_l_2f59;
	case 12127ULL: goto x86_l_2f5f;
	case 12132ULL: goto x86_l_2f64;
	case 12134ULL: goto x86_l_2f66;
	case 12140ULL: goto x86_l_2f6c;
	case 12145ULL: goto x86_l_2f71;
	case 12147ULL: goto x86_l_2f73;
	case 12153ULL: goto x86_l_2f79;
	case 12156ULL: goto x86_l_2f7c;
	case 12162ULL: goto x86_l_2f82;
	case 12167ULL: goto x86_l_2f87;
	case 12172ULL: goto x86_l_2f8c;
	case 12179ULL: goto x86_l_2f93;
	case 12184ULL: goto x86_l_2f98;
	case 12186ULL: goto x86_l_2f9a;
	case 12189ULL: goto x86_l_2f9d;
	case 12191ULL: goto x86_l_2f9f;
	case 12194ULL: goto x86_l_2fa2;
	case 12196ULL: goto x86_l_2fa4;
	case 12198ULL: goto x86_l_2fa6;
	case 12203ULL: goto x86_l_2fab;
	case 12205ULL: goto x86_l_2fad;
	case 12211ULL: goto x86_l_2fb3;
	case 12216ULL: goto x86_l_2fb8;
	case 12220ULL: goto x86_l_2fbc;
	case 12226ULL: goto x86_l_2fc2;
	case 12228ULL: goto x86_l_2fc4;
	case 12232ULL: goto x86_l_2fc8;
	case 12238ULL: goto x86_l_2fce;
	case 12241ULL: goto x86_l_2fd1;
	case 12247ULL: goto x86_l_2fd7;
	case 12252ULL: goto x86_l_2fdc;
	case 12255ULL: goto x86_l_2fdf;
	case 12257ULL: goto x86_l_2fe1;
	case 12260ULL: goto x86_l_2fe4;
	case 12263ULL: goto x86_l_2fe7;
	case 12265ULL: goto x86_l_2fe9;
	case 12268ULL: goto x86_l_2fec;
	case 12274ULL: goto x86_l_2ff2;
	case 12277ULL: goto x86_l_2ff5;
	case 12283ULL: goto x86_l_2ffb;
	case 12287ULL: goto x86_l_2fff;
	case 12293ULL: goto x86_l_3005;
	case 12298ULL: goto x86_l_300a;
	case 12301ULL: goto x86_l_300d;
	case 12307ULL: goto x86_l_3013;
	case 12310ULL: goto x86_l_3016;
	case 12316ULL: goto x86_l_301c;
	case 12319ULL: goto x86_l_301f;
	case 12321ULL: goto x86_l_3021;
	case 12324ULL: goto x86_l_3024;
	case 12330ULL: goto x86_l_302a;
	case 12334ULL: goto x86_l_302e;
	case 12340ULL: goto x86_l_3034;
	case 12345ULL: goto x86_l_3039;
	case 12349ULL: goto x86_l_303d;
	case 12355ULL: goto x86_l_3043;
	case 12360ULL: goto x86_l_3048;
	case 12363ULL: goto x86_l_304b;
	case 12369ULL: goto x86_l_3051;
	case 12374ULL: goto x86_l_3056;
	case 12376ULL: goto x86_l_3058;
	case 12382ULL: goto x86_l_305e;
	case 12387ULL: goto x86_l_3063;
	case 12390ULL: goto x86_l_3066;
	case 12396ULL: goto x86_l_306c;
	case 12401ULL: goto x86_l_3071;
	case 12403ULL: goto x86_l_3073;
	case 12409ULL: goto x86_l_3079;
	case 12414ULL: goto x86_l_307e;
	case 12419ULL: goto x86_l_3083;
	case 12426ULL: goto x86_l_308a;
	case 12431ULL: goto x86_l_308f;
	case 12433ULL: goto x86_l_3091;
	case 12438ULL: goto x86_l_3096;
	case 12443ULL: goto x86_l_309b;
	case 12450ULL: goto x86_l_30a2;
	case 12452ULL: goto x86_l_30a4;
	case 12457ULL: goto x86_l_30a9;
	case 12462ULL: goto x86_l_30ae;
	case 12469ULL: goto x86_l_30b5;
	case 12471ULL: goto x86_l_30b7;
	case 12476ULL: goto x86_l_30bc;
	case 12481ULL: goto x86_l_30c1;
	case 12488ULL: goto x86_l_30c8;
	case 12490ULL: goto x86_l_30ca;
	case 12495ULL: goto x86_l_30cf;
	case 12500ULL: goto x86_l_30d4;
	case 12507ULL: goto x86_l_30db;
	case 12509ULL: goto x86_l_30dd;
	case 12514ULL: goto x86_l_30e2;
	case 12519ULL: goto x86_l_30e7;
	case 12526ULL: goto x86_l_30ee;
	case 12528ULL: goto x86_l_30f0;
	case 12533ULL: goto x86_l_30f5;
	case 12538ULL: goto x86_l_30fa;
	case 12545ULL: goto x86_l_3101;
	case 12547ULL: goto x86_l_3103;
	case 12550ULL: goto x86_l_3106;
	case 12556ULL: goto x86_l_310c;
	case 12559ULL: goto x86_l_310f;
	case 12564ULL: goto x86_l_3114;
	case 12569ULL: goto x86_l_3119;
	case 12574ULL: goto x86_l_311e;
	case 12579ULL: goto x86_l_3123;
	case 12581ULL: goto x86_l_3125;
	case 12586ULL: goto x86_l_312a;
	case 12588ULL: goto x86_l_312c;
	case 12593ULL: goto x86_l_3131;
	case 12595ULL: goto x86_l_3133;
	case 12598ULL: goto x86_l_3136;
	case 12603ULL: goto x86_l_313b;
	case 12606ULL: goto x86_l_313e;
	case 12612ULL: goto x86_l_3144;
	case 12619ULL: goto x86_l_314b;
	case 12623ULL: goto x86_l_314f;
	case 12628ULL: goto x86_l_3154;
	case 12633ULL: goto x86_l_3159;
	case 12640ULL: goto x86_l_3160;
	case 12645ULL: goto x86_l_3165;
	case 12648ULL: goto x86_l_3168;
	case 12650ULL: goto x86_l_316a;
	case 12653ULL: goto x86_l_316d;
	case 12658ULL: goto x86_l_3172;
	case 12665ULL: goto x86_l_3179;
	case 12668ULL: goto x86_l_317c;
	case 12670ULL: goto x86_l_317e;
	case 12675ULL: goto x86_l_3183;
	case 12678ULL: goto x86_l_3186;
	case 12684ULL: goto x86_l_318c;
	case 12689ULL: goto x86_l_3191;
	case 12692ULL: goto x86_l_3194;
	case 12697ULL: goto x86_l_3199;
	case 12702ULL: goto x86_l_319e;
	case 12707ULL: goto x86_l_31a3;
	case 12713ULL: goto x86_l_31a9;
	case 12716ULL: goto x86_l_31ac;
	case 12720ULL: goto x86_l_31b0;
	case 12723ULL: goto x86_l_31b3;
	case 12725ULL: goto x86_l_31b5;
	case 12730ULL: goto x86_l_31ba;
	case 12733ULL: goto x86_l_31bd;
	case 12737ULL: goto x86_l_31c1;
	case 12742ULL: goto x86_l_31c6;
	case 12747ULL: goto x86_l_31cb;
	case 12749ULL: goto x86_l_31cd;
	case 12751ULL: goto x86_l_31cf;
	case 12756ULL: goto x86_l_31d4;
	case 12758ULL: goto x86_l_31d6;
	case 12760ULL: goto x86_l_31d8;
	case 12765ULL: goto x86_l_31dd;
	case 12769ULL: goto x86_l_31e1;
	case 12772ULL: goto x86_l_31e4;
	case 12778ULL: goto x86_l_31ea;
	case 12783ULL: goto x86_l_31ef;
	case 12786ULL: goto x86_l_31f2;
	case 12788ULL: goto x86_l_31f4;
	case 12793ULL: goto x86_l_31f9;
	case 12796ULL: goto x86_l_31fc;
	case 12800ULL: goto x86_l_3200;
	case 12805ULL: goto x86_l_3205;
	case 12810ULL: goto x86_l_320a;
	case 12812ULL: goto x86_l_320c;
	case 12814ULL: goto x86_l_320e;
	case 12819ULL: goto x86_l_3213;
	case 12821ULL: goto x86_l_3215;
	case 12823ULL: goto x86_l_3217;
	case 12828ULL: goto x86_l_321c;
	case 12832ULL: goto x86_l_3220;
	case 12836ULL: goto x86_l_3224;
	case 12842ULL: goto x86_l_322a;
	case 12847ULL: goto x86_l_322f;
	case 12850ULL: goto x86_l_3232;
	case 12852ULL: goto x86_l_3234;
	case 12859ULL: goto x86_l_323b;
	case 12863ULL: goto x86_l_323f;
	case 12866ULL: goto x86_l_3242;
	case 12868ULL: goto x86_l_3244;
	case 12871ULL: goto x86_l_3247;
	case 12877ULL: goto x86_l_324d;
	case 12880ULL: goto x86_l_3250;
	case 12886ULL: goto x86_l_3256;
	case 12889ULL: goto x86_l_3259;
	case 12895ULL: goto x86_l_325f;
	case 12898ULL: goto x86_l_3262;
	case 12904ULL: goto x86_l_3268;
	case 12909ULL: goto x86_l_326d;
	case 12914ULL: goto x86_l_3272;
	case 12921ULL: goto x86_l_3279;
	case 12926ULL: goto x86_l_327e;
	case 12929ULL: goto x86_l_3281;
	case 12935ULL: goto x86_l_3287;
	case 12938ULL: goto x86_l_328a;
	case 12944ULL: goto x86_l_3290;
	case 12947ULL: goto x86_l_3293;
	case 12953ULL: goto x86_l_3299;
	case 12956ULL: goto x86_l_329c;
	case 12962ULL: goto x86_l_32a2;
	case 12967ULL: goto x86_l_32a7;
	case 12972ULL: goto x86_l_32ac;
	case 12979ULL: goto x86_l_32b3;
	case 12984ULL: goto x86_l_32b8;
	case 12986ULL: goto x86_l_32ba;
	case 12992ULL: goto x86_l_32c0;
	case 12994ULL: goto x86_l_32c2;
	case 13000ULL: goto x86_l_32c8;
	case 13005ULL: goto x86_l_32cd;
	case 13008ULL: goto x86_l_32d0;
	case 13010ULL: goto x86_l_32d2;
	case 13013ULL: goto x86_l_32d5;
	case 13019ULL: goto x86_l_32db;
	case 13023ULL: goto x86_l_32df;
	case 13029ULL: goto x86_l_32e5;
	case 13034ULL: goto x86_l_32ea;
	case 13039ULL: goto x86_l_32ef;
	case 13046ULL: goto x86_l_32f6;
	case 13051ULL: goto x86_l_32fb;
	case 13053ULL: goto x86_l_32fd;
	case 13058ULL: goto x86_l_3302;
	case 13063ULL: goto x86_l_3307;
	case 13070ULL: goto x86_l_330e;
	case 13072ULL: goto x86_l_3310;
	case 13077ULL: goto x86_l_3315;
	case 13082ULL: goto x86_l_331a;
	case 13089ULL: goto x86_l_3321;
	case 13091ULL: goto x86_l_3323;
	case 13096ULL: goto x86_l_3328;
	case 13101ULL: goto x86_l_332d;
	case 13108ULL: goto x86_l_3334;
	case 13110ULL: goto x86_l_3336;
	case 13115ULL: goto x86_l_333b;
	case 13120ULL: goto x86_l_3340;
	case 13127ULL: goto x86_l_3347;
	case 13129ULL: goto x86_l_3349;
	case 13134ULL: goto x86_l_334e;
	case 13139ULL: goto x86_l_3353;
	case 13146ULL: goto x86_l_335a;
	case 13148ULL: goto x86_l_335c;
	case 13153ULL: goto x86_l_3361;
	case 13158ULL: goto x86_l_3366;
	case 13165ULL: goto x86_l_336d;
	case 13167ULL: goto x86_l_336f;
	case 13170ULL: goto x86_l_3372;
	case 13172ULL: goto x86_l_3374;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2cf8:
	/* 0x2cf8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cfd:
	/* 0x2cfd: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d02:
	/* 0x2d02: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2d09:
	/* 0x2d09: jmp    3101 <generic_uprobe_filter_arg+0x3101> */
	goto x86_l_3101;
x86_l_2d0e:
	/* 0x2d0e: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_2d11:
	/* 0x2d11: je     343f <generic_uprobe_filter_arg+0x343f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13375ULL;
	}
x86_l_2d17:
	/* 0x2d17: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_2d1a:
	/* 0x2d1a: je     3406 <generic_uprobe_filter_arg+0x3406> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13318ULL;
	}
x86_l_2d20:
	/* 0x2d20: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2d23:
	/* 0x2d23: jne    2195 <generic_uprobe_filter_arg+0x2195> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8597ULL;
	}
x86_l_2d29:
	/* 0x2d29: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d2e:
	/* 0x2d2e: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d33:
	/* 0x2d33: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_2d3a:
	/* 0x2d3a: jmp    3450 <generic_uprobe_filter_arg+0x3450> */
	return 13392ULL;
x86_l_2d3f:
	/* 0x2d3f: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2d42:
	/* 0x2d42: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2d46:
	/* 0x2d46: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2d48:
	/* 0x2d48: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2d4c:
	/* 0x2d4c: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2d4f:
	/* 0x2d4f: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2d52:
	/* 0x2d52: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_2d55:
	/* 0x2d55: jb     2fa6 <generic_uprobe_filter_arg+0x2fa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2fa6;
	}
x86_l_2d5b:
	/* 0x2d5b: mov    edi,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d60:
	/* 0x2d60: mov    esi,DWORD PTR [r12+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2d65:
	/* 0x2d65: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2d68:
	/* 0x2d68: ja     2f98 <generic_uprobe_filter_arg+0x2f98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f98;
	}
x86_l_2d6e:
	/* 0x2d6e: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2d74:
	/* 0x2d74: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2d78:
	/* 0x2d78: jae    2f98 <generic_uprobe_filter_arg+0x2f98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2f98;
	}
x86_l_2d7e:
	/* 0x2d7e: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2d80:
	/* 0x2d80: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_2d83:
	/* 0x2d83: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2d85:
	/* 0x2d85: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_2d88:
	/* 0x2d88: jmp    2fa2 <generic_uprobe_filter_arg+0x2fa2> */
	goto x86_l_2fa2;
x86_l_2d8d:
	/* 0x2d8d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d8f:
	/* 0x2d8f: jmp    2d96 <generic_uprobe_filter_arg+0x2d96> */
	goto x86_l_2d96;
x86_l_2d91:
	/* 0x2d91: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2d96:
	/* 0x2d96: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d9b:
	/* 0x2d9b: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2da0:
	/* 0x2da0: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_2da3:
	/* 0x2da3: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2da8:
	/* 0x2da8: jmp    3746 <generic_uprobe_filter_arg+0x3746> */
	return 14150ULL;
x86_l_2dad:
	/* 0x2dad: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2daf:
	/* 0x2daf: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2db4:
	/* 0x2db4: ja     2dbe <generic_uprobe_filter_arg+0x2dbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2dbe;
	}
x86_l_2db6:
	/* 0x2db6: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_2db8:
	/* 0x2db8: jbe    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_2dbe:
	/* 0x2dbe: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2dc1:
	/* 0x2dc1: jb     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 272ULL;
	}
x86_l_2dc7:
	/* 0x2dc7: mov    esi,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2dcc:
	/* 0x2dcc: mov    edx,DWORD PTR [r12+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2dd1:
	/* 0x2dd1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2dd4:
	/* 0x2dd4: ja     32b8 <generic_uprobe_filter_arg+0x32b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_32b8;
	}
x86_l_2dda:
	/* 0x2dda: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2de0:
	/* 0x2de0: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2de4:
	/* 0x2de4: jae    32b8 <generic_uprobe_filter_arg+0x32b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_32b8;
	}
x86_l_2dea:
	/* 0x2dea: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2dec:
	/* 0x2dec: jg     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 272ULL;
	}
x86_l_2df2:
	/* 0x2df2: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2df4:
	/* 0x2df4: jle    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_2dfa:
	/* 0x2dfa: jmp    110 <generic_uprobe_filter_arg+0x110> */
	return 272ULL;
x86_l_2dff:
	/* 0x2dff: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e03:
	/* 0x2e03: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_2e09:
	/* 0x2e09: jmp    2e15 <generic_uprobe_filter_arg+0x2e15> */
	goto x86_l_2e15;
x86_l_2e0b:
	/* 0x2e0b: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e0f:
	/* 0x2e0f: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_2e15:
	/* 0x2e15: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2e18:
	/* 0x2e18: jb     37cd <generic_uprobe_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14285ULL;
	}
x86_l_2e1e:
	/* 0x2e1e: mov    esi,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e23:
	/* 0x2e23: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e26:
	/* 0x2e26: jle    2e44 <generic_uprobe_filter_arg+0x2e44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e44;
	}
x86_l_2e28:
	/* 0x2e28: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2e2b:
	/* 0x2e2b: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2e2e:
	/* 0x2e2e: jae    2e7a <generic_uprobe_filter_arg+0x2e7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2e7a;
	}
x86_l_2e30:
	/* 0x2e30: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e34:
	/* 0x2e34: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e39:
	/* 0x2e39: jne    3551 <generic_uprobe_filter_arg+0x3551> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13649ULL;
	}
x86_l_2e3f:
	/* 0x2e3f: jmp    366e <generic_uprobe_filter_arg+0x366e> */
	return 13934ULL;
x86_l_2e44:
	/* 0x2e44: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e47:
	/* 0x2e47: je     2e97 <generic_uprobe_filter_arg+0x2e97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e97;
	}
x86_l_2e49:
	/* 0x2e49: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e4c:
	/* 0x2e4c: jne    3551 <generic_uprobe_filter_arg+0x3551> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13649ULL;
	}
x86_l_2e52:
	/* 0x2e52: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2e55:
	/* 0x2e55: ja     3547 <generic_uprobe_filter_arg+0x3547> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13639ULL;
	}
x86_l_2e5b:
	/* 0x2e5b: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2e61:
	/* 0x2e61: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2e65:
	/* 0x2e65: jae    3547 <generic_uprobe_filter_arg+0x3547> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13639ULL;
	}
x86_l_2e6b:
	/* 0x2e6b: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e6f:
	/* 0x2e6f: jl     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_2e75:
	/* 0x2e75: jmp    3551 <generic_uprobe_filter_arg+0x3551> */
	return 13649ULL;
x86_l_2e7a:
	/* 0x2e7a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2e7d:
	/* 0x2e7d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e82:
	/* 0x2e82: jne    3551 <generic_uprobe_filter_arg+0x3551> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13649ULL;
	}
x86_l_2e88:
	/* 0x2e88: test   DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e8c:
	/* 0x2e8c: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_2e92:
	/* 0x2e92: jmp    3551 <generic_uprobe_filter_arg+0x3551> */
	return 13649ULL;
x86_l_2e97:
	/* 0x2e97: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2e9a:
	/* 0x2e9a: ja     353b <generic_uprobe_filter_arg+0x353b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13627ULL;
	}
x86_l_2ea0:
	/* 0x2ea0: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2ea6:
	/* 0x2ea6: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2eaa:
	/* 0x2eaa: jae    353b <generic_uprobe_filter_arg+0x353b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13627ULL;
	}
x86_l_2eb0:
	/* 0x2eb0: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eb4:
	/* 0x2eb4: jg     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_2eba:
	/* 0x2eba: jmp    3551 <generic_uprobe_filter_arg+0x3551> */
	return 13649ULL;
x86_l_2ebf:
	/* 0x2ebf: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2ec2:
	/* 0x2ec2: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2ec5:
	/* 0x2ec5: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_2ec8:
	/* 0x2ec8: jmp    2f9f <generic_uprobe_filter_arg+0x2f9f> */
	goto x86_l_2f9f;
x86_l_2ecd:
	/* 0x2ecd: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ecf:
	/* 0x2ecf: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2ed4:
	/* 0x2ed4: jmp    3746 <generic_uprobe_filter_arg+0x3746> */
	return 14150ULL;
x86_l_2ed9:
	/* 0x2ed9: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_2edb:
	/* 0x2edb: je     32ea <generic_uprobe_filter_arg+0x32ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ea;
	}
x86_l_2ee1:
	/* 0x2ee1: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2ee4:
	/* 0x2ee4: jne    2efc <generic_uprobe_filter_arg+0x2efc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2efc;
	}
x86_l_2ee6:
	/* 0x2ee6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2eeb:
	/* 0x2eeb: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ef0:
	/* 0x2ef0: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2ef7:
	/* 0x2ef7: jmp    336d <generic_uprobe_filter_arg+0x336d> */
	goto x86_l_336d;
x86_l_2efc:
	/* 0x2efc: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2efe:
	/* 0x2efe: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f03:
	/* 0x2f03: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2f07:
	/* 0x2f07: jbe    33b0 <generic_uprobe_filter_arg+0x33b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13232ULL;
	}
x86_l_2f0d:
	/* 0x2f0d: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_2f12:
	/* 0x2f12: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2f15:
	/* 0x2f15: ja     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 272ULL;
	}
x86_l_2f1b:
	/* 0x2f1b: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2f1e:
	/* 0x2f1e: jbe    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_2f24:
	/* 0x2f24: jmp    110 <generic_uprobe_filter_arg+0x110> */
	return 272ULL;
x86_l_2f29:
	/* 0x2f29: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f2c:
	/* 0x2f2c: je     346d <generic_uprobe_filter_arg+0x346d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13421ULL;
	}
x86_l_2f32:
	/* 0x2f32: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f35:
	/* 0x2f35: jne    347a <generic_uprobe_filter_arg+0x347a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13434ULL;
	}
x86_l_2f3b:
	/* 0x2f3b: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2f40:
	/* 0x2f40: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2f42:
	/* 0x2f42: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_2f48:
	/* 0x2f48: jmp    347a <generic_uprobe_filter_arg+0x347a> */
	return 13434ULL;
x86_l_2f4d:
	/* 0x2f4d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f50:
	/* 0x2f50: je     34b6 <generic_uprobe_filter_arg+0x34b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13494ULL;
	}
x86_l_2f56:
	/* 0x2f56: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f59:
	/* 0x2f59: jne    34c3 <generic_uprobe_filter_arg+0x34c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13507ULL;
	}
x86_l_2f5f:
	/* 0x2f5f: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f64:
	/* 0x2f64: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2f66:
	/* 0x2f66: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_2f6c:
	/* 0x2f6c: jmp    34c3 <generic_uprobe_filter_arg+0x34c3> */
	return 13507ULL;
x86_l_2f71:
	/* 0x2f71: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_2f73:
	/* 0x2f73: je     33cd <generic_uprobe_filter_arg+0x33cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13261ULL;
	}
x86_l_2f79:
	/* 0x2f79: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2f7c:
	/* 0x2f7c: jne    2195 <generic_uprobe_filter_arg+0x2195> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8597ULL;
	}
x86_l_2f82:
	/* 0x2f82: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f87:
	/* 0x2f87: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f8c:
	/* 0x2f8c: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2f93:
	/* 0x2f93: jmp    3450 <generic_uprobe_filter_arg+0x3450> */
	return 13392ULL;
x86_l_2f98:
	/* 0x2f98: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2f9a:
	/* 0x2f9a: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2f9d:
	/* 0x2f9d: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2f9f:
	/* 0x2f9f: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_2fa2:
	/* 0x2fa2: and    dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2fa4:
	/* 0x2fa4: or     al,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2fa6:
	/* 0x2fa6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fab:
	/* 0x2fab: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2fad:
	/* 0x2fad: je     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 716ULL;
	}
x86_l_2fb3:
	/* 0x2fb3: jmp    110 <generic_uprobe_filter_arg+0x110> */
	return 272ULL;
x86_l_2fb8:
	/* 0x2fb8: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fbc:
	/* 0x2fbc: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_2fc2:
	/* 0x2fc2: jmp    2fce <generic_uprobe_filter_arg+0x2fce> */
	goto x86_l_2fce;
x86_l_2fc4:
	/* 0x2fc4: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc8:
	/* 0x2fc8: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_2fce:
	/* 0x2fce: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2fd1:
	/* 0x2fd1: jb     37cd <generic_uprobe_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14285ULL;
	}
x86_l_2fd7:
	/* 0x2fd7: mov    rdx,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2fdc:
	/* 0x2fdc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2fdf:
	/* 0x2fdf: jle    300a <generic_uprobe_filter_arg+0x300a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_300a;
	}
x86_l_2fe1:
	/* 0x2fe1: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2fe4:
	/* 0x2fe4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2fe7:
	/* 0x2fe7: jb     3039 <generic_uprobe_filter_arg+0x3039> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3039;
	}
x86_l_2fe9:
	/* 0x2fe9: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2fec:
	/* 0x2fec: je     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 716ULL;
	}
x86_l_2ff2:
	/* 0x2ff2: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2ff5:
	/* 0x2ff5: jne    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_2ffb:
	/* 0x2ffb: test   QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fff:
	/* 0x2fff: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_3005:
	/* 0x3005: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	return 14285ULL;
x86_l_300a:
	/* 0x300a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_300d:
	/* 0x300d: je     32cd <generic_uprobe_filter_arg+0x32cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32cd;
	}
x86_l_3013:
	/* 0x3013: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3016:
	/* 0x3016: jne    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_301c:
	/* 0x301c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_301f:
	/* 0x301f: je     302a <generic_uprobe_filter_arg+0x302a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_302a;
	}
x86_l_3021:
	/* 0x3021: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_3024:
	/* 0x3024: jne    367b <generic_uprobe_filter_arg+0x367b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13947ULL;
	}
x86_l_302a:
	/* 0x302a: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_302e:
	/* 0x302e: jl     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_3034:
	/* 0x3034: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	return 14285ULL;
x86_l_3039:
	/* 0x3039: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_303d:
	/* 0x303d: je     366e <generic_uprobe_filter_arg+0x366e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13934ULL;
	}
x86_l_3043:
	/* 0x3043: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	return 14285ULL;
x86_l_3048:
	/* 0x3048: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_304b:
	/* 0x304b: jne    347a <generic_uprobe_filter_arg+0x347a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13434ULL;
	}
x86_l_3051:
	/* 0x3051: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3056:
	/* 0x3056: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_3058:
	/* 0x3058: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_305e:
	/* 0x305e: jmp    347a <generic_uprobe_filter_arg+0x347a> */
	return 13434ULL;
x86_l_3063:
	/* 0x3063: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3066:
	/* 0x3066: jne    34c3 <generic_uprobe_filter_arg+0x34c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13507ULL;
	}
x86_l_306c:
	/* 0x306c: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3071:
	/* 0x3071: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_3073:
	/* 0x3073: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_3079:
	/* 0x3079: jmp    34c3 <generic_uprobe_filter_arg+0x34c3> */
	return 13507ULL;
x86_l_307e:
	/* 0x307e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3083:
	/* 0x3083: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_308a:
	/* 0x308a: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_308f:
	/* 0x308f: jmp    3101 <generic_uprobe_filter_arg+0x3101> */
	goto x86_l_3101;
x86_l_3091:
	/* 0x3091: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3096:
	/* 0x3096: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_309b:
	/* 0x309b: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_30a2:
	/* 0x30a2: jmp    3101 <generic_uprobe_filter_arg+0x3101> */
	goto x86_l_3101;
x86_l_30a4:
	/* 0x30a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30a9:
	/* 0x30a9: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30ae:
	/* 0x30ae: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_30b5:
	/* 0x30b5: jmp    3101 <generic_uprobe_filter_arg+0x3101> */
	goto x86_l_3101;
x86_l_30b7:
	/* 0x30b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30bc:
	/* 0x30bc: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30c1:
	/* 0x30c1: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_30c8:
	/* 0x30c8: jmp    3101 <generic_uprobe_filter_arg+0x3101> */
	goto x86_l_3101;
x86_l_30ca:
	/* 0x30ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30cf:
	/* 0x30cf: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30d4:
	/* 0x30d4: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_30db:
	/* 0x30db: jmp    3101 <generic_uprobe_filter_arg+0x3101> */
	goto x86_l_3101;
x86_l_30dd:
	/* 0x30dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30e2:
	/* 0x30e2: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30e7:
	/* 0x30e7: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_30ee:
	/* 0x30ee: jmp    3101 <generic_uprobe_filter_arg+0x3101> */
	goto x86_l_3101;
x86_l_30f0:
	/* 0x30f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30f5:
	/* 0x30f5: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30fa:
	/* 0x30fa: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_3101:
	/* 0x3101: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3103:
	/* 0x3103: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3106:
	/* 0x3106: je     3390 <generic_uprobe_filter_arg+0x3390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13200ULL;
	}
x86_l_310c:
	/* 0x310c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_310f:
	/* 0x310f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3114:
	/* 0x3114: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3119:
	/* 0x3119: jmp    3384 <generic_uprobe_filter_arg+0x3384> */
	return 13188ULL;
x86_l_311e:
	/* 0x311e: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_3123:
	/* 0x3123: jmp    3131 <generic_uprobe_filter_arg+0x3131> */
	goto x86_l_3131;
x86_l_3125:
	/* 0x3125: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_312a:
	/* 0x312a: jmp    3131 <generic_uprobe_filter_arg+0x3131> */
	goto x86_l_3131;
x86_l_312c:
	/* 0x312c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3131:
	/* 0x3131: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_3133:
	/* 0x3133: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_3136:
	/* 0x3136: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_313b:
	/* 0x313b: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_313e:
	/* 0x313e: je     3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14133ULL;
	}
x86_l_3144:
	/* 0x3144: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_314b:
	/* 0x314b: mov    DWORD PTR [rsp+0x6c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_314f:
	/* 0x314f: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3154:
	/* 0x3154: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3159:
	/* 0x3159: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_3160:
	/* 0x3160: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3165:
	/* 0x3165: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_3168:
	/* 0x3168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_316a:
	/* 0x316a: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_316d:
	/* 0x316d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3172:
	/* 0x3172: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3179:
	/* 0x3179: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_317c:
	/* 0x317c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_317e:
	/* 0x317e: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3183:
	/* 0x3183: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3186:
	/* 0x3186: je     3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14133ULL;
	}
x86_l_318c:
	/* 0x318c: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_3191:
	/* 0x3191: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3194:
	/* 0x3194: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3199:
	/* 0x3199: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_319e:
	/* 0x319e: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31a3:
	/* 0x31a3: je     3746 <generic_uprobe_filter_arg+0x3746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14150ULL;
	}
x86_l_31a9:
	/* 0x31a9: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_31ac:
	/* 0x31ac: mov    ebx,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_31b0:
	/* 0x31b0: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_31b3:
	/* 0x31b3: jg     31f4 <generic_uprobe_filter_arg+0x31f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_31f4;
	}
x86_l_31b5:
	/* 0x31b5: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31ba:
	/* 0x31ba: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31bd:
	/* 0x31bd: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_31c1:
	/* 0x31c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31c6:
	/* 0x31c6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31cb:
	/* 0x31cb: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_31cd:
	/* 0x31cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31cf:
	/* 0x31cf: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_31d4:
	/* 0x31d4: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31d6:
	/* 0x31d6: jbe    3234 <generic_uprobe_filter_arg+0x3234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3234;
	}
x86_l_31d8:
	/* 0x31d8: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31dd:
	/* 0x31dd: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_31e1:
	/* 0x31e1: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_31e4:
	/* 0x31e4: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_31ea:
	/* 0x31ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31ef:
	/* 0x31ef: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_31f2:
	/* 0x31f2: jmp    3232 <generic_uprobe_filter_arg+0x3232> */
	goto x86_l_3232;
x86_l_31f4:
	/* 0x31f4: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31f9:
	/* 0x31f9: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31fc:
	/* 0x31fc: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3200:
	/* 0x3200: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3205:
	/* 0x3205: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_320a:
	/* 0x320a: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_320c:
	/* 0x320c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_320e:
	/* 0x320e: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3213:
	/* 0x3213: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3215:
	/* 0x3215: jbe    3234 <generic_uprobe_filter_arg+0x3234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3234;
	}
x86_l_3217:
	/* 0x3217: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_321c:
	/* 0x321c: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3220:
	/* 0x3220: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3224:
	/* 0x3224: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_322a:
	/* 0x322a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_322f:
	/* 0x322f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3232:
	/* 0x3232: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3234:
	/* 0x3234: mov    eax,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_323b:
	/* 0x323b: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_323f:
	/* 0x323f: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3242:
	/* 0x3242: jle    327e <generic_uprobe_filter_arg+0x327e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_327e;
	}
x86_l_3244:
	/* 0x3244: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_3247:
	/* 0x3247: jg     350a <generic_uprobe_filter_arg+0x350a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13578ULL;
	}
x86_l_324d:
	/* 0x324d: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_3250:
	/* 0x3250: je     36f8 <generic_uprobe_filter_arg+0x36f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14072ULL;
	}
x86_l_3256:
	/* 0x3256: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3259:
	/* 0x3259: je     36bf <generic_uprobe_filter_arg+0x36bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14015ULL;
	}
x86_l_325f:
	/* 0x325f: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_3262:
	/* 0x3262: jne    3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14133ULL;
	}
x86_l_3268:
	/* 0x3268: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_326d:
	/* 0x326d: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3272:
	/* 0x3272: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_3279:
	/* 0x3279: jmp    371c <generic_uprobe_filter_arg+0x371c> */
	return 14108ULL;
x86_l_327e:
	/* 0x327e: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3281:
	/* 0x3281: jle    35f6 <generic_uprobe_filter_arg+0x35f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 13814ULL;
	}
x86_l_3287:
	/* 0x3287: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_328a:
	/* 0x328a: je     36e5 <generic_uprobe_filter_arg+0x36e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14053ULL;
	}
x86_l_3290:
	/* 0x3290: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_3293:
	/* 0x3293: je     36ac <generic_uprobe_filter_arg+0x36ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13996ULL;
	}
x86_l_3299:
	/* 0x3299: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_329c:
	/* 0x329c: jne    3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14133ULL;
	}
x86_l_32a2:
	/* 0x32a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32a7:
	/* 0x32a7: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_32ac:
	/* 0x32ac: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_32b3:
	/* 0x32b3: jmp    371c <generic_uprobe_filter_arg+0x371c> */
	return 14108ULL;
x86_l_32b8:
	/* 0x32b8: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_32ba:
	/* 0x32ba: ja     110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 272ULL;
	}
x86_l_32c0:
	/* 0x32c0: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_32c2:
	/* 0x32c2: jbe    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_32c8:
	/* 0x32c8: jmp    110 <generic_uprobe_filter_arg+0x110> */
	return 272ULL;
x86_l_32cd:
	/* 0x32cd: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_32d0:
	/* 0x32d0: je     32db <generic_uprobe_filter_arg+0x32db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32db;
	}
x86_l_32d2:
	/* 0x32d2: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_32d5:
	/* 0x32d5: jne    368a <generic_uprobe_filter_arg+0x368a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13962ULL;
	}
x86_l_32db:
	/* 0x32db: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32df:
	/* 0x32df: jg     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_32e5:
	/* 0x32e5: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	return 14285ULL;
x86_l_32ea:
	/* 0x32ea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32ef:
	/* 0x32ef: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_32f6:
	/* 0x32f6: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_32fb:
	/* 0x32fb: jmp    336d <generic_uprobe_filter_arg+0x336d> */
	goto x86_l_336d;
x86_l_32fd:
	/* 0x32fd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3302:
	/* 0x3302: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3307:
	/* 0x3307: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_330e:
	/* 0x330e: jmp    336d <generic_uprobe_filter_arg+0x336d> */
	goto x86_l_336d;
x86_l_3310:
	/* 0x3310: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3315:
	/* 0x3315: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_331a:
	/* 0x331a: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_3321:
	/* 0x3321: jmp    336d <generic_uprobe_filter_arg+0x336d> */
	goto x86_l_336d;
x86_l_3323:
	/* 0x3323: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3328:
	/* 0x3328: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_332d:
	/* 0x332d: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_3334:
	/* 0x3334: jmp    336d <generic_uprobe_filter_arg+0x336d> */
	goto x86_l_336d;
x86_l_3336:
	/* 0x3336: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_333b:
	/* 0x333b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3340:
	/* 0x3340: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3347:
	/* 0x3347: jmp    336d <generic_uprobe_filter_arg+0x336d> */
	goto x86_l_336d;
x86_l_3349:
	/* 0x3349: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_334e:
	/* 0x334e: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3353:
	/* 0x3353: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_335a:
	/* 0x335a: jmp    336d <generic_uprobe_filter_arg+0x336d> */
	goto x86_l_336d;
x86_l_335c:
	/* 0x335c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3361:
	/* 0x3361: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3366:
	/* 0x3366: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_336d:
	/* 0x336d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_336f:
	/* 0x336f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3372:
	/* 0x3372: je     3390 <generic_uprobe_filter_arg+0x3390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13200ULL;
	}
x86_l_3374:
	/* 0x3374: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
	return 13175ULL;
}

static __noinline __u64 tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13175ULL: goto x86_l_3377;
	case 13180ULL: goto x86_l_337c;
	case 13188ULL: goto x86_l_3384;
	case 13190ULL: goto x86_l_3386;
	case 13192ULL: goto x86_l_3388;
	case 13195ULL: goto x86_l_338b;
	case 13198ULL: goto x86_l_338e;
	case 13200ULL: goto x86_l_3390;
	case 13202ULL: goto x86_l_3392;
	case 13207ULL: goto x86_l_3397;
	case 13212ULL: goto x86_l_339c;
	case 13217ULL: goto x86_l_33a1;
	case 13222ULL: goto x86_l_33a6;
	case 13226ULL: goto x86_l_33aa;
	case 13232ULL: goto x86_l_33b0;
	case 13242ULL: goto x86_l_33ba;
	case 13246ULL: goto x86_l_33be;
	case 13252ULL: goto x86_l_33c4;
	case 13256ULL: goto x86_l_33c8;
	case 13261ULL: goto x86_l_33cd;
	case 13266ULL: goto x86_l_33d2;
	case 13273ULL: goto x86_l_33d9;
	case 13278ULL: goto x86_l_33de;
	case 13280ULL: goto x86_l_33e0;
	case 13285ULL: goto x86_l_33e5;
	case 13290ULL: goto x86_l_33ea;
	case 13297ULL: goto x86_l_33f1;
	case 13299ULL: goto x86_l_33f3;
	case 13304ULL: goto x86_l_33f8;
	case 13309ULL: goto x86_l_33fd;
	case 13316ULL: goto x86_l_3404;
	case 13318ULL: goto x86_l_3406;
	case 13323ULL: goto x86_l_340b;
	case 13328ULL: goto x86_l_3410;
	case 13335ULL: goto x86_l_3417;
	case 13337ULL: goto x86_l_3419;
	case 13342ULL: goto x86_l_341e;
	case 13347ULL: goto x86_l_3423;
	case 13354ULL: goto x86_l_342a;
	case 13356ULL: goto x86_l_342c;
	case 13361ULL: goto x86_l_3431;
	case 13366ULL: goto x86_l_3436;
	case 13373ULL: goto x86_l_343d;
	case 13375ULL: goto x86_l_343f;
	case 13380ULL: goto x86_l_3444;
	case 13385ULL: goto x86_l_3449;
	case 13392ULL: goto x86_l_3450;
	case 13394ULL: goto x86_l_3452;
	case 13397ULL: goto x86_l_3455;
	case 13403ULL: goto x86_l_345b;
	case 13406ULL: goto x86_l_345e;
	case 13411ULL: goto x86_l_3463;
	case 13416ULL: goto x86_l_3468;
	case 13421ULL: goto x86_l_346d;
	case 13426ULL: goto x86_l_3472;
	case 13428ULL: goto x86_l_3474;
	case 13434ULL: goto x86_l_347a;
	case 13437ULL: goto x86_l_347d;
	case 13443ULL: goto x86_l_3483;
	case 13448ULL: goto x86_l_3488;
	case 13451ULL: goto x86_l_348b;
	case 13457ULL: goto x86_l_3491;
	case 13460ULL: goto x86_l_3494;
	case 13463ULL: goto x86_l_3497;
	case 13469ULL: goto x86_l_349d;
	case 13472ULL: goto x86_l_34a0;
	case 13478ULL: goto x86_l_34a6;
	case 13481ULL: goto x86_l_34a9;
	case 13487ULL: goto x86_l_34af;
	case 13492ULL: goto x86_l_34b4;
	case 13494ULL: goto x86_l_34b6;
	case 13499ULL: goto x86_l_34bb;
	case 13501ULL: goto x86_l_34bd;
	case 13507ULL: goto x86_l_34c3;
	case 13510ULL: goto x86_l_34c6;
	case 13516ULL: goto x86_l_34cc;
	case 13521ULL: goto x86_l_34d1;
	case 13524ULL: goto x86_l_34d4;
	case 13530ULL: goto x86_l_34da;
	case 13533ULL: goto x86_l_34dd;
	case 13536ULL: goto x86_l_34e0;
	case 13542ULL: goto x86_l_34e6;
	case 13545ULL: goto x86_l_34e9;
	case 13551ULL: goto x86_l_34ef;
	case 13554ULL: goto x86_l_34f2;
	case 13560ULL: goto x86_l_34f8;
	case 13565ULL: goto x86_l_34fd;
	case 13567ULL: goto x86_l_34ff;
	case 13573ULL: goto x86_l_3505;
	case 13578ULL: goto x86_l_350a;
	case 13581ULL: goto x86_l_350d;
	case 13587ULL: goto x86_l_3513;
	case 13590ULL: goto x86_l_3516;
	case 13596ULL: goto x86_l_351c;
	case 13599ULL: goto x86_l_351f;
	case 13605ULL: goto x86_l_3525;
	case 13610ULL: goto x86_l_352a;
	case 13615ULL: goto x86_l_352f;
	case 13622ULL: goto x86_l_3536;
	case 13627ULL: goto x86_l_353b;
	case 13631ULL: goto x86_l_353f;
	case 13637ULL: goto x86_l_3545;
	case 13639ULL: goto x86_l_3547;
	case 13643ULL: goto x86_l_354b;
	case 13649ULL: goto x86_l_3551;
	case 13652ULL: goto x86_l_3554;
	case 13658ULL: goto x86_l_355a;
	case 13663ULL: goto x86_l_355f;
	case 13666ULL: goto x86_l_3562;
	case 13668ULL: goto x86_l_3564;
	case 13671ULL: goto x86_l_3567;
	case 13674ULL: goto x86_l_356a;
	case 13676ULL: goto x86_l_356c;
	case 13679ULL: goto x86_l_356f;
	case 13685ULL: goto x86_l_3575;
	case 13688ULL: goto x86_l_3578;
	case 13694ULL: goto x86_l_357e;
	case 13698ULL: goto x86_l_3582;
	case 13704ULL: goto x86_l_3588;
	case 13709ULL: goto x86_l_358d;
	case 13712ULL: goto x86_l_3590;
	case 13714ULL: goto x86_l_3592;
	case 13717ULL: goto x86_l_3595;
	case 13723ULL: goto x86_l_359b;
	case 13726ULL: goto x86_l_359e;
	case 13732ULL: goto x86_l_35a4;
	case 13737ULL: goto x86_l_35a9;
	case 13740ULL: goto x86_l_35ac;
	case 13746ULL: goto x86_l_35b2;
	case 13750ULL: goto x86_l_35b6;
	case 13756ULL: goto x86_l_35bc;
	case 13761ULL: goto x86_l_35c1;
	case 13765ULL: goto x86_l_35c5;
	case 13771ULL: goto x86_l_35cb;
	case 13776ULL: goto x86_l_35d0;
	case 13779ULL: goto x86_l_35d3;
	case 13785ULL: goto x86_l_35d9;
	case 13790ULL: goto x86_l_35de;
	case 13793ULL: goto x86_l_35e1;
	case 13799ULL: goto x86_l_35e7;
	case 13803ULL: goto x86_l_35eb;
	case 13809ULL: goto x86_l_35f1;
	case 13814ULL: goto x86_l_35f6;
	case 13816ULL: goto x86_l_35f8;
	case 13822ULL: goto x86_l_35fe;
	case 13825ULL: goto x86_l_3601;
	case 13831ULL: goto x86_l_3607;
	case 13836ULL: goto x86_l_360c;
	case 13841ULL: goto x86_l_3611;
	case 13848ULL: goto x86_l_3618;
	case 13853ULL: goto x86_l_361d;
	case 13856ULL: goto x86_l_3620;
	case 13862ULL: goto x86_l_3626;
	case 13865ULL: goto x86_l_3629;
	case 13871ULL: goto x86_l_362f;
	case 13876ULL: goto x86_l_3634;
	case 13878ULL: goto x86_l_3636;
	case 13881ULL: goto x86_l_3639;
	case 13887ULL: goto x86_l_363f;
	case 13890ULL: goto x86_l_3642;
	case 13896ULL: goto x86_l_3648;
	case 13901ULL: goto x86_l_364d;
	case 13903ULL: goto x86_l_364f;
	case 13909ULL: goto x86_l_3655;
	case 13914ULL: goto x86_l_365a;
	case 13919ULL: goto x86_l_365f;
	case 13921ULL: goto x86_l_3661;
	case 13926ULL: goto x86_l_3666;
	case 13928ULL: goto x86_l_3668;
	case 13934ULL: goto x86_l_366e;
	case 13936ULL: goto x86_l_3670;
	case 13939ULL: goto x86_l_3673;
	case 13942ULL: goto x86_l_3676;
	case 13947ULL: goto x86_l_367b;
	case 13951ULL: goto x86_l_367f;
	case 13957ULL: goto x86_l_3685;
	case 13962ULL: goto x86_l_368a;
	case 13966ULL: goto x86_l_368e;
	case 13972ULL: goto x86_l_3694;
	case 13977ULL: goto x86_l_3699;
	case 13982ULL: goto x86_l_369e;
	case 13989ULL: goto x86_l_36a5;
	case 13994ULL: goto x86_l_36aa;
	case 13996ULL: goto x86_l_36ac;
	case 14001ULL: goto x86_l_36b1;
	case 14006ULL: goto x86_l_36b6;
	case 14013ULL: goto x86_l_36bd;
	case 14015ULL: goto x86_l_36bf;
	case 14020ULL: goto x86_l_36c4;
	case 14025ULL: goto x86_l_36c9;
	case 14032ULL: goto x86_l_36d0;
	case 14034ULL: goto x86_l_36d2;
	case 14039ULL: goto x86_l_36d7;
	case 14044ULL: goto x86_l_36dc;
	case 14051ULL: goto x86_l_36e3;
	case 14053ULL: goto x86_l_36e5;
	case 14058ULL: goto x86_l_36ea;
	case 14063ULL: goto x86_l_36ef;
	case 14070ULL: goto x86_l_36f6;
	case 14072ULL: goto x86_l_36f8;
	case 14077ULL: goto x86_l_36fd;
	case 14082ULL: goto x86_l_3702;
	case 14089ULL: goto x86_l_3709;
	case 14091ULL: goto x86_l_370b;
	case 14096ULL: goto x86_l_3710;
	case 14101ULL: goto x86_l_3715;
	case 14108ULL: goto x86_l_371c;
	case 14110ULL: goto x86_l_371e;
	case 14113ULL: goto x86_l_3721;
	case 14115ULL: goto x86_l_3723;
	case 14118ULL: goto x86_l_3726;
	case 14123ULL: goto x86_l_372b;
	case 14128ULL: goto x86_l_3730;
	case 14133ULL: goto x86_l_3735;
	case 14135ULL: goto x86_l_3737;
	case 14140ULL: goto x86_l_373c;
	case 14145ULL: goto x86_l_3741;
	case 14150ULL: goto x86_l_3746;
	case 14155ULL: goto x86_l_374b;
	case 14159ULL: goto x86_l_374f;
	case 14165ULL: goto x86_l_3755;
	case 14175ULL: goto x86_l_375f;
	case 14179ULL: goto x86_l_3763;
	case 14185ULL: goto x86_l_3769;
	case 14187ULL: goto x86_l_376b;
	case 14190ULL: goto x86_l_376e;
	case 14193ULL: goto x86_l_3771;
	case 14196ULL: goto x86_l_3774;
	case 14201ULL: goto x86_l_3779;
	case 14203ULL: goto x86_l_377b;
	case 14208ULL: goto x86_l_3780;
	case 14213ULL: goto x86_l_3785;
	case 14216ULL: goto x86_l_3788;
	case 14221ULL: goto x86_l_378d;
	case 14226ULL: goto x86_l_3792;
	case 14230ULL: goto x86_l_3796;
	case 14236ULL: goto x86_l_379c;
	case 14241ULL: goto x86_l_37a1;
	case 14246ULL: goto x86_l_37a6;
	case 14248ULL: goto x86_l_37a8;
	case 14253ULL: goto x86_l_37ad;
	case 14255ULL: goto x86_l_37af;
	case 14261ULL: goto x86_l_37b5;
	case 14263ULL: goto x86_l_37b7;
	case 14267ULL: goto x86_l_37bb;
	case 14273ULL: goto x86_l_37c1;
	case 14275ULL: goto x86_l_37c3;
	case 14279ULL: goto x86_l_37c7;
	case 14285ULL: goto x86_l_37cd;
	case 14288ULL: goto x86_l_37d0;
	case 14291ULL: goto x86_l_37d3;
	case 14297ULL: goto x86_l_37d9;
	case 14302ULL: goto x86_l_37de;
	case 14307ULL: goto x86_l_37e3;
	case 14310ULL: goto x86_l_37e6;
	case 14312ULL: goto x86_l_37e8;
	case 14313ULL: goto x86_l_37e9;
	case 14315ULL: goto x86_l_37eb;
	case 14317ULL: goto x86_l_37ed;
	case 14320ULL: goto x86_l_37f0;
	case 14323ULL: goto x86_l_37f3;
	case 14326ULL: goto x86_l_37f6;
	case 14328ULL: goto x86_l_37f8;
	case 14331ULL: goto x86_l_37fb;
	case 14335ULL: goto x86_l_37ff;
	case 14338ULL: goto x86_l_3802;
	case 14340ULL: goto x86_l_3804;
	case 14345ULL: goto x86_l_3809;
	case 14348ULL: goto x86_l_380c;
	case 14350ULL: goto x86_l_380e;
	case 14355ULL: goto x86_l_3813;
	case 14359ULL: goto x86_l_3817;
	case 14362ULL: goto x86_l_381a;
	case 14365ULL: goto x86_l_381d;
	case 14369ULL: goto x86_l_3821;
	case 14373ULL: goto x86_l_3825;
	case 14377ULL: goto x86_l_3829;
	case 14380ULL: goto x86_l_382c;
	case 14384ULL: goto x86_l_3830;
	case 14388ULL: goto x86_l_3834;
	case 14392ULL: goto x86_l_3838;
	case 14395ULL: goto x86_l_383b;
	case 14397ULL: goto x86_l_383d;
	case 14401ULL: goto x86_l_3841;
	case 14405ULL: goto x86_l_3845;
	case 14408ULL: goto x86_l_3848;
	case 14410ULL: goto x86_l_384a;
	case 14412ULL: goto x86_l_384c;
	case 14414ULL: goto x86_l_384e;
	case 14415ULL: goto x86_l_384f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3377:
	/* 0x3377: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_337c:
	/* 0x337c: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3384:
	/* 0x3384: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3386:
	/* 0x3386: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3388:
	/* 0x3388: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_338b:
	/* 0x338b: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_338e:
	/* 0x338e: jmp    3392 <generic_uprobe_filter_arg+0x3392> */
	goto x86_l_3392;
x86_l_3390:
	/* 0x3390: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3392:
	/* 0x3392: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3397:
	/* 0x3397: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_339c:
	/* 0x339c: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33a1:
	/* 0x33a1: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_33a6:
	/* 0x33a6: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_33aa:
	/* 0x33aa: ja     2bb <generic_uprobe_filter_arg+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 699ULL;
	}
x86_l_33b0:
	/* 0x33b0: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_33ba:
	/* 0x33ba: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_33be:
	/* 0x33be: jae    2bb <generic_uprobe_filter_arg+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 699ULL;
	}
x86_l_33c4:
	/* 0x33c4: xor    rbx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_33c8:
	/* 0x33c8: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_33cd:
	/* 0x33cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33d2:
	/* 0x33d2: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_33d9:
	/* 0x33d9: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_33de:
	/* 0x33de: jmp    3450 <generic_uprobe_filter_arg+0x3450> */
	goto x86_l_3450;
x86_l_33e0:
	/* 0x33e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33e5:
	/* 0x33e5: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_33ea:
	/* 0x33ea: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_33f1:
	/* 0x33f1: jmp    3450 <generic_uprobe_filter_arg+0x3450> */
	goto x86_l_3450;
x86_l_33f3:
	/* 0x33f3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33f8:
	/* 0x33f8: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_33fd:
	/* 0x33fd: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_3404:
	/* 0x3404: jmp    3450 <generic_uprobe_filter_arg+0x3450> */
	goto x86_l_3450;
x86_l_3406:
	/* 0x3406: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_340b:
	/* 0x340b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3410:
	/* 0x3410: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_3417:
	/* 0x3417: jmp    3450 <generic_uprobe_filter_arg+0x3450> */
	goto x86_l_3450;
x86_l_3419:
	/* 0x3419: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_341e:
	/* 0x341e: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3423:
	/* 0x3423: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_342a:
	/* 0x342a: jmp    3450 <generic_uprobe_filter_arg+0x3450> */
	goto x86_l_3450;
x86_l_342c:
	/* 0x342c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3431:
	/* 0x3431: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3436:
	/* 0x3436: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_343d:
	/* 0x343d: jmp    3450 <generic_uprobe_filter_arg+0x3450> */
	goto x86_l_3450;
x86_l_343f:
	/* 0x343f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3444:
	/* 0x3444: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3449:
	/* 0x3449: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_3450:
	/* 0x3450: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3452:
	/* 0x3452: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3455:
	/* 0x3455: je     3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3735;
	}
x86_l_345b:
	/* 0x345b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_345e:
	/* 0x345e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3463:
	/* 0x3463: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3468:
	/* 0x3468: jmp    1b3e <generic_uprobe_filter_arg+0x1b3e> */
	return 6974ULL;
x86_l_346d:
	/* 0x346d: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3472:
	/* 0x3472: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_3474:
	/* 0x3474: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_347a:
	/* 0x347a: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_347d:
	/* 0x347d: jb     37cd <generic_uprobe_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37cd;
	}
x86_l_3483:
	/* 0x3483: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3488:
	/* 0x3488: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_348b:
	/* 0x348b: jle    361d <generic_uprobe_filter_arg+0x361d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_361d;
	}
x86_l_3491:
	/* 0x3491: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3494:
	/* 0x3494: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3497:
	/* 0x3497: jb     365a <generic_uprobe_filter_arg+0x365a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_365a;
	}
x86_l_349d:
	/* 0x349d: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_34a0:
	/* 0x34a0: je     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 716ULL;
	}
x86_l_34a6:
	/* 0x34a6: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_34a9:
	/* 0x34a9: jne    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_34af:
	/* 0x34af: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_34b4:
	/* 0x34b4: jmp    34fd <generic_uprobe_filter_arg+0x34fd> */
	goto x86_l_34fd;
x86_l_34b6:
	/* 0x34b6: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34bb:
	/* 0x34bb: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_34bd:
	/* 0x34bd: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_34c3:
	/* 0x34c3: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_34c6:
	/* 0x34c6: jb     37cd <generic_uprobe_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37cd;
	}
x86_l_34cc:
	/* 0x34cc: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_34d1:
	/* 0x34d1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_34d4:
	/* 0x34d4: jle    3636 <generic_uprobe_filter_arg+0x3636> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3636;
	}
x86_l_34da:
	/* 0x34da: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_34dd:
	/* 0x34dd: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_34e0:
	/* 0x34e0: jb     3661 <generic_uprobe_filter_arg+0x3661> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3661;
	}
x86_l_34e6:
	/* 0x34e6: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_34e9:
	/* 0x34e9: je     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 716ULL;
	}
x86_l_34ef:
	/* 0x34ef: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_34f2:
	/* 0x34f2: jne    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_34f8:
	/* 0x34f8: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34fd:
	/* 0x34fd: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_34ff:
	/* 0x34ff: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_3505:
	/* 0x3505: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	goto x86_l_37cd;
x86_l_350a:
	/* 0x350a: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_350d:
	/* 0x350d: je     370b <generic_uprobe_filter_arg+0x370b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_370b;
	}
x86_l_3513:
	/* 0x3513: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_3516:
	/* 0x3516: je     36d2 <generic_uprobe_filter_arg+0x36d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36d2;
	}
x86_l_351c:
	/* 0x351c: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_351f:
	/* 0x351f: jne    3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3735;
	}
x86_l_3525:
	/* 0x3525: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_352a:
	/* 0x352a: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_352f:
	/* 0x352f: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_3536:
	/* 0x3536: jmp    371c <generic_uprobe_filter_arg+0x371c> */
	goto x86_l_371c;
x86_l_353b:
	/* 0x353b: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_353f:
	/* 0x353f: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_3545:
	/* 0x3545: jmp    3551 <generic_uprobe_filter_arg+0x3551> */
	goto x86_l_3551;
x86_l_3547:
	/* 0x3547: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_354b:
	/* 0x354b: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_3551:
	/* 0x3551: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_3554:
	/* 0x3554: jb     37cd <generic_uprobe_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37cd;
	}
x86_l_355a:
	/* 0x355a: mov    edx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_355f:
	/* 0x355f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3562:
	/* 0x3562: jle    358d <generic_uprobe_filter_arg+0x358d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_358d;
	}
x86_l_3564:
	/* 0x3564: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3567:
	/* 0x3567: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_356a:
	/* 0x356a: jb     35c1 <generic_uprobe_filter_arg+0x35c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_35c1;
	}
x86_l_356c:
	/* 0x356c: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_356f:
	/* 0x356f: je     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 716ULL;
	}
x86_l_3575:
	/* 0x3575: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3578:
	/* 0x3578: jne    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_357e:
	/* 0x357e: test   DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3582:
	/* 0x3582: jne    2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_3588:
	/* 0x3588: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	goto x86_l_37cd;
x86_l_358d:
	/* 0x358d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3590:
	/* 0x3590: je     35d0 <generic_uprobe_filter_arg+0x35d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35d0;
	}
x86_l_3592:
	/* 0x3592: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3595:
	/* 0x3595: jne    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_359b:
	/* 0x359b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_359e:
	/* 0x359e: ja     37b7 <generic_uprobe_filter_arg+0x37b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_37b7;
	}
x86_l_35a4:
	/* 0x35a4: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_35a9:
	/* 0x35a9: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_35ac:
	/* 0x35ac: jae    37b7 <generic_uprobe_filter_arg+0x37b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_37b7;
	}
x86_l_35b2:
	/* 0x35b2: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35b6:
	/* 0x35b6: jl     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_35bc:
	/* 0x35bc: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	goto x86_l_37cd;
x86_l_35c1:
	/* 0x35c1: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35c5:
	/* 0x35c5: je     366e <generic_uprobe_filter_arg+0x366e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_366e;
	}
x86_l_35cb:
	/* 0x35cb: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	goto x86_l_37cd;
x86_l_35d0:
	/* 0x35d0: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_35d3:
	/* 0x35d3: ja     37c3 <generic_uprobe_filter_arg+0x37c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_37c3;
	}
x86_l_35d9:
	/* 0x35d9: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_35de:
	/* 0x35de: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_35e1:
	/* 0x35e1: jae    37c3 <generic_uprobe_filter_arg+0x37c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_37c3;
	}
x86_l_35e7:
	/* 0x35e7: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35eb:
	/* 0x35eb: jg     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_35f1:
	/* 0x35f1: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	goto x86_l_37cd;
x86_l_35f6:
	/* 0x35f6: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_35f8:
	/* 0x35f8: je     3699 <generic_uprobe_filter_arg+0x3699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3699;
	}
x86_l_35fe:
	/* 0x35fe: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3601:
	/* 0x3601: jne    3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3735;
	}
x86_l_3607:
	/* 0x3607: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_360c:
	/* 0x360c: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3611:
	/* 0x3611: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_3618:
	/* 0x3618: jmp    371c <generic_uprobe_filter_arg+0x371c> */
	goto x86_l_371c;
x86_l_361d:
	/* 0x361d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3620:
	/* 0x3620: je     37a1 <generic_uprobe_filter_arg+0x37a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37a1;
	}
x86_l_3626:
	/* 0x3626: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3629:
	/* 0x3629: jne    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_362f:
	/* 0x362f: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3634:
	/* 0x3634: jmp    364d <generic_uprobe_filter_arg+0x364d> */
	goto x86_l_364d;
x86_l_3636:
	/* 0x3636: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3639:
	/* 0x3639: je     37a8 <generic_uprobe_filter_arg+0x37a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37a8;
	}
x86_l_363f:
	/* 0x363f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3642:
	/* 0x3642: jne    110 <generic_uprobe_filter_arg+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 272ULL;
	}
x86_l_3648:
	/* 0x3648: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_364d:
	/* 0x364d: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_364f:
	/* 0x364f: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_3655:
	/* 0x3655: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	goto x86_l_37cd;
x86_l_365a:
	/* 0x365a: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_365f:
	/* 0x365f: jmp    3666 <generic_uprobe_filter_arg+0x3666> */
	goto x86_l_3666;
x86_l_3661:
	/* 0x3661: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3666:
	/* 0x3666: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_3668:
	/* 0x3668: jne    37cd <generic_uprobe_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37cd;
	}
x86_l_366e:
	/* 0x366e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3670:
	/* 0x3670: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3673:
	/* 0x3673: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_3676:
	/* 0x3676: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_367b:
	/* 0x367b: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_367f:
	/* 0x367f: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_3685:
	/* 0x3685: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	goto x86_l_37cd;
x86_l_368a:
	/* 0x368a: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_368e:
	/* 0x368e: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_3694:
	/* 0x3694: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	goto x86_l_37cd;
x86_l_3699:
	/* 0x3699: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_369e:
	/* 0x369e: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_36a5:
	/* 0x36a5: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36aa:
	/* 0x36aa: jmp    371c <generic_uprobe_filter_arg+0x371c> */
	goto x86_l_371c;
x86_l_36ac:
	/* 0x36ac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36b1:
	/* 0x36b1: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36b6:
	/* 0x36b6: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_36bd:
	/* 0x36bd: jmp    371c <generic_uprobe_filter_arg+0x371c> */
	goto x86_l_371c;
x86_l_36bf:
	/* 0x36bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36c4:
	/* 0x36c4: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36c9:
	/* 0x36c9: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_36d0:
	/* 0x36d0: jmp    371c <generic_uprobe_filter_arg+0x371c> */
	goto x86_l_371c;
x86_l_36d2:
	/* 0x36d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36d7:
	/* 0x36d7: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36dc:
	/* 0x36dc: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_36e3:
	/* 0x36e3: jmp    371c <generic_uprobe_filter_arg+0x371c> */
	goto x86_l_371c;
x86_l_36e5:
	/* 0x36e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36ea:
	/* 0x36ea: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36ef:
	/* 0x36ef: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_36f6:
	/* 0x36f6: jmp    371c <generic_uprobe_filter_arg+0x371c> */
	goto x86_l_371c;
x86_l_36f8:
	/* 0x36f8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36fd:
	/* 0x36fd: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3702:
	/* 0x3702: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3709:
	/* 0x3709: jmp    371c <generic_uprobe_filter_arg+0x371c> */
	goto x86_l_371c;
x86_l_370b:
	/* 0x370b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3710:
	/* 0x3710: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3715:
	/* 0x3715: mov    rdi,QWORD PTR [rip+0x1eeb6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_371c:
	/* 0x371c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_371e:
	/* 0x371e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3721:
	/* 0x3721: je     3735 <generic_uprobe_filter_arg+0x3735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3735;
	}
x86_l_3723:
	/* 0x3723: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3726:
	/* 0x3726: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_372b:
	/* 0x372b: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3730:
	/* 0x3730: jmp    1b3e <generic_uprobe_filter_arg+0x1b3e> */
	return 6974ULL;
x86_l_3735:
	/* 0x3735: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3737:
	/* 0x3737: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_373c:
	/* 0x373c: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3741:
	/* 0x3741: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3746:
	/* 0x3746: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_374b:
	/* 0x374b: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_374f:
	/* 0x374f: ja     2bb <generic_uprobe_filter_arg+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 699ULL;
	}
x86_l_3755:
	/* 0x3755: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_375f:
	/* 0x375f: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3763:
	/* 0x3763: jae    2bb <generic_uprobe_filter_arg+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 699ULL;
	}
x86_l_3769:
	/* 0x3769: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_376b:
	/* 0x376b: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_376e:
	/* 0x376e: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_3771:
	/* 0x3771: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3774:
	/* 0x3774: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_3779:
	/* 0x3779: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_377b:
	/* 0x377b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3780:
	/* 0x3780: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3785:
	/* 0x3785: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_3788:
	/* 0x3788: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_378d:
	/* 0x378d: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3792:
	/* 0x3792: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_3796:
	/* 0x3796: jbe    33b0 <generic_uprobe_filter_arg+0x33b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_33b0;
	}
x86_l_379c:
	/* 0x379c: jmp    2bb <generic_uprobe_filter_arg+0x2bb> */
	return 699ULL;
x86_l_37a1:
	/* 0x37a1: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_37a6:
	/* 0x37a6: jmp    37ad <generic_uprobe_filter_arg+0x37ad> */
	goto x86_l_37ad;
x86_l_37a8:
	/* 0x37a8: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37ad:
	/* 0x37ad: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_37af:
	/* 0x37af: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_37b5:
	/* 0x37b5: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	goto x86_l_37cd;
x86_l_37b7:
	/* 0x37b7: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37bb:
	/* 0x37bb: jb     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_37c1:
	/* 0x37c1: jmp    37cd <generic_uprobe_filter_arg+0x37cd> */
	goto x86_l_37cd;
x86_l_37c3:
	/* 0x37c3: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37c7:
	/* 0x37c7: ja     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_37cd:
	/* 0x37cd: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_37d0:
	/* 0x37d0: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_37d3:
	/* 0x37d3: je     2cc <generic_uprobe_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 716ULL;
	}
x86_l_37d9:
	/* 0x37d9: jmp    110 <generic_uprobe_filter_arg+0x110> */
	return 272ULL;
x86_l_37de:
	/* 0x37de: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_37e3:
	/* 0x37e3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_37e6:
	/* 0x37e6: je     384f <native_bpf_strncasestr+0x71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_384f;
	}
x86_l_37e8:
	/* 0x37e8: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_37e9:
	/* 0x37e9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37eb:
	/* 0x37eb: jmp    37f8 <native_bpf_strncasestr+0x1a> */
	goto x86_l_37f8;
x86_l_37ed:
	/* 0x37ed: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_37f0:
	/* 0x37f0: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_37f3:
	/* 0x37f3: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_37f6:
	/* 0x37f6: je     384e <native_bpf_strncasestr+0x70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_384e;
	}
x86_l_37f8:
	/* 0x37f8: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37fb:
	/* 0x37fb: lea    r9,[rcx+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_37ff:
	/* 0x37ff: cmp    r9,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RDX, X86_WIDTH_64);
x86_l_3802:
	/* 0x3802: jae    37ed <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_37ed;
	}
x86_l_3804:
	/* 0x3804: movsx  r9d,BYTE PTR [rsi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_3809:
	/* 0x3809: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_380c:
	/* 0x380c: je     384c <native_bpf_strncasestr+0x6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_384c;
	}
x86_l_380e:
	/* 0x380e: movsx  r10d,BYTE PTR [rdi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_3813:
	/* 0x3813: lea    r11d,[r10-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_3817:
	/* 0x3817: mov    ebx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R10, X86_WIDTH_32);
x86_l_381a:
	/* 0x381a: or     ebx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_381d:
	/* 0x381d: cmp    r11d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 26ULL);
x86_l_3821:
	/* 0x3821: cmovae ebx,r10d */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R10, X86_WIDTH_32, X86_CC_AE);
x86_l_3825:
	/* 0x3825: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_3829:
	/* 0x3829: mov    r11d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_32);
x86_l_382c:
	/* 0x382c: or     r11d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_3830:
	/* 0x3830: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_3834:
	/* 0x3834: cmovae r11d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_3838:
	/* 0x3838: cmp    ebx,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R11, X86_WIDTH_32);
x86_l_383b:
	/* 0x383b: jne    37ed <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37ed;
	}
x86_l_383d:
	/* 0x383d: lea    r9,[r8+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3841:
	/* 0x3841: cmp    r8,0x63 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 99ULL);
x86_l_3845:
	/* 0x3845: mov    r8,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_64);
x86_l_3848:
	/* 0x3848: jb     37fb <native_bpf_strncasestr+0x1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37fb;
	}
x86_l_384a:
	/* 0x384a: jmp    37ed <native_bpf_strncasestr+0xf> */
	goto x86_l_37ed;
x86_l_384c:
	/* 0x384c: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_384e:
	/* 0x384e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_384f:
	/* 0x384f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 13448U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1724ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1729ULL && __x86_pc <= 3392ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3395ULL && __x86_pc <= 4988ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4992ULL && __x86_pc <= 6638ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6644ULL && __x86_pc <= 8240ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8242ULL && __x86_pc <= 9852ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9855ULL && __x86_pc <= 11506ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11512ULL && __x86_pc <= 13172ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13175ULL && __x86_pc <= 14415ULL)
			__x86_pc = tetragon_bpf_multi_uprobe_v511_generic_uprobe_filter_arg_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

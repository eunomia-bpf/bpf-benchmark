extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
extern char filter_map;
extern char heap_ro_zero;
extern char lsm_calls;
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
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_0(
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
	case 79ULL: goto x86_l_4f;
	case 86ULL: goto x86_l_56;
	case 91ULL: goto x86_l_5b;
	case 93ULL: goto x86_l_5d;
	case 96ULL: goto x86_l_60;
	case 102ULL: goto x86_l_66;
	case 110ULL: goto x86_l_6e;
	case 116ULL: goto x86_l_74;
	case 119ULL: goto x86_l_77;
	case 127ULL: goto x86_l_7f;
	case 130ULL: goto x86_l_82;
	case 133ULL: goto x86_l_85;
	case 142ULL: goto x86_l_8e;
	case 148ULL: goto x86_l_94;
	case 150ULL: goto x86_l_96;
	case 155ULL: goto x86_l_9b;
	case 159ULL: goto x86_l_9f;
	case 163ULL: goto x86_l_a3;
	case 167ULL: goto x86_l_a7;
	case 171ULL: goto x86_l_ab;
	case 176ULL: goto x86_l_b0;
	case 180ULL: goto x86_l_b4;
	case 183ULL: goto x86_l_b7;
	case 187ULL: goto x86_l_bb;
	case 189ULL: goto x86_l_bd;
	case 195ULL: goto x86_l_c3;
	case 199ULL: goto x86_l_c7;
	case 202ULL: goto x86_l_ca;
	case 204ULL: goto x86_l_cc;
	case 209ULL: goto x86_l_d1;
	case 213ULL: goto x86_l_d5;
	case 216ULL: goto x86_l_d8;
	case 218ULL: goto x86_l_da;
	case 224ULL: goto x86_l_e0;
	case 228ULL: goto x86_l_e4;
	case 231ULL: goto x86_l_e7;
	case 233ULL: goto x86_l_e9;
	case 238ULL: goto x86_l_ee;
	case 242ULL: goto x86_l_f2;
	case 245ULL: goto x86_l_f5;
	case 248ULL: goto x86_l_f8;
	case 254ULL: goto x86_l_fe;
	case 259ULL: goto x86_l_103;
	case 261ULL: goto x86_l_105;
	case 265ULL: goto x86_l_109;
	case 271ULL: goto x86_l_10f;
	case 273ULL: goto x86_l_111;
	case 279ULL: goto x86_l_117;
	case 287ULL: goto x86_l_11f;
	case 290ULL: goto x86_l_122;
	case 292ULL: goto x86_l_124;
	case 295ULL: goto x86_l_127;
	case 301ULL: goto x86_l_12d;
	case 303ULL: goto x86_l_12f;
	case 309ULL: goto x86_l_135;
	case 312ULL: goto x86_l_138;
	case 318ULL: goto x86_l_13e;
	case 320ULL: goto x86_l_140;
	case 323ULL: goto x86_l_143;
	case 329ULL: goto x86_l_149;
	case 332ULL: goto x86_l_14c;
	case 338ULL: goto x86_l_152;
	case 341ULL: goto x86_l_155;
	case 347ULL: goto x86_l_15b;
	case 350ULL: goto x86_l_15e;
	case 356ULL: goto x86_l_164;
	case 358ULL: goto x86_l_166;
	case 363ULL: goto x86_l_16b;
	case 367ULL: goto x86_l_16f;
	case 375ULL: goto x86_l_177;
	case 378ULL: goto x86_l_17a;
	case 386ULL: goto x86_l_182;
	case 391ULL: goto x86_l_187;
	case 399ULL: goto x86_l_18f;
	case 404ULL: goto x86_l_194;
	case 409ULL: goto x86_l_199;
	case 414ULL: goto x86_l_19e;
	case 419ULL: goto x86_l_1a3;
	case 426ULL: goto x86_l_1aa;
	case 433ULL: goto x86_l_1b1;
	case 438ULL: goto x86_l_1b6;
	case 443ULL: goto x86_l_1bb;
	case 446ULL: goto x86_l_1be;
	case 451ULL: goto x86_l_1c3;
	case 453ULL: goto x86_l_1c5;
	case 460ULL: goto x86_l_1cc;
	case 465ULL: goto x86_l_1d1;
	case 470ULL: goto x86_l_1d6;
	case 473ULL: goto x86_l_1d9;
	case 478ULL: goto x86_l_1de;
	case 480ULL: goto x86_l_1e0;
	case 482ULL: goto x86_l_1e2;
	case 489ULL: goto x86_l_1e9;
	case 490ULL: goto x86_l_1ea;
	case 492ULL: goto x86_l_1ec;
	case 494ULL: goto x86_l_1ee;
	case 496ULL: goto x86_l_1f0;
	case 498ULL: goto x86_l_1f2;
	case 499ULL: goto x86_l_1f3;
	case 504ULL: goto x86_l_1f8;
	case 506ULL: goto x86_l_1fa;
	case 514ULL: goto x86_l_202;
	case 516ULL: goto x86_l_204;
	case 521ULL: goto x86_l_209;
	case 529ULL: goto x86_l_211;
	case 531ULL: goto x86_l_213;
	case 536ULL: goto x86_l_218;
	case 544ULL: goto x86_l_220;
	case 546ULL: goto x86_l_222;
	case 551ULL: goto x86_l_227;
	case 559ULL: goto x86_l_22f;
	case 561ULL: goto x86_l_231;
	case 566ULL: goto x86_l_236;
	case 574ULL: goto x86_l_23e;
	case 576ULL: goto x86_l_240;
	case 581ULL: goto x86_l_245;
	case 589ULL: goto x86_l_24d;
	case 591ULL: goto x86_l_24f;
	case 598ULL: goto x86_l_256;
	case 605ULL: goto x86_l_25d;
	case 610ULL: goto x86_l_262;
	case 615ULL: goto x86_l_267;
	case 618ULL: goto x86_l_26a;
	case 623ULL: goto x86_l_26f;
	case 625ULL: goto x86_l_271;
	case 629ULL: goto x86_l_275;
	case 634ULL: goto x86_l_27a;
	case 636ULL: goto x86_l_27c;
	case 641ULL: goto x86_l_281;
	case 646ULL: goto x86_l_286;
	case 653ULL: goto x86_l_28d;
	case 658ULL: goto x86_l_292;
	case 663ULL: goto x86_l_297;
	case 665ULL: goto x86_l_299;
	case 668ULL: goto x86_l_29c;
	case 674ULL: goto x86_l_2a2;
	case 681ULL: goto x86_l_2a9;
	case 686ULL: goto x86_l_2ae;
	case 691ULL: goto x86_l_2b3;
	case 693ULL: goto x86_l_2b5;
	case 698ULL: goto x86_l_2ba;
	case 700ULL: goto x86_l_2bc;
	case 705ULL: goto x86_l_2c1;
	case 710ULL: goto x86_l_2c6;
	case 713ULL: goto x86_l_2c9;
	case 716ULL: goto x86_l_2cc;
	case 724ULL: goto x86_l_2d4;
	case 730ULL: goto x86_l_2da;
	case 733ULL: goto x86_l_2dd;
	case 737ULL: goto x86_l_2e1;
	case 743ULL: goto x86_l_2e7;
	case 751ULL: goto x86_l_2ef;
	case 756ULL: goto x86_l_2f4;
	case 763ULL: goto x86_l_2fb;
	case 769ULL: goto x86_l_301;
	case 772ULL: goto x86_l_304;
	case 779ULL: goto x86_l_30b;
	case 784ULL: goto x86_l_310;
	case 787ULL: goto x86_l_313;
	case 793ULL: goto x86_l_319;
	case 796ULL: goto x86_l_31c;
	case 800ULL: goto x86_l_320;
	case 804ULL: goto x86_l_324;
	case 810ULL: goto x86_l_32a;
	case 819ULL: goto x86_l_333;
	case 825ULL: goto x86_l_339;
	case 833ULL: goto x86_l_341;
	case 839ULL: goto x86_l_347;
	case 843ULL: goto x86_l_34b;
	case 850ULL: goto x86_l_352;
	case 855ULL: goto x86_l_357;
	case 858ULL: goto x86_l_35a;
	case 860ULL: goto x86_l_35c;
	case 863ULL: goto x86_l_35f;
	case 865ULL: goto x86_l_361;
	case 868ULL: goto x86_l_364;
	case 871ULL: goto x86_l_367;
	case 877ULL: goto x86_l_36d;
	case 880ULL: goto x86_l_370;
	case 886ULL: goto x86_l_376;
	case 891ULL: goto x86_l_37b;
	case 894ULL: goto x86_l_37e;
	case 896ULL: goto x86_l_380;
	case 899ULL: goto x86_l_383;
	case 902ULL: goto x86_l_386;
	case 904ULL: goto x86_l_388;
	case 907ULL: goto x86_l_38b;
	case 910ULL: goto x86_l_38e;
	case 916ULL: goto x86_l_394;
	case 919ULL: goto x86_l_397;
	case 925ULL: goto x86_l_39d;
	case 929ULL: goto x86_l_3a1;
	case 934ULL: goto x86_l_3a6;
	case 937ULL: goto x86_l_3a9;
	case 943ULL: goto x86_l_3af;
	case 946ULL: goto x86_l_3b2;
	case 949ULL: goto x86_l_3b5;
	case 955ULL: goto x86_l_3bb;
	case 958ULL: goto x86_l_3be;
	case 961ULL: goto x86_l_3c1;
	case 967ULL: goto x86_l_3c7;
	case 972ULL: goto x86_l_3cc;
	case 975ULL: goto x86_l_3cf;
	case 981ULL: goto x86_l_3d5;
	case 984ULL: goto x86_l_3d8;
	case 986ULL: goto x86_l_3da;
	case 989ULL: goto x86_l_3dd;
	case 995ULL: goto x86_l_3e3;
	case 998ULL: goto x86_l_3e6;
	case 1004ULL: goto x86_l_3ec;
	case 1007ULL: goto x86_l_3ef;
	case 1013ULL: goto x86_l_3f5;
	case 1016ULL: goto x86_l_3f8;
	case 1022ULL: goto x86_l_3fe;
	case 1024ULL: goto x86_l_400;
	case 1034ULL: goto x86_l_40a;
	case 1038ULL: goto x86_l_40e;
	case 1044ULL: goto x86_l_414;
	case 1049ULL: goto x86_l_419;
	case 1053ULL: goto x86_l_41d;
	case 1059ULL: goto x86_l_423;
	case 1069ULL: goto x86_l_42d;
	case 1073ULL: goto x86_l_431;
	case 1079ULL: goto x86_l_437;
	case 1082ULL: goto x86_l_43a;
	case 1088ULL: goto x86_l_440;
	case 1090ULL: goto x86_l_442;
	case 1095ULL: goto x86_l_447;
	case 1099ULL: goto x86_l_44b;
	case 1105ULL: goto x86_l_451;
	case 1110ULL: goto x86_l_456;
	case 1113ULL: goto x86_l_459;
	case 1119ULL: goto x86_l_45f;
	case 1122ULL: goto x86_l_462;
	case 1125ULL: goto x86_l_465;
	case 1131ULL: goto x86_l_46b;
	case 1136ULL: goto x86_l_470;
	case 1138ULL: goto x86_l_472;
	case 1144ULL: goto x86_l_478;
	case 1149ULL: goto x86_l_47d;
	case 1152ULL: goto x86_l_480;
	case 1155ULL: goto x86_l_483;
	case 1161ULL: goto x86_l_489;
	case 1164ULL: goto x86_l_48c;
	case 1170ULL: goto x86_l_492;
	case 1173ULL: goto x86_l_495;
	case 1179ULL: goto x86_l_49b;
	case 1184ULL: goto x86_l_4a0;
	case 1187ULL: goto x86_l_4a3;
	case 1189ULL: goto x86_l_4a5;
	case 1192ULL: goto x86_l_4a8;
	case 1194ULL: goto x86_l_4aa;
	case 1197ULL: goto x86_l_4ad;
	case 1203ULL: goto x86_l_4b3;
	case 1212ULL: goto x86_l_4bc;
	case 1221ULL: goto x86_l_4c5;
	case 1230ULL: goto x86_l_4ce;
	case 1239ULL: goto x86_l_4d7;
	case 1248ULL: goto x86_l_4e0;
	case 1251ULL: goto x86_l_4e3;
	case 1257ULL: goto x86_l_4e9;
	case 1260ULL: goto x86_l_4ec;
	case 1266ULL: goto x86_l_4f2;
	case 1269ULL: goto x86_l_4f5;
	case 1274ULL: goto x86_l_4fa;
	case 1277ULL: goto x86_l_4fd;
	case 1283ULL: goto x86_l_503;
	case 1288ULL: goto x86_l_508;
	case 1292ULL: goto x86_l_50c;
	case 1296ULL: goto x86_l_510;
	case 1299ULL: goto x86_l_513;
	case 1305ULL: goto x86_l_519;
	case 1308ULL: goto x86_l_51c;
	case 1311ULL: goto x86_l_51f;
	case 1317ULL: goto x86_l_525;
	case 1320ULL: goto x86_l_528;
	case 1326ULL: goto x86_l_52e;
	case 1331ULL: goto x86_l_533;
	case 1334ULL: goto x86_l_536;
	case 1340ULL: goto x86_l_53c;
	case 1345ULL: goto x86_l_541;
	case 1348ULL: goto x86_l_544;
	case 1354ULL: goto x86_l_54a;
	case 1357ULL: goto x86_l_54d;
	case 1363ULL: goto x86_l_553;
	case 1366ULL: goto x86_l_556;
	case 1369ULL: goto x86_l_559;
	case 1375ULL: goto x86_l_55f;
	case 1378ULL: goto x86_l_562;
	case 1384ULL: goto x86_l_568;
	case 1389ULL: goto x86_l_56d;
	case 1392ULL: goto x86_l_570;
	case 1398ULL: goto x86_l_576;
	case 1401ULL: goto x86_l_579;
	case 1407ULL: goto x86_l_57f;
	case 1411ULL: goto x86_l_583;
	case 1416ULL: goto x86_l_588;
	case 1420ULL: goto x86_l_58c;
	case 1423ULL: goto x86_l_58f;
	case 1429ULL: goto x86_l_595;
	case 1432ULL: goto x86_l_598;
	case 1435ULL: goto x86_l_59b;
	case 1441ULL: goto x86_l_5a1;
	case 1452ULL: goto x86_l_5ac;
	case 1458ULL: goto x86_l_5b2;
	case 1462ULL: goto x86_l_5b6;
	case 1468ULL: goto x86_l_5bc;
	case 1472ULL: goto x86_l_5c0;
	case 1478ULL: goto x86_l_5c6;
	case 1481ULL: goto x86_l_5c9;
	case 1484ULL: goto x86_l_5cc;
	case 1487ULL: goto x86_l_5cf;
	case 1490ULL: goto x86_l_5d2;
	case 1492ULL: goto x86_l_5d4;
	case 1495ULL: goto x86_l_5d7;
	case 1497ULL: goto x86_l_5d9;
	case 1500ULL: goto x86_l_5dc;
	case 1502ULL: goto x86_l_5de;
	case 1504ULL: goto x86_l_5e0;
	case 1507ULL: goto x86_l_5e3;
	case 1510ULL: goto x86_l_5e6;
	case 1512ULL: goto x86_l_5e8;
	case 1514ULL: goto x86_l_5ea;
	case 1517ULL: goto x86_l_5ed;
	case 1521ULL: goto x86_l_5f1;
	case 1525ULL: goto x86_l_5f5;
	case 1531ULL: goto x86_l_5fb;
	case 1535ULL: goto x86_l_5ff;
	case 1542ULL: goto x86_l_606;
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1554ULL: goto x86_l_612;
	case 1558ULL: goto x86_l_616;
	case 1560ULL: goto x86_l_618;
	case 1563ULL: goto x86_l_61b;
	case 1566ULL: goto x86_l_61e;
	case 1568ULL: goto x86_l_620;
	case 1570ULL: goto x86_l_622;
	case 1576ULL: goto x86_l_628;
	case 1579ULL: goto x86_l_62b;
	case 1585ULL: goto x86_l_631;
	case 1587ULL: goto x86_l_633;
	case 1592ULL: goto x86_l_638;
	case 1596ULL: goto x86_l_63c;
	case 1602ULL: goto x86_l_642;
	case 1607ULL: goto x86_l_647;
	case 1611ULL: goto x86_l_64b;
	case 1617ULL: goto x86_l_651;
	case 1627ULL: goto x86_l_65b;
	case 1631ULL: goto x86_l_65f;
	case 1637ULL: goto x86_l_665;
	case 1644ULL: goto x86_l_66c;
	case 1650ULL: goto x86_l_672;
	case 1656ULL: goto x86_l_678;
	case 1659ULL: goto x86_l_67b;
	case 1662ULL: goto x86_l_67e;
	case 1666ULL: goto x86_l_682;
	case 1670ULL: goto x86_l_686;
	case 1675ULL: goto x86_l_68b;
	case 1680ULL: goto x86_l_690;
	case 1685ULL: goto x86_l_695;
	case 1687ULL: goto x86_l_697;
	case 1691ULL: goto x86_l_69b;
	case 1695ULL: goto x86_l_69f;
	case 1700ULL: goto x86_l_6a4;
	case 1702ULL: goto x86_l_6a6;
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
	/* 0xa: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x1edb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
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
	/* 0x38: je     1e0 <generic_lsm_filter_arg+0x1e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e0;
	}
x86_l_3e:
	/* 0x3e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: mov    r12d,DWORD PTR [rax+0x5f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_48:
	/* 0x48: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_4f:
	/* 0x4f: mov    rdi,QWORD PTR [rip+0x1edb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_56:
	/* 0x56: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b:
	/* 0x5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d:
	/* 0x5d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_60:
	/* 0x60: je     1c5 <generic_lsm_filter_arg+0x1c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c5;
	}
x86_l_66:
	/* 0x66: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_6e:
	/* 0x6e: je     1c5 <generic_lsm_filter_arg+0x1c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c5;
	}
x86_l_74:
	/* 0x74: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_77:
	/* 0x77: mov    QWORD PTR [rsp+0xb8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_7f:
	/* 0x7f: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_82:
	/* 0x82: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_85:
	/* 0x85: cmp    BYTE PTR [r14+rax*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699072ULL);
x86_l_8e:
	/* 0x8e: je     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_117;
	}
x86_l_94:
	/* 0x94: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_96:
	/* 0x96: mov    ecx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_9b:
	/* 0x9b: lea    rdx,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_9f:
	/* 0x9f: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a3:
	/* 0xa3: lea    rax,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_a7:
	/* 0xa7: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_ab:
	/* 0xab: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b0:
	/* 0xb0: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_b4:
	/* 0xb4: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b7:
	/* 0xb7: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_bb:
	/* 0xbb: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_bd:
	/* 0xbd: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_c3:
	/* 0xc3: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_c7:
	/* 0xc7: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ca:
	/* 0xca: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_cc:
	/* 0xcc: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_d1:
	/* 0xd1: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_d5:
	/* 0xd5: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d8:
	/* 0xd8: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_da:
	/* 0xda: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_e0:
	/* 0xe0: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_e4:
	/* 0xe4: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e7:
	/* 0xe7: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_e9:
	/* 0xe9: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_ee:
	/* 0xee: mov    r9d,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_f2:
	/* 0xf2: add    r9,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f5:
	/* 0xf5: mov    edi,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R9, X86_WIDTH_32);
x86_l_f8:
	/* 0xf8: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_fe:
	/* 0xfe: cmp    DWORD PTR [r15+rdi*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 25ULL);
x86_l_103:
	/* 0x103: jae    16b <generic_lsm_filter_arg+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16b;
	}
x86_l_105:
	/* 0x105: cmp    rdi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_64, 1ULL);
x86_l_109:
	/* 0x109: je     1c5 <generic_lsm_filter_arg+0x1c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c5;
	}
x86_l_10f:
	/* 0x10f: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_111:
	/* 0x111: jne    1a3 <generic_lsm_filter_arg+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a3;
	}
x86_l_117:
	/* 0x117: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_11f:
	/* 0x11f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_122:
	/* 0x122: jg     140 <generic_lsm_filter_arg+0x140> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_140;
	}
x86_l_124:
	/* 0x124: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_127:
	/* 0x127: je     1f8 <generic_lsm_filter_arg+0x1f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f8;
	}
x86_l_12d:
	/* 0x12d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12f:
	/* 0x12f: je     204 <generic_lsm_filter_arg+0x204> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_204;
	}
x86_l_135:
	/* 0x135: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_138:
	/* 0x138: je     213 <generic_lsm_filter_arg+0x213> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_213;
	}
x86_l_13e:
	/* 0x13e: jmp    15b <generic_lsm_filter_arg+0x15b> */
	goto x86_l_15b;
x86_l_140:
	/* 0x140: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_143:
	/* 0x143: je     222 <generic_lsm_filter_arg+0x222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_222;
	}
x86_l_149:
	/* 0x149: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_14c:
	/* 0x14c: je     231 <generic_lsm_filter_arg+0x231> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_231;
	}
x86_l_152:
	/* 0x152: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_155:
	/* 0x155: je     240 <generic_lsm_filter_arg+0x240> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_240;
	}
x86_l_15b:
	/* 0x15b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15e:
	/* 0x15e: jg     271 <generic_lsm_filter_arg+0x271> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_271;
	}
x86_l_164:
	/* 0x164: inc    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_166:
	/* 0x166: jmp    24f <generic_lsm_filter_arg+0x24f> */
	goto x86_l_24f;
x86_l_16b:
	/* 0x16b: lea    rax,[r15+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_16f:
	/* 0x16f: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_177:
	/* 0x177: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17a:
	/* 0x17a: lea    rax,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_182:
	/* 0x182: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_187:
	/* 0x187: mov    QWORD PTR [rsp+0xb0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_18f:
	/* 0x18f: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_194:
	/* 0x194: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_199:
	/* 0x199: mov    QWORD PTR [rsp+0x78],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19e:
	/* 0x19e: jmp    2e7 <generic_lsm_filter_arg+0x2e7> */
	goto x86_l_2e7;
x86_l_1a3:
	/* 0x1a3: mov    DWORD PTR [r14+0x5f04],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_1aa:
	/* 0x1aa: mov    rsi,QWORD PTR [rip+0x1edb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&lsm_calls)));
x86_l_1b1:
	/* 0x1b1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b6:
	/* 0x1b6: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1bb:
	/* 0x1bb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1be:
	/* 0x1be: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1c3:
	/* 0x1c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c5:
	/* 0x1c5: mov    rsi,QWORD PTR [rip+0x1edb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&lsm_calls)));
x86_l_1cc:
	/* 0x1cc: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1d1:
	/* 0x1d1: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d6:
	/* 0x1d6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d9:
	/* 0x1d9: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1de:
	/* 0x1de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0:
	/* 0x1e0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e2:
	/* 0x1e2: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_1e9:
	/* 0x1e9: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1ea:
	/* 0x1ea: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1ec:
	/* 0x1ec: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1ee:
	/* 0x1ee: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1f0:
	/* 0x1f0: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1f2:
	/* 0x1f2: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1f3:
	/* 0x1f3: jmp    385e <native_bpf_strncasestr+0x72> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f8:
	/* 0x1f8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fa:
	/* 0x1fa: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_202:
	/* 0x202: jne    24f <generic_lsm_filter_arg+0x24f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24f;
	}
x86_l_204:
	/* 0x204: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_209:
	/* 0x209: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_211:
	/* 0x211: jne    24f <generic_lsm_filter_arg+0x24f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24f;
	}
x86_l_213:
	/* 0x213: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_218:
	/* 0x218: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_220:
	/* 0x220: jne    24f <generic_lsm_filter_arg+0x24f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24f;
	}
x86_l_222:
	/* 0x222: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_227:
	/* 0x227: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_22f:
	/* 0x22f: jne    24f <generic_lsm_filter_arg+0x24f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24f;
	}
x86_l_231:
	/* 0x231: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_236:
	/* 0x236: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_23e:
	/* 0x23e: jne    24f <generic_lsm_filter_arg+0x24f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24f;
	}
x86_l_240:
	/* 0x240: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_245:
	/* 0x245: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_24d:
	/* 0x24d: je     271 <generic_lsm_filter_arg+0x271> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_271;
	}
x86_l_24f:
	/* 0x24f: mov    DWORD PTR [r14+0x5f00],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_256:
	/* 0x256: mov    rsi,QWORD PTR [rip+0x1edac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&lsm_calls)));
x86_l_25d:
	/* 0x25d: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_262:
	/* 0x262: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_267:
	/* 0x267: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_26a:
	/* 0x26a: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_26f:
	/* 0x26f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_271:
	/* 0x271: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_275:
	/* 0x275: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_27a:
	/* 0x27a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27c:
	/* 0x27c: mov    QWORD PTR [rsp+0x40],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_281:
	/* 0x281: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_286:
	/* 0x286: mov    rdi,QWORD PTR [rip+0x1edac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_28d:
	/* 0x28d: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_292:
	/* 0x292: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_297:
	/* 0x297: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_299:
	/* 0x299: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29c:
	/* 0x29c: je     1e0 <generic_lsm_filter_arg+0x1e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e0;
	}
x86_l_2a2:
	/* 0x2a2: mov    rdi,QWORD PTR [rip+0x1edac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_2a9:
	/* 0x2a9: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ae:
	/* 0x2ae: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2b3:
	/* 0x2b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5:
	/* 0x2b5: jmp    1e0 <generic_lsm_filter_arg+0x1e0> */
	goto x86_l_1e0;
x86_l_2ba:
	/* 0x2ba: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bc:
	/* 0x2bc: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c1:
	/* 0x2c1: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c6:
	/* 0x2c6: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_2c9:
	/* 0x2c9: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2cc:
	/* 0x2cc: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2d4:
	/* 0x2d4: je     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_117;
	}
x86_l_2da:
	/* 0x2da: inc    r11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2dd:
	/* 0x2dd: cmp    r11,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 5ULL);
x86_l_2e1:
	/* 0x2e1: je     105 <generic_lsm_filter_arg+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_105;
	}
x86_l_2e7:
	/* 0x2e7: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2ef:
	/* 0x2ef: mov    r12d,DWORD PTR [rax+r11*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 2), 4ULL);
x86_l_2f4:
	/* 0x2f4: test   r12d,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1023ULL);
x86_l_2fb:
	/* 0x2fb: je     105 <generic_lsm_filter_arg+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_105;
	}
x86_l_301:
	/* 0x301: add    r12d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_304:
	/* 0x304: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_30b:
	/* 0x30b: mov    eax,DWORD PTR [r15+r12*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_310:
	/* 0x310: cmp    eax,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_313:
	/* 0x313: je     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_117;
	}
x86_l_319:
	/* 0x319: add    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31c:
	/* 0x31c: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_320:
	/* 0x320: cmp    rcx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4ULL);
x86_l_324:
	/* 0x324: ja     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_117;
	}
x86_l_32a:
	/* 0x32a: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_333:
	/* 0x333: jne    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_117;
	}
x86_l_339:
	/* 0x339: mov    rcx,QWORD PTR [r14+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_341:
	/* 0x341: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_347:
	/* 0x347: lea    r13,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_34b:
	/* 0x34b: add    r13,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_352:
	/* 0x352: mov    ecx,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_357:
	/* 0x357: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_35a:
	/* 0x35a: jle    37b <generic_lsm_filter_arg+0x37b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_37b;
	}
x86_l_35c:
	/* 0x35c: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_35f:
	/* 0x35f: jg     3a6 <generic_lsm_filter_arg+0x3a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3a6;
	}
x86_l_361:
	/* 0x361: lea    edx,[rcx-0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551588ULL);
x86_l_364:
	/* 0x364: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_367:
	/* 0x367: jb     3ec <generic_lsm_filter_arg+0x3ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3ec;
	}
x86_l_36d:
	/* 0x36d: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_370:
	/* 0x370: je     612 <generic_lsm_filter_arg+0x612> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_612;
	}
x86_l_376:
	/* 0x376: jmp    2da <generic_lsm_filter_arg+0x2da> */
	goto x86_l_2da;
x86_l_37b:
	/* 0x37b: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_37e:
	/* 0x37e: jle    3cc <generic_lsm_filter_arg+0x3cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3cc;
	}
x86_l_380:
	/* 0x380: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_383:
	/* 0x383: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_386:
	/* 0x386: jb     3ec <generic_lsm_filter_arg+0x3ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3ec;
	}
x86_l_388:
	/* 0x388: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_38b:
	/* 0x38b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_38e:
	/* 0x38e: jb     612 <generic_lsm_filter_arg+0x612> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_612;
	}
x86_l_394:
	/* 0x394: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_397:
	/* 0x397: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2da;
	}
x86_l_39d:
	/* 0x39d: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3a1:
	/* 0x3a1: jmp    612 <generic_lsm_filter_arg+0x612> */
	goto x86_l_612;
x86_l_3a6:
	/* 0x3a6: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_3a9:
	/* 0x3a9: jg     56d <generic_lsm_filter_arg+0x56d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_56d;
	}
x86_l_3af:
	/* 0x3af: lea    edx,[rcx-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_3b2:
	/* 0x3b2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3b5:
	/* 0x3b5: jb     508 <generic_lsm_filter_arg+0x508> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_508;
	}
x86_l_3bb:
	/* 0x3bb: lea    edx,[rcx-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_3be:
	/* 0x3be: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3c1:
	/* 0x3c1: jb     4b3 <generic_lsm_filter_arg+0x4b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4b3;
	}
x86_l_3c7:
	/* 0x3c7: jmp    2da <generic_lsm_filter_arg+0x2da> */
	goto x86_l_2da;
x86_l_3cc:
	/* 0x3cc: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3cf:
	/* 0x3cf: jg     4a0 <generic_lsm_filter_arg+0x4a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4a0;
	}
x86_l_3d5:
	/* 0x3d5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3d8:
	/* 0x3d8: je     3ec <generic_lsm_filter_arg+0x3ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ec;
	}
x86_l_3da:
	/* 0x3da: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3dd:
	/* 0x3dd: je     bcf <generic_lsm_filter_arg+0xbcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3023ULL;
	}
x86_l_3e3:
	/* 0x3e3: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3e6:
	/* 0x3e6: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2da;
	}
x86_l_3ec:
	/* 0x3ec: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_3ef:
	/* 0x3ef: jle    47d <generic_lsm_filter_arg+0x47d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_47d;
	}
x86_l_3f5:
	/* 0x3f5: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_3f8:
	/* 0x3f8: ja     73a <generic_lsm_filter_arg+0x73a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1850ULL;
	}
x86_l_3fe:
	/* 0x3fe: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_400:
	/* 0x400: movabs rsi,0x1e00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 128849018880ULL);
x86_l_40a:
	/* 0x40a: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_40e:
	/* 0x40e: jb     541 <generic_lsm_filter_arg+0x541> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_541;
	}
x86_l_414:
	/* 0x414: mov    esi,0x60000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1610612736ULL);
x86_l_419:
	/* 0x419: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_41d:
	/* 0x41d: jb     995 <generic_lsm_filter_arg+0x995> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2453ULL;
	}
x86_l_423:
	/* 0x423: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_42d:
	/* 0x42d: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_431:
	/* 0x431: jae    73a <generic_lsm_filter_arg+0x73a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 1850ULL;
	}
x86_l_437:
	/* 0x437: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_43a:
	/* 0x43a: ja     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_117;
	}
x86_l_440:
	/* 0x440: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_442:
	/* 0x442: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_447:
	/* 0x447: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_44b:
	/* 0x44b: jae    110a <generic_lsm_filter_arg+0x110a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4362ULL;
	}
x86_l_451:
	/* 0x451: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_456:
	/* 0x456: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_459:
	/* 0x459: jle    1684 <generic_lsm_filter_arg+0x1684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5764ULL;
	}
x86_l_45f:
	/* 0x45f: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_462:
	/* 0x462: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_465:
	/* 0x465: jae    1e73 <generic_lsm_filter_arg+0x1e73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7795ULL;
	}
x86_l_46b:
	/* 0x46b: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_470:
	/* 0x470: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_472:
	/* 0x472: jne    1fb7 <generic_lsm_filter_arg+0x1fb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8119ULL;
	}
x86_l_478:
	/* 0x478: jmp    367c <generic_lsm_filter_arg+0x367c> */
	return 13948ULL;
x86_l_47d:
	/* 0x47d: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_480:
	/* 0x480: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_483:
	/* 0x483: jb     c4e <generic_lsm_filter_arg+0xc4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3150ULL;
	}
x86_l_489:
	/* 0x489: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_48c:
	/* 0x48c: je     746 <generic_lsm_filter_arg+0x746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1862ULL;
	}
x86_l_492:
	/* 0x492: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_495:
	/* 0x495: je     746 <generic_lsm_filter_arg+0x746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1862ULL;
	}
x86_l_49b:
	/* 0x49b: jmp    2da <generic_lsm_filter_arg+0x2da> */
	goto x86_l_2da;
x86_l_4a0:
	/* 0x4a0: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4a3:
	/* 0x4a3: je     4b3 <generic_lsm_filter_arg+0x4b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b3;
	}
x86_l_4a5:
	/* 0x4a5: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4a8:
	/* 0x4a8: je     508 <generic_lsm_filter_arg+0x508> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_508;
	}
x86_l_4aa:
	/* 0x4aa: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_4ad:
	/* 0x4ad: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2da;
	}
x86_l_4b3:
	/* 0x4b3: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_4bc:
	/* 0x4bc: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_4c5:
	/* 0x4c5: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_4ce:
	/* 0x4ce: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4d7:
	/* 0x4d7: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_4e0:
	/* 0x4e0: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_4e3:
	/* 0x4e3: jg     785 <generic_lsm_filter_arg+0x785> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1925ULL;
	}
x86_l_4e9:
	/* 0x4e9: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4ec:
	/* 0x4ec: je     dbe <generic_lsm_filter_arg+0xdbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3518ULL;
	}
x86_l_4f2:
	/* 0x4f2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4f5:
	/* 0x4f5: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_4fa:
	/* 0x4fa: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_4fd:
	/* 0x4fd: je     dc0 <generic_lsm_filter_arg+0xdc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3520ULL;
	}
x86_l_503:
	/* 0x503: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	goto x86_l_2c9;
x86_l_508:
	/* 0x508: mov    ebp,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50c:
	/* 0x50c: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_510:
	/* 0x510: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_513:
	/* 0x513: jg     80a <generic_lsm_filter_arg+0x80a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2058ULL;
	}
x86_l_519:
	/* 0x519: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_51c:
	/* 0x51c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_51f:
	/* 0x51f: jb     1025 <generic_lsm_filter_arg+0x1025> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4133ULL;
	}
x86_l_525:
	/* 0x525: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_528:
	/* 0x528: je     f86 <generic_lsm_filter_arg+0xf86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3974ULL;
	}
x86_l_52e:
	/* 0x52e: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_533:
	/* 0x533: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_536:
	/* 0x536: je     82a <generic_lsm_filter_arg+0x82a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2090ULL;
	}
x86_l_53c:
	/* 0x53c: jmp    3754 <generic_lsm_filter_arg+0x3754> */
	return 14164ULL;
x86_l_541:
	/* 0x541: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_544:
	/* 0x544: jle    bbe <generic_lsm_filter_arg+0xbbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3006ULL;
	}
x86_l_54a:
	/* 0x54a: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_54d:
	/* 0x54d: jg     f3e <generic_lsm_filter_arg+0xf3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3902ULL;
	}
x86_l_553:
	/* 0x553: lea    edx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_556:
	/* 0x556: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_559:
	/* 0x559: jb     cdc <generic_lsm_filter_arg+0xcdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3292ULL;
	}
x86_l_55f:
	/* 0x55f: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_562:
	/* 0x562: je     c64 <generic_lsm_filter_arg+0xc64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3172ULL;
	}
x86_l_568:
	/* 0x568: jmp    117 <generic_lsm_filter_arg+0x117> */
	goto x86_l_117;
x86_l_56d:
	/* 0x56d: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_570:
	/* 0x570: je     612 <generic_lsm_filter_arg+0x612> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_612;
	}
x86_l_576:
	/* 0x576: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_579:
	/* 0x579: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2da;
	}
x86_l_57f:
	/* 0x57f: lea    rsi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_583:
	/* 0x583: movzx  r8d,BYTE PTR [r13+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_588:
	/* 0x588: movzx  ebp,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_58c:
	/* 0x58c: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_58f:
	/* 0x58f: jg     13f9 <generic_lsm_filter_arg+0x13f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5113ULL;
	}
x86_l_595:
	/* 0x595: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_598:
	/* 0x598: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_59b:
	/* 0x59b: jae    19bc <generic_lsm_filter_arg+0x19bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6588ULL;
	}
x86_l_5a1:
	/* 0x5a1: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_5ac:
	/* 0x5ac: mov    r10d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 256ULL);
x86_l_5b2:
	/* 0x5b2: cmp    bpl,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 144ULL);
x86_l_5b6:
	/* 0x5b6: ja     175e <generic_lsm_filter_arg+0x175e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5982ULL;
	}
x86_l_5bc:
	/* 0x5bc: movzx  eax,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5c0:
	/* 0x5c0: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_5c6:
	/* 0x5c6: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_5c9:
	/* 0x5c9: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_5cc:
	/* 0x5cc: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_5cf:
	/* 0x5cf: mov    eax,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_5d2:
	/* 0x5d2: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5d4:
	/* 0x5d4: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_5d7:
	/* 0x5d7: je     5e0 <generic_lsm_filter_arg+0x5e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e0;
	}
x86_l_5d9:
	/* 0x5d9: mov    r10d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RBP, X86_WIDTH_32);
x86_l_5dc:
	/* 0x5dc: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_5de:
	/* 0x5de: je     5fb <generic_lsm_filter_arg+0x5fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fb;
	}
x86_l_5e0:
	/* 0x5e0: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5e3:
	/* 0x5e3: movzx  ecx,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5e6:
	/* 0x5e6: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5e8:
	/* 0x5e8: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_5ea:
	/* 0x5ea: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_5ed:
	/* 0x5ed: movzx  r10d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5f1:
	/* 0x5f1: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_5f5:
	/* 0x5f5: ja     175e <generic_lsm_filter_arg+0x175e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5982ULL;
	}
x86_l_5fb:
	/* 0x5fb: movzx  eax,r10b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R10, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5ff:
	/* 0x5ff: imul   r13d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R13, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_606:
	/* 0x606: shr    r13d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_60a:
	/* 0x60a: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_60d:
	/* 0x60d: jmp    2640 <generic_lsm_filter_arg+0x2640> */
	return 9792ULL;
x86_l_612:
	/* 0x612: mov    ebp,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_616:
	/* 0x616: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_618:
	/* 0x618: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_61b:
	/* 0x61b: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_61e:
	/* 0x61e: je     628 <generic_lsm_filter_arg+0x628> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_628;
	}
x86_l_620:
	/* 0x620: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_622:
	/* 0x622: je     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_117;
	}
x86_l_628:
	/* 0x628: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_62b:
	/* 0x62b: ja     960 <generic_lsm_filter_arg+0x960> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2400ULL;
	}
x86_l_631:
	/* 0x631: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_633:
	/* 0x633: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_638:
	/* 0x638: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_63c:
	/* 0x63c: jb     b15 <generic_lsm_filter_arg+0xb15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2837ULL;
	}
x86_l_642:
	/* 0x642: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_647:
	/* 0x647: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_64b:
	/* 0x64b: jb     9db <generic_lsm_filter_arg+0x9db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2523ULL;
	}
x86_l_651:
	/* 0x651: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_65b:
	/* 0x65b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_65f:
	/* 0x65f: jae    960 <generic_lsm_filter_arg+0x960> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2400ULL;
	}
x86_l_665:
	/* 0x665: mov    WORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_66c:
	/* 0x66c: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_672:
	/* 0x672: ja     97f <generic_lsm_filter_arg+0x97f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2431ULL;
	}
x86_l_678:
	/* 0x678: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_67b:
	/* 0x67b: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_67e:
	/* 0x67e: lea    rcx,[rsi+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_682:
	/* 0x682: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_686:
	/* 0x686: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_68b:
	/* 0x68b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_690:
	/* 0x690: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_695:
	/* 0x695: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_697:
	/* 0x697: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_69b:
	/* 0x69b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_69f:
	/* 0x69f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_6a4:
	/* 0x6a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a6:
	/* 0x6a6: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 1707ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1707ULL: goto x86_l_6ab;
	case 1709ULL: goto x86_l_6ad;
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1725ULL: goto x86_l_6bd;
	case 1730ULL: goto x86_l_6c2;
	case 1732ULL: goto x86_l_6c4;
	case 1738ULL: goto x86_l_6ca;
	case 1743ULL: goto x86_l_6cf;
	case 1746ULL: goto x86_l_6d2;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1759ULL: goto x86_l_6df;
	case 1765ULL: goto x86_l_6e5;
	case 1770ULL: goto x86_l_6ea;
	case 1772ULL: goto x86_l_6ec;
	case 1778ULL: goto x86_l_6f2;
	case 1780ULL: goto x86_l_6f4;
	case 1786ULL: goto x86_l_6fa;
	case 1789ULL: goto x86_l_6fd;
	case 1795ULL: goto x86_l_703;
	case 1800ULL: goto x86_l_708;
	case 1802ULL: goto x86_l_70a;
	case 1808ULL: goto x86_l_710;
	case 1810ULL: goto x86_l_712;
	case 1816ULL: goto x86_l_718;
	case 1819ULL: goto x86_l_71b;
	case 1825ULL: goto x86_l_721;
	case 1830ULL: goto x86_l_726;
	case 1832ULL: goto x86_l_728;
	case 1838ULL: goto x86_l_72e;
	case 1840ULL: goto x86_l_730;
	case 1842ULL: goto x86_l_732;
	case 1845ULL: goto x86_l_735;
	case 1850ULL: goto x86_l_73a;
	case 1853ULL: goto x86_l_73d;
	case 1856ULL: goto x86_l_740;
	case 1862ULL: goto x86_l_746;
	case 1865ULL: goto x86_l_749;
	case 1871ULL: goto x86_l_74f;
	case 1873ULL: goto x86_l_751;
	case 1878ULL: goto x86_l_756;
	case 1882ULL: goto x86_l_75a;
	case 1884ULL: goto x86_l_75c;
	case 1889ULL: goto x86_l_761;
	case 1892ULL: goto x86_l_764;
	case 1898ULL: goto x86_l_76a;
	case 1901ULL: goto x86_l_76d;
	case 1904ULL: goto x86_l_770;
	case 1910ULL: goto x86_l_776;
	case 1914ULL: goto x86_l_77a;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1928ULL: goto x86_l_788;
	case 1934ULL: goto x86_l_78e;
	case 1937ULL: goto x86_l_791;
	case 1942ULL: goto x86_l_796;
	case 1945ULL: goto x86_l_799;
	case 1951ULL: goto x86_l_79f;
	case 1956ULL: goto x86_l_7a4;
	case 1961ULL: goto x86_l_7a9;
	case 1965ULL: goto x86_l_7ad;
	case 1971ULL: goto x86_l_7b3;
	case 1981ULL: goto x86_l_7bd;
	case 1985ULL: goto x86_l_7c1;
	case 1991ULL: goto x86_l_7c7;
	case 1994ULL: goto x86_l_7ca;
	case 2000ULL: goto x86_l_7d0;
	case 2005ULL: goto x86_l_7d5;
	case 2010ULL: goto x86_l_7da;
	case 2013ULL: goto x86_l_7dd;
	case 2019ULL: goto x86_l_7e3;
	case 2024ULL: goto x86_l_7e8;
	case 2027ULL: goto x86_l_7eb;
	case 2033ULL: goto x86_l_7f1;
	case 2037ULL: goto x86_l_7f5;
	case 2039ULL: goto x86_l_7f7;
	case 2045ULL: goto x86_l_7fd;
	case 2047ULL: goto x86_l_7ff;
	case 2053ULL: goto x86_l_805;
	case 2058ULL: goto x86_l_80a;
	case 2061ULL: goto x86_l_80d;
	case 2067ULL: goto x86_l_813;
	case 2070ULL: goto x86_l_816;
	case 2076ULL: goto x86_l_81c;
	case 2081ULL: goto x86_l_821;
	case 2084ULL: goto x86_l_824;
	case 2090ULL: goto x86_l_82a;
	case 2095ULL: goto x86_l_82f;
	case 2100ULL: goto x86_l_834;
	case 2104ULL: goto x86_l_838;
	case 2115ULL: goto x86_l_843;
	case 2120ULL: goto x86_l_848;
	case 2125ULL: goto x86_l_84d;
	case 2132ULL: goto x86_l_854;
	case 2134ULL: goto x86_l_856;
	case 2136ULL: goto x86_l_858;
	case 2142ULL: goto x86_l_85e;
	case 2147ULL: goto x86_l_863;
	case 2150ULL: goto x86_l_866;
	case 2156ULL: goto x86_l_86c;
	case 2161ULL: goto x86_l_871;
	case 2166ULL: goto x86_l_876;
	case 2171ULL: goto x86_l_87b;
	case 2178ULL: goto x86_l_882;
	case 2180ULL: goto x86_l_884;
	case 2183ULL: goto x86_l_887;
	case 2189ULL: goto x86_l_88d;
	case 2192ULL: goto x86_l_890;
	case 2195ULL: goto x86_l_893;
	case 2200ULL: goto x86_l_898;
	case 2203ULL: goto x86_l_89b;
	case 2206ULL: goto x86_l_89e;
	case 2208ULL: goto x86_l_8a0;
	case 2211ULL: goto x86_l_8a3;
	case 2214ULL: goto x86_l_8a6;
	case 2219ULL: goto x86_l_8ab;
	case 2222ULL: goto x86_l_8ae;
	case 2225ULL: goto x86_l_8b1;
	case 2230ULL: goto x86_l_8b6;
	case 2234ULL: goto x86_l_8ba;
	case 2240ULL: goto x86_l_8c0;
	case 2243ULL: goto x86_l_8c3;
	case 2247ULL: goto x86_l_8c7;
	case 2253ULL: goto x86_l_8cd;
	case 2256ULL: goto x86_l_8d0;
	case 2260ULL: goto x86_l_8d4;
	case 2262ULL: goto x86_l_8d6;
	case 2264ULL: goto x86_l_8d8;
	case 2267ULL: goto x86_l_8db;
	case 2271ULL: goto x86_l_8df;
	case 2278ULL: goto x86_l_8e6;
	case 2283ULL: goto x86_l_8eb;
	case 2287ULL: goto x86_l_8ef;
	case 2290ULL: goto x86_l_8f2;
	case 2292ULL: goto x86_l_8f4;
	case 2296ULL: goto x86_l_8f8;
	case 2303ULL: goto x86_l_8ff;
	case 2308ULL: goto x86_l_904;
	case 2312ULL: goto x86_l_908;
	case 2315ULL: goto x86_l_90b;
	case 2317ULL: goto x86_l_90d;
	case 2321ULL: goto x86_l_911;
	case 2328ULL: goto x86_l_918;
	case 2333ULL: goto x86_l_91d;
	case 2337ULL: goto x86_l_921;
	case 2340ULL: goto x86_l_924;
	case 2342ULL: goto x86_l_926;
	case 2346ULL: goto x86_l_92a;
	case 2348ULL: goto x86_l_92c;
	case 2352ULL: goto x86_l_930;
	case 2359ULL: goto x86_l_937;
	case 2364ULL: goto x86_l_93c;
	case 2367ULL: goto x86_l_93f;
	case 2371ULL: goto x86_l_943;
	case 2375ULL: goto x86_l_947;
	case 2378ULL: goto x86_l_94a;
	case 2380ULL: goto x86_l_94c;
	case 2385ULL: goto x86_l_951;
	case 2390ULL: goto x86_l_956;
	case 2395ULL: goto x86_l_95b;
	case 2400ULL: goto x86_l_960;
	case 2403ULL: goto x86_l_963;
	case 2406ULL: goto x86_l_966;
	case 2408ULL: goto x86_l_968;
	case 2419ULL: goto x86_l_973;
	case 2425ULL: goto x86_l_979;
	case 2431ULL: goto x86_l_97f;
	case 2433ULL: goto x86_l_981;
	case 2438ULL: goto x86_l_986;
	case 2442ULL: goto x86_l_98a;
	case 2448ULL: goto x86_l_990;
	case 2453ULL: goto x86_l_995;
	case 2456ULL: goto x86_l_998;
	case 2462ULL: goto x86_l_99e;
	case 2464ULL: goto x86_l_9a0;
	case 2469ULL: goto x86_l_9a5;
	case 2473ULL: goto x86_l_9a9;
	case 2479ULL: goto x86_l_9af;
	case 2484ULL: goto x86_l_9b4;
	case 2487ULL: goto x86_l_9b7;
	case 2493ULL: goto x86_l_9bd;
	case 2496ULL: goto x86_l_9c0;
	case 2499ULL: goto x86_l_9c3;
	case 2505ULL: goto x86_l_9c9;
	case 2510ULL: goto x86_l_9ce;
	case 2512ULL: goto x86_l_9d0;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2537ULL: goto x86_l_9e9;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2558ULL: goto x86_l_9fe;
	case 2565ULL: goto x86_l_a05;
	case 2567ULL: goto x86_l_a07;
	case 2569ULL: goto x86_l_a09;
	case 2575ULL: goto x86_l_a0f;
	case 2580ULL: goto x86_l_a14;
	case 2583ULL: goto x86_l_a17;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2599ULL: goto x86_l_a27;
	case 2604ULL: goto x86_l_a2c;
	case 2611ULL: goto x86_l_a33;
	case 2613ULL: goto x86_l_a35;
	case 2616ULL: goto x86_l_a38;
	case 2622ULL: goto x86_l_a3e;
	case 2625ULL: goto x86_l_a41;
	case 2628ULL: goto x86_l_a44;
	case 2633ULL: goto x86_l_a49;
	case 2636ULL: goto x86_l_a4c;
	case 2639ULL: goto x86_l_a4f;
	case 2641ULL: goto x86_l_a51;
	case 2644ULL: goto x86_l_a54;
	case 2647ULL: goto x86_l_a57;
	case 2652ULL: goto x86_l_a5c;
	case 2655ULL: goto x86_l_a5f;
	case 2658ULL: goto x86_l_a62;
	case 2663ULL: goto x86_l_a67;
	case 2667ULL: goto x86_l_a6b;
	case 2673ULL: goto x86_l_a71;
	case 2676ULL: goto x86_l_a74;
	case 2680ULL: goto x86_l_a78;
	case 2686ULL: goto x86_l_a7e;
	case 2689ULL: goto x86_l_a81;
	case 2693ULL: goto x86_l_a85;
	case 2695ULL: goto x86_l_a87;
	case 2697ULL: goto x86_l_a89;
	case 2700ULL: goto x86_l_a8c;
	case 2704ULL: goto x86_l_a90;
	case 2711ULL: goto x86_l_a97;
	case 2717ULL: goto x86_l_a9d;
	case 2721ULL: goto x86_l_aa1;
	case 2724ULL: goto x86_l_aa4;
	case 2726ULL: goto x86_l_aa6;
	case 2730ULL: goto x86_l_aaa;
	case 2737ULL: goto x86_l_ab1;
	case 2743ULL: goto x86_l_ab7;
	case 2747ULL: goto x86_l_abb;
	case 2750ULL: goto x86_l_abe;
	case 2752ULL: goto x86_l_ac0;
	case 2756ULL: goto x86_l_ac4;
	case 2763ULL: goto x86_l_acb;
	case 2769ULL: goto x86_l_ad1;
	case 2773ULL: goto x86_l_ad5;
	case 2776ULL: goto x86_l_ad8;
	case 2778ULL: goto x86_l_ada;
	case 2782ULL: goto x86_l_ade;
	case 2784ULL: goto x86_l_ae0;
	case 2788ULL: goto x86_l_ae4;
	case 2795ULL: goto x86_l_aeb;
	case 2801ULL: goto x86_l_af1;
	case 2804ULL: goto x86_l_af4;
	case 2808ULL: goto x86_l_af8;
	case 2812ULL: goto x86_l_afc;
	case 2815ULL: goto x86_l_aff;
	case 2817ULL: goto x86_l_b01;
	case 2822ULL: goto x86_l_b06;
	case 2827ULL: goto x86_l_b0b;
	case 2832ULL: goto x86_l_b10;
	case 2837ULL: goto x86_l_b15;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2852ULL: goto x86_l_b24;
	case 2856ULL: goto x86_l_b28;
	case 2867ULL: goto x86_l_b33;
	case 2872ULL: goto x86_l_b38;
	case 2877ULL: goto x86_l_b3d;
	case 2884ULL: goto x86_l_b44;
	case 2886ULL: goto x86_l_b46;
	case 2888ULL: goto x86_l_b48;
	case 2894ULL: goto x86_l_b4e;
	case 2897ULL: goto x86_l_b51;
	case 2902ULL: goto x86_l_b56;
	case 2905ULL: goto x86_l_b59;
	case 2911ULL: goto x86_l_b5f;
	case 2916ULL: goto x86_l_b64;
	case 2921ULL: goto x86_l_b69;
	case 2928ULL: goto x86_l_b70;
	case 2930ULL: goto x86_l_b72;
	case 2933ULL: goto x86_l_b75;
	case 2939ULL: goto x86_l_b7b;
	case 2942ULL: goto x86_l_b7e;
	case 2947ULL: goto x86_l_b83;
	case 2951ULL: goto x86_l_b87;
	case 2957ULL: goto x86_l_b8d;
	case 2962ULL: goto x86_l_b92;
	case 2965ULL: goto x86_l_b95;
	case 2972ULL: goto x86_l_b9c;
	case 2974ULL: goto x86_l_b9e;
	case 2977ULL: goto x86_l_ba1;
	case 2981ULL: goto x86_l_ba5;
	case 2986ULL: goto x86_l_baa;
	case 2988ULL: goto x86_l_bac;
	case 2990ULL: goto x86_l_bae;
	case 2995ULL: goto x86_l_bb3;
	case 2998ULL: goto x86_l_bb6;
	case 3001ULL: goto x86_l_bb9;
	case 3006ULL: goto x86_l_bbe;
	case 3009ULL: goto x86_l_bc1;
	case 3012ULL: goto x86_l_bc4;
	case 3018ULL: goto x86_l_bca;
	case 3023ULL: goto x86_l_bcf;
	case 3027ULL: goto x86_l_bd3;
	case 3031ULL: goto x86_l_bd7;
	case 3034ULL: goto x86_l_bda;
	case 3040ULL: goto x86_l_be0;
	case 3043ULL: goto x86_l_be3;
	case 3046ULL: goto x86_l_be6;
	case 3052ULL: goto x86_l_bec;
	case 3057ULL: goto x86_l_bf1;
	case 3060ULL: goto x86_l_bf4;
	case 3066ULL: goto x86_l_bfa;
	case 3071ULL: goto x86_l_bff;
	case 3074ULL: goto x86_l_c02;
	case 3080ULL: goto x86_l_c08;
	case 3085ULL: goto x86_l_c0d;
	case 3088ULL: goto x86_l_c10;
	case 3094ULL: goto x86_l_c16;
	case 3097ULL: goto x86_l_c19;
	case 3103ULL: goto x86_l_c1f;
	case 3106ULL: goto x86_l_c22;
	case 3112ULL: goto x86_l_c28;
	case 3117ULL: goto x86_l_c2d;
	case 3120ULL: goto x86_l_c30;
	case 3126ULL: goto x86_l_c36;
	case 3130ULL: goto x86_l_c3a;
	case 3136ULL: goto x86_l_c40;
	case 3141ULL: goto x86_l_c45;
	case 3144ULL: goto x86_l_c48;
	case 3150ULL: goto x86_l_c4e;
	case 3153ULL: goto x86_l_c51;
	case 3159ULL: goto x86_l_c57;
	case 3161ULL: goto x86_l_c59;
	case 3166ULL: goto x86_l_c5e;
	case 3170ULL: goto x86_l_c62;
	case 3172ULL: goto x86_l_c64;
	case 3177ULL: goto x86_l_c69;
	case 3180ULL: goto x86_l_c6c;
	case 3182ULL: goto x86_l_c6e;
	case 3185ULL: goto x86_l_c71;
	case 3188ULL: goto x86_l_c74;
	case 3194ULL: goto x86_l_c7a;
	case 3198ULL: goto x86_l_c7e;
	case 3204ULL: goto x86_l_c84;
	case 3209ULL: goto x86_l_c89;
	case 3214ULL: goto x86_l_c8e;
	case 3218ULL: goto x86_l_c92;
	case 3220ULL: goto x86_l_c94;
	case 3230ULL: goto x86_l_c9e;
	case 3234ULL: goto x86_l_ca2;
	case 3240ULL: goto x86_l_ca8;
	case 3245ULL: goto x86_l_cad;
	case 3248ULL: goto x86_l_cb0;
	case 3254ULL: goto x86_l_cb6;
	case 3257ULL: goto x86_l_cb9;
	case 3263ULL: goto x86_l_cbf;
	case 3266ULL: goto x86_l_cc2;
	case 3268ULL: goto x86_l_cc4;
	case 3271ULL: goto x86_l_cc7;
	case 3277ULL: goto x86_l_ccd;
	case 3281ULL: goto x86_l_cd1;
	case 3287ULL: goto x86_l_cd7;
	case 3292ULL: goto x86_l_cdc;
	case 3295ULL: goto x86_l_cdf;
	case 3298ULL: goto x86_l_ce2;
	case 3304ULL: goto x86_l_ce8;
	case 3311ULL: goto x86_l_cef;
	case 3316ULL: goto x86_l_cf4;
	case 3321ULL: goto x86_l_cf9;
	case 3328ULL: goto x86_l_d00;
	case 3330ULL: goto x86_l_d02;
	case 3333ULL: goto x86_l_d05;
	case 3339ULL: goto x86_l_d0b;
	case 3342ULL: goto x86_l_d0e;
	case 3345ULL: goto x86_l_d11;
	case 3350ULL: goto x86_l_d16;
	case 3355ULL: goto x86_l_d1b;
	case 3360ULL: goto x86_l_d20;
	case 3362ULL: goto x86_l_d22;
	case 3367ULL: goto x86_l_d27;
	case 3370ULL: goto x86_l_d2a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6ab:
	/* 0x6ab: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_6ad:
	/* 0x6ad: je     1d0a <generic_lsm_filter_arg+0x1d0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7434ULL;
	}
x86_l_6b3:
	/* 0x6b3: movzx  eax,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_6b8:
	/* 0x6b8: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_6bd:
	/* 0x6bd: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_6c2:
	/* 0x6c2: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6c4:
	/* 0x6c4: je     1d0c <generic_lsm_filter_arg+0x1d0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7436ULL;
	}
x86_l_6ca:
	/* 0x6ca: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6cf:
	/* 0x6cf: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_6d2:
	/* 0x6d2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d7:
	/* 0x6d7: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6dc:
	/* 0x6dc: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_6df:
	/* 0x6df: jb     97f <generic_lsm_filter_arg+0x97f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_97f;
	}
x86_l_6e5:
	/* 0x6e5: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6ea:
	/* 0x6ea: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_6ec:
	/* 0x6ec: je     97f <generic_lsm_filter_arg+0x97f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_97f;
	}
x86_l_6f2:
	/* 0x6f2: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_6f4:
	/* 0x6f4: je     33af <generic_lsm_filter_arg+0x33af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13231ULL;
	}
x86_l_6fa:
	/* 0x6fa: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6fd:
	/* 0x6fd: jb     97f <generic_lsm_filter_arg+0x97f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_97f;
	}
x86_l_703:
	/* 0x703: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_708:
	/* 0x708: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_70a:
	/* 0x70a: je     97f <generic_lsm_filter_arg+0x97f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_97f;
	}
x86_l_710:
	/* 0x710: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_712:
	/* 0x712: je     33af <generic_lsm_filter_arg+0x33af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13231ULL;
	}
x86_l_718:
	/* 0x718: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_71b:
	/* 0x71b: jb     3787 <generic_lsm_filter_arg+0x3787> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14215ULL;
	}
x86_l_721:
	/* 0x721: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_726:
	/* 0x726: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_728:
	/* 0x728: je     3787 <generic_lsm_filter_arg+0x3787> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14215ULL;
	}
x86_l_72e:
	/* 0x72e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_730:
	/* 0x730: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_732:
	/* 0x732: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_735:
	/* 0x735: jmp    3789 <generic_lsm_filter_arg+0x3789> */
	return 14217ULL;
x86_l_73a:
	/* 0x73a: lea    edx,[rcx-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_73d:
	/* 0x73d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_740:
	/* 0x740: jae    c45 <generic_lsm_filter_arg+0xc45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_c45;
	}
x86_l_746:
	/* 0x746: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_749:
	/* 0x749: ja     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 279ULL;
	}
x86_l_74f:
	/* 0x74f: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_751:
	/* 0x751: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_756:
	/* 0x756: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_75a:
	/* 0x75a: jae    7a4 <generic_lsm_filter_arg+0x7a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_7a4;
	}
x86_l_75c:
	/* 0x75c: mov    edx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_761:
	/* 0x761: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_764:
	/* 0x764: jle    c0d <generic_lsm_filter_arg+0xc0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c0d;
	}
x86_l_76a:
	/* 0x76a: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_76d:
	/* 0x76d: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_770:
	/* 0x770: jae    10f2 <generic_lsm_filter_arg+0x10f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4338ULL;
	}
x86_l_776:
	/* 0x776: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77a:
	/* 0x77a: jne    22fa <generic_lsm_filter_arg+0x22fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8954ULL;
	}
x86_l_780:
	/* 0x780: jmp    367c <generic_lsm_filter_arg+0x367c> */
	return 13948ULL;
x86_l_785:
	/* 0x785: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_788:
	/* 0x788: je     d93 <generic_lsm_filter_arg+0xd93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3475ULL;
	}
x86_l_78e:
	/* 0x78e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_791:
	/* 0x791: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_796:
	/* 0x796: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_799:
	/* 0x799: je     dc0 <generic_lsm_filter_arg+0xdc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3520ULL;
	}
x86_l_79f:
	/* 0x79f: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_7a4:
	/* 0x7a4: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_7a9:
	/* 0x7a9: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_7ad:
	/* 0x7ad: jb     d4b <generic_lsm_filter_arg+0xd4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3403ULL;
	}
x86_l_7b3:
	/* 0x7b3: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_7bd:
	/* 0x7bd: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_7c1:
	/* 0x7c1: jae    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 279ULL;
	}
x86_l_7c7:
	/* 0x7c7: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_7ca:
	/* 0x7ca: jne    13c4 <generic_lsm_filter_arg+0x13c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5060ULL;
	}
x86_l_7d0:
	/* 0x7d0: mov    esi,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7d5:
	/* 0x7d5: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7da:
	/* 0x7da: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_7dd:
	/* 0x7dd: ja     2038 <generic_lsm_filter_arg+0x2038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8248ULL;
	}
x86_l_7e3:
	/* 0x7e3: mov    eax,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5122ULL);
x86_l_7e8:
	/* 0x7e8: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_7eb:
	/* 0x7eb: jae    2038 <generic_lsm_filter_arg+0x2038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8248ULL;
	}
x86_l_7f1:
	/* 0x7f1: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7f5:
	/* 0x7f5: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_7f7:
	/* 0x7f7: jg     2048 <generic_lsm_filter_arg+0x2048> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8264ULL;
	}
x86_l_7fd:
	/* 0x7fd: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_7ff:
	/* 0x7ff: jle    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 730ULL;
	}
x86_l_805:
	/* 0x805: jmp    2048 <generic_lsm_filter_arg+0x2048> */
	return 8264ULL;
x86_l_80a:
	/* 0x80a: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_80d:
	/* 0x80d: jg     e44 <generic_lsm_filter_arg+0xe44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3652ULL;
	}
x86_l_813:
	/* 0x813: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_816:
	/* 0x816: je     f86 <generic_lsm_filter_arg+0xf86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3974ULL;
	}
x86_l_81c:
	/* 0x81c: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_821:
	/* 0x821: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_824:
	/* 0x824: jne    3754 <generic_lsm_filter_arg+0x3754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14164ULL;
	}
x86_l_82a:
	/* 0x82a: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_82f:
	/* 0x82f: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_834:
	/* 0x834: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_838:
	/* 0x838: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_843:
	/* 0x843: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_848:
	/* 0x848: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_84d:
	/* 0x84d: mov    rdi,QWORD PTR [rip+0x1edb3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_854:
	/* 0x854: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_856:
	/* 0x856: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_858:
	/* 0x858: je     3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14147ULL;
	}
x86_l_85e:
	/* 0x85e: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_863:
	/* 0x863: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_866:
	/* 0x866: je     3745 <generic_lsm_filter_arg+0x3745> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14149ULL;
	}
x86_l_86c:
	/* 0x86c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_871:
	/* 0x871: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_876:
	/* 0x876: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_87b:
	/* 0x87b: mov    rdi,QWORD PTR [rip+0x1edb3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_882:
	/* 0x882: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_884:
	/* 0x884: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_887:
	/* 0x887: je     3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14147ULL;
	}
x86_l_88d:
	/* 0x88d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_890:
	/* 0x890: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_893:
	/* 0x893: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_898:
	/* 0x898: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_89b:
	/* 0x89b: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_89e:
	/* 0x89e: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a0:
	/* 0x8a0: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_8a3:
	/* 0x8a3: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_8a6:
	/* 0x8a6: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_8ab:
	/* 0x8ab: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8ae:
	/* 0x8ae: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_8b1:
	/* 0x8b1: mov    QWORD PTR [rsp+0x70],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8b6:
	/* 0x8b6: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_8ba:
	/* 0x8ba: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_8c0:
	/* 0x8c0: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8c3:
	/* 0x8c3: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_8c7:
	/* 0x8c7: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_8cd:
	/* 0x8cd: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8d0:
	/* 0x8d0: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_8d4:
	/* 0x8d4: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_8d6:
	/* 0x8d6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8d8:
	/* 0x8d8: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_8db:
	/* 0x8db: lea    r13d,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_8df:
	/* 0x8df: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8e6:
	/* 0x8e6: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_8eb:
	/* 0x8eb: mov    BYTE PTR [rdi-0x3],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_8ef:
	/* 0x8ef: cmp    r10,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RBX, X86_WIDTH_64);
x86_l_8f2:
	/* 0x8f2: je     94c <generic_lsm_filter_arg+0x94c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_94c;
	}
x86_l_8f4:
	/* 0x8f4: lea    r13d,[r11+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_8f8:
	/* 0x8f8: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8ff:
	/* 0x8ff: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_904:
	/* 0x904: mov    BYTE PTR [rdi-0x2],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_908:
	/* 0x908: cmp    r8,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RBX, X86_WIDTH_64);
x86_l_90b:
	/* 0x90b: je     94c <generic_lsm_filter_arg+0x94c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_94c;
	}
x86_l_90d:
	/* 0x90d: lea    r13d,[r9+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_911:
	/* 0x911: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_918:
	/* 0x918: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_91d:
	/* 0x91d: mov    BYTE PTR [rdi-0x1],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_921:
	/* 0x921: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_924:
	/* 0x924: je     94c <generic_lsm_filter_arg+0x94c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_94c;
	}
x86_l_926:
	/* 0x926: cmp    rbx,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_92a:
	/* 0x92a: je     94c <generic_lsm_filter_arg+0x94c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_94c;
	}
x86_l_92c:
	/* 0x92c: lea    r13d,[rdx+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_930:
	/* 0x930: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_937:
	/* 0x937: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_93c:
	/* 0x93c: mov    BYTE PTR [rdi],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_93f:
	/* 0x93f: add    rbx,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_943:
	/* 0x943: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_947:
	/* 0x947: cmp    rax,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_94a:
	/* 0x94a: jne    8db <generic_lsm_filter_arg+0x8db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8db;
	}
x86_l_94c:
	/* 0x94c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_951:
	/* 0x951: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_956:
	/* 0x956: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_95b:
	/* 0x95b: jmp    1b4c <generic_lsm_filter_arg+0x1b4c> */
	return 6988ULL;
x86_l_960:
	/* 0x960: add    eax,0xfffffffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967293ULL);
x86_l_963:
	/* 0x963: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_966:
	/* 0x966: jae    97f <generic_lsm_filter_arg+0x97f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_97f;
	}
x86_l_968:
	/* 0x968: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_973:
	/* 0x973: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_979:
	/* 0x979: jbe    11fc <generic_lsm_filter_arg+0x11fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4604ULL;
	}
x86_l_97f:
	/* 0x97f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_981:
	/* 0x981: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_986:
	/* 0x986: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_98a:
	/* 0x98a: jbe    33be <generic_lsm_filter_arg+0x33be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13246ULL;
	}
x86_l_990:
	/* 0x990: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_995:
	/* 0x995: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_998:
	/* 0x998: ja     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 279ULL;
	}
x86_l_99e:
	/* 0x99e: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_9a0:
	/* 0x9a0: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_9a5:
	/* 0x9a5: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9a9:
	/* 0x9a9: jae    113d <generic_lsm_filter_arg+0x113d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4413ULL;
	}
x86_l_9af:
	/* 0x9af: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9b4:
	/* 0x9b4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9b7:
	/* 0x9b7: jle    16a8 <generic_lsm_filter_arg+0x16a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5800ULL;
	}
x86_l_9bd:
	/* 0x9bd: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_9c0:
	/* 0x9c0: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_9c3:
	/* 0x9c3: jae    1e8e <generic_lsm_filter_arg+0x1e8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7822ULL;
	}
x86_l_9c9:
	/* 0x9c9: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_9ce:
	/* 0x9ce: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_9d0:
	/* 0x9d0: jne    1ffe <generic_lsm_filter_arg+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8190ULL;
	}
x86_l_9d6:
	/* 0x9d6: jmp    367c <generic_lsm_filter_arg+0x367c> */
	return 13948ULL;
x86_l_9db:
	/* 0x9db: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9e0:
	/* 0x9e0: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9e5:
	/* 0x9e5: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9e9:
	/* 0x9e9: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_9f4:
	/* 0x9f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9f9:
	/* 0x9f9: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9fe:
	/* 0x9fe: mov    rdi,QWORD PTR [rip+0x1edb3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_a05:
	/* 0xa05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a07:
	/* 0xa07: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_a09:
	/* 0xa09: je     339e <generic_lsm_filter_arg+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13214ULL;
	}
x86_l_a0f:
	/* 0xa0f: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_a14:
	/* 0xa14: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a17:
	/* 0xa17: je     33a0 <generic_lsm_filter_arg+0x33a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13216ULL;
	}
x86_l_a1d:
	/* 0xa1d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a22:
	/* 0xa22: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a27:
	/* 0xa27: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a2c:
	/* 0xa2c: mov    rdi,QWORD PTR [rip+0x1edb3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_a33:
	/* 0xa33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a35:
	/* 0xa35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a38:
	/* 0xa38: je     339e <generic_lsm_filter_arg+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13214ULL;
	}
x86_l_a3e:
	/* 0xa3e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_a41:
	/* 0xa41: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_a44:
	/* 0xa44: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_a49:
	/* 0xa49: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_a4c:
	/* 0xa4c: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_a4f:
	/* 0xa4f: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a51:
	/* 0xa51: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_a54:
	/* 0xa54: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_a57:
	/* 0xa57: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a5c:
	/* 0xa5c: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a5f:
	/* 0xa5f: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_a62:
	/* 0xa62: mov    QWORD PTR [rsp+0x70],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a67:
	/* 0xa67: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_a6b:
	/* 0xa6b: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_a71:
	/* 0xa71: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a74:
	/* 0xa74: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_a78:
	/* 0xa78: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_a7e:
	/* 0xa7e: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a81:
	/* 0xa81: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_a85:
	/* 0xa85: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_a87:
	/* 0xa87: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a89:
	/* 0xa89: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_a8c:
	/* 0xa8c: lea    r13d,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_a90:
	/* 0xa90: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a97:
	/* 0xa97: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_a9d:
	/* 0xa9d: mov    BYTE PTR [rdi-0x3],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_aa1:
	/* 0xaa1: cmp    r10,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RBX, X86_WIDTH_64);
x86_l_aa4:
	/* 0xaa4: je     b01 <generic_lsm_filter_arg+0xb01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b01;
	}
x86_l_aa6:
	/* 0xaa6: lea    r13d,[r11+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_aaa:
	/* 0xaaa: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ab1:
	/* 0xab1: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_ab7:
	/* 0xab7: mov    BYTE PTR [rdi-0x2],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_abb:
	/* 0xabb: cmp    r8,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RBX, X86_WIDTH_64);
x86_l_abe:
	/* 0xabe: je     b01 <generic_lsm_filter_arg+0xb01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b01;
	}
x86_l_ac0:
	/* 0xac0: lea    r13d,[r9+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_ac4:
	/* 0xac4: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_acb:
	/* 0xacb: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_ad1:
	/* 0xad1: mov    BYTE PTR [rdi-0x1],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_ad5:
	/* 0xad5: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_ad8:
	/* 0xad8: je     b01 <generic_lsm_filter_arg+0xb01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b01;
	}
x86_l_ada:
	/* 0xada: cmp    rbx,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_ade:
	/* 0xade: je     b01 <generic_lsm_filter_arg+0xb01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b01;
	}
x86_l_ae0:
	/* 0xae0: lea    r13d,[rdx+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_ae4:
	/* 0xae4: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_aeb:
	/* 0xaeb: movzx  r13d,BYTE PTR [rsi+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 4ULL);
x86_l_af1:
	/* 0xaf1: mov    BYTE PTR [rdi],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af4:
	/* 0xaf4: add    rbx,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_af8:
	/* 0xaf8: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_afc:
	/* 0xafc: cmp    rax,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_aff:
	/* 0xaff: jne    a8c <generic_lsm_filter_arg+0xa8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a8c;
	}
x86_l_b01:
	/* 0xb01: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b06:
	/* 0xb06: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b0b:
	/* 0xb0b: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b10:
	/* 0xb10: jmp    3392 <generic_lsm_filter_arg+0x3392> */
	return 13202ULL;
x86_l_b15:
	/* 0xb15: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b1a:
	/* 0xb1a: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b1f:
	/* 0xb1f: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b24:
	/* 0xb24: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b28:
	/* 0xb28: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_b33:
	/* 0xb33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b38:
	/* 0xb38: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b3d:
	/* 0xb3d: mov    rdi,QWORD PTR [rip+0x1edb3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_b44:
	/* 0xb44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b46:
	/* 0xb46: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_b48:
	/* 0xb48: je     339e <generic_lsm_filter_arg+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13214ULL;
	}
x86_l_b4e:
	/* 0xb4e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_b51:
	/* 0xb51: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_b56:
	/* 0xb56: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b59:
	/* 0xb59: je     33a0 <generic_lsm_filter_arg+0x33a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13216ULL;
	}
x86_l_b5f:
	/* 0xb5f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b64:
	/* 0xb64: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b69:
	/* 0xb69: mov    rdi,QWORD PTR [rip+0x1edb3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_b70:
	/* 0xb70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b72:
	/* 0xb72: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b75:
	/* 0xb75: je     339e <generic_lsm_filter_arg+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13214ULL;
	}
x86_l_b7b:
	/* 0xb7b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_b7e:
	/* 0xb7e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b83:
	/* 0xb83: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_b87:
	/* 0xb87: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_b8d:
	/* 0xb8d: mov    eax,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_b92:
	/* 0xb92: cmovae ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_b95:
	/* 0xb95: lea    eax,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_b9c:
	/* 0xb9c: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b9e:
	/* 0xb9e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ba1:
	/* 0xba1: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_ba5:
	/* 0xba5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_baa:
	/* 0xbaa: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_bac:
	/* 0xbac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bae:
	/* 0xbae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bb3:
	/* 0xbb3: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_bb6:
	/* 0xbb6: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_bb9:
	/* 0xbb9: jmp    3392 <generic_lsm_filter_arg+0x3392> */
	return 13202ULL;
x86_l_bbe:
	/* 0xbbe: lea    edx,[rax-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_bc1:
	/* 0xbc1: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_bc4:
	/* 0xbc4: jb     c64 <generic_lsm_filter_arg+0xc64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c64;
	}
x86_l_bca:
	/* 0xbca: jmp    117 <generic_lsm_filter_arg+0x117> */
	return 279ULL;
x86_l_bcf:
	/* 0xbcf: mov    ebp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bd3:
	/* 0xbd3: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_bd7:
	/* 0xbd7: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_bda:
	/* 0xbda: jg     1264 <generic_lsm_filter_arg+0x1264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4708ULL;
	}
x86_l_be0:
	/* 0xbe0: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_be3:
	/* 0xbe3: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_be6:
	/* 0xbe6: jb     1b5b <generic_lsm_filter_arg+0x1b5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7003ULL;
	}
x86_l_bec:
	/* 0xbec: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bf1:
	/* 0xbf1: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_bf4:
	/* 0xbf4: je     1ab1 <generic_lsm_filter_arg+0x1ab1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6833ULL;
	}
x86_l_bfa:
	/* 0xbfa: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_bff:
	/* 0xbff: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_c02:
	/* 0xc02: je     1289 <generic_lsm_filter_arg+0x1289> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4745ULL;
	}
x86_l_c08:
	/* 0xc08: jmp    3754 <generic_lsm_filter_arg+0x3754> */
	return 14164ULL;
x86_l_c0d:
	/* 0xc0d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c10:
	/* 0xc10: je     155f <generic_lsm_filter_arg+0x155f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5471ULL;
	}
x86_l_c16:
	/* 0xc16: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c19:
	/* 0xc19: jne    22fa <generic_lsm_filter_arg+0x22fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8954ULL;
	}
x86_l_c1f:
	/* 0xc1f: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_c22:
	/* 0xc22: ja     22f0 <generic_lsm_filter_arg+0x22f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8944ULL;
	}
x86_l_c28:
	/* 0xc28: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_c2d:
	/* 0xc2d: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_c30:
	/* 0xc30: jae    22f0 <generic_lsm_filter_arg+0x22f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8944ULL;
	}
x86_l_c36:
	/* 0xc36: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c3a:
	/* 0xc3a: jl     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 730ULL;
	}
x86_l_c40:
	/* 0xc40: jmp    22fa <generic_lsm_filter_arg+0x22fa> */
	return 8954ULL;
x86_l_c45:
	/* 0xc45: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_c48:
	/* 0xc48: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_c4e:
	/* 0xc4e: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_c51:
	/* 0xc51: ja     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 279ULL;
	}
x86_l_c57:
	/* 0xc57: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_c59:
	/* 0xc59: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_c5e:
	/* 0xc5e: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_c62:
	/* 0xc62: jae    c89 <generic_lsm_filter_arg+0xc89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_c89;
	}
x86_l_c64:
	/* 0xc64: mov    rdx,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c69:
	/* 0xc69: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c6c:
	/* 0xc6c: jle    cad <generic_lsm_filter_arg+0xcad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_cad;
	}
x86_l_c6e:
	/* 0xc6e: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_c71:
	/* 0xc71: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c74:
	/* 0xc74: jae    f26 <generic_lsm_filter_arg+0xf26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3878ULL;
	}
x86_l_c7a:
	/* 0xc7a: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c7e:
	/* 0xc7e: jne    1df3 <generic_lsm_filter_arg+0x1df3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7667ULL;
	}
x86_l_c84:
	/* 0xc84: jmp    367c <generic_lsm_filter_arg+0x367c> */
	return 13948ULL;
x86_l_c89:
	/* 0xc89: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_c8e:
	/* 0xc8e: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_c92:
	/* 0xc92: jb     cdc <generic_lsm_filter_arg+0xcdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cdc;
	}
x86_l_c94:
	/* 0xc94: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_c9e:
	/* 0xc9e: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_ca2:
	/* 0xca2: jb     f4a <generic_lsm_filter_arg+0xf4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3914ULL;
	}
x86_l_ca8:
	/* 0xca8: jmp    117 <generic_lsm_filter_arg+0x117> */
	return 279ULL;
x86_l_cad:
	/* 0xcad: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cb0:
	/* 0xcb0: je     11df <generic_lsm_filter_arg+0x11df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4575ULL;
	}
x86_l_cb6:
	/* 0xcb6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cb9:
	/* 0xcb9: jne    1df3 <generic_lsm_filter_arg+0x1df3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7667ULL;
	}
x86_l_cbf:
	/* 0xcbf: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_cc2:
	/* 0xcc2: je     ccd <generic_lsm_filter_arg+0xccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccd;
	}
x86_l_cc4:
	/* 0xcc4: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_cc7:
	/* 0xcc7: jne    1de9 <generic_lsm_filter_arg+0x1de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7657ULL;
	}
x86_l_ccd:
	/* 0xccd: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cd1:
	/* 0xcd1: jl     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 730ULL;
	}
x86_l_cd7:
	/* 0xcd7: jmp    1df3 <generic_lsm_filter_arg+0x1df3> */
	return 7667ULL;
x86_l_cdc:
	/* 0xcdc: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_cdf:
	/* 0xcdf: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_ce2:
	/* 0xce2: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_ce8:
	/* 0xce8: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cef:
	/* 0xcef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cf4:
	/* 0xcf4: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cf9:
	/* 0xcf9: mov    rdi,QWORD PTR [rip+0x1edb3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_d00:
	/* 0xd00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d02:
	/* 0xd02: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d05:
	/* 0xd05: je     2ba <generic_lsm_filter_arg+0x2ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 698ULL;
	}
x86_l_d0b:
	/* 0xd0b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d0e:
	/* 0xd0e: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d11:
	/* 0xd11: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d16:
	/* 0xd16: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d1b:
	/* 0xd1b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d20:
	/* 0xd20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d22:
	/* 0xd22: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d27:
	/* 0xd27: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_d2a:
	/* 0xd2a: je     17b4 <generic_lsm_filter_arg+0x17b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6068ULL;
	}
	return 3376ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3376ULL: goto x86_l_d30;
	case 3379ULL: goto x86_l_d33;
	case 3384ULL: goto x86_l_d38;
	case 3389ULL: goto x86_l_d3d;
	case 3392ULL: goto x86_l_d40;
	case 3398ULL: goto x86_l_d46;
	case 3403ULL: goto x86_l_d4b;
	case 3406ULL: goto x86_l_d4e;
	case 3409ULL: goto x86_l_d51;
	case 3415ULL: goto x86_l_d57;
	case 3422ULL: goto x86_l_d5e;
	case 3427ULL: goto x86_l_d63;
	case 3432ULL: goto x86_l_d68;
	case 3439ULL: goto x86_l_d6f;
	case 3441ULL: goto x86_l_d71;
	case 3444ULL: goto x86_l_d74;
	case 3450ULL: goto x86_l_d7a;
	case 3453ULL: goto x86_l_d7d;
	case 3455ULL: goto x86_l_d7f;
	case 3460ULL: goto x86_l_d84;
	case 3465ULL: goto x86_l_d89;
	case 3470ULL: goto x86_l_d8e;
	case 3475ULL: goto x86_l_d93;
	case 3480ULL: goto x86_l_d98;
	case 3485ULL: goto x86_l_d9d;
	case 3490ULL: goto x86_l_da2;
	case 3495ULL: goto x86_l_da7;
	case 3499ULL: goto x86_l_dab;
	case 3504ULL: goto x86_l_db0;
	case 3508ULL: goto x86_l_db4;
	case 3513ULL: goto x86_l_db9;
	case 3518ULL: goto x86_l_dbe;
	case 3520ULL: goto x86_l_dc0;
	case 3523ULL: goto x86_l_dc3;
	case 3525ULL: goto x86_l_dc5;
	case 3528ULL: goto x86_l_dc8;
	case 3530ULL: goto x86_l_dca;
	case 3533ULL: goto x86_l_dcd;
	case 3536ULL: goto x86_l_dd0;
	case 3542ULL: goto x86_l_dd6;
	case 3545ULL: goto x86_l_dd9;
	case 3550ULL: goto x86_l_dde;
	case 3553ULL: goto x86_l_de1;
	case 3559ULL: goto x86_l_de7;
	case 3564ULL: goto x86_l_dec;
	case 3567ULL: goto x86_l_def;
	case 3573ULL: goto x86_l_df5;
	case 3576ULL: goto x86_l_df8;
	case 3582ULL: goto x86_l_dfe;
	case 3585ULL: goto x86_l_e01;
	case 3591ULL: goto x86_l_e07;
	case 3596ULL: goto x86_l_e0c;
	case 3599ULL: goto x86_l_e0f;
	case 3605ULL: goto x86_l_e15;
	case 3610ULL: goto x86_l_e1a;
	case 3615ULL: goto x86_l_e1f;
	case 3618ULL: goto x86_l_e22;
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
	case 3669ULL: goto x86_l_e55;
	case 3675ULL: goto x86_l_e5b;
	case 3680ULL: goto x86_l_e60;
	case 3682ULL: goto x86_l_e62;
	case 3685ULL: goto x86_l_e65;
	case 3688ULL: goto x86_l_e68;
	case 3693ULL: goto x86_l_e6d;
	case 3697ULL: goto x86_l_e71;
	case 3702ULL: goto x86_l_e76;
	case 3707ULL: goto x86_l_e7b;
	case 3714ULL: goto x86_l_e82;
	case 3716ULL: goto x86_l_e84;
	case 3719ULL: goto x86_l_e87;
	case 3725ULL: goto x86_l_e8d;
	case 3727ULL: goto x86_l_e8f;
	case 3730ULL: goto x86_l_e92;
	case 3735ULL: goto x86_l_e97;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	case 3744ULL: goto x86_l_ea0;
	case 3746ULL: goto x86_l_ea2;
	case 3749ULL: goto x86_l_ea5;
	case 3752ULL: goto x86_l_ea8;
	case 3755ULL: goto x86_l_eab;
	case 3757ULL: goto x86_l_ead;
	case 3759ULL: goto x86_l_eaf;
	case 3763ULL: goto x86_l_eb3;
	case 3766ULL: goto x86_l_eb6;
	case 3768ULL: goto x86_l_eb8;
	case 3772ULL: goto x86_l_ebc;
	case 3774ULL: goto x86_l_ebe;
	case 3776ULL: goto x86_l_ec0;
	case 3781ULL: goto x86_l_ec5;
	case 3785ULL: goto x86_l_ec9;
	case 3788ULL: goto x86_l_ecc;
	case 3792ULL: goto x86_l_ed0;
	case 3796ULL: goto x86_l_ed4;
	case 3800ULL: goto x86_l_ed8;
	case 3804ULL: goto x86_l_edc;
	case 3807ULL: goto x86_l_edf;
	case 3811ULL: goto x86_l_ee3;
	case 3815ULL: goto x86_l_ee7;
	case 3819ULL: goto x86_l_eeb;
	case 3823ULL: goto x86_l_eef;
	case 3825ULL: goto x86_l_ef1;
	case 3828ULL: goto x86_l_ef4;
	case 3831ULL: goto x86_l_ef7;
	case 3833ULL: goto x86_l_ef9;
	case 3835ULL: goto x86_l_efb;
	case 3837ULL: goto x86_l_efd;
	case 3843ULL: goto x86_l_f03;
	case 3847ULL: goto x86_l_f07;
	case 3852ULL: goto x86_l_f0c;
	case 3854ULL: goto x86_l_f0e;
	case 3858ULL: goto x86_l_f12;
	case 3861ULL: goto x86_l_f15;
	case 3865ULL: goto x86_l_f19;
	case 3871ULL: goto x86_l_f1f;
	case 3873ULL: goto x86_l_f21;
	case 3878ULL: goto x86_l_f26;
	case 3881ULL: goto x86_l_f29;
	case 3887ULL: goto x86_l_f2f;
	case 3891ULL: goto x86_l_f33;
	case 3897ULL: goto x86_l_f39;
	case 3902ULL: goto x86_l_f3e;
	case 3905ULL: goto x86_l_f41;
	case 3908ULL: goto x86_l_f44;
	case 3914ULL: goto x86_l_f4a;
	case 3917ULL: goto x86_l_f4d;
	case 3923ULL: goto x86_l_f53;
	case 3928ULL: goto x86_l_f58;
	case 3933ULL: goto x86_l_f5d;
	case 3936ULL: goto x86_l_f60;
	case 3938ULL: goto x86_l_f62;
	case 3941ULL: goto x86_l_f65;
	case 3947ULL: goto x86_l_f6b;
	case 3951ULL: goto x86_l_f6f;
	case 3954ULL: goto x86_l_f72;
	case 3960ULL: goto x86_l_f78;
	case 3963ULL: goto x86_l_f7b;
	case 3969ULL: goto x86_l_f81;
	case 3974ULL: goto x86_l_f86;
	case 3979ULL: goto x86_l_f8b;
	case 3984ULL: goto x86_l_f90;
	case 3989ULL: goto x86_l_f95;
	case 3993ULL: goto x86_l_f99;
	case 4004ULL: goto x86_l_fa4;
	case 4009ULL: goto x86_l_fa9;
	case 4014ULL: goto x86_l_fae;
	case 4021ULL: goto x86_l_fb5;
	case 4023ULL: goto x86_l_fb7;
	case 4025ULL: goto x86_l_fb9;
	case 4031ULL: goto x86_l_fbf;
	case 4034ULL: goto x86_l_fc2;
	case 4039ULL: goto x86_l_fc7;
	case 4042ULL: goto x86_l_fca;
	case 4048ULL: goto x86_l_fd0;
	case 4053ULL: goto x86_l_fd5;
	case 4058ULL: goto x86_l_fda;
	case 4065ULL: goto x86_l_fe1;
	case 4067ULL: goto x86_l_fe3;
	case 4070ULL: goto x86_l_fe6;
	case 4076ULL: goto x86_l_fec;
	case 4082ULL: goto x86_l_ff2;
	case 4087ULL: goto x86_l_ff7;
	case 4090ULL: goto x86_l_ffa;
	case 4097ULL: goto x86_l_1001;
	case 4099ULL: goto x86_l_1003;
	case 4102ULL: goto x86_l_1006;
	case 4106ULL: goto x86_l_100a;
	case 4109ULL: goto x86_l_100d;
	case 4114ULL: goto x86_l_1012;
	case 4119ULL: goto x86_l_1017;
	case 4121ULL: goto x86_l_1019;
	case 4123ULL: goto x86_l_101b;
	case 4128ULL: goto x86_l_1020;
	case 4133ULL: goto x86_l_1025;
	case 4144ULL: goto x86_l_1030;
	case 4150ULL: goto x86_l_1036;
	case 4156ULL: goto x86_l_103c;
	case 4159ULL: goto x86_l_103f;
	case 4164ULL: goto x86_l_1044;
	case 4169ULL: goto x86_l_1049;
	case 4175ULL: goto x86_l_104f;
	case 4179ULL: goto x86_l_1053;
	case 4185ULL: goto x86_l_1059;
	case 4188ULL: goto x86_l_105c;
	case 4191ULL: goto x86_l_105f;
	case 4194ULL: goto x86_l_1062;
	case 4196ULL: goto x86_l_1064;
	case 4199ULL: goto x86_l_1067;
	case 4201ULL: goto x86_l_1069;
	case 4203ULL: goto x86_l_106b;
	case 4205ULL: goto x86_l_106d;
	case 4207ULL: goto x86_l_106f;
	case 4209ULL: goto x86_l_1071;
	case 4212ULL: goto x86_l_1074;
	case 4214ULL: goto x86_l_1076;
	case 4216ULL: goto x86_l_1078;
	case 4218ULL: goto x86_l_107a;
	case 4221ULL: goto x86_l_107d;
	case 4224ULL: goto x86_l_1080;
	case 4228ULL: goto x86_l_1084;
	case 4234ULL: goto x86_l_108a;
	case 4236ULL: goto x86_l_108c;
	case 4239ULL: goto x86_l_108f;
	case 4245ULL: goto x86_l_1095;
	case 4248ULL: goto x86_l_1098;
	case 4250ULL: goto x86_l_109a;
	case 4255ULL: goto x86_l_109f;
	case 4258ULL: goto x86_l_10a2;
	case 4264ULL: goto x86_l_10a8;
	case 4267ULL: goto x86_l_10ab;
	case 4273ULL: goto x86_l_10b1;
	case 4278ULL: goto x86_l_10b6;
	case 4281ULL: goto x86_l_10b9;
	case 4287ULL: goto x86_l_10bf;
	case 4292ULL: goto x86_l_10c4;
	case 4297ULL: goto x86_l_10c9;
	case 4302ULL: goto x86_l_10ce;
	case 4305ULL: goto x86_l_10d1;
	case 4307ULL: goto x86_l_10d3;
	case 4310ULL: goto x86_l_10d6;
	case 4316ULL: goto x86_l_10dc;
	case 4320ULL: goto x86_l_10e0;
	case 4323ULL: goto x86_l_10e3;
	case 4327ULL: goto x86_l_10e7;
	case 4330ULL: goto x86_l_10ea;
	case 4333ULL: goto x86_l_10ed;
	case 4338ULL: goto x86_l_10f2;
	case 4341ULL: goto x86_l_10f5;
	case 4347ULL: goto x86_l_10fb;
	case 4351ULL: goto x86_l_10ff;
	case 4357ULL: goto x86_l_1105;
	case 4362ULL: goto x86_l_110a;
	case 4367ULL: goto x86_l_110f;
	case 4371ULL: goto x86_l_1113;
	case 4377ULL: goto x86_l_1119;
	case 4387ULL: goto x86_l_1123;
	case 4391ULL: goto x86_l_1127;
	case 4397ULL: goto x86_l_112d;
	case 4400ULL: goto x86_l_1130;
	case 4406ULL: goto x86_l_1136;
	case 4411ULL: goto x86_l_113b;
	case 4413ULL: goto x86_l_113d;
	case 4418ULL: goto x86_l_1142;
	case 4422ULL: goto x86_l_1146;
	case 4428ULL: goto x86_l_114c;
	case 4438ULL: goto x86_l_1156;
	case 4442ULL: goto x86_l_115a;
	case 4448ULL: goto x86_l_1160;
	case 4451ULL: goto x86_l_1163;
	case 4457ULL: goto x86_l_1169;
	case 4462ULL: goto x86_l_116e;
	case 4467ULL: goto x86_l_1173;
	case 4469ULL: goto x86_l_1175;
	case 4474ULL: goto x86_l_117a;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4488ULL: goto x86_l_1188;
	case 4494ULL: goto x86_l_118e;
	case 4499ULL: goto x86_l_1193;
	case 4501ULL: goto x86_l_1195;
	case 4506ULL: goto x86_l_119a;
	case 4512ULL: goto x86_l_11a0;
	case 4515ULL: goto x86_l_11a3;
	case 4521ULL: goto x86_l_11a9;
	case 4526ULL: goto x86_l_11ae;
	case 4528ULL: goto x86_l_11b0;
	case 4533ULL: goto x86_l_11b5;
	case 4539ULL: goto x86_l_11bb;
	case 4542ULL: goto x86_l_11be;
	case 4548ULL: goto x86_l_11c4;
	case 4553ULL: goto x86_l_11c9;
	case 4559ULL: goto x86_l_11cf;
	case 4564ULL: goto x86_l_11d4;
	case 4570ULL: goto x86_l_11da;
	case 4575ULL: goto x86_l_11df;
	case 4578ULL: goto x86_l_11e2;
	case 4580ULL: goto x86_l_11e4;
	case 4583ULL: goto x86_l_11e7;
	case 4589ULL: goto x86_l_11ed;
	case 4593ULL: goto x86_l_11f1;
	case 4599ULL: goto x86_l_11f7;
	case 4604ULL: goto x86_l_11fc;
	case 4607ULL: goto x86_l_11ff;
	case 4612ULL: goto x86_l_1204;
	case 4617ULL: goto x86_l_1209;
	case 4622ULL: goto x86_l_120e;
	case 4628ULL: goto x86_l_1214;
	case 4632ULL: goto x86_l_1218;
	case 4638ULL: goto x86_l_121e;
	case 4641ULL: goto x86_l_1221;
	case 4644ULL: goto x86_l_1224;
	case 4647ULL: goto x86_l_1227;
	case 4649ULL: goto x86_l_1229;
	case 4652ULL: goto x86_l_122c;
	case 4654ULL: goto x86_l_122e;
	case 4656ULL: goto x86_l_1230;
	case 4658ULL: goto x86_l_1232;
	case 4660ULL: goto x86_l_1234;
	case 4662ULL: goto x86_l_1236;
	case 4665ULL: goto x86_l_1239;
	case 4667ULL: goto x86_l_123b;
	case 4669ULL: goto x86_l_123d;
	case 4671ULL: goto x86_l_123f;
	case 4674ULL: goto x86_l_1242;
	case 4677ULL: goto x86_l_1245;
	case 4681ULL: goto x86_l_1249;
	case 4687ULL: goto x86_l_124f;
	case 4689ULL: goto x86_l_1251;
	case 4692ULL: goto x86_l_1254;
	case 4698ULL: goto x86_l_125a;
	case 4701ULL: goto x86_l_125d;
	case 4703ULL: goto x86_l_125f;
	case 4708ULL: goto x86_l_1264;
	case 4711ULL: goto x86_l_1267;
	case 4716ULL: goto x86_l_126c;
	case 4722ULL: goto x86_l_1272;
	case 4725ULL: goto x86_l_1275;
	case 4731ULL: goto x86_l_127b;
	case 4736ULL: goto x86_l_1280;
	case 4739ULL: goto x86_l_1283;
	case 4745ULL: goto x86_l_1289;
	case 4750ULL: goto x86_l_128e;
	case 4755ULL: goto x86_l_1293;
	case 4759ULL: goto x86_l_1297;
	case 4770ULL: goto x86_l_12a2;
	case 4775ULL: goto x86_l_12a7;
	case 4780ULL: goto x86_l_12ac;
	case 4787ULL: goto x86_l_12b3;
	case 4789ULL: goto x86_l_12b5;
	case 4791ULL: goto x86_l_12b7;
	case 4797ULL: goto x86_l_12bd;
	case 4800ULL: goto x86_l_12c0;
	case 4805ULL: goto x86_l_12c5;
	case 4808ULL: goto x86_l_12c8;
	case 4814ULL: goto x86_l_12ce;
	case 4819ULL: goto x86_l_12d3;
	case 4824ULL: goto x86_l_12d8;
	case 4831ULL: goto x86_l_12df;
	case 4833ULL: goto x86_l_12e1;
	case 4836ULL: goto x86_l_12e4;
	case 4842ULL: goto x86_l_12ea;
	case 4845ULL: goto x86_l_12ed;
	case 4850ULL: goto x86_l_12f2;
	case 4853ULL: goto x86_l_12f5;
	case 4858ULL: goto x86_l_12fa;
	case 4861ULL: goto x86_l_12fd;
	case 4864ULL: goto x86_l_1300;
	case 4866ULL: goto x86_l_1302;
	case 4869ULL: goto x86_l_1305;
	case 4872ULL: goto x86_l_1308;
	case 4877ULL: goto x86_l_130d;
	case 4880ULL: goto x86_l_1310;
	case 4883ULL: goto x86_l_1313;
	case 4888ULL: goto x86_l_1318;
	case 4892ULL: goto x86_l_131c;
	case 4898ULL: goto x86_l_1322;
	case 4901ULL: goto x86_l_1325;
	case 4905ULL: goto x86_l_1329;
	case 4911ULL: goto x86_l_132f;
	case 4914ULL: goto x86_l_1332;
	case 4918ULL: goto x86_l_1336;
	case 4920ULL: goto x86_l_1338;
	case 4922ULL: goto x86_l_133a;
	case 4927ULL: goto x86_l_133f;
	case 4931ULL: goto x86_l_1343;
	case 4938ULL: goto x86_l_134a;
	case 4943ULL: goto x86_l_134f;
	case 4947ULL: goto x86_l_1353;
	case 4950ULL: goto x86_l_1356;
	case 4952ULL: goto x86_l_1358;
	case 4956ULL: goto x86_l_135c;
	case 4963ULL: goto x86_l_1363;
	case 4968ULL: goto x86_l_1368;
	case 4972ULL: goto x86_l_136c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d30:
	/* 0xd30: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_d33:
	/* 0xd33: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d38:
	/* 0xd38: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d3d:
	/* 0xd3d: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_d40:
	/* 0xd40: je     18c9 <generic_lsm_filter_arg+0x18c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6345ULL;
	}
x86_l_d46:
	/* 0xd46: jmp    18d7 <generic_lsm_filter_arg+0x18d7> */
	return 6359ULL;
x86_l_d4b:
	/* 0xd4b: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_d4e:
	/* 0xd4e: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_d51:
	/* 0xd51: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_d57:
	/* 0xd57: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d5e:
	/* 0xd5e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d63:
	/* 0xd63: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d68:
	/* 0xd68: mov    rdi,QWORD PTR [rip+0x1edb3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_d6f:
	/* 0xd6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d71:
	/* 0xd71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d74:
	/* 0xd74: je     2ba <generic_lsm_filter_arg+0x2ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 698ULL;
	}
x86_l_d7a:
	/* 0xd7a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d7d:
	/* 0xd7d: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d7f:
	/* 0xd7f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d84:
	/* 0xd84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d89:
	/* 0xd89: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d8e:
	/* 0xd8e: jmp    1cc1 <generic_lsm_filter_arg+0x1cc1> */
	return 7361ULL;
x86_l_d93:
	/* 0xd93: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d98:
	/* 0xd98: mov    WORD PTR [rsp+0x66],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 102ULL);
x86_l_d9d:
	/* 0xd9d: movzx  edx,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_da2:
	/* 0xda2: mov    WORD PTR [rsp+0x60],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_da7:
	/* 0xda7: mov    rdx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dab:
	/* 0xdab: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_db0:
	/* 0xdb0: mov    rdx,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db4:
	/* 0xdb4: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_db9:
	/* 0xdb9: lea    r13,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dbe:
	/* 0xdbe: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dc0:
	/* 0xdc0: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_dc3:
	/* 0xdc3: jle    dec <generic_lsm_filter_arg+0xdec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_dec;
	}
x86_l_dc5:
	/* 0xdc5: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_dc8:
	/* 0xdc8: jg     e1f <generic_lsm_filter_arg+0xe1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_e1f;
	}
x86_l_dca:
	/* 0xdca: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_dcd:
	/* 0xdcd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dd0:
	/* 0xdd0: jb     1435 <generic_lsm_filter_arg+0x1435> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5173ULL;
	}
x86_l_dd6:
	/* 0xdd6: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_dd9:
	/* 0xdd9: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_dde:
	/* 0xdde: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_de1:
	/* 0xde1: jb     142b <generic_lsm_filter_arg+0x142b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5163ULL;
	}
x86_l_de7:
	/* 0xde7: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_dec:
	/* 0xdec: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_def:
	/* 0xdef: jle    109f <generic_lsm_filter_arg+0x109f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_109f;
	}
x86_l_df5:
	/* 0xdf5: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_df8:
	/* 0xdf8: jg     1418 <generic_lsm_filter_arg+0x1418> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5144ULL;
	}
x86_l_dfe:
	/* 0xdfe: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_e01:
	/* 0xe01: je     142b <generic_lsm_filter_arg+0x142b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5163ULL;
	}
x86_l_e07:
	/* 0xe07: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_e0c:
	/* 0xe0c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_e0f:
	/* 0xe0f: jne    2c9 <generic_lsm_filter_arg+0x2c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 713ULL;
	}
x86_l_e15:
	/* 0xe15: movzx  ebx,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_e1a:
	/* 0xe1a: jmp    1c80 <generic_lsm_filter_arg+0x1c80> */
	return 7296ULL;
x86_l_e1f:
	/* 0xe1f: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_e22:
	/* 0xe22: jg     1476 <generic_lsm_filter_arg+0x1476> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5238ULL;
	}
x86_l_e28:
	/* 0xe28: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_e2b:
	/* 0xe2b: je     14b3 <generic_lsm_filter_arg+0x14b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5299ULL;
	}
x86_l_e31:
	/* 0xe31: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_e36:
	/* 0xe36: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_e39:
	/* 0xe39: je     14a6 <generic_lsm_filter_arg+0x14a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5286ULL;
	}
x86_l_e3f:
	/* 0xe3f: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_e44:
	/* 0xe44: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_e47:
	/* 0xe47: je     1585 <generic_lsm_filter_arg+0x1585> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5509ULL;
	}
x86_l_e4d:
	/* 0xe4d: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_e52:
	/* 0xe52: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_e55:
	/* 0xe55: jne    3754 <generic_lsm_filter_arg+0x3754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14164ULL;
	}
x86_l_e5b:
	/* 0xe5b: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e60:
	/* 0xe60: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e62:
	/* 0xe62: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e65:
	/* 0xe65: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_e68:
	/* 0xe68: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_e6d:
	/* 0xe6d: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e71:
	/* 0xe71: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e76:
	/* 0xe76: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e7b:
	/* 0xe7b: mov    rdi,QWORD PTR [rip+0x1edb3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_e82:
	/* 0xe82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e84:
	/* 0xe84: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e87:
	/* 0xe87: je     2273 <generic_lsm_filter_arg+0x2273> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8819ULL;
	}
x86_l_e8d:
	/* 0xe8d: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_e8f:
	/* 0xe8f: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_e92:
	/* 0xe92: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e97:
	/* 0xe97: je     f03 <generic_lsm_filter_arg+0xf03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f03;
	}
x86_l_e99:
	/* 0xe99: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e9e:
	/* 0xe9e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ea0:
	/* 0xea0: jmp    ead <generic_lsm_filter_arg+0xead> */
	goto x86_l_ead;
x86_l_ea2:
	/* 0xea2: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ea5:
	/* 0xea5: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ea8:
	/* 0xea8: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_eab:
	/* 0xeab: je     f03 <generic_lsm_filter_arg+0xf03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f03;
	}
x86_l_ead:
	/* 0xead: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eaf:
	/* 0xeaf: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_eb3:
	/* 0xeb3: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_eb6:
	/* 0xeb6: jae    ea2 <generic_lsm_filter_arg+0xea2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ea2;
	}
x86_l_eb8:
	/* 0xeb8: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_ebc:
	/* 0xebc: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_ebe:
	/* 0xebe: je     efb <generic_lsm_filter_arg+0xefb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_efb;
	}
x86_l_ec0:
	/* 0xec0: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_ec5:
	/* 0xec5: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_ec9:
	/* 0xec9: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_ecc:
	/* 0xecc: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_ed0:
	/* 0xed0: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_ed4:
	/* 0xed4: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_ed8:
	/* 0xed8: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_edc:
	/* 0xedc: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_edf:
	/* 0xedf: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_ee3:
	/* 0xee3: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_ee7:
	/* 0xee7: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_eeb:
	/* 0xeeb: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_eef:
	/* 0xeef: ja     ea2 <generic_lsm_filter_arg+0xea2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ea2;
	}
x86_l_ef1:
	/* 0xef1: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ef4:
	/* 0xef4: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_ef7:
	/* 0xef7: je     eaf <generic_lsm_filter_arg+0xeaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eaf;
	}
x86_l_ef9:
	/* 0xef9: jmp    ea2 <generic_lsm_filter_arg+0xea2> */
	goto x86_l_ea2;
x86_l_efb:
	/* 0xefb: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_efd:
	/* 0xefd: jns    25be <generic_lsm_filter_arg+0x25be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9662ULL;
	}
x86_l_f03:
	/* 0xf03: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f07:
	/* 0xf07: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_f0c:
	/* 0xf0c: jae    f1f <generic_lsm_filter_arg+0xf1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f1f;
	}
x86_l_f0e:
	/* 0xf0e: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_f12:
	/* 0xf12: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_f15:
	/* 0xf15: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_f19:
	/* 0xf19: jne    e65 <generic_lsm_filter_arg+0xe65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e65;
	}
x86_l_f1f:
	/* 0xf1f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f21:
	/* 0xf21: jmp    25c3 <generic_lsm_filter_arg+0x25c3> */
	return 9667ULL;
x86_l_f26:
	/* 0xf26: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_f29:
	/* 0xf29: jne    1df3 <generic_lsm_filter_arg+0x1df3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7667ULL;
	}
x86_l_f2f:
	/* 0xf2f: test   QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f33:
	/* 0xf33: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_f39:
	/* 0xf39: jmp    1df3 <generic_lsm_filter_arg+0x1df3> */
	return 7667ULL;
x86_l_f3e:
	/* 0xf3e: lea    edx,[rax-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_f41:
	/* 0xf41: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_f44:
	/* 0xf44: jae    18e1 <generic_lsm_filter_arg+0x18e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6369ULL;
	}
x86_l_f4a:
	/* 0xf4a: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_f4d:
	/* 0xf4d: jne    10c4 <generic_lsm_filter_arg+0x10c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10c4;
	}
x86_l_f53:
	/* 0xf53: mov    rsi,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f58:
	/* 0xf58: mov    rdx,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f5d:
	/* 0xf5d: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f60:
	/* 0xf60: je     f6b <generic_lsm_filter_arg+0xf6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f6b;
	}
x86_l_f62:
	/* 0xf62: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_f65:
	/* 0xf65: jne    1bda <generic_lsm_filter_arg+0x1bda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7130ULL;
	}
x86_l_f6b:
	/* 0xf6b: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f6f:
	/* 0xf6f: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f72:
	/* 0xf72: jg     1bec <generic_lsm_filter_arg+0x1bec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7148ULL;
	}
x86_l_f78:
	/* 0xf78: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_f7b:
	/* 0xf7b: jle    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 730ULL;
	}
x86_l_f81:
	/* 0xf81: jmp    1bec <generic_lsm_filter_arg+0x1bec> */
	return 7148ULL;
x86_l_f86:
	/* 0xf86: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f8b:
	/* 0xf8b: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f90:
	/* 0xf90: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f95:
	/* 0xf95: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f99:
	/* 0xf99: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_fa4:
	/* 0xfa4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fa9:
	/* 0xfa9: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fae:
	/* 0xfae: mov    rdi,QWORD PTR [rip+0x1edc1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_fb5:
	/* 0xfb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb7:
	/* 0xfb7: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_fb9:
	/* 0xfb9: je     3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14147ULL;
	}
x86_l_fbf:
	/* 0xfbf: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_fc2:
	/* 0xfc2: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_fc7:
	/* 0xfc7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fca:
	/* 0xfca: je     3745 <generic_lsm_filter_arg+0x3745> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14149ULL;
	}
x86_l_fd0:
	/* 0xfd0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fd5:
	/* 0xfd5: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fda:
	/* 0xfda: mov    rdi,QWORD PTR [rip+0x1edc1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_fe1:
	/* 0xfe1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe3:
	/* 0xfe3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fe6:
	/* 0xfe6: je     3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14147ULL;
	}
x86_l_fec:
	/* 0xfec: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_ff2:
	/* 0xff2: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_ff7:
	/* 0xff7: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_ffa:
	/* 0xffa: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_1001:
	/* 0x1001: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1003:
	/* 0x1003: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1006:
	/* 0x1006: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_100a:
	/* 0x100a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_100d:
	/* 0x100d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1012:
	/* 0x1012: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1017:
	/* 0x1017: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1019:
	/* 0x1019: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_101b:
	/* 0x101b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1020:
	/* 0x1020: jmp    1b46 <generic_lsm_filter_arg+0x1b46> */
	return 6982ULL;
x86_l_1025:
	/* 0x1025: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1030:
	/* 0x1030: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_1036:
	/* 0x1036: ja     2b1e <generic_lsm_filter_arg+0x2b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11038ULL;
	}
x86_l_103c:
	/* 0x103c: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_103f:
	/* 0x103f: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1044:
	/* 0x1044: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1049:
	/* 0x1049: ja     1d76 <generic_lsm_filter_arg+0x1d76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7542ULL;
	}
x86_l_104f:
	/* 0x104f: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1053:
	/* 0x1053: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1059:
	/* 0x1059: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_105c:
	/* 0x105c: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_105f:
	/* 0x105f: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1062:
	/* 0x1062: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1064:
	/* 0x1064: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1067:
	/* 0x1067: je     1071 <generic_lsm_filter_arg+0x1071> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1071;
	}
x86_l_1069:
	/* 0x1069: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_106b:
	/* 0x106b: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_106d:
	/* 0x106d: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_106f:
	/* 0x106f: je     108c <generic_lsm_filter_arg+0x108c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_108c;
	}
x86_l_1071:
	/* 0x1071: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1074:
	/* 0x1074: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1076:
	/* 0x1076: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1078:
	/* 0x1078: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_107a:
	/* 0x107a: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_107d:
	/* 0x107d: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1080:
	/* 0x1080: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1084:
	/* 0x1084: ja     1dad <generic_lsm_filter_arg+0x1dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7597ULL;
	}
x86_l_108a:
	/* 0x108a: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_108c:
	/* 0x108c: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_108f:
	/* 0x108f: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1095:
	/* 0x1095: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1098:
	/* 0x1098: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_109a:
	/* 0x109a: jmp    2a53 <generic_lsm_filter_arg+0x2a53> */
	return 10835ULL;
x86_l_109f:
	/* 0x109f: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_10a2:
	/* 0x10a2: je     14b3 <generic_lsm_filter_arg+0x14b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5299ULL;
	}
x86_l_10a8:
	/* 0x10a8: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_10ab:
	/* 0x10ab: je     14a6 <generic_lsm_filter_arg+0x14a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5286ULL;
	}
x86_l_10b1:
	/* 0x10b1: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_10b6:
	/* 0x10b6: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_10b9:
	/* 0x10b9: je     1435 <generic_lsm_filter_arg+0x1435> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5173ULL;
	}
x86_l_10bf:
	/* 0x10bf: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_10c4:
	/* 0x10c4: mov    rsi,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10c9:
	/* 0x10c9: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10ce:
	/* 0x10ce: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_10d1:
	/* 0x10d1: je     10dc <generic_lsm_filter_arg+0x10dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10dc;
	}
x86_l_10d3:
	/* 0x10d3: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_10d6:
	/* 0x10d6: jne    1c2e <generic_lsm_filter_arg+0x1c2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7214ULL;
	}
x86_l_10dc:
	/* 0x10dc: mov    rdx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10e0:
	/* 0x10e0: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_10e3:
	/* 0x10e3: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_10e7:
	/* 0x10e7: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_10ea:
	/* 0x10ea: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_10ed:
	/* 0x10ed: jmp    1c3f <generic_lsm_filter_arg+0x1c3f> */
	return 7231ULL;
x86_l_10f2:
	/* 0x10f2: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_10f5:
	/* 0x10f5: jne    22fa <generic_lsm_filter_arg+0x22fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8954ULL;
	}
x86_l_10fb:
	/* 0x10fb: test   DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ff:
	/* 0x10ff: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_1105:
	/* 0x1105: jmp    22fa <generic_lsm_filter_arg+0x22fa> */
	return 8954ULL;
x86_l_110a:
	/* 0x110a: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_110f:
	/* 0x110f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1113:
	/* 0x1113: jb     16cc <generic_lsm_filter_arg+0x16cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5836ULL;
	}
x86_l_1119:
	/* 0x1119: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_1123:
	/* 0x1123: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1127:
	/* 0x1127: jae    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 279ULL;
	}
x86_l_112d:
	/* 0x112d: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_1130:
	/* 0x1130: jne    1ee2 <generic_lsm_filter_arg+0x1ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7906ULL;
	}
x86_l_1136:
	/* 0x1136: movzx  eax,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_113b:
	/* 0x113b: jmp    116e <generic_lsm_filter_arg+0x116e> */
	goto x86_l_116e;
x86_l_113d:
	/* 0x113d: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_1142:
	/* 0x1142: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1146:
	/* 0x1146: jb     1715 <generic_lsm_filter_arg+0x1715> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5909ULL;
	}
x86_l_114c:
	/* 0x114c: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_1156:
	/* 0x1156: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_115a:
	/* 0x115a: jae    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 279ULL;
	}
x86_l_1160:
	/* 0x1160: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_1163:
	/* 0x1163: jne    1eee <generic_lsm_filter_arg+0x1eee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7918ULL;
	}
x86_l_1169:
	/* 0x1169: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_116e:
	/* 0x116e: cmp    DWORD PTR [r12+0x10],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1173:
	/* 0x1173: ja     1180 <generic_lsm_filter_arg+0x1180> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1180;
	}
x86_l_1175:
	/* 0x1175: cmp    DWORD PTR [r12+0x14],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_117a:
	/* 0x117a: jae    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 730ULL;
	}
x86_l_1180:
	/* 0x1180: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1185:
	/* 0x1185: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1188:
	/* 0x1188: jb     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 279ULL;
	}
x86_l_118e:
	/* 0x118e: cmp    DWORD PTR [r12+0x18],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1193:
	/* 0x1193: ja     11a0 <generic_lsm_filter_arg+0x11a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11a0;
	}
x86_l_1195:
	/* 0x1195: cmp    DWORD PTR [r12+0x1c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_119a:
	/* 0x119a: jae    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 730ULL;
	}
x86_l_11a0:
	/* 0x11a0: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_11a3:
	/* 0x11a3: jb     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 279ULL;
	}
x86_l_11a9:
	/* 0x11a9: cmp    DWORD PTR [r12+0x20],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11ae:
	/* 0x11ae: ja     11bb <generic_lsm_filter_arg+0x11bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11bb;
	}
x86_l_11b0:
	/* 0x11b0: cmp    DWORD PTR [r12+0x24],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_11b5:
	/* 0x11b5: jae    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 730ULL;
	}
x86_l_11bb:
	/* 0x11bb: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_11be:
	/* 0x11be: jb     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 279ULL;
	}
x86_l_11c4:
	/* 0x11c4: cmp    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11c9:
	/* 0x11c9: ja     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 279ULL;
	}
x86_l_11cf:
	/* 0x11cf: cmp    DWORD PTR [r12+0x2c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_11d4:
	/* 0x11d4: jae    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 730ULL;
	}
x86_l_11da:
	/* 0x11da: jmp    117 <generic_lsm_filter_arg+0x117> */
	return 279ULL;
x86_l_11df:
	/* 0x11df: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_11e2:
	/* 0x11e2: je     11ed <generic_lsm_filter_arg+0x11ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11ed;
	}
x86_l_11e4:
	/* 0x11e4: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_11e7:
	/* 0x11e7: jne    1ddd <generic_lsm_filter_arg+0x1ddd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7645ULL;
	}
x86_l_11ed:
	/* 0x11ed: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f1:
	/* 0x11f1: jg     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 730ULL;
	}
x86_l_11f7:
	/* 0x11f7: jmp    1df3 <generic_lsm_filter_arg+0x1df3> */
	return 7667ULL;
x86_l_11fc:
	/* 0x11fc: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11ff:
	/* 0x11ff: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1204:
	/* 0x1204: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1209:
	/* 0x1209: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_120e:
	/* 0x120e: ja     17cf <generic_lsm_filter_arg+0x17cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6095ULL;
	}
x86_l_1214:
	/* 0x1214: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1218:
	/* 0x1218: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_121e:
	/* 0x121e: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1221:
	/* 0x1221: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1224:
	/* 0x1224: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1227:
	/* 0x1227: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1229:
	/* 0x1229: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_122c:
	/* 0x122c: je     1236 <generic_lsm_filter_arg+0x1236> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1236;
	}
x86_l_122e:
	/* 0x122e: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1230:
	/* 0x1230: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1232:
	/* 0x1232: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1234:
	/* 0x1234: je     1251 <generic_lsm_filter_arg+0x1251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1251;
	}
x86_l_1236:
	/* 0x1236: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1239:
	/* 0x1239: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_123b:
	/* 0x123b: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_123d:
	/* 0x123d: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_123f:
	/* 0x123f: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1242:
	/* 0x1242: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1245:
	/* 0x1245: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1249:
	/* 0x1249: ja     1806 <generic_lsm_filter_arg+0x1806> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6150ULL;
	}
x86_l_124f:
	/* 0x124f: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1251:
	/* 0x1251: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1254:
	/* 0x1254: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_125a:
	/* 0x125a: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_125d:
	/* 0x125d: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_125f:
	/* 0x125f: jmp    2413 <generic_lsm_filter_arg+0x2413> */
	return 9235ULL;
x86_l_1264:
	/* 0x1264: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1267:
	/* 0x1267: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_126c:
	/* 0x126c: jg     1928 <generic_lsm_filter_arg+0x1928> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6440ULL;
	}
x86_l_1272:
	/* 0x1272: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1275:
	/* 0x1275: je     1ab1 <generic_lsm_filter_arg+0x1ab1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6833ULL;
	}
x86_l_127b:
	/* 0x127b: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1280:
	/* 0x1280: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1283:
	/* 0x1283: jne    3754 <generic_lsm_filter_arg+0x3754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14164ULL;
	}
x86_l_1289:
	/* 0x1289: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_128e:
	/* 0x128e: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1293:
	/* 0x1293: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1297:
	/* 0x1297: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_12a2:
	/* 0x12a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12a7:
	/* 0x12a7: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12ac:
	/* 0x12ac: mov    rdi,QWORD PTR [rip+0x1edc1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_12b3:
	/* 0x12b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b5:
	/* 0x12b5: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_12b7:
	/* 0x12b7: je     3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14147ULL;
	}
x86_l_12bd:
	/* 0x12bd: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_12c0:
	/* 0x12c0: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_12c5:
	/* 0x12c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12c8:
	/* 0x12c8: je     3745 <generic_lsm_filter_arg+0x3745> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14149ULL;
	}
x86_l_12ce:
	/* 0x12ce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12d3:
	/* 0x12d3: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12d8:
	/* 0x12d8: mov    rdi,QWORD PTR [rip+0x1edc1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_12df:
	/* 0x12df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e1:
	/* 0x12e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12e4:
	/* 0x12e4: je     3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14147ULL;
	}
x86_l_12ea:
	/* 0x12ea: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12ed:
	/* 0x12ed: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12f2:
	/* 0x12f2: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_12f5:
	/* 0x12f5: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_12fa:
	/* 0x12fa: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_12fd:
	/* 0x12fd: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1300:
	/* 0x1300: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1302:
	/* 0x1302: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_1305:
	/* 0x1305: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1308:
	/* 0x1308: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_130d:
	/* 0x130d: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1310:
	/* 0x1310: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_1313:
	/* 0x1313: mov    QWORD PTR [rsp+0x70],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1318:
	/* 0x1318: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_131c:
	/* 0x131c: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1322:
	/* 0x1322: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1325:
	/* 0x1325: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1329:
	/* 0x1329: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_132f:
	/* 0x132f: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1332:
	/* 0x1332: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1336:
	/* 0x1336: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1338:
	/* 0x1338: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_133a:
	/* 0x133a: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_133f:
	/* 0x133f: lea    r13d,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1343:
	/* 0x1343: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_134a:
	/* 0x134a: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_134f:
	/* 0x134f: mov    BYTE PTR [rdi-0x3],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1353:
	/* 0x1353: cmp    r10,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RBX, X86_WIDTH_64);
x86_l_1356:
	/* 0x1356: je     13b0 <generic_lsm_filter_arg+0x13b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5040ULL;
	}
x86_l_1358:
	/* 0x1358: lea    r13d,[r11+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_135c:
	/* 0x135c: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1363:
	/* 0x1363: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_1368:
	/* 0x1368: mov    BYTE PTR [rdi-0x2],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_136c:
	/* 0x136c: cmp    r8,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RBX, X86_WIDTH_64);
	return 4975ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4975ULL: goto x86_l_136f;
	case 4977ULL: goto x86_l_1371;
	case 4981ULL: goto x86_l_1375;
	case 4988ULL: goto x86_l_137c;
	case 4993ULL: goto x86_l_1381;
	case 4997ULL: goto x86_l_1385;
	case 5000ULL: goto x86_l_1388;
	case 5002ULL: goto x86_l_138a;
	case 5006ULL: goto x86_l_138e;
	case 5008ULL: goto x86_l_1390;
	case 5012ULL: goto x86_l_1394;
	case 5019ULL: goto x86_l_139b;
	case 5024ULL: goto x86_l_13a0;
	case 5027ULL: goto x86_l_13a3;
	case 5031ULL: goto x86_l_13a7;
	case 5035ULL: goto x86_l_13ab;
	case 5038ULL: goto x86_l_13ae;
	case 5040ULL: goto x86_l_13b0;
	case 5045ULL: goto x86_l_13b5;
	case 5050ULL: goto x86_l_13ba;
	case 5055ULL: goto x86_l_13bf;
	case 5060ULL: goto x86_l_13c4;
	case 5065ULL: goto x86_l_13c9;
	case 5070ULL: goto x86_l_13ce;
	case 5073ULL: goto x86_l_13d1;
	case 5079ULL: goto x86_l_13d7;
	case 5084ULL: goto x86_l_13dc;
	case 5087ULL: goto x86_l_13df;
	case 5093ULL: goto x86_l_13e5;
	case 5097ULL: goto x86_l_13e9;
	case 5099ULL: goto x86_l_13eb;
	case 5103ULL: goto x86_l_13ef;
	case 5105ULL: goto x86_l_13f1;
	case 5108ULL: goto x86_l_13f4;
	case 5113ULL: goto x86_l_13f9;
	case 5116ULL: goto x86_l_13fc;
	case 5122ULL: goto x86_l_1402;
	case 5125ULL: goto x86_l_1405;
	case 5130ULL: goto x86_l_140a;
	case 5133ULL: goto x86_l_140d;
	case 5139ULL: goto x86_l_1413;
	case 5144ULL: goto x86_l_1418;
	case 5147ULL: goto x86_l_141b;
	case 5149ULL: goto x86_l_141d;
	case 5154ULL: goto x86_l_1422;
	case 5157ULL: goto x86_l_1425;
	case 5163ULL: goto x86_l_142b;
	case 5166ULL: goto x86_l_142e;
	case 5171ULL: goto x86_l_1433;
	case 5173ULL: goto x86_l_1435;
	case 5176ULL: goto x86_l_1438;
	case 5181ULL: goto x86_l_143d;
	case 5183ULL: goto x86_l_143f;
	case 5186ULL: goto x86_l_1442;
	case 5189ULL: goto x86_l_1445;
	case 5191ULL: goto x86_l_1447;
	case 5194ULL: goto x86_l_144a;
	case 5200ULL: goto x86_l_1450;
	case 5203ULL: goto x86_l_1453;
	case 5206ULL: goto x86_l_1456;
	case 5212ULL: goto x86_l_145c;
	case 5215ULL: goto x86_l_145f;
	case 5218ULL: goto x86_l_1462;
	case 5224ULL: goto x86_l_1468;
	case 5227ULL: goto x86_l_146b;
	case 5233ULL: goto x86_l_1471;
	case 5238ULL: goto x86_l_1476;
	case 5241ULL: goto x86_l_1479;
	case 5247ULL: goto x86_l_147f;
	case 5252ULL: goto x86_l_1484;
	case 5255ULL: goto x86_l_1487;
	case 5261ULL: goto x86_l_148d;
	case 5264ULL: goto x86_l_1490;
	case 5270ULL: goto x86_l_1496;
	case 5273ULL: goto x86_l_1499;
	case 5279ULL: goto x86_l_149f;
	case 5281ULL: goto x86_l_14a1;
	case 5286ULL: goto x86_l_14a6;
	case 5290ULL: goto x86_l_14aa;
	case 5293ULL: goto x86_l_14ad;
	case 5297ULL: goto x86_l_14b1;
	case 5299ULL: goto x86_l_14b3;
	case 5303ULL: goto x86_l_14b7;
	case 5306ULL: goto x86_l_14ba;
	case 5310ULL: goto x86_l_14be;
	case 5313ULL: goto x86_l_14c1;
	case 5317ULL: goto x86_l_14c5;
	case 5319ULL: goto x86_l_14c7;
	case 5321ULL: goto x86_l_14c9;
	case 5324ULL: goto x86_l_14cc;
	case 5326ULL: goto x86_l_14ce;
	case 5329ULL: goto x86_l_14d1;
	case 5335ULL: goto x86_l_14d7;
	case 5340ULL: goto x86_l_14dc;
	case 5343ULL: goto x86_l_14df;
	case 5349ULL: goto x86_l_14e5;
	case 5354ULL: goto x86_l_14ea;
	case 5357ULL: goto x86_l_14ed;
	case 5363ULL: goto x86_l_14f3;
	case 5368ULL: goto x86_l_14f8;
	case 5371ULL: goto x86_l_14fb;
	case 5377ULL: goto x86_l_1501;
	case 5381ULL: goto x86_l_1505;
	case 5384ULL: goto x86_l_1508;
	case 5390ULL: goto x86_l_150e;
	case 5393ULL: goto x86_l_1511;
	case 5399ULL: goto x86_l_1517;
	case 5402ULL: goto x86_l_151a;
	case 5407ULL: goto x86_l_151f;
	case 5412ULL: goto x86_l_1524;
	case 5416ULL: goto x86_l_1528;
	case 5421ULL: goto x86_l_152d;
	case 5426ULL: goto x86_l_1532;
	case 5433ULL: goto x86_l_1539;
	case 5435ULL: goto x86_l_153b;
	case 5438ULL: goto x86_l_153e;
	case 5444ULL: goto x86_l_1544;
	case 5447ULL: goto x86_l_1547;
	case 5458ULL: goto x86_l_1552;
	case 5466ULL: goto x86_l_155a;
	case 5471ULL: goto x86_l_155f;
	case 5474ULL: goto x86_l_1562;
	case 5480ULL: goto x86_l_1568;
	case 5485ULL: goto x86_l_156d;
	case 5488ULL: goto x86_l_1570;
	case 5494ULL: goto x86_l_1576;
	case 5498ULL: goto x86_l_157a;
	case 5504ULL: goto x86_l_1580;
	case 5509ULL: goto x86_l_1585;
	case 5514ULL: goto x86_l_158a;
	case 5516ULL: goto x86_l_158c;
	case 5519ULL: goto x86_l_158f;
	case 5522ULL: goto x86_l_1592;
	case 5527ULL: goto x86_l_1597;
	case 5531ULL: goto x86_l_159b;
	case 5536ULL: goto x86_l_15a0;
	case 5541ULL: goto x86_l_15a5;
	case 5548ULL: goto x86_l_15ac;
	case 5550ULL: goto x86_l_15ae;
	case 5553ULL: goto x86_l_15b1;
	case 5559ULL: goto x86_l_15b7;
	case 5561ULL: goto x86_l_15b9;
	case 5566ULL: goto x86_l_15be;
	case 5569ULL: goto x86_l_15c1;
	case 5574ULL: goto x86_l_15c6;
	case 5576ULL: goto x86_l_15c8;
	case 5581ULL: goto x86_l_15cd;
	case 5583ULL: goto x86_l_15cf;
	case 5585ULL: goto x86_l_15d1;
	case 5588ULL: goto x86_l_15d4;
	case 5591ULL: goto x86_l_15d7;
	case 5594ULL: goto x86_l_15da;
	case 5596ULL: goto x86_l_15dc;
	case 5598ULL: goto x86_l_15de;
	case 5602ULL: goto x86_l_15e2;
	case 5605ULL: goto x86_l_15e5;
	case 5607ULL: goto x86_l_15e7;
	case 5611ULL: goto x86_l_15eb;
	case 5614ULL: goto x86_l_15ee;
	case 5616ULL: goto x86_l_15f0;
	case 5620ULL: goto x86_l_15f4;
	case 5622ULL: goto x86_l_15f6;
	case 5626ULL: goto x86_l_15fa;
	case 5630ULL: goto x86_l_15fe;
	case 5633ULL: goto x86_l_1601;
	case 5635ULL: goto x86_l_1603;
	case 5637ULL: goto x86_l_1605;
	case 5639ULL: goto x86_l_1607;
	case 5645ULL: goto x86_l_160d;
	case 5649ULL: goto x86_l_1611;
	case 5654ULL: goto x86_l_1616;
	case 5660ULL: goto x86_l_161c;
	case 5664ULL: goto x86_l_1620;
	case 5667ULL: goto x86_l_1623;
	case 5671ULL: goto x86_l_1627;
	case 5677ULL: goto x86_l_162d;
	case 5682ULL: goto x86_l_1632;
	case 5685ULL: goto x86_l_1635;
	case 5688ULL: goto x86_l_1638;
	case 5694ULL: goto x86_l_163e;
	case 5697ULL: goto x86_l_1641;
	case 5703ULL: goto x86_l_1647;
	case 5707ULL: goto x86_l_164b;
	case 5712ULL: goto x86_l_1650;
	case 5719ULL: goto x86_l_1657;
	case 5724ULL: goto x86_l_165c;
	case 5726ULL: goto x86_l_165e;
	case 5729ULL: goto x86_l_1661;
	case 5735ULL: goto x86_l_1667;
	case 5738ULL: goto x86_l_166a;
	case 5741ULL: goto x86_l_166d;
	case 5749ULL: goto x86_l_1675;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5764ULL: goto x86_l_1684;
	case 5767ULL: goto x86_l_1687;
	case 5773ULL: goto x86_l_168d;
	case 5776ULL: goto x86_l_1690;
	case 5782ULL: goto x86_l_1696;
	case 5787ULL: goto x86_l_169b;
	case 5789ULL: goto x86_l_169d;
	case 5795ULL: goto x86_l_16a3;
	case 5800ULL: goto x86_l_16a8;
	case 5803ULL: goto x86_l_16ab;
	case 5809ULL: goto x86_l_16b1;
	case 5812ULL: goto x86_l_16b4;
	case 5818ULL: goto x86_l_16ba;
	case 5823ULL: goto x86_l_16bf;
	case 5825ULL: goto x86_l_16c1;
	case 5831ULL: goto x86_l_16c7;
	case 5836ULL: goto x86_l_16cc;
	case 5839ULL: goto x86_l_16cf;
	case 5842ULL: goto x86_l_16d2;
	case 5848ULL: goto x86_l_16d8;
	case 5855ULL: goto x86_l_16df;
	case 5860ULL: goto x86_l_16e4;
	case 5865ULL: goto x86_l_16e9;
	case 5872ULL: goto x86_l_16f0;
	case 5874ULL: goto x86_l_16f2;
	case 5877ULL: goto x86_l_16f5;
	case 5883ULL: goto x86_l_16fb;
	case 5886ULL: goto x86_l_16fe;
	case 5889ULL: goto x86_l_1701;
	case 5894ULL: goto x86_l_1706;
	case 5899ULL: goto x86_l_170b;
	case 5904ULL: goto x86_l_1710;
	case 5909ULL: goto x86_l_1715;
	case 5912ULL: goto x86_l_1718;
	case 5915ULL: goto x86_l_171b;
	case 5921ULL: goto x86_l_1721;
	case 5928ULL: goto x86_l_1728;
	case 5933ULL: goto x86_l_172d;
	case 5938ULL: goto x86_l_1732;
	case 5945ULL: goto x86_l_1739;
	case 5947ULL: goto x86_l_173b;
	case 5950ULL: goto x86_l_173e;
	case 5956ULL: goto x86_l_1744;
	case 5959ULL: goto x86_l_1747;
	case 5962ULL: goto x86_l_174a;
	case 5967ULL: goto x86_l_174f;
	case 5972ULL: goto x86_l_1754;
	case 5977ULL: goto x86_l_1759;
	case 5982ULL: goto x86_l_175e;
	case 5989ULL: goto x86_l_1765;
	case 5995ULL: goto x86_l_176b;
	case 5998ULL: goto x86_l_176e;
	case 6004ULL: goto x86_l_1774;
	case 6006ULL: goto x86_l_1776;
	case 6012ULL: goto x86_l_177c;
	case 6015ULL: goto x86_l_177f;
	case 6021ULL: goto x86_l_1785;
	case 6027ULL: goto x86_l_178b;
	case 6032ULL: goto x86_l_1790;
	case 6035ULL: goto x86_l_1793;
	case 6037ULL: goto x86_l_1795;
	case 6042ULL: goto x86_l_179a;
	case 6045ULL: goto x86_l_179d;
	case 6050ULL: goto x86_l_17a2;
	case 6053ULL: goto x86_l_17a5;
	case 6055ULL: goto x86_l_17a7;
	case 6060ULL: goto x86_l_17ac;
	case 6063ULL: goto x86_l_17af;
	case 6068ULL: goto x86_l_17b4;
	case 6071ULL: goto x86_l_17b7;
	case 6074ULL: goto x86_l_17ba;
	case 6079ULL: goto x86_l_17bf;
	case 6084ULL: goto x86_l_17c4;
	case 6087ULL: goto x86_l_17c7;
	case 6090ULL: goto x86_l_17ca;
	case 6095ULL: goto x86_l_17cf;
	case 6100ULL: goto x86_l_17d4;
	case 6105ULL: goto x86_l_17d9;
	case 6107ULL: goto x86_l_17db;
	case 6112ULL: goto x86_l_17e0;
	case 6117ULL: goto x86_l_17e5;
	case 6119ULL: goto x86_l_17e7;
	case 6124ULL: goto x86_l_17ec;
	case 6129ULL: goto x86_l_17f1;
	case 6131ULL: goto x86_l_17f3;
	case 6133ULL: goto x86_l_17f5;
	case 6138ULL: goto x86_l_17fa;
	case 6141ULL: goto x86_l_17fd;
	case 6144ULL: goto x86_l_1800;
	case 6150ULL: goto x86_l_1806;
	case 6156ULL: goto x86_l_180c;
	case 6162ULL: goto x86_l_1812;
	case 6165ULL: goto x86_l_1815;
	case 6171ULL: goto x86_l_181b;
	case 6173ULL: goto x86_l_181d;
	case 6179ULL: goto x86_l_1823;
	case 6182ULL: goto x86_l_1826;
	case 6188ULL: goto x86_l_182c;
	case 6193ULL: goto x86_l_1831;
	case 6198ULL: goto x86_l_1836;
	case 6201ULL: goto x86_l_1839;
	case 6204ULL: goto x86_l_183c;
	case 6209ULL: goto x86_l_1841;
	case 6214ULL: goto x86_l_1846;
	case 6218ULL: goto x86_l_184a;
	case 6223ULL: goto x86_l_184f;
	case 6230ULL: goto x86_l_1856;
	case 6235ULL: goto x86_l_185b;
	case 6237ULL: goto x86_l_185d;
	case 6240ULL: goto x86_l_1860;
	case 6246ULL: goto x86_l_1866;
	case 6249ULL: goto x86_l_1869;
	case 6260ULL: goto x86_l_1874;
	case 6267ULL: goto x86_l_187b;
	case 6275ULL: goto x86_l_1883;
	case 6282ULL: goto x86_l_188a;
	case 6286ULL: goto x86_l_188e;
	case 6293ULL: goto x86_l_1895;
	case 6298ULL: goto x86_l_189a;
	case 6303ULL: goto x86_l_189f;
	case 6305ULL: goto x86_l_18a1;
	case 6310ULL: goto x86_l_18a6;
	case 6313ULL: goto x86_l_18a9;
	case 6316ULL: goto x86_l_18ac;
	case 6322ULL: goto x86_l_18b2;
	case 6325ULL: goto x86_l_18b5;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6345ULL: goto x86_l_18c9;
	case 6348ULL: goto x86_l_18cc;
	case 6351ULL: goto x86_l_18cf;
	case 6354ULL: goto x86_l_18d2;
	case 6359ULL: goto x86_l_18d7;
	case 6361ULL: goto x86_l_18d9;
	case 6364ULL: goto x86_l_18dc;
	case 6369ULL: goto x86_l_18e1;
	case 6372ULL: goto x86_l_18e4;
	case 6378ULL: goto x86_l_18ea;
	case 6383ULL: goto x86_l_18ef;
	case 6386ULL: goto x86_l_18f2;
	case 6388ULL: goto x86_l_18f4;
	case 6397ULL: goto x86_l_18fd;
	case 6403ULL: goto x86_l_1903;
	case 6407ULL: goto x86_l_1907;
	case 6415ULL: goto x86_l_190f;
	case 6420ULL: goto x86_l_1914;
	case 6422ULL: goto x86_l_1916;
	case 6432ULL: goto x86_l_1920;
	case 6435ULL: goto x86_l_1923;
	case 6440ULL: goto x86_l_1928;
	case 6443ULL: goto x86_l_192b;
	case 6449ULL: goto x86_l_1931;
	case 6454ULL: goto x86_l_1936;
	case 6457ULL: goto x86_l_1939;
	case 6463ULL: goto x86_l_193f;
	case 6469ULL: goto x86_l_1945;
	case 6472ULL: goto x86_l_1948;
	case 6476ULL: goto x86_l_194c;
	case 6480ULL: goto x86_l_1950;
	case 6485ULL: goto x86_l_1955;
	case 6490ULL: goto x86_l_195a;
	case 6497ULL: goto x86_l_1961;
	case 6499ULL: goto x86_l_1963;
	case 6502ULL: goto x86_l_1966;
	case 6508ULL: goto x86_l_196c;
	case 6513ULL: goto x86_l_1971;
	case 6516ULL: goto x86_l_1974;
	case 6519ULL: goto x86_l_1977;
	case 6524ULL: goto x86_l_197c;
	case 6526ULL: goto x86_l_197e;
	case 6532ULL: goto x86_l_1984;
	case 6536ULL: goto x86_l_1988;
	case 6540ULL: goto x86_l_198c;
	case 6545ULL: goto x86_l_1991;
	case 6550ULL: goto x86_l_1996;
	case 6555ULL: goto x86_l_199b;
	case 6558ULL: goto x86_l_199e;
	case 6564ULL: goto x86_l_19a4;
	case 6569ULL: goto x86_l_19a9;
	case 6576ULL: goto x86_l_19b0;
	case 6581ULL: goto x86_l_19b5;
	case 6583ULL: goto x86_l_19b7;
	case 6588ULL: goto x86_l_19bc;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6599ULL: goto x86_l_19c7;
	case 6605ULL: goto x86_l_19cd;
	case 6610ULL: goto x86_l_19d2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_136f:
	/* 0x136f: je     13b0 <generic_lsm_filter_arg+0x13b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13b0;
	}
x86_l_1371:
	/* 0x1371: lea    r13d,[r9+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1375:
	/* 0x1375: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_137c:
	/* 0x137c: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_1381:
	/* 0x1381: mov    BYTE PTR [rdi-0x1],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1385:
	/* 0x1385: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1388:
	/* 0x1388: je     13b0 <generic_lsm_filter_arg+0x13b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13b0;
	}
x86_l_138a:
	/* 0x138a: cmp    rbx,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_138e:
	/* 0x138e: je     13b0 <generic_lsm_filter_arg+0x13b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13b0;
	}
x86_l_1390:
	/* 0x1390: lea    r13d,[rdx+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1394:
	/* 0x1394: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_139b:
	/* 0x139b: movzx  r13d,BYTE PTR [rsi+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_13a0:
	/* 0x13a0: mov    BYTE PTR [rdi],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13a3:
	/* 0x13a3: add    rbx,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_13a7:
	/* 0x13a7: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_13ab:
	/* 0x13ab: cmp    rax,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_13ae:
	/* 0x13ae: jne    133f <generic_lsm_filter_arg+0x133f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4927ULL;
	}
x86_l_13b0:
	/* 0x13b0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13b5:
	/* 0x13b5: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13ba:
	/* 0x13ba: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13bf:
	/* 0x13bf: jmp    1b4c <generic_lsm_filter_arg+0x1b4c> */
	return 6988ULL;
x86_l_13c4:
	/* 0x13c4: mov    esi,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13c9:
	/* 0x13c9: mov    eax,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_13ce:
	/* 0x13ce: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_13d1:
	/* 0x13d1: ja     2093 <generic_lsm_filter_arg+0x2093> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8339ULL;
	}
x86_l_13d7:
	/* 0x13d7: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_13dc:
	/* 0x13dc: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_13df:
	/* 0x13df: jae    2093 <generic_lsm_filter_arg+0x2093> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8339ULL;
	}
x86_l_13e5:
	/* 0x13e5: mov    edx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e9:
	/* 0x13e9: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_13eb:
	/* 0x13eb: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_13ef:
	/* 0x13ef: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_13f1:
	/* 0x13f1: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_13f4:
	/* 0x13f4: jmp    20a2 <generic_lsm_filter_arg+0x20a2> */
	return 8354ULL;
x86_l_13f9:
	/* 0x13f9: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_13fc:
	/* 0x13fc: je     1a68 <generic_lsm_filter_arg+0x1a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6760ULL;
	}
x86_l_1402:
	/* 0x1402: mov    r13d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_32);
x86_l_1405:
	/* 0x1405: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_140a:
	/* 0x140a: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_140d:
	/* 0x140d: je     19cd <generic_lsm_filter_arg+0x19cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19cd;
	}
x86_l_1413:
	/* 0x1413: jmp    117 <generic_lsm_filter_arg+0x117> */
	return 279ULL;
x86_l_1418:
	/* 0x1418: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_141b:
	/* 0x141b: je     1435 <generic_lsm_filter_arg+0x1435> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1435;
	}
x86_l_141d:
	/* 0x141d: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1422:
	/* 0x1422: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1425:
	/* 0x1425: jne    2c9 <generic_lsm_filter_arg+0x2c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 713ULL;
	}
x86_l_142b:
	/* 0x142b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_142e:
	/* 0x142e: movzx  ebp,WORD PTR [r13+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1433:
	/* 0x1433: jmp    143d <generic_lsm_filter_arg+0x143d> */
	goto x86_l_143d;
x86_l_1435:
	/* 0x1435: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1438:
	/* 0x1438: movzx  ebp,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_143d:
	/* 0x143d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_143f:
	/* 0x143f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1442:
	/* 0x1442: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1445:
	/* 0x1445: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1447:
	/* 0x1447: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_144a:
	/* 0x144a: jg     14ce <generic_lsm_filter_arg+0x14ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_14ce;
	}
x86_l_1450:
	/* 0x1450: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_1453:
	/* 0x1453: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1456:
	/* 0x1456: jb     1501 <generic_lsm_filter_arg+0x1501> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1501;
	}
x86_l_145c:
	/* 0x145c: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_145f:
	/* 0x145f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1462:
	/* 0x1462: jb     163e <generic_lsm_filter_arg+0x163e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_163e;
	}
x86_l_1468:
	/* 0x1468: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_146b:
	/* 0x146b: je     1c80 <generic_lsm_filter_arg+0x1c80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7296ULL;
	}
x86_l_1471:
	/* 0x1471: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_1476:
	/* 0x1476: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_1479:
	/* 0x1479: je     1c7b <generic_lsm_filter_arg+0x1c7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7291ULL;
	}
x86_l_147f:
	/* 0x147f: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1484:
	/* 0x1484: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_1487:
	/* 0x1487: jne    2c9 <generic_lsm_filter_arg+0x2c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 713ULL;
	}
x86_l_148d:
	/* 0x148d: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1490:
	/* 0x1490: jne    2210 <generic_lsm_filter_arg+0x2210> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8720ULL;
	}
x86_l_1496:
	/* 0x1496: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1499:
	/* 0x1499: jne    221c <generic_lsm_filter_arg+0x221c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8732ULL;
	}
x86_l_149f:
	/* 0x149f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a1:
	/* 0x14a1: jmp    222e <generic_lsm_filter_arg+0x222e> */
	return 8750ULL;
x86_l_14a6:
	/* 0x14a6: mov    rsi,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14aa:
	/* 0x14aa: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_14ad:
	/* 0x14ad: mov    r8,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14b1:
	/* 0x14b1: jmp    14be <generic_lsm_filter_arg+0x14be> */
	goto x86_l_14be;
x86_l_14b3:
	/* 0x14b3: mov    rsi,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b7:
	/* 0x14b7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_14ba:
	/* 0x14ba: mov    r8,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14be:
	/* 0x14be: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_14c1:
	/* 0x14c1: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_14c5:
	/* 0x14c5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c7:
	/* 0x14c7: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c9:
	/* 0x14c9: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_14cc:
	/* 0x14cc: jle    1450 <generic_lsm_filter_arg+0x1450> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1450;
	}
x86_l_14ce:
	/* 0x14ce: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_14d1:
	/* 0x14d1: ja     1632 <generic_lsm_filter_arg+0x1632> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1632;
	}
x86_l_14d7:
	/* 0x14d7: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_14dc:
	/* 0x14dc: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_14df:
	/* 0x14df: jb     1790 <generic_lsm_filter_arg+0x1790> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1790;
	}
x86_l_14e5:
	/* 0x14e5: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_14ea:
	/* 0x14ea: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_14ed:
	/* 0x14ed: jb     17a2 <generic_lsm_filter_arg+0x17a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_17a2;
	}
x86_l_14f3:
	/* 0x14f3: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_14f8:
	/* 0x14f8: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_14fb:
	/* 0x14fb: jae    1632 <generic_lsm_filter_arg+0x1632> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1632;
	}
x86_l_1501:
	/* 0x1501: movzx  eax,WORD PTR [rdx+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1505:
	/* 0x1505: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1508:
	/* 0x1508: je     1836 <generic_lsm_filter_arg+0x1836> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1836;
	}
x86_l_150e:
	/* 0x150e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1511:
	/* 0x1511: jne    18d7 <generic_lsm_filter_arg+0x18d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18d7;
	}
x86_l_1517:
	/* 0x1517: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_151a:
	/* 0x151a: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_151f:
	/* 0x151f: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1524:
	/* 0x1524: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1528:
	/* 0x1528: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_152d:
	/* 0x152d: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1532:
	/* 0x1532: mov    rdi,QWORD PTR [rip+0x1edbd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_1539:
	/* 0x1539: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153b:
	/* 0x153b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_153e:
	/* 0x153e: je     1d66 <generic_lsm_filter_arg+0x1d66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7526ULL;
	}
x86_l_1544:
	/* 0x1544: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1547:
	/* 0x1547: mov    DWORD PTR [rsp+0x80],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813920ULL);
x86_l_1552:
	/* 0x1552: mov    DWORD PTR [rsp+0x84],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_155a:
	/* 0x155a: jmp    1895 <generic_lsm_filter_arg+0x1895> */
	goto x86_l_1895;
x86_l_155f:
	/* 0x155f: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1562:
	/* 0x1562: ja     22e4 <generic_lsm_filter_arg+0x22e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8932ULL;
	}
x86_l_1568:
	/* 0x1568: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_156d:
	/* 0x156d: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1570:
	/* 0x1570: jae    22e4 <generic_lsm_filter_arg+0x22e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8932ULL;
	}
x86_l_1576:
	/* 0x1576: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_157a:
	/* 0x157a: jg     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 730ULL;
	}
x86_l_1580:
	/* 0x1580: jmp    22fa <generic_lsm_filter_arg+0x22fa> */
	return 8954ULL;
x86_l_1585:
	/* 0x1585: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_158a:
	/* 0x158a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_158c:
	/* 0x158c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_158f:
	/* 0x158f: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_1592:
	/* 0x1592: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_1597:
	/* 0x1597: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_159b:
	/* 0x159b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15a0:
	/* 0x15a0: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15a5:
	/* 0x15a5: mov    rdi,QWORD PTR [rip+0x1edbd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_15ac:
	/* 0x15ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ae:
	/* 0x15ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15b1:
	/* 0x15b1: je     21af <generic_lsm_filter_arg+0x21af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8623ULL;
	}
x86_l_15b7:
	/* 0x15b7: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_15b9:
	/* 0x15b9: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15be:
	/* 0x15be: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_15c1:
	/* 0x15c1: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15c6:
	/* 0x15c6: je     160d <generic_lsm_filter_arg+0x160d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_160d;
	}
x86_l_15c8:
	/* 0x15c8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15cd:
	/* 0x15cd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15cf:
	/* 0x15cf: jmp    15dc <generic_lsm_filter_arg+0x15dc> */
	goto x86_l_15dc;
x86_l_15d1:
	/* 0x15d1: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15d4:
	/* 0x15d4: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15d7:
	/* 0x15d7: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_15da:
	/* 0x15da: je     160d <generic_lsm_filter_arg+0x160d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_160d;
	}
x86_l_15dc:
	/* 0x15dc: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15de:
	/* 0x15de: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_15e2:
	/* 0x15e2: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_15e5:
	/* 0x15e5: jae    15d1 <generic_lsm_filter_arg+0x15d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_15d1;
	}
x86_l_15e7:
	/* 0x15e7: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_15eb:
	/* 0x15eb: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_15ee:
	/* 0x15ee: je     1605 <generic_lsm_filter_arg+0x1605> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1605;
	}
x86_l_15f0:
	/* 0x15f0: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_15f4:
	/* 0x15f4: ja     15d1 <generic_lsm_filter_arg+0x15d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15d1;
	}
x86_l_15f6:
	/* 0x15f6: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_15fa:
	/* 0x15fa: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_15fe:
	/* 0x15fe: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1601:
	/* 0x1601: je     15de <generic_lsm_filter_arg+0x15de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15de;
	}
x86_l_1603:
	/* 0x1603: jmp    15d1 <generic_lsm_filter_arg+0x15d1> */
	goto x86_l_15d1;
x86_l_1605:
	/* 0x1605: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1607:
	/* 0x1607: jns    23f1 <generic_lsm_filter_arg+0x23f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9201ULL;
	}
x86_l_160d:
	/* 0x160d: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1611:
	/* 0x1611: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1616:
	/* 0x1616: jae    21a3 <generic_lsm_filter_arg+0x21a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8611ULL;
	}
x86_l_161c:
	/* 0x161c: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1620:
	/* 0x1620: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1623:
	/* 0x1623: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_1627:
	/* 0x1627: jne    158f <generic_lsm_filter_arg+0x158f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_158f;
	}
x86_l_162d:
	/* 0x162d: jmp    21a3 <generic_lsm_filter_arg+0x21a3> */
	return 8611ULL;
x86_l_1632:
	/* 0x1632: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_1635:
	/* 0x1635: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1638:
	/* 0x1638: jae    2c9 <generic_lsm_filter_arg+0x2c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 713ULL;
	}
x86_l_163e:
	/* 0x163e: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_1641:
	/* 0x1641: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1647:
	/* 0x1647: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_164b:
	/* 0x164b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1650:
	/* 0x1650: mov    rdi,QWORD PTR [rip+0x1edc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1657:
	/* 0x1657: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_165c:
	/* 0x165c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_165e:
	/* 0x165e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1661:
	/* 0x1661: je     2ba <generic_lsm_filter_arg+0x2ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 698ULL;
	}
x86_l_1667:
	/* 0x1667: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_166a:
	/* 0x166a: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_166d:
	/* 0x166d: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1675:
	/* 0x1675: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_167a:
	/* 0x167a: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_167f:
	/* 0x167f: jmp    1cc1 <generic_lsm_filter_arg+0x1cc1> */
	return 7361ULL;
x86_l_1684:
	/* 0x1684: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1687:
	/* 0x1687: je     1faa <generic_lsm_filter_arg+0x1faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8106ULL;
	}
x86_l_168d:
	/* 0x168d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1690:
	/* 0x1690: jne    1fb7 <generic_lsm_filter_arg+0x1fb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8119ULL;
	}
x86_l_1696:
	/* 0x1696: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_169b:
	/* 0x169b: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_169d:
	/* 0x169d: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_16a3:
	/* 0x16a3: jmp    1fb7 <generic_lsm_filter_arg+0x1fb7> */
	return 8119ULL;
x86_l_16a8:
	/* 0x16a8: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16ab:
	/* 0x16ab: je     1ff1 <generic_lsm_filter_arg+0x1ff1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8177ULL;
	}
x86_l_16b1:
	/* 0x16b1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16b4:
	/* 0x16b4: jne    1ffe <generic_lsm_filter_arg+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8190ULL;
	}
x86_l_16ba:
	/* 0x16ba: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16bf:
	/* 0x16bf: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_16c1:
	/* 0x16c1: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_16c7:
	/* 0x16c7: jmp    1ffe <generic_lsm_filter_arg+0x1ffe> */
	return 8190ULL;
x86_l_16cc:
	/* 0x16cc: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_16cf:
	/* 0x16cf: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_16d2:
	/* 0x16d2: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_16d8:
	/* 0x16d8: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_16df:
	/* 0x16df: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16e4:
	/* 0x16e4: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16e9:
	/* 0x16e9: mov    rdi,QWORD PTR [rip+0x1edc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_16f0:
	/* 0x16f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f2:
	/* 0x16f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16f5:
	/* 0x16f5: je     2ba <generic_lsm_filter_arg+0x2ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 698ULL;
	}
x86_l_16fb:
	/* 0x16fb: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_16fe:
	/* 0x16fe: movzx  eax,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1701:
	/* 0x1701: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1706:
	/* 0x1706: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_170b:
	/* 0x170b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1710:
	/* 0x1710: jmp    1cc1 <generic_lsm_filter_arg+0x1cc1> */
	return 7361ULL;
x86_l_1715:
	/* 0x1715: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_1718:
	/* 0x1718: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_171b:
	/* 0x171b: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1721:
	/* 0x1721: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1728:
	/* 0x1728: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_172d:
	/* 0x172d: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1732:
	/* 0x1732: mov    rdi,QWORD PTR [rip+0x1edc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1739:
	/* 0x1739: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173b:
	/* 0x173b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_173e:
	/* 0x173e: je     2ba <generic_lsm_filter_arg+0x2ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 698ULL;
	}
x86_l_1744:
	/* 0x1744: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1747:
	/* 0x1747: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_174a:
	/* 0x174a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_174f:
	/* 0x174f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1754:
	/* 0x1754: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1759:
	/* 0x1759: jmp    1cc1 <generic_lsm_filter_arg+0x1cc1> */
	return 7361ULL;
x86_l_175e:
	/* 0x175e: lea    eax,[r10-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_1765:
	/* 0x1765: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_176b:
	/* 0x176b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_176e:
	/* 0x176e: jg     1f70 <generic_lsm_filter_arg+0x1f70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8048ULL;
	}
x86_l_1774:
	/* 0x1774: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1776:
	/* 0x1776: je     2632 <generic_lsm_filter_arg+0x2632> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9778ULL;
	}
x86_l_177c:
	/* 0x177c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_177f:
	/* 0x177f: jne    262a <generic_lsm_filter_arg+0x262a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9770ULL;
	}
x86_l_1785:
	/* 0x1785: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_178b:
	/* 0x178b: jmp    2640 <generic_lsm_filter_arg+0x2640> */
	return 9792ULL;
x86_l_1790:
	/* 0x1790: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1793:
	/* 0x1793: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1795:
	/* 0x1795: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_179a:
	/* 0x179a: setb   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_B);
x86_l_179d:
	/* 0x179d: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_17a2:
	/* 0x17a2: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_17a5:
	/* 0x17a5: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17a7:
	/* 0x17a7: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_17ac:
	/* 0x17ac: setae  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_AE);
x86_l_17af:
	/* 0x17af: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_17b4:
	/* 0x17b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17b7:
	/* 0x17b7: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_17ba:
	/* 0x17ba: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17bf:
	/* 0x17bf: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17c4:
	/* 0x17c4: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_17c7:
	/* 0x17c7: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_17ca:
	/* 0x17ca: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_17cf:
	/* 0x17cf: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_17d4:
	/* 0x17d4: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_17d9:
	/* 0x17d9: jb     1806 <generic_lsm_filter_arg+0x1806> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1806;
	}
x86_l_17db:
	/* 0x17db: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_17e0:
	/* 0x17e0: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_17e5:
	/* 0x17e5: jb     1806 <generic_lsm_filter_arg+0x1806> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1806;
	}
x86_l_17e7:
	/* 0x17e7: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_17ec:
	/* 0x17ec: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_17f1:
	/* 0x17f1: jb     1806 <generic_lsm_filter_arg+0x1806> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1806;
	}
x86_l_17f3:
	/* 0x17f3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17f5:
	/* 0x17f5: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_17fa:
	/* 0x17fa: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_17fd:
	/* 0x17fd: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_1800:
	/* 0x1800: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_1806:
	/* 0x1806: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_180c:
	/* 0x180c: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_1812:
	/* 0x1812: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1815:
	/* 0x1815: jg     1ea9 <generic_lsm_filter_arg+0x1ea9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7849ULL;
	}
x86_l_181b:
	/* 0x181b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_181d:
	/* 0x181d: je     2407 <generic_lsm_filter_arg+0x2407> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9223ULL;
	}
x86_l_1823:
	/* 0x1823: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1826:
	/* 0x1826: jne    2400 <generic_lsm_filter_arg+0x2400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9216ULL;
	}
x86_l_182c:
	/* 0x182c: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1831:
	/* 0x1831: jmp    2413 <generic_lsm_filter_arg+0x2413> */
	return 9235ULL;
x86_l_1836:
	/* 0x1836: mov    rbx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R8, X86_WIDTH_64);
x86_l_1839:
	/* 0x1839: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_183c:
	/* 0x183c: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1841:
	/* 0x1841: mov    eax,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1846:
	/* 0x1846: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_184a:
	/* 0x184a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_184f:
	/* 0x184f: mov    rdi,QWORD PTR [rip+0x1edc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_1856:
	/* 0x1856: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_185b:
	/* 0x185b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_185d:
	/* 0x185d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1860:
	/* 0x1860: je     1d66 <generic_lsm_filter_arg+0x1d66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7526ULL;
	}
x86_l_1866:
	/* 0x1866: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1869:
	/* 0x1869: mov    DWORD PTR [rsp+0x80],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755814016ULL);
x86_l_1874:
	/* 0x1874: mov    DWORD PTR [rsp+0x84],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_187b:
	/* 0x187b: mov    DWORD PTR [rsp+0x88],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1883:
	/* 0x1883: mov    DWORD PTR [rsp+0x8c],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_188a:
	/* 0x188a: shr    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_188e:
	/* 0x188e: mov    DWORD PTR [rsp+0x90],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1895:
	/* 0x1895: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_189a:
	/* 0x189a: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_189f:
	/* 0x189f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a1:
	/* 0x18a1: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18a6:
	/* 0x18a6: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_18a9:
	/* 0x18a9: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_18ac:
	/* 0x18ac: jb     1f8d <generic_lsm_filter_arg+0x1f8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8077ULL;
	}
x86_l_18b2:
	/* 0x18b2: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_18b5:
	/* 0x18b5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_18b8:
	/* 0x18b8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18bd:
	/* 0x18bd: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18c2:
	/* 0x18c2: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18c7:
	/* 0x18c7: ja     18d7 <generic_lsm_filter_arg+0x18d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18d7;
	}
x86_l_18c9:
	/* 0x18c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18cc:
	/* 0x18cc: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_18cf:
	/* 0x18cf: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_18d2:
	/* 0x18d2: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_18d7:
	/* 0x18d7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18d9:
	/* 0x18d9: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_18dc:
	/* 0x18dc: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_18e1:
	/* 0x18e1: cmp    eax,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_18e4:
	/* 0x18e4: jne    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_18ea:
	/* 0x18ea: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18ef:
	/* 0x18ef: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_18f2:
	/* 0x18f2: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_18f4:
	/* 0x18f4: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_18fd:
	/* 0x18fd: jne    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_1903:
	/* 0x1903: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1907:
	/* 0x1907: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_190f:
	/* 0x190f: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1914:
	/* 0x1914: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1916:
	/* 0x1916: andn   rax,rcx,QWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ANDN_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 144ULL);
x86_l_1920:
	/* 0x1920: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_1923:
	/* 0x1923: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_1928:
	/* 0x1928: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_192b:
	/* 0x192b: je     2104 <generic_lsm_filter_arg+0x2104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8452ULL;
	}
x86_l_1931:
	/* 0x1931: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1936:
	/* 0x1936: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_1939:
	/* 0x1939: jne    3754 <generic_lsm_filter_arg+0x3754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14164ULL;
	}
x86_l_193f:
	/* 0x193f: mov    r13d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16ULL);
x86_l_1945:
	/* 0x1945: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_1948:
	/* 0x1948: mov    eax,DWORD PTR [r12+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_194c:
	/* 0x194c: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1950:
	/* 0x1950: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1955:
	/* 0x1955: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_195a:
	/* 0x195a: mov    rdi,QWORD PTR [rip+0x1edc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1961:
	/* 0x1961: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1963:
	/* 0x1963: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1966:
	/* 0x1966: je     2d9b <generic_lsm_filter_arg+0x2d9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11675ULL;
	}
x86_l_196c:
	/* 0x196c: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1971:
	/* 0x1971: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1974:
	/* 0x1974: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1977:
	/* 0x1977: call   0 <generic_lsm_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 6524ULL);
	__x86_sim_call_depth++;
	return 14316ULL;
x86_l_197c:
	/* 0x197c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_197e:
	/* 0x197e: jns    2d9f <generic_lsm_filter_arg+0x2d9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11679ULL;
	}
x86_l_1984:
	/* 0x1984: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1988:
	/* 0x1988: lea    eax,[r13-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_198c:
	/* 0x198c: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1991:
	/* 0x1991: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1996:
	/* 0x1996: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_199b:
	/* 0x199b: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_199e:
	/* 0x199e: jae    2edb <generic_lsm_filter_arg+0x2edb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11995ULL;
	}
x86_l_19a4:
	/* 0x19a4: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_19a9:
	/* 0x19a9: cmp    r13,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 416ULL);
x86_l_19b0:
	/* 0x19b0: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19b5:
	/* 0x19b5: jne    1945 <generic_lsm_filter_arg+0x1945> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1945;
	}
x86_l_19b7:
	/* 0x19b7: jmp    3754 <generic_lsm_filter_arg+0x3754> */
	return 14164ULL;
x86_l_19bc:
	/* 0x19bc: mov    r13d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_32);
x86_l_19bf:
	/* 0x19bf: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19c4:
	/* 0x19c4: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_19c7:
	/* 0x19c7: jne    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_19cd:
	/* 0x19cd: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19d2:
	/* 0x19d2: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 6615ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6615ULL: goto x86_l_19d7;
	case 6619ULL: goto x86_l_19db;
	case 6630ULL: goto x86_l_19e6;
	case 6635ULL: goto x86_l_19eb;
	case 6640ULL: goto x86_l_19f0;
	case 6647ULL: goto x86_l_19f7;
	case 6649ULL: goto x86_l_19f9;
	case 6652ULL: goto x86_l_19fc;
	case 6658ULL: goto x86_l_1a02;
	case 6663ULL: goto x86_l_1a07;
	case 6666ULL: goto x86_l_1a0a;
	case 6672ULL: goto x86_l_1a10;
	case 6675ULL: goto x86_l_1a13;
	case 6680ULL: goto x86_l_1a18;
	case 6685ULL: goto x86_l_1a1d;
	case 6692ULL: goto x86_l_1a24;
	case 6694ULL: goto x86_l_1a26;
	case 6697ULL: goto x86_l_1a29;
	case 6703ULL: goto x86_l_1a2f;
	case 6705ULL: goto x86_l_1a31;
	case 6708ULL: goto x86_l_1a34;
	case 6710ULL: goto x86_l_1a36;
	case 6713ULL: goto x86_l_1a39;
	case 6717ULL: goto x86_l_1a3d;
	case 6720ULL: goto x86_l_1a40;
	case 6725ULL: goto x86_l_1a45;
	case 6730ULL: goto x86_l_1a4a;
	case 6732ULL: goto x86_l_1a4c;
	case 6734ULL: goto x86_l_1a4e;
	case 6739ULL: goto x86_l_1a53;
	case 6742ULL: goto x86_l_1a56;
	case 6745ULL: goto x86_l_1a59;
	case 6747ULL: goto x86_l_1a5b;
	case 6749ULL: goto x86_l_1a5d;
	case 6752ULL: goto x86_l_1a60;
	case 6755ULL: goto x86_l_1a63;
	case 6760ULL: goto x86_l_1a68;
	case 6763ULL: goto x86_l_1a6b;
	case 6766ULL: goto x86_l_1a6e;
	case 6769ULL: goto x86_l_1a71;
	case 6775ULL: goto x86_l_1a77;
	case 6782ULL: goto x86_l_1a7e;
	case 6787ULL: goto x86_l_1a83;
	case 6792ULL: goto x86_l_1a88;
	case 6799ULL: goto x86_l_1a8f;
	case 6801ULL: goto x86_l_1a91;
	case 6804ULL: goto x86_l_1a94;
	case 6810ULL: goto x86_l_1a9a;
	case 6813ULL: goto x86_l_1a9d;
	case 6818ULL: goto x86_l_1aa2;
	case 6823ULL: goto x86_l_1aa7;
	case 6828ULL: goto x86_l_1aac;
	case 6833ULL: goto x86_l_1ab1;
	case 6838ULL: goto x86_l_1ab6;
	case 6843ULL: goto x86_l_1abb;
	case 6847ULL: goto x86_l_1abf;
	case 6858ULL: goto x86_l_1aca;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6875ULL: goto x86_l_1adb;
	case 6877ULL: goto x86_l_1add;
	case 6879ULL: goto x86_l_1adf;
	case 6885ULL: goto x86_l_1ae5;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6896ULL: goto x86_l_1af0;
	case 6902ULL: goto x86_l_1af6;
	case 6907ULL: goto x86_l_1afb;
	case 6912ULL: goto x86_l_1b00;
	case 6919ULL: goto x86_l_1b07;
	case 6921ULL: goto x86_l_1b09;
	case 6924ULL: goto x86_l_1b0c;
	case 6930ULL: goto x86_l_1b12;
	case 6936ULL: goto x86_l_1b18;
	case 6941ULL: goto x86_l_1b1d;
	case 6944ULL: goto x86_l_1b20;
	case 6951ULL: goto x86_l_1b27;
	case 6953ULL: goto x86_l_1b29;
	case 6956ULL: goto x86_l_1b2c;
	case 6960ULL: goto x86_l_1b30;
	case 6963ULL: goto x86_l_1b33;
	case 6968ULL: goto x86_l_1b38;
	case 6973ULL: goto x86_l_1b3d;
	case 6975ULL: goto x86_l_1b3f;
	case 6977ULL: goto x86_l_1b41;
	case 6982ULL: goto x86_l_1b46;
	case 6985ULL: goto x86_l_1b49;
	case 6988ULL: goto x86_l_1b4c;
	case 6990ULL: goto x86_l_1b4e;
	case 6992ULL: goto x86_l_1b50;
	case 6995ULL: goto x86_l_1b53;
	case 6998ULL: goto x86_l_1b56;
	case 7003ULL: goto x86_l_1b5b;
	case 7014ULL: goto x86_l_1b66;
	case 7020ULL: goto x86_l_1b6c;
	case 7026ULL: goto x86_l_1b72;
	case 7029ULL: goto x86_l_1b75;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7044ULL: goto x86_l_1b84;
	case 7050ULL: goto x86_l_1b8a;
	case 7054ULL: goto x86_l_1b8e;
	case 7060ULL: goto x86_l_1b94;
	case 7063ULL: goto x86_l_1b97;
	case 7066ULL: goto x86_l_1b9a;
	case 7069ULL: goto x86_l_1b9d;
	case 7071ULL: goto x86_l_1b9f;
	case 7074ULL: goto x86_l_1ba2;
	case 7076ULL: goto x86_l_1ba4;
	case 7078ULL: goto x86_l_1ba6;
	case 7080ULL: goto x86_l_1ba8;
	case 7082ULL: goto x86_l_1baa;
	case 7084ULL: goto x86_l_1bac;
	case 7087ULL: goto x86_l_1baf;
	case 7089ULL: goto x86_l_1bb1;
	case 7091ULL: goto x86_l_1bb3;
	case 7093ULL: goto x86_l_1bb5;
	case 7096ULL: goto x86_l_1bb8;
	case 7099ULL: goto x86_l_1bbb;
	case 7103ULL: goto x86_l_1bbf;
	case 7109ULL: goto x86_l_1bc5;
	case 7111ULL: goto x86_l_1bc7;
	case 7114ULL: goto x86_l_1bca;
	case 7120ULL: goto x86_l_1bd0;
	case 7123ULL: goto x86_l_1bd3;
	case 7125ULL: goto x86_l_1bd5;
	case 7130ULL: goto x86_l_1bda;
	case 7134ULL: goto x86_l_1bde;
	case 7137ULL: goto x86_l_1be1;
	case 7139ULL: goto x86_l_1be3;
	case 7142ULL: goto x86_l_1be6;
	case 7148ULL: goto x86_l_1bec;
	case 7153ULL: goto x86_l_1bf1;
	case 7156ULL: goto x86_l_1bf4;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7172ULL: goto x86_l_1c04;
	case 7175ULL: goto x86_l_1c07;
	case 7177ULL: goto x86_l_1c09;
	case 7180ULL: goto x86_l_1c0c;
	case 7186ULL: goto x86_l_1c12;
	case 7189ULL: goto x86_l_1c15;
	case 7194ULL: goto x86_l_1c1a;
	case 7200ULL: goto x86_l_1c20;
	case 7203ULL: goto x86_l_1c23;
	case 7209ULL: goto x86_l_1c29;
	case 7214ULL: goto x86_l_1c2e;
	case 7218ULL: goto x86_l_1c32;
	case 7221ULL: goto x86_l_1c35;
	case 7225ULL: goto x86_l_1c39;
	case 7228ULL: goto x86_l_1c3c;
	case 7231ULL: goto x86_l_1c3f;
	case 7234ULL: goto x86_l_1c42;
	case 7239ULL: goto x86_l_1c47;
	case 7242ULL: goto x86_l_1c4a;
	case 7248ULL: goto x86_l_1c50;
	case 7253ULL: goto x86_l_1c55;
	case 7258ULL: goto x86_l_1c5a;
	case 7261ULL: goto x86_l_1c5d;
	case 7263ULL: goto x86_l_1c5f;
	case 7266ULL: goto x86_l_1c62;
	case 7272ULL: goto x86_l_1c68;
	case 7275ULL: goto x86_l_1c6b;
	case 7279ULL: goto x86_l_1c6f;
	case 7282ULL: goto x86_l_1c72;
	case 7286ULL: goto x86_l_1c76;
	case 7291ULL: goto x86_l_1c7b;
	case 7296ULL: goto x86_l_1c80;
	case 7299ULL: goto x86_l_1c83;
	case 7305ULL: goto x86_l_1c89;
	case 7309ULL: goto x86_l_1c8d;
	case 7314ULL: goto x86_l_1c92;
	case 7321ULL: goto x86_l_1c99;
	case 7326ULL: goto x86_l_1c9e;
	case 7328ULL: goto x86_l_1ca0;
	case 7331ULL: goto x86_l_1ca3;
	case 7337ULL: goto x86_l_1ca9;
	case 7340ULL: goto x86_l_1cac;
	case 7343ULL: goto x86_l_1caf;
	case 7351ULL: goto x86_l_1cb7;
	case 7356ULL: goto x86_l_1cbc;
	case 7361ULL: goto x86_l_1cc1;
	case 7363ULL: goto x86_l_1cc3;
	case 7368ULL: goto x86_l_1cc8;
	case 7370ULL: goto x86_l_1cca;
	case 7373ULL: goto x86_l_1ccd;
	case 7379ULL: goto x86_l_1cd3;
	case 7384ULL: goto x86_l_1cd8;
	case 7387ULL: goto x86_l_1cdb;
	case 7392ULL: goto x86_l_1ce0;
	case 7397ULL: goto x86_l_1ce5;
	case 7400ULL: goto x86_l_1ce8;
	case 7402ULL: goto x86_l_1cea;
	case 7405ULL: goto x86_l_1ced;
	case 7408ULL: goto x86_l_1cf0;
	case 7410ULL: goto x86_l_1cf2;
	case 7415ULL: goto x86_l_1cf7;
	case 7418ULL: goto x86_l_1cfa;
	case 7420ULL: goto x86_l_1cfc;
	case 7423ULL: goto x86_l_1cff;
	case 7426ULL: goto x86_l_1d02;
	case 7429ULL: goto x86_l_1d05;
	case 7434ULL: goto x86_l_1d0a;
	case 7436ULL: goto x86_l_1d0c;
	case 7441ULL: goto x86_l_1d11;
	case 7446ULL: goto x86_l_1d16;
	case 7449ULL: goto x86_l_1d19;
	case 7454ULL: goto x86_l_1d1e;
	case 7458ULL: goto x86_l_1d22;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7471ULL: goto x86_l_1d2f;
	case 7476ULL: goto x86_l_1d34;
	case 7480ULL: goto x86_l_1d38;
	case 7486ULL: goto x86_l_1d3e;
	case 7496ULL: goto x86_l_1d48;
	case 7500ULL: goto x86_l_1d4c;
	case 7505ULL: goto x86_l_1d51;
	case 7510ULL: goto x86_l_1d56;
	case 7515ULL: goto x86_l_1d5b;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7531ULL: goto x86_l_1d6b;
	case 7534ULL: goto x86_l_1d6e;
	case 7537ULL: goto x86_l_1d71;
	case 7542ULL: goto x86_l_1d76;
	case 7547ULL: goto x86_l_1d7b;
	case 7552ULL: goto x86_l_1d80;
	case 7554ULL: goto x86_l_1d82;
	case 7559ULL: goto x86_l_1d87;
	case 7564ULL: goto x86_l_1d8c;
	case 7566ULL: goto x86_l_1d8e;
	case 7571ULL: goto x86_l_1d93;
	case 7576ULL: goto x86_l_1d98;
	case 7578ULL: goto x86_l_1d9a;
	case 7580ULL: goto x86_l_1d9c;
	case 7585ULL: goto x86_l_1da1;
	case 7588ULL: goto x86_l_1da4;
	case 7591ULL: goto x86_l_1da7;
	case 7597ULL: goto x86_l_1dad;
	case 7603ULL: goto x86_l_1db3;
	case 7609ULL: goto x86_l_1db9;
	case 7612ULL: goto x86_l_1dbc;
	case 7618ULL: goto x86_l_1dc2;
	case 7620ULL: goto x86_l_1dc4;
	case 7626ULL: goto x86_l_1dca;
	case 7629ULL: goto x86_l_1dcd;
	case 7635ULL: goto x86_l_1dd3;
	case 7640ULL: goto x86_l_1dd8;
	case 7645ULL: goto x86_l_1ddd;
	case 7649ULL: goto x86_l_1de1;
	case 7655ULL: goto x86_l_1de7;
	case 7657ULL: goto x86_l_1de9;
	case 7661ULL: goto x86_l_1ded;
	case 7667ULL: goto x86_l_1df3;
	case 7672ULL: goto x86_l_1df8;
	case 7675ULL: goto x86_l_1dfb;
	case 7681ULL: goto x86_l_1e01;
	case 7686ULL: goto x86_l_1e06;
	case 7689ULL: goto x86_l_1e09;
	case 7691ULL: goto x86_l_1e0b;
	case 7694ULL: goto x86_l_1e0e;
	case 7697ULL: goto x86_l_1e11;
	case 7699ULL: goto x86_l_1e13;
	case 7703ULL: goto x86_l_1e17;
	case 7708ULL: goto x86_l_1e1c;
	case 7714ULL: goto x86_l_1e22;
	case 7719ULL: goto x86_l_1e27;
	case 7722ULL: goto x86_l_1e2a;
	case 7728ULL: goto x86_l_1e30;
	case 7731ULL: goto x86_l_1e33;
	case 7737ULL: goto x86_l_1e39;
	case 7740ULL: goto x86_l_1e3c;
	case 7742ULL: goto x86_l_1e3e;
	case 7745ULL: goto x86_l_1e41;
	case 7751ULL: goto x86_l_1e47;
	case 7755ULL: goto x86_l_1e4b;
	case 7761ULL: goto x86_l_1e51;
	case 7766ULL: goto x86_l_1e56;
	case 7769ULL: goto x86_l_1e59;
	case 7774ULL: goto x86_l_1e5e;
	case 7780ULL: goto x86_l_1e64;
	case 7784ULL: goto x86_l_1e68;
	case 7790ULL: goto x86_l_1e6e;
	case 7795ULL: goto x86_l_1e73;
	case 7798ULL: goto x86_l_1e76;
	case 7804ULL: goto x86_l_1e7c;
	case 7809ULL: goto x86_l_1e81;
	case 7811ULL: goto x86_l_1e83;
	case 7817ULL: goto x86_l_1e89;
	case 7822ULL: goto x86_l_1e8e;
	case 7825ULL: goto x86_l_1e91;
	case 7831ULL: goto x86_l_1e97;
	case 7836ULL: goto x86_l_1e9c;
	case 7838ULL: goto x86_l_1e9e;
	case 7844ULL: goto x86_l_1ea4;
	case 7849ULL: goto x86_l_1ea9;
	case 7852ULL: goto x86_l_1eac;
	case 7858ULL: goto x86_l_1eb2;
	case 7861ULL: goto x86_l_1eb5;
	case 7867ULL: goto x86_l_1ebb;
	case 7872ULL: goto x86_l_1ec0;
	case 7877ULL: goto x86_l_1ec5;
	case 7880ULL: goto x86_l_1ec8;
	case 7882ULL: goto x86_l_1eca;
	case 7885ULL: goto x86_l_1ecd;
	case 7891ULL: goto x86_l_1ed3;
	case 7895ULL: goto x86_l_1ed7;
	case 7901ULL: goto x86_l_1edd;
	case 7906ULL: goto x86_l_1ee2;
	case 7911ULL: goto x86_l_1ee7;
	case 7916ULL: goto x86_l_1eec;
	case 7918ULL: goto x86_l_1eee;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7933ULL: goto x86_l_1efd;
	case 7937ULL: goto x86_l_1f01;
	case 7942ULL: goto x86_l_1f06;
	case 7945ULL: goto x86_l_1f09;
	case 7948ULL: goto x86_l_1f0c;
	case 7951ULL: goto x86_l_1f0f;
	case 7957ULL: goto x86_l_1f15;
	case 7962ULL: goto x86_l_1f1a;
	case 7966ULL: goto x86_l_1f1e;
	case 7971ULL: goto x86_l_1f23;
	case 7975ULL: goto x86_l_1f27;
	case 7978ULL: goto x86_l_1f2a;
	case 7981ULL: goto x86_l_1f2d;
	case 7984ULL: goto x86_l_1f30;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 7999ULL: goto x86_l_1f3f;
	case 8004ULL: goto x86_l_1f44;
	case 8008ULL: goto x86_l_1f48;
	case 8011ULL: goto x86_l_1f4b;
	case 8014ULL: goto x86_l_1f4e;
	case 8017ULL: goto x86_l_1f51;
	case 8023ULL: goto x86_l_1f57;
	case 8028ULL: goto x86_l_1f5c;
	case 8031ULL: goto x86_l_1f5f;
	case 8036ULL: goto x86_l_1f64;
	case 8039ULL: goto x86_l_1f67;
	case 8041ULL: goto x86_l_1f69;
	case 8043ULL: goto x86_l_1f6b;
	case 8048ULL: goto x86_l_1f70;
	case 8051ULL: goto x86_l_1f73;
	case 8057ULL: goto x86_l_1f79;
	case 8060ULL: goto x86_l_1f7c;
	case 8066ULL: goto x86_l_1f82;
	case 8072ULL: goto x86_l_1f88;
	case 8077ULL: goto x86_l_1f8d;
	case 8080ULL: goto x86_l_1f90;
	case 8083ULL: goto x86_l_1f93;
	case 8088ULL: goto x86_l_1f98;
	case 8093ULL: goto x86_l_1f9d;
	case 8098ULL: goto x86_l_1fa2;
	case 8101ULL: goto x86_l_1fa5;
	case 8106ULL: goto x86_l_1faa;
	case 8111ULL: goto x86_l_1faf;
	case 8113ULL: goto x86_l_1fb1;
	case 8119ULL: goto x86_l_1fb7;
	case 8124ULL: goto x86_l_1fbc;
	case 8127ULL: goto x86_l_1fbf;
	case 8133ULL: goto x86_l_1fc5;
	case 8138ULL: goto x86_l_1fca;
	case 8141ULL: goto x86_l_1fcd;
	case 8147ULL: goto x86_l_1fd3;
	case 8150ULL: goto x86_l_1fd6;
	case 8153ULL: goto x86_l_1fd9;
	case 8159ULL: goto x86_l_1fdf;
	case 8164ULL: goto x86_l_1fe4;
	case 8166ULL: goto x86_l_1fe6;
	case 8172ULL: goto x86_l_1fec;
	case 8177ULL: goto x86_l_1ff1;
	case 8182ULL: goto x86_l_1ff6;
	case 8184ULL: goto x86_l_1ff8;
	case 8190ULL: goto x86_l_1ffe;
	case 8195ULL: goto x86_l_2003;
	case 8198ULL: goto x86_l_2006;
	case 8204ULL: goto x86_l_200c;
	case 8209ULL: goto x86_l_2011;
	case 8212ULL: goto x86_l_2014;
	case 8218ULL: goto x86_l_201a;
	case 8221ULL: goto x86_l_201d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_19d7:
	/* 0x19d7: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19db:
	/* 0x19db: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_19e6:
	/* 0x19e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19eb:
	/* 0x19eb: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19f0:
	/* 0x19f0: mov    rdi,QWORD PTR [rip+0x1edc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_19f7:
	/* 0x19f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f9:
	/* 0x19f9: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_19fc:
	/* 0x19fc: je     1d2d <generic_lsm_filter_arg+0x1d2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d2d;
	}
x86_l_1a02:
	/* 0x1a02: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1a07:
	/* 0x1a07: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a0a:
	/* 0x1a0a: je     1d2f <generic_lsm_filter_arg+0x1d2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d2f;
	}
x86_l_1a10:
	/* 0x1a10: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1a13:
	/* 0x1a13: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a18:
	/* 0x1a18: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a1d:
	/* 0x1a1d: mov    rdi,QWORD PTR [rip+0x1edc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1a24:
	/* 0x1a24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a26:
	/* 0x1a26: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a29:
	/* 0x1a29: je     1d2d <generic_lsm_filter_arg+0x1d2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d2d;
	}
x86_l_1a2f:
	/* 0x1a2f: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1a31:
	/* 0x1a31: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1a34:
	/* 0x1a34: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a36:
	/* 0x1a36: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1a39:
	/* 0x1a39: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a3d:
	/* 0x1a3d: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1a40:
	/* 0x1a40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a45:
	/* 0x1a45: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a4a:
	/* 0x1a4a: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1a4c:
	/* 0x1a4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4e:
	/* 0x1a4e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a53:
	/* 0x1a53: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1a56:
	/* 0x1a56: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1a59:
	/* 0x1a59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5b:
	/* 0x1a5b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a5d:
	/* 0x1a5d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a60:
	/* 0x1a60: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_1a63:
	/* 0x1a63: jmp    1d2f <generic_lsm_filter_arg+0x1d2f> */
	goto x86_l_1d2f;
x86_l_1a68:
	/* 0x1a68: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1a6b:
	/* 0x1a6b: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_1a6e:
	/* 0x1a6e: movzx  ebx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a71:
	/* 0x1a71: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1a77:
	/* 0x1a77: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a7e:
	/* 0x1a7e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a83:
	/* 0x1a83: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a88:
	/* 0x1a88: mov    rdi,QWORD PTR [rip+0x1edc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1a8f:
	/* 0x1a8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a91:
	/* 0x1a91: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a94:
	/* 0x1a94: je     2ba <generic_lsm_filter_arg+0x2ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 698ULL;
	}
x86_l_1a9a:
	/* 0x1a9a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1a9d:
	/* 0x1a9d: mov    QWORD PTR [rsp+0x40],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1aa7:
	/* 0x1aa7: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1aac:
	/* 0x1aac: jmp    1cc1 <generic_lsm_filter_arg+0x1cc1> */
	goto x86_l_1cc1;
x86_l_1ab1:
	/* 0x1ab1: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ab6:
	/* 0x1ab6: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1abb:
	/* 0x1abb: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1abf:
	/* 0x1abf: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1aca:
	/* 0x1aca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1acf:
	/* 0x1acf: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ad4:
	/* 0x1ad4: mov    rdi,QWORD PTR [rip+0x1edc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1adb:
	/* 0x1adb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1add:
	/* 0x1add: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1adf:
	/* 0x1adf: je     3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14147ULL;
	}
x86_l_1ae5:
	/* 0x1ae5: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1ae8:
	/* 0x1ae8: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1aed:
	/* 0x1aed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1af0:
	/* 0x1af0: je     3745 <generic_lsm_filter_arg+0x3745> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14149ULL;
	}
x86_l_1af6:
	/* 0x1af6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1afb:
	/* 0x1afb: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b00:
	/* 0x1b00: mov    rdi,QWORD PTR [rip+0x1edc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1b07:
	/* 0x1b07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b09:
	/* 0x1b09: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b0c:
	/* 0x1b0c: je     3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14147ULL;
	}
x86_l_1b12:
	/* 0x1b12: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_1b18:
	/* 0x1b18: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_1b1d:
	/* 0x1b1d: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_1b20:
	/* 0x1b20: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_1b27:
	/* 0x1b27: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b29:
	/* 0x1b29: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b2c:
	/* 0x1b2c: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1b30:
	/* 0x1b30: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1b33:
	/* 0x1b33: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b38:
	/* 0x1b38: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b3d:
	/* 0x1b3d: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1b3f:
	/* 0x1b3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b41:
	/* 0x1b41: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b46:
	/* 0x1b46: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1b49:
	/* 0x1b49: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1b4c:
	/* 0x1b4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b4e:
	/* 0x1b4e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b50:
	/* 0x1b50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b53:
	/* 0x1b53: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_1b56:
	/* 0x1b56: jmp    3745 <generic_lsm_filter_arg+0x3745> */
	return 14149ULL;
x86_l_1b5b:
	/* 0x1b5b: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1b66:
	/* 0x1b66: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_1b6c:
	/* 0x1b6c: ja     2b1e <generic_lsm_filter_arg+0x2b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11038ULL;
	}
x86_l_1b72:
	/* 0x1b72: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1b75:
	/* 0x1b75: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1b7a:
	/* 0x1b7a: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b7f:
	/* 0x1b7f: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b84:
	/* 0x1b84: ja     2853 <generic_lsm_filter_arg+0x2853> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10323ULL;
	}
x86_l_1b8a:
	/* 0x1b8a: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b8e:
	/* 0x1b8e: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1b94:
	/* 0x1b94: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1b97:
	/* 0x1b97: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1b9a:
	/* 0x1b9a: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1b9d:
	/* 0x1b9d: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1b9f:
	/* 0x1b9f: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1ba2:
	/* 0x1ba2: je     1bac <generic_lsm_filter_arg+0x1bac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bac;
	}
x86_l_1ba4:
	/* 0x1ba4: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1ba6:
	/* 0x1ba6: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1ba8:
	/* 0x1ba8: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1baa:
	/* 0x1baa: je     1bc7 <generic_lsm_filter_arg+0x1bc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bc7;
	}
x86_l_1bac:
	/* 0x1bac: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1baf:
	/* 0x1baf: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1bb1:
	/* 0x1bb1: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1bb3:
	/* 0x1bb3: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1bb5:
	/* 0x1bb5: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1bb8:
	/* 0x1bb8: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1bbb:
	/* 0x1bbb: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1bbf:
	/* 0x1bbf: ja     288a <generic_lsm_filter_arg+0x288a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10378ULL;
	}
x86_l_1bc5:
	/* 0x1bc5: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1bc7:
	/* 0x1bc7: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1bca:
	/* 0x1bca: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1bd0:
	/* 0x1bd0: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1bd3:
	/* 0x1bd3: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1bd5:
	/* 0x1bd5: jmp    313f <generic_lsm_filter_arg+0x313f> */
	return 12607ULL;
x86_l_1bda:
	/* 0x1bda: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bde:
	/* 0x1bde: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1be1:
	/* 0x1be1: ja     1bec <generic_lsm_filter_arg+0x1bec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bec;
	}
x86_l_1be3:
	/* 0x1be3: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1be6:
	/* 0x1be6: jbe    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 730ULL;
	}
x86_l_1bec:
	/* 0x1bec: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bf1:
	/* 0x1bf1: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1bf4:
	/* 0x1bf4: jb     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 279ULL;
	}
x86_l_1bfa:
	/* 0x1bfa: mov    rdi,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bff:
	/* 0x1bff: mov    rsi,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c04:
	/* 0x1c04: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c07:
	/* 0x1c07: je     1c12 <generic_lsm_filter_arg+0x1c12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c12;
	}
x86_l_1c09:
	/* 0x1c09: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1c0c:
	/* 0x1c0c: jne    2282 <generic_lsm_filter_arg+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8834ULL;
	}
x86_l_1c12:
	/* 0x1c12: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1c15:
	/* 0x1c15: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c1a:
	/* 0x1c1a: jg     2295 <generic_lsm_filter_arg+0x2295> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8853ULL;
	}
x86_l_1c20:
	/* 0x1c20: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_1c23:
	/* 0x1c23: jle    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 730ULL;
	}
x86_l_1c29:
	/* 0x1c29: jmp    2295 <generic_lsm_filter_arg+0x2295> */
	return 8853ULL;
x86_l_1c2e:
	/* 0x1c2e: mov    rdx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c32:
	/* 0x1c32: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1c35:
	/* 0x1c35: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1c39:
	/* 0x1c39: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1c3c:
	/* 0x1c3c: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1c3f:
	/* 0x1c3f: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1c42:
	/* 0x1c42: mov    esi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c47:
	/* 0x1c47: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_1c4a:
	/* 0x1c4a: jb     2fb9 <generic_lsm_filter_arg+0x2fb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12217ULL;
	}
x86_l_1c50:
	/* 0x1c50: mov    r8,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c55:
	/* 0x1c55: mov    rdi,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c5a:
	/* 0x1c5a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c5d:
	/* 0x1c5d: je     1c68 <generic_lsm_filter_arg+0x1c68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c68;
	}
x86_l_1c5f:
	/* 0x1c5f: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1c62:
	/* 0x1c62: jne    21c8 <generic_lsm_filter_arg+0x21c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8648ULL;
	}
x86_l_1c68:
	/* 0x1c68: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_1c6b:
	/* 0x1c6b: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1c6f:
	/* 0x1c6f: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1c72:
	/* 0x1c72: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1c76:
	/* 0x1c76: jmp    21d6 <generic_lsm_filter_arg+0x21d6> */
	return 8662ULL;
x86_l_1c7b:
	/* 0x1c7b: movzx  ebx,WORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1c80:
	/* 0x1c80: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_1c83:
	/* 0x1c83: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1c89:
	/* 0x1c89: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1c8d:
	/* 0x1c8d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c92:
	/* 0x1c92: mov    rdi,QWORD PTR [rip+0x1edc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1c99:
	/* 0x1c99: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1c9e:
	/* 0x1c9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca0:
	/* 0x1ca0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ca3:
	/* 0x1ca3: je     2ba <generic_lsm_filter_arg+0x2ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 698ULL;
	}
x86_l_1ca9:
	/* 0x1ca9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1cac:
	/* 0x1cac: movzx  eax,bx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1caf:
	/* 0x1caf: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1cb7:
	/* 0x1cb7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cbc:
	/* 0x1cbc: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cc1:
	/* 0x1cc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc3:
	/* 0x1cc3: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cc8:
	/* 0x1cc8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cca:
	/* 0x1cca: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1ccd:
	/* 0x1ccd: ja     22d2 <generic_lsm_filter_arg+0x22d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8914ULL;
	}
x86_l_1cd3:
	/* 0x1cd3: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1cd8:
	/* 0x1cd8: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1cdb:
	/* 0x1cdb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ce0:
	/* 0x1ce0: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ce5:
	/* 0x1ce5: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_1ce8:
	/* 0x1ce8: jae    1cf2 <generic_lsm_filter_arg+0x1cf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1cf2;
	}
x86_l_1cea:
	/* 0x1cea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ced:
	/* 0x1ced: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1cf0:
	/* 0x1cf0: jmp    1d02 <generic_lsm_filter_arg+0x1d02> */
	goto x86_l_1d02;
x86_l_1cf2:
	/* 0x1cf2: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1cf7:
	/* 0x1cf7: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1cfa:
	/* 0x1cfa: jae    1d02 <generic_lsm_filter_arg+0x1d02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d02;
	}
x86_l_1cfc:
	/* 0x1cfc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cff:
	/* 0x1cff: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1d02:
	/* 0x1d02: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1d05:
	/* 0x1d05: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_1d0a:
	/* 0x1d0a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d0c:
	/* 0x1d0c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d11:
	/* 0x1d11: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d16:
	/* 0x1d16: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_1d19:
	/* 0x1d19: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d1e:
	/* 0x1d1e: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_1d22:
	/* 0x1d22: jbe    33be <generic_lsm_filter_arg+0x33be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13246ULL;
	}
x86_l_1d28:
	/* 0x1d28: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_1d2d:
	/* 0x1d2d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d2f:
	/* 0x1d2f: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d34:
	/* 0x1d34: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_1d38:
	/* 0x1d38: ja     2c41 <generic_lsm_filter_arg+0x2c41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11329ULL;
	}
x86_l_1d3e:
	/* 0x1d3e: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_1d48:
	/* 0x1d48: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1d4c:
	/* 0x1d4c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d51:
	/* 0x1d51: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d56:
	/* 0x1d56: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d5b:
	/* 0x1d5b: jb     33d2 <generic_lsm_filter_arg+0x33d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13266ULL;
	}
x86_l_1d61:
	/* 0x1d61: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_1d66:
	/* 0x1d66: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d6b:
	/* 0x1d6b: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1d6e:
	/* 0x1d6e: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1d71:
	/* 0x1d71: jmp    1f90 <generic_lsm_filter_arg+0x1f90> */
	goto x86_l_1f90;
x86_l_1d76:
	/* 0x1d76: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1d7b:
	/* 0x1d7b: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1d80:
	/* 0x1d80: jb     1dad <generic_lsm_filter_arg+0x1dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1dad;
	}
x86_l_1d82:
	/* 0x1d82: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_1d87:
	/* 0x1d87: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_1d8c:
	/* 0x1d8c: jb     1dad <generic_lsm_filter_arg+0x1dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1dad;
	}
x86_l_1d8e:
	/* 0x1d8e: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_1d93:
	/* 0x1d93: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_1d98:
	/* 0x1d98: jb     1dad <generic_lsm_filter_arg+0x1dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1dad;
	}
x86_l_1d9a:
	/* 0x1d9a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d9c:
	/* 0x1d9c: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_1da1:
	/* 0x1da1: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_1da4:
	/* 0x1da4: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_1da7:
	/* 0x1da7: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_1dad:
	/* 0x1dad: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_1db3:
	/* 0x1db3: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_1db9:
	/* 0x1db9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1dbc:
	/* 0x1dbc: jg     20e8 <generic_lsm_filter_arg+0x20e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8424ULL;
	}
x86_l_1dc2:
	/* 0x1dc2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dc4:
	/* 0x1dc4: je     2a47 <generic_lsm_filter_arg+0x2a47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10823ULL;
	}
x86_l_1dca:
	/* 0x1dca: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dcd:
	/* 0x1dcd: jne    2a40 <generic_lsm_filter_arg+0x2a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10816ULL;
	}
x86_l_1dd3:
	/* 0x1dd3: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1dd8:
	/* 0x1dd8: jmp    2a53 <generic_lsm_filter_arg+0x2a53> */
	return 10835ULL;
x86_l_1ddd:
	/* 0x1ddd: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1de1:
	/* 0x1de1: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_1de7:
	/* 0x1de7: jmp    1df3 <generic_lsm_filter_arg+0x1df3> */
	goto x86_l_1df3;
x86_l_1de9:
	/* 0x1de9: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ded:
	/* 0x1ded: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_1df3:
	/* 0x1df3: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df8:
	/* 0x1df8: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1dfb:
	/* 0x1dfb: jb     37db <generic_lsm_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14299ULL;
	}
x86_l_1e01:
	/* 0x1e01: mov    rsi,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e06:
	/* 0x1e06: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e09:
	/* 0x1e09: jle    1e27 <generic_lsm_filter_arg+0x1e27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e27;
	}
x86_l_1e0b:
	/* 0x1e0b: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1e0e:
	/* 0x1e0e: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1e11:
	/* 0x1e11: jae    1e56 <generic_lsm_filter_arg+0x1e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1e56;
	}
x86_l_1e13:
	/* 0x1e13: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e17:
	/* 0x1e17: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e1c:
	/* 0x1e1c: jne    295e <generic_lsm_filter_arg+0x295e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10590ULL;
	}
x86_l_1e22:
	/* 0x1e22: jmp    367c <generic_lsm_filter_arg+0x367c> */
	return 13948ULL;
x86_l_1e27:
	/* 0x1e27: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e2a:
	/* 0x1e2a: je     1ec5 <generic_lsm_filter_arg+0x1ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ec5;
	}
x86_l_1e30:
	/* 0x1e30: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e33:
	/* 0x1e33: jne    295e <generic_lsm_filter_arg+0x295e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10590ULL;
	}
x86_l_1e39:
	/* 0x1e39: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1e3c:
	/* 0x1e3c: je     1e47 <generic_lsm_filter_arg+0x1e47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e47;
	}
x86_l_1e3e:
	/* 0x1e3e: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1e41:
	/* 0x1e41: jne    2954 <generic_lsm_filter_arg+0x2954> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10580ULL;
	}
x86_l_1e47:
	/* 0x1e47: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e4b:
	/* 0x1e4b: jl     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 730ULL;
	}
x86_l_1e51:
	/* 0x1e51: jmp    295e <generic_lsm_filter_arg+0x295e> */
	return 10590ULL;
x86_l_1e56:
	/* 0x1e56: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1e59:
	/* 0x1e59: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e5e:
	/* 0x1e5e: jne    295e <generic_lsm_filter_arg+0x295e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10590ULL;
	}
x86_l_1e64:
	/* 0x1e64: test   QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e68:
	/* 0x1e68: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_1e6e:
	/* 0x1e6e: jmp    295e <generic_lsm_filter_arg+0x295e> */
	return 10590ULL;
x86_l_1e73:
	/* 0x1e73: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1e76:
	/* 0x1e76: jne    1fb7 <generic_lsm_filter_arg+0x1fb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fb7;
	}
x86_l_1e7c:
	/* 0x1e7c: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e81:
	/* 0x1e81: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1e83:
	/* 0x1e83: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_1e89:
	/* 0x1e89: jmp    1fb7 <generic_lsm_filter_arg+0x1fb7> */
	goto x86_l_1fb7;
x86_l_1e8e:
	/* 0x1e8e: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1e91:
	/* 0x1e91: jne    1ffe <generic_lsm_filter_arg+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ffe;
	}
x86_l_1e97:
	/* 0x1e97: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e9c:
	/* 0x1e9c: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1e9e:
	/* 0x1e9e: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_1ea4:
	/* 0x1ea4: jmp    1ffe <generic_lsm_filter_arg+0x1ffe> */
	goto x86_l_1ffe;
x86_l_1ea9:
	/* 0x1ea9: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1eac:
	/* 0x1eac: je     240e <generic_lsm_filter_arg+0x240e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9230ULL;
	}
x86_l_1eb2:
	/* 0x1eb2: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1eb5:
	/* 0x1eb5: jne    2400 <generic_lsm_filter_arg+0x2400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9216ULL;
	}
x86_l_1ebb:
	/* 0x1ebb: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_1ec0:
	/* 0x1ec0: jmp    2413 <generic_lsm_filter_arg+0x2413> */
	return 9235ULL;
x86_l_1ec5:
	/* 0x1ec5: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1ec8:
	/* 0x1ec8: je     1ed3 <generic_lsm_filter_arg+0x1ed3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ed3;
	}
x86_l_1eca:
	/* 0x1eca: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1ecd:
	/* 0x1ecd: jne    2948 <generic_lsm_filter_arg+0x2948> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10568ULL;
	}
x86_l_1ed3:
	/* 0x1ed3: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ed7:
	/* 0x1ed7: jg     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 730ULL;
	}
x86_l_1edd:
	/* 0x1edd: jmp    295e <generic_lsm_filter_arg+0x295e> */
	return 10590ULL;
x86_l_1ee2:
	/* 0x1ee2: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ee7:
	/* 0x1ee7: movzx  ecx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1eec:
	/* 0x1eec: jmp    1ef8 <generic_lsm_filter_arg+0x1ef8> */
	goto x86_l_1ef8;
x86_l_1eee:
	/* 0x1eee: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ef3:
	/* 0x1ef3: movzx  ecx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ef8:
	/* 0x1ef8: cmp    DWORD PTR [r12+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1efd:
	/* 0x1efd: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1f01:
	/* 0x1f01: cmp    DWORD PTR [r12+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1f06:
	/* 0x1f06: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_1f09:
	/* 0x1f09: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f0c:
	/* 0x1f0c: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1f0f:
	/* 0x1f0f: jb     2fb9 <generic_lsm_filter_arg+0x2fb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12217ULL;
	}
x86_l_1f15:
	/* 0x1f15: cmp    DWORD PTR [r12+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f1a:
	/* 0x1f1a: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1f1e:
	/* 0x1f1e: cmp    DWORD PTR [r12+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f23:
	/* 0x1f23: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1f27:
	/* 0x1f27: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f2a:
	/* 0x1f2a: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f2d:
	/* 0x1f2d: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1f30:
	/* 0x1f30: jb     2fb4 <generic_lsm_filter_arg+0x2fb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12212ULL;
	}
x86_l_1f36:
	/* 0x1f36: cmp    DWORD PTR [r12+0x20],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f3b:
	/* 0x1f3b: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1f3f:
	/* 0x1f3f: cmp    DWORD PTR [r12+0x24],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f44:
	/* 0x1f44: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1f48:
	/* 0x1f48: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f4b:
	/* 0x1f4b: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f4e:
	/* 0x1f4e: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1f51:
	/* 0x1f51: jb     2fb4 <generic_lsm_filter_arg+0x2fb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12212ULL;
	}
x86_l_1f57:
	/* 0x1f57: cmp    DWORD PTR [r12+0x28],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f5c:
	/* 0x1f5c: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_1f5f:
	/* 0x1f5f: cmp    DWORD PTR [r12+0x2c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1f64:
	/* 0x1f64: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_1f67:
	/* 0x1f67: and    cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f69:
	/* 0x1f69: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f6b:
	/* 0x1f6b: jmp    2fb4 <generic_lsm_filter_arg+0x2fb4> */
	return 12212ULL;
x86_l_1f70:
	/* 0x1f70: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1f73:
	/* 0x1f73: je     263a <generic_lsm_filter_arg+0x263a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9786ULL;
	}
x86_l_1f79:
	/* 0x1f79: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1f7c:
	/* 0x1f7c: jne    262a <generic_lsm_filter_arg+0x262a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9770ULL;
	}
x86_l_1f82:
	/* 0x1f82: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_1f88:
	/* 0x1f88: jmp    2640 <generic_lsm_filter_arg+0x2640> */
	return 9792ULL;
x86_l_1f8d:
	/* 0x1f8d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f90:
	/* 0x1f90: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1f93:
	/* 0x1f93: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f98:
	/* 0x1f98: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f9d:
	/* 0x1f9d: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fa2:
	/* 0x1fa2: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1fa5:
	/* 0x1fa5: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_1faa:
	/* 0x1faa: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1faf:
	/* 0x1faf: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1fb1:
	/* 0x1fb1: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_1fb7:
	/* 0x1fb7: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fbc:
	/* 0x1fbc: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1fbf:
	/* 0x1fbf: jb     37db <generic_lsm_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14299ULL;
	}
x86_l_1fc5:
	/* 0x1fc5: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1fca:
	/* 0x1fca: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1fcd:
	/* 0x1fcd: jle    23a9 <generic_lsm_filter_arg+0x23a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9129ULL;
	}
x86_l_1fd3:
	/* 0x1fd3: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1fd6:
	/* 0x1fd6: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1fd9:
	/* 0x1fd9: jae    29d9 <generic_lsm_filter_arg+0x29d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10713ULL;
	}
x86_l_1fdf:
	/* 0x1fdf: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1fe4:
	/* 0x1fe4: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1fe6:
	/* 0x1fe6: jne    2c7e <generic_lsm_filter_arg+0x2c7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11390ULL;
	}
x86_l_1fec:
	/* 0x1fec: jmp    367c <generic_lsm_filter_arg+0x367c> */
	return 13948ULL;
x86_l_1ff1:
	/* 0x1ff1: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ff6:
	/* 0x1ff6: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1ff8:
	/* 0x1ff8: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_1ffe:
	/* 0x1ffe: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2003:
	/* 0x2003: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_2006:
	/* 0x2006: jb     37db <generic_lsm_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14299ULL;
	}
x86_l_200c:
	/* 0x200c: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2011:
	/* 0x2011: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2014:
	/* 0x2014: jle    23cd <generic_lsm_filter_arg+0x23cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9165ULL;
	}
x86_l_201a:
	/* 0x201a: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_201d:
	/* 0x201d: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
	return 8224ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8224ULL: goto x86_l_2020;
	case 8230ULL: goto x86_l_2026;
	case 8235ULL: goto x86_l_202b;
	case 8237ULL: goto x86_l_202d;
	case 8243ULL: goto x86_l_2033;
	case 8248ULL: goto x86_l_2038;
	case 8252ULL: goto x86_l_203c;
	case 8254ULL: goto x86_l_203e;
	case 8256ULL: goto x86_l_2040;
	case 8258ULL: goto x86_l_2042;
	case 8264ULL: goto x86_l_2048;
	case 8269ULL: goto x86_l_204d;
	case 8272ULL: goto x86_l_2050;
	case 8278ULL: goto x86_l_2056;
	case 8283ULL: goto x86_l_205b;
	case 8288ULL: goto x86_l_2060;
	case 8291ULL: goto x86_l_2063;
	case 8297ULL: goto x86_l_2069;
	case 8303ULL: goto x86_l_206f;
	case 8307ULL: goto x86_l_2073;
	case 8313ULL: goto x86_l_2079;
	case 8315ULL: goto x86_l_207b;
	case 8320ULL: goto x86_l_2080;
	case 8326ULL: goto x86_l_2086;
	case 8328ULL: goto x86_l_2088;
	case 8334ULL: goto x86_l_208e;
	case 8339ULL: goto x86_l_2093;
	case 8343ULL: goto x86_l_2097;
	case 8345ULL: goto x86_l_2099;
	case 8349ULL: goto x86_l_209d;
	case 8351ULL: goto x86_l_209f;
	case 8354ULL: goto x86_l_20a2;
	case 8357ULL: goto x86_l_20a5;
	case 8362ULL: goto x86_l_20aa;
	case 8365ULL: goto x86_l_20ad;
	case 8371ULL: goto x86_l_20b3;
	case 8376ULL: goto x86_l_20b8;
	case 8381ULL: goto x86_l_20bd;
	case 8384ULL: goto x86_l_20c0;
	case 8390ULL: goto x86_l_20c6;
	case 8396ULL: goto x86_l_20cc;
	case 8400ULL: goto x86_l_20d0;
	case 8406ULL: goto x86_l_20d6;
	case 8409ULL: goto x86_l_20d9;
	case 8413ULL: goto x86_l_20dd;
	case 8415ULL: goto x86_l_20df;
	case 8419ULL: goto x86_l_20e3;
	case 8424ULL: goto x86_l_20e8;
	case 8427ULL: goto x86_l_20eb;
	case 8433ULL: goto x86_l_20f1;
	case 8436ULL: goto x86_l_20f4;
	case 8442ULL: goto x86_l_20fa;
	case 8447ULL: goto x86_l_20ff;
	case 8452ULL: goto x86_l_2104;
	case 8454ULL: goto x86_l_2106;
	case 8457ULL: goto x86_l_2109;
	case 8460ULL: goto x86_l_210c;
	case 8465ULL: goto x86_l_2111;
	case 8469ULL: goto x86_l_2115;
	case 8474ULL: goto x86_l_211a;
	case 8479ULL: goto x86_l_211f;
	case 8486ULL: goto x86_l_2126;
	case 8488ULL: goto x86_l_2128;
	case 8491ULL: goto x86_l_212b;
	case 8497ULL: goto x86_l_2131;
	case 8499ULL: goto x86_l_2133;
	case 8504ULL: goto x86_l_2138;
	case 8507ULL: goto x86_l_213b;
	case 8512ULL: goto x86_l_2140;
	case 8514ULL: goto x86_l_2142;
	case 8519ULL: goto x86_l_2147;
	case 8521ULL: goto x86_l_2149;
	case 8523ULL: goto x86_l_214b;
	case 8526ULL: goto x86_l_214e;
	case 8529ULL: goto x86_l_2151;
	case 8532ULL: goto x86_l_2154;
	case 8534ULL: goto x86_l_2156;
	case 8536ULL: goto x86_l_2158;
	case 8540ULL: goto x86_l_215c;
	case 8543ULL: goto x86_l_215f;
	case 8545ULL: goto x86_l_2161;
	case 8549ULL: goto x86_l_2165;
	case 8552ULL: goto x86_l_2168;
	case 8554ULL: goto x86_l_216a;
	case 8558ULL: goto x86_l_216e;
	case 8560ULL: goto x86_l_2170;
	case 8564ULL: goto x86_l_2174;
	case 8568ULL: goto x86_l_2178;
	case 8571ULL: goto x86_l_217b;
	case 8573ULL: goto x86_l_217d;
	case 8575ULL: goto x86_l_217f;
	case 8577ULL: goto x86_l_2181;
	case 8583ULL: goto x86_l_2187;
	case 8587ULL: goto x86_l_218b;
	case 8592ULL: goto x86_l_2190;
	case 8594ULL: goto x86_l_2192;
	case 8598ULL: goto x86_l_2196;
	case 8601ULL: goto x86_l_2199;
	case 8605ULL: goto x86_l_219d;
	case 8611ULL: goto x86_l_21a3;
	case 8613ULL: goto x86_l_21a5;
	case 8618ULL: goto x86_l_21aa;
	case 8623ULL: goto x86_l_21af;
	case 8625ULL: goto x86_l_21b1;
	case 8630ULL: goto x86_l_21b6;
	case 8633ULL: goto x86_l_21b9;
	case 8638ULL: goto x86_l_21be;
	case 8643ULL: goto x86_l_21c3;
	case 8648ULL: goto x86_l_21c8;
	case 8651ULL: goto x86_l_21cb;
	case 8655ULL: goto x86_l_21cf;
	case 8658ULL: goto x86_l_21d2;
	case 8662ULL: goto x86_l_21d6;
	case 8665ULL: goto x86_l_21d9;
	case 8668ULL: goto x86_l_21dc;
	case 8671ULL: goto x86_l_21df;
	case 8677ULL: goto x86_l_21e5;
	case 8682ULL: goto x86_l_21ea;
	case 8687ULL: goto x86_l_21ef;
	case 8690ULL: goto x86_l_21f2;
	case 8692ULL: goto x86_l_21f4;
	case 8695ULL: goto x86_l_21f7;
	case 8701ULL: goto x86_l_21fd;
	case 8704ULL: goto x86_l_2200;
	case 8708ULL: goto x86_l_2204;
	case 8711ULL: goto x86_l_2207;
	case 8715ULL: goto x86_l_220b;
	case 8720ULL: goto x86_l_2210;
	case 8722ULL: goto x86_l_2212;
	case 8725ULL: goto x86_l_2215;
	case 8727ULL: goto x86_l_2217;
	case 8730ULL: goto x86_l_221a;
	case 8732ULL: goto x86_l_221c;
	case 8736ULL: goto x86_l_2220;
	case 8739ULL: goto x86_l_2223;
	case 8741ULL: goto x86_l_2225;
	case 8744ULL: goto x86_l_2228;
	case 8750ULL: goto x86_l_222e;
	case 8753ULL: goto x86_l_2231;
	case 8759ULL: goto x86_l_2237;
	case 8763ULL: goto x86_l_223b;
	case 8768ULL: goto x86_l_2240;
	case 8775ULL: goto x86_l_2247;
	case 8780ULL: goto x86_l_224c;
	case 8782ULL: goto x86_l_224e;
	case 8785ULL: goto x86_l_2251;
	case 8791ULL: goto x86_l_2257;
	case 8794ULL: goto x86_l_225a;
	case 8796ULL: goto x86_l_225c;
	case 8804ULL: goto x86_l_2264;
	case 8809ULL: goto x86_l_2269;
	case 8814ULL: goto x86_l_226e;
	case 8819ULL: goto x86_l_2273;
	case 8821ULL: goto x86_l_2275;
	case 8824ULL: goto x86_l_2278;
	case 8829ULL: goto x86_l_227d;
	case 8834ULL: goto x86_l_2282;
	case 8837ULL: goto x86_l_2285;
	case 8842ULL: goto x86_l_228a;
	case 8844ULL: goto x86_l_228c;
	case 8847ULL: goto x86_l_228f;
	case 8853ULL: goto x86_l_2295;
	case 8856ULL: goto x86_l_2298;
	case 8862ULL: goto x86_l_229e;
	case 8867ULL: goto x86_l_22a3;
	case 8872ULL: goto x86_l_22a8;
	case 8875ULL: goto x86_l_22ab;
	case 8877ULL: goto x86_l_22ad;
	case 8880ULL: goto x86_l_22b0;
	case 8886ULL: goto x86_l_22b6;
	case 8889ULL: goto x86_l_22b9;
	case 8894ULL: goto x86_l_22be;
	case 8900ULL: goto x86_l_22c4;
	case 8903ULL: goto x86_l_22c7;
	case 8909ULL: goto x86_l_22cd;
	case 8914ULL: goto x86_l_22d2;
	case 8919ULL: goto x86_l_22d7;
	case 8924ULL: goto x86_l_22dc;
	case 8927ULL: goto x86_l_22df;
	case 8932ULL: goto x86_l_22e4;
	case 8936ULL: goto x86_l_22e8;
	case 8942ULL: goto x86_l_22ee;
	case 8944ULL: goto x86_l_22f0;
	case 8948ULL: goto x86_l_22f4;
	case 8954ULL: goto x86_l_22fa;
	case 8959ULL: goto x86_l_22ff;
	case 8962ULL: goto x86_l_2302;
	case 8968ULL: goto x86_l_2308;
	case 8973ULL: goto x86_l_230d;
	case 8976ULL: goto x86_l_2310;
	case 8978ULL: goto x86_l_2312;
	case 8981ULL: goto x86_l_2315;
	case 8984ULL: goto x86_l_2318;
	case 8986ULL: goto x86_l_231a;
	case 8990ULL: goto x86_l_231e;
	case 8995ULL: goto x86_l_2323;
	case 9001ULL: goto x86_l_2329;
	case 9006ULL: goto x86_l_232e;
	case 9009ULL: goto x86_l_2331;
	case 9011ULL: goto x86_l_2333;
	case 9014ULL: goto x86_l_2336;
	case 9020ULL: goto x86_l_233c;
	case 9023ULL: goto x86_l_233f;
	case 9029ULL: goto x86_l_2345;
	case 9035ULL: goto x86_l_234b;
	case 9039ULL: goto x86_l_234f;
	case 9045ULL: goto x86_l_2355;
	case 9049ULL: goto x86_l_2359;
	case 9055ULL: goto x86_l_235f;
	case 9060ULL: goto x86_l_2364;
	case 9063ULL: goto x86_l_2367;
	case 9068ULL: goto x86_l_236c;
	case 9074ULL: goto x86_l_2372;
	case 9078ULL: goto x86_l_2376;
	case 9084ULL: goto x86_l_237c;
	case 9089ULL: goto x86_l_2381;
	case 9092ULL: goto x86_l_2384;
	case 9098ULL: goto x86_l_238a;
	case 9104ULL: goto x86_l_2390;
	case 9108ULL: goto x86_l_2394;
	case 9114ULL: goto x86_l_239a;
	case 9118ULL: goto x86_l_239e;
	case 9124ULL: goto x86_l_23a4;
	case 9129ULL: goto x86_l_23a9;
	case 9132ULL: goto x86_l_23ac;
	case 9138ULL: goto x86_l_23b2;
	case 9141ULL: goto x86_l_23b5;
	case 9147ULL: goto x86_l_23bb;
	case 9152ULL: goto x86_l_23c0;
	case 9154ULL: goto x86_l_23c2;
	case 9160ULL: goto x86_l_23c8;
	case 9165ULL: goto x86_l_23cd;
	case 9168ULL: goto x86_l_23d0;
	case 9174ULL: goto x86_l_23d6;
	case 9177ULL: goto x86_l_23d9;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9190ULL: goto x86_l_23e6;
	case 9196ULL: goto x86_l_23ec;
	case 9201ULL: goto x86_l_23f1;
	case 9206ULL: goto x86_l_23f6;
	case 9211ULL: goto x86_l_23fb;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9223ULL: goto x86_l_2407;
	case 9228ULL: goto x86_l_240c;
	case 9230ULL: goto x86_l_240e;
	case 9235ULL: goto x86_l_2413;
	case 9237ULL: goto x86_l_2415;
	case 9240ULL: goto x86_l_2418;
	case 9245ULL: goto x86_l_241d;
	case 9248ULL: goto x86_l_2420;
	case 9254ULL: goto x86_l_2426;
	case 9258ULL: goto x86_l_242a;
	case 9265ULL: goto x86_l_2431;
	case 9270ULL: goto x86_l_2436;
	case 9275ULL: goto x86_l_243b;
	case 9282ULL: goto x86_l_2442;
	case 9287ULL: goto x86_l_2447;
	case 9290ULL: goto x86_l_244a;
	case 9292ULL: goto x86_l_244c;
	case 9295ULL: goto x86_l_244f;
	case 9300ULL: goto x86_l_2454;
	case 9307ULL: goto x86_l_245b;
	case 9310ULL: goto x86_l_245e;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9320ULL: goto x86_l_2468;
	case 9326ULL: goto x86_l_246e;
	case 9331ULL: goto x86_l_2473;
	case 9334ULL: goto x86_l_2476;
	case 9339ULL: goto x86_l_247b;
	case 9344ULL: goto x86_l_2480;
	case 9349ULL: goto x86_l_2485;
	case 9355ULL: goto x86_l_248b;
	case 9363ULL: goto x86_l_2493;
	case 9368ULL: goto x86_l_2498;
	case 9372ULL: goto x86_l_249c;
	case 9379ULL: goto x86_l_24a3;
	case 9382ULL: goto x86_l_24a6;
	case 9384ULL: goto x86_l_24a8;
	case 9389ULL: goto x86_l_24ad;
	case 9392ULL: goto x86_l_24b0;
	case 9396ULL: goto x86_l_24b4;
	case 9401ULL: goto x86_l_24b9;
	case 9403ULL: goto x86_l_24bb;
	case 9405ULL: goto x86_l_24bd;
	case 9410ULL: goto x86_l_24c2;
	case 9412ULL: goto x86_l_24c4;
	case 9417ULL: goto x86_l_24c9;
	case 9419ULL: goto x86_l_24cb;
	case 9424ULL: goto x86_l_24d0;
	case 9428ULL: goto x86_l_24d4;
	case 9431ULL: goto x86_l_24d7;
	case 9437ULL: goto x86_l_24dd;
	case 9442ULL: goto x86_l_24e2;
	case 9450ULL: goto x86_l_24ea;
	case 9452ULL: goto x86_l_24ec;
	case 9457ULL: goto x86_l_24f1;
	case 9460ULL: goto x86_l_24f4;
	case 9464ULL: goto x86_l_24f8;
	case 9469ULL: goto x86_l_24fd;
	case 9471ULL: goto x86_l_24ff;
	case 9473ULL: goto x86_l_2501;
	case 9478ULL: goto x86_l_2506;
	case 9480ULL: goto x86_l_2508;
	case 9485ULL: goto x86_l_250d;
	case 9487ULL: goto x86_l_250f;
	case 9492ULL: goto x86_l_2514;
	case 9496ULL: goto x86_l_2518;
	case 9500ULL: goto x86_l_251c;
	case 9506ULL: goto x86_l_2522;
	case 9511ULL: goto x86_l_2527;
	case 9519ULL: goto x86_l_252f;
	case 9521ULL: goto x86_l_2531;
	case 9526ULL: goto x86_l_2536;
	case 9529ULL: goto x86_l_2539;
	case 9534ULL: goto x86_l_253e;
	case 9539ULL: goto x86_l_2543;
	case 9544ULL: goto x86_l_2548;
	case 9546ULL: goto x86_l_254a;
	case 9549ULL: goto x86_l_254d;
	case 9555ULL: goto x86_l_2553;
	case 9558ULL: goto x86_l_2556;
	case 9564ULL: goto x86_l_255c;
	case 9567ULL: goto x86_l_255f;
	case 9573ULL: goto x86_l_2565;
	case 9576ULL: goto x86_l_2568;
	case 9582ULL: goto x86_l_256e;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9599ULL: goto x86_l_257f;
	case 9604ULL: goto x86_l_2584;
	case 9607ULL: goto x86_l_2587;
	case 9613ULL: goto x86_l_258d;
	case 9616ULL: goto x86_l_2590;
	case 9622ULL: goto x86_l_2596;
	case 9625ULL: goto x86_l_2599;
	case 9631ULL: goto x86_l_259f;
	case 9634ULL: goto x86_l_25a2;
	case 9640ULL: goto x86_l_25a8;
	case 9645ULL: goto x86_l_25ad;
	case 9650ULL: goto x86_l_25b2;
	case 9657ULL: goto x86_l_25b9;
	case 9662ULL: goto x86_l_25be;
	case 9667ULL: goto x86_l_25c3;
	case 9672ULL: goto x86_l_25c8;
	case 9677ULL: goto x86_l_25cd;
	case 9682ULL: goto x86_l_25d2;
	case 9685ULL: goto x86_l_25d5;
	case 9689ULL: goto x86_l_25d9;
	case 9691ULL: goto x86_l_25db;
	case 9695ULL: goto x86_l_25df;
	case 9698ULL: goto x86_l_25e2;
	case 9701ULL: goto x86_l_25e5;
	case 9704ULL: goto x86_l_25e8;
	case 9710ULL: goto x86_l_25ee;
	case 9715ULL: goto x86_l_25f3;
	case 9720ULL: goto x86_l_25f8;
	case 9723ULL: goto x86_l_25fb;
	case 9729ULL: goto x86_l_2601;
	case 9735ULL: goto x86_l_2607;
	case 9739ULL: goto x86_l_260b;
	case 9745ULL: goto x86_l_2611;
	case 9748ULL: goto x86_l_2614;
	case 9752ULL: goto x86_l_2618;
	case 9754ULL: goto x86_l_261a;
	case 9758ULL: goto x86_l_261e;
	case 9763ULL: goto x86_l_2623;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9776ULL: goto x86_l_2630;
	case 9778ULL: goto x86_l_2632;
	case 9784ULL: goto x86_l_2638;
	case 9786ULL: goto x86_l_263a;
	case 9792ULL: goto x86_l_2640;
	case 9795ULL: goto x86_l_2643;
	case 9798ULL: goto x86_l_2646;
	case 9803ULL: goto x86_l_264b;
	case 9806ULL: goto x86_l_264e;
	case 9812ULL: goto x86_l_2654;
	case 9816ULL: goto x86_l_2658;
	case 9821ULL: goto x86_l_265d;
	case 9829ULL: goto x86_l_2665;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2020:
	/* 0x2020: jae    29f4 <generic_lsm_filter_arg+0x29f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10740ULL;
	}
x86_l_2026:
	/* 0x2026: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_202b:
	/* 0x202b: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_202d:
	/* 0x202d: jne    2cc0 <generic_lsm_filter_arg+0x2cc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11456ULL;
	}
x86_l_2033:
	/* 0x2033: jmp    367c <generic_lsm_filter_arg+0x367c> */
	return 13948ULL;
x86_l_2038:
	/* 0x2038: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_203c:
	/* 0x203c: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_203e:
	/* 0x203e: ja     2048 <generic_lsm_filter_arg+0x2048> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2048;
	}
x86_l_2040:
	/* 0x2040: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2042:
	/* 0x2042: jbe    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 730ULL;
	}
x86_l_2048:
	/* 0x2048: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_204d:
	/* 0x204d: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2050:
	/* 0x2050: jb     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 279ULL;
	}
x86_l_2056:
	/* 0x2056: mov    edi,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_205b:
	/* 0x205b: mov    esi,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2060:
	/* 0x2060: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2063:
	/* 0x2063: ja     27fc <generic_lsm_filter_arg+0x27fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10236ULL;
	}
x86_l_2069:
	/* 0x2069: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_206f:
	/* 0x206f: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2073:
	/* 0x2073: jae    27fc <generic_lsm_filter_arg+0x27fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10236ULL;
	}
x86_l_2079:
	/* 0x2079: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_207b:
	/* 0x207b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2080:
	/* 0x2080: jg     280d <generic_lsm_filter_arg+0x280d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10253ULL;
	}
x86_l_2086:
	/* 0x2086: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_2088:
	/* 0x2088: jle    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 730ULL;
	}
x86_l_208e:
	/* 0x208e: jmp    280d <generic_lsm_filter_arg+0x280d> */
	return 10253ULL;
x86_l_2093:
	/* 0x2093: mov    edx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2097:
	/* 0x2097: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2099:
	/* 0x2099: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_209d:
	/* 0x209d: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_209f:
	/* 0x209f: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_20a2:
	/* 0x20a2: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_20a5:
	/* 0x20a5: mov    esi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20aa:
	/* 0x20aa: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_20ad:
	/* 0x20ad: jb     2fb9 <generic_lsm_filter_arg+0x2fb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12217ULL;
	}
x86_l_20b3:
	/* 0x20b3: mov    r8d,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20b8:
	/* 0x20b8: mov    edi,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20bd:
	/* 0x20bd: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_20c0:
	/* 0x20c0: ja     25d2 <generic_lsm_filter_arg+0x25d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_25d2;
	}
x86_l_20c6:
	/* 0x20c6: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_20cc:
	/* 0x20cc: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_20d0:
	/* 0x20d0: jae    25d2 <generic_lsm_filter_arg+0x25d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_25d2;
	}
x86_l_20d6:
	/* 0x20d6: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_20d9:
	/* 0x20d9: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_20dd:
	/* 0x20dd: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_20df:
	/* 0x20df: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_20e3:
	/* 0x20e3: jmp    25df <generic_lsm_filter_arg+0x25df> */
	goto x86_l_25df;
x86_l_20e8:
	/* 0x20e8: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_20eb:
	/* 0x20eb: je     2a4e <generic_lsm_filter_arg+0x2a4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10830ULL;
	}
x86_l_20f1:
	/* 0x20f1: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_20f4:
	/* 0x20f4: jne    2a40 <generic_lsm_filter_arg+0x2a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10816ULL;
	}
x86_l_20fa:
	/* 0x20fa: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_20ff:
	/* 0x20ff: jmp    2a53 <generic_lsm_filter_arg+0x2a53> */
	return 10835ULL;
x86_l_2104:
	/* 0x2104: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2106:
	/* 0x2106: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2109:
	/* 0x2109: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_210c:
	/* 0x210c: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_2111:
	/* 0x2111: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2115:
	/* 0x2115: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_211a:
	/* 0x211a: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_211f:
	/* 0x211f: mov    rdi,QWORD PTR [rip+0x1edc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_2126:
	/* 0x2126: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2128:
	/* 0x2128: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_212b:
	/* 0x212b: je     21af <generic_lsm_filter_arg+0x21af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21af;
	}
x86_l_2131:
	/* 0x2131: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_2133:
	/* 0x2133: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2138:
	/* 0x2138: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_213b:
	/* 0x213b: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2140:
	/* 0x2140: je     2187 <generic_lsm_filter_arg+0x2187> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2187;
	}
x86_l_2142:
	/* 0x2142: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2147:
	/* 0x2147: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2149:
	/* 0x2149: jmp    2156 <generic_lsm_filter_arg+0x2156> */
	goto x86_l_2156;
x86_l_214b:
	/* 0x214b: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_214e:
	/* 0x214e: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2151:
	/* 0x2151: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2154:
	/* 0x2154: je     2187 <generic_lsm_filter_arg+0x2187> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2187;
	}
x86_l_2156:
	/* 0x2156: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2158:
	/* 0x2158: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_215c:
	/* 0x215c: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_215f:
	/* 0x215f: jae    214b <generic_lsm_filter_arg+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_214b;
	}
x86_l_2161:
	/* 0x2161: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_2165:
	/* 0x2165: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_2168:
	/* 0x2168: je     217f <generic_lsm_filter_arg+0x217f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_217f;
	}
x86_l_216a:
	/* 0x216a: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_216e:
	/* 0x216e: ja     214b <generic_lsm_filter_arg+0x214b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_214b;
	}
x86_l_2170:
	/* 0x2170: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2174:
	/* 0x2174: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_2178:
	/* 0x2178: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_217b:
	/* 0x217b: je     2158 <generic_lsm_filter_arg+0x2158> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2158;
	}
x86_l_217d:
	/* 0x217d: jmp    214b <generic_lsm_filter_arg+0x214b> */
	goto x86_l_214b;
x86_l_217f:
	/* 0x217f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2181:
	/* 0x2181: jns    23f1 <generic_lsm_filter_arg+0x23f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_23f1;
	}
x86_l_2187:
	/* 0x2187: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_218b:
	/* 0x218b: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_2190:
	/* 0x2190: jae    21a3 <generic_lsm_filter_arg+0x21a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_21a3;
	}
x86_l_2192:
	/* 0x2192: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2196:
	/* 0x2196: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2199:
	/* 0x2199: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_219d:
	/* 0x219d: jne    2109 <generic_lsm_filter_arg+0x2109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2109;
	}
x86_l_21a3:
	/* 0x21a3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21a5:
	/* 0x21a5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21aa:
	/* 0x21aa: jmp    3754 <generic_lsm_filter_arg+0x3754> */
	return 14164ULL;
x86_l_21af:
	/* 0x21af: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21b1:
	/* 0x21b1: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21b6:
	/* 0x21b6: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_21b9:
	/* 0x21b9: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_21be:
	/* 0x21be: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21c3:
	/* 0x21c3: jmp    3754 <generic_lsm_filter_arg+0x3754> */
	return 14164ULL;
x86_l_21c8:
	/* 0x21c8: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_21cb:
	/* 0x21cb: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_21cf:
	/* 0x21cf: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_21d2:
	/* 0x21d2: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_21d6:
	/* 0x21d6: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_21d9:
	/* 0x21d9: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_21dc:
	/* 0x21dc: cmp    esi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 41ULL);
x86_l_21df:
	/* 0x21df: jb     2fb4 <generic_lsm_filter_arg+0x2fb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12212ULL;
	}
x86_l_21e5:
	/* 0x21e5: mov    r8,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21ea:
	/* 0x21ea: mov    rdi,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21ef:
	/* 0x21ef: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_21f2:
	/* 0x21f2: je     21fd <generic_lsm_filter_arg+0x21fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21fd;
	}
x86_l_21f4:
	/* 0x21f4: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_21f7:
	/* 0x21f7: jne    28ba <generic_lsm_filter_arg+0x28ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10426ULL;
	}
x86_l_21fd:
	/* 0x21fd: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_2200:
	/* 0x2200: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2204:
	/* 0x2204: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2207:
	/* 0x2207: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_220b:
	/* 0x220b: jmp    28c8 <generic_lsm_filter_arg+0x28c8> */
	return 10440ULL;
x86_l_2210:
	/* 0x2210: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2212:
	/* 0x2212: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2215:
	/* 0x2215: jne    2220 <generic_lsm_filter_arg+0x2220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2220;
	}
x86_l_2217:
	/* 0x2217: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_221a:
	/* 0x221a: je     2220 <generic_lsm_filter_arg+0x2220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2220;
	}
x86_l_221c:
	/* 0x221c: movzx  ebx,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_2220:
	/* 0x2220: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2223:
	/* 0x2223: je     222e <generic_lsm_filter_arg+0x222e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_222e;
	}
x86_l_2225:
	/* 0x2225: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2228:
	/* 0x2228: jne    2623 <generic_lsm_filter_arg+0x2623> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2623;
	}
x86_l_222e:
	/* 0x222e: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_2231:
	/* 0x2231: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2237:
	/* 0x2237: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_223b:
	/* 0x223b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2240:
	/* 0x2240: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2247:
	/* 0x2247: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_224c:
	/* 0x224c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_224e:
	/* 0x224e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2251:
	/* 0x2251: je     2ba <generic_lsm_filter_arg+0x2ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 698ULL;
	}
x86_l_2257:
	/* 0x2257: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_225a:
	/* 0x225a: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_225c:
	/* 0x225c: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2264:
	/* 0x2264: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2269:
	/* 0x2269: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_226e:
	/* 0x226e: jmp    1cc1 <generic_lsm_filter_arg+0x1cc1> */
	return 7361ULL;
x86_l_2273:
	/* 0x2273: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2275:
	/* 0x2275: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_2278:
	/* 0x2278: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_227d:
	/* 0x227d: jmp    25c3 <generic_lsm_filter_arg+0x25c3> */
	goto x86_l_25c3;
x86_l_2282:
	/* 0x2282: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2285:
	/* 0x2285: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_228a:
	/* 0x228a: ja     2295 <generic_lsm_filter_arg+0x2295> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2295;
	}
x86_l_228c:
	/* 0x228c: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_228f:
	/* 0x228f: jbe    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 730ULL;
	}
x86_l_2295:
	/* 0x2295: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_2298:
	/* 0x2298: jb     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 279ULL;
	}
x86_l_229e:
	/* 0x229e: mov    rdi,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22a3:
	/* 0x22a3: mov    rsi,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22a8:
	/* 0x22a8: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_22ab:
	/* 0x22ab: je     22b6 <generic_lsm_filter_arg+0x22b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22b6;
	}
x86_l_22ad:
	/* 0x22ad: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_22b0:
	/* 0x22b0: jne    28fd <generic_lsm_filter_arg+0x28fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10493ULL;
	}
x86_l_22b6:
	/* 0x22b6: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_22b9:
	/* 0x22b9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22be:
	/* 0x22be: jg     2910 <generic_lsm_filter_arg+0x2910> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10512ULL;
	}
x86_l_22c4:
	/* 0x22c4: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_22c7:
	/* 0x22c7: jle    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 730ULL;
	}
x86_l_22cd:
	/* 0x22cd: jmp    2910 <generic_lsm_filter_arg+0x2910> */
	return 10512ULL;
x86_l_22d2:
	/* 0x22d2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22d7:
	/* 0x22d7: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22dc:
	/* 0x22dc: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_22df:
	/* 0x22df: jmp    1d02 <generic_lsm_filter_arg+0x1d02> */
	return 7426ULL;
x86_l_22e4:
	/* 0x22e4: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e8:
	/* 0x22e8: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_22ee:
	/* 0x22ee: jmp    22fa <generic_lsm_filter_arg+0x22fa> */
	goto x86_l_22fa;
x86_l_22f0:
	/* 0x22f0: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22f4:
	/* 0x22f4: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_22fa:
	/* 0x22fa: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ff:
	/* 0x22ff: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2302:
	/* 0x2302: jb     37db <generic_lsm_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14299ULL;
	}
x86_l_2308:
	/* 0x2308: mov    esi,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_230d:
	/* 0x230d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2310:
	/* 0x2310: jle    232e <generic_lsm_filter_arg+0x232e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_232e;
	}
x86_l_2312:
	/* 0x2312: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2315:
	/* 0x2315: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2318:
	/* 0x2318: jae    2364 <generic_lsm_filter_arg+0x2364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2364;
	}
x86_l_231a:
	/* 0x231a: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_231e:
	/* 0x231e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2323:
	/* 0x2323: jne    2e23 <generic_lsm_filter_arg+0x2e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11811ULL;
	}
x86_l_2329:
	/* 0x2329: jmp    367c <generic_lsm_filter_arg+0x367c> */
	return 13948ULL;
x86_l_232e:
	/* 0x232e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2331:
	/* 0x2331: je     2381 <generic_lsm_filter_arg+0x2381> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2381;
	}
x86_l_2333:
	/* 0x2333: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2336:
	/* 0x2336: jne    2e23 <generic_lsm_filter_arg+0x2e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11811ULL;
	}
x86_l_233c:
	/* 0x233c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_233f:
	/* 0x233f: ja     2e19 <generic_lsm_filter_arg+0x2e19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11801ULL;
	}
x86_l_2345:
	/* 0x2345: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_234b:
	/* 0x234b: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_234f:
	/* 0x234f: jae    2e19 <generic_lsm_filter_arg+0x2e19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11801ULL;
	}
x86_l_2355:
	/* 0x2355: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2359:
	/* 0x2359: jl     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 730ULL;
	}
x86_l_235f:
	/* 0x235f: jmp    2e23 <generic_lsm_filter_arg+0x2e23> */
	return 11811ULL;
x86_l_2364:
	/* 0x2364: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2367:
	/* 0x2367: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_236c:
	/* 0x236c: jne    2e23 <generic_lsm_filter_arg+0x2e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11811ULL;
	}
x86_l_2372:
	/* 0x2372: test   DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2376:
	/* 0x2376: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_237c:
	/* 0x237c: jmp    2e23 <generic_lsm_filter_arg+0x2e23> */
	return 11811ULL;
x86_l_2381:
	/* 0x2381: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2384:
	/* 0x2384: ja     2e0d <generic_lsm_filter_arg+0x2e0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11789ULL;
	}
x86_l_238a:
	/* 0x238a: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2390:
	/* 0x2390: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2394:
	/* 0x2394: jae    2e0d <generic_lsm_filter_arg+0x2e0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11789ULL;
	}
x86_l_239a:
	/* 0x239a: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_239e:
	/* 0x239e: jg     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 730ULL;
	}
x86_l_23a4:
	/* 0x23a4: jmp    2e23 <generic_lsm_filter_arg+0x2e23> */
	return 11811ULL;
x86_l_23a9:
	/* 0x23a9: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23ac:
	/* 0x23ac: je     2c71 <generic_lsm_filter_arg+0x2c71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11377ULL;
	}
x86_l_23b2:
	/* 0x23b2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23b5:
	/* 0x23b5: jne    2c7e <generic_lsm_filter_arg+0x2c7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11390ULL;
	}
x86_l_23bb:
	/* 0x23bb: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_23c0:
	/* 0x23c0: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_23c2:
	/* 0x23c2: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_23c8:
	/* 0x23c8: jmp    2c7e <generic_lsm_filter_arg+0x2c7e> */
	return 11390ULL;
x86_l_23cd:
	/* 0x23cd: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23d0:
	/* 0x23d0: je     2cb3 <generic_lsm_filter_arg+0x2cb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11443ULL;
	}
x86_l_23d6:
	/* 0x23d6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23d9:
	/* 0x23d9: jne    2cc0 <generic_lsm_filter_arg+0x2cc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11456ULL;
	}
x86_l_23df:
	/* 0x23df: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23e4:
	/* 0x23e4: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_23e6:
	/* 0x23e6: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_23ec:
	/* 0x23ec: jmp    2cc0 <generic_lsm_filter_arg+0x2cc0> */
	return 11456ULL;
x86_l_23f1:
	/* 0x23f1: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_23f6:
	/* 0x23f6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23fb:
	/* 0x23fb: jmp    3754 <generic_lsm_filter_arg+0x3754> */
	return 14164ULL;
x86_l_2400:
	/* 0x2400: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2405:
	/* 0x2405: jmp    2413 <generic_lsm_filter_arg+0x2413> */
	goto x86_l_2413;
x86_l_2407:
	/* 0x2407: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_240c:
	/* 0x240c: jmp    2413 <generic_lsm_filter_arg+0x2413> */
	goto x86_l_2413;
x86_l_240e:
	/* 0x240e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2413:
	/* 0x2413: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2415:
	/* 0x2415: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2418:
	/* 0x2418: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_241d:
	/* 0x241d: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2420:
	/* 0x2420: je     339e <generic_lsm_filter_arg+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13214ULL;
	}
x86_l_2426:
	/* 0x2426: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_242a:
	/* 0x242a: mov    DWORD PTR [rsp+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2431:
	/* 0x2431: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2436:
	/* 0x2436: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_243b:
	/* 0x243b: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2442:
	/* 0x2442: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2447:
	/* 0x2447: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_244a:
	/* 0x244a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244c:
	/* 0x244c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_244f:
	/* 0x244f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2454:
	/* 0x2454: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_245b:
	/* 0x245b: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_245e:
	/* 0x245e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2460:
	/* 0x2460: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2465:
	/* 0x2465: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2468:
	/* 0x2468: je     339e <generic_lsm_filter_arg+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13214ULL;
	}
x86_l_246e:
	/* 0x246e: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_2473:
	/* 0x2473: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2476:
	/* 0x2476: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_247b:
	/* 0x247b: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2480:
	/* 0x2480: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2485:
	/* 0x2485: je     33af <generic_lsm_filter_arg+0x33af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13231ULL;
	}
x86_l_248b:
	/* 0x248b: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2493:
	/* 0x2493: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2498:
	/* 0x2498: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_249c:
	/* 0x249c: mov    ebx,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_24a3:
	/* 0x24a3: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_24a6:
	/* 0x24a6: jg     24ec <generic_lsm_filter_arg+0x24ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_24ec;
	}
x86_l_24a8:
	/* 0x24a8: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24ad:
	/* 0x24ad: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24b0:
	/* 0x24b0: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_24b4:
	/* 0x24b4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24b9:
	/* 0x24b9: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_24bb:
	/* 0x24bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24bd:
	/* 0x24bd: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24c2:
	/* 0x24c2: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_24c4:
	/* 0x24c4: mov    r13d,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_24c9:
	/* 0x24c9: jbe    2531 <generic_lsm_filter_arg+0x2531> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2531;
	}
x86_l_24cb:
	/* 0x24cb: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24d0:
	/* 0x24d0: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_24d4:
	/* 0x24d4: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_24d7:
	/* 0x24d7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24dd:
	/* 0x24dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24e2:
	/* 0x24e2: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_24ea:
	/* 0x24ea: jmp    252f <generic_lsm_filter_arg+0x252f> */
	goto x86_l_252f;
x86_l_24ec:
	/* 0x24ec: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24f1:
	/* 0x24f1: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24f4:
	/* 0x24f4: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_24f8:
	/* 0x24f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24fd:
	/* 0x24fd: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_24ff:
	/* 0x24ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2501:
	/* 0x2501: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2506:
	/* 0x2506: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2508:
	/* 0x2508: mov    r13d,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_250d:
	/* 0x250d: jbe    2531 <generic_lsm_filter_arg+0x2531> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2531;
	}
x86_l_250f:
	/* 0x250f: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2514:
	/* 0x2514: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2518:
	/* 0x2518: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_251c:
	/* 0x251c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2522:
	/* 0x2522: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2527:
	/* 0x2527: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_252f:
	/* 0x252f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2531:
	/* 0x2531: mov    DWORD PTR [rsp+0x40],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2536:
	/* 0x2536: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2539:
	/* 0x2539: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_253e:
	/* 0x253e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2543:
	/* 0x2543: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2548:
	/* 0x2548: jle    2584 <generic_lsm_filter_arg+0x2584> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2584;
	}
x86_l_254a:
	/* 0x254a: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_254d:
	/* 0x254d: jg     2a0f <generic_lsm_filter_arg+0x2a0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10767ULL;
	}
x86_l_2553:
	/* 0x2553: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2556:
	/* 0x2556: je     30eb <generic_lsm_filter_arg+0x30eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12523ULL;
	}
x86_l_255c:
	/* 0x255c: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_255f:
	/* 0x255f: je     30b2 <generic_lsm_filter_arg+0x30b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12466ULL;
	}
x86_l_2565:
	/* 0x2565: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2568:
	/* 0x2568: jne    97f <generic_lsm_filter_arg+0x97f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2431ULL;
	}
x86_l_256e:
	/* 0x256e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2573:
	/* 0x2573: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2578:
	/* 0x2578: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_257f:
	/* 0x257f: jmp    310f <generic_lsm_filter_arg+0x310f> */
	return 12559ULL;
x86_l_2584:
	/* 0x2584: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2587:
	/* 0x2587: jle    2cf5 <generic_lsm_filter_arg+0x2cf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11509ULL;
	}
x86_l_258d:
	/* 0x258d: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_2590:
	/* 0x2590: je     30d8 <generic_lsm_filter_arg+0x30d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12504ULL;
	}
x86_l_2596:
	/* 0x2596: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2599:
	/* 0x2599: je     309f <generic_lsm_filter_arg+0x309f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12447ULL;
	}
x86_l_259f:
	/* 0x259f: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_25a2:
	/* 0x25a2: jne    97f <generic_lsm_filter_arg+0x97f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2431ULL;
	}
x86_l_25a8:
	/* 0x25a8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25ad:
	/* 0x25ad: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25b2:
	/* 0x25b2: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_25b9:
	/* 0x25b9: jmp    310f <generic_lsm_filter_arg+0x310f> */
	return 12559ULL;
x86_l_25be:
	/* 0x25be: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_25c3:
	/* 0x25c3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25c8:
	/* 0x25c8: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25cd:
	/* 0x25cd: jmp    3754 <generic_lsm_filter_arg+0x3754> */
	return 14164ULL;
x86_l_25d2:
	/* 0x25d2: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_25d5:
	/* 0x25d5: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_25d9:
	/* 0x25d9: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_25db:
	/* 0x25db: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_25df:
	/* 0x25df: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_25e2:
	/* 0x25e2: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_25e5:
	/* 0x25e5: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_25e8:
	/* 0x25e8: jb     2fb4 <generic_lsm_filter_arg+0x2fb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12212ULL;
	}
x86_l_25ee:
	/* 0x25ee: mov    r8d,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25f3:
	/* 0x25f3: mov    edi,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_25f8:
	/* 0x25f8: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_25fb:
	/* 0x25fb: ja     2d4d <generic_lsm_filter_arg+0x2d4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11597ULL;
	}
x86_l_2601:
	/* 0x2601: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_2607:
	/* 0x2607: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_260b:
	/* 0x260b: jae    2d4d <generic_lsm_filter_arg+0x2d4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11597ULL;
	}
x86_l_2611:
	/* 0x2611: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2614:
	/* 0x2614: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2618:
	/* 0x2618: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_261a:
	/* 0x261a: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_261e:
	/* 0x261e: jmp    2d5a <generic_lsm_filter_arg+0x2d5a> */
	return 11610ULL;
x86_l_2623:
	/* 0x2623: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2625:
	/* 0x2625: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_262a:
	/* 0x262a: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_2630:
	/* 0x2630: jmp    2640 <generic_lsm_filter_arg+0x2640> */
	goto x86_l_2640;
x86_l_2632:
	/* 0x2632: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_2638:
	/* 0x2638: jmp    2640 <generic_lsm_filter_arg+0x2640> */
	goto x86_l_2640;
x86_l_263a:
	/* 0x263a: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_2640:
	/* 0x2640: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_2643:
	/* 0x2643: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2646:
	/* 0x2646: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_264b:
	/* 0x264b: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_264e:
	/* 0x264e: je     2f0a <generic_lsm_filter_arg+0x2f0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12042ULL;
	}
x86_l_2654:
	/* 0x2654: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2658:
	/* 0x2658: mov    QWORD PTR [rsp+0x70],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_265d:
	/* 0x265d: mov    BYTE PTR [rsp+0x98],r8b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2665:
	/* 0x2665: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
	return 9834ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9844ULL: goto x86_l_2674;
	case 9849ULL: goto x86_l_2679;
	case 9856ULL: goto x86_l_2680;
	case 9861ULL: goto x86_l_2685;
	case 9864ULL: goto x86_l_2688;
	case 9866ULL: goto x86_l_268a;
	case 9869ULL: goto x86_l_268d;
	case 9874ULL: goto x86_l_2692;
	case 9881ULL: goto x86_l_2699;
	case 9884ULL: goto x86_l_269c;
	case 9886ULL: goto x86_l_269e;
	case 9889ULL: goto x86_l_26a1;
	case 9895ULL: goto x86_l_26a7;
	case 9900ULL: goto x86_l_26ac;
	case 9903ULL: goto x86_l_26af;
	case 9908ULL: goto x86_l_26b4;
	case 9913ULL: goto x86_l_26b9;
	case 9918ULL: goto x86_l_26be;
	case 9924ULL: goto x86_l_26c4;
	case 9927ULL: goto x86_l_26c7;
	case 9930ULL: goto x86_l_26ca;
	case 9933ULL: goto x86_l_26cd;
	case 9937ULL: goto x86_l_26d1;
	case 9945ULL: goto x86_l_26d9;
	case 9947ULL: goto x86_l_26db;
	case 9950ULL: goto x86_l_26de;
	case 9958ULL: goto x86_l_26e6;
	case 9960ULL: goto x86_l_26e8;
	case 9964ULL: goto x86_l_26ec;
	case 9969ULL: goto x86_l_26f1;
	case 9974ULL: goto x86_l_26f6;
	case 9979ULL: goto x86_l_26fb;
	case 9982ULL: goto x86_l_26fe;
	case 9984ULL: goto x86_l_2700;
	case 9989ULL: goto x86_l_2705;
	case 9992ULL: goto x86_l_2708;
	case 9994ULL: goto x86_l_270a;
	case 10002ULL: goto x86_l_2712;
	case 10006ULL: goto x86_l_2716;
	case 10009ULL: goto x86_l_2719;
	case 10015ULL: goto x86_l_271f;
	case 10020ULL: goto x86_l_2724;
	case 10022ULL: goto x86_l_2726;
	case 10027ULL: goto x86_l_272b;
	case 10031ULL: goto x86_l_272f;
	case 10035ULL: goto x86_l_2733;
	case 10040ULL: goto x86_l_2738;
	case 10045ULL: goto x86_l_273d;
	case 10048ULL: goto x86_l_2740;
	case 10050ULL: goto x86_l_2742;
	case 10055ULL: goto x86_l_2747;
	case 10058ULL: goto x86_l_274a;
	case 10060ULL: goto x86_l_274c;
	case 10068ULL: goto x86_l_2754;
	case 10072ULL: goto x86_l_2758;
	case 10076ULL: goto x86_l_275c;
	case 10082ULL: goto x86_l_2762;
	case 10087ULL: goto x86_l_2767;
	case 10090ULL: goto x86_l_276a;
	case 10092ULL: goto x86_l_276c;
	case 10096ULL: goto x86_l_2770;
	case 10100ULL: goto x86_l_2774;
	case 10103ULL: goto x86_l_2777;
	case 10108ULL: goto x86_l_277c;
	case 10113ULL: goto x86_l_2781;
	case 10118ULL: goto x86_l_2786;
	case 10120ULL: goto x86_l_2788;
	case 10123ULL: goto x86_l_278b;
	case 10129ULL: goto x86_l_2791;
	case 10132ULL: goto x86_l_2794;
	case 10138ULL: goto x86_l_279a;
	case 10141ULL: goto x86_l_279d;
	case 10147ULL: goto x86_l_27a3;
	case 10150ULL: goto x86_l_27a6;
	case 10156ULL: goto x86_l_27ac;
	case 10161ULL: goto x86_l_27b1;
	case 10166ULL: goto x86_l_27b6;
	case 10173ULL: goto x86_l_27bd;
	case 10178ULL: goto x86_l_27c2;
	case 10181ULL: goto x86_l_27c5;
	case 10187ULL: goto x86_l_27cb;
	case 10190ULL: goto x86_l_27ce;
	case 10196ULL: goto x86_l_27d4;
	case 10199ULL: goto x86_l_27d7;
	case 10205ULL: goto x86_l_27dd;
	case 10208ULL: goto x86_l_27e0;
	case 10214ULL: goto x86_l_27e6;
	case 10219ULL: goto x86_l_27eb;
	case 10224ULL: goto x86_l_27f0;
	case 10231ULL: goto x86_l_27f7;
	case 10236ULL: goto x86_l_27fc;
	case 10238ULL: goto x86_l_27fe;
	case 10243ULL: goto x86_l_2803;
	case 10245ULL: goto x86_l_2805;
	case 10247ULL: goto x86_l_2807;
	case 10253ULL: goto x86_l_280d;
	case 10256ULL: goto x86_l_2810;
	case 10262ULL: goto x86_l_2816;
	case 10267ULL: goto x86_l_281b;
	case 10272ULL: goto x86_l_2820;
	case 10275ULL: goto x86_l_2823;
	case 10281ULL: goto x86_l_2829;
	case 10287ULL: goto x86_l_282f;
	case 10291ULL: goto x86_l_2833;
	case 10297ULL: goto x86_l_2839;
	case 10299ULL: goto x86_l_283b;
	case 10304ULL: goto x86_l_2840;
	case 10310ULL: goto x86_l_2846;
	case 10312ULL: goto x86_l_2848;
	case 10318ULL: goto x86_l_284e;
	case 10323ULL: goto x86_l_2853;
	case 10328ULL: goto x86_l_2858;
	case 10333ULL: goto x86_l_285d;
	case 10335ULL: goto x86_l_285f;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10347ULL: goto x86_l_286b;
	case 10352ULL: goto x86_l_2870;
	case 10357ULL: goto x86_l_2875;
	case 10359ULL: goto x86_l_2877;
	case 10361ULL: goto x86_l_2879;
	case 10366ULL: goto x86_l_287e;
	case 10369ULL: goto x86_l_2881;
	case 10372ULL: goto x86_l_2884;
	case 10378ULL: goto x86_l_288a;
	case 10384ULL: goto x86_l_2890;
	case 10390ULL: goto x86_l_2896;
	case 10393ULL: goto x86_l_2899;
	case 10399ULL: goto x86_l_289f;
	case 10401ULL: goto x86_l_28a1;
	case 10407ULL: goto x86_l_28a7;
	case 10410ULL: goto x86_l_28aa;
	case 10416ULL: goto x86_l_28b0;
	case 10421ULL: goto x86_l_28b5;
	case 10426ULL: goto x86_l_28ba;
	case 10429ULL: goto x86_l_28bd;
	case 10433ULL: goto x86_l_28c1;
	case 10436ULL: goto x86_l_28c4;
	case 10440ULL: goto x86_l_28c8;
	case 10443ULL: goto x86_l_28cb;
	case 10446ULL: goto x86_l_28ce;
	case 10449ULL: goto x86_l_28d1;
	case 10455ULL: goto x86_l_28d7;
	case 10460ULL: goto x86_l_28dc;
	case 10465ULL: goto x86_l_28e1;
	case 10468ULL: goto x86_l_28e4;
	case 10470ULL: goto x86_l_28e6;
	case 10473ULL: goto x86_l_28e9;
	case 10479ULL: goto x86_l_28ef;
	case 10482ULL: goto x86_l_28f2;
	case 10485ULL: goto x86_l_28f5;
	case 10488ULL: goto x86_l_28f8;
	case 10493ULL: goto x86_l_28fd;
	case 10496ULL: goto x86_l_2900;
	case 10501ULL: goto x86_l_2905;
	case 10503ULL: goto x86_l_2907;
	case 10506ULL: goto x86_l_290a;
	case 10512ULL: goto x86_l_2910;
	case 10515ULL: goto x86_l_2913;
	case 10521ULL: goto x86_l_2919;
	case 10526ULL: goto x86_l_291e;
	case 10531ULL: goto x86_l_2923;
	case 10534ULL: goto x86_l_2926;
	case 10536ULL: goto x86_l_2928;
	case 10539ULL: goto x86_l_292b;
	case 10545ULL: goto x86_l_2931;
	case 10548ULL: goto x86_l_2934;
	case 10554ULL: goto x86_l_293a;
	case 10557ULL: goto x86_l_293d;
	case 10563ULL: goto x86_l_2943;
	case 10568ULL: goto x86_l_2948;
	case 10572ULL: goto x86_l_294c;
	case 10578ULL: goto x86_l_2952;
	case 10580ULL: goto x86_l_2954;
	case 10584ULL: goto x86_l_2958;
	case 10590ULL: goto x86_l_295e;
	case 10593ULL: goto x86_l_2961;
	case 10599ULL: goto x86_l_2967;
	case 10604ULL: goto x86_l_296c;
	case 10607ULL: goto x86_l_296f;
	case 10609ULL: goto x86_l_2971;
	case 10612ULL: goto x86_l_2974;
	case 10615ULL: goto x86_l_2977;
	case 10617ULL: goto x86_l_2979;
	case 10621ULL: goto x86_l_297d;
	case 10626ULL: goto x86_l_2982;
	case 10632ULL: goto x86_l_2988;
	case 10637ULL: goto x86_l_298d;
	case 10640ULL: goto x86_l_2990;
	case 10646ULL: goto x86_l_2996;
	case 10649ULL: goto x86_l_2999;
	case 10655ULL: goto x86_l_299f;
	case 10658ULL: goto x86_l_29a2;
	case 10660ULL: goto x86_l_29a4;
	case 10663ULL: goto x86_l_29a7;
	case 10669ULL: goto x86_l_29ad;
	case 10673ULL: goto x86_l_29b1;
	case 10679ULL: goto x86_l_29b7;
	case 10684ULL: goto x86_l_29bc;
	case 10687ULL: goto x86_l_29bf;
	case 10692ULL: goto x86_l_29c4;
	case 10698ULL: goto x86_l_29ca;
	case 10702ULL: goto x86_l_29ce;
	case 10708ULL: goto x86_l_29d4;
	case 10713ULL: goto x86_l_29d9;
	case 10716ULL: goto x86_l_29dc;
	case 10722ULL: goto x86_l_29e2;
	case 10727ULL: goto x86_l_29e7;
	case 10729ULL: goto x86_l_29e9;
	case 10735ULL: goto x86_l_29ef;
	case 10740ULL: goto x86_l_29f4;
	case 10743ULL: goto x86_l_29f7;
	case 10749ULL: goto x86_l_29fd;
	case 10754ULL: goto x86_l_2a02;
	case 10756ULL: goto x86_l_2a04;
	case 10762ULL: goto x86_l_2a0a;
	case 10767ULL: goto x86_l_2a0f;
	case 10770ULL: goto x86_l_2a12;
	case 10776ULL: goto x86_l_2a18;
	case 10779ULL: goto x86_l_2a1b;
	case 10785ULL: goto x86_l_2a21;
	case 10788ULL: goto x86_l_2a24;
	case 10794ULL: goto x86_l_2a2a;
	case 10799ULL: goto x86_l_2a2f;
	case 10804ULL: goto x86_l_2a34;
	case 10811ULL: goto x86_l_2a3b;
	case 10816ULL: goto x86_l_2a40;
	case 10821ULL: goto x86_l_2a45;
	case 10823ULL: goto x86_l_2a47;
	case 10828ULL: goto x86_l_2a4c;
	case 10830ULL: goto x86_l_2a4e;
	case 10835ULL: goto x86_l_2a53;
	case 10837ULL: goto x86_l_2a55;
	case 10840ULL: goto x86_l_2a58;
	case 10845ULL: goto x86_l_2a5d;
	case 10848ULL: goto x86_l_2a60;
	case 10854ULL: goto x86_l_2a66;
	case 10858ULL: goto x86_l_2a6a;
	case 10862ULL: goto x86_l_2a6e;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10880ULL: goto x86_l_2a80;
	case 10887ULL: goto x86_l_2a87;
	case 10892ULL: goto x86_l_2a8c;
	case 10895ULL: goto x86_l_2a8f;
	case 10897ULL: goto x86_l_2a91;
	case 10900ULL: goto x86_l_2a94;
	case 10905ULL: goto x86_l_2a99;
	case 10912ULL: goto x86_l_2aa0;
	case 10915ULL: goto x86_l_2aa3;
	case 10917ULL: goto x86_l_2aa5;
	case 10922ULL: goto x86_l_2aaa;
	case 10925ULL: goto x86_l_2aad;
	case 10931ULL: goto x86_l_2ab3;
	case 10936ULL: goto x86_l_2ab8;
	case 10939ULL: goto x86_l_2abb;
	case 10944ULL: goto x86_l_2ac0;
	case 10949ULL: goto x86_l_2ac5;
	case 10954ULL: goto x86_l_2aca;
	case 10960ULL: goto x86_l_2ad0;
	case 10963ULL: goto x86_l_2ad3;
	case 10967ULL: goto x86_l_2ad7;
	case 10970ULL: goto x86_l_2ada;
	case 10972ULL: goto x86_l_2adc;
	case 10977ULL: goto x86_l_2ae1;
	case 10980ULL: goto x86_l_2ae4;
	case 10984ULL: goto x86_l_2ae8;
	case 10989ULL: goto x86_l_2aed;
	case 10994ULL: goto x86_l_2af2;
	case 10996ULL: goto x86_l_2af4;
	case 10998ULL: goto x86_l_2af6;
	case 11006ULL: goto x86_l_2afe;
	case 11008ULL: goto x86_l_2b00;
	case 11010ULL: goto x86_l_2b02;
	case 11015ULL: goto x86_l_2b07;
	case 11019ULL: goto x86_l_2b0b;
	case 11022ULL: goto x86_l_2b0e;
	case 11028ULL: goto x86_l_2b14;
	case 11033ULL: goto x86_l_2b19;
	case 11036ULL: goto x86_l_2b1c;
	case 11038ULL: goto x86_l_2b1e;
	case 11040ULL: goto x86_l_2b20;
	case 11045ULL: goto x86_l_2b25;
	case 11050ULL: goto x86_l_2b2a;
	case 11053ULL: goto x86_l_2b2d;
	case 11057ULL: goto x86_l_2b31;
	case 11062ULL: goto x86_l_2b36;
	case 11067ULL: goto x86_l_2b3b;
	case 11069ULL: goto x86_l_2b3d;
	case 11071ULL: goto x86_l_2b3f;
	case 11079ULL: goto x86_l_2b47;
	case 11081ULL: goto x86_l_2b49;
	case 11083ULL: goto x86_l_2b4b;
	case 11088ULL: goto x86_l_2b50;
	case 11092ULL: goto x86_l_2b54;
	case 11096ULL: goto x86_l_2b58;
	case 11102ULL: goto x86_l_2b5e;
	case 11107ULL: goto x86_l_2b63;
	case 11110ULL: goto x86_l_2b66;
	case 11112ULL: goto x86_l_2b68;
	case 11116ULL: goto x86_l_2b6c;
	case 11120ULL: goto x86_l_2b70;
	case 11123ULL: goto x86_l_2b73;
	case 11128ULL: goto x86_l_2b78;
	case 11133ULL: goto x86_l_2b7d;
	case 11135ULL: goto x86_l_2b7f;
	case 11138ULL: goto x86_l_2b82;
	case 11144ULL: goto x86_l_2b88;
	case 11147ULL: goto x86_l_2b8b;
	case 11153ULL: goto x86_l_2b91;
	case 11156ULL: goto x86_l_2b94;
	case 11162ULL: goto x86_l_2b9a;
	case 11165ULL: goto x86_l_2b9d;
	case 11171ULL: goto x86_l_2ba3;
	case 11176ULL: goto x86_l_2ba8;
	case 11181ULL: goto x86_l_2bad;
	case 11188ULL: goto x86_l_2bb4;
	case 11193ULL: goto x86_l_2bb9;
	case 11196ULL: goto x86_l_2bbc;
	case 11202ULL: goto x86_l_2bc2;
	case 11205ULL: goto x86_l_2bc5;
	case 11211ULL: goto x86_l_2bcb;
	case 11214ULL: goto x86_l_2bce;
	case 11220ULL: goto x86_l_2bd4;
	case 11223ULL: goto x86_l_2bd7;
	case 11229ULL: goto x86_l_2bdd;
	case 11234ULL: goto x86_l_2be2;
	case 11239ULL: goto x86_l_2be7;
	case 11246ULL: goto x86_l_2bee;
	case 11251ULL: goto x86_l_2bf3;
	case 11254ULL: goto x86_l_2bf6;
	case 11256ULL: goto x86_l_2bf8;
	case 11259ULL: goto x86_l_2bfb;
	case 11265ULL: goto x86_l_2c01;
	case 11269ULL: goto x86_l_2c05;
	case 11275ULL: goto x86_l_2c0b;
	case 11280ULL: goto x86_l_2c10;
	case 11283ULL: goto x86_l_2c13;
	case 11289ULL: goto x86_l_2c19;
	case 11292ULL: goto x86_l_2c1c;
	case 11298ULL: goto x86_l_2c22;
	case 11301ULL: goto x86_l_2c25;
	case 11307ULL: goto x86_l_2c2b;
	case 11312ULL: goto x86_l_2c30;
	case 11317ULL: goto x86_l_2c35;
	case 11324ULL: goto x86_l_2c3c;
	case 11329ULL: goto x86_l_2c41;
	case 11334ULL: goto x86_l_2c46;
	case 11339ULL: goto x86_l_2c4b;
	case 11344ULL: goto x86_l_2c50;
	case 11349ULL: goto x86_l_2c55;
	case 11352ULL: goto x86_l_2c58;
	case 11358ULL: goto x86_l_2c5e;
	case 11361ULL: goto x86_l_2c61;
	case 11367ULL: goto x86_l_2c67;
	case 11372ULL: goto x86_l_2c6c;
	case 11377ULL: goto x86_l_2c71;
	case 11382ULL: goto x86_l_2c76;
	case 11384ULL: goto x86_l_2c78;
	case 11390ULL: goto x86_l_2c7e;
	case 11393ULL: goto x86_l_2c81;
	case 11399ULL: goto x86_l_2c87;
	case 11404ULL: goto x86_l_2c8c;
	case 11407ULL: goto x86_l_2c8f;
	case 11413ULL: goto x86_l_2c95;
	case 11416ULL: goto x86_l_2c98;
	case 11419ULL: goto x86_l_2c9b;
	case 11425ULL: goto x86_l_2ca1;
	case 11430ULL: goto x86_l_2ca6;
	case 11432ULL: goto x86_l_2ca8;
	case 11438ULL: goto x86_l_2cae;
	case 11443ULL: goto x86_l_2cb3;
	case 11448ULL: goto x86_l_2cb8;
	case 11450ULL: goto x86_l_2cba;
	case 11456ULL: goto x86_l_2cc0;
	case 11459ULL: goto x86_l_2cc3;
	case 11465ULL: goto x86_l_2cc9;
	case 11470ULL: goto x86_l_2cce;
	case 11473ULL: goto x86_l_2cd1;
	case 11479ULL: goto x86_l_2cd7;
	case 11482ULL: goto x86_l_2cda;
	case 11485ULL: goto x86_l_2cdd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_266a:
	/* 0x266a: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_266f:
	/* 0x266f: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2674:
	/* 0x2674: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2679:
	/* 0x2679: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2680:
	/* 0x2680: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2685:
	/* 0x2685: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2688:
	/* 0x2688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268a:
	/* 0x268a: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_268d:
	/* 0x268d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2692:
	/* 0x2692: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2699:
	/* 0x2699: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_269c:
	/* 0x269c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_269e:
	/* 0x269e: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_26a1:
	/* 0x26a1: je     339e <generic_lsm_filter_arg+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13214ULL;
	}
x86_l_26a7:
	/* 0x26a7: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_26ac:
	/* 0x26ac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26af:
	/* 0x26af: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26b4:
	/* 0x26b4: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26b9:
	/* 0x26b9: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26be:
	/* 0x26be: je     33af <generic_lsm_filter_arg+0x33af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13231ULL;
	}
x86_l_26c4:
	/* 0x26c4: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_26c7:
	/* 0x26c7: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_26ca:
	/* 0x26ca: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_26cd:
	/* 0x26cd: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_26d1:
	/* 0x26d1: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_26d9:
	/* 0x26d9: jg     2726 <generic_lsm_filter_arg+0x2726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2726;
	}
x86_l_26db:
	/* 0x26db: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_26de:
	/* 0x26de: movzx  ecx,BYTE PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 152ULL);
x86_l_26e6:
	/* 0x26e6: mov    BYTE PTR [rax],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26e8:
	/* 0x26e8: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_26ec:
	/* 0x26ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26f1:
	/* 0x26f1: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26f6:
	/* 0x26f6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26fb:
	/* 0x26fb: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_26fe:
	/* 0x26fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2700:
	/* 0x2700: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2705:
	/* 0x2705: sub    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2708:
	/* 0x2708: jbe    276c <generic_lsm_filter_arg+0x276c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_276c;
	}
x86_l_270a:
	/* 0x270a: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2712:
	/* 0x2712: lea    rdi,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2716:
	/* 0x2716: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2719:
	/* 0x2719: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_271f:
	/* 0x271f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2724:
	/* 0x2724: jmp    2767 <generic_lsm_filter_arg+0x2767> */
	goto x86_l_2767;
x86_l_2726:
	/* 0x2726: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_272b:
	/* 0x272b: mov    WORD PTR [rcx],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_272f:
	/* 0x272f: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2733:
	/* 0x2733: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2738:
	/* 0x2738: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_273d:
	/* 0x273d: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_2740:
	/* 0x2740: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2742:
	/* 0x2742: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2747:
	/* 0x2747: sub    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_274a:
	/* 0x274a: jbe    276c <generic_lsm_filter_arg+0x276c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_276c;
	}
x86_l_274c:
	/* 0x274c: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2754:
	/* 0x2754: lea    rdi,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2758:
	/* 0x2758: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_275c:
	/* 0x275c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2762:
	/* 0x2762: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2767:
	/* 0x2767: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_276a:
	/* 0x276a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_276c:
	/* 0x276c: mov    eax,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2770:
	/* 0x2770: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2774:
	/* 0x2774: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2777:
	/* 0x2777: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_277c:
	/* 0x277c: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2781:
	/* 0x2781: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2786:
	/* 0x2786: jle    27c2 <generic_lsm_filter_arg+0x27c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_27c2;
	}
x86_l_2788:
	/* 0x2788: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_278b:
	/* 0x278b: jg     2c10 <generic_lsm_filter_arg+0x2c10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2c10;
	}
x86_l_2791:
	/* 0x2791: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2794:
	/* 0x2794: je     3357 <generic_lsm_filter_arg+0x3357> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13143ULL;
	}
x86_l_279a:
	/* 0x279a: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_279d:
	/* 0x279d: je     331e <generic_lsm_filter_arg+0x331e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13086ULL;
	}
x86_l_27a3:
	/* 0x27a3: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_27a6:
	/* 0x27a6: jne    2f0a <generic_lsm_filter_arg+0x2f0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12042ULL;
	}
x86_l_27ac:
	/* 0x27ac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27b1:
	/* 0x27b1: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27b6:
	/* 0x27b6: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_27bd:
	/* 0x27bd: jmp    337b <generic_lsm_filter_arg+0x337b> */
	return 13179ULL;
x86_l_27c2:
	/* 0x27c2: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_27c5:
	/* 0x27c5: jle    2ee7 <generic_lsm_filter_arg+0x2ee7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12007ULL;
	}
x86_l_27cb:
	/* 0x27cb: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_27ce:
	/* 0x27ce: je     3344 <generic_lsm_filter_arg+0x3344> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13124ULL;
	}
x86_l_27d4:
	/* 0x27d4: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_27d7:
	/* 0x27d7: je     330b <generic_lsm_filter_arg+0x330b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13067ULL;
	}
x86_l_27dd:
	/* 0x27dd: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_27e0:
	/* 0x27e0: jne    2f0a <generic_lsm_filter_arg+0x2f0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12042ULL;
	}
x86_l_27e6:
	/* 0x27e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27eb:
	/* 0x27eb: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27f0:
	/* 0x27f0: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_27f7:
	/* 0x27f7: jmp    337b <generic_lsm_filter_arg+0x337b> */
	return 13179ULL;
x86_l_27fc:
	/* 0x27fc: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_27fe:
	/* 0x27fe: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2803:
	/* 0x2803: ja     280d <generic_lsm_filter_arg+0x280d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_280d;
	}
x86_l_2805:
	/* 0x2805: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_2807:
	/* 0x2807: jbe    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 730ULL;
	}
x86_l_280d:
	/* 0x280d: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2810:
	/* 0x2810: jb     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 279ULL;
	}
x86_l_2816:
	/* 0x2816: mov    edi,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_281b:
	/* 0x281b: mov    esi,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2820:
	/* 0x2820: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2823:
	/* 0x2823: ja     2dbb <generic_lsm_filter_arg+0x2dbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11707ULL;
	}
x86_l_2829:
	/* 0x2829: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_282f:
	/* 0x282f: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2833:
	/* 0x2833: jae    2dbb <generic_lsm_filter_arg+0x2dbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11707ULL;
	}
x86_l_2839:
	/* 0x2839: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_283b:
	/* 0x283b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2840:
	/* 0x2840: jg     2dcc <generic_lsm_filter_arg+0x2dcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11724ULL;
	}
x86_l_2846:
	/* 0x2846: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_2848:
	/* 0x2848: jle    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 730ULL;
	}
x86_l_284e:
	/* 0x284e: jmp    2dcc <generic_lsm_filter_arg+0x2dcc> */
	return 11724ULL;
x86_l_2853:
	/* 0x2853: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2858:
	/* 0x2858: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_285d:
	/* 0x285d: jb     288a <generic_lsm_filter_arg+0x288a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_288a;
	}
x86_l_285f:
	/* 0x285f: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_2864:
	/* 0x2864: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_2869:
	/* 0x2869: jb     288a <generic_lsm_filter_arg+0x288a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_288a;
	}
x86_l_286b:
	/* 0x286b: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_2870:
	/* 0x2870: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_2875:
	/* 0x2875: jb     288a <generic_lsm_filter_arg+0x288a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_288a;
	}
x86_l_2877:
	/* 0x2877: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2879:
	/* 0x2879: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_287e:
	/* 0x287e: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_2881:
	/* 0x2881: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_2884:
	/* 0x2884: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_288a:
	/* 0x288a: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_2890:
	/* 0x2890: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_2896:
	/* 0x2896: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2899:
	/* 0x2899: jg     2c55 <generic_lsm_filter_arg+0x2c55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2c55;
	}
x86_l_289f:
	/* 0x289f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28a1:
	/* 0x28a1: je     3133 <generic_lsm_filter_arg+0x3133> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12595ULL;
	}
x86_l_28a7:
	/* 0x28a7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28aa:
	/* 0x28aa: jne    312c <generic_lsm_filter_arg+0x312c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12588ULL;
	}
x86_l_28b0:
	/* 0x28b0: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_28b5:
	/* 0x28b5: jmp    313f <generic_lsm_filter_arg+0x313f> */
	return 12607ULL;
x86_l_28ba:
	/* 0x28ba: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_28bd:
	/* 0x28bd: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_28c1:
	/* 0x28c1: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_28c4:
	/* 0x28c4: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_28c8:
	/* 0x28c8: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_28cb:
	/* 0x28cb: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_28ce:
	/* 0x28ce: cmp    esi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 57ULL);
x86_l_28d1:
	/* 0x28d1: jb     2fb4 <generic_lsm_filter_arg+0x2fb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12212ULL;
	}
x86_l_28d7:
	/* 0x28d7: mov    rdi,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28dc:
	/* 0x28dc: mov    rsi,QWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_28e1:
	/* 0x28e1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_28e4:
	/* 0x28e4: je     28ef <generic_lsm_filter_arg+0x28ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28ef;
	}
x86_l_28e6:
	/* 0x28e6: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_28e9:
	/* 0x28e9: jne    2ecd <generic_lsm_filter_arg+0x2ecd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11981ULL;
	}
x86_l_28ef:
	/* 0x28ef: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_28f2:
	/* 0x28f2: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_28f5:
	/* 0x28f5: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_28f8:
	/* 0x28f8: jmp    2d93 <generic_lsm_filter_arg+0x2d93> */
	return 11667ULL;
x86_l_28fd:
	/* 0x28fd: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2900:
	/* 0x2900: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2905:
	/* 0x2905: ja     2910 <generic_lsm_filter_arg+0x2910> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2910;
	}
x86_l_2907:
	/* 0x2907: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_290a:
	/* 0x290a: jbe    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 730ULL;
	}
x86_l_2910:
	/* 0x2910: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_2913:
	/* 0x2913: jb     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 279ULL;
	}
x86_l_2919:
	/* 0x2919: mov    rsi,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_291e:
	/* 0x291e: mov    rdx,QWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2923:
	/* 0x2923: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2926:
	/* 0x2926: je     2931 <generic_lsm_filter_arg+0x2931> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2931;
	}
x86_l_2928:
	/* 0x2928: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_292b:
	/* 0x292b: jne    2f20 <generic_lsm_filter_arg+0x2f20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12064ULL;
	}
x86_l_2931:
	/* 0x2931: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2934:
	/* 0x2934: jg     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 279ULL;
	}
x86_l_293a:
	/* 0x293a: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_293d:
	/* 0x293d: jle    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 730ULL;
	}
x86_l_2943:
	/* 0x2943: jmp    117 <generic_lsm_filter_arg+0x117> */
	return 279ULL;
x86_l_2948:
	/* 0x2948: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_294c:
	/* 0x294c: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_2952:
	/* 0x2952: jmp    295e <generic_lsm_filter_arg+0x295e> */
	goto x86_l_295e;
x86_l_2954:
	/* 0x2954: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2958:
	/* 0x2958: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_295e:
	/* 0x295e: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2961:
	/* 0x2961: jb     37db <generic_lsm_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14299ULL;
	}
x86_l_2967:
	/* 0x2967: mov    rsi,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_296c:
	/* 0x296c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_296f:
	/* 0x296f: jle    298d <generic_lsm_filter_arg+0x298d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_298d;
	}
x86_l_2971:
	/* 0x2971: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2974:
	/* 0x2974: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2977:
	/* 0x2977: jae    29bc <generic_lsm_filter_arg+0x29bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_29bc;
	}
x86_l_2979:
	/* 0x2979: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_297d:
	/* 0x297d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2982:
	/* 0x2982: jne    2fdc <generic_lsm_filter_arg+0x2fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12252ULL;
	}
x86_l_2988:
	/* 0x2988: jmp    367c <generic_lsm_filter_arg+0x367c> */
	return 13948ULL;
x86_l_298d:
	/* 0x298d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2990:
	/* 0x2990: je     2bf3 <generic_lsm_filter_arg+0x2bf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bf3;
	}
x86_l_2996:
	/* 0x2996: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2999:
	/* 0x2999: jne    2fdc <generic_lsm_filter_arg+0x2fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12252ULL;
	}
x86_l_299f:
	/* 0x299f: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_29a2:
	/* 0x29a2: je     29ad <generic_lsm_filter_arg+0x29ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29ad;
	}
x86_l_29a4:
	/* 0x29a4: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_29a7:
	/* 0x29a7: jne    2fd2 <generic_lsm_filter_arg+0x2fd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12242ULL;
	}
x86_l_29ad:
	/* 0x29ad: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29b1:
	/* 0x29b1: jl     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 730ULL;
	}
x86_l_29b7:
	/* 0x29b7: jmp    2fdc <generic_lsm_filter_arg+0x2fdc> */
	return 12252ULL;
x86_l_29bc:
	/* 0x29bc: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_29bf:
	/* 0x29bf: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29c4:
	/* 0x29c4: jne    2fdc <generic_lsm_filter_arg+0x2fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12252ULL;
	}
x86_l_29ca:
	/* 0x29ca: test   QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ce:
	/* 0x29ce: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_29d4:
	/* 0x29d4: jmp    2fdc <generic_lsm_filter_arg+0x2fdc> */
	return 12252ULL;
x86_l_29d9:
	/* 0x29d9: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_29dc:
	/* 0x29dc: jne    2c7e <generic_lsm_filter_arg+0x2c7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c7e;
	}
x86_l_29e2:
	/* 0x29e2: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_29e7:
	/* 0x29e7: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_29e9:
	/* 0x29e9: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_29ef:
	/* 0x29ef: jmp    2c7e <generic_lsm_filter_arg+0x2c7e> */
	goto x86_l_2c7e;
x86_l_29f4:
	/* 0x29f4: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_29f7:
	/* 0x29f7: jne    2cc0 <generic_lsm_filter_arg+0x2cc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cc0;
	}
x86_l_29fd:
	/* 0x29fd: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a02:
	/* 0x2a02: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2a04:
	/* 0x2a04: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_2a0a:
	/* 0x2a0a: jmp    2cc0 <generic_lsm_filter_arg+0x2cc0> */
	goto x86_l_2cc0;
x86_l_2a0f:
	/* 0x2a0f: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_2a12:
	/* 0x2a12: je     30fe <generic_lsm_filter_arg+0x30fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12542ULL;
	}
x86_l_2a18:
	/* 0x2a18: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_2a1b:
	/* 0x2a1b: je     30c5 <generic_lsm_filter_arg+0x30c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12485ULL;
	}
x86_l_2a21:
	/* 0x2a21: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2a24:
	/* 0x2a24: jne    97f <generic_lsm_filter_arg+0x97f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2431ULL;
	}
x86_l_2a2a:
	/* 0x2a2a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a2f:
	/* 0x2a2f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a34:
	/* 0x2a34: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_2a3b:
	/* 0x2a3b: jmp    310f <generic_lsm_filter_arg+0x310f> */
	return 12559ULL;
x86_l_2a40:
	/* 0x2a40: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2a45:
	/* 0x2a45: jmp    2a53 <generic_lsm_filter_arg+0x2a53> */
	goto x86_l_2a53;
x86_l_2a47:
	/* 0x2a47: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2a4c:
	/* 0x2a4c: jmp    2a53 <generic_lsm_filter_arg+0x2a53> */
	goto x86_l_2a53;
x86_l_2a4e:
	/* 0x2a4e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a53:
	/* 0x2a53: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2a55:
	/* 0x2a55: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2a58:
	/* 0x2a58: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2a5d:
	/* 0x2a5d: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2a60:
	/* 0x2a60: je     2b1e <generic_lsm_filter_arg+0x2b1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b1e;
	}
x86_l_2a66:
	/* 0x2a66: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2a6a:
	/* 0x2a6a: mov    DWORD PTR [rsp+0x70],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2a6e:
	/* 0x2a6e: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2a76:
	/* 0x2a76: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a7b:
	/* 0x2a7b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a80:
	/* 0x2a80: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2a87:
	/* 0x2a87: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a8c:
	/* 0x2a8c: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2a8f:
	/* 0x2a8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a91:
	/* 0x2a91: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2a94:
	/* 0x2a94: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a99:
	/* 0x2a99: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2aa0:
	/* 0x2aa0: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2aa3:
	/* 0x2aa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa5:
	/* 0x2aa5: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2aaa:
	/* 0x2aaa: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2aad:
	/* 0x2aad: je     3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14147ULL;
	}
x86_l_2ab3:
	/* 0x2ab3: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_2ab8:
	/* 0x2ab8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2abb:
	/* 0x2abb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ac0:
	/* 0x2ac0: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ac5:
	/* 0x2ac5: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2aca:
	/* 0x2aca: je     3754 <generic_lsm_filter_arg+0x3754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14164ULL;
	}
x86_l_2ad0:
	/* 0x2ad0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2ad3:
	/* 0x2ad3: mov    ebx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2ad7:
	/* 0x2ad7: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2ada:
	/* 0x2ada: jg     2b25 <generic_lsm_filter_arg+0x2b25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b25;
	}
x86_l_2adc:
	/* 0x2adc: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ae1:
	/* 0x2ae1: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ae4:
	/* 0x2ae4: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2ae8:
	/* 0x2ae8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2aed:
	/* 0x2aed: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2af2:
	/* 0x2af2: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2af4:
	/* 0x2af4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af6:
	/* 0x2af6: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2afe:
	/* 0x2afe: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b00:
	/* 0x2b00: jbe    2b68 <generic_lsm_filter_arg+0x2b68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2b68;
	}
x86_l_2b02:
	/* 0x2b02: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b07:
	/* 0x2b07: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2b0b:
	/* 0x2b0b: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2b0e:
	/* 0x2b0e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b14:
	/* 0x2b14: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b19:
	/* 0x2b19: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b1c:
	/* 0x2b1c: jmp    2b66 <generic_lsm_filter_arg+0x2b66> */
	goto x86_l_2b66;
x86_l_2b1e:
	/* 0x2b1e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b20:
	/* 0x2b20: jmp    3754 <generic_lsm_filter_arg+0x3754> */
	return 14164ULL;
x86_l_2b25:
	/* 0x2b25: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b2a:
	/* 0x2b2a: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b2d:
	/* 0x2b2d: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2b31:
	/* 0x2b31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b36:
	/* 0x2b36: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b3b:
	/* 0x2b3b: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2b3d:
	/* 0x2b3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b3f:
	/* 0x2b3f: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2b47:
	/* 0x2b47: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b49:
	/* 0x2b49: jbe    2b68 <generic_lsm_filter_arg+0x2b68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2b68;
	}
x86_l_2b4b:
	/* 0x2b4b: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b50:
	/* 0x2b50: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2b54:
	/* 0x2b54: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2b58:
	/* 0x2b58: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b5e:
	/* 0x2b5e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b63:
	/* 0x2b63: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b66:
	/* 0x2b66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b68:
	/* 0x2b68: mov    eax,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2b6c:
	/* 0x2b6c: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b70:
	/* 0x2b70: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2b73:
	/* 0x2b73: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b78:
	/* 0x2b78: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b7d:
	/* 0x2b7d: jle    2bb9 <generic_lsm_filter_arg+0x2bb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2bb9;
	}
x86_l_2b7f:
	/* 0x2b7f: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2b82:
	/* 0x2b82: jg     2d1c <generic_lsm_filter_arg+0x2d1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11548ULL;
	}
x86_l_2b88:
	/* 0x2b88: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2b8b:
	/* 0x2b8b: je     343a <generic_lsm_filter_arg+0x343a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13370ULL;
	}
x86_l_2b91:
	/* 0x2b91: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2b94:
	/* 0x2b94: je     3401 <generic_lsm_filter_arg+0x3401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13313ULL;
	}
x86_l_2b9a:
	/* 0x2b9a: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2b9d:
	/* 0x2b9d: jne    21a3 <generic_lsm_filter_arg+0x21a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8611ULL;
	}
x86_l_2ba3:
	/* 0x2ba3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ba8:
	/* 0x2ba8: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bad:
	/* 0x2bad: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2bb4:
	/* 0x2bb4: jmp    345e <generic_lsm_filter_arg+0x345e> */
	return 13406ULL;
x86_l_2bb9:
	/* 0x2bb9: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2bbc:
	/* 0x2bbc: jle    2f7f <generic_lsm_filter_arg+0x2f7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12159ULL;
	}
x86_l_2bc2:
	/* 0x2bc2: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_2bc5:
	/* 0x2bc5: je     3427 <generic_lsm_filter_arg+0x3427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13351ULL;
	}
x86_l_2bcb:
	/* 0x2bcb: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2bce:
	/* 0x2bce: je     33ee <generic_lsm_filter_arg+0x33ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13294ULL;
	}
x86_l_2bd4:
	/* 0x2bd4: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2bd7:
	/* 0x2bd7: jne    21a3 <generic_lsm_filter_arg+0x21a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8611ULL;
	}
x86_l_2bdd:
	/* 0x2bdd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2be2:
	/* 0x2be2: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2be7:
	/* 0x2be7: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2bee:
	/* 0x2bee: jmp    345e <generic_lsm_filter_arg+0x345e> */
	return 13406ULL;
x86_l_2bf3:
	/* 0x2bf3: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2bf6:
	/* 0x2bf6: je     2c01 <generic_lsm_filter_arg+0x2c01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c01;
	}
x86_l_2bf8:
	/* 0x2bf8: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2bfb:
	/* 0x2bfb: jne    2fc6 <generic_lsm_filter_arg+0x2fc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12230ULL;
	}
x86_l_2c01:
	/* 0x2c01: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c05:
	/* 0x2c05: jg     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 730ULL;
	}
x86_l_2c0b:
	/* 0x2c0b: jmp    2fdc <generic_lsm_filter_arg+0x2fdc> */
	return 12252ULL;
x86_l_2c10:
	/* 0x2c10: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_2c13:
	/* 0x2c13: je     336a <generic_lsm_filter_arg+0x336a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13162ULL;
	}
x86_l_2c19:
	/* 0x2c19: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_2c1c:
	/* 0x2c1c: je     3331 <generic_lsm_filter_arg+0x3331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13105ULL;
	}
x86_l_2c22:
	/* 0x2c22: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2c25:
	/* 0x2c25: jne    2f0a <generic_lsm_filter_arg+0x2f0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12042ULL;
	}
x86_l_2c2b:
	/* 0x2c2b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c30:
	/* 0x2c30: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c35:
	/* 0x2c35: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_2c3c:
	/* 0x2c3c: jmp    337b <generic_lsm_filter_arg+0x337b> */
	return 13179ULL;
x86_l_2c41:
	/* 0x2c41: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c46:
	/* 0x2c46: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c4b:
	/* 0x2c4b: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c50:
	/* 0x2c50: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_2c55:
	/* 0x2c55: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2c58:
	/* 0x2c58: je     313a <generic_lsm_filter_arg+0x313a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12602ULL;
	}
x86_l_2c5e:
	/* 0x2c5e: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2c61:
	/* 0x2c61: jne    312c <generic_lsm_filter_arg+0x312c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12588ULL;
	}
x86_l_2c67:
	/* 0x2c67: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2c6c:
	/* 0x2c6c: jmp    313f <generic_lsm_filter_arg+0x313f> */
	return 12607ULL;
x86_l_2c71:
	/* 0x2c71: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2c76:
	/* 0x2c76: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2c78:
	/* 0x2c78: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_2c7e:
	/* 0x2c7e: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2c81:
	/* 0x2c81: jb     37db <generic_lsm_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14299ULL;
	}
x86_l_2c87:
	/* 0x2c87: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c8c:
	/* 0x2c8c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c8f:
	/* 0x2c8f: jle    2f37 <generic_lsm_filter_arg+0x2f37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12087ULL;
	}
x86_l_2c95:
	/* 0x2c95: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2c98:
	/* 0x2c98: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2c9b:
	/* 0x2c9b: jae    3056 <generic_lsm_filter_arg+0x3056> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12374ULL;
	}
x86_l_2ca1:
	/* 0x2ca1: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2ca6:
	/* 0x2ca6: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2ca8:
	/* 0x2ca8: jne    3488 <generic_lsm_filter_arg+0x3488> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13448ULL;
	}
x86_l_2cae:
	/* 0x2cae: jmp    367c <generic_lsm_filter_arg+0x367c> */
	return 13948ULL;
x86_l_2cb3:
	/* 0x2cb3: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2cb8:
	/* 0x2cb8: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2cba:
	/* 0x2cba: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_2cc0:
	/* 0x2cc0: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2cc3:
	/* 0x2cc3: jb     37db <generic_lsm_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14299ULL;
	}
x86_l_2cc9:
	/* 0x2cc9: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cce:
	/* 0x2cce: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2cd1:
	/* 0x2cd1: jle    2f5b <generic_lsm_filter_arg+0x2f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12123ULL;
	}
x86_l_2cd7:
	/* 0x2cd7: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2cda:
	/* 0x2cda: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2cdd:
	/* 0x2cdd: jae    3071 <generic_lsm_filter_arg+0x3071> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12401ULL;
	}
	return 11491ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11491ULL: goto x86_l_2ce3;
	case 11496ULL: goto x86_l_2ce8;
	case 11498ULL: goto x86_l_2cea;
	case 11504ULL: goto x86_l_2cf0;
	case 11509ULL: goto x86_l_2cf5;
	case 11511ULL: goto x86_l_2cf7;
	case 11517ULL: goto x86_l_2cfd;
	case 11520ULL: goto x86_l_2d00;
	case 11526ULL: goto x86_l_2d06;
	case 11531ULL: goto x86_l_2d0b;
	case 11536ULL: goto x86_l_2d10;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11551ULL: goto x86_l_2d1f;
	case 11557ULL: goto x86_l_2d25;
	case 11560ULL: goto x86_l_2d28;
	case 11566ULL: goto x86_l_2d2e;
	case 11569ULL: goto x86_l_2d31;
	case 11575ULL: goto x86_l_2d37;
	case 11580ULL: goto x86_l_2d3c;
	case 11585ULL: goto x86_l_2d41;
	case 11592ULL: goto x86_l_2d48;
	case 11597ULL: goto x86_l_2d4d;
	case 11600ULL: goto x86_l_2d50;
	case 11604ULL: goto x86_l_2d54;
	case 11606ULL: goto x86_l_2d56;
	case 11610ULL: goto x86_l_2d5a;
	case 11613ULL: goto x86_l_2d5d;
	case 11616ULL: goto x86_l_2d60;
	case 11619ULL: goto x86_l_2d63;
	case 11625ULL: goto x86_l_2d69;
	case 11630ULL: goto x86_l_2d6e;
	case 11635ULL: goto x86_l_2d73;
	case 11638ULL: goto x86_l_2d76;
	case 11644ULL: goto x86_l_2d7c;
	case 11650ULL: goto x86_l_2d82;
	case 11654ULL: goto x86_l_2d86;
	case 11660ULL: goto x86_l_2d8c;
	case 11662ULL: goto x86_l_2d8e;
	case 11665ULL: goto x86_l_2d91;
	case 11667ULL: goto x86_l_2d93;
	case 11670ULL: goto x86_l_2d96;
	case 11675ULL: goto x86_l_2d9b;
	case 11677ULL: goto x86_l_2d9d;
	case 11679ULL: goto x86_l_2d9f;
	case 11684ULL: goto x86_l_2da4;
	case 11689ULL: goto x86_l_2da9;
	case 11694ULL: goto x86_l_2dae;
	case 11697ULL: goto x86_l_2db1;
	case 11702ULL: goto x86_l_2db6;
	case 11707ULL: goto x86_l_2dbb;
	case 11709ULL: goto x86_l_2dbd;
	case 11714ULL: goto x86_l_2dc2;
	case 11716ULL: goto x86_l_2dc4;
	case 11718ULL: goto x86_l_2dc6;
	case 11724ULL: goto x86_l_2dcc;
	case 11727ULL: goto x86_l_2dcf;
	case 11733ULL: goto x86_l_2dd5;
	case 11738ULL: goto x86_l_2dda;
	case 11743ULL: goto x86_l_2ddf;
	case 11746ULL: goto x86_l_2de2;
	case 11752ULL: goto x86_l_2de8;
	case 11758ULL: goto x86_l_2dee;
	case 11762ULL: goto x86_l_2df2;
	case 11768ULL: goto x86_l_2df8;
	case 11770ULL: goto x86_l_2dfa;
	case 11776ULL: goto x86_l_2e00;
	case 11778ULL: goto x86_l_2e02;
	case 11784ULL: goto x86_l_2e08;
	case 11789ULL: goto x86_l_2e0d;
	case 11793ULL: goto x86_l_2e11;
	case 11799ULL: goto x86_l_2e17;
	case 11801ULL: goto x86_l_2e19;
	case 11805ULL: goto x86_l_2e1d;
	case 11811ULL: goto x86_l_2e23;
	case 11814ULL: goto x86_l_2e26;
	case 11820ULL: goto x86_l_2e2c;
	case 11825ULL: goto x86_l_2e31;
	case 11828ULL: goto x86_l_2e34;
	case 11830ULL: goto x86_l_2e36;
	case 11833ULL: goto x86_l_2e39;
	case 11836ULL: goto x86_l_2e3c;
	case 11838ULL: goto x86_l_2e3e;
	case 11842ULL: goto x86_l_2e42;
	case 11847ULL: goto x86_l_2e47;
	case 11853ULL: goto x86_l_2e4d;
	case 11858ULL: goto x86_l_2e52;
	case 11861ULL: goto x86_l_2e55;
	case 11863ULL: goto x86_l_2e57;
	case 11866ULL: goto x86_l_2e5a;
	case 11872ULL: goto x86_l_2e60;
	case 11875ULL: goto x86_l_2e63;
	case 11881ULL: goto x86_l_2e69;
	case 11887ULL: goto x86_l_2e6f;
	case 11891ULL: goto x86_l_2e73;
	case 11897ULL: goto x86_l_2e79;
	case 11901ULL: goto x86_l_2e7d;
	case 11907ULL: goto x86_l_2e83;
	case 11912ULL: goto x86_l_2e88;
	case 11915ULL: goto x86_l_2e8b;
	case 11920ULL: goto x86_l_2e90;
	case 11926ULL: goto x86_l_2e96;
	case 11930ULL: goto x86_l_2e9a;
	case 11936ULL: goto x86_l_2ea0;
	case 11941ULL: goto x86_l_2ea5;
	case 11944ULL: goto x86_l_2ea8;
	case 11950ULL: goto x86_l_2eae;
	case 11956ULL: goto x86_l_2eb4;
	case 11960ULL: goto x86_l_2eb8;
	case 11966ULL: goto x86_l_2ebe;
	case 11970ULL: goto x86_l_2ec2;
	case 11976ULL: goto x86_l_2ec8;
	case 11981ULL: goto x86_l_2ecd;
	case 11984ULL: goto x86_l_2ed0;
	case 11987ULL: goto x86_l_2ed3;
	case 11990ULL: goto x86_l_2ed6;
	case 11995ULL: goto x86_l_2edb;
	case 11997ULL: goto x86_l_2edd;
	case 12002ULL: goto x86_l_2ee2;
	case 12007ULL: goto x86_l_2ee7;
	case 12009ULL: goto x86_l_2ee9;
	case 12015ULL: goto x86_l_2eef;
	case 12018ULL: goto x86_l_2ef2;
	case 12020ULL: goto x86_l_2ef4;
	case 12025ULL: goto x86_l_2ef9;
	case 12030ULL: goto x86_l_2efe;
	case 12037ULL: goto x86_l_2f05;
	case 12042ULL: goto x86_l_2f0a;
	case 12044ULL: goto x86_l_2f0c;
	case 12049ULL: goto x86_l_2f11;
	case 12053ULL: goto x86_l_2f15;
	case 12059ULL: goto x86_l_2f1b;
	case 12064ULL: goto x86_l_2f20;
	case 12067ULL: goto x86_l_2f23;
	case 12073ULL: goto x86_l_2f29;
	case 12076ULL: goto x86_l_2f2c;
	case 12082ULL: goto x86_l_2f32;
	case 12087ULL: goto x86_l_2f37;
	case 12090ULL: goto x86_l_2f3a;
	case 12096ULL: goto x86_l_2f40;
	case 12099ULL: goto x86_l_2f43;
	case 12105ULL: goto x86_l_2f49;
	case 12110ULL: goto x86_l_2f4e;
	case 12112ULL: goto x86_l_2f50;
	case 12118ULL: goto x86_l_2f56;
	case 12123ULL: goto x86_l_2f5b;
	case 12126ULL: goto x86_l_2f5e;
	case 12132ULL: goto x86_l_2f64;
	case 12135ULL: goto x86_l_2f67;
	case 12141ULL: goto x86_l_2f6d;
	case 12146ULL: goto x86_l_2f72;
	case 12148ULL: goto x86_l_2f74;
	case 12154ULL: goto x86_l_2f7a;
	case 12159ULL: goto x86_l_2f7f;
	case 12161ULL: goto x86_l_2f81;
	case 12167ULL: goto x86_l_2f87;
	case 12170ULL: goto x86_l_2f8a;
	case 12176ULL: goto x86_l_2f90;
	case 12181ULL: goto x86_l_2f95;
	case 12186ULL: goto x86_l_2f9a;
	case 12193ULL: goto x86_l_2fa1;
	case 12198ULL: goto x86_l_2fa6;
	case 12200ULL: goto x86_l_2fa8;
	case 12203ULL: goto x86_l_2fab;
	case 12205ULL: goto x86_l_2fad;
	case 12208ULL: goto x86_l_2fb0;
	case 12210ULL: goto x86_l_2fb2;
	case 12212ULL: goto x86_l_2fb4;
	case 12217ULL: goto x86_l_2fb9;
	case 12219ULL: goto x86_l_2fbb;
	case 12225ULL: goto x86_l_2fc1;
	case 12230ULL: goto x86_l_2fc6;
	case 12234ULL: goto x86_l_2fca;
	case 12240ULL: goto x86_l_2fd0;
	case 12242ULL: goto x86_l_2fd2;
	case 12246ULL: goto x86_l_2fd6;
	case 12252ULL: goto x86_l_2fdc;
	case 12255ULL: goto x86_l_2fdf;
	case 12261ULL: goto x86_l_2fe5;
	case 12266ULL: goto x86_l_2fea;
	case 12269ULL: goto x86_l_2fed;
	case 12271ULL: goto x86_l_2fef;
	case 12274ULL: goto x86_l_2ff2;
	case 12277ULL: goto x86_l_2ff5;
	case 12279ULL: goto x86_l_2ff7;
	case 12282ULL: goto x86_l_2ffa;
	case 12288ULL: goto x86_l_3000;
	case 12291ULL: goto x86_l_3003;
	case 12297ULL: goto x86_l_3009;
	case 12301ULL: goto x86_l_300d;
	case 12307ULL: goto x86_l_3013;
	case 12312ULL: goto x86_l_3018;
	case 12315ULL: goto x86_l_301b;
	case 12321ULL: goto x86_l_3021;
	case 12324ULL: goto x86_l_3024;
	case 12330ULL: goto x86_l_302a;
	case 12333ULL: goto x86_l_302d;
	case 12335ULL: goto x86_l_302f;
	case 12338ULL: goto x86_l_3032;
	case 12344ULL: goto x86_l_3038;
	case 12348ULL: goto x86_l_303c;
	case 12354ULL: goto x86_l_3042;
	case 12359ULL: goto x86_l_3047;
	case 12363ULL: goto x86_l_304b;
	case 12369ULL: goto x86_l_3051;
	case 12374ULL: goto x86_l_3056;
	case 12377ULL: goto x86_l_3059;
	case 12383ULL: goto x86_l_305f;
	case 12388ULL: goto x86_l_3064;
	case 12390ULL: goto x86_l_3066;
	case 12396ULL: goto x86_l_306c;
	case 12401ULL: goto x86_l_3071;
	case 12404ULL: goto x86_l_3074;
	case 12410ULL: goto x86_l_307a;
	case 12415ULL: goto x86_l_307f;
	case 12417ULL: goto x86_l_3081;
	case 12423ULL: goto x86_l_3087;
	case 12428ULL: goto x86_l_308c;
	case 12433ULL: goto x86_l_3091;
	case 12440ULL: goto x86_l_3098;
	case 12445ULL: goto x86_l_309d;
	case 12447ULL: goto x86_l_309f;
	case 12452ULL: goto x86_l_30a4;
	case 12457ULL: goto x86_l_30a9;
	case 12464ULL: goto x86_l_30b0;
	case 12466ULL: goto x86_l_30b2;
	case 12471ULL: goto x86_l_30b7;
	case 12476ULL: goto x86_l_30bc;
	case 12483ULL: goto x86_l_30c3;
	case 12485ULL: goto x86_l_30c5;
	case 12490ULL: goto x86_l_30ca;
	case 12495ULL: goto x86_l_30cf;
	case 12502ULL: goto x86_l_30d6;
	case 12504ULL: goto x86_l_30d8;
	case 12509ULL: goto x86_l_30dd;
	case 12514ULL: goto x86_l_30e2;
	case 12521ULL: goto x86_l_30e9;
	case 12523ULL: goto x86_l_30eb;
	case 12528ULL: goto x86_l_30f0;
	case 12533ULL: goto x86_l_30f5;
	case 12540ULL: goto x86_l_30fc;
	case 12542ULL: goto x86_l_30fe;
	case 12547ULL: goto x86_l_3103;
	case 12552ULL: goto x86_l_3108;
	case 12559ULL: goto x86_l_310f;
	case 12561ULL: goto x86_l_3111;
	case 12564ULL: goto x86_l_3114;
	case 12570ULL: goto x86_l_311a;
	case 12573ULL: goto x86_l_311d;
	case 12578ULL: goto x86_l_3122;
	case 12583ULL: goto x86_l_3127;
	case 12588ULL: goto x86_l_312c;
	case 12593ULL: goto x86_l_3131;
	case 12595ULL: goto x86_l_3133;
	case 12600ULL: goto x86_l_3138;
	case 12602ULL: goto x86_l_313a;
	case 12607ULL: goto x86_l_313f;
	case 12609ULL: goto x86_l_3141;
	case 12612ULL: goto x86_l_3144;
	case 12617ULL: goto x86_l_3149;
	case 12620ULL: goto x86_l_314c;
	case 12626ULL: goto x86_l_3152;
	case 12633ULL: goto x86_l_3159;
	case 12637ULL: goto x86_l_315d;
	case 12642ULL: goto x86_l_3162;
	case 12647ULL: goto x86_l_3167;
	case 12654ULL: goto x86_l_316e;
	case 12659ULL: goto x86_l_3173;
	case 12662ULL: goto x86_l_3176;
	case 12664ULL: goto x86_l_3178;
	case 12667ULL: goto x86_l_317b;
	case 12672ULL: goto x86_l_3180;
	case 12679ULL: goto x86_l_3187;
	case 12682ULL: goto x86_l_318a;
	case 12684ULL: goto x86_l_318c;
	case 12689ULL: goto x86_l_3191;
	case 12692ULL: goto x86_l_3194;
	case 12698ULL: goto x86_l_319a;
	case 12703ULL: goto x86_l_319f;
	case 12706ULL: goto x86_l_31a2;
	case 12711ULL: goto x86_l_31a7;
	case 12716ULL: goto x86_l_31ac;
	case 12721ULL: goto x86_l_31b1;
	case 12727ULL: goto x86_l_31b7;
	case 12730ULL: goto x86_l_31ba;
	case 12734ULL: goto x86_l_31be;
	case 12737ULL: goto x86_l_31c1;
	case 12739ULL: goto x86_l_31c3;
	case 12744ULL: goto x86_l_31c8;
	case 12747ULL: goto x86_l_31cb;
	case 12751ULL: goto x86_l_31cf;
	case 12756ULL: goto x86_l_31d4;
	case 12761ULL: goto x86_l_31d9;
	case 12763ULL: goto x86_l_31db;
	case 12765ULL: goto x86_l_31dd;
	case 12770ULL: goto x86_l_31e2;
	case 12772ULL: goto x86_l_31e4;
	case 12774ULL: goto x86_l_31e6;
	case 12779ULL: goto x86_l_31eb;
	case 12783ULL: goto x86_l_31ef;
	case 12786ULL: goto x86_l_31f2;
	case 12792ULL: goto x86_l_31f8;
	case 12797ULL: goto x86_l_31fd;
	case 12800ULL: goto x86_l_3200;
	case 12802ULL: goto x86_l_3202;
	case 12807ULL: goto x86_l_3207;
	case 12810ULL: goto x86_l_320a;
	case 12814ULL: goto x86_l_320e;
	case 12819ULL: goto x86_l_3213;
	case 12824ULL: goto x86_l_3218;
	case 12826ULL: goto x86_l_321a;
	case 12828ULL: goto x86_l_321c;
	case 12833ULL: goto x86_l_3221;
	case 12835ULL: goto x86_l_3223;
	case 12837ULL: goto x86_l_3225;
	case 12842ULL: goto x86_l_322a;
	case 12846ULL: goto x86_l_322e;
	case 12850ULL: goto x86_l_3232;
	case 12856ULL: goto x86_l_3238;
	case 12861ULL: goto x86_l_323d;
	case 12864ULL: goto x86_l_3240;
	case 12866ULL: goto x86_l_3242;
	case 12873ULL: goto x86_l_3249;
	case 12877ULL: goto x86_l_324d;
	case 12880ULL: goto x86_l_3250;
	case 12882ULL: goto x86_l_3252;
	case 12885ULL: goto x86_l_3255;
	case 12891ULL: goto x86_l_325b;
	case 12894ULL: goto x86_l_325e;
	case 12900ULL: goto x86_l_3264;
	case 12903ULL: goto x86_l_3267;
	case 12909ULL: goto x86_l_326d;
	case 12912ULL: goto x86_l_3270;
	case 12918ULL: goto x86_l_3276;
	case 12923ULL: goto x86_l_327b;
	case 12928ULL: goto x86_l_3280;
	case 12935ULL: goto x86_l_3287;
	case 12940ULL: goto x86_l_328c;
	case 12943ULL: goto x86_l_328f;
	case 12949ULL: goto x86_l_3295;
	case 12952ULL: goto x86_l_3298;
	case 12958ULL: goto x86_l_329e;
	case 12961ULL: goto x86_l_32a1;
	case 12967ULL: goto x86_l_32a7;
	case 12970ULL: goto x86_l_32aa;
	case 12976ULL: goto x86_l_32b0;
	case 12981ULL: goto x86_l_32b5;
	case 12986ULL: goto x86_l_32ba;
	case 12993ULL: goto x86_l_32c1;
	case 12998ULL: goto x86_l_32c6;
	case 13000ULL: goto x86_l_32c8;
	case 13006ULL: goto x86_l_32ce;
	case 13008ULL: goto x86_l_32d0;
	case 13014ULL: goto x86_l_32d6;
	case 13019ULL: goto x86_l_32db;
	case 13022ULL: goto x86_l_32de;
	case 13024ULL: goto x86_l_32e0;
	case 13027ULL: goto x86_l_32e3;
	case 13033ULL: goto x86_l_32e9;
	case 13037ULL: goto x86_l_32ed;
	case 13043ULL: goto x86_l_32f3;
	case 13048ULL: goto x86_l_32f8;
	case 13053ULL: goto x86_l_32fd;
	case 13060ULL: goto x86_l_3304;
	case 13065ULL: goto x86_l_3309;
	case 13067ULL: goto x86_l_330b;
	case 13072ULL: goto x86_l_3310;
	case 13077ULL: goto x86_l_3315;
	case 13084ULL: goto x86_l_331c;
	case 13086ULL: goto x86_l_331e;
	case 13091ULL: goto x86_l_3323;
	case 13096ULL: goto x86_l_3328;
	case 13103ULL: goto x86_l_332f;
	case 13105ULL: goto x86_l_3331;
	case 13110ULL: goto x86_l_3336;
	case 13115ULL: goto x86_l_333b;
	case 13122ULL: goto x86_l_3342;
	case 13124ULL: goto x86_l_3344;
	case 13129ULL: goto x86_l_3349;
	case 13134ULL: goto x86_l_334e;
	case 13141ULL: goto x86_l_3355;
	case 13143ULL: goto x86_l_3357;
	case 13148ULL: goto x86_l_335c;
	case 13153ULL: goto x86_l_3361;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2ce3:
	/* 0x2ce3: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ce8:
	/* 0x2ce8: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2cea:
	/* 0x2cea: jne    34d1 <generic_lsm_filter_arg+0x34d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13521ULL;
	}
x86_l_2cf0:
	/* 0x2cf0: jmp    367c <generic_lsm_filter_arg+0x367c> */
	return 13948ULL;
x86_l_2cf5:
	/* 0x2cf5: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_2cf7:
	/* 0x2cf7: je     308c <generic_lsm_filter_arg+0x308c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_308c;
	}
x86_l_2cfd:
	/* 0x2cfd: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2d00:
	/* 0x2d00: jne    97f <generic_lsm_filter_arg+0x97f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2431ULL;
	}
x86_l_2d06:
	/* 0x2d06: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d0b:
	/* 0x2d0b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d10:
	/* 0x2d10: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2d17:
	/* 0x2d17: jmp    310f <generic_lsm_filter_arg+0x310f> */
	goto x86_l_310f;
x86_l_2d1c:
	/* 0x2d1c: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_2d1f:
	/* 0x2d1f: je     344d <generic_lsm_filter_arg+0x344d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13389ULL;
	}
x86_l_2d25:
	/* 0x2d25: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_2d28:
	/* 0x2d28: je     3414 <generic_lsm_filter_arg+0x3414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13332ULL;
	}
x86_l_2d2e:
	/* 0x2d2e: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2d31:
	/* 0x2d31: jne    21a3 <generic_lsm_filter_arg+0x21a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8611ULL;
	}
x86_l_2d37:
	/* 0x2d37: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d3c:
	/* 0x2d3c: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d41:
	/* 0x2d41: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_2d48:
	/* 0x2d48: jmp    345e <generic_lsm_filter_arg+0x345e> */
	return 13406ULL;
x86_l_2d4d:
	/* 0x2d4d: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2d50:
	/* 0x2d50: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2d54:
	/* 0x2d54: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2d56:
	/* 0x2d56: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2d5a:
	/* 0x2d5a: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2d5d:
	/* 0x2d5d: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2d60:
	/* 0x2d60: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_2d63:
	/* 0x2d63: jb     2fb4 <generic_lsm_filter_arg+0x2fb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2fb4;
	}
x86_l_2d69:
	/* 0x2d69: mov    edi,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d6e:
	/* 0x2d6e: mov    esi,DWORD PTR [r12+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2d73:
	/* 0x2d73: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2d76:
	/* 0x2d76: ja     2fa6 <generic_lsm_filter_arg+0x2fa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2fa6;
	}
x86_l_2d7c:
	/* 0x2d7c: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2d82:
	/* 0x2d82: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2d86:
	/* 0x2d86: jae    2fa6 <generic_lsm_filter_arg+0x2fa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2fa6;
	}
x86_l_2d8c:
	/* 0x2d8c: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2d8e:
	/* 0x2d8e: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_2d91:
	/* 0x2d91: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2d93:
	/* 0x2d93: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_2d96:
	/* 0x2d96: jmp    2fb0 <generic_lsm_filter_arg+0x2fb0> */
	goto x86_l_2fb0;
x86_l_2d9b:
	/* 0x2d9b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d9d:
	/* 0x2d9d: jmp    2da4 <generic_lsm_filter_arg+0x2da4> */
	goto x86_l_2da4;
x86_l_2d9f:
	/* 0x2d9f: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2da4:
	/* 0x2da4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2da9:
	/* 0x2da9: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dae:
	/* 0x2dae: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_2db1:
	/* 0x2db1: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2db6:
	/* 0x2db6: jmp    3754 <generic_lsm_filter_arg+0x3754> */
	return 14164ULL;
x86_l_2dbb:
	/* 0x2dbb: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2dbd:
	/* 0x2dbd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dc2:
	/* 0x2dc2: ja     2dcc <generic_lsm_filter_arg+0x2dcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2dcc;
	}
x86_l_2dc4:
	/* 0x2dc4: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_2dc6:
	/* 0x2dc6: jbe    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 730ULL;
	}
x86_l_2dcc:
	/* 0x2dcc: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2dcf:
	/* 0x2dcf: jb     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 279ULL;
	}
x86_l_2dd5:
	/* 0x2dd5: mov    esi,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2dda:
	/* 0x2dda: mov    edx,DWORD PTR [r12+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2ddf:
	/* 0x2ddf: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2de2:
	/* 0x2de2: ja     32c6 <generic_lsm_filter_arg+0x32c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_32c6;
	}
x86_l_2de8:
	/* 0x2de8: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2dee:
	/* 0x2dee: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2df2:
	/* 0x2df2: jae    32c6 <generic_lsm_filter_arg+0x32c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_32c6;
	}
x86_l_2df8:
	/* 0x2df8: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2dfa:
	/* 0x2dfa: jg     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 279ULL;
	}
x86_l_2e00:
	/* 0x2e00: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2e02:
	/* 0x2e02: jle    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 730ULL;
	}
x86_l_2e08:
	/* 0x2e08: jmp    117 <generic_lsm_filter_arg+0x117> */
	return 279ULL;
x86_l_2e0d:
	/* 0x2e0d: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e11:
	/* 0x2e11: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_2e17:
	/* 0x2e17: jmp    2e23 <generic_lsm_filter_arg+0x2e23> */
	goto x86_l_2e23;
x86_l_2e19:
	/* 0x2e19: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e1d:
	/* 0x2e1d: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_2e23:
	/* 0x2e23: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2e26:
	/* 0x2e26: jb     37db <generic_lsm_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14299ULL;
	}
x86_l_2e2c:
	/* 0x2e2c: mov    esi,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e31:
	/* 0x2e31: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e34:
	/* 0x2e34: jle    2e52 <generic_lsm_filter_arg+0x2e52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e52;
	}
x86_l_2e36:
	/* 0x2e36: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2e39:
	/* 0x2e39: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2e3c:
	/* 0x2e3c: jae    2e88 <generic_lsm_filter_arg+0x2e88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2e88;
	}
x86_l_2e3e:
	/* 0x2e3e: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e42:
	/* 0x2e42: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e47:
	/* 0x2e47: jne    355f <generic_lsm_filter_arg+0x355f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13663ULL;
	}
x86_l_2e4d:
	/* 0x2e4d: jmp    367c <generic_lsm_filter_arg+0x367c> */
	return 13948ULL;
x86_l_2e52:
	/* 0x2e52: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e55:
	/* 0x2e55: je     2ea5 <generic_lsm_filter_arg+0x2ea5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ea5;
	}
x86_l_2e57:
	/* 0x2e57: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e5a:
	/* 0x2e5a: jne    355f <generic_lsm_filter_arg+0x355f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13663ULL;
	}
x86_l_2e60:
	/* 0x2e60: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2e63:
	/* 0x2e63: ja     3555 <generic_lsm_filter_arg+0x3555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13653ULL;
	}
x86_l_2e69:
	/* 0x2e69: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2e6f:
	/* 0x2e6f: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2e73:
	/* 0x2e73: jae    3555 <generic_lsm_filter_arg+0x3555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13653ULL;
	}
x86_l_2e79:
	/* 0x2e79: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e7d:
	/* 0x2e7d: jl     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 730ULL;
	}
x86_l_2e83:
	/* 0x2e83: jmp    355f <generic_lsm_filter_arg+0x355f> */
	return 13663ULL;
x86_l_2e88:
	/* 0x2e88: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2e8b:
	/* 0x2e8b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e90:
	/* 0x2e90: jne    355f <generic_lsm_filter_arg+0x355f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13663ULL;
	}
x86_l_2e96:
	/* 0x2e96: test   DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e9a:
	/* 0x2e9a: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_2ea0:
	/* 0x2ea0: jmp    355f <generic_lsm_filter_arg+0x355f> */
	return 13663ULL;
x86_l_2ea5:
	/* 0x2ea5: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2ea8:
	/* 0x2ea8: ja     3549 <generic_lsm_filter_arg+0x3549> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13641ULL;
	}
x86_l_2eae:
	/* 0x2eae: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2eb4:
	/* 0x2eb4: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2eb8:
	/* 0x2eb8: jae    3549 <generic_lsm_filter_arg+0x3549> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13641ULL;
	}
x86_l_2ebe:
	/* 0x2ebe: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec2:
	/* 0x2ec2: jg     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 730ULL;
	}
x86_l_2ec8:
	/* 0x2ec8: jmp    355f <generic_lsm_filter_arg+0x355f> */
	return 13663ULL;
x86_l_2ecd:
	/* 0x2ecd: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2ed0:
	/* 0x2ed0: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2ed3:
	/* 0x2ed3: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_2ed6:
	/* 0x2ed6: jmp    2fad <generic_lsm_filter_arg+0x2fad> */
	goto x86_l_2fad;
x86_l_2edb:
	/* 0x2edb: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2edd:
	/* 0x2edd: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2ee2:
	/* 0x2ee2: jmp    3754 <generic_lsm_filter_arg+0x3754> */
	return 14164ULL;
x86_l_2ee7:
	/* 0x2ee7: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_2ee9:
	/* 0x2ee9: je     32f8 <generic_lsm_filter_arg+0x32f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32f8;
	}
x86_l_2eef:
	/* 0x2eef: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2ef2:
	/* 0x2ef2: jne    2f0a <generic_lsm_filter_arg+0x2f0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f0a;
	}
x86_l_2ef4:
	/* 0x2ef4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ef9:
	/* 0x2ef9: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2efe:
	/* 0x2efe: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2f05:
	/* 0x2f05: jmp    337b <generic_lsm_filter_arg+0x337b> */
	return 13179ULL;
x86_l_2f0a:
	/* 0x2f0a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f0c:
	/* 0x2f0c: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f11:
	/* 0x2f11: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2f15:
	/* 0x2f15: jbe    33be <generic_lsm_filter_arg+0x33be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13246ULL;
	}
x86_l_2f1b:
	/* 0x2f1b: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_2f20:
	/* 0x2f20: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2f23:
	/* 0x2f23: ja     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 279ULL;
	}
x86_l_2f29:
	/* 0x2f29: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2f2c:
	/* 0x2f2c: jbe    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 730ULL;
	}
x86_l_2f32:
	/* 0x2f32: jmp    117 <generic_lsm_filter_arg+0x117> */
	return 279ULL;
x86_l_2f37:
	/* 0x2f37: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f3a:
	/* 0x2f3a: je     347b <generic_lsm_filter_arg+0x347b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13435ULL;
	}
x86_l_2f40:
	/* 0x2f40: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f43:
	/* 0x2f43: jne    3488 <generic_lsm_filter_arg+0x3488> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13448ULL;
	}
x86_l_2f49:
	/* 0x2f49: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2f4e:
	/* 0x2f4e: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2f50:
	/* 0x2f50: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_2f56:
	/* 0x2f56: jmp    3488 <generic_lsm_filter_arg+0x3488> */
	return 13448ULL;
x86_l_2f5b:
	/* 0x2f5b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f5e:
	/* 0x2f5e: je     34c4 <generic_lsm_filter_arg+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13508ULL;
	}
x86_l_2f64:
	/* 0x2f64: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f67:
	/* 0x2f67: jne    34d1 <generic_lsm_filter_arg+0x34d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13521ULL;
	}
x86_l_2f6d:
	/* 0x2f6d: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f72:
	/* 0x2f72: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2f74:
	/* 0x2f74: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_2f7a:
	/* 0x2f7a: jmp    34d1 <generic_lsm_filter_arg+0x34d1> */
	return 13521ULL;
x86_l_2f7f:
	/* 0x2f7f: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_2f81:
	/* 0x2f81: je     33db <generic_lsm_filter_arg+0x33db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13275ULL;
	}
x86_l_2f87:
	/* 0x2f87: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2f8a:
	/* 0x2f8a: jne    21a3 <generic_lsm_filter_arg+0x21a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8611ULL;
	}
x86_l_2f90:
	/* 0x2f90: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f95:
	/* 0x2f95: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f9a:
	/* 0x2f9a: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2fa1:
	/* 0x2fa1: jmp    345e <generic_lsm_filter_arg+0x345e> */
	return 13406ULL;
x86_l_2fa6:
	/* 0x2fa6: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2fa8:
	/* 0x2fa8: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2fab:
	/* 0x2fab: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2fad:
	/* 0x2fad: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_2fb0:
	/* 0x2fb0: and    dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2fb2:
	/* 0x2fb2: or     al,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2fb4:
	/* 0x2fb4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fb9:
	/* 0x2fb9: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2fbb:
	/* 0x2fbb: je     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 730ULL;
	}
x86_l_2fc1:
	/* 0x2fc1: jmp    117 <generic_lsm_filter_arg+0x117> */
	return 279ULL;
x86_l_2fc6:
	/* 0x2fc6: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fca:
	/* 0x2fca: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_2fd0:
	/* 0x2fd0: jmp    2fdc <generic_lsm_filter_arg+0x2fdc> */
	goto x86_l_2fdc;
x86_l_2fd2:
	/* 0x2fd2: cmp    QWORD PTR [r13+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fd6:
	/* 0x2fd6: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_2fdc:
	/* 0x2fdc: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2fdf:
	/* 0x2fdf: jb     37db <generic_lsm_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14299ULL;
	}
x86_l_2fe5:
	/* 0x2fe5: mov    rdx,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2fea:
	/* 0x2fea: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2fed:
	/* 0x2fed: jle    3018 <generic_lsm_filter_arg+0x3018> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3018;
	}
x86_l_2fef:
	/* 0x2fef: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2ff2:
	/* 0x2ff2: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2ff5:
	/* 0x2ff5: jb     3047 <generic_lsm_filter_arg+0x3047> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3047;
	}
x86_l_2ff7:
	/* 0x2ff7: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2ffa:
	/* 0x2ffa: je     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 730ULL;
	}
x86_l_3000:
	/* 0x3000: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3003:
	/* 0x3003: jne    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_3009:
	/* 0x3009: test   QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_300d:
	/* 0x300d: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_3013:
	/* 0x3013: jmp    37db <generic_lsm_filter_arg+0x37db> */
	return 14299ULL;
x86_l_3018:
	/* 0x3018: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_301b:
	/* 0x301b: je     32db <generic_lsm_filter_arg+0x32db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32db;
	}
x86_l_3021:
	/* 0x3021: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3024:
	/* 0x3024: jne    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_302a:
	/* 0x302a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_302d:
	/* 0x302d: je     3038 <generic_lsm_filter_arg+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3038;
	}
x86_l_302f:
	/* 0x302f: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_3032:
	/* 0x3032: jne    3689 <generic_lsm_filter_arg+0x3689> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13961ULL;
	}
x86_l_3038:
	/* 0x3038: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_303c:
	/* 0x303c: jl     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 730ULL;
	}
x86_l_3042:
	/* 0x3042: jmp    37db <generic_lsm_filter_arg+0x37db> */
	return 14299ULL;
x86_l_3047:
	/* 0x3047: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_304b:
	/* 0x304b: je     367c <generic_lsm_filter_arg+0x367c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13948ULL;
	}
x86_l_3051:
	/* 0x3051: jmp    37db <generic_lsm_filter_arg+0x37db> */
	return 14299ULL;
x86_l_3056:
	/* 0x3056: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3059:
	/* 0x3059: jne    3488 <generic_lsm_filter_arg+0x3488> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13448ULL;
	}
x86_l_305f:
	/* 0x305f: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3064:
	/* 0x3064: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_3066:
	/* 0x3066: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_306c:
	/* 0x306c: jmp    3488 <generic_lsm_filter_arg+0x3488> */
	return 13448ULL;
x86_l_3071:
	/* 0x3071: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3074:
	/* 0x3074: jne    34d1 <generic_lsm_filter_arg+0x34d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13521ULL;
	}
x86_l_307a:
	/* 0x307a: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_307f:
	/* 0x307f: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_3081:
	/* 0x3081: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_3087:
	/* 0x3087: jmp    34d1 <generic_lsm_filter_arg+0x34d1> */
	return 13521ULL;
x86_l_308c:
	/* 0x308c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3091:
	/* 0x3091: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_3098:
	/* 0x3098: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_309d:
	/* 0x309d: jmp    310f <generic_lsm_filter_arg+0x310f> */
	goto x86_l_310f;
x86_l_309f:
	/* 0x309f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30a4:
	/* 0x30a4: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30a9:
	/* 0x30a9: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_30b0:
	/* 0x30b0: jmp    310f <generic_lsm_filter_arg+0x310f> */
	goto x86_l_310f;
x86_l_30b2:
	/* 0x30b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30b7:
	/* 0x30b7: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30bc:
	/* 0x30bc: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_30c3:
	/* 0x30c3: jmp    310f <generic_lsm_filter_arg+0x310f> */
	goto x86_l_310f;
x86_l_30c5:
	/* 0x30c5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30ca:
	/* 0x30ca: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30cf:
	/* 0x30cf: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_30d6:
	/* 0x30d6: jmp    310f <generic_lsm_filter_arg+0x310f> */
	goto x86_l_310f;
x86_l_30d8:
	/* 0x30d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30dd:
	/* 0x30dd: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30e2:
	/* 0x30e2: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_30e9:
	/* 0x30e9: jmp    310f <generic_lsm_filter_arg+0x310f> */
	goto x86_l_310f;
x86_l_30eb:
	/* 0x30eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30f0:
	/* 0x30f0: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30f5:
	/* 0x30f5: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_30fc:
	/* 0x30fc: jmp    310f <generic_lsm_filter_arg+0x310f> */
	goto x86_l_310f;
x86_l_30fe:
	/* 0x30fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3103:
	/* 0x3103: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3108:
	/* 0x3108: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_310f:
	/* 0x310f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3111:
	/* 0x3111: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3114:
	/* 0x3114: je     339e <generic_lsm_filter_arg+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13214ULL;
	}
x86_l_311a:
	/* 0x311a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_311d:
	/* 0x311d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3122:
	/* 0x3122: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3127:
	/* 0x3127: jmp    3392 <generic_lsm_filter_arg+0x3392> */
	return 13202ULL;
x86_l_312c:
	/* 0x312c: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_3131:
	/* 0x3131: jmp    313f <generic_lsm_filter_arg+0x313f> */
	goto x86_l_313f;
x86_l_3133:
	/* 0x3133: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3138:
	/* 0x3138: jmp    313f <generic_lsm_filter_arg+0x313f> */
	goto x86_l_313f;
x86_l_313a:
	/* 0x313a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_313f:
	/* 0x313f: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_3141:
	/* 0x3141: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_3144:
	/* 0x3144: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_3149:
	/* 0x3149: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_314c:
	/* 0x314c: je     3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14147ULL;
	}
x86_l_3152:
	/* 0x3152: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3159:
	/* 0x3159: mov    DWORD PTR [rsp+0x6c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_315d:
	/* 0x315d: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3162:
	/* 0x3162: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3167:
	/* 0x3167: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_316e:
	/* 0x316e: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3173:
	/* 0x3173: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_3176:
	/* 0x3176: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3178:
	/* 0x3178: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_317b:
	/* 0x317b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3180:
	/* 0x3180: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3187:
	/* 0x3187: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_318a:
	/* 0x318a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_318c:
	/* 0x318c: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3191:
	/* 0x3191: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3194:
	/* 0x3194: je     3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14147ULL;
	}
x86_l_319a:
	/* 0x319a: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_319f:
	/* 0x319f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31a2:
	/* 0x31a2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31a7:
	/* 0x31a7: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31ac:
	/* 0x31ac: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31b1:
	/* 0x31b1: je     3754 <generic_lsm_filter_arg+0x3754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14164ULL;
	}
x86_l_31b7:
	/* 0x31b7: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_31ba:
	/* 0x31ba: mov    ebx,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_31be:
	/* 0x31be: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_31c1:
	/* 0x31c1: jg     3202 <generic_lsm_filter_arg+0x3202> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3202;
	}
x86_l_31c3:
	/* 0x31c3: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31c8:
	/* 0x31c8: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31cb:
	/* 0x31cb: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_31cf:
	/* 0x31cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31d4:
	/* 0x31d4: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31d9:
	/* 0x31d9: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_31db:
	/* 0x31db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31dd:
	/* 0x31dd: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_31e2:
	/* 0x31e2: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31e4:
	/* 0x31e4: jbe    3242 <generic_lsm_filter_arg+0x3242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3242;
	}
x86_l_31e6:
	/* 0x31e6: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31eb:
	/* 0x31eb: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_31ef:
	/* 0x31ef: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_31f2:
	/* 0x31f2: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_31f8:
	/* 0x31f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31fd:
	/* 0x31fd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3200:
	/* 0x3200: jmp    3240 <generic_lsm_filter_arg+0x3240> */
	goto x86_l_3240;
x86_l_3202:
	/* 0x3202: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3207:
	/* 0x3207: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_320a:
	/* 0x320a: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_320e:
	/* 0x320e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3213:
	/* 0x3213: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3218:
	/* 0x3218: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_321a:
	/* 0x321a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_321c:
	/* 0x321c: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3221:
	/* 0x3221: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3223:
	/* 0x3223: jbe    3242 <generic_lsm_filter_arg+0x3242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3242;
	}
x86_l_3225:
	/* 0x3225: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_322a:
	/* 0x322a: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_322e:
	/* 0x322e: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3232:
	/* 0x3232: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3238:
	/* 0x3238: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_323d:
	/* 0x323d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3240:
	/* 0x3240: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3242:
	/* 0x3242: mov    eax,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3249:
	/* 0x3249: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_324d:
	/* 0x324d: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3250:
	/* 0x3250: jle    328c <generic_lsm_filter_arg+0x328c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_328c;
	}
x86_l_3252:
	/* 0x3252: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_3255:
	/* 0x3255: jg     3518 <generic_lsm_filter_arg+0x3518> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13592ULL;
	}
x86_l_325b:
	/* 0x325b: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_325e:
	/* 0x325e: je     3706 <generic_lsm_filter_arg+0x3706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14086ULL;
	}
x86_l_3264:
	/* 0x3264: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3267:
	/* 0x3267: je     36cd <generic_lsm_filter_arg+0x36cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14029ULL;
	}
x86_l_326d:
	/* 0x326d: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_3270:
	/* 0x3270: jne    3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14147ULL;
	}
x86_l_3276:
	/* 0x3276: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_327b:
	/* 0x327b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3280:
	/* 0x3280: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_3287:
	/* 0x3287: jmp    372a <generic_lsm_filter_arg+0x372a> */
	return 14122ULL;
x86_l_328c:
	/* 0x328c: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_328f:
	/* 0x328f: jle    3604 <generic_lsm_filter_arg+0x3604> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 13828ULL;
	}
x86_l_3295:
	/* 0x3295: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_3298:
	/* 0x3298: je     36f3 <generic_lsm_filter_arg+0x36f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14067ULL;
	}
x86_l_329e:
	/* 0x329e: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_32a1:
	/* 0x32a1: je     36ba <generic_lsm_filter_arg+0x36ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14010ULL;
	}
x86_l_32a7:
	/* 0x32a7: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_32aa:
	/* 0x32aa: jne    3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14147ULL;
	}
x86_l_32b0:
	/* 0x32b0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32b5:
	/* 0x32b5: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_32ba:
	/* 0x32ba: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_32c1:
	/* 0x32c1: jmp    372a <generic_lsm_filter_arg+0x372a> */
	return 14122ULL;
x86_l_32c6:
	/* 0x32c6: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_32c8:
	/* 0x32c8: ja     117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 279ULL;
	}
x86_l_32ce:
	/* 0x32ce: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_32d0:
	/* 0x32d0: jbe    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 730ULL;
	}
x86_l_32d6:
	/* 0x32d6: jmp    117 <generic_lsm_filter_arg+0x117> */
	return 279ULL;
x86_l_32db:
	/* 0x32db: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_32de:
	/* 0x32de: je     32e9 <generic_lsm_filter_arg+0x32e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32e9;
	}
x86_l_32e0:
	/* 0x32e0: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_32e3:
	/* 0x32e3: jne    3698 <generic_lsm_filter_arg+0x3698> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13976ULL;
	}
x86_l_32e9:
	/* 0x32e9: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32ed:
	/* 0x32ed: jg     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 730ULL;
	}
x86_l_32f3:
	/* 0x32f3: jmp    37db <generic_lsm_filter_arg+0x37db> */
	return 14299ULL;
x86_l_32f8:
	/* 0x32f8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32fd:
	/* 0x32fd: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_3304:
	/* 0x3304: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3309:
	/* 0x3309: jmp    337b <generic_lsm_filter_arg+0x337b> */
	return 13179ULL;
x86_l_330b:
	/* 0x330b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3310:
	/* 0x3310: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3315:
	/* 0x3315: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_331c:
	/* 0x331c: jmp    337b <generic_lsm_filter_arg+0x337b> */
	return 13179ULL;
x86_l_331e:
	/* 0x331e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3323:
	/* 0x3323: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3328:
	/* 0x3328: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_332f:
	/* 0x332f: jmp    337b <generic_lsm_filter_arg+0x337b> */
	return 13179ULL;
x86_l_3331:
	/* 0x3331: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3336:
	/* 0x3336: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_333b:
	/* 0x333b: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_3342:
	/* 0x3342: jmp    337b <generic_lsm_filter_arg+0x337b> */
	return 13179ULL;
x86_l_3344:
	/* 0x3344: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3349:
	/* 0x3349: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_334e:
	/* 0x334e: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3355:
	/* 0x3355: jmp    337b <generic_lsm_filter_arg+0x337b> */
	return 13179ULL;
x86_l_3357:
	/* 0x3357: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_335c:
	/* 0x335c: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3361:
	/* 0x3361: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
	return 13160ULL;
}

static __noinline __u64 tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13160ULL: goto x86_l_3368;
	case 13162ULL: goto x86_l_336a;
	case 13167ULL: goto x86_l_336f;
	case 13172ULL: goto x86_l_3374;
	case 13179ULL: goto x86_l_337b;
	case 13181ULL: goto x86_l_337d;
	case 13184ULL: goto x86_l_3380;
	case 13186ULL: goto x86_l_3382;
	case 13189ULL: goto x86_l_3385;
	case 13194ULL: goto x86_l_338a;
	case 13202ULL: goto x86_l_3392;
	case 13204ULL: goto x86_l_3394;
	case 13206ULL: goto x86_l_3396;
	case 13209ULL: goto x86_l_3399;
	case 13212ULL: goto x86_l_339c;
	case 13214ULL: goto x86_l_339e;
	case 13216ULL: goto x86_l_33a0;
	case 13221ULL: goto x86_l_33a5;
	case 13226ULL: goto x86_l_33aa;
	case 13231ULL: goto x86_l_33af;
	case 13236ULL: goto x86_l_33b4;
	case 13240ULL: goto x86_l_33b8;
	case 13246ULL: goto x86_l_33be;
	case 13256ULL: goto x86_l_33c8;
	case 13260ULL: goto x86_l_33cc;
	case 13266ULL: goto x86_l_33d2;
	case 13270ULL: goto x86_l_33d6;
	case 13275ULL: goto x86_l_33db;
	case 13280ULL: goto x86_l_33e0;
	case 13287ULL: goto x86_l_33e7;
	case 13292ULL: goto x86_l_33ec;
	case 13294ULL: goto x86_l_33ee;
	case 13299ULL: goto x86_l_33f3;
	case 13304ULL: goto x86_l_33f8;
	case 13311ULL: goto x86_l_33ff;
	case 13313ULL: goto x86_l_3401;
	case 13318ULL: goto x86_l_3406;
	case 13323ULL: goto x86_l_340b;
	case 13330ULL: goto x86_l_3412;
	case 13332ULL: goto x86_l_3414;
	case 13337ULL: goto x86_l_3419;
	case 13342ULL: goto x86_l_341e;
	case 13349ULL: goto x86_l_3425;
	case 13351ULL: goto x86_l_3427;
	case 13356ULL: goto x86_l_342c;
	case 13361ULL: goto x86_l_3431;
	case 13368ULL: goto x86_l_3438;
	case 13370ULL: goto x86_l_343a;
	case 13375ULL: goto x86_l_343f;
	case 13380ULL: goto x86_l_3444;
	case 13387ULL: goto x86_l_344b;
	case 13389ULL: goto x86_l_344d;
	case 13394ULL: goto x86_l_3452;
	case 13399ULL: goto x86_l_3457;
	case 13406ULL: goto x86_l_345e;
	case 13408ULL: goto x86_l_3460;
	case 13411ULL: goto x86_l_3463;
	case 13417ULL: goto x86_l_3469;
	case 13420ULL: goto x86_l_346c;
	case 13425ULL: goto x86_l_3471;
	case 13430ULL: goto x86_l_3476;
	case 13435ULL: goto x86_l_347b;
	case 13440ULL: goto x86_l_3480;
	case 13442ULL: goto x86_l_3482;
	case 13448ULL: goto x86_l_3488;
	case 13451ULL: goto x86_l_348b;
	case 13457ULL: goto x86_l_3491;
	case 13462ULL: goto x86_l_3496;
	case 13465ULL: goto x86_l_3499;
	case 13471ULL: goto x86_l_349f;
	case 13474ULL: goto x86_l_34a2;
	case 13477ULL: goto x86_l_34a5;
	case 13483ULL: goto x86_l_34ab;
	case 13486ULL: goto x86_l_34ae;
	case 13492ULL: goto x86_l_34b4;
	case 13495ULL: goto x86_l_34b7;
	case 13501ULL: goto x86_l_34bd;
	case 13506ULL: goto x86_l_34c2;
	case 13508ULL: goto x86_l_34c4;
	case 13513ULL: goto x86_l_34c9;
	case 13515ULL: goto x86_l_34cb;
	case 13521ULL: goto x86_l_34d1;
	case 13524ULL: goto x86_l_34d4;
	case 13530ULL: goto x86_l_34da;
	case 13535ULL: goto x86_l_34df;
	case 13538ULL: goto x86_l_34e2;
	case 13544ULL: goto x86_l_34e8;
	case 13547ULL: goto x86_l_34eb;
	case 13550ULL: goto x86_l_34ee;
	case 13556ULL: goto x86_l_34f4;
	case 13559ULL: goto x86_l_34f7;
	case 13565ULL: goto x86_l_34fd;
	case 13568ULL: goto x86_l_3500;
	case 13574ULL: goto x86_l_3506;
	case 13579ULL: goto x86_l_350b;
	case 13581ULL: goto x86_l_350d;
	case 13587ULL: goto x86_l_3513;
	case 13592ULL: goto x86_l_3518;
	case 13595ULL: goto x86_l_351b;
	case 13601ULL: goto x86_l_3521;
	case 13604ULL: goto x86_l_3524;
	case 13610ULL: goto x86_l_352a;
	case 13613ULL: goto x86_l_352d;
	case 13619ULL: goto x86_l_3533;
	case 13624ULL: goto x86_l_3538;
	case 13629ULL: goto x86_l_353d;
	case 13636ULL: goto x86_l_3544;
	case 13641ULL: goto x86_l_3549;
	case 13645ULL: goto x86_l_354d;
	case 13651ULL: goto x86_l_3553;
	case 13653ULL: goto x86_l_3555;
	case 13657ULL: goto x86_l_3559;
	case 13663ULL: goto x86_l_355f;
	case 13666ULL: goto x86_l_3562;
	case 13672ULL: goto x86_l_3568;
	case 13677ULL: goto x86_l_356d;
	case 13680ULL: goto x86_l_3570;
	case 13682ULL: goto x86_l_3572;
	case 13685ULL: goto x86_l_3575;
	case 13688ULL: goto x86_l_3578;
	case 13690ULL: goto x86_l_357a;
	case 13693ULL: goto x86_l_357d;
	case 13699ULL: goto x86_l_3583;
	case 13702ULL: goto x86_l_3586;
	case 13708ULL: goto x86_l_358c;
	case 13712ULL: goto x86_l_3590;
	case 13718ULL: goto x86_l_3596;
	case 13723ULL: goto x86_l_359b;
	case 13726ULL: goto x86_l_359e;
	case 13728ULL: goto x86_l_35a0;
	case 13731ULL: goto x86_l_35a3;
	case 13737ULL: goto x86_l_35a9;
	case 13740ULL: goto x86_l_35ac;
	case 13746ULL: goto x86_l_35b2;
	case 13751ULL: goto x86_l_35b7;
	case 13754ULL: goto x86_l_35ba;
	case 13760ULL: goto x86_l_35c0;
	case 13764ULL: goto x86_l_35c4;
	case 13770ULL: goto x86_l_35ca;
	case 13775ULL: goto x86_l_35cf;
	case 13779ULL: goto x86_l_35d3;
	case 13785ULL: goto x86_l_35d9;
	case 13790ULL: goto x86_l_35de;
	case 13793ULL: goto x86_l_35e1;
	case 13799ULL: goto x86_l_35e7;
	case 13804ULL: goto x86_l_35ec;
	case 13807ULL: goto x86_l_35ef;
	case 13813ULL: goto x86_l_35f5;
	case 13817ULL: goto x86_l_35f9;
	case 13823ULL: goto x86_l_35ff;
	case 13828ULL: goto x86_l_3604;
	case 13830ULL: goto x86_l_3606;
	case 13836ULL: goto x86_l_360c;
	case 13839ULL: goto x86_l_360f;
	case 13845ULL: goto x86_l_3615;
	case 13850ULL: goto x86_l_361a;
	case 13855ULL: goto x86_l_361f;
	case 13862ULL: goto x86_l_3626;
	case 13867ULL: goto x86_l_362b;
	case 13870ULL: goto x86_l_362e;
	case 13876ULL: goto x86_l_3634;
	case 13879ULL: goto x86_l_3637;
	case 13885ULL: goto x86_l_363d;
	case 13890ULL: goto x86_l_3642;
	case 13892ULL: goto x86_l_3644;
	case 13895ULL: goto x86_l_3647;
	case 13901ULL: goto x86_l_364d;
	case 13904ULL: goto x86_l_3650;
	case 13910ULL: goto x86_l_3656;
	case 13915ULL: goto x86_l_365b;
	case 13917ULL: goto x86_l_365d;
	case 13923ULL: goto x86_l_3663;
	case 13928ULL: goto x86_l_3668;
	case 13933ULL: goto x86_l_366d;
	case 13935ULL: goto x86_l_366f;
	case 13940ULL: goto x86_l_3674;
	case 13942ULL: goto x86_l_3676;
	case 13948ULL: goto x86_l_367c;
	case 13950ULL: goto x86_l_367e;
	case 13953ULL: goto x86_l_3681;
	case 13956ULL: goto x86_l_3684;
	case 13961ULL: goto x86_l_3689;
	case 13965ULL: goto x86_l_368d;
	case 13971ULL: goto x86_l_3693;
	case 13976ULL: goto x86_l_3698;
	case 13980ULL: goto x86_l_369c;
	case 13986ULL: goto x86_l_36a2;
	case 13991ULL: goto x86_l_36a7;
	case 13996ULL: goto x86_l_36ac;
	case 14003ULL: goto x86_l_36b3;
	case 14008ULL: goto x86_l_36b8;
	case 14010ULL: goto x86_l_36ba;
	case 14015ULL: goto x86_l_36bf;
	case 14020ULL: goto x86_l_36c4;
	case 14027ULL: goto x86_l_36cb;
	case 14029ULL: goto x86_l_36cd;
	case 14034ULL: goto x86_l_36d2;
	case 14039ULL: goto x86_l_36d7;
	case 14046ULL: goto x86_l_36de;
	case 14048ULL: goto x86_l_36e0;
	case 14053ULL: goto x86_l_36e5;
	case 14058ULL: goto x86_l_36ea;
	case 14065ULL: goto x86_l_36f1;
	case 14067ULL: goto x86_l_36f3;
	case 14072ULL: goto x86_l_36f8;
	case 14077ULL: goto x86_l_36fd;
	case 14084ULL: goto x86_l_3704;
	case 14086ULL: goto x86_l_3706;
	case 14091ULL: goto x86_l_370b;
	case 14096ULL: goto x86_l_3710;
	case 14103ULL: goto x86_l_3717;
	case 14105ULL: goto x86_l_3719;
	case 14110ULL: goto x86_l_371e;
	case 14115ULL: goto x86_l_3723;
	case 14122ULL: goto x86_l_372a;
	case 14124ULL: goto x86_l_372c;
	case 14127ULL: goto x86_l_372f;
	case 14129ULL: goto x86_l_3731;
	case 14132ULL: goto x86_l_3734;
	case 14137ULL: goto x86_l_3739;
	case 14142ULL: goto x86_l_373e;
	case 14147ULL: goto x86_l_3743;
	case 14149ULL: goto x86_l_3745;
	case 14154ULL: goto x86_l_374a;
	case 14159ULL: goto x86_l_374f;
	case 14164ULL: goto x86_l_3754;
	case 14169ULL: goto x86_l_3759;
	case 14173ULL: goto x86_l_375d;
	case 14179ULL: goto x86_l_3763;
	case 14189ULL: goto x86_l_376d;
	case 14193ULL: goto x86_l_3771;
	case 14199ULL: goto x86_l_3777;
	case 14201ULL: goto x86_l_3779;
	case 14204ULL: goto x86_l_377c;
	case 14207ULL: goto x86_l_377f;
	case 14210ULL: goto x86_l_3782;
	case 14215ULL: goto x86_l_3787;
	case 14217ULL: goto x86_l_3789;
	case 14222ULL: goto x86_l_378e;
	case 14227ULL: goto x86_l_3793;
	case 14230ULL: goto x86_l_3796;
	case 14235ULL: goto x86_l_379b;
	case 14240ULL: goto x86_l_37a0;
	case 14244ULL: goto x86_l_37a4;
	case 14250ULL: goto x86_l_37aa;
	case 14255ULL: goto x86_l_37af;
	case 14260ULL: goto x86_l_37b4;
	case 14262ULL: goto x86_l_37b6;
	case 14267ULL: goto x86_l_37bb;
	case 14269ULL: goto x86_l_37bd;
	case 14275ULL: goto x86_l_37c3;
	case 14277ULL: goto x86_l_37c5;
	case 14281ULL: goto x86_l_37c9;
	case 14287ULL: goto x86_l_37cf;
	case 14289ULL: goto x86_l_37d1;
	case 14293ULL: goto x86_l_37d5;
	case 14299ULL: goto x86_l_37db;
	case 14302ULL: goto x86_l_37de;
	case 14305ULL: goto x86_l_37e1;
	case 14311ULL: goto x86_l_37e7;
	case 14316ULL: goto x86_l_37ec;
	case 14321ULL: goto x86_l_37f1;
	case 14324ULL: goto x86_l_37f4;
	case 14326ULL: goto x86_l_37f6;
	case 14327ULL: goto x86_l_37f7;
	case 14329ULL: goto x86_l_37f9;
	case 14331ULL: goto x86_l_37fb;
	case 14334ULL: goto x86_l_37fe;
	case 14337ULL: goto x86_l_3801;
	case 14340ULL: goto x86_l_3804;
	case 14342ULL: goto x86_l_3806;
	case 14345ULL: goto x86_l_3809;
	case 14349ULL: goto x86_l_380d;
	case 14352ULL: goto x86_l_3810;
	case 14354ULL: goto x86_l_3812;
	case 14359ULL: goto x86_l_3817;
	case 14362ULL: goto x86_l_381a;
	case 14364ULL: goto x86_l_381c;
	case 14369ULL: goto x86_l_3821;
	case 14373ULL: goto x86_l_3825;
	case 14376ULL: goto x86_l_3828;
	case 14379ULL: goto x86_l_382b;
	case 14383ULL: goto x86_l_382f;
	case 14387ULL: goto x86_l_3833;
	case 14391ULL: goto x86_l_3837;
	case 14394ULL: goto x86_l_383a;
	case 14398ULL: goto x86_l_383e;
	case 14402ULL: goto x86_l_3842;
	case 14406ULL: goto x86_l_3846;
	case 14409ULL: goto x86_l_3849;
	case 14411ULL: goto x86_l_384b;
	case 14415ULL: goto x86_l_384f;
	case 14419ULL: goto x86_l_3853;
	case 14422ULL: goto x86_l_3856;
	case 14424ULL: goto x86_l_3858;
	case 14426ULL: goto x86_l_385a;
	case 14428ULL: goto x86_l_385c;
	case 14429ULL: goto x86_l_385d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3368:
	/* 0x3368: jmp    337b <generic_lsm_filter_arg+0x337b> */
	goto x86_l_337b;
x86_l_336a:
	/* 0x336a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_336f:
	/* 0x336f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3374:
	/* 0x3374: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_337b:
	/* 0x337b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_337d:
	/* 0x337d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3380:
	/* 0x3380: je     339e <generic_lsm_filter_arg+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_339e;
	}
x86_l_3382:
	/* 0x3382: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3385:
	/* 0x3385: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_338a:
	/* 0x338a: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3392:
	/* 0x3392: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3394:
	/* 0x3394: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3396:
	/* 0x3396: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3399:
	/* 0x3399: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_339c:
	/* 0x339c: jmp    33a0 <generic_lsm_filter_arg+0x33a0> */
	goto x86_l_33a0;
x86_l_339e:
	/* 0x339e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33a0:
	/* 0x33a0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33a5:
	/* 0x33a5: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33aa:
	/* 0x33aa: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33af:
	/* 0x33af: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_33b4:
	/* 0x33b4: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_33b8:
	/* 0x33b8: ja     2c9 <generic_lsm_filter_arg+0x2c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 713ULL;
	}
x86_l_33be:
	/* 0x33be: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_33c8:
	/* 0x33c8: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_33cc:
	/* 0x33cc: jae    2c9 <generic_lsm_filter_arg+0x2c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 713ULL;
	}
x86_l_33d2:
	/* 0x33d2: xor    rbx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_33d6:
	/* 0x33d6: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_33db:
	/* 0x33db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33e0:
	/* 0x33e0: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_33e7:
	/* 0x33e7: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_33ec:
	/* 0x33ec: jmp    345e <generic_lsm_filter_arg+0x345e> */
	goto x86_l_345e;
x86_l_33ee:
	/* 0x33ee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33f3:
	/* 0x33f3: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_33f8:
	/* 0x33f8: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_33ff:
	/* 0x33ff: jmp    345e <generic_lsm_filter_arg+0x345e> */
	goto x86_l_345e;
x86_l_3401:
	/* 0x3401: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3406:
	/* 0x3406: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_340b:
	/* 0x340b: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_3412:
	/* 0x3412: jmp    345e <generic_lsm_filter_arg+0x345e> */
	goto x86_l_345e;
x86_l_3414:
	/* 0x3414: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3419:
	/* 0x3419: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_341e:
	/* 0x341e: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_3425:
	/* 0x3425: jmp    345e <generic_lsm_filter_arg+0x345e> */
	goto x86_l_345e;
x86_l_3427:
	/* 0x3427: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_342c:
	/* 0x342c: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3431:
	/* 0x3431: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3438:
	/* 0x3438: jmp    345e <generic_lsm_filter_arg+0x345e> */
	goto x86_l_345e;
x86_l_343a:
	/* 0x343a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_343f:
	/* 0x343f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3444:
	/* 0x3444: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_344b:
	/* 0x344b: jmp    345e <generic_lsm_filter_arg+0x345e> */
	goto x86_l_345e;
x86_l_344d:
	/* 0x344d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3452:
	/* 0x3452: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3457:
	/* 0x3457: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_345e:
	/* 0x345e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3460:
	/* 0x3460: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3463:
	/* 0x3463: je     3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3743;
	}
x86_l_3469:
	/* 0x3469: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_346c:
	/* 0x346c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3471:
	/* 0x3471: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3476:
	/* 0x3476: jmp    1b4c <generic_lsm_filter_arg+0x1b4c> */
	return 6988ULL;
x86_l_347b:
	/* 0x347b: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3480:
	/* 0x3480: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_3482:
	/* 0x3482: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_3488:
	/* 0x3488: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_348b:
	/* 0x348b: jb     37db <generic_lsm_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37db;
	}
x86_l_3491:
	/* 0x3491: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3496:
	/* 0x3496: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3499:
	/* 0x3499: jle    362b <generic_lsm_filter_arg+0x362b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_362b;
	}
x86_l_349f:
	/* 0x349f: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_34a2:
	/* 0x34a2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_34a5:
	/* 0x34a5: jb     3668 <generic_lsm_filter_arg+0x3668> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3668;
	}
x86_l_34ab:
	/* 0x34ab: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_34ae:
	/* 0x34ae: je     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 730ULL;
	}
x86_l_34b4:
	/* 0x34b4: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_34b7:
	/* 0x34b7: jne    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_34bd:
	/* 0x34bd: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_34c2:
	/* 0x34c2: jmp    350b <generic_lsm_filter_arg+0x350b> */
	goto x86_l_350b;
x86_l_34c4:
	/* 0x34c4: movzx  esi,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34c9:
	/* 0x34c9: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_34cb:
	/* 0x34cb: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_34d1:
	/* 0x34d1: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_34d4:
	/* 0x34d4: jb     37db <generic_lsm_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37db;
	}
x86_l_34da:
	/* 0x34da: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_34df:
	/* 0x34df: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_34e2:
	/* 0x34e2: jle    3644 <generic_lsm_filter_arg+0x3644> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3644;
	}
x86_l_34e8:
	/* 0x34e8: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_34eb:
	/* 0x34eb: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_34ee:
	/* 0x34ee: jb     366f <generic_lsm_filter_arg+0x366f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_366f;
	}
x86_l_34f4:
	/* 0x34f4: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_34f7:
	/* 0x34f7: je     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 730ULL;
	}
x86_l_34fd:
	/* 0x34fd: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3500:
	/* 0x3500: jne    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_3506:
	/* 0x3506: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_350b:
	/* 0x350b: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_350d:
	/* 0x350d: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_3513:
	/* 0x3513: jmp    37db <generic_lsm_filter_arg+0x37db> */
	goto x86_l_37db;
x86_l_3518:
	/* 0x3518: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_351b:
	/* 0x351b: je     3719 <generic_lsm_filter_arg+0x3719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3719;
	}
x86_l_3521:
	/* 0x3521: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_3524:
	/* 0x3524: je     36e0 <generic_lsm_filter_arg+0x36e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36e0;
	}
x86_l_352a:
	/* 0x352a: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_352d:
	/* 0x352d: jne    3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3743;
	}
x86_l_3533:
	/* 0x3533: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3538:
	/* 0x3538: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_353d:
	/* 0x353d: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_3544:
	/* 0x3544: jmp    372a <generic_lsm_filter_arg+0x372a> */
	goto x86_l_372a;
x86_l_3549:
	/* 0x3549: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_354d:
	/* 0x354d: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_3553:
	/* 0x3553: jmp    355f <generic_lsm_filter_arg+0x355f> */
	goto x86_l_355f;
x86_l_3555:
	/* 0x3555: cmp    DWORD PTR [r13+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3559:
	/* 0x3559: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_355f:
	/* 0x355f: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_3562:
	/* 0x3562: jb     37db <generic_lsm_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37db;
	}
x86_l_3568:
	/* 0x3568: mov    edx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_356d:
	/* 0x356d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3570:
	/* 0x3570: jle    359b <generic_lsm_filter_arg+0x359b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_359b;
	}
x86_l_3572:
	/* 0x3572: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3575:
	/* 0x3575: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3578:
	/* 0x3578: jb     35cf <generic_lsm_filter_arg+0x35cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_35cf;
	}
x86_l_357a:
	/* 0x357a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_357d:
	/* 0x357d: je     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 730ULL;
	}
x86_l_3583:
	/* 0x3583: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3586:
	/* 0x3586: jne    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_358c:
	/* 0x358c: test   DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3590:
	/* 0x3590: jne    2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 730ULL;
	}
x86_l_3596:
	/* 0x3596: jmp    37db <generic_lsm_filter_arg+0x37db> */
	goto x86_l_37db;
x86_l_359b:
	/* 0x359b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_359e:
	/* 0x359e: je     35de <generic_lsm_filter_arg+0x35de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35de;
	}
x86_l_35a0:
	/* 0x35a0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_35a3:
	/* 0x35a3: jne    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_35a9:
	/* 0x35a9: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_35ac:
	/* 0x35ac: ja     37c5 <generic_lsm_filter_arg+0x37c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_37c5;
	}
x86_l_35b2:
	/* 0x35b2: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_35b7:
	/* 0x35b7: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_35ba:
	/* 0x35ba: jae    37c5 <generic_lsm_filter_arg+0x37c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_37c5;
	}
x86_l_35c0:
	/* 0x35c0: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35c4:
	/* 0x35c4: jl     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 730ULL;
	}
x86_l_35ca:
	/* 0x35ca: jmp    37db <generic_lsm_filter_arg+0x37db> */
	goto x86_l_37db;
x86_l_35cf:
	/* 0x35cf: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35d3:
	/* 0x35d3: je     367c <generic_lsm_filter_arg+0x367c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_367c;
	}
x86_l_35d9:
	/* 0x35d9: jmp    37db <generic_lsm_filter_arg+0x37db> */
	goto x86_l_37db;
x86_l_35de:
	/* 0x35de: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_35e1:
	/* 0x35e1: ja     37d1 <generic_lsm_filter_arg+0x37d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_37d1;
	}
x86_l_35e7:
	/* 0x35e7: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_35ec:
	/* 0x35ec: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_35ef:
	/* 0x35ef: jae    37d1 <generic_lsm_filter_arg+0x37d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_37d1;
	}
x86_l_35f5:
	/* 0x35f5: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35f9:
	/* 0x35f9: jg     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 730ULL;
	}
x86_l_35ff:
	/* 0x35ff: jmp    37db <generic_lsm_filter_arg+0x37db> */
	goto x86_l_37db;
x86_l_3604:
	/* 0x3604: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_3606:
	/* 0x3606: je     36a7 <generic_lsm_filter_arg+0x36a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36a7;
	}
x86_l_360c:
	/* 0x360c: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_360f:
	/* 0x360f: jne    3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3743;
	}
x86_l_3615:
	/* 0x3615: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_361a:
	/* 0x361a: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_361f:
	/* 0x361f: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_3626:
	/* 0x3626: jmp    372a <generic_lsm_filter_arg+0x372a> */
	goto x86_l_372a;
x86_l_362b:
	/* 0x362b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_362e:
	/* 0x362e: je     37af <generic_lsm_filter_arg+0x37af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37af;
	}
x86_l_3634:
	/* 0x3634: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3637:
	/* 0x3637: jne    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_363d:
	/* 0x363d: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3642:
	/* 0x3642: jmp    365b <generic_lsm_filter_arg+0x365b> */
	goto x86_l_365b;
x86_l_3644:
	/* 0x3644: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3647:
	/* 0x3647: je     37b6 <generic_lsm_filter_arg+0x37b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37b6;
	}
x86_l_364d:
	/* 0x364d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3650:
	/* 0x3650: jne    117 <generic_lsm_filter_arg+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_3656:
	/* 0x3656: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_365b:
	/* 0x365b: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_365d:
	/* 0x365d: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_3663:
	/* 0x3663: jmp    37db <generic_lsm_filter_arg+0x37db> */
	goto x86_l_37db;
x86_l_3668:
	/* 0x3668: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_366d:
	/* 0x366d: jmp    3674 <generic_lsm_filter_arg+0x3674> */
	goto x86_l_3674;
x86_l_366f:
	/* 0x366f: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3674:
	/* 0x3674: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_3676:
	/* 0x3676: jne    37db <generic_lsm_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37db;
	}
x86_l_367c:
	/* 0x367c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_367e:
	/* 0x367e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3681:
	/* 0x3681: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_3684:
	/* 0x3684: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_3689:
	/* 0x3689: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_368d:
	/* 0x368d: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_3693:
	/* 0x3693: jmp    37db <generic_lsm_filter_arg+0x37db> */
	goto x86_l_37db;
x86_l_3698:
	/* 0x3698: cmp    QWORD PTR [r13+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_369c:
	/* 0x369c: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_36a2:
	/* 0x36a2: jmp    37db <generic_lsm_filter_arg+0x37db> */
	goto x86_l_37db;
x86_l_36a7:
	/* 0x36a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36ac:
	/* 0x36ac: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_36b3:
	/* 0x36b3: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36b8:
	/* 0x36b8: jmp    372a <generic_lsm_filter_arg+0x372a> */
	goto x86_l_372a;
x86_l_36ba:
	/* 0x36ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36bf:
	/* 0x36bf: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36c4:
	/* 0x36c4: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_36cb:
	/* 0x36cb: jmp    372a <generic_lsm_filter_arg+0x372a> */
	goto x86_l_372a;
x86_l_36cd:
	/* 0x36cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36d2:
	/* 0x36d2: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36d7:
	/* 0x36d7: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_36de:
	/* 0x36de: jmp    372a <generic_lsm_filter_arg+0x372a> */
	goto x86_l_372a;
x86_l_36e0:
	/* 0x36e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36e5:
	/* 0x36e5: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36ea:
	/* 0x36ea: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_36f1:
	/* 0x36f1: jmp    372a <generic_lsm_filter_arg+0x372a> */
	goto x86_l_372a;
x86_l_36f3:
	/* 0x36f3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36f8:
	/* 0x36f8: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36fd:
	/* 0x36fd: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3704:
	/* 0x3704: jmp    372a <generic_lsm_filter_arg+0x372a> */
	goto x86_l_372a;
x86_l_3706:
	/* 0x3706: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_370b:
	/* 0x370b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3710:
	/* 0x3710: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3717:
	/* 0x3717: jmp    372a <generic_lsm_filter_arg+0x372a> */
	goto x86_l_372a;
x86_l_3719:
	/* 0x3719: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_371e:
	/* 0x371e: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3723:
	/* 0x3723: mov    rdi,QWORD PTR [rip+0x1edc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_372a:
	/* 0x372a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_372c:
	/* 0x372c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_372f:
	/* 0x372f: je     3743 <generic_lsm_filter_arg+0x3743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3743;
	}
x86_l_3731:
	/* 0x3731: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3734:
	/* 0x3734: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3739:
	/* 0x3739: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_373e:
	/* 0x373e: jmp    1b4c <generic_lsm_filter_arg+0x1b4c> */
	return 6988ULL;
x86_l_3743:
	/* 0x3743: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3745:
	/* 0x3745: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_374a:
	/* 0x374a: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_374f:
	/* 0x374f: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3754:
	/* 0x3754: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3759:
	/* 0x3759: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_375d:
	/* 0x375d: ja     2c9 <generic_lsm_filter_arg+0x2c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 713ULL;
	}
x86_l_3763:
	/* 0x3763: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_376d:
	/* 0x376d: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3771:
	/* 0x3771: jae    2c9 <generic_lsm_filter_arg+0x2c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 713ULL;
	}
x86_l_3777:
	/* 0x3777: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3779:
	/* 0x3779: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_377c:
	/* 0x377c: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_377f:
	/* 0x377f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3782:
	/* 0x3782: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_3787:
	/* 0x3787: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3789:
	/* 0x3789: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_378e:
	/* 0x378e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3793:
	/* 0x3793: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_3796:
	/* 0x3796: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_379b:
	/* 0x379b: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37a0:
	/* 0x37a0: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_37a4:
	/* 0x37a4: jbe    33be <generic_lsm_filter_arg+0x33be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_33be;
	}
x86_l_37aa:
	/* 0x37aa: jmp    2c9 <generic_lsm_filter_arg+0x2c9> */
	return 713ULL;
x86_l_37af:
	/* 0x37af: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_37b4:
	/* 0x37b4: jmp    37bb <generic_lsm_filter_arg+0x37bb> */
	goto x86_l_37bb;
x86_l_37b6:
	/* 0x37b6: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37bb:
	/* 0x37bb: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_37bd:
	/* 0x37bd: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_37c3:
	/* 0x37c3: jmp    37db <generic_lsm_filter_arg+0x37db> */
	goto x86_l_37db;
x86_l_37c5:
	/* 0x37c5: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37c9:
	/* 0x37c9: jb     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 730ULL;
	}
x86_l_37cf:
	/* 0x37cf: jmp    37db <generic_lsm_filter_arg+0x37db> */
	goto x86_l_37db;
x86_l_37d1:
	/* 0x37d1: cmp    DWORD PTR [r13+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37d5:
	/* 0x37d5: ja     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 730ULL;
	}
x86_l_37db:
	/* 0x37db: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_37de:
	/* 0x37de: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_37e1:
	/* 0x37e1: je     2da <generic_lsm_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 730ULL;
	}
x86_l_37e7:
	/* 0x37e7: jmp    117 <generic_lsm_filter_arg+0x117> */
	return 279ULL;
x86_l_37ec:
	/* 0x37ec: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_37f1:
	/* 0x37f1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_37f4:
	/* 0x37f4: je     385d <native_bpf_strncasestr+0x71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_385d;
	}
x86_l_37f6:
	/* 0x37f6: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_37f7:
	/* 0x37f7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37f9:
	/* 0x37f9: jmp    3806 <native_bpf_strncasestr+0x1a> */
	goto x86_l_3806;
x86_l_37fb:
	/* 0x37fb: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_37fe:
	/* 0x37fe: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3801:
	/* 0x3801: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3804:
	/* 0x3804: je     385c <native_bpf_strncasestr+0x70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_385c;
	}
x86_l_3806:
	/* 0x3806: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3809:
	/* 0x3809: lea    r9,[rcx+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_380d:
	/* 0x380d: cmp    r9,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RDX, X86_WIDTH_64);
x86_l_3810:
	/* 0x3810: jae    37fb <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_37fb;
	}
x86_l_3812:
	/* 0x3812: movsx  r9d,BYTE PTR [rsi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_3817:
	/* 0x3817: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_381a:
	/* 0x381a: je     385a <native_bpf_strncasestr+0x6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_385a;
	}
x86_l_381c:
	/* 0x381c: movsx  r10d,BYTE PTR [rdi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_3821:
	/* 0x3821: lea    r11d,[r10-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_3825:
	/* 0x3825: mov    ebx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R10, X86_WIDTH_32);
x86_l_3828:
	/* 0x3828: or     ebx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_382b:
	/* 0x382b: cmp    r11d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 26ULL);
x86_l_382f:
	/* 0x382f: cmovae ebx,r10d */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R10, X86_WIDTH_32, X86_CC_AE);
x86_l_3833:
	/* 0x3833: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_3837:
	/* 0x3837: mov    r11d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_32);
x86_l_383a:
	/* 0x383a: or     r11d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_383e:
	/* 0x383e: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_3842:
	/* 0x3842: cmovae r11d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_3846:
	/* 0x3846: cmp    ebx,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R11, X86_WIDTH_32);
x86_l_3849:
	/* 0x3849: jne    37fb <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37fb;
	}
x86_l_384b:
	/* 0x384b: lea    r9,[r8+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_384f:
	/* 0x384f: cmp    r8,0x63 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 99ULL);
x86_l_3853:
	/* 0x3853: mov    r8,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_64);
x86_l_3856:
	/* 0x3856: jb     3809 <native_bpf_strncasestr+0x1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3809;
	}
x86_l_3858:
	/* 0x3858: jmp    37fb <native_bpf_strncasestr+0xf> */
	goto x86_l_37fb;
x86_l_385a:
	/* 0x385a: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_385c:
	/* 0x385c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_385d:
	/* 0x385d: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 13480U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1702ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1707ULL && __x86_pc <= 3370ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3376ULL && __x86_pc <= 4972ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4975ULL && __x86_pc <= 6610ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6615ULL && __x86_pc <= 8221ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8224ULL && __x86_pc <= 9829ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9834ULL && __x86_pc <= 11485ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11491ULL && __x86_pc <= 13153ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13160ULL && __x86_pc <= 14429ULL)
			__x86_pc = tetragon_bpf_generic_lsm_core_v511_generic_lsm_filter_arg_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

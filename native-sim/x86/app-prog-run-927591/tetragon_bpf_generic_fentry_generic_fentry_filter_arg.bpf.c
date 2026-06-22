extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
extern char fentry_calls;
extern char filter_map;
extern char heap_ro_zero;
extern char process_call_heap;
extern char retprobe_map;
extern char string_maps_0;
extern char string_maps_1;
extern char string_maps_2;
extern char string_maps_3;
extern char string_maps_4;
extern char string_maps_5;
extern char string_maps_heap;
extern char string_postfix_maps;
extern char string_postfix_maps_heap;
extern char string_prefix_maps;
extern char string_prefix_maps_heap;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 24ULL: goto x86_l_18;
	case 29ULL: goto x86_l_1d;
	case 36ULL: goto x86_l_24;
	case 44ULL: goto x86_l_2c;
	case 46ULL: goto x86_l_2e;
	case 49ULL: goto x86_l_31;
	case 55ULL: goto x86_l_37;
	case 58ULL: goto x86_l_3a;
	case 65ULL: goto x86_l_41;
	case 72ULL: goto x86_l_48;
	case 77ULL: goto x86_l_4d;
	case 84ULL: goto x86_l_54;
	case 86ULL: goto x86_l_56;
	case 89ULL: goto x86_l_59;
	case 95ULL: goto x86_l_5f;
	case 103ULL: goto x86_l_67;
	case 109ULL: goto x86_l_6d;
	case 112ULL: goto x86_l_70;
	case 115ULL: goto x86_l_73;
	case 124ULL: goto x86_l_7c;
	case 130ULL: goto x86_l_82;
	case 132ULL: goto x86_l_84;
	case 136ULL: goto x86_l_88;
	case 140ULL: goto x86_l_8c;
	case 144ULL: goto x86_l_90;
	case 148ULL: goto x86_l_94;
	case 152ULL: goto x86_l_98;
	case 158ULL: goto x86_l_9e;
	case 161ULL: goto x86_l_a1;
	case 164ULL: goto x86_l_a4;
	case 168ULL: goto x86_l_a8;
	case 170ULL: goto x86_l_aa;
	case 176ULL: goto x86_l_b0;
	case 179ULL: goto x86_l_b3;
	case 182ULL: goto x86_l_b6;
	case 184ULL: goto x86_l_b8;
	case 190ULL: goto x86_l_be;
	case 193ULL: goto x86_l_c1;
	case 196ULL: goto x86_l_c4;
	case 198ULL: goto x86_l_c6;
	case 204ULL: goto x86_l_cc;
	case 207ULL: goto x86_l_cf;
	case 210ULL: goto x86_l_d2;
	case 212ULL: goto x86_l_d4;
	case 218ULL: goto x86_l_da;
	case 221ULL: goto x86_l_dd;
	case 224ULL: goto x86_l_e0;
	case 226ULL: goto x86_l_e2;
	case 232ULL: goto x86_l_e8;
	case 236ULL: goto x86_l_ec;
	case 242ULL: goto x86_l_f2;
	case 246ULL: goto x86_l_f6;
	case 252ULL: goto x86_l_fc;
	case 258ULL: goto x86_l_102;
	case 260ULL: goto x86_l_104;
	case 266ULL: goto x86_l_10a;
	case 269ULL: goto x86_l_10d;
	case 273ULL: goto x86_l_111;
	case 279ULL: goto x86_l_117;
	case 288ULL: goto x86_l_120;
	case 294ULL: goto x86_l_126;
	case 297ULL: goto x86_l_129;
	case 300ULL: goto x86_l_12c;
	case 304ULL: goto x86_l_130;
	case 312ULL: goto x86_l_138;
	case 318ULL: goto x86_l_13e;
	case 322ULL: goto x86_l_142;
	case 329ULL: goto x86_l_149;
	case 332ULL: goto x86_l_14c;
	case 334ULL: goto x86_l_14e;
	case 337ULL: goto x86_l_151;
	case 339ULL: goto x86_l_153;
	case 342ULL: goto x86_l_156;
	case 348ULL: goto x86_l_15c;
	case 351ULL: goto x86_l_15f;
	case 357ULL: goto x86_l_165;
	case 360ULL: goto x86_l_168;
	case 362ULL: goto x86_l_16a;
	case 365ULL: goto x86_l_16d;
	case 371ULL: goto x86_l_173;
	case 376ULL: goto x86_l_178;
	case 379ULL: goto x86_l_17b;
	case 381ULL: goto x86_l_17d;
	case 384ULL: goto x86_l_180;
	case 387ULL: goto x86_l_183;
	case 393ULL: goto x86_l_189;
	case 396ULL: goto x86_l_18c;
	case 402ULL: goto x86_l_192;
	case 405ULL: goto x86_l_195;
	case 411ULL: goto x86_l_19b;
	case 416ULL: goto x86_l_1a0;
	case 419ULL: goto x86_l_1a3;
	case 422ULL: goto x86_l_1a6;
	case 428ULL: goto x86_l_1ac;
	case 431ULL: goto x86_l_1af;
	case 434ULL: goto x86_l_1b2;
	case 440ULL: goto x86_l_1b8;
	case 443ULL: goto x86_l_1bb;
	case 445ULL: goto x86_l_1bd;
	case 450ULL: goto x86_l_1c2;
	case 453ULL: goto x86_l_1c5;
	case 456ULL: goto x86_l_1c8;
	case 458ULL: goto x86_l_1ca;
	case 461ULL: goto x86_l_1cd;
	case 464ULL: goto x86_l_1d0;
	case 470ULL: goto x86_l_1d6;
	case 479ULL: goto x86_l_1df;
	case 488ULL: goto x86_l_1e8;
	case 497ULL: goto x86_l_1f1;
	case 506ULL: goto x86_l_1fa;
	case 515ULL: goto x86_l_203;
	case 518ULL: goto x86_l_206;
	case 521ULL: goto x86_l_209;
	case 527ULL: goto x86_l_20f;
	case 530ULL: goto x86_l_212;
	case 536ULL: goto x86_l_218;
	case 539ULL: goto x86_l_21b;
	case 542ULL: goto x86_l_21e;
	case 548ULL: goto x86_l_224;
	case 553ULL: goto x86_l_229;
	case 557ULL: goto x86_l_22d;
	case 560ULL: goto x86_l_230;
	case 563ULL: goto x86_l_233;
	case 569ULL: goto x86_l_239;
	case 571ULL: goto x86_l_23b;
	case 575ULL: goto x86_l_23f;
	case 580ULL: goto x86_l_244;
	case 583ULL: goto x86_l_247;
	case 587ULL: goto x86_l_24b;
	case 592ULL: goto x86_l_250;
	case 598ULL: goto x86_l_256;
	case 603ULL: goto x86_l_25b;
	case 606ULL: goto x86_l_25e;
	case 611ULL: goto x86_l_263;
	case 617ULL: goto x86_l_269;
	case 622ULL: goto x86_l_26e;
	case 625ULL: goto x86_l_271;
	case 631ULL: goto x86_l_277;
	case 635ULL: goto x86_l_27b;
	case 639ULL: goto x86_l_27f;
	case 647ULL: goto x86_l_287;
	case 652ULL: goto x86_l_28c;
	case 659ULL: goto x86_l_293;
	case 664ULL: goto x86_l_298;
	case 666ULL: goto x86_l_29a;
	case 669ULL: goto x86_l_29d;
	case 674ULL: goto x86_l_2a2;
	case 680ULL: goto x86_l_2a8;
	case 683ULL: goto x86_l_2ab;
	case 686ULL: goto x86_l_2ae;
	case 692ULL: goto x86_l_2b4;
	case 697ULL: goto x86_l_2b9;
	case 704ULL: goto x86_l_2c0;
	case 709ULL: goto x86_l_2c5;
	case 711ULL: goto x86_l_2c7;
	case 714ULL: goto x86_l_2ca;
	case 720ULL: goto x86_l_2d0;
	case 724ULL: goto x86_l_2d4;
	case 727ULL: goto x86_l_2d7;
	case 732ULL: goto x86_l_2dc;
	case 735ULL: goto x86_l_2df;
	case 738ULL: goto x86_l_2e2;
	case 740ULL: goto x86_l_2e4;
	case 743ULL: goto x86_l_2e7;
	case 749ULL: goto x86_l_2ed;
	case 754ULL: goto x86_l_2f2;
	case 758ULL: goto x86_l_2f6;
	case 761ULL: goto x86_l_2f9;
	case 765ULL: goto x86_l_2fd;
	case 771ULL: goto x86_l_303;
	case 777ULL: goto x86_l_309;
	case 783ULL: goto x86_l_30f;
	case 787ULL: goto x86_l_313;
	case 790ULL: goto x86_l_316;
	case 794ULL: goto x86_l_31a;
	case 800ULL: goto x86_l_320;
	case 806ULL: goto x86_l_326;
	case 812ULL: goto x86_l_32c;
	case 816ULL: goto x86_l_330;
	case 819ULL: goto x86_l_333;
	case 823ULL: goto x86_l_337;
	case 829ULL: goto x86_l_33d;
	case 835ULL: goto x86_l_343;
	case 841ULL: goto x86_l_349;
	case 845ULL: goto x86_l_34d;
	case 848ULL: goto x86_l_350;
	case 852ULL: goto x86_l_354;
	case 858ULL: goto x86_l_35a;
	case 864ULL: goto x86_l_360;
	case 870ULL: goto x86_l_366;
	case 874ULL: goto x86_l_36a;
	case 877ULL: goto x86_l_36d;
	case 881ULL: goto x86_l_371;
	case 887ULL: goto x86_l_377;
	case 893ULL: goto x86_l_37d;
	case 899ULL: goto x86_l_383;
	case 903ULL: goto x86_l_387;
	case 906ULL: goto x86_l_38a;
	case 910ULL: goto x86_l_38e;
	case 916ULL: goto x86_l_394;
	case 922ULL: goto x86_l_39a;
	case 928ULL: goto x86_l_3a0;
	case 932ULL: goto x86_l_3a4;
	case 935ULL: goto x86_l_3a7;
	case 939ULL: goto x86_l_3ab;
	case 945ULL: goto x86_l_3b1;
	case 951ULL: goto x86_l_3b7;
	case 957ULL: goto x86_l_3bd;
	case 961ULL: goto x86_l_3c1;
	case 964ULL: goto x86_l_3c4;
	case 968ULL: goto x86_l_3c8;
	case 974ULL: goto x86_l_3ce;
	case 980ULL: goto x86_l_3d4;
	case 986ULL: goto x86_l_3da;
	case 990ULL: goto x86_l_3de;
	case 993ULL: goto x86_l_3e1;
	case 997ULL: goto x86_l_3e5;
	case 1003ULL: goto x86_l_3eb;
	case 1009ULL: goto x86_l_3f1;
	case 1015ULL: goto x86_l_3f7;
	case 1019ULL: goto x86_l_3fb;
	case 1022ULL: goto x86_l_3fe;
	case 1026ULL: goto x86_l_402;
	case 1032ULL: goto x86_l_408;
	case 1038ULL: goto x86_l_40e;
	case 1044ULL: goto x86_l_414;
	case 1048ULL: goto x86_l_418;
	case 1051ULL: goto x86_l_41b;
	case 1055ULL: goto x86_l_41f;
	case 1061ULL: goto x86_l_425;
	case 1067ULL: goto x86_l_42b;
	case 1073ULL: goto x86_l_431;
	case 1077ULL: goto x86_l_435;
	case 1080ULL: goto x86_l_438;
	case 1084ULL: goto x86_l_43c;
	case 1090ULL: goto x86_l_442;
	case 1096ULL: goto x86_l_448;
	case 1102ULL: goto x86_l_44e;
	case 1106ULL: goto x86_l_452;
	case 1109ULL: goto x86_l_455;
	case 1113ULL: goto x86_l_459;
	case 1119ULL: goto x86_l_45f;
	case 1125ULL: goto x86_l_465;
	case 1131ULL: goto x86_l_46b;
	case 1135ULL: goto x86_l_46f;
	case 1138ULL: goto x86_l_472;
	case 1142ULL: goto x86_l_476;
	case 1148ULL: goto x86_l_47c;
	case 1154ULL: goto x86_l_482;
	case 1160ULL: goto x86_l_488;
	case 1164ULL: goto x86_l_48c;
	case 1167ULL: goto x86_l_48f;
	case 1171ULL: goto x86_l_493;
	case 1177ULL: goto x86_l_499;
	case 1183ULL: goto x86_l_49f;
	case 1189ULL: goto x86_l_4a5;
	case 1193ULL: goto x86_l_4a9;
	case 1196ULL: goto x86_l_4ac;
	case 1200ULL: goto x86_l_4b0;
	case 1206ULL: goto x86_l_4b6;
	case 1212ULL: goto x86_l_4bc;
	case 1218ULL: goto x86_l_4c2;
	case 1222ULL: goto x86_l_4c6;
	case 1225ULL: goto x86_l_4c9;
	case 1229ULL: goto x86_l_4cd;
	case 1235ULL: goto x86_l_4d3;
	case 1241ULL: goto x86_l_4d9;
	case 1247ULL: goto x86_l_4df;
	case 1251ULL: goto x86_l_4e3;
	case 1254ULL: goto x86_l_4e6;
	case 1258ULL: goto x86_l_4ea;
	case 1264ULL: goto x86_l_4f0;
	case 1270ULL: goto x86_l_4f6;
	case 1276ULL: goto x86_l_4fc;
	case 1280ULL: goto x86_l_500;
	case 1283ULL: goto x86_l_503;
	case 1287ULL: goto x86_l_507;
	case 1293ULL: goto x86_l_50d;
	case 1299ULL: goto x86_l_513;
	case 1305ULL: goto x86_l_519;
	case 1309ULL: goto x86_l_51d;
	case 1312ULL: goto x86_l_520;
	case 1316ULL: goto x86_l_524;
	case 1322ULL: goto x86_l_52a;
	case 1328ULL: goto x86_l_530;
	case 1334ULL: goto x86_l_536;
	case 1338ULL: goto x86_l_53a;
	case 1341ULL: goto x86_l_53d;
	case 1345ULL: goto x86_l_541;
	case 1351ULL: goto x86_l_547;
	case 1357ULL: goto x86_l_54d;
	case 1363ULL: goto x86_l_553;
	case 1367ULL: goto x86_l_557;
	case 1370ULL: goto x86_l_55a;
	case 1374ULL: goto x86_l_55e;
	case 1380ULL: goto x86_l_564;
	case 1386ULL: goto x86_l_56a;
	case 1392ULL: goto x86_l_570;
	case 1396ULL: goto x86_l_574;
	case 1399ULL: goto x86_l_577;
	case 1403ULL: goto x86_l_57b;
	case 1409ULL: goto x86_l_581;
	case 1415ULL: goto x86_l_587;
	case 1421ULL: goto x86_l_58d;
	case 1425ULL: goto x86_l_591;
	case 1428ULL: goto x86_l_594;
	case 1432ULL: goto x86_l_598;
	case 1438ULL: goto x86_l_59e;
	case 1444ULL: goto x86_l_5a4;
	case 1450ULL: goto x86_l_5aa;
	case 1454ULL: goto x86_l_5ae;
	case 1457ULL: goto x86_l_5b1;
	case 1461ULL: goto x86_l_5b5;
	case 1467ULL: goto x86_l_5bb;
	case 1473ULL: goto x86_l_5c1;
	case 1479ULL: goto x86_l_5c7;
	case 1483ULL: goto x86_l_5cb;
	case 1486ULL: goto x86_l_5ce;
	case 1490ULL: goto x86_l_5d2;
	case 1496ULL: goto x86_l_5d8;
	case 1502ULL: goto x86_l_5de;
	case 1508ULL: goto x86_l_5e4;
	case 1512ULL: goto x86_l_5e8;
	case 1515ULL: goto x86_l_5eb;
	case 1519ULL: goto x86_l_5ef;
	case 1525ULL: goto x86_l_5f5;
	case 1531ULL: goto x86_l_5fb;
	case 1537ULL: goto x86_l_601;
	case 1541ULL: goto x86_l_605;
	case 1544ULL: goto x86_l_608;
	case 1548ULL: goto x86_l_60c;
	case 1554ULL: goto x86_l_612;
	case 1560ULL: goto x86_l_618;
	case 1566ULL: goto x86_l_61e;
	case 1570ULL: goto x86_l_622;
	case 1573ULL: goto x86_l_625;
	case 1577ULL: goto x86_l_629;
	case 1583ULL: goto x86_l_62f;
	case 1589ULL: goto x86_l_635;
	case 1595ULL: goto x86_l_63b;
	case 1599ULL: goto x86_l_63f;
	case 1602ULL: goto x86_l_642;
	case 1606ULL: goto x86_l_646;
	case 1612ULL: goto x86_l_64c;
	case 1618ULL: goto x86_l_652;
	case 1624ULL: goto x86_l_658;
	case 1628ULL: goto x86_l_65c;
	case 1631ULL: goto x86_l_65f;
	case 1635ULL: goto x86_l_663;
	case 1641ULL: goto x86_l_669;
	case 1647ULL: goto x86_l_66f;
	case 1653ULL: goto x86_l_675;
	case 1657ULL: goto x86_l_679;
	case 1660ULL: goto x86_l_67c;
	case 1664ULL: goto x86_l_680;
	case 1670ULL: goto x86_l_686;
	case 1676ULL: goto x86_l_68c;
	case 1682ULL: goto x86_l_692;
	case 1686ULL: goto x86_l_696;
	case 1689ULL: goto x86_l_699;
	case 1693ULL: goto x86_l_69d;
	case 1699ULL: goto x86_l_6a3;
	case 1705ULL: goto x86_l_6a9;
	case 1711ULL: goto x86_l_6af;
	case 1715ULL: goto x86_l_6b3;
	case 1718ULL: goto x86_l_6b6;
	case 1722ULL: goto x86_l_6ba;
	case 1728ULL: goto x86_l_6c0;
	case 1734ULL: goto x86_l_6c6;
	case 1740ULL: goto x86_l_6cc;
	case 1744ULL: goto x86_l_6d0;
	case 1747ULL: goto x86_l_6d3;
	case 1751ULL: goto x86_l_6d7;
	case 1757ULL: goto x86_l_6dd;
	case 1763ULL: goto x86_l_6e3;
	case 1769ULL: goto x86_l_6e9;
	case 1773ULL: goto x86_l_6ed;
	case 1776ULL: goto x86_l_6f0;
	case 1780ULL: goto x86_l_6f4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 136ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x5d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     38cc <generic_fentry_filter_arg+0x38cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14540ULL;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    r12d,DWORD PTR [rax+0x5ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_41:
	/* 0x41: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_48:
	/* 0x48: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d:
	/* 0x4d: mov    rdi,QWORD PTR [rip+0x5d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_54:
	/* 0x54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56:
	/* 0x56: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59:
	/* 0x59: je     38b6 <generic_fentry_filter_arg+0x38b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14518ULL;
	}
x86_l_5f:
	/* 0x5f: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_67:
	/* 0x67: je     38b6 <generic_fentry_filter_arg+0x38b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14518ULL;
	}
x86_l_6d:
	/* 0x6d: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_70:
	/* 0x70: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_73:
	/* 0x73: cmp    BYTE PTR [r14+rcx*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 104183021699072ULL);
x86_l_7c:
	/* 0x7c: je     3844 <generic_fentry_filter_arg+0x3844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14404ULL;
	}
x86_l_82:
	/* 0x82: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_84:
	/* 0x84: mov    edx,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_88:
	/* 0x88: lea    rsi,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_8c:
	/* 0x8c: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_90:
	/* 0x90: lea    rcx,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_94:
	/* 0x94: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_98:
	/* 0x98: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_9e:
	/* 0x9e: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_a1:
	/* 0xa1: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a4:
	/* 0xa4: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a8:
	/* 0xa8: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_aa:
	/* 0xaa: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b0:
	/* 0xb0: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_b3:
	/* 0xb3: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b6:
	/* 0xb6: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_b8:
	/* 0xb8: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_be:
	/* 0xbe: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_c1:
	/* 0xc1: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c4:
	/* 0xc4: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_c6:
	/* 0xc6: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_cc:
	/* 0xcc: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_cf:
	/* 0xcf: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d2:
	/* 0xd2: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_d4:
	/* 0xd4: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_da:
	/* 0xda: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_dd:
	/* 0xdd: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e0:
	/* 0xe0: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_e2:
	/* 0xe2: and    ebp,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_e8:
	/* 0xe8: cmp    DWORD PTR [rax+rbp*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 25ULL);
x86_l_ec:
	/* 0xec: jb     383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14394ULL;
	}
x86_l_f2:
	/* 0xf2: mov    edx,DWORD PTR [rax+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_f6:
	/* 0xf6: test   edx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 1023ULL);
x86_l_fc:
	/* 0xfc: je     383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14394ULL;
	}
x86_l_102:
	/* 0x102: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_104:
	/* 0x104: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_10a:
	/* 0x10a: mov    edx,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_10d:
	/* 0x10d: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_111:
	/* 0x111: ja     3844 <generic_fentry_filter_arg+0x3844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14404ULL;
	}
x86_l_117:
	/* 0x117: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_120:
	/* 0x120: jne    3844 <generic_fentry_filter_arg+0x3844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14404ULL;
	}
x86_l_126:
	/* 0x126: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_129:
	/* 0x129: add    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12c:
	/* 0x12c: mov    eax,DWORD PTR [rax+rcx*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 12ULL);
x86_l_130:
	/* 0x130: mov    rcx,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_138:
	/* 0x138: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_13e:
	/* 0x13e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_142:
	/* 0x142: add    rdi,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_149:
	/* 0x149: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_14c:
	/* 0x14c: jg     178 <generic_fentry_filter_arg+0x178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_178;
	}
x86_l_14e:
	/* 0x14e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_151:
	/* 0x151: jg     1a0 <generic_fentry_filter_arg+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1a0;
	}
x86_l_153:
	/* 0x153: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_156:
	/* 0x156: jle    d7e <generic_fentry_filter_arg+0xd7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3454ULL;
	}
x86_l_15c:
	/* 0x15c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15f:
	/* 0x15f: je     1c33 <generic_fentry_filter_arg+0x1c33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7219ULL;
	}
x86_l_165:
	/* 0x165: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_168:
	/* 0x168: je     1d6 <generic_fentry_filter_arg+0x1d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d6;
	}
x86_l_16a:
	/* 0x16a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_16d:
	/* 0x16d: je     229 <generic_fentry_filter_arg+0x229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_229;
	}
x86_l_173:
	/* 0x173: jmp    383a <generic_fentry_filter_arg+0x383a> */
	return 14394ULL;
x86_l_178:
	/* 0x178: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_17b:
	/* 0x17b: jg     1c2 <generic_fentry_filter_arg+0x1c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1c2;
	}
x86_l_17d:
	/* 0x17d: lea    ecx,[rax-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_180:
	/* 0x180: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_183:
	/* 0x183: jb     1c33 <generic_fentry_filter_arg+0x1c33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7219ULL;
	}
x86_l_189:
	/* 0x189: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_18c:
	/* 0x18c: je     1e15 <generic_fentry_filter_arg+0x1e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7701ULL;
	}
x86_l_192:
	/* 0x192: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_195:
	/* 0x195: je     1c33 <generic_fentry_filter_arg+0x1c33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7219ULL;
	}
x86_l_19b:
	/* 0x19b: jmp    383a <generic_fentry_filter_arg+0x383a> */
	return 14394ULL;
x86_l_1a0:
	/* 0x1a0: lea    ecx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_1a3:
	/* 0x1a3: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a6:
	/* 0x1a6: jb     1c33 <generic_fentry_filter_arg+0x1c33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7219ULL;
	}
x86_l_1ac:
	/* 0x1ac: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_1af:
	/* 0x1af: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b2:
	/* 0x1b2: jb     1e19 <generic_fentry_filter_arg+0x1e19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7705ULL;
	}
x86_l_1b8:
	/* 0x1b8: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1bb:
	/* 0x1bb: je     1d6 <generic_fentry_filter_arg+0x1d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d6;
	}
x86_l_1bd:
	/* 0x1bd: jmp    383a <generic_fentry_filter_arg+0x383a> */
	return 14394ULL;
x86_l_1c2:
	/* 0x1c2: lea    ecx,[rax-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_1c5:
	/* 0x1c5: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c8:
	/* 0x1c8: jb     229 <generic_fentry_filter_arg+0x229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_229;
	}
x86_l_1ca:
	/* 0x1ca: lea    ecx,[rax-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_1cd:
	/* 0x1cd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1d0:
	/* 0x1d0: jae    1d86 <generic_fentry_filter_arg+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7558ULL;
	}
x86_l_1d6:
	/* 0x1d6: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1df:
	/* 0x1df: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1e8:
	/* 0x1e8: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1f1:
	/* 0x1f1: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1fa:
	/* 0x1fa: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_203:
	/* 0x203: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_206:
	/* 0x206: cmp    eax,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_209:
	/* 0x209: jg     1cce <generic_fentry_filter_arg+0x1cce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7374ULL;
	}
x86_l_20f:
	/* 0x20f: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_212:
	/* 0x212: je     1f90 <generic_fentry_filter_arg+0x1f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8080ULL;
	}
x86_l_218:
	/* 0x218: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_21b:
	/* 0x21b: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_21e:
	/* 0x21e: je     1f92 <generic_fentry_filter_arg+0x1f92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8082ULL;
	}
x86_l_224:
	/* 0x224: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_229:
	/* 0x229: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_22d:
	/* 0x22d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_230:
	/* 0x230: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_233:
	/* 0x233: ja     381a <generic_fentry_filter_arg+0x381a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14362ULL;
	}
x86_l_239:
	/* 0x239: mov    edx,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23b:
	/* 0x23b: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_23f:
	/* 0x23f: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_244:
	/* 0x244: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_247:
	/* 0x247: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24b:
	/* 0x24b: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_250:
	/* 0x250: jb     1f28 <generic_fentry_filter_arg+0x1f28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7976ULL;
	}
x86_l_256:
	/* 0x256: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_25b:
	/* 0x25b: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_25e:
	/* 0x25e: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_263:
	/* 0x263: jb     1e8c <generic_fentry_filter_arg+0x1e8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7820ULL;
	}
x86_l_269:
	/* 0x269: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_26e:
	/* 0x26e: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_271:
	/* 0x271: jae    381a <generic_fentry_filter_arg+0x381a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14362ULL;
	}
x86_l_277:
	/* 0x277: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27b:
	/* 0x27b: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_27f:
	/* 0x27f: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_287:
	/* 0x287: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28c:
	/* 0x28c: mov    rdi,QWORD PTR [rip+0x5d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_293:
	/* 0x293: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_298:
	/* 0x298: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a:
	/* 0x29a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29d:
	/* 0x29d: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a2:
	/* 0x2a2: je     3717 <generic_fentry_filter_arg+0x3717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14103ULL;
	}
x86_l_2a8:
	/* 0x2a8: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2ab:
	/* 0x2ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ae:
	/* 0x2ae: je     3717 <generic_fentry_filter_arg+0x3717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14103ULL;
	}
x86_l_2b4:
	/* 0x2b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b9:
	/* 0x2b9: mov    rdi,QWORD PTR [rip+0x5d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_2c0:
	/* 0x2c0: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c5:
	/* 0x2c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c7:
	/* 0x2c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ca:
	/* 0x2ca: je     3714 <generic_fentry_filter_arg+0x3714> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14100ULL;
	}
x86_l_2d0:
	/* 0x2d0: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d4:
	/* 0x2d4: cmp    esi,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 94ULL);
x86_l_2d7:
	/* 0x2d7: mov    ecx,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 94ULL);
x86_l_2dc:
	/* 0x2dc: cmovb  ecx,esi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_2df:
	/* 0x2df: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_2e2:
	/* 0x2e2: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e4:
	/* 0x2e4: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2e7:
	/* 0x2e7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ed:
	/* 0x2ed: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f2:
	/* 0x2f2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2f6:
	/* 0x2f6: mov    BYTE PTR [rax+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f9:
	/* 0x2f9: cmp    rsi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1ULL);
x86_l_2fd:
	/* 0x2fd: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_303:
	/* 0x303: lea    ecx,[rsi+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_309:
	/* 0x309: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30f:
	/* 0x30f: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_313:
	/* 0x313: mov    BYTE PTR [rax+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_316:
	/* 0x316: cmp    rsi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 2ULL);
x86_l_31a:
	/* 0x31a: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_320:
	/* 0x320: lea    ecx,[rsi+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_326:
	/* 0x326: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_32c:
	/* 0x32c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_330:
	/* 0x330: mov    BYTE PTR [rax+0x6],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_333:
	/* 0x333: cmp    rsi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 3ULL);
x86_l_337:
	/* 0x337: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_33d:
	/* 0x33d: lea    ecx,[rsi+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_343:
	/* 0x343: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_349:
	/* 0x349: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_34d:
	/* 0x34d: mov    BYTE PTR [rax+0x7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_350:
	/* 0x350: cmp    rsi,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4ULL);
x86_l_354:
	/* 0x354: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_35a:
	/* 0x35a: lea    ecx,[rsi+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_360:
	/* 0x360: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_366:
	/* 0x366: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_36a:
	/* 0x36a: mov    BYTE PTR [rax+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36d:
	/* 0x36d: cmp    rsi,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 5ULL);
x86_l_371:
	/* 0x371: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_377:
	/* 0x377: lea    ecx,[rsi+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_37d:
	/* 0x37d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_383:
	/* 0x383: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_387:
	/* 0x387: mov    BYTE PTR [rax+0x9],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_38a:
	/* 0x38a: cmp    rsi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 6ULL);
x86_l_38e:
	/* 0x38e: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_394:
	/* 0x394: lea    ecx,[rsi+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_39a:
	/* 0x39a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3a0:
	/* 0x3a0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_3a4:
	/* 0x3a4: mov    BYTE PTR [rax+0xa],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_3a7:
	/* 0x3a7: cmp    rsi,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 7ULL);
x86_l_3ab:
	/* 0x3ab: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_3b1:
	/* 0x3b1: lea    ecx,[rsi+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_3b7:
	/* 0x3b7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3bd:
	/* 0x3bd: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_3c1:
	/* 0x3c1: mov    BYTE PTR [rax+0xb],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_3c4:
	/* 0x3c4: cmp    rsi,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 8ULL);
x86_l_3c8:
	/* 0x3c8: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_3ce:
	/* 0x3ce: lea    ecx,[rsi+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_3d4:
	/* 0x3d4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3da:
	/* 0x3da: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_3de:
	/* 0x3de: mov    BYTE PTR [rax+0xc],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3e1:
	/* 0x3e1: cmp    rsi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 9ULL);
x86_l_3e5:
	/* 0x3e5: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_3eb:
	/* 0x3eb: lea    ecx,[rsi+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_3f1:
	/* 0x3f1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3f7:
	/* 0x3f7: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_3fb:
	/* 0x3fb: mov    BYTE PTR [rax+0xd],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_3fe:
	/* 0x3fe: cmp    rsi,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 10ULL);
x86_l_402:
	/* 0x402: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_408:
	/* 0x408: lea    ecx,[rsi+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_40e:
	/* 0x40e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_414:
	/* 0x414: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_418:
	/* 0x418: mov    BYTE PTR [rax+0xe],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_41b:
	/* 0x41b: cmp    rsi,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 11ULL);
x86_l_41f:
	/* 0x41f: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_425:
	/* 0x425: lea    ecx,[rsi+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_42b:
	/* 0x42b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_431:
	/* 0x431: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_435:
	/* 0x435: mov    BYTE PTR [rax+0xf],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_438:
	/* 0x438: cmp    rsi,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 12ULL);
x86_l_43c:
	/* 0x43c: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_442:
	/* 0x442: lea    ecx,[rsi+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_448:
	/* 0x448: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_44e:
	/* 0x44e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_452:
	/* 0x452: mov    BYTE PTR [rax+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_455:
	/* 0x455: cmp    rsi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 13ULL);
x86_l_459:
	/* 0x459: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_45f:
	/* 0x45f: lea    ecx,[rsi+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_465:
	/* 0x465: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_46b:
	/* 0x46b: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_46f:
	/* 0x46f: mov    BYTE PTR [rax+0x11],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_472:
	/* 0x472: cmp    rsi,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 14ULL);
x86_l_476:
	/* 0x476: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_47c:
	/* 0x47c: lea    ecx,[rsi+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_482:
	/* 0x482: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_488:
	/* 0x488: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_48c:
	/* 0x48c: mov    BYTE PTR [rax+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_48f:
	/* 0x48f: cmp    rsi,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 15ULL);
x86_l_493:
	/* 0x493: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_499:
	/* 0x499: lea    ecx,[rsi+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_49f:
	/* 0x49f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4a5:
	/* 0x4a5: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_4a9:
	/* 0x4a9: mov    BYTE PTR [rax+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_4ac:
	/* 0x4ac: cmp    rsi,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 16ULL);
x86_l_4b0:
	/* 0x4b0: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_4b6:
	/* 0x4b6: lea    ecx,[rsi+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_4bc:
	/* 0x4bc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4c2:
	/* 0x4c2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_4c6:
	/* 0x4c6: mov    BYTE PTR [rax+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4c9:
	/* 0x4c9: cmp    rsi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 17ULL);
x86_l_4cd:
	/* 0x4cd: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_4d3:
	/* 0x4d3: lea    ecx,[rsi+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_4d9:
	/* 0x4d9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4df:
	/* 0x4df: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_4e3:
	/* 0x4e3: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_4e6:
	/* 0x4e6: cmp    rsi,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18ULL);
x86_l_4ea:
	/* 0x4ea: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_4f0:
	/* 0x4f0: lea    ecx,[rsi+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_4f6:
	/* 0x4f6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4fc:
	/* 0x4fc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_500:
	/* 0x500: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_503:
	/* 0x503: cmp    rsi,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 19ULL);
x86_l_507:
	/* 0x507: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_50d:
	/* 0x50d: lea    ecx,[rsi+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_513:
	/* 0x513: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_519:
	/* 0x519: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_51d:
	/* 0x51d: mov    BYTE PTR [rax+0x17],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_520:
	/* 0x520: cmp    rsi,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 20ULL);
x86_l_524:
	/* 0x524: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_52a:
	/* 0x52a: lea    ecx,[rsi+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_530:
	/* 0x530: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_536:
	/* 0x536: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_53a:
	/* 0x53a: mov    BYTE PTR [rax+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_53d:
	/* 0x53d: cmp    rsi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 21ULL);
x86_l_541:
	/* 0x541: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_547:
	/* 0x547: lea    ecx,[rsi+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_54d:
	/* 0x54d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_553:
	/* 0x553: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_557:
	/* 0x557: mov    BYTE PTR [rax+0x19],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_55a:
	/* 0x55a: cmp    rsi,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 22ULL);
x86_l_55e:
	/* 0x55e: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_564:
	/* 0x564: lea    ecx,[rsi+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_56a:
	/* 0x56a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_570:
	/* 0x570: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_574:
	/* 0x574: mov    BYTE PTR [rax+0x1a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_577:
	/* 0x577: cmp    rsi,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 23ULL);
x86_l_57b:
	/* 0x57b: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_581:
	/* 0x581: lea    ecx,[rsi+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_587:
	/* 0x587: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_58d:
	/* 0x58d: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_591:
	/* 0x591: mov    BYTE PTR [rax+0x1b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_594:
	/* 0x594: cmp    rsi,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 24ULL);
x86_l_598:
	/* 0x598: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_59e:
	/* 0x59e: lea    ecx,[rsi+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_5a4:
	/* 0x5a4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5aa:
	/* 0x5aa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_5ae:
	/* 0x5ae: mov    BYTE PTR [rax+0x1c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5b1:
	/* 0x5b1: cmp    rsi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 25ULL);
x86_l_5b5:
	/* 0x5b5: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_5bb:
	/* 0x5bb: lea    ecx,[rsi+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_5c1:
	/* 0x5c1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5c7:
	/* 0x5c7: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_5cb:
	/* 0x5cb: mov    BYTE PTR [rax+0x1d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_5ce:
	/* 0x5ce: cmp    rsi,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 26ULL);
x86_l_5d2:
	/* 0x5d2: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_5d8:
	/* 0x5d8: lea    ecx,[rsi+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_5de:
	/* 0x5de: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5e4:
	/* 0x5e4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_5e8:
	/* 0x5e8: mov    BYTE PTR [rax+0x1e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_5eb:
	/* 0x5eb: cmp    rsi,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 27ULL);
x86_l_5ef:
	/* 0x5ef: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_5f5:
	/* 0x5f5: lea    ecx,[rsi+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_5fb:
	/* 0x5fb: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_601:
	/* 0x601: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_605:
	/* 0x605: mov    BYTE PTR [rax+0x1f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_608:
	/* 0x608: cmp    rsi,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 28ULL);
x86_l_60c:
	/* 0x60c: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_612:
	/* 0x612: lea    ecx,[rsi+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_618:
	/* 0x618: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_61e:
	/* 0x61e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_622:
	/* 0x622: mov    BYTE PTR [rax+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_625:
	/* 0x625: cmp    rsi,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 29ULL);
x86_l_629:
	/* 0x629: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_62f:
	/* 0x62f: lea    ecx,[rsi+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_635:
	/* 0x635: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_63b:
	/* 0x63b: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_63f:
	/* 0x63f: mov    BYTE PTR [rax+0x21],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_642:
	/* 0x642: cmp    rsi,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 30ULL);
x86_l_646:
	/* 0x646: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_64c:
	/* 0x64c: lea    ecx,[rsi+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_652:
	/* 0x652: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_658:
	/* 0x658: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_65c:
	/* 0x65c: mov    BYTE PTR [rax+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_65f:
	/* 0x65f: cmp    rsi,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 31ULL);
x86_l_663:
	/* 0x663: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_669:
	/* 0x669: lea    ecx,[rsi+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_66f:
	/* 0x66f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_675:
	/* 0x675: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_679:
	/* 0x679: mov    BYTE PTR [rax+0x23],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_67c:
	/* 0x67c: cmp    rsi,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 32ULL);
x86_l_680:
	/* 0x680: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_686:
	/* 0x686: lea    ecx,[rsi+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_68c:
	/* 0x68c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_692:
	/* 0x692: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_696:
	/* 0x696: mov    BYTE PTR [rax+0x24],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_699:
	/* 0x699: cmp    rsi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 33ULL);
x86_l_69d:
	/* 0x69d: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_6a3:
	/* 0x6a3: lea    ecx,[rsi+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_6a9:
	/* 0x6a9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6af:
	/* 0x6af: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_6b3:
	/* 0x6b3: mov    BYTE PTR [rax+0x25],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_6b6:
	/* 0x6b6: cmp    rsi,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 34ULL);
x86_l_6ba:
	/* 0x6ba: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_6c0:
	/* 0x6c0: lea    ecx,[rsi+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_6c6:
	/* 0x6c6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6cc:
	/* 0x6cc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_6d0:
	/* 0x6d0: mov    BYTE PTR [rax+0x26],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_6d3:
	/* 0x6d3: cmp    rsi,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 35ULL);
x86_l_6d7:
	/* 0x6d7: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
x86_l_6dd:
	/* 0x6dd: lea    ecx,[rsi+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_6e3:
	/* 0x6e3: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6e9:
	/* 0x6e9: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_6ed:
	/* 0x6ed: mov    BYTE PTR [rax+0x27],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_6f0:
	/* 0x6f0: cmp    rsi,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 36ULL);
x86_l_6f4:
	/* 0x6f4: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3438ULL;
	}
	return 1786ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1786ULL: goto x86_l_6fa;
	case 1792ULL: goto x86_l_700;
	case 1798ULL: goto x86_l_706;
	case 1802ULL: goto x86_l_70a;
	case 1805ULL: goto x86_l_70d;
	case 1809ULL: goto x86_l_711;
	case 1815ULL: goto x86_l_717;
	case 1821ULL: goto x86_l_71d;
	case 1827ULL: goto x86_l_723;
	case 1831ULL: goto x86_l_727;
	case 1834ULL: goto x86_l_72a;
	case 1838ULL: goto x86_l_72e;
	case 1844ULL: goto x86_l_734;
	case 1850ULL: goto x86_l_73a;
	case 1856ULL: goto x86_l_740;
	case 1860ULL: goto x86_l_744;
	case 1863ULL: goto x86_l_747;
	case 1867ULL: goto x86_l_74b;
	case 1873ULL: goto x86_l_751;
	case 1879ULL: goto x86_l_757;
	case 1885ULL: goto x86_l_75d;
	case 1889ULL: goto x86_l_761;
	case 1892ULL: goto x86_l_764;
	case 1896ULL: goto x86_l_768;
	case 1902ULL: goto x86_l_76e;
	case 1908ULL: goto x86_l_774;
	case 1914ULL: goto x86_l_77a;
	case 1918ULL: goto x86_l_77e;
	case 1921ULL: goto x86_l_781;
	case 1925ULL: goto x86_l_785;
	case 1931ULL: goto x86_l_78b;
	case 1937ULL: goto x86_l_791;
	case 1943ULL: goto x86_l_797;
	case 1947ULL: goto x86_l_79b;
	case 1950ULL: goto x86_l_79e;
	case 1954ULL: goto x86_l_7a2;
	case 1960ULL: goto x86_l_7a8;
	case 1966ULL: goto x86_l_7ae;
	case 1972ULL: goto x86_l_7b4;
	case 1976ULL: goto x86_l_7b8;
	case 1979ULL: goto x86_l_7bb;
	case 1983ULL: goto x86_l_7bf;
	case 1989ULL: goto x86_l_7c5;
	case 1995ULL: goto x86_l_7cb;
	case 2001ULL: goto x86_l_7d1;
	case 2005ULL: goto x86_l_7d5;
	case 2008ULL: goto x86_l_7d8;
	case 2012ULL: goto x86_l_7dc;
	case 2018ULL: goto x86_l_7e2;
	case 2024ULL: goto x86_l_7e8;
	case 2030ULL: goto x86_l_7ee;
	case 2034ULL: goto x86_l_7f2;
	case 2037ULL: goto x86_l_7f5;
	case 2041ULL: goto x86_l_7f9;
	case 2047ULL: goto x86_l_7ff;
	case 2053ULL: goto x86_l_805;
	case 2059ULL: goto x86_l_80b;
	case 2063ULL: goto x86_l_80f;
	case 2066ULL: goto x86_l_812;
	case 2070ULL: goto x86_l_816;
	case 2076ULL: goto x86_l_81c;
	case 2082ULL: goto x86_l_822;
	case 2088ULL: goto x86_l_828;
	case 2092ULL: goto x86_l_82c;
	case 2095ULL: goto x86_l_82f;
	case 2099ULL: goto x86_l_833;
	case 2105ULL: goto x86_l_839;
	case 2111ULL: goto x86_l_83f;
	case 2117ULL: goto x86_l_845;
	case 2121ULL: goto x86_l_849;
	case 2124ULL: goto x86_l_84c;
	case 2128ULL: goto x86_l_850;
	case 2134ULL: goto x86_l_856;
	case 2140ULL: goto x86_l_85c;
	case 2146ULL: goto x86_l_862;
	case 2150ULL: goto x86_l_866;
	case 2153ULL: goto x86_l_869;
	case 2157ULL: goto x86_l_86d;
	case 2163ULL: goto x86_l_873;
	case 2169ULL: goto x86_l_879;
	case 2175ULL: goto x86_l_87f;
	case 2179ULL: goto x86_l_883;
	case 2182ULL: goto x86_l_886;
	case 2186ULL: goto x86_l_88a;
	case 2192ULL: goto x86_l_890;
	case 2198ULL: goto x86_l_896;
	case 2204ULL: goto x86_l_89c;
	case 2208ULL: goto x86_l_8a0;
	case 2211ULL: goto x86_l_8a3;
	case 2215ULL: goto x86_l_8a7;
	case 2221ULL: goto x86_l_8ad;
	case 2227ULL: goto x86_l_8b3;
	case 2233ULL: goto x86_l_8b9;
	case 2237ULL: goto x86_l_8bd;
	case 2240ULL: goto x86_l_8c0;
	case 2244ULL: goto x86_l_8c4;
	case 2250ULL: goto x86_l_8ca;
	case 2256ULL: goto x86_l_8d0;
	case 2262ULL: goto x86_l_8d6;
	case 2266ULL: goto x86_l_8da;
	case 2269ULL: goto x86_l_8dd;
	case 2273ULL: goto x86_l_8e1;
	case 2279ULL: goto x86_l_8e7;
	case 2285ULL: goto x86_l_8ed;
	case 2291ULL: goto x86_l_8f3;
	case 2295ULL: goto x86_l_8f7;
	case 2298ULL: goto x86_l_8fa;
	case 2302ULL: goto x86_l_8fe;
	case 2308ULL: goto x86_l_904;
	case 2314ULL: goto x86_l_90a;
	case 2320ULL: goto x86_l_910;
	case 2324ULL: goto x86_l_914;
	case 2327ULL: goto x86_l_917;
	case 2331ULL: goto x86_l_91b;
	case 2337ULL: goto x86_l_921;
	case 2343ULL: goto x86_l_927;
	case 2349ULL: goto x86_l_92d;
	case 2353ULL: goto x86_l_931;
	case 2356ULL: goto x86_l_934;
	case 2360ULL: goto x86_l_938;
	case 2366ULL: goto x86_l_93e;
	case 2372ULL: goto x86_l_944;
	case 2378ULL: goto x86_l_94a;
	case 2382ULL: goto x86_l_94e;
	case 2385ULL: goto x86_l_951;
	case 2389ULL: goto x86_l_955;
	case 2395ULL: goto x86_l_95b;
	case 2401ULL: goto x86_l_961;
	case 2407ULL: goto x86_l_967;
	case 2411ULL: goto x86_l_96b;
	case 2414ULL: goto x86_l_96e;
	case 2418ULL: goto x86_l_972;
	case 2424ULL: goto x86_l_978;
	case 2430ULL: goto x86_l_97e;
	case 2436ULL: goto x86_l_984;
	case 2440ULL: goto x86_l_988;
	case 2443ULL: goto x86_l_98b;
	case 2447ULL: goto x86_l_98f;
	case 2453ULL: goto x86_l_995;
	case 2459ULL: goto x86_l_99b;
	case 2465ULL: goto x86_l_9a1;
	case 2469ULL: goto x86_l_9a5;
	case 2472ULL: goto x86_l_9a8;
	case 2476ULL: goto x86_l_9ac;
	case 2482ULL: goto x86_l_9b2;
	case 2488ULL: goto x86_l_9b8;
	case 2494ULL: goto x86_l_9be;
	case 2498ULL: goto x86_l_9c2;
	case 2501ULL: goto x86_l_9c5;
	case 2505ULL: goto x86_l_9c9;
	case 2511ULL: goto x86_l_9cf;
	case 2517ULL: goto x86_l_9d5;
	case 2523ULL: goto x86_l_9db;
	case 2527ULL: goto x86_l_9df;
	case 2530ULL: goto x86_l_9e2;
	case 2534ULL: goto x86_l_9e6;
	case 2540ULL: goto x86_l_9ec;
	case 2546ULL: goto x86_l_9f2;
	case 2552ULL: goto x86_l_9f8;
	case 2556ULL: goto x86_l_9fc;
	case 2559ULL: goto x86_l_9ff;
	case 2563ULL: goto x86_l_a03;
	case 2569ULL: goto x86_l_a09;
	case 2575ULL: goto x86_l_a0f;
	case 2581ULL: goto x86_l_a15;
	case 2585ULL: goto x86_l_a19;
	case 2588ULL: goto x86_l_a1c;
	case 2592ULL: goto x86_l_a20;
	case 2598ULL: goto x86_l_a26;
	case 2604ULL: goto x86_l_a2c;
	case 2610ULL: goto x86_l_a32;
	case 2614ULL: goto x86_l_a36;
	case 2617ULL: goto x86_l_a39;
	case 2621ULL: goto x86_l_a3d;
	case 2627ULL: goto x86_l_a43;
	case 2633ULL: goto x86_l_a49;
	case 2639ULL: goto x86_l_a4f;
	case 2643ULL: goto x86_l_a53;
	case 2646ULL: goto x86_l_a56;
	case 2650ULL: goto x86_l_a5a;
	case 2656ULL: goto x86_l_a60;
	case 2662ULL: goto x86_l_a66;
	case 2668ULL: goto x86_l_a6c;
	case 2672ULL: goto x86_l_a70;
	case 2675ULL: goto x86_l_a73;
	case 2679ULL: goto x86_l_a77;
	case 2685ULL: goto x86_l_a7d;
	case 2691ULL: goto x86_l_a83;
	case 2697ULL: goto x86_l_a89;
	case 2701ULL: goto x86_l_a8d;
	case 2704ULL: goto x86_l_a90;
	case 2708ULL: goto x86_l_a94;
	case 2714ULL: goto x86_l_a9a;
	case 2720ULL: goto x86_l_aa0;
	case 2726ULL: goto x86_l_aa6;
	case 2730ULL: goto x86_l_aaa;
	case 2733ULL: goto x86_l_aad;
	case 2737ULL: goto x86_l_ab1;
	case 2743ULL: goto x86_l_ab7;
	case 2749ULL: goto x86_l_abd;
	case 2755ULL: goto x86_l_ac3;
	case 2759ULL: goto x86_l_ac7;
	case 2762ULL: goto x86_l_aca;
	case 2766ULL: goto x86_l_ace;
	case 2772ULL: goto x86_l_ad4;
	case 2778ULL: goto x86_l_ada;
	case 2784ULL: goto x86_l_ae0;
	case 2788ULL: goto x86_l_ae4;
	case 2791ULL: goto x86_l_ae7;
	case 2795ULL: goto x86_l_aeb;
	case 2801ULL: goto x86_l_af1;
	case 2807ULL: goto x86_l_af7;
	case 2813ULL: goto x86_l_afd;
	case 2817ULL: goto x86_l_b01;
	case 2820ULL: goto x86_l_b04;
	case 2824ULL: goto x86_l_b08;
	case 2830ULL: goto x86_l_b0e;
	case 2836ULL: goto x86_l_b14;
	case 2842ULL: goto x86_l_b1a;
	case 2846ULL: goto x86_l_b1e;
	case 2849ULL: goto x86_l_b21;
	case 2853ULL: goto x86_l_b25;
	case 2859ULL: goto x86_l_b2b;
	case 2865ULL: goto x86_l_b31;
	case 2871ULL: goto x86_l_b37;
	case 2875ULL: goto x86_l_b3b;
	case 2878ULL: goto x86_l_b3e;
	case 2882ULL: goto x86_l_b42;
	case 2888ULL: goto x86_l_b48;
	case 2894ULL: goto x86_l_b4e;
	case 2900ULL: goto x86_l_b54;
	case 2904ULL: goto x86_l_b58;
	case 2907ULL: goto x86_l_b5b;
	case 2911ULL: goto x86_l_b5f;
	case 2917ULL: goto x86_l_b65;
	case 2923ULL: goto x86_l_b6b;
	case 2929ULL: goto x86_l_b71;
	case 2933ULL: goto x86_l_b75;
	case 2936ULL: goto x86_l_b78;
	case 2940ULL: goto x86_l_b7c;
	case 2946ULL: goto x86_l_b82;
	case 2952ULL: goto x86_l_b88;
	case 2958ULL: goto x86_l_b8e;
	case 2962ULL: goto x86_l_b92;
	case 2965ULL: goto x86_l_b95;
	case 2969ULL: goto x86_l_b99;
	case 2975ULL: goto x86_l_b9f;
	case 2981ULL: goto x86_l_ba5;
	case 2987ULL: goto x86_l_bab;
	case 2991ULL: goto x86_l_baf;
	case 2994ULL: goto x86_l_bb2;
	case 2998ULL: goto x86_l_bb6;
	case 3004ULL: goto x86_l_bbc;
	case 3010ULL: goto x86_l_bc2;
	case 3016ULL: goto x86_l_bc8;
	case 3020ULL: goto x86_l_bcc;
	case 3023ULL: goto x86_l_bcf;
	case 3027ULL: goto x86_l_bd3;
	case 3033ULL: goto x86_l_bd9;
	case 3039ULL: goto x86_l_bdf;
	case 3045ULL: goto x86_l_be5;
	case 3049ULL: goto x86_l_be9;
	case 3052ULL: goto x86_l_bec;
	case 3056ULL: goto x86_l_bf0;
	case 3062ULL: goto x86_l_bf6;
	case 3068ULL: goto x86_l_bfc;
	case 3074ULL: goto x86_l_c02;
	case 3078ULL: goto x86_l_c06;
	case 3081ULL: goto x86_l_c09;
	case 3085ULL: goto x86_l_c0d;
	case 3091ULL: goto x86_l_c13;
	case 3097ULL: goto x86_l_c19;
	case 3103ULL: goto x86_l_c1f;
	case 3107ULL: goto x86_l_c23;
	case 3110ULL: goto x86_l_c26;
	case 3114ULL: goto x86_l_c2a;
	case 3120ULL: goto x86_l_c30;
	case 3126ULL: goto x86_l_c36;
	case 3132ULL: goto x86_l_c3c;
	case 3136ULL: goto x86_l_c40;
	case 3139ULL: goto x86_l_c43;
	case 3143ULL: goto x86_l_c47;
	case 3149ULL: goto x86_l_c4d;
	case 3155ULL: goto x86_l_c53;
	case 3161ULL: goto x86_l_c59;
	case 3165ULL: goto x86_l_c5d;
	case 3168ULL: goto x86_l_c60;
	case 3172ULL: goto x86_l_c64;
	case 3178ULL: goto x86_l_c6a;
	case 3184ULL: goto x86_l_c70;
	case 3190ULL: goto x86_l_c76;
	case 3194ULL: goto x86_l_c7a;
	case 3197ULL: goto x86_l_c7d;
	case 3201ULL: goto x86_l_c81;
	case 3207ULL: goto x86_l_c87;
	case 3213ULL: goto x86_l_c8d;
	case 3219ULL: goto x86_l_c93;
	case 3223ULL: goto x86_l_c97;
	case 3226ULL: goto x86_l_c9a;
	case 3230ULL: goto x86_l_c9e;
	case 3236ULL: goto x86_l_ca4;
	case 3242ULL: goto x86_l_caa;
	case 3248ULL: goto x86_l_cb0;
	case 3252ULL: goto x86_l_cb4;
	case 3255ULL: goto x86_l_cb7;
	case 3259ULL: goto x86_l_cbb;
	case 3265ULL: goto x86_l_cc1;
	case 3271ULL: goto x86_l_cc7;
	case 3277ULL: goto x86_l_ccd;
	case 3281ULL: goto x86_l_cd1;
	case 3284ULL: goto x86_l_cd4;
	case 3288ULL: goto x86_l_cd8;
	case 3294ULL: goto x86_l_cde;
	case 3300ULL: goto x86_l_ce4;
	case 3306ULL: goto x86_l_cea;
	case 3310ULL: goto x86_l_cee;
	case 3313ULL: goto x86_l_cf1;
	case 3317ULL: goto x86_l_cf5;
	case 3319ULL: goto x86_l_cf7;
	case 3325ULL: goto x86_l_cfd;
	case 3331ULL: goto x86_l_d03;
	case 3335ULL: goto x86_l_d07;
	case 3338ULL: goto x86_l_d0a;
	case 3342ULL: goto x86_l_d0e;
	case 3344ULL: goto x86_l_d10;
	case 3350ULL: goto x86_l_d16;
	case 3356ULL: goto x86_l_d1c;
	case 3360ULL: goto x86_l_d20;
	case 3363ULL: goto x86_l_d23;
	case 3367ULL: goto x86_l_d27;
	case 3369ULL: goto x86_l_d29;
	case 3375ULL: goto x86_l_d2f;
	case 3381ULL: goto x86_l_d35;
	case 3385ULL: goto x86_l_d39;
	case 3388ULL: goto x86_l_d3c;
	case 3392ULL: goto x86_l_d40;
	case 3394ULL: goto x86_l_d42;
	case 3400ULL: goto x86_l_d48;
	case 3406ULL: goto x86_l_d4e;
	case 3410ULL: goto x86_l_d52;
	case 3413ULL: goto x86_l_d55;
	case 3417ULL: goto x86_l_d59;
	case 3419ULL: goto x86_l_d5b;
	case 3425ULL: goto x86_l_d61;
	case 3431ULL: goto x86_l_d67;
	case 3435ULL: goto x86_l_d6b;
	case 3438ULL: goto x86_l_d6e;
	case 3443ULL: goto x86_l_d73;
	case 3446ULL: goto x86_l_d76;
	case 3449ULL: goto x86_l_d79;
	case 3454ULL: goto x86_l_d7e;
	case 3457ULL: goto x86_l_d81;
	case 3463ULL: goto x86_l_d87;
	case 3466ULL: goto x86_l_d8a;
	case 3472ULL: goto x86_l_d90;
	case 3476ULL: goto x86_l_d94;
	case 3479ULL: goto x86_l_d97;
	case 3482ULL: goto x86_l_d9a;
	case 3488ULL: goto x86_l_da0;
	case 3491ULL: goto x86_l_da3;
	case 3495ULL: goto x86_l_da7;
	case 3500ULL: goto x86_l_dac;
	case 3503ULL: goto x86_l_daf;
	case 3507ULL: goto x86_l_db3;
	case 3513ULL: goto x86_l_db9;
	case 3518ULL: goto x86_l_dbe;
	case 3521ULL: goto x86_l_dc1;
	case 3526ULL: goto x86_l_dc6;
	case 3532ULL: goto x86_l_dcc;
	case 3537ULL: goto x86_l_dd1;
	case 3540ULL: goto x86_l_dd4;
	case 3546ULL: goto x86_l_dda;
	case 3551ULL: goto x86_l_ddf;
	case 3555ULL: goto x86_l_de3;
	case 3559ULL: goto x86_l_de7;
	case 3567ULL: goto x86_l_def;
	case 3572ULL: goto x86_l_df4;
	case 3579ULL: goto x86_l_dfb;
	case 3584ULL: goto x86_l_e00;
	case 3586ULL: goto x86_l_e02;
	case 3589ULL: goto x86_l_e05;
	case 3594ULL: goto x86_l_e0a;
	case 3600ULL: goto x86_l_e10;
	case 3603ULL: goto x86_l_e13;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6fa:
	/* 0x6fa: lea    ecx,[rsi+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_700:
	/* 0x700: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_706:
	/* 0x706: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_70a:
	/* 0x70a: mov    BYTE PTR [rax+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_70d:
	/* 0x70d: cmp    rsi,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 37ULL);
x86_l_711:
	/* 0x711: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_717:
	/* 0x717: lea    ecx,[rsi+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_71d:
	/* 0x71d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_723:
	/* 0x723: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_727:
	/* 0x727: mov    BYTE PTR [rax+0x29],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_72a:
	/* 0x72a: cmp    rsi,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 38ULL);
x86_l_72e:
	/* 0x72e: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_734:
	/* 0x734: lea    ecx,[rsi+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_73a:
	/* 0x73a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_740:
	/* 0x740: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_744:
	/* 0x744: mov    BYTE PTR [rax+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_747:
	/* 0x747: cmp    rsi,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 39ULL);
x86_l_74b:
	/* 0x74b: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_751:
	/* 0x751: lea    ecx,[rsi+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_757:
	/* 0x757: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_75d:
	/* 0x75d: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_761:
	/* 0x761: mov    BYTE PTR [rax+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_764:
	/* 0x764: cmp    rsi,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 40ULL);
x86_l_768:
	/* 0x768: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_76e:
	/* 0x76e: lea    ecx,[rsi+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_774:
	/* 0x774: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_77a:
	/* 0x77a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_77e:
	/* 0x77e: mov    BYTE PTR [rax+0x2c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_781:
	/* 0x781: cmp    rsi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 41ULL);
x86_l_785:
	/* 0x785: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_78b:
	/* 0x78b: lea    ecx,[rsi+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_791:
	/* 0x791: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_797:
	/* 0x797: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_79b:
	/* 0x79b: mov    BYTE PTR [rax+0x2d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_79e:
	/* 0x79e: cmp    rsi,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 42ULL);
x86_l_7a2:
	/* 0x7a2: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_7a8:
	/* 0x7a8: lea    ecx,[rsi+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_7ae:
	/* 0x7ae: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7b4:
	/* 0x7b4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_7b8:
	/* 0x7b8: mov    BYTE PTR [rax+0x2e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_7bb:
	/* 0x7bb: cmp    rsi,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 43ULL);
x86_l_7bf:
	/* 0x7bf: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_7c5:
	/* 0x7c5: lea    ecx,[rsi+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_7cb:
	/* 0x7cb: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7d1:
	/* 0x7d1: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_7d5:
	/* 0x7d5: mov    BYTE PTR [rax+0x2f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_7d8:
	/* 0x7d8: cmp    rsi,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 44ULL);
x86_l_7dc:
	/* 0x7dc: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_7e2:
	/* 0x7e2: lea    ecx,[rsi+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_7e8:
	/* 0x7e8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7ee:
	/* 0x7ee: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_7f2:
	/* 0x7f2: mov    BYTE PTR [rax+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7f5:
	/* 0x7f5: cmp    rsi,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 45ULL);
x86_l_7f9:
	/* 0x7f9: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_7ff:
	/* 0x7ff: lea    ecx,[rsi+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_805:
	/* 0x805: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_80b:
	/* 0x80b: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_80f:
	/* 0x80f: mov    BYTE PTR [rax+0x31],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_812:
	/* 0x812: cmp    rsi,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 46ULL);
x86_l_816:
	/* 0x816: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_81c:
	/* 0x81c: lea    ecx,[rsi+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_822:
	/* 0x822: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_828:
	/* 0x828: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_82c:
	/* 0x82c: mov    BYTE PTR [rax+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_82f:
	/* 0x82f: cmp    rsi,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 47ULL);
x86_l_833:
	/* 0x833: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_839:
	/* 0x839: lea    ecx,[rsi+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_83f:
	/* 0x83f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_845:
	/* 0x845: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_849:
	/* 0x849: mov    BYTE PTR [rax+0x33],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_84c:
	/* 0x84c: cmp    rsi,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 48ULL);
x86_l_850:
	/* 0x850: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_856:
	/* 0x856: lea    ecx,[rsi+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_85c:
	/* 0x85c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_862:
	/* 0x862: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_866:
	/* 0x866: mov    BYTE PTR [rax+0x34],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_869:
	/* 0x869: cmp    rsi,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 49ULL);
x86_l_86d:
	/* 0x86d: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_873:
	/* 0x873: lea    ecx,[rsi+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_879:
	/* 0x879: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_87f:
	/* 0x87f: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_883:
	/* 0x883: mov    BYTE PTR [rax+0x35],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_886:
	/* 0x886: cmp    rsi,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 50ULL);
x86_l_88a:
	/* 0x88a: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_890:
	/* 0x890: lea    ecx,[rsi+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_896:
	/* 0x896: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_89c:
	/* 0x89c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8a0:
	/* 0x8a0: mov    BYTE PTR [rax+0x36],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_8a3:
	/* 0x8a3: cmp    rsi,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 51ULL);
x86_l_8a7:
	/* 0x8a7: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_8ad:
	/* 0x8ad: lea    ecx,[rsi+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_8b3:
	/* 0x8b3: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8b9:
	/* 0x8b9: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8bd:
	/* 0x8bd: mov    BYTE PTR [rax+0x37],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_8c0:
	/* 0x8c0: cmp    rsi,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 52ULL);
x86_l_8c4:
	/* 0x8c4: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_8ca:
	/* 0x8ca: lea    ecx,[rsi+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_8d0:
	/* 0x8d0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8d6:
	/* 0x8d6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8da:
	/* 0x8da: mov    BYTE PTR [rax+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8dd:
	/* 0x8dd: cmp    rsi,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 53ULL);
x86_l_8e1:
	/* 0x8e1: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_8e7:
	/* 0x8e7: lea    ecx,[rsi+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_8ed:
	/* 0x8ed: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8f3:
	/* 0x8f3: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8f7:
	/* 0x8f7: mov    BYTE PTR [rax+0x39],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_8fa:
	/* 0x8fa: cmp    rsi,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 54ULL);
x86_l_8fe:
	/* 0x8fe: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_904:
	/* 0x904: lea    ecx,[rsi+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_90a:
	/* 0x90a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_910:
	/* 0x910: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_914:
	/* 0x914: mov    BYTE PTR [rax+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_917:
	/* 0x917: cmp    rsi,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 55ULL);
x86_l_91b:
	/* 0x91b: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_921:
	/* 0x921: lea    ecx,[rsi+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_927:
	/* 0x927: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_92d:
	/* 0x92d: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_931:
	/* 0x931: mov    BYTE PTR [rax+0x3b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_934:
	/* 0x934: cmp    rsi,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 56ULL);
x86_l_938:
	/* 0x938: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_93e:
	/* 0x93e: lea    ecx,[rsi+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_944:
	/* 0x944: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_94a:
	/* 0x94a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_94e:
	/* 0x94e: mov    BYTE PTR [rax+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_951:
	/* 0x951: cmp    rsi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 57ULL);
x86_l_955:
	/* 0x955: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_95b:
	/* 0x95b: lea    ecx,[rsi+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_961:
	/* 0x961: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_967:
	/* 0x967: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_96b:
	/* 0x96b: mov    BYTE PTR [rax+0x3d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_96e:
	/* 0x96e: cmp    rsi,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 58ULL);
x86_l_972:
	/* 0x972: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_978:
	/* 0x978: lea    ecx,[rsi+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_97e:
	/* 0x97e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_984:
	/* 0x984: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_988:
	/* 0x988: mov    BYTE PTR [rax+0x3e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_98b:
	/* 0x98b: cmp    rsi,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 59ULL);
x86_l_98f:
	/* 0x98f: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_995:
	/* 0x995: lea    ecx,[rsi+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_99b:
	/* 0x99b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9a1:
	/* 0x9a1: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_9a5:
	/* 0x9a5: mov    BYTE PTR [rax+0x3f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_9a8:
	/* 0x9a8: cmp    rsi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 60ULL);
x86_l_9ac:
	/* 0x9ac: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_9b2:
	/* 0x9b2: lea    ecx,[rsi+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_9b8:
	/* 0x9b8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9be:
	/* 0x9be: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_9c2:
	/* 0x9c2: mov    BYTE PTR [rax+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9c5:
	/* 0x9c5: cmp    rsi,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 61ULL);
x86_l_9c9:
	/* 0x9c9: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_9cf:
	/* 0x9cf: lea    ecx,[rsi+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_9d5:
	/* 0x9d5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9db:
	/* 0x9db: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_9df:
	/* 0x9df: mov    BYTE PTR [rax+0x41],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_9e2:
	/* 0x9e2: cmp    rsi,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 62ULL);
x86_l_9e6:
	/* 0x9e6: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_9ec:
	/* 0x9ec: lea    ecx,[rsi+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_9f2:
	/* 0x9f2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9f8:
	/* 0x9f8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_9fc:
	/* 0x9fc: mov    BYTE PTR [rax+0x42],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_9ff:
	/* 0x9ff: cmp    rsi,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 63ULL);
x86_l_a03:
	/* 0xa03: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_a09:
	/* 0xa09: lea    ecx,[rsi+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_a0f:
	/* 0xa0f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a15:
	/* 0xa15: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a19:
	/* 0xa19: mov    BYTE PTR [rax+0x43],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_a1c:
	/* 0xa1c: cmp    rsi,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 64ULL);
x86_l_a20:
	/* 0xa20: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_a26:
	/* 0xa26: lea    ecx,[rsi+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_a2c:
	/* 0xa2c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a32:
	/* 0xa32: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a36:
	/* 0xa36: mov    BYTE PTR [rax+0x44],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_a39:
	/* 0xa39: cmp    rsi,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 65ULL);
x86_l_a3d:
	/* 0xa3d: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_a43:
	/* 0xa43: lea    ecx,[rsi+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_a49:
	/* 0xa49: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a4f:
	/* 0xa4f: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a53:
	/* 0xa53: mov    BYTE PTR [rax+0x45],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_a56:
	/* 0xa56: cmp    rsi,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 66ULL);
x86_l_a5a:
	/* 0xa5a: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_a60:
	/* 0xa60: lea    ecx,[rsi+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_a66:
	/* 0xa66: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a6c:
	/* 0xa6c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a70:
	/* 0xa70: mov    BYTE PTR [rax+0x46],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_a73:
	/* 0xa73: cmp    rsi,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 67ULL);
x86_l_a77:
	/* 0xa77: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_a7d:
	/* 0xa7d: lea    ecx,[rsi+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_a83:
	/* 0xa83: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a89:
	/* 0xa89: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a8d:
	/* 0xa8d: mov    BYTE PTR [rax+0x47],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_a90:
	/* 0xa90: cmp    rsi,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 68ULL);
x86_l_a94:
	/* 0xa94: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_a9a:
	/* 0xa9a: lea    ecx,[rsi+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_aa0:
	/* 0xaa0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_aa6:
	/* 0xaa6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_aaa:
	/* 0xaaa: mov    BYTE PTR [rax+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_aad:
	/* 0xaad: cmp    rsi,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 69ULL);
x86_l_ab1:
	/* 0xab1: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_ab7:
	/* 0xab7: lea    ecx,[rsi+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_abd:
	/* 0xabd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ac3:
	/* 0xac3: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ac7:
	/* 0xac7: mov    BYTE PTR [rax+0x49],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_aca:
	/* 0xaca: cmp    rsi,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 70ULL);
x86_l_ace:
	/* 0xace: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_ad4:
	/* 0xad4: lea    ecx,[rsi+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_ada:
	/* 0xada: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ae0:
	/* 0xae0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ae4:
	/* 0xae4: mov    BYTE PTR [rax+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_ae7:
	/* 0xae7: cmp    rsi,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 71ULL);
x86_l_aeb:
	/* 0xaeb: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_af1:
	/* 0xaf1: lea    ecx,[rsi+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_af7:
	/* 0xaf7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_afd:
	/* 0xafd: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b01:
	/* 0xb01: mov    BYTE PTR [rax+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_b04:
	/* 0xb04: cmp    rsi,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 72ULL);
x86_l_b08:
	/* 0xb08: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_b0e:
	/* 0xb0e: lea    ecx,[rsi+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_b14:
	/* 0xb14: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b1a:
	/* 0xb1a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b1e:
	/* 0xb1e: mov    BYTE PTR [rax+0x4c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_b21:
	/* 0xb21: cmp    rsi,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 73ULL);
x86_l_b25:
	/* 0xb25: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_b2b:
	/* 0xb2b: lea    ecx,[rsi+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_b31:
	/* 0xb31: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b37:
	/* 0xb37: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b3b:
	/* 0xb3b: mov    BYTE PTR [rax+0x4d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_b3e:
	/* 0xb3e: cmp    rsi,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 74ULL);
x86_l_b42:
	/* 0xb42: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_b48:
	/* 0xb48: lea    ecx,[rsi+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_b4e:
	/* 0xb4e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b54:
	/* 0xb54: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b58:
	/* 0xb58: mov    BYTE PTR [rax+0x4e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_b5b:
	/* 0xb5b: cmp    rsi,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 75ULL);
x86_l_b5f:
	/* 0xb5f: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_b65:
	/* 0xb65: lea    ecx,[rsi+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_b6b:
	/* 0xb6b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b71:
	/* 0xb71: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b75:
	/* 0xb75: mov    BYTE PTR [rax+0x4f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_b78:
	/* 0xb78: cmp    rsi,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 76ULL);
x86_l_b7c:
	/* 0xb7c: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_b82:
	/* 0xb82: lea    ecx,[rsi+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_b88:
	/* 0xb88: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b8e:
	/* 0xb8e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b92:
	/* 0xb92: mov    BYTE PTR [rax+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b95:
	/* 0xb95: cmp    rsi,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 77ULL);
x86_l_b99:
	/* 0xb99: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_b9f:
	/* 0xb9f: lea    ecx,[rsi+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_ba5:
	/* 0xba5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bab:
	/* 0xbab: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_baf:
	/* 0xbaf: mov    BYTE PTR [rax+0x51],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_bb2:
	/* 0xbb2: cmp    rsi,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 78ULL);
x86_l_bb6:
	/* 0xbb6: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_bbc:
	/* 0xbbc: lea    ecx,[rsi+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_bc2:
	/* 0xbc2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bc8:
	/* 0xbc8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_bcc:
	/* 0xbcc: mov    BYTE PTR [rax+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_bcf:
	/* 0xbcf: cmp    rsi,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 79ULL);
x86_l_bd3:
	/* 0xbd3: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_bd9:
	/* 0xbd9: lea    ecx,[rsi+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_bdf:
	/* 0xbdf: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_be5:
	/* 0xbe5: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_be9:
	/* 0xbe9: mov    BYTE PTR [rax+0x53],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_bec:
	/* 0xbec: cmp    rsi,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 80ULL);
x86_l_bf0:
	/* 0xbf0: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_bf6:
	/* 0xbf6: lea    ecx,[rsi+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_bfc:
	/* 0xbfc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c02:
	/* 0xc02: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c06:
	/* 0xc06: mov    BYTE PTR [rax+0x54],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_c09:
	/* 0xc09: cmp    rsi,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 81ULL);
x86_l_c0d:
	/* 0xc0d: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_c13:
	/* 0xc13: lea    ecx,[rsi+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_c19:
	/* 0xc19: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c1f:
	/* 0xc1f: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c23:
	/* 0xc23: mov    BYTE PTR [rax+0x55],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_c26:
	/* 0xc26: cmp    rsi,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 82ULL);
x86_l_c2a:
	/* 0xc2a: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_c30:
	/* 0xc30: lea    ecx,[rsi+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_c36:
	/* 0xc36: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c3c:
	/* 0xc3c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c40:
	/* 0xc40: mov    BYTE PTR [rax+0x56],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_c43:
	/* 0xc43: cmp    rsi,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 83ULL);
x86_l_c47:
	/* 0xc47: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_c4d:
	/* 0xc4d: lea    ecx,[rsi+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_c53:
	/* 0xc53: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c59:
	/* 0xc59: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c5d:
	/* 0xc5d: mov    BYTE PTR [rax+0x57],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_c60:
	/* 0xc60: cmp    rsi,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 84ULL);
x86_l_c64:
	/* 0xc64: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_c6a:
	/* 0xc6a: lea    ecx,[rsi+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_c70:
	/* 0xc70: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c76:
	/* 0xc76: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c7a:
	/* 0xc7a: mov    BYTE PTR [rax+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c7d:
	/* 0xc7d: cmp    rsi,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 85ULL);
x86_l_c81:
	/* 0xc81: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_c87:
	/* 0xc87: lea    ecx,[rsi+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_c8d:
	/* 0xc8d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c93:
	/* 0xc93: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c97:
	/* 0xc97: mov    BYTE PTR [rax+0x59],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_c9a:
	/* 0xc9a: cmp    rsi,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 86ULL);
x86_l_c9e:
	/* 0xc9e: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_ca4:
	/* 0xca4: lea    ecx,[rsi+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_caa:
	/* 0xcaa: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_cb0:
	/* 0xcb0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_cb4:
	/* 0xcb4: mov    BYTE PTR [rax+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_cb7:
	/* 0xcb7: cmp    rsi,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 87ULL);
x86_l_cbb:
	/* 0xcbb: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_cc1:
	/* 0xcc1: lea    ecx,[rsi+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_cc7:
	/* 0xcc7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ccd:
	/* 0xccd: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_cd1:
	/* 0xcd1: mov    BYTE PTR [rax+0x5b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_cd4:
	/* 0xcd4: cmp    rsi,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 88ULL);
x86_l_cd8:
	/* 0xcd8: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_cde:
	/* 0xcde: lea    ecx,[rsi+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_ce4:
	/* 0xce4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_cea:
	/* 0xcea: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_cee:
	/* 0xcee: mov    BYTE PTR [rax+0x5c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_cf1:
	/* 0xcf1: cmp    rsi,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 89ULL);
x86_l_cf5:
	/* 0xcf5: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_cf7:
	/* 0xcf7: lea    ecx,[rsi+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_cfd:
	/* 0xcfd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_d03:
	/* 0xd03: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_d07:
	/* 0xd07: mov    BYTE PTR [rax+0x5d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_d0a:
	/* 0xd0a: cmp    rsi,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 90ULL);
x86_l_d0e:
	/* 0xd0e: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_d10:
	/* 0xd10: lea    ecx,[rsi+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_d16:
	/* 0xd16: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_d1c:
	/* 0xd1c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_d20:
	/* 0xd20: mov    BYTE PTR [rax+0x5e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_d23:
	/* 0xd23: cmp    rsi,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 91ULL);
x86_l_d27:
	/* 0xd27: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_d29:
	/* 0xd29: lea    ecx,[rsi+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_d2f:
	/* 0xd2f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_d35:
	/* 0xd35: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_d39:
	/* 0xd39: mov    BYTE PTR [rax+0x5f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_d3c:
	/* 0xd3c: cmp    rsi,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 92ULL);
x86_l_d40:
	/* 0xd40: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_d42:
	/* 0xd42: lea    ecx,[rsi+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_d48:
	/* 0xd48: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_d4e:
	/* 0xd4e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_d52:
	/* 0xd52: mov    BYTE PTR [rax+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d55:
	/* 0xd55: cmp    rsi,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 93ULL);
x86_l_d59:
	/* 0xd59: je     d6e <generic_fentry_filter_arg+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_d5b:
	/* 0xd5b: add    esi,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_d61:
	/* 0xd61: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_d67:
	/* 0xd67: movzx  ecx,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_d6b:
	/* 0xd6b: mov    BYTE PTR [rax+0x61],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_d6e:
	/* 0xd6e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d73:
	/* 0xd73: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_d76:
	/* 0xd76: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d79:
	/* 0xd79: jmp    3706 <generic_fentry_filter_arg+0x3706> */
	return 14086ULL;
x86_l_d7e:
	/* 0xd7e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d81:
	/* 0xd81: je     1c33 <generic_fentry_filter_arg+0x1c33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7219ULL;
	}
x86_l_d87:
	/* 0xd87: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d8a:
	/* 0xd8a: jne    383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14394ULL;
	}
x86_l_d90:
	/* 0xd90: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d94:
	/* 0xd94: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d97:
	/* 0xd97: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_d9a:
	/* 0xd9a: ja     381a <generic_fentry_filter_arg+0x381a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14362ULL;
	}
x86_l_da0:
	/* 0xda0: mov    edx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_da3:
	/* 0xda3: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_da7:
	/* 0xda7: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_dac:
	/* 0xdac: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_daf:
	/* 0xdaf: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db3:
	/* 0xdb3: jb     2ec4 <generic_fentry_filter_arg+0x2ec4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11972ULL;
	}
x86_l_db9:
	/* 0xdb9: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_dbe:
	/* 0xdbe: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_dc1:
	/* 0xdc1: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc6:
	/* 0xdc6: jb     2e1e <generic_fentry_filter_arg+0x2e1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11806ULL;
	}
x86_l_dcc:
	/* 0xdcc: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_dd1:
	/* 0xdd1: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_dd4:
	/* 0xdd4: jae    381a <generic_fentry_filter_arg+0x381a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14362ULL;
	}
x86_l_dda:
	/* 0xdda: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ddf:
	/* 0xddf: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de3:
	/* 0xde3: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_de7:
	/* 0xde7: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_def:
	/* 0xdef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_df4:
	/* 0xdf4: mov    rdi,QWORD PTR [rip+0x5d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_dfb:
	/* 0xdfb: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e00:
	/* 0xe00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e02:
	/* 0xe02: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e05:
	/* 0xe05: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e0a:
	/* 0xe0a: je     3811 <generic_fentry_filter_arg+0x3811> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14353ULL;
	}
x86_l_e10:
	/* 0xe10: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e13:
	/* 0xe13: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 3606ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3606ULL: goto x86_l_e16;
	case 3612ULL: goto x86_l_e1c;
	case 3617ULL: goto x86_l_e21;
	case 3624ULL: goto x86_l_e28;
	case 3629ULL: goto x86_l_e2d;
	case 3631ULL: goto x86_l_e2f;
	case 3634ULL: goto x86_l_e32;
	case 3640ULL: goto x86_l_e38;
	case 3644ULL: goto x86_l_e3c;
	case 3647ULL: goto x86_l_e3f;
	case 3652ULL: goto x86_l_e44;
	case 3655ULL: goto x86_l_e47;
	case 3658ULL: goto x86_l_e4a;
	case 3660ULL: goto x86_l_e4c;
	case 3663ULL: goto x86_l_e4f;
	case 3669ULL: goto x86_l_e55;
	case 3674ULL: goto x86_l_e5a;
	case 3678ULL: goto x86_l_e5e;
	case 3681ULL: goto x86_l_e61;
	case 3685ULL: goto x86_l_e65;
	case 3691ULL: goto x86_l_e6b;
	case 3695ULL: goto x86_l_e6f;
	case 3701ULL: goto x86_l_e75;
	case 3707ULL: goto x86_l_e7b;
	case 3712ULL: goto x86_l_e80;
	case 3716ULL: goto x86_l_e84;
	case 3719ULL: goto x86_l_e87;
	case 3723ULL: goto x86_l_e8b;
	case 3729ULL: goto x86_l_e91;
	case 3733ULL: goto x86_l_e95;
	case 3739ULL: goto x86_l_e9b;
	case 3745ULL: goto x86_l_ea1;
	case 3750ULL: goto x86_l_ea6;
	case 3754ULL: goto x86_l_eaa;
	case 3757ULL: goto x86_l_ead;
	case 3761ULL: goto x86_l_eb1;
	case 3767ULL: goto x86_l_eb7;
	case 3771ULL: goto x86_l_ebb;
	case 3777ULL: goto x86_l_ec1;
	case 3783ULL: goto x86_l_ec7;
	case 3788ULL: goto x86_l_ecc;
	case 3792ULL: goto x86_l_ed0;
	case 3795ULL: goto x86_l_ed3;
	case 3799ULL: goto x86_l_ed7;
	case 3805ULL: goto x86_l_edd;
	case 3809ULL: goto x86_l_ee1;
	case 3815ULL: goto x86_l_ee7;
	case 3821ULL: goto x86_l_eed;
	case 3826ULL: goto x86_l_ef2;
	case 3830ULL: goto x86_l_ef6;
	case 3833ULL: goto x86_l_ef9;
	case 3837ULL: goto x86_l_efd;
	case 3843ULL: goto x86_l_f03;
	case 3847ULL: goto x86_l_f07;
	case 3853ULL: goto x86_l_f0d;
	case 3859ULL: goto x86_l_f13;
	case 3864ULL: goto x86_l_f18;
	case 3868ULL: goto x86_l_f1c;
	case 3871ULL: goto x86_l_f1f;
	case 3875ULL: goto x86_l_f23;
	case 3881ULL: goto x86_l_f29;
	case 3885ULL: goto x86_l_f2d;
	case 3891ULL: goto x86_l_f33;
	case 3897ULL: goto x86_l_f39;
	case 3902ULL: goto x86_l_f3e;
	case 3906ULL: goto x86_l_f42;
	case 3909ULL: goto x86_l_f45;
	case 3913ULL: goto x86_l_f49;
	case 3919ULL: goto x86_l_f4f;
	case 3923ULL: goto x86_l_f53;
	case 3929ULL: goto x86_l_f59;
	case 3935ULL: goto x86_l_f5f;
	case 3940ULL: goto x86_l_f64;
	case 3944ULL: goto x86_l_f68;
	case 3947ULL: goto x86_l_f6b;
	case 3951ULL: goto x86_l_f6f;
	case 3957ULL: goto x86_l_f75;
	case 3961ULL: goto x86_l_f79;
	case 3967ULL: goto x86_l_f7f;
	case 3973ULL: goto x86_l_f85;
	case 3978ULL: goto x86_l_f8a;
	case 3982ULL: goto x86_l_f8e;
	case 3985ULL: goto x86_l_f91;
	case 3989ULL: goto x86_l_f95;
	case 3995ULL: goto x86_l_f9b;
	case 3999ULL: goto x86_l_f9f;
	case 4005ULL: goto x86_l_fa5;
	case 4011ULL: goto x86_l_fab;
	case 4016ULL: goto x86_l_fb0;
	case 4020ULL: goto x86_l_fb4;
	case 4023ULL: goto x86_l_fb7;
	case 4027ULL: goto x86_l_fbb;
	case 4033ULL: goto x86_l_fc1;
	case 4037ULL: goto x86_l_fc5;
	case 4043ULL: goto x86_l_fcb;
	case 4049ULL: goto x86_l_fd1;
	case 4054ULL: goto x86_l_fd6;
	case 4058ULL: goto x86_l_fda;
	case 4061ULL: goto x86_l_fdd;
	case 4065ULL: goto x86_l_fe1;
	case 4071ULL: goto x86_l_fe7;
	case 4075ULL: goto x86_l_feb;
	case 4081ULL: goto x86_l_ff1;
	case 4087ULL: goto x86_l_ff7;
	case 4092ULL: goto x86_l_ffc;
	case 4096ULL: goto x86_l_1000;
	case 4099ULL: goto x86_l_1003;
	case 4103ULL: goto x86_l_1007;
	case 4109ULL: goto x86_l_100d;
	case 4113ULL: goto x86_l_1011;
	case 4119ULL: goto x86_l_1017;
	case 4125ULL: goto x86_l_101d;
	case 4130ULL: goto x86_l_1022;
	case 4134ULL: goto x86_l_1026;
	case 4137ULL: goto x86_l_1029;
	case 4141ULL: goto x86_l_102d;
	case 4147ULL: goto x86_l_1033;
	case 4151ULL: goto x86_l_1037;
	case 4157ULL: goto x86_l_103d;
	case 4163ULL: goto x86_l_1043;
	case 4168ULL: goto x86_l_1048;
	case 4172ULL: goto x86_l_104c;
	case 4175ULL: goto x86_l_104f;
	case 4179ULL: goto x86_l_1053;
	case 4185ULL: goto x86_l_1059;
	case 4189ULL: goto x86_l_105d;
	case 4195ULL: goto x86_l_1063;
	case 4201ULL: goto x86_l_1069;
	case 4206ULL: goto x86_l_106e;
	case 4210ULL: goto x86_l_1072;
	case 4213ULL: goto x86_l_1075;
	case 4217ULL: goto x86_l_1079;
	case 4223ULL: goto x86_l_107f;
	case 4227ULL: goto x86_l_1083;
	case 4233ULL: goto x86_l_1089;
	case 4239ULL: goto x86_l_108f;
	case 4244ULL: goto x86_l_1094;
	case 4248ULL: goto x86_l_1098;
	case 4251ULL: goto x86_l_109b;
	case 4255ULL: goto x86_l_109f;
	case 4261ULL: goto x86_l_10a5;
	case 4265ULL: goto x86_l_10a9;
	case 4271ULL: goto x86_l_10af;
	case 4277ULL: goto x86_l_10b5;
	case 4282ULL: goto x86_l_10ba;
	case 4286ULL: goto x86_l_10be;
	case 4289ULL: goto x86_l_10c1;
	case 4293ULL: goto x86_l_10c5;
	case 4299ULL: goto x86_l_10cb;
	case 4303ULL: goto x86_l_10cf;
	case 4309ULL: goto x86_l_10d5;
	case 4315ULL: goto x86_l_10db;
	case 4320ULL: goto x86_l_10e0;
	case 4324ULL: goto x86_l_10e4;
	case 4327ULL: goto x86_l_10e7;
	case 4331ULL: goto x86_l_10eb;
	case 4337ULL: goto x86_l_10f1;
	case 4341ULL: goto x86_l_10f5;
	case 4347ULL: goto x86_l_10fb;
	case 4353ULL: goto x86_l_1101;
	case 4358ULL: goto x86_l_1106;
	case 4362ULL: goto x86_l_110a;
	case 4365ULL: goto x86_l_110d;
	case 4369ULL: goto x86_l_1111;
	case 4375ULL: goto x86_l_1117;
	case 4379ULL: goto x86_l_111b;
	case 4385ULL: goto x86_l_1121;
	case 4391ULL: goto x86_l_1127;
	case 4396ULL: goto x86_l_112c;
	case 4400ULL: goto x86_l_1130;
	case 4403ULL: goto x86_l_1133;
	case 4407ULL: goto x86_l_1137;
	case 4413ULL: goto x86_l_113d;
	case 4417ULL: goto x86_l_1141;
	case 4423ULL: goto x86_l_1147;
	case 4429ULL: goto x86_l_114d;
	case 4434ULL: goto x86_l_1152;
	case 4438ULL: goto x86_l_1156;
	case 4441ULL: goto x86_l_1159;
	case 4445ULL: goto x86_l_115d;
	case 4451ULL: goto x86_l_1163;
	case 4455ULL: goto x86_l_1167;
	case 4461ULL: goto x86_l_116d;
	case 4467ULL: goto x86_l_1173;
	case 4472ULL: goto x86_l_1178;
	case 4476ULL: goto x86_l_117c;
	case 4479ULL: goto x86_l_117f;
	case 4483ULL: goto x86_l_1183;
	case 4489ULL: goto x86_l_1189;
	case 4493ULL: goto x86_l_118d;
	case 4499ULL: goto x86_l_1193;
	case 4505ULL: goto x86_l_1199;
	case 4510ULL: goto x86_l_119e;
	case 4514ULL: goto x86_l_11a2;
	case 4517ULL: goto x86_l_11a5;
	case 4521ULL: goto x86_l_11a9;
	case 4527ULL: goto x86_l_11af;
	case 4531ULL: goto x86_l_11b3;
	case 4537ULL: goto x86_l_11b9;
	case 4543ULL: goto x86_l_11bf;
	case 4548ULL: goto x86_l_11c4;
	case 4552ULL: goto x86_l_11c8;
	case 4555ULL: goto x86_l_11cb;
	case 4559ULL: goto x86_l_11cf;
	case 4565ULL: goto x86_l_11d5;
	case 4569ULL: goto x86_l_11d9;
	case 4575ULL: goto x86_l_11df;
	case 4581ULL: goto x86_l_11e5;
	case 4586ULL: goto x86_l_11ea;
	case 4590ULL: goto x86_l_11ee;
	case 4593ULL: goto x86_l_11f1;
	case 4597ULL: goto x86_l_11f5;
	case 4603ULL: goto x86_l_11fb;
	case 4607ULL: goto x86_l_11ff;
	case 4613ULL: goto x86_l_1205;
	case 4619ULL: goto x86_l_120b;
	case 4624ULL: goto x86_l_1210;
	case 4628ULL: goto x86_l_1214;
	case 4631ULL: goto x86_l_1217;
	case 4635ULL: goto x86_l_121b;
	case 4641ULL: goto x86_l_1221;
	case 4645ULL: goto x86_l_1225;
	case 4651ULL: goto x86_l_122b;
	case 4657ULL: goto x86_l_1231;
	case 4662ULL: goto x86_l_1236;
	case 4666ULL: goto x86_l_123a;
	case 4669ULL: goto x86_l_123d;
	case 4673ULL: goto x86_l_1241;
	case 4679ULL: goto x86_l_1247;
	case 4683ULL: goto x86_l_124b;
	case 4689ULL: goto x86_l_1251;
	case 4695ULL: goto x86_l_1257;
	case 4700ULL: goto x86_l_125c;
	case 4704ULL: goto x86_l_1260;
	case 4707ULL: goto x86_l_1263;
	case 4711ULL: goto x86_l_1267;
	case 4717ULL: goto x86_l_126d;
	case 4721ULL: goto x86_l_1271;
	case 4727ULL: goto x86_l_1277;
	case 4733ULL: goto x86_l_127d;
	case 4738ULL: goto x86_l_1282;
	case 4742ULL: goto x86_l_1286;
	case 4745ULL: goto x86_l_1289;
	case 4749ULL: goto x86_l_128d;
	case 4755ULL: goto x86_l_1293;
	case 4759ULL: goto x86_l_1297;
	case 4765ULL: goto x86_l_129d;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4780ULL: goto x86_l_12ac;
	case 4783ULL: goto x86_l_12af;
	case 4787ULL: goto x86_l_12b3;
	case 4793ULL: goto x86_l_12b9;
	case 4797ULL: goto x86_l_12bd;
	case 4803ULL: goto x86_l_12c3;
	case 4809ULL: goto x86_l_12c9;
	case 4814ULL: goto x86_l_12ce;
	case 4818ULL: goto x86_l_12d2;
	case 4821ULL: goto x86_l_12d5;
	case 4825ULL: goto x86_l_12d9;
	case 4831ULL: goto x86_l_12df;
	case 4835ULL: goto x86_l_12e3;
	case 4841ULL: goto x86_l_12e9;
	case 4847ULL: goto x86_l_12ef;
	case 4852ULL: goto x86_l_12f4;
	case 4856ULL: goto x86_l_12f8;
	case 4859ULL: goto x86_l_12fb;
	case 4863ULL: goto x86_l_12ff;
	case 4869ULL: goto x86_l_1305;
	case 4873ULL: goto x86_l_1309;
	case 4879ULL: goto x86_l_130f;
	case 4885ULL: goto x86_l_1315;
	case 4890ULL: goto x86_l_131a;
	case 4894ULL: goto x86_l_131e;
	case 4897ULL: goto x86_l_1321;
	case 4901ULL: goto x86_l_1325;
	case 4907ULL: goto x86_l_132b;
	case 4911ULL: goto x86_l_132f;
	case 4917ULL: goto x86_l_1335;
	case 4923ULL: goto x86_l_133b;
	case 4928ULL: goto x86_l_1340;
	case 4932ULL: goto x86_l_1344;
	case 4935ULL: goto x86_l_1347;
	case 4939ULL: goto x86_l_134b;
	case 4945ULL: goto x86_l_1351;
	case 4949ULL: goto x86_l_1355;
	case 4955ULL: goto x86_l_135b;
	case 4961ULL: goto x86_l_1361;
	case 4966ULL: goto x86_l_1366;
	case 4970ULL: goto x86_l_136a;
	case 4973ULL: goto x86_l_136d;
	case 4977ULL: goto x86_l_1371;
	case 4983ULL: goto x86_l_1377;
	case 4987ULL: goto x86_l_137b;
	case 4993ULL: goto x86_l_1381;
	case 4999ULL: goto x86_l_1387;
	case 5004ULL: goto x86_l_138c;
	case 5008ULL: goto x86_l_1390;
	case 5011ULL: goto x86_l_1393;
	case 5015ULL: goto x86_l_1397;
	case 5021ULL: goto x86_l_139d;
	case 5025ULL: goto x86_l_13a1;
	case 5031ULL: goto x86_l_13a7;
	case 5037ULL: goto x86_l_13ad;
	case 5042ULL: goto x86_l_13b2;
	case 5046ULL: goto x86_l_13b6;
	case 5049ULL: goto x86_l_13b9;
	case 5053ULL: goto x86_l_13bd;
	case 5059ULL: goto x86_l_13c3;
	case 5063ULL: goto x86_l_13c7;
	case 5069ULL: goto x86_l_13cd;
	case 5075ULL: goto x86_l_13d3;
	case 5080ULL: goto x86_l_13d8;
	case 5084ULL: goto x86_l_13dc;
	case 5087ULL: goto x86_l_13df;
	case 5091ULL: goto x86_l_13e3;
	case 5097ULL: goto x86_l_13e9;
	case 5101ULL: goto x86_l_13ed;
	case 5107ULL: goto x86_l_13f3;
	case 5113ULL: goto x86_l_13f9;
	case 5118ULL: goto x86_l_13fe;
	case 5122ULL: goto x86_l_1402;
	case 5125ULL: goto x86_l_1405;
	case 5129ULL: goto x86_l_1409;
	case 5135ULL: goto x86_l_140f;
	case 5139ULL: goto x86_l_1413;
	case 5145ULL: goto x86_l_1419;
	case 5151ULL: goto x86_l_141f;
	case 5156ULL: goto x86_l_1424;
	case 5160ULL: goto x86_l_1428;
	case 5163ULL: goto x86_l_142b;
	case 5167ULL: goto x86_l_142f;
	case 5173ULL: goto x86_l_1435;
	case 5177ULL: goto x86_l_1439;
	case 5183ULL: goto x86_l_143f;
	case 5189ULL: goto x86_l_1445;
	case 5194ULL: goto x86_l_144a;
	case 5198ULL: goto x86_l_144e;
	case 5201ULL: goto x86_l_1451;
	case 5205ULL: goto x86_l_1455;
	case 5211ULL: goto x86_l_145b;
	case 5215ULL: goto x86_l_145f;
	case 5221ULL: goto x86_l_1465;
	case 5227ULL: goto x86_l_146b;
	case 5232ULL: goto x86_l_1470;
	case 5236ULL: goto x86_l_1474;
	case 5239ULL: goto x86_l_1477;
	case 5243ULL: goto x86_l_147b;
	case 5249ULL: goto x86_l_1481;
	case 5253ULL: goto x86_l_1485;
	case 5259ULL: goto x86_l_148b;
	case 5265ULL: goto x86_l_1491;
	case 5270ULL: goto x86_l_1496;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5281ULL: goto x86_l_14a1;
	case 5287ULL: goto x86_l_14a7;
	case 5291ULL: goto x86_l_14ab;
	case 5297ULL: goto x86_l_14b1;
	case 5303ULL: goto x86_l_14b7;
	case 5308ULL: goto x86_l_14bc;
	case 5312ULL: goto x86_l_14c0;
	case 5315ULL: goto x86_l_14c3;
	case 5319ULL: goto x86_l_14c7;
	case 5325ULL: goto x86_l_14cd;
	case 5329ULL: goto x86_l_14d1;
	case 5335ULL: goto x86_l_14d7;
	case 5341ULL: goto x86_l_14dd;
	case 5346ULL: goto x86_l_14e2;
	case 5350ULL: goto x86_l_14e6;
	case 5353ULL: goto x86_l_14e9;
	case 5357ULL: goto x86_l_14ed;
	case 5363ULL: goto x86_l_14f3;
	case 5367ULL: goto x86_l_14f7;
	case 5373ULL: goto x86_l_14fd;
	case 5379ULL: goto x86_l_1503;
	case 5384ULL: goto x86_l_1508;
	case 5388ULL: goto x86_l_150c;
	case 5391ULL: goto x86_l_150f;
	case 5395ULL: goto x86_l_1513;
	case 5401ULL: goto x86_l_1519;
	case 5405ULL: goto x86_l_151d;
	case 5411ULL: goto x86_l_1523;
	case 5417ULL: goto x86_l_1529;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e16:
	/* 0xe16: je     3811 <generic_fentry_filter_arg+0x3811> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14353ULL;
	}
x86_l_e1c:
	/* 0xe1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e21:
	/* 0xe21: mov    rdi,QWORD PTR [rip+0x5d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_e28:
	/* 0xe28: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e2d:
	/* 0xe2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2f:
	/* 0xe2f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e32:
	/* 0xe32: je     380e <generic_fentry_filter_arg+0x380e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14350ULL;
	}
x86_l_e38:
	/* 0xe38: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e3c:
	/* 0xe3c: cmp    esi,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 94ULL);
x86_l_e3f:
	/* 0xe3f: mov    ecx,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 94ULL);
x86_l_e44:
	/* 0xe44: cmovb  ecx,esi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_e47:
	/* 0xe47: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_e4a:
	/* 0xe4a: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e4c:
	/* 0xe4c: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_e4f:
	/* 0xe4f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e55:
	/* 0xe55: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e5a:
	/* 0xe5a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_e5e:
	/* 0xe5e: mov    BYTE PTR [rax+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e61:
	/* 0xe61: cmp    rsi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1ULL);
x86_l_e65:
	/* 0xe65: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_e6b:
	/* 0xe6b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6f:
	/* 0xe6f: lea    ecx,[rsi+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_e75:
	/* 0xe75: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e7b:
	/* 0xe7b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e80:
	/* 0xe80: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_e84:
	/* 0xe84: mov    BYTE PTR [rax+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_e87:
	/* 0xe87: cmp    rsi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 2ULL);
x86_l_e8b:
	/* 0xe8b: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_e91:
	/* 0xe91: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e95:
	/* 0xe95: lea    ecx,[rsi+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_e9b:
	/* 0xe9b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ea1:
	/* 0xea1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ea6:
	/* 0xea6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_eaa:
	/* 0xeaa: mov    BYTE PTR [rax+0x6],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_ead:
	/* 0xead: cmp    rsi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 3ULL);
x86_l_eb1:
	/* 0xeb1: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_eb7:
	/* 0xeb7: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ebb:
	/* 0xebb: lea    ecx,[rsi+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_ec1:
	/* 0xec1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ec7:
	/* 0xec7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ecc:
	/* 0xecc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ed0:
	/* 0xed0: mov    BYTE PTR [rax+0x7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_ed3:
	/* 0xed3: cmp    rsi,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4ULL);
x86_l_ed7:
	/* 0xed7: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_edd:
	/* 0xedd: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee1:
	/* 0xee1: lea    ecx,[rsi+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_ee7:
	/* 0xee7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_eed:
	/* 0xeed: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ef2:
	/* 0xef2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ef6:
	/* 0xef6: mov    BYTE PTR [rax+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ef9:
	/* 0xef9: cmp    rsi,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 5ULL);
x86_l_efd:
	/* 0xefd: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_f03:
	/* 0xf03: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f07:
	/* 0xf07: lea    ecx,[rsi+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_f0d:
	/* 0xf0d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f13:
	/* 0xf13: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f18:
	/* 0xf18: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_f1c:
	/* 0xf1c: mov    BYTE PTR [rax+0x9],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_f1f:
	/* 0xf1f: cmp    rsi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 6ULL);
x86_l_f23:
	/* 0xf23: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_f29:
	/* 0xf29: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f2d:
	/* 0xf2d: lea    ecx,[rsi+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_f33:
	/* 0xf33: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f39:
	/* 0xf39: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f3e:
	/* 0xf3e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_f42:
	/* 0xf42: mov    BYTE PTR [rax+0xa],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_f45:
	/* 0xf45: cmp    rsi,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 7ULL);
x86_l_f49:
	/* 0xf49: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_f4f:
	/* 0xf4f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f53:
	/* 0xf53: lea    ecx,[rsi+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_f59:
	/* 0xf59: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f5f:
	/* 0xf5f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f64:
	/* 0xf64: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_f68:
	/* 0xf68: mov    BYTE PTR [rax+0xb],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_f6b:
	/* 0xf6b: cmp    rsi,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 8ULL);
x86_l_f6f:
	/* 0xf6f: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_f75:
	/* 0xf75: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f79:
	/* 0xf79: lea    ecx,[rsi+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_f7f:
	/* 0xf7f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f85:
	/* 0xf85: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f8a:
	/* 0xf8a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_f8e:
	/* 0xf8e: mov    BYTE PTR [rax+0xc],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f91:
	/* 0xf91: cmp    rsi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 9ULL);
x86_l_f95:
	/* 0xf95: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_f9b:
	/* 0xf9b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f9f:
	/* 0xf9f: lea    ecx,[rsi+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_fa5:
	/* 0xfa5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fab:
	/* 0xfab: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fb0:
	/* 0xfb0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_fb4:
	/* 0xfb4: mov    BYTE PTR [rax+0xd],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_fb7:
	/* 0xfb7: cmp    rsi,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 10ULL);
x86_l_fbb:
	/* 0xfbb: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_fc1:
	/* 0xfc1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc5:
	/* 0xfc5: lea    ecx,[rsi+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_fcb:
	/* 0xfcb: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fd1:
	/* 0xfd1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fd6:
	/* 0xfd6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_fda:
	/* 0xfda: mov    BYTE PTR [rax+0xe],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_fdd:
	/* 0xfdd: cmp    rsi,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 11ULL);
x86_l_fe1:
	/* 0xfe1: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_fe7:
	/* 0xfe7: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_feb:
	/* 0xfeb: lea    ecx,[rsi+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_ff1:
	/* 0xff1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ff7:
	/* 0xff7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ffc:
	/* 0xffc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1000:
	/* 0x1000: mov    BYTE PTR [rax+0xf],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1003:
	/* 0x1003: cmp    rsi,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 12ULL);
x86_l_1007:
	/* 0x1007: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_100d:
	/* 0x100d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1011:
	/* 0x1011: lea    ecx,[rsi+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_1017:
	/* 0x1017: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_101d:
	/* 0x101d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1022:
	/* 0x1022: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1026:
	/* 0x1026: mov    BYTE PTR [rax+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1029:
	/* 0x1029: cmp    rsi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 13ULL);
x86_l_102d:
	/* 0x102d: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1033:
	/* 0x1033: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1037:
	/* 0x1037: lea    ecx,[rsi+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_103d:
	/* 0x103d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1043:
	/* 0x1043: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1048:
	/* 0x1048: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_104c:
	/* 0x104c: mov    BYTE PTR [rax+0x11],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_104f:
	/* 0x104f: cmp    rsi,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 14ULL);
x86_l_1053:
	/* 0x1053: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1059:
	/* 0x1059: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_105d:
	/* 0x105d: lea    ecx,[rsi+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_1063:
	/* 0x1063: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1069:
	/* 0x1069: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_106e:
	/* 0x106e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1072:
	/* 0x1072: mov    BYTE PTR [rax+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1075:
	/* 0x1075: cmp    rsi,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 15ULL);
x86_l_1079:
	/* 0x1079: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_107f:
	/* 0x107f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1083:
	/* 0x1083: lea    ecx,[rsi+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_1089:
	/* 0x1089: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_108f:
	/* 0x108f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1094:
	/* 0x1094: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1098:
	/* 0x1098: mov    BYTE PTR [rax+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_109b:
	/* 0x109b: cmp    rsi,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 16ULL);
x86_l_109f:
	/* 0x109f: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_10a5:
	/* 0x10a5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a9:
	/* 0x10a9: lea    ecx,[rsi+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_10af:
	/* 0x10af: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10b5:
	/* 0x10b5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10ba:
	/* 0x10ba: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_10be:
	/* 0x10be: mov    BYTE PTR [rax+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_10c1:
	/* 0x10c1: cmp    rsi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 17ULL);
x86_l_10c5:
	/* 0x10c5: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_10cb:
	/* 0x10cb: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10cf:
	/* 0x10cf: lea    ecx,[rsi+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_10d5:
	/* 0x10d5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10db:
	/* 0x10db: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10e0:
	/* 0x10e0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_10e4:
	/* 0x10e4: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_10e7:
	/* 0x10e7: cmp    rsi,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18ULL);
x86_l_10eb:
	/* 0x10eb: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_10f1:
	/* 0x10f1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f5:
	/* 0x10f5: lea    ecx,[rsi+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_10fb:
	/* 0x10fb: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1101:
	/* 0x1101: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1106:
	/* 0x1106: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_110a:
	/* 0x110a: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_110d:
	/* 0x110d: cmp    rsi,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 19ULL);
x86_l_1111:
	/* 0x1111: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1117:
	/* 0x1117: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_111b:
	/* 0x111b: lea    ecx,[rsi+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_1121:
	/* 0x1121: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1127:
	/* 0x1127: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_112c:
	/* 0x112c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1130:
	/* 0x1130: mov    BYTE PTR [rax+0x17],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_1133:
	/* 0x1133: cmp    rsi,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 20ULL);
x86_l_1137:
	/* 0x1137: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_113d:
	/* 0x113d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1141:
	/* 0x1141: lea    ecx,[rsi+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_1147:
	/* 0x1147: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_114d:
	/* 0x114d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1152:
	/* 0x1152: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1156:
	/* 0x1156: mov    BYTE PTR [rax+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1159:
	/* 0x1159: cmp    rsi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 21ULL);
x86_l_115d:
	/* 0x115d: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1163:
	/* 0x1163: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1167:
	/* 0x1167: lea    ecx,[rsi+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_116d:
	/* 0x116d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1173:
	/* 0x1173: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1178:
	/* 0x1178: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_117c:
	/* 0x117c: mov    BYTE PTR [rax+0x19],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_117f:
	/* 0x117f: cmp    rsi,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 22ULL);
x86_l_1183:
	/* 0x1183: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1189:
	/* 0x1189: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_118d:
	/* 0x118d: lea    ecx,[rsi+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_1193:
	/* 0x1193: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1199:
	/* 0x1199: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_119e:
	/* 0x119e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_11a2:
	/* 0x11a2: mov    BYTE PTR [rax+0x1a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_11a5:
	/* 0x11a5: cmp    rsi,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 23ULL);
x86_l_11a9:
	/* 0x11a9: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_11af:
	/* 0x11af: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11b3:
	/* 0x11b3: lea    ecx,[rsi+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_11b9:
	/* 0x11b9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11bf:
	/* 0x11bf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11c4:
	/* 0x11c4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_11c8:
	/* 0x11c8: mov    BYTE PTR [rax+0x1b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_11cb:
	/* 0x11cb: cmp    rsi,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 24ULL);
x86_l_11cf:
	/* 0x11cf: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_11d5:
	/* 0x11d5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11d9:
	/* 0x11d9: lea    ecx,[rsi+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_11df:
	/* 0x11df: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11e5:
	/* 0x11e5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11ea:
	/* 0x11ea: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_11ee:
	/* 0x11ee: mov    BYTE PTR [rax+0x1c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_11f1:
	/* 0x11f1: cmp    rsi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 25ULL);
x86_l_11f5:
	/* 0x11f5: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_11fb:
	/* 0x11fb: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ff:
	/* 0x11ff: lea    ecx,[rsi+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_1205:
	/* 0x1205: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_120b:
	/* 0x120b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1210:
	/* 0x1210: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1214:
	/* 0x1214: mov    BYTE PTR [rax+0x1d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_1217:
	/* 0x1217: cmp    rsi,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 26ULL);
x86_l_121b:
	/* 0x121b: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1221:
	/* 0x1221: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1225:
	/* 0x1225: lea    ecx,[rsi+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_122b:
	/* 0x122b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1231:
	/* 0x1231: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1236:
	/* 0x1236: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_123a:
	/* 0x123a: mov    BYTE PTR [rax+0x1e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_123d:
	/* 0x123d: cmp    rsi,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 27ULL);
x86_l_1241:
	/* 0x1241: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1247:
	/* 0x1247: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_124b:
	/* 0x124b: lea    ecx,[rsi+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_1251:
	/* 0x1251: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1257:
	/* 0x1257: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_125c:
	/* 0x125c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1260:
	/* 0x1260: mov    BYTE PTR [rax+0x1f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_1263:
	/* 0x1263: cmp    rsi,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 28ULL);
x86_l_1267:
	/* 0x1267: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_126d:
	/* 0x126d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1271:
	/* 0x1271: lea    ecx,[rsi+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_1277:
	/* 0x1277: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_127d:
	/* 0x127d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1282:
	/* 0x1282: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1286:
	/* 0x1286: mov    BYTE PTR [rax+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1289:
	/* 0x1289: cmp    rsi,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 29ULL);
x86_l_128d:
	/* 0x128d: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1293:
	/* 0x1293: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1297:
	/* 0x1297: lea    ecx,[rsi+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_129d:
	/* 0x129d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12a3:
	/* 0x12a3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12a8:
	/* 0x12a8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_12ac:
	/* 0x12ac: mov    BYTE PTR [rax+0x21],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_12af:
	/* 0x12af: cmp    rsi,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 30ULL);
x86_l_12b3:
	/* 0x12b3: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_12b9:
	/* 0x12b9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12bd:
	/* 0x12bd: lea    ecx,[rsi+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_12c3:
	/* 0x12c3: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12c9:
	/* 0x12c9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12ce:
	/* 0x12ce: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_12d2:
	/* 0x12d2: mov    BYTE PTR [rax+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_12d5:
	/* 0x12d5: cmp    rsi,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 31ULL);
x86_l_12d9:
	/* 0x12d9: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_12df:
	/* 0x12df: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12e3:
	/* 0x12e3: lea    ecx,[rsi+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_12e9:
	/* 0x12e9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12ef:
	/* 0x12ef: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12f4:
	/* 0x12f4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_12f8:
	/* 0x12f8: mov    BYTE PTR [rax+0x23],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_12fb:
	/* 0x12fb: cmp    rsi,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 32ULL);
x86_l_12ff:
	/* 0x12ff: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1305:
	/* 0x1305: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1309:
	/* 0x1309: lea    ecx,[rsi+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_130f:
	/* 0x130f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1315:
	/* 0x1315: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_131a:
	/* 0x131a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_131e:
	/* 0x131e: mov    BYTE PTR [rax+0x24],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1321:
	/* 0x1321: cmp    rsi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 33ULL);
x86_l_1325:
	/* 0x1325: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_132b:
	/* 0x132b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_132f:
	/* 0x132f: lea    ecx,[rsi+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_1335:
	/* 0x1335: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_133b:
	/* 0x133b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1340:
	/* 0x1340: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1344:
	/* 0x1344: mov    BYTE PTR [rax+0x25],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_1347:
	/* 0x1347: cmp    rsi,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 34ULL);
x86_l_134b:
	/* 0x134b: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1351:
	/* 0x1351: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1355:
	/* 0x1355: lea    ecx,[rsi+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_135b:
	/* 0x135b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1361:
	/* 0x1361: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1366:
	/* 0x1366: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_136a:
	/* 0x136a: mov    BYTE PTR [rax+0x26],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_136d:
	/* 0x136d: cmp    rsi,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 35ULL);
x86_l_1371:
	/* 0x1371: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1377:
	/* 0x1377: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_137b:
	/* 0x137b: lea    ecx,[rsi+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_1381:
	/* 0x1381: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1387:
	/* 0x1387: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_138c:
	/* 0x138c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1390:
	/* 0x1390: mov    BYTE PTR [rax+0x27],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_1393:
	/* 0x1393: cmp    rsi,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 36ULL);
x86_l_1397:
	/* 0x1397: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_139d:
	/* 0x139d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13a1:
	/* 0x13a1: lea    ecx,[rsi+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_13a7:
	/* 0x13a7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13ad:
	/* 0x13ad: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13b2:
	/* 0x13b2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_13b6:
	/* 0x13b6: mov    BYTE PTR [rax+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13b9:
	/* 0x13b9: cmp    rsi,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 37ULL);
x86_l_13bd:
	/* 0x13bd: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_13c3:
	/* 0x13c3: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c7:
	/* 0x13c7: lea    ecx,[rsi+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_13cd:
	/* 0x13cd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13d3:
	/* 0x13d3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13d8:
	/* 0x13d8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_13dc:
	/* 0x13dc: mov    BYTE PTR [rax+0x29],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_13df:
	/* 0x13df: cmp    rsi,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 38ULL);
x86_l_13e3:
	/* 0x13e3: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_13e9:
	/* 0x13e9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ed:
	/* 0x13ed: lea    ecx,[rsi+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_13f3:
	/* 0x13f3: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13f9:
	/* 0x13f9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13fe:
	/* 0x13fe: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1402:
	/* 0x1402: mov    BYTE PTR [rax+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1405:
	/* 0x1405: cmp    rsi,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 39ULL);
x86_l_1409:
	/* 0x1409: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_140f:
	/* 0x140f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1413:
	/* 0x1413: lea    ecx,[rsi+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_1419:
	/* 0x1419: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_141f:
	/* 0x141f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1424:
	/* 0x1424: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1428:
	/* 0x1428: mov    BYTE PTR [rax+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_142b:
	/* 0x142b: cmp    rsi,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 40ULL);
x86_l_142f:
	/* 0x142f: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1435:
	/* 0x1435: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1439:
	/* 0x1439: lea    ecx,[rsi+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_143f:
	/* 0x143f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1445:
	/* 0x1445: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_144a:
	/* 0x144a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_144e:
	/* 0x144e: mov    BYTE PTR [rax+0x2c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1451:
	/* 0x1451: cmp    rsi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 41ULL);
x86_l_1455:
	/* 0x1455: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_145b:
	/* 0x145b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_145f:
	/* 0x145f: lea    ecx,[rsi+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_1465:
	/* 0x1465: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_146b:
	/* 0x146b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1470:
	/* 0x1470: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1474:
	/* 0x1474: mov    BYTE PTR [rax+0x2d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_1477:
	/* 0x1477: cmp    rsi,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 42ULL);
x86_l_147b:
	/* 0x147b: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1481:
	/* 0x1481: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1485:
	/* 0x1485: lea    ecx,[rsi+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_148b:
	/* 0x148b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1491:
	/* 0x1491: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1496:
	/* 0x1496: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_149a:
	/* 0x149a: mov    BYTE PTR [rax+0x2e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_149d:
	/* 0x149d: cmp    rsi,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 43ULL);
x86_l_14a1:
	/* 0x14a1: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_14a7:
	/* 0x14a7: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14ab:
	/* 0x14ab: lea    ecx,[rsi+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_14b1:
	/* 0x14b1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14b7:
	/* 0x14b7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14bc:
	/* 0x14bc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_14c0:
	/* 0x14c0: mov    BYTE PTR [rax+0x2f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_14c3:
	/* 0x14c3: cmp    rsi,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 44ULL);
x86_l_14c7:
	/* 0x14c7: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_14cd:
	/* 0x14cd: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14d1:
	/* 0x14d1: lea    ecx,[rsi+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_14d7:
	/* 0x14d7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14dd:
	/* 0x14dd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14e2:
	/* 0x14e2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_14e6:
	/* 0x14e6: mov    BYTE PTR [rax+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14e9:
	/* 0x14e9: cmp    rsi,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 45ULL);
x86_l_14ed:
	/* 0x14ed: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_14f3:
	/* 0x14f3: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14f7:
	/* 0x14f7: lea    ecx,[rsi+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_14fd:
	/* 0x14fd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1503:
	/* 0x1503: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1508:
	/* 0x1508: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_150c:
	/* 0x150c: mov    BYTE PTR [rax+0x31],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_150f:
	/* 0x150f: cmp    rsi,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 46ULL);
x86_l_1513:
	/* 0x1513: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7203ULL;
	}
x86_l_1519:
	/* 0x1519: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_151d:
	/* 0x151d: lea    ecx,[rsi+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_1523:
	/* 0x1523: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1529:
	/* 0x1529: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 5422ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5422ULL: goto x86_l_152e;
	case 5426ULL: goto x86_l_1532;
	case 5429ULL: goto x86_l_1535;
	case 5433ULL: goto x86_l_1539;
	case 5439ULL: goto x86_l_153f;
	case 5443ULL: goto x86_l_1543;
	case 5449ULL: goto x86_l_1549;
	case 5455ULL: goto x86_l_154f;
	case 5460ULL: goto x86_l_1554;
	case 5464ULL: goto x86_l_1558;
	case 5467ULL: goto x86_l_155b;
	case 5471ULL: goto x86_l_155f;
	case 5477ULL: goto x86_l_1565;
	case 5481ULL: goto x86_l_1569;
	case 5487ULL: goto x86_l_156f;
	case 5493ULL: goto x86_l_1575;
	case 5498ULL: goto x86_l_157a;
	case 5502ULL: goto x86_l_157e;
	case 5505ULL: goto x86_l_1581;
	case 5509ULL: goto x86_l_1585;
	case 5515ULL: goto x86_l_158b;
	case 5519ULL: goto x86_l_158f;
	case 5525ULL: goto x86_l_1595;
	case 5531ULL: goto x86_l_159b;
	case 5536ULL: goto x86_l_15a0;
	case 5540ULL: goto x86_l_15a4;
	case 5543ULL: goto x86_l_15a7;
	case 5547ULL: goto x86_l_15ab;
	case 5553ULL: goto x86_l_15b1;
	case 5557ULL: goto x86_l_15b5;
	case 5563ULL: goto x86_l_15bb;
	case 5569ULL: goto x86_l_15c1;
	case 5574ULL: goto x86_l_15c6;
	case 5578ULL: goto x86_l_15ca;
	case 5581ULL: goto x86_l_15cd;
	case 5585ULL: goto x86_l_15d1;
	case 5591ULL: goto x86_l_15d7;
	case 5595ULL: goto x86_l_15db;
	case 5601ULL: goto x86_l_15e1;
	case 5607ULL: goto x86_l_15e7;
	case 5612ULL: goto x86_l_15ec;
	case 5616ULL: goto x86_l_15f0;
	case 5619ULL: goto x86_l_15f3;
	case 5623ULL: goto x86_l_15f7;
	case 5629ULL: goto x86_l_15fd;
	case 5633ULL: goto x86_l_1601;
	case 5639ULL: goto x86_l_1607;
	case 5645ULL: goto x86_l_160d;
	case 5650ULL: goto x86_l_1612;
	case 5654ULL: goto x86_l_1616;
	case 5657ULL: goto x86_l_1619;
	case 5661ULL: goto x86_l_161d;
	case 5667ULL: goto x86_l_1623;
	case 5671ULL: goto x86_l_1627;
	case 5677ULL: goto x86_l_162d;
	case 5683ULL: goto x86_l_1633;
	case 5688ULL: goto x86_l_1638;
	case 5692ULL: goto x86_l_163c;
	case 5695ULL: goto x86_l_163f;
	case 5699ULL: goto x86_l_1643;
	case 5705ULL: goto x86_l_1649;
	case 5709ULL: goto x86_l_164d;
	case 5715ULL: goto x86_l_1653;
	case 5721ULL: goto x86_l_1659;
	case 5726ULL: goto x86_l_165e;
	case 5730ULL: goto x86_l_1662;
	case 5733ULL: goto x86_l_1665;
	case 5737ULL: goto x86_l_1669;
	case 5743ULL: goto x86_l_166f;
	case 5747ULL: goto x86_l_1673;
	case 5753ULL: goto x86_l_1679;
	case 5759ULL: goto x86_l_167f;
	case 5764ULL: goto x86_l_1684;
	case 5768ULL: goto x86_l_1688;
	case 5771ULL: goto x86_l_168b;
	case 5775ULL: goto x86_l_168f;
	case 5781ULL: goto x86_l_1695;
	case 5785ULL: goto x86_l_1699;
	case 5791ULL: goto x86_l_169f;
	case 5797ULL: goto x86_l_16a5;
	case 5802ULL: goto x86_l_16aa;
	case 5806ULL: goto x86_l_16ae;
	case 5809ULL: goto x86_l_16b1;
	case 5813ULL: goto x86_l_16b5;
	case 5819ULL: goto x86_l_16bb;
	case 5823ULL: goto x86_l_16bf;
	case 5829ULL: goto x86_l_16c5;
	case 5835ULL: goto x86_l_16cb;
	case 5840ULL: goto x86_l_16d0;
	case 5844ULL: goto x86_l_16d4;
	case 5847ULL: goto x86_l_16d7;
	case 5851ULL: goto x86_l_16db;
	case 5857ULL: goto x86_l_16e1;
	case 5861ULL: goto x86_l_16e5;
	case 5867ULL: goto x86_l_16eb;
	case 5873ULL: goto x86_l_16f1;
	case 5878ULL: goto x86_l_16f6;
	case 5882ULL: goto x86_l_16fa;
	case 5885ULL: goto x86_l_16fd;
	case 5889ULL: goto x86_l_1701;
	case 5895ULL: goto x86_l_1707;
	case 5899ULL: goto x86_l_170b;
	case 5905ULL: goto x86_l_1711;
	case 5911ULL: goto x86_l_1717;
	case 5916ULL: goto x86_l_171c;
	case 5920ULL: goto x86_l_1720;
	case 5923ULL: goto x86_l_1723;
	case 5927ULL: goto x86_l_1727;
	case 5933ULL: goto x86_l_172d;
	case 5937ULL: goto x86_l_1731;
	case 5943ULL: goto x86_l_1737;
	case 5949ULL: goto x86_l_173d;
	case 5954ULL: goto x86_l_1742;
	case 5958ULL: goto x86_l_1746;
	case 5961ULL: goto x86_l_1749;
	case 5965ULL: goto x86_l_174d;
	case 5971ULL: goto x86_l_1753;
	case 5975ULL: goto x86_l_1757;
	case 5981ULL: goto x86_l_175d;
	case 5987ULL: goto x86_l_1763;
	case 5992ULL: goto x86_l_1768;
	case 5996ULL: goto x86_l_176c;
	case 5999ULL: goto x86_l_176f;
	case 6003ULL: goto x86_l_1773;
	case 6009ULL: goto x86_l_1779;
	case 6013ULL: goto x86_l_177d;
	case 6019ULL: goto x86_l_1783;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6034ULL: goto x86_l_1792;
	case 6037ULL: goto x86_l_1795;
	case 6041ULL: goto x86_l_1799;
	case 6047ULL: goto x86_l_179f;
	case 6051ULL: goto x86_l_17a3;
	case 6057ULL: goto x86_l_17a9;
	case 6063ULL: goto x86_l_17af;
	case 6068ULL: goto x86_l_17b4;
	case 6072ULL: goto x86_l_17b8;
	case 6075ULL: goto x86_l_17bb;
	case 6079ULL: goto x86_l_17bf;
	case 6085ULL: goto x86_l_17c5;
	case 6089ULL: goto x86_l_17c9;
	case 6095ULL: goto x86_l_17cf;
	case 6101ULL: goto x86_l_17d5;
	case 6106ULL: goto x86_l_17da;
	case 6110ULL: goto x86_l_17de;
	case 6113ULL: goto x86_l_17e1;
	case 6117ULL: goto x86_l_17e5;
	case 6123ULL: goto x86_l_17eb;
	case 6127ULL: goto x86_l_17ef;
	case 6133ULL: goto x86_l_17f5;
	case 6139ULL: goto x86_l_17fb;
	case 6144ULL: goto x86_l_1800;
	case 6148ULL: goto x86_l_1804;
	case 6151ULL: goto x86_l_1807;
	case 6155ULL: goto x86_l_180b;
	case 6161ULL: goto x86_l_1811;
	case 6165ULL: goto x86_l_1815;
	case 6171ULL: goto x86_l_181b;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6186ULL: goto x86_l_182a;
	case 6189ULL: goto x86_l_182d;
	case 6193ULL: goto x86_l_1831;
	case 6199ULL: goto x86_l_1837;
	case 6203ULL: goto x86_l_183b;
	case 6209ULL: goto x86_l_1841;
	case 6215ULL: goto x86_l_1847;
	case 6220ULL: goto x86_l_184c;
	case 6224ULL: goto x86_l_1850;
	case 6227ULL: goto x86_l_1853;
	case 6231ULL: goto x86_l_1857;
	case 6237ULL: goto x86_l_185d;
	case 6241ULL: goto x86_l_1861;
	case 6247ULL: goto x86_l_1867;
	case 6253ULL: goto x86_l_186d;
	case 6258ULL: goto x86_l_1872;
	case 6262ULL: goto x86_l_1876;
	case 6265ULL: goto x86_l_1879;
	case 6269ULL: goto x86_l_187d;
	case 6275ULL: goto x86_l_1883;
	case 6279ULL: goto x86_l_1887;
	case 6285ULL: goto x86_l_188d;
	case 6291ULL: goto x86_l_1893;
	case 6296ULL: goto x86_l_1898;
	case 6300ULL: goto x86_l_189c;
	case 6303ULL: goto x86_l_189f;
	case 6307ULL: goto x86_l_18a3;
	case 6313ULL: goto x86_l_18a9;
	case 6317ULL: goto x86_l_18ad;
	case 6323ULL: goto x86_l_18b3;
	case 6329ULL: goto x86_l_18b9;
	case 6334ULL: goto x86_l_18be;
	case 6338ULL: goto x86_l_18c2;
	case 6341ULL: goto x86_l_18c5;
	case 6345ULL: goto x86_l_18c9;
	case 6351ULL: goto x86_l_18cf;
	case 6355ULL: goto x86_l_18d3;
	case 6361ULL: goto x86_l_18d9;
	case 6367ULL: goto x86_l_18df;
	case 6372ULL: goto x86_l_18e4;
	case 6376ULL: goto x86_l_18e8;
	case 6379ULL: goto x86_l_18eb;
	case 6383ULL: goto x86_l_18ef;
	case 6389ULL: goto x86_l_18f5;
	case 6393ULL: goto x86_l_18f9;
	case 6399ULL: goto x86_l_18ff;
	case 6405ULL: goto x86_l_1905;
	case 6410ULL: goto x86_l_190a;
	case 6414ULL: goto x86_l_190e;
	case 6417ULL: goto x86_l_1911;
	case 6421ULL: goto x86_l_1915;
	case 6427ULL: goto x86_l_191b;
	case 6431ULL: goto x86_l_191f;
	case 6437ULL: goto x86_l_1925;
	case 6443ULL: goto x86_l_192b;
	case 6448ULL: goto x86_l_1930;
	case 6452ULL: goto x86_l_1934;
	case 6455ULL: goto x86_l_1937;
	case 6459ULL: goto x86_l_193b;
	case 6465ULL: goto x86_l_1941;
	case 6469ULL: goto x86_l_1945;
	case 6475ULL: goto x86_l_194b;
	case 6481ULL: goto x86_l_1951;
	case 6486ULL: goto x86_l_1956;
	case 6490ULL: goto x86_l_195a;
	case 6493ULL: goto x86_l_195d;
	case 6497ULL: goto x86_l_1961;
	case 6503ULL: goto x86_l_1967;
	case 6507ULL: goto x86_l_196b;
	case 6513ULL: goto x86_l_1971;
	case 6519ULL: goto x86_l_1977;
	case 6524ULL: goto x86_l_197c;
	case 6528ULL: goto x86_l_1980;
	case 6531ULL: goto x86_l_1983;
	case 6535ULL: goto x86_l_1987;
	case 6541ULL: goto x86_l_198d;
	case 6545ULL: goto x86_l_1991;
	case 6551ULL: goto x86_l_1997;
	case 6557ULL: goto x86_l_199d;
	case 6562ULL: goto x86_l_19a2;
	case 6566ULL: goto x86_l_19a6;
	case 6569ULL: goto x86_l_19a9;
	case 6573ULL: goto x86_l_19ad;
	case 6579ULL: goto x86_l_19b3;
	case 6583ULL: goto x86_l_19b7;
	case 6589ULL: goto x86_l_19bd;
	case 6595ULL: goto x86_l_19c3;
	case 6600ULL: goto x86_l_19c8;
	case 6604ULL: goto x86_l_19cc;
	case 6607ULL: goto x86_l_19cf;
	case 6611ULL: goto x86_l_19d3;
	case 6617ULL: goto x86_l_19d9;
	case 6621ULL: goto x86_l_19dd;
	case 6627ULL: goto x86_l_19e3;
	case 6633ULL: goto x86_l_19e9;
	case 6638ULL: goto x86_l_19ee;
	case 6642ULL: goto x86_l_19f2;
	case 6645ULL: goto x86_l_19f5;
	case 6649ULL: goto x86_l_19f9;
	case 6655ULL: goto x86_l_19ff;
	case 6659ULL: goto x86_l_1a03;
	case 6665ULL: goto x86_l_1a09;
	case 6671ULL: goto x86_l_1a0f;
	case 6676ULL: goto x86_l_1a14;
	case 6680ULL: goto x86_l_1a18;
	case 6683ULL: goto x86_l_1a1b;
	case 6687ULL: goto x86_l_1a1f;
	case 6693ULL: goto x86_l_1a25;
	case 6697ULL: goto x86_l_1a29;
	case 6703ULL: goto x86_l_1a2f;
	case 6709ULL: goto x86_l_1a35;
	case 6714ULL: goto x86_l_1a3a;
	case 6718ULL: goto x86_l_1a3e;
	case 6721ULL: goto x86_l_1a41;
	case 6725ULL: goto x86_l_1a45;
	case 6731ULL: goto x86_l_1a4b;
	case 6735ULL: goto x86_l_1a4f;
	case 6741ULL: goto x86_l_1a55;
	case 6747ULL: goto x86_l_1a5b;
	case 6752ULL: goto x86_l_1a60;
	case 6756ULL: goto x86_l_1a64;
	case 6759ULL: goto x86_l_1a67;
	case 6763ULL: goto x86_l_1a6b;
	case 6769ULL: goto x86_l_1a71;
	case 6773ULL: goto x86_l_1a75;
	case 6779ULL: goto x86_l_1a7b;
	case 6785ULL: goto x86_l_1a81;
	case 6790ULL: goto x86_l_1a86;
	case 6794ULL: goto x86_l_1a8a;
	case 6797ULL: goto x86_l_1a8d;
	case 6801ULL: goto x86_l_1a91;
	case 6807ULL: goto x86_l_1a97;
	case 6811ULL: goto x86_l_1a9b;
	case 6817ULL: goto x86_l_1aa1;
	case 6823ULL: goto x86_l_1aa7;
	case 6828ULL: goto x86_l_1aac;
	case 6832ULL: goto x86_l_1ab0;
	case 6835ULL: goto x86_l_1ab3;
	case 6839ULL: goto x86_l_1ab7;
	case 6845ULL: goto x86_l_1abd;
	case 6849ULL: goto x86_l_1ac1;
	case 6855ULL: goto x86_l_1ac7;
	case 6861ULL: goto x86_l_1acd;
	case 6866ULL: goto x86_l_1ad2;
	case 6870ULL: goto x86_l_1ad6;
	case 6873ULL: goto x86_l_1ad9;
	case 6877ULL: goto x86_l_1add;
	case 6883ULL: goto x86_l_1ae3;
	case 6887ULL: goto x86_l_1ae7;
	case 6893ULL: goto x86_l_1aed;
	case 6899ULL: goto x86_l_1af3;
	case 6904ULL: goto x86_l_1af8;
	case 6908ULL: goto x86_l_1afc;
	case 6911ULL: goto x86_l_1aff;
	case 6915ULL: goto x86_l_1b03;
	case 6921ULL: goto x86_l_1b09;
	case 6925ULL: goto x86_l_1b0d;
	case 6931ULL: goto x86_l_1b13;
	case 6937ULL: goto x86_l_1b19;
	case 6942ULL: goto x86_l_1b1e;
	case 6946ULL: goto x86_l_1b22;
	case 6949ULL: goto x86_l_1b25;
	case 6953ULL: goto x86_l_1b29;
	case 6959ULL: goto x86_l_1b2f;
	case 6963ULL: goto x86_l_1b33;
	case 6969ULL: goto x86_l_1b39;
	case 6975ULL: goto x86_l_1b3f;
	case 6980ULL: goto x86_l_1b44;
	case 6984ULL: goto x86_l_1b48;
	case 6987ULL: goto x86_l_1b4b;
	case 6991ULL: goto x86_l_1b4f;
	case 6997ULL: goto x86_l_1b55;
	case 7001ULL: goto x86_l_1b59;
	case 7007ULL: goto x86_l_1b5f;
	case 7013ULL: goto x86_l_1b65;
	case 7018ULL: goto x86_l_1b6a;
	case 7022ULL: goto x86_l_1b6e;
	case 7025ULL: goto x86_l_1b71;
	case 7029ULL: goto x86_l_1b75;
	case 7035ULL: goto x86_l_1b7b;
	case 7039ULL: goto x86_l_1b7f;
	case 7045ULL: goto x86_l_1b85;
	case 7051ULL: goto x86_l_1b8b;
	case 7056ULL: goto x86_l_1b90;
	case 7060ULL: goto x86_l_1b94;
	case 7063ULL: goto x86_l_1b97;
	case 7067ULL: goto x86_l_1b9b;
	case 7073ULL: goto x86_l_1ba1;
	case 7077ULL: goto x86_l_1ba5;
	case 7083ULL: goto x86_l_1bab;
	case 7089ULL: goto x86_l_1bb1;
	case 7094ULL: goto x86_l_1bb6;
	case 7098ULL: goto x86_l_1bba;
	case 7101ULL: goto x86_l_1bbd;
	case 7105ULL: goto x86_l_1bc1;
	case 7107ULL: goto x86_l_1bc3;
	case 7111ULL: goto x86_l_1bc7;
	case 7117ULL: goto x86_l_1bcd;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7132ULL: goto x86_l_1bdc;
	case 7135ULL: goto x86_l_1bdf;
	case 7139ULL: goto x86_l_1be3;
	case 7141ULL: goto x86_l_1be5;
	case 7145ULL: goto x86_l_1be9;
	case 7151ULL: goto x86_l_1bef;
	case 7157ULL: goto x86_l_1bf5;
	case 7162ULL: goto x86_l_1bfa;
	case 7166ULL: goto x86_l_1bfe;
	case 7169ULL: goto x86_l_1c01;
	case 7173ULL: goto x86_l_1c05;
	case 7175ULL: goto x86_l_1c07;
	case 7179ULL: goto x86_l_1c0b;
	case 7185ULL: goto x86_l_1c11;
	case 7191ULL: goto x86_l_1c17;
	case 7196ULL: goto x86_l_1c1c;
	case 7200ULL: goto x86_l_1c20;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7211ULL: goto x86_l_1c2b;
	case 7214ULL: goto x86_l_1c2e;
	case 7219ULL: goto x86_l_1c33;
	case 7222ULL: goto x86_l_1c36;
	default: return 0xffffffffffffffffULL;
	}
x86_l_152e:
	/* 0x152e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1532:
	/* 0x1532: mov    BYTE PTR [rax+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_1535:
	/* 0x1535: cmp    rsi,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 47ULL);
x86_l_1539:
	/* 0x1539: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_153f:
	/* 0x153f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1543:
	/* 0x1543: lea    ecx,[rsi+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_1549:
	/* 0x1549: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_154f:
	/* 0x154f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1554:
	/* 0x1554: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1558:
	/* 0x1558: mov    BYTE PTR [rax+0x33],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_155b:
	/* 0x155b: cmp    rsi,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 48ULL);
x86_l_155f:
	/* 0x155f: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1565:
	/* 0x1565: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1569:
	/* 0x1569: lea    ecx,[rsi+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_156f:
	/* 0x156f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1575:
	/* 0x1575: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_157a:
	/* 0x157a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_157e:
	/* 0x157e: mov    BYTE PTR [rax+0x34],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1581:
	/* 0x1581: cmp    rsi,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 49ULL);
x86_l_1585:
	/* 0x1585: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_158b:
	/* 0x158b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_158f:
	/* 0x158f: lea    ecx,[rsi+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_1595:
	/* 0x1595: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_159b:
	/* 0x159b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15a0:
	/* 0x15a0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_15a4:
	/* 0x15a4: mov    BYTE PTR [rax+0x35],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_15a7:
	/* 0x15a7: cmp    rsi,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 50ULL);
x86_l_15ab:
	/* 0x15ab: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_15b1:
	/* 0x15b1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b5:
	/* 0x15b5: lea    ecx,[rsi+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_15bb:
	/* 0x15bb: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15c1:
	/* 0x15c1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15c6:
	/* 0x15c6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_15ca:
	/* 0x15ca: mov    BYTE PTR [rax+0x36],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_15cd:
	/* 0x15cd: cmp    rsi,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 51ULL);
x86_l_15d1:
	/* 0x15d1: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_15d7:
	/* 0x15d7: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15db:
	/* 0x15db: lea    ecx,[rsi+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_15e1:
	/* 0x15e1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15e7:
	/* 0x15e7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ec:
	/* 0x15ec: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_15f0:
	/* 0x15f0: mov    BYTE PTR [rax+0x37],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_15f3:
	/* 0x15f3: cmp    rsi,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 52ULL);
x86_l_15f7:
	/* 0x15f7: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_15fd:
	/* 0x15fd: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1601:
	/* 0x1601: lea    ecx,[rsi+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_1607:
	/* 0x1607: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_160d:
	/* 0x160d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1612:
	/* 0x1612: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1616:
	/* 0x1616: mov    BYTE PTR [rax+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1619:
	/* 0x1619: cmp    rsi,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 53ULL);
x86_l_161d:
	/* 0x161d: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1623:
	/* 0x1623: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1627:
	/* 0x1627: lea    ecx,[rsi+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_162d:
	/* 0x162d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1633:
	/* 0x1633: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1638:
	/* 0x1638: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_163c:
	/* 0x163c: mov    BYTE PTR [rax+0x39],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_163f:
	/* 0x163f: cmp    rsi,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 54ULL);
x86_l_1643:
	/* 0x1643: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1649:
	/* 0x1649: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_164d:
	/* 0x164d: lea    ecx,[rsi+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_1653:
	/* 0x1653: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1659:
	/* 0x1659: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_165e:
	/* 0x165e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1662:
	/* 0x1662: mov    BYTE PTR [rax+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1665:
	/* 0x1665: cmp    rsi,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 55ULL);
x86_l_1669:
	/* 0x1669: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_166f:
	/* 0x166f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1673:
	/* 0x1673: lea    ecx,[rsi+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_1679:
	/* 0x1679: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_167f:
	/* 0x167f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1684:
	/* 0x1684: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1688:
	/* 0x1688: mov    BYTE PTR [rax+0x3b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_168b:
	/* 0x168b: cmp    rsi,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 56ULL);
x86_l_168f:
	/* 0x168f: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1695:
	/* 0x1695: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1699:
	/* 0x1699: lea    ecx,[rsi+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_169f:
	/* 0x169f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16a5:
	/* 0x16a5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16aa:
	/* 0x16aa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_16ae:
	/* 0x16ae: mov    BYTE PTR [rax+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_16b1:
	/* 0x16b1: cmp    rsi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 57ULL);
x86_l_16b5:
	/* 0x16b5: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_16bb:
	/* 0x16bb: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16bf:
	/* 0x16bf: lea    ecx,[rsi+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_16c5:
	/* 0x16c5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16cb:
	/* 0x16cb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16d0:
	/* 0x16d0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_16d4:
	/* 0x16d4: mov    BYTE PTR [rax+0x3d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_16d7:
	/* 0x16d7: cmp    rsi,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 58ULL);
x86_l_16db:
	/* 0x16db: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_16e1:
	/* 0x16e1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e5:
	/* 0x16e5: lea    ecx,[rsi+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_16eb:
	/* 0x16eb: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16f1:
	/* 0x16f1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16f6:
	/* 0x16f6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_16fa:
	/* 0x16fa: mov    BYTE PTR [rax+0x3e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_16fd:
	/* 0x16fd: cmp    rsi,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 59ULL);
x86_l_1701:
	/* 0x1701: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1707:
	/* 0x1707: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_170b:
	/* 0x170b: lea    ecx,[rsi+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_1711:
	/* 0x1711: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1717:
	/* 0x1717: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_171c:
	/* 0x171c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1720:
	/* 0x1720: mov    BYTE PTR [rax+0x3f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_1723:
	/* 0x1723: cmp    rsi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 60ULL);
x86_l_1727:
	/* 0x1727: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_172d:
	/* 0x172d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1731:
	/* 0x1731: lea    ecx,[rsi+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_1737:
	/* 0x1737: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_173d:
	/* 0x173d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1742:
	/* 0x1742: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1746:
	/* 0x1746: mov    BYTE PTR [rax+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1749:
	/* 0x1749: cmp    rsi,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 61ULL);
x86_l_174d:
	/* 0x174d: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1753:
	/* 0x1753: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1757:
	/* 0x1757: lea    ecx,[rsi+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_175d:
	/* 0x175d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1763:
	/* 0x1763: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1768:
	/* 0x1768: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_176c:
	/* 0x176c: mov    BYTE PTR [rax+0x41],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_176f:
	/* 0x176f: cmp    rsi,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 62ULL);
x86_l_1773:
	/* 0x1773: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1779:
	/* 0x1779: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_177d:
	/* 0x177d: lea    ecx,[rsi+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_1783:
	/* 0x1783: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1789:
	/* 0x1789: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_178e:
	/* 0x178e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1792:
	/* 0x1792: mov    BYTE PTR [rax+0x42],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_1795:
	/* 0x1795: cmp    rsi,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 63ULL);
x86_l_1799:
	/* 0x1799: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_179f:
	/* 0x179f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17a3:
	/* 0x17a3: lea    ecx,[rsi+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_17a9:
	/* 0x17a9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17af:
	/* 0x17af: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17b4:
	/* 0x17b4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_17b8:
	/* 0x17b8: mov    BYTE PTR [rax+0x43],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_17bb:
	/* 0x17bb: cmp    rsi,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 64ULL);
x86_l_17bf:
	/* 0x17bf: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_17c5:
	/* 0x17c5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17c9:
	/* 0x17c9: lea    ecx,[rsi+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_17cf:
	/* 0x17cf: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17d5:
	/* 0x17d5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17da:
	/* 0x17da: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_17de:
	/* 0x17de: mov    BYTE PTR [rax+0x44],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_17e1:
	/* 0x17e1: cmp    rsi,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 65ULL);
x86_l_17e5:
	/* 0x17e5: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_17eb:
	/* 0x17eb: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17ef:
	/* 0x17ef: lea    ecx,[rsi+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_17f5:
	/* 0x17f5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17fb:
	/* 0x17fb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1800:
	/* 0x1800: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1804:
	/* 0x1804: mov    BYTE PTR [rax+0x45],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_1807:
	/* 0x1807: cmp    rsi,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 66ULL);
x86_l_180b:
	/* 0x180b: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1811:
	/* 0x1811: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1815:
	/* 0x1815: lea    ecx,[rsi+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_181b:
	/* 0x181b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1821:
	/* 0x1821: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1826:
	/* 0x1826: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_182a:
	/* 0x182a: mov    BYTE PTR [rax+0x46],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_182d:
	/* 0x182d: cmp    rsi,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 67ULL);
x86_l_1831:
	/* 0x1831: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1837:
	/* 0x1837: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_183b:
	/* 0x183b: lea    ecx,[rsi+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_1841:
	/* 0x1841: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1847:
	/* 0x1847: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_184c:
	/* 0x184c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1850:
	/* 0x1850: mov    BYTE PTR [rax+0x47],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_1853:
	/* 0x1853: cmp    rsi,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 68ULL);
x86_l_1857:
	/* 0x1857: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_185d:
	/* 0x185d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1861:
	/* 0x1861: lea    ecx,[rsi+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_1867:
	/* 0x1867: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_186d:
	/* 0x186d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1872:
	/* 0x1872: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1876:
	/* 0x1876: mov    BYTE PTR [rax+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1879:
	/* 0x1879: cmp    rsi,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 69ULL);
x86_l_187d:
	/* 0x187d: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1883:
	/* 0x1883: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1887:
	/* 0x1887: lea    ecx,[rsi+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_188d:
	/* 0x188d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1893:
	/* 0x1893: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1898:
	/* 0x1898: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_189c:
	/* 0x189c: mov    BYTE PTR [rax+0x49],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_189f:
	/* 0x189f: cmp    rsi,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 70ULL);
x86_l_18a3:
	/* 0x18a3: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_18a9:
	/* 0x18a9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ad:
	/* 0x18ad: lea    ecx,[rsi+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_18b3:
	/* 0x18b3: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18b9:
	/* 0x18b9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18be:
	/* 0x18be: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_18c2:
	/* 0x18c2: mov    BYTE PTR [rax+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_18c5:
	/* 0x18c5: cmp    rsi,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 71ULL);
x86_l_18c9:
	/* 0x18c9: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_18cf:
	/* 0x18cf: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18d3:
	/* 0x18d3: lea    ecx,[rsi+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_18d9:
	/* 0x18d9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18df:
	/* 0x18df: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18e4:
	/* 0x18e4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_18e8:
	/* 0x18e8: mov    BYTE PTR [rax+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_18eb:
	/* 0x18eb: cmp    rsi,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 72ULL);
x86_l_18ef:
	/* 0x18ef: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_18f5:
	/* 0x18f5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18f9:
	/* 0x18f9: lea    ecx,[rsi+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_18ff:
	/* 0x18ff: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1905:
	/* 0x1905: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_190a:
	/* 0x190a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_190e:
	/* 0x190e: mov    BYTE PTR [rax+0x4c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1911:
	/* 0x1911: cmp    rsi,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 73ULL);
x86_l_1915:
	/* 0x1915: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_191b:
	/* 0x191b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_191f:
	/* 0x191f: lea    ecx,[rsi+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_1925:
	/* 0x1925: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_192b:
	/* 0x192b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1930:
	/* 0x1930: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1934:
	/* 0x1934: mov    BYTE PTR [rax+0x4d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_1937:
	/* 0x1937: cmp    rsi,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 74ULL);
x86_l_193b:
	/* 0x193b: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1941:
	/* 0x1941: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1945:
	/* 0x1945: lea    ecx,[rsi+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_194b:
	/* 0x194b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1951:
	/* 0x1951: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1956:
	/* 0x1956: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_195a:
	/* 0x195a: mov    BYTE PTR [rax+0x4e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_195d:
	/* 0x195d: cmp    rsi,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 75ULL);
x86_l_1961:
	/* 0x1961: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1967:
	/* 0x1967: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_196b:
	/* 0x196b: lea    ecx,[rsi+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_1971:
	/* 0x1971: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1977:
	/* 0x1977: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197c:
	/* 0x197c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1980:
	/* 0x1980: mov    BYTE PTR [rax+0x4f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_1983:
	/* 0x1983: cmp    rsi,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 76ULL);
x86_l_1987:
	/* 0x1987: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_198d:
	/* 0x198d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1991:
	/* 0x1991: lea    ecx,[rsi+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_1997:
	/* 0x1997: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_199d:
	/* 0x199d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19a2:
	/* 0x19a2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_19a6:
	/* 0x19a6: mov    BYTE PTR [rax+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19a9:
	/* 0x19a9: cmp    rsi,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 77ULL);
x86_l_19ad:
	/* 0x19ad: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_19b3:
	/* 0x19b3: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b7:
	/* 0x19b7: lea    ecx,[rsi+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_19bd:
	/* 0x19bd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19c3:
	/* 0x19c3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c8:
	/* 0x19c8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_19cc:
	/* 0x19cc: mov    BYTE PTR [rax+0x51],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_19cf:
	/* 0x19cf: cmp    rsi,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 78ULL);
x86_l_19d3:
	/* 0x19d3: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_19d9:
	/* 0x19d9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19dd:
	/* 0x19dd: lea    ecx,[rsi+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_19e3:
	/* 0x19e3: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19e9:
	/* 0x19e9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19ee:
	/* 0x19ee: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_19f2:
	/* 0x19f2: mov    BYTE PTR [rax+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_19f5:
	/* 0x19f5: cmp    rsi,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 79ULL);
x86_l_19f9:
	/* 0x19f9: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_19ff:
	/* 0x19ff: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a03:
	/* 0x1a03: lea    ecx,[rsi+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_1a09:
	/* 0x1a09: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a0f:
	/* 0x1a0f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a14:
	/* 0x1a14: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a18:
	/* 0x1a18: mov    BYTE PTR [rax+0x53],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_1a1b:
	/* 0x1a1b: cmp    rsi,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 80ULL);
x86_l_1a1f:
	/* 0x1a1f: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1a25:
	/* 0x1a25: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a29:
	/* 0x1a29: lea    ecx,[rsi+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_1a2f:
	/* 0x1a2f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a35:
	/* 0x1a35: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a3a:
	/* 0x1a3a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a3e:
	/* 0x1a3e: mov    BYTE PTR [rax+0x54],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1a41:
	/* 0x1a41: cmp    rsi,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 81ULL);
x86_l_1a45:
	/* 0x1a45: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1a4b:
	/* 0x1a4b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a4f:
	/* 0x1a4f: lea    ecx,[rsi+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_1a55:
	/* 0x1a55: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a5b:
	/* 0x1a5b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a60:
	/* 0x1a60: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a64:
	/* 0x1a64: mov    BYTE PTR [rax+0x55],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_1a67:
	/* 0x1a67: cmp    rsi,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 82ULL);
x86_l_1a6b:
	/* 0x1a6b: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1a71:
	/* 0x1a71: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a75:
	/* 0x1a75: lea    ecx,[rsi+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_1a7b:
	/* 0x1a7b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a81:
	/* 0x1a81: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a86:
	/* 0x1a86: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a8a:
	/* 0x1a8a: mov    BYTE PTR [rax+0x56],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1a8d:
	/* 0x1a8d: cmp    rsi,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 83ULL);
x86_l_1a91:
	/* 0x1a91: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1a97:
	/* 0x1a97: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a9b:
	/* 0x1a9b: lea    ecx,[rsi+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_1aa1:
	/* 0x1aa1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1aa7:
	/* 0x1aa7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aac:
	/* 0x1aac: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ab0:
	/* 0x1ab0: mov    BYTE PTR [rax+0x57],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_1ab3:
	/* 0x1ab3: cmp    rsi,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 84ULL);
x86_l_1ab7:
	/* 0x1ab7: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1abd:
	/* 0x1abd: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ac1:
	/* 0x1ac1: lea    ecx,[rsi+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_1ac7:
	/* 0x1ac7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1acd:
	/* 0x1acd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ad2:
	/* 0x1ad2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ad6:
	/* 0x1ad6: mov    BYTE PTR [rax+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ad9:
	/* 0x1ad9: cmp    rsi,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 85ULL);
x86_l_1add:
	/* 0x1add: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1ae3:
	/* 0x1ae3: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ae7:
	/* 0x1ae7: lea    ecx,[rsi+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_1aed:
	/* 0x1aed: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1af3:
	/* 0x1af3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1af8:
	/* 0x1af8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1afc:
	/* 0x1afc: mov    BYTE PTR [rax+0x59],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_1aff:
	/* 0x1aff: cmp    rsi,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 86ULL);
x86_l_1b03:
	/* 0x1b03: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1b09:
	/* 0x1b09: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b0d:
	/* 0x1b0d: lea    ecx,[rsi+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_1b13:
	/* 0x1b13: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b19:
	/* 0x1b19: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b1e:
	/* 0x1b1e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1b22:
	/* 0x1b22: mov    BYTE PTR [rax+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_1b25:
	/* 0x1b25: cmp    rsi,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 87ULL);
x86_l_1b29:
	/* 0x1b29: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1b2f:
	/* 0x1b2f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b33:
	/* 0x1b33: lea    ecx,[rsi+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_1b39:
	/* 0x1b39: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b3f:
	/* 0x1b3f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b44:
	/* 0x1b44: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1b48:
	/* 0x1b48: mov    BYTE PTR [rax+0x5b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_1b4b:
	/* 0x1b4b: cmp    rsi,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 88ULL);
x86_l_1b4f:
	/* 0x1b4f: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1b55:
	/* 0x1b55: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b59:
	/* 0x1b59: lea    ecx,[rsi+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_1b5f:
	/* 0x1b5f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b65:
	/* 0x1b65: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b6a:
	/* 0x1b6a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1b6e:
	/* 0x1b6e: mov    BYTE PTR [rax+0x5c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1b71:
	/* 0x1b71: cmp    rsi,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 89ULL);
x86_l_1b75:
	/* 0x1b75: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1b7b:
	/* 0x1b7b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b7f:
	/* 0x1b7f: lea    ecx,[rsi+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_1b85:
	/* 0x1b85: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b8b:
	/* 0x1b8b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b90:
	/* 0x1b90: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1b94:
	/* 0x1b94: mov    BYTE PTR [rax+0x5d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_1b97:
	/* 0x1b97: cmp    rsi,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 90ULL);
x86_l_1b9b:
	/* 0x1b9b: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1ba1:
	/* 0x1ba1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ba5:
	/* 0x1ba5: lea    ecx,[rsi+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_1bab:
	/* 0x1bab: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1bb1:
	/* 0x1bb1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bb6:
	/* 0x1bb6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1bba:
	/* 0x1bba: mov    BYTE PTR [rax+0x5e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_1bbd:
	/* 0x1bbd: cmp    rsi,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 91ULL);
x86_l_1bc1:
	/* 0x1bc1: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1bc3:
	/* 0x1bc3: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc7:
	/* 0x1bc7: lea    ecx,[rsi+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_1bcd:
	/* 0x1bcd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1bd3:
	/* 0x1bd3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bd8:
	/* 0x1bd8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1bdc:
	/* 0x1bdc: mov    BYTE PTR [rax+0x5f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_1bdf:
	/* 0x1bdf: cmp    rsi,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 92ULL);
x86_l_1be3:
	/* 0x1be3: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1be5:
	/* 0x1be5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1be9:
	/* 0x1be9: lea    ecx,[rsi+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_1bef:
	/* 0x1bef: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1bf5:
	/* 0x1bf5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bfa:
	/* 0x1bfa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1bfe:
	/* 0x1bfe: mov    BYTE PTR [rax+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c01:
	/* 0x1c01: cmp    rsi,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 93ULL);
x86_l_1c05:
	/* 0x1c05: je     1c23 <generic_fentry_filter_arg+0x1c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c23;
	}
x86_l_1c07:
	/* 0x1c07: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c0b:
	/* 0x1c0b: add    edx,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_1c11:
	/* 0x1c11: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c17:
	/* 0x1c17: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c1c:
	/* 0x1c1c: movzx  ecx,BYTE PTR [rcx+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_8), 0ULL);
x86_l_1c20:
	/* 0x1c20: mov    BYTE PTR [rax+0x61],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_1c23:
	/* 0x1c23: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1c28:
	/* 0x1c28: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1c2b:
	/* 0x1c2b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1c2e:
	/* 0x1c2e: jmp    3800 <generic_fentry_filter_arg+0x3800> */
	return 14336ULL;
x86_l_1c33:
	/* 0x1c33: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_1c36:
	/* 0x1c36: ja     383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14394ULL;
	}
	return 7228ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7228ULL: goto x86_l_1c3c;
	case 7230ULL: goto x86_l_1c3e;
	case 7240ULL: goto x86_l_1c48;
	case 7244ULL: goto x86_l_1c4c;
	case 7246ULL: goto x86_l_1c4e;
	case 7250ULL: goto x86_l_1c52;
	case 7253ULL: goto x86_l_1c55;
	case 7259ULL: goto x86_l_1c5b;
	case 7264ULL: goto x86_l_1c60;
	case 7267ULL: goto x86_l_1c63;
	case 7273ULL: goto x86_l_1c69;
	case 7277ULL: goto x86_l_1c6d;
	case 7280ULL: goto x86_l_1c70;
	case 7283ULL: goto x86_l_1c73;
	case 7289ULL: goto x86_l_1c79;
	case 7292ULL: goto x86_l_1c7c;
	case 7298ULL: goto x86_l_1c82;
	case 7303ULL: goto x86_l_1c87;
	case 7308ULL: goto x86_l_1c8c;
	case 7312ULL: goto x86_l_1c90;
	case 7318ULL: goto x86_l_1c96;
	case 7322ULL: goto x86_l_1c9a;
	case 7325ULL: goto x86_l_1c9d;
	case 7331ULL: goto x86_l_1ca3;
	case 7336ULL: goto x86_l_1ca8;
	case 7339ULL: goto x86_l_1cab;
	case 7345ULL: goto x86_l_1cb1;
	case 7349ULL: goto x86_l_1cb5;
	case 7352ULL: goto x86_l_1cb8;
	case 7355ULL: goto x86_l_1cbb;
	case 7361ULL: goto x86_l_1cc1;
	case 7363ULL: goto x86_l_1cc3;
	case 7369ULL: goto x86_l_1cc9;
	case 7374ULL: goto x86_l_1cce;
	case 7377ULL: goto x86_l_1cd1;
	case 7383ULL: goto x86_l_1cd7;
	case 7386ULL: goto x86_l_1cda;
	case 7389ULL: goto x86_l_1cdd;
	case 7395ULL: goto x86_l_1ce3;
	case 7400ULL: goto x86_l_1ce8;
	case 7405ULL: goto x86_l_1ced;
	case 7408ULL: goto x86_l_1cf0;
	case 7414ULL: goto x86_l_1cf6;
	case 7417ULL: goto x86_l_1cf9;
	case 7422ULL: goto x86_l_1cfe;
	case 7426ULL: goto x86_l_1d02;
	case 7431ULL: goto x86_l_1d07;
	case 7438ULL: goto x86_l_1d0e;
	case 7443ULL: goto x86_l_1d13;
	case 7445ULL: goto x86_l_1d15;
	case 7448ULL: goto x86_l_1d18;
	case 7454ULL: goto x86_l_1d1e;
	case 7457ULL: goto x86_l_1d21;
	case 7462ULL: goto x86_l_1d26;
	case 7467ULL: goto x86_l_1d2b;
	case 7472ULL: goto x86_l_1d30;
	case 7475ULL: goto x86_l_1d33;
	case 7477ULL: goto x86_l_1d35;
	case 7481ULL: goto x86_l_1d39;
	case 7484ULL: goto x86_l_1d3c;
	case 7490ULL: goto x86_l_1d42;
	case 7493ULL: goto x86_l_1d45;
	case 7499ULL: goto x86_l_1d4b;
	case 7504ULL: goto x86_l_1d50;
	case 7507ULL: goto x86_l_1d53;
	case 7509ULL: goto x86_l_1d55;
	case 7512ULL: goto x86_l_1d58;
	case 7518ULL: goto x86_l_1d5e;
	case 7522ULL: goto x86_l_1d62;
	case 7525ULL: goto x86_l_1d65;
	case 7531ULL: goto x86_l_1d6b;
	case 7535ULL: goto x86_l_1d6f;
	case 7538ULL: goto x86_l_1d72;
	case 7544ULL: goto x86_l_1d78;
	case 7547ULL: goto x86_l_1d7b;
	case 7553ULL: goto x86_l_1d81;
	case 7558ULL: goto x86_l_1d86;
	case 7561ULL: goto x86_l_1d89;
	case 7567ULL: goto x86_l_1d8f;
	case 7572ULL: goto x86_l_1d94;
	case 7577ULL: goto x86_l_1d99;
	case 7580ULL: goto x86_l_1d9c;
	case 7586ULL: goto x86_l_1da2;
	case 7589ULL: goto x86_l_1da5;
	case 7594ULL: goto x86_l_1daa;
	case 7598ULL: goto x86_l_1dae;
	case 7603ULL: goto x86_l_1db3;
	case 7610ULL: goto x86_l_1dba;
	case 7615ULL: goto x86_l_1dbf;
	case 7617ULL: goto x86_l_1dc1;
	case 7620ULL: goto x86_l_1dc4;
	case 7626ULL: goto x86_l_1dca;
	case 7629ULL: goto x86_l_1dcd;
	case 7634ULL: goto x86_l_1dd2;
	case 7639ULL: goto x86_l_1dd7;
	case 7644ULL: goto x86_l_1ddc;
	case 7649ULL: goto x86_l_1de1;
	case 7652ULL: goto x86_l_1de4;
	case 7654ULL: goto x86_l_1de6;
	case 7656ULL: goto x86_l_1de8;
	case 7662ULL: goto x86_l_1dee;
	case 7666ULL: goto x86_l_1df2;
	case 7669ULL: goto x86_l_1df5;
	case 7675ULL: goto x86_l_1dfb;
	case 7679ULL: goto x86_l_1dff;
	case 7682ULL: goto x86_l_1e02;
	case 7688ULL: goto x86_l_1e08;
	case 7690ULL: goto x86_l_1e0a;
	case 7696ULL: goto x86_l_1e10;
	case 7701ULL: goto x86_l_1e15;
	case 7705ULL: goto x86_l_1e19;
	case 7708ULL: goto x86_l_1e1c;
	case 7712ULL: goto x86_l_1e20;
	case 7715ULL: goto x86_l_1e23;
	case 7717ULL: goto x86_l_1e25;
	case 7719ULL: goto x86_l_1e27;
	case 7722ULL: goto x86_l_1e2a;
	case 7725ULL: goto x86_l_1e2d;
	case 7731ULL: goto x86_l_1e33;
	case 7734ULL: goto x86_l_1e36;
	case 7740ULL: goto x86_l_1e3c;
	case 7742ULL: goto x86_l_1e3e;
	case 7747ULL: goto x86_l_1e43;
	case 7751ULL: goto x86_l_1e47;
	case 7757ULL: goto x86_l_1e4d;
	case 7762ULL: goto x86_l_1e52;
	case 7766ULL: goto x86_l_1e56;
	case 7772ULL: goto x86_l_1e5c;
	case 7782ULL: goto x86_l_1e66;
	case 7786ULL: goto x86_l_1e6a;
	case 7792ULL: goto x86_l_1e70;
	case 7799ULL: goto x86_l_1e77;
	case 7806ULL: goto x86_l_1e7e;
	case 7812ULL: goto x86_l_1e84;
	case 7815ULL: goto x86_l_1e87;
	case 7820ULL: goto x86_l_1e8c;
	case 7824ULL: goto x86_l_1e90;
	case 7828ULL: goto x86_l_1e94;
	case 7836ULL: goto x86_l_1e9c;
	case 7841ULL: goto x86_l_1ea1;
	case 7848ULL: goto x86_l_1ea8;
	case 7853ULL: goto x86_l_1ead;
	case 7855ULL: goto x86_l_1eaf;
	case 7858ULL: goto x86_l_1eb2;
	case 7863ULL: goto x86_l_1eb7;
	case 7869ULL: goto x86_l_1ebd;
	case 7872ULL: goto x86_l_1ec0;
	case 7875ULL: goto x86_l_1ec3;
	case 7881ULL: goto x86_l_1ec9;
	case 7886ULL: goto x86_l_1ece;
	case 7893ULL: goto x86_l_1ed5;
	case 7898ULL: goto x86_l_1eda;
	case 7900ULL: goto x86_l_1edc;
	case 7903ULL: goto x86_l_1edf;
	case 7909ULL: goto x86_l_1ee5;
	case 7913ULL: goto x86_l_1ee9;
	case 7919ULL: goto x86_l_1eef;
	case 7924ULL: goto x86_l_1ef4;
	case 7927ULL: goto x86_l_1ef7;
	case 7934ULL: goto x86_l_1efe;
	case 7936ULL: goto x86_l_1f00;
	case 7939ULL: goto x86_l_1f03;
	case 7943ULL: goto x86_l_1f07;
	case 7948ULL: goto x86_l_1f0c;
	case 7953ULL: goto x86_l_1f11;
	case 7956ULL: goto x86_l_1f14;
	case 7958ULL: goto x86_l_1f16;
	case 7963ULL: goto x86_l_1f1b;
	case 7966ULL: goto x86_l_1f1e;
	case 7969ULL: goto x86_l_1f21;
	case 7971ULL: goto x86_l_1f23;
	case 7976ULL: goto x86_l_1f28;
	case 7984ULL: goto x86_l_1f30;
	case 7990ULL: goto x86_l_1f36;
	case 7996ULL: goto x86_l_1f3c;
	case 7999ULL: goto x86_l_1f3f;
	case 8005ULL: goto x86_l_1f45;
	case 8008ULL: goto x86_l_1f48;
	case 8011ULL: goto x86_l_1f4b;
	case 8014ULL: goto x86_l_1f4e;
	case 8016ULL: goto x86_l_1f50;
	case 8018ULL: goto x86_l_1f52;
	case 8021ULL: goto x86_l_1f55;
	case 8027ULL: goto x86_l_1f5b;
	case 8029ULL: goto x86_l_1f5d;
	case 8035ULL: goto x86_l_1f63;
	case 8040ULL: goto x86_l_1f68;
	case 8043ULL: goto x86_l_1f6b;
	case 8048ULL: goto x86_l_1f70;
	case 8052ULL: goto x86_l_1f74;
	case 8057ULL: goto x86_l_1f79;
	case 8061ULL: goto x86_l_1f7d;
	case 8066ULL: goto x86_l_1f82;
	case 8070ULL: goto x86_l_1f86;
	case 8075ULL: goto x86_l_1f8b;
	case 8080ULL: goto x86_l_1f90;
	case 8082ULL: goto x86_l_1f92;
	case 8086ULL: goto x86_l_1f96;
	case 8089ULL: goto x86_l_1f99;
	case 8092ULL: goto x86_l_1f9c;
	case 8094ULL: goto x86_l_1f9e;
	case 8097ULL: goto x86_l_1fa1;
	case 8099ULL: goto x86_l_1fa3;
	case 8102ULL: goto x86_l_1fa6;
	case 8105ULL: goto x86_l_1fa9;
	case 8111ULL: goto x86_l_1faf;
	case 8114ULL: goto x86_l_1fb2;
	case 8117ULL: goto x86_l_1fb5;
	case 8123ULL: goto x86_l_1fbb;
	case 8128ULL: goto x86_l_1fc0;
	case 8131ULL: goto x86_l_1fc3;
	case 8133ULL: goto x86_l_1fc5;
	case 8136ULL: goto x86_l_1fc8;
	case 8142ULL: goto x86_l_1fce;
	case 8145ULL: goto x86_l_1fd1;
	case 8151ULL: goto x86_l_1fd7;
	case 8154ULL: goto x86_l_1fda;
	case 8160ULL: goto x86_l_1fe0;
	case 8165ULL: goto x86_l_1fe5;
	case 8170ULL: goto x86_l_1fea;
	case 8173ULL: goto x86_l_1fed;
	case 8179ULL: goto x86_l_1ff3;
	case 8182ULL: goto x86_l_1ff6;
	case 8188ULL: goto x86_l_1ffc;
	case 8191ULL: goto x86_l_1fff;
	case 8197ULL: goto x86_l_2005;
	case 8202ULL: goto x86_l_200a;
	case 8205ULL: goto x86_l_200d;
	case 8211ULL: goto x86_l_2013;
	case 8214ULL: goto x86_l_2016;
	case 8220ULL: goto x86_l_201c;
	case 8223ULL: goto x86_l_201f;
	case 8229ULL: goto x86_l_2025;
	case 8234ULL: goto x86_l_202a;
	case 8237ULL: goto x86_l_202d;
	case 8240ULL: goto x86_l_2030;
	case 8246ULL: goto x86_l_2036;
	case 8251ULL: goto x86_l_203b;
	case 8259ULL: goto x86_l_2043;
	case 8266ULL: goto x86_l_204a;
	case 8272ULL: goto x86_l_2050;
	case 8277ULL: goto x86_l_2055;
	case 8281ULL: goto x86_l_2059;
	case 8287ULL: goto x86_l_205f;
	case 8290ULL: goto x86_l_2062;
	case 8293ULL: goto x86_l_2065;
	case 8296ULL: goto x86_l_2068;
	case 8299ULL: goto x86_l_206b;
	case 8301ULL: goto x86_l_206d;
	case 8305ULL: goto x86_l_2071;
	case 8310ULL: goto x86_l_2076;
	case 8316ULL: goto x86_l_207c;
	case 8318ULL: goto x86_l_207e;
	case 8324ULL: goto x86_l_2084;
	case 8327ULL: goto x86_l_2087;
	case 8332ULL: goto x86_l_208c;
	case 8335ULL: goto x86_l_208f;
	case 8337ULL: goto x86_l_2091;
	case 8340ULL: goto x86_l_2094;
	case 8346ULL: goto x86_l_209a;
	case 8349ULL: goto x86_l_209d;
	case 8355ULL: goto x86_l_20a3;
	case 8359ULL: goto x86_l_20a7;
	case 8362ULL: goto x86_l_20aa;
	case 8368ULL: goto x86_l_20b0;
	case 8371ULL: goto x86_l_20b3;
	case 8377ULL: goto x86_l_20b9;
	case 8382ULL: goto x86_l_20be;
	case 8385ULL: goto x86_l_20c1;
	case 8387ULL: goto x86_l_20c3;
	case 8390ULL: goto x86_l_20c6;
	case 8396ULL: goto x86_l_20cc;
	case 8401ULL: goto x86_l_20d1;
	case 8405ULL: goto x86_l_20d5;
	case 8407ULL: goto x86_l_20d7;
	case 8412ULL: goto x86_l_20dc;
	case 8416ULL: goto x86_l_20e0;
	case 8418ULL: goto x86_l_20e2;
	case 8421ULL: goto x86_l_20e5;
	case 8424ULL: goto x86_l_20e8;
	case 8429ULL: goto x86_l_20ed;
	case 8432ULL: goto x86_l_20f0;
	case 8438ULL: goto x86_l_20f6;
	case 8441ULL: goto x86_l_20f9;
	case 8447ULL: goto x86_l_20ff;
	case 8450ULL: goto x86_l_2102;
	case 8456ULL: goto x86_l_2108;
	case 8459ULL: goto x86_l_210b;
	case 8465ULL: goto x86_l_2111;
	case 8468ULL: goto x86_l_2114;
	case 8473ULL: goto x86_l_2119;
	case 8478ULL: goto x86_l_211e;
	case 8483ULL: goto x86_l_2123;
	case 8487ULL: goto x86_l_2127;
	case 8491ULL: goto x86_l_212b;
	case 8499ULL: goto x86_l_2133;
	case 8504ULL: goto x86_l_2138;
	case 8511ULL: goto x86_l_213f;
	case 8516ULL: goto x86_l_2144;
	case 8519ULL: goto x86_l_2147;
	case 8521ULL: goto x86_l_2149;
	case 8524ULL: goto x86_l_214c;
	case 8527ULL: goto x86_l_214f;
	case 8530ULL: goto x86_l_2152;
	case 8536ULL: goto x86_l_2158;
	case 8540ULL: goto x86_l_215c;
	case 8543ULL: goto x86_l_215f;
	case 8549ULL: goto x86_l_2165;
	case 8554ULL: goto x86_l_216a;
	case 8561ULL: goto x86_l_2171;
	case 8566ULL: goto x86_l_2176;
	case 8568ULL: goto x86_l_2178;
	case 8571ULL: goto x86_l_217b;
	case 8577ULL: goto x86_l_2181;
	case 8582ULL: goto x86_l_2186;
	case 8586ULL: goto x86_l_218a;
	case 8590ULL: goto x86_l_218e;
	case 8595ULL: goto x86_l_2193;
	case 8599ULL: goto x86_l_2197;
	case 8602ULL: goto x86_l_219a;
	case 8604ULL: goto x86_l_219c;
	case 8608ULL: goto x86_l_21a0;
	case 8614ULL: goto x86_l_21a6;
	case 8618ULL: goto x86_l_21aa;
	case 8621ULL: goto x86_l_21ad;
	case 8625ULL: goto x86_l_21b1;
	case 8631ULL: goto x86_l_21b7;
	case 8638ULL: goto x86_l_21be;
	case 8644ULL: goto x86_l_21c4;
	case 8648ULL: goto x86_l_21c8;
	case 8651ULL: goto x86_l_21cb;
	case 8655ULL: goto x86_l_21cf;
	case 8661ULL: goto x86_l_21d5;
	case 8668ULL: goto x86_l_21dc;
	case 8674ULL: goto x86_l_21e2;
	case 8678ULL: goto x86_l_21e6;
	case 8681ULL: goto x86_l_21e9;
	case 8685ULL: goto x86_l_21ed;
	case 8691ULL: goto x86_l_21f3;
	case 8698ULL: goto x86_l_21fa;
	case 8704ULL: goto x86_l_2200;
	case 8708ULL: goto x86_l_2204;
	case 8711ULL: goto x86_l_2207;
	case 8715ULL: goto x86_l_220b;
	case 8721ULL: goto x86_l_2211;
	case 8728ULL: goto x86_l_2218;
	case 8734ULL: goto x86_l_221e;
	case 8738ULL: goto x86_l_2222;
	case 8741ULL: goto x86_l_2225;
	case 8745ULL: goto x86_l_2229;
	case 8751ULL: goto x86_l_222f;
	case 8758ULL: goto x86_l_2236;
	case 8764ULL: goto x86_l_223c;
	case 8768ULL: goto x86_l_2240;
	case 8771ULL: goto x86_l_2243;
	case 8775ULL: goto x86_l_2247;
	case 8781ULL: goto x86_l_224d;
	case 8788ULL: goto x86_l_2254;
	case 8794ULL: goto x86_l_225a;
	case 8798ULL: goto x86_l_225e;
	case 8801ULL: goto x86_l_2261;
	case 8805ULL: goto x86_l_2265;
	case 8811ULL: goto x86_l_226b;
	case 8818ULL: goto x86_l_2272;
	case 8824ULL: goto x86_l_2278;
	case 8828ULL: goto x86_l_227c;
	case 8831ULL: goto x86_l_227f;
	case 8835ULL: goto x86_l_2283;
	case 8841ULL: goto x86_l_2289;
	case 8848ULL: goto x86_l_2290;
	case 8854ULL: goto x86_l_2296;
	case 8858ULL: goto x86_l_229a;
	case 8861ULL: goto x86_l_229d;
	case 8865ULL: goto x86_l_22a1;
	case 8871ULL: goto x86_l_22a7;
	case 8878ULL: goto x86_l_22ae;
	case 8884ULL: goto x86_l_22b4;
	case 8888ULL: goto x86_l_22b8;
	case 8891ULL: goto x86_l_22bb;
	case 8895ULL: goto x86_l_22bf;
	case 8901ULL: goto x86_l_22c5;
	case 8908ULL: goto x86_l_22cc;
	case 8914ULL: goto x86_l_22d2;
	case 8918ULL: goto x86_l_22d6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c3c:
	/* 0x1c3c: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c3e:
	/* 0x1c3e: movabs rcx,0x1e10000c00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 129117457408ULL);
x86_l_1c48:
	/* 0x1c48: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1c4c:
	/* 0x1c4c: jae    1c87 <generic_fentry_filter_arg+0x1c87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1c87;
	}
x86_l_1c4e:
	/* 0x1c4e: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c52:
	/* 0x1c52: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1c55:
	/* 0x1c55: ja     3844 <generic_fentry_filter_arg+0x3844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14404ULL;
	}
x86_l_1c5b:
	/* 0x1c5b: mov    ecx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4126ULL);
x86_l_1c60:
	/* 0x1c60: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1c63:
	/* 0x1c63: jae    1ce8 <generic_fentry_filter_arg+0x1ce8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1ce8;
	}
x86_l_1c69:
	/* 0x1c69: mov    rdx,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c6d:
	/* 0x1c6d: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1c70:
	/* 0x1c70: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c73:
	/* 0x1c73: jae    1d50 <generic_fentry_filter_arg+0x1d50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d50;
	}
x86_l_1c79:
	/* 0x1c79: cmp    QWORD PTR [rdi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c7c:
	/* 0x1c7c: jne    1d5e <generic_fentry_filter_arg+0x1d5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d5e;
	}
x86_l_1c82:
	/* 0x1c82: jmp    3632 <generic_fentry_filter_arg+0x3632> */
	return 13874ULL;
x86_l_1c87:
	/* 0x1c87: mov    ecx,0x3012 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 12306ULL);
x86_l_1c8c:
	/* 0x1c8c: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1c90:
	/* 0x1c90: jae    383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14394ULL;
	}
x86_l_1c96:
	/* 0x1c96: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c9a:
	/* 0x1c9a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1c9d:
	/* 0x1c9d: ja     3844 <generic_fentry_filter_arg+0x3844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14404ULL;
	}
x86_l_1ca3:
	/* 0x1ca3: mov    ecx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4126ULL);
x86_l_1ca8:
	/* 0x1ca8: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1cab:
	/* 0x1cab: jae    1d94 <generic_fentry_filter_arg+0x1d94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d94;
	}
x86_l_1cb1:
	/* 0x1cb1: mov    edx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cb5:
	/* 0x1cb5: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1cb8:
	/* 0x1cb8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1cbb:
	/* 0x1cbb: jae    1de1 <generic_fentry_filter_arg+0x1de1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1de1;
	}
x86_l_1cc1:
	/* 0x1cc1: cmp    DWORD PTR [rdi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc3:
	/* 0x1cc3: jne    1dee <generic_fentry_filter_arg+0x1dee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1dee;
	}
x86_l_1cc9:
	/* 0x1cc9: jmp    3632 <generic_fentry_filter_arg+0x3632> */
	return 13874ULL;
x86_l_1cce:
	/* 0x1cce: cmp    eax,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 40ULL);
x86_l_1cd1:
	/* 0x1cd1: je     1f68 <generic_fentry_filter_arg+0x1f68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f68;
	}
x86_l_1cd7:
	/* 0x1cd7: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1cda:
	/* 0x1cda: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_1cdd:
	/* 0x1cdd: je     1f92 <generic_fentry_filter_arg+0x1f92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f92;
	}
x86_l_1ce3:
	/* 0x1ce3: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_1ce8:
	/* 0x1ce8: mov    ecx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3072ULL);
x86_l_1ced:
	/* 0x1ced: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1cf0:
	/* 0x1cf0: jae    3844 <generic_fentry_filter_arg+0x3844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14404ULL;
	}
x86_l_1cf6:
	/* 0x1cf6: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_1cf9:
	/* 0x1cf9: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1cfe:
	/* 0x1cfe: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d02:
	/* 0x1d02: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d07:
	/* 0x1d07: mov    rdi,QWORD PTR [rip+0x5d33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1d0e:
	/* 0x1d0e: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d13:
	/* 0x1d13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d15:
	/* 0x1d15: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d18:
	/* 0x1d18: je     346a <generic_fentry_filter_arg+0x346a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13418ULL;
	}
x86_l_1d1e:
	/* 0x1d1e: mov    rcx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d21:
	/* 0x1d21: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d26:
	/* 0x1d26: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1d2b:
	/* 0x1d2b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d30:
	/* 0x1d30: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1d33:
	/* 0x1d33: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1d35:
	/* 0x1d35: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d39:
	/* 0x1d39: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1d3c:
	/* 0x1d3c: je     2f8a <generic_fentry_filter_arg+0x2f8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12170ULL;
	}
x86_l_1d42:
	/* 0x1d42: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1d45:
	/* 0x1d45: je     303f <generic_fentry_filter_arg+0x303f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12351ULL;
	}
x86_l_1d4b:
	/* 0x1d4b: jmp    304e <generic_fentry_filter_arg+0x304e> */
	return 12366ULL;
x86_l_1d50:
	/* 0x1d50: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d53:
	/* 0x1d53: jne    1d5e <generic_fentry_filter_arg+0x1d5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d5e;
	}
x86_l_1d55:
	/* 0x1d55: test   QWORD PTR [rdi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d58:
	/* 0x1d58: jne    383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14394ULL;
	}
x86_l_1d5e:
	/* 0x1d5e: mov    edx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d62:
	/* 0x1d62: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d65:
	/* 0x1d65: jb     36a6 <generic_fentry_filter_arg+0x36a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13990ULL;
	}
x86_l_1d6b:
	/* 0x1d6b: mov    rsi,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d6f:
	/* 0x1d6f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1d72:
	/* 0x1d72: jae    208c <generic_fentry_filter_arg+0x208c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_208c;
	}
x86_l_1d78:
	/* 0x1d78: cmp    QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d7b:
	/* 0x1d7b: jne    209a <generic_fentry_filter_arg+0x209a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_209a;
	}
x86_l_1d81:
	/* 0x1d81: jmp    3632 <generic_fentry_filter_arg+0x3632> */
	return 13874ULL;
x86_l_1d86:
	/* 0x1d86: cmp    eax,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 42ULL);
x86_l_1d89:
	/* 0x1d89: je     1e19 <generic_fentry_filter_arg+0x1e19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e19;
	}
x86_l_1d8f:
	/* 0x1d8f: jmp    383a <generic_fentry_filter_arg+0x383a> */
	return 14394ULL;
x86_l_1d94:
	/* 0x1d94: mov    ecx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3072ULL);
x86_l_1d99:
	/* 0x1d99: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1d9c:
	/* 0x1d9c: jae    3844 <generic_fentry_filter_arg+0x3844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14404ULL;
	}
x86_l_1da2:
	/* 0x1da2: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_1da5:
	/* 0x1da5: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1daa:
	/* 0x1daa: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1dae:
	/* 0x1dae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1db3:
	/* 0x1db3: mov    rdi,QWORD PTR [rip+0x5d33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1dba:
	/* 0x1dba: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1dbf:
	/* 0x1dbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc1:
	/* 0x1dc1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dc4:
	/* 0x1dc4: je     346a <generic_fentry_filter_arg+0x346a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13418ULL;
	}
x86_l_1dca:
	/* 0x1dca: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dcd:
	/* 0x1dcd: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1dd2:
	/* 0x1dd2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1dd7:
	/* 0x1dd7: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ddc:
	/* 0x1ddc: jmp    3262 <generic_fentry_filter_arg+0x3262> */
	return 12898ULL;
x86_l_1de1:
	/* 0x1de1: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1de4:
	/* 0x1de4: jne    1dee <generic_fentry_filter_arg+0x1dee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1dee;
	}
x86_l_1de6:
	/* 0x1de6: test   DWORD PTR [rdi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1de8:
	/* 0x1de8: jne    383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14394ULL;
	}
x86_l_1dee:
	/* 0x1dee: mov    edx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df2:
	/* 0x1df2: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1df5:
	/* 0x1df5: jb     36a6 <generic_fentry_filter_arg+0x36a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13990ULL;
	}
x86_l_1dfb:
	/* 0x1dfb: mov    esi,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1dff:
	/* 0x1dff: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1e02:
	/* 0x1e02: jae    2f0e <generic_fentry_filter_arg+0x2f0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12046ULL;
	}
x86_l_1e08:
	/* 0x1e08: cmp    DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e0a:
	/* 0x1e0a: jne    2f1b <generic_fentry_filter_arg+0x2f1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12059ULL;
	}
x86_l_1e10:
	/* 0x1e10: jmp    3632 <generic_fentry_filter_arg+0x3632> */
	return 13874ULL;
x86_l_1e15:
	/* 0x1e15: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1e19:
	/* 0x1e19: mov    r8d,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e1c:
	/* 0x1e1c: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e20:
	/* 0x1e20: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_1e23:
	/* 0x1e23: jne    1e33 <generic_fentry_filter_arg+0x1e33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e33;
	}
x86_l_1e25:
	/* 0x1e25: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1e27:
	/* 0x1e27: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1e2a:
	/* 0x1e2a: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_1e2d:
	/* 0x1e2d: jne    3844 <generic_fentry_filter_arg+0x3844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14404ULL;
	}
x86_l_1e33:
	/* 0x1e33: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_1e36:
	/* 0x1e36: ja     202a <generic_fentry_filter_arg+0x202a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_202a;
	}
x86_l_1e3c:
	/* 0x1e3c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1e3e:
	/* 0x1e3e: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_1e43:
	/* 0x1e43: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1e47:
	/* 0x1e47: jb     2c96 <generic_fentry_filter_arg+0x2c96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11414ULL;
	}
x86_l_1e4d:
	/* 0x1e4d: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_1e52:
	/* 0x1e52: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1e56:
	/* 0x1e56: jb     2119 <generic_fentry_filter_arg+0x2119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2119;
	}
x86_l_1e5c:
	/* 0x1e5c: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_1e66:
	/* 0x1e66: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1e6a:
	/* 0x1e6a: jae    202a <generic_fentry_filter_arg+0x202a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_202a;
	}
x86_l_1e70:
	/* 0x1e70: mov    WORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1e77:
	/* 0x1e77: cmp    r8d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 144ULL);
x86_l_1e7e:
	/* 0x1e7e: jbe    3183 <generic_fentry_filter_arg+0x3183> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 12675ULL;
	}
x86_l_1e84:
	/* 0x1e84: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e87:
	/* 0x1e87: jmp    3789 <generic_fentry_filter_arg+0x3789> */
	return 14217ULL;
x86_l_1e8c:
	/* 0x1e8c: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e90:
	/* 0x1e90: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e94:
	/* 0x1e94: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1e9c:
	/* 0x1e9c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ea1:
	/* 0x1ea1: mov    rdi,QWORD PTR [rip+0x5d33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1ea8:
	/* 0x1ea8: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ead:
	/* 0x1ead: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eaf:
	/* 0x1eaf: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eb2:
	/* 0x1eb2: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eb7:
	/* 0x1eb7: je     3717 <generic_fentry_filter_arg+0x3717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14103ULL;
	}
x86_l_1ebd:
	/* 0x1ebd: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1ec0:
	/* 0x1ec0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ec3:
	/* 0x1ec3: je     3717 <generic_fentry_filter_arg+0x3717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14103ULL;
	}
x86_l_1ec9:
	/* 0x1ec9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ece:
	/* 0x1ece: mov    rdi,QWORD PTR [rip+0x5d33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1ed5:
	/* 0x1ed5: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1eda:
	/* 0x1eda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1edc:
	/* 0x1edc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1edf:
	/* 0x1edf: je     3714 <generic_fentry_filter_arg+0x3714> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14100ULL;
	}
x86_l_1ee5:
	/* 0x1ee5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ee9:
	/* 0x1ee9: cmp    ecx,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_1eef:
	/* 0x1eef: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_1ef4:
	/* 0x1ef4: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1ef7:
	/* 0x1ef7: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_1efe:
	/* 0x1efe: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f00:
	/* 0x1f00: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1f03:
	/* 0x1f03: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1f07:
	/* 0x1f07: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f0c:
	/* 0x1f0c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f11:
	/* 0x1f11: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1f14:
	/* 0x1f14: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1f16:
	/* 0x1f16: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f1b:
	/* 0x1f1b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1f1e:
	/* 0x1f1e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1f21:
	/* 0x1f21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f23:
	/* 0x1f23: jmp    3708 <generic_fentry_filter_arg+0x3708> */
	return 14088ULL;
x86_l_1f28:
	/* 0x1f28: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1f30:
	/* 0x1f30: cmp    edx,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1f36:
	/* 0x1f36: ja     3714 <generic_fentry_filter_arg+0x3714> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14100ULL;
	}
x86_l_1f3c:
	/* 0x1f3c: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f3f:
	/* 0x1f3f: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1f45:
	/* 0x1f45: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1f48:
	/* 0x1f48: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1f4b:
	/* 0x1f4b: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1f4e:
	/* 0x1f4e: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1f50:
	/* 0x1f50: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1f52:
	/* 0x1f52: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_1f55:
	/* 0x1f55: je     3059 <generic_fentry_filter_arg+0x3059> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12377ULL;
	}
x86_l_1f5b:
	/* 0x1f5b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1f5d:
	/* 0x1f5d: jne    3059 <generic_fentry_filter_arg+0x3059> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12377ULL;
	}
x86_l_1f63:
	/* 0x1f63: jmp    3070 <generic_fentry_filter_arg+0x3070> */
	return 12400ULL;
x86_l_1f68:
	/* 0x1f68: movzx  ecx,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f6b:
	/* 0x1f6b: mov    WORD PTR [rsp+0x76],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_1f70:
	/* 0x1f70: movzx  ecx,WORD PTR [rdi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1f74:
	/* 0x1f74: mov    WORD PTR [rsp+0x70],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f79:
	/* 0x1f79: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f7d:
	/* 0x1f7d: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f82:
	/* 0x1f82: mov    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f86:
	/* 0x1f86: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f8b:
	/* 0x1f8b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f90:
	/* 0x1f90: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f92:
	/* 0x1f92: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f96:
	/* 0x1f96: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f99:
	/* 0x1f99: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1f9c:
	/* 0x1f9c: jle    1fc0 <generic_fentry_filter_arg+0x1fc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1fc0;
	}
x86_l_1f9e:
	/* 0x1f9e: cmp    ecx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 23ULL);
x86_l_1fa1:
	/* 0x1fa1: jg     1fea <generic_fentry_filter_arg+0x1fea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1fea;
	}
x86_l_1fa3:
	/* 0x1fa3: lea    eax,[rcx-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_1fa6:
	/* 0x1fa6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1fa9:
	/* 0x1fa9: jb     20d7 <generic_fentry_filter_arg+0x20d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_20d7;
	}
x86_l_1faf:
	/* 0x1faf: lea    eax,[rcx-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_1fb2:
	/* 0x1fb2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1fb5:
	/* 0x1fb5: jb     20cc <generic_fentry_filter_arg+0x20cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_20cc;
	}
x86_l_1fbb:
	/* 0x1fbb: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_1fc0:
	/* 0x1fc0: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_1fc3:
	/* 0x1fc3: jle    200a <generic_fentry_filter_arg+0x200a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_200a;
	}
x86_l_1fc5:
	/* 0x1fc5: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1fc8:
	/* 0x1fc8: jg     20be <generic_fentry_filter_arg+0x20be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_20be;
	}
x86_l_1fce:
	/* 0x1fce: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1fd1:
	/* 0x1fd1: je     20cc <generic_fentry_filter_arg+0x20cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20cc;
	}
x86_l_1fd7:
	/* 0x1fd7: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1fda:
	/* 0x1fda: jne    3835 <generic_fentry_filter_arg+0x3835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14389ULL;
	}
x86_l_1fe0:
	/* 0x1fe0: movzx  r15d,WORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1fe5:
	/* 0x1fe5: jmp    322a <generic_fentry_filter_arg+0x322a> */
	return 12842ULL;
x86_l_1fea:
	/* 0x1fea: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_1fed:
	/* 0x1fed: jg     20ed <generic_fentry_filter_arg+0x20ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_20ed;
	}
x86_l_1ff3:
	/* 0x1ff3: cmp    ecx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_1ff6:
	/* 0x1ff6: je     2d53 <generic_fentry_filter_arg+0x2d53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11603ULL;
	}
x86_l_1ffc:
	/* 0x1ffc: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_1fff:
	/* 0x1fff: je     2d44 <generic_fentry_filter_arg+0x2d44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11588ULL;
	}
x86_l_2005:
	/* 0x2005: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_200a:
	/* 0x200a: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_200d:
	/* 0x200d: je     2d53 <generic_fentry_filter_arg+0x2d53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11603ULL;
	}
x86_l_2013:
	/* 0x2013: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_2016:
	/* 0x2016: je     2d44 <generic_fentry_filter_arg+0x2d44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11588ULL;
	}
x86_l_201c:
	/* 0x201c: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_201f:
	/* 0x201f: je     20d7 <generic_fentry_filter_arg+0x20d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20d7;
	}
x86_l_2025:
	/* 0x2025: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_202a:
	/* 0x202a: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_202d:
	/* 0x202d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2030:
	/* 0x2030: jae    317b <generic_fentry_filter_arg+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12667ULL;
	}
x86_l_2036:
	/* 0x2036: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_203b:
	/* 0x203b: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2043:
	/* 0x2043: cmp    r8d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 144ULL);
x86_l_204a:
	/* 0x204a: ja     3781 <generic_fentry_filter_arg+0x3781> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14209ULL;
	}
x86_l_2050:
	/* 0x2050: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2055:
	/* 0x2055: movzx  eax,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2059:
	/* 0x2059: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_205f:
	/* 0x205f: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2062:
	/* 0x2062: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2065:
	/* 0x2065: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2068:
	/* 0x2068: mov    eax,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_206b:
	/* 0x206b: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_206d:
	/* 0x206d: test   r8w,r8w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_16);
x86_l_2071:
	/* 0x2071: mov    QWORD PTR [rsp+0x18],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2076:
	/* 0x2076: je     32f7 <generic_fentry_filter_arg+0x32f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13047ULL;
	}
x86_l_207c:
	/* 0x207c: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_207e:
	/* 0x207e: jne    32f7 <generic_fentry_filter_arg+0x32f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13047ULL;
	}
x86_l_2084:
	/* 0x2084: mov    edx,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_2087:
	/* 0x2087: jmp    330f <generic_fentry_filter_arg+0x330f> */
	return 13071ULL;
x86_l_208c:
	/* 0x208c: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_208f:
	/* 0x208f: jne    209a <generic_fentry_filter_arg+0x209a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_209a;
	}
x86_l_2091:
	/* 0x2091: test   QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2094:
	/* 0x2094: jne    383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14394ULL;
	}
x86_l_209a:
	/* 0x209a: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_209d:
	/* 0x209d: jb     36a6 <generic_fentry_filter_arg+0x36a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13990ULL;
	}
x86_l_20a3:
	/* 0x20a3: mov    rsi,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20a7:
	/* 0x20a7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_20aa:
	/* 0x20aa: jae    329d <generic_fentry_filter_arg+0x329d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12957ULL;
	}
x86_l_20b0:
	/* 0x20b0: cmp    QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b3:
	/* 0x20b3: jne    32ab <generic_fentry_filter_arg+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12971ULL;
	}
x86_l_20b9:
	/* 0x20b9: jmp    3632 <generic_fentry_filter_arg+0x3632> */
	return 13874ULL;
x86_l_20be:
	/* 0x20be: cmp    ecx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 18ULL);
x86_l_20c1:
	/* 0x20c1: je     20d7 <generic_fentry_filter_arg+0x20d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20d7;
	}
x86_l_20c3:
	/* 0x20c3: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_20c6:
	/* 0x20c6: jne    3835 <generic_fentry_filter_arg+0x3835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14389ULL;
	}
x86_l_20cc:
	/* 0x20cc: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20d1:
	/* 0x20d1: movzx  esi,WORD PTR [rdi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_20d5:
	/* 0x20d5: jmp    20e0 <generic_fentry_filter_arg+0x20e0> */
	goto x86_l_20e0;
x86_l_20d7:
	/* 0x20d7: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20dc:
	/* 0x20dc: movzx  esi,WORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_20e0:
	/* 0x20e0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20e2:
	/* 0x20e2: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20e5:
	/* 0x20e5: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20e8:
	/* 0x20e8: jmp    2d68 <generic_fentry_filter_arg+0x2d68> */
	return 11624ULL;
x86_l_20ed:
	/* 0x20ed: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_20f0:
	/* 0x20f0: je     3225 <generic_fentry_filter_arg+0x3225> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12837ULL;
	}
x86_l_20f6:
	/* 0x20f6: cmp    ecx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 29ULL);
x86_l_20f9:
	/* 0x20f9: jne    3835 <generic_fentry_filter_arg+0x3835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14389ULL;
	}
x86_l_20ff:
	/* 0x20ff: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2102:
	/* 0x2102: jne    341b <generic_fentry_filter_arg+0x341b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13339ULL;
	}
x86_l_2108:
	/* 0x2108: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_210b:
	/* 0x210b: jne    3428 <generic_fentry_filter_arg+0x3428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13352ULL;
	}
x86_l_2111:
	/* 0x2111: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2114:
	/* 0x2114: jmp    3437 <generic_fentry_filter_arg+0x3437> */
	return 13367ULL;
x86_l_2119:
	/* 0x2119: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_211e:
	/* 0x211e: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2123:
	/* 0x2123: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2127:
	/* 0x2127: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_212b:
	/* 0x212b: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2133:
	/* 0x2133: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2138:
	/* 0x2138: mov    rdi,QWORD PTR [rip+0x5d33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_213f:
	/* 0x213f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2144:
	/* 0x2144: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_2147:
	/* 0x2147: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2149:
	/* 0x2149: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_214c:
	/* 0x214c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_214f:
	/* 0x214f: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2152:
	/* 0x2152: je     3784 <generic_fentry_filter_arg+0x3784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14212ULL;
	}
x86_l_2158:
	/* 0x2158: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_215c:
	/* 0x215c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_215f:
	/* 0x215f: je     3784 <generic_fentry_filter_arg+0x3784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14212ULL;
	}
x86_l_2165:
	/* 0x2165: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_216a:
	/* 0x216a: mov    rdi,QWORD PTR [rip+0x5d33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_2171:
	/* 0x2171: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2176:
	/* 0x2176: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2178:
	/* 0x2178: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_217b:
	/* 0x217b: je     3781 <generic_fentry_filter_arg+0x3781> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14209ULL;
	}
x86_l_2181:
	/* 0x2181: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2186:
	/* 0x2186: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_218a:
	/* 0x218a: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_218e:
	/* 0x218e: mov    ecx,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 94ULL);
x86_l_2193:
	/* 0x2193: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_2197:
	/* 0x2197: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_219a:
	/* 0x219a: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_219c:
	/* 0x219c: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_21a0:
	/* 0x21a0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21a6:
	/* 0x21a6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_21aa:
	/* 0x21aa: mov    BYTE PTR [rax+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21ad:
	/* 0x21ad: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_21b1:
	/* 0x21b1: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_21b7:
	/* 0x21b7: lea    ecx,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_21be:
	/* 0x21be: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21c4:
	/* 0x21c4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_21c8:
	/* 0x21c8: mov    BYTE PTR [rax+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_21cb:
	/* 0x21cb: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_21cf:
	/* 0x21cf: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_21d5:
	/* 0x21d5: lea    ecx,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_21dc:
	/* 0x21dc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21e2:
	/* 0x21e2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_21e6:
	/* 0x21e6: mov    BYTE PTR [rax+0x6],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_21e9:
	/* 0x21e9: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_21ed:
	/* 0x21ed: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_21f3:
	/* 0x21f3: lea    ecx,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_21fa:
	/* 0x21fa: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2200:
	/* 0x2200: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2204:
	/* 0x2204: mov    BYTE PTR [rax+0x7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_2207:
	/* 0x2207: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_220b:
	/* 0x220b: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2211:
	/* 0x2211: lea    ecx,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_2218:
	/* 0x2218: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_221e:
	/* 0x221e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2222:
	/* 0x2222: mov    BYTE PTR [rax+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2225:
	/* 0x2225: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_2229:
	/* 0x2229: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_222f:
	/* 0x222f: lea    ecx,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_2236:
	/* 0x2236: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_223c:
	/* 0x223c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2240:
	/* 0x2240: mov    BYTE PTR [rax+0x9],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_2243:
	/* 0x2243: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_2247:
	/* 0x2247: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_224d:
	/* 0x224d: lea    ecx,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_2254:
	/* 0x2254: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_225a:
	/* 0x225a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_225e:
	/* 0x225e: mov    BYTE PTR [rax+0xa],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_2261:
	/* 0x2261: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_2265:
	/* 0x2265: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_226b:
	/* 0x226b: lea    ecx,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_2272:
	/* 0x2272: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2278:
	/* 0x2278: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_227c:
	/* 0x227c: mov    BYTE PTR [rax+0xb],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_227f:
	/* 0x227f: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_2283:
	/* 0x2283: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2289:
	/* 0x2289: lea    ecx,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_2290:
	/* 0x2290: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2296:
	/* 0x2296: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_229a:
	/* 0x229a: mov    BYTE PTR [rax+0xc],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_229d:
	/* 0x229d: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_22a1:
	/* 0x22a1: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_22a7:
	/* 0x22a7: lea    ecx,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_22ae:
	/* 0x22ae: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22b4:
	/* 0x22b4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22b8:
	/* 0x22b8: mov    BYTE PTR [rax+0xd],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_22bb:
	/* 0x22bb: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_22bf:
	/* 0x22bf: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_22c5:
	/* 0x22c5: lea    ecx,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_22cc:
	/* 0x22cc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22d2:
	/* 0x22d2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22d6:
	/* 0x22d6: mov    BYTE PTR [rax+0xe],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
	return 8921ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8921ULL: goto x86_l_22d9;
	case 8925ULL: goto x86_l_22dd;
	case 8931ULL: goto x86_l_22e3;
	case 8938ULL: goto x86_l_22ea;
	case 8944ULL: goto x86_l_22f0;
	case 8948ULL: goto x86_l_22f4;
	case 8951ULL: goto x86_l_22f7;
	case 8955ULL: goto x86_l_22fb;
	case 8961ULL: goto x86_l_2301;
	case 8968ULL: goto x86_l_2308;
	case 8974ULL: goto x86_l_230e;
	case 8978ULL: goto x86_l_2312;
	case 8981ULL: goto x86_l_2315;
	case 8985ULL: goto x86_l_2319;
	case 8991ULL: goto x86_l_231f;
	case 8998ULL: goto x86_l_2326;
	case 9004ULL: goto x86_l_232c;
	case 9008ULL: goto x86_l_2330;
	case 9011ULL: goto x86_l_2333;
	case 9015ULL: goto x86_l_2337;
	case 9021ULL: goto x86_l_233d;
	case 9028ULL: goto x86_l_2344;
	case 9034ULL: goto x86_l_234a;
	case 9038ULL: goto x86_l_234e;
	case 9041ULL: goto x86_l_2351;
	case 9045ULL: goto x86_l_2355;
	case 9051ULL: goto x86_l_235b;
	case 9058ULL: goto x86_l_2362;
	case 9064ULL: goto x86_l_2368;
	case 9068ULL: goto x86_l_236c;
	case 9071ULL: goto x86_l_236f;
	case 9075ULL: goto x86_l_2373;
	case 9081ULL: goto x86_l_2379;
	case 9088ULL: goto x86_l_2380;
	case 9094ULL: goto x86_l_2386;
	case 9098ULL: goto x86_l_238a;
	case 9101ULL: goto x86_l_238d;
	case 9105ULL: goto x86_l_2391;
	case 9111ULL: goto x86_l_2397;
	case 9118ULL: goto x86_l_239e;
	case 9124ULL: goto x86_l_23a4;
	case 9128ULL: goto x86_l_23a8;
	case 9131ULL: goto x86_l_23ab;
	case 9135ULL: goto x86_l_23af;
	case 9141ULL: goto x86_l_23b5;
	case 9148ULL: goto x86_l_23bc;
	case 9154ULL: goto x86_l_23c2;
	case 9158ULL: goto x86_l_23c6;
	case 9161ULL: goto x86_l_23c9;
	case 9165ULL: goto x86_l_23cd;
	case 9171ULL: goto x86_l_23d3;
	case 9178ULL: goto x86_l_23da;
	case 9184ULL: goto x86_l_23e0;
	case 9188ULL: goto x86_l_23e4;
	case 9191ULL: goto x86_l_23e7;
	case 9195ULL: goto x86_l_23eb;
	case 9201ULL: goto x86_l_23f1;
	case 9208ULL: goto x86_l_23f8;
	case 9214ULL: goto x86_l_23fe;
	case 9218ULL: goto x86_l_2402;
	case 9221ULL: goto x86_l_2405;
	case 9225ULL: goto x86_l_2409;
	case 9231ULL: goto x86_l_240f;
	case 9238ULL: goto x86_l_2416;
	case 9244ULL: goto x86_l_241c;
	case 9248ULL: goto x86_l_2420;
	case 9251ULL: goto x86_l_2423;
	case 9255ULL: goto x86_l_2427;
	case 9261ULL: goto x86_l_242d;
	case 9268ULL: goto x86_l_2434;
	case 9274ULL: goto x86_l_243a;
	case 9278ULL: goto x86_l_243e;
	case 9281ULL: goto x86_l_2441;
	case 9285ULL: goto x86_l_2445;
	case 9291ULL: goto x86_l_244b;
	case 9298ULL: goto x86_l_2452;
	case 9304ULL: goto x86_l_2458;
	case 9308ULL: goto x86_l_245c;
	case 9311ULL: goto x86_l_245f;
	case 9315ULL: goto x86_l_2463;
	case 9321ULL: goto x86_l_2469;
	case 9328ULL: goto x86_l_2470;
	case 9334ULL: goto x86_l_2476;
	case 9338ULL: goto x86_l_247a;
	case 9341ULL: goto x86_l_247d;
	case 9345ULL: goto x86_l_2481;
	case 9351ULL: goto x86_l_2487;
	case 9358ULL: goto x86_l_248e;
	case 9364ULL: goto x86_l_2494;
	case 9368ULL: goto x86_l_2498;
	case 9371ULL: goto x86_l_249b;
	case 9375ULL: goto x86_l_249f;
	case 9381ULL: goto x86_l_24a5;
	case 9388ULL: goto x86_l_24ac;
	case 9394ULL: goto x86_l_24b2;
	case 9398ULL: goto x86_l_24b6;
	case 9401ULL: goto x86_l_24b9;
	case 9405ULL: goto x86_l_24bd;
	case 9411ULL: goto x86_l_24c3;
	case 9418ULL: goto x86_l_24ca;
	case 9424ULL: goto x86_l_24d0;
	case 9428ULL: goto x86_l_24d4;
	case 9431ULL: goto x86_l_24d7;
	case 9435ULL: goto x86_l_24db;
	case 9441ULL: goto x86_l_24e1;
	case 9448ULL: goto x86_l_24e8;
	case 9454ULL: goto x86_l_24ee;
	case 9458ULL: goto x86_l_24f2;
	case 9461ULL: goto x86_l_24f5;
	case 9465ULL: goto x86_l_24f9;
	case 9471ULL: goto x86_l_24ff;
	case 9478ULL: goto x86_l_2506;
	case 9484ULL: goto x86_l_250c;
	case 9488ULL: goto x86_l_2510;
	case 9491ULL: goto x86_l_2513;
	case 9495ULL: goto x86_l_2517;
	case 9501ULL: goto x86_l_251d;
	case 9508ULL: goto x86_l_2524;
	case 9514ULL: goto x86_l_252a;
	case 9518ULL: goto x86_l_252e;
	case 9521ULL: goto x86_l_2531;
	case 9525ULL: goto x86_l_2535;
	case 9531ULL: goto x86_l_253b;
	case 9538ULL: goto x86_l_2542;
	case 9544ULL: goto x86_l_2548;
	case 9548ULL: goto x86_l_254c;
	case 9551ULL: goto x86_l_254f;
	case 9555ULL: goto x86_l_2553;
	case 9561ULL: goto x86_l_2559;
	case 9568ULL: goto x86_l_2560;
	case 9574ULL: goto x86_l_2566;
	case 9578ULL: goto x86_l_256a;
	case 9581ULL: goto x86_l_256d;
	case 9585ULL: goto x86_l_2571;
	case 9591ULL: goto x86_l_2577;
	case 9598ULL: goto x86_l_257e;
	case 9604ULL: goto x86_l_2584;
	case 9608ULL: goto x86_l_2588;
	case 9611ULL: goto x86_l_258b;
	case 9615ULL: goto x86_l_258f;
	case 9621ULL: goto x86_l_2595;
	case 9628ULL: goto x86_l_259c;
	case 9634ULL: goto x86_l_25a2;
	case 9638ULL: goto x86_l_25a6;
	case 9641ULL: goto x86_l_25a9;
	case 9645ULL: goto x86_l_25ad;
	case 9651ULL: goto x86_l_25b3;
	case 9658ULL: goto x86_l_25ba;
	case 9664ULL: goto x86_l_25c0;
	case 9668ULL: goto x86_l_25c4;
	case 9671ULL: goto x86_l_25c7;
	case 9675ULL: goto x86_l_25cb;
	case 9681ULL: goto x86_l_25d1;
	case 9688ULL: goto x86_l_25d8;
	case 9694ULL: goto x86_l_25de;
	case 9698ULL: goto x86_l_25e2;
	case 9701ULL: goto x86_l_25e5;
	case 9705ULL: goto x86_l_25e9;
	case 9711ULL: goto x86_l_25ef;
	case 9718ULL: goto x86_l_25f6;
	case 9724ULL: goto x86_l_25fc;
	case 9728ULL: goto x86_l_2600;
	case 9731ULL: goto x86_l_2603;
	case 9735ULL: goto x86_l_2607;
	case 9741ULL: goto x86_l_260d;
	case 9748ULL: goto x86_l_2614;
	case 9754ULL: goto x86_l_261a;
	case 9758ULL: goto x86_l_261e;
	case 9761ULL: goto x86_l_2621;
	case 9765ULL: goto x86_l_2625;
	case 9771ULL: goto x86_l_262b;
	case 9778ULL: goto x86_l_2632;
	case 9784ULL: goto x86_l_2638;
	case 9788ULL: goto x86_l_263c;
	case 9791ULL: goto x86_l_263f;
	case 9795ULL: goto x86_l_2643;
	case 9801ULL: goto x86_l_2649;
	case 9808ULL: goto x86_l_2650;
	case 9814ULL: goto x86_l_2656;
	case 9818ULL: goto x86_l_265a;
	case 9821ULL: goto x86_l_265d;
	case 9825ULL: goto x86_l_2661;
	case 9831ULL: goto x86_l_2667;
	case 9838ULL: goto x86_l_266e;
	case 9844ULL: goto x86_l_2674;
	case 9848ULL: goto x86_l_2678;
	case 9851ULL: goto x86_l_267b;
	case 9855ULL: goto x86_l_267f;
	case 9861ULL: goto x86_l_2685;
	case 9868ULL: goto x86_l_268c;
	case 9874ULL: goto x86_l_2692;
	case 9878ULL: goto x86_l_2696;
	case 9881ULL: goto x86_l_2699;
	case 9885ULL: goto x86_l_269d;
	case 9891ULL: goto x86_l_26a3;
	case 9898ULL: goto x86_l_26aa;
	case 9904ULL: goto x86_l_26b0;
	case 9908ULL: goto x86_l_26b4;
	case 9911ULL: goto x86_l_26b7;
	case 9915ULL: goto x86_l_26bb;
	case 9921ULL: goto x86_l_26c1;
	case 9928ULL: goto x86_l_26c8;
	case 9934ULL: goto x86_l_26ce;
	case 9938ULL: goto x86_l_26d2;
	case 9941ULL: goto x86_l_26d5;
	case 9945ULL: goto x86_l_26d9;
	case 9951ULL: goto x86_l_26df;
	case 9958ULL: goto x86_l_26e6;
	case 9964ULL: goto x86_l_26ec;
	case 9968ULL: goto x86_l_26f0;
	case 9971ULL: goto x86_l_26f3;
	case 9975ULL: goto x86_l_26f7;
	case 9981ULL: goto x86_l_26fd;
	case 9988ULL: goto x86_l_2704;
	case 9994ULL: goto x86_l_270a;
	case 9998ULL: goto x86_l_270e;
	case 10001ULL: goto x86_l_2711;
	case 10005ULL: goto x86_l_2715;
	case 10011ULL: goto x86_l_271b;
	case 10018ULL: goto x86_l_2722;
	case 10024ULL: goto x86_l_2728;
	case 10028ULL: goto x86_l_272c;
	case 10031ULL: goto x86_l_272f;
	case 10035ULL: goto x86_l_2733;
	case 10041ULL: goto x86_l_2739;
	case 10048ULL: goto x86_l_2740;
	case 10054ULL: goto x86_l_2746;
	case 10058ULL: goto x86_l_274a;
	case 10061ULL: goto x86_l_274d;
	case 10065ULL: goto x86_l_2751;
	case 10071ULL: goto x86_l_2757;
	case 10078ULL: goto x86_l_275e;
	case 10084ULL: goto x86_l_2764;
	case 10088ULL: goto x86_l_2768;
	case 10091ULL: goto x86_l_276b;
	case 10095ULL: goto x86_l_276f;
	case 10101ULL: goto x86_l_2775;
	case 10108ULL: goto x86_l_277c;
	case 10114ULL: goto x86_l_2782;
	case 10118ULL: goto x86_l_2786;
	case 10121ULL: goto x86_l_2789;
	case 10125ULL: goto x86_l_278d;
	case 10131ULL: goto x86_l_2793;
	case 10138ULL: goto x86_l_279a;
	case 10144ULL: goto x86_l_27a0;
	case 10148ULL: goto x86_l_27a4;
	case 10151ULL: goto x86_l_27a7;
	case 10155ULL: goto x86_l_27ab;
	case 10161ULL: goto x86_l_27b1;
	case 10168ULL: goto x86_l_27b8;
	case 10174ULL: goto x86_l_27be;
	case 10178ULL: goto x86_l_27c2;
	case 10181ULL: goto x86_l_27c5;
	case 10185ULL: goto x86_l_27c9;
	case 10191ULL: goto x86_l_27cf;
	case 10198ULL: goto x86_l_27d6;
	case 10204ULL: goto x86_l_27dc;
	case 10208ULL: goto x86_l_27e0;
	case 10211ULL: goto x86_l_27e3;
	case 10215ULL: goto x86_l_27e7;
	case 10221ULL: goto x86_l_27ed;
	case 10228ULL: goto x86_l_27f4;
	case 10234ULL: goto x86_l_27fa;
	case 10238ULL: goto x86_l_27fe;
	case 10241ULL: goto x86_l_2801;
	case 10245ULL: goto x86_l_2805;
	case 10251ULL: goto x86_l_280b;
	case 10258ULL: goto x86_l_2812;
	case 10264ULL: goto x86_l_2818;
	case 10268ULL: goto x86_l_281c;
	case 10271ULL: goto x86_l_281f;
	case 10275ULL: goto x86_l_2823;
	case 10281ULL: goto x86_l_2829;
	case 10288ULL: goto x86_l_2830;
	case 10294ULL: goto x86_l_2836;
	case 10298ULL: goto x86_l_283a;
	case 10301ULL: goto x86_l_283d;
	case 10305ULL: goto x86_l_2841;
	case 10311ULL: goto x86_l_2847;
	case 10318ULL: goto x86_l_284e;
	case 10324ULL: goto x86_l_2854;
	case 10328ULL: goto x86_l_2858;
	case 10331ULL: goto x86_l_285b;
	case 10335ULL: goto x86_l_285f;
	case 10341ULL: goto x86_l_2865;
	case 10348ULL: goto x86_l_286c;
	case 10354ULL: goto x86_l_2872;
	case 10358ULL: goto x86_l_2876;
	case 10361ULL: goto x86_l_2879;
	case 10365ULL: goto x86_l_287d;
	case 10371ULL: goto x86_l_2883;
	case 10378ULL: goto x86_l_288a;
	case 10384ULL: goto x86_l_2890;
	case 10388ULL: goto x86_l_2894;
	case 10391ULL: goto x86_l_2897;
	case 10395ULL: goto x86_l_289b;
	case 10401ULL: goto x86_l_28a1;
	case 10408ULL: goto x86_l_28a8;
	case 10414ULL: goto x86_l_28ae;
	case 10418ULL: goto x86_l_28b2;
	case 10421ULL: goto x86_l_28b5;
	case 10425ULL: goto x86_l_28b9;
	case 10431ULL: goto x86_l_28bf;
	case 10438ULL: goto x86_l_28c6;
	case 10444ULL: goto x86_l_28cc;
	case 10448ULL: goto x86_l_28d0;
	case 10451ULL: goto x86_l_28d3;
	case 10455ULL: goto x86_l_28d7;
	case 10461ULL: goto x86_l_28dd;
	case 10468ULL: goto x86_l_28e4;
	case 10474ULL: goto x86_l_28ea;
	case 10478ULL: goto x86_l_28ee;
	case 10481ULL: goto x86_l_28f1;
	case 10485ULL: goto x86_l_28f5;
	case 10491ULL: goto x86_l_28fb;
	case 10498ULL: goto x86_l_2902;
	case 10504ULL: goto x86_l_2908;
	case 10508ULL: goto x86_l_290c;
	case 10511ULL: goto x86_l_290f;
	case 10515ULL: goto x86_l_2913;
	case 10521ULL: goto x86_l_2919;
	case 10528ULL: goto x86_l_2920;
	case 10534ULL: goto x86_l_2926;
	case 10538ULL: goto x86_l_292a;
	case 10541ULL: goto x86_l_292d;
	case 10545ULL: goto x86_l_2931;
	case 10551ULL: goto x86_l_2937;
	case 10558ULL: goto x86_l_293e;
	case 10564ULL: goto x86_l_2944;
	case 10568ULL: goto x86_l_2948;
	case 10571ULL: goto x86_l_294b;
	case 10575ULL: goto x86_l_294f;
	case 10581ULL: goto x86_l_2955;
	case 10588ULL: goto x86_l_295c;
	case 10594ULL: goto x86_l_2962;
	case 10598ULL: goto x86_l_2966;
	case 10601ULL: goto x86_l_2969;
	case 10605ULL: goto x86_l_296d;
	case 10611ULL: goto x86_l_2973;
	case 10618ULL: goto x86_l_297a;
	case 10624ULL: goto x86_l_2980;
	case 10628ULL: goto x86_l_2984;
	case 10631ULL: goto x86_l_2987;
	case 10635ULL: goto x86_l_298b;
	case 10641ULL: goto x86_l_2991;
	case 10648ULL: goto x86_l_2998;
	case 10654ULL: goto x86_l_299e;
	case 10658ULL: goto x86_l_29a2;
	case 10661ULL: goto x86_l_29a5;
	case 10665ULL: goto x86_l_29a9;
	case 10671ULL: goto x86_l_29af;
	case 10678ULL: goto x86_l_29b6;
	case 10684ULL: goto x86_l_29bc;
	case 10688ULL: goto x86_l_29c0;
	case 10691ULL: goto x86_l_29c3;
	case 10695ULL: goto x86_l_29c7;
	case 10701ULL: goto x86_l_29cd;
	case 10708ULL: goto x86_l_29d4;
	case 10714ULL: goto x86_l_29da;
	case 10718ULL: goto x86_l_29de;
	case 10721ULL: goto x86_l_29e1;
	case 10725ULL: goto x86_l_29e5;
	case 10731ULL: goto x86_l_29eb;
	case 10738ULL: goto x86_l_29f2;
	case 10744ULL: goto x86_l_29f8;
	case 10748ULL: goto x86_l_29fc;
	case 10751ULL: goto x86_l_29ff;
	case 10755ULL: goto x86_l_2a03;
	case 10761ULL: goto x86_l_2a09;
	case 10768ULL: goto x86_l_2a10;
	case 10774ULL: goto x86_l_2a16;
	case 10778ULL: goto x86_l_2a1a;
	case 10781ULL: goto x86_l_2a1d;
	case 10785ULL: goto x86_l_2a21;
	case 10791ULL: goto x86_l_2a27;
	case 10798ULL: goto x86_l_2a2e;
	case 10804ULL: goto x86_l_2a34;
	case 10808ULL: goto x86_l_2a38;
	case 10811ULL: goto x86_l_2a3b;
	case 10815ULL: goto x86_l_2a3f;
	case 10821ULL: goto x86_l_2a45;
	case 10828ULL: goto x86_l_2a4c;
	case 10834ULL: goto x86_l_2a52;
	case 10838ULL: goto x86_l_2a56;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22d9:
	/* 0x22d9: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_22dd:
	/* 0x22dd: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_22e3:
	/* 0x22e3: lea    ecx,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_22ea:
	/* 0x22ea: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22f0:
	/* 0x22f0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22f4:
	/* 0x22f4: mov    BYTE PTR [rax+0xf],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_22f7:
	/* 0x22f7: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_22fb:
	/* 0x22fb: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2301:
	/* 0x2301: lea    ecx,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_2308:
	/* 0x2308: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_230e:
	/* 0x230e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2312:
	/* 0x2312: mov    BYTE PTR [rax+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2315:
	/* 0x2315: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_2319:
	/* 0x2319: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_231f:
	/* 0x231f: lea    ecx,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_2326:
	/* 0x2326: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_232c:
	/* 0x232c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2330:
	/* 0x2330: mov    BYTE PTR [rax+0x11],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_2333:
	/* 0x2333: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_2337:
	/* 0x2337: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_233d:
	/* 0x233d: lea    ecx,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_2344:
	/* 0x2344: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_234a:
	/* 0x234a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_234e:
	/* 0x234e: mov    BYTE PTR [rax+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_2351:
	/* 0x2351: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_2355:
	/* 0x2355: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_235b:
	/* 0x235b: lea    ecx,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_2362:
	/* 0x2362: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2368:
	/* 0x2368: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_236c:
	/* 0x236c: mov    BYTE PTR [rax+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_236f:
	/* 0x236f: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_2373:
	/* 0x2373: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2379:
	/* 0x2379: lea    ecx,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_2380:
	/* 0x2380: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2386:
	/* 0x2386: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_238a:
	/* 0x238a: mov    BYTE PTR [rax+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_238d:
	/* 0x238d: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_2391:
	/* 0x2391: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2397:
	/* 0x2397: lea    ecx,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_239e:
	/* 0x239e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23a4:
	/* 0x23a4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_23a8:
	/* 0x23a8: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_23ab:
	/* 0x23ab: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_23af:
	/* 0x23af: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_23b5:
	/* 0x23b5: lea    ecx,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_23bc:
	/* 0x23bc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23c2:
	/* 0x23c2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_23c6:
	/* 0x23c6: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_23c9:
	/* 0x23c9: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_23cd:
	/* 0x23cd: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_23d3:
	/* 0x23d3: lea    ecx,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_23da:
	/* 0x23da: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23e0:
	/* 0x23e0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_23e4:
	/* 0x23e4: mov    BYTE PTR [rax+0x17],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_23e7:
	/* 0x23e7: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_23eb:
	/* 0x23eb: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_23f1:
	/* 0x23f1: lea    ecx,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_23f8:
	/* 0x23f8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23fe:
	/* 0x23fe: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2402:
	/* 0x2402: mov    BYTE PTR [rax+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2405:
	/* 0x2405: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_2409:
	/* 0x2409: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_240f:
	/* 0x240f: lea    ecx,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_2416:
	/* 0x2416: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_241c:
	/* 0x241c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2420:
	/* 0x2420: mov    BYTE PTR [rax+0x19],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_2423:
	/* 0x2423: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_2427:
	/* 0x2427: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_242d:
	/* 0x242d: lea    ecx,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_2434:
	/* 0x2434: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_243a:
	/* 0x243a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_243e:
	/* 0x243e: mov    BYTE PTR [rax+0x1a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_2441:
	/* 0x2441: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_2445:
	/* 0x2445: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_244b:
	/* 0x244b: lea    ecx,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_2452:
	/* 0x2452: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2458:
	/* 0x2458: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_245c:
	/* 0x245c: mov    BYTE PTR [rax+0x1b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_245f:
	/* 0x245f: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_2463:
	/* 0x2463: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2469:
	/* 0x2469: lea    ecx,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_2470:
	/* 0x2470: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2476:
	/* 0x2476: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_247a:
	/* 0x247a: mov    BYTE PTR [rax+0x1c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_247d:
	/* 0x247d: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_2481:
	/* 0x2481: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2487:
	/* 0x2487: lea    ecx,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_248e:
	/* 0x248e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2494:
	/* 0x2494: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2498:
	/* 0x2498: mov    BYTE PTR [rax+0x1d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_249b:
	/* 0x249b: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_249f:
	/* 0x249f: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_24a5:
	/* 0x24a5: lea    ecx,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_24ac:
	/* 0x24ac: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24b2:
	/* 0x24b2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24b6:
	/* 0x24b6: mov    BYTE PTR [rax+0x1e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_24b9:
	/* 0x24b9: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_24bd:
	/* 0x24bd: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_24c3:
	/* 0x24c3: lea    ecx,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_24ca:
	/* 0x24ca: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24d0:
	/* 0x24d0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24d4:
	/* 0x24d4: mov    BYTE PTR [rax+0x1f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_24d7:
	/* 0x24d7: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_24db:
	/* 0x24db: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_24e1:
	/* 0x24e1: lea    ecx,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_24e8:
	/* 0x24e8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24ee:
	/* 0x24ee: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24f2:
	/* 0x24f2: mov    BYTE PTR [rax+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24f5:
	/* 0x24f5: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_24f9:
	/* 0x24f9: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_24ff:
	/* 0x24ff: lea    ecx,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_2506:
	/* 0x2506: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_250c:
	/* 0x250c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2510:
	/* 0x2510: mov    BYTE PTR [rax+0x21],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_2513:
	/* 0x2513: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_2517:
	/* 0x2517: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_251d:
	/* 0x251d: lea    ecx,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_2524:
	/* 0x2524: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_252a:
	/* 0x252a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_252e:
	/* 0x252e: mov    BYTE PTR [rax+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2531:
	/* 0x2531: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_2535:
	/* 0x2535: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_253b:
	/* 0x253b: lea    ecx,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_2542:
	/* 0x2542: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2548:
	/* 0x2548: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_254c:
	/* 0x254c: mov    BYTE PTR [rax+0x23],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_254f:
	/* 0x254f: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_2553:
	/* 0x2553: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2559:
	/* 0x2559: lea    ecx,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_2560:
	/* 0x2560: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2566:
	/* 0x2566: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_256a:
	/* 0x256a: mov    BYTE PTR [rax+0x24],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_256d:
	/* 0x256d: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_2571:
	/* 0x2571: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2577:
	/* 0x2577: lea    ecx,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_257e:
	/* 0x257e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2584:
	/* 0x2584: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2588:
	/* 0x2588: mov    BYTE PTR [rax+0x25],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_258b:
	/* 0x258b: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_258f:
	/* 0x258f: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2595:
	/* 0x2595: lea    ecx,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_259c:
	/* 0x259c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25a2:
	/* 0x25a2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_25a6:
	/* 0x25a6: mov    BYTE PTR [rax+0x26],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_25a9:
	/* 0x25a9: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_25ad:
	/* 0x25ad: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_25b3:
	/* 0x25b3: lea    ecx,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_25ba:
	/* 0x25ba: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25c0:
	/* 0x25c0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_25c4:
	/* 0x25c4: mov    BYTE PTR [rax+0x27],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_25c7:
	/* 0x25c7: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_25cb:
	/* 0x25cb: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_25d1:
	/* 0x25d1: lea    ecx,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_25d8:
	/* 0x25d8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25de:
	/* 0x25de: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_25e2:
	/* 0x25e2: mov    BYTE PTR [rax+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25e5:
	/* 0x25e5: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_25e9:
	/* 0x25e9: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_25ef:
	/* 0x25ef: lea    ecx,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_25f6:
	/* 0x25f6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25fc:
	/* 0x25fc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2600:
	/* 0x2600: mov    BYTE PTR [rax+0x29],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_2603:
	/* 0x2603: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_2607:
	/* 0x2607: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_260d:
	/* 0x260d: lea    ecx,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_2614:
	/* 0x2614: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_261a:
	/* 0x261a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_261e:
	/* 0x261e: mov    BYTE PTR [rax+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2621:
	/* 0x2621: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_2625:
	/* 0x2625: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_262b:
	/* 0x262b: lea    ecx,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_2632:
	/* 0x2632: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2638:
	/* 0x2638: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_263c:
	/* 0x263c: mov    BYTE PTR [rax+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_263f:
	/* 0x263f: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_2643:
	/* 0x2643: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2649:
	/* 0x2649: lea    ecx,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_2650:
	/* 0x2650: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2656:
	/* 0x2656: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_265a:
	/* 0x265a: mov    BYTE PTR [rax+0x2c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_265d:
	/* 0x265d: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_2661:
	/* 0x2661: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2667:
	/* 0x2667: lea    ecx,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_266e:
	/* 0x266e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2674:
	/* 0x2674: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2678:
	/* 0x2678: mov    BYTE PTR [rax+0x2d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_267b:
	/* 0x267b: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_267f:
	/* 0x267f: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2685:
	/* 0x2685: lea    ecx,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_268c:
	/* 0x268c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2692:
	/* 0x2692: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2696:
	/* 0x2696: mov    BYTE PTR [rax+0x2e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_2699:
	/* 0x2699: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_269d:
	/* 0x269d: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_26a3:
	/* 0x26a3: lea    ecx,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_26aa:
	/* 0x26aa: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26b0:
	/* 0x26b0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_26b4:
	/* 0x26b4: mov    BYTE PTR [rax+0x2f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_26b7:
	/* 0x26b7: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_26bb:
	/* 0x26bb: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_26c1:
	/* 0x26c1: lea    ecx,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_26c8:
	/* 0x26c8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26ce:
	/* 0x26ce: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_26d2:
	/* 0x26d2: mov    BYTE PTR [rax+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26d5:
	/* 0x26d5: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_26d9:
	/* 0x26d9: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_26df:
	/* 0x26df: lea    ecx,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_26e6:
	/* 0x26e6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26ec:
	/* 0x26ec: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_26f0:
	/* 0x26f0: mov    BYTE PTR [rax+0x31],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_26f3:
	/* 0x26f3: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_26f7:
	/* 0x26f7: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_26fd:
	/* 0x26fd: lea    ecx,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_2704:
	/* 0x2704: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_270a:
	/* 0x270a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_270e:
	/* 0x270e: mov    BYTE PTR [rax+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_2711:
	/* 0x2711: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_2715:
	/* 0x2715: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_271b:
	/* 0x271b: lea    ecx,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_2722:
	/* 0x2722: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2728:
	/* 0x2728: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_272c:
	/* 0x272c: mov    BYTE PTR [rax+0x33],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_272f:
	/* 0x272f: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_2733:
	/* 0x2733: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2739:
	/* 0x2739: lea    ecx,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_2740:
	/* 0x2740: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2746:
	/* 0x2746: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_274a:
	/* 0x274a: mov    BYTE PTR [rax+0x34],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_274d:
	/* 0x274d: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_2751:
	/* 0x2751: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2757:
	/* 0x2757: lea    ecx,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_275e:
	/* 0x275e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2764:
	/* 0x2764: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2768:
	/* 0x2768: mov    BYTE PTR [rax+0x35],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_276b:
	/* 0x276b: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_276f:
	/* 0x276f: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2775:
	/* 0x2775: lea    ecx,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_277c:
	/* 0x277c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2782:
	/* 0x2782: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2786:
	/* 0x2786: mov    BYTE PTR [rax+0x36],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2789:
	/* 0x2789: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_278d:
	/* 0x278d: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2793:
	/* 0x2793: lea    ecx,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_279a:
	/* 0x279a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27a0:
	/* 0x27a0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_27a4:
	/* 0x27a4: mov    BYTE PTR [rax+0x37],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_27a7:
	/* 0x27a7: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_27ab:
	/* 0x27ab: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_27b1:
	/* 0x27b1: lea    ecx,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_27b8:
	/* 0x27b8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27be:
	/* 0x27be: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_27c2:
	/* 0x27c2: mov    BYTE PTR [rax+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27c5:
	/* 0x27c5: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_27c9:
	/* 0x27c9: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_27cf:
	/* 0x27cf: lea    ecx,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_27d6:
	/* 0x27d6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27dc:
	/* 0x27dc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_27e0:
	/* 0x27e0: mov    BYTE PTR [rax+0x39],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_27e3:
	/* 0x27e3: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_27e7:
	/* 0x27e7: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_27ed:
	/* 0x27ed: lea    ecx,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_27f4:
	/* 0x27f4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27fa:
	/* 0x27fa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_27fe:
	/* 0x27fe: mov    BYTE PTR [rax+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_2801:
	/* 0x2801: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_2805:
	/* 0x2805: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_280b:
	/* 0x280b: lea    ecx,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_2812:
	/* 0x2812: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2818:
	/* 0x2818: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_281c:
	/* 0x281c: mov    BYTE PTR [rax+0x3b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_281f:
	/* 0x281f: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_2823:
	/* 0x2823: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2829:
	/* 0x2829: lea    ecx,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_2830:
	/* 0x2830: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2836:
	/* 0x2836: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_283a:
	/* 0x283a: mov    BYTE PTR [rax+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_283d:
	/* 0x283d: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_2841:
	/* 0x2841: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2847:
	/* 0x2847: lea    ecx,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_284e:
	/* 0x284e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2854:
	/* 0x2854: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2858:
	/* 0x2858: mov    BYTE PTR [rax+0x3d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_285b:
	/* 0x285b: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_285f:
	/* 0x285f: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2865:
	/* 0x2865: lea    ecx,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_286c:
	/* 0x286c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2872:
	/* 0x2872: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2876:
	/* 0x2876: mov    BYTE PTR [rax+0x3e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_2879:
	/* 0x2879: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_287d:
	/* 0x287d: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2883:
	/* 0x2883: lea    ecx,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_288a:
	/* 0x288a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2890:
	/* 0x2890: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2894:
	/* 0x2894: mov    BYTE PTR [rax+0x3f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_2897:
	/* 0x2897: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_289b:
	/* 0x289b: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_28a1:
	/* 0x28a1: lea    ecx,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_28a8:
	/* 0x28a8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28ae:
	/* 0x28ae: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_28b2:
	/* 0x28b2: mov    BYTE PTR [rax+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28b5:
	/* 0x28b5: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_28b9:
	/* 0x28b9: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_28bf:
	/* 0x28bf: lea    ecx,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_28c6:
	/* 0x28c6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28cc:
	/* 0x28cc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_28d0:
	/* 0x28d0: mov    BYTE PTR [rax+0x41],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_28d3:
	/* 0x28d3: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_28d7:
	/* 0x28d7: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_28dd:
	/* 0x28dd: lea    ecx,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_28e4:
	/* 0x28e4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28ea:
	/* 0x28ea: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_28ee:
	/* 0x28ee: mov    BYTE PTR [rax+0x42],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_28f1:
	/* 0x28f1: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_28f5:
	/* 0x28f5: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_28fb:
	/* 0x28fb: lea    ecx,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_2902:
	/* 0x2902: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2908:
	/* 0x2908: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_290c:
	/* 0x290c: mov    BYTE PTR [rax+0x43],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_290f:
	/* 0x290f: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_2913:
	/* 0x2913: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2919:
	/* 0x2919: lea    ecx,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_2920:
	/* 0x2920: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2926:
	/* 0x2926: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_292a:
	/* 0x292a: mov    BYTE PTR [rax+0x44],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_292d:
	/* 0x292d: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_2931:
	/* 0x2931: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2937:
	/* 0x2937: lea    ecx,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_293e:
	/* 0x293e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2944:
	/* 0x2944: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2948:
	/* 0x2948: mov    BYTE PTR [rax+0x45],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_294b:
	/* 0x294b: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_294f:
	/* 0x294f: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2955:
	/* 0x2955: lea    ecx,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_295c:
	/* 0x295c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2962:
	/* 0x2962: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2966:
	/* 0x2966: mov    BYTE PTR [rax+0x46],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_2969:
	/* 0x2969: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_296d:
	/* 0x296d: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2973:
	/* 0x2973: lea    ecx,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_297a:
	/* 0x297a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2980:
	/* 0x2980: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2984:
	/* 0x2984: mov    BYTE PTR [rax+0x47],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_2987:
	/* 0x2987: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_298b:
	/* 0x298b: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2991:
	/* 0x2991: lea    ecx,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_2998:
	/* 0x2998: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_299e:
	/* 0x299e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_29a2:
	/* 0x29a2: mov    BYTE PTR [rax+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29a5:
	/* 0x29a5: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_29a9:
	/* 0x29a9: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_29af:
	/* 0x29af: lea    ecx,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_29b6:
	/* 0x29b6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29bc:
	/* 0x29bc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_29c0:
	/* 0x29c0: mov    BYTE PTR [rax+0x49],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_29c3:
	/* 0x29c3: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_29c7:
	/* 0x29c7: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_29cd:
	/* 0x29cd: lea    ecx,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_29d4:
	/* 0x29d4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29da:
	/* 0x29da: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_29de:
	/* 0x29de: mov    BYTE PTR [rax+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_29e1:
	/* 0x29e1: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_29e5:
	/* 0x29e5: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_29eb:
	/* 0x29eb: lea    ecx,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_29f2:
	/* 0x29f2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29f8:
	/* 0x29f8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_29fc:
	/* 0x29fc: mov    BYTE PTR [rax+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_29ff:
	/* 0x29ff: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_2a03:
	/* 0x2a03: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2a09:
	/* 0x2a09: lea    ecx,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_2a10:
	/* 0x2a10: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a16:
	/* 0x2a16: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a1a:
	/* 0x2a1a: mov    BYTE PTR [rax+0x4c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2a1d:
	/* 0x2a1d: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_2a21:
	/* 0x2a21: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2a27:
	/* 0x2a27: lea    ecx,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_2a2e:
	/* 0x2a2e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a34:
	/* 0x2a34: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a38:
	/* 0x2a38: mov    BYTE PTR [rax+0x4d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_2a3b:
	/* 0x2a3b: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_2a3f:
	/* 0x2a3f: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11397ULL;
	}
x86_l_2a45:
	/* 0x2a45: lea    ecx,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_2a4c:
	/* 0x2a4c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a52:
	/* 0x2a52: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a56:
	/* 0x2a56: mov    BYTE PTR [rax+0x4e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
	return 10841ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10841ULL: goto x86_l_2a59;
	case 10845ULL: goto x86_l_2a5d;
	case 10851ULL: goto x86_l_2a63;
	case 10858ULL: goto x86_l_2a6a;
	case 10864ULL: goto x86_l_2a70;
	case 10868ULL: goto x86_l_2a74;
	case 10871ULL: goto x86_l_2a77;
	case 10875ULL: goto x86_l_2a7b;
	case 10881ULL: goto x86_l_2a81;
	case 10888ULL: goto x86_l_2a88;
	case 10894ULL: goto x86_l_2a8e;
	case 10898ULL: goto x86_l_2a92;
	case 10901ULL: goto x86_l_2a95;
	case 10905ULL: goto x86_l_2a99;
	case 10911ULL: goto x86_l_2a9f;
	case 10918ULL: goto x86_l_2aa6;
	case 10924ULL: goto x86_l_2aac;
	case 10928ULL: goto x86_l_2ab0;
	case 10931ULL: goto x86_l_2ab3;
	case 10935ULL: goto x86_l_2ab7;
	case 10941ULL: goto x86_l_2abd;
	case 10948ULL: goto x86_l_2ac4;
	case 10954ULL: goto x86_l_2aca;
	case 10958ULL: goto x86_l_2ace;
	case 10961ULL: goto x86_l_2ad1;
	case 10965ULL: goto x86_l_2ad5;
	case 10971ULL: goto x86_l_2adb;
	case 10978ULL: goto x86_l_2ae2;
	case 10984ULL: goto x86_l_2ae8;
	case 10988ULL: goto x86_l_2aec;
	case 10991ULL: goto x86_l_2aef;
	case 10995ULL: goto x86_l_2af3;
	case 11001ULL: goto x86_l_2af9;
	case 11008ULL: goto x86_l_2b00;
	case 11014ULL: goto x86_l_2b06;
	case 11018ULL: goto x86_l_2b0a;
	case 11021ULL: goto x86_l_2b0d;
	case 11025ULL: goto x86_l_2b11;
	case 11031ULL: goto x86_l_2b17;
	case 11038ULL: goto x86_l_2b1e;
	case 11044ULL: goto x86_l_2b24;
	case 11048ULL: goto x86_l_2b28;
	case 11051ULL: goto x86_l_2b2b;
	case 11055ULL: goto x86_l_2b2f;
	case 11061ULL: goto x86_l_2b35;
	case 11068ULL: goto x86_l_2b3c;
	case 11074ULL: goto x86_l_2b42;
	case 11078ULL: goto x86_l_2b46;
	case 11081ULL: goto x86_l_2b49;
	case 11085ULL: goto x86_l_2b4d;
	case 11091ULL: goto x86_l_2b53;
	case 11098ULL: goto x86_l_2b5a;
	case 11104ULL: goto x86_l_2b60;
	case 11108ULL: goto x86_l_2b64;
	case 11111ULL: goto x86_l_2b67;
	case 11115ULL: goto x86_l_2b6b;
	case 11121ULL: goto x86_l_2b71;
	case 11128ULL: goto x86_l_2b78;
	case 11134ULL: goto x86_l_2b7e;
	case 11138ULL: goto x86_l_2b82;
	case 11141ULL: goto x86_l_2b85;
	case 11145ULL: goto x86_l_2b89;
	case 11151ULL: goto x86_l_2b8f;
	case 11158ULL: goto x86_l_2b96;
	case 11164ULL: goto x86_l_2b9c;
	case 11168ULL: goto x86_l_2ba0;
	case 11171ULL: goto x86_l_2ba3;
	case 11175ULL: goto x86_l_2ba7;
	case 11181ULL: goto x86_l_2bad;
	case 11188ULL: goto x86_l_2bb4;
	case 11194ULL: goto x86_l_2bba;
	case 11198ULL: goto x86_l_2bbe;
	case 11201ULL: goto x86_l_2bc1;
	case 11205ULL: goto x86_l_2bc5;
	case 11211ULL: goto x86_l_2bcb;
	case 11218ULL: goto x86_l_2bd2;
	case 11224ULL: goto x86_l_2bd8;
	case 11228ULL: goto x86_l_2bdc;
	case 11231ULL: goto x86_l_2bdf;
	case 11235ULL: goto x86_l_2be3;
	case 11241ULL: goto x86_l_2be9;
	case 11248ULL: goto x86_l_2bf0;
	case 11254ULL: goto x86_l_2bf6;
	case 11258ULL: goto x86_l_2bfa;
	case 11261ULL: goto x86_l_2bfd;
	case 11265ULL: goto x86_l_2c01;
	case 11271ULL: goto x86_l_2c07;
	case 11278ULL: goto x86_l_2c0e;
	case 11284ULL: goto x86_l_2c14;
	case 11288ULL: goto x86_l_2c18;
	case 11291ULL: goto x86_l_2c1b;
	case 11295ULL: goto x86_l_2c1f;
	case 11297ULL: goto x86_l_2c21;
	case 11304ULL: goto x86_l_2c28;
	case 11310ULL: goto x86_l_2c2e;
	case 11314ULL: goto x86_l_2c32;
	case 11317ULL: goto x86_l_2c35;
	case 11321ULL: goto x86_l_2c39;
	case 11323ULL: goto x86_l_2c3b;
	case 11330ULL: goto x86_l_2c42;
	case 11336ULL: goto x86_l_2c48;
	case 11340ULL: goto x86_l_2c4c;
	case 11343ULL: goto x86_l_2c4f;
	case 11347ULL: goto x86_l_2c53;
	case 11349ULL: goto x86_l_2c55;
	case 11356ULL: goto x86_l_2c5c;
	case 11362ULL: goto x86_l_2c62;
	case 11366ULL: goto x86_l_2c66;
	case 11369ULL: goto x86_l_2c69;
	case 11373ULL: goto x86_l_2c6d;
	case 11375ULL: goto x86_l_2c6f;
	case 11382ULL: goto x86_l_2c76;
	case 11389ULL: goto x86_l_2c7d;
	case 11394ULL: goto x86_l_2c82;
	case 11397ULL: goto x86_l_2c85;
	case 11402ULL: goto x86_l_2c8a;
	case 11406ULL: goto x86_l_2c8e;
	case 11409ULL: goto x86_l_2c91;
	case 11414ULL: goto x86_l_2c96;
	case 11419ULL: goto x86_l_2c9b;
	case 11424ULL: goto x86_l_2ca0;
	case 11428ULL: goto x86_l_2ca4;
	case 11432ULL: goto x86_l_2ca8;
	case 11440ULL: goto x86_l_2cb0;
	case 11445ULL: goto x86_l_2cb5;
	case 11452ULL: goto x86_l_2cbc;
	case 11457ULL: goto x86_l_2cc1;
	case 11460ULL: goto x86_l_2cc4;
	case 11462ULL: goto x86_l_2cc6;
	case 11465ULL: goto x86_l_2cc9;
	case 11468ULL: goto x86_l_2ccc;
	case 11471ULL: goto x86_l_2ccf;
	case 11477ULL: goto x86_l_2cd5;
	case 11481ULL: goto x86_l_2cd9;
	case 11484ULL: goto x86_l_2cdc;
	case 11490ULL: goto x86_l_2ce2;
	case 11495ULL: goto x86_l_2ce7;
	case 11502ULL: goto x86_l_2cee;
	case 11507ULL: goto x86_l_2cf3;
	case 11509ULL: goto x86_l_2cf5;
	case 11512ULL: goto x86_l_2cf8;
	case 11518ULL: goto x86_l_2cfe;
	case 11523ULL: goto x86_l_2d03;
	case 11527ULL: goto x86_l_2d07;
	case 11534ULL: goto x86_l_2d0e;
	case 11539ULL: goto x86_l_2d13;
	case 11543ULL: goto x86_l_2d17;
	case 11550ULL: goto x86_l_2d1e;
	case 11552ULL: goto x86_l_2d20;
	case 11555ULL: goto x86_l_2d23;
	case 11559ULL: goto x86_l_2d27;
	case 11564ULL: goto x86_l_2d2c;
	case 11567ULL: goto x86_l_2d2f;
	case 11569ULL: goto x86_l_2d31;
	case 11574ULL: goto x86_l_2d36;
	case 11578ULL: goto x86_l_2d3a;
	case 11581ULL: goto x86_l_2d3d;
	case 11583ULL: goto x86_l_2d3f;
	case 11588ULL: goto x86_l_2d44;
	case 11593ULL: goto x86_l_2d49;
	case 11597ULL: goto x86_l_2d4d;
	case 11601ULL: goto x86_l_2d51;
	case 11603ULL: goto x86_l_2d53;
	case 11608ULL: goto x86_l_2d58;
	case 11611ULL: goto x86_l_2d5b;
	case 11615ULL: goto x86_l_2d5f;
	case 11618ULL: goto x86_l_2d62;
	case 11622ULL: goto x86_l_2d66;
	case 11624ULL: goto x86_l_2d68;
	case 11627ULL: goto x86_l_2d6b;
	case 11630ULL: goto x86_l_2d6e;
	case 11632ULL: goto x86_l_2d70;
	case 11635ULL: goto x86_l_2d73;
	case 11638ULL: goto x86_l_2d76;
	case 11640ULL: goto x86_l_2d78;
	case 11643ULL: goto x86_l_2d7b;
	case 11646ULL: goto x86_l_2d7e;
	case 11651ULL: goto x86_l_2d83;
	case 11657ULL: goto x86_l_2d89;
	case 11660ULL: goto x86_l_2d8c;
	case 11666ULL: goto x86_l_2d92;
	case 11671ULL: goto x86_l_2d97;
	case 11674ULL: goto x86_l_2d9a;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11688ULL: goto x86_l_2da8;
	case 11694ULL: goto x86_l_2dae;
	case 11699ULL: goto x86_l_2db3;
	case 11702ULL: goto x86_l_2db6;
	case 11708ULL: goto x86_l_2dbc;
	case 11713ULL: goto x86_l_2dc1;
	case 11716ULL: goto x86_l_2dc4;
	case 11722ULL: goto x86_l_2dca;
	case 11726ULL: goto x86_l_2dce;
	case 11729ULL: goto x86_l_2dd1;
	case 11735ULL: goto x86_l_2dd7;
	case 11738ULL: goto x86_l_2dda;
	case 11744ULL: goto x86_l_2de0;
	case 11747ULL: goto x86_l_2de3;
	case 11752ULL: goto x86_l_2de8;
	case 11756ULL: goto x86_l_2dec;
	case 11760ULL: goto x86_l_2df0;
	case 11765ULL: goto x86_l_2df5;
	case 11772ULL: goto x86_l_2dfc;
	case 11777ULL: goto x86_l_2e01;
	case 11779ULL: goto x86_l_2e03;
	case 11782ULL: goto x86_l_2e06;
	case 11788ULL: goto x86_l_2e0c;
	case 11796ULL: goto x86_l_2e14;
	case 11801ULL: goto x86_l_2e19;
	case 11806ULL: goto x86_l_2e1e;
	case 11810ULL: goto x86_l_2e22;
	case 11814ULL: goto x86_l_2e26;
	case 11822ULL: goto x86_l_2e2e;
	case 11827ULL: goto x86_l_2e33;
	case 11834ULL: goto x86_l_2e3a;
	case 11839ULL: goto x86_l_2e3f;
	case 11841ULL: goto x86_l_2e41;
	case 11844ULL: goto x86_l_2e44;
	case 11849ULL: goto x86_l_2e49;
	case 11855ULL: goto x86_l_2e4f;
	case 11860ULL: goto x86_l_2e54;
	case 11863ULL: goto x86_l_2e57;
	case 11869ULL: goto x86_l_2e5d;
	case 11874ULL: goto x86_l_2e62;
	case 11879ULL: goto x86_l_2e67;
	case 11886ULL: goto x86_l_2e6e;
	case 11891ULL: goto x86_l_2e73;
	case 11893ULL: goto x86_l_2e75;
	case 11896ULL: goto x86_l_2e78;
	case 11902ULL: goto x86_l_2e7e;
	case 11905ULL: goto x86_l_2e81;
	case 11909ULL: goto x86_l_2e85;
	case 11914ULL: goto x86_l_2e8a;
	case 11919ULL: goto x86_l_2e8f;
	case 11922ULL: goto x86_l_2e92;
	case 11929ULL: goto x86_l_2e99;
	case 11933ULL: goto x86_l_2e9d;
	case 11936ULL: goto x86_l_2ea0;
	case 11940ULL: goto x86_l_2ea4;
	case 11945ULL: goto x86_l_2ea9;
	case 11950ULL: goto x86_l_2eae;
	case 11952ULL: goto x86_l_2eb0;
	case 11957ULL: goto x86_l_2eb5;
	case 11962ULL: goto x86_l_2eba;
	case 11965ULL: goto x86_l_2ebd;
	case 11967ULL: goto x86_l_2ebf;
	case 11972ULL: goto x86_l_2ec4;
	case 11977ULL: goto x86_l_2ec9;
	case 11985ULL: goto x86_l_2ed1;
	case 11991ULL: goto x86_l_2ed7;
	case 11997ULL: goto x86_l_2edd;
	case 12002ULL: goto x86_l_2ee2;
	case 12005ULL: goto x86_l_2ee5;
	case 12011ULL: goto x86_l_2eeb;
	case 12014ULL: goto x86_l_2eee;
	case 12017ULL: goto x86_l_2ef1;
	case 12020ULL: goto x86_l_2ef4;
	case 12022ULL: goto x86_l_2ef6;
	case 12024ULL: goto x86_l_2ef8;
	case 12027ULL: goto x86_l_2efb;
	case 12033ULL: goto x86_l_2f01;
	case 12035ULL: goto x86_l_2f03;
	case 12041ULL: goto x86_l_2f09;
	case 12046ULL: goto x86_l_2f0e;
	case 12049ULL: goto x86_l_2f11;
	case 12051ULL: goto x86_l_2f13;
	case 12053ULL: goto x86_l_2f15;
	case 12059ULL: goto x86_l_2f1b;
	case 12062ULL: goto x86_l_2f1e;
	case 12068ULL: goto x86_l_2f24;
	case 12072ULL: goto x86_l_2f28;
	case 12075ULL: goto x86_l_2f2b;
	case 12081ULL: goto x86_l_2f31;
	case 12083ULL: goto x86_l_2f33;
	case 12089ULL: goto x86_l_2f39;
	case 12094ULL: goto x86_l_2f3e;
	case 12097ULL: goto x86_l_2f41;
	case 12100ULL: goto x86_l_2f44;
	case 12105ULL: goto x86_l_2f49;
	case 12111ULL: goto x86_l_2f4f;
	case 12114ULL: goto x86_l_2f52;
	case 12119ULL: goto x86_l_2f57;
	case 12123ULL: goto x86_l_2f5b;
	case 12128ULL: goto x86_l_2f60;
	case 12135ULL: goto x86_l_2f67;
	case 12140ULL: goto x86_l_2f6c;
	case 12142ULL: goto x86_l_2f6e;
	case 12145ULL: goto x86_l_2f71;
	case 12151ULL: goto x86_l_2f77;
	case 12155ULL: goto x86_l_2f7b;
	case 12160ULL: goto x86_l_2f80;
	case 12165ULL: goto x86_l_2f85;
	case 12170ULL: goto x86_l_2f8a;
	case 12173ULL: goto x86_l_2f8d;
	case 12176ULL: goto x86_l_2f90;
	case 12180ULL: goto x86_l_2f94;
	case 12185ULL: goto x86_l_2f99;
	case 12188ULL: goto x86_l_2f9c;
	case 12191ULL: goto x86_l_2f9f;
	case 12196ULL: goto x86_l_2fa4;
	case 12200ULL: goto x86_l_2fa8;
	case 12205ULL: goto x86_l_2fad;
	case 12208ULL: goto x86_l_2fb0;
	case 12211ULL: goto x86_l_2fb3;
	case 12216ULL: goto x86_l_2fb8;
	case 12220ULL: goto x86_l_2fbc;
	case 12225ULL: goto x86_l_2fc1;
	case 12230ULL: goto x86_l_2fc6;
	case 12233ULL: goto x86_l_2fc9;
	case 12238ULL: goto x86_l_2fce;
	case 12241ULL: goto x86_l_2fd1;
	case 12245ULL: goto x86_l_2fd5;
	case 12250ULL: goto x86_l_2fda;
	case 12257ULL: goto x86_l_2fe1;
	case 12262ULL: goto x86_l_2fe6;
	case 12264ULL: goto x86_l_2fe8;
	case 12267ULL: goto x86_l_2feb;
	case 12273ULL: goto x86_l_2ff1;
	case 12281ULL: goto x86_l_2ff9;
	case 12286ULL: goto x86_l_2ffe;
	case 12291ULL: goto x86_l_3003;
	case 12296ULL: goto x86_l_3008;
	case 12300ULL: goto x86_l_300c;
	case 12304ULL: goto x86_l_3010;
	case 12308ULL: goto x86_l_3014;
	case 12313ULL: goto x86_l_3019;
	case 12318ULL: goto x86_l_301e;
	case 12321ULL: goto x86_l_3021;
	case 12323ULL: goto x86_l_3023;
	case 12328ULL: goto x86_l_3028;
	case 12331ULL: goto x86_l_302b;
	case 12334ULL: goto x86_l_302e;
	case 12337ULL: goto x86_l_3031;
	case 12343ULL: goto x86_l_3037;
	case 12346ULL: goto x86_l_303a;
	case 12349ULL: goto x86_l_303d;
	case 12351ULL: goto x86_l_303f;
	case 12354ULL: goto x86_l_3042;
	case 12357ULL: goto x86_l_3045;
	case 12361ULL: goto x86_l_3049;
	case 12366ULL: goto x86_l_304e;
	case 12368ULL: goto x86_l_3050;
	case 12372ULL: goto x86_l_3054;
	case 12377ULL: goto x86_l_3059;
	case 12380ULL: goto x86_l_305c;
	case 12382ULL: goto x86_l_305e;
	case 12384ULL: goto x86_l_3060;
	case 12386ULL: goto x86_l_3062;
	case 12389ULL: goto x86_l_3065;
	case 12394ULL: goto x86_l_306a;
	case 12398ULL: goto x86_l_306e;
	case 12400ULL: goto x86_l_3070;
	case 12403ULL: goto x86_l_3073;
	case 12409ULL: goto x86_l_3079;
	case 12412ULL: goto x86_l_307c;
	case 12414ULL: goto x86_l_307e;
	case 12418ULL: goto x86_l_3082;
	case 12423ULL: goto x86_l_3087;
	case 12427ULL: goto x86_l_308b;
	case 12430ULL: goto x86_l_308e;
	case 12435ULL: goto x86_l_3093;
	case 12439ULL: goto x86_l_3097;
	case 12443ULL: goto x86_l_309b;
	case 12446ULL: goto x86_l_309e;
	case 12452ULL: goto x86_l_30a4;
	case 12457ULL: goto x86_l_30a9;
	case 12464ULL: goto x86_l_30b0;
	case 12469ULL: goto x86_l_30b5;
	case 12472ULL: goto x86_l_30b8;
	case 12474ULL: goto x86_l_30ba;
	case 12477ULL: goto x86_l_30bd;
	case 12482ULL: goto x86_l_30c2;
	case 12489ULL: goto x86_l_30c9;
	case 12492ULL: goto x86_l_30cc;
	case 12494ULL: goto x86_l_30ce;
	case 12497ULL: goto x86_l_30d1;
	case 12502ULL: goto x86_l_30d6;
	case 12505ULL: goto x86_l_30d9;
	case 12511ULL: goto x86_l_30df;
	case 12514ULL: goto x86_l_30e2;
	case 12520ULL: goto x86_l_30e8;
	case 12523ULL: goto x86_l_30eb;
	case 12527ULL: goto x86_l_30ef;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a59:
	/* 0x2a59: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_2a5d:
	/* 0x2a5d: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2a63:
	/* 0x2a63: lea    ecx,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_2a6a:
	/* 0x2a6a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a70:
	/* 0x2a70: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a74:
	/* 0x2a74: mov    BYTE PTR [rax+0x4f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_2a77:
	/* 0x2a77: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_2a7b:
	/* 0x2a7b: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2a81:
	/* 0x2a81: lea    ecx,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_2a88:
	/* 0x2a88: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a8e:
	/* 0x2a8e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a92:
	/* 0x2a92: mov    BYTE PTR [rax+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a95:
	/* 0x2a95: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_2a99:
	/* 0x2a99: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2a9f:
	/* 0x2a9f: lea    ecx,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_2aa6:
	/* 0x2aa6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2aac:
	/* 0x2aac: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2ab0:
	/* 0x2ab0: mov    BYTE PTR [rax+0x51],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_2ab3:
	/* 0x2ab3: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_2ab7:
	/* 0x2ab7: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2abd:
	/* 0x2abd: lea    ecx,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_2ac4:
	/* 0x2ac4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2aca:
	/* 0x2aca: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2ace:
	/* 0x2ace: mov    BYTE PTR [rax+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_2ad1:
	/* 0x2ad1: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_2ad5:
	/* 0x2ad5: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2adb:
	/* 0x2adb: lea    ecx,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_2ae2:
	/* 0x2ae2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ae8:
	/* 0x2ae8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2aec:
	/* 0x2aec: mov    BYTE PTR [rax+0x53],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_2aef:
	/* 0x2aef: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_2af3:
	/* 0x2af3: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2af9:
	/* 0x2af9: lea    ecx,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_2b00:
	/* 0x2b00: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b06:
	/* 0x2b06: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2b0a:
	/* 0x2b0a: mov    BYTE PTR [rax+0x54],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2b0d:
	/* 0x2b0d: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_2b11:
	/* 0x2b11: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2b17:
	/* 0x2b17: lea    ecx,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_2b1e:
	/* 0x2b1e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b24:
	/* 0x2b24: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2b28:
	/* 0x2b28: mov    BYTE PTR [rax+0x55],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_2b2b:
	/* 0x2b2b: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_2b2f:
	/* 0x2b2f: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2b35:
	/* 0x2b35: lea    ecx,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_2b3c:
	/* 0x2b3c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b42:
	/* 0x2b42: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2b46:
	/* 0x2b46: mov    BYTE PTR [rax+0x56],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2b49:
	/* 0x2b49: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_2b4d:
	/* 0x2b4d: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2b53:
	/* 0x2b53: lea    ecx,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_2b5a:
	/* 0x2b5a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b60:
	/* 0x2b60: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2b64:
	/* 0x2b64: mov    BYTE PTR [rax+0x57],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_2b67:
	/* 0x2b67: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_2b6b:
	/* 0x2b6b: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2b71:
	/* 0x2b71: lea    ecx,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_2b78:
	/* 0x2b78: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b7e:
	/* 0x2b7e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2b82:
	/* 0x2b82: mov    BYTE PTR [rax+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2b85:
	/* 0x2b85: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_2b89:
	/* 0x2b89: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2b8f:
	/* 0x2b8f: lea    ecx,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_2b96:
	/* 0x2b96: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b9c:
	/* 0x2b9c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2ba0:
	/* 0x2ba0: mov    BYTE PTR [rax+0x59],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_2ba3:
	/* 0x2ba3: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_2ba7:
	/* 0x2ba7: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2bad:
	/* 0x2bad: lea    ecx,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_2bb4:
	/* 0x2bb4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bba:
	/* 0x2bba: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2bbe:
	/* 0x2bbe: mov    BYTE PTR [rax+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_2bc1:
	/* 0x2bc1: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_2bc5:
	/* 0x2bc5: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2bcb:
	/* 0x2bcb: lea    ecx,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_2bd2:
	/* 0x2bd2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bd8:
	/* 0x2bd8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2bdc:
	/* 0x2bdc: mov    BYTE PTR [rax+0x5b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_2bdf:
	/* 0x2bdf: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_2be3:
	/* 0x2be3: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2be9:
	/* 0x2be9: lea    ecx,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_2bf0:
	/* 0x2bf0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bf6:
	/* 0x2bf6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2bfa:
	/* 0x2bfa: mov    BYTE PTR [rax+0x5c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_2bfd:
	/* 0x2bfd: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_2c01:
	/* 0x2c01: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2c07:
	/* 0x2c07: lea    ecx,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_2c0e:
	/* 0x2c0e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c14:
	/* 0x2c14: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2c18:
	/* 0x2c18: mov    BYTE PTR [rax+0x5d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_2c1b:
	/* 0x2c1b: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_2c1f:
	/* 0x2c1f: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2c21:
	/* 0x2c21: lea    ecx,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_2c28:
	/* 0x2c28: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c2e:
	/* 0x2c2e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2c32:
	/* 0x2c32: mov    BYTE PTR [rax+0x5e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_2c35:
	/* 0x2c35: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_2c39:
	/* 0x2c39: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2c3b:
	/* 0x2c3b: lea    ecx,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_2c42:
	/* 0x2c42: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c48:
	/* 0x2c48: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2c4c:
	/* 0x2c4c: mov    BYTE PTR [rax+0x5f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_2c4f:
	/* 0x2c4f: cmp    r13,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 92ULL);
x86_l_2c53:
	/* 0x2c53: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2c55:
	/* 0x2c55: lea    ecx,[r13+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_2c5c:
	/* 0x2c5c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c62:
	/* 0x2c62: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2c66:
	/* 0x2c66: mov    BYTE PTR [rax+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2c69:
	/* 0x2c69: cmp    r13,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 93ULL);
x86_l_2c6d:
	/* 0x2c6d: je     2c85 <generic_fentry_filter_arg+0x2c85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c85;
	}
x86_l_2c6f:
	/* 0x2c6f: add    r13d,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_2c76:
	/* 0x2c76: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c7d:
	/* 0x2c7d: movzx  ecx,BYTE PTR [rdx+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_2c82:
	/* 0x2c82: mov    BYTE PTR [rax+0x61],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_2c85:
	/* 0x2c85: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2c8a:
	/* 0x2c8a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c8e:
	/* 0x2c8e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2c91:
	/* 0x2c91: jmp    3773 <generic_fentry_filter_arg+0x3773> */
	return 14195ULL;
x86_l_2c96:
	/* 0x2c96: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c9b:
	/* 0x2c9b: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca0:
	/* 0x2ca0: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca4:
	/* 0x2ca4: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ca8:
	/* 0x2ca8: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2cb0:
	/* 0x2cb0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cb5:
	/* 0x2cb5: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_2cbc:
	/* 0x2cbc: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2cc1:
	/* 0x2cc1: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_2cc4:
	/* 0x2cc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc6:
	/* 0x2cc6: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2cc9:
	/* 0x2cc9: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ccc:
	/* 0x2ccc: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2ccf:
	/* 0x2ccf: je     3784 <generic_fentry_filter_arg+0x3784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14212ULL;
	}
x86_l_2cd5:
	/* 0x2cd5: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cd9:
	/* 0x2cd9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cdc:
	/* 0x2cdc: je     3784 <generic_fentry_filter_arg+0x3784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14212ULL;
	}
x86_l_2ce2:
	/* 0x2ce2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ce7:
	/* 0x2ce7: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_2cee:
	/* 0x2cee: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cf3:
	/* 0x2cf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cf5:
	/* 0x2cf5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cf8:
	/* 0x2cf8: je     3781 <generic_fentry_filter_arg+0x3781> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14209ULL;
	}
x86_l_2cfe:
	/* 0x2cfe: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d03:
	/* 0x2d03: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d07:
	/* 0x2d07: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_2d0e:
	/* 0x2d0e: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_2d13:
	/* 0x2d13: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_2d17:
	/* 0x2d17: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_2d1e:
	/* 0x2d1e: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d20:
	/* 0x2d20: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d23:
	/* 0x2d23: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d27:
	/* 0x2d27: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2d2c:
	/* 0x2d2c: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2d2f:
	/* 0x2d2f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2d31:
	/* 0x2d31: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d36:
	/* 0x2d36: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d3a:
	/* 0x2d3a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2d3d:
	/* 0x2d3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d3f:
	/* 0x2d3f: jmp    3775 <generic_fentry_filter_arg+0x3775> */
	return 14197ULL;
x86_l_2d44:
	/* 0x2d44: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d49:
	/* 0x2d49: mov    rdx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d4d:
	/* 0x2d4d: mov    r8,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d51:
	/* 0x2d51: jmp    2d5f <generic_fentry_filter_arg+0x2d5f> */
	goto x86_l_2d5f;
x86_l_2d53:
	/* 0x2d53: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d58:
	/* 0x2d58: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d5b:
	/* 0x2d5b: mov    r8,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d5f:
	/* 0x2d5f: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2d62:
	/* 0x2d62: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2d66:
	/* 0x2d66: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d68:
	/* 0x2d68: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d6b:
	/* 0x2d6b: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2d6e:
	/* 0x2d6e: jg     2d97 <generic_fentry_filter_arg+0x2d97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2d97;
	}
x86_l_2d70:
	/* 0x2d70: lea    eax,[rcx-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_2d73:
	/* 0x2d73: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d76:
	/* 0x2d76: jb     2dca <generic_fentry_filter_arg+0x2dca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2dca;
	}
x86_l_2d78:
	/* 0x2d78: lea    eax,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_2d7b:
	/* 0x2d7b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d7e:
	/* 0x2d7e: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d83:
	/* 0x2d83: jb     2f4f <generic_fentry_filter_arg+0x2f4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f4f;
	}
x86_l_2d89:
	/* 0x2d89: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2d8c:
	/* 0x2d8c: je     322a <generic_fentry_filter_arg+0x322a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12842ULL;
	}
x86_l_2d92:
	/* 0x2d92: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_2d97:
	/* 0x2d97: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_2d9a:
	/* 0x2d9a: ja     2f3e <generic_fentry_filter_arg+0x2f3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f3e;
	}
x86_l_2da0:
	/* 0x2da0: mov    eax,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5242880ULL);
x86_l_2da5:
	/* 0x2da5: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2da8:
	/* 0x2da8: jb     2f99 <generic_fentry_filter_arg+0x2f99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f99;
	}
x86_l_2dae:
	/* 0x2dae: mov    eax,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10485760ULL);
x86_l_2db3:
	/* 0x2db3: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2db6:
	/* 0x2db6: jb     2fad <generic_fentry_filter_arg+0x2fad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2fad;
	}
x86_l_2dbc:
	/* 0x2dbc: mov    eax,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50331648ULL);
x86_l_2dc1:
	/* 0x2dc1: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2dc4:
	/* 0x2dc4: jae    2f3e <generic_fentry_filter_arg+0x2f3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2f3e;
	}
x86_l_2dca:
	/* 0x2dca: movzx  eax,WORD PTR [rdi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2dce:
	/* 0x2dce: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_2dd1:
	/* 0x2dd1: je     2fc1 <generic_fentry_filter_arg+0x2fc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fc1;
	}
x86_l_2dd7:
	/* 0x2dd7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2dda:
	/* 0x2dda: jne    304e <generic_fentry_filter_arg+0x304e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_304e;
	}
x86_l_2de0:
	/* 0x2de0: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2de3:
	/* 0x2de3: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2de8:
	/* 0x2de8: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dec:
	/* 0x2dec: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2df0:
	/* 0x2df0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2df5:
	/* 0x2df5: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_2dfc:
	/* 0x2dfc: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2e01:
	/* 0x2e01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e03:
	/* 0x2e03: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e06:
	/* 0x2e06: je     34b7 <generic_fentry_filter_arg+0x34b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13495ULL;
	}
x86_l_2e0c:
	/* 0x2e0c: mov    DWORD PTR [rsp+0x28],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691872ULL);
x86_l_2e14:
	/* 0x2e14: mov    DWORD PTR [rsp+0x2c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2e19:
	/* 0x2e19: jmp    3014 <generic_fentry_filter_arg+0x3014> */
	goto x86_l_3014;
x86_l_2e1e:
	/* 0x2e1e: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e22:
	/* 0x2e22: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e26:
	/* 0x2e26: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2e2e:
	/* 0x2e2e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e33:
	/* 0x2e33: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_2e3a:
	/* 0x2e3a: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e3f:
	/* 0x2e3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e41:
	/* 0x2e41: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e44:
	/* 0x2e44: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e49:
	/* 0x2e49: je     3816 <generic_fentry_filter_arg+0x3816> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14358ULL;
	}
x86_l_2e4f:
	/* 0x2e4f: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e54:
	/* 0x2e54: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e57:
	/* 0x2e57: je     3816 <generic_fentry_filter_arg+0x3816> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14358ULL;
	}
x86_l_2e5d:
	/* 0x2e5d: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e62:
	/* 0x2e62: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e67:
	/* 0x2e67: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_2e6e:
	/* 0x2e6e: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e73:
	/* 0x2e73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e75:
	/* 0x2e75: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e78:
	/* 0x2e78: je     380e <generic_fentry_filter_arg+0x380e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14350ULL;
	}
x86_l_2e7e:
	/* 0x2e7e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2e81:
	/* 0x2e81: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e85:
	/* 0x2e85: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2e8a:
	/* 0x2e8a: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_2e8f:
	/* 0x2e8f: cmovb  esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2e92:
	/* 0x2e92: lea    eax,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_2e99:
	/* 0x2e99: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e9d:
	/* 0x2e9d: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2ea0:
	/* 0x2ea0: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2ea4:
	/* 0x2ea4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ea9:
	/* 0x2ea9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eae:
	/* 0x2eae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb0:
	/* 0x2eb0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2eb5:
	/* 0x2eb5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2eba:
	/* 0x2eba: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2ebd:
	/* 0x2ebd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ebf:
	/* 0x2ebf: jmp    3802 <generic_fentry_filter_arg+0x3802> */
	return 14338ULL;
x86_l_2ec4:
	/* 0x2ec4: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ec9:
	/* 0x2ec9: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2ed1:
	/* 0x2ed1: cmp    edx,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_2ed7:
	/* 0x2ed7: ja     380e <generic_fentry_filter_arg+0x380e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14350ULL;
	}
x86_l_2edd:
	/* 0x2edd: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ee2:
	/* 0x2ee2: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ee5:
	/* 0x2ee5: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2eeb:
	/* 0x2eeb: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2eee:
	/* 0x2eee: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2ef1:
	/* 0x2ef1: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2ef4:
	/* 0x2ef4: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2ef6:
	/* 0x2ef6: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2ef8:
	/* 0x2ef8: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_2efb:
	/* 0x2efb: je     34d7 <generic_fentry_filter_arg+0x34d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13527ULL;
	}
x86_l_2f01:
	/* 0x2f01: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2f03:
	/* 0x2f03: jne    34d7 <generic_fentry_filter_arg+0x34d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13527ULL;
	}
x86_l_2f09:
	/* 0x2f09: jmp    34ee <generic_fentry_filter_arg+0x34ee> */
	return 13550ULL;
x86_l_2f0e:
	/* 0x2f0e: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2f11:
	/* 0x2f11: jne    2f1b <generic_fentry_filter_arg+0x2f1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f1b;
	}
x86_l_2f13:
	/* 0x2f13: test   DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f15:
	/* 0x2f15: jne    383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14394ULL;
	}
x86_l_2f1b:
	/* 0x2f1b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2f1e:
	/* 0x2f1e: jb     36a6 <generic_fentry_filter_arg+0x36a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13990ULL;
	}
x86_l_2f24:
	/* 0x2f24: mov    esi,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f28:
	/* 0x2f28: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2f2b:
	/* 0x2f2b: jae    3472 <generic_fentry_filter_arg+0x3472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13426ULL;
	}
x86_l_2f31:
	/* 0x2f31: cmp    DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f33:
	/* 0x2f33: jne    347f <generic_fentry_filter_arg+0x347f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13439ULL;
	}
x86_l_2f39:
	/* 0x2f39: jmp    3632 <generic_fentry_filter_arg+0x3632> */
	return 13874ULL;
x86_l_2f3e:
	/* 0x2f3e: add    ecx,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_2f41:
	/* 0x2f41: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2f44:
	/* 0x2f44: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f49:
	/* 0x2f49: jae    3835 <generic_fentry_filter_arg+0x3835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14389ULL;
	}
x86_l_2f4f:
	/* 0x2f4f: mov    r15d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_32);
x86_l_2f52:
	/* 0x2f52: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2f57:
	/* 0x2f57: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2f5b:
	/* 0x2f5b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f60:
	/* 0x2f60: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2f67:
	/* 0x2f67: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2f6c:
	/* 0x2f6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f6e:
	/* 0x2f6e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f71:
	/* 0x2f71: je     346a <generic_fentry_filter_arg+0x346a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13418ULL;
	}
x86_l_2f77:
	/* 0x2f77: movzx  ecx,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f7b:
	/* 0x2f7b: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f80:
	/* 0x2f80: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2f85:
	/* 0x2f85: jmp    325d <generic_fentry_filter_arg+0x325d> */
	return 12893ULL;
x86_l_2f8a:
	/* 0x2f8a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f8d:
	/* 0x2f8d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2f90:
	/* 0x2f90: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2f94:
	/* 0x2f94: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_2f99:
	/* 0x2f99: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f9c:
	/* 0x2f9c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f9f:
	/* 0x2f9f: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2fa4:
	/* 0x2fa4: setb   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_B);
x86_l_2fa8:
	/* 0x2fa8: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_2fad:
	/* 0x2fad: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2fb0:
	/* 0x2fb0: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fb3:
	/* 0x2fb3: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2fb8:
	/* 0x2fb8: setae  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_AE);
x86_l_2fbc:
	/* 0x2fbc: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_2fc1:
	/* 0x2fc1: mov    QWORD PTR [rsp+0x8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fc6:
	/* 0x2fc6: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_2fc9:
	/* 0x2fc9: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fce:
	/* 0x2fce: mov    eax,DWORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2fd1:
	/* 0x2fd1: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2fd5:
	/* 0x2fd5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fda:
	/* 0x2fda: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_2fe1:
	/* 0x2fe1: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2fe6:
	/* 0x2fe6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe8:
	/* 0x2fe8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2feb:
	/* 0x2feb: je     34bd <generic_fentry_filter_arg+0x34bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13501ULL;
	}
x86_l_2ff1:
	/* 0x2ff1: mov    DWORD PTR [rsp+0x28],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691968ULL);
x86_l_2ff9:
	/* 0x2ff9: mov    DWORD PTR [rsp+0x2c],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2ffe:
	/* 0x2ffe: mov    DWORD PTR [rsp+0x30],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3003:
	/* 0x3003: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3008:
	/* 0x3008: mov    DWORD PTR [rsp+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_300c:
	/* 0x300c: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3010:
	/* 0x3010: mov    DWORD PTR [rsp+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3014:
	/* 0x3014: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3019:
	/* 0x3019: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_301e:
	/* 0x301e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3021:
	/* 0x3021: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3023:
	/* 0x3023: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3028:
	/* 0x3028: mov    ecx,DWORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_302b:
	/* 0x302b: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_302e:
	/* 0x302e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3031:
	/* 0x3031: jb     32ef <generic_fentry_filter_arg+0x32ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13039ULL;
	}
x86_l_3037:
	/* 0x3037: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_303a:
	/* 0x303a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_303d:
	/* 0x303d: ja     304e <generic_fentry_filter_arg+0x304e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_304e;
	}
x86_l_303f:
	/* 0x303f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3042:
	/* 0x3042: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_3045:
	/* 0x3045: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3049:
	/* 0x3049: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_304e:
	/* 0x304e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3050:
	/* 0x3050: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3054:
	/* 0x3054: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_3059:
	/* 0x3059: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_305c:
	/* 0x305c: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_305e:
	/* 0x305e: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3060:
	/* 0x3060: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_3062:
	/* 0x3062: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_3065:
	/* 0x3065: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_306a:
	/* 0x306a: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_306e:
	/* 0x306e: ja     307e <generic_fentry_filter_arg+0x307e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_307e;
	}
x86_l_3070:
	/* 0x3070: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3073:
	/* 0x3073: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_3079:
	/* 0x3079: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_307c:
	/* 0x307c: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_307e:
	/* 0x307e: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_3082:
	/* 0x3082: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3087:
	/* 0x3087: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_308b:
	/* 0x308b: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_308e:
	/* 0x308e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3093:
	/* 0x3093: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_3097:
	/* 0x3097: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_309b:
	/* 0x309b: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_309e:
	/* 0x309e: je     3714 <generic_fentry_filter_arg+0x3714> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14100ULL;
	}
x86_l_30a4:
	/* 0x30a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30a9:
	/* 0x30a9: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_30b0:
	/* 0x30b0: lea    r15,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30b5:
	/* 0x30b5: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_30b8:
	/* 0x30b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ba:
	/* 0x30ba: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_30bd:
	/* 0x30bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30c2:
	/* 0x30c2: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_30c9:
	/* 0x30c9: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_30cc:
	/* 0x30cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ce:
	/* 0x30ce: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30d1:
	/* 0x30d1: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30d6:
	/* 0x30d6: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_30d9:
	/* 0x30d9: je     3717 <generic_fentry_filter_arg+0x3717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14103ULL;
	}
x86_l_30df:
	/* 0x30df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30e2:
	/* 0x30e2: je     3717 <generic_fentry_filter_arg+0x3717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14103ULL;
	}
x86_l_30e8:
	/* 0x30e8: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_30eb:
	/* 0x30eb: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30ef:
	/* 0x30ef: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
	return 12532ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12532ULL: goto x86_l_30f4;
	case 12535ULL: goto x86_l_30f7;
	case 12539ULL: goto x86_l_30fb;
	case 12544ULL: goto x86_l_3100;
	case 12547ULL: goto x86_l_3103;
	case 12552ULL: goto x86_l_3108;
	case 12554ULL: goto x86_l_310a;
	case 12559ULL: goto x86_l_310f;
	case 12562ULL: goto x86_l_3112;
	case 12564ULL: goto x86_l_3114;
	case 12568ULL: goto x86_l_3118;
	case 12573ULL: goto x86_l_311d;
	case 12577ULL: goto x86_l_3121;
	case 12580ULL: goto x86_l_3124;
	case 12582ULL: goto x86_l_3126;
	case 12588ULL: goto x86_l_312c;
	case 12593ULL: goto x86_l_3131;
	case 12596ULL: goto x86_l_3134;
	case 12598ULL: goto x86_l_3136;
	case 12602ULL: goto x86_l_313a;
	case 12606ULL: goto x86_l_313e;
	case 12611ULL: goto x86_l_3143;
	case 12617ULL: goto x86_l_3149;
	case 12622ULL: goto x86_l_314e;
	case 12628ULL: goto x86_l_3154;
	case 12633ULL: goto x86_l_3159;
	case 12639ULL: goto x86_l_315f;
	case 12644ULL: goto x86_l_3164;
	case 12650ULL: goto x86_l_316a;
	case 12655ULL: goto x86_l_316f;
	case 12662ULL: goto x86_l_3176;
	case 12667ULL: goto x86_l_317b;
	case 12670ULL: goto x86_l_317e;
	case 12675ULL: goto x86_l_3183;
	case 12680ULL: goto x86_l_3188;
	case 12682ULL: goto x86_l_318a;
	case 12686ULL: goto x86_l_318e;
	case 12690ULL: goto x86_l_3192;
	case 12695ULL: goto x86_l_3197;
	case 12700ULL: goto x86_l_319c;
	case 12702ULL: goto x86_l_319e;
	case 12705ULL: goto x86_l_31a1;
	case 12709ULL: goto x86_l_31a5;
	case 12711ULL: goto x86_l_31a7;
	case 12717ULL: goto x86_l_31ad;
	case 12722ULL: goto x86_l_31b2;
	case 12727ULL: goto x86_l_31b7;
	case 12733ULL: goto x86_l_31bd;
	case 12735ULL: goto x86_l_31bf;
	case 12741ULL: goto x86_l_31c5;
	case 12744ULL: goto x86_l_31c8;
	case 12747ULL: goto x86_l_31cb;
	case 12753ULL: goto x86_l_31d1;
	case 12756ULL: goto x86_l_31d4;
	case 12758ULL: goto x86_l_31d6;
	case 12764ULL: goto x86_l_31dc;
	case 12766ULL: goto x86_l_31de;
	case 12772ULL: goto x86_l_31e4;
	case 12775ULL: goto x86_l_31e7;
	case 12781ULL: goto x86_l_31ed;
	case 12784ULL: goto x86_l_31f0;
	case 12786ULL: goto x86_l_31f2;
	case 12792ULL: goto x86_l_31f8;
	case 12794ULL: goto x86_l_31fa;
	case 12797ULL: goto x86_l_31fd;
	case 12803ULL: goto x86_l_3203;
	case 12806ULL: goto x86_l_3206;
	case 12812ULL: goto x86_l_320c;
	case 12815ULL: goto x86_l_320f;
	case 12817ULL: goto x86_l_3211;
	case 12823ULL: goto x86_l_3217;
	case 12826ULL: goto x86_l_321a;
	case 12828ULL: goto x86_l_321c;
	case 12832ULL: goto x86_l_3220;
	case 12837ULL: goto x86_l_3225;
	case 12842ULL: goto x86_l_322a;
	case 12847ULL: goto x86_l_322f;
	case 12851ULL: goto x86_l_3233;
	case 12856ULL: goto x86_l_3238;
	case 12863ULL: goto x86_l_323f;
	case 12868ULL: goto x86_l_3244;
	case 12870ULL: goto x86_l_3246;
	case 12873ULL: goto x86_l_3249;
	case 12879ULL: goto x86_l_324f;
	case 12883ULL: goto x86_l_3253;
	case 12888ULL: goto x86_l_3258;
	case 12893ULL: goto x86_l_325d;
	case 12898ULL: goto x86_l_3262;
	case 12901ULL: goto x86_l_3265;
	case 12903ULL: goto x86_l_3267;
	case 12907ULL: goto x86_l_326b;
	case 12909ULL: goto x86_l_326d;
	case 12912ULL: goto x86_l_3270;
	case 12914ULL: goto x86_l_3272;
	case 12919ULL: goto x86_l_3277;
	case 12922ULL: goto x86_l_327a;
	case 12924ULL: goto x86_l_327c;
	case 12927ULL: goto x86_l_327f;
	case 12930ULL: goto x86_l_3282;
	case 12932ULL: goto x86_l_3284;
	case 12937ULL: goto x86_l_3289;
	case 12940ULL: goto x86_l_328c;
	case 12942ULL: goto x86_l_328e;
	case 12945ULL: goto x86_l_3291;
	case 12948ULL: goto x86_l_3294;
	case 12952ULL: goto x86_l_3298;
	case 12957ULL: goto x86_l_329d;
	case 12960ULL: goto x86_l_32a0;
	case 12962ULL: goto x86_l_32a2;
	case 12965ULL: goto x86_l_32a5;
	case 12971ULL: goto x86_l_32ab;
	case 12974ULL: goto x86_l_32ae;
	case 12980ULL: goto x86_l_32b4;
	case 12984ULL: goto x86_l_32b8;
	case 12987ULL: goto x86_l_32bb;
	case 12993ULL: goto x86_l_32c1;
	case 12996ULL: goto x86_l_32c4;
	case 13002ULL: goto x86_l_32ca;
	case 13005ULL: goto x86_l_32cd;
	case 13011ULL: goto x86_l_32d3;
	case 13014ULL: goto x86_l_32d6;
	case 13017ULL: goto x86_l_32d9;
	case 13023ULL: goto x86_l_32df;
	case 13028ULL: goto x86_l_32e4;
	case 13031ULL: goto x86_l_32e7;
	case 13034ULL: goto x86_l_32ea;
	case 13039ULL: goto x86_l_32ef;
	case 13042ULL: goto x86_l_32f2;
	case 13047ULL: goto x86_l_32f7;
	case 13050ULL: goto x86_l_32fa;
	case 13053ULL: goto x86_l_32fd;
	case 13055ULL: goto x86_l_32ff;
	case 13057ULL: goto x86_l_3301;
	case 13060ULL: goto x86_l_3304;
	case 13065ULL: goto x86_l_3309;
	case 13069ULL: goto x86_l_330d;
	case 13071ULL: goto x86_l_330f;
	case 13074ULL: goto x86_l_3312;
	case 13080ULL: goto x86_l_3318;
	case 13083ULL: goto x86_l_331b;
	case 13085ULL: goto x86_l_331d;
	case 13089ULL: goto x86_l_3321;
	case 13092ULL: goto x86_l_3324;
	case 13095ULL: goto x86_l_3327;
	case 13100ULL: goto x86_l_332c;
	case 13104ULL: goto x86_l_3330;
	case 13108ULL: goto x86_l_3334;
	case 13111ULL: goto x86_l_3337;
	case 13117ULL: goto x86_l_333d;
	case 13122ULL: goto x86_l_3342;
	case 13129ULL: goto x86_l_3349;
	case 13134ULL: goto x86_l_334e;
	case 13137ULL: goto x86_l_3351;
	case 13139ULL: goto x86_l_3353;
	case 13142ULL: goto x86_l_3356;
	case 13147ULL: goto x86_l_335b;
	case 13154ULL: goto x86_l_3362;
	case 13157ULL: goto x86_l_3365;
	case 13159ULL: goto x86_l_3367;
	case 13164ULL: goto x86_l_336c;
	case 13167ULL: goto x86_l_336f;
	case 13172ULL: goto x86_l_3374;
	case 13175ULL: goto x86_l_3377;
	case 13181ULL: goto x86_l_337d;
	case 13187ULL: goto x86_l_3383;
	case 13193ULL: goto x86_l_3389;
	case 13198ULL: goto x86_l_338e;
	case 13202ULL: goto x86_l_3392;
	case 13207ULL: goto x86_l_3397;
	case 13212ULL: goto x86_l_339c;
	case 13215ULL: goto x86_l_339f;
	case 13219ULL: goto x86_l_33a3;
	case 13224ULL: goto x86_l_33a8;
	case 13227ULL: goto x86_l_33ab;
	case 13229ULL: goto x86_l_33ad;
	case 13234ULL: goto x86_l_33b2;
	case 13237ULL: goto x86_l_33b5;
	case 13239ULL: goto x86_l_33b7;
	case 13242ULL: goto x86_l_33ba;
	case 13247ULL: goto x86_l_33bf;
	case 13251ULL: goto x86_l_33c3;
	case 13254ULL: goto x86_l_33c6;
	case 13256ULL: goto x86_l_33c8;
	case 13262ULL: goto x86_l_33ce;
	case 13267ULL: goto x86_l_33d3;
	case 13272ULL: goto x86_l_33d8;
	case 13274ULL: goto x86_l_33da;
	case 13278ULL: goto x86_l_33de;
	case 13282ULL: goto x86_l_33e2;
	case 13286ULL: goto x86_l_33e6;
	case 13292ULL: goto x86_l_33ec;
	case 13296ULL: goto x86_l_33f0;
	case 13302ULL: goto x86_l_33f6;
	case 13306ULL: goto x86_l_33fa;
	case 13312ULL: goto x86_l_3400;
	case 13316ULL: goto x86_l_3404;
	case 13322ULL: goto x86_l_340a;
	case 13327ULL: goto x86_l_340f;
	case 13334ULL: goto x86_l_3416;
	case 13339ULL: goto x86_l_341b;
	case 13342ULL: goto x86_l_341e;
	case 13345ULL: goto x86_l_3421;
	case 13347ULL: goto x86_l_3423;
	case 13350ULL: goto x86_l_3426;
	case 13352ULL: goto x86_l_3428;
	case 13357ULL: goto x86_l_342d;
	case 13360ULL: goto x86_l_3430;
	case 13362ULL: goto x86_l_3432;
	case 13365ULL: goto x86_l_3435;
	case 13367ULL: goto x86_l_3437;
	case 13372ULL: goto x86_l_343c;
	case 13376ULL: goto x86_l_3440;
	case 13381ULL: goto x86_l_3445;
	case 13388ULL: goto x86_l_344c;
	case 13393ULL: goto x86_l_3451;
	case 13395ULL: goto x86_l_3453;
	case 13398ULL: goto x86_l_3456;
	case 13400ULL: goto x86_l_3458;
	case 13403ULL: goto x86_l_345b;
	case 13408ULL: goto x86_l_3460;
	case 13413ULL: goto x86_l_3465;
	case 13418ULL: goto x86_l_346a;
	case 13421ULL: goto x86_l_346d;
	case 13426ULL: goto x86_l_3472;
	case 13429ULL: goto x86_l_3475;
	case 13431ULL: goto x86_l_3477;
	case 13433ULL: goto x86_l_3479;
	case 13439ULL: goto x86_l_347f;
	case 13442ULL: goto x86_l_3482;
	case 13448ULL: goto x86_l_3488;
	case 13452ULL: goto x86_l_348c;
	case 13455ULL: goto x86_l_348f;
	case 13461ULL: goto x86_l_3495;
	case 13464ULL: goto x86_l_3498;
	case 13470ULL: goto x86_l_349e;
	case 13473ULL: goto x86_l_34a1;
	case 13479ULL: goto x86_l_34a7;
	case 13482ULL: goto x86_l_34aa;
	case 13484ULL: goto x86_l_34ac;
	case 13490ULL: goto x86_l_34b2;
	case 13495ULL: goto x86_l_34b7;
	case 13499ULL: goto x86_l_34bb;
	case 13501ULL: goto x86_l_34bd;
	case 13506ULL: goto x86_l_34c2;
	case 13509ULL: goto x86_l_34c5;
	case 13512ULL: goto x86_l_34c8;
	case 13515ULL: goto x86_l_34cb;
	case 13518ULL: goto x86_l_34ce;
	case 13522ULL: goto x86_l_34d2;
	case 13527ULL: goto x86_l_34d7;
	case 13530ULL: goto x86_l_34da;
	case 13532ULL: goto x86_l_34dc;
	case 13534ULL: goto x86_l_34de;
	case 13536ULL: goto x86_l_34e0;
	case 13539ULL: goto x86_l_34e3;
	case 13544ULL: goto x86_l_34e8;
	case 13548ULL: goto x86_l_34ec;
	case 13550ULL: goto x86_l_34ee;
	case 13553ULL: goto x86_l_34f1;
	case 13559ULL: goto x86_l_34f7;
	case 13562ULL: goto x86_l_34fa;
	case 13564ULL: goto x86_l_34fc;
	case 13568ULL: goto x86_l_3500;
	case 13572ULL: goto x86_l_3504;
	case 13575ULL: goto x86_l_3507;
	case 13580ULL: goto x86_l_350c;
	case 13584ULL: goto x86_l_3510;
	case 13588ULL: goto x86_l_3514;
	case 13591ULL: goto x86_l_3517;
	case 13597ULL: goto x86_l_351d;
	case 13602ULL: goto x86_l_3522;
	case 13609ULL: goto x86_l_3529;
	case 13614ULL: goto x86_l_352e;
	case 13617ULL: goto x86_l_3531;
	case 13619ULL: goto x86_l_3533;
	case 13622ULL: goto x86_l_3536;
	case 13627ULL: goto x86_l_353b;
	case 13634ULL: goto x86_l_3542;
	case 13637ULL: goto x86_l_3545;
	case 13639ULL: goto x86_l_3547;
	case 13644ULL: goto x86_l_354c;
	case 13647ULL: goto x86_l_354f;
	case 13652ULL: goto x86_l_3554;
	case 13655ULL: goto x86_l_3557;
	case 13661ULL: goto x86_l_355d;
	case 13667ULL: goto x86_l_3563;
	case 13673ULL: goto x86_l_3569;
	case 13677ULL: goto x86_l_356d;
	case 13682ULL: goto x86_l_3572;
	case 13685ULL: goto x86_l_3575;
	case 13689ULL: goto x86_l_3579;
	case 13694ULL: goto x86_l_357e;
	case 13697ULL: goto x86_l_3581;
	case 13702ULL: goto x86_l_3586;
	case 13704ULL: goto x86_l_3588;
	case 13709ULL: goto x86_l_358d;
	case 13712ULL: goto x86_l_3590;
	case 13714ULL: goto x86_l_3592;
	case 13718ULL: goto x86_l_3596;
	case 13723ULL: goto x86_l_359b;
	case 13727ULL: goto x86_l_359f;
	case 13730ULL: goto x86_l_35a2;
	case 13732ULL: goto x86_l_35a4;
	case 13738ULL: goto x86_l_35aa;
	case 13743ULL: goto x86_l_35af;
	case 13748ULL: goto x86_l_35b4;
	case 13750ULL: goto x86_l_35b6;
	case 13754ULL: goto x86_l_35ba;
	case 13758ULL: goto x86_l_35be;
	case 13763ULL: goto x86_l_35c3;
	case 13769ULL: goto x86_l_35c9;
	case 13774ULL: goto x86_l_35ce;
	case 13780ULL: goto x86_l_35d4;
	case 13785ULL: goto x86_l_35d9;
	case 13791ULL: goto x86_l_35df;
	case 13796ULL: goto x86_l_35e4;
	case 13802ULL: goto x86_l_35ea;
	case 13807ULL: goto x86_l_35ef;
	case 13814ULL: goto x86_l_35f6;
	case 13819ULL: goto x86_l_35fb;
	case 13824ULL: goto x86_l_3600;
	case 13830ULL: goto x86_l_3606;
	case 13835ULL: goto x86_l_360b;
	case 13841ULL: goto x86_l_3611;
	case 13846ULL: goto x86_l_3616;
	case 13852ULL: goto x86_l_361c;
	case 13857ULL: goto x86_l_3621;
	case 13864ULL: goto x86_l_3628;
	case 13869ULL: goto x86_l_362d;
	case 13872ULL: goto x86_l_3630;
	case 13874ULL: goto x86_l_3632;
	case 13877ULL: goto x86_l_3635;
	case 13880ULL: goto x86_l_3638;
	case 13884ULL: goto x86_l_363c;
	case 13889ULL: goto x86_l_3641;
	case 13893ULL: goto x86_l_3645;
	case 13899ULL: goto x86_l_364b;
	case 13903ULL: goto x86_l_364f;
	case 13909ULL: goto x86_l_3655;
	case 13913ULL: goto x86_l_3659;
	case 13919ULL: goto x86_l_365f;
	case 13924ULL: goto x86_l_3664;
	case 13931ULL: goto x86_l_366b;
	case 13936ULL: goto x86_l_3670;
	case 13941ULL: goto x86_l_3675;
	case 13947ULL: goto x86_l_367b;
	case 13952ULL: goto x86_l_3680;
	case 13958ULL: goto x86_l_3686;
	case 13963ULL: goto x86_l_368b;
	case 13969ULL: goto x86_l_3691;
	case 13974ULL: goto x86_l_3696;
	case 13981ULL: goto x86_l_369d;
	case 13986ULL: goto x86_l_36a2;
	case 13988ULL: goto x86_l_36a4;
	case 13990ULL: goto x86_l_36a6;
	case 13993ULL: goto x86_l_36a9;
	case 13996ULL: goto x86_l_36ac;
	case 14002ULL: goto x86_l_36b2;
	case 14007ULL: goto x86_l_36b7;
	case 14012ULL: goto x86_l_36bc;
	case 14019ULL: goto x86_l_36c3;
	case 14021ULL: goto x86_l_36c5;
	case 14026ULL: goto x86_l_36ca;
	case 14033ULL: goto x86_l_36d1;
	case 14035ULL: goto x86_l_36d3;
	case 14040ULL: goto x86_l_36d8;
	case 14047ULL: goto x86_l_36df;
	case 14049ULL: goto x86_l_36e1;
	case 14054ULL: goto x86_l_36e6;
	case 14061ULL: goto x86_l_36ed;
	case 14066ULL: goto x86_l_36f2;
	case 14068ULL: goto x86_l_36f4;
	case 14071ULL: goto x86_l_36f7;
	case 14073ULL: goto x86_l_36f9;
	case 14078ULL: goto x86_l_36fe;
	case 14081ULL: goto x86_l_3701;
	case 14086ULL: goto x86_l_3706;
	case 14088ULL: goto x86_l_3708;
	case 14091ULL: goto x86_l_370b;
	case 14094ULL: goto x86_l_370e;
	case 14098ULL: goto x86_l_3712;
	case 14100ULL: goto x86_l_3714;
	case 14103ULL: goto x86_l_3717;
	case 14108ULL: goto x86_l_371c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_30f4:
	/* 0x30f4: mov    BYTE PTR [rax],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30f7:
	/* 0x30f7: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_30fb:
	/* 0x30fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3100:
	/* 0x3100: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3103:
	/* 0x3103: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3108:
	/* 0x3108: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310a:
	/* 0x310a: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_310f:
	/* 0x310f: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3112:
	/* 0x3112: jbe    3136 <generic_fentry_filter_arg+0x3136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3136;
	}
x86_l_3114:
	/* 0x3114: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3118:
	/* 0x3118: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_311d:
	/* 0x311d: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3121:
	/* 0x3121: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3124:
	/* 0x3124: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3126:
	/* 0x3126: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_312c:
	/* 0x312c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3131:
	/* 0x3131: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3134:
	/* 0x3134: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3136:
	/* 0x3136: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_313a:
	/* 0x313a: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_313e:
	/* 0x313e: cmp    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_3143:
	/* 0x3143: jg     35fb <generic_fentry_filter_arg+0x35fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_35fb;
	}
x86_l_3149:
	/* 0x3149: cmp    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_314e:
	/* 0x314e: je     36b7 <generic_fentry_filter_arg+0x36b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36b7;
	}
x86_l_3154:
	/* 0x3154: cmp    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_3159:
	/* 0x3159: je     36d3 <generic_fentry_filter_arg+0x36d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36d3;
	}
x86_l_315f:
	/* 0x315f: cmp    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_3164:
	/* 0x3164: jne    3714 <generic_fentry_filter_arg+0x3714> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3714;
	}
x86_l_316a:
	/* 0x316a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_316f:
	/* 0x316f: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3176:
	/* 0x3176: jmp    36ed <generic_fentry_filter_arg+0x36ed> */
	goto x86_l_36ed;
x86_l_317b:
	/* 0x317b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_317e:
	/* 0x317e: jmp    378d <generic_fentry_filter_arg+0x378d> */
	return 14221ULL;
x86_l_3183:
	/* 0x3183: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3188:
	/* 0x3188: mov    ecx,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_318a:
	/* 0x318a: lea    rdx,[rdi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_318e:
	/* 0x318e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3192:
	/* 0x3192: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3197:
	/* 0x3197: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_319c:
	/* 0x319c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_319e:
	/* 0x319e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_31a1:
	/* 0x31a1: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31a5:
	/* 0x31a5: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_31a7:
	/* 0x31a7: je     32e4 <generic_fentry_filter_arg+0x32e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32e4;
	}
x86_l_31ad:
	/* 0x31ad: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_31b2:
	/* 0x31b2: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_31b7:
	/* 0x31b7: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_31bd:
	/* 0x31bd: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_31bf:
	/* 0x31bf: je     32e7 <generic_fentry_filter_arg+0x32e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32e7;
	}
x86_l_31c5:
	/* 0x31c5: mov    ecx,DWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31c8:
	/* 0x31c8: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_31cb:
	/* 0x31cb: jbe    32e4 <generic_fentry_filter_arg+0x32e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_32e4;
	}
x86_l_31d1:
	/* 0x31d1: mov    edx,DWORD PTR [rsi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_31d4:
	/* 0x31d4: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_31d6:
	/* 0x31d6: je     32e4 <generic_fentry_filter_arg+0x32e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32e4;
	}
x86_l_31dc:
	/* 0x31dc: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_31de:
	/* 0x31de: je     32e7 <generic_fentry_filter_arg+0x32e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32e7;
	}
x86_l_31e4:
	/* 0x31e4: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_31e7:
	/* 0x31e7: jb     32e4 <generic_fentry_filter_arg+0x32e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_32e4;
	}
x86_l_31ed:
	/* 0x31ed: mov    edx,DWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31f0:
	/* 0x31f0: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_31f2:
	/* 0x31f2: je     32e4 <generic_fentry_filter_arg+0x32e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32e4;
	}
x86_l_31f8:
	/* 0x31f8: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_31fa:
	/* 0x31fa: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_31fd:
	/* 0x31fd: je     3789 <generic_fentry_filter_arg+0x3789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14217ULL;
	}
x86_l_3203:
	/* 0x3203: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_3206:
	/* 0x3206: jb     32e4 <generic_fentry_filter_arg+0x32e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_32e4;
	}
x86_l_320c:
	/* 0x320c: mov    ecx,DWORD PTR [rsi+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_320f:
	/* 0x320f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3211:
	/* 0x3211: je     32e4 <generic_fentry_filter_arg+0x32e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32e4;
	}
x86_l_3217:
	/* 0x3217: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_321a:
	/* 0x321a: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_321c:
	/* 0x321c: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_3220:
	/* 0x3220: jmp    32e7 <generic_fentry_filter_arg+0x32e7> */
	goto x86_l_32e7;
x86_l_3225:
	/* 0x3225: movzx  r15d,WORD PTR [rdi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_322a:
	/* 0x322a: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_322f:
	/* 0x322f: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3233:
	/* 0x3233: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3238:
	/* 0x3238: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_323f:
	/* 0x323f: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3244:
	/* 0x3244: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3246:
	/* 0x3246: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3249:
	/* 0x3249: je     346a <generic_fentry_filter_arg+0x346a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_346a;
	}
x86_l_324f:
	/* 0x324f: movzx  ecx,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3253:
	/* 0x3253: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3258:
	/* 0x3258: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_325d:
	/* 0x325d: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3262:
	/* 0x3262: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3265:
	/* 0x3265: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3267:
	/* 0x3267: mov    edx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_326b:
	/* 0x326b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_326d:
	/* 0x326d: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_3270:
	/* 0x3270: ja     3294 <generic_fentry_filter_arg+0x3294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3294;
	}
x86_l_3272:
	/* 0x3272: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_3277:
	/* 0x3277: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_327a:
	/* 0x327a: jae    3284 <generic_fentry_filter_arg+0x3284> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3284;
	}
x86_l_327c:
	/* 0x327c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_327f:
	/* 0x327f: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_3282:
	/* 0x3282: jmp    3294 <generic_fentry_filter_arg+0x3294> */
	goto x86_l_3294;
x86_l_3284:
	/* 0x3284: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_3289:
	/* 0x3289: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_328c:
	/* 0x328c: jae    3294 <generic_fentry_filter_arg+0x3294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3294;
	}
x86_l_328e:
	/* 0x328e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3291:
	/* 0x3291: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_3294:
	/* 0x3294: movzx  r15d,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3298:
	/* 0x3298: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_329d:
	/* 0x329d: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_32a0:
	/* 0x32a0: jne    32ab <generic_fentry_filter_arg+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32ab;
	}
x86_l_32a2:
	/* 0x32a2: test   QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32a5:
	/* 0x32a5: jne    383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14394ULL;
	}
x86_l_32ab:
	/* 0x32ab: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_32ae:
	/* 0x32ae: jb     36a6 <generic_fentry_filter_arg+0x36a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_36a6;
	}
x86_l_32b4:
	/* 0x32b4: mov    rdx,QWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32b8:
	/* 0x32b8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_32bb:
	/* 0x32bb: jb     362d <generic_fentry_filter_arg+0x362d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_362d;
	}
x86_l_32c1:
	/* 0x32c1: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_32c4:
	/* 0x32c4: je     383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14394ULL;
	}
x86_l_32ca:
	/* 0x32ca: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_32cd:
	/* 0x32cd: jne    3844 <generic_fentry_filter_arg+0x3844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14404ULL;
	}
x86_l_32d3:
	/* 0x32d3: mov    rcx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDI, X86_WIDTH_64);
x86_l_32d6:
	/* 0x32d6: test   QWORD PTR [rdi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32d9:
	/* 0x32d9: jne    383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14394ULL;
	}
x86_l_32df:
	/* 0x32df: jmp    36a6 <generic_fentry_filter_arg+0x36a6> */
	goto x86_l_36a6;
x86_l_32e4:
	/* 0x32e4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32e7:
	/* 0x32e7: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_32ea:
	/* 0x32ea: jmp    3789 <generic_fentry_filter_arg+0x3789> */
	return 14217ULL;
x86_l_32ef:
	/* 0x32ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32f2:
	/* 0x32f2: jmp    34cb <generic_fentry_filter_arg+0x34cb> */
	goto x86_l_34cb;
x86_l_32f7:
	/* 0x32f7: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_32fa:
	/* 0x32fa: mov    ecx,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R8, X86_WIDTH_32);
x86_l_32fd:
	/* 0x32fd: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_32ff:
	/* 0x32ff: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_3301:
	/* 0x3301: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_3304:
	/* 0x3304: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_3309:
	/* 0x3309: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_330d:
	/* 0x330d: ja     331d <generic_fentry_filter_arg+0x331d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_331d;
	}
x86_l_330f:
	/* 0x330f: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3312:
	/* 0x3312: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_3318:
	/* 0x3318: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_331b:
	/* 0x331b: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_331d:
	/* 0x331d: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_3321:
	/* 0x3321: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3324:
	/* 0x3324: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_3327:
	/* 0x3327: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_332c:
	/* 0x332c: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_3330:
	/* 0x3330: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3334:
	/* 0x3334: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_3337:
	/* 0x3337: je     3781 <generic_fentry_filter_arg+0x3781> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14209ULL;
	}
x86_l_333d:
	/* 0x333d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3342:
	/* 0x3342: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_3349:
	/* 0x3349: lea    r15,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_334e:
	/* 0x334e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3351:
	/* 0x3351: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3353:
	/* 0x3353: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3356:
	/* 0x3356: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_335b:
	/* 0x335b: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3362:
	/* 0x3362: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3365:
	/* 0x3365: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3367:
	/* 0x3367: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_336c:
	/* 0x336c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_336f:
	/* 0x336f: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3374:
	/* 0x3374: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3377:
	/* 0x3377: je     3784 <generic_fentry_filter_arg+0x3784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14212ULL;
	}
x86_l_337d:
	/* 0x337d: cmp    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3383:
	/* 0x3383: je     3784 <generic_fentry_filter_arg+0x3784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14212ULL;
	}
x86_l_3389:
	/* 0x3389: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_338e:
	/* 0x338e: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3392:
	/* 0x3392: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3397:
	/* 0x3397: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_339c:
	/* 0x339c: mov    BYTE PTR [rax],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_339f:
	/* 0x339f: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_33a3:
	/* 0x33a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33a8:
	/* 0x33a8: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_33ab:
	/* 0x33ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33ad:
	/* 0x33ad: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_33b2:
	/* 0x33b2: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_33b5:
	/* 0x33b5: jbe    33da <generic_fentry_filter_arg+0x33da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_33da;
	}
x86_l_33b7:
	/* 0x33b7: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_33ba:
	/* 0x33ba: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_33bf:
	/* 0x33bf: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_33c3:
	/* 0x33c3: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_33c6:
	/* 0x33c6: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_33c8:
	/* 0x33c8: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_33ce:
	/* 0x33ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33d3:
	/* 0x33d3: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_33d8:
	/* 0x33d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33da:
	/* 0x33da: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_33de:
	/* 0x33de: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_33e2:
	/* 0x33e2: cmp    DWORD PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_33e6:
	/* 0x33e6: jg     3641 <generic_fentry_filter_arg+0x3641> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3641;
	}
x86_l_33ec:
	/* 0x33ec: cmp    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33f0:
	/* 0x33f0: je     3724 <generic_fentry_filter_arg+0x3724> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14116ULL;
	}
x86_l_33f6:
	/* 0x33f6: cmp    DWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_33fa:
	/* 0x33fa: je     3740 <generic_fentry_filter_arg+0x3740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14144ULL;
	}
x86_l_3400:
	/* 0x3400: cmp    DWORD PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3404:
	/* 0x3404: jne    3781 <generic_fentry_filter_arg+0x3781> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14209ULL;
	}
x86_l_340a:
	/* 0x340a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_340f:
	/* 0x340f: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3416:
	/* 0x3416: jmp    375a <generic_fentry_filter_arg+0x375a> */
	return 14170ULL;
x86_l_341b:
	/* 0x341b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_341e:
	/* 0x341e: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_3421:
	/* 0x3421: jne    342d <generic_fentry_filter_arg+0x342d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_342d;
	}
x86_l_3423:
	/* 0x3423: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3426:
	/* 0x3426: je     342d <generic_fentry_filter_arg+0x342d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_342d;
	}
x86_l_3428:
	/* 0x3428: movzx  r15d,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_342d:
	/* 0x342d: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_3430:
	/* 0x3430: je     3437 <generic_fentry_filter_arg+0x3437> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3437;
	}
x86_l_3432:
	/* 0x3432: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_3435:
	/* 0x3435: jne    346a <generic_fentry_filter_arg+0x346a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_346a;
	}
x86_l_3437:
	/* 0x3437: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_343c:
	/* 0x343c: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3440:
	/* 0x3440: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3445:
	/* 0x3445: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_344c:
	/* 0x344c: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3451:
	/* 0x3451: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3453:
	/* 0x3453: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3456:
	/* 0x3456: je     346a <generic_fentry_filter_arg+0x346a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_346a;
	}
x86_l_3458:
	/* 0x3458: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_345b:
	/* 0x345b: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3460:
	/* 0x3460: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3465:
	/* 0x3465: jmp    325d <generic_fentry_filter_arg+0x325d> */
	goto x86_l_325d;
x86_l_346a:
	/* 0x346a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_346d:
	/* 0x346d: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_3472:
	/* 0x3472: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3475:
	/* 0x3475: jne    347f <generic_fentry_filter_arg+0x347f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_347f;
	}
x86_l_3477:
	/* 0x3477: test   DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3479:
	/* 0x3479: jne    383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14394ULL;
	}
x86_l_347f:
	/* 0x347f: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_3482:
	/* 0x3482: jb     36a6 <generic_fentry_filter_arg+0x36a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_36a6;
	}
x86_l_3488:
	/* 0x3488: mov    edx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_348c:
	/* 0x348c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_348f:
	/* 0x348f: jb     36a2 <generic_fentry_filter_arg+0x36a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_36a2;
	}
x86_l_3495:
	/* 0x3495: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3498:
	/* 0x3498: je     383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14394ULL;
	}
x86_l_349e:
	/* 0x349e: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_34a1:
	/* 0x34a1: jne    3844 <generic_fentry_filter_arg+0x3844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14404ULL;
	}
x86_l_34a7:
	/* 0x34a7: mov    rcx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDI, X86_WIDTH_64);
x86_l_34aa:
	/* 0x34aa: test   DWORD PTR [rdi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34ac:
	/* 0x34ac: jne    383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14394ULL;
	}
x86_l_34b2:
	/* 0x34b2: jmp    36a6 <generic_fentry_filter_arg+0x36a6> */
	goto x86_l_36a6;
x86_l_34b7:
	/* 0x34b7: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_34bb:
	/* 0x34bb: jmp    34c5 <generic_fentry_filter_arg+0x34c5> */
	goto x86_l_34c5;
x86_l_34bd:
	/* 0x34bd: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34c2:
	/* 0x34c2: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_34c5:
	/* 0x34c5: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_34c8:
	/* 0x34c8: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_34cb:
	/* 0x34cb: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_34ce:
	/* 0x34ce: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_34d2:
	/* 0x34d2: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_34d7:
	/* 0x34d7: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_34da:
	/* 0x34da: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_34dc:
	/* 0x34dc: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34de:
	/* 0x34de: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_34e0:
	/* 0x34e0: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_34e3:
	/* 0x34e3: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_34e8:
	/* 0x34e8: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_34ec:
	/* 0x34ec: ja     34fc <generic_fentry_filter_arg+0x34fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_34fc;
	}
x86_l_34ee:
	/* 0x34ee: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_34f1:
	/* 0x34f1: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_34f7:
	/* 0x34f7: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_34fa:
	/* 0x34fa: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_34fc:
	/* 0x34fc: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_3500:
	/* 0x3500: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3504:
	/* 0x3504: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_3507:
	/* 0x3507: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_350c:
	/* 0x350c: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_3510:
	/* 0x3510: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3514:
	/* 0x3514: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_3517:
	/* 0x3517: je     380e <generic_fentry_filter_arg+0x380e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14350ULL;
	}
x86_l_351d:
	/* 0x351d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3522:
	/* 0x3522: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_3529:
	/* 0x3529: lea    r15,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_352e:
	/* 0x352e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3531:
	/* 0x3531: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3533:
	/* 0x3533: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3536:
	/* 0x3536: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_353b:
	/* 0x353b: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3542:
	/* 0x3542: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3545:
	/* 0x3545: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3547:
	/* 0x3547: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_354c:
	/* 0x354c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_354f:
	/* 0x354f: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3554:
	/* 0x3554: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3557:
	/* 0x3557: je     3811 <generic_fentry_filter_arg+0x3811> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14353ULL;
	}
x86_l_355d:
	/* 0x355d: cmp    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3563:
	/* 0x3563: je     3811 <generic_fentry_filter_arg+0x3811> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14353ULL;
	}
x86_l_3569:
	/* 0x3569: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_356d:
	/* 0x356d: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3572:
	/* 0x3572: mov    BYTE PTR [rax],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3575:
	/* 0x3575: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3579:
	/* 0x3579: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_357e:
	/* 0x357e: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3581:
	/* 0x3581: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3586:
	/* 0x3586: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3588:
	/* 0x3588: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_358d:
	/* 0x358d: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3590:
	/* 0x3590: jbe    35b6 <generic_fentry_filter_arg+0x35b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_35b6;
	}
x86_l_3592:
	/* 0x3592: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3596:
	/* 0x3596: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_359b:
	/* 0x359b: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_359f:
	/* 0x359f: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_35a2:
	/* 0x35a2: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_35a4:
	/* 0x35a4: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_35aa:
	/* 0x35aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35af:
	/* 0x35af: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_35b4:
	/* 0x35b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35b6:
	/* 0x35b6: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_35ba:
	/* 0x35ba: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_35be:
	/* 0x35be: cmp    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_35c3:
	/* 0x35c3: jg     3670 <generic_fentry_filter_arg+0x3670> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3670;
	}
x86_l_35c9:
	/* 0x35c9: cmp    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_35ce:
	/* 0x35ce: je     37b1 <generic_fentry_filter_arg+0x37b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14257ULL;
	}
x86_l_35d4:
	/* 0x35d4: cmp    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_35d9:
	/* 0x35d9: je     37cd <generic_fentry_filter_arg+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14285ULL;
	}
x86_l_35df:
	/* 0x35df: cmp    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_35e4:
	/* 0x35e4: jne    380e <generic_fentry_filter_arg+0x380e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14350ULL;
	}
x86_l_35ea:
	/* 0x35ea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35ef:
	/* 0x35ef: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_35f6:
	/* 0x35f6: jmp    37e7 <generic_fentry_filter_arg+0x37e7> */
	return 14311ULL;
x86_l_35fb:
	/* 0x35fb: cmp    DWORD PTR [rsp+0x18],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215107ULL);
x86_l_3600:
	/* 0x3600: je     36c5 <generic_fentry_filter_arg+0x36c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36c5;
	}
x86_l_3606:
	/* 0x3606: cmp    DWORD PTR [rsp+0x18],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215108ULL);
x86_l_360b:
	/* 0x360b: je     36e1 <generic_fentry_filter_arg+0x36e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36e1;
	}
x86_l_3611:
	/* 0x3611: cmp    DWORD PTR [rsp+0x18],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215109ULL);
x86_l_3616:
	/* 0x3616: jne    3714 <generic_fentry_filter_arg+0x3714> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3714;
	}
x86_l_361c:
	/* 0x361c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3621:
	/* 0x3621: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3628:
	/* 0x3628: jmp    36ed <generic_fentry_filter_arg+0x36ed> */
	goto x86_l_36ed;
x86_l_362d:
	/* 0x362d: cmp    QWORD PTR [rdi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3630:
	/* 0x3630: jne    36a6 <generic_fentry_filter_arg+0x36a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_36a6;
	}
x86_l_3632:
	/* 0x3632: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3635:
	/* 0x3635: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3638:
	/* 0x3638: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_363c:
	/* 0x363c: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	return 14389ULL;
x86_l_3641:
	/* 0x3641: cmp    DWORD PTR [rsp],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_3645:
	/* 0x3645: je     3732 <generic_fentry_filter_arg+0x3732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14130ULL;
	}
x86_l_364b:
	/* 0x364b: cmp    DWORD PTR [rsp],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_364f:
	/* 0x364f: je     374e <generic_fentry_filter_arg+0x374e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14158ULL;
	}
x86_l_3655:
	/* 0x3655: cmp    DWORD PTR [rsp],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3659:
	/* 0x3659: jne    3781 <generic_fentry_filter_arg+0x3781> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14209ULL;
	}
x86_l_365f:
	/* 0x365f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3664:
	/* 0x3664: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_366b:
	/* 0x366b: jmp    375a <generic_fentry_filter_arg+0x375a> */
	return 14170ULL;
x86_l_3670:
	/* 0x3670: cmp    DWORD PTR [rsp+0x18],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215107ULL);
x86_l_3675:
	/* 0x3675: je     37bf <generic_fentry_filter_arg+0x37bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14271ULL;
	}
x86_l_367b:
	/* 0x367b: cmp    DWORD PTR [rsp+0x18],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215108ULL);
x86_l_3680:
	/* 0x3680: je     37db <generic_fentry_filter_arg+0x37db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14299ULL;
	}
x86_l_3686:
	/* 0x3686: cmp    DWORD PTR [rsp+0x18],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215109ULL);
x86_l_368b:
	/* 0x368b: jne    380e <generic_fentry_filter_arg+0x380e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14350ULL;
	}
x86_l_3691:
	/* 0x3691: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3696:
	/* 0x3696: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_369d:
	/* 0x369d: jmp    37e7 <generic_fentry_filter_arg+0x37e7> */
	return 14311ULL;
x86_l_36a2:
	/* 0x36a2: cmp    DWORD PTR [rdi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36a4:
	/* 0x36a4: je     3632 <generic_fentry_filter_arg+0x3632> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3632;
	}
x86_l_36a6:
	/* 0x36a6: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_36a9:
	/* 0x36a9: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_36ac:
	/* 0x36ac: je     383a <generic_fentry_filter_arg+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14394ULL;
	}
x86_l_36b2:
	/* 0x36b2: jmp    3844 <generic_fentry_filter_arg+0x3844> */
	return 14404ULL;
x86_l_36b7:
	/* 0x36b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36bc:
	/* 0x36bc: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_36c3:
	/* 0x36c3: jmp    36ed <generic_fentry_filter_arg+0x36ed> */
	goto x86_l_36ed;
x86_l_36c5:
	/* 0x36c5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36ca:
	/* 0x36ca: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_36d1:
	/* 0x36d1: jmp    36ed <generic_fentry_filter_arg+0x36ed> */
	goto x86_l_36ed;
x86_l_36d3:
	/* 0x36d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36d8:
	/* 0x36d8: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_36df:
	/* 0x36df: jmp    36ed <generic_fentry_filter_arg+0x36ed> */
	goto x86_l_36ed;
x86_l_36e1:
	/* 0x36e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36e6:
	/* 0x36e6: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_36ed:
	/* 0x36ed: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_36f2:
	/* 0x36f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36f4:
	/* 0x36f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36f7:
	/* 0x36f7: je     3714 <generic_fentry_filter_arg+0x3714> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3714;
	}
x86_l_36f9:
	/* 0x36f9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_36fe:
	/* 0x36fe: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3701:
	/* 0x3701: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3706:
	/* 0x3706: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3708:
	/* 0x3708: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_370b:
	/* 0x370b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_370e:
	/* 0x370e: setne  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_NE);
x86_l_3712:
	/* 0x3712: jmp    3717 <generic_fentry_filter_arg+0x3717> */
	goto x86_l_3717;
x86_l_3714:
	/* 0x3714: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3717:
	/* 0x3717: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_371c:
	/* 0x371c: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
	return 14111ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14111ULL: goto x86_l_371f;
	case 14116ULL: goto x86_l_3724;
	case 14121ULL: goto x86_l_3729;
	case 14128ULL: goto x86_l_3730;
	case 14130ULL: goto x86_l_3732;
	case 14135ULL: goto x86_l_3737;
	case 14142ULL: goto x86_l_373e;
	case 14144ULL: goto x86_l_3740;
	case 14149ULL: goto x86_l_3745;
	case 14156ULL: goto x86_l_374c;
	case 14158ULL: goto x86_l_374e;
	case 14163ULL: goto x86_l_3753;
	case 14170ULL: goto x86_l_375a;
	case 14175ULL: goto x86_l_375f;
	case 14177ULL: goto x86_l_3761;
	case 14180ULL: goto x86_l_3764;
	case 14182ULL: goto x86_l_3766;
	case 14187ULL: goto x86_l_376b;
	case 14190ULL: goto x86_l_376e;
	case 14195ULL: goto x86_l_3773;
	case 14197ULL: goto x86_l_3775;
	case 14200ULL: goto x86_l_3778;
	case 14203ULL: goto x86_l_377b;
	case 14207ULL: goto x86_l_377f;
	case 14209ULL: goto x86_l_3781;
	case 14212ULL: goto x86_l_3784;
	case 14217ULL: goto x86_l_3789;
	case 14221ULL: goto x86_l_378d;
	case 14224ULL: goto x86_l_3790;
	case 14230ULL: goto x86_l_3796;
	case 14232ULL: goto x86_l_3798;
	case 14242ULL: goto x86_l_37a2;
	case 14246ULL: goto x86_l_37a6;
	case 14252ULL: goto x86_l_37ac;
	case 14257ULL: goto x86_l_37b1;
	case 14262ULL: goto x86_l_37b6;
	case 14269ULL: goto x86_l_37bd;
	case 14271ULL: goto x86_l_37bf;
	case 14276ULL: goto x86_l_37c4;
	case 14283ULL: goto x86_l_37cb;
	case 14285ULL: goto x86_l_37cd;
	case 14290ULL: goto x86_l_37d2;
	case 14297ULL: goto x86_l_37d9;
	case 14299ULL: goto x86_l_37db;
	case 14304ULL: goto x86_l_37e0;
	case 14311ULL: goto x86_l_37e7;
	case 14316ULL: goto x86_l_37ec;
	case 14318ULL: goto x86_l_37ee;
	case 14321ULL: goto x86_l_37f1;
	case 14323ULL: goto x86_l_37f3;
	case 14328ULL: goto x86_l_37f8;
	case 14331ULL: goto x86_l_37fb;
	case 14336ULL: goto x86_l_3800;
	case 14338ULL: goto x86_l_3802;
	case 14341ULL: goto x86_l_3805;
	case 14344ULL: goto x86_l_3808;
	case 14348ULL: goto x86_l_380c;
	case 14350ULL: goto x86_l_380e;
	case 14353ULL: goto x86_l_3811;
	case 14358ULL: goto x86_l_3816;
	case 14362ULL: goto x86_l_381a;
	case 14365ULL: goto x86_l_381d;
	case 14367ULL: goto x86_l_381f;
	case 14369ULL: goto x86_l_3821;
	case 14379ULL: goto x86_l_382b;
	case 14383ULL: goto x86_l_382f;
	case 14385ULL: goto x86_l_3831;
	case 14389ULL: goto x86_l_3835;
	case 14392ULL: goto x86_l_3838;
	case 14394ULL: goto x86_l_383a;
	case 14398ULL: goto x86_l_383e;
	case 14400ULL: goto x86_l_3840;
	case 14402ULL: goto x86_l_3842;
	case 14404ULL: goto x86_l_3844;
	case 14408ULL: goto x86_l_3848;
	case 14410ULL: goto x86_l_384a;
	case 14414ULL: goto x86_l_384e;
	case 14420ULL: goto x86_l_3854;
	case 14423ULL: goto x86_l_3857;
	case 14429ULL: goto x86_l_385d;
	case 14433ULL: goto x86_l_3861;
	case 14439ULL: goto x86_l_3867;
	case 14441ULL: goto x86_l_3869;
	case 14445ULL: goto x86_l_386d;
	case 14451ULL: goto x86_l_3873;
	case 14455ULL: goto x86_l_3877;
	case 14461ULL: goto x86_l_387d;
	case 14465ULL: goto x86_l_3881;
	case 14471ULL: goto x86_l_3887;
	case 14475ULL: goto x86_l_388b;
	case 14481ULL: goto x86_l_3891;
	case 14484ULL: goto x86_l_3894;
	case 14489ULL: goto x86_l_3899;
	case 14496ULL: goto x86_l_38a0;
	case 14501ULL: goto x86_l_38a5;
	case 14508ULL: goto x86_l_38ac;
	case 14511ULL: goto x86_l_38af;
	case 14516ULL: goto x86_l_38b4;
	case 14518ULL: goto x86_l_38b6;
	case 14523ULL: goto x86_l_38bb;
	case 14530ULL: goto x86_l_38c2;
	case 14533ULL: goto x86_l_38c5;
	case 14538ULL: goto x86_l_38ca;
	case 14540ULL: goto x86_l_38cc;
	case 14542ULL: goto x86_l_38ce;
	case 14549ULL: goto x86_l_38d5;
	case 14551ULL: goto x86_l_38d7;
	case 14552ULL: goto x86_l_38d8;
	case 14557ULL: goto x86_l_38dd;
	case 14560ULL: goto x86_l_38e0;
	case 14568ULL: goto x86_l_38e8;
	case 14570ULL: goto x86_l_38ea;
	case 14576ULL: goto x86_l_38f0;
	case 14584ULL: goto x86_l_38f8;
	case 14586ULL: goto x86_l_38fa;
	case 14592ULL: goto x86_l_3900;
	case 14600ULL: goto x86_l_3908;
	case 14602ULL: goto x86_l_390a;
	case 14608ULL: goto x86_l_3910;
	case 14616ULL: goto x86_l_3918;
	case 14618ULL: goto x86_l_391a;
	case 14624ULL: goto x86_l_3920;
	case 14632ULL: goto x86_l_3928;
	case 14634ULL: goto x86_l_392a;
	case 14640ULL: goto x86_l_3930;
	case 14648ULL: goto x86_l_3938;
	case 14650ULL: goto x86_l_393a;
	case 14657ULL: goto x86_l_3941;
	case 14662ULL: goto x86_l_3946;
	case 14669ULL: goto x86_l_394d;
	case 14672ULL: goto x86_l_3950;
	case 14677ULL: goto x86_l_3955;
	case 14679ULL: goto x86_l_3957;
	case 14683ULL: goto x86_l_395b;
	case 14688ULL: goto x86_l_3960;
	case 14690ULL: goto x86_l_3962;
	case 14695ULL: goto x86_l_3967;
	case 14700ULL: goto x86_l_396c;
	case 14705ULL: goto x86_l_3971;
	case 14712ULL: goto x86_l_3978;
	case 14717ULL: goto x86_l_397d;
	case 14719ULL: goto x86_l_397f;
	case 14722ULL: goto x86_l_3982;
	case 14728ULL: goto x86_l_3988;
	case 14733ULL: goto x86_l_398d;
	case 14740ULL: goto x86_l_3994;
	case 14745ULL: goto x86_l_3999;
	case 14747ULL: goto x86_l_399b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_371f:
	/* 0x371f: jmp    381a <generic_fentry_filter_arg+0x381a> */
	goto x86_l_381a;
x86_l_3724:
	/* 0x3724: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3729:
	/* 0x3729: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_3730:
	/* 0x3730: jmp    375a <generic_fentry_filter_arg+0x375a> */
	goto x86_l_375a;
x86_l_3732:
	/* 0x3732: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3737:
	/* 0x3737: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_373e:
	/* 0x373e: jmp    375a <generic_fentry_filter_arg+0x375a> */
	goto x86_l_375a;
x86_l_3740:
	/* 0x3740: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3745:
	/* 0x3745: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_374c:
	/* 0x374c: jmp    375a <generic_fentry_filter_arg+0x375a> */
	goto x86_l_375a;
x86_l_374e:
	/* 0x374e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3753:
	/* 0x3753: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_375a:
	/* 0x375a: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_375f:
	/* 0x375f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3761:
	/* 0x3761: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3764:
	/* 0x3764: je     3781 <generic_fentry_filter_arg+0x3781> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3781;
	}
x86_l_3766:
	/* 0x3766: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_376b:
	/* 0x376b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_376e:
	/* 0x376e: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3773:
	/* 0x3773: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3775:
	/* 0x3775: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3778:
	/* 0x3778: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_377b:
	/* 0x377b: setne  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_NE);
x86_l_377f:
	/* 0x377f: jmp    3784 <generic_fentry_filter_arg+0x3784> */
	goto x86_l_3784;
x86_l_3781:
	/* 0x3781: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3784:
	/* 0x3784: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3789:
	/* 0x3789: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_378d:
	/* 0x378d: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_3790:
	/* 0x3790: ja     3835 <generic_fentry_filter_arg+0x3835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3835;
	}
x86_l_3796:
	/* 0x3796: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3798:
	/* 0x3798: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_37a2:
	/* 0x37a2: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_37a6:
	/* 0x37a6: jb     3831 <generic_fentry_filter_arg+0x3831> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3831;
	}
x86_l_37ac:
	/* 0x37ac: jmp    3835 <generic_fentry_filter_arg+0x3835> */
	goto x86_l_3835;
x86_l_37b1:
	/* 0x37b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37b6:
	/* 0x37b6: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_37bd:
	/* 0x37bd: jmp    37e7 <generic_fentry_filter_arg+0x37e7> */
	goto x86_l_37e7;
x86_l_37bf:
	/* 0x37bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37c4:
	/* 0x37c4: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_37cb:
	/* 0x37cb: jmp    37e7 <generic_fentry_filter_arg+0x37e7> */
	goto x86_l_37e7;
x86_l_37cd:
	/* 0x37cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37d2:
	/* 0x37d2: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_37d9:
	/* 0x37d9: jmp    37e7 <generic_fentry_filter_arg+0x37e7> */
	goto x86_l_37e7;
x86_l_37db:
	/* 0x37db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37e0:
	/* 0x37e0: mov    rdi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_37e7:
	/* 0x37e7: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_37ec:
	/* 0x37ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37ee:
	/* 0x37ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_37f1:
	/* 0x37f1: je     380e <generic_fentry_filter_arg+0x380e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_380e;
	}
x86_l_37f3:
	/* 0x37f3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_37f8:
	/* 0x37f8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_37fb:
	/* 0x37fb: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3800:
	/* 0x3800: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3802:
	/* 0x3802: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3805:
	/* 0x3805: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3808:
	/* 0x3808: setne  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_NE);
x86_l_380c:
	/* 0x380c: jmp    3811 <generic_fentry_filter_arg+0x3811> */
	goto x86_l_3811;
x86_l_380e:
	/* 0x380e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3811:
	/* 0x3811: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3816:
	/* 0x3816: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_381a:
	/* 0x381a: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_381d:
	/* 0x381d: ja     3835 <generic_fentry_filter_arg+0x3835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3835;
	}
x86_l_381f:
	/* 0x381f: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3821:
	/* 0x3821: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_382b:
	/* 0x382b: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_382f:
	/* 0x382f: jae    3835 <generic_fentry_filter_arg+0x3835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3835;
	}
x86_l_3831:
	/* 0x3831: xor    r15,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_3835:
	/* 0x3835: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_3838:
	/* 0x3838: je     3844 <generic_fentry_filter_arg+0x3844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3844;
	}
x86_l_383a:
	/* 0x383a: cmp    rbp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 1ULL);
x86_l_383e:
	/* 0x383e: je     38b6 <generic_fentry_filter_arg+0x38b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b6;
	}
x86_l_3840:
	/* 0x3840: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_3842:
	/* 0x3842: jne    3899 <generic_fentry_filter_arg+0x3899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3899;
	}
x86_l_3844:
	/* 0x3844: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_3848:
	/* 0x3848: jg     3869 <generic_fentry_filter_arg+0x3869> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3869;
	}
x86_l_384a:
	/* 0x384a: cmp    r12d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_384e:
	/* 0x384e: je     38dd <generic_fentry_filter_arg+0x38dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38dd;
	}
x86_l_3854:
	/* 0x3854: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_3857:
	/* 0x3857: je     38ea <generic_fentry_filter_arg+0x38ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ea;
	}
x86_l_385d:
	/* 0x385d: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_3861:
	/* 0x3861: je     38fa <generic_fentry_filter_arg+0x38fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38fa;
	}
x86_l_3867:
	/* 0x3867: jmp    3887 <generic_fentry_filter_arg+0x3887> */
	goto x86_l_3887;
x86_l_3869:
	/* 0x3869: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_386d:
	/* 0x386d: je     390a <generic_fentry_filter_arg+0x390a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_390a;
	}
x86_l_3873:
	/* 0x3873: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_3877:
	/* 0x3877: je     391a <generic_fentry_filter_arg+0x391a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_391a;
	}
x86_l_387d:
	/* 0x387d: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3881:
	/* 0x3881: je     392a <generic_fentry_filter_arg+0x392a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_392a;
	}
x86_l_3887:
	/* 0x3887: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_388b:
	/* 0x388b: jg     3957 <generic_fentry_filter_arg+0x3957> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3957;
	}
x86_l_3891:
	/* 0x3891: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3894:
	/* 0x3894: jmp    393a <generic_fentry_filter_arg+0x393a> */
	goto x86_l_393a;
x86_l_3899:
	/* 0x3899: mov    DWORD PTR [r14+0x5ef4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_38a0:
	/* 0x38a0: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_38a5:
	/* 0x38a5: mov    rsi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_38ac:
	/* 0x38ac: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_38af:
	/* 0x38af: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_38b4:
	/* 0x38b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38b6:
	/* 0x38b6: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_38bb:
	/* 0x38bb: mov    rsi,QWORD PTR [rip+0x5d2f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_38c2:
	/* 0x38c2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_38c5:
	/* 0x38c5: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_38ca:
	/* 0x38ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38cc:
	/* 0x38cc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38ce:
	/* 0x38ce: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_38d5:
	/* 0x38d5: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_38d7:
	/* 0x38d7: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_38d8:
	/* 0x38d8: jmp    39a0 <generic_fentry_filter_arg+0x39a0> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_38dd:
	/* 0x38dd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38e0:
	/* 0x38e0: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_38e8:
	/* 0x38e8: jne    393a <generic_fentry_filter_arg+0x393a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_393a;
	}
x86_l_38ea:
	/* 0x38ea: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_38f0:
	/* 0x38f0: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_38f8:
	/* 0x38f8: jne    393a <generic_fentry_filter_arg+0x393a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_393a;
	}
x86_l_38fa:
	/* 0x38fa: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_3900:
	/* 0x3900: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_3908:
	/* 0x3908: jne    393a <generic_fentry_filter_arg+0x393a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_393a;
	}
x86_l_390a:
	/* 0x390a: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_3910:
	/* 0x3910: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_3918:
	/* 0x3918: jne    393a <generic_fentry_filter_arg+0x393a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_393a;
	}
x86_l_391a:
	/* 0x391a: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3920:
	/* 0x3920: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_3928:
	/* 0x3928: jne    393a <generic_fentry_filter_arg+0x393a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_393a;
	}
x86_l_392a:
	/* 0x392a: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_3930:
	/* 0x3930: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_3938:
	/* 0x3938: je     3957 <generic_fentry_filter_arg+0x3957> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3957;
	}
x86_l_393a:
	/* 0x393a: mov    DWORD PTR [r14+0x5ef0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_3941:
	/* 0x3941: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3946:
	/* 0x3946: mov    rsi,QWORD PTR [rip+0x5d32] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_394d:
	/* 0x394d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3950:
	/* 0x3950: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3955:
	/* 0x3955: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3957:
	/* 0x3957: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_395b:
	/* 0x395b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3960:
	/* 0x3960: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3962:
	/* 0x3962: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3967:
	/* 0x3967: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_396c:
	/* 0x396c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3971:
	/* 0x3971: mov    rdi,QWORD PTR [rip+0x5d32] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_3978:
	/* 0x3978: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_397d:
	/* 0x397d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_397f:
	/* 0x397f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3982:
	/* 0x3982: je     38cc <generic_fentry_filter_arg+0x38cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38cc;
	}
x86_l_3988:
	/* 0x3988: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_398d:
	/* 0x398d: mov    rdi,QWORD PTR [rip+0x5d32] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_3994:
	/* 0x3994: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3999:
	/* 0x3999: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_399b:
	/* 0x399b: jmp    38cc <generic_fentry_filter_arg+0x38cc> */
	goto x86_l_38cc;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12880U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1780ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1786ULL && __x86_pc <= 3603ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3606ULL && __x86_pc <= 5417ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5422ULL && __x86_pc <= 7222ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7228ULL && __x86_pc <= 8918ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8921ULL && __x86_pc <= 10838ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10841ULL && __x86_pc <= 12527ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12532ULL && __x86_pc <= 14108ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14111ULL && __x86_pc <= 14747ULL)
			__x86_pc = tetragon_bpf_generic_fentry_generic_fentry_filter_arg_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

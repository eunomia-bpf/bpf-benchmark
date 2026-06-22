extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
extern char filter_map;
extern char heap_ro_zero;
extern char process_call_heap;
extern char retprobe_map;
extern char retuprobe_calls;
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

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_0(
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
	case 59ULL: goto x86_l_3b;
	case 66ULL: goto x86_l_42;
	case 71ULL: goto x86_l_47;
	case 78ULL: goto x86_l_4e;
	case 80ULL: goto x86_l_50;
	case 83ULL: goto x86_l_53;
	case 89ULL: goto x86_l_59;
	case 97ULL: goto x86_l_61;
	case 103ULL: goto x86_l_67;
	case 106ULL: goto x86_l_6a;
	case 109ULL: goto x86_l_6d;
	case 118ULL: goto x86_l_76;
	case 124ULL: goto x86_l_7c;
	case 126ULL: goto x86_l_7e;
	case 130ULL: goto x86_l_82;
	case 134ULL: goto x86_l_86;
	case 138ULL: goto x86_l_8a;
	case 140ULL: goto x86_l_8c;
	case 146ULL: goto x86_l_92;
	case 150ULL: goto x86_l_96;
	case 156ULL: goto x86_l_9c;
	case 160ULL: goto x86_l_a0;
	case 166ULL: goto x86_l_a6;
	case 172ULL: goto x86_l_ac;
	case 174ULL: goto x86_l_ae;
	case 180ULL: goto x86_l_b4;
	case 183ULL: goto x86_l_b7;
	case 187ULL: goto x86_l_bb;
	case 193ULL: goto x86_l_c1;
	case 202ULL: goto x86_l_ca;
	case 208ULL: goto x86_l_d0;
	case 211ULL: goto x86_l_d3;
	case 214ULL: goto x86_l_d6;
	case 218ULL: goto x86_l_da;
	case 226ULL: goto x86_l_e2;
	case 231ULL: goto x86_l_e7;
	case 235ULL: goto x86_l_eb;
	case 242ULL: goto x86_l_f2;
	case 245ULL: goto x86_l_f5;
	case 247ULL: goto x86_l_f7;
	case 250ULL: goto x86_l_fa;
	case 256ULL: goto x86_l_100;
	case 259ULL: goto x86_l_103;
	case 265ULL: goto x86_l_109;
	case 268ULL: goto x86_l_10c;
	case 274ULL: goto x86_l_112;
	case 277ULL: goto x86_l_115;
	case 279ULL: goto x86_l_117;
	case 284ULL: goto x86_l_11c;
	case 287ULL: goto x86_l_11f;
	case 293ULL: goto x86_l_125;
	case 296ULL: goto x86_l_128;
	case 299ULL: goto x86_l_12b;
	case 305ULL: goto x86_l_131;
	case 308ULL: goto x86_l_134;
	case 311ULL: goto x86_l_137;
	case 314ULL: goto x86_l_13a;
	case 320ULL: goto x86_l_140;
	case 323ULL: goto x86_l_143;
	case 327ULL: goto x86_l_147;
	case 332ULL: goto x86_l_14c;
	case 335ULL: goto x86_l_14f;
	case 341ULL: goto x86_l_155;
	case 346ULL: goto x86_l_15a;
	case 349ULL: goto x86_l_15d;
	case 355ULL: goto x86_l_163;
	case 360ULL: goto x86_l_168;
	case 363ULL: goto x86_l_16b;
	case 369ULL: goto x86_l_171;
	case 374ULL: goto x86_l_176;
	case 378ULL: goto x86_l_17a;
	case 381ULL: goto x86_l_17d;
	case 385ULL: goto x86_l_181;
	case 393ULL: goto x86_l_189;
	case 398ULL: goto x86_l_18e;
	case 405ULL: goto x86_l_195;
	case 410ULL: goto x86_l_19a;
	case 412ULL: goto x86_l_19c;
	case 415ULL: goto x86_l_19f;
	case 418ULL: goto x86_l_1a2;
	case 421ULL: goto x86_l_1a5;
	case 427ULL: goto x86_l_1ab;
	case 430ULL: goto x86_l_1ae;
	case 436ULL: goto x86_l_1b4;
	case 439ULL: goto x86_l_1b7;
	case 444ULL: goto x86_l_1bc;
	case 451ULL: goto x86_l_1c3;
	case 456ULL: goto x86_l_1c8;
	case 458ULL: goto x86_l_1ca;
	case 461ULL: goto x86_l_1cd;
	case 467ULL: goto x86_l_1d3;
	case 471ULL: goto x86_l_1d7;
	case 476ULL: goto x86_l_1dc;
	case 480ULL: goto x86_l_1e0;
	case 483ULL: goto x86_l_1e3;
	case 485ULL: goto x86_l_1e5;
	case 489ULL: goto x86_l_1e9;
	case 495ULL: goto x86_l_1ef;
	case 500ULL: goto x86_l_1f4;
	case 504ULL: goto x86_l_1f8;
	case 507ULL: goto x86_l_1fb;
	case 511ULL: goto x86_l_1ff;
	case 517ULL: goto x86_l_205;
	case 524ULL: goto x86_l_20c;
	case 530ULL: goto x86_l_212;
	case 534ULL: goto x86_l_216;
	case 537ULL: goto x86_l_219;
	case 541ULL: goto x86_l_21d;
	case 547ULL: goto x86_l_223;
	case 554ULL: goto x86_l_22a;
	case 560ULL: goto x86_l_230;
	case 564ULL: goto x86_l_234;
	case 567ULL: goto x86_l_237;
	case 571ULL: goto x86_l_23b;
	case 577ULL: goto x86_l_241;
	case 584ULL: goto x86_l_248;
	case 590ULL: goto x86_l_24e;
	case 594ULL: goto x86_l_252;
	case 597ULL: goto x86_l_255;
	case 601ULL: goto x86_l_259;
	case 607ULL: goto x86_l_25f;
	case 614ULL: goto x86_l_266;
	case 620ULL: goto x86_l_26c;
	case 624ULL: goto x86_l_270;
	case 627ULL: goto x86_l_273;
	case 631ULL: goto x86_l_277;
	case 637ULL: goto x86_l_27d;
	case 644ULL: goto x86_l_284;
	case 650ULL: goto x86_l_28a;
	case 654ULL: goto x86_l_28e;
	case 657ULL: goto x86_l_291;
	case 661ULL: goto x86_l_295;
	case 667ULL: goto x86_l_29b;
	case 674ULL: goto x86_l_2a2;
	case 680ULL: goto x86_l_2a8;
	case 684ULL: goto x86_l_2ac;
	case 687ULL: goto x86_l_2af;
	case 691ULL: goto x86_l_2b3;
	case 697ULL: goto x86_l_2b9;
	case 704ULL: goto x86_l_2c0;
	case 710ULL: goto x86_l_2c6;
	case 714ULL: goto x86_l_2ca;
	case 717ULL: goto x86_l_2cd;
	case 721ULL: goto x86_l_2d1;
	case 727ULL: goto x86_l_2d7;
	case 734ULL: goto x86_l_2de;
	case 740ULL: goto x86_l_2e4;
	case 744ULL: goto x86_l_2e8;
	case 747ULL: goto x86_l_2eb;
	case 751ULL: goto x86_l_2ef;
	case 757ULL: goto x86_l_2f5;
	case 764ULL: goto x86_l_2fc;
	case 770ULL: goto x86_l_302;
	case 774ULL: goto x86_l_306;
	case 777ULL: goto x86_l_309;
	case 781ULL: goto x86_l_30d;
	case 787ULL: goto x86_l_313;
	case 794ULL: goto x86_l_31a;
	case 800ULL: goto x86_l_320;
	case 804ULL: goto x86_l_324;
	case 807ULL: goto x86_l_327;
	case 811ULL: goto x86_l_32b;
	case 817ULL: goto x86_l_331;
	case 824ULL: goto x86_l_338;
	case 830ULL: goto x86_l_33e;
	case 834ULL: goto x86_l_342;
	case 837ULL: goto x86_l_345;
	case 841ULL: goto x86_l_349;
	case 847ULL: goto x86_l_34f;
	case 854ULL: goto x86_l_356;
	case 860ULL: goto x86_l_35c;
	case 864ULL: goto x86_l_360;
	case 867ULL: goto x86_l_363;
	case 871ULL: goto x86_l_367;
	case 877ULL: goto x86_l_36d;
	case 884ULL: goto x86_l_374;
	case 890ULL: goto x86_l_37a;
	case 894ULL: goto x86_l_37e;
	case 897ULL: goto x86_l_381;
	case 901ULL: goto x86_l_385;
	case 907ULL: goto x86_l_38b;
	case 914ULL: goto x86_l_392;
	case 920ULL: goto x86_l_398;
	case 924ULL: goto x86_l_39c;
	case 927ULL: goto x86_l_39f;
	case 931ULL: goto x86_l_3a3;
	case 937ULL: goto x86_l_3a9;
	case 944ULL: goto x86_l_3b0;
	case 950ULL: goto x86_l_3b6;
	case 954ULL: goto x86_l_3ba;
	case 957ULL: goto x86_l_3bd;
	case 961ULL: goto x86_l_3c1;
	case 967ULL: goto x86_l_3c7;
	case 974ULL: goto x86_l_3ce;
	case 980ULL: goto x86_l_3d4;
	case 984ULL: goto x86_l_3d8;
	case 987ULL: goto x86_l_3db;
	case 991ULL: goto x86_l_3df;
	case 997ULL: goto x86_l_3e5;
	case 1004ULL: goto x86_l_3ec;
	case 1010ULL: goto x86_l_3f2;
	case 1014ULL: goto x86_l_3f6;
	case 1017ULL: goto x86_l_3f9;
	case 1021ULL: goto x86_l_3fd;
	case 1027ULL: goto x86_l_403;
	case 1034ULL: goto x86_l_40a;
	case 1040ULL: goto x86_l_410;
	case 1044ULL: goto x86_l_414;
	case 1047ULL: goto x86_l_417;
	case 1051ULL: goto x86_l_41b;
	case 1057ULL: goto x86_l_421;
	case 1064ULL: goto x86_l_428;
	case 1070ULL: goto x86_l_42e;
	case 1074ULL: goto x86_l_432;
	case 1077ULL: goto x86_l_435;
	case 1081ULL: goto x86_l_439;
	case 1087ULL: goto x86_l_43f;
	case 1094ULL: goto x86_l_446;
	case 1100ULL: goto x86_l_44c;
	case 1104ULL: goto x86_l_450;
	case 1107ULL: goto x86_l_453;
	case 1111ULL: goto x86_l_457;
	case 1117ULL: goto x86_l_45d;
	case 1124ULL: goto x86_l_464;
	case 1130ULL: goto x86_l_46a;
	case 1134ULL: goto x86_l_46e;
	case 1137ULL: goto x86_l_471;
	case 1141ULL: goto x86_l_475;
	case 1147ULL: goto x86_l_47b;
	case 1154ULL: goto x86_l_482;
	case 1160ULL: goto x86_l_488;
	case 1164ULL: goto x86_l_48c;
	case 1167ULL: goto x86_l_48f;
	case 1171ULL: goto x86_l_493;
	case 1177ULL: goto x86_l_499;
	case 1184ULL: goto x86_l_4a0;
	case 1190ULL: goto x86_l_4a6;
	case 1194ULL: goto x86_l_4aa;
	case 1197ULL: goto x86_l_4ad;
	case 1201ULL: goto x86_l_4b1;
	case 1207ULL: goto x86_l_4b7;
	case 1214ULL: goto x86_l_4be;
	case 1220ULL: goto x86_l_4c4;
	case 1224ULL: goto x86_l_4c8;
	case 1227ULL: goto x86_l_4cb;
	case 1231ULL: goto x86_l_4cf;
	case 1237ULL: goto x86_l_4d5;
	case 1244ULL: goto x86_l_4dc;
	case 1250ULL: goto x86_l_4e2;
	case 1254ULL: goto x86_l_4e6;
	case 1257ULL: goto x86_l_4e9;
	case 1261ULL: goto x86_l_4ed;
	case 1267ULL: goto x86_l_4f3;
	case 1274ULL: goto x86_l_4fa;
	case 1280ULL: goto x86_l_500;
	case 1284ULL: goto x86_l_504;
	case 1287ULL: goto x86_l_507;
	case 1291ULL: goto x86_l_50b;
	case 1297ULL: goto x86_l_511;
	case 1304ULL: goto x86_l_518;
	case 1310ULL: goto x86_l_51e;
	case 1314ULL: goto x86_l_522;
	case 1317ULL: goto x86_l_525;
	case 1321ULL: goto x86_l_529;
	case 1327ULL: goto x86_l_52f;
	case 1334ULL: goto x86_l_536;
	case 1340ULL: goto x86_l_53c;
	case 1344ULL: goto x86_l_540;
	case 1347ULL: goto x86_l_543;
	case 1351ULL: goto x86_l_547;
	case 1357ULL: goto x86_l_54d;
	case 1364ULL: goto x86_l_554;
	case 1370ULL: goto x86_l_55a;
	case 1374ULL: goto x86_l_55e;
	case 1377ULL: goto x86_l_561;
	case 1381ULL: goto x86_l_565;
	case 1387ULL: goto x86_l_56b;
	case 1394ULL: goto x86_l_572;
	case 1400ULL: goto x86_l_578;
	case 1404ULL: goto x86_l_57c;
	case 1407ULL: goto x86_l_57f;
	case 1411ULL: goto x86_l_583;
	case 1417ULL: goto x86_l_589;
	case 1424ULL: goto x86_l_590;
	case 1430ULL: goto x86_l_596;
	case 1434ULL: goto x86_l_59a;
	case 1437ULL: goto x86_l_59d;
	case 1441ULL: goto x86_l_5a1;
	case 1447ULL: goto x86_l_5a7;
	case 1454ULL: goto x86_l_5ae;
	case 1460ULL: goto x86_l_5b4;
	case 1464ULL: goto x86_l_5b8;
	case 1467ULL: goto x86_l_5bb;
	case 1471ULL: goto x86_l_5bf;
	case 1477ULL: goto x86_l_5c5;
	case 1484ULL: goto x86_l_5cc;
	case 1490ULL: goto x86_l_5d2;
	case 1494ULL: goto x86_l_5d6;
	case 1497ULL: goto x86_l_5d9;
	case 1501ULL: goto x86_l_5dd;
	case 1507ULL: goto x86_l_5e3;
	case 1514ULL: goto x86_l_5ea;
	case 1520ULL: goto x86_l_5f0;
	case 1524ULL: goto x86_l_5f4;
	case 1527ULL: goto x86_l_5f7;
	case 1531ULL: goto x86_l_5fb;
	case 1537ULL: goto x86_l_601;
	case 1544ULL: goto x86_l_608;
	case 1550ULL: goto x86_l_60e;
	case 1554ULL: goto x86_l_612;
	case 1557ULL: goto x86_l_615;
	case 1561ULL: goto x86_l_619;
	case 1567ULL: goto x86_l_61f;
	case 1574ULL: goto x86_l_626;
	case 1580ULL: goto x86_l_62c;
	case 1584ULL: goto x86_l_630;
	case 1587ULL: goto x86_l_633;
	case 1591ULL: goto x86_l_637;
	case 1597ULL: goto x86_l_63d;
	case 1604ULL: goto x86_l_644;
	case 1610ULL: goto x86_l_64a;
	case 1614ULL: goto x86_l_64e;
	case 1617ULL: goto x86_l_651;
	case 1621ULL: goto x86_l_655;
	case 1627ULL: goto x86_l_65b;
	case 1634ULL: goto x86_l_662;
	case 1640ULL: goto x86_l_668;
	case 1644ULL: goto x86_l_66c;
	case 1647ULL: goto x86_l_66f;
	case 1651ULL: goto x86_l_673;
	case 1657ULL: goto x86_l_679;
	case 1664ULL: goto x86_l_680;
	case 1670ULL: goto x86_l_686;
	case 1674ULL: goto x86_l_68a;
	case 1677ULL: goto x86_l_68d;
	case 1681ULL: goto x86_l_691;
	case 1687ULL: goto x86_l_697;
	case 1694ULL: goto x86_l_69e;
	case 1700ULL: goto x86_l_6a4;
	case 1704ULL: goto x86_l_6a8;
	case 1707ULL: goto x86_l_6ab;
	case 1711ULL: goto x86_l_6af;
	case 1717ULL: goto x86_l_6b5;
	case 1724ULL: goto x86_l_6bc;
	case 1730ULL: goto x86_l_6c2;
	case 1734ULL: goto x86_l_6c6;
	case 1737ULL: goto x86_l_6c9;
	case 1741ULL: goto x86_l_6cd;
	case 1747ULL: goto x86_l_6d3;
	case 1754ULL: goto x86_l_6da;
	case 1760ULL: goto x86_l_6e0;
	case 1764ULL: goto x86_l_6e4;
	case 1767ULL: goto x86_l_6e7;
	case 1771ULL: goto x86_l_6eb;
	case 1777ULL: goto x86_l_6f1;
	case 1784ULL: goto x86_l_6f8;
	case 1790ULL: goto x86_l_6fe;
	case 1794ULL: goto x86_l_702;
	case 1797ULL: goto x86_l_705;
	case 1801ULL: goto x86_l_709;
	case 1807ULL: goto x86_l_70f;
	case 1814ULL: goto x86_l_716;
	case 1820ULL: goto x86_l_71c;
	case 1824ULL: goto x86_l_720;
	case 1827ULL: goto x86_l_723;
	case 1831ULL: goto x86_l_727;
	case 1837ULL: goto x86_l_72d;
	case 1844ULL: goto x86_l_734;
	case 1850ULL: goto x86_l_73a;
	case 1854ULL: goto x86_l_73e;
	case 1857ULL: goto x86_l_741;
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
	/* 0xd: mov    DWORD PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_15:
	/* 0x15: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a:
	/* 0x1a: mov    rdi,QWORD PTR [rip+0x1787] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_21:
	/* 0x21: lea    rsi,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_26:
	/* 0x26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28:
	/* 0x28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: je     3317 <generic_retuprobe_filter_arg_2+0x3317> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13079ULL;
	}
x86_l_31:
	/* 0x31: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_34:
	/* 0x34: mov    r12d,DWORD PTR [rax+0x5ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_3b:
	/* 0x3b: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_42:
	/* 0x42: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_47:
	/* 0x47: mov    rdi,QWORD PTR [rip+0x1787] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_4e:
	/* 0x4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50:
	/* 0x50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: je     3301 <generic_retuprobe_filter_arg_2+0x3301> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13057ULL;
	}
x86_l_59:
	/* 0x59: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_61:
	/* 0x61: je     3301 <generic_retuprobe_filter_arg_2+0x3301> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13057ULL;
	}
x86_l_67:
	/* 0x67: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_6a:
	/* 0x6a: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_6d:
	/* 0x6d: cmp    BYTE PTR [r14+rcx*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 104183021699072ULL);
x86_l_76:
	/* 0x76: je     328f <generic_retuprobe_filter_arg_2+0x328f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12943ULL;
	}
x86_l_7c:
	/* 0x7c: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_7e:
	/* 0x7e: mov    edx,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_82:
	/* 0x82: lea    rcx,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_86:
	/* 0x86: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_8a:
	/* 0x8a: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_8c:
	/* 0x8c: and    ebp,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_92:
	/* 0x92: cmp    DWORD PTR [rax+rbp*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 25ULL);
x86_l_96:
	/* 0x96: jb     3285 <generic_retuprobe_filter_arg_2+0x3285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12933ULL;
	}
x86_l_9c:
	/* 0x9c: mov    edx,DWORD PTR [rax+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_a0:
	/* 0xa0: test   edx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 1023ULL);
x86_l_a6:
	/* 0xa6: je     3285 <generic_retuprobe_filter_arg_2+0x3285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12933ULL;
	}
x86_l_ac:
	/* 0xac: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ae:
	/* 0xae: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b4:
	/* 0xb4: mov    edx,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_b7:
	/* 0xb7: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_bb:
	/* 0xbb: ja     328f <generic_retuprobe_filter_arg_2+0x328f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12943ULL;
	}
x86_l_c1:
	/* 0xc1: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_ca:
	/* 0xca: jne    328f <generic_retuprobe_filter_arg_2+0x328f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12943ULL;
	}
x86_l_d0:
	/* 0xd0: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d3:
	/* 0xd3: add    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d6:
	/* 0xd6: mov    ecx,DWORD PTR [rax+rcx*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 12ULL);
x86_l_da:
	/* 0xda: mov    rax,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_e2:
	/* 0xe2: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e7:
	/* 0xe7: lea    rdi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_eb:
	/* 0xeb: add    rdi,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_f2:
	/* 0xf2: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_f5:
	/* 0xf5: jg     11c <generic_retuprobe_filter_arg_2+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_11c;
	}
x86_l_f7:
	/* 0xf7: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_fa:
	/* 0xfa: jg     ce3 <generic_retuprobe_filter_arg_2+0xce3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3299ULL;
	}
x86_l_100:
	/* 0x100: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_103:
	/* 0x103: je     e94 <generic_retuprobe_filter_arg_2+0xe94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3732ULL;
	}
x86_l_109:
	/* 0x109: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_10c:
	/* 0x10c: je     d01 <generic_retuprobe_filter_arg_2+0xd01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3329ULL;
	}
x86_l_112:
	/* 0x112: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_115:
	/* 0x115: je     131 <generic_retuprobe_filter_arg_2+0x131> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131;
	}
x86_l_117:
	/* 0x117: jmp    3285 <generic_retuprobe_filter_arg_2+0x3285> */
	return 12933ULL;
x86_l_11c:
	/* 0x11c: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_11f:
	/* 0x11f: jg     cf9 <generic_retuprobe_filter_arg_2+0xcf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3321ULL;
	}
x86_l_125:
	/* 0x125: lea    eax,[rcx-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_128:
	/* 0x128: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12b:
	/* 0x12b: jae    d6a <generic_retuprobe_filter_arg_2+0xd6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3434ULL;
	}
x86_l_131:
	/* 0x131: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_134:
	/* 0x134: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_137:
	/* 0x137: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_13a:
	/* 0x13a: ja     3265 <generic_retuprobe_filter_arg_2+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12901ULL;
	}
x86_l_140:
	/* 0x140: mov    r13d,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_143:
	/* 0x143: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_147:
	/* 0x147: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_14c:
	/* 0x14c: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_14f:
	/* 0x14f: jb     1b4e <generic_retuprobe_filter_arg_2+0x1b4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6990ULL;
	}
x86_l_155:
	/* 0x155: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_15a:
	/* 0x15a: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_15d:
	/* 0x15d: jb     1aa7 <generic_retuprobe_filter_arg_2+0x1aa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6823ULL;
	}
x86_l_163:
	/* 0x163: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_168:
	/* 0x168: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_16b:
	/* 0x16b: jae    3265 <generic_retuprobe_filter_arg_2+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12901ULL;
	}
x86_l_171:
	/* 0x171: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_176:
	/* 0x176: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17a:
	/* 0x17a: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d:
	/* 0x17d: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_181:
	/* 0x181: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_189:
	/* 0x189: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18e:
	/* 0x18e: mov    rdi,QWORD PTR [rip+0x1787] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_195:
	/* 0x195: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19a:
	/* 0x19a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c:
	/* 0x19c: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_19f:
	/* 0x19f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a2:
	/* 0x1a2: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1a5:
	/* 0x1a5: je     325e <generic_retuprobe_filter_arg_2+0x325e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12894ULL;
	}
x86_l_1ab:
	/* 0x1ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ae:
	/* 0x1ae: je     325e <generic_retuprobe_filter_arg_2+0x325e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12894ULL;
	}
x86_l_1b4:
	/* 0x1b4: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1b7:
	/* 0x1b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bc:
	/* 0x1bc: mov    rdi,QWORD PTR [rip+0x1784] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_1c3:
	/* 0x1c3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c8:
	/* 0x1c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca:
	/* 0x1ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cd:
	/* 0x1cd: je     325b <generic_retuprobe_filter_arg_2+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12891ULL;
	}
x86_l_1d3:
	/* 0x1d3: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_1d7:
	/* 0x1d7: mov    ecx,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 94ULL);
x86_l_1dc:
	/* 0x1dc: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1e0:
	/* 0x1e0: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1e3:
	/* 0x1e3: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e5:
	/* 0x1e5: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1e9:
	/* 0x1e9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ef:
	/* 0x1ef: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f4:
	/* 0x1f4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f8:
	/* 0x1f8: mov    BYTE PTR [rax+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fb:
	/* 0x1fb: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_1ff:
	/* 0x1ff: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_205:
	/* 0x205: lea    ecx,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_20c:
	/* 0x20c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_212:
	/* 0x212: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_216:
	/* 0x216: mov    BYTE PTR [rax+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_219:
	/* 0x219: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_21d:
	/* 0x21d: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_223:
	/* 0x223: lea    ecx,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_22a:
	/* 0x22a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_230:
	/* 0x230: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_234:
	/* 0x234: mov    BYTE PTR [rax+0x6],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_237:
	/* 0x237: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_23b:
	/* 0x23b: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_241:
	/* 0x241: lea    ecx,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_248:
	/* 0x248: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24e:
	/* 0x24e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_252:
	/* 0x252: mov    BYTE PTR [rax+0x7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_255:
	/* 0x255: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_259:
	/* 0x259: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_25f:
	/* 0x25f: lea    ecx,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_266:
	/* 0x266: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26c:
	/* 0x26c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_270:
	/* 0x270: mov    BYTE PTR [rax+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_273:
	/* 0x273: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_277:
	/* 0x277: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_27d:
	/* 0x27d: lea    ecx,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_284:
	/* 0x284: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28a:
	/* 0x28a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_28e:
	/* 0x28e: mov    BYTE PTR [rax+0x9],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_291:
	/* 0x291: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_295:
	/* 0x295: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_29b:
	/* 0x29b: lea    ecx,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_2a2:
	/* 0x2a2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a8:
	/* 0x2a8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2ac:
	/* 0x2ac: mov    BYTE PTR [rax+0xa],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_2af:
	/* 0x2af: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_2b3:
	/* 0x2b3: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_2b9:
	/* 0x2b9: lea    ecx,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_2c0:
	/* 0x2c0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c6:
	/* 0x2c6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2ca:
	/* 0x2ca: mov    BYTE PTR [rax+0xb],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_2cd:
	/* 0x2cd: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_2d1:
	/* 0x2d1: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_2d7:
	/* 0x2d7: lea    ecx,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_2de:
	/* 0x2de: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2e4:
	/* 0x2e4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2e8:
	/* 0x2e8: mov    BYTE PTR [rax+0xc],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2eb:
	/* 0x2eb: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_2ef:
	/* 0x2ef: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_2f5:
	/* 0x2f5: lea    ecx,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_2fc:
	/* 0x2fc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_302:
	/* 0x302: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_306:
	/* 0x306: mov    BYTE PTR [rax+0xd],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_309:
	/* 0x309: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_30d:
	/* 0x30d: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_313:
	/* 0x313: lea    ecx,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_31a:
	/* 0x31a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_320:
	/* 0x320: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_324:
	/* 0x324: mov    BYTE PTR [rax+0xe],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_327:
	/* 0x327: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_32b:
	/* 0x32b: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_331:
	/* 0x331: lea    ecx,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_338:
	/* 0x338: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_33e:
	/* 0x33e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_342:
	/* 0x342: mov    BYTE PTR [rax+0xf],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_345:
	/* 0x345: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_349:
	/* 0x349: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_34f:
	/* 0x34f: lea    ecx,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_356:
	/* 0x356: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_35c:
	/* 0x35c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_360:
	/* 0x360: mov    BYTE PTR [rax+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_363:
	/* 0x363: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_367:
	/* 0x367: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_36d:
	/* 0x36d: lea    ecx,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_374:
	/* 0x374: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_37a:
	/* 0x37a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_37e:
	/* 0x37e: mov    BYTE PTR [rax+0x11],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_381:
	/* 0x381: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_385:
	/* 0x385: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_38b:
	/* 0x38b: lea    ecx,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_392:
	/* 0x392: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_398:
	/* 0x398: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_39c:
	/* 0x39c: mov    BYTE PTR [rax+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_39f:
	/* 0x39f: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_3a3:
	/* 0x3a3: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_3a9:
	/* 0x3a9: lea    ecx,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_3b0:
	/* 0x3b0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3b6:
	/* 0x3b6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_3ba:
	/* 0x3ba: mov    BYTE PTR [rax+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_3bd:
	/* 0x3bd: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_3c1:
	/* 0x3c1: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_3c7:
	/* 0x3c7: lea    ecx,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_3ce:
	/* 0x3ce: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3d4:
	/* 0x3d4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_3d8:
	/* 0x3d8: mov    BYTE PTR [rax+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3db:
	/* 0x3db: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_3df:
	/* 0x3df: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_3e5:
	/* 0x3e5: lea    ecx,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_3ec:
	/* 0x3ec: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3f2:
	/* 0x3f2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_3f6:
	/* 0x3f6: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_3f9:
	/* 0x3f9: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_3fd:
	/* 0x3fd: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_403:
	/* 0x403: lea    ecx,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_40a:
	/* 0x40a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_410:
	/* 0x410: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_414:
	/* 0x414: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_417:
	/* 0x417: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_41b:
	/* 0x41b: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_421:
	/* 0x421: lea    ecx,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_428:
	/* 0x428: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_42e:
	/* 0x42e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_432:
	/* 0x432: mov    BYTE PTR [rax+0x17],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_435:
	/* 0x435: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_439:
	/* 0x439: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_43f:
	/* 0x43f: lea    ecx,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_446:
	/* 0x446: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_44c:
	/* 0x44c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_450:
	/* 0x450: mov    BYTE PTR [rax+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_453:
	/* 0x453: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_457:
	/* 0x457: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_45d:
	/* 0x45d: lea    ecx,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_464:
	/* 0x464: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_46a:
	/* 0x46a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_46e:
	/* 0x46e: mov    BYTE PTR [rax+0x19],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_471:
	/* 0x471: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_475:
	/* 0x475: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_47b:
	/* 0x47b: lea    ecx,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_482:
	/* 0x482: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_488:
	/* 0x488: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_48c:
	/* 0x48c: mov    BYTE PTR [rax+0x1a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_48f:
	/* 0x48f: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_493:
	/* 0x493: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_499:
	/* 0x499: lea    ecx,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_4a0:
	/* 0x4a0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4a6:
	/* 0x4a6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_4aa:
	/* 0x4aa: mov    BYTE PTR [rax+0x1b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_4ad:
	/* 0x4ad: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_4b1:
	/* 0x4b1: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_4b7:
	/* 0x4b7: lea    ecx,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_4be:
	/* 0x4be: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4c4:
	/* 0x4c4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_4c8:
	/* 0x4c8: mov    BYTE PTR [rax+0x1c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4cb:
	/* 0x4cb: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_4cf:
	/* 0x4cf: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_4d5:
	/* 0x4d5: lea    ecx,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_4dc:
	/* 0x4dc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4e2:
	/* 0x4e2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_4e6:
	/* 0x4e6: mov    BYTE PTR [rax+0x1d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_4e9:
	/* 0x4e9: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_4ed:
	/* 0x4ed: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_4f3:
	/* 0x4f3: lea    ecx,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_4fa:
	/* 0x4fa: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_500:
	/* 0x500: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_504:
	/* 0x504: mov    BYTE PTR [rax+0x1e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_507:
	/* 0x507: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_50b:
	/* 0x50b: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_511:
	/* 0x511: lea    ecx,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_518:
	/* 0x518: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_51e:
	/* 0x51e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_522:
	/* 0x522: mov    BYTE PTR [rax+0x1f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_525:
	/* 0x525: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_529:
	/* 0x529: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_52f:
	/* 0x52f: lea    ecx,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_536:
	/* 0x536: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_53c:
	/* 0x53c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_540:
	/* 0x540: mov    BYTE PTR [rax+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_543:
	/* 0x543: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_547:
	/* 0x547: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_54d:
	/* 0x54d: lea    ecx,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_554:
	/* 0x554: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_55a:
	/* 0x55a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_55e:
	/* 0x55e: mov    BYTE PTR [rax+0x21],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_561:
	/* 0x561: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_565:
	/* 0x565: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_56b:
	/* 0x56b: lea    ecx,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_572:
	/* 0x572: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_578:
	/* 0x578: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_57c:
	/* 0x57c: mov    BYTE PTR [rax+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_57f:
	/* 0x57f: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_583:
	/* 0x583: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_589:
	/* 0x589: lea    ecx,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_590:
	/* 0x590: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_596:
	/* 0x596: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_59a:
	/* 0x59a: mov    BYTE PTR [rax+0x23],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_59d:
	/* 0x59d: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_5a1:
	/* 0x5a1: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_5a7:
	/* 0x5a7: lea    ecx,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_5ae:
	/* 0x5ae: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5b4:
	/* 0x5b4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_5b8:
	/* 0x5b8: mov    BYTE PTR [rax+0x24],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5bb:
	/* 0x5bb: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_5bf:
	/* 0x5bf: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_5c5:
	/* 0x5c5: lea    ecx,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_5cc:
	/* 0x5cc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5d2:
	/* 0x5d2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_5d6:
	/* 0x5d6: mov    BYTE PTR [rax+0x25],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_5d9:
	/* 0x5d9: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_5dd:
	/* 0x5dd: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_5e3:
	/* 0x5e3: lea    ecx,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_5ea:
	/* 0x5ea: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5f0:
	/* 0x5f0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_5f4:
	/* 0x5f4: mov    BYTE PTR [rax+0x26],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_5f7:
	/* 0x5f7: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_5fb:
	/* 0x5fb: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_601:
	/* 0x601: lea    ecx,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_608:
	/* 0x608: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_60e:
	/* 0x60e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_612:
	/* 0x612: mov    BYTE PTR [rax+0x27],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_615:
	/* 0x615: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_619:
	/* 0x619: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_61f:
	/* 0x61f: lea    ecx,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_626:
	/* 0x626: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_62c:
	/* 0x62c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_630:
	/* 0x630: mov    BYTE PTR [rax+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_633:
	/* 0x633: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_637:
	/* 0x637: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_63d:
	/* 0x63d: lea    ecx,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_644:
	/* 0x644: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_64a:
	/* 0x64a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_64e:
	/* 0x64e: mov    BYTE PTR [rax+0x29],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_651:
	/* 0x651: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_655:
	/* 0x655: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_65b:
	/* 0x65b: lea    ecx,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_662:
	/* 0x662: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_668:
	/* 0x668: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_66c:
	/* 0x66c: mov    BYTE PTR [rax+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_66f:
	/* 0x66f: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_673:
	/* 0x673: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_679:
	/* 0x679: lea    ecx,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_680:
	/* 0x680: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_686:
	/* 0x686: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_68a:
	/* 0x68a: mov    BYTE PTR [rax+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_68d:
	/* 0x68d: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_691:
	/* 0x691: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_697:
	/* 0x697: lea    ecx,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_69e:
	/* 0x69e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6a4:
	/* 0x6a4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_6a8:
	/* 0x6a8: mov    BYTE PTR [rax+0x2c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6ab:
	/* 0x6ab: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_6af:
	/* 0x6af: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_6b5:
	/* 0x6b5: lea    ecx,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_6bc:
	/* 0x6bc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6c2:
	/* 0x6c2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_6c6:
	/* 0x6c6: mov    BYTE PTR [rax+0x2d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_6c9:
	/* 0x6c9: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_6cd:
	/* 0x6cd: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_6d3:
	/* 0x6d3: lea    ecx,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_6da:
	/* 0x6da: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6e0:
	/* 0x6e0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_6e4:
	/* 0x6e4: mov    BYTE PTR [rax+0x2e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_6e7:
	/* 0x6e7: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_6eb:
	/* 0x6eb: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_6f1:
	/* 0x6f1: lea    ecx,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_6f8:
	/* 0x6f8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6fe:
	/* 0x6fe: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_702:
	/* 0x702: mov    BYTE PTR [rax+0x2f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_705:
	/* 0x705: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_709:
	/* 0x709: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_70f:
	/* 0x70f: lea    ecx,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_716:
	/* 0x716: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_71c:
	/* 0x71c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_720:
	/* 0x720: mov    BYTE PTR [rax+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_723:
	/* 0x723: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_727:
	/* 0x727: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3283ULL;
	}
x86_l_72d:
	/* 0x72d: lea    ecx,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_734:
	/* 0x734: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_73a:
	/* 0x73a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_73e:
	/* 0x73e: mov    BYTE PTR [rax+0x31],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_741:
	/* 0x741: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
	return 1861ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1861ULL: goto x86_l_745;
	case 1867ULL: goto x86_l_74b;
	case 1874ULL: goto x86_l_752;
	case 1880ULL: goto x86_l_758;
	case 1884ULL: goto x86_l_75c;
	case 1887ULL: goto x86_l_75f;
	case 1891ULL: goto x86_l_763;
	case 1897ULL: goto x86_l_769;
	case 1904ULL: goto x86_l_770;
	case 1910ULL: goto x86_l_776;
	case 1914ULL: goto x86_l_77a;
	case 1917ULL: goto x86_l_77d;
	case 1921ULL: goto x86_l_781;
	case 1927ULL: goto x86_l_787;
	case 1934ULL: goto x86_l_78e;
	case 1940ULL: goto x86_l_794;
	case 1944ULL: goto x86_l_798;
	case 1947ULL: goto x86_l_79b;
	case 1951ULL: goto x86_l_79f;
	case 1957ULL: goto x86_l_7a5;
	case 1964ULL: goto x86_l_7ac;
	case 1970ULL: goto x86_l_7b2;
	case 1974ULL: goto x86_l_7b6;
	case 1977ULL: goto x86_l_7b9;
	case 1981ULL: goto x86_l_7bd;
	case 1987ULL: goto x86_l_7c3;
	case 1994ULL: goto x86_l_7ca;
	case 2000ULL: goto x86_l_7d0;
	case 2004ULL: goto x86_l_7d4;
	case 2007ULL: goto x86_l_7d7;
	case 2011ULL: goto x86_l_7db;
	case 2017ULL: goto x86_l_7e1;
	case 2024ULL: goto x86_l_7e8;
	case 2030ULL: goto x86_l_7ee;
	case 2034ULL: goto x86_l_7f2;
	case 2037ULL: goto x86_l_7f5;
	case 2041ULL: goto x86_l_7f9;
	case 2047ULL: goto x86_l_7ff;
	case 2054ULL: goto x86_l_806;
	case 2060ULL: goto x86_l_80c;
	case 2064ULL: goto x86_l_810;
	case 2067ULL: goto x86_l_813;
	case 2071ULL: goto x86_l_817;
	case 2077ULL: goto x86_l_81d;
	case 2084ULL: goto x86_l_824;
	case 2090ULL: goto x86_l_82a;
	case 2094ULL: goto x86_l_82e;
	case 2097ULL: goto x86_l_831;
	case 2101ULL: goto x86_l_835;
	case 2107ULL: goto x86_l_83b;
	case 2114ULL: goto x86_l_842;
	case 2120ULL: goto x86_l_848;
	case 2124ULL: goto x86_l_84c;
	case 2127ULL: goto x86_l_84f;
	case 2131ULL: goto x86_l_853;
	case 2137ULL: goto x86_l_859;
	case 2144ULL: goto x86_l_860;
	case 2150ULL: goto x86_l_866;
	case 2154ULL: goto x86_l_86a;
	case 2157ULL: goto x86_l_86d;
	case 2161ULL: goto x86_l_871;
	case 2167ULL: goto x86_l_877;
	case 2174ULL: goto x86_l_87e;
	case 2180ULL: goto x86_l_884;
	case 2184ULL: goto x86_l_888;
	case 2187ULL: goto x86_l_88b;
	case 2191ULL: goto x86_l_88f;
	case 2197ULL: goto x86_l_895;
	case 2204ULL: goto x86_l_89c;
	case 2210ULL: goto x86_l_8a2;
	case 2214ULL: goto x86_l_8a6;
	case 2217ULL: goto x86_l_8a9;
	case 2221ULL: goto x86_l_8ad;
	case 2227ULL: goto x86_l_8b3;
	case 2234ULL: goto x86_l_8ba;
	case 2240ULL: goto x86_l_8c0;
	case 2244ULL: goto x86_l_8c4;
	case 2247ULL: goto x86_l_8c7;
	case 2251ULL: goto x86_l_8cb;
	case 2257ULL: goto x86_l_8d1;
	case 2264ULL: goto x86_l_8d8;
	case 2270ULL: goto x86_l_8de;
	case 2274ULL: goto x86_l_8e2;
	case 2277ULL: goto x86_l_8e5;
	case 2281ULL: goto x86_l_8e9;
	case 2287ULL: goto x86_l_8ef;
	case 2294ULL: goto x86_l_8f6;
	case 2300ULL: goto x86_l_8fc;
	case 2304ULL: goto x86_l_900;
	case 2307ULL: goto x86_l_903;
	case 2311ULL: goto x86_l_907;
	case 2317ULL: goto x86_l_90d;
	case 2324ULL: goto x86_l_914;
	case 2330ULL: goto x86_l_91a;
	case 2334ULL: goto x86_l_91e;
	case 2337ULL: goto x86_l_921;
	case 2341ULL: goto x86_l_925;
	case 2347ULL: goto x86_l_92b;
	case 2354ULL: goto x86_l_932;
	case 2360ULL: goto x86_l_938;
	case 2364ULL: goto x86_l_93c;
	case 2367ULL: goto x86_l_93f;
	case 2371ULL: goto x86_l_943;
	case 2377ULL: goto x86_l_949;
	case 2384ULL: goto x86_l_950;
	case 2390ULL: goto x86_l_956;
	case 2394ULL: goto x86_l_95a;
	case 2397ULL: goto x86_l_95d;
	case 2401ULL: goto x86_l_961;
	case 2407ULL: goto x86_l_967;
	case 2414ULL: goto x86_l_96e;
	case 2420ULL: goto x86_l_974;
	case 2424ULL: goto x86_l_978;
	case 2427ULL: goto x86_l_97b;
	case 2431ULL: goto x86_l_97f;
	case 2437ULL: goto x86_l_985;
	case 2444ULL: goto x86_l_98c;
	case 2450ULL: goto x86_l_992;
	case 2454ULL: goto x86_l_996;
	case 2457ULL: goto x86_l_999;
	case 2461ULL: goto x86_l_99d;
	case 2467ULL: goto x86_l_9a3;
	case 2474ULL: goto x86_l_9aa;
	case 2480ULL: goto x86_l_9b0;
	case 2484ULL: goto x86_l_9b4;
	case 2487ULL: goto x86_l_9b7;
	case 2491ULL: goto x86_l_9bb;
	case 2497ULL: goto x86_l_9c1;
	case 2504ULL: goto x86_l_9c8;
	case 2510ULL: goto x86_l_9ce;
	case 2514ULL: goto x86_l_9d2;
	case 2517ULL: goto x86_l_9d5;
	case 2521ULL: goto x86_l_9d9;
	case 2527ULL: goto x86_l_9df;
	case 2534ULL: goto x86_l_9e6;
	case 2540ULL: goto x86_l_9ec;
	case 2544ULL: goto x86_l_9f0;
	case 2547ULL: goto x86_l_9f3;
	case 2551ULL: goto x86_l_9f7;
	case 2557ULL: goto x86_l_9fd;
	case 2564ULL: goto x86_l_a04;
	case 2570ULL: goto x86_l_a0a;
	case 2574ULL: goto x86_l_a0e;
	case 2577ULL: goto x86_l_a11;
	case 2581ULL: goto x86_l_a15;
	case 2587ULL: goto x86_l_a1b;
	case 2594ULL: goto x86_l_a22;
	case 2600ULL: goto x86_l_a28;
	case 2604ULL: goto x86_l_a2c;
	case 2607ULL: goto x86_l_a2f;
	case 2611ULL: goto x86_l_a33;
	case 2617ULL: goto x86_l_a39;
	case 2624ULL: goto x86_l_a40;
	case 2630ULL: goto x86_l_a46;
	case 2634ULL: goto x86_l_a4a;
	case 2637ULL: goto x86_l_a4d;
	case 2641ULL: goto x86_l_a51;
	case 2647ULL: goto x86_l_a57;
	case 2654ULL: goto x86_l_a5e;
	case 2660ULL: goto x86_l_a64;
	case 2664ULL: goto x86_l_a68;
	case 2667ULL: goto x86_l_a6b;
	case 2671ULL: goto x86_l_a6f;
	case 2677ULL: goto x86_l_a75;
	case 2684ULL: goto x86_l_a7c;
	case 2690ULL: goto x86_l_a82;
	case 2694ULL: goto x86_l_a86;
	case 2697ULL: goto x86_l_a89;
	case 2701ULL: goto x86_l_a8d;
	case 2707ULL: goto x86_l_a93;
	case 2714ULL: goto x86_l_a9a;
	case 2720ULL: goto x86_l_aa0;
	case 2724ULL: goto x86_l_aa4;
	case 2727ULL: goto x86_l_aa7;
	case 2731ULL: goto x86_l_aab;
	case 2737ULL: goto x86_l_ab1;
	case 2744ULL: goto x86_l_ab8;
	case 2750ULL: goto x86_l_abe;
	case 2754ULL: goto x86_l_ac2;
	case 2757ULL: goto x86_l_ac5;
	case 2761ULL: goto x86_l_ac9;
	case 2767ULL: goto x86_l_acf;
	case 2774ULL: goto x86_l_ad6;
	case 2780ULL: goto x86_l_adc;
	case 2784ULL: goto x86_l_ae0;
	case 2787ULL: goto x86_l_ae3;
	case 2791ULL: goto x86_l_ae7;
	case 2797ULL: goto x86_l_aed;
	case 2804ULL: goto x86_l_af4;
	case 2810ULL: goto x86_l_afa;
	case 2814ULL: goto x86_l_afe;
	case 2817ULL: goto x86_l_b01;
	case 2821ULL: goto x86_l_b05;
	case 2827ULL: goto x86_l_b0b;
	case 2834ULL: goto x86_l_b12;
	case 2840ULL: goto x86_l_b18;
	case 2844ULL: goto x86_l_b1c;
	case 2847ULL: goto x86_l_b1f;
	case 2851ULL: goto x86_l_b23;
	case 2857ULL: goto x86_l_b29;
	case 2864ULL: goto x86_l_b30;
	case 2870ULL: goto x86_l_b36;
	case 2874ULL: goto x86_l_b3a;
	case 2877ULL: goto x86_l_b3d;
	case 2881ULL: goto x86_l_b41;
	case 2887ULL: goto x86_l_b47;
	case 2894ULL: goto x86_l_b4e;
	case 2900ULL: goto x86_l_b54;
	case 2904ULL: goto x86_l_b58;
	case 2907ULL: goto x86_l_b5b;
	case 2911ULL: goto x86_l_b5f;
	case 2917ULL: goto x86_l_b65;
	case 2924ULL: goto x86_l_b6c;
	case 2930ULL: goto x86_l_b72;
	case 2934ULL: goto x86_l_b76;
	case 2937ULL: goto x86_l_b79;
	case 2941ULL: goto x86_l_b7d;
	case 2947ULL: goto x86_l_b83;
	case 2954ULL: goto x86_l_b8a;
	case 2960ULL: goto x86_l_b90;
	case 2964ULL: goto x86_l_b94;
	case 2967ULL: goto x86_l_b97;
	case 2971ULL: goto x86_l_b9b;
	case 2977ULL: goto x86_l_ba1;
	case 2984ULL: goto x86_l_ba8;
	case 2990ULL: goto x86_l_bae;
	case 2994ULL: goto x86_l_bb2;
	case 2997ULL: goto x86_l_bb5;
	case 3001ULL: goto x86_l_bb9;
	case 3007ULL: goto x86_l_bbf;
	case 3014ULL: goto x86_l_bc6;
	case 3020ULL: goto x86_l_bcc;
	case 3024ULL: goto x86_l_bd0;
	case 3027ULL: goto x86_l_bd3;
	case 3031ULL: goto x86_l_bd7;
	case 3037ULL: goto x86_l_bdd;
	case 3044ULL: goto x86_l_be4;
	case 3050ULL: goto x86_l_bea;
	case 3054ULL: goto x86_l_bee;
	case 3057ULL: goto x86_l_bf1;
	case 3061ULL: goto x86_l_bf5;
	case 3067ULL: goto x86_l_bfb;
	case 3074ULL: goto x86_l_c02;
	case 3080ULL: goto x86_l_c08;
	case 3084ULL: goto x86_l_c0c;
	case 3087ULL: goto x86_l_c0f;
	case 3091ULL: goto x86_l_c13;
	case 3097ULL: goto x86_l_c19;
	case 3104ULL: goto x86_l_c20;
	case 3110ULL: goto x86_l_c26;
	case 3114ULL: goto x86_l_c2a;
	case 3117ULL: goto x86_l_c2d;
	case 3121ULL: goto x86_l_c31;
	case 3127ULL: goto x86_l_c37;
	case 3134ULL: goto x86_l_c3e;
	case 3140ULL: goto x86_l_c44;
	case 3144ULL: goto x86_l_c48;
	case 3147ULL: goto x86_l_c4b;
	case 3151ULL: goto x86_l_c4f;
	case 3157ULL: goto x86_l_c55;
	case 3164ULL: goto x86_l_c5c;
	case 3170ULL: goto x86_l_c62;
	case 3174ULL: goto x86_l_c66;
	case 3177ULL: goto x86_l_c69;
	case 3181ULL: goto x86_l_c6d;
	case 3183ULL: goto x86_l_c6f;
	case 3190ULL: goto x86_l_c76;
	case 3196ULL: goto x86_l_c7c;
	case 3200ULL: goto x86_l_c80;
	case 3203ULL: goto x86_l_c83;
	case 3207ULL: goto x86_l_c87;
	case 3209ULL: goto x86_l_c89;
	case 3216ULL: goto x86_l_c90;
	case 3222ULL: goto x86_l_c96;
	case 3226ULL: goto x86_l_c9a;
	case 3229ULL: goto x86_l_c9d;
	case 3233ULL: goto x86_l_ca1;
	case 3235ULL: goto x86_l_ca3;
	case 3242ULL: goto x86_l_caa;
	case 3248ULL: goto x86_l_cb0;
	case 3252ULL: goto x86_l_cb4;
	case 3255ULL: goto x86_l_cb7;
	case 3259ULL: goto x86_l_cbb;
	case 3261ULL: goto x86_l_cbd;
	case 3268ULL: goto x86_l_cc4;
	case 3275ULL: goto x86_l_ccb;
	case 3280ULL: goto x86_l_cd0;
	case 3283ULL: goto x86_l_cd3;
	case 3288ULL: goto x86_l_cd8;
	case 3291ULL: goto x86_l_cdb;
	case 3294ULL: goto x86_l_cde;
	case 3299ULL: goto x86_l_ce3;
	case 3302ULL: goto x86_l_ce6;
	case 3305ULL: goto x86_l_ce9;
	case 3311ULL: goto x86_l_cef;
	case 3314ULL: goto x86_l_cf2;
	case 3316ULL: goto x86_l_cf4;
	case 3321ULL: goto x86_l_cf9;
	case 3324ULL: goto x86_l_cfc;
	case 3327ULL: goto x86_l_cff;
	case 3329ULL: goto x86_l_d01;
	case 3338ULL: goto x86_l_d0a;
	case 3347ULL: goto x86_l_d13;
	case 3356ULL: goto x86_l_d1c;
	case 3365ULL: goto x86_l_d25;
	case 3374ULL: goto x86_l_d2e;
	case 3377ULL: goto x86_l_d31;
	case 3380ULL: goto x86_l_d34;
	case 3382ULL: goto x86_l_d36;
	case 3385ULL: goto x86_l_d39;
	case 3391ULL: goto x86_l_d3f;
	case 3394ULL: goto x86_l_d42;
	case 3397ULL: goto x86_l_d45;
	case 3403ULL: goto x86_l_d4b;
	case 3408ULL: goto x86_l_d50;
	case 3411ULL: goto x86_l_d53;
	case 3417ULL: goto x86_l_d59;
	case 3420ULL: goto x86_l_d5c;
	case 3423ULL: goto x86_l_d5f;
	case 3429ULL: goto x86_l_d65;
	case 3434ULL: goto x86_l_d6a;
	case 3437ULL: goto x86_l_d6d;
	case 3443ULL: goto x86_l_d73;
	case 3447ULL: goto x86_l_d77;
	case 3449ULL: goto x86_l_d79;
	case 3452ULL: goto x86_l_d7c;
	case 3458ULL: goto x86_l_d82;
	case 3461ULL: goto x86_l_d85;
	case 3464ULL: goto x86_l_d88;
	case 3467ULL: goto x86_l_d8b;
	case 3469ULL: goto x86_l_d8d;
	case 3471ULL: goto x86_l_d8f;
	case 3474ULL: goto x86_l_d92;
	case 3477ULL: goto x86_l_d95;
	case 3483ULL: goto x86_l_d9b;
	case 3486ULL: goto x86_l_d9e;
	case 3492ULL: goto x86_l_da4;
	case 3494ULL: goto x86_l_da6;
	case 3499ULL: goto x86_l_dab;
	case 3503ULL: goto x86_l_daf;
	case 3509ULL: goto x86_l_db5;
	case 3514ULL: goto x86_l_dba;
	case 3518ULL: goto x86_l_dbe;
	case 3524ULL: goto x86_l_dc4;
	case 3534ULL: goto x86_l_dce;
	case 3538ULL: goto x86_l_dd2;
	case 3544ULL: goto x86_l_dd8;
	case 3551ULL: goto x86_l_ddf;
	case 3558ULL: goto x86_l_de6;
	case 3564ULL: goto x86_l_dec;
	case 3569ULL: goto x86_l_df1;
	case 3571ULL: goto x86_l_df3;
	case 3575ULL: goto x86_l_df7;
	case 3579ULL: goto x86_l_dfb;
	case 3584ULL: goto x86_l_e00;
	case 3587ULL: goto x86_l_e03;
	case 3592ULL: goto x86_l_e08;
	case 3594ULL: goto x86_l_e0a;
	case 3597ULL: goto x86_l_e0d;
	case 3601ULL: goto x86_l_e11;
	case 3603ULL: goto x86_l_e13;
	case 3609ULL: goto x86_l_e19;
	case 3614ULL: goto x86_l_e1e;
	case 3619ULL: goto x86_l_e23;
	case 3625ULL: goto x86_l_e29;
	case 3627ULL: goto x86_l_e2b;
	case 3633ULL: goto x86_l_e31;
	case 3636ULL: goto x86_l_e34;
	case 3639ULL: goto x86_l_e37;
	case 3645ULL: goto x86_l_e3d;
	case 3649ULL: goto x86_l_e41;
	case 3651ULL: goto x86_l_e43;
	case 3657ULL: goto x86_l_e49;
	case 3659ULL: goto x86_l_e4b;
	case 3665ULL: goto x86_l_e51;
	case 3668ULL: goto x86_l_e54;
	case 3674ULL: goto x86_l_e5a;
	case 3678ULL: goto x86_l_e5e;
	case 3680ULL: goto x86_l_e60;
	case 3686ULL: goto x86_l_e66;
	case 3688ULL: goto x86_l_e68;
	case 3691ULL: goto x86_l_e6b;
	case 3697ULL: goto x86_l_e71;
	case 3700ULL: goto x86_l_e74;
	default: return 0xffffffffffffffffULL;
	}
x86_l_745:
	/* 0x745: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_74b:
	/* 0x74b: lea    ecx,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_752:
	/* 0x752: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_758:
	/* 0x758: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_75c:
	/* 0x75c: mov    BYTE PTR [rax+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_75f:
	/* 0x75f: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_763:
	/* 0x763: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_769:
	/* 0x769: lea    ecx,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_770:
	/* 0x770: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_776:
	/* 0x776: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_77a:
	/* 0x77a: mov    BYTE PTR [rax+0x33],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_77d:
	/* 0x77d: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_781:
	/* 0x781: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_787:
	/* 0x787: lea    ecx,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_78e:
	/* 0x78e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_794:
	/* 0x794: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_798:
	/* 0x798: mov    BYTE PTR [rax+0x34],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_79b:
	/* 0x79b: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_79f:
	/* 0x79f: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_7a5:
	/* 0x7a5: lea    ecx,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_7ac:
	/* 0x7ac: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7b2:
	/* 0x7b2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_7b6:
	/* 0x7b6: mov    BYTE PTR [rax+0x35],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_7b9:
	/* 0x7b9: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_7bd:
	/* 0x7bd: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_7c3:
	/* 0x7c3: lea    ecx,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_7ca:
	/* 0x7ca: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7d0:
	/* 0x7d0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_7d4:
	/* 0x7d4: mov    BYTE PTR [rax+0x36],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_7d7:
	/* 0x7d7: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_7db:
	/* 0x7db: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_7e1:
	/* 0x7e1: lea    ecx,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_7e8:
	/* 0x7e8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7ee:
	/* 0x7ee: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_7f2:
	/* 0x7f2: mov    BYTE PTR [rax+0x37],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_7f5:
	/* 0x7f5: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_7f9:
	/* 0x7f9: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_7ff:
	/* 0x7ff: lea    ecx,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_806:
	/* 0x806: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_80c:
	/* 0x80c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_810:
	/* 0x810: mov    BYTE PTR [rax+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_813:
	/* 0x813: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_817:
	/* 0x817: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_81d:
	/* 0x81d: lea    ecx,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_824:
	/* 0x824: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_82a:
	/* 0x82a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_82e:
	/* 0x82e: mov    BYTE PTR [rax+0x39],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_831:
	/* 0x831: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_835:
	/* 0x835: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_83b:
	/* 0x83b: lea    ecx,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_842:
	/* 0x842: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_848:
	/* 0x848: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_84c:
	/* 0x84c: mov    BYTE PTR [rax+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_84f:
	/* 0x84f: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_853:
	/* 0x853: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_859:
	/* 0x859: lea    ecx,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_860:
	/* 0x860: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_866:
	/* 0x866: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_86a:
	/* 0x86a: mov    BYTE PTR [rax+0x3b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_86d:
	/* 0x86d: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_871:
	/* 0x871: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_877:
	/* 0x877: lea    ecx,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_87e:
	/* 0x87e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_884:
	/* 0x884: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_888:
	/* 0x888: mov    BYTE PTR [rax+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_88b:
	/* 0x88b: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_88f:
	/* 0x88f: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_895:
	/* 0x895: lea    ecx,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_89c:
	/* 0x89c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8a2:
	/* 0x8a2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8a6:
	/* 0x8a6: mov    BYTE PTR [rax+0x3d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_8a9:
	/* 0x8a9: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_8ad:
	/* 0x8ad: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_8b3:
	/* 0x8b3: lea    ecx,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_8ba:
	/* 0x8ba: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8c0:
	/* 0x8c0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8c4:
	/* 0x8c4: mov    BYTE PTR [rax+0x3e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_8c7:
	/* 0x8c7: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_8cb:
	/* 0x8cb: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_8d1:
	/* 0x8d1: lea    ecx,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_8d8:
	/* 0x8d8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8de:
	/* 0x8de: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8e2:
	/* 0x8e2: mov    BYTE PTR [rax+0x3f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_8e5:
	/* 0x8e5: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_8e9:
	/* 0x8e9: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_8ef:
	/* 0x8ef: lea    ecx,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_8f6:
	/* 0x8f6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8fc:
	/* 0x8fc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_900:
	/* 0x900: mov    BYTE PTR [rax+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_903:
	/* 0x903: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_907:
	/* 0x907: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_90d:
	/* 0x90d: lea    ecx,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_914:
	/* 0x914: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_91a:
	/* 0x91a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_91e:
	/* 0x91e: mov    BYTE PTR [rax+0x41],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_921:
	/* 0x921: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_925:
	/* 0x925: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_92b:
	/* 0x92b: lea    ecx,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_932:
	/* 0x932: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_938:
	/* 0x938: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_93c:
	/* 0x93c: mov    BYTE PTR [rax+0x42],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_93f:
	/* 0x93f: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_943:
	/* 0x943: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_949:
	/* 0x949: lea    ecx,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_950:
	/* 0x950: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_956:
	/* 0x956: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_95a:
	/* 0x95a: mov    BYTE PTR [rax+0x43],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_95d:
	/* 0x95d: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_961:
	/* 0x961: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_967:
	/* 0x967: lea    ecx,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_96e:
	/* 0x96e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_974:
	/* 0x974: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_978:
	/* 0x978: mov    BYTE PTR [rax+0x44],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_97b:
	/* 0x97b: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_97f:
	/* 0x97f: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_985:
	/* 0x985: lea    ecx,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_98c:
	/* 0x98c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_992:
	/* 0x992: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_996:
	/* 0x996: mov    BYTE PTR [rax+0x45],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_999:
	/* 0x999: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_99d:
	/* 0x99d: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_9a3:
	/* 0x9a3: lea    ecx,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_9aa:
	/* 0x9aa: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9b0:
	/* 0x9b0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_9b4:
	/* 0x9b4: mov    BYTE PTR [rax+0x46],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_9b7:
	/* 0x9b7: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_9bb:
	/* 0x9bb: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_9c1:
	/* 0x9c1: lea    ecx,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_9c8:
	/* 0x9c8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9ce:
	/* 0x9ce: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_9d2:
	/* 0x9d2: mov    BYTE PTR [rax+0x47],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_9d5:
	/* 0x9d5: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_9d9:
	/* 0x9d9: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_9df:
	/* 0x9df: lea    ecx,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_9e6:
	/* 0x9e6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9ec:
	/* 0x9ec: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_9f0:
	/* 0x9f0: mov    BYTE PTR [rax+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9f3:
	/* 0x9f3: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_9f7:
	/* 0x9f7: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_9fd:
	/* 0x9fd: lea    ecx,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_a04:
	/* 0xa04: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a0a:
	/* 0xa0a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a0e:
	/* 0xa0e: mov    BYTE PTR [rax+0x49],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_a11:
	/* 0xa11: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_a15:
	/* 0xa15: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_a1b:
	/* 0xa1b: lea    ecx,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_a22:
	/* 0xa22: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a28:
	/* 0xa28: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a2c:
	/* 0xa2c: mov    BYTE PTR [rax+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_a2f:
	/* 0xa2f: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_a33:
	/* 0xa33: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_a39:
	/* 0xa39: lea    ecx,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_a40:
	/* 0xa40: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a46:
	/* 0xa46: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a4a:
	/* 0xa4a: mov    BYTE PTR [rax+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_a4d:
	/* 0xa4d: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_a51:
	/* 0xa51: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_a57:
	/* 0xa57: lea    ecx,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_a5e:
	/* 0xa5e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a64:
	/* 0xa64: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a68:
	/* 0xa68: mov    BYTE PTR [rax+0x4c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_a6b:
	/* 0xa6b: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_a6f:
	/* 0xa6f: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_a75:
	/* 0xa75: lea    ecx,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_a7c:
	/* 0xa7c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a82:
	/* 0xa82: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a86:
	/* 0xa86: mov    BYTE PTR [rax+0x4d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_a89:
	/* 0xa89: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_a8d:
	/* 0xa8d: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_a93:
	/* 0xa93: lea    ecx,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_a9a:
	/* 0xa9a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_aa0:
	/* 0xaa0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_aa4:
	/* 0xaa4: mov    BYTE PTR [rax+0x4e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_aa7:
	/* 0xaa7: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_aab:
	/* 0xaab: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_ab1:
	/* 0xab1: lea    ecx,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_ab8:
	/* 0xab8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_abe:
	/* 0xabe: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ac2:
	/* 0xac2: mov    BYTE PTR [rax+0x4f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_ac5:
	/* 0xac5: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_ac9:
	/* 0xac9: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_acf:
	/* 0xacf: lea    ecx,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_ad6:
	/* 0xad6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_adc:
	/* 0xadc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ae0:
	/* 0xae0: mov    BYTE PTR [rax+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ae3:
	/* 0xae3: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_ae7:
	/* 0xae7: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_aed:
	/* 0xaed: lea    ecx,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_af4:
	/* 0xaf4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_afa:
	/* 0xafa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_afe:
	/* 0xafe: mov    BYTE PTR [rax+0x51],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_b01:
	/* 0xb01: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_b05:
	/* 0xb05: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_b0b:
	/* 0xb0b: lea    ecx,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_b12:
	/* 0xb12: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b18:
	/* 0xb18: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b1c:
	/* 0xb1c: mov    BYTE PTR [rax+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_b1f:
	/* 0xb1f: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_b23:
	/* 0xb23: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_b29:
	/* 0xb29: lea    ecx,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_b30:
	/* 0xb30: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b36:
	/* 0xb36: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b3a:
	/* 0xb3a: mov    BYTE PTR [rax+0x53],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_b3d:
	/* 0xb3d: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_b41:
	/* 0xb41: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_b47:
	/* 0xb47: lea    ecx,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_b4e:
	/* 0xb4e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b54:
	/* 0xb54: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b58:
	/* 0xb58: mov    BYTE PTR [rax+0x54],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_b5b:
	/* 0xb5b: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_b5f:
	/* 0xb5f: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_b65:
	/* 0xb65: lea    ecx,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_b6c:
	/* 0xb6c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b72:
	/* 0xb72: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b76:
	/* 0xb76: mov    BYTE PTR [rax+0x55],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_b79:
	/* 0xb79: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_b7d:
	/* 0xb7d: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_b83:
	/* 0xb83: lea    ecx,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_b8a:
	/* 0xb8a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b90:
	/* 0xb90: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b94:
	/* 0xb94: mov    BYTE PTR [rax+0x56],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_b97:
	/* 0xb97: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_b9b:
	/* 0xb9b: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_ba1:
	/* 0xba1: lea    ecx,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_ba8:
	/* 0xba8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bae:
	/* 0xbae: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_bb2:
	/* 0xbb2: mov    BYTE PTR [rax+0x57],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_bb5:
	/* 0xbb5: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_bb9:
	/* 0xbb9: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_bbf:
	/* 0xbbf: lea    ecx,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_bc6:
	/* 0xbc6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bcc:
	/* 0xbcc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_bd0:
	/* 0xbd0: mov    BYTE PTR [rax+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bd3:
	/* 0xbd3: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_bd7:
	/* 0xbd7: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_bdd:
	/* 0xbdd: lea    ecx,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_be4:
	/* 0xbe4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bea:
	/* 0xbea: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_bee:
	/* 0xbee: mov    BYTE PTR [rax+0x59],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_bf1:
	/* 0xbf1: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_bf5:
	/* 0xbf5: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_bfb:
	/* 0xbfb: lea    ecx,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_c02:
	/* 0xc02: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c08:
	/* 0xc08: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c0c:
	/* 0xc0c: mov    BYTE PTR [rax+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_c0f:
	/* 0xc0f: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_c13:
	/* 0xc13: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_c19:
	/* 0xc19: lea    ecx,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_c20:
	/* 0xc20: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c26:
	/* 0xc26: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c2a:
	/* 0xc2a: mov    BYTE PTR [rax+0x5b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_c2d:
	/* 0xc2d: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_c31:
	/* 0xc31: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_c37:
	/* 0xc37: lea    ecx,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_c3e:
	/* 0xc3e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c44:
	/* 0xc44: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c48:
	/* 0xc48: mov    BYTE PTR [rax+0x5c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_c4b:
	/* 0xc4b: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_c4f:
	/* 0xc4f: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_c55:
	/* 0xc55: lea    ecx,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_c5c:
	/* 0xc5c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c62:
	/* 0xc62: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c66:
	/* 0xc66: mov    BYTE PTR [rax+0x5d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_c69:
	/* 0xc69: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_c6d:
	/* 0xc6d: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_c6f:
	/* 0xc6f: lea    ecx,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_c76:
	/* 0xc76: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c7c:
	/* 0xc7c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c80:
	/* 0xc80: mov    BYTE PTR [rax+0x5e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_c83:
	/* 0xc83: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_c87:
	/* 0xc87: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_c89:
	/* 0xc89: lea    ecx,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_c90:
	/* 0xc90: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c96:
	/* 0xc96: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c9a:
	/* 0xc9a: mov    BYTE PTR [rax+0x5f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_c9d:
	/* 0xc9d: cmp    r13,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 92ULL);
x86_l_ca1:
	/* 0xca1: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_ca3:
	/* 0xca3: lea    ecx,[r13+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_caa:
	/* 0xcaa: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_cb0:
	/* 0xcb0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_cb4:
	/* 0xcb4: mov    BYTE PTR [rax+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cb7:
	/* 0xcb7: cmp    r13,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 93ULL);
x86_l_cbb:
	/* 0xcbb: je     cd3 <generic_retuprobe_filter_arg_2+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd3;
	}
x86_l_cbd:
	/* 0xcbd: add    r13d,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_cc4:
	/* 0xcc4: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ccb:
	/* 0xccb: movzx  ecx,BYTE PTR [rdx+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_cd0:
	/* 0xcd0: mov    BYTE PTR [rax+0x61],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_cd3:
	/* 0xcd3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cd8:
	/* 0xcd8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_cdb:
	/* 0xcdb: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_cde:
	/* 0xcde: jmp    324d <generic_retuprobe_filter_arg_2+0x324d> */
	return 12877ULL;
x86_l_ce3:
	/* 0xce3: lea    eax,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_ce6:
	/* 0xce6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ce9:
	/* 0xce9: jb     d82 <generic_retuprobe_filter_arg_2+0xd82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d82;
	}
x86_l_cef:
	/* 0xcef: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_cf2:
	/* 0xcf2: je     d01 <generic_retuprobe_filter_arg_2+0xd01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d01;
	}
x86_l_cf4:
	/* 0xcf4: jmp    3285 <generic_retuprobe_filter_arg_2+0x3285> */
	return 12933ULL;
x86_l_cf9:
	/* 0xcf9: lea    eax,[rcx-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_cfc:
	/* 0xcfc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cff:
	/* 0xcff: jae    d79 <generic_retuprobe_filter_arg_2+0xd79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_d79;
	}
x86_l_d01:
	/* 0xd01: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_d0a:
	/* 0xd0a: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_d13:
	/* 0xd13: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_d1c:
	/* 0xd1c: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_d25:
	/* 0xd25: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_d2e:
	/* 0xd2e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d31:
	/* 0xd31: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_d34:
	/* 0xd34: jg     d50 <generic_retuprobe_filter_arg_2+0xd50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d50;
	}
x86_l_d36:
	/* 0xd36: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d39:
	/* 0xd39: je     1bbd <generic_retuprobe_filter_arg_2+0x1bbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7101ULL;
	}
x86_l_d3f:
	/* 0xd3f: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_d42:
	/* 0xd42: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_d45:
	/* 0xd45: je     1bbf <generic_retuprobe_filter_arg_2+0x1bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7103ULL;
	}
x86_l_d4b:
	/* 0xd4b: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	return 12928ULL;
x86_l_d50:
	/* 0xd50: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_d53:
	/* 0xd53: je     1b95 <generic_retuprobe_filter_arg_2+0x1b95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7061ULL;
	}
x86_l_d59:
	/* 0xd59: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_d5c:
	/* 0xd5c: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_d5f:
	/* 0xd5f: je     1bbf <generic_retuprobe_filter_arg_2+0x1bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7103ULL;
	}
x86_l_d65:
	/* 0xd65: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	return 12928ULL;
x86_l_d6a:
	/* 0xd6a: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_d6d:
	/* 0xd6d: jne    3285 <generic_retuprobe_filter_arg_2+0x3285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12933ULL;
	}
x86_l_d73:
	/* 0xd73: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_d77:
	/* 0xd77: jmp    d82 <generic_retuprobe_filter_arg_2+0xd82> */
	goto x86_l_d82;
x86_l_d79:
	/* 0xd79: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_d7c:
	/* 0xd7c: jne    3285 <generic_retuprobe_filter_arg_2+0x3285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12933ULL;
	}
x86_l_d82:
	/* 0xd82: mov    r13d,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d85:
	/* 0xd85: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d88:
	/* 0xd88: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_d8b:
	/* 0xd8b: jne    d9b <generic_retuprobe_filter_arg_2+0xd9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d9b;
	}
x86_l_d8d:
	/* 0xd8d: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d8f:
	/* 0xd8f: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_d92:
	/* 0xd92: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_d95:
	/* 0xd95: jne    328f <generic_retuprobe_filter_arg_2+0x328f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12943ULL;
	}
x86_l_d9b:
	/* 0xd9b: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_d9e:
	/* 0xd9e: ja     1c36 <generic_retuprobe_filter_arg_2+0x1c36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7222ULL;
	}
x86_l_da4:
	/* 0xda4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_da6:
	/* 0xda6: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_dab:
	/* 0xdab: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_daf:
	/* 0xdaf: jb     27f9 <generic_retuprobe_filter_arg_2+0x27f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10233ULL;
	}
x86_l_db5:
	/* 0xdb5: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_dba:
	/* 0xdba: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_dbe:
	/* 0xdbe: jb     1c7f <generic_retuprobe_filter_arg_2+0x1c7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7295ULL;
	}
x86_l_dc4:
	/* 0xdc4: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_dce:
	/* 0xdce: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_dd2:
	/* 0xdd2: jae    1c36 <generic_retuprobe_filter_arg_2+0x1c36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7222ULL;
	}
x86_l_dd8:
	/* 0xdd8: mov    WORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_ddf:
	/* 0xddf: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_de6:
	/* 0xde6: ja     1c57 <generic_retuprobe_filter_arg_2+0x1c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7255ULL;
	}
x86_l_dec:
	/* 0xdec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_df1:
	/* 0xdf1: mov    ecx,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df3:
	/* 0xdf3: lea    rdx,[rdi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_df7:
	/* 0xdf7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_dfb:
	/* 0xdfb: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e00:
	/* 0xe00: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_e03:
	/* 0xe03: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e08:
	/* 0xe08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0a:
	/* 0xe0a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_e0d:
	/* 0xe0d: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e11:
	/* 0xe11: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e13:
	/* 0xe13: je     1c57 <generic_retuprobe_filter_arg_2+0x1c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7255ULL;
	}
x86_l_e19:
	/* 0xe19: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_e1e:
	/* 0xe1e: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_e23:
	/* 0xe23: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_e29:
	/* 0xe29: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e2b:
	/* 0xe2b: je     31d7 <generic_retuprobe_filter_arg_2+0x31d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12759ULL;
	}
x86_l_e31:
	/* 0xe31: mov    ecx,DWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e34:
	/* 0xe34: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_e37:
	/* 0xe37: jbe    30b4 <generic_retuprobe_filter_arg_2+0x30b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 12468ULL;
	}
x86_l_e3d:
	/* 0xe3d: mov    edx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_e41:
	/* 0xe41: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_e43:
	/* 0xe43: je     30b4 <generic_retuprobe_filter_arg_2+0x30b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12468ULL;
	}
x86_l_e49:
	/* 0xe49: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e4b:
	/* 0xe4b: je     30b7 <generic_retuprobe_filter_arg_2+0x30b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12471ULL;
	}
x86_l_e51:
	/* 0xe51: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_e54:
	/* 0xe54: jb     30b4 <generic_retuprobe_filter_arg_2+0x30b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12468ULL;
	}
x86_l_e5a:
	/* 0xe5a: mov    edx,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e5e:
	/* 0xe5e: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_e60:
	/* 0xe60: je     30b4 <generic_retuprobe_filter_arg_2+0x30b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12468ULL;
	}
x86_l_e66:
	/* 0xe66: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e68:
	/* 0xe68: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_e6b:
	/* 0xe6b: je     31d7 <generic_retuprobe_filter_arg_2+0x31d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12759ULL;
	}
x86_l_e71:
	/* 0xe71: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_e74:
	/* 0xe74: jb     30b4 <generic_retuprobe_filter_arg_2+0x30b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12468ULL;
	}
	return 3706ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3706ULL: goto x86_l_e7a;
	case 3710ULL: goto x86_l_e7e;
	case 3712ULL: goto x86_l_e80;
	case 3718ULL: goto x86_l_e86;
	case 3721ULL: goto x86_l_e89;
	case 3723ULL: goto x86_l_e8b;
	case 3727ULL: goto x86_l_e8f;
	case 3732ULL: goto x86_l_e94;
	case 3735ULL: goto x86_l_e97;
	case 3738ULL: goto x86_l_e9a;
	case 3741ULL: goto x86_l_e9d;
	case 3747ULL: goto x86_l_ea3;
	case 3750ULL: goto x86_l_ea6;
	case 3754ULL: goto x86_l_eaa;
	case 3759ULL: goto x86_l_eaf;
	case 3762ULL: goto x86_l_eb2;
	case 3767ULL: goto x86_l_eb7;
	case 3773ULL: goto x86_l_ebd;
	case 3778ULL: goto x86_l_ec2;
	case 3781ULL: goto x86_l_ec5;
	case 3787ULL: goto x86_l_ecb;
	case 3792ULL: goto x86_l_ed0;
	case 3795ULL: goto x86_l_ed3;
	case 3801ULL: goto x86_l_ed9;
	case 3804ULL: goto x86_l_edc;
	case 3808ULL: goto x86_l_ee0;
	case 3811ULL: goto x86_l_ee3;
	case 3815ULL: goto x86_l_ee7;
	case 3823ULL: goto x86_l_eef;
	case 3828ULL: goto x86_l_ef4;
	case 3835ULL: goto x86_l_efb;
	case 3840ULL: goto x86_l_f00;
	case 3842ULL: goto x86_l_f02;
	case 3845ULL: goto x86_l_f05;
	case 3851ULL: goto x86_l_f0b;
	case 3857ULL: goto x86_l_f11;
	case 3862ULL: goto x86_l_f16;
	case 3865ULL: goto x86_l_f19;
	case 3871ULL: goto x86_l_f1f;
	case 3876ULL: goto x86_l_f24;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3890ULL: goto x86_l_f32;
	case 3893ULL: goto x86_l_f35;
	case 3899ULL: goto x86_l_f3b;
	case 3904ULL: goto x86_l_f40;
	case 3907ULL: goto x86_l_f43;
	case 3912ULL: goto x86_l_f48;
	case 3915ULL: goto x86_l_f4b;
	case 3918ULL: goto x86_l_f4e;
	case 3920ULL: goto x86_l_f50;
	case 3923ULL: goto x86_l_f53;
	case 3929ULL: goto x86_l_f59;
	case 3935ULL: goto x86_l_f5f;
	case 3938ULL: goto x86_l_f62;
	case 3942ULL: goto x86_l_f66;
	case 3948ULL: goto x86_l_f6c;
	case 3954ULL: goto x86_l_f72;
	case 3960ULL: goto x86_l_f78;
	case 3966ULL: goto x86_l_f7e;
	case 3969ULL: goto x86_l_f81;
	case 3973ULL: goto x86_l_f85;
	case 3979ULL: goto x86_l_f8b;
	case 3985ULL: goto x86_l_f91;
	case 3991ULL: goto x86_l_f97;
	case 3997ULL: goto x86_l_f9d;
	case 4000ULL: goto x86_l_fa0;
	case 4004ULL: goto x86_l_fa4;
	case 4010ULL: goto x86_l_faa;
	case 4016ULL: goto x86_l_fb0;
	case 4022ULL: goto x86_l_fb6;
	case 4028ULL: goto x86_l_fbc;
	case 4031ULL: goto x86_l_fbf;
	case 4035ULL: goto x86_l_fc3;
	case 4041ULL: goto x86_l_fc9;
	case 4047ULL: goto x86_l_fcf;
	case 4053ULL: goto x86_l_fd5;
	case 4059ULL: goto x86_l_fdb;
	case 4062ULL: goto x86_l_fde;
	case 4066ULL: goto x86_l_fe2;
	case 4072ULL: goto x86_l_fe8;
	case 4078ULL: goto x86_l_fee;
	case 4084ULL: goto x86_l_ff4;
	case 4090ULL: goto x86_l_ffa;
	case 4093ULL: goto x86_l_ffd;
	case 4097ULL: goto x86_l_1001;
	case 4103ULL: goto x86_l_1007;
	case 4109ULL: goto x86_l_100d;
	case 4115ULL: goto x86_l_1013;
	case 4121ULL: goto x86_l_1019;
	case 4124ULL: goto x86_l_101c;
	case 4128ULL: goto x86_l_1020;
	case 4134ULL: goto x86_l_1026;
	case 4140ULL: goto x86_l_102c;
	case 4146ULL: goto x86_l_1032;
	case 4152ULL: goto x86_l_1038;
	case 4155ULL: goto x86_l_103b;
	case 4159ULL: goto x86_l_103f;
	case 4165ULL: goto x86_l_1045;
	case 4171ULL: goto x86_l_104b;
	case 4177ULL: goto x86_l_1051;
	case 4183ULL: goto x86_l_1057;
	case 4186ULL: goto x86_l_105a;
	case 4190ULL: goto x86_l_105e;
	case 4196ULL: goto x86_l_1064;
	case 4202ULL: goto x86_l_106a;
	case 4208ULL: goto x86_l_1070;
	case 4214ULL: goto x86_l_1076;
	case 4217ULL: goto x86_l_1079;
	case 4221ULL: goto x86_l_107d;
	case 4227ULL: goto x86_l_1083;
	case 4233ULL: goto x86_l_1089;
	case 4239ULL: goto x86_l_108f;
	case 4245ULL: goto x86_l_1095;
	case 4248ULL: goto x86_l_1098;
	case 4252ULL: goto x86_l_109c;
	case 4258ULL: goto x86_l_10a2;
	case 4264ULL: goto x86_l_10a8;
	case 4270ULL: goto x86_l_10ae;
	case 4276ULL: goto x86_l_10b4;
	case 4279ULL: goto x86_l_10b7;
	case 4283ULL: goto x86_l_10bb;
	case 4289ULL: goto x86_l_10c1;
	case 4295ULL: goto x86_l_10c7;
	case 4301ULL: goto x86_l_10cd;
	case 4307ULL: goto x86_l_10d3;
	case 4310ULL: goto x86_l_10d6;
	case 4314ULL: goto x86_l_10da;
	case 4320ULL: goto x86_l_10e0;
	case 4326ULL: goto x86_l_10e6;
	case 4332ULL: goto x86_l_10ec;
	case 4338ULL: goto x86_l_10f2;
	case 4341ULL: goto x86_l_10f5;
	case 4345ULL: goto x86_l_10f9;
	case 4351ULL: goto x86_l_10ff;
	case 4357ULL: goto x86_l_1105;
	case 4363ULL: goto x86_l_110b;
	case 4369ULL: goto x86_l_1111;
	case 4372ULL: goto x86_l_1114;
	case 4376ULL: goto x86_l_1118;
	case 4382ULL: goto x86_l_111e;
	case 4388ULL: goto x86_l_1124;
	case 4394ULL: goto x86_l_112a;
	case 4400ULL: goto x86_l_1130;
	case 4403ULL: goto x86_l_1133;
	case 4407ULL: goto x86_l_1137;
	case 4413ULL: goto x86_l_113d;
	case 4419ULL: goto x86_l_1143;
	case 4425ULL: goto x86_l_1149;
	case 4431ULL: goto x86_l_114f;
	case 4434ULL: goto x86_l_1152;
	case 4438ULL: goto x86_l_1156;
	case 4444ULL: goto x86_l_115c;
	case 4450ULL: goto x86_l_1162;
	case 4456ULL: goto x86_l_1168;
	case 4462ULL: goto x86_l_116e;
	case 4465ULL: goto x86_l_1171;
	case 4469ULL: goto x86_l_1175;
	case 4475ULL: goto x86_l_117b;
	case 4481ULL: goto x86_l_1181;
	case 4487ULL: goto x86_l_1187;
	case 4493ULL: goto x86_l_118d;
	case 4496ULL: goto x86_l_1190;
	case 4500ULL: goto x86_l_1194;
	case 4506ULL: goto x86_l_119a;
	case 4512ULL: goto x86_l_11a0;
	case 4518ULL: goto x86_l_11a6;
	case 4524ULL: goto x86_l_11ac;
	case 4527ULL: goto x86_l_11af;
	case 4531ULL: goto x86_l_11b3;
	case 4537ULL: goto x86_l_11b9;
	case 4543ULL: goto x86_l_11bf;
	case 4549ULL: goto x86_l_11c5;
	case 4555ULL: goto x86_l_11cb;
	case 4558ULL: goto x86_l_11ce;
	case 4562ULL: goto x86_l_11d2;
	case 4568ULL: goto x86_l_11d8;
	case 4574ULL: goto x86_l_11de;
	case 4580ULL: goto x86_l_11e4;
	case 4586ULL: goto x86_l_11ea;
	case 4589ULL: goto x86_l_11ed;
	case 4593ULL: goto x86_l_11f1;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4611ULL: goto x86_l_1203;
	case 4617ULL: goto x86_l_1209;
	case 4620ULL: goto x86_l_120c;
	case 4624ULL: goto x86_l_1210;
	case 4630ULL: goto x86_l_1216;
	case 4636ULL: goto x86_l_121c;
	case 4642ULL: goto x86_l_1222;
	case 4648ULL: goto x86_l_1228;
	case 4651ULL: goto x86_l_122b;
	case 4655ULL: goto x86_l_122f;
	case 4661ULL: goto x86_l_1235;
	case 4667ULL: goto x86_l_123b;
	case 4673ULL: goto x86_l_1241;
	case 4679ULL: goto x86_l_1247;
	case 4682ULL: goto x86_l_124a;
	case 4686ULL: goto x86_l_124e;
	case 4692ULL: goto x86_l_1254;
	case 4698ULL: goto x86_l_125a;
	case 4704ULL: goto x86_l_1260;
	case 4710ULL: goto x86_l_1266;
	case 4713ULL: goto x86_l_1269;
	case 4717ULL: goto x86_l_126d;
	case 4723ULL: goto x86_l_1273;
	case 4729ULL: goto x86_l_1279;
	case 4735ULL: goto x86_l_127f;
	case 4741ULL: goto x86_l_1285;
	case 4744ULL: goto x86_l_1288;
	case 4748ULL: goto x86_l_128c;
	case 4754ULL: goto x86_l_1292;
	case 4760ULL: goto x86_l_1298;
	case 4766ULL: goto x86_l_129e;
	case 4772ULL: goto x86_l_12a4;
	case 4775ULL: goto x86_l_12a7;
	case 4779ULL: goto x86_l_12ab;
	case 4785ULL: goto x86_l_12b1;
	case 4791ULL: goto x86_l_12b7;
	case 4797ULL: goto x86_l_12bd;
	case 4803ULL: goto x86_l_12c3;
	case 4806ULL: goto x86_l_12c6;
	case 4810ULL: goto x86_l_12ca;
	case 4816ULL: goto x86_l_12d0;
	case 4822ULL: goto x86_l_12d6;
	case 4828ULL: goto x86_l_12dc;
	case 4834ULL: goto x86_l_12e2;
	case 4837ULL: goto x86_l_12e5;
	case 4841ULL: goto x86_l_12e9;
	case 4847ULL: goto x86_l_12ef;
	case 4853ULL: goto x86_l_12f5;
	case 4859ULL: goto x86_l_12fb;
	case 4865ULL: goto x86_l_1301;
	case 4868ULL: goto x86_l_1304;
	case 4872ULL: goto x86_l_1308;
	case 4878ULL: goto x86_l_130e;
	case 4884ULL: goto x86_l_1314;
	case 4890ULL: goto x86_l_131a;
	case 4896ULL: goto x86_l_1320;
	case 4899ULL: goto x86_l_1323;
	case 4903ULL: goto x86_l_1327;
	case 4909ULL: goto x86_l_132d;
	case 4915ULL: goto x86_l_1333;
	case 4921ULL: goto x86_l_1339;
	case 4927ULL: goto x86_l_133f;
	case 4930ULL: goto x86_l_1342;
	case 4934ULL: goto x86_l_1346;
	case 4940ULL: goto x86_l_134c;
	case 4946ULL: goto x86_l_1352;
	case 4952ULL: goto x86_l_1358;
	case 4958ULL: goto x86_l_135e;
	case 4961ULL: goto x86_l_1361;
	case 4965ULL: goto x86_l_1365;
	case 4971ULL: goto x86_l_136b;
	case 4977ULL: goto x86_l_1371;
	case 4983ULL: goto x86_l_1377;
	case 4989ULL: goto x86_l_137d;
	case 4992ULL: goto x86_l_1380;
	case 4996ULL: goto x86_l_1384;
	case 5002ULL: goto x86_l_138a;
	case 5008ULL: goto x86_l_1390;
	case 5014ULL: goto x86_l_1396;
	case 5020ULL: goto x86_l_139c;
	case 5023ULL: goto x86_l_139f;
	case 5027ULL: goto x86_l_13a3;
	case 5033ULL: goto x86_l_13a9;
	case 5039ULL: goto x86_l_13af;
	case 5045ULL: goto x86_l_13b5;
	case 5051ULL: goto x86_l_13bb;
	case 5054ULL: goto x86_l_13be;
	case 5058ULL: goto x86_l_13c2;
	case 5064ULL: goto x86_l_13c8;
	case 5070ULL: goto x86_l_13ce;
	case 5076ULL: goto x86_l_13d4;
	case 5082ULL: goto x86_l_13da;
	case 5085ULL: goto x86_l_13dd;
	case 5089ULL: goto x86_l_13e1;
	case 5095ULL: goto x86_l_13e7;
	case 5101ULL: goto x86_l_13ed;
	case 5107ULL: goto x86_l_13f3;
	case 5113ULL: goto x86_l_13f9;
	case 5116ULL: goto x86_l_13fc;
	case 5120ULL: goto x86_l_1400;
	case 5126ULL: goto x86_l_1406;
	case 5132ULL: goto x86_l_140c;
	case 5138ULL: goto x86_l_1412;
	case 5144ULL: goto x86_l_1418;
	case 5147ULL: goto x86_l_141b;
	case 5151ULL: goto x86_l_141f;
	case 5157ULL: goto x86_l_1425;
	case 5163ULL: goto x86_l_142b;
	case 5169ULL: goto x86_l_1431;
	case 5175ULL: goto x86_l_1437;
	case 5178ULL: goto x86_l_143a;
	case 5182ULL: goto x86_l_143e;
	case 5188ULL: goto x86_l_1444;
	case 5194ULL: goto x86_l_144a;
	case 5200ULL: goto x86_l_1450;
	case 5206ULL: goto x86_l_1456;
	case 5209ULL: goto x86_l_1459;
	case 5213ULL: goto x86_l_145d;
	case 5219ULL: goto x86_l_1463;
	case 5225ULL: goto x86_l_1469;
	case 5231ULL: goto x86_l_146f;
	case 5237ULL: goto x86_l_1475;
	case 5240ULL: goto x86_l_1478;
	case 5244ULL: goto x86_l_147c;
	case 5250ULL: goto x86_l_1482;
	case 5256ULL: goto x86_l_1488;
	case 5262ULL: goto x86_l_148e;
	case 5268ULL: goto x86_l_1494;
	case 5271ULL: goto x86_l_1497;
	case 5275ULL: goto x86_l_149b;
	case 5281ULL: goto x86_l_14a1;
	case 5287ULL: goto x86_l_14a7;
	case 5293ULL: goto x86_l_14ad;
	case 5299ULL: goto x86_l_14b3;
	case 5302ULL: goto x86_l_14b6;
	case 5306ULL: goto x86_l_14ba;
	case 5312ULL: goto x86_l_14c0;
	case 5318ULL: goto x86_l_14c6;
	case 5324ULL: goto x86_l_14cc;
	case 5330ULL: goto x86_l_14d2;
	case 5333ULL: goto x86_l_14d5;
	case 5337ULL: goto x86_l_14d9;
	case 5343ULL: goto x86_l_14df;
	case 5349ULL: goto x86_l_14e5;
	case 5355ULL: goto x86_l_14eb;
	case 5361ULL: goto x86_l_14f1;
	case 5364ULL: goto x86_l_14f4;
	case 5368ULL: goto x86_l_14f8;
	case 5374ULL: goto x86_l_14fe;
	case 5380ULL: goto x86_l_1504;
	case 5386ULL: goto x86_l_150a;
	case 5392ULL: goto x86_l_1510;
	case 5395ULL: goto x86_l_1513;
	case 5399ULL: goto x86_l_1517;
	case 5405ULL: goto x86_l_151d;
	case 5411ULL: goto x86_l_1523;
	case 5417ULL: goto x86_l_1529;
	case 5423ULL: goto x86_l_152f;
	case 5426ULL: goto x86_l_1532;
	case 5430ULL: goto x86_l_1536;
	case 5436ULL: goto x86_l_153c;
	case 5442ULL: goto x86_l_1542;
	case 5448ULL: goto x86_l_1548;
	case 5454ULL: goto x86_l_154e;
	case 5457ULL: goto x86_l_1551;
	case 5461ULL: goto x86_l_1555;
	case 5467ULL: goto x86_l_155b;
	case 5473ULL: goto x86_l_1561;
	case 5479ULL: goto x86_l_1567;
	case 5485ULL: goto x86_l_156d;
	case 5488ULL: goto x86_l_1570;
	case 5492ULL: goto x86_l_1574;
	case 5498ULL: goto x86_l_157a;
	case 5504ULL: goto x86_l_1580;
	case 5510ULL: goto x86_l_1586;
	case 5516ULL: goto x86_l_158c;
	case 5519ULL: goto x86_l_158f;
	case 5523ULL: goto x86_l_1593;
	case 5529ULL: goto x86_l_1599;
	case 5535ULL: goto x86_l_159f;
	case 5541ULL: goto x86_l_15a5;
	case 5547ULL: goto x86_l_15ab;
	case 5550ULL: goto x86_l_15ae;
	case 5554ULL: goto x86_l_15b2;
	case 5560ULL: goto x86_l_15b8;
	case 5566ULL: goto x86_l_15be;
	case 5572ULL: goto x86_l_15c4;
	case 5578ULL: goto x86_l_15ca;
	case 5581ULL: goto x86_l_15cd;
	case 5585ULL: goto x86_l_15d1;
	case 5591ULL: goto x86_l_15d7;
	case 5597ULL: goto x86_l_15dd;
	case 5603ULL: goto x86_l_15e3;
	case 5609ULL: goto x86_l_15e9;
	case 5612ULL: goto x86_l_15ec;
	case 5616ULL: goto x86_l_15f0;
	case 5622ULL: goto x86_l_15f6;
	case 5628ULL: goto x86_l_15fc;
	case 5634ULL: goto x86_l_1602;
	case 5640ULL: goto x86_l_1608;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e7a:
	/* 0xe7a: mov    ecx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e7e:
	/* 0xe7e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e80:
	/* 0xe80: je     30b4 <generic_retuprobe_filter_arg_2+0x30b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12468ULL;
	}
x86_l_e86:
	/* 0xe86: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e89:
	/* 0xe89: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e8b:
	/* 0xe8b: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_e8f:
	/* 0xe8f: jmp    30b7 <generic_retuprobe_filter_arg_2+0x30b7> */
	return 12471ULL;
x86_l_e94:
	/* 0xe94: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e97:
	/* 0xe97: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e9a:
	/* 0xe9a: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_e9d:
	/* 0xe9d: ja     3265 <generic_retuprobe_filter_arg_2+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12901ULL;
	}
x86_l_ea3:
	/* 0xea3: mov    edx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ea6:
	/* 0xea6: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_eaa:
	/* 0xeaa: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_eaf:
	/* 0xeaf: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_eb2:
	/* 0xeb2: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eb7:
	/* 0xeb7: jb     2abc <generic_retuprobe_filter_arg_2+0x2abc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10940ULL;
	}
x86_l_ebd:
	/* 0xebd: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_ec2:
	/* 0xec2: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ec5:
	/* 0xec5: jb     2a16 <generic_retuprobe_filter_arg_2+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10774ULL;
	}
x86_l_ecb:
	/* 0xecb: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_ed0:
	/* 0xed0: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ed3:
	/* 0xed3: jae    3265 <generic_retuprobe_filter_arg_2+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12901ULL;
	}
x86_l_ed9:
	/* 0xed9: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_edc:
	/* 0xedc: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee0:
	/* 0xee0: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ee3:
	/* 0xee3: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ee7:
	/* 0xee7: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_eef:
	/* 0xeef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ef4:
	/* 0xef4: mov    rdi,QWORD PTR [rip+0x1783] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_efb:
	/* 0xefb: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f00:
	/* 0xf00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f02:
	/* 0xf02: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f05:
	/* 0xf05: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f0b:
	/* 0xf0b: je     325e <generic_retuprobe_filter_arg_2+0x325e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12894ULL;
	}
x86_l_f11:
	/* 0xf11: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f16:
	/* 0xf16: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f19:
	/* 0xf19: je     325e <generic_retuprobe_filter_arg_2+0x325e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12894ULL;
	}
x86_l_f1f:
	/* 0xf1f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f24:
	/* 0xf24: mov    rdi,QWORD PTR [rip+0x1780] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_f2b:
	/* 0xf2b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f30:
	/* 0xf30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f32:
	/* 0xf32: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f35:
	/* 0xf35: je     325b <generic_retuprobe_filter_arg_2+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12891ULL;
	}
x86_l_f3b:
	/* 0xf3b: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f40:
	/* 0xf40: cmp    esi,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 94ULL);
x86_l_f43:
	/* 0xf43: mov    ecx,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 94ULL);
x86_l_f48:
	/* 0xf48: cmovb  ecx,esi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_f4b:
	/* 0xf4b: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_f4e:
	/* 0xf4e: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f50:
	/* 0xf50: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_f53:
	/* 0xf53: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f59:
	/* 0xf59: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_f5f:
	/* 0xf5f: mov    BYTE PTR [rax+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f62:
	/* 0xf62: cmp    rsi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1ULL);
x86_l_f66:
	/* 0xf66: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_f6c:
	/* 0xf6c: lea    ecx,[rsi+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_f72:
	/* 0xf72: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f78:
	/* 0xf78: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_f7e:
	/* 0xf7e: mov    BYTE PTR [rax+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_f81:
	/* 0xf81: cmp    rsi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 2ULL);
x86_l_f85:
	/* 0xf85: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_f8b:
	/* 0xf8b: lea    ecx,[rsi+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_f91:
	/* 0xf91: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f97:
	/* 0xf97: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_f9d:
	/* 0xf9d: mov    BYTE PTR [rax+0x6],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_fa0:
	/* 0xfa0: cmp    rsi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 3ULL);
x86_l_fa4:
	/* 0xfa4: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_faa:
	/* 0xfaa: lea    ecx,[rsi+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_fb0:
	/* 0xfb0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fb6:
	/* 0xfb6: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_fbc:
	/* 0xfbc: mov    BYTE PTR [rax+0x7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_fbf:
	/* 0xfbf: cmp    rsi,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4ULL);
x86_l_fc3:
	/* 0xfc3: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_fc9:
	/* 0xfc9: lea    ecx,[rsi+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_fcf:
	/* 0xfcf: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fd5:
	/* 0xfd5: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_fdb:
	/* 0xfdb: mov    BYTE PTR [rax+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fde:
	/* 0xfde: cmp    rsi,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 5ULL);
x86_l_fe2:
	/* 0xfe2: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_fe8:
	/* 0xfe8: lea    ecx,[rsi+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_fee:
	/* 0xfee: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ff4:
	/* 0xff4: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ffa:
	/* 0xffa: mov    BYTE PTR [rax+0x9],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_ffd:
	/* 0xffd: cmp    rsi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 6ULL);
x86_l_1001:
	/* 0x1001: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1007:
	/* 0x1007: lea    ecx,[rsi+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_100d:
	/* 0x100d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1013:
	/* 0x1013: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1019:
	/* 0x1019: mov    BYTE PTR [rax+0xa],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_101c:
	/* 0x101c: cmp    rsi,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 7ULL);
x86_l_1020:
	/* 0x1020: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1026:
	/* 0x1026: lea    ecx,[rsi+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_102c:
	/* 0x102c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1032:
	/* 0x1032: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1038:
	/* 0x1038: mov    BYTE PTR [rax+0xb],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_103b:
	/* 0x103b: cmp    rsi,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 8ULL);
x86_l_103f:
	/* 0x103f: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1045:
	/* 0x1045: lea    ecx,[rsi+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_104b:
	/* 0x104b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1051:
	/* 0x1051: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1057:
	/* 0x1057: mov    BYTE PTR [rax+0xc],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_105a:
	/* 0x105a: cmp    rsi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 9ULL);
x86_l_105e:
	/* 0x105e: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1064:
	/* 0x1064: lea    ecx,[rsi+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_106a:
	/* 0x106a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1070:
	/* 0x1070: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1076:
	/* 0x1076: mov    BYTE PTR [rax+0xd],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_1079:
	/* 0x1079: cmp    rsi,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 10ULL);
x86_l_107d:
	/* 0x107d: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1083:
	/* 0x1083: lea    ecx,[rsi+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_1089:
	/* 0x1089: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_108f:
	/* 0x108f: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1095:
	/* 0x1095: mov    BYTE PTR [rax+0xe],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1098:
	/* 0x1098: cmp    rsi,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 11ULL);
x86_l_109c:
	/* 0x109c: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_10a2:
	/* 0x10a2: lea    ecx,[rsi+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_10a8:
	/* 0x10a8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10ae:
	/* 0x10ae: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_10b4:
	/* 0x10b4: mov    BYTE PTR [rax+0xf],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_10b7:
	/* 0x10b7: cmp    rsi,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 12ULL);
x86_l_10bb:
	/* 0x10bb: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_10c1:
	/* 0x10c1: lea    ecx,[rsi+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_10c7:
	/* 0x10c7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10cd:
	/* 0x10cd: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_10d3:
	/* 0x10d3: mov    BYTE PTR [rax+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10d6:
	/* 0x10d6: cmp    rsi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 13ULL);
x86_l_10da:
	/* 0x10da: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_10e0:
	/* 0x10e0: lea    ecx,[rsi+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_10e6:
	/* 0x10e6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10ec:
	/* 0x10ec: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_10f2:
	/* 0x10f2: mov    BYTE PTR [rax+0x11],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_10f5:
	/* 0x10f5: cmp    rsi,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 14ULL);
x86_l_10f9:
	/* 0x10f9: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_10ff:
	/* 0x10ff: lea    ecx,[rsi+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_1105:
	/* 0x1105: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_110b:
	/* 0x110b: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1111:
	/* 0x1111: mov    BYTE PTR [rax+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1114:
	/* 0x1114: cmp    rsi,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 15ULL);
x86_l_1118:
	/* 0x1118: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_111e:
	/* 0x111e: lea    ecx,[rsi+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_1124:
	/* 0x1124: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_112a:
	/* 0x112a: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1130:
	/* 0x1130: mov    BYTE PTR [rax+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_1133:
	/* 0x1133: cmp    rsi,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 16ULL);
x86_l_1137:
	/* 0x1137: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_113d:
	/* 0x113d: lea    ecx,[rsi+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_1143:
	/* 0x1143: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1149:
	/* 0x1149: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_114f:
	/* 0x114f: mov    BYTE PTR [rax+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1152:
	/* 0x1152: cmp    rsi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 17ULL);
x86_l_1156:
	/* 0x1156: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_115c:
	/* 0x115c: lea    ecx,[rsi+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_1162:
	/* 0x1162: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1168:
	/* 0x1168: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_116e:
	/* 0x116e: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1171:
	/* 0x1171: cmp    rsi,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18ULL);
x86_l_1175:
	/* 0x1175: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_117b:
	/* 0x117b: lea    ecx,[rsi+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_1181:
	/* 0x1181: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1187:
	/* 0x1187: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_118d:
	/* 0x118d: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1190:
	/* 0x1190: cmp    rsi,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 19ULL);
x86_l_1194:
	/* 0x1194: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_119a:
	/* 0x119a: lea    ecx,[rsi+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_11a0:
	/* 0x11a0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11a6:
	/* 0x11a6: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_11ac:
	/* 0x11ac: mov    BYTE PTR [rax+0x17],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_11af:
	/* 0x11af: cmp    rsi,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 20ULL);
x86_l_11b3:
	/* 0x11b3: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_11b9:
	/* 0x11b9: lea    ecx,[rsi+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_11bf:
	/* 0x11bf: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11c5:
	/* 0x11c5: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_11cb:
	/* 0x11cb: mov    BYTE PTR [rax+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ce:
	/* 0x11ce: cmp    rsi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 21ULL);
x86_l_11d2:
	/* 0x11d2: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_11d8:
	/* 0x11d8: lea    ecx,[rsi+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_11de:
	/* 0x11de: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11e4:
	/* 0x11e4: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_11ea:
	/* 0x11ea: mov    BYTE PTR [rax+0x19],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_11ed:
	/* 0x11ed: cmp    rsi,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 22ULL);
x86_l_11f1:
	/* 0x11f1: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_11f7:
	/* 0x11f7: lea    ecx,[rsi+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_11fd:
	/* 0x11fd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1203:
	/* 0x1203: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1209:
	/* 0x1209: mov    BYTE PTR [rax+0x1a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_120c:
	/* 0x120c: cmp    rsi,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 23ULL);
x86_l_1210:
	/* 0x1210: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1216:
	/* 0x1216: lea    ecx,[rsi+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_121c:
	/* 0x121c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1222:
	/* 0x1222: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1228:
	/* 0x1228: mov    BYTE PTR [rax+0x1b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_122b:
	/* 0x122b: cmp    rsi,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 24ULL);
x86_l_122f:
	/* 0x122f: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1235:
	/* 0x1235: lea    ecx,[rsi+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_123b:
	/* 0x123b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1241:
	/* 0x1241: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1247:
	/* 0x1247: mov    BYTE PTR [rax+0x1c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_124a:
	/* 0x124a: cmp    rsi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 25ULL);
x86_l_124e:
	/* 0x124e: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1254:
	/* 0x1254: lea    ecx,[rsi+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_125a:
	/* 0x125a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1260:
	/* 0x1260: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1266:
	/* 0x1266: mov    BYTE PTR [rax+0x1d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_1269:
	/* 0x1269: cmp    rsi,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 26ULL);
x86_l_126d:
	/* 0x126d: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1273:
	/* 0x1273: lea    ecx,[rsi+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_1279:
	/* 0x1279: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_127f:
	/* 0x127f: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1285:
	/* 0x1285: mov    BYTE PTR [rax+0x1e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1288:
	/* 0x1288: cmp    rsi,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 27ULL);
x86_l_128c:
	/* 0x128c: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1292:
	/* 0x1292: lea    ecx,[rsi+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_1298:
	/* 0x1298: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_129e:
	/* 0x129e: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_12a4:
	/* 0x12a4: mov    BYTE PTR [rax+0x1f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_12a7:
	/* 0x12a7: cmp    rsi,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 28ULL);
x86_l_12ab:
	/* 0x12ab: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_12b1:
	/* 0x12b1: lea    ecx,[rsi+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_12b7:
	/* 0x12b7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12bd:
	/* 0x12bd: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_12c3:
	/* 0x12c3: mov    BYTE PTR [rax+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12c6:
	/* 0x12c6: cmp    rsi,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 29ULL);
x86_l_12ca:
	/* 0x12ca: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_12d0:
	/* 0x12d0: lea    ecx,[rsi+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_12d6:
	/* 0x12d6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12dc:
	/* 0x12dc: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_12e2:
	/* 0x12e2: mov    BYTE PTR [rax+0x21],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_12e5:
	/* 0x12e5: cmp    rsi,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 30ULL);
x86_l_12e9:
	/* 0x12e9: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_12ef:
	/* 0x12ef: lea    ecx,[rsi+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_12f5:
	/* 0x12f5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12fb:
	/* 0x12fb: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1301:
	/* 0x1301: mov    BYTE PTR [rax+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1304:
	/* 0x1304: cmp    rsi,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 31ULL);
x86_l_1308:
	/* 0x1308: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_130e:
	/* 0x130e: lea    ecx,[rsi+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_1314:
	/* 0x1314: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_131a:
	/* 0x131a: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1320:
	/* 0x1320: mov    BYTE PTR [rax+0x23],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_1323:
	/* 0x1323: cmp    rsi,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 32ULL);
x86_l_1327:
	/* 0x1327: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_132d:
	/* 0x132d: lea    ecx,[rsi+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_1333:
	/* 0x1333: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1339:
	/* 0x1339: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_133f:
	/* 0x133f: mov    BYTE PTR [rax+0x24],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1342:
	/* 0x1342: cmp    rsi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 33ULL);
x86_l_1346:
	/* 0x1346: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_134c:
	/* 0x134c: lea    ecx,[rsi+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_1352:
	/* 0x1352: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1358:
	/* 0x1358: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_135e:
	/* 0x135e: mov    BYTE PTR [rax+0x25],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_1361:
	/* 0x1361: cmp    rsi,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 34ULL);
x86_l_1365:
	/* 0x1365: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_136b:
	/* 0x136b: lea    ecx,[rsi+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_1371:
	/* 0x1371: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1377:
	/* 0x1377: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_137d:
	/* 0x137d: mov    BYTE PTR [rax+0x26],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_1380:
	/* 0x1380: cmp    rsi,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 35ULL);
x86_l_1384:
	/* 0x1384: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_138a:
	/* 0x138a: lea    ecx,[rsi+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_1390:
	/* 0x1390: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1396:
	/* 0x1396: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_139c:
	/* 0x139c: mov    BYTE PTR [rax+0x27],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_139f:
	/* 0x139f: cmp    rsi,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 36ULL);
x86_l_13a3:
	/* 0x13a3: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_13a9:
	/* 0x13a9: lea    ecx,[rsi+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_13af:
	/* 0x13af: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13b5:
	/* 0x13b5: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_13bb:
	/* 0x13bb: mov    BYTE PTR [rax+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13be:
	/* 0x13be: cmp    rsi,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 37ULL);
x86_l_13c2:
	/* 0x13c2: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_13c8:
	/* 0x13c8: lea    ecx,[rsi+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_13ce:
	/* 0x13ce: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13d4:
	/* 0x13d4: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_13da:
	/* 0x13da: mov    BYTE PTR [rax+0x29],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_13dd:
	/* 0x13dd: cmp    rsi,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 38ULL);
x86_l_13e1:
	/* 0x13e1: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_13e7:
	/* 0x13e7: lea    ecx,[rsi+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_13ed:
	/* 0x13ed: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13f3:
	/* 0x13f3: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_13f9:
	/* 0x13f9: mov    BYTE PTR [rax+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_13fc:
	/* 0x13fc: cmp    rsi,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 39ULL);
x86_l_1400:
	/* 0x1400: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1406:
	/* 0x1406: lea    ecx,[rsi+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_140c:
	/* 0x140c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1412:
	/* 0x1412: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1418:
	/* 0x1418: mov    BYTE PTR [rax+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_141b:
	/* 0x141b: cmp    rsi,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 40ULL);
x86_l_141f:
	/* 0x141f: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1425:
	/* 0x1425: lea    ecx,[rsi+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_142b:
	/* 0x142b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1431:
	/* 0x1431: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1437:
	/* 0x1437: mov    BYTE PTR [rax+0x2c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_143a:
	/* 0x143a: cmp    rsi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 41ULL);
x86_l_143e:
	/* 0x143e: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1444:
	/* 0x1444: lea    ecx,[rsi+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_144a:
	/* 0x144a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1450:
	/* 0x1450: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1456:
	/* 0x1456: mov    BYTE PTR [rax+0x2d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_1459:
	/* 0x1459: cmp    rsi,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 42ULL);
x86_l_145d:
	/* 0x145d: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1463:
	/* 0x1463: lea    ecx,[rsi+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_1469:
	/* 0x1469: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_146f:
	/* 0x146f: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1475:
	/* 0x1475: mov    BYTE PTR [rax+0x2e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_1478:
	/* 0x1478: cmp    rsi,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 43ULL);
x86_l_147c:
	/* 0x147c: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1482:
	/* 0x1482: lea    ecx,[rsi+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_1488:
	/* 0x1488: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_148e:
	/* 0x148e: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1494:
	/* 0x1494: mov    BYTE PTR [rax+0x2f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_1497:
	/* 0x1497: cmp    rsi,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 44ULL);
x86_l_149b:
	/* 0x149b: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_14a1:
	/* 0x14a1: lea    ecx,[rsi+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_14a7:
	/* 0x14a7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14ad:
	/* 0x14ad: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_14b3:
	/* 0x14b3: mov    BYTE PTR [rax+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14b6:
	/* 0x14b6: cmp    rsi,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 45ULL);
x86_l_14ba:
	/* 0x14ba: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_14c0:
	/* 0x14c0: lea    ecx,[rsi+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_14c6:
	/* 0x14c6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14cc:
	/* 0x14cc: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_14d2:
	/* 0x14d2: mov    BYTE PTR [rax+0x31],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_14d5:
	/* 0x14d5: cmp    rsi,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 46ULL);
x86_l_14d9:
	/* 0x14d9: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_14df:
	/* 0x14df: lea    ecx,[rsi+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_14e5:
	/* 0x14e5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14eb:
	/* 0x14eb: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_14f1:
	/* 0x14f1: mov    BYTE PTR [rax+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_14f4:
	/* 0x14f4: cmp    rsi,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 47ULL);
x86_l_14f8:
	/* 0x14f8: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_14fe:
	/* 0x14fe: lea    ecx,[rsi+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_1504:
	/* 0x1504: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_150a:
	/* 0x150a: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1510:
	/* 0x1510: mov    BYTE PTR [rax+0x33],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_1513:
	/* 0x1513: cmp    rsi,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 48ULL);
x86_l_1517:
	/* 0x1517: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_151d:
	/* 0x151d: lea    ecx,[rsi+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_1523:
	/* 0x1523: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1529:
	/* 0x1529: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_152f:
	/* 0x152f: mov    BYTE PTR [rax+0x34],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1532:
	/* 0x1532: cmp    rsi,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 49ULL);
x86_l_1536:
	/* 0x1536: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_153c:
	/* 0x153c: lea    ecx,[rsi+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_1542:
	/* 0x1542: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1548:
	/* 0x1548: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_154e:
	/* 0x154e: mov    BYTE PTR [rax+0x35],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_1551:
	/* 0x1551: cmp    rsi,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 50ULL);
x86_l_1555:
	/* 0x1555: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_155b:
	/* 0x155b: lea    ecx,[rsi+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_1561:
	/* 0x1561: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1567:
	/* 0x1567: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_156d:
	/* 0x156d: mov    BYTE PTR [rax+0x36],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_1570:
	/* 0x1570: cmp    rsi,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 51ULL);
x86_l_1574:
	/* 0x1574: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_157a:
	/* 0x157a: lea    ecx,[rsi+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_1580:
	/* 0x1580: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1586:
	/* 0x1586: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_158c:
	/* 0x158c: mov    BYTE PTR [rax+0x37],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_158f:
	/* 0x158f: cmp    rsi,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 52ULL);
x86_l_1593:
	/* 0x1593: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_1599:
	/* 0x1599: lea    ecx,[rsi+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_159f:
	/* 0x159f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15a5:
	/* 0x15a5: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_15ab:
	/* 0x15ab: mov    BYTE PTR [rax+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15ae:
	/* 0x15ae: cmp    rsi,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 53ULL);
x86_l_15b2:
	/* 0x15b2: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_15b8:
	/* 0x15b8: lea    ecx,[rsi+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_15be:
	/* 0x15be: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15c4:
	/* 0x15c4: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_15ca:
	/* 0x15ca: mov    BYTE PTR [rax+0x39],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_15cd:
	/* 0x15cd: cmp    rsi,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 54ULL);
x86_l_15d1:
	/* 0x15d1: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_15d7:
	/* 0x15d7: lea    ecx,[rsi+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_15dd:
	/* 0x15dd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15e3:
	/* 0x15e3: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_15e9:
	/* 0x15e9: mov    BYTE PTR [rax+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_15ec:
	/* 0x15ec: cmp    rsi,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 55ULL);
x86_l_15f0:
	/* 0x15f0: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6805ULL;
	}
x86_l_15f6:
	/* 0x15f6: lea    ecx,[rsi+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_15fc:
	/* 0x15fc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1602:
	/* 0x1602: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1608:
	/* 0x1608: mov    BYTE PTR [rax+0x3b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
	return 5643ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5643ULL: goto x86_l_160b;
	case 5647ULL: goto x86_l_160f;
	case 5653ULL: goto x86_l_1615;
	case 5659ULL: goto x86_l_161b;
	case 5665ULL: goto x86_l_1621;
	case 5671ULL: goto x86_l_1627;
	case 5674ULL: goto x86_l_162a;
	case 5678ULL: goto x86_l_162e;
	case 5684ULL: goto x86_l_1634;
	case 5690ULL: goto x86_l_163a;
	case 5696ULL: goto x86_l_1640;
	case 5702ULL: goto x86_l_1646;
	case 5705ULL: goto x86_l_1649;
	case 5709ULL: goto x86_l_164d;
	case 5715ULL: goto x86_l_1653;
	case 5721ULL: goto x86_l_1659;
	case 5727ULL: goto x86_l_165f;
	case 5733ULL: goto x86_l_1665;
	case 5736ULL: goto x86_l_1668;
	case 5740ULL: goto x86_l_166c;
	case 5746ULL: goto x86_l_1672;
	case 5752ULL: goto x86_l_1678;
	case 5758ULL: goto x86_l_167e;
	case 5764ULL: goto x86_l_1684;
	case 5767ULL: goto x86_l_1687;
	case 5771ULL: goto x86_l_168b;
	case 5777ULL: goto x86_l_1691;
	case 5783ULL: goto x86_l_1697;
	case 5789ULL: goto x86_l_169d;
	case 5795ULL: goto x86_l_16a3;
	case 5798ULL: goto x86_l_16a6;
	case 5802ULL: goto x86_l_16aa;
	case 5808ULL: goto x86_l_16b0;
	case 5814ULL: goto x86_l_16b6;
	case 5820ULL: goto x86_l_16bc;
	case 5826ULL: goto x86_l_16c2;
	case 5829ULL: goto x86_l_16c5;
	case 5833ULL: goto x86_l_16c9;
	case 5839ULL: goto x86_l_16cf;
	case 5845ULL: goto x86_l_16d5;
	case 5851ULL: goto x86_l_16db;
	case 5857ULL: goto x86_l_16e1;
	case 5860ULL: goto x86_l_16e4;
	case 5864ULL: goto x86_l_16e8;
	case 5870ULL: goto x86_l_16ee;
	case 5876ULL: goto x86_l_16f4;
	case 5882ULL: goto x86_l_16fa;
	case 5888ULL: goto x86_l_1700;
	case 5891ULL: goto x86_l_1703;
	case 5895ULL: goto x86_l_1707;
	case 5901ULL: goto x86_l_170d;
	case 5907ULL: goto x86_l_1713;
	case 5913ULL: goto x86_l_1719;
	case 5919ULL: goto x86_l_171f;
	case 5922ULL: goto x86_l_1722;
	case 5926ULL: goto x86_l_1726;
	case 5932ULL: goto x86_l_172c;
	case 5938ULL: goto x86_l_1732;
	case 5944ULL: goto x86_l_1738;
	case 5950ULL: goto x86_l_173e;
	case 5953ULL: goto x86_l_1741;
	case 5957ULL: goto x86_l_1745;
	case 5963ULL: goto x86_l_174b;
	case 5969ULL: goto x86_l_1751;
	case 5975ULL: goto x86_l_1757;
	case 5981ULL: goto x86_l_175d;
	case 5984ULL: goto x86_l_1760;
	case 5988ULL: goto x86_l_1764;
	case 5994ULL: goto x86_l_176a;
	case 6000ULL: goto x86_l_1770;
	case 6006ULL: goto x86_l_1776;
	case 6012ULL: goto x86_l_177c;
	case 6015ULL: goto x86_l_177f;
	case 6019ULL: goto x86_l_1783;
	case 6025ULL: goto x86_l_1789;
	case 6031ULL: goto x86_l_178f;
	case 6037ULL: goto x86_l_1795;
	case 6043ULL: goto x86_l_179b;
	case 6046ULL: goto x86_l_179e;
	case 6050ULL: goto x86_l_17a2;
	case 6056ULL: goto x86_l_17a8;
	case 6062ULL: goto x86_l_17ae;
	case 6068ULL: goto x86_l_17b4;
	case 6074ULL: goto x86_l_17ba;
	case 6077ULL: goto x86_l_17bd;
	case 6081ULL: goto x86_l_17c1;
	case 6087ULL: goto x86_l_17c7;
	case 6093ULL: goto x86_l_17cd;
	case 6099ULL: goto x86_l_17d3;
	case 6105ULL: goto x86_l_17d9;
	case 6108ULL: goto x86_l_17dc;
	case 6112ULL: goto x86_l_17e0;
	case 6118ULL: goto x86_l_17e6;
	case 6124ULL: goto x86_l_17ec;
	case 6130ULL: goto x86_l_17f2;
	case 6136ULL: goto x86_l_17f8;
	case 6139ULL: goto x86_l_17fb;
	case 6143ULL: goto x86_l_17ff;
	case 6149ULL: goto x86_l_1805;
	case 6155ULL: goto x86_l_180b;
	case 6161ULL: goto x86_l_1811;
	case 6167ULL: goto x86_l_1817;
	case 6170ULL: goto x86_l_181a;
	case 6174ULL: goto x86_l_181e;
	case 6180ULL: goto x86_l_1824;
	case 6186ULL: goto x86_l_182a;
	case 6192ULL: goto x86_l_1830;
	case 6198ULL: goto x86_l_1836;
	case 6201ULL: goto x86_l_1839;
	case 6205ULL: goto x86_l_183d;
	case 6211ULL: goto x86_l_1843;
	case 6217ULL: goto x86_l_1849;
	case 6223ULL: goto x86_l_184f;
	case 6229ULL: goto x86_l_1855;
	case 6232ULL: goto x86_l_1858;
	case 6236ULL: goto x86_l_185c;
	case 6242ULL: goto x86_l_1862;
	case 6248ULL: goto x86_l_1868;
	case 6254ULL: goto x86_l_186e;
	case 6260ULL: goto x86_l_1874;
	case 6263ULL: goto x86_l_1877;
	case 6267ULL: goto x86_l_187b;
	case 6273ULL: goto x86_l_1881;
	case 6279ULL: goto x86_l_1887;
	case 6285ULL: goto x86_l_188d;
	case 6291ULL: goto x86_l_1893;
	case 6294ULL: goto x86_l_1896;
	case 6298ULL: goto x86_l_189a;
	case 6304ULL: goto x86_l_18a0;
	case 6310ULL: goto x86_l_18a6;
	case 6316ULL: goto x86_l_18ac;
	case 6322ULL: goto x86_l_18b2;
	case 6325ULL: goto x86_l_18b5;
	case 6329ULL: goto x86_l_18b9;
	case 6335ULL: goto x86_l_18bf;
	case 6341ULL: goto x86_l_18c5;
	case 6347ULL: goto x86_l_18cb;
	case 6353ULL: goto x86_l_18d1;
	case 6356ULL: goto x86_l_18d4;
	case 6360ULL: goto x86_l_18d8;
	case 6366ULL: goto x86_l_18de;
	case 6372ULL: goto x86_l_18e4;
	case 6378ULL: goto x86_l_18ea;
	case 6384ULL: goto x86_l_18f0;
	case 6387ULL: goto x86_l_18f3;
	case 6391ULL: goto x86_l_18f7;
	case 6397ULL: goto x86_l_18fd;
	case 6403ULL: goto x86_l_1903;
	case 6409ULL: goto x86_l_1909;
	case 6415ULL: goto x86_l_190f;
	case 6418ULL: goto x86_l_1912;
	case 6422ULL: goto x86_l_1916;
	case 6428ULL: goto x86_l_191c;
	case 6434ULL: goto x86_l_1922;
	case 6440ULL: goto x86_l_1928;
	case 6446ULL: goto x86_l_192e;
	case 6449ULL: goto x86_l_1931;
	case 6453ULL: goto x86_l_1935;
	case 6459ULL: goto x86_l_193b;
	case 6465ULL: goto x86_l_1941;
	case 6471ULL: goto x86_l_1947;
	case 6477ULL: goto x86_l_194d;
	case 6480ULL: goto x86_l_1950;
	case 6484ULL: goto x86_l_1954;
	case 6490ULL: goto x86_l_195a;
	case 6496ULL: goto x86_l_1960;
	case 6502ULL: goto x86_l_1966;
	case 6508ULL: goto x86_l_196c;
	case 6511ULL: goto x86_l_196f;
	case 6515ULL: goto x86_l_1973;
	case 6521ULL: goto x86_l_1979;
	case 6527ULL: goto x86_l_197f;
	case 6533ULL: goto x86_l_1985;
	case 6539ULL: goto x86_l_198b;
	case 6542ULL: goto x86_l_198e;
	case 6546ULL: goto x86_l_1992;
	case 6552ULL: goto x86_l_1998;
	case 6558ULL: goto x86_l_199e;
	case 6564ULL: goto x86_l_19a4;
	case 6570ULL: goto x86_l_19aa;
	case 6573ULL: goto x86_l_19ad;
	case 6577ULL: goto x86_l_19b1;
	case 6583ULL: goto x86_l_19b7;
	case 6589ULL: goto x86_l_19bd;
	case 6595ULL: goto x86_l_19c3;
	case 6601ULL: goto x86_l_19c9;
	case 6604ULL: goto x86_l_19cc;
	case 6608ULL: goto x86_l_19d0;
	case 6614ULL: goto x86_l_19d6;
	case 6620ULL: goto x86_l_19dc;
	case 6626ULL: goto x86_l_19e2;
	case 6632ULL: goto x86_l_19e8;
	case 6635ULL: goto x86_l_19eb;
	case 6639ULL: goto x86_l_19ef;
	case 6645ULL: goto x86_l_19f5;
	case 6651ULL: goto x86_l_19fb;
	case 6657ULL: goto x86_l_1a01;
	case 6663ULL: goto x86_l_1a07;
	case 6666ULL: goto x86_l_1a0a;
	case 6670ULL: goto x86_l_1a0e;
	case 6676ULL: goto x86_l_1a14;
	case 6682ULL: goto x86_l_1a1a;
	case 6688ULL: goto x86_l_1a20;
	case 6694ULL: goto x86_l_1a26;
	case 6697ULL: goto x86_l_1a29;
	case 6701ULL: goto x86_l_1a2d;
	case 6703ULL: goto x86_l_1a2f;
	case 6709ULL: goto x86_l_1a35;
	case 6715ULL: goto x86_l_1a3b;
	case 6721ULL: goto x86_l_1a41;
	case 6724ULL: goto x86_l_1a44;
	case 6728ULL: goto x86_l_1a48;
	case 6730ULL: goto x86_l_1a4a;
	case 6736ULL: goto x86_l_1a50;
	case 6742ULL: goto x86_l_1a56;
	case 6748ULL: goto x86_l_1a5c;
	case 6751ULL: goto x86_l_1a5f;
	case 6755ULL: goto x86_l_1a63;
	case 6757ULL: goto x86_l_1a65;
	case 6763ULL: goto x86_l_1a6b;
	case 6769ULL: goto x86_l_1a71;
	case 6775ULL: goto x86_l_1a77;
	case 6778ULL: goto x86_l_1a7a;
	case 6782ULL: goto x86_l_1a7e;
	case 6784ULL: goto x86_l_1a80;
	case 6790ULL: goto x86_l_1a86;
	case 6796ULL: goto x86_l_1a8c;
	case 6802ULL: goto x86_l_1a92;
	case 6805ULL: goto x86_l_1a95;
	case 6810ULL: goto x86_l_1a9a;
	case 6815ULL: goto x86_l_1a9f;
	case 6818ULL: goto x86_l_1aa2;
	case 6823ULL: goto x86_l_1aa7;
	case 6828ULL: goto x86_l_1aac;
	case 6832ULL: goto x86_l_1ab0;
	case 6835ULL: goto x86_l_1ab3;
	case 6839ULL: goto x86_l_1ab7;
	case 6847ULL: goto x86_l_1abf;
	case 6852ULL: goto x86_l_1ac4;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6866ULL: goto x86_l_1ad2;
	case 6869ULL: goto x86_l_1ad5;
	case 6872ULL: goto x86_l_1ad8;
	case 6875ULL: goto x86_l_1adb;
	case 6881ULL: goto x86_l_1ae1;
	case 6884ULL: goto x86_l_1ae4;
	case 6890ULL: goto x86_l_1aea;
	case 6895ULL: goto x86_l_1aef;
	case 6900ULL: goto x86_l_1af4;
	case 6907ULL: goto x86_l_1afb;
	case 6912ULL: goto x86_l_1b00;
	case 6914ULL: goto x86_l_1b02;
	case 6917ULL: goto x86_l_1b05;
	case 6923ULL: goto x86_l_1b0b;
	case 6930ULL: goto x86_l_1b12;
	case 6935ULL: goto x86_l_1b17;
	case 6939ULL: goto x86_l_1b1b;
	case 6946ULL: goto x86_l_1b22;
	case 6948ULL: goto x86_l_1b24;
	case 6951ULL: goto x86_l_1b27;
	case 6955ULL: goto x86_l_1b2b;
	case 6960ULL: goto x86_l_1b30;
	case 6965ULL: goto x86_l_1b35;
	case 6968ULL: goto x86_l_1b38;
	case 6970ULL: goto x86_l_1b3a;
	case 6975ULL: goto x86_l_1b3f;
	case 6980ULL: goto x86_l_1b44;
	case 6983ULL: goto x86_l_1b47;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6998ULL: goto x86_l_1b56;
	case 7005ULL: goto x86_l_1b5d;
	case 7011ULL: goto x86_l_1b63;
	case 7015ULL: goto x86_l_1b67;
	case 7021ULL: goto x86_l_1b6d;
	case 7024ULL: goto x86_l_1b70;
	case 7027ULL: goto x86_l_1b73;
	case 7030ULL: goto x86_l_1b76;
	case 7033ULL: goto x86_l_1b79;
	case 7035ULL: goto x86_l_1b7b;
	case 7039ULL: goto x86_l_1b7f;
	case 7045ULL: goto x86_l_1b85;
	case 7047ULL: goto x86_l_1b87;
	case 7053ULL: goto x86_l_1b8d;
	case 7056ULL: goto x86_l_1b90;
	case 7061ULL: goto x86_l_1b95;
	case 7064ULL: goto x86_l_1b98;
	case 7069ULL: goto x86_l_1b9d;
	case 7073ULL: goto x86_l_1ba1;
	case 7078ULL: goto x86_l_1ba6;
	case 7082ULL: goto x86_l_1baa;
	case 7087ULL: goto x86_l_1baf;
	case 7091ULL: goto x86_l_1bb3;
	case 7096ULL: goto x86_l_1bb8;
	case 7101ULL: goto x86_l_1bbd;
	case 7103ULL: goto x86_l_1bbf;
	case 7106ULL: goto x86_l_1bc2;
	case 7109ULL: goto x86_l_1bc5;
	case 7112ULL: goto x86_l_1bc8;
	case 7114ULL: goto x86_l_1bca;
	case 7117ULL: goto x86_l_1bcd;
	case 7119ULL: goto x86_l_1bcf;
	case 7122ULL: goto x86_l_1bd2;
	case 7125ULL: goto x86_l_1bd5;
	case 7131ULL: goto x86_l_1bdb;
	case 7134ULL: goto x86_l_1bde;
	case 7137ULL: goto x86_l_1be1;
	case 7143ULL: goto x86_l_1be7;
	case 7148ULL: goto x86_l_1bec;
	case 7151ULL: goto x86_l_1bef;
	case 7153ULL: goto x86_l_1bf1;
	case 7156ULL: goto x86_l_1bf4;
	case 7162ULL: goto x86_l_1bfa;
	case 7165ULL: goto x86_l_1bfd;
	case 7171ULL: goto x86_l_1c03;
	case 7174ULL: goto x86_l_1c06;
	case 7180ULL: goto x86_l_1c0c;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	case 7193ULL: goto x86_l_1c19;
	case 7199ULL: goto x86_l_1c1f;
	case 7202ULL: goto x86_l_1c22;
	case 7208ULL: goto x86_l_1c28;
	case 7211ULL: goto x86_l_1c2b;
	case 7217ULL: goto x86_l_1c31;
	case 7222ULL: goto x86_l_1c36;
	case 7225ULL: goto x86_l_1c39;
	case 7228ULL: goto x86_l_1c3c;
	case 7234ULL: goto x86_l_1c42;
	case 7242ULL: goto x86_l_1c4a;
	case 7249ULL: goto x86_l_1c51;
	case 7255ULL: goto x86_l_1c57;
	case 7258ULL: goto x86_l_1c5a;
	case 7263ULL: goto x86_l_1c5f;
	case 7266ULL: goto x86_l_1c62;
	case 7272ULL: goto x86_l_1c68;
	case 7275ULL: goto x86_l_1c6b;
	case 7281ULL: goto x86_l_1c71;
	case 7284ULL: goto x86_l_1c74;
	case 7290ULL: goto x86_l_1c7a;
	case 7295ULL: goto x86_l_1c7f;
	case 7300ULL: goto x86_l_1c84;
	case 7304ULL: goto x86_l_1c88;
	case 7307ULL: goto x86_l_1c8b;
	case 7311ULL: goto x86_l_1c8f;
	case 7319ULL: goto x86_l_1c97;
	case 7324ULL: goto x86_l_1c9c;
	case 7331ULL: goto x86_l_1ca3;
	case 7336ULL: goto x86_l_1ca8;
	case 7338ULL: goto x86_l_1caa;
	case 7341ULL: goto x86_l_1cad;
	case 7344ULL: goto x86_l_1cb0;
	case 7347ULL: goto x86_l_1cb3;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7361ULL: goto x86_l_1cc1;
	case 7367ULL: goto x86_l_1cc7;
	case 7372ULL: goto x86_l_1ccc;
	case 7379ULL: goto x86_l_1cd3;
	case 7384ULL: goto x86_l_1cd8;
	case 7386ULL: goto x86_l_1cda;
	case 7389ULL: goto x86_l_1cdd;
	case 7395ULL: goto x86_l_1ce3;
	case 7400ULL: goto x86_l_1ce8;
	case 7404ULL: goto x86_l_1cec;
	case 7408ULL: goto x86_l_1cf0;
	case 7413ULL: goto x86_l_1cf5;
	case 7417ULL: goto x86_l_1cf9;
	case 7420ULL: goto x86_l_1cfc;
	case 7422ULL: goto x86_l_1cfe;
	case 7426ULL: goto x86_l_1d02;
	case 7432ULL: goto x86_l_1d08;
	case 7436ULL: goto x86_l_1d0c;
	case 7439ULL: goto x86_l_1d0f;
	case 7443ULL: goto x86_l_1d13;
	case 7449ULL: goto x86_l_1d19;
	case 7456ULL: goto x86_l_1d20;
	case 7462ULL: goto x86_l_1d26;
	case 7466ULL: goto x86_l_1d2a;
	case 7469ULL: goto x86_l_1d2d;
	case 7473ULL: goto x86_l_1d31;
	case 7479ULL: goto x86_l_1d37;
	case 7486ULL: goto x86_l_1d3e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_160b:
	/* 0x160b: cmp    rsi,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 56ULL);
x86_l_160f:
	/* 0x160f: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1615:
	/* 0x1615: lea    ecx,[rsi+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_161b:
	/* 0x161b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1621:
	/* 0x1621: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1627:
	/* 0x1627: mov    BYTE PTR [rax+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_162a:
	/* 0x162a: cmp    rsi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 57ULL);
x86_l_162e:
	/* 0x162e: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1634:
	/* 0x1634: lea    ecx,[rsi+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_163a:
	/* 0x163a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1640:
	/* 0x1640: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1646:
	/* 0x1646: mov    BYTE PTR [rax+0x3d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_1649:
	/* 0x1649: cmp    rsi,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 58ULL);
x86_l_164d:
	/* 0x164d: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1653:
	/* 0x1653: lea    ecx,[rsi+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_1659:
	/* 0x1659: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_165f:
	/* 0x165f: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1665:
	/* 0x1665: mov    BYTE PTR [rax+0x3e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_1668:
	/* 0x1668: cmp    rsi,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 59ULL);
x86_l_166c:
	/* 0x166c: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1672:
	/* 0x1672: lea    ecx,[rsi+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_1678:
	/* 0x1678: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_167e:
	/* 0x167e: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1684:
	/* 0x1684: mov    BYTE PTR [rax+0x3f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_1687:
	/* 0x1687: cmp    rsi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 60ULL);
x86_l_168b:
	/* 0x168b: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1691:
	/* 0x1691: lea    ecx,[rsi+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_1697:
	/* 0x1697: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_169d:
	/* 0x169d: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_16a3:
	/* 0x16a3: mov    BYTE PTR [rax+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16a6:
	/* 0x16a6: cmp    rsi,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 61ULL);
x86_l_16aa:
	/* 0x16aa: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_16b0:
	/* 0x16b0: lea    ecx,[rsi+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_16b6:
	/* 0x16b6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16bc:
	/* 0x16bc: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_16c2:
	/* 0x16c2: mov    BYTE PTR [rax+0x41],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_16c5:
	/* 0x16c5: cmp    rsi,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 62ULL);
x86_l_16c9:
	/* 0x16c9: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_16cf:
	/* 0x16cf: lea    ecx,[rsi+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_16d5:
	/* 0x16d5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16db:
	/* 0x16db: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_16e1:
	/* 0x16e1: mov    BYTE PTR [rax+0x42],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_16e4:
	/* 0x16e4: cmp    rsi,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 63ULL);
x86_l_16e8:
	/* 0x16e8: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_16ee:
	/* 0x16ee: lea    ecx,[rsi+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_16f4:
	/* 0x16f4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16fa:
	/* 0x16fa: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1700:
	/* 0x1700: mov    BYTE PTR [rax+0x43],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_1703:
	/* 0x1703: cmp    rsi,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 64ULL);
x86_l_1707:
	/* 0x1707: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_170d:
	/* 0x170d: lea    ecx,[rsi+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_1713:
	/* 0x1713: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1719:
	/* 0x1719: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_171f:
	/* 0x171f: mov    BYTE PTR [rax+0x44],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1722:
	/* 0x1722: cmp    rsi,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 65ULL);
x86_l_1726:
	/* 0x1726: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_172c:
	/* 0x172c: lea    ecx,[rsi+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_1732:
	/* 0x1732: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1738:
	/* 0x1738: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_173e:
	/* 0x173e: mov    BYTE PTR [rax+0x45],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_1741:
	/* 0x1741: cmp    rsi,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 66ULL);
x86_l_1745:
	/* 0x1745: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_174b:
	/* 0x174b: lea    ecx,[rsi+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_1751:
	/* 0x1751: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1757:
	/* 0x1757: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_175d:
	/* 0x175d: mov    BYTE PTR [rax+0x46],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_1760:
	/* 0x1760: cmp    rsi,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 67ULL);
x86_l_1764:
	/* 0x1764: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_176a:
	/* 0x176a: lea    ecx,[rsi+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_1770:
	/* 0x1770: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1776:
	/* 0x1776: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_177c:
	/* 0x177c: mov    BYTE PTR [rax+0x47],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_177f:
	/* 0x177f: cmp    rsi,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 68ULL);
x86_l_1783:
	/* 0x1783: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1789:
	/* 0x1789: lea    ecx,[rsi+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_178f:
	/* 0x178f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1795:
	/* 0x1795: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_179b:
	/* 0x179b: mov    BYTE PTR [rax+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_179e:
	/* 0x179e: cmp    rsi,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 69ULL);
x86_l_17a2:
	/* 0x17a2: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_17a8:
	/* 0x17a8: lea    ecx,[rsi+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_17ae:
	/* 0x17ae: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17b4:
	/* 0x17b4: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_17ba:
	/* 0x17ba: mov    BYTE PTR [rax+0x49],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_17bd:
	/* 0x17bd: cmp    rsi,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 70ULL);
x86_l_17c1:
	/* 0x17c1: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_17c7:
	/* 0x17c7: lea    ecx,[rsi+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_17cd:
	/* 0x17cd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17d3:
	/* 0x17d3: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_17d9:
	/* 0x17d9: mov    BYTE PTR [rax+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_17dc:
	/* 0x17dc: cmp    rsi,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 71ULL);
x86_l_17e0:
	/* 0x17e0: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_17e6:
	/* 0x17e6: lea    ecx,[rsi+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_17ec:
	/* 0x17ec: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17f2:
	/* 0x17f2: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_17f8:
	/* 0x17f8: mov    BYTE PTR [rax+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_17fb:
	/* 0x17fb: cmp    rsi,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 72ULL);
x86_l_17ff:
	/* 0x17ff: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1805:
	/* 0x1805: lea    ecx,[rsi+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_180b:
	/* 0x180b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1811:
	/* 0x1811: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1817:
	/* 0x1817: mov    BYTE PTR [rax+0x4c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_181a:
	/* 0x181a: cmp    rsi,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 73ULL);
x86_l_181e:
	/* 0x181e: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1824:
	/* 0x1824: lea    ecx,[rsi+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_182a:
	/* 0x182a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1830:
	/* 0x1830: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1836:
	/* 0x1836: mov    BYTE PTR [rax+0x4d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_1839:
	/* 0x1839: cmp    rsi,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 74ULL);
x86_l_183d:
	/* 0x183d: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1843:
	/* 0x1843: lea    ecx,[rsi+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_1849:
	/* 0x1849: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_184f:
	/* 0x184f: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1855:
	/* 0x1855: mov    BYTE PTR [rax+0x4e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_1858:
	/* 0x1858: cmp    rsi,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 75ULL);
x86_l_185c:
	/* 0x185c: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1862:
	/* 0x1862: lea    ecx,[rsi+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_1868:
	/* 0x1868: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_186e:
	/* 0x186e: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1874:
	/* 0x1874: mov    BYTE PTR [rax+0x4f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_1877:
	/* 0x1877: cmp    rsi,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 76ULL);
x86_l_187b:
	/* 0x187b: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1881:
	/* 0x1881: lea    ecx,[rsi+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_1887:
	/* 0x1887: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_188d:
	/* 0x188d: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1893:
	/* 0x1893: mov    BYTE PTR [rax+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1896:
	/* 0x1896: cmp    rsi,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 77ULL);
x86_l_189a:
	/* 0x189a: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_18a0:
	/* 0x18a0: lea    ecx,[rsi+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_18a6:
	/* 0x18a6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18ac:
	/* 0x18ac: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_18b2:
	/* 0x18b2: mov    BYTE PTR [rax+0x51],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_18b5:
	/* 0x18b5: cmp    rsi,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 78ULL);
x86_l_18b9:
	/* 0x18b9: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_18bf:
	/* 0x18bf: lea    ecx,[rsi+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_18c5:
	/* 0x18c5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18cb:
	/* 0x18cb: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_18d1:
	/* 0x18d1: mov    BYTE PTR [rax+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_18d4:
	/* 0x18d4: cmp    rsi,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 79ULL);
x86_l_18d8:
	/* 0x18d8: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_18de:
	/* 0x18de: lea    ecx,[rsi+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_18e4:
	/* 0x18e4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18ea:
	/* 0x18ea: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_18f0:
	/* 0x18f0: mov    BYTE PTR [rax+0x53],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_18f3:
	/* 0x18f3: cmp    rsi,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 80ULL);
x86_l_18f7:
	/* 0x18f7: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_18fd:
	/* 0x18fd: lea    ecx,[rsi+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_1903:
	/* 0x1903: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1909:
	/* 0x1909: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_190f:
	/* 0x190f: mov    BYTE PTR [rax+0x54],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1912:
	/* 0x1912: cmp    rsi,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 81ULL);
x86_l_1916:
	/* 0x1916: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_191c:
	/* 0x191c: lea    ecx,[rsi+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_1922:
	/* 0x1922: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1928:
	/* 0x1928: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_192e:
	/* 0x192e: mov    BYTE PTR [rax+0x55],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_1931:
	/* 0x1931: cmp    rsi,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 82ULL);
x86_l_1935:
	/* 0x1935: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_193b:
	/* 0x193b: lea    ecx,[rsi+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_1941:
	/* 0x1941: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1947:
	/* 0x1947: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_194d:
	/* 0x194d: mov    BYTE PTR [rax+0x56],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1950:
	/* 0x1950: cmp    rsi,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 83ULL);
x86_l_1954:
	/* 0x1954: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_195a:
	/* 0x195a: lea    ecx,[rsi+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_1960:
	/* 0x1960: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1966:
	/* 0x1966: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_196c:
	/* 0x196c: mov    BYTE PTR [rax+0x57],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_196f:
	/* 0x196f: cmp    rsi,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 84ULL);
x86_l_1973:
	/* 0x1973: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1979:
	/* 0x1979: lea    ecx,[rsi+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_197f:
	/* 0x197f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1985:
	/* 0x1985: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_198b:
	/* 0x198b: mov    BYTE PTR [rax+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_198e:
	/* 0x198e: cmp    rsi,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 85ULL);
x86_l_1992:
	/* 0x1992: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1998:
	/* 0x1998: lea    ecx,[rsi+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_199e:
	/* 0x199e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19a4:
	/* 0x19a4: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_19aa:
	/* 0x19aa: mov    BYTE PTR [rax+0x59],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_19ad:
	/* 0x19ad: cmp    rsi,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 86ULL);
x86_l_19b1:
	/* 0x19b1: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_19b7:
	/* 0x19b7: lea    ecx,[rsi+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_19bd:
	/* 0x19bd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19c3:
	/* 0x19c3: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_19c9:
	/* 0x19c9: mov    BYTE PTR [rax+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_19cc:
	/* 0x19cc: cmp    rsi,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 87ULL);
x86_l_19d0:
	/* 0x19d0: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_19d6:
	/* 0x19d6: lea    ecx,[rsi+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_19dc:
	/* 0x19dc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19e2:
	/* 0x19e2: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_19e8:
	/* 0x19e8: mov    BYTE PTR [rax+0x5b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_19eb:
	/* 0x19eb: cmp    rsi,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 88ULL);
x86_l_19ef:
	/* 0x19ef: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_19f5:
	/* 0x19f5: lea    ecx,[rsi+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_19fb:
	/* 0x19fb: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a01:
	/* 0x1a01: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a07:
	/* 0x1a07: mov    BYTE PTR [rax+0x5c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1a0a:
	/* 0x1a0a: cmp    rsi,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 89ULL);
x86_l_1a0e:
	/* 0x1a0e: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1a14:
	/* 0x1a14: lea    ecx,[rsi+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_1a1a:
	/* 0x1a1a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a20:
	/* 0x1a20: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a26:
	/* 0x1a26: mov    BYTE PTR [rax+0x5d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_1a29:
	/* 0x1a29: cmp    rsi,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 90ULL);
x86_l_1a2d:
	/* 0x1a2d: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1a2f:
	/* 0x1a2f: lea    ecx,[rsi+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_1a35:
	/* 0x1a35: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a3b:
	/* 0x1a3b: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a41:
	/* 0x1a41: mov    BYTE PTR [rax+0x5e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_1a44:
	/* 0x1a44: cmp    rsi,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 91ULL);
x86_l_1a48:
	/* 0x1a48: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1a4a:
	/* 0x1a4a: lea    ecx,[rsi+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_1a50:
	/* 0x1a50: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a56:
	/* 0x1a56: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a5c:
	/* 0x1a5c: mov    BYTE PTR [rax+0x5f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_1a5f:
	/* 0x1a5f: cmp    rsi,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 92ULL);
x86_l_1a63:
	/* 0x1a63: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1a65:
	/* 0x1a65: lea    ecx,[rsi+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_1a6b:
	/* 0x1a6b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a71:
	/* 0x1a71: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a77:
	/* 0x1a77: mov    BYTE PTR [rax+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a7a:
	/* 0x1a7a: cmp    rsi,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 93ULL);
x86_l_1a7e:
	/* 0x1a7e: je     1a95 <generic_retuprobe_filter_arg_2+0x1a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a95;
	}
x86_l_1a80:
	/* 0x1a80: add    esi,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_1a86:
	/* 0x1a86: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a8c:
	/* 0x1a8c: movzx  ecx,BYTE PTR [r13+rsi*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1a92:
	/* 0x1a92: mov    BYTE PTR [rax+0x61],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_1a95:
	/* 0x1a95: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1a9a:
	/* 0x1a9a: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a9f:
	/* 0x1a9f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1aa2:
	/* 0x1aa2: jmp    324d <generic_retuprobe_filter_arg_2+0x324d> */
	return 12877ULL;
x86_l_1aa7:
	/* 0x1aa7: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1aac:
	/* 0x1aac: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ab0:
	/* 0x1ab0: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ab3:
	/* 0x1ab3: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ab7:
	/* 0x1ab7: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1abf:
	/* 0x1abf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ac4:
	/* 0x1ac4: mov    rdi,QWORD PTR [rip+0x1784] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1acb:
	/* 0x1acb: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ad0:
	/* 0x1ad0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad2:
	/* 0x1ad2: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1ad5:
	/* 0x1ad5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ad8:
	/* 0x1ad8: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1adb:
	/* 0x1adb: je     325e <generic_retuprobe_filter_arg_2+0x325e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12894ULL;
	}
x86_l_1ae1:
	/* 0x1ae1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ae4:
	/* 0x1ae4: je     325e <generic_retuprobe_filter_arg_2+0x325e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12894ULL;
	}
x86_l_1aea:
	/* 0x1aea: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aef:
	/* 0x1aef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1af4:
	/* 0x1af4: mov    rdi,QWORD PTR [rip+0x1783] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1afb:
	/* 0x1afb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b00:
	/* 0x1b00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b02:
	/* 0x1b02: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b05:
	/* 0x1b05: je     325b <generic_retuprobe_filter_arg_2+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12891ULL;
	}
x86_l_1b0b:
	/* 0x1b0b: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_1b12:
	/* 0x1b12: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_1b17:
	/* 0x1b17: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1b1b:
	/* 0x1b1b: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_1b22:
	/* 0x1b22: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b24:
	/* 0x1b24: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b27:
	/* 0x1b27: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1b2b:
	/* 0x1b2b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b30:
	/* 0x1b30: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b35:
	/* 0x1b35: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1b38:
	/* 0x1b38: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b3a:
	/* 0x1b3a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b3f:
	/* 0x1b3f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b44:
	/* 0x1b44: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1b47:
	/* 0x1b47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b49:
	/* 0x1b49: jmp    324f <generic_retuprobe_filter_arg_2+0x324f> */
	return 12879ULL;
x86_l_1b4e:
	/* 0x1b4e: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1b56:
	/* 0x1b56: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_1b5d:
	/* 0x1b5d: ja     2d2b <generic_retuprobe_filter_arg_2+0x2d2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11563ULL;
	}
x86_l_1b63:
	/* 0x1b63: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b67:
	/* 0x1b67: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1b6d:
	/* 0x1b6d: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1b70:
	/* 0x1b70: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1b73:
	/* 0x1b73: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1b76:
	/* 0x1b76: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1b79:
	/* 0x1b79: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1b7b:
	/* 0x1b7b: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_1b7f:
	/* 0x1b7f: je     2bff <generic_retuprobe_filter_arg_2+0x2bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11263ULL;
	}
x86_l_1b85:
	/* 0x1b85: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1b87:
	/* 0x1b87: jne    2bff <generic_retuprobe_filter_arg_2+0x2bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11263ULL;
	}
x86_l_1b8d:
	/* 0x1b8d: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_1b90:
	/* 0x1b90: jmp    2c19 <generic_retuprobe_filter_arg_2+0x2c19> */
	return 11289ULL;
x86_l_1b95:
	/* 0x1b95: movzx  eax,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b98:
	/* 0x1b98: mov    WORD PTR [rsp+0x76],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_1b9d:
	/* 0x1b9d: movzx  eax,WORD PTR [rdi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1ba1:
	/* 0x1ba1: mov    WORD PTR [rsp+0x70],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1ba6:
	/* 0x1ba6: mov    rax,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1baa:
	/* 0x1baa: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1baf:
	/* 0x1baf: mov    rax,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bb3:
	/* 0x1bb3: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1bb8:
	/* 0x1bb8: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bbd:
	/* 0x1bbd: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bbf:
	/* 0x1bbf: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1bc2:
	/* 0x1bc2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bc5:
	/* 0x1bc5: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1bc8:
	/* 0x1bc8: jle    1bec <generic_retuprobe_filter_arg_2+0x1bec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1bec;
	}
x86_l_1bca:
	/* 0x1bca: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1bcd:
	/* 0x1bcd: jg     1c16 <generic_retuprobe_filter_arg_2+0x1c16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1c16;
	}
x86_l_1bcf:
	/* 0x1bcf: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_1bd2:
	/* 0x1bd2: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1bd5:
	/* 0x1bd5: jb     28c3 <generic_retuprobe_filter_arg_2+0x28c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10435ULL;
	}
x86_l_1bdb:
	/* 0x1bdb: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_1bde:
	/* 0x1bde: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1be1:
	/* 0x1be1: jb     28bc <generic_retuprobe_filter_arg_2+0x28bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10428ULL;
	}
x86_l_1be7:
	/* 0x1be7: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	return 12928ULL;
x86_l_1bec:
	/* 0x1bec: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1bef:
	/* 0x1bef: jle    1c5f <generic_retuprobe_filter_arg_2+0x1c5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1c5f;
	}
x86_l_1bf1:
	/* 0x1bf1: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1bf4:
	/* 0x1bf4: jg     28ae <generic_retuprobe_filter_arg_2+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10414ULL;
	}
x86_l_1bfa:
	/* 0x1bfa: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1bfd:
	/* 0x1bfd: je     28bc <generic_retuprobe_filter_arg_2+0x28bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10428ULL;
	}
x86_l_1c03:
	/* 0x1c03: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1c06:
	/* 0x1c06: jne    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12928ULL;
	}
x86_l_1c0c:
	/* 0x1c0c: movzx  r15d,WORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1c11:
	/* 0x1c11: jmp    2d38 <generic_retuprobe_filter_arg_2+0x2d38> */
	return 11576ULL;
x86_l_1c16:
	/* 0x1c16: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1c19:
	/* 0x1c19: jg     28d2 <generic_retuprobe_filter_arg_2+0x28d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10450ULL;
	}
x86_l_1c1f:
	/* 0x1c1f: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1c22:
	/* 0x1c22: je     2908 <generic_retuprobe_filter_arg_2+0x2908> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10504ULL;
	}
x86_l_1c28:
	/* 0x1c28: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1c2b:
	/* 0x1c2b: je     28fe <generic_retuprobe_filter_arg_2+0x28fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10494ULL;
	}
x86_l_1c31:
	/* 0x1c31: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	return 12928ULL;
x86_l_1c36:
	/* 0x1c36: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1c39:
	/* 0x1c39: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c3c:
	/* 0x1c3c: jae    2bc5 <generic_retuprobe_filter_arg_2+0x2bc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11205ULL;
	}
x86_l_1c42:
	/* 0x1c42: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1c4a:
	/* 0x1c4a: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_1c51:
	/* 0x1c51: jbe    2bcd <generic_retuprobe_filter_arg_2+0x2bcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11213ULL;
	}
x86_l_1c57:
	/* 0x1c57: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c5a:
	/* 0x1c5a: jmp    31d7 <generic_retuprobe_filter_arg_2+0x31d7> */
	return 12759ULL;
x86_l_1c5f:
	/* 0x1c5f: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1c62:
	/* 0x1c62: je     2908 <generic_retuprobe_filter_arg_2+0x2908> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10504ULL;
	}
x86_l_1c68:
	/* 0x1c68: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1c6b:
	/* 0x1c6b: je     28fe <generic_retuprobe_filter_arg_2+0x28fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10494ULL;
	}
x86_l_1c71:
	/* 0x1c71: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1c74:
	/* 0x1c74: je     28c3 <generic_retuprobe_filter_arg_2+0x28c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10435ULL;
	}
x86_l_1c7a:
	/* 0x1c7a: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	return 12928ULL;
x86_l_1c7f:
	/* 0x1c7f: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c84:
	/* 0x1c84: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c88:
	/* 0x1c88: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c8b:
	/* 0x1c8b: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c8f:
	/* 0x1c8f: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1c97:
	/* 0x1c97: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c9c:
	/* 0x1c9c: mov    rdi,QWORD PTR [rip+0x1783] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_1ca3:
	/* 0x1ca3: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ca8:
	/* 0x1ca8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1caa:
	/* 0x1caa: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1cad:
	/* 0x1cad: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cb0:
	/* 0x1cb0: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1cb3:
	/* 0x1cb3: je     31d3 <generic_retuprobe_filter_arg_2+0x31d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12755ULL;
	}
x86_l_1cb9:
	/* 0x1cb9: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cbe:
	/* 0x1cbe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cc1:
	/* 0x1cc1: je     31d3 <generic_retuprobe_filter_arg_2+0x31d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12755ULL;
	}
x86_l_1cc7:
	/* 0x1cc7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ccc:
	/* 0x1ccc: mov    rdi,QWORD PTR [rip+0x1783] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_1cd3:
	/* 0x1cd3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cd8:
	/* 0x1cd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cda:
	/* 0x1cda: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cdd:
	/* 0x1cdd: je     31d0 <generic_retuprobe_filter_arg_2+0x31d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12752ULL;
	}
x86_l_1ce3:
	/* 0x1ce3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ce8:
	/* 0x1ce8: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1cec:
	/* 0x1cec: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_1cf0:
	/* 0x1cf0: mov    ecx,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 94ULL);
x86_l_1cf5:
	/* 0x1cf5: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1cf9:
	/* 0x1cf9: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1cfc:
	/* 0x1cfc: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cfe:
	/* 0x1cfe: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1d02:
	/* 0x1d02: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d08:
	/* 0x1d08: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d0c:
	/* 0x1d0c: mov    BYTE PTR [rax+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d0f:
	/* 0x1d0f: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_1d13:
	/* 0x1d13: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1d19:
	/* 0x1d19: lea    ecx,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_1d20:
	/* 0x1d20: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d26:
	/* 0x1d26: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d2a:
	/* 0x1d2a: mov    BYTE PTR [rax+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_1d2d:
	/* 0x1d2d: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_1d31:
	/* 0x1d31: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1d37:
	/* 0x1d37: lea    ecx,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_1d3e:
	/* 0x1d3e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
	return 7492ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7492ULL: goto x86_l_1d44;
	case 7496ULL: goto x86_l_1d48;
	case 7499ULL: goto x86_l_1d4b;
	case 7503ULL: goto x86_l_1d4f;
	case 7509ULL: goto x86_l_1d55;
	case 7516ULL: goto x86_l_1d5c;
	case 7522ULL: goto x86_l_1d62;
	case 7526ULL: goto x86_l_1d66;
	case 7529ULL: goto x86_l_1d69;
	case 7533ULL: goto x86_l_1d6d;
	case 7539ULL: goto x86_l_1d73;
	case 7546ULL: goto x86_l_1d7a;
	case 7552ULL: goto x86_l_1d80;
	case 7556ULL: goto x86_l_1d84;
	case 7559ULL: goto x86_l_1d87;
	case 7563ULL: goto x86_l_1d8b;
	case 7569ULL: goto x86_l_1d91;
	case 7576ULL: goto x86_l_1d98;
	case 7582ULL: goto x86_l_1d9e;
	case 7586ULL: goto x86_l_1da2;
	case 7589ULL: goto x86_l_1da5;
	case 7593ULL: goto x86_l_1da9;
	case 7599ULL: goto x86_l_1daf;
	case 7606ULL: goto x86_l_1db6;
	case 7612ULL: goto x86_l_1dbc;
	case 7616ULL: goto x86_l_1dc0;
	case 7619ULL: goto x86_l_1dc3;
	case 7623ULL: goto x86_l_1dc7;
	case 7629ULL: goto x86_l_1dcd;
	case 7636ULL: goto x86_l_1dd4;
	case 7642ULL: goto x86_l_1dda;
	case 7646ULL: goto x86_l_1dde;
	case 7649ULL: goto x86_l_1de1;
	case 7653ULL: goto x86_l_1de5;
	case 7659ULL: goto x86_l_1deb;
	case 7666ULL: goto x86_l_1df2;
	case 7672ULL: goto x86_l_1df8;
	case 7676ULL: goto x86_l_1dfc;
	case 7679ULL: goto x86_l_1dff;
	case 7683ULL: goto x86_l_1e03;
	case 7689ULL: goto x86_l_1e09;
	case 7696ULL: goto x86_l_1e10;
	case 7702ULL: goto x86_l_1e16;
	case 7706ULL: goto x86_l_1e1a;
	case 7709ULL: goto x86_l_1e1d;
	case 7713ULL: goto x86_l_1e21;
	case 7719ULL: goto x86_l_1e27;
	case 7726ULL: goto x86_l_1e2e;
	case 7732ULL: goto x86_l_1e34;
	case 7736ULL: goto x86_l_1e38;
	case 7739ULL: goto x86_l_1e3b;
	case 7743ULL: goto x86_l_1e3f;
	case 7749ULL: goto x86_l_1e45;
	case 7756ULL: goto x86_l_1e4c;
	case 7762ULL: goto x86_l_1e52;
	case 7766ULL: goto x86_l_1e56;
	case 7769ULL: goto x86_l_1e59;
	case 7773ULL: goto x86_l_1e5d;
	case 7779ULL: goto x86_l_1e63;
	case 7786ULL: goto x86_l_1e6a;
	case 7792ULL: goto x86_l_1e70;
	case 7796ULL: goto x86_l_1e74;
	case 7799ULL: goto x86_l_1e77;
	case 7803ULL: goto x86_l_1e7b;
	case 7809ULL: goto x86_l_1e81;
	case 7816ULL: goto x86_l_1e88;
	case 7822ULL: goto x86_l_1e8e;
	case 7826ULL: goto x86_l_1e92;
	case 7829ULL: goto x86_l_1e95;
	case 7833ULL: goto x86_l_1e99;
	case 7839ULL: goto x86_l_1e9f;
	case 7846ULL: goto x86_l_1ea6;
	case 7852ULL: goto x86_l_1eac;
	case 7856ULL: goto x86_l_1eb0;
	case 7859ULL: goto x86_l_1eb3;
	case 7863ULL: goto x86_l_1eb7;
	case 7869ULL: goto x86_l_1ebd;
	case 7876ULL: goto x86_l_1ec4;
	case 7882ULL: goto x86_l_1eca;
	case 7886ULL: goto x86_l_1ece;
	case 7889ULL: goto x86_l_1ed1;
	case 7893ULL: goto x86_l_1ed5;
	case 7899ULL: goto x86_l_1edb;
	case 7906ULL: goto x86_l_1ee2;
	case 7912ULL: goto x86_l_1ee8;
	case 7916ULL: goto x86_l_1eec;
	case 7919ULL: goto x86_l_1eef;
	case 7923ULL: goto x86_l_1ef3;
	case 7929ULL: goto x86_l_1ef9;
	case 7936ULL: goto x86_l_1f00;
	case 7942ULL: goto x86_l_1f06;
	case 7946ULL: goto x86_l_1f0a;
	case 7949ULL: goto x86_l_1f0d;
	case 7953ULL: goto x86_l_1f11;
	case 7959ULL: goto x86_l_1f17;
	case 7966ULL: goto x86_l_1f1e;
	case 7972ULL: goto x86_l_1f24;
	case 7976ULL: goto x86_l_1f28;
	case 7979ULL: goto x86_l_1f2b;
	case 7983ULL: goto x86_l_1f2f;
	case 7989ULL: goto x86_l_1f35;
	case 7996ULL: goto x86_l_1f3c;
	case 8002ULL: goto x86_l_1f42;
	case 8006ULL: goto x86_l_1f46;
	case 8009ULL: goto x86_l_1f49;
	case 8013ULL: goto x86_l_1f4d;
	case 8019ULL: goto x86_l_1f53;
	case 8026ULL: goto x86_l_1f5a;
	case 8032ULL: goto x86_l_1f60;
	case 8036ULL: goto x86_l_1f64;
	case 8039ULL: goto x86_l_1f67;
	case 8043ULL: goto x86_l_1f6b;
	case 8049ULL: goto x86_l_1f71;
	case 8056ULL: goto x86_l_1f78;
	case 8062ULL: goto x86_l_1f7e;
	case 8066ULL: goto x86_l_1f82;
	case 8069ULL: goto x86_l_1f85;
	case 8073ULL: goto x86_l_1f89;
	case 8079ULL: goto x86_l_1f8f;
	case 8086ULL: goto x86_l_1f96;
	case 8092ULL: goto x86_l_1f9c;
	case 8096ULL: goto x86_l_1fa0;
	case 8099ULL: goto x86_l_1fa3;
	case 8103ULL: goto x86_l_1fa7;
	case 8109ULL: goto x86_l_1fad;
	case 8116ULL: goto x86_l_1fb4;
	case 8122ULL: goto x86_l_1fba;
	case 8126ULL: goto x86_l_1fbe;
	case 8129ULL: goto x86_l_1fc1;
	case 8133ULL: goto x86_l_1fc5;
	case 8139ULL: goto x86_l_1fcb;
	case 8146ULL: goto x86_l_1fd2;
	case 8152ULL: goto x86_l_1fd8;
	case 8156ULL: goto x86_l_1fdc;
	case 8159ULL: goto x86_l_1fdf;
	case 8163ULL: goto x86_l_1fe3;
	case 8169ULL: goto x86_l_1fe9;
	case 8176ULL: goto x86_l_1ff0;
	case 8182ULL: goto x86_l_1ff6;
	case 8186ULL: goto x86_l_1ffa;
	case 8189ULL: goto x86_l_1ffd;
	case 8193ULL: goto x86_l_2001;
	case 8199ULL: goto x86_l_2007;
	case 8206ULL: goto x86_l_200e;
	case 8212ULL: goto x86_l_2014;
	case 8216ULL: goto x86_l_2018;
	case 8219ULL: goto x86_l_201b;
	case 8223ULL: goto x86_l_201f;
	case 8229ULL: goto x86_l_2025;
	case 8236ULL: goto x86_l_202c;
	case 8242ULL: goto x86_l_2032;
	case 8246ULL: goto x86_l_2036;
	case 8249ULL: goto x86_l_2039;
	case 8253ULL: goto x86_l_203d;
	case 8259ULL: goto x86_l_2043;
	case 8266ULL: goto x86_l_204a;
	case 8272ULL: goto x86_l_2050;
	case 8276ULL: goto x86_l_2054;
	case 8279ULL: goto x86_l_2057;
	case 8283ULL: goto x86_l_205b;
	case 8289ULL: goto x86_l_2061;
	case 8296ULL: goto x86_l_2068;
	case 8302ULL: goto x86_l_206e;
	case 8306ULL: goto x86_l_2072;
	case 8309ULL: goto x86_l_2075;
	case 8313ULL: goto x86_l_2079;
	case 8319ULL: goto x86_l_207f;
	case 8326ULL: goto x86_l_2086;
	case 8332ULL: goto x86_l_208c;
	case 8336ULL: goto x86_l_2090;
	case 8339ULL: goto x86_l_2093;
	case 8343ULL: goto x86_l_2097;
	case 8349ULL: goto x86_l_209d;
	case 8356ULL: goto x86_l_20a4;
	case 8362ULL: goto x86_l_20aa;
	case 8366ULL: goto x86_l_20ae;
	case 8369ULL: goto x86_l_20b1;
	case 8373ULL: goto x86_l_20b5;
	case 8379ULL: goto x86_l_20bb;
	case 8386ULL: goto x86_l_20c2;
	case 8392ULL: goto x86_l_20c8;
	case 8396ULL: goto x86_l_20cc;
	case 8399ULL: goto x86_l_20cf;
	case 8403ULL: goto x86_l_20d3;
	case 8409ULL: goto x86_l_20d9;
	case 8416ULL: goto x86_l_20e0;
	case 8422ULL: goto x86_l_20e6;
	case 8426ULL: goto x86_l_20ea;
	case 8429ULL: goto x86_l_20ed;
	case 8433ULL: goto x86_l_20f1;
	case 8439ULL: goto x86_l_20f7;
	case 8446ULL: goto x86_l_20fe;
	case 8452ULL: goto x86_l_2104;
	case 8456ULL: goto x86_l_2108;
	case 8459ULL: goto x86_l_210b;
	case 8463ULL: goto x86_l_210f;
	case 8469ULL: goto x86_l_2115;
	case 8476ULL: goto x86_l_211c;
	case 8482ULL: goto x86_l_2122;
	case 8486ULL: goto x86_l_2126;
	case 8489ULL: goto x86_l_2129;
	case 8493ULL: goto x86_l_212d;
	case 8499ULL: goto x86_l_2133;
	case 8506ULL: goto x86_l_213a;
	case 8512ULL: goto x86_l_2140;
	case 8516ULL: goto x86_l_2144;
	case 8519ULL: goto x86_l_2147;
	case 8523ULL: goto x86_l_214b;
	case 8529ULL: goto x86_l_2151;
	case 8536ULL: goto x86_l_2158;
	case 8542ULL: goto x86_l_215e;
	case 8546ULL: goto x86_l_2162;
	case 8549ULL: goto x86_l_2165;
	case 8553ULL: goto x86_l_2169;
	case 8559ULL: goto x86_l_216f;
	case 8566ULL: goto x86_l_2176;
	case 8572ULL: goto x86_l_217c;
	case 8576ULL: goto x86_l_2180;
	case 8579ULL: goto x86_l_2183;
	case 8583ULL: goto x86_l_2187;
	case 8589ULL: goto x86_l_218d;
	case 8596ULL: goto x86_l_2194;
	case 8602ULL: goto x86_l_219a;
	case 8606ULL: goto x86_l_219e;
	case 8609ULL: goto x86_l_21a1;
	case 8613ULL: goto x86_l_21a5;
	case 8619ULL: goto x86_l_21ab;
	case 8626ULL: goto x86_l_21b2;
	case 8632ULL: goto x86_l_21b8;
	case 8636ULL: goto x86_l_21bc;
	case 8639ULL: goto x86_l_21bf;
	case 8643ULL: goto x86_l_21c3;
	case 8649ULL: goto x86_l_21c9;
	case 8656ULL: goto x86_l_21d0;
	case 8662ULL: goto x86_l_21d6;
	case 8666ULL: goto x86_l_21da;
	case 8669ULL: goto x86_l_21dd;
	case 8673ULL: goto x86_l_21e1;
	case 8679ULL: goto x86_l_21e7;
	case 8686ULL: goto x86_l_21ee;
	case 8692ULL: goto x86_l_21f4;
	case 8696ULL: goto x86_l_21f8;
	case 8699ULL: goto x86_l_21fb;
	case 8703ULL: goto x86_l_21ff;
	case 8709ULL: goto x86_l_2205;
	case 8716ULL: goto x86_l_220c;
	case 8722ULL: goto x86_l_2212;
	case 8726ULL: goto x86_l_2216;
	case 8729ULL: goto x86_l_2219;
	case 8733ULL: goto x86_l_221d;
	case 8739ULL: goto x86_l_2223;
	case 8746ULL: goto x86_l_222a;
	case 8752ULL: goto x86_l_2230;
	case 8756ULL: goto x86_l_2234;
	case 8759ULL: goto x86_l_2237;
	case 8763ULL: goto x86_l_223b;
	case 8769ULL: goto x86_l_2241;
	case 8776ULL: goto x86_l_2248;
	case 8782ULL: goto x86_l_224e;
	case 8786ULL: goto x86_l_2252;
	case 8789ULL: goto x86_l_2255;
	case 8793ULL: goto x86_l_2259;
	case 8799ULL: goto x86_l_225f;
	case 8806ULL: goto x86_l_2266;
	case 8812ULL: goto x86_l_226c;
	case 8816ULL: goto x86_l_2270;
	case 8819ULL: goto x86_l_2273;
	case 8823ULL: goto x86_l_2277;
	case 8829ULL: goto x86_l_227d;
	case 8836ULL: goto x86_l_2284;
	case 8842ULL: goto x86_l_228a;
	case 8846ULL: goto x86_l_228e;
	case 8849ULL: goto x86_l_2291;
	case 8853ULL: goto x86_l_2295;
	case 8859ULL: goto x86_l_229b;
	case 8866ULL: goto x86_l_22a2;
	case 8872ULL: goto x86_l_22a8;
	case 8876ULL: goto x86_l_22ac;
	case 8879ULL: goto x86_l_22af;
	case 8883ULL: goto x86_l_22b3;
	case 8889ULL: goto x86_l_22b9;
	case 8896ULL: goto x86_l_22c0;
	case 8902ULL: goto x86_l_22c6;
	case 8906ULL: goto x86_l_22ca;
	case 8909ULL: goto x86_l_22cd;
	case 8913ULL: goto x86_l_22d1;
	case 8919ULL: goto x86_l_22d7;
	case 8926ULL: goto x86_l_22de;
	case 8932ULL: goto x86_l_22e4;
	case 8936ULL: goto x86_l_22e8;
	case 8939ULL: goto x86_l_22eb;
	case 8943ULL: goto x86_l_22ef;
	case 8949ULL: goto x86_l_22f5;
	case 8956ULL: goto x86_l_22fc;
	case 8962ULL: goto x86_l_2302;
	case 8966ULL: goto x86_l_2306;
	case 8969ULL: goto x86_l_2309;
	case 8973ULL: goto x86_l_230d;
	case 8979ULL: goto x86_l_2313;
	case 8986ULL: goto x86_l_231a;
	case 8992ULL: goto x86_l_2320;
	case 8996ULL: goto x86_l_2324;
	case 8999ULL: goto x86_l_2327;
	case 9003ULL: goto x86_l_232b;
	case 9009ULL: goto x86_l_2331;
	case 9016ULL: goto x86_l_2338;
	case 9022ULL: goto x86_l_233e;
	case 9026ULL: goto x86_l_2342;
	case 9029ULL: goto x86_l_2345;
	case 9033ULL: goto x86_l_2349;
	case 9039ULL: goto x86_l_234f;
	case 9046ULL: goto x86_l_2356;
	case 9052ULL: goto x86_l_235c;
	case 9056ULL: goto x86_l_2360;
	case 9059ULL: goto x86_l_2363;
	case 9063ULL: goto x86_l_2367;
	case 9069ULL: goto x86_l_236d;
	case 9076ULL: goto x86_l_2374;
	case 9082ULL: goto x86_l_237a;
	case 9086ULL: goto x86_l_237e;
	case 9089ULL: goto x86_l_2381;
	case 9093ULL: goto x86_l_2385;
	case 9099ULL: goto x86_l_238b;
	case 9106ULL: goto x86_l_2392;
	case 9112ULL: goto x86_l_2398;
	case 9116ULL: goto x86_l_239c;
	case 9119ULL: goto x86_l_239f;
	case 9123ULL: goto x86_l_23a3;
	case 9129ULL: goto x86_l_23a9;
	case 9136ULL: goto x86_l_23b0;
	case 9142ULL: goto x86_l_23b6;
	case 9146ULL: goto x86_l_23ba;
	case 9149ULL: goto x86_l_23bd;
	case 9153ULL: goto x86_l_23c1;
	case 9159ULL: goto x86_l_23c7;
	case 9166ULL: goto x86_l_23ce;
	case 9172ULL: goto x86_l_23d4;
	case 9176ULL: goto x86_l_23d8;
	case 9179ULL: goto x86_l_23db;
	case 9183ULL: goto x86_l_23df;
	case 9189ULL: goto x86_l_23e5;
	case 9196ULL: goto x86_l_23ec;
	case 9202ULL: goto x86_l_23f2;
	case 9206ULL: goto x86_l_23f6;
	case 9209ULL: goto x86_l_23f9;
	case 9213ULL: goto x86_l_23fd;
	case 9219ULL: goto x86_l_2403;
	case 9226ULL: goto x86_l_240a;
	case 9232ULL: goto x86_l_2410;
	case 9236ULL: goto x86_l_2414;
	case 9239ULL: goto x86_l_2417;
	case 9243ULL: goto x86_l_241b;
	case 9249ULL: goto x86_l_2421;
	case 9256ULL: goto x86_l_2428;
	case 9262ULL: goto x86_l_242e;
	case 9266ULL: goto x86_l_2432;
	case 9269ULL: goto x86_l_2435;
	case 9273ULL: goto x86_l_2439;
	case 9279ULL: goto x86_l_243f;
	case 9286ULL: goto x86_l_2446;
	case 9292ULL: goto x86_l_244c;
	case 9296ULL: goto x86_l_2450;
	case 9299ULL: goto x86_l_2453;
	case 9303ULL: goto x86_l_2457;
	case 9309ULL: goto x86_l_245d;
	case 9316ULL: goto x86_l_2464;
	case 9322ULL: goto x86_l_246a;
	case 9326ULL: goto x86_l_246e;
	case 9329ULL: goto x86_l_2471;
	case 9333ULL: goto x86_l_2475;
	case 9339ULL: goto x86_l_247b;
	case 9346ULL: goto x86_l_2482;
	case 9352ULL: goto x86_l_2488;
	case 9356ULL: goto x86_l_248c;
	case 9359ULL: goto x86_l_248f;
	case 9363ULL: goto x86_l_2493;
	case 9369ULL: goto x86_l_2499;
	case 9376ULL: goto x86_l_24a0;
	case 9382ULL: goto x86_l_24a6;
	case 9386ULL: goto x86_l_24aa;
	case 9389ULL: goto x86_l_24ad;
	case 9393ULL: goto x86_l_24b1;
	case 9399ULL: goto x86_l_24b7;
	case 9406ULL: goto x86_l_24be;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1d44:
	/* 0x1d44: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d48:
	/* 0x1d48: mov    BYTE PTR [rax+0x6],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1d4b:
	/* 0x1d4b: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_1d4f:
	/* 0x1d4f: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1d55:
	/* 0x1d55: lea    ecx,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_1d5c:
	/* 0x1d5c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d62:
	/* 0x1d62: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d66:
	/* 0x1d66: mov    BYTE PTR [rax+0x7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_1d69:
	/* 0x1d69: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_1d6d:
	/* 0x1d6d: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1d73:
	/* 0x1d73: lea    ecx,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_1d7a:
	/* 0x1d7a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d80:
	/* 0x1d80: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d84:
	/* 0x1d84: mov    BYTE PTR [rax+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d87:
	/* 0x1d87: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_1d8b:
	/* 0x1d8b: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1d91:
	/* 0x1d91: lea    ecx,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_1d98:
	/* 0x1d98: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d9e:
	/* 0x1d9e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1da2:
	/* 0x1da2: mov    BYTE PTR [rax+0x9],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1da5:
	/* 0x1da5: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_1da9:
	/* 0x1da9: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1daf:
	/* 0x1daf: lea    ecx,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_1db6:
	/* 0x1db6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1dbc:
	/* 0x1dbc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1dc0:
	/* 0x1dc0: mov    BYTE PTR [rax+0xa],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1dc3:
	/* 0x1dc3: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_1dc7:
	/* 0x1dc7: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1dcd:
	/* 0x1dcd: lea    ecx,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_1dd4:
	/* 0x1dd4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1dda:
	/* 0x1dda: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1dde:
	/* 0x1dde: mov    BYTE PTR [rax+0xb],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_1de1:
	/* 0x1de1: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_1de5:
	/* 0x1de5: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1deb:
	/* 0x1deb: lea    ecx,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_1df2:
	/* 0x1df2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1df8:
	/* 0x1df8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1dfc:
	/* 0x1dfc: mov    BYTE PTR [rax+0xc],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1dff:
	/* 0x1dff: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_1e03:
	/* 0x1e03: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1e09:
	/* 0x1e09: lea    ecx,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_1e10:
	/* 0x1e10: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e16:
	/* 0x1e16: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e1a:
	/* 0x1e1a: mov    BYTE PTR [rax+0xd],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_1e1d:
	/* 0x1e1d: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_1e21:
	/* 0x1e21: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1e27:
	/* 0x1e27: lea    ecx,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_1e2e:
	/* 0x1e2e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e34:
	/* 0x1e34: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e38:
	/* 0x1e38: mov    BYTE PTR [rax+0xe],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1e3b:
	/* 0x1e3b: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_1e3f:
	/* 0x1e3f: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1e45:
	/* 0x1e45: lea    ecx,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_1e4c:
	/* 0x1e4c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e52:
	/* 0x1e52: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e56:
	/* 0x1e56: mov    BYTE PTR [rax+0xf],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1e59:
	/* 0x1e59: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_1e5d:
	/* 0x1e5d: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1e63:
	/* 0x1e63: lea    ecx,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_1e6a:
	/* 0x1e6a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e70:
	/* 0x1e70: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e74:
	/* 0x1e74: mov    BYTE PTR [rax+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e77:
	/* 0x1e77: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_1e7b:
	/* 0x1e7b: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1e81:
	/* 0x1e81: lea    ecx,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_1e88:
	/* 0x1e88: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e8e:
	/* 0x1e8e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e92:
	/* 0x1e92: mov    BYTE PTR [rax+0x11],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_1e95:
	/* 0x1e95: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_1e99:
	/* 0x1e99: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1e9f:
	/* 0x1e9f: lea    ecx,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_1ea6:
	/* 0x1ea6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1eac:
	/* 0x1eac: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1eb0:
	/* 0x1eb0: mov    BYTE PTR [rax+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1eb3:
	/* 0x1eb3: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_1eb7:
	/* 0x1eb7: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1ebd:
	/* 0x1ebd: lea    ecx,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_1ec4:
	/* 0x1ec4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1eca:
	/* 0x1eca: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ece:
	/* 0x1ece: mov    BYTE PTR [rax+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_1ed1:
	/* 0x1ed1: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_1ed5:
	/* 0x1ed5: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1edb:
	/* 0x1edb: lea    ecx,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_1ee2:
	/* 0x1ee2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ee8:
	/* 0x1ee8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1eec:
	/* 0x1eec: mov    BYTE PTR [rax+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1eef:
	/* 0x1eef: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_1ef3:
	/* 0x1ef3: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1ef9:
	/* 0x1ef9: lea    ecx,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_1f00:
	/* 0x1f00: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f06:
	/* 0x1f06: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f0a:
	/* 0x1f0a: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1f0d:
	/* 0x1f0d: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_1f11:
	/* 0x1f11: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1f17:
	/* 0x1f17: lea    ecx,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_1f1e:
	/* 0x1f1e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f24:
	/* 0x1f24: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f28:
	/* 0x1f28: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1f2b:
	/* 0x1f2b: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_1f2f:
	/* 0x1f2f: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1f35:
	/* 0x1f35: lea    ecx,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_1f3c:
	/* 0x1f3c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f42:
	/* 0x1f42: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f46:
	/* 0x1f46: mov    BYTE PTR [rax+0x17],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_1f49:
	/* 0x1f49: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_1f4d:
	/* 0x1f4d: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1f53:
	/* 0x1f53: lea    ecx,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_1f5a:
	/* 0x1f5a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f60:
	/* 0x1f60: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f64:
	/* 0x1f64: mov    BYTE PTR [rax+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f67:
	/* 0x1f67: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_1f6b:
	/* 0x1f6b: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1f71:
	/* 0x1f71: lea    ecx,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_1f78:
	/* 0x1f78: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f7e:
	/* 0x1f7e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f82:
	/* 0x1f82: mov    BYTE PTR [rax+0x19],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_1f85:
	/* 0x1f85: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_1f89:
	/* 0x1f89: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1f8f:
	/* 0x1f8f: lea    ecx,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_1f96:
	/* 0x1f96: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f9c:
	/* 0x1f9c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fa0:
	/* 0x1fa0: mov    BYTE PTR [rax+0x1a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1fa3:
	/* 0x1fa3: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_1fa7:
	/* 0x1fa7: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1fad:
	/* 0x1fad: lea    ecx,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_1fb4:
	/* 0x1fb4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fba:
	/* 0x1fba: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fbe:
	/* 0x1fbe: mov    BYTE PTR [rax+0x1b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_1fc1:
	/* 0x1fc1: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_1fc5:
	/* 0x1fc5: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1fcb:
	/* 0x1fcb: lea    ecx,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_1fd2:
	/* 0x1fd2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fd8:
	/* 0x1fd8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fdc:
	/* 0x1fdc: mov    BYTE PTR [rax+0x1c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1fdf:
	/* 0x1fdf: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_1fe3:
	/* 0x1fe3: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1fe9:
	/* 0x1fe9: lea    ecx,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_1ff0:
	/* 0x1ff0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ff6:
	/* 0x1ff6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ffa:
	/* 0x1ffa: mov    BYTE PTR [rax+0x1d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_1ffd:
	/* 0x1ffd: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_2001:
	/* 0x2001: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2007:
	/* 0x2007: lea    ecx,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_200e:
	/* 0x200e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2014:
	/* 0x2014: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2018:
	/* 0x2018: mov    BYTE PTR [rax+0x1e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_201b:
	/* 0x201b: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_201f:
	/* 0x201f: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2025:
	/* 0x2025: lea    ecx,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_202c:
	/* 0x202c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2032:
	/* 0x2032: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2036:
	/* 0x2036: mov    BYTE PTR [rax+0x1f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_2039:
	/* 0x2039: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_203d:
	/* 0x203d: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2043:
	/* 0x2043: lea    ecx,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_204a:
	/* 0x204a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2050:
	/* 0x2050: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2054:
	/* 0x2054: mov    BYTE PTR [rax+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2057:
	/* 0x2057: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_205b:
	/* 0x205b: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2061:
	/* 0x2061: lea    ecx,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_2068:
	/* 0x2068: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_206e:
	/* 0x206e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2072:
	/* 0x2072: mov    BYTE PTR [rax+0x21],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_2075:
	/* 0x2075: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_2079:
	/* 0x2079: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_207f:
	/* 0x207f: lea    ecx,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_2086:
	/* 0x2086: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_208c:
	/* 0x208c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2090:
	/* 0x2090: mov    BYTE PTR [rax+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2093:
	/* 0x2093: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_2097:
	/* 0x2097: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_209d:
	/* 0x209d: lea    ecx,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_20a4:
	/* 0x20a4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20aa:
	/* 0x20aa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_20ae:
	/* 0x20ae: mov    BYTE PTR [rax+0x23],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_20b1:
	/* 0x20b1: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_20b5:
	/* 0x20b5: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_20bb:
	/* 0x20bb: lea    ecx,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_20c2:
	/* 0x20c2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20c8:
	/* 0x20c8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_20cc:
	/* 0x20cc: mov    BYTE PTR [rax+0x24],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_20cf:
	/* 0x20cf: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_20d3:
	/* 0x20d3: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_20d9:
	/* 0x20d9: lea    ecx,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_20e0:
	/* 0x20e0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20e6:
	/* 0x20e6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_20ea:
	/* 0x20ea: mov    BYTE PTR [rax+0x25],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_20ed:
	/* 0x20ed: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_20f1:
	/* 0x20f1: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_20f7:
	/* 0x20f7: lea    ecx,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_20fe:
	/* 0x20fe: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2104:
	/* 0x2104: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2108:
	/* 0x2108: mov    BYTE PTR [rax+0x26],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_210b:
	/* 0x210b: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_210f:
	/* 0x210f: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2115:
	/* 0x2115: lea    ecx,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_211c:
	/* 0x211c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2122:
	/* 0x2122: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2126:
	/* 0x2126: mov    BYTE PTR [rax+0x27],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_2129:
	/* 0x2129: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_212d:
	/* 0x212d: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2133:
	/* 0x2133: lea    ecx,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_213a:
	/* 0x213a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2140:
	/* 0x2140: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2144:
	/* 0x2144: mov    BYTE PTR [rax+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2147:
	/* 0x2147: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_214b:
	/* 0x214b: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2151:
	/* 0x2151: lea    ecx,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_2158:
	/* 0x2158: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_215e:
	/* 0x215e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2162:
	/* 0x2162: mov    BYTE PTR [rax+0x29],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_2165:
	/* 0x2165: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_2169:
	/* 0x2169: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_216f:
	/* 0x216f: lea    ecx,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_2176:
	/* 0x2176: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_217c:
	/* 0x217c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2180:
	/* 0x2180: mov    BYTE PTR [rax+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2183:
	/* 0x2183: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_2187:
	/* 0x2187: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_218d:
	/* 0x218d: lea    ecx,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_2194:
	/* 0x2194: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_219a:
	/* 0x219a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_219e:
	/* 0x219e: mov    BYTE PTR [rax+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_21a1:
	/* 0x21a1: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_21a5:
	/* 0x21a5: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_21ab:
	/* 0x21ab: lea    ecx,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_21b2:
	/* 0x21b2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21b8:
	/* 0x21b8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_21bc:
	/* 0x21bc: mov    BYTE PTR [rax+0x2c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_21bf:
	/* 0x21bf: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_21c3:
	/* 0x21c3: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_21c9:
	/* 0x21c9: lea    ecx,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_21d0:
	/* 0x21d0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21d6:
	/* 0x21d6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_21da:
	/* 0x21da: mov    BYTE PTR [rax+0x2d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_21dd:
	/* 0x21dd: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_21e1:
	/* 0x21e1: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_21e7:
	/* 0x21e7: lea    ecx,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_21ee:
	/* 0x21ee: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21f4:
	/* 0x21f4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_21f8:
	/* 0x21f8: mov    BYTE PTR [rax+0x2e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_21fb:
	/* 0x21fb: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_21ff:
	/* 0x21ff: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2205:
	/* 0x2205: lea    ecx,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_220c:
	/* 0x220c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2212:
	/* 0x2212: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2216:
	/* 0x2216: mov    BYTE PTR [rax+0x2f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_2219:
	/* 0x2219: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_221d:
	/* 0x221d: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2223:
	/* 0x2223: lea    ecx,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_222a:
	/* 0x222a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2230:
	/* 0x2230: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2234:
	/* 0x2234: mov    BYTE PTR [rax+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2237:
	/* 0x2237: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_223b:
	/* 0x223b: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2241:
	/* 0x2241: lea    ecx,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_2248:
	/* 0x2248: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_224e:
	/* 0x224e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2252:
	/* 0x2252: mov    BYTE PTR [rax+0x31],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_2255:
	/* 0x2255: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_2259:
	/* 0x2259: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_225f:
	/* 0x225f: lea    ecx,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_2266:
	/* 0x2266: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_226c:
	/* 0x226c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2270:
	/* 0x2270: mov    BYTE PTR [rax+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_2273:
	/* 0x2273: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_2277:
	/* 0x2277: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_227d:
	/* 0x227d: lea    ecx,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_2284:
	/* 0x2284: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_228a:
	/* 0x228a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_228e:
	/* 0x228e: mov    BYTE PTR [rax+0x33],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_2291:
	/* 0x2291: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_2295:
	/* 0x2295: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_229b:
	/* 0x229b: lea    ecx,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_22a2:
	/* 0x22a2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22a8:
	/* 0x22a8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22ac:
	/* 0x22ac: mov    BYTE PTR [rax+0x34],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_22af:
	/* 0x22af: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_22b3:
	/* 0x22b3: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_22b9:
	/* 0x22b9: lea    ecx,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_22c0:
	/* 0x22c0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22c6:
	/* 0x22c6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22ca:
	/* 0x22ca: mov    BYTE PTR [rax+0x35],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_22cd:
	/* 0x22cd: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_22d1:
	/* 0x22d1: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_22d7:
	/* 0x22d7: lea    ecx,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_22de:
	/* 0x22de: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22e4:
	/* 0x22e4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22e8:
	/* 0x22e8: mov    BYTE PTR [rax+0x36],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_22eb:
	/* 0x22eb: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_22ef:
	/* 0x22ef: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_22f5:
	/* 0x22f5: lea    ecx,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_22fc:
	/* 0x22fc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2302:
	/* 0x2302: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2306:
	/* 0x2306: mov    BYTE PTR [rax+0x37],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_2309:
	/* 0x2309: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_230d:
	/* 0x230d: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2313:
	/* 0x2313: lea    ecx,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_231a:
	/* 0x231a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2320:
	/* 0x2320: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2324:
	/* 0x2324: mov    BYTE PTR [rax+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2327:
	/* 0x2327: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_232b:
	/* 0x232b: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2331:
	/* 0x2331: lea    ecx,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_2338:
	/* 0x2338: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_233e:
	/* 0x233e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2342:
	/* 0x2342: mov    BYTE PTR [rax+0x39],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_2345:
	/* 0x2345: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_2349:
	/* 0x2349: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_234f:
	/* 0x234f: lea    ecx,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_2356:
	/* 0x2356: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_235c:
	/* 0x235c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2360:
	/* 0x2360: mov    BYTE PTR [rax+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_2363:
	/* 0x2363: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_2367:
	/* 0x2367: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_236d:
	/* 0x236d: lea    ecx,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_2374:
	/* 0x2374: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_237a:
	/* 0x237a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_237e:
	/* 0x237e: mov    BYTE PTR [rax+0x3b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_2381:
	/* 0x2381: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_2385:
	/* 0x2385: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_238b:
	/* 0x238b: lea    ecx,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_2392:
	/* 0x2392: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2398:
	/* 0x2398: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_239c:
	/* 0x239c: mov    BYTE PTR [rax+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_239f:
	/* 0x239f: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_23a3:
	/* 0x23a3: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_23a9:
	/* 0x23a9: lea    ecx,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_23b0:
	/* 0x23b0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23b6:
	/* 0x23b6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_23ba:
	/* 0x23ba: mov    BYTE PTR [rax+0x3d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_23bd:
	/* 0x23bd: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_23c1:
	/* 0x23c1: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_23c7:
	/* 0x23c7: lea    ecx,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_23ce:
	/* 0x23ce: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23d4:
	/* 0x23d4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_23d8:
	/* 0x23d8: mov    BYTE PTR [rax+0x3e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_23db:
	/* 0x23db: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_23df:
	/* 0x23df: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_23e5:
	/* 0x23e5: lea    ecx,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_23ec:
	/* 0x23ec: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23f2:
	/* 0x23f2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_23f6:
	/* 0x23f6: mov    BYTE PTR [rax+0x3f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_23f9:
	/* 0x23f9: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_23fd:
	/* 0x23fd: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2403:
	/* 0x2403: lea    ecx,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_240a:
	/* 0x240a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2410:
	/* 0x2410: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2414:
	/* 0x2414: mov    BYTE PTR [rax+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2417:
	/* 0x2417: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_241b:
	/* 0x241b: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2421:
	/* 0x2421: lea    ecx,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_2428:
	/* 0x2428: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_242e:
	/* 0x242e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2432:
	/* 0x2432: mov    BYTE PTR [rax+0x41],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_2435:
	/* 0x2435: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_2439:
	/* 0x2439: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_243f:
	/* 0x243f: lea    ecx,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_2446:
	/* 0x2446: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_244c:
	/* 0x244c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2450:
	/* 0x2450: mov    BYTE PTR [rax+0x42],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_2453:
	/* 0x2453: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_2457:
	/* 0x2457: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_245d:
	/* 0x245d: lea    ecx,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_2464:
	/* 0x2464: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_246a:
	/* 0x246a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_246e:
	/* 0x246e: mov    BYTE PTR [rax+0x43],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_2471:
	/* 0x2471: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_2475:
	/* 0x2475: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_247b:
	/* 0x247b: lea    ecx,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_2482:
	/* 0x2482: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2488:
	/* 0x2488: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_248c:
	/* 0x248c: mov    BYTE PTR [rax+0x44],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_248f:
	/* 0x248f: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_2493:
	/* 0x2493: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_2499:
	/* 0x2499: lea    ecx,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_24a0:
	/* 0x24a0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24a6:
	/* 0x24a6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24aa:
	/* 0x24aa: mov    BYTE PTR [rax+0x45],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_24ad:
	/* 0x24ad: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_24b1:
	/* 0x24b1: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_24b7:
	/* 0x24b7: lea    ecx,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_24be:
	/* 0x24be: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
	return 9412ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9412ULL: goto x86_l_24c4;
	case 9416ULL: goto x86_l_24c8;
	case 9419ULL: goto x86_l_24cb;
	case 9423ULL: goto x86_l_24cf;
	case 9429ULL: goto x86_l_24d5;
	case 9436ULL: goto x86_l_24dc;
	case 9442ULL: goto x86_l_24e2;
	case 9446ULL: goto x86_l_24e6;
	case 9449ULL: goto x86_l_24e9;
	case 9453ULL: goto x86_l_24ed;
	case 9459ULL: goto x86_l_24f3;
	case 9466ULL: goto x86_l_24fa;
	case 9472ULL: goto x86_l_2500;
	case 9476ULL: goto x86_l_2504;
	case 9479ULL: goto x86_l_2507;
	case 9483ULL: goto x86_l_250b;
	case 9489ULL: goto x86_l_2511;
	case 9496ULL: goto x86_l_2518;
	case 9502ULL: goto x86_l_251e;
	case 9506ULL: goto x86_l_2522;
	case 9509ULL: goto x86_l_2525;
	case 9513ULL: goto x86_l_2529;
	case 9519ULL: goto x86_l_252f;
	case 9526ULL: goto x86_l_2536;
	case 9532ULL: goto x86_l_253c;
	case 9536ULL: goto x86_l_2540;
	case 9539ULL: goto x86_l_2543;
	case 9543ULL: goto x86_l_2547;
	case 9549ULL: goto x86_l_254d;
	case 9556ULL: goto x86_l_2554;
	case 9562ULL: goto x86_l_255a;
	case 9566ULL: goto x86_l_255e;
	case 9569ULL: goto x86_l_2561;
	case 9573ULL: goto x86_l_2565;
	case 9579ULL: goto x86_l_256b;
	case 9586ULL: goto x86_l_2572;
	case 9592ULL: goto x86_l_2578;
	case 9596ULL: goto x86_l_257c;
	case 9599ULL: goto x86_l_257f;
	case 9603ULL: goto x86_l_2583;
	case 9609ULL: goto x86_l_2589;
	case 9616ULL: goto x86_l_2590;
	case 9622ULL: goto x86_l_2596;
	case 9626ULL: goto x86_l_259a;
	case 9629ULL: goto x86_l_259d;
	case 9633ULL: goto x86_l_25a1;
	case 9639ULL: goto x86_l_25a7;
	case 9646ULL: goto x86_l_25ae;
	case 9652ULL: goto x86_l_25b4;
	case 9656ULL: goto x86_l_25b8;
	case 9659ULL: goto x86_l_25bb;
	case 9663ULL: goto x86_l_25bf;
	case 9669ULL: goto x86_l_25c5;
	case 9676ULL: goto x86_l_25cc;
	case 9682ULL: goto x86_l_25d2;
	case 9686ULL: goto x86_l_25d6;
	case 9689ULL: goto x86_l_25d9;
	case 9693ULL: goto x86_l_25dd;
	case 9699ULL: goto x86_l_25e3;
	case 9706ULL: goto x86_l_25ea;
	case 9712ULL: goto x86_l_25f0;
	case 9716ULL: goto x86_l_25f4;
	case 9719ULL: goto x86_l_25f7;
	case 9723ULL: goto x86_l_25fb;
	case 9729ULL: goto x86_l_2601;
	case 9736ULL: goto x86_l_2608;
	case 9742ULL: goto x86_l_260e;
	case 9746ULL: goto x86_l_2612;
	case 9749ULL: goto x86_l_2615;
	case 9753ULL: goto x86_l_2619;
	case 9759ULL: goto x86_l_261f;
	case 9766ULL: goto x86_l_2626;
	case 9772ULL: goto x86_l_262c;
	case 9776ULL: goto x86_l_2630;
	case 9779ULL: goto x86_l_2633;
	case 9783ULL: goto x86_l_2637;
	case 9789ULL: goto x86_l_263d;
	case 9796ULL: goto x86_l_2644;
	case 9802ULL: goto x86_l_264a;
	case 9806ULL: goto x86_l_264e;
	case 9809ULL: goto x86_l_2651;
	case 9813ULL: goto x86_l_2655;
	case 9819ULL: goto x86_l_265b;
	case 9826ULL: goto x86_l_2662;
	case 9832ULL: goto x86_l_2668;
	case 9836ULL: goto x86_l_266c;
	case 9839ULL: goto x86_l_266f;
	case 9843ULL: goto x86_l_2673;
	case 9849ULL: goto x86_l_2679;
	case 9856ULL: goto x86_l_2680;
	case 9862ULL: goto x86_l_2686;
	case 9866ULL: goto x86_l_268a;
	case 9869ULL: goto x86_l_268d;
	case 9873ULL: goto x86_l_2691;
	case 9879ULL: goto x86_l_2697;
	case 9886ULL: goto x86_l_269e;
	case 9892ULL: goto x86_l_26a4;
	case 9896ULL: goto x86_l_26a8;
	case 9899ULL: goto x86_l_26ab;
	case 9903ULL: goto x86_l_26af;
	case 9909ULL: goto x86_l_26b5;
	case 9916ULL: goto x86_l_26bc;
	case 9922ULL: goto x86_l_26c2;
	case 9926ULL: goto x86_l_26c6;
	case 9929ULL: goto x86_l_26c9;
	case 9933ULL: goto x86_l_26cd;
	case 9939ULL: goto x86_l_26d3;
	case 9946ULL: goto x86_l_26da;
	case 9952ULL: goto x86_l_26e0;
	case 9956ULL: goto x86_l_26e4;
	case 9959ULL: goto x86_l_26e7;
	case 9963ULL: goto x86_l_26eb;
	case 9969ULL: goto x86_l_26f1;
	case 9976ULL: goto x86_l_26f8;
	case 9982ULL: goto x86_l_26fe;
	case 9986ULL: goto x86_l_2702;
	case 9989ULL: goto x86_l_2705;
	case 9993ULL: goto x86_l_2709;
	case 9999ULL: goto x86_l_270f;
	case 10006ULL: goto x86_l_2716;
	case 10012ULL: goto x86_l_271c;
	case 10016ULL: goto x86_l_2720;
	case 10019ULL: goto x86_l_2723;
	case 10023ULL: goto x86_l_2727;
	case 10029ULL: goto x86_l_272d;
	case 10036ULL: goto x86_l_2734;
	case 10042ULL: goto x86_l_273a;
	case 10046ULL: goto x86_l_273e;
	case 10049ULL: goto x86_l_2741;
	case 10053ULL: goto x86_l_2745;
	case 10059ULL: goto x86_l_274b;
	case 10066ULL: goto x86_l_2752;
	case 10072ULL: goto x86_l_2758;
	case 10076ULL: goto x86_l_275c;
	case 10079ULL: goto x86_l_275f;
	case 10083ULL: goto x86_l_2763;
	case 10089ULL: goto x86_l_2769;
	case 10096ULL: goto x86_l_2770;
	case 10102ULL: goto x86_l_2776;
	case 10106ULL: goto x86_l_277a;
	case 10109ULL: goto x86_l_277d;
	case 10113ULL: goto x86_l_2781;
	case 10115ULL: goto x86_l_2783;
	case 10122ULL: goto x86_l_278a;
	case 10128ULL: goto x86_l_2790;
	case 10132ULL: goto x86_l_2794;
	case 10135ULL: goto x86_l_2797;
	case 10139ULL: goto x86_l_279b;
	case 10141ULL: goto x86_l_279d;
	case 10148ULL: goto x86_l_27a4;
	case 10154ULL: goto x86_l_27aa;
	case 10158ULL: goto x86_l_27ae;
	case 10161ULL: goto x86_l_27b1;
	case 10165ULL: goto x86_l_27b5;
	case 10167ULL: goto x86_l_27b7;
	case 10174ULL: goto x86_l_27be;
	case 10180ULL: goto x86_l_27c4;
	case 10184ULL: goto x86_l_27c8;
	case 10187ULL: goto x86_l_27cb;
	case 10191ULL: goto x86_l_27cf;
	case 10193ULL: goto x86_l_27d1;
	case 10200ULL: goto x86_l_27d8;
	case 10207ULL: goto x86_l_27df;
	case 10212ULL: goto x86_l_27e4;
	case 10215ULL: goto x86_l_27e7;
	case 10220ULL: goto x86_l_27ec;
	case 10225ULL: goto x86_l_27f1;
	case 10228ULL: goto x86_l_27f4;
	case 10233ULL: goto x86_l_27f9;
	case 10238ULL: goto x86_l_27fe;
	case 10242ULL: goto x86_l_2802;
	case 10245ULL: goto x86_l_2805;
	case 10249ULL: goto x86_l_2809;
	case 10257ULL: goto x86_l_2811;
	case 10262ULL: goto x86_l_2816;
	case 10269ULL: goto x86_l_281d;
	case 10274ULL: goto x86_l_2822;
	case 10276ULL: goto x86_l_2824;
	case 10279ULL: goto x86_l_2827;
	case 10282ULL: goto x86_l_282a;
	case 10285ULL: goto x86_l_282d;
	case 10291ULL: goto x86_l_2833;
	case 10296ULL: goto x86_l_2838;
	case 10299ULL: goto x86_l_283b;
	case 10305ULL: goto x86_l_2841;
	case 10310ULL: goto x86_l_2846;
	case 10317ULL: goto x86_l_284d;
	case 10322ULL: goto x86_l_2852;
	case 10324ULL: goto x86_l_2854;
	case 10327ULL: goto x86_l_2857;
	case 10333ULL: goto x86_l_285d;
	case 10338ULL: goto x86_l_2862;
	case 10342ULL: goto x86_l_2866;
	case 10349ULL: goto x86_l_286d;
	case 10354ULL: goto x86_l_2872;
	case 10358ULL: goto x86_l_2876;
	case 10365ULL: goto x86_l_287d;
	case 10367ULL: goto x86_l_287f;
	case 10370ULL: goto x86_l_2882;
	case 10374ULL: goto x86_l_2886;
	case 10379ULL: goto x86_l_288b;
	case 10382ULL: goto x86_l_288e;
	case 10384ULL: goto x86_l_2890;
	case 10389ULL: goto x86_l_2895;
	case 10394ULL: goto x86_l_289a;
	case 10397ULL: goto x86_l_289d;
	case 10399ULL: goto x86_l_289f;
	case 10402ULL: goto x86_l_28a2;
	case 10405ULL: goto x86_l_28a5;
	case 10409ULL: goto x86_l_28a9;
	case 10414ULL: goto x86_l_28ae;
	case 10417ULL: goto x86_l_28b1;
	case 10419ULL: goto x86_l_28b3;
	case 10422ULL: goto x86_l_28b6;
	case 10428ULL: goto x86_l_28bc;
	case 10433ULL: goto x86_l_28c1;
	case 10435ULL: goto x86_l_28c3;
	case 10440ULL: goto x86_l_28c8;
	case 10442ULL: goto x86_l_28ca;
	case 10445ULL: goto x86_l_28cd;
	case 10448ULL: goto x86_l_28d0;
	case 10450ULL: goto x86_l_28d2;
	case 10453ULL: goto x86_l_28d5;
	case 10459ULL: goto x86_l_28db;
	case 10462ULL: goto x86_l_28de;
	case 10468ULL: goto x86_l_28e4;
	case 10471ULL: goto x86_l_28e7;
	case 10477ULL: goto x86_l_28ed;
	case 10480ULL: goto x86_l_28f0;
	case 10486ULL: goto x86_l_28f6;
	case 10489ULL: goto x86_l_28f9;
	case 10494ULL: goto x86_l_28fe;
	case 10498ULL: goto x86_l_2902;
	case 10502ULL: goto x86_l_2906;
	case 10504ULL: goto x86_l_2908;
	case 10507ULL: goto x86_l_290b;
	case 10511ULL: goto x86_l_290f;
	case 10514ULL: goto x86_l_2912;
	case 10518ULL: goto x86_l_2916;
	case 10521ULL: goto x86_l_2919;
	case 10524ULL: goto x86_l_291c;
	case 10527ULL: goto x86_l_291f;
	case 10529ULL: goto x86_l_2921;
	case 10532ULL: goto x86_l_2924;
	case 10535ULL: goto x86_l_2927;
	case 10537ULL: goto x86_l_2929;
	case 10540ULL: goto x86_l_292c;
	case 10543ULL: goto x86_l_292f;
	case 10549ULL: goto x86_l_2935;
	case 10552ULL: goto x86_l_2938;
	case 10558ULL: goto x86_l_293e;
	case 10563ULL: goto x86_l_2943;
	case 10566ULL: goto x86_l_2946;
	case 10568ULL: goto x86_l_2948;
	case 10573ULL: goto x86_l_294d;
	case 10576ULL: goto x86_l_2950;
	case 10582ULL: goto x86_l_2956;
	case 10587ULL: goto x86_l_295b;
	case 10590ULL: goto x86_l_295e;
	case 10596ULL: goto x86_l_2964;
	case 10601ULL: goto x86_l_2969;
	case 10604ULL: goto x86_l_296c;
	case 10606ULL: goto x86_l_296e;
	case 10610ULL: goto x86_l_2972;
	case 10613ULL: goto x86_l_2975;
	case 10619ULL: goto x86_l_297b;
	case 10622ULL: goto x86_l_297e;
	case 10628ULL: goto x86_l_2984;
	case 10631ULL: goto x86_l_2987;
	case 10634ULL: goto x86_l_298a;
	case 10637ULL: goto x86_l_298d;
	case 10641ULL: goto x86_l_2991;
	case 10646ULL: goto x86_l_2996;
	case 10653ULL: goto x86_l_299d;
	case 10658ULL: goto x86_l_29a2;
	case 10660ULL: goto x86_l_29a4;
	case 10663ULL: goto x86_l_29a7;
	case 10669ULL: goto x86_l_29ad;
	case 10677ULL: goto x86_l_29b5;
	case 10682ULL: goto x86_l_29ba;
	case 10687ULL: goto x86_l_29bf;
	case 10690ULL: goto x86_l_29c2;
	case 10693ULL: goto x86_l_29c5;
	case 10699ULL: goto x86_l_29cb;
	case 10702ULL: goto x86_l_29ce;
	case 10706ULL: goto x86_l_29d2;
	case 10710ULL: goto x86_l_29d6;
	case 10715ULL: goto x86_l_29db;
	case 10722ULL: goto x86_l_29e2;
	case 10725ULL: goto x86_l_29e5;
	case 10730ULL: goto x86_l_29ea;
	case 10732ULL: goto x86_l_29ec;
	case 10735ULL: goto x86_l_29ef;
	case 10741ULL: goto x86_l_29f5;
	case 10745ULL: goto x86_l_29f9;
	case 10750ULL: goto x86_l_29fe;
	case 10755ULL: goto x86_l_2a03;
	case 10760ULL: goto x86_l_2a08;
	case 10763ULL: goto x86_l_2a0b;
	case 10765ULL: goto x86_l_2a0d;
	case 10769ULL: goto x86_l_2a11;
	case 10774ULL: goto x86_l_2a16;
	case 10779ULL: goto x86_l_2a1b;
	case 10783ULL: goto x86_l_2a1f;
	case 10786ULL: goto x86_l_2a22;
	case 10790ULL: goto x86_l_2a26;
	case 10798ULL: goto x86_l_2a2e;
	case 10803ULL: goto x86_l_2a33;
	case 10810ULL: goto x86_l_2a3a;
	case 10815ULL: goto x86_l_2a3f;
	case 10817ULL: goto x86_l_2a41;
	case 10820ULL: goto x86_l_2a44;
	case 10826ULL: goto x86_l_2a4a;
	case 10832ULL: goto x86_l_2a50;
	case 10835ULL: goto x86_l_2a53;
	case 10838ULL: goto x86_l_2a56;
	case 10844ULL: goto x86_l_2a5c;
	case 10849ULL: goto x86_l_2a61;
	case 10856ULL: goto x86_l_2a68;
	case 10861ULL: goto x86_l_2a6d;
	case 10863ULL: goto x86_l_2a6f;
	case 10866ULL: goto x86_l_2a72;
	case 10872ULL: goto x86_l_2a78;
	case 10877ULL: goto x86_l_2a7d;
	case 10883ULL: goto x86_l_2a83;
	case 10888ULL: goto x86_l_2a88;
	case 10891ULL: goto x86_l_2a8b;
	case 10898ULL: goto x86_l_2a92;
	case 10900ULL: goto x86_l_2a94;
	case 10903ULL: goto x86_l_2a97;
	case 10907ULL: goto x86_l_2a9b;
	case 10912ULL: goto x86_l_2aa0;
	case 10917ULL: goto x86_l_2aa5;
	case 10920ULL: goto x86_l_2aa8;
	case 10922ULL: goto x86_l_2aaa;
	case 10927ULL: goto x86_l_2aaf;
	case 10930ULL: goto x86_l_2ab2;
	case 10933ULL: goto x86_l_2ab5;
	case 10935ULL: goto x86_l_2ab7;
	case 10940ULL: goto x86_l_2abc;
	case 10948ULL: goto x86_l_2ac4;
	case 10954ULL: goto x86_l_2aca;
	case 10960ULL: goto x86_l_2ad0;
	case 10965ULL: goto x86_l_2ad5;
	case 10969ULL: goto x86_l_2ad9;
	case 10972ULL: goto x86_l_2adc;
	case 10978ULL: goto x86_l_2ae2;
	case 10981ULL: goto x86_l_2ae5;
	case 10984ULL: goto x86_l_2ae8;
	case 10987ULL: goto x86_l_2aeb;
	case 10989ULL: goto x86_l_2aed;
	case 10991ULL: goto x86_l_2aef;
	case 10994ULL: goto x86_l_2af2;
	case 11000ULL: goto x86_l_2af8;
	case 11002ULL: goto x86_l_2afa;
	case 11008ULL: goto x86_l_2b00;
	case 11013ULL: goto x86_l_2b05;
	case 11017ULL: goto x86_l_2b09;
	case 11020ULL: goto x86_l_2b0c;
	case 11025ULL: goto x86_l_2b11;
	case 11029ULL: goto x86_l_2b15;
	case 11034ULL: goto x86_l_2b1a;
	case 11038ULL: goto x86_l_2b1e;
	case 11041ULL: goto x86_l_2b21;
	case 11046ULL: goto x86_l_2b26;
	case 11050ULL: goto x86_l_2b2a;
	case 11055ULL: goto x86_l_2b2f;
	case 11060ULL: goto x86_l_2b34;
	case 11064ULL: goto x86_l_2b38;
	case 11067ULL: goto x86_l_2b3b;
	case 11070ULL: goto x86_l_2b3e;
	case 11074ULL: goto x86_l_2b42;
	case 11079ULL: goto x86_l_2b47;
	case 11086ULL: goto x86_l_2b4e;
	case 11091ULL: goto x86_l_2b53;
	case 11093ULL: goto x86_l_2b55;
	case 11096ULL: goto x86_l_2b58;
	case 11102ULL: goto x86_l_2b5e;
	case 11110ULL: goto x86_l_2b66;
	case 11114ULL: goto x86_l_2b6a;
	case 11118ULL: goto x86_l_2b6e;
	case 11123ULL: goto x86_l_2b73;
	case 11128ULL: goto x86_l_2b78;
	case 11132ULL: goto x86_l_2b7c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_24c4:
	/* 0x24c4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24c8:
	/* 0x24c8: mov    BYTE PTR [rax+0x46],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_24cb:
	/* 0x24cb: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_24cf:
	/* 0x24cf: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_24d5:
	/* 0x24d5: lea    ecx,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_24dc:
	/* 0x24dc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24e2:
	/* 0x24e2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24e6:
	/* 0x24e6: mov    BYTE PTR [rax+0x47],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_24e9:
	/* 0x24e9: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_24ed:
	/* 0x24ed: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_24f3:
	/* 0x24f3: lea    ecx,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_24fa:
	/* 0x24fa: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2500:
	/* 0x2500: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2504:
	/* 0x2504: mov    BYTE PTR [rax+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2507:
	/* 0x2507: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_250b:
	/* 0x250b: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_2511:
	/* 0x2511: lea    ecx,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_2518:
	/* 0x2518: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_251e:
	/* 0x251e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2522:
	/* 0x2522: mov    BYTE PTR [rax+0x49],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_2525:
	/* 0x2525: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_2529:
	/* 0x2529: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_252f:
	/* 0x252f: lea    ecx,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_2536:
	/* 0x2536: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_253c:
	/* 0x253c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2540:
	/* 0x2540: mov    BYTE PTR [rax+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_2543:
	/* 0x2543: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_2547:
	/* 0x2547: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_254d:
	/* 0x254d: lea    ecx,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_2554:
	/* 0x2554: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_255a:
	/* 0x255a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_255e:
	/* 0x255e: mov    BYTE PTR [rax+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_2561:
	/* 0x2561: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_2565:
	/* 0x2565: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_256b:
	/* 0x256b: lea    ecx,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_2572:
	/* 0x2572: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2578:
	/* 0x2578: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_257c:
	/* 0x257c: mov    BYTE PTR [rax+0x4c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_257f:
	/* 0x257f: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_2583:
	/* 0x2583: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_2589:
	/* 0x2589: lea    ecx,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_2590:
	/* 0x2590: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2596:
	/* 0x2596: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_259a:
	/* 0x259a: mov    BYTE PTR [rax+0x4d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_259d:
	/* 0x259d: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_25a1:
	/* 0x25a1: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_25a7:
	/* 0x25a7: lea    ecx,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_25ae:
	/* 0x25ae: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25b4:
	/* 0x25b4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_25b8:
	/* 0x25b8: mov    BYTE PTR [rax+0x4e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_25bb:
	/* 0x25bb: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_25bf:
	/* 0x25bf: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_25c5:
	/* 0x25c5: lea    ecx,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_25cc:
	/* 0x25cc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25d2:
	/* 0x25d2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_25d6:
	/* 0x25d6: mov    BYTE PTR [rax+0x4f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_25d9:
	/* 0x25d9: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_25dd:
	/* 0x25dd: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_25e3:
	/* 0x25e3: lea    ecx,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_25ea:
	/* 0x25ea: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25f0:
	/* 0x25f0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_25f4:
	/* 0x25f4: mov    BYTE PTR [rax+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_25f7:
	/* 0x25f7: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_25fb:
	/* 0x25fb: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_2601:
	/* 0x2601: lea    ecx,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_2608:
	/* 0x2608: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_260e:
	/* 0x260e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2612:
	/* 0x2612: mov    BYTE PTR [rax+0x51],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_2615:
	/* 0x2615: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_2619:
	/* 0x2619: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_261f:
	/* 0x261f: lea    ecx,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_2626:
	/* 0x2626: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_262c:
	/* 0x262c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2630:
	/* 0x2630: mov    BYTE PTR [rax+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_2633:
	/* 0x2633: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_2637:
	/* 0x2637: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_263d:
	/* 0x263d: lea    ecx,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_2644:
	/* 0x2644: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_264a:
	/* 0x264a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_264e:
	/* 0x264e: mov    BYTE PTR [rax+0x53],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_2651:
	/* 0x2651: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_2655:
	/* 0x2655: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_265b:
	/* 0x265b: lea    ecx,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_2662:
	/* 0x2662: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2668:
	/* 0x2668: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_266c:
	/* 0x266c: mov    BYTE PTR [rax+0x54],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_266f:
	/* 0x266f: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_2673:
	/* 0x2673: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_2679:
	/* 0x2679: lea    ecx,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_2680:
	/* 0x2680: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2686:
	/* 0x2686: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_268a:
	/* 0x268a: mov    BYTE PTR [rax+0x55],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_268d:
	/* 0x268d: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_2691:
	/* 0x2691: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_2697:
	/* 0x2697: lea    ecx,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_269e:
	/* 0x269e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26a4:
	/* 0x26a4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_26a8:
	/* 0x26a8: mov    BYTE PTR [rax+0x56],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_26ab:
	/* 0x26ab: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_26af:
	/* 0x26af: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_26b5:
	/* 0x26b5: lea    ecx,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_26bc:
	/* 0x26bc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26c2:
	/* 0x26c2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_26c6:
	/* 0x26c6: mov    BYTE PTR [rax+0x57],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_26c9:
	/* 0x26c9: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_26cd:
	/* 0x26cd: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_26d3:
	/* 0x26d3: lea    ecx,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_26da:
	/* 0x26da: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26e0:
	/* 0x26e0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_26e4:
	/* 0x26e4: mov    BYTE PTR [rax+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_26e7:
	/* 0x26e7: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_26eb:
	/* 0x26eb: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_26f1:
	/* 0x26f1: lea    ecx,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_26f8:
	/* 0x26f8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26fe:
	/* 0x26fe: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2702:
	/* 0x2702: mov    BYTE PTR [rax+0x59],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_2705:
	/* 0x2705: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_2709:
	/* 0x2709: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_270f:
	/* 0x270f: lea    ecx,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_2716:
	/* 0x2716: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_271c:
	/* 0x271c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2720:
	/* 0x2720: mov    BYTE PTR [rax+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_2723:
	/* 0x2723: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_2727:
	/* 0x2727: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_272d:
	/* 0x272d: lea    ecx,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_2734:
	/* 0x2734: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_273a:
	/* 0x273a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_273e:
	/* 0x273e: mov    BYTE PTR [rax+0x5b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_2741:
	/* 0x2741: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_2745:
	/* 0x2745: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_274b:
	/* 0x274b: lea    ecx,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_2752:
	/* 0x2752: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2758:
	/* 0x2758: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_275c:
	/* 0x275c: mov    BYTE PTR [rax+0x5c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_275f:
	/* 0x275f: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_2763:
	/* 0x2763: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_2769:
	/* 0x2769: lea    ecx,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_2770:
	/* 0x2770: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2776:
	/* 0x2776: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_277a:
	/* 0x277a: mov    BYTE PTR [rax+0x5d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_277d:
	/* 0x277d: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_2781:
	/* 0x2781: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_2783:
	/* 0x2783: lea    ecx,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_278a:
	/* 0x278a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2790:
	/* 0x2790: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2794:
	/* 0x2794: mov    BYTE PTR [rax+0x5e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_2797:
	/* 0x2797: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_279b:
	/* 0x279b: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_279d:
	/* 0x279d: lea    ecx,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_27a4:
	/* 0x27a4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27aa:
	/* 0x27aa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_27ae:
	/* 0x27ae: mov    BYTE PTR [rax+0x5f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_27b1:
	/* 0x27b1: cmp    r13,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 92ULL);
x86_l_27b5:
	/* 0x27b5: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_27b7:
	/* 0x27b7: lea    ecx,[r13+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_27be:
	/* 0x27be: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27c4:
	/* 0x27c4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_27c8:
	/* 0x27c8: mov    BYTE PTR [rax+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_27cb:
	/* 0x27cb: cmp    r13,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 93ULL);
x86_l_27cf:
	/* 0x27cf: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e7;
	}
x86_l_27d1:
	/* 0x27d1: add    r13d,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_27d8:
	/* 0x27d8: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27df:
	/* 0x27df: movzx  ecx,BYTE PTR [rdx+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_27e4:
	/* 0x27e4: mov    BYTE PTR [rax+0x61],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_27e7:
	/* 0x27e7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_27ec:
	/* 0x27ec: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27f1:
	/* 0x27f1: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_27f4:
	/* 0x27f4: jmp    31c2 <generic_retuprobe_filter_arg_2+0x31c2> */
	return 12738ULL;
x86_l_27f9:
	/* 0x27f9: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27fe:
	/* 0x27fe: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2802:
	/* 0x2802: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2805:
	/* 0x2805: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2809:
	/* 0x2809: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2811:
	/* 0x2811: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2816:
	/* 0x2816: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_281d:
	/* 0x281d: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2822:
	/* 0x2822: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2824:
	/* 0x2824: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2827:
	/* 0x2827: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_282a:
	/* 0x282a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_282d:
	/* 0x282d: je     31d3 <generic_retuprobe_filter_arg_2+0x31d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12755ULL;
	}
x86_l_2833:
	/* 0x2833: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2838:
	/* 0x2838: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_283b:
	/* 0x283b: je     31d3 <generic_retuprobe_filter_arg_2+0x31d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12755ULL;
	}
x86_l_2841:
	/* 0x2841: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2846:
	/* 0x2846: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_284d:
	/* 0x284d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2852:
	/* 0x2852: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2854:
	/* 0x2854: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2857:
	/* 0x2857: je     31d0 <generic_retuprobe_filter_arg_2+0x31d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12752ULL;
	}
x86_l_285d:
	/* 0x285d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2862:
	/* 0x2862: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2866:
	/* 0x2866: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_286d:
	/* 0x286d: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_2872:
	/* 0x2872: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_2876:
	/* 0x2876: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_287d:
	/* 0x287d: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_287f:
	/* 0x287f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2882:
	/* 0x2882: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2886:
	/* 0x2886: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_288b:
	/* 0x288b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_288e:
	/* 0x288e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2890:
	/* 0x2890: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2895:
	/* 0x2895: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_289a:
	/* 0x289a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_289d:
	/* 0x289d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_289f:
	/* 0x289f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28a2:
	/* 0x28a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28a5:
	/* 0x28a5: setne  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_NE);
x86_l_28a9:
	/* 0x28a9: jmp    31d3 <generic_retuprobe_filter_arg_2+0x31d3> */
	return 12755ULL;
x86_l_28ae:
	/* 0x28ae: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_28b1:
	/* 0x28b1: je     28c3 <generic_retuprobe_filter_arg_2+0x28c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28c3;
	}
x86_l_28b3:
	/* 0x28b3: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_28b6:
	/* 0x28b6: jne    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12928ULL;
	}
x86_l_28bc:
	/* 0x28bc: movzx  r8d,WORD PTR [rdi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_28c1:
	/* 0x28c1: jmp    28c8 <generic_retuprobe_filter_arg_2+0x28c8> */
	goto x86_l_28c8;
x86_l_28c3:
	/* 0x28c3: movzx  r8d,WORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_28c8:
	/* 0x28c8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28ca:
	/* 0x28ca: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28cd:
	/* 0x28cd: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28d0:
	/* 0x28d0: jmp    2919 <generic_retuprobe_filter_arg_2+0x2919> */
	goto x86_l_2919;
x86_l_28d2:
	/* 0x28d2: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_28d5:
	/* 0x28d5: je     2d33 <generic_retuprobe_filter_arg_2+0x2d33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11571ULL;
	}
x86_l_28db:
	/* 0x28db: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_28de:
	/* 0x28de: jne    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12928ULL;
	}
x86_l_28e4:
	/* 0x28e4: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_28e7:
	/* 0x28e7: jne    2ef9 <generic_retuprobe_filter_arg_2+0x2ef9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12025ULL;
	}
x86_l_28ed:
	/* 0x28ed: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_28f0:
	/* 0x28f0: jne    2f06 <generic_retuprobe_filter_arg_2+0x2f06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12038ULL;
	}
x86_l_28f6:
	/* 0x28f6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28f9:
	/* 0x28f9: jmp    2f15 <generic_retuprobe_filter_arg_2+0x2f15> */
	return 12053ULL;
x86_l_28fe:
	/* 0x28fe: mov    rdx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2902:
	/* 0x2902: mov    r9,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2906:
	/* 0x2906: jmp    290f <generic_retuprobe_filter_arg_2+0x290f> */
	goto x86_l_290f;
x86_l_2908:
	/* 0x2908: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_290b:
	/* 0x290b: mov    r9,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_290f:
	/* 0x290f: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2912:
	/* 0x2912: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2916:
	/* 0x2916: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2919:
	/* 0x2919: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_291c:
	/* 0x291c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_291f:
	/* 0x291f: jg     2943 <generic_retuprobe_filter_arg_2+0x2943> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2943;
	}
x86_l_2921:
	/* 0x2921: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_2924:
	/* 0x2924: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2927:
	/* 0x2927: jb     296e <generic_retuprobe_filter_arg_2+0x296e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_296e;
	}
x86_l_2929:
	/* 0x2929: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_292c:
	/* 0x292c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_292f:
	/* 0x292f: jb     29cb <generic_retuprobe_filter_arg_2+0x29cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_29cb;
	}
x86_l_2935:
	/* 0x2935: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2938:
	/* 0x2938: je     2d38 <generic_retuprobe_filter_arg_2+0x2d38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11576ULL;
	}
x86_l_293e:
	/* 0x293e: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	return 12928ULL;
x86_l_2943:
	/* 0x2943: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2946:
	/* 0x2946: ja     29bf <generic_retuprobe_filter_arg_2+0x29bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29bf;
	}
x86_l_2948:
	/* 0x2948: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_294d:
	/* 0x294d: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2950:
	/* 0x2950: jb     2b05 <generic_retuprobe_filter_arg_2+0x2b05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2b05;
	}
x86_l_2956:
	/* 0x2956: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_295b:
	/* 0x295b: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_295e:
	/* 0x295e: jb     2b1a <generic_retuprobe_filter_arg_2+0x2b1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2b1a;
	}
x86_l_2964:
	/* 0x2964: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_2969:
	/* 0x2969: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_296c:
	/* 0x296c: jae    29bf <generic_retuprobe_filter_arg_2+0x29bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_29bf;
	}
x86_l_296e:
	/* 0x296e: movzx  eax,WORD PTR [rdi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2972:
	/* 0x2972: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_2975:
	/* 0x2975: je     2b2f <generic_retuprobe_filter_arg_2+0x2b2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b2f;
	}
x86_l_297b:
	/* 0x297b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_297e:
	/* 0x297e: jne    2bba <generic_retuprobe_filter_arg_2+0x2bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11194ULL;
	}
x86_l_2984:
	/* 0x2984: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2987:
	/* 0x2987: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_298a:
	/* 0x298a: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_298d:
	/* 0x298d: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2991:
	/* 0x2991: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2996:
	/* 0x2996: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_299d:
	/* 0x299d: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_29a2:
	/* 0x29a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a4:
	/* 0x29a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29a7:
	/* 0x29a7: je     2dad <generic_retuprobe_filter_arg_2+0x2dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11693ULL;
	}
x86_l_29ad:
	/* 0x29ad: mov    DWORD PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_29b5:
	/* 0x29b5: mov    DWORD PTR [rsp+0x24],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_29ba:
	/* 0x29ba: jmp    2b84 <generic_retuprobe_filter_arg_2+0x2b84> */
	return 11140ULL;
x86_l_29bf:
	/* 0x29bf: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_29c2:
	/* 0x29c2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29c5:
	/* 0x29c5: jae    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12928ULL;
	}
x86_l_29cb:
	/* 0x29cb: mov    r13d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_32);
x86_l_29ce:
	/* 0x29ce: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_29d2:
	/* 0x29d2: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_29d6:
	/* 0x29d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29db:
	/* 0x29db: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_29e2:
	/* 0x29e2: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_29e5:
	/* 0x29e5: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_29ea:
	/* 0x29ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ec:
	/* 0x29ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29ef:
	/* 0x29ef: je     2f4a <generic_retuprobe_filter_arg_2+0x2f4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12106ULL;
	}
x86_l_29f5:
	/* 0x29f5: movzx  ecx,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_29f9:
	/* 0x29f9: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29fe:
	/* 0x29fe: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2a03:
	/* 0x2a03: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a08:
	/* 0x2a08: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2a0b:
	/* 0x2a0b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2a0d:
	/* 0x2a0d: mov    edx,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a11:
	/* 0x2a11: jmp    2d7b <generic_retuprobe_filter_arg_2+0x2d7b> */
	return 11643ULL;
x86_l_2a16:
	/* 0x2a16: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a1b:
	/* 0x2a1b: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a1f:
	/* 0x2a1f: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a22:
	/* 0x2a22: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a26:
	/* 0x2a26: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2a2e:
	/* 0x2a2e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a33:
	/* 0x2a33: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_2a3a:
	/* 0x2a3a: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a3f:
	/* 0x2a3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a41:
	/* 0x2a41: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a44:
	/* 0x2a44: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2a4a:
	/* 0x2a4a: je     325e <generic_retuprobe_filter_arg_2+0x325e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12894ULL;
	}
x86_l_2a50:
	/* 0x2a50: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2a53:
	/* 0x2a53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a56:
	/* 0x2a56: je     325e <generic_retuprobe_filter_arg_2+0x325e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12894ULL;
	}
x86_l_2a5c:
	/* 0x2a5c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a61:
	/* 0x2a61: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_2a68:
	/* 0x2a68: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a6d:
	/* 0x2a6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a6f:
	/* 0x2a6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a72:
	/* 0x2a72: je     325b <generic_retuprobe_filter_arg_2+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12891ULL;
	}
x86_l_2a78:
	/* 0x2a78: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a7d:
	/* 0x2a7d: cmp    ecx,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_2a83:
	/* 0x2a83: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_2a88:
	/* 0x2a88: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2a8b:
	/* 0x2a8b: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_2a92:
	/* 0x2a92: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a94:
	/* 0x2a94: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2a97:
	/* 0x2a97: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2a9b:
	/* 0x2a9b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2aa0:
	/* 0x2aa0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aa5:
	/* 0x2aa5: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2aa8:
	/* 0x2aa8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2aaa:
	/* 0x2aaa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2aaf:
	/* 0x2aaf: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2ab2:
	/* 0x2ab2: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2ab5:
	/* 0x2ab5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ab7:
	/* 0x2ab7: jmp    324f <generic_retuprobe_filter_arg_2+0x324f> */
	return 12879ULL;
x86_l_2abc:
	/* 0x2abc: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2ac4:
	/* 0x2ac4: cmp    edx,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_2aca:
	/* 0x2aca: ja     2d2b <generic_retuprobe_filter_arg_2+0x2d2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11563ULL;
	}
x86_l_2ad0:
	/* 0x2ad0: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ad5:
	/* 0x2ad5: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad9:
	/* 0x2ad9: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2adc:
	/* 0x2adc: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2ae2:
	/* 0x2ae2: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2ae5:
	/* 0x2ae5: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2ae8:
	/* 0x2ae8: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2aeb:
	/* 0x2aeb: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2aed:
	/* 0x2aed: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2aef:
	/* 0x2aef: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_2af2:
	/* 0x2af2: je     2f52 <generic_retuprobe_filter_arg_2+0x2f52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12114ULL;
	}
x86_l_2af8:
	/* 0x2af8: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2afa:
	/* 0x2afa: jne    2f52 <generic_retuprobe_filter_arg_2+0x2f52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12114ULL;
	}
x86_l_2b00:
	/* 0x2b00: jmp    2f69 <generic_retuprobe_filter_arg_2+0x2f69> */
	return 12137ULL;
x86_l_2b05:
	/* 0x2b05: movzx  eax,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2b09:
	/* 0x2b09: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b0c:
	/* 0x2b0c: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2b11:
	/* 0x2b11: setb   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_B);
x86_l_2b15:
	/* 0x2b15: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	return 12928ULL;
x86_l_2b1a:
	/* 0x2b1a: movzx  eax,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2b1e:
	/* 0x2b1e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b21:
	/* 0x2b21: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2b26:
	/* 0x2b26: setae  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_AE);
x86_l_2b2a:
	/* 0x2b2a: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	return 12928ULL;
x86_l_2b2f:
	/* 0x2b2f: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b34:
	/* 0x2b34: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b38:
	/* 0x2b38: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_2b3b:
	/* 0x2b3b: mov    eax,DWORD PTR [rsi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2b3e:
	/* 0x2b3e: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2b42:
	/* 0x2b42: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b47:
	/* 0x2b47: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_2b4e:
	/* 0x2b4e: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2b53:
	/* 0x2b53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b55:
	/* 0x2b55: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b58:
	/* 0x2b58: je     2dad <generic_retuprobe_filter_arg_2+0x2dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11693ULL;
	}
x86_l_2b5e:
	/* 0x2b5e: mov    DWORD PTR [rsp+0x20],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953600ULL);
x86_l_2b66:
	/* 0x2b66: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b6a:
	/* 0x2b6a: mov    DWORD PTR [rsp+0x24],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2b6e:
	/* 0x2b6e: mov    DWORD PTR [rsp+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b73:
	/* 0x2b73: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b78:
	/* 0x2b78: mov    DWORD PTR [rsp+0x2c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2b7c:
	/* 0x2b7c: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
	return 11136ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11136ULL: goto x86_l_2b80;
	case 11140ULL: goto x86_l_2b84;
	case 11145ULL: goto x86_l_2b89;
	case 11150ULL: goto x86_l_2b8e;
	case 11153ULL: goto x86_l_2b91;
	case 11155ULL: goto x86_l_2b93;
	case 11159ULL: goto x86_l_2b97;
	case 11162ULL: goto x86_l_2b9a;
	case 11165ULL: goto x86_l_2b9d;
	case 11171ULL: goto x86_l_2ba3;
	case 11174ULL: goto x86_l_2ba6;
	case 11177ULL: goto x86_l_2ba9;
	case 11179ULL: goto x86_l_2bab;
	case 11182ULL: goto x86_l_2bae;
	case 11185ULL: goto x86_l_2bb1;
	case 11189ULL: goto x86_l_2bb5;
	case 11194ULL: goto x86_l_2bba;
	case 11196ULL: goto x86_l_2bbc;
	case 11200ULL: goto x86_l_2bc0;
	case 11205ULL: goto x86_l_2bc5;
	case 11208ULL: goto x86_l_2bc8;
	case 11213ULL: goto x86_l_2bcd;
	case 11217ULL: goto x86_l_2bd1;
	case 11223ULL: goto x86_l_2bd7;
	case 11226ULL: goto x86_l_2bda;
	case 11229ULL: goto x86_l_2bdd;
	case 11232ULL: goto x86_l_2be0;
	case 11235ULL: goto x86_l_2be3;
	case 11237ULL: goto x86_l_2be5;
	case 11241ULL: goto x86_l_2be9;
	case 11247ULL: goto x86_l_2bef;
	case 11249ULL: goto x86_l_2bf1;
	case 11255ULL: goto x86_l_2bf7;
	case 11258ULL: goto x86_l_2bfa;
	case 11263ULL: goto x86_l_2bff;
	case 11266ULL: goto x86_l_2c02;
	case 11269ULL: goto x86_l_2c05;
	case 11271ULL: goto x86_l_2c07;
	case 11274ULL: goto x86_l_2c0a;
	case 11278ULL: goto x86_l_2c0e;
	case 11283ULL: goto x86_l_2c13;
	case 11287ULL: goto x86_l_2c17;
	case 11289ULL: goto x86_l_2c19;
	case 11293ULL: goto x86_l_2c1d;
	case 11299ULL: goto x86_l_2c23;
	case 11302ULL: goto x86_l_2c26;
	case 11304ULL: goto x86_l_2c28;
	case 11309ULL: goto x86_l_2c2d;
	case 11314ULL: goto x86_l_2c32;
	case 11319ULL: goto x86_l_2c37;
	case 11323ULL: goto x86_l_2c3b;
	case 11326ULL: goto x86_l_2c3e;
	case 11330ULL: goto x86_l_2c42;
	case 11334ULL: goto x86_l_2c46;
	case 11337ULL: goto x86_l_2c49;
	case 11343ULL: goto x86_l_2c4f;
	case 11347ULL: goto x86_l_2c53;
	case 11352ULL: goto x86_l_2c58;
	case 11359ULL: goto x86_l_2c5f;
	case 11364ULL: goto x86_l_2c64;
	case 11367ULL: goto x86_l_2c67;
	case 11369ULL: goto x86_l_2c69;
	case 11372ULL: goto x86_l_2c6c;
	case 11377ULL: goto x86_l_2c71;
	case 11384ULL: goto x86_l_2c78;
	case 11387ULL: goto x86_l_2c7b;
	case 11389ULL: goto x86_l_2c7d;
	case 11392ULL: goto x86_l_2c80;
	case 11397ULL: goto x86_l_2c85;
	case 11400ULL: goto x86_l_2c88;
	case 11406ULL: goto x86_l_2c8e;
	case 11409ULL: goto x86_l_2c91;
	case 11413ULL: goto x86_l_2c95;
	case 11419ULL: goto x86_l_2c9b;
	case 11422ULL: goto x86_l_2c9e;
	case 11427ULL: goto x86_l_2ca3;
	case 11432ULL: goto x86_l_2ca8;
	case 11435ULL: goto x86_l_2cab;
	case 11439ULL: goto x86_l_2caf;
	case 11444ULL: goto x86_l_2cb4;
	case 11447ULL: goto x86_l_2cb7;
	case 11452ULL: goto x86_l_2cbc;
	case 11454ULL: goto x86_l_2cbe;
	case 11459ULL: goto x86_l_2cc3;
	case 11462ULL: goto x86_l_2cc6;
	case 11464ULL: goto x86_l_2cc8;
	case 11469ULL: goto x86_l_2ccd;
	case 11473ULL: goto x86_l_2cd1;
	case 11476ULL: goto x86_l_2cd4;
	case 11479ULL: goto x86_l_2cd7;
	case 11485ULL: goto x86_l_2cdd;
	case 11490ULL: goto x86_l_2ce2;
	case 11493ULL: goto x86_l_2ce5;
	case 11495ULL: goto x86_l_2ce7;
	case 11499ULL: goto x86_l_2ceb;
	case 11503ULL: goto x86_l_2cef;
	case 11507ULL: goto x86_l_2cf3;
	case 11510ULL: goto x86_l_2cf6;
	case 11516ULL: goto x86_l_2cfc;
	case 11518ULL: goto x86_l_2cfe;
	case 11524ULL: goto x86_l_2d04;
	case 11529ULL: goto x86_l_2d09;
	case 11535ULL: goto x86_l_2d0f;
	case 11540ULL: goto x86_l_2d14;
	case 11546ULL: goto x86_l_2d1a;
	case 11551ULL: goto x86_l_2d1f;
	case 11558ULL: goto x86_l_2d26;
	case 11563ULL: goto x86_l_2d2b;
	case 11566ULL: goto x86_l_2d2e;
	case 11571ULL: goto x86_l_2d33;
	case 11576ULL: goto x86_l_2d38;
	case 11580ULL: goto x86_l_2d3c;
	case 11584ULL: goto x86_l_2d40;
	case 11589ULL: goto x86_l_2d45;
	case 11596ULL: goto x86_l_2d4c;
	case 11599ULL: goto x86_l_2d4f;
	case 11604ULL: goto x86_l_2d54;
	case 11606ULL: goto x86_l_2d56;
	case 11609ULL: goto x86_l_2d59;
	case 11615ULL: goto x86_l_2d5f;
	case 11619ULL: goto x86_l_2d63;
	case 11624ULL: goto x86_l_2d68;
	case 11629ULL: goto x86_l_2d6d;
	case 11634ULL: goto x86_l_2d72;
	case 11637ULL: goto x86_l_2d75;
	case 11639ULL: goto x86_l_2d77;
	case 11643ULL: goto x86_l_2d7b;
	case 11645ULL: goto x86_l_2d7d;
	case 11648ULL: goto x86_l_2d80;
	case 11650ULL: goto x86_l_2d82;
	case 11655ULL: goto x86_l_2d87;
	case 11658ULL: goto x86_l_2d8a;
	case 11660ULL: goto x86_l_2d8c;
	case 11663ULL: goto x86_l_2d8f;
	case 11666ULL: goto x86_l_2d92;
	case 11668ULL: goto x86_l_2d94;
	case 11673ULL: goto x86_l_2d99;
	case 11676ULL: goto x86_l_2d9c;
	case 11678ULL: goto x86_l_2d9e;
	case 11681ULL: goto x86_l_2da1;
	case 11684ULL: goto x86_l_2da4;
	case 11688ULL: goto x86_l_2da8;
	case 11693ULL: goto x86_l_2dad;
	case 11697ULL: goto x86_l_2db1;
	case 11700ULL: goto x86_l_2db4;
	case 11703ULL: goto x86_l_2db7;
	case 11705ULL: goto x86_l_2db9;
	case 11708ULL: goto x86_l_2dbc;
	case 11711ULL: goto x86_l_2dbf;
	case 11715ULL: goto x86_l_2dc3;
	case 11720ULL: goto x86_l_2dc8;
	case 11723ULL: goto x86_l_2dcb;
	case 11726ULL: goto x86_l_2dce;
	case 11728ULL: goto x86_l_2dd0;
	case 11730ULL: goto x86_l_2dd2;
	case 11733ULL: goto x86_l_2dd5;
	case 11738ULL: goto x86_l_2dda;
	case 11742ULL: goto x86_l_2dde;
	case 11744ULL: goto x86_l_2de0;
	case 11747ULL: goto x86_l_2de3;
	case 11753ULL: goto x86_l_2de9;
	case 11756ULL: goto x86_l_2dec;
	case 11758ULL: goto x86_l_2dee;
	case 11762ULL: goto x86_l_2df2;
	case 11767ULL: goto x86_l_2df7;
	case 11772ULL: goto x86_l_2dfc;
	case 11776ULL: goto x86_l_2e00;
	case 11779ULL: goto x86_l_2e03;
	case 11783ULL: goto x86_l_2e07;
	case 11787ULL: goto x86_l_2e0b;
	case 11791ULL: goto x86_l_2e0f;
	case 11794ULL: goto x86_l_2e12;
	case 11800ULL: goto x86_l_2e18;
	case 11805ULL: goto x86_l_2e1d;
	case 11812ULL: goto x86_l_2e24;
	case 11817ULL: goto x86_l_2e29;
	case 11820ULL: goto x86_l_2e2c;
	case 11822ULL: goto x86_l_2e2e;
	case 11825ULL: goto x86_l_2e31;
	case 11830ULL: goto x86_l_2e36;
	case 11837ULL: goto x86_l_2e3d;
	case 11840ULL: goto x86_l_2e40;
	case 11842ULL: goto x86_l_2e42;
	case 11845ULL: goto x86_l_2e45;
	case 11850ULL: goto x86_l_2e4a;
	case 11853ULL: goto x86_l_2e4d;
	case 11859ULL: goto x86_l_2e53;
	case 11862ULL: goto x86_l_2e56;
	case 11866ULL: goto x86_l_2e5a;
	case 11872ULL: goto x86_l_2e60;
	case 11875ULL: goto x86_l_2e63;
	case 11880ULL: goto x86_l_2e68;
	case 11884ULL: goto x86_l_2e6c;
	case 11889ULL: goto x86_l_2e71;
	case 11894ULL: goto x86_l_2e76;
	case 11897ULL: goto x86_l_2e79;
	case 11901ULL: goto x86_l_2e7d;
	case 11906ULL: goto x86_l_2e82;
	case 11909ULL: goto x86_l_2e85;
	case 11911ULL: goto x86_l_2e87;
	case 11916ULL: goto x86_l_2e8c;
	case 11919ULL: goto x86_l_2e8f;
	case 11921ULL: goto x86_l_2e91;
	case 11926ULL: goto x86_l_2e96;
	case 11931ULL: goto x86_l_2e9b;
	case 11935ULL: goto x86_l_2e9f;
	case 11938ULL: goto x86_l_2ea2;
	case 11940ULL: goto x86_l_2ea4;
	case 11946ULL: goto x86_l_2eaa;
	case 11951ULL: goto x86_l_2eaf;
	case 11954ULL: goto x86_l_2eb2;
	case 11956ULL: goto x86_l_2eb4;
	case 11960ULL: goto x86_l_2eb8;
	case 11964ULL: goto x86_l_2ebc;
	case 11969ULL: goto x86_l_2ec1;
	case 11975ULL: goto x86_l_2ec7;
	case 11980ULL: goto x86_l_2ecc;
	case 11986ULL: goto x86_l_2ed2;
	case 11991ULL: goto x86_l_2ed7;
	case 11997ULL: goto x86_l_2edd;
	case 12002ULL: goto x86_l_2ee2;
	case 12008ULL: goto x86_l_2ee8;
	case 12013ULL: goto x86_l_2eed;
	case 12020ULL: goto x86_l_2ef4;
	case 12025ULL: goto x86_l_2ef9;
	case 12028ULL: goto x86_l_2efc;
	case 12031ULL: goto x86_l_2eff;
	case 12033ULL: goto x86_l_2f01;
	case 12036ULL: goto x86_l_2f04;
	case 12038ULL: goto x86_l_2f06;
	case 12043ULL: goto x86_l_2f0b;
	case 12046ULL: goto x86_l_2f0e;
	case 12048ULL: goto x86_l_2f10;
	case 12051ULL: goto x86_l_2f13;
	case 12053ULL: goto x86_l_2f15;
	case 12056ULL: goto x86_l_2f18;
	case 12060ULL: goto x86_l_2f1c;
	case 12064ULL: goto x86_l_2f20;
	case 12069ULL: goto x86_l_2f25;
	case 12076ULL: goto x86_l_2f2c;
	case 12081ULL: goto x86_l_2f31;
	case 12083ULL: goto x86_l_2f33;
	case 12086ULL: goto x86_l_2f36;
	case 12088ULL: goto x86_l_2f38;
	case 12091ULL: goto x86_l_2f3b;
	case 12096ULL: goto x86_l_2f40;
	case 12101ULL: goto x86_l_2f45;
	case 12106ULL: goto x86_l_2f4a;
	case 12109ULL: goto x86_l_2f4d;
	case 12114ULL: goto x86_l_2f52;
	case 12117ULL: goto x86_l_2f55;
	case 12119ULL: goto x86_l_2f57;
	case 12121ULL: goto x86_l_2f59;
	case 12123ULL: goto x86_l_2f5b;
	case 12126ULL: goto x86_l_2f5e;
	case 12131ULL: goto x86_l_2f63;
	case 12135ULL: goto x86_l_2f67;
	case 12137ULL: goto x86_l_2f69;
	case 12140ULL: goto x86_l_2f6c;
	case 12146ULL: goto x86_l_2f72;
	case 12149ULL: goto x86_l_2f75;
	case 12151ULL: goto x86_l_2f77;
	case 12155ULL: goto x86_l_2f7b;
	case 12159ULL: goto x86_l_2f7f;
	case 12162ULL: goto x86_l_2f82;
	case 12166ULL: goto x86_l_2f86;
	case 12170ULL: goto x86_l_2f8a;
	case 12174ULL: goto x86_l_2f8e;
	case 12177ULL: goto x86_l_2f91;
	case 12183ULL: goto x86_l_2f97;
	case 12188ULL: goto x86_l_2f9c;
	case 12195ULL: goto x86_l_2fa3;
	case 12200ULL: goto x86_l_2fa8;
	case 12203ULL: goto x86_l_2fab;
	case 12205ULL: goto x86_l_2fad;
	case 12208ULL: goto x86_l_2fb0;
	case 12213ULL: goto x86_l_2fb5;
	case 12220ULL: goto x86_l_2fbc;
	case 12223ULL: goto x86_l_2fbf;
	case 12225ULL: goto x86_l_2fc1;
	case 12233ULL: goto x86_l_2fc9;
	case 12236ULL: goto x86_l_2fcc;
	case 12241ULL: goto x86_l_2fd1;
	case 12244ULL: goto x86_l_2fd4;
	case 12250ULL: goto x86_l_2fda;
	case 12259ULL: goto x86_l_2fe3;
	case 12263ULL: goto x86_l_2fe7;
	case 12269ULL: goto x86_l_2fed;
	case 12274ULL: goto x86_l_2ff2;
	case 12279ULL: goto x86_l_2ff7;
	case 12282ULL: goto x86_l_2ffa;
	case 12286ULL: goto x86_l_2ffe;
	case 12291ULL: goto x86_l_3003;
	case 12294ULL: goto x86_l_3006;
	case 12299ULL: goto x86_l_300b;
	case 12301ULL: goto x86_l_300d;
	case 12306ULL: goto x86_l_3012;
	case 12309ULL: goto x86_l_3015;
	case 12311ULL: goto x86_l_3017;
	case 12316ULL: goto x86_l_301c;
	case 12321ULL: goto x86_l_3021;
	case 12325ULL: goto x86_l_3025;
	case 12328ULL: goto x86_l_3028;
	case 12330ULL: goto x86_l_302a;
	case 12336ULL: goto x86_l_3030;
	case 12341ULL: goto x86_l_3035;
	case 12349ULL: goto x86_l_303d;
	case 12351ULL: goto x86_l_303f;
	case 12355ULL: goto x86_l_3043;
	case 12359ULL: goto x86_l_3047;
	case 12364ULL: goto x86_l_304c;
	case 12370ULL: goto x86_l_3052;
	case 12375ULL: goto x86_l_3057;
	case 12381ULL: goto x86_l_305d;
	case 12386ULL: goto x86_l_3062;
	case 12392ULL: goto x86_l_3068;
	case 12397ULL: goto x86_l_306d;
	case 12403ULL: goto x86_l_3073;
	case 12408ULL: goto x86_l_3078;
	case 12415ULL: goto x86_l_307f;
	case 12420ULL: goto x86_l_3084;
	case 12423ULL: goto x86_l_3087;
	case 12429ULL: goto x86_l_308d;
	case 12434ULL: goto x86_l_3092;
	case 12440ULL: goto x86_l_3098;
	case 12445ULL: goto x86_l_309d;
	case 12451ULL: goto x86_l_30a3;
	case 12456ULL: goto x86_l_30a8;
	case 12463ULL: goto x86_l_30af;
	case 12468ULL: goto x86_l_30b4;
	case 12471ULL: goto x86_l_30b7;
	case 12474ULL: goto x86_l_30ba;
	case 12479ULL: goto x86_l_30bf;
	case 12484ULL: goto x86_l_30c4;
	case 12490ULL: goto x86_l_30ca;
	case 12495ULL: goto x86_l_30cf;
	case 12501ULL: goto x86_l_30d5;
	case 12506ULL: goto x86_l_30da;
	case 12512ULL: goto x86_l_30e0;
	case 12517ULL: goto x86_l_30e5;
	case 12524ULL: goto x86_l_30ec;
	case 12529ULL: goto x86_l_30f1;
	case 12534ULL: goto x86_l_30f6;
	case 12540ULL: goto x86_l_30fc;
	case 12545ULL: goto x86_l_3101;
	case 12551ULL: goto x86_l_3107;
	case 12556ULL: goto x86_l_310c;
	case 12562ULL: goto x86_l_3112;
	case 12567ULL: goto x86_l_3117;
	case 12574ULL: goto x86_l_311e;
	case 12579ULL: goto x86_l_3123;
	case 12584ULL: goto x86_l_3128;
	case 12591ULL: goto x86_l_312f;
	case 12593ULL: goto x86_l_3131;
	case 12598ULL: goto x86_l_3136;
	case 12605ULL: goto x86_l_313d;
	case 12607ULL: goto x86_l_313f;
	case 12612ULL: goto x86_l_3144;
	case 12619ULL: goto x86_l_314b;
	case 12621ULL: goto x86_l_314d;
	case 12626ULL: goto x86_l_3152;
	case 12633ULL: goto x86_l_3159;
	case 12638ULL: goto x86_l_315e;
	case 12640ULL: goto x86_l_3160;
	case 12643ULL: goto x86_l_3163;
	case 12649ULL: goto x86_l_3169;
	case 12654ULL: goto x86_l_316e;
	case 12659ULL: goto x86_l_3173;
	case 12664ULL: goto x86_l_3178;
	case 12671ULL: goto x86_l_317f;
	case 12673ULL: goto x86_l_3181;
	case 12678ULL: goto x86_l_3186;
	case 12685ULL: goto x86_l_318d;
	case 12687ULL: goto x86_l_318f;
	case 12692ULL: goto x86_l_3194;
	case 12699ULL: goto x86_l_319b;
	case 12701ULL: goto x86_l_319d;
	case 12706ULL: goto x86_l_31a2;
	case 12713ULL: goto x86_l_31a9;
	case 12718ULL: goto x86_l_31ae;
	case 12720ULL: goto x86_l_31b0;
	case 12723ULL: goto x86_l_31b3;
	case 12725ULL: goto x86_l_31b5;
	case 12730ULL: goto x86_l_31ba;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2b80:
	/* 0x2b80: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b84:
	/* 0x2b84: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b89:
	/* 0x2b89: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2b8e:
	/* 0x2b8e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2b91:
	/* 0x2b91: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2b93:
	/* 0x2b93: mov    ecx,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b97:
	/* 0x2b97: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_2b9a:
	/* 0x2b9a: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2b9d:
	/* 0x2b9d: jb     2db9 <generic_retuprobe_filter_arg_2+0x2db9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2db9;
	}
x86_l_2ba3:
	/* 0x2ba3: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_2ba6:
	/* 0x2ba6: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2ba9:
	/* 0x2ba9: ja     2bba <generic_retuprobe_filter_arg_2+0x2bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2bba;
	}
x86_l_2bab:
	/* 0x2bab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bae:
	/* 0x2bae: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2bb1:
	/* 0x2bb1: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2bb5:
	/* 0x2bb5: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	return 12928ULL;
x86_l_2bba:
	/* 0x2bba: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bbc:
	/* 0x2bbc: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2bc0:
	/* 0x2bc0: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	return 12928ULL;
x86_l_2bc5:
	/* 0x2bc5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bc8:
	/* 0x2bc8: jmp    31da <generic_retuprobe_filter_arg_2+0x31da> */
	return 12762ULL;
x86_l_2bcd:
	/* 0x2bcd: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2bd1:
	/* 0x2bd1: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2bd7:
	/* 0x2bd7: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2bda:
	/* 0x2bda: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2bdd:
	/* 0x2bdd: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2be0:
	/* 0x2be0: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_2be3:
	/* 0x2be3: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2be5:
	/* 0x2be5: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_2be9:
	/* 0x2be9: je     2dc8 <generic_retuprobe_filter_arg_2+0x2dc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dc8;
	}
x86_l_2bef:
	/* 0x2bef: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2bf1:
	/* 0x2bf1: jne    2dc8 <generic_retuprobe_filter_arg_2+0x2dc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2dc8;
	}
x86_l_2bf7:
	/* 0x2bf7: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_2bfa:
	/* 0x2bfa: jmp    2de0 <generic_retuprobe_filter_arg_2+0x2de0> */
	goto x86_l_2de0;
x86_l_2bff:
	/* 0x2bff: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c02:
	/* 0x2c02: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2c05:
	/* 0x2c05: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c07:
	/* 0x2c07: mov    r8d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2c0a:
	/* 0x2c0a: add    r8d,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2c0e:
	/* 0x2c0e: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2c13:
	/* 0x2c13: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2c17:
	/* 0x2c17: ja     2c28 <generic_retuprobe_filter_arg_2+0x2c28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c28;
	}
x86_l_2c19:
	/* 0x2c19: movzx  eax,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c1d:
	/* 0x2c1d: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2c23:
	/* 0x2c23: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2c26:
	/* 0x2c26: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2c28:
	/* 0x2c28: mov    DWORD PTR [rsp+0x4c],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2c2d:
	/* 0x2c2d: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c32:
	/* 0x2c32: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c37:
	/* 0x2c37: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c3b:
	/* 0x2c3b: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2c3e:
	/* 0x2c3e: mov    eax,DWORD PTR [rsi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2c42:
	/* 0x2c42: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c46:
	/* 0x2c46: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2c49:
	/* 0x2c49: je     2d2b <generic_retuprobe_filter_arg_2+0x2d2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d2b;
	}
x86_l_2c4f:
	/* 0x2c4f: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c53:
	/* 0x2c53: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c58:
	/* 0x2c58: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2c5f:
	/* 0x2c5f: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c64:
	/* 0x2c64: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2c67:
	/* 0x2c67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c69:
	/* 0x2c69: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2c6c:
	/* 0x2c6c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c71:
	/* 0x2c71: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2c78:
	/* 0x2c78: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2c7b:
	/* 0x2c7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c7d:
	/* 0x2c7d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c80:
	/* 0x2c80: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c85:
	/* 0x2c85: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2c88:
	/* 0x2c88: je     325e <generic_retuprobe_filter_arg_2+0x325e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12894ULL;
	}
x86_l_2c8e:
	/* 0x2c8e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c91:
	/* 0x2c91: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c95:
	/* 0x2c95: je     3262 <generic_retuprobe_filter_arg_2+0x3262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12898ULL;
	}
x86_l_2c9b:
	/* 0x2c9b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2c9e:
	/* 0x2c9e: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ca3:
	/* 0x2ca3: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ca8:
	/* 0x2ca8: mov    BYTE PTR [rax],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cab:
	/* 0x2cab: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2caf:
	/* 0x2caf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cb4:
	/* 0x2cb4: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_2cb7:
	/* 0x2cb7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cbc:
	/* 0x2cbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cbe:
	/* 0x2cbe: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2cc3:
	/* 0x2cc3: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_2cc6:
	/* 0x2cc6: jbe    2ce7 <generic_retuprobe_filter_arg_2+0x2ce7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2ce7;
	}
x86_l_2cc8:
	/* 0x2cc8: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ccd:
	/* 0x2ccd: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2cd1:
	/* 0x2cd1: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2cd4:
	/* 0x2cd4: sub    esi,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cd7:
	/* 0x2cd7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2cdd:
	/* 0x2cdd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ce2:
	/* 0x2ce2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2ce5:
	/* 0x2ce5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce7:
	/* 0x2ce7: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2ceb:
	/* 0x2ceb: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2cef:
	/* 0x2cef: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cf3:
	/* 0x2cf3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2cf6:
	/* 0x2cf6: jg     3084 <generic_retuprobe_filter_arg_2+0x3084> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3084;
	}
x86_l_2cfc:
	/* 0x2cfc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cfe:
	/* 0x2cfe: je     3123 <generic_retuprobe_filter_arg_2+0x3123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3123;
	}
x86_l_2d04:
	/* 0x2d04: cmp    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2d09:
	/* 0x2d09: je     313f <generic_retuprobe_filter_arg_2+0x313f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_313f;
	}
x86_l_2d0f:
	/* 0x2d0f: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2d14:
	/* 0x2d14: jne    325b <generic_retuprobe_filter_arg_2+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12891ULL;
	}
x86_l_2d1a:
	/* 0x2d1a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d1f:
	/* 0x2d1f: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2d26:
	/* 0x2d26: jmp    3159 <generic_retuprobe_filter_arg_2+0x3159> */
	goto x86_l_3159;
x86_l_2d2b:
	/* 0x2d2b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d2e:
	/* 0x2d2e: jmp    3262 <generic_retuprobe_filter_arg_2+0x3262> */
	return 12898ULL;
x86_l_2d33:
	/* 0x2d33: movzx  r15d,WORD PTR [rdi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2d38:
	/* 0x2d38: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2d3c:
	/* 0x2d3c: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2d40:
	/* 0x2d40: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d45:
	/* 0x2d45: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2d4c:
	/* 0x2d4c: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2d4f:
	/* 0x2d4f: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2d54:
	/* 0x2d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d56:
	/* 0x2d56: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d59:
	/* 0x2d59: je     2f4a <generic_retuprobe_filter_arg_2+0x2f4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f4a;
	}
x86_l_2d5f:
	/* 0x2d5f: movzx  ecx,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2d63:
	/* 0x2d63: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d68:
	/* 0x2d68: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2d6d:
	/* 0x2d6d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d72:
	/* 0x2d72: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d75:
	/* 0x2d75: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2d77:
	/* 0x2d77: mov    edx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d7b:
	/* 0x2d7b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d7d:
	/* 0x2d7d: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_2d80:
	/* 0x2d80: ja     2da4 <generic_retuprobe_filter_arg_2+0x2da4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2da4;
	}
x86_l_2d82:
	/* 0x2d82: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_2d87:
	/* 0x2d87: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2d8a:
	/* 0x2d8a: jae    2d94 <generic_retuprobe_filter_arg_2+0x2d94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2d94;
	}
x86_l_2d8c:
	/* 0x2d8c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d8f:
	/* 0x2d8f: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_2d92:
	/* 0x2d92: jmp    2da4 <generic_retuprobe_filter_arg_2+0x2da4> */
	goto x86_l_2da4;
x86_l_2d94:
	/* 0x2d94: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_2d99:
	/* 0x2d99: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2d9c:
	/* 0x2d9c: jae    2da4 <generic_retuprobe_filter_arg_2+0x2da4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2da4;
	}
x86_l_2d9e:
	/* 0x2d9e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2da1:
	/* 0x2da1: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2da4:
	/* 0x2da4: movzx  r15d,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2da8:
	/* 0x2da8: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	return 12928ULL;
x86_l_2dad:
	/* 0x2dad: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2db1:
	/* 0x2db1: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_2db4:
	/* 0x2db4: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_2db7:
	/* 0x2db7: jmp    2dbc <generic_retuprobe_filter_arg_2+0x2dbc> */
	goto x86_l_2dbc;
x86_l_2db9:
	/* 0x2db9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2dbc:
	/* 0x2dbc: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2dbf:
	/* 0x2dbf: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2dc3:
	/* 0x2dc3: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	return 12928ULL;
x86_l_2dc8:
	/* 0x2dc8: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2dcb:
	/* 0x2dcb: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2dce:
	/* 0x2dce: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2dd0:
	/* 0x2dd0: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2dd2:
	/* 0x2dd2: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2dd5:
	/* 0x2dd5: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2dda:
	/* 0x2dda: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2dde:
	/* 0x2dde: ja     2dee <generic_retuprobe_filter_arg_2+0x2dee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2dee;
	}
x86_l_2de0:
	/* 0x2de0: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2de3:
	/* 0x2de3: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2de9:
	/* 0x2de9: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2dec:
	/* 0x2dec: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2dee:
	/* 0x2dee: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2df2:
	/* 0x2df2: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2df7:
	/* 0x2df7: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dfc:
	/* 0x2dfc: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e00:
	/* 0x2e00: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2e03:
	/* 0x2e03: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e07:
	/* 0x2e07: mov    eax,DWORD PTR [rsi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2e0b:
	/* 0x2e0b: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e0f:
	/* 0x2e0f: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2e12:
	/* 0x2e12: je     31d0 <generic_retuprobe_filter_arg_2+0x31d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12752ULL;
	}
x86_l_2e18:
	/* 0x2e18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e1d:
	/* 0x2e1d: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2e24:
	/* 0x2e24: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e29:
	/* 0x2e29: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2e2c:
	/* 0x2e2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2e:
	/* 0x2e2e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2e31:
	/* 0x2e31: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e36:
	/* 0x2e36: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2e3d:
	/* 0x2e3d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2e40:
	/* 0x2e40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e42:
	/* 0x2e42: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e45:
	/* 0x2e45: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e4a:
	/* 0x2e4a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2e4d:
	/* 0x2e4d: je     31d3 <generic_retuprobe_filter_arg_2+0x31d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12755ULL;
	}
x86_l_2e53:
	/* 0x2e53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e56:
	/* 0x2e56: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e5a:
	/* 0x2e5a: je     31d7 <generic_retuprobe_filter_arg_2+0x31d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12759ULL;
	}
x86_l_2e60:
	/* 0x2e60: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2e63:
	/* 0x2e63: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e68:
	/* 0x2e68: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2e6c:
	/* 0x2e6c: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e71:
	/* 0x2e71: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e76:
	/* 0x2e76: mov    BYTE PTR [rax],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e79:
	/* 0x2e79: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2e7d:
	/* 0x2e7d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e82:
	/* 0x2e82: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_2e85:
	/* 0x2e85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e87:
	/* 0x2e87: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2e8c:
	/* 0x2e8c: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_2e8f:
	/* 0x2e8f: jbe    2eb4 <generic_retuprobe_filter_arg_2+0x2eb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2eb4;
	}
x86_l_2e91:
	/* 0x2e91: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e96:
	/* 0x2e96: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e9b:
	/* 0x2e9b: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2e9f:
	/* 0x2e9f: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2ea2:
	/* 0x2ea2: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ea4:
	/* 0x2ea4: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2eaa:
	/* 0x2eaa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2eaf:
	/* 0x2eaf: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2eb2:
	/* 0x2eb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb4:
	/* 0x2eb4: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2eb8:
	/* 0x2eb8: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ebc:
	/* 0x2ebc: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2ec1:
	/* 0x2ec1: jg     30bf <generic_retuprobe_filter_arg_2+0x30bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_30bf;
	}
x86_l_2ec7:
	/* 0x2ec7: cmp    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2ecc:
	/* 0x2ecc: je     3173 <generic_retuprobe_filter_arg_2+0x3173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3173;
	}
x86_l_2ed2:
	/* 0x2ed2: cmp    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2ed7:
	/* 0x2ed7: je     318f <generic_retuprobe_filter_arg_2+0x318f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_318f;
	}
x86_l_2edd:
	/* 0x2edd: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2ee2:
	/* 0x2ee2: jne    31d0 <generic_retuprobe_filter_arg_2+0x31d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12752ULL;
	}
x86_l_2ee8:
	/* 0x2ee8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2eed:
	/* 0x2eed: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2ef4:
	/* 0x2ef4: jmp    31a9 <generic_retuprobe_filter_arg_2+0x31a9> */
	goto x86_l_31a9;
x86_l_2ef9:
	/* 0x2ef9: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2efc:
	/* 0x2efc: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2eff:
	/* 0x2eff: jne    2f0b <generic_retuprobe_filter_arg_2+0x2f0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f0b;
	}
x86_l_2f01:
	/* 0x2f01: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2f04:
	/* 0x2f04: je     2f0b <generic_retuprobe_filter_arg_2+0x2f0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f0b;
	}
x86_l_2f06:
	/* 0x2f06: movzx  r15d,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_2f0b:
	/* 0x2f0b: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2f0e:
	/* 0x2f0e: je     2f15 <generic_retuprobe_filter_arg_2+0x2f15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f15;
	}
x86_l_2f10:
	/* 0x2f10: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2f13:
	/* 0x2f13: jne    2f4a <generic_retuprobe_filter_arg_2+0x2f4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f4a;
	}
x86_l_2f15:
	/* 0x2f15: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2f18:
	/* 0x2f18: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2f1c:
	/* 0x2f1c: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2f20:
	/* 0x2f20: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f25:
	/* 0x2f25: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2f2c:
	/* 0x2f2c: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2f31:
	/* 0x2f31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f33:
	/* 0x2f33: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f36:
	/* 0x2f36: je     2f4a <generic_retuprobe_filter_arg_2+0x2f4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f4a;
	}
x86_l_2f38:
	/* 0x2f38: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_2f3b:
	/* 0x2f3b: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f40:
	/* 0x2f40: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2f45:
	/* 0x2f45: jmp    2d6d <generic_retuprobe_filter_arg_2+0x2d6d> */
	goto x86_l_2d6d;
x86_l_2f4a:
	/* 0x2f4a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f4d:
	/* 0x2f4d: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	return 12928ULL;
x86_l_2f52:
	/* 0x2f52: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2f55:
	/* 0x2f55: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2f57:
	/* 0x2f57: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f59:
	/* 0x2f59: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2f5b:
	/* 0x2f5b: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2f5e:
	/* 0x2f5e: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2f63:
	/* 0x2f63: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2f67:
	/* 0x2f67: ja     2f77 <generic_retuprobe_filter_arg_2+0x2f77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f77;
	}
x86_l_2f69:
	/* 0x2f69: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2f6c:
	/* 0x2f6c: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2f72:
	/* 0x2f72: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2f75:
	/* 0x2f75: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2f77:
	/* 0x2f77: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2f7b:
	/* 0x2f7b: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f7f:
	/* 0x2f7f: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2f82:
	/* 0x2f82: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f86:
	/* 0x2f86: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2f8a:
	/* 0x2f8a: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f8e:
	/* 0x2f8e: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2f91:
	/* 0x2f91: je     325b <generic_retuprobe_filter_arg_2+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12891ULL;
	}
x86_l_2f97:
	/* 0x2f97: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f9c:
	/* 0x2f9c: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2fa3:
	/* 0x2fa3: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fa8:
	/* 0x2fa8: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2fab:
	/* 0x2fab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fad:
	/* 0x2fad: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2fb0:
	/* 0x2fb0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fb5:
	/* 0x2fb5: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2fbc:
	/* 0x2fbc: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2fbf:
	/* 0x2fbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fc1:
	/* 0x2fc1: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2fc9:
	/* 0x2fc9: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fcc:
	/* 0x2fcc: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2fd1:
	/* 0x2fd1: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2fd4:
	/* 0x2fd4: je     325e <generic_retuprobe_filter_arg_2+0x325e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12894ULL;
	}
x86_l_2fda:
	/* 0x2fda: cmp    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_2fe3:
	/* 0x2fe3: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fe7:
	/* 0x2fe7: je     3262 <generic_retuprobe_filter_arg_2+0x3262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12898ULL;
	}
x86_l_2fed:
	/* 0x2fed: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ff2:
	/* 0x2ff2: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ff7:
	/* 0x2ff7: mov    BYTE PTR [rax],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ffa:
	/* 0x2ffa: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2ffe:
	/* 0x2ffe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3003:
	/* 0x3003: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3006:
	/* 0x3006: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_300b:
	/* 0x300b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_300d:
	/* 0x300d: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_3012:
	/* 0x3012: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3015:
	/* 0x3015: jbe    303f <generic_retuprobe_filter_arg_2+0x303f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_303f;
	}
x86_l_3017:
	/* 0x3017: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_301c:
	/* 0x301c: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3021:
	/* 0x3021: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3025:
	/* 0x3025: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3028:
	/* 0x3028: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_302a:
	/* 0x302a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3030:
	/* 0x3030: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3035:
	/* 0x3035: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_303d:
	/* 0x303d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_303f:
	/* 0x303f: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3043:
	/* 0x3043: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3047:
	/* 0x3047: cmp    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_304c:
	/* 0x304c: jg     30f1 <generic_retuprobe_filter_arg_2+0x30f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_30f1;
	}
x86_l_3052:
	/* 0x3052: cmp    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_3057:
	/* 0x3057: je     31fe <generic_retuprobe_filter_arg_2+0x31fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12798ULL;
	}
x86_l_305d:
	/* 0x305d: cmp    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_3062:
	/* 0x3062: je     321a <generic_retuprobe_filter_arg_2+0x321a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12826ULL;
	}
x86_l_3068:
	/* 0x3068: cmp    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_306d:
	/* 0x306d: jne    325b <generic_retuprobe_filter_arg_2+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12891ULL;
	}
x86_l_3073:
	/* 0x3073: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3078:
	/* 0x3078: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_307f:
	/* 0x307f: jmp    3234 <generic_retuprobe_filter_arg_2+0x3234> */
	return 12852ULL;
x86_l_3084:
	/* 0x3084: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3087:
	/* 0x3087: je     3131 <generic_retuprobe_filter_arg_2+0x3131> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3131;
	}
x86_l_308d:
	/* 0x308d: cmp    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_3092:
	/* 0x3092: je     314d <generic_retuprobe_filter_arg_2+0x314d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_314d;
	}
x86_l_3098:
	/* 0x3098: cmp    DWORD PTR [rsp+0x8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738373ULL);
x86_l_309d:
	/* 0x309d: jne    325b <generic_retuprobe_filter_arg_2+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12891ULL;
	}
x86_l_30a3:
	/* 0x30a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30a8:
	/* 0x30a8: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_30af:
	/* 0x30af: jmp    3159 <generic_retuprobe_filter_arg_2+0x3159> */
	goto x86_l_3159;
x86_l_30b4:
	/* 0x30b4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30b7:
	/* 0x30b7: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_30ba:
	/* 0x30ba: jmp    31d7 <generic_retuprobe_filter_arg_2+0x31d7> */
	return 12759ULL;
x86_l_30bf:
	/* 0x30bf: cmp    DWORD PTR [rsp+0x8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_30c4:
	/* 0x30c4: je     3181 <generic_retuprobe_filter_arg_2+0x3181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3181;
	}
x86_l_30ca:
	/* 0x30ca: cmp    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_30cf:
	/* 0x30cf: je     319d <generic_retuprobe_filter_arg_2+0x319d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_319d;
	}
x86_l_30d5:
	/* 0x30d5: cmp    DWORD PTR [rsp+0x8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738373ULL);
x86_l_30da:
	/* 0x30da: jne    31d0 <generic_retuprobe_filter_arg_2+0x31d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12752ULL;
	}
x86_l_30e0:
	/* 0x30e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30e5:
	/* 0x30e5: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_30ec:
	/* 0x30ec: jmp    31a9 <generic_retuprobe_filter_arg_2+0x31a9> */
	goto x86_l_31a9;
x86_l_30f1:
	/* 0x30f1: cmp    DWORD PTR [rsp+0x38],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168579ULL);
x86_l_30f6:
	/* 0x30f6: je     320c <generic_retuprobe_filter_arg_2+0x320c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12812ULL;
	}
x86_l_30fc:
	/* 0x30fc: cmp    DWORD PTR [rsp+0x38],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168580ULL);
x86_l_3101:
	/* 0x3101: je     3228 <generic_retuprobe_filter_arg_2+0x3228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12840ULL;
	}
x86_l_3107:
	/* 0x3107: cmp    DWORD PTR [rsp+0x38],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168581ULL);
x86_l_310c:
	/* 0x310c: jne    325b <generic_retuprobe_filter_arg_2+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12891ULL;
	}
x86_l_3112:
	/* 0x3112: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3117:
	/* 0x3117: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_311e:
	/* 0x311e: jmp    3234 <generic_retuprobe_filter_arg_2+0x3234> */
	return 12852ULL;
x86_l_3123:
	/* 0x3123: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3128:
	/* 0x3128: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_312f:
	/* 0x312f: jmp    3159 <generic_retuprobe_filter_arg_2+0x3159> */
	goto x86_l_3159;
x86_l_3131:
	/* 0x3131: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3136:
	/* 0x3136: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_313d:
	/* 0x313d: jmp    3159 <generic_retuprobe_filter_arg_2+0x3159> */
	goto x86_l_3159;
x86_l_313f:
	/* 0x313f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3144:
	/* 0x3144: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_314b:
	/* 0x314b: jmp    3159 <generic_retuprobe_filter_arg_2+0x3159> */
	goto x86_l_3159;
x86_l_314d:
	/* 0x314d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3152:
	/* 0x3152: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_3159:
	/* 0x3159: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_315e:
	/* 0x315e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3160:
	/* 0x3160: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3163:
	/* 0x3163: je     325b <generic_retuprobe_filter_arg_2+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12891ULL;
	}
x86_l_3169:
	/* 0x3169: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_316e:
	/* 0x316e: jmp    3245 <generic_retuprobe_filter_arg_2+0x3245> */
	return 12869ULL;
x86_l_3173:
	/* 0x3173: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3178:
	/* 0x3178: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_317f:
	/* 0x317f: jmp    31a9 <generic_retuprobe_filter_arg_2+0x31a9> */
	goto x86_l_31a9;
x86_l_3181:
	/* 0x3181: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3186:
	/* 0x3186: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_318d:
	/* 0x318d: jmp    31a9 <generic_retuprobe_filter_arg_2+0x31a9> */
	goto x86_l_31a9;
x86_l_318f:
	/* 0x318f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3194:
	/* 0x3194: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_319b:
	/* 0x319b: jmp    31a9 <generic_retuprobe_filter_arg_2+0x31a9> */
	goto x86_l_31a9;
x86_l_319d:
	/* 0x319d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31a2:
	/* 0x31a2: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_31a9:
	/* 0x31a9: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31ae:
	/* 0x31ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b0:
	/* 0x31b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31b3:
	/* 0x31b3: je     31d0 <generic_retuprobe_filter_arg_2+0x31d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12752ULL;
	}
x86_l_31b5:
	/* 0x31b5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_31ba:
	/* 0x31ba: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
	return 12733ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12733ULL: goto x86_l_31bd;
	case 12738ULL: goto x86_l_31c2;
	case 12740ULL: goto x86_l_31c4;
	case 12743ULL: goto x86_l_31c7;
	case 12746ULL: goto x86_l_31ca;
	case 12750ULL: goto x86_l_31ce;
	case 12752ULL: goto x86_l_31d0;
	case 12755ULL: goto x86_l_31d3;
	case 12759ULL: goto x86_l_31d7;
	case 12762ULL: goto x86_l_31da;
	case 12765ULL: goto x86_l_31dd;
	case 12771ULL: goto x86_l_31e3;
	case 12773ULL: goto x86_l_31e5;
	case 12783ULL: goto x86_l_31ef;
	case 12787ULL: goto x86_l_31f3;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12803ULL: goto x86_l_3203;
	case 12810ULL: goto x86_l_320a;
	case 12812ULL: goto x86_l_320c;
	case 12817ULL: goto x86_l_3211;
	case 12824ULL: goto x86_l_3218;
	case 12826ULL: goto x86_l_321a;
	case 12831ULL: goto x86_l_321f;
	case 12838ULL: goto x86_l_3226;
	case 12840ULL: goto x86_l_3228;
	case 12845ULL: goto x86_l_322d;
	case 12852ULL: goto x86_l_3234;
	case 12857ULL: goto x86_l_3239;
	case 12859ULL: goto x86_l_323b;
	case 12862ULL: goto x86_l_323e;
	case 12864ULL: goto x86_l_3240;
	case 12869ULL: goto x86_l_3245;
	case 12872ULL: goto x86_l_3248;
	case 12877ULL: goto x86_l_324d;
	case 12879ULL: goto x86_l_324f;
	case 12882ULL: goto x86_l_3252;
	case 12885ULL: goto x86_l_3255;
	case 12889ULL: goto x86_l_3259;
	case 12891ULL: goto x86_l_325b;
	case 12894ULL: goto x86_l_325e;
	case 12898ULL: goto x86_l_3262;
	case 12901ULL: goto x86_l_3265;
	case 12904ULL: goto x86_l_3268;
	case 12906ULL: goto x86_l_326a;
	case 12908ULL: goto x86_l_326c;
	case 12918ULL: goto x86_l_3276;
	case 12922ULL: goto x86_l_327a;
	case 12924ULL: goto x86_l_327c;
	case 12928ULL: goto x86_l_3280;
	case 12931ULL: goto x86_l_3283;
	case 12933ULL: goto x86_l_3285;
	case 12937ULL: goto x86_l_3289;
	case 12939ULL: goto x86_l_328b;
	case 12941ULL: goto x86_l_328d;
	case 12943ULL: goto x86_l_328f;
	case 12947ULL: goto x86_l_3293;
	case 12949ULL: goto x86_l_3295;
	case 12953ULL: goto x86_l_3299;
	case 12959ULL: goto x86_l_329f;
	case 12962ULL: goto x86_l_32a2;
	case 12968ULL: goto x86_l_32a8;
	case 12972ULL: goto x86_l_32ac;
	case 12978ULL: goto x86_l_32b2;
	case 12980ULL: goto x86_l_32b4;
	case 12984ULL: goto x86_l_32b8;
	case 12990ULL: goto x86_l_32be;
	case 12994ULL: goto x86_l_32c2;
	case 13000ULL: goto x86_l_32c8;
	case 13004ULL: goto x86_l_32cc;
	case 13010ULL: goto x86_l_32d2;
	case 13014ULL: goto x86_l_32d6;
	case 13020ULL: goto x86_l_32dc;
	case 13023ULL: goto x86_l_32df;
	case 13028ULL: goto x86_l_32e4;
	case 13035ULL: goto x86_l_32eb;
	case 13040ULL: goto x86_l_32f0;
	case 13047ULL: goto x86_l_32f7;
	case 13050ULL: goto x86_l_32fa;
	case 13055ULL: goto x86_l_32ff;
	case 13057ULL: goto x86_l_3301;
	case 13062ULL: goto x86_l_3306;
	case 13069ULL: goto x86_l_330d;
	case 13072ULL: goto x86_l_3310;
	case 13077ULL: goto x86_l_3315;
	case 13079ULL: goto x86_l_3317;
	case 13081ULL: goto x86_l_3319;
	case 13088ULL: goto x86_l_3320;
	case 13090ULL: goto x86_l_3322;
	case 13091ULL: goto x86_l_3323;
	case 13096ULL: goto x86_l_3328;
	case 13099ULL: goto x86_l_332b;
	case 13107ULL: goto x86_l_3333;
	case 13109ULL: goto x86_l_3335;
	case 13115ULL: goto x86_l_333b;
	case 13123ULL: goto x86_l_3343;
	case 13125ULL: goto x86_l_3345;
	case 13131ULL: goto x86_l_334b;
	case 13139ULL: goto x86_l_3353;
	case 13141ULL: goto x86_l_3355;
	case 13147ULL: goto x86_l_335b;
	case 13155ULL: goto x86_l_3363;
	case 13157ULL: goto x86_l_3365;
	case 13163ULL: goto x86_l_336b;
	case 13171ULL: goto x86_l_3373;
	case 13173ULL: goto x86_l_3375;
	case 13179ULL: goto x86_l_337b;
	case 13187ULL: goto x86_l_3383;
	case 13189ULL: goto x86_l_3385;
	case 13196ULL: goto x86_l_338c;
	case 13201ULL: goto x86_l_3391;
	case 13208ULL: goto x86_l_3398;
	case 13211ULL: goto x86_l_339b;
	case 13216ULL: goto x86_l_33a0;
	case 13218ULL: goto x86_l_33a2;
	case 13222ULL: goto x86_l_33a6;
	case 13227ULL: goto x86_l_33ab;
	case 13229ULL: goto x86_l_33ad;
	case 13234ULL: goto x86_l_33b2;
	case 13239ULL: goto x86_l_33b7;
	case 13244ULL: goto x86_l_33bc;
	case 13251ULL: goto x86_l_33c3;
	case 13256ULL: goto x86_l_33c8;
	case 13258ULL: goto x86_l_33ca;
	case 13261ULL: goto x86_l_33cd;
	case 13267ULL: goto x86_l_33d3;
	case 13272ULL: goto x86_l_33d8;
	case 13279ULL: goto x86_l_33df;
	case 13284ULL: goto x86_l_33e4;
	case 13286ULL: goto x86_l_33e6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_31bd:
	/* 0x31bd: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_31c2:
	/* 0x31c2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_31c4:
	/* 0x31c4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31c7:
	/* 0x31c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31ca:
	/* 0x31ca: setne  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_NE);
x86_l_31ce:
	/* 0x31ce: jmp    31d3 <generic_retuprobe_filter_arg_2+0x31d3> */
	goto x86_l_31d3;
x86_l_31d0:
	/* 0x31d0: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31d3:
	/* 0x31d3: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31d7:
	/* 0x31d7: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_31da:
	/* 0x31da: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_31dd:
	/* 0x31dd: ja     3280 <generic_retuprobe_filter_arg_2+0x3280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3280;
	}
x86_l_31e3:
	/* 0x31e3: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31e5:
	/* 0x31e5: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_31ef:
	/* 0x31ef: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_31f3:
	/* 0x31f3: jb     327c <generic_retuprobe_filter_arg_2+0x327c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_327c;
	}
x86_l_31f9:
	/* 0x31f9: jmp    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	goto x86_l_3280;
x86_l_31fe:
	/* 0x31fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3203:
	/* 0x3203: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_320a:
	/* 0x320a: jmp    3234 <generic_retuprobe_filter_arg_2+0x3234> */
	goto x86_l_3234;
x86_l_320c:
	/* 0x320c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3211:
	/* 0x3211: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_3218:
	/* 0x3218: jmp    3234 <generic_retuprobe_filter_arg_2+0x3234> */
	goto x86_l_3234;
x86_l_321a:
	/* 0x321a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_321f:
	/* 0x321f: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_3226:
	/* 0x3226: jmp    3234 <generic_retuprobe_filter_arg_2+0x3234> */
	goto x86_l_3234;
x86_l_3228:
	/* 0x3228: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_322d:
	/* 0x322d: mov    rdi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_3234:
	/* 0x3234: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3239:
	/* 0x3239: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_323b:
	/* 0x323b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_323e:
	/* 0x323e: je     325b <generic_retuprobe_filter_arg_2+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_325b;
	}
x86_l_3240:
	/* 0x3240: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3245:
	/* 0x3245: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3248:
	/* 0x3248: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_324d:
	/* 0x324d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_324f:
	/* 0x324f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3252:
	/* 0x3252: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3255:
	/* 0x3255: setne  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_NE);
x86_l_3259:
	/* 0x3259: jmp    325e <generic_retuprobe_filter_arg_2+0x325e> */
	goto x86_l_325e;
x86_l_325b:
	/* 0x325b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_325e:
	/* 0x325e: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3262:
	/* 0x3262: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3265:
	/* 0x3265: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_3268:
	/* 0x3268: ja     3280 <generic_retuprobe_filter_arg_2+0x3280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3280;
	}
x86_l_326a:
	/* 0x326a: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_326c:
	/* 0x326c: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_3276:
	/* 0x3276: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_327a:
	/* 0x327a: jae    3280 <generic_retuprobe_filter_arg_2+0x3280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3280;
	}
x86_l_327c:
	/* 0x327c: xor    r15,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_3280:
	/* 0x3280: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_3283:
	/* 0x3283: je     328f <generic_retuprobe_filter_arg_2+0x328f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_328f;
	}
x86_l_3285:
	/* 0x3285: cmp    rbp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 1ULL);
x86_l_3289:
	/* 0x3289: je     3301 <generic_retuprobe_filter_arg_2+0x3301> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3301;
	}
x86_l_328b:
	/* 0x328b: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_328d:
	/* 0x328d: jne    32e4 <generic_retuprobe_filter_arg_2+0x32e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32e4;
	}
x86_l_328f:
	/* 0x328f: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_3293:
	/* 0x3293: jg     32b4 <generic_retuprobe_filter_arg_2+0x32b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_32b4;
	}
x86_l_3295:
	/* 0x3295: cmp    r12d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_3299:
	/* 0x3299: je     3328 <generic_retuprobe_filter_arg_2+0x3328> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3328;
	}
x86_l_329f:
	/* 0x329f: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_32a2:
	/* 0x32a2: je     3335 <generic_retuprobe_filter_arg_2+0x3335> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3335;
	}
x86_l_32a8:
	/* 0x32a8: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_32ac:
	/* 0x32ac: je     3345 <generic_retuprobe_filter_arg_2+0x3345> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3345;
	}
x86_l_32b2:
	/* 0x32b2: jmp    32d2 <generic_retuprobe_filter_arg_2+0x32d2> */
	goto x86_l_32d2;
x86_l_32b4:
	/* 0x32b4: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_32b8:
	/* 0x32b8: je     3355 <generic_retuprobe_filter_arg_2+0x3355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3355;
	}
x86_l_32be:
	/* 0x32be: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_32c2:
	/* 0x32c2: je     3365 <generic_retuprobe_filter_arg_2+0x3365> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3365;
	}
x86_l_32c8:
	/* 0x32c8: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_32cc:
	/* 0x32cc: je     3375 <generic_retuprobe_filter_arg_2+0x3375> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3375;
	}
x86_l_32d2:
	/* 0x32d2: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_32d6:
	/* 0x32d6: jg     33a2 <generic_retuprobe_filter_arg_2+0x33a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_33a2;
	}
x86_l_32dc:
	/* 0x32dc: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_32df:
	/* 0x32df: jmp    3385 <generic_retuprobe_filter_arg_2+0x3385> */
	goto x86_l_3385;
x86_l_32e4:
	/* 0x32e4: mov    DWORD PTR [r14+0x5ef4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_32eb:
	/* 0x32eb: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_32f0:
	/* 0x32f0: mov    rsi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_32f7:
	/* 0x32f7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_32fa:
	/* 0x32fa: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_32ff:
	/* 0x32ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3301:
	/* 0x3301: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3306:
	/* 0x3306: mov    rsi,QWORD PTR [rip+0x177f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_330d:
	/* 0x330d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3310:
	/* 0x3310: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3315:
	/* 0x3315: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3317:
	/* 0x3317: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3319:
	/* 0x3319: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_3320:
	/* 0x3320: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3322:
	/* 0x3322: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3323:
	/* 0x3323: jmp    33eb <generic_retuprobe_filter_arg_2+0x33eb> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_3328:
	/* 0x3328: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_332b:
	/* 0x332b: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_3333:
	/* 0x3333: jne    3385 <generic_retuprobe_filter_arg_2+0x3385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3385;
	}
x86_l_3335:
	/* 0x3335: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_333b:
	/* 0x333b: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_3343:
	/* 0x3343: jne    3385 <generic_retuprobe_filter_arg_2+0x3385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3385;
	}
x86_l_3345:
	/* 0x3345: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_334b:
	/* 0x334b: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_3353:
	/* 0x3353: jne    3385 <generic_retuprobe_filter_arg_2+0x3385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3385;
	}
x86_l_3355:
	/* 0x3355: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_335b:
	/* 0x335b: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_3363:
	/* 0x3363: jne    3385 <generic_retuprobe_filter_arg_2+0x3385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3385;
	}
x86_l_3365:
	/* 0x3365: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_336b:
	/* 0x336b: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_3373:
	/* 0x3373: jne    3385 <generic_retuprobe_filter_arg_2+0x3385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3385;
	}
x86_l_3375:
	/* 0x3375: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_337b:
	/* 0x337b: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_3383:
	/* 0x3383: je     33a2 <generic_retuprobe_filter_arg_2+0x33a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33a2;
	}
x86_l_3385:
	/* 0x3385: mov    DWORD PTR [r14+0x5ef0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_338c:
	/* 0x338c: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3391:
	/* 0x3391: mov    rsi,QWORD PTR [rip+0x1782] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_3398:
	/* 0x3398: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_339b:
	/* 0x339b: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_33a0:
	/* 0x33a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33a2:
	/* 0x33a2: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_33a6:
	/* 0x33a6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_33ab:
	/* 0x33ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33ad:
	/* 0x33ad: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_33b2:
	/* 0x33b2: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_33b7:
	/* 0x33b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33bc:
	/* 0x33bc: mov    rdi,QWORD PTR [rip+0x1782] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_33c3:
	/* 0x33c3: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_33c8:
	/* 0x33c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33ca:
	/* 0x33ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33cd:
	/* 0x33cd: je     3317 <generic_retuprobe_filter_arg_2+0x3317> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3317;
	}
x86_l_33d3:
	/* 0x33d3: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_33d8:
	/* 0x33d8: mov    rdi,QWORD PTR [rip+0x1782] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_33df:
	/* 0x33df: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_33e4:
	/* 0x33e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33e6:
	/* 0x33e6: jmp    3317 <generic_retuprobe_filter_arg_2+0x3317> */
	goto x86_l_3317;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11272U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1857ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1861ULL && __x86_pc <= 3700ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3706ULL && __x86_pc <= 5640ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5643ULL && __x86_pc <= 7486ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7492ULL && __x86_pc <= 9406ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9412ULL && __x86_pc <= 11132ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11136ULL && __x86_pc <= 12730ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12733ULL && __x86_pc <= 13286ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

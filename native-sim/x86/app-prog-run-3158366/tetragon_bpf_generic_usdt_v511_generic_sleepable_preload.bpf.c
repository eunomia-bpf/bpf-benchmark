extern char CONFIG_ITER_NUM;
extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 15ULL: goto x86_l_f;
	case 26ULL: goto x86_l_1a;
	case 33ULL: goto x86_l_21;
	case 41ULL: goto x86_l_29;
	case 46ULL: goto x86_l_2e;
	case 48ULL: goto x86_l_30;
	case 51ULL: goto x86_l_33;
	case 57ULL: goto x86_l_39;
	case 60ULL: goto x86_l_3c;
	case 67ULL: goto x86_l_43;
	case 72ULL: goto x86_l_48;
	case 79ULL: goto x86_l_4f;
	case 84ULL: goto x86_l_54;
	case 91ULL: goto x86_l_5b;
	case 96ULL: goto x86_l_60;
	case 100ULL: goto x86_l_64;
	case 108ULL: goto x86_l_6c;
	case 112ULL: goto x86_l_70;
	case 117ULL: goto x86_l_75;
	case 121ULL: goto x86_l_79;
	case 129ULL: goto x86_l_81;
	case 133ULL: goto x86_l_85;
	case 138ULL: goto x86_l_8a;
	case 142ULL: goto x86_l_8e;
	case 150ULL: goto x86_l_96;
	case 154ULL: goto x86_l_9a;
	case 159ULL: goto x86_l_9f;
	case 163ULL: goto x86_l_a3;
	case 171ULL: goto x86_l_ab;
	case 175ULL: goto x86_l_af;
	case 180ULL: goto x86_l_b4;
	case 184ULL: goto x86_l_b8;
	case 192ULL: goto x86_l_c0;
	case 196ULL: goto x86_l_c4;
	case 201ULL: goto x86_l_c9;
	case 205ULL: goto x86_l_cd;
	case 213ULL: goto x86_l_d5;
	case 217ULL: goto x86_l_d9;
	case 222ULL: goto x86_l_de;
	case 225ULL: goto x86_l_e1;
	case 229ULL: goto x86_l_e5;
	case 237ULL: goto x86_l_ed;
	case 241ULL: goto x86_l_f1;
	case 246ULL: goto x86_l_f6;
	case 251ULL: goto x86_l_fb;
	case 257ULL: goto x86_l_101;
	case 261ULL: goto x86_l_105;
	case 264ULL: goto x86_l_108;
	case 271ULL: goto x86_l_10f;
	case 277ULL: goto x86_l_115;
	case 282ULL: goto x86_l_11a;
	case 284ULL: goto x86_l_11c;
	case 287ULL: goto x86_l_11f;
	case 292ULL: goto x86_l_124;
	case 297ULL: goto x86_l_129;
	case 301ULL: goto x86_l_12d;
	case 305ULL: goto x86_l_131;
	case 309ULL: goto x86_l_135;
	case 316ULL: goto x86_l_13c;
	case 322ULL: goto x86_l_142;
	case 326ULL: goto x86_l_146;
	case 331ULL: goto x86_l_14b;
	case 333ULL: goto x86_l_14d;
	case 335ULL: goto x86_l_14f;
	case 337ULL: goto x86_l_151;
	case 341ULL: goto x86_l_155;
	case 344ULL: goto x86_l_158;
	case 350ULL: goto x86_l_15e;
	case 353ULL: goto x86_l_161;
	case 359ULL: goto x86_l_167;
	case 364ULL: goto x86_l_16c;
	case 367ULL: goto x86_l_16f;
	case 373ULL: goto x86_l_175;
	case 376ULL: goto x86_l_178;
	case 382ULL: goto x86_l_17e;
	case 387ULL: goto x86_l_183;
	case 392ULL: goto x86_l_188;
	case 397ULL: goto x86_l_18d;
	case 400ULL: goto x86_l_190;
	case 405ULL: goto x86_l_195;
	case 407ULL: goto x86_l_197;
	case 409ULL: goto x86_l_199;
	case 415ULL: goto x86_l_19f;
	case 417ULL: goto x86_l_1a1;
	case 422ULL: goto x86_l_1a6;
	case 430ULL: goto x86_l_1ae;
	case 438ULL: goto x86_l_1b6;
	case 444ULL: goto x86_l_1bc;
	case 447ULL: goto x86_l_1bf;
	case 453ULL: goto x86_l_1c5;
	case 456ULL: goto x86_l_1c8;
	case 462ULL: goto x86_l_1ce;
	case 465ULL: goto x86_l_1d1;
	case 471ULL: goto x86_l_1d7;
	case 479ULL: goto x86_l_1df;
	case 482ULL: goto x86_l_1e2;
	case 488ULL: goto x86_l_1e8;
	case 493ULL: goto x86_l_1ed;
	case 496ULL: goto x86_l_1f0;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 510ULL: goto x86_l_1fe;
	case 516ULL: goto x86_l_204;
	case 521ULL: goto x86_l_209;
	case 526ULL: goto x86_l_20e;
	case 529ULL: goto x86_l_211;
	case 535ULL: goto x86_l_217;
	case 540ULL: goto x86_l_21c;
	case 543ULL: goto x86_l_21f;
	case 549ULL: goto x86_l_225;
	case 552ULL: goto x86_l_228;
	case 558ULL: goto x86_l_22e;
	case 563ULL: goto x86_l_233;
	case 566ULL: goto x86_l_236;
	case 571ULL: goto x86_l_23b;
	case 576ULL: goto x86_l_240;
	case 579ULL: goto x86_l_243;
	case 584ULL: goto x86_l_248;
	case 586ULL: goto x86_l_24a;
	case 588ULL: goto x86_l_24c;
	case 594ULL: goto x86_l_252;
	case 597ULL: goto x86_l_255;
	case 603ULL: goto x86_l_25b;
	case 606ULL: goto x86_l_25e;
	case 611ULL: goto x86_l_263;
	case 616ULL: goto x86_l_268;
	case 622ULL: goto x86_l_26e;
	case 627ULL: goto x86_l_273;
	case 629ULL: goto x86_l_275;
	case 631ULL: goto x86_l_277;
	case 637ULL: goto x86_l_27d;
	case 641ULL: goto x86_l_281;
	case 648ULL: goto x86_l_288;
	case 651ULL: goto x86_l_28b;
	case 656ULL: goto x86_l_290;
	case 659ULL: goto x86_l_293;
	case 664ULL: goto x86_l_298;
	case 668ULL: goto x86_l_29c;
	case 675ULL: goto x86_l_2a3;
	case 678ULL: goto x86_l_2a6;
	case 683ULL: goto x86_l_2ab;
	case 686ULL: goto x86_l_2ae;
	case 691ULL: goto x86_l_2b3;
	case 694ULL: goto x86_l_2b6;
	case 696ULL: goto x86_l_2b8;
	case 699ULL: goto x86_l_2bb;
	case 705ULL: goto x86_l_2c1;
	case 710ULL: goto x86_l_2c6;
	case 712ULL: goto x86_l_2c8;
	case 718ULL: goto x86_l_2ce;
	case 723ULL: goto x86_l_2d3;
	case 728ULL: goto x86_l_2d8;
	case 731ULL: goto x86_l_2db;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 745ULL: goto x86_l_2e9;
	case 751ULL: goto x86_l_2ef;
	case 759ULL: goto x86_l_2f7;
	case 762ULL: goto x86_l_2fa;
	case 768ULL: goto x86_l_300;
	case 773ULL: goto x86_l_305;
	case 778ULL: goto x86_l_30a;
	case 781ULL: goto x86_l_30d;
	case 787ULL: goto x86_l_313;
	case 792ULL: goto x86_l_318;
	case 795ULL: goto x86_l_31b;
	case 801ULL: goto x86_l_321;
	case 809ULL: goto x86_l_329;
	case 812ULL: goto x86_l_32c;
	case 818ULL: goto x86_l_332;
	case 823ULL: goto x86_l_337;
	case 828ULL: goto x86_l_33c;
	case 831ULL: goto x86_l_33f;
	case 837ULL: goto x86_l_345;
	case 842ULL: goto x86_l_34a;
	case 845ULL: goto x86_l_34d;
	case 850ULL: goto x86_l_352;
	case 854ULL: goto x86_l_356;
	case 861ULL: goto x86_l_35d;
	case 865ULL: goto x86_l_361;
	case 870ULL: goto x86_l_366;
	case 875ULL: goto x86_l_36b;
	case 879ULL: goto x86_l_36f;
	case 881ULL: goto x86_l_371;
	case 884ULL: goto x86_l_374;
	case 890ULL: goto x86_l_37a;
	case 895ULL: goto x86_l_37f;
	case 900ULL: goto x86_l_384;
	case 906ULL: goto x86_l_38a;
	case 909ULL: goto x86_l_38d;
	case 914ULL: goto x86_l_392;
	case 916ULL: goto x86_l_394;
	case 918ULL: goto x86_l_396;
	case 920ULL: goto x86_l_398;
	case 925ULL: goto x86_l_39d;
	case 928ULL: goto x86_l_3a0;
	case 933ULL: goto x86_l_3a5;
	case 938ULL: goto x86_l_3aa;
	case 941ULL: goto x86_l_3ad;
	case 944ULL: goto x86_l_3b0;
	case 949ULL: goto x86_l_3b5;
	case 951ULL: goto x86_l_3b7;
	case 953ULL: goto x86_l_3b9;
	case 955ULL: goto x86_l_3bb;
	case 958ULL: goto x86_l_3be;
	case 963ULL: goto x86_l_3c3;
	case 966ULL: goto x86_l_3c6;
	case 968ULL: goto x86_l_3c8;
	case 972ULL: goto x86_l_3cc;
	case 979ULL: goto x86_l_3d3;
	case 985ULL: goto x86_l_3d9;
	case 992ULL: goto x86_l_3e0;
	case 995ULL: goto x86_l_3e3;
	case 1000ULL: goto x86_l_3e8;
	case 1003ULL: goto x86_l_3eb;
	case 1008ULL: goto x86_l_3f0;
	case 1014ULL: goto x86_l_3f6;
	case 1016ULL: goto x86_l_3f8;
	case 1021ULL: goto x86_l_3fd;
	case 1027ULL: goto x86_l_403;
	case 1030ULL: goto x86_l_406;
	case 1032ULL: goto x86_l_408;
	case 1037ULL: goto x86_l_40d;
	case 1042ULL: goto x86_l_412;
	case 1047ULL: goto x86_l_417;
	case 1052ULL: goto x86_l_41c;
	case 1054ULL: goto x86_l_41e;
	case 1056ULL: goto x86_l_420;
	case 1062ULL: goto x86_l_426;
	case 1069ULL: goto x86_l_42d;
	case 1075ULL: goto x86_l_433;
	case 1080ULL: goto x86_l_438;
	case 1085ULL: goto x86_l_43d;
	case 1090ULL: goto x86_l_442;
	case 1097ULL: goto x86_l_449;
	case 1099ULL: goto x86_l_44b;
	case 1104ULL: goto x86_l_450;
	case 1109ULL: goto x86_l_455;
	case 1114ULL: goto x86_l_45a;
	case 1119ULL: goto x86_l_45f;
	case 1121ULL: goto x86_l_461;
	case 1123ULL: goto x86_l_463;
	case 1129ULL: goto x86_l_469;
	case 1136ULL: goto x86_l_470;
	case 1142ULL: goto x86_l_476;
	case 1147ULL: goto x86_l_47b;
	case 1152ULL: goto x86_l_480;
	case 1157ULL: goto x86_l_485;
	case 1164ULL: goto x86_l_48c;
	case 1166ULL: goto x86_l_48e;
	case 1171ULL: goto x86_l_493;
	case 1176ULL: goto x86_l_498;
	case 1181ULL: goto x86_l_49d;
	case 1186ULL: goto x86_l_4a2;
	case 1188ULL: goto x86_l_4a4;
	case 1190ULL: goto x86_l_4a6;
	case 1196ULL: goto x86_l_4ac;
	case 1203ULL: goto x86_l_4b3;
	case 1209ULL: goto x86_l_4b9;
	case 1214ULL: goto x86_l_4be;
	case 1219ULL: goto x86_l_4c3;
	case 1224ULL: goto x86_l_4c8;
	case 1231ULL: goto x86_l_4cf;
	case 1233ULL: goto x86_l_4d1;
	case 1238ULL: goto x86_l_4d6;
	case 1243ULL: goto x86_l_4db;
	case 1248ULL: goto x86_l_4e0;
	case 1253ULL: goto x86_l_4e5;
	case 1255ULL: goto x86_l_4e7;
	case 1257ULL: goto x86_l_4e9;
	case 1263ULL: goto x86_l_4ef;
	case 1270ULL: goto x86_l_4f6;
	case 1276ULL: goto x86_l_4fc;
	case 1281ULL: goto x86_l_501;
	case 1286ULL: goto x86_l_506;
	case 1291ULL: goto x86_l_50b;
	case 1298ULL: goto x86_l_512;
	case 1300ULL: goto x86_l_514;
	case 1305ULL: goto x86_l_519;
	case 1310ULL: goto x86_l_51e;
	case 1315ULL: goto x86_l_523;
	case 1320ULL: goto x86_l_528;
	case 1322ULL: goto x86_l_52a;
	case 1324ULL: goto x86_l_52c;
	case 1330ULL: goto x86_l_532;
	case 1337ULL: goto x86_l_539;
	case 1343ULL: goto x86_l_53f;
	case 1348ULL: goto x86_l_544;
	case 1353ULL: goto x86_l_549;
	case 1358ULL: goto x86_l_54e;
	case 1365ULL: goto x86_l_555;
	case 1367ULL: goto x86_l_557;
	case 1372ULL: goto x86_l_55c;
	case 1377ULL: goto x86_l_561;
	case 1382ULL: goto x86_l_566;
	case 1387ULL: goto x86_l_56b;
	case 1389ULL: goto x86_l_56d;
	case 1391ULL: goto x86_l_56f;
	case 1397ULL: goto x86_l_575;
	case 1404ULL: goto x86_l_57c;
	case 1410ULL: goto x86_l_582;
	case 1415ULL: goto x86_l_587;
	case 1420ULL: goto x86_l_58c;
	case 1425ULL: goto x86_l_591;
	case 1432ULL: goto x86_l_598;
	case 1434ULL: goto x86_l_59a;
	case 1439ULL: goto x86_l_59f;
	case 1444ULL: goto x86_l_5a4;
	case 1449ULL: goto x86_l_5a9;
	case 1454ULL: goto x86_l_5ae;
	case 1456ULL: goto x86_l_5b0;
	case 1458ULL: goto x86_l_5b2;
	case 1464ULL: goto x86_l_5b8;
	case 1471ULL: goto x86_l_5bf;
	case 1477ULL: goto x86_l_5c5;
	case 1482ULL: goto x86_l_5ca;
	case 1487ULL: goto x86_l_5cf;
	case 1492ULL: goto x86_l_5d4;
	case 1499ULL: goto x86_l_5db;
	case 1501ULL: goto x86_l_5dd;
	case 1506ULL: goto x86_l_5e2;
	case 1511ULL: goto x86_l_5e7;
	case 1516ULL: goto x86_l_5ec;
	case 1521ULL: goto x86_l_5f1;
	case 1523ULL: goto x86_l_5f3;
	case 1525ULL: goto x86_l_5f5;
	case 1531ULL: goto x86_l_5fb;
	case 1538ULL: goto x86_l_602;
	case 1544ULL: goto x86_l_608;
	case 1549ULL: goto x86_l_60d;
	case 1554ULL: goto x86_l_612;
	case 1559ULL: goto x86_l_617;
	case 1566ULL: goto x86_l_61e;
	case 1568ULL: goto x86_l_620;
	case 1573ULL: goto x86_l_625;
	case 1578ULL: goto x86_l_62a;
	case 1583ULL: goto x86_l_62f;
	case 1588ULL: goto x86_l_634;
	case 1590ULL: goto x86_l_636;
	case 1592ULL: goto x86_l_638;
	case 1598ULL: goto x86_l_63e;
	case 1605ULL: goto x86_l_645;
	case 1611ULL: goto x86_l_64b;
	case 1616ULL: goto x86_l_650;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1633ULL: goto x86_l_661;
	case 1639ULL: goto x86_l_667;
	case 1644ULL: goto x86_l_66c;
	case 1649ULL: goto x86_l_671;
	case 1654ULL: goto x86_l_676;
	case 1659ULL: goto x86_l_67b;
	case 1664ULL: goto x86_l_680;
	case 1667ULL: goto x86_l_683;
	case 1669ULL: goto x86_l_685;
	case 1674ULL: goto x86_l_68a;
	case 1679ULL: goto x86_l_68f;
	case 1684ULL: goto x86_l_694;
	case 1689ULL: goto x86_l_699;
	case 1691ULL: goto x86_l_69b;
	case 1693ULL: goto x86_l_69d;
	case 1699ULL: goto x86_l_6a3;
	case 1706ULL: goto x86_l_6aa;
	case 1712ULL: goto x86_l_6b0;
	case 1717ULL: goto x86_l_6b5;
	case 1722ULL: goto x86_l_6ba;
	case 1727ULL: goto x86_l_6bf;
	case 1734ULL: goto x86_l_6c6;
	case 1736ULL: goto x86_l_6c8;
	case 1741ULL: goto x86_l_6cd;
	case 1746ULL: goto x86_l_6d2;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1758ULL: goto x86_l_6de;
	case 1760ULL: goto x86_l_6e0;
	case 1766ULL: goto x86_l_6e6;
	case 1773ULL: goto x86_l_6ed;
	case 1779ULL: goto x86_l_6f3;
	case 1784ULL: goto x86_l_6f8;
	case 1789ULL: goto x86_l_6fd;
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
	/* 0xa: mov    QWORD PTR [rsp+0x30],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f:
	/* 0xf: mov    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_1a:
	/* 0x1a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_21:
	/* 0x21: lea    rsi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_29:
	/* 0x29: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e:
	/* 0x2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30:
	/* 0x30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33:
	/* 0x33: je     11ee <generic_sleepable_preload+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4590ULL;
	}
x86_l_39:
	/* 0x39: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3c:
	/* 0x3c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_43:
	/* 0x43: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48:
	/* 0x48: lea    rcx,[r15+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4f:
	/* 0x4f: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_54:
	/* 0x54: lea    rcx,[r15+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5b:
	/* 0x5b: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_60:
	/* 0x60: lea    rcx,[r15+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_64:
	/* 0x64: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6c:
	/* 0x6c: lea    rcx,[r15+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_70:
	/* 0x70: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_75:
	/* 0x75: lea    rcx,[r15+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_79:
	/* 0x79: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_81:
	/* 0x81: lea    rcx,[r15+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_85:
	/* 0x85: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8a:
	/* 0x8a: lea    rcx,[r15+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8e:
	/* 0x8e: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_96:
	/* 0x96: lea    rcx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9a:
	/* 0x9a: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9f:
	/* 0x9f: lea    rcx,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a3:
	/* 0xa3: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ab:
	/* 0xab: lea    rcx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_af:
	/* 0xaf: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b4:
	/* 0xb4: lea    rcx,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b8:
	/* 0xb8: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c0:
	/* 0xc0: lea    rcx,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c4:
	/* 0xc4: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c9:
	/* 0xc9: lea    rcx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cd:
	/* 0xcd: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_d5:
	/* 0xd5: lea    rcx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d9:
	/* 0xd9: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_de:
	/* 0xde: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e1:
	/* 0xe1: lea    rax,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e5:
	/* 0xe5: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ed:
	/* 0xed: lea    rax,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f1:
	/* 0xf1: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f6:
	/* 0xf6: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fb:
	/* 0xfb: je     11a2 <generic_sleepable_preload+0x11a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4514ULL;
	}
x86_l_101:
	/* 0x101: lea    r14,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_105:
	/* 0x105: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_108:
	/* 0x108: add    rbx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 512ULL);
x86_l_10f:
	/* 0x10f: mov    r15d,0xbe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 190ULL);
x86_l_115:
	/* 0x115: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11a:
	/* 0x11a: jmp    142 <generic_sleepable_preload+0x142> */
	goto x86_l_142;
x86_l_11c:
	/* 0x11c: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f:
	/* 0x11f: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_124:
	/* 0x124: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_129:
	/* 0x129: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_12d:
	/* 0x12d: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_131:
	/* 0x131: add    r15,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_135:
	/* 0x135: cmp    r15,0x24e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 590ULL);
x86_l_13c:
	/* 0x13c: je     11ee <generic_sleepable_preload+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4590ULL;
	}
x86_l_142:
	/* 0x142: mov    eax,DWORD PTR [r14+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_146:
	/* 0x146: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_14b:
	/* 0x14b: je     129 <generic_sleepable_preload+0x129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_129;
	}
x86_l_14d:
	/* 0x14d: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_14f:
	/* 0x14f: js     1a6 <generic_sleepable_preload+0x1a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a6;
	}
x86_l_151:
	/* 0x151: movzx  eax,BYTE PTR [rbx+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_155:
	/* 0x155: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_158:
	/* 0x158: jg     20e <generic_sleepable_preload+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_20e;
	}
x86_l_15e:
	/* 0x15e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_161:
	/* 0x161: je     34a <generic_sleepable_preload+0x34a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34a;
	}
x86_l_167:
	/* 0x167: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_16c:
	/* 0x16c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16f:
	/* 0x16f: jne    3be <generic_sleepable_preload+0x3be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3be;
	}
x86_l_175:
	/* 0x175: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_178:
	/* 0x178: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17e:
	/* 0x17e: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_183:
	/* 0x183: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_188:
	/* 0x188: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18d:
	/* 0x18d: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_190:
	/* 0x190: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_195:
	/* 0x195: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_197:
	/* 0x197: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_199:
	/* 0x199: je     352 <generic_sleepable_preload+0x352> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_352;
	}
x86_l_19f:
	/* 0x19f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a1:
	/* 0x1a1: jmp    3be <generic_sleepable_preload+0x3be> */
	goto x86_l_3be;
x86_l_1a6:
	/* 0x1a6: movzx  eax,BYTE PTR [r14+0x2be] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 702ULL);
x86_l_1ae:
	/* 0x1ae: movzx  ecx,WORD PTR [r14+0x2bc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 700ULL);
x86_l_1b6:
	/* 0x1b6: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1bc:
	/* 0x1bc: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1bf:
	/* 0x1bf: jle    2b3 <generic_sleepable_preload+0x2b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2b3;
	}
x86_l_1c5:
	/* 0x1c5: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1c8:
	/* 0x1c8: jle    2e6 <generic_sleepable_preload+0x2e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e6;
	}
x86_l_1ce:
	/* 0x1ce: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1d1:
	/* 0x1d1: jle    972 <generic_sleepable_preload+0x972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2418ULL;
	}
x86_l_1d7:
	/* 0x1d7: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1df:
	/* 0x1df: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1e2:
	/* 0x1e2: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2446ULL;
	}
x86_l_1e8:
	/* 0x1e8: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ed:
	/* 0x1ed: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1f0:
	/* 0x1f0: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2446ULL;
	}
x86_l_1f6:
	/* 0x1f6: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1fb:
	/* 0x1fb: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1fe:
	/* 0x1fe: jne    9a1 <generic_sleepable_preload+0x9a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2465ULL;
	}
x86_l_204:
	/* 0x204: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_209:
	/* 0x209: jmp    98e <generic_sleepable_preload+0x98e> */
	return 2446ULL;
x86_l_20e:
	/* 0x20e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_211:
	/* 0x211: je     371 <generic_sleepable_preload+0x371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_371;
	}
x86_l_217:
	/* 0x217: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_21c:
	/* 0x21c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21f:
	/* 0x21f: jne    3be <generic_sleepable_preload+0x3be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3be;
	}
x86_l_225:
	/* 0x225: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_228:
	/* 0x228: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22e:
	/* 0x22e: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_233:
	/* 0x233: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_236:
	/* 0x236: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23b:
	/* 0x23b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_240:
	/* 0x240: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_243:
	/* 0x243: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_248:
	/* 0x248: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a:
	/* 0x24a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24c:
	/* 0x24c: jne    3bb <generic_sleepable_preload+0x3bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3bb;
	}
x86_l_252:
	/* 0x252: mov    edx,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_255:
	/* 0x255: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25b:
	/* 0x25b: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25e:
	/* 0x25e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_263:
	/* 0x263: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_268:
	/* 0x268: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_26e:
	/* 0x26e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_273:
	/* 0x273: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_275:
	/* 0x275: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_277:
	/* 0x277: jne    3bb <generic_sleepable_preload+0x3bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3bb;
	}
x86_l_27d:
	/* 0x27d: movzx  eax,BYTE PTR [rbx+0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 19ULL);
x86_l_281:
	/* 0x281: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_288:
	/* 0x288: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28b:
	/* 0x28b: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_290:
	/* 0x290: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_293:
	/* 0x293: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_298:
	/* 0x298: movzx  ecx,BYTE PTR [rbx+0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 19ULL);
x86_l_29c:
	/* 0x29c: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2a3:
	/* 0x2a3: mov    rdx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a6:
	/* 0x2a6: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2ab:
	/* 0x2ab: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ae:
	/* 0x2ae: jmp    3ad <generic_sleepable_preload+0x3ad> */
	goto x86_l_3ad;
x86_l_2b3:
	/* 0x2b3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_2b6:
	/* 0x2b6: jg     318 <generic_sleepable_preload+0x318> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_318;
	}
x86_l_2b8:
	/* 0x2b8: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2bb:
	/* 0x2bb: jg     936 <generic_sleepable_preload+0x936> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2358ULL;
	}
x86_l_2c1:
	/* 0x2c1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c6:
	/* 0x2c6: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2c8:
	/* 0x2c8: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2446ULL;
	}
x86_l_2ce:
	/* 0x2ce: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d3:
	/* 0x2d3: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_2d8:
	/* 0x2d8: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2db:
	/* 0x2db: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2446ULL;
	}
x86_l_2e1:
	/* 0x2e1: jmp    9a1 <generic_sleepable_preload+0x9a1> */
	return 2465ULL;
x86_l_2e6:
	/* 0x2e6: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2e9:
	/* 0x2e9: jg     918 <generic_sleepable_preload+0x918> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2328ULL;
	}
x86_l_2ef:
	/* 0x2ef: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2f7:
	/* 0x2f7: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fa:
	/* 0x2fa: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2446ULL;
	}
x86_l_300:
	/* 0x300: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_305:
	/* 0x305: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_30a:
	/* 0x30a: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_30d:
	/* 0x30d: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2446ULL;
	}
x86_l_313:
	/* 0x313: jmp    9a1 <generic_sleepable_preload+0x9a1> */
	return 2465ULL;
x86_l_318:
	/* 0x318: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_31b:
	/* 0x31b: jg     954 <generic_sleepable_preload+0x954> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2388ULL;
	}
x86_l_321:
	/* 0x321: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_329:
	/* 0x329: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_32c:
	/* 0x32c: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2446ULL;
	}
x86_l_332:
	/* 0x332: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_337:
	/* 0x337: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_33c:
	/* 0x33c: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_33f:
	/* 0x33f: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2446ULL;
	}
x86_l_345:
	/* 0x345: jmp    9a1 <generic_sleepable_preload+0x9a1> */
	return 2465ULL;
x86_l_34a:
	/* 0x34a: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34d:
	/* 0x34d: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_352:
	/* 0x352: movzx  eax,BYTE PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_356:
	/* 0x356: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_35d:
	/* 0x35d: cmp    BYTE PTR [rbx+0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77309411328ULL);
x86_l_361:
	/* 0x361: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_366:
	/* 0x366: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_36b:
	/* 0x36b: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_36f:
	/* 0x36f: jmp    3be <generic_sleepable_preload+0x3be> */
	goto x86_l_3be;
x86_l_371:
	/* 0x371: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_374:
	/* 0x374: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_37a:
	/* 0x37a: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_37f:
	/* 0x37f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_384:
	/* 0x384: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_38a:
	/* 0x38a: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_38d:
	/* 0x38d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_392:
	/* 0x392: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_394:
	/* 0x394: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_396:
	/* 0x396: jne    3bb <generic_sleepable_preload+0x3bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3bb;
	}
x86_l_398:
	/* 0x398: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_39d:
	/* 0x39d: add    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a0:
	/* 0x3a0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a5:
	/* 0x3a5: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3aa:
	/* 0x3aa: add    rdx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3ad:
	/* 0x3ad: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_3b0:
	/* 0x3b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b5:
	/* 0x3b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b7:
	/* 0x3b7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b9:
	/* 0x3b9: je     352 <generic_sleepable_preload+0x352> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_352;
	}
x86_l_3bb:
	/* 0x3bb: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3be:
	/* 0x3be: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c3:
	/* 0x3c3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c6:
	/* 0x3c6: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_3c8:
	/* 0x3c8: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3cc:
	/* 0x3cc: cmp    WORD PTR [r13+r15*1-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743764471906304ULL);
x86_l_3d3:
	/* 0x3d3: je     676 <generic_sleepable_preload+0x676> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_676;
	}
x86_l_3d9:
	/* 0x3d9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3e0:
	/* 0x3e0: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3e3:
	/* 0x3e3: mov    eax,DWORD PTR [r13+r15*1-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551538ULL);
x86_l_3e8:
	/* 0x3e8: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3eb:
	/* 0x3eb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f0:
	/* 0x3f0: movzx  eax,WORD PTR [r13+r15*1-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R15, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_3f6:
	/* 0x3f6: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_3f8:
	/* 0x3f8: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_3fd:
	/* 0x3fd: je     680 <generic_sleepable_preload+0x680> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_680;
	}
x86_l_403:
	/* 0x403: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_406:
	/* 0x406: je     426 <generic_sleepable_preload+0x426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_426;
	}
x86_l_408:
	/* 0x408: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_40d:
	/* 0x40d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_412:
	/* 0x412: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_417:
	/* 0x417: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41c:
	/* 0x41c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41e:
	/* 0x41e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_420:
	/* 0x420: js     90d <generic_sleepable_preload+0x90d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2317ULL;
	}
x86_l_426:
	/* 0x426: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_42d:
	/* 0x42d: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_433:
	/* 0x433: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_438:
	/* 0x438: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_43d:
	/* 0x43d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_442:
	/* 0x442: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_449:
	/* 0x449: je     469 <generic_sleepable_preload+0x469> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_469;
	}
x86_l_44b:
	/* 0x44b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_450:
	/* 0x450: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_455:
	/* 0x455: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45a:
	/* 0x45a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45f:
	/* 0x45f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_461:
	/* 0x461: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_463:
	/* 0x463: js     f53 <generic_sleepable_preload+0xf53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3923ULL;
	}
x86_l_469:
	/* 0x469: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_470:
	/* 0x470: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_476:
	/* 0x476: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_47b:
	/* 0x47b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_480:
	/* 0x480: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_485:
	/* 0x485: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_48c:
	/* 0x48c: je     4ac <generic_sleepable_preload+0x4ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ac;
	}
x86_l_48e:
	/* 0x48e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_493:
	/* 0x493: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_498:
	/* 0x498: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49d:
	/* 0x49d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a2:
	/* 0x4a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a4:
	/* 0x4a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a6:
	/* 0x4a6: js     f66 <generic_sleepable_preload+0xf66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3942ULL;
	}
x86_l_4ac:
	/* 0x4ac: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_4b3:
	/* 0x4b3: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_4b9:
	/* 0x4b9: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_4be:
	/* 0x4be: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c3:
	/* 0x4c3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c8:
	/* 0x4c8: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_4cf:
	/* 0x4cf: je     4ef <generic_sleepable_preload+0x4ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ef;
	}
x86_l_4d1:
	/* 0x4d1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4d6:
	/* 0x4d6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4db:
	/* 0x4db: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e0:
	/* 0x4e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e5:
	/* 0x4e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e7:
	/* 0x4e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e9:
	/* 0x4e9: js     f79 <generic_sleepable_preload+0xf79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3961ULL;
	}
x86_l_4ef:
	/* 0x4ef: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_4f6:
	/* 0x4f6: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_4fc:
	/* 0x4fc: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_501:
	/* 0x501: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_506:
	/* 0x506: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50b:
	/* 0x50b: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_512:
	/* 0x512: je     532 <generic_sleepable_preload+0x532> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_532;
	}
x86_l_514:
	/* 0x514: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_519:
	/* 0x519: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51e:
	/* 0x51e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_523:
	/* 0x523: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_528:
	/* 0x528: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52a:
	/* 0x52a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52c:
	/* 0x52c: js     f8c <generic_sleepable_preload+0xf8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3980ULL;
	}
x86_l_532:
	/* 0x532: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_539:
	/* 0x539: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_53f:
	/* 0x53f: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_544:
	/* 0x544: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_549:
	/* 0x549: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54e:
	/* 0x54e: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_555:
	/* 0x555: je     575 <generic_sleepable_preload+0x575> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_575;
	}
x86_l_557:
	/* 0x557: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55c:
	/* 0x55c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_561:
	/* 0x561: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_566:
	/* 0x566: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56b:
	/* 0x56b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56d:
	/* 0x56d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56f:
	/* 0x56f: js     f9f <generic_sleepable_preload+0xf9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3999ULL;
	}
x86_l_575:
	/* 0x575: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_57c:
	/* 0x57c: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_582:
	/* 0x582: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_587:
	/* 0x587: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_58c:
	/* 0x58c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_591:
	/* 0x591: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_598:
	/* 0x598: je     5b8 <generic_sleepable_preload+0x5b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b8;
	}
x86_l_59a:
	/* 0x59a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59f:
	/* 0x59f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a4:
	/* 0x5a4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a9:
	/* 0x5a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ae:
	/* 0x5ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b0:
	/* 0x5b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b2:
	/* 0x5b2: js     fb2 <generic_sleepable_preload+0xfb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4018ULL;
	}
x86_l_5b8:
	/* 0x5b8: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_5bf:
	/* 0x5bf: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_5c5:
	/* 0x5c5: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_5ca:
	/* 0x5ca: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5cf:
	/* 0x5cf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d4:
	/* 0x5d4: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_5db:
	/* 0x5db: je     5fb <generic_sleepable_preload+0x5fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fb;
	}
x86_l_5dd:
	/* 0x5dd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e2:
	/* 0x5e2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e7:
	/* 0x5e7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ec:
	/* 0x5ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f1:
	/* 0x5f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f3:
	/* 0x5f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f5:
	/* 0x5f5: js     115d <generic_sleepable_preload+0x115d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4445ULL;
	}
x86_l_5fb:
	/* 0x5fb: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_602:
	/* 0x602: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_608:
	/* 0x608: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_60d:
	/* 0x60d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_612:
	/* 0x612: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_617:
	/* 0x617: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_61e:
	/* 0x61e: je     63e <generic_sleepable_preload+0x63e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_63e;
	}
x86_l_620:
	/* 0x620: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_625:
	/* 0x625: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_62a:
	/* 0x62a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_62f:
	/* 0x62f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_634:
	/* 0x634: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_636:
	/* 0x636: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_638:
	/* 0x638: js     118c <generic_sleepable_preload+0x118c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4492ULL;
	}
x86_l_63e:
	/* 0x63e: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_645:
	/* 0x645: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_64b:
	/* 0x64b: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_650:
	/* 0x650: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_655:
	/* 0x655: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_65a:
	/* 0x65a: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_661:
	/* 0x661: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_667:
	/* 0x667: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_66c:
	/* 0x66c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_671:
	/* 0x671: jmp    8ee <generic_sleepable_preload+0x8ee> */
	return 2286ULL;
x86_l_676:
	/* 0x676: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_67b:
	/* 0x67b: jmp    fc0 <generic_sleepable_preload+0xfc0> */
	return 4032ULL;
x86_l_680:
	/* 0x680: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_683:
	/* 0x683: je     6a3 <generic_sleepable_preload+0x6a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a3;
	}
x86_l_685:
	/* 0x685: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_68a:
	/* 0x68a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_68f:
	/* 0x68f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_694:
	/* 0x694: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_699:
	/* 0x699: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69b:
	/* 0x69b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_69d:
	/* 0x69d: js     90d <generic_sleepable_preload+0x90d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2317ULL;
	}
x86_l_6a3:
	/* 0x6a3: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_6aa:
	/* 0x6aa: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_6b0:
	/* 0x6b0: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_6b5:
	/* 0x6b5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6ba:
	/* 0x6ba: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6bf:
	/* 0x6bf: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_6c6:
	/* 0x6c6: je     6e6 <generic_sleepable_preload+0x6e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6e6;
	}
x86_l_6c8:
	/* 0x6c8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6cd:
	/* 0x6cd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d2:
	/* 0x6d2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d7:
	/* 0x6d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6dc:
	/* 0x6dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6de:
	/* 0x6de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6e0:
	/* 0x6e0: js     f53 <generic_sleepable_preload+0xf53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3923ULL;
	}
x86_l_6e6:
	/* 0x6e6: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_6ed:
	/* 0x6ed: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_6f3:
	/* 0x6f3: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_6f8:
	/* 0x6f8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6fd:
	/* 0x6fd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 1794ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1794ULL: goto x86_l_702;
	case 1801ULL: goto x86_l_709;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1813ULL: goto x86_l_715;
	case 1818ULL: goto x86_l_71a;
	case 1823ULL: goto x86_l_71f;
	case 1825ULL: goto x86_l_721;
	case 1827ULL: goto x86_l_723;
	case 1833ULL: goto x86_l_729;
	case 1840ULL: goto x86_l_730;
	case 1846ULL: goto x86_l_736;
	case 1851ULL: goto x86_l_73b;
	case 1856ULL: goto x86_l_740;
	case 1861ULL: goto x86_l_745;
	case 1868ULL: goto x86_l_74c;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1892ULL: goto x86_l_764;
	case 1894ULL: goto x86_l_766;
	case 1900ULL: goto x86_l_76c;
	case 1907ULL: goto x86_l_773;
	case 1913ULL: goto x86_l_779;
	case 1918ULL: goto x86_l_77e;
	case 1923ULL: goto x86_l_783;
	case 1928ULL: goto x86_l_788;
	case 1935ULL: goto x86_l_78f;
	case 1937ULL: goto x86_l_791;
	case 1942ULL: goto x86_l_796;
	case 1947ULL: goto x86_l_79b;
	case 1952ULL: goto x86_l_7a0;
	case 1957ULL: goto x86_l_7a5;
	case 1959ULL: goto x86_l_7a7;
	case 1961ULL: goto x86_l_7a9;
	case 1967ULL: goto x86_l_7af;
	case 1974ULL: goto x86_l_7b6;
	case 1980ULL: goto x86_l_7bc;
	case 1985ULL: goto x86_l_7c1;
	case 1990ULL: goto x86_l_7c6;
	case 1995ULL: goto x86_l_7cb;
	case 2002ULL: goto x86_l_7d2;
	case 2004ULL: goto x86_l_7d4;
	case 2009ULL: goto x86_l_7d9;
	case 2014ULL: goto x86_l_7de;
	case 2019ULL: goto x86_l_7e3;
	case 2024ULL: goto x86_l_7e8;
	case 2026ULL: goto x86_l_7ea;
	case 2028ULL: goto x86_l_7ec;
	case 2034ULL: goto x86_l_7f2;
	case 2041ULL: goto x86_l_7f9;
	case 2047ULL: goto x86_l_7ff;
	case 2052ULL: goto x86_l_804;
	case 2057ULL: goto x86_l_809;
	case 2062ULL: goto x86_l_80e;
	case 2069ULL: goto x86_l_815;
	case 2071ULL: goto x86_l_817;
	case 2076ULL: goto x86_l_81c;
	case 2081ULL: goto x86_l_821;
	case 2086ULL: goto x86_l_826;
	case 2091ULL: goto x86_l_82b;
	case 2093ULL: goto x86_l_82d;
	case 2095ULL: goto x86_l_82f;
	case 2101ULL: goto x86_l_835;
	case 2108ULL: goto x86_l_83c;
	case 2114ULL: goto x86_l_842;
	case 2119ULL: goto x86_l_847;
	case 2124ULL: goto x86_l_84c;
	case 2129ULL: goto x86_l_851;
	case 2136ULL: goto x86_l_858;
	case 2138ULL: goto x86_l_85a;
	case 2143ULL: goto x86_l_85f;
	case 2148ULL: goto x86_l_864;
	case 2153ULL: goto x86_l_869;
	case 2158ULL: goto x86_l_86e;
	case 2160ULL: goto x86_l_870;
	case 2162ULL: goto x86_l_872;
	case 2168ULL: goto x86_l_878;
	case 2175ULL: goto x86_l_87f;
	case 2181ULL: goto x86_l_885;
	case 2186ULL: goto x86_l_88a;
	case 2191ULL: goto x86_l_88f;
	case 2196ULL: goto x86_l_894;
	case 2203ULL: goto x86_l_89b;
	case 2205ULL: goto x86_l_89d;
	case 2210ULL: goto x86_l_8a2;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2225ULL: goto x86_l_8b1;
	case 2227ULL: goto x86_l_8b3;
	case 2229ULL: goto x86_l_8b5;
	case 2235ULL: goto x86_l_8bb;
	case 2242ULL: goto x86_l_8c2;
	case 2248ULL: goto x86_l_8c8;
	case 2253ULL: goto x86_l_8cd;
	case 2258ULL: goto x86_l_8d2;
	case 2263ULL: goto x86_l_8d7;
	case 2270ULL: goto x86_l_8de;
	case 2276ULL: goto x86_l_8e4;
	case 2281ULL: goto x86_l_8e9;
	case 2286ULL: goto x86_l_8ee;
	case 2291ULL: goto x86_l_8f3;
	case 2296ULL: goto x86_l_8f8;
	case 2298ULL: goto x86_l_8fa;
	case 2300ULL: goto x86_l_8fc;
	case 2306ULL: goto x86_l_902;
	case 2312ULL: goto x86_l_908;
	case 2317ULL: goto x86_l_90d;
	case 2323ULL: goto x86_l_913;
	case 2328ULL: goto x86_l_918;
	case 2336ULL: goto x86_l_920;
	case 2339ULL: goto x86_l_923;
	case 2341ULL: goto x86_l_925;
	case 2346ULL: goto x86_l_92a;
	case 2351ULL: goto x86_l_92f;
	case 2354ULL: goto x86_l_932;
	case 2356ULL: goto x86_l_934;
	case 2358ULL: goto x86_l_936;
	case 2366ULL: goto x86_l_93e;
	case 2369ULL: goto x86_l_941;
	case 2371ULL: goto x86_l_943;
	case 2376ULL: goto x86_l_948;
	case 2381ULL: goto x86_l_94d;
	case 2384ULL: goto x86_l_950;
	case 2386ULL: goto x86_l_952;
	case 2388ULL: goto x86_l_954;
	case 2396ULL: goto x86_l_95c;
	case 2399ULL: goto x86_l_95f;
	case 2401ULL: goto x86_l_961;
	case 2406ULL: goto x86_l_966;
	case 2411ULL: goto x86_l_96b;
	case 2414ULL: goto x86_l_96e;
	case 2416ULL: goto x86_l_970;
	case 2418ULL: goto x86_l_972;
	case 2426ULL: goto x86_l_97a;
	case 2429ULL: goto x86_l_97d;
	case 2431ULL: goto x86_l_97f;
	case 2436ULL: goto x86_l_984;
	case 2441ULL: goto x86_l_989;
	case 2444ULL: goto x86_l_98c;
	case 2446ULL: goto x86_l_98e;
	case 2449ULL: goto x86_l_991;
	case 2451ULL: goto x86_l_993;
	case 2453ULL: goto x86_l_995;
	case 2458ULL: goto x86_l_99a;
	case 2460ULL: goto x86_l_99c;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2473ULL: goto x86_l_9a9;
	case 2476ULL: goto x86_l_9ac;
	case 2478ULL: goto x86_l_9ae;
	case 2482ULL: goto x86_l_9b2;
	case 2489ULL: goto x86_l_9b9;
	case 2495ULL: goto x86_l_9bf;
	case 2502ULL: goto x86_l_9c6;
	case 2505ULL: goto x86_l_9c9;
	case 2510ULL: goto x86_l_9ce;
	case 2513ULL: goto x86_l_9d1;
	case 2518ULL: goto x86_l_9d6;
	case 2524ULL: goto x86_l_9dc;
	case 2526ULL: goto x86_l_9de;
	case 2532ULL: goto x86_l_9e4;
	case 2535ULL: goto x86_l_9e7;
	case 2537ULL: goto x86_l_9e9;
	case 2542ULL: goto x86_l_9ee;
	case 2547ULL: goto x86_l_9f3;
	case 2552ULL: goto x86_l_9f8;
	case 2557ULL: goto x86_l_9fd;
	case 2562ULL: goto x86_l_a02;
	case 2564ULL: goto x86_l_a04;
	case 2566ULL: goto x86_l_a06;
	case 2572ULL: goto x86_l_a0c;
	case 2579ULL: goto x86_l_a13;
	case 2585ULL: goto x86_l_a19;
	case 2590ULL: goto x86_l_a1e;
	case 2595ULL: goto x86_l_a23;
	case 2600ULL: goto x86_l_a28;
	case 2607ULL: goto x86_l_a2f;
	case 2609ULL: goto x86_l_a31;
	case 2614ULL: goto x86_l_a36;
	case 2619ULL: goto x86_l_a3b;
	case 2624ULL: goto x86_l_a40;
	case 2629ULL: goto x86_l_a45;
	case 2634ULL: goto x86_l_a4a;
	case 2636ULL: goto x86_l_a4c;
	case 2638ULL: goto x86_l_a4e;
	case 2644ULL: goto x86_l_a54;
	case 2651ULL: goto x86_l_a5b;
	case 2657ULL: goto x86_l_a61;
	case 2662ULL: goto x86_l_a66;
	case 2667ULL: goto x86_l_a6b;
	case 2672ULL: goto x86_l_a70;
	case 2679ULL: goto x86_l_a77;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2691ULL: goto x86_l_a83;
	case 2696ULL: goto x86_l_a88;
	case 2701ULL: goto x86_l_a8d;
	case 2706ULL: goto x86_l_a92;
	case 2708ULL: goto x86_l_a94;
	case 2710ULL: goto x86_l_a96;
	case 2716ULL: goto x86_l_a9c;
	case 2723ULL: goto x86_l_aa3;
	case 2729ULL: goto x86_l_aa9;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2744ULL: goto x86_l_ab8;
	case 2751ULL: goto x86_l_abf;
	case 2753ULL: goto x86_l_ac1;
	case 2758ULL: goto x86_l_ac6;
	case 2763ULL: goto x86_l_acb;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2778ULL: goto x86_l_ada;
	case 2780ULL: goto x86_l_adc;
	case 2782ULL: goto x86_l_ade;
	case 2788ULL: goto x86_l_ae4;
	case 2795ULL: goto x86_l_aeb;
	case 2801ULL: goto x86_l_af1;
	case 2806ULL: goto x86_l_af6;
	case 2811ULL: goto x86_l_afb;
	case 2816ULL: goto x86_l_b00;
	case 2823ULL: goto x86_l_b07;
	case 2825ULL: goto x86_l_b09;
	case 2830ULL: goto x86_l_b0e;
	case 2835ULL: goto x86_l_b13;
	case 2840ULL: goto x86_l_b18;
	case 2845ULL: goto x86_l_b1d;
	case 2850ULL: goto x86_l_b22;
	case 2852ULL: goto x86_l_b24;
	case 2854ULL: goto x86_l_b26;
	case 2860ULL: goto x86_l_b2c;
	case 2867ULL: goto x86_l_b33;
	case 2873ULL: goto x86_l_b39;
	case 2878ULL: goto x86_l_b3e;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2895ULL: goto x86_l_b4f;
	case 2897ULL: goto x86_l_b51;
	case 2902ULL: goto x86_l_b56;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2924ULL: goto x86_l_b6c;
	case 2926ULL: goto x86_l_b6e;
	case 2932ULL: goto x86_l_b74;
	case 2939ULL: goto x86_l_b7b;
	case 2945ULL: goto x86_l_b81;
	case 2950ULL: goto x86_l_b86;
	case 2955ULL: goto x86_l_b8b;
	case 2960ULL: goto x86_l_b90;
	case 2967ULL: goto x86_l_b97;
	case 2969ULL: goto x86_l_b99;
	case 2974ULL: goto x86_l_b9e;
	case 2979ULL: goto x86_l_ba3;
	case 2984ULL: goto x86_l_ba8;
	case 2989ULL: goto x86_l_bad;
	case 2994ULL: goto x86_l_bb2;
	case 2996ULL: goto x86_l_bb4;
	case 2998ULL: goto x86_l_bb6;
	case 3004ULL: goto x86_l_bbc;
	case 3011ULL: goto x86_l_bc3;
	case 3017ULL: goto x86_l_bc9;
	case 3022ULL: goto x86_l_bce;
	case 3027ULL: goto x86_l_bd3;
	case 3032ULL: goto x86_l_bd8;
	case 3039ULL: goto x86_l_bdf;
	case 3041ULL: goto x86_l_be1;
	case 3046ULL: goto x86_l_be6;
	case 3051ULL: goto x86_l_beb;
	case 3056ULL: goto x86_l_bf0;
	case 3061ULL: goto x86_l_bf5;
	case 3066ULL: goto x86_l_bfa;
	case 3068ULL: goto x86_l_bfc;
	case 3070ULL: goto x86_l_bfe;
	case 3076ULL: goto x86_l_c04;
	case 3083ULL: goto x86_l_c0b;
	case 3089ULL: goto x86_l_c11;
	case 3094ULL: goto x86_l_c16;
	case 3099ULL: goto x86_l_c1b;
	case 3104ULL: goto x86_l_c20;
	case 3111ULL: goto x86_l_c27;
	case 3113ULL: goto x86_l_c29;
	case 3118ULL: goto x86_l_c2e;
	case 3123ULL: goto x86_l_c33;
	case 3128ULL: goto x86_l_c38;
	case 3133ULL: goto x86_l_c3d;
	case 3138ULL: goto x86_l_c42;
	case 3140ULL: goto x86_l_c44;
	case 3142ULL: goto x86_l_c46;
	case 3148ULL: goto x86_l_c4c;
	case 3155ULL: goto x86_l_c53;
	case 3161ULL: goto x86_l_c59;
	case 3166ULL: goto x86_l_c5e;
	case 3171ULL: goto x86_l_c63;
	case 3176ULL: goto x86_l_c68;
	case 3183ULL: goto x86_l_c6f;
	case 3189ULL: goto x86_l_c75;
	case 3194ULL: goto x86_l_c7a;
	case 3199ULL: goto x86_l_c7f;
	case 3204ULL: goto x86_l_c84;
	case 3209ULL: goto x86_l_c89;
	case 3212ULL: goto x86_l_c8c;
	case 3214ULL: goto x86_l_c8e;
	case 3219ULL: goto x86_l_c93;
	case 3224ULL: goto x86_l_c98;
	case 3229ULL: goto x86_l_c9d;
	case 3234ULL: goto x86_l_ca2;
	case 3239ULL: goto x86_l_ca7;
	case 3241ULL: goto x86_l_ca9;
	case 3243ULL: goto x86_l_cab;
	case 3249ULL: goto x86_l_cb1;
	case 3256ULL: goto x86_l_cb8;
	case 3262ULL: goto x86_l_cbe;
	case 3267ULL: goto x86_l_cc3;
	case 3272ULL: goto x86_l_cc8;
	case 3277ULL: goto x86_l_ccd;
	case 3284ULL: goto x86_l_cd4;
	case 3286ULL: goto x86_l_cd6;
	case 3291ULL: goto x86_l_cdb;
	case 3296ULL: goto x86_l_ce0;
	case 3301ULL: goto x86_l_ce5;
	case 3306ULL: goto x86_l_cea;
	case 3311ULL: goto x86_l_cef;
	case 3313ULL: goto x86_l_cf1;
	case 3315ULL: goto x86_l_cf3;
	case 3321ULL: goto x86_l_cf9;
	case 3328ULL: goto x86_l_d00;
	case 3334ULL: goto x86_l_d06;
	case 3339ULL: goto x86_l_d0b;
	case 3344ULL: goto x86_l_d10;
	case 3349ULL: goto x86_l_d15;
	case 3356ULL: goto x86_l_d1c;
	case 3358ULL: goto x86_l_d1e;
	case 3363ULL: goto x86_l_d23;
	case 3368ULL: goto x86_l_d28;
	case 3373ULL: goto x86_l_d2d;
	case 3378ULL: goto x86_l_d32;
	case 3383ULL: goto x86_l_d37;
	case 3385ULL: goto x86_l_d39;
	case 3387ULL: goto x86_l_d3b;
	case 3393ULL: goto x86_l_d41;
	case 3400ULL: goto x86_l_d48;
	case 3406ULL: goto x86_l_d4e;
	case 3411ULL: goto x86_l_d53;
	case 3416ULL: goto x86_l_d58;
	case 3421ULL: goto x86_l_d5d;
	case 3428ULL: goto x86_l_d64;
	case 3430ULL: goto x86_l_d66;
	case 3435ULL: goto x86_l_d6b;
	case 3440ULL: goto x86_l_d70;
	case 3445ULL: goto x86_l_d75;
	case 3450ULL: goto x86_l_d7a;
	case 3455ULL: goto x86_l_d7f;
	case 3457ULL: goto x86_l_d81;
	case 3459ULL: goto x86_l_d83;
	case 3465ULL: goto x86_l_d89;
	case 3472ULL: goto x86_l_d90;
	case 3478ULL: goto x86_l_d96;
	case 3483ULL: goto x86_l_d9b;
	case 3488ULL: goto x86_l_da0;
	case 3493ULL: goto x86_l_da5;
	case 3500ULL: goto x86_l_dac;
	case 3502ULL: goto x86_l_dae;
	case 3507ULL: goto x86_l_db3;
	case 3512ULL: goto x86_l_db8;
	case 3517ULL: goto x86_l_dbd;
	case 3522ULL: goto x86_l_dc2;
	case 3527ULL: goto x86_l_dc7;
	case 3529ULL: goto x86_l_dc9;
	case 3531ULL: goto x86_l_dcb;
	case 3537ULL: goto x86_l_dd1;
	case 3544ULL: goto x86_l_dd8;
	case 3550ULL: goto x86_l_dde;
	case 3555ULL: goto x86_l_de3;
	case 3560ULL: goto x86_l_de8;
	case 3565ULL: goto x86_l_ded;
	case 3572ULL: goto x86_l_df4;
	case 3574ULL: goto x86_l_df6;
	case 3579ULL: goto x86_l_dfb;
	case 3584ULL: goto x86_l_e00;
	default: return 0xffffffffffffffffULL;
	}
x86_l_702:
	/* 0x702: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_709:
	/* 0x709: je     729 <generic_sleepable_preload+0x729> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_729;
	}
x86_l_70b:
	/* 0x70b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_710:
	/* 0x710: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_715:
	/* 0x715: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_71a:
	/* 0x71a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_71f:
	/* 0x71f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_721:
	/* 0x721: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_723:
	/* 0x723: js     f66 <generic_sleepable_preload+0xf66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3942ULL;
	}
x86_l_729:
	/* 0x729: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_730:
	/* 0x730: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_736:
	/* 0x736: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_73b:
	/* 0x73b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_740:
	/* 0x740: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_745:
	/* 0x745: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_74c:
	/* 0x74c: je     76c <generic_sleepable_preload+0x76c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_76c;
	}
x86_l_74e:
	/* 0x74e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_753:
	/* 0x753: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_758:
	/* 0x758: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_75d:
	/* 0x75d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_762:
	/* 0x762: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_764:
	/* 0x764: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_766:
	/* 0x766: js     f79 <generic_sleepable_preload+0xf79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3961ULL;
	}
x86_l_76c:
	/* 0x76c: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_773:
	/* 0x773: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_779:
	/* 0x779: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_77e:
	/* 0x77e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_783:
	/* 0x783: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_788:
	/* 0x788: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_78f:
	/* 0x78f: je     7af <generic_sleepable_preload+0x7af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7af;
	}
x86_l_791:
	/* 0x791: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_796:
	/* 0x796: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_79b:
	/* 0x79b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7a0:
	/* 0x7a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7a5:
	/* 0x7a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a7:
	/* 0x7a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7a9:
	/* 0x7a9: js     f8c <generic_sleepable_preload+0xf8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3980ULL;
	}
x86_l_7af:
	/* 0x7af: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_7b6:
	/* 0x7b6: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_7bc:
	/* 0x7bc: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_7c1:
	/* 0x7c1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_7c6:
	/* 0x7c6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7cb:
	/* 0x7cb: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_7d2:
	/* 0x7d2: je     7f2 <generic_sleepable_preload+0x7f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7f2;
	}
x86_l_7d4:
	/* 0x7d4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7d9:
	/* 0x7d9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7de:
	/* 0x7de: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7e3:
	/* 0x7e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7e8:
	/* 0x7e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ea:
	/* 0x7ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7ec:
	/* 0x7ec: js     f9f <generic_sleepable_preload+0xf9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3999ULL;
	}
x86_l_7f2:
	/* 0x7f2: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_7f9:
	/* 0x7f9: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_7ff:
	/* 0x7ff: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_804:
	/* 0x804: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_809:
	/* 0x809: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_80e:
	/* 0x80e: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_815:
	/* 0x815: je     835 <generic_sleepable_preload+0x835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_835;
	}
x86_l_817:
	/* 0x817: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_81c:
	/* 0x81c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_821:
	/* 0x821: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_826:
	/* 0x826: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_82b:
	/* 0x82b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82d:
	/* 0x82d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_82f:
	/* 0x82f: js     fb2 <generic_sleepable_preload+0xfb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4018ULL;
	}
x86_l_835:
	/* 0x835: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_83c:
	/* 0x83c: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_842:
	/* 0x842: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_847:
	/* 0x847: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_84c:
	/* 0x84c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_851:
	/* 0x851: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_858:
	/* 0x858: je     878 <generic_sleepable_preload+0x878> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_878;
	}
x86_l_85a:
	/* 0x85a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_85f:
	/* 0x85f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_864:
	/* 0x864: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_869:
	/* 0x869: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_86e:
	/* 0x86e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_870:
	/* 0x870: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_872:
	/* 0x872: js     115d <generic_sleepable_preload+0x115d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4445ULL;
	}
x86_l_878:
	/* 0x878: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_87f:
	/* 0x87f: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_885:
	/* 0x885: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_88a:
	/* 0x88a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_88f:
	/* 0x88f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_894:
	/* 0x894: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_89b:
	/* 0x89b: je     8bb <generic_sleepable_preload+0x8bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8bb;
	}
x86_l_89d:
	/* 0x89d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8a2:
	/* 0x8a2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a7:
	/* 0x8a7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8ac:
	/* 0x8ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8b1:
	/* 0x8b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b3:
	/* 0x8b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8b5:
	/* 0x8b5: js     118c <generic_sleepable_preload+0x118c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4492ULL;
	}
x86_l_8bb:
	/* 0x8bb: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_8c2:
	/* 0x8c2: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_8c8:
	/* 0x8c8: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_8cd:
	/* 0x8cd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_8d2:
	/* 0x8d2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8d7:
	/* 0x8d7: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_8de:
	/* 0x8de: je     fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4032ULL;
	}
x86_l_8e4:
	/* 0x8e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8e9:
	/* 0x8e9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8ee:
	/* 0x8ee: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8f3:
	/* 0x8f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8f8:
	/* 0x8f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8fa:
	/* 0x8fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8fc:
	/* 0x8fc: jns    fc0 <generic_sleepable_preload+0xfc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 4032ULL;
	}
x86_l_902:
	/* 0x902: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_908:
	/* 0x908: jmp    fb8 <generic_sleepable_preload+0xfb8> */
	return 4024ULL;
x86_l_90d:
	/* 0x90d: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_913:
	/* 0x913: jmp    fb8 <generic_sleepable_preload+0xfb8> */
	return 4024ULL;
x86_l_918:
	/* 0x918: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_920:
	/* 0x920: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_923:
	/* 0x923: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98e;
	}
x86_l_925:
	/* 0x925: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_92a:
	/* 0x92a: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_92f:
	/* 0x92f: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_932:
	/* 0x932: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98e;
	}
x86_l_934:
	/* 0x934: jmp    9a1 <generic_sleepable_preload+0x9a1> */
	goto x86_l_9a1;
x86_l_936:
	/* 0x936: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_93e:
	/* 0x93e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_941:
	/* 0x941: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98e;
	}
x86_l_943:
	/* 0x943: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_948:
	/* 0x948: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_94d:
	/* 0x94d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_950:
	/* 0x950: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98e;
	}
x86_l_952:
	/* 0x952: jmp    9a1 <generic_sleepable_preload+0x9a1> */
	goto x86_l_9a1;
x86_l_954:
	/* 0x954: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_95c:
	/* 0x95c: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_95f:
	/* 0x95f: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98e;
	}
x86_l_961:
	/* 0x961: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_966:
	/* 0x966: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_96b:
	/* 0x96b: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_96e:
	/* 0x96e: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98e;
	}
x86_l_970:
	/* 0x970: jmp    9a1 <generic_sleepable_preload+0x9a1> */
	goto x86_l_9a1;
x86_l_972:
	/* 0x972: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_97a:
	/* 0x97a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_97d:
	/* 0x97d: je     98e <generic_sleepable_preload+0x98e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98e;
	}
x86_l_97f:
	/* 0x97f: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_984:
	/* 0x984: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_989:
	/* 0x989: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_98c:
	/* 0x98c: jne    9a1 <generic_sleepable_preload+0x9a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9a1;
	}
x86_l_98e:
	/* 0x98e: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_991:
	/* 0x991: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_993:
	/* 0x993: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_995:
	/* 0x995: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_99a:
	/* 0x99a: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_99c:
	/* 0x99c: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_9a1:
	/* 0x9a1: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9a6:
	/* 0x9a6: mov    ebp,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9a9:
	/* 0x9a9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ac:
	/* 0x9ac: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_9ae:
	/* 0x9ae: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_9b2:
	/* 0x9b2: cmp    WORD PTR [r13+r15*1-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743764471906304ULL);
x86_l_9b9:
	/* 0x9b9: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_9bf:
	/* 0x9bf: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_9c6:
	/* 0x9c6: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_9c9:
	/* 0x9c9: mov    eax,DWORD PTR [r13+r15*1-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551538ULL);
x86_l_9ce:
	/* 0x9ce: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9d1:
	/* 0x9d1: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9d6:
	/* 0x9d6: movzx  eax,WORD PTR [r13+r15*1-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R15, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_9dc:
	/* 0x9dc: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_9de:
	/* 0x9de: je     c89 <generic_sleepable_preload+0xc89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c89;
	}
x86_l_9e4:
	/* 0x9e4: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_9e7:
	/* 0x9e7: je     a0c <generic_sleepable_preload+0xa0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a0c;
	}
x86_l_9e9:
	/* 0x9e9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9ee:
	/* 0x9ee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9f3:
	/* 0x9f3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9f8:
	/* 0x9f8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9fd:
	/* 0x9fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a02:
	/* 0xa02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a04:
	/* 0xa04: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a06:
	/* 0xa06: js     f48 <generic_sleepable_preload+0xf48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3912ULL;
	}
x86_l_a0c:
	/* 0xa0c: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_a13:
	/* 0xa13: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_a19:
	/* 0xa19: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_a1e:
	/* 0xa1e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a23:
	/* 0xa23: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a28:
	/* 0xa28: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_a2f:
	/* 0xa2f: je     a54 <generic_sleepable_preload+0xa54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a54;
	}
x86_l_a31:
	/* 0xa31: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a36:
	/* 0xa36: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a3b:
	/* 0xa3b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a40:
	/* 0xa40: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a45:
	/* 0xa45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a4a:
	/* 0xa4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4c:
	/* 0xa4c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a4e:
	/* 0xa4e: js     f5b <generic_sleepable_preload+0xf5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3931ULL;
	}
x86_l_a54:
	/* 0xa54: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_a5b:
	/* 0xa5b: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_a61:
	/* 0xa61: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_a66:
	/* 0xa66: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a6b:
	/* 0xa6b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a70:
	/* 0xa70: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_a77:
	/* 0xa77: je     a9c <generic_sleepable_preload+0xa9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a9c;
	}
x86_l_a79:
	/* 0xa79: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a7e:
	/* 0xa7e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a83:
	/* 0xa83: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a88:
	/* 0xa88: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a8d:
	/* 0xa8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a92:
	/* 0xa92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a94:
	/* 0xa94: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a96:
	/* 0xa96: js     f6e <generic_sleepable_preload+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3950ULL;
	}
x86_l_a9c:
	/* 0xa9c: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_aa3:
	/* 0xaa3: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_aa9:
	/* 0xaa9: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_aae:
	/* 0xaae: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ab3:
	/* 0xab3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ab8:
	/* 0xab8: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_abf:
	/* 0xabf: je     ae4 <generic_sleepable_preload+0xae4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ae4;
	}
x86_l_ac1:
	/* 0xac1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ac6:
	/* 0xac6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_acb:
	/* 0xacb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ad0:
	/* 0xad0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ad5:
	/* 0xad5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ada:
	/* 0xada: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_adc:
	/* 0xadc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ade:
	/* 0xade: js     f81 <generic_sleepable_preload+0xf81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3969ULL;
	}
x86_l_ae4:
	/* 0xae4: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_aeb:
	/* 0xaeb: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_af1:
	/* 0xaf1: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_af6:
	/* 0xaf6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_afb:
	/* 0xafb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b00:
	/* 0xb00: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_b07:
	/* 0xb07: je     b2c <generic_sleepable_preload+0xb2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b2c;
	}
x86_l_b09:
	/* 0xb09: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b0e:
	/* 0xb0e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b13:
	/* 0xb13: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b18:
	/* 0xb18: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b1d:
	/* 0xb1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b22:
	/* 0xb22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b24:
	/* 0xb24: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b26:
	/* 0xb26: js     f94 <generic_sleepable_preload+0xf94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3988ULL;
	}
x86_l_b2c:
	/* 0xb2c: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_b33:
	/* 0xb33: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_b39:
	/* 0xb39: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_b3e:
	/* 0xb3e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b43:
	/* 0xb43: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b48:
	/* 0xb48: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_b4f:
	/* 0xb4f: je     b74 <generic_sleepable_preload+0xb74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b74;
	}
x86_l_b51:
	/* 0xb51: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b56:
	/* 0xb56: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b5b:
	/* 0xb5b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b60:
	/* 0xb60: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b65:
	/* 0xb65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b6a:
	/* 0xb6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b6c:
	/* 0xb6c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b6e:
	/* 0xb6e: js     fa7 <generic_sleepable_preload+0xfa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4007ULL;
	}
x86_l_b74:
	/* 0xb74: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_b7b:
	/* 0xb7b: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_b81:
	/* 0xb81: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_b86:
	/* 0xb86: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b8b:
	/* 0xb8b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b90:
	/* 0xb90: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_b97:
	/* 0xb97: je     bbc <generic_sleepable_preload+0xbbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bbc;
	}
x86_l_b99:
	/* 0xb99: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b9e:
	/* 0xb9e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ba3:
	/* 0xba3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ba8:
	/* 0xba8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bad:
	/* 0xbad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bb2:
	/* 0xbb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb4:
	/* 0xbb4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bb6:
	/* 0xbb6: js     109b <generic_sleepable_preload+0x109b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4251ULL;
	}
x86_l_bbc:
	/* 0xbbc: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_bc3:
	/* 0xbc3: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_bc9:
	/* 0xbc9: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_bce:
	/* 0xbce: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_bd3:
	/* 0xbd3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bd8:
	/* 0xbd8: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_bdf:
	/* 0xbdf: je     c04 <generic_sleepable_preload+0xc04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c04;
	}
x86_l_be1:
	/* 0xbe1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_be6:
	/* 0xbe6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_beb:
	/* 0xbeb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bf0:
	/* 0xbf0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bf5:
	/* 0xbf5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bfa:
	/* 0xbfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfc:
	/* 0xbfc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bfe:
	/* 0xbfe: js     1170 <generic_sleepable_preload+0x1170> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4464ULL;
	}
x86_l_c04:
	/* 0xc04: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_c0b:
	/* 0xc0b: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_c11:
	/* 0xc11: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_c16:
	/* 0xc16: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c1b:
	/* 0xc1b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c20:
	/* 0xc20: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_c27:
	/* 0xc27: je     c4c <generic_sleepable_preload+0xc4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c4c;
	}
x86_l_c29:
	/* 0xc29: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c2e:
	/* 0xc2e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c33:
	/* 0xc33: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c38:
	/* 0xc38: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c3d:
	/* 0xc3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c42:
	/* 0xc42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c44:
	/* 0xc44: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c46:
	/* 0xc46: js     1197 <generic_sleepable_preload+0x1197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4503ULL;
	}
x86_l_c4c:
	/* 0xc4c: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_c53:
	/* 0xc53: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_c59:
	/* 0xc59: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_c5e:
	/* 0xc5e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c63:
	/* 0xc63: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c68:
	/* 0xc68: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_c6f:
	/* 0xc6f: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_c75:
	/* 0xc75: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c7a:
	/* 0xc7a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c7f:
	/* 0xc7f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c84:
	/* 0xc84: jmp    f29 <generic_sleepable_preload+0xf29> */
	return 3881ULL;
x86_l_c89:
	/* 0xc89: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_c8c:
	/* 0xc8c: je     cb1 <generic_sleepable_preload+0xcb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cb1;
	}
x86_l_c8e:
	/* 0xc8e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c93:
	/* 0xc93: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c98:
	/* 0xc98: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c9d:
	/* 0xc9d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ca2:
	/* 0xca2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ca7:
	/* 0xca7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca9:
	/* 0xca9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cab:
	/* 0xcab: js     f48 <generic_sleepable_preload+0xf48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3912ULL;
	}
x86_l_cb1:
	/* 0xcb1: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_cb8:
	/* 0xcb8: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_cbe:
	/* 0xcbe: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_cc3:
	/* 0xcc3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_cc8:
	/* 0xcc8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ccd:
	/* 0xccd: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_cd4:
	/* 0xcd4: je     cf9 <generic_sleepable_preload+0xcf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cf9;
	}
x86_l_cd6:
	/* 0xcd6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_cdb:
	/* 0xcdb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ce0:
	/* 0xce0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ce5:
	/* 0xce5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cea:
	/* 0xcea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cef:
	/* 0xcef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf1:
	/* 0xcf1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cf3:
	/* 0xcf3: js     f5b <generic_sleepable_preload+0xf5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3931ULL;
	}
x86_l_cf9:
	/* 0xcf9: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_d00:
	/* 0xd00: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_d06:
	/* 0xd06: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_d0b:
	/* 0xd0b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d10:
	/* 0xd10: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d15:
	/* 0xd15: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_d1c:
	/* 0xd1c: je     d41 <generic_sleepable_preload+0xd41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d41;
	}
x86_l_d1e:
	/* 0xd1e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d23:
	/* 0xd23: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d28:
	/* 0xd28: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d2d:
	/* 0xd2d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d32:
	/* 0xd32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d37:
	/* 0xd37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d39:
	/* 0xd39: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d3b:
	/* 0xd3b: js     f6e <generic_sleepable_preload+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3950ULL;
	}
x86_l_d41:
	/* 0xd41: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_d48:
	/* 0xd48: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_d4e:
	/* 0xd4e: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_d53:
	/* 0xd53: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d58:
	/* 0xd58: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d5d:
	/* 0xd5d: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_d64:
	/* 0xd64: je     d89 <generic_sleepable_preload+0xd89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d89;
	}
x86_l_d66:
	/* 0xd66: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d6b:
	/* 0xd6b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d70:
	/* 0xd70: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d75:
	/* 0xd75: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d7a:
	/* 0xd7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d7f:
	/* 0xd7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d81:
	/* 0xd81: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d83:
	/* 0xd83: js     f81 <generic_sleepable_preload+0xf81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3969ULL;
	}
x86_l_d89:
	/* 0xd89: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_d90:
	/* 0xd90: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_d96:
	/* 0xd96: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_d9b:
	/* 0xd9b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_da0:
	/* 0xda0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da5:
	/* 0xda5: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_dac:
	/* 0xdac: je     dd1 <generic_sleepable_preload+0xdd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dd1;
	}
x86_l_dae:
	/* 0xdae: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_db3:
	/* 0xdb3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_db8:
	/* 0xdb8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dbd:
	/* 0xdbd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc2:
	/* 0xdc2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dc7:
	/* 0xdc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc9:
	/* 0xdc9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dcb:
	/* 0xdcb: js     f94 <generic_sleepable_preload+0xf94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3988ULL;
	}
x86_l_dd1:
	/* 0xdd1: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_dd8:
	/* 0xdd8: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4265ULL;
	}
x86_l_dde:
	/* 0xdde: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_de3:
	/* 0xde3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_de8:
	/* 0xde8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ded:
	/* 0xded: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_df4:
	/* 0xdf4: je     e19 <generic_sleepable_preload+0xe19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3609ULL;
	}
x86_l_df6:
	/* 0xdf6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_dfb:
	/* 0xdfb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e00:
	/* 0xe00: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 3589ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3589ULL: goto x86_l_e05;
	case 3594ULL: goto x86_l_e0a;
	case 3599ULL: goto x86_l_e0f;
	case 3601ULL: goto x86_l_e11;
	case 3603ULL: goto x86_l_e13;
	case 3609ULL: goto x86_l_e19;
	case 3616ULL: goto x86_l_e20;
	case 3622ULL: goto x86_l_e26;
	case 3627ULL: goto x86_l_e2b;
	case 3632ULL: goto x86_l_e30;
	case 3637ULL: goto x86_l_e35;
	case 3644ULL: goto x86_l_e3c;
	case 3646ULL: goto x86_l_e3e;
	case 3651ULL: goto x86_l_e43;
	case 3656ULL: goto x86_l_e48;
	case 3661ULL: goto x86_l_e4d;
	case 3666ULL: goto x86_l_e52;
	case 3671ULL: goto x86_l_e57;
	case 3673ULL: goto x86_l_e59;
	case 3675ULL: goto x86_l_e5b;
	case 3681ULL: goto x86_l_e61;
	case 3688ULL: goto x86_l_e68;
	case 3694ULL: goto x86_l_e6e;
	case 3699ULL: goto x86_l_e73;
	case 3704ULL: goto x86_l_e78;
	case 3709ULL: goto x86_l_e7d;
	case 3716ULL: goto x86_l_e84;
	case 3718ULL: goto x86_l_e86;
	case 3723ULL: goto x86_l_e8b;
	case 3728ULL: goto x86_l_e90;
	case 3733ULL: goto x86_l_e95;
	case 3738ULL: goto x86_l_e9a;
	case 3743ULL: goto x86_l_e9f;
	case 3745ULL: goto x86_l_ea1;
	case 3747ULL: goto x86_l_ea3;
	case 3753ULL: goto x86_l_ea9;
	case 3760ULL: goto x86_l_eb0;
	case 3766ULL: goto x86_l_eb6;
	case 3771ULL: goto x86_l_ebb;
	case 3776ULL: goto x86_l_ec0;
	case 3781ULL: goto x86_l_ec5;
	case 3788ULL: goto x86_l_ecc;
	case 3790ULL: goto x86_l_ece;
	case 3795ULL: goto x86_l_ed3;
	case 3800ULL: goto x86_l_ed8;
	case 3805ULL: goto x86_l_edd;
	case 3810ULL: goto x86_l_ee2;
	case 3815ULL: goto x86_l_ee7;
	case 3817ULL: goto x86_l_ee9;
	case 3819ULL: goto x86_l_eeb;
	case 3825ULL: goto x86_l_ef1;
	case 3832ULL: goto x86_l_ef8;
	case 3838ULL: goto x86_l_efe;
	case 3843ULL: goto x86_l_f03;
	case 3848ULL: goto x86_l_f08;
	case 3853ULL: goto x86_l_f0d;
	case 3860ULL: goto x86_l_f14;
	case 3866ULL: goto x86_l_f1a;
	case 3871ULL: goto x86_l_f1f;
	case 3876ULL: goto x86_l_f24;
	case 3881ULL: goto x86_l_f29;
	case 3886ULL: goto x86_l_f2e;
	case 3891ULL: goto x86_l_f33;
	case 3893ULL: goto x86_l_f35;
	case 3895ULL: goto x86_l_f37;
	case 3901ULL: goto x86_l_f3d;
	case 3907ULL: goto x86_l_f43;
	case 3912ULL: goto x86_l_f48;
	case 3918ULL: goto x86_l_f4e;
	case 3923ULL: goto x86_l_f53;
	case 3929ULL: goto x86_l_f59;
	case 3931ULL: goto x86_l_f5b;
	case 3937ULL: goto x86_l_f61;
	case 3942ULL: goto x86_l_f66;
	case 3948ULL: goto x86_l_f6c;
	case 3950ULL: goto x86_l_f6e;
	case 3956ULL: goto x86_l_f74;
	case 3961ULL: goto x86_l_f79;
	case 3967ULL: goto x86_l_f7f;
	case 3969ULL: goto x86_l_f81;
	case 3975ULL: goto x86_l_f87;
	case 3980ULL: goto x86_l_f8c;
	case 3986ULL: goto x86_l_f92;
	case 3988ULL: goto x86_l_f94;
	case 3994ULL: goto x86_l_f9a;
	case 3999ULL: goto x86_l_f9f;
	case 4005ULL: goto x86_l_fa5;
	case 4007ULL: goto x86_l_fa7;
	case 4013ULL: goto x86_l_fad;
	case 4018ULL: goto x86_l_fb2;
	case 4024ULL: goto x86_l_fb8;
	case 4032ULL: goto x86_l_fc0;
	case 4035ULL: goto x86_l_fc3;
	case 4040ULL: goto x86_l_fc8;
	case 4045ULL: goto x86_l_fcd;
	case 4050ULL: goto x86_l_fd2;
	case 4053ULL: goto x86_l_fd5;
	case 4055ULL: goto x86_l_fd7;
	case 4059ULL: goto x86_l_fdb;
	case 4065ULL: goto x86_l_fe1;
	case 4070ULL: goto x86_l_fe6;
	case 4078ULL: goto x86_l_fee;
	case 4083ULL: goto x86_l_ff3;
	case 4085ULL: goto x86_l_ff5;
	case 4090ULL: goto x86_l_ffa;
	case 4098ULL: goto x86_l_1002;
	case 4103ULL: goto x86_l_1007;
	case 4110ULL: goto x86_l_100e;
	case 4115ULL: goto x86_l_1013;
	case 4117ULL: goto x86_l_1015;
	case 4120ULL: goto x86_l_1018;
	case 4126ULL: goto x86_l_101e;
	case 4129ULL: goto x86_l_1021;
	case 4134ULL: goto x86_l_1026;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4144ULL: goto x86_l_1030;
	case 4151ULL: goto x86_l_1037;
	case 4154ULL: goto x86_l_103a;
	case 4157ULL: goto x86_l_103d;
	case 4159ULL: goto x86_l_103f;
	case 4161ULL: goto x86_l_1041;
	case 4166ULL: goto x86_l_1046;
	case 4169ULL: goto x86_l_1049;
	case 4172ULL: goto x86_l_104c;
	case 4175ULL: goto x86_l_104f;
	case 4177ULL: goto x86_l_1051;
	case 4180ULL: goto x86_l_1054;
	case 4186ULL: goto x86_l_105a;
	case 4191ULL: goto x86_l_105f;
	case 4197ULL: goto x86_l_1065;
	case 4201ULL: goto x86_l_1069;
	case 4206ULL: goto x86_l_106e;
	case 4214ULL: goto x86_l_1076;
	case 4216ULL: goto x86_l_1078;
	case 4219ULL: goto x86_l_107b;
	case 4224ULL: goto x86_l_1080;
	case 4226ULL: goto x86_l_1082;
	case 4229ULL: goto x86_l_1085;
	case 4232ULL: goto x86_l_1088;
	case 4234ULL: goto x86_l_108a;
	case 4240ULL: goto x86_l_1090;
	case 4246ULL: goto x86_l_1096;
	case 4251ULL: goto x86_l_109b;
	case 4257ULL: goto x86_l_10a1;
	case 4265ULL: goto x86_l_10a9;
	case 4268ULL: goto x86_l_10ac;
	case 4274ULL: goto x86_l_10b2;
	case 4279ULL: goto x86_l_10b7;
	case 4287ULL: goto x86_l_10bf;
	case 4292ULL: goto x86_l_10c4;
	case 4294ULL: goto x86_l_10c6;
	case 4299ULL: goto x86_l_10cb;
	case 4307ULL: goto x86_l_10d3;
	case 4312ULL: goto x86_l_10d8;
	case 4319ULL: goto x86_l_10df;
	case 4324ULL: goto x86_l_10e4;
	case 4326ULL: goto x86_l_10e6;
	case 4329ULL: goto x86_l_10e9;
	case 4335ULL: goto x86_l_10ef;
	case 4338ULL: goto x86_l_10f2;
	case 4343ULL: goto x86_l_10f7;
	case 4345ULL: goto x86_l_10f9;
	case 4350ULL: goto x86_l_10fe;
	case 4353ULL: goto x86_l_1101;
	case 4360ULL: goto x86_l_1108;
	case 4363ULL: goto x86_l_110b;
	case 4366ULL: goto x86_l_110e;
	case 4368ULL: goto x86_l_1110;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4378ULL: goto x86_l_111a;
	case 4381ULL: goto x86_l_111d;
	case 4383ULL: goto x86_l_111f;
	case 4386ULL: goto x86_l_1122;
	case 4392ULL: goto x86_l_1128;
	case 4395ULL: goto x86_l_112b;
	case 4400ULL: goto x86_l_1130;
	case 4402ULL: goto x86_l_1132;
	case 4406ULL: goto x86_l_1136;
	case 4411ULL: goto x86_l_113b;
	case 4419ULL: goto x86_l_1143;
	case 4421ULL: goto x86_l_1145;
	case 4426ULL: goto x86_l_114a;
	case 4428ULL: goto x86_l_114c;
	case 4430ULL: goto x86_l_114e;
	case 4436ULL: goto x86_l_1154;
	case 4440ULL: goto x86_l_1158;
	case 4445ULL: goto x86_l_115d;
	case 4453ULL: goto x86_l_1165;
	case 4459ULL: goto x86_l_116b;
	case 4464ULL: goto x86_l_1170;
	case 4472ULL: goto x86_l_1178;
	case 4478ULL: goto x86_l_117e;
	case 4481ULL: goto x86_l_1181;
	case 4487ULL: goto x86_l_1187;
	case 4492ULL: goto x86_l_118c;
	case 4498ULL: goto x86_l_1192;
	case 4503ULL: goto x86_l_1197;
	case 4509ULL: goto x86_l_119d;
	case 4514ULL: goto x86_l_11a2;
	case 4518ULL: goto x86_l_11a6;
	case 4523ULL: goto x86_l_11ab;
	case 4525ULL: goto x86_l_11ad;
	case 4529ULL: goto x86_l_11b1;
	case 4534ULL: goto x86_l_11b6;
	case 4540ULL: goto x86_l_11bc;
	case 4544ULL: goto x86_l_11c0;
	case 4549ULL: goto x86_l_11c5;
	case 4554ULL: goto x86_l_11ca;
	case 4560ULL: goto x86_l_11d0;
	case 4564ULL: goto x86_l_11d4;
	case 4569ULL: goto x86_l_11d9;
	case 4575ULL: goto x86_l_11df;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4590ULL: goto x86_l_11ee;
	case 4592ULL: goto x86_l_11f0;
	case 4599ULL: goto x86_l_11f7;
	case 4601ULL: goto x86_l_11f9;
	case 4602ULL: goto x86_l_11fa;
	case 4607ULL: goto x86_l_11ff;
	case 4609ULL: goto x86_l_1201;
	case 4615ULL: goto x86_l_1207;
	case 4623ULL: goto x86_l_120f;
	case 4625ULL: goto x86_l_1211;
	case 4628ULL: goto x86_l_1214;
	case 4634ULL: goto x86_l_121a;
	case 4637ULL: goto x86_l_121d;
	case 4643ULL: goto x86_l_1223;
	case 4646ULL: goto x86_l_1226;
	case 4652ULL: goto x86_l_122c;
	case 4659ULL: goto x86_l_1233;
	case 4665ULL: goto x86_l_1239;
	case 4668ULL: goto x86_l_123c;
	case 4673ULL: goto x86_l_1241;
	case 4678ULL: goto x86_l_1246;
	case 4683ULL: goto x86_l_124b;
	case 4688ULL: goto x86_l_1250;
	case 4690ULL: goto x86_l_1252;
	case 4692ULL: goto x86_l_1254;
	case 4698ULL: goto x86_l_125a;
	case 4700ULL: goto x86_l_125c;
	case 4705ULL: goto x86_l_1261;
	case 4707ULL: goto x86_l_1263;
	case 4713ULL: goto x86_l_1269;
	case 4721ULL: goto x86_l_1271;
	case 4723ULL: goto x86_l_1273;
	case 4726ULL: goto x86_l_1276;
	case 4732ULL: goto x86_l_127c;
	case 4735ULL: goto x86_l_127f;
	case 4741ULL: goto x86_l_1285;
	case 4744ULL: goto x86_l_1288;
	case 4750ULL: goto x86_l_128e;
	case 4757ULL: goto x86_l_1295;
	case 4763ULL: goto x86_l_129b;
	case 4766ULL: goto x86_l_129e;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4781ULL: goto x86_l_12ad;
	case 4786ULL: goto x86_l_12b2;
	case 4788ULL: goto x86_l_12b4;
	case 4790ULL: goto x86_l_12b6;
	case 4796ULL: goto x86_l_12bc;
	case 4798ULL: goto x86_l_12be;
	case 4803ULL: goto x86_l_12c3;
	case 4805ULL: goto x86_l_12c5;
	case 4811ULL: goto x86_l_12cb;
	case 4819ULL: goto x86_l_12d3;
	case 4821ULL: goto x86_l_12d5;
	case 4824ULL: goto x86_l_12d8;
	case 4830ULL: goto x86_l_12de;
	case 4833ULL: goto x86_l_12e1;
	case 4838ULL: goto x86_l_12e6;
	case 4844ULL: goto x86_l_12ec;
	case 4847ULL: goto x86_l_12ef;
	case 4853ULL: goto x86_l_12f5;
	case 4860ULL: goto x86_l_12fc;
	case 4866ULL: goto x86_l_1302;
	case 4869ULL: goto x86_l_1305;
	case 4874ULL: goto x86_l_130a;
	case 4879ULL: goto x86_l_130f;
	case 4884ULL: goto x86_l_1314;
	case 4889ULL: goto x86_l_1319;
	case 4891ULL: goto x86_l_131b;
	case 4893ULL: goto x86_l_131d;
	case 4899ULL: goto x86_l_1323;
	case 4901ULL: goto x86_l_1325;
	case 4906ULL: goto x86_l_132a;
	case 4908ULL: goto x86_l_132c;
	case 4914ULL: goto x86_l_1332;
	case 4922ULL: goto x86_l_133a;
	case 4924ULL: goto x86_l_133c;
	case 4927ULL: goto x86_l_133f;
	case 4932ULL: goto x86_l_1344;
	case 4938ULL: goto x86_l_134a;
	case 4941ULL: goto x86_l_134d;
	case 4947ULL: goto x86_l_1353;
	case 4950ULL: goto x86_l_1356;
	case 4956ULL: goto x86_l_135c;
	case 4963ULL: goto x86_l_1363;
	case 4969ULL: goto x86_l_1369;
	case 4972ULL: goto x86_l_136c;
	case 4977ULL: goto x86_l_1371;
	case 4982ULL: goto x86_l_1376;
	case 4987ULL: goto x86_l_137b;
	case 4992ULL: goto x86_l_1380;
	case 4994ULL: goto x86_l_1382;
	case 4996ULL: goto x86_l_1384;
	case 5002ULL: goto x86_l_138a;
	case 5004ULL: goto x86_l_138c;
	case 5009ULL: goto x86_l_1391;
	case 5011ULL: goto x86_l_1393;
	case 5017ULL: goto x86_l_1399;
	case 5025ULL: goto x86_l_13a1;
	case 5027ULL: goto x86_l_13a3;
	case 5030ULL: goto x86_l_13a6;
	case 5036ULL: goto x86_l_13ac;
	case 5039ULL: goto x86_l_13af;
	case 5044ULL: goto x86_l_13b4;
	case 5050ULL: goto x86_l_13ba;
	case 5053ULL: goto x86_l_13bd;
	case 5059ULL: goto x86_l_13c3;
	case 5066ULL: goto x86_l_13ca;
	case 5071ULL: goto x86_l_13cf;
	case 5074ULL: goto x86_l_13d2;
	case 5079ULL: goto x86_l_13d7;
	case 5084ULL: goto x86_l_13dc;
	case 5089ULL: goto x86_l_13e1;
	case 5094ULL: goto x86_l_13e6;
	case 5096ULL: goto x86_l_13e8;
	case 5098ULL: goto x86_l_13ea;
	case 5104ULL: goto x86_l_13f0;
	case 5106ULL: goto x86_l_13f2;
	case 5111ULL: goto x86_l_13f7;
	case 5119ULL: goto x86_l_13ff;
	case 5127ULL: goto x86_l_1407;
	case 5133ULL: goto x86_l_140d;
	case 5135ULL: goto x86_l_140f;
	case 5138ULL: goto x86_l_1412;
	case 5144ULL: goto x86_l_1418;
	case 5147ULL: goto x86_l_141b;
	case 5153ULL: goto x86_l_1421;
	case 5156ULL: goto x86_l_1424;
	case 5162ULL: goto x86_l_142a;
	case 5170ULL: goto x86_l_1432;
	case 5173ULL: goto x86_l_1435;
	case 5179ULL: goto x86_l_143b;
	case 5184ULL: goto x86_l_1440;
	case 5187ULL: goto x86_l_1443;
	case 5193ULL: goto x86_l_1449;
	case 5196ULL: goto x86_l_144c;
	case 5202ULL: goto x86_l_1452;
	case 5207ULL: goto x86_l_1457;
	case 5212ULL: goto x86_l_145c;
	case 5220ULL: goto x86_l_1464;
	case 5228ULL: goto x86_l_146c;
	case 5234ULL: goto x86_l_1472;
	case 5236ULL: goto x86_l_1474;
	case 5239ULL: goto x86_l_1477;
	case 5245ULL: goto x86_l_147d;
	case 5248ULL: goto x86_l_1480;
	case 5254ULL: goto x86_l_1486;
	case 5257ULL: goto x86_l_1489;
	case 5263ULL: goto x86_l_148f;
	case 5271ULL: goto x86_l_1497;
	case 5274ULL: goto x86_l_149a;
	case 5280ULL: goto x86_l_14a0;
	case 5285ULL: goto x86_l_14a5;
	case 5288ULL: goto x86_l_14a8;
	case 5294ULL: goto x86_l_14ae;
	case 5299ULL: goto x86_l_14b3;
	case 5302ULL: goto x86_l_14b6;
	case 5308ULL: goto x86_l_14bc;
	case 5313ULL: goto x86_l_14c1;
	case 5321ULL: goto x86_l_14c9;
	case 5329ULL: goto x86_l_14d1;
	case 5335ULL: goto x86_l_14d7;
	case 5337ULL: goto x86_l_14d9;
	case 5340ULL: goto x86_l_14dc;
	case 5346ULL: goto x86_l_14e2;
	case 5349ULL: goto x86_l_14e5;
	case 5355ULL: goto x86_l_14eb;
	case 5358ULL: goto x86_l_14ee;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e05:
	/* 0xe05: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e0a:
	/* 0xe0a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e0f:
	/* 0xe0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e11:
	/* 0xe11: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e13:
	/* 0xe13: js     fa7 <generic_sleepable_preload+0xfa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_fa7;
	}
x86_l_e19:
	/* 0xe19: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_e20:
	/* 0xe20: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a9;
	}
x86_l_e26:
	/* 0xe26: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_e2b:
	/* 0xe2b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e30:
	/* 0xe30: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e35:
	/* 0xe35: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_e3c:
	/* 0xe3c: je     e61 <generic_sleepable_preload+0xe61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e61;
	}
x86_l_e3e:
	/* 0xe3e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e43:
	/* 0xe43: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e48:
	/* 0xe48: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e4d:
	/* 0xe4d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e52:
	/* 0xe52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e57:
	/* 0xe57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e59:
	/* 0xe59: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e5b:
	/* 0xe5b: js     109b <generic_sleepable_preload+0x109b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_109b;
	}
x86_l_e61:
	/* 0xe61: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_e68:
	/* 0xe68: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a9;
	}
x86_l_e6e:
	/* 0xe6e: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_e73:
	/* 0xe73: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e78:
	/* 0xe78: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e7d:
	/* 0xe7d: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_e84:
	/* 0xe84: je     ea9 <generic_sleepable_preload+0xea9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ea9;
	}
x86_l_e86:
	/* 0xe86: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e8b:
	/* 0xe8b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e90:
	/* 0xe90: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e95:
	/* 0xe95: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e9a:
	/* 0xe9a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e9f:
	/* 0xe9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea1:
	/* 0xea1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ea3:
	/* 0xea3: js     1170 <generic_sleepable_preload+0x1170> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1170;
	}
x86_l_ea9:
	/* 0xea9: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_eb0:
	/* 0xeb0: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a9;
	}
x86_l_eb6:
	/* 0xeb6: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_ebb:
	/* 0xebb: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ec0:
	/* 0xec0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ec5:
	/* 0xec5: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_ecc:
	/* 0xecc: je     ef1 <generic_sleepable_preload+0xef1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ef1;
	}
x86_l_ece:
	/* 0xece: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ed3:
	/* 0xed3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ed8:
	/* 0xed8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_edd:
	/* 0xedd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ee2:
	/* 0xee2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ee7:
	/* 0xee7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee9:
	/* 0xee9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_eeb:
	/* 0xeeb: js     1197 <generic_sleepable_preload+0x1197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1197;
	}
x86_l_ef1:
	/* 0xef1: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_ef8:
	/* 0xef8: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a9;
	}
x86_l_efe:
	/* 0xefe: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_f03:
	/* 0xf03: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f08:
	/* 0xf08: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f0d:
	/* 0xf0d: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_f14:
	/* 0xf14: je     10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10a9;
	}
x86_l_f1a:
	/* 0xf1a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f1f:
	/* 0xf1f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f24:
	/* 0xf24: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f29:
	/* 0xf29: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f2e:
	/* 0xf2e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f33:
	/* 0xf33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f35:
	/* 0xf35: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f37:
	/* 0xf37: jns    10a9 <generic_sleepable_preload+0x10a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_10a9;
	}
x86_l_f3d:
	/* 0xf3d: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_f43:
	/* 0xf43: jmp    10a1 <generic_sleepable_preload+0x10a1> */
	goto x86_l_10a1;
x86_l_f48:
	/* 0xf48: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_f4e:
	/* 0xf4e: jmp    10a1 <generic_sleepable_preload+0x10a1> */
	goto x86_l_10a1;
x86_l_f53:
	/* 0xf53: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_f59:
	/* 0xf59: jmp    fb8 <generic_sleepable_preload+0xfb8> */
	goto x86_l_fb8;
x86_l_f5b:
	/* 0xf5b: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_f61:
	/* 0xf61: jmp    10a1 <generic_sleepable_preload+0x10a1> */
	goto x86_l_10a1;
x86_l_f66:
	/* 0xf66: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_f6c:
	/* 0xf6c: jmp    fb8 <generic_sleepable_preload+0xfb8> */
	goto x86_l_fb8;
x86_l_f6e:
	/* 0xf6e: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_f74:
	/* 0xf74: jmp    10a1 <generic_sleepable_preload+0x10a1> */
	goto x86_l_10a1;
x86_l_f79:
	/* 0xf79: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_f7f:
	/* 0xf7f: jmp    fb8 <generic_sleepable_preload+0xfb8> */
	goto x86_l_fb8;
x86_l_f81:
	/* 0xf81: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_f87:
	/* 0xf87: jmp    10a1 <generic_sleepable_preload+0x10a1> */
	goto x86_l_10a1;
x86_l_f8c:
	/* 0xf8c: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_f92:
	/* 0xf92: jmp    fb8 <generic_sleepable_preload+0xfb8> */
	goto x86_l_fb8;
x86_l_f94:
	/* 0xf94: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_f9a:
	/* 0xf9a: jmp    10a1 <generic_sleepable_preload+0x10a1> */
	goto x86_l_10a1;
x86_l_f9f:
	/* 0xf9f: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_fa5:
	/* 0xfa5: jmp    fb8 <generic_sleepable_preload+0xfb8> */
	goto x86_l_fb8;
x86_l_fa7:
	/* 0xfa7: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_fad:
	/* 0xfad: jmp    10a1 <generic_sleepable_preload+0x10a1> */
	goto x86_l_10a1;
x86_l_fb2:
	/* 0xfb2: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_fb8:
	/* 0xfb8: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_fc0:
	/* 0xfc0: mov    r13d,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc3:
	/* 0xfc3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fc8:
	/* 0xfc8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fcd:
	/* 0xfcd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fd2:
	/* 0xfd2: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_fd5:
	/* 0xfd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd7:
	/* 0xfd7: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_fdb:
	/* 0xfdb: jne    11f <generic_sleepable_preload+0x11f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 287ULL;
	}
x86_l_fe1:
	/* 0xfe1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe6:
	/* 0xfe6: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_fee:
	/* 0xfee: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_ff3:
	/* 0xff3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff5:
	/* 0xff5: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ffa:
	/* 0xffa: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1002:
	/* 0x1002: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1007:
	/* 0x1007: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_100e:
	/* 0x100e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1013:
	/* 0x1013: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1015:
	/* 0x1015: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1018:
	/* 0x1018: je     11f <generic_sleepable_preload+0x11f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 287ULL;
	}
x86_l_101e:
	/* 0x101e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1021:
	/* 0x1021: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1026:
	/* 0x1026: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1028:
	/* 0x1028: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_102d:
	/* 0x102d: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_1030:
	/* 0x1030: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1037:
	/* 0x1037: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_103a:
	/* 0x103a: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_103d:
	/* 0x103d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_103f:
	/* 0x103f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1041:
	/* 0x1041: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1046:
	/* 0x1046: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1049:
	/* 0x1049: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_104c:
	/* 0x104c: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_104f:
	/* 0x104f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1051:
	/* 0x1051: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1054:
	/* 0x1054: je     11f <generic_sleepable_preload+0x11f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 287ULL;
	}
x86_l_105a:
	/* 0x105a: cmp    BYTE PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_105f:
	/* 0x105f: je     11c <generic_sleepable_preload+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 284ULL;
	}
x86_l_1065:
	/* 0x1065: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1069:
	/* 0x1069: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_106e:
	/* 0x106e: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1076:
	/* 0x1076: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1078:
	/* 0x1078: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_107b:
	/* 0x107b: call   1080 <generic_sleepable_preload+0x1080> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1080:
	/* 0x1080: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1082:
	/* 0x1082: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1085:
	/* 0x1085: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_1088:
	/* 0x1088: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_108a:
	/* 0x108a: jns    11c <generic_sleepable_preload+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 284ULL;
	}
x86_l_1090:
	/* 0x1090: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_1096:
	/* 0x1096: jmp    11c <generic_sleepable_preload+0x11c> */
	return 284ULL;
x86_l_109b:
	/* 0x109b: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_10a1:
	/* 0x10a1: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_10a9:
	/* 0x10a9: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_10ac:
	/* 0x10ac: jne    124 <generic_sleepable_preload+0x124> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 292ULL;
	}
x86_l_10b2:
	/* 0x10b2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10b7:
	/* 0x10b7: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_10bf:
	/* 0x10bf: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_10c4:
	/* 0x10c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c6:
	/* 0x10c6: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10cb:
	/* 0x10cb: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10d3:
	/* 0x10d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10d8:
	/* 0x10d8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_10df:
	/* 0x10df: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10e4:
	/* 0x10e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e6:
	/* 0x10e6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10e9:
	/* 0x10e9: je     11f <generic_sleepable_preload+0x11f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 287ULL;
	}
x86_l_10ef:
	/* 0x10ef: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_10f2:
	/* 0x10f2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10f7:
	/* 0x10f7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10f9:
	/* 0x10f9: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10fe:
	/* 0x10fe: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_1101:
	/* 0x1101: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1108:
	/* 0x1108: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_110b:
	/* 0x110b: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_110e:
	/* 0x110e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1110:
	/* 0x1110: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1112:
	/* 0x1112: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1117:
	/* 0x1117: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_111a:
	/* 0x111a: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_111d:
	/* 0x111d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_111f:
	/* 0x111f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1122:
	/* 0x1122: je     11f <generic_sleepable_preload+0x11f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 287ULL;
	}
x86_l_1128:
	/* 0x1128: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_112b:
	/* 0x112b: cmp    BYTE PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1130:
	/* 0x1130: je     1154 <generic_sleepable_preload+0x1154> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1154;
	}
x86_l_1132:
	/* 0x1132: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1136:
	/* 0x1136: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_113b:
	/* 0x113b: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1143:
	/* 0x1143: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1145:
	/* 0x1145: call   114a <generic_sleepable_preload+0x114a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_114a:
	/* 0x114a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_114c:
	/* 0x114c: jns    1154 <generic_sleepable_preload+0x1154> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1154;
	}
x86_l_114e:
	/* 0x114e: mov    r13d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_1154:
	/* 0x1154: mov    DWORD PTR [rbp+0x0],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1158:
	/* 0x1158: jmp    11f <generic_sleepable_preload+0x11f> */
	return 287ULL;
x86_l_115d:
	/* 0x115d: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1165:
	/* 0x1165: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_116b:
	/* 0x116b: jmp    fc0 <generic_sleepable_preload+0xfc0> */
	goto x86_l_fc0;
x86_l_1170:
	/* 0x1170: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1178:
	/* 0x1178: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_117e:
	/* 0x117e: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1181:
	/* 0x1181: jne    124 <generic_sleepable_preload+0x124> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 292ULL;
	}
x86_l_1187:
	/* 0x1187: jmp    10b2 <generic_sleepable_preload+0x10b2> */
	goto x86_l_10b2;
x86_l_118c:
	/* 0x118c: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_1192:
	/* 0x1192: jmp    fb8 <generic_sleepable_preload+0xfb8> */
	goto x86_l_fb8;
x86_l_1197:
	/* 0x1197: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_119d:
	/* 0x119d: jmp    10a1 <generic_sleepable_preload+0x10a1> */
	goto x86_l_10a1;
x86_l_11a2:
	/* 0x11a2: mov    eax,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11a6:
	/* 0x11a6: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11ab:
	/* 0x11ab: jne    11ff <generic_sleepable_preload+0x11ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11ff;
	}
x86_l_11ad:
	/* 0x11ad: mov    eax,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_11b1:
	/* 0x11b1: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11b6:
	/* 0x11b6: jne    1261 <generic_sleepable_preload+0x1261> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1261;
	}
x86_l_11bc:
	/* 0x11bc: mov    eax,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11c0:
	/* 0x11c0: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11c5:
	/* 0x11c5: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11ca:
	/* 0x11ca: jne    12c3 <generic_sleepable_preload+0x12c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12c3;
	}
x86_l_11d0:
	/* 0x11d0: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_11d4:
	/* 0x11d4: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11d9:
	/* 0x11d9: jne    132a <generic_sleepable_preload+0x132a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_132a;
	}
x86_l_11df:
	/* 0x11df: mov    eax,DWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11e3:
	/* 0x11e3: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11e8:
	/* 0x11e8: jne    1391 <generic_sleepable_preload+0x1391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1391;
	}
x86_l_11ee:
	/* 0x11ee: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11f0:
	/* 0x11f0: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_11f7:
	/* 0x11f7: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_11f9:
	/* 0x11f9: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_11fa:
	/* 0x11fa: jmp    6a60 <generic_sleepable_preload+0x6a60> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_11ff:
	/* 0x11ff: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1201:
	/* 0x1201: js     13f7 <generic_sleepable_preload+0x13f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_13f7;
	}
x86_l_1207:
	/* 0x1207: movzx  eax,BYTE PTR [r13+0x211] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 529ULL);
x86_l_120f:
	/* 0x120f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1211:
	/* 0x1211: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1214:
	/* 0x1214: jg     15f0 <generic_sleepable_preload+0x15f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5616ULL;
	}
x86_l_121a:
	/* 0x121a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_121d:
	/* 0x121d: je     1b61 <generic_sleepable_preload+0x1b61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7009ULL;
	}
x86_l_1223:
	/* 0x1223: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1226:
	/* 0x1226: jne    1cd7 <generic_sleepable_preload+0x1cd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7383ULL;
	}
x86_l_122c:
	/* 0x122c: mov    edx,DWORD PTR [r13+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1233:
	/* 0x1233: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1239:
	/* 0x1239: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_123c:
	/* 0x123c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1241:
	/* 0x1241: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1246:
	/* 0x1246: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_124b:
	/* 0x124b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1250:
	/* 0x1250: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1252:
	/* 0x1252: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1254:
	/* 0x1254: je     1b6d <generic_sleepable_preload+0x1b6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7021ULL;
	}
x86_l_125a:
	/* 0x125a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_125c:
	/* 0x125c: jmp    1cd7 <generic_sleepable_preload+0x1cd7> */
	return 7383ULL;
x86_l_1261:
	/* 0x1261: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1263:
	/* 0x1263: js     145c <generic_sleepable_preload+0x145c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_145c;
	}
x86_l_1269:
	/* 0x1269: movzx  eax,BYTE PTR [r13+0x229] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 553ULL);
x86_l_1271:
	/* 0x1271: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1273:
	/* 0x1273: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1276:
	/* 0x1276: jg     16bd <generic_sleepable_preload+0x16bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5821ULL;
	}
x86_l_127c:
	/* 0x127c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_127f:
	/* 0x127f: je     1b97 <generic_sleepable_preload+0x1b97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7063ULL;
	}
x86_l_1285:
	/* 0x1285: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1288:
	/* 0x1288: jne    23a0 <generic_sleepable_preload+0x23a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9120ULL;
	}
x86_l_128e:
	/* 0x128e: mov    edx,DWORD PTR [r13+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_1295:
	/* 0x1295: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_129b:
	/* 0x129b: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_129e:
	/* 0x129e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12a3:
	/* 0x12a3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12a8:
	/* 0x12a8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12ad:
	/* 0x12ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12b2:
	/* 0x12b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b4:
	/* 0x12b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12b6:
	/* 0x12b6: je     1ba3 <generic_sleepable_preload+0x1ba3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7075ULL;
	}
x86_l_12bc:
	/* 0x12bc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12be:
	/* 0x12be: jmp    23a0 <generic_sleepable_preload+0x23a0> */
	return 9120ULL;
x86_l_12c3:
	/* 0x12c3: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_12c5:
	/* 0x12c5: js     14c1 <generic_sleepable_preload+0x14c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_14c1;
	}
x86_l_12cb:
	/* 0x12cb: movzx  eax,BYTE PTR [r13+0x241] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 577ULL);
x86_l_12d3:
	/* 0x12d3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12d5:
	/* 0x12d5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12d8:
	/* 0x12d8: jg     1738 <generic_sleepable_preload+0x1738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5944ULL;
	}
x86_l_12de:
	/* 0x12de: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12e1:
	/* 0x12e1: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12e6:
	/* 0x12e6: je     1bd2 <generic_sleepable_preload+0x1bd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7122ULL;
	}
x86_l_12ec:
	/* 0x12ec: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12ef:
	/* 0x12ef: jne    2a75 <generic_sleepable_preload+0x2a75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10869ULL;
	}
x86_l_12f5:
	/* 0x12f5: mov    edx,DWORD PTR [r13+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_12fc:
	/* 0x12fc: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1302:
	/* 0x1302: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1305:
	/* 0x1305: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_130a:
	/* 0x130a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_130f:
	/* 0x130f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1314:
	/* 0x1314: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1319:
	/* 0x1319: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131b:
	/* 0x131b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_131d:
	/* 0x131d: je     1bde <generic_sleepable_preload+0x1bde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7134ULL;
	}
x86_l_1323:
	/* 0x1323: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1325:
	/* 0x1325: jmp    2a75 <generic_sleepable_preload+0x2a75> */
	return 10869ULL;
x86_l_132a:
	/* 0x132a: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_132c:
	/* 0x132c: js     1526 <generic_sleepable_preload+0x1526> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5414ULL;
	}
x86_l_1332:
	/* 0x1332: movzx  eax,BYTE PTR [r13+0x259] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 601ULL);
x86_l_133a:
	/* 0x133a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_133c:
	/* 0x133c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_133f:
	/* 0x133f: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1344:
	/* 0x1344: jg     17b8 <generic_sleepable_preload+0x17b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6072ULL;
	}
x86_l_134a:
	/* 0x134a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_134d:
	/* 0x134d: je     1c08 <generic_sleepable_preload+0x1c08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7176ULL;
	}
x86_l_1353:
	/* 0x1353: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1356:
	/* 0x1356: jne    3159 <generic_sleepable_preload+0x3159> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12633ULL;
	}
x86_l_135c:
	/* 0x135c: mov    edx,DWORD PTR [r13+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_1363:
	/* 0x1363: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1369:
	/* 0x1369: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_136c:
	/* 0x136c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1371:
	/* 0x1371: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1376:
	/* 0x1376: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_137b:
	/* 0x137b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1380:
	/* 0x1380: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1382:
	/* 0x1382: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1384:
	/* 0x1384: je     1c14 <generic_sleepable_preload+0x1c14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7188ULL;
	}
x86_l_138a:
	/* 0x138a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_138c:
	/* 0x138c: jmp    3159 <generic_sleepable_preload+0x3159> */
	return 12633ULL;
x86_l_1391:
	/* 0x1391: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1393:
	/* 0x1393: js     158b <generic_sleepable_preload+0x158b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5515ULL;
	}
x86_l_1399:
	/* 0x1399: movzx  eax,BYTE PTR [r13+0x271] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 625ULL);
x86_l_13a1:
	/* 0x13a1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13a3:
	/* 0x13a3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13a6:
	/* 0x13a6: jg     1833 <generic_sleepable_preload+0x1833> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6195ULL;
	}
x86_l_13ac:
	/* 0x13ac: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13af:
	/* 0x13af: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13b4:
	/* 0x13b4: je     1c3e <generic_sleepable_preload+0x1c3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7230ULL;
	}
x86_l_13ba:
	/* 0x13ba: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13bd:
	/* 0x13bd: jne    3830 <generic_sleepable_preload+0x3830> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14384ULL;
	}
x86_l_13c3:
	/* 0x13c3: mov    eax,DWORD PTR [r13+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_13ca:
	/* 0x13ca: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13cf:
	/* 0x13cf: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_13d2:
	/* 0x13d2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13d7:
	/* 0x13d7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13dc:
	/* 0x13dc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13e1:
	/* 0x13e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13e6:
	/* 0x13e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e8:
	/* 0x13e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13ea:
	/* 0x13ea: je     1c4a <generic_sleepable_preload+0x1c4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7242ULL;
	}
x86_l_13f0:
	/* 0x13f0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13f2:
	/* 0x13f2: jmp    3830 <generic_sleepable_preload+0x3830> */
	return 14384ULL;
x86_l_13f7:
	/* 0x13f7: movzx  eax,BYTE PTR [r13+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_13ff:
	/* 0x13ff: movzx  ecx,WORD PTR [r13+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_1407:
	/* 0x1407: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_140d:
	/* 0x140d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_140f:
	/* 0x140f: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1412:
	/* 0x1412: jle    18b5 <generic_sleepable_preload+0x18b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6325ULL;
	}
x86_l_1418:
	/* 0x1418: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_141b:
	/* 0x141b: jle    199f <generic_sleepable_preload+0x199f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6559ULL;
	}
x86_l_1421:
	/* 0x1421: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1424:
	/* 0x1424: jle    409e <generic_sleepable_preload+0x409e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 16542ULL;
	}
x86_l_142a:
	/* 0x142a: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1432:
	/* 0x1432: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_1435:
	/* 0x1435: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16565ULL;
	}
x86_l_143b:
	/* 0x143b: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1440:
	/* 0x1440: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1443:
	/* 0x1443: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16565ULL;
	}
x86_l_1449:
	/* 0x1449: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_144c:
	/* 0x144c: jne    40c8 <generic_sleepable_preload+0x40c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16584ULL;
	}
x86_l_1452:
	/* 0x1452: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1457:
	/* 0x1457: jmp    40b5 <generic_sleepable_preload+0x40b5> */
	return 16565ULL;
x86_l_145c:
	/* 0x145c: movzx  eax,BYTE PTR [r13+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_1464:
	/* 0x1464: movzx  ecx,WORD PTR [r13+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_146c:
	/* 0x146c: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1472:
	/* 0x1472: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1474:
	/* 0x1474: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1477:
	/* 0x1477: jle    18e5 <generic_sleepable_preload+0x18e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6373ULL;
	}
x86_l_147d:
	/* 0x147d: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1480:
	/* 0x1480: jle    19cc <generic_sleepable_preload+0x19cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6604ULL;
	}
x86_l_1486:
	/* 0x1486: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1489:
	/* 0x1489: jle    46ea <generic_sleepable_preload+0x46ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 18154ULL;
	}
x86_l_148f:
	/* 0x148f: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1497:
	/* 0x1497: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_149a:
	/* 0x149a: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_14a0:
	/* 0x14a0: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14a5:
	/* 0x14a5: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_14a8:
	/* 0x14a8: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_14ae:
	/* 0x14ae: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14b3:
	/* 0x14b3: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_14b6:
	/* 0x14b6: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_14bc:
	/* 0x14bc: jmp    5457 <generic_sleepable_preload+0x5457> */
	return 21591ULL;
x86_l_14c1:
	/* 0x14c1: movzx  eax,BYTE PTR [r13+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_14c9:
	/* 0x14c9: movzx  ecx,WORD PTR [r13+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_14d1:
	/* 0x14d1: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_14d7:
	/* 0x14d7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14d9:
	/* 0x14d9: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_14dc:
	/* 0x14dc: jle    1912 <generic_sleepable_preload+0x1912> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6418ULL;
	}
x86_l_14e2:
	/* 0x14e2: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_14e5:
	/* 0x14e5: jle    19f9 <generic_sleepable_preload+0x19f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6649ULL;
	}
x86_l_14eb:
	/* 0x14eb: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_14ee:
	/* 0x14ee: jle    470e <generic_sleepable_preload+0x470e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 18190ULL;
	}
	return 5364ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5364ULL: goto x86_l_14f4;
	case 5372ULL: goto x86_l_14fc;
	case 5375ULL: goto x86_l_14ff;
	case 5381ULL: goto x86_l_1505;
	case 5386ULL: goto x86_l_150a;
	case 5389ULL: goto x86_l_150d;
	case 5395ULL: goto x86_l_1513;
	case 5400ULL: goto x86_l_1518;
	case 5403ULL: goto x86_l_151b;
	case 5409ULL: goto x86_l_1521;
	case 5414ULL: goto x86_l_1526;
	case 5422ULL: goto x86_l_152e;
	case 5430ULL: goto x86_l_1536;
	case 5436ULL: goto x86_l_153c;
	case 5438ULL: goto x86_l_153e;
	case 5441ULL: goto x86_l_1541;
	case 5447ULL: goto x86_l_1547;
	case 5450ULL: goto x86_l_154a;
	case 5456ULL: goto x86_l_1550;
	case 5459ULL: goto x86_l_1553;
	case 5465ULL: goto x86_l_1559;
	case 5473ULL: goto x86_l_1561;
	case 5476ULL: goto x86_l_1564;
	case 5482ULL: goto x86_l_156a;
	case 5487ULL: goto x86_l_156f;
	case 5490ULL: goto x86_l_1572;
	case 5496ULL: goto x86_l_1578;
	case 5501ULL: goto x86_l_157d;
	case 5504ULL: goto x86_l_1580;
	case 5510ULL: goto x86_l_1586;
	case 5515ULL: goto x86_l_158b;
	case 5523ULL: goto x86_l_1593;
	case 5531ULL: goto x86_l_159b;
	case 5537ULL: goto x86_l_15a1;
	case 5539ULL: goto x86_l_15a3;
	case 5542ULL: goto x86_l_15a6;
	case 5548ULL: goto x86_l_15ac;
	case 5551ULL: goto x86_l_15af;
	case 5557ULL: goto x86_l_15b5;
	case 5560ULL: goto x86_l_15b8;
	case 5566ULL: goto x86_l_15be;
	case 5574ULL: goto x86_l_15c6;
	case 5577ULL: goto x86_l_15c9;
	case 5583ULL: goto x86_l_15cf;
	case 5588ULL: goto x86_l_15d4;
	case 5591ULL: goto x86_l_15d7;
	case 5597ULL: goto x86_l_15dd;
	case 5602ULL: goto x86_l_15e2;
	case 5605ULL: goto x86_l_15e5;
	case 5611ULL: goto x86_l_15eb;
	case 5616ULL: goto x86_l_15f0;
	case 5619ULL: goto x86_l_15f3;
	case 5625ULL: goto x86_l_15f9;
	case 5628ULL: goto x86_l_15fc;
	case 5634ULL: goto x86_l_1602;
	case 5641ULL: goto x86_l_1609;
	case 5647ULL: goto x86_l_160f;
	case 5650ULL: goto x86_l_1612;
	case 5655ULL: goto x86_l_1617;
	case 5660ULL: goto x86_l_161c;
	case 5665ULL: goto x86_l_1621;
	case 5670ULL: goto x86_l_1626;
	case 5672ULL: goto x86_l_1628;
	case 5674ULL: goto x86_l_162a;
	case 5680ULL: goto x86_l_1630;
	case 5687ULL: goto x86_l_1637;
	case 5693ULL: goto x86_l_163d;
	case 5696ULL: goto x86_l_1640;
	case 5701ULL: goto x86_l_1645;
	case 5706ULL: goto x86_l_164a;
	case 5711ULL: goto x86_l_164f;
	case 5716ULL: goto x86_l_1654;
	case 5718ULL: goto x86_l_1656;
	case 5720ULL: goto x86_l_1658;
	case 5726ULL: goto x86_l_165e;
	case 5734ULL: goto x86_l_1666;
	case 5741ULL: goto x86_l_166d;
	case 5748ULL: goto x86_l_1674;
	case 5753ULL: goto x86_l_1679;
	case 5756ULL: goto x86_l_167c;
	case 5761ULL: goto x86_l_1681;
	case 5766ULL: goto x86_l_1686;
	case 5771ULL: goto x86_l_168b;
	case 5779ULL: goto x86_l_1693;
	case 5786ULL: goto x86_l_169a;
	case 5793ULL: goto x86_l_16a1;
	case 5798ULL: goto x86_l_16a6;
	case 5801ULL: goto x86_l_16a9;
	case 5806ULL: goto x86_l_16ae;
	case 5808ULL: goto x86_l_16b0;
	case 5810ULL: goto x86_l_16b2;
	case 5816ULL: goto x86_l_16b8;
	case 5821ULL: goto x86_l_16bd;
	case 5824ULL: goto x86_l_16c0;
	case 5830ULL: goto x86_l_16c6;
	case 5833ULL: goto x86_l_16c9;
	case 5839ULL: goto x86_l_16cf;
	case 5846ULL: goto x86_l_16d6;
	case 5852ULL: goto x86_l_16dc;
	case 5855ULL: goto x86_l_16df;
	case 5860ULL: goto x86_l_16e4;
	case 5865ULL: goto x86_l_16e9;
	case 5870ULL: goto x86_l_16ee;
	case 5875ULL: goto x86_l_16f3;
	case 5877ULL: goto x86_l_16f5;
	case 5879ULL: goto x86_l_16f7;
	case 5885ULL: goto x86_l_16fd;
	case 5890ULL: goto x86_l_1702;
	case 5897ULL: goto x86_l_1709;
	case 5902ULL: goto x86_l_170e;
	case 5907ULL: goto x86_l_1713;
	case 5912ULL: goto x86_l_1718;
	case 5917ULL: goto x86_l_171d;
	case 5924ULL: goto x86_l_1724;
	case 5929ULL: goto x86_l_1729;
	case 5931ULL: goto x86_l_172b;
	case 5933ULL: goto x86_l_172d;
	case 5939ULL: goto x86_l_1733;
	case 5944ULL: goto x86_l_1738;
	case 5947ULL: goto x86_l_173b;
	case 5952ULL: goto x86_l_1740;
	case 5958ULL: goto x86_l_1746;
	case 5961ULL: goto x86_l_1749;
	case 5967ULL: goto x86_l_174f;
	case 5974ULL: goto x86_l_1756;
	case 5980ULL: goto x86_l_175c;
	case 5983ULL: goto x86_l_175f;
	case 5988ULL: goto x86_l_1764;
	case 5993ULL: goto x86_l_1769;
	case 5998ULL: goto x86_l_176e;
	case 6003ULL: goto x86_l_1773;
	case 6005ULL: goto x86_l_1775;
	case 6007ULL: goto x86_l_1777;
	case 6013ULL: goto x86_l_177d;
	case 6018ULL: goto x86_l_1782;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6035ULL: goto x86_l_1793;
	case 6040ULL: goto x86_l_1798;
	case 6045ULL: goto x86_l_179d;
	case 6052ULL: goto x86_l_17a4;
	case 6057ULL: goto x86_l_17a9;
	case 6059ULL: goto x86_l_17ab;
	case 6061ULL: goto x86_l_17ad;
	case 6067ULL: goto x86_l_17b3;
	case 6072ULL: goto x86_l_17b8;
	case 6075ULL: goto x86_l_17bb;
	case 6081ULL: goto x86_l_17c1;
	case 6084ULL: goto x86_l_17c4;
	case 6090ULL: goto x86_l_17ca;
	case 6097ULL: goto x86_l_17d1;
	case 6103ULL: goto x86_l_17d7;
	case 6106ULL: goto x86_l_17da;
	case 6111ULL: goto x86_l_17df;
	case 6116ULL: goto x86_l_17e4;
	case 6121ULL: goto x86_l_17e9;
	case 6126ULL: goto x86_l_17ee;
	case 6128ULL: goto x86_l_17f0;
	case 6130ULL: goto x86_l_17f2;
	case 6136ULL: goto x86_l_17f8;
	case 6141ULL: goto x86_l_17fd;
	case 6148ULL: goto x86_l_1804;
	case 6153ULL: goto x86_l_1809;
	case 6158ULL: goto x86_l_180e;
	case 6163ULL: goto x86_l_1813;
	case 6168ULL: goto x86_l_1818;
	case 6175ULL: goto x86_l_181f;
	case 6180ULL: goto x86_l_1824;
	case 6182ULL: goto x86_l_1826;
	case 6184ULL: goto x86_l_1828;
	case 6190ULL: goto x86_l_182e;
	case 6195ULL: goto x86_l_1833;
	case 6198ULL: goto x86_l_1836;
	case 6203ULL: goto x86_l_183b;
	case 6209ULL: goto x86_l_1841;
	case 6212ULL: goto x86_l_1844;
	case 6218ULL: goto x86_l_184a;
	case 6225ULL: goto x86_l_1851;
	case 6230ULL: goto x86_l_1856;
	case 6233ULL: goto x86_l_1859;
	case 6238ULL: goto x86_l_185e;
	case 6243ULL: goto x86_l_1863;
	case 6248ULL: goto x86_l_1868;
	case 6253ULL: goto x86_l_186d;
	case 6256ULL: goto x86_l_1870;
	case 6258ULL: goto x86_l_1872;
	case 6260ULL: goto x86_l_1874;
	case 6266ULL: goto x86_l_187a;
	case 6271ULL: goto x86_l_187f;
	case 6278ULL: goto x86_l_1886;
	case 6283ULL: goto x86_l_188b;
	case 6288ULL: goto x86_l_1890;
	case 6293ULL: goto x86_l_1895;
	case 6298ULL: goto x86_l_189a;
	case 6305ULL: goto x86_l_18a1;
	case 6310ULL: goto x86_l_18a6;
	case 6312ULL: goto x86_l_18a8;
	case 6314ULL: goto x86_l_18aa;
	case 6320ULL: goto x86_l_18b0;
	case 6325ULL: goto x86_l_18b5;
	case 6328ULL: goto x86_l_18b8;
	case 6334ULL: goto x86_l_18be;
	case 6337ULL: goto x86_l_18c1;
	case 6343ULL: goto x86_l_18c7;
	case 6346ULL: goto x86_l_18ca;
	case 6348ULL: goto x86_l_18cc;
	case 6354ULL: goto x86_l_18d2;
	case 6359ULL: goto x86_l_18d7;
	case 6362ULL: goto x86_l_18da;
	case 6368ULL: goto x86_l_18e0;
	case 6373ULL: goto x86_l_18e5;
	case 6376ULL: goto x86_l_18e8;
	case 6382ULL: goto x86_l_18ee;
	case 6385ULL: goto x86_l_18f1;
	case 6391ULL: goto x86_l_18f7;
	case 6393ULL: goto x86_l_18f9;
	case 6399ULL: goto x86_l_18ff;
	case 6404ULL: goto x86_l_1904;
	case 6407ULL: goto x86_l_1907;
	case 6413ULL: goto x86_l_190d;
	case 6418ULL: goto x86_l_1912;
	case 6421ULL: goto x86_l_1915;
	case 6426ULL: goto x86_l_191a;
	case 6432ULL: goto x86_l_1920;
	case 6435ULL: goto x86_l_1923;
	case 6441ULL: goto x86_l_1929;
	case 6443ULL: goto x86_l_192b;
	case 6449ULL: goto x86_l_1931;
	case 6452ULL: goto x86_l_1934;
	case 6455ULL: goto x86_l_1937;
	case 6461ULL: goto x86_l_193d;
	case 6466ULL: goto x86_l_1942;
	case 6469ULL: goto x86_l_1945;
	case 6474ULL: goto x86_l_194a;
	case 6480ULL: goto x86_l_1950;
	case 6483ULL: goto x86_l_1953;
	case 6489ULL: goto x86_l_1959;
	case 6491ULL: goto x86_l_195b;
	case 6497ULL: goto x86_l_1961;
	case 6500ULL: goto x86_l_1964;
	case 6503ULL: goto x86_l_1967;
	case 6509ULL: goto x86_l_196d;
	case 6514ULL: goto x86_l_1972;
	case 6517ULL: goto x86_l_1975;
	case 6523ULL: goto x86_l_197b;
	case 6526ULL: goto x86_l_197e;
	case 6532ULL: goto x86_l_1984;
	case 6534ULL: goto x86_l_1986;
	case 6540ULL: goto x86_l_198c;
	case 6543ULL: goto x86_l_198f;
	case 6548ULL: goto x86_l_1994;
	case 6554ULL: goto x86_l_199a;
	case 6559ULL: goto x86_l_199f;
	case 6562ULL: goto x86_l_19a2;
	case 6568ULL: goto x86_l_19a8;
	case 6576ULL: goto x86_l_19b0;
	case 6579ULL: goto x86_l_19b3;
	case 6585ULL: goto x86_l_19b9;
	case 6590ULL: goto x86_l_19be;
	case 6593ULL: goto x86_l_19c1;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6607ULL: goto x86_l_19cf;
	case 6613ULL: goto x86_l_19d5;
	case 6621ULL: goto x86_l_19dd;
	case 6624ULL: goto x86_l_19e0;
	case 6630ULL: goto x86_l_19e6;
	case 6635ULL: goto x86_l_19eb;
	case 6638ULL: goto x86_l_19ee;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6652ULL: goto x86_l_19fc;
	case 6658ULL: goto x86_l_1a02;
	case 6666ULL: goto x86_l_1a0a;
	case 6669ULL: goto x86_l_1a0d;
	case 6675ULL: goto x86_l_1a13;
	case 6680ULL: goto x86_l_1a18;
	case 6683ULL: goto x86_l_1a1b;
	case 6689ULL: goto x86_l_1a21;
	case 6694ULL: goto x86_l_1a26;
	case 6697ULL: goto x86_l_1a29;
	case 6703ULL: goto x86_l_1a2f;
	case 6711ULL: goto x86_l_1a37;
	case 6714ULL: goto x86_l_1a3a;
	case 6720ULL: goto x86_l_1a40;
	case 6725ULL: goto x86_l_1a45;
	case 6728ULL: goto x86_l_1a48;
	case 6734ULL: goto x86_l_1a4e;
	case 6739ULL: goto x86_l_1a53;
	case 6742ULL: goto x86_l_1a56;
	case 6748ULL: goto x86_l_1a5c;
	case 6756ULL: goto x86_l_1a64;
	case 6759ULL: goto x86_l_1a67;
	case 6765ULL: goto x86_l_1a6d;
	case 6770ULL: goto x86_l_1a72;
	case 6773ULL: goto x86_l_1a75;
	case 6779ULL: goto x86_l_1a7b;
	case 6784ULL: goto x86_l_1a80;
	case 6787ULL: goto x86_l_1a83;
	case 6793ULL: goto x86_l_1a89;
	case 6801ULL: goto x86_l_1a91;
	case 6804ULL: goto x86_l_1a94;
	case 6810ULL: goto x86_l_1a9a;
	case 6815ULL: goto x86_l_1a9f;
	case 6818ULL: goto x86_l_1aa2;
	case 6824ULL: goto x86_l_1aa8;
	case 6829ULL: goto x86_l_1aad;
	case 6832ULL: goto x86_l_1ab0;
	case 6838ULL: goto x86_l_1ab6;
	case 6846ULL: goto x86_l_1abe;
	case 6849ULL: goto x86_l_1ac1;
	case 6855ULL: goto x86_l_1ac7;
	case 6860ULL: goto x86_l_1acc;
	case 6863ULL: goto x86_l_1acf;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6877ULL: goto x86_l_1add;
	case 6883ULL: goto x86_l_1ae3;
	case 6891ULL: goto x86_l_1aeb;
	case 6894ULL: goto x86_l_1aee;
	case 6900ULL: goto x86_l_1af4;
	case 6905ULL: goto x86_l_1af9;
	case 6908ULL: goto x86_l_1afc;
	case 6914ULL: goto x86_l_1b02;
	case 6919ULL: goto x86_l_1b07;
	case 6922ULL: goto x86_l_1b0a;
	case 6928ULL: goto x86_l_1b10;
	case 6936ULL: goto x86_l_1b18;
	case 6939ULL: goto x86_l_1b1b;
	case 6945ULL: goto x86_l_1b21;
	case 6950ULL: goto x86_l_1b26;
	case 6953ULL: goto x86_l_1b29;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6967ULL: goto x86_l_1b37;
	case 6973ULL: goto x86_l_1b3d;
	case 6981ULL: goto x86_l_1b45;
	case 6984ULL: goto x86_l_1b48;
	case 6990ULL: goto x86_l_1b4e;
	case 6995ULL: goto x86_l_1b53;
	case 6998ULL: goto x86_l_1b56;
	case 7004ULL: goto x86_l_1b5c;
	case 7009ULL: goto x86_l_1b61;
	case 7016ULL: goto x86_l_1b68;
	case 7021ULL: goto x86_l_1b6d;
	case 7029ULL: goto x86_l_1b75;
	case 7036ULL: goto x86_l_1b7c;
	case 7044ULL: goto x86_l_1b84;
	case 7049ULL: goto x86_l_1b89;
	case 7054ULL: goto x86_l_1b8e;
	case 7058ULL: goto x86_l_1b92;
	case 7063ULL: goto x86_l_1b97;
	case 7070ULL: goto x86_l_1b9e;
	case 7075ULL: goto x86_l_1ba3;
	case 7083ULL: goto x86_l_1bab;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7103ULL: goto x86_l_1bbf;
	case 7108ULL: goto x86_l_1bc4;
	case 7113ULL: goto x86_l_1bc9;
	case 7117ULL: goto x86_l_1bcd;
	case 7122ULL: goto x86_l_1bd2;
	case 7129ULL: goto x86_l_1bd9;
	case 7134ULL: goto x86_l_1bde;
	case 7142ULL: goto x86_l_1be6;
	case 7149ULL: goto x86_l_1bed;
	case 7157ULL: goto x86_l_1bf5;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7171ULL: goto x86_l_1c03;
	case 7176ULL: goto x86_l_1c08;
	case 7183ULL: goto x86_l_1c0f;
	case 7188ULL: goto x86_l_1c14;
	case 7196ULL: goto x86_l_1c1c;
	case 7203ULL: goto x86_l_1c23;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7221ULL: goto x86_l_1c35;
	case 7225ULL: goto x86_l_1c39;
	case 7230ULL: goto x86_l_1c3e;
	case 7237ULL: goto x86_l_1c45;
	case 7242ULL: goto x86_l_1c4a;
	case 7250ULL: goto x86_l_1c52;
	case 7257ULL: goto x86_l_1c59;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14f4:
	/* 0x14f4: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_14fc:
	/* 0x14fc: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_14ff:
	/* 0x14ff: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_1505:
	/* 0x1505: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_150a:
	/* 0x150a: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_150d:
	/* 0x150d: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_1513:
	/* 0x1513: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1518:
	/* 0x1518: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_151b:
	/* 0x151b: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_1521:
	/* 0x1521: jmp    4738 <generic_sleepable_preload+0x4738> */
	return 18232ULL;
x86_l_1526:
	/* 0x1526: movzx  eax,BYTE PTR [r13+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_152e:
	/* 0x152e: movzx  ecx,WORD PTR [r13+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_1536:
	/* 0x1536: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_153c:
	/* 0x153c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_153e:
	/* 0x153e: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1541:
	/* 0x1541: jle    1942 <generic_sleepable_preload+0x1942> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1942;
	}
x86_l_1547:
	/* 0x1547: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_154a:
	/* 0x154a: jle    1a26 <generic_sleepable_preload+0x1a26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a26;
	}
x86_l_1550:
	/* 0x1550: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1553:
	/* 0x1553: jle    4d75 <generic_sleepable_preload+0x4d75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 19829ULL;
	}
x86_l_1559:
	/* 0x1559: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1561:
	/* 0x1561: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_1564:
	/* 0x1564: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_156a:
	/* 0x156a: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_156f:
	/* 0x156f: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1572:
	/* 0x1572: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_1578:
	/* 0x1578: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_157d:
	/* 0x157d: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1580:
	/* 0x1580: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_1586:
	/* 0x1586: jmp    4d9f <generic_sleepable_preload+0x4d9f> */
	return 19871ULL;
x86_l_158b:
	/* 0x158b: movzx  eax,BYTE PTR [r13+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_1593:
	/* 0x1593: movzx  ecx,WORD PTR [r13+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_159b:
	/* 0x159b: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_15a1:
	/* 0x15a1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15a3:
	/* 0x15a3: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_15a6:
	/* 0x15a6: jle    1972 <generic_sleepable_preload+0x1972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1972;
	}
x86_l_15ac:
	/* 0x15ac: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_15af:
	/* 0x15af: jle    1a53 <generic_sleepable_preload+0x1a53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a53;
	}
x86_l_15b5:
	/* 0x15b5: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_15b8:
	/* 0x15b8: jle    53cd <generic_sleepable_preload+0x53cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 21453ULL;
	}
x86_l_15be:
	/* 0x15be: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15c6:
	/* 0x15c6: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_15c9:
	/* 0x15c9: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_15cf:
	/* 0x15cf: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15d4:
	/* 0x15d4: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_15d7:
	/* 0x15d7: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_15dd:
	/* 0x15dd: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15e2:
	/* 0x15e2: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_15e5:
	/* 0x15e5: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_15eb:
	/* 0x15eb: jmp    5aa7 <generic_sleepable_preload+0x5aa7> */
	return 23207ULL;
x86_l_15f0:
	/* 0x15f0: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_15f3:
	/* 0x15f3: je     1c74 <generic_sleepable_preload+0x1c74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7284ULL;
	}
x86_l_15f9:
	/* 0x15f9: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15fc:
	/* 0x15fc: jne    1cd7 <generic_sleepable_preload+0x1cd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7383ULL;
	}
x86_l_1602:
	/* 0x1602: mov    edx,DWORD PTR [r13+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1609:
	/* 0x1609: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_160f:
	/* 0x160f: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1612:
	/* 0x1612: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1617:
	/* 0x1617: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_161c:
	/* 0x161c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1621:
	/* 0x1621: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1626:
	/* 0x1626: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1628:
	/* 0x1628: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_162a:
	/* 0x162a: jne    1cd4 <generic_sleepable_preload+0x1cd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7380ULL;
	}
x86_l_1630:
	/* 0x1630: mov    edx,DWORD PTR [r13+0x20c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_1637:
	/* 0x1637: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_163d:
	/* 0x163d: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1640:
	/* 0x1640: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1645:
	/* 0x1645: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_164a:
	/* 0x164a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_164f:
	/* 0x164f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1654:
	/* 0x1654: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1656:
	/* 0x1656: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1658:
	/* 0x1658: jne    1cd4 <generic_sleepable_preload+0x1cd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7380ULL;
	}
x86_l_165e:
	/* 0x165e: movzx  eax,BYTE PTR [r13+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_1666:
	/* 0x1666: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_166d:
	/* 0x166d: mov    rcx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_1674:
	/* 0x1674: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1679:
	/* 0x1679: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_167c:
	/* 0x167c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1681:
	/* 0x1681: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1686:
	/* 0x1686: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_168b:
	/* 0x168b: movzx  ecx,BYTE PTR [r13+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_1693:
	/* 0x1693: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_169a:
	/* 0x169a: mov    rdx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_16a1:
	/* 0x16a1: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_16a6:
	/* 0x16a6: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16a9:
	/* 0x16a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16ae:
	/* 0x16ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16b0:
	/* 0x16b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16b2:
	/* 0x16b2: jne    1cd4 <generic_sleepable_preload+0x1cd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7380ULL;
	}
x86_l_16b8:
	/* 0x16b8: jmp    1b6d <generic_sleepable_preload+0x1b6d> */
	goto x86_l_1b6d;
x86_l_16bd:
	/* 0x16bd: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16c0:
	/* 0x16c0: je     22eb <generic_sleepable_preload+0x22eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8939ULL;
	}
x86_l_16c6:
	/* 0x16c6: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_16c9:
	/* 0x16c9: jne    23a0 <generic_sleepable_preload+0x23a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9120ULL;
	}
x86_l_16cf:
	/* 0x16cf: mov    edx,DWORD PTR [r13+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_16d6:
	/* 0x16d6: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16dc:
	/* 0x16dc: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16df:
	/* 0x16df: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16e4:
	/* 0x16e4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16e9:
	/* 0x16e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16ee:
	/* 0x16ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16f3:
	/* 0x16f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f5:
	/* 0x16f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16f7:
	/* 0x16f7: jne    239d <generic_sleepable_preload+0x239d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9117ULL;
	}
x86_l_16fd:
	/* 0x16fd: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1702:
	/* 0x1702: add    rcx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_1709:
	/* 0x1709: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_170e:
	/* 0x170e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1713:
	/* 0x1713: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1718:
	/* 0x1718: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_171d:
	/* 0x171d: add    rdx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_1724:
	/* 0x1724: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1729:
	/* 0x1729: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_172b:
	/* 0x172b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_172d:
	/* 0x172d: jne    239d <generic_sleepable_preload+0x239d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9117ULL;
	}
x86_l_1733:
	/* 0x1733: jmp    1ba3 <generic_sleepable_preload+0x1ba3> */
	goto x86_l_1ba3;
x86_l_1738:
	/* 0x1738: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_173b:
	/* 0x173b: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1740:
	/* 0x1740: je     29c0 <generic_sleepable_preload+0x29c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10688ULL;
	}
x86_l_1746:
	/* 0x1746: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1749:
	/* 0x1749: jne    2a75 <generic_sleepable_preload+0x2a75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10869ULL;
	}
x86_l_174f:
	/* 0x174f: mov    edx,DWORD PTR [r13+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_1756:
	/* 0x1756: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_175c:
	/* 0x175c: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_175f:
	/* 0x175f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1764:
	/* 0x1764: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1769:
	/* 0x1769: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_176e:
	/* 0x176e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1773:
	/* 0x1773: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1775:
	/* 0x1775: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1777:
	/* 0x1777: jne    2a72 <generic_sleepable_preload+0x2a72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10866ULL;
	}
x86_l_177d:
	/* 0x177d: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1782:
	/* 0x1782: add    rcx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_1789:
	/* 0x1789: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_178e:
	/* 0x178e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1793:
	/* 0x1793: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1798:
	/* 0x1798: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_179d:
	/* 0x179d: add    rdx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_17a4:
	/* 0x17a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17a9:
	/* 0x17a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ab:
	/* 0x17ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17ad:
	/* 0x17ad: jne    2a72 <generic_sleepable_preload+0x2a72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10866ULL;
	}
x86_l_17b3:
	/* 0x17b3: jmp    1bde <generic_sleepable_preload+0x1bde> */
	goto x86_l_1bde;
x86_l_17b8:
	/* 0x17b8: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17bb:
	/* 0x17bb: je     30a4 <generic_sleepable_preload+0x30a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12452ULL;
	}
x86_l_17c1:
	/* 0x17c1: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_17c4:
	/* 0x17c4: jne    3159 <generic_sleepable_preload+0x3159> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12633ULL;
	}
x86_l_17ca:
	/* 0x17ca: mov    edx,DWORD PTR [r13+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_17d1:
	/* 0x17d1: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17d7:
	/* 0x17d7: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17da:
	/* 0x17da: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17df:
	/* 0x17df: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17e4:
	/* 0x17e4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17e9:
	/* 0x17e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17ee:
	/* 0x17ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f0:
	/* 0x17f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17f2:
	/* 0x17f2: jne    3156 <generic_sleepable_preload+0x3156> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12630ULL;
	}
x86_l_17f8:
	/* 0x17f8: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17fd:
	/* 0x17fd: add    rcx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_1804:
	/* 0x1804: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1809:
	/* 0x1809: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_180e:
	/* 0x180e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1813:
	/* 0x1813: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1818:
	/* 0x1818: add    rdx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_181f:
	/* 0x181f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1824:
	/* 0x1824: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1826:
	/* 0x1826: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1828:
	/* 0x1828: jne    3156 <generic_sleepable_preload+0x3156> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12630ULL;
	}
x86_l_182e:
	/* 0x182e: jmp    1c14 <generic_sleepable_preload+0x1c14> */
	goto x86_l_1c14;
x86_l_1833:
	/* 0x1833: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1836:
	/* 0x1836: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_183b:
	/* 0x183b: je     3779 <generic_sleepable_preload+0x3779> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14201ULL;
	}
x86_l_1841:
	/* 0x1841: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1844:
	/* 0x1844: jne    3830 <generic_sleepable_preload+0x3830> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14384ULL;
	}
x86_l_184a:
	/* 0x184a: mov    eax,DWORD PTR [r13+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_1851:
	/* 0x1851: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1856:
	/* 0x1856: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1859:
	/* 0x1859: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_185e:
	/* 0x185e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1863:
	/* 0x1863: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1868:
	/* 0x1868: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_186d:
	/* 0x186d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1870:
	/* 0x1870: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1872:
	/* 0x1872: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1874:
	/* 0x1874: jne    382d <generic_sleepable_preload+0x382d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14381ULL;
	}
x86_l_187a:
	/* 0x187a: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_187f:
	/* 0x187f: add    rcx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_1886:
	/* 0x1886: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_188b:
	/* 0x188b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1890:
	/* 0x1890: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1895:
	/* 0x1895: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_189a:
	/* 0x189a: add    rdx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_18a1:
	/* 0x18a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18a6:
	/* 0x18a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a8:
	/* 0x18a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18aa:
	/* 0x18aa: jne    382d <generic_sleepable_preload+0x382d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14381ULL;
	}
x86_l_18b0:
	/* 0x18b0: jmp    1c4a <generic_sleepable_preload+0x1c4a> */
	goto x86_l_1c4a;
x86_l_18b5:
	/* 0x18b5: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_18b8:
	/* 0x18b8: jg     1a80 <generic_sleepable_preload+0x1a80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1a80;
	}
x86_l_18be:
	/* 0x18be: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_18c1:
	/* 0x18c1: jg     3f36 <generic_sleepable_preload+0x3f36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16182ULL;
	}
x86_l_18c7:
	/* 0x18c7: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_18ca:
	/* 0x18ca: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_18cc:
	/* 0x18cc: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16565ULL;
	}
x86_l_18d2:
	/* 0x18d2: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18d7:
	/* 0x18d7: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_18da:
	/* 0x18da: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16565ULL;
	}
x86_l_18e0:
	/* 0x18e0: jmp    40c8 <generic_sleepable_preload+0x40c8> */
	return 16584ULL;
x86_l_18e5:
	/* 0x18e5: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_18e8:
	/* 0x18e8: jg     1aad <generic_sleepable_preload+0x1aad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1aad;
	}
x86_l_18ee:
	/* 0x18ee: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_18f1:
	/* 0x18f1: jg     3f5a <generic_sleepable_preload+0x3f5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16218ULL;
	}
x86_l_18f7:
	/* 0x18f7: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_18f9:
	/* 0x18f9: je     5441 <generic_sleepable_preload+0x5441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21569ULL;
	}
x86_l_18ff:
	/* 0x18ff: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1904:
	/* 0x1904: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1907:
	/* 0x1907: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_190d:
	/* 0x190d: jmp    5457 <generic_sleepable_preload+0x5457> */
	return 21591ULL;
x86_l_1912:
	/* 0x1912: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1915:
	/* 0x1915: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_191a:
	/* 0x191a: jg     1ada <generic_sleepable_preload+0x1ada> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ada;
	}
x86_l_1920:
	/* 0x1920: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1923:
	/* 0x1923: jg     3f7e <generic_sleepable_preload+0x3f7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16254ULL;
	}
x86_l_1929:
	/* 0x1929: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_192b:
	/* 0x192b: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_1931:
	/* 0x1931: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1934:
	/* 0x1934: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1937:
	/* 0x1937: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_193d:
	/* 0x193d: jmp    4738 <generic_sleepable_preload+0x4738> */
	return 18232ULL;
x86_l_1942:
	/* 0x1942: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1945:
	/* 0x1945: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_194a:
	/* 0x194a: jg     1b07 <generic_sleepable_preload+0x1b07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b07;
	}
x86_l_1950:
	/* 0x1950: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1953:
	/* 0x1953: jg     3fa2 <generic_sleepable_preload+0x3fa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16290ULL;
	}
x86_l_1959:
	/* 0x1959: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_195b:
	/* 0x195b: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_1961:
	/* 0x1961: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1964:
	/* 0x1964: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1967:
	/* 0x1967: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_196d:
	/* 0x196d: jmp    4d9f <generic_sleepable_preload+0x4d9f> */
	return 19871ULL;
x86_l_1972:
	/* 0x1972: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1975:
	/* 0x1975: jg     1b34 <generic_sleepable_preload+0x1b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b34;
	}
x86_l_197b:
	/* 0x197b: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_197e:
	/* 0x197e: jg     3fc6 <generic_sleepable_preload+0x3fc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16326ULL;
	}
x86_l_1984:
	/* 0x1984: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1986:
	/* 0x1986: je     5a8f <generic_sleepable_preload+0x5a8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23183ULL;
	}
x86_l_198c:
	/* 0x198c: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_198f:
	/* 0x198f: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1994:
	/* 0x1994: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_199a:
	/* 0x199a: jmp    5aa7 <generic_sleepable_preload+0x5aa7> */
	return 23207ULL;
x86_l_199f:
	/* 0x199f: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19a2:
	/* 0x19a2: jg     3e82 <generic_sleepable_preload+0x3e82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16002ULL;
	}
x86_l_19a8:
	/* 0x19a8: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_19b0:
	/* 0x19b0: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19b3:
	/* 0x19b3: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16565ULL;
	}
x86_l_19b9:
	/* 0x19b9: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19be:
	/* 0x19be: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19c1:
	/* 0x19c1: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16565ULL;
	}
x86_l_19c7:
	/* 0x19c7: jmp    40c8 <generic_sleepable_preload+0x40c8> */
	return 16584ULL;
x86_l_19cc:
	/* 0x19cc: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19cf:
	/* 0x19cf: jg     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16038ULL;
	}
x86_l_19d5:
	/* 0x19d5: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_19dd:
	/* 0x19dd: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19e0:
	/* 0x19e0: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_19e6:
	/* 0x19e6: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19eb:
	/* 0x19eb: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19ee:
	/* 0x19ee: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_19f4:
	/* 0x19f4: jmp    5457 <generic_sleepable_preload+0x5457> */
	return 21591ULL;
x86_l_19f9:
	/* 0x19f9: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19fc:
	/* 0x19fc: jg     3eca <generic_sleepable_preload+0x3eca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16074ULL;
	}
x86_l_1a02:
	/* 0x1a02: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a0a:
	/* 0x1a0a: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a0d:
	/* 0x1a0d: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_1a13:
	/* 0x1a13: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a18:
	/* 0x1a18: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a1b:
	/* 0x1a1b: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_1a21:
	/* 0x1a21: jmp    4738 <generic_sleepable_preload+0x4738> */
	return 18232ULL;
x86_l_1a26:
	/* 0x1a26: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a29:
	/* 0x1a29: jg     3eee <generic_sleepable_preload+0x3eee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16110ULL;
	}
x86_l_1a2f:
	/* 0x1a2f: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a37:
	/* 0x1a37: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a3a:
	/* 0x1a3a: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_1a40:
	/* 0x1a40: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a45:
	/* 0x1a45: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a48:
	/* 0x1a48: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_1a4e:
	/* 0x1a4e: jmp    4d9f <generic_sleepable_preload+0x4d9f> */
	return 19871ULL;
x86_l_1a53:
	/* 0x1a53: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a56:
	/* 0x1a56: jg     3f12 <generic_sleepable_preload+0x3f12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16146ULL;
	}
x86_l_1a5c:
	/* 0x1a5c: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a64:
	/* 0x1a64: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a67:
	/* 0x1a67: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_1a6d:
	/* 0x1a6d: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a72:
	/* 0x1a72: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a75:
	/* 0x1a75: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_1a7b:
	/* 0x1a7b: jmp    5aa7 <generic_sleepable_preload+0x5aa7> */
	return 23207ULL;
x86_l_1a80:
	/* 0x1a80: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1a83:
	/* 0x1a83: jg     3fea <generic_sleepable_preload+0x3fea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16362ULL;
	}
x86_l_1a89:
	/* 0x1a89: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a91:
	/* 0x1a91: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1a94:
	/* 0x1a94: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16565ULL;
	}
x86_l_1a9a:
	/* 0x1a9a: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a9f:
	/* 0x1a9f: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1aa2:
	/* 0x1aa2: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16565ULL;
	}
x86_l_1aa8:
	/* 0x1aa8: jmp    40c8 <generic_sleepable_preload+0x40c8> */
	return 16584ULL;
x86_l_1aad:
	/* 0x1aad: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1ab0:
	/* 0x1ab0: jg     400e <generic_sleepable_preload+0x400e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16398ULL;
	}
x86_l_1ab6:
	/* 0x1ab6: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1abe:
	/* 0x1abe: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1ac1:
	/* 0x1ac1: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_1ac7:
	/* 0x1ac7: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1acc:
	/* 0x1acc: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1acf:
	/* 0x1acf: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_1ad5:
	/* 0x1ad5: jmp    5457 <generic_sleepable_preload+0x5457> */
	return 21591ULL;
x86_l_1ada:
	/* 0x1ada: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1add:
	/* 0x1add: jg     4032 <generic_sleepable_preload+0x4032> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16434ULL;
	}
x86_l_1ae3:
	/* 0x1ae3: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1aeb:
	/* 0x1aeb: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1aee:
	/* 0x1aee: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_1af4:
	/* 0x1af4: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1af9:
	/* 0x1af9: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1afc:
	/* 0x1afc: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_1b02:
	/* 0x1b02: jmp    4738 <generic_sleepable_preload+0x4738> */
	return 18232ULL;
x86_l_1b07:
	/* 0x1b07: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b0a:
	/* 0x1b0a: jg     4056 <generic_sleepable_preload+0x4056> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16470ULL;
	}
x86_l_1b10:
	/* 0x1b10: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b18:
	/* 0x1b18: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b1b:
	/* 0x1b1b: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_1b21:
	/* 0x1b21: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b26:
	/* 0x1b26: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b29:
	/* 0x1b29: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_1b2f:
	/* 0x1b2f: jmp    4d9f <generic_sleepable_preload+0x4d9f> */
	return 19871ULL;
x86_l_1b34:
	/* 0x1b34: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b37:
	/* 0x1b37: jg     407a <generic_sleepable_preload+0x407a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16506ULL;
	}
x86_l_1b3d:
	/* 0x1b3d: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b45:
	/* 0x1b45: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b48:
	/* 0x1b48: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_1b4e:
	/* 0x1b4e: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b53:
	/* 0x1b53: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b56:
	/* 0x1b56: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_1b5c:
	/* 0x1b5c: jmp    5aa7 <generic_sleepable_preload+0x5aa7> */
	return 23207ULL;
x86_l_1b61:
	/* 0x1b61: mov    rax,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_1b68:
	/* 0x1b68: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b6d:
	/* 0x1b6d: movzx  eax,BYTE PTR [r13+0x210] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 528ULL);
x86_l_1b75:
	/* 0x1b75: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1b7c:
	/* 0x1b7c: cmp    BYTE PTR [r13+0x212],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2276332666880ULL);
x86_l_1b84:
	/* 0x1b84: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1b89:
	/* 0x1b89: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1b8e:
	/* 0x1b8e: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1b92:
	/* 0x1b92: jmp    1cd7 <generic_sleepable_preload+0x1cd7> */
	return 7383ULL;
x86_l_1b97:
	/* 0x1b97: mov    rax,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_1b9e:
	/* 0x1b9e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ba3:
	/* 0x1ba3: movzx  eax,BYTE PTR [r13+0x228] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 552ULL);
x86_l_1bab:
	/* 0x1bab: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1bb2:
	/* 0x1bb2: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bb7:
	/* 0x1bb7: cmp    BYTE PTR [r13+0x22a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2379411881984ULL);
x86_l_1bbf:
	/* 0x1bbf: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1bc4:
	/* 0x1bc4: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1bc9:
	/* 0x1bc9: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1bcd:
	/* 0x1bcd: jmp    23a0 <generic_sleepable_preload+0x23a0> */
	return 9120ULL;
x86_l_1bd2:
	/* 0x1bd2: mov    rax,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_1bd9:
	/* 0x1bd9: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bde:
	/* 0x1bde: movzx  eax,BYTE PTR [r13+0x240] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 576ULL);
x86_l_1be6:
	/* 0x1be6: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1bed:
	/* 0x1bed: cmp    BYTE PTR [r13+0x242],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2482491097088ULL);
x86_l_1bf5:
	/* 0x1bf5: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1bfa:
	/* 0x1bfa: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1bff:
	/* 0x1bff: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1c03:
	/* 0x1c03: jmp    2a75 <generic_sleepable_preload+0x2a75> */
	return 10869ULL;
x86_l_1c08:
	/* 0x1c08: mov    rax,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_1c0f:
	/* 0x1c0f: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c14:
	/* 0x1c14: movzx  eax,BYTE PTR [r13+0x258] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 600ULL);
x86_l_1c1c:
	/* 0x1c1c: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1c23:
	/* 0x1c23: cmp    BYTE PTR [r13+0x25a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2585570312192ULL);
x86_l_1c2b:
	/* 0x1c2b: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1c30:
	/* 0x1c30: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1c35:
	/* 0x1c35: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1c39:
	/* 0x1c39: jmp    3159 <generic_sleepable_preload+0x3159> */
	return 12633ULL;
x86_l_1c3e:
	/* 0x1c3e: mov    rax,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_1c45:
	/* 0x1c45: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c4a:
	/* 0x1c4a: movzx  eax,BYTE PTR [r13+0x270] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 624ULL);
x86_l_1c52:
	/* 0x1c52: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1c59:
	/* 0x1c59: cmp    BYTE PTR [r13+0x272],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2688649527296ULL);
	return 7265ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7265ULL: goto x86_l_1c61;
	case 7270ULL: goto x86_l_1c66;
	case 7275ULL: goto x86_l_1c6b;
	case 7279ULL: goto x86_l_1c6f;
	case 7284ULL: goto x86_l_1c74;
	case 7291ULL: goto x86_l_1c7b;
	case 7297ULL: goto x86_l_1c81;
	case 7300ULL: goto x86_l_1c84;
	case 7305ULL: goto x86_l_1c89;
	case 7310ULL: goto x86_l_1c8e;
	case 7315ULL: goto x86_l_1c93;
	case 7320ULL: goto x86_l_1c98;
	case 7322ULL: goto x86_l_1c9a;
	case 7324ULL: goto x86_l_1c9c;
	case 7326ULL: goto x86_l_1c9e;
	case 7331ULL: goto x86_l_1ca3;
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7348ULL: goto x86_l_1cb4;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7365ULL: goto x86_l_1cc5;
	case 7370ULL: goto x86_l_1cca;
	case 7372ULL: goto x86_l_1ccc;
	case 7374ULL: goto x86_l_1cce;
	case 7380ULL: goto x86_l_1cd4;
	case 7383ULL: goto x86_l_1cd7;
	case 7388ULL: goto x86_l_1cdc;
	case 7390ULL: goto x86_l_1cde;
	case 7393ULL: goto x86_l_1ce1;
	case 7399ULL: goto x86_l_1ce7;
	case 7405ULL: goto x86_l_1ced;
	case 7412ULL: goto x86_l_1cf4;
	case 7415ULL: goto x86_l_1cf7;
	case 7419ULL: goto x86_l_1cfb;
	case 7422ULL: goto x86_l_1cfe;
	case 7427ULL: goto x86_l_1d03;
	case 7432ULL: goto x86_l_1d08;
	case 7434ULL: goto x86_l_1d0a;
	case 7440ULL: goto x86_l_1d10;
	case 7443ULL: goto x86_l_1d13;
	case 7445ULL: goto x86_l_1d15;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7460ULL: goto x86_l_1d24;
	case 7465ULL: goto x86_l_1d29;
	case 7470ULL: goto x86_l_1d2e;
	case 7472ULL: goto x86_l_1d30;
	case 7474ULL: goto x86_l_1d32;
	case 7480ULL: goto x86_l_1d38;
	case 7486ULL: goto x86_l_1d3e;
	case 7492ULL: goto x86_l_1d44;
	case 7496ULL: goto x86_l_1d48;
	case 7501ULL: goto x86_l_1d4d;
	case 7506ULL: goto x86_l_1d52;
	case 7512ULL: goto x86_l_1d58;
	case 7514ULL: goto x86_l_1d5a;
	case 7519ULL: goto x86_l_1d5f;
	case 7524ULL: goto x86_l_1d64;
	case 7529ULL: goto x86_l_1d69;
	case 7534ULL: goto x86_l_1d6e;
	case 7539ULL: goto x86_l_1d73;
	case 7541ULL: goto x86_l_1d75;
	case 7543ULL: goto x86_l_1d77;
	case 7549ULL: goto x86_l_1d7d;
	case 7558ULL: goto x86_l_1d86;
	case 7564ULL: goto x86_l_1d8c;
	case 7571ULL: goto x86_l_1d93;
	case 7576ULL: goto x86_l_1d98;
	case 7581ULL: goto x86_l_1d9d;
	case 7590ULL: goto x86_l_1da6;
	case 7592ULL: goto x86_l_1da8;
	case 7597ULL: goto x86_l_1dad;
	case 7602ULL: goto x86_l_1db2;
	case 7607ULL: goto x86_l_1db7;
	case 7612ULL: goto x86_l_1dbc;
	case 7617ULL: goto x86_l_1dc1;
	case 7619ULL: goto x86_l_1dc3;
	case 7621ULL: goto x86_l_1dc5;
	case 7627ULL: goto x86_l_1dcb;
	case 7636ULL: goto x86_l_1dd4;
	case 7642ULL: goto x86_l_1dda;
	case 7649ULL: goto x86_l_1de1;
	case 7654ULL: goto x86_l_1de6;
	case 7659ULL: goto x86_l_1deb;
	case 7668ULL: goto x86_l_1df4;
	case 7670ULL: goto x86_l_1df6;
	case 7675ULL: goto x86_l_1dfb;
	case 7680ULL: goto x86_l_1e00;
	case 7685ULL: goto x86_l_1e05;
	case 7690ULL: goto x86_l_1e0a;
	case 7695ULL: goto x86_l_1e0f;
	case 7697ULL: goto x86_l_1e11;
	case 7699ULL: goto x86_l_1e13;
	case 7705ULL: goto x86_l_1e19;
	case 7714ULL: goto x86_l_1e22;
	case 7720ULL: goto x86_l_1e28;
	case 7727ULL: goto x86_l_1e2f;
	case 7732ULL: goto x86_l_1e34;
	case 7737ULL: goto x86_l_1e39;
	case 7746ULL: goto x86_l_1e42;
	case 7748ULL: goto x86_l_1e44;
	case 7753ULL: goto x86_l_1e49;
	case 7758ULL: goto x86_l_1e4e;
	case 7763ULL: goto x86_l_1e53;
	case 7768ULL: goto x86_l_1e58;
	case 7773ULL: goto x86_l_1e5d;
	case 7775ULL: goto x86_l_1e5f;
	case 7777ULL: goto x86_l_1e61;
	case 7783ULL: goto x86_l_1e67;
	case 7792ULL: goto x86_l_1e70;
	case 7798ULL: goto x86_l_1e76;
	case 7805ULL: goto x86_l_1e7d;
	case 7810ULL: goto x86_l_1e82;
	case 7815ULL: goto x86_l_1e87;
	case 7824ULL: goto x86_l_1e90;
	case 7826ULL: goto x86_l_1e92;
	case 7831ULL: goto x86_l_1e97;
	case 7836ULL: goto x86_l_1e9c;
	case 7841ULL: goto x86_l_1ea1;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7853ULL: goto x86_l_1ead;
	case 7855ULL: goto x86_l_1eaf;
	case 7861ULL: goto x86_l_1eb5;
	case 7870ULL: goto x86_l_1ebe;
	case 7876ULL: goto x86_l_1ec4;
	case 7883ULL: goto x86_l_1ecb;
	case 7888ULL: goto x86_l_1ed0;
	case 7893ULL: goto x86_l_1ed5;
	case 7902ULL: goto x86_l_1ede;
	case 7904ULL: goto x86_l_1ee0;
	case 7909ULL: goto x86_l_1ee5;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7924ULL: goto x86_l_1ef4;
	case 7929ULL: goto x86_l_1ef9;
	case 7931ULL: goto x86_l_1efb;
	case 7933ULL: goto x86_l_1efd;
	case 7939ULL: goto x86_l_1f03;
	case 7948ULL: goto x86_l_1f0c;
	case 7954ULL: goto x86_l_1f12;
	case 7961ULL: goto x86_l_1f19;
	case 7966ULL: goto x86_l_1f1e;
	case 7971ULL: goto x86_l_1f23;
	case 7980ULL: goto x86_l_1f2c;
	case 7982ULL: goto x86_l_1f2e;
	case 7987ULL: goto x86_l_1f33;
	case 7992ULL: goto x86_l_1f38;
	case 7997ULL: goto x86_l_1f3d;
	case 8002ULL: goto x86_l_1f42;
	case 8007ULL: goto x86_l_1f47;
	case 8009ULL: goto x86_l_1f49;
	case 8011ULL: goto x86_l_1f4b;
	case 8017ULL: goto x86_l_1f51;
	case 8026ULL: goto x86_l_1f5a;
	case 8032ULL: goto x86_l_1f60;
	case 8039ULL: goto x86_l_1f67;
	case 8044ULL: goto x86_l_1f6c;
	case 8049ULL: goto x86_l_1f71;
	case 8058ULL: goto x86_l_1f7a;
	case 8060ULL: goto x86_l_1f7c;
	case 8065ULL: goto x86_l_1f81;
	case 8070ULL: goto x86_l_1f86;
	case 8075ULL: goto x86_l_1f8b;
	case 8080ULL: goto x86_l_1f90;
	case 8085ULL: goto x86_l_1f95;
	case 8087ULL: goto x86_l_1f97;
	case 8089ULL: goto x86_l_1f99;
	case 8095ULL: goto x86_l_1f9f;
	case 8100ULL: goto x86_l_1fa4;
	case 8109ULL: goto x86_l_1fad;
	case 8114ULL: goto x86_l_1fb2;
	case 8120ULL: goto x86_l_1fb8;
	case 8127ULL: goto x86_l_1fbf;
	case 8132ULL: goto x86_l_1fc4;
	case 8137ULL: goto x86_l_1fc9;
	case 8146ULL: goto x86_l_1fd2;
	case 8152ULL: goto x86_l_1fd8;
	case 8157ULL: goto x86_l_1fdd;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8172ULL: goto x86_l_1fec;
	case 8175ULL: goto x86_l_1fef;
	case 8177ULL: goto x86_l_1ff1;
	case 8182ULL: goto x86_l_1ff6;
	case 8187ULL: goto x86_l_1ffb;
	case 8192ULL: goto x86_l_2000;
	case 8197ULL: goto x86_l_2005;
	case 8202ULL: goto x86_l_200a;
	case 8204ULL: goto x86_l_200c;
	case 8206ULL: goto x86_l_200e;
	case 8212ULL: goto x86_l_2014;
	case 8218ULL: goto x86_l_201a;
	case 8224ULL: goto x86_l_2020;
	case 8228ULL: goto x86_l_2024;
	case 8233ULL: goto x86_l_2029;
	case 8238ULL: goto x86_l_202e;
	case 8244ULL: goto x86_l_2034;
	case 8246ULL: goto x86_l_2036;
	case 8251ULL: goto x86_l_203b;
	case 8256ULL: goto x86_l_2040;
	case 8261ULL: goto x86_l_2045;
	case 8266ULL: goto x86_l_204a;
	case 8271ULL: goto x86_l_204f;
	case 8273ULL: goto x86_l_2051;
	case 8275ULL: goto x86_l_2053;
	case 8281ULL: goto x86_l_2059;
	case 8290ULL: goto x86_l_2062;
	case 8296ULL: goto x86_l_2068;
	case 8303ULL: goto x86_l_206f;
	case 8308ULL: goto x86_l_2074;
	case 8313ULL: goto x86_l_2079;
	case 8322ULL: goto x86_l_2082;
	case 8324ULL: goto x86_l_2084;
	case 8329ULL: goto x86_l_2089;
	case 8334ULL: goto x86_l_208e;
	case 8339ULL: goto x86_l_2093;
	case 8344ULL: goto x86_l_2098;
	case 8349ULL: goto x86_l_209d;
	case 8351ULL: goto x86_l_209f;
	case 8353ULL: goto x86_l_20a1;
	case 8359ULL: goto x86_l_20a7;
	case 8368ULL: goto x86_l_20b0;
	case 8374ULL: goto x86_l_20b6;
	case 8381ULL: goto x86_l_20bd;
	case 8386ULL: goto x86_l_20c2;
	case 8391ULL: goto x86_l_20c7;
	case 8400ULL: goto x86_l_20d0;
	case 8402ULL: goto x86_l_20d2;
	case 8407ULL: goto x86_l_20d7;
	case 8412ULL: goto x86_l_20dc;
	case 8417ULL: goto x86_l_20e1;
	case 8422ULL: goto x86_l_20e6;
	case 8427ULL: goto x86_l_20eb;
	case 8429ULL: goto x86_l_20ed;
	case 8431ULL: goto x86_l_20ef;
	case 8437ULL: goto x86_l_20f5;
	case 8446ULL: goto x86_l_20fe;
	case 8452ULL: goto x86_l_2104;
	case 8459ULL: goto x86_l_210b;
	case 8464ULL: goto x86_l_2110;
	case 8469ULL: goto x86_l_2115;
	case 8478ULL: goto x86_l_211e;
	case 8480ULL: goto x86_l_2120;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8495ULL: goto x86_l_212f;
	case 8500ULL: goto x86_l_2134;
	case 8505ULL: goto x86_l_2139;
	case 8507ULL: goto x86_l_213b;
	case 8509ULL: goto x86_l_213d;
	case 8515ULL: goto x86_l_2143;
	case 8524ULL: goto x86_l_214c;
	case 8530ULL: goto x86_l_2152;
	case 8537ULL: goto x86_l_2159;
	case 8542ULL: goto x86_l_215e;
	case 8547ULL: goto x86_l_2163;
	case 8556ULL: goto x86_l_216c;
	case 8558ULL: goto x86_l_216e;
	case 8563ULL: goto x86_l_2173;
	case 8568ULL: goto x86_l_2178;
	case 8573ULL: goto x86_l_217d;
	case 8578ULL: goto x86_l_2182;
	case 8583ULL: goto x86_l_2187;
	case 8585ULL: goto x86_l_2189;
	case 8587ULL: goto x86_l_218b;
	case 8593ULL: goto x86_l_2191;
	case 8602ULL: goto x86_l_219a;
	case 8608ULL: goto x86_l_21a0;
	case 8615ULL: goto x86_l_21a7;
	case 8620ULL: goto x86_l_21ac;
	case 8625ULL: goto x86_l_21b1;
	case 8634ULL: goto x86_l_21ba;
	case 8636ULL: goto x86_l_21bc;
	case 8641ULL: goto x86_l_21c1;
	case 8646ULL: goto x86_l_21c6;
	case 8651ULL: goto x86_l_21cb;
	case 8656ULL: goto x86_l_21d0;
	case 8661ULL: goto x86_l_21d5;
	case 8663ULL: goto x86_l_21d7;
	case 8665ULL: goto x86_l_21d9;
	case 8671ULL: goto x86_l_21df;
	case 8680ULL: goto x86_l_21e8;
	case 8686ULL: goto x86_l_21ee;
	case 8693ULL: goto x86_l_21f5;
	case 8698ULL: goto x86_l_21fa;
	case 8703ULL: goto x86_l_21ff;
	case 8712ULL: goto x86_l_2208;
	case 8714ULL: goto x86_l_220a;
	case 8719ULL: goto x86_l_220f;
	case 8724ULL: goto x86_l_2214;
	case 8729ULL: goto x86_l_2219;
	case 8734ULL: goto x86_l_221e;
	case 8739ULL: goto x86_l_2223;
	case 8741ULL: goto x86_l_2225;
	case 8743ULL: goto x86_l_2227;
	case 8749ULL: goto x86_l_222d;
	case 8754ULL: goto x86_l_2232;
	case 8763ULL: goto x86_l_223b;
	case 8768ULL: goto x86_l_2240;
	case 8774ULL: goto x86_l_2246;
	case 8781ULL: goto x86_l_224d;
	case 8786ULL: goto x86_l_2252;
	case 8791ULL: goto x86_l_2257;
	case 8800ULL: goto x86_l_2260;
	case 8802ULL: goto x86_l_2262;
	case 8807ULL: goto x86_l_2267;
	case 8812ULL: goto x86_l_226c;
	case 8817ULL: goto x86_l_2271;
	case 8822ULL: goto x86_l_2276;
	case 8827ULL: goto x86_l_227b;
	case 8829ULL: goto x86_l_227d;
	case 8831ULL: goto x86_l_227f;
	case 8837ULL: goto x86_l_2285;
	case 8842ULL: goto x86_l_228a;
	case 8851ULL: goto x86_l_2293;
	case 8856ULL: goto x86_l_2298;
	case 8862ULL: goto x86_l_229e;
	case 8869ULL: goto x86_l_22a5;
	case 8874ULL: goto x86_l_22aa;
	case 8879ULL: goto x86_l_22af;
	case 8888ULL: goto x86_l_22b8;
	case 8894ULL: goto x86_l_22be;
	case 8899ULL: goto x86_l_22c3;
	case 8904ULL: goto x86_l_22c8;
	case 8909ULL: goto x86_l_22cd;
	case 8914ULL: goto x86_l_22d2;
	case 8919ULL: goto x86_l_22d7;
	case 8921ULL: goto x86_l_22d9;
	case 8923ULL: goto x86_l_22db;
	case 8929ULL: goto x86_l_22e1;
	case 8934ULL: goto x86_l_22e6;
	case 8939ULL: goto x86_l_22eb;
	case 8946ULL: goto x86_l_22f2;
	case 8952ULL: goto x86_l_22f8;
	case 8955ULL: goto x86_l_22fb;
	case 8960ULL: goto x86_l_2300;
	case 8965ULL: goto x86_l_2305;
	case 8970ULL: goto x86_l_230a;
	case 8975ULL: goto x86_l_230f;
	case 8977ULL: goto x86_l_2311;
	case 8979ULL: goto x86_l_2313;
	case 8985ULL: goto x86_l_2319;
	case 8992ULL: goto x86_l_2320;
	case 8998ULL: goto x86_l_2326;
	case 9001ULL: goto x86_l_2329;
	case 9006ULL: goto x86_l_232e;
	case 9011ULL: goto x86_l_2333;
	case 9016ULL: goto x86_l_2338;
	case 9021ULL: goto x86_l_233d;
	case 9023ULL: goto x86_l_233f;
	case 9025ULL: goto x86_l_2341;
	case 9027ULL: goto x86_l_2343;
	case 9035ULL: goto x86_l_234b;
	case 9042ULL: goto x86_l_2352;
	case 9049ULL: goto x86_l_2359;
	case 9054ULL: goto x86_l_235e;
	case 9057ULL: goto x86_l_2361;
	case 9062ULL: goto x86_l_2366;
	case 9067ULL: goto x86_l_236b;
	case 9072ULL: goto x86_l_2370;
	case 9080ULL: goto x86_l_2378;
	case 9087ULL: goto x86_l_237f;
	case 9094ULL: goto x86_l_2386;
	case 9099ULL: goto x86_l_238b;
	case 9102ULL: goto x86_l_238e;
	case 9107ULL: goto x86_l_2393;
	case 9109ULL: goto x86_l_2395;
	case 9111ULL: goto x86_l_2397;
	case 9117ULL: goto x86_l_239d;
	case 9120ULL: goto x86_l_23a0;
	case 9125ULL: goto x86_l_23a5;
	case 9127ULL: goto x86_l_23a7;
	case 9130ULL: goto x86_l_23aa;
	case 9139ULL: goto x86_l_23b3;
	case 9145ULL: goto x86_l_23b9;
	case 9152ULL: goto x86_l_23c0;
	case 9155ULL: goto x86_l_23c3;
	case 9162ULL: goto x86_l_23ca;
	case 9165ULL: goto x86_l_23cd;
	case 9170ULL: goto x86_l_23d2;
	case 9178ULL: goto x86_l_23da;
	case 9180ULL: goto x86_l_23dc;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c61:
	/* 0x1c61: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1c66:
	/* 0x1c66: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1c6b:
	/* 0x1c6b: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1c6f:
	/* 0x1c6f: jmp    3830 <generic_sleepable_preload+0x3830> */
	return 14384ULL;
x86_l_1c74:
	/* 0x1c74: mov    edx,DWORD PTR [r13+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1c7b:
	/* 0x1c7b: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c81:
	/* 0x1c81: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c84:
	/* 0x1c84: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c89:
	/* 0x1c89: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c8e:
	/* 0x1c8e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c93:
	/* 0x1c93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c98:
	/* 0x1c98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9a:
	/* 0x1c9a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c9c:
	/* 0x1c9c: jne    1cd4 <generic_sleepable_preload+0x1cd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1cd4;
	}
x86_l_1c9e:
	/* 0x1c9e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ca3:
	/* 0x1ca3: add    rcx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_1caa:
	/* 0x1caa: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1caf:
	/* 0x1caf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1cb4:
	/* 0x1cb4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1cb9:
	/* 0x1cb9: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cbe:
	/* 0x1cbe: add    rdx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_1cc5:
	/* 0x1cc5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cca:
	/* 0x1cca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ccc:
	/* 0x1ccc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cce:
	/* 0x1cce: je     1b6d <generic_sleepable_preload+0x1b6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7021ULL;
	}
x86_l_1cd4:
	/* 0x1cd4: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1cd7:
	/* 0x1cd7: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cdc:
	/* 0x1cdc: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cde:
	/* 0x1cde: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_1ce1:
	/* 0x1ce1: cmp    WORD PTR [r13+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1ce7:
	/* 0x1ce7: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_1ced:
	/* 0x1ced: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1cf4:
	/* 0x1cf4: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1cf7:
	/* 0x1cf7: mov    eax,DWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1cfb:
	/* 0x1cfb: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1cfe:
	/* 0x1cfe: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d03:
	/* 0x1d03: movzx  eax,WORD PTR [r13+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_1d08:
	/* 0x1d08: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1d0a:
	/* 0x1d0a: je     1fec <generic_sleepable_preload+0x1fec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fec;
	}
x86_l_1d10:
	/* 0x1d10: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1d13:
	/* 0x1d13: je     1d38 <generic_sleepable_preload+0x1d38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d38;
	}
x86_l_1d15:
	/* 0x1d15: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d1a:
	/* 0x1d1a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d1f:
	/* 0x1d1f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d24:
	/* 0x1d24: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d29:
	/* 0x1d29: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d2e:
	/* 0x1d2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d30:
	/* 0x1d30: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d32:
	/* 0x1d32: js     3e50 <generic_sleepable_preload+0x3e50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15952ULL;
	}
x86_l_1d38:
	/* 0x1d38: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1d3e:
	/* 0x1d3e: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_1d44:
	/* 0x1d44: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1d48:
	/* 0x1d48: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1d4d:
	/* 0x1d4d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d52:
	/* 0x1d52: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1d58:
	/* 0x1d58: je     1d7d <generic_sleepable_preload+0x1d7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d7d;
	}
x86_l_1d5a:
	/* 0x1d5a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d5f:
	/* 0x1d5f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d64:
	/* 0x1d64: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d69:
	/* 0x1d69: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d6e:
	/* 0x1d6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d73:
	/* 0x1d73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d75:
	/* 0x1d75: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d77:
	/* 0x1d77: js     53f1 <generic_sleepable_preload+0x53f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21489ULL;
	}
x86_l_1d7d:
	/* 0x1d7d: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1d86:
	/* 0x1d86: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_1d8c:
	/* 0x1d8c: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1d93:
	/* 0x1d93: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1d98:
	/* 0x1d98: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d9d:
	/* 0x1d9d: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1da6:
	/* 0x1da6: je     1dcb <generic_sleepable_preload+0x1dcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dcb;
	}
x86_l_1da8:
	/* 0x1da8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dad:
	/* 0x1dad: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1db2:
	/* 0x1db2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1db7:
	/* 0x1db7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dbc:
	/* 0x1dbc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dc1:
	/* 0x1dc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc3:
	/* 0x1dc3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dc5:
	/* 0x1dc5: js     60d8 <generic_sleepable_preload+0x60d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24792ULL;
	}
x86_l_1dcb:
	/* 0x1dcb: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1dd4:
	/* 0x1dd4: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_1dda:
	/* 0x1dda: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1de1:
	/* 0x1de1: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1de6:
	/* 0x1de6: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1deb:
	/* 0x1deb: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1df4:
	/* 0x1df4: je     1e19 <generic_sleepable_preload+0x1e19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e19;
	}
x86_l_1df6:
	/* 0x1df6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dfb:
	/* 0x1dfb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e00:
	/* 0x1e00: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e05:
	/* 0x1e05: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e0a:
	/* 0x1e0a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e0f:
	/* 0x1e0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e11:
	/* 0x1e11: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e13:
	/* 0x1e13: js     613c <generic_sleepable_preload+0x613c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24892ULL;
	}
x86_l_1e19:
	/* 0x1e19: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1e22:
	/* 0x1e22: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_1e28:
	/* 0x1e28: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1e2f:
	/* 0x1e2f: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1e34:
	/* 0x1e34: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e39:
	/* 0x1e39: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1e42:
	/* 0x1e42: je     1e67 <generic_sleepable_preload+0x1e67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e67;
	}
x86_l_1e44:
	/* 0x1e44: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e49:
	/* 0x1e49: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e4e:
	/* 0x1e4e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e53:
	/* 0x1e53: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e58:
	/* 0x1e58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e5d:
	/* 0x1e5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5f:
	/* 0x1e5f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e61:
	/* 0x1e61: js     61a0 <generic_sleepable_preload+0x61a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24992ULL;
	}
x86_l_1e67:
	/* 0x1e67: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1e70:
	/* 0x1e70: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_1e76:
	/* 0x1e76: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1e7d:
	/* 0x1e7d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1e82:
	/* 0x1e82: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e87:
	/* 0x1e87: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1e90:
	/* 0x1e90: je     1eb5 <generic_sleepable_preload+0x1eb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eb5;
	}
x86_l_1e92:
	/* 0x1e92: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e97:
	/* 0x1e97: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e9c:
	/* 0x1e9c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ea1:
	/* 0x1ea1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ea6:
	/* 0x1ea6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eab:
	/* 0x1eab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ead:
	/* 0x1ead: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1eaf:
	/* 0x1eaf: js     6204 <generic_sleepable_preload+0x6204> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25092ULL;
	}
x86_l_1eb5:
	/* 0x1eb5: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1ebe:
	/* 0x1ebe: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_1ec4:
	/* 0x1ec4: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ecb:
	/* 0x1ecb: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1ed0:
	/* 0x1ed0: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ed5:
	/* 0x1ed5: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1ede:
	/* 0x1ede: je     1f03 <generic_sleepable_preload+0x1f03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f03;
	}
x86_l_1ee0:
	/* 0x1ee0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ee5:
	/* 0x1ee5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1eea:
	/* 0x1eea: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1eef:
	/* 0x1eef: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ef4:
	/* 0x1ef4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ef9:
	/* 0x1ef9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1efb:
	/* 0x1efb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1efd:
	/* 0x1efd: js     6265 <generic_sleepable_preload+0x6265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25189ULL;
	}
x86_l_1f03:
	/* 0x1f03: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1f0c:
	/* 0x1f0c: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_1f12:
	/* 0x1f12: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1f19:
	/* 0x1f19: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1f1e:
	/* 0x1f1e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f23:
	/* 0x1f23: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1f2c:
	/* 0x1f2c: je     1f51 <generic_sleepable_preload+0x1f51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f51;
	}
x86_l_1f2e:
	/* 0x1f2e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f33:
	/* 0x1f33: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f38:
	/* 0x1f38: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f3d:
	/* 0x1f3d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f42:
	/* 0x1f42: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f47:
	/* 0x1f47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f49:
	/* 0x1f49: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f4b:
	/* 0x1f4b: js     68b5 <generic_sleepable_preload+0x68b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26805ULL;
	}
x86_l_1f51:
	/* 0x1f51: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1f5a:
	/* 0x1f5a: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_1f60:
	/* 0x1f60: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1f67:
	/* 0x1f67: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1f6c:
	/* 0x1f6c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f71:
	/* 0x1f71: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1f7a:
	/* 0x1f7a: je     1f9f <generic_sleepable_preload+0x1f9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f9f;
	}
x86_l_1f7c:
	/* 0x1f7c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f81:
	/* 0x1f81: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f86:
	/* 0x1f86: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f8b:
	/* 0x1f8b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f90:
	/* 0x1f90: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f95:
	/* 0x1f95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f97:
	/* 0x1f97: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f99:
	/* 0x1f99: js     6922 <generic_sleepable_preload+0x6922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26914ULL;
	}
x86_l_1f9f:
	/* 0x1f9f: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1fa4:
	/* 0x1fa4: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1fad:
	/* 0x1fad: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fb2:
	/* 0x1fb2: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_1fb8:
	/* 0x1fb8: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1fbf:
	/* 0x1fbf: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1fc4:
	/* 0x1fc4: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fc9:
	/* 0x1fc9: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1fd2:
	/* 0x1fd2: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_1fd8:
	/* 0x1fd8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fdd:
	/* 0x1fdd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1fe2:
	/* 0x1fe2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1fe7:
	/* 0x1fe7: jmp    22cd <generic_sleepable_preload+0x22cd> */
	goto x86_l_22cd;
x86_l_1fec:
	/* 0x1fec: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1fef:
	/* 0x1fef: je     2014 <generic_sleepable_preload+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2014;
	}
x86_l_1ff1:
	/* 0x1ff1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ff6:
	/* 0x1ff6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ffb:
	/* 0x1ffb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2000:
	/* 0x2000: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2005:
	/* 0x2005: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_200a:
	/* 0x200a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_200c:
	/* 0x200c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_200e:
	/* 0x200e: js     3e50 <generic_sleepable_preload+0x3e50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15952ULL;
	}
x86_l_2014:
	/* 0x2014: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_201a:
	/* 0x201a: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_2020:
	/* 0x2020: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2024:
	/* 0x2024: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2029:
	/* 0x2029: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_202e:
	/* 0x202e: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_2034:
	/* 0x2034: je     2059 <generic_sleepable_preload+0x2059> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2059;
	}
x86_l_2036:
	/* 0x2036: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_203b:
	/* 0x203b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2040:
	/* 0x2040: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2045:
	/* 0x2045: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_204a:
	/* 0x204a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_204f:
	/* 0x204f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2051:
	/* 0x2051: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2053:
	/* 0x2053: js     53f1 <generic_sleepable_preload+0x53f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21489ULL;
	}
x86_l_2059:
	/* 0x2059: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_2062:
	/* 0x2062: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_2068:
	/* 0x2068: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_206f:
	/* 0x206f: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2074:
	/* 0x2074: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2079:
	/* 0x2079: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_2082:
	/* 0x2082: je     20a7 <generic_sleepable_preload+0x20a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20a7;
	}
x86_l_2084:
	/* 0x2084: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2089:
	/* 0x2089: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_208e:
	/* 0x208e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2093:
	/* 0x2093: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2098:
	/* 0x2098: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_209d:
	/* 0x209d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_209f:
	/* 0x209f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20a1:
	/* 0x20a1: js     60d8 <generic_sleepable_preload+0x60d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24792ULL;
	}
x86_l_20a7:
	/* 0x20a7: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_20b0:
	/* 0x20b0: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_20b6:
	/* 0x20b6: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_20bd:
	/* 0x20bd: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_20c2:
	/* 0x20c2: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20c7:
	/* 0x20c7: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_20d0:
	/* 0x20d0: je     20f5 <generic_sleepable_preload+0x20f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f5;
	}
x86_l_20d2:
	/* 0x20d2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20d7:
	/* 0x20d7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20dc:
	/* 0x20dc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20e1:
	/* 0x20e1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20e6:
	/* 0x20e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20eb:
	/* 0x20eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ed:
	/* 0x20ed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20ef:
	/* 0x20ef: js     613c <generic_sleepable_preload+0x613c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24892ULL;
	}
x86_l_20f5:
	/* 0x20f5: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_20fe:
	/* 0x20fe: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_2104:
	/* 0x2104: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_210b:
	/* 0x210b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2110:
	/* 0x2110: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2115:
	/* 0x2115: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_211e:
	/* 0x211e: je     2143 <generic_sleepable_preload+0x2143> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2143;
	}
x86_l_2120:
	/* 0x2120: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2125:
	/* 0x2125: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_212a:
	/* 0x212a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_212f:
	/* 0x212f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2134:
	/* 0x2134: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2139:
	/* 0x2139: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_213b:
	/* 0x213b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_213d:
	/* 0x213d: js     61a0 <generic_sleepable_preload+0x61a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24992ULL;
	}
x86_l_2143:
	/* 0x2143: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_214c:
	/* 0x214c: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_2152:
	/* 0x2152: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2159:
	/* 0x2159: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_215e:
	/* 0x215e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2163:
	/* 0x2163: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_216c:
	/* 0x216c: je     2191 <generic_sleepable_preload+0x2191> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2191;
	}
x86_l_216e:
	/* 0x216e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2173:
	/* 0x2173: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2178:
	/* 0x2178: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_217d:
	/* 0x217d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2182:
	/* 0x2182: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2187:
	/* 0x2187: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2189:
	/* 0x2189: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_218b:
	/* 0x218b: js     6204 <generic_sleepable_preload+0x6204> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25092ULL;
	}
x86_l_2191:
	/* 0x2191: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_219a:
	/* 0x219a: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_21a0:
	/* 0x21a0: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_21a7:
	/* 0x21a7: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_21ac:
	/* 0x21ac: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21b1:
	/* 0x21b1: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_21ba:
	/* 0x21ba: je     21df <generic_sleepable_preload+0x21df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21df;
	}
x86_l_21bc:
	/* 0x21bc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21c1:
	/* 0x21c1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21c6:
	/* 0x21c6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21cb:
	/* 0x21cb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21d0:
	/* 0x21d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21d5:
	/* 0x21d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d7:
	/* 0x21d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21d9:
	/* 0x21d9: js     6265 <generic_sleepable_preload+0x6265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25189ULL;
	}
x86_l_21df:
	/* 0x21df: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_21e8:
	/* 0x21e8: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_21ee:
	/* 0x21ee: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_21f5:
	/* 0x21f5: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_21fa:
	/* 0x21fa: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21ff:
	/* 0x21ff: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_2208:
	/* 0x2208: je     222d <generic_sleepable_preload+0x222d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_222d;
	}
x86_l_220a:
	/* 0x220a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_220f:
	/* 0x220f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2214:
	/* 0x2214: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2219:
	/* 0x2219: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_221e:
	/* 0x221e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2223:
	/* 0x2223: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2225:
	/* 0x2225: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2227:
	/* 0x2227: js     69b2 <generic_sleepable_preload+0x69b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27058ULL;
	}
x86_l_222d:
	/* 0x222d: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2232:
	/* 0x2232: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_223b:
	/* 0x223b: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2240:
	/* 0x2240: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_2246:
	/* 0x2246: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_224d:
	/* 0x224d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2252:
	/* 0x2252: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2257:
	/* 0x2257: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_2260:
	/* 0x2260: je     2285 <generic_sleepable_preload+0x2285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2285;
	}
x86_l_2262:
	/* 0x2262: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2267:
	/* 0x2267: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_226c:
	/* 0x226c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2271:
	/* 0x2271: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2276:
	/* 0x2276: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_227b:
	/* 0x227b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_227d:
	/* 0x227d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_227f:
	/* 0x227f: js     6922 <generic_sleepable_preload+0x6922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26914ULL;
	}
x86_l_2285:
	/* 0x2285: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_228a:
	/* 0x228a: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_2293:
	/* 0x2293: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2298:
	/* 0x2298: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_229e:
	/* 0x229e: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_22a5:
	/* 0x22a5: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_22aa:
	/* 0x22aa: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22af:
	/* 0x22af: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_22b8:
	/* 0x22b8: je     626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25196ULL;
	}
x86_l_22be:
	/* 0x22be: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22c3:
	/* 0x22c3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_22c8:
	/* 0x22c8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22cd:
	/* 0x22cd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22d2:
	/* 0x22d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22d7:
	/* 0x22d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d9:
	/* 0x22d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22db:
	/* 0x22db: jns    626c <generic_sleepable_preload+0x626c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25196ULL;
	}
x86_l_22e1:
	/* 0x22e1: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_22e6:
	/* 0x22e6: jmp    626a <generic_sleepable_preload+0x626a> */
	return 25194ULL;
x86_l_22eb:
	/* 0x22eb: mov    edx,DWORD PTR [r13+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_22f2:
	/* 0x22f2: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22f8:
	/* 0x22f8: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22fb:
	/* 0x22fb: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2300:
	/* 0x2300: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2305:
	/* 0x2305: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_230a:
	/* 0x230a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_230f:
	/* 0x230f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2311:
	/* 0x2311: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2313:
	/* 0x2313: jne    239d <generic_sleepable_preload+0x239d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_239d;
	}
x86_l_2319:
	/* 0x2319: mov    edx,DWORD PTR [r13+0x224] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 548ULL);
x86_l_2320:
	/* 0x2320: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2326:
	/* 0x2326: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2329:
	/* 0x2329: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_232e:
	/* 0x232e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2333:
	/* 0x2333: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2338:
	/* 0x2338: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_233d:
	/* 0x233d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_233f:
	/* 0x233f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2341:
	/* 0x2341: jne    239d <generic_sleepable_preload+0x239d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_239d;
	}
x86_l_2343:
	/* 0x2343: movzx  eax,BYTE PTR [r13+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_234b:
	/* 0x234b: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2352:
	/* 0x2352: mov    rcx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_2359:
	/* 0x2359: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_235e:
	/* 0x235e: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2361:
	/* 0x2361: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2366:
	/* 0x2366: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_236b:
	/* 0x236b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2370:
	/* 0x2370: movzx  ecx,BYTE PTR [r13+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_2378:
	/* 0x2378: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_237f:
	/* 0x237f: mov    rdx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_2386:
	/* 0x2386: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_238b:
	/* 0x238b: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_238e:
	/* 0x238e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2393:
	/* 0x2393: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2395:
	/* 0x2395: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2397:
	/* 0x2397: je     1ba3 <generic_sleepable_preload+0x1ba3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7075ULL;
	}
x86_l_239d:
	/* 0x239d: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_23a0:
	/* 0x23a0: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23a5:
	/* 0x23a5: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23a7:
	/* 0x23a7: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_23aa:
	/* 0x23aa: cmp    WORD PTR [r13+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_23b3:
	/* 0x23b3: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_23b9:
	/* 0x23b9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_23c0:
	/* 0x23c0: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_23c3:
	/* 0x23c3: mov    eax,DWORD PTR [r13+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_23ca:
	/* 0x23ca: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23cd:
	/* 0x23cd: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23d2:
	/* 0x23d2: movzx  eax,WORD PTR [r13+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_23da:
	/* 0x23da: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_23dc:
	/* 0x23dc: je     26c2 <generic_sleepable_preload+0x26c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9922ULL;
	}
	return 9186ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9186ULL: goto x86_l_23e2;
	case 9189ULL: goto x86_l_23e5;
	case 9191ULL: goto x86_l_23e7;
	case 9196ULL: goto x86_l_23ec;
	case 9201ULL: goto x86_l_23f1;
	case 9206ULL: goto x86_l_23f6;
	case 9211ULL: goto x86_l_23fb;
	case 9216ULL: goto x86_l_2400;
	case 9218ULL: goto x86_l_2402;
	case 9220ULL: goto x86_l_2404;
	case 9226ULL: goto x86_l_240a;
	case 9235ULL: goto x86_l_2413;
	case 9241ULL: goto x86_l_2419;
	case 9248ULL: goto x86_l_2420;
	case 9253ULL: goto x86_l_2425;
	case 9258ULL: goto x86_l_242a;
	case 9267ULL: goto x86_l_2433;
	case 9269ULL: goto x86_l_2435;
	case 9274ULL: goto x86_l_243a;
	case 9279ULL: goto x86_l_243f;
	case 9284ULL: goto x86_l_2444;
	case 9289ULL: goto x86_l_2449;
	case 9294ULL: goto x86_l_244e;
	case 9296ULL: goto x86_l_2450;
	case 9298ULL: goto x86_l_2452;
	case 9304ULL: goto x86_l_2458;
	case 9313ULL: goto x86_l_2461;
	case 9319ULL: goto x86_l_2467;
	case 9326ULL: goto x86_l_246e;
	case 9331ULL: goto x86_l_2473;
	case 9336ULL: goto x86_l_2478;
	case 9345ULL: goto x86_l_2481;
	case 9347ULL: goto x86_l_2483;
	case 9352ULL: goto x86_l_2488;
	case 9357ULL: goto x86_l_248d;
	case 9362ULL: goto x86_l_2492;
	case 9367ULL: goto x86_l_2497;
	case 9372ULL: goto x86_l_249c;
	case 9374ULL: goto x86_l_249e;
	case 9376ULL: goto x86_l_24a0;
	case 9382ULL: goto x86_l_24a6;
	case 9391ULL: goto x86_l_24af;
	case 9397ULL: goto x86_l_24b5;
	case 9404ULL: goto x86_l_24bc;
	case 9409ULL: goto x86_l_24c1;
	case 9414ULL: goto x86_l_24c6;
	case 9423ULL: goto x86_l_24cf;
	case 9425ULL: goto x86_l_24d1;
	case 9430ULL: goto x86_l_24d6;
	case 9435ULL: goto x86_l_24db;
	case 9440ULL: goto x86_l_24e0;
	case 9445ULL: goto x86_l_24e5;
	case 9450ULL: goto x86_l_24ea;
	case 9452ULL: goto x86_l_24ec;
	case 9454ULL: goto x86_l_24ee;
	case 9460ULL: goto x86_l_24f4;
	case 9469ULL: goto x86_l_24fd;
	case 9475ULL: goto x86_l_2503;
	case 9482ULL: goto x86_l_250a;
	case 9487ULL: goto x86_l_250f;
	case 9492ULL: goto x86_l_2514;
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
	case 9547ULL: goto x86_l_254b;
	case 9553ULL: goto x86_l_2551;
	case 9560ULL: goto x86_l_2558;
	case 9565ULL: goto x86_l_255d;
	case 9570ULL: goto x86_l_2562;
	case 9579ULL: goto x86_l_256b;
	case 9581ULL: goto x86_l_256d;
	case 9586ULL: goto x86_l_2572;
	case 9591ULL: goto x86_l_2577;
	case 9596ULL: goto x86_l_257c;
	case 9601ULL: goto x86_l_2581;
	case 9606ULL: goto x86_l_2586;
	case 9608ULL: goto x86_l_2588;
	case 9610ULL: goto x86_l_258a;
	case 9616ULL: goto x86_l_2590;
	case 9625ULL: goto x86_l_2599;
	case 9631ULL: goto x86_l_259f;
	case 9638ULL: goto x86_l_25a6;
	case 9643ULL: goto x86_l_25ab;
	case 9648ULL: goto x86_l_25b0;
	case 9657ULL: goto x86_l_25b9;
	case 9659ULL: goto x86_l_25bb;
	case 9664ULL: goto x86_l_25c0;
	case 9669ULL: goto x86_l_25c5;
	case 9674ULL: goto x86_l_25ca;
	case 9679ULL: goto x86_l_25cf;
	case 9684ULL: goto x86_l_25d4;
	case 9686ULL: goto x86_l_25d6;
	case 9688ULL: goto x86_l_25d8;
	case 9694ULL: goto x86_l_25de;
	case 9703ULL: goto x86_l_25e7;
	case 9709ULL: goto x86_l_25ed;
	case 9716ULL: goto x86_l_25f4;
	case 9721ULL: goto x86_l_25f9;
	case 9726ULL: goto x86_l_25fe;
	case 9735ULL: goto x86_l_2607;
	case 9737ULL: goto x86_l_2609;
	case 9742ULL: goto x86_l_260e;
	case 9747ULL: goto x86_l_2613;
	case 9752ULL: goto x86_l_2618;
	case 9757ULL: goto x86_l_261d;
	case 9762ULL: goto x86_l_2622;
	case 9764ULL: goto x86_l_2624;
	case 9766ULL: goto x86_l_2626;
	case 9772ULL: goto x86_l_262c;
	case 9781ULL: goto x86_l_2635;
	case 9787ULL: goto x86_l_263b;
	case 9794ULL: goto x86_l_2642;
	case 9799ULL: goto x86_l_2647;
	case 9804ULL: goto x86_l_264c;
	case 9813ULL: goto x86_l_2655;
	case 9815ULL: goto x86_l_2657;
	case 9820ULL: goto x86_l_265c;
	case 9825ULL: goto x86_l_2661;
	case 9830ULL: goto x86_l_2666;
	case 9835ULL: goto x86_l_266b;
	case 9840ULL: goto x86_l_2670;
	case 9842ULL: goto x86_l_2672;
	case 9844ULL: goto x86_l_2674;
	case 9850ULL: goto x86_l_267a;
	case 9855ULL: goto x86_l_267f;
	case 9864ULL: goto x86_l_2688;
	case 9870ULL: goto x86_l_268e;
	case 9877ULL: goto x86_l_2695;
	case 9882ULL: goto x86_l_269a;
	case 9887ULL: goto x86_l_269f;
	case 9896ULL: goto x86_l_26a8;
	case 9902ULL: goto x86_l_26ae;
	case 9907ULL: goto x86_l_26b3;
	case 9912ULL: goto x86_l_26b8;
	case 9917ULL: goto x86_l_26bd;
	case 9922ULL: goto x86_l_26c2;
	case 9925ULL: goto x86_l_26c5;
	case 9927ULL: goto x86_l_26c7;
	case 9932ULL: goto x86_l_26cc;
	case 9937ULL: goto x86_l_26d1;
	case 9942ULL: goto x86_l_26d6;
	case 9947ULL: goto x86_l_26db;
	case 9952ULL: goto x86_l_26e0;
	case 9954ULL: goto x86_l_26e2;
	case 9956ULL: goto x86_l_26e4;
	case 9962ULL: goto x86_l_26ea;
	case 9971ULL: goto x86_l_26f3;
	case 9977ULL: goto x86_l_26f9;
	case 9984ULL: goto x86_l_2700;
	case 9989ULL: goto x86_l_2705;
	case 9994ULL: goto x86_l_270a;
	case 10003ULL: goto x86_l_2713;
	case 10005ULL: goto x86_l_2715;
	case 10010ULL: goto x86_l_271a;
	case 10015ULL: goto x86_l_271f;
	case 10020ULL: goto x86_l_2724;
	case 10025ULL: goto x86_l_2729;
	case 10030ULL: goto x86_l_272e;
	case 10032ULL: goto x86_l_2730;
	case 10034ULL: goto x86_l_2732;
	case 10040ULL: goto x86_l_2738;
	case 10049ULL: goto x86_l_2741;
	case 10055ULL: goto x86_l_2747;
	case 10062ULL: goto x86_l_274e;
	case 10067ULL: goto x86_l_2753;
	case 10072ULL: goto x86_l_2758;
	case 10081ULL: goto x86_l_2761;
	case 10083ULL: goto x86_l_2763;
	case 10088ULL: goto x86_l_2768;
	case 10093ULL: goto x86_l_276d;
	case 10098ULL: goto x86_l_2772;
	case 10103ULL: goto x86_l_2777;
	case 10108ULL: goto x86_l_277c;
	case 10110ULL: goto x86_l_277e;
	case 10112ULL: goto x86_l_2780;
	case 10118ULL: goto x86_l_2786;
	case 10127ULL: goto x86_l_278f;
	case 10133ULL: goto x86_l_2795;
	case 10140ULL: goto x86_l_279c;
	case 10145ULL: goto x86_l_27a1;
	case 10150ULL: goto x86_l_27a6;
	case 10159ULL: goto x86_l_27af;
	case 10161ULL: goto x86_l_27b1;
	case 10166ULL: goto x86_l_27b6;
	case 10171ULL: goto x86_l_27bb;
	case 10176ULL: goto x86_l_27c0;
	case 10181ULL: goto x86_l_27c5;
	case 10186ULL: goto x86_l_27ca;
	case 10188ULL: goto x86_l_27cc;
	case 10190ULL: goto x86_l_27ce;
	case 10196ULL: goto x86_l_27d4;
	case 10205ULL: goto x86_l_27dd;
	case 10211ULL: goto x86_l_27e3;
	case 10218ULL: goto x86_l_27ea;
	case 10223ULL: goto x86_l_27ef;
	case 10228ULL: goto x86_l_27f4;
	case 10237ULL: goto x86_l_27fd;
	case 10239ULL: goto x86_l_27ff;
	case 10244ULL: goto x86_l_2804;
	case 10249ULL: goto x86_l_2809;
	case 10254ULL: goto x86_l_280e;
	case 10259ULL: goto x86_l_2813;
	case 10264ULL: goto x86_l_2818;
	case 10266ULL: goto x86_l_281a;
	case 10268ULL: goto x86_l_281c;
	case 10274ULL: goto x86_l_2822;
	case 10283ULL: goto x86_l_282b;
	case 10289ULL: goto x86_l_2831;
	case 10296ULL: goto x86_l_2838;
	case 10301ULL: goto x86_l_283d;
	case 10306ULL: goto x86_l_2842;
	case 10315ULL: goto x86_l_284b;
	case 10317ULL: goto x86_l_284d;
	case 10322ULL: goto x86_l_2852;
	case 10327ULL: goto x86_l_2857;
	case 10332ULL: goto x86_l_285c;
	case 10337ULL: goto x86_l_2861;
	case 10342ULL: goto x86_l_2866;
	case 10344ULL: goto x86_l_2868;
	case 10346ULL: goto x86_l_286a;
	case 10352ULL: goto x86_l_2870;
	case 10361ULL: goto x86_l_2879;
	case 10367ULL: goto x86_l_287f;
	case 10374ULL: goto x86_l_2886;
	case 10379ULL: goto x86_l_288b;
	case 10384ULL: goto x86_l_2890;
	case 10393ULL: goto x86_l_2899;
	case 10395ULL: goto x86_l_289b;
	case 10400ULL: goto x86_l_28a0;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10415ULL: goto x86_l_28af;
	case 10420ULL: goto x86_l_28b4;
	case 10422ULL: goto x86_l_28b6;
	case 10424ULL: goto x86_l_28b8;
	case 10430ULL: goto x86_l_28be;
	case 10439ULL: goto x86_l_28c7;
	case 10445ULL: goto x86_l_28cd;
	case 10452ULL: goto x86_l_28d4;
	case 10457ULL: goto x86_l_28d9;
	case 10462ULL: goto x86_l_28de;
	case 10471ULL: goto x86_l_28e7;
	case 10473ULL: goto x86_l_28e9;
	case 10478ULL: goto x86_l_28ee;
	case 10483ULL: goto x86_l_28f3;
	case 10488ULL: goto x86_l_28f8;
	case 10493ULL: goto x86_l_28fd;
	case 10498ULL: goto x86_l_2902;
	case 10500ULL: goto x86_l_2904;
	case 10502ULL: goto x86_l_2906;
	case 10508ULL: goto x86_l_290c;
	case 10513ULL: goto x86_l_2911;
	case 10522ULL: goto x86_l_291a;
	case 10528ULL: goto x86_l_2920;
	case 10535ULL: goto x86_l_2927;
	case 10540ULL: goto x86_l_292c;
	case 10545ULL: goto x86_l_2931;
	case 10554ULL: goto x86_l_293a;
	case 10556ULL: goto x86_l_293c;
	case 10561ULL: goto x86_l_2941;
	case 10566ULL: goto x86_l_2946;
	case 10571ULL: goto x86_l_294b;
	case 10576ULL: goto x86_l_2950;
	case 10581ULL: goto x86_l_2955;
	case 10583ULL: goto x86_l_2957;
	case 10585ULL: goto x86_l_2959;
	case 10591ULL: goto x86_l_295f;
	case 10596ULL: goto x86_l_2964;
	case 10605ULL: goto x86_l_296d;
	case 10611ULL: goto x86_l_2973;
	case 10618ULL: goto x86_l_297a;
	case 10623ULL: goto x86_l_297f;
	case 10628ULL: goto x86_l_2984;
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
	case 10683ULL: goto x86_l_29bb;
	case 10688ULL: goto x86_l_29c0;
	case 10695ULL: goto x86_l_29c7;
	case 10701ULL: goto x86_l_29cd;
	case 10704ULL: goto x86_l_29d0;
	case 10709ULL: goto x86_l_29d5;
	case 10714ULL: goto x86_l_29da;
	case 10719ULL: goto x86_l_29df;
	case 10724ULL: goto x86_l_29e4;
	case 10726ULL: goto x86_l_29e6;
	case 10728ULL: goto x86_l_29e8;
	case 10734ULL: goto x86_l_29ee;
	case 10741ULL: goto x86_l_29f5;
	case 10747ULL: goto x86_l_29fb;
	case 10750ULL: goto x86_l_29fe;
	case 10755ULL: goto x86_l_2a03;
	case 10760ULL: goto x86_l_2a08;
	case 10765ULL: goto x86_l_2a0d;
	case 10770ULL: goto x86_l_2a12;
	case 10772ULL: goto x86_l_2a14;
	case 10774ULL: goto x86_l_2a16;
	case 10776ULL: goto x86_l_2a18;
	case 10784ULL: goto x86_l_2a20;
	case 10791ULL: goto x86_l_2a27;
	case 10798ULL: goto x86_l_2a2e;
	case 10803ULL: goto x86_l_2a33;
	case 10806ULL: goto x86_l_2a36;
	case 10811ULL: goto x86_l_2a3b;
	case 10816ULL: goto x86_l_2a40;
	case 10821ULL: goto x86_l_2a45;
	case 10829ULL: goto x86_l_2a4d;
	case 10836ULL: goto x86_l_2a54;
	case 10843ULL: goto x86_l_2a5b;
	case 10848ULL: goto x86_l_2a60;
	case 10851ULL: goto x86_l_2a63;
	case 10856ULL: goto x86_l_2a68;
	case 10858ULL: goto x86_l_2a6a;
	case 10860ULL: goto x86_l_2a6c;
	case 10866ULL: goto x86_l_2a72;
	case 10869ULL: goto x86_l_2a75;
	case 10874ULL: goto x86_l_2a7a;
	case 10876ULL: goto x86_l_2a7c;
	case 10879ULL: goto x86_l_2a7f;
	case 10888ULL: goto x86_l_2a88;
	case 10894ULL: goto x86_l_2a8e;
	case 10901ULL: goto x86_l_2a95;
	case 10904ULL: goto x86_l_2a98;
	case 10911ULL: goto x86_l_2a9f;
	case 10914ULL: goto x86_l_2aa2;
	case 10919ULL: goto x86_l_2aa7;
	case 10927ULL: goto x86_l_2aaf;
	case 10929ULL: goto x86_l_2ab1;
	case 10935ULL: goto x86_l_2ab7;
	case 10938ULL: goto x86_l_2aba;
	case 10940ULL: goto x86_l_2abc;
	case 10945ULL: goto x86_l_2ac1;
	case 10950ULL: goto x86_l_2ac6;
	case 10955ULL: goto x86_l_2acb;
	case 10960ULL: goto x86_l_2ad0;
	case 10965ULL: goto x86_l_2ad5;
	case 10967ULL: goto x86_l_2ad7;
	case 10969ULL: goto x86_l_2ad9;
	case 10975ULL: goto x86_l_2adf;
	case 10984ULL: goto x86_l_2ae8;
	case 10990ULL: goto x86_l_2aee;
	case 10997ULL: goto x86_l_2af5;
	case 11002ULL: goto x86_l_2afa;
	case 11007ULL: goto x86_l_2aff;
	case 11016ULL: goto x86_l_2b08;
	case 11018ULL: goto x86_l_2b0a;
	case 11023ULL: goto x86_l_2b0f;
	case 11028ULL: goto x86_l_2b14;
	case 11033ULL: goto x86_l_2b19;
	case 11038ULL: goto x86_l_2b1e;
	case 11043ULL: goto x86_l_2b23;
	case 11045ULL: goto x86_l_2b25;
	case 11047ULL: goto x86_l_2b27;
	case 11053ULL: goto x86_l_2b2d;
	case 11062ULL: goto x86_l_2b36;
	case 11068ULL: goto x86_l_2b3c;
	case 11075ULL: goto x86_l_2b43;
	case 11080ULL: goto x86_l_2b48;
	case 11085ULL: goto x86_l_2b4d;
	case 11094ULL: goto x86_l_2b56;
	case 11096ULL: goto x86_l_2b58;
	case 11101ULL: goto x86_l_2b5d;
	case 11106ULL: goto x86_l_2b62;
	case 11111ULL: goto x86_l_2b67;
	case 11116ULL: goto x86_l_2b6c;
	case 11121ULL: goto x86_l_2b71;
	case 11123ULL: goto x86_l_2b73;
	case 11125ULL: goto x86_l_2b75;
	case 11131ULL: goto x86_l_2b7b;
	case 11140ULL: goto x86_l_2b84;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23e2:
	/* 0x23e2: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_23e5:
	/* 0x23e5: je     240a <generic_sleepable_preload+0x240a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_240a;
	}
x86_l_23e7:
	/* 0x23e7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23ec:
	/* 0x23ec: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23f1:
	/* 0x23f1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23f6:
	/* 0x23f6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23fb:
	/* 0x23fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2400:
	/* 0x2400: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2402:
	/* 0x2402: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2404:
	/* 0x2404: js     3e5a <generic_sleepable_preload+0x3e5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15962ULL;
	}
x86_l_240a:
	/* 0x240a: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2413:
	/* 0x2413: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_2419:
	/* 0x2419: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2420:
	/* 0x2420: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2425:
	/* 0x2425: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_242a:
	/* 0x242a: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2433:
	/* 0x2433: je     2458 <generic_sleepable_preload+0x2458> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2458;
	}
x86_l_2435:
	/* 0x2435: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_243a:
	/* 0x243a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_243f:
	/* 0x243f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2444:
	/* 0x2444: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2449:
	/* 0x2449: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_244e:
	/* 0x244e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2450:
	/* 0x2450: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2452:
	/* 0x2452: js     53fb <generic_sleepable_preload+0x53fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21499ULL;
	}
x86_l_2458:
	/* 0x2458: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2461:
	/* 0x2461: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_2467:
	/* 0x2467: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_246e:
	/* 0x246e: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2473:
	/* 0x2473: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2478:
	/* 0x2478: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_2481:
	/* 0x2481: je     24a6 <generic_sleepable_preload+0x24a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24a6;
	}
x86_l_2483:
	/* 0x2483: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2488:
	/* 0x2488: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_248d:
	/* 0x248d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2492:
	/* 0x2492: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2497:
	/* 0x2497: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_249c:
	/* 0x249c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_249e:
	/* 0x249e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24a0:
	/* 0x24a0: js     60e2 <generic_sleepable_preload+0x60e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24802ULL;
	}
x86_l_24a6:
	/* 0x24a6: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_24af:
	/* 0x24af: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_24b5:
	/* 0x24b5: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_24bc:
	/* 0x24bc: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_24c1:
	/* 0x24c1: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24c6:
	/* 0x24c6: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_24cf:
	/* 0x24cf: je     24f4 <generic_sleepable_preload+0x24f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f4;
	}
x86_l_24d1:
	/* 0x24d1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24d6:
	/* 0x24d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24db:
	/* 0x24db: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24e0:
	/* 0x24e0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e5:
	/* 0x24e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24ea:
	/* 0x24ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ec:
	/* 0x24ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24ee:
	/* 0x24ee: js     6146 <generic_sleepable_preload+0x6146> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24902ULL;
	}
x86_l_24f4:
	/* 0x24f4: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_24fd:
	/* 0x24fd: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_2503:
	/* 0x2503: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_250a:
	/* 0x250a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_250f:
	/* 0x250f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2514:
	/* 0x2514: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_251d:
	/* 0x251d: je     2542 <generic_sleepable_preload+0x2542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2542;
	}
x86_l_251f:
	/* 0x251f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2524:
	/* 0x2524: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2529:
	/* 0x2529: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_252e:
	/* 0x252e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x253c: js     61aa <generic_sleepable_preload+0x61aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25002ULL;
	}
x86_l_2542:
	/* 0x2542: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_254b:
	/* 0x254b: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_2551:
	/* 0x2551: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2558:
	/* 0x2558: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_255d:
	/* 0x255d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2562:
	/* 0x2562: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_256b:
	/* 0x256b: je     2590 <generic_sleepable_preload+0x2590> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2590;
	}
x86_l_256d:
	/* 0x256d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2572:
	/* 0x2572: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2577:
	/* 0x2577: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_257c:
	/* 0x257c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2581:
	/* 0x2581: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2586:
	/* 0x2586: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2588:
	/* 0x2588: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_258a:
	/* 0x258a: js     620b <generic_sleepable_preload+0x620b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25099ULL;
	}
x86_l_2590:
	/* 0x2590: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2599:
	/* 0x2599: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_259f:
	/* 0x259f: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_25a6:
	/* 0x25a6: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_25ab:
	/* 0x25ab: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25b0:
	/* 0x25b0: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_25b9:
	/* 0x25b9: je     25de <generic_sleepable_preload+0x25de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25de;
	}
x86_l_25bb:
	/* 0x25bb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25c0:
	/* 0x25c0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_25c5:
	/* 0x25c5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25ca:
	/* 0x25ca: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25cf:
	/* 0x25cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25d4:
	/* 0x25d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d6:
	/* 0x25d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25d8:
	/* 0x25d8: js     62f2 <generic_sleepable_preload+0x62f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25330ULL;
	}
x86_l_25de:
	/* 0x25de: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_25e7:
	/* 0x25e7: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_25ed:
	/* 0x25ed: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_25f4:
	/* 0x25f4: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_25f9:
	/* 0x25f9: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25fe:
	/* 0x25fe: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2607:
	/* 0x2607: je     262c <generic_sleepable_preload+0x262c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_262c;
	}
x86_l_2609:
	/* 0x2609: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_260e:
	/* 0x260e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2613:
	/* 0x2613: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2618:
	/* 0x2618: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_261d:
	/* 0x261d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2622:
	/* 0x2622: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2624:
	/* 0x2624: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2626:
	/* 0x2626: js     68c1 <generic_sleepable_preload+0x68c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26817ULL;
	}
x86_l_262c:
	/* 0x262c: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2635:
	/* 0x2635: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_263b:
	/* 0x263b: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2642:
	/* 0x2642: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2647:
	/* 0x2647: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_264c:
	/* 0x264c: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2655:
	/* 0x2655: je     267a <generic_sleepable_preload+0x267a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_267a;
	}
x86_l_2657:
	/* 0x2657: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_265c:
	/* 0x265c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2661:
	/* 0x2661: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2666:
	/* 0x2666: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_266b:
	/* 0x266b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2670:
	/* 0x2670: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2672:
	/* 0x2672: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2674:
	/* 0x2674: js     692e <generic_sleepable_preload+0x692e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26926ULL;
	}
x86_l_267a:
	/* 0x267a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_267f:
	/* 0x267f: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2688:
	/* 0x2688: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_268e:
	/* 0x268e: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2695:
	/* 0x2695: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_269a:
	/* 0x269a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_269f:
	/* 0x269f: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_26a8:
	/* 0x26a8: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_26ae:
	/* 0x26ae: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26b3:
	/* 0x26b3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26b8:
	/* 0x26b8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26bd:
	/* 0x26bd: jmp    29a2 <generic_sleepable_preload+0x29a2> */
	goto x86_l_29a2;
x86_l_26c2:
	/* 0x26c2: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_26c5:
	/* 0x26c5: je     26ea <generic_sleepable_preload+0x26ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26ea;
	}
x86_l_26c7:
	/* 0x26c7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26cc:
	/* 0x26cc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26d1:
	/* 0x26d1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26d6:
	/* 0x26d6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26db:
	/* 0x26db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26e0:
	/* 0x26e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e2:
	/* 0x26e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26e4:
	/* 0x26e4: js     3e5a <generic_sleepable_preload+0x3e5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15962ULL;
	}
x86_l_26ea:
	/* 0x26ea: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_26f3:
	/* 0x26f3: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_26f9:
	/* 0x26f9: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2700:
	/* 0x2700: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2705:
	/* 0x2705: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_270a:
	/* 0x270a: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2713:
	/* 0x2713: je     2738 <generic_sleepable_preload+0x2738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2738;
	}
x86_l_2715:
	/* 0x2715: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_271a:
	/* 0x271a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_271f:
	/* 0x271f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2724:
	/* 0x2724: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2729:
	/* 0x2729: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_272e:
	/* 0x272e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2730:
	/* 0x2730: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2732:
	/* 0x2732: js     53fb <generic_sleepable_preload+0x53fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21499ULL;
	}
x86_l_2738:
	/* 0x2738: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2741:
	/* 0x2741: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_2747:
	/* 0x2747: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_274e:
	/* 0x274e: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2753:
	/* 0x2753: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2758:
	/* 0x2758: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_2761:
	/* 0x2761: je     2786 <generic_sleepable_preload+0x2786> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2786;
	}
x86_l_2763:
	/* 0x2763: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2768:
	/* 0x2768: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_276d:
	/* 0x276d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2772:
	/* 0x2772: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2777:
	/* 0x2777: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_277c:
	/* 0x277c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277e:
	/* 0x277e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2780:
	/* 0x2780: js     60e2 <generic_sleepable_preload+0x60e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24802ULL;
	}
x86_l_2786:
	/* 0x2786: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_278f:
	/* 0x278f: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_2795:
	/* 0x2795: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_279c:
	/* 0x279c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_27a1:
	/* 0x27a1: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27a6:
	/* 0x27a6: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_27af:
	/* 0x27af: je     27d4 <generic_sleepable_preload+0x27d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d4;
	}
x86_l_27b1:
	/* 0x27b1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27b6:
	/* 0x27b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27bb:
	/* 0x27bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27c0:
	/* 0x27c0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27c5:
	/* 0x27c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27ca:
	/* 0x27ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27cc:
	/* 0x27cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27ce:
	/* 0x27ce: js     6146 <generic_sleepable_preload+0x6146> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24902ULL;
	}
x86_l_27d4:
	/* 0x27d4: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_27dd:
	/* 0x27dd: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_27e3:
	/* 0x27e3: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_27ea:
	/* 0x27ea: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_27ef:
	/* 0x27ef: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27f4:
	/* 0x27f4: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_27fd:
	/* 0x27fd: je     2822 <generic_sleepable_preload+0x2822> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2822;
	}
x86_l_27ff:
	/* 0x27ff: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2804:
	/* 0x2804: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2809:
	/* 0x2809: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_280e:
	/* 0x280e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2813:
	/* 0x2813: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2818:
	/* 0x2818: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_281a:
	/* 0x281a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_281c:
	/* 0x281c: js     61aa <generic_sleepable_preload+0x61aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25002ULL;
	}
x86_l_2822:
	/* 0x2822: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_282b:
	/* 0x282b: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_2831:
	/* 0x2831: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2838:
	/* 0x2838: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_283d:
	/* 0x283d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2842:
	/* 0x2842: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_284b:
	/* 0x284b: je     2870 <generic_sleepable_preload+0x2870> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2870;
	}
x86_l_284d:
	/* 0x284d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2852:
	/* 0x2852: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2857:
	/* 0x2857: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_285c:
	/* 0x285c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2861:
	/* 0x2861: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2866:
	/* 0x2866: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2868:
	/* 0x2868: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_286a:
	/* 0x286a: js     620b <generic_sleepable_preload+0x620b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25099ULL;
	}
x86_l_2870:
	/* 0x2870: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2879:
	/* 0x2879: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_287f:
	/* 0x287f: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2886:
	/* 0x2886: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_288b:
	/* 0x288b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2890:
	/* 0x2890: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2899:
	/* 0x2899: je     28be <generic_sleepable_preload+0x28be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28be;
	}
x86_l_289b:
	/* 0x289b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28a0:
	/* 0x28a0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28a5:
	/* 0x28a5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28aa:
	/* 0x28aa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28af:
	/* 0x28af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28b4:
	/* 0x28b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b6:
	/* 0x28b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28b8:
	/* 0x28b8: js     62f2 <generic_sleepable_preload+0x62f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25330ULL;
	}
x86_l_28be:
	/* 0x28be: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_28c7:
	/* 0x28c7: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_28cd:
	/* 0x28cd: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_28d4:
	/* 0x28d4: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_28d9:
	/* 0x28d9: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28de:
	/* 0x28de: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_28e7:
	/* 0x28e7: je     290c <generic_sleepable_preload+0x290c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_290c;
	}
x86_l_28e9:
	/* 0x28e9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28ee:
	/* 0x28ee: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28f3:
	/* 0x28f3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28f8:
	/* 0x28f8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28fd:
	/* 0x28fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2902:
	/* 0x2902: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2904:
	/* 0x2904: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2906:
	/* 0x2906: js     69c8 <generic_sleepable_preload+0x69c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27080ULL;
	}
x86_l_290c:
	/* 0x290c: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2911:
	/* 0x2911: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_291a:
	/* 0x291a: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_2920:
	/* 0x2920: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2927:
	/* 0x2927: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_292c:
	/* 0x292c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2931:
	/* 0x2931: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_293a:
	/* 0x293a: je     295f <generic_sleepable_preload+0x295f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_295f;
	}
x86_l_293c:
	/* 0x293c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2941:
	/* 0x2941: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2946:
	/* 0x2946: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_294b:
	/* 0x294b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2950:
	/* 0x2950: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2955:
	/* 0x2955: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2957:
	/* 0x2957: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2959:
	/* 0x2959: js     692e <generic_sleepable_preload+0x692e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26926ULL;
	}
x86_l_295f:
	/* 0x295f: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2964:
	/* 0x2964: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_296d:
	/* 0x296d: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_2973:
	/* 0x2973: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_297a:
	/* 0x297a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_297f:
	/* 0x297f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2984:
	/* 0x2984: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_298d:
	/* 0x298d: je     62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25337ULL;
	}
x86_l_2993:
	/* 0x2993: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2998:
	/* 0x2998: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_299d:
	/* 0x299d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29a2:
	/* 0x29a2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x29b0: jns    62f9 <generic_sleepable_preload+0x62f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25337ULL;
	}
x86_l_29b6:
	/* 0x29b6: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_29bb:
	/* 0x29bb: jmp    62f7 <generic_sleepable_preload+0x62f7> */
	return 25335ULL;
x86_l_29c0:
	/* 0x29c0: mov    edx,DWORD PTR [r13+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_29c7:
	/* 0x29c7: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29cd:
	/* 0x29cd: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29d0:
	/* 0x29d0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29d5:
	/* 0x29d5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29da:
	/* 0x29da: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29df:
	/* 0x29df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29e4:
	/* 0x29e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29e6:
	/* 0x29e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29e8:
	/* 0x29e8: jne    2a72 <generic_sleepable_preload+0x2a72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a72;
	}
x86_l_29ee:
	/* 0x29ee: mov    edx,DWORD PTR [r13+0x23c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_29f5:
	/* 0x29f5: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29fb:
	/* 0x29fb: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29fe:
	/* 0x29fe: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a03:
	/* 0x2a03: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a08:
	/* 0x2a08: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a0d:
	/* 0x2a0d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a12:
	/* 0x2a12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a14:
	/* 0x2a14: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a16:
	/* 0x2a16: jne    2a72 <generic_sleepable_preload+0x2a72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a72;
	}
x86_l_2a18:
	/* 0x2a18: movzx  eax,BYTE PTR [r13+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_2a20:
	/* 0x2a20: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2a27:
	/* 0x2a27: mov    rcx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_2a2e:
	/* 0x2a2e: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2a33:
	/* 0x2a33: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a36:
	/* 0x2a36: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a3b:
	/* 0x2a3b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a40:
	/* 0x2a40: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a45:
	/* 0x2a45: movzx  ecx,BYTE PTR [r13+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_2a4d:
	/* 0x2a4d: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2a54:
	/* 0x2a54: mov    rdx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_2a5b:
	/* 0x2a5b: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2a60:
	/* 0x2a60: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a63:
	/* 0x2a63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a68:
	/* 0x2a68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a6a:
	/* 0x2a6a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a6c:
	/* 0x2a6c: je     1bde <generic_sleepable_preload+0x1bde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7134ULL;
	}
x86_l_2a72:
	/* 0x2a72: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2a75:
	/* 0x2a75: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a7a:
	/* 0x2a7a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a7c:
	/* 0x2a7c: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_2a7f:
	/* 0x2a7f: cmp    WORD PTR [r13+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_2a88:
	/* 0x2a88: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2a8e:
	/* 0x2a8e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2a95:
	/* 0x2a95: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2a98:
	/* 0x2a98: mov    eax,DWORD PTR [r13+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2a9f:
	/* 0x2a9f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2aa2:
	/* 0x2aa2: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aa7:
	/* 0x2aa7: movzx  eax,WORD PTR [r13+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_2aaf:
	/* 0x2aaf: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2ab1:
	/* 0x2ab1: je     2d9c <generic_sleepable_preload+0x2d9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11676ULL;
	}
x86_l_2ab7:
	/* 0x2ab7: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2aba:
	/* 0x2aba: je     2adf <generic_sleepable_preload+0x2adf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2adf;
	}
x86_l_2abc:
	/* 0x2abc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ac1:
	/* 0x2ac1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ac6:
	/* 0x2ac6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2acb:
	/* 0x2acb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ad0:
	/* 0x2ad0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ad5:
	/* 0x2ad5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ad7:
	/* 0x2ad7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ad9:
	/* 0x2ad9: js     3e64 <generic_sleepable_preload+0x3e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15972ULL;
	}
x86_l_2adf:
	/* 0x2adf: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2ae8:
	/* 0x2ae8: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2aee:
	/* 0x2aee: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2af5:
	/* 0x2af5: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2afa:
	/* 0x2afa: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aff:
	/* 0x2aff: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2b08:
	/* 0x2b08: je     2b2d <generic_sleepable_preload+0x2b2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b2d;
	}
x86_l_2b0a:
	/* 0x2b0a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b0f:
	/* 0x2b0f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b14:
	/* 0x2b14: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b19:
	/* 0x2b19: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b1e:
	/* 0x2b1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b23:
	/* 0x2b23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b25:
	/* 0x2b25: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b27:
	/* 0x2b27: js     5405 <generic_sleepable_preload+0x5405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21509ULL;
	}
x86_l_2b2d:
	/* 0x2b2d: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2b36:
	/* 0x2b36: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2b3c:
	/* 0x2b3c: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2b43:
	/* 0x2b43: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2b48:
	/* 0x2b48: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b4d:
	/* 0x2b4d: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2b56:
	/* 0x2b56: je     2b7b <generic_sleepable_preload+0x2b7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b7b;
	}
x86_l_2b58:
	/* 0x2b58: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b5d:
	/* 0x2b5d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b62:
	/* 0x2b62: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b67:
	/* 0x2b67: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b6c:
	/* 0x2b6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b71:
	/* 0x2b71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b73:
	/* 0x2b73: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b75:
	/* 0x2b75: js     60ec <generic_sleepable_preload+0x60ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24812ULL;
	}
x86_l_2b7b:
	/* 0x2b7b: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2b84:
	/* 0x2b84: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
	return 11146ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11146ULL: goto x86_l_2b8a;
	case 11153ULL: goto x86_l_2b91;
	case 11158ULL: goto x86_l_2b96;
	case 11163ULL: goto x86_l_2b9b;
	case 11172ULL: goto x86_l_2ba4;
	case 11174ULL: goto x86_l_2ba6;
	case 11179ULL: goto x86_l_2bab;
	case 11184ULL: goto x86_l_2bb0;
	case 11189ULL: goto x86_l_2bb5;
	case 11194ULL: goto x86_l_2bba;
	case 11199ULL: goto x86_l_2bbf;
	case 11201ULL: goto x86_l_2bc1;
	case 11203ULL: goto x86_l_2bc3;
	case 11209ULL: goto x86_l_2bc9;
	case 11218ULL: goto x86_l_2bd2;
	case 11224ULL: goto x86_l_2bd8;
	case 11231ULL: goto x86_l_2bdf;
	case 11236ULL: goto x86_l_2be4;
	case 11241ULL: goto x86_l_2be9;
	case 11250ULL: goto x86_l_2bf2;
	case 11252ULL: goto x86_l_2bf4;
	case 11257ULL: goto x86_l_2bf9;
	case 11262ULL: goto x86_l_2bfe;
	case 11267ULL: goto x86_l_2c03;
	case 11272ULL: goto x86_l_2c08;
	case 11277ULL: goto x86_l_2c0d;
	case 11279ULL: goto x86_l_2c0f;
	case 11281ULL: goto x86_l_2c11;
	case 11287ULL: goto x86_l_2c17;
	case 11296ULL: goto x86_l_2c20;
	case 11302ULL: goto x86_l_2c26;
	case 11309ULL: goto x86_l_2c2d;
	case 11314ULL: goto x86_l_2c32;
	case 11319ULL: goto x86_l_2c37;
	case 11328ULL: goto x86_l_2c40;
	case 11330ULL: goto x86_l_2c42;
	case 11335ULL: goto x86_l_2c47;
	case 11340ULL: goto x86_l_2c4c;
	case 11345ULL: goto x86_l_2c51;
	case 11350ULL: goto x86_l_2c56;
	case 11355ULL: goto x86_l_2c5b;
	case 11357ULL: goto x86_l_2c5d;
	case 11359ULL: goto x86_l_2c5f;
	case 11365ULL: goto x86_l_2c65;
	case 11374ULL: goto x86_l_2c6e;
	case 11380ULL: goto x86_l_2c74;
	case 11387ULL: goto x86_l_2c7b;
	case 11392ULL: goto x86_l_2c80;
	case 11397ULL: goto x86_l_2c85;
	case 11406ULL: goto x86_l_2c8e;
	case 11408ULL: goto x86_l_2c90;
	case 11413ULL: goto x86_l_2c95;
	case 11418ULL: goto x86_l_2c9a;
	case 11423ULL: goto x86_l_2c9f;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11435ULL: goto x86_l_2cab;
	case 11437ULL: goto x86_l_2cad;
	case 11443ULL: goto x86_l_2cb3;
	case 11452ULL: goto x86_l_2cbc;
	case 11458ULL: goto x86_l_2cc2;
	case 11465ULL: goto x86_l_2cc9;
	case 11470ULL: goto x86_l_2cce;
	case 11475ULL: goto x86_l_2cd3;
	case 11484ULL: goto x86_l_2cdc;
	case 11486ULL: goto x86_l_2cde;
	case 11491ULL: goto x86_l_2ce3;
	case 11496ULL: goto x86_l_2ce8;
	case 11501ULL: goto x86_l_2ced;
	case 11506ULL: goto x86_l_2cf2;
	case 11511ULL: goto x86_l_2cf7;
	case 11513ULL: goto x86_l_2cf9;
	case 11515ULL: goto x86_l_2cfb;
	case 11521ULL: goto x86_l_2d01;
	case 11530ULL: goto x86_l_2d0a;
	case 11536ULL: goto x86_l_2d10;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11553ULL: goto x86_l_2d21;
	case 11562ULL: goto x86_l_2d2a;
	case 11564ULL: goto x86_l_2d2c;
	case 11569ULL: goto x86_l_2d31;
	case 11574ULL: goto x86_l_2d36;
	case 11579ULL: goto x86_l_2d3b;
	case 11584ULL: goto x86_l_2d40;
	case 11589ULL: goto x86_l_2d45;
	case 11591ULL: goto x86_l_2d47;
	case 11593ULL: goto x86_l_2d49;
	case 11599ULL: goto x86_l_2d4f;
	case 11604ULL: goto x86_l_2d54;
	case 11613ULL: goto x86_l_2d5d;
	case 11618ULL: goto x86_l_2d62;
	case 11624ULL: goto x86_l_2d68;
	case 11631ULL: goto x86_l_2d6f;
	case 11636ULL: goto x86_l_2d74;
	case 11641ULL: goto x86_l_2d79;
	case 11650ULL: goto x86_l_2d82;
	case 11656ULL: goto x86_l_2d88;
	case 11661ULL: goto x86_l_2d8d;
	case 11666ULL: goto x86_l_2d92;
	case 11671ULL: goto x86_l_2d97;
	case 11676ULL: goto x86_l_2d9c;
	case 11679ULL: goto x86_l_2d9f;
	case 11681ULL: goto x86_l_2da1;
	case 11686ULL: goto x86_l_2da6;
	case 11691ULL: goto x86_l_2dab;
	case 11696ULL: goto x86_l_2db0;
	case 11701ULL: goto x86_l_2db5;
	case 11706ULL: goto x86_l_2dba;
	case 11708ULL: goto x86_l_2dbc;
	case 11710ULL: goto x86_l_2dbe;
	case 11716ULL: goto x86_l_2dc4;
	case 11725ULL: goto x86_l_2dcd;
	case 11731ULL: goto x86_l_2dd3;
	case 11738ULL: goto x86_l_2dda;
	case 11743ULL: goto x86_l_2ddf;
	case 11748ULL: goto x86_l_2de4;
	case 11757ULL: goto x86_l_2ded;
	case 11759ULL: goto x86_l_2def;
	case 11764ULL: goto x86_l_2df4;
	case 11769ULL: goto x86_l_2df9;
	case 11774ULL: goto x86_l_2dfe;
	case 11779ULL: goto x86_l_2e03;
	case 11784ULL: goto x86_l_2e08;
	case 11786ULL: goto x86_l_2e0a;
	case 11788ULL: goto x86_l_2e0c;
	case 11794ULL: goto x86_l_2e12;
	case 11803ULL: goto x86_l_2e1b;
	case 11809ULL: goto x86_l_2e21;
	case 11816ULL: goto x86_l_2e28;
	case 11821ULL: goto x86_l_2e2d;
	case 11826ULL: goto x86_l_2e32;
	case 11835ULL: goto x86_l_2e3b;
	case 11837ULL: goto x86_l_2e3d;
	case 11842ULL: goto x86_l_2e42;
	case 11847ULL: goto x86_l_2e47;
	case 11852ULL: goto x86_l_2e4c;
	case 11857ULL: goto x86_l_2e51;
	case 11862ULL: goto x86_l_2e56;
	case 11864ULL: goto x86_l_2e58;
	case 11866ULL: goto x86_l_2e5a;
	case 11872ULL: goto x86_l_2e60;
	case 11881ULL: goto x86_l_2e69;
	case 11887ULL: goto x86_l_2e6f;
	case 11894ULL: goto x86_l_2e76;
	case 11899ULL: goto x86_l_2e7b;
	case 11904ULL: goto x86_l_2e80;
	case 11913ULL: goto x86_l_2e89;
	case 11915ULL: goto x86_l_2e8b;
	case 11920ULL: goto x86_l_2e90;
	case 11925ULL: goto x86_l_2e95;
	case 11930ULL: goto x86_l_2e9a;
	case 11935ULL: goto x86_l_2e9f;
	case 11940ULL: goto x86_l_2ea4;
	case 11942ULL: goto x86_l_2ea6;
	case 11944ULL: goto x86_l_2ea8;
	case 11950ULL: goto x86_l_2eae;
	case 11959ULL: goto x86_l_2eb7;
	case 11965ULL: goto x86_l_2ebd;
	case 11972ULL: goto x86_l_2ec4;
	case 11977ULL: goto x86_l_2ec9;
	case 11982ULL: goto x86_l_2ece;
	case 11991ULL: goto x86_l_2ed7;
	case 11993ULL: goto x86_l_2ed9;
	case 11998ULL: goto x86_l_2ede;
	case 12003ULL: goto x86_l_2ee3;
	case 12008ULL: goto x86_l_2ee8;
	case 12013ULL: goto x86_l_2eed;
	case 12018ULL: goto x86_l_2ef2;
	case 12020ULL: goto x86_l_2ef4;
	case 12022ULL: goto x86_l_2ef6;
	case 12028ULL: goto x86_l_2efc;
	case 12037ULL: goto x86_l_2f05;
	case 12043ULL: goto x86_l_2f0b;
	case 12050ULL: goto x86_l_2f12;
	case 12055ULL: goto x86_l_2f17;
	case 12060ULL: goto x86_l_2f1c;
	case 12069ULL: goto x86_l_2f25;
	case 12071ULL: goto x86_l_2f27;
	case 12076ULL: goto x86_l_2f2c;
	case 12081ULL: goto x86_l_2f31;
	case 12086ULL: goto x86_l_2f36;
	case 12091ULL: goto x86_l_2f3b;
	case 12096ULL: goto x86_l_2f40;
	case 12098ULL: goto x86_l_2f42;
	case 12100ULL: goto x86_l_2f44;
	case 12106ULL: goto x86_l_2f4a;
	case 12115ULL: goto x86_l_2f53;
	case 12121ULL: goto x86_l_2f59;
	case 12128ULL: goto x86_l_2f60;
	case 12133ULL: goto x86_l_2f65;
	case 12138ULL: goto x86_l_2f6a;
	case 12147ULL: goto x86_l_2f73;
	case 12149ULL: goto x86_l_2f75;
	case 12154ULL: goto x86_l_2f7a;
	case 12159ULL: goto x86_l_2f7f;
	case 12164ULL: goto x86_l_2f84;
	case 12169ULL: goto x86_l_2f89;
	case 12174ULL: goto x86_l_2f8e;
	case 12176ULL: goto x86_l_2f90;
	case 12178ULL: goto x86_l_2f92;
	case 12184ULL: goto x86_l_2f98;
	case 12193ULL: goto x86_l_2fa1;
	case 12199ULL: goto x86_l_2fa7;
	case 12206ULL: goto x86_l_2fae;
	case 12211ULL: goto x86_l_2fb3;
	case 12216ULL: goto x86_l_2fb8;
	case 12225ULL: goto x86_l_2fc1;
	case 12227ULL: goto x86_l_2fc3;
	case 12232ULL: goto x86_l_2fc8;
	case 12237ULL: goto x86_l_2fcd;
	case 12242ULL: goto x86_l_2fd2;
	case 12247ULL: goto x86_l_2fd7;
	case 12252ULL: goto x86_l_2fdc;
	case 12254ULL: goto x86_l_2fde;
	case 12256ULL: goto x86_l_2fe0;
	case 12262ULL: goto x86_l_2fe6;
	case 12267ULL: goto x86_l_2feb;
	case 12276ULL: goto x86_l_2ff4;
	case 12281ULL: goto x86_l_2ff9;
	case 12287ULL: goto x86_l_2fff;
	case 12294ULL: goto x86_l_3006;
	case 12299ULL: goto x86_l_300b;
	case 12304ULL: goto x86_l_3010;
	case 12313ULL: goto x86_l_3019;
	case 12315ULL: goto x86_l_301b;
	case 12320ULL: goto x86_l_3020;
	case 12325ULL: goto x86_l_3025;
	case 12330ULL: goto x86_l_302a;
	case 12335ULL: goto x86_l_302f;
	case 12340ULL: goto x86_l_3034;
	case 12342ULL: goto x86_l_3036;
	case 12344ULL: goto x86_l_3038;
	case 12350ULL: goto x86_l_303e;
	case 12355ULL: goto x86_l_3043;
	case 12364ULL: goto x86_l_304c;
	case 12369ULL: goto x86_l_3051;
	case 12375ULL: goto x86_l_3057;
	case 12382ULL: goto x86_l_305e;
	case 12387ULL: goto x86_l_3063;
	case 12392ULL: goto x86_l_3068;
	case 12401ULL: goto x86_l_3071;
	case 12407ULL: goto x86_l_3077;
	case 12412ULL: goto x86_l_307c;
	case 12417ULL: goto x86_l_3081;
	case 12422ULL: goto x86_l_3086;
	case 12427ULL: goto x86_l_308b;
	case 12432ULL: goto x86_l_3090;
	case 12434ULL: goto x86_l_3092;
	case 12436ULL: goto x86_l_3094;
	case 12442ULL: goto x86_l_309a;
	case 12447ULL: goto x86_l_309f;
	case 12452ULL: goto x86_l_30a4;
	case 12459ULL: goto x86_l_30ab;
	case 12465ULL: goto x86_l_30b1;
	case 12468ULL: goto x86_l_30b4;
	case 12473ULL: goto x86_l_30b9;
	case 12478ULL: goto x86_l_30be;
	case 12483ULL: goto x86_l_30c3;
	case 12488ULL: goto x86_l_30c8;
	case 12490ULL: goto x86_l_30ca;
	case 12492ULL: goto x86_l_30cc;
	case 12498ULL: goto x86_l_30d2;
	case 12505ULL: goto x86_l_30d9;
	case 12511ULL: goto x86_l_30df;
	case 12514ULL: goto x86_l_30e2;
	case 12519ULL: goto x86_l_30e7;
	case 12524ULL: goto x86_l_30ec;
	case 12529ULL: goto x86_l_30f1;
	case 12534ULL: goto x86_l_30f6;
	case 12536ULL: goto x86_l_30f8;
	case 12538ULL: goto x86_l_30fa;
	case 12540ULL: goto x86_l_30fc;
	case 12548ULL: goto x86_l_3104;
	case 12555ULL: goto x86_l_310b;
	case 12562ULL: goto x86_l_3112;
	case 12567ULL: goto x86_l_3117;
	case 12570ULL: goto x86_l_311a;
	case 12575ULL: goto x86_l_311f;
	case 12580ULL: goto x86_l_3124;
	case 12585ULL: goto x86_l_3129;
	case 12593ULL: goto x86_l_3131;
	case 12600ULL: goto x86_l_3138;
	case 12607ULL: goto x86_l_313f;
	case 12612ULL: goto x86_l_3144;
	case 12615ULL: goto x86_l_3147;
	case 12620ULL: goto x86_l_314c;
	case 12622ULL: goto x86_l_314e;
	case 12624ULL: goto x86_l_3150;
	case 12630ULL: goto x86_l_3156;
	case 12633ULL: goto x86_l_3159;
	case 12638ULL: goto x86_l_315e;
	case 12640ULL: goto x86_l_3160;
	case 12643ULL: goto x86_l_3163;
	case 12652ULL: goto x86_l_316c;
	case 12658ULL: goto x86_l_3172;
	case 12665ULL: goto x86_l_3179;
	case 12668ULL: goto x86_l_317c;
	case 12675ULL: goto x86_l_3183;
	case 12678ULL: goto x86_l_3186;
	case 12683ULL: goto x86_l_318b;
	case 12691ULL: goto x86_l_3193;
	case 12693ULL: goto x86_l_3195;
	case 12699ULL: goto x86_l_319b;
	case 12702ULL: goto x86_l_319e;
	case 12704ULL: goto x86_l_31a0;
	case 12709ULL: goto x86_l_31a5;
	case 12714ULL: goto x86_l_31aa;
	case 12719ULL: goto x86_l_31af;
	case 12724ULL: goto x86_l_31b4;
	case 12729ULL: goto x86_l_31b9;
	case 12731ULL: goto x86_l_31bb;
	case 12733ULL: goto x86_l_31bd;
	case 12739ULL: goto x86_l_31c3;
	case 12748ULL: goto x86_l_31cc;
	case 12754ULL: goto x86_l_31d2;
	case 12761ULL: goto x86_l_31d9;
	case 12766ULL: goto x86_l_31de;
	case 12771ULL: goto x86_l_31e3;
	case 12780ULL: goto x86_l_31ec;
	case 12782ULL: goto x86_l_31ee;
	case 12787ULL: goto x86_l_31f3;
	case 12792ULL: goto x86_l_31f8;
	case 12797ULL: goto x86_l_31fd;
	case 12802ULL: goto x86_l_3202;
	case 12807ULL: goto x86_l_3207;
	case 12809ULL: goto x86_l_3209;
	case 12811ULL: goto x86_l_320b;
	case 12817ULL: goto x86_l_3211;
	case 12826ULL: goto x86_l_321a;
	case 12832ULL: goto x86_l_3220;
	case 12839ULL: goto x86_l_3227;
	case 12844ULL: goto x86_l_322c;
	case 12849ULL: goto x86_l_3231;
	case 12858ULL: goto x86_l_323a;
	case 12860ULL: goto x86_l_323c;
	case 12865ULL: goto x86_l_3241;
	case 12870ULL: goto x86_l_3246;
	case 12875ULL: goto x86_l_324b;
	case 12880ULL: goto x86_l_3250;
	case 12885ULL: goto x86_l_3255;
	case 12887ULL: goto x86_l_3257;
	case 12889ULL: goto x86_l_3259;
	case 12895ULL: goto x86_l_325f;
	case 12904ULL: goto x86_l_3268;
	case 12910ULL: goto x86_l_326e;
	case 12917ULL: goto x86_l_3275;
	case 12922ULL: goto x86_l_327a;
	case 12927ULL: goto x86_l_327f;
	case 12936ULL: goto x86_l_3288;
	case 12938ULL: goto x86_l_328a;
	case 12943ULL: goto x86_l_328f;
	case 12948ULL: goto x86_l_3294;
	case 12953ULL: goto x86_l_3299;
	case 12958ULL: goto x86_l_329e;
	case 12963ULL: goto x86_l_32a3;
	case 12965ULL: goto x86_l_32a5;
	case 12967ULL: goto x86_l_32a7;
	case 12973ULL: goto x86_l_32ad;
	case 12982ULL: goto x86_l_32b6;
	case 12988ULL: goto x86_l_32bc;
	case 12995ULL: goto x86_l_32c3;
	case 13000ULL: goto x86_l_32c8;
	case 13005ULL: goto x86_l_32cd;
	case 13014ULL: goto x86_l_32d6;
	case 13016ULL: goto x86_l_32d8;
	case 13021ULL: goto x86_l_32dd;
	case 13026ULL: goto x86_l_32e2;
	case 13031ULL: goto x86_l_32e7;
	case 13036ULL: goto x86_l_32ec;
	case 13041ULL: goto x86_l_32f1;
	case 13043ULL: goto x86_l_32f3;
	case 13045ULL: goto x86_l_32f5;
	case 13051ULL: goto x86_l_32fb;
	case 13060ULL: goto x86_l_3304;
	case 13066ULL: goto x86_l_330a;
	case 13073ULL: goto x86_l_3311;
	case 13078ULL: goto x86_l_3316;
	case 13083ULL: goto x86_l_331b;
	case 13092ULL: goto x86_l_3324;
	case 13094ULL: goto x86_l_3326;
	case 13099ULL: goto x86_l_332b;
	case 13104ULL: goto x86_l_3330;
	case 13109ULL: goto x86_l_3335;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2b8a:
	/* 0x2b8a: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2b91:
	/* 0x2b91: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2b96:
	/* 0x2b96: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b9b:
	/* 0x2b9b: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2ba4:
	/* 0x2ba4: je     2bc9 <generic_sleepable_preload+0x2bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bc9;
	}
x86_l_2ba6:
	/* 0x2ba6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bab:
	/* 0x2bab: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bb0:
	/* 0x2bb0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2bb5:
	/* 0x2bb5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bba:
	/* 0x2bba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bbf:
	/* 0x2bbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc1:
	/* 0x2bc1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bc3:
	/* 0x2bc3: js     6150 <generic_sleepable_preload+0x6150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24912ULL;
	}
x86_l_2bc9:
	/* 0x2bc9: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2bd2:
	/* 0x2bd2: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2bd8:
	/* 0x2bd8: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2bdf:
	/* 0x2bdf: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2be4:
	/* 0x2be4: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2be9:
	/* 0x2be9: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2bf2:
	/* 0x2bf2: je     2c17 <generic_sleepable_preload+0x2c17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c17;
	}
x86_l_2bf4:
	/* 0x2bf4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bf9:
	/* 0x2bf9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bfe:
	/* 0x2bfe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c03:
	/* 0x2c03: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c08:
	/* 0x2c08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c0d:
	/* 0x2c0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c0f:
	/* 0x2c0f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c11:
	/* 0x2c11: js     61b4 <generic_sleepable_preload+0x61b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25012ULL;
	}
x86_l_2c17:
	/* 0x2c17: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2c20:
	/* 0x2c20: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2c26:
	/* 0x2c26: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2c2d:
	/* 0x2c2d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2c32:
	/* 0x2c32: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c37:
	/* 0x2c37: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2c40:
	/* 0x2c40: je     2c65 <generic_sleepable_preload+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c65;
	}
x86_l_2c42:
	/* 0x2c42: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c47:
	/* 0x2c47: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c4c:
	/* 0x2c4c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c51:
	/* 0x2c51: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c56:
	/* 0x2c56: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c5b:
	/* 0x2c5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c5d:
	/* 0x2c5d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c5f:
	/* 0x2c5f: js     6215 <generic_sleepable_preload+0x6215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25109ULL;
	}
x86_l_2c65:
	/* 0x2c65: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2c6e:
	/* 0x2c6e: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2c74:
	/* 0x2c74: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2c7b:
	/* 0x2c7b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2c80:
	/* 0x2c80: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c85:
	/* 0x2c85: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2c8e:
	/* 0x2c8e: je     2cb3 <generic_sleepable_preload+0x2cb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cb3;
	}
x86_l_2c90:
	/* 0x2c90: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c95:
	/* 0x2c95: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c9a:
	/* 0x2c9a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c9f:
	/* 0x2c9f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca4:
	/* 0x2ca4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ca9:
	/* 0x2ca9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cab:
	/* 0x2cab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cad:
	/* 0x2cad: js     637f <generic_sleepable_preload+0x637f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25471ULL;
	}
x86_l_2cb3:
	/* 0x2cb3: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2cbc:
	/* 0x2cbc: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2cc2:
	/* 0x2cc2: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2cc9:
	/* 0x2cc9: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2cce:
	/* 0x2cce: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cd3:
	/* 0x2cd3: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2cdc:
	/* 0x2cdc: je     2d01 <generic_sleepable_preload+0x2d01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d01;
	}
x86_l_2cde:
	/* 0x2cde: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ce3:
	/* 0x2ce3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ce8:
	/* 0x2ce8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ced:
	/* 0x2ced: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cf2:
	/* 0x2cf2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cf7:
	/* 0x2cf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cf9:
	/* 0x2cf9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cfb:
	/* 0x2cfb: js     68cd <generic_sleepable_preload+0x68cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26829ULL;
	}
x86_l_2d01:
	/* 0x2d01: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_2d0a:
	/* 0x2d0a: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2d10:
	/* 0x2d10: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_2d17:
	/* 0x2d17: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2d1c:
	/* 0x2d1c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d21:
	/* 0x2d21: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_2d2a:
	/* 0x2d2a: je     2d4f <generic_sleepable_preload+0x2d4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d4f;
	}
x86_l_2d2c:
	/* 0x2d2c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d31:
	/* 0x2d31: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d36:
	/* 0x2d36: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d3b:
	/* 0x2d3b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d40:
	/* 0x2d40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d45:
	/* 0x2d45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d47:
	/* 0x2d47: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d49:
	/* 0x2d49: js     693f <generic_sleepable_preload+0x693f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26943ULL;
	}
x86_l_2d4f:
	/* 0x2d4f: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d54:
	/* 0x2d54: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_2d5d:
	/* 0x2d5d: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d62:
	/* 0x2d62: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2d68:
	/* 0x2d68: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2d6f:
	/* 0x2d6f: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2d74:
	/* 0x2d74: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d79:
	/* 0x2d79: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_2d82:
	/* 0x2d82: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2d88:
	/* 0x2d88: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d8d:
	/* 0x2d8d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d92:
	/* 0x2d92: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d97:
	/* 0x2d97: jmp    3086 <generic_sleepable_preload+0x3086> */
	goto x86_l_3086;
x86_l_2d9c:
	/* 0x2d9c: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2d9f:
	/* 0x2d9f: je     2dc4 <generic_sleepable_preload+0x2dc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dc4;
	}
x86_l_2da1:
	/* 0x2da1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2da6:
	/* 0x2da6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2dab:
	/* 0x2dab: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2db0:
	/* 0x2db0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2db5:
	/* 0x2db5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dba:
	/* 0x2dba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dbc:
	/* 0x2dbc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dbe:
	/* 0x2dbe: js     3e64 <generic_sleepable_preload+0x3e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15972ULL;
	}
x86_l_2dc4:
	/* 0x2dc4: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2dcd:
	/* 0x2dcd: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2dd3:
	/* 0x2dd3: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2dda:
	/* 0x2dda: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2ddf:
	/* 0x2ddf: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2de4:
	/* 0x2de4: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2ded:
	/* 0x2ded: je     2e12 <generic_sleepable_preload+0x2e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e12;
	}
x86_l_2def:
	/* 0x2def: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2df4:
	/* 0x2df4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2df9:
	/* 0x2df9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2dfe:
	/* 0x2dfe: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e03:
	/* 0x2e03: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e08:
	/* 0x2e08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e0a:
	/* 0x2e0a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e0c:
	/* 0x2e0c: js     5405 <generic_sleepable_preload+0x5405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21509ULL;
	}
x86_l_2e12:
	/* 0x2e12: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2e1b:
	/* 0x2e1b: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2e21:
	/* 0x2e21: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2e28:
	/* 0x2e28: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2e2d:
	/* 0x2e2d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e32:
	/* 0x2e32: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2e3b:
	/* 0x2e3b: je     2e60 <generic_sleepable_preload+0x2e60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e60;
	}
x86_l_2e3d:
	/* 0x2e3d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e42:
	/* 0x2e42: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e47:
	/* 0x2e47: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e4c:
	/* 0x2e4c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e51:
	/* 0x2e51: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e56:
	/* 0x2e56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e58:
	/* 0x2e58: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e5a:
	/* 0x2e5a: js     60ec <generic_sleepable_preload+0x60ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24812ULL;
	}
x86_l_2e60:
	/* 0x2e60: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2e69:
	/* 0x2e69: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2e6f:
	/* 0x2e6f: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2e76:
	/* 0x2e76: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2e7b:
	/* 0x2e7b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e80:
	/* 0x2e80: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2e89:
	/* 0x2e89: je     2eae <generic_sleepable_preload+0x2eae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eae;
	}
x86_l_2e8b:
	/* 0x2e8b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e90:
	/* 0x2e90: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e95:
	/* 0x2e95: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e9a:
	/* 0x2e9a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e9f:
	/* 0x2e9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea4:
	/* 0x2ea4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea6:
	/* 0x2ea6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ea8:
	/* 0x2ea8: js     6150 <generic_sleepable_preload+0x6150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24912ULL;
	}
x86_l_2eae:
	/* 0x2eae: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2eb7:
	/* 0x2eb7: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2ebd:
	/* 0x2ebd: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2ec4:
	/* 0x2ec4: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2ec9:
	/* 0x2ec9: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ece:
	/* 0x2ece: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2ed7:
	/* 0x2ed7: je     2efc <generic_sleepable_preload+0x2efc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2efc;
	}
x86_l_2ed9:
	/* 0x2ed9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ede:
	/* 0x2ede: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ee3:
	/* 0x2ee3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ee8:
	/* 0x2ee8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eed:
	/* 0x2eed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ef2:
	/* 0x2ef2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef4:
	/* 0x2ef4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ef6:
	/* 0x2ef6: js     61b4 <generic_sleepable_preload+0x61b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25012ULL;
	}
x86_l_2efc:
	/* 0x2efc: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2f05:
	/* 0x2f05: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2f0b:
	/* 0x2f0b: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2f12:
	/* 0x2f12: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2f17:
	/* 0x2f17: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f1c:
	/* 0x2f1c: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2f25:
	/* 0x2f25: je     2f4a <generic_sleepable_preload+0x2f4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f4a;
	}
x86_l_2f27:
	/* 0x2f27: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f2c:
	/* 0x2f2c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f31:
	/* 0x2f31: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f36:
	/* 0x2f36: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f3b:
	/* 0x2f3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f40:
	/* 0x2f40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f42:
	/* 0x2f42: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f44:
	/* 0x2f44: js     6215 <generic_sleepable_preload+0x6215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25109ULL;
	}
x86_l_2f4a:
	/* 0x2f4a: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2f53:
	/* 0x2f53: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2f59:
	/* 0x2f59: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2f60:
	/* 0x2f60: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2f65:
	/* 0x2f65: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f6a:
	/* 0x2f6a: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2f73:
	/* 0x2f73: je     2f98 <generic_sleepable_preload+0x2f98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f98;
	}
x86_l_2f75:
	/* 0x2f75: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f7a:
	/* 0x2f7a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f7f:
	/* 0x2f7f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f84:
	/* 0x2f84: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f89:
	/* 0x2f89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f8e:
	/* 0x2f8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f90:
	/* 0x2f90: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f92:
	/* 0x2f92: js     637f <generic_sleepable_preload+0x637f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25471ULL;
	}
x86_l_2f98:
	/* 0x2f98: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2fa1:
	/* 0x2fa1: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2fa7:
	/* 0x2fa7: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2fae:
	/* 0x2fae: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2fb3:
	/* 0x2fb3: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fb8:
	/* 0x2fb8: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2fc1:
	/* 0x2fc1: je     2fe6 <generic_sleepable_preload+0x2fe6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fe6;
	}
x86_l_2fc3:
	/* 0x2fc3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fc8:
	/* 0x2fc8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2fcd:
	/* 0x2fcd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2fd2:
	/* 0x2fd2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fd7:
	/* 0x2fd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fdc:
	/* 0x2fdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fde:
	/* 0x2fde: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fe0:
	/* 0x2fe0: js     69d9 <generic_sleepable_preload+0x69d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27097ULL;
	}
x86_l_2fe6:
	/* 0x2fe6: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2feb:
	/* 0x2feb: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_2ff4:
	/* 0x2ff4: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ff9:
	/* 0x2ff9: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_2fff:
	/* 0x2fff: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3006:
	/* 0x3006: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_300b:
	/* 0x300b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3010:
	/* 0x3010: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3019:
	/* 0x3019: je     303e <generic_sleepable_preload+0x303e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_303e;
	}
x86_l_301b:
	/* 0x301b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3020:
	/* 0x3020: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3025:
	/* 0x3025: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_302a:
	/* 0x302a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_302f:
	/* 0x302f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3034:
	/* 0x3034: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3036:
	/* 0x3036: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3038:
	/* 0x3038: js     693f <generic_sleepable_preload+0x693f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26943ULL;
	}
x86_l_303e:
	/* 0x303e: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3043:
	/* 0x3043: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_304c:
	/* 0x304c: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3051:
	/* 0x3051: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_3057:
	/* 0x3057: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_305e:
	/* 0x305e: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3063:
	/* 0x3063: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3068:
	/* 0x3068: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3071:
	/* 0x3071: je     6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25478ULL;
	}
x86_l_3077:
	/* 0x3077: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_307c:
	/* 0x307c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3081:
	/* 0x3081: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3086:
	/* 0x3086: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_308b:
	/* 0x308b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3090:
	/* 0x3090: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3092:
	/* 0x3092: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3094:
	/* 0x3094: jns    6386 <generic_sleepable_preload+0x6386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25478ULL;
	}
x86_l_309a:
	/* 0x309a: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_309f:
	/* 0x309f: jmp    6384 <generic_sleepable_preload+0x6384> */
	return 25476ULL;
x86_l_30a4:
	/* 0x30a4: mov    edx,DWORD PTR [r13+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_30ab:
	/* 0x30ab: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30b1:
	/* 0x30b1: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30b4:
	/* 0x30b4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30b9:
	/* 0x30b9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_30be:
	/* 0x30be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30c3:
	/* 0x30c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30c8:
	/* 0x30c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ca:
	/* 0x30ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30cc:
	/* 0x30cc: jne    3156 <generic_sleepable_preload+0x3156> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3156;
	}
x86_l_30d2:
	/* 0x30d2: mov    edx,DWORD PTR [r13+0x254] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 596ULL);
x86_l_30d9:
	/* 0x30d9: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30df:
	/* 0x30df: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30e2:
	/* 0x30e2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30e7:
	/* 0x30e7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_30ec:
	/* 0x30ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30f1:
	/* 0x30f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30f6:
	/* 0x30f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30f8:
	/* 0x30f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30fa:
	/* 0x30fa: jne    3156 <generic_sleepable_preload+0x3156> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3156;
	}
x86_l_30fc:
	/* 0x30fc: movzx  eax,BYTE PTR [r13+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_3104:
	/* 0x3104: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_310b:
	/* 0x310b: mov    rcx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_3112:
	/* 0x3112: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3117:
	/* 0x3117: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_311a:
	/* 0x311a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_311f:
	/* 0x311f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3124:
	/* 0x3124: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3129:
	/* 0x3129: movzx  ecx,BYTE PTR [r13+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_3131:
	/* 0x3131: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_3138:
	/* 0x3138: mov    rdx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_313f:
	/* 0x313f: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3144:
	/* 0x3144: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3147:
	/* 0x3147: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_314c:
	/* 0x314c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314e:
	/* 0x314e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3150:
	/* 0x3150: je     1c14 <generic_sleepable_preload+0x1c14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7188ULL;
	}
x86_l_3156:
	/* 0x3156: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3159:
	/* 0x3159: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_315e:
	/* 0x315e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3160:
	/* 0x3160: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_3163:
	/* 0x3163: cmp    WORD PTR [r13+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_316c:
	/* 0x316c: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_3172:
	/* 0x3172: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3179:
	/* 0x3179: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_317c:
	/* 0x317c: mov    eax,DWORD PTR [r13+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_3183:
	/* 0x3183: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3186:
	/* 0x3186: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_318b:
	/* 0x318b: movzx  eax,WORD PTR [r13+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_3193:
	/* 0x3193: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_3195:
	/* 0x3195: je     347b <generic_sleepable_preload+0x347b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13435ULL;
	}
x86_l_319b:
	/* 0x319b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_319e:
	/* 0x319e: je     31c3 <generic_sleepable_preload+0x31c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31c3;
	}
x86_l_31a0:
	/* 0x31a0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31a5:
	/* 0x31a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31aa:
	/* 0x31aa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31af:
	/* 0x31af: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31b4:
	/* 0x31b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31b9:
	/* 0x31b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31bb:
	/* 0x31bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31bd:
	/* 0x31bd: js     3e6e <generic_sleepable_preload+0x3e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15982ULL;
	}
x86_l_31c3:
	/* 0x31c3: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_31cc:
	/* 0x31cc: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_31d2:
	/* 0x31d2: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_31d9:
	/* 0x31d9: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_31de:
	/* 0x31de: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31e3:
	/* 0x31e3: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_31ec:
	/* 0x31ec: je     3211 <generic_sleepable_preload+0x3211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3211;
	}
x86_l_31ee:
	/* 0x31ee: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31f3:
	/* 0x31f3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31f8:
	/* 0x31f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31fd:
	/* 0x31fd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3202:
	/* 0x3202: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3207:
	/* 0x3207: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3209:
	/* 0x3209: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_320b:
	/* 0x320b: js     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21519ULL;
	}
x86_l_3211:
	/* 0x3211: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_321a:
	/* 0x321a: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_3220:
	/* 0x3220: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3227:
	/* 0x3227: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_322c:
	/* 0x322c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3231:
	/* 0x3231: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_323a:
	/* 0x323a: je     325f <generic_sleepable_preload+0x325f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_325f;
	}
x86_l_323c:
	/* 0x323c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3241:
	/* 0x3241: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3246:
	/* 0x3246: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_324b:
	/* 0x324b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3250:
	/* 0x3250: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3255:
	/* 0x3255: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3257:
	/* 0x3257: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3259:
	/* 0x3259: js     60f6 <generic_sleepable_preload+0x60f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24822ULL;
	}
x86_l_325f:
	/* 0x325f: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3268:
	/* 0x3268: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_326e:
	/* 0x326e: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3275:
	/* 0x3275: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_327a:
	/* 0x327a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_327f:
	/* 0x327f: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_3288:
	/* 0x3288: je     32ad <generic_sleepable_preload+0x32ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ad;
	}
x86_l_328a:
	/* 0x328a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_328f:
	/* 0x328f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3294:
	/* 0x3294: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3299:
	/* 0x3299: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_329e:
	/* 0x329e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32a3:
	/* 0x32a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a5:
	/* 0x32a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32a7:
	/* 0x32a7: js     615a <generic_sleepable_preload+0x615a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24922ULL;
	}
x86_l_32ad:
	/* 0x32ad: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_32b6:
	/* 0x32b6: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_32bc:
	/* 0x32bc: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_32c3:
	/* 0x32c3: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_32c8:
	/* 0x32c8: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32cd:
	/* 0x32cd: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_32d6:
	/* 0x32d6: je     32fb <generic_sleepable_preload+0x32fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32fb;
	}
x86_l_32d8:
	/* 0x32d8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32dd:
	/* 0x32dd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32e2:
	/* 0x32e2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32e7:
	/* 0x32e7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32ec:
	/* 0x32ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32f1:
	/* 0x32f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32f3:
	/* 0x32f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32f5:
	/* 0x32f5: js     61be <generic_sleepable_preload+0x61be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25022ULL;
	}
x86_l_32fb:
	/* 0x32fb: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_3304:
	/* 0x3304: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_330a:
	/* 0x330a: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_3311:
	/* 0x3311: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3316:
	/* 0x3316: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_331b:
	/* 0x331b: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_3324:
	/* 0x3324: je     3349 <generic_sleepable_preload+0x3349> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13129ULL;
	}
x86_l_3326:
	/* 0x3326: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_332b:
	/* 0x332b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3330:
	/* 0x3330: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3335:
	/* 0x3335: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 13114ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13114ULL: goto x86_l_333a;
	case 13119ULL: goto x86_l_333f;
	case 13121ULL: goto x86_l_3341;
	case 13123ULL: goto x86_l_3343;
	case 13129ULL: goto x86_l_3349;
	case 13138ULL: goto x86_l_3352;
	case 13144ULL: goto x86_l_3358;
	case 13151ULL: goto x86_l_335f;
	case 13156ULL: goto x86_l_3364;
	case 13161ULL: goto x86_l_3369;
	case 13170ULL: goto x86_l_3372;
	case 13172ULL: goto x86_l_3374;
	case 13177ULL: goto x86_l_3379;
	case 13182ULL: goto x86_l_337e;
	case 13187ULL: goto x86_l_3383;
	case 13192ULL: goto x86_l_3388;
	case 13197ULL: goto x86_l_338d;
	case 13199ULL: goto x86_l_338f;
	case 13201ULL: goto x86_l_3391;
	case 13207ULL: goto x86_l_3397;
	case 13216ULL: goto x86_l_33a0;
	case 13222ULL: goto x86_l_33a6;
	case 13229ULL: goto x86_l_33ad;
	case 13234ULL: goto x86_l_33b2;
	case 13239ULL: goto x86_l_33b7;
	case 13248ULL: goto x86_l_33c0;
	case 13250ULL: goto x86_l_33c2;
	case 13255ULL: goto x86_l_33c7;
	case 13260ULL: goto x86_l_33cc;
	case 13265ULL: goto x86_l_33d1;
	case 13270ULL: goto x86_l_33d6;
	case 13275ULL: goto x86_l_33db;
	case 13277ULL: goto x86_l_33dd;
	case 13279ULL: goto x86_l_33df;
	case 13285ULL: goto x86_l_33e5;
	case 13294ULL: goto x86_l_33ee;
	case 13300ULL: goto x86_l_33f4;
	case 13307ULL: goto x86_l_33fb;
	case 13312ULL: goto x86_l_3400;
	case 13317ULL: goto x86_l_3405;
	case 13326ULL: goto x86_l_340e;
	case 13328ULL: goto x86_l_3410;
	case 13333ULL: goto x86_l_3415;
	case 13338ULL: goto x86_l_341a;
	case 13343ULL: goto x86_l_341f;
	case 13348ULL: goto x86_l_3424;
	case 13353ULL: goto x86_l_3429;
	case 13355ULL: goto x86_l_342b;
	case 13357ULL: goto x86_l_342d;
	case 13363ULL: goto x86_l_3433;
	case 13368ULL: goto x86_l_3438;
	case 13377ULL: goto x86_l_3441;
	case 13383ULL: goto x86_l_3447;
	case 13390ULL: goto x86_l_344e;
	case 13395ULL: goto x86_l_3453;
	case 13400ULL: goto x86_l_3458;
	case 13409ULL: goto x86_l_3461;
	case 13415ULL: goto x86_l_3467;
	case 13420ULL: goto x86_l_346c;
	case 13425ULL: goto x86_l_3471;
	case 13430ULL: goto x86_l_3476;
	case 13435ULL: goto x86_l_347b;
	case 13438ULL: goto x86_l_347e;
	case 13440ULL: goto x86_l_3480;
	case 13445ULL: goto x86_l_3485;
	case 13450ULL: goto x86_l_348a;
	case 13455ULL: goto x86_l_348f;
	case 13460ULL: goto x86_l_3494;
	case 13465ULL: goto x86_l_3499;
	case 13467ULL: goto x86_l_349b;
	case 13469ULL: goto x86_l_349d;
	case 13475ULL: goto x86_l_34a3;
	case 13484ULL: goto x86_l_34ac;
	case 13490ULL: goto x86_l_34b2;
	case 13497ULL: goto x86_l_34b9;
	case 13502ULL: goto x86_l_34be;
	case 13507ULL: goto x86_l_34c3;
	case 13516ULL: goto x86_l_34cc;
	case 13518ULL: goto x86_l_34ce;
	case 13523ULL: goto x86_l_34d3;
	case 13528ULL: goto x86_l_34d8;
	case 13533ULL: goto x86_l_34dd;
	case 13538ULL: goto x86_l_34e2;
	case 13543ULL: goto x86_l_34e7;
	case 13545ULL: goto x86_l_34e9;
	case 13547ULL: goto x86_l_34eb;
	case 13553ULL: goto x86_l_34f1;
	case 13562ULL: goto x86_l_34fa;
	case 13568ULL: goto x86_l_3500;
	case 13575ULL: goto x86_l_3507;
	case 13580ULL: goto x86_l_350c;
	case 13585ULL: goto x86_l_3511;
	case 13594ULL: goto x86_l_351a;
	case 13596ULL: goto x86_l_351c;
	case 13601ULL: goto x86_l_3521;
	case 13606ULL: goto x86_l_3526;
	case 13611ULL: goto x86_l_352b;
	case 13616ULL: goto x86_l_3530;
	case 13621ULL: goto x86_l_3535;
	case 13623ULL: goto x86_l_3537;
	case 13625ULL: goto x86_l_3539;
	case 13631ULL: goto x86_l_353f;
	case 13640ULL: goto x86_l_3548;
	case 13646ULL: goto x86_l_354e;
	case 13653ULL: goto x86_l_3555;
	case 13658ULL: goto x86_l_355a;
	case 13663ULL: goto x86_l_355f;
	case 13672ULL: goto x86_l_3568;
	case 13674ULL: goto x86_l_356a;
	case 13679ULL: goto x86_l_356f;
	case 13684ULL: goto x86_l_3574;
	case 13689ULL: goto x86_l_3579;
	case 13694ULL: goto x86_l_357e;
	case 13699ULL: goto x86_l_3583;
	case 13701ULL: goto x86_l_3585;
	case 13703ULL: goto x86_l_3587;
	case 13709ULL: goto x86_l_358d;
	case 13718ULL: goto x86_l_3596;
	case 13724ULL: goto x86_l_359c;
	case 13731ULL: goto x86_l_35a3;
	case 13736ULL: goto x86_l_35a8;
	case 13741ULL: goto x86_l_35ad;
	case 13750ULL: goto x86_l_35b6;
	case 13752ULL: goto x86_l_35b8;
	case 13757ULL: goto x86_l_35bd;
	case 13762ULL: goto x86_l_35c2;
	case 13767ULL: goto x86_l_35c7;
	case 13772ULL: goto x86_l_35cc;
	case 13777ULL: goto x86_l_35d1;
	case 13779ULL: goto x86_l_35d3;
	case 13781ULL: goto x86_l_35d5;
	case 13787ULL: goto x86_l_35db;
	case 13796ULL: goto x86_l_35e4;
	case 13802ULL: goto x86_l_35ea;
	case 13809ULL: goto x86_l_35f1;
	case 13814ULL: goto x86_l_35f6;
	case 13819ULL: goto x86_l_35fb;
	case 13828ULL: goto x86_l_3604;
	case 13830ULL: goto x86_l_3606;
	case 13835ULL: goto x86_l_360b;
	case 13840ULL: goto x86_l_3610;
	case 13845ULL: goto x86_l_3615;
	case 13850ULL: goto x86_l_361a;
	case 13855ULL: goto x86_l_361f;
	case 13857ULL: goto x86_l_3621;
	case 13859ULL: goto x86_l_3623;
	case 13865ULL: goto x86_l_3629;
	case 13874ULL: goto x86_l_3632;
	case 13880ULL: goto x86_l_3638;
	case 13887ULL: goto x86_l_363f;
	case 13892ULL: goto x86_l_3644;
	case 13897ULL: goto x86_l_3649;
	case 13906ULL: goto x86_l_3652;
	case 13908ULL: goto x86_l_3654;
	case 13913ULL: goto x86_l_3659;
	case 13918ULL: goto x86_l_365e;
	case 13923ULL: goto x86_l_3663;
	case 13928ULL: goto x86_l_3668;
	case 13933ULL: goto x86_l_366d;
	case 13935ULL: goto x86_l_366f;
	case 13937ULL: goto x86_l_3671;
	case 13943ULL: goto x86_l_3677;
	case 13952ULL: goto x86_l_3680;
	case 13958ULL: goto x86_l_3686;
	case 13965ULL: goto x86_l_368d;
	case 13970ULL: goto x86_l_3692;
	case 13975ULL: goto x86_l_3697;
	case 13984ULL: goto x86_l_36a0;
	case 13986ULL: goto x86_l_36a2;
	case 13991ULL: goto x86_l_36a7;
	case 13996ULL: goto x86_l_36ac;
	case 14001ULL: goto x86_l_36b1;
	case 14006ULL: goto x86_l_36b6;
	case 14011ULL: goto x86_l_36bb;
	case 14013ULL: goto x86_l_36bd;
	case 14015ULL: goto x86_l_36bf;
	case 14021ULL: goto x86_l_36c5;
	case 14026ULL: goto x86_l_36ca;
	case 14035ULL: goto x86_l_36d3;
	case 14041ULL: goto x86_l_36d9;
	case 14048ULL: goto x86_l_36e0;
	case 14053ULL: goto x86_l_36e5;
	case 14058ULL: goto x86_l_36ea;
	case 14067ULL: goto x86_l_36f3;
	case 14069ULL: goto x86_l_36f5;
	case 14074ULL: goto x86_l_36fa;
	case 14079ULL: goto x86_l_36ff;
	case 14084ULL: goto x86_l_3704;
	case 14089ULL: goto x86_l_3709;
	case 14094ULL: goto x86_l_370e;
	case 14096ULL: goto x86_l_3710;
	case 14098ULL: goto x86_l_3712;
	case 14104ULL: goto x86_l_3718;
	case 14109ULL: goto x86_l_371d;
	case 14118ULL: goto x86_l_3726;
	case 14124ULL: goto x86_l_372c;
	case 14131ULL: goto x86_l_3733;
	case 14136ULL: goto x86_l_3738;
	case 14141ULL: goto x86_l_373d;
	case 14150ULL: goto x86_l_3746;
	case 14156ULL: goto x86_l_374c;
	case 14161ULL: goto x86_l_3751;
	case 14166ULL: goto x86_l_3756;
	case 14171ULL: goto x86_l_375b;
	case 14176ULL: goto x86_l_3760;
	case 14181ULL: goto x86_l_3765;
	case 14183ULL: goto x86_l_3767;
	case 14185ULL: goto x86_l_3769;
	case 14191ULL: goto x86_l_376f;
	case 14196ULL: goto x86_l_3774;
	case 14201ULL: goto x86_l_3779;
	case 14208ULL: goto x86_l_3780;
	case 14214ULL: goto x86_l_3786;
	case 14217ULL: goto x86_l_3789;
	case 14222ULL: goto x86_l_378e;
	case 14227ULL: goto x86_l_3793;
	case 14232ULL: goto x86_l_3798;
	case 14237ULL: goto x86_l_379d;
	case 14239ULL: goto x86_l_379f;
	case 14241ULL: goto x86_l_37a1;
	case 14247ULL: goto x86_l_37a7;
	case 14254ULL: goto x86_l_37ae;
	case 14259ULL: goto x86_l_37b3;
	case 14262ULL: goto x86_l_37b6;
	case 14267ULL: goto x86_l_37bb;
	case 14272ULL: goto x86_l_37c0;
	case 14277ULL: goto x86_l_37c5;
	case 14282ULL: goto x86_l_37ca;
	case 14285ULL: goto x86_l_37cd;
	case 14287ULL: goto x86_l_37cf;
	case 14289ULL: goto x86_l_37d1;
	case 14291ULL: goto x86_l_37d3;
	case 14299ULL: goto x86_l_37db;
	case 14306ULL: goto x86_l_37e2;
	case 14313ULL: goto x86_l_37e9;
	case 14318ULL: goto x86_l_37ee;
	case 14321ULL: goto x86_l_37f1;
	case 14326ULL: goto x86_l_37f6;
	case 14331ULL: goto x86_l_37fb;
	case 14336ULL: goto x86_l_3800;
	case 14344ULL: goto x86_l_3808;
	case 14351ULL: goto x86_l_380f;
	case 14358ULL: goto x86_l_3816;
	case 14363ULL: goto x86_l_381b;
	case 14366ULL: goto x86_l_381e;
	case 14371ULL: goto x86_l_3823;
	case 14373ULL: goto x86_l_3825;
	case 14375ULL: goto x86_l_3827;
	case 14381ULL: goto x86_l_382d;
	case 14384ULL: goto x86_l_3830;
	case 14389ULL: goto x86_l_3835;
	case 14391ULL: goto x86_l_3837;
	case 14394ULL: goto x86_l_383a;
	case 14403ULL: goto x86_l_3843;
	case 14409ULL: goto x86_l_3849;
	case 14416ULL: goto x86_l_3850;
	case 14419ULL: goto x86_l_3853;
	case 14426ULL: goto x86_l_385a;
	case 14429ULL: goto x86_l_385d;
	case 14434ULL: goto x86_l_3862;
	case 14442ULL: goto x86_l_386a;
	case 14444ULL: goto x86_l_386c;
	case 14450ULL: goto x86_l_3872;
	case 14453ULL: goto x86_l_3875;
	case 14455ULL: goto x86_l_3877;
	case 14460ULL: goto x86_l_387c;
	case 14465ULL: goto x86_l_3881;
	case 14470ULL: goto x86_l_3886;
	case 14475ULL: goto x86_l_388b;
	case 14480ULL: goto x86_l_3890;
	case 14482ULL: goto x86_l_3892;
	case 14484ULL: goto x86_l_3894;
	case 14490ULL: goto x86_l_389a;
	case 14499ULL: goto x86_l_38a3;
	case 14505ULL: goto x86_l_38a9;
	case 14512ULL: goto x86_l_38b0;
	case 14517ULL: goto x86_l_38b5;
	case 14522ULL: goto x86_l_38ba;
	case 14531ULL: goto x86_l_38c3;
	case 14533ULL: goto x86_l_38c5;
	case 14538ULL: goto x86_l_38ca;
	case 14543ULL: goto x86_l_38cf;
	case 14548ULL: goto x86_l_38d4;
	case 14553ULL: goto x86_l_38d9;
	case 14558ULL: goto x86_l_38de;
	case 14560ULL: goto x86_l_38e0;
	case 14562ULL: goto x86_l_38e2;
	case 14568ULL: goto x86_l_38e8;
	case 14577ULL: goto x86_l_38f1;
	case 14583ULL: goto x86_l_38f7;
	case 14590ULL: goto x86_l_38fe;
	case 14595ULL: goto x86_l_3903;
	case 14600ULL: goto x86_l_3908;
	case 14609ULL: goto x86_l_3911;
	case 14611ULL: goto x86_l_3913;
	case 14616ULL: goto x86_l_3918;
	case 14621ULL: goto x86_l_391d;
	case 14626ULL: goto x86_l_3922;
	case 14631ULL: goto x86_l_3927;
	case 14636ULL: goto x86_l_392c;
	case 14638ULL: goto x86_l_392e;
	case 14640ULL: goto x86_l_3930;
	case 14646ULL: goto x86_l_3936;
	case 14655ULL: goto x86_l_393f;
	case 14661ULL: goto x86_l_3945;
	case 14668ULL: goto x86_l_394c;
	case 14673ULL: goto x86_l_3951;
	case 14678ULL: goto x86_l_3956;
	case 14687ULL: goto x86_l_395f;
	case 14689ULL: goto x86_l_3961;
	case 14694ULL: goto x86_l_3966;
	case 14699ULL: goto x86_l_396b;
	case 14704ULL: goto x86_l_3970;
	case 14709ULL: goto x86_l_3975;
	case 14714ULL: goto x86_l_397a;
	case 14716ULL: goto x86_l_397c;
	case 14718ULL: goto x86_l_397e;
	case 14724ULL: goto x86_l_3984;
	case 14733ULL: goto x86_l_398d;
	case 14739ULL: goto x86_l_3993;
	case 14746ULL: goto x86_l_399a;
	case 14751ULL: goto x86_l_399f;
	case 14756ULL: goto x86_l_39a4;
	case 14765ULL: goto x86_l_39ad;
	case 14767ULL: goto x86_l_39af;
	case 14772ULL: goto x86_l_39b4;
	case 14777ULL: goto x86_l_39b9;
	case 14782ULL: goto x86_l_39be;
	case 14787ULL: goto x86_l_39c3;
	case 14792ULL: goto x86_l_39c8;
	case 14794ULL: goto x86_l_39ca;
	case 14796ULL: goto x86_l_39cc;
	case 14802ULL: goto x86_l_39d2;
	case 14811ULL: goto x86_l_39db;
	case 14817ULL: goto x86_l_39e1;
	case 14824ULL: goto x86_l_39e8;
	case 14829ULL: goto x86_l_39ed;
	case 14834ULL: goto x86_l_39f2;
	case 14843ULL: goto x86_l_39fb;
	case 14845ULL: goto x86_l_39fd;
	case 14850ULL: goto x86_l_3a02;
	case 14855ULL: goto x86_l_3a07;
	case 14860ULL: goto x86_l_3a0c;
	case 14865ULL: goto x86_l_3a11;
	case 14870ULL: goto x86_l_3a16;
	case 14872ULL: goto x86_l_3a18;
	case 14874ULL: goto x86_l_3a1a;
	case 14880ULL: goto x86_l_3a20;
	case 14889ULL: goto x86_l_3a29;
	case 14895ULL: goto x86_l_3a2f;
	case 14902ULL: goto x86_l_3a36;
	case 14907ULL: goto x86_l_3a3b;
	case 14912ULL: goto x86_l_3a40;
	case 14921ULL: goto x86_l_3a49;
	case 14923ULL: goto x86_l_3a4b;
	case 14928ULL: goto x86_l_3a50;
	case 14933ULL: goto x86_l_3a55;
	case 14938ULL: goto x86_l_3a5a;
	case 14943ULL: goto x86_l_3a5f;
	case 14948ULL: goto x86_l_3a64;
	case 14950ULL: goto x86_l_3a66;
	case 14952ULL: goto x86_l_3a68;
	case 14958ULL: goto x86_l_3a6e;
	case 14967ULL: goto x86_l_3a77;
	case 14973ULL: goto x86_l_3a7d;
	case 14980ULL: goto x86_l_3a84;
	case 14985ULL: goto x86_l_3a89;
	case 14990ULL: goto x86_l_3a8e;
	case 14999ULL: goto x86_l_3a97;
	case 15001ULL: goto x86_l_3a99;
	case 15006ULL: goto x86_l_3a9e;
	case 15011ULL: goto x86_l_3aa3;
	case 15016ULL: goto x86_l_3aa8;
	case 15021ULL: goto x86_l_3aad;
	case 15026ULL: goto x86_l_3ab2;
	case 15028ULL: goto x86_l_3ab4;
	case 15030ULL: goto x86_l_3ab6;
	case 15036ULL: goto x86_l_3abc;
	case 15045ULL: goto x86_l_3ac5;
	case 15051ULL: goto x86_l_3acb;
	case 15058ULL: goto x86_l_3ad2;
	case 15063ULL: goto x86_l_3ad7;
	case 15068ULL: goto x86_l_3adc;
	case 15077ULL: goto x86_l_3ae5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_333a:
	/* 0x333a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_333f:
	/* 0x333f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3341:
	/* 0x3341: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3343:
	/* 0x3343: js     621f <generic_sleepable_preload+0x621f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25119ULL;
	}
x86_l_3349:
	/* 0x3349: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_3352:
	/* 0x3352: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_3358:
	/* 0x3358: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_335f:
	/* 0x335f: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3364:
	/* 0x3364: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3369:
	/* 0x3369: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_3372:
	/* 0x3372: je     3397 <generic_sleepable_preload+0x3397> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3397;
	}
x86_l_3374:
	/* 0x3374: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3379:
	/* 0x3379: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_337e:
	/* 0x337e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3383:
	/* 0x3383: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3388:
	/* 0x3388: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_338d:
	/* 0x338d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_338f:
	/* 0x338f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3391:
	/* 0x3391: js     640c <generic_sleepable_preload+0x640c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25612ULL;
	}
x86_l_3397:
	/* 0x3397: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_33a0:
	/* 0x33a0: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_33a6:
	/* 0x33a6: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_33ad:
	/* 0x33ad: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33b2:
	/* 0x33b2: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33b7:
	/* 0x33b7: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_33c0:
	/* 0x33c0: je     33e5 <generic_sleepable_preload+0x33e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33e5;
	}
x86_l_33c2:
	/* 0x33c2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33c7:
	/* 0x33c7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33cc:
	/* 0x33cc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33d1:
	/* 0x33d1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33d6:
	/* 0x33d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33db:
	/* 0x33db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33dd:
	/* 0x33dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33df:
	/* 0x33df: js     68d9 <generic_sleepable_preload+0x68d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26841ULL;
	}
x86_l_33e5:
	/* 0x33e5: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_33ee:
	/* 0x33ee: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_33f4:
	/* 0x33f4: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_33fb:
	/* 0x33fb: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3400:
	/* 0x3400: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3405:
	/* 0x3405: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_340e:
	/* 0x340e: je     3433 <generic_sleepable_preload+0x3433> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3433;
	}
x86_l_3410:
	/* 0x3410: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3415:
	/* 0x3415: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_341a:
	/* 0x341a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_341f:
	/* 0x341f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3424:
	/* 0x3424: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3429:
	/* 0x3429: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_342b:
	/* 0x342b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_342d:
	/* 0x342d: js     694b <generic_sleepable_preload+0x694b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26955ULL;
	}
x86_l_3433:
	/* 0x3433: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3438:
	/* 0x3438: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_3441:
	/* 0x3441: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_3447:
	/* 0x3447: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_344e:
	/* 0x344e: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3453:
	/* 0x3453: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3458:
	/* 0x3458: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_3461:
	/* 0x3461: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_3467:
	/* 0x3467: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_346c:
	/* 0x346c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3471:
	/* 0x3471: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3476:
	/* 0x3476: jmp    375b <generic_sleepable_preload+0x375b> */
	goto x86_l_375b;
x86_l_347b:
	/* 0x347b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_347e:
	/* 0x347e: je     34a3 <generic_sleepable_preload+0x34a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34a3;
	}
x86_l_3480:
	/* 0x3480: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3485:
	/* 0x3485: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_348a:
	/* 0x348a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_348f:
	/* 0x348f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3494:
	/* 0x3494: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3499:
	/* 0x3499: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_349b:
	/* 0x349b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_349d:
	/* 0x349d: js     3e6e <generic_sleepable_preload+0x3e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15982ULL;
	}
x86_l_34a3:
	/* 0x34a3: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_34ac:
	/* 0x34ac: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_34b2:
	/* 0x34b2: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_34b9:
	/* 0x34b9: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_34be:
	/* 0x34be: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34c3:
	/* 0x34c3: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_34cc:
	/* 0x34cc: je     34f1 <generic_sleepable_preload+0x34f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34f1;
	}
x86_l_34ce:
	/* 0x34ce: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34d3:
	/* 0x34d3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34d8:
	/* 0x34d8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34dd:
	/* 0x34dd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34e2:
	/* 0x34e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34e7:
	/* 0x34e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34e9:
	/* 0x34e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34eb:
	/* 0x34eb: js     540f <generic_sleepable_preload+0x540f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21519ULL;
	}
x86_l_34f1:
	/* 0x34f1: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_34fa:
	/* 0x34fa: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_3500:
	/* 0x3500: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3507:
	/* 0x3507: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_350c:
	/* 0x350c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3511:
	/* 0x3511: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_351a:
	/* 0x351a: je     353f <generic_sleepable_preload+0x353f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_353f;
	}
x86_l_351c:
	/* 0x351c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3521:
	/* 0x3521: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3526:
	/* 0x3526: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_352b:
	/* 0x352b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3530:
	/* 0x3530: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3535:
	/* 0x3535: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3537:
	/* 0x3537: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3539:
	/* 0x3539: js     60f6 <generic_sleepable_preload+0x60f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24822ULL;
	}
x86_l_353f:
	/* 0x353f: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3548:
	/* 0x3548: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_354e:
	/* 0x354e: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3555:
	/* 0x3555: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_355a:
	/* 0x355a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_355f:
	/* 0x355f: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_3568:
	/* 0x3568: je     358d <generic_sleepable_preload+0x358d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_358d;
	}
x86_l_356a:
	/* 0x356a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_356f:
	/* 0x356f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3574:
	/* 0x3574: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3579:
	/* 0x3579: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_357e:
	/* 0x357e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3583:
	/* 0x3583: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3585:
	/* 0x3585: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3587:
	/* 0x3587: js     615a <generic_sleepable_preload+0x615a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24922ULL;
	}
x86_l_358d:
	/* 0x358d: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_3596:
	/* 0x3596: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_359c:
	/* 0x359c: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_35a3:
	/* 0x35a3: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_35a8:
	/* 0x35a8: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35ad:
	/* 0x35ad: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_35b6:
	/* 0x35b6: je     35db <generic_sleepable_preload+0x35db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35db;
	}
x86_l_35b8:
	/* 0x35b8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35bd:
	/* 0x35bd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_35c2:
	/* 0x35c2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35c7:
	/* 0x35c7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35cc:
	/* 0x35cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35d1:
	/* 0x35d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35d3:
	/* 0x35d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35d5:
	/* 0x35d5: js     61be <generic_sleepable_preload+0x61be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25022ULL;
	}
x86_l_35db:
	/* 0x35db: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_35e4:
	/* 0x35e4: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_35ea:
	/* 0x35ea: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_35f1:
	/* 0x35f1: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_35f6:
	/* 0x35f6: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35fb:
	/* 0x35fb: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_3604:
	/* 0x3604: je     3629 <generic_sleepable_preload+0x3629> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3629;
	}
x86_l_3606:
	/* 0x3606: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_360b:
	/* 0x360b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3610:
	/* 0x3610: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3615:
	/* 0x3615: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_361a:
	/* 0x361a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_361f:
	/* 0x361f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3621:
	/* 0x3621: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3623:
	/* 0x3623: js     621f <generic_sleepable_preload+0x621f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25119ULL;
	}
x86_l_3629:
	/* 0x3629: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_3632:
	/* 0x3632: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_3638:
	/* 0x3638: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_363f:
	/* 0x363f: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3644:
	/* 0x3644: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3649:
	/* 0x3649: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_3652:
	/* 0x3652: je     3677 <generic_sleepable_preload+0x3677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3677;
	}
x86_l_3654:
	/* 0x3654: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3659:
	/* 0x3659: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_365e:
	/* 0x365e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3663:
	/* 0x3663: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3668:
	/* 0x3668: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_366d:
	/* 0x366d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_366f:
	/* 0x366f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3671:
	/* 0x3671: js     640c <generic_sleepable_preload+0x640c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25612ULL;
	}
x86_l_3677:
	/* 0x3677: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_3680:
	/* 0x3680: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_3686:
	/* 0x3686: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_368d:
	/* 0x368d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3692:
	/* 0x3692: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3697:
	/* 0x3697: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_36a0:
	/* 0x36a0: je     36c5 <generic_sleepable_preload+0x36c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36c5;
	}
x86_l_36a2:
	/* 0x36a2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36a7:
	/* 0x36a7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36ac:
	/* 0x36ac: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36b1:
	/* 0x36b1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36b6:
	/* 0x36b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36bb:
	/* 0x36bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36bd:
	/* 0x36bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36bf:
	/* 0x36bf: js     69ef <generic_sleepable_preload+0x69ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27119ULL;
	}
x86_l_36c5:
	/* 0x36c5: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36ca:
	/* 0x36ca: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_36d3:
	/* 0x36d3: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_36d9:
	/* 0x36d9: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_36e0:
	/* 0x36e0: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_36e5:
	/* 0x36e5: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36ea:
	/* 0x36ea: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_36f3:
	/* 0x36f3: je     3718 <generic_sleepable_preload+0x3718> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3718;
	}
x86_l_36f5:
	/* 0x36f5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36fa:
	/* 0x36fa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36ff:
	/* 0x36ff: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3704:
	/* 0x3704: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3709:
	/* 0x3709: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_370e:
	/* 0x370e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3710:
	/* 0x3710: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3712:
	/* 0x3712: js     694b <generic_sleepable_preload+0x694b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26955ULL;
	}
x86_l_3718:
	/* 0x3718: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_371d:
	/* 0x371d: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_3726:
	/* 0x3726: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_372c:
	/* 0x372c: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_3733:
	/* 0x3733: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3738:
	/* 0x3738: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_373d:
	/* 0x373d: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_3746:
	/* 0x3746: je     6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25619ULL;
	}
x86_l_374c:
	/* 0x374c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3751:
	/* 0x3751: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3756:
	/* 0x3756: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_375b:
	/* 0x375b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3760:
	/* 0x3760: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3765:
	/* 0x3765: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3767:
	/* 0x3767: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3769:
	/* 0x3769: jns    6413 <generic_sleepable_preload+0x6413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25619ULL;
	}
x86_l_376f:
	/* 0x376f: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_3774:
	/* 0x3774: jmp    6411 <generic_sleepable_preload+0x6411> */
	return 25617ULL;
x86_l_3779:
	/* 0x3779: mov    edx,DWORD PTR [r13+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_3780:
	/* 0x3780: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3786:
	/* 0x3786: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3789:
	/* 0x3789: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_378e:
	/* 0x378e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3793:
	/* 0x3793: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3798:
	/* 0x3798: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_379d:
	/* 0x379d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_379f:
	/* 0x379f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37a1:
	/* 0x37a1: jne    382d <generic_sleepable_preload+0x382d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_382d;
	}
x86_l_37a7:
	/* 0x37a7: mov    eax,DWORD PTR [r13+0x26c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 620ULL);
x86_l_37ae:
	/* 0x37ae: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_37b3:
	/* 0x37b3: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37b6:
	/* 0x37b6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37bb:
	/* 0x37bb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37c0:
	/* 0x37c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37c5:
	/* 0x37c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37ca:
	/* 0x37ca: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_37cd:
	/* 0x37cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37cf:
	/* 0x37cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37d1:
	/* 0x37d1: jne    382d <generic_sleepable_preload+0x382d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_382d;
	}
x86_l_37d3:
	/* 0x37d3: movzx  eax,BYTE PTR [r13+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_37db:
	/* 0x37db: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_37e2:
	/* 0x37e2: mov    rcx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_37e9:
	/* 0x37e9: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_37ee:
	/* 0x37ee: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37f1:
	/* 0x37f1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_37f6:
	/* 0x37f6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37fb:
	/* 0x37fb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3800:
	/* 0x3800: movzx  ecx,BYTE PTR [r13+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_3808:
	/* 0x3808: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_380f:
	/* 0x380f: mov    rdx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_3816:
	/* 0x3816: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_381b:
	/* 0x381b: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_381e:
	/* 0x381e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3823:
	/* 0x3823: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3825:
	/* 0x3825: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3827:
	/* 0x3827: je     1c4a <generic_sleepable_preload+0x1c4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7242ULL;
	}
x86_l_382d:
	/* 0x382d: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3830:
	/* 0x3830: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3835:
	/* 0x3835: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3837:
	/* 0x3837: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_383a:
	/* 0x383a: cmp    WORD PTR [r13+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_3843:
	/* 0x3843: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3849:
	/* 0x3849: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3850:
	/* 0x3850: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3853:
	/* 0x3853: mov    eax,DWORD PTR [r13+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_385a:
	/* 0x385a: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_385d:
	/* 0x385d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3862:
	/* 0x3862: movzx  eax,WORD PTR [r13+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_386a:
	/* 0x386a: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_386c:
	/* 0x386c: je     3b52 <generic_sleepable_preload+0x3b52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15186ULL;
	}
x86_l_3872:
	/* 0x3872: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3875:
	/* 0x3875: je     389a <generic_sleepable_preload+0x389a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_389a;
	}
x86_l_3877:
	/* 0x3877: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_387c:
	/* 0x387c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3881:
	/* 0x3881: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3886:
	/* 0x3886: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_388b:
	/* 0x388b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3890:
	/* 0x3890: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3892:
	/* 0x3892: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3894:
	/* 0x3894: js     3e78 <generic_sleepable_preload+0x3e78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15992ULL;
	}
x86_l_389a:
	/* 0x389a: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_38a3:
	/* 0x38a3: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_38a9:
	/* 0x38a9: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_38b0:
	/* 0x38b0: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_38b5:
	/* 0x38b5: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38ba:
	/* 0x38ba: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_38c3:
	/* 0x38c3: je     38e8 <generic_sleepable_preload+0x38e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38e8;
	}
x86_l_38c5:
	/* 0x38c5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38ca:
	/* 0x38ca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_38cf:
	/* 0x38cf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38d4:
	/* 0x38d4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38d9:
	/* 0x38d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38de:
	/* 0x38de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38e0:
	/* 0x38e0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38e2:
	/* 0x38e2: js     5419 <generic_sleepable_preload+0x5419> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21529ULL;
	}
x86_l_38e8:
	/* 0x38e8: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_38f1:
	/* 0x38f1: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_38f7:
	/* 0x38f7: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_38fe:
	/* 0x38fe: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3903:
	/* 0x3903: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3908:
	/* 0x3908: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_3911:
	/* 0x3911: je     3936 <generic_sleepable_preload+0x3936> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3936;
	}
x86_l_3913:
	/* 0x3913: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3918:
	/* 0x3918: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_391d:
	/* 0x391d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3922:
	/* 0x3922: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3927:
	/* 0x3927: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_392c:
	/* 0x392c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_392e:
	/* 0x392e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3930:
	/* 0x3930: js     6100 <generic_sleepable_preload+0x6100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24832ULL;
	}
x86_l_3936:
	/* 0x3936: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_393f:
	/* 0x393f: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3945:
	/* 0x3945: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_394c:
	/* 0x394c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3951:
	/* 0x3951: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3956:
	/* 0x3956: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_395f:
	/* 0x395f: je     3984 <generic_sleepable_preload+0x3984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3984;
	}
x86_l_3961:
	/* 0x3961: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3966:
	/* 0x3966: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_396b:
	/* 0x396b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3970:
	/* 0x3970: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3975:
	/* 0x3975: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_397a:
	/* 0x397a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_397c:
	/* 0x397c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_397e:
	/* 0x397e: js     6164 <generic_sleepable_preload+0x6164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24932ULL;
	}
x86_l_3984:
	/* 0x3984: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_398d:
	/* 0x398d: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3993:
	/* 0x3993: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_399a:
	/* 0x399a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_399f:
	/* 0x399f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39a4:
	/* 0x39a4: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_39ad:
	/* 0x39ad: je     39d2 <generic_sleepable_preload+0x39d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39d2;
	}
x86_l_39af:
	/* 0x39af: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39b4:
	/* 0x39b4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_39b9:
	/* 0x39b9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39be:
	/* 0x39be: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39c3:
	/* 0x39c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39c8:
	/* 0x39c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39ca:
	/* 0x39ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39cc:
	/* 0x39cc: js     61c8 <generic_sleepable_preload+0x61c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25032ULL;
	}
x86_l_39d2:
	/* 0x39d2: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_39db:
	/* 0x39db: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_39e1:
	/* 0x39e1: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_39e8:
	/* 0x39e8: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_39ed:
	/* 0x39ed: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39f2:
	/* 0x39f2: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_39fb:
	/* 0x39fb: je     3a20 <generic_sleepable_preload+0x3a20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a20;
	}
x86_l_39fd:
	/* 0x39fd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a02:
	/* 0x3a02: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a07:
	/* 0x3a07: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a0c:
	/* 0x3a0c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a11:
	/* 0x3a11: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a16:
	/* 0x3a16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a18:
	/* 0x3a18: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a1a:
	/* 0x3a1a: js     6229 <generic_sleepable_preload+0x6229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25129ULL;
	}
x86_l_3a20:
	/* 0x3a20: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_3a29:
	/* 0x3a29: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3a2f:
	/* 0x3a2f: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_3a36:
	/* 0x3a36: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3a3b:
	/* 0x3a3b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a40:
	/* 0x3a40: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_3a49:
	/* 0x3a49: je     3a6e <generic_sleepable_preload+0x3a6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a6e;
	}
x86_l_3a4b:
	/* 0x3a4b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a50:
	/* 0x3a50: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a55:
	/* 0x3a55: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a5a:
	/* 0x3a5a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a5f:
	/* 0x3a5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a64:
	/* 0x3a64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a66:
	/* 0x3a66: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a68:
	/* 0x3a68: js     6499 <generic_sleepable_preload+0x6499> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25753ULL;
	}
x86_l_3a6e:
	/* 0x3a6e: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_3a77:
	/* 0x3a77: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3a7d:
	/* 0x3a7d: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_3a84:
	/* 0x3a84: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3a89:
	/* 0x3a89: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a8e:
	/* 0x3a8e: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_3a97:
	/* 0x3a97: je     3abc <generic_sleepable_preload+0x3abc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3abc;
	}
x86_l_3a99:
	/* 0x3a99: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a9e:
	/* 0x3a9e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3aa3:
	/* 0x3aa3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3aa8:
	/* 0x3aa8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aad:
	/* 0x3aad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ab2:
	/* 0x3ab2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ab4:
	/* 0x3ab4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ab6:
	/* 0x3ab6: js     68e5 <generic_sleepable_preload+0x68e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26853ULL;
	}
x86_l_3abc:
	/* 0x3abc: cmp    WORD PTR [r13+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_3ac5:
	/* 0x3ac5: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3acb:
	/* 0x3acb: mov    ecx,DWORD PTR [r13+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_3ad2:
	/* 0x3ad2: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3ad7:
	/* 0x3ad7: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3adc:
	/* 0x3adc: cmp    WORD PTR [r13+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_3ae5:
	/* 0x3ae5: je     3b0a <generic_sleepable_preload+0x3b0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15114ULL;
	}
	return 15079ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15079ULL: goto x86_l_3ae7;
	case 15084ULL: goto x86_l_3aec;
	case 15089ULL: goto x86_l_3af1;
	case 15094ULL: goto x86_l_3af6;
	case 15099ULL: goto x86_l_3afb;
	case 15104ULL: goto x86_l_3b00;
	case 15106ULL: goto x86_l_3b02;
	case 15108ULL: goto x86_l_3b04;
	case 15114ULL: goto x86_l_3b0a;
	case 15119ULL: goto x86_l_3b0f;
	case 15128ULL: goto x86_l_3b18;
	case 15134ULL: goto x86_l_3b1e;
	case 15141ULL: goto x86_l_3b25;
	case 15146ULL: goto x86_l_3b2a;
	case 15151ULL: goto x86_l_3b2f;
	case 15160ULL: goto x86_l_3b38;
	case 15166ULL: goto x86_l_3b3e;
	case 15171ULL: goto x86_l_3b43;
	case 15176ULL: goto x86_l_3b48;
	case 15181ULL: goto x86_l_3b4d;
	case 15186ULL: goto x86_l_3b52;
	case 15189ULL: goto x86_l_3b55;
	case 15191ULL: goto x86_l_3b57;
	case 15196ULL: goto x86_l_3b5c;
	case 15201ULL: goto x86_l_3b61;
	case 15206ULL: goto x86_l_3b66;
	case 15211ULL: goto x86_l_3b6b;
	case 15216ULL: goto x86_l_3b70;
	case 15218ULL: goto x86_l_3b72;
	case 15220ULL: goto x86_l_3b74;
	case 15226ULL: goto x86_l_3b7a;
	case 15235ULL: goto x86_l_3b83;
	case 15241ULL: goto x86_l_3b89;
	case 15248ULL: goto x86_l_3b90;
	case 15253ULL: goto x86_l_3b95;
	case 15258ULL: goto x86_l_3b9a;
	case 15267ULL: goto x86_l_3ba3;
	case 15269ULL: goto x86_l_3ba5;
	case 15274ULL: goto x86_l_3baa;
	case 15279ULL: goto x86_l_3baf;
	case 15284ULL: goto x86_l_3bb4;
	case 15289ULL: goto x86_l_3bb9;
	case 15294ULL: goto x86_l_3bbe;
	case 15296ULL: goto x86_l_3bc0;
	case 15298ULL: goto x86_l_3bc2;
	case 15304ULL: goto x86_l_3bc8;
	case 15313ULL: goto x86_l_3bd1;
	case 15319ULL: goto x86_l_3bd7;
	case 15326ULL: goto x86_l_3bde;
	case 15331ULL: goto x86_l_3be3;
	case 15336ULL: goto x86_l_3be8;
	case 15345ULL: goto x86_l_3bf1;
	case 15347ULL: goto x86_l_3bf3;
	case 15352ULL: goto x86_l_3bf8;
	case 15357ULL: goto x86_l_3bfd;
	case 15362ULL: goto x86_l_3c02;
	case 15367ULL: goto x86_l_3c07;
	case 15372ULL: goto x86_l_3c0c;
	case 15374ULL: goto x86_l_3c0e;
	case 15376ULL: goto x86_l_3c10;
	case 15382ULL: goto x86_l_3c16;
	case 15391ULL: goto x86_l_3c1f;
	case 15397ULL: goto x86_l_3c25;
	case 15404ULL: goto x86_l_3c2c;
	case 15409ULL: goto x86_l_3c31;
	case 15414ULL: goto x86_l_3c36;
	case 15423ULL: goto x86_l_3c3f;
	case 15425ULL: goto x86_l_3c41;
	case 15430ULL: goto x86_l_3c46;
	case 15435ULL: goto x86_l_3c4b;
	case 15440ULL: goto x86_l_3c50;
	case 15445ULL: goto x86_l_3c55;
	case 15450ULL: goto x86_l_3c5a;
	case 15452ULL: goto x86_l_3c5c;
	case 15454ULL: goto x86_l_3c5e;
	case 15460ULL: goto x86_l_3c64;
	case 15469ULL: goto x86_l_3c6d;
	case 15475ULL: goto x86_l_3c73;
	case 15482ULL: goto x86_l_3c7a;
	case 15487ULL: goto x86_l_3c7f;
	case 15492ULL: goto x86_l_3c84;
	case 15501ULL: goto x86_l_3c8d;
	case 15503ULL: goto x86_l_3c8f;
	case 15508ULL: goto x86_l_3c94;
	case 15513ULL: goto x86_l_3c99;
	case 15518ULL: goto x86_l_3c9e;
	case 15523ULL: goto x86_l_3ca3;
	case 15528ULL: goto x86_l_3ca8;
	case 15530ULL: goto x86_l_3caa;
	case 15532ULL: goto x86_l_3cac;
	case 15538ULL: goto x86_l_3cb2;
	case 15547ULL: goto x86_l_3cbb;
	case 15553ULL: goto x86_l_3cc1;
	case 15560ULL: goto x86_l_3cc8;
	case 15565ULL: goto x86_l_3ccd;
	case 15570ULL: goto x86_l_3cd2;
	case 15579ULL: goto x86_l_3cdb;
	case 15581ULL: goto x86_l_3cdd;
	case 15586ULL: goto x86_l_3ce2;
	case 15591ULL: goto x86_l_3ce7;
	case 15596ULL: goto x86_l_3cec;
	case 15601ULL: goto x86_l_3cf1;
	case 15606ULL: goto x86_l_3cf6;
	case 15608ULL: goto x86_l_3cf8;
	case 15610ULL: goto x86_l_3cfa;
	case 15616ULL: goto x86_l_3d00;
	case 15625ULL: goto x86_l_3d09;
	case 15631ULL: goto x86_l_3d0f;
	case 15638ULL: goto x86_l_3d16;
	case 15643ULL: goto x86_l_3d1b;
	case 15648ULL: goto x86_l_3d20;
	case 15657ULL: goto x86_l_3d29;
	case 15659ULL: goto x86_l_3d2b;
	case 15664ULL: goto x86_l_3d30;
	case 15669ULL: goto x86_l_3d35;
	case 15674ULL: goto x86_l_3d3a;
	case 15679ULL: goto x86_l_3d3f;
	case 15684ULL: goto x86_l_3d44;
	case 15686ULL: goto x86_l_3d46;
	case 15688ULL: goto x86_l_3d48;
	case 15694ULL: goto x86_l_3d4e;
	case 15703ULL: goto x86_l_3d57;
	case 15709ULL: goto x86_l_3d5d;
	case 15716ULL: goto x86_l_3d64;
	case 15721ULL: goto x86_l_3d69;
	case 15726ULL: goto x86_l_3d6e;
	case 15735ULL: goto x86_l_3d77;
	case 15737ULL: goto x86_l_3d79;
	case 15742ULL: goto x86_l_3d7e;
	case 15747ULL: goto x86_l_3d83;
	case 15752ULL: goto x86_l_3d88;
	case 15757ULL: goto x86_l_3d8d;
	case 15762ULL: goto x86_l_3d92;
	case 15764ULL: goto x86_l_3d94;
	case 15766ULL: goto x86_l_3d96;
	case 15772ULL: goto x86_l_3d9c;
	case 15777ULL: goto x86_l_3da1;
	case 15786ULL: goto x86_l_3daa;
	case 15792ULL: goto x86_l_3db0;
	case 15799ULL: goto x86_l_3db7;
	case 15804ULL: goto x86_l_3dbc;
	case 15809ULL: goto x86_l_3dc1;
	case 15818ULL: goto x86_l_3dca;
	case 15820ULL: goto x86_l_3dcc;
	case 15825ULL: goto x86_l_3dd1;
	case 15830ULL: goto x86_l_3dd6;
	case 15835ULL: goto x86_l_3ddb;
	case 15840ULL: goto x86_l_3de0;
	case 15845ULL: goto x86_l_3de5;
	case 15847ULL: goto x86_l_3de7;
	case 15849ULL: goto x86_l_3de9;
	case 15855ULL: goto x86_l_3def;
	case 15860ULL: goto x86_l_3df4;
	case 15869ULL: goto x86_l_3dfd;
	case 15875ULL: goto x86_l_3e03;
	case 15882ULL: goto x86_l_3e0a;
	case 15887ULL: goto x86_l_3e0f;
	case 15892ULL: goto x86_l_3e14;
	case 15901ULL: goto x86_l_3e1d;
	case 15907ULL: goto x86_l_3e23;
	case 15912ULL: goto x86_l_3e28;
	case 15917ULL: goto x86_l_3e2d;
	case 15922ULL: goto x86_l_3e32;
	case 15927ULL: goto x86_l_3e37;
	case 15932ULL: goto x86_l_3e3c;
	case 15934ULL: goto x86_l_3e3e;
	case 15936ULL: goto x86_l_3e40;
	case 15942ULL: goto x86_l_3e46;
	case 15947ULL: goto x86_l_3e4b;
	case 15952ULL: goto x86_l_3e50;
	case 15957ULL: goto x86_l_3e55;
	case 15962ULL: goto x86_l_3e5a;
	case 15967ULL: goto x86_l_3e5f;
	case 15972ULL: goto x86_l_3e64;
	case 15977ULL: goto x86_l_3e69;
	case 15982ULL: goto x86_l_3e6e;
	case 15987ULL: goto x86_l_3e73;
	case 15992ULL: goto x86_l_3e78;
	case 15997ULL: goto x86_l_3e7d;
	case 16002ULL: goto x86_l_3e82;
	case 16010ULL: goto x86_l_3e8a;
	case 16013ULL: goto x86_l_3e8d;
	case 16019ULL: goto x86_l_3e93;
	case 16024ULL: goto x86_l_3e98;
	case 16027ULL: goto x86_l_3e9b;
	case 16033ULL: goto x86_l_3ea1;
	case 16038ULL: goto x86_l_3ea6;
	case 16046ULL: goto x86_l_3eae;
	case 16049ULL: goto x86_l_3eb1;
	case 16055ULL: goto x86_l_3eb7;
	case 16060ULL: goto x86_l_3ebc;
	case 16063ULL: goto x86_l_3ebf;
	case 16069ULL: goto x86_l_3ec5;
	case 16074ULL: goto x86_l_3eca;
	case 16082ULL: goto x86_l_3ed2;
	case 16085ULL: goto x86_l_3ed5;
	case 16091ULL: goto x86_l_3edb;
	case 16096ULL: goto x86_l_3ee0;
	case 16099ULL: goto x86_l_3ee3;
	case 16105ULL: goto x86_l_3ee9;
	case 16110ULL: goto x86_l_3eee;
	case 16118ULL: goto x86_l_3ef6;
	case 16121ULL: goto x86_l_3ef9;
	case 16127ULL: goto x86_l_3eff;
	case 16132ULL: goto x86_l_3f04;
	case 16135ULL: goto x86_l_3f07;
	case 16141ULL: goto x86_l_3f0d;
	case 16146ULL: goto x86_l_3f12;
	case 16154ULL: goto x86_l_3f1a;
	case 16157ULL: goto x86_l_3f1d;
	case 16163ULL: goto x86_l_3f23;
	case 16168ULL: goto x86_l_3f28;
	case 16171ULL: goto x86_l_3f2b;
	case 16177ULL: goto x86_l_3f31;
	case 16182ULL: goto x86_l_3f36;
	case 16190ULL: goto x86_l_3f3e;
	case 16193ULL: goto x86_l_3f41;
	case 16199ULL: goto x86_l_3f47;
	case 16204ULL: goto x86_l_3f4c;
	case 16207ULL: goto x86_l_3f4f;
	case 16213ULL: goto x86_l_3f55;
	case 16218ULL: goto x86_l_3f5a;
	case 16226ULL: goto x86_l_3f62;
	case 16229ULL: goto x86_l_3f65;
	case 16235ULL: goto x86_l_3f6b;
	case 16240ULL: goto x86_l_3f70;
	case 16243ULL: goto x86_l_3f73;
	case 16249ULL: goto x86_l_3f79;
	case 16254ULL: goto x86_l_3f7e;
	case 16262ULL: goto x86_l_3f86;
	case 16265ULL: goto x86_l_3f89;
	case 16271ULL: goto x86_l_3f8f;
	case 16276ULL: goto x86_l_3f94;
	case 16279ULL: goto x86_l_3f97;
	case 16285ULL: goto x86_l_3f9d;
	case 16290ULL: goto x86_l_3fa2;
	case 16298ULL: goto x86_l_3faa;
	case 16301ULL: goto x86_l_3fad;
	case 16307ULL: goto x86_l_3fb3;
	case 16312ULL: goto x86_l_3fb8;
	case 16315ULL: goto x86_l_3fbb;
	case 16321ULL: goto x86_l_3fc1;
	case 16326ULL: goto x86_l_3fc6;
	case 16334ULL: goto x86_l_3fce;
	case 16337ULL: goto x86_l_3fd1;
	case 16343ULL: goto x86_l_3fd7;
	case 16348ULL: goto x86_l_3fdc;
	case 16351ULL: goto x86_l_3fdf;
	case 16357ULL: goto x86_l_3fe5;
	case 16362ULL: goto x86_l_3fea;
	case 16370ULL: goto x86_l_3ff2;
	case 16373ULL: goto x86_l_3ff5;
	case 16379ULL: goto x86_l_3ffb;
	case 16384ULL: goto x86_l_4000;
	case 16387ULL: goto x86_l_4003;
	case 16393ULL: goto x86_l_4009;
	case 16398ULL: goto x86_l_400e;
	case 16406ULL: goto x86_l_4016;
	case 16409ULL: goto x86_l_4019;
	case 16415ULL: goto x86_l_401f;
	case 16420ULL: goto x86_l_4024;
	case 16423ULL: goto x86_l_4027;
	case 16429ULL: goto x86_l_402d;
	case 16434ULL: goto x86_l_4032;
	case 16442ULL: goto x86_l_403a;
	case 16445ULL: goto x86_l_403d;
	case 16451ULL: goto x86_l_4043;
	case 16456ULL: goto x86_l_4048;
	case 16459ULL: goto x86_l_404b;
	case 16465ULL: goto x86_l_4051;
	case 16470ULL: goto x86_l_4056;
	case 16478ULL: goto x86_l_405e;
	case 16481ULL: goto x86_l_4061;
	case 16487ULL: goto x86_l_4067;
	case 16492ULL: goto x86_l_406c;
	case 16495ULL: goto x86_l_406f;
	case 16501ULL: goto x86_l_4075;
	case 16506ULL: goto x86_l_407a;
	case 16514ULL: goto x86_l_4082;
	case 16517ULL: goto x86_l_4085;
	case 16523ULL: goto x86_l_408b;
	case 16528ULL: goto x86_l_4090;
	case 16531ULL: goto x86_l_4093;
	case 16537ULL: goto x86_l_4099;
	case 16542ULL: goto x86_l_409e;
	case 16550ULL: goto x86_l_40a6;
	case 16553ULL: goto x86_l_40a9;
	case 16555ULL: goto x86_l_40ab;
	case 16560ULL: goto x86_l_40b0;
	case 16563ULL: goto x86_l_40b3;
	case 16565ULL: goto x86_l_40b5;
	case 16568ULL: goto x86_l_40b8;
	case 16570ULL: goto x86_l_40ba;
	case 16572ULL: goto x86_l_40bc;
	case 16577ULL: goto x86_l_40c1;
	case 16579ULL: goto x86_l_40c3;
	case 16584ULL: goto x86_l_40c8;
	case 16589ULL: goto x86_l_40cd;
	case 16593ULL: goto x86_l_40d1;
	case 16595ULL: goto x86_l_40d3;
	case 16598ULL: goto x86_l_40d6;
	case 16604ULL: goto x86_l_40dc;
	case 16610ULL: goto x86_l_40e2;
	case 16617ULL: goto x86_l_40e9;
	case 16620ULL: goto x86_l_40ec;
	case 16624ULL: goto x86_l_40f0;
	case 16627ULL: goto x86_l_40f3;
	case 16632ULL: goto x86_l_40f8;
	case 16637ULL: goto x86_l_40fd;
	case 16639ULL: goto x86_l_40ff;
	case 16645ULL: goto x86_l_4105;
	case 16648ULL: goto x86_l_4108;
	case 16650ULL: goto x86_l_410a;
	case 16655ULL: goto x86_l_410f;
	case 16660ULL: goto x86_l_4114;
	case 16665ULL: goto x86_l_4119;
	case 16670ULL: goto x86_l_411e;
	case 16675ULL: goto x86_l_4123;
	case 16677ULL: goto x86_l_4125;
	case 16679ULL: goto x86_l_4127;
	case 16685ULL: goto x86_l_412d;
	case 16691ULL: goto x86_l_4133;
	case 16697ULL: goto x86_l_4139;
	case 16701ULL: goto x86_l_413d;
	case 16706ULL: goto x86_l_4142;
	case 16711ULL: goto x86_l_4147;
	case 16717ULL: goto x86_l_414d;
	case 16719ULL: goto x86_l_414f;
	case 16724ULL: goto x86_l_4154;
	case 16729ULL: goto x86_l_4159;
	case 16734ULL: goto x86_l_415e;
	case 16739ULL: goto x86_l_4163;
	case 16744ULL: goto x86_l_4168;
	case 16746ULL: goto x86_l_416a;
	case 16748ULL: goto x86_l_416c;
	case 16754ULL: goto x86_l_4172;
	case 16763ULL: goto x86_l_417b;
	case 16769ULL: goto x86_l_4181;
	case 16776ULL: goto x86_l_4188;
	case 16781ULL: goto x86_l_418d;
	case 16786ULL: goto x86_l_4192;
	case 16795ULL: goto x86_l_419b;
	case 16797ULL: goto x86_l_419d;
	case 16802ULL: goto x86_l_41a2;
	case 16807ULL: goto x86_l_41a7;
	case 16812ULL: goto x86_l_41ac;
	case 16817ULL: goto x86_l_41b1;
	case 16822ULL: goto x86_l_41b6;
	case 16824ULL: goto x86_l_41b8;
	case 16826ULL: goto x86_l_41ba;
	case 16832ULL: goto x86_l_41c0;
	case 16841ULL: goto x86_l_41c9;
	case 16847ULL: goto x86_l_41cf;
	case 16854ULL: goto x86_l_41d6;
	case 16859ULL: goto x86_l_41db;
	case 16864ULL: goto x86_l_41e0;
	case 16873ULL: goto x86_l_41e9;
	case 16875ULL: goto x86_l_41eb;
	case 16880ULL: goto x86_l_41f0;
	case 16885ULL: goto x86_l_41f5;
	case 16890ULL: goto x86_l_41fa;
	case 16895ULL: goto x86_l_41ff;
	case 16900ULL: goto x86_l_4204;
	case 16902ULL: goto x86_l_4206;
	case 16904ULL: goto x86_l_4208;
	case 16910ULL: goto x86_l_420e;
	case 16919ULL: goto x86_l_4217;
	case 16925ULL: goto x86_l_421d;
	case 16932ULL: goto x86_l_4224;
	case 16937ULL: goto x86_l_4229;
	case 16942ULL: goto x86_l_422e;
	case 16951ULL: goto x86_l_4237;
	case 16953ULL: goto x86_l_4239;
	case 16958ULL: goto x86_l_423e;
	case 16963ULL: goto x86_l_4243;
	case 16968ULL: goto x86_l_4248;
	case 16973ULL: goto x86_l_424d;
	case 16978ULL: goto x86_l_4252;
	case 16980ULL: goto x86_l_4254;
	case 16982ULL: goto x86_l_4256;
	case 16988ULL: goto x86_l_425c;
	case 16997ULL: goto x86_l_4265;
	case 17003ULL: goto x86_l_426b;
	case 17010ULL: goto x86_l_4272;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3ae7:
	/* 0x3ae7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aec:
	/* 0x3aec: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3af1:
	/* 0x3af1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3af6:
	/* 0x3af6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3afb:
	/* 0x3afb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b00:
	/* 0x3b00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b02:
	/* 0x3b02: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b04:
	/* 0x3b04: js     695c <generic_sleepable_preload+0x695c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26972ULL;
	}
x86_l_3b0a:
	/* 0x3b0a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3b0f:
	/* 0x3b0f: cmp    WORD PTR [r13+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_3b18:
	/* 0x3b18: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3b1e:
	/* 0x3b1e: mov    ecx,DWORD PTR [r13+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_3b25:
	/* 0x3b25: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3b2a:
	/* 0x3b2a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b2f:
	/* 0x3b2f: cmp    WORD PTR [r13+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_3b38:
	/* 0x3b38: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3b3e:
	/* 0x3b3e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b43:
	/* 0x3b43: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b48:
	/* 0x3b48: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b4d:
	/* 0x3b4d: jmp    3e32 <generic_sleepable_preload+0x3e32> */
	goto x86_l_3e32;
x86_l_3b52:
	/* 0x3b52: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3b55:
	/* 0x3b55: je     3b7a <generic_sleepable_preload+0x3b7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b7a;
	}
x86_l_3b57:
	/* 0x3b57: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b5c:
	/* 0x3b5c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b61:
	/* 0x3b61: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b66:
	/* 0x3b66: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b6b:
	/* 0x3b6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b70:
	/* 0x3b70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b72:
	/* 0x3b72: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b74:
	/* 0x3b74: js     3e78 <generic_sleepable_preload+0x3e78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e78;
	}
x86_l_3b7a:
	/* 0x3b7a: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_3b83:
	/* 0x3b83: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3b89:
	/* 0x3b89: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_3b90:
	/* 0x3b90: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3b95:
	/* 0x3b95: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b9a:
	/* 0x3b9a: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_3ba3:
	/* 0x3ba3: je     3bc8 <generic_sleepable_preload+0x3bc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bc8;
	}
x86_l_3ba5:
	/* 0x3ba5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3baa:
	/* 0x3baa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3baf:
	/* 0x3baf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3bb4:
	/* 0x3bb4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bb9:
	/* 0x3bb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bbe:
	/* 0x3bbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bc0:
	/* 0x3bc0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3bc2:
	/* 0x3bc2: js     5419 <generic_sleepable_preload+0x5419> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21529ULL;
	}
x86_l_3bc8:
	/* 0x3bc8: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_3bd1:
	/* 0x3bd1: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3bd7:
	/* 0x3bd7: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_3bde:
	/* 0x3bde: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3be3:
	/* 0x3be3: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3be8:
	/* 0x3be8: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_3bf1:
	/* 0x3bf1: je     3c16 <generic_sleepable_preload+0x3c16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c16;
	}
x86_l_3bf3:
	/* 0x3bf3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bf8:
	/* 0x3bf8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3bfd:
	/* 0x3bfd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c02:
	/* 0x3c02: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c07:
	/* 0x3c07: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c0c:
	/* 0x3c0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c0e:
	/* 0x3c0e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c10:
	/* 0x3c10: js     6100 <generic_sleepable_preload+0x6100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24832ULL;
	}
x86_l_3c16:
	/* 0x3c16: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_3c1f:
	/* 0x3c1f: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3c25:
	/* 0x3c25: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_3c2c:
	/* 0x3c2c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3c31:
	/* 0x3c31: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c36:
	/* 0x3c36: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_3c3f:
	/* 0x3c3f: je     3c64 <generic_sleepable_preload+0x3c64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c64;
	}
x86_l_3c41:
	/* 0x3c41: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c46:
	/* 0x3c46: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c4b:
	/* 0x3c4b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c50:
	/* 0x3c50: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c55:
	/* 0x3c55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c5a:
	/* 0x3c5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c5c:
	/* 0x3c5c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c5e:
	/* 0x3c5e: js     6164 <generic_sleepable_preload+0x6164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24932ULL;
	}
x86_l_3c64:
	/* 0x3c64: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_3c6d:
	/* 0x3c6d: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3c73:
	/* 0x3c73: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_3c7a:
	/* 0x3c7a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3c7f:
	/* 0x3c7f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c84:
	/* 0x3c84: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_3c8d:
	/* 0x3c8d: je     3cb2 <generic_sleepable_preload+0x3cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cb2;
	}
x86_l_3c8f:
	/* 0x3c8f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c94:
	/* 0x3c94: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c99:
	/* 0x3c99: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c9e:
	/* 0x3c9e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ca3:
	/* 0x3ca3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ca8:
	/* 0x3ca8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3caa:
	/* 0x3caa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3cac:
	/* 0x3cac: js     61c8 <generic_sleepable_preload+0x61c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25032ULL;
	}
x86_l_3cb2:
	/* 0x3cb2: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_3cbb:
	/* 0x3cbb: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3cc1:
	/* 0x3cc1: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_3cc8:
	/* 0x3cc8: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3ccd:
	/* 0x3ccd: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cd2:
	/* 0x3cd2: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_3cdb:
	/* 0x3cdb: je     3d00 <generic_sleepable_preload+0x3d00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d00;
	}
x86_l_3cdd:
	/* 0x3cdd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ce2:
	/* 0x3ce2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3ce7:
	/* 0x3ce7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3cec:
	/* 0x3cec: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cf1:
	/* 0x3cf1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cf6:
	/* 0x3cf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cf8:
	/* 0x3cf8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3cfa:
	/* 0x3cfa: js     6229 <generic_sleepable_preload+0x6229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25129ULL;
	}
x86_l_3d00:
	/* 0x3d00: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_3d09:
	/* 0x3d09: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3d0f:
	/* 0x3d0f: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_3d16:
	/* 0x3d16: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3d1b:
	/* 0x3d1b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d20:
	/* 0x3d20: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_3d29:
	/* 0x3d29: je     3d4e <generic_sleepable_preload+0x3d4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d4e;
	}
x86_l_3d2b:
	/* 0x3d2b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d30:
	/* 0x3d30: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d35:
	/* 0x3d35: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d3a:
	/* 0x3d3a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d3f:
	/* 0x3d3f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d44:
	/* 0x3d44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d46:
	/* 0x3d46: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d48:
	/* 0x3d48: js     6499 <generic_sleepable_preload+0x6499> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25753ULL;
	}
x86_l_3d4e:
	/* 0x3d4e: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_3d57:
	/* 0x3d57: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3d5d:
	/* 0x3d5d: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_3d64:
	/* 0x3d64: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3d69:
	/* 0x3d69: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d6e:
	/* 0x3d6e: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_3d77:
	/* 0x3d77: je     3d9c <generic_sleepable_preload+0x3d9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d9c;
	}
x86_l_3d79:
	/* 0x3d79: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d7e:
	/* 0x3d7e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d83:
	/* 0x3d83: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d88:
	/* 0x3d88: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d8d:
	/* 0x3d8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d92:
	/* 0x3d92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d94:
	/* 0x3d94: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d96:
	/* 0x3d96: js     6a00 <generic_sleepable_preload+0x6a00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27136ULL;
	}
x86_l_3d9c:
	/* 0x3d9c: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3da1:
	/* 0x3da1: cmp    WORD PTR [r13+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_3daa:
	/* 0x3daa: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3db0:
	/* 0x3db0: mov    ecx,DWORD PTR [r13+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_3db7:
	/* 0x3db7: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3dbc:
	/* 0x3dbc: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dc1:
	/* 0x3dc1: cmp    WORD PTR [r13+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_3dca:
	/* 0x3dca: je     3def <generic_sleepable_preload+0x3def> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3def;
	}
x86_l_3dcc:
	/* 0x3dcc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dd1:
	/* 0x3dd1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3dd6:
	/* 0x3dd6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ddb:
	/* 0x3ddb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3de0:
	/* 0x3de0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3de5:
	/* 0x3de5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3de7:
	/* 0x3de7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3de9:
	/* 0x3de9: js     695c <generic_sleepable_preload+0x695c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26972ULL;
	}
x86_l_3def:
	/* 0x3def: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3df4:
	/* 0x3df4: cmp    WORD PTR [r13+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_3dfd:
	/* 0x3dfd: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3e03:
	/* 0x3e03: mov    ecx,DWORD PTR [r13+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_3e0a:
	/* 0x3e0a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3e0f:
	/* 0x3e0f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e14:
	/* 0x3e14: cmp    WORD PTR [r13+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_3e1d:
	/* 0x3e1d: je     64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25761ULL;
	}
x86_l_3e23:
	/* 0x3e23: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e28:
	/* 0x3e28: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3e2d:
	/* 0x3e2d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3e32:
	/* 0x3e32: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e37:
	/* 0x3e37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e3c:
	/* 0x3e3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e3e:
	/* 0x3e3e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e40:
	/* 0x3e40: jns    64a1 <generic_sleepable_preload+0x64a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25761ULL;
	}
x86_l_3e46:
	/* 0x3e46: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_3e4b:
	/* 0x3e4b: jmp    649e <generic_sleepable_preload+0x649e> */
	return 25758ULL;
x86_l_3e50:
	/* 0x3e50: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e55:
	/* 0x3e55: jmp    626a <generic_sleepable_preload+0x626a> */
	return 25194ULL;
x86_l_3e5a:
	/* 0x3e5a: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e5f:
	/* 0x3e5f: jmp    62f7 <generic_sleepable_preload+0x62f7> */
	return 25335ULL;
x86_l_3e64:
	/* 0x3e64: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e69:
	/* 0x3e69: jmp    6384 <generic_sleepable_preload+0x6384> */
	return 25476ULL;
x86_l_3e6e:
	/* 0x3e6e: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e73:
	/* 0x3e73: jmp    6411 <generic_sleepable_preload+0x6411> */
	return 25617ULL;
x86_l_3e78:
	/* 0x3e78: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_3e7d:
	/* 0x3e7d: jmp    649e <generic_sleepable_preload+0x649e> */
	return 25758ULL;
x86_l_3e82:
	/* 0x3e82: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3e8a:
	/* 0x3e8a: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3e8d:
	/* 0x3e8d: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40b5;
	}
x86_l_3e93:
	/* 0x3e93: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3e98:
	/* 0x3e98: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3e9b:
	/* 0x3e9b: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40b5;
	}
x86_l_3ea1:
	/* 0x3ea1: jmp    40c8 <generic_sleepable_preload+0x40c8> */
	goto x86_l_40c8;
x86_l_3ea6:
	/* 0x3ea6: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3eae:
	/* 0x3eae: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3eb1:
	/* 0x3eb1: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_3eb7:
	/* 0x3eb7: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ebc:
	/* 0x3ebc: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3ebf:
	/* 0x3ebf: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_3ec5:
	/* 0x3ec5: jmp    5457 <generic_sleepable_preload+0x5457> */
	return 21591ULL;
x86_l_3eca:
	/* 0x3eca: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3ed2:
	/* 0x3ed2: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3ed5:
	/* 0x3ed5: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_3edb:
	/* 0x3edb: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ee0:
	/* 0x3ee0: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3ee3:
	/* 0x3ee3: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_3ee9:
	/* 0x3ee9: jmp    4738 <generic_sleepable_preload+0x4738> */
	return 18232ULL;
x86_l_3eee:
	/* 0x3eee: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3ef6:
	/* 0x3ef6: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3ef9:
	/* 0x3ef9: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_3eff:
	/* 0x3eff: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3f04:
	/* 0x3f04: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3f07:
	/* 0x3f07: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_3f0d:
	/* 0x3f0d: jmp    4d9f <generic_sleepable_preload+0x4d9f> */
	return 19871ULL;
x86_l_3f12:
	/* 0x3f12: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3f1a:
	/* 0x3f1a: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3f1d:
	/* 0x3f1d: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_3f23:
	/* 0x3f23: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3f28:
	/* 0x3f28: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3f2b:
	/* 0x3f2b: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_3f31:
	/* 0x3f31: jmp    5aa7 <generic_sleepable_preload+0x5aa7> */
	return 23207ULL;
x86_l_3f36:
	/* 0x3f36: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f3e:
	/* 0x3f3e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3f41:
	/* 0x3f41: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40b5;
	}
x86_l_3f47:
	/* 0x3f47: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3f4c:
	/* 0x3f4c: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3f4f:
	/* 0x3f4f: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40b5;
	}
x86_l_3f55:
	/* 0x3f55: jmp    40c8 <generic_sleepable_preload+0x40c8> */
	goto x86_l_40c8;
x86_l_3f5a:
	/* 0x3f5a: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f62:
	/* 0x3f62: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3f65:
	/* 0x3f65: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_3f6b:
	/* 0x3f6b: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3f70:
	/* 0x3f70: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3f73:
	/* 0x3f73: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_3f79:
	/* 0x3f79: jmp    5457 <generic_sleepable_preload+0x5457> */
	return 21591ULL;
x86_l_3f7e:
	/* 0x3f7e: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f86:
	/* 0x3f86: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3f89:
	/* 0x3f89: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_3f8f:
	/* 0x3f8f: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3f94:
	/* 0x3f94: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3f97:
	/* 0x3f97: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_3f9d:
	/* 0x3f9d: jmp    4738 <generic_sleepable_preload+0x4738> */
	return 18232ULL;
x86_l_3fa2:
	/* 0x3fa2: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3faa:
	/* 0x3faa: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3fad:
	/* 0x3fad: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_3fb3:
	/* 0x3fb3: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3fb8:
	/* 0x3fb8: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3fbb:
	/* 0x3fbb: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_3fc1:
	/* 0x3fc1: jmp    4d9f <generic_sleepable_preload+0x4d9f> */
	return 19871ULL;
x86_l_3fc6:
	/* 0x3fc6: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3fce:
	/* 0x3fce: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3fd1:
	/* 0x3fd1: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_3fd7:
	/* 0x3fd7: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3fdc:
	/* 0x3fdc: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3fdf:
	/* 0x3fdf: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_3fe5:
	/* 0x3fe5: jmp    5aa7 <generic_sleepable_preload+0x5aa7> */
	return 23207ULL;
x86_l_3fea:
	/* 0x3fea: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3ff2:
	/* 0x3ff2: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_3ff5:
	/* 0x3ff5: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40b5;
	}
x86_l_3ffb:
	/* 0x3ffb: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4000:
	/* 0x4000: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4003:
	/* 0x4003: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40b5;
	}
x86_l_4009:
	/* 0x4009: jmp    40c8 <generic_sleepable_preload+0x40c8> */
	goto x86_l_40c8;
x86_l_400e:
	/* 0x400e: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4016:
	/* 0x4016: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4019:
	/* 0x4019: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_401f:
	/* 0x401f: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4024:
	/* 0x4024: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4027:
	/* 0x4027: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_402d:
	/* 0x402d: jmp    5457 <generic_sleepable_preload+0x5457> */
	return 21591ULL;
x86_l_4032:
	/* 0x4032: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_403a:
	/* 0x403a: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_403d:
	/* 0x403d: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_4043:
	/* 0x4043: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4048:
	/* 0x4048: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_404b:
	/* 0x404b: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18213ULL;
	}
x86_l_4051:
	/* 0x4051: jmp    4738 <generic_sleepable_preload+0x4738> */
	return 18232ULL;
x86_l_4056:
	/* 0x4056: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_405e:
	/* 0x405e: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4061:
	/* 0x4061: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_4067:
	/* 0x4067: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_406c:
	/* 0x406c: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_406f:
	/* 0x406f: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19852ULL;
	}
x86_l_4075:
	/* 0x4075: jmp    4d9f <generic_sleepable_preload+0x4d9f> */
	return 19871ULL;
x86_l_407a:
	/* 0x407a: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4082:
	/* 0x4082: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4085:
	/* 0x4085: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_408b:
	/* 0x408b: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4090:
	/* 0x4090: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4093:
	/* 0x4093: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_4099:
	/* 0x4099: jmp    5aa7 <generic_sleepable_preload+0x5aa7> */
	return 23207ULL;
x86_l_409e:
	/* 0x409e: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_40a6:
	/* 0x40a6: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_40a9:
	/* 0x40a9: je     40b5 <generic_sleepable_preload+0x40b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40b5;
	}
x86_l_40ab:
	/* 0x40ab: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_40b0:
	/* 0x40b0: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_40b3:
	/* 0x40b3: jne    40c8 <generic_sleepable_preload+0x40c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_40c8;
	}
x86_l_40b5:
	/* 0x40b5: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_40b8:
	/* 0x40b8: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_40ba:
	/* 0x40ba: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_40bc:
	/* 0x40bc: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_40c1:
	/* 0x40c1: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_40c3:
	/* 0x40c3: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_40c8:
	/* 0x40c8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40cd:
	/* 0x40cd: mov    r14d,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_40d1:
	/* 0x40d1: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_40d3:
	/* 0x40d3: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_40d6:
	/* 0x40d6: cmp    WORD PTR [r13+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_40dc:
	/* 0x40dc: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_40e2:
	/* 0x40e2: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_40e9:
	/* 0x40e9: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_40ec:
	/* 0x40ec: mov    eax,DWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_40f0:
	/* 0x40f0: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_40f3:
	/* 0x40f3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40f8:
	/* 0x40f8: movzx  eax,WORD PTR [r13+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_40fd:
	/* 0x40fd: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_40ff:
	/* 0x40ff: je     43e1 <generic_sleepable_preload+0x43e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17377ULL;
	}
x86_l_4105:
	/* 0x4105: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4108:
	/* 0x4108: je     412d <generic_sleepable_preload+0x412d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_412d;
	}
x86_l_410a:
	/* 0x410a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_410f:
	/* 0x410f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4114:
	/* 0x4114: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4119:
	/* 0x4119: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_411e:
	/* 0x411e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4123:
	/* 0x4123: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4125:
	/* 0x4125: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4127:
	/* 0x4127: js     46e0 <generic_sleepable_preload+0x46e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 18144ULL;
	}
x86_l_412d:
	/* 0x412d: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_4133:
	/* 0x4133: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_4139:
	/* 0x4139: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_413d:
	/* 0x413d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4142:
	/* 0x4142: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4147:
	/* 0x4147: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_414d:
	/* 0x414d: je     4172 <generic_sleepable_preload+0x4172> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4172;
	}
x86_l_414f:
	/* 0x414f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4154:
	/* 0x4154: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4159:
	/* 0x4159: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_415e:
	/* 0x415e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4163:
	/* 0x4163: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4168:
	/* 0x4168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_416a:
	/* 0x416a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_416c:
	/* 0x416c: js     5423 <generic_sleepable_preload+0x5423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21539ULL;
	}
x86_l_4172:
	/* 0x4172: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_417b:
	/* 0x417b: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_4181:
	/* 0x4181: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4188:
	/* 0x4188: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_418d:
	/* 0x418d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4192:
	/* 0x4192: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_419b:
	/* 0x419b: je     41c0 <generic_sleepable_preload+0x41c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41c0;
	}
x86_l_419d:
	/* 0x419d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41a2:
	/* 0x41a2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41a7:
	/* 0x41a7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41ac:
	/* 0x41ac: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41b1:
	/* 0x41b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41b6:
	/* 0x41b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41b8:
	/* 0x41b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41ba:
	/* 0x41ba: js     610a <generic_sleepable_preload+0x610a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24842ULL;
	}
x86_l_41c0:
	/* 0x41c0: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_41c9:
	/* 0x41c9: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_41cf:
	/* 0x41cf: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_41d6:
	/* 0x41d6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_41db:
	/* 0x41db: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41e0:
	/* 0x41e0: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_41e9:
	/* 0x41e9: je     420e <generic_sleepable_preload+0x420e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_420e;
	}
x86_l_41eb:
	/* 0x41eb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41f0:
	/* 0x41f0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41f5:
	/* 0x41f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41fa:
	/* 0x41fa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41ff:
	/* 0x41ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4204:
	/* 0x4204: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4206:
	/* 0x4206: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4208:
	/* 0x4208: js     616e <generic_sleepable_preload+0x616e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24942ULL;
	}
x86_l_420e:
	/* 0x420e: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_4217:
	/* 0x4217: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_421d:
	/* 0x421d: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4224:
	/* 0x4224: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4229:
	/* 0x4229: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_422e:
	/* 0x422e: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_4237:
	/* 0x4237: je     425c <generic_sleepable_preload+0x425c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_425c;
	}
x86_l_4239:
	/* 0x4239: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_423e:
	/* 0x423e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4243:
	/* 0x4243: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4248:
	/* 0x4248: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_424d:
	/* 0x424d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4252:
	/* 0x4252: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4254:
	/* 0x4254: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4256:
	/* 0x4256: js     61d2 <generic_sleepable_preload+0x61d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25042ULL;
	}
x86_l_425c:
	/* 0x425c: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_4265:
	/* 0x4265: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_426b:
	/* 0x426b: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4272:
	/* 0x4272: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
	return 17015ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17015ULL: goto x86_l_4277;
	case 17020ULL: goto x86_l_427c;
	case 17029ULL: goto x86_l_4285;
	case 17031ULL: goto x86_l_4287;
	case 17036ULL: goto x86_l_428c;
	case 17041ULL: goto x86_l_4291;
	case 17046ULL: goto x86_l_4296;
	case 17051ULL: goto x86_l_429b;
	case 17056ULL: goto x86_l_42a0;
	case 17058ULL: goto x86_l_42a2;
	case 17060ULL: goto x86_l_42a4;
	case 17066ULL: goto x86_l_42aa;
	case 17075ULL: goto x86_l_42b3;
	case 17081ULL: goto x86_l_42b9;
	case 17088ULL: goto x86_l_42c0;
	case 17093ULL: goto x86_l_42c5;
	case 17098ULL: goto x86_l_42ca;
	case 17107ULL: goto x86_l_42d3;
	case 17109ULL: goto x86_l_42d5;
	case 17114ULL: goto x86_l_42da;
	case 17119ULL: goto x86_l_42df;
	case 17124ULL: goto x86_l_42e4;
	case 17129ULL: goto x86_l_42e9;
	case 17134ULL: goto x86_l_42ee;
	case 17136ULL: goto x86_l_42f0;
	case 17138ULL: goto x86_l_42f2;
	case 17144ULL: goto x86_l_42f8;
	case 17153ULL: goto x86_l_4301;
	case 17159ULL: goto x86_l_4307;
	case 17166ULL: goto x86_l_430e;
	case 17171ULL: goto x86_l_4313;
	case 17176ULL: goto x86_l_4318;
	case 17185ULL: goto x86_l_4321;
	case 17187ULL: goto x86_l_4323;
	case 17192ULL: goto x86_l_4328;
	case 17197ULL: goto x86_l_432d;
	case 17202ULL: goto x86_l_4332;
	case 17207ULL: goto x86_l_4337;
	case 17212ULL: goto x86_l_433c;
	case 17214ULL: goto x86_l_433e;
	case 17216ULL: goto x86_l_4340;
	case 17222ULL: goto x86_l_4346;
	case 17231ULL: goto x86_l_434f;
	case 17237ULL: goto x86_l_4355;
	case 17244ULL: goto x86_l_435c;
	case 17249ULL: goto x86_l_4361;
	case 17254ULL: goto x86_l_4366;
	case 17263ULL: goto x86_l_436f;
	case 17265ULL: goto x86_l_4371;
	case 17270ULL: goto x86_l_4376;
	case 17275ULL: goto x86_l_437b;
	case 17280ULL: goto x86_l_4380;
	case 17285ULL: goto x86_l_4385;
	case 17290ULL: goto x86_l_438a;
	case 17292ULL: goto x86_l_438c;
	case 17294ULL: goto x86_l_438e;
	case 17300ULL: goto x86_l_4394;
	case 17305ULL: goto x86_l_4399;
	case 17314ULL: goto x86_l_43a2;
	case 17319ULL: goto x86_l_43a7;
	case 17325ULL: goto x86_l_43ad;
	case 17332ULL: goto x86_l_43b4;
	case 17337ULL: goto x86_l_43b9;
	case 17342ULL: goto x86_l_43be;
	case 17351ULL: goto x86_l_43c7;
	case 17357ULL: goto x86_l_43cd;
	case 17362ULL: goto x86_l_43d2;
	case 17367ULL: goto x86_l_43d7;
	case 17372ULL: goto x86_l_43dc;
	case 17377ULL: goto x86_l_43e1;
	case 17380ULL: goto x86_l_43e4;
	case 17382ULL: goto x86_l_43e6;
	case 17387ULL: goto x86_l_43eb;
	case 17392ULL: goto x86_l_43f0;
	case 17397ULL: goto x86_l_43f5;
	case 17402ULL: goto x86_l_43fa;
	case 17407ULL: goto x86_l_43ff;
	case 17409ULL: goto x86_l_4401;
	case 17411ULL: goto x86_l_4403;
	case 17417ULL: goto x86_l_4409;
	case 17423ULL: goto x86_l_440f;
	case 17429ULL: goto x86_l_4415;
	case 17433ULL: goto x86_l_4419;
	case 17438ULL: goto x86_l_441e;
	case 17443ULL: goto x86_l_4423;
	case 17449ULL: goto x86_l_4429;
	case 17451ULL: goto x86_l_442b;
	case 17456ULL: goto x86_l_4430;
	case 17461ULL: goto x86_l_4435;
	case 17466ULL: goto x86_l_443a;
	case 17471ULL: goto x86_l_443f;
	case 17476ULL: goto x86_l_4444;
	case 17478ULL: goto x86_l_4446;
	case 17480ULL: goto x86_l_4448;
	case 17486ULL: goto x86_l_444e;
	case 17495ULL: goto x86_l_4457;
	case 17501ULL: goto x86_l_445d;
	case 17508ULL: goto x86_l_4464;
	case 17513ULL: goto x86_l_4469;
	case 17518ULL: goto x86_l_446e;
	case 17527ULL: goto x86_l_4477;
	case 17529ULL: goto x86_l_4479;
	case 17534ULL: goto x86_l_447e;
	case 17539ULL: goto x86_l_4483;
	case 17544ULL: goto x86_l_4488;
	case 17549ULL: goto x86_l_448d;
	case 17554ULL: goto x86_l_4492;
	case 17556ULL: goto x86_l_4494;
	case 17558ULL: goto x86_l_4496;
	case 17564ULL: goto x86_l_449c;
	case 17573ULL: goto x86_l_44a5;
	case 17579ULL: goto x86_l_44ab;
	case 17586ULL: goto x86_l_44b2;
	case 17591ULL: goto x86_l_44b7;
	case 17596ULL: goto x86_l_44bc;
	case 17605ULL: goto x86_l_44c5;
	case 17607ULL: goto x86_l_44c7;
	case 17612ULL: goto x86_l_44cc;
	case 17617ULL: goto x86_l_44d1;
	case 17622ULL: goto x86_l_44d6;
	case 17627ULL: goto x86_l_44db;
	case 17632ULL: goto x86_l_44e0;
	case 17634ULL: goto x86_l_44e2;
	case 17636ULL: goto x86_l_44e4;
	case 17642ULL: goto x86_l_44ea;
	case 17651ULL: goto x86_l_44f3;
	case 17657ULL: goto x86_l_44f9;
	case 17664ULL: goto x86_l_4500;
	case 17669ULL: goto x86_l_4505;
	case 17674ULL: goto x86_l_450a;
	case 17683ULL: goto x86_l_4513;
	case 17685ULL: goto x86_l_4515;
	case 17690ULL: goto x86_l_451a;
	case 17695ULL: goto x86_l_451f;
	case 17700ULL: goto x86_l_4524;
	case 17705ULL: goto x86_l_4529;
	case 17710ULL: goto x86_l_452e;
	case 17712ULL: goto x86_l_4530;
	case 17714ULL: goto x86_l_4532;
	case 17720ULL: goto x86_l_4538;
	case 17729ULL: goto x86_l_4541;
	case 17735ULL: goto x86_l_4547;
	case 17742ULL: goto x86_l_454e;
	case 17747ULL: goto x86_l_4553;
	case 17752ULL: goto x86_l_4558;
	case 17761ULL: goto x86_l_4561;
	case 17763ULL: goto x86_l_4563;
	case 17768ULL: goto x86_l_4568;
	case 17773ULL: goto x86_l_456d;
	case 17778ULL: goto x86_l_4572;
	case 17783ULL: goto x86_l_4577;
	case 17788ULL: goto x86_l_457c;
	case 17790ULL: goto x86_l_457e;
	case 17792ULL: goto x86_l_4580;
	case 17798ULL: goto x86_l_4586;
	case 17807ULL: goto x86_l_458f;
	case 17813ULL: goto x86_l_4595;
	case 17820ULL: goto x86_l_459c;
	case 17825ULL: goto x86_l_45a1;
	case 17830ULL: goto x86_l_45a6;
	case 17839ULL: goto x86_l_45af;
	case 17841ULL: goto x86_l_45b1;
	case 17846ULL: goto x86_l_45b6;
	case 17851ULL: goto x86_l_45bb;
	case 17856ULL: goto x86_l_45c0;
	case 17861ULL: goto x86_l_45c5;
	case 17866ULL: goto x86_l_45ca;
	case 17868ULL: goto x86_l_45cc;
	case 17870ULL: goto x86_l_45ce;
	case 17876ULL: goto x86_l_45d4;
	case 17885ULL: goto x86_l_45dd;
	case 17891ULL: goto x86_l_45e3;
	case 17898ULL: goto x86_l_45ea;
	case 17903ULL: goto x86_l_45ef;
	case 17908ULL: goto x86_l_45f4;
	case 17917ULL: goto x86_l_45fd;
	case 17919ULL: goto x86_l_45ff;
	case 17924ULL: goto x86_l_4604;
	case 17929ULL: goto x86_l_4609;
	case 17934ULL: goto x86_l_460e;
	case 17939ULL: goto x86_l_4613;
	case 17944ULL: goto x86_l_4618;
	case 17946ULL: goto x86_l_461a;
	case 17948ULL: goto x86_l_461c;
	case 17954ULL: goto x86_l_4622;
	case 17959ULL: goto x86_l_4627;
	case 17968ULL: goto x86_l_4630;
	case 17973ULL: goto x86_l_4635;
	case 17979ULL: goto x86_l_463b;
	case 17986ULL: goto x86_l_4642;
	case 17991ULL: goto x86_l_4647;
	case 17996ULL: goto x86_l_464c;
	case 18005ULL: goto x86_l_4655;
	case 18007ULL: goto x86_l_4657;
	case 18012ULL: goto x86_l_465c;
	case 18017ULL: goto x86_l_4661;
	case 18022ULL: goto x86_l_4666;
	case 18027ULL: goto x86_l_466b;
	case 18032ULL: goto x86_l_4670;
	case 18034ULL: goto x86_l_4672;
	case 18036ULL: goto x86_l_4674;
	case 18042ULL: goto x86_l_467a;
	case 18047ULL: goto x86_l_467f;
	case 18056ULL: goto x86_l_4688;
	case 18061ULL: goto x86_l_468d;
	case 18067ULL: goto x86_l_4693;
	case 18074ULL: goto x86_l_469a;
	case 18079ULL: goto x86_l_469f;
	case 18084ULL: goto x86_l_46a4;
	case 18093ULL: goto x86_l_46ad;
	case 18099ULL: goto x86_l_46b3;
	case 18104ULL: goto x86_l_46b8;
	case 18109ULL: goto x86_l_46bd;
	case 18114ULL: goto x86_l_46c2;
	case 18119ULL: goto x86_l_46c7;
	case 18124ULL: goto x86_l_46cc;
	case 18126ULL: goto x86_l_46ce;
	case 18128ULL: goto x86_l_46d0;
	case 18134ULL: goto x86_l_46d6;
	case 18139ULL: goto x86_l_46db;
	case 18144ULL: goto x86_l_46e0;
	case 18149ULL: goto x86_l_46e5;
	case 18154ULL: goto x86_l_46ea;
	case 18162ULL: goto x86_l_46f2;
	case 18165ULL: goto x86_l_46f5;
	case 18171ULL: goto x86_l_46fb;
	case 18176ULL: goto x86_l_4700;
	case 18179ULL: goto x86_l_4703;
	case 18185ULL: goto x86_l_4709;
	case 18190ULL: goto x86_l_470e;
	case 18198ULL: goto x86_l_4716;
	case 18201ULL: goto x86_l_4719;
	case 18203ULL: goto x86_l_471b;
	case 18208ULL: goto x86_l_4720;
	case 18211ULL: goto x86_l_4723;
	case 18213ULL: goto x86_l_4725;
	case 18216ULL: goto x86_l_4728;
	case 18218ULL: goto x86_l_472a;
	case 18220ULL: goto x86_l_472c;
	case 18225ULL: goto x86_l_4731;
	case 18227ULL: goto x86_l_4733;
	case 18232ULL: goto x86_l_4738;
	case 18237ULL: goto x86_l_473d;
	case 18241ULL: goto x86_l_4741;
	case 18243ULL: goto x86_l_4743;
	case 18246ULL: goto x86_l_4746;
	case 18255ULL: goto x86_l_474f;
	case 18261ULL: goto x86_l_4755;
	case 18268ULL: goto x86_l_475c;
	case 18271ULL: goto x86_l_475f;
	case 18278ULL: goto x86_l_4766;
	case 18281ULL: goto x86_l_4769;
	case 18286ULL: goto x86_l_476e;
	case 18294ULL: goto x86_l_4776;
	case 18296ULL: goto x86_l_4778;
	case 18302ULL: goto x86_l_477e;
	case 18305ULL: goto x86_l_4781;
	case 18307ULL: goto x86_l_4783;
	case 18312ULL: goto x86_l_4788;
	case 18317ULL: goto x86_l_478d;
	case 18322ULL: goto x86_l_4792;
	case 18327ULL: goto x86_l_4797;
	case 18332ULL: goto x86_l_479c;
	case 18334ULL: goto x86_l_479e;
	case 18336ULL: goto x86_l_47a0;
	case 18342ULL: goto x86_l_47a6;
	case 18351ULL: goto x86_l_47af;
	case 18357ULL: goto x86_l_47b5;
	case 18364ULL: goto x86_l_47bc;
	case 18369ULL: goto x86_l_47c1;
	case 18374ULL: goto x86_l_47c6;
	case 18383ULL: goto x86_l_47cf;
	case 18385ULL: goto x86_l_47d1;
	case 18390ULL: goto x86_l_47d6;
	case 18395ULL: goto x86_l_47db;
	case 18400ULL: goto x86_l_47e0;
	case 18405ULL: goto x86_l_47e5;
	case 18410ULL: goto x86_l_47ea;
	case 18412ULL: goto x86_l_47ec;
	case 18414ULL: goto x86_l_47ee;
	case 18420ULL: goto x86_l_47f4;
	case 18429ULL: goto x86_l_47fd;
	case 18435ULL: goto x86_l_4803;
	case 18442ULL: goto x86_l_480a;
	case 18447ULL: goto x86_l_480f;
	case 18452ULL: goto x86_l_4814;
	case 18461ULL: goto x86_l_481d;
	case 18463ULL: goto x86_l_481f;
	case 18468ULL: goto x86_l_4824;
	case 18473ULL: goto x86_l_4829;
	case 18478ULL: goto x86_l_482e;
	case 18483ULL: goto x86_l_4833;
	case 18488ULL: goto x86_l_4838;
	case 18490ULL: goto x86_l_483a;
	case 18492ULL: goto x86_l_483c;
	case 18498ULL: goto x86_l_4842;
	case 18507ULL: goto x86_l_484b;
	case 18513ULL: goto x86_l_4851;
	case 18520ULL: goto x86_l_4858;
	case 18525ULL: goto x86_l_485d;
	case 18530ULL: goto x86_l_4862;
	case 18539ULL: goto x86_l_486b;
	case 18541ULL: goto x86_l_486d;
	case 18546ULL: goto x86_l_4872;
	case 18551ULL: goto x86_l_4877;
	case 18556ULL: goto x86_l_487c;
	case 18561ULL: goto x86_l_4881;
	case 18566ULL: goto x86_l_4886;
	case 18568ULL: goto x86_l_4888;
	case 18570ULL: goto x86_l_488a;
	case 18576ULL: goto x86_l_4890;
	case 18585ULL: goto x86_l_4899;
	case 18591ULL: goto x86_l_489f;
	case 18598ULL: goto x86_l_48a6;
	case 18603ULL: goto x86_l_48ab;
	case 18608ULL: goto x86_l_48b0;
	case 18617ULL: goto x86_l_48b9;
	case 18619ULL: goto x86_l_48bb;
	case 18624ULL: goto x86_l_48c0;
	case 18629ULL: goto x86_l_48c5;
	case 18634ULL: goto x86_l_48ca;
	case 18639ULL: goto x86_l_48cf;
	case 18644ULL: goto x86_l_48d4;
	case 18646ULL: goto x86_l_48d6;
	case 18648ULL: goto x86_l_48d8;
	case 18654ULL: goto x86_l_48de;
	case 18663ULL: goto x86_l_48e7;
	case 18669ULL: goto x86_l_48ed;
	case 18676ULL: goto x86_l_48f4;
	case 18681ULL: goto x86_l_48f9;
	case 18686ULL: goto x86_l_48fe;
	case 18695ULL: goto x86_l_4907;
	case 18697ULL: goto x86_l_4909;
	case 18702ULL: goto x86_l_490e;
	case 18707ULL: goto x86_l_4913;
	case 18712ULL: goto x86_l_4918;
	case 18717ULL: goto x86_l_491d;
	case 18722ULL: goto x86_l_4922;
	case 18724ULL: goto x86_l_4924;
	case 18726ULL: goto x86_l_4926;
	case 18732ULL: goto x86_l_492c;
	case 18741ULL: goto x86_l_4935;
	case 18747ULL: goto x86_l_493b;
	case 18754ULL: goto x86_l_4942;
	case 18759ULL: goto x86_l_4947;
	case 18764ULL: goto x86_l_494c;
	case 18773ULL: goto x86_l_4955;
	case 18775ULL: goto x86_l_4957;
	case 18780ULL: goto x86_l_495c;
	case 18785ULL: goto x86_l_4961;
	case 18790ULL: goto x86_l_4966;
	case 18795ULL: goto x86_l_496b;
	case 18800ULL: goto x86_l_4970;
	case 18802ULL: goto x86_l_4972;
	case 18804ULL: goto x86_l_4974;
	case 18810ULL: goto x86_l_497a;
	case 18819ULL: goto x86_l_4983;
	case 18825ULL: goto x86_l_4989;
	case 18832ULL: goto x86_l_4990;
	case 18837ULL: goto x86_l_4995;
	case 18842ULL: goto x86_l_499a;
	case 18851ULL: goto x86_l_49a3;
	case 18853ULL: goto x86_l_49a5;
	case 18858ULL: goto x86_l_49aa;
	case 18863ULL: goto x86_l_49af;
	case 18868ULL: goto x86_l_49b4;
	case 18873ULL: goto x86_l_49b9;
	case 18878ULL: goto x86_l_49be;
	case 18880ULL: goto x86_l_49c0;
	case 18882ULL: goto x86_l_49c2;
	case 18888ULL: goto x86_l_49c8;
	case 18897ULL: goto x86_l_49d1;
	case 18903ULL: goto x86_l_49d7;
	case 18910ULL: goto x86_l_49de;
	case 18915ULL: goto x86_l_49e3;
	case 18920ULL: goto x86_l_49e8;
	case 18929ULL: goto x86_l_49f1;
	case 18931ULL: goto x86_l_49f3;
	case 18936ULL: goto x86_l_49f8;
	case 18941ULL: goto x86_l_49fd;
	case 18946ULL: goto x86_l_4a02;
	case 18951ULL: goto x86_l_4a07;
	case 18956ULL: goto x86_l_4a0c;
	case 18958ULL: goto x86_l_4a0e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4277:
	/* 0x4277: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_427c:
	/* 0x427c: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_4285:
	/* 0x4285: je     42aa <generic_sleepable_preload+0x42aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42aa;
	}
x86_l_4287:
	/* 0x4287: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_428c:
	/* 0x428c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4291:
	/* 0x4291: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4296:
	/* 0x4296: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_429b:
	/* 0x429b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42a0:
	/* 0x42a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42a2:
	/* 0x42a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42a4:
	/* 0x42a4: js     6233 <generic_sleepable_preload+0x6233> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25139ULL;
	}
x86_l_42aa:
	/* 0x42aa: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_42b3:
	/* 0x42b3: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_42b9:
	/* 0x42b9: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_42c0:
	/* 0x42c0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_42c5:
	/* 0x42c5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42ca:
	/* 0x42ca: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_42d3:
	/* 0x42d3: je     42f8 <generic_sleepable_preload+0x42f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42f8;
	}
x86_l_42d5:
	/* 0x42d5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42da:
	/* 0x42da: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42df:
	/* 0x42df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42e4:
	/* 0x42e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42e9:
	/* 0x42e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42ee:
	/* 0x42ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42f0:
	/* 0x42f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42f2:
	/* 0x42f2: js     6526 <generic_sleepable_preload+0x6526> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25894ULL;
	}
x86_l_42f8:
	/* 0x42f8: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_4301:
	/* 0x4301: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_4307:
	/* 0x4307: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_430e:
	/* 0x430e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4313:
	/* 0x4313: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4318:
	/* 0x4318: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_4321:
	/* 0x4321: je     4346 <generic_sleepable_preload+0x4346> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4346;
	}
x86_l_4323:
	/* 0x4323: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4328:
	/* 0x4328: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_432d:
	/* 0x432d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4332:
	/* 0x4332: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4337:
	/* 0x4337: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_433c:
	/* 0x433c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_433e:
	/* 0x433e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4340:
	/* 0x4340: js     68f2 <generic_sleepable_preload+0x68f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26866ULL;
	}
x86_l_4346:
	/* 0x4346: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_434f:
	/* 0x434f: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_4355:
	/* 0x4355: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_435c:
	/* 0x435c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4361:
	/* 0x4361: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4366:
	/* 0x4366: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_436f:
	/* 0x436f: je     4394 <generic_sleepable_preload+0x4394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4394;
	}
x86_l_4371:
	/* 0x4371: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4376:
	/* 0x4376: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_437b:
	/* 0x437b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4380:
	/* 0x4380: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4385:
	/* 0x4385: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_438a:
	/* 0x438a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_438c:
	/* 0x438c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_438e:
	/* 0x438e: js     696e <generic_sleepable_preload+0x696e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26990ULL;
	}
x86_l_4394:
	/* 0x4394: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4399:
	/* 0x4399: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_43a2:
	/* 0x43a2: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43a7:
	/* 0x43a7: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_43ad:
	/* 0x43ad: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_43b4:
	/* 0x43b4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_43b9:
	/* 0x43b9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43be:
	/* 0x43be: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_43c7:
	/* 0x43c7: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_43cd:
	/* 0x43cd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43d2:
	/* 0x43d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_43d7:
	/* 0x43d7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43dc:
	/* 0x43dc: jmp    46c2 <generic_sleepable_preload+0x46c2> */
	goto x86_l_46c2;
x86_l_43e1:
	/* 0x43e1: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_43e4:
	/* 0x43e4: je     4409 <generic_sleepable_preload+0x4409> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4409;
	}
x86_l_43e6:
	/* 0x43e6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43eb:
	/* 0x43eb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_43f0:
	/* 0x43f0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43f5:
	/* 0x43f5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43fa:
	/* 0x43fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43ff:
	/* 0x43ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4401:
	/* 0x4401: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4403:
	/* 0x4403: js     46e0 <generic_sleepable_preload+0x46e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_46e0;
	}
x86_l_4409:
	/* 0x4409: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_440f:
	/* 0x440f: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_4415:
	/* 0x4415: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4419:
	/* 0x4419: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_441e:
	/* 0x441e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4423:
	/* 0x4423: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_4429:
	/* 0x4429: je     444e <generic_sleepable_preload+0x444e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_444e;
	}
x86_l_442b:
	/* 0x442b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4430:
	/* 0x4430: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4435:
	/* 0x4435: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_443a:
	/* 0x443a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_443f:
	/* 0x443f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4444:
	/* 0x4444: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4446:
	/* 0x4446: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4448:
	/* 0x4448: js     5423 <generic_sleepable_preload+0x5423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21539ULL;
	}
x86_l_444e:
	/* 0x444e: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_4457:
	/* 0x4457: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_445d:
	/* 0x445d: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4464:
	/* 0x4464: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4469:
	/* 0x4469: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_446e:
	/* 0x446e: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_4477:
	/* 0x4477: je     449c <generic_sleepable_preload+0x449c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_449c;
	}
x86_l_4479:
	/* 0x4479: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_447e:
	/* 0x447e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4483:
	/* 0x4483: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4488:
	/* 0x4488: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_448d:
	/* 0x448d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4492:
	/* 0x4492: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4494:
	/* 0x4494: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4496:
	/* 0x4496: js     610a <generic_sleepable_preload+0x610a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24842ULL;
	}
x86_l_449c:
	/* 0x449c: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_44a5:
	/* 0x44a5: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_44ab:
	/* 0x44ab: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_44b2:
	/* 0x44b2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_44b7:
	/* 0x44b7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44bc:
	/* 0x44bc: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_44c5:
	/* 0x44c5: je     44ea <generic_sleepable_preload+0x44ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44ea;
	}
x86_l_44c7:
	/* 0x44c7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44cc:
	/* 0x44cc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_44d1:
	/* 0x44d1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_44d6:
	/* 0x44d6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44db:
	/* 0x44db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44e0:
	/* 0x44e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44e2:
	/* 0x44e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44e4:
	/* 0x44e4: js     616e <generic_sleepable_preload+0x616e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24942ULL;
	}
x86_l_44ea:
	/* 0x44ea: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_44f3:
	/* 0x44f3: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_44f9:
	/* 0x44f9: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4500:
	/* 0x4500: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4505:
	/* 0x4505: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_450a:
	/* 0x450a: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_4513:
	/* 0x4513: je     4538 <generic_sleepable_preload+0x4538> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4538;
	}
x86_l_4515:
	/* 0x4515: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_451a:
	/* 0x451a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_451f:
	/* 0x451f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4524:
	/* 0x4524: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4529:
	/* 0x4529: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_452e:
	/* 0x452e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4530:
	/* 0x4530: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4532:
	/* 0x4532: js     61d2 <generic_sleepable_preload+0x61d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25042ULL;
	}
x86_l_4538:
	/* 0x4538: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_4541:
	/* 0x4541: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_4547:
	/* 0x4547: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_454e:
	/* 0x454e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4553:
	/* 0x4553: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4558:
	/* 0x4558: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_4561:
	/* 0x4561: je     4586 <generic_sleepable_preload+0x4586> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4586;
	}
x86_l_4563:
	/* 0x4563: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4568:
	/* 0x4568: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_456d:
	/* 0x456d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4572:
	/* 0x4572: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4577:
	/* 0x4577: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_457c:
	/* 0x457c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_457e:
	/* 0x457e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4580:
	/* 0x4580: js     6233 <generic_sleepable_preload+0x6233> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25139ULL;
	}
x86_l_4586:
	/* 0x4586: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_458f:
	/* 0x458f: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_4595:
	/* 0x4595: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_459c:
	/* 0x459c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_45a1:
	/* 0x45a1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45a6:
	/* 0x45a6: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_45af:
	/* 0x45af: je     45d4 <generic_sleepable_preload+0x45d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45d4;
	}
x86_l_45b1:
	/* 0x45b1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45b6:
	/* 0x45b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_45bb:
	/* 0x45bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45c0:
	/* 0x45c0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45c5:
	/* 0x45c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45ca:
	/* 0x45ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45cc:
	/* 0x45cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45ce:
	/* 0x45ce: js     6526 <generic_sleepable_preload+0x6526> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25894ULL;
	}
x86_l_45d4:
	/* 0x45d4: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_45dd:
	/* 0x45dd: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_45e3:
	/* 0x45e3: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_45ea:
	/* 0x45ea: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_45ef:
	/* 0x45ef: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45f4:
	/* 0x45f4: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_45fd:
	/* 0x45fd: je     4622 <generic_sleepable_preload+0x4622> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4622;
	}
x86_l_45ff:
	/* 0x45ff: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4604:
	/* 0x4604: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4609:
	/* 0x4609: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_460e:
	/* 0x460e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4613:
	/* 0x4613: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4618:
	/* 0x4618: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_461a:
	/* 0x461a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_461c:
	/* 0x461c: js     6a12 <generic_sleepable_preload+0x6a12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27154ULL;
	}
x86_l_4622:
	/* 0x4622: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4627:
	/* 0x4627: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_4630:
	/* 0x4630: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4635:
	/* 0x4635: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_463b:
	/* 0x463b: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4642:
	/* 0x4642: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4647:
	/* 0x4647: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_464c:
	/* 0x464c: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_4655:
	/* 0x4655: je     467a <generic_sleepable_preload+0x467a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_467a;
	}
x86_l_4657:
	/* 0x4657: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_465c:
	/* 0x465c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4661:
	/* 0x4661: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4666:
	/* 0x4666: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_466b:
	/* 0x466b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4670:
	/* 0x4670: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4672:
	/* 0x4672: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4674:
	/* 0x4674: js     696e <generic_sleepable_preload+0x696e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26990ULL;
	}
x86_l_467a:
	/* 0x467a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_467f:
	/* 0x467f: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_4688:
	/* 0x4688: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_468d:
	/* 0x468d: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_4693:
	/* 0x4693: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_469a:
	/* 0x469a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_469f:
	/* 0x469f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46a4:
	/* 0x46a4: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_46ad:
	/* 0x46ad: je     652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25901ULL;
	}
x86_l_46b3:
	/* 0x46b3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46b8:
	/* 0x46b8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46bd:
	/* 0x46bd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46c2:
	/* 0x46c2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46c7:
	/* 0x46c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46cc:
	/* 0x46cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46ce:
	/* 0x46ce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46d0:
	/* 0x46d0: jns    652d <generic_sleepable_preload+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25901ULL;
	}
x86_l_46d6:
	/* 0x46d6: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_46db:
	/* 0x46db: jmp    652b <generic_sleepable_preload+0x652b> */
	return 25899ULL;
x86_l_46e0:
	/* 0x46e0: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_46e5:
	/* 0x46e5: jmp    652b <generic_sleepable_preload+0x652b> */
	return 25899ULL;
x86_l_46ea:
	/* 0x46ea: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_46f2:
	/* 0x46f2: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_46f5:
	/* 0x46f5: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_46fb:
	/* 0x46fb: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4700:
	/* 0x4700: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4703:
	/* 0x4703: je     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21572ULL;
	}
x86_l_4709:
	/* 0x4709: jmp    5457 <generic_sleepable_preload+0x5457> */
	return 21591ULL;
x86_l_470e:
	/* 0x470e: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4716:
	/* 0x4716: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4719:
	/* 0x4719: je     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4725;
	}
x86_l_471b:
	/* 0x471b: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4720:
	/* 0x4720: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4723:
	/* 0x4723: jne    4738 <generic_sleepable_preload+0x4738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4738;
	}
x86_l_4725:
	/* 0x4725: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_4728:
	/* 0x4728: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_472a:
	/* 0x472a: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_472c:
	/* 0x472c: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_4731:
	/* 0x4731: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4733:
	/* 0x4733: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_4738:
	/* 0x4738: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_473d:
	/* 0x473d: mov    r14d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4741:
	/* 0x4741: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4743:
	/* 0x4743: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_4746:
	/* 0x4746: cmp    WORD PTR [r13+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_474f:
	/* 0x474f: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4755:
	/* 0x4755: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_475c:
	/* 0x475c: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_475f:
	/* 0x475f: mov    eax,DWORD PTR [r13+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_4766:
	/* 0x4766: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4769:
	/* 0x4769: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_476e:
	/* 0x476e: movzx  eax,WORD PTR [r13+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_4776:
	/* 0x4776: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4778:
	/* 0x4778: je     4a63 <generic_sleepable_preload+0x4a63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19043ULL;
	}
x86_l_477e:
	/* 0x477e: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4781:
	/* 0x4781: je     47a6 <generic_sleepable_preload+0x47a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47a6;
	}
x86_l_4783:
	/* 0x4783: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4788:
	/* 0x4788: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_478d:
	/* 0x478d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4792:
	/* 0x4792: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4797:
	/* 0x4797: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_479c:
	/* 0x479c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_479e:
	/* 0x479e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47a0:
	/* 0x47a0: js     4d6b <generic_sleepable_preload+0x4d6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19819ULL;
	}
x86_l_47a6:
	/* 0x47a6: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_47af:
	/* 0x47af: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_47b5:
	/* 0x47b5: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_47bc:
	/* 0x47bc: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_47c1:
	/* 0x47c1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47c6:
	/* 0x47c6: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_47cf:
	/* 0x47cf: je     47f4 <generic_sleepable_preload+0x47f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47f4;
	}
x86_l_47d1:
	/* 0x47d1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47d6:
	/* 0x47d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47db:
	/* 0x47db: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47e0:
	/* 0x47e0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47e5:
	/* 0x47e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47ea:
	/* 0x47ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47ec:
	/* 0x47ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47ee:
	/* 0x47ee: js     542d <generic_sleepable_preload+0x542d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21549ULL;
	}
x86_l_47f4:
	/* 0x47f4: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_47fd:
	/* 0x47fd: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4803:
	/* 0x4803: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_480a:
	/* 0x480a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_480f:
	/* 0x480f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4814:
	/* 0x4814: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_481d:
	/* 0x481d: je     4842 <generic_sleepable_preload+0x4842> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4842;
	}
x86_l_481f:
	/* 0x481f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4824:
	/* 0x4824: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4829:
	/* 0x4829: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_482e:
	/* 0x482e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4833:
	/* 0x4833: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4838:
	/* 0x4838: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_483a:
	/* 0x483a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_483c:
	/* 0x483c: js     6114 <generic_sleepable_preload+0x6114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24852ULL;
	}
x86_l_4842:
	/* 0x4842: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_484b:
	/* 0x484b: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4851:
	/* 0x4851: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_4858:
	/* 0x4858: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_485d:
	/* 0x485d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4862:
	/* 0x4862: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_486b:
	/* 0x486b: je     4890 <generic_sleepable_preload+0x4890> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4890;
	}
x86_l_486d:
	/* 0x486d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4872:
	/* 0x4872: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4877:
	/* 0x4877: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_487c:
	/* 0x487c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4881:
	/* 0x4881: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4886:
	/* 0x4886: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4888:
	/* 0x4888: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_488a:
	/* 0x488a: js     6178 <generic_sleepable_preload+0x6178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24952ULL;
	}
x86_l_4890:
	/* 0x4890: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_4899:
	/* 0x4899: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_489f:
	/* 0x489f: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_48a6:
	/* 0x48a6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_48ab:
	/* 0x48ab: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48b0:
	/* 0x48b0: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_48b9:
	/* 0x48b9: je     48de <generic_sleepable_preload+0x48de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48de;
	}
x86_l_48bb:
	/* 0x48bb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48c0:
	/* 0x48c0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_48c5:
	/* 0x48c5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48ca:
	/* 0x48ca: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48cf:
	/* 0x48cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48d4:
	/* 0x48d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48d6:
	/* 0x48d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48d8:
	/* 0x48d8: js     61dc <generic_sleepable_preload+0x61dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25052ULL;
	}
x86_l_48de:
	/* 0x48de: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_48e7:
	/* 0x48e7: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_48ed:
	/* 0x48ed: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_48f4:
	/* 0x48f4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_48f9:
	/* 0x48f9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48fe:
	/* 0x48fe: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_4907:
	/* 0x4907: je     492c <generic_sleepable_preload+0x492c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_492c;
	}
x86_l_4909:
	/* 0x4909: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_490e:
	/* 0x490e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4913:
	/* 0x4913: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4918:
	/* 0x4918: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_491d:
	/* 0x491d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4922:
	/* 0x4922: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4924:
	/* 0x4924: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4926:
	/* 0x4926: js     623d <generic_sleepable_preload+0x623d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25149ULL;
	}
x86_l_492c:
	/* 0x492c: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_4935:
	/* 0x4935: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_493b:
	/* 0x493b: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_4942:
	/* 0x4942: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4947:
	/* 0x4947: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_494c:
	/* 0x494c: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_4955:
	/* 0x4955: je     497a <generic_sleepable_preload+0x497a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_497a;
	}
x86_l_4957:
	/* 0x4957: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_495c:
	/* 0x495c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4961:
	/* 0x4961: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4966:
	/* 0x4966: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_496b:
	/* 0x496b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4970:
	/* 0x4970: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4972:
	/* 0x4972: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4974:
	/* 0x4974: js     65da <generic_sleepable_preload+0x65da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26074ULL;
	}
x86_l_497a:
	/* 0x497a: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_4983:
	/* 0x4983: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4989:
	/* 0x4989: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_4990:
	/* 0x4990: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4995:
	/* 0x4995: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_499a:
	/* 0x499a: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_49a3:
	/* 0x49a3: je     49c8 <generic_sleepable_preload+0x49c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49c8;
	}
x86_l_49a5:
	/* 0x49a5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49aa:
	/* 0x49aa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49af:
	/* 0x49af: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49b4:
	/* 0x49b4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49b9:
	/* 0x49b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49be:
	/* 0x49be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49c0:
	/* 0x49c0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49c2:
	/* 0x49c2: js     68fe <generic_sleepable_preload+0x68fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26878ULL;
	}
x86_l_49c8:
	/* 0x49c8: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_49d1:
	/* 0x49d1: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_49d7:
	/* 0x49d7: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_49de:
	/* 0x49de: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49e3:
	/* 0x49e3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49e8:
	/* 0x49e8: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_49f1:
	/* 0x49f1: je     4a16 <generic_sleepable_preload+0x4a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18966ULL;
	}
x86_l_49f3:
	/* 0x49f3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49f8:
	/* 0x49f8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49fd:
	/* 0x49fd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a02:
	/* 0x4a02: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a07:
	/* 0x4a07: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a0c:
	/* 0x4a0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a0e:
	/* 0x4a0e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
	return 18960ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18960ULL: goto x86_l_4a10;
	case 18966ULL: goto x86_l_4a16;
	case 18971ULL: goto x86_l_4a1b;
	case 18980ULL: goto x86_l_4a24;
	case 18985ULL: goto x86_l_4a29;
	case 18991ULL: goto x86_l_4a2f;
	case 18998ULL: goto x86_l_4a36;
	case 19003ULL: goto x86_l_4a3b;
	case 19008ULL: goto x86_l_4a40;
	case 19017ULL: goto x86_l_4a49;
	case 19023ULL: goto x86_l_4a4f;
	case 19028ULL: goto x86_l_4a54;
	case 19033ULL: goto x86_l_4a59;
	case 19038ULL: goto x86_l_4a5e;
	case 19043ULL: goto x86_l_4a63;
	case 19046ULL: goto x86_l_4a66;
	case 19048ULL: goto x86_l_4a68;
	case 19053ULL: goto x86_l_4a6d;
	case 19058ULL: goto x86_l_4a72;
	case 19063ULL: goto x86_l_4a77;
	case 19068ULL: goto x86_l_4a7c;
	case 19073ULL: goto x86_l_4a81;
	case 19075ULL: goto x86_l_4a83;
	case 19077ULL: goto x86_l_4a85;
	case 19083ULL: goto x86_l_4a8b;
	case 19092ULL: goto x86_l_4a94;
	case 19098ULL: goto x86_l_4a9a;
	case 19105ULL: goto x86_l_4aa1;
	case 19110ULL: goto x86_l_4aa6;
	case 19115ULL: goto x86_l_4aab;
	case 19124ULL: goto x86_l_4ab4;
	case 19126ULL: goto x86_l_4ab6;
	case 19131ULL: goto x86_l_4abb;
	case 19136ULL: goto x86_l_4ac0;
	case 19141ULL: goto x86_l_4ac5;
	case 19146ULL: goto x86_l_4aca;
	case 19151ULL: goto x86_l_4acf;
	case 19153ULL: goto x86_l_4ad1;
	case 19155ULL: goto x86_l_4ad3;
	case 19161ULL: goto x86_l_4ad9;
	case 19170ULL: goto x86_l_4ae2;
	case 19176ULL: goto x86_l_4ae8;
	case 19183ULL: goto x86_l_4aef;
	case 19188ULL: goto x86_l_4af4;
	case 19193ULL: goto x86_l_4af9;
	case 19202ULL: goto x86_l_4b02;
	case 19204ULL: goto x86_l_4b04;
	case 19209ULL: goto x86_l_4b09;
	case 19214ULL: goto x86_l_4b0e;
	case 19219ULL: goto x86_l_4b13;
	case 19224ULL: goto x86_l_4b18;
	case 19229ULL: goto x86_l_4b1d;
	case 19231ULL: goto x86_l_4b1f;
	case 19233ULL: goto x86_l_4b21;
	case 19239ULL: goto x86_l_4b27;
	case 19248ULL: goto x86_l_4b30;
	case 19254ULL: goto x86_l_4b36;
	case 19261ULL: goto x86_l_4b3d;
	case 19266ULL: goto x86_l_4b42;
	case 19271ULL: goto x86_l_4b47;
	case 19280ULL: goto x86_l_4b50;
	case 19282ULL: goto x86_l_4b52;
	case 19287ULL: goto x86_l_4b57;
	case 19292ULL: goto x86_l_4b5c;
	case 19297ULL: goto x86_l_4b61;
	case 19302ULL: goto x86_l_4b66;
	case 19307ULL: goto x86_l_4b6b;
	case 19309ULL: goto x86_l_4b6d;
	case 19311ULL: goto x86_l_4b6f;
	case 19317ULL: goto x86_l_4b75;
	case 19326ULL: goto x86_l_4b7e;
	case 19332ULL: goto x86_l_4b84;
	case 19339ULL: goto x86_l_4b8b;
	case 19344ULL: goto x86_l_4b90;
	case 19349ULL: goto x86_l_4b95;
	case 19358ULL: goto x86_l_4b9e;
	case 19360ULL: goto x86_l_4ba0;
	case 19365ULL: goto x86_l_4ba5;
	case 19370ULL: goto x86_l_4baa;
	case 19375ULL: goto x86_l_4baf;
	case 19380ULL: goto x86_l_4bb4;
	case 19385ULL: goto x86_l_4bb9;
	case 19387ULL: goto x86_l_4bbb;
	case 19389ULL: goto x86_l_4bbd;
	case 19395ULL: goto x86_l_4bc3;
	case 19404ULL: goto x86_l_4bcc;
	case 19410ULL: goto x86_l_4bd2;
	case 19417ULL: goto x86_l_4bd9;
	case 19422ULL: goto x86_l_4bde;
	case 19427ULL: goto x86_l_4be3;
	case 19436ULL: goto x86_l_4bec;
	case 19438ULL: goto x86_l_4bee;
	case 19443ULL: goto x86_l_4bf3;
	case 19448ULL: goto x86_l_4bf8;
	case 19453ULL: goto x86_l_4bfd;
	case 19458ULL: goto x86_l_4c02;
	case 19463ULL: goto x86_l_4c07;
	case 19465ULL: goto x86_l_4c09;
	case 19467ULL: goto x86_l_4c0b;
	case 19473ULL: goto x86_l_4c11;
	case 19482ULL: goto x86_l_4c1a;
	case 19488ULL: goto x86_l_4c20;
	case 19495ULL: goto x86_l_4c27;
	case 19500ULL: goto x86_l_4c2c;
	case 19505ULL: goto x86_l_4c31;
	case 19514ULL: goto x86_l_4c3a;
	case 19516ULL: goto x86_l_4c3c;
	case 19521ULL: goto x86_l_4c41;
	case 19526ULL: goto x86_l_4c46;
	case 19531ULL: goto x86_l_4c4b;
	case 19536ULL: goto x86_l_4c50;
	case 19541ULL: goto x86_l_4c55;
	case 19543ULL: goto x86_l_4c57;
	case 19545ULL: goto x86_l_4c59;
	case 19551ULL: goto x86_l_4c5f;
	case 19560ULL: goto x86_l_4c68;
	case 19566ULL: goto x86_l_4c6e;
	case 19573ULL: goto x86_l_4c75;
	case 19578ULL: goto x86_l_4c7a;
	case 19583ULL: goto x86_l_4c7f;
	case 19592ULL: goto x86_l_4c88;
	case 19594ULL: goto x86_l_4c8a;
	case 19599ULL: goto x86_l_4c8f;
	case 19604ULL: goto x86_l_4c94;
	case 19609ULL: goto x86_l_4c99;
	case 19614ULL: goto x86_l_4c9e;
	case 19619ULL: goto x86_l_4ca3;
	case 19621ULL: goto x86_l_4ca5;
	case 19623ULL: goto x86_l_4ca7;
	case 19629ULL: goto x86_l_4cad;
	case 19634ULL: goto x86_l_4cb2;
	case 19643ULL: goto x86_l_4cbb;
	case 19648ULL: goto x86_l_4cc0;
	case 19654ULL: goto x86_l_4cc6;
	case 19661ULL: goto x86_l_4ccd;
	case 19666ULL: goto x86_l_4cd2;
	case 19671ULL: goto x86_l_4cd7;
	case 19680ULL: goto x86_l_4ce0;
	case 19682ULL: goto x86_l_4ce2;
	case 19687ULL: goto x86_l_4ce7;
	case 19692ULL: goto x86_l_4cec;
	case 19697ULL: goto x86_l_4cf1;
	case 19702ULL: goto x86_l_4cf6;
	case 19707ULL: goto x86_l_4cfb;
	case 19709ULL: goto x86_l_4cfd;
	case 19711ULL: goto x86_l_4cff;
	case 19717ULL: goto x86_l_4d05;
	case 19722ULL: goto x86_l_4d0a;
	case 19731ULL: goto x86_l_4d13;
	case 19736ULL: goto x86_l_4d18;
	case 19742ULL: goto x86_l_4d1e;
	case 19749ULL: goto x86_l_4d25;
	case 19754ULL: goto x86_l_4d2a;
	case 19759ULL: goto x86_l_4d2f;
	case 19768ULL: goto x86_l_4d38;
	case 19774ULL: goto x86_l_4d3e;
	case 19779ULL: goto x86_l_4d43;
	case 19784ULL: goto x86_l_4d48;
	case 19789ULL: goto x86_l_4d4d;
	case 19794ULL: goto x86_l_4d52;
	case 19799ULL: goto x86_l_4d57;
	case 19801ULL: goto x86_l_4d59;
	case 19803ULL: goto x86_l_4d5b;
	case 19809ULL: goto x86_l_4d61;
	case 19814ULL: goto x86_l_4d66;
	case 19819ULL: goto x86_l_4d6b;
	case 19824ULL: goto x86_l_4d70;
	case 19829ULL: goto x86_l_4d75;
	case 19837ULL: goto x86_l_4d7d;
	case 19840ULL: goto x86_l_4d80;
	case 19842ULL: goto x86_l_4d82;
	case 19847ULL: goto x86_l_4d87;
	case 19850ULL: goto x86_l_4d8a;
	case 19852ULL: goto x86_l_4d8c;
	case 19855ULL: goto x86_l_4d8f;
	case 19857ULL: goto x86_l_4d91;
	case 19859ULL: goto x86_l_4d93;
	case 19864ULL: goto x86_l_4d98;
	case 19866ULL: goto x86_l_4d9a;
	case 19871ULL: goto x86_l_4d9f;
	case 19876ULL: goto x86_l_4da4;
	case 19880ULL: goto x86_l_4da8;
	case 19882ULL: goto x86_l_4daa;
	case 19885ULL: goto x86_l_4dad;
	case 19894ULL: goto x86_l_4db6;
	case 19900ULL: goto x86_l_4dbc;
	case 19907ULL: goto x86_l_4dc3;
	case 19910ULL: goto x86_l_4dc6;
	case 19917ULL: goto x86_l_4dcd;
	case 19920ULL: goto x86_l_4dd0;
	case 19925ULL: goto x86_l_4dd5;
	case 19933ULL: goto x86_l_4ddd;
	case 19935ULL: goto x86_l_4ddf;
	case 19941ULL: goto x86_l_4de5;
	case 19944ULL: goto x86_l_4de8;
	case 19946ULL: goto x86_l_4dea;
	case 19951ULL: goto x86_l_4def;
	case 19956ULL: goto x86_l_4df4;
	case 19961ULL: goto x86_l_4df9;
	case 19966ULL: goto x86_l_4dfe;
	case 19971ULL: goto x86_l_4e03;
	case 19973ULL: goto x86_l_4e05;
	case 19975ULL: goto x86_l_4e07;
	case 19981ULL: goto x86_l_4e0d;
	case 19990ULL: goto x86_l_4e16;
	case 19996ULL: goto x86_l_4e1c;
	case 20003ULL: goto x86_l_4e23;
	case 20008ULL: goto x86_l_4e28;
	case 20013ULL: goto x86_l_4e2d;
	case 20022ULL: goto x86_l_4e36;
	case 20024ULL: goto x86_l_4e38;
	case 20029ULL: goto x86_l_4e3d;
	case 20034ULL: goto x86_l_4e42;
	case 20039ULL: goto x86_l_4e47;
	case 20044ULL: goto x86_l_4e4c;
	case 20049ULL: goto x86_l_4e51;
	case 20051ULL: goto x86_l_4e53;
	case 20053ULL: goto x86_l_4e55;
	case 20059ULL: goto x86_l_4e5b;
	case 20068ULL: goto x86_l_4e64;
	case 20074ULL: goto x86_l_4e6a;
	case 20081ULL: goto x86_l_4e71;
	case 20086ULL: goto x86_l_4e76;
	case 20091ULL: goto x86_l_4e7b;
	case 20100ULL: goto x86_l_4e84;
	case 20102ULL: goto x86_l_4e86;
	case 20107ULL: goto x86_l_4e8b;
	case 20112ULL: goto x86_l_4e90;
	case 20117ULL: goto x86_l_4e95;
	case 20122ULL: goto x86_l_4e9a;
	case 20127ULL: goto x86_l_4e9f;
	case 20129ULL: goto x86_l_4ea1;
	case 20131ULL: goto x86_l_4ea3;
	case 20137ULL: goto x86_l_4ea9;
	case 20146ULL: goto x86_l_4eb2;
	case 20152ULL: goto x86_l_4eb8;
	case 20159ULL: goto x86_l_4ebf;
	case 20164ULL: goto x86_l_4ec4;
	case 20169ULL: goto x86_l_4ec9;
	case 20178ULL: goto x86_l_4ed2;
	case 20180ULL: goto x86_l_4ed4;
	case 20185ULL: goto x86_l_4ed9;
	case 20190ULL: goto x86_l_4ede;
	case 20195ULL: goto x86_l_4ee3;
	case 20200ULL: goto x86_l_4ee8;
	case 20205ULL: goto x86_l_4eed;
	case 20207ULL: goto x86_l_4eef;
	case 20209ULL: goto x86_l_4ef1;
	case 20215ULL: goto x86_l_4ef7;
	case 20224ULL: goto x86_l_4f00;
	case 20230ULL: goto x86_l_4f06;
	case 20237ULL: goto x86_l_4f0d;
	case 20242ULL: goto x86_l_4f12;
	case 20247ULL: goto x86_l_4f17;
	case 20256ULL: goto x86_l_4f20;
	case 20258ULL: goto x86_l_4f22;
	case 20263ULL: goto x86_l_4f27;
	case 20268ULL: goto x86_l_4f2c;
	case 20273ULL: goto x86_l_4f31;
	case 20278ULL: goto x86_l_4f36;
	case 20283ULL: goto x86_l_4f3b;
	case 20285ULL: goto x86_l_4f3d;
	case 20287ULL: goto x86_l_4f3f;
	case 20293ULL: goto x86_l_4f45;
	case 20302ULL: goto x86_l_4f4e;
	case 20308ULL: goto x86_l_4f54;
	case 20315ULL: goto x86_l_4f5b;
	case 20320ULL: goto x86_l_4f60;
	case 20325ULL: goto x86_l_4f65;
	case 20334ULL: goto x86_l_4f6e;
	case 20336ULL: goto x86_l_4f70;
	case 20341ULL: goto x86_l_4f75;
	case 20346ULL: goto x86_l_4f7a;
	case 20351ULL: goto x86_l_4f7f;
	case 20356ULL: goto x86_l_4f84;
	case 20361ULL: goto x86_l_4f89;
	case 20363ULL: goto x86_l_4f8b;
	case 20365ULL: goto x86_l_4f8d;
	case 20371ULL: goto x86_l_4f93;
	case 20380ULL: goto x86_l_4f9c;
	case 20386ULL: goto x86_l_4fa2;
	case 20393ULL: goto x86_l_4fa9;
	case 20398ULL: goto x86_l_4fae;
	case 20403ULL: goto x86_l_4fb3;
	case 20412ULL: goto x86_l_4fbc;
	case 20414ULL: goto x86_l_4fbe;
	case 20419ULL: goto x86_l_4fc3;
	case 20424ULL: goto x86_l_4fc8;
	case 20429ULL: goto x86_l_4fcd;
	case 20434ULL: goto x86_l_4fd2;
	case 20439ULL: goto x86_l_4fd7;
	case 20441ULL: goto x86_l_4fd9;
	case 20443ULL: goto x86_l_4fdb;
	case 20449ULL: goto x86_l_4fe1;
	case 20458ULL: goto x86_l_4fea;
	case 20464ULL: goto x86_l_4ff0;
	case 20471ULL: goto x86_l_4ff7;
	case 20476ULL: goto x86_l_4ffc;
	case 20481ULL: goto x86_l_5001;
	case 20490ULL: goto x86_l_500a;
	case 20492ULL: goto x86_l_500c;
	case 20497ULL: goto x86_l_5011;
	case 20502ULL: goto x86_l_5016;
	case 20507ULL: goto x86_l_501b;
	case 20512ULL: goto x86_l_5020;
	case 20517ULL: goto x86_l_5025;
	case 20519ULL: goto x86_l_5027;
	case 20521ULL: goto x86_l_5029;
	case 20527ULL: goto x86_l_502f;
	case 20536ULL: goto x86_l_5038;
	case 20542ULL: goto x86_l_503e;
	case 20549ULL: goto x86_l_5045;
	case 20554ULL: goto x86_l_504a;
	case 20559ULL: goto x86_l_504f;
	case 20568ULL: goto x86_l_5058;
	case 20570ULL: goto x86_l_505a;
	case 20575ULL: goto x86_l_505f;
	case 20580ULL: goto x86_l_5064;
	case 20585ULL: goto x86_l_5069;
	case 20590ULL: goto x86_l_506e;
	case 20595ULL: goto x86_l_5073;
	case 20597ULL: goto x86_l_5075;
	case 20599ULL: goto x86_l_5077;
	case 20605ULL: goto x86_l_507d;
	case 20610ULL: goto x86_l_5082;
	case 20619ULL: goto x86_l_508b;
	case 20625ULL: goto x86_l_5091;
	case 20632ULL: goto x86_l_5098;
	case 20637ULL: goto x86_l_509d;
	case 20642ULL: goto x86_l_50a2;
	case 20651ULL: goto x86_l_50ab;
	case 20657ULL: goto x86_l_50b1;
	case 20662ULL: goto x86_l_50b6;
	case 20667ULL: goto x86_l_50bb;
	case 20672ULL: goto x86_l_50c0;
	case 20677ULL: goto x86_l_50c5;
	case 20680ULL: goto x86_l_50c8;
	case 20682ULL: goto x86_l_50ca;
	case 20687ULL: goto x86_l_50cf;
	case 20692ULL: goto x86_l_50d4;
	case 20697ULL: goto x86_l_50d9;
	case 20702ULL: goto x86_l_50de;
	case 20707ULL: goto x86_l_50e3;
	case 20709ULL: goto x86_l_50e5;
	case 20711ULL: goto x86_l_50e7;
	case 20717ULL: goto x86_l_50ed;
	case 20726ULL: goto x86_l_50f6;
	case 20732ULL: goto x86_l_50fc;
	case 20739ULL: goto x86_l_5103;
	case 20744ULL: goto x86_l_5108;
	case 20749ULL: goto x86_l_510d;
	case 20758ULL: goto x86_l_5116;
	case 20760ULL: goto x86_l_5118;
	case 20765ULL: goto x86_l_511d;
	case 20770ULL: goto x86_l_5122;
	case 20775ULL: goto x86_l_5127;
	case 20780ULL: goto x86_l_512c;
	case 20785ULL: goto x86_l_5131;
	case 20787ULL: goto x86_l_5133;
	case 20789ULL: goto x86_l_5135;
	case 20795ULL: goto x86_l_513b;
	case 20804ULL: goto x86_l_5144;
	case 20810ULL: goto x86_l_514a;
	case 20817ULL: goto x86_l_5151;
	case 20822ULL: goto x86_l_5156;
	case 20827ULL: goto x86_l_515b;
	case 20836ULL: goto x86_l_5164;
	case 20838ULL: goto x86_l_5166;
	case 20843ULL: goto x86_l_516b;
	case 20848ULL: goto x86_l_5170;
	case 20853ULL: goto x86_l_5175;
	case 20858ULL: goto x86_l_517a;
	case 20863ULL: goto x86_l_517f;
	case 20865ULL: goto x86_l_5181;
	case 20867ULL: goto x86_l_5183;
	case 20873ULL: goto x86_l_5189;
	case 20882ULL: goto x86_l_5192;
	case 20888ULL: goto x86_l_5198;
	case 20895ULL: goto x86_l_519f;
	case 20900ULL: goto x86_l_51a4;
	case 20905ULL: goto x86_l_51a9;
	case 20914ULL: goto x86_l_51b2;
	case 20916ULL: goto x86_l_51b4;
	case 20921ULL: goto x86_l_51b9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4a10:
	/* 0x4a10: js     697a <generic_sleepable_preload+0x697a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27002ULL;
	}
x86_l_4a16:
	/* 0x4a16: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4a1b:
	/* 0x4a1b: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_4a24:
	/* 0x4a24: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4a29:
	/* 0x4a29: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4a2f:
	/* 0x4a2f: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_4a36:
	/* 0x4a36: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4a3b:
	/* 0x4a3b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a40:
	/* 0x4a40: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_4a49:
	/* 0x4a49: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4a4f:
	/* 0x4a4f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a54:
	/* 0x4a54: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a59:
	/* 0x4a59: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a5e:
	/* 0x4a5e: jmp    4d4d <generic_sleepable_preload+0x4d4d> */
	goto x86_l_4d4d;
x86_l_4a63:
	/* 0x4a63: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4a66:
	/* 0x4a66: je     4a8b <generic_sleepable_preload+0x4a8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a8b;
	}
x86_l_4a68:
	/* 0x4a68: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a6d:
	/* 0x4a6d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a72:
	/* 0x4a72: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a77:
	/* 0x4a77: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a7c:
	/* 0x4a7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a81:
	/* 0x4a81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a83:
	/* 0x4a83: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a85:
	/* 0x4a85: js     4d6b <generic_sleepable_preload+0x4d6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d6b;
	}
x86_l_4a8b:
	/* 0x4a8b: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_4a94:
	/* 0x4a94: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4a9a:
	/* 0x4a9a: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_4aa1:
	/* 0x4aa1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4aa6:
	/* 0x4aa6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4aab:
	/* 0x4aab: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_4ab4:
	/* 0x4ab4: je     4ad9 <generic_sleepable_preload+0x4ad9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ad9;
	}
x86_l_4ab6:
	/* 0x4ab6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4abb:
	/* 0x4abb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ac0:
	/* 0x4ac0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ac5:
	/* 0x4ac5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4aca:
	/* 0x4aca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4acf:
	/* 0x4acf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ad1:
	/* 0x4ad1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ad3:
	/* 0x4ad3: js     542d <generic_sleepable_preload+0x542d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21549ULL;
	}
x86_l_4ad9:
	/* 0x4ad9: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_4ae2:
	/* 0x4ae2: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4ae8:
	/* 0x4ae8: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_4aef:
	/* 0x4aef: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4af4:
	/* 0x4af4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4af9:
	/* 0x4af9: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_4b02:
	/* 0x4b02: je     4b27 <generic_sleepable_preload+0x4b27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b27;
	}
x86_l_4b04:
	/* 0x4b04: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b09:
	/* 0x4b09: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b0e:
	/* 0x4b0e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b13:
	/* 0x4b13: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b18:
	/* 0x4b18: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b1d:
	/* 0x4b1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b1f:
	/* 0x4b1f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b21:
	/* 0x4b21: js     6114 <generic_sleepable_preload+0x6114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24852ULL;
	}
x86_l_4b27:
	/* 0x4b27: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_4b30:
	/* 0x4b30: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4b36:
	/* 0x4b36: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_4b3d:
	/* 0x4b3d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b42:
	/* 0x4b42: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b47:
	/* 0x4b47: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_4b50:
	/* 0x4b50: je     4b75 <generic_sleepable_preload+0x4b75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b75;
	}
x86_l_4b52:
	/* 0x4b52: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b57:
	/* 0x4b57: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b5c:
	/* 0x4b5c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b61:
	/* 0x4b61: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b66:
	/* 0x4b66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b6b:
	/* 0x4b6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b6d:
	/* 0x4b6d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b6f:
	/* 0x4b6f: js     6178 <generic_sleepable_preload+0x6178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24952ULL;
	}
x86_l_4b75:
	/* 0x4b75: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_4b7e:
	/* 0x4b7e: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4b84:
	/* 0x4b84: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_4b8b:
	/* 0x4b8b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b90:
	/* 0x4b90: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b95:
	/* 0x4b95: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_4b9e:
	/* 0x4b9e: je     4bc3 <generic_sleepable_preload+0x4bc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc3;
	}
x86_l_4ba0:
	/* 0x4ba0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ba5:
	/* 0x4ba5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4baa:
	/* 0x4baa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4baf:
	/* 0x4baf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bb4:
	/* 0x4bb4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4bb9:
	/* 0x4bb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bbb:
	/* 0x4bbb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4bbd:
	/* 0x4bbd: js     61dc <generic_sleepable_preload+0x61dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25052ULL;
	}
x86_l_4bc3:
	/* 0x4bc3: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_4bcc:
	/* 0x4bcc: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4bd2:
	/* 0x4bd2: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_4bd9:
	/* 0x4bd9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4bde:
	/* 0x4bde: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4be3:
	/* 0x4be3: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_4bec:
	/* 0x4bec: je     4c11 <generic_sleepable_preload+0x4c11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c11;
	}
x86_l_4bee:
	/* 0x4bee: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bf3:
	/* 0x4bf3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4bf8:
	/* 0x4bf8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4bfd:
	/* 0x4bfd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c02:
	/* 0x4c02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c07:
	/* 0x4c07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c09:
	/* 0x4c09: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c0b:
	/* 0x4c0b: js     623d <generic_sleepable_preload+0x623d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25149ULL;
	}
x86_l_4c11:
	/* 0x4c11: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_4c1a:
	/* 0x4c1a: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4c20:
	/* 0x4c20: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_4c27:
	/* 0x4c27: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c2c:
	/* 0x4c2c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c31:
	/* 0x4c31: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_4c3a:
	/* 0x4c3a: je     4c5f <generic_sleepable_preload+0x4c5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c5f;
	}
x86_l_4c3c:
	/* 0x4c3c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c41:
	/* 0x4c41: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c46:
	/* 0x4c46: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c4b:
	/* 0x4c4b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c50:
	/* 0x4c50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c55:
	/* 0x4c55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c57:
	/* 0x4c57: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c59:
	/* 0x4c59: js     65da <generic_sleepable_preload+0x65da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26074ULL;
	}
x86_l_4c5f:
	/* 0x4c5f: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_4c68:
	/* 0x4c68: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4c6e:
	/* 0x4c6e: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_4c75:
	/* 0x4c75: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c7a:
	/* 0x4c7a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c7f:
	/* 0x4c7f: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_4c88:
	/* 0x4c88: je     4cad <generic_sleepable_preload+0x4cad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cad;
	}
x86_l_4c8a:
	/* 0x4c8a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c8f:
	/* 0x4c8f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c94:
	/* 0x4c94: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c99:
	/* 0x4c99: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c9e:
	/* 0x4c9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ca3:
	/* 0x4ca3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ca5:
	/* 0x4ca5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ca7:
	/* 0x4ca7: js     6a28 <generic_sleepable_preload+0x6a28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27176ULL;
	}
x86_l_4cad:
	/* 0x4cad: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4cb2:
	/* 0x4cb2: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_4cbb:
	/* 0x4cbb: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4cc0:
	/* 0x4cc0: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4cc6:
	/* 0x4cc6: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_4ccd:
	/* 0x4ccd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4cd2:
	/* 0x4cd2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cd7:
	/* 0x4cd7: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_4ce0:
	/* 0x4ce0: je     4d05 <generic_sleepable_preload+0x4d05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d05;
	}
x86_l_4ce2:
	/* 0x4ce2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ce7:
	/* 0x4ce7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4cec:
	/* 0x4cec: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4cf1:
	/* 0x4cf1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cf6:
	/* 0x4cf6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cfb:
	/* 0x4cfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cfd:
	/* 0x4cfd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4cff:
	/* 0x4cff: js     697a <generic_sleepable_preload+0x697a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27002ULL;
	}
x86_l_4d05:
	/* 0x4d05: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4d0a:
	/* 0x4d0a: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_4d13:
	/* 0x4d13: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4d18:
	/* 0x4d18: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4d1e:
	/* 0x4d1e: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_4d25:
	/* 0x4d25: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4d2a:
	/* 0x4d2a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d2f:
	/* 0x4d2f: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_4d38:
	/* 0x4d38: je     65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26081ULL;
	}
x86_l_4d3e:
	/* 0x4d3e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d43:
	/* 0x4d43: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d48:
	/* 0x4d48: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4d4d:
	/* 0x4d4d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d52:
	/* 0x4d52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d57:
	/* 0x4d57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d59:
	/* 0x4d59: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d5b:
	/* 0x4d5b: jns    65e1 <generic_sleepable_preload+0x65e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26081ULL;
	}
x86_l_4d61:
	/* 0x4d61: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_4d66:
	/* 0x4d66: jmp    65df <generic_sleepable_preload+0x65df> */
	return 26079ULL;
x86_l_4d6b:
	/* 0x4d6b: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4d70:
	/* 0x4d70: jmp    65df <generic_sleepable_preload+0x65df> */
	return 26079ULL;
x86_l_4d75:
	/* 0x4d75: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4d7d:
	/* 0x4d7d: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4d80:
	/* 0x4d80: je     4d8c <generic_sleepable_preload+0x4d8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d8c;
	}
x86_l_4d82:
	/* 0x4d82: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4d87:
	/* 0x4d87: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4d8a:
	/* 0x4d8a: jne    4d9f <generic_sleepable_preload+0x4d9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4d9f;
	}
x86_l_4d8c:
	/* 0x4d8c: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_4d8f:
	/* 0x4d8f: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_4d91:
	/* 0x4d91: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_4d93:
	/* 0x4d93: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_4d98:
	/* 0x4d98: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4d9a:
	/* 0x4d9a: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_4d9f:
	/* 0x4d9f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4da4:
	/* 0x4da4: mov    r14d,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4da8:
	/* 0x4da8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4daa:
	/* 0x4daa: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_4dad:
	/* 0x4dad: cmp    WORD PTR [r13+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_4db6:
	/* 0x4db6: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_4dbc:
	/* 0x4dbc: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4dc3:
	/* 0x4dc3: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4dc6:
	/* 0x4dc6: mov    eax,DWORD PTR [r13+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_4dcd:
	/* 0x4dcd: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4dd0:
	/* 0x4dd0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dd5:
	/* 0x4dd5: movzx  eax,WORD PTR [r13+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_4ddd:
	/* 0x4ddd: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4ddf:
	/* 0x4ddf: je     50c5 <generic_sleepable_preload+0x50c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50c5;
	}
x86_l_4de5:
	/* 0x4de5: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4de8:
	/* 0x4de8: je     4e0d <generic_sleepable_preload+0x4e0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e0d;
	}
x86_l_4dea:
	/* 0x4dea: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4def:
	/* 0x4def: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4df4:
	/* 0x4df4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4df9:
	/* 0x4df9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dfe:
	/* 0x4dfe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e03:
	/* 0x4e03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e05:
	/* 0x4e05: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e07:
	/* 0x4e07: js     53c3 <generic_sleepable_preload+0x53c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21443ULL;
	}
x86_l_4e0d:
	/* 0x4e0d: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4e16:
	/* 0x4e16: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_4e1c:
	/* 0x4e1c: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4e23:
	/* 0x4e23: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4e28:
	/* 0x4e28: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e2d:
	/* 0x4e2d: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4e36:
	/* 0x4e36: je     4e5b <generic_sleepable_preload+0x4e5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e5b;
	}
x86_l_4e38:
	/* 0x4e38: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e3d:
	/* 0x4e3d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e42:
	/* 0x4e42: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e47:
	/* 0x4e47: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e4c:
	/* 0x4e4c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e51:
	/* 0x4e51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e53:
	/* 0x4e53: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e55:
	/* 0x4e55: js     5437 <generic_sleepable_preload+0x5437> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21559ULL;
	}
x86_l_4e5b:
	/* 0x4e5b: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4e64:
	/* 0x4e64: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_4e6a:
	/* 0x4e6a: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_4e71:
	/* 0x4e71: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4e76:
	/* 0x4e76: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e7b:
	/* 0x4e7b: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_4e84:
	/* 0x4e84: je     4ea9 <generic_sleepable_preload+0x4ea9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ea9;
	}
x86_l_4e86:
	/* 0x4e86: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e8b:
	/* 0x4e8b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e90:
	/* 0x4e90: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e95:
	/* 0x4e95: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e9a:
	/* 0x4e9a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e9f:
	/* 0x4e9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ea1:
	/* 0x4ea1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ea3:
	/* 0x4ea3: js     611e <generic_sleepable_preload+0x611e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24862ULL;
	}
x86_l_4ea9:
	/* 0x4ea9: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4eb2:
	/* 0x4eb2: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_4eb8:
	/* 0x4eb8: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_4ebf:
	/* 0x4ebf: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ec4:
	/* 0x4ec4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ec9:
	/* 0x4ec9: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4ed2:
	/* 0x4ed2: je     4ef7 <generic_sleepable_preload+0x4ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ef7;
	}
x86_l_4ed4:
	/* 0x4ed4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ed9:
	/* 0x4ed9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ede:
	/* 0x4ede: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ee3:
	/* 0x4ee3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ee8:
	/* 0x4ee8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4eed:
	/* 0x4eed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4eef:
	/* 0x4eef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ef1:
	/* 0x4ef1: js     6182 <generic_sleepable_preload+0x6182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24962ULL;
	}
x86_l_4ef7:
	/* 0x4ef7: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4f00:
	/* 0x4f00: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_4f06:
	/* 0x4f06: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4f0d:
	/* 0x4f0d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4f12:
	/* 0x4f12: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f17:
	/* 0x4f17: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4f20:
	/* 0x4f20: je     4f45 <generic_sleepable_preload+0x4f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f45;
	}
x86_l_4f22:
	/* 0x4f22: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f27:
	/* 0x4f27: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f2c:
	/* 0x4f2c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f31:
	/* 0x4f31: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f36:
	/* 0x4f36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f3b:
	/* 0x4f3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f3d:
	/* 0x4f3d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f3f:
	/* 0x4f3f: js     61e6 <generic_sleepable_preload+0x61e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25062ULL;
	}
x86_l_4f45:
	/* 0x4f45: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_4f4e:
	/* 0x4f4e: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_4f54:
	/* 0x4f54: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_4f5b:
	/* 0x4f5b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4f60:
	/* 0x4f60: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f65:
	/* 0x4f65: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4f6e:
	/* 0x4f6e: je     4f93 <generic_sleepable_preload+0x4f93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f93;
	}
x86_l_4f70:
	/* 0x4f70: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f75:
	/* 0x4f75: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f7a:
	/* 0x4f7a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f7f:
	/* 0x4f7f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f84:
	/* 0x4f84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f89:
	/* 0x4f89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f8b:
	/* 0x4f8b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f8d:
	/* 0x4f8d: js     6247 <generic_sleepable_preload+0x6247> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25159ULL;
	}
x86_l_4f93:
	/* 0x4f93: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4f9c:
	/* 0x4f9c: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_4fa2:
	/* 0x4fa2: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4fa9:
	/* 0x4fa9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4fae:
	/* 0x4fae: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fb3:
	/* 0x4fb3: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4fbc:
	/* 0x4fbc: je     4fe1 <generic_sleepable_preload+0x4fe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fe1;
	}
x86_l_4fbe:
	/* 0x4fbe: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fc3:
	/* 0x4fc3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4fc8:
	/* 0x4fc8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4fcd:
	/* 0x4fcd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fd2:
	/* 0x4fd2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fd7:
	/* 0x4fd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fd9:
	/* 0x4fd9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fdb:
	/* 0x4fdb: js     668f <generic_sleepable_preload+0x668f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26255ULL;
	}
x86_l_4fe1:
	/* 0x4fe1: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4fea:
	/* 0x4fea: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_4ff0:
	/* 0x4ff0: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4ff7:
	/* 0x4ff7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ffc:
	/* 0x4ffc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5001:
	/* 0x5001: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_500a:
	/* 0x500a: je     502f <generic_sleepable_preload+0x502f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_502f;
	}
x86_l_500c:
	/* 0x500c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5011:
	/* 0x5011: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5016:
	/* 0x5016: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_501b:
	/* 0x501b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5020:
	/* 0x5020: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5025:
	/* 0x5025: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5027:
	/* 0x5027: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5029:
	/* 0x5029: js     690a <generic_sleepable_preload+0x690a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26890ULL;
	}
x86_l_502f:
	/* 0x502f: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_5038:
	/* 0x5038: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_503e:
	/* 0x503e: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_5045:
	/* 0x5045: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_504a:
	/* 0x504a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_504f:
	/* 0x504f: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_5058:
	/* 0x5058: je     507d <generic_sleepable_preload+0x507d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_507d;
	}
x86_l_505a:
	/* 0x505a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_505f:
	/* 0x505f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5064:
	/* 0x5064: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5069:
	/* 0x5069: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_506e:
	/* 0x506e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5073:
	/* 0x5073: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5075:
	/* 0x5075: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5077:
	/* 0x5077: js     6986 <generic_sleepable_preload+0x6986> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27014ULL;
	}
x86_l_507d:
	/* 0x507d: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5082:
	/* 0x5082: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_508b:
	/* 0x508b: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_5091:
	/* 0x5091: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_5098:
	/* 0x5098: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_509d:
	/* 0x509d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50a2:
	/* 0x50a2: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_50ab:
	/* 0x50ab: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_50b1:
	/* 0x50b1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50b6:
	/* 0x50b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50bb:
	/* 0x50bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50c0:
	/* 0x50c0: jmp    53a5 <generic_sleepable_preload+0x53a5> */
	return 21413ULL;
x86_l_50c5:
	/* 0x50c5: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_50c8:
	/* 0x50c8: je     50ed <generic_sleepable_preload+0x50ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50ed;
	}
x86_l_50ca:
	/* 0x50ca: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50cf:
	/* 0x50cf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50d4:
	/* 0x50d4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50d9:
	/* 0x50d9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50de:
	/* 0x50de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50e3:
	/* 0x50e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50e5:
	/* 0x50e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50e7:
	/* 0x50e7: js     53c3 <generic_sleepable_preload+0x53c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21443ULL;
	}
x86_l_50ed:
	/* 0x50ed: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_50f6:
	/* 0x50f6: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_50fc:
	/* 0x50fc: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_5103:
	/* 0x5103: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5108:
	/* 0x5108: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_510d:
	/* 0x510d: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_5116:
	/* 0x5116: je     513b <generic_sleepable_preload+0x513b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_513b;
	}
x86_l_5118:
	/* 0x5118: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_511d:
	/* 0x511d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5122:
	/* 0x5122: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5127:
	/* 0x5127: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_512c:
	/* 0x512c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5131:
	/* 0x5131: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5133:
	/* 0x5133: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5135:
	/* 0x5135: js     5437 <generic_sleepable_preload+0x5437> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21559ULL;
	}
x86_l_513b:
	/* 0x513b: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_5144:
	/* 0x5144: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_514a:
	/* 0x514a: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_5151:
	/* 0x5151: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5156:
	/* 0x5156: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_515b:
	/* 0x515b: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_5164:
	/* 0x5164: je     5189 <generic_sleepable_preload+0x5189> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5189;
	}
x86_l_5166:
	/* 0x5166: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_516b:
	/* 0x516b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5170:
	/* 0x5170: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5175:
	/* 0x5175: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_517a:
	/* 0x517a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_517f:
	/* 0x517f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5181:
	/* 0x5181: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5183:
	/* 0x5183: js     611e <generic_sleepable_preload+0x611e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24862ULL;
	}
x86_l_5189:
	/* 0x5189: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_5192:
	/* 0x5192: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_5198:
	/* 0x5198: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_519f:
	/* 0x519f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_51a4:
	/* 0x51a4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51a9:
	/* 0x51a9: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_51b2:
	/* 0x51b2: je     51d7 <generic_sleepable_preload+0x51d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20951ULL;
	}
x86_l_51b4:
	/* 0x51b4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51b9:
	/* 0x51b9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
	return 20926ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20926ULL: goto x86_l_51be;
	case 20931ULL: goto x86_l_51c3;
	case 20936ULL: goto x86_l_51c8;
	case 20941ULL: goto x86_l_51cd;
	case 20943ULL: goto x86_l_51cf;
	case 20945ULL: goto x86_l_51d1;
	case 20951ULL: goto x86_l_51d7;
	case 20960ULL: goto x86_l_51e0;
	case 20966ULL: goto x86_l_51e6;
	case 20973ULL: goto x86_l_51ed;
	case 20978ULL: goto x86_l_51f2;
	case 20983ULL: goto x86_l_51f7;
	case 20992ULL: goto x86_l_5200;
	case 20994ULL: goto x86_l_5202;
	case 20999ULL: goto x86_l_5207;
	case 21004ULL: goto x86_l_520c;
	case 21009ULL: goto x86_l_5211;
	case 21014ULL: goto x86_l_5216;
	case 21019ULL: goto x86_l_521b;
	case 21021ULL: goto x86_l_521d;
	case 21023ULL: goto x86_l_521f;
	case 21029ULL: goto x86_l_5225;
	case 21038ULL: goto x86_l_522e;
	case 21044ULL: goto x86_l_5234;
	case 21051ULL: goto x86_l_523b;
	case 21056ULL: goto x86_l_5240;
	case 21061ULL: goto x86_l_5245;
	case 21070ULL: goto x86_l_524e;
	case 21072ULL: goto x86_l_5250;
	case 21077ULL: goto x86_l_5255;
	case 21082ULL: goto x86_l_525a;
	case 21087ULL: goto x86_l_525f;
	case 21092ULL: goto x86_l_5264;
	case 21097ULL: goto x86_l_5269;
	case 21099ULL: goto x86_l_526b;
	case 21101ULL: goto x86_l_526d;
	case 21107ULL: goto x86_l_5273;
	case 21116ULL: goto x86_l_527c;
	case 21122ULL: goto x86_l_5282;
	case 21129ULL: goto x86_l_5289;
	case 21134ULL: goto x86_l_528e;
	case 21139ULL: goto x86_l_5293;
	case 21148ULL: goto x86_l_529c;
	case 21150ULL: goto x86_l_529e;
	case 21155ULL: goto x86_l_52a3;
	case 21160ULL: goto x86_l_52a8;
	case 21165ULL: goto x86_l_52ad;
	case 21170ULL: goto x86_l_52b2;
	case 21175ULL: goto x86_l_52b7;
	case 21177ULL: goto x86_l_52b9;
	case 21179ULL: goto x86_l_52bb;
	case 21185ULL: goto x86_l_52c1;
	case 21194ULL: goto x86_l_52ca;
	case 21200ULL: goto x86_l_52d0;
	case 21207ULL: goto x86_l_52d7;
	case 21212ULL: goto x86_l_52dc;
	case 21217ULL: goto x86_l_52e1;
	case 21226ULL: goto x86_l_52ea;
	case 21228ULL: goto x86_l_52ec;
	case 21233ULL: goto x86_l_52f1;
	case 21238ULL: goto x86_l_52f6;
	case 21243ULL: goto x86_l_52fb;
	case 21248ULL: goto x86_l_5300;
	case 21253ULL: goto x86_l_5305;
	case 21255ULL: goto x86_l_5307;
	case 21257ULL: goto x86_l_5309;
	case 21263ULL: goto x86_l_530f;
	case 21268ULL: goto x86_l_5314;
	case 21277ULL: goto x86_l_531d;
	case 21283ULL: goto x86_l_5323;
	case 21290ULL: goto x86_l_532a;
	case 21295ULL: goto x86_l_532f;
	case 21300ULL: goto x86_l_5334;
	case 21309ULL: goto x86_l_533d;
	case 21311ULL: goto x86_l_533f;
	case 21316ULL: goto x86_l_5344;
	case 21321ULL: goto x86_l_5349;
	case 21326ULL: goto x86_l_534e;
	case 21331ULL: goto x86_l_5353;
	case 21336ULL: goto x86_l_5358;
	case 21338ULL: goto x86_l_535a;
	case 21340ULL: goto x86_l_535c;
	case 21346ULL: goto x86_l_5362;
	case 21351ULL: goto x86_l_5367;
	case 21360ULL: goto x86_l_5370;
	case 21366ULL: goto x86_l_5376;
	case 21373ULL: goto x86_l_537d;
	case 21378ULL: goto x86_l_5382;
	case 21383ULL: goto x86_l_5387;
	case 21392ULL: goto x86_l_5390;
	case 21398ULL: goto x86_l_5396;
	case 21403ULL: goto x86_l_539b;
	case 21408ULL: goto x86_l_53a0;
	case 21413ULL: goto x86_l_53a5;
	case 21418ULL: goto x86_l_53aa;
	case 21423ULL: goto x86_l_53af;
	case 21425ULL: goto x86_l_53b1;
	case 21427ULL: goto x86_l_53b3;
	case 21433ULL: goto x86_l_53b9;
	case 21438ULL: goto x86_l_53be;
	case 21443ULL: goto x86_l_53c3;
	case 21448ULL: goto x86_l_53c8;
	case 21453ULL: goto x86_l_53cd;
	case 21461ULL: goto x86_l_53d5;
	case 21464ULL: goto x86_l_53d8;
	case 21470ULL: goto x86_l_53de;
	case 21475ULL: goto x86_l_53e3;
	case 21478ULL: goto x86_l_53e6;
	case 21484ULL: goto x86_l_53ec;
	case 21489ULL: goto x86_l_53f1;
	case 21494ULL: goto x86_l_53f6;
	case 21499ULL: goto x86_l_53fb;
	case 21504ULL: goto x86_l_5400;
	case 21509ULL: goto x86_l_5405;
	case 21514ULL: goto x86_l_540a;
	case 21519ULL: goto x86_l_540f;
	case 21524ULL: goto x86_l_5414;
	case 21529ULL: goto x86_l_5419;
	case 21534ULL: goto x86_l_541e;
	case 21539ULL: goto x86_l_5423;
	case 21544ULL: goto x86_l_5428;
	case 21549ULL: goto x86_l_542d;
	case 21554ULL: goto x86_l_5432;
	case 21559ULL: goto x86_l_5437;
	case 21564ULL: goto x86_l_543c;
	case 21569ULL: goto x86_l_5441;
	case 21572ULL: goto x86_l_5444;
	case 21575ULL: goto x86_l_5447;
	case 21577ULL: goto x86_l_5449;
	case 21579ULL: goto x86_l_544b;
	case 21584ULL: goto x86_l_5450;
	case 21586ULL: goto x86_l_5452;
	case 21591ULL: goto x86_l_5457;
	case 21596ULL: goto x86_l_545c;
	case 21600ULL: goto x86_l_5460;
	case 21602ULL: goto x86_l_5462;
	case 21605ULL: goto x86_l_5465;
	case 21614ULL: goto x86_l_546e;
	case 21620ULL: goto x86_l_5474;
	case 21627ULL: goto x86_l_547b;
	case 21630ULL: goto x86_l_547e;
	case 21637ULL: goto x86_l_5485;
	case 21640ULL: goto x86_l_5488;
	case 21645ULL: goto x86_l_548d;
	case 21653ULL: goto x86_l_5495;
	case 21655ULL: goto x86_l_5497;
	case 21661ULL: goto x86_l_549d;
	case 21664ULL: goto x86_l_54a0;
	case 21666ULL: goto x86_l_54a2;
	case 21671ULL: goto x86_l_54a7;
	case 21676ULL: goto x86_l_54ac;
	case 21681ULL: goto x86_l_54b1;
	case 21686ULL: goto x86_l_54b6;
	case 21691ULL: goto x86_l_54bb;
	case 21693ULL: goto x86_l_54bd;
	case 21695ULL: goto x86_l_54bf;
	case 21701ULL: goto x86_l_54c5;
	case 21710ULL: goto x86_l_54ce;
	case 21716ULL: goto x86_l_54d4;
	case 21723ULL: goto x86_l_54db;
	case 21728ULL: goto x86_l_54e0;
	case 21733ULL: goto x86_l_54e5;
	case 21742ULL: goto x86_l_54ee;
	case 21744ULL: goto x86_l_54f0;
	case 21749ULL: goto x86_l_54f5;
	case 21754ULL: goto x86_l_54fa;
	case 21759ULL: goto x86_l_54ff;
	case 21764ULL: goto x86_l_5504;
	case 21769ULL: goto x86_l_5509;
	case 21771ULL: goto x86_l_550b;
	case 21773ULL: goto x86_l_550d;
	case 21779ULL: goto x86_l_5513;
	case 21788ULL: goto x86_l_551c;
	case 21794ULL: goto x86_l_5522;
	case 21801ULL: goto x86_l_5529;
	case 21806ULL: goto x86_l_552e;
	case 21811ULL: goto x86_l_5533;
	case 21820ULL: goto x86_l_553c;
	case 21822ULL: goto x86_l_553e;
	case 21827ULL: goto x86_l_5543;
	case 21832ULL: goto x86_l_5548;
	case 21837ULL: goto x86_l_554d;
	case 21842ULL: goto x86_l_5552;
	case 21847ULL: goto x86_l_5557;
	case 21849ULL: goto x86_l_5559;
	case 21851ULL: goto x86_l_555b;
	case 21857ULL: goto x86_l_5561;
	case 21866ULL: goto x86_l_556a;
	case 21872ULL: goto x86_l_5570;
	case 21879ULL: goto x86_l_5577;
	case 21884ULL: goto x86_l_557c;
	case 21889ULL: goto x86_l_5581;
	case 21898ULL: goto x86_l_558a;
	case 21900ULL: goto x86_l_558c;
	case 21905ULL: goto x86_l_5591;
	case 21910ULL: goto x86_l_5596;
	case 21915ULL: goto x86_l_559b;
	case 21920ULL: goto x86_l_55a0;
	case 21925ULL: goto x86_l_55a5;
	case 21927ULL: goto x86_l_55a7;
	case 21929ULL: goto x86_l_55a9;
	case 21935ULL: goto x86_l_55af;
	case 21944ULL: goto x86_l_55b8;
	case 21950ULL: goto x86_l_55be;
	case 21957ULL: goto x86_l_55c5;
	case 21962ULL: goto x86_l_55ca;
	case 21967ULL: goto x86_l_55cf;
	case 21976ULL: goto x86_l_55d8;
	case 21978ULL: goto x86_l_55da;
	case 21983ULL: goto x86_l_55df;
	case 21988ULL: goto x86_l_55e4;
	case 21993ULL: goto x86_l_55e9;
	case 21998ULL: goto x86_l_55ee;
	case 22003ULL: goto x86_l_55f3;
	case 22005ULL: goto x86_l_55f5;
	case 22007ULL: goto x86_l_55f7;
	case 22013ULL: goto x86_l_55fd;
	case 22022ULL: goto x86_l_5606;
	case 22028ULL: goto x86_l_560c;
	case 22035ULL: goto x86_l_5613;
	case 22040ULL: goto x86_l_5618;
	case 22045ULL: goto x86_l_561d;
	case 22054ULL: goto x86_l_5626;
	case 22056ULL: goto x86_l_5628;
	case 22061ULL: goto x86_l_562d;
	case 22066ULL: goto x86_l_5632;
	case 22071ULL: goto x86_l_5637;
	case 22076ULL: goto x86_l_563c;
	case 22081ULL: goto x86_l_5641;
	case 22083ULL: goto x86_l_5643;
	case 22085ULL: goto x86_l_5645;
	case 22091ULL: goto x86_l_564b;
	case 22100ULL: goto x86_l_5654;
	case 22106ULL: goto x86_l_565a;
	case 22113ULL: goto x86_l_5661;
	case 22118ULL: goto x86_l_5666;
	case 22123ULL: goto x86_l_566b;
	case 22132ULL: goto x86_l_5674;
	case 22134ULL: goto x86_l_5676;
	case 22139ULL: goto x86_l_567b;
	case 22144ULL: goto x86_l_5680;
	case 22149ULL: goto x86_l_5685;
	case 22154ULL: goto x86_l_568a;
	case 22159ULL: goto x86_l_568f;
	case 22161ULL: goto x86_l_5691;
	case 22163ULL: goto x86_l_5693;
	case 22169ULL: goto x86_l_5699;
	case 22178ULL: goto x86_l_56a2;
	case 22184ULL: goto x86_l_56a8;
	case 22191ULL: goto x86_l_56af;
	case 22196ULL: goto x86_l_56b4;
	case 22201ULL: goto x86_l_56b9;
	case 22210ULL: goto x86_l_56c2;
	case 22212ULL: goto x86_l_56c4;
	case 22217ULL: goto x86_l_56c9;
	case 22222ULL: goto x86_l_56ce;
	case 22227ULL: goto x86_l_56d3;
	case 22232ULL: goto x86_l_56d8;
	case 22237ULL: goto x86_l_56dd;
	case 22239ULL: goto x86_l_56df;
	case 22241ULL: goto x86_l_56e1;
	case 22247ULL: goto x86_l_56e7;
	case 22256ULL: goto x86_l_56f0;
	case 22262ULL: goto x86_l_56f6;
	case 22269ULL: goto x86_l_56fd;
	case 22274ULL: goto x86_l_5702;
	case 22279ULL: goto x86_l_5707;
	case 22288ULL: goto x86_l_5710;
	case 22290ULL: goto x86_l_5712;
	case 22295ULL: goto x86_l_5717;
	case 22300ULL: goto x86_l_571c;
	case 22305ULL: goto x86_l_5721;
	case 22310ULL: goto x86_l_5726;
	case 22315ULL: goto x86_l_572b;
	case 22317ULL: goto x86_l_572d;
	case 22319ULL: goto x86_l_572f;
	case 22325ULL: goto x86_l_5735;
	case 22330ULL: goto x86_l_573a;
	case 22339ULL: goto x86_l_5743;
	case 22345ULL: goto x86_l_5749;
	case 22352ULL: goto x86_l_5750;
	case 22357ULL: goto x86_l_5755;
	case 22362ULL: goto x86_l_575a;
	case 22371ULL: goto x86_l_5763;
	case 22377ULL: goto x86_l_5769;
	case 22382ULL: goto x86_l_576e;
	case 22387ULL: goto x86_l_5773;
	case 22392ULL: goto x86_l_5778;
	case 22397ULL: goto x86_l_577d;
	case 22400ULL: goto x86_l_5780;
	case 22402ULL: goto x86_l_5782;
	case 22407ULL: goto x86_l_5787;
	case 22412ULL: goto x86_l_578c;
	case 22417ULL: goto x86_l_5791;
	case 22422ULL: goto x86_l_5796;
	case 22427ULL: goto x86_l_579b;
	case 22429ULL: goto x86_l_579d;
	case 22431ULL: goto x86_l_579f;
	case 22437ULL: goto x86_l_57a5;
	case 22446ULL: goto x86_l_57ae;
	case 22452ULL: goto x86_l_57b4;
	case 22459ULL: goto x86_l_57bb;
	case 22464ULL: goto x86_l_57c0;
	case 22469ULL: goto x86_l_57c5;
	case 22478ULL: goto x86_l_57ce;
	case 22480ULL: goto x86_l_57d0;
	case 22485ULL: goto x86_l_57d5;
	case 22490ULL: goto x86_l_57da;
	case 22495ULL: goto x86_l_57df;
	case 22500ULL: goto x86_l_57e4;
	case 22505ULL: goto x86_l_57e9;
	case 22507ULL: goto x86_l_57eb;
	case 22509ULL: goto x86_l_57ed;
	case 22515ULL: goto x86_l_57f3;
	case 22524ULL: goto x86_l_57fc;
	case 22530ULL: goto x86_l_5802;
	case 22537ULL: goto x86_l_5809;
	case 22542ULL: goto x86_l_580e;
	case 22547ULL: goto x86_l_5813;
	case 22556ULL: goto x86_l_581c;
	case 22558ULL: goto x86_l_581e;
	case 22563ULL: goto x86_l_5823;
	case 22568ULL: goto x86_l_5828;
	case 22573ULL: goto x86_l_582d;
	case 22578ULL: goto x86_l_5832;
	case 22583ULL: goto x86_l_5837;
	case 22585ULL: goto x86_l_5839;
	case 22587ULL: goto x86_l_583b;
	case 22593ULL: goto x86_l_5841;
	case 22602ULL: goto x86_l_584a;
	case 22608ULL: goto x86_l_5850;
	case 22615ULL: goto x86_l_5857;
	case 22620ULL: goto x86_l_585c;
	case 22625ULL: goto x86_l_5861;
	case 22634ULL: goto x86_l_586a;
	case 22636ULL: goto x86_l_586c;
	case 22641ULL: goto x86_l_5871;
	case 22646ULL: goto x86_l_5876;
	case 22651ULL: goto x86_l_587b;
	case 22656ULL: goto x86_l_5880;
	case 22661ULL: goto x86_l_5885;
	case 22663ULL: goto x86_l_5887;
	case 22665ULL: goto x86_l_5889;
	case 22671ULL: goto x86_l_588f;
	case 22680ULL: goto x86_l_5898;
	case 22686ULL: goto x86_l_589e;
	case 22693ULL: goto x86_l_58a5;
	case 22698ULL: goto x86_l_58aa;
	case 22703ULL: goto x86_l_58af;
	case 22712ULL: goto x86_l_58b8;
	case 22714ULL: goto x86_l_58ba;
	case 22719ULL: goto x86_l_58bf;
	case 22724ULL: goto x86_l_58c4;
	case 22729ULL: goto x86_l_58c9;
	case 22734ULL: goto x86_l_58ce;
	case 22739ULL: goto x86_l_58d3;
	case 22741ULL: goto x86_l_58d5;
	case 22743ULL: goto x86_l_58d7;
	case 22749ULL: goto x86_l_58dd;
	case 22758ULL: goto x86_l_58e6;
	case 22764ULL: goto x86_l_58ec;
	case 22771ULL: goto x86_l_58f3;
	case 22776ULL: goto x86_l_58f8;
	case 22781ULL: goto x86_l_58fd;
	case 22790ULL: goto x86_l_5906;
	case 22792ULL: goto x86_l_5908;
	case 22797ULL: goto x86_l_590d;
	case 22802ULL: goto x86_l_5912;
	case 22807ULL: goto x86_l_5917;
	case 22812ULL: goto x86_l_591c;
	case 22817ULL: goto x86_l_5921;
	case 22819ULL: goto x86_l_5923;
	case 22821ULL: goto x86_l_5925;
	case 22827ULL: goto x86_l_592b;
	case 22836ULL: goto x86_l_5934;
	case 22842ULL: goto x86_l_593a;
	case 22849ULL: goto x86_l_5941;
	case 22854ULL: goto x86_l_5946;
	case 22859ULL: goto x86_l_594b;
	case 22868ULL: goto x86_l_5954;
	case 22870ULL: goto x86_l_5956;
	case 22875ULL: goto x86_l_595b;
	case 22880ULL: goto x86_l_5960;
	case 22885ULL: goto x86_l_5965;
	default: return 0xffffffffffffffffULL;
	}
x86_l_51be:
	/* 0x51be: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51c3:
	/* 0x51c3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51c8:
	/* 0x51c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51cd:
	/* 0x51cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51cf:
	/* 0x51cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51d1:
	/* 0x51d1: js     6182 <generic_sleepable_preload+0x6182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24962ULL;
	}
x86_l_51d7:
	/* 0x51d7: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_51e0:
	/* 0x51e0: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_51e6:
	/* 0x51e6: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_51ed:
	/* 0x51ed: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_51f2:
	/* 0x51f2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51f7:
	/* 0x51f7: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_5200:
	/* 0x5200: je     5225 <generic_sleepable_preload+0x5225> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5225;
	}
x86_l_5202:
	/* 0x5202: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5207:
	/* 0x5207: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_520c:
	/* 0x520c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5211:
	/* 0x5211: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5216:
	/* 0x5216: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_521b:
	/* 0x521b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_521d:
	/* 0x521d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_521f:
	/* 0x521f: js     61e6 <generic_sleepable_preload+0x61e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25062ULL;
	}
x86_l_5225:
	/* 0x5225: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_522e:
	/* 0x522e: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_5234:
	/* 0x5234: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_523b:
	/* 0x523b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5240:
	/* 0x5240: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5245:
	/* 0x5245: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_524e:
	/* 0x524e: je     5273 <generic_sleepable_preload+0x5273> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5273;
	}
x86_l_5250:
	/* 0x5250: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5255:
	/* 0x5255: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_525a:
	/* 0x525a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_525f:
	/* 0x525f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5264:
	/* 0x5264: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5269:
	/* 0x5269: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_526b:
	/* 0x526b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_526d:
	/* 0x526d: js     6247 <generic_sleepable_preload+0x6247> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25159ULL;
	}
x86_l_5273:
	/* 0x5273: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_527c:
	/* 0x527c: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_5282:
	/* 0x5282: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_5289:
	/* 0x5289: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_528e:
	/* 0x528e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5293:
	/* 0x5293: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_529c:
	/* 0x529c: je     52c1 <generic_sleepable_preload+0x52c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52c1;
	}
x86_l_529e:
	/* 0x529e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52a3:
	/* 0x52a3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_52a8:
	/* 0x52a8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_52ad:
	/* 0x52ad: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52b2:
	/* 0x52b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52b7:
	/* 0x52b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52b9:
	/* 0x52b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52bb:
	/* 0x52bb: js     668f <generic_sleepable_preload+0x668f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26255ULL;
	}
x86_l_52c1:
	/* 0x52c1: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_52ca:
	/* 0x52ca: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_52d0:
	/* 0x52d0: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_52d7:
	/* 0x52d7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_52dc:
	/* 0x52dc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52e1:
	/* 0x52e1: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_52ea:
	/* 0x52ea: je     530f <generic_sleepable_preload+0x530f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_530f;
	}
x86_l_52ec:
	/* 0x52ec: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52f1:
	/* 0x52f1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_52f6:
	/* 0x52f6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_52fb:
	/* 0x52fb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5300:
	/* 0x5300: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5305:
	/* 0x5305: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5307:
	/* 0x5307: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5309:
	/* 0x5309: js     6a3e <generic_sleepable_preload+0x6a3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27198ULL;
	}
x86_l_530f:
	/* 0x530f: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5314:
	/* 0x5314: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_531d:
	/* 0x531d: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_5323:
	/* 0x5323: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_532a:
	/* 0x532a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_532f:
	/* 0x532f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5334:
	/* 0x5334: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_533d:
	/* 0x533d: je     5362 <generic_sleepable_preload+0x5362> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5362;
	}
x86_l_533f:
	/* 0x533f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5344:
	/* 0x5344: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5349:
	/* 0x5349: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_534e:
	/* 0x534e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5353:
	/* 0x5353: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5358:
	/* 0x5358: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_535a:
	/* 0x535a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_535c:
	/* 0x535c: js     6986 <generic_sleepable_preload+0x6986> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27014ULL;
	}
x86_l_5362:
	/* 0x5362: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5367:
	/* 0x5367: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_5370:
	/* 0x5370: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_5376:
	/* 0x5376: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_537d:
	/* 0x537d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5382:
	/* 0x5382: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5387:
	/* 0x5387: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_5390:
	/* 0x5390: je     6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26262ULL;
	}
x86_l_5396:
	/* 0x5396: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_539b:
	/* 0x539b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_53a0:
	/* 0x53a0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_53a5:
	/* 0x53a5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53aa:
	/* 0x53aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53af:
	/* 0x53af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53b1:
	/* 0x53b1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_53b3:
	/* 0x53b3: jns    6696 <generic_sleepable_preload+0x6696> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26262ULL;
	}
x86_l_53b9:
	/* 0x53b9: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_53be:
	/* 0x53be: jmp    6694 <generic_sleepable_preload+0x6694> */
	return 26260ULL;
x86_l_53c3:
	/* 0x53c3: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_53c8:
	/* 0x53c8: jmp    6694 <generic_sleepable_preload+0x6694> */
	return 26260ULL;
x86_l_53cd:
	/* 0x53cd: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_53d5:
	/* 0x53d5: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_53d8:
	/* 0x53d8: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_53de:
	/* 0x53de: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_53e3:
	/* 0x53e3: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_53e6:
	/* 0x53e6: je     5a94 <generic_sleepable_preload+0x5a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23188ULL;
	}
x86_l_53ec:
	/* 0x53ec: jmp    5aa7 <generic_sleepable_preload+0x5aa7> */
	return 23207ULL;
x86_l_53f1:
	/* 0x53f1: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_53f6:
	/* 0x53f6: jmp    626a <generic_sleepable_preload+0x626a> */
	return 25194ULL;
x86_l_53fb:
	/* 0x53fb: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5400:
	/* 0x5400: jmp    62f7 <generic_sleepable_preload+0x62f7> */
	return 25335ULL;
x86_l_5405:
	/* 0x5405: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_540a:
	/* 0x540a: jmp    6384 <generic_sleepable_preload+0x6384> */
	return 25476ULL;
x86_l_540f:
	/* 0x540f: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5414:
	/* 0x5414: jmp    6411 <generic_sleepable_preload+0x6411> */
	return 25617ULL;
x86_l_5419:
	/* 0x5419: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_541e:
	/* 0x541e: jmp    649e <generic_sleepable_preload+0x649e> */
	return 25758ULL;
x86_l_5423:
	/* 0x5423: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5428:
	/* 0x5428: jmp    652b <generic_sleepable_preload+0x652b> */
	return 25899ULL;
x86_l_542d:
	/* 0x542d: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5432:
	/* 0x5432: jmp    65df <generic_sleepable_preload+0x65df> */
	return 26079ULL;
x86_l_5437:
	/* 0x5437: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_543c:
	/* 0x543c: jmp    6694 <generic_sleepable_preload+0x6694> */
	return 26260ULL;
x86_l_5441:
	/* 0x5441: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5444:
	/* 0x5444: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_5447:
	/* 0x5447: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_5449:
	/* 0x5449: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_544b:
	/* 0x544b: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_5450:
	/* 0x5450: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5452:
	/* 0x5452: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_5457:
	/* 0x5457: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_545c:
	/* 0x545c: mov    r14d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5460:
	/* 0x5460: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5462:
	/* 0x5462: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_5465:
	/* 0x5465: cmp    WORD PTR [r13+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_546e:
	/* 0x546e: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_5474:
	/* 0x5474: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_547b:
	/* 0x547b: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_547e:
	/* 0x547e: mov    eax,DWORD PTR [r13+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_5485:
	/* 0x5485: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5488:
	/* 0x5488: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_548d:
	/* 0x548d: movzx  eax,WORD PTR [r13+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_5495:
	/* 0x5495: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_5497:
	/* 0x5497: je     577d <generic_sleepable_preload+0x577d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_577d;
	}
x86_l_549d:
	/* 0x549d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_54a0:
	/* 0x54a0: je     54c5 <generic_sleepable_preload+0x54c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54c5;
	}
x86_l_54a2:
	/* 0x54a2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54a7:
	/* 0x54a7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_54ac:
	/* 0x54ac: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54b1:
	/* 0x54b1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54b6:
	/* 0x54b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54bb:
	/* 0x54bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54bd:
	/* 0x54bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54bf:
	/* 0x54bf: js     5a7b <generic_sleepable_preload+0x5a7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23163ULL;
	}
x86_l_54c5:
	/* 0x54c5: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_54ce:
	/* 0x54ce: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_54d4:
	/* 0x54d4: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_54db:
	/* 0x54db: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_54e0:
	/* 0x54e0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54e5:
	/* 0x54e5: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_54ee:
	/* 0x54ee: je     5513 <generic_sleepable_preload+0x5513> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5513;
	}
x86_l_54f0:
	/* 0x54f0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54f5:
	/* 0x54f5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_54fa:
	/* 0x54fa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54ff:
	/* 0x54ff: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5504:
	/* 0x5504: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5509:
	/* 0x5509: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_550b:
	/* 0x550b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_550d:
	/* 0x550d: js     5a85 <generic_sleepable_preload+0x5a85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23173ULL;
	}
x86_l_5513:
	/* 0x5513: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_551c:
	/* 0x551c: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_5522:
	/* 0x5522: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_5529:
	/* 0x5529: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_552e:
	/* 0x552e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5533:
	/* 0x5533: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_553c:
	/* 0x553c: je     5561 <generic_sleepable_preload+0x5561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5561;
	}
x86_l_553e:
	/* 0x553e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5543:
	/* 0x5543: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5548:
	/* 0x5548: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_554d:
	/* 0x554d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5552:
	/* 0x5552: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5557:
	/* 0x5557: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5559:
	/* 0x5559: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_555b:
	/* 0x555b: js     6128 <generic_sleepable_preload+0x6128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24872ULL;
	}
x86_l_5561:
	/* 0x5561: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_556a:
	/* 0x556a: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_5570:
	/* 0x5570: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_5577:
	/* 0x5577: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_557c:
	/* 0x557c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5581:
	/* 0x5581: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_558a:
	/* 0x558a: je     55af <generic_sleepable_preload+0x55af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55af;
	}
x86_l_558c:
	/* 0x558c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5591:
	/* 0x5591: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5596:
	/* 0x5596: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_559b:
	/* 0x559b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55a0:
	/* 0x55a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55a5:
	/* 0x55a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55a7:
	/* 0x55a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55a9:
	/* 0x55a9: js     618c <generic_sleepable_preload+0x618c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24972ULL;
	}
x86_l_55af:
	/* 0x55af: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_55b8:
	/* 0x55b8: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_55be:
	/* 0x55be: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_55c5:
	/* 0x55c5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_55ca:
	/* 0x55ca: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55cf:
	/* 0x55cf: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_55d8:
	/* 0x55d8: je     55fd <generic_sleepable_preload+0x55fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55fd;
	}
x86_l_55da:
	/* 0x55da: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55df:
	/* 0x55df: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55e4:
	/* 0x55e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55e9:
	/* 0x55e9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55ee:
	/* 0x55ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55f3:
	/* 0x55f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55f5:
	/* 0x55f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55f7:
	/* 0x55f7: js     61f0 <generic_sleepable_preload+0x61f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25072ULL;
	}
x86_l_55fd:
	/* 0x55fd: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_5606:
	/* 0x5606: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_560c:
	/* 0x560c: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_5613:
	/* 0x5613: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5618:
	/* 0x5618: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_561d:
	/* 0x561d: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_5626:
	/* 0x5626: je     564b <generic_sleepable_preload+0x564b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_564b;
	}
x86_l_5628:
	/* 0x5628: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_562d:
	/* 0x562d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5632:
	/* 0x5632: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5637:
	/* 0x5637: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_563c:
	/* 0x563c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5641:
	/* 0x5641: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5643:
	/* 0x5643: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5645:
	/* 0x5645: js     6251 <generic_sleepable_preload+0x6251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25169ULL;
	}
x86_l_564b:
	/* 0x564b: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_5654:
	/* 0x5654: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_565a:
	/* 0x565a: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_5661:
	/* 0x5661: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5666:
	/* 0x5666: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_566b:
	/* 0x566b: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_5674:
	/* 0x5674: je     5699 <generic_sleepable_preload+0x5699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5699;
	}
x86_l_5676:
	/* 0x5676: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_567b:
	/* 0x567b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5680:
	/* 0x5680: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5685:
	/* 0x5685: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_568a:
	/* 0x568a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_568f:
	/* 0x568f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5691:
	/* 0x5691: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5693:
	/* 0x5693: js     673f <generic_sleepable_preload+0x673f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26431ULL;
	}
x86_l_5699:
	/* 0x5699: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_56a2:
	/* 0x56a2: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_56a8:
	/* 0x56a8: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_56af:
	/* 0x56af: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_56b4:
	/* 0x56b4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56b9:
	/* 0x56b9: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_56c2:
	/* 0x56c2: je     56e7 <generic_sleepable_preload+0x56e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56e7;
	}
x86_l_56c4:
	/* 0x56c4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56c9:
	/* 0x56c9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_56ce:
	/* 0x56ce: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_56d3:
	/* 0x56d3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56d8:
	/* 0x56d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56dd:
	/* 0x56dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56df:
	/* 0x56df: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56e1:
	/* 0x56e1: js     6916 <generic_sleepable_preload+0x6916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26902ULL;
	}
x86_l_56e7:
	/* 0x56e7: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_56f0:
	/* 0x56f0: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_56f6:
	/* 0x56f6: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_56fd:
	/* 0x56fd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5702:
	/* 0x5702: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5707:
	/* 0x5707: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_5710:
	/* 0x5710: je     5735 <generic_sleepable_preload+0x5735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5735;
	}
x86_l_5712:
	/* 0x5712: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5717:
	/* 0x5717: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_571c:
	/* 0x571c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5721:
	/* 0x5721: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5726:
	/* 0x5726: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_572b:
	/* 0x572b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_572d:
	/* 0x572d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_572f:
	/* 0x572f: js     6997 <generic_sleepable_preload+0x6997> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27031ULL;
	}
x86_l_5735:
	/* 0x5735: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_573a:
	/* 0x573a: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_5743:
	/* 0x5743: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_5749:
	/* 0x5749: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_5750:
	/* 0x5750: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5755:
	/* 0x5755: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_575a:
	/* 0x575a: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_5763:
	/* 0x5763: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_5769:
	/* 0x5769: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_576e:
	/* 0x576e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5773:
	/* 0x5773: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5778:
	/* 0x5778: jmp    5a5d <generic_sleepable_preload+0x5a5d> */
	return 23133ULL;
x86_l_577d:
	/* 0x577d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5780:
	/* 0x5780: je     57a5 <generic_sleepable_preload+0x57a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57a5;
	}
x86_l_5782:
	/* 0x5782: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5787:
	/* 0x5787: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_578c:
	/* 0x578c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5791:
	/* 0x5791: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5796:
	/* 0x5796: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_579b:
	/* 0x579b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_579d:
	/* 0x579d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_579f:
	/* 0x579f: js     5a7b <generic_sleepable_preload+0x5a7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23163ULL;
	}
x86_l_57a5:
	/* 0x57a5: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_57ae:
	/* 0x57ae: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_57b4:
	/* 0x57b4: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_57bb:
	/* 0x57bb: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_57c0:
	/* 0x57c0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57c5:
	/* 0x57c5: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_57ce:
	/* 0x57ce: je     57f3 <generic_sleepable_preload+0x57f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57f3;
	}
x86_l_57d0:
	/* 0x57d0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57d5:
	/* 0x57d5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_57da:
	/* 0x57da: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_57df:
	/* 0x57df: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57e4:
	/* 0x57e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57e9:
	/* 0x57e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57eb:
	/* 0x57eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57ed:
	/* 0x57ed: js     5a85 <generic_sleepable_preload+0x5a85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23173ULL;
	}
x86_l_57f3:
	/* 0x57f3: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_57fc:
	/* 0x57fc: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_5802:
	/* 0x5802: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_5809:
	/* 0x5809: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_580e:
	/* 0x580e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5813:
	/* 0x5813: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_581c:
	/* 0x581c: je     5841 <generic_sleepable_preload+0x5841> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5841;
	}
x86_l_581e:
	/* 0x581e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5823:
	/* 0x5823: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5828:
	/* 0x5828: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_582d:
	/* 0x582d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5832:
	/* 0x5832: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5837:
	/* 0x5837: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5839:
	/* 0x5839: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_583b:
	/* 0x583b: js     6128 <generic_sleepable_preload+0x6128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24872ULL;
	}
x86_l_5841:
	/* 0x5841: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_584a:
	/* 0x584a: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_5850:
	/* 0x5850: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_5857:
	/* 0x5857: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_585c:
	/* 0x585c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5861:
	/* 0x5861: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_586a:
	/* 0x586a: je     588f <generic_sleepable_preload+0x588f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_588f;
	}
x86_l_586c:
	/* 0x586c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5871:
	/* 0x5871: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5876:
	/* 0x5876: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_587b:
	/* 0x587b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5880:
	/* 0x5880: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5885:
	/* 0x5885: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5887:
	/* 0x5887: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5889:
	/* 0x5889: js     618c <generic_sleepable_preload+0x618c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24972ULL;
	}
x86_l_588f:
	/* 0x588f: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_5898:
	/* 0x5898: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_589e:
	/* 0x589e: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_58a5:
	/* 0x58a5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_58aa:
	/* 0x58aa: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58af:
	/* 0x58af: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_58b8:
	/* 0x58b8: je     58dd <generic_sleepable_preload+0x58dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58dd;
	}
x86_l_58ba:
	/* 0x58ba: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58bf:
	/* 0x58bf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58c4:
	/* 0x58c4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58c9:
	/* 0x58c9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58ce:
	/* 0x58ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58d3:
	/* 0x58d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58d5:
	/* 0x58d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58d7:
	/* 0x58d7: js     61f0 <generic_sleepable_preload+0x61f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25072ULL;
	}
x86_l_58dd:
	/* 0x58dd: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_58e6:
	/* 0x58e6: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_58ec:
	/* 0x58ec: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_58f3:
	/* 0x58f3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_58f8:
	/* 0x58f8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58fd:
	/* 0x58fd: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_5906:
	/* 0x5906: je     592b <generic_sleepable_preload+0x592b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_592b;
	}
x86_l_5908:
	/* 0x5908: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_590d:
	/* 0x590d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5912:
	/* 0x5912: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5917:
	/* 0x5917: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_591c:
	/* 0x591c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5921:
	/* 0x5921: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5923:
	/* 0x5923: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5925:
	/* 0x5925: js     6251 <generic_sleepable_preload+0x6251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25169ULL;
	}
x86_l_592b:
	/* 0x592b: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_5934:
	/* 0x5934: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_593a:
	/* 0x593a: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_5941:
	/* 0x5941: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5946:
	/* 0x5946: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_594b:
	/* 0x594b: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_5954:
	/* 0x5954: je     5979 <generic_sleepable_preload+0x5979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22905ULL;
	}
x86_l_5956:
	/* 0x5956: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_595b:
	/* 0x595b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5960:
	/* 0x5960: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5965:
	/* 0x5965: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 22890ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22890ULL: goto x86_l_596a;
	case 22895ULL: goto x86_l_596f;
	case 22897ULL: goto x86_l_5971;
	case 22899ULL: goto x86_l_5973;
	case 22905ULL: goto x86_l_5979;
	case 22914ULL: goto x86_l_5982;
	case 22920ULL: goto x86_l_5988;
	case 22927ULL: goto x86_l_598f;
	case 22932ULL: goto x86_l_5994;
	case 22937ULL: goto x86_l_5999;
	case 22946ULL: goto x86_l_59a2;
	case 22948ULL: goto x86_l_59a4;
	case 22953ULL: goto x86_l_59a9;
	case 22958ULL: goto x86_l_59ae;
	case 22963ULL: goto x86_l_59b3;
	case 22968ULL: goto x86_l_59b8;
	case 22973ULL: goto x86_l_59bd;
	case 22975ULL: goto x86_l_59bf;
	case 22977ULL: goto x86_l_59c1;
	case 22983ULL: goto x86_l_59c7;
	case 22988ULL: goto x86_l_59cc;
	case 22997ULL: goto x86_l_59d5;
	case 23003ULL: goto x86_l_59db;
	case 23010ULL: goto x86_l_59e2;
	case 23015ULL: goto x86_l_59e7;
	case 23020ULL: goto x86_l_59ec;
	case 23029ULL: goto x86_l_59f5;
	case 23031ULL: goto x86_l_59f7;
	case 23036ULL: goto x86_l_59fc;
	case 23041ULL: goto x86_l_5a01;
	case 23046ULL: goto x86_l_5a06;
	case 23051ULL: goto x86_l_5a0b;
	case 23056ULL: goto x86_l_5a10;
	case 23058ULL: goto x86_l_5a12;
	case 23060ULL: goto x86_l_5a14;
	case 23066ULL: goto x86_l_5a1a;
	case 23071ULL: goto x86_l_5a1f;
	case 23080ULL: goto x86_l_5a28;
	case 23086ULL: goto x86_l_5a2e;
	case 23093ULL: goto x86_l_5a35;
	case 23098ULL: goto x86_l_5a3a;
	case 23103ULL: goto x86_l_5a3f;
	case 23112ULL: goto x86_l_5a48;
	case 23118ULL: goto x86_l_5a4e;
	case 23123ULL: goto x86_l_5a53;
	case 23128ULL: goto x86_l_5a58;
	case 23133ULL: goto x86_l_5a5d;
	case 23138ULL: goto x86_l_5a62;
	case 23143ULL: goto x86_l_5a67;
	case 23145ULL: goto x86_l_5a69;
	case 23147ULL: goto x86_l_5a6b;
	case 23153ULL: goto x86_l_5a71;
	case 23158ULL: goto x86_l_5a76;
	case 23163ULL: goto x86_l_5a7b;
	case 23168ULL: goto x86_l_5a80;
	case 23173ULL: goto x86_l_5a85;
	case 23178ULL: goto x86_l_5a8a;
	case 23183ULL: goto x86_l_5a8f;
	case 23188ULL: goto x86_l_5a94;
	case 23191ULL: goto x86_l_5a97;
	case 23193ULL: goto x86_l_5a99;
	case 23195ULL: goto x86_l_5a9b;
	case 23200ULL: goto x86_l_5aa0;
	case 23202ULL: goto x86_l_5aa2;
	case 23207ULL: goto x86_l_5aa7;
	case 23212ULL: goto x86_l_5aac;
	case 23216ULL: goto x86_l_5ab0;
	case 23218ULL: goto x86_l_5ab2;
	case 23221ULL: goto x86_l_5ab5;
	case 23230ULL: goto x86_l_5abe;
	case 23236ULL: goto x86_l_5ac4;
	case 23243ULL: goto x86_l_5acb;
	case 23246ULL: goto x86_l_5ace;
	case 23253ULL: goto x86_l_5ad5;
	case 23256ULL: goto x86_l_5ad8;
	case 23261ULL: goto x86_l_5add;
	case 23269ULL: goto x86_l_5ae5;
	case 23271ULL: goto x86_l_5ae7;
	case 23277ULL: goto x86_l_5aed;
	case 23280ULL: goto x86_l_5af0;
	case 23282ULL: goto x86_l_5af2;
	case 23287ULL: goto x86_l_5af7;
	case 23292ULL: goto x86_l_5afc;
	case 23297ULL: goto x86_l_5b01;
	case 23302ULL: goto x86_l_5b06;
	case 23307ULL: goto x86_l_5b0b;
	case 23309ULL: goto x86_l_5b0d;
	case 23311ULL: goto x86_l_5b0f;
	case 23317ULL: goto x86_l_5b15;
	case 23326ULL: goto x86_l_5b1e;
	case 23332ULL: goto x86_l_5b24;
	case 23339ULL: goto x86_l_5b2b;
	case 23344ULL: goto x86_l_5b30;
	case 23349ULL: goto x86_l_5b35;
	case 23358ULL: goto x86_l_5b3e;
	case 23360ULL: goto x86_l_5b40;
	case 23365ULL: goto x86_l_5b45;
	case 23370ULL: goto x86_l_5b4a;
	case 23375ULL: goto x86_l_5b4f;
	case 23380ULL: goto x86_l_5b54;
	case 23385ULL: goto x86_l_5b59;
	case 23387ULL: goto x86_l_5b5b;
	case 23389ULL: goto x86_l_5b5d;
	case 23395ULL: goto x86_l_5b63;
	case 23404ULL: goto x86_l_5b6c;
	case 23410ULL: goto x86_l_5b72;
	case 23417ULL: goto x86_l_5b79;
	case 23422ULL: goto x86_l_5b7e;
	case 23427ULL: goto x86_l_5b83;
	case 23436ULL: goto x86_l_5b8c;
	case 23438ULL: goto x86_l_5b8e;
	case 23443ULL: goto x86_l_5b93;
	case 23448ULL: goto x86_l_5b98;
	case 23453ULL: goto x86_l_5b9d;
	case 23458ULL: goto x86_l_5ba2;
	case 23463ULL: goto x86_l_5ba7;
	case 23465ULL: goto x86_l_5ba9;
	case 23467ULL: goto x86_l_5bab;
	case 23473ULL: goto x86_l_5bb1;
	case 23482ULL: goto x86_l_5bba;
	case 23488ULL: goto x86_l_5bc0;
	case 23495ULL: goto x86_l_5bc7;
	case 23500ULL: goto x86_l_5bcc;
	case 23505ULL: goto x86_l_5bd1;
	case 23514ULL: goto x86_l_5bda;
	case 23516ULL: goto x86_l_5bdc;
	case 23521ULL: goto x86_l_5be1;
	case 23526ULL: goto x86_l_5be6;
	case 23531ULL: goto x86_l_5beb;
	case 23536ULL: goto x86_l_5bf0;
	case 23541ULL: goto x86_l_5bf5;
	case 23543ULL: goto x86_l_5bf7;
	case 23545ULL: goto x86_l_5bf9;
	case 23551ULL: goto x86_l_5bff;
	case 23560ULL: goto x86_l_5c08;
	case 23566ULL: goto x86_l_5c0e;
	case 23573ULL: goto x86_l_5c15;
	case 23578ULL: goto x86_l_5c1a;
	case 23583ULL: goto x86_l_5c1f;
	case 23592ULL: goto x86_l_5c28;
	case 23594ULL: goto x86_l_5c2a;
	case 23599ULL: goto x86_l_5c2f;
	case 23604ULL: goto x86_l_5c34;
	case 23609ULL: goto x86_l_5c39;
	case 23614ULL: goto x86_l_5c3e;
	case 23619ULL: goto x86_l_5c43;
	case 23621ULL: goto x86_l_5c45;
	case 23623ULL: goto x86_l_5c47;
	case 23629ULL: goto x86_l_5c4d;
	case 23638ULL: goto x86_l_5c56;
	case 23644ULL: goto x86_l_5c5c;
	case 23651ULL: goto x86_l_5c63;
	case 23656ULL: goto x86_l_5c68;
	case 23661ULL: goto x86_l_5c6d;
	case 23670ULL: goto x86_l_5c76;
	case 23672ULL: goto x86_l_5c78;
	case 23677ULL: goto x86_l_5c7d;
	case 23682ULL: goto x86_l_5c82;
	case 23687ULL: goto x86_l_5c87;
	case 23692ULL: goto x86_l_5c8c;
	case 23697ULL: goto x86_l_5c91;
	case 23699ULL: goto x86_l_5c93;
	case 23701ULL: goto x86_l_5c95;
	case 23707ULL: goto x86_l_5c9b;
	case 23716ULL: goto x86_l_5ca4;
	case 23722ULL: goto x86_l_5caa;
	case 23729ULL: goto x86_l_5cb1;
	case 23734ULL: goto x86_l_5cb6;
	case 23739ULL: goto x86_l_5cbb;
	case 23748ULL: goto x86_l_5cc4;
	case 23750ULL: goto x86_l_5cc6;
	case 23755ULL: goto x86_l_5ccb;
	case 23760ULL: goto x86_l_5cd0;
	case 23765ULL: goto x86_l_5cd5;
	case 23770ULL: goto x86_l_5cda;
	case 23775ULL: goto x86_l_5cdf;
	case 23777ULL: goto x86_l_5ce1;
	case 23779ULL: goto x86_l_5ce3;
	case 23785ULL: goto x86_l_5ce9;
	case 23794ULL: goto x86_l_5cf2;
	case 23800ULL: goto x86_l_5cf8;
	case 23807ULL: goto x86_l_5cff;
	case 23812ULL: goto x86_l_5d04;
	case 23817ULL: goto x86_l_5d09;
	case 23826ULL: goto x86_l_5d12;
	case 23828ULL: goto x86_l_5d14;
	case 23833ULL: goto x86_l_5d19;
	case 23838ULL: goto x86_l_5d1e;
	case 23843ULL: goto x86_l_5d23;
	case 23848ULL: goto x86_l_5d28;
	case 23853ULL: goto x86_l_5d2d;
	case 23855ULL: goto x86_l_5d2f;
	case 23857ULL: goto x86_l_5d31;
	case 23863ULL: goto x86_l_5d37;
	case 23868ULL: goto x86_l_5d3c;
	case 23876ULL: goto x86_l_5d44;
	case 23882ULL: goto x86_l_5d4a;
	case 23888ULL: goto x86_l_5d50;
	case 23893ULL: goto x86_l_5d55;
	case 23898ULL: goto x86_l_5d5a;
	case 23906ULL: goto x86_l_5d62;
	case 23908ULL: goto x86_l_5d64;
	case 23913ULL: goto x86_l_5d69;
	case 23918ULL: goto x86_l_5d6e;
	case 23923ULL: goto x86_l_5d73;
	case 23928ULL: goto x86_l_5d78;
	case 23933ULL: goto x86_l_5d7d;
	case 23935ULL: goto x86_l_5d7f;
	case 23937ULL: goto x86_l_5d81;
	case 23943ULL: goto x86_l_5d87;
	case 23948ULL: goto x86_l_5d8c;
	case 23956ULL: goto x86_l_5d94;
	case 23962ULL: goto x86_l_5d9a;
	case 23968ULL: goto x86_l_5da0;
	case 23973ULL: goto x86_l_5da5;
	case 23978ULL: goto x86_l_5daa;
	case 23986ULL: goto x86_l_5db2;
	case 23992ULL: goto x86_l_5db8;
	case 23997ULL: goto x86_l_5dbd;
	case 24002ULL: goto x86_l_5dc2;
	case 24007ULL: goto x86_l_5dc7;
	case 24012ULL: goto x86_l_5dcc;
	case 24015ULL: goto x86_l_5dcf;
	case 24017ULL: goto x86_l_5dd1;
	case 24022ULL: goto x86_l_5dd6;
	case 24027ULL: goto x86_l_5ddb;
	case 24032ULL: goto x86_l_5de0;
	case 24037ULL: goto x86_l_5de5;
	case 24042ULL: goto x86_l_5dea;
	case 24044ULL: goto x86_l_5dec;
	case 24046ULL: goto x86_l_5dee;
	case 24052ULL: goto x86_l_5df4;
	case 24061ULL: goto x86_l_5dfd;
	case 24067ULL: goto x86_l_5e03;
	case 24074ULL: goto x86_l_5e0a;
	case 24079ULL: goto x86_l_5e0f;
	case 24084ULL: goto x86_l_5e14;
	case 24093ULL: goto x86_l_5e1d;
	case 24095ULL: goto x86_l_5e1f;
	case 24100ULL: goto x86_l_5e24;
	case 24105ULL: goto x86_l_5e29;
	case 24110ULL: goto x86_l_5e2e;
	case 24115ULL: goto x86_l_5e33;
	case 24120ULL: goto x86_l_5e38;
	case 24122ULL: goto x86_l_5e3a;
	case 24124ULL: goto x86_l_5e3c;
	case 24130ULL: goto x86_l_5e42;
	case 24139ULL: goto x86_l_5e4b;
	case 24145ULL: goto x86_l_5e51;
	case 24152ULL: goto x86_l_5e58;
	case 24157ULL: goto x86_l_5e5d;
	case 24162ULL: goto x86_l_5e62;
	case 24171ULL: goto x86_l_5e6b;
	case 24173ULL: goto x86_l_5e6d;
	case 24178ULL: goto x86_l_5e72;
	case 24183ULL: goto x86_l_5e77;
	case 24188ULL: goto x86_l_5e7c;
	case 24193ULL: goto x86_l_5e81;
	case 24198ULL: goto x86_l_5e86;
	case 24200ULL: goto x86_l_5e88;
	case 24202ULL: goto x86_l_5e8a;
	case 24208ULL: goto x86_l_5e90;
	case 24217ULL: goto x86_l_5e99;
	case 24223ULL: goto x86_l_5e9f;
	case 24230ULL: goto x86_l_5ea6;
	case 24235ULL: goto x86_l_5eab;
	case 24240ULL: goto x86_l_5eb0;
	case 24249ULL: goto x86_l_5eb9;
	case 24251ULL: goto x86_l_5ebb;
	case 24256ULL: goto x86_l_5ec0;
	case 24261ULL: goto x86_l_5ec5;
	case 24266ULL: goto x86_l_5eca;
	case 24271ULL: goto x86_l_5ecf;
	case 24276ULL: goto x86_l_5ed4;
	case 24278ULL: goto x86_l_5ed6;
	case 24280ULL: goto x86_l_5ed8;
	case 24286ULL: goto x86_l_5ede;
	case 24295ULL: goto x86_l_5ee7;
	case 24301ULL: goto x86_l_5eed;
	case 24308ULL: goto x86_l_5ef4;
	case 24313ULL: goto x86_l_5ef9;
	case 24318ULL: goto x86_l_5efe;
	case 24327ULL: goto x86_l_5f07;
	case 24329ULL: goto x86_l_5f09;
	case 24334ULL: goto x86_l_5f0e;
	case 24339ULL: goto x86_l_5f13;
	case 24344ULL: goto x86_l_5f18;
	case 24349ULL: goto x86_l_5f1d;
	case 24354ULL: goto x86_l_5f22;
	case 24356ULL: goto x86_l_5f24;
	case 24358ULL: goto x86_l_5f26;
	case 24364ULL: goto x86_l_5f2c;
	case 24373ULL: goto x86_l_5f35;
	case 24379ULL: goto x86_l_5f3b;
	case 24386ULL: goto x86_l_5f42;
	case 24391ULL: goto x86_l_5f47;
	case 24396ULL: goto x86_l_5f4c;
	case 24405ULL: goto x86_l_5f55;
	case 24407ULL: goto x86_l_5f57;
	case 24412ULL: goto x86_l_5f5c;
	case 24417ULL: goto x86_l_5f61;
	case 24422ULL: goto x86_l_5f66;
	case 24427ULL: goto x86_l_5f6b;
	case 24432ULL: goto x86_l_5f70;
	case 24434ULL: goto x86_l_5f72;
	case 24436ULL: goto x86_l_5f74;
	case 24442ULL: goto x86_l_5f7a;
	case 24451ULL: goto x86_l_5f83;
	case 24457ULL: goto x86_l_5f89;
	case 24464ULL: goto x86_l_5f90;
	case 24469ULL: goto x86_l_5f95;
	case 24474ULL: goto x86_l_5f9a;
	case 24483ULL: goto x86_l_5fa3;
	case 24485ULL: goto x86_l_5fa5;
	case 24490ULL: goto x86_l_5faa;
	case 24495ULL: goto x86_l_5faf;
	case 24500ULL: goto x86_l_5fb4;
	case 24505ULL: goto x86_l_5fb9;
	case 24510ULL: goto x86_l_5fbe;
	case 24512ULL: goto x86_l_5fc0;
	case 24514ULL: goto x86_l_5fc2;
	case 24520ULL: goto x86_l_5fc8;
	case 24529ULL: goto x86_l_5fd1;
	case 24535ULL: goto x86_l_5fd7;
	case 24542ULL: goto x86_l_5fde;
	case 24547ULL: goto x86_l_5fe3;
	case 24552ULL: goto x86_l_5fe8;
	case 24561ULL: goto x86_l_5ff1;
	case 24563ULL: goto x86_l_5ff3;
	case 24568ULL: goto x86_l_5ff8;
	case 24573ULL: goto x86_l_5ffd;
	case 24578ULL: goto x86_l_6002;
	case 24583ULL: goto x86_l_6007;
	case 24588ULL: goto x86_l_600c;
	case 24590ULL: goto x86_l_600e;
	case 24592ULL: goto x86_l_6010;
	case 24598ULL: goto x86_l_6016;
	case 24603ULL: goto x86_l_601b;
	case 24611ULL: goto x86_l_6023;
	case 24617ULL: goto x86_l_6029;
	case 24623ULL: goto x86_l_602f;
	case 24628ULL: goto x86_l_6034;
	case 24633ULL: goto x86_l_6039;
	case 24641ULL: goto x86_l_6041;
	case 24643ULL: goto x86_l_6043;
	case 24648ULL: goto x86_l_6048;
	case 24653ULL: goto x86_l_604d;
	case 24658ULL: goto x86_l_6052;
	case 24663ULL: goto x86_l_6057;
	case 24668ULL: goto x86_l_605c;
	case 24670ULL: goto x86_l_605e;
	case 24672ULL: goto x86_l_6060;
	case 24678ULL: goto x86_l_6066;
	case 24683ULL: goto x86_l_606b;
	case 24691ULL: goto x86_l_6073;
	case 24697ULL: goto x86_l_6079;
	case 24703ULL: goto x86_l_607f;
	case 24708ULL: goto x86_l_6084;
	case 24713ULL: goto x86_l_6089;
	case 24721ULL: goto x86_l_6091;
	case 24727ULL: goto x86_l_6097;
	case 24732ULL: goto x86_l_609c;
	case 24737ULL: goto x86_l_60a1;
	case 24742ULL: goto x86_l_60a6;
	case 24747ULL: goto x86_l_60ab;
	case 24752ULL: goto x86_l_60b0;
	case 24754ULL: goto x86_l_60b2;
	case 24756ULL: goto x86_l_60b4;
	case 24762ULL: goto x86_l_60ba;
	case 24767ULL: goto x86_l_60bf;
	case 24772ULL: goto x86_l_60c4;
	case 24777ULL: goto x86_l_60c9;
	case 24782ULL: goto x86_l_60ce;
	case 24787ULL: goto x86_l_60d3;
	case 24792ULL: goto x86_l_60d8;
	case 24797ULL: goto x86_l_60dd;
	case 24802ULL: goto x86_l_60e2;
	case 24807ULL: goto x86_l_60e7;
	case 24812ULL: goto x86_l_60ec;
	case 24817ULL: goto x86_l_60f1;
	case 24822ULL: goto x86_l_60f6;
	case 24827ULL: goto x86_l_60fb;
	case 24832ULL: goto x86_l_6100;
	case 24837ULL: goto x86_l_6105;
	default: return 0xffffffffffffffffULL;
	}
x86_l_596a:
	/* 0x596a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_596f:
	/* 0x596f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5971:
	/* 0x5971: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5973:
	/* 0x5973: js     673f <generic_sleepable_preload+0x673f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26431ULL;
	}
x86_l_5979:
	/* 0x5979: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_5982:
	/* 0x5982: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_5988:
	/* 0x5988: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_598f:
	/* 0x598f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5994:
	/* 0x5994: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5999:
	/* 0x5999: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_59a2:
	/* 0x59a2: je     59c7 <generic_sleepable_preload+0x59c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59c7;
	}
x86_l_59a4:
	/* 0x59a4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59a9:
	/* 0x59a9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59ae:
	/* 0x59ae: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59b3:
	/* 0x59b3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59b8:
	/* 0x59b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59bd:
	/* 0x59bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59bf:
	/* 0x59bf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_59c1:
	/* 0x59c1: js     6a4f <generic_sleepable_preload+0x6a4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27215ULL;
	}
x86_l_59c7:
	/* 0x59c7: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_59cc:
	/* 0x59cc: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_59d5:
	/* 0x59d5: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_59db:
	/* 0x59db: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_59e2:
	/* 0x59e2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_59e7:
	/* 0x59e7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59ec:
	/* 0x59ec: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_59f5:
	/* 0x59f5: je     5a1a <generic_sleepable_preload+0x5a1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a1a;
	}
x86_l_59f7:
	/* 0x59f7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59fc:
	/* 0x59fc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5a01:
	/* 0x5a01: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a06:
	/* 0x5a06: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a0b:
	/* 0x5a0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a10:
	/* 0x5a10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a12:
	/* 0x5a12: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a14:
	/* 0x5a14: js     6997 <generic_sleepable_preload+0x6997> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27031ULL;
	}
x86_l_5a1a:
	/* 0x5a1a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5a1f:
	/* 0x5a1f: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_5a28:
	/* 0x5a28: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_5a2e:
	/* 0x5a2e: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_5a35:
	/* 0x5a35: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a3a:
	/* 0x5a3a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a3f:
	/* 0x5a3f: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_5a48:
	/* 0x5a48: je     6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26438ULL;
	}
x86_l_5a4e:
	/* 0x5a4e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a53:
	/* 0x5a53: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5a58:
	/* 0x5a58: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a5d:
	/* 0x5a5d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a62:
	/* 0x5a62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a67:
	/* 0x5a67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a69:
	/* 0x5a69: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a6b:
	/* 0x5a6b: jns    6746 <generic_sleepable_preload+0x6746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26438ULL;
	}
x86_l_5a71:
	/* 0x5a71: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_5a76:
	/* 0x5a76: jmp    6744 <generic_sleepable_preload+0x6744> */
	return 26436ULL;
x86_l_5a7b:
	/* 0x5a7b: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_5a80:
	/* 0x5a80: jmp    6744 <generic_sleepable_preload+0x6744> */
	return 26436ULL;
x86_l_5a85:
	/* 0x5a85: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5a8a:
	/* 0x5a8a: jmp    6744 <generic_sleepable_preload+0x6744> */
	return 26436ULL;
x86_l_5a8f:
	/* 0x5a8f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a94:
	/* 0x5a94: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_5a97:
	/* 0x5a97: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_5a99:
	/* 0x5a99: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5a9b:
	/* 0x5a9b: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_5aa0:
	/* 0x5aa0: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5aa2:
	/* 0x5aa2: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_5aa7:
	/* 0x5aa7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5aac:
	/* 0x5aac: mov    ebx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5ab0:
	/* 0x5ab0: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ab2:
	/* 0x5ab2: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_5ab5:
	/* 0x5ab5: cmp    WORD PTR [r13+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_5abe:
	/* 0x5abe: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5ac4:
	/* 0x5ac4: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5acb:
	/* 0x5acb: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5ace:
	/* 0x5ace: mov    eax,DWORD PTR [r13+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_5ad5:
	/* 0x5ad5: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5ad8:
	/* 0x5ad8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5add:
	/* 0x5add: movzx  eax,WORD PTR [r13+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_5ae5:
	/* 0x5ae5: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_5ae7:
	/* 0x5ae7: je     5dcc <generic_sleepable_preload+0x5dcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5dcc;
	}
x86_l_5aed:
	/* 0x5aed: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5af0:
	/* 0x5af0: je     5b15 <generic_sleepable_preload+0x5b15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b15;
	}
x86_l_5af2:
	/* 0x5af2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5af7:
	/* 0x5af7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5afc:
	/* 0x5afc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b01:
	/* 0x5b01: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b06:
	/* 0x5b06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b0b:
	/* 0x5b0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b0d:
	/* 0x5b0d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b0f:
	/* 0x5b0f: js     60c4 <generic_sleepable_preload+0x60c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60c4;
	}
x86_l_5b15:
	/* 0x5b15: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5b1e:
	/* 0x5b1e: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5b24:
	/* 0x5b24: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5b2b:
	/* 0x5b2b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b30:
	/* 0x5b30: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b35:
	/* 0x5b35: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5b3e:
	/* 0x5b3e: je     5b63 <generic_sleepable_preload+0x5b63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b63;
	}
x86_l_5b40:
	/* 0x5b40: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b45:
	/* 0x5b45: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b4a:
	/* 0x5b4a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b4f:
	/* 0x5b4f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b54:
	/* 0x5b54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b59:
	/* 0x5b59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b5b:
	/* 0x5b5b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b5d:
	/* 0x5b5d: js     60ce <generic_sleepable_preload+0x60ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60ce;
	}
x86_l_5b63:
	/* 0x5b63: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_5b6c:
	/* 0x5b6c: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5b72:
	/* 0x5b72: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5b79:
	/* 0x5b79: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b7e:
	/* 0x5b7e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b83:
	/* 0x5b83: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5b8c:
	/* 0x5b8c: je     5bb1 <generic_sleepable_preload+0x5bb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5bb1;
	}
x86_l_5b8e:
	/* 0x5b8e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b93:
	/* 0x5b93: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b98:
	/* 0x5b98: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b9d:
	/* 0x5b9d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ba2:
	/* 0x5ba2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ba7:
	/* 0x5ba7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ba9:
	/* 0x5ba9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5bab:
	/* 0x5bab: js     6132 <generic_sleepable_preload+0x6132> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24882ULL;
	}
x86_l_5bb1:
	/* 0x5bb1: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5bba:
	/* 0x5bba: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5bc0:
	/* 0x5bc0: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5bc7:
	/* 0x5bc7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5bcc:
	/* 0x5bcc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bd1:
	/* 0x5bd1: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5bda:
	/* 0x5bda: je     5bff <generic_sleepable_preload+0x5bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5bff;
	}
x86_l_5bdc:
	/* 0x5bdc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5be1:
	/* 0x5be1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5be6:
	/* 0x5be6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5beb:
	/* 0x5beb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bf0:
	/* 0x5bf0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bf5:
	/* 0x5bf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bf7:
	/* 0x5bf7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5bf9:
	/* 0x5bf9: js     6196 <generic_sleepable_preload+0x6196> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24982ULL;
	}
x86_l_5bff:
	/* 0x5bff: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5c08:
	/* 0x5c08: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5c0e:
	/* 0x5c0e: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5c15:
	/* 0x5c15: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5c1a:
	/* 0x5c1a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c1f:
	/* 0x5c1f: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5c28:
	/* 0x5c28: je     5c4d <generic_sleepable_preload+0x5c4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c4d;
	}
x86_l_5c2a:
	/* 0x5c2a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c2f:
	/* 0x5c2f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c34:
	/* 0x5c34: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c39:
	/* 0x5c39: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c3e:
	/* 0x5c3e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c43:
	/* 0x5c43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c45:
	/* 0x5c45: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c47:
	/* 0x5c47: js     61fa <generic_sleepable_preload+0x61fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25082ULL;
	}
x86_l_5c4d:
	/* 0x5c4d: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5c56:
	/* 0x5c56: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5c5c:
	/* 0x5c5c: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5c63:
	/* 0x5c63: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5c68:
	/* 0x5c68: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c6d:
	/* 0x5c6d: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5c76:
	/* 0x5c76: je     5c9b <generic_sleepable_preload+0x5c9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c9b;
	}
x86_l_5c78:
	/* 0x5c78: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c7d:
	/* 0x5c7d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c82:
	/* 0x5c82: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c87:
	/* 0x5c87: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c8c:
	/* 0x5c8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c91:
	/* 0x5c91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c93:
	/* 0x5c93: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c95:
	/* 0x5c95: js     625b <generic_sleepable_preload+0x625b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25179ULL;
	}
x86_l_5c9b:
	/* 0x5c9b: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5ca4:
	/* 0x5ca4: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5caa:
	/* 0x5caa: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5cb1:
	/* 0x5cb1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5cb6:
	/* 0x5cb6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cbb:
	/* 0x5cbb: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5cc4:
	/* 0x5cc4: je     5ce9 <generic_sleepable_preload+0x5ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ce9;
	}
x86_l_5cc6:
	/* 0x5cc6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ccb:
	/* 0x5ccb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5cd0:
	/* 0x5cd0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5cd5:
	/* 0x5cd5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cda:
	/* 0x5cda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cdf:
	/* 0x5cdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ce1:
	/* 0x5ce1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ce3:
	/* 0x5ce3: js     67ef <generic_sleepable_preload+0x67ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26607ULL;
	}
x86_l_5ce9:
	/* 0x5ce9: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5cf2:
	/* 0x5cf2: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5cf8:
	/* 0x5cf8: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5cff:
	/* 0x5cff: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5d04:
	/* 0x5d04: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d09:
	/* 0x5d09: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5d12:
	/* 0x5d12: je     5d37 <generic_sleepable_preload+0x5d37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d37;
	}
x86_l_5d14:
	/* 0x5d14: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d19:
	/* 0x5d19: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d1e:
	/* 0x5d1e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5d23:
	/* 0x5d23: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d28:
	/* 0x5d28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d2d:
	/* 0x5d2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d2f:
	/* 0x5d2f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d31:
	/* 0x5d31: js     689f <generic_sleepable_preload+0x689f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26783ULL;
	}
x86_l_5d37:
	/* 0x5d37: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d3c:
	/* 0x5d3c: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5d44:
	/* 0x5d44: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5d4a:
	/* 0x5d4a: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5d50:
	/* 0x5d50: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5d55:
	/* 0x5d55: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d5a:
	/* 0x5d5a: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5d62:
	/* 0x5d62: je     5d87 <generic_sleepable_preload+0x5d87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d87;
	}
x86_l_5d64:
	/* 0x5d64: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d69:
	/* 0x5d69: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d6e:
	/* 0x5d6e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5d73:
	/* 0x5d73: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d78:
	/* 0x5d78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d7d:
	/* 0x5d7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d7f:
	/* 0x5d7f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d81:
	/* 0x5d81: js     69a8 <generic_sleepable_preload+0x69a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27048ULL;
	}
x86_l_5d87:
	/* 0x5d87: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d8c:
	/* 0x5d8c: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5d94:
	/* 0x5d94: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5d9a:
	/* 0x5d9a: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5da0:
	/* 0x5da0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5da5:
	/* 0x5da5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5daa:
	/* 0x5daa: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_5db2:
	/* 0x5db2: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5db8:
	/* 0x5db8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dbd:
	/* 0x5dbd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5dc2:
	/* 0x5dc2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5dc7:
	/* 0x5dc7: jmp    60a6 <generic_sleepable_preload+0x60a6> */
	goto x86_l_60a6;
x86_l_5dcc:
	/* 0x5dcc: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5dcf:
	/* 0x5dcf: je     5df4 <generic_sleepable_preload+0x5df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5df4;
	}
x86_l_5dd1:
	/* 0x5dd1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dd6:
	/* 0x5dd6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ddb:
	/* 0x5ddb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5de0:
	/* 0x5de0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5de5:
	/* 0x5de5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5dea:
	/* 0x5dea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dec:
	/* 0x5dec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5dee:
	/* 0x5dee: js     60c4 <generic_sleepable_preload+0x60c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60c4;
	}
x86_l_5df4:
	/* 0x5df4: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5dfd:
	/* 0x5dfd: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5e03:
	/* 0x5e03: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5e0a:
	/* 0x5e0a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5e0f:
	/* 0x5e0f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e14:
	/* 0x5e14: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5e1d:
	/* 0x5e1d: je     5e42 <generic_sleepable_preload+0x5e42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e42;
	}
x86_l_5e1f:
	/* 0x5e1f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e24:
	/* 0x5e24: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5e29:
	/* 0x5e29: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e2e:
	/* 0x5e2e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e33:
	/* 0x5e33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e38:
	/* 0x5e38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e3a:
	/* 0x5e3a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e3c:
	/* 0x5e3c: js     60ce <generic_sleepable_preload+0x60ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60ce;
	}
x86_l_5e42:
	/* 0x5e42: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_5e4b:
	/* 0x5e4b: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5e51:
	/* 0x5e51: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5e58:
	/* 0x5e58: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5e5d:
	/* 0x5e5d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e62:
	/* 0x5e62: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5e6b:
	/* 0x5e6b: je     5e90 <generic_sleepable_preload+0x5e90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e90;
	}
x86_l_5e6d:
	/* 0x5e6d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e72:
	/* 0x5e72: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5e77:
	/* 0x5e77: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e7c:
	/* 0x5e7c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e81:
	/* 0x5e81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e86:
	/* 0x5e86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e88:
	/* 0x5e88: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e8a:
	/* 0x5e8a: js     6132 <generic_sleepable_preload+0x6132> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24882ULL;
	}
x86_l_5e90:
	/* 0x5e90: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5e99:
	/* 0x5e99: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5e9f:
	/* 0x5e9f: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5ea6:
	/* 0x5ea6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5eab:
	/* 0x5eab: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5eb0:
	/* 0x5eb0: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5eb9:
	/* 0x5eb9: je     5ede <generic_sleepable_preload+0x5ede> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ede;
	}
x86_l_5ebb:
	/* 0x5ebb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ec0:
	/* 0x5ec0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ec5:
	/* 0x5ec5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5eca:
	/* 0x5eca: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ecf:
	/* 0x5ecf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ed4:
	/* 0x5ed4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ed6:
	/* 0x5ed6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ed8:
	/* 0x5ed8: js     6196 <generic_sleepable_preload+0x6196> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24982ULL;
	}
x86_l_5ede:
	/* 0x5ede: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5ee7:
	/* 0x5ee7: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5eed:
	/* 0x5eed: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5ef4:
	/* 0x5ef4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5ef9:
	/* 0x5ef9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5efe:
	/* 0x5efe: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5f07:
	/* 0x5f07: je     5f2c <generic_sleepable_preload+0x5f2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f2c;
	}
x86_l_5f09:
	/* 0x5f09: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f0e:
	/* 0x5f0e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f13:
	/* 0x5f13: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5f18:
	/* 0x5f18: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f1d:
	/* 0x5f1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f22:
	/* 0x5f22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f24:
	/* 0x5f24: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f26:
	/* 0x5f26: js     61fa <generic_sleepable_preload+0x61fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25082ULL;
	}
x86_l_5f2c:
	/* 0x5f2c: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5f35:
	/* 0x5f35: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5f3b:
	/* 0x5f3b: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5f42:
	/* 0x5f42: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f47:
	/* 0x5f47: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f4c:
	/* 0x5f4c: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5f55:
	/* 0x5f55: je     5f7a <generic_sleepable_preload+0x5f7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f7a;
	}
x86_l_5f57:
	/* 0x5f57: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f5c:
	/* 0x5f5c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f61:
	/* 0x5f61: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5f66:
	/* 0x5f66: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f6b:
	/* 0x5f6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f70:
	/* 0x5f70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f72:
	/* 0x5f72: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f74:
	/* 0x5f74: js     625b <generic_sleepable_preload+0x625b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25179ULL;
	}
x86_l_5f7a:
	/* 0x5f7a: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5f83:
	/* 0x5f83: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5f89:
	/* 0x5f89: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5f90:
	/* 0x5f90: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f95:
	/* 0x5f95: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f9a:
	/* 0x5f9a: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5fa3:
	/* 0x5fa3: je     5fc8 <generic_sleepable_preload+0x5fc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fc8;
	}
x86_l_5fa5:
	/* 0x5fa5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5faa:
	/* 0x5faa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5faf:
	/* 0x5faf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5fb4:
	/* 0x5fb4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fb9:
	/* 0x5fb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fbe:
	/* 0x5fbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fc0:
	/* 0x5fc0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fc2:
	/* 0x5fc2: js     67ef <generic_sleepable_preload+0x67ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26607ULL;
	}
x86_l_5fc8:
	/* 0x5fc8: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5fd1:
	/* 0x5fd1: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_5fd7:
	/* 0x5fd7: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5fde:
	/* 0x5fde: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5fe3:
	/* 0x5fe3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fe8:
	/* 0x5fe8: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5ff1:
	/* 0x5ff1: je     6016 <generic_sleepable_preload+0x6016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6016;
	}
x86_l_5ff3:
	/* 0x5ff3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ff8:
	/* 0x5ff8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ffd:
	/* 0x5ffd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6002:
	/* 0x6002: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6007:
	/* 0x6007: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_600c:
	/* 0x600c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_600e:
	/* 0x600e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6010:
	/* 0x6010: js     689f <generic_sleepable_preload+0x689f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26783ULL;
	}
x86_l_6016:
	/* 0x6016: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_601b:
	/* 0x601b: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_6023:
	/* 0x6023: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_6029:
	/* 0x6029: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_602f:
	/* 0x602f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6034:
	/* 0x6034: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6039:
	/* 0x6039: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_6041:
	/* 0x6041: je     6066 <generic_sleepable_preload+0x6066> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6066;
	}
x86_l_6043:
	/* 0x6043: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6048:
	/* 0x6048: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_604d:
	/* 0x604d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6052:
	/* 0x6052: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6057:
	/* 0x6057: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_605c:
	/* 0x605c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_605e:
	/* 0x605e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6060:
	/* 0x6060: js     69a8 <generic_sleepable_preload+0x69a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27048ULL;
	}
x86_l_6066:
	/* 0x6066: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_606b:
	/* 0x606b: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_6073:
	/* 0x6073: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_6079:
	/* 0x6079: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_607f:
	/* 0x607f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6084:
	/* 0x6084: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6089:
	/* 0x6089: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_6091:
	/* 0x6091: je     67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26615ULL;
	}
x86_l_6097:
	/* 0x6097: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_609c:
	/* 0x609c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_60a1:
	/* 0x60a1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_60a6:
	/* 0x60a6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60ab:
	/* 0x60ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60b0:
	/* 0x60b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60b2:
	/* 0x60b2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_60b4:
	/* 0x60b4: jns    67f7 <generic_sleepable_preload+0x67f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26615ULL;
	}
x86_l_60ba:
	/* 0x60ba: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_60bf:
	/* 0x60bf: jmp    67f4 <generic_sleepable_preload+0x67f4> */
	return 26612ULL;
x86_l_60c4:
	/* 0x60c4: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_60c9:
	/* 0x60c9: jmp    67f4 <generic_sleepable_preload+0x67f4> */
	return 26612ULL;
x86_l_60ce:
	/* 0x60ce: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_60d3:
	/* 0x60d3: jmp    67f4 <generic_sleepable_preload+0x67f4> */
	return 26612ULL;
x86_l_60d8:
	/* 0x60d8: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_60dd:
	/* 0x60dd: jmp    626a <generic_sleepable_preload+0x626a> */
	return 25194ULL;
x86_l_60e2:
	/* 0x60e2: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_60e7:
	/* 0x60e7: jmp    62f7 <generic_sleepable_preload+0x62f7> */
	return 25335ULL;
x86_l_60ec:
	/* 0x60ec: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_60f1:
	/* 0x60f1: jmp    6384 <generic_sleepable_preload+0x6384> */
	return 25476ULL;
x86_l_60f6:
	/* 0x60f6: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_60fb:
	/* 0x60fb: jmp    6411 <generic_sleepable_preload+0x6411> */
	return 25617ULL;
x86_l_6100:
	/* 0x6100: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_6105:
	/* 0x6105: jmp    649e <generic_sleepable_preload+0x649e> */
	return 25758ULL;
	return 24842ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 24842ULL: goto x86_l_610a;
	case 24847ULL: goto x86_l_610f;
	case 24852ULL: goto x86_l_6114;
	case 24857ULL: goto x86_l_6119;
	case 24862ULL: goto x86_l_611e;
	case 24867ULL: goto x86_l_6123;
	case 24872ULL: goto x86_l_6128;
	case 24877ULL: goto x86_l_612d;
	case 24882ULL: goto x86_l_6132;
	case 24887ULL: goto x86_l_6137;
	case 24892ULL: goto x86_l_613c;
	case 24897ULL: goto x86_l_6141;
	case 24902ULL: goto x86_l_6146;
	case 24907ULL: goto x86_l_614b;
	case 24912ULL: goto x86_l_6150;
	case 24917ULL: goto x86_l_6155;
	case 24922ULL: goto x86_l_615a;
	case 24927ULL: goto x86_l_615f;
	case 24932ULL: goto x86_l_6164;
	case 24937ULL: goto x86_l_6169;
	case 24942ULL: goto x86_l_616e;
	case 24947ULL: goto x86_l_6173;
	case 24952ULL: goto x86_l_6178;
	case 24957ULL: goto x86_l_617d;
	case 24962ULL: goto x86_l_6182;
	case 24967ULL: goto x86_l_6187;
	case 24972ULL: goto x86_l_618c;
	case 24977ULL: goto x86_l_6191;
	case 24982ULL: goto x86_l_6196;
	case 24987ULL: goto x86_l_619b;
	case 24992ULL: goto x86_l_61a0;
	case 24997ULL: goto x86_l_61a5;
	case 25002ULL: goto x86_l_61aa;
	case 25007ULL: goto x86_l_61af;
	case 25012ULL: goto x86_l_61b4;
	case 25017ULL: goto x86_l_61b9;
	case 25022ULL: goto x86_l_61be;
	case 25027ULL: goto x86_l_61c3;
	case 25032ULL: goto x86_l_61c8;
	case 25037ULL: goto x86_l_61cd;
	case 25042ULL: goto x86_l_61d2;
	case 25047ULL: goto x86_l_61d7;
	case 25052ULL: goto x86_l_61dc;
	case 25057ULL: goto x86_l_61e1;
	case 25062ULL: goto x86_l_61e6;
	case 25067ULL: goto x86_l_61eb;
	case 25072ULL: goto x86_l_61f0;
	case 25077ULL: goto x86_l_61f5;
	case 25082ULL: goto x86_l_61fa;
	case 25087ULL: goto x86_l_61ff;
	case 25092ULL: goto x86_l_6204;
	case 25097ULL: goto x86_l_6209;
	case 25099ULL: goto x86_l_620b;
	case 25104ULL: goto x86_l_6210;
	case 25109ULL: goto x86_l_6215;
	case 25114ULL: goto x86_l_621a;
	case 25119ULL: goto x86_l_621f;
	case 25124ULL: goto x86_l_6224;
	case 25129ULL: goto x86_l_6229;
	case 25134ULL: goto x86_l_622e;
	case 25139ULL: goto x86_l_6233;
	case 25144ULL: goto x86_l_6238;
	case 25149ULL: goto x86_l_623d;
	case 25154ULL: goto x86_l_6242;
	case 25159ULL: goto x86_l_6247;
	case 25164ULL: goto x86_l_624c;
	case 25169ULL: goto x86_l_6251;
	case 25174ULL: goto x86_l_6256;
	case 25179ULL: goto x86_l_625b;
	case 25184ULL: goto x86_l_6260;
	case 25189ULL: goto x86_l_6265;
	case 25194ULL: goto x86_l_626a;
	case 25196ULL: goto x86_l_626c;
	case 25200ULL: goto x86_l_6270;
	case 25205ULL: goto x86_l_6275;
	case 25210ULL: goto x86_l_627a;
	case 25215ULL: goto x86_l_627f;
	case 25220ULL: goto x86_l_6284;
	case 25223ULL: goto x86_l_6287;
	case 25225ULL: goto x86_l_6289;
	case 25229ULL: goto x86_l_628d;
	case 25235ULL: goto x86_l_6293;
	case 25240ULL: goto x86_l_6298;
	case 25245ULL: goto x86_l_629d;
	case 25247ULL: goto x86_l_629f;
	case 25252ULL: goto x86_l_62a4;
	case 25260ULL: goto x86_l_62ac;
	case 25267ULL: goto x86_l_62b3;
	case 25272ULL: goto x86_l_62b8;
	case 25277ULL: goto x86_l_62bd;
	case 25279ULL: goto x86_l_62bf;
	case 25282ULL: goto x86_l_62c2;
	case 25288ULL: goto x86_l_62c8;
	case 25291ULL: goto x86_l_62cb;
	case 25298ULL: goto x86_l_62d2;
	case 25300ULL: goto x86_l_62d4;
	case 25305ULL: goto x86_l_62d9;
	case 25310ULL: goto x86_l_62de;
	case 25313ULL: goto x86_l_62e1;
	case 25316ULL: goto x86_l_62e4;
	case 25318ULL: goto x86_l_62e6;
	case 25320ULL: goto x86_l_62e8;
	case 25325ULL: goto x86_l_62ed;
	case 25330ULL: goto x86_l_62f2;
	case 25335ULL: goto x86_l_62f7;
	case 25337ULL: goto x86_l_62f9;
	case 25341ULL: goto x86_l_62fd;
	case 25346ULL: goto x86_l_6302;
	case 25351ULL: goto x86_l_6307;
	case 25356ULL: goto x86_l_630c;
	case 25361ULL: goto x86_l_6311;
	case 25364ULL: goto x86_l_6314;
	case 25366ULL: goto x86_l_6316;
	case 25370ULL: goto x86_l_631a;
	case 25376ULL: goto x86_l_6320;
	case 25381ULL: goto x86_l_6325;
	case 25386ULL: goto x86_l_632a;
	case 25388ULL: goto x86_l_632c;
	case 25393ULL: goto x86_l_6331;
	case 25401ULL: goto x86_l_6339;
	case 25408ULL: goto x86_l_6340;
	case 25413ULL: goto x86_l_6345;
	case 25418ULL: goto x86_l_634a;
	case 25420ULL: goto x86_l_634c;
	case 25423ULL: goto x86_l_634f;
	case 25429ULL: goto x86_l_6355;
	case 25432ULL: goto x86_l_6358;
	case 25439ULL: goto x86_l_635f;
	case 25441ULL: goto x86_l_6361;
	case 25446ULL: goto x86_l_6366;
	case 25451ULL: goto x86_l_636b;
	case 25454ULL: goto x86_l_636e;
	case 25457ULL: goto x86_l_6371;
	case 25459ULL: goto x86_l_6373;
	case 25461ULL: goto x86_l_6375;
	case 25466ULL: goto x86_l_637a;
	case 25471ULL: goto x86_l_637f;
	case 25476ULL: goto x86_l_6384;
	case 25478ULL: goto x86_l_6386;
	case 25482ULL: goto x86_l_638a;
	case 25487ULL: goto x86_l_638f;
	case 25492ULL: goto x86_l_6394;
	case 25497ULL: goto x86_l_6399;
	case 25502ULL: goto x86_l_639e;
	case 25505ULL: goto x86_l_63a1;
	case 25507ULL: goto x86_l_63a3;
	case 25511ULL: goto x86_l_63a7;
	case 25517ULL: goto x86_l_63ad;
	case 25522ULL: goto x86_l_63b2;
	case 25527ULL: goto x86_l_63b7;
	case 25529ULL: goto x86_l_63b9;
	case 25534ULL: goto x86_l_63be;
	case 25542ULL: goto x86_l_63c6;
	case 25549ULL: goto x86_l_63cd;
	case 25554ULL: goto x86_l_63d2;
	case 25559ULL: goto x86_l_63d7;
	case 25561ULL: goto x86_l_63d9;
	case 25564ULL: goto x86_l_63dc;
	case 25570ULL: goto x86_l_63e2;
	case 25573ULL: goto x86_l_63e5;
	case 25580ULL: goto x86_l_63ec;
	case 25582ULL: goto x86_l_63ee;
	case 25587ULL: goto x86_l_63f3;
	case 25592ULL: goto x86_l_63f8;
	case 25595ULL: goto x86_l_63fb;
	case 25598ULL: goto x86_l_63fe;
	case 25600ULL: goto x86_l_6400;
	case 25602ULL: goto x86_l_6402;
	case 25607ULL: goto x86_l_6407;
	case 25612ULL: goto x86_l_640c;
	case 25617ULL: goto x86_l_6411;
	case 25619ULL: goto x86_l_6413;
	case 25623ULL: goto x86_l_6417;
	case 25628ULL: goto x86_l_641c;
	case 25633ULL: goto x86_l_6421;
	case 25638ULL: goto x86_l_6426;
	case 25643ULL: goto x86_l_642b;
	case 25646ULL: goto x86_l_642e;
	case 25648ULL: goto x86_l_6430;
	case 25652ULL: goto x86_l_6434;
	case 25658ULL: goto x86_l_643a;
	case 25663ULL: goto x86_l_643f;
	case 25668ULL: goto x86_l_6444;
	case 25670ULL: goto x86_l_6446;
	case 25675ULL: goto x86_l_644b;
	case 25683ULL: goto x86_l_6453;
	case 25690ULL: goto x86_l_645a;
	case 25695ULL: goto x86_l_645f;
	case 25700ULL: goto x86_l_6464;
	case 25702ULL: goto x86_l_6466;
	case 25705ULL: goto x86_l_6469;
	case 25711ULL: goto x86_l_646f;
	case 25714ULL: goto x86_l_6472;
	case 25721ULL: goto x86_l_6479;
	case 25723ULL: goto x86_l_647b;
	case 25728ULL: goto x86_l_6480;
	case 25733ULL: goto x86_l_6485;
	case 25736ULL: goto x86_l_6488;
	case 25739ULL: goto x86_l_648b;
	case 25741ULL: goto x86_l_648d;
	case 25743ULL: goto x86_l_648f;
	case 25748ULL: goto x86_l_6494;
	case 25753ULL: goto x86_l_6499;
	case 25758ULL: goto x86_l_649e;
	case 25761ULL: goto x86_l_64a1;
	case 25765ULL: goto x86_l_64a5;
	case 25770ULL: goto x86_l_64aa;
	case 25775ULL: goto x86_l_64af;
	case 25780ULL: goto x86_l_64b4;
	case 25785ULL: goto x86_l_64b9;
	case 25788ULL: goto x86_l_64bc;
	case 25790ULL: goto x86_l_64be;
	case 25793ULL: goto x86_l_64c1;
	case 25799ULL: goto x86_l_64c7;
	case 25804ULL: goto x86_l_64cc;
	case 25809ULL: goto x86_l_64d1;
	case 25811ULL: goto x86_l_64d3;
	case 25816ULL: goto x86_l_64d8;
	case 25824ULL: goto x86_l_64e0;
	case 25831ULL: goto x86_l_64e7;
	case 25836ULL: goto x86_l_64ec;
	case 25841ULL: goto x86_l_64f1;
	case 25843ULL: goto x86_l_64f3;
	case 25846ULL: goto x86_l_64f6;
	case 25852ULL: goto x86_l_64fc;
	case 25855ULL: goto x86_l_64ff;
	case 25862ULL: goto x86_l_6506;
	case 25864ULL: goto x86_l_6508;
	case 25869ULL: goto x86_l_650d;
	case 25874ULL: goto x86_l_6512;
	case 25877ULL: goto x86_l_6515;
	case 25880ULL: goto x86_l_6518;
	case 25882ULL: goto x86_l_651a;
	case 25884ULL: goto x86_l_651c;
	case 25889ULL: goto x86_l_6521;
	case 25894ULL: goto x86_l_6526;
	case 25899ULL: goto x86_l_652b;
	case 25901ULL: goto x86_l_652d;
	case 25905ULL: goto x86_l_6531;
	case 25911ULL: goto x86_l_6537;
	case 25916ULL: goto x86_l_653c;
	case 25921ULL: goto x86_l_6541;
	case 25923ULL: goto x86_l_6543;
	case 25928ULL: goto x86_l_6548;
	case 25936ULL: goto x86_l_6550;
	case 25943ULL: goto x86_l_6557;
	case 25948ULL: goto x86_l_655c;
	case 25953ULL: goto x86_l_6561;
	case 25955ULL: goto x86_l_6563;
	case 25958ULL: goto x86_l_6566;
	case 25964ULL: goto x86_l_656c;
	case 25967ULL: goto x86_l_656f;
	case 25974ULL: goto x86_l_6576;
	case 25976ULL: goto x86_l_6578;
	case 25981ULL: goto x86_l_657d;
	case 25986ULL: goto x86_l_6582;
	case 25989ULL: goto x86_l_6585;
	case 25992ULL: goto x86_l_6588;
	case 25994ULL: goto x86_l_658a;
	case 25996ULL: goto x86_l_658c;
	case 26001ULL: goto x86_l_6591;
	case 26004ULL: goto x86_l_6594;
	case 26009ULL: goto x86_l_6599;
	case 26012ULL: goto x86_l_659c;
	case 26014ULL: goto x86_l_659e;
	case 26017ULL: goto x86_l_65a1;
	case 26023ULL: goto x86_l_65a7;
	case 26026ULL: goto x86_l_65aa;
	case 26028ULL: goto x86_l_65ac;
	case 26031ULL: goto x86_l_65af;
	case 26035ULL: goto x86_l_65b3;
	case 26040ULL: goto x86_l_65b8;
	case 26043ULL: goto x86_l_65bb;
	case 26045ULL: goto x86_l_65bd;
	case 26048ULL: goto x86_l_65c0;
	case 26053ULL: goto x86_l_65c5;
	case 26055ULL: goto x86_l_65c7;
	case 26058ULL: goto x86_l_65ca;
	case 26060ULL: goto x86_l_65cc;
	case 26062ULL: goto x86_l_65ce;
	case 26067ULL: goto x86_l_65d3;
	case 26069ULL: goto x86_l_65d5;
	case 26074ULL: goto x86_l_65da;
	case 26079ULL: goto x86_l_65df;
	case 26081ULL: goto x86_l_65e1;
	case 26085ULL: goto x86_l_65e5;
	case 26091ULL: goto x86_l_65eb;
	case 26096ULL: goto x86_l_65f0;
	case 26101ULL: goto x86_l_65f5;
	case 26103ULL: goto x86_l_65f7;
	case 26108ULL: goto x86_l_65fc;
	case 26116ULL: goto x86_l_6604;
	case 26123ULL: goto x86_l_660b;
	case 26128ULL: goto x86_l_6610;
	case 26133ULL: goto x86_l_6615;
	case 26135ULL: goto x86_l_6617;
	case 26138ULL: goto x86_l_661a;
	case 26144ULL: goto x86_l_6620;
	case 26147ULL: goto x86_l_6623;
	case 26154ULL: goto x86_l_662a;
	case 26156ULL: goto x86_l_662c;
	case 26161ULL: goto x86_l_6631;
	case 26166ULL: goto x86_l_6636;
	case 26169ULL: goto x86_l_6639;
	case 26172ULL: goto x86_l_663c;
	case 26174ULL: goto x86_l_663e;
	case 26176ULL: goto x86_l_6640;
	case 26181ULL: goto x86_l_6645;
	case 26184ULL: goto x86_l_6648;
	case 26189ULL: goto x86_l_664d;
	case 26192ULL: goto x86_l_6650;
	case 26194ULL: goto x86_l_6652;
	case 26197ULL: goto x86_l_6655;
	case 26203ULL: goto x86_l_665b;
	case 26206ULL: goto x86_l_665e;
	case 26208ULL: goto x86_l_6660;
	case 26211ULL: goto x86_l_6663;
	case 26215ULL: goto x86_l_6667;
	case 26220ULL: goto x86_l_666c;
	case 26223ULL: goto x86_l_666f;
	case 26225ULL: goto x86_l_6671;
	case 26228ULL: goto x86_l_6674;
	case 26233ULL: goto x86_l_6679;
	case 26235ULL: goto x86_l_667b;
	case 26238ULL: goto x86_l_667e;
	case 26240ULL: goto x86_l_6680;
	case 26245ULL: goto x86_l_6685;
	case 26248ULL: goto x86_l_6688;
	case 26250ULL: goto x86_l_668a;
	case 26255ULL: goto x86_l_668f;
	case 26260ULL: goto x86_l_6694;
	case 26262ULL: goto x86_l_6696;
	case 26266ULL: goto x86_l_669a;
	case 26272ULL: goto x86_l_66a0;
	case 26277ULL: goto x86_l_66a5;
	case 26282ULL: goto x86_l_66aa;
	case 26284ULL: goto x86_l_66ac;
	case 26289ULL: goto x86_l_66b1;
	case 26297ULL: goto x86_l_66b9;
	case 26304ULL: goto x86_l_66c0;
	case 26309ULL: goto x86_l_66c5;
	case 26314ULL: goto x86_l_66ca;
	case 26316ULL: goto x86_l_66cc;
	case 26319ULL: goto x86_l_66cf;
	case 26325ULL: goto x86_l_66d5;
	case 26328ULL: goto x86_l_66d8;
	case 26335ULL: goto x86_l_66df;
	case 26337ULL: goto x86_l_66e1;
	case 26342ULL: goto x86_l_66e6;
	case 26347ULL: goto x86_l_66eb;
	case 26350ULL: goto x86_l_66ee;
	case 26353ULL: goto x86_l_66f1;
	case 26355ULL: goto x86_l_66f3;
	case 26357ULL: goto x86_l_66f5;
	case 26362ULL: goto x86_l_66fa;
	case 26365ULL: goto x86_l_66fd;
	case 26368ULL: goto x86_l_6700;
	case 26370ULL: goto x86_l_6702;
	case 26373ULL: goto x86_l_6705;
	case 26379ULL: goto x86_l_670b;
	case 26382ULL: goto x86_l_670e;
	case 26384ULL: goto x86_l_6710;
	case 26387ULL: goto x86_l_6713;
	case 26391ULL: goto x86_l_6717;
	case 26396ULL: goto x86_l_671c;
	case 26399ULL: goto x86_l_671f;
	case 26401ULL: goto x86_l_6721;
	case 26404ULL: goto x86_l_6724;
	case 26409ULL: goto x86_l_6729;
	case 26411ULL: goto x86_l_672b;
	case 26414ULL: goto x86_l_672e;
	case 26416ULL: goto x86_l_6730;
	case 26421ULL: goto x86_l_6735;
	case 26424ULL: goto x86_l_6738;
	case 26426ULL: goto x86_l_673a;
	case 26431ULL: goto x86_l_673f;
	case 26436ULL: goto x86_l_6744;
	case 26438ULL: goto x86_l_6746;
	case 26442ULL: goto x86_l_674a;
	case 26448ULL: goto x86_l_6750;
	case 26453ULL: goto x86_l_6755;
	case 26458ULL: goto x86_l_675a;
	case 26460ULL: goto x86_l_675c;
	case 26465ULL: goto x86_l_6761;
	default: return 0xffffffffffffffffULL;
	}
x86_l_610a:
	/* 0x610a: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_610f:
	/* 0x610f: jmp    652b <generic_sleepable_preload+0x652b> */
	goto x86_l_652b;
x86_l_6114:
	/* 0x6114: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_6119:
	/* 0x6119: jmp    65df <generic_sleepable_preload+0x65df> */
	goto x86_l_65df;
x86_l_611e:
	/* 0x611e: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_6123:
	/* 0x6123: jmp    6694 <generic_sleepable_preload+0x6694> */
	goto x86_l_6694;
x86_l_6128:
	/* 0x6128: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_612d:
	/* 0x612d: jmp    6744 <generic_sleepable_preload+0x6744> */
	goto x86_l_6744;
x86_l_6132:
	/* 0x6132: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_6137:
	/* 0x6137: jmp    67f4 <generic_sleepable_preload+0x67f4> */
	return 26612ULL;
x86_l_613c:
	/* 0x613c: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6141:
	/* 0x6141: jmp    626a <generic_sleepable_preload+0x626a> */
	goto x86_l_626a;
x86_l_6146:
	/* 0x6146: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_614b:
	/* 0x614b: jmp    62f7 <generic_sleepable_preload+0x62f7> */
	goto x86_l_62f7;
x86_l_6150:
	/* 0x6150: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6155:
	/* 0x6155: jmp    6384 <generic_sleepable_preload+0x6384> */
	goto x86_l_6384;
x86_l_615a:
	/* 0x615a: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_615f:
	/* 0x615f: jmp    6411 <generic_sleepable_preload+0x6411> */
	goto x86_l_6411;
x86_l_6164:
	/* 0x6164: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_6169:
	/* 0x6169: jmp    649e <generic_sleepable_preload+0x649e> */
	goto x86_l_649e;
x86_l_616e:
	/* 0x616e: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6173:
	/* 0x6173: jmp    652b <generic_sleepable_preload+0x652b> */
	goto x86_l_652b;
x86_l_6178:
	/* 0x6178: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_617d:
	/* 0x617d: jmp    65df <generic_sleepable_preload+0x65df> */
	goto x86_l_65df;
x86_l_6182:
	/* 0x6182: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6187:
	/* 0x6187: jmp    6694 <generic_sleepable_preload+0x6694> */
	goto x86_l_6694;
x86_l_618c:
	/* 0x618c: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6191:
	/* 0x6191: jmp    6744 <generic_sleepable_preload+0x6744> */
	goto x86_l_6744;
x86_l_6196:
	/* 0x6196: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_619b:
	/* 0x619b: jmp    67f4 <generic_sleepable_preload+0x67f4> */
	return 26612ULL;
x86_l_61a0:
	/* 0x61a0: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61a5:
	/* 0x61a5: jmp    626a <generic_sleepable_preload+0x626a> */
	goto x86_l_626a;
x86_l_61aa:
	/* 0x61aa: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61af:
	/* 0x61af: jmp    62f7 <generic_sleepable_preload+0x62f7> */
	goto x86_l_62f7;
x86_l_61b4:
	/* 0x61b4: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61b9:
	/* 0x61b9: jmp    6384 <generic_sleepable_preload+0x6384> */
	goto x86_l_6384;
x86_l_61be:
	/* 0x61be: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61c3:
	/* 0x61c3: jmp    6411 <generic_sleepable_preload+0x6411> */
	goto x86_l_6411;
x86_l_61c8:
	/* 0x61c8: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_61cd:
	/* 0x61cd: jmp    649e <generic_sleepable_preload+0x649e> */
	goto x86_l_649e;
x86_l_61d2:
	/* 0x61d2: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61d7:
	/* 0x61d7: jmp    652b <generic_sleepable_preload+0x652b> */
	goto x86_l_652b;
x86_l_61dc:
	/* 0x61dc: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61e1:
	/* 0x61e1: jmp    65df <generic_sleepable_preload+0x65df> */
	goto x86_l_65df;
x86_l_61e6:
	/* 0x61e6: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61eb:
	/* 0x61eb: jmp    6694 <generic_sleepable_preload+0x6694> */
	goto x86_l_6694;
x86_l_61f0:
	/* 0x61f0: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61f5:
	/* 0x61f5: jmp    6744 <generic_sleepable_preload+0x6744> */
	goto x86_l_6744;
x86_l_61fa:
	/* 0x61fa: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_61ff:
	/* 0x61ff: jmp    67f4 <generic_sleepable_preload+0x67f4> */
	return 26612ULL;
x86_l_6204:
	/* 0x6204: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6209:
	/* 0x6209: jmp    626a <generic_sleepable_preload+0x626a> */
	goto x86_l_626a;
x86_l_620b:
	/* 0x620b: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6210:
	/* 0x6210: jmp    62f7 <generic_sleepable_preload+0x62f7> */
	goto x86_l_62f7;
x86_l_6215:
	/* 0x6215: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_621a:
	/* 0x621a: jmp    6384 <generic_sleepable_preload+0x6384> */
	goto x86_l_6384;
x86_l_621f:
	/* 0x621f: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6224:
	/* 0x6224: jmp    6411 <generic_sleepable_preload+0x6411> */
	goto x86_l_6411;
x86_l_6229:
	/* 0x6229: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_622e:
	/* 0x622e: jmp    649e <generic_sleepable_preload+0x649e> */
	goto x86_l_649e;
x86_l_6233:
	/* 0x6233: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6238:
	/* 0x6238: jmp    652b <generic_sleepable_preload+0x652b> */
	goto x86_l_652b;
x86_l_623d:
	/* 0x623d: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6242:
	/* 0x6242: jmp    65df <generic_sleepable_preload+0x65df> */
	goto x86_l_65df;
x86_l_6247:
	/* 0x6247: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_624c:
	/* 0x624c: jmp    6694 <generic_sleepable_preload+0x6694> */
	goto x86_l_6694;
x86_l_6251:
	/* 0x6251: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6256:
	/* 0x6256: jmp    6744 <generic_sleepable_preload+0x6744> */
	goto x86_l_6744;
x86_l_625b:
	/* 0x625b: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_6260:
	/* 0x6260: jmp    67f4 <generic_sleepable_preload+0x67f4> */
	return 26612ULL;
x86_l_6265:
	/* 0x6265: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_626a:
	/* 0x626a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_626c:
	/* 0x626c: mov    r14d,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6270:
	/* 0x6270: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6275:
	/* 0x6275: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_627a:
	/* 0x627a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_627f:
	/* 0x627f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6284:
	/* 0x6284: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_6287:
	/* 0x6287: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6289:
	/* 0x6289: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_628d:
	/* 0x628d: jne    11ad <generic_sleepable_preload+0x11ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4525ULL;
	}
x86_l_6293:
	/* 0x6293: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6298:
	/* 0x6298: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_629d:
	/* 0x629d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_629f:
	/* 0x629f: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62a4:
	/* 0x62a4: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_62ac:
	/* 0x62ac: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_62b3:
	/* 0x62b3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_62b8:
	/* 0x62b8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_62bd:
	/* 0x62bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62bf:
	/* 0x62bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_62c2:
	/* 0x62c2: je     11ad <generic_sleepable_preload+0x11ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4525ULL;
	}
x86_l_62c8:
	/* 0x62c8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_62cb:
	/* 0x62cb: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_62d2:
	/* 0x62d2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62d4:
	/* 0x62d4: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62d9:
	/* 0x62d9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_62de:
	/* 0x62de: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_62e1:
	/* 0x62e1: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_62e4:
	/* 0x62e4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62e6:
	/* 0x62e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62e8:
	/* 0x62e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_62ed:
	/* 0x62ed: jmp    6591 <generic_sleepable_preload+0x6591> */
	goto x86_l_6591;
x86_l_62f2:
	/* 0x62f2: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_62f7:
	/* 0x62f7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62f9:
	/* 0x62f9: mov    r14d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_62fd:
	/* 0x62fd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6302:
	/* 0x6302: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6307:
	/* 0x6307: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_630c:
	/* 0x630c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6311:
	/* 0x6311: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_6314:
	/* 0x6314: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6316:
	/* 0x6316: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_631a:
	/* 0x631a: jne    11bc <generic_sleepable_preload+0x11bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4540ULL;
	}
x86_l_6320:
	/* 0x6320: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6325:
	/* 0x6325: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_632a:
	/* 0x632a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_632c:
	/* 0x632c: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6331:
	/* 0x6331: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6339:
	/* 0x6339: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6340:
	/* 0x6340: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6345:
	/* 0x6345: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_634a:
	/* 0x634a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_634c:
	/* 0x634c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_634f:
	/* 0x634f: je     11bc <generic_sleepable_preload+0x11bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4540ULL;
	}
x86_l_6355:
	/* 0x6355: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6358:
	/* 0x6358: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_635f:
	/* 0x635f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6361:
	/* 0x6361: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6366:
	/* 0x6366: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_636b:
	/* 0x636b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_636e:
	/* 0x636e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6371:
	/* 0x6371: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6373:
	/* 0x6373: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6375:
	/* 0x6375: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_637a:
	/* 0x637a: jmp    67aa <generic_sleepable_preload+0x67aa> */
	return 26538ULL;
x86_l_637f:
	/* 0x637f: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6384:
	/* 0x6384: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6386:
	/* 0x6386: mov    r14d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_638a:
	/* 0x638a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_638f:
	/* 0x638f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6394:
	/* 0x6394: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6399:
	/* 0x6399: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_639e:
	/* 0x639e: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_63a1:
	/* 0x63a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63a3:
	/* 0x63a3: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_63a7:
	/* 0x63a7: jne    11d0 <generic_sleepable_preload+0x11d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4560ULL;
	}
x86_l_63ad:
	/* 0x63ad: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_63b2:
	/* 0x63b2: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_63b7:
	/* 0x63b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63b9:
	/* 0x63b9: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63be:
	/* 0x63be: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_63c6:
	/* 0x63c6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_63cd:
	/* 0x63cd: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_63d2:
	/* 0x63d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63d7:
	/* 0x63d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63d9:
	/* 0x63d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63dc:
	/* 0x63dc: je     11d0 <generic_sleepable_preload+0x11d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4560ULL;
	}
x86_l_63e2:
	/* 0x63e2: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_63e5:
	/* 0x63e5: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_63ec:
	/* 0x63ec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_63ee:
	/* 0x63ee: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63f3:
	/* 0x63f3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_63f8:
	/* 0x63f8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_63fb:
	/* 0x63fb: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_63fe:
	/* 0x63fe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6400:
	/* 0x6400: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6402:
	/* 0x6402: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6407:
	/* 0x6407: jmp    6645 <generic_sleepable_preload+0x6645> */
	goto x86_l_6645;
x86_l_640c:
	/* 0x640c: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6411:
	/* 0x6411: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6413:
	/* 0x6413: mov    r14d,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6417:
	/* 0x6417: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_641c:
	/* 0x641c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6421:
	/* 0x6421: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6426:
	/* 0x6426: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_642b:
	/* 0x642b: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_642e:
	/* 0x642e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6430:
	/* 0x6430: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_6434:
	/* 0x6434: jne    11df <generic_sleepable_preload+0x11df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4575ULL;
	}
x86_l_643a:
	/* 0x643a: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_643f:
	/* 0x643f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6444:
	/* 0x6444: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6446:
	/* 0x6446: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_644b:
	/* 0x644b: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6453:
	/* 0x6453: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_645a:
	/* 0x645a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_645f:
	/* 0x645f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6464:
	/* 0x6464: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6466:
	/* 0x6466: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6469:
	/* 0x6469: je     11df <generic_sleepable_preload+0x11df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4575ULL;
	}
x86_l_646f:
	/* 0x646f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6472:
	/* 0x6472: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6479:
	/* 0x6479: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_647b:
	/* 0x647b: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6480:
	/* 0x6480: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6485:
	/* 0x6485: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6488:
	/* 0x6488: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_648b:
	/* 0x648b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_648d:
	/* 0x648d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_648f:
	/* 0x648f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6494:
	/* 0x6494: jmp    66fa <generic_sleepable_preload+0x66fa> */
	goto x86_l_66fa;
x86_l_6499:
	/* 0x6499: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_649e:
	/* 0x649e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_64a1:
	/* 0x64a1: mov    ebx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_64a5:
	/* 0x64a5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64aa:
	/* 0x64aa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_64af:
	/* 0x64af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_64b4:
	/* 0x64b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64b9:
	/* 0x64b9: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_64bc:
	/* 0x64bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64be:
	/* 0x64be: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_64c1:
	/* 0x64c1: jne    11ee <generic_sleepable_preload+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4590ULL;
	}
x86_l_64c7:
	/* 0x64c7: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64cc:
	/* 0x64cc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_64d1:
	/* 0x64d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64d3:
	/* 0x64d3: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64d8:
	/* 0x64d8: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_64e0:
	/* 0x64e0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_64e7:
	/* 0x64e7: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_64ec:
	/* 0x64ec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_64f1:
	/* 0x64f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64f3:
	/* 0x64f3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_64f6:
	/* 0x64f6: je     11ee <generic_sleepable_preload+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4590ULL;
	}
x86_l_64fc:
	/* 0x64fc: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_64ff:
	/* 0x64ff: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6506:
	/* 0x6506: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6508:
	/* 0x6508: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_650d:
	/* 0x650d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6512:
	/* 0x6512: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_6515:
	/* 0x6515: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6518:
	/* 0x6518: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_651a:
	/* 0x651a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_651c:
	/* 0x651c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6521:
	/* 0x6521: jmp    685a <generic_sleepable_preload+0x685a> */
	return 26714ULL;
x86_l_6526:
	/* 0x6526: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_652b:
	/* 0x652b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_652d:
	/* 0x652d: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_6531:
	/* 0x6531: jne    11ad <generic_sleepable_preload+0x11ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4525ULL;
	}
x86_l_6537:
	/* 0x6537: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_653c:
	/* 0x653c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6541:
	/* 0x6541: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6543:
	/* 0x6543: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6548:
	/* 0x6548: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6550:
	/* 0x6550: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6557:
	/* 0x6557: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_655c:
	/* 0x655c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6561:
	/* 0x6561: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6563:
	/* 0x6563: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6566:
	/* 0x6566: je     11ad <generic_sleepable_preload+0x11ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4525ULL;
	}
x86_l_656c:
	/* 0x656c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_656f:
	/* 0x656f: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6576:
	/* 0x6576: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6578:
	/* 0x6578: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_657d:
	/* 0x657d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6582:
	/* 0x6582: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6585:
	/* 0x6585: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6588:
	/* 0x6588: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_658a:
	/* 0x658a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_658c:
	/* 0x658c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6591:
	/* 0x6591: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6594:
	/* 0x6594: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6599:
	/* 0x6599: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_659c:
	/* 0x659c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_659e:
	/* 0x659e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_65a1:
	/* 0x65a1: je     11ad <generic_sleepable_preload+0x11ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4525ULL;
	}
x86_l_65a7:
	/* 0x65a7: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_65aa:
	/* 0x65aa: je     65d3 <generic_sleepable_preload+0x65d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_65d3;
	}
x86_l_65ac:
	/* 0x65ac: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_65af:
	/* 0x65af: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_65b3:
	/* 0x65b3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_65b8:
	/* 0x65b8: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_65bb:
	/* 0x65bb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65bd:
	/* 0x65bd: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_65c0:
	/* 0x65c0: call   65c5 <generic_sleepable_preload+0x65c5> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_65c5:
	/* 0x65c5: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_65c7:
	/* 0x65c7: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_65ca:
	/* 0x65ca: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_65cc:
	/* 0x65cc: jns    65d3 <generic_sleepable_preload+0x65d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_65d3;
	}
x86_l_65ce:
	/* 0x65ce: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_65d3:
	/* 0x65d3: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65d5:
	/* 0x65d5: jmp    11ad <generic_sleepable_preload+0x11ad> */
	return 4525ULL;
x86_l_65da:
	/* 0x65da: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_65df:
	/* 0x65df: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65e1:
	/* 0x65e1: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_65e5:
	/* 0x65e5: jne    11d0 <generic_sleepable_preload+0x11d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4560ULL;
	}
x86_l_65eb:
	/* 0x65eb: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_65f0:
	/* 0x65f0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_65f5:
	/* 0x65f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65f7:
	/* 0x65f7: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65fc:
	/* 0x65fc: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6604:
	/* 0x6604: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_660b:
	/* 0x660b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6610:
	/* 0x6610: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6615:
	/* 0x6615: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6617:
	/* 0x6617: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_661a:
	/* 0x661a: je     11d0 <generic_sleepable_preload+0x11d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4560ULL;
	}
x86_l_6620:
	/* 0x6620: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6623:
	/* 0x6623: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_662a:
	/* 0x662a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_662c:
	/* 0x662c: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6631:
	/* 0x6631: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6636:
	/* 0x6636: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6639:
	/* 0x6639: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_663c:
	/* 0x663c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_663e:
	/* 0x663e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6640:
	/* 0x6640: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6645:
	/* 0x6645: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6648:
	/* 0x6648: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_664d:
	/* 0x664d: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6650:
	/* 0x6650: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6652:
	/* 0x6652: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6655:
	/* 0x6655: je     11d0 <generic_sleepable_preload+0x11d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4560ULL;
	}
x86_l_665b:
	/* 0x665b: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_665e:
	/* 0x665e: je     6688 <generic_sleepable_preload+0x6688> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6688;
	}
x86_l_6660:
	/* 0x6660: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6663:
	/* 0x6663: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6667:
	/* 0x6667: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_666c:
	/* 0x666c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_666f:
	/* 0x666f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6671:
	/* 0x6671: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_6674:
	/* 0x6674: call   6679 <generic_sleepable_preload+0x6679> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_6679:
	/* 0x6679: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_667b:
	/* 0x667b: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_667e:
	/* 0x667e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_6680:
	/* 0x6680: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_6685:
	/* 0x6685: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_6688:
	/* 0x6688: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_668a:
	/* 0x668a: jmp    11d0 <generic_sleepable_preload+0x11d0> */
	return 4560ULL;
x86_l_668f:
	/* 0x668f: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6694:
	/* 0x6694: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6696:
	/* 0x6696: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_669a:
	/* 0x669a: jne    11df <generic_sleepable_preload+0x11df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4575ULL;
	}
x86_l_66a0:
	/* 0x66a0: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66a5:
	/* 0x66a5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_66aa:
	/* 0x66aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66ac:
	/* 0x66ac: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66b1:
	/* 0x66b1: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_66b9:
	/* 0x66b9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_66c0:
	/* 0x66c0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66c5:
	/* 0x66c5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_66ca:
	/* 0x66ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66cc:
	/* 0x66cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_66cf:
	/* 0x66cf: je     11df <generic_sleepable_preload+0x11df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4575ULL;
	}
x86_l_66d5:
	/* 0x66d5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_66d8:
	/* 0x66d8: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_66df:
	/* 0x66df: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66e1:
	/* 0x66e1: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66e6:
	/* 0x66e6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_66eb:
	/* 0x66eb: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_66ee:
	/* 0x66ee: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_66f1:
	/* 0x66f1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66f3:
	/* 0x66f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66f5:
	/* 0x66f5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_66fa:
	/* 0x66fa: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_66fd:
	/* 0x66fd: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6700:
	/* 0x6700: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6702:
	/* 0x6702: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6705:
	/* 0x6705: je     11df <generic_sleepable_preload+0x11df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4575ULL;
	}
x86_l_670b:
	/* 0x670b: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_670e:
	/* 0x670e: je     6738 <generic_sleepable_preload+0x6738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6738;
	}
x86_l_6710:
	/* 0x6710: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6713:
	/* 0x6713: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6717:
	/* 0x6717: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_671c:
	/* 0x671c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_671f:
	/* 0x671f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6721:
	/* 0x6721: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_6724:
	/* 0x6724: call   6729 <generic_sleepable_preload+0x6729> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_6729:
	/* 0x6729: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_672b:
	/* 0x672b: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_672e:
	/* 0x672e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_6730:
	/* 0x6730: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_6735:
	/* 0x6735: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_6738:
	/* 0x6738: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_673a:
	/* 0x673a: jmp    11df <generic_sleepable_preload+0x11df> */
	return 4575ULL;
x86_l_673f:
	/* 0x673f: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6744:
	/* 0x6744: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6746:
	/* 0x6746: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_674a:
	/* 0x674a: jne    11bc <generic_sleepable_preload+0x11bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4540ULL;
	}
x86_l_6750:
	/* 0x6750: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6755:
	/* 0x6755: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_675a:
	/* 0x675a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_675c:
	/* 0x675c: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6761:
	/* 0x6761: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
	return 26473ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 26473ULL: goto x86_l_6769;
	case 26480ULL: goto x86_l_6770;
	case 26485ULL: goto x86_l_6775;
	case 26490ULL: goto x86_l_677a;
	case 26492ULL: goto x86_l_677c;
	case 26495ULL: goto x86_l_677f;
	case 26501ULL: goto x86_l_6785;
	case 26504ULL: goto x86_l_6788;
	case 26511ULL: goto x86_l_678f;
	case 26513ULL: goto x86_l_6791;
	case 26518ULL: goto x86_l_6796;
	case 26523ULL: goto x86_l_679b;
	case 26526ULL: goto x86_l_679e;
	case 26529ULL: goto x86_l_67a1;
	case 26531ULL: goto x86_l_67a3;
	case 26533ULL: goto x86_l_67a5;
	case 26538ULL: goto x86_l_67aa;
	case 26541ULL: goto x86_l_67ad;
	case 26544ULL: goto x86_l_67b0;
	case 26546ULL: goto x86_l_67b2;
	case 26549ULL: goto x86_l_67b5;
	case 26555ULL: goto x86_l_67bb;
	case 26558ULL: goto x86_l_67be;
	case 26560ULL: goto x86_l_67c0;
	case 26563ULL: goto x86_l_67c3;
	case 26567ULL: goto x86_l_67c7;
	case 26572ULL: goto x86_l_67cc;
	case 26575ULL: goto x86_l_67cf;
	case 26577ULL: goto x86_l_67d1;
	case 26580ULL: goto x86_l_67d4;
	case 26585ULL: goto x86_l_67d9;
	case 26587ULL: goto x86_l_67db;
	case 26590ULL: goto x86_l_67de;
	case 26592ULL: goto x86_l_67e0;
	case 26597ULL: goto x86_l_67e5;
	case 26600ULL: goto x86_l_67e8;
	case 26602ULL: goto x86_l_67ea;
	case 26607ULL: goto x86_l_67ef;
	case 26612ULL: goto x86_l_67f4;
	case 26615ULL: goto x86_l_67f7;
	case 26618ULL: goto x86_l_67fa;
	case 26624ULL: goto x86_l_6800;
	case 26629ULL: goto x86_l_6805;
	case 26634ULL: goto x86_l_680a;
	case 26636ULL: goto x86_l_680c;
	case 26641ULL: goto x86_l_6811;
	case 26649ULL: goto x86_l_6819;
	case 26656ULL: goto x86_l_6820;
	case 26661ULL: goto x86_l_6825;
	case 26666ULL: goto x86_l_682a;
	case 26668ULL: goto x86_l_682c;
	case 26671ULL: goto x86_l_682f;
	case 26677ULL: goto x86_l_6835;
	case 26680ULL: goto x86_l_6838;
	case 26687ULL: goto x86_l_683f;
	case 26689ULL: goto x86_l_6841;
	case 26694ULL: goto x86_l_6846;
	case 26699ULL: goto x86_l_684b;
	case 26702ULL: goto x86_l_684e;
	case 26705ULL: goto x86_l_6851;
	case 26707ULL: goto x86_l_6853;
	case 26709ULL: goto x86_l_6855;
	case 26714ULL: goto x86_l_685a;
	case 26717ULL: goto x86_l_685d;
	case 26720ULL: goto x86_l_6860;
	case 26722ULL: goto x86_l_6862;
	case 26725ULL: goto x86_l_6865;
	case 26731ULL: goto x86_l_686b;
	case 26734ULL: goto x86_l_686e;
	case 26736ULL: goto x86_l_6870;
	case 26739ULL: goto x86_l_6873;
	case 26743ULL: goto x86_l_6877;
	case 26748ULL: goto x86_l_687c;
	case 26751ULL: goto x86_l_687f;
	case 26753ULL: goto x86_l_6881;
	case 26756ULL: goto x86_l_6884;
	case 26761ULL: goto x86_l_6889;
	case 26763ULL: goto x86_l_688b;
	case 26766ULL: goto x86_l_688e;
	case 26768ULL: goto x86_l_6890;
	case 26773ULL: goto x86_l_6895;
	case 26776ULL: goto x86_l_6898;
	case 26778ULL: goto x86_l_689a;
	case 26783ULL: goto x86_l_689f;
	case 26786ULL: goto x86_l_68a2;
	case 26791ULL: goto x86_l_68a7;
	case 26794ULL: goto x86_l_68aa;
	case 26800ULL: goto x86_l_68b0;
	case 26805ULL: goto x86_l_68b5;
	case 26807ULL: goto x86_l_68b7;
	case 26812ULL: goto x86_l_68bc;
	case 26817ULL: goto x86_l_68c1;
	case 26819ULL: goto x86_l_68c3;
	case 26824ULL: goto x86_l_68c8;
	case 26829ULL: goto x86_l_68cd;
	case 26831ULL: goto x86_l_68cf;
	case 26836ULL: goto x86_l_68d4;
	case 26841ULL: goto x86_l_68d9;
	case 26843ULL: goto x86_l_68db;
	case 26848ULL: goto x86_l_68e0;
	case 26853ULL: goto x86_l_68e5;
	case 26856ULL: goto x86_l_68e8;
	case 26861ULL: goto x86_l_68ed;
	case 26866ULL: goto x86_l_68f2;
	case 26868ULL: goto x86_l_68f4;
	case 26873ULL: goto x86_l_68f9;
	case 26878ULL: goto x86_l_68fe;
	case 26880ULL: goto x86_l_6900;
	case 26885ULL: goto x86_l_6905;
	case 26890ULL: goto x86_l_690a;
	case 26892ULL: goto x86_l_690c;
	case 26897ULL: goto x86_l_6911;
	case 26902ULL: goto x86_l_6916;
	case 26904ULL: goto x86_l_6918;
	case 26909ULL: goto x86_l_691d;
	case 26914ULL: goto x86_l_6922;
	case 26919ULL: goto x86_l_6927;
	case 26921ULL: goto x86_l_6929;
	case 26926ULL: goto x86_l_692e;
	case 26931ULL: goto x86_l_6933;
	case 26933ULL: goto x86_l_6935;
	case 26938ULL: goto x86_l_693a;
	case 26943ULL: goto x86_l_693f;
	case 26948ULL: goto x86_l_6944;
	case 26950ULL: goto x86_l_6946;
	case 26955ULL: goto x86_l_694b;
	case 26960ULL: goto x86_l_6950;
	case 26962ULL: goto x86_l_6952;
	case 26967ULL: goto x86_l_6957;
	case 26972ULL: goto x86_l_695c;
	case 26977ULL: goto x86_l_6961;
	case 26980ULL: goto x86_l_6964;
	case 26985ULL: goto x86_l_6969;
	case 26990ULL: goto x86_l_696e;
	case 26995ULL: goto x86_l_6973;
	case 26997ULL: goto x86_l_6975;
	case 27002ULL: goto x86_l_697a;
	case 27007ULL: goto x86_l_697f;
	case 27009ULL: goto x86_l_6981;
	case 27014ULL: goto x86_l_6986;
	case 27019ULL: goto x86_l_698b;
	case 27021ULL: goto x86_l_698d;
	case 27026ULL: goto x86_l_6992;
	case 27031ULL: goto x86_l_6997;
	case 27036ULL: goto x86_l_699c;
	case 27038ULL: goto x86_l_699e;
	case 27043ULL: goto x86_l_69a3;
	case 27048ULL: goto x86_l_69a8;
	case 27053ULL: goto x86_l_69ad;
	case 27058ULL: goto x86_l_69b2;
	case 27060ULL: goto x86_l_69b4;
	case 27065ULL: goto x86_l_69b9;
	case 27070ULL: goto x86_l_69be;
	case 27075ULL: goto x86_l_69c3;
	case 27080ULL: goto x86_l_69c8;
	case 27082ULL: goto x86_l_69ca;
	case 27087ULL: goto x86_l_69cf;
	case 27092ULL: goto x86_l_69d4;
	case 27097ULL: goto x86_l_69d9;
	case 27099ULL: goto x86_l_69db;
	case 27104ULL: goto x86_l_69e0;
	case 27109ULL: goto x86_l_69e5;
	case 27114ULL: goto x86_l_69ea;
	case 27119ULL: goto x86_l_69ef;
	case 27121ULL: goto x86_l_69f1;
	case 27126ULL: goto x86_l_69f6;
	case 27131ULL: goto x86_l_69fb;
	case 27136ULL: goto x86_l_6a00;
	case 27139ULL: goto x86_l_6a03;
	case 27144ULL: goto x86_l_6a08;
	case 27149ULL: goto x86_l_6a0d;
	case 27154ULL: goto x86_l_6a12;
	case 27156ULL: goto x86_l_6a14;
	case 27161ULL: goto x86_l_6a19;
	case 27166ULL: goto x86_l_6a1e;
	case 27171ULL: goto x86_l_6a23;
	case 27176ULL: goto x86_l_6a28;
	case 27178ULL: goto x86_l_6a2a;
	case 27183ULL: goto x86_l_6a2f;
	case 27188ULL: goto x86_l_6a34;
	case 27193ULL: goto x86_l_6a39;
	case 27198ULL: goto x86_l_6a3e;
	case 27200ULL: goto x86_l_6a40;
	case 27205ULL: goto x86_l_6a45;
	case 27210ULL: goto x86_l_6a4a;
	case 27215ULL: goto x86_l_6a4f;
	case 27217ULL: goto x86_l_6a51;
	case 27222ULL: goto x86_l_6a56;
	case 27227ULL: goto x86_l_6a5b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6769:
	/* 0x6769: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6770:
	/* 0x6770: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6775:
	/* 0x6775: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_677a:
	/* 0x677a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_677c:
	/* 0x677c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_677f:
	/* 0x677f: je     11bc <generic_sleepable_preload+0x11bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4540ULL;
	}
x86_l_6785:
	/* 0x6785: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6788:
	/* 0x6788: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_678f:
	/* 0x678f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6791:
	/* 0x6791: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6796:
	/* 0x6796: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_679b:
	/* 0x679b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_679e:
	/* 0x679e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_67a1:
	/* 0x67a1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67a3:
	/* 0x67a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67a5:
	/* 0x67a5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_67aa:
	/* 0x67aa: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_67ad:
	/* 0x67ad: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_67b0:
	/* 0x67b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67b2:
	/* 0x67b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_67b5:
	/* 0x67b5: je     11bc <generic_sleepable_preload+0x11bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4540ULL;
	}
x86_l_67bb:
	/* 0x67bb: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_67be:
	/* 0x67be: je     67e8 <generic_sleepable_preload+0x67e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_67e8;
	}
x86_l_67c0:
	/* 0x67c0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_67c3:
	/* 0x67c3: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_67c7:
	/* 0x67c7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_67cc:
	/* 0x67cc: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_67cf:
	/* 0x67cf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67d1:
	/* 0x67d1: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_67d4:
	/* 0x67d4: call   67d9 <generic_sleepable_preload+0x67d9> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_67d9:
	/* 0x67d9: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_67db:
	/* 0x67db: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_67de:
	/* 0x67de: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_67e0:
	/* 0x67e0: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_67e5:
	/* 0x67e5: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_67e8:
	/* 0x67e8: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67ea:
	/* 0x67ea: jmp    11bc <generic_sleepable_preload+0x11bc> */
	return 4540ULL;
x86_l_67ef:
	/* 0x67ef: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_67f4:
	/* 0x67f4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67f7:
	/* 0x67f7: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_67fa:
	/* 0x67fa: jne    11ee <generic_sleepable_preload+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4590ULL;
	}
x86_l_6800:
	/* 0x6800: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6805:
	/* 0x6805: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_680a:
	/* 0x680a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_680c:
	/* 0x680c: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6811:
	/* 0x6811: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6819:
	/* 0x6819: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6820:
	/* 0x6820: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6825:
	/* 0x6825: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_682a:
	/* 0x682a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_682c:
	/* 0x682c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_682f:
	/* 0x682f: je     11ee <generic_sleepable_preload+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4590ULL;
	}
x86_l_6835:
	/* 0x6835: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6838:
	/* 0x6838: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_683f:
	/* 0x683f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6841:
	/* 0x6841: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6846:
	/* 0x6846: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_684b:
	/* 0x684b: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_684e:
	/* 0x684e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6851:
	/* 0x6851: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6853:
	/* 0x6853: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6855:
	/* 0x6855: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_685a:
	/* 0x685a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_685d:
	/* 0x685d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6860:
	/* 0x6860: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6862:
	/* 0x6862: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6865:
	/* 0x6865: je     11ee <generic_sleepable_preload+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4590ULL;
	}
x86_l_686b:
	/* 0x686b: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_686e:
	/* 0x686e: je     6898 <generic_sleepable_preload+0x6898> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6898;
	}
x86_l_6870:
	/* 0x6870: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6873:
	/* 0x6873: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6877:
	/* 0x6877: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_687c:
	/* 0x687c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_687f:
	/* 0x687f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6881:
	/* 0x6881: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_6884:
	/* 0x6884: call   6889 <generic_sleepable_preload+0x6889> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_6889:
	/* 0x6889: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_688b:
	/* 0x688b: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_688e:
	/* 0x688e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_6890:
	/* 0x6890: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_6895:
	/* 0x6895: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_6898:
	/* 0x6898: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_689a:
	/* 0x689a: jmp    11ee <generic_sleepable_preload+0x11ee> */
	return 4590ULL;
x86_l_689f:
	/* 0x689f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68a2:
	/* 0x68a2: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_68a7:
	/* 0x68a7: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_68aa:
	/* 0x68aa: jne    11ee <generic_sleepable_preload+0x11ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4590ULL;
	}
x86_l_68b0:
	/* 0x68b0: jmp    6800 <generic_sleepable_preload+0x6800> */
	goto x86_l_6800;
x86_l_68b5:
	/* 0x68b5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68b7:
	/* 0x68b7: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68bc:
	/* 0x68bc: jmp    626c <generic_sleepable_preload+0x626c> */
	return 25196ULL;
x86_l_68c1:
	/* 0x68c1: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68c3:
	/* 0x68c3: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68c8:
	/* 0x68c8: jmp    62f9 <generic_sleepable_preload+0x62f9> */
	return 25337ULL;
x86_l_68cd:
	/* 0x68cd: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68cf:
	/* 0x68cf: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68d4:
	/* 0x68d4: jmp    6386 <generic_sleepable_preload+0x6386> */
	return 25478ULL;
x86_l_68d9:
	/* 0x68d9: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68db:
	/* 0x68db: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68e0:
	/* 0x68e0: jmp    6413 <generic_sleepable_preload+0x6413> */
	return 25619ULL;
x86_l_68e5:
	/* 0x68e5: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68e8:
	/* 0x68e8: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_68ed:
	/* 0x68ed: jmp    64a1 <generic_sleepable_preload+0x64a1> */
	return 25761ULL;
x86_l_68f2:
	/* 0x68f2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68f4:
	/* 0x68f4: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68f9:
	/* 0x68f9: jmp    652d <generic_sleepable_preload+0x652d> */
	return 25901ULL;
x86_l_68fe:
	/* 0x68fe: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6900:
	/* 0x6900: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6905:
	/* 0x6905: jmp    65e1 <generic_sleepable_preload+0x65e1> */
	return 26081ULL;
x86_l_690a:
	/* 0x690a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_690c:
	/* 0x690c: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6911:
	/* 0x6911: jmp    6696 <generic_sleepable_preload+0x6696> */
	return 26262ULL;
x86_l_6916:
	/* 0x6916: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6918:
	/* 0x6918: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_691d:
	/* 0x691d: jmp    6746 <generic_sleepable_preload+0x6746> */
	return 26438ULL;
x86_l_6922:
	/* 0x6922: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6927:
	/* 0x6927: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6929:
	/* 0x6929: jmp    69b9 <generic_sleepable_preload+0x69b9> */
	goto x86_l_69b9;
x86_l_692e:
	/* 0x692e: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6933:
	/* 0x6933: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6935:
	/* 0x6935: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_693a:
	/* 0x693a: jmp    62f9 <generic_sleepable_preload+0x62f9> */
	return 25337ULL;
x86_l_693f:
	/* 0x693f: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6944:
	/* 0x6944: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6946:
	/* 0x6946: jmp    69e0 <generic_sleepable_preload+0x69e0> */
	goto x86_l_69e0;
x86_l_694b:
	/* 0x694b: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6950:
	/* 0x6950: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6952:
	/* 0x6952: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6957:
	/* 0x6957: jmp    6413 <generic_sleepable_preload+0x6413> */
	return 25619ULL;
x86_l_695c:
	/* 0x695c: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6961:
	/* 0x6961: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6964:
	/* 0x6964: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6969:
	/* 0x6969: jmp    64a1 <generic_sleepable_preload+0x64a1> */
	return 25761ULL;
x86_l_696e:
	/* 0x696e: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6973:
	/* 0x6973: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6975:
	/* 0x6975: jmp    6a19 <generic_sleepable_preload+0x6a19> */
	goto x86_l_6a19;
x86_l_697a:
	/* 0x697a: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_697f:
	/* 0x697f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6981:
	/* 0x6981: jmp    6a2f <generic_sleepable_preload+0x6a2f> */
	goto x86_l_6a2f;
x86_l_6986:
	/* 0x6986: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_698b:
	/* 0x698b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_698d:
	/* 0x698d: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6992:
	/* 0x6992: jmp    6696 <generic_sleepable_preload+0x6696> */
	return 26262ULL;
x86_l_6997:
	/* 0x6997: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_699c:
	/* 0x699c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_699e:
	/* 0x699e: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69a3:
	/* 0x69a3: jmp    6746 <generic_sleepable_preload+0x6746> */
	return 26438ULL;
x86_l_69a8:
	/* 0x69a8: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_69ad:
	/* 0x69ad: jmp    67f4 <generic_sleepable_preload+0x67f4> */
	goto x86_l_67f4;
x86_l_69b2:
	/* 0x69b2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69b4:
	/* 0x69b4: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_69b9:
	/* 0x69b9: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69be:
	/* 0x69be: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_69c3:
	/* 0x69c3: jmp    626c <generic_sleepable_preload+0x626c> */
	return 25196ULL;
x86_l_69c8:
	/* 0x69c8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69ca:
	/* 0x69ca: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_69cf:
	/* 0x69cf: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69d4:
	/* 0x69d4: jmp    62f9 <generic_sleepable_preload+0x62f9> */
	return 25337ULL;
x86_l_69d9:
	/* 0x69d9: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69db:
	/* 0x69db: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_69e0:
	/* 0x69e0: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69e5:
	/* 0x69e5: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_69ea:
	/* 0x69ea: jmp    6386 <generic_sleepable_preload+0x6386> */
	return 25478ULL;
x86_l_69ef:
	/* 0x69ef: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69f1:
	/* 0x69f1: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_69f6:
	/* 0x69f6: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69fb:
	/* 0x69fb: jmp    6413 <generic_sleepable_preload+0x6413> */
	return 25619ULL;
x86_l_6a00:
	/* 0x6a00: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a03:
	/* 0x6a03: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_6a08:
	/* 0x6a08: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a0d:
	/* 0x6a0d: jmp    64a1 <generic_sleepable_preload+0x64a1> */
	return 25761ULL;
x86_l_6a12:
	/* 0x6a12: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a14:
	/* 0x6a14: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a19:
	/* 0x6a19: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a1e:
	/* 0x6a1e: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6a23:
	/* 0x6a23: jmp    652d <generic_sleepable_preload+0x652d> */
	return 25901ULL;
x86_l_6a28:
	/* 0x6a28: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a2a:
	/* 0x6a2a: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a2f:
	/* 0x6a2f: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a34:
	/* 0x6a34: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6a39:
	/* 0x6a39: jmp    65e1 <generic_sleepable_preload+0x65e1> */
	return 26081ULL;
x86_l_6a3e:
	/* 0x6a3e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a40:
	/* 0x6a40: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a45:
	/* 0x6a45: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a4a:
	/* 0x6a4a: jmp    6696 <generic_sleepable_preload+0x6696> */
	return 26262ULL;
x86_l_6a4f:
	/* 0x6a4f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a51:
	/* 0x6a51: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a56:
	/* 0x6a56: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a5b:
	/* 0x6a5b: jmp    6746 <generic_sleepable_preload+0x6746> */
	return 26438ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 22260U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1789ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1794ULL && __x86_pc <= 3584ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3589ULL && __x86_pc <= 5358ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5364ULL && __x86_pc <= 7257ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7265ULL && __x86_pc <= 9180ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9186ULL && __x86_pc <= 11140ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11146ULL && __x86_pc <= 13109ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 13114ULL && __x86_pc <= 15077ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 15079ULL && __x86_pc <= 17010ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 17015ULL && __x86_pc <= 18958ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 18960ULL && __x86_pc <= 20921ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 20926ULL && __x86_pc <= 22885ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 22890ULL && __x86_pc <= 24837ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 24842ULL && __x86_pc <= 26465ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 26473ULL && __x86_pc <= 27227ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_14(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

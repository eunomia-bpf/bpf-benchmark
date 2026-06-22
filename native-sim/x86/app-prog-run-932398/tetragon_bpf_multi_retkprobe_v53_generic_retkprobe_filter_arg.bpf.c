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
extern char string_maps_2;
extern char string_maps_3;
extern char string_maps_4;
extern char string_maps_5;
extern char string_maps_6;
extern char string_maps_7;
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

static __noinline __u64 tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_0(
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
	case 64ULL: goto x86_l_40;
	case 71ULL: goto x86_l_47;
	case 76ULL: goto x86_l_4c;
	case 83ULL: goto x86_l_53;
	case 85ULL: goto x86_l_55;
	case 88ULL: goto x86_l_58;
	case 94ULL: goto x86_l_5e;
	case 102ULL: goto x86_l_66;
	case 108ULL: goto x86_l_6c;
	case 111ULL: goto x86_l_6f;
	case 113ULL: goto x86_l_71;
	case 116ULL: goto x86_l_74;
	case 125ULL: goto x86_l_7d;
	case 127ULL: goto x86_l_7f;
	case 129ULL: goto x86_l_81;
	case 133ULL: goto x86_l_85;
	case 137ULL: goto x86_l_89;
	case 141ULL: goto x86_l_8d;
	case 144ULL: goto x86_l_90;
	case 151ULL: goto x86_l_97;
	case 156ULL: goto x86_l_9c;
	case 158ULL: goto x86_l_9e;
	case 162ULL: goto x86_l_a2;
	case 168ULL: goto x86_l_a8;
	case 171ULL: goto x86_l_ab;
	case 177ULL: goto x86_l_b1;
	case 180ULL: goto x86_l_b4;
	case 182ULL: goto x86_l_b6;
	case 185ULL: goto x86_l_b9;
	case 191ULL: goto x86_l_bf;
	case 193ULL: goto x86_l_c1;
	case 199ULL: goto x86_l_c7;
	case 202ULL: goto x86_l_ca;
	case 208ULL: goto x86_l_d0;
	case 210ULL: goto x86_l_d2;
	case 213ULL: goto x86_l_d5;
	case 219ULL: goto x86_l_db;
	case 222ULL: goto x86_l_de;
	case 228ULL: goto x86_l_e4;
	case 231ULL: goto x86_l_e7;
	case 237ULL: goto x86_l_ed;
	case 240ULL: goto x86_l_f0;
	case 246ULL: goto x86_l_f6;
	case 248ULL: goto x86_l_f8;
	case 253ULL: goto x86_l_fd;
	case 257ULL: goto x86_l_101;
	case 265ULL: goto x86_l_109;
	case 268ULL: goto x86_l_10c;
	case 276ULL: goto x86_l_114;
	case 281ULL: goto x86_l_119;
	case 286ULL: goto x86_l_11e;
	case 294ULL: goto x86_l_126;
	case 299ULL: goto x86_l_12b;
	case 304ULL: goto x86_l_130;
	case 309ULL: goto x86_l_135;
	case 314ULL: goto x86_l_13a;
	case 321ULL: goto x86_l_141;
	case 326ULL: goto x86_l_146;
	case 333ULL: goto x86_l_14d;
	case 336ULL: goto x86_l_150;
	case 341ULL: goto x86_l_155;
	case 343ULL: goto x86_l_157;
	case 348ULL: goto x86_l_15c;
	case 355ULL: goto x86_l_163;
	case 358ULL: goto x86_l_166;
	case 363ULL: goto x86_l_16b;
	case 365ULL: goto x86_l_16d;
	case 367ULL: goto x86_l_16f;
	case 374ULL: goto x86_l_176;
	case 376ULL: goto x86_l_178;
	case 377ULL: goto x86_l_179;
	case 382ULL: goto x86_l_17e;
	case 384ULL: goto x86_l_180;
	case 392ULL: goto x86_l_188;
	case 394ULL: goto x86_l_18a;
	case 399ULL: goto x86_l_18f;
	case 407ULL: goto x86_l_197;
	case 409ULL: goto x86_l_199;
	case 414ULL: goto x86_l_19e;
	case 422ULL: goto x86_l_1a6;
	case 424ULL: goto x86_l_1a8;
	case 429ULL: goto x86_l_1ad;
	case 437ULL: goto x86_l_1b5;
	case 439ULL: goto x86_l_1b7;
	case 444ULL: goto x86_l_1bc;
	case 452ULL: goto x86_l_1c4;
	case 454ULL: goto x86_l_1c6;
	case 459ULL: goto x86_l_1cb;
	case 467ULL: goto x86_l_1d3;
	case 469ULL: goto x86_l_1d5;
	case 476ULL: goto x86_l_1dc;
	case 481ULL: goto x86_l_1e1;
	case 488ULL: goto x86_l_1e8;
	case 491ULL: goto x86_l_1eb;
	case 496ULL: goto x86_l_1f0;
	case 498ULL: goto x86_l_1f2;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 509ULL: goto x86_l_1fd;
	case 514ULL: goto x86_l_202;
	case 519ULL: goto x86_l_207;
	case 524ULL: goto x86_l_20c;
	case 531ULL: goto x86_l_213;
	case 536ULL: goto x86_l_218;
	case 538ULL: goto x86_l_21a;
	case 541ULL: goto x86_l_21d;
	case 547ULL: goto x86_l_223;
	case 552ULL: goto x86_l_228;
	case 559ULL: goto x86_l_22f;
	case 564ULL: goto x86_l_234;
	case 566ULL: goto x86_l_236;
	case 571ULL: goto x86_l_23b;
	case 573ULL: goto x86_l_23d;
	case 578ULL: goto x86_l_242;
	case 583ULL: goto x86_l_247;
	case 588ULL: goto x86_l_24c;
	case 593ULL: goto x86_l_251;
	case 596ULL: goto x86_l_254;
	case 604ULL: goto x86_l_25c;
	case 610ULL: goto x86_l_262;
	case 613ULL: goto x86_l_265;
	case 617ULL: goto x86_l_269;
	case 623ULL: goto x86_l_26f;
	case 631ULL: goto x86_l_277;
	case 636ULL: goto x86_l_27c;
	case 643ULL: goto x86_l_283;
	case 649ULL: goto x86_l_289;
	case 652ULL: goto x86_l_28c;
	case 659ULL: goto x86_l_293;
	case 664ULL: goto x86_l_298;
	case 667ULL: goto x86_l_29b;
	case 673ULL: goto x86_l_2a1;
	case 676ULL: goto x86_l_2a4;
	case 679ULL: goto x86_l_2a7;
	case 683ULL: goto x86_l_2ab;
	case 689ULL: goto x86_l_2b1;
	case 698ULL: goto x86_l_2ba;
	case 704ULL: goto x86_l_2c0;
	case 712ULL: goto x86_l_2c8;
	case 718ULL: goto x86_l_2ce;
	case 722ULL: goto x86_l_2d2;
	case 729ULL: goto x86_l_2d9;
	case 733ULL: goto x86_l_2dd;
	case 736ULL: goto x86_l_2e0;
	case 738ULL: goto x86_l_2e2;
	case 741ULL: goto x86_l_2e5;
	case 744ULL: goto x86_l_2e8;
	case 750ULL: goto x86_l_2ee;
	case 753ULL: goto x86_l_2f1;
	case 755ULL: goto x86_l_2f3;
	case 757ULL: goto x86_l_2f5;
	case 767ULL: goto x86_l_2ff;
	case 771ULL: goto x86_l_303;
	case 773ULL: goto x86_l_305;
	case 783ULL: goto x86_l_30f;
	case 787ULL: goto x86_l_313;
	case 793ULL: goto x86_l_319;
	case 803ULL: goto x86_l_323;
	case 807ULL: goto x86_l_327;
	case 813ULL: goto x86_l_32d;
	case 816ULL: goto x86_l_330;
	case 822ULL: goto x86_l_336;
	case 826ULL: goto x86_l_33a;
	case 828ULL: goto x86_l_33c;
	case 831ULL: goto x86_l_33f;
	case 833ULL: goto x86_l_341;
	case 836ULL: goto x86_l_344;
	case 842ULL: goto x86_l_34a;
	case 845ULL: goto x86_l_34d;
	case 851ULL: goto x86_l_353;
	case 854ULL: goto x86_l_356;
	case 860ULL: goto x86_l_35c;
	case 863ULL: goto x86_l_35f;
	case 869ULL: goto x86_l_365;
	case 872ULL: goto x86_l_368;
	case 875ULL: goto x86_l_36b;
	case 879ULL: goto x86_l_36f;
	case 882ULL: goto x86_l_372;
	case 888ULL: goto x86_l_378;
	case 891ULL: goto x86_l_37b;
	case 894ULL: goto x86_l_37e;
	case 900ULL: goto x86_l_384;
	case 903ULL: goto x86_l_387;
	case 909ULL: goto x86_l_38d;
	case 914ULL: goto x86_l_392;
	case 917ULL: goto x86_l_395;
	case 923ULL: goto x86_l_39b;
	case 928ULL: goto x86_l_3a0;
	case 931ULL: goto x86_l_3a3;
	case 934ULL: goto x86_l_3a6;
	case 940ULL: goto x86_l_3ac;
	case 943ULL: goto x86_l_3af;
	case 946ULL: goto x86_l_3b2;
	case 952ULL: goto x86_l_3b8;
	case 957ULL: goto x86_l_3bd;
	case 960ULL: goto x86_l_3c0;
	case 962ULL: goto x86_l_3c2;
	case 965ULL: goto x86_l_3c5;
	case 968ULL: goto x86_l_3c8;
	case 970ULL: goto x86_l_3ca;
	case 972ULL: goto x86_l_3cc;
	case 978ULL: goto x86_l_3d2;
	case 981ULL: goto x86_l_3d5;
	case 986ULL: goto x86_l_3da;
	case 992ULL: goto x86_l_3e0;
	case 994ULL: goto x86_l_3e2;
	case 999ULL: goto x86_l_3e7;
	case 1003ULL: goto x86_l_3eb;
	case 1009ULL: goto x86_l_3f1;
	case 1014ULL: goto x86_l_3f6;
	case 1018ULL: goto x86_l_3fa;
	case 1024ULL: goto x86_l_400;
	case 1034ULL: goto x86_l_40a;
	case 1038ULL: goto x86_l_40e;
	case 1044ULL: goto x86_l_414;
	case 1051ULL: goto x86_l_41b;
	case 1057ULL: goto x86_l_421;
	case 1063ULL: goto x86_l_427;
	case 1068ULL: goto x86_l_42c;
	case 1070ULL: goto x86_l_42e;
	case 1074ULL: goto x86_l_432;
	case 1078ULL: goto x86_l_436;
	case 1083ULL: goto x86_l_43b;
	case 1088ULL: goto x86_l_440;
	case 1090ULL: goto x86_l_442;
	case 1094ULL: goto x86_l_446;
	case 1096ULL: goto x86_l_448;
	case 1102ULL: goto x86_l_44e;
	case 1107ULL: goto x86_l_453;
	case 1112ULL: goto x86_l_458;
	case 1117ULL: goto x86_l_45d;
	case 1119ULL: goto x86_l_45f;
	case 1125ULL: goto x86_l_465;
	case 1129ULL: goto x86_l_469;
	case 1132ULL: goto x86_l_46c;
	case 1137ULL: goto x86_l_471;
	case 1142ULL: goto x86_l_476;
	case 1147ULL: goto x86_l_47b;
	case 1153ULL: goto x86_l_481;
	case 1157ULL: goto x86_l_485;
	case 1159ULL: goto x86_l_487;
	case 1165ULL: goto x86_l_48d;
	case 1167ULL: goto x86_l_48f;
	case 1173ULL: goto x86_l_495;
	case 1176ULL: goto x86_l_498;
	case 1182ULL: goto x86_l_49e;
	case 1186ULL: goto x86_l_4a2;
	case 1188ULL: goto x86_l_4a4;
	case 1194ULL: goto x86_l_4aa;
	case 1196ULL: goto x86_l_4ac;
	case 1202ULL: goto x86_l_4b2;
	case 1205ULL: goto x86_l_4b5;
	case 1211ULL: goto x86_l_4bb;
	case 1215ULL: goto x86_l_4bf;
	case 1217ULL: goto x86_l_4c1;
	case 1223ULL: goto x86_l_4c7;
	case 1225ULL: goto x86_l_4c9;
	case 1227ULL: goto x86_l_4cb;
	case 1230ULL: goto x86_l_4ce;
	case 1235ULL: goto x86_l_4d3;
	case 1238ULL: goto x86_l_4d6;
	case 1240ULL: goto x86_l_4d8;
	case 1243ULL: goto x86_l_4db;
	case 1249ULL: goto x86_l_4e1;
	case 1252ULL: goto x86_l_4e4;
	case 1255ULL: goto x86_l_4e7;
	case 1259ULL: goto x86_l_4eb;
	case 1262ULL: goto x86_l_4ee;
	case 1268ULL: goto x86_l_4f4;
	case 1271ULL: goto x86_l_4f7;
	case 1274ULL: goto x86_l_4fa;
	case 1280ULL: goto x86_l_500;
	case 1285ULL: goto x86_l_505;
	case 1288ULL: goto x86_l_508;
	case 1294ULL: goto x86_l_50e;
	case 1299ULL: goto x86_l_513;
	case 1302ULL: goto x86_l_516;
	case 1308ULL: goto x86_l_51c;
	case 1313ULL: goto x86_l_521;
	case 1316ULL: goto x86_l_524;
	case 1322ULL: goto x86_l_52a;
	case 1325ULL: goto x86_l_52d;
	case 1331ULL: goto x86_l_533;
	case 1333ULL: goto x86_l_535;
	case 1343ULL: goto x86_l_53f;
	case 1347ULL: goto x86_l_543;
	case 1353ULL: goto x86_l_549;
	case 1358ULL: goto x86_l_54e;
	case 1362ULL: goto x86_l_552;
	case 1368ULL: goto x86_l_558;
	case 1378ULL: goto x86_l_562;
	case 1382ULL: goto x86_l_566;
	case 1388ULL: goto x86_l_56c;
	case 1391ULL: goto x86_l_56f;
	case 1397ULL: goto x86_l_575;
	case 1399ULL: goto x86_l_577;
	case 1404ULL: goto x86_l_57c;
	case 1408ULL: goto x86_l_580;
	case 1414ULL: goto x86_l_586;
	case 1418ULL: goto x86_l_58a;
	case 1421ULL: goto x86_l_58d;
	case 1427ULL: goto x86_l_593;
	case 1430ULL: goto x86_l_596;
	case 1433ULL: goto x86_l_599;
	case 1439ULL: goto x86_l_59f;
	case 1442ULL: goto x86_l_5a2;
	case 1446ULL: goto x86_l_5a6;
	case 1448ULL: goto x86_l_5a8;
	case 1454ULL: goto x86_l_5ae;
	case 1459ULL: goto x86_l_5b3;
	case 1462ULL: goto x86_l_5b6;
	case 1465ULL: goto x86_l_5b9;
	case 1471ULL: goto x86_l_5bf;
	case 1474ULL: goto x86_l_5c2;
	case 1476ULL: goto x86_l_5c4;
	case 1479ULL: goto x86_l_5c7;
	case 1481ULL: goto x86_l_5c9;
	case 1486ULL: goto x86_l_5ce;
	case 1489ULL: goto x86_l_5d1;
	case 1495ULL: goto x86_l_5d7;
	case 1498ULL: goto x86_l_5da;
	case 1504ULL: goto x86_l_5e0;
	case 1507ULL: goto x86_l_5e3;
	case 1510ULL: goto x86_l_5e6;
	case 1516ULL: goto x86_l_5ec;
	case 1519ULL: goto x86_l_5ef;
	case 1525ULL: goto x86_l_5f5;
	case 1530ULL: goto x86_l_5fa;
	case 1533ULL: goto x86_l_5fd;
	case 1536ULL: goto x86_l_600;
	case 1542ULL: goto x86_l_606;
	case 1545ULL: goto x86_l_609;
	case 1551ULL: goto x86_l_60f;
	case 1553ULL: goto x86_l_611;
	case 1558ULL: goto x86_l_616;
	case 1562ULL: goto x86_l_61a;
	case 1564ULL: goto x86_l_61c;
	case 1568ULL: goto x86_l_620;
	case 1571ULL: goto x86_l_623;
	case 1577ULL: goto x86_l_629;
	case 1580ULL: goto x86_l_62c;
	case 1583ULL: goto x86_l_62f;
	case 1589ULL: goto x86_l_635;
	case 1592ULL: goto x86_l_638;
	case 1598ULL: goto x86_l_63e;
	case 1603ULL: goto x86_l_643;
	case 1608ULL: goto x86_l_648;
	case 1612ULL: goto x86_l_64c;
	case 1618ULL: goto x86_l_652;
	case 1628ULL: goto x86_l_65c;
	case 1632ULL: goto x86_l_660;
	case 1638ULL: goto x86_l_666;
	case 1641ULL: goto x86_l_669;
	case 1647ULL: goto x86_l_66f;
	case 1651ULL: goto x86_l_673;
	case 1655ULL: goto x86_l_677;
	case 1658ULL: goto x86_l_67a;
	case 1664ULL: goto x86_l_680;
	case 1669ULL: goto x86_l_685;
	case 1672ULL: goto x86_l_688;
	case 1678ULL: goto x86_l_68e;
	case 1681ULL: goto x86_l_691;
	case 1683ULL: goto x86_l_693;
	case 1689ULL: goto x86_l_699;
	case 1691ULL: goto x86_l_69b;
	case 1697ULL: goto x86_l_6a1;
	case 1702ULL: goto x86_l_6a6;
	case 1705ULL: goto x86_l_6a9;
	case 1711ULL: goto x86_l_6af;
	case 1714ULL: goto x86_l_6b2;
	case 1720ULL: goto x86_l_6b8;
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
	/* 0xa: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     16d <generic_retkprobe_filter_arg+0x16d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16d;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    ebx,DWORD PTR [rax+0x5f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_40:
	/* 0x40: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_47:
	/* 0x47: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c:
	/* 0x4c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_53:
	/* 0x53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55:
	/* 0x55: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_58:
	/* 0x58: je     157 <generic_retkprobe_filter_arg+0x157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_157;
	}
x86_l_5e:
	/* 0x5e: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_66:
	/* 0x66: je     157 <generic_retkprobe_filter_arg+0x157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_157;
	}
x86_l_6c:
	/* 0x6c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6f:
	/* 0x6f: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_71:
	/* 0x71: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_74:
	/* 0x74: cmp    BYTE PTR [r14+rax*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699072ULL);
x86_l_7d:
	/* 0x7d: je     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b1;
	}
x86_l_7f:
	/* 0x7f: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_81:
	/* 0x81: mov    ecx,DWORD PTR [rdi+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_85:
	/* 0x85: lea    r11,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_89:
	/* 0x89: add    r11,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_8d:
	/* 0x8d: mov    r9d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R11, X86_WIDTH_32);
x86_l_90:
	/* 0x90: and    r9d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_97:
	/* 0x97: cmp    DWORD PTR [rdi+r9*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 25ULL);
x86_l_9c:
	/* 0x9c: jae    fd <generic_retkprobe_filter_arg+0xfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_fd;
	}
x86_l_9e:
	/* 0x9e: cmp    r9,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 1ULL);
x86_l_a2:
	/* 0xa2: je     157 <generic_retkprobe_filter_arg+0x157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_157;
	}
x86_l_a8:
	/* 0xa8: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_ab:
	/* 0xab: jne    13a <generic_retkprobe_filter_arg+0x13a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13a;
	}
x86_l_b1:
	/* 0xb1: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_b4:
	/* 0xb4: jg     d2 <generic_retkprobe_filter_arg+0xd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d2;
	}
x86_l_b6:
	/* 0xb6: cmp    ebx,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_b9:
	/* 0xb9: je     17e <generic_retkprobe_filter_arg+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17e;
	}
x86_l_bf:
	/* 0xbf: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_c1:
	/* 0xc1: je     18a <generic_retkprobe_filter_arg+0x18a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18a;
	}
x86_l_c7:
	/* 0xc7: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_ca:
	/* 0xca: je     199 <generic_retkprobe_filter_arg+0x199> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_199;
	}
x86_l_d0:
	/* 0xd0: jmp    ed <generic_retkprobe_filter_arg+0xed> */
	goto x86_l_ed;
x86_l_d2:
	/* 0xd2: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_d5:
	/* 0xd5: je     1a8 <generic_retkprobe_filter_arg+0x1a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a8;
	}
x86_l_db:
	/* 0xdb: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_de:
	/* 0xde: je     1b7 <generic_retkprobe_filter_arg+0x1b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b7;
	}
x86_l_e4:
	/* 0xe4: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_e7:
	/* 0xe7: je     1c6 <generic_retkprobe_filter_arg+0x1c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c6;
	}
x86_l_ed:
	/* 0xed: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_f0:
	/* 0xf0: jg     1f2 <generic_retkprobe_filter_arg+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f2;
	}
x86_l_f6:
	/* 0xf6: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f8:
	/* 0xf8: jmp    1d5 <generic_retkprobe_filter_arg+0x1d5> */
	goto x86_l_1d5;
x86_l_fd:
	/* 0xfd: lea    rax,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_101:
	/* 0x101: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_109:
	/* 0x109: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10c:
	/* 0x10c: lea    rax,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_114:
	/* 0x114: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_119:
	/* 0x119: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11e:
	/* 0x11e: mov    QWORD PTR [rsp+0xa8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_126:
	/* 0x126: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12b:
	/* 0x12b: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_130:
	/* 0x130: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_135:
	/* 0x135: jmp    26f <generic_retkprobe_filter_arg+0x26f> */
	goto x86_l_26f;
x86_l_13a:
	/* 0x13a: mov    DWORD PTR [r14+0x5f04],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_141:
	/* 0x141: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_146:
	/* 0x146: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_14d:
	/* 0x14d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_150:
	/* 0x150: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_155:
	/* 0x155: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157:
	/* 0x157: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_15c:
	/* 0x15c: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_163:
	/* 0x163: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_166:
	/* 0x166: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_16b:
	/* 0x16b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d:
	/* 0x16d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16f:
	/* 0x16f: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_176:
	/* 0x176: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_178:
	/* 0x178: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_179:
	/* 0x179: jmp    2fd8 <native_bpf_strncasestr+0x72> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_17e:
	/* 0x17e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_180:
	/* 0x180: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_188:
	/* 0x188: jne    1d5 <generic_retkprobe_filter_arg+0x1d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d5;
	}
x86_l_18a:
	/* 0x18a: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_18f:
	/* 0x18f: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_197:
	/* 0x197: jne    1d5 <generic_retkprobe_filter_arg+0x1d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d5;
	}
x86_l_199:
	/* 0x199: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_19e:
	/* 0x19e: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_1a6:
	/* 0x1a6: jne    1d5 <generic_retkprobe_filter_arg+0x1d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d5;
	}
x86_l_1a8:
	/* 0x1a8: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_1ad:
	/* 0x1ad: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_1b5:
	/* 0x1b5: jne    1d5 <generic_retkprobe_filter_arg+0x1d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d5;
	}
x86_l_1b7:
	/* 0x1b7: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1bc:
	/* 0x1bc: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_1c4:
	/* 0x1c4: jne    1d5 <generic_retkprobe_filter_arg+0x1d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d5;
	}
x86_l_1c6:
	/* 0x1c6: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1cb:
	/* 0x1cb: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_1d3:
	/* 0x1d3: je     1f2 <generic_retkprobe_filter_arg+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f2;
	}
x86_l_1d5:
	/* 0x1d5: mov    DWORD PTR [r14+0x5f00],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_1dc:
	/* 0x1dc: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1e1:
	/* 0x1e1: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_1e8:
	/* 0x1e8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1eb:
	/* 0x1eb: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1f0:
	/* 0x1f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f2:
	/* 0x1f2: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f6:
	/* 0x1f6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1fb:
	/* 0x1fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd:
	/* 0x1fd: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_202:
	/* 0x202: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_207:
	/* 0x207: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20c:
	/* 0x20c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_213:
	/* 0x213: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_218:
	/* 0x218: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a:
	/* 0x21a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21d:
	/* 0x21d: je     16d <generic_retkprobe_filter_arg+0x16d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16d;
	}
x86_l_223:
	/* 0x223: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_228:
	/* 0x228: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_22f:
	/* 0x22f: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_234:
	/* 0x234: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_236:
	/* 0x236: jmp    16d <generic_retkprobe_filter_arg+0x16d> */
	goto x86_l_16d;
x86_l_23b:
	/* 0x23b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23d:
	/* 0x23d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_242:
	/* 0x242: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_247:
	/* 0x247: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24c:
	/* 0x24c: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_251:
	/* 0x251: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_254:
	/* 0x254: mov    rbx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_25c:
	/* 0x25c: je     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b1;
	}
x86_l_262:
	/* 0x262: inc    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_265:
	/* 0x265: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_269:
	/* 0x269: je     9e <generic_retkprobe_filter_arg+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9e;
	}
x86_l_26f:
	/* 0x26f: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_277:
	/* 0x277: mov    r15d,DWORD PTR [rax+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_27c:
	/* 0x27c: test   r15d,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_32, 1023ULL);
x86_l_283:
	/* 0x283: je     9e <generic_retkprobe_filter_arg+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9e;
	}
x86_l_289:
	/* 0x289: add    r15d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_28c:
	/* 0x28c: and    r15d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_293:
	/* 0x293: mov    eax,DWORD PTR [rdi+r15*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_298:
	/* 0x298: cmp    eax,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_29b:
	/* 0x29b: je     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b1;
	}
x86_l_2a1:
	/* 0x2a1: add    r15,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a4:
	/* 0x2a4: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a7:
	/* 0x2a7: cmp    rcx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4ULL);
x86_l_2ab:
	/* 0x2ab: ja     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b1;
	}
x86_l_2b1:
	/* 0x2b1: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_2ba:
	/* 0x2ba: jne    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b1;
	}
x86_l_2c0:
	/* 0x2c0: mov    rcx,QWORD PTR [r14+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_2c8:
	/* 0x2c8: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2ce:
	/* 0x2ce: lea    rbp,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2d2:
	/* 0x2d2: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2d9:
	/* 0x2d9: mov    ecx,DWORD PTR [r15+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2dd:
	/* 0x2dd: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2e0:
	/* 0x2e0: jle    33c <generic_retkprobe_filter_arg+0x33c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_33c;
	}
x86_l_2e2:
	/* 0x2e2: lea    edx,[rcx-0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551588ULL);
x86_l_2e5:
	/* 0x2e5: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_2e8:
	/* 0x2e8: jb     521 <generic_retkprobe_filter_arg+0x521> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_521;
	}
x86_l_2ee:
	/* 0x2ee: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_2f1:
	/* 0x2f1: ja     32d <generic_retkprobe_filter_arg+0x32d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_32d;
	}
x86_l_2f3:
	/* 0x2f3: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2f5:
	/* 0x2f5: movabs rsi,0xc000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 824633720832ULL);
x86_l_2ff:
	/* 0x2ff: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_303:
	/* 0x303: jb     365 <generic_retkprobe_filter_arg+0x365> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_365;
	}
x86_l_305:
	/* 0x305: movabs rsi,0x30000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 3298534883328ULL);
x86_l_30f:
	/* 0x30f: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_313:
	/* 0x313: jb     894 <generic_retkprobe_filter_arg+0x894> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2196ULL;
	}
x86_l_319:
	/* 0x319: movabs rsi,0x42000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 4535485464576ULL);
x86_l_323:
	/* 0x323: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_327:
	/* 0x327: jb     3b8 <generic_retkprobe_filter_arg+0x3b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3b8;
	}
x86_l_32d:
	/* 0x32d: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_330:
	/* 0x330: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_262;
	}
x86_l_336:
	/* 0x336: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_33a:
	/* 0x33a: jmp    3b8 <generic_retkprobe_filter_arg+0x3b8> */
	goto x86_l_3b8;
x86_l_33c:
	/* 0x33c: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_33f:
	/* 0x33f: jg     3a0 <generic_retkprobe_filter_arg+0x3a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3a0;
	}
x86_l_341:
	/* 0x341: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_344:
	/* 0x344: jle    4d3 <generic_retkprobe_filter_arg+0x4d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4d3;
	}
x86_l_34a:
	/* 0x34a: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_34d:
	/* 0x34d: je     521 <generic_retkprobe_filter_arg+0x521> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_521;
	}
x86_l_353:
	/* 0x353: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_356:
	/* 0x356: je     894 <generic_retkprobe_filter_arg+0x894> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2196ULL;
	}
x86_l_35c:
	/* 0x35c: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_35f:
	/* 0x35f: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_262;
	}
x86_l_365:
	/* 0x365: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_368:
	/* 0x368: mov    ebp,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36b:
	/* 0x36b: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_36f:
	/* 0x36f: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_372:
	/* 0x372: jg     6a6 <generic_retkprobe_filter_arg+0x6a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6a6;
	}
x86_l_378:
	/* 0x378: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_37b:
	/* 0x37b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_37e:
	/* 0x37e: jb     f4d <generic_retkprobe_filter_arg+0xf4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3917ULL;
	}
x86_l_384:
	/* 0x384: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_387:
	/* 0x387: je     ea6 <generic_retkprobe_filter_arg+0xea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3750ULL;
	}
x86_l_38d:
	/* 0x38d: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_392:
	/* 0x392: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_395:
	/* 0x395: je     6c6 <generic_retkprobe_filter_arg+0x6c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1734ULL;
	}
x86_l_39b:
	/* 0x39b: jmp    2c49 <generic_retkprobe_filter_arg+0x2c49> */
	return 11337ULL;
x86_l_3a0:
	/* 0x3a0: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_3a3:
	/* 0x3a3: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3a6:
	/* 0x3a6: jb     521 <generic_retkprobe_filter_arg+0x521> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_521;
	}
x86_l_3ac:
	/* 0x3ac: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_3af:
	/* 0x3af: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3b2:
	/* 0x3b2: jae    88b <generic_retkprobe_filter_arg+0x88b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2187ULL;
	}
x86_l_3b8:
	/* 0x3b8: mov    QWORD PTR [rsp+0x20],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3bd:
	/* 0x3bd: mov    ebp,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c0:
	/* 0x3c0: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3c2:
	/* 0x3c2: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_3c5:
	/* 0x3c5: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_3c8:
	/* 0x3c8: je     3d2 <generic_retkprobe_filter_arg+0x3d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d2;
	}
x86_l_3ca:
	/* 0x3ca: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_3cc:
	/* 0x3cc: je     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b1;
	}
x86_l_3d2:
	/* 0x3d2: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_3d5:
	/* 0x3d5: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3da:
	/* 0x3da: ja     807 <generic_retkprobe_filter_arg+0x807> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2055ULL;
	}
x86_l_3e0:
	/* 0x3e0: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3e2:
	/* 0x3e2: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_3e7:
	/* 0x3e7: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_3eb:
	/* 0x3eb: jb     bac <generic_retkprobe_filter_arg+0xbac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2988ULL;
	}
x86_l_3f1:
	/* 0x3f1: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_3f6:
	/* 0x3f6: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_3fa:
	/* 0x3fa: jb     a6c <generic_retkprobe_filter_arg+0xa6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2668ULL;
	}
x86_l_400:
	/* 0x400: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_40a:
	/* 0x40a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_40e:
	/* 0x40e: jae    807 <generic_retkprobe_filter_arg+0x807> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2055ULL;
	}
x86_l_414:
	/* 0x414: mov    WORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_41b:
	/* 0x41b: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_421:
	/* 0x421: ja     90a <generic_retkprobe_filter_arg+0x90a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2314ULL;
	}
x86_l_427:
	/* 0x427: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_42c:
	/* 0x42c: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42e:
	/* 0x42e: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_432:
	/* 0x432: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_436:
	/* 0x436: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_43b:
	/* 0x43b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_440:
	/* 0x440: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_442:
	/* 0x442: mov    ecx,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_446:
	/* 0x446: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_448:
	/* 0x448: je     c48 <generic_retkprobe_filter_arg+0xc48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3144ULL;
	}
x86_l_44e:
	/* 0x44e: movzx  eax,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_453:
	/* 0x453: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_458:
	/* 0x458: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_45d:
	/* 0x45d: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_45f:
	/* 0x45f: je     c4a <generic_retkprobe_filter_arg+0xc4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3146ULL;
	}
x86_l_465:
	/* 0x465: mov    ecx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_469:
	/* 0x469: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_46c:
	/* 0x46c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_471:
	/* 0x471: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_476:
	/* 0x476: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_47b:
	/* 0x47b: jb     90a <generic_retkprobe_filter_arg+0x90a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2314ULL;
	}
x86_l_481:
	/* 0x481: mov    edx,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_485:
	/* 0x485: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_487:
	/* 0x487: je     90a <generic_retkprobe_filter_arg+0x90a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2314ULL;
	}
x86_l_48d:
	/* 0x48d: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_48f:
	/* 0x48f: je     c59 <generic_retkprobe_filter_arg+0xc59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3161ULL;
	}
x86_l_495:
	/* 0x495: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_498:
	/* 0x498: jb     90a <generic_retkprobe_filter_arg+0x90a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2314ULL;
	}
x86_l_49e:
	/* 0x49e: mov    edx,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a2:
	/* 0x4a2: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4a4:
	/* 0x4a4: je     90a <generic_retkprobe_filter_arg+0x90a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2314ULL;
	}
x86_l_4aa:
	/* 0x4aa: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_4ac:
	/* 0x4ac: je     c59 <generic_retkprobe_filter_arg+0xc59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3161ULL;
	}
x86_l_4b2:
	/* 0x4b2: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_4b5:
	/* 0x4b5: jb     2f3a <generic_retkprobe_filter_arg+0x2f3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12090ULL;
	}
x86_l_4bb:
	/* 0x4bb: mov    ecx,DWORD PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4bf:
	/* 0x4bf: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4c1:
	/* 0x4c1: je     2f3a <generic_retkprobe_filter_arg+0x2f3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12090ULL;
	}
x86_l_4c7:
	/* 0x4c7: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c9:
	/* 0x4c9: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4cb:
	/* 0x4cb: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_4ce:
	/* 0x4ce: jmp    ba2 <generic_retkprobe_filter_arg+0xba2> */
	return 2978ULL;
x86_l_4d3:
	/* 0x4d3: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4d6:
	/* 0x4d6: je     521 <generic_retkprobe_filter_arg+0x521> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_521;
	}
x86_l_4d8:
	/* 0x4d8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4db:
	/* 0x4db: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_262;
	}
x86_l_4e1:
	/* 0x4e1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4e4:
	/* 0x4e4: mov    ebp,DWORD PTR [rbp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4e7:
	/* 0x4e7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4eb:
	/* 0x4eb: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_4ee:
	/* 0x4ee: jg     fca <generic_retkprobe_filter_arg+0xfca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4042ULL;
	}
x86_l_4f4:
	/* 0x4f4: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_4f7:
	/* 0x4f7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4fa:
	/* 0x4fa: jb     17b1 <generic_retkprobe_filter_arg+0x17b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6065ULL;
	}
x86_l_500:
	/* 0x500: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_505:
	/* 0x505: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_508:
	/* 0x508: je     1713 <generic_retkprobe_filter_arg+0x1713> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5907ULL;
	}
x86_l_50e:
	/* 0x50e: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_513:
	/* 0x513: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_516:
	/* 0x516: je     fef <generic_retkprobe_filter_arg+0xfef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4079ULL;
	}
x86_l_51c:
	/* 0x51c: jmp    2ed7 <generic_retkprobe_filter_arg+0x2ed7> */
	return 11991ULL;
x86_l_521:
	/* 0x521: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_524:
	/* 0x524: jle    5b3 <generic_retkprobe_filter_arg+0x5b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5b3;
	}
x86_l_52a:
	/* 0x52a: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_52d:
	/* 0x52d: ja     5fa <generic_retkprobe_filter_arg+0x5fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_5fa;
	}
x86_l_533:
	/* 0x533: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_535:
	/* 0x535: movabs rsi,0x1e00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 128849018880ULL);
x86_l_53f:
	/* 0x53f: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_543:
	/* 0x543: jb     5ce <generic_retkprobe_filter_arg+0x5ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5ce;
	}
x86_l_549:
	/* 0x549: mov    esi,0x60000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1610612736ULL);
x86_l_54e:
	/* 0x54e: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_552:
	/* 0x552: jb     844 <generic_retkprobe_filter_arg+0x844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2116ULL;
	}
x86_l_558:
	/* 0x558: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_562:
	/* 0x562: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_566:
	/* 0x566: jae    5fa <generic_retkprobe_filter_arg+0x5fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5fa;
	}
x86_l_56c:
	/* 0x56c: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_56f:
	/* 0x56f: ja     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b1;
	}
x86_l_575:
	/* 0x575: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_577:
	/* 0x577: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_57c:
	/* 0x57c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_580:
	/* 0x580: jae    1136 <generic_retkprobe_filter_arg+0x1136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4406ULL;
	}
x86_l_586:
	/* 0x586: mov    ecx,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_58a:
	/* 0x58a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_58d:
	/* 0x58d: jle    15ce <generic_retkprobe_filter_arg+0x15ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5582ULL;
	}
x86_l_593:
	/* 0x593: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_596:
	/* 0x596: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_599:
	/* 0x599: jae    1b86 <generic_retkprobe_filter_arg+0x1b86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7046ULL;
	}
x86_l_59f:
	/* 0x59f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5a2:
	/* 0x5a2: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5a6:
	/* 0x5a6: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_5a8:
	/* 0x5a8: jne    1e68 <generic_retkprobe_filter_arg+0x1e68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7784ULL;
	}
x86_l_5ae:
	/* 0x5ae: jmp    2e60 <generic_retkprobe_filter_arg+0x2e60> */
	return 11872ULL;
x86_l_5b3:
	/* 0x5b3: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_5b6:
	/* 0x5b6: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_5b9:
	/* 0x5b9: jb     96c <generic_retkprobe_filter_arg+0x96c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2412ULL;
	}
x86_l_5bf:
	/* 0x5bf: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5c2:
	/* 0x5c2: je     606 <generic_retkprobe_filter_arg+0x606> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_606;
	}
x86_l_5c4:
	/* 0x5c4: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5c7:
	/* 0x5c7: je     606 <generic_retkprobe_filter_arg+0x606> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_606;
	}
x86_l_5c9:
	/* 0x5c9: jmp    262 <generic_retkprobe_filter_arg+0x262> */
	goto x86_l_262;
x86_l_5ce:
	/* 0x5ce: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_5d1:
	/* 0x5d1: jle    91f <generic_retkprobe_filter_arg+0x91f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2335ULL;
	}
x86_l_5d7:
	/* 0x5d7: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_5da:
	/* 0x5da: jg     d83 <generic_retkprobe_filter_arg+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3459ULL;
	}
x86_l_5e0:
	/* 0x5e0: lea    edx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_5e3:
	/* 0x5e3: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_5e6:
	/* 0x5e6: jb     9f9 <generic_retkprobe_filter_arg+0x9f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2553ULL;
	}
x86_l_5ec:
	/* 0x5ec: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_5ef:
	/* 0x5ef: je     982 <generic_retkprobe_filter_arg+0x982> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2434ULL;
	}
x86_l_5f5:
	/* 0x5f5: jmp    b1 <generic_retkprobe_filter_arg+0xb1> */
	goto x86_l_b1;
x86_l_5fa:
	/* 0x5fa: lea    edx,[rcx-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_5fd:
	/* 0x5fd: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_600:
	/* 0x600: jae    963 <generic_retkprobe_filter_arg+0x963> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2403ULL;
	}
x86_l_606:
	/* 0x606: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_609:
	/* 0x609: ja     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b1;
	}
x86_l_60f:
	/* 0x60f: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_611:
	/* 0x611: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_616:
	/* 0x616: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_61a:
	/* 0x61a: jae    643 <generic_retkprobe_filter_arg+0x643> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_643;
	}
x86_l_61c:
	/* 0x61c: mov    edx,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_620:
	/* 0x620: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_623:
	/* 0x623: jle    92c <generic_retkprobe_filter_arg+0x92c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2348ULL;
	}
x86_l_629:
	/* 0x629: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_62c:
	/* 0x62c: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_62f:
	/* 0x62f: jae    111f <generic_retkprobe_filter_arg+0x111f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4383ULL;
	}
x86_l_635:
	/* 0x635: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_638:
	/* 0x638: jne    20a6 <generic_retkprobe_filter_arg+0x20a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8358ULL;
	}
x86_l_63e:
	/* 0x63e: jmp    2e60 <generic_retkprobe_filter_arg+0x2e60> */
	return 11872ULL;
x86_l_643:
	/* 0x643: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_648:
	/* 0x648: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_64c:
	/* 0x64c: jb     c84 <generic_retkprobe_filter_arg+0xc84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3204ULL;
	}
x86_l_652:
	/* 0x652: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_65c:
	/* 0x65c: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_660:
	/* 0x660: jae    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b1;
	}
x86_l_666:
	/* 0x666: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_669:
	/* 0x669: jne    1276 <generic_retkprobe_filter_arg+0x1276> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4726ULL;
	}
x86_l_66f:
	/* 0x66f: mov    esi,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_673:
	/* 0x673: mov    edx,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_677:
	/* 0x677: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_67a:
	/* 0x67a: ja     1eff <generic_retkprobe_filter_arg+0x1eff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7935ULL;
	}
x86_l_680:
	/* 0x680: mov    eax,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5122ULL);
x86_l_685:
	/* 0x685: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_688:
	/* 0x688: jae    1eff <generic_retkprobe_filter_arg+0x1eff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7935ULL;
	}
x86_l_68e:
	/* 0x68e: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_691:
	/* 0x691: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_693:
	/* 0x693: jg     1f0e <generic_retkprobe_filter_arg+0x1f0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7950ULL;
	}
x86_l_699:
	/* 0x699: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_69b:
	/* 0x69b: jle    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_262;
	}
x86_l_6a1:
	/* 0x6a1: jmp    1f0e <generic_retkprobe_filter_arg+0x1f0e> */
	return 7950ULL;
x86_l_6a6:
	/* 0x6a6: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_6a9:
	/* 0x6a9: jg     dc9 <generic_retkprobe_filter_arg+0xdc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3529ULL;
	}
x86_l_6af:
	/* 0x6af: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_6b2:
	/* 0x6b2: je     ea6 <generic_retkprobe_filter_arg+0xea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3750ULL;
	}
x86_l_6b8:
	/* 0x6b8: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
	return 1725ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1725ULL: goto x86_l_6bd;
	case 1728ULL: goto x86_l_6c0;
	case 1734ULL: goto x86_l_6c6;
	case 1739ULL: goto x86_l_6cb;
	case 1743ULL: goto x86_l_6cf;
	case 1747ULL: goto x86_l_6d3;
	case 1758ULL: goto x86_l_6de;
	case 1763ULL: goto x86_l_6e3;
	case 1770ULL: goto x86_l_6ea;
	case 1775ULL: goto x86_l_6ef;
	case 1777ULL: goto x86_l_6f1;
	case 1780ULL: goto x86_l_6f4;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1794ULL: goto x86_l_702;
	case 1800ULL: goto x86_l_708;
	case 1805ULL: goto x86_l_70d;
	case 1810ULL: goto x86_l_712;
	case 1817ULL: goto x86_l_719;
	case 1822ULL: goto x86_l_71e;
	case 1824ULL: goto x86_l_720;
	case 1827ULL: goto x86_l_723;
	case 1833ULL: goto x86_l_729;
	case 1836ULL: goto x86_l_72c;
	case 1839ULL: goto x86_l_72f;
	case 1844ULL: goto x86_l_734;
	case 1847ULL: goto x86_l_737;
	case 1850ULL: goto x86_l_73a;
	case 1852ULL: goto x86_l_73c;
	case 1855ULL: goto x86_l_73f;
	case 1858ULL: goto x86_l_742;
	case 1863ULL: goto x86_l_747;
	case 1866ULL: goto x86_l_74a;
	case 1869ULL: goto x86_l_74d;
	case 1874ULL: goto x86_l_752;
	case 1878ULL: goto x86_l_756;
	case 1884ULL: goto x86_l_75c;
	case 1887ULL: goto x86_l_75f;
	case 1891ULL: goto x86_l_763;
	case 1897ULL: goto x86_l_769;
	case 1900ULL: goto x86_l_76c;
	case 1904ULL: goto x86_l_770;
	case 1907ULL: goto x86_l_773;
	case 1910ULL: goto x86_l_776;
	case 1915ULL: goto x86_l_77b;
	case 1919ULL: goto x86_l_77f;
	case 1925ULL: goto x86_l_785;
	case 1929ULL: goto x86_l_789;
	case 1933ULL: goto x86_l_78d;
	case 1936ULL: goto x86_l_790;
	case 1938ULL: goto x86_l_792;
	case 1942ULL: goto x86_l_796;
	case 1948ULL: goto x86_l_79c;
	case 1952ULL: goto x86_l_7a0;
	case 1956ULL: goto x86_l_7a4;
	case 1959ULL: goto x86_l_7a7;
	case 1961ULL: goto x86_l_7a9;
	case 1965ULL: goto x86_l_7ad;
	case 1971ULL: goto x86_l_7b3;
	case 1975ULL: goto x86_l_7b7;
	case 1979ULL: goto x86_l_7bb;
	case 1982ULL: goto x86_l_7be;
	case 1984ULL: goto x86_l_7c0;
	case 1988ULL: goto x86_l_7c4;
	case 1990ULL: goto x86_l_7c6;
	case 1994ULL: goto x86_l_7ca;
	case 2000ULL: goto x86_l_7d0;
	case 2004ULL: goto x86_l_7d4;
	case 2007ULL: goto x86_l_7d7;
	case 2011ULL: goto x86_l_7db;
	case 2015ULL: goto x86_l_7df;
	case 2018ULL: goto x86_l_7e2;
	case 2020ULL: goto x86_l_7e4;
	case 2025ULL: goto x86_l_7e9;
	case 2030ULL: goto x86_l_7ee;
	case 2035ULL: goto x86_l_7f3;
	case 2037ULL: goto x86_l_7f5;
	case 2039ULL: goto x86_l_7f7;
	case 2042ULL: goto x86_l_7fa;
	case 2045ULL: goto x86_l_7fd;
	case 2050ULL: goto x86_l_802;
	case 2055ULL: goto x86_l_807;
	case 2058ULL: goto x86_l_80a;
	case 2061ULL: goto x86_l_80d;
	case 2067ULL: goto x86_l_813;
	case 2078ULL: goto x86_l_81e;
	case 2084ULL: goto x86_l_824;
	case 2090ULL: goto x86_l_82a;
	case 2092ULL: goto x86_l_82c;
	case 2097ULL: goto x86_l_831;
	case 2101ULL: goto x86_l_835;
	case 2105ULL: goto x86_l_839;
	case 2111ULL: goto x86_l_83f;
	case 2116ULL: goto x86_l_844;
	case 2119ULL: goto x86_l_847;
	case 2125ULL: goto x86_l_84d;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2136ULL: goto x86_l_858;
	case 2142ULL: goto x86_l_85e;
	case 2146ULL: goto x86_l_862;
	case 2149ULL: goto x86_l_865;
	case 2155ULL: goto x86_l_86b;
	case 2158ULL: goto x86_l_86e;
	case 2161ULL: goto x86_l_871;
	case 2167ULL: goto x86_l_877;
	case 2170ULL: goto x86_l_87a;
	case 2174ULL: goto x86_l_87e;
	case 2176ULL: goto x86_l_880;
	case 2182ULL: goto x86_l_886;
	case 2187ULL: goto x86_l_88b;
	case 2190ULL: goto x86_l_88e;
	case 2196ULL: goto x86_l_894;
	case 2205ULL: goto x86_l_89d;
	case 2214ULL: goto x86_l_8a6;
	case 2223ULL: goto x86_l_8af;
	case 2232ULL: goto x86_l_8b8;
	case 2241ULL: goto x86_l_8c1;
	case 2244ULL: goto x86_l_8c4;
	case 2246ULL: goto x86_l_8c6;
	case 2249ULL: goto x86_l_8c9;
	case 2252ULL: goto x86_l_8cc;
	case 2258ULL: goto x86_l_8d2;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2269ULL: goto x86_l_8dd;
	case 2275ULL: goto x86_l_8e3;
	case 2280ULL: goto x86_l_8e8;
	case 2283ULL: goto x86_l_8eb;
	case 2286ULL: goto x86_l_8ee;
	case 2292ULL: goto x86_l_8f4;
	case 2295ULL: goto x86_l_8f7;
	case 2300ULL: goto x86_l_8fc;
	case 2303ULL: goto x86_l_8ff;
	case 2309ULL: goto x86_l_905;
	case 2314ULL: goto x86_l_90a;
	case 2316ULL: goto x86_l_90c;
	case 2320ULL: goto x86_l_910;
	case 2324ULL: goto x86_l_914;
	case 2330ULL: goto x86_l_91a;
	case 2335ULL: goto x86_l_91f;
	case 2338ULL: goto x86_l_922;
	case 2341ULL: goto x86_l_925;
	case 2343ULL: goto x86_l_927;
	case 2348ULL: goto x86_l_92c;
	case 2351ULL: goto x86_l_92f;
	case 2357ULL: goto x86_l_935;
	case 2360ULL: goto x86_l_938;
	case 2366ULL: goto x86_l_93e;
	case 2369ULL: goto x86_l_941;
	case 2375ULL: goto x86_l_947;
	case 2380ULL: goto x86_l_94c;
	case 2383ULL: goto x86_l_94f;
	case 2389ULL: goto x86_l_955;
	case 2392ULL: goto x86_l_958;
	case 2398ULL: goto x86_l_95e;
	case 2403ULL: goto x86_l_963;
	case 2406ULL: goto x86_l_966;
	case 2412ULL: goto x86_l_96c;
	case 2415ULL: goto x86_l_96f;
	case 2421ULL: goto x86_l_975;
	case 2423ULL: goto x86_l_977;
	case 2428ULL: goto x86_l_97c;
	case 2432ULL: goto x86_l_980;
	case 2434ULL: goto x86_l_982;
	case 2438ULL: goto x86_l_986;
	case 2441ULL: goto x86_l_989;
	case 2443ULL: goto x86_l_98b;
	case 2446ULL: goto x86_l_98e;
	case 2449ULL: goto x86_l_991;
	case 2455ULL: goto x86_l_997;
	case 2459ULL: goto x86_l_99b;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2475ULL: goto x86_l_9ab;
	case 2479ULL: goto x86_l_9af;
	case 2481ULL: goto x86_l_9b1;
	case 2491ULL: goto x86_l_9bb;
	case 2495ULL: goto x86_l_9bf;
	case 2501ULL: goto x86_l_9c5;
	case 2506ULL: goto x86_l_9ca;
	case 2509ULL: goto x86_l_9cd;
	case 2515ULL: goto x86_l_9d3;
	case 2518ULL: goto x86_l_9d6;
	case 2524ULL: goto x86_l_9dc;
	case 2527ULL: goto x86_l_9df;
	case 2529ULL: goto x86_l_9e1;
	case 2532ULL: goto x86_l_9e4;
	case 2538ULL: goto x86_l_9ea;
	case 2542ULL: goto x86_l_9ee;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2558ULL: goto x86_l_9fe;
	case 2565ULL: goto x86_l_a05;
	case 2570ULL: goto x86_l_a0a;
	case 2577ULL: goto x86_l_a11;
	case 2582ULL: goto x86_l_a16;
	case 2584ULL: goto x86_l_a18;
	case 2587ULL: goto x86_l_a1b;
	case 2593ULL: goto x86_l_a21;
	case 2597ULL: goto x86_l_a25;
	case 2602ULL: goto x86_l_a2a;
	case 2607ULL: goto x86_l_a2f;
	case 2610ULL: goto x86_l_a32;
	case 2615ULL: goto x86_l_a37;
	case 2617ULL: goto x86_l_a39;
	case 2621ULL: goto x86_l_a3d;
	case 2624ULL: goto x86_l_a40;
	case 2630ULL: goto x86_l_a46;
	case 2633ULL: goto x86_l_a49;
	case 2638ULL: goto x86_l_a4e;
	case 2643ULL: goto x86_l_a53;
	case 2648ULL: goto x86_l_a58;
	case 2654ULL: goto x86_l_a5e;
	case 2657ULL: goto x86_l_a61;
	case 2660ULL: goto x86_l_a64;
	case 2663ULL: goto x86_l_a67;
	case 2668ULL: goto x86_l_a6c;
	case 2672ULL: goto x86_l_a70;
	case 2676ULL: goto x86_l_a74;
	case 2687ULL: goto x86_l_a7f;
	case 2692ULL: goto x86_l_a84;
	case 2699ULL: goto x86_l_a8b;
	case 2704ULL: goto x86_l_a90;
	case 2706ULL: goto x86_l_a92;
	case 2709ULL: goto x86_l_a95;
	case 2715ULL: goto x86_l_a9b;
	case 2720ULL: goto x86_l_aa0;
	case 2723ULL: goto x86_l_aa3;
	case 2729ULL: goto x86_l_aa9;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2746ULL: goto x86_l_aba;
	case 2751ULL: goto x86_l_abf;
	case 2753ULL: goto x86_l_ac1;
	case 2756ULL: goto x86_l_ac4;
	case 2762ULL: goto x86_l_aca;
	case 2765ULL: goto x86_l_acd;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2776ULL: goto x86_l_ad8;
	case 2779ULL: goto x86_l_adb;
	case 2781ULL: goto x86_l_add;
	case 2784ULL: goto x86_l_ae0;
	case 2787ULL: goto x86_l_ae3;
	case 2792ULL: goto x86_l_ae8;
	case 2795ULL: goto x86_l_aeb;
	case 2798ULL: goto x86_l_aee;
	case 2803ULL: goto x86_l_af3;
	case 2807ULL: goto x86_l_af7;
	case 2813ULL: goto x86_l_afd;
	case 2816ULL: goto x86_l_b00;
	case 2820ULL: goto x86_l_b04;
	case 2826ULL: goto x86_l_b0a;
	case 2829ULL: goto x86_l_b0d;
	case 2833ULL: goto x86_l_b11;
	case 2836ULL: goto x86_l_b14;
	case 2839ULL: goto x86_l_b17;
	case 2844ULL: goto x86_l_b1c;
	case 2848ULL: goto x86_l_b20;
	case 2854ULL: goto x86_l_b26;
	case 2859ULL: goto x86_l_b2b;
	case 2863ULL: goto x86_l_b2f;
	case 2866ULL: goto x86_l_b32;
	case 2868ULL: goto x86_l_b34;
	case 2872ULL: goto x86_l_b38;
	case 2878ULL: goto x86_l_b3e;
	case 2883ULL: goto x86_l_b43;
	case 2887ULL: goto x86_l_b47;
	case 2890ULL: goto x86_l_b4a;
	case 2892ULL: goto x86_l_b4c;
	case 2896ULL: goto x86_l_b50;
	case 2902ULL: goto x86_l_b56;
	case 2907ULL: goto x86_l_b5b;
	case 2911ULL: goto x86_l_b5f;
	case 2914ULL: goto x86_l_b62;
	case 2916ULL: goto x86_l_b64;
	case 2920ULL: goto x86_l_b68;
	case 2922ULL: goto x86_l_b6a;
	case 2926ULL: goto x86_l_b6e;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2940ULL: goto x86_l_b7c;
	case 2944ULL: goto x86_l_b80;
	case 2948ULL: goto x86_l_b84;
	case 2951ULL: goto x86_l_b87;
	case 2953ULL: goto x86_l_b89;
	case 2958ULL: goto x86_l_b8e;
	case 2963ULL: goto x86_l_b93;
	case 2968ULL: goto x86_l_b98;
	case 2970ULL: goto x86_l_b9a;
	case 2972ULL: goto x86_l_b9c;
	case 2975ULL: goto x86_l_b9f;
	case 2978ULL: goto x86_l_ba2;
	case 2983ULL: goto x86_l_ba7;
	case 2988ULL: goto x86_l_bac;
	case 2992ULL: goto x86_l_bb0;
	case 2996ULL: goto x86_l_bb4;
	case 3007ULL: goto x86_l_bbf;
	case 3012ULL: goto x86_l_bc4;
	case 3019ULL: goto x86_l_bcb;
	case 3024ULL: goto x86_l_bd0;
	case 3026ULL: goto x86_l_bd2;
	case 3029ULL: goto x86_l_bd5;
	case 3031ULL: goto x86_l_bd7;
	case 3036ULL: goto x86_l_bdc;
	case 3039ULL: goto x86_l_bdf;
	case 3041ULL: goto x86_l_be1;
	case 3046ULL: goto x86_l_be6;
	case 3051ULL: goto x86_l_beb;
	case 3058ULL: goto x86_l_bf2;
	case 3063ULL: goto x86_l_bf7;
	case 3065ULL: goto x86_l_bf9;
	case 3068ULL: goto x86_l_bfc;
	case 3070ULL: goto x86_l_bfe;
	case 3073ULL: goto x86_l_c01;
	case 3078ULL: goto x86_l_c06;
	case 3082ULL: goto x86_l_c0a;
	case 3088ULL: goto x86_l_c10;
	case 3093ULL: goto x86_l_c15;
	case 3096ULL: goto x86_l_c18;
	case 3103ULL: goto x86_l_c1f;
	case 3105ULL: goto x86_l_c21;
	case 3108ULL: goto x86_l_c24;
	case 3112ULL: goto x86_l_c28;
	case 3117ULL: goto x86_l_c2d;
	case 3119ULL: goto x86_l_c2f;
	case 3124ULL: goto x86_l_c34;
	case 3129ULL: goto x86_l_c39;
	case 3132ULL: goto x86_l_c3c;
	case 3134ULL: goto x86_l_c3e;
	case 3136ULL: goto x86_l_c40;
	case 3139ULL: goto x86_l_c43;
	case 3142ULL: goto x86_l_c46;
	case 3144ULL: goto x86_l_c48;
	case 3146ULL: goto x86_l_c4a;
	case 3151ULL: goto x86_l_c4f;
	case 3156ULL: goto x86_l_c54;
	case 3161ULL: goto x86_l_c59;
	case 3165ULL: goto x86_l_c5d;
	case 3169ULL: goto x86_l_c61;
	case 3175ULL: goto x86_l_c67;
	case 3185ULL: goto x86_l_c71;
	case 3189ULL: goto x86_l_c75;
	case 3195ULL: goto x86_l_c7b;
	case 3199ULL: goto x86_l_c7f;
	case 3204ULL: goto x86_l_c84;
	case 3209ULL: goto x86_l_c89;
	case 3216ULL: goto x86_l_c90;
	case 3221ULL: goto x86_l_c95;
	case 3228ULL: goto x86_l_c9c;
	case 3233ULL: goto x86_l_ca1;
	case 3235ULL: goto x86_l_ca3;
	case 3238ULL: goto x86_l_ca6;
	case 3244ULL: goto x86_l_cac;
	case 3247ULL: goto x86_l_caf;
	case 3252ULL: goto x86_l_cb4;
	case 3257ULL: goto x86_l_cb9;
	case 3262ULL: goto x86_l_cbe;
	case 3265ULL: goto x86_l_cc1;
	case 3271ULL: goto x86_l_cc7;
	case 3275ULL: goto x86_l_ccb;
	case 3281ULL: goto x86_l_cd1;
	case 3286ULL: goto x86_l_cd6;
	case 3289ULL: goto x86_l_cd9;
	case 3294ULL: goto x86_l_cde;
	case 3298ULL: goto x86_l_ce2;
	case 3303ULL: goto x86_l_ce7;
	case 3307ULL: goto x86_l_ceb;
	case 3312ULL: goto x86_l_cf0;
	case 3316ULL: goto x86_l_cf4;
	case 3321ULL: goto x86_l_cf9;
	case 3326ULL: goto x86_l_cfe;
	case 3328ULL: goto x86_l_d00;
	case 3331ULL: goto x86_l_d03;
	case 3333ULL: goto x86_l_d05;
	case 3336ULL: goto x86_l_d08;
	case 3338ULL: goto x86_l_d0a;
	case 3341ULL: goto x86_l_d0d;
	case 3344ULL: goto x86_l_d10;
	case 3350ULL: goto x86_l_d16;
	case 3353ULL: goto x86_l_d19;
	case 3358ULL: goto x86_l_d1e;
	case 3361ULL: goto x86_l_d21;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6bd:
	/* 0x6bd: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_6c0:
	/* 0x6c0: jne    2c49 <generic_retkprobe_filter_arg+0x2c49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11337ULL;
	}
x86_l_6c6:
	/* 0x6c6: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6cb:
	/* 0x6cb: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6cf:
	/* 0x6cf: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6d3:
	/* 0x6d3: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_6de:
	/* 0x6de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6e3:
	/* 0x6e3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_6ea:
	/* 0x6ea: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6ef:
	/* 0x6ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f1:
	/* 0x6f1: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_6f4:
	/* 0x6f4: je     2c38 <generic_retkprobe_filter_arg+0x2c38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11320ULL;
	}
x86_l_6fa:
	/* 0x6fa: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_6ff:
	/* 0x6ff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_702:
	/* 0x702: je     2c3a <generic_retkprobe_filter_arg+0x2c3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11322ULL;
	}
x86_l_708:
	/* 0x708: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_70d:
	/* 0x70d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_712:
	/* 0x712: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_719:
	/* 0x719: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_71e:
	/* 0x71e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_720:
	/* 0x720: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_723:
	/* 0x723: je     2c38 <generic_retkprobe_filter_arg+0x2c38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11320ULL;
	}
x86_l_729:
	/* 0x729: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_72c:
	/* 0x72c: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_72f:
	/* 0x72f: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_734:
	/* 0x734: cmovb  ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_737:
	/* 0x737: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_73a:
	/* 0x73a: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_73c:
	/* 0x73c: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_73f:
	/* 0x73f: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_742:
	/* 0x742: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_747:
	/* 0x747: sub    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_74a:
	/* 0x74a: lea    eax,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_74d:
	/* 0x74d: mov    QWORD PTR [rsp+0x50],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_752:
	/* 0x752: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_756:
	/* 0x756: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_75c:
	/* 0x75c: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_75f:
	/* 0x75f: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_763:
	/* 0x763: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_769:
	/* 0x769: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_76c:
	/* 0x76c: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_770:
	/* 0x770: lea    ebx,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_773:
	/* 0x773: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_776:
	/* 0x776: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_77b:
	/* 0x77b: lea    ebp,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_77f:
	/* 0x77f: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_785:
	/* 0x785: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_789:
	/* 0x789: mov    BYTE PTR [rdi-0x3],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_78d:
	/* 0x78d: cmp    r10,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R12, X86_WIDTH_64);
x86_l_790:
	/* 0x790: je     7e4 <generic_retkprobe_filter_arg+0x7e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e4;
	}
x86_l_792:
	/* 0x792: lea    ebp,[r11+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_796:
	/* 0x796: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_79c:
	/* 0x79c: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_7a0:
	/* 0x7a0: mov    BYTE PTR [rdi-0x2],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_7a4:
	/* 0x7a4: cmp    r8,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R12, X86_WIDTH_64);
x86_l_7a7:
	/* 0x7a7: je     7e4 <generic_retkprobe_filter_arg+0x7e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e4;
	}
x86_l_7a9:
	/* 0x7a9: lea    ebp,[r9+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_7ad:
	/* 0x7ad: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7b3:
	/* 0x7b3: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_7b7:
	/* 0x7b7: mov    BYTE PTR [rdi-0x1],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_7bb:
	/* 0x7bb: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7be:
	/* 0x7be: je     7e4 <generic_retkprobe_filter_arg+0x7e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e4;
	}
x86_l_7c0:
	/* 0x7c0: cmp    r12,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_7c4:
	/* 0x7c4: je     7e4 <generic_retkprobe_filter_arg+0x7e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e4;
	}
x86_l_7c6:
	/* 0x7c6: lea    ebp,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_7ca:
	/* 0x7ca: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7d0:
	/* 0x7d0: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_7d4:
	/* 0x7d4: mov    BYTE PTR [rdi],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7d7:
	/* 0x7d7: add    r12,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_7db:
	/* 0x7db: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_7df:
	/* 0x7df: cmp    rcx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_7e2:
	/* 0x7e2: jne    77b <generic_retkprobe_filter_arg+0x77b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_77b;
	}
x86_l_7e4:
	/* 0x7e4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7e9:
	/* 0x7e9: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7ee:
	/* 0x7ee: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7f3:
	/* 0x7f3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7f5:
	/* 0x7f5: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7f7:
	/* 0x7f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7fa:
	/* 0x7fa: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_7fd:
	/* 0x7fd: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_802:
	/* 0x802: jmp    2c3a <generic_retkprobe_filter_arg+0x2c3a> */
	return 11322ULL;
x86_l_807:
	/* 0x807: add    eax,0xfffffffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967293ULL);
x86_l_80a:
	/* 0x80a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_80d:
	/* 0x80d: jae    90a <generic_retkprobe_filter_arg+0x90a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_90a;
	}
x86_l_813:
	/* 0x813: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_81e:
	/* 0x81e: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_824:
	/* 0x824: jbe    121d <generic_retkprobe_filter_arg+0x121d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4637ULL;
	}
x86_l_82a:
	/* 0x82a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_82c:
	/* 0x82c: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_831:
	/* 0x831: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_835:
	/* 0x835: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_839:
	/* 0x839: jbe    c67 <generic_retkprobe_filter_arg+0xc67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_c67;
	}
x86_l_83f:
	/* 0x83f: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_844:
	/* 0x844: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_847:
	/* 0x847: ja     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 177ULL;
	}
x86_l_84d:
	/* 0x84d: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_84f:
	/* 0x84f: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_854:
	/* 0x854: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_858:
	/* 0x858: jae    1168 <generic_retkprobe_filter_arg+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4456ULL;
	}
x86_l_85e:
	/* 0x85e: mov    ecx,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_862:
	/* 0x862: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_865:
	/* 0x865: jle    15f1 <generic_retkprobe_filter_arg+0x15f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5617ULL;
	}
x86_l_86b:
	/* 0x86b: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_86e:
	/* 0x86e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_871:
	/* 0x871: jae    1ba0 <generic_retkprobe_filter_arg+0x1ba0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7072ULL;
	}
x86_l_877:
	/* 0x877: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_87a:
	/* 0x87a: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_87e:
	/* 0x87e: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_880:
	/* 0x880: jne    1eab <generic_retkprobe_filter_arg+0x1eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7851ULL;
	}
x86_l_886:
	/* 0x886: jmp    2e60 <generic_retkprobe_filter_arg+0x2e60> */
	return 11872ULL;
x86_l_88b:
	/* 0x88b: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_88e:
	/* 0x88e: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_894:
	/* 0x894: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_89d:
	/* 0x89d: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_8a6:
	/* 0x8a6: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_8af:
	/* 0x8af: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_8b8:
	/* 0x8b8: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_8c1:
	/* 0x8c1: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_8c4:
	/* 0x8c4: jg     8e8 <generic_retkprobe_filter_arg+0x8e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_8e8;
	}
x86_l_8c6:
	/* 0x8c6: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_8c9:
	/* 0x8c9: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_8cc:
	/* 0x8cc: je     cfe <generic_retkprobe_filter_arg+0xcfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cfe;
	}
x86_l_8d2:
	/* 0x8d2: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_8d5:
	/* 0x8d5: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_8da:
	/* 0x8da: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_8dd:
	/* 0x8dd: je     d00 <generic_retkprobe_filter_arg+0xd00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d00;
	}
x86_l_8e3:
	/* 0x8e3: jmp    24c <generic_retkprobe_filter_arg+0x24c> */
	return 588ULL;
x86_l_8e8:
	/* 0x8e8: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_8eb:
	/* 0x8eb: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_8ee:
	/* 0x8ee: je     cd6 <generic_retkprobe_filter_arg+0xcd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd6;
	}
x86_l_8f4:
	/* 0x8f4: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_8f7:
	/* 0x8f7: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_8fc:
	/* 0x8fc: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_8ff:
	/* 0x8ff: je     d00 <generic_retkprobe_filter_arg+0xd00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d00;
	}
x86_l_905:
	/* 0x905: jmp    24c <generic_retkprobe_filter_arg+0x24c> */
	return 588ULL;
x86_l_90a:
	/* 0x90a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_90c:
	/* 0x90c: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_910:
	/* 0x910: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_914:
	/* 0x914: jbe    c67 <generic_retkprobe_filter_arg+0xc67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_c67;
	}
x86_l_91a:
	/* 0x91a: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_91f:
	/* 0x91f: lea    edx,[rax-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_922:
	/* 0x922: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_925:
	/* 0x925: jb     982 <generic_retkprobe_filter_arg+0x982> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_982;
	}
x86_l_927:
	/* 0x927: jmp    b1 <generic_retkprobe_filter_arg+0xb1> */
	return 177ULL;
x86_l_92c:
	/* 0x92c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_92f:
	/* 0x92f: je     13d4 <generic_retkprobe_filter_arg+0x13d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5076ULL;
	}
x86_l_935:
	/* 0x935: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_938:
	/* 0x938: jne    20a6 <generic_retkprobe_filter_arg+0x20a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8358ULL;
	}
x86_l_93e:
	/* 0x93e: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_941:
	/* 0x941: ja     209d <generic_retkprobe_filter_arg+0x209d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8349ULL;
	}
x86_l_947:
	/* 0x947: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_94c:
	/* 0x94c: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_94f:
	/* 0x94f: jae    209d <generic_retkprobe_filter_arg+0x209d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8349ULL;
	}
x86_l_955:
	/* 0x955: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_958:
	/* 0x958: jl     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 610ULL;
	}
x86_l_95e:
	/* 0x95e: jmp    20a6 <generic_retkprobe_filter_arg+0x20a6> */
	return 8358ULL;
x86_l_963:
	/* 0x963: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_966:
	/* 0x966: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_96c:
	/* 0x96c: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_96f:
	/* 0x96f: ja     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 177ULL;
	}
x86_l_975:
	/* 0x975: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_977:
	/* 0x977: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_97c:
	/* 0x97c: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_980:
	/* 0x980: jae    9a6 <generic_retkprobe_filter_arg+0x9a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9a6;
	}
x86_l_982:
	/* 0x982: mov    rdx,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_986:
	/* 0x986: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_989:
	/* 0x989: jle    9ca <generic_retkprobe_filter_arg+0x9ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_9ca;
	}
x86_l_98b:
	/* 0x98b: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_98e:
	/* 0x98e: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_991:
	/* 0x991: jae    cbe <generic_retkprobe_filter_arg+0xcbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_cbe;
	}
x86_l_997:
	/* 0x997: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99b:
	/* 0x99b: jne    1b08 <generic_retkprobe_filter_arg+0x1b08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6920ULL;
	}
x86_l_9a1:
	/* 0x9a1: jmp    2e60 <generic_retkprobe_filter_arg+0x2e60> */
	return 11872ULL;
x86_l_9a6:
	/* 0x9a6: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_9ab:
	/* 0x9ab: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_9af:
	/* 0x9af: jb     9f9 <generic_retkprobe_filter_arg+0x9f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9f9;
	}
x86_l_9b1:
	/* 0x9b1: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_9bb:
	/* 0x9bb: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_9bf:
	/* 0x9bf: jb     d8f <generic_retkprobe_filter_arg+0xd8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3471ULL;
	}
x86_l_9c5:
	/* 0x9c5: jmp    b1 <generic_retkprobe_filter_arg+0xb1> */
	return 177ULL;
x86_l_9ca:
	/* 0x9ca: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9cd:
	/* 0x9cd: je     1200 <generic_retkprobe_filter_arg+0x1200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4608ULL;
	}
x86_l_9d3:
	/* 0x9d3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9d6:
	/* 0x9d6: jne    1b08 <generic_retkprobe_filter_arg+0x1b08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6920ULL;
	}
x86_l_9dc:
	/* 0x9dc: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_9df:
	/* 0x9df: je     9ea <generic_retkprobe_filter_arg+0x9ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9ea;
	}
x86_l_9e1:
	/* 0x9e1: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_9e4:
	/* 0x9e4: jne    1afe <generic_retkprobe_filter_arg+0x1afe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6910ULL;
	}
x86_l_9ea:
	/* 0x9ea: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ee:
	/* 0x9ee: jl     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 610ULL;
	}
x86_l_9f4:
	/* 0x9f4: jmp    1b08 <generic_retkprobe_filter_arg+0x1b08> */
	return 6920ULL;
x86_l_9f9:
	/* 0x9f9: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_9fe:
	/* 0x9fe: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a05:
	/* 0xa05: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a0a:
	/* 0xa0a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_a11:
	/* 0xa11: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a16:
	/* 0xa16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a18:
	/* 0xa18: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a1b:
	/* 0xa1b: je     16be <generic_retkprobe_filter_arg+0x16be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5822ULL;
	}
x86_l_a21:
	/* 0xa21: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a25:
	/* 0xa25: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a2a:
	/* 0xa2a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a2f:
	/* 0xa2f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_a32:
	/* 0xa32: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a37:
	/* 0xa37: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a39:
	/* 0xa39: mov    ecx,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a3d:
	/* 0xa3d: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_a40:
	/* 0xa40: je     16ec <generic_retkprobe_filter_arg+0x16ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5868ULL;
	}
x86_l_a46:
	/* 0xa46: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_a49:
	/* 0xa49: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a4e:
	/* 0xa4e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a53:
	/* 0xa53: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a58:
	/* 0xa58: jne    1709 <generic_retkprobe_filter_arg+0x1709> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5897ULL;
	}
x86_l_a5e:
	/* 0xa5e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a61:
	/* 0xa61: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_a64:
	/* 0xa64: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_a67:
	/* 0xa67: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_a6c:
	/* 0xa6c: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a70:
	/* 0xa70: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a74:
	/* 0xa74: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_a7f:
	/* 0xa7f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a84:
	/* 0xa84: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_a8b:
	/* 0xa8b: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a90:
	/* 0xa90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a92:
	/* 0xa92: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_a95:
	/* 0xa95: je     c48 <generic_retkprobe_filter_arg+0xc48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c48;
	}
x86_l_a9b:
	/* 0xa9b: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_aa0:
	/* 0xaa0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aa3:
	/* 0xaa3: je     c4a <generic_retkprobe_filter_arg+0xc4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c4a;
	}
x86_l_aa9:
	/* 0xaa9: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_aae:
	/* 0xaae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ab3:
	/* 0xab3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_aba:
	/* 0xaba: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_abf:
	/* 0xabf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac1:
	/* 0xac1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ac4:
	/* 0xac4: je     c48 <generic_retkprobe_filter_arg+0xc48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c48;
	}
x86_l_aca:
	/* 0xaca: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_acd:
	/* 0xacd: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_ad0:
	/* 0xad0: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_ad5:
	/* 0xad5: cmovb  ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_ad8:
	/* 0xad8: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_adb:
	/* 0xadb: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_add:
	/* 0xadd: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_ae0:
	/* 0xae0: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_ae3:
	/* 0xae3: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_ae8:
	/* 0xae8: sub    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_aeb:
	/* 0xaeb: lea    eax,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_aee:
	/* 0xaee: mov    QWORD PTR [rsp+0x50],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_af3:
	/* 0xaf3: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_af7:
	/* 0xaf7: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_afd:
	/* 0xafd: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b00:
	/* 0xb00: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_b04:
	/* 0xb04: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_b0a:
	/* 0xb0a: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b0d:
	/* 0xb0d: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_b11:
	/* 0xb11: lea    ebx,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_b14:
	/* 0xb14: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b17:
	/* 0xb17: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b1c:
	/* 0xb1c: lea    ebp,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_b20:
	/* 0xb20: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b26:
	/* 0xb26: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_b2b:
	/* 0xb2b: mov    BYTE PTR [rdi-0x3],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_b2f:
	/* 0xb2f: cmp    r10,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R12, X86_WIDTH_64);
x86_l_b32:
	/* 0xb32: je     b89 <generic_retkprobe_filter_arg+0xb89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b89;
	}
x86_l_b34:
	/* 0xb34: lea    ebp,[r11+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_b38:
	/* 0xb38: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b3e:
	/* 0xb3e: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_b43:
	/* 0xb43: mov    BYTE PTR [rdi-0x2],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_b47:
	/* 0xb47: cmp    r8,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R12, X86_WIDTH_64);
x86_l_b4a:
	/* 0xb4a: je     b89 <generic_retkprobe_filter_arg+0xb89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b89;
	}
x86_l_b4c:
	/* 0xb4c: lea    ebp,[r9+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_b50:
	/* 0xb50: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b56:
	/* 0xb56: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_b5b:
	/* 0xb5b: mov    BYTE PTR [rdi-0x1],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_b5f:
	/* 0xb5f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_b62:
	/* 0xb62: je     b89 <generic_retkprobe_filter_arg+0xb89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b89;
	}
x86_l_b64:
	/* 0xb64: cmp    r12,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_b68:
	/* 0xb68: je     b89 <generic_retkprobe_filter_arg+0xb89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b89;
	}
x86_l_b6a:
	/* 0xb6a: lea    ebp,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_b6e:
	/* 0xb6e: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b74:
	/* 0xb74: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_b79:
	/* 0xb79: mov    BYTE PTR [rdi],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7c:
	/* 0xb7c: add    r12,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_b80:
	/* 0xb80: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_b84:
	/* 0xb84: cmp    rcx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_b87:
	/* 0xb87: jne    b1c <generic_retkprobe_filter_arg+0xb1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b1c;
	}
x86_l_b89:
	/* 0xb89: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b8e:
	/* 0xb8e: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b93:
	/* 0xb93: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b98:
	/* 0xb98: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b9a:
	/* 0xb9a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b9c:
	/* 0xb9c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b9f:
	/* 0xb9f: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_ba2:
	/* 0xba2: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ba7:
	/* 0xba7: jmp    c4a <generic_retkprobe_filter_arg+0xc4a> */
	goto x86_l_c4a;
x86_l_bac:
	/* 0xbac: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bb0:
	/* 0xbb0: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bb4:
	/* 0xbb4: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_bbf:
	/* 0xbbf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bc4:
	/* 0xbc4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_bcb:
	/* 0xbcb: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bd0:
	/* 0xbd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd2:
	/* 0xbd2: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_bd5:
	/* 0xbd5: je     c48 <generic_retkprobe_filter_arg+0xc48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c48;
	}
x86_l_bd7:
	/* 0xbd7: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_bdc:
	/* 0xbdc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bdf:
	/* 0xbdf: je     c4a <generic_retkprobe_filter_arg+0xc4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c4a;
	}
x86_l_be1:
	/* 0xbe1: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_be6:
	/* 0xbe6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_beb:
	/* 0xbeb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_bf2:
	/* 0xbf2: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bf7:
	/* 0xbf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf9:
	/* 0xbf9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bfc:
	/* 0xbfc: je     c48 <generic_retkprobe_filter_arg+0xc48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c48;
	}
x86_l_bfe:
	/* 0xbfe: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_c01:
	/* 0xc01: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c06:
	/* 0xc06: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_c0a:
	/* 0xc0a: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_c10:
	/* 0xc10: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_c15:
	/* 0xc15: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_c18:
	/* 0xc18: lea    eax,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_c1f:
	/* 0xc1f: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c21:
	/* 0xc21: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c24:
	/* 0xc24: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_c28:
	/* 0xc28: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c2d:
	/* 0xc2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2f:
	/* 0xc2f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c34:
	/* 0xc34: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c39:
	/* 0xc39: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_c3c:
	/* 0xc3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c3e:
	/* 0xc3e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c40:
	/* 0xc40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c43:
	/* 0xc43: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_c46:
	/* 0xc46: jmp    c4a <generic_retkprobe_filter_arg+0xc4a> */
	goto x86_l_c4a;
x86_l_c48:
	/* 0xc48: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c4a:
	/* 0xc4a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c4f:
	/* 0xc4f: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c54:
	/* 0xc54: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c59:
	/* 0xc59: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c5d:
	/* 0xc5d: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_c61:
	/* 0xc61: ja     251 <generic_retkprobe_filter_arg+0x251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 593ULL;
	}
x86_l_c67:
	/* 0xc67: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_c71:
	/* 0xc71: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c75:
	/* 0xc75: jae    251 <generic_retkprobe_filter_arg+0x251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 593ULL;
	}
x86_l_c7b:
	/* 0xc7b: xor    rbx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_c7f:
	/* 0xc7f: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_c84:
	/* 0xc84: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_c89:
	/* 0xc89: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c90:
	/* 0xc90: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c95:
	/* 0xc95: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_c9c:
	/* 0xc9c: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ca1:
	/* 0xca1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca3:
	/* 0xca3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ca6:
	/* 0xca6: je     16be <generic_retkprobe_filter_arg+0x16be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5822ULL;
	}
x86_l_cac:
	/* 0xcac: mov    ecx,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_caf:
	/* 0xcaf: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cb4:
	/* 0xcb4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cb9:
	/* 0xcb9: jmp    167e <generic_retkprobe_filter_arg+0x167e> */
	return 5758ULL;
x86_l_cbe:
	/* 0xcbe: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_cc1:
	/* 0xcc1: jne    1b08 <generic_retkprobe_filter_arg+0x1b08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6920ULL;
	}
x86_l_cc7:
	/* 0xcc7: test   QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ccb:
	/* 0xccb: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_cd1:
	/* 0xcd1: jmp    1b08 <generic_retkprobe_filter_arg+0x1b08> */
	return 6920ULL;
x86_l_cd6:
	/* 0xcd6: movzx  edx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_cd9:
	/* 0xcd9: mov    WORD PTR [rsp+0x7e],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_cde:
	/* 0xcde: movzx  edx,WORD PTR [rsi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_ce2:
	/* 0xce2: mov    WORD PTR [rsp+0x78],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ce7:
	/* 0xce7: mov    rdx,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ceb:
	/* 0xceb: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cf0:
	/* 0xcf0: mov    rdx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cf4:
	/* 0xcf4: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cf9:
	/* 0xcf9: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cfe:
	/* 0xcfe: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d00:
	/* 0xd00: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_d03:
	/* 0xd03: jle    d2c <generic_retkprobe_filter_arg+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3372ULL;
	}
x86_l_d05:
	/* 0xd05: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_d08:
	/* 0xd08: jg     d5e <generic_retkprobe_filter_arg+0xd5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3422ULL;
	}
x86_l_d0a:
	/* 0xd0a: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_d0d:
	/* 0xd0d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d10:
	/* 0xd10: jb     12c2 <generic_retkprobe_filter_arg+0x12c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4802ULL;
	}
x86_l_d16:
	/* 0xd16: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_d19:
	/* 0xd19: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_d1e:
	/* 0xd1e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d21:
	/* 0xd21: jb     12bb <generic_retkprobe_filter_arg+0x12bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4795ULL;
	}
	return 3367ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3367ULL: goto x86_l_d27;
	case 3372ULL: goto x86_l_d2c;
	case 3375ULL: goto x86_l_d2f;
	case 3381ULL: goto x86_l_d35;
	case 3384ULL: goto x86_l_d38;
	case 3390ULL: goto x86_l_d3e;
	case 3393ULL: goto x86_l_d41;
	case 3399ULL: goto x86_l_d47;
	case 3404ULL: goto x86_l_d4c;
	case 3407ULL: goto x86_l_d4f;
	case 3413ULL: goto x86_l_d55;
	case 3417ULL: goto x86_l_d59;
	case 3422ULL: goto x86_l_d5e;
	case 3425ULL: goto x86_l_d61;
	case 3431ULL: goto x86_l_d67;
	case 3434ULL: goto x86_l_d6a;
	case 3440ULL: goto x86_l_d70;
	case 3445ULL: goto x86_l_d75;
	case 3448ULL: goto x86_l_d78;
	case 3454ULL: goto x86_l_d7e;
	case 3459ULL: goto x86_l_d83;
	case 3462ULL: goto x86_l_d86;
	case 3465ULL: goto x86_l_d89;
	case 3471ULL: goto x86_l_d8f;
	case 3474ULL: goto x86_l_d92;
	case 3480ULL: goto x86_l_d98;
	case 3484ULL: goto x86_l_d9c;
	case 3488ULL: goto x86_l_da0;
	case 3491ULL: goto x86_l_da3;
	case 3493ULL: goto x86_l_da5;
	case 3496ULL: goto x86_l_da8;
	case 3502ULL: goto x86_l_dae;
	case 3506ULL: goto x86_l_db2;
	case 3509ULL: goto x86_l_db5;
	case 3515ULL: goto x86_l_dbb;
	case 3518ULL: goto x86_l_dbe;
	case 3524ULL: goto x86_l_dc4;
	case 3529ULL: goto x86_l_dc9;
	case 3532ULL: goto x86_l_dcc;
	case 3538ULL: goto x86_l_dd2;
	case 3543ULL: goto x86_l_dd7;
	case 3546ULL: goto x86_l_dda;
	case 3552ULL: goto x86_l_de0;
	case 3557ULL: goto x86_l_de5;
	case 3559ULL: goto x86_l_de7;
	case 3562ULL: goto x86_l_dea;
	case 3567ULL: goto x86_l_def;
	case 3571ULL: goto x86_l_df3;
	case 3576ULL: goto x86_l_df8;
	case 3583ULL: goto x86_l_dff;
	case 3588ULL: goto x86_l_e04;
	case 3590ULL: goto x86_l_e06;
	case 3593ULL: goto x86_l_e09;
	case 3599ULL: goto x86_l_e0f;
	case 3602ULL: goto x86_l_e12;
	case 3607ULL: goto x86_l_e17;
	case 3609ULL: goto x86_l_e19;
	case 3614ULL: goto x86_l_e1e;
	case 3616ULL: goto x86_l_e20;
	case 3618ULL: goto x86_l_e22;
	case 3621ULL: goto x86_l_e25;
	case 3624ULL: goto x86_l_e28;
	case 3627ULL: goto x86_l_e2b;
	case 3629ULL: goto x86_l_e2d;
	case 3631ULL: goto x86_l_e2f;
	case 3635ULL: goto x86_l_e33;
	case 3638ULL: goto x86_l_e36;
	case 3640ULL: goto x86_l_e38;
	case 3644ULL: goto x86_l_e3c;
	case 3646ULL: goto x86_l_e3e;
	case 3648ULL: goto x86_l_e40;
	case 3653ULL: goto x86_l_e45;
	case 3657ULL: goto x86_l_e49;
	case 3660ULL: goto x86_l_e4c;
	case 3664ULL: goto x86_l_e50;
	case 3668ULL: goto x86_l_e54;
	case 3672ULL: goto x86_l_e58;
	case 3676ULL: goto x86_l_e5c;
	case 3679ULL: goto x86_l_e5f;
	case 3683ULL: goto x86_l_e63;
	case 3687ULL: goto x86_l_e67;
	case 3691ULL: goto x86_l_e6b;
	case 3695ULL: goto x86_l_e6f;
	case 3697ULL: goto x86_l_e71;
	case 3700ULL: goto x86_l_e74;
	case 3703ULL: goto x86_l_e77;
	case 3705ULL: goto x86_l_e79;
	case 3707ULL: goto x86_l_e7b;
	case 3709ULL: goto x86_l_e7d;
	case 3715ULL: goto x86_l_e83;
	case 3720ULL: goto x86_l_e88;
	case 3724ULL: goto x86_l_e8c;
	case 3726ULL: goto x86_l_e8e;
	case 3730ULL: goto x86_l_e92;
	case 3733ULL: goto x86_l_e95;
	case 3737ULL: goto x86_l_e99;
	case 3743ULL: goto x86_l_e9f;
	case 3745ULL: goto x86_l_ea1;
	case 3750ULL: goto x86_l_ea6;
	case 3755ULL: goto x86_l_eab;
	case 3759ULL: goto x86_l_eaf;
	case 3763ULL: goto x86_l_eb3;
	case 3774ULL: goto x86_l_ebe;
	case 3779ULL: goto x86_l_ec3;
	case 3786ULL: goto x86_l_eca;
	case 3791ULL: goto x86_l_ecf;
	case 3793ULL: goto x86_l_ed1;
	case 3796ULL: goto x86_l_ed4;
	case 3802ULL: goto x86_l_eda;
	case 3807ULL: goto x86_l_edf;
	case 3810ULL: goto x86_l_ee2;
	case 3816ULL: goto x86_l_ee8;
	case 3819ULL: goto x86_l_eeb;
	case 3824ULL: goto x86_l_ef0;
	case 3831ULL: goto x86_l_ef7;
	case 3836ULL: goto x86_l_efc;
	case 3838ULL: goto x86_l_efe;
	case 3841ULL: goto x86_l_f01;
	case 3847ULL: goto x86_l_f07;
	case 3853ULL: goto x86_l_f0d;
	case 3858ULL: goto x86_l_f12;
	case 3861ULL: goto x86_l_f15;
	case 3868ULL: goto x86_l_f1c;
	case 3870ULL: goto x86_l_f1e;
	case 3873ULL: goto x86_l_f21;
	case 3877ULL: goto x86_l_f25;
	case 3882ULL: goto x86_l_f2a;
	case 3884ULL: goto x86_l_f2c;
	case 3889ULL: goto x86_l_f31;
	case 3892ULL: goto x86_l_f34;
	case 3894ULL: goto x86_l_f36;
	case 3899ULL: goto x86_l_f3b;
	case 3902ULL: goto x86_l_f3e;
	case 3905ULL: goto x86_l_f41;
	case 3910ULL: goto x86_l_f46;
	case 3912ULL: goto x86_l_f48;
	case 3917ULL: goto x86_l_f4d;
	case 3928ULL: goto x86_l_f58;
	case 3934ULL: goto x86_l_f5e;
	case 3940ULL: goto x86_l_f64;
	case 3942ULL: goto x86_l_f66;
	case 3946ULL: goto x86_l_f6a;
	case 3950ULL: goto x86_l_f6e;
	case 3956ULL: goto x86_l_f74;
	case 3961ULL: goto x86_l_f79;
	case 3965ULL: goto x86_l_f7d;
	case 3969ULL: goto x86_l_f81;
	case 3972ULL: goto x86_l_f84;
	case 3974ULL: goto x86_l_f86;
	case 3977ULL: goto x86_l_f89;
	case 3983ULL: goto x86_l_f8f;
	case 3987ULL: goto x86_l_f93;
	case 3990ULL: goto x86_l_f96;
	case 3994ULL: goto x86_l_f9a;
	case 3997ULL: goto x86_l_f9d;
	case 4000ULL: goto x86_l_fa0;
	case 4005ULL: goto x86_l_fa5;
	case 4008ULL: goto x86_l_fa8;
	case 4014ULL: goto x86_l_fae;
	case 4017ULL: goto x86_l_fb1;
	case 4023ULL: goto x86_l_fb7;
	case 4028ULL: goto x86_l_fbc;
	case 4031ULL: goto x86_l_fbf;
	case 4037ULL: goto x86_l_fc5;
	case 4042ULL: goto x86_l_fca;
	case 4045ULL: goto x86_l_fcd;
	case 4050ULL: goto x86_l_fd2;
	case 4056ULL: goto x86_l_fd8;
	case 4059ULL: goto x86_l_fdb;
	case 4065ULL: goto x86_l_fe1;
	case 4070ULL: goto x86_l_fe6;
	case 4073ULL: goto x86_l_fe9;
	case 4079ULL: goto x86_l_fef;
	case 4083ULL: goto x86_l_ff3;
	case 4087ULL: goto x86_l_ff7;
	case 4098ULL: goto x86_l_1002;
	case 4103ULL: goto x86_l_1007;
	case 4110ULL: goto x86_l_100e;
	case 4115ULL: goto x86_l_1013;
	case 4117ULL: goto x86_l_1015;
	case 4120ULL: goto x86_l_1018;
	case 4126ULL: goto x86_l_101e;
	case 4129ULL: goto x86_l_1021;
	case 4134ULL: goto x86_l_1026;
	case 4137ULL: goto x86_l_1029;
	case 4143ULL: goto x86_l_102f;
	case 4148ULL: goto x86_l_1034;
	case 4155ULL: goto x86_l_103b;
	case 4160ULL: goto x86_l_1040;
	case 4162ULL: goto x86_l_1042;
	case 4165ULL: goto x86_l_1045;
	case 4171ULL: goto x86_l_104b;
	case 4174ULL: goto x86_l_104e;
	case 4179ULL: goto x86_l_1053;
	case 4182ULL: goto x86_l_1056;
	case 4187ULL: goto x86_l_105b;
	case 4190ULL: goto x86_l_105e;
	case 4193ULL: goto x86_l_1061;
	case 4195ULL: goto x86_l_1063;
	case 4198ULL: goto x86_l_1066;
	case 4201ULL: goto x86_l_1069;
	case 4206ULL: goto x86_l_106e;
	case 4209ULL: goto x86_l_1071;
	case 4212ULL: goto x86_l_1074;
	case 4217ULL: goto x86_l_1079;
	case 4221ULL: goto x86_l_107d;
	case 4227ULL: goto x86_l_1083;
	case 4230ULL: goto x86_l_1086;
	case 4234ULL: goto x86_l_108a;
	case 4240ULL: goto x86_l_1090;
	case 4243ULL: goto x86_l_1093;
	case 4247ULL: goto x86_l_1097;
	case 4250ULL: goto x86_l_109a;
	case 4253ULL: goto x86_l_109d;
	case 4258ULL: goto x86_l_10a2;
	case 4262ULL: goto x86_l_10a6;
	case 4268ULL: goto x86_l_10ac;
	case 4272ULL: goto x86_l_10b0;
	case 4276ULL: goto x86_l_10b4;
	case 4279ULL: goto x86_l_10b7;
	case 4281ULL: goto x86_l_10b9;
	case 4285ULL: goto x86_l_10bd;
	case 4291ULL: goto x86_l_10c3;
	case 4295ULL: goto x86_l_10c7;
	case 4299ULL: goto x86_l_10cb;
	case 4302ULL: goto x86_l_10ce;
	case 4304ULL: goto x86_l_10d0;
	case 4308ULL: goto x86_l_10d4;
	case 4314ULL: goto x86_l_10da;
	case 4318ULL: goto x86_l_10de;
	case 4322ULL: goto x86_l_10e2;
	case 4325ULL: goto x86_l_10e5;
	case 4327ULL: goto x86_l_10e7;
	case 4331ULL: goto x86_l_10eb;
	case 4333ULL: goto x86_l_10ed;
	case 4337ULL: goto x86_l_10f1;
	case 4343ULL: goto x86_l_10f7;
	case 4347ULL: goto x86_l_10fb;
	case 4350ULL: goto x86_l_10fe;
	case 4354ULL: goto x86_l_1102;
	case 4358ULL: goto x86_l_1106;
	case 4361ULL: goto x86_l_1109;
	case 4363ULL: goto x86_l_110b;
	case 4368ULL: goto x86_l_1110;
	case 4373ULL: goto x86_l_1115;
	case 4378ULL: goto x86_l_111a;
	case 4383ULL: goto x86_l_111f;
	case 4386ULL: goto x86_l_1122;
	case 4392ULL: goto x86_l_1128;
	case 4395ULL: goto x86_l_112b;
	case 4401ULL: goto x86_l_1131;
	case 4406ULL: goto x86_l_1136;
	case 4411ULL: goto x86_l_113b;
	case 4415ULL: goto x86_l_113f;
	case 4421ULL: goto x86_l_1145;
	case 4431ULL: goto x86_l_114f;
	case 4435ULL: goto x86_l_1153;
	case 4441ULL: goto x86_l_1159;
	case 4444ULL: goto x86_l_115c;
	case 4450ULL: goto x86_l_1162;
	case 4454ULL: goto x86_l_1166;
	case 4456ULL: goto x86_l_1168;
	case 4461ULL: goto x86_l_116d;
	case 4465ULL: goto x86_l_1171;
	case 4471ULL: goto x86_l_1177;
	case 4481ULL: goto x86_l_1181;
	case 4485ULL: goto x86_l_1185;
	case 4491ULL: goto x86_l_118b;
	case 4494ULL: goto x86_l_118e;
	case 4500ULL: goto x86_l_1194;
	case 4504ULL: goto x86_l_1198;
	case 4508ULL: goto x86_l_119c;
	case 4510ULL: goto x86_l_119e;
	case 4514ULL: goto x86_l_11a2;
	case 4520ULL: goto x86_l_11a8;
	case 4524ULL: goto x86_l_11ac;
	case 4527ULL: goto x86_l_11af;
	case 4533ULL: goto x86_l_11b5;
	case 4537ULL: goto x86_l_11b9;
	case 4539ULL: goto x86_l_11bb;
	case 4543ULL: goto x86_l_11bf;
	case 4549ULL: goto x86_l_11c5;
	case 4552ULL: goto x86_l_11c8;
	case 4558ULL: goto x86_l_11ce;
	case 4562ULL: goto x86_l_11d2;
	case 4564ULL: goto x86_l_11d4;
	case 4568ULL: goto x86_l_11d8;
	case 4574ULL: goto x86_l_11de;
	case 4577ULL: goto x86_l_11e1;
	case 4583ULL: goto x86_l_11e7;
	case 4587ULL: goto x86_l_11eb;
	case 4593ULL: goto x86_l_11f1;
	case 4597ULL: goto x86_l_11f5;
	case 4603ULL: goto x86_l_11fb;
	case 4608ULL: goto x86_l_1200;
	case 4611ULL: goto x86_l_1203;
	case 4613ULL: goto x86_l_1205;
	case 4616ULL: goto x86_l_1208;
	case 4622ULL: goto x86_l_120e;
	case 4626ULL: goto x86_l_1212;
	case 4632ULL: goto x86_l_1218;
	case 4637ULL: goto x86_l_121d;
	case 4640ULL: goto x86_l_1220;
	case 4645ULL: goto x86_l_1225;
	case 4651ULL: goto x86_l_122b;
	case 4655ULL: goto x86_l_122f;
	case 4661ULL: goto x86_l_1235;
	case 4664ULL: goto x86_l_1238;
	case 4667ULL: goto x86_l_123b;
	case 4670ULL: goto x86_l_123e;
	case 4672ULL: goto x86_l_1240;
	case 4674ULL: goto x86_l_1242;
	case 4677ULL: goto x86_l_1245;
	case 4679ULL: goto x86_l_1247;
	case 4681ULL: goto x86_l_1249;
	case 4683ULL: goto x86_l_124b;
	case 4685ULL: goto x86_l_124d;
	case 4688ULL: goto x86_l_1250;
	case 4690ULL: goto x86_l_1252;
	case 4692ULL: goto x86_l_1254;
	case 4694ULL: goto x86_l_1256;
	case 4697ULL: goto x86_l_1259;
	case 4701ULL: goto x86_l_125d;
	case 4707ULL: goto x86_l_1263;
	case 4710ULL: goto x86_l_1266;
	case 4716ULL: goto x86_l_126c;
	case 4719ULL: goto x86_l_126f;
	case 4721ULL: goto x86_l_1271;
	case 4726ULL: goto x86_l_1276;
	case 4730ULL: goto x86_l_127a;
	case 4734ULL: goto x86_l_127e;
	case 4737ULL: goto x86_l_1281;
	case 4743ULL: goto x86_l_1287;
	case 4748ULL: goto x86_l_128c;
	case 4751ULL: goto x86_l_128f;
	case 4757ULL: goto x86_l_1295;
	case 4760ULL: goto x86_l_1298;
	case 4762ULL: goto x86_l_129a;
	case 4766ULL: goto x86_l_129e;
	case 4768ULL: goto x86_l_12a0;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4779ULL: goto x86_l_12ab;
	case 4781ULL: goto x86_l_12ad;
	case 4786ULL: goto x86_l_12b2;
	case 4789ULL: goto x86_l_12b5;
	case 4795ULL: goto x86_l_12bb;
	case 4800ULL: goto x86_l_12c0;
	case 4802ULL: goto x86_l_12c2;
	case 4807ULL: goto x86_l_12c7;
	case 4809ULL: goto x86_l_12c9;
	case 4811ULL: goto x86_l_12cb;
	case 4814ULL: goto x86_l_12ce;
	case 4816ULL: goto x86_l_12d0;
	case 4819ULL: goto x86_l_12d3;
	case 4821ULL: goto x86_l_12d5;
	case 4824ULL: goto x86_l_12d8;
	case 4827ULL: goto x86_l_12db;
	case 4833ULL: goto x86_l_12e1;
	case 4836ULL: goto x86_l_12e4;
	case 4839ULL: goto x86_l_12e7;
	case 4845ULL: goto x86_l_12ed;
	case 4848ULL: goto x86_l_12f0;
	case 4854ULL: goto x86_l_12f6;
	case 4859ULL: goto x86_l_12fb;
	case 4862ULL: goto x86_l_12fe;
	case 4868ULL: goto x86_l_1304;
	case 4873ULL: goto x86_l_1309;
	case 4876ULL: goto x86_l_130c;
	case 4882ULL: goto x86_l_1312;
	case 4885ULL: goto x86_l_1315;
	case 4891ULL: goto x86_l_131b;
	case 4894ULL: goto x86_l_131e;
	case 4900ULL: goto x86_l_1324;
	case 4902ULL: goto x86_l_1326;
	case 4907ULL: goto x86_l_132b;
	case 4911ULL: goto x86_l_132f;
	case 4915ULL: goto x86_l_1333;
	case 4917ULL: goto x86_l_1335;
	case 4920ULL: goto x86_l_1338;
	case 4924ULL: goto x86_l_133c;
	case 4927ULL: goto x86_l_133f;
	case 4931ULL: goto x86_l_1343;
	case 4934ULL: goto x86_l_1346;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d27:
	/* 0xd27: jmp    24c <generic_retkprobe_filter_arg+0x24c> */
	return 588ULL;
x86_l_d2c:
	/* 0xd2c: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_d2f:
	/* 0xd2f: jle    fa5 <generic_retkprobe_filter_arg+0xfa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_fa5;
	}
x86_l_d35:
	/* 0xd35: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_d38:
	/* 0xd38: jg     12a8 <generic_retkprobe_filter_arg+0x12a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_12a8;
	}
x86_l_d3e:
	/* 0xd3e: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_d41:
	/* 0xd41: je     12bb <generic_retkprobe_filter_arg+0x12bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12bb;
	}
x86_l_d47:
	/* 0xd47: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_d4c:
	/* 0xd4c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_d4f:
	/* 0xd4f: jne    24c <generic_retkprobe_filter_arg+0x24c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 588ULL;
	}
x86_l_d55:
	/* 0xd55: movzx  ebx,WORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_d59:
	/* 0xd59: jmp    1a6b <generic_retkprobe_filter_arg+0x1a6b> */
	return 6763ULL;
x86_l_d5e:
	/* 0xd5e: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_d61:
	/* 0xd61: jg     12fb <generic_retkprobe_filter_arg+0x12fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_12fb;
	}
x86_l_d67:
	/* 0xd67: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_d6a:
	/* 0xd6a: je     1335 <generic_retkprobe_filter_arg+0x1335> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1335;
	}
x86_l_d70:
	/* 0xd70: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_d75:
	/* 0xd75: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_d78:
	/* 0xd78: je     132b <generic_retkprobe_filter_arg+0x132b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_132b;
	}
x86_l_d7e:
	/* 0xd7e: jmp    24c <generic_retkprobe_filter_arg+0x24c> */
	return 588ULL;
x86_l_d83:
	/* 0xd83: lea    edx,[rax-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_d86:
	/* 0xd86: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_d89:
	/* 0xd89: jae    17cf <generic_retkprobe_filter_arg+0x17cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6095ULL;
	}
x86_l_d8f:
	/* 0xd8f: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_d92:
	/* 0xd92: jne    f79 <generic_retkprobe_filter_arg+0xf79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f79;
	}
x86_l_d98:
	/* 0xd98: mov    rsi,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d9c:
	/* 0xd9c: mov    rdx,QWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_da0:
	/* 0xda0: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_da3:
	/* 0xda3: je     dae <generic_retkprobe_filter_arg+0xdae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dae;
	}
x86_l_da5:
	/* 0xda5: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_da8:
	/* 0xda8: jne    19cc <generic_retkprobe_filter_arg+0x19cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6604ULL;
	}
x86_l_dae:
	/* 0xdae: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db2:
	/* 0xdb2: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_db5:
	/* 0xdb5: jg     19de <generic_retkprobe_filter_arg+0x19de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6622ULL;
	}
x86_l_dbb:
	/* 0xdbb: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_dbe:
	/* 0xdbe: jle    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 610ULL;
	}
x86_l_dc4:
	/* 0xdc4: jmp    19de <generic_retkprobe_filter_arg+0x19de> */
	return 6622ULL;
x86_l_dc9:
	/* 0xdc9: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_dcc:
	/* 0xdcc: je     13f9 <generic_retkprobe_filter_arg+0x13f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5113ULL;
	}
x86_l_dd2:
	/* 0xdd2: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_dd7:
	/* 0xdd7: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_dda:
	/* 0xdda: jne    2c49 <generic_retkprobe_filter_arg+0x2c49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11337ULL;
	}
x86_l_de0:
	/* 0xde0: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_de5:
	/* 0xde5: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_de7:
	/* 0xde7: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dea:
	/* 0xdea: mov    eax,DWORD PTR [r15+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_def:
	/* 0xdef: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_df3:
	/* 0xdf3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_df8:
	/* 0xdf8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_dff:
	/* 0xdff: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e04:
	/* 0xe04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e06:
	/* 0xe06: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e09:
	/* 0xe09: je     2160 <generic_retkprobe_filter_arg+0x2160> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8544ULL;
	}
x86_l_e0f:
	/* 0xe0f: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_e12:
	/* 0xe12: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e17:
	/* 0xe17: je     e83 <generic_retkprobe_filter_arg+0xe83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e83;
	}
x86_l_e19:
	/* 0xe19: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e1e:
	/* 0xe1e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e20:
	/* 0xe20: jmp    e2d <generic_retkprobe_filter_arg+0xe2d> */
	goto x86_l_e2d;
x86_l_e22:
	/* 0xe22: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e25:
	/* 0xe25: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e28:
	/* 0xe28: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_e2b:
	/* 0xe2b: je     e83 <generic_retkprobe_filter_arg+0xe83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e83;
	}
x86_l_e2d:
	/* 0xe2d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e2f:
	/* 0xe2f: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_e33:
	/* 0xe33: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_e36:
	/* 0xe36: jae    e22 <generic_retkprobe_filter_arg+0xe22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e22;
	}
x86_l_e38:
	/* 0xe38: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_e3c:
	/* 0xe3c: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_e3e:
	/* 0xe3e: je     e7b <generic_retkprobe_filter_arg+0xe7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e7b;
	}
x86_l_e40:
	/* 0xe40: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_e45:
	/* 0xe45: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_e49:
	/* 0xe49: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_e4c:
	/* 0xe4c: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_e50:
	/* 0xe50: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_e54:
	/* 0xe54: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_e58:
	/* 0xe58: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_e5c:
	/* 0xe5c: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_e5f:
	/* 0xe5f: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_e63:
	/* 0xe63: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_e67:
	/* 0xe67: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_e6b:
	/* 0xe6b: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_e6f:
	/* 0xe6f: ja     e22 <generic_retkprobe_filter_arg+0xe22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e22;
	}
x86_l_e71:
	/* 0xe71: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e74:
	/* 0xe74: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_e77:
	/* 0xe77: je     e2f <generic_retkprobe_filter_arg+0xe2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e2f;
	}
x86_l_e79:
	/* 0xe79: jmp    e22 <generic_retkprobe_filter_arg+0xe22> */
	goto x86_l_e22;
x86_l_e7b:
	/* 0xe7b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e7d:
	/* 0xe7d: jns    2423 <generic_retkprobe_filter_arg+0x2423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9251ULL;
	}
x86_l_e83:
	/* 0xe83: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_e88:
	/* 0xe88: cmp    eax,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_e8c:
	/* 0xe8c: jae    e9f <generic_retkprobe_filter_arg+0xe9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e9f;
	}
x86_l_e8e:
	/* 0xe8e: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_e92:
	/* 0xe92: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e95:
	/* 0xe95: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_e99:
	/* 0xe99: jne    dea <generic_retkprobe_filter_arg+0xdea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_dea;
	}
x86_l_e9f:
	/* 0xe9f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ea1:
	/* 0xea1: jmp    2428 <generic_retkprobe_filter_arg+0x2428> */
	return 9256ULL;
x86_l_ea6:
	/* 0xea6: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_eab:
	/* 0xeab: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eaf:
	/* 0xeaf: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_eb3:
	/* 0xeb3: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_ebe:
	/* 0xebe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ec3:
	/* 0xec3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_eca:
	/* 0xeca: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ecf:
	/* 0xecf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed1:
	/* 0xed1: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_ed4:
	/* 0xed4: je     2c38 <generic_retkprobe_filter_arg+0x2c38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11320ULL;
	}
x86_l_eda:
	/* 0xeda: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_edf:
	/* 0xedf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ee2:
	/* 0xee2: je     2c3a <generic_retkprobe_filter_arg+0x2c3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11322ULL;
	}
x86_l_ee8:
	/* 0xee8: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_eeb:
	/* 0xeeb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ef0:
	/* 0xef0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_ef7:
	/* 0xef7: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_efc:
	/* 0xefc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_efe:
	/* 0xefe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f01:
	/* 0xf01: je     2c38 <generic_retkprobe_filter_arg+0x2c38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11320ULL;
	}
x86_l_f07:
	/* 0xf07: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_f0d:
	/* 0xf0d: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_f12:
	/* 0xf12: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_f15:
	/* 0xf15: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_f1c:
	/* 0xf1c: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f1e:
	/* 0xf1e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f21:
	/* 0xf21: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_f25:
	/* 0xf25: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f2a:
	/* 0xf2a: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_f2c:
	/* 0xf2c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f31:
	/* 0xf31: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_f34:
	/* 0xf34: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f36:
	/* 0xf36: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f3b:
	/* 0xf3b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f3e:
	/* 0xf3e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_f41:
	/* 0xf41: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f46:
	/* 0xf46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f48:
	/* 0xf48: jmp    2c2e <generic_retkprobe_filter_arg+0x2c2e> */
	return 11310ULL;
x86_l_f4d:
	/* 0xf4d: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_f58:
	/* 0xf58: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_f5e:
	/* 0xf5e: jbe    149f <generic_retkprobe_filter_arg+0x149f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 5279ULL;
	}
x86_l_f64:
	/* 0xf64: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f66:
	/* 0xf66: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f6a:
	/* 0xf6a: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_f6e:
	/* 0xf6e: jbe    2c57 <generic_retkprobe_filter_arg+0x2c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11351ULL;
	}
x86_l_f74:
	/* 0xf74: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_f79:
	/* 0xf79: mov    rsi,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f7d:
	/* 0xf7d: mov    rax,QWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f81:
	/* 0xf81: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_f84:
	/* 0xf84: je     f8f <generic_retkprobe_filter_arg+0xf8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8f;
	}
x86_l_f86:
	/* 0xf86: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f89:
	/* 0xf89: jne    1a1d <generic_retkprobe_filter_arg+0x1a1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6685ULL;
	}
x86_l_f8f:
	/* 0xf8f: mov    rdx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f93:
	/* 0xf93: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_f96:
	/* 0xf96: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_f9a:
	/* 0xf9a: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_f9d:
	/* 0xf9d: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_fa0:
	/* 0xfa0: jmp    1a2e <generic_retkprobe_filter_arg+0x1a2e> */
	return 6702ULL;
x86_l_fa5:
	/* 0xfa5: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_fa8:
	/* 0xfa8: je     1335 <generic_retkprobe_filter_arg+0x1335> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1335;
	}
x86_l_fae:
	/* 0xfae: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_fb1:
	/* 0xfb1: je     132b <generic_retkprobe_filter_arg+0x132b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_132b;
	}
x86_l_fb7:
	/* 0xfb7: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_fbc:
	/* 0xfbc: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_fbf:
	/* 0xfbf: je     12c2 <generic_retkprobe_filter_arg+0x12c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c2;
	}
x86_l_fc5:
	/* 0xfc5: jmp    24c <generic_retkprobe_filter_arg+0x24c> */
	return 588ULL;
x86_l_fca:
	/* 0xfca: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_fcd:
	/* 0xfcd: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fd2:
	/* 0xfd2: jg     1540 <generic_retkprobe_filter_arg+0x1540> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5440ULL;
	}
x86_l_fd8:
	/* 0xfd8: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_fdb:
	/* 0xfdb: je     1713 <generic_retkprobe_filter_arg+0x1713> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5907ULL;
	}
x86_l_fe1:
	/* 0xfe1: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_fe6:
	/* 0xfe6: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_fe9:
	/* 0xfe9: jne    2ed7 <generic_retkprobe_filter_arg+0x2ed7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11991ULL;
	}
x86_l_fef:
	/* 0xfef: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ff3:
	/* 0xff3: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ff7:
	/* 0xff7: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1002:
	/* 0x1002: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1007:
	/* 0x1007: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_100e:
	/* 0x100e: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1013:
	/* 0x1013: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1015:
	/* 0x1015: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_1018:
	/* 0x1018: je     2ec6 <generic_retkprobe_filter_arg+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11974ULL;
	}
x86_l_101e:
	/* 0x101e: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1021:
	/* 0x1021: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1026:
	/* 0x1026: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1029:
	/* 0x1029: je     2ec8 <generic_retkprobe_filter_arg+0x2ec8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11976ULL;
	}
x86_l_102f:
	/* 0x102f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1034:
	/* 0x1034: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_103b:
	/* 0x103b: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1040:
	/* 0x1040: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1042:
	/* 0x1042: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1045:
	/* 0x1045: je     2ec6 <generic_retkprobe_filter_arg+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11974ULL;
	}
x86_l_104b:
	/* 0x104b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_104e:
	/* 0x104e: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1053:
	/* 0x1053: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_1056:
	/* 0x1056: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_105b:
	/* 0x105b: cmovb  ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_105e:
	/* 0x105e: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1061:
	/* 0x1061: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1063:
	/* 0x1063: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1066:
	/* 0x1066: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1069:
	/* 0x1069: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_106e:
	/* 0x106e: sub    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1071:
	/* 0x1071: lea    eax,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_1074:
	/* 0x1074: mov    QWORD PTR [rsp+0x50],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1079:
	/* 0x1079: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_107d:
	/* 0x107d: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1083:
	/* 0x1083: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1086:
	/* 0x1086: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_108a:
	/* 0x108a: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_1090:
	/* 0x1090: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1093:
	/* 0x1093: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1097:
	/* 0x1097: lea    ebx,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_109a:
	/* 0x109a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_109d:
	/* 0x109d: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10a2:
	/* 0x10a2: lea    ebp,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_10a6:
	/* 0x10a6: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10ac:
	/* 0x10ac: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_10b0:
	/* 0x10b0: mov    BYTE PTR [rdi-0x3],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_10b4:
	/* 0x10b4: cmp    r10,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R12, X86_WIDTH_64);
x86_l_10b7:
	/* 0x10b7: je     110b <generic_retkprobe_filter_arg+0x110b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_110b;
	}
x86_l_10b9:
	/* 0x10b9: lea    ebp,[r11+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_10bd:
	/* 0x10bd: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10c3:
	/* 0x10c3: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_10c7:
	/* 0x10c7: mov    BYTE PTR [rdi-0x2],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_10cb:
	/* 0x10cb: cmp    r8,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R12, X86_WIDTH_64);
x86_l_10ce:
	/* 0x10ce: je     110b <generic_retkprobe_filter_arg+0x110b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_110b;
	}
x86_l_10d0:
	/* 0x10d0: lea    ebp,[r9+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_10d4:
	/* 0x10d4: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10da:
	/* 0x10da: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_10de:
	/* 0x10de: mov    BYTE PTR [rdi-0x1],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_10e2:
	/* 0x10e2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_10e5:
	/* 0x10e5: je     110b <generic_retkprobe_filter_arg+0x110b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_110b;
	}
x86_l_10e7:
	/* 0x10e7: cmp    r12,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_10eb:
	/* 0x10eb: je     110b <generic_retkprobe_filter_arg+0x110b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_110b;
	}
x86_l_10ed:
	/* 0x10ed: lea    ebp,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_10f1:
	/* 0x10f1: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10f7:
	/* 0x10f7: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_10fb:
	/* 0x10fb: mov    BYTE PTR [rdi],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10fe:
	/* 0x10fe: add    r12,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1102:
	/* 0x1102: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1106:
	/* 0x1106: cmp    rcx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1109:
	/* 0x1109: jne    10a2 <generic_retkprobe_filter_arg+0x10a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10a2;
	}
x86_l_110b:
	/* 0x110b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1110:
	/* 0x1110: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1115:
	/* 0x1115: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_111a:
	/* 0x111a: jmp    2eba <generic_retkprobe_filter_arg+0x2eba> */
	return 11962ULL;
x86_l_111f:
	/* 0x111f: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1122:
	/* 0x1122: jne    20a6 <generic_retkprobe_filter_arg+0x20a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8358ULL;
	}
x86_l_1128:
	/* 0x1128: test   DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_112b:
	/* 0x112b: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_1131:
	/* 0x1131: jmp    20a6 <generic_retkprobe_filter_arg+0x20a6> */
	return 8358ULL;
x86_l_1136:
	/* 0x1136: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_113b:
	/* 0x113b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_113f:
	/* 0x113f: jb     1614 <generic_retkprobe_filter_arg+0x1614> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5652ULL;
	}
x86_l_1145:
	/* 0x1145: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_114f:
	/* 0x114f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1153:
	/* 0x1153: jae    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 177ULL;
	}
x86_l_1159:
	/* 0x1159: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_115c:
	/* 0x115c: jne    1cda <generic_retkprobe_filter_arg+0x1cda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7386ULL;
	}
x86_l_1162:
	/* 0x1162: movzx  eax,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1166:
	/* 0x1166: jmp    1198 <generic_retkprobe_filter_arg+0x1198> */
	goto x86_l_1198;
x86_l_1168:
	/* 0x1168: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_116d:
	/* 0x116d: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1171:
	/* 0x1171: jb     164c <generic_retkprobe_filter_arg+0x164c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5708ULL;
	}
x86_l_1177:
	/* 0x1177: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_1181:
	/* 0x1181: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1185:
	/* 0x1185: jae    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 177ULL;
	}
x86_l_118b:
	/* 0x118b: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_118e:
	/* 0x118e: jne    1ce4 <generic_retkprobe_filter_arg+0x1ce4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7396ULL;
	}
x86_l_1194:
	/* 0x1194: movzx  eax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1198:
	/* 0x1198: cmp    DWORD PTR [r15+0x10],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_119c:
	/* 0x119c: ja     11a8 <generic_retkprobe_filter_arg+0x11a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11a8;
	}
x86_l_119e:
	/* 0x119e: cmp    DWORD PTR [r15+0x14],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_11a2:
	/* 0x11a2: jae    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 610ULL;
	}
x86_l_11a8:
	/* 0x11a8: mov    ecx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11ac:
	/* 0x11ac: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_11af:
	/* 0x11af: jb     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 177ULL;
	}
x86_l_11b5:
	/* 0x11b5: cmp    DWORD PTR [r15+0x18],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11b9:
	/* 0x11b9: ja     11c5 <generic_retkprobe_filter_arg+0x11c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11c5;
	}
x86_l_11bb:
	/* 0x11bb: cmp    DWORD PTR [r15+0x1c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_11bf:
	/* 0x11bf: jae    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 610ULL;
	}
x86_l_11c5:
	/* 0x11c5: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_11c8:
	/* 0x11c8: jb     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 177ULL;
	}
x86_l_11ce:
	/* 0x11ce: cmp    DWORD PTR [r15+0x20],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11d2:
	/* 0x11d2: ja     11de <generic_retkprobe_filter_arg+0x11de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11de;
	}
x86_l_11d4:
	/* 0x11d4: cmp    DWORD PTR [r15+0x24],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_11d8:
	/* 0x11d8: jae    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 610ULL;
	}
x86_l_11de:
	/* 0x11de: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_11e1:
	/* 0x11e1: jb     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 177ULL;
	}
x86_l_11e7:
	/* 0x11e7: cmp    DWORD PTR [r15+0x28],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11eb:
	/* 0x11eb: ja     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 177ULL;
	}
x86_l_11f1:
	/* 0x11f1: cmp    DWORD PTR [r15+0x2c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_11f5:
	/* 0x11f5: jae    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 610ULL;
	}
x86_l_11fb:
	/* 0x11fb: jmp    b1 <generic_retkprobe_filter_arg+0xb1> */
	return 177ULL;
x86_l_1200:
	/* 0x1200: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1203:
	/* 0x1203: je     120e <generic_retkprobe_filter_arg+0x120e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_120e;
	}
x86_l_1205:
	/* 0x1205: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1208:
	/* 0x1208: jne    1af2 <generic_retkprobe_filter_arg+0x1af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6898ULL;
	}
x86_l_120e:
	/* 0x120e: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1212:
	/* 0x1212: jg     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 610ULL;
	}
x86_l_1218:
	/* 0x1218: jmp    1b08 <generic_retkprobe_filter_arg+0x1b08> */
	return 6920ULL;
x86_l_121d:
	/* 0x121d: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1220:
	/* 0x1220: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1225:
	/* 0x1225: ja     183b <generic_retkprobe_filter_arg+0x183b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6203ULL;
	}
x86_l_122b:
	/* 0x122b: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_122f:
	/* 0x122f: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1235:
	/* 0x1235: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1238:
	/* 0x1238: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_123b:
	/* 0x123b: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_123e:
	/* 0x123e: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1240:
	/* 0x1240: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1242:
	/* 0x1242: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1245:
	/* 0x1245: je     124d <generic_retkprobe_filter_arg+0x124d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_124d;
	}
x86_l_1247:
	/* 0x1247: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1249:
	/* 0x1249: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_124b:
	/* 0x124b: je     1263 <generic_retkprobe_filter_arg+0x1263> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1263;
	}
x86_l_124d:
	/* 0x124d: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1250:
	/* 0x1250: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1252:
	/* 0x1252: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1254:
	/* 0x1254: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1256:
	/* 0x1256: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1259:
	/* 0x1259: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_125d:
	/* 0x125d: ja     1850 <generic_retkprobe_filter_arg+0x1850> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6224ULL;
	}
x86_l_1263:
	/* 0x1263: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1266:
	/* 0x1266: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_126c:
	/* 0x126c: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_126f:
	/* 0x126f: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1271:
	/* 0x1271: jmp    1860 <generic_retkprobe_filter_arg+0x1860> */
	return 6240ULL;
x86_l_1276:
	/* 0x1276: mov    esi,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_127a:
	/* 0x127a: mov    eax,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_127e:
	/* 0x127e: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1281:
	/* 0x1281: ja     1f56 <generic_retkprobe_filter_arg+0x1f56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8022ULL;
	}
x86_l_1287:
	/* 0x1287: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_128c:
	/* 0x128c: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_128f:
	/* 0x128f: jae    1f56 <generic_retkprobe_filter_arg+0x1f56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8022ULL;
	}
x86_l_1295:
	/* 0x1295: mov    edx,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1298:
	/* 0x1298: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_129a:
	/* 0x129a: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_129e:
	/* 0x129e: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_12a0:
	/* 0x12a0: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_12a3:
	/* 0x12a3: jmp    1f64 <generic_retkprobe_filter_arg+0x1f64> */
	return 8036ULL;
x86_l_12a8:
	/* 0x12a8: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_12ab:
	/* 0x12ab: je     12c2 <generic_retkprobe_filter_arg+0x12c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c2;
	}
x86_l_12ad:
	/* 0x12ad: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_12b2:
	/* 0x12b2: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_12b5:
	/* 0x12b5: jne    24c <generic_retkprobe_filter_arg+0x24c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 588ULL;
	}
x86_l_12bb:
	/* 0x12bb: movzx  r12d,WORD PTR [rsi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_12c0:
	/* 0x12c0: jmp    12c7 <generic_retkprobe_filter_arg+0x12c7> */
	goto x86_l_12c7;
x86_l_12c2:
	/* 0x12c2: movzx  r12d,WORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_12c7:
	/* 0x12c7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12c9:
	/* 0x12c9: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12cb:
	/* 0x12cb: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12ce:
	/* 0x12ce: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12d0:
	/* 0x12d0: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_12d3:
	/* 0x12d3: jg     134d <generic_retkprobe_filter_arg+0x134d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4941ULL;
	}
x86_l_12d5:
	/* 0x12d5: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_12d8:
	/* 0x12d8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_12db:
	/* 0x12db: jb     1380 <generic_retkprobe_filter_arg+0x1380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4992ULL;
	}
x86_l_12e1:
	/* 0x12e1: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_12e4:
	/* 0x12e4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_12e7:
	/* 0x12e7: jb     1505 <generic_retkprobe_filter_arg+0x1505> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5381ULL;
	}
x86_l_12ed:
	/* 0x12ed: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_12f0:
	/* 0x12f0: je     1a6b <generic_retkprobe_filter_arg+0x1a6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6763ULL;
	}
x86_l_12f6:
	/* 0x12f6: jmp    24c <generic_retkprobe_filter_arg+0x24c> */
	return 588ULL;
x86_l_12fb:
	/* 0x12fb: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_12fe:
	/* 0x12fe: je     1a67 <generic_retkprobe_filter_arg+0x1a67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6759ULL;
	}
x86_l_1304:
	/* 0x1304: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1309:
	/* 0x1309: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_130c:
	/* 0x130c: jne    24c <generic_retkprobe_filter_arg+0x24c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 588ULL;
	}
x86_l_1312:
	/* 0x1312: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1315:
	/* 0x1315: jne    203b <generic_retkprobe_filter_arg+0x203b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8251ULL;
	}
x86_l_131b:
	/* 0x131b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_131e:
	/* 0x131e: jne    2047 <generic_retkprobe_filter_arg+0x2047> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8263ULL;
	}
x86_l_1324:
	/* 0x1324: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1326:
	/* 0x1326: jmp    2059 <generic_retkprobe_filter_arg+0x2059> */
	return 8281ULL;
x86_l_132b:
	/* 0x132b: mov    rdx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_132f:
	/* 0x132f: mov    r8,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1333:
	/* 0x1333: jmp    133c <generic_retkprobe_filter_arg+0x133c> */
	goto x86_l_133c;
x86_l_1335:
	/* 0x1335: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1338:
	/* 0x1338: mov    r8,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_133c:
	/* 0x133c: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_133f:
	/* 0x133f: shr    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1343:
	/* 0x1343: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1346:
	/* 0x1346: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
	return 4936ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4936ULL: goto x86_l_1348;
	case 4939ULL: goto x86_l_134b;
	case 4941ULL: goto x86_l_134d;
	case 4944ULL: goto x86_l_1350;
	case 4950ULL: goto x86_l_1356;
	case 4955ULL: goto x86_l_135b;
	case 4958ULL: goto x86_l_135e;
	case 4964ULL: goto x86_l_1364;
	case 4969ULL: goto x86_l_1369;
	case 4972ULL: goto x86_l_136c;
	case 4978ULL: goto x86_l_1372;
	case 4983ULL: goto x86_l_1377;
	case 4986ULL: goto x86_l_137a;
	case 4992ULL: goto x86_l_1380;
	case 4996ULL: goto x86_l_1384;
	case 4999ULL: goto x86_l_1387;
	case 5005ULL: goto x86_l_138d;
	case 5008ULL: goto x86_l_1390;
	case 5014ULL: goto x86_l_1396;
	case 5017ULL: goto x86_l_1399;
	case 5021ULL: goto x86_l_139d;
	case 5025ULL: goto x86_l_13a1;
	case 5030ULL: goto x86_l_13a6;
	case 5037ULL: goto x86_l_13ad;
	case 5042ULL: goto x86_l_13b2;
	case 5044ULL: goto x86_l_13b4;
	case 5047ULL: goto x86_l_13b7;
	case 5053ULL: goto x86_l_13bd;
	case 5064ULL: goto x86_l_13c8;
	case 5071ULL: goto x86_l_13cf;
	case 5076ULL: goto x86_l_13d4;
	case 5079ULL: goto x86_l_13d7;
	case 5085ULL: goto x86_l_13dd;
	case 5090ULL: goto x86_l_13e2;
	case 5093ULL: goto x86_l_13e5;
	case 5099ULL: goto x86_l_13eb;
	case 5102ULL: goto x86_l_13ee;
	case 5108ULL: goto x86_l_13f4;
	case 5113ULL: goto x86_l_13f9;
	case 5118ULL: goto x86_l_13fe;
	case 5120ULL: goto x86_l_1400;
	case 5123ULL: goto x86_l_1403;
	case 5128ULL: goto x86_l_1408;
	case 5132ULL: goto x86_l_140c;
	case 5137ULL: goto x86_l_1411;
	case 5144ULL: goto x86_l_1418;
	case 5149ULL: goto x86_l_141d;
	case 5151ULL: goto x86_l_141f;
	case 5154ULL: goto x86_l_1422;
	case 5160ULL: goto x86_l_1428;
	case 5163ULL: goto x86_l_142b;
	case 5168ULL: goto x86_l_1430;
	case 5173ULL: goto x86_l_1435;
	case 5175ULL: goto x86_l_1437;
	case 5180ULL: goto x86_l_143c;
	case 5182ULL: goto x86_l_143e;
	case 5184ULL: goto x86_l_1440;
	case 5187ULL: goto x86_l_1443;
	case 5190ULL: goto x86_l_1446;
	case 5193ULL: goto x86_l_1449;
	case 5195ULL: goto x86_l_144b;
	case 5197ULL: goto x86_l_144d;
	case 5201ULL: goto x86_l_1451;
	case 5204ULL: goto x86_l_1454;
	case 5206ULL: goto x86_l_1456;
	case 5210ULL: goto x86_l_145a;
	case 5213ULL: goto x86_l_145d;
	case 5215ULL: goto x86_l_145f;
	case 5219ULL: goto x86_l_1463;
	case 5221ULL: goto x86_l_1465;
	case 5225ULL: goto x86_l_1469;
	case 5229ULL: goto x86_l_146d;
	case 5232ULL: goto x86_l_1470;
	case 5234ULL: goto x86_l_1472;
	case 5236ULL: goto x86_l_1474;
	case 5238ULL: goto x86_l_1476;
	case 5244ULL: goto x86_l_147c;
	case 5249ULL: goto x86_l_1481;
	case 5253ULL: goto x86_l_1485;
	case 5255ULL: goto x86_l_1487;
	case 5259ULL: goto x86_l_148b;
	case 5262ULL: goto x86_l_148e;
	case 5266ULL: goto x86_l_1492;
	case 5272ULL: goto x86_l_1498;
	case 5274ULL: goto x86_l_149a;
	case 5279ULL: goto x86_l_149f;
	case 5282ULL: goto x86_l_14a2;
	case 5287ULL: goto x86_l_14a7;
	case 5293ULL: goto x86_l_14ad;
	case 5297ULL: goto x86_l_14b1;
	case 5303ULL: goto x86_l_14b7;
	case 5306ULL: goto x86_l_14ba;
	case 5309ULL: goto x86_l_14bd;
	case 5312ULL: goto x86_l_14c0;
	case 5314ULL: goto x86_l_14c2;
	case 5316ULL: goto x86_l_14c4;
	case 5319ULL: goto x86_l_14c7;
	case 5321ULL: goto x86_l_14c9;
	case 5323ULL: goto x86_l_14cb;
	case 5325ULL: goto x86_l_14cd;
	case 5327ULL: goto x86_l_14cf;
	case 5330ULL: goto x86_l_14d2;
	case 5332ULL: goto x86_l_14d4;
	case 5334ULL: goto x86_l_14d6;
	case 5336ULL: goto x86_l_14d8;
	case 5339ULL: goto x86_l_14db;
	case 5343ULL: goto x86_l_14df;
	case 5349ULL: goto x86_l_14e5;
	case 5353ULL: goto x86_l_14e9;
	case 5359ULL: goto x86_l_14ef;
	case 5362ULL: goto x86_l_14f2;
	case 5364ULL: goto x86_l_14f4;
	case 5369ULL: goto x86_l_14f9;
	case 5372ULL: goto x86_l_14fc;
	case 5375ULL: goto x86_l_14ff;
	case 5381ULL: goto x86_l_1505;
	case 5386ULL: goto x86_l_150a;
	case 5390ULL: goto x86_l_150e;
	case 5395ULL: goto x86_l_1513;
	case 5402ULL: goto x86_l_151a;
	case 5407ULL: goto x86_l_151f;
	case 5409ULL: goto x86_l_1521;
	case 5412ULL: goto x86_l_1524;
	case 5418ULL: goto x86_l_152a;
	case 5422ULL: goto x86_l_152e;
	case 5430ULL: goto x86_l_1536;
	case 5435ULL: goto x86_l_153b;
	case 5440ULL: goto x86_l_1540;
	case 5443ULL: goto x86_l_1543;
	case 5449ULL: goto x86_l_1549;
	case 5454ULL: goto x86_l_154e;
	case 5457ULL: goto x86_l_1551;
	case 5463ULL: goto x86_l_1557;
	case 5469ULL: goto x86_l_155d;
	case 5473ULL: goto x86_l_1561;
	case 5477ULL: goto x86_l_1565;
	case 5482ULL: goto x86_l_156a;
	case 5489ULL: goto x86_l_1571;
	case 5494ULL: goto x86_l_1576;
	case 5496ULL: goto x86_l_1578;
	case 5499ULL: goto x86_l_157b;
	case 5505ULL: goto x86_l_1581;
	case 5510ULL: goto x86_l_1586;
	case 5513ULL: goto x86_l_1589;
	case 5516ULL: goto x86_l_158c;
	case 5521ULL: goto x86_l_1591;
	case 5523ULL: goto x86_l_1593;
	case 5529ULL: goto x86_l_1599;
	case 5533ULL: goto x86_l_159d;
	case 5538ULL: goto x86_l_15a2;
	case 5542ULL: goto x86_l_15a6;
	case 5547ULL: goto x86_l_15ab;
	case 5552ULL: goto x86_l_15b0;
	case 5557ULL: goto x86_l_15b5;
	case 5563ULL: goto x86_l_15bb;
	case 5568ULL: goto x86_l_15c0;
	case 5575ULL: goto x86_l_15c7;
	case 5577ULL: goto x86_l_15c9;
	case 5582ULL: goto x86_l_15ce;
	case 5585ULL: goto x86_l_15d1;
	case 5591ULL: goto x86_l_15d7;
	case 5594ULL: goto x86_l_15da;
	case 5600ULL: goto x86_l_15e0;
	case 5604ULL: goto x86_l_15e4;
	case 5606ULL: goto x86_l_15e6;
	case 5612ULL: goto x86_l_15ec;
	case 5617ULL: goto x86_l_15f1;
	case 5620ULL: goto x86_l_15f4;
	case 5626ULL: goto x86_l_15fa;
	case 5629ULL: goto x86_l_15fd;
	case 5635ULL: goto x86_l_1603;
	case 5639ULL: goto x86_l_1607;
	case 5641ULL: goto x86_l_1609;
	case 5647ULL: goto x86_l_160f;
	case 5652ULL: goto x86_l_1614;
	case 5657ULL: goto x86_l_1619;
	case 5664ULL: goto x86_l_1620;
	case 5669ULL: goto x86_l_1625;
	case 5676ULL: goto x86_l_162c;
	case 5681ULL: goto x86_l_1631;
	case 5683ULL: goto x86_l_1633;
	case 5686ULL: goto x86_l_1636;
	case 5692ULL: goto x86_l_163c;
	case 5696ULL: goto x86_l_1640;
	case 5701ULL: goto x86_l_1645;
	case 5706ULL: goto x86_l_164a;
	case 5708ULL: goto x86_l_164c;
	case 5713ULL: goto x86_l_1651;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5732ULL: goto x86_l_1664;
	case 5737ULL: goto x86_l_1669;
	case 5739ULL: goto x86_l_166b;
	case 5742ULL: goto x86_l_166e;
	case 5744ULL: goto x86_l_1670;
	case 5748ULL: goto x86_l_1674;
	case 5753ULL: goto x86_l_1679;
	case 5758ULL: goto x86_l_167e;
	case 5761ULL: goto x86_l_1681;
	case 5766ULL: goto x86_l_1686;
	case 5768ULL: goto x86_l_1688;
	case 5772ULL: goto x86_l_168c;
	case 5774ULL: goto x86_l_168e;
	case 5777ULL: goto x86_l_1691;
	case 5783ULL: goto x86_l_1697;
	case 5788ULL: goto x86_l_169c;
	case 5791ULL: goto x86_l_169f;
	case 5796ULL: goto x86_l_16a4;
	case 5801ULL: goto x86_l_16a9;
	case 5806ULL: goto x86_l_16ae;
	case 5808ULL: goto x86_l_16b0;
	case 5811ULL: goto x86_l_16b3;
	case 5814ULL: goto x86_l_16b6;
	case 5817ULL: goto x86_l_16b9;
	case 5822ULL: goto x86_l_16be;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5834ULL: goto x86_l_16ca;
	case 5839ULL: goto x86_l_16cf;
	case 5844ULL: goto x86_l_16d4;
	case 5849ULL: goto x86_l_16d9;
	case 5852ULL: goto x86_l_16dc;
	case 5854ULL: goto x86_l_16de;
	case 5857ULL: goto x86_l_16e1;
	case 5860ULL: goto x86_l_16e4;
	case 5863ULL: goto x86_l_16e7;
	case 5868ULL: goto x86_l_16ec;
	case 5871ULL: goto x86_l_16ef;
	case 5874ULL: goto x86_l_16f2;
	case 5879ULL: goto x86_l_16f7;
	case 5884ULL: goto x86_l_16fc;
	case 5889ULL: goto x86_l_1701;
	case 5892ULL: goto x86_l_1704;
	case 5897ULL: goto x86_l_1709;
	case 5899ULL: goto x86_l_170b;
	case 5902ULL: goto x86_l_170e;
	case 5907ULL: goto x86_l_1713;
	case 5911ULL: goto x86_l_1717;
	case 5915ULL: goto x86_l_171b;
	case 5926ULL: goto x86_l_1726;
	case 5931ULL: goto x86_l_172b;
	case 5938ULL: goto x86_l_1732;
	case 5943ULL: goto x86_l_1737;
	case 5945ULL: goto x86_l_1739;
	case 5948ULL: goto x86_l_173c;
	case 5954ULL: goto x86_l_1742;
	case 5957ULL: goto x86_l_1745;
	case 5962ULL: goto x86_l_174a;
	case 5965ULL: goto x86_l_174d;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5983ULL: goto x86_l_175f;
	case 5988ULL: goto x86_l_1764;
	case 5990ULL: goto x86_l_1766;
	case 5993ULL: goto x86_l_1769;
	case 5999ULL: goto x86_l_176f;
	case 6005ULL: goto x86_l_1775;
	case 6010ULL: goto x86_l_177a;
	case 6013ULL: goto x86_l_177d;
	case 6020ULL: goto x86_l_1784;
	case 6022ULL: goto x86_l_1786;
	case 6025ULL: goto x86_l_1789;
	case 6029ULL: goto x86_l_178d;
	case 6034ULL: goto x86_l_1792;
	case 6039ULL: goto x86_l_1797;
	case 6042ULL: goto x86_l_179a;
	case 6045ULL: goto x86_l_179d;
	case 6047ULL: goto x86_l_179f;
	case 6052ULL: goto x86_l_17a4;
	case 6055ULL: goto x86_l_17a7;
	case 6058ULL: goto x86_l_17aa;
	case 6060ULL: goto x86_l_17ac;
	case 6065ULL: goto x86_l_17b1;
	case 6076ULL: goto x86_l_17bc;
	case 6082ULL: goto x86_l_17c2;
	case 6088ULL: goto x86_l_17c8;
	case 6090ULL: goto x86_l_17ca;
	case 6095ULL: goto x86_l_17cf;
	case 6098ULL: goto x86_l_17d2;
	case 6104ULL: goto x86_l_17d8;
	case 6108ULL: goto x86_l_17dc;
	case 6111ULL: goto x86_l_17df;
	case 6113ULL: goto x86_l_17e1;
	case 6122ULL: goto x86_l_17ea;
	case 6128ULL: goto x86_l_17f0;
	case 6132ULL: goto x86_l_17f4;
	case 6140ULL: goto x86_l_17fc;
	case 6145ULL: goto x86_l_1801;
	case 6147ULL: goto x86_l_1803;
	case 6157ULL: goto x86_l_180d;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6169ULL: goto x86_l_1819;
	case 6171ULL: goto x86_l_181b;
	case 6176ULL: goto x86_l_1820;
	case 6179ULL: goto x86_l_1823;
	case 6184ULL: goto x86_l_1828;
	case 6188ULL: goto x86_l_182c;
	case 6190ULL: goto x86_l_182e;
	case 6195ULL: goto x86_l_1833;
	case 6198ULL: goto x86_l_1836;
	case 6203ULL: goto x86_l_183b;
	case 6206ULL: goto x86_l_183e;
	case 6211ULL: goto x86_l_1843;
	case 6216ULL: goto x86_l_1848;
	case 6221ULL: goto x86_l_184d;
	case 6224ULL: goto x86_l_1850;
	case 6227ULL: goto x86_l_1853;
	case 6229ULL: goto x86_l_1855;
	case 6234ULL: goto x86_l_185a;
	case 6237ULL: goto x86_l_185d;
	case 6240ULL: goto x86_l_1860;
	case 6242ULL: goto x86_l_1862;
	case 6245ULL: goto x86_l_1865;
	case 6250ULL: goto x86_l_186a;
	case 6253ULL: goto x86_l_186d;
	case 6259ULL: goto x86_l_1873;
	case 6263ULL: goto x86_l_1877;
	case 6267ULL: goto x86_l_187b;
	case 6271ULL: goto x86_l_187f;
	case 6276ULL: goto x86_l_1884;
	case 6283ULL: goto x86_l_188b;
	case 6288ULL: goto x86_l_1890;
	case 6291ULL: goto x86_l_1893;
	case 6293ULL: goto x86_l_1895;
	case 6296ULL: goto x86_l_1898;
	case 6301ULL: goto x86_l_189d;
	case 6308ULL: goto x86_l_18a4;
	case 6311ULL: goto x86_l_18a7;
	case 6313ULL: goto x86_l_18a9;
	case 6316ULL: goto x86_l_18ac;
	case 6322ULL: goto x86_l_18b2;
	case 6327ULL: goto x86_l_18b7;
	case 6330ULL: goto x86_l_18ba;
	case 6335ULL: goto x86_l_18bf;
	case 6340ULL: goto x86_l_18c4;
	case 6345ULL: goto x86_l_18c9;
	case 6351ULL: goto x86_l_18cf;
	case 6354ULL: goto x86_l_18d2;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6371ULL: goto x86_l_18e3;
	case 6376ULL: goto x86_l_18e8;
	case 6381ULL: goto x86_l_18ed;
	case 6387ULL: goto x86_l_18f3;
	case 6390ULL: goto x86_l_18f6;
	case 6393ULL: goto x86_l_18f9;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6404ULL: goto x86_l_1904;
	case 6406ULL: goto x86_l_1906;
	case 6408ULL: goto x86_l_1908;
	case 6414ULL: goto x86_l_190e;
	case 6418ULL: goto x86_l_1912;
	case 6421ULL: goto x86_l_1915;
	case 6423ULL: goto x86_l_1917;
	case 6429ULL: goto x86_l_191d;
	case 6434ULL: goto x86_l_1922;
	case 6439ULL: goto x86_l_1927;
	case 6442ULL: goto x86_l_192a;
	case 6445ULL: goto x86_l_192d;
	case 6449ULL: goto x86_l_1931;
	case 6453ULL: goto x86_l_1935;
	case 6458ULL: goto x86_l_193a;
	case 6465ULL: goto x86_l_1941;
	case 6470ULL: goto x86_l_1946;
	case 6472ULL: goto x86_l_1948;
	case 6475ULL: goto x86_l_194b;
	case 6481ULL: goto x86_l_1951;
	case 6492ULL: goto x86_l_195c;
	case 6499ULL: goto x86_l_1963;
	case 6506ULL: goto x86_l_196a;
	case 6514ULL: goto x86_l_1972;
	case 6518ULL: goto x86_l_1976;
	case 6526ULL: goto x86_l_197e;
	case 6531ULL: goto x86_l_1983;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6541ULL: goto x86_l_198d;
	case 6545ULL: goto x86_l_1991;
	case 6548ULL: goto x86_l_1994;
	case 6551ULL: goto x86_l_1997;
	case 6557ULL: goto x86_l_199d;
	case 6560ULL: goto x86_l_19a0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1348:
	/* 0x1348: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_134b:
	/* 0x134b: jle    12d5 <generic_retkprobe_filter_arg+0x12d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4821ULL;
	}
x86_l_134d:
	/* 0x134d: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1350:
	/* 0x1350: ja     14f9 <generic_retkprobe_filter_arg+0x14f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_14f9;
	}
x86_l_1356:
	/* 0x1356: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_135b:
	/* 0x135b: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_135e:
	/* 0x135e: jb     1815 <generic_retkprobe_filter_arg+0x1815> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1815;
	}
x86_l_1364:
	/* 0x1364: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_1369:
	/* 0x1369: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_136c:
	/* 0x136c: jb     1828 <generic_retkprobe_filter_arg+0x1828> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1828;
	}
x86_l_1372:
	/* 0x1372: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_1377:
	/* 0x1377: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_137a:
	/* 0x137a: jae    14f9 <generic_retkprobe_filter_arg+0x14f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_14f9;
	}
x86_l_1380:
	/* 0x1380: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1384:
	/* 0x1384: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1387:
	/* 0x1387: je     1927 <generic_retkprobe_filter_arg+0x1927> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1927;
	}
x86_l_138d:
	/* 0x138d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1390:
	/* 0x1390: jne    19c2 <generic_retkprobe_filter_arg+0x19c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6594ULL;
	}
x86_l_1396:
	/* 0x1396: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_1399:
	/* 0x1399: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_139d:
	/* 0x139d: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_13a1:
	/* 0x13a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13a6:
	/* 0x13a6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_13ad:
	/* 0x13ad: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_13b2:
	/* 0x13b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b4:
	/* 0x13b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13b7:
	/* 0x13b7: je     1bba <generic_retkprobe_filter_arg+0x1bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7098ULL;
	}
x86_l_13bd:
	/* 0x13bd: mov    DWORD PTR [rsp+0x80],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813920ULL);
x86_l_13c8:
	/* 0x13c8: mov    DWORD PTR [rsp+0x84],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_13cf:
	/* 0x13cf: jmp    197e <generic_retkprobe_filter_arg+0x197e> */
	goto x86_l_197e;
x86_l_13d4:
	/* 0x13d4: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_13d7:
	/* 0x13d7: ja     2092 <generic_retkprobe_filter_arg+0x2092> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8338ULL;
	}
x86_l_13dd:
	/* 0x13dd: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_13e2:
	/* 0x13e2: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_13e5:
	/* 0x13e5: jae    2092 <generic_retkprobe_filter_arg+0x2092> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8338ULL;
	}
x86_l_13eb:
	/* 0x13eb: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ee:
	/* 0x13ee: jg     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 610ULL;
	}
x86_l_13f4:
	/* 0x13f4: jmp    20a6 <generic_retkprobe_filter_arg+0x20a6> */
	return 8358ULL;
x86_l_13f9:
	/* 0x13f9: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13fe:
	/* 0x13fe: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1400:
	/* 0x1400: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1403:
	/* 0x1403: mov    eax,DWORD PTR [r15+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_1408:
	/* 0x1408: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_140c:
	/* 0x140c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1411:
	/* 0x1411: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1418:
	/* 0x1418: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_141d:
	/* 0x141d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_141f:
	/* 0x141f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1422:
	/* 0x1422: je     214f <generic_retkprobe_filter_arg+0x214f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8527ULL;
	}
x86_l_1428:
	/* 0x1428: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_142b:
	/* 0x142b: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1430:
	/* 0x1430: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1435:
	/* 0x1435: je     147c <generic_retkprobe_filter_arg+0x147c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_147c;
	}
x86_l_1437:
	/* 0x1437: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_143c:
	/* 0x143c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_143e:
	/* 0x143e: jmp    144b <generic_retkprobe_filter_arg+0x144b> */
	goto x86_l_144b;
x86_l_1440:
	/* 0x1440: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1443:
	/* 0x1443: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1446:
	/* 0x1446: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1449:
	/* 0x1449: je     147c <generic_retkprobe_filter_arg+0x147c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_147c;
	}
x86_l_144b:
	/* 0x144b: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_144d:
	/* 0x144d: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1451:
	/* 0x1451: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1454:
	/* 0x1454: jae    1440 <generic_retkprobe_filter_arg+0x1440> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1440;
	}
x86_l_1456:
	/* 0x1456: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_145a:
	/* 0x145a: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_145d:
	/* 0x145d: je     1474 <generic_retkprobe_filter_arg+0x1474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1474;
	}
x86_l_145f:
	/* 0x145f: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1463:
	/* 0x1463: ja     1440 <generic_retkprobe_filter_arg+0x1440> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1440;
	}
x86_l_1465:
	/* 0x1465: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1469:
	/* 0x1469: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_146d:
	/* 0x146d: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1470:
	/* 0x1470: je     144d <generic_retkprobe_filter_arg+0x144d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_144d;
	}
x86_l_1472:
	/* 0x1472: jmp    1440 <generic_retkprobe_filter_arg+0x1440> */
	goto x86_l_1440;
x86_l_1474:
	/* 0x1474: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1476:
	/* 0x1476: jns    2401 <generic_retkprobe_filter_arg+0x2401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9217ULL;
	}
x86_l_147c:
	/* 0x147c: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1481:
	/* 0x1481: cmp    eax,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1485:
	/* 0x1485: jae    1498 <generic_retkprobe_filter_arg+0x1498> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1498;
	}
x86_l_1487:
	/* 0x1487: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_148b:
	/* 0x148b: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_148e:
	/* 0x148e: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_1492:
	/* 0x1492: jne    1403 <generic_retkprobe_filter_arg+0x1403> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1403;
	}
x86_l_1498:
	/* 0x1498: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_149a:
	/* 0x149a: jmp    2406 <generic_retkprobe_filter_arg+0x2406> */
	return 9222ULL;
x86_l_149f:
	/* 0x149f: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_14a2:
	/* 0x14a2: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_14a7:
	/* 0x14a7: ja     1bc9 <generic_retkprobe_filter_arg+0x1bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7113ULL;
	}
x86_l_14ad:
	/* 0x14ad: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_14b1:
	/* 0x14b1: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_14b7:
	/* 0x14b7: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_14ba:
	/* 0x14ba: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_14bd:
	/* 0x14bd: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_14c0:
	/* 0x14c0: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_14c2:
	/* 0x14c2: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_14c4:
	/* 0x14c4: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_14c7:
	/* 0x14c7: je     14cf <generic_retkprobe_filter_arg+0x14cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14cf;
	}
x86_l_14c9:
	/* 0x14c9: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_14cb:
	/* 0x14cb: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_14cd:
	/* 0x14cd: je     14e5 <generic_retkprobe_filter_arg+0x14e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14e5;
	}
x86_l_14cf:
	/* 0x14cf: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_14d2:
	/* 0x14d2: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_14d4:
	/* 0x14d4: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_14d6:
	/* 0x14d6: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_14d8:
	/* 0x14d8: add    esi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_14db:
	/* 0x14db: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_14df:
	/* 0x14df: ja     1bde <generic_retkprobe_filter_arg+0x1bde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7134ULL;
	}
x86_l_14e5:
	/* 0x14e5: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_14e9:
	/* 0x14e9: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_14ef:
	/* 0x14ef: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_14f2:
	/* 0x14f2: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_14f4:
	/* 0x14f4: jmp    1bee <generic_retkprobe_filter_arg+0x1bee> */
	return 7150ULL;
x86_l_14f9:
	/* 0x14f9: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_14fc:
	/* 0x14fc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14ff:
	/* 0x14ff: jae    24c <generic_retkprobe_filter_arg+0x24c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 588ULL;
	}
x86_l_1505:
	/* 0x1505: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_150a:
	/* 0x150a: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_150e:
	/* 0x150e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1513:
	/* 0x1513: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_151a:
	/* 0x151a: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_151f:
	/* 0x151f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1521:
	/* 0x1521: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1524:
	/* 0x1524: je     23b <generic_retkprobe_filter_arg+0x23b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 571ULL;
	}
x86_l_152a:
	/* 0x152a: movzx  ecx,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_152e:
	/* 0x152e: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1536:
	/* 0x1536: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_153b:
	/* 0x153b: jmp    1aa0 <generic_retkprobe_filter_arg+0x1aa0> */
	return 6816ULL;
x86_l_1540:
	/* 0x1540: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1543:
	/* 0x1543: je     1d5c <generic_retkprobe_filter_arg+0x1d5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7516ULL;
	}
x86_l_1549:
	/* 0x1549: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_154e:
	/* 0x154e: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_1551:
	/* 0x1551: jne    2ed7 <generic_retkprobe_filter_arg+0x2ed7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11991ULL;
	}
x86_l_1557:
	/* 0x1557: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_155d:
	/* 0x155d: mov    eax,DWORD PTR [r15+r12*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1561:
	/* 0x1561: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1565:
	/* 0x1565: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_156a:
	/* 0x156a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1571:
	/* 0x1571: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1576:
	/* 0x1576: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1578:
	/* 0x1578: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_157b:
	/* 0x157b: je     2ec6 <generic_retkprobe_filter_arg+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11974ULL;
	}
x86_l_1581:
	/* 0x1581: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1586:
	/* 0x1586: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1589:
	/* 0x1589: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_158c:
	/* 0x158c: call   0 <generic_retkprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 5521ULL);
	return 12134ULL;
x86_l_1591:
	/* 0x1591: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1593:
	/* 0x1593: jns    2704 <generic_retkprobe_filter_arg+0x2704> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9988ULL;
	}
x86_l_1599:
	/* 0x1599: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_159d:
	/* 0x159d: lea    eax,[r12-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_15a2:
	/* 0x15a2: cmp    eax,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_15a6:
	/* 0x15a6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ab:
	/* 0x15ab: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15b0:
	/* 0x15b0: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15b5:
	/* 0x15b5: jae    17c8 <generic_retkprobe_filter_arg+0x17c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_17c8;
	}
x86_l_15bb:
	/* 0x15bb: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_15c0:
	/* 0x15c0: cmp    r12,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 416ULL);
x86_l_15c7:
	/* 0x15c7: jne    155d <generic_retkprobe_filter_arg+0x155d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_155d;
	}
x86_l_15c9:
	/* 0x15c9: jmp    2ed7 <generic_retkprobe_filter_arg+0x2ed7> */
	return 11991ULL;
x86_l_15ce:
	/* 0x15ce: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15d1:
	/* 0x15d1: je     1e5c <generic_retkprobe_filter_arg+0x1e5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7772ULL;
	}
x86_l_15d7:
	/* 0x15d7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15da:
	/* 0x15da: jne    1e68 <generic_retkprobe_filter_arg+0x1e68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7784ULL;
	}
x86_l_15e0:
	/* 0x15e0: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_15e4:
	/* 0x15e4: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_15e6:
	/* 0x15e6: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_15ec:
	/* 0x15ec: jmp    1e68 <generic_retkprobe_filter_arg+0x1e68> */
	return 7784ULL;
x86_l_15f1:
	/* 0x15f1: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15f4:
	/* 0x15f4: je     1e9f <generic_retkprobe_filter_arg+0x1e9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7839ULL;
	}
x86_l_15fa:
	/* 0x15fa: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15fd:
	/* 0x15fd: jne    1eab <generic_retkprobe_filter_arg+0x1eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7851ULL;
	}
x86_l_1603:
	/* 0x1603: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1607:
	/* 0x1607: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1609:
	/* 0x1609: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_160f:
	/* 0x160f: jmp    1eab <generic_retkprobe_filter_arg+0x1eab> */
	return 7851ULL;
x86_l_1614:
	/* 0x1614: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1619:
	/* 0x1619: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1620:
	/* 0x1620: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1625:
	/* 0x1625: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_162c:
	/* 0x162c: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1631:
	/* 0x1631: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1633:
	/* 0x1633: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1636:
	/* 0x1636: je     16be <generic_retkprobe_filter_arg+0x16be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16be;
	}
x86_l_163c:
	/* 0x163c: movzx  ecx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1640:
	/* 0x1640: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1645:
	/* 0x1645: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_164a:
	/* 0x164a: jmp    167e <generic_retkprobe_filter_arg+0x167e> */
	goto x86_l_167e;
x86_l_164c:
	/* 0x164c: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1651:
	/* 0x1651: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1658:
	/* 0x1658: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_165d:
	/* 0x165d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1664:
	/* 0x1664: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1669:
	/* 0x1669: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166b:
	/* 0x166b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_166e:
	/* 0x166e: je     16be <generic_retkprobe_filter_arg+0x16be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16be;
	}
x86_l_1670:
	/* 0x1670: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1674:
	/* 0x1674: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1679:
	/* 0x1679: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_167e:
	/* 0x167e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1681:
	/* 0x1681: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1686:
	/* 0x1686: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1688:
	/* 0x1688: mov    edx,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_168c:
	/* 0x168c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_168e:
	/* 0x168e: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1691:
	/* 0x1691: ja     2660 <generic_retkprobe_filter_arg+0x2660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9824ULL;
	}
x86_l_1697:
	/* 0x1697: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_169c:
	/* 0x169c: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_169f:
	/* 0x169f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16a4:
	/* 0x16a4: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16a9:
	/* 0x16a9: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16ae:
	/* 0x16ae: jae    16d4 <generic_retkprobe_filter_arg+0x16d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16d4;
	}
x86_l_16b0:
	/* 0x16b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16b3:
	/* 0x16b3: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_16b6:
	/* 0x16b6: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_16b9:
	/* 0x16b9: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_16be:
	/* 0x16be: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16c0:
	/* 0x16c0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16c5:
	/* 0x16c5: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16ca:
	/* 0x16ca: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16cf:
	/* 0x16cf: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_16d4:
	/* 0x16d4: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_16d9:
	/* 0x16d9: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_16dc:
	/* 0x16dc: jae    16e4 <generic_retkprobe_filter_arg+0x16e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_16e4;
	}
x86_l_16de:
	/* 0x16de: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16e1:
	/* 0x16e1: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_16e4:
	/* 0x16e4: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_16e7:
	/* 0x16e7: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_16ec:
	/* 0x16ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16ef:
	/* 0x16ef: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_16f2:
	/* 0x16f2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16f7:
	/* 0x16f7: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16fc:
	/* 0x16fc: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1701:
	/* 0x1701: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1704:
	/* 0x1704: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_1709:
	/* 0x1709: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_170b:
	/* 0x170b: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_170e:
	/* 0x170e: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_1713:
	/* 0x1713: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1717:
	/* 0x1717: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_171b:
	/* 0x171b: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1726:
	/* 0x1726: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_172b:
	/* 0x172b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1732:
	/* 0x1732: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1737:
	/* 0x1737: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1739:
	/* 0x1739: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_173c:
	/* 0x173c: je     2ec6 <generic_retkprobe_filter_arg+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11974ULL;
	}
x86_l_1742:
	/* 0x1742: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1745:
	/* 0x1745: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_174a:
	/* 0x174a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_174d:
	/* 0x174d: je     2ec8 <generic_retkprobe_filter_arg+0x2ec8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11976ULL;
	}
x86_l_1753:
	/* 0x1753: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1758:
	/* 0x1758: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_175f:
	/* 0x175f: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1764:
	/* 0x1764: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1766:
	/* 0x1766: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1769:
	/* 0x1769: je     2ec6 <generic_retkprobe_filter_arg+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11974ULL;
	}
x86_l_176f:
	/* 0x176f: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_1775:
	/* 0x1775: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_177a:
	/* 0x177a: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_177d:
	/* 0x177d: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_1784:
	/* 0x1784: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1786:
	/* 0x1786: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1789:
	/* 0x1789: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_178d:
	/* 0x178d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1792:
	/* 0x1792: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1797:
	/* 0x1797: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_179a:
	/* 0x179a: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_179d:
	/* 0x179d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_179f:
	/* 0x179f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17a4:
	/* 0x17a4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17a7:
	/* 0x17a7: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_17aa:
	/* 0x17aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ac:
	/* 0x17ac: jmp    2ebc <generic_retkprobe_filter_arg+0x2ebc> */
	return 11964ULL;
x86_l_17b1:
	/* 0x17b1: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_17bc:
	/* 0x17bc: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_17c2:
	/* 0x17c2: jbe    1e02 <generic_retkprobe_filter_arg+0x1e02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7682ULL;
	}
x86_l_17c8:
	/* 0x17c8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17ca:
	/* 0x17ca: jmp    2ed7 <generic_retkprobe_filter_arg+0x2ed7> */
	return 11991ULL;
x86_l_17cf:
	/* 0x17cf: cmp    eax,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_17d2:
	/* 0x17d2: jne    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 177ULL;
	}
x86_l_17d8:
	/* 0x17d8: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17dc:
	/* 0x17dc: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_17df:
	/* 0x17df: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_17e1:
	/* 0x17e1: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_17ea:
	/* 0x17ea: jne    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 177ULL;
	}
x86_l_17f0:
	/* 0x17f0: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17f4:
	/* 0x17f4: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_17fc:
	/* 0x17fc: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1801:
	/* 0x1801: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1803:
	/* 0x1803: andn   rax,rcx,QWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ANDN_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 144ULL);
x86_l_180d:
	/* 0x180d: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_1810:
	/* 0x1810: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_1815:
	/* 0x1815: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1819:
	/* 0x1819: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_181b:
	/* 0x181b: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_1820:
	/* 0x1820: setb   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_B);
x86_l_1823:
	/* 0x1823: jmp    24c <generic_retkprobe_filter_arg+0x24c> */
	return 588ULL;
x86_l_1828:
	/* 0x1828: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_182c:
	/* 0x182c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_182e:
	/* 0x182e: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_1833:
	/* 0x1833: setae  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_AE);
x86_l_1836:
	/* 0x1836: jmp    24c <generic_retkprobe_filter_arg+0x24c> */
	return 588ULL;
x86_l_183b:
	/* 0x183b: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_183e:
	/* 0x183e: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1843:
	/* 0x1843: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1848:
	/* 0x1848: mov    eax,0x1fe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 510ULL);
x86_l_184d:
	/* 0x184d: cmovae edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_1850:
	/* 0x1850: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1853:
	/* 0x1853: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1855:
	/* 0x1855: cmp    eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_185a:
	/* 0x185a: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_185d:
	/* 0x185d: xor    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 7ULL);
x86_l_1860:
	/* 0x1860: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1862:
	/* 0x1862: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1865:
	/* 0x1865: mov    eax,DWORD PTR [r15+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_186a:
	/* 0x186a: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_186d:
	/* 0x186d: je     2a9f <generic_retkprobe_filter_arg+0x2a9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10911ULL;
	}
x86_l_1873:
	/* 0x1873: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1877:
	/* 0x1877: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_187b:
	/* 0x187b: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_187f:
	/* 0x187f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1884:
	/* 0x1884: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_188b:
	/* 0x188b: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1890:
	/* 0x1890: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1893:
	/* 0x1893: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1895:
	/* 0x1895: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1898:
	/* 0x1898: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_189d:
	/* 0x189d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_18a4:
	/* 0x18a4: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_18a7:
	/* 0x18a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a9:
	/* 0x18a9: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_18ac:
	/* 0x18ac: je     2a9f <generic_retkprobe_filter_arg+0x2a9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10911ULL;
	}
x86_l_18b2:
	/* 0x18b2: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_18b7:
	/* 0x18b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18ba:
	/* 0x18ba: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18bf:
	/* 0x18bf: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18c4:
	/* 0x18c4: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18c9:
	/* 0x18c9: je     2ab0 <generic_retkprobe_filter_arg+0x2ab0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10928ULL;
	}
x86_l_18cf:
	/* 0x18cf: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_18d2:
	/* 0x18d2: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_18da:
	/* 0x18da: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18df:
	/* 0x18df: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_18e3:
	/* 0x18e3: movzx  ebx,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_18e8:
	/* 0x18e8: cmp    DWORD PTR [rsp+0x28],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691845ULL);
x86_l_18ed:
	/* 0x18ed: jg     21b2 <generic_retkprobe_filter_arg+0x21b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8626ULL;
	}
x86_l_18f3:
	/* 0x18f3: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_18f6:
	/* 0x18f6: mov    BYTE PTR [rcx],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18f9:
	/* 0x18f9: lea    rdi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_18fd:
	/* 0x18fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1902:
	/* 0x1902: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1904:
	/* 0x1904: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1906:
	/* 0x1906: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_1908:
	/* 0x1908: jbe    21ea <generic_retkprobe_filter_arg+0x21ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 8682ULL;
	}
x86_l_190e:
	/* 0x190e: lea    rdi,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1912:
	/* 0x1912: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1915:
	/* 0x1915: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1917:
	/* 0x1917: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_191d:
	/* 0x191d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1922:
	/* 0x1922: jmp    21de <generic_retkprobe_filter_arg+0x21de> */
	return 8670ULL;
x86_l_1927:
	/* 0x1927: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_192a:
	/* 0x192a: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_192d:
	/* 0x192d: mov    eax,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1931:
	/* 0x1931: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1935:
	/* 0x1935: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_193a:
	/* 0x193a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_1941:
	/* 0x1941: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1946:
	/* 0x1946: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1948:
	/* 0x1948: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_194b:
	/* 0x194b: je     1bba <generic_retkprobe_filter_arg+0x1bba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7098ULL;
	}
x86_l_1951:
	/* 0x1951: mov    DWORD PTR [rsp+0x80],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755814016ULL);
x86_l_195c:
	/* 0x195c: mov    DWORD PTR [rsp+0x84],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_1963:
	/* 0x1963: mov    DWORD PTR [rsp+0x88],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_196a:
	/* 0x196a: mov    DWORD PTR [rsp+0x8c],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_1972:
	/* 0x1972: shr    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1976:
	/* 0x1976: mov    DWORD PTR [rsp+0x90],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_197e:
	/* 0x197e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1983:
	/* 0x1983: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1986:
	/* 0x1986: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_198b:
	/* 0x198b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_198d:
	/* 0x198d: mov    ecx,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1991:
	/* 0x1991: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_1994:
	/* 0x1994: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1997:
	/* 0x1997: jb     1ee2 <generic_retkprobe_filter_arg+0x1ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7906ULL;
	}
x86_l_199d:
	/* 0x199d: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_19a0:
	/* 0x19a0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
	return 6563ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6563ULL: goto x86_l_19a3;
	case 6568ULL: goto x86_l_19a8;
	case 6573ULL: goto x86_l_19ad;
	case 6578ULL: goto x86_l_19b2;
	case 6580ULL: goto x86_l_19b4;
	case 6583ULL: goto x86_l_19b7;
	case 6586ULL: goto x86_l_19ba;
	case 6589ULL: goto x86_l_19bd;
	case 6594ULL: goto x86_l_19c2;
	case 6596ULL: goto x86_l_19c4;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6608ULL: goto x86_l_19d0;
	case 6611ULL: goto x86_l_19d3;
	case 6613ULL: goto x86_l_19d5;
	case 6616ULL: goto x86_l_19d8;
	case 6622ULL: goto x86_l_19de;
	case 6626ULL: goto x86_l_19e2;
	case 6629ULL: goto x86_l_19e5;
	case 6635ULL: goto x86_l_19eb;
	case 6639ULL: goto x86_l_19ef;
	case 6643ULL: goto x86_l_19f3;
	case 6646ULL: goto x86_l_19f6;
	case 6648ULL: goto x86_l_19f8;
	case 6651ULL: goto x86_l_19fb;
	case 6657ULL: goto x86_l_1a01;
	case 6660ULL: goto x86_l_1a04;
	case 6665ULL: goto x86_l_1a09;
	case 6671ULL: goto x86_l_1a0f;
	case 6674ULL: goto x86_l_1a12;
	case 6680ULL: goto x86_l_1a18;
	case 6685ULL: goto x86_l_1a1d;
	case 6689ULL: goto x86_l_1a21;
	case 6692ULL: goto x86_l_1a24;
	case 6696ULL: goto x86_l_1a28;
	case 6699ULL: goto x86_l_1a2b;
	case 6702ULL: goto x86_l_1a2e;
	case 6705ULL: goto x86_l_1a31;
	case 6709ULL: goto x86_l_1a35;
	case 6712ULL: goto x86_l_1a38;
	case 6718ULL: goto x86_l_1a3e;
	case 6722ULL: goto x86_l_1a42;
	case 6726ULL: goto x86_l_1a46;
	case 6729ULL: goto x86_l_1a49;
	case 6731ULL: goto x86_l_1a4b;
	case 6734ULL: goto x86_l_1a4e;
	case 6740ULL: goto x86_l_1a54;
	case 6743ULL: goto x86_l_1a57;
	case 6747ULL: goto x86_l_1a5b;
	case 6750ULL: goto x86_l_1a5e;
	case 6754ULL: goto x86_l_1a62;
	case 6759ULL: goto x86_l_1a67;
	case 6763ULL: goto x86_l_1a6b;
	case 6768ULL: goto x86_l_1a70;
	case 6772ULL: goto x86_l_1a74;
	case 6777ULL: goto x86_l_1a79;
	case 6784ULL: goto x86_l_1a80;
	case 6789ULL: goto x86_l_1a85;
	case 6791ULL: goto x86_l_1a87;
	case 6794ULL: goto x86_l_1a8a;
	case 6800ULL: goto x86_l_1a90;
	case 6803ULL: goto x86_l_1a93;
	case 6811ULL: goto x86_l_1a9b;
	case 6816ULL: goto x86_l_1aa0;
	case 6819ULL: goto x86_l_1aa3;
	case 6824ULL: goto x86_l_1aa8;
	case 6826ULL: goto x86_l_1aaa;
	case 6830ULL: goto x86_l_1aae;
	case 6832ULL: goto x86_l_1ab0;
	case 6835ULL: goto x86_l_1ab3;
	case 6841ULL: goto x86_l_1ab9;
	case 6846ULL: goto x86_l_1abe;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6866ULL: goto x86_l_1ad2;
	case 6869ULL: goto x86_l_1ad5;
	case 6872ULL: goto x86_l_1ad8;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6882ULL: goto x86_l_1ae2;
	case 6884ULL: goto x86_l_1ae4;
	case 6887ULL: goto x86_l_1ae7;
	case 6890ULL: goto x86_l_1aea;
	case 6893ULL: goto x86_l_1aed;
	case 6898ULL: goto x86_l_1af2;
	case 6902ULL: goto x86_l_1af6;
	case 6908ULL: goto x86_l_1afc;
	case 6910ULL: goto x86_l_1afe;
	case 6914ULL: goto x86_l_1b02;
	case 6920ULL: goto x86_l_1b08;
	case 6924ULL: goto x86_l_1b0c;
	case 6927ULL: goto x86_l_1b0f;
	case 6933ULL: goto x86_l_1b15;
	case 6937ULL: goto x86_l_1b19;
	case 6940ULL: goto x86_l_1b1c;
	case 6942ULL: goto x86_l_1b1e;
	case 6945ULL: goto x86_l_1b21;
	case 6948ULL: goto x86_l_1b24;
	case 6950ULL: goto x86_l_1b26;
	case 6954ULL: goto x86_l_1b2a;
	case 6959ULL: goto x86_l_1b2f;
	case 6965ULL: goto x86_l_1b35;
	case 6970ULL: goto x86_l_1b3a;
	case 6973ULL: goto x86_l_1b3d;
	case 6979ULL: goto x86_l_1b43;
	case 6982ULL: goto x86_l_1b46;
	case 6988ULL: goto x86_l_1b4c;
	case 6991ULL: goto x86_l_1b4f;
	case 6993ULL: goto x86_l_1b51;
	case 6996ULL: goto x86_l_1b54;
	case 7002ULL: goto x86_l_1b5a;
	case 7006ULL: goto x86_l_1b5e;
	case 7012ULL: goto x86_l_1b64;
	case 7017ULL: goto x86_l_1b69;
	case 7020ULL: goto x86_l_1b6c;
	case 7025ULL: goto x86_l_1b71;
	case 7031ULL: goto x86_l_1b77;
	case 7035ULL: goto x86_l_1b7b;
	case 7041ULL: goto x86_l_1b81;
	case 7046ULL: goto x86_l_1b86;
	case 7049ULL: goto x86_l_1b89;
	case 7055ULL: goto x86_l_1b8f;
	case 7059ULL: goto x86_l_1b93;
	case 7061ULL: goto x86_l_1b95;
	case 7067ULL: goto x86_l_1b9b;
	case 7072ULL: goto x86_l_1ba0;
	case 7075ULL: goto x86_l_1ba3;
	case 7081ULL: goto x86_l_1ba9;
	case 7085ULL: goto x86_l_1bad;
	case 7087ULL: goto x86_l_1baf;
	case 7093ULL: goto x86_l_1bb5;
	case 7098ULL: goto x86_l_1bba;
	case 7102ULL: goto x86_l_1bbe;
	case 7105ULL: goto x86_l_1bc1;
	case 7108ULL: goto x86_l_1bc4;
	case 7113ULL: goto x86_l_1bc9;
	case 7116ULL: goto x86_l_1bcc;
	case 7121ULL: goto x86_l_1bd1;
	case 7126ULL: goto x86_l_1bd6;
	case 7131ULL: goto x86_l_1bdb;
	case 7134ULL: goto x86_l_1bde;
	case 7137ULL: goto x86_l_1be1;
	case 7139ULL: goto x86_l_1be3;
	case 7144ULL: goto x86_l_1be8;
	case 7147ULL: goto x86_l_1beb;
	case 7150ULL: goto x86_l_1bee;
	case 7152ULL: goto x86_l_1bf0;
	case 7155ULL: goto x86_l_1bf3;
	case 7160ULL: goto x86_l_1bf8;
	case 7163ULL: goto x86_l_1bfb;
	case 7169ULL: goto x86_l_1c01;
	case 7176ULL: goto x86_l_1c08;
	case 7180ULL: goto x86_l_1c0c;
	case 7184ULL: goto x86_l_1c10;
	case 7189ULL: goto x86_l_1c15;
	case 7194ULL: goto x86_l_1c1a;
	case 7201ULL: goto x86_l_1c21;
	case 7206ULL: goto x86_l_1c26;
	case 7209ULL: goto x86_l_1c29;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7221ULL: goto x86_l_1c35;
	case 7228ULL: goto x86_l_1c3c;
	case 7231ULL: goto x86_l_1c3f;
	case 7233ULL: goto x86_l_1c41;
	case 7239ULL: goto x86_l_1c47;
	case 7245ULL: goto x86_l_1c4d;
	case 7250ULL: goto x86_l_1c52;
	case 7253ULL: goto x86_l_1c55;
	case 7258ULL: goto x86_l_1c5a;
	case 7263ULL: goto x86_l_1c5f;
	case 7268ULL: goto x86_l_1c64;
	case 7274ULL: goto x86_l_1c6a;
	case 7277ULL: goto x86_l_1c6d;
	case 7282ULL: goto x86_l_1c72;
	case 7288ULL: goto x86_l_1c78;
	case 7293ULL: goto x86_l_1c7d;
	case 7296ULL: goto x86_l_1c80;
	case 7300ULL: goto x86_l_1c84;
	case 7305ULL: goto x86_l_1c89;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7314ULL: goto x86_l_1c92;
	case 7319ULL: goto x86_l_1c97;
	case 7321ULL: goto x86_l_1c99;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7336ULL: goto x86_l_1ca8;
	case 7339ULL: goto x86_l_1cab;
	case 7341ULL: goto x86_l_1cad;
	case 7347ULL: goto x86_l_1cb3;
	case 7352ULL: goto x86_l_1cb8;
	case 7357ULL: goto x86_l_1cbd;
	case 7360ULL: goto x86_l_1cc0;
	case 7362ULL: goto x86_l_1cc2;
	case 7365ULL: goto x86_l_1cc5;
	case 7371ULL: goto x86_l_1ccb;
	case 7375ULL: goto x86_l_1ccf;
	case 7381ULL: goto x86_l_1cd5;
	case 7386ULL: goto x86_l_1cda;
	case 7390ULL: goto x86_l_1cde;
	case 7394ULL: goto x86_l_1ce2;
	case 7396ULL: goto x86_l_1ce4;
	case 7400ULL: goto x86_l_1ce8;
	case 7404ULL: goto x86_l_1cec;
	case 7408ULL: goto x86_l_1cf0;
	case 7412ULL: goto x86_l_1cf4;
	case 7416ULL: goto x86_l_1cf8;
	case 7419ULL: goto x86_l_1cfb;
	case 7422ULL: goto x86_l_1cfe;
	case 7425ULL: goto x86_l_1d01;
	case 7431ULL: goto x86_l_1d07;
	case 7435ULL: goto x86_l_1d0b;
	case 7439ULL: goto x86_l_1d0f;
	case 7443ULL: goto x86_l_1d13;
	case 7447ULL: goto x86_l_1d17;
	case 7450ULL: goto x86_l_1d1a;
	case 7453ULL: goto x86_l_1d1d;
	case 7456ULL: goto x86_l_1d20;
	case 7462ULL: goto x86_l_1d26;
	case 7466ULL: goto x86_l_1d2a;
	case 7470ULL: goto x86_l_1d2e;
	case 7474ULL: goto x86_l_1d32;
	case 7478ULL: goto x86_l_1d36;
	case 7481ULL: goto x86_l_1d39;
	case 7484ULL: goto x86_l_1d3c;
	case 7487ULL: goto x86_l_1d3f;
	case 7493ULL: goto x86_l_1d45;
	case 7497ULL: goto x86_l_1d49;
	case 7500ULL: goto x86_l_1d4c;
	case 7504ULL: goto x86_l_1d50;
	case 7507ULL: goto x86_l_1d53;
	case 7509ULL: goto x86_l_1d55;
	case 7511ULL: goto x86_l_1d57;
	case 7516ULL: goto x86_l_1d5c;
	case 7518ULL: goto x86_l_1d5e;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7530ULL: goto x86_l_1d6a;
	case 7535ULL: goto x86_l_1d6f;
	case 7542ULL: goto x86_l_1d76;
	case 7547ULL: goto x86_l_1d7b;
	case 7549ULL: goto x86_l_1d7d;
	case 7552ULL: goto x86_l_1d80;
	case 7558ULL: goto x86_l_1d86;
	case 7561ULL: goto x86_l_1d89;
	case 7566ULL: goto x86_l_1d8e;
	case 7571ULL: goto x86_l_1d93;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7580ULL: goto x86_l_1d9c;
	case 7582ULL: goto x86_l_1d9e;
	case 7585ULL: goto x86_l_1da1;
	case 7588ULL: goto x86_l_1da4;
	case 7591ULL: goto x86_l_1da7;
	case 7593ULL: goto x86_l_1da9;
	case 7595ULL: goto x86_l_1dab;
	case 7599ULL: goto x86_l_1daf;
	case 7602ULL: goto x86_l_1db2;
	case 7604ULL: goto x86_l_1db4;
	case 7608ULL: goto x86_l_1db8;
	case 7611ULL: goto x86_l_1dbb;
	case 7613ULL: goto x86_l_1dbd;
	case 7617ULL: goto x86_l_1dc1;
	case 7619ULL: goto x86_l_1dc3;
	case 7623ULL: goto x86_l_1dc7;
	case 7627ULL: goto x86_l_1dcb;
	case 7630ULL: goto x86_l_1dce;
	case 7632ULL: goto x86_l_1dd0;
	case 7634ULL: goto x86_l_1dd2;
	case 7636ULL: goto x86_l_1dd4;
	case 7642ULL: goto x86_l_1dda;
	case 7647ULL: goto x86_l_1ddf;
	case 7651ULL: goto x86_l_1de3;
	case 7653ULL: goto x86_l_1de5;
	case 7657ULL: goto x86_l_1de9;
	case 7660ULL: goto x86_l_1dec;
	case 7664ULL: goto x86_l_1df0;
	case 7670ULL: goto x86_l_1df6;
	case 7672ULL: goto x86_l_1df8;
	case 7677ULL: goto x86_l_1dfd;
	case 7682ULL: goto x86_l_1e02;
	case 7685ULL: goto x86_l_1e05;
	case 7690ULL: goto x86_l_1e0a;
	case 7696ULL: goto x86_l_1e10;
	case 7700ULL: goto x86_l_1e14;
	case 7706ULL: goto x86_l_1e1a;
	case 7709ULL: goto x86_l_1e1d;
	case 7712ULL: goto x86_l_1e20;
	case 7715ULL: goto x86_l_1e23;
	case 7717ULL: goto x86_l_1e25;
	case 7719ULL: goto x86_l_1e27;
	case 7722ULL: goto x86_l_1e2a;
	case 7724ULL: goto x86_l_1e2c;
	case 7726ULL: goto x86_l_1e2e;
	case 7728ULL: goto x86_l_1e30;
	case 7730ULL: goto x86_l_1e32;
	case 7733ULL: goto x86_l_1e35;
	case 7735ULL: goto x86_l_1e37;
	case 7737ULL: goto x86_l_1e39;
	case 7739ULL: goto x86_l_1e3b;
	case 7742ULL: goto x86_l_1e3e;
	case 7746ULL: goto x86_l_1e42;
	case 7752ULL: goto x86_l_1e48;
	case 7756ULL: goto x86_l_1e4c;
	case 7762ULL: goto x86_l_1e52;
	case 7765ULL: goto x86_l_1e55;
	case 7767ULL: goto x86_l_1e57;
	case 7772ULL: goto x86_l_1e5c;
	case 7776ULL: goto x86_l_1e60;
	case 7778ULL: goto x86_l_1e62;
	case 7784ULL: goto x86_l_1e68;
	case 7788ULL: goto x86_l_1e6c;
	case 7791ULL: goto x86_l_1e6f;
	case 7797ULL: goto x86_l_1e75;
	case 7801ULL: goto x86_l_1e79;
	case 7804ULL: goto x86_l_1e7c;
	case 7810ULL: goto x86_l_1e82;
	case 7813ULL: goto x86_l_1e85;
	case 7816ULL: goto x86_l_1e88;
	case 7822ULL: goto x86_l_1e8e;
	case 7826ULL: goto x86_l_1e92;
	case 7828ULL: goto x86_l_1e94;
	case 7834ULL: goto x86_l_1e9a;
	case 7839ULL: goto x86_l_1e9f;
	case 7843ULL: goto x86_l_1ea3;
	case 7845ULL: goto x86_l_1ea5;
	case 7851ULL: goto x86_l_1eab;
	case 7855ULL: goto x86_l_1eaf;
	case 7858ULL: goto x86_l_1eb2;
	case 7864ULL: goto x86_l_1eb8;
	case 7868ULL: goto x86_l_1ebc;
	case 7871ULL: goto x86_l_1ebf;
	case 7877ULL: goto x86_l_1ec5;
	case 7880ULL: goto x86_l_1ec8;
	case 7883ULL: goto x86_l_1ecb;
	case 7889ULL: goto x86_l_1ed1;
	case 7893ULL: goto x86_l_1ed5;
	case 7895ULL: goto x86_l_1ed7;
	case 7901ULL: goto x86_l_1edd;
	case 7906ULL: goto x86_l_1ee2;
	case 7909ULL: goto x86_l_1ee5;
	case 7912ULL: goto x86_l_1ee8;
	case 7917ULL: goto x86_l_1eed;
	case 7922ULL: goto x86_l_1ef2;
	case 7927ULL: goto x86_l_1ef7;
	case 7930ULL: goto x86_l_1efa;
	case 7935ULL: goto x86_l_1eff;
	case 7938ULL: goto x86_l_1f02;
	case 7940ULL: goto x86_l_1f04;
	case 7942ULL: goto x86_l_1f06;
	case 7944ULL: goto x86_l_1f08;
	case 7950ULL: goto x86_l_1f0e;
	case 7954ULL: goto x86_l_1f12;
	case 7957ULL: goto x86_l_1f15;
	case 7963ULL: goto x86_l_1f1b;
	case 7967ULL: goto x86_l_1f1f;
	case 7971ULL: goto x86_l_1f23;
	case 7974ULL: goto x86_l_1f26;
	case 7980ULL: goto x86_l_1f2c;
	case 7986ULL: goto x86_l_1f32;
	case 7990ULL: goto x86_l_1f36;
	case 7996ULL: goto x86_l_1f3c;
	case 7998ULL: goto x86_l_1f3e;
	case 8003ULL: goto x86_l_1f43;
	case 8009ULL: goto x86_l_1f49;
	case 8011ULL: goto x86_l_1f4b;
	case 8017ULL: goto x86_l_1f51;
	case 8022ULL: goto x86_l_1f56;
	case 8025ULL: goto x86_l_1f59;
	case 8027ULL: goto x86_l_1f5b;
	case 8031ULL: goto x86_l_1f5f;
	case 8033ULL: goto x86_l_1f61;
	case 8036ULL: goto x86_l_1f64;
	case 8039ULL: goto x86_l_1f67;
	case 8043ULL: goto x86_l_1f6b;
	case 8046ULL: goto x86_l_1f6e;
	case 8052ULL: goto x86_l_1f74;
	case 8056ULL: goto x86_l_1f78;
	case 8060ULL: goto x86_l_1f7c;
	case 8063ULL: goto x86_l_1f7f;
	case 8069ULL: goto x86_l_1f85;
	default: return 0xffffffffffffffffULL;
	}
x86_l_19a3:
	/* 0x19a3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19a8:
	/* 0x19a8: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19ad:
	/* 0x19ad: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19b2:
	/* 0x19b2: ja     19c2 <generic_retkprobe_filter_arg+0x19c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19c2;
	}
x86_l_19b4:
	/* 0x19b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19b7:
	/* 0x19b7: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_19ba:
	/* 0x19ba: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_19bd:
	/* 0x19bd: jmp    24c <generic_retkprobe_filter_arg+0x24c> */
	return 588ULL;
x86_l_19c2:
	/* 0x19c2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19c4:
	/* 0x19c4: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_19c7:
	/* 0x19c7: jmp    24c <generic_retkprobe_filter_arg+0x24c> */
	return 588ULL;
x86_l_19cc:
	/* 0x19cc: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19d0:
	/* 0x19d0: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_19d3:
	/* 0x19d3: ja     19de <generic_retkprobe_filter_arg+0x19de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19de;
	}
x86_l_19d5:
	/* 0x19d5: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_19d8:
	/* 0x19d8: jbe    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 610ULL;
	}
x86_l_19de:
	/* 0x19de: mov    edx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19e2:
	/* 0x19e2: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_19e5:
	/* 0x19e5: jb     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 177ULL;
	}
x86_l_19eb:
	/* 0x19eb: mov    rdi,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19ef:
	/* 0x19ef: mov    rsi,QWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19f3:
	/* 0x19f3: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_19f6:
	/* 0x19f6: je     1a01 <generic_retkprobe_filter_arg+0x1a01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a01;
	}
x86_l_19f8:
	/* 0x19f8: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_19fb:
	/* 0x19fb: jne    1fed <generic_retkprobe_filter_arg+0x1fed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8173ULL;
	}
x86_l_1a01:
	/* 0x1a01: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1a04:
	/* 0x1a04: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a09:
	/* 0x1a09: jg     2000 <generic_retkprobe_filter_arg+0x2000> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8192ULL;
	}
x86_l_1a0f:
	/* 0x1a0f: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_1a12:
	/* 0x1a12: jle    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 610ULL;
	}
x86_l_1a18:
	/* 0x1a18: jmp    2000 <generic_retkprobe_filter_arg+0x2000> */
	return 8192ULL;
x86_l_1a1d:
	/* 0x1a1d: mov    rdx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a21:
	/* 0x1a21: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1a24:
	/* 0x1a24: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1a28:
	/* 0x1a28: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1a2b:
	/* 0x1a2b: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1a2e:
	/* 0x1a2e: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a31:
	/* 0x1a31: mov    esi,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a35:
	/* 0x1a35: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_1a38:
	/* 0x1a38: jb     2adb <generic_retkprobe_filter_arg+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10971ULL;
	}
x86_l_1a3e:
	/* 0x1a3e: mov    r8,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a42:
	/* 0x1a42: mov    rdi,QWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a46:
	/* 0x1a46: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1a49:
	/* 0x1a49: je     1a54 <generic_retkprobe_filter_arg+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a54;
	}
x86_l_1a4b:
	/* 0x1a4b: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1a4e:
	/* 0x1a4e: jne    1fa7 <generic_retkprobe_filter_arg+0x1fa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8103ULL;
	}
x86_l_1a54:
	/* 0x1a54: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_1a57:
	/* 0x1a57: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1a5b:
	/* 0x1a5b: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1a5e:
	/* 0x1a5e: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1a62:
	/* 0x1a62: jmp    1fb5 <generic_retkprobe_filter_arg+0x1fb5> */
	return 8117ULL;
x86_l_1a67:
	/* 0x1a67: movzx  ebx,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1a6b:
	/* 0x1a6b: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1a70:
	/* 0x1a70: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1a74:
	/* 0x1a74: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a79:
	/* 0x1a79: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1a80:
	/* 0x1a80: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1a85:
	/* 0x1a85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a87:
	/* 0x1a87: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a8a:
	/* 0x1a8a: je     23b <generic_retkprobe_filter_arg+0x23b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 571ULL;
	}
x86_l_1a90:
	/* 0x1a90: movzx  ecx,bx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1a93:
	/* 0x1a93: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1aa0:
	/* 0x1aa0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1aa3:
	/* 0x1aa3: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1aa8:
	/* 0x1aa8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1aaa:
	/* 0x1aaa: mov    edx,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1aae:
	/* 0x1aae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ab0:
	/* 0x1ab0: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1ab3:
	/* 0x1ab3: ja     2677 <generic_retkprobe_filter_arg+0x2677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9847ULL;
	}
x86_l_1ab9:
	/* 0x1ab9: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1abe:
	/* 0x1abe: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1ac1:
	/* 0x1ac1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ac6:
	/* 0x1ac6: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1acb:
	/* 0x1acb: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ad0:
	/* 0x1ad0: jae    1ada <generic_retkprobe_filter_arg+0x1ada> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1ada;
	}
x86_l_1ad2:
	/* 0x1ad2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ad5:
	/* 0x1ad5: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1ad8:
	/* 0x1ad8: jmp    1aea <generic_retkprobe_filter_arg+0x1aea> */
	goto x86_l_1aea;
x86_l_1ada:
	/* 0x1ada: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1adf:
	/* 0x1adf: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1ae2:
	/* 0x1ae2: jae    1aea <generic_retkprobe_filter_arg+0x1aea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1aea;
	}
x86_l_1ae4:
	/* 0x1ae4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ae7:
	/* 0x1ae7: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1aea:
	/* 0x1aea: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1aed:
	/* 0x1aed: jmp    24c <generic_retkprobe_filter_arg+0x24c> */
	return 588ULL;
x86_l_1af2:
	/* 0x1af2: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af6:
	/* 0x1af6: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_1afc:
	/* 0x1afc: jmp    1b08 <generic_retkprobe_filter_arg+0x1b08> */
	goto x86_l_1b08;
x86_l_1afe:
	/* 0x1afe: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b02:
	/* 0x1b02: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_1b08:
	/* 0x1b08: mov    edx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b0c:
	/* 0x1b0c: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1b0f:
	/* 0x1b0f: jb     2f55 <generic_retkprobe_filter_arg+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12117ULL;
	}
x86_l_1b15:
	/* 0x1b15: mov    rsi,QWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b19:
	/* 0x1b19: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b1c:
	/* 0x1b1c: jle    1b3a <generic_retkprobe_filter_arg+0x1b3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1b3a;
	}
x86_l_1b1e:
	/* 0x1b1e: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1b21:
	/* 0x1b21: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1b24:
	/* 0x1b24: jae    1b69 <generic_retkprobe_filter_arg+0x1b69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b69;
	}
x86_l_1b26:
	/* 0x1b26: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b2a:
	/* 0x1b2a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b2f:
	/* 0x1b2f: jne    25b2 <generic_retkprobe_filter_arg+0x25b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9650ULL;
	}
x86_l_1b35:
	/* 0x1b35: jmp    2e60 <generic_retkprobe_filter_arg+0x2e60> */
	return 11872ULL;
x86_l_1b3a:
	/* 0x1b3a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b3d:
	/* 0x1b3d: je     1cbd <generic_retkprobe_filter_arg+0x1cbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cbd;
	}
x86_l_1b43:
	/* 0x1b43: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b46:
	/* 0x1b46: jne    25b2 <generic_retkprobe_filter_arg+0x25b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9650ULL;
	}
x86_l_1b4c:
	/* 0x1b4c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1b4f:
	/* 0x1b4f: je     1b5a <generic_retkprobe_filter_arg+0x1b5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b5a;
	}
x86_l_1b51:
	/* 0x1b51: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1b54:
	/* 0x1b54: jne    25a8 <generic_retkprobe_filter_arg+0x25a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9640ULL;
	}
x86_l_1b5a:
	/* 0x1b5a: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b5e:
	/* 0x1b5e: jl     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 610ULL;
	}
x86_l_1b64:
	/* 0x1b64: jmp    25b2 <generic_retkprobe_filter_arg+0x25b2> */
	return 9650ULL;
x86_l_1b69:
	/* 0x1b69: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1b6c:
	/* 0x1b6c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b71:
	/* 0x1b71: jne    25b2 <generic_retkprobe_filter_arg+0x25b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9650ULL;
	}
x86_l_1b77:
	/* 0x1b77: test   QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b7b:
	/* 0x1b7b: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_1b81:
	/* 0x1b81: jmp    25b2 <generic_retkprobe_filter_arg+0x25b2> */
	return 9650ULL;
x86_l_1b86:
	/* 0x1b86: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1b89:
	/* 0x1b89: jne    1e68 <generic_retkprobe_filter_arg+0x1e68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e68;
	}
x86_l_1b8f:
	/* 0x1b8f: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1b93:
	/* 0x1b93: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1b95:
	/* 0x1b95: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_1b9b:
	/* 0x1b9b: jmp    1e68 <generic_retkprobe_filter_arg+0x1e68> */
	goto x86_l_1e68;
x86_l_1ba0:
	/* 0x1ba0: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1ba3:
	/* 0x1ba3: jne    1eab <generic_retkprobe_filter_arg+0x1eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1eab;
	}
x86_l_1ba9:
	/* 0x1ba9: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1bad:
	/* 0x1bad: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1baf:
	/* 0x1baf: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_1bb5:
	/* 0x1bb5: jmp    1eab <generic_retkprobe_filter_arg+0x1eab> */
	goto x86_l_1eab;
x86_l_1bba:
	/* 0x1bba: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1bbe:
	/* 0x1bbe: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1bc1:
	/* 0x1bc1: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1bc4:
	/* 0x1bc4: jmp    1ee5 <generic_retkprobe_filter_arg+0x1ee5> */
	goto x86_l_1ee5;
x86_l_1bc9:
	/* 0x1bc9: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1bcc:
	/* 0x1bcc: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1bd1:
	/* 0x1bd1: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_1bd6:
	/* 0x1bd6: mov    eax,0x1fe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 510ULL);
x86_l_1bdb:
	/* 0x1bdb: cmovae esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_1bde:
	/* 0x1bde: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1be1:
	/* 0x1be1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1be3:
	/* 0x1be3: cmp    eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1be8:
	/* 0x1be8: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1beb:
	/* 0x1beb: xor    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 7ULL);
x86_l_1bee:
	/* 0x1bee: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1bf0:
	/* 0x1bf0: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1bf3:
	/* 0x1bf3: mov    eax,DWORD PTR [r15+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_1bf8:
	/* 0x1bf8: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_1bfb:
	/* 0x1bfb: je     2c38 <generic_retkprobe_filter_arg+0x2c38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11320ULL;
	}
x86_l_1c01:
	/* 0x1c01: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1c08:
	/* 0x1c08: mov    DWORD PTR [rsp+0x4c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1c0c:
	/* 0x1c0c: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c10:
	/* 0x1c10: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c15:
	/* 0x1c15: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c1a:
	/* 0x1c1a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_1c21:
	/* 0x1c21: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c26:
	/* 0x1c26: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1c29:
	/* 0x1c29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2b:
	/* 0x1c2b: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c30:
	/* 0x1c30: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c35:
	/* 0x1c35: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1c3c:
	/* 0x1c3c: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1c3f:
	/* 0x1c3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c41:
	/* 0x1c41: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1c47:
	/* 0x1c47: je     2c38 <generic_retkprobe_filter_arg+0x2c38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11320ULL;
	}
x86_l_1c4d:
	/* 0x1c4d: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1c52:
	/* 0x1c52: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c55:
	/* 0x1c55: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c5a:
	/* 0x1c5a: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c5f:
	/* 0x1c5f: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c64:
	/* 0x1c64: je     2c49 <generic_retkprobe_filter_arg+0x2c49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11337ULL;
	}
x86_l_1c6a:
	/* 0x1c6a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1c6d:
	/* 0x1c6d: cmp    DWORD PTR [rsp+0x50],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383685ULL);
x86_l_1c72:
	/* 0x1c72: jg     2492 <generic_retkprobe_filter_arg+0x2492> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9362ULL;
	}
x86_l_1c78:
	/* 0x1c78: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c7d:
	/* 0x1c7d: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c80:
	/* 0x1c80: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1c84:
	/* 0x1c84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c89:
	/* 0x1c89: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1c8b:
	/* 0x1c8b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c90:
	/* 0x1c90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c92:
	/* 0x1c92: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_1c97:
	/* 0x1c97: cmp    esi,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1c99:
	/* 0x1c99: jbe    24d4 <generic_retkprobe_filter_arg+0x24d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9428ULL;
	}
x86_l_1c9f:
	/* 0x1c9f: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ca4:
	/* 0x1ca4: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1ca8:
	/* 0x1ca8: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1cab:
	/* 0x1cab: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1cad:
	/* 0x1cad: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1cb3:
	/* 0x1cb3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cb8:
	/* 0x1cb8: jmp    24cf <generic_retkprobe_filter_arg+0x24cf> */
	return 9423ULL;
x86_l_1cbd:
	/* 0x1cbd: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1cc0:
	/* 0x1cc0: je     1ccb <generic_retkprobe_filter_arg+0x1ccb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ccb;
	}
x86_l_1cc2:
	/* 0x1cc2: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1cc5:
	/* 0x1cc5: jne    259c <generic_retkprobe_filter_arg+0x259c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9628ULL;
	}
x86_l_1ccb:
	/* 0x1ccb: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ccf:
	/* 0x1ccf: jg     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 610ULL;
	}
x86_l_1cd5:
	/* 0x1cd5: jmp    25b2 <generic_retkprobe_filter_arg+0x25b2> */
	return 9650ULL;
x86_l_1cda:
	/* 0x1cda: mov    edx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cde:
	/* 0x1cde: movzx  ecx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1ce2:
	/* 0x1ce2: jmp    1cec <generic_retkprobe_filter_arg+0x1cec> */
	goto x86_l_1cec;
x86_l_1ce4:
	/* 0x1ce4: mov    edx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ce8:
	/* 0x1ce8: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1cec:
	/* 0x1cec: cmp    DWORD PTR [r15+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cf0:
	/* 0x1cf0: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1cf4:
	/* 0x1cf4: cmp    DWORD PTR [r15+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1cf8:
	/* 0x1cf8: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_1cfb:
	/* 0x1cfb: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1cfe:
	/* 0x1cfe: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d01:
	/* 0x1d01: jb     2adb <generic_retkprobe_filter_arg+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10971ULL;
	}
x86_l_1d07:
	/* 0x1d07: cmp    DWORD PTR [r15+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d0b:
	/* 0x1d0b: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1d0f:
	/* 0x1d0f: cmp    DWORD PTR [r15+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1d13:
	/* 0x1d13: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1d17:
	/* 0x1d17: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1d1a:
	/* 0x1d1a: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1d1d:
	/* 0x1d1d: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1d20:
	/* 0x1d20: jb     2ad6 <generic_retkprobe_filter_arg+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10966ULL;
	}
x86_l_1d26:
	/* 0x1d26: cmp    DWORD PTR [r15+0x20],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d2a:
	/* 0x1d2a: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1d2e:
	/* 0x1d2e: cmp    DWORD PTR [r15+0x24],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d32:
	/* 0x1d32: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1d36:
	/* 0x1d36: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1d39:
	/* 0x1d39: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1d3c:
	/* 0x1d3c: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1d3f:
	/* 0x1d3f: jb     2ad6 <generic_retkprobe_filter_arg+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10966ULL;
	}
x86_l_1d45:
	/* 0x1d45: cmp    DWORD PTR [r15+0x28],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d49:
	/* 0x1d49: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_1d4c:
	/* 0x1d4c: cmp    DWORD PTR [r15+0x2c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1d50:
	/* 0x1d50: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_1d53:
	/* 0x1d53: and    cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1d55:
	/* 0x1d55: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1d57:
	/* 0x1d57: jmp    2ad6 <generic_retkprobe_filter_arg+0x2ad6> */
	return 10966ULL;
x86_l_1d5c:
	/* 0x1d5c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d5e:
	/* 0x1d5e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d61:
	/* 0x1d61: mov    eax,DWORD PTR [r15+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_1d66:
	/* 0x1d66: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1d6a:
	/* 0x1d6a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d6f:
	/* 0x1d6f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1d76:
	/* 0x1d76: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1d7b:
	/* 0x1d7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7d:
	/* 0x1d7d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d80:
	/* 0x1d80: je     26a8 <generic_retkprobe_filter_arg+0x26a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9896ULL;
	}
x86_l_1d86:
	/* 0x1d86: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_1d89:
	/* 0x1d89: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d8e:
	/* 0x1d8e: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d93:
	/* 0x1d93: je     1dda <generic_retkprobe_filter_arg+0x1dda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dda;
	}
x86_l_1d95:
	/* 0x1d95: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d9a:
	/* 0x1d9a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d9c:
	/* 0x1d9c: jmp    1da9 <generic_retkprobe_filter_arg+0x1da9> */
	goto x86_l_1da9;
x86_l_1d9e:
	/* 0x1d9e: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1da1:
	/* 0x1da1: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1da4:
	/* 0x1da4: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1da7:
	/* 0x1da7: je     1dda <generic_retkprobe_filter_arg+0x1dda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dda;
	}
x86_l_1da9:
	/* 0x1da9: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dab:
	/* 0x1dab: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1daf:
	/* 0x1daf: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1db2:
	/* 0x1db2: jae    1d9e <generic_retkprobe_filter_arg+0x1d9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d9e;
	}
x86_l_1db4:
	/* 0x1db4: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1db8:
	/* 0x1db8: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_1dbb:
	/* 0x1dbb: je     1dd2 <generic_retkprobe_filter_arg+0x1dd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dd2;
	}
x86_l_1dbd:
	/* 0x1dbd: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1dc1:
	/* 0x1dc1: ja     1d9e <generic_retkprobe_filter_arg+0x1d9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d9e;
	}
x86_l_1dc3:
	/* 0x1dc3: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1dc7:
	/* 0x1dc7: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1dcb:
	/* 0x1dcb: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1dce:
	/* 0x1dce: je     1dab <generic_retkprobe_filter_arg+0x1dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dab;
	}
x86_l_1dd0:
	/* 0x1dd0: jmp    1d9e <generic_retkprobe_filter_arg+0x1d9e> */
	goto x86_l_1d9e;
x86_l_1dd2:
	/* 0x1dd2: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1dd4:
	/* 0x1dd4: jns    2992 <generic_retkprobe_filter_arg+0x2992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10642ULL;
	}
x86_l_1dda:
	/* 0x1dda: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ddf:
	/* 0x1ddf: cmp    eax,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1de3:
	/* 0x1de3: jae    1df6 <generic_retkprobe_filter_arg+0x1df6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1df6;
	}
x86_l_1de5:
	/* 0x1de5: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1de9:
	/* 0x1de9: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1dec:
	/* 0x1dec: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_1df0:
	/* 0x1df0: jne    1d61 <generic_retkprobe_filter_arg+0x1d61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d61;
	}
x86_l_1df6:
	/* 0x1df6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1df8:
	/* 0x1df8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dfd:
	/* 0x1dfd: jmp    2ed7 <generic_retkprobe_filter_arg+0x2ed7> */
	return 11991ULL;
x86_l_1e02:
	/* 0x1e02: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1e05:
	/* 0x1e05: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1e0a:
	/* 0x1e0a: ja     2270 <generic_retkprobe_filter_arg+0x2270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8816ULL;
	}
x86_l_1e10:
	/* 0x1e10: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e14:
	/* 0x1e14: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1e1a:
	/* 0x1e1a: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1e1d:
	/* 0x1e1d: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1e20:
	/* 0x1e20: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1e23:
	/* 0x1e23: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1e25:
	/* 0x1e25: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1e27:
	/* 0x1e27: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1e2a:
	/* 0x1e2a: je     1e32 <generic_retkprobe_filter_arg+0x1e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e32;
	}
x86_l_1e2c:
	/* 0x1e2c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1e2e:
	/* 0x1e2e: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1e30:
	/* 0x1e30: je     1e48 <generic_retkprobe_filter_arg+0x1e48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e48;
	}
x86_l_1e32:
	/* 0x1e32: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e35:
	/* 0x1e35: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1e37:
	/* 0x1e37: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e39:
	/* 0x1e39: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1e3b:
	/* 0x1e3b: add    esi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1e3e:
	/* 0x1e3e: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1e42:
	/* 0x1e42: ja     2285 <generic_retkprobe_filter_arg+0x2285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8837ULL;
	}
x86_l_1e48:
	/* 0x1e48: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e4c:
	/* 0x1e4c: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1e52:
	/* 0x1e52: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1e55:
	/* 0x1e55: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1e57:
	/* 0x1e57: jmp    2295 <generic_retkprobe_filter_arg+0x2295> */
	return 8853ULL;
x86_l_1e5c:
	/* 0x1e5c: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e60:
	/* 0x1e60: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1e62:
	/* 0x1e62: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_1e68:
	/* 0x1e68: mov    ecx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e6c:
	/* 0x1e6c: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1e6f:
	/* 0x1e6f: jb     2f55 <generic_retkprobe_filter_arg+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12117ULL;
	}
x86_l_1e75:
	/* 0x1e75: mov    edx,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e79:
	/* 0x1e79: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e7c:
	/* 0x1e7c: jle    216c <generic_retkprobe_filter_arg+0x216c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8556ULL;
	}
x86_l_1e82:
	/* 0x1e82: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1e85:
	/* 0x1e85: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e88:
	/* 0x1e88: jae    262c <generic_retkprobe_filter_arg+0x262c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9772ULL;
	}
x86_l_1e8e:
	/* 0x1e8e: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e92:
	/* 0x1e92: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1e94:
	/* 0x1e94: jne    271a <generic_retkprobe_filter_arg+0x271a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10010ULL;
	}
x86_l_1e9a:
	/* 0x1e9a: jmp    2e60 <generic_retkprobe_filter_arg+0x2e60> */
	return 11872ULL;
x86_l_1e9f:
	/* 0x1e9f: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ea3:
	/* 0x1ea3: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1ea5:
	/* 0x1ea5: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_1eab:
	/* 0x1eab: mov    ecx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eaf:
	/* 0x1eaf: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1eb2:
	/* 0x1eb2: jb     2f55 <generic_retkprobe_filter_arg+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12117ULL;
	}
x86_l_1eb8:
	/* 0x1eb8: mov    edx,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1ebc:
	/* 0x1ebc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ebf:
	/* 0x1ebf: jle    218f <generic_retkprobe_filter_arg+0x218f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8591ULL;
	}
x86_l_1ec5:
	/* 0x1ec5: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1ec8:
	/* 0x1ec8: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1ecb:
	/* 0x1ecb: jae    2646 <generic_retkprobe_filter_arg+0x2646> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9798ULL;
	}
x86_l_1ed1:
	/* 0x1ed1: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ed5:
	/* 0x1ed5: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1ed7:
	/* 0x1ed7: jne    2759 <generic_retkprobe_filter_arg+0x2759> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10073ULL;
	}
x86_l_1edd:
	/* 0x1edd: jmp    2e60 <generic_retkprobe_filter_arg+0x2e60> */
	return 11872ULL;
x86_l_1ee2:
	/* 0x1ee2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ee5:
	/* 0x1ee5: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1ee8:
	/* 0x1ee8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eed:
	/* 0x1eed: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ef2:
	/* 0x1ef2: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ef7:
	/* 0x1ef7: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1efa:
	/* 0x1efa: jmp    24c <generic_retkprobe_filter_arg+0x24c> */
	return 588ULL;
x86_l_1eff:
	/* 0x1eff: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f02:
	/* 0x1f02: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1f04:
	/* 0x1f04: ja     1f0e <generic_retkprobe_filter_arg+0x1f0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f0e;
	}
x86_l_1f06:
	/* 0x1f06: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1f08:
	/* 0x1f08: jbe    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 610ULL;
	}
x86_l_1f0e:
	/* 0x1f0e: mov    edx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f12:
	/* 0x1f12: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1f15:
	/* 0x1f15: jb     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 177ULL;
	}
x86_l_1f1b:
	/* 0x1f1b: mov    edi,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f1f:
	/* 0x1f1f: mov    esi,DWORD PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f23:
	/* 0x1f23: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1f26:
	/* 0x1f26: ja     23ac <generic_retkprobe_filter_arg+0x23ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9132ULL;
	}
x86_l_1f2c:
	/* 0x1f2c: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_1f32:
	/* 0x1f32: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_1f36:
	/* 0x1f36: jae    23ac <generic_retkprobe_filter_arg+0x23ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9132ULL;
	}
x86_l_1f3c:
	/* 0x1f3c: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_1f3e:
	/* 0x1f3e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f43:
	/* 0x1f43: jg     23bd <generic_retkprobe_filter_arg+0x23bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9149ULL;
	}
x86_l_1f49:
	/* 0x1f49: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_1f4b:
	/* 0x1f4b: jle    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 610ULL;
	}
x86_l_1f51:
	/* 0x1f51: jmp    23bd <generic_retkprobe_filter_arg+0x23bd> */
	return 9149ULL;
x86_l_1f56:
	/* 0x1f56: mov    edx,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f59:
	/* 0x1f59: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1f5b:
	/* 0x1f5b: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1f5f:
	/* 0x1f5f: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1f61:
	/* 0x1f61: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1f64:
	/* 0x1f64: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f67:
	/* 0x1f67: mov    esi,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f6b:
	/* 0x1f6b: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1f6e:
	/* 0x1f6e: jb     2adb <generic_retkprobe_filter_arg+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10971ULL;
	}
x86_l_1f74:
	/* 0x1f74: mov    r8d,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f78:
	/* 0x1f78: mov    edi,DWORD PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f7c:
	/* 0x1f7c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1f7f:
	/* 0x1f7f: ja     235d <generic_retkprobe_filter_arg+0x235d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9053ULL;
	}
x86_l_1f85:
	/* 0x1f85: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
	return 8075ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8075ULL: goto x86_l_1f8b;
	case 8079ULL: goto x86_l_1f8f;
	case 8085ULL: goto x86_l_1f95;
	case 8088ULL: goto x86_l_1f98;
	case 8092ULL: goto x86_l_1f9c;
	case 8094ULL: goto x86_l_1f9e;
	case 8098ULL: goto x86_l_1fa2;
	case 8103ULL: goto x86_l_1fa7;
	case 8106ULL: goto x86_l_1faa;
	case 8110ULL: goto x86_l_1fae;
	case 8113ULL: goto x86_l_1fb1;
	case 8117ULL: goto x86_l_1fb5;
	case 8120ULL: goto x86_l_1fb8;
	case 8123ULL: goto x86_l_1fbb;
	case 8126ULL: goto x86_l_1fbe;
	case 8132ULL: goto x86_l_1fc4;
	case 8136ULL: goto x86_l_1fc8;
	case 8140ULL: goto x86_l_1fcc;
	case 8143ULL: goto x86_l_1fcf;
	case 8145ULL: goto x86_l_1fd1;
	case 8148ULL: goto x86_l_1fd4;
	case 8154ULL: goto x86_l_1fda;
	case 8157ULL: goto x86_l_1fdd;
	case 8161ULL: goto x86_l_1fe1;
	case 8164ULL: goto x86_l_1fe4;
	case 8168ULL: goto x86_l_1fe8;
	case 8173ULL: goto x86_l_1fed;
	case 8176ULL: goto x86_l_1ff0;
	case 8181ULL: goto x86_l_1ff5;
	case 8183ULL: goto x86_l_1ff7;
	case 8186ULL: goto x86_l_1ffa;
	case 8192ULL: goto x86_l_2000;
	case 8195ULL: goto x86_l_2003;
	case 8201ULL: goto x86_l_2009;
	case 8205ULL: goto x86_l_200d;
	case 8209ULL: goto x86_l_2011;
	case 8212ULL: goto x86_l_2014;
	case 8214ULL: goto x86_l_2016;
	case 8217ULL: goto x86_l_2019;
	case 8223ULL: goto x86_l_201f;
	case 8226ULL: goto x86_l_2022;
	case 8231ULL: goto x86_l_2027;
	case 8237ULL: goto x86_l_202d;
	case 8240ULL: goto x86_l_2030;
	case 8246ULL: goto x86_l_2036;
	case 8251ULL: goto x86_l_203b;
	case 8253ULL: goto x86_l_203d;
	case 8256ULL: goto x86_l_2040;
	case 8258ULL: goto x86_l_2042;
	case 8261ULL: goto x86_l_2045;
	case 8263ULL: goto x86_l_2047;
	case 8267ULL: goto x86_l_204b;
	case 8270ULL: goto x86_l_204e;
	case 8272ULL: goto x86_l_2050;
	case 8275ULL: goto x86_l_2053;
	case 8281ULL: goto x86_l_2059;
	case 8286ULL: goto x86_l_205e;
	case 8290ULL: goto x86_l_2062;
	case 8295ULL: goto x86_l_2067;
	case 8302ULL: goto x86_l_206e;
	case 8307ULL: goto x86_l_2073;
	case 8309ULL: goto x86_l_2075;
	case 8312ULL: goto x86_l_2078;
	case 8318ULL: goto x86_l_207e;
	case 8320ULL: goto x86_l_2080;
	case 8328ULL: goto x86_l_2088;
	case 8333ULL: goto x86_l_208d;
	case 8338ULL: goto x86_l_2092;
	case 8341ULL: goto x86_l_2095;
	case 8347ULL: goto x86_l_209b;
	case 8349ULL: goto x86_l_209d;
	case 8352ULL: goto x86_l_20a0;
	case 8358ULL: goto x86_l_20a6;
	case 8362ULL: goto x86_l_20aa;
	case 8365ULL: goto x86_l_20ad;
	case 8371ULL: goto x86_l_20b3;
	case 8375ULL: goto x86_l_20b7;
	case 8378ULL: goto x86_l_20ba;
	case 8380ULL: goto x86_l_20bc;
	case 8383ULL: goto x86_l_20bf;
	case 8386ULL: goto x86_l_20c2;
	case 8388ULL: goto x86_l_20c4;
	case 8391ULL: goto x86_l_20c7;
	case 8396ULL: goto x86_l_20cc;
	case 8402ULL: goto x86_l_20d2;
	case 8407ULL: goto x86_l_20d7;
	case 8410ULL: goto x86_l_20da;
	case 8412ULL: goto x86_l_20dc;
	case 8415ULL: goto x86_l_20df;
	case 8421ULL: goto x86_l_20e5;
	case 8424ULL: goto x86_l_20e8;
	case 8430ULL: goto x86_l_20ee;
	case 8436ULL: goto x86_l_20f4;
	case 8440ULL: goto x86_l_20f8;
	case 8446ULL: goto x86_l_20fe;
	case 8449ULL: goto x86_l_2101;
	case 8455ULL: goto x86_l_2107;
	case 8460ULL: goto x86_l_210c;
	case 8463ULL: goto x86_l_210f;
	case 8468ULL: goto x86_l_2114;
	case 8474ULL: goto x86_l_211a;
	case 8477ULL: goto x86_l_211d;
	case 8483ULL: goto x86_l_2123;
	case 8488ULL: goto x86_l_2128;
	case 8491ULL: goto x86_l_212b;
	case 8497ULL: goto x86_l_2131;
	case 8503ULL: goto x86_l_2137;
	case 8507ULL: goto x86_l_213b;
	case 8513ULL: goto x86_l_2141;
	case 8516ULL: goto x86_l_2144;
	case 8522ULL: goto x86_l_214a;
	case 8527ULL: goto x86_l_214f;
	case 8529ULL: goto x86_l_2151;
	case 8534ULL: goto x86_l_2156;
	case 8539ULL: goto x86_l_215b;
	case 8544ULL: goto x86_l_2160;
	case 8546ULL: goto x86_l_2162;
	case 8551ULL: goto x86_l_2167;
	case 8556ULL: goto x86_l_216c;
	case 8559ULL: goto x86_l_216f;
	case 8565ULL: goto x86_l_2175;
	case 8568ULL: goto x86_l_2178;
	case 8574ULL: goto x86_l_217e;
	case 8578ULL: goto x86_l_2182;
	case 8580ULL: goto x86_l_2184;
	case 8586ULL: goto x86_l_218a;
	case 8591ULL: goto x86_l_218f;
	case 8594ULL: goto x86_l_2192;
	case 8600ULL: goto x86_l_2198;
	case 8603ULL: goto x86_l_219b;
	case 8609ULL: goto x86_l_21a1;
	case 8613ULL: goto x86_l_21a5;
	case 8615ULL: goto x86_l_21a7;
	case 8621ULL: goto x86_l_21ad;
	case 8626ULL: goto x86_l_21b2;
	case 8629ULL: goto x86_l_21b5;
	case 8632ULL: goto x86_l_21b8;
	case 8636ULL: goto x86_l_21bc;
	case 8641ULL: goto x86_l_21c1;
	case 8643ULL: goto x86_l_21c3;
	case 8645ULL: goto x86_l_21c5;
	case 8647ULL: goto x86_l_21c7;
	case 8649ULL: goto x86_l_21c9;
	case 8653ULL: goto x86_l_21cd;
	case 8657ULL: goto x86_l_21d1;
	case 8659ULL: goto x86_l_21d3;
	case 8665ULL: goto x86_l_21d9;
	case 8670ULL: goto x86_l_21de;
	case 8672ULL: goto x86_l_21e0;
	case 8680ULL: goto x86_l_21e8;
	case 8682ULL: goto x86_l_21ea;
	case 8686ULL: goto x86_l_21ee;
	case 8690ULL: goto x86_l_21f2;
	case 8694ULL: goto x86_l_21f6;
	case 8697ULL: goto x86_l_21f9;
	case 8699ULL: goto x86_l_21fb;
	case 8702ULL: goto x86_l_21fe;
	case 8707ULL: goto x86_l_2203;
	case 8712ULL: goto x86_l_2208;
	case 8717ULL: goto x86_l_220d;
	case 8723ULL: goto x86_l_2213;
	case 8725ULL: goto x86_l_2215;
	case 8731ULL: goto x86_l_221b;
	case 8734ULL: goto x86_l_221e;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8752ULL: goto x86_l_2230;
	case 8757ULL: goto x86_l_2235;
	case 8760ULL: goto x86_l_2238;
	case 8765ULL: goto x86_l_223d;
	case 8770ULL: goto x86_l_2242;
	case 8775ULL: goto x86_l_2247;
	case 8781ULL: goto x86_l_224d;
	case 8784ULL: goto x86_l_2250;
	case 8790ULL: goto x86_l_2256;
	case 8793ULL: goto x86_l_2259;
	case 8799ULL: goto x86_l_225f;
	case 8804ULL: goto x86_l_2264;
	case 8811ULL: goto x86_l_226b;
	case 8816ULL: goto x86_l_2270;
	case 8819ULL: goto x86_l_2273;
	case 8824ULL: goto x86_l_2278;
	case 8829ULL: goto x86_l_227d;
	case 8834ULL: goto x86_l_2282;
	case 8837ULL: goto x86_l_2285;
	case 8840ULL: goto x86_l_2288;
	case 8842ULL: goto x86_l_228a;
	case 8847ULL: goto x86_l_228f;
	case 8850ULL: goto x86_l_2292;
	case 8853ULL: goto x86_l_2295;
	case 8855ULL: goto x86_l_2297;
	case 8858ULL: goto x86_l_229a;
	case 8863ULL: goto x86_l_229f;
	case 8866ULL: goto x86_l_22a2;
	case 8872ULL: goto x86_l_22a8;
	case 8876ULL: goto x86_l_22ac;
	case 8880ULL: goto x86_l_22b0;
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
	case 8934ULL: goto x86_l_22e6;
	case 8940ULL: goto x86_l_22ec;
	case 8945ULL: goto x86_l_22f1;
	case 8948ULL: goto x86_l_22f4;
	case 8953ULL: goto x86_l_22f9;
	case 8958ULL: goto x86_l_22fe;
	case 8963ULL: goto x86_l_2303;
	case 8969ULL: goto x86_l_2309;
	case 8972ULL: goto x86_l_230c;
	case 8980ULL: goto x86_l_2314;
	case 8985ULL: goto x86_l_2319;
	case 8990ULL: goto x86_l_231e;
	case 8996ULL: goto x86_l_2324;
	case 8999ULL: goto x86_l_2327;
	case 9002ULL: goto x86_l_232a;
	case 9006ULL: goto x86_l_232e;
	case 9011ULL: goto x86_l_2333;
	case 9013ULL: goto x86_l_2335;
	case 9018ULL: goto x86_l_233a;
	case 9020ULL: goto x86_l_233c;
	case 9022ULL: goto x86_l_233e;
	case 9028ULL: goto x86_l_2344;
	case 9032ULL: goto x86_l_2348;
	case 9035ULL: goto x86_l_234b;
	case 9037ULL: goto x86_l_234d;
	case 9043ULL: goto x86_l_2353;
	case 9048ULL: goto x86_l_2358;
	case 9053ULL: goto x86_l_235d;
	case 9056ULL: goto x86_l_2360;
	case 9060ULL: goto x86_l_2364;
	case 9062ULL: goto x86_l_2366;
	case 9066ULL: goto x86_l_236a;
	case 9069ULL: goto x86_l_236d;
	case 9072ULL: goto x86_l_2370;
	case 9075ULL: goto x86_l_2373;
	case 9081ULL: goto x86_l_2379;
	case 9085ULL: goto x86_l_237d;
	case 9089ULL: goto x86_l_2381;
	case 9092ULL: goto x86_l_2384;
	case 9098ULL: goto x86_l_238a;
	case 9104ULL: goto x86_l_2390;
	case 9108ULL: goto x86_l_2394;
	case 9114ULL: goto x86_l_239a;
	case 9117ULL: goto x86_l_239d;
	case 9121ULL: goto x86_l_23a1;
	case 9123ULL: goto x86_l_23a3;
	case 9127ULL: goto x86_l_23a7;
	case 9132ULL: goto x86_l_23ac;
	case 9134ULL: goto x86_l_23ae;
	case 9139ULL: goto x86_l_23b3;
	case 9141ULL: goto x86_l_23b5;
	case 9143ULL: goto x86_l_23b7;
	case 9149ULL: goto x86_l_23bd;
	case 9152ULL: goto x86_l_23c0;
	case 9158ULL: goto x86_l_23c6;
	case 9162ULL: goto x86_l_23ca;
	case 9166ULL: goto x86_l_23ce;
	case 9169ULL: goto x86_l_23d1;
	case 9175ULL: goto x86_l_23d7;
	case 9181ULL: goto x86_l_23dd;
	case 9185ULL: goto x86_l_23e1;
	case 9191ULL: goto x86_l_23e7;
	case 9193ULL: goto x86_l_23e9;
	case 9198ULL: goto x86_l_23ee;
	case 9204ULL: goto x86_l_23f4;
	case 9206ULL: goto x86_l_23f6;
	case 9212ULL: goto x86_l_23fc;
	case 9217ULL: goto x86_l_2401;
	case 9222ULL: goto x86_l_2406;
	case 9227ULL: goto x86_l_240b;
	case 9232ULL: goto x86_l_2410;
	case 9236ULL: goto x86_l_2414;
	case 9240ULL: goto x86_l_2418;
	case 9246ULL: goto x86_l_241e;
	case 9251ULL: goto x86_l_2423;
	case 9256ULL: goto x86_l_2428;
	case 9261ULL: goto x86_l_242d;
	case 9266ULL: goto x86_l_2432;
	case 9271ULL: goto x86_l_2437;
	case 9275ULL: goto x86_l_243b;
	case 9279ULL: goto x86_l_243f;
	case 9285ULL: goto x86_l_2445;
	case 9290ULL: goto x86_l_244a;
	case 9293ULL: goto x86_l_244d;
	case 9297ULL: goto x86_l_2451;
	case 9300ULL: goto x86_l_2454;
	case 9304ULL: goto x86_l_2458;
	case 9307ULL: goto x86_l_245b;
	case 9310ULL: goto x86_l_245e;
	case 9313ULL: goto x86_l_2461;
	case 9319ULL: goto x86_l_2467;
	case 9323ULL: goto x86_l_246b;
	case 9327ULL: goto x86_l_246f;
	case 9330ULL: goto x86_l_2472;
	case 9332ULL: goto x86_l_2474;
	case 9335ULL: goto x86_l_2477;
	case 9341ULL: goto x86_l_247d;
	case 9344ULL: goto x86_l_2480;
	case 9347ULL: goto x86_l_2483;
	case 9350ULL: goto x86_l_2486;
	case 9355ULL: goto x86_l_248b;
	case 9357ULL: goto x86_l_248d;
	case 9362ULL: goto x86_l_2492;
	case 9367ULL: goto x86_l_2497;
	case 9370ULL: goto x86_l_249a;
	case 9374ULL: goto x86_l_249e;
	case 9379ULL: goto x86_l_24a3;
	case 9381ULL: goto x86_l_24a5;
	case 9386ULL: goto x86_l_24aa;
	case 9388ULL: goto x86_l_24ac;
	case 9393ULL: goto x86_l_24b1;
	case 9395ULL: goto x86_l_24b3;
	case 9397ULL: goto x86_l_24b5;
	case 9402ULL: goto x86_l_24ba;
	case 9406ULL: goto x86_l_24be;
	case 9410ULL: goto x86_l_24c2;
	case 9412ULL: goto x86_l_24c4;
	case 9418ULL: goto x86_l_24ca;
	case 9423ULL: goto x86_l_24cf;
	case 9426ULL: goto x86_l_24d2;
	case 9428ULL: goto x86_l_24d4;
	case 9435ULL: goto x86_l_24db;
	case 9439ULL: goto x86_l_24df;
	case 9443ULL: goto x86_l_24e3;
	case 9446ULL: goto x86_l_24e6;
	case 9448ULL: goto x86_l_24e8;
	case 9451ULL: goto x86_l_24eb;
	case 9456ULL: goto x86_l_24f0;
	case 9461ULL: goto x86_l_24f5;
	case 9467ULL: goto x86_l_24fb;
	case 9469ULL: goto x86_l_24fd;
	case 9475ULL: goto x86_l_2503;
	case 9478ULL: goto x86_l_2506;
	case 9484ULL: goto x86_l_250c;
	case 9489ULL: goto x86_l_2511;
	case 9496ULL: goto x86_l_2518;
	case 9501ULL: goto x86_l_251d;
	case 9504ULL: goto x86_l_2520;
	case 9509ULL: goto x86_l_2525;
	case 9514ULL: goto x86_l_252a;
	case 9520ULL: goto x86_l_2530;
	case 9523ULL: goto x86_l_2533;
	case 9529ULL: goto x86_l_2539;
	case 9532ULL: goto x86_l_253c;
	case 9538ULL: goto x86_l_2542;
	case 9543ULL: goto x86_l_2547;
	case 9550ULL: goto x86_l_254e;
	case 9555ULL: goto x86_l_2553;
	case 9558ULL: goto x86_l_2556;
	case 9563ULL: goto x86_l_255b;
	case 9565ULL: goto x86_l_255d;
	case 9568ULL: goto x86_l_2560;
	case 9574ULL: goto x86_l_2566;
	case 9577ULL: goto x86_l_2569;
	case 9583ULL: goto x86_l_256f;
	case 9587ULL: goto x86_l_2573;
	case 9591ULL: goto x86_l_2577;
	case 9594ULL: goto x86_l_257a;
	case 9596ULL: goto x86_l_257c;
	case 9599ULL: goto x86_l_257f;
	case 9605ULL: goto x86_l_2585;
	case 9608ULL: goto x86_l_2588;
	case 9614ULL: goto x86_l_258e;
	case 9617ULL: goto x86_l_2591;
	case 9623ULL: goto x86_l_2597;
	case 9628ULL: goto x86_l_259c;
	case 9632ULL: goto x86_l_25a0;
	case 9638ULL: goto x86_l_25a6;
	case 9640ULL: goto x86_l_25a8;
	case 9644ULL: goto x86_l_25ac;
	case 9650ULL: goto x86_l_25b2;
	case 9653ULL: goto x86_l_25b5;
	case 9659ULL: goto x86_l_25bb;
	case 9663ULL: goto x86_l_25bf;
	case 9666ULL: goto x86_l_25c2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1f8b:
	/* 0x1f8b: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_1f8f:
	/* 0x1f8f: jae    235d <generic_retkprobe_filter_arg+0x235d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_235d;
	}
x86_l_1f95:
	/* 0x1f95: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_1f98:
	/* 0x1f98: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1f9c:
	/* 0x1f9c: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_1f9e:
	/* 0x1f9e: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1fa2:
	/* 0x1fa2: jmp    236a <generic_retkprobe_filter_arg+0x236a> */
	goto x86_l_236a;
x86_l_1fa7:
	/* 0x1fa7: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_1faa:
	/* 0x1faa: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1fae:
	/* 0x1fae: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1fb1:
	/* 0x1fb1: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_1fb5:
	/* 0x1fb5: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1fb8:
	/* 0x1fb8: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1fbb:
	/* 0x1fbb: cmp    esi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 41ULL);
x86_l_1fbe:
	/* 0x1fbe: jb     2ad6 <generic_retkprobe_filter_arg+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10966ULL;
	}
x86_l_1fc4:
	/* 0x1fc4: mov    r8,QWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fc8:
	/* 0x1fc8: mov    rdi,QWORD PTR [r15+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1fcc:
	/* 0x1fcc: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1fcf:
	/* 0x1fcf: je     1fda <generic_retkprobe_filter_arg+0x1fda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fda;
	}
x86_l_1fd1:
	/* 0x1fd1: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1fd4:
	/* 0x1fd4: jne    244a <generic_retkprobe_filter_arg+0x244a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_244a;
	}
x86_l_1fda:
	/* 0x1fda: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_1fdd:
	/* 0x1fdd: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1fe1:
	/* 0x1fe1: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1fe4:
	/* 0x1fe4: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1fe8:
	/* 0x1fe8: jmp    2458 <generic_retkprobe_filter_arg+0x2458> */
	goto x86_l_2458;
x86_l_1fed:
	/* 0x1fed: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ff0:
	/* 0x1ff0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ff5:
	/* 0x1ff5: ja     2000 <generic_retkprobe_filter_arg+0x2000> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2000;
	}
x86_l_1ff7:
	/* 0x1ff7: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_1ffa:
	/* 0x1ffa: jbe    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 610ULL;
	}
x86_l_2000:
	/* 0x2000: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_2003:
	/* 0x2003: jb     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 177ULL;
	}
x86_l_2009:
	/* 0x2009: mov    rdi,QWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_200d:
	/* 0x200d: mov    rsi,QWORD PTR [r15+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2011:
	/* 0x2011: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2014:
	/* 0x2014: je     201f <generic_retkprobe_filter_arg+0x201f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_201f;
	}
x86_l_2016:
	/* 0x2016: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2019:
	/* 0x2019: jne    2553 <generic_retkprobe_filter_arg+0x2553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2553;
	}
x86_l_201f:
	/* 0x201f: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2022:
	/* 0x2022: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2027:
	/* 0x2027: jg     2566 <generic_retkprobe_filter_arg+0x2566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2566;
	}
x86_l_202d:
	/* 0x202d: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_2030:
	/* 0x2030: jle    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 610ULL;
	}
x86_l_2036:
	/* 0x2036: jmp    2566 <generic_retkprobe_filter_arg+0x2566> */
	goto x86_l_2566;
x86_l_203b:
	/* 0x203b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_203d:
	/* 0x203d: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2040:
	/* 0x2040: jne    204b <generic_retkprobe_filter_arg+0x204b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_204b;
	}
x86_l_2042:
	/* 0x2042: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2045:
	/* 0x2045: je     204b <generic_retkprobe_filter_arg+0x204b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_204b;
	}
x86_l_2047:
	/* 0x2047: movzx  ebx,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_204b:
	/* 0x204b: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_204e:
	/* 0x204e: je     2059 <generic_retkprobe_filter_arg+0x2059> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2059;
	}
x86_l_2050:
	/* 0x2050: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2053:
	/* 0x2053: jne    248b <generic_retkprobe_filter_arg+0x248b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_248b;
	}
x86_l_2059:
	/* 0x2059: movzx  eax,BYTE PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_205e:
	/* 0x205e: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2062:
	/* 0x2062: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2067:
	/* 0x2067: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_206e:
	/* 0x206e: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2073:
	/* 0x2073: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2075:
	/* 0x2075: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2078:
	/* 0x2078: je     23b <generic_retkprobe_filter_arg+0x23b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 571ULL;
	}
x86_l_207e:
	/* 0x207e: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_2080:
	/* 0x2080: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2088:
	/* 0x2088: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_208d:
	/* 0x208d: jmp    1aa0 <generic_retkprobe_filter_arg+0x1aa0> */
	return 6816ULL;
x86_l_2092:
	/* 0x2092: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2095:
	/* 0x2095: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_209b:
	/* 0x209b: jmp    20a6 <generic_retkprobe_filter_arg+0x20a6> */
	goto x86_l_20a6;
x86_l_209d:
	/* 0x209d: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a0:
	/* 0x20a0: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_20a6:
	/* 0x20a6: mov    edx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20aa:
	/* 0x20aa: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_20ad:
	/* 0x20ad: jb     2f55 <generic_retkprobe_filter_arg+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12117ULL;
	}
x86_l_20b3:
	/* 0x20b3: mov    esi,DWORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_20b7:
	/* 0x20b7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_20ba:
	/* 0x20ba: jle    20d7 <generic_retkprobe_filter_arg+0x20d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_20d7;
	}
x86_l_20bc:
	/* 0x20bc: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_20bf:
	/* 0x20bf: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_20c2:
	/* 0x20c2: jae    210c <generic_retkprobe_filter_arg+0x210c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_210c;
	}
x86_l_20c4:
	/* 0x20c4: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20c7:
	/* 0x20c7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20cc:
	/* 0x20cc: jne    283c <generic_retkprobe_filter_arg+0x283c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10300ULL;
	}
x86_l_20d2:
	/* 0x20d2: jmp    2e60 <generic_retkprobe_filter_arg+0x2e60> */
	return 11872ULL;
x86_l_20d7:
	/* 0x20d7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20da:
	/* 0x20da: je     2128 <generic_retkprobe_filter_arg+0x2128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2128;
	}
x86_l_20dc:
	/* 0x20dc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_20df:
	/* 0x20df: jne    283c <generic_retkprobe_filter_arg+0x283c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10300ULL;
	}
x86_l_20e5:
	/* 0x20e5: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_20e8:
	/* 0x20e8: ja     2833 <generic_retkprobe_filter_arg+0x2833> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10291ULL;
	}
x86_l_20ee:
	/* 0x20ee: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_20f4:
	/* 0x20f4: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_20f8:
	/* 0x20f8: jae    2833 <generic_retkprobe_filter_arg+0x2833> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10291ULL;
	}
x86_l_20fe:
	/* 0x20fe: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2101:
	/* 0x2101: jl     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 610ULL;
	}
x86_l_2107:
	/* 0x2107: jmp    283c <generic_retkprobe_filter_arg+0x283c> */
	return 10300ULL;
x86_l_210c:
	/* 0x210c: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_210f:
	/* 0x210f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2114:
	/* 0x2114: jne    283c <generic_retkprobe_filter_arg+0x283c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10300ULL;
	}
x86_l_211a:
	/* 0x211a: test   DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_211d:
	/* 0x211d: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_2123:
	/* 0x2123: jmp    283c <generic_retkprobe_filter_arg+0x283c> */
	return 10300ULL;
x86_l_2128:
	/* 0x2128: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_212b:
	/* 0x212b: ja     2828 <generic_retkprobe_filter_arg+0x2828> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10280ULL;
	}
x86_l_2131:
	/* 0x2131: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2137:
	/* 0x2137: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_213b:
	/* 0x213b: jae    2828 <generic_retkprobe_filter_arg+0x2828> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10280ULL;
	}
x86_l_2141:
	/* 0x2141: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2144:
	/* 0x2144: jg     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 610ULL;
	}
x86_l_214a:
	/* 0x214a: jmp    283c <generic_retkprobe_filter_arg+0x283c> */
	return 10300ULL;
x86_l_214f:
	/* 0x214f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2151:
	/* 0x2151: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2156:
	/* 0x2156: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_215b:
	/* 0x215b: jmp    2406 <generic_retkprobe_filter_arg+0x2406> */
	goto x86_l_2406;
x86_l_2160:
	/* 0x2160: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2162:
	/* 0x2162: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2167:
	/* 0x2167: jmp    2428 <generic_retkprobe_filter_arg+0x2428> */
	goto x86_l_2428;
x86_l_216c:
	/* 0x216c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_216f:
	/* 0x216f: je     270e <generic_retkprobe_filter_arg+0x270e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9998ULL;
	}
x86_l_2175:
	/* 0x2175: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2178:
	/* 0x2178: jne    271a <generic_retkprobe_filter_arg+0x271a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10010ULL;
	}
x86_l_217e:
	/* 0x217e: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2182:
	/* 0x2182: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2184:
	/* 0x2184: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_218a:
	/* 0x218a: jmp    271a <generic_retkprobe_filter_arg+0x271a> */
	return 10010ULL;
x86_l_218f:
	/* 0x218f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2192:
	/* 0x2192: je     274d <generic_retkprobe_filter_arg+0x274d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10061ULL;
	}
x86_l_2198:
	/* 0x2198: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_219b:
	/* 0x219b: jne    2759 <generic_retkprobe_filter_arg+0x2759> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10073ULL;
	}
x86_l_21a1:
	/* 0x21a1: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21a5:
	/* 0x21a5: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_21a7:
	/* 0x21a7: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_21ad:
	/* 0x21ad: jmp    2759 <generic_retkprobe_filter_arg+0x2759> */
	return 10073ULL;
x86_l_21b2:
	/* 0x21b2: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_21b5:
	/* 0x21b5: mov    WORD PTR [rcx],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21b8:
	/* 0x21b8: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_21bc:
	/* 0x21bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21c1:
	/* 0x21c1: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_21c3:
	/* 0x21c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21c5:
	/* 0x21c5: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_21c7:
	/* 0x21c7: jbe    21ea <generic_retkprobe_filter_arg+0x21ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_21ea;
	}
x86_l_21c9:
	/* 0x21c9: lea    rdi,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_21cd:
	/* 0x21cd: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_21d1:
	/* 0x21d1: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21d3:
	/* 0x21d3: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21d9:
	/* 0x21d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21de:
	/* 0x21de: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_21e0:
	/* 0x21e0: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_21e8:
	/* 0x21e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ea:
	/* 0x21ea: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_21ee:
	/* 0x21ee: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_21f2:
	/* 0x21f2: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21f6:
	/* 0x21f6: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_21f9:
	/* 0x21f9: jg     2235 <generic_retkprobe_filter_arg+0x2235> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2235;
	}
x86_l_21fb:
	/* 0x21fb: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21fe:
	/* 0x21fe: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2203:
	/* 0x2203: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2208:
	/* 0x2208: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_220d:
	/* 0x220d: jg     26be <generic_retkprobe_filter_arg+0x26be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9918ULL;
	}
x86_l_2213:
	/* 0x2213: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2215:
	/* 0x2215: je     2a46 <generic_retkprobe_filter_arg+0x2a46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10822ULL;
	}
x86_l_221b:
	/* 0x221b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_221e:
	/* 0x221e: jne    82a <generic_retkprobe_filter_arg+0x82a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2090ULL;
	}
x86_l_2224:
	/* 0x2224: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2229:
	/* 0x2229: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2230:
	/* 0x2230: jmp    2a7c <generic_retkprobe_filter_arg+0x2a7c> */
	return 10876ULL;
x86_l_2235:
	/* 0x2235: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2238:
	/* 0x2238: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_223d:
	/* 0x223d: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2242:
	/* 0x2242: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2247:
	/* 0x2247: jg     26e1 <generic_retkprobe_filter_arg+0x26e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9953ULL;
	}
x86_l_224d:
	/* 0x224d: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2250:
	/* 0x2250: je     2a54 <generic_retkprobe_filter_arg+0x2a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10836ULL;
	}
x86_l_2256:
	/* 0x2256: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2259:
	/* 0x2259: jne    82a <generic_retkprobe_filter_arg+0x82a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2090ULL;
	}
x86_l_225f:
	/* 0x225f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2264:
	/* 0x2264: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_226b:
	/* 0x226b: jmp    2a7c <generic_retkprobe_filter_arg+0x2a7c> */
	return 10876ULL;
x86_l_2270:
	/* 0x2270: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2273:
	/* 0x2273: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_2278:
	/* 0x2278: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_227d:
	/* 0x227d: mov    eax,0x1fe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 510ULL);
x86_l_2282:
	/* 0x2282: cmovae esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_2285:
	/* 0x2285: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2288:
	/* 0x2288: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_228a:
	/* 0x228a: cmp    eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_228f:
	/* 0x228f: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2292:
	/* 0x2292: xor    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 7ULL);
x86_l_2295:
	/* 0x2295: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2297:
	/* 0x2297: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_229a:
	/* 0x229a: mov    eax,DWORD PTR [r15+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_229f:
	/* 0x229f: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_22a2:
	/* 0x22a2: je     2ec6 <generic_retkprobe_filter_arg+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11974ULL;
	}
x86_l_22a8:
	/* 0x22a8: mov    DWORD PTR [rsp+0x4c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_22ac:
	/* 0x22ac: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_22b0:
	/* 0x22b0: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22b4:
	/* 0x22b4: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22b9:
	/* 0x22b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22be:
	/* 0x22be: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_22c5:
	/* 0x22c5: mov    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22ca:
	/* 0x22ca: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_22cd:
	/* 0x22cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22cf:
	/* 0x22cf: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
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
	/* 0x22e3: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_22e6:
	/* 0x22e6: je     2ec6 <generic_retkprobe_filter_arg+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11974ULL;
	}
x86_l_22ec:
	/* 0x22ec: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_22f1:
	/* 0x22f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22f4:
	/* 0x22f4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22f9:
	/* 0x22f9: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22fe:
	/* 0x22fe: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2303:
	/* 0x2303: je     2ed7 <generic_retkprobe_filter_arg+0x2ed7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11991ULL;
	}
x86_l_2309:
	/* 0x2309: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_230c:
	/* 0x230c: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2314:
	/* 0x2314: movzx  ebx,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2319:
	/* 0x2319: cmp    DWORD PTR [rsp+0x28],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691845ULL);
x86_l_231e:
	/* 0x231e: jg     29a1 <generic_retkprobe_filter_arg+0x29a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10657ULL;
	}
x86_l_2324:
	/* 0x2324: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_2327:
	/* 0x2327: mov    BYTE PTR [rcx],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_232a:
	/* 0x232a: lea    rdi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_232e:
	/* 0x232e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2333:
	/* 0x2333: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2335:
	/* 0x2335: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_233a:
	/* 0x233a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_233c:
	/* 0x233c: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_233e:
	/* 0x233e: jbe    29de <generic_retkprobe_filter_arg+0x29de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 10718ULL;
	}
x86_l_2344:
	/* 0x2344: lea    rdi,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2348:
	/* 0x2348: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_234b:
	/* 0x234b: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_234d:
	/* 0x234d: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2353:
	/* 0x2353: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2358:
	/* 0x2358: jmp    29d2 <generic_retkprobe_filter_arg+0x29d2> */
	return 10706ULL;
x86_l_235d:
	/* 0x235d: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2360:
	/* 0x2360: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2364:
	/* 0x2364: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2366:
	/* 0x2366: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_236a:
	/* 0x236a: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_236d:
	/* 0x236d: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2370:
	/* 0x2370: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_2373:
	/* 0x2373: jb     2ad6 <generic_retkprobe_filter_arg+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10966ULL;
	}
x86_l_2379:
	/* 0x2379: mov    r8d,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_237d:
	/* 0x237d: mov    edi,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2381:
	/* 0x2381: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2384:
	/* 0x2384: ja     278c <generic_retkprobe_filter_arg+0x278c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10124ULL;
	}
x86_l_238a:
	/* 0x238a: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_2390:
	/* 0x2390: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_2394:
	/* 0x2394: jae    278c <generic_retkprobe_filter_arg+0x278c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10124ULL;
	}
x86_l_239a:
	/* 0x239a: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_239d:
	/* 0x239d: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_23a1:
	/* 0x23a1: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_23a3:
	/* 0x23a3: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_23a7:
	/* 0x23a7: jmp    2799 <generic_retkprobe_filter_arg+0x2799> */
	return 10137ULL;
x86_l_23ac:
	/* 0x23ac: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_23ae:
	/* 0x23ae: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23b3:
	/* 0x23b3: ja     23bd <generic_retkprobe_filter_arg+0x23bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_23bd;
	}
x86_l_23b5:
	/* 0x23b5: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_23b7:
	/* 0x23b7: jbe    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 610ULL;
	}
x86_l_23bd:
	/* 0x23bd: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_23c0:
	/* 0x23c0: jb     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 177ULL;
	}
x86_l_23c6:
	/* 0x23c6: mov    edi,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23ca:
	/* 0x23ca: mov    esi,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_23ce:
	/* 0x23ce: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_23d1:
	/* 0x23d1: ja     27d8 <generic_retkprobe_filter_arg+0x27d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10200ULL;
	}
x86_l_23d7:
	/* 0x23d7: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_23dd:
	/* 0x23dd: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_23e1:
	/* 0x23e1: jae    27d8 <generic_retkprobe_filter_arg+0x27d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10200ULL;
	}
x86_l_23e7:
	/* 0x23e7: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_23e9:
	/* 0x23e9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ee:
	/* 0x23ee: jg     27e9 <generic_retkprobe_filter_arg+0x27e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10217ULL;
	}
x86_l_23f4:
	/* 0x23f4: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_23f6:
	/* 0x23f6: jle    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 610ULL;
	}
x86_l_23fc:
	/* 0x23fc: jmp    27e9 <generic_retkprobe_filter_arg+0x27e9> */
	return 10217ULL;
x86_l_2401:
	/* 0x2401: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2406:
	/* 0x2406: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_240b:
	/* 0x240b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2410:
	/* 0x2410: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2414:
	/* 0x2414: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2418:
	/* 0x2418: jbe    2c57 <generic_retkprobe_filter_arg+0x2c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11351ULL;
	}
x86_l_241e:
	/* 0x241e: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_2423:
	/* 0x2423: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2428:
	/* 0x2428: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_242d:
	/* 0x242d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2432:
	/* 0x2432: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2437:
	/* 0x2437: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_243b:
	/* 0x243b: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_243f:
	/* 0x243f: jbe    2c57 <generic_retkprobe_filter_arg+0x2c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11351ULL;
	}
x86_l_2445:
	/* 0x2445: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_244a:
	/* 0x244a: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_244d:
	/* 0x244d: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2451:
	/* 0x2451: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2454:
	/* 0x2454: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2458:
	/* 0x2458: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_245b:
	/* 0x245b: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_245e:
	/* 0x245e: cmp    esi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 57ULL);
x86_l_2461:
	/* 0x2461: jb     2ad6 <generic_retkprobe_filter_arg+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10966ULL;
	}
x86_l_2467:
	/* 0x2467: mov    rdi,QWORD PTR [r15+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_246b:
	/* 0x246b: mov    rsi,QWORD PTR [r15+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_246f:
	/* 0x246f: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2472:
	/* 0x2472: je     247d <generic_retkprobe_filter_arg+0x247d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_247d;
	}
x86_l_2474:
	/* 0x2474: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2477:
	/* 0x2477: jne    28e1 <generic_retkprobe_filter_arg+0x28e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10465ULL;
	}
x86_l_247d:
	/* 0x247d: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2480:
	/* 0x2480: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_2483:
	/* 0x2483: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_2486:
	/* 0x2486: jmp    27d0 <generic_retkprobe_filter_arg+0x27d0> */
	return 10192ULL;
x86_l_248b:
	/* 0x248b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_248d:
	/* 0x248d: jmp    24c <generic_retkprobe_filter_arg+0x24c> */
	return 588ULL;
x86_l_2492:
	/* 0x2492: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2497:
	/* 0x2497: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_249a:
	/* 0x249a: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_249e:
	/* 0x249e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24a3:
	/* 0x24a3: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_24a5:
	/* 0x24a5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24aa:
	/* 0x24aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ac:
	/* 0x24ac: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_24b1:
	/* 0x24b1: cmp    esi,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_24b3:
	/* 0x24b3: jbe    24d4 <generic_retkprobe_filter_arg+0x24d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_24d4;
	}
x86_l_24b5:
	/* 0x24b5: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24ba:
	/* 0x24ba: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_24be:
	/* 0x24be: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_24c2:
	/* 0x24c2: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_24c4:
	/* 0x24c4: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24ca:
	/* 0x24ca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24cf:
	/* 0x24cf: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_24d2:
	/* 0x24d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d4:
	/* 0x24d4: mov    eax,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_24db:
	/* 0x24db: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_24df:
	/* 0x24df: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_24e3:
	/* 0x24e3: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_24e6:
	/* 0x24e6: jg     251d <generic_retkprobe_filter_arg+0x251d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_251d;
	}
x86_l_24e8:
	/* 0x24e8: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24eb:
	/* 0x24eb: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24f0:
	/* 0x24f0: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24f5:
	/* 0x24f5: jg     28ef <generic_retkprobe_filter_arg+0x28ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10479ULL;
	}
x86_l_24fb:
	/* 0x24fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24fd:
	/* 0x24fd: je     2bdd <generic_retkprobe_filter_arg+0x2bdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11229ULL;
	}
x86_l_2503:
	/* 0x2503: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2506:
	/* 0x2506: jne    2c70 <generic_retkprobe_filter_arg+0x2c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11376ULL;
	}
x86_l_250c:
	/* 0x250c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2511:
	/* 0x2511: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2518:
	/* 0x2518: jmp    2c13 <generic_retkprobe_filter_arg+0x2c13> */
	return 11283ULL;
x86_l_251d:
	/* 0x251d: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2520:
	/* 0x2520: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2525:
	/* 0x2525: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_252a:
	/* 0x252a: jg     2912 <generic_retkprobe_filter_arg+0x2912> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10514ULL;
	}
x86_l_2530:
	/* 0x2530: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2533:
	/* 0x2533: je     2beb <generic_retkprobe_filter_arg+0x2beb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11243ULL;
	}
x86_l_2539:
	/* 0x2539: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_253c:
	/* 0x253c: jne    2c70 <generic_retkprobe_filter_arg+0x2c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11376ULL;
	}
x86_l_2542:
	/* 0x2542: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2547:
	/* 0x2547: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_254e:
	/* 0x254e: jmp    2c13 <generic_retkprobe_filter_arg+0x2c13> */
	return 11283ULL;
x86_l_2553:
	/* 0x2553: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2556:
	/* 0x2556: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_255b:
	/* 0x255b: ja     2566 <generic_retkprobe_filter_arg+0x2566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2566;
	}
x86_l_255d:
	/* 0x255d: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_2560:
	/* 0x2560: jbe    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 610ULL;
	}
x86_l_2566:
	/* 0x2566: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_2569:
	/* 0x2569: jb     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 177ULL;
	}
x86_l_256f:
	/* 0x256f: mov    rsi,QWORD PTR [r15+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2573:
	/* 0x2573: mov    rdx,QWORD PTR [r15+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2577:
	/* 0x2577: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_257a:
	/* 0x257a: je     2585 <generic_retkprobe_filter_arg+0x2585> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2585;
	}
x86_l_257c:
	/* 0x257c: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_257f:
	/* 0x257f: jne    2935 <generic_retkprobe_filter_arg+0x2935> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10549ULL;
	}
x86_l_2585:
	/* 0x2585: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2588:
	/* 0x2588: jg     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 177ULL;
	}
x86_l_258e:
	/* 0x258e: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2591:
	/* 0x2591: jle    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 610ULL;
	}
x86_l_2597:
	/* 0x2597: jmp    b1 <generic_retkprobe_filter_arg+0xb1> */
	return 177ULL;
x86_l_259c:
	/* 0x259c: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25a0:
	/* 0x25a0: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_25a6:
	/* 0x25a6: jmp    25b2 <generic_retkprobe_filter_arg+0x25b2> */
	goto x86_l_25b2;
x86_l_25a8:
	/* 0x25a8: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25ac:
	/* 0x25ac: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_25b2:
	/* 0x25b2: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_25b5:
	/* 0x25b5: jb     2f55 <generic_retkprobe_filter_arg+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12117ULL;
	}
x86_l_25bb:
	/* 0x25bb: mov    rsi,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25bf:
	/* 0x25bf: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_25c2:
	/* 0x25c2: jle    25e0 <generic_retkprobe_filter_arg+0x25e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9696ULL;
	}
	return 9668ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9668ULL: goto x86_l_25c4;
	case 9671ULL: goto x86_l_25c7;
	case 9674ULL: goto x86_l_25ca;
	case 9676ULL: goto x86_l_25cc;
	case 9680ULL: goto x86_l_25d0;
	case 9685ULL: goto x86_l_25d5;
	case 9691ULL: goto x86_l_25db;
	case 9696ULL: goto x86_l_25e0;
	case 9699ULL: goto x86_l_25e3;
	case 9705ULL: goto x86_l_25e9;
	case 9708ULL: goto x86_l_25ec;
	case 9714ULL: goto x86_l_25f2;
	case 9717ULL: goto x86_l_25f5;
	case 9719ULL: goto x86_l_25f7;
	case 9722ULL: goto x86_l_25fa;
	case 9728ULL: goto x86_l_2600;
	case 9732ULL: goto x86_l_2604;
	case 9738ULL: goto x86_l_260a;
	case 9743ULL: goto x86_l_260f;
	case 9746ULL: goto x86_l_2612;
	case 9751ULL: goto x86_l_2617;
	case 9757ULL: goto x86_l_261d;
	case 9761ULL: goto x86_l_2621;
	case 9767ULL: goto x86_l_2627;
	case 9772ULL: goto x86_l_262c;
	case 9775ULL: goto x86_l_262f;
	case 9781ULL: goto x86_l_2635;
	case 9785ULL: goto x86_l_2639;
	case 9787ULL: goto x86_l_263b;
	case 9793ULL: goto x86_l_2641;
	case 9798ULL: goto x86_l_2646;
	case 9801ULL: goto x86_l_2649;
	case 9807ULL: goto x86_l_264f;
	case 9811ULL: goto x86_l_2653;
	case 9813ULL: goto x86_l_2655;
	case 9819ULL: goto x86_l_265b;
	case 9824ULL: goto x86_l_2660;
	case 9829ULL: goto x86_l_2665;
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9842ULL: goto x86_l_2672;
	case 9847ULL: goto x86_l_2677;
	case 9852ULL: goto x86_l_267c;
	case 9857ULL: goto x86_l_2681;
	case 9862ULL: goto x86_l_2686;
	case 9867ULL: goto x86_l_268b;
	case 9870ULL: goto x86_l_268e;
	case 9872ULL: goto x86_l_2690;
	case 9875ULL: goto x86_l_2693;
	case 9881ULL: goto x86_l_2699;
	case 9885ULL: goto x86_l_269d;
	case 9891ULL: goto x86_l_26a3;
	case 9896ULL: goto x86_l_26a8;
	case 9898ULL: goto x86_l_26aa;
	case 9903ULL: goto x86_l_26af;
	case 9908ULL: goto x86_l_26b4;
	case 9913ULL: goto x86_l_26b9;
	case 9918ULL: goto x86_l_26be;
	case 9921ULL: goto x86_l_26c1;
	case 9927ULL: goto x86_l_26c7;
	case 9930ULL: goto x86_l_26ca;
	case 9936ULL: goto x86_l_26d0;
	case 9941ULL: goto x86_l_26d5;
	case 9948ULL: goto x86_l_26dc;
	case 9953ULL: goto x86_l_26e1;
	case 9956ULL: goto x86_l_26e4;
	case 9962ULL: goto x86_l_26ea;
	case 9965ULL: goto x86_l_26ed;
	case 9971ULL: goto x86_l_26f3;
	case 9976ULL: goto x86_l_26f8;
	case 9983ULL: goto x86_l_26ff;
	case 9988ULL: goto x86_l_2704;
	case 9993ULL: goto x86_l_2709;
	case 9998ULL: goto x86_l_270e;
	case 10002ULL: goto x86_l_2712;
	case 10004ULL: goto x86_l_2714;
	case 10010ULL: goto x86_l_271a;
	case 10013ULL: goto x86_l_271d;
	case 10019ULL: goto x86_l_2723;
	case 10023ULL: goto x86_l_2727;
	case 10026ULL: goto x86_l_272a;
	case 10032ULL: goto x86_l_2730;
	case 10035ULL: goto x86_l_2733;
	case 10038ULL: goto x86_l_2736;
	case 10044ULL: goto x86_l_273c;
	case 10048ULL: goto x86_l_2740;
	case 10050ULL: goto x86_l_2742;
	case 10056ULL: goto x86_l_2748;
	case 10061ULL: goto x86_l_274d;
	case 10065ULL: goto x86_l_2751;
	case 10067ULL: goto x86_l_2753;
	case 10073ULL: goto x86_l_2759;
	case 10076ULL: goto x86_l_275c;
	case 10082ULL: goto x86_l_2762;
	case 10086ULL: goto x86_l_2766;
	case 10089ULL: goto x86_l_2769;
	case 10095ULL: goto x86_l_276f;
	case 10098ULL: goto x86_l_2772;
	case 10101ULL: goto x86_l_2775;
	case 10107ULL: goto x86_l_277b;
	case 10111ULL: goto x86_l_277f;
	case 10113ULL: goto x86_l_2781;
	case 10119ULL: goto x86_l_2787;
	case 10124ULL: goto x86_l_278c;
	case 10127ULL: goto x86_l_278f;
	case 10131ULL: goto x86_l_2793;
	case 10133ULL: goto x86_l_2795;
	case 10137ULL: goto x86_l_2799;
	case 10140ULL: goto x86_l_279c;
	case 10143ULL: goto x86_l_279f;
	case 10146ULL: goto x86_l_27a2;
	case 10152ULL: goto x86_l_27a8;
	case 10156ULL: goto x86_l_27ac;
	case 10160ULL: goto x86_l_27b0;
	case 10163ULL: goto x86_l_27b3;
	case 10169ULL: goto x86_l_27b9;
	case 10175ULL: goto x86_l_27bf;
	case 10179ULL: goto x86_l_27c3;
	case 10185ULL: goto x86_l_27c9;
	case 10187ULL: goto x86_l_27cb;
	case 10190ULL: goto x86_l_27ce;
	case 10192ULL: goto x86_l_27d0;
	case 10195ULL: goto x86_l_27d3;
	case 10200ULL: goto x86_l_27d8;
	case 10202ULL: goto x86_l_27da;
	case 10207ULL: goto x86_l_27df;
	case 10209ULL: goto x86_l_27e1;
	case 10211ULL: goto x86_l_27e3;
	case 10217ULL: goto x86_l_27e9;
	case 10220ULL: goto x86_l_27ec;
	case 10226ULL: goto x86_l_27f2;
	case 10230ULL: goto x86_l_27f6;
	case 10234ULL: goto x86_l_27fa;
	case 10237ULL: goto x86_l_27fd;
	case 10243ULL: goto x86_l_2803;
	case 10249ULL: goto x86_l_2809;
	case 10253ULL: goto x86_l_280d;
	case 10259ULL: goto x86_l_2813;
	case 10261ULL: goto x86_l_2815;
	case 10267ULL: goto x86_l_281b;
	case 10269ULL: goto x86_l_281d;
	case 10275ULL: goto x86_l_2823;
	case 10280ULL: goto x86_l_2828;
	case 10283ULL: goto x86_l_282b;
	case 10289ULL: goto x86_l_2831;
	case 10291ULL: goto x86_l_2833;
	case 10294ULL: goto x86_l_2836;
	case 10300ULL: goto x86_l_283c;
	case 10303ULL: goto x86_l_283f;
	case 10309ULL: goto x86_l_2845;
	case 10313ULL: goto x86_l_2849;
	case 10316ULL: goto x86_l_284c;
	case 10318ULL: goto x86_l_284e;
	case 10321ULL: goto x86_l_2851;
	case 10324ULL: goto x86_l_2854;
	case 10326ULL: goto x86_l_2856;
	case 10329ULL: goto x86_l_2859;
	case 10334ULL: goto x86_l_285e;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10348ULL: goto x86_l_286c;
	case 10350ULL: goto x86_l_286e;
	case 10353ULL: goto x86_l_2871;
	case 10359ULL: goto x86_l_2877;
	case 10362ULL: goto x86_l_287a;
	case 10368ULL: goto x86_l_2880;
	case 10374ULL: goto x86_l_2886;
	case 10378ULL: goto x86_l_288a;
	case 10384ULL: goto x86_l_2890;
	case 10387ULL: goto x86_l_2893;
	case 10393ULL: goto x86_l_2899;
	case 10398ULL: goto x86_l_289e;
	case 10401ULL: goto x86_l_28a1;
	case 10406ULL: goto x86_l_28a6;
	case 10412ULL: goto x86_l_28ac;
	case 10415ULL: goto x86_l_28af;
	case 10421ULL: goto x86_l_28b5;
	case 10426ULL: goto x86_l_28ba;
	case 10429ULL: goto x86_l_28bd;
	case 10435ULL: goto x86_l_28c3;
	case 10441ULL: goto x86_l_28c9;
	case 10445ULL: goto x86_l_28cd;
	case 10451ULL: goto x86_l_28d3;
	case 10454ULL: goto x86_l_28d6;
	case 10460ULL: goto x86_l_28dc;
	case 10465ULL: goto x86_l_28e1;
	case 10468ULL: goto x86_l_28e4;
	case 10471ULL: goto x86_l_28e7;
	case 10474ULL: goto x86_l_28ea;
	case 10479ULL: goto x86_l_28ef;
	case 10482ULL: goto x86_l_28f2;
	case 10488ULL: goto x86_l_28f8;
	case 10491ULL: goto x86_l_28fb;
	case 10497ULL: goto x86_l_2901;
	case 10502ULL: goto x86_l_2906;
	case 10509ULL: goto x86_l_290d;
	case 10514ULL: goto x86_l_2912;
	case 10517ULL: goto x86_l_2915;
	case 10523ULL: goto x86_l_291b;
	case 10526ULL: goto x86_l_291e;
	case 10532ULL: goto x86_l_2924;
	case 10537ULL: goto x86_l_2929;
	case 10544ULL: goto x86_l_2930;
	case 10549ULL: goto x86_l_2935;
	case 10552ULL: goto x86_l_2938;
	case 10558ULL: goto x86_l_293e;
	case 10561ULL: goto x86_l_2941;
	case 10567ULL: goto x86_l_2947;
	case 10572ULL: goto x86_l_294c;
	case 10575ULL: goto x86_l_294f;
	case 10581ULL: goto x86_l_2955;
	case 10584ULL: goto x86_l_2958;
	case 10590ULL: goto x86_l_295e;
	case 10594ULL: goto x86_l_2962;
	case 10596ULL: goto x86_l_2964;
	case 10602ULL: goto x86_l_296a;
	case 10607ULL: goto x86_l_296f;
	case 10610ULL: goto x86_l_2972;
	case 10616ULL: goto x86_l_2978;
	case 10619ULL: goto x86_l_297b;
	case 10625ULL: goto x86_l_2981;
	case 10629ULL: goto x86_l_2985;
	case 10631ULL: goto x86_l_2987;
	case 10637ULL: goto x86_l_298d;
	case 10642ULL: goto x86_l_2992;
	case 10647ULL: goto x86_l_2997;
	case 10652ULL: goto x86_l_299c;
	case 10657ULL: goto x86_l_29a1;
	case 10660ULL: goto x86_l_29a4;
	case 10663ULL: goto x86_l_29a7;
	case 10667ULL: goto x86_l_29ab;
	case 10672ULL: goto x86_l_29b0;
	case 10674ULL: goto x86_l_29b2;
	case 10679ULL: goto x86_l_29b7;
	case 10681ULL: goto x86_l_29b9;
	case 10683ULL: goto x86_l_29bb;
	case 10685ULL: goto x86_l_29bd;
	case 10689ULL: goto x86_l_29c1;
	case 10693ULL: goto x86_l_29c5;
	case 10695ULL: goto x86_l_29c7;
	case 10701ULL: goto x86_l_29cd;
	case 10706ULL: goto x86_l_29d2;
	case 10708ULL: goto x86_l_29d4;
	case 10716ULL: goto x86_l_29dc;
	case 10718ULL: goto x86_l_29de;
	case 10722ULL: goto x86_l_29e2;
	case 10726ULL: goto x86_l_29e6;
	case 10730ULL: goto x86_l_29ea;
	case 10733ULL: goto x86_l_29ed;
	case 10735ULL: goto x86_l_29ef;
	case 10738ULL: goto x86_l_29f2;
	case 10744ULL: goto x86_l_29f8;
	case 10746ULL: goto x86_l_29fa;
	case 10752ULL: goto x86_l_2a00;
	case 10755ULL: goto x86_l_2a03;
	case 10761ULL: goto x86_l_2a09;
	case 10766ULL: goto x86_l_2a0e;
	case 10773ULL: goto x86_l_2a15;
	case 10778ULL: goto x86_l_2a1a;
	case 10781ULL: goto x86_l_2a1d;
	case 10787ULL: goto x86_l_2a23;
	case 10790ULL: goto x86_l_2a26;
	case 10796ULL: goto x86_l_2a2c;
	case 10799ULL: goto x86_l_2a2f;
	case 10805ULL: goto x86_l_2a35;
	case 10810ULL: goto x86_l_2a3a;
	case 10817ULL: goto x86_l_2a41;
	case 10822ULL: goto x86_l_2a46;
	case 10827ULL: goto x86_l_2a4b;
	case 10834ULL: goto x86_l_2a52;
	case 10836ULL: goto x86_l_2a54;
	case 10841ULL: goto x86_l_2a59;
	case 10848ULL: goto x86_l_2a60;
	case 10850ULL: goto x86_l_2a62;
	case 10855ULL: goto x86_l_2a67;
	case 10862ULL: goto x86_l_2a6e;
	case 10864ULL: goto x86_l_2a70;
	case 10869ULL: goto x86_l_2a75;
	case 10876ULL: goto x86_l_2a7c;
	case 10881ULL: goto x86_l_2a81;
	case 10883ULL: goto x86_l_2a83;
	case 10886ULL: goto x86_l_2a86;
	case 10888ULL: goto x86_l_2a88;
	case 10893ULL: goto x86_l_2a8d;
	case 10896ULL: goto x86_l_2a90;
	case 10899ULL: goto x86_l_2a93;
	case 10901ULL: goto x86_l_2a95;
	case 10903ULL: goto x86_l_2a97;
	case 10906ULL: goto x86_l_2a9a;
	case 10909ULL: goto x86_l_2a9d;
	case 10911ULL: goto x86_l_2a9f;
	case 10913ULL: goto x86_l_2aa1;
	case 10918ULL: goto x86_l_2aa6;
	case 10923ULL: goto x86_l_2aab;
	case 10928ULL: goto x86_l_2ab0;
	case 10933ULL: goto x86_l_2ab5;
	case 10937ULL: goto x86_l_2ab9;
	case 10941ULL: goto x86_l_2abd;
	case 10947ULL: goto x86_l_2ac3;
	case 10952ULL: goto x86_l_2ac8;
	case 10954ULL: goto x86_l_2aca;
	case 10957ULL: goto x86_l_2acd;
	case 10959ULL: goto x86_l_2acf;
	case 10962ULL: goto x86_l_2ad2;
	case 10964ULL: goto x86_l_2ad4;
	case 10966ULL: goto x86_l_2ad6;
	case 10971ULL: goto x86_l_2adb;
	case 10973ULL: goto x86_l_2add;
	case 10979ULL: goto x86_l_2ae3;
	case 10984ULL: goto x86_l_2ae8;
	case 10988ULL: goto x86_l_2aec;
	case 10994ULL: goto x86_l_2af2;
	case 10996ULL: goto x86_l_2af4;
	case 11000ULL: goto x86_l_2af8;
	case 11006ULL: goto x86_l_2afe;
	case 11009ULL: goto x86_l_2b01;
	case 11015ULL: goto x86_l_2b07;
	case 11019ULL: goto x86_l_2b0b;
	case 11022ULL: goto x86_l_2b0e;
	case 11024ULL: goto x86_l_2b10;
	case 11027ULL: goto x86_l_2b13;
	case 11030ULL: goto x86_l_2b16;
	case 11032ULL: goto x86_l_2b18;
	case 11035ULL: goto x86_l_2b1b;
	case 11041ULL: goto x86_l_2b21;
	case 11044ULL: goto x86_l_2b24;
	case 11050ULL: goto x86_l_2b2a;
	case 11054ULL: goto x86_l_2b2e;
	case 11060ULL: goto x86_l_2b34;
	case 11065ULL: goto x86_l_2b39;
	case 11068ULL: goto x86_l_2b3c;
	case 11074ULL: goto x86_l_2b42;
	case 11077ULL: goto x86_l_2b45;
	case 11083ULL: goto x86_l_2b4b;
	case 11086ULL: goto x86_l_2b4e;
	case 11088ULL: goto x86_l_2b50;
	case 11091ULL: goto x86_l_2b53;
	case 11097ULL: goto x86_l_2b59;
	case 11101ULL: goto x86_l_2b5d;
	case 11107ULL: goto x86_l_2b63;
	case 11112ULL: goto x86_l_2b68;
	case 11116ULL: goto x86_l_2b6c;
	case 11122ULL: goto x86_l_2b72;
	case 11127ULL: goto x86_l_2b77;
	case 11130ULL: goto x86_l_2b7a;
	case 11136ULL: goto x86_l_2b80;
	case 11140ULL: goto x86_l_2b84;
	case 11142ULL: goto x86_l_2b86;
	case 11148ULL: goto x86_l_2b8c;
	case 11153ULL: goto x86_l_2b91;
	case 11156ULL: goto x86_l_2b94;
	case 11162ULL: goto x86_l_2b9a;
	case 11166ULL: goto x86_l_2b9e;
	case 11168ULL: goto x86_l_2ba0;
	case 11174ULL: goto x86_l_2ba6;
	case 11179ULL: goto x86_l_2bab;
	case 11181ULL: goto x86_l_2bad;
	case 11187ULL: goto x86_l_2bb3;
	case 11189ULL: goto x86_l_2bb5;
	case 11195ULL: goto x86_l_2bbb;
	case 11200ULL: goto x86_l_2bc0;
	case 11203ULL: goto x86_l_2bc3;
	case 11205ULL: goto x86_l_2bc5;
	case 11208ULL: goto x86_l_2bc8;
	case 11214ULL: goto x86_l_2bce;
	case 11218ULL: goto x86_l_2bd2;
	case 11224ULL: goto x86_l_2bd8;
	case 11229ULL: goto x86_l_2bdd;
	case 11234ULL: goto x86_l_2be2;
	case 11241ULL: goto x86_l_2be9;
	case 11243ULL: goto x86_l_2beb;
	case 11248ULL: goto x86_l_2bf0;
	case 11255ULL: goto x86_l_2bf7;
	case 11257ULL: goto x86_l_2bf9;
	case 11262ULL: goto x86_l_2bfe;
	case 11269ULL: goto x86_l_2c05;
	case 11271ULL: goto x86_l_2c07;
	case 11276ULL: goto x86_l_2c0c;
	case 11283ULL: goto x86_l_2c13;
	case 11288ULL: goto x86_l_2c18;
	case 11290ULL: goto x86_l_2c1a;
	case 11293ULL: goto x86_l_2c1d;
	case 11295ULL: goto x86_l_2c1f;
	case 11300ULL: goto x86_l_2c24;
	default: return 0xffffffffffffffffULL;
	}
x86_l_25c4:
	/* 0x25c4: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_25c7:
	/* 0x25c7: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_25ca:
	/* 0x25ca: jae    260f <generic_retkprobe_filter_arg+0x260f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_260f;
	}
x86_l_25cc:
	/* 0x25cc: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25d0:
	/* 0x25d0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25d5:
	/* 0x25d5: jne    2afe <generic_retkprobe_filter_arg+0x2afe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2afe;
	}
x86_l_25db:
	/* 0x25db: jmp    2e60 <generic_retkprobe_filter_arg+0x2e60> */
	return 11872ULL;
x86_l_25e0:
	/* 0x25e0: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25e3:
	/* 0x25e3: je     268b <generic_retkprobe_filter_arg+0x268b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_268b;
	}
x86_l_25e9:
	/* 0x25e9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_25ec:
	/* 0x25ec: jne    2afe <generic_retkprobe_filter_arg+0x2afe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2afe;
	}
x86_l_25f2:
	/* 0x25f2: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_25f5:
	/* 0x25f5: je     2600 <generic_retkprobe_filter_arg+0x2600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2600;
	}
x86_l_25f7:
	/* 0x25f7: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_25fa:
	/* 0x25fa: jne    2af4 <generic_retkprobe_filter_arg+0x2af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2af4;
	}
x86_l_2600:
	/* 0x2600: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2604:
	/* 0x2604: jl     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 610ULL;
	}
x86_l_260a:
	/* 0x260a: jmp    2afe <generic_retkprobe_filter_arg+0x2afe> */
	goto x86_l_2afe;
x86_l_260f:
	/* 0x260f: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2612:
	/* 0x2612: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2617:
	/* 0x2617: jne    2afe <generic_retkprobe_filter_arg+0x2afe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2afe;
	}
x86_l_261d:
	/* 0x261d: test   QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2621:
	/* 0x2621: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_2627:
	/* 0x2627: jmp    2afe <generic_retkprobe_filter_arg+0x2afe> */
	goto x86_l_2afe;
x86_l_262c:
	/* 0x262c: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_262f:
	/* 0x262f: jne    271a <generic_retkprobe_filter_arg+0x271a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_271a;
	}
x86_l_2635:
	/* 0x2635: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2639:
	/* 0x2639: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_263b:
	/* 0x263b: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_2641:
	/* 0x2641: jmp    271a <generic_retkprobe_filter_arg+0x271a> */
	goto x86_l_271a;
x86_l_2646:
	/* 0x2646: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2649:
	/* 0x2649: jne    2759 <generic_retkprobe_filter_arg+0x2759> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2759;
	}
x86_l_264f:
	/* 0x264f: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2653:
	/* 0x2653: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2655:
	/* 0x2655: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_265b:
	/* 0x265b: jmp    2759 <generic_retkprobe_filter_arg+0x2759> */
	goto x86_l_2759;
x86_l_2660:
	/* 0x2660: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2665:
	/* 0x2665: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_266a:
	/* 0x266a: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_266f:
	/* 0x266f: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2672:
	/* 0x2672: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_2677:
	/* 0x2677: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_267c:
	/* 0x267c: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2681:
	/* 0x2681: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2686:
	/* 0x2686: jmp    1aea <generic_retkprobe_filter_arg+0x1aea> */
	return 6890ULL;
x86_l_268b:
	/* 0x268b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_268e:
	/* 0x268e: je     2699 <generic_retkprobe_filter_arg+0x2699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2699;
	}
x86_l_2690:
	/* 0x2690: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2693:
	/* 0x2693: jne    2ae8 <generic_retkprobe_filter_arg+0x2ae8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ae8;
	}
x86_l_2699:
	/* 0x2699: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_269d:
	/* 0x269d: jg     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 610ULL;
	}
x86_l_26a3:
	/* 0x26a3: jmp    2afe <generic_retkprobe_filter_arg+0x2afe> */
	goto x86_l_2afe;
x86_l_26a8:
	/* 0x26a8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26aa:
	/* 0x26aa: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26af:
	/* 0x26af: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26b4:
	/* 0x26b4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26b9:
	/* 0x26b9: jmp    2ed7 <generic_retkprobe_filter_arg+0x2ed7> */
	return 11991ULL;
x86_l_26be:
	/* 0x26be: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_26c1:
	/* 0x26c1: je     2a62 <generic_retkprobe_filter_arg+0x2a62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a62;
	}
x86_l_26c7:
	/* 0x26c7: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_26ca:
	/* 0x26ca: jne    82a <generic_retkprobe_filter_arg+0x82a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2090ULL;
	}
x86_l_26d0:
	/* 0x26d0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26d5:
	/* 0x26d5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_26dc:
	/* 0x26dc: jmp    2a7c <generic_retkprobe_filter_arg+0x2a7c> */
	goto x86_l_2a7c;
x86_l_26e1:
	/* 0x26e1: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_26e4:
	/* 0x26e4: je     2a70 <generic_retkprobe_filter_arg+0x2a70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a70;
	}
x86_l_26ea:
	/* 0x26ea: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_26ed:
	/* 0x26ed: jne    82a <generic_retkprobe_filter_arg+0x82a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2090ULL;
	}
x86_l_26f3:
	/* 0x26f3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26f8:
	/* 0x26f8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_26ff:
	/* 0x26ff: jmp    2a7c <generic_retkprobe_filter_arg+0x2a7c> */
	goto x86_l_2a7c;
x86_l_2704:
	/* 0x2704: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2709:
	/* 0x2709: jmp    2ec8 <generic_retkprobe_filter_arg+0x2ec8> */
	return 11976ULL;
x86_l_270e:
	/* 0x270e: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2712:
	/* 0x2712: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2714:
	/* 0x2714: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_271a:
	/* 0x271a: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_271d:
	/* 0x271d: jb     2f55 <generic_retkprobe_filter_arg+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12117ULL;
	}
x86_l_2723:
	/* 0x2723: mov    edx,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2727:
	/* 0x2727: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_272a:
	/* 0x272a: jle    294c <generic_retkprobe_filter_arg+0x294c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_294c;
	}
x86_l_2730:
	/* 0x2730: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2733:
	/* 0x2733: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2736:
	/* 0x2736: jae    2b77 <generic_retkprobe_filter_arg+0x2b77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2b77;
	}
x86_l_273c:
	/* 0x273c: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2740:
	/* 0x2740: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2742:
	/* 0x2742: jne    2cd8 <generic_retkprobe_filter_arg+0x2cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11480ULL;
	}
x86_l_2748:
	/* 0x2748: jmp    2e60 <generic_retkprobe_filter_arg+0x2e60> */
	return 11872ULL;
x86_l_274d:
	/* 0x274d: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2751:
	/* 0x2751: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2753:
	/* 0x2753: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_2759:
	/* 0x2759: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_275c:
	/* 0x275c: jb     2f55 <generic_retkprobe_filter_arg+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12117ULL;
	}
x86_l_2762:
	/* 0x2762: mov    edx,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2766:
	/* 0x2766: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2769:
	/* 0x2769: jle    296f <generic_retkprobe_filter_arg+0x296f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_296f;
	}
x86_l_276f:
	/* 0x276f: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2772:
	/* 0x2772: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2775:
	/* 0x2775: jae    2b91 <generic_retkprobe_filter_arg+0x2b91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2b91;
	}
x86_l_277b:
	/* 0x277b: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_277f:
	/* 0x277f: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2781:
	/* 0x2781: jne    2d1e <generic_retkprobe_filter_arg+0x2d1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11550ULL;
	}
x86_l_2787:
	/* 0x2787: jmp    2e60 <generic_retkprobe_filter_arg+0x2e60> */
	return 11872ULL;
x86_l_278c:
	/* 0x278c: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_278f:
	/* 0x278f: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2793:
	/* 0x2793: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2795:
	/* 0x2795: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2799:
	/* 0x2799: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_279c:
	/* 0x279c: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_279f:
	/* 0x279f: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_27a2:
	/* 0x27a2: jb     2ad6 <generic_retkprobe_filter_arg+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ad6;
	}
x86_l_27a8:
	/* 0x27a8: mov    edi,DWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27ac:
	/* 0x27ac: mov    esi,DWORD PTR [r15+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_27b0:
	/* 0x27b0: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_27b3:
	/* 0x27b3: ja     2ac8 <generic_retkprobe_filter_arg+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ac8;
	}
x86_l_27b9:
	/* 0x27b9: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_27bf:
	/* 0x27bf: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_27c3:
	/* 0x27c3: jae    2ac8 <generic_retkprobe_filter_arg+0x2ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2ac8;
	}
x86_l_27c9:
	/* 0x27c9: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_27cb:
	/* 0x27cb: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_27ce:
	/* 0x27ce: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_27d0:
	/* 0x27d0: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_27d3:
	/* 0x27d3: jmp    2ad2 <generic_retkprobe_filter_arg+0x2ad2> */
	goto x86_l_2ad2;
x86_l_27d8:
	/* 0x27d8: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_27da:
	/* 0x27da: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27df:
	/* 0x27df: ja     27e9 <generic_retkprobe_filter_arg+0x27e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_27e9;
	}
x86_l_27e1:
	/* 0x27e1: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_27e3:
	/* 0x27e3: jbe    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 610ULL;
	}
x86_l_27e9:
	/* 0x27e9: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_27ec:
	/* 0x27ec: jb     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 177ULL;
	}
x86_l_27f2:
	/* 0x27f2: mov    esi,DWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27f6:
	/* 0x27f6: mov    edx,DWORD PTR [r15+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_27fa:
	/* 0x27fa: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_27fd:
	/* 0x27fd: ja     2bab <generic_retkprobe_filter_arg+0x2bab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2bab;
	}
x86_l_2803:
	/* 0x2803: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2809:
	/* 0x2809: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_280d:
	/* 0x280d: jae    2bab <generic_retkprobe_filter_arg+0x2bab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2bab;
	}
x86_l_2813:
	/* 0x2813: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2815:
	/* 0x2815: jg     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 177ULL;
	}
x86_l_281b:
	/* 0x281b: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_281d:
	/* 0x281d: jle    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 610ULL;
	}
x86_l_2823:
	/* 0x2823: jmp    b1 <generic_retkprobe_filter_arg+0xb1> */
	return 177ULL;
x86_l_2828:
	/* 0x2828: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_282b:
	/* 0x282b: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_2831:
	/* 0x2831: jmp    283c <generic_retkprobe_filter_arg+0x283c> */
	goto x86_l_283c;
x86_l_2833:
	/* 0x2833: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2836:
	/* 0x2836: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_283c:
	/* 0x283c: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_283f:
	/* 0x283f: jb     2f55 <generic_retkprobe_filter_arg+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12117ULL;
	}
x86_l_2845:
	/* 0x2845: mov    esi,DWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2849:
	/* 0x2849: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_284c:
	/* 0x284c: jle    2869 <generic_retkprobe_filter_arg+0x2869> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2869;
	}
x86_l_284e:
	/* 0x284e: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2851:
	/* 0x2851: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2854:
	/* 0x2854: jae    289e <generic_retkprobe_filter_arg+0x289e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_289e;
	}
x86_l_2856:
	/* 0x2856: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2859:
	/* 0x2859: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_285e:
	/* 0x285e: jne    2d77 <generic_retkprobe_filter_arg+0x2d77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11639ULL;
	}
x86_l_2864:
	/* 0x2864: jmp    2e60 <generic_retkprobe_filter_arg+0x2e60> */
	return 11872ULL;
x86_l_2869:
	/* 0x2869: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_286c:
	/* 0x286c: je     28ba <generic_retkprobe_filter_arg+0x28ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28ba;
	}
x86_l_286e:
	/* 0x286e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2871:
	/* 0x2871: jne    2d77 <generic_retkprobe_filter_arg+0x2d77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11639ULL;
	}
x86_l_2877:
	/* 0x2877: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_287a:
	/* 0x287a: ja     2d6e <generic_retkprobe_filter_arg+0x2d6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11630ULL;
	}
x86_l_2880:
	/* 0x2880: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2886:
	/* 0x2886: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_288a:
	/* 0x288a: jae    2d6e <generic_retkprobe_filter_arg+0x2d6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11630ULL;
	}
x86_l_2890:
	/* 0x2890: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2893:
	/* 0x2893: jl     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 610ULL;
	}
x86_l_2899:
	/* 0x2899: jmp    2d77 <generic_retkprobe_filter_arg+0x2d77> */
	return 11639ULL;
x86_l_289e:
	/* 0x289e: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_28a1:
	/* 0x28a1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28a6:
	/* 0x28a6: jne    2d77 <generic_retkprobe_filter_arg+0x2d77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11639ULL;
	}
x86_l_28ac:
	/* 0x28ac: test   DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28af:
	/* 0x28af: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_28b5:
	/* 0x28b5: jmp    2d77 <generic_retkprobe_filter_arg+0x2d77> */
	return 11639ULL;
x86_l_28ba:
	/* 0x28ba: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_28bd:
	/* 0x28bd: ja     2d63 <generic_retkprobe_filter_arg+0x2d63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11619ULL;
	}
x86_l_28c3:
	/* 0x28c3: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_28c9:
	/* 0x28c9: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_28cd:
	/* 0x28cd: jae    2d63 <generic_retkprobe_filter_arg+0x2d63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11619ULL;
	}
x86_l_28d3:
	/* 0x28d3: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d6:
	/* 0x28d6: jg     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 610ULL;
	}
x86_l_28dc:
	/* 0x28dc: jmp    2d77 <generic_retkprobe_filter_arg+0x2d77> */
	return 11639ULL;
x86_l_28e1:
	/* 0x28e1: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_28e4:
	/* 0x28e4: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_28e7:
	/* 0x28e7: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_28ea:
	/* 0x28ea: jmp    2acf <generic_retkprobe_filter_arg+0x2acf> */
	goto x86_l_2acf;
x86_l_28ef:
	/* 0x28ef: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28f2:
	/* 0x28f2: je     2bf9 <generic_retkprobe_filter_arg+0x2bf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bf9;
	}
x86_l_28f8:
	/* 0x28f8: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_28fb:
	/* 0x28fb: jne    2c70 <generic_retkprobe_filter_arg+0x2c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11376ULL;
	}
x86_l_2901:
	/* 0x2901: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2906:
	/* 0x2906: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_290d:
	/* 0x290d: jmp    2c13 <generic_retkprobe_filter_arg+0x2c13> */
	goto x86_l_2c13;
x86_l_2912:
	/* 0x2912: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2915:
	/* 0x2915: je     2c07 <generic_retkprobe_filter_arg+0x2c07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c07;
	}
x86_l_291b:
	/* 0x291b: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_291e:
	/* 0x291e: jne    2c70 <generic_retkprobe_filter_arg+0x2c70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11376ULL;
	}
x86_l_2924:
	/* 0x2924: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2929:
	/* 0x2929: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2930:
	/* 0x2930: jmp    2c13 <generic_retkprobe_filter_arg+0x2c13> */
	goto x86_l_2c13;
x86_l_2935:
	/* 0x2935: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2938:
	/* 0x2938: ja     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 177ULL;
	}
x86_l_293e:
	/* 0x293e: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2941:
	/* 0x2941: jbe    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 610ULL;
	}
x86_l_2947:
	/* 0x2947: jmp    b1 <generic_retkprobe_filter_arg+0xb1> */
	return 177ULL;
x86_l_294c:
	/* 0x294c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_294f:
	/* 0x294f: je     2ccc <generic_retkprobe_filter_arg+0x2ccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11468ULL;
	}
x86_l_2955:
	/* 0x2955: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2958:
	/* 0x2958: jne    2cd8 <generic_retkprobe_filter_arg+0x2cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11480ULL;
	}
x86_l_295e:
	/* 0x295e: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2962:
	/* 0x2962: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2964:
	/* 0x2964: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_296a:
	/* 0x296a: jmp    2cd8 <generic_retkprobe_filter_arg+0x2cd8> */
	return 11480ULL;
x86_l_296f:
	/* 0x296f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2972:
	/* 0x2972: je     2d12 <generic_retkprobe_filter_arg+0x2d12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11538ULL;
	}
x86_l_2978:
	/* 0x2978: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_297b:
	/* 0x297b: jne    2d1e <generic_retkprobe_filter_arg+0x2d1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11550ULL;
	}
x86_l_2981:
	/* 0x2981: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2985:
	/* 0x2985: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2987:
	/* 0x2987: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_298d:
	/* 0x298d: jmp    2d1e <generic_retkprobe_filter_arg+0x2d1e> */
	return 11550ULL;
x86_l_2992:
	/* 0x2992: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2997:
	/* 0x2997: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_299c:
	/* 0x299c: jmp    2ed7 <generic_retkprobe_filter_arg+0x2ed7> */
	return 11991ULL;
x86_l_29a1:
	/* 0x29a1: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_29a4:
	/* 0x29a4: mov    WORD PTR [rcx],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29a7:
	/* 0x29a7: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_29ab:
	/* 0x29ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29b0:
	/* 0x29b0: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_29b2:
	/* 0x29b2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29b7:
	/* 0x29b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b9:
	/* 0x29b9: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_29bb:
	/* 0x29bb: jbe    29de <generic_retkprobe_filter_arg+0x29de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_29de;
	}
x86_l_29bd:
	/* 0x29bd: lea    rdi,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_29c1:
	/* 0x29c1: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_29c5:
	/* 0x29c5: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29c7:
	/* 0x29c7: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29cd:
	/* 0x29cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29d2:
	/* 0x29d2: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_29d4:
	/* 0x29d4: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_29dc:
	/* 0x29dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29de:
	/* 0x29de: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_29e2:
	/* 0x29e2: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_29e6:
	/* 0x29e6: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29ea:
	/* 0x29ea: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_29ed:
	/* 0x29ed: jg     2a1a <generic_retkprobe_filter_arg+0x2a1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2a1a;
	}
x86_l_29ef:
	/* 0x29ef: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29f2:
	/* 0x29f2: jg     2c86 <generic_retkprobe_filter_arg+0x2c86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11398ULL;
	}
x86_l_29f8:
	/* 0x29f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29fa:
	/* 0x29fa: je     2e6d <generic_retkprobe_filter_arg+0x2e6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11885ULL;
	}
x86_l_2a00:
	/* 0x2a00: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a03:
	/* 0x2a03: jne    2ec6 <generic_retkprobe_filter_arg+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11974ULL;
	}
x86_l_2a09:
	/* 0x2a09: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a0e:
	/* 0x2a0e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2a15:
	/* 0x2a15: jmp    2ea3 <generic_retkprobe_filter_arg+0x2ea3> */
	return 11939ULL;
x86_l_2a1a:
	/* 0x2a1a: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2a1d:
	/* 0x2a1d: jg     2ca9 <generic_retkprobe_filter_arg+0x2ca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11433ULL;
	}
x86_l_2a23:
	/* 0x2a23: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a26:
	/* 0x2a26: je     2e7b <generic_retkprobe_filter_arg+0x2e7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11899ULL;
	}
x86_l_2a2c:
	/* 0x2a2c: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2a2f:
	/* 0x2a2f: jne    2ec6 <generic_retkprobe_filter_arg+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11974ULL;
	}
x86_l_2a35:
	/* 0x2a35: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a3a:
	/* 0x2a3a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2a41:
	/* 0x2a41: jmp    2ea3 <generic_retkprobe_filter_arg+0x2ea3> */
	return 11939ULL;
x86_l_2a46:
	/* 0x2a46: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a4b:
	/* 0x2a4b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2a52:
	/* 0x2a52: jmp    2a7c <generic_retkprobe_filter_arg+0x2a7c> */
	goto x86_l_2a7c;
x86_l_2a54:
	/* 0x2a54: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a59:
	/* 0x2a59: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2a60:
	/* 0x2a60: jmp    2a7c <generic_retkprobe_filter_arg+0x2a7c> */
	goto x86_l_2a7c;
x86_l_2a62:
	/* 0x2a62: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a67:
	/* 0x2a67: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2a6e:
	/* 0x2a6e: jmp    2a7c <generic_retkprobe_filter_arg+0x2a7c> */
	goto x86_l_2a7c;
x86_l_2a70:
	/* 0x2a70: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a75:
	/* 0x2a75: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2a7c:
	/* 0x2a7c: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2a81:
	/* 0x2a81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a83:
	/* 0x2a83: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a86:
	/* 0x2a86: je     2a9f <generic_retkprobe_filter_arg+0x2a9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a9f;
	}
x86_l_2a88:
	/* 0x2a88: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2a8d:
	/* 0x2a8d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2a90:
	/* 0x2a90: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2a93:
	/* 0x2a93: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2a95:
	/* 0x2a95: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a97:
	/* 0x2a97: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a9a:
	/* 0x2a9a: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_2a9d:
	/* 0x2a9d: jmp    2aa1 <generic_retkprobe_filter_arg+0x2aa1> */
	goto x86_l_2aa1;
x86_l_2a9f:
	/* 0x2a9f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2aa1:
	/* 0x2aa1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2aa6:
	/* 0x2aa6: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aab:
	/* 0x2aab: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ab0:
	/* 0x2ab0: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ab5:
	/* 0x2ab5: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ab9:
	/* 0x2ab9: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2abd:
	/* 0x2abd: jbe    c67 <generic_retkprobe_filter_arg+0xc67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3175ULL;
	}
x86_l_2ac3:
	/* 0x2ac3: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_2ac8:
	/* 0x2ac8: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2aca:
	/* 0x2aca: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2acd:
	/* 0x2acd: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2acf:
	/* 0x2acf: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_2ad2:
	/* 0x2ad2: and    dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2ad4:
	/* 0x2ad4: or     al,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2ad6:
	/* 0x2ad6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2adb:
	/* 0x2adb: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2add:
	/* 0x2add: je     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 610ULL;
	}
x86_l_2ae3:
	/* 0x2ae3: jmp    b1 <generic_retkprobe_filter_arg+0xb1> */
	return 177ULL;
x86_l_2ae8:
	/* 0x2ae8: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aec:
	/* 0x2aec: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_2af2:
	/* 0x2af2: jmp    2afe <generic_retkprobe_filter_arg+0x2afe> */
	goto x86_l_2afe;
x86_l_2af4:
	/* 0x2af4: cmp    QWORD PTR [rbp+0x0],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2af8:
	/* 0x2af8: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_2afe:
	/* 0x2afe: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2b01:
	/* 0x2b01: jb     2f55 <generic_retkprobe_filter_arg+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12117ULL;
	}
x86_l_2b07:
	/* 0x2b07: mov    rdx,QWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b0b:
	/* 0x2b0b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b0e:
	/* 0x2b0e: jle    2b39 <generic_retkprobe_filter_arg+0x2b39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2b39;
	}
x86_l_2b10:
	/* 0x2b10: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2b13:
	/* 0x2b13: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2b16:
	/* 0x2b16: jb     2b68 <generic_retkprobe_filter_arg+0x2b68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2b68;
	}
x86_l_2b18:
	/* 0x2b18: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2b1b:
	/* 0x2b1b: je     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 610ULL;
	}
x86_l_2b21:
	/* 0x2b21: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2b24:
	/* 0x2b24: jne    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 177ULL;
	}
x86_l_2b2a:
	/* 0x2b2a: test   QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b2e:
	/* 0x2b2e: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_2b34:
	/* 0x2b34: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	return 12117ULL;
x86_l_2b39:
	/* 0x2b39: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b3c:
	/* 0x2b3c: je     2bc0 <generic_retkprobe_filter_arg+0x2bc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bc0;
	}
x86_l_2b42:
	/* 0x2b42: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b45:
	/* 0x2b45: jne    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 177ULL;
	}
x86_l_2b4b:
	/* 0x2b4b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2b4e:
	/* 0x2b4e: je     2b59 <generic_retkprobe_filter_arg+0x2b59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b59;
	}
x86_l_2b50:
	/* 0x2b50: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2b53:
	/* 0x2b53: jne    2f0e <generic_retkprobe_filter_arg+0x2f0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12046ULL;
	}
x86_l_2b59:
	/* 0x2b59: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b5d:
	/* 0x2b5d: jl     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 610ULL;
	}
x86_l_2b63:
	/* 0x2b63: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	return 12117ULL;
x86_l_2b68:
	/* 0x2b68: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b6c:
	/* 0x2b6c: je     2e60 <generic_retkprobe_filter_arg+0x2e60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11872ULL;
	}
x86_l_2b72:
	/* 0x2b72: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	return 12117ULL;
x86_l_2b77:
	/* 0x2b77: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2b7a:
	/* 0x2b7a: jne    2cd8 <generic_retkprobe_filter_arg+0x2cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11480ULL;
	}
x86_l_2b80:
	/* 0x2b80: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2b84:
	/* 0x2b84: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2b86:
	/* 0x2b86: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_2b8c:
	/* 0x2b8c: jmp    2cd8 <generic_retkprobe_filter_arg+0x2cd8> */
	return 11480ULL;
x86_l_2b91:
	/* 0x2b91: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2b94:
	/* 0x2b94: jne    2d1e <generic_retkprobe_filter_arg+0x2d1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11550ULL;
	}
x86_l_2b9a:
	/* 0x2b9a: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b9e:
	/* 0x2b9e: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2ba0:
	/* 0x2ba0: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_2ba6:
	/* 0x2ba6: jmp    2d1e <generic_retkprobe_filter_arg+0x2d1e> */
	return 11550ULL;
x86_l_2bab:
	/* 0x2bab: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2bad:
	/* 0x2bad: ja     b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 177ULL;
	}
x86_l_2bb3:
	/* 0x2bb3: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2bb5:
	/* 0x2bb5: jbe    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 610ULL;
	}
x86_l_2bbb:
	/* 0x2bbb: jmp    b1 <generic_retkprobe_filter_arg+0xb1> */
	return 177ULL;
x86_l_2bc0:
	/* 0x2bc0: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2bc3:
	/* 0x2bc3: je     2bce <generic_retkprobe_filter_arg+0x2bce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bce;
	}
x86_l_2bc5:
	/* 0x2bc5: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2bc8:
	/* 0x2bc8: jne    2f1a <generic_retkprobe_filter_arg+0x2f1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12058ULL;
	}
x86_l_2bce:
	/* 0x2bce: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bd2:
	/* 0x2bd2: jg     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 610ULL;
	}
x86_l_2bd8:
	/* 0x2bd8: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	return 12117ULL;
x86_l_2bdd:
	/* 0x2bdd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2be2:
	/* 0x2be2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2be9:
	/* 0x2be9: jmp    2c13 <generic_retkprobe_filter_arg+0x2c13> */
	goto x86_l_2c13;
x86_l_2beb:
	/* 0x2beb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bf0:
	/* 0x2bf0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2bf7:
	/* 0x2bf7: jmp    2c13 <generic_retkprobe_filter_arg+0x2c13> */
	goto x86_l_2c13;
x86_l_2bf9:
	/* 0x2bf9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bfe:
	/* 0x2bfe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2c05:
	/* 0x2c05: jmp    2c13 <generic_retkprobe_filter_arg+0x2c13> */
	goto x86_l_2c13;
x86_l_2c07:
	/* 0x2c07: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c0c:
	/* 0x2c0c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2c13:
	/* 0x2c13: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2c18:
	/* 0x2c18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1a:
	/* 0x2c1a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c1d:
	/* 0x2c1d: je     2c38 <generic_retkprobe_filter_arg+0x2c38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11320ULL;
	}
x86_l_2c1f:
	/* 0x2c1f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2c24:
	/* 0x2c24: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
	return 11303ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11303ULL: goto x86_l_2c27;
	case 11308ULL: goto x86_l_2c2c;
	case 11310ULL: goto x86_l_2c2e;
	case 11312ULL: goto x86_l_2c30;
	case 11315ULL: goto x86_l_2c33;
	case 11318ULL: goto x86_l_2c36;
	case 11320ULL: goto x86_l_2c38;
	case 11322ULL: goto x86_l_2c3a;
	case 11327ULL: goto x86_l_2c3f;
	case 11332ULL: goto x86_l_2c44;
	case 11337ULL: goto x86_l_2c49;
	case 11341ULL: goto x86_l_2c4d;
	case 11345ULL: goto x86_l_2c51;
	case 11351ULL: goto x86_l_2c57;
	case 11361ULL: goto x86_l_2c61;
	case 11365ULL: goto x86_l_2c65;
	case 11371ULL: goto x86_l_2c6b;
	case 11376ULL: goto x86_l_2c70;
	case 11378ULL: goto x86_l_2c72;
	case 11383ULL: goto x86_l_2c77;
	case 11387ULL: goto x86_l_2c7b;
	case 11391ULL: goto x86_l_2c7f;
	case 11393ULL: goto x86_l_2c81;
	case 11398ULL: goto x86_l_2c86;
	case 11401ULL: goto x86_l_2c89;
	case 11407ULL: goto x86_l_2c8f;
	case 11410ULL: goto x86_l_2c92;
	case 11416ULL: goto x86_l_2c98;
	case 11421ULL: goto x86_l_2c9d;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11436ULL: goto x86_l_2cac;
	case 11442ULL: goto x86_l_2cb2;
	case 11445ULL: goto x86_l_2cb5;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11463ULL: goto x86_l_2cc7;
	case 11468ULL: goto x86_l_2ccc;
	case 11472ULL: goto x86_l_2cd0;
	case 11474ULL: goto x86_l_2cd2;
	case 11480ULL: goto x86_l_2cd8;
	case 11483ULL: goto x86_l_2cdb;
	case 11489ULL: goto x86_l_2ce1;
	case 11493ULL: goto x86_l_2ce5;
	case 11496ULL: goto x86_l_2ce8;
	case 11502ULL: goto x86_l_2cee;
	case 11505ULL: goto x86_l_2cf1;
	case 11508ULL: goto x86_l_2cf4;
	case 11514ULL: goto x86_l_2cfa;
	case 11517ULL: goto x86_l_2cfd;
	case 11523ULL: goto x86_l_2d03;
	case 11526ULL: goto x86_l_2d06;
	case 11532ULL: goto x86_l_2d0c;
	case 11536ULL: goto x86_l_2d10;
	case 11538ULL: goto x86_l_2d12;
	case 11542ULL: goto x86_l_2d16;
	case 11544ULL: goto x86_l_2d18;
	case 11550ULL: goto x86_l_2d1e;
	case 11553ULL: goto x86_l_2d21;
	case 11559ULL: goto x86_l_2d27;
	case 11563ULL: goto x86_l_2d2b;
	case 11566ULL: goto x86_l_2d2e;
	case 11572ULL: goto x86_l_2d34;
	case 11575ULL: goto x86_l_2d37;
	case 11578ULL: goto x86_l_2d3a;
	case 11584ULL: goto x86_l_2d40;
	case 11587ULL: goto x86_l_2d43;
	case 11593ULL: goto x86_l_2d49;
	case 11596ULL: goto x86_l_2d4c;
	case 11602ULL: goto x86_l_2d52;
	case 11606ULL: goto x86_l_2d56;
	case 11608ULL: goto x86_l_2d58;
	case 11614ULL: goto x86_l_2d5e;
	case 11619ULL: goto x86_l_2d63;
	case 11622ULL: goto x86_l_2d66;
	case 11628ULL: goto x86_l_2d6c;
	case 11630ULL: goto x86_l_2d6e;
	case 11633ULL: goto x86_l_2d71;
	case 11639ULL: goto x86_l_2d77;
	case 11642ULL: goto x86_l_2d7a;
	case 11648ULL: goto x86_l_2d80;
	case 11652ULL: goto x86_l_2d84;
	case 11655ULL: goto x86_l_2d87;
	case 11657ULL: goto x86_l_2d89;
	case 11660ULL: goto x86_l_2d8c;
	case 11663ULL: goto x86_l_2d8f;
	case 11665ULL: goto x86_l_2d91;
	case 11668ULL: goto x86_l_2d94;
	case 11674ULL: goto x86_l_2d9a;
	case 11677ULL: goto x86_l_2d9d;
	case 11683ULL: goto x86_l_2da3;
	case 11686ULL: goto x86_l_2da6;
	case 11692ULL: goto x86_l_2dac;
	case 11697ULL: goto x86_l_2db1;
	case 11700ULL: goto x86_l_2db4;
	case 11702ULL: goto x86_l_2db6;
	case 11705ULL: goto x86_l_2db9;
	case 11711ULL: goto x86_l_2dbf;
	case 11714ULL: goto x86_l_2dc2;
	case 11720ULL: goto x86_l_2dc8;
	case 11725ULL: goto x86_l_2dcd;
	case 11728ULL: goto x86_l_2dd0;
	case 11734ULL: goto x86_l_2dd6;
	case 11737ULL: goto x86_l_2dd9;
	case 11743ULL: goto x86_l_2ddf;
	case 11748ULL: goto x86_l_2de4;
	case 11751ULL: goto x86_l_2de7;
	case 11753ULL: goto x86_l_2de9;
	case 11758ULL: goto x86_l_2dee;
	case 11761ULL: goto x86_l_2df1;
	case 11767ULL: goto x86_l_2df7;
	case 11772ULL: goto x86_l_2dfc;
	case 11775ULL: goto x86_l_2dff;
	case 11781ULL: goto x86_l_2e05;
	case 11784ULL: goto x86_l_2e08;
	case 11790ULL: goto x86_l_2e0e;
	case 11795ULL: goto x86_l_2e13;
	case 11798ULL: goto x86_l_2e16;
	case 11804ULL: goto x86_l_2e1c;
	case 11807ULL: goto x86_l_2e1f;
	case 11813ULL: goto x86_l_2e25;
	case 11817ULL: goto x86_l_2e29;
	case 11819ULL: goto x86_l_2e2b;
	case 11822ULL: goto x86_l_2e2e;
	case 11828ULL: goto x86_l_2e34;
	case 11831ULL: goto x86_l_2e37;
	case 11837ULL: goto x86_l_2e3d;
	case 11841ULL: goto x86_l_2e41;
	case 11843ULL: goto x86_l_2e43;
	case 11849ULL: goto x86_l_2e49;
	case 11854ULL: goto x86_l_2e4e;
	case 11858ULL: goto x86_l_2e52;
	case 11860ULL: goto x86_l_2e54;
	case 11864ULL: goto x86_l_2e58;
	case 11866ULL: goto x86_l_2e5a;
	case 11872ULL: goto x86_l_2e60;
	case 11874ULL: goto x86_l_2e62;
	case 11877ULL: goto x86_l_2e65;
	case 11880ULL: goto x86_l_2e68;
	case 11885ULL: goto x86_l_2e6d;
	case 11890ULL: goto x86_l_2e72;
	case 11897ULL: goto x86_l_2e79;
	case 11899ULL: goto x86_l_2e7b;
	case 11904ULL: goto x86_l_2e80;
	case 11911ULL: goto x86_l_2e87;
	case 11913ULL: goto x86_l_2e89;
	case 11918ULL: goto x86_l_2e8e;
	case 11925ULL: goto x86_l_2e95;
	case 11927ULL: goto x86_l_2e97;
	case 11932ULL: goto x86_l_2e9c;
	case 11939ULL: goto x86_l_2ea3;
	case 11944ULL: goto x86_l_2ea8;
	case 11946ULL: goto x86_l_2eaa;
	case 11949ULL: goto x86_l_2ead;
	case 11951ULL: goto x86_l_2eaf;
	case 11956ULL: goto x86_l_2eb4;
	case 11959ULL: goto x86_l_2eb7;
	case 11962ULL: goto x86_l_2eba;
	case 11964ULL: goto x86_l_2ebc;
	case 11966ULL: goto x86_l_2ebe;
	case 11969ULL: goto x86_l_2ec1;
	case 11972ULL: goto x86_l_2ec4;
	case 11974ULL: goto x86_l_2ec6;
	case 11976ULL: goto x86_l_2ec8;
	case 11981ULL: goto x86_l_2ecd;
	case 11986ULL: goto x86_l_2ed2;
	case 11991ULL: goto x86_l_2ed7;
	case 11995ULL: goto x86_l_2edb;
	case 11999ULL: goto x86_l_2edf;
	case 12005ULL: goto x86_l_2ee5;
	case 12015ULL: goto x86_l_2eef;
	case 12019ULL: goto x86_l_2ef3;
	case 12024ULL: goto x86_l_2ef8;
	case 12030ULL: goto x86_l_2efe;
	case 12032ULL: goto x86_l_2f00;
	case 12035ULL: goto x86_l_2f03;
	case 12038ULL: goto x86_l_2f06;
	case 12041ULL: goto x86_l_2f09;
	case 12046ULL: goto x86_l_2f0e;
	case 12050ULL: goto x86_l_2f12;
	case 12056ULL: goto x86_l_2f18;
	case 12058ULL: goto x86_l_2f1a;
	case 12062ULL: goto x86_l_2f1e;
	case 12068ULL: goto x86_l_2f24;
	case 12070ULL: goto x86_l_2f26;
	case 12074ULL: goto x86_l_2f2a;
	case 12076ULL: goto x86_l_2f2c;
	case 12080ULL: goto x86_l_2f30;
	case 12082ULL: goto x86_l_2f32;
	case 12088ULL: goto x86_l_2f38;
	case 12090ULL: goto x86_l_2f3a;
	case 12092ULL: goto x86_l_2f3c;
	case 12097ULL: goto x86_l_2f41;
	case 12100ULL: goto x86_l_2f44;
	case 12106ULL: goto x86_l_2f4a;
	case 12108ULL: goto x86_l_2f4c;
	case 12111ULL: goto x86_l_2f4f;
	case 12117ULL: goto x86_l_2f55;
	case 12120ULL: goto x86_l_2f58;
	case 12123ULL: goto x86_l_2f5b;
	case 12129ULL: goto x86_l_2f61;
	case 12134ULL: goto x86_l_2f66;
	case 12139ULL: goto x86_l_2f6b;
	case 12142ULL: goto x86_l_2f6e;
	case 12144ULL: goto x86_l_2f70;
	case 12145ULL: goto x86_l_2f71;
	case 12147ULL: goto x86_l_2f73;
	case 12149ULL: goto x86_l_2f75;
	case 12152ULL: goto x86_l_2f78;
	case 12155ULL: goto x86_l_2f7b;
	case 12158ULL: goto x86_l_2f7e;
	case 12160ULL: goto x86_l_2f80;
	case 12163ULL: goto x86_l_2f83;
	case 12167ULL: goto x86_l_2f87;
	case 12170ULL: goto x86_l_2f8a;
	case 12172ULL: goto x86_l_2f8c;
	case 12177ULL: goto x86_l_2f91;
	case 12180ULL: goto x86_l_2f94;
	case 12182ULL: goto x86_l_2f96;
	case 12187ULL: goto x86_l_2f9b;
	case 12191ULL: goto x86_l_2f9f;
	case 12194ULL: goto x86_l_2fa2;
	case 12197ULL: goto x86_l_2fa5;
	case 12201ULL: goto x86_l_2fa9;
	case 12205ULL: goto x86_l_2fad;
	case 12209ULL: goto x86_l_2fb1;
	case 12212ULL: goto x86_l_2fb4;
	case 12216ULL: goto x86_l_2fb8;
	case 12220ULL: goto x86_l_2fbc;
	case 12224ULL: goto x86_l_2fc0;
	case 12227ULL: goto x86_l_2fc3;
	case 12229ULL: goto x86_l_2fc5;
	case 12233ULL: goto x86_l_2fc9;
	case 12237ULL: goto x86_l_2fcd;
	case 12240ULL: goto x86_l_2fd0;
	case 12242ULL: goto x86_l_2fd2;
	case 12244ULL: goto x86_l_2fd4;
	case 12246ULL: goto x86_l_2fd6;
	case 12247ULL: goto x86_l_2fd7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2c27:
	/* 0x2c27: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c2c:
	/* 0x2c2c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2c2e:
	/* 0x2c2e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c30:
	/* 0x2c30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c33:
	/* 0x2c33: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_2c36:
	/* 0x2c36: jmp    2c3a <generic_retkprobe_filter_arg+0x2c3a> */
	goto x86_l_2c3a;
x86_l_2c38:
	/* 0x2c38: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c3a:
	/* 0x2c3a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c3f:
	/* 0x2c3f: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c44:
	/* 0x2c44: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c49:
	/* 0x2c49: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c4d:
	/* 0x2c4d: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2c51:
	/* 0x2c51: ja     251 <generic_retkprobe_filter_arg+0x251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 593ULL;
	}
x86_l_2c57:
	/* 0x2c57: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_2c61:
	/* 0x2c61: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2c65:
	/* 0x2c65: jb     2efe <generic_retkprobe_filter_arg+0x2efe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2efe;
	}
x86_l_2c6b:
	/* 0x2c6b: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_2c70:
	/* 0x2c70: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c72:
	/* 0x2c72: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c77:
	/* 0x2c77: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c7b:
	/* 0x2c7b: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2c7f:
	/* 0x2c7f: jbe    2c57 <generic_retkprobe_filter_arg+0x2c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2c57;
	}
x86_l_2c81:
	/* 0x2c81: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_2c86:
	/* 0x2c86: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c89:
	/* 0x2c89: je     2e89 <generic_retkprobe_filter_arg+0x2e89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e89;
	}
x86_l_2c8f:
	/* 0x2c8f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2c92:
	/* 0x2c92: jne    2ec6 <generic_retkprobe_filter_arg+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ec6;
	}
x86_l_2c98:
	/* 0x2c98: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c9d:
	/* 0x2c9d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_2ca4:
	/* 0x2ca4: jmp    2ea3 <generic_retkprobe_filter_arg+0x2ea3> */
	goto x86_l_2ea3;
x86_l_2ca9:
	/* 0x2ca9: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2cac:
	/* 0x2cac: je     2e97 <generic_retkprobe_filter_arg+0x2e97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e97;
	}
x86_l_2cb2:
	/* 0x2cb2: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2cb5:
	/* 0x2cb5: jne    2ec6 <generic_retkprobe_filter_arg+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ec6;
	}
x86_l_2cbb:
	/* 0x2cbb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cc0:
	/* 0x2cc0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2cc7:
	/* 0x2cc7: jmp    2ea3 <generic_retkprobe_filter_arg+0x2ea3> */
	goto x86_l_2ea3;
x86_l_2ccc:
	/* 0x2ccc: movzx  esi,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2cd0:
	/* 0x2cd0: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2cd2:
	/* 0x2cd2: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_2cd8:
	/* 0x2cd8: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_2cdb:
	/* 0x2cdb: jb     2f55 <generic_retkprobe_filter_arg+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f55;
	}
x86_l_2ce1:
	/* 0x2ce1: mov    ecx,DWORD PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2ce5:
	/* 0x2ce5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ce8:
	/* 0x2ce8: jle    2e13 <generic_retkprobe_filter_arg+0x2e13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e13;
	}
x86_l_2cee:
	/* 0x2cee: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2cf1:
	/* 0x2cf1: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2cf4:
	/* 0x2cf4: jb     2e4e <generic_retkprobe_filter_arg+0x2e4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2e4e;
	}
x86_l_2cfa:
	/* 0x2cfa: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2cfd:
	/* 0x2cfd: je     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 610ULL;
	}
x86_l_2d03:
	/* 0x2d03: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2d06:
	/* 0x2d06: jne    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 177ULL;
	}
x86_l_2d0c:
	/* 0x2d0c: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2d10:
	/* 0x2d10: jmp    2d56 <generic_retkprobe_filter_arg+0x2d56> */
	goto x86_l_2d56;
x86_l_2d12:
	/* 0x2d12: movzx  esi,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d16:
	/* 0x2d16: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2d18:
	/* 0x2d18: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_2d1e:
	/* 0x2d1e: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_2d21:
	/* 0x2d21: jb     2f55 <generic_retkprobe_filter_arg+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f55;
	}
x86_l_2d27:
	/* 0x2d27: mov    ecx,DWORD PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2d2b:
	/* 0x2d2b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d2e:
	/* 0x2d2e: jle    2e2b <generic_retkprobe_filter_arg+0x2e2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e2b;
	}
x86_l_2d34:
	/* 0x2d34: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2d37:
	/* 0x2d37: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2d3a:
	/* 0x2d3a: jb     2e54 <generic_retkprobe_filter_arg+0x2e54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2e54;
	}
x86_l_2d40:
	/* 0x2d40: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2d43:
	/* 0x2d43: je     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 610ULL;
	}
x86_l_2d49:
	/* 0x2d49: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2d4c:
	/* 0x2d4c: jne    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 177ULL;
	}
x86_l_2d52:
	/* 0x2d52: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d56:
	/* 0x2d56: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2d58:
	/* 0x2d58: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_2d5e:
	/* 0x2d5e: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	goto x86_l_2f55;
x86_l_2d63:
	/* 0x2d63: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d66:
	/* 0x2d66: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_2d6c:
	/* 0x2d6c: jmp    2d77 <generic_retkprobe_filter_arg+0x2d77> */
	goto x86_l_2d77;
x86_l_2d6e:
	/* 0x2d6e: cmp    DWORD PTR [rbp+0x0],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d71:
	/* 0x2d71: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_2d77:
	/* 0x2d77: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2d7a:
	/* 0x2d7a: jb     2f55 <generic_retkprobe_filter_arg+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f55;
	}
x86_l_2d80:
	/* 0x2d80: mov    edx,DWORD PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2d84:
	/* 0x2d84: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d87:
	/* 0x2d87: jle    2db1 <generic_retkprobe_filter_arg+0x2db1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2db1;
	}
x86_l_2d89:
	/* 0x2d89: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2d8c:
	/* 0x2d8c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2d8f:
	/* 0x2d8f: jb     2de4 <generic_retkprobe_filter_arg+0x2de4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2de4;
	}
x86_l_2d91:
	/* 0x2d91: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2d94:
	/* 0x2d94: je     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 610ULL;
	}
x86_l_2d9a:
	/* 0x2d9a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2d9d:
	/* 0x2d9d: jne    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 177ULL;
	}
x86_l_2da3:
	/* 0x2da3: test   DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2da6:
	/* 0x2da6: jne    262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 610ULL;
	}
x86_l_2dac:
	/* 0x2dac: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	goto x86_l_2f55;
x86_l_2db1:
	/* 0x2db1: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2db4:
	/* 0x2db4: je     2dee <generic_retkprobe_filter_arg+0x2dee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dee;
	}
x86_l_2db6:
	/* 0x2db6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2db9:
	/* 0x2db9: jne    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 177ULL;
	}
x86_l_2dbf:
	/* 0x2dbf: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2dc2:
	/* 0x2dc2: ja     2f41 <generic_retkprobe_filter_arg+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f41;
	}
x86_l_2dc8:
	/* 0x2dc8: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_2dcd:
	/* 0x2dcd: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_2dd0:
	/* 0x2dd0: jae    2f41 <generic_retkprobe_filter_arg+0x2f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2f41;
	}
x86_l_2dd6:
	/* 0x2dd6: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dd9:
	/* 0x2dd9: jl     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 610ULL;
	}
x86_l_2ddf:
	/* 0x2ddf: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	goto x86_l_2f55;
x86_l_2de4:
	/* 0x2de4: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2de7:
	/* 0x2de7: je     2e60 <generic_retkprobe_filter_arg+0x2e60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e60;
	}
x86_l_2de9:
	/* 0x2de9: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	goto x86_l_2f55;
x86_l_2dee:
	/* 0x2dee: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2df1:
	/* 0x2df1: ja     2f4c <generic_retkprobe_filter_arg+0x2f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f4c;
	}
x86_l_2df7:
	/* 0x2df7: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_2dfc:
	/* 0x2dfc: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_2dff:
	/* 0x2dff: jae    2f4c <generic_retkprobe_filter_arg+0x2f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2f4c;
	}
x86_l_2e05:
	/* 0x2e05: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e08:
	/* 0x2e08: jg     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 610ULL;
	}
x86_l_2e0e:
	/* 0x2e0e: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	goto x86_l_2f55;
x86_l_2e13:
	/* 0x2e13: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e16:
	/* 0x2e16: je     2f26 <generic_retkprobe_filter_arg+0x2f26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f26;
	}
x86_l_2e1c:
	/* 0x2e1c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e1f:
	/* 0x2e1f: jne    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 177ULL;
	}
x86_l_2e25:
	/* 0x2e25: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2e29:
	/* 0x2e29: jmp    2e41 <generic_retkprobe_filter_arg+0x2e41> */
	goto x86_l_2e41;
x86_l_2e2b:
	/* 0x2e2b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e2e:
	/* 0x2e2e: je     2f2c <generic_retkprobe_filter_arg+0x2f2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f2c;
	}
x86_l_2e34:
	/* 0x2e34: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e37:
	/* 0x2e37: jne    b1 <generic_retkprobe_filter_arg+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 177ULL;
	}
x86_l_2e3d:
	/* 0x2e3d: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e41:
	/* 0x2e41: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2e43:
	/* 0x2e43: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_2e49:
	/* 0x2e49: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	goto x86_l_2f55;
x86_l_2e4e:
	/* 0x2e4e: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2e52:
	/* 0x2e52: jmp    2e58 <generic_retkprobe_filter_arg+0x2e58> */
	goto x86_l_2e58;
x86_l_2e54:
	/* 0x2e54: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e58:
	/* 0x2e58: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2e5a:
	/* 0x2e5a: jne    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f55;
	}
x86_l_2e60:
	/* 0x2e60: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e62:
	/* 0x2e62: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2e65:
	/* 0x2e65: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_2e68:
	/* 0x2e68: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_2e6d:
	/* 0x2e6d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e72:
	/* 0x2e72: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2e79:
	/* 0x2e79: jmp    2ea3 <generic_retkprobe_filter_arg+0x2ea3> */
	goto x86_l_2ea3;
x86_l_2e7b:
	/* 0x2e7b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e80:
	/* 0x2e80: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2e87:
	/* 0x2e87: jmp    2ea3 <generic_retkprobe_filter_arg+0x2ea3> */
	goto x86_l_2ea3;
x86_l_2e89:
	/* 0x2e89: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e8e:
	/* 0x2e8e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2e95:
	/* 0x2e95: jmp    2ea3 <generic_retkprobe_filter_arg+0x2ea3> */
	goto x86_l_2ea3;
x86_l_2e97:
	/* 0x2e97: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e9c:
	/* 0x2e9c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2ea3:
	/* 0x2ea3: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2ea8:
	/* 0x2ea8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eaa:
	/* 0x2eaa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ead:
	/* 0x2ead: je     2ec6 <generic_retkprobe_filter_arg+0x2ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ec6;
	}
x86_l_2eaf:
	/* 0x2eaf: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2eb4:
	/* 0x2eb4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2eb7:
	/* 0x2eb7: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2eba:
	/* 0x2eba: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2ebc:
	/* 0x2ebc: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ebe:
	/* 0x2ebe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ec1:
	/* 0x2ec1: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_2ec4:
	/* 0x2ec4: jmp    2ec8 <generic_retkprobe_filter_arg+0x2ec8> */
	goto x86_l_2ec8;
x86_l_2ec6:
	/* 0x2ec6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ec8:
	/* 0x2ec8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ecd:
	/* 0x2ecd: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ed2:
	/* 0x2ed2: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ed7:
	/* 0x2ed7: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2edb:
	/* 0x2edb: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2edf:
	/* 0x2edf: ja     24c <generic_retkprobe_filter_arg+0x24c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 588ULL;
	}
x86_l_2ee5:
	/* 0x2ee5: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_2eef:
	/* 0x2eef: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2ef3:
	/* 0x2ef3: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ef8:
	/* 0x2ef8: jae    251 <generic_retkprobe_filter_arg+0x251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 593ULL;
	}
x86_l_2efe:
	/* 0x2efe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f00:
	/* 0x2f00: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2f03:
	/* 0x2f03: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2f06:
	/* 0x2f06: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2f09:
	/* 0x2f09: jmp    251 <generic_retkprobe_filter_arg+0x251> */
	return 593ULL;
x86_l_2f0e:
	/* 0x2f0e: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f12:
	/* 0x2f12: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_2f18:
	/* 0x2f18: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	goto x86_l_2f55;
x86_l_2f1a:
	/* 0x2f1a: cmp    QWORD PTR [rbp+0x0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f1e:
	/* 0x2f1e: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_2f24:
	/* 0x2f24: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	goto x86_l_2f55;
x86_l_2f26:
	/* 0x2f26: movzx  edx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2f2a:
	/* 0x2f2a: jmp    2f30 <generic_retkprobe_filter_arg+0x2f30> */
	goto x86_l_2f30;
x86_l_2f2c:
	/* 0x2f2c: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f30:
	/* 0x2f30: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2f32:
	/* 0x2f32: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_2f38:
	/* 0x2f38: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	goto x86_l_2f55;
x86_l_2f3a:
	/* 0x2f3a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f3c:
	/* 0x2f3c: jmp    ba2 <generic_retkprobe_filter_arg+0xba2> */
	return 2978ULL;
x86_l_2f41:
	/* 0x2f41: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f44:
	/* 0x2f44: jb     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 610ULL;
	}
x86_l_2f4a:
	/* 0x2f4a: jmp    2f55 <generic_retkprobe_filter_arg+0x2f55> */
	goto x86_l_2f55;
x86_l_2f4c:
	/* 0x2f4c: cmp    DWORD PTR [rbp+0x0],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f4f:
	/* 0x2f4f: ja     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 610ULL;
	}
x86_l_2f55:
	/* 0x2f55: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_2f58:
	/* 0x2f58: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2f5b:
	/* 0x2f5b: je     262 <generic_retkprobe_filter_arg+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 610ULL;
	}
x86_l_2f61:
	/* 0x2f61: jmp    b1 <generic_retkprobe_filter_arg+0xb1> */
	return 177ULL;
x86_l_2f66:
	/* 0x2f66: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2f6b:
	/* 0x2f6b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2f6e:
	/* 0x2f6e: je     2fd7 <native_bpf_strncasestr+0x71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd7;
	}
x86_l_2f70:
	/* 0x2f70: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2f71:
	/* 0x2f71: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f73:
	/* 0x2f73: jmp    2f80 <native_bpf_strncasestr+0x1a> */
	goto x86_l_2f80;
x86_l_2f75:
	/* 0x2f75: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2f78:
	/* 0x2f78: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2f7b:
	/* 0x2f7b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2f7e:
	/* 0x2f7e: je     2fd6 <native_bpf_strncasestr+0x70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd6;
	}
x86_l_2f80:
	/* 0x2f80: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f83:
	/* 0x2f83: lea    r9,[rcx+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_2f87:
	/* 0x2f87: cmp    r9,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RDX, X86_WIDTH_64);
x86_l_2f8a:
	/* 0x2f8a: jae    2f75 <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2f75;
	}
x86_l_2f8c:
	/* 0x2f8c: movsx  r9d,BYTE PTR [rsi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_2f91:
	/* 0x2f91: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_2f94:
	/* 0x2f94: je     2fd4 <native_bpf_strncasestr+0x6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd4;
	}
x86_l_2f96:
	/* 0x2f96: movsx  r10d,BYTE PTR [rdi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_2f9b:
	/* 0x2f9b: lea    r11d,[r10-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_2f9f:
	/* 0x2f9f: mov    ebx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R10, X86_WIDTH_32);
x86_l_2fa2:
	/* 0x2fa2: or     ebx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_2fa5:
	/* 0x2fa5: cmp    r11d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 26ULL);
x86_l_2fa9:
	/* 0x2fa9: cmovae ebx,r10d */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R10, X86_WIDTH_32, X86_CC_AE);
x86_l_2fad:
	/* 0x2fad: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_2fb1:
	/* 0x2fb1: mov    r11d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_32);
x86_l_2fb4:
	/* 0x2fb4: or     r11d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_2fb8:
	/* 0x2fb8: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_2fbc:
	/* 0x2fbc: cmovae r11d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_2fc0:
	/* 0x2fc0: cmp    ebx,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R11, X86_WIDTH_32);
x86_l_2fc3:
	/* 0x2fc3: jne    2f75 <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f75;
	}
x86_l_2fc5:
	/* 0x2fc5: lea    r9,[r8+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2fc9:
	/* 0x2fc9: cmp    r8,0x63 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 99ULL);
x86_l_2fcd:
	/* 0x2fcd: mov    r8,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_64);
x86_l_2fd0:
	/* 0x2fd0: jb     2f83 <native_bpf_strncasestr+0x1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f83;
	}
x86_l_2fd2:
	/* 0x2fd2: jmp    2f75 <native_bpf_strncasestr+0xf> */
	goto x86_l_2f75;
x86_l_2fd4:
	/* 0x2fd4: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2fd6:
	/* 0x2fd6: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2fd7:
	/* 0x2fd7: ret */
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11708U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1720ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1725ULL && __x86_pc <= 3361ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3367ULL && __x86_pc <= 4934ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4936ULL && __x86_pc <= 6560ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6563ULL && __x86_pc <= 8069ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8075ULL && __x86_pc <= 9666ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9668ULL && __x86_pc <= 11300ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11303ULL && __x86_pc <= 12247ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v53_generic_retkprobe_filter_arg_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

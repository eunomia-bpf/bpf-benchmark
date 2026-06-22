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

static __noinline __u64 tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_0(
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
	case 118ULL: goto x86_l_76;
	case 127ULL: goto x86_l_7f;
	case 133ULL: goto x86_l_85;
	case 135ULL: goto x86_l_87;
	case 140ULL: goto x86_l_8c;
	case 144ULL: goto x86_l_90;
	case 148ULL: goto x86_l_94;
	case 152ULL: goto x86_l_98;
	case 156ULL: goto x86_l_9c;
	case 161ULL: goto x86_l_a1;
	case 165ULL: goto x86_l_a5;
	case 168ULL: goto x86_l_a8;
	case 172ULL: goto x86_l_ac;
	case 174ULL: goto x86_l_ae;
	case 180ULL: goto x86_l_b4;
	case 184ULL: goto x86_l_b8;
	case 187ULL: goto x86_l_bb;
	case 189ULL: goto x86_l_bd;
	case 194ULL: goto x86_l_c2;
	case 198ULL: goto x86_l_c6;
	case 201ULL: goto x86_l_c9;
	case 203ULL: goto x86_l_cb;
	case 209ULL: goto x86_l_d1;
	case 213ULL: goto x86_l_d5;
	case 216ULL: goto x86_l_d8;
	case 218ULL: goto x86_l_da;
	case 223ULL: goto x86_l_df;
	case 227ULL: goto x86_l_e3;
	case 230ULL: goto x86_l_e6;
	case 233ULL: goto x86_l_e9;
	case 239ULL: goto x86_l_ef;
	case 244ULL: goto x86_l_f4;
	case 246ULL: goto x86_l_f6;
	case 250ULL: goto x86_l_fa;
	case 256ULL: goto x86_l_100;
	case 258ULL: goto x86_l_102;
	case 264ULL: goto x86_l_108;
	case 268ULL: goto x86_l_10c;
	case 270ULL: goto x86_l_10e;
	case 274ULL: goto x86_l_112;
	case 280ULL: goto x86_l_118;
	case 283ULL: goto x86_l_11b;
	case 289ULL: goto x86_l_121;
	case 293ULL: goto x86_l_125;
	case 299ULL: goto x86_l_12b;
	case 301ULL: goto x86_l_12d;
	case 305ULL: goto x86_l_131;
	case 311ULL: goto x86_l_137;
	case 315ULL: goto x86_l_13b;
	case 321ULL: goto x86_l_141;
	case 325ULL: goto x86_l_145;
	case 331ULL: goto x86_l_14b;
	case 335ULL: goto x86_l_14f;
	case 341ULL: goto x86_l_155;
	case 344ULL: goto x86_l_158;
	case 349ULL: goto x86_l_15d;
	case 353ULL: goto x86_l_161;
	case 361ULL: goto x86_l_169;
	case 364ULL: goto x86_l_16c;
	case 369ULL: goto x86_l_171;
	case 374ULL: goto x86_l_176;
	case 379ULL: goto x86_l_17b;
	case 387ULL: goto x86_l_183;
	case 392ULL: goto x86_l_188;
	case 397ULL: goto x86_l_18d;
	case 402ULL: goto x86_l_192;
	case 407ULL: goto x86_l_197;
	case 414ULL: goto x86_l_19e;
	case 419ULL: goto x86_l_1a3;
	case 426ULL: goto x86_l_1aa;
	case 429ULL: goto x86_l_1ad;
	case 434ULL: goto x86_l_1b2;
	case 436ULL: goto x86_l_1b4;
	case 441ULL: goto x86_l_1b9;
	case 448ULL: goto x86_l_1c0;
	case 451ULL: goto x86_l_1c3;
	case 456ULL: goto x86_l_1c8;
	case 458ULL: goto x86_l_1ca;
	case 460ULL: goto x86_l_1cc;
	case 467ULL: goto x86_l_1d3;
	case 469ULL: goto x86_l_1d5;
	case 470ULL: goto x86_l_1d6;
	case 475ULL: goto x86_l_1db;
	case 478ULL: goto x86_l_1de;
	case 486ULL: goto x86_l_1e6;
	case 488ULL: goto x86_l_1e8;
	case 494ULL: goto x86_l_1ee;
	case 502ULL: goto x86_l_1f6;
	case 504ULL: goto x86_l_1f8;
	case 510ULL: goto x86_l_1fe;
	case 518ULL: goto x86_l_206;
	case 520ULL: goto x86_l_208;
	case 526ULL: goto x86_l_20e;
	case 534ULL: goto x86_l_216;
	case 536ULL: goto x86_l_218;
	case 542ULL: goto x86_l_21e;
	case 550ULL: goto x86_l_226;
	case 552ULL: goto x86_l_228;
	case 558ULL: goto x86_l_22e;
	case 566ULL: goto x86_l_236;
	case 568ULL: goto x86_l_238;
	case 575ULL: goto x86_l_23f;
	case 580ULL: goto x86_l_244;
	case 587ULL: goto x86_l_24b;
	case 590ULL: goto x86_l_24e;
	case 595ULL: goto x86_l_253;
	case 597ULL: goto x86_l_255;
	case 601ULL: goto x86_l_259;
	case 606ULL: goto x86_l_25e;
	case 608ULL: goto x86_l_260;
	case 613ULL: goto x86_l_265;
	case 618ULL: goto x86_l_26a;
	case 623ULL: goto x86_l_26f;
	case 630ULL: goto x86_l_276;
	case 635ULL: goto x86_l_27b;
	case 637ULL: goto x86_l_27d;
	case 640ULL: goto x86_l_280;
	case 646ULL: goto x86_l_286;
	case 651ULL: goto x86_l_28b;
	case 658ULL: goto x86_l_292;
	case 663ULL: goto x86_l_297;
	case 665ULL: goto x86_l_299;
	case 670ULL: goto x86_l_29e;
	case 673ULL: goto x86_l_2a1;
	case 676ULL: goto x86_l_2a4;
	case 680ULL: goto x86_l_2a8;
	case 683ULL: goto x86_l_2ab;
	case 691ULL: goto x86_l_2b3;
	case 697ULL: goto x86_l_2b9;
	case 700ULL: goto x86_l_2bc;
	case 704ULL: goto x86_l_2c0;
	case 710ULL: goto x86_l_2c6;
	case 718ULL: goto x86_l_2ce;
	case 723ULL: goto x86_l_2d3;
	case 730ULL: goto x86_l_2da;
	case 736ULL: goto x86_l_2e0;
	case 739ULL: goto x86_l_2e3;
	case 746ULL: goto x86_l_2ea;
	case 751ULL: goto x86_l_2ef;
	case 754ULL: goto x86_l_2f2;
	case 760ULL: goto x86_l_2f8;
	case 763ULL: goto x86_l_2fb;
	case 767ULL: goto x86_l_2ff;
	case 771ULL: goto x86_l_303;
	case 777ULL: goto x86_l_309;
	case 786ULL: goto x86_l_312;
	case 792ULL: goto x86_l_318;
	case 800ULL: goto x86_l_320;
	case 806ULL: goto x86_l_326;
	case 810ULL: goto x86_l_32a;
	case 817ULL: goto x86_l_331;
	case 821ULL: goto x86_l_335;
	case 824ULL: goto x86_l_338;
	case 828ULL: goto x86_l_33c;
	case 830ULL: goto x86_l_33e;
	case 833ULL: goto x86_l_341;
	case 835ULL: goto x86_l_343;
	case 838ULL: goto x86_l_346;
	case 841ULL: goto x86_l_349;
	case 847ULL: goto x86_l_34f;
	case 850ULL: goto x86_l_352;
	case 856ULL: goto x86_l_358;
	case 861ULL: goto x86_l_35d;
	case 864ULL: goto x86_l_360;
	case 866ULL: goto x86_l_362;
	case 869ULL: goto x86_l_365;
	case 872ULL: goto x86_l_368;
	case 874ULL: goto x86_l_36a;
	case 877ULL: goto x86_l_36d;
	case 880ULL: goto x86_l_370;
	case 886ULL: goto x86_l_376;
	case 889ULL: goto x86_l_379;
	case 895ULL: goto x86_l_37f;
	case 900ULL: goto x86_l_384;
	case 905ULL: goto x86_l_389;
	case 908ULL: goto x86_l_38c;
	case 914ULL: goto x86_l_392;
	case 917ULL: goto x86_l_395;
	case 920ULL: goto x86_l_398;
	case 926ULL: goto x86_l_39e;
	case 929ULL: goto x86_l_3a1;
	case 932ULL: goto x86_l_3a4;
	case 938ULL: goto x86_l_3aa;
	case 943ULL: goto x86_l_3af;
	case 946ULL: goto x86_l_3b2;
	case 952ULL: goto x86_l_3b8;
	case 955ULL: goto x86_l_3bb;
	case 957ULL: goto x86_l_3bd;
	case 960ULL: goto x86_l_3c0;
	case 966ULL: goto x86_l_3c6;
	case 969ULL: goto x86_l_3c9;
	case 975ULL: goto x86_l_3cf;
	case 978ULL: goto x86_l_3d2;
	case 984ULL: goto x86_l_3d8;
	case 987ULL: goto x86_l_3db;
	case 993ULL: goto x86_l_3e1;
	case 995ULL: goto x86_l_3e3;
	case 1005ULL: goto x86_l_3ed;
	case 1009ULL: goto x86_l_3f1;
	case 1015ULL: goto x86_l_3f7;
	case 1020ULL: goto x86_l_3fc;
	case 1024ULL: goto x86_l_400;
	case 1030ULL: goto x86_l_406;
	case 1040ULL: goto x86_l_410;
	case 1044ULL: goto x86_l_414;
	case 1050ULL: goto x86_l_41a;
	case 1053ULL: goto x86_l_41d;
	case 1059ULL: goto x86_l_423;
	case 1061ULL: goto x86_l_425;
	case 1066ULL: goto x86_l_42a;
	case 1070ULL: goto x86_l_42e;
	case 1076ULL: goto x86_l_434;
	case 1080ULL: goto x86_l_438;
	case 1083ULL: goto x86_l_43b;
	case 1089ULL: goto x86_l_441;
	case 1092ULL: goto x86_l_444;
	case 1095ULL: goto x86_l_447;
	case 1099ULL: goto x86_l_44b;
	case 1105ULL: goto x86_l_451;
	case 1108ULL: goto x86_l_454;
	case 1110ULL: goto x86_l_456;
	case 1116ULL: goto x86_l_45c;
	case 1121ULL: goto x86_l_461;
	case 1124ULL: goto x86_l_464;
	case 1127ULL: goto x86_l_467;
	case 1133ULL: goto x86_l_46d;
	case 1136ULL: goto x86_l_470;
	case 1142ULL: goto x86_l_476;
	case 1145ULL: goto x86_l_479;
	case 1151ULL: goto x86_l_47f;
	case 1156ULL: goto x86_l_484;
	case 1159ULL: goto x86_l_487;
	case 1161ULL: goto x86_l_489;
	case 1164ULL: goto x86_l_48c;
	case 1168ULL: goto x86_l_490;
	case 1170ULL: goto x86_l_492;
	case 1173ULL: goto x86_l_495;
	case 1179ULL: goto x86_l_49b;
	case 1188ULL: goto x86_l_4a4;
	case 1197ULL: goto x86_l_4ad;
	case 1206ULL: goto x86_l_4b6;
	case 1215ULL: goto x86_l_4bf;
	case 1224ULL: goto x86_l_4c8;
	case 1227ULL: goto x86_l_4cb;
	case 1233ULL: goto x86_l_4d1;
	case 1236ULL: goto x86_l_4d4;
	case 1240ULL: goto x86_l_4d8;
	case 1246ULL: goto x86_l_4de;
	case 1249ULL: goto x86_l_4e1;
	case 1255ULL: goto x86_l_4e7;
	case 1258ULL: goto x86_l_4ea;
	case 1264ULL: goto x86_l_4f0;
	case 1269ULL: goto x86_l_4f5;
	case 1271ULL: goto x86_l_4f7;
	case 1275ULL: goto x86_l_4fb;
	case 1278ULL: goto x86_l_4fe;
	case 1284ULL: goto x86_l_504;
	case 1287ULL: goto x86_l_507;
	case 1290ULL: goto x86_l_50a;
	case 1296ULL: goto x86_l_510;
	case 1299ULL: goto x86_l_513;
	case 1305ULL: goto x86_l_519;
	case 1311ULL: goto x86_l_51f;
	case 1314ULL: goto x86_l_522;
	case 1320ULL: goto x86_l_528;
	case 1325ULL: goto x86_l_52d;
	case 1328ULL: goto x86_l_530;
	case 1334ULL: goto x86_l_536;
	case 1337ULL: goto x86_l_539;
	case 1343ULL: goto x86_l_53f;
	case 1346ULL: goto x86_l_542;
	case 1349ULL: goto x86_l_545;
	case 1355ULL: goto x86_l_54b;
	case 1358ULL: goto x86_l_54e;
	case 1364ULL: goto x86_l_554;
	case 1369ULL: goto x86_l_559;
	case 1372ULL: goto x86_l_55c;
	case 1378ULL: goto x86_l_562;
	case 1381ULL: goto x86_l_565;
	case 1387ULL: goto x86_l_56b;
	case 1391ULL: goto x86_l_56f;
	case 1395ULL: goto x86_l_573;
	case 1399ULL: goto x86_l_577;
	case 1403ULL: goto x86_l_57b;
	case 1406ULL: goto x86_l_57e;
	case 1412ULL: goto x86_l_584;
	case 1415ULL: goto x86_l_587;
	case 1418ULL: goto x86_l_58a;
	case 1424ULL: goto x86_l_590;
	case 1432ULL: goto x86_l_598;
	case 1438ULL: goto x86_l_59e;
	case 1441ULL: goto x86_l_5a1;
	case 1447ULL: goto x86_l_5a7;
	case 1451ULL: goto x86_l_5ab;
	case 1457ULL: goto x86_l_5b1;
	case 1460ULL: goto x86_l_5b4;
	case 1463ULL: goto x86_l_5b7;
	case 1466ULL: goto x86_l_5ba;
	case 1468ULL: goto x86_l_5bc;
	case 1470ULL: goto x86_l_5be;
	case 1473ULL: goto x86_l_5c1;
	case 1475ULL: goto x86_l_5c3;
	case 1478ULL: goto x86_l_5c6;
	case 1480ULL: goto x86_l_5c8;
	case 1482ULL: goto x86_l_5ca;
	case 1485ULL: goto x86_l_5cd;
	case 1488ULL: goto x86_l_5d0;
	case 1490ULL: goto x86_l_5d2;
	case 1492ULL: goto x86_l_5d4;
	case 1495ULL: goto x86_l_5d7;
	case 1499ULL: goto x86_l_5db;
	case 1503ULL: goto x86_l_5df;
	case 1509ULL: goto x86_l_5e5;
	case 1513ULL: goto x86_l_5e9;
	case 1519ULL: goto x86_l_5ef;
	case 1522ULL: goto x86_l_5f2;
	case 1524ULL: goto x86_l_5f4;
	case 1529ULL: goto x86_l_5f9;
	case 1533ULL: goto x86_l_5fd;
	case 1535ULL: goto x86_l_5ff;
	case 1537ULL: goto x86_l_601;
	case 1540ULL: goto x86_l_604;
	case 1543ULL: goto x86_l_607;
	case 1545ULL: goto x86_l_609;
	case 1547ULL: goto x86_l_60b;
	case 1553ULL: goto x86_l_611;
	case 1556ULL: goto x86_l_614;
	case 1560ULL: goto x86_l_618;
	case 1566ULL: goto x86_l_61e;
	case 1568ULL: goto x86_l_620;
	case 1573ULL: goto x86_l_625;
	case 1577ULL: goto x86_l_629;
	case 1583ULL: goto x86_l_62f;
	case 1588ULL: goto x86_l_634;
	case 1592ULL: goto x86_l_638;
	case 1598ULL: goto x86_l_63e;
	case 1608ULL: goto x86_l_648;
	case 1612ULL: goto x86_l_64c;
	case 1618ULL: goto x86_l_652;
	case 1625ULL: goto x86_l_659;
	case 1631ULL: goto x86_l_65f;
	case 1637ULL: goto x86_l_665;
	case 1640ULL: goto x86_l_668;
	case 1645ULL: goto x86_l_66d;
	case 1647ULL: goto x86_l_66f;
	case 1651ULL: goto x86_l_673;
	case 1655ULL: goto x86_l_677;
	case 1660ULL: goto x86_l_67c;
	case 1665ULL: goto x86_l_681;
	case 1667ULL: goto x86_l_683;
	case 1671ULL: goto x86_l_687;
	case 1673ULL: goto x86_l_689;
	case 1679ULL: goto x86_l_68f;
	case 1684ULL: goto x86_l_694;
	case 1689ULL: goto x86_l_699;
	case 1695ULL: goto x86_l_69f;
	case 1697ULL: goto x86_l_6a1;
	case 1703ULL: goto x86_l_6a7;
	case 1707ULL: goto x86_l_6ab;
	case 1710ULL: goto x86_l_6ae;
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
	/* 0xd: mov    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x1c227] */
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
	/* 0x31: je     1ca <generic_fentry_filter_arg+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ca;
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
	/* 0x48: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d:
	/* 0x4d: mov    rdi,QWORD PTR [rip+0x1c227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_54:
	/* 0x54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56:
	/* 0x56: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59:
	/* 0x59: je     1b4 <generic_fentry_filter_arg+0x1b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b4;
	}
x86_l_5f:
	/* 0x5f: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_67:
	/* 0x67: je     1b4 <generic_fentry_filter_arg+0x1b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b4;
	}
x86_l_6d:
	/* 0x6d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_70:
	/* 0x70: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_73:
	/* 0x73: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_76:
	/* 0x76: cmp    BYTE PTR [r14+rax*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699072ULL);
x86_l_7f:
	/* 0x7f: je     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_108;
	}
x86_l_85:
	/* 0x85: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_87:
	/* 0x87: mov    ecx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_8c:
	/* 0x8c: lea    rdx,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_90:
	/* 0x90: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_94:
	/* 0x94: lea    rax,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_98:
	/* 0x98: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_9c:
	/* 0x9c: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_a1:
	/* 0xa1: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_a5:
	/* 0xa5: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a8:
	/* 0xa8: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_ac:
	/* 0xac: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ae:
	/* 0xae: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b4:
	/* 0xb4: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_b8:
	/* 0xb8: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bb:
	/* 0xbb: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_bd:
	/* 0xbd: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_c2:
	/* 0xc2: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_c6:
	/* 0xc6: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c9:
	/* 0xc9: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_cb:
	/* 0xcb: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_d1:
	/* 0xd1: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_d5:
	/* 0xd5: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d8:
	/* 0xd8: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_da:
	/* 0xda: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_df:
	/* 0xdf: mov    r9d,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_e3:
	/* 0xe3: add    r9,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e6:
	/* 0xe6: mov    edi,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R9, X86_WIDTH_32);
x86_l_e9:
	/* 0xe9: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_ef:
	/* 0xef: cmp    DWORD PTR [r15+rdi*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 25ULL);
x86_l_f4:
	/* 0xf4: jae    15d <generic_fentry_filter_arg+0x15d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_15d;
	}
x86_l_f6:
	/* 0xf6: cmp    rdi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_64, 1ULL);
x86_l_fa:
	/* 0xfa: je     1b4 <generic_fentry_filter_arg+0x1b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b4;
	}
x86_l_100:
	/* 0x100: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_102:
	/* 0x102: jne    197 <generic_fentry_filter_arg+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_197;
	}
x86_l_108:
	/* 0x108: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_10c:
	/* 0x10c: jg     12d <generic_fentry_filter_arg+0x12d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_12d;
	}
x86_l_10e:
	/* 0x10e: cmp    r12d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_112:
	/* 0x112: je     1db <generic_fentry_filter_arg+0x1db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1db;
	}
x86_l_118:
	/* 0x118: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_11b:
	/* 0x11b: je     1e8 <generic_fentry_filter_arg+0x1e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e8;
	}
x86_l_121:
	/* 0x121: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_125:
	/* 0x125: je     1f8 <generic_fentry_filter_arg+0x1f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f8;
	}
x86_l_12b:
	/* 0x12b: jmp    14b <generic_fentry_filter_arg+0x14b> */
	goto x86_l_14b;
x86_l_12d:
	/* 0x12d: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_131:
	/* 0x131: je     208 <generic_fentry_filter_arg+0x208> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_208;
	}
x86_l_137:
	/* 0x137: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_13b:
	/* 0x13b: je     218 <generic_fentry_filter_arg+0x218> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_218;
	}
x86_l_141:
	/* 0x141: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_145:
	/* 0x145: je     228 <generic_fentry_filter_arg+0x228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_228;
	}
x86_l_14b:
	/* 0x14b: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_14f:
	/* 0x14f: jg     255 <generic_fentry_filter_arg+0x255> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_255;
	}
x86_l_155:
	/* 0x155: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_158:
	/* 0x158: jmp    238 <generic_fentry_filter_arg+0x238> */
	goto x86_l_238;
x86_l_15d:
	/* 0x15d: lea    rax,[r15+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_161:
	/* 0x161: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_169:
	/* 0x169: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16c:
	/* 0x16c: lea    rax,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_171:
	/* 0x171: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_176:
	/* 0x176: mov    QWORD PTR [rsp+0x20],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17b:
	/* 0x17b: mov    QWORD PTR [rsp+0xa8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_183:
	/* 0x183: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_188:
	/* 0x188: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18d:
	/* 0x18d: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_192:
	/* 0x192: jmp    2c6 <generic_fentry_filter_arg+0x2c6> */
	goto x86_l_2c6;
x86_l_197:
	/* 0x197: mov    DWORD PTR [r14+0x5f04],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_19e:
	/* 0x19e: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1a3:
	/* 0x1a3: mov    rsi,QWORD PTR [rip+0x1c227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_1aa:
	/* 0x1aa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ad:
	/* 0x1ad: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b2:
	/* 0x1b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b4:
	/* 0x1b4: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1b9:
	/* 0x1b9: mov    rsi,QWORD PTR [rip+0x1c227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_1c0:
	/* 0x1c0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c3:
	/* 0x1c3: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1c8:
	/* 0x1c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca:
	/* 0x1ca: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cc:
	/* 0x1cc: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_1d3:
	/* 0x1d3: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1d5:
	/* 0x1d5: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1d6:
	/* 0x1d6: jmp    39e5 <native_bpf_strncasestr+0x72> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_1db:
	/* 0x1db: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1de:
	/* 0x1de: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_1e6:
	/* 0x1e6: jne    238 <generic_fentry_filter_arg+0x238> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_238;
	}
x86_l_1e8:
	/* 0x1e8: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1ee:
	/* 0x1ee: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_1f6:
	/* 0x1f6: jne    238 <generic_fentry_filter_arg+0x238> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_238;
	}
x86_l_1f8:
	/* 0x1f8: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1fe:
	/* 0x1fe: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_206:
	/* 0x206: jne    238 <generic_fentry_filter_arg+0x238> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_238;
	}
x86_l_208:
	/* 0x208: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_20e:
	/* 0x20e: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_216:
	/* 0x216: jne    238 <generic_fentry_filter_arg+0x238> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_238;
	}
x86_l_218:
	/* 0x218: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_21e:
	/* 0x21e: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_226:
	/* 0x226: jne    238 <generic_fentry_filter_arg+0x238> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_238;
	}
x86_l_228:
	/* 0x228: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_22e:
	/* 0x22e: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_236:
	/* 0x236: je     255 <generic_fentry_filter_arg+0x255> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_255;
	}
x86_l_238:
	/* 0x238: mov    DWORD PTR [r14+0x5f00],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_23f:
	/* 0x23f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_244:
	/* 0x244: mov    rsi,QWORD PTR [rip+0x1c22a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_24b:
	/* 0x24b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_24e:
	/* 0x24e: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_253:
	/* 0x253: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255:
	/* 0x255: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_259:
	/* 0x259: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_25e:
	/* 0x25e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_260:
	/* 0x260: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_265:
	/* 0x265: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_26a:
	/* 0x26a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26f:
	/* 0x26f: mov    rdi,QWORD PTR [rip+0x1c22a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_276:
	/* 0x276: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_27b:
	/* 0x27b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d:
	/* 0x27d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_280:
	/* 0x280: je     1ca <generic_fentry_filter_arg+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ca;
	}
x86_l_286:
	/* 0x286: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_28b:
	/* 0x28b: mov    rdi,QWORD PTR [rip+0x1c22a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_292:
	/* 0x292: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_297:
	/* 0x297: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_299:
	/* 0x299: jmp    1ca <generic_fentry_filter_arg+0x1ca> */
	goto x86_l_1ca;
x86_l_29e:
	/* 0x29e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a1:
	/* 0x2a1: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2a4:
	/* 0x2a4: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_2a8:
	/* 0x2a8: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_2ab:
	/* 0x2ab: mov    r12,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2b3:
	/* 0x2b3: je     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_108;
	}
x86_l_2b9:
	/* 0x2b9: inc    r11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2bc:
	/* 0x2bc: cmp    r11,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 5ULL);
x86_l_2c0:
	/* 0x2c0: je     f6 <generic_fentry_filter_arg+0xf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f6;
	}
x86_l_2c6:
	/* 0x2c6: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2ce:
	/* 0x2ce: mov    r13d,DWORD PTR [rax+r11*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 2), 4ULL);
x86_l_2d3:
	/* 0x2d3: test   r13d,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R13, X86_WIDTH_32, 1023ULL);
x86_l_2da:
	/* 0x2da: je     f6 <generic_fentry_filter_arg+0xf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f6;
	}
x86_l_2e0:
	/* 0x2e0: add    r13d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e3:
	/* 0x2e3: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_2ea:
	/* 0x2ea: mov    eax,DWORD PTR [r15+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_2ef:
	/* 0x2ef: cmp    eax,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2f2:
	/* 0x2f2: je     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_108;
	}
x86_l_2f8:
	/* 0x2f8: add    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2fb:
	/* 0x2fb: mov    ecx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ff:
	/* 0x2ff: cmp    rcx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4ULL);
x86_l_303:
	/* 0x303: ja     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_108;
	}
x86_l_309:
	/* 0x309: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_312:
	/* 0x312: jne    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_108;
	}
x86_l_318:
	/* 0x318: mov    rcx,QWORD PTR [r14+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_320:
	/* 0x320: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_326:
	/* 0x326: lea    rsi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_32a:
	/* 0x32a: add    rsi,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_331:
	/* 0x331: mov    ecx,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_335:
	/* 0x335: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_338:
	/* 0x338: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33c:
	/* 0x33c: jle    35d <generic_fentry_filter_arg+0x35d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_35d;
	}
x86_l_33e:
	/* 0x33e: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_341:
	/* 0x341: jg     389 <generic_fentry_filter_arg+0x389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_389;
	}
x86_l_343:
	/* 0x343: lea    edx,[rcx-0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551588ULL);
x86_l_346:
	/* 0x346: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_349:
	/* 0x349: jb     3cf <generic_fentry_filter_arg+0x3cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3cf;
	}
x86_l_34f:
	/* 0x34f: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_352:
	/* 0x352: je     5f9 <generic_fentry_filter_arg+0x5f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f9;
	}
x86_l_358:
	/* 0x358: jmp    2b9 <generic_fentry_filter_arg+0x2b9> */
	goto x86_l_2b9;
x86_l_35d:
	/* 0x35d: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_360:
	/* 0x360: jle    3af <generic_fentry_filter_arg+0x3af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3af;
	}
x86_l_362:
	/* 0x362: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_365:
	/* 0x365: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_368:
	/* 0x368: jb     3cf <generic_fentry_filter_arg+0x3cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3cf;
	}
x86_l_36a:
	/* 0x36a: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_36d:
	/* 0x36d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_370:
	/* 0x370: jb     5f9 <generic_fentry_filter_arg+0x5f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5f9;
	}
x86_l_376:
	/* 0x376: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_379:
	/* 0x379: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b9;
	}
x86_l_37f:
	/* 0x37f: add    QWORD PTR [rsp],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 4ULL);
x86_l_384:
	/* 0x384: jmp    5f9 <generic_fentry_filter_arg+0x5f9> */
	goto x86_l_5f9;
x86_l_389:
	/* 0x389: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_38c:
	/* 0x38c: jg     559 <generic_fentry_filter_arg+0x559> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_559;
	}
x86_l_392:
	/* 0x392: lea    edx,[rcx-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_395:
	/* 0x395: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_398:
	/* 0x398: jb     4f5 <generic_fentry_filter_arg+0x4f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4f5;
	}
x86_l_39e:
	/* 0x39e: lea    edx,[rcx-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_3a1:
	/* 0x3a1: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3a4:
	/* 0x3a4: jb     49b <generic_fentry_filter_arg+0x49b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_49b;
	}
x86_l_3aa:
	/* 0x3aa: jmp    2b9 <generic_fentry_filter_arg+0x2b9> */
	goto x86_l_2b9;
x86_l_3af:
	/* 0x3af: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3b2:
	/* 0x3b2: jg     484 <generic_fentry_filter_arg+0x484> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_484;
	}
x86_l_3b8:
	/* 0x3b8: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3bb:
	/* 0x3bb: je     3cf <generic_fentry_filter_arg+0x3cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf;
	}
x86_l_3bd:
	/* 0x3bd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3c0:
	/* 0x3c0: je     b9f <generic_fentry_filter_arg+0xb9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2975ULL;
	}
x86_l_3c6:
	/* 0x3c6: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3c9:
	/* 0x3c9: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b9;
	}
x86_l_3cf:
	/* 0x3cf: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_3d2:
	/* 0x3d2: jle    461 <generic_fentry_filter_arg+0x461> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_461;
	}
x86_l_3d8:
	/* 0x3d8: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_3db:
	/* 0x3db: ja     715 <generic_fentry_filter_arg+0x715> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1813ULL;
	}
x86_l_3e1:
	/* 0x3e1: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_3e3:
	/* 0x3e3: movabs rsi,0x1e00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 128849018880ULL);
x86_l_3ed:
	/* 0x3ed: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3f1:
	/* 0x3f1: jb     52d <generic_fentry_filter_arg+0x52d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_52d;
	}
x86_l_3f7:
	/* 0x3f7: mov    esi,0x60000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1610612736ULL);
x86_l_3fc:
	/* 0x3fc: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_400:
	/* 0x400: jb     964 <generic_fentry_filter_arg+0x964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2404ULL;
	}
x86_l_406:
	/* 0x406: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_410:
	/* 0x410: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_414:
	/* 0x414: jae    715 <generic_fentry_filter_arg+0x715> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 1813ULL;
	}
x86_l_41a:
	/* 0x41a: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_41d:
	/* 0x41d: ja     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_108;
	}
x86_l_423:
	/* 0x423: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_425:
	/* 0x425: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_42a:
	/* 0x42a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_42e:
	/* 0x42e: jae    10f0 <generic_fentry_filter_arg+0x10f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4336ULL;
	}
x86_l_434:
	/* 0x434: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_438:
	/* 0x438: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_43b:
	/* 0x43b: jle    16d3 <generic_fentry_filter_arg+0x16d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5843ULL;
	}
x86_l_441:
	/* 0x441: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_444:
	/* 0x444: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_447:
	/* 0x447: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44b:
	/* 0x44b: jae    1ea1 <generic_fentry_filter_arg+0x1ea1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7841ULL;
	}
x86_l_451:
	/* 0x451: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_454:
	/* 0x454: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_456:
	/* 0x456: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29e;
	}
x86_l_45c:
	/* 0x45c: jmp    1fd2 <generic_fentry_filter_arg+0x1fd2> */
	return 8146ULL;
x86_l_461:
	/* 0x461: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_464:
	/* 0x464: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_467:
	/* 0x467: jb     c23 <generic_fentry_filter_arg+0xc23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3107ULL;
	}
x86_l_46d:
	/* 0x46d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_470:
	/* 0x470: je     721 <generic_fentry_filter_arg+0x721> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1825ULL;
	}
x86_l_476:
	/* 0x476: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_479:
	/* 0x479: je     721 <generic_fentry_filter_arg+0x721> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1825ULL;
	}
x86_l_47f:
	/* 0x47f: jmp    2b9 <generic_fentry_filter_arg+0x2b9> */
	goto x86_l_2b9;
x86_l_484:
	/* 0x484: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_487:
	/* 0x487: je     49b <generic_fentry_filter_arg+0x49b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49b;
	}
x86_l_489:
	/* 0x489: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_48c:
	/* 0x48c: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_490:
	/* 0x490: je     4f5 <generic_fentry_filter_arg+0x4f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f5;
	}
x86_l_492:
	/* 0x492: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_495:
	/* 0x495: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b9;
	}
x86_l_49b:
	/* 0x49b: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_4a4:
	/* 0x4a4: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_4ad:
	/* 0x4ad: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_4b6:
	/* 0x4b6: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_4bf:
	/* 0x4bf: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_4c8:
	/* 0x4c8: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_4cb:
	/* 0x4cb: jg     761 <generic_fentry_filter_arg+0x761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1889ULL;
	}
x86_l_4d1:
	/* 0x4d1: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4d4:
	/* 0x4d4: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d8:
	/* 0x4d8: je     d8c <generic_fentry_filter_arg+0xd8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3468ULL;
	}
x86_l_4de:
	/* 0x4de: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_4e1:
	/* 0x4e1: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_4e7:
	/* 0x4e7: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_4ea:
	/* 0x4ea: je     d8e <generic_fentry_filter_arg+0xd8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3470ULL;
	}
x86_l_4f0:
	/* 0x4f0: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	goto x86_l_2a8;
x86_l_4f5:
	/* 0x4f5: mov    ebp,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f7:
	/* 0x4f7: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4fb:
	/* 0x4fb: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_4fe:
	/* 0x4fe: jg     7eb <generic_fentry_filter_arg+0x7eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2027ULL;
	}
x86_l_504:
	/* 0x504: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_507:
	/* 0x507: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_50a:
	/* 0x50a: jb     100f <generic_fentry_filter_arg+0x100f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4111ULL;
	}
x86_l_510:
	/* 0x510: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_513:
	/* 0x513: je     f63 <generic_fentry_filter_arg+0xf63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3939ULL;
	}
x86_l_519:
	/* 0x519: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_51f:
	/* 0x51f: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_522:
	/* 0x522: je     80c <generic_fentry_filter_arg+0x80c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2060ULL;
	}
x86_l_528:
	/* 0x528: jmp    35bf <generic_fentry_filter_arg+0x35bf> */
	return 13759ULL;
x86_l_52d:
	/* 0x52d: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_530:
	/* 0x530: jle    b8e <generic_fentry_filter_arg+0xb8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2958ULL;
	}
x86_l_536:
	/* 0x536: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_539:
	/* 0x539: jg     f12 <generic_fentry_filter_arg+0xf12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3858ULL;
	}
x86_l_53f:
	/* 0x53f: lea    edx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_542:
	/* 0x542: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_545:
	/* 0x545: jb     cb6 <generic_fentry_filter_arg+0xcb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3254ULL;
	}
x86_l_54b:
	/* 0x54b: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_54e:
	/* 0x54e: je     c39 <generic_fentry_filter_arg+0xc39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3129ULL;
	}
x86_l_554:
	/* 0x554: jmp    108 <generic_fentry_filter_arg+0x108> */
	goto x86_l_108;
x86_l_559:
	/* 0x559: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_55c:
	/* 0x55c: je     5f9 <generic_fentry_filter_arg+0x5f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f9;
	}
x86_l_562:
	/* 0x562: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_565:
	/* 0x565: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b9;
	}
x86_l_56b:
	/* 0x56b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56f:
	/* 0x56f: lea    rsi,[rcx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_573:
	/* 0x573: movzx  ebp,BYTE PTR [rcx+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_577:
	/* 0x577: movzx  edx,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_57b:
	/* 0x57b: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_57e:
	/* 0x57e: jg     13c9 <generic_fentry_filter_arg+0x13c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5065ULL;
	}
x86_l_584:
	/* 0x584: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_587:
	/* 0x587: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_58a:
	/* 0x58a: jae    1a2f <generic_fentry_filter_arg+0x1a2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6703ULL;
	}
x86_l_590:
	/* 0x590: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_598:
	/* 0x598: mov    r10d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 256ULL);
x86_l_59e:
	/* 0x59e: cmp    dl,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 144ULL);
x86_l_5a1:
	/* 0x5a1: ja     17b7 <generic_fentry_filter_arg+0x17b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6071ULL;
	}
x86_l_5a7:
	/* 0x5a7: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5ab:
	/* 0x5ab: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_5b1:
	/* 0x5b1: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_5b4:
	/* 0x5b4: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_5b7:
	/* 0x5b7: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_5ba:
	/* 0x5ba: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_5bc:
	/* 0x5bc: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5be:
	/* 0x5be: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_5c1:
	/* 0x5c1: je     5ca <generic_fentry_filter_arg+0x5ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ca;
	}
x86_l_5c3:
	/* 0x5c3: mov    r10d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RDX, X86_WIDTH_32);
x86_l_5c6:
	/* 0x5c6: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_5c8:
	/* 0x5c8: je     5e5 <generic_fentry_filter_arg+0x5e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e5;
	}
x86_l_5ca:
	/* 0x5ca: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5cd:
	/* 0x5cd: movzx  ecx,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5d0:
	/* 0x5d0: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5d2:
	/* 0x5d2: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_5d4:
	/* 0x5d4: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_5d7:
	/* 0x5d7: movzx  r10d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5db:
	/* 0x5db: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_5df:
	/* 0x5df: ja     17b7 <generic_fentry_filter_arg+0x17b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6071ULL;
	}
x86_l_5e5:
	/* 0x5e5: movzx  eax,r10b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R10, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5e9:
	/* 0x5e9: imul   ebx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RBX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_5ef:
	/* 0x5ef: shr    ebx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_5f2:
	/* 0x5f2: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_5f4:
	/* 0x5f4: jmp    2754 <generic_fentry_filter_arg+0x2754> */
	return 10068ULL;
x86_l_5f9:
	/* 0x5f9: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fd:
	/* 0x5fd: mov    ebp,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ff:
	/* 0x5ff: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_601:
	/* 0x601: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_604:
	/* 0x604: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_607:
	/* 0x607: je     611 <generic_fentry_filter_arg+0x611> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_611;
	}
x86_l_609:
	/* 0x609: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_60b:
	/* 0x60b: je     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_108;
	}
x86_l_611:
	/* 0x611: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_614:
	/* 0x614: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_618:
	/* 0x618: ja     93b <generic_fentry_filter_arg+0x93b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2363ULL;
	}
x86_l_61e:
	/* 0x61e: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_620:
	/* 0x620: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_625:
	/* 0x625: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_629:
	/* 0x629: jb     ae2 <generic_fentry_filter_arg+0xae2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2786ULL;
	}
x86_l_62f:
	/* 0x62f: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_634:
	/* 0x634: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_638:
	/* 0x638: jb     9b3 <generic_fentry_filter_arg+0x9b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2483ULL;
	}
x86_l_63e:
	/* 0x63e: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_648:
	/* 0x648: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_64c:
	/* 0x64c: jae    93b <generic_fentry_filter_arg+0x93b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2363ULL;
	}
x86_l_652:
	/* 0x652: mov    WORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_659:
	/* 0x659: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_65f:
	/* 0x65f: ja     9ab <generic_fentry_filter_arg+0x9ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2475ULL;
	}
x86_l_665:
	/* 0x665: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_668:
	/* 0x668: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_66d:
	/* 0x66d: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66f:
	/* 0x66f: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_673:
	/* 0x673: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_677:
	/* 0x677: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_67c:
	/* 0x67c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_681:
	/* 0x681: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_683:
	/* 0x683: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_687:
	/* 0x687: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_689:
	/* 0x689: je     1d09 <generic_fentry_filter_arg+0x1d09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7433ULL;
	}
x86_l_68f:
	/* 0x68f: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_694:
	/* 0x694: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_699:
	/* 0x699: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_69f:
	/* 0x69f: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6a1:
	/* 0x6a1: je     1d0c <generic_fentry_filter_arg+0x1d0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7436ULL;
	}
x86_l_6a7:
	/* 0x6a7: mov    ecx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ab:
	/* 0x6ab: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_6ae:
	/* 0x6ae: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 1715ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1723ULL: goto x86_l_6bb;
	case 1729ULL: goto x86_l_6c1;
	case 1733ULL: goto x86_l_6c5;
	case 1735ULL: goto x86_l_6c7;
	case 1741ULL: goto x86_l_6cd;
	case 1743ULL: goto x86_l_6cf;
	case 1749ULL: goto x86_l_6d5;
	case 1752ULL: goto x86_l_6d8;
	case 1758ULL: goto x86_l_6de;
	case 1762ULL: goto x86_l_6e2;
	case 1764ULL: goto x86_l_6e4;
	case 1770ULL: goto x86_l_6ea;
	case 1772ULL: goto x86_l_6ec;
	case 1778ULL: goto x86_l_6f2;
	case 1781ULL: goto x86_l_6f5;
	case 1787ULL: goto x86_l_6fb;
	case 1791ULL: goto x86_l_6ff;
	case 1793ULL: goto x86_l_701;
	case 1799ULL: goto x86_l_707;
	case 1802ULL: goto x86_l_70a;
	case 1804ULL: goto x86_l_70c;
	case 1808ULL: goto x86_l_710;
	case 1813ULL: goto x86_l_715;
	case 1816ULL: goto x86_l_718;
	case 1819ULL: goto x86_l_71b;
	case 1825ULL: goto x86_l_721;
	case 1828ULL: goto x86_l_724;
	case 1834ULL: goto x86_l_72a;
	case 1836ULL: goto x86_l_72c;
	case 1841ULL: goto x86_l_731;
	case 1845ULL: goto x86_l_735;
	case 1847ULL: goto x86_l_737;
	case 1851ULL: goto x86_l_73b;
	case 1854ULL: goto x86_l_73e;
	case 1860ULL: goto x86_l_744;
	case 1863ULL: goto x86_l_747;
	case 1866ULL: goto x86_l_74a;
	case 1872ULL: goto x86_l_750;
	case 1876ULL: goto x86_l_754;
	case 1878ULL: goto x86_l_756;
	case 1884ULL: goto x86_l_75c;
	case 1889ULL: goto x86_l_761;
	case 1892ULL: goto x86_l_764;
	case 1896ULL: goto x86_l_768;
	case 1902ULL: goto x86_l_76e;
	case 1905ULL: goto x86_l_771;
	case 1911ULL: goto x86_l_777;
	case 1914ULL: goto x86_l_77a;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1930ULL: goto x86_l_78a;
	case 1934ULL: goto x86_l_78e;
	case 1940ULL: goto x86_l_794;
	case 1950ULL: goto x86_l_79e;
	case 1954ULL: goto x86_l_7a2;
	case 1960ULL: goto x86_l_7a8;
	case 1963ULL: goto x86_l_7ab;
	case 1969ULL: goto x86_l_7b1;
	case 1973ULL: goto x86_l_7b5;
	case 1977ULL: goto x86_l_7b9;
	case 1980ULL: goto x86_l_7bc;
	case 1986ULL: goto x86_l_7c2;
	case 1991ULL: goto x86_l_7c7;
	case 1994ULL: goto x86_l_7ca;
	case 2000ULL: goto x86_l_7d0;
	case 2004ULL: goto x86_l_7d4;
	case 2006ULL: goto x86_l_7d6;
	case 2008ULL: goto x86_l_7d8;
	case 2014ULL: goto x86_l_7de;
	case 2016ULL: goto x86_l_7e0;
	case 2022ULL: goto x86_l_7e6;
	case 2027ULL: goto x86_l_7eb;
	case 2030ULL: goto x86_l_7ee;
	case 2036ULL: goto x86_l_7f4;
	case 2039ULL: goto x86_l_7f7;
	case 2045ULL: goto x86_l_7fd;
	case 2051ULL: goto x86_l_803;
	case 2054ULL: goto x86_l_806;
	case 2060ULL: goto x86_l_80c;
	case 2064ULL: goto x86_l_810;
	case 2069ULL: goto x86_l_815;
	case 2073ULL: goto x86_l_819;
	case 2077ULL: goto x86_l_81d;
	case 2085ULL: goto x86_l_825;
	case 2090ULL: goto x86_l_82a;
	case 2097ULL: goto x86_l_831;
	case 2102ULL: goto x86_l_836;
	case 2104ULL: goto x86_l_838;
	case 2106ULL: goto x86_l_83a;
	case 2112ULL: goto x86_l_840;
	case 2118ULL: goto x86_l_846;
	case 2121ULL: goto x86_l_849;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2137ULL: goto x86_l_859;
	case 2144ULL: goto x86_l_860;
	case 2149ULL: goto x86_l_865;
	case 2151ULL: goto x86_l_867;
	case 2154ULL: goto x86_l_86a;
	case 2160ULL: goto x86_l_870;
	case 2163ULL: goto x86_l_873;
	case 2166ULL: goto x86_l_876;
	case 2171ULL: goto x86_l_87b;
	case 2174ULL: goto x86_l_87e;
	case 2177ULL: goto x86_l_881;
	case 2179ULL: goto x86_l_883;
	case 2182ULL: goto x86_l_886;
	case 2185ULL: goto x86_l_889;
	case 2190ULL: goto x86_l_88e;
	case 2193ULL: goto x86_l_891;
	case 2196ULL: goto x86_l_894;
	case 2201ULL: goto x86_l_899;
	case 2205ULL: goto x86_l_89d;
	case 2211ULL: goto x86_l_8a3;
	case 2214ULL: goto x86_l_8a6;
	case 2218ULL: goto x86_l_8aa;
	case 2224ULL: goto x86_l_8b0;
	case 2227ULL: goto x86_l_8b3;
	case 2231ULL: goto x86_l_8b7;
	case 2233ULL: goto x86_l_8b9;
	case 2236ULL: goto x86_l_8bc;
	case 2240ULL: goto x86_l_8c0;
	case 2244ULL: goto x86_l_8c4;
	case 2250ULL: goto x86_l_8ca;
	case 2254ULL: goto x86_l_8ce;
	case 2257ULL: goto x86_l_8d1;
	case 2260ULL: goto x86_l_8d4;
	case 2262ULL: goto x86_l_8d6;
	case 2266ULL: goto x86_l_8da;
	case 2272ULL: goto x86_l_8e0;
	case 2276ULL: goto x86_l_8e4;
	case 2279ULL: goto x86_l_8e7;
	case 2282ULL: goto x86_l_8ea;
	case 2284ULL: goto x86_l_8ec;
	case 2288ULL: goto x86_l_8f0;
	case 2294ULL: goto x86_l_8f6;
	case 2298ULL: goto x86_l_8fa;
	case 2301ULL: goto x86_l_8fd;
	case 2304ULL: goto x86_l_900;
	case 2306ULL: goto x86_l_902;
	case 2310ULL: goto x86_l_906;
	case 2312ULL: goto x86_l_908;
	case 2316ULL: goto x86_l_90c;
	case 2322ULL: goto x86_l_912;
	case 2326ULL: goto x86_l_916;
	case 2328ULL: goto x86_l_918;
	case 2332ULL: goto x86_l_91c;
	case 2336ULL: goto x86_l_920;
	case 2339ULL: goto x86_l_923;
	case 2341ULL: goto x86_l_925;
	case 2346ULL: goto x86_l_92a;
	case 2351ULL: goto x86_l_92f;
	case 2356ULL: goto x86_l_934;
	case 2358ULL: goto x86_l_936;
	case 2363ULL: goto x86_l_93b;
	case 2366ULL: goto x86_l_93e;
	case 2369ULL: goto x86_l_941;
	case 2371ULL: goto x86_l_943;
	case 2379ULL: goto x86_l_94b;
	case 2385ULL: goto x86_l_951;
	case 2391ULL: goto x86_l_957;
	case 2394ULL: goto x86_l_95a;
	case 2399ULL: goto x86_l_95f;
	case 2404ULL: goto x86_l_964;
	case 2407ULL: goto x86_l_967;
	case 2413ULL: goto x86_l_96d;
	case 2415ULL: goto x86_l_96f;
	case 2420ULL: goto x86_l_974;
	case 2424ULL: goto x86_l_978;
	case 2430ULL: goto x86_l_97e;
	case 2434ULL: goto x86_l_982;
	case 2437ULL: goto x86_l_985;
	case 2443ULL: goto x86_l_98b;
	case 2446ULL: goto x86_l_98e;
	case 2449ULL: goto x86_l_991;
	case 2453ULL: goto x86_l_995;
	case 2459ULL: goto x86_l_99b;
	case 2462ULL: goto x86_l_99e;
	case 2464ULL: goto x86_l_9a0;
	case 2470ULL: goto x86_l_9a6;
	case 2475ULL: goto x86_l_9ab;
	case 2478ULL: goto x86_l_9ae;
	case 2483ULL: goto x86_l_9b3;
	case 2488ULL: goto x86_l_9b8;
	case 2492ULL: goto x86_l_9bc;
	case 2496ULL: goto x86_l_9c0;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2516ULL: goto x86_l_9d4;
	case 2521ULL: goto x86_l_9d9;
	case 2523ULL: goto x86_l_9db;
	case 2525ULL: goto x86_l_9dd;
	case 2531ULL: goto x86_l_9e3;
	case 2537ULL: goto x86_l_9e9;
	case 2540ULL: goto x86_l_9ec;
	case 2546ULL: goto x86_l_9f2;
	case 2551ULL: goto x86_l_9f7;
	case 2556ULL: goto x86_l_9fc;
	case 2563ULL: goto x86_l_a03;
	case 2568ULL: goto x86_l_a08;
	case 2570ULL: goto x86_l_a0a;
	case 2573ULL: goto x86_l_a0d;
	case 2579ULL: goto x86_l_a13;
	case 2582ULL: goto x86_l_a16;
	case 2585ULL: goto x86_l_a19;
	case 2590ULL: goto x86_l_a1e;
	case 2593ULL: goto x86_l_a21;
	case 2596ULL: goto x86_l_a24;
	case 2598ULL: goto x86_l_a26;
	case 2601ULL: goto x86_l_a29;
	case 2604ULL: goto x86_l_a2c;
	case 2609ULL: goto x86_l_a31;
	case 2612ULL: goto x86_l_a34;
	case 2615ULL: goto x86_l_a37;
	case 2620ULL: goto x86_l_a3c;
	case 2624ULL: goto x86_l_a40;
	case 2630ULL: goto x86_l_a46;
	case 2633ULL: goto x86_l_a49;
	case 2637ULL: goto x86_l_a4d;
	case 2643ULL: goto x86_l_a53;
	case 2646ULL: goto x86_l_a56;
	case 2650ULL: goto x86_l_a5a;
	case 2652ULL: goto x86_l_a5c;
	case 2655ULL: goto x86_l_a5f;
	case 2659ULL: goto x86_l_a63;
	case 2663ULL: goto x86_l_a67;
	case 2669ULL: goto x86_l_a6d;
	case 2674ULL: goto x86_l_a72;
	case 2677ULL: goto x86_l_a75;
	case 2680ULL: goto x86_l_a78;
	case 2682ULL: goto x86_l_a7a;
	case 2686ULL: goto x86_l_a7e;
	case 2692ULL: goto x86_l_a84;
	case 2697ULL: goto x86_l_a89;
	case 2700ULL: goto x86_l_a8c;
	case 2703ULL: goto x86_l_a8f;
	case 2705ULL: goto x86_l_a91;
	case 2709ULL: goto x86_l_a95;
	case 2715ULL: goto x86_l_a9b;
	case 2720ULL: goto x86_l_aa0;
	case 2723ULL: goto x86_l_aa3;
	case 2726ULL: goto x86_l_aa6;
	case 2728ULL: goto x86_l_aa8;
	case 2732ULL: goto x86_l_aac;
	case 2734ULL: goto x86_l_aae;
	case 2738ULL: goto x86_l_ab2;
	case 2744ULL: goto x86_l_ab8;
	case 2749ULL: goto x86_l_abd;
	case 2751ULL: goto x86_l_abf;
	case 2755ULL: goto x86_l_ac3;
	case 2759ULL: goto x86_l_ac7;
	case 2762ULL: goto x86_l_aca;
	case 2764ULL: goto x86_l_acc;
	case 2769ULL: goto x86_l_ad1;
	case 2774ULL: goto x86_l_ad6;
	case 2779ULL: goto x86_l_adb;
	case 2781ULL: goto x86_l_add;
	case 2786ULL: goto x86_l_ae2;
	case 2791ULL: goto x86_l_ae7;
	case 2795ULL: goto x86_l_aeb;
	case 2799ULL: goto x86_l_aef;
	case 2807ULL: goto x86_l_af7;
	case 2812ULL: goto x86_l_afc;
	case 2819ULL: goto x86_l_b03;
	case 2824ULL: goto x86_l_b08;
	case 2826ULL: goto x86_l_b0a;
	case 2828ULL: goto x86_l_b0c;
	case 2834ULL: goto x86_l_b12;
	case 2840ULL: goto x86_l_b18;
	case 2843ULL: goto x86_l_b1b;
	case 2849ULL: goto x86_l_b21;
	case 2852ULL: goto x86_l_b24;
	case 2857ULL: goto x86_l_b29;
	case 2864ULL: goto x86_l_b30;
	case 2869ULL: goto x86_l_b35;
	case 2871ULL: goto x86_l_b37;
	case 2874ULL: goto x86_l_b3a;
	case 2880ULL: goto x86_l_b40;
	case 2883ULL: goto x86_l_b43;
	case 2887ULL: goto x86_l_b47;
	case 2891ULL: goto x86_l_b4b;
	case 2897ULL: goto x86_l_b51;
	case 2902ULL: goto x86_l_b56;
	case 2905ULL: goto x86_l_b59;
	case 2912ULL: goto x86_l_b60;
	case 2914ULL: goto x86_l_b62;
	case 2917ULL: goto x86_l_b65;
	case 2921ULL: goto x86_l_b69;
	case 2926ULL: goto x86_l_b6e;
	case 2928ULL: goto x86_l_b70;
	case 2930ULL: goto x86_l_b72;
	case 2935ULL: goto x86_l_b77;
	case 2938ULL: goto x86_l_b7a;
	case 2941ULL: goto x86_l_b7d;
	case 2943ULL: goto x86_l_b7f;
	case 2946ULL: goto x86_l_b82;
	case 2949ULL: goto x86_l_b85;
	case 2953ULL: goto x86_l_b89;
	case 2958ULL: goto x86_l_b8e;
	case 2961ULL: goto x86_l_b91;
	case 2964ULL: goto x86_l_b94;
	case 2970ULL: goto x86_l_b9a;
	case 2975ULL: goto x86_l_b9f;
	case 2979ULL: goto x86_l_ba3;
	case 2982ULL: goto x86_l_ba6;
	case 2986ULL: goto x86_l_baa;
	case 2989ULL: goto x86_l_bad;
	case 2995ULL: goto x86_l_bb3;
	case 2998ULL: goto x86_l_bb6;
	case 3001ULL: goto x86_l_bb9;
	case 3007ULL: goto x86_l_bbf;
	case 3011ULL: goto x86_l_bc3;
	case 3014ULL: goto x86_l_bc6;
	case 3020ULL: goto x86_l_bcc;
	case 3026ULL: goto x86_l_bd2;
	case 3029ULL: goto x86_l_bd5;
	case 3035ULL: goto x86_l_bdb;
	case 3040ULL: goto x86_l_be0;
	case 3043ULL: goto x86_l_be3;
	case 3049ULL: goto x86_l_be9;
	case 3052ULL: goto x86_l_bec;
	case 3058ULL: goto x86_l_bf2;
	case 3061ULL: goto x86_l_bf5;
	case 3067ULL: goto x86_l_bfb;
	case 3072ULL: goto x86_l_c00;
	case 3075ULL: goto x86_l_c03;
	case 3081ULL: goto x86_l_c09;
	case 3085ULL: goto x86_l_c0d;
	case 3087ULL: goto x86_l_c0f;
	case 3093ULL: goto x86_l_c15;
	case 3098ULL: goto x86_l_c1a;
	case 3101ULL: goto x86_l_c1d;
	case 3107ULL: goto x86_l_c23;
	case 3110ULL: goto x86_l_c26;
	case 3116ULL: goto x86_l_c2c;
	case 3118ULL: goto x86_l_c2e;
	case 3123ULL: goto x86_l_c33;
	case 3127ULL: goto x86_l_c37;
	case 3129ULL: goto x86_l_c39;
	case 3133ULL: goto x86_l_c3d;
	case 3136ULL: goto x86_l_c40;
	case 3138ULL: goto x86_l_c42;
	case 3141ULL: goto x86_l_c45;
	case 3144ULL: goto x86_l_c48;
	case 3150ULL: goto x86_l_c4e;
	case 3154ULL: goto x86_l_c52;
	case 3157ULL: goto x86_l_c55;
	case 3163ULL: goto x86_l_c5b;
	case 3168ULL: goto x86_l_c60;
	case 3173ULL: goto x86_l_c65;
	case 3177ULL: goto x86_l_c69;
	case 3179ULL: goto x86_l_c6b;
	case 3189ULL: goto x86_l_c75;
	case 3193ULL: goto x86_l_c79;
	case 3199ULL: goto x86_l_c7f;
	case 3204ULL: goto x86_l_c84;
	case 3207ULL: goto x86_l_c87;
	case 3213ULL: goto x86_l_c8d;
	case 3216ULL: goto x86_l_c90;
	case 3222ULL: goto x86_l_c96;
	case 3225ULL: goto x86_l_c99;
	case 3227ULL: goto x86_l_c9b;
	case 3230ULL: goto x86_l_c9e;
	case 3236ULL: goto x86_l_ca4;
	case 3240ULL: goto x86_l_ca8;
	case 3243ULL: goto x86_l_cab;
	case 3249ULL: goto x86_l_cb1;
	case 3254ULL: goto x86_l_cb6;
	case 3257ULL: goto x86_l_cb9;
	case 3262ULL: goto x86_l_cbe;
	case 3266ULL: goto x86_l_cc2;
	case 3271ULL: goto x86_l_cc7;
	case 3278ULL: goto x86_l_cce;
	case 3283ULL: goto x86_l_cd3;
	case 3285ULL: goto x86_l_cd5;
	case 3288ULL: goto x86_l_cd8;
	case 3294ULL: goto x86_l_cde;
	case 3298ULL: goto x86_l_ce2;
	case 3301ULL: goto x86_l_ce5;
	case 3306ULL: goto x86_l_cea;
	case 3311ULL: goto x86_l_cef;
	case 3314ULL: goto x86_l_cf2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6b3:
	/* 0x6b3: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b8:
	/* 0x6b8: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_6bb:
	/* 0x6bb: jb     9ab <generic_fentry_filter_arg+0x9ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9ab;
	}
x86_l_6c1:
	/* 0x6c1: mov    edx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6c5:
	/* 0x6c5: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_6c7:
	/* 0x6c7: je     9ab <generic_fentry_filter_arg+0x9ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9ab;
	}
x86_l_6cd:
	/* 0x6cd: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_6cf:
	/* 0x6cf: je     1d32 <generic_fentry_filter_arg+0x1d32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7474ULL;
	}
x86_l_6d5:
	/* 0x6d5: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6d8:
	/* 0x6d8: jb     9ab <generic_fentry_filter_arg+0x9ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9ab;
	}
x86_l_6de:
	/* 0x6de: mov    edx,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6e2:
	/* 0x6e2: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_6e4:
	/* 0x6e4: je     9ab <generic_fentry_filter_arg+0x9ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9ab;
	}
x86_l_6ea:
	/* 0x6ea: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_6ec:
	/* 0x6ec: je     1d32 <generic_fentry_filter_arg+0x1d32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7474ULL;
	}
x86_l_6f2:
	/* 0x6f2: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_6f5:
	/* 0x6f5: jb     390f <generic_fentry_filter_arg+0x390f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14607ULL;
	}
x86_l_6fb:
	/* 0x6fb: mov    ecx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_6ff:
	/* 0x6ff: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_701:
	/* 0x701: je     390f <generic_fentry_filter_arg+0x390f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14607ULL;
	}
x86_l_707:
	/* 0x707: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_70a:
	/* 0x70a: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_70c:
	/* 0x70c: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_710:
	/* 0x710: jmp    3912 <generic_fentry_filter_arg+0x3912> */
	return 14610ULL;
x86_l_715:
	/* 0x715: lea    edx,[rcx-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_718:
	/* 0x718: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_71b:
	/* 0x71b: jae    c1a <generic_fentry_filter_arg+0xc1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_c1a;
	}
x86_l_721:
	/* 0x721: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_724:
	/* 0x724: ja     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 264ULL;
	}
x86_l_72a:
	/* 0x72a: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_72c:
	/* 0x72c: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_731:
	/* 0x731: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_735:
	/* 0x735: jae    785 <generic_fentry_filter_arg+0x785> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_785;
	}
x86_l_737:
	/* 0x737: mov    edx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_73b:
	/* 0x73b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_73e:
	/* 0x73e: jle    be0 <generic_fentry_filter_arg+0xbe0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_be0;
	}
x86_l_744:
	/* 0x744: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_747:
	/* 0x747: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_74a:
	/* 0x74a: jae    10d6 <generic_fentry_filter_arg+0x10d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4310ULL;
	}
x86_l_750:
	/* 0x750: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_754:
	/* 0x754: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_756:
	/* 0x756: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 670ULL;
	}
x86_l_75c:
	/* 0x75c: jmp    23ea <generic_fentry_filter_arg+0x23ea> */
	return 9194ULL;
x86_l_761:
	/* 0x761: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_764:
	/* 0x764: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_768:
	/* 0x768: je     d64 <generic_fentry_filter_arg+0xd64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3428ULL;
	}
x86_l_76e:
	/* 0x76e: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_771:
	/* 0x771: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_777:
	/* 0x777: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_77a:
	/* 0x77a: je     d8e <generic_fentry_filter_arg+0xd8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3470ULL;
	}
x86_l_780:
	/* 0x780: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_785:
	/* 0x785: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_78a:
	/* 0x78a: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_78e:
	/* 0x78e: jb     d27 <generic_fentry_filter_arg+0xd27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3367ULL;
	}
x86_l_794:
	/* 0x794: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_79e:
	/* 0x79e: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_7a2:
	/* 0x7a2: jae    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 264ULL;
	}
x86_l_7a8:
	/* 0x7a8: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_7ab:
	/* 0x7ab: jne    1394 <generic_fentry_filter_arg+0x1394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5012ULL;
	}
x86_l_7b1:
	/* 0x7b1: mov    esi,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b5:
	/* 0x7b5: mov    edx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7b9:
	/* 0x7b9: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_7bc:
	/* 0x7bc: ja     2055 <generic_fentry_filter_arg+0x2055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8277ULL;
	}
x86_l_7c2:
	/* 0x7c2: mov    eax,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5122ULL);
x86_l_7c7:
	/* 0x7c7: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_7ca:
	/* 0x7ca: jae    2055 <generic_fentry_filter_arg+0x2055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8277ULL;
	}
x86_l_7d0:
	/* 0x7d0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7d4:
	/* 0x7d4: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7d6:
	/* 0x7d6: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_7d8:
	/* 0x7d8: jg     2067 <generic_fentry_filter_arg+0x2067> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8295ULL;
	}
x86_l_7de:
	/* 0x7de: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_7e0:
	/* 0x7e0: jle    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 697ULL;
	}
x86_l_7e6:
	/* 0x7e6: jmp    2067 <generic_fentry_filter_arg+0x2067> */
	return 8295ULL;
x86_l_7eb:
	/* 0x7eb: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_7ee:
	/* 0x7ee: jg     e15 <generic_fentry_filter_arg+0xe15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3605ULL;
	}
x86_l_7f4:
	/* 0x7f4: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_7f7:
	/* 0x7f7: je     f63 <generic_fentry_filter_arg+0xf63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3939ULL;
	}
x86_l_7fd:
	/* 0x7fd: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_803:
	/* 0x803: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_806:
	/* 0x806: jne    35bf <generic_fentry_filter_arg+0x35bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13759ULL;
	}
x86_l_80c:
	/* 0x80c: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_810:
	/* 0x810: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_815:
	/* 0x815: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_819:
	/* 0x819: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_81d:
	/* 0x81d: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_825:
	/* 0x825: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_82a:
	/* 0x82a: mov    rdi,QWORD PTR [rip+0x1c238] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_831:
	/* 0x831: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_836:
	/* 0x836: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_838:
	/* 0x838: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_83a:
	/* 0x83a: je     16ae <generic_fentry_filter_arg+0x16ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5806ULL;
	}
x86_l_840:
	/* 0x840: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_846:
	/* 0x846: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_849:
	/* 0x849: je     16b1 <generic_fentry_filter_arg+0x16b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5809ULL;
	}
x86_l_84f:
	/* 0x84f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_854:
	/* 0x854: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_859:
	/* 0x859: mov    rdi,QWORD PTR [rip+0x1c238] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_860:
	/* 0x860: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_865:
	/* 0x865: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_867:
	/* 0x867: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_86a:
	/* 0x86a: je     16ae <generic_fentry_filter_arg+0x16ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5806ULL;
	}
x86_l_870:
	/* 0x870: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_873:
	/* 0x873: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_876:
	/* 0x876: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_87b:
	/* 0x87b: cmovb  ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_87e:
	/* 0x87e: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_881:
	/* 0x881: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_883:
	/* 0x883: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_886:
	/* 0x886: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_889:
	/* 0x889: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_88e:
	/* 0x88e: sub    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_891:
	/* 0x891: lea    eax,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_894:
	/* 0x894: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_899:
	/* 0x899: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_89d:
	/* 0x89d: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_8a3:
	/* 0x8a3: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8a6:
	/* 0x8a6: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_8aa:
	/* 0x8aa: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_8b0:
	/* 0x8b0: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8b3:
	/* 0x8b3: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_8b7:
	/* 0x8b7: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_8b9:
	/* 0x8b9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8bc:
	/* 0x8bc: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c0:
	/* 0x8c0: lea    ebx,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_8c4:
	/* 0x8c4: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8ca:
	/* 0x8ca: movzx  ebx,BYTE PTR [rsi+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 0, X86_WIDTH_8), 0ULL);
x86_l_8ce:
	/* 0x8ce: mov    BYTE PTR [rdi-0x3],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_8d1:
	/* 0x8d1: cmp    r10,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R12, X86_WIDTH_64);
x86_l_8d4:
	/* 0x8d4: je     925 <generic_fentry_filter_arg+0x925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_925;
	}
x86_l_8d6:
	/* 0x8d6: lea    ebx,[r11+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_8da:
	/* 0x8da: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8e0:
	/* 0x8e0: movzx  ebx,BYTE PTR [rsi+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 0, X86_WIDTH_8), 0ULL);
x86_l_8e4:
	/* 0x8e4: mov    BYTE PTR [rdi-0x2],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_8e7:
	/* 0x8e7: cmp    r8,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R12, X86_WIDTH_64);
x86_l_8ea:
	/* 0x8ea: je     925 <generic_fentry_filter_arg+0x925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_925;
	}
x86_l_8ec:
	/* 0x8ec: lea    ebx,[r9+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_8f0:
	/* 0x8f0: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8f6:
	/* 0x8f6: movzx  ebx,BYTE PTR [rsi+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 0, X86_WIDTH_8), 0ULL);
x86_l_8fa:
	/* 0x8fa: mov    BYTE PTR [rdi-0x1],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_8fd:
	/* 0x8fd: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_900:
	/* 0x900: je     925 <generic_fentry_filter_arg+0x925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_925;
	}
x86_l_902:
	/* 0x902: cmp    r12,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_906:
	/* 0x906: je     925 <generic_fentry_filter_arg+0x925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_925;
	}
x86_l_908:
	/* 0x908: lea    ebx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_90c:
	/* 0x90c: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_912:
	/* 0x912: movzx  ebx,BYTE PTR [rsi+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 0, X86_WIDTH_8), 0ULL);
x86_l_916:
	/* 0x916: mov    BYTE PTR [rdi],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_918:
	/* 0x918: add    r12,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_91c:
	/* 0x91c: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_920:
	/* 0x920: cmp    rcx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_923:
	/* 0x923: jne    8c0 <generic_fentry_filter_arg+0x8c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8c0;
	}
x86_l_925:
	/* 0x925: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_92a:
	/* 0x92a: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_92f:
	/* 0x92f: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_934:
	/* 0x934: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_936:
	/* 0x936: jmp    1000 <generic_fentry_filter_arg+0x1000> */
	return 4096ULL;
x86_l_93b:
	/* 0x93b: add    eax,0xfffffffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967293ULL);
x86_l_93e:
	/* 0x93e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_941:
	/* 0x941: jae    9ab <generic_fentry_filter_arg+0x9ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9ab;
	}
x86_l_943:
	/* 0x943: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_94b:
	/* 0x94b: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_951:
	/* 0x951: jbe    11e0 <generic_fentry_filter_arg+0x11e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4576ULL;
	}
x86_l_957:
	/* 0x957: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_95a:
	/* 0x95a: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_95f:
	/* 0x95f: jmp    1d32 <generic_fentry_filter_arg+0x1d32> */
	return 7474ULL;
x86_l_964:
	/* 0x964: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_967:
	/* 0x967: ja     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 264ULL;
	}
x86_l_96d:
	/* 0x96d: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_96f:
	/* 0x96f: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_974:
	/* 0x974: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_978:
	/* 0x978: jae    1125 <generic_fentry_filter_arg+0x1125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4389ULL;
	}
x86_l_97e:
	/* 0x97e: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_982:
	/* 0x982: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_985:
	/* 0x985: jle    16f9 <generic_fentry_filter_arg+0x16f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5881ULL;
	}
x86_l_98b:
	/* 0x98b: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_98e:
	/* 0x98e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_991:
	/* 0x991: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_995:
	/* 0x995: jae    1ebe <generic_fentry_filter_arg+0x1ebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7870ULL;
	}
x86_l_99b:
	/* 0x99b: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_99e:
	/* 0x99e: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_9a0:
	/* 0x9a0: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 670ULL;
	}
x86_l_9a6:
	/* 0x9a6: jmp    201b <generic_fentry_filter_arg+0x201b> */
	return 8219ULL;
x86_l_9ab:
	/* 0x9ab: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ae:
	/* 0x9ae: jmp    1d32 <generic_fentry_filter_arg+0x1d32> */
	return 7474ULL;
x86_l_9b3:
	/* 0x9b3: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9b8:
	/* 0x9b8: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9bc:
	/* 0x9bc: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9c0:
	/* 0x9c0: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_9c8:
	/* 0x9c8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9cd:
	/* 0x9cd: mov    rdi,QWORD PTR [rip+0x1c238] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_9d4:
	/* 0x9d4: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9d9:
	/* 0x9d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9db:
	/* 0x9db: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_9dd:
	/* 0x9dd: je     f5b <generic_fentry_filter_arg+0xf5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3931ULL;
	}
x86_l_9e3:
	/* 0x9e3: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_9e9:
	/* 0x9e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9ec:
	/* 0x9ec: je     1d23 <generic_fentry_filter_arg+0x1d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7459ULL;
	}
x86_l_9f2:
	/* 0x9f2: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9f7:
	/* 0x9f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9fc:
	/* 0x9fc: mov    rdi,QWORD PTR [rip+0x1c238] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_a03:
	/* 0xa03: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a08:
	/* 0xa08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0a:
	/* 0xa0a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a0d:
	/* 0xa0d: je     f5b <generic_fentry_filter_arg+0xf5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3931ULL;
	}
x86_l_a13:
	/* 0xa13: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_a16:
	/* 0xa16: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_a19:
	/* 0xa19: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_a1e:
	/* 0xa1e: cmovb  ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_a21:
	/* 0xa21: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_a24:
	/* 0xa24: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a26:
	/* 0xa26: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_a29:
	/* 0xa29: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_a2c:
	/* 0xa2c: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_a31:
	/* 0xa31: sub    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a34:
	/* 0xa34: lea    eax,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_a37:
	/* 0xa37: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a3c:
	/* 0xa3c: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_a40:
	/* 0xa40: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_a46:
	/* 0xa46: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a49:
	/* 0xa49: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_a4d:
	/* 0xa4d: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_a53:
	/* 0xa53: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a56:
	/* 0xa56: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_a5a:
	/* 0xa5a: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_a5c:
	/* 0xa5c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a5f:
	/* 0xa5f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a63:
	/* 0xa63: lea    ebx,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_a67:
	/* 0xa67: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a6d:
	/* 0xa6d: movzx  ebx,BYTE PTR [rsi+rbx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 0, X86_WIDTH_8), 4ULL);
x86_l_a72:
	/* 0xa72: mov    BYTE PTR [rdi-0x3],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_a75:
	/* 0xa75: cmp    r10,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R12, X86_WIDTH_64);
x86_l_a78:
	/* 0xa78: je     acc <generic_fentry_filter_arg+0xacc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_acc;
	}
x86_l_a7a:
	/* 0xa7a: lea    ebx,[r11+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_a7e:
	/* 0xa7e: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a84:
	/* 0xa84: movzx  ebx,BYTE PTR [rsi+rbx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 0, X86_WIDTH_8), 4ULL);
x86_l_a89:
	/* 0xa89: mov    BYTE PTR [rdi-0x2],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_a8c:
	/* 0xa8c: cmp    r8,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R12, X86_WIDTH_64);
x86_l_a8f:
	/* 0xa8f: je     acc <generic_fentry_filter_arg+0xacc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_acc;
	}
x86_l_a91:
	/* 0xa91: lea    ebx,[r9+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_a95:
	/* 0xa95: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a9b:
	/* 0xa9b: movzx  ebx,BYTE PTR [rsi+rbx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 0, X86_WIDTH_8), 4ULL);
x86_l_aa0:
	/* 0xaa0: mov    BYTE PTR [rdi-0x1],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_aa3:
	/* 0xaa3: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_aa6:
	/* 0xaa6: je     acc <generic_fentry_filter_arg+0xacc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_acc;
	}
x86_l_aa8:
	/* 0xaa8: cmp    r12,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_aac:
	/* 0xaac: je     acc <generic_fentry_filter_arg+0xacc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_acc;
	}
x86_l_aae:
	/* 0xaae: lea    ebx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_ab2:
	/* 0xab2: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ab8:
	/* 0xab8: movzx  ebx,BYTE PTR [rsi+rbx*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 0, X86_WIDTH_8), 4ULL);
x86_l_abd:
	/* 0xabd: mov    BYTE PTR [rdi],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_abf:
	/* 0xabf: add    r12,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_ac3:
	/* 0xac3: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_ac7:
	/* 0xac7: cmp    rcx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_aca:
	/* 0xaca: jne    a63 <generic_fentry_filter_arg+0xa63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a63;
	}
x86_l_acc:
	/* 0xacc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ad1:
	/* 0xad1: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ad6:
	/* 0xad6: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_adb:
	/* 0xadb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_add:
	/* 0xadd: jmp    b7f <generic_fentry_filter_arg+0xb7f> */
	goto x86_l_b7f;
x86_l_ae2:
	/* 0xae2: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ae7:
	/* 0xae7: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aeb:
	/* 0xaeb: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_aef:
	/* 0xaef: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_af7:
	/* 0xaf7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_afc:
	/* 0xafc: mov    rdi,QWORD PTR [rip+0x1c238] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_b03:
	/* 0xb03: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b08:
	/* 0xb08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0a:
	/* 0xb0a: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_b0c:
	/* 0xb0c: je     f5b <generic_fentry_filter_arg+0xf5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3931ULL;
	}
x86_l_b12:
	/* 0xb12: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_b18:
	/* 0xb18: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b1b:
	/* 0xb1b: je     1d23 <generic_fentry_filter_arg+0x1d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7459ULL;
	}
x86_l_b21:
	/* 0xb21: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_b24:
	/* 0xb24: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b29:
	/* 0xb29: mov    rdi,QWORD PTR [rip+0x1c238] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_b30:
	/* 0xb30: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b35:
	/* 0xb35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b37:
	/* 0xb37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b3a:
	/* 0xb3a: je     1d1b <generic_fentry_filter_arg+0x1d1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7451ULL;
	}
x86_l_b40:
	/* 0xb40: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_b43:
	/* 0xb43: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b47:
	/* 0xb47: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_b4b:
	/* 0xb4b: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_b51:
	/* 0xb51: mov    eax,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_b56:
	/* 0xb56: cmovae ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_b59:
	/* 0xb59: lea    eax,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_b60:
	/* 0xb60: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b62:
	/* 0xb62: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b65:
	/* 0xb65: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_b69:
	/* 0xb69: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b6e:
	/* 0xb6e: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_b70:
	/* 0xb70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b72:
	/* 0xb72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b77:
	/* 0xb77: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_b7a:
	/* 0xb7a: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_b7d:
	/* 0xb7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b7f:
	/* 0xb7f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b82:
	/* 0xb82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b85:
	/* 0xb85: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_b89:
	/* 0xb89: jmp    1d1e <generic_fentry_filter_arg+0x1d1e> */
	return 7454ULL;
x86_l_b8e:
	/* 0xb8e: lea    edx,[rax-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_b91:
	/* 0xb91: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_b94:
	/* 0xb94: jb     c39 <generic_fentry_filter_arg+0xc39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c39;
	}
x86_l_b9a:
	/* 0xb9a: jmp    108 <generic_fentry_filter_arg+0x108> */
	return 264ULL;
x86_l_b9f:
	/* 0xb9f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ba3:
	/* 0xba3: mov    ebp,DWORD PTR [rdx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ba6:
	/* 0xba6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_baa:
	/* 0xbaa: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_bad:
	/* 0xbad: jg     1243 <generic_fentry_filter_arg+0x1243> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4675ULL;
	}
x86_l_bb3:
	/* 0xbb3: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_bb6:
	/* 0xbb6: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bb9:
	/* 0xbb9: jb     1bbd <generic_fentry_filter_arg+0x1bbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7101ULL;
	}
x86_l_bbf:
	/* 0xbbf: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bc3:
	/* 0xbc3: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_bc6:
	/* 0xbc6: je     1b1f <generic_fentry_filter_arg+0x1b1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6943ULL;
	}
x86_l_bcc:
	/* 0xbcc: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_bd2:
	/* 0xbd2: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_bd5:
	/* 0xbd5: je     1268 <generic_fentry_filter_arg+0x1268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4712ULL;
	}
x86_l_bdb:
	/* 0xbdb: jmp    38d2 <generic_fentry_filter_arg+0x38d2> */
	return 14546ULL;
x86_l_be0:
	/* 0xbe0: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_be3:
	/* 0xbe3: je     1523 <generic_fentry_filter_arg+0x1523> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5411ULL;
	}
x86_l_be9:
	/* 0xbe9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bec:
	/* 0xbec: jne    23ea <generic_fentry_filter_arg+0x23ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9194ULL;
	}
x86_l_bf2:
	/* 0xbf2: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_bf5:
	/* 0xbf5: ja     23de <generic_fentry_filter_arg+0x23de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9182ULL;
	}
x86_l_bfb:
	/* 0xbfb: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_c00:
	/* 0xc00: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_c03:
	/* 0xc03: jae    23de <generic_fentry_filter_arg+0x23de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9182ULL;
	}
x86_l_c09:
	/* 0xc09: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c0d:
	/* 0xc0d: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c0f:
	/* 0xc0f: jl     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 697ULL;
	}
x86_l_c15:
	/* 0xc15: jmp    23ea <generic_fentry_filter_arg+0x23ea> */
	return 9194ULL;
x86_l_c1a:
	/* 0xc1a: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_c1d:
	/* 0xc1d: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_c23:
	/* 0xc23: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_c26:
	/* 0xc26: ja     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 264ULL;
	}
x86_l_c2c:
	/* 0xc2c: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_c2e:
	/* 0xc2e: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_c33:
	/* 0xc33: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_c37:
	/* 0xc37: jae    c60 <generic_fentry_filter_arg+0xc60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_c60;
	}
x86_l_c39:
	/* 0xc39: mov    rdx,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c3d:
	/* 0xc3d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c40:
	/* 0xc40: jle    c84 <generic_fentry_filter_arg+0xc84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c84;
	}
x86_l_c42:
	/* 0xc42: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_c45:
	/* 0xc45: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c48:
	/* 0xc48: jae    ef7 <generic_fentry_filter_arg+0xef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3831ULL;
	}
x86_l_c4e:
	/* 0xc4e: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c52:
	/* 0xc52: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c55:
	/* 0xc55: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 670ULL;
	}
x86_l_c5b:
	/* 0xc5b: jmp    1e1a <generic_fentry_filter_arg+0x1e1a> */
	return 7706ULL;
x86_l_c60:
	/* 0xc60: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_c65:
	/* 0xc65: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_c69:
	/* 0xc69: jb     cb6 <generic_fentry_filter_arg+0xcb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cb6;
	}
x86_l_c6b:
	/* 0xc6b: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_c75:
	/* 0xc75: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_c79:
	/* 0xc79: jb     f1e <generic_fentry_filter_arg+0xf1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3870ULL;
	}
x86_l_c7f:
	/* 0xc7f: jmp    108 <generic_fentry_filter_arg+0x108> */
	return 264ULL;
x86_l_c84:
	/* 0xc84: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c87:
	/* 0xc87: je     11c0 <generic_fentry_filter_arg+0x11c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4544ULL;
	}
x86_l_c8d:
	/* 0xc8d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c90:
	/* 0xc90: jne    1e1a <generic_fentry_filter_arg+0x1e1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7706ULL;
	}
x86_l_c96:
	/* 0xc96: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_c99:
	/* 0xc99: je     ca4 <generic_fentry_filter_arg+0xca4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ca4;
	}
x86_l_c9b:
	/* 0xc9b: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_c9e:
	/* 0xc9e: jne    1e0d <generic_fentry_filter_arg+0x1e0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7693ULL;
	}
x86_l_ca4:
	/* 0xca4: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca8:
	/* 0xca8: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cab:
	/* 0xcab: jl     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 697ULL;
	}
x86_l_cb1:
	/* 0xcb1: jmp    1e1a <generic_fentry_filter_arg+0x1e1a> */
	return 7706ULL;
x86_l_cb6:
	/* 0xcb6: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_cb9:
	/* 0xcb9: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_cbe:
	/* 0xcbe: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_cc2:
	/* 0xcc2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cc7:
	/* 0xcc7: mov    rdi,QWORD PTR [rip+0x1c238] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_cce:
	/* 0xcce: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cd3:
	/* 0xcd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd5:
	/* 0xcd5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cd8:
	/* 0xcd8: je     1cf4 <generic_fentry_filter_arg+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_cde:
	/* 0xcde: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce2:
	/* 0xce2: mov    rcx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce5:
	/* 0xce5: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cea:
	/* 0xcea: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cef:
	/* 0xcef: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_cf2:
	/* 0xcf2: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
	return 3319ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3319ULL: goto x86_l_cf7;
	case 3321ULL: goto x86_l_cf9;
	case 3325ULL: goto x86_l_cfd;
	case 3328ULL: goto x86_l_d00;
	case 3334ULL: goto x86_l_d06;
	case 3337ULL: goto x86_l_d09;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3350ULL: goto x86_l_d16;
	case 3356ULL: goto x86_l_d1c;
	case 3358ULL: goto x86_l_d1e;
	case 3362ULL: goto x86_l_d22;
	case 3367ULL: goto x86_l_d27;
	case 3370ULL: goto x86_l_d2a;
	case 3375ULL: goto x86_l_d2f;
	case 3379ULL: goto x86_l_d33;
	case 3384ULL: goto x86_l_d38;
	case 3391ULL: goto x86_l_d3f;
	case 3396ULL: goto x86_l_d44;
	case 3398ULL: goto x86_l_d46;
	case 3401ULL: goto x86_l_d49;
	case 3407ULL: goto x86_l_d4f;
	case 3411ULL: goto x86_l_d53;
	case 3413ULL: goto x86_l_d55;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3428ULL: goto x86_l_d64;
	case 3431ULL: goto x86_l_d67;
	case 3436ULL: goto x86_l_d6c;
	case 3440ULL: goto x86_l_d70;
	case 3445ULL: goto x86_l_d75;
	case 3449ULL: goto x86_l_d79;
	case 3454ULL: goto x86_l_d7e;
	case 3458ULL: goto x86_l_d82;
	case 3463ULL: goto x86_l_d87;
	case 3468ULL: goto x86_l_d8c;
	case 3470ULL: goto x86_l_d8e;
	case 3473ULL: goto x86_l_d91;
	case 3475ULL: goto x86_l_d93;
	case 3478ULL: goto x86_l_d96;
	case 3480ULL: goto x86_l_d98;
	case 3483ULL: goto x86_l_d9b;
	case 3486ULL: goto x86_l_d9e;
	case 3492ULL: goto x86_l_da4;
	case 3495ULL: goto x86_l_da7;
	case 3501ULL: goto x86_l_dad;
	case 3504ULL: goto x86_l_db0;
	case 3510ULL: goto x86_l_db6;
	case 3515ULL: goto x86_l_dbb;
	case 3518ULL: goto x86_l_dbe;
	case 3524ULL: goto x86_l_dc4;
	case 3527ULL: goto x86_l_dc7;
	case 3533ULL: goto x86_l_dcd;
	case 3536ULL: goto x86_l_dd0;
	case 3542ULL: goto x86_l_dd6;
	case 3548ULL: goto x86_l_ddc;
	case 3551ULL: goto x86_l_ddf;
	case 3557ULL: goto x86_l_de5;
	case 3562ULL: goto x86_l_dea;
	case 3567ULL: goto x86_l_def;
	case 3570ULL: goto x86_l_df2;
	case 3576ULL: goto x86_l_df8;
	case 3579ULL: goto x86_l_dfb;
	case 3585ULL: goto x86_l_e01;
	case 3591ULL: goto x86_l_e07;
	case 3594ULL: goto x86_l_e0a;
	case 3600ULL: goto x86_l_e10;
	case 3605ULL: goto x86_l_e15;
	case 3608ULL: goto x86_l_e18;
	case 3614ULL: goto x86_l_e1e;
	case 3620ULL: goto x86_l_e24;
	case 3623ULL: goto x86_l_e27;
	case 3629ULL: goto x86_l_e2d;
	case 3633ULL: goto x86_l_e31;
	case 3635ULL: goto x86_l_e33;
	case 3638ULL: goto x86_l_e36;
	case 3641ULL: goto x86_l_e39;
	case 3646ULL: goto x86_l_e3e;
	case 3650ULL: goto x86_l_e42;
	case 3655ULL: goto x86_l_e47;
	case 3662ULL: goto x86_l_e4e;
	case 3667ULL: goto x86_l_e53;
	case 3669ULL: goto x86_l_e55;
	case 3672ULL: goto x86_l_e58;
	case 3678ULL: goto x86_l_e5e;
	case 3680ULL: goto x86_l_e60;
	case 3683ULL: goto x86_l_e63;
	case 3688ULL: goto x86_l_e68;
	case 3690ULL: goto x86_l_e6a;
	case 3694ULL: goto x86_l_e6e;
	case 3696ULL: goto x86_l_e70;
	case 3698ULL: goto x86_l_e72;
	case 3701ULL: goto x86_l_e75;
	case 3704ULL: goto x86_l_e78;
	case 3707ULL: goto x86_l_e7b;
	case 3709ULL: goto x86_l_e7d;
	case 3711ULL: goto x86_l_e7f;
	case 3715ULL: goto x86_l_e83;
	case 3718ULL: goto x86_l_e86;
	case 3720ULL: goto x86_l_e88;
	case 3724ULL: goto x86_l_e8c;
	case 3726ULL: goto x86_l_e8e;
	case 3728ULL: goto x86_l_e90;
	case 3733ULL: goto x86_l_e95;
	case 3737ULL: goto x86_l_e99;
	case 3740ULL: goto x86_l_e9c;
	case 3744ULL: goto x86_l_ea0;
	case 3748ULL: goto x86_l_ea4;
	case 3752ULL: goto x86_l_ea8;
	case 3756ULL: goto x86_l_eac;
	case 3759ULL: goto x86_l_eaf;
	case 3763ULL: goto x86_l_eb3;
	case 3767ULL: goto x86_l_eb7;
	case 3771ULL: goto x86_l_ebb;
	case 3775ULL: goto x86_l_ebf;
	case 3777ULL: goto x86_l_ec1;
	case 3780ULL: goto x86_l_ec4;
	case 3783ULL: goto x86_l_ec7;
	case 3785ULL: goto x86_l_ec9;
	case 3787ULL: goto x86_l_ecb;
	case 3789ULL: goto x86_l_ecd;
	case 3795ULL: goto x86_l_ed3;
	case 3800ULL: goto x86_l_ed8;
	case 3804ULL: goto x86_l_edc;
	case 3806ULL: goto x86_l_ede;
	case 3810ULL: goto x86_l_ee2;
	case 3813ULL: goto x86_l_ee5;
	case 3817ULL: goto x86_l_ee9;
	case 3823ULL: goto x86_l_eef;
	case 3826ULL: goto x86_l_ef2;
	case 3831ULL: goto x86_l_ef7;
	case 3834ULL: goto x86_l_efa;
	case 3840ULL: goto x86_l_f00;
	case 3844ULL: goto x86_l_f04;
	case 3847ULL: goto x86_l_f07;
	case 3853ULL: goto x86_l_f0d;
	case 3858ULL: goto x86_l_f12;
	case 3861ULL: goto x86_l_f15;
	case 3864ULL: goto x86_l_f18;
	case 3870ULL: goto x86_l_f1e;
	case 3873ULL: goto x86_l_f21;
	case 3879ULL: goto x86_l_f27;
	case 3883ULL: goto x86_l_f2b;
	case 3887ULL: goto x86_l_f2f;
	case 3890ULL: goto x86_l_f32;
	case 3892ULL: goto x86_l_f34;
	case 3895ULL: goto x86_l_f37;
	case 3901ULL: goto x86_l_f3d;
	case 3905ULL: goto x86_l_f41;
	case 3908ULL: goto x86_l_f44;
	case 3911ULL: goto x86_l_f47;
	case 3917ULL: goto x86_l_f4d;
	case 3920ULL: goto x86_l_f50;
	case 3926ULL: goto x86_l_f56;
	case 3931ULL: goto x86_l_f5b;
	case 3934ULL: goto x86_l_f5e;
	case 3939ULL: goto x86_l_f63;
	case 3943ULL: goto x86_l_f67;
	case 3948ULL: goto x86_l_f6c;
	case 3952ULL: goto x86_l_f70;
	case 3956ULL: goto x86_l_f74;
	case 3964ULL: goto x86_l_f7c;
	case 3969ULL: goto x86_l_f81;
	case 3976ULL: goto x86_l_f88;
	case 3981ULL: goto x86_l_f8d;
	case 3983ULL: goto x86_l_f8f;
	case 3985ULL: goto x86_l_f91;
	case 3991ULL: goto x86_l_f97;
	case 3994ULL: goto x86_l_f9a;
	case 4000ULL: goto x86_l_fa0;
	case 4003ULL: goto x86_l_fa3;
	case 4009ULL: goto x86_l_fa9;
	case 4014ULL: goto x86_l_fae;
	case 4021ULL: goto x86_l_fb5;
	case 4026ULL: goto x86_l_fba;
	case 4028ULL: goto x86_l_fbc;
	case 4031ULL: goto x86_l_fbf;
	case 4037ULL: goto x86_l_fc5;
	case 4043ULL: goto x86_l_fcb;
	case 4048ULL: goto x86_l_fd0;
	case 4051ULL: goto x86_l_fd3;
	case 4058ULL: goto x86_l_fda;
	case 4060ULL: goto x86_l_fdc;
	case 4063ULL: goto x86_l_fdf;
	case 4067ULL: goto x86_l_fe3;
	case 4072ULL: goto x86_l_fe8;
	case 4074ULL: goto x86_l_fea;
	case 4078ULL: goto x86_l_fee;
	case 4081ULL: goto x86_l_ff1;
	case 4083ULL: goto x86_l_ff3;
	case 4088ULL: goto x86_l_ff8;
	case 4091ULL: goto x86_l_ffb;
	case 4094ULL: goto x86_l_ffe;
	case 4096ULL: goto x86_l_1000;
	case 4099ULL: goto x86_l_1003;
	case 4102ULL: goto x86_l_1006;
	case 4106ULL: goto x86_l_100a;
	case 4111ULL: goto x86_l_100f;
	case 4119ULL: goto x86_l_1017;
	case 4125ULL: goto x86_l_101d;
	case 4131ULL: goto x86_l_1023;
	case 4134ULL: goto x86_l_1026;
	case 4139ULL: goto x86_l_102b;
	case 4145ULL: goto x86_l_1031;
	case 4149ULL: goto x86_l_1035;
	case 4155ULL: goto x86_l_103b;
	case 4158ULL: goto x86_l_103e;
	case 4161ULL: goto x86_l_1041;
	case 4164ULL: goto x86_l_1044;
	case 4166ULL: goto x86_l_1046;
	case 4169ULL: goto x86_l_1049;
	case 4171ULL: goto x86_l_104b;
	case 4173ULL: goto x86_l_104d;
	case 4175ULL: goto x86_l_104f;
	case 4177ULL: goto x86_l_1051;
	case 4179ULL: goto x86_l_1053;
	case 4182ULL: goto x86_l_1056;
	case 4184ULL: goto x86_l_1058;
	case 4186ULL: goto x86_l_105a;
	case 4188ULL: goto x86_l_105c;
	case 4191ULL: goto x86_l_105f;
	case 4194ULL: goto x86_l_1062;
	case 4198ULL: goto x86_l_1066;
	case 4204ULL: goto x86_l_106c;
	case 4206ULL: goto x86_l_106e;
	case 4209ULL: goto x86_l_1071;
	case 4215ULL: goto x86_l_1077;
	case 4218ULL: goto x86_l_107a;
	case 4220ULL: goto x86_l_107c;
	case 4225ULL: goto x86_l_1081;
	case 4228ULL: goto x86_l_1084;
	case 4234ULL: goto x86_l_108a;
	case 4237ULL: goto x86_l_108d;
	case 4243ULL: goto x86_l_1093;
	case 4249ULL: goto x86_l_1099;
	case 4252ULL: goto x86_l_109c;
	case 4258ULL: goto x86_l_10a2;
	case 4263ULL: goto x86_l_10a7;
	case 4267ULL: goto x86_l_10ab;
	case 4271ULL: goto x86_l_10af;
	case 4274ULL: goto x86_l_10b2;
	case 4276ULL: goto x86_l_10b4;
	case 4279ULL: goto x86_l_10b7;
	case 4285ULL: goto x86_l_10bd;
	case 4289ULL: goto x86_l_10c1;
	case 4292ULL: goto x86_l_10c4;
	case 4295ULL: goto x86_l_10c7;
	case 4299ULL: goto x86_l_10cb;
	case 4302ULL: goto x86_l_10ce;
	case 4305ULL: goto x86_l_10d1;
	case 4310ULL: goto x86_l_10d6;
	case 4313ULL: goto x86_l_10d9;
	case 4319ULL: goto x86_l_10df;
	case 4323ULL: goto x86_l_10e3;
	case 4325ULL: goto x86_l_10e5;
	case 4331ULL: goto x86_l_10eb;
	case 4336ULL: goto x86_l_10f0;
	case 4341ULL: goto x86_l_10f5;
	case 4345ULL: goto x86_l_10f9;
	case 4351ULL: goto x86_l_10ff;
	case 4361ULL: goto x86_l_1109;
	case 4365ULL: goto x86_l_110d;
	case 4371ULL: goto x86_l_1113;
	case 4374ULL: goto x86_l_1116;
	case 4380ULL: goto x86_l_111c;
	case 4384ULL: goto x86_l_1120;
	case 4387ULL: goto x86_l_1123;
	case 4389ULL: goto x86_l_1125;
	case 4394ULL: goto x86_l_112a;
	case 4398ULL: goto x86_l_112e;
	case 4404ULL: goto x86_l_1134;
	case 4414ULL: goto x86_l_113e;
	case 4418ULL: goto x86_l_1142;
	case 4424ULL: goto x86_l_1148;
	case 4427ULL: goto x86_l_114b;
	case 4433ULL: goto x86_l_1151;
	case 4437ULL: goto x86_l_1155;
	case 4440ULL: goto x86_l_1158;
	case 4444ULL: goto x86_l_115c;
	case 4446ULL: goto x86_l_115e;
	case 4450ULL: goto x86_l_1162;
	case 4456ULL: goto x86_l_1168;
	case 4460ULL: goto x86_l_116c;
	case 4463ULL: goto x86_l_116f;
	case 4469ULL: goto x86_l_1175;
	case 4473ULL: goto x86_l_1179;
	case 4475ULL: goto x86_l_117b;
	case 4479ULL: goto x86_l_117f;
	case 4485ULL: goto x86_l_1185;
	case 4488ULL: goto x86_l_1188;
	case 4494ULL: goto x86_l_118e;
	case 4498ULL: goto x86_l_1192;
	case 4500ULL: goto x86_l_1194;
	case 4504ULL: goto x86_l_1198;
	case 4510ULL: goto x86_l_119e;
	case 4513ULL: goto x86_l_11a1;
	case 4519ULL: goto x86_l_11a7;
	case 4523ULL: goto x86_l_11ab;
	case 4529ULL: goto x86_l_11b1;
	case 4533ULL: goto x86_l_11b5;
	case 4539ULL: goto x86_l_11bb;
	case 4544ULL: goto x86_l_11c0;
	case 4547ULL: goto x86_l_11c3;
	case 4549ULL: goto x86_l_11c5;
	case 4552ULL: goto x86_l_11c8;
	case 4558ULL: goto x86_l_11ce;
	case 4562ULL: goto x86_l_11d2;
	case 4565ULL: goto x86_l_11d5;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4589ULL: goto x86_l_11ed;
	case 4595ULL: goto x86_l_11f3;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4608ULL: goto x86_l_1200;
	case 4611ULL: goto x86_l_1203;
	case 4614ULL: goto x86_l_1206;
	case 4616ULL: goto x86_l_1208;
	case 4619ULL: goto x86_l_120b;
	case 4621ULL: goto x86_l_120d;
	case 4623ULL: goto x86_l_120f;
	case 4625ULL: goto x86_l_1211;
	case 4627ULL: goto x86_l_1213;
	case 4629ULL: goto x86_l_1215;
	case 4632ULL: goto x86_l_1218;
	case 4634ULL: goto x86_l_121a;
	case 4636ULL: goto x86_l_121c;
	case 4638ULL: goto x86_l_121e;
	case 4641ULL: goto x86_l_1221;
	case 4644ULL: goto x86_l_1224;
	case 4648ULL: goto x86_l_1228;
	case 4654ULL: goto x86_l_122e;
	case 4656ULL: goto x86_l_1230;
	case 4659ULL: goto x86_l_1233;
	case 4665ULL: goto x86_l_1239;
	case 4668ULL: goto x86_l_123c;
	case 4670ULL: goto x86_l_123e;
	case 4675ULL: goto x86_l_1243;
	case 4678ULL: goto x86_l_1246;
	case 4682ULL: goto x86_l_124a;
	case 4688ULL: goto x86_l_1250;
	case 4691ULL: goto x86_l_1253;
	case 4697ULL: goto x86_l_1259;
	case 4703ULL: goto x86_l_125f;
	case 4706ULL: goto x86_l_1262;
	case 4712ULL: goto x86_l_1268;
	case 4717ULL: goto x86_l_126d;
	case 4721ULL: goto x86_l_1271;
	case 4725ULL: goto x86_l_1275;
	case 4733ULL: goto x86_l_127d;
	case 4738ULL: goto x86_l_1282;
	case 4745ULL: goto x86_l_1289;
	case 4750ULL: goto x86_l_128e;
	case 4752ULL: goto x86_l_1290;
	case 4754ULL: goto x86_l_1292;
	case 4760ULL: goto x86_l_1298;
	case 4763ULL: goto x86_l_129b;
	case 4769ULL: goto x86_l_12a1;
	case 4772ULL: goto x86_l_12a4;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4790ULL: goto x86_l_12b6;
	case 4795ULL: goto x86_l_12bb;
	case 4797ULL: goto x86_l_12bd;
	case 4800ULL: goto x86_l_12c0;
	case 4806ULL: goto x86_l_12c6;
	case 4809ULL: goto x86_l_12c9;
	case 4814ULL: goto x86_l_12ce;
	case 4817ULL: goto x86_l_12d1;
	case 4822ULL: goto x86_l_12d6;
	case 4825ULL: goto x86_l_12d9;
	case 4828ULL: goto x86_l_12dc;
	case 4830ULL: goto x86_l_12de;
	case 4833ULL: goto x86_l_12e1;
	case 4836ULL: goto x86_l_12e4;
	case 4841ULL: goto x86_l_12e9;
	case 4844ULL: goto x86_l_12ec;
	case 4847ULL: goto x86_l_12ef;
	case 4852ULL: goto x86_l_12f4;
	case 4856ULL: goto x86_l_12f8;
	case 4862ULL: goto x86_l_12fe;
	case 4865ULL: goto x86_l_1301;
	default: return 0xffffffffffffffffULL;
	}
x86_l_cf7:
	/* 0xcf7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_cf9:
	/* 0xcf9: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cfd:
	/* 0xcfd: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_d00:
	/* 0xd00: je     181a <generic_fentry_filter_arg+0x181a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6170ULL;
	}
x86_l_d06:
	/* 0xd06: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_d09:
	/* 0xd09: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d0e:
	/* 0xd0e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d13:
	/* 0xd13: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_d16:
	/* 0xd16: je     1932 <generic_fentry_filter_arg+0x1932> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6450ULL;
	}
x86_l_d1c:
	/* 0xd1c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d1e:
	/* 0xd1e: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_d22:
	/* 0xd22: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_d27:
	/* 0xd27: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_d2a:
	/* 0xd2a: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_d2f:
	/* 0xd2f: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d33:
	/* 0xd33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d38:
	/* 0xd38: mov    rdi,QWORD PTR [rip+0x1c238] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_d3f:
	/* 0xd3f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d44:
	/* 0xd44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d46:
	/* 0xd46: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d49:
	/* 0xd49: je     1cf4 <generic_fentry_filter_arg+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_d4f:
	/* 0xd4f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d53:
	/* 0xd53: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d55:
	/* 0xd55: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d5a:
	/* 0xd5a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d5f:
	/* 0xd5f: jmp    17aa <generic_fentry_filter_arg+0x17aa> */
	return 6058ULL;
x86_l_d64:
	/* 0xd64: movzx  edx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d67:
	/* 0xd67: mov    WORD PTR [rsp+0x76],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_d6c:
	/* 0xd6c: movzx  edx,WORD PTR [rsi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_d70:
	/* 0xd70: mov    WORD PTR [rsp+0x70],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d75:
	/* 0xd75: mov    rdx,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d79:
	/* 0xd79: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d7e:
	/* 0xd7e: mov    rdx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d82:
	/* 0xd82: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d87:
	/* 0xd87: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d8c:
	/* 0xd8c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d8e:
	/* 0xd8e: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_d91:
	/* 0xd91: jle    dbb <generic_fentry_filter_arg+0xdbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_dbb;
	}
x86_l_d93:
	/* 0xd93: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_d96:
	/* 0xd96: jg     def <generic_fentry_filter_arg+0xdef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_def;
	}
x86_l_d98:
	/* 0xd98: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_d9b:
	/* 0xd9b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d9e:
	/* 0xd9e: jb     1403 <generic_fentry_filter_arg+0x1403> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5123ULL;
	}
x86_l_da4:
	/* 0xda4: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_da7:
	/* 0xda7: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_dad:
	/* 0xdad: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_db0:
	/* 0xdb0: jb     13fd <generic_fentry_filter_arg+0x13fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5117ULL;
	}
x86_l_db6:
	/* 0xdb6: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_dbb:
	/* 0xdbb: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_dbe:
	/* 0xdbe: jle    1081 <generic_fentry_filter_arg+0x1081> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1081;
	}
x86_l_dc4:
	/* 0xdc4: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_dc7:
	/* 0xdc7: jg     13e9 <generic_fentry_filter_arg+0x13e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5097ULL;
	}
x86_l_dcd:
	/* 0xdcd: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_dd0:
	/* 0xdd0: je     13fd <generic_fentry_filter_arg+0x13fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5117ULL;
	}
x86_l_dd6:
	/* 0xdd6: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_ddc:
	/* 0xddc: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_ddf:
	/* 0xddf: jne    2a8 <generic_fentry_filter_arg+0x2a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 680ULL;
	}
x86_l_de5:
	/* 0xde5: movzx  r12d,WORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_dea:
	/* 0xdea: jmp    1c7f <generic_fentry_filter_arg+0x1c7f> */
	return 7295ULL;
x86_l_def:
	/* 0xdef: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_df2:
	/* 0xdf2: jg     1445 <generic_fentry_filter_arg+0x1445> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5189ULL;
	}
x86_l_df8:
	/* 0xdf8: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_dfb:
	/* 0xdfb: je     1480 <generic_fentry_filter_arg+0x1480> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5248ULL;
	}
x86_l_e01:
	/* 0xe01: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_e07:
	/* 0xe07: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_e0a:
	/* 0xe0a: je     1476 <generic_fentry_filter_arg+0x1476> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5238ULL;
	}
x86_l_e10:
	/* 0xe10: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_e15:
	/* 0xe15: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_e18:
	/* 0xe18: je     154b <generic_fentry_filter_arg+0x154b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5451ULL;
	}
x86_l_e1e:
	/* 0xe1e: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_e24:
	/* 0xe24: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_e27:
	/* 0xe27: jne    35bf <generic_fentry_filter_arg+0x35bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13759ULL;
	}
x86_l_e2d:
	/* 0xe2d: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e31:
	/* 0xe31: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e33:
	/* 0xe33: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e36:
	/* 0xe36: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_e39:
	/* 0xe39: mov    eax,DWORD PTR [r13+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_e3e:
	/* 0xe3e: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e42:
	/* 0xe42: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e47:
	/* 0xe47: mov    rdi,QWORD PTR [rip+0x1c238] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_e4e:
	/* 0xe4e: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e53:
	/* 0xe53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e55:
	/* 0xe55: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e58:
	/* 0xe58: je     2339 <generic_fentry_filter_arg+0x2339> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9017ULL;
	}
x86_l_e5e:
	/* 0xe5e: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_e60:
	/* 0xe60: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_e63:
	/* 0xe63: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e68:
	/* 0xe68: je     ed3 <generic_fentry_filter_arg+0xed3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ed3;
	}
x86_l_e6a:
	/* 0xe6a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6e:
	/* 0xe6e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e70:
	/* 0xe70: jmp    e7d <generic_fentry_filter_arg+0xe7d> */
	goto x86_l_e7d;
x86_l_e72:
	/* 0xe72: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e75:
	/* 0xe75: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e78:
	/* 0xe78: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_e7b:
	/* 0xe7b: je     ed3 <generic_fentry_filter_arg+0xed3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ed3;
	}
x86_l_e7d:
	/* 0xe7d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e7f:
	/* 0xe7f: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_e83:
	/* 0xe83: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_e86:
	/* 0xe86: jae    e72 <generic_fentry_filter_arg+0xe72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e72;
	}
x86_l_e88:
	/* 0xe88: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_e8c:
	/* 0xe8c: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_e8e:
	/* 0xe8e: je     ecb <generic_fentry_filter_arg+0xecb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ecb;
	}
x86_l_e90:
	/* 0xe90: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_e95:
	/* 0xe95: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_e99:
	/* 0xe99: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_e9c:
	/* 0xe9c: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_ea0:
	/* 0xea0: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_ea4:
	/* 0xea4: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_ea8:
	/* 0xea8: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_eac:
	/* 0xeac: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_eaf:
	/* 0xeaf: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_eb3:
	/* 0xeb3: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_eb7:
	/* 0xeb7: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_ebb:
	/* 0xebb: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_ebf:
	/* 0xebf: ja     e72 <generic_fentry_filter_arg+0xe72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e72;
	}
x86_l_ec1:
	/* 0xec1: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ec4:
	/* 0xec4: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_ec7:
	/* 0xec7: je     e7f <generic_fentry_filter_arg+0xe7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e7f;
	}
x86_l_ec9:
	/* 0xec9: jmp    e72 <generic_fentry_filter_arg+0xe72> */
	goto x86_l_e72;
x86_l_ecb:
	/* 0xecb: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_ecd:
	/* 0xecd: jns    26bd <generic_fentry_filter_arg+0x26bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9917ULL;
	}
x86_l_ed3:
	/* 0xed3: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ed8:
	/* 0xed8: cmp    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_edc:
	/* 0xedc: jae    eef <generic_fentry_filter_arg+0xeef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_eef;
	}
x86_l_ede:
	/* 0xede: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_ee2:
	/* 0xee2: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ee5:
	/* 0xee5: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_ee9:
	/* 0xee9: jne    e36 <generic_fentry_filter_arg+0xe36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e36;
	}
x86_l_eef:
	/* 0xeef: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ef2:
	/* 0xef2: jmp    26c3 <generic_fentry_filter_arg+0x26c3> */
	return 9923ULL;
x86_l_ef7:
	/* 0xef7: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_efa:
	/* 0xefa: jne    1e1a <generic_fentry_filter_arg+0x1e1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7706ULL;
	}
x86_l_f00:
	/* 0xf00: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f04:
	/* 0xf04: test   QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f07:
	/* 0xf07: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_f0d:
	/* 0xf0d: jmp    1e1a <generic_fentry_filter_arg+0x1e1a> */
	return 7706ULL;
x86_l_f12:
	/* 0xf12: lea    edx,[rax-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_f15:
	/* 0xf15: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_f18:
	/* 0xf18: jae    1951 <generic_fentry_filter_arg+0x1951> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6481ULL;
	}
x86_l_f1e:
	/* 0xf1e: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_f21:
	/* 0xf21: jne    10a7 <generic_fentry_filter_arg+0x10a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10a7;
	}
x86_l_f27:
	/* 0xf27: mov    rsi,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f2b:
	/* 0xf2b: mov    rdx,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f2f:
	/* 0xf2f: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f32:
	/* 0xf32: je     f3d <generic_fentry_filter_arg+0xf3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f3d;
	}
x86_l_f34:
	/* 0xf34: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_f37:
	/* 0xf37: jne    1bd9 <generic_fentry_filter_arg+0x1bd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7129ULL;
	}
x86_l_f3d:
	/* 0xf3d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f41:
	/* 0xf41: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f44:
	/* 0xf44: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f47:
	/* 0xf47: jg     1bee <generic_fentry_filter_arg+0x1bee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7150ULL;
	}
x86_l_f4d:
	/* 0xf4d: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_f50:
	/* 0xf50: jle    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 697ULL;
	}
x86_l_f56:
	/* 0xf56: jmp    1bee <generic_fentry_filter_arg+0x1bee> */
	return 7150ULL;
x86_l_f5b:
	/* 0xf5b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f5e:
	/* 0xf5e: jmp    1d23 <generic_fentry_filter_arg+0x1d23> */
	return 7459ULL;
x86_l_f63:
	/* 0xf63: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f67:
	/* 0xf67: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f6c:
	/* 0xf6c: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f70:
	/* 0xf70: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f74:
	/* 0xf74: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_f7c:
	/* 0xf7c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f81:
	/* 0xf81: mov    rdi,QWORD PTR [rip+0x1c241] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_f88:
	/* 0xf88: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f8d:
	/* 0xf8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8f:
	/* 0xf8f: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_f91:
	/* 0xf91: je     16a4 <generic_fentry_filter_arg+0x16a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5796ULL;
	}
x86_l_f97:
	/* 0xf97: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_f9a:
	/* 0xf9a: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_fa0:
	/* 0xfa0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fa3:
	/* 0xfa3: je     16a7 <generic_fentry_filter_arg+0x16a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5799ULL;
	}
x86_l_fa9:
	/* 0xfa9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fae:
	/* 0xfae: mov    rdi,QWORD PTR [rip+0x1c241] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_fb5:
	/* 0xfb5: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fba:
	/* 0xfba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fbc:
	/* 0xfbc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fbf:
	/* 0xfbf: je     16a4 <generic_fentry_filter_arg+0x16a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5796ULL;
	}
x86_l_fc5:
	/* 0xfc5: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_fcb:
	/* 0xfcb: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_fd0:
	/* 0xfd0: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_fd3:
	/* 0xfd3: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_fda:
	/* 0xfda: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fdc:
	/* 0xfdc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_fdf:
	/* 0xfdf: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_fe3:
	/* 0xfe3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_fe8:
	/* 0xfe8: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_fea:
	/* 0xfea: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fee:
	/* 0xfee: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ff1:
	/* 0xff1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_ff3:
	/* 0xff3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ff8:
	/* 0xff8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ffb:
	/* 0xffb: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_ffe:
	/* 0xffe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1000:
	/* 0x1000: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1003:
	/* 0x1003: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1006:
	/* 0x1006: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_100a:
	/* 0x100a: jmp    16a7 <generic_fentry_filter_arg+0x16a7> */
	return 5799ULL;
x86_l_100f:
	/* 0x100f: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1017:
	/* 0x1017: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_101d:
	/* 0x101d: ja     2c1f <generic_fentry_filter_arg+0x2c1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11295ULL;
	}
x86_l_1023:
	/* 0x1023: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1026:
	/* 0x1026: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_102b:
	/* 0x102b: ja     1d97 <generic_fentry_filter_arg+0x1d97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7575ULL;
	}
x86_l_1031:
	/* 0x1031: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1035:
	/* 0x1035: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_103b:
	/* 0x103b: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_103e:
	/* 0x103e: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1041:
	/* 0x1041: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1044:
	/* 0x1044: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1046:
	/* 0x1046: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1049:
	/* 0x1049: je     1053 <generic_fentry_filter_arg+0x1053> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1053;
	}
x86_l_104b:
	/* 0x104b: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_104d:
	/* 0x104d: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_104f:
	/* 0x104f: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1051:
	/* 0x1051: je     106e <generic_fentry_filter_arg+0x106e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106e;
	}
x86_l_1053:
	/* 0x1053: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1056:
	/* 0x1056: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1058:
	/* 0x1058: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_105a:
	/* 0x105a: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_105c:
	/* 0x105c: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_105f:
	/* 0x105f: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1062:
	/* 0x1062: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1066:
	/* 0x1066: ja     1dce <generic_fentry_filter_arg+0x1dce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7630ULL;
	}
x86_l_106c:
	/* 0x106c: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_106e:
	/* 0x106e: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1071:
	/* 0x1071: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1077:
	/* 0x1077: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_107a:
	/* 0x107a: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_107c:
	/* 0x107c: jmp    2b53 <generic_fentry_filter_arg+0x2b53> */
	return 11091ULL;
x86_l_1081:
	/* 0x1081: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1084:
	/* 0x1084: je     1480 <generic_fentry_filter_arg+0x1480> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5248ULL;
	}
x86_l_108a:
	/* 0x108a: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_108d:
	/* 0x108d: je     1476 <generic_fentry_filter_arg+0x1476> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5238ULL;
	}
x86_l_1093:
	/* 0x1093: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_1099:
	/* 0x1099: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_109c:
	/* 0x109c: je     1403 <generic_fentry_filter_arg+0x1403> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5123ULL;
	}
x86_l_10a2:
	/* 0x10a2: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_10a7:
	/* 0x10a7: mov    rsi,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10ab:
	/* 0x10ab: mov    rax,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10af:
	/* 0x10af: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_10b2:
	/* 0x10b2: je     10bd <generic_fentry_filter_arg+0x10bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10bd;
	}
x86_l_10b4:
	/* 0x10b4: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_10b7:
	/* 0x10b7: jne    1c2d <generic_fentry_filter_arg+0x1c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7213ULL;
	}
x86_l_10bd:
	/* 0x10bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c1:
	/* 0x10c1: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c4:
	/* 0x10c4: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_10c7:
	/* 0x10c7: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_10cb:
	/* 0x10cb: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_10ce:
	/* 0x10ce: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_10d1:
	/* 0x10d1: jmp    1c41 <generic_fentry_filter_arg+0x1c41> */
	return 7233ULL;
x86_l_10d6:
	/* 0x10d6: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_10d9:
	/* 0x10d9: jne    23ea <generic_fentry_filter_arg+0x23ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9194ULL;
	}
x86_l_10df:
	/* 0x10df: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10e3:
	/* 0x10e3: test   DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10e5:
	/* 0x10e5: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_10eb:
	/* 0x10eb: jmp    23ea <generic_fentry_filter_arg+0x23ea> */
	return 9194ULL;
x86_l_10f0:
	/* 0x10f0: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_10f5:
	/* 0x10f5: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_10f9:
	/* 0x10f9: jb     1736 <generic_fentry_filter_arg+0x1736> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5942ULL;
	}
x86_l_10ff:
	/* 0x10ff: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_1109:
	/* 0x1109: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_110d:
	/* 0x110d: jae    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 264ULL;
	}
x86_l_1113:
	/* 0x1113: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_1116:
	/* 0x1116: jne    1f17 <generic_fentry_filter_arg+0x1f17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7959ULL;
	}
x86_l_111c:
	/* 0x111c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1120:
	/* 0x1120: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1123:
	/* 0x1123: jmp    1158 <generic_fentry_filter_arg+0x1158> */
	goto x86_l_1158;
x86_l_1125:
	/* 0x1125: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_112a:
	/* 0x112a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_112e:
	/* 0x112e: jb     1771 <generic_fentry_filter_arg+0x1771> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6001ULL;
	}
x86_l_1134:
	/* 0x1134: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_113e:
	/* 0x113e: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1142:
	/* 0x1142: jae    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 264ULL;
	}
x86_l_1148:
	/* 0x1148: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_114b:
	/* 0x114b: jne    1f24 <generic_fentry_filter_arg+0x1f24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7972ULL;
	}
x86_l_1151:
	/* 0x1151: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1155:
	/* 0x1155: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1158:
	/* 0x1158: cmp    DWORD PTR [r13+0x10],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_115c:
	/* 0x115c: ja     1168 <generic_fentry_filter_arg+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1168;
	}
x86_l_115e:
	/* 0x115e: cmp    DWORD PTR [r13+0x14],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1162:
	/* 0x1162: jae    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 697ULL;
	}
x86_l_1168:
	/* 0x1168: mov    ecx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_116c:
	/* 0x116c: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_116f:
	/* 0x116f: jb     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 264ULL;
	}
x86_l_1175:
	/* 0x1175: cmp    DWORD PTR [r13+0x18],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1179:
	/* 0x1179: ja     1185 <generic_fentry_filter_arg+0x1185> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1185;
	}
x86_l_117b:
	/* 0x117b: cmp    DWORD PTR [r13+0x1c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_117f:
	/* 0x117f: jae    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 697ULL;
	}
x86_l_1185:
	/* 0x1185: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_1188:
	/* 0x1188: jb     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 264ULL;
	}
x86_l_118e:
	/* 0x118e: cmp    DWORD PTR [r13+0x20],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1192:
	/* 0x1192: ja     119e <generic_fentry_filter_arg+0x119e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_119e;
	}
x86_l_1194:
	/* 0x1194: cmp    DWORD PTR [r13+0x24],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1198:
	/* 0x1198: jae    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 697ULL;
	}
x86_l_119e:
	/* 0x119e: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_11a1:
	/* 0x11a1: jb     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 264ULL;
	}
x86_l_11a7:
	/* 0x11a7: cmp    DWORD PTR [r13+0x28],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11ab:
	/* 0x11ab: ja     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 264ULL;
	}
x86_l_11b1:
	/* 0x11b1: cmp    DWORD PTR [r13+0x2c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_11b5:
	/* 0x11b5: jae    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 697ULL;
	}
x86_l_11bb:
	/* 0x11bb: jmp    108 <generic_fentry_filter_arg+0x108> */
	return 264ULL;
x86_l_11c0:
	/* 0x11c0: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_11c3:
	/* 0x11c3: je     11ce <generic_fentry_filter_arg+0x11ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11ce;
	}
x86_l_11c5:
	/* 0x11c5: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_11c8:
	/* 0x11c8: jne    1dfe <generic_fentry_filter_arg+0x1dfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7678ULL;
	}
x86_l_11ce:
	/* 0x11ce: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11d2:
	/* 0x11d2: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11d5:
	/* 0x11d5: jg     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 697ULL;
	}
x86_l_11db:
	/* 0x11db: jmp    1e1a <generic_fentry_filter_arg+0x1e1a> */
	return 7706ULL;
x86_l_11e0:
	/* 0x11e0: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11e3:
	/* 0x11e3: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_11e8:
	/* 0x11e8: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ed:
	/* 0x11ed: ja     1836 <generic_fentry_filter_arg+0x1836> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6198ULL;
	}
x86_l_11f3:
	/* 0x11f3: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11f7:
	/* 0x11f7: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_11fd:
	/* 0x11fd: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1200:
	/* 0x1200: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1203:
	/* 0x1203: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1206:
	/* 0x1206: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1208:
	/* 0x1208: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_120b:
	/* 0x120b: je     1215 <generic_fentry_filter_arg+0x1215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1215;
	}
x86_l_120d:
	/* 0x120d: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_120f:
	/* 0x120f: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1211:
	/* 0x1211: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1213:
	/* 0x1213: je     1230 <generic_fentry_filter_arg+0x1230> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1230;
	}
x86_l_1215:
	/* 0x1215: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1218:
	/* 0x1218: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_121a:
	/* 0x121a: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_121c:
	/* 0x121c: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_121e:
	/* 0x121e: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1221:
	/* 0x1221: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1224:
	/* 0x1224: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1228:
	/* 0x1228: ja     186d <generic_fentry_filter_arg+0x186d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6253ULL;
	}
x86_l_122e:
	/* 0x122e: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1230:
	/* 0x1230: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1233:
	/* 0x1233: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1239:
	/* 0x1239: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_123c:
	/* 0x123c: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_123e:
	/* 0x123e: jmp    2501 <generic_fentry_filter_arg+0x2501> */
	return 9473ULL;
x86_l_1243:
	/* 0x1243: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1246:
	/* 0x1246: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_124a:
	/* 0x124a: jg     199c <generic_fentry_filter_arg+0x199c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6556ULL;
	}
x86_l_1250:
	/* 0x1250: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1253:
	/* 0x1253: je     1b1f <generic_fentry_filter_arg+0x1b1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6943ULL;
	}
x86_l_1259:
	/* 0x1259: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_125f:
	/* 0x125f: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1262:
	/* 0x1262: jne    38d2 <generic_fentry_filter_arg+0x38d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14546ULL;
	}
x86_l_1268:
	/* 0x1268: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_126d:
	/* 0x126d: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1271:
	/* 0x1271: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1275:
	/* 0x1275: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_127d:
	/* 0x127d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1282:
	/* 0x1282: mov    rdi,QWORD PTR [rip+0x1c241] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_1289:
	/* 0x1289: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_128e:
	/* 0x128e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1290:
	/* 0x1290: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1292:
	/* 0x1292: je     38c0 <generic_fentry_filter_arg+0x38c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14528ULL;
	}
x86_l_1298:
	/* 0x1298: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_129b:
	/* 0x129b: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_12a1:
	/* 0x12a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12a4:
	/* 0x12a4: je     38c3 <generic_fentry_filter_arg+0x38c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14531ULL;
	}
x86_l_12aa:
	/* 0x12aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12af:
	/* 0x12af: mov    rdi,QWORD PTR [rip+0x1c241] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_12b6:
	/* 0x12b6: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12bb:
	/* 0x12bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12bd:
	/* 0x12bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12c0:
	/* 0x12c0: je     38c0 <generic_fentry_filter_arg+0x38c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14528ULL;
	}
x86_l_12c6:
	/* 0x12c6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12c9:
	/* 0x12c9: mov    QWORD PTR [rsp+0x28],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12ce:
	/* 0x12ce: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_12d1:
	/* 0x12d1: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_12d6:
	/* 0x12d6: cmovb  ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_12d9:
	/* 0x12d9: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_12dc:
	/* 0x12dc: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12de:
	/* 0x12de: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_12e1:
	/* 0x12e1: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_12e4:
	/* 0x12e4: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_12e9:
	/* 0x12e9: sub    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_12ec:
	/* 0x12ec: lea    eax,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_12ef:
	/* 0x12ef: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12f4:
	/* 0x12f4: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_12f8:
	/* 0x12f8: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_12fe:
	/* 0x12fe: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1301:
	/* 0x1301: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
	return 4869ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4869ULL: goto x86_l_1305;
	case 4875ULL: goto x86_l_130b;
	case 4878ULL: goto x86_l_130e;
	case 4882ULL: goto x86_l_1312;
	case 4884ULL: goto x86_l_1314;
	case 4887ULL: goto x86_l_1317;
	case 4891ULL: goto x86_l_131b;
	case 4895ULL: goto x86_l_131f;
	case 4901ULL: goto x86_l_1325;
	case 4905ULL: goto x86_l_1329;
	case 4908ULL: goto x86_l_132c;
	case 4911ULL: goto x86_l_132f;
	case 4913ULL: goto x86_l_1331;
	case 4917ULL: goto x86_l_1335;
	case 4923ULL: goto x86_l_133b;
	case 4927ULL: goto x86_l_133f;
	case 4930ULL: goto x86_l_1342;
	case 4933ULL: goto x86_l_1345;
	case 4935ULL: goto x86_l_1347;
	case 4939ULL: goto x86_l_134b;
	case 4945ULL: goto x86_l_1351;
	case 4949ULL: goto x86_l_1355;
	case 4952ULL: goto x86_l_1358;
	case 4955ULL: goto x86_l_135b;
	case 4957ULL: goto x86_l_135d;
	case 4961ULL: goto x86_l_1361;
	case 4963ULL: goto x86_l_1363;
	case 4967ULL: goto x86_l_1367;
	case 4973ULL: goto x86_l_136d;
	case 4977ULL: goto x86_l_1371;
	case 4979ULL: goto x86_l_1373;
	case 4983ULL: goto x86_l_1377;
	case 4987ULL: goto x86_l_137b;
	case 4990ULL: goto x86_l_137e;
	case 4992ULL: goto x86_l_1380;
	case 4997ULL: goto x86_l_1385;
	case 5002ULL: goto x86_l_138a;
	case 5007ULL: goto x86_l_138f;
	case 5012ULL: goto x86_l_1394;
	case 5016ULL: goto x86_l_1398;
	case 5020ULL: goto x86_l_139c;
	case 5023ULL: goto x86_l_139f;
	case 5029ULL: goto x86_l_13a5;
	case 5034ULL: goto x86_l_13aa;
	case 5037ULL: goto x86_l_13ad;
	case 5043ULL: goto x86_l_13b3;
	case 5047ULL: goto x86_l_13b7;
	case 5049ULL: goto x86_l_13b9;
	case 5051ULL: goto x86_l_13bb;
	case 5055ULL: goto x86_l_13bf;
	case 5057ULL: goto x86_l_13c1;
	case 5060ULL: goto x86_l_13c4;
	case 5065ULL: goto x86_l_13c9;
	case 5068ULL: goto x86_l_13cc;
	case 5074ULL: goto x86_l_13d2;
	case 5079ULL: goto x86_l_13d7;
	case 5083ULL: goto x86_l_13db;
	case 5086ULL: goto x86_l_13de;
	case 5092ULL: goto x86_l_13e4;
	case 5097ULL: goto x86_l_13e9;
	case 5100ULL: goto x86_l_13ec;
	case 5102ULL: goto x86_l_13ee;
	case 5108ULL: goto x86_l_13f4;
	case 5111ULL: goto x86_l_13f7;
	case 5117ULL: goto x86_l_13fd;
	case 5121ULL: goto x86_l_1401;
	case 5123ULL: goto x86_l_1403;
	case 5127ULL: goto x86_l_1407;
	case 5129ULL: goto x86_l_1409;
	case 5131ULL: goto x86_l_140b;
	case 5134ULL: goto x86_l_140e;
	case 5137ULL: goto x86_l_1411;
	case 5140ULL: goto x86_l_1414;
	case 5146ULL: goto x86_l_141a;
	case 5149ULL: goto x86_l_141d;
	case 5152ULL: goto x86_l_1420;
	case 5158ULL: goto x86_l_1426;
	case 5161ULL: goto x86_l_1429;
	case 5164ULL: goto x86_l_142c;
	case 5169ULL: goto x86_l_1431;
	case 5175ULL: goto x86_l_1437;
	case 5178ULL: goto x86_l_143a;
	case 5184ULL: goto x86_l_1440;
	case 5189ULL: goto x86_l_1445;
	case 5192ULL: goto x86_l_1448;
	case 5198ULL: goto x86_l_144e;
	case 5204ULL: goto x86_l_1454;
	case 5207ULL: goto x86_l_1457;
	case 5213ULL: goto x86_l_145d;
	case 5216ULL: goto x86_l_1460;
	case 5222ULL: goto x86_l_1466;
	case 5225ULL: goto x86_l_1469;
	case 5231ULL: goto x86_l_146f;
	case 5233ULL: goto x86_l_1471;
	case 5238ULL: goto x86_l_1476;
	case 5242ULL: goto x86_l_147a;
	case 5246ULL: goto x86_l_147e;
	case 5248ULL: goto x86_l_1480;
	case 5251ULL: goto x86_l_1483;
	case 5255ULL: goto x86_l_1487;
	case 5258ULL: goto x86_l_148a;
	case 5262ULL: goto x86_l_148e;
	case 5264ULL: goto x86_l_1490;
	case 5267ULL: goto x86_l_1493;
	case 5270ULL: goto x86_l_1496;
	case 5272ULL: goto x86_l_1498;
	case 5275ULL: goto x86_l_149b;
	case 5281ULL: goto x86_l_14a1;
	case 5286ULL: goto x86_l_14a6;
	case 5289ULL: goto x86_l_14a9;
	case 5295ULL: goto x86_l_14af;
	case 5300ULL: goto x86_l_14b4;
	case 5303ULL: goto x86_l_14b7;
	case 5309ULL: goto x86_l_14bd;
	case 5314ULL: goto x86_l_14c2;
	case 5317ULL: goto x86_l_14c5;
	case 5323ULL: goto x86_l_14cb;
	case 5327ULL: goto x86_l_14cf;
	case 5330ULL: goto x86_l_14d2;
	case 5336ULL: goto x86_l_14d8;
	case 5339ULL: goto x86_l_14db;
	case 5345ULL: goto x86_l_14e1;
	case 5348ULL: goto x86_l_14e4;
	case 5353ULL: goto x86_l_14e9;
	case 5357ULL: goto x86_l_14ed;
	case 5361ULL: goto x86_l_14f1;
	case 5366ULL: goto x86_l_14f6;
	case 5373ULL: goto x86_l_14fd;
	case 5378ULL: goto x86_l_1502;
	case 5380ULL: goto x86_l_1504;
	case 5383ULL: goto x86_l_1507;
	case 5388ULL: goto x86_l_150c;
	case 5394ULL: goto x86_l_1512;
	case 5402ULL: goto x86_l_151a;
	case 5406ULL: goto x86_l_151e;
	case 5411ULL: goto x86_l_1523;
	case 5414ULL: goto x86_l_1526;
	case 5420ULL: goto x86_l_152c;
	case 5425ULL: goto x86_l_1531;
	case 5428ULL: goto x86_l_1534;
	case 5434ULL: goto x86_l_153a;
	case 5438ULL: goto x86_l_153e;
	case 5440ULL: goto x86_l_1540;
	case 5446ULL: goto x86_l_1546;
	case 5451ULL: goto x86_l_154b;
	case 5455ULL: goto x86_l_154f;
	case 5457ULL: goto x86_l_1551;
	case 5460ULL: goto x86_l_1554;
	case 5463ULL: goto x86_l_1557;
	case 5468ULL: goto x86_l_155c;
	case 5472ULL: goto x86_l_1560;
	case 5477ULL: goto x86_l_1565;
	case 5484ULL: goto x86_l_156c;
	case 5489ULL: goto x86_l_1571;
	case 5491ULL: goto x86_l_1573;
	case 5494ULL: goto x86_l_1576;
	case 5500ULL: goto x86_l_157c;
	case 5502ULL: goto x86_l_157e;
	case 5507ULL: goto x86_l_1583;
	case 5510ULL: goto x86_l_1586;
	case 5515ULL: goto x86_l_158b;
	case 5517ULL: goto x86_l_158d;
	case 5521ULL: goto x86_l_1591;
	case 5523ULL: goto x86_l_1593;
	case 5525ULL: goto x86_l_1595;
	case 5528ULL: goto x86_l_1598;
	case 5531ULL: goto x86_l_159b;
	case 5534ULL: goto x86_l_159e;
	case 5536ULL: goto x86_l_15a0;
	case 5538ULL: goto x86_l_15a2;
	case 5542ULL: goto x86_l_15a6;
	case 5545ULL: goto x86_l_15a9;
	case 5547ULL: goto x86_l_15ab;
	case 5551ULL: goto x86_l_15af;
	case 5554ULL: goto x86_l_15b2;
	case 5556ULL: goto x86_l_15b4;
	case 5560ULL: goto x86_l_15b8;
	case 5562ULL: goto x86_l_15ba;
	case 5566ULL: goto x86_l_15be;
	case 5570ULL: goto x86_l_15c2;
	case 5573ULL: goto x86_l_15c5;
	case 5575ULL: goto x86_l_15c7;
	case 5577ULL: goto x86_l_15c9;
	case 5579ULL: goto x86_l_15cb;
	case 5585ULL: goto x86_l_15d1;
	case 5590ULL: goto x86_l_15d6;
	case 5594ULL: goto x86_l_15da;
	case 5596ULL: goto x86_l_15dc;
	case 5600ULL: goto x86_l_15e0;
	case 5603ULL: goto x86_l_15e3;
	case 5607ULL: goto x86_l_15e7;
	case 5613ULL: goto x86_l_15ed;
	case 5616ULL: goto x86_l_15f0;
	case 5621ULL: goto x86_l_15f5;
	case 5626ULL: goto x86_l_15fa;
	case 5630ULL: goto x86_l_15fe;
	case 5634ULL: goto x86_l_1602;
	case 5640ULL: goto x86_l_1608;
	case 5645ULL: goto x86_l_160d;
	case 5648ULL: goto x86_l_1610;
	case 5651ULL: goto x86_l_1613;
	case 5656ULL: goto x86_l_1618;
	case 5662ULL: goto x86_l_161e;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5676ULL: goto x86_l_162c;
	case 5681ULL: goto x86_l_1631;
	case 5688ULL: goto x86_l_1638;
	case 5693ULL: goto x86_l_163d;
	case 5695ULL: goto x86_l_163f;
	case 5698ULL: goto x86_l_1642;
	case 5704ULL: goto x86_l_1648;
	case 5707ULL: goto x86_l_164b;
	case 5712ULL: goto x86_l_1650;
	case 5717ULL: goto x86_l_1655;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5727ULL: goto x86_l_165f;
	case 5731ULL: goto x86_l_1663;
	case 5733ULL: goto x86_l_1665;
	case 5736ULL: goto x86_l_1668;
	case 5742ULL: goto x86_l_166e;
	case 5747ULL: goto x86_l_1673;
	case 5750ULL: goto x86_l_1676;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5765ULL: goto x86_l_1685;
	case 5771ULL: goto x86_l_168b;
	case 5776ULL: goto x86_l_1690;
	case 5779ULL: goto x86_l_1693;
	case 5785ULL: goto x86_l_1699;
	case 5788ULL: goto x86_l_169c;
	case 5791ULL: goto x86_l_169f;
	case 5796ULL: goto x86_l_16a4;
	case 5799ULL: goto x86_l_16a7;
	case 5804ULL: goto x86_l_16ac;
	case 5806ULL: goto x86_l_16ae;
	case 5809ULL: goto x86_l_16b1;
	case 5814ULL: goto x86_l_16b6;
	case 5819ULL: goto x86_l_16bb;
	case 5824ULL: goto x86_l_16c0;
	case 5828ULL: goto x86_l_16c4;
	case 5832ULL: goto x86_l_16c8;
	case 5838ULL: goto x86_l_16ce;
	case 5843ULL: goto x86_l_16d3;
	case 5846ULL: goto x86_l_16d6;
	case 5852ULL: goto x86_l_16dc;
	case 5855ULL: goto x86_l_16df;
	case 5861ULL: goto x86_l_16e5;
	case 5865ULL: goto x86_l_16e9;
	case 5868ULL: goto x86_l_16ec;
	case 5870ULL: goto x86_l_16ee;
	case 5876ULL: goto x86_l_16f4;
	case 5881ULL: goto x86_l_16f9;
	case 5884ULL: goto x86_l_16fc;
	case 5890ULL: goto x86_l_1702;
	case 5893ULL: goto x86_l_1705;
	case 5899ULL: goto x86_l_170b;
	case 5903ULL: goto x86_l_170f;
	case 5906ULL: goto x86_l_1712;
	case 5908ULL: goto x86_l_1714;
	case 5914ULL: goto x86_l_171a;
	case 5919ULL: goto x86_l_171f;
	case 5922ULL: goto x86_l_1722;
	case 5927ULL: goto x86_l_1727;
	case 5932ULL: goto x86_l_172c;
	case 5937ULL: goto x86_l_1731;
	case 5942ULL: goto x86_l_1736;
	case 5945ULL: goto x86_l_1739;
	case 5950ULL: goto x86_l_173e;
	case 5954ULL: goto x86_l_1742;
	case 5959ULL: goto x86_l_1747;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5973ULL: goto x86_l_1755;
	case 5976ULL: goto x86_l_1758;
	case 5982ULL: goto x86_l_175e;
	case 5986ULL: goto x86_l_1762;
	case 5989ULL: goto x86_l_1765;
	case 5994ULL: goto x86_l_176a;
	case 5999ULL: goto x86_l_176f;
	case 6001ULL: goto x86_l_1771;
	case 6004ULL: goto x86_l_1774;
	case 6009ULL: goto x86_l_1779;
	case 6013ULL: goto x86_l_177d;
	case 6018ULL: goto x86_l_1782;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6032ULL: goto x86_l_1790;
	case 6035ULL: goto x86_l_1793;
	case 6041ULL: goto x86_l_1799;
	case 6045ULL: goto x86_l_179d;
	case 6048ULL: goto x86_l_17a0;
	case 6053ULL: goto x86_l_17a5;
	case 6058ULL: goto x86_l_17aa;
	case 6061ULL: goto x86_l_17ad;
	case 6066ULL: goto x86_l_17b2;
	case 6071ULL: goto x86_l_17b7;
	case 6078ULL: goto x86_l_17be;
	case 6084ULL: goto x86_l_17c4;
	case 6087ULL: goto x86_l_17c7;
	case 6093ULL: goto x86_l_17cd;
	case 6095ULL: goto x86_l_17cf;
	case 6101ULL: goto x86_l_17d5;
	case 6104ULL: goto x86_l_17d8;
	case 6110ULL: goto x86_l_17de;
	case 6115ULL: goto x86_l_17e3;
	case 6120ULL: goto x86_l_17e8;
	case 6123ULL: goto x86_l_17eb;
	case 6126ULL: goto x86_l_17ee;
	case 6131ULL: goto x86_l_17f3;
	case 6135ULL: goto x86_l_17f7;
	case 6140ULL: goto x86_l_17fc;
	case 6145ULL: goto x86_l_1801;
	case 6148ULL: goto x86_l_1804;
	case 6151ULL: goto x86_l_1807;
	case 6156ULL: goto x86_l_180c;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6173ULL: goto x86_l_181d;
	case 6176ULL: goto x86_l_1820;
	case 6181ULL: goto x86_l_1825;
	case 6186ULL: goto x86_l_182a;
	case 6189ULL: goto x86_l_182d;
	case 6193ULL: goto x86_l_1831;
	case 6198ULL: goto x86_l_1836;
	case 6203ULL: goto x86_l_183b;
	case 6208ULL: goto x86_l_1840;
	case 6210ULL: goto x86_l_1842;
	case 6215ULL: goto x86_l_1847;
	case 6220ULL: goto x86_l_184c;
	case 6222ULL: goto x86_l_184e;
	case 6227ULL: goto x86_l_1853;
	case 6232ULL: goto x86_l_1858;
	case 6234ULL: goto x86_l_185a;
	case 6236ULL: goto x86_l_185c;
	case 6241ULL: goto x86_l_1861;
	case 6244ULL: goto x86_l_1864;
	case 6247ULL: goto x86_l_1867;
	case 6253ULL: goto x86_l_186d;
	case 6259ULL: goto x86_l_1873;
	case 6265ULL: goto x86_l_1879;
	case 6268ULL: goto x86_l_187c;
	case 6274ULL: goto x86_l_1882;
	case 6276ULL: goto x86_l_1884;
	case 6282ULL: goto x86_l_188a;
	case 6285ULL: goto x86_l_188d;
	case 6291ULL: goto x86_l_1893;
	case 6296ULL: goto x86_l_1898;
	case 6301ULL: goto x86_l_189d;
	case 6304ULL: goto x86_l_18a0;
	case 6307ULL: goto x86_l_18a3;
	case 6312ULL: goto x86_l_18a8;
	case 6316ULL: goto x86_l_18ac;
	case 6320ULL: goto x86_l_18b0;
	case 6325ULL: goto x86_l_18b5;
	case 6332ULL: goto x86_l_18bc;
	case 6337ULL: goto x86_l_18c1;
	case 6339ULL: goto x86_l_18c3;
	case 6342ULL: goto x86_l_18c6;
	case 6348ULL: goto x86_l_18cc;
	case 6356ULL: goto x86_l_18d4;
	case 6360ULL: goto x86_l_18d8;
	case 6367ULL: goto x86_l_18df;
	case 6375ULL: goto x86_l_18e7;
	case 6379ULL: goto x86_l_18eb;
	case 6387ULL: goto x86_l_18f3;
	case 6392ULL: goto x86_l_18f8;
	case 6397ULL: goto x86_l_18fd;
	case 6400ULL: goto x86_l_1900;
	case 6405ULL: goto x86_l_1905;
	case 6407ULL: goto x86_l_1907;
	case 6411ULL: goto x86_l_190b;
	case 6414ULL: goto x86_l_190e;
	case 6417ULL: goto x86_l_1911;
	case 6423ULL: goto x86_l_1917;
	case 6426ULL: goto x86_l_191a;
	case 6429ULL: goto x86_l_191d;
	case 6434ULL: goto x86_l_1922;
	case 6439ULL: goto x86_l_1927;
	case 6444ULL: goto x86_l_192c;
	case 6450ULL: goto x86_l_1932;
	case 6453ULL: goto x86_l_1935;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1305:
	/* 0x1305: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_130b:
	/* 0x130b: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_130e:
	/* 0x130e: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1312:
	/* 0x1312: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1314:
	/* 0x1314: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1317:
	/* 0x1317: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_131b:
	/* 0x131b: lea    ebx,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_131f:
	/* 0x131f: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1325:
	/* 0x1325: movzx  ebx,BYTE PTR [rsi+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 0, X86_WIDTH_8), 0ULL);
x86_l_1329:
	/* 0x1329: mov    BYTE PTR [rdi-0x3],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_132c:
	/* 0x132c: cmp    r10,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R12, X86_WIDTH_64);
x86_l_132f:
	/* 0x132f: je     1380 <generic_fentry_filter_arg+0x1380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1380;
	}
x86_l_1331:
	/* 0x1331: lea    ebx,[r11+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1335:
	/* 0x1335: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_133b:
	/* 0x133b: movzx  ebx,BYTE PTR [rsi+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 0, X86_WIDTH_8), 0ULL);
x86_l_133f:
	/* 0x133f: mov    BYTE PTR [rdi-0x2],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1342:
	/* 0x1342: cmp    r8,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R12, X86_WIDTH_64);
x86_l_1345:
	/* 0x1345: je     1380 <generic_fentry_filter_arg+0x1380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1380;
	}
x86_l_1347:
	/* 0x1347: lea    ebx,[r9+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_134b:
	/* 0x134b: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1351:
	/* 0x1351: movzx  ebx,BYTE PTR [rsi+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 0, X86_WIDTH_8), 0ULL);
x86_l_1355:
	/* 0x1355: mov    BYTE PTR [rdi-0x1],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1358:
	/* 0x1358: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_135b:
	/* 0x135b: je     1380 <generic_fentry_filter_arg+0x1380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1380;
	}
x86_l_135d:
	/* 0x135d: cmp    r12,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_1361:
	/* 0x1361: je     1380 <generic_fentry_filter_arg+0x1380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1380;
	}
x86_l_1363:
	/* 0x1363: lea    ebx,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1367:
	/* 0x1367: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_136d:
	/* 0x136d: movzx  ebx,BYTE PTR [rsi+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBX, 0, X86_WIDTH_8), 0ULL);
x86_l_1371:
	/* 0x1371: mov    BYTE PTR [rdi],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1373:
	/* 0x1373: add    r12,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1377:
	/* 0x1377: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_137b:
	/* 0x137b: cmp    rcx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_137e:
	/* 0x137e: jne    131b <generic_fentry_filter_arg+0x131b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_131b;
	}
x86_l_1380:
	/* 0x1380: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1385:
	/* 0x1385: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_138a:
	/* 0x138a: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_138f:
	/* 0x138f: jmp    38b2 <generic_fentry_filter_arg+0x38b2> */
	return 14514ULL;
x86_l_1394:
	/* 0x1394: mov    esi,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1398:
	/* 0x1398: mov    eax,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_139c:
	/* 0x139c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_139f:
	/* 0x139f: ja     20af <generic_fentry_filter_arg+0x20af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8367ULL;
	}
x86_l_13a5:
	/* 0x13a5: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_13aa:
	/* 0x13aa: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_13ad:
	/* 0x13ad: jae    20af <generic_fentry_filter_arg+0x20af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8367ULL;
	}
x86_l_13b3:
	/* 0x13b3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b7:
	/* 0x13b7: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b9:
	/* 0x13b9: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_13bb:
	/* 0x13bb: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_13bf:
	/* 0x13bf: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_13c1:
	/* 0x13c1: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_13c4:
	/* 0x13c4: jmp    20c0 <generic_fentry_filter_arg+0x20c0> */
	return 8384ULL;
x86_l_13c9:
	/* 0x13c9: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_13cc:
	/* 0x13cc: je     1add <generic_fentry_filter_arg+0x1add> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6877ULL;
	}
x86_l_13d2:
	/* 0x13d2: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13d7:
	/* 0x13d7: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13db:
	/* 0x13db: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_13de:
	/* 0x13de: je     1a41 <generic_fentry_filter_arg+0x1a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6721ULL;
	}
x86_l_13e4:
	/* 0x13e4: jmp    108 <generic_fentry_filter_arg+0x108> */
	return 264ULL;
x86_l_13e9:
	/* 0x13e9: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_13ec:
	/* 0x13ec: je     1403 <generic_fentry_filter_arg+0x1403> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1403;
	}
x86_l_13ee:
	/* 0x13ee: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_13f4:
	/* 0x13f4: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_13f7:
	/* 0x13f7: jne    2a8 <generic_fentry_filter_arg+0x2a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 680ULL;
	}
x86_l_13fd:
	/* 0x13fd: movzx  ebp,WORD PTR [rsi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1401:
	/* 0x1401: jmp    1407 <generic_fentry_filter_arg+0x1407> */
	goto x86_l_1407;
x86_l_1403:
	/* 0x1403: movzx  ebp,WORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1407:
	/* 0x1407: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1409:
	/* 0x1409: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_140b:
	/* 0x140b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_140e:
	/* 0x140e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1411:
	/* 0x1411: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1414:
	/* 0x1414: jg     1498 <generic_fentry_filter_arg+0x1498> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1498;
	}
x86_l_141a:
	/* 0x141a: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_141d:
	/* 0x141d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1420:
	/* 0x1420: jb     14cb <generic_fentry_filter_arg+0x14cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_14cb;
	}
x86_l_1426:
	/* 0x1426: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_1429:
	/* 0x1429: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_142c:
	/* 0x142c: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1431:
	/* 0x1431: jb     161e <generic_fentry_filter_arg+0x161e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_161e;
	}
x86_l_1437:
	/* 0x1437: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_143a:
	/* 0x143a: je     1c7f <generic_fentry_filter_arg+0x1c7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7295ULL;
	}
x86_l_1440:
	/* 0x1440: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_1445:
	/* 0x1445: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_1448:
	/* 0x1448: je     1c7a <generic_fentry_filter_arg+0x1c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7290ULL;
	}
x86_l_144e:
	/* 0x144e: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_1454:
	/* 0x1454: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_1457:
	/* 0x1457: jne    2a8 <generic_fentry_filter_arg+0x2a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 680ULL;
	}
x86_l_145d:
	/* 0x145d: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1460:
	/* 0x1460: jne    2273 <generic_fentry_filter_arg+0x2273> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8819ULL;
	}
x86_l_1466:
	/* 0x1466: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1469:
	/* 0x1469: jne    227f <generic_fentry_filter_arg+0x227f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8831ULL;
	}
x86_l_146f:
	/* 0x146f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1471:
	/* 0x1471: jmp    2291 <generic_fentry_filter_arg+0x2291> */
	return 8849ULL;
x86_l_1476:
	/* 0x1476: mov    rdx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_147a:
	/* 0x147a: mov    r8,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_147e:
	/* 0x147e: jmp    1487 <generic_fentry_filter_arg+0x1487> */
	goto x86_l_1487;
x86_l_1480:
	/* 0x1480: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1483:
	/* 0x1483: mov    r8,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1487:
	/* 0x1487: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_148a:
	/* 0x148a: shr    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_148e:
	/* 0x148e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1490:
	/* 0x1490: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1493:
	/* 0x1493: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1496:
	/* 0x1496: jle    141a <generic_fentry_filter_arg+0x141a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_141a;
	}
x86_l_1498:
	/* 0x1498: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_149b:
	/* 0x149b: ja     160d <generic_fentry_filter_arg+0x160d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_160d;
	}
x86_l_14a1:
	/* 0x14a1: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_14a6:
	/* 0x14a6: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_14a9:
	/* 0x14a9: jb     17e8 <generic_fentry_filter_arg+0x17e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_17e8;
	}
x86_l_14af:
	/* 0x14af: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_14b4:
	/* 0x14b4: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_14b7:
	/* 0x14b7: jb     1801 <generic_fentry_filter_arg+0x1801> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1801;
	}
x86_l_14bd:
	/* 0x14bd: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_14c2:
	/* 0x14c2: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_14c5:
	/* 0x14c5: jae    160d <generic_fentry_filter_arg+0x160d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_160d;
	}
x86_l_14cb:
	/* 0x14cb: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_14cf:
	/* 0x14cf: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_14d2:
	/* 0x14d2: je     189d <generic_fentry_filter_arg+0x189d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_189d;
	}
x86_l_14d8:
	/* 0x14d8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14db:
	/* 0x14db: jne    1941 <generic_fentry_filter_arg+0x1941> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6465ULL;
	}
x86_l_14e1:
	/* 0x14e1: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_14e4:
	/* 0x14e4: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14e9:
	/* 0x14e9: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14ed:
	/* 0x14ed: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14f1:
	/* 0x14f1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14f6:
	/* 0x14f6: mov    rdi,QWORD PTR [rip+0x1c23d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_14fd:
	/* 0x14fd: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1502:
	/* 0x1502: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1504:
	/* 0x1504: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1507:
	/* 0x1507: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_150c:
	/* 0x150c: je     2397 <generic_fentry_filter_arg+0x2397> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9111ULL;
	}
x86_l_1512:
	/* 0x1512: mov    DWORD PTR [rsp+0x78],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075552ULL);
x86_l_151a:
	/* 0x151a: mov    DWORD PTR [rsp+0x7c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_151e:
	/* 0x151e: jmp    18f8 <generic_fentry_filter_arg+0x18f8> */
	goto x86_l_18f8;
x86_l_1523:
	/* 0x1523: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1526:
	/* 0x1526: ja     23d0 <generic_fentry_filter_arg+0x23d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9168ULL;
	}
x86_l_152c:
	/* 0x152c: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_1531:
	/* 0x1531: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1534:
	/* 0x1534: jae    23d0 <generic_fentry_filter_arg+0x23d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9168ULL;
	}
x86_l_153a:
	/* 0x153a: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_153e:
	/* 0x153e: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1540:
	/* 0x1540: jg     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 697ULL;
	}
x86_l_1546:
	/* 0x1546: jmp    23ea <generic_fentry_filter_arg+0x23ea> */
	return 9194ULL;
x86_l_154b:
	/* 0x154b: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_154f:
	/* 0x154f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1551:
	/* 0x1551: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1554:
	/* 0x1554: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_1557:
	/* 0x1557: mov    eax,DWORD PTR [r13+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_155c:
	/* 0x155c: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1560:
	/* 0x1560: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1565:
	/* 0x1565: mov    rdi,QWORD PTR [rip+0x1c23d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_156c:
	/* 0x156c: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1571:
	/* 0x1571: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1573:
	/* 0x1573: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1576:
	/* 0x1576: je     230c <generic_fentry_filter_arg+0x230c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8972ULL;
	}
x86_l_157c:
	/* 0x157c: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_157e:
	/* 0x157e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1583:
	/* 0x1583: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_1586:
	/* 0x1586: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_158b:
	/* 0x158b: je     15d1 <generic_fentry_filter_arg+0x15d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15d1;
	}
x86_l_158d:
	/* 0x158d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1591:
	/* 0x1591: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1593:
	/* 0x1593: jmp    15a0 <generic_fentry_filter_arg+0x15a0> */
	goto x86_l_15a0;
x86_l_1595:
	/* 0x1595: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1598:
	/* 0x1598: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_159b:
	/* 0x159b: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_159e:
	/* 0x159e: je     15d1 <generic_fentry_filter_arg+0x15d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15d1;
	}
x86_l_15a0:
	/* 0x15a0: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15a2:
	/* 0x15a2: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_15a6:
	/* 0x15a6: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_15a9:
	/* 0x15a9: jae    1595 <generic_fentry_filter_arg+0x1595> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1595;
	}
x86_l_15ab:
	/* 0x15ab: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_15af:
	/* 0x15af: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_15b2:
	/* 0x15b2: je     15c9 <generic_fentry_filter_arg+0x15c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15c9;
	}
x86_l_15b4:
	/* 0x15b4: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_15b8:
	/* 0x15b8: ja     1595 <generic_fentry_filter_arg+0x1595> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1595;
	}
x86_l_15ba:
	/* 0x15ba: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_15be:
	/* 0x15be: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_15c2:
	/* 0x15c2: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_15c5:
	/* 0x15c5: je     15a2 <generic_fentry_filter_arg+0x15a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15a2;
	}
x86_l_15c7:
	/* 0x15c7: jmp    1595 <generic_fentry_filter_arg+0x1595> */
	goto x86_l_1595;
x86_l_15c9:
	/* 0x15c9: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_15cb:
	/* 0x15cb: jns    269a <generic_fentry_filter_arg+0x269a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9882ULL;
	}
x86_l_15d1:
	/* 0x15d1: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_15d6:
	/* 0x15d6: cmp    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_15da:
	/* 0x15da: jae    15ed <generic_fentry_filter_arg+0x15ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_15ed;
	}
x86_l_15dc:
	/* 0x15dc: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_15e0:
	/* 0x15e0: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15e3:
	/* 0x15e3: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_15e7:
	/* 0x15e7: jne    1554 <generic_fentry_filter_arg+0x1554> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1554;
	}
x86_l_15ed:
	/* 0x15ed: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15f0:
	/* 0x15f0: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15f5:
	/* 0x15f5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15fa:
	/* 0x15fa: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15fe:
	/* 0x15fe: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_1602:
	/* 0x1602: jbe    35cd <generic_fentry_filter_arg+0x35cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13773ULL;
	}
x86_l_1608:
	/* 0x1608: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_160d:
	/* 0x160d: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_1610:
	/* 0x1610: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1613:
	/* 0x1613: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1618:
	/* 0x1618: jae    2a8 <generic_fentry_filter_arg+0x2a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 680ULL;
	}
x86_l_161e:
	/* 0x161e: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1623:
	/* 0x1623: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1628:
	/* 0x1628: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_162c:
	/* 0x162c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1631:
	/* 0x1631: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1638:
	/* 0x1638: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_163d:
	/* 0x163d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163f:
	/* 0x163f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1642:
	/* 0x1642: je     171f <generic_fentry_filter_arg+0x171f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_171f;
	}
x86_l_1648:
	/* 0x1648: movzx  ecx,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_164b:
	/* 0x164b: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1650:
	/* 0x1650: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1655:
	/* 0x1655: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1658:
	/* 0x1658: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_165d:
	/* 0x165d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_165f:
	/* 0x165f: mov    edx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1663:
	/* 0x1663: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1665:
	/* 0x1665: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1668:
	/* 0x1668: ja     3055 <generic_fentry_filter_arg+0x3055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12373ULL;
	}
x86_l_166e:
	/* 0x166e: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1673:
	/* 0x1673: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1676:
	/* 0x1676: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_167b:
	/* 0x167b: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1680:
	/* 0x1680: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1685:
	/* 0x1685: jb     1ce5 <generic_fentry_filter_arg+0x1ce5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7397ULL;
	}
x86_l_168b:
	/* 0x168b: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1690:
	/* 0x1690: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1693:
	/* 0x1693: jae    1ceb <generic_fentry_filter_arg+0x1ceb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7403ULL;
	}
x86_l_1699:
	/* 0x1699: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_169c:
	/* 0x169c: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_169f:
	/* 0x169f: jmp    1ceb <generic_fentry_filter_arg+0x1ceb> */
	return 7403ULL;
x86_l_16a4:
	/* 0x16a4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16a7:
	/* 0x16a7: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16ac:
	/* 0x16ac: jmp    16b1 <generic_fentry_filter_arg+0x16b1> */
	goto x86_l_16b1;
x86_l_16ae:
	/* 0x16ae: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16b1:
	/* 0x16b1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16b6:
	/* 0x16b6: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16bb:
	/* 0x16bb: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16c0:
	/* 0x16c0: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16c4:
	/* 0x16c4: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_16c8:
	/* 0x16c8: jbe    35cd <generic_fentry_filter_arg+0x35cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13773ULL;
	}
x86_l_16ce:
	/* 0x16ce: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_16d3:
	/* 0x16d3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16d6:
	/* 0x16d6: je     1fc3 <generic_fentry_filter_arg+0x1fc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8131ULL;
	}
x86_l_16dc:
	/* 0x16dc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16df:
	/* 0x16df: jne    1fd2 <generic_fentry_filter_arg+0x1fd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8146ULL;
	}
x86_l_16e5:
	/* 0x16e5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e9:
	/* 0x16e9: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_16ec:
	/* 0x16ec: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_16ee:
	/* 0x16ee: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_16f4:
	/* 0x16f4: jmp    1fd2 <generic_fentry_filter_arg+0x1fd2> */
	return 8146ULL;
x86_l_16f9:
	/* 0x16f9: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16fc:
	/* 0x16fc: je     200c <generic_fentry_filter_arg+0x200c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8204ULL;
	}
x86_l_1702:
	/* 0x1702: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1705:
	/* 0x1705: jne    201b <generic_fentry_filter_arg+0x201b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8219ULL;
	}
x86_l_170b:
	/* 0x170b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_170f:
	/* 0x170f: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1712:
	/* 0x1712: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1714:
	/* 0x1714: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_171a:
	/* 0x171a: jmp    201b <generic_fentry_filter_arg+0x201b> */
	return 8219ULL;
x86_l_171f:
	/* 0x171f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1722:
	/* 0x1722: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1727:
	/* 0x1727: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_172c:
	/* 0x172c: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1731:
	/* 0x1731: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_1736:
	/* 0x1736: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_1739:
	/* 0x1739: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_173e:
	/* 0x173e: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1742:
	/* 0x1742: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1747:
	/* 0x1747: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_174e:
	/* 0x174e: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1753:
	/* 0x1753: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1755:
	/* 0x1755: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1758:
	/* 0x1758: je     1cf4 <generic_fentry_filter_arg+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_175e:
	/* 0x175e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1762:
	/* 0x1762: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1765:
	/* 0x1765: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_176a:
	/* 0x176a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_176f:
	/* 0x176f: jmp    17aa <generic_fentry_filter_arg+0x17aa> */
	goto x86_l_17aa;
x86_l_1771:
	/* 0x1771: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_1774:
	/* 0x1774: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1779:
	/* 0x1779: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_177d:
	/* 0x177d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1782:
	/* 0x1782: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1789:
	/* 0x1789: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_178e:
	/* 0x178e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1790:
	/* 0x1790: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1793:
	/* 0x1793: je     1cf4 <generic_fentry_filter_arg+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7412ULL;
	}
x86_l_1799:
	/* 0x1799: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_179d:
	/* 0x179d: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17a0:
	/* 0x17a0: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17a5:
	/* 0x17a5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17aa:
	/* 0x17aa: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_17ad:
	/* 0x17ad: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17b2:
	/* 0x17b2: jmp    1cb9 <generic_fentry_filter_arg+0x1cb9> */
	return 7353ULL;
x86_l_17b7:
	/* 0x17b7: lea    eax,[r10-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_17be:
	/* 0x17be: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_17c4:
	/* 0x17c4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_17c7:
	/* 0x17c7: jg     1f9f <generic_fentry_filter_arg+0x1f9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8095ULL;
	}
x86_l_17cd:
	/* 0x17cd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17cf:
	/* 0x17cf: je     2748 <generic_fentry_filter_arg+0x2748> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10056ULL;
	}
x86_l_17d5:
	/* 0x17d5: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17d8:
	/* 0x17d8: jne    2741 <generic_fentry_filter_arg+0x2741> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10049ULL;
	}
x86_l_17de:
	/* 0x17de: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_17e3:
	/* 0x17e3: jmp    2754 <generic_fentry_filter_arg+0x2754> */
	return 10068ULL;
x86_l_17e8:
	/* 0x17e8: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_17eb:
	/* 0x17eb: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17ee:
	/* 0x17ee: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_17f3:
	/* 0x17f3: setb   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_B);
x86_l_17f7:
	/* 0x17f7: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17fc:
	/* 0x17fc: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_1801:
	/* 0x1801: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1804:
	/* 0x1804: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1807:
	/* 0x1807: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_180c:
	/* 0x180c: setae  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_AE);
x86_l_1810:
	/* 0x1810: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1815:
	/* 0x1815: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_181a:
	/* 0x181a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_181d:
	/* 0x181d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1820:
	/* 0x1820: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1825:
	/* 0x1825: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_182a:
	/* 0x182a: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_182d:
	/* 0x182d: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1831:
	/* 0x1831: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_1836:
	/* 0x1836: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_183b:
	/* 0x183b: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1840:
	/* 0x1840: jb     186d <generic_fentry_filter_arg+0x186d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_186d;
	}
x86_l_1842:
	/* 0x1842: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_1847:
	/* 0x1847: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_184c:
	/* 0x184c: jb     186d <generic_fentry_filter_arg+0x186d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_186d;
	}
x86_l_184e:
	/* 0x184e: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_1853:
	/* 0x1853: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_1858:
	/* 0x1858: jb     186d <generic_fentry_filter_arg+0x186d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_186d;
	}
x86_l_185a:
	/* 0x185a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_185c:
	/* 0x185c: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_1861:
	/* 0x1861: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_1864:
	/* 0x1864: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_1867:
	/* 0x1867: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_186d:
	/* 0x186d: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_1873:
	/* 0x1873: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_1879:
	/* 0x1879: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_187c:
	/* 0x187c: jg     1edb <generic_fentry_filter_arg+0x1edb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7899ULL;
	}
x86_l_1882:
	/* 0x1882: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1884:
	/* 0x1884: je     24f5 <generic_fentry_filter_arg+0x24f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9461ULL;
	}
x86_l_188a:
	/* 0x188a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_188d:
	/* 0x188d: jne    24ee <generic_fentry_filter_arg+0x24ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9454ULL;
	}
x86_l_1893:
	/* 0x1893: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1898:
	/* 0x1898: jmp    2501 <generic_fentry_filter_arg+0x2501> */
	return 9473ULL;
x86_l_189d:
	/* 0x189d: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_18a0:
	/* 0x18a0: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_18a3:
	/* 0x18a3: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18a8:
	/* 0x18a8: mov    eax,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_18ac:
	/* 0x18ac: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18b0:
	/* 0x18b0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18b5:
	/* 0x18b5: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_18bc:
	/* 0x18bc: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18c1:
	/* 0x18c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c3:
	/* 0x18c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18c6:
	/* 0x18c6: je     23a6 <generic_fentry_filter_arg+0x23a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9126ULL;
	}
x86_l_18cc:
	/* 0x18cc: mov    DWORD PTR [rsp+0x78],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075648ULL);
x86_l_18d4:
	/* 0x18d4: mov    DWORD PTR [rsp+0x7c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_18d8:
	/* 0x18d8: mov    DWORD PTR [rsp+0x80],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_18df:
	/* 0x18df: mov    DWORD PTR [rsp+0x84],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_18e7:
	/* 0x18e7: shr    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_18eb:
	/* 0x18eb: mov    DWORD PTR [rsp+0x88],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_18f3:
	/* 0x18f3: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18f8:
	/* 0x18f8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_18fd:
	/* 0x18fd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1900:
	/* 0x1900: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1905:
	/* 0x1905: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1907:
	/* 0x1907: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_190b:
	/* 0x190b: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_190e:
	/* 0x190e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1911:
	/* 0x1911: jb     1fbb <generic_fentry_filter_arg+0x1fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8123ULL;
	}
x86_l_1917:
	/* 0x1917: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_191a:
	/* 0x191a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_191d:
	/* 0x191d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1922:
	/* 0x1922: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1927:
	/* 0x1927: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_192c:
	/* 0x192c: ja     d1c <generic_fentry_filter_arg+0xd1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3356ULL;
	}
x86_l_1932:
	/* 0x1932: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1935:
	/* 0x1935: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
	return 6456ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6456ULL: goto x86_l_1938;
	case 6460ULL: goto x86_l_193c;
	case 6465ULL: goto x86_l_1941;
	case 6467ULL: goto x86_l_1943;
	case 6472ULL: goto x86_l_1948;
	case 6476ULL: goto x86_l_194c;
	case 6481ULL: goto x86_l_1951;
	case 6484ULL: goto x86_l_1954;
	case 6490ULL: goto x86_l_195a;
	case 6494ULL: goto x86_l_195e;
	case 6497ULL: goto x86_l_1961;
	case 6499ULL: goto x86_l_1963;
	case 6508ULL: goto x86_l_196c;
	case 6514ULL: goto x86_l_1972;
	case 6518ULL: goto x86_l_1976;
	case 6521ULL: goto x86_l_1979;
	case 6529ULL: goto x86_l_1981;
	case 6534ULL: goto x86_l_1986;
	case 6537ULL: goto x86_l_1989;
	case 6547ULL: goto x86_l_1993;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6559ULL: goto x86_l_199f;
	case 6565ULL: goto x86_l_19a5;
	case 6571ULL: goto x86_l_19ab;
	case 6574ULL: goto x86_l_19ae;
	case 6580ULL: goto x86_l_19b4;
	case 6585ULL: goto x86_l_19b9;
	case 6588ULL: goto x86_l_19bc;
	case 6593ULL: goto x86_l_19c1;
	case 6597ULL: goto x86_l_19c5;
	case 6602ULL: goto x86_l_19ca;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6616ULL: goto x86_l_19d8;
	case 6619ULL: goto x86_l_19db;
	case 6625ULL: goto x86_l_19e1;
	case 6629ULL: goto x86_l_19e5;
	case 6632ULL: goto x86_l_19e8;
	case 6635ULL: goto x86_l_19eb;
	case 6640ULL: goto x86_l_19f0;
	case 6642ULL: goto x86_l_19f2;
	case 6648ULL: goto x86_l_19f8;
	case 6652ULL: goto x86_l_19fc;
	case 6655ULL: goto x86_l_19ff;
	case 6659ULL: goto x86_l_1a03;
	case 6664ULL: goto x86_l_1a08;
	case 6669ULL: goto x86_l_1a0d;
	case 6672ULL: goto x86_l_1a10;
	case 6678ULL: goto x86_l_1a16;
	case 6684ULL: goto x86_l_1a1c;
	case 6691ULL: goto x86_l_1a23;
	case 6696ULL: goto x86_l_1a28;
	case 6698ULL: goto x86_l_1a2a;
	case 6703ULL: goto x86_l_1a2f;
	case 6708ULL: goto x86_l_1a34;
	case 6712ULL: goto x86_l_1a38;
	case 6715ULL: goto x86_l_1a3b;
	case 6721ULL: goto x86_l_1a41;
	case 6726ULL: goto x86_l_1a46;
	case 6730ULL: goto x86_l_1a4a;
	case 6734ULL: goto x86_l_1a4e;
	case 6742ULL: goto x86_l_1a56;
	case 6747ULL: goto x86_l_1a5b;
	case 6754ULL: goto x86_l_1a62;
	case 6759ULL: goto x86_l_1a67;
	case 6761ULL: goto x86_l_1a69;
	case 6764ULL: goto x86_l_1a6c;
	case 6770ULL: goto x86_l_1a72;
	case 6773ULL: goto x86_l_1a75;
	case 6779ULL: goto x86_l_1a7b;
	case 6782ULL: goto x86_l_1a7e;
	case 6788ULL: goto x86_l_1a84;
	case 6793ULL: goto x86_l_1a89;
	case 6800ULL: goto x86_l_1a90;
	case 6805ULL: goto x86_l_1a95;
	case 6807ULL: goto x86_l_1a97;
	case 6810ULL: goto x86_l_1a9a;
	case 6816ULL: goto x86_l_1aa0;
	case 6820ULL: goto x86_l_1aa4;
	case 6822ULL: goto x86_l_1aa6;
	case 6825ULL: goto x86_l_1aa9;
	case 6827ULL: goto x86_l_1aab;
	case 6830ULL: goto x86_l_1aae;
	case 6834ULL: goto x86_l_1ab2;
	case 6839ULL: goto x86_l_1ab7;
	case 6844ULL: goto x86_l_1abc;
	case 6847ULL: goto x86_l_1abf;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6857ULL: goto x86_l_1ac9;
	case 6860ULL: goto x86_l_1acc;
	case 6862ULL: goto x86_l_1ace;
	case 6865ULL: goto x86_l_1ad1;
	case 6868ULL: goto x86_l_1ad4;
	case 6872ULL: goto x86_l_1ad8;
	case 6877ULL: goto x86_l_1add;
	case 6880ULL: goto x86_l_1ae0;
	case 6883ULL: goto x86_l_1ae3;
	case 6888ULL: goto x86_l_1ae8;
	case 6892ULL: goto x86_l_1aec;
	case 6897ULL: goto x86_l_1af1;
	case 6904ULL: goto x86_l_1af8;
	case 6909ULL: goto x86_l_1afd;
	case 6911ULL: goto x86_l_1aff;
	case 6914ULL: goto x86_l_1b02;
	case 6920ULL: goto x86_l_1b08;
	case 6925ULL: goto x86_l_1b0d;
	case 6930ULL: goto x86_l_1b12;
	case 6933ULL: goto x86_l_1b15;
	case 6938ULL: goto x86_l_1b1a;
	case 6943ULL: goto x86_l_1b1f;
	case 6948ULL: goto x86_l_1b24;
	case 6952ULL: goto x86_l_1b28;
	case 6956ULL: goto x86_l_1b2c;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6976ULL: goto x86_l_1b40;
	case 6981ULL: goto x86_l_1b45;
	case 6983ULL: goto x86_l_1b47;
	case 6985ULL: goto x86_l_1b49;
	case 6991ULL: goto x86_l_1b4f;
	case 6994ULL: goto x86_l_1b52;
	case 7000ULL: goto x86_l_1b58;
	case 7003ULL: goto x86_l_1b5b;
	case 7009ULL: goto x86_l_1b61;
	case 7014ULL: goto x86_l_1b66;
	case 7021ULL: goto x86_l_1b6d;
	case 7026ULL: goto x86_l_1b72;
	case 7028ULL: goto x86_l_1b74;
	case 7031ULL: goto x86_l_1b77;
	case 7037ULL: goto x86_l_1b7d;
	case 7043ULL: goto x86_l_1b83;
	case 7048ULL: goto x86_l_1b88;
	case 7051ULL: goto x86_l_1b8b;
	case 7058ULL: goto x86_l_1b92;
	case 7060ULL: goto x86_l_1b94;
	case 7063ULL: goto x86_l_1b97;
	case 7067ULL: goto x86_l_1b9b;
	case 7072ULL: goto x86_l_1ba0;
	case 7074ULL: goto x86_l_1ba2;
	case 7078ULL: goto x86_l_1ba6;
	case 7081ULL: goto x86_l_1ba9;
	case 7083ULL: goto x86_l_1bab;
	case 7088ULL: goto x86_l_1bb0;
	case 7091ULL: goto x86_l_1bb3;
	case 7094ULL: goto x86_l_1bb6;
	case 7096ULL: goto x86_l_1bb8;
	case 7101ULL: goto x86_l_1bbd;
	case 7109ULL: goto x86_l_1bc5;
	case 7115ULL: goto x86_l_1bcb;
	case 7121ULL: goto x86_l_1bd1;
	case 7124ULL: goto x86_l_1bd4;
	case 7129ULL: goto x86_l_1bd9;
	case 7133ULL: goto x86_l_1bdd;
	case 7136ULL: goto x86_l_1be0;
	case 7139ULL: goto x86_l_1be3;
	case 7141ULL: goto x86_l_1be5;
	case 7144ULL: goto x86_l_1be8;
	case 7150ULL: goto x86_l_1bee;
	case 7154ULL: goto x86_l_1bf2;
	case 7157ULL: goto x86_l_1bf5;
	case 7163ULL: goto x86_l_1bfb;
	case 7167ULL: goto x86_l_1bff;
	case 7171ULL: goto x86_l_1c03;
	case 7174ULL: goto x86_l_1c06;
	case 7176ULL: goto x86_l_1c08;
	case 7179ULL: goto x86_l_1c0b;
	case 7185ULL: goto x86_l_1c11;
	case 7188ULL: goto x86_l_1c14;
	case 7193ULL: goto x86_l_1c19;
	case 7199ULL: goto x86_l_1c1f;
	case 7202ULL: goto x86_l_1c22;
	case 7208ULL: goto x86_l_1c28;
	case 7213ULL: goto x86_l_1c2d;
	case 7217ULL: goto x86_l_1c31;
	case 7220ULL: goto x86_l_1c34;
	case 7223ULL: goto x86_l_1c37;
	case 7227ULL: goto x86_l_1c3b;
	case 7230ULL: goto x86_l_1c3e;
	case 7233ULL: goto x86_l_1c41;
	case 7236ULL: goto x86_l_1c44;
	case 7240ULL: goto x86_l_1c48;
	case 7243ULL: goto x86_l_1c4b;
	case 7249ULL: goto x86_l_1c51;
	case 7253ULL: goto x86_l_1c55;
	case 7257ULL: goto x86_l_1c59;
	case 7260ULL: goto x86_l_1c5c;
	case 7262ULL: goto x86_l_1c5e;
	case 7265ULL: goto x86_l_1c61;
	case 7271ULL: goto x86_l_1c67;
	case 7274ULL: goto x86_l_1c6a;
	case 7278ULL: goto x86_l_1c6e;
	case 7281ULL: goto x86_l_1c71;
	case 7285ULL: goto x86_l_1c75;
	case 7290ULL: goto x86_l_1c7a;
	case 7295ULL: goto x86_l_1c7f;
	case 7298ULL: goto x86_l_1c82;
	case 7303ULL: goto x86_l_1c87;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7319ULL: goto x86_l_1c97;
	case 7324ULL: goto x86_l_1c9c;
	case 7326ULL: goto x86_l_1c9e;
	case 7329ULL: goto x86_l_1ca1;
	case 7331ULL: goto x86_l_1ca3;
	case 7335ULL: goto x86_l_1ca7;
	case 7340ULL: goto x86_l_1cac;
	case 7345ULL: goto x86_l_1cb1;
	case 7348ULL: goto x86_l_1cb4;
	case 7353ULL: goto x86_l_1cb9;
	case 7355ULL: goto x86_l_1cbb;
	case 7359ULL: goto x86_l_1cbf;
	case 7361ULL: goto x86_l_1cc1;
	case 7364ULL: goto x86_l_1cc4;
	case 7370ULL: goto x86_l_1cca;
	case 7375ULL: goto x86_l_1ccf;
	case 7378ULL: goto x86_l_1cd2;
	case 7383ULL: goto x86_l_1cd7;
	case 7388ULL: goto x86_l_1cdc;
	case 7391ULL: goto x86_l_1cdf;
	case 7397ULL: goto x86_l_1ce5;
	case 7400ULL: goto x86_l_1ce8;
	case 7403ULL: goto x86_l_1ceb;
	case 7407ULL: goto x86_l_1cef;
	case 7412ULL: goto x86_l_1cf4;
	case 7415ULL: goto x86_l_1cf7;
	case 7420ULL: goto x86_l_1cfc;
	case 7425ULL: goto x86_l_1d01;
	case 7428ULL: goto x86_l_1d04;
	case 7433ULL: goto x86_l_1d09;
	case 7436ULL: goto x86_l_1d0c;
	case 7441ULL: goto x86_l_1d11;
	case 7446ULL: goto x86_l_1d16;
	case 7449ULL: goto x86_l_1d19;
	case 7451ULL: goto x86_l_1d1b;
	case 7454ULL: goto x86_l_1d1e;
	case 7459ULL: goto x86_l_1d23;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7474ULL: goto x86_l_1d32;
	case 7478ULL: goto x86_l_1d36;
	case 7482ULL: goto x86_l_1d3a;
	case 7488ULL: goto x86_l_1d40;
	case 7498ULL: goto x86_l_1d4a;
	case 7502ULL: goto x86_l_1d4e;
	case 7508ULL: goto x86_l_1d54;
	case 7512ULL: goto x86_l_1d58;
	case 7517ULL: goto x86_l_1d5d;
	case 7520ULL: goto x86_l_1d60;
	case 7524ULL: goto x86_l_1d64;
	case 7528ULL: goto x86_l_1d68;
	case 7534ULL: goto x86_l_1d6e;
	case 7544ULL: goto x86_l_1d78;
	case 7548ULL: goto x86_l_1d7c;
	case 7553ULL: goto x86_l_1d81;
	case 7558ULL: goto x86_l_1d86;
	case 7563ULL: goto x86_l_1d8b;
	case 7568ULL: goto x86_l_1d90;
	case 7570ULL: goto x86_l_1d92;
	case 7575ULL: goto x86_l_1d97;
	case 7580ULL: goto x86_l_1d9c;
	case 7585ULL: goto x86_l_1da1;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7597ULL: goto x86_l_1dad;
	case 7599ULL: goto x86_l_1daf;
	case 7604ULL: goto x86_l_1db4;
	case 7609ULL: goto x86_l_1db9;
	case 7611ULL: goto x86_l_1dbb;
	case 7613ULL: goto x86_l_1dbd;
	case 7618ULL: goto x86_l_1dc2;
	case 7621ULL: goto x86_l_1dc5;
	case 7624ULL: goto x86_l_1dc8;
	case 7630ULL: goto x86_l_1dce;
	case 7636ULL: goto x86_l_1dd4;
	case 7642ULL: goto x86_l_1dda;
	case 7645ULL: goto x86_l_1ddd;
	case 7651ULL: goto x86_l_1de3;
	case 7653ULL: goto x86_l_1de5;
	case 7659ULL: goto x86_l_1deb;
	case 7662ULL: goto x86_l_1dee;
	case 7668ULL: goto x86_l_1df4;
	case 7673ULL: goto x86_l_1df9;
	case 7678ULL: goto x86_l_1dfe;
	case 7682ULL: goto x86_l_1e02;
	case 7685ULL: goto x86_l_1e05;
	case 7691ULL: goto x86_l_1e0b;
	case 7693ULL: goto x86_l_1e0d;
	case 7697ULL: goto x86_l_1e11;
	case 7700ULL: goto x86_l_1e14;
	case 7706ULL: goto x86_l_1e1a;
	case 7710ULL: goto x86_l_1e1e;
	case 7713ULL: goto x86_l_1e21;
	case 7719ULL: goto x86_l_1e27;
	case 7723ULL: goto x86_l_1e2b;
	case 7726ULL: goto x86_l_1e2e;
	case 7728ULL: goto x86_l_1e30;
	case 7731ULL: goto x86_l_1e33;
	case 7734ULL: goto x86_l_1e36;
	case 7736ULL: goto x86_l_1e38;
	case 7740ULL: goto x86_l_1e3c;
	case 7743ULL: goto x86_l_1e3f;
	case 7748ULL: goto x86_l_1e44;
	case 7754ULL: goto x86_l_1e4a;
	case 7759ULL: goto x86_l_1e4f;
	case 7762ULL: goto x86_l_1e52;
	case 7768ULL: goto x86_l_1e58;
	case 7771ULL: goto x86_l_1e5b;
	case 7777ULL: goto x86_l_1e61;
	case 7780ULL: goto x86_l_1e64;
	case 7782ULL: goto x86_l_1e66;
	case 7785ULL: goto x86_l_1e69;
	case 7791ULL: goto x86_l_1e6f;
	case 7795ULL: goto x86_l_1e73;
	case 7798ULL: goto x86_l_1e76;
	case 7804ULL: goto x86_l_1e7c;
	case 7809ULL: goto x86_l_1e81;
	case 7812ULL: goto x86_l_1e84;
	case 7817ULL: goto x86_l_1e89;
	case 7823ULL: goto x86_l_1e8f;
	case 7827ULL: goto x86_l_1e93;
	case 7830ULL: goto x86_l_1e96;
	case 7836ULL: goto x86_l_1e9c;
	case 7841ULL: goto x86_l_1ea1;
	case 7844ULL: goto x86_l_1ea4;
	case 7850ULL: goto x86_l_1eaa;
	case 7854ULL: goto x86_l_1eae;
	case 7857ULL: goto x86_l_1eb1;
	case 7859ULL: goto x86_l_1eb3;
	case 7865ULL: goto x86_l_1eb9;
	case 7870ULL: goto x86_l_1ebe;
	case 7873ULL: goto x86_l_1ec1;
	case 7879ULL: goto x86_l_1ec7;
	case 7883ULL: goto x86_l_1ecb;
	case 7886ULL: goto x86_l_1ece;
	case 7888ULL: goto x86_l_1ed0;
	case 7894ULL: goto x86_l_1ed6;
	case 7899ULL: goto x86_l_1edb;
	case 7902ULL: goto x86_l_1ede;
	case 7908ULL: goto x86_l_1ee4;
	case 7911ULL: goto x86_l_1ee7;
	case 7917ULL: goto x86_l_1eed;
	case 7922ULL: goto x86_l_1ef2;
	case 7927ULL: goto x86_l_1ef7;
	case 7930ULL: goto x86_l_1efa;
	case 7932ULL: goto x86_l_1efc;
	case 7935ULL: goto x86_l_1eff;
	case 7941ULL: goto x86_l_1f05;
	case 7945ULL: goto x86_l_1f09;
	case 7948ULL: goto x86_l_1f0c;
	case 7954ULL: goto x86_l_1f12;
	case 7959ULL: goto x86_l_1f17;
	case 7963ULL: goto x86_l_1f1b;
	case 7967ULL: goto x86_l_1f1f;
	case 7970ULL: goto x86_l_1f22;
	case 7972ULL: goto x86_l_1f24;
	case 7976ULL: goto x86_l_1f28;
	case 7980ULL: goto x86_l_1f2c;
	case 7983ULL: goto x86_l_1f2f;
	case 7987ULL: goto x86_l_1f33;
	case 7991ULL: goto x86_l_1f37;
	case 7995ULL: goto x86_l_1f3b;
	case 7998ULL: goto x86_l_1f3e;
	case 8001ULL: goto x86_l_1f41;
	case 8004ULL: goto x86_l_1f44;
	case 8010ULL: goto x86_l_1f4a;
	case 8014ULL: goto x86_l_1f4e;
	case 8018ULL: goto x86_l_1f52;
	case 8022ULL: goto x86_l_1f56;
	case 8026ULL: goto x86_l_1f5a;
	case 8029ULL: goto x86_l_1f5d;
	case 8032ULL: goto x86_l_1f60;
	case 8035ULL: goto x86_l_1f63;
	case 8041ULL: goto x86_l_1f69;
	case 8045ULL: goto x86_l_1f6d;
	case 8049ULL: goto x86_l_1f71;
	case 8053ULL: goto x86_l_1f75;
	case 8057ULL: goto x86_l_1f79;
	case 8060ULL: goto x86_l_1f7c;
	case 8063ULL: goto x86_l_1f7f;
	case 8066ULL: goto x86_l_1f82;
	case 8072ULL: goto x86_l_1f88;
	case 8076ULL: goto x86_l_1f8c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1938:
	/* 0x1938: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_193c:
	/* 0x193c: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_1941:
	/* 0x1941: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1943:
	/* 0x1943: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1948:
	/* 0x1948: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_194c:
	/* 0x194c: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_1951:
	/* 0x1951: cmp    eax,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_1954:
	/* 0x1954: jne    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 264ULL;
	}
x86_l_195a:
	/* 0x195a: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_195e:
	/* 0x195e: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1961:
	/* 0x1961: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1963:
	/* 0x1963: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_196c:
	/* 0x196c: jne    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 264ULL;
	}
x86_l_1972:
	/* 0x1972: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1976:
	/* 0x1976: mov    rcx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1979:
	/* 0x1979: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_1981:
	/* 0x1981: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1986:
	/* 0x1986: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1989:
	/* 0x1989: andn   rax,rcx,QWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ANDN_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 144ULL);
x86_l_1993:
	/* 0x1993: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_1997:
	/* 0x1997: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_199c:
	/* 0x199c: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_199f:
	/* 0x199f: je     211f <generic_fentry_filter_arg+0x211f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8479ULL;
	}
x86_l_19a5:
	/* 0x19a5: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_19ab:
	/* 0x19ab: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_19ae:
	/* 0x19ae: jne    38d2 <generic_fentry_filter_arg+0x38d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14546ULL;
	}
x86_l_19b4:
	/* 0x19b4: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_19b9:
	/* 0x19b9: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_19bc:
	/* 0x19bc: mov    eax,DWORD PTR [r13+rbx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_19c1:
	/* 0x19c1: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19c5:
	/* 0x19c5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19ca:
	/* 0x19ca: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_19d1:
	/* 0x19d1: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19d6:
	/* 0x19d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d8:
	/* 0x19d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19db:
	/* 0x19db: je     2ead <generic_fentry_filter_arg+0x2ead> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11949ULL;
	}
x86_l_19e1:
	/* 0x19e1: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19e5:
	/* 0x19e5: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_19e8:
	/* 0x19e8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_19eb:
	/* 0x19eb: call   0 <generic_fentry_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 6640ULL);
	return 14707ULL;
x86_l_19f0:
	/* 0x19f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19f2:
	/* 0x19f2: jns    2eb2 <generic_fentry_filter_arg+0x2eb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11954ULL;
	}
x86_l_19f8:
	/* 0x19f8: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_19fc:
	/* 0x19fc: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_19ff:
	/* 0x19ff: cmp    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1a03:
	/* 0x1a03: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a08:
	/* 0x1a08: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a0d:
	/* 0x1a0d: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_1a10:
	/* 0x1a10: jae    2ffd <generic_fentry_filter_arg+0x2ffd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12285ULL;
	}
x86_l_1a16:
	/* 0x1a16: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_1a1c:
	/* 0x1a1c: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_1a23:
	/* 0x1a23: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a28:
	/* 0x1a28: jne    19b9 <generic_fentry_filter_arg+0x19b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19b9;
	}
x86_l_1a2a:
	/* 0x1a2a: jmp    38d2 <generic_fentry_filter_arg+0x38d2> */
	return 14546ULL;
x86_l_1a2f:
	/* 0x1a2f: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a34:
	/* 0x1a34: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a38:
	/* 0x1a38: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1a3b:
	/* 0x1a3b: jne    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 264ULL;
	}
x86_l_1a41:
	/* 0x1a41: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a46:
	/* 0x1a46: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a4a:
	/* 0x1a4a: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a4e:
	/* 0x1a4e: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1a56:
	/* 0x1a56: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a5b:
	/* 0x1a5b: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1a62:
	/* 0x1a62: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a67:
	/* 0x1a67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a69:
	/* 0x1a69: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_1a6c:
	/* 0x1a6c: je     1d5d <generic_fentry_filter_arg+0x1d5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d5d;
	}
x86_l_1a72:
	/* 0x1a72: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1a75:
	/* 0x1a75: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_1a7b:
	/* 0x1a7b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a7e:
	/* 0x1a7e: je     1d60 <generic_fentry_filter_arg+0x1d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d60;
	}
x86_l_1a84:
	/* 0x1a84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a89:
	/* 0x1a89: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1a90:
	/* 0x1a90: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a95:
	/* 0x1a95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a97:
	/* 0x1a97: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a9a:
	/* 0x1a9a: je     1d5d <generic_fentry_filter_arg+0x1d5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d5d;
	}
x86_l_1aa0:
	/* 0x1aa0: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa4:
	/* 0x1aa4: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1aa6:
	/* 0x1aa6: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1aa9:
	/* 0x1aa9: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aab:
	/* 0x1aab: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1aae:
	/* 0x1aae: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1ab2:
	/* 0x1ab2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ab7:
	/* 0x1ab7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1abc:
	/* 0x1abc: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1abf:
	/* 0x1abf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ac1:
	/* 0x1ac1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ac6:
	/* 0x1ac6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ac9:
	/* 0x1ac9: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1acc:
	/* 0x1acc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ace:
	/* 0x1ace: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ad1:
	/* 0x1ad1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ad4:
	/* 0x1ad4: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_1ad8:
	/* 0x1ad8: jmp    1d60 <generic_fentry_filter_arg+0x1d60> */
	goto x86_l_1d60;
x86_l_1add:
	/* 0x1add: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_1ae0:
	/* 0x1ae0: movzx  ebx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ae3:
	/* 0x1ae3: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1ae8:
	/* 0x1ae8: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1aec:
	/* 0x1aec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1af1:
	/* 0x1af1: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1af8:
	/* 0x1af8: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1afd:
	/* 0x1afd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aff:
	/* 0x1aff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b02:
	/* 0x1b02: je     22ff <generic_fentry_filter_arg+0x22ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8959ULL;
	}
x86_l_1b08:
	/* 0x1b08: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b0d:
	/* 0x1b0d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1b12:
	/* 0x1b12: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b15:
	/* 0x1b15: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b1a:
	/* 0x1b1a: jmp    22c9 <generic_fentry_filter_arg+0x22c9> */
	return 8905ULL;
x86_l_1b1f:
	/* 0x1b1f: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b24:
	/* 0x1b24: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b28:
	/* 0x1b28: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b2c:
	/* 0x1b2c: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1b34:
	/* 0x1b34: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b39:
	/* 0x1b39: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1b40:
	/* 0x1b40: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b45:
	/* 0x1b45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b47:
	/* 0x1b47: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1b49:
	/* 0x1b49: je     38c0 <generic_fentry_filter_arg+0x38c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14528ULL;
	}
x86_l_1b4f:
	/* 0x1b4f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1b52:
	/* 0x1b52: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_1b58:
	/* 0x1b58: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b5b:
	/* 0x1b5b: je     38c3 <generic_fentry_filter_arg+0x38c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14531ULL;
	}
x86_l_1b61:
	/* 0x1b61: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b66:
	/* 0x1b66: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1b6d:
	/* 0x1b6d: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b72:
	/* 0x1b72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b74:
	/* 0x1b74: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b77:
	/* 0x1b77: je     38c0 <generic_fentry_filter_arg+0x38c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14528ULL;
	}
x86_l_1b7d:
	/* 0x1b7d: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_1b83:
	/* 0x1b83: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_1b88:
	/* 0x1b88: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_1b8b:
	/* 0x1b8b: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_1b92:
	/* 0x1b92: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b94:
	/* 0x1b94: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b97:
	/* 0x1b97: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1b9b:
	/* 0x1b9b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ba0:
	/* 0x1ba0: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1ba2:
	/* 0x1ba2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ba6:
	/* 0x1ba6: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1ba9:
	/* 0x1ba9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1bab:
	/* 0x1bab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bb0:
	/* 0x1bb0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1bb3:
	/* 0x1bb3: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1bb6:
	/* 0x1bb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb8:
	/* 0x1bb8: jmp    38b4 <generic_fentry_filter_arg+0x38b4> */
	return 14516ULL;
x86_l_1bbd:
	/* 0x1bbd: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1bc5:
	/* 0x1bc5: cmp    ebp,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_1bcb:
	/* 0x1bcb: jbe    21ca <generic_fentry_filter_arg+0x21ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 8650ULL;
	}
x86_l_1bd1:
	/* 0x1bd1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd4:
	/* 0x1bd4: jmp    38d2 <generic_fentry_filter_arg+0x38d2> */
	return 14546ULL;
x86_l_1bd9:
	/* 0x1bd9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bdd:
	/* 0x1bdd: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1be0:
	/* 0x1be0: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1be3:
	/* 0x1be3: ja     1bee <generic_fentry_filter_arg+0x1bee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bee;
	}
x86_l_1be5:
	/* 0x1be5: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1be8:
	/* 0x1be8: jbe    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 697ULL;
	}
x86_l_1bee:
	/* 0x1bee: mov    edx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bf2:
	/* 0x1bf2: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1bf5:
	/* 0x1bf5: jb     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 264ULL;
	}
x86_l_1bfb:
	/* 0x1bfb: mov    rdi,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bff:
	/* 0x1bff: mov    rsi,QWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c03:
	/* 0x1c03: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c06:
	/* 0x1c06: je     1c11 <generic_fentry_filter_arg+0x1c11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c11;
	}
x86_l_1c08:
	/* 0x1c08: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1c0b:
	/* 0x1c0b: jne    2349 <generic_fentry_filter_arg+0x2349> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9033ULL;
	}
x86_l_1c11:
	/* 0x1c11: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1c14:
	/* 0x1c14: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c19:
	/* 0x1c19: jg     235c <generic_fentry_filter_arg+0x235c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9052ULL;
	}
x86_l_1c1f:
	/* 0x1c1f: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_1c22:
	/* 0x1c22: jle    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 697ULL;
	}
x86_l_1c28:
	/* 0x1c28: jmp    235c <generic_fentry_filter_arg+0x235c> */
	return 9052ULL;
x86_l_1c2d:
	/* 0x1c2d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c31:
	/* 0x1c31: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c34:
	/* 0x1c34: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1c37:
	/* 0x1c37: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1c3b:
	/* 0x1c3b: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1c3e:
	/* 0x1c3e: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1c41:
	/* 0x1c41: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1c44:
	/* 0x1c44: mov    esi,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c48:
	/* 0x1c48: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_1c4b:
	/* 0x1c4b: jb     30fa <generic_fentry_filter_arg+0x30fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12538ULL;
	}
x86_l_1c51:
	/* 0x1c51: mov    r8,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c55:
	/* 0x1c55: mov    rdi,QWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c59:
	/* 0x1c59: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c5c:
	/* 0x1c5c: je     1c67 <generic_fentry_filter_arg+0x1c67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c67;
	}
x86_l_1c5e:
	/* 0x1c5e: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1c61:
	/* 0x1c61: jne    222d <generic_fentry_filter_arg+0x222d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8749ULL;
	}
x86_l_1c67:
	/* 0x1c67: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_1c6a:
	/* 0x1c6a: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1c6e:
	/* 0x1c6e: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1c71:
	/* 0x1c71: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1c75:
	/* 0x1c75: jmp    223b <generic_fentry_filter_arg+0x223b> */
	return 8763ULL;
x86_l_1c7a:
	/* 0x1c7a: movzx  r12d,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1c7f:
	/* 0x1c7f: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_1c82:
	/* 0x1c82: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1c87:
	/* 0x1c87: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c8b:
	/* 0x1c8b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c90:
	/* 0x1c90: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1c97:
	/* 0x1c97: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c9c:
	/* 0x1c9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9e:
	/* 0x1c9e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ca1:
	/* 0x1ca1: je     1cf4 <generic_fentry_filter_arg+0x1cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cf4;
	}
x86_l_1ca3:
	/* 0x1ca3: movzx  ecx,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1ca7:
	/* 0x1ca7: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1cac:
	/* 0x1cac: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1cb1:
	/* 0x1cb1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1cb4:
	/* 0x1cb4: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cb9:
	/* 0x1cb9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1cbb:
	/* 0x1cbb: mov    edx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cbf:
	/* 0x1cbf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cc1:
	/* 0x1cc1: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1cc4:
	/* 0x1cc4: ja     344c <generic_fentry_filter_arg+0x344c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13388ULL;
	}
x86_l_1cca:
	/* 0x1cca: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1ccf:
	/* 0x1ccf: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1cd2:
	/* 0x1cd2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd7:
	/* 0x1cd7: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cdc:
	/* 0x1cdc: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_1cdf:
	/* 0x1cdf: jae    168b <generic_fentry_filter_arg+0x168b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5771ULL;
	}
x86_l_1ce5:
	/* 0x1ce5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ce8:
	/* 0x1ce8: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1ceb:
	/* 0x1ceb: movzx  r12d,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1cef:
	/* 0x1cef: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_1cf4:
	/* 0x1cf4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cf7:
	/* 0x1cf7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cfc:
	/* 0x1cfc: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d01:
	/* 0x1d01: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_1d04:
	/* 0x1d04: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_1d09:
	/* 0x1d09: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d0c:
	/* 0x1d0c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d11:
	/* 0x1d11: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d16:
	/* 0x1d16: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_1d19:
	/* 0x1d19: jmp    1d32 <generic_fentry_filter_arg+0x1d32> */
	goto x86_l_1d32;
x86_l_1d1b:
	/* 0x1d1b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d1e:
	/* 0x1d1e: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d23:
	/* 0x1d23: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d28:
	/* 0x1d28: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d2d:
	/* 0x1d2d: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d32:
	/* 0x1d32: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d36:
	/* 0x1d36: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_1d3a:
	/* 0x1d3a: ja     2a8 <generic_fentry_filter_arg+0x2a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 680ULL;
	}
x86_l_1d40:
	/* 0x1d40: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_1d4a:
	/* 0x1d4a: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1d4e:
	/* 0x1d4e: jae    2a8 <generic_fentry_filter_arg+0x2a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 680ULL;
	}
x86_l_1d54:
	/* 0x1d54: xor    r12,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_1d58:
	/* 0x1d58: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_1d5d:
	/* 0x1d5d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d60:
	/* 0x1d60: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d64:
	/* 0x1d64: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_1d68:
	/* 0x1d68: ja     2d49 <generic_fentry_filter_arg+0x2d49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11593ULL;
	}
x86_l_1d6e:
	/* 0x1d6e: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_1d78:
	/* 0x1d78: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1d7c:
	/* 0x1d7c: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d81:
	/* 0x1d81: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d86:
	/* 0x1d86: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d8b:
	/* 0x1d8b: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d90:
	/* 0x1d90: jb     1d54 <generic_fentry_filter_arg+0x1d54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d54;
	}
x86_l_1d92:
	/* 0x1d92: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_1d97:
	/* 0x1d97: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1d9c:
	/* 0x1d9c: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1da1:
	/* 0x1da1: jb     1dce <generic_fentry_filter_arg+0x1dce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1dce;
	}
x86_l_1da3:
	/* 0x1da3: mov    edx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 512ULL);
x86_l_1da8:
	/* 0x1da8: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_1dad:
	/* 0x1dad: jb     1dce <generic_fentry_filter_arg+0x1dce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1dce;
	}
x86_l_1daf:
	/* 0x1daf: mov    edx,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_1db4:
	/* 0x1db4: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_1db9:
	/* 0x1db9: jb     1dce <generic_fentry_filter_arg+0x1dce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1dce;
	}
x86_l_1dbb:
	/* 0x1dbb: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dbd:
	/* 0x1dbd: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_1dc2:
	/* 0x1dc2: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_1dc5:
	/* 0x1dc5: shl    edx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_1dc8:
	/* 0x1dc8: add    edx,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_1dce:
	/* 0x1dce: lea    eax,[rdx-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_1dd4:
	/* 0x1dd4: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_1dda:
	/* 0x1dda: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ddd:
	/* 0x1ddd: jg     2103 <generic_fentry_filter_arg+0x2103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8451ULL;
	}
x86_l_1de3:
	/* 0x1de3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1de5:
	/* 0x1de5: je     2b47 <generic_fentry_filter_arg+0x2b47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11079ULL;
	}
x86_l_1deb:
	/* 0x1deb: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dee:
	/* 0x1dee: jne    2b40 <generic_fentry_filter_arg+0x2b40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11072ULL;
	}
x86_l_1df4:
	/* 0x1df4: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1df9:
	/* 0x1df9: jmp    2b53 <generic_fentry_filter_arg+0x2b53> */
	return 11091ULL;
x86_l_1dfe:
	/* 0x1dfe: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e02:
	/* 0x1e02: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e05:
	/* 0x1e05: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_1e0b:
	/* 0x1e0b: jmp    1e1a <generic_fentry_filter_arg+0x1e1a> */
	goto x86_l_1e1a;
x86_l_1e0d:
	/* 0x1e0d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e11:
	/* 0x1e11: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e14:
	/* 0x1e14: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_1e1a:
	/* 0x1e1a: mov    edx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e1e:
	/* 0x1e1e: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1e21:
	/* 0x1e21: jb     3962 <generic_fentry_filter_arg+0x3962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14690ULL;
	}
x86_l_1e27:
	/* 0x1e27: mov    rsi,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e2b:
	/* 0x1e2b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e2e:
	/* 0x1e2e: jle    1e4f <generic_fentry_filter_arg+0x1e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e4f;
	}
x86_l_1e30:
	/* 0x1e30: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1e33:
	/* 0x1e33: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1e36:
	/* 0x1e36: jae    1e81 <generic_fentry_filter_arg+0x1e81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1e81;
	}
x86_l_1e38:
	/* 0x1e38: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e3c:
	/* 0x1e3c: cmp    QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e3f:
	/* 0x1e3f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e44:
	/* 0x1e44: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 670ULL;
	}
x86_l_1e4a:
	/* 0x1e4a: jmp    2a57 <generic_fentry_filter_arg+0x2a57> */
	return 10839ULL;
x86_l_1e4f:
	/* 0x1e4f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e52:
	/* 0x1e52: je     1ef7 <generic_fentry_filter_arg+0x1ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ef7;
	}
x86_l_1e58:
	/* 0x1e58: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e5b:
	/* 0x1e5b: jne    2a57 <generic_fentry_filter_arg+0x2a57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10839ULL;
	}
x86_l_1e61:
	/* 0x1e61: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1e64:
	/* 0x1e64: je     1e6f <generic_fentry_filter_arg+0x1e6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e6f;
	}
x86_l_1e66:
	/* 0x1e66: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1e69:
	/* 0x1e69: jne    2a4a <generic_fentry_filter_arg+0x2a4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10826ULL;
	}
x86_l_1e6f:
	/* 0x1e6f: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e73:
	/* 0x1e73: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e76:
	/* 0x1e76: jl     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 697ULL;
	}
x86_l_1e7c:
	/* 0x1e7c: jmp    2a57 <generic_fentry_filter_arg+0x2a57> */
	return 10839ULL;
x86_l_1e81:
	/* 0x1e81: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1e84:
	/* 0x1e84: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e89:
	/* 0x1e89: jne    2a57 <generic_fentry_filter_arg+0x2a57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10839ULL;
	}
x86_l_1e8f:
	/* 0x1e8f: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e93:
	/* 0x1e93: test   QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e96:
	/* 0x1e96: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_1e9c:
	/* 0x1e9c: jmp    2a57 <generic_fentry_filter_arg+0x2a57> */
	return 10839ULL;
x86_l_1ea1:
	/* 0x1ea1: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1ea4:
	/* 0x1ea4: jne    1fd2 <generic_fentry_filter_arg+0x1fd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8146ULL;
	}
x86_l_1eaa:
	/* 0x1eaa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eae:
	/* 0x1eae: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1eb1:
	/* 0x1eb1: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1eb3:
	/* 0x1eb3: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_1eb9:
	/* 0x1eb9: jmp    1fd2 <generic_fentry_filter_arg+0x1fd2> */
	return 8146ULL;
x86_l_1ebe:
	/* 0x1ebe: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1ec1:
	/* 0x1ec1: jne    201b <generic_fentry_filter_arg+0x201b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8219ULL;
	}
x86_l_1ec7:
	/* 0x1ec7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ecb:
	/* 0x1ecb: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ece:
	/* 0x1ece: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1ed0:
	/* 0x1ed0: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_1ed6:
	/* 0x1ed6: jmp    201b <generic_fentry_filter_arg+0x201b> */
	return 8219ULL;
x86_l_1edb:
	/* 0x1edb: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1ede:
	/* 0x1ede: je     24fc <generic_fentry_filter_arg+0x24fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9468ULL;
	}
x86_l_1ee4:
	/* 0x1ee4: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1ee7:
	/* 0x1ee7: jne    24ee <generic_fentry_filter_arg+0x24ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9454ULL;
	}
x86_l_1eed:
	/* 0x1eed: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_1ef2:
	/* 0x1ef2: jmp    2501 <generic_fentry_filter_arg+0x2501> */
	return 9473ULL;
x86_l_1ef7:
	/* 0x1ef7: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1efa:
	/* 0x1efa: je     1f05 <generic_fentry_filter_arg+0x1f05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f05;
	}
x86_l_1efc:
	/* 0x1efc: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1eff:
	/* 0x1eff: jne    2a3b <generic_fentry_filter_arg+0x2a3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10811ULL;
	}
x86_l_1f05:
	/* 0x1f05: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f09:
	/* 0x1f09: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f0c:
	/* 0x1f0c: jg     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 697ULL;
	}
x86_l_1f12:
	/* 0x1f12: jmp    2a57 <generic_fentry_filter_arg+0x2a57> */
	return 10839ULL;
x86_l_1f17:
	/* 0x1f17: mov    edx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f1b:
	/* 0x1f1b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f1f:
	/* 0x1f1f: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1f22:
	/* 0x1f22: jmp    1f2f <generic_fentry_filter_arg+0x1f2f> */
	goto x86_l_1f2f;
x86_l_1f24:
	/* 0x1f24: mov    edx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f28:
	/* 0x1f28: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f2c:
	/* 0x1f2c: movzx  ecx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f2f:
	/* 0x1f2f: cmp    DWORD PTR [r13+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f33:
	/* 0x1f33: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1f37:
	/* 0x1f37: cmp    DWORD PTR [r13+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1f3b:
	/* 0x1f3b: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_1f3e:
	/* 0x1f3e: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f41:
	/* 0x1f41: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1f44:
	/* 0x1f44: jb     30fa <generic_fentry_filter_arg+0x30fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12538ULL;
	}
x86_l_1f4a:
	/* 0x1f4a: cmp    DWORD PTR [r13+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f4e:
	/* 0x1f4e: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1f52:
	/* 0x1f52: cmp    DWORD PTR [r13+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f56:
	/* 0x1f56: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1f5a:
	/* 0x1f5a: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f5d:
	/* 0x1f5d: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f60:
	/* 0x1f60: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1f63:
	/* 0x1f63: jb     30f5 <generic_fentry_filter_arg+0x30f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12533ULL;
	}
x86_l_1f69:
	/* 0x1f69: cmp    DWORD PTR [r13+0x20],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f6d:
	/* 0x1f6d: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1f71:
	/* 0x1f71: cmp    DWORD PTR [r13+0x24],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f75:
	/* 0x1f75: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1f79:
	/* 0x1f79: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f7c:
	/* 0x1f7c: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f7f:
	/* 0x1f7f: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1f82:
	/* 0x1f82: jb     30f5 <generic_fentry_filter_arg+0x30f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12533ULL;
	}
x86_l_1f88:
	/* 0x1f88: cmp    DWORD PTR [r13+0x28],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f8c:
	/* 0x1f8c: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
	return 8079ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8079ULL: goto x86_l_1f8f;
	case 8083ULL: goto x86_l_1f93;
	case 8086ULL: goto x86_l_1f96;
	case 8088ULL: goto x86_l_1f98;
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8098ULL: goto x86_l_1fa2;
	case 8104ULL: goto x86_l_1fa8;
	case 8107ULL: goto x86_l_1fab;
	case 8113ULL: goto x86_l_1fb1;
	case 8118ULL: goto x86_l_1fb6;
	case 8123ULL: goto x86_l_1fbb;
	case 8126ULL: goto x86_l_1fbe;
	case 8131ULL: goto x86_l_1fc3;
	case 8135ULL: goto x86_l_1fc7;
	case 8138ULL: goto x86_l_1fca;
	case 8140ULL: goto x86_l_1fcc;
	case 8146ULL: goto x86_l_1fd2;
	case 8150ULL: goto x86_l_1fd6;
	case 8153ULL: goto x86_l_1fd9;
	case 8159ULL: goto x86_l_1fdf;
	case 8163ULL: goto x86_l_1fe3;
	case 8166ULL: goto x86_l_1fe6;
	case 8172ULL: goto x86_l_1fec;
	case 8175ULL: goto x86_l_1fef;
	case 8178ULL: goto x86_l_1ff2;
	case 8184ULL: goto x86_l_1ff8;
	case 8188ULL: goto x86_l_1ffc;
	case 8191ULL: goto x86_l_1fff;
	case 8193ULL: goto x86_l_2001;
	case 8199ULL: goto x86_l_2007;
	case 8204ULL: goto x86_l_200c;
	case 8208ULL: goto x86_l_2010;
	case 8211ULL: goto x86_l_2013;
	case 8213ULL: goto x86_l_2015;
	case 8219ULL: goto x86_l_201b;
	case 8223ULL: goto x86_l_201f;
	case 8226ULL: goto x86_l_2022;
	case 8232ULL: goto x86_l_2028;
	case 8236ULL: goto x86_l_202c;
	case 8239ULL: goto x86_l_202f;
	case 8245ULL: goto x86_l_2035;
	case 8248ULL: goto x86_l_2038;
	case 8251ULL: goto x86_l_203b;
	case 8257ULL: goto x86_l_2041;
	case 8261ULL: goto x86_l_2045;
	case 8264ULL: goto x86_l_2048;
	case 8266ULL: goto x86_l_204a;
	case 8272ULL: goto x86_l_2050;
	case 8277ULL: goto x86_l_2055;
	case 8281ULL: goto x86_l_2059;
	case 8283ULL: goto x86_l_205b;
	case 8285ULL: goto x86_l_205d;
	case 8287ULL: goto x86_l_205f;
	case 8289ULL: goto x86_l_2061;
	case 8295ULL: goto x86_l_2067;
	case 8299ULL: goto x86_l_206b;
	case 8302ULL: goto x86_l_206e;
	case 8308ULL: goto x86_l_2074;
	case 8312ULL: goto x86_l_2078;
	case 8316ULL: goto x86_l_207c;
	case 8319ULL: goto x86_l_207f;
	case 8325ULL: goto x86_l_2085;
	case 8331ULL: goto x86_l_208b;
	case 8335ULL: goto x86_l_208f;
	case 8341ULL: goto x86_l_2095;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8354ULL: goto x86_l_20a2;
	case 8356ULL: goto x86_l_20a4;
	case 8362ULL: goto x86_l_20aa;
	case 8367ULL: goto x86_l_20af;
	case 8371ULL: goto x86_l_20b3;
	case 8373ULL: goto x86_l_20b5;
	case 8375ULL: goto x86_l_20b7;
	case 8379ULL: goto x86_l_20bb;
	case 8381ULL: goto x86_l_20bd;
	case 8384ULL: goto x86_l_20c0;
	case 8387ULL: goto x86_l_20c3;
	case 8391ULL: goto x86_l_20c7;
	case 8394ULL: goto x86_l_20ca;
	case 8400ULL: goto x86_l_20d0;
	case 8404ULL: goto x86_l_20d4;
	case 8408ULL: goto x86_l_20d8;
	case 8411ULL: goto x86_l_20db;
	case 8417ULL: goto x86_l_20e1;
	case 8423ULL: goto x86_l_20e7;
	case 8427ULL: goto x86_l_20eb;
	case 8433ULL: goto x86_l_20f1;
	case 8436ULL: goto x86_l_20f4;
	case 8440ULL: goto x86_l_20f8;
	case 8442ULL: goto x86_l_20fa;
	case 8446ULL: goto x86_l_20fe;
	case 8451ULL: goto x86_l_2103;
	case 8454ULL: goto x86_l_2106;
	case 8460ULL: goto x86_l_210c;
	case 8463ULL: goto x86_l_210f;
	case 8469ULL: goto x86_l_2115;
	case 8474ULL: goto x86_l_211a;
	case 8479ULL: goto x86_l_211f;
	case 8481ULL: goto x86_l_2121;
	case 8484ULL: goto x86_l_2124;
	case 8487ULL: goto x86_l_2127;
	case 8492ULL: goto x86_l_212c;
	case 8496ULL: goto x86_l_2130;
	case 8501ULL: goto x86_l_2135;
	case 8508ULL: goto x86_l_213c;
	case 8513ULL: goto x86_l_2141;
	case 8515ULL: goto x86_l_2143;
	case 8518ULL: goto x86_l_2146;
	case 8524ULL: goto x86_l_214c;
	case 8526ULL: goto x86_l_214e;
	case 8531ULL: goto x86_l_2153;
	case 8534ULL: goto x86_l_2156;
	case 8539ULL: goto x86_l_215b;
	case 8541ULL: goto x86_l_215d;
	case 8545ULL: goto x86_l_2161;
	case 8547ULL: goto x86_l_2163;
	case 8549ULL: goto x86_l_2165;
	case 8552ULL: goto x86_l_2168;
	case 8555ULL: goto x86_l_216b;
	case 8558ULL: goto x86_l_216e;
	case 8560ULL: goto x86_l_2170;
	case 8562ULL: goto x86_l_2172;
	case 8566ULL: goto x86_l_2176;
	case 8569ULL: goto x86_l_2179;
	case 8571ULL: goto x86_l_217b;
	case 8575ULL: goto x86_l_217f;
	case 8578ULL: goto x86_l_2182;
	case 8580ULL: goto x86_l_2184;
	case 8584ULL: goto x86_l_2188;
	case 8586ULL: goto x86_l_218a;
	case 8590ULL: goto x86_l_218e;
	case 8594ULL: goto x86_l_2192;
	case 8597ULL: goto x86_l_2195;
	case 8599ULL: goto x86_l_2197;
	case 8601ULL: goto x86_l_2199;
	case 8603ULL: goto x86_l_219b;
	case 8609ULL: goto x86_l_21a1;
	case 8614ULL: goto x86_l_21a6;
	case 8618ULL: goto x86_l_21aa;
	case 8620ULL: goto x86_l_21ac;
	case 8624ULL: goto x86_l_21b0;
	case 8627ULL: goto x86_l_21b3;
	case 8631ULL: goto x86_l_21b7;
	case 8637ULL: goto x86_l_21bd;
	case 8640ULL: goto x86_l_21c0;
	case 8645ULL: goto x86_l_21c5;
	case 8650ULL: goto x86_l_21ca;
	case 8653ULL: goto x86_l_21cd;
	case 8658ULL: goto x86_l_21d2;
	case 8663ULL: goto x86_l_21d7;
	case 8669ULL: goto x86_l_21dd;
	case 8673ULL: goto x86_l_21e1;
	case 8679ULL: goto x86_l_21e7;
	case 8682ULL: goto x86_l_21ea;
	case 8685ULL: goto x86_l_21ed;
	case 8688ULL: goto x86_l_21f0;
	case 8690ULL: goto x86_l_21f2;
	case 8693ULL: goto x86_l_21f5;
	case 8695ULL: goto x86_l_21f7;
	case 8697ULL: goto x86_l_21f9;
	case 8699ULL: goto x86_l_21fb;
	case 8701ULL: goto x86_l_21fd;
	case 8703ULL: goto x86_l_21ff;
	case 8706ULL: goto x86_l_2202;
	case 8708ULL: goto x86_l_2204;
	case 8710ULL: goto x86_l_2206;
	case 8712ULL: goto x86_l_2208;
	case 8715ULL: goto x86_l_220b;
	case 8718ULL: goto x86_l_220e;
	case 8722ULL: goto x86_l_2212;
	case 8728ULL: goto x86_l_2218;
	case 8730ULL: goto x86_l_221a;
	case 8733ULL: goto x86_l_221d;
	case 8739ULL: goto x86_l_2223;
	case 8742ULL: goto x86_l_2226;
	case 8744ULL: goto x86_l_2228;
	case 8749ULL: goto x86_l_222d;
	case 8752ULL: goto x86_l_2230;
	case 8756ULL: goto x86_l_2234;
	case 8759ULL: goto x86_l_2237;
	case 8763ULL: goto x86_l_223b;
	case 8766ULL: goto x86_l_223e;
	case 8769ULL: goto x86_l_2241;
	case 8772ULL: goto x86_l_2244;
	case 8778ULL: goto x86_l_224a;
	case 8782ULL: goto x86_l_224e;
	case 8786ULL: goto x86_l_2252;
	case 8789ULL: goto x86_l_2255;
	case 8791ULL: goto x86_l_2257;
	case 8794ULL: goto x86_l_225a;
	case 8800ULL: goto x86_l_2260;
	case 8803ULL: goto x86_l_2263;
	case 8807ULL: goto x86_l_2267;
	case 8810ULL: goto x86_l_226a;
	case 8814ULL: goto x86_l_226e;
	case 8819ULL: goto x86_l_2273;
	case 8821ULL: goto x86_l_2275;
	case 8824ULL: goto x86_l_2278;
	case 8826ULL: goto x86_l_227a;
	case 8829ULL: goto x86_l_227d;
	case 8831ULL: goto x86_l_227f;
	case 8835ULL: goto x86_l_2283;
	case 8838ULL: goto x86_l_2286;
	case 8840ULL: goto x86_l_2288;
	case 8843ULL: goto x86_l_228b;
	case 8849ULL: goto x86_l_2291;
	case 8852ULL: goto x86_l_2294;
	case 8857ULL: goto x86_l_2299;
	case 8861ULL: goto x86_l_229d;
	case 8866ULL: goto x86_l_22a2;
	case 8873ULL: goto x86_l_22a9;
	case 8878ULL: goto x86_l_22ae;
	case 8880ULL: goto x86_l_22b0;
	case 8883ULL: goto x86_l_22b3;
	case 8885ULL: goto x86_l_22b5;
	case 8887ULL: goto x86_l_22b7;
	case 8892ULL: goto x86_l_22bc;
	case 8897ULL: goto x86_l_22c1;
	case 8900ULL: goto x86_l_22c4;
	case 8905ULL: goto x86_l_22c9;
	case 8907ULL: goto x86_l_22cb;
	case 8911ULL: goto x86_l_22cf;
	case 8913ULL: goto x86_l_22d1;
	case 8916ULL: goto x86_l_22d4;
	case 8922ULL: goto x86_l_22da;
	case 8927ULL: goto x86_l_22df;
	case 8930ULL: goto x86_l_22e2;
	case 8935ULL: goto x86_l_22e7;
	case 8940ULL: goto x86_l_22ec;
	case 8945ULL: goto x86_l_22f1;
	case 8948ULL: goto x86_l_22f4;
	case 8954ULL: goto x86_l_22fa;
	case 8959ULL: goto x86_l_22ff;
	case 8962ULL: goto x86_l_2302;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8975ULL: goto x86_l_230f;
	case 8980ULL: goto x86_l_2314;
	case 8985ULL: goto x86_l_2319;
	case 8988ULL: goto x86_l_231c;
	case 8993ULL: goto x86_l_2321;
	case 8998ULL: goto x86_l_2326;
	case 9002ULL: goto x86_l_232a;
	case 9006ULL: goto x86_l_232e;
	case 9012ULL: goto x86_l_2334;
	case 9017ULL: goto x86_l_2339;
	case 9020ULL: goto x86_l_233c;
	case 9023ULL: goto x86_l_233f;
	case 9028ULL: goto x86_l_2344;
	case 9033ULL: goto x86_l_2349;
	case 9036ULL: goto x86_l_234c;
	case 9041ULL: goto x86_l_2351;
	case 9043ULL: goto x86_l_2353;
	case 9046ULL: goto x86_l_2356;
	case 9052ULL: goto x86_l_235c;
	case 9055ULL: goto x86_l_235f;
	case 9061ULL: goto x86_l_2365;
	case 9065ULL: goto x86_l_2369;
	case 9069ULL: goto x86_l_236d;
	case 9072ULL: goto x86_l_2370;
	case 9074ULL: goto x86_l_2372;
	case 9077ULL: goto x86_l_2375;
	case 9083ULL: goto x86_l_237b;
	case 9086ULL: goto x86_l_237e;
	case 9091ULL: goto x86_l_2383;
	case 9097ULL: goto x86_l_2389;
	case 9100ULL: goto x86_l_238c;
	case 9106ULL: goto x86_l_2392;
	case 9111ULL: goto x86_l_2397;
	case 9115ULL: goto x86_l_239b;
	case 9118ULL: goto x86_l_239e;
	case 9121ULL: goto x86_l_23a1;
	case 9124ULL: goto x86_l_23a4;
	case 9126ULL: goto x86_l_23a6;
	case 9130ULL: goto x86_l_23aa;
	case 9133ULL: goto x86_l_23ad;
	case 9136ULL: goto x86_l_23b0;
	case 9139ULL: goto x86_l_23b3;
	case 9144ULL: goto x86_l_23b8;
	case 9149ULL: goto x86_l_23bd;
	case 9154ULL: goto x86_l_23c2;
	case 9159ULL: goto x86_l_23c7;
	case 9163ULL: goto x86_l_23cb;
	case 9168ULL: goto x86_l_23d0;
	case 9172ULL: goto x86_l_23d4;
	case 9174ULL: goto x86_l_23d6;
	case 9180ULL: goto x86_l_23dc;
	case 9182ULL: goto x86_l_23de;
	case 9186ULL: goto x86_l_23e2;
	case 9188ULL: goto x86_l_23e4;
	case 9194ULL: goto x86_l_23ea;
	case 9198ULL: goto x86_l_23ee;
	case 9201ULL: goto x86_l_23f1;
	case 9207ULL: goto x86_l_23f7;
	case 9211ULL: goto x86_l_23fb;
	case 9214ULL: goto x86_l_23fe;
	case 9216ULL: goto x86_l_2400;
	case 9219ULL: goto x86_l_2403;
	case 9222ULL: goto x86_l_2406;
	case 9224ULL: goto x86_l_2408;
	case 9228ULL: goto x86_l_240c;
	case 9230ULL: goto x86_l_240e;
	case 9235ULL: goto x86_l_2413;
	case 9241ULL: goto x86_l_2419;
	case 9246ULL: goto x86_l_241e;
	case 9249ULL: goto x86_l_2421;
	case 9251ULL: goto x86_l_2423;
	case 9254ULL: goto x86_l_2426;
	case 9260ULL: goto x86_l_242c;
	case 9263ULL: goto x86_l_242f;
	case 9269ULL: goto x86_l_2435;
	case 9275ULL: goto x86_l_243b;
	case 9279ULL: goto x86_l_243f;
	case 9285ULL: goto x86_l_2445;
	case 9289ULL: goto x86_l_2449;
	case 9292ULL: goto x86_l_244c;
	case 9298ULL: goto x86_l_2452;
	case 9303ULL: goto x86_l_2457;
	case 9306ULL: goto x86_l_245a;
	case 9311ULL: goto x86_l_245f;
	case 9317ULL: goto x86_l_2465;
	case 9321ULL: goto x86_l_2469;
	case 9324ULL: goto x86_l_246c;
	case 9330ULL: goto x86_l_2472;
	case 9335ULL: goto x86_l_2477;
	case 9338ULL: goto x86_l_247a;
	case 9344ULL: goto x86_l_2480;
	case 9350ULL: goto x86_l_2486;
	case 9354ULL: goto x86_l_248a;
	case 9360ULL: goto x86_l_2490;
	case 9364ULL: goto x86_l_2494;
	case 9367ULL: goto x86_l_2497;
	case 9373ULL: goto x86_l_249d;
	case 9378ULL: goto x86_l_24a2;
	case 9381ULL: goto x86_l_24a5;
	case 9387ULL: goto x86_l_24ab;
	case 9390ULL: goto x86_l_24ae;
	case 9396ULL: goto x86_l_24b4;
	case 9400ULL: goto x86_l_24b8;
	case 9403ULL: goto x86_l_24bb;
	case 9405ULL: goto x86_l_24bd;
	case 9411ULL: goto x86_l_24c3;
	case 9416ULL: goto x86_l_24c8;
	case 9419ULL: goto x86_l_24cb;
	case 9425ULL: goto x86_l_24d1;
	case 9428ULL: goto x86_l_24d4;
	case 9434ULL: goto x86_l_24da;
	case 9438ULL: goto x86_l_24de;
	case 9441ULL: goto x86_l_24e1;
	case 9443ULL: goto x86_l_24e3;
	case 9449ULL: goto x86_l_24e9;
	case 9454ULL: goto x86_l_24ee;
	case 9459ULL: goto x86_l_24f3;
	case 9461ULL: goto x86_l_24f5;
	case 9466ULL: goto x86_l_24fa;
	case 9468ULL: goto x86_l_24fc;
	case 9473ULL: goto x86_l_2501;
	case 9475ULL: goto x86_l_2503;
	case 9478ULL: goto x86_l_2506;
	case 9483ULL: goto x86_l_250b;
	case 9486ULL: goto x86_l_250e;
	case 9492ULL: goto x86_l_2514;
	case 9496ULL: goto x86_l_2518;
	case 9503ULL: goto x86_l_251f;
	case 9508ULL: goto x86_l_2524;
	case 9513ULL: goto x86_l_2529;
	case 9520ULL: goto x86_l_2530;
	case 9525ULL: goto x86_l_2535;
	case 9528ULL: goto x86_l_2538;
	case 9530ULL: goto x86_l_253a;
	case 9533ULL: goto x86_l_253d;
	case 9538ULL: goto x86_l_2542;
	case 9545ULL: goto x86_l_2549;
	case 9548ULL: goto x86_l_254c;
	case 9550ULL: goto x86_l_254e;
	case 9555ULL: goto x86_l_2553;
	case 9558ULL: goto x86_l_2556;
	case 9564ULL: goto x86_l_255c;
	case 9570ULL: goto x86_l_2562;
	case 9573ULL: goto x86_l_2565;
	case 9578ULL: goto x86_l_256a;
	case 9583ULL: goto x86_l_256f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1f8f:
	/* 0x1f8f: cmp    DWORD PTR [r13+0x2c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1f93:
	/* 0x1f93: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_1f96:
	/* 0x1f96: and    cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f98:
	/* 0x1f98: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f9a:
	/* 0x1f9a: jmp    30f5 <generic_fentry_filter_arg+0x30f5> */
	return 12533ULL;
x86_l_1f9f:
	/* 0x1f9f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1fa2:
	/* 0x1fa2: je     274f <generic_fentry_filter_arg+0x274f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10063ULL;
	}
x86_l_1fa8:
	/* 0x1fa8: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1fab:
	/* 0x1fab: jne    2741 <generic_fentry_filter_arg+0x2741> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10049ULL;
	}
x86_l_1fb1:
	/* 0x1fb1: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_1fb6:
	/* 0x1fb6: jmp    2754 <generic_fentry_filter_arg+0x2754> */
	return 10068ULL;
x86_l_1fbb:
	/* 0x1fbb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fbe:
	/* 0x1fbe: jmp    23a1 <generic_fentry_filter_arg+0x23a1> */
	goto x86_l_23a1;
x86_l_1fc3:
	/* 0x1fc3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fc7:
	/* 0x1fc7: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1fca:
	/* 0x1fca: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1fcc:
	/* 0x1fcc: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_1fd2:
	/* 0x1fd2: mov    ecx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fd6:
	/* 0x1fd6: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1fd9:
	/* 0x1fd9: jb     3962 <generic_fentry_filter_arg+0x3962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14690ULL;
	}
x86_l_1fdf:
	/* 0x1fdf: mov    edx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1fe3:
	/* 0x1fe3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1fe6:
	/* 0x1fe6: jle    24a2 <generic_fentry_filter_arg+0x24a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_24a2;
	}
x86_l_1fec:
	/* 0x1fec: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1fef:
	/* 0x1fef: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1ff2:
	/* 0x1ff2: jae    2ada <generic_fentry_filter_arg+0x2ada> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10970ULL;
	}
x86_l_1ff8:
	/* 0x1ff8: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ffc:
	/* 0x1ffc: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1fff:
	/* 0x1fff: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2001:
	/* 0x2001: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 670ULL;
	}
x86_l_2007:
	/* 0x2007: jmp    2d7e <generic_fentry_filter_arg+0x2d7e> */
	return 11646ULL;
x86_l_200c:
	/* 0x200c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2010:
	/* 0x2010: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2013:
	/* 0x2013: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2015:
	/* 0x2015: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_201b:
	/* 0x201b: mov    ecx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_201f:
	/* 0x201f: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_2022:
	/* 0x2022: jb     3962 <generic_fentry_filter_arg+0x3962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14690ULL;
	}
x86_l_2028:
	/* 0x2028: mov    edx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_202c:
	/* 0x202c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_202f:
	/* 0x202f: jle    24c8 <generic_fentry_filter_arg+0x24c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_24c8;
	}
x86_l_2035:
	/* 0x2035: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2038:
	/* 0x2038: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_203b:
	/* 0x203b: jae    2af7 <generic_fentry_filter_arg+0x2af7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10999ULL;
	}
x86_l_2041:
	/* 0x2041: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2045:
	/* 0x2045: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2048:
	/* 0x2048: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_204a:
	/* 0x204a: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 670ULL;
	}
x86_l_2050:
	/* 0x2050: jmp    2dc3 <generic_fentry_filter_arg+0x2dc3> */
	return 11715ULL;
x86_l_2055:
	/* 0x2055: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2059:
	/* 0x2059: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_205b:
	/* 0x205b: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_205d:
	/* 0x205d: ja     2067 <generic_fentry_filter_arg+0x2067> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2067;
	}
x86_l_205f:
	/* 0x205f: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2061:
	/* 0x2061: jbe    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 697ULL;
	}
x86_l_2067:
	/* 0x2067: mov    edx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_206b:
	/* 0x206b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_206e:
	/* 0x206e: jb     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 264ULL;
	}
x86_l_2074:
	/* 0x2074: mov    edi,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2078:
	/* 0x2078: mov    esi,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_207c:
	/* 0x207c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_207f:
	/* 0x207f: ja     28f4 <generic_fentry_filter_arg+0x28f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10484ULL;
	}
x86_l_2085:
	/* 0x2085: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_208b:
	/* 0x208b: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_208f:
	/* 0x208f: jae    28f4 <generic_fentry_filter_arg+0x28f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10484ULL;
	}
x86_l_2095:
	/* 0x2095: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2097:
	/* 0x2097: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_209c:
	/* 0x209c: jg     2905 <generic_fentry_filter_arg+0x2905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10501ULL;
	}
x86_l_20a2:
	/* 0x20a2: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_20a4:
	/* 0x20a4: jle    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 697ULL;
	}
x86_l_20aa:
	/* 0x20aa: jmp    2905 <generic_fentry_filter_arg+0x2905> */
	return 10501ULL;
x86_l_20af:
	/* 0x20af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b3:
	/* 0x20b3: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b5:
	/* 0x20b5: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_20b7:
	/* 0x20b7: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_20bb:
	/* 0x20bb: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_20bd:
	/* 0x20bd: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_20c0:
	/* 0x20c0: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_20c3:
	/* 0x20c3: mov    esi,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20c7:
	/* 0x20c7: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_20ca:
	/* 0x20ca: jb     30fa <generic_fentry_filter_arg+0x30fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12538ULL;
	}
x86_l_20d0:
	/* 0x20d0: mov    r8d,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20d4:
	/* 0x20d4: mov    edi,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20d8:
	/* 0x20d8: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_20db:
	/* 0x20db: ja     26e5 <generic_fentry_filter_arg+0x26e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9957ULL;
	}
x86_l_20e1:
	/* 0x20e1: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_20e7:
	/* 0x20e7: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_20eb:
	/* 0x20eb: jae    26e5 <generic_fentry_filter_arg+0x26e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9957ULL;
	}
x86_l_20f1:
	/* 0x20f1: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_20f4:
	/* 0x20f4: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_20f8:
	/* 0x20f8: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_20fa:
	/* 0x20fa: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_20fe:
	/* 0x20fe: jmp    26f2 <generic_fentry_filter_arg+0x26f2> */
	return 9970ULL;
x86_l_2103:
	/* 0x2103: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2106:
	/* 0x2106: je     2b4e <generic_fentry_filter_arg+0x2b4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11086ULL;
	}
x86_l_210c:
	/* 0x210c: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_210f:
	/* 0x210f: jne    2b40 <generic_fentry_filter_arg+0x2b40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11072ULL;
	}
x86_l_2115:
	/* 0x2115: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_211a:
	/* 0x211a: jmp    2b53 <generic_fentry_filter_arg+0x2b53> */
	return 11091ULL;
x86_l_211f:
	/* 0x211f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2121:
	/* 0x2121: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2124:
	/* 0x2124: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_2127:
	/* 0x2127: mov    eax,DWORD PTR [r13+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_212c:
	/* 0x212c: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2130:
	/* 0x2130: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2135:
	/* 0x2135: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_213c:
	/* 0x213c: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2141:
	/* 0x2141: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2143:
	/* 0x2143: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2146:
	/* 0x2146: je     2df9 <generic_fentry_filter_arg+0x2df9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11769ULL;
	}
x86_l_214c:
	/* 0x214c: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_214e:
	/* 0x214e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2153:
	/* 0x2153: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_2156:
	/* 0x2156: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_215b:
	/* 0x215b: je     21a1 <generic_fentry_filter_arg+0x21a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21a1;
	}
x86_l_215d:
	/* 0x215d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2161:
	/* 0x2161: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2163:
	/* 0x2163: jmp    2170 <generic_fentry_filter_arg+0x2170> */
	goto x86_l_2170;
x86_l_2165:
	/* 0x2165: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2168:
	/* 0x2168: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_216b:
	/* 0x216b: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_216e:
	/* 0x216e: je     21a1 <generic_fentry_filter_arg+0x21a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21a1;
	}
x86_l_2170:
	/* 0x2170: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2172:
	/* 0x2172: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_2176:
	/* 0x2176: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2179:
	/* 0x2179: jae    2165 <generic_fentry_filter_arg+0x2165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2165;
	}
x86_l_217b:
	/* 0x217b: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_217f:
	/* 0x217f: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_2182:
	/* 0x2182: je     2199 <generic_fentry_filter_arg+0x2199> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2199;
	}
x86_l_2184:
	/* 0x2184: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_2188:
	/* 0x2188: ja     2165 <generic_fentry_filter_arg+0x2165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2165;
	}
x86_l_218a:
	/* 0x218a: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_218e:
	/* 0x218e: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_2192:
	/* 0x2192: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_2195:
	/* 0x2195: je     2172 <generic_fentry_filter_arg+0x2172> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2172;
	}
x86_l_2197:
	/* 0x2197: jmp    2165 <generic_fentry_filter_arg+0x2165> */
	goto x86_l_2165;
x86_l_2199:
	/* 0x2199: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_219b:
	/* 0x219b: jns    30d7 <generic_fentry_filter_arg+0x30d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12503ULL;
	}
x86_l_21a1:
	/* 0x21a1: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_21a6:
	/* 0x21a6: cmp    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_21aa:
	/* 0x21aa: jae    21bd <generic_fentry_filter_arg+0x21bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_21bd;
	}
x86_l_21ac:
	/* 0x21ac: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_21b0:
	/* 0x21b0: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_21b3:
	/* 0x21b3: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_21b7:
	/* 0x21b7: jne    2124 <generic_fentry_filter_arg+0x2124> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2124;
	}
x86_l_21bd:
	/* 0x21bd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21c0:
	/* 0x21c0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21c5:
	/* 0x21c5: jmp    38d2 <generic_fentry_filter_arg+0x38d2> */
	return 14546ULL;
x86_l_21ca:
	/* 0x21ca: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_21cd:
	/* 0x21cd: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_21d2:
	/* 0x21d2: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21d7:
	/* 0x21d7: ja     2949 <generic_fentry_filter_arg+0x2949> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10569ULL;
	}
x86_l_21dd:
	/* 0x21dd: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_21e1:
	/* 0x21e1: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_21e7:
	/* 0x21e7: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_21ea:
	/* 0x21ea: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_21ed:
	/* 0x21ed: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_21f0:
	/* 0x21f0: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_21f2:
	/* 0x21f2: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_21f5:
	/* 0x21f5: je     21ff <generic_fentry_filter_arg+0x21ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21ff;
	}
x86_l_21f7:
	/* 0x21f7: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_21f9:
	/* 0x21f9: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_21fb:
	/* 0x21fb: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_21fd:
	/* 0x21fd: je     221a <generic_fentry_filter_arg+0x221a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_221a;
	}
x86_l_21ff:
	/* 0x21ff: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2202:
	/* 0x2202: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2204:
	/* 0x2204: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2206:
	/* 0x2206: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2208:
	/* 0x2208: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_220b:
	/* 0x220b: movzx  esi,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_220e:
	/* 0x220e: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2212:
	/* 0x2212: ja     2981 <generic_fentry_filter_arg+0x2981> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10625ULL;
	}
x86_l_2218:
	/* 0x2218: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_221a:
	/* 0x221a: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_221d:
	/* 0x221d: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2223:
	/* 0x2223: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2226:
	/* 0x2226: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2228:
	/* 0x2228: jmp    3295 <generic_fentry_filter_arg+0x3295> */
	return 12949ULL;
x86_l_222d:
	/* 0x222d: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_2230:
	/* 0x2230: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2234:
	/* 0x2234: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2237:
	/* 0x2237: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_223b:
	/* 0x223b: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_223e:
	/* 0x223e: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2241:
	/* 0x2241: cmp    esi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 41ULL);
x86_l_2244:
	/* 0x2244: jb     30f5 <generic_fentry_filter_arg+0x30f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12533ULL;
	}
x86_l_224a:
	/* 0x224a: mov    r8,QWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_224e:
	/* 0x224e: mov    rdi,QWORD PTR [r13+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2252:
	/* 0x2252: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2255:
	/* 0x2255: je     2260 <generic_fentry_filter_arg+0x2260> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2260;
	}
x86_l_2257:
	/* 0x2257: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_225a:
	/* 0x225a: jne    29b1 <generic_fentry_filter_arg+0x29b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10673ULL;
	}
x86_l_2260:
	/* 0x2260: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_2263:
	/* 0x2263: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2267:
	/* 0x2267: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_226a:
	/* 0x226a: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_226e:
	/* 0x226e: jmp    29bf <generic_fentry_filter_arg+0x29bf> */
	return 10687ULL;
x86_l_2273:
	/* 0x2273: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2275:
	/* 0x2275: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2278:
	/* 0x2278: jne    2283 <generic_fentry_filter_arg+0x2283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2283;
	}
x86_l_227a:
	/* 0x227a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_227d:
	/* 0x227d: je     2283 <generic_fentry_filter_arg+0x2283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2283;
	}
x86_l_227f:
	/* 0x227f: movzx  ebx,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_2283:
	/* 0x2283: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2286:
	/* 0x2286: je     2291 <generic_fentry_filter_arg+0x2291> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2291;
	}
x86_l_2288:
	/* 0x2288: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_228b:
	/* 0x228b: jne    2734 <generic_fentry_filter_arg+0x2734> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10036ULL;
	}
x86_l_2291:
	/* 0x2291: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_2294:
	/* 0x2294: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2299:
	/* 0x2299: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_229d:
	/* 0x229d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22a2:
	/* 0x22a2: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_22a9:
	/* 0x22a9: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22ae:
	/* 0x22ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22b0:
	/* 0x22b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22b3:
	/* 0x22b3: je     22ff <generic_fentry_filter_arg+0x22ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22ff;
	}
x86_l_22b5:
	/* 0x22b5: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_22b7:
	/* 0x22b7: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_22bc:
	/* 0x22bc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_22c1:
	/* 0x22c1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_22c4:
	/* 0x22c4: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22c9:
	/* 0x22c9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_22cb:
	/* 0x22cb: mov    edx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_22cf:
	/* 0x22cf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22d1:
	/* 0x22d1: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_22d4:
	/* 0x22d4: ja     3447 <generic_fentry_filter_arg+0x3447> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13383ULL;
	}
x86_l_22da:
	/* 0x22da: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_22df:
	/* 0x22df: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_22e2:
	/* 0x22e2: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22e7:
	/* 0x22e7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ec:
	/* 0x22ec: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22f1:
	/* 0x22f1: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_22f4:
	/* 0x22f4: jb     1ce5 <generic_fentry_filter_arg+0x1ce5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7397ULL;
	}
x86_l_22fa:
	/* 0x22fa: jmp    168b <generic_fentry_filter_arg+0x168b> */
	return 5771ULL;
x86_l_22ff:
	/* 0x22ff: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2302:
	/* 0x2302: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2307:
	/* 0x2307: jmp    1cf7 <generic_fentry_filter_arg+0x1cf7> */
	return 7415ULL;
x86_l_230c:
	/* 0x230c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_230f:
	/* 0x230f: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2314:
	/* 0x2314: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2319:
	/* 0x2319: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_231c:
	/* 0x231c: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2321:
	/* 0x2321: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2326:
	/* 0x2326: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_232a:
	/* 0x232a: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_232e:
	/* 0x232e: jbe    35cd <generic_fentry_filter_arg+0x35cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13773ULL;
	}
x86_l_2334:
	/* 0x2334: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_2339:
	/* 0x2339: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_233c:
	/* 0x233c: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_233f:
	/* 0x233f: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2344:
	/* 0x2344: jmp    26c3 <generic_fentry_filter_arg+0x26c3> */
	return 9923ULL;
x86_l_2349:
	/* 0x2349: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_234c:
	/* 0x234c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2351:
	/* 0x2351: ja     235c <generic_fentry_filter_arg+0x235c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_235c;
	}
x86_l_2353:
	/* 0x2353: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_2356:
	/* 0x2356: jbe    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 697ULL;
	}
x86_l_235c:
	/* 0x235c: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_235f:
	/* 0x235f: jb     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 264ULL;
	}
x86_l_2365:
	/* 0x2365: mov    rdi,QWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2369:
	/* 0x2369: mov    rsi,QWORD PTR [r13+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_236d:
	/* 0x236d: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2370:
	/* 0x2370: je     237b <generic_fentry_filter_arg+0x237b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_237b;
	}
x86_l_2372:
	/* 0x2372: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2375:
	/* 0x2375: jne    29f2 <generic_fentry_filter_arg+0x29f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10738ULL;
	}
x86_l_237b:
	/* 0x237b: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_237e:
	/* 0x237e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2383:
	/* 0x2383: jg     2a05 <generic_fentry_filter_arg+0x2a05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10757ULL;
	}
x86_l_2389:
	/* 0x2389: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_238c:
	/* 0x238c: jle    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 697ULL;
	}
x86_l_2392:
	/* 0x2392: jmp    2a05 <generic_fentry_filter_arg+0x2a05> */
	return 10757ULL;
x86_l_2397:
	/* 0x2397: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_239b:
	/* 0x239b: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_239e:
	/* 0x239e: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_23a1:
	/* 0x23a1: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_23a4:
	/* 0x23a4: jmp    23b8 <generic_fentry_filter_arg+0x23b8> */
	goto x86_l_23b8;
x86_l_23a6:
	/* 0x23a6: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_23aa:
	/* 0x23aa: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_23ad:
	/* 0x23ad: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_23b0:
	/* 0x23b0: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_23b3:
	/* 0x23b3: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23b8:
	/* 0x23b8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23bd:
	/* 0x23bd: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23c2:
	/* 0x23c2: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23c7:
	/* 0x23c7: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_23cb:
	/* 0x23cb: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_23d0:
	/* 0x23d0: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23d4:
	/* 0x23d4: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23d6:
	/* 0x23d6: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_23dc:
	/* 0x23dc: jmp    23ea <generic_fentry_filter_arg+0x23ea> */
	goto x86_l_23ea;
x86_l_23de:
	/* 0x23de: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23e2:
	/* 0x23e2: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23e4:
	/* 0x23e4: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_23ea:
	/* 0x23ea: mov    edx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ee:
	/* 0x23ee: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_23f1:
	/* 0x23f1: jb     3962 <generic_fentry_filter_arg+0x3962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14690ULL;
	}
x86_l_23f7:
	/* 0x23f7: mov    esi,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_23fb:
	/* 0x23fb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23fe:
	/* 0x23fe: jle    241e <generic_fentry_filter_arg+0x241e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_241e;
	}
x86_l_2400:
	/* 0x2400: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2403:
	/* 0x2403: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2406:
	/* 0x2406: jae    2457 <generic_fentry_filter_arg+0x2457> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2457;
	}
x86_l_2408:
	/* 0x2408: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_240c:
	/* 0x240c: cmp    DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_240e:
	/* 0x240e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2413:
	/* 0x2413: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 670ULL;
	}
x86_l_2419:
	/* 0x2419: jmp    2f3b <generic_fentry_filter_arg+0x2f3b> */
	return 12091ULL;
x86_l_241e:
	/* 0x241e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2421:
	/* 0x2421: je     2477 <generic_fentry_filter_arg+0x2477> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2477;
	}
x86_l_2423:
	/* 0x2423: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2426:
	/* 0x2426: jne    2f3b <generic_fentry_filter_arg+0x2f3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12091ULL;
	}
x86_l_242c:
	/* 0x242c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_242f:
	/* 0x242f: ja     2f2e <generic_fentry_filter_arg+0x2f2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12078ULL;
	}
x86_l_2435:
	/* 0x2435: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_243b:
	/* 0x243b: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_243f:
	/* 0x243f: jae    2f2e <generic_fentry_filter_arg+0x2f2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12078ULL;
	}
x86_l_2445:
	/* 0x2445: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2449:
	/* 0x2449: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_244c:
	/* 0x244c: jl     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 697ULL;
	}
x86_l_2452:
	/* 0x2452: jmp    2f3b <generic_fentry_filter_arg+0x2f3b> */
	return 12091ULL;
x86_l_2457:
	/* 0x2457: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_245a:
	/* 0x245a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_245f:
	/* 0x245f: jne    2f3b <generic_fentry_filter_arg+0x2f3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12091ULL;
	}
x86_l_2465:
	/* 0x2465: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2469:
	/* 0x2469: test   DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_246c:
	/* 0x246c: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_2472:
	/* 0x2472: jmp    2f3b <generic_fentry_filter_arg+0x2f3b> */
	return 12091ULL;
x86_l_2477:
	/* 0x2477: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_247a:
	/* 0x247a: ja     2f1f <generic_fentry_filter_arg+0x2f1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12063ULL;
	}
x86_l_2480:
	/* 0x2480: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2486:
	/* 0x2486: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_248a:
	/* 0x248a: jae    2f1f <generic_fentry_filter_arg+0x2f1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12063ULL;
	}
x86_l_2490:
	/* 0x2490: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2494:
	/* 0x2494: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2497:
	/* 0x2497: jg     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 697ULL;
	}
x86_l_249d:
	/* 0x249d: jmp    2f3b <generic_fentry_filter_arg+0x2f3b> */
	return 12091ULL;
x86_l_24a2:
	/* 0x24a2: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24a5:
	/* 0x24a5: je     2d6f <generic_fentry_filter_arg+0x2d6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11631ULL;
	}
x86_l_24ab:
	/* 0x24ab: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_24ae:
	/* 0x24ae: jne    2d7e <generic_fentry_filter_arg+0x2d7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11646ULL;
	}
x86_l_24b4:
	/* 0x24b4: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24b8:
	/* 0x24b8: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_24bb:
	/* 0x24bb: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_24bd:
	/* 0x24bd: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_24c3:
	/* 0x24c3: jmp    2d7e <generic_fentry_filter_arg+0x2d7e> */
	return 11646ULL;
x86_l_24c8:
	/* 0x24c8: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24cb:
	/* 0x24cb: je     2db4 <generic_fentry_filter_arg+0x2db4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11700ULL;
	}
x86_l_24d1:
	/* 0x24d1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_24d4:
	/* 0x24d4: jne    2dc3 <generic_fentry_filter_arg+0x2dc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11715ULL;
	}
x86_l_24da:
	/* 0x24da: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24de:
	/* 0x24de: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24e1:
	/* 0x24e1: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_24e3:
	/* 0x24e3: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_24e9:
	/* 0x24e9: jmp    2dc3 <generic_fentry_filter_arg+0x2dc3> */
	return 11715ULL;
x86_l_24ee:
	/* 0x24ee: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_24f3:
	/* 0x24f3: jmp    2501 <generic_fentry_filter_arg+0x2501> */
	goto x86_l_2501;
x86_l_24f5:
	/* 0x24f5: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_24fa:
	/* 0x24fa: jmp    2501 <generic_fentry_filter_arg+0x2501> */
	goto x86_l_2501;
x86_l_24fc:
	/* 0x24fc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2501:
	/* 0x2501: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2503:
	/* 0x2503: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2506:
	/* 0x2506: mov    eax,DWORD PTR [r13+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_250b:
	/* 0x250b: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_250e:
	/* 0x250e: je     3266 <generic_fentry_filter_arg+0x3266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12902ULL;
	}
x86_l_2514:
	/* 0x2514: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2518:
	/* 0x2518: mov    DWORD PTR [rsp+0x90],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_251f:
	/* 0x251f: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2524:
	/* 0x2524: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2529:
	/* 0x2529: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2530:
	/* 0x2530: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2535:
	/* 0x2535: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2538:
	/* 0x2538: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253a:
	/* 0x253a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_253d:
	/* 0x253d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2542:
	/* 0x2542: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2549:
	/* 0x2549: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_254c:
	/* 0x254c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254e:
	/* 0x254e: mov    QWORD PTR [rsp+0x28],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2553:
	/* 0x2553: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2556:
	/* 0x2556: je     3266 <generic_fentry_filter_arg+0x3266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12902ULL;
	}
x86_l_255c:
	/* 0x255c: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_2562:
	/* 0x2562: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2565:
	/* 0x2565: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_256a:
	/* 0x256a: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_256f:
	/* 0x256f: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
	return 9588ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9588ULL: goto x86_l_2574;
	case 9594ULL: goto x86_l_257a;
	case 9602ULL: goto x86_l_2582;
	case 9606ULL: goto x86_l_2586;
	case 9610ULL: goto x86_l_258a;
	case 9617ULL: goto x86_l_2591;
	case 9620ULL: goto x86_l_2594;
	case 9622ULL: goto x86_l_2596;
	case 9627ULL: goto x86_l_259b;
	case 9630ULL: goto x86_l_259e;
	case 9634ULL: goto x86_l_25a2;
	case 9639ULL: goto x86_l_25a7;
	case 9641ULL: goto x86_l_25a9;
	case 9643ULL: goto x86_l_25ab;
	case 9648ULL: goto x86_l_25b0;
	case 9650ULL: goto x86_l_25b2;
	case 9655ULL: goto x86_l_25b7;
	case 9657ULL: goto x86_l_25b9;
	case 9662ULL: goto x86_l_25be;
	case 9666ULL: goto x86_l_25c2;
	case 9669ULL: goto x86_l_25c5;
	case 9675ULL: goto x86_l_25cb;
	case 9680ULL: goto x86_l_25d0;
	case 9682ULL: goto x86_l_25d2;
	case 9687ULL: goto x86_l_25d7;
	case 9690ULL: goto x86_l_25da;
	case 9694ULL: goto x86_l_25de;
	case 9699ULL: goto x86_l_25e3;
	case 9701ULL: goto x86_l_25e5;
	case 9703ULL: goto x86_l_25e7;
	case 9708ULL: goto x86_l_25ec;
	case 9710ULL: goto x86_l_25ee;
	case 9715ULL: goto x86_l_25f3;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9726ULL: goto x86_l_25fe;
	case 9730ULL: goto x86_l_2602;
	case 9736ULL: goto x86_l_2608;
	case 9741ULL: goto x86_l_260d;
	case 9749ULL: goto x86_l_2615;
	case 9751ULL: goto x86_l_2617;
	case 9756ULL: goto x86_l_261c;
	case 9759ULL: goto x86_l_261f;
	case 9764ULL: goto x86_l_2624;
	case 9769ULL: goto x86_l_2629;
	case 9774ULL: goto x86_l_262e;
	case 9776ULL: goto x86_l_2630;
	case 9779ULL: goto x86_l_2633;
	case 9785ULL: goto x86_l_2639;
	case 9788ULL: goto x86_l_263c;
	case 9794ULL: goto x86_l_2642;
	case 9797ULL: goto x86_l_2645;
	case 9803ULL: goto x86_l_264b;
	case 9806ULL: goto x86_l_264e;
	case 9812ULL: goto x86_l_2654;
	case 9817ULL: goto x86_l_2659;
	case 9824ULL: goto x86_l_2660;
	case 9829ULL: goto x86_l_2665;
	case 9832ULL: goto x86_l_2668;
	case 9838ULL: goto x86_l_266e;
	case 9841ULL: goto x86_l_2671;
	case 9847ULL: goto x86_l_2677;
	case 9850ULL: goto x86_l_267a;
	case 9856ULL: goto x86_l_2680;
	case 9859ULL: goto x86_l_2683;
	case 9865ULL: goto x86_l_2689;
	case 9870ULL: goto x86_l_268e;
	case 9877ULL: goto x86_l_2695;
	case 9882ULL: goto x86_l_269a;
	case 9888ULL: goto x86_l_26a0;
	case 9893ULL: goto x86_l_26a5;
	case 9898ULL: goto x86_l_26aa;
	case 9902ULL: goto x86_l_26ae;
	case 9906ULL: goto x86_l_26b2;
	case 9912ULL: goto x86_l_26b8;
	case 9917ULL: goto x86_l_26bd;
	case 9923ULL: goto x86_l_26c3;
	case 9928ULL: goto x86_l_26c8;
	case 9933ULL: goto x86_l_26cd;
	case 9938ULL: goto x86_l_26d2;
	case 9942ULL: goto x86_l_26d6;
	case 9946ULL: goto x86_l_26da;
	case 9952ULL: goto x86_l_26e0;
	case 9957ULL: goto x86_l_26e5;
	case 9960ULL: goto x86_l_26e8;
	case 9964ULL: goto x86_l_26ec;
	case 9966ULL: goto x86_l_26ee;
	case 9970ULL: goto x86_l_26f2;
	case 9973ULL: goto x86_l_26f5;
	case 9976ULL: goto x86_l_26f8;
	case 9979ULL: goto x86_l_26fb;
	case 9985ULL: goto x86_l_2701;
	case 9989ULL: goto x86_l_2705;
	case 9993ULL: goto x86_l_2709;
	case 9996ULL: goto x86_l_270c;
	case 10002ULL: goto x86_l_2712;
	case 10008ULL: goto x86_l_2718;
	case 10012ULL: goto x86_l_271c;
	case 10018ULL: goto x86_l_2722;
	case 10021ULL: goto x86_l_2725;
	case 10025ULL: goto x86_l_2729;
	case 10027ULL: goto x86_l_272b;
	case 10031ULL: goto x86_l_272f;
	case 10036ULL: goto x86_l_2734;
	case 10039ULL: goto x86_l_2737;
	case 10044ULL: goto x86_l_273c;
	case 10049ULL: goto x86_l_2741;
	case 10054ULL: goto x86_l_2746;
	case 10056ULL: goto x86_l_2748;
	case 10061ULL: goto x86_l_274d;
	case 10063ULL: goto x86_l_274f;
	case 10068ULL: goto x86_l_2754;
	case 10070ULL: goto x86_l_2756;
	case 10073ULL: goto x86_l_2759;
	case 10078ULL: goto x86_l_275e;
	case 10081ULL: goto x86_l_2761;
	case 10087ULL: goto x86_l_2767;
	case 10091ULL: goto x86_l_276b;
	case 10096ULL: goto x86_l_2770;
	case 10104ULL: goto x86_l_2778;
	case 10109ULL: goto x86_l_277d;
	case 10113ULL: goto x86_l_2781;
	case 10118ULL: goto x86_l_2786;
	case 10123ULL: goto x86_l_278b;
	case 10130ULL: goto x86_l_2792;
	case 10135ULL: goto x86_l_2797;
	case 10138ULL: goto x86_l_279a;
	case 10140ULL: goto x86_l_279c;
	case 10143ULL: goto x86_l_279f;
	case 10148ULL: goto x86_l_27a4;
	case 10155ULL: goto x86_l_27ab;
	case 10158ULL: goto x86_l_27ae;
	case 10160ULL: goto x86_l_27b0;
	case 10163ULL: goto x86_l_27b3;
	case 10169ULL: goto x86_l_27b9;
	case 10175ULL: goto x86_l_27bf;
	case 10178ULL: goto x86_l_27c2;
	case 10183ULL: goto x86_l_27c7;
	case 10188ULL: goto x86_l_27cc;
	case 10193ULL: goto x86_l_27d1;
	case 10199ULL: goto x86_l_27d7;
	case 10202ULL: goto x86_l_27da;
	case 10210ULL: goto x86_l_27e2;
	case 10213ULL: goto x86_l_27e5;
	case 10215ULL: goto x86_l_27e7;
	case 10218ULL: goto x86_l_27ea;
	case 10226ULL: goto x86_l_27f2;
	case 10228ULL: goto x86_l_27f4;
	case 10232ULL: goto x86_l_27f8;
	case 10237ULL: goto x86_l_27fd;
	case 10241ULL: goto x86_l_2801;
	case 10244ULL: goto x86_l_2804;
	case 10249ULL: goto x86_l_2809;
	case 10251ULL: goto x86_l_280b;
	case 10256ULL: goto x86_l_2810;
	case 10259ULL: goto x86_l_2813;
	case 10261ULL: goto x86_l_2815;
	case 10265ULL: goto x86_l_2819;
	case 10268ULL: goto x86_l_281c;
	case 10274ULL: goto x86_l_2822;
	case 10279ULL: goto x86_l_2827;
	case 10281ULL: goto x86_l_2829;
	case 10285ULL: goto x86_l_282d;
	case 10288ULL: goto x86_l_2830;
	case 10292ULL: goto x86_l_2834;
	case 10296ULL: goto x86_l_2838;
	case 10301ULL: goto x86_l_283d;
	case 10304ULL: goto x86_l_2840;
	case 10309ULL: goto x86_l_2845;
	case 10311ULL: goto x86_l_2847;
	case 10316ULL: goto x86_l_284c;
	case 10319ULL: goto x86_l_284f;
	case 10321ULL: goto x86_l_2851;
	case 10325ULL: goto x86_l_2855;
	case 10329ULL: goto x86_l_2859;
	case 10335ULL: goto x86_l_285f;
	case 10340ULL: goto x86_l_2864;
	case 10348ULL: goto x86_l_286c;
	case 10350ULL: goto x86_l_286e;
	case 10354ULL: goto x86_l_2872;
	case 10358ULL: goto x86_l_2876;
	case 10361ULL: goto x86_l_2879;
	case 10366ULL: goto x86_l_287e;
	case 10371ULL: goto x86_l_2883;
	case 10376ULL: goto x86_l_2888;
	case 10378ULL: goto x86_l_288a;
	case 10381ULL: goto x86_l_288d;
	case 10387ULL: goto x86_l_2893;
	case 10390ULL: goto x86_l_2896;
	case 10396ULL: goto x86_l_289c;
	case 10399ULL: goto x86_l_289f;
	case 10405ULL: goto x86_l_28a5;
	case 10408ULL: goto x86_l_28a8;
	case 10414ULL: goto x86_l_28ae;
	case 10419ULL: goto x86_l_28b3;
	case 10426ULL: goto x86_l_28ba;
	case 10431ULL: goto x86_l_28bf;
	case 10434ULL: goto x86_l_28c2;
	case 10440ULL: goto x86_l_28c8;
	case 10443ULL: goto x86_l_28cb;
	case 10449ULL: goto x86_l_28d1;
	case 10452ULL: goto x86_l_28d4;
	case 10458ULL: goto x86_l_28da;
	case 10461ULL: goto x86_l_28dd;
	case 10467ULL: goto x86_l_28e3;
	case 10472ULL: goto x86_l_28e8;
	case 10479ULL: goto x86_l_28ef;
	case 10484ULL: goto x86_l_28f4;
	case 10486ULL: goto x86_l_28f6;
	case 10491ULL: goto x86_l_28fb;
	case 10493ULL: goto x86_l_28fd;
	case 10495ULL: goto x86_l_28ff;
	case 10501ULL: goto x86_l_2905;
	case 10504ULL: goto x86_l_2908;
	case 10510ULL: goto x86_l_290e;
	case 10514ULL: goto x86_l_2912;
	case 10518ULL: goto x86_l_2916;
	case 10521ULL: goto x86_l_2919;
	case 10527ULL: goto x86_l_291f;
	case 10533ULL: goto x86_l_2925;
	case 10537ULL: goto x86_l_2929;
	case 10543ULL: goto x86_l_292f;
	case 10545ULL: goto x86_l_2931;
	case 10550ULL: goto x86_l_2936;
	case 10556ULL: goto x86_l_293c;
	case 10558ULL: goto x86_l_293e;
	case 10564ULL: goto x86_l_2944;
	case 10569ULL: goto x86_l_2949;
	case 10574ULL: goto x86_l_294e;
	case 10579ULL: goto x86_l_2953;
	case 10581ULL: goto x86_l_2955;
	case 10586ULL: goto x86_l_295a;
	case 10591ULL: goto x86_l_295f;
	case 10593ULL: goto x86_l_2961;
	case 10598ULL: goto x86_l_2966;
	case 10603ULL: goto x86_l_296b;
	case 10605ULL: goto x86_l_296d;
	case 10607ULL: goto x86_l_296f;
	case 10612ULL: goto x86_l_2974;
	case 10616ULL: goto x86_l_2978;
	case 10619ULL: goto x86_l_297b;
	case 10625ULL: goto x86_l_2981;
	case 10631ULL: goto x86_l_2987;
	case 10637ULL: goto x86_l_298d;
	case 10640ULL: goto x86_l_2990;
	case 10646ULL: goto x86_l_2996;
	case 10648ULL: goto x86_l_2998;
	case 10654ULL: goto x86_l_299e;
	case 10657ULL: goto x86_l_29a1;
	case 10663ULL: goto x86_l_29a7;
	case 10668ULL: goto x86_l_29ac;
	case 10673ULL: goto x86_l_29b1;
	case 10676ULL: goto x86_l_29b4;
	case 10680ULL: goto x86_l_29b8;
	case 10683ULL: goto x86_l_29bb;
	case 10687ULL: goto x86_l_29bf;
	case 10690ULL: goto x86_l_29c2;
	case 10693ULL: goto x86_l_29c5;
	case 10696ULL: goto x86_l_29c8;
	case 10702ULL: goto x86_l_29ce;
	case 10706ULL: goto x86_l_29d2;
	case 10710ULL: goto x86_l_29d6;
	case 10713ULL: goto x86_l_29d9;
	case 10715ULL: goto x86_l_29db;
	case 10718ULL: goto x86_l_29de;
	case 10724ULL: goto x86_l_29e4;
	case 10727ULL: goto x86_l_29e7;
	case 10730ULL: goto x86_l_29ea;
	case 10733ULL: goto x86_l_29ed;
	case 10738ULL: goto x86_l_29f2;
	case 10741ULL: goto x86_l_29f5;
	case 10746ULL: goto x86_l_29fa;
	case 10748ULL: goto x86_l_29fc;
	case 10751ULL: goto x86_l_29ff;
	case 10757ULL: goto x86_l_2a05;
	case 10760ULL: goto x86_l_2a08;
	case 10766ULL: goto x86_l_2a0e;
	case 10770ULL: goto x86_l_2a12;
	case 10774ULL: goto x86_l_2a16;
	case 10777ULL: goto x86_l_2a19;
	case 10779ULL: goto x86_l_2a1b;
	case 10782ULL: goto x86_l_2a1e;
	case 10788ULL: goto x86_l_2a24;
	case 10791ULL: goto x86_l_2a27;
	case 10797ULL: goto x86_l_2a2d;
	case 10800ULL: goto x86_l_2a30;
	case 10806ULL: goto x86_l_2a36;
	case 10811ULL: goto x86_l_2a3b;
	case 10815ULL: goto x86_l_2a3f;
	case 10818ULL: goto x86_l_2a42;
	case 10824ULL: goto x86_l_2a48;
	case 10826ULL: goto x86_l_2a4a;
	case 10830ULL: goto x86_l_2a4e;
	case 10833ULL: goto x86_l_2a51;
	case 10839ULL: goto x86_l_2a57;
	case 10842ULL: goto x86_l_2a5a;
	case 10848ULL: goto x86_l_2a60;
	case 10852ULL: goto x86_l_2a64;
	case 10855ULL: goto x86_l_2a67;
	case 10857ULL: goto x86_l_2a69;
	case 10860ULL: goto x86_l_2a6c;
	case 10863ULL: goto x86_l_2a6f;
	case 10865ULL: goto x86_l_2a71;
	case 10869ULL: goto x86_l_2a75;
	case 10872ULL: goto x86_l_2a78;
	case 10877ULL: goto x86_l_2a7d;
	case 10883ULL: goto x86_l_2a83;
	case 10888ULL: goto x86_l_2a88;
	case 10891ULL: goto x86_l_2a8b;
	case 10897ULL: goto x86_l_2a91;
	case 10900ULL: goto x86_l_2a94;
	case 10906ULL: goto x86_l_2a9a;
	case 10909ULL: goto x86_l_2a9d;
	case 10911ULL: goto x86_l_2a9f;
	case 10914ULL: goto x86_l_2aa2;
	case 10920ULL: goto x86_l_2aa8;
	case 10924ULL: goto x86_l_2aac;
	case 10927ULL: goto x86_l_2aaf;
	case 10933ULL: goto x86_l_2ab5;
	case 10938ULL: goto x86_l_2aba;
	case 10941ULL: goto x86_l_2abd;
	case 10946ULL: goto x86_l_2ac2;
	case 10952ULL: goto x86_l_2ac8;
	case 10956ULL: goto x86_l_2acc;
	case 10959ULL: goto x86_l_2acf;
	case 10965ULL: goto x86_l_2ad5;
	case 10970ULL: goto x86_l_2ada;
	case 10973ULL: goto x86_l_2add;
	case 10979ULL: goto x86_l_2ae3;
	case 10983ULL: goto x86_l_2ae7;
	case 10986ULL: goto x86_l_2aea;
	case 10988ULL: goto x86_l_2aec;
	case 10994ULL: goto x86_l_2af2;
	case 10999ULL: goto x86_l_2af7;
	case 11002ULL: goto x86_l_2afa;
	case 11008ULL: goto x86_l_2b00;
	case 11012ULL: goto x86_l_2b04;
	case 11015ULL: goto x86_l_2b07;
	case 11017ULL: goto x86_l_2b09;
	case 11023ULL: goto x86_l_2b0f;
	case 11028ULL: goto x86_l_2b14;
	case 11031ULL: goto x86_l_2b17;
	case 11037ULL: goto x86_l_2b1d;
	case 11040ULL: goto x86_l_2b20;
	case 11046ULL: goto x86_l_2b26;
	case 11049ULL: goto x86_l_2b29;
	case 11055ULL: goto x86_l_2b2f;
	case 11060ULL: goto x86_l_2b34;
	case 11067ULL: goto x86_l_2b3b;
	case 11072ULL: goto x86_l_2b40;
	case 11077ULL: goto x86_l_2b45;
	case 11079ULL: goto x86_l_2b47;
	case 11084ULL: goto x86_l_2b4c;
	case 11086ULL: goto x86_l_2b4e;
	case 11091ULL: goto x86_l_2b53;
	case 11093ULL: goto x86_l_2b55;
	case 11096ULL: goto x86_l_2b58;
	case 11101ULL: goto x86_l_2b5d;
	case 11104ULL: goto x86_l_2b60;
	case 11110ULL: goto x86_l_2b66;
	case 11114ULL: goto x86_l_2b6a;
	case 11118ULL: goto x86_l_2b6e;
	case 11126ULL: goto x86_l_2b76;
	case 11130ULL: goto x86_l_2b7a;
	case 11135ULL: goto x86_l_2b7f;
	case 11140ULL: goto x86_l_2b84;
	case 11147ULL: goto x86_l_2b8b;
	case 11152ULL: goto x86_l_2b90;
	case 11155ULL: goto x86_l_2b93;
	case 11157ULL: goto x86_l_2b95;
	case 11160ULL: goto x86_l_2b98;
	case 11165ULL: goto x86_l_2b9d;
	case 11172ULL: goto x86_l_2ba4;
	case 11175ULL: goto x86_l_2ba7;
	case 11177ULL: goto x86_l_2ba9;
	case 11182ULL: goto x86_l_2bae;
	case 11185ULL: goto x86_l_2bb1;
	case 11191ULL: goto x86_l_2bb7;
	case 11197ULL: goto x86_l_2bbd;
	case 11200ULL: goto x86_l_2bc0;
	case 11205ULL: goto x86_l_2bc5;
	case 11210ULL: goto x86_l_2bca;
	case 11215ULL: goto x86_l_2bcf;
	case 11221ULL: goto x86_l_2bd5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2574:
	/* 0x2574: je     3278 <generic_fentry_filter_arg+0x3278> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12920ULL;
	}
x86_l_257a:
	/* 0x257a: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2582:
	/* 0x2582: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2586:
	/* 0x2586: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_258a:
	/* 0x258a: mov    ebx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2591:
	/* 0x2591: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2594:
	/* 0x2594: jg     25d2 <generic_fentry_filter_arg+0x25d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_25d2;
	}
x86_l_2596:
	/* 0x2596: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_259b:
	/* 0x259b: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_259e:
	/* 0x259e: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_25a2:
	/* 0x25a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25a7:
	/* 0x25a7: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_25a9:
	/* 0x25a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ab:
	/* 0x25ab: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25b0:
	/* 0x25b0: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25b2:
	/* 0x25b2: mov    r12d,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_25b7:
	/* 0x25b7: jbe    2617 <generic_fentry_filter_arg+0x2617> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2617;
	}
x86_l_25b9:
	/* 0x25b9: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25be:
	/* 0x25be: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_25c2:
	/* 0x25c2: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_25c5:
	/* 0x25c5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25cb:
	/* 0x25cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25d0:
	/* 0x25d0: jmp    260d <generic_fentry_filter_arg+0x260d> */
	goto x86_l_260d;
x86_l_25d2:
	/* 0x25d2: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25d7:
	/* 0x25d7: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25da:
	/* 0x25da: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_25de:
	/* 0x25de: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25e3:
	/* 0x25e3: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_25e5:
	/* 0x25e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25e7:
	/* 0x25e7: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25ec:
	/* 0x25ec: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25ee:
	/* 0x25ee: mov    r12d,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_25f3:
	/* 0x25f3: jbe    2617 <generic_fentry_filter_arg+0x2617> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2617;
	}
x86_l_25f5:
	/* 0x25f5: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25fa:
	/* 0x25fa: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_25fe:
	/* 0x25fe: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2602:
	/* 0x2602: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2608:
	/* 0x2608: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_260d:
	/* 0x260d: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2615:
	/* 0x2615: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2617:
	/* 0x2617: mov    DWORD PTR [rsp+0x50],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_261c:
	/* 0x261c: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_261f:
	/* 0x261f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2624:
	/* 0x2624: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2629:
	/* 0x2629: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_262e:
	/* 0x262e: jle    2665 <generic_fentry_filter_arg+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2665;
	}
x86_l_2630:
	/* 0x2630: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2633:
	/* 0x2633: jg     2b14 <generic_fentry_filter_arg+0x2b14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b14;
	}
x86_l_2639:
	/* 0x2639: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_263c:
	/* 0x263c: je     3225 <generic_fentry_filter_arg+0x3225> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12837ULL;
	}
x86_l_2642:
	/* 0x2642: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2645:
	/* 0x2645: je     31fb <generic_fentry_filter_arg+0x31fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12795ULL;
	}
x86_l_264b:
	/* 0x264b: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_264e:
	/* 0x264e: jne    957 <generic_fentry_filter_arg+0x957> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2391ULL;
	}
x86_l_2654:
	/* 0x2654: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2659:
	/* 0x2659: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2660:
	/* 0x2660: jmp    323f <generic_fentry_filter_arg+0x323f> */
	return 12863ULL;
x86_l_2665:
	/* 0x2665: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2668:
	/* 0x2668: jle    2e13 <generic_fentry_filter_arg+0x2e13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11795ULL;
	}
x86_l_266e:
	/* 0x266e: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_2671:
	/* 0x2671: je     3217 <generic_fentry_filter_arg+0x3217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12823ULL;
	}
x86_l_2677:
	/* 0x2677: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_267a:
	/* 0x267a: je     31ed <generic_fentry_filter_arg+0x31ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12781ULL;
	}
x86_l_2680:
	/* 0x2680: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2683:
	/* 0x2683: jne    957 <generic_fentry_filter_arg+0x957> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2391ULL;
	}
x86_l_2689:
	/* 0x2689: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_268e:
	/* 0x268e: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2695:
	/* 0x2695: jmp    323f <generic_fentry_filter_arg+0x323f> */
	return 12863ULL;
x86_l_269a:
	/* 0x269a: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_26a0:
	/* 0x26a0: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26a5:
	/* 0x26a5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26aa:
	/* 0x26aa: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_26ae:
	/* 0x26ae: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_26b2:
	/* 0x26b2: jbe    35cd <generic_fentry_filter_arg+0x35cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13773ULL;
	}
x86_l_26b8:
	/* 0x26b8: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_26bd:
	/* 0x26bd: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_26c3:
	/* 0x26c3: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26c8:
	/* 0x26c8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26cd:
	/* 0x26cd: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26d2:
	/* 0x26d2: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_26d6:
	/* 0x26d6: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_26da:
	/* 0x26da: jbe    35cd <generic_fentry_filter_arg+0x35cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13773ULL;
	}
x86_l_26e0:
	/* 0x26e0: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_26e5:
	/* 0x26e5: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_26e8:
	/* 0x26e8: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_26ec:
	/* 0x26ec: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_26ee:
	/* 0x26ee: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_26f2:
	/* 0x26f2: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_26f5:
	/* 0x26f5: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_26f8:
	/* 0x26f8: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_26fb:
	/* 0x26fb: jb     30f5 <generic_fentry_filter_arg+0x30f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12533ULL;
	}
x86_l_2701:
	/* 0x2701: mov    r8d,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2705:
	/* 0x2705: mov    edi,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2709:
	/* 0x2709: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_270c:
	/* 0x270c: ja     2e61 <generic_fentry_filter_arg+0x2e61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11873ULL;
	}
x86_l_2712:
	/* 0x2712: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_2718:
	/* 0x2718: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_271c:
	/* 0x271c: jae    2e61 <generic_fentry_filter_arg+0x2e61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11873ULL;
	}
x86_l_2722:
	/* 0x2722: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2725:
	/* 0x2725: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2729:
	/* 0x2729: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_272b:
	/* 0x272b: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_272f:
	/* 0x272f: jmp    2e6e <generic_fentry_filter_arg+0x2e6e> */
	return 11886ULL;
x86_l_2734:
	/* 0x2734: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2737:
	/* 0x2737: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_273c:
	/* 0x273c: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_2741:
	/* 0x2741: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2746:
	/* 0x2746: jmp    2754 <generic_fentry_filter_arg+0x2754> */
	goto x86_l_2754;
x86_l_2748:
	/* 0x2748: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_274d:
	/* 0x274d: jmp    2754 <generic_fentry_filter_arg+0x2754> */
	goto x86_l_2754;
x86_l_274f:
	/* 0x274f: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_2754:
	/* 0x2754: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_2756:
	/* 0x2756: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2759:
	/* 0x2759: mov    eax,DWORD PTR [r13+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_275e:
	/* 0x275e: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2761:
	/* 0x2761: je     3028 <generic_fentry_filter_arg+0x3028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12328ULL;
	}
x86_l_2767:
	/* 0x2767: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_276b:
	/* 0x276b: mov    QWORD PTR [rsp+0x40],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2770:
	/* 0x2770: mov    BYTE PTR [rsp+0x90],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2778:
	/* 0x2778: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_277d:
	/* 0x277d: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2781:
	/* 0x2781: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2786:
	/* 0x2786: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_278b:
	/* 0x278b: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2792:
	/* 0x2792: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2797:
	/* 0x2797: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_279a:
	/* 0x279a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_279c:
	/* 0x279c: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_279f:
	/* 0x279f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27a4:
	/* 0x27a4: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_27ab:
	/* 0x27ab: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_27ae:
	/* 0x27ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27b0:
	/* 0x27b0: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_27b3:
	/* 0x27b3: je     34e3 <generic_fentry_filter_arg+0x34e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13539ULL;
	}
x86_l_27b9:
	/* 0x27b9: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_27bf:
	/* 0x27bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27c2:
	/* 0x27c2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27c7:
	/* 0x27c7: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27cc:
	/* 0x27cc: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27d1:
	/* 0x27d1: je     34f5 <generic_fentry_filter_arg+0x34f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13557ULL;
	}
x86_l_27d7:
	/* 0x27d7: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_27da:
	/* 0x27da: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_27e2:
	/* 0x27e2: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_27e5:
	/* 0x27e5: jg     2829 <generic_fentry_filter_arg+0x2829> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2829;
	}
x86_l_27e7:
	/* 0x27e7: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_27ea:
	/* 0x27ea: movzx  eax,BYTE PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 144ULL);
x86_l_27f2:
	/* 0x27f2: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27f4:
	/* 0x27f4: lea    rdi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_27f8:
	/* 0x27f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27fd:
	/* 0x27fd: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2801:
	/* 0x2801: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2804:
	/* 0x2804: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2809:
	/* 0x2809: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_280b:
	/* 0x280b: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2810:
	/* 0x2810: sub    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2813:
	/* 0x2813: jbe    286e <generic_fentry_filter_arg+0x286e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_286e;
	}
x86_l_2815:
	/* 0x2815: lea    rdi,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2819:
	/* 0x2819: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_281c:
	/* 0x281c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2822:
	/* 0x2822: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2827:
	/* 0x2827: jmp    2864 <generic_fentry_filter_arg+0x2864> */
	goto x86_l_2864;
x86_l_2829:
	/* 0x2829: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_282d:
	/* 0x282d: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_2830:
	/* 0x2830: mov    WORD PTR [rcx],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2834:
	/* 0x2834: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2838:
	/* 0x2838: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_283d:
	/* 0x283d: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2840:
	/* 0x2840: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2845:
	/* 0x2845: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2847:
	/* 0x2847: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_284c:
	/* 0x284c: sub    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_284f:
	/* 0x284f: jbe    286e <generic_fentry_filter_arg+0x286e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_286e;
	}
x86_l_2851:
	/* 0x2851: lea    rdi,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2855:
	/* 0x2855: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2859:
	/* 0x2859: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_285f:
	/* 0x285f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2864:
	/* 0x2864: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_286c:
	/* 0x286c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_286e:
	/* 0x286e: mov    eax,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2872:
	/* 0x2872: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2876:
	/* 0x2876: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2879:
	/* 0x2879: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_287e:
	/* 0x287e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2883:
	/* 0x2883: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2888:
	/* 0x2888: jle    28bf <generic_fentry_filter_arg+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_28bf;
	}
x86_l_288a:
	/* 0x288a: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_288d:
	/* 0x288d: jg     2d1d <generic_fentry_filter_arg+0x2d1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11549ULL;
	}
x86_l_2893:
	/* 0x2893: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2896:
	/* 0x2896: je     34a4 <generic_fentry_filter_arg+0x34a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13476ULL;
	}
x86_l_289c:
	/* 0x289c: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_289f:
	/* 0x289f: je     347a <generic_fentry_filter_arg+0x347a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13434ULL;
	}
x86_l_28a5:
	/* 0x28a5: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_28a8:
	/* 0x28a8: jne    3028 <generic_fentry_filter_arg+0x3028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12328ULL;
	}
x86_l_28ae:
	/* 0x28ae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28b3:
	/* 0x28b3: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_28ba:
	/* 0x28ba: jmp    34be <generic_fentry_filter_arg+0x34be> */
	return 13502ULL;
x86_l_28bf:
	/* 0x28bf: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_28c2:
	/* 0x28c2: jle    300a <generic_fentry_filter_arg+0x300a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12298ULL;
	}
x86_l_28c8:
	/* 0x28c8: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_28cb:
	/* 0x28cb: je     3496 <generic_fentry_filter_arg+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13462ULL;
	}
x86_l_28d1:
	/* 0x28d1: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_28d4:
	/* 0x28d4: je     346c <generic_fentry_filter_arg+0x346c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13420ULL;
	}
x86_l_28da:
	/* 0x28da: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_28dd:
	/* 0x28dd: jne    3028 <generic_fentry_filter_arg+0x3028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12328ULL;
	}
x86_l_28e3:
	/* 0x28e3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28e8:
	/* 0x28e8: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_28ef:
	/* 0x28ef: jmp    34be <generic_fentry_filter_arg+0x34be> */
	return 13502ULL;
x86_l_28f4:
	/* 0x28f4: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_28f6:
	/* 0x28f6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28fb:
	/* 0x28fb: ja     2905 <generic_fentry_filter_arg+0x2905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2905;
	}
x86_l_28fd:
	/* 0x28fd: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_28ff:
	/* 0x28ff: jbe    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 697ULL;
	}
x86_l_2905:
	/* 0x2905: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2908:
	/* 0x2908: jb     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 264ULL;
	}
x86_l_290e:
	/* 0x290e: mov    edi,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2912:
	/* 0x2912: mov    esi,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2916:
	/* 0x2916: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2919:
	/* 0x2919: ja     2ecf <generic_fentry_filter_arg+0x2ecf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11983ULL;
	}
x86_l_291f:
	/* 0x291f: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2925:
	/* 0x2925: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2929:
	/* 0x2929: jae    2ecf <generic_fentry_filter_arg+0x2ecf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11983ULL;
	}
x86_l_292f:
	/* 0x292f: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2931:
	/* 0x2931: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2936:
	/* 0x2936: jg     2ee0 <generic_fentry_filter_arg+0x2ee0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 12000ULL;
	}
x86_l_293c:
	/* 0x293c: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_293e:
	/* 0x293e: jle    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 697ULL;
	}
x86_l_2944:
	/* 0x2944: jmp    2ee0 <generic_fentry_filter_arg+0x2ee0> */
	return 12000ULL;
x86_l_2949:
	/* 0x2949: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_294e:
	/* 0x294e: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_2953:
	/* 0x2953: jb     2981 <generic_fentry_filter_arg+0x2981> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2981;
	}
x86_l_2955:
	/* 0x2955: mov    esi,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 512ULL);
x86_l_295a:
	/* 0x295a: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_295f:
	/* 0x295f: jb     2981 <generic_fentry_filter_arg+0x2981> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2981;
	}
x86_l_2961:
	/* 0x2961: mov    esi,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1024ULL);
x86_l_2966:
	/* 0x2966: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_296b:
	/* 0x296b: jb     2981 <generic_fentry_filter_arg+0x2981> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2981;
	}
x86_l_296d:
	/* 0x296d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_296f:
	/* 0x296f: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_2974:
	/* 0x2974: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_2978:
	/* 0x2978: shl    esi,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_297b:
	/* 0x297b: add    esi,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_2981:
	/* 0x2981: lea    eax,[rsi-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_2987:
	/* 0x2987: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_298d:
	/* 0x298d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2990:
	/* 0x2990: jg     2d53 <generic_fentry_filter_arg+0x2d53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11603ULL;
	}
x86_l_2996:
	/* 0x2996: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2998:
	/* 0x2998: je     3289 <generic_fentry_filter_arg+0x3289> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12937ULL;
	}
x86_l_299e:
	/* 0x299e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29a1:
	/* 0x29a1: jne    3282 <generic_fentry_filter_arg+0x3282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12930ULL;
	}
x86_l_29a7:
	/* 0x29a7: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_29ac:
	/* 0x29ac: jmp    3295 <generic_fentry_filter_arg+0x3295> */
	return 12949ULL;
x86_l_29b1:
	/* 0x29b1: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_29b4:
	/* 0x29b4: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_29b8:
	/* 0x29b8: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_29bb:
	/* 0x29bb: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_29bf:
	/* 0x29bf: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_29c2:
	/* 0x29c2: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_29c5:
	/* 0x29c5: cmp    esi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 57ULL);
x86_l_29c8:
	/* 0x29c8: jb     30f5 <generic_fentry_filter_arg+0x30f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12533ULL;
	}
x86_l_29ce:
	/* 0x29ce: mov    rdi,QWORD PTR [r13+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29d2:
	/* 0x29d2: mov    rsi,QWORD PTR [r13+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29d6:
	/* 0x29d6: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_29d9:
	/* 0x29d9: je     29e4 <generic_fentry_filter_arg+0x29e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29e4;
	}
x86_l_29db:
	/* 0x29db: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_29de:
	/* 0x29de: jne    2fef <generic_fentry_filter_arg+0x2fef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12271ULL;
	}
x86_l_29e4:
	/* 0x29e4: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_29e7:
	/* 0x29e7: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_29ea:
	/* 0x29ea: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_29ed:
	/* 0x29ed: jmp    2ea5 <generic_fentry_filter_arg+0x2ea5> */
	return 11941ULL;
x86_l_29f2:
	/* 0x29f2: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_29f5:
	/* 0x29f5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29fa:
	/* 0x29fa: ja     2a05 <generic_fentry_filter_arg+0x2a05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2a05;
	}
x86_l_29fc:
	/* 0x29fc: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_29ff:
	/* 0x29ff: jbe    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 697ULL;
	}
x86_l_2a05:
	/* 0x2a05: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_2a08:
	/* 0x2a08: jb     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 264ULL;
	}
x86_l_2a0e:
	/* 0x2a0e: mov    rsi,QWORD PTR [r13+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a12:
	/* 0x2a12: mov    rdx,QWORD PTR [r13+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a16:
	/* 0x2a16: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2a19:
	/* 0x2a19: je     2a24 <generic_fentry_filter_arg+0x2a24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a24;
	}
x86_l_2a1b:
	/* 0x2a1b: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2a1e:
	/* 0x2a1e: jne    303e <generic_fentry_filter_arg+0x303e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12350ULL;
	}
x86_l_2a24:
	/* 0x2a24: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2a27:
	/* 0x2a27: jg     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 264ULL;
	}
x86_l_2a2d:
	/* 0x2a2d: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2a30:
	/* 0x2a30: jle    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 697ULL;
	}
x86_l_2a36:
	/* 0x2a36: jmp    108 <generic_fentry_filter_arg+0x108> */
	return 264ULL;
x86_l_2a3b:
	/* 0x2a3b: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a3f:
	/* 0x2a3f: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a42:
	/* 0x2a42: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_2a48:
	/* 0x2a48: jmp    2a57 <generic_fentry_filter_arg+0x2a57> */
	goto x86_l_2a57;
x86_l_2a4a:
	/* 0x2a4a: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a4e:
	/* 0x2a4e: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a51:
	/* 0x2a51: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_2a57:
	/* 0x2a57: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2a5a:
	/* 0x2a5a: jb     3962 <generic_fentry_filter_arg+0x3962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14690ULL;
	}
x86_l_2a60:
	/* 0x2a60: mov    rsi,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a64:
	/* 0x2a64: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a67:
	/* 0x2a67: jle    2a88 <generic_fentry_filter_arg+0x2a88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2a88;
	}
x86_l_2a69:
	/* 0x2a69: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2a6c:
	/* 0x2a6c: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2a6f:
	/* 0x2a6f: jae    2aba <generic_fentry_filter_arg+0x2aba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2aba;
	}
x86_l_2a71:
	/* 0x2a71: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a75:
	/* 0x2a75: cmp    QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a78:
	/* 0x2a78: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a7d:
	/* 0x2a7d: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 670ULL;
	}
x86_l_2a83:
	/* 0x2a83: jmp    3123 <generic_fentry_filter_arg+0x3123> */
	return 12579ULL;
x86_l_2a88:
	/* 0x2a88: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a8b:
	/* 0x2a8b: je     2cfd <generic_fentry_filter_arg+0x2cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11517ULL;
	}
x86_l_2a91:
	/* 0x2a91: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a94:
	/* 0x2a94: jne    3123 <generic_fentry_filter_arg+0x3123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12579ULL;
	}
x86_l_2a9a:
	/* 0x2a9a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2a9d:
	/* 0x2a9d: je     2aa8 <generic_fentry_filter_arg+0x2aa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa8;
	}
x86_l_2a9f:
	/* 0x2a9f: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2aa2:
	/* 0x2aa2: jne    3116 <generic_fentry_filter_arg+0x3116> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12566ULL;
	}
x86_l_2aa8:
	/* 0x2aa8: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aac:
	/* 0x2aac: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aaf:
	/* 0x2aaf: jl     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 697ULL;
	}
x86_l_2ab5:
	/* 0x2ab5: jmp    3123 <generic_fentry_filter_arg+0x3123> */
	return 12579ULL;
x86_l_2aba:
	/* 0x2aba: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2abd:
	/* 0x2abd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ac2:
	/* 0x2ac2: jne    3123 <generic_fentry_filter_arg+0x3123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12579ULL;
	}
x86_l_2ac8:
	/* 0x2ac8: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2acc:
	/* 0x2acc: test   QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2acf:
	/* 0x2acf: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_2ad5:
	/* 0x2ad5: jmp    3123 <generic_fentry_filter_arg+0x3123> */
	return 12579ULL;
x86_l_2ada:
	/* 0x2ada: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2add:
	/* 0x2add: jne    2d7e <generic_fentry_filter_arg+0x2d7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11646ULL;
	}
x86_l_2ae3:
	/* 0x2ae3: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ae7:
	/* 0x2ae7: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2aea:
	/* 0x2aea: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2aec:
	/* 0x2aec: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_2af2:
	/* 0x2af2: jmp    2d7e <generic_fentry_filter_arg+0x2d7e> */
	return 11646ULL;
x86_l_2af7:
	/* 0x2af7: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2afa:
	/* 0x2afa: jne    2dc3 <generic_fentry_filter_arg+0x2dc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11715ULL;
	}
x86_l_2b00:
	/* 0x2b00: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b04:
	/* 0x2b04: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b07:
	/* 0x2b07: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2b09:
	/* 0x2b09: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_2b0f:
	/* 0x2b0f: jmp    2dc3 <generic_fentry_filter_arg+0x2dc3> */
	return 11715ULL;
x86_l_2b14:
	/* 0x2b14: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_2b17:
	/* 0x2b17: je     3233 <generic_fentry_filter_arg+0x3233> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12851ULL;
	}
x86_l_2b1d:
	/* 0x2b1d: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_2b20:
	/* 0x2b20: je     3209 <generic_fentry_filter_arg+0x3209> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12809ULL;
	}
x86_l_2b26:
	/* 0x2b26: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2b29:
	/* 0x2b29: jne    957 <generic_fentry_filter_arg+0x957> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2391ULL;
	}
x86_l_2b2f:
	/* 0x2b2f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b34:
	/* 0x2b34: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_2b3b:
	/* 0x2b3b: jmp    323f <generic_fentry_filter_arg+0x323f> */
	return 12863ULL;
x86_l_2b40:
	/* 0x2b40: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2b45:
	/* 0x2b45: jmp    2b53 <generic_fentry_filter_arg+0x2b53> */
	goto x86_l_2b53;
x86_l_2b47:
	/* 0x2b47: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2b4c:
	/* 0x2b4c: jmp    2b53 <generic_fentry_filter_arg+0x2b53> */
	goto x86_l_2b53;
x86_l_2b4e:
	/* 0x2b4e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b53:
	/* 0x2b53: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2b55:
	/* 0x2b55: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2b58:
	/* 0x2b58: mov    eax,DWORD PTR [r13+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2b5d:
	/* 0x2b5d: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2b60:
	/* 0x2b60: je     2c1f <generic_fentry_filter_arg+0x2c1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11295ULL;
	}
x86_l_2b66:
	/* 0x2b66: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2b6a:
	/* 0x2b6a: mov    DWORD PTR [rsp+0x40],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b6e:
	/* 0x2b6e: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b76:
	/* 0x2b76: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b7a:
	/* 0x2b7a: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b7f:
	/* 0x2b7f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b84:
	/* 0x2b84: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2b8b:
	/* 0x2b8b: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b90:
	/* 0x2b90: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2b93:
	/* 0x2b93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b95:
	/* 0x2b95: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2b98:
	/* 0x2b98: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b9d:
	/* 0x2b9d: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2ba4:
	/* 0x2ba4: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2ba7:
	/* 0x2ba7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba9:
	/* 0x2ba9: mov    QWORD PTR [rsp+0x28],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2bae:
	/* 0x2bae: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2bb1:
	/* 0x2bb1: je     35a8 <generic_fentry_filter_arg+0x35a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13736ULL;
	}
x86_l_2bb7:
	/* 0x2bb7: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_2bbd:
	/* 0x2bbd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bc0:
	/* 0x2bc0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bc5:
	/* 0x2bc5: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bca:
	/* 0x2bca: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bcf:
	/* 0x2bcf: je     35ba <generic_fentry_filter_arg+0x35ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13754ULL;
	}
x86_l_2bd5:
	/* 0x2bd5: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
	return 11224ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11224ULL: goto x86_l_2bd8;
	case 11228ULL: goto x86_l_2bdc;
	case 11231ULL: goto x86_l_2bdf;
	case 11233ULL: goto x86_l_2be1;
	case 11238ULL: goto x86_l_2be6;
	case 11241ULL: goto x86_l_2be9;
	case 11245ULL: goto x86_l_2bed;
	case 11250ULL: goto x86_l_2bf2;
	case 11252ULL: goto x86_l_2bf4;
	case 11256ULL: goto x86_l_2bf8;
	case 11258ULL: goto x86_l_2bfa;
	case 11266ULL: goto x86_l_2c02;
	case 11268ULL: goto x86_l_2c04;
	case 11270ULL: goto x86_l_2c06;
	case 11275ULL: goto x86_l_2c0b;
	case 11279ULL: goto x86_l_2c0f;
	case 11282ULL: goto x86_l_2c12;
	case 11288ULL: goto x86_l_2c18;
	case 11293ULL: goto x86_l_2c1d;
	case 11295ULL: goto x86_l_2c1f;
	case 11298ULL: goto x86_l_2c22;
	case 11303ULL: goto x86_l_2c27;
	case 11307ULL: goto x86_l_2c2b;
	case 11311ULL: goto x86_l_2c2f;
	case 11317ULL: goto x86_l_2c35;
	case 11322ULL: goto x86_l_2c3a;
	case 11327ULL: goto x86_l_2c3f;
	case 11330ULL: goto x86_l_2c42;
	case 11334ULL: goto x86_l_2c46;
	case 11339ULL: goto x86_l_2c4b;
	case 11341ULL: goto x86_l_2c4d;
	case 11345ULL: goto x86_l_2c51;
	case 11347ULL: goto x86_l_2c53;
	case 11355ULL: goto x86_l_2c5b;
	case 11357ULL: goto x86_l_2c5d;
	case 11359ULL: goto x86_l_2c5f;
	case 11364ULL: goto x86_l_2c64;
	case 11368ULL: goto x86_l_2c68;
	case 11372ULL: goto x86_l_2c6c;
	case 11378ULL: goto x86_l_2c72;
	case 11383ULL: goto x86_l_2c77;
	case 11386ULL: goto x86_l_2c7a;
	case 11388ULL: goto x86_l_2c7c;
	case 11392ULL: goto x86_l_2c80;
	case 11396ULL: goto x86_l_2c84;
	case 11399ULL: goto x86_l_2c87;
	case 11404ULL: goto x86_l_2c8c;
	case 11409ULL: goto x86_l_2c91;
	case 11411ULL: goto x86_l_2c93;
	case 11414ULL: goto x86_l_2c96;
	case 11420ULL: goto x86_l_2c9c;
	case 11423ULL: goto x86_l_2c9f;
	case 11429ULL: goto x86_l_2ca5;
	case 11432ULL: goto x86_l_2ca8;
	case 11438ULL: goto x86_l_2cae;
	case 11441ULL: goto x86_l_2cb1;
	case 11447ULL: goto x86_l_2cb7;
	case 11452ULL: goto x86_l_2cbc;
	case 11459ULL: goto x86_l_2cc3;
	case 11464ULL: goto x86_l_2cc8;
	case 11467ULL: goto x86_l_2ccb;
	case 11473ULL: goto x86_l_2cd1;
	case 11476ULL: goto x86_l_2cd4;
	case 11482ULL: goto x86_l_2cda;
	case 11485ULL: goto x86_l_2cdd;
	case 11491ULL: goto x86_l_2ce3;
	case 11494ULL: goto x86_l_2ce6;
	case 11500ULL: goto x86_l_2cec;
	case 11505ULL: goto x86_l_2cf1;
	case 11512ULL: goto x86_l_2cf8;
	case 11517ULL: goto x86_l_2cfd;
	case 11520ULL: goto x86_l_2d00;
	case 11522ULL: goto x86_l_2d02;
	case 11525ULL: goto x86_l_2d05;
	case 11531ULL: goto x86_l_2d0b;
	case 11535ULL: goto x86_l_2d0f;
	case 11538ULL: goto x86_l_2d12;
	case 11544ULL: goto x86_l_2d18;
	case 11549ULL: goto x86_l_2d1d;
	case 11552ULL: goto x86_l_2d20;
	case 11558ULL: goto x86_l_2d26;
	case 11561ULL: goto x86_l_2d29;
	case 11567ULL: goto x86_l_2d2f;
	case 11570ULL: goto x86_l_2d32;
	case 11576ULL: goto x86_l_2d38;
	case 11581ULL: goto x86_l_2d3d;
	case 11588ULL: goto x86_l_2d44;
	case 11593ULL: goto x86_l_2d49;
	case 11598ULL: goto x86_l_2d4e;
	case 11603ULL: goto x86_l_2d53;
	case 11606ULL: goto x86_l_2d56;
	case 11612ULL: goto x86_l_2d5c;
	case 11615ULL: goto x86_l_2d5f;
	case 11621ULL: goto x86_l_2d65;
	case 11626ULL: goto x86_l_2d6a;
	case 11631ULL: goto x86_l_2d6f;
	case 11635ULL: goto x86_l_2d73;
	case 11638ULL: goto x86_l_2d76;
	case 11640ULL: goto x86_l_2d78;
	case 11646ULL: goto x86_l_2d7e;
	case 11649ULL: goto x86_l_2d81;
	case 11655ULL: goto x86_l_2d87;
	case 11659ULL: goto x86_l_2d8b;
	case 11662ULL: goto x86_l_2d8e;
	case 11668ULL: goto x86_l_2d94;
	case 11671ULL: goto x86_l_2d97;
	case 11674ULL: goto x86_l_2d9a;
	case 11680ULL: goto x86_l_2da0;
	case 11684ULL: goto x86_l_2da4;
	case 11687ULL: goto x86_l_2da7;
	case 11689ULL: goto x86_l_2da9;
	case 11695ULL: goto x86_l_2daf;
	case 11700ULL: goto x86_l_2db4;
	case 11704ULL: goto x86_l_2db8;
	case 11707ULL: goto x86_l_2dbb;
	case 11709ULL: goto x86_l_2dbd;
	case 11715ULL: goto x86_l_2dc3;
	case 11718ULL: goto x86_l_2dc6;
	case 11724ULL: goto x86_l_2dcc;
	case 11728ULL: goto x86_l_2dd0;
	case 11731ULL: goto x86_l_2dd3;
	case 11737ULL: goto x86_l_2dd9;
	case 11740ULL: goto x86_l_2ddc;
	case 11743ULL: goto x86_l_2ddf;
	case 11749ULL: goto x86_l_2de5;
	case 11753ULL: goto x86_l_2de9;
	case 11756ULL: goto x86_l_2dec;
	case 11758ULL: goto x86_l_2dee;
	case 11764ULL: goto x86_l_2df4;
	case 11769ULL: goto x86_l_2df9;
	case 11772ULL: goto x86_l_2dfc;
	case 11777ULL: goto x86_l_2e01;
	case 11780ULL: goto x86_l_2e04;
	case 11785ULL: goto x86_l_2e09;
	case 11790ULL: goto x86_l_2e0e;
	case 11795ULL: goto x86_l_2e13;
	case 11797ULL: goto x86_l_2e15;
	case 11803ULL: goto x86_l_2e1b;
	case 11806ULL: goto x86_l_2e1e;
	case 11812ULL: goto x86_l_2e24;
	case 11817ULL: goto x86_l_2e29;
	case 11824ULL: goto x86_l_2e30;
	case 11829ULL: goto x86_l_2e35;
	case 11832ULL: goto x86_l_2e38;
	case 11838ULL: goto x86_l_2e3e;
	case 11841ULL: goto x86_l_2e41;
	case 11847ULL: goto x86_l_2e47;
	case 11850ULL: goto x86_l_2e4a;
	case 11856ULL: goto x86_l_2e50;
	case 11861ULL: goto x86_l_2e55;
	case 11868ULL: goto x86_l_2e5c;
	case 11873ULL: goto x86_l_2e61;
	case 11876ULL: goto x86_l_2e64;
	case 11880ULL: goto x86_l_2e68;
	case 11882ULL: goto x86_l_2e6a;
	case 11886ULL: goto x86_l_2e6e;
	case 11889ULL: goto x86_l_2e71;
	case 11892ULL: goto x86_l_2e74;
	case 11895ULL: goto x86_l_2e77;
	case 11901ULL: goto x86_l_2e7d;
	case 11905ULL: goto x86_l_2e81;
	case 11909ULL: goto x86_l_2e85;
	case 11912ULL: goto x86_l_2e88;
	case 11918ULL: goto x86_l_2e8e;
	case 11924ULL: goto x86_l_2e94;
	case 11928ULL: goto x86_l_2e98;
	case 11934ULL: goto x86_l_2e9e;
	case 11936ULL: goto x86_l_2ea0;
	case 11939ULL: goto x86_l_2ea3;
	case 11941ULL: goto x86_l_2ea5;
	case 11944ULL: goto x86_l_2ea8;
	case 11949ULL: goto x86_l_2ead;
	case 11952ULL: goto x86_l_2eb0;
	case 11954ULL: goto x86_l_2eb2;
	case 11960ULL: goto x86_l_2eb8;
	case 11965ULL: goto x86_l_2ebd;
	case 11970ULL: goto x86_l_2ec2;
	case 11973ULL: goto x86_l_2ec5;
	case 11978ULL: goto x86_l_2eca;
	case 11983ULL: goto x86_l_2ecf;
	case 11985ULL: goto x86_l_2ed1;
	case 11990ULL: goto x86_l_2ed6;
	case 11992ULL: goto x86_l_2ed8;
	case 11994ULL: goto x86_l_2eda;
	case 12000ULL: goto x86_l_2ee0;
	case 12003ULL: goto x86_l_2ee3;
	case 12009ULL: goto x86_l_2ee9;
	case 12013ULL: goto x86_l_2eed;
	case 12017ULL: goto x86_l_2ef1;
	case 12020ULL: goto x86_l_2ef4;
	case 12026ULL: goto x86_l_2efa;
	case 12032ULL: goto x86_l_2f00;
	case 12036ULL: goto x86_l_2f04;
	case 12042ULL: goto x86_l_2f0a;
	case 12044ULL: goto x86_l_2f0c;
	case 12050ULL: goto x86_l_2f12;
	case 12052ULL: goto x86_l_2f14;
	case 12058ULL: goto x86_l_2f1a;
	case 12063ULL: goto x86_l_2f1f;
	case 12067ULL: goto x86_l_2f23;
	case 12070ULL: goto x86_l_2f26;
	case 12076ULL: goto x86_l_2f2c;
	case 12078ULL: goto x86_l_2f2e;
	case 12082ULL: goto x86_l_2f32;
	case 12085ULL: goto x86_l_2f35;
	case 12091ULL: goto x86_l_2f3b;
	case 12094ULL: goto x86_l_2f3e;
	case 12100ULL: goto x86_l_2f44;
	case 12104ULL: goto x86_l_2f48;
	case 12107ULL: goto x86_l_2f4b;
	case 12109ULL: goto x86_l_2f4d;
	case 12112ULL: goto x86_l_2f50;
	case 12115ULL: goto x86_l_2f53;
	case 12117ULL: goto x86_l_2f55;
	case 12121ULL: goto x86_l_2f59;
	case 12123ULL: goto x86_l_2f5b;
	case 12128ULL: goto x86_l_2f60;
	case 12134ULL: goto x86_l_2f66;
	case 12139ULL: goto x86_l_2f6b;
	case 12142ULL: goto x86_l_2f6e;
	case 12144ULL: goto x86_l_2f70;
	case 12147ULL: goto x86_l_2f73;
	case 12153ULL: goto x86_l_2f79;
	case 12156ULL: goto x86_l_2f7c;
	case 12162ULL: goto x86_l_2f82;
	case 12168ULL: goto x86_l_2f88;
	case 12172ULL: goto x86_l_2f8c;
	case 12178ULL: goto x86_l_2f92;
	case 12182ULL: goto x86_l_2f96;
	case 12185ULL: goto x86_l_2f99;
	case 12191ULL: goto x86_l_2f9f;
	case 12196ULL: goto x86_l_2fa4;
	case 12199ULL: goto x86_l_2fa7;
	case 12204ULL: goto x86_l_2fac;
	case 12210ULL: goto x86_l_2fb2;
	case 12214ULL: goto x86_l_2fb6;
	case 12217ULL: goto x86_l_2fb9;
	case 12223ULL: goto x86_l_2fbf;
	case 12228ULL: goto x86_l_2fc4;
	case 12231ULL: goto x86_l_2fc7;
	case 12237ULL: goto x86_l_2fcd;
	case 12243ULL: goto x86_l_2fd3;
	case 12247ULL: goto x86_l_2fd7;
	case 12253ULL: goto x86_l_2fdd;
	case 12257ULL: goto x86_l_2fe1;
	case 12260ULL: goto x86_l_2fe4;
	case 12266ULL: goto x86_l_2fea;
	case 12271ULL: goto x86_l_2fef;
	case 12274ULL: goto x86_l_2ff2;
	case 12277ULL: goto x86_l_2ff5;
	case 12280ULL: goto x86_l_2ff8;
	case 12285ULL: goto x86_l_2ffd;
	case 12288ULL: goto x86_l_3000;
	case 12293ULL: goto x86_l_3005;
	case 12298ULL: goto x86_l_300a;
	case 12300ULL: goto x86_l_300c;
	case 12306ULL: goto x86_l_3012;
	case 12309ULL: goto x86_l_3015;
	case 12311ULL: goto x86_l_3017;
	case 12316ULL: goto x86_l_301c;
	case 12323ULL: goto x86_l_3023;
	case 12328ULL: goto x86_l_3028;
	case 12331ULL: goto x86_l_302b;
	case 12335ULL: goto x86_l_302f;
	case 12339ULL: goto x86_l_3033;
	case 12345ULL: goto x86_l_3039;
	case 12350ULL: goto x86_l_303e;
	case 12353ULL: goto x86_l_3041;
	case 12359ULL: goto x86_l_3047;
	case 12362ULL: goto x86_l_304a;
	case 12368ULL: goto x86_l_3050;
	case 12373ULL: goto x86_l_3055;
	case 12378ULL: goto x86_l_305a;
	case 12383ULL: goto x86_l_305f;
	case 12388ULL: goto x86_l_3064;
	case 12393ULL: goto x86_l_3069;
	case 12396ULL: goto x86_l_306c;
	case 12402ULL: goto x86_l_3072;
	case 12405ULL: goto x86_l_3075;
	case 12411ULL: goto x86_l_307b;
	case 12415ULL: goto x86_l_307f;
	case 12418ULL: goto x86_l_3082;
	case 12420ULL: goto x86_l_3084;
	case 12426ULL: goto x86_l_308a;
	case 12431ULL: goto x86_l_308f;
	case 12434ULL: goto x86_l_3092;
	case 12440ULL: goto x86_l_3098;
	case 12443ULL: goto x86_l_309b;
	case 12449ULL: goto x86_l_30a1;
	case 12453ULL: goto x86_l_30a5;
	case 12456ULL: goto x86_l_30a8;
	case 12458ULL: goto x86_l_30aa;
	case 12464ULL: goto x86_l_30b0;
	case 12469ULL: goto x86_l_30b5;
	case 12471ULL: goto x86_l_30b7;
	case 12477ULL: goto x86_l_30bd;
	case 12480ULL: goto x86_l_30c0;
	case 12486ULL: goto x86_l_30c6;
	case 12491ULL: goto x86_l_30cb;
	case 12498ULL: goto x86_l_30d2;
	case 12503ULL: goto x86_l_30d7;
	case 12509ULL: goto x86_l_30dd;
	case 12514ULL: goto x86_l_30e2;
	case 12519ULL: goto x86_l_30e7;
	case 12521ULL: goto x86_l_30e9;
	case 12524ULL: goto x86_l_30ec;
	case 12526ULL: goto x86_l_30ee;
	case 12529ULL: goto x86_l_30f1;
	case 12531ULL: goto x86_l_30f3;
	case 12533ULL: goto x86_l_30f5;
	case 12538ULL: goto x86_l_30fa;
	case 12540ULL: goto x86_l_30fc;
	case 12546ULL: goto x86_l_3102;
	case 12551ULL: goto x86_l_3107;
	case 12555ULL: goto x86_l_310b;
	case 12558ULL: goto x86_l_310e;
	case 12564ULL: goto x86_l_3114;
	case 12566ULL: goto x86_l_3116;
	case 12570ULL: goto x86_l_311a;
	case 12573ULL: goto x86_l_311d;
	case 12579ULL: goto x86_l_3123;
	case 12582ULL: goto x86_l_3126;
	case 12588ULL: goto x86_l_312c;
	case 12592ULL: goto x86_l_3130;
	case 12595ULL: goto x86_l_3133;
	case 12597ULL: goto x86_l_3135;
	case 12600ULL: goto x86_l_3138;
	case 12603ULL: goto x86_l_313b;
	case 12605ULL: goto x86_l_313d;
	case 12608ULL: goto x86_l_3140;
	case 12614ULL: goto x86_l_3146;
	case 12617ULL: goto x86_l_3149;
	case 12623ULL: goto x86_l_314f;
	case 12627ULL: goto x86_l_3153;
	case 12630ULL: goto x86_l_3156;
	case 12636ULL: goto x86_l_315c;
	case 12641ULL: goto x86_l_3161;
	case 12644ULL: goto x86_l_3164;
	case 12650ULL: goto x86_l_316a;
	case 12653ULL: goto x86_l_316d;
	case 12659ULL: goto x86_l_3173;
	case 12662ULL: goto x86_l_3176;
	case 12664ULL: goto x86_l_3178;
	case 12667ULL: goto x86_l_317b;
	case 12673ULL: goto x86_l_3181;
	case 12677ULL: goto x86_l_3185;
	case 12680ULL: goto x86_l_3188;
	case 12686ULL: goto x86_l_318e;
	case 12691ULL: goto x86_l_3193;
	case 12695ULL: goto x86_l_3197;
	case 12698ULL: goto x86_l_319a;
	case 12704ULL: goto x86_l_31a0;
	case 12709ULL: goto x86_l_31a5;
	case 12712ULL: goto x86_l_31a8;
	case 12718ULL: goto x86_l_31ae;
	case 12722ULL: goto x86_l_31b2;
	case 12725ULL: goto x86_l_31b5;
	case 12727ULL: goto x86_l_31b7;
	case 12733ULL: goto x86_l_31bd;
	case 12738ULL: goto x86_l_31c2;
	case 12741ULL: goto x86_l_31c5;
	case 12747ULL: goto x86_l_31cb;
	case 12751ULL: goto x86_l_31cf;
	case 12754ULL: goto x86_l_31d2;
	case 12756ULL: goto x86_l_31d4;
	case 12762ULL: goto x86_l_31da;
	case 12767ULL: goto x86_l_31df;
	case 12772ULL: goto x86_l_31e4;
	case 12779ULL: goto x86_l_31eb;
	case 12781ULL: goto x86_l_31ed;
	case 12786ULL: goto x86_l_31f2;
	case 12793ULL: goto x86_l_31f9;
	case 12795ULL: goto x86_l_31fb;
	case 12800ULL: goto x86_l_3200;
	case 12807ULL: goto x86_l_3207;
	case 12809ULL: goto x86_l_3209;
	case 12814ULL: goto x86_l_320e;
	case 12821ULL: goto x86_l_3215;
	case 12823ULL: goto x86_l_3217;
	case 12828ULL: goto x86_l_321c;
	case 12835ULL: goto x86_l_3223;
	case 12837ULL: goto x86_l_3225;
	case 12842ULL: goto x86_l_322a;
	case 12849ULL: goto x86_l_3231;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2bd8:
	/* 0x2bd8: mov    ebx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bdc:
	/* 0x2bdc: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2bdf:
	/* 0x2bdf: jg     2c3a <generic_fentry_filter_arg+0x2c3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2c3a;
	}
x86_l_2be1:
	/* 0x2be1: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2be6:
	/* 0x2be6: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2be9:
	/* 0x2be9: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2bed:
	/* 0x2bed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bf2:
	/* 0x2bf2: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2bf4:
	/* 0x2bf4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf8:
	/* 0x2bf8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bfa:
	/* 0x2bfa: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2c02:
	/* 0x2c02: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c04:
	/* 0x2c04: jbe    2c7c <generic_fentry_filter_arg+0x2c7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2c7c;
	}
x86_l_2c06:
	/* 0x2c06: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c0b:
	/* 0x2c0b: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2c0f:
	/* 0x2c0f: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2c12:
	/* 0x2c12: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c18:
	/* 0x2c18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c1d:
	/* 0x2c1d: jmp    2c77 <generic_fentry_filter_arg+0x2c77> */
	goto x86_l_2c77;
x86_l_2c1f:
	/* 0x2c1f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c22:
	/* 0x2c22: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c27:
	/* 0x2c27: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c2b:
	/* 0x2c2b: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2c2f:
	/* 0x2c2f: jbe    35cd <generic_fentry_filter_arg+0x35cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13773ULL;
	}
x86_l_2c35:
	/* 0x2c35: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_2c3a:
	/* 0x2c3a: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c3f:
	/* 0x2c3f: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c42:
	/* 0x2c42: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2c46:
	/* 0x2c46: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c4b:
	/* 0x2c4b: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2c4d:
	/* 0x2c4d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c51:
	/* 0x2c51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c53:
	/* 0x2c53: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2c5b:
	/* 0x2c5b: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c5d:
	/* 0x2c5d: jbe    2c7c <generic_fentry_filter_arg+0x2c7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2c7c;
	}
x86_l_2c5f:
	/* 0x2c5f: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c64:
	/* 0x2c64: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2c68:
	/* 0x2c68: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2c6c:
	/* 0x2c6c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c72:
	/* 0x2c72: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c77:
	/* 0x2c77: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2c7a:
	/* 0x2c7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c7c:
	/* 0x2c7c: mov    eax,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2c80:
	/* 0x2c80: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c84:
	/* 0x2c84: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2c87:
	/* 0x2c87: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c8c:
	/* 0x2c8c: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c91:
	/* 0x2c91: jle    2cc8 <generic_fentry_filter_arg+0x2cc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2cc8;
	}
x86_l_2c93:
	/* 0x2c93: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2c96:
	/* 0x2c96: jg     2e35 <generic_fentry_filter_arg+0x2e35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e35;
	}
x86_l_2c9c:
	/* 0x2c9c: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_2c9f:
	/* 0x2c9f: je     3567 <generic_fentry_filter_arg+0x3567> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13671ULL;
	}
x86_l_2ca5:
	/* 0x2ca5: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2ca8:
	/* 0x2ca8: je     353d <generic_fentry_filter_arg+0x353d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13629ULL;
	}
x86_l_2cae:
	/* 0x2cae: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_2cb1:
	/* 0x2cb1: jne    35e6 <generic_fentry_filter_arg+0x35e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13798ULL;
	}
x86_l_2cb7:
	/* 0x2cb7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cbc:
	/* 0x2cbc: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2cc3:
	/* 0x2cc3: jmp    3581 <generic_fentry_filter_arg+0x3581> */
	return 13697ULL;
x86_l_2cc8:
	/* 0x2cc8: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2ccb:
	/* 0x2ccb: jle    30b5 <generic_fentry_filter_arg+0x30b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_30b5;
	}
x86_l_2cd1:
	/* 0x2cd1: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_2cd4:
	/* 0x2cd4: je     3559 <generic_fentry_filter_arg+0x3559> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13657ULL;
	}
x86_l_2cda:
	/* 0x2cda: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_2cdd:
	/* 0x2cdd: je     352f <generic_fentry_filter_arg+0x352f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13615ULL;
	}
x86_l_2ce3:
	/* 0x2ce3: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2ce6:
	/* 0x2ce6: jne    35e6 <generic_fentry_filter_arg+0x35e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13798ULL;
	}
x86_l_2cec:
	/* 0x2cec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cf1:
	/* 0x2cf1: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2cf8:
	/* 0x2cf8: jmp    3581 <generic_fentry_filter_arg+0x3581> */
	return 13697ULL;
x86_l_2cfd:
	/* 0x2cfd: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2d00:
	/* 0x2d00: je     2d0b <generic_fentry_filter_arg+0x2d0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d0b;
	}
x86_l_2d02:
	/* 0x2d02: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2d05:
	/* 0x2d05: jne    3107 <generic_fentry_filter_arg+0x3107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3107;
	}
x86_l_2d0b:
	/* 0x2d0b: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d0f:
	/* 0x2d0f: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d12:
	/* 0x2d12: jg     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 697ULL;
	}
x86_l_2d18:
	/* 0x2d18: jmp    3123 <generic_fentry_filter_arg+0x3123> */
	goto x86_l_3123;
x86_l_2d1d:
	/* 0x2d1d: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_2d20:
	/* 0x2d20: je     34b2 <generic_fentry_filter_arg+0x34b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13490ULL;
	}
x86_l_2d26:
	/* 0x2d26: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_2d29:
	/* 0x2d29: je     3488 <generic_fentry_filter_arg+0x3488> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13448ULL;
	}
x86_l_2d2f:
	/* 0x2d2f: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2d32:
	/* 0x2d32: jne    3028 <generic_fentry_filter_arg+0x3028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3028;
	}
x86_l_2d38:
	/* 0x2d38: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d3d:
	/* 0x2d3d: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_2d44:
	/* 0x2d44: jmp    34be <generic_fentry_filter_arg+0x34be> */
	return 13502ULL;
x86_l_2d49:
	/* 0x2d49: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d4e:
	/* 0x2d4e: jmp    1722 <generic_fentry_filter_arg+0x1722> */
	return 5922ULL;
x86_l_2d53:
	/* 0x2d53: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2d56:
	/* 0x2d56: je     3290 <generic_fentry_filter_arg+0x3290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12944ULL;
	}
x86_l_2d5c:
	/* 0x2d5c: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2d5f:
	/* 0x2d5f: jne    3282 <generic_fentry_filter_arg+0x3282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12930ULL;
	}
x86_l_2d65:
	/* 0x2d65: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2d6a:
	/* 0x2d6a: jmp    3295 <generic_fentry_filter_arg+0x3295> */
	return 12949ULL;
x86_l_2d6f:
	/* 0x2d6f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d73:
	/* 0x2d73: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2d76:
	/* 0x2d76: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2d78:
	/* 0x2d78: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_2d7e:
	/* 0x2d7e: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2d81:
	/* 0x2d81: jb     3962 <generic_fentry_filter_arg+0x3962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14690ULL;
	}
x86_l_2d87:
	/* 0x2d87: mov    edx,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d8b:
	/* 0x2d8b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d8e:
	/* 0x2d8e: jle    3069 <generic_fentry_filter_arg+0x3069> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3069;
	}
x86_l_2d94:
	/* 0x2d94: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2d97:
	/* 0x2d97: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2d9a:
	/* 0x2d9a: jae    31a5 <generic_fentry_filter_arg+0x31a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_31a5;
	}
x86_l_2da0:
	/* 0x2da0: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2da4:
	/* 0x2da4: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2da7:
	/* 0x2da7: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2da9:
	/* 0x2da9: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 670ULL;
	}
x86_l_2daf:
	/* 0x2daf: jmp    3611 <generic_fentry_filter_arg+0x3611> */
	return 13841ULL;
x86_l_2db4:
	/* 0x2db4: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2db8:
	/* 0x2db8: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2dbb:
	/* 0x2dbb: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2dbd:
	/* 0x2dbd: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_2dc3:
	/* 0x2dc3: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2dc6:
	/* 0x2dc6: jb     3962 <generic_fentry_filter_arg+0x3962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14690ULL;
	}
x86_l_2dcc:
	/* 0x2dcc: mov    edx,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dd0:
	/* 0x2dd0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2dd3:
	/* 0x2dd3: jle    308f <generic_fentry_filter_arg+0x308f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_308f;
	}
x86_l_2dd9:
	/* 0x2dd9: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2ddc:
	/* 0x2ddc: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2ddf:
	/* 0x2ddf: jae    31c2 <generic_fentry_filter_arg+0x31c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_31c2;
	}
x86_l_2de5:
	/* 0x2de5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2de9:
	/* 0x2de9: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2dec:
	/* 0x2dec: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2dee:
	/* 0x2dee: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 670ULL;
	}
x86_l_2df4:
	/* 0x2df4: jmp    365d <generic_fentry_filter_arg+0x365d> */
	return 13917ULL;
x86_l_2df9:
	/* 0x2df9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dfc:
	/* 0x2dfc: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e01:
	/* 0x2e01: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_2e04:
	/* 0x2e04: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e09:
	/* 0x2e09: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e0e:
	/* 0x2e0e: jmp    38d2 <generic_fentry_filter_arg+0x38d2> */
	return 14546ULL;
x86_l_2e13:
	/* 0x2e13: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_2e15:
	/* 0x2e15: je     31df <generic_fentry_filter_arg+0x31df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31df;
	}
x86_l_2e1b:
	/* 0x2e1b: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2e1e:
	/* 0x2e1e: jne    957 <generic_fentry_filter_arg+0x957> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2391ULL;
	}
x86_l_2e24:
	/* 0x2e24: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e29:
	/* 0x2e29: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2e30:
	/* 0x2e30: jmp    323f <generic_fentry_filter_arg+0x323f> */
	return 12863ULL;
x86_l_2e35:
	/* 0x2e35: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_2e38:
	/* 0x2e38: je     3575 <generic_fentry_filter_arg+0x3575> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13685ULL;
	}
x86_l_2e3e:
	/* 0x2e3e: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_2e41:
	/* 0x2e41: je     354b <generic_fentry_filter_arg+0x354b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13643ULL;
	}
x86_l_2e47:
	/* 0x2e47: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_2e4a:
	/* 0x2e4a: jne    35e6 <generic_fentry_filter_arg+0x35e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13798ULL;
	}
x86_l_2e50:
	/* 0x2e50: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e55:
	/* 0x2e55: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_2e5c:
	/* 0x2e5c: jmp    3581 <generic_fentry_filter_arg+0x3581> */
	return 13697ULL;
x86_l_2e61:
	/* 0x2e61: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2e64:
	/* 0x2e64: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2e68:
	/* 0x2e68: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2e6a:
	/* 0x2e6a: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2e6e:
	/* 0x2e6e: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2e71:
	/* 0x2e71: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2e74:
	/* 0x2e74: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_2e77:
	/* 0x2e77: jb     30f5 <generic_fentry_filter_arg+0x30f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_30f5;
	}
x86_l_2e7d:
	/* 0x2e7d: mov    edi,DWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e81:
	/* 0x2e81: mov    esi,DWORD PTR [r13+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2e85:
	/* 0x2e85: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2e88:
	/* 0x2e88: ja     30e7 <generic_fentry_filter_arg+0x30e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_30e7;
	}
x86_l_2e8e:
	/* 0x2e8e: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2e94:
	/* 0x2e94: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2e98:
	/* 0x2e98: jae    30e7 <generic_fentry_filter_arg+0x30e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_30e7;
	}
x86_l_2e9e:
	/* 0x2e9e: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2ea0:
	/* 0x2ea0: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_2ea3:
	/* 0x2ea3: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2ea5:
	/* 0x2ea5: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_2ea8:
	/* 0x2ea8: jmp    30f1 <generic_fentry_filter_arg+0x30f1> */
	goto x86_l_30f1;
x86_l_2ead:
	/* 0x2ead: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2eb0:
	/* 0x2eb0: jmp    2eb8 <generic_fentry_filter_arg+0x2eb8> */
	goto x86_l_2eb8;
x86_l_2eb2:
	/* 0x2eb2: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_2eb8:
	/* 0x2eb8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ebd:
	/* 0x2ebd: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ec2:
	/* 0x2ec2: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_2ec5:
	/* 0x2ec5: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2eca:
	/* 0x2eca: jmp    38d2 <generic_fentry_filter_arg+0x38d2> */
	return 14546ULL;
x86_l_2ecf:
	/* 0x2ecf: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2ed1:
	/* 0x2ed1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ed6:
	/* 0x2ed6: ja     2ee0 <generic_fentry_filter_arg+0x2ee0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ee0;
	}
x86_l_2ed8:
	/* 0x2ed8: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_2eda:
	/* 0x2eda: jbe    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 697ULL;
	}
x86_l_2ee0:
	/* 0x2ee0: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2ee3:
	/* 0x2ee3: jb     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 264ULL;
	}
x86_l_2ee9:
	/* 0x2ee9: mov    esi,DWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2eed:
	/* 0x2eed: mov    edx,DWORD PTR [r13+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2ef1:
	/* 0x2ef1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2ef4:
	/* 0x2ef4: ja     3412 <generic_fentry_filter_arg+0x3412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13330ULL;
	}
x86_l_2efa:
	/* 0x2efa: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2f00:
	/* 0x2f00: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2f04:
	/* 0x2f04: jae    3412 <generic_fentry_filter_arg+0x3412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13330ULL;
	}
x86_l_2f0a:
	/* 0x2f0a: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2f0c:
	/* 0x2f0c: jg     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 264ULL;
	}
x86_l_2f12:
	/* 0x2f12: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2f14:
	/* 0x2f14: jle    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 697ULL;
	}
x86_l_2f1a:
	/* 0x2f1a: jmp    108 <generic_fentry_filter_arg+0x108> */
	return 264ULL;
x86_l_2f1f:
	/* 0x2f1f: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f23:
	/* 0x2f23: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f26:
	/* 0x2f26: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_2f2c:
	/* 0x2f2c: jmp    2f3b <generic_fentry_filter_arg+0x2f3b> */
	goto x86_l_2f3b;
x86_l_2f2e:
	/* 0x2f2e: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f32:
	/* 0x2f32: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f35:
	/* 0x2f35: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_2f3b:
	/* 0x2f3b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2f3e:
	/* 0x2f3e: jb     3962 <generic_fentry_filter_arg+0x3962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14690ULL;
	}
x86_l_2f44:
	/* 0x2f44: mov    esi,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f48:
	/* 0x2f48: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f4b:
	/* 0x2f4b: jle    2f6b <generic_fentry_filter_arg+0x2f6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2f6b;
	}
x86_l_2f4d:
	/* 0x2f4d: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2f50:
	/* 0x2f50: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2f53:
	/* 0x2f53: jae    2fa4 <generic_fentry_filter_arg+0x2fa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2fa4;
	}
x86_l_2f55:
	/* 0x2f55: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f59:
	/* 0x2f59: cmp    DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f5b:
	/* 0x2f5b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f60:
	/* 0x2f60: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 670ULL;
	}
x86_l_2f66:
	/* 0x2f66: jmp    36ed <generic_fentry_filter_arg+0x36ed> */
	return 14061ULL;
x86_l_2f6b:
	/* 0x2f6b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f6e:
	/* 0x2f6e: je     2fc4 <generic_fentry_filter_arg+0x2fc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fc4;
	}
x86_l_2f70:
	/* 0x2f70: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f73:
	/* 0x2f73: jne    36ed <generic_fentry_filter_arg+0x36ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14061ULL;
	}
x86_l_2f79:
	/* 0x2f79: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2f7c:
	/* 0x2f7c: ja     36e0 <generic_fentry_filter_arg+0x36e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14048ULL;
	}
x86_l_2f82:
	/* 0x2f82: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2f88:
	/* 0x2f88: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2f8c:
	/* 0x2f8c: jae    36e0 <generic_fentry_filter_arg+0x36e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14048ULL;
	}
x86_l_2f92:
	/* 0x2f92: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f96:
	/* 0x2f96: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f99:
	/* 0x2f99: jl     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 697ULL;
	}
x86_l_2f9f:
	/* 0x2f9f: jmp    36ed <generic_fentry_filter_arg+0x36ed> */
	return 14061ULL;
x86_l_2fa4:
	/* 0x2fa4: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2fa7:
	/* 0x2fa7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fac:
	/* 0x2fac: jne    36ed <generic_fentry_filter_arg+0x36ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14061ULL;
	}
x86_l_2fb2:
	/* 0x2fb2: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fb6:
	/* 0x2fb6: test   DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fb9:
	/* 0x2fb9: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_2fbf:
	/* 0x2fbf: jmp    36ed <generic_fentry_filter_arg+0x36ed> */
	return 14061ULL;
x86_l_2fc4:
	/* 0x2fc4: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2fc7:
	/* 0x2fc7: ja     36d1 <generic_fentry_filter_arg+0x36d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14033ULL;
	}
x86_l_2fcd:
	/* 0x2fcd: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2fd3:
	/* 0x2fd3: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2fd7:
	/* 0x2fd7: jae    36d1 <generic_fentry_filter_arg+0x36d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14033ULL;
	}
x86_l_2fdd:
	/* 0x2fdd: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fe1:
	/* 0x2fe1: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fe4:
	/* 0x2fe4: jg     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 697ULL;
	}
x86_l_2fea:
	/* 0x2fea: jmp    36ed <generic_fentry_filter_arg+0x36ed> */
	return 14061ULL;
x86_l_2fef:
	/* 0x2fef: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2ff2:
	/* 0x2ff2: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2ff5:
	/* 0x2ff5: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_2ff8:
	/* 0x2ff8: jmp    30ee <generic_fentry_filter_arg+0x30ee> */
	goto x86_l_30ee;
x86_l_2ffd:
	/* 0x2ffd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3000:
	/* 0x3000: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3005:
	/* 0x3005: jmp    38d2 <generic_fentry_filter_arg+0x38d2> */
	return 14546ULL;
x86_l_300a:
	/* 0x300a: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_300c:
	/* 0x300c: je     345e <generic_fentry_filter_arg+0x345e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13406ULL;
	}
x86_l_3012:
	/* 0x3012: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3015:
	/* 0x3015: jne    3028 <generic_fentry_filter_arg+0x3028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3028;
	}
x86_l_3017:
	/* 0x3017: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_301c:
	/* 0x301c: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_3023:
	/* 0x3023: jmp    34be <generic_fentry_filter_arg+0x34be> */
	return 13502ULL;
x86_l_3028:
	/* 0x3028: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_302b:
	/* 0x302b: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_302f:
	/* 0x302f: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_3033:
	/* 0x3033: jbe    3503 <generic_fentry_filter_arg+0x3503> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13571ULL;
	}
x86_l_3039:
	/* 0x3039: jmp    3905 <generic_fentry_filter_arg+0x3905> */
	return 14597ULL;
x86_l_303e:
	/* 0x303e: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_3041:
	/* 0x3041: ja     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 264ULL;
	}
x86_l_3047:
	/* 0x3047: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_304a:
	/* 0x304a: jbe    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 697ULL;
	}
x86_l_3050:
	/* 0x3050: jmp    108 <generic_fentry_filter_arg+0x108> */
	return 264ULL;
x86_l_3055:
	/* 0x3055: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_305a:
	/* 0x305a: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_305f:
	/* 0x305f: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3064:
	/* 0x3064: jmp    1ceb <generic_fentry_filter_arg+0x1ceb> */
	return 7403ULL;
x86_l_3069:
	/* 0x3069: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_306c:
	/* 0x306c: je     3602 <generic_fentry_filter_arg+0x3602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13826ULL;
	}
x86_l_3072:
	/* 0x3072: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3075:
	/* 0x3075: jne    3611 <generic_fentry_filter_arg+0x3611> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13841ULL;
	}
x86_l_307b:
	/* 0x307b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_307f:
	/* 0x307f: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3082:
	/* 0x3082: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_3084:
	/* 0x3084: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_308a:
	/* 0x308a: jmp    3611 <generic_fentry_filter_arg+0x3611> */
	return 13841ULL;
x86_l_308f:
	/* 0x308f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3092:
	/* 0x3092: je     364e <generic_fentry_filter_arg+0x364e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13902ULL;
	}
x86_l_3098:
	/* 0x3098: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_309b:
	/* 0x309b: jne    365d <generic_fentry_filter_arg+0x365d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13917ULL;
	}
x86_l_30a1:
	/* 0x30a1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30a5:
	/* 0x30a5: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30a8:
	/* 0x30a8: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_30aa:
	/* 0x30aa: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_30b0:
	/* 0x30b0: jmp    365d <generic_fentry_filter_arg+0x365d> */
	return 13917ULL;
x86_l_30b5:
	/* 0x30b5: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_30b7:
	/* 0x30b7: je     3521 <generic_fentry_filter_arg+0x3521> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13601ULL;
	}
x86_l_30bd:
	/* 0x30bd: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_30c0:
	/* 0x30c0: jne    35e6 <generic_fentry_filter_arg+0x35e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13798ULL;
	}
x86_l_30c6:
	/* 0x30c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30cb:
	/* 0x30cb: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_30d2:
	/* 0x30d2: jmp    3581 <generic_fentry_filter_arg+0x3581> */
	return 13697ULL;
x86_l_30d7:
	/* 0x30d7: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_30dd:
	/* 0x30dd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30e2:
	/* 0x30e2: jmp    38d2 <generic_fentry_filter_arg+0x38d2> */
	return 14546ULL;
x86_l_30e7:
	/* 0x30e7: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_30e9:
	/* 0x30e9: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_30ec:
	/* 0x30ec: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_30ee:
	/* 0x30ee: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_30f1:
	/* 0x30f1: and    dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_AND);
x86_l_30f3:
	/* 0x30f3: or     al,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_30f5:
	/* 0x30f5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30fa:
	/* 0x30fa: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_30fc:
	/* 0x30fc: je     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 697ULL;
	}
x86_l_3102:
	/* 0x3102: jmp    108 <generic_fentry_filter_arg+0x108> */
	return 264ULL;
x86_l_3107:
	/* 0x3107: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_310b:
	/* 0x310b: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_310e:
	/* 0x310e: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_3114:
	/* 0x3114: jmp    3123 <generic_fentry_filter_arg+0x3123> */
	goto x86_l_3123;
x86_l_3116:
	/* 0x3116: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_311a:
	/* 0x311a: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_311d:
	/* 0x311d: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_3123:
	/* 0x3123: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_3126:
	/* 0x3126: jb     3962 <generic_fentry_filter_arg+0x3962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14690ULL;
	}
x86_l_312c:
	/* 0x312c: mov    rdx,QWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3130:
	/* 0x3130: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3133:
	/* 0x3133: jle    3161 <generic_fentry_filter_arg+0x3161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3161;
	}
x86_l_3135:
	/* 0x3135: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3138:
	/* 0x3138: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_313b:
	/* 0x313b: jb     3193 <generic_fentry_filter_arg+0x3193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3193;
	}
x86_l_313d:
	/* 0x313d: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3140:
	/* 0x3140: je     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 697ULL;
	}
x86_l_3146:
	/* 0x3146: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3149:
	/* 0x3149: jne    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 264ULL;
	}
x86_l_314f:
	/* 0x314f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3153:
	/* 0x3153: test   QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3156:
	/* 0x3156: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_315c:
	/* 0x315c: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	return 14690ULL;
x86_l_3161:
	/* 0x3161: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3164:
	/* 0x3164: je     3427 <generic_fentry_filter_arg+0x3427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13351ULL;
	}
x86_l_316a:
	/* 0x316a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_316d:
	/* 0x316d: jne    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 264ULL;
	}
x86_l_3173:
	/* 0x3173: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_3176:
	/* 0x3176: je     3181 <generic_fentry_filter_arg+0x3181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3181;
	}
x86_l_3178:
	/* 0x3178: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_317b:
	/* 0x317b: jne    3819 <generic_fentry_filter_arg+0x3819> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14361ULL;
	}
x86_l_3181:
	/* 0x3181: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3185:
	/* 0x3185: cmp    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3188:
	/* 0x3188: jl     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 697ULL;
	}
x86_l_318e:
	/* 0x318e: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	return 14690ULL;
x86_l_3193:
	/* 0x3193: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3197:
	/* 0x3197: cmp    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_319a:
	/* 0x319a: jne    3962 <generic_fentry_filter_arg+0x3962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14690ULL;
	}
x86_l_31a0:
	/* 0x31a0: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_31a5:
	/* 0x31a5: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_31a8:
	/* 0x31a8: jne    3611 <generic_fentry_filter_arg+0x3611> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13841ULL;
	}
x86_l_31ae:
	/* 0x31ae: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31b2:
	/* 0x31b2: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_31b5:
	/* 0x31b5: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_31b7:
	/* 0x31b7: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_31bd:
	/* 0x31bd: jmp    3611 <generic_fentry_filter_arg+0x3611> */
	return 13841ULL;
x86_l_31c2:
	/* 0x31c2: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_31c5:
	/* 0x31c5: jne    365d <generic_fentry_filter_arg+0x365d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13917ULL;
	}
x86_l_31cb:
	/* 0x31cb: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31cf:
	/* 0x31cf: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31d2:
	/* 0x31d2: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_31d4:
	/* 0x31d4: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_31da:
	/* 0x31da: jmp    365d <generic_fentry_filter_arg+0x365d> */
	return 13917ULL;
x86_l_31df:
	/* 0x31df: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31e4:
	/* 0x31e4: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_31eb:
	/* 0x31eb: jmp    323f <generic_fentry_filter_arg+0x323f> */
	return 12863ULL;
x86_l_31ed:
	/* 0x31ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31f2:
	/* 0x31f2: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_31f9:
	/* 0x31f9: jmp    323f <generic_fentry_filter_arg+0x323f> */
	return 12863ULL;
x86_l_31fb:
	/* 0x31fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3200:
	/* 0x3200: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_3207:
	/* 0x3207: jmp    323f <generic_fentry_filter_arg+0x323f> */
	return 12863ULL;
x86_l_3209:
	/* 0x3209: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_320e:
	/* 0x320e: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_3215:
	/* 0x3215: jmp    323f <generic_fentry_filter_arg+0x323f> */
	return 12863ULL;
x86_l_3217:
	/* 0x3217: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_321c:
	/* 0x321c: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3223:
	/* 0x3223: jmp    323f <generic_fentry_filter_arg+0x323f> */
	return 12863ULL;
x86_l_3225:
	/* 0x3225: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_322a:
	/* 0x322a: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3231:
	/* 0x3231: jmp    323f <generic_fentry_filter_arg+0x323f> */
	return 12863ULL;
	return 12851ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12851ULL: goto x86_l_3233;
	case 12856ULL: goto x86_l_3238;
	case 12863ULL: goto x86_l_323f;
	case 12868ULL: goto x86_l_3244;
	case 12870ULL: goto x86_l_3246;
	case 12873ULL: goto x86_l_3249;
	case 12875ULL: goto x86_l_324b;
	case 12880ULL: goto x86_l_3250;
	case 12883ULL: goto x86_l_3253;
	case 12888ULL: goto x86_l_3258;
	case 12890ULL: goto x86_l_325a;
	case 12893ULL: goto x86_l_325d;
	case 12896ULL: goto x86_l_3260;
	case 12900ULL: goto x86_l_3264;
	case 12902ULL: goto x86_l_3266;
	case 12905ULL: goto x86_l_3269;
	case 12910ULL: goto x86_l_326e;
	case 12915ULL: goto x86_l_3273;
	case 12920ULL: goto x86_l_3278;
	case 12925ULL: goto x86_l_327d;
	case 12930ULL: goto x86_l_3282;
	case 12935ULL: goto x86_l_3287;
	case 12937ULL: goto x86_l_3289;
	case 12942ULL: goto x86_l_328e;
	case 12944ULL: goto x86_l_3290;
	case 12949ULL: goto x86_l_3295;
	case 12951ULL: goto x86_l_3297;
	case 12954ULL: goto x86_l_329a;
	case 12959ULL: goto x86_l_329f;
	case 12962ULL: goto x86_l_32a2;
	case 12968ULL: goto x86_l_32a8;
	case 12975ULL: goto x86_l_32af;
	case 12979ULL: goto x86_l_32b3;
	case 12984ULL: goto x86_l_32b8;
	case 12988ULL: goto x86_l_32bc;
	case 12993ULL: goto x86_l_32c1;
	case 13000ULL: goto x86_l_32c8;
	case 13005ULL: goto x86_l_32cd;
	case 13008ULL: goto x86_l_32d0;
	case 13010ULL: goto x86_l_32d2;
	case 13013ULL: goto x86_l_32d5;
	case 13018ULL: goto x86_l_32da;
	case 13025ULL: goto x86_l_32e1;
	case 13028ULL: goto x86_l_32e4;
	case 13030ULL: goto x86_l_32e6;
	case 13035ULL: goto x86_l_32eb;
	case 13038ULL: goto x86_l_32ee;
	case 13044ULL: goto x86_l_32f4;
	case 13050ULL: goto x86_l_32fa;
	case 13053ULL: goto x86_l_32fd;
	case 13058ULL: goto x86_l_3302;
	case 13063ULL: goto x86_l_3307;
	case 13068ULL: goto x86_l_330c;
	case 13074ULL: goto x86_l_3312;
	case 13077ULL: goto x86_l_3315;
	case 13081ULL: goto x86_l_3319;
	case 13084ULL: goto x86_l_331c;
	case 13086ULL: goto x86_l_331e;
	case 13091ULL: goto x86_l_3323;
	case 13094ULL: goto x86_l_3326;
	case 13098ULL: goto x86_l_332a;
	case 13103ULL: goto x86_l_332f;
	case 13105ULL: goto x86_l_3331;
	case 13109ULL: goto x86_l_3335;
	case 13111ULL: goto x86_l_3337;
	case 13116ULL: goto x86_l_333c;
	case 13118ULL: goto x86_l_333e;
	case 13120ULL: goto x86_l_3340;
	case 13125ULL: goto x86_l_3345;
	case 13129ULL: goto x86_l_3349;
	case 13132ULL: goto x86_l_334c;
	case 13138ULL: goto x86_l_3352;
	case 13143ULL: goto x86_l_3357;
	case 13145ULL: goto x86_l_3359;
	case 13150ULL: goto x86_l_335e;
	case 13153ULL: goto x86_l_3361;
	case 13157ULL: goto x86_l_3365;
	case 13162ULL: goto x86_l_336a;
	case 13164ULL: goto x86_l_336c;
	case 13168ULL: goto x86_l_3370;
	case 13170ULL: goto x86_l_3372;
	case 13175ULL: goto x86_l_3377;
	case 13177ULL: goto x86_l_3379;
	case 13179ULL: goto x86_l_337b;
	case 13184ULL: goto x86_l_3380;
	case 13188ULL: goto x86_l_3384;
	case 13192ULL: goto x86_l_3388;
	case 13198ULL: goto x86_l_338e;
	case 13203ULL: goto x86_l_3393;
	case 13206ULL: goto x86_l_3396;
	case 13208ULL: goto x86_l_3398;
	case 13215ULL: goto x86_l_339f;
	case 13219ULL: goto x86_l_33a3;
	case 13222ULL: goto x86_l_33a6;
	case 13224ULL: goto x86_l_33a8;
	case 13227ULL: goto x86_l_33ab;
	case 13233ULL: goto x86_l_33b1;
	case 13236ULL: goto x86_l_33b4;
	case 13242ULL: goto x86_l_33ba;
	case 13245ULL: goto x86_l_33bd;
	case 13251ULL: goto x86_l_33c3;
	case 13254ULL: goto x86_l_33c6;
	case 13260ULL: goto x86_l_33cc;
	case 13265ULL: goto x86_l_33d1;
	case 13272ULL: goto x86_l_33d8;
	case 13277ULL: goto x86_l_33dd;
	case 13280ULL: goto x86_l_33e0;
	case 13286ULL: goto x86_l_33e6;
	case 13289ULL: goto x86_l_33e9;
	case 13295ULL: goto x86_l_33ef;
	case 13298ULL: goto x86_l_33f2;
	case 13304ULL: goto x86_l_33f8;
	case 13307ULL: goto x86_l_33fb;
	case 13313ULL: goto x86_l_3401;
	case 13318ULL: goto x86_l_3406;
	case 13325ULL: goto x86_l_340d;
	case 13330ULL: goto x86_l_3412;
	case 13332ULL: goto x86_l_3414;
	case 13338ULL: goto x86_l_341a;
	case 13340ULL: goto x86_l_341c;
	case 13346ULL: goto x86_l_3422;
	case 13351ULL: goto x86_l_3427;
	case 13354ULL: goto x86_l_342a;
	case 13358ULL: goto x86_l_342e;
	case 13360ULL: goto x86_l_3430;
	case 13363ULL: goto x86_l_3433;
	case 13369ULL: goto x86_l_3439;
	case 13372ULL: goto x86_l_343c;
	case 13378ULL: goto x86_l_3442;
	case 13383ULL: goto x86_l_3447;
	case 13388ULL: goto x86_l_344c;
	case 13393ULL: goto x86_l_3451;
	case 13398ULL: goto x86_l_3456;
	case 13401ULL: goto x86_l_3459;
	case 13406ULL: goto x86_l_345e;
	case 13411ULL: goto x86_l_3463;
	case 13418ULL: goto x86_l_346a;
	case 13420ULL: goto x86_l_346c;
	case 13425ULL: goto x86_l_3471;
	case 13432ULL: goto x86_l_3478;
	case 13434ULL: goto x86_l_347a;
	case 13439ULL: goto x86_l_347f;
	case 13446ULL: goto x86_l_3486;
	case 13448ULL: goto x86_l_3488;
	case 13453ULL: goto x86_l_348d;
	case 13460ULL: goto x86_l_3494;
	case 13462ULL: goto x86_l_3496;
	case 13467ULL: goto x86_l_349b;
	case 13474ULL: goto x86_l_34a2;
	case 13476ULL: goto x86_l_34a4;
	case 13481ULL: goto x86_l_34a9;
	case 13488ULL: goto x86_l_34b0;
	case 13490ULL: goto x86_l_34b2;
	case 13495ULL: goto x86_l_34b7;
	case 13502ULL: goto x86_l_34be;
	case 13507ULL: goto x86_l_34c3;
	case 13509ULL: goto x86_l_34c5;
	case 13512ULL: goto x86_l_34c8;
	case 13514ULL: goto x86_l_34ca;
	case 13519ULL: goto x86_l_34cf;
	case 13522ULL: goto x86_l_34d2;
	case 13525ULL: goto x86_l_34d5;
	case 13527ULL: goto x86_l_34d7;
	case 13530ULL: goto x86_l_34da;
	case 13533ULL: goto x86_l_34dd;
	case 13537ULL: goto x86_l_34e1;
	case 13539ULL: goto x86_l_34e3;
	case 13542ULL: goto x86_l_34e6;
	case 13547ULL: goto x86_l_34eb;
	case 13552ULL: goto x86_l_34f0;
	case 13557ULL: goto x86_l_34f5;
	case 13561ULL: goto x86_l_34f9;
	case 13565ULL: goto x86_l_34fd;
	case 13571ULL: goto x86_l_3503;
	case 13581ULL: goto x86_l_350d;
	case 13585ULL: goto x86_l_3511;
	case 13590ULL: goto x86_l_3516;
	case 13596ULL: goto x86_l_351c;
	case 13601ULL: goto x86_l_3521;
	case 13606ULL: goto x86_l_3526;
	case 13613ULL: goto x86_l_352d;
	case 13615ULL: goto x86_l_352f;
	case 13620ULL: goto x86_l_3534;
	case 13627ULL: goto x86_l_353b;
	case 13629ULL: goto x86_l_353d;
	case 13634ULL: goto x86_l_3542;
	case 13641ULL: goto x86_l_3549;
	case 13643ULL: goto x86_l_354b;
	case 13648ULL: goto x86_l_3550;
	case 13655ULL: goto x86_l_3557;
	case 13657ULL: goto x86_l_3559;
	case 13662ULL: goto x86_l_355e;
	case 13669ULL: goto x86_l_3565;
	case 13671ULL: goto x86_l_3567;
	case 13676ULL: goto x86_l_356c;
	case 13683ULL: goto x86_l_3573;
	case 13685ULL: goto x86_l_3575;
	case 13690ULL: goto x86_l_357a;
	case 13697ULL: goto x86_l_3581;
	case 13702ULL: goto x86_l_3586;
	case 13704ULL: goto x86_l_3588;
	case 13707ULL: goto x86_l_358b;
	case 13709ULL: goto x86_l_358d;
	case 13714ULL: goto x86_l_3592;
	case 13717ULL: goto x86_l_3595;
	case 13722ULL: goto x86_l_359a;
	case 13724ULL: goto x86_l_359c;
	case 13727ULL: goto x86_l_359f;
	case 13730ULL: goto x86_l_35a2;
	case 13734ULL: goto x86_l_35a6;
	case 13736ULL: goto x86_l_35a8;
	case 13739ULL: goto x86_l_35ab;
	case 13744ULL: goto x86_l_35b0;
	case 13749ULL: goto x86_l_35b5;
	case 13754ULL: goto x86_l_35ba;
	case 13759ULL: goto x86_l_35bf;
	case 13763ULL: goto x86_l_35c3;
	case 13767ULL: goto x86_l_35c7;
	case 13773ULL: goto x86_l_35cd;
	case 13783ULL: goto x86_l_35d7;
	case 13787ULL: goto x86_l_35db;
	case 13793ULL: goto x86_l_35e1;
	case 13798ULL: goto x86_l_35e6;
	case 13801ULL: goto x86_l_35e9;
	case 13806ULL: goto x86_l_35ee;
	case 13811ULL: goto x86_l_35f3;
	case 13815ULL: goto x86_l_35f7;
	case 13819ULL: goto x86_l_35fb;
	case 13821ULL: goto x86_l_35fd;
	case 13826ULL: goto x86_l_3602;
	case 13830ULL: goto x86_l_3606;
	case 13833ULL: goto x86_l_3609;
	case 13835ULL: goto x86_l_360b;
	case 13841ULL: goto x86_l_3611;
	case 13844ULL: goto x86_l_3614;
	case 13850ULL: goto x86_l_361a;
	case 13854ULL: goto x86_l_361e;
	case 13857ULL: goto x86_l_3621;
	case 13863ULL: goto x86_l_3627;
	case 13866ULL: goto x86_l_362a;
	case 13869ULL: goto x86_l_362d;
	case 13875ULL: goto x86_l_3633;
	case 13878ULL: goto x86_l_3636;
	case 13884ULL: goto x86_l_363c;
	case 13887ULL: goto x86_l_363f;
	case 13893ULL: goto x86_l_3645;
	case 13897ULL: goto x86_l_3649;
	case 13900ULL: goto x86_l_364c;
	case 13902ULL: goto x86_l_364e;
	case 13906ULL: goto x86_l_3652;
	case 13909ULL: goto x86_l_3655;
	case 13911ULL: goto x86_l_3657;
	case 13917ULL: goto x86_l_365d;
	case 13920ULL: goto x86_l_3660;
	case 13926ULL: goto x86_l_3666;
	case 13930ULL: goto x86_l_366a;
	case 13933ULL: goto x86_l_366d;
	case 13939ULL: goto x86_l_3673;
	case 13942ULL: goto x86_l_3676;
	case 13945ULL: goto x86_l_3679;
	case 13951ULL: goto x86_l_367f;
	case 13954ULL: goto x86_l_3682;
	case 13960ULL: goto x86_l_3688;
	case 13963ULL: goto x86_l_368b;
	case 13969ULL: goto x86_l_3691;
	case 13973ULL: goto x86_l_3695;
	case 13976ULL: goto x86_l_3698;
	case 13978ULL: goto x86_l_369a;
	case 13984ULL: goto x86_l_36a0;
	case 13989ULL: goto x86_l_36a5;
	case 13992ULL: goto x86_l_36a8;
	case 13998ULL: goto x86_l_36ae;
	case 14001ULL: goto x86_l_36b1;
	case 14007ULL: goto x86_l_36b7;
	case 14010ULL: goto x86_l_36ba;
	case 14016ULL: goto x86_l_36c0;
	case 14021ULL: goto x86_l_36c5;
	case 14028ULL: goto x86_l_36cc;
	case 14033ULL: goto x86_l_36d1;
	case 14037ULL: goto x86_l_36d5;
	case 14040ULL: goto x86_l_36d8;
	case 14046ULL: goto x86_l_36de;
	case 14048ULL: goto x86_l_36e0;
	case 14052ULL: goto x86_l_36e4;
	case 14055ULL: goto x86_l_36e7;
	case 14061ULL: goto x86_l_36ed;
	case 14064ULL: goto x86_l_36f0;
	case 14070ULL: goto x86_l_36f6;
	case 14074ULL: goto x86_l_36fa;
	case 14077ULL: goto x86_l_36fd;
	case 14079ULL: goto x86_l_36ff;
	case 14082ULL: goto x86_l_3702;
	case 14085ULL: goto x86_l_3705;
	case 14087ULL: goto x86_l_3707;
	case 14090ULL: goto x86_l_370a;
	case 14096ULL: goto x86_l_3710;
	case 14099ULL: goto x86_l_3713;
	case 14105ULL: goto x86_l_3719;
	case 14109ULL: goto x86_l_371d;
	case 14111ULL: goto x86_l_371f;
	case 14117ULL: goto x86_l_3725;
	case 14122ULL: goto x86_l_372a;
	case 14125ULL: goto x86_l_372d;
	case 14127ULL: goto x86_l_372f;
	case 14130ULL: goto x86_l_3732;
	case 14136ULL: goto x86_l_3738;
	case 14139ULL: goto x86_l_373b;
	case 14145ULL: goto x86_l_3741;
	case 14150ULL: goto x86_l_3746;
	case 14153ULL: goto x86_l_3749;
	case 14159ULL: goto x86_l_374f;
	case 14163ULL: goto x86_l_3753;
	case 14165ULL: goto x86_l_3755;
	case 14171ULL: goto x86_l_375b;
	case 14176ULL: goto x86_l_3760;
	case 14180ULL: goto x86_l_3764;
	case 14182ULL: goto x86_l_3766;
	case 14188ULL: goto x86_l_376c;
	case 14193ULL: goto x86_l_3771;
	case 14196ULL: goto x86_l_3774;
	case 14202ULL: goto x86_l_377a;
	case 14207ULL: goto x86_l_377f;
	case 14210ULL: goto x86_l_3782;
	case 14216ULL: goto x86_l_3788;
	case 14220ULL: goto x86_l_378c;
	case 14222ULL: goto x86_l_378e;
	case 14228ULL: goto x86_l_3794;
	case 14233ULL: goto x86_l_3799;
	case 14235ULL: goto x86_l_379b;
	case 14241ULL: goto x86_l_37a1;
	case 14244ULL: goto x86_l_37a4;
	case 14250ULL: goto x86_l_37aa;
	case 14255ULL: goto x86_l_37af;
	case 14262ULL: goto x86_l_37b6;
	case 14267ULL: goto x86_l_37bb;
	case 14270ULL: goto x86_l_37be;
	case 14276ULL: goto x86_l_37c4;
	case 14279ULL: goto x86_l_37c7;
	case 14285ULL: goto x86_l_37cd;
	case 14289ULL: goto x86_l_37d1;
	case 14292ULL: goto x86_l_37d4;
	case 14294ULL: goto x86_l_37d6;
	case 14297ULL: goto x86_l_37d9;
	case 14303ULL: goto x86_l_37df;
	case 14306ULL: goto x86_l_37e2;
	case 14312ULL: goto x86_l_37e8;
	case 14316ULL: goto x86_l_37ec;
	case 14319ULL: goto x86_l_37ef;
	case 14321ULL: goto x86_l_37f1;
	case 14327ULL: goto x86_l_37f7;
	case 14332ULL: goto x86_l_37fc;
	case 14336ULL: goto x86_l_3800;
	case 14339ULL: goto x86_l_3803;
	case 14341ULL: goto x86_l_3805;
	case 14345ULL: goto x86_l_3809;
	case 14348ULL: goto x86_l_380c;
	case 14350ULL: goto x86_l_380e;
	case 14356ULL: goto x86_l_3814;
	case 14361ULL: goto x86_l_3819;
	case 14365ULL: goto x86_l_381d;
	case 14368ULL: goto x86_l_3820;
	case 14374ULL: goto x86_l_3826;
	case 14379ULL: goto x86_l_382b;
	case 14382ULL: goto x86_l_382e;
	case 14388ULL: goto x86_l_3834;
	case 14393ULL: goto x86_l_3839;
	case 14398ULL: goto x86_l_383e;
	case 14405ULL: goto x86_l_3845;
	case 14407ULL: goto x86_l_3847;
	case 14412ULL: goto x86_l_384c;
	case 14419ULL: goto x86_l_3853;
	case 14421ULL: goto x86_l_3855;
	case 14426ULL: goto x86_l_385a;
	case 14433ULL: goto x86_l_3861;
	case 14435ULL: goto x86_l_3863;
	case 14440ULL: goto x86_l_3868;
	case 14447ULL: goto x86_l_386f;
	case 14449ULL: goto x86_l_3871;
	case 14454ULL: goto x86_l_3876;
	case 14461ULL: goto x86_l_387d;
	case 14463ULL: goto x86_l_387f;
	case 14468ULL: goto x86_l_3884;
	case 14475ULL: goto x86_l_388b;
	case 14477ULL: goto x86_l_388d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3233:
	/* 0x3233: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3238:
	/* 0x3238: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_323f:
	/* 0x323f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3244:
	/* 0x3244: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3246:
	/* 0x3246: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3249:
	/* 0x3249: je     3266 <generic_fentry_filter_arg+0x3266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3266;
	}
x86_l_324b:
	/* 0x324b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3250:
	/* 0x3250: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3253:
	/* 0x3253: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3258:
	/* 0x3258: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_325a:
	/* 0x325a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_325d:
	/* 0x325d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3260:
	/* 0x3260: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_3264:
	/* 0x3264: jmp    3269 <generic_fentry_filter_arg+0x3269> */
	goto x86_l_3269;
x86_l_3266:
	/* 0x3266: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3269:
	/* 0x3269: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_326e:
	/* 0x326e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3273:
	/* 0x3273: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3278:
	/* 0x3278: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_327d:
	/* 0x327d: jmp    1d32 <generic_fentry_filter_arg+0x1d32> */
	return 7474ULL;
x86_l_3282:
	/* 0x3282: mov    ecx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_3287:
	/* 0x3287: jmp    3295 <generic_fentry_filter_arg+0x3295> */
	goto x86_l_3295;
x86_l_3289:
	/* 0x3289: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_328e:
	/* 0x328e: jmp    3295 <generic_fentry_filter_arg+0x3295> */
	goto x86_l_3295;
x86_l_3290:
	/* 0x3290: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3295:
	/* 0x3295: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_3297:
	/* 0x3297: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_329a:
	/* 0x329a: mov    eax,DWORD PTR [r13+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_329f:
	/* 0x329f: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_32a2:
	/* 0x32a2: je     38c0 <generic_fentry_filter_arg+0x38c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14528ULL;
	}
x86_l_32a8:
	/* 0x32a8: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_32af:
	/* 0x32af: mov    DWORD PTR [rsp+0x3c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_32b3:
	/* 0x32b3: mov    QWORD PTR [rsp+0x40],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_32b8:
	/* 0x32b8: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32bc:
	/* 0x32bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32c1:
	/* 0x32c1: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_32c8:
	/* 0x32c8: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32cd:
	/* 0x32cd: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_32d0:
	/* 0x32d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32d2:
	/* 0x32d2: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_32d5:
	/* 0x32d5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32da:
	/* 0x32da: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_32e1:
	/* 0x32e1: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_32e4:
	/* 0x32e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e6:
	/* 0x32e6: mov    QWORD PTR [rsp+0x28],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32eb:
	/* 0x32eb: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_32ee:
	/* 0x32ee: je     38c0 <generic_fentry_filter_arg+0x38c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14528ULL;
	}
x86_l_32f4:
	/* 0x32f4: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_32fa:
	/* 0x32fa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32fd:
	/* 0x32fd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3302:
	/* 0x3302: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3307:
	/* 0x3307: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_330c:
	/* 0x330c: je     38d2 <generic_fentry_filter_arg+0x38d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14546ULL;
	}
x86_l_3312:
	/* 0x3312: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3315:
	/* 0x3315: mov    ebx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_3319:
	/* 0x3319: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_331c:
	/* 0x331c: jg     3359 <generic_fentry_filter_arg+0x3359> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3359;
	}
x86_l_331e:
	/* 0x331e: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3323:
	/* 0x3323: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3326:
	/* 0x3326: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_332a:
	/* 0x332a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_332f:
	/* 0x332f: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_3331:
	/* 0x3331: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3335:
	/* 0x3335: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3337:
	/* 0x3337: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_333c:
	/* 0x333c: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_333e:
	/* 0x333e: jbe    3398 <generic_fentry_filter_arg+0x3398> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3398;
	}
x86_l_3340:
	/* 0x3340: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3345:
	/* 0x3345: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3349:
	/* 0x3349: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_334c:
	/* 0x334c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3352:
	/* 0x3352: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3357:
	/* 0x3357: jmp    3393 <generic_fentry_filter_arg+0x3393> */
	goto x86_l_3393;
x86_l_3359:
	/* 0x3359: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_335e:
	/* 0x335e: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3361:
	/* 0x3361: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3365:
	/* 0x3365: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_336a:
	/* 0x336a: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_336c:
	/* 0x336c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3370:
	/* 0x3370: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3372:
	/* 0x3372: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3377:
	/* 0x3377: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3379:
	/* 0x3379: jbe    3398 <generic_fentry_filter_arg+0x3398> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3398;
	}
x86_l_337b:
	/* 0x337b: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3380:
	/* 0x3380: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3384:
	/* 0x3384: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3388:
	/* 0x3388: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_338e:
	/* 0x338e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3393:
	/* 0x3393: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3396:
	/* 0x3396: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3398:
	/* 0x3398: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_339f:
	/* 0x339f: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_33a3:
	/* 0x33a3: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_33a6:
	/* 0x33a6: jle    33dd <generic_fentry_filter_arg+0x33dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_33dd;
	}
x86_l_33a8:
	/* 0x33a8: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_33ab:
	/* 0x33ab: jg     36a5 <generic_fentry_filter_arg+0x36a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_36a5;
	}
x86_l_33b1:
	/* 0x33b1: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_33b4:
	/* 0x33b4: je     387f <generic_fentry_filter_arg+0x387f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_387f;
	}
x86_l_33ba:
	/* 0x33ba: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_33bd:
	/* 0x33bd: je     3855 <generic_fentry_filter_arg+0x3855> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3855;
	}
x86_l_33c3:
	/* 0x33c3: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_33c6:
	/* 0x33c6: jne    38c0 <generic_fentry_filter_arg+0x38c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14528ULL;
	}
x86_l_33cc:
	/* 0x33cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33d1:
	/* 0x33d1: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_33d8:
	/* 0x33d8: jmp    3899 <generic_fentry_filter_arg+0x3899> */
	return 14489ULL;
x86_l_33dd:
	/* 0x33dd: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_33e0:
	/* 0x33e0: jle    3799 <generic_fentry_filter_arg+0x3799> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3799;
	}
x86_l_33e6:
	/* 0x33e6: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_33e9:
	/* 0x33e9: je     3871 <generic_fentry_filter_arg+0x3871> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3871;
	}
x86_l_33ef:
	/* 0x33ef: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_33f2:
	/* 0x33f2: je     3847 <generic_fentry_filter_arg+0x3847> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3847;
	}
x86_l_33f8:
	/* 0x33f8: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_33fb:
	/* 0x33fb: jne    38c0 <generic_fentry_filter_arg+0x38c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14528ULL;
	}
x86_l_3401:
	/* 0x3401: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3406:
	/* 0x3406: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_340d:
	/* 0x340d: jmp    3899 <generic_fentry_filter_arg+0x3899> */
	return 14489ULL;
x86_l_3412:
	/* 0x3412: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_3414:
	/* 0x3414: ja     108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 264ULL;
	}
x86_l_341a:
	/* 0x341a: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_341c:
	/* 0x341c: jbe    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 697ULL;
	}
x86_l_3422:
	/* 0x3422: jmp    108 <generic_fentry_filter_arg+0x108> */
	return 264ULL;
x86_l_3427:
	/* 0x3427: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_342a:
	/* 0x342a: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_342e:
	/* 0x342e: je     3439 <generic_fentry_filter_arg+0x3439> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3439;
	}
x86_l_3430:
	/* 0x3430: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_3433:
	/* 0x3433: jne    382b <generic_fentry_filter_arg+0x382b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_382b;
	}
x86_l_3439:
	/* 0x3439: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_343c:
	/* 0x343c: jg     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 697ULL;
	}
x86_l_3442:
	/* 0x3442: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	return 14690ULL;
x86_l_3447:
	/* 0x3447: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_344c:
	/* 0x344c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3451:
	/* 0x3451: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3456:
	/* 0x3456: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_3459:
	/* 0x3459: jmp    1ceb <generic_fentry_filter_arg+0x1ceb> */
	return 7403ULL;
x86_l_345e:
	/* 0x345e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3463:
	/* 0x3463: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_346a:
	/* 0x346a: jmp    34be <generic_fentry_filter_arg+0x34be> */
	goto x86_l_34be;
x86_l_346c:
	/* 0x346c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3471:
	/* 0x3471: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_3478:
	/* 0x3478: jmp    34be <generic_fentry_filter_arg+0x34be> */
	goto x86_l_34be;
x86_l_347a:
	/* 0x347a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_347f:
	/* 0x347f: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_3486:
	/* 0x3486: jmp    34be <generic_fentry_filter_arg+0x34be> */
	goto x86_l_34be;
x86_l_3488:
	/* 0x3488: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_348d:
	/* 0x348d: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_3494:
	/* 0x3494: jmp    34be <generic_fentry_filter_arg+0x34be> */
	goto x86_l_34be;
x86_l_3496:
	/* 0x3496: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_349b:
	/* 0x349b: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_34a2:
	/* 0x34a2: jmp    34be <generic_fentry_filter_arg+0x34be> */
	goto x86_l_34be;
x86_l_34a4:
	/* 0x34a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34a9:
	/* 0x34a9: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_34b0:
	/* 0x34b0: jmp    34be <generic_fentry_filter_arg+0x34be> */
	goto x86_l_34be;
x86_l_34b2:
	/* 0x34b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34b7:
	/* 0x34b7: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_34be:
	/* 0x34be: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_34c3:
	/* 0x34c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34c5:
	/* 0x34c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34c8:
	/* 0x34c8: je     34e3 <generic_fentry_filter_arg+0x34e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34e3;
	}
x86_l_34ca:
	/* 0x34ca: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_34cf:
	/* 0x34cf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_34d2:
	/* 0x34d2: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_34d5:
	/* 0x34d5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_34d7:
	/* 0x34d7: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34da:
	/* 0x34da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34dd:
	/* 0x34dd: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_34e1:
	/* 0x34e1: jmp    34e6 <generic_fentry_filter_arg+0x34e6> */
	goto x86_l_34e6;
x86_l_34e3:
	/* 0x34e3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34e6:
	/* 0x34e6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34eb:
	/* 0x34eb: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34f0:
	/* 0x34f0: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34f5:
	/* 0x34f5: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_34f9:
	/* 0x34f9: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_34fd:
	/* 0x34fd: ja     3905 <generic_fentry_filter_arg+0x3905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14597ULL;
	}
x86_l_3503:
	/* 0x3503: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_350d:
	/* 0x350d: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3511:
	/* 0x3511: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3516:
	/* 0x3516: jb     1d54 <generic_fentry_filter_arg+0x1d54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7508ULL;
	}
x86_l_351c:
	/* 0x351c: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_3521:
	/* 0x3521: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3526:
	/* 0x3526: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_352d:
	/* 0x352d: jmp    3581 <generic_fentry_filter_arg+0x3581> */
	goto x86_l_3581;
x86_l_352f:
	/* 0x352f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3534:
	/* 0x3534: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_353b:
	/* 0x353b: jmp    3581 <generic_fentry_filter_arg+0x3581> */
	goto x86_l_3581;
x86_l_353d:
	/* 0x353d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3542:
	/* 0x3542: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_3549:
	/* 0x3549: jmp    3581 <generic_fentry_filter_arg+0x3581> */
	goto x86_l_3581;
x86_l_354b:
	/* 0x354b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3550:
	/* 0x3550: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_3557:
	/* 0x3557: jmp    3581 <generic_fentry_filter_arg+0x3581> */
	goto x86_l_3581;
x86_l_3559:
	/* 0x3559: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_355e:
	/* 0x355e: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3565:
	/* 0x3565: jmp    3581 <generic_fentry_filter_arg+0x3581> */
	goto x86_l_3581;
x86_l_3567:
	/* 0x3567: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_356c:
	/* 0x356c: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3573:
	/* 0x3573: jmp    3581 <generic_fentry_filter_arg+0x3581> */
	goto x86_l_3581;
x86_l_3575:
	/* 0x3575: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_357a:
	/* 0x357a: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_3581:
	/* 0x3581: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3586:
	/* 0x3586: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3588:
	/* 0x3588: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_358b:
	/* 0x358b: je     35a8 <generic_fentry_filter_arg+0x35a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35a8;
	}
x86_l_358d:
	/* 0x358d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3592:
	/* 0x3592: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3595:
	/* 0x3595: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_359a:
	/* 0x359a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_359c:
	/* 0x359c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_359f:
	/* 0x359f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35a2:
	/* 0x35a2: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_35a6:
	/* 0x35a6: jmp    35ab <generic_fentry_filter_arg+0x35ab> */
	goto x86_l_35ab;
x86_l_35a8:
	/* 0x35a8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35ab:
	/* 0x35ab: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35b0:
	/* 0x35b0: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35b5:
	/* 0x35b5: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35ba:
	/* 0x35ba: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35bf:
	/* 0x35bf: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_35c3:
	/* 0x35c3: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_35c7:
	/* 0x35c7: ja     2a8 <generic_fentry_filter_arg+0x2a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 680ULL;
	}
x86_l_35cd:
	/* 0x35cd: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_35d7:
	/* 0x35d7: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_35db:
	/* 0x35db: jb     38f5 <generic_fentry_filter_arg+0x38f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14581ULL;
	}
x86_l_35e1:
	/* 0x35e1: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_35e6:
	/* 0x35e6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35e9:
	/* 0x35e9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35ee:
	/* 0x35ee: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35f3:
	/* 0x35f3: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_35f7:
	/* 0x35f7: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_35fb:
	/* 0x35fb: jbe    35cd <generic_fentry_filter_arg+0x35cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_35cd;
	}
x86_l_35fd:
	/* 0x35fd: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_3602:
	/* 0x3602: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3606:
	/* 0x3606: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3609:
	/* 0x3609: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_360b:
	/* 0x360b: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_3611:
	/* 0x3611: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_3614:
	/* 0x3614: jb     3962 <generic_fentry_filter_arg+0x3962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14690ULL;
	}
x86_l_361a:
	/* 0x361a: mov    ecx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_361e:
	/* 0x361e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3621:
	/* 0x3621: jle    37bb <generic_fentry_filter_arg+0x37bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_37bb;
	}
x86_l_3627:
	/* 0x3627: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_362a:
	/* 0x362a: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_362d:
	/* 0x362d: jb     37fc <generic_fentry_filter_arg+0x37fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37fc;
	}
x86_l_3633:
	/* 0x3633: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3636:
	/* 0x3636: je     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 697ULL;
	}
x86_l_363c:
	/* 0x363c: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_363f:
	/* 0x363f: jne    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 264ULL;
	}
x86_l_3645:
	/* 0x3645: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3649:
	/* 0x3649: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_364c:
	/* 0x364c: jmp    3698 <generic_fentry_filter_arg+0x3698> */
	goto x86_l_3698;
x86_l_364e:
	/* 0x364e: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3652:
	/* 0x3652: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3655:
	/* 0x3655: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_3657:
	/* 0x3657: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_365d:
	/* 0x365d: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_3660:
	/* 0x3660: jb     3962 <generic_fentry_filter_arg+0x3962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14690ULL;
	}
x86_l_3666:
	/* 0x3666: mov    ecx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_366a:
	/* 0x366a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_366d:
	/* 0x366d: jle    37d6 <generic_fentry_filter_arg+0x37d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_37d6;
	}
x86_l_3673:
	/* 0x3673: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3676:
	/* 0x3676: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3679:
	/* 0x3679: jb     3805 <generic_fentry_filter_arg+0x3805> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3805;
	}
x86_l_367f:
	/* 0x367f: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3682:
	/* 0x3682: je     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 697ULL;
	}
x86_l_3688:
	/* 0x3688: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_368b:
	/* 0x368b: jne    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 264ULL;
	}
x86_l_3691:
	/* 0x3691: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3695:
	/* 0x3695: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3698:
	/* 0x3698: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_369a:
	/* 0x369a: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_36a0:
	/* 0x36a0: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	return 14690ULL;
x86_l_36a5:
	/* 0x36a5: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_36a8:
	/* 0x36a8: je     388d <generic_fentry_filter_arg+0x388d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_388d;
	}
x86_l_36ae:
	/* 0x36ae: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_36b1:
	/* 0x36b1: je     3863 <generic_fentry_filter_arg+0x3863> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3863;
	}
x86_l_36b7:
	/* 0x36b7: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_36ba:
	/* 0x36ba: jne    38c0 <generic_fentry_filter_arg+0x38c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14528ULL;
	}
x86_l_36c0:
	/* 0x36c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36c5:
	/* 0x36c5: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_36cc:
	/* 0x36cc: jmp    3899 <generic_fentry_filter_arg+0x3899> */
	return 14489ULL;
x86_l_36d1:
	/* 0x36d1: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36d5:
	/* 0x36d5: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36d8:
	/* 0x36d8: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_36de:
	/* 0x36de: jmp    36ed <generic_fentry_filter_arg+0x36ed> */
	goto x86_l_36ed;
x86_l_36e0:
	/* 0x36e0: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36e4:
	/* 0x36e4: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36e7:
	/* 0x36e7: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_36ed:
	/* 0x36ed: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_36f0:
	/* 0x36f0: jb     3962 <generic_fentry_filter_arg+0x3962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14690ULL;
	}
x86_l_36f6:
	/* 0x36f6: mov    edx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_36fa:
	/* 0x36fa: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_36fd:
	/* 0x36fd: jle    372a <generic_fentry_filter_arg+0x372a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_372a;
	}
x86_l_36ff:
	/* 0x36ff: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3702:
	/* 0x3702: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3705:
	/* 0x3705: jb     3760 <generic_fentry_filter_arg+0x3760> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3760;
	}
x86_l_3707:
	/* 0x3707: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_370a:
	/* 0x370a: je     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 697ULL;
	}
x86_l_3710:
	/* 0x3710: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3713:
	/* 0x3713: jne    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 264ULL;
	}
x86_l_3719:
	/* 0x3719: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_371d:
	/* 0x371d: test   DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_371f:
	/* 0x371f: jne    2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 697ULL;
	}
x86_l_3725:
	/* 0x3725: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	return 14690ULL;
x86_l_372a:
	/* 0x372a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_372d:
	/* 0x372d: je     3771 <generic_fentry_filter_arg+0x3771> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3771;
	}
x86_l_372f:
	/* 0x372f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3732:
	/* 0x3732: jne    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 264ULL;
	}
x86_l_3738:
	/* 0x3738: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_373b:
	/* 0x373b: ja     3948 <generic_fentry_filter_arg+0x3948> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14664ULL;
	}
x86_l_3741:
	/* 0x3741: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_3746:
	/* 0x3746: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_3749:
	/* 0x3749: jae    3948 <generic_fentry_filter_arg+0x3948> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14664ULL;
	}
x86_l_374f:
	/* 0x374f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3753:
	/* 0x3753: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3755:
	/* 0x3755: jl     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 697ULL;
	}
x86_l_375b:
	/* 0x375b: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	return 14690ULL;
x86_l_3760:
	/* 0x3760: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3764:
	/* 0x3764: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3766:
	/* 0x3766: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 670ULL;
	}
x86_l_376c:
	/* 0x376c: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	return 14690ULL;
x86_l_3771:
	/* 0x3771: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_3774:
	/* 0x3774: ja     3956 <generic_fentry_filter_arg+0x3956> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14678ULL;
	}
x86_l_377a:
	/* 0x377a: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_377f:
	/* 0x377f: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_3782:
	/* 0x3782: jae    3956 <generic_fentry_filter_arg+0x3956> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14678ULL;
	}
x86_l_3788:
	/* 0x3788: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_378c:
	/* 0x378c: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_378e:
	/* 0x378e: jg     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 697ULL;
	}
x86_l_3794:
	/* 0x3794: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	return 14690ULL;
x86_l_3799:
	/* 0x3799: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_379b:
	/* 0x379b: je     3839 <generic_fentry_filter_arg+0x3839> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3839;
	}
x86_l_37a1:
	/* 0x37a1: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_37a4:
	/* 0x37a4: jne    38c0 <generic_fentry_filter_arg+0x38c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14528ULL;
	}
x86_l_37aa:
	/* 0x37aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37af:
	/* 0x37af: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_37b6:
	/* 0x37b6: jmp    3899 <generic_fentry_filter_arg+0x3899> */
	return 14489ULL;
x86_l_37bb:
	/* 0x37bb: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37be:
	/* 0x37be: je     392e <generic_fentry_filter_arg+0x392e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14638ULL;
	}
x86_l_37c4:
	/* 0x37c4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_37c7:
	/* 0x37c7: jne    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 264ULL;
	}
x86_l_37cd:
	/* 0x37cd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37d1:
	/* 0x37d1: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_37d4:
	/* 0x37d4: jmp    37ef <generic_fentry_filter_arg+0x37ef> */
	goto x86_l_37ef;
x86_l_37d6:
	/* 0x37d6: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37d9:
	/* 0x37d9: je     3937 <generic_fentry_filter_arg+0x3937> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14647ULL;
	}
x86_l_37df:
	/* 0x37df: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_37e2:
	/* 0x37e2: jne    108 <generic_fentry_filter_arg+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 264ULL;
	}
x86_l_37e8:
	/* 0x37e8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37ec:
	/* 0x37ec: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37ef:
	/* 0x37ef: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_37f1:
	/* 0x37f1: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_37f7:
	/* 0x37f7: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	return 14690ULL;
x86_l_37fc:
	/* 0x37fc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3800:
	/* 0x3800: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3803:
	/* 0x3803: jmp    380c <generic_fentry_filter_arg+0x380c> */
	goto x86_l_380c;
x86_l_3805:
	/* 0x3805: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3809:
	/* 0x3809: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_380c:
	/* 0x380c: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_380e:
	/* 0x380e: je     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 670ULL;
	}
x86_l_3814:
	/* 0x3814: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	return 14690ULL;
x86_l_3819:
	/* 0x3819: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_381d:
	/* 0x381d: cmp    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3820:
	/* 0x3820: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_3826:
	/* 0x3826: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	return 14690ULL;
x86_l_382b:
	/* 0x382b: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_382e:
	/* 0x382e: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_3834:
	/* 0x3834: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	return 14690ULL;
x86_l_3839:
	/* 0x3839: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_383e:
	/* 0x383e: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_3845:
	/* 0x3845: jmp    3899 <generic_fentry_filter_arg+0x3899> */
	return 14489ULL;
x86_l_3847:
	/* 0x3847: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_384c:
	/* 0x384c: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_3853:
	/* 0x3853: jmp    3899 <generic_fentry_filter_arg+0x3899> */
	return 14489ULL;
x86_l_3855:
	/* 0x3855: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_385a:
	/* 0x385a: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_3861:
	/* 0x3861: jmp    3899 <generic_fentry_filter_arg+0x3899> */
	return 14489ULL;
x86_l_3863:
	/* 0x3863: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3868:
	/* 0x3868: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_386f:
	/* 0x386f: jmp    3899 <generic_fentry_filter_arg+0x3899> */
	return 14489ULL;
x86_l_3871:
	/* 0x3871: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3876:
	/* 0x3876: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_387d:
	/* 0x387d: jmp    3899 <generic_fentry_filter_arg+0x3899> */
	return 14489ULL;
x86_l_387f:
	/* 0x387f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3884:
	/* 0x3884: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_388b:
	/* 0x388b: jmp    3899 <generic_fentry_filter_arg+0x3899> */
	return 14489ULL;
x86_l_388d:
	/* 0x388d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
	return 14482ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14482ULL: goto x86_l_3892;
	case 14489ULL: goto x86_l_3899;
	case 14494ULL: goto x86_l_389e;
	case 14496ULL: goto x86_l_38a0;
	case 14499ULL: goto x86_l_38a3;
	case 14501ULL: goto x86_l_38a5;
	case 14506ULL: goto x86_l_38aa;
	case 14509ULL: goto x86_l_38ad;
	case 14514ULL: goto x86_l_38b2;
	case 14516ULL: goto x86_l_38b4;
	case 14519ULL: goto x86_l_38b7;
	case 14522ULL: goto x86_l_38ba;
	case 14526ULL: goto x86_l_38be;
	case 14528ULL: goto x86_l_38c0;
	case 14531ULL: goto x86_l_38c3;
	case 14536ULL: goto x86_l_38c8;
	case 14541ULL: goto x86_l_38cd;
	case 14546ULL: goto x86_l_38d2;
	case 14550ULL: goto x86_l_38d6;
	case 14554ULL: goto x86_l_38da;
	case 14556ULL: goto x86_l_38dc;
	case 14566ULL: goto x86_l_38e6;
	case 14570ULL: goto x86_l_38ea;
	case 14575ULL: goto x86_l_38ef;
	case 14581ULL: goto x86_l_38f5;
	case 14583ULL: goto x86_l_38f7;
	case 14586ULL: goto x86_l_38fa;
	case 14589ULL: goto x86_l_38fd;
	case 14592ULL: goto x86_l_3900;
	case 14597ULL: goto x86_l_3905;
	case 14602ULL: goto x86_l_390a;
	case 14607ULL: goto x86_l_390f;
	case 14610ULL: goto x86_l_3912;
	case 14615ULL: goto x86_l_3917;
	case 14620ULL: goto x86_l_391c;
	case 14625ULL: goto x86_l_3921;
	case 14628ULL: goto x86_l_3924;
	case 14633ULL: goto x86_l_3929;
	case 14638ULL: goto x86_l_392e;
	case 14642ULL: goto x86_l_3932;
	case 14645ULL: goto x86_l_3935;
	case 14647ULL: goto x86_l_3937;
	case 14651ULL: goto x86_l_393b;
	case 14654ULL: goto x86_l_393e;
	case 14656ULL: goto x86_l_3940;
	case 14662ULL: goto x86_l_3946;
	case 14664ULL: goto x86_l_3948;
	case 14668ULL: goto x86_l_394c;
	case 14670ULL: goto x86_l_394e;
	case 14676ULL: goto x86_l_3954;
	case 14678ULL: goto x86_l_3956;
	case 14682ULL: goto x86_l_395a;
	case 14684ULL: goto x86_l_395c;
	case 14690ULL: goto x86_l_3962;
	case 14693ULL: goto x86_l_3965;
	case 14696ULL: goto x86_l_3968;
	case 14702ULL: goto x86_l_396e;
	case 14707ULL: goto x86_l_3973;
	case 14712ULL: goto x86_l_3978;
	case 14715ULL: goto x86_l_397b;
	case 14717ULL: goto x86_l_397d;
	case 14718ULL: goto x86_l_397e;
	case 14720ULL: goto x86_l_3980;
	case 14722ULL: goto x86_l_3982;
	case 14725ULL: goto x86_l_3985;
	case 14728ULL: goto x86_l_3988;
	case 14731ULL: goto x86_l_398b;
	case 14733ULL: goto x86_l_398d;
	case 14736ULL: goto x86_l_3990;
	case 14740ULL: goto x86_l_3994;
	case 14743ULL: goto x86_l_3997;
	case 14745ULL: goto x86_l_3999;
	case 14750ULL: goto x86_l_399e;
	case 14753ULL: goto x86_l_39a1;
	case 14755ULL: goto x86_l_39a3;
	case 14760ULL: goto x86_l_39a8;
	case 14764ULL: goto x86_l_39ac;
	case 14767ULL: goto x86_l_39af;
	case 14770ULL: goto x86_l_39b2;
	case 14774ULL: goto x86_l_39b6;
	case 14778ULL: goto x86_l_39ba;
	case 14782ULL: goto x86_l_39be;
	case 14785ULL: goto x86_l_39c1;
	case 14789ULL: goto x86_l_39c5;
	case 14793ULL: goto x86_l_39c9;
	case 14797ULL: goto x86_l_39cd;
	case 14800ULL: goto x86_l_39d0;
	case 14802ULL: goto x86_l_39d2;
	case 14806ULL: goto x86_l_39d6;
	case 14810ULL: goto x86_l_39da;
	case 14813ULL: goto x86_l_39dd;
	case 14815ULL: goto x86_l_39df;
	case 14817ULL: goto x86_l_39e1;
	case 14819ULL: goto x86_l_39e3;
	case 14820ULL: goto x86_l_39e4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3892:
	/* 0x3892: mov    rdi,QWORD PTR [rip+0x1c23e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_3899:
	/* 0x3899: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_389e:
	/* 0x389e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38a0:
	/* 0x38a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38a3:
	/* 0x38a3: je     38c0 <generic_fentry_filter_arg+0x38c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38c0;
	}
x86_l_38a5:
	/* 0x38a5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_38aa:
	/* 0x38aa: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_38ad:
	/* 0x38ad: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_38b2:
	/* 0x38b2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_38b4:
	/* 0x38b4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38b7:
	/* 0x38b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38ba:
	/* 0x38ba: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_38be:
	/* 0x38be: jmp    38c3 <generic_fentry_filter_arg+0x38c3> */
	goto x86_l_38c3;
x86_l_38c0:
	/* 0x38c0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38c3:
	/* 0x38c3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38c8:
	/* 0x38c8: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38cd:
	/* 0x38cd: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38d2:
	/* 0x38d2: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_38d6:
	/* 0x38d6: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_38da:
	/* 0x38da: ja     3905 <generic_fentry_filter_arg+0x3905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3905;
	}
x86_l_38dc:
	/* 0x38dc: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_38e6:
	/* 0x38e6: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_38ea:
	/* 0x38ea: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38ef:
	/* 0x38ef: jae    2a8 <generic_fentry_filter_arg+0x2a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 680ULL;
	}
x86_l_38f5:
	/* 0x38f5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38f7:
	/* 0x38f7: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_38fa:
	/* 0x38fa: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_38fd:
	/* 0x38fd: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3900:
	/* 0x3900: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_3905:
	/* 0x3905: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_390a:
	/* 0x390a: jmp    2a8 <generic_fentry_filter_arg+0x2a8> */
	return 680ULL;
x86_l_390f:
	/* 0x390f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3912:
	/* 0x3912: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3917:
	/* 0x3917: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_391c:
	/* 0x391c: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3921:
	/* 0x3921: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_3924:
	/* 0x3924: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3929:
	/* 0x3929: jmp    1d32 <generic_fentry_filter_arg+0x1d32> */
	return 7474ULL;
x86_l_392e:
	/* 0x392e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3932:
	/* 0x3932: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3935:
	/* 0x3935: jmp    393e <generic_fentry_filter_arg+0x393e> */
	goto x86_l_393e;
x86_l_3937:
	/* 0x3937: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_393b:
	/* 0x393b: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_393e:
	/* 0x393e: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_3940:
	/* 0x3940: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_3946:
	/* 0x3946: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	goto x86_l_3962;
x86_l_3948:
	/* 0x3948: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_394c:
	/* 0x394c: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_394e:
	/* 0x394e: jb     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 697ULL;
	}
x86_l_3954:
	/* 0x3954: jmp    3962 <generic_fentry_filter_arg+0x3962> */
	goto x86_l_3962;
x86_l_3956:
	/* 0x3956: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_395a:
	/* 0x395a: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_395c:
	/* 0x395c: ja     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 697ULL;
	}
x86_l_3962:
	/* 0x3962: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_3965:
	/* 0x3965: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3968:
	/* 0x3968: je     2b9 <generic_fentry_filter_arg+0x2b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 697ULL;
	}
x86_l_396e:
	/* 0x396e: jmp    108 <generic_fentry_filter_arg+0x108> */
	return 264ULL;
x86_l_3973:
	/* 0x3973: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_3978:
	/* 0x3978: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_397b:
	/* 0x397b: je     39e4 <native_bpf_strncasestr+0x71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39e4;
	}
x86_l_397d:
	/* 0x397d: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_397e:
	/* 0x397e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3980:
	/* 0x3980: jmp    398d <native_bpf_strncasestr+0x1a> */
	goto x86_l_398d;
x86_l_3982:
	/* 0x3982: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3985:
	/* 0x3985: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3988:
	/* 0x3988: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_398b:
	/* 0x398b: je     39e3 <native_bpf_strncasestr+0x70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39e3;
	}
x86_l_398d:
	/* 0x398d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3990:
	/* 0x3990: lea    r9,[rcx+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_3994:
	/* 0x3994: cmp    r9,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RDX, X86_WIDTH_64);
x86_l_3997:
	/* 0x3997: jae    3982 <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3982;
	}
x86_l_3999:
	/* 0x3999: movsx  r9d,BYTE PTR [rsi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_399e:
	/* 0x399e: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_39a1:
	/* 0x39a1: je     39e1 <native_bpf_strncasestr+0x6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39e1;
	}
x86_l_39a3:
	/* 0x39a3: movsx  r10d,BYTE PTR [rdi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_39a8:
	/* 0x39a8: lea    r11d,[r10-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_39ac:
	/* 0x39ac: mov    ebx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R10, X86_WIDTH_32);
x86_l_39af:
	/* 0x39af: or     ebx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_39b2:
	/* 0x39b2: cmp    r11d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 26ULL);
x86_l_39b6:
	/* 0x39b6: cmovae ebx,r10d */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R10, X86_WIDTH_32, X86_CC_AE);
x86_l_39ba:
	/* 0x39ba: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_39be:
	/* 0x39be: mov    r11d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_32);
x86_l_39c1:
	/* 0x39c1: or     r11d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_39c5:
	/* 0x39c5: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_39c9:
	/* 0x39c9: cmovae r11d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_39cd:
	/* 0x39cd: cmp    ebx,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R11, X86_WIDTH_32);
x86_l_39d0:
	/* 0x39d0: jne    3982 <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3982;
	}
x86_l_39d2:
	/* 0x39d2: lea    r9,[r8+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_39d6:
	/* 0x39d6: cmp    r8,0x63 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 99ULL);
x86_l_39da:
	/* 0x39da: mov    r8,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_64);
x86_l_39dd:
	/* 0x39dd: jb     3990 <native_bpf_strncasestr+0x1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3990;
	}
x86_l_39df:
	/* 0x39df: jmp    3982 <native_bpf_strncasestr+0xf> */
	goto x86_l_3982;
x86_l_39e1:
	/* 0x39e1: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_39e3:
	/* 0x39e3: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_39e4:
	/* 0x39e4: ret */
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 14204U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1710ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1715ULL && __x86_pc <= 3314ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3319ULL && __x86_pc <= 4865ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4869ULL && __x86_pc <= 6453ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6456ULL && __x86_pc <= 8076ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8079ULL && __x86_pc <= 9583ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9588ULL && __x86_pc <= 11221ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11224ULL && __x86_pc <= 12849ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 12851ULL && __x86_pc <= 14477ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 14482ULL && __x86_pc <= 14820ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v511_generic_fentry_filter_arg_x86_chunk_9(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

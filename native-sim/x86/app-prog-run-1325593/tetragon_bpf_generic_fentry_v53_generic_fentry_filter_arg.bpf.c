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

static __noinline __u64 tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_0(
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
	case 131ULL: goto x86_l_83;
	case 133ULL: goto x86_l_85;
	case 138ULL: goto x86_l_8a;
	case 142ULL: goto x86_l_8e;
	case 146ULL: goto x86_l_92;
	case 150ULL: goto x86_l_96;
	case 154ULL: goto x86_l_9a;
	case 159ULL: goto x86_l_9f;
	case 163ULL: goto x86_l_a3;
	case 166ULL: goto x86_l_a6;
	case 170ULL: goto x86_l_aa;
	case 172ULL: goto x86_l_ac;
	case 178ULL: goto x86_l_b2;
	case 182ULL: goto x86_l_b6;
	case 185ULL: goto x86_l_b9;
	case 187ULL: goto x86_l_bb;
	case 192ULL: goto x86_l_c0;
	case 196ULL: goto x86_l_c4;
	case 199ULL: goto x86_l_c7;
	case 201ULL: goto x86_l_c9;
	case 207ULL: goto x86_l_cf;
	case 211ULL: goto x86_l_d3;
	case 214ULL: goto x86_l_d6;
	case 216ULL: goto x86_l_d8;
	case 221ULL: goto x86_l_dd;
	case 225ULL: goto x86_l_e1;
	case 228ULL: goto x86_l_e4;
	case 231ULL: goto x86_l_e7;
	case 237ULL: goto x86_l_ed;
	case 242ULL: goto x86_l_f2;
	case 244ULL: goto x86_l_f4;
	case 248ULL: goto x86_l_f8;
	case 254ULL: goto x86_l_fe;
	case 256ULL: goto x86_l_100;
	case 262ULL: goto x86_l_106;
	case 265ULL: goto x86_l_109;
	case 267ULL: goto x86_l_10b;
	case 270ULL: goto x86_l_10e;
	case 276ULL: goto x86_l_114;
	case 278ULL: goto x86_l_116;
	case 284ULL: goto x86_l_11c;
	case 287ULL: goto x86_l_11f;
	case 293ULL: goto x86_l_125;
	case 295ULL: goto x86_l_127;
	case 298ULL: goto x86_l_12a;
	case 304ULL: goto x86_l_130;
	case 307ULL: goto x86_l_133;
	case 313ULL: goto x86_l_139;
	case 316ULL: goto x86_l_13c;
	case 322ULL: goto x86_l_142;
	case 325ULL: goto x86_l_145;
	case 331ULL: goto x86_l_14b;
	case 333ULL: goto x86_l_14d;
	case 338ULL: goto x86_l_152;
	case 342ULL: goto x86_l_156;
	case 350ULL: goto x86_l_15e;
	case 353ULL: goto x86_l_161;
	case 361ULL: goto x86_l_169;
	case 366ULL: goto x86_l_16e;
	case 374ULL: goto x86_l_176;
	case 379ULL: goto x86_l_17b;
	case 384ULL: goto x86_l_180;
	case 389ULL: goto x86_l_185;
	case 394ULL: goto x86_l_18a;
	case 399ULL: goto x86_l_18f;
	case 406ULL: goto x86_l_196;
	case 411ULL: goto x86_l_19b;
	case 418ULL: goto x86_l_1a2;
	case 421ULL: goto x86_l_1a5;
	case 426ULL: goto x86_l_1aa;
	case 428ULL: goto x86_l_1ac;
	case 433ULL: goto x86_l_1b1;
	case 440ULL: goto x86_l_1b8;
	case 443ULL: goto x86_l_1bb;
	case 448ULL: goto x86_l_1c0;
	case 450ULL: goto x86_l_1c2;
	case 452ULL: goto x86_l_1c4;
	case 459ULL: goto x86_l_1cb;
	case 461ULL: goto x86_l_1cd;
	case 462ULL: goto x86_l_1ce;
	case 467ULL: goto x86_l_1d3;
	case 469ULL: goto x86_l_1d5;
	case 477ULL: goto x86_l_1dd;
	case 479ULL: goto x86_l_1df;
	case 484ULL: goto x86_l_1e4;
	case 492ULL: goto x86_l_1ec;
	case 494ULL: goto x86_l_1ee;
	case 499ULL: goto x86_l_1f3;
	case 507ULL: goto x86_l_1fb;
	case 509ULL: goto x86_l_1fd;
	case 514ULL: goto x86_l_202;
	case 522ULL: goto x86_l_20a;
	case 524ULL: goto x86_l_20c;
	case 529ULL: goto x86_l_211;
	case 537ULL: goto x86_l_219;
	case 539ULL: goto x86_l_21b;
	case 544ULL: goto x86_l_220;
	case 552ULL: goto x86_l_228;
	case 554ULL: goto x86_l_22a;
	case 561ULL: goto x86_l_231;
	case 566ULL: goto x86_l_236;
	case 573ULL: goto x86_l_23d;
	case 576ULL: goto x86_l_240;
	case 581ULL: goto x86_l_245;
	case 583ULL: goto x86_l_247;
	case 587ULL: goto x86_l_24b;
	case 592ULL: goto x86_l_250;
	case 594ULL: goto x86_l_252;
	case 599ULL: goto x86_l_257;
	case 604ULL: goto x86_l_25c;
	case 609ULL: goto x86_l_261;
	case 616ULL: goto x86_l_268;
	case 621ULL: goto x86_l_26d;
	case 623ULL: goto x86_l_26f;
	case 626ULL: goto x86_l_272;
	case 632ULL: goto x86_l_278;
	case 637ULL: goto x86_l_27d;
	case 644ULL: goto x86_l_284;
	case 649ULL: goto x86_l_289;
	case 651ULL: goto x86_l_28b;
	case 656ULL: goto x86_l_290;
	case 659ULL: goto x86_l_293;
	case 662ULL: goto x86_l_296;
	case 665ULL: goto x86_l_299;
	case 670ULL: goto x86_l_29e;
	case 673ULL: goto x86_l_2a1;
	case 681ULL: goto x86_l_2a9;
	case 687ULL: goto x86_l_2af;
	case 690ULL: goto x86_l_2b2;
	case 694ULL: goto x86_l_2b6;
	case 700ULL: goto x86_l_2bc;
	case 708ULL: goto x86_l_2c4;
	case 713ULL: goto x86_l_2c9;
	case 720ULL: goto x86_l_2d0;
	case 726ULL: goto x86_l_2d6;
	case 729ULL: goto x86_l_2d9;
	case 736ULL: goto x86_l_2e0;
	case 741ULL: goto x86_l_2e5;
	case 744ULL: goto x86_l_2e8;
	case 750ULL: goto x86_l_2ee;
	case 753ULL: goto x86_l_2f1;
	case 757ULL: goto x86_l_2f5;
	case 761ULL: goto x86_l_2f9;
	case 767ULL: goto x86_l_2ff;
	case 776ULL: goto x86_l_308;
	case 782ULL: goto x86_l_30e;
	case 790ULL: goto x86_l_316;
	case 796ULL: goto x86_l_31c;
	case 800ULL: goto x86_l_320;
	case 807ULL: goto x86_l_327;
	case 812ULL: goto x86_l_32c;
	case 815ULL: goto x86_l_32f;
	case 817ULL: goto x86_l_331;
	case 820ULL: goto x86_l_334;
	case 823ULL: goto x86_l_337;
	case 829ULL: goto x86_l_33d;
	case 832ULL: goto x86_l_340;
	case 835ULL: goto x86_l_343;
	case 841ULL: goto x86_l_349;
	case 843ULL: goto x86_l_34b;
	case 853ULL: goto x86_l_355;
	case 857ULL: goto x86_l_359;
	case 859ULL: goto x86_l_35b;
	case 869ULL: goto x86_l_365;
	case 873ULL: goto x86_l_369;
	case 879ULL: goto x86_l_36f;
	case 889ULL: goto x86_l_379;
	case 893ULL: goto x86_l_37d;
	case 899ULL: goto x86_l_383;
	case 902ULL: goto x86_l_386;
	case 907ULL: goto x86_l_38b;
	case 910ULL: goto x86_l_38e;
	case 912ULL: goto x86_l_390;
	case 915ULL: goto x86_l_393;
	case 921ULL: goto x86_l_399;
	case 924ULL: goto x86_l_39c;
	case 930ULL: goto x86_l_3a2;
	case 933ULL: goto x86_l_3a5;
	case 936ULL: goto x86_l_3a8;
	case 938ULL: goto x86_l_3aa;
	case 941ULL: goto x86_l_3ad;
	case 947ULL: goto x86_l_3b3;
	case 950ULL: goto x86_l_3b6;
	case 953ULL: goto x86_l_3b9;
	case 957ULL: goto x86_l_3bd;
	case 960ULL: goto x86_l_3c0;
	case 966ULL: goto x86_l_3c6;
	case 969ULL: goto x86_l_3c9;
	case 972ULL: goto x86_l_3cc;
	case 978ULL: goto x86_l_3d2;
	case 981ULL: goto x86_l_3d5;
	case 987ULL: goto x86_l_3db;
	case 992ULL: goto x86_l_3e0;
	case 995ULL: goto x86_l_3e3;
	case 1001ULL: goto x86_l_3e9;
	case 1006ULL: goto x86_l_3ee;
	case 1009ULL: goto x86_l_3f1;
	case 1012ULL: goto x86_l_3f4;
	case 1018ULL: goto x86_l_3fa;
	case 1021ULL: goto x86_l_3fd;
	case 1024ULL: goto x86_l_400;
	case 1030ULL: goto x86_l_406;
	case 1033ULL: goto x86_l_409;
	case 1036ULL: goto x86_l_40c;
	case 1042ULL: goto x86_l_412;
	case 1051ULL: goto x86_l_41b;
	case 1060ULL: goto x86_l_424;
	case 1069ULL: goto x86_l_42d;
	case 1078ULL: goto x86_l_436;
	case 1087ULL: goto x86_l_43f;
	case 1090ULL: goto x86_l_442;
	case 1096ULL: goto x86_l_448;
	case 1099ULL: goto x86_l_44b;
	case 1102ULL: goto x86_l_44e;
	case 1108ULL: goto x86_l_454;
	case 1111ULL: goto x86_l_457;
	case 1116ULL: goto x86_l_45c;
	case 1119ULL: goto x86_l_45f;
	case 1125ULL: goto x86_l_465;
	case 1130ULL: goto x86_l_46a;
	case 1133ULL: goto x86_l_46d;
	case 1135ULL: goto x86_l_46f;
	case 1138ULL: goto x86_l_472;
	case 1144ULL: goto x86_l_478;
	case 1147ULL: goto x86_l_47b;
	case 1150ULL: goto x86_l_47e;
	case 1154ULL: goto x86_l_482;
	case 1157ULL: goto x86_l_485;
	case 1163ULL: goto x86_l_48b;
	case 1166ULL: goto x86_l_48e;
	case 1169ULL: goto x86_l_491;
	case 1175ULL: goto x86_l_497;
	case 1179ULL: goto x86_l_49b;
	case 1182ULL: goto x86_l_49e;
	case 1188ULL: goto x86_l_4a4;
	case 1193ULL: goto x86_l_4a9;
	case 1196ULL: goto x86_l_4ac;
	case 1202ULL: goto x86_l_4b2;
	case 1207ULL: goto x86_l_4b7;
	case 1211ULL: goto x86_l_4bb;
	case 1214ULL: goto x86_l_4be;
	case 1220ULL: goto x86_l_4c4;
	case 1223ULL: goto x86_l_4c7;
	case 1229ULL: goto x86_l_4cd;
	case 1231ULL: goto x86_l_4cf;
	case 1241ULL: goto x86_l_4d9;
	case 1245ULL: goto x86_l_4dd;
	case 1251ULL: goto x86_l_4e3;
	case 1256ULL: goto x86_l_4e8;
	case 1260ULL: goto x86_l_4ec;
	case 1266ULL: goto x86_l_4f2;
	case 1276ULL: goto x86_l_4fc;
	case 1280ULL: goto x86_l_500;
	case 1286ULL: goto x86_l_506;
	case 1289ULL: goto x86_l_509;
	case 1295ULL: goto x86_l_50f;
	case 1297ULL: goto x86_l_511;
	case 1302ULL: goto x86_l_516;
	case 1306ULL: goto x86_l_51a;
	case 1312ULL: goto x86_l_520;
	case 1317ULL: goto x86_l_525;
	case 1320ULL: goto x86_l_528;
	case 1326ULL: goto x86_l_52e;
	case 1329ULL: goto x86_l_531;
	case 1332ULL: goto x86_l_534;
	case 1336ULL: goto x86_l_538;
	case 1342ULL: goto x86_l_53e;
	case 1345ULL: goto x86_l_541;
	case 1347ULL: goto x86_l_543;
	case 1353ULL: goto x86_l_549;
	case 1358ULL: goto x86_l_54e;
	case 1361ULL: goto x86_l_551;
	case 1364ULL: goto x86_l_554;
	case 1370ULL: goto x86_l_55a;
	case 1373ULL: goto x86_l_55d;
	case 1375ULL: goto x86_l_55f;
	case 1378ULL: goto x86_l_562;
	case 1380ULL: goto x86_l_564;
	case 1385ULL: goto x86_l_569;
	case 1388ULL: goto x86_l_56c;
	case 1394ULL: goto x86_l_572;
	case 1397ULL: goto x86_l_575;
	case 1403ULL: goto x86_l_57b;
	case 1406ULL: goto x86_l_57e;
	case 1409ULL: goto x86_l_581;
	case 1415ULL: goto x86_l_587;
	case 1418ULL: goto x86_l_58a;
	case 1424ULL: goto x86_l_590;
	case 1429ULL: goto x86_l_595;
	case 1432ULL: goto x86_l_598;
	case 1435ULL: goto x86_l_59b;
	case 1441ULL: goto x86_l_5a1;
	case 1444ULL: goto x86_l_5a4;
	case 1450ULL: goto x86_l_5aa;
	case 1452ULL: goto x86_l_5ac;
	case 1457ULL: goto x86_l_5b1;
	case 1461ULL: goto x86_l_5b5;
	case 1463ULL: goto x86_l_5b7;
	case 1468ULL: goto x86_l_5bc;
	case 1471ULL: goto x86_l_5bf;
	case 1477ULL: goto x86_l_5c5;
	case 1480ULL: goto x86_l_5c8;
	case 1483ULL: goto x86_l_5cb;
	case 1489ULL: goto x86_l_5d1;
	case 1493ULL: goto x86_l_5d5;
	case 1495ULL: goto x86_l_5d7;
	case 1501ULL: goto x86_l_5dd;
	case 1506ULL: goto x86_l_5e2;
	case 1509ULL: goto x86_l_5e5;
	case 1512ULL: goto x86_l_5e8;
	case 1518ULL: goto x86_l_5ee;
	case 1521ULL: goto x86_l_5f1;
	case 1526ULL: goto x86_l_5f6;
	case 1529ULL: goto x86_l_5f9;
	case 1535ULL: goto x86_l_5ff;
	case 1540ULL: goto x86_l_604;
	case 1545ULL: goto x86_l_609;
	case 1549ULL: goto x86_l_60d;
	case 1555ULL: goto x86_l_613;
	case 1565ULL: goto x86_l_61d;
	case 1569ULL: goto x86_l_621;
	case 1575ULL: goto x86_l_627;
	case 1578ULL: goto x86_l_62a;
	case 1584ULL: goto x86_l_630;
	case 1589ULL: goto x86_l_635;
	case 1594ULL: goto x86_l_63a;
	case 1597ULL: goto x86_l_63d;
	case 1603ULL: goto x86_l_643;
	case 1608ULL: goto x86_l_648;
	case 1611ULL: goto x86_l_64b;
	case 1617ULL: goto x86_l_651;
	case 1621ULL: goto x86_l_655;
	case 1623ULL: goto x86_l_657;
	case 1625ULL: goto x86_l_659;
	case 1631ULL: goto x86_l_65f;
	case 1633ULL: goto x86_l_661;
	case 1639ULL: goto x86_l_667;
	case 1644ULL: goto x86_l_66c;
	case 1647ULL: goto x86_l_66f;
	case 1653ULL: goto x86_l_675;
	case 1656ULL: goto x86_l_678;
	case 1662ULL: goto x86_l_67e;
	case 1667ULL: goto x86_l_683;
	case 1670ULL: goto x86_l_686;
	case 1676ULL: goto x86_l_68c;
	case 1680ULL: goto x86_l_690;
	case 1685ULL: goto x86_l_695;
	case 1690ULL: goto x86_l_69a;
	case 1694ULL: goto x86_l_69e;
	case 1705ULL: goto x86_l_6a9;
	case 1710ULL: goto x86_l_6ae;
	case 1717ULL: goto x86_l_6b5;
	case 1722ULL: goto x86_l_6ba;
	case 1724ULL: goto x86_l_6bc;
	case 1727ULL: goto x86_l_6bf;
	case 1733ULL: goto x86_l_6c5;
	case 1738ULL: goto x86_l_6ca;
	case 1741ULL: goto x86_l_6cd;
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
	/* 0xa: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x1bba7] */
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
	/* 0x31: je     1c2 <generic_fentry_filter_arg+0x1c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c2;
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
	/* 0x4c: mov    rdi,QWORD PTR [rip+0x1bba7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_53:
	/* 0x53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55:
	/* 0x55: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_58:
	/* 0x58: je     1ac <generic_fentry_filter_arg+0x1ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ac;
	}
x86_l_5e:
	/* 0x5e: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_66:
	/* 0x66: je     1ac <generic_fentry_filter_arg+0x1ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ac;
	}
x86_l_6c:
	/* 0x6c: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
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
	/* 0x7d: je     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106;
	}
x86_l_83:
	/* 0x83: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_85:
	/* 0x85: mov    ecx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_8a:
	/* 0x8a: lea    rdx,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_8e:
	/* 0x8e: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_92:
	/* 0x92: lea    rax,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_96:
	/* 0x96: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_9a:
	/* 0x9a: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_9f:
	/* 0x9f: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_a3:
	/* 0xa3: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a6:
	/* 0xa6: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_aa:
	/* 0xaa: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ac:
	/* 0xac: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b2:
	/* 0xb2: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_b6:
	/* 0xb6: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b9:
	/* 0xb9: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_bb:
	/* 0xbb: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_c0:
	/* 0xc0: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_c4:
	/* 0xc4: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c7:
	/* 0xc7: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_c9:
	/* 0xc9: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_cf:
	/* 0xcf: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_d3:
	/* 0xd3: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d6:
	/* 0xd6: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_d8:
	/* 0xd8: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_dd:
	/* 0xdd: mov    r9d,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_e1:
	/* 0xe1: add    r9,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e4:
	/* 0xe4: mov    edi,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R9, X86_WIDTH_32);
x86_l_e7:
	/* 0xe7: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_ed:
	/* 0xed: cmp    DWORD PTR [r15+rdi*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 25ULL);
x86_l_f2:
	/* 0xf2: jae    152 <generic_fentry_filter_arg+0x152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_152;
	}
x86_l_f4:
	/* 0xf4: cmp    rdi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_64, 1ULL);
x86_l_f8:
	/* 0xf8: je     1ac <generic_fentry_filter_arg+0x1ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ac;
	}
x86_l_fe:
	/* 0xfe: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_100:
	/* 0x100: jne    18f <generic_fentry_filter_arg+0x18f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18f;
	}
x86_l_106:
	/* 0x106: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_109:
	/* 0x109: jg     127 <generic_fentry_filter_arg+0x127> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_127;
	}
x86_l_10b:
	/* 0x10b: cmp    ebx,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_10e:
	/* 0x10e: je     1d3 <generic_fentry_filter_arg+0x1d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d3;
	}
x86_l_114:
	/* 0x114: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_116:
	/* 0x116: je     1df <generic_fentry_filter_arg+0x1df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df;
	}
x86_l_11c:
	/* 0x11c: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_11f:
	/* 0x11f: je     1ee <generic_fentry_filter_arg+0x1ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ee;
	}
x86_l_125:
	/* 0x125: jmp    142 <generic_fentry_filter_arg+0x142> */
	goto x86_l_142;
x86_l_127:
	/* 0x127: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_12a:
	/* 0x12a: je     1fd <generic_fentry_filter_arg+0x1fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fd;
	}
x86_l_130:
	/* 0x130: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_133:
	/* 0x133: je     20c <generic_fentry_filter_arg+0x20c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c;
	}
x86_l_139:
	/* 0x139: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_13c:
	/* 0x13c: je     21b <generic_fentry_filter_arg+0x21b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21b;
	}
x86_l_142:
	/* 0x142: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_145:
	/* 0x145: jg     247 <generic_fentry_filter_arg+0x247> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_247;
	}
x86_l_14b:
	/* 0x14b: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_14d:
	/* 0x14d: jmp    22a <generic_fentry_filter_arg+0x22a> */
	goto x86_l_22a;
x86_l_152:
	/* 0x152: lea    rax,[r15+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_156:
	/* 0x156: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15e:
	/* 0x15e: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_161:
	/* 0x161: lea    rax,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_169:
	/* 0x169: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16e:
	/* 0x16e: mov    QWORD PTR [rsp+0xa8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_176:
	/* 0x176: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17b:
	/* 0x17b: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_180:
	/* 0x180: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_185:
	/* 0x185: mov    QWORD PTR [rsp+0x48],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18a:
	/* 0x18a: jmp    2bc <generic_fentry_filter_arg+0x2bc> */
	goto x86_l_2bc;
x86_l_18f:
	/* 0x18f: mov    DWORD PTR [r14+0x5f04],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_196:
	/* 0x196: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_19b:
	/* 0x19b: mov    rsi,QWORD PTR [rip+0x1bba7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_1a2:
	/* 0x1a2: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1a5:
	/* 0x1a5: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1aa:
	/* 0x1aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac:
	/* 0x1ac: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1b1:
	/* 0x1b1: mov    rsi,QWORD PTR [rip+0x1bba7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_1b8:
	/* 0x1b8: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1bb:
	/* 0x1bb: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1c0:
	/* 0x1c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2:
	/* 0x1c2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c4:
	/* 0x1c4: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_1cb:
	/* 0x1cb: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1cd:
	/* 0x1cd: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1ce:
	/* 0x1ce: jmp    32ae <native_bpf_strncasestr+0x72> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1d3:
	/* 0x1d3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d5:
	/* 0x1d5: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_1dd:
	/* 0x1dd: jne    22a <generic_fentry_filter_arg+0x22a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22a;
	}
x86_l_1df:
	/* 0x1df: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1e4:
	/* 0x1e4: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_1ec:
	/* 0x1ec: jne    22a <generic_fentry_filter_arg+0x22a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22a;
	}
x86_l_1ee:
	/* 0x1ee: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1f3:
	/* 0x1f3: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_1fb:
	/* 0x1fb: jne    22a <generic_fentry_filter_arg+0x22a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22a;
	}
x86_l_1fd:
	/* 0x1fd: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_202:
	/* 0x202: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_20a:
	/* 0x20a: jne    22a <generic_fentry_filter_arg+0x22a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22a;
	}
x86_l_20c:
	/* 0x20c: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_211:
	/* 0x211: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_219:
	/* 0x219: jne    22a <generic_fentry_filter_arg+0x22a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22a;
	}
x86_l_21b:
	/* 0x21b: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_220:
	/* 0x220: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_228:
	/* 0x228: je     247 <generic_fentry_filter_arg+0x247> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_247;
	}
x86_l_22a:
	/* 0x22a: mov    DWORD PTR [r14+0x5f00],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_231:
	/* 0x231: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_236:
	/* 0x236: mov    rsi,QWORD PTR [rip+0x1bbaa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_23d:
	/* 0x23d: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_240:
	/* 0x240: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_245:
	/* 0x245: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_247:
	/* 0x247: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24b:
	/* 0x24b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_250:
	/* 0x250: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_252:
	/* 0x252: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_257:
	/* 0x257: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_25c:
	/* 0x25c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_261:
	/* 0x261: mov    rdi,QWORD PTR [rip+0x1bbaa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_268:
	/* 0x268: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_26d:
	/* 0x26d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f:
	/* 0x26f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_272:
	/* 0x272: je     1c2 <generic_fentry_filter_arg+0x1c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c2;
	}
x86_l_278:
	/* 0x278: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_27d:
	/* 0x27d: mov    rdi,QWORD PTR [rip+0x1bbaa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_284:
	/* 0x284: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_289:
	/* 0x289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b:
	/* 0x28b: jmp    1c2 <generic_fentry_filter_arg+0x1c2> */
	goto x86_l_1c2;
x86_l_290:
	/* 0x290: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_293:
	/* 0x293: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_296:
	/* 0x296: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_299:
	/* 0x299: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29e:
	/* 0x29e: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2a1:
	/* 0x2a1: mov    rbx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2a9:
	/* 0x2a9: je     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106;
	}
x86_l_2af:
	/* 0x2af: inc    r11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2b2:
	/* 0x2b2: cmp    r11,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 5ULL);
x86_l_2b6:
	/* 0x2b6: je     f4 <generic_fentry_filter_arg+0xf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f4;
	}
x86_l_2bc:
	/* 0x2bc: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2c4:
	/* 0x2c4: mov    r12d,DWORD PTR [rax+r11*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 2), 4ULL);
x86_l_2c9:
	/* 0x2c9: test   r12d,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1023ULL);
x86_l_2d0:
	/* 0x2d0: je     f4 <generic_fentry_filter_arg+0xf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f4;
	}
x86_l_2d6:
	/* 0x2d6: add    r12d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d9:
	/* 0x2d9: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_2e0:
	/* 0x2e0: mov    eax,DWORD PTR [r15+r12*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_2e5:
	/* 0x2e5: cmp    eax,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2e8:
	/* 0x2e8: je     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106;
	}
x86_l_2ee:
	/* 0x2ee: add    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f1:
	/* 0x2f1: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f5:
	/* 0x2f5: cmp    rcx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4ULL);
x86_l_2f9:
	/* 0x2f9: ja     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_106;
	}
x86_l_2ff:
	/* 0x2ff: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_308:
	/* 0x308: jne    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_106;
	}
x86_l_30e:
	/* 0x30e: mov    rcx,QWORD PTR [r14+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_316:
	/* 0x316: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_31c:
	/* 0x31c: lea    rsi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_320:
	/* 0x320: add    rsi,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_327:
	/* 0x327: mov    ecx,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_32c:
	/* 0x32c: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_32f:
	/* 0x32f: jle    38b <generic_fentry_filter_arg+0x38b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_38b;
	}
x86_l_331:
	/* 0x331: lea    edx,[rcx-0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551588ULL);
x86_l_334:
	/* 0x334: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_337:
	/* 0x337: jb     4b7 <generic_fentry_filter_arg+0x4b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4b7;
	}
x86_l_33d:
	/* 0x33d: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_340:
	/* 0x340: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_343:
	/* 0x343: ja     7d1 <generic_fentry_filter_arg+0x7d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2001ULL;
	}
x86_l_349:
	/* 0x349: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_34b:
	/* 0x34b: movabs rsi,0xc000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 824633720832ULL);
x86_l_355:
	/* 0x355: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_359:
	/* 0x359: jb     3b3 <generic_fentry_filter_arg+0x3b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3b3;
	}
x86_l_35b:
	/* 0x35b: movabs rsi,0x30000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 3298534883328ULL);
x86_l_365:
	/* 0x365: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_369:
	/* 0x369: jb     412 <generic_fentry_filter_arg+0x412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_412;
	}
x86_l_36f:
	/* 0x36f: movabs rsi,0x42000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 4535485464576ULL);
x86_l_379:
	/* 0x379: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_37d:
	/* 0x37d: jae    7d1 <generic_fentry_filter_arg+0x7d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2001ULL;
	}
x86_l_383:
	/* 0x383: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_386:
	/* 0x386: jmp    7e1 <generic_fentry_filter_arg+0x7e1> */
	return 2017ULL;
x86_l_38b:
	/* 0x38b: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_38e:
	/* 0x38e: jg     3ee <generic_fentry_filter_arg+0x3ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3ee;
	}
x86_l_390:
	/* 0x390: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_393:
	/* 0x393: jle    46a <generic_fentry_filter_arg+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_46a;
	}
x86_l_399:
	/* 0x399: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_39c:
	/* 0x39c: je     4b7 <generic_fentry_filter_arg+0x4b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b7;
	}
x86_l_3a2:
	/* 0x3a2: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_3a5:
	/* 0x3a5: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_3a8:
	/* 0x3a8: je     412 <generic_fentry_filter_arg+0x412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_412;
	}
x86_l_3aa:
	/* 0x3aa: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3ad:
	/* 0x3ad: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2af;
	}
x86_l_3b3:
	/* 0x3b3: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_3b6:
	/* 0x3b6: mov    ebp,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b9:
	/* 0x3b9: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3bd:
	/* 0x3bd: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3c0:
	/* 0x3c0: jg     66c <generic_fentry_filter_arg+0x66c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_66c;
	}
x86_l_3c6:
	/* 0x3c6: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3c9:
	/* 0x3c9: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3cc:
	/* 0x3cc: jb     fe0 <generic_fentry_filter_arg+0xfe0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4064ULL;
	}
x86_l_3d2:
	/* 0x3d2: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3d5:
	/* 0x3d5: je     f3a <generic_fentry_filter_arg+0xf3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3898ULL;
	}
x86_l_3db:
	/* 0x3db: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_3e0:
	/* 0x3e0: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_3e3:
	/* 0x3e3: je     68c <generic_fentry_filter_arg+0x68c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_68c;
	}
x86_l_3e9:
	/* 0x3e9: jmp    2ec9 <generic_fentry_filter_arg+0x2ec9> */
	return 11977ULL;
x86_l_3ee:
	/* 0x3ee: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_3f1:
	/* 0x3f1: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3f4:
	/* 0x3f4: jb     4b7 <generic_fentry_filter_arg+0x4b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4b7;
	}
x86_l_3fa:
	/* 0x3fa: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_3fd:
	/* 0x3fd: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_400:
	/* 0x400: jb     7e1 <generic_fentry_filter_arg+0x7e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2017ULL;
	}
x86_l_406:
	/* 0x406: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_409:
	/* 0x409: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_40c:
	/* 0x40c: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2af;
	}
x86_l_412:
	/* 0x412: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_41b:
	/* 0x41b: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_424:
	/* 0x424: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_42d:
	/* 0x42d: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_436:
	/* 0x436: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_43f:
	/* 0x43f: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_442:
	/* 0x442: jg     5e2 <generic_fentry_filter_arg+0x5e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5e2;
	}
x86_l_448:
	/* 0x448: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_44b:
	/* 0x44b: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_44e:
	/* 0x44e: je     d89 <generic_fentry_filter_arg+0xd89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3465ULL;
	}
x86_l_454:
	/* 0x454: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_457:
	/* 0x457: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_45c:
	/* 0x45c: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_45f:
	/* 0x45f: je     d8b <generic_fentry_filter_arg+0xd8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3467ULL;
	}
x86_l_465:
	/* 0x465: jmp    299 <generic_fentry_filter_arg+0x299> */
	goto x86_l_299;
x86_l_46a:
	/* 0x46a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_46d:
	/* 0x46d: je     4b7 <generic_fentry_filter_arg+0x4b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b7;
	}
x86_l_46f:
	/* 0x46f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_472:
	/* 0x472: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2af;
	}
x86_l_478:
	/* 0x478: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_47b:
	/* 0x47b: mov    ebp,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_47e:
	/* 0x47e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_482:
	/* 0x482: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_485:
	/* 0x485: jg     1063 <generic_fentry_filter_arg+0x1063> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4195ULL;
	}
x86_l_48b:
	/* 0x48b: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_48e:
	/* 0x48e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_491:
	/* 0x491: jb     18cf <generic_fentry_filter_arg+0x18cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6351ULL;
	}
x86_l_497:
	/* 0x497: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49b:
	/* 0x49b: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_49e:
	/* 0x49e: je     182f <generic_fentry_filter_arg+0x182f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6191ULL;
	}
x86_l_4a4:
	/* 0x4a4: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_4a9:
	/* 0x4a9: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_4ac:
	/* 0x4ac: je     1087 <generic_fentry_filter_arg+0x1087> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4231ULL;
	}
x86_l_4b2:
	/* 0x4b2: jmp    318c <generic_fentry_filter_arg+0x318c> */
	return 12684ULL;
x86_l_4b7:
	/* 0x4b7: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bb:
	/* 0x4bb: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_4be:
	/* 0x4be: jle    54e <generic_fentry_filter_arg+0x54e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_54e;
	}
x86_l_4c4:
	/* 0x4c4: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_4c7:
	/* 0x4c7: ja     595 <generic_fentry_filter_arg+0x595> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_595;
	}
x86_l_4cd:
	/* 0x4cd: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_4cf:
	/* 0x4cf: movabs rsi,0x1e00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 128849018880ULL);
x86_l_4d9:
	/* 0x4d9: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_4dd:
	/* 0x4dd: jb     569 <generic_fentry_filter_arg+0x569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_569;
	}
x86_l_4e3:
	/* 0x4e3: mov    esi,0x60000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1610612736ULL);
x86_l_4e8:
	/* 0x4e8: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_4ec:
	/* 0x4ec: jb     92a <generic_fentry_filter_arg+0x92a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2346ULL;
	}
x86_l_4f2:
	/* 0x4f2: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_4fc:
	/* 0x4fc: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_500:
	/* 0x500: jae    595 <generic_fentry_filter_arg+0x595> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_595;
	}
x86_l_506:
	/* 0x506: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_509:
	/* 0x509: ja     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_106;
	}
x86_l_50f:
	/* 0x50f: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_511:
	/* 0x511: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_516:
	/* 0x516: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_51a:
	/* 0x51a: jae    11d6 <generic_fentry_filter_arg+0x11d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4566ULL;
	}
x86_l_520:
	/* 0x520: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_525:
	/* 0x525: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_528:
	/* 0x528: jle    16db <generic_fentry_filter_arg+0x16db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5851ULL;
	}
x86_l_52e:
	/* 0x52e: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_531:
	/* 0x531: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_534:
	/* 0x534: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_538:
	/* 0x538: jae    1cf6 <generic_fentry_filter_arg+0x1cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7414ULL;
	}
x86_l_53e:
	/* 0x53e: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_541:
	/* 0x541: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_543:
	/* 0x543: jne    1ffd <generic_fentry_filter_arg+0x1ffd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8189ULL;
	}
x86_l_549:
	/* 0x549: jmp    3115 <generic_fentry_filter_arg+0x3115> */
	return 12565ULL;
x86_l_54e:
	/* 0x54e: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_551:
	/* 0x551: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_554:
	/* 0x554: jb     9c9 <generic_fentry_filter_arg+0x9c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2505ULL;
	}
x86_l_55a:
	/* 0x55a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_55d:
	/* 0x55d: je     5a1 <generic_fentry_filter_arg+0x5a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a1;
	}
x86_l_55f:
	/* 0x55f: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_562:
	/* 0x562: je     5a1 <generic_fentry_filter_arg+0x5a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a1;
	}
x86_l_564:
	/* 0x564: jmp    2af <generic_fentry_filter_arg+0x2af> */
	goto x86_l_2af;
x86_l_569:
	/* 0x569: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_56c:
	/* 0x56c: jle    979 <generic_fentry_filter_arg+0x979> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2425ULL;
	}
x86_l_572:
	/* 0x572: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_575:
	/* 0x575: jg     e0e <generic_fentry_filter_arg+0xe0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3598ULL;
	}
x86_l_57b:
	/* 0x57b: lea    edx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_57e:
	/* 0x57e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_581:
	/* 0x581: jb     a5d <generic_fentry_filter_arg+0xa5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2653ULL;
	}
x86_l_587:
	/* 0x587: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_58a:
	/* 0x58a: je     9df <generic_fentry_filter_arg+0x9df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2527ULL;
	}
x86_l_590:
	/* 0x590: jmp    106 <generic_fentry_filter_arg+0x106> */
	goto x86_l_106;
x86_l_595:
	/* 0x595: lea    edx,[rcx-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_598:
	/* 0x598: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_59b:
	/* 0x59b: jae    9c0 <generic_fentry_filter_arg+0x9c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2496ULL;
	}
x86_l_5a1:
	/* 0x5a1: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_5a4:
	/* 0x5a4: ja     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_106;
	}
x86_l_5aa:
	/* 0x5aa: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_5ac:
	/* 0x5ac: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_5b1:
	/* 0x5b1: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_5b5:
	/* 0x5b5: jae    604 <generic_fentry_filter_arg+0x604> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_604;
	}
x86_l_5b7:
	/* 0x5b7: mov    edx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bc:
	/* 0x5bc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5bf:
	/* 0x5bf: jle    986 <generic_fentry_filter_arg+0x986> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2438ULL;
	}
x86_l_5c5:
	/* 0x5c5: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_5c8:
	/* 0x5c8: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_5cb:
	/* 0x5cb: jae    11bc <generic_fentry_filter_arg+0x11bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4540ULL;
	}
x86_l_5d1:
	/* 0x5d1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d5:
	/* 0x5d5: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d7:
	/* 0x5d7: jne    2272 <generic_fentry_filter_arg+0x2272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8818ULL;
	}
x86_l_5dd:
	/* 0x5dd: jmp    3115 <generic_fentry_filter_arg+0x3115> */
	return 12565ULL;
x86_l_5e2:
	/* 0x5e2: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_5e5:
	/* 0x5e5: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_5e8:
	/* 0x5e8: je     d61 <generic_fentry_filter_arg+0xd61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3425ULL;
	}
x86_l_5ee:
	/* 0x5ee: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_5f1:
	/* 0x5f1: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_5f6:
	/* 0x5f6: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_5f9:
	/* 0x5f9: je     d8b <generic_fentry_filter_arg+0xd8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3467ULL;
	}
x86_l_5ff:
	/* 0x5ff: jmp    299 <generic_fentry_filter_arg+0x299> */
	goto x86_l_299;
x86_l_604:
	/* 0x604: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_609:
	/* 0x609: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_60d:
	/* 0x60d: jb     cc8 <generic_fentry_filter_arg+0xcc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3272ULL;
	}
x86_l_613:
	/* 0x613: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_61d:
	/* 0x61d: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_621:
	/* 0x621: jae    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_106;
	}
x86_l_627:
	/* 0x627: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_62a:
	/* 0x62a: jne    132d <generic_fentry_filter_arg+0x132d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4909ULL;
	}
x86_l_630:
	/* 0x630: mov    esi,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_635:
	/* 0x635: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_63a:
	/* 0x63a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_63d:
	/* 0x63d: ja     20a1 <generic_fentry_filter_arg+0x20a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8353ULL;
	}
x86_l_643:
	/* 0x643: mov    eax,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5122ULL);
x86_l_648:
	/* 0x648: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_64b:
	/* 0x64b: jae    20a1 <generic_fentry_filter_arg+0x20a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8353ULL;
	}
x86_l_651:
	/* 0x651: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_655:
	/* 0x655: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_657:
	/* 0x657: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_659:
	/* 0x659: jg     20b3 <generic_fentry_filter_arg+0x20b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8371ULL;
	}
x86_l_65f:
	/* 0x65f: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_661:
	/* 0x661: jle    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2af;
	}
x86_l_667:
	/* 0x667: jmp    20b3 <generic_fentry_filter_arg+0x20b3> */
	return 8371ULL;
x86_l_66c:
	/* 0x66c: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_66f:
	/* 0x66f: jg     e59 <generic_fentry_filter_arg+0xe59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3673ULL;
	}
x86_l_675:
	/* 0x675: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_678:
	/* 0x678: je     f3a <generic_fentry_filter_arg+0xf3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3898ULL;
	}
x86_l_67e:
	/* 0x67e: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_683:
	/* 0x683: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_686:
	/* 0x686: jne    2ec9 <generic_fentry_filter_arg+0x2ec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11977ULL;
	}
x86_l_68c:
	/* 0x68c: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_690:
	/* 0x690: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_695:
	/* 0x695: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_69a:
	/* 0x69a: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_69e:
	/* 0x69e: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_6a9:
	/* 0x6a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6ae:
	/* 0x6ae: mov    rdi,QWORD PTR [rip+0x1bbaa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_6b5:
	/* 0x6b5: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6ba:
	/* 0x6ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6bc:
	/* 0x6bc: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_6bf:
	/* 0x6bf: je     2eb8 <generic_fentry_filter_arg+0x2eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11960ULL;
	}
x86_l_6c5:
	/* 0x6c5: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_6ca:
	/* 0x6ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6cd:
	/* 0x6cd: je     2eba <generic_fentry_filter_arg+0x2eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11962ULL;
	}
	return 1747ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1747ULL: goto x86_l_6d3;
	case 1752ULL: goto x86_l_6d8;
	case 1757ULL: goto x86_l_6dd;
	case 1764ULL: goto x86_l_6e4;
	case 1769ULL: goto x86_l_6e9;
	case 1771ULL: goto x86_l_6eb;
	case 1774ULL: goto x86_l_6ee;
	case 1780ULL: goto x86_l_6f4;
	case 1783ULL: goto x86_l_6f7;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1794ULL: goto x86_l_702;
	case 1797ULL: goto x86_l_705;
	case 1799ULL: goto x86_l_707;
	case 1802ULL: goto x86_l_70a;
	case 1805ULL: goto x86_l_70d;
	case 1810ULL: goto x86_l_712;
	case 1813ULL: goto x86_l_715;
	case 1816ULL: goto x86_l_718;
	case 1821ULL: goto x86_l_71d;
	case 1825ULL: goto x86_l_721;
	case 1831ULL: goto x86_l_727;
	case 1834ULL: goto x86_l_72a;
	case 1838ULL: goto x86_l_72e;
	case 1844ULL: goto x86_l_734;
	case 1847ULL: goto x86_l_737;
	case 1851ULL: goto x86_l_73b;
	case 1854ULL: goto x86_l_73e;
	case 1857ULL: goto x86_l_741;
	case 1861ULL: goto x86_l_745;
	case 1865ULL: goto x86_l_749;
	case 1871ULL: goto x86_l_74f;
	case 1875ULL: goto x86_l_753;
	case 1879ULL: goto x86_l_757;
	case 1882ULL: goto x86_l_75a;
	case 1884ULL: goto x86_l_75c;
	case 1888ULL: goto x86_l_760;
	case 1894ULL: goto x86_l_766;
	case 1898ULL: goto x86_l_76a;
	case 1902ULL: goto x86_l_76e;
	case 1905ULL: goto x86_l_771;
	case 1907ULL: goto x86_l_773;
	case 1911ULL: goto x86_l_777;
	case 1917ULL: goto x86_l_77d;
	case 1921ULL: goto x86_l_781;
	case 1925ULL: goto x86_l_785;
	case 1928ULL: goto x86_l_788;
	case 1930ULL: goto x86_l_78a;
	case 1934ULL: goto x86_l_78e;
	case 1936ULL: goto x86_l_790;
	case 1940ULL: goto x86_l_794;
	case 1946ULL: goto x86_l_79a;
	case 1950ULL: goto x86_l_79e;
	case 1953ULL: goto x86_l_7a1;
	case 1957ULL: goto x86_l_7a5;
	case 1961ULL: goto x86_l_7a9;
	case 1964ULL: goto x86_l_7ac;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1981ULL: goto x86_l_7bd;
	case 1983ULL: goto x86_l_7bf;
	case 1985ULL: goto x86_l_7c1;
	case 1988ULL: goto x86_l_7c4;
	case 1991ULL: goto x86_l_7c7;
	case 1996ULL: goto x86_l_7cc;
	case 2001ULL: goto x86_l_7d1;
	case 2004ULL: goto x86_l_7d4;
	case 2010ULL: goto x86_l_7da;
	case 2013ULL: goto x86_l_7dd;
	case 2017ULL: goto x86_l_7e1;
	case 2021ULL: goto x86_l_7e5;
	case 2023ULL: goto x86_l_7e7;
	case 2025ULL: goto x86_l_7e9;
	case 2028ULL: goto x86_l_7ec;
	case 2031ULL: goto x86_l_7ef;
	case 2033ULL: goto x86_l_7f1;
	case 2035ULL: goto x86_l_7f3;
	case 2041ULL: goto x86_l_7f9;
	case 2044ULL: goto x86_l_7fc;
	case 2048ULL: goto x86_l_800;
	case 2054ULL: goto x86_l_806;
	case 2056ULL: goto x86_l_808;
	case 2061ULL: goto x86_l_80d;
	case 2065ULL: goto x86_l_811;
	case 2071ULL: goto x86_l_817;
	case 2076ULL: goto x86_l_81c;
	case 2080ULL: goto x86_l_820;
	case 2086ULL: goto x86_l_826;
	case 2096ULL: goto x86_l_830;
	case 2100ULL: goto x86_l_834;
	case 2106ULL: goto x86_l_83a;
	case 2113ULL: goto x86_l_841;
	case 2119ULL: goto x86_l_847;
	case 2125ULL: goto x86_l_84d;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2135ULL: goto x86_l_857;
	case 2139ULL: goto x86_l_85b;
	case 2143ULL: goto x86_l_85f;
	case 2148ULL: goto x86_l_864;
	case 2153ULL: goto x86_l_869;
	case 2155ULL: goto x86_l_86b;
	case 2160ULL: goto x86_l_870;
	case 2162ULL: goto x86_l_872;
	case 2168ULL: goto x86_l_878;
	case 2173ULL: goto x86_l_87d;
	case 2178ULL: goto x86_l_882;
	case 2183ULL: goto x86_l_887;
	case 2185ULL: goto x86_l_889;
	case 2191ULL: goto x86_l_88f;
	case 2196ULL: goto x86_l_894;
	case 2199ULL: goto x86_l_897;
	case 2204ULL: goto x86_l_89c;
	case 2209ULL: goto x86_l_8a1;
	case 2212ULL: goto x86_l_8a4;
	case 2218ULL: goto x86_l_8aa;
	case 2223ULL: goto x86_l_8af;
	case 2225ULL: goto x86_l_8b1;
	case 2231ULL: goto x86_l_8b7;
	case 2233ULL: goto x86_l_8b9;
	case 2239ULL: goto x86_l_8bf;
	case 2242ULL: goto x86_l_8c2;
	case 2248ULL: goto x86_l_8c8;
	case 2253ULL: goto x86_l_8cd;
	case 2255ULL: goto x86_l_8cf;
	case 2261ULL: goto x86_l_8d5;
	case 2263ULL: goto x86_l_8d7;
	case 2269ULL: goto x86_l_8dd;
	case 2272ULL: goto x86_l_8e0;
	case 2278ULL: goto x86_l_8e6;
	case 2283ULL: goto x86_l_8eb;
	case 2285ULL: goto x86_l_8ed;
	case 2291ULL: goto x86_l_8f3;
	case 2293ULL: goto x86_l_8f5;
	case 2295ULL: goto x86_l_8f7;
	case 2298ULL: goto x86_l_8fa;
	case 2303ULL: goto x86_l_8ff;
	case 2306ULL: goto x86_l_902;
	case 2309ULL: goto x86_l_905;
	case 2311ULL: goto x86_l_907;
	case 2322ULL: goto x86_l_912;
	case 2328ULL: goto x86_l_918;
	case 2334ULL: goto x86_l_91e;
	case 2336ULL: goto x86_l_920;
	case 2341ULL: goto x86_l_925;
	case 2346ULL: goto x86_l_92a;
	case 2349ULL: goto x86_l_92d;
	case 2355ULL: goto x86_l_933;
	case 2357ULL: goto x86_l_935;
	case 2362ULL: goto x86_l_93a;
	case 2366ULL: goto x86_l_93e;
	case 2372ULL: goto x86_l_944;
	case 2377ULL: goto x86_l_949;
	case 2380ULL: goto x86_l_94c;
	case 2386ULL: goto x86_l_952;
	case 2389ULL: goto x86_l_955;
	case 2392ULL: goto x86_l_958;
	case 2396ULL: goto x86_l_95c;
	case 2402ULL: goto x86_l_962;
	case 2405ULL: goto x86_l_965;
	case 2407ULL: goto x86_l_967;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2420ULL: goto x86_l_974;
	case 2425ULL: goto x86_l_979;
	case 2428ULL: goto x86_l_97c;
	case 2431ULL: goto x86_l_97f;
	case 2433ULL: goto x86_l_981;
	case 2438ULL: goto x86_l_986;
	case 2441ULL: goto x86_l_989;
	case 2447ULL: goto x86_l_98f;
	case 2450ULL: goto x86_l_992;
	case 2456ULL: goto x86_l_998;
	case 2459ULL: goto x86_l_99b;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2473ULL: goto x86_l_9a9;
	case 2479ULL: goto x86_l_9af;
	case 2483ULL: goto x86_l_9b3;
	case 2485ULL: goto x86_l_9b5;
	case 2491ULL: goto x86_l_9bb;
	case 2496ULL: goto x86_l_9c0;
	case 2499ULL: goto x86_l_9c3;
	case 2505ULL: goto x86_l_9c9;
	case 2508ULL: goto x86_l_9cc;
	case 2514ULL: goto x86_l_9d2;
	case 2516ULL: goto x86_l_9d4;
	case 2521ULL: goto x86_l_9d9;
	case 2525ULL: goto x86_l_9dd;
	case 2527ULL: goto x86_l_9df;
	case 2532ULL: goto x86_l_9e4;
	case 2535ULL: goto x86_l_9e7;
	case 2537ULL: goto x86_l_9e9;
	case 2540ULL: goto x86_l_9ec;
	case 2543ULL: goto x86_l_9ef;
	case 2549ULL: goto x86_l_9f5;
	case 2553ULL: goto x86_l_9f9;
	case 2556ULL: goto x86_l_9fc;
	case 2562ULL: goto x86_l_a02;
	case 2567ULL: goto x86_l_a07;
	case 2572ULL: goto x86_l_a0c;
	case 2576ULL: goto x86_l_a10;
	case 2578ULL: goto x86_l_a12;
	case 2588ULL: goto x86_l_a1c;
	case 2592ULL: goto x86_l_a20;
	case 2598ULL: goto x86_l_a26;
	case 2603ULL: goto x86_l_a2b;
	case 2606ULL: goto x86_l_a2e;
	case 2612ULL: goto x86_l_a34;
	case 2615ULL: goto x86_l_a37;
	case 2621ULL: goto x86_l_a3d;
	case 2624ULL: goto x86_l_a40;
	case 2626ULL: goto x86_l_a42;
	case 2629ULL: goto x86_l_a45;
	case 2635ULL: goto x86_l_a4b;
	case 2639ULL: goto x86_l_a4f;
	case 2642ULL: goto x86_l_a52;
	case 2648ULL: goto x86_l_a58;
	case 2653ULL: goto x86_l_a5d;
	case 2656ULL: goto x86_l_a60;
	case 2662ULL: goto x86_l_a66;
	case 2669ULL: goto x86_l_a6d;
	case 2674ULL: goto x86_l_a72;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2688ULL: goto x86_l_a80;
	case 2691ULL: goto x86_l_a83;
	case 2697ULL: goto x86_l_a89;
	case 2701ULL: goto x86_l_a8d;
	case 2704ULL: goto x86_l_a90;
	case 2709ULL: goto x86_l_a95;
	case 2714ULL: goto x86_l_a9a;
	case 2717ULL: goto x86_l_a9d;
	case 2722ULL: goto x86_l_aa2;
	case 2724ULL: goto x86_l_aa4;
	case 2729ULL: goto x86_l_aa9;
	case 2732ULL: goto x86_l_aac;
	case 2738ULL: goto x86_l_ab2;
	case 2741ULL: goto x86_l_ab5;
	case 2746ULL: goto x86_l_aba;
	case 2751ULL: goto x86_l_abf;
	case 2754ULL: goto x86_l_ac2;
	case 2760ULL: goto x86_l_ac8;
	case 2763ULL: goto x86_l_acb;
	case 2766ULL: goto x86_l_ace;
	case 2769ULL: goto x86_l_ad1;
	case 2774ULL: goto x86_l_ad6;
	case 2779ULL: goto x86_l_adb;
	case 2784ULL: goto x86_l_ae0;
	case 2788ULL: goto x86_l_ae4;
	case 2799ULL: goto x86_l_aef;
	case 2804ULL: goto x86_l_af4;
	case 2811ULL: goto x86_l_afb;
	case 2816ULL: goto x86_l_b00;
	case 2818ULL: goto x86_l_b02;
	case 2821ULL: goto x86_l_b05;
	case 2827ULL: goto x86_l_b0b;
	case 2832ULL: goto x86_l_b10;
	case 2835ULL: goto x86_l_b13;
	case 2841ULL: goto x86_l_b19;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2858ULL: goto x86_l_b2a;
	case 2863ULL: goto x86_l_b2f;
	case 2865ULL: goto x86_l_b31;
	case 2868ULL: goto x86_l_b34;
	case 2874ULL: goto x86_l_b3a;
	case 2877ULL: goto x86_l_b3d;
	case 2880ULL: goto x86_l_b40;
	case 2885ULL: goto x86_l_b45;
	case 2888ULL: goto x86_l_b48;
	case 2891ULL: goto x86_l_b4b;
	case 2893ULL: goto x86_l_b4d;
	case 2896ULL: goto x86_l_b50;
	case 2899ULL: goto x86_l_b53;
	case 2904ULL: goto x86_l_b58;
	case 2907ULL: goto x86_l_b5b;
	case 2910ULL: goto x86_l_b5e;
	case 2915ULL: goto x86_l_b63;
	case 2919ULL: goto x86_l_b67;
	case 2925ULL: goto x86_l_b6d;
	case 2928ULL: goto x86_l_b70;
	case 2932ULL: goto x86_l_b74;
	case 2938ULL: goto x86_l_b7a;
	case 2941ULL: goto x86_l_b7d;
	case 2945ULL: goto x86_l_b81;
	case 2948ULL: goto x86_l_b84;
	case 2951ULL: goto x86_l_b87;
	case 2955ULL: goto x86_l_b8b;
	case 2959ULL: goto x86_l_b8f;
	case 2965ULL: goto x86_l_b95;
	case 2970ULL: goto x86_l_b9a;
	case 2974ULL: goto x86_l_b9e;
	case 2977ULL: goto x86_l_ba1;
	case 2979ULL: goto x86_l_ba3;
	case 2983ULL: goto x86_l_ba7;
	case 2989ULL: goto x86_l_bad;
	case 2994ULL: goto x86_l_bb2;
	case 2998ULL: goto x86_l_bb6;
	case 3001ULL: goto x86_l_bb9;
	case 3003ULL: goto x86_l_bbb;
	case 3007ULL: goto x86_l_bbf;
	case 3013ULL: goto x86_l_bc5;
	case 3018ULL: goto x86_l_bca;
	case 3022ULL: goto x86_l_bce;
	case 3025ULL: goto x86_l_bd1;
	case 3027ULL: goto x86_l_bd3;
	case 3031ULL: goto x86_l_bd7;
	case 3033ULL: goto x86_l_bd9;
	case 3037ULL: goto x86_l_bdd;
	case 3043ULL: goto x86_l_be3;
	case 3048ULL: goto x86_l_be8;
	case 3051ULL: goto x86_l_beb;
	case 3055ULL: goto x86_l_bef;
	case 3059ULL: goto x86_l_bf3;
	case 3062ULL: goto x86_l_bf6;
	case 3064ULL: goto x86_l_bf8;
	case 3069ULL: goto x86_l_bfd;
	case 3074ULL: goto x86_l_c02;
	case 3079ULL: goto x86_l_c07;
	case 3081ULL: goto x86_l_c09;
	case 3083ULL: goto x86_l_c0b;
	case 3086ULL: goto x86_l_c0e;
	case 3089ULL: goto x86_l_c11;
	case 3094ULL: goto x86_l_c16;
	case 3099ULL: goto x86_l_c1b;
	case 3104ULL: goto x86_l_c20;
	case 3109ULL: goto x86_l_c25;
	case 3113ULL: goto x86_l_c29;
	case 3124ULL: goto x86_l_c34;
	case 3129ULL: goto x86_l_c39;
	case 3136ULL: goto x86_l_c40;
	case 3141ULL: goto x86_l_c45;
	case 3143ULL: goto x86_l_c47;
	case 3146ULL: goto x86_l_c4a;
	case 3152ULL: goto x86_l_c50;
	case 3157ULL: goto x86_l_c55;
	case 3160ULL: goto x86_l_c58;
	case 3166ULL: goto x86_l_c5e;
	case 3171ULL: goto x86_l_c63;
	case 3176ULL: goto x86_l_c68;
	case 3183ULL: goto x86_l_c6f;
	case 3188ULL: goto x86_l_c74;
	case 3190ULL: goto x86_l_c76;
	case 3193ULL: goto x86_l_c79;
	case 3199ULL: goto x86_l_c7f;
	case 3202ULL: goto x86_l_c82;
	case 3206ULL: goto x86_l_c86;
	case 3210ULL: goto x86_l_c8a;
	case 3216ULL: goto x86_l_c90;
	case 3221ULL: goto x86_l_c95;
	case 3224ULL: goto x86_l_c98;
	case 3231ULL: goto x86_l_c9f;
	case 3233ULL: goto x86_l_ca1;
	case 3236ULL: goto x86_l_ca4;
	case 3240ULL: goto x86_l_ca8;
	case 3245ULL: goto x86_l_cad;
	case 3247ULL: goto x86_l_caf;
	case 3252ULL: goto x86_l_cb4;
	case 3257ULL: goto x86_l_cb9;
	case 3260ULL: goto x86_l_cbc;
	case 3262ULL: goto x86_l_cbe;
	case 3264ULL: goto x86_l_cc0;
	case 3267ULL: goto x86_l_cc3;
	case 3270ULL: goto x86_l_cc6;
	case 3272ULL: goto x86_l_cc8;
	case 3275ULL: goto x86_l_ccb;
	case 3281ULL: goto x86_l_cd1;
	case 3288ULL: goto x86_l_cd8;
	case 3293ULL: goto x86_l_cdd;
	case 3300ULL: goto x86_l_ce4;
	case 3305ULL: goto x86_l_ce9;
	case 3307ULL: goto x86_l_ceb;
	case 3310ULL: goto x86_l_cee;
	case 3316ULL: goto x86_l_cf4;
	case 3320ULL: goto x86_l_cf8;
	case 3322ULL: goto x86_l_cfa;
	case 3327ULL: goto x86_l_cff;
	case 3332ULL: goto x86_l_d04;
	case 3337ULL: goto x86_l_d09;
	case 3339ULL: goto x86_l_d0b;
	case 3344ULL: goto x86_l_d10;
	case 3349ULL: goto x86_l_d15;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6d3:
	/* 0x6d3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6d8:
	/* 0x6d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6dd:
	/* 0x6dd: mov    rdi,QWORD PTR [rip+0x1bbaa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_6e4:
	/* 0x6e4: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6e9:
	/* 0x6e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6eb:
	/* 0x6eb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6ee:
	/* 0x6ee: je     2eb8 <generic_fentry_filter_arg+0x2eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11960ULL;
	}
x86_l_6f4:
	/* 0x6f4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6f7:
	/* 0x6f7: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_6fa:
	/* 0x6fa: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_6ff:
	/* 0x6ff: cmovb  ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_702:
	/* 0x702: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_705:
	/* 0x705: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_707:
	/* 0x707: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_70a:
	/* 0x70a: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_70d:
	/* 0x70d: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_712:
	/* 0x712: sub    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_715:
	/* 0x715: lea    eax,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_718:
	/* 0x718: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_71d:
	/* 0x71d: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_721:
	/* 0x721: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_727:
	/* 0x727: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_72a:
	/* 0x72a: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_72e:
	/* 0x72e: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_734:
	/* 0x734: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_737:
	/* 0x737: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_73b:
	/* 0x73b: lea    ebx,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_73e:
	/* 0x73e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_741:
	/* 0x741: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_745:
	/* 0x745: lea    ebp,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_749:
	/* 0x749: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_74f:
	/* 0x74f: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_753:
	/* 0x753: mov    BYTE PTR [rdi-0x3],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_757:
	/* 0x757: cmp    r10,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R13, X86_WIDTH_64);
x86_l_75a:
	/* 0x75a: je     7ae <generic_fentry_filter_arg+0x7ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7ae;
	}
x86_l_75c:
	/* 0x75c: lea    ebp,[r11+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_760:
	/* 0x760: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_766:
	/* 0x766: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_76a:
	/* 0x76a: mov    BYTE PTR [rdi-0x2],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_76e:
	/* 0x76e: cmp    r8,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R13, X86_WIDTH_64);
x86_l_771:
	/* 0x771: je     7ae <generic_fentry_filter_arg+0x7ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7ae;
	}
x86_l_773:
	/* 0x773: lea    ebp,[r9+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_777:
	/* 0x777: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_77d:
	/* 0x77d: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_781:
	/* 0x781: mov    BYTE PTR [rdi-0x1],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_785:
	/* 0x785: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_788:
	/* 0x788: je     7ae <generic_fentry_filter_arg+0x7ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7ae;
	}
x86_l_78a:
	/* 0x78a: cmp    r13,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_78e:
	/* 0x78e: je     7ae <generic_fentry_filter_arg+0x7ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7ae;
	}
x86_l_790:
	/* 0x790: lea    ebp,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_794:
	/* 0x794: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_79a:
	/* 0x79a: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_79e:
	/* 0x79e: mov    BYTE PTR [rdi],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a1:
	/* 0x7a1: add    r13,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_7a5:
	/* 0x7a5: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_7a9:
	/* 0x7a9: cmp    rcx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_7ac:
	/* 0x7ac: jne    745 <generic_fentry_filter_arg+0x745> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_745;
	}
x86_l_7ae:
	/* 0x7ae: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7b3:
	/* 0x7b3: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7b8:
	/* 0x7b8: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7bd:
	/* 0x7bd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7bf:
	/* 0x7bf: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c1:
	/* 0x7c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7c4:
	/* 0x7c4: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_7c7:
	/* 0x7c7: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7cc:
	/* 0x7cc: jmp    2eba <generic_fentry_filter_arg+0x2eba> */
	return 11962ULL;
x86_l_7d1:
	/* 0x7d1: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_7d4:
	/* 0x7d4: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_7da:
	/* 0x7da: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_7dd:
	/* 0x7dd: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_7e1:
	/* 0x7e1: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e5:
	/* 0x7e5: mov    ebp,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e7:
	/* 0x7e7: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_7e9:
	/* 0x7e9: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_7ec:
	/* 0x7ec: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_7ef:
	/* 0x7ef: je     7f9 <generic_fentry_filter_arg+0x7f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7f9;
	}
x86_l_7f1:
	/* 0x7f1: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_7f3:
	/* 0x7f3: je     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 262ULL;
	}
x86_l_7f9:
	/* 0x7f9: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_7fc:
	/* 0x7fc: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_800:
	/* 0x800: ja     8ff <generic_fentry_filter_arg+0x8ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_8ff;
	}
x86_l_806:
	/* 0x806: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_808:
	/* 0x808: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_80d:
	/* 0x80d: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_811:
	/* 0x811: jb     c1b <generic_fentry_filter_arg+0xc1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c1b;
	}
x86_l_817:
	/* 0x817: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_81c:
	/* 0x81c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_820:
	/* 0x820: jb     ad6 <generic_fentry_filter_arg+0xad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ad6;
	}
x86_l_826:
	/* 0x826: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_830:
	/* 0x830: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_834:
	/* 0x834: jae    8ff <generic_fentry_filter_arg+0x8ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_8ff;
	}
x86_l_83a:
	/* 0x83a: mov    WORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_841:
	/* 0x841: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_847:
	/* 0x847: ja     972 <generic_fentry_filter_arg+0x972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_972;
	}
x86_l_84d:
	/* 0x84d: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_850:
	/* 0x850: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_855:
	/* 0x855: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_857:
	/* 0x857: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_85b:
	/* 0x85b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_85f:
	/* 0x85f: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_864:
	/* 0x864: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_869:
	/* 0x869: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86b:
	/* 0x86b: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_870:
	/* 0x870: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_872:
	/* 0x872: je     1ce2 <generic_fentry_filter_arg+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7394ULL;
	}
x86_l_878:
	/* 0x878: movzx  eax,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_87d:
	/* 0x87d: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_882:
	/* 0x882: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_887:
	/* 0x887: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_889:
	/* 0x889: je     1ce4 <generic_fentry_filter_arg+0x1ce4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7396ULL;
	}
x86_l_88f:
	/* 0x88f: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_894:
	/* 0x894: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_897:
	/* 0x897: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_89c:
	/* 0x89c: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8a1:
	/* 0x8a1: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_8a4:
	/* 0x8a4: jb     972 <generic_fentry_filter_arg+0x972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_972;
	}
x86_l_8aa:
	/* 0x8aa: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_8af:
	/* 0x8af: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_8b1:
	/* 0x8b1: je     972 <generic_fentry_filter_arg+0x972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_972;
	}
x86_l_8b7:
	/* 0x8b7: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_8b9:
	/* 0x8b9: je     d1a <generic_fentry_filter_arg+0xd1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3354ULL;
	}
x86_l_8bf:
	/* 0x8bf: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_8c2:
	/* 0x8c2: jb     972 <generic_fentry_filter_arg+0x972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_972;
	}
x86_l_8c8:
	/* 0x8c8: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8cd:
	/* 0x8cd: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_8cf:
	/* 0x8cf: je     972 <generic_fentry_filter_arg+0x972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_972;
	}
x86_l_8d5:
	/* 0x8d5: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_8d7:
	/* 0x8d7: je     d1a <generic_fentry_filter_arg+0xd1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3354ULL;
	}
x86_l_8dd:
	/* 0x8dd: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_8e0:
	/* 0x8e0: jb     31f8 <generic_fentry_filter_arg+0x31f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12792ULL;
	}
x86_l_8e6:
	/* 0x8e6: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_8eb:
	/* 0x8eb: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_8ed:
	/* 0x8ed: je     31f8 <generic_fentry_filter_arg+0x31f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12792ULL;
	}
x86_l_8f3:
	/* 0x8f3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8f5:
	/* 0x8f5: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_8f7:
	/* 0x8f7: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_8fa:
	/* 0x8fa: jmp    31fa <generic_fentry_filter_arg+0x31fa> */
	return 12794ULL;
x86_l_8ff:
	/* 0x8ff: add    eax,0xfffffffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967293ULL);
x86_l_902:
	/* 0x902: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_905:
	/* 0x905: jae    972 <generic_fentry_filter_arg+0x972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_972;
	}
x86_l_907:
	/* 0x907: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_912:
	/* 0x912: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_918:
	/* 0x918: jbe    12cf <generic_fentry_filter_arg+0x12cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4815ULL;
	}
x86_l_91e:
	/* 0x91e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_920:
	/* 0x920: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_925:
	/* 0x925: jmp    d1a <generic_fentry_filter_arg+0xd1a> */
	return 3354ULL;
x86_l_92a:
	/* 0x92a: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_92d:
	/* 0x92d: ja     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 262ULL;
	}
x86_l_933:
	/* 0x933: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_935:
	/* 0x935: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_93a:
	/* 0x93a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_93e:
	/* 0x93e: jae    120b <generic_fentry_filter_arg+0x120b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4619ULL;
	}
x86_l_944:
	/* 0x944: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_949:
	/* 0x949: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_94c:
	/* 0x94c: jle    1701 <generic_fentry_filter_arg+0x1701> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5889ULL;
	}
x86_l_952:
	/* 0x952: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_955:
	/* 0x955: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_958:
	/* 0x958: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_95c:
	/* 0x95c: jae    1d13 <generic_fentry_filter_arg+0x1d13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7443ULL;
	}
x86_l_962:
	/* 0x962: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_965:
	/* 0x965: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_967:
	/* 0x967: jne    2048 <generic_fentry_filter_arg+0x2048> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8264ULL;
	}
x86_l_96d:
	/* 0x96d: jmp    3115 <generic_fentry_filter_arg+0x3115> */
	return 12565ULL;
x86_l_972:
	/* 0x972: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_974:
	/* 0x974: jmp    d1a <generic_fentry_filter_arg+0xd1a> */
	return 3354ULL;
x86_l_979:
	/* 0x979: lea    edx,[rax-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_97c:
	/* 0x97c: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_97f:
	/* 0x97f: jb     9df <generic_fentry_filter_arg+0x9df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9df;
	}
x86_l_981:
	/* 0x981: jmp    106 <generic_fentry_filter_arg+0x106> */
	return 262ULL;
x86_l_986:
	/* 0x986: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_989:
	/* 0x989: je     1497 <generic_fentry_filter_arg+0x1497> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5271ULL;
	}
x86_l_98f:
	/* 0x98f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_992:
	/* 0x992: jne    2272 <generic_fentry_filter_arg+0x2272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8818ULL;
	}
x86_l_998:
	/* 0x998: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_99b:
	/* 0x99b: ja     2266 <generic_fentry_filter_arg+0x2266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8806ULL;
	}
x86_l_9a1:
	/* 0x9a1: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_9a6:
	/* 0x9a6: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_9a9:
	/* 0x9a9: jae    2266 <generic_fentry_filter_arg+0x2266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8806ULL;
	}
x86_l_9af:
	/* 0x9af: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b3:
	/* 0x9b3: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b5:
	/* 0x9b5: jl     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 687ULL;
	}
x86_l_9bb:
	/* 0x9bb: jmp    2272 <generic_fentry_filter_arg+0x2272> */
	return 8818ULL;
x86_l_9c0:
	/* 0x9c0: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_9c3:
	/* 0x9c3: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_9c9:
	/* 0x9c9: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_9cc:
	/* 0x9cc: ja     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 262ULL;
	}
x86_l_9d2:
	/* 0x9d2: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_9d4:
	/* 0x9d4: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_9d9:
	/* 0x9d9: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_9dd:
	/* 0x9dd: jae    a07 <generic_fentry_filter_arg+0xa07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_a07;
	}
x86_l_9df:
	/* 0x9df: mov    rdx,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9e4:
	/* 0x9e4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9e7:
	/* 0x9e7: jle    a2b <generic_fentry_filter_arg+0xa2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_a2b;
	}
x86_l_9e9:
	/* 0x9e9: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_9ec:
	/* 0x9ec: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_9ef:
	/* 0x9ef: jae    d46 <generic_fentry_filter_arg+0xd46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3398ULL;
	}
x86_l_9f5:
	/* 0x9f5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f9:
	/* 0x9f9: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9fc:
	/* 0x9fc: jne    1c59 <generic_fentry_filter_arg+0x1c59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7257ULL;
	}
x86_l_a02:
	/* 0xa02: jmp    3115 <generic_fentry_filter_arg+0x3115> */
	return 12565ULL;
x86_l_a07:
	/* 0xa07: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_a0c:
	/* 0xa0c: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_a10:
	/* 0xa10: jb     a5d <generic_fentry_filter_arg+0xa5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a5d;
	}
x86_l_a12:
	/* 0xa12: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_a1c:
	/* 0xa1c: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_a20:
	/* 0xa20: jb     e1a <generic_fentry_filter_arg+0xe1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3610ULL;
	}
x86_l_a26:
	/* 0xa26: jmp    106 <generic_fentry_filter_arg+0x106> */
	return 262ULL;
x86_l_a2b:
	/* 0xa2b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a2e:
	/* 0xa2e: je     12af <generic_fentry_filter_arg+0x12af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4783ULL;
	}
x86_l_a34:
	/* 0xa34: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a37:
	/* 0xa37: jne    1c59 <generic_fentry_filter_arg+0x1c59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7257ULL;
	}
x86_l_a3d:
	/* 0xa3d: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_a40:
	/* 0xa40: je     a4b <generic_fentry_filter_arg+0xa4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a4b;
	}
x86_l_a42:
	/* 0xa42: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_a45:
	/* 0xa45: jne    1c4c <generic_fentry_filter_arg+0x1c4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7244ULL;
	}
x86_l_a4b:
	/* 0xa4b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a4f:
	/* 0xa4f: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a52:
	/* 0xa52: jl     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 687ULL;
	}
x86_l_a58:
	/* 0xa58: jmp    1c59 <generic_fentry_filter_arg+0x1c59> */
	return 7257ULL;
x86_l_a5d:
	/* 0xa5d: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_a60:
	/* 0xa60: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_a66:
	/* 0xa66: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a6d:
	/* 0xa6d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a72:
	/* 0xa72: mov    rdi,QWORD PTR [rip+0x1bbaa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_a79:
	/* 0xa79: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a7e:
	/* 0xa7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a80:
	/* 0xa80: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a83:
	/* 0xa83: je     17de <generic_fentry_filter_arg+0x17de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6110ULL;
	}
x86_l_a89:
	/* 0xa89: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a8d:
	/* 0xa8d: mov    rcx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a90:
	/* 0xa90: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a95:
	/* 0xa95: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a9a:
	/* 0xa9a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_a9d:
	/* 0xa9d: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_aa2:
	/* 0xaa2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_aa4:
	/* 0xaa4: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_aa9:
	/* 0xaa9: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_aac:
	/* 0xaac: je     180a <generic_fentry_filter_arg+0x180a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6154ULL;
	}
x86_l_ab2:
	/* 0xab2: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_ab5:
	/* 0xab5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aba:
	/* 0xaba: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_abf:
	/* 0xabf: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_ac2:
	/* 0xac2: jne    1825 <generic_fentry_filter_arg+0x1825> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6181ULL;
	}
x86_l_ac8:
	/* 0xac8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_acb:
	/* 0xacb: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_ace:
	/* 0xace: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ad1:
	/* 0xad1: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_ad6:
	/* 0xad6: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_adb:
	/* 0xadb: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ae0:
	/* 0xae0: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ae4:
	/* 0xae4: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_aef:
	/* 0xaef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_af4:
	/* 0xaf4: mov    rdi,QWORD PTR [rip+0x1bbaa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_afb:
	/* 0xafb: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b00:
	/* 0xb00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b02:
	/* 0xb02: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_b05:
	/* 0xb05: je     d09 <generic_fentry_filter_arg+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d09;
	}
x86_l_b0b:
	/* 0xb0b: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_b10:
	/* 0xb10: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b13:
	/* 0xb13: je     d0b <generic_fentry_filter_arg+0xd0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d0b;
	}
x86_l_b19:
	/* 0xb19: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b1e:
	/* 0xb1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b23:
	/* 0xb23: mov    rdi,QWORD PTR [rip+0x1bbaa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_b2a:
	/* 0xb2a: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b2f:
	/* 0xb2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b31:
	/* 0xb31: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b34:
	/* 0xb34: je     d09 <generic_fentry_filter_arg+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d09;
	}
x86_l_b3a:
	/* 0xb3a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_b3d:
	/* 0xb3d: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_b40:
	/* 0xb40: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_b45:
	/* 0xb45: cmovb  ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_b48:
	/* 0xb48: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_b4b:
	/* 0xb4b: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b4d:
	/* 0xb4d: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_b50:
	/* 0xb50: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_b53:
	/* 0xb53: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_b58:
	/* 0xb58: sub    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b5b:
	/* 0xb5b: lea    eax,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_b5e:
	/* 0xb5e: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b63:
	/* 0xb63: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_b67:
	/* 0xb67: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_b6d:
	/* 0xb6d: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b70:
	/* 0xb70: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_b74:
	/* 0xb74: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_b7a:
	/* 0xb7a: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b7d:
	/* 0xb7d: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_b81:
	/* 0xb81: lea    ebx,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_b84:
	/* 0xb84: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b87:
	/* 0xb87: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b8b:
	/* 0xb8b: lea    ebp,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_b8f:
	/* 0xb8f: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b95:
	/* 0xb95: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_b9a:
	/* 0xb9a: mov    BYTE PTR [rdi-0x3],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_b9e:
	/* 0xb9e: cmp    r10,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R13, X86_WIDTH_64);
x86_l_ba1:
	/* 0xba1: je     bf8 <generic_fentry_filter_arg+0xbf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf8;
	}
x86_l_ba3:
	/* 0xba3: lea    ebp,[r11+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_ba7:
	/* 0xba7: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bad:
	/* 0xbad: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_bb2:
	/* 0xbb2: mov    BYTE PTR [rdi-0x2],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_bb6:
	/* 0xbb6: cmp    r8,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R13, X86_WIDTH_64);
x86_l_bb9:
	/* 0xbb9: je     bf8 <generic_fentry_filter_arg+0xbf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf8;
	}
x86_l_bbb:
	/* 0xbbb: lea    ebp,[r9+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_bbf:
	/* 0xbbf: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bc5:
	/* 0xbc5: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_bca:
	/* 0xbca: mov    BYTE PTR [rdi-0x1],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_bce:
	/* 0xbce: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_bd1:
	/* 0xbd1: je     bf8 <generic_fentry_filter_arg+0xbf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf8;
	}
x86_l_bd3:
	/* 0xbd3: cmp    r13,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_bd7:
	/* 0xbd7: je     bf8 <generic_fentry_filter_arg+0xbf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf8;
	}
x86_l_bd9:
	/* 0xbd9: lea    ebp,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_bdd:
	/* 0xbdd: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_be3:
	/* 0xbe3: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_be8:
	/* 0xbe8: mov    BYTE PTR [rdi],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_beb:
	/* 0xbeb: add    r13,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_bef:
	/* 0xbef: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_bf3:
	/* 0xbf3: cmp    rcx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_bf6:
	/* 0xbf6: jne    b8b <generic_fentry_filter_arg+0xb8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b8b;
	}
x86_l_bf8:
	/* 0xbf8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_bfd:
	/* 0xbfd: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c02:
	/* 0xc02: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c07:
	/* 0xc07: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c09:
	/* 0xc09: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c0b:
	/* 0xc0b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c0e:
	/* 0xc0e: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_c11:
	/* 0xc11: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c16:
	/* 0xc16: jmp    d0b <generic_fentry_filter_arg+0xd0b> */
	goto x86_l_d0b;
x86_l_c1b:
	/* 0xc1b: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c20:
	/* 0xc20: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c25:
	/* 0xc25: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c29:
	/* 0xc29: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_c34:
	/* 0xc34: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c39:
	/* 0xc39: mov    rdi,QWORD PTR [rip+0x1bbaa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_c40:
	/* 0xc40: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c45:
	/* 0xc45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c47:
	/* 0xc47: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_c4a:
	/* 0xc4a: je     d09 <generic_fentry_filter_arg+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d09;
	}
x86_l_c50:
	/* 0xc50: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_c55:
	/* 0xc55: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c58:
	/* 0xc58: je     d0b <generic_fentry_filter_arg+0xd0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d0b;
	}
x86_l_c5e:
	/* 0xc5e: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c63:
	/* 0xc63: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c68:
	/* 0xc68: mov    rdi,QWORD PTR [rip+0x1bbaa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_c6f:
	/* 0xc6f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c74:
	/* 0xc74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c76:
	/* 0xc76: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c79:
	/* 0xc79: je     d09 <generic_fentry_filter_arg+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d09;
	}
x86_l_c7f:
	/* 0xc7f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_c82:
	/* 0xc82: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c86:
	/* 0xc86: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_c8a:
	/* 0xc8a: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_c90:
	/* 0xc90: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_c95:
	/* 0xc95: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_c98:
	/* 0xc98: lea    eax,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_c9f:
	/* 0xc9f: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca1:
	/* 0xca1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ca4:
	/* 0xca4: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_ca8:
	/* 0xca8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cad:
	/* 0xcad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_caf:
	/* 0xcaf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cb4:
	/* 0xcb4: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cb9:
	/* 0xcb9: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_cbc:
	/* 0xcbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cbe:
	/* 0xcbe: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc0:
	/* 0xcc0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cc3:
	/* 0xcc3: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_cc6:
	/* 0xcc6: jmp    d0b <generic_fentry_filter_arg+0xd0b> */
	goto x86_l_d0b;
x86_l_cc8:
	/* 0xcc8: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_ccb:
	/* 0xccb: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_cd1:
	/* 0xcd1: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cd8:
	/* 0xcd8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cdd:
	/* 0xcdd: mov    rdi,QWORD PTR [rip+0x1bbaa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_ce4:
	/* 0xce4: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ce9:
	/* 0xce9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ceb:
	/* 0xceb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cee:
	/* 0xcee: je     17de <generic_fentry_filter_arg+0x17de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6110ULL;
	}
x86_l_cf4:
	/* 0xcf4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cf8:
	/* 0xcf8: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cfa:
	/* 0xcfa: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cff:
	/* 0xcff: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d04:
	/* 0xd04: jmp    179f <generic_fentry_filter_arg+0x179f> */
	return 6047ULL;
x86_l_d09:
	/* 0xd09: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d0b:
	/* 0xd0b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d10:
	/* 0xd10: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d15:
	/* 0xd15: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
	return 3354ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3354ULL: goto x86_l_d1a;
	case 3359ULL: goto x86_l_d1f;
	case 3363ULL: goto x86_l_d23;
	case 3369ULL: goto x86_l_d29;
	case 3379ULL: goto x86_l_d33;
	case 3383ULL: goto x86_l_d37;
	case 3389ULL: goto x86_l_d3d;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3401ULL: goto x86_l_d49;
	case 3407ULL: goto x86_l_d4f;
	case 3411ULL: goto x86_l_d53;
	case 3414ULL: goto x86_l_d56;
	case 3420ULL: goto x86_l_d5c;
	case 3425ULL: goto x86_l_d61;
	case 3428ULL: goto x86_l_d64;
	case 3433ULL: goto x86_l_d69;
	case 3437ULL: goto x86_l_d6d;
	case 3442ULL: goto x86_l_d72;
	case 3446ULL: goto x86_l_d76;
	case 3451ULL: goto x86_l_d7b;
	case 3455ULL: goto x86_l_d7f;
	case 3460ULL: goto x86_l_d84;
	case 3465ULL: goto x86_l_d89;
	case 3467ULL: goto x86_l_d8b;
	case 3470ULL: goto x86_l_d8e;
	case 3472ULL: goto x86_l_d90;
	case 3475ULL: goto x86_l_d93;
	case 3477ULL: goto x86_l_d95;
	case 3480ULL: goto x86_l_d98;
	case 3483ULL: goto x86_l_d9b;
	case 3489ULL: goto x86_l_da1;
	case 3492ULL: goto x86_l_da4;
	case 3497ULL: goto x86_l_da9;
	case 3500ULL: goto x86_l_dac;
	case 3506ULL: goto x86_l_db2;
	case 3511ULL: goto x86_l_db7;
	case 3514ULL: goto x86_l_dba;
	case 3520ULL: goto x86_l_dc0;
	case 3523ULL: goto x86_l_dc3;
	case 3529ULL: goto x86_l_dc9;
	case 3532ULL: goto x86_l_dcc;
	case 3538ULL: goto x86_l_dd2;
	case 3543ULL: goto x86_l_dd7;
	case 3546ULL: goto x86_l_dda;
	case 3552ULL: goto x86_l_de0;
	case 3556ULL: goto x86_l_de4;
	case 3561ULL: goto x86_l_de9;
	case 3564ULL: goto x86_l_dec;
	case 3570ULL: goto x86_l_df2;
	case 3573ULL: goto x86_l_df5;
	case 3579ULL: goto x86_l_dfb;
	case 3584ULL: goto x86_l_e00;
	case 3587ULL: goto x86_l_e03;
	case 3593ULL: goto x86_l_e09;
	case 3598ULL: goto x86_l_e0e;
	case 3601ULL: goto x86_l_e11;
	case 3604ULL: goto x86_l_e14;
	case 3610ULL: goto x86_l_e1a;
	case 3613ULL: goto x86_l_e1d;
	case 3619ULL: goto x86_l_e23;
	case 3624ULL: goto x86_l_e28;
	case 3629ULL: goto x86_l_e2d;
	case 3632ULL: goto x86_l_e30;
	case 3634ULL: goto x86_l_e32;
	case 3637ULL: goto x86_l_e35;
	case 3643ULL: goto x86_l_e3b;
	case 3647ULL: goto x86_l_e3f;
	case 3650ULL: goto x86_l_e42;
	case 3653ULL: goto x86_l_e45;
	case 3659ULL: goto x86_l_e4b;
	case 3662ULL: goto x86_l_e4e;
	case 3668ULL: goto x86_l_e54;
	case 3673ULL: goto x86_l_e59;
	case 3676ULL: goto x86_l_e5c;
	case 3682ULL: goto x86_l_e62;
	case 3687ULL: goto x86_l_e67;
	case 3690ULL: goto x86_l_e6a;
	case 3696ULL: goto x86_l_e70;
	case 3700ULL: goto x86_l_e74;
	case 3702ULL: goto x86_l_e76;
	case 3705ULL: goto x86_l_e79;
	case 3708ULL: goto x86_l_e7c;
	case 3713ULL: goto x86_l_e81;
	case 3717ULL: goto x86_l_e85;
	case 3722ULL: goto x86_l_e8a;
	case 3729ULL: goto x86_l_e91;
	case 3734ULL: goto x86_l_e96;
	case 3736ULL: goto x86_l_e98;
	case 3739ULL: goto x86_l_e9b;
	case 3745ULL: goto x86_l_ea1;
	case 3748ULL: goto x86_l_ea4;
	case 3751ULL: goto x86_l_ea7;
	case 3756ULL: goto x86_l_eac;
	case 3758ULL: goto x86_l_eae;
	case 3762ULL: goto x86_l_eb2;
	case 3764ULL: goto x86_l_eb4;
	case 3766ULL: goto x86_l_eb6;
	case 3769ULL: goto x86_l_eb9;
	case 3772ULL: goto x86_l_ebc;
	case 3775ULL: goto x86_l_ebf;
	case 3777ULL: goto x86_l_ec1;
	case 3779ULL: goto x86_l_ec3;
	case 3783ULL: goto x86_l_ec7;
	case 3786ULL: goto x86_l_eca;
	case 3788ULL: goto x86_l_ecc;
	case 3792ULL: goto x86_l_ed0;
	case 3794ULL: goto x86_l_ed2;
	case 3796ULL: goto x86_l_ed4;
	case 3801ULL: goto x86_l_ed9;
	case 3805ULL: goto x86_l_edd;
	case 3808ULL: goto x86_l_ee0;
	case 3812ULL: goto x86_l_ee4;
	case 3816ULL: goto x86_l_ee8;
	case 3820ULL: goto x86_l_eec;
	case 3824ULL: goto x86_l_ef0;
	case 3827ULL: goto x86_l_ef3;
	case 3831ULL: goto x86_l_ef7;
	case 3835ULL: goto x86_l_efb;
	case 3839ULL: goto x86_l_eff;
	case 3843ULL: goto x86_l_f03;
	case 3845ULL: goto x86_l_f05;
	case 3848ULL: goto x86_l_f08;
	case 3851ULL: goto x86_l_f0b;
	case 3853ULL: goto x86_l_f0d;
	case 3855ULL: goto x86_l_f0f;
	case 3857ULL: goto x86_l_f11;
	case 3863ULL: goto x86_l_f17;
	case 3867ULL: goto x86_l_f1b;
	case 3872ULL: goto x86_l_f20;
	case 3874ULL: goto x86_l_f22;
	case 3878ULL: goto x86_l_f26;
	case 3881ULL: goto x86_l_f29;
	case 3885ULL: goto x86_l_f2d;
	case 3891ULL: goto x86_l_f33;
	case 3893ULL: goto x86_l_f35;
	case 3898ULL: goto x86_l_f3a;
	case 3902ULL: goto x86_l_f3e;
	case 3907ULL: goto x86_l_f43;
	case 3912ULL: goto x86_l_f48;
	case 3916ULL: goto x86_l_f4c;
	case 3927ULL: goto x86_l_f57;
	case 3932ULL: goto x86_l_f5c;
	case 3939ULL: goto x86_l_f63;
	case 3944ULL: goto x86_l_f68;
	case 3946ULL: goto x86_l_f6a;
	case 3949ULL: goto x86_l_f6d;
	case 3955ULL: goto x86_l_f73;
	case 3960ULL: goto x86_l_f78;
	case 3963ULL: goto x86_l_f7b;
	case 3969ULL: goto x86_l_f81;
	case 3972ULL: goto x86_l_f84;
	case 3977ULL: goto x86_l_f89;
	case 3984ULL: goto x86_l_f90;
	case 3989ULL: goto x86_l_f95;
	case 3991ULL: goto x86_l_f97;
	case 3994ULL: goto x86_l_f9a;
	case 4000ULL: goto x86_l_fa0;
	case 4006ULL: goto x86_l_fa6;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4021ULL: goto x86_l_fb5;
	case 4023ULL: goto x86_l_fb7;
	case 4026ULL: goto x86_l_fba;
	case 4030ULL: goto x86_l_fbe;
	case 4035ULL: goto x86_l_fc3;
	case 4037ULL: goto x86_l_fc5;
	case 4041ULL: goto x86_l_fc9;
	case 4044ULL: goto x86_l_fcc;
	case 4046ULL: goto x86_l_fce;
	case 4051ULL: goto x86_l_fd3;
	case 4054ULL: goto x86_l_fd6;
	case 4057ULL: goto x86_l_fd9;
	case 4059ULL: goto x86_l_fdb;
	case 4064ULL: goto x86_l_fe0;
	case 4075ULL: goto x86_l_feb;
	case 4081ULL: goto x86_l_ff1;
	case 4087ULL: goto x86_l_ff7;
	case 4089ULL: goto x86_l_ff9;
	case 4094ULL: goto x86_l_ffe;
	case 4098ULL: goto x86_l_1002;
	case 4104ULL: goto x86_l_1008;
	case 4109ULL: goto x86_l_100d;
	case 4114ULL: goto x86_l_1012;
	case 4119ULL: goto x86_l_1017;
	case 4122ULL: goto x86_l_101a;
	case 4124ULL: goto x86_l_101c;
	case 4127ULL: goto x86_l_101f;
	case 4133ULL: goto x86_l_1025;
	case 4137ULL: goto x86_l_1029;
	case 4140ULL: goto x86_l_102c;
	case 4143ULL: goto x86_l_102f;
	case 4147ULL: goto x86_l_1033;
	case 4150ULL: goto x86_l_1036;
	case 4153ULL: goto x86_l_1039;
	case 4158ULL: goto x86_l_103e;
	case 4161ULL: goto x86_l_1041;
	case 4167ULL: goto x86_l_1047;
	case 4170ULL: goto x86_l_104a;
	case 4176ULL: goto x86_l_1050;
	case 4181ULL: goto x86_l_1055;
	case 4184ULL: goto x86_l_1058;
	case 4190ULL: goto x86_l_105e;
	case 4195ULL: goto x86_l_1063;
	case 4198ULL: goto x86_l_1066;
	case 4202ULL: goto x86_l_106a;
	case 4208ULL: goto x86_l_1070;
	case 4211ULL: goto x86_l_1073;
	case 4217ULL: goto x86_l_1079;
	case 4222ULL: goto x86_l_107e;
	case 4225ULL: goto x86_l_1081;
	case 4231ULL: goto x86_l_1087;
	case 4236ULL: goto x86_l_108c;
	case 4241ULL: goto x86_l_1091;
	case 4245ULL: goto x86_l_1095;
	case 4256ULL: goto x86_l_10a0;
	case 4261ULL: goto x86_l_10a5;
	case 4268ULL: goto x86_l_10ac;
	case 4273ULL: goto x86_l_10b1;
	case 4275ULL: goto x86_l_10b3;
	case 4278ULL: goto x86_l_10b6;
	case 4284ULL: goto x86_l_10bc;
	case 4287ULL: goto x86_l_10bf;
	case 4292ULL: goto x86_l_10c4;
	case 4295ULL: goto x86_l_10c7;
	case 4301ULL: goto x86_l_10cd;
	case 4306ULL: goto x86_l_10d2;
	case 4313ULL: goto x86_l_10d9;
	case 4318ULL: goto x86_l_10de;
	case 4320ULL: goto x86_l_10e0;
	case 4323ULL: goto x86_l_10e3;
	case 4329ULL: goto x86_l_10e9;
	case 4332ULL: goto x86_l_10ec;
	case 4337ULL: goto x86_l_10f1;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4348ULL: goto x86_l_10fc;
	case 4351ULL: goto x86_l_10ff;
	case 4353ULL: goto x86_l_1101;
	case 4356ULL: goto x86_l_1104;
	case 4359ULL: goto x86_l_1107;
	case 4364ULL: goto x86_l_110c;
	case 4367ULL: goto x86_l_110f;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4379ULL: goto x86_l_111b;
	case 4385ULL: goto x86_l_1121;
	case 4388ULL: goto x86_l_1124;
	case 4392ULL: goto x86_l_1128;
	case 4398ULL: goto x86_l_112e;
	case 4401ULL: goto x86_l_1131;
	case 4405ULL: goto x86_l_1135;
	case 4408ULL: goto x86_l_1138;
	case 4411ULL: goto x86_l_113b;
	case 4415ULL: goto x86_l_113f;
	case 4419ULL: goto x86_l_1143;
	case 4425ULL: goto x86_l_1149;
	case 4429ULL: goto x86_l_114d;
	case 4433ULL: goto x86_l_1151;
	case 4436ULL: goto x86_l_1154;
	case 4438ULL: goto x86_l_1156;
	case 4442ULL: goto x86_l_115a;
	case 4448ULL: goto x86_l_1160;
	case 4452ULL: goto x86_l_1164;
	case 4456ULL: goto x86_l_1168;
	case 4459ULL: goto x86_l_116b;
	case 4461ULL: goto x86_l_116d;
	case 4465ULL: goto x86_l_1171;
	case 4471ULL: goto x86_l_1177;
	case 4475ULL: goto x86_l_117b;
	case 4479ULL: goto x86_l_117f;
	case 4482ULL: goto x86_l_1182;
	case 4484ULL: goto x86_l_1184;
	case 4488ULL: goto x86_l_1188;
	case 4490ULL: goto x86_l_118a;
	case 4494ULL: goto x86_l_118e;
	case 4500ULL: goto x86_l_1194;
	case 4504ULL: goto x86_l_1198;
	case 4507ULL: goto x86_l_119b;
	case 4511ULL: goto x86_l_119f;
	case 4515ULL: goto x86_l_11a3;
	case 4518ULL: goto x86_l_11a6;
	case 4520ULL: goto x86_l_11a8;
	case 4525ULL: goto x86_l_11ad;
	case 4530ULL: goto x86_l_11b2;
	case 4535ULL: goto x86_l_11b7;
	case 4540ULL: goto x86_l_11bc;
	case 4543ULL: goto x86_l_11bf;
	case 4549ULL: goto x86_l_11c5;
	case 4553ULL: goto x86_l_11c9;
	case 4555ULL: goto x86_l_11cb;
	case 4561ULL: goto x86_l_11d1;
	case 4566ULL: goto x86_l_11d6;
	case 4571ULL: goto x86_l_11db;
	case 4575ULL: goto x86_l_11df;
	case 4581ULL: goto x86_l_11e5;
	case 4591ULL: goto x86_l_11ef;
	case 4595ULL: goto x86_l_11f3;
	case 4601ULL: goto x86_l_11f9;
	case 4604ULL: goto x86_l_11fc;
	case 4610ULL: goto x86_l_1202;
	case 4614ULL: goto x86_l_1206;
	case 4617ULL: goto x86_l_1209;
	case 4619ULL: goto x86_l_120b;
	case 4624ULL: goto x86_l_1210;
	case 4628ULL: goto x86_l_1214;
	case 4634ULL: goto x86_l_121a;
	case 4644ULL: goto x86_l_1224;
	case 4648ULL: goto x86_l_1228;
	case 4654ULL: goto x86_l_122e;
	case 4657ULL: goto x86_l_1231;
	case 4663ULL: goto x86_l_1237;
	case 4667ULL: goto x86_l_123b;
	case 4670ULL: goto x86_l_123e;
	case 4675ULL: goto x86_l_1243;
	case 4677ULL: goto x86_l_1245;
	case 4682ULL: goto x86_l_124a;
	case 4688ULL: goto x86_l_1250;
	case 4693ULL: goto x86_l_1255;
	case 4696ULL: goto x86_l_1258;
	case 4702ULL: goto x86_l_125e;
	case 4707ULL: goto x86_l_1263;
	case 4709ULL: goto x86_l_1265;
	case 4714ULL: goto x86_l_126a;
	case 4720ULL: goto x86_l_1270;
	case 4723ULL: goto x86_l_1273;
	case 4729ULL: goto x86_l_1279;
	case 4734ULL: goto x86_l_127e;
	case 4736ULL: goto x86_l_1280;
	case 4741ULL: goto x86_l_1285;
	case 4747ULL: goto x86_l_128b;
	case 4750ULL: goto x86_l_128e;
	case 4756ULL: goto x86_l_1294;
	case 4761ULL: goto x86_l_1299;
	case 4767ULL: goto x86_l_129f;
	case 4772ULL: goto x86_l_12a4;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4786ULL: goto x86_l_12b2;
	case 4788ULL: goto x86_l_12b4;
	case 4791ULL: goto x86_l_12b7;
	case 4797ULL: goto x86_l_12bd;
	case 4801ULL: goto x86_l_12c1;
	case 4804ULL: goto x86_l_12c4;
	case 4810ULL: goto x86_l_12ca;
	case 4815ULL: goto x86_l_12cf;
	case 4818ULL: goto x86_l_12d2;
	case 4823ULL: goto x86_l_12d7;
	case 4828ULL: goto x86_l_12dc;
	case 4834ULL: goto x86_l_12e2;
	case 4838ULL: goto x86_l_12e6;
	case 4844ULL: goto x86_l_12ec;
	case 4847ULL: goto x86_l_12ef;
	case 4850ULL: goto x86_l_12f2;
	case 4853ULL: goto x86_l_12f5;
	case 4855ULL: goto x86_l_12f7;
	case 4857ULL: goto x86_l_12f9;
	case 4860ULL: goto x86_l_12fc;
	case 4862ULL: goto x86_l_12fe;
	case 4864ULL: goto x86_l_1300;
	case 4866ULL: goto x86_l_1302;
	case 4868ULL: goto x86_l_1304;
	case 4871ULL: goto x86_l_1307;
	case 4873ULL: goto x86_l_1309;
	case 4875ULL: goto x86_l_130b;
	case 4877ULL: goto x86_l_130d;
	case 4880ULL: goto x86_l_1310;
	case 4884ULL: goto x86_l_1314;
	case 4890ULL: goto x86_l_131a;
	case 4893ULL: goto x86_l_131d;
	case 4899ULL: goto x86_l_1323;
	case 4902ULL: goto x86_l_1326;
	case 4904ULL: goto x86_l_1328;
	case 4909ULL: goto x86_l_132d;
	case 4914ULL: goto x86_l_1332;
	case 4919ULL: goto x86_l_1337;
	case 4922ULL: goto x86_l_133a;
	case 4928ULL: goto x86_l_1340;
	case 4933ULL: goto x86_l_1345;
	case 4936ULL: goto x86_l_1348;
	case 4942ULL: goto x86_l_134e;
	case 4946ULL: goto x86_l_1352;
	case 4948ULL: goto x86_l_1354;
	case 4950ULL: goto x86_l_1356;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d1a:
	/* 0xd1a: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d1f:
	/* 0xd1f: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_d23:
	/* 0xd23: ja     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 670ULL;
	}
x86_l_d29:
	/* 0xd29: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_d33:
	/* 0xd33: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_d37:
	/* 0xd37: jae    29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 670ULL;
	}
x86_l_d3d:
	/* 0xd3d: xor    rbx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_d41:
	/* 0xd41: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_d46:
	/* 0xd46: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d49:
	/* 0xd49: jne    1c59 <generic_fentry_filter_arg+0x1c59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7257ULL;
	}
x86_l_d4f:
	/* 0xd4f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d53:
	/* 0xd53: test   QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d56:
	/* 0xd56: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_d5c:
	/* 0xd5c: jmp    1c59 <generic_fentry_filter_arg+0x1c59> */
	return 7257ULL;
x86_l_d61:
	/* 0xd61: movzx  edx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d64:
	/* 0xd64: mov    WORD PTR [rsp+0x7e],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_d69:
	/* 0xd69: movzx  edx,WORD PTR [rsi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_d6d:
	/* 0xd6d: mov    WORD PTR [rsp+0x78],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d72:
	/* 0xd72: mov    rdx,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d76:
	/* 0xd76: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d7b:
	/* 0xd7b: mov    rdx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d7f:
	/* 0xd7f: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d84:
	/* 0xd84: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d89:
	/* 0xd89: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d8b:
	/* 0xd8b: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_d8e:
	/* 0xd8e: jle    db7 <generic_fentry_filter_arg+0xdb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_db7;
	}
x86_l_d90:
	/* 0xd90: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_d93:
	/* 0xd93: jg     de9 <generic_fentry_filter_arg+0xde9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_de9;
	}
x86_l_d95:
	/* 0xd95: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_d98:
	/* 0xd98: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d9b:
	/* 0xd9b: jb     137e <generic_fentry_filter_arg+0x137e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4990ULL;
	}
x86_l_da1:
	/* 0xda1: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_da4:
	/* 0xda4: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_da9:
	/* 0xda9: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dac:
	/* 0xdac: jb     1377 <generic_fentry_filter_arg+0x1377> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4983ULL;
	}
x86_l_db2:
	/* 0xdb2: jmp    299 <generic_fentry_filter_arg+0x299> */
	return 665ULL;
x86_l_db7:
	/* 0xdb7: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_dba:
	/* 0xdba: jle    103e <generic_fentry_filter_arg+0x103e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_103e;
	}
x86_l_dc0:
	/* 0xdc0: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_dc3:
	/* 0xdc3: jg     1364 <generic_fentry_filter_arg+0x1364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4964ULL;
	}
x86_l_dc9:
	/* 0xdc9: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_dcc:
	/* 0xdcc: je     1377 <generic_fentry_filter_arg+0x1377> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4983ULL;
	}
x86_l_dd2:
	/* 0xdd2: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_dd7:
	/* 0xdd7: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_dda:
	/* 0xdda: jne    299 <generic_fentry_filter_arg+0x299> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 665ULL;
	}
x86_l_de0:
	/* 0xde0: movzx  ebx,WORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_de4:
	/* 0xde4: jmp    1bb6 <generic_fentry_filter_arg+0x1bb6> */
	return 7094ULL;
x86_l_de9:
	/* 0xde9: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_dec:
	/* 0xdec: jg     13b7 <generic_fentry_filter_arg+0x13b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5047ULL;
	}
x86_l_df2:
	/* 0xdf2: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_df5:
	/* 0xdf5: je     13f1 <generic_fentry_filter_arg+0x13f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5105ULL;
	}
x86_l_dfb:
	/* 0xdfb: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_e00:
	/* 0xe00: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_e03:
	/* 0xe03: je     13e7 <generic_fentry_filter_arg+0x13e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5095ULL;
	}
x86_l_e09:
	/* 0xe09: jmp    299 <generic_fentry_filter_arg+0x299> */
	return 665ULL;
x86_l_e0e:
	/* 0xe0e: lea    edx,[rax-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_e11:
	/* 0xe11: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_e14:
	/* 0xe14: jae    1901 <generic_fentry_filter_arg+0x1901> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6401ULL;
	}
x86_l_e1a:
	/* 0xe1a: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_e1d:
	/* 0xe1d: jne    100d <generic_fentry_filter_arg+0x100d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_100d;
	}
x86_l_e23:
	/* 0xe23: mov    rsi,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e28:
	/* 0xe28: mov    rdx,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e2d:
	/* 0xe2d: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_e30:
	/* 0xe30: je     e3b <generic_fentry_filter_arg+0xe3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e3b;
	}
x86_l_e32:
	/* 0xe32: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_e35:
	/* 0xe35: jne    1b0b <generic_fentry_filter_arg+0x1b0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6923ULL;
	}
x86_l_e3b:
	/* 0xe3b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e3f:
	/* 0xe3f: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e42:
	/* 0xe42: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_e45:
	/* 0xe45: jg     1b20 <generic_fentry_filter_arg+0x1b20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6944ULL;
	}
x86_l_e4b:
	/* 0xe4b: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_e4e:
	/* 0xe4e: jle    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 687ULL;
	}
x86_l_e54:
	/* 0xe54: jmp    1b20 <generic_fentry_filter_arg+0x1b20> */
	return 6944ULL;
x86_l_e59:
	/* 0xe59: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_e5c:
	/* 0xe5c: je     14bf <generic_fentry_filter_arg+0x14bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5311ULL;
	}
x86_l_e62:
	/* 0xe62: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_e67:
	/* 0xe67: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_e6a:
	/* 0xe6a: jne    2ec9 <generic_fentry_filter_arg+0x2ec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11977ULL;
	}
x86_l_e70:
	/* 0xe70: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e74:
	/* 0xe74: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e76:
	/* 0xe76: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e79:
	/* 0xe79: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_e7c:
	/* 0xe7c: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_e81:
	/* 0xe81: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e85:
	/* 0xe85: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e8a:
	/* 0xe8a: mov    rdi,QWORD PTR [rip+0x1bbaa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_e91:
	/* 0xe91: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e96:
	/* 0xe96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e98:
	/* 0xe98: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e9b:
	/* 0xe9b: je     2340 <generic_fentry_filter_arg+0x2340> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9024ULL;
	}
x86_l_ea1:
	/* 0xea1: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_ea4:
	/* 0xea4: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_ea7:
	/* 0xea7: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_eac:
	/* 0xeac: je     f17 <generic_fentry_filter_arg+0xf17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f17;
	}
x86_l_eae:
	/* 0xeae: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb2:
	/* 0xeb2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eb4:
	/* 0xeb4: jmp    ec1 <generic_fentry_filter_arg+0xec1> */
	goto x86_l_ec1;
x86_l_eb6:
	/* 0xeb6: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_eb9:
	/* 0xeb9: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ebc:
	/* 0xebc: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_ebf:
	/* 0xebf: je     f17 <generic_fentry_filter_arg+0xf17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f17;
	}
x86_l_ec1:
	/* 0xec1: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ec3:
	/* 0xec3: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_ec7:
	/* 0xec7: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_eca:
	/* 0xeca: jae    eb6 <generic_fentry_filter_arg+0xeb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_eb6;
	}
x86_l_ecc:
	/* 0xecc: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_ed0:
	/* 0xed0: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_ed2:
	/* 0xed2: je     f0f <generic_fentry_filter_arg+0xf0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f0f;
	}
x86_l_ed4:
	/* 0xed4: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_ed9:
	/* 0xed9: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_edd:
	/* 0xedd: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_ee0:
	/* 0xee0: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_ee4:
	/* 0xee4: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_ee8:
	/* 0xee8: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_eec:
	/* 0xeec: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_ef0:
	/* 0xef0: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_ef3:
	/* 0xef3: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_ef7:
	/* 0xef7: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_efb:
	/* 0xefb: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_eff:
	/* 0xeff: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_f03:
	/* 0xf03: ja     eb6 <generic_fentry_filter_arg+0xeb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_eb6;
	}
x86_l_f05:
	/* 0xf05: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_f08:
	/* 0xf08: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_f0b:
	/* 0xf0b: je     ec3 <generic_fentry_filter_arg+0xec3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ec3;
	}
x86_l_f0d:
	/* 0xf0d: jmp    eb6 <generic_fentry_filter_arg+0xeb6> */
	goto x86_l_eb6;
x86_l_f0f:
	/* 0xf0f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_f11:
	/* 0xf11: jns    2616 <generic_fentry_filter_arg+0x2616> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9750ULL;
	}
x86_l_f17:
	/* 0xf17: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f1b:
	/* 0xf1b: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_f20:
	/* 0xf20: jae    f33 <generic_fentry_filter_arg+0xf33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f33;
	}
x86_l_f22:
	/* 0xf22: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_f26:
	/* 0xf26: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_f29:
	/* 0xf29: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_f2d:
	/* 0xf2d: jne    e79 <generic_fentry_filter_arg+0xe79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e79;
	}
x86_l_f33:
	/* 0xf33: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f35:
	/* 0xf35: jmp    261b <generic_fentry_filter_arg+0x261b> */
	return 9755ULL;
x86_l_f3a:
	/* 0xf3a: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f3e:
	/* 0xf3e: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f43:
	/* 0xf43: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f48:
	/* 0xf48: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f4c:
	/* 0xf4c: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_f57:
	/* 0xf57: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f5c:
	/* 0xf5c: mov    rdi,QWORD PTR [rip+0x1bbad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_f63:
	/* 0xf63: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f68:
	/* 0xf68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6a:
	/* 0xf6a: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_f6d:
	/* 0xf6d: je     2eb8 <generic_fentry_filter_arg+0x2eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11960ULL;
	}
x86_l_f73:
	/* 0xf73: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_f78:
	/* 0xf78: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f7b:
	/* 0xf7b: je     2eba <generic_fentry_filter_arg+0x2eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11962ULL;
	}
x86_l_f81:
	/* 0xf81: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_f84:
	/* 0xf84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f89:
	/* 0xf89: mov    rdi,QWORD PTR [rip+0x1bbad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_f90:
	/* 0xf90: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f95:
	/* 0xf95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f97:
	/* 0xf97: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f9a:
	/* 0xf9a: je     2eb8 <generic_fentry_filter_arg+0x2eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11960ULL;
	}
x86_l_fa0:
	/* 0xfa0: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_fa6:
	/* 0xfa6: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_fab:
	/* 0xfab: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_fae:
	/* 0xfae: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_fb5:
	/* 0xfb5: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fb7:
	/* 0xfb7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_fba:
	/* 0xfba: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_fbe:
	/* 0xfbe: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_fc3:
	/* 0xfc3: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_fc5:
	/* 0xfc5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc9:
	/* 0xfc9: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_fcc:
	/* 0xfcc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_fce:
	/* 0xfce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fd3:
	/* 0xfd3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_fd6:
	/* 0xfd6: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_fd9:
	/* 0xfd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fdb:
	/* 0xfdb: jmp    2eae <generic_fentry_filter_arg+0x2eae> */
	return 11950ULL;
x86_l_fe0:
	/* 0xfe0: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_feb:
	/* 0xfeb: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_ff1:
	/* 0xff1: jbe    1569 <generic_fentry_filter_arg+0x1569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 5481ULL;
	}
x86_l_ff7:
	/* 0xff7: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ff9:
	/* 0xff9: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ffe:
	/* 0xffe: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_1002:
	/* 0x1002: jbe    2ed8 <generic_fentry_filter_arg+0x2ed8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11992ULL;
	}
x86_l_1008:
	/* 0x1008: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_100d:
	/* 0x100d: mov    rsi,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1012:
	/* 0x1012: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1017:
	/* 0x1017: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_101a:
	/* 0x101a: je     1025 <generic_fentry_filter_arg+0x1025> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1025;
	}
x86_l_101c:
	/* 0x101c: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_101f:
	/* 0x101f: jne    1b62 <generic_fentry_filter_arg+0x1b62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7010ULL;
	}
x86_l_1025:
	/* 0x1025: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1029:
	/* 0x1029: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_102c:
	/* 0x102c: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_102f:
	/* 0x102f: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_1033:
	/* 0x1033: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1036:
	/* 0x1036: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_1039:
	/* 0x1039: jmp    1b76 <generic_fentry_filter_arg+0x1b76> */
	return 7030ULL;
x86_l_103e:
	/* 0x103e: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1041:
	/* 0x1041: je     13f1 <generic_fentry_filter_arg+0x13f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5105ULL;
	}
x86_l_1047:
	/* 0x1047: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_104a:
	/* 0x104a: je     13e7 <generic_fentry_filter_arg+0x13e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5095ULL;
	}
x86_l_1050:
	/* 0x1050: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1055:
	/* 0x1055: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1058:
	/* 0x1058: je     137e <generic_fentry_filter_arg+0x137e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4990ULL;
	}
x86_l_105e:
	/* 0x105e: jmp    299 <generic_fentry_filter_arg+0x299> */
	return 665ULL;
x86_l_1063:
	/* 0x1063: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1066:
	/* 0x1066: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_106a:
	/* 0x106a: jg     1648 <generic_fentry_filter_arg+0x1648> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5704ULL;
	}
x86_l_1070:
	/* 0x1070: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1073:
	/* 0x1073: je     182f <generic_fentry_filter_arg+0x182f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6191ULL;
	}
x86_l_1079:
	/* 0x1079: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_107e:
	/* 0x107e: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1081:
	/* 0x1081: jne    318c <generic_fentry_filter_arg+0x318c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12684ULL;
	}
x86_l_1087:
	/* 0x1087: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_108c:
	/* 0x108c: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1091:
	/* 0x1091: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1095:
	/* 0x1095: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_10a0:
	/* 0x10a0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10a5:
	/* 0x10a5: mov    rdi,QWORD PTR [rip+0x1bbad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_10ac:
	/* 0x10ac: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_10b1:
	/* 0x10b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b3:
	/* 0x10b3: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_10b6:
	/* 0x10b6: je     317b <generic_fentry_filter_arg+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12667ULL;
	}
x86_l_10bc:
	/* 0x10bc: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_10bf:
	/* 0x10bf: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_10c4:
	/* 0x10c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10c7:
	/* 0x10c7: je     317d <generic_fentry_filter_arg+0x317d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12669ULL;
	}
x86_l_10cd:
	/* 0x10cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10d2:
	/* 0x10d2: mov    rdi,QWORD PTR [rip+0x1bbad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_10d9:
	/* 0x10d9: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10de:
	/* 0x10de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e0:
	/* 0x10e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10e3:
	/* 0x10e3: je     317b <generic_fentry_filter_arg+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12667ULL;
	}
x86_l_10e9:
	/* 0x10e9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10ec:
	/* 0x10ec: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10f1:
	/* 0x10f1: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_10f4:
	/* 0x10f4: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_10f9:
	/* 0x10f9: cmovb  ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_10fc:
	/* 0x10fc: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_10ff:
	/* 0x10ff: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1101:
	/* 0x1101: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1104:
	/* 0x1104: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1107:
	/* 0x1107: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_110c:
	/* 0x110c: sub    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_110f:
	/* 0x110f: lea    eax,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_1112:
	/* 0x1112: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1117:
	/* 0x1117: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_111b:
	/* 0x111b: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1121:
	/* 0x1121: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1124:
	/* 0x1124: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1128:
	/* 0x1128: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_112e:
	/* 0x112e: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1131:
	/* 0x1131: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1135:
	/* 0x1135: lea    ebx,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1138:
	/* 0x1138: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_113b:
	/* 0x113b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_113f:
	/* 0x113f: lea    ebp,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1143:
	/* 0x1143: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1149:
	/* 0x1149: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_114d:
	/* 0x114d: mov    BYTE PTR [rdi-0x3],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1151:
	/* 0x1151: cmp    r10,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R13, X86_WIDTH_64);
x86_l_1154:
	/* 0x1154: je     11a8 <generic_fentry_filter_arg+0x11a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11a8;
	}
x86_l_1156:
	/* 0x1156: lea    ebp,[r11+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_115a:
	/* 0x115a: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1160:
	/* 0x1160: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_1164:
	/* 0x1164: mov    BYTE PTR [rdi-0x2],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1168:
	/* 0x1168: cmp    r8,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R13, X86_WIDTH_64);
x86_l_116b:
	/* 0x116b: je     11a8 <generic_fentry_filter_arg+0x11a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11a8;
	}
x86_l_116d:
	/* 0x116d: lea    ebp,[r9+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1171:
	/* 0x1171: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1177:
	/* 0x1177: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_117b:
	/* 0x117b: mov    BYTE PTR [rdi-0x1],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_117f:
	/* 0x117f: cmp    rdx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1182:
	/* 0x1182: je     11a8 <generic_fentry_filter_arg+0x11a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11a8;
	}
x86_l_1184:
	/* 0x1184: cmp    r13,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_1188:
	/* 0x1188: je     11a8 <generic_fentry_filter_arg+0x11a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11a8;
	}
x86_l_118a:
	/* 0x118a: lea    ebp,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_118e:
	/* 0x118e: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1194:
	/* 0x1194: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_1198:
	/* 0x1198: mov    BYTE PTR [rdi],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_119b:
	/* 0x119b: add    r13,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_119f:
	/* 0x119f: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_11a3:
	/* 0x11a3: cmp    rcx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_11a6:
	/* 0x11a6: jne    113f <generic_fentry_filter_arg+0x113f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_113f;
	}
x86_l_11a8:
	/* 0x11a8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11ad:
	/* 0x11ad: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11b2:
	/* 0x11b2: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11b7:
	/* 0x11b7: jmp    316f <generic_fentry_filter_arg+0x316f> */
	return 12655ULL;
x86_l_11bc:
	/* 0x11bc: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_11bf:
	/* 0x11bf: jne    2272 <generic_fentry_filter_arg+0x2272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8818ULL;
	}
x86_l_11c5:
	/* 0x11c5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c9:
	/* 0x11c9: test   DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11cb:
	/* 0x11cb: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_11d1:
	/* 0x11d1: jmp    2272 <generic_fentry_filter_arg+0x2272> */
	return 8818ULL;
x86_l_11d6:
	/* 0x11d6: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_11db:
	/* 0x11db: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_11df:
	/* 0x11df: jb     1727 <generic_fentry_filter_arg+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5927ULL;
	}
x86_l_11e5:
	/* 0x11e5: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_11ef:
	/* 0x11ef: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_11f3:
	/* 0x11f3: jae    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 262ULL;
	}
x86_l_11f9:
	/* 0x11f9: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_11fc:
	/* 0x11fc: jne    1e52 <generic_fentry_filter_arg+0x1e52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7762ULL;
	}
x86_l_1202:
	/* 0x1202: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1206:
	/* 0x1206: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1209:
	/* 0x1209: jmp    123e <generic_fentry_filter_arg+0x123e> */
	goto x86_l_123e;
x86_l_120b:
	/* 0x120b: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_1210:
	/* 0x1210: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1214:
	/* 0x1214: jb     1766 <generic_fentry_filter_arg+0x1766> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5990ULL;
	}
x86_l_121a:
	/* 0x121a: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_1224:
	/* 0x1224: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1228:
	/* 0x1228: jae    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 262ULL;
	}
x86_l_122e:
	/* 0x122e: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_1231:
	/* 0x1231: jne    1e60 <generic_fentry_filter_arg+0x1e60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7776ULL;
	}
x86_l_1237:
	/* 0x1237: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_123b:
	/* 0x123b: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_123e:
	/* 0x123e: cmp    DWORD PTR [r12+0x10],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1243:
	/* 0x1243: ja     1250 <generic_fentry_filter_arg+0x1250> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1250;
	}
x86_l_1245:
	/* 0x1245: cmp    DWORD PTR [r12+0x14],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_124a:
	/* 0x124a: jae    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 687ULL;
	}
x86_l_1250:
	/* 0x1250: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1255:
	/* 0x1255: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1258:
	/* 0x1258: jb     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 262ULL;
	}
x86_l_125e:
	/* 0x125e: cmp    DWORD PTR [r12+0x18],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1263:
	/* 0x1263: ja     1270 <generic_fentry_filter_arg+0x1270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1270;
	}
x86_l_1265:
	/* 0x1265: cmp    DWORD PTR [r12+0x1c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_126a:
	/* 0x126a: jae    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 687ULL;
	}
x86_l_1270:
	/* 0x1270: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_1273:
	/* 0x1273: jb     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 262ULL;
	}
x86_l_1279:
	/* 0x1279: cmp    DWORD PTR [r12+0x20],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_127e:
	/* 0x127e: ja     128b <generic_fentry_filter_arg+0x128b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_128b;
	}
x86_l_1280:
	/* 0x1280: cmp    DWORD PTR [r12+0x24],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1285:
	/* 0x1285: jae    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 687ULL;
	}
x86_l_128b:
	/* 0x128b: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_128e:
	/* 0x128e: jb     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 262ULL;
	}
x86_l_1294:
	/* 0x1294: cmp    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1299:
	/* 0x1299: ja     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 262ULL;
	}
x86_l_129f:
	/* 0x129f: cmp    DWORD PTR [r12+0x2c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_12a4:
	/* 0x12a4: jae    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 687ULL;
	}
x86_l_12aa:
	/* 0x12aa: jmp    106 <generic_fentry_filter_arg+0x106> */
	return 262ULL;
x86_l_12af:
	/* 0x12af: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_12b2:
	/* 0x12b2: je     12bd <generic_fentry_filter_arg+0x12bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12bd;
	}
x86_l_12b4:
	/* 0x12b4: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_12b7:
	/* 0x12b7: jne    1c3d <generic_fentry_filter_arg+0x1c3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7229ULL;
	}
x86_l_12bd:
	/* 0x12bd: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c1:
	/* 0x12c1: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c4:
	/* 0x12c4: jg     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 687ULL;
	}
x86_l_12ca:
	/* 0x12ca: jmp    1c59 <generic_fentry_filter_arg+0x1c59> */
	return 7257ULL;
x86_l_12cf:
	/* 0x12cf: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12d2:
	/* 0x12d2: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_12d7:
	/* 0x12d7: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12dc:
	/* 0x12dc: ja     1971 <generic_fentry_filter_arg+0x1971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6513ULL;
	}
x86_l_12e2:
	/* 0x12e2: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_12e6:
	/* 0x12e6: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_12ec:
	/* 0x12ec: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_12ef:
	/* 0x12ef: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_12f2:
	/* 0x12f2: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_12f5:
	/* 0x12f5: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_12f7:
	/* 0x12f7: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_12f9:
	/* 0x12f9: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_12fc:
	/* 0x12fc: je     1304 <generic_fentry_filter_arg+0x1304> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1304;
	}
x86_l_12fe:
	/* 0x12fe: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1300:
	/* 0x1300: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1302:
	/* 0x1302: je     131a <generic_fentry_filter_arg+0x131a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131a;
	}
x86_l_1304:
	/* 0x1304: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1307:
	/* 0x1307: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1309:
	/* 0x1309: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_130b:
	/* 0x130b: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_130d:
	/* 0x130d: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1310:
	/* 0x1310: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1314:
	/* 0x1314: ja     1986 <generic_fentry_filter_arg+0x1986> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6534ULL;
	}
x86_l_131a:
	/* 0x131a: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_131d:
	/* 0x131d: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1323:
	/* 0x1323: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1326:
	/* 0x1326: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1328:
	/* 0x1328: jmp    1996 <generic_fentry_filter_arg+0x1996> */
	return 6550ULL;
x86_l_132d:
	/* 0x132d: mov    esi,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1332:
	/* 0x1332: mov    eax,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1337:
	/* 0x1337: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_133a:
	/* 0x133a: ja     20fe <generic_fentry_filter_arg+0x20fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8446ULL;
	}
x86_l_1340:
	/* 0x1340: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1345:
	/* 0x1345: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1348:
	/* 0x1348: jae    20fe <generic_fentry_filter_arg+0x20fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8446ULL;
	}
x86_l_134e:
	/* 0x134e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1352:
	/* 0x1352: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1354:
	/* 0x1354: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1356:
	/* 0x1356: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
	return 4954ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4954ULL: goto x86_l_135a;
	case 4956ULL: goto x86_l_135c;
	case 4959ULL: goto x86_l_135f;
	case 4964ULL: goto x86_l_1364;
	case 4967ULL: goto x86_l_1367;
	case 4969ULL: goto x86_l_1369;
	case 4974ULL: goto x86_l_136e;
	case 4977ULL: goto x86_l_1371;
	case 4983ULL: goto x86_l_1377;
	case 4988ULL: goto x86_l_137c;
	case 4990ULL: goto x86_l_137e;
	case 4995ULL: goto x86_l_1383;
	case 4997ULL: goto x86_l_1385;
	case 4999ULL: goto x86_l_1387;
	case 5002ULL: goto x86_l_138a;
	case 5004ULL: goto x86_l_138c;
	case 5007ULL: goto x86_l_138f;
	case 5009ULL: goto x86_l_1391;
	case 5012ULL: goto x86_l_1394;
	case 5015ULL: goto x86_l_1397;
	case 5021ULL: goto x86_l_139d;
	case 5024ULL: goto x86_l_13a0;
	case 5027ULL: goto x86_l_13a3;
	case 5033ULL: goto x86_l_13a9;
	case 5036ULL: goto x86_l_13ac;
	case 5042ULL: goto x86_l_13b2;
	case 5047ULL: goto x86_l_13b7;
	case 5050ULL: goto x86_l_13ba;
	case 5056ULL: goto x86_l_13c0;
	case 5061ULL: goto x86_l_13c5;
	case 5064ULL: goto x86_l_13c8;
	case 5070ULL: goto x86_l_13ce;
	case 5073ULL: goto x86_l_13d1;
	case 5079ULL: goto x86_l_13d7;
	case 5082ULL: goto x86_l_13da;
	case 5088ULL: goto x86_l_13e0;
	case 5090ULL: goto x86_l_13e2;
	case 5095ULL: goto x86_l_13e7;
	case 5099ULL: goto x86_l_13eb;
	case 5103ULL: goto x86_l_13ef;
	case 5105ULL: goto x86_l_13f1;
	case 5108ULL: goto x86_l_13f4;
	case 5112ULL: goto x86_l_13f8;
	case 5115ULL: goto x86_l_13fb;
	case 5119ULL: goto x86_l_13ff;
	case 5122ULL: goto x86_l_1402;
	case 5124ULL: goto x86_l_1404;
	case 5127ULL: goto x86_l_1407;
	case 5129ULL: goto x86_l_1409;
	case 5132ULL: goto x86_l_140c;
	case 5138ULL: goto x86_l_1412;
	case 5143ULL: goto x86_l_1417;
	case 5146ULL: goto x86_l_141a;
	case 5152ULL: goto x86_l_1420;
	case 5157ULL: goto x86_l_1425;
	case 5160ULL: goto x86_l_1428;
	case 5166ULL: goto x86_l_142e;
	case 5171ULL: goto x86_l_1433;
	case 5174ULL: goto x86_l_1436;
	case 5180ULL: goto x86_l_143c;
	case 5184ULL: goto x86_l_1440;
	case 5187ULL: goto x86_l_1443;
	case 5193ULL: goto x86_l_1449;
	case 5196ULL: goto x86_l_144c;
	case 5202ULL: goto x86_l_1452;
	case 5205ULL: goto x86_l_1455;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5231ULL: goto x86_l_146f;
	case 5236ULL: goto x86_l_1474;
	case 5238ULL: goto x86_l_1476;
	case 5241ULL: goto x86_l_1479;
	case 5247ULL: goto x86_l_147f;
	case 5258ULL: goto x86_l_148a;
	case 5266ULL: goto x86_l_1492;
	case 5271ULL: goto x86_l_1497;
	case 5274ULL: goto x86_l_149a;
	case 5280ULL: goto x86_l_14a0;
	case 5285ULL: goto x86_l_14a5;
	case 5288ULL: goto x86_l_14a8;
	case 5294ULL: goto x86_l_14ae;
	case 5298ULL: goto x86_l_14b2;
	case 5300ULL: goto x86_l_14b4;
	case 5306ULL: goto x86_l_14ba;
	case 5311ULL: goto x86_l_14bf;
	case 5315ULL: goto x86_l_14c3;
	case 5317ULL: goto x86_l_14c5;
	case 5320ULL: goto x86_l_14c8;
	case 5323ULL: goto x86_l_14cb;
	case 5328ULL: goto x86_l_14d0;
	case 5332ULL: goto x86_l_14d4;
	case 5337ULL: goto x86_l_14d9;
	case 5344ULL: goto x86_l_14e0;
	case 5349ULL: goto x86_l_14e5;
	case 5351ULL: goto x86_l_14e7;
	case 5354ULL: goto x86_l_14ea;
	case 5360ULL: goto x86_l_14f0;
	case 5363ULL: goto x86_l_14f3;
	case 5368ULL: goto x86_l_14f8;
	case 5371ULL: goto x86_l_14fb;
	case 5376ULL: goto x86_l_1500;
	case 5378ULL: goto x86_l_1502;
	case 5382ULL: goto x86_l_1506;
	case 5384ULL: goto x86_l_1508;
	case 5386ULL: goto x86_l_150a;
	case 5389ULL: goto x86_l_150d;
	case 5392ULL: goto x86_l_1510;
	case 5395ULL: goto x86_l_1513;
	case 5397ULL: goto x86_l_1515;
	case 5399ULL: goto x86_l_1517;
	case 5403ULL: goto x86_l_151b;
	case 5406ULL: goto x86_l_151e;
	case 5408ULL: goto x86_l_1520;
	case 5412ULL: goto x86_l_1524;
	case 5415ULL: goto x86_l_1527;
	case 5417ULL: goto x86_l_1529;
	case 5421ULL: goto x86_l_152d;
	case 5423ULL: goto x86_l_152f;
	case 5427ULL: goto x86_l_1533;
	case 5431ULL: goto x86_l_1537;
	case 5434ULL: goto x86_l_153a;
	case 5436ULL: goto x86_l_153c;
	case 5438ULL: goto x86_l_153e;
	case 5440ULL: goto x86_l_1540;
	case 5446ULL: goto x86_l_1546;
	case 5450ULL: goto x86_l_154a;
	case 5455ULL: goto x86_l_154f;
	case 5457ULL: goto x86_l_1551;
	case 5461ULL: goto x86_l_1555;
	case 5464ULL: goto x86_l_1558;
	case 5468ULL: goto x86_l_155c;
	case 5474ULL: goto x86_l_1562;
	case 5476ULL: goto x86_l_1564;
	case 5481ULL: goto x86_l_1569;
	case 5484ULL: goto x86_l_156c;
	case 5489ULL: goto x86_l_1571;
	case 5494ULL: goto x86_l_1576;
	case 5500ULL: goto x86_l_157c;
	case 5504ULL: goto x86_l_1580;
	case 5510ULL: goto x86_l_1586;
	case 5513ULL: goto x86_l_1589;
	case 5516ULL: goto x86_l_158c;
	case 5519ULL: goto x86_l_158f;
	case 5521ULL: goto x86_l_1591;
	case 5523ULL: goto x86_l_1593;
	case 5526ULL: goto x86_l_1596;
	case 5528ULL: goto x86_l_1598;
	case 5530ULL: goto x86_l_159a;
	case 5532ULL: goto x86_l_159c;
	case 5534ULL: goto x86_l_159e;
	case 5537ULL: goto x86_l_15a1;
	case 5539ULL: goto x86_l_15a3;
	case 5541ULL: goto x86_l_15a5;
	case 5543ULL: goto x86_l_15a7;
	case 5546ULL: goto x86_l_15aa;
	case 5550ULL: goto x86_l_15ae;
	case 5556ULL: goto x86_l_15b4;
	case 5560ULL: goto x86_l_15b8;
	case 5566ULL: goto x86_l_15be;
	case 5569ULL: goto x86_l_15c1;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5579ULL: goto x86_l_15cb;
	case 5582ULL: goto x86_l_15ce;
	case 5588ULL: goto x86_l_15d4;
	case 5591ULL: goto x86_l_15d7;
	case 5597ULL: goto x86_l_15dd;
	case 5601ULL: goto x86_l_15e1;
	case 5606ULL: goto x86_l_15e6;
	case 5613ULL: goto x86_l_15ed;
	case 5618ULL: goto x86_l_15f2;
	case 5620ULL: goto x86_l_15f4;
	case 5623ULL: goto x86_l_15f7;
	case 5629ULL: goto x86_l_15fd;
	case 5633ULL: goto x86_l_1601;
	case 5641ULL: goto x86_l_1609;
	case 5646ULL: goto x86_l_160e;
	case 5649ULL: goto x86_l_1611;
	case 5654ULL: goto x86_l_1616;
	case 5656ULL: goto x86_l_1618;
	case 5661ULL: goto x86_l_161d;
	case 5663ULL: goto x86_l_161f;
	case 5666ULL: goto x86_l_1622;
	case 5672ULL: goto x86_l_1628;
	case 5677ULL: goto x86_l_162d;
	case 5680ULL: goto x86_l_1630;
	case 5685ULL: goto x86_l_1635;
	case 5690ULL: goto x86_l_163a;
	case 5693ULL: goto x86_l_163d;
	case 5699ULL: goto x86_l_1643;
	case 5704ULL: goto x86_l_1648;
	case 5707ULL: goto x86_l_164b;
	case 5713ULL: goto x86_l_1651;
	case 5718ULL: goto x86_l_1656;
	case 5721ULL: goto x86_l_1659;
	case 5727ULL: goto x86_l_165f;
	case 5733ULL: goto x86_l_1665;
	case 5736ULL: goto x86_l_1668;
	case 5740ULL: goto x86_l_166c;
	case 5744ULL: goto x86_l_1670;
	case 5749ULL: goto x86_l_1675;
	case 5756ULL: goto x86_l_167c;
	case 5761ULL: goto x86_l_1681;
	case 5763ULL: goto x86_l_1683;
	case 5766ULL: goto x86_l_1686;
	case 5772ULL: goto x86_l_168c;
	case 5776ULL: goto x86_l_1690;
	case 5779ULL: goto x86_l_1693;
	case 5782ULL: goto x86_l_1696;
	case 5787ULL: goto x86_l_169b;
	case 5789ULL: goto x86_l_169d;
	case 5795ULL: goto x86_l_16a3;
	case 5799ULL: goto x86_l_16a7;
	case 5803ULL: goto x86_l_16ab;
	case 5808ULL: goto x86_l_16b0;
	case 5813ULL: goto x86_l_16b5;
	case 5818ULL: goto x86_l_16ba;
	case 5821ULL: goto x86_l_16bd;
	case 5827ULL: goto x86_l_16c3;
	case 5832ULL: goto x86_l_16c8;
	case 5839ULL: goto x86_l_16cf;
	case 5844ULL: goto x86_l_16d4;
	case 5846ULL: goto x86_l_16d6;
	case 5851ULL: goto x86_l_16db;
	case 5854ULL: goto x86_l_16de;
	case 5860ULL: goto x86_l_16e4;
	case 5863ULL: goto x86_l_16e7;
	case 5869ULL: goto x86_l_16ed;
	case 5873ULL: goto x86_l_16f1;
	case 5876ULL: goto x86_l_16f4;
	case 5878ULL: goto x86_l_16f6;
	case 5884ULL: goto x86_l_16fc;
	case 5889ULL: goto x86_l_1701;
	case 5892ULL: goto x86_l_1704;
	case 5898ULL: goto x86_l_170a;
	case 5901ULL: goto x86_l_170d;
	case 5907ULL: goto x86_l_1713;
	case 5911ULL: goto x86_l_1717;
	case 5914ULL: goto x86_l_171a;
	case 5916ULL: goto x86_l_171c;
	case 5922ULL: goto x86_l_1722;
	case 5927ULL: goto x86_l_1727;
	case 5930ULL: goto x86_l_172a;
	case 5936ULL: goto x86_l_1730;
	case 5943ULL: goto x86_l_1737;
	case 5948ULL: goto x86_l_173c;
	case 5955ULL: goto x86_l_1743;
	case 5960ULL: goto x86_l_1748;
	case 5962ULL: goto x86_l_174a;
	case 5965ULL: goto x86_l_174d;
	case 5971ULL: goto x86_l_1753;
	case 5975ULL: goto x86_l_1757;
	case 5978ULL: goto x86_l_175a;
	case 5983ULL: goto x86_l_175f;
	case 5988ULL: goto x86_l_1764;
	case 5990ULL: goto x86_l_1766;
	case 5993ULL: goto x86_l_1769;
	case 5999ULL: goto x86_l_176f;
	case 6006ULL: goto x86_l_1776;
	case 6011ULL: goto x86_l_177b;
	case 6018ULL: goto x86_l_1782;
	case 6023ULL: goto x86_l_1787;
	case 6025ULL: goto x86_l_1789;
	case 6028ULL: goto x86_l_178c;
	case 6030ULL: goto x86_l_178e;
	case 6034ULL: goto x86_l_1792;
	case 6037ULL: goto x86_l_1795;
	case 6042ULL: goto x86_l_179a;
	case 6047ULL: goto x86_l_179f;
	case 6050ULL: goto x86_l_17a2;
	case 6055ULL: goto x86_l_17a7;
	case 6057ULL: goto x86_l_17a9;
	case 6062ULL: goto x86_l_17ae;
	case 6064ULL: goto x86_l_17b0;
	case 6067ULL: goto x86_l_17b3;
	case 6073ULL: goto x86_l_17b9;
	case 6078ULL: goto x86_l_17be;
	case 6081ULL: goto x86_l_17c1;
	case 6086ULL: goto x86_l_17c6;
	case 6091ULL: goto x86_l_17cb;
	case 6094ULL: goto x86_l_17ce;
	case 6096ULL: goto x86_l_17d0;
	case 6099ULL: goto x86_l_17d3;
	case 6102ULL: goto x86_l_17d6;
	case 6105ULL: goto x86_l_17d9;
	case 6110ULL: goto x86_l_17de;
	case 6112ULL: goto x86_l_17e0;
	case 6117ULL: goto x86_l_17e5;
	case 6122ULL: goto x86_l_17ea;
	case 6125ULL: goto x86_l_17ed;
	case 6130ULL: goto x86_l_17f2;
	case 6135ULL: goto x86_l_17f7;
	case 6138ULL: goto x86_l_17fa;
	case 6140ULL: goto x86_l_17fc;
	case 6143ULL: goto x86_l_17ff;
	case 6146ULL: goto x86_l_1802;
	case 6149ULL: goto x86_l_1805;
	case 6154ULL: goto x86_l_180a;
	case 6157ULL: goto x86_l_180d;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6173ULL: goto x86_l_181d;
	case 6176ULL: goto x86_l_1820;
	case 6181ULL: goto x86_l_1825;
	case 6183ULL: goto x86_l_1827;
	case 6186ULL: goto x86_l_182a;
	case 6191ULL: goto x86_l_182f;
	case 6196ULL: goto x86_l_1834;
	case 6201ULL: goto x86_l_1839;
	case 6205ULL: goto x86_l_183d;
	case 6216ULL: goto x86_l_1848;
	case 6221ULL: goto x86_l_184d;
	case 6228ULL: goto x86_l_1854;
	case 6233ULL: goto x86_l_1859;
	case 6235ULL: goto x86_l_185b;
	case 6238ULL: goto x86_l_185e;
	case 6244ULL: goto x86_l_1864;
	case 6247ULL: goto x86_l_1867;
	case 6252ULL: goto x86_l_186c;
	case 6255ULL: goto x86_l_186f;
	case 6261ULL: goto x86_l_1875;
	case 6266ULL: goto x86_l_187a;
	case 6273ULL: goto x86_l_1881;
	case 6278ULL: goto x86_l_1886;
	case 6280ULL: goto x86_l_1888;
	case 6283ULL: goto x86_l_188b;
	case 6289ULL: goto x86_l_1891;
	case 6295ULL: goto x86_l_1897;
	case 6300ULL: goto x86_l_189c;
	case 6303ULL: goto x86_l_189f;
	case 6310ULL: goto x86_l_18a6;
	case 6312ULL: goto x86_l_18a8;
	case 6315ULL: goto x86_l_18ab;
	case 6319ULL: goto x86_l_18af;
	case 6324ULL: goto x86_l_18b4;
	case 6328ULL: goto x86_l_18b8;
	case 6331ULL: goto x86_l_18bb;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6341ULL: goto x86_l_18c5;
	case 6344ULL: goto x86_l_18c8;
	case 6346ULL: goto x86_l_18ca;
	case 6351ULL: goto x86_l_18cf;
	case 6362ULL: goto x86_l_18da;
	case 6368ULL: goto x86_l_18e0;
	case 6374ULL: goto x86_l_18e6;
	case 6376ULL: goto x86_l_18e8;
	case 6381ULL: goto x86_l_18ed;
	case 6383ULL: goto x86_l_18ef;
	case 6388ULL: goto x86_l_18f4;
	case 6393ULL: goto x86_l_18f9;
	case 6396ULL: goto x86_l_18fc;
	case 6401ULL: goto x86_l_1901;
	case 6404ULL: goto x86_l_1904;
	case 6410ULL: goto x86_l_190a;
	case 6415ULL: goto x86_l_190f;
	case 6418ULL: goto x86_l_1912;
	case 6420ULL: goto x86_l_1914;
	case 6429ULL: goto x86_l_191d;
	case 6435ULL: goto x86_l_1923;
	case 6439ULL: goto x86_l_1927;
	case 6442ULL: goto x86_l_192a;
	case 6450ULL: goto x86_l_1932;
	case 6455ULL: goto x86_l_1937;
	case 6457ULL: goto x86_l_1939;
	case 6467ULL: goto x86_l_1943;
	case 6470ULL: goto x86_l_1946;
	case 6475ULL: goto x86_l_194b;
	case 6479ULL: goto x86_l_194f;
	case 6481ULL: goto x86_l_1951;
	case 6486ULL: goto x86_l_1956;
	case 6489ULL: goto x86_l_1959;
	case 6494ULL: goto x86_l_195e;
	case 6498ULL: goto x86_l_1962;
	case 6500ULL: goto x86_l_1964;
	case 6505ULL: goto x86_l_1969;
	case 6508ULL: goto x86_l_196c;
	case 6513ULL: goto x86_l_1971;
	case 6516ULL: goto x86_l_1974;
	case 6521ULL: goto x86_l_1979;
	case 6526ULL: goto x86_l_197e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_135a:
	/* 0x135a: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_135c:
	/* 0x135c: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_135f:
	/* 0x135f: jmp    210f <generic_fentry_filter_arg+0x210f> */
	return 8463ULL;
x86_l_1364:
	/* 0x1364: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_1367:
	/* 0x1367: je     137e <generic_fentry_filter_arg+0x137e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_137e;
	}
x86_l_1369:
	/* 0x1369: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_136e:
	/* 0x136e: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1371:
	/* 0x1371: jne    299 <generic_fentry_filter_arg+0x299> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 665ULL;
	}
x86_l_1377:
	/* 0x1377: movzx  r13d,WORD PTR [rsi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_137c:
	/* 0x137c: jmp    1383 <generic_fentry_filter_arg+0x1383> */
	goto x86_l_1383;
x86_l_137e:
	/* 0x137e: movzx  r13d,WORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1383:
	/* 0x1383: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1385:
	/* 0x1385: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1387:
	/* 0x1387: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_138a:
	/* 0x138a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_138c:
	/* 0x138c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_138f:
	/* 0x138f: jg     1409 <generic_fentry_filter_arg+0x1409> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1409;
	}
x86_l_1391:
	/* 0x1391: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_1394:
	/* 0x1394: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1397:
	/* 0x1397: jb     143c <generic_fentry_filter_arg+0x143c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_143c;
	}
x86_l_139d:
	/* 0x139d: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_13a0:
	/* 0x13a0: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_13a3:
	/* 0x13a3: jb     15d4 <generic_fentry_filter_arg+0x15d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_15d4;
	}
x86_l_13a9:
	/* 0x13a9: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_13ac:
	/* 0x13ac: je     1bb6 <generic_fentry_filter_arg+0x1bb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7094ULL;
	}
x86_l_13b2:
	/* 0x13b2: jmp    299 <generic_fentry_filter_arg+0x299> */
	return 665ULL;
x86_l_13b7:
	/* 0x13b7: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_13ba:
	/* 0x13ba: je     1bb2 <generic_fentry_filter_arg+0x1bb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7090ULL;
	}
x86_l_13c0:
	/* 0x13c0: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_13c5:
	/* 0x13c5: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_13c8:
	/* 0x13c8: jne    299 <generic_fentry_filter_arg+0x299> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 665ULL;
	}
x86_l_13ce:
	/* 0x13ce: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_13d1:
	/* 0x13d1: jne    21ed <generic_fentry_filter_arg+0x21ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8685ULL;
	}
x86_l_13d7:
	/* 0x13d7: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_13da:
	/* 0x13da: jne    21f9 <generic_fentry_filter_arg+0x21f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8697ULL;
	}
x86_l_13e0:
	/* 0x13e0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13e2:
	/* 0x13e2: jmp    220b <generic_fentry_filter_arg+0x220b> */
	return 8715ULL;
x86_l_13e7:
	/* 0x13e7: mov    rdx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13eb:
	/* 0x13eb: mov    r8,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13ef:
	/* 0x13ef: jmp    13f8 <generic_fentry_filter_arg+0x13f8> */
	goto x86_l_13f8;
x86_l_13f1:
	/* 0x13f1: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13f4:
	/* 0x13f4: mov    r8,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13f8:
	/* 0x13f8: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_13fb:
	/* 0x13fb: shr    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_13ff:
	/* 0x13ff: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1402:
	/* 0x1402: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1404:
	/* 0x1404: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1407:
	/* 0x1407: jle    1391 <generic_fentry_filter_arg+0x1391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1391;
	}
x86_l_1409:
	/* 0x1409: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_140c:
	/* 0x140c: ja     15c8 <generic_fentry_filter_arg+0x15c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15c8;
	}
x86_l_1412:
	/* 0x1412: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_1417:
	/* 0x1417: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_141a:
	/* 0x141a: jb     194b <generic_fentry_filter_arg+0x194b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_194b;
	}
x86_l_1420:
	/* 0x1420: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_1425:
	/* 0x1425: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1428:
	/* 0x1428: jb     195e <generic_fentry_filter_arg+0x195e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_195e;
	}
x86_l_142e:
	/* 0x142e: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_1433:
	/* 0x1433: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1436:
	/* 0x1436: jae    15c8 <generic_fentry_filter_arg+0x15c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_15c8;
	}
x86_l_143c:
	/* 0x143c: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1440:
	/* 0x1440: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1443:
	/* 0x1443: je     1a60 <generic_fentry_filter_arg+0x1a60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6752ULL;
	}
x86_l_1449:
	/* 0x1449: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_144c:
	/* 0x144c: jne    1b01 <generic_fentry_filter_arg+0x1b01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6913ULL;
	}
x86_l_1452:
	/* 0x1452: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_1455:
	/* 0x1455: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_145a:
	/* 0x145a: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_145f:
	/* 0x145f: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1463:
	/* 0x1463: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1468:
	/* 0x1468: mov    rdi,QWORD PTR [rip+0x1bbad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_146f:
	/* 0x146f: lea    rsi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1474:
	/* 0x1474: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1476:
	/* 0x1476: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1479:
	/* 0x1479: je     1d30 <generic_fentry_filter_arg+0x1d30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7472ULL;
	}
x86_l_147f:
	/* 0x147f: mov    DWORD PTR [rsp+0x80],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813920ULL);
x86_l_148a:
	/* 0x148a: mov    DWORD PTR [rsp+0x84],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_1492:
	/* 0x1492: jmp    1abc <generic_fentry_filter_arg+0x1abc> */
	return 6844ULL;
x86_l_1497:
	/* 0x1497: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_149a:
	/* 0x149a: ja     2258 <generic_fentry_filter_arg+0x2258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8792ULL;
	}
x86_l_14a0:
	/* 0x14a0: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_14a5:
	/* 0x14a5: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_14a8:
	/* 0x14a8: jae    2258 <generic_fentry_filter_arg+0x2258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8792ULL;
	}
x86_l_14ae:
	/* 0x14ae: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b2:
	/* 0x14b2: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b4:
	/* 0x14b4: jg     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 687ULL;
	}
x86_l_14ba:
	/* 0x14ba: jmp    2272 <generic_fentry_filter_arg+0x2272> */
	return 8818ULL;
x86_l_14bf:
	/* 0x14bf: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c3:
	/* 0x14c3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c5:
	/* 0x14c5: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c8:
	/* 0x14c8: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_14cb:
	/* 0x14cb: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_14d0:
	/* 0x14d0: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_14d4:
	/* 0x14d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14d9:
	/* 0x14d9: mov    rdi,QWORD PTR [rip+0x1bbad] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_14e0:
	/* 0x14e0: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_14e5:
	/* 0x14e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e7:
	/* 0x14e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14ea:
	/* 0x14ea: je     232c <generic_fentry_filter_arg+0x232c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9004ULL;
	}
x86_l_14f0:
	/* 0x14f0: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_14f3:
	/* 0x14f3: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14f8:
	/* 0x14f8: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_14fb:
	/* 0x14fb: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1500:
	/* 0x1500: je     1546 <generic_fentry_filter_arg+0x1546> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1546;
	}
x86_l_1502:
	/* 0x1502: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1506:
	/* 0x1506: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1508:
	/* 0x1508: jmp    1515 <generic_fentry_filter_arg+0x1515> */
	goto x86_l_1515;
x86_l_150a:
	/* 0x150a: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_150d:
	/* 0x150d: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1510:
	/* 0x1510: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1513:
	/* 0x1513: je     1546 <generic_fentry_filter_arg+0x1546> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1546;
	}
x86_l_1515:
	/* 0x1515: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1517:
	/* 0x1517: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_151b:
	/* 0x151b: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_151e:
	/* 0x151e: jae    150a <generic_fentry_filter_arg+0x150a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_150a;
	}
x86_l_1520:
	/* 0x1520: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1524:
	/* 0x1524: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_1527:
	/* 0x1527: je     153e <generic_fentry_filter_arg+0x153e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_153e;
	}
x86_l_1529:
	/* 0x1529: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_152d:
	/* 0x152d: ja     150a <generic_fentry_filter_arg+0x150a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_150a;
	}
x86_l_152f:
	/* 0x152f: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1533:
	/* 0x1533: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1537:
	/* 0x1537: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_153a:
	/* 0x153a: je     1517 <generic_fentry_filter_arg+0x1517> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1517;
	}
x86_l_153c:
	/* 0x153c: jmp    150a <generic_fentry_filter_arg+0x150a> */
	goto x86_l_150a;
x86_l_153e:
	/* 0x153e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1540:
	/* 0x1540: jns    25f3 <generic_fentry_filter_arg+0x25f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9715ULL;
	}
x86_l_1546:
	/* 0x1546: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_154a:
	/* 0x154a: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_154f:
	/* 0x154f: jae    1562 <generic_fentry_filter_arg+0x1562> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1562;
	}
x86_l_1551:
	/* 0x1551: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1555:
	/* 0x1555: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1558:
	/* 0x1558: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_155c:
	/* 0x155c: jne    14c8 <generic_fentry_filter_arg+0x14c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14c8;
	}
x86_l_1562:
	/* 0x1562: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1564:
	/* 0x1564: jmp    25f8 <generic_fentry_filter_arg+0x25f8> */
	return 9720ULL;
x86_l_1569:
	/* 0x1569: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_156c:
	/* 0x156c: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1571:
	/* 0x1571: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1576:
	/* 0x1576: ja     1d40 <generic_fentry_filter_arg+0x1d40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7488ULL;
	}
x86_l_157c:
	/* 0x157c: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1580:
	/* 0x1580: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1586:
	/* 0x1586: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1589:
	/* 0x1589: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_158c:
	/* 0x158c: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_158f:
	/* 0x158f: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1591:
	/* 0x1591: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1593:
	/* 0x1593: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1596:
	/* 0x1596: je     159e <generic_fentry_filter_arg+0x159e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_159e;
	}
x86_l_1598:
	/* 0x1598: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_159a:
	/* 0x159a: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_159c:
	/* 0x159c: je     15b4 <generic_fentry_filter_arg+0x15b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15b4;
	}
x86_l_159e:
	/* 0x159e: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_15a1:
	/* 0x15a1: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_15a3:
	/* 0x15a3: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_15a5:
	/* 0x15a5: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_15a7:
	/* 0x15a7: add    esi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_15aa:
	/* 0x15aa: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_15ae:
	/* 0x15ae: ja     1d55 <generic_fentry_filter_arg+0x1d55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7509ULL;
	}
x86_l_15b4:
	/* 0x15b4: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_15b8:
	/* 0x15b8: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_15be:
	/* 0x15be: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_15c1:
	/* 0x15c1: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_15c3:
	/* 0x15c3: jmp    1d65 <generic_fentry_filter_arg+0x1d65> */
	return 7525ULL;
x86_l_15c8:
	/* 0x15c8: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_15cb:
	/* 0x15cb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15ce:
	/* 0x15ce: jae    299 <generic_fentry_filter_arg+0x299> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 665ULL;
	}
x86_l_15d4:
	/* 0x15d4: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_15d7:
	/* 0x15d7: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_15dd:
	/* 0x15dd: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_15e1:
	/* 0x15e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15e6:
	/* 0x15e6: mov    rdi,QWORD PTR [rip+0x1bbb9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_15ed:
	/* 0x15ed: lea    rsi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_15f2:
	/* 0x15f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f4:
	/* 0x15f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15f7:
	/* 0x15f7: je     18ed <generic_fentry_filter_arg+0x18ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18ed;
	}
x86_l_15fd:
	/* 0x15fd: movzx  ecx,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1601:
	/* 0x1601: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1609:
	/* 0x1609: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_160e:
	/* 0x160e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1611:
	/* 0x1611: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1616:
	/* 0x1616: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1618:
	/* 0x1618: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_161d:
	/* 0x161d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_161f:
	/* 0x161f: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1622:
	/* 0x1622: ja     2c02 <generic_fentry_filter_arg+0x2c02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11266ULL;
	}
x86_l_1628:
	/* 0x1628: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_162d:
	/* 0x162d: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1630:
	/* 0x1630: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1635:
	/* 0x1635: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_163a:
	/* 0x163a: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_163d:
	/* 0x163d: jb     290 <generic_fentry_filter_arg+0x290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 656ULL;
	}
x86_l_1643:
	/* 0x1643: jmp    1c24 <generic_fentry_filter_arg+0x1c24> */
	return 7204ULL;
x86_l_1648:
	/* 0x1648: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_164b:
	/* 0x164b: je     1ee4 <generic_fentry_filter_arg+0x1ee4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7908ULL;
	}
x86_l_1651:
	/* 0x1651: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1656:
	/* 0x1656: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_1659:
	/* 0x1659: jne    318c <generic_fentry_filter_arg+0x318c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12684ULL;
	}
x86_l_165f:
	/* 0x165f: mov    r13d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16ULL);
x86_l_1665:
	/* 0x1665: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_1668:
	/* 0x1668: mov    eax,DWORD PTR [r12+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_166c:
	/* 0x166c: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1670:
	/* 0x1670: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1675:
	/* 0x1675: mov    rdi,QWORD PTR [rip+0x1bbb9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_167c:
	/* 0x167c: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1681:
	/* 0x1681: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1683:
	/* 0x1683: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1686:
	/* 0x1686: je     2901 <generic_fentry_filter_arg+0x2901> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10497ULL;
	}
x86_l_168c:
	/* 0x168c: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1690:
	/* 0x1690: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1693:
	/* 0x1693: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1696:
	/* 0x1696: call   0 <generic_fentry_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 5787ULL);
	__x86_sim_call_depth++;
	return 12860ULL;
x86_l_169b:
	/* 0x169b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_169d:
	/* 0x169d: jns    2905 <generic_fentry_filter_arg+0x2905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10501ULL;
	}
x86_l_16a3:
	/* 0x16a3: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_16a7:
	/* 0x16a7: lea    eax,[r13-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_16ab:
	/* 0x16ab: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_16b0:
	/* 0x16b0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16b5:
	/* 0x16b5: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16ba:
	/* 0x16ba: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_16bd:
	/* 0x16bd: jae    29ad <generic_fentry_filter_arg+0x29ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10669ULL;
	}
x86_l_16c3:
	/* 0x16c3: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_16c8:
	/* 0x16c8: cmp    r13,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 416ULL);
x86_l_16cf:
	/* 0x16cf: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_16d4:
	/* 0x16d4: jne    1665 <generic_fentry_filter_arg+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1665;
	}
x86_l_16d6:
	/* 0x16d6: jmp    318c <generic_fentry_filter_arg+0x318c> */
	return 12684ULL;
x86_l_16db:
	/* 0x16db: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16de:
	/* 0x16de: je     1fee <generic_fentry_filter_arg+0x1fee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8174ULL;
	}
x86_l_16e4:
	/* 0x16e4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16e7:
	/* 0x16e7: jne    1ffd <generic_fentry_filter_arg+0x1ffd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8189ULL;
	}
x86_l_16ed:
	/* 0x16ed: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16f1:
	/* 0x16f1: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_16f4:
	/* 0x16f4: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_16f6:
	/* 0x16f6: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_16fc:
	/* 0x16fc: jmp    1ffd <generic_fentry_filter_arg+0x1ffd> */
	return 8189ULL;
x86_l_1701:
	/* 0x1701: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1704:
	/* 0x1704: je     2039 <generic_fentry_filter_arg+0x2039> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8249ULL;
	}
x86_l_170a:
	/* 0x170a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_170d:
	/* 0x170d: jne    2048 <generic_fentry_filter_arg+0x2048> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8264ULL;
	}
x86_l_1713:
	/* 0x1713: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1717:
	/* 0x1717: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_171a:
	/* 0x171a: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_171c:
	/* 0x171c: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_1722:
	/* 0x1722: jmp    2048 <generic_fentry_filter_arg+0x2048> */
	return 8264ULL;
x86_l_1727:
	/* 0x1727: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_172a:
	/* 0x172a: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1730:
	/* 0x1730: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1737:
	/* 0x1737: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_173c:
	/* 0x173c: mov    rdi,QWORD PTR [rip+0x1bbb9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1743:
	/* 0x1743: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1748:
	/* 0x1748: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_174a:
	/* 0x174a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_174d:
	/* 0x174d: je     17de <generic_fentry_filter_arg+0x17de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17de;
	}
x86_l_1753:
	/* 0x1753: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1757:
	/* 0x1757: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_175a:
	/* 0x175a: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_175f:
	/* 0x175f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1764:
	/* 0x1764: jmp    179f <generic_fentry_filter_arg+0x179f> */
	goto x86_l_179f;
x86_l_1766:
	/* 0x1766: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_1769:
	/* 0x1769: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_176f:
	/* 0x176f: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1776:
	/* 0x1776: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_177b:
	/* 0x177b: mov    rdi,QWORD PTR [rip+0x1bbb9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1782:
	/* 0x1782: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1787:
	/* 0x1787: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1789:
	/* 0x1789: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_178c:
	/* 0x178c: je     17de <generic_fentry_filter_arg+0x17de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17de;
	}
x86_l_178e:
	/* 0x178e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1792:
	/* 0x1792: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1795:
	/* 0x1795: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_179a:
	/* 0x179a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_179f:
	/* 0x179f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_17a2:
	/* 0x17a2: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_17a7:
	/* 0x17a7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_17a9:
	/* 0x17a9: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17ae:
	/* 0x17ae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17b0:
	/* 0x17b0: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_17b3:
	/* 0x17b3: ja     286d <generic_fentry_filter_arg+0x286d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10349ULL;
	}
x86_l_17b9:
	/* 0x17b9: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_17be:
	/* 0x17be: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_17c1:
	/* 0x17c1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17c6:
	/* 0x17c6: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17cb:
	/* 0x17cb: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_17ce:
	/* 0x17ce: jae    17f2 <generic_fentry_filter_arg+0x17f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_17f2;
	}
x86_l_17d0:
	/* 0x17d0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17d3:
	/* 0x17d3: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_17d6:
	/* 0x17d6: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_17d9:
	/* 0x17d9: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_17de:
	/* 0x17de: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17e0:
	/* 0x17e0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17e5:
	/* 0x17e5: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17ea:
	/* 0x17ea: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_17ed:
	/* 0x17ed: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_17f2:
	/* 0x17f2: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_17f7:
	/* 0x17f7: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_17fa:
	/* 0x17fa: jae    1802 <generic_fentry_filter_arg+0x1802> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1802;
	}
x86_l_17fc:
	/* 0x17fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17ff:
	/* 0x17ff: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1802:
	/* 0x1802: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1805:
	/* 0x1805: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_180a:
	/* 0x180a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_180d:
	/* 0x180d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1810:
	/* 0x1810: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1815:
	/* 0x1815: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_181a:
	/* 0x181a: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_181d:
	/* 0x181d: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1820:
	/* 0x1820: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_1825:
	/* 0x1825: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1827:
	/* 0x1827: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_182a:
	/* 0x182a: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_182f:
	/* 0x182f: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1834:
	/* 0x1834: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1839:
	/* 0x1839: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_183d:
	/* 0x183d: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1848:
	/* 0x1848: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_184d:
	/* 0x184d: mov    rdi,QWORD PTR [rip+0x1bbb9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1854:
	/* 0x1854: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1859:
	/* 0x1859: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_185b:
	/* 0x185b: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_185e:
	/* 0x185e: je     317b <generic_fentry_filter_arg+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12667ULL;
	}
x86_l_1864:
	/* 0x1864: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1867:
	/* 0x1867: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_186c:
	/* 0x186c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_186f:
	/* 0x186f: je     317d <generic_fentry_filter_arg+0x317d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12669ULL;
	}
x86_l_1875:
	/* 0x1875: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_187a:
	/* 0x187a: mov    rdi,QWORD PTR [rip+0x1bbb9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1881:
	/* 0x1881: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1886:
	/* 0x1886: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1888:
	/* 0x1888: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_188b:
	/* 0x188b: je     317b <generic_fentry_filter_arg+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12667ULL;
	}
x86_l_1891:
	/* 0x1891: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_1897:
	/* 0x1897: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_189c:
	/* 0x189c: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_189f:
	/* 0x189f: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_18a6:
	/* 0x18a6: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18a8:
	/* 0x18a8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_18ab:
	/* 0x18ab: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_18af:
	/* 0x18af: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_18b4:
	/* 0x18b4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b8:
	/* 0x18b8: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_18bb:
	/* 0x18bb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_18bd:
	/* 0x18bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18c2:
	/* 0x18c2: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_18c5:
	/* 0x18c5: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_18c8:
	/* 0x18c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ca:
	/* 0x18ca: jmp    3171 <generic_fentry_filter_arg+0x3171> */
	return 12657ULL;
x86_l_18cf:
	/* 0x18cf: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_18da:
	/* 0x18da: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_18e0:
	/* 0x18e0: jbe    1f8f <generic_fentry_filter_arg+0x1f8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 8079ULL;
	}
x86_l_18e6:
	/* 0x18e6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18e8:
	/* 0x18e8: jmp    318c <generic_fentry_filter_arg+0x318c> */
	return 12684ULL;
x86_l_18ed:
	/* 0x18ed: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18ef:
	/* 0x18ef: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f4:
	/* 0x18f4: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18f9:
	/* 0x18f9: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_18fc:
	/* 0x18fc: jmp    299 <generic_fentry_filter_arg+0x299> */
	return 665ULL;
x86_l_1901:
	/* 0x1901: cmp    eax,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_1904:
	/* 0x1904: jne    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 262ULL;
	}
x86_l_190a:
	/* 0x190a: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_190f:
	/* 0x190f: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1912:
	/* 0x1912: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1914:
	/* 0x1914: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_191d:
	/* 0x191d: jne    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 262ULL;
	}
x86_l_1923:
	/* 0x1923: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1927:
	/* 0x1927: mov    rcx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_192a:
	/* 0x192a: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_1932:
	/* 0x1932: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1937:
	/* 0x1937: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1939:
	/* 0x1939: andn   rax,rcx,QWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ANDN_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 144ULL);
x86_l_1943:
	/* 0x1943: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_1946:
	/* 0x1946: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_194b:
	/* 0x194b: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_194f:
	/* 0x194f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1951:
	/* 0x1951: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_1956:
	/* 0x1956: setb   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_B);
x86_l_1959:
	/* 0x1959: jmp    299 <generic_fentry_filter_arg+0x299> */
	return 665ULL;
x86_l_195e:
	/* 0x195e: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1962:
	/* 0x1962: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1964:
	/* 0x1964: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_1969:
	/* 0x1969: setae  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_AE);
x86_l_196c:
	/* 0x196c: jmp    299 <generic_fentry_filter_arg+0x299> */
	return 665ULL;
x86_l_1971:
	/* 0x1971: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1974:
	/* 0x1974: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1979:
	/* 0x1979: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_197e:
	/* 0x197e: mov    eax,0x1fe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 510ULL);
	return 6531ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6531ULL: goto x86_l_1983;
	case 6534ULL: goto x86_l_1986;
	case 6537ULL: goto x86_l_1989;
	case 6539ULL: goto x86_l_198b;
	case 6544ULL: goto x86_l_1990;
	case 6547ULL: goto x86_l_1993;
	case 6550ULL: goto x86_l_1996;
	case 6552ULL: goto x86_l_1998;
	case 6555ULL: goto x86_l_199b;
	case 6560ULL: goto x86_l_19a0;
	case 6563ULL: goto x86_l_19a3;
	case 6569ULL: goto x86_l_19a9;
	case 6573ULL: goto x86_l_19ad;
	case 6577ULL: goto x86_l_19b1;
	case 6581ULL: goto x86_l_19b5;
	case 6586ULL: goto x86_l_19ba;
	case 6593ULL: goto x86_l_19c1;
	case 6598ULL: goto x86_l_19c6;
	case 6601ULL: goto x86_l_19c9;
	case 6603ULL: goto x86_l_19cb;
	case 6606ULL: goto x86_l_19ce;
	case 6611ULL: goto x86_l_19d3;
	case 6618ULL: goto x86_l_19da;
	case 6621ULL: goto x86_l_19dd;
	case 6623ULL: goto x86_l_19df;
	case 6626ULL: goto x86_l_19e2;
	case 6632ULL: goto x86_l_19e8;
	case 6637ULL: goto x86_l_19ed;
	case 6640ULL: goto x86_l_19f0;
	case 6645ULL: goto x86_l_19f5;
	case 6650ULL: goto x86_l_19fa;
	case 6655ULL: goto x86_l_19ff;
	case 6661ULL: goto x86_l_1a05;
	case 6664ULL: goto x86_l_1a08;
	case 6672ULL: goto x86_l_1a10;
	case 6676ULL: goto x86_l_1a14;
	case 6680ULL: goto x86_l_1a18;
	case 6685ULL: goto x86_l_1a1d;
	case 6690ULL: goto x86_l_1a22;
	case 6696ULL: goto x86_l_1a28;
	case 6699ULL: goto x86_l_1a2b;
	case 6702ULL: goto x86_l_1a2e;
	case 6706ULL: goto x86_l_1a32;
	case 6711ULL: goto x86_l_1a37;
	case 6713ULL: goto x86_l_1a39;
	case 6715ULL: goto x86_l_1a3b;
	case 6717ULL: goto x86_l_1a3d;
	case 6723ULL: goto x86_l_1a43;
	case 6731ULL: goto x86_l_1a4b;
	case 6734ULL: goto x86_l_1a4e;
	case 6736ULL: goto x86_l_1a50;
	case 6742ULL: goto x86_l_1a56;
	case 6747ULL: goto x86_l_1a5b;
	case 6752ULL: goto x86_l_1a60;
	case 6755ULL: goto x86_l_1a63;
	case 6758ULL: goto x86_l_1a66;
	case 6763ULL: goto x86_l_1a6b;
	case 6768ULL: goto x86_l_1a70;
	case 6772ULL: goto x86_l_1a74;
	case 6777ULL: goto x86_l_1a79;
	case 6784ULL: goto x86_l_1a80;
	case 6789ULL: goto x86_l_1a85;
	case 6791ULL: goto x86_l_1a87;
	case 6794ULL: goto x86_l_1a8a;
	case 6800ULL: goto x86_l_1a90;
	case 6811ULL: goto x86_l_1a9b;
	case 6819ULL: goto x86_l_1aa3;
	case 6826ULL: goto x86_l_1aaa;
	case 6833ULL: goto x86_l_1ab1;
	case 6837ULL: goto x86_l_1ab5;
	case 6844ULL: goto x86_l_1abc;
	case 6849ULL: goto x86_l_1ac1;
	case 6852ULL: goto x86_l_1ac4;
	case 6857ULL: goto x86_l_1ac9;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6867ULL: goto x86_l_1ad3;
	case 6870ULL: goto x86_l_1ad6;
	case 6876ULL: goto x86_l_1adc;
	case 6879ULL: goto x86_l_1adf;
	case 6882ULL: goto x86_l_1ae2;
	case 6887ULL: goto x86_l_1ae7;
	case 6892ULL: goto x86_l_1aec;
	case 6897ULL: goto x86_l_1af1;
	case 6899ULL: goto x86_l_1af3;
	case 6902ULL: goto x86_l_1af6;
	case 6905ULL: goto x86_l_1af9;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6915ULL: goto x86_l_1b03;
	case 6918ULL: goto x86_l_1b06;
	case 6923ULL: goto x86_l_1b0b;
	case 6927ULL: goto x86_l_1b0f;
	case 6930ULL: goto x86_l_1b12;
	case 6933ULL: goto x86_l_1b15;
	case 6935ULL: goto x86_l_1b17;
	case 6938ULL: goto x86_l_1b1a;
	case 6944ULL: goto x86_l_1b20;
	case 6949ULL: goto x86_l_1b25;
	case 6952ULL: goto x86_l_1b28;
	case 6958ULL: goto x86_l_1b2e;
	case 6963ULL: goto x86_l_1b33;
	case 6968ULL: goto x86_l_1b38;
	case 6971ULL: goto x86_l_1b3b;
	case 6973ULL: goto x86_l_1b3d;
	case 6976ULL: goto x86_l_1b40;
	case 6982ULL: goto x86_l_1b46;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6996ULL: goto x86_l_1b54;
	case 6999ULL: goto x86_l_1b57;
	case 7005ULL: goto x86_l_1b5d;
	case 7010ULL: goto x86_l_1b62;
	case 7014ULL: goto x86_l_1b66;
	case 7017ULL: goto x86_l_1b69;
	case 7020ULL: goto x86_l_1b6c;
	case 7024ULL: goto x86_l_1b70;
	case 7027ULL: goto x86_l_1b73;
	case 7030ULL: goto x86_l_1b76;
	case 7033ULL: goto x86_l_1b79;
	case 7038ULL: goto x86_l_1b7e;
	case 7041ULL: goto x86_l_1b81;
	case 7047ULL: goto x86_l_1b87;
	case 7052ULL: goto x86_l_1b8c;
	case 7057ULL: goto x86_l_1b91;
	case 7060ULL: goto x86_l_1b94;
	case 7062ULL: goto x86_l_1b96;
	case 7065ULL: goto x86_l_1b99;
	case 7071ULL: goto x86_l_1b9f;
	case 7074ULL: goto x86_l_1ba2;
	case 7078ULL: goto x86_l_1ba6;
	case 7081ULL: goto x86_l_1ba9;
	case 7085ULL: goto x86_l_1bad;
	case 7090ULL: goto x86_l_1bb2;
	case 7094ULL: goto x86_l_1bb6;
	case 7097ULL: goto x86_l_1bb9;
	case 7103ULL: goto x86_l_1bbf;
	case 7107ULL: goto x86_l_1bc3;
	case 7112ULL: goto x86_l_1bc8;
	case 7119ULL: goto x86_l_1bcf;
	case 7124ULL: goto x86_l_1bd4;
	case 7126ULL: goto x86_l_1bd6;
	case 7129ULL: goto x86_l_1bd9;
	case 7135ULL: goto x86_l_1bdf;
	case 7138ULL: goto x86_l_1be2;
	case 7146ULL: goto x86_l_1bea;
	case 7151ULL: goto x86_l_1bef;
	case 7154ULL: goto x86_l_1bf2;
	case 7159ULL: goto x86_l_1bf7;
	case 7161ULL: goto x86_l_1bf9;
	case 7166ULL: goto x86_l_1bfe;
	case 7168ULL: goto x86_l_1c00;
	case 7171ULL: goto x86_l_1c03;
	case 7177ULL: goto x86_l_1c09;
	case 7182ULL: goto x86_l_1c0e;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	case 7195ULL: goto x86_l_1c1b;
	case 7198ULL: goto x86_l_1c1e;
	case 7204ULL: goto x86_l_1c24;
	case 7209ULL: goto x86_l_1c29;
	case 7212ULL: goto x86_l_1c2c;
	case 7218ULL: goto x86_l_1c32;
	case 7221ULL: goto x86_l_1c35;
	case 7224ULL: goto x86_l_1c38;
	case 7229ULL: goto x86_l_1c3d;
	case 7233ULL: goto x86_l_1c41;
	case 7236ULL: goto x86_l_1c44;
	case 7242ULL: goto x86_l_1c4a;
	case 7244ULL: goto x86_l_1c4c;
	case 7248ULL: goto x86_l_1c50;
	case 7251ULL: goto x86_l_1c53;
	case 7257ULL: goto x86_l_1c59;
	case 7262ULL: goto x86_l_1c5e;
	case 7265ULL: goto x86_l_1c61;
	case 7271ULL: goto x86_l_1c67;
	case 7276ULL: goto x86_l_1c6c;
	case 7279ULL: goto x86_l_1c6f;
	case 7281ULL: goto x86_l_1c71;
	case 7284ULL: goto x86_l_1c74;
	case 7287ULL: goto x86_l_1c77;
	case 7289ULL: goto x86_l_1c79;
	case 7293ULL: goto x86_l_1c7d;
	case 7296ULL: goto x86_l_1c80;
	case 7301ULL: goto x86_l_1c85;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7315ULL: goto x86_l_1c93;
	case 7321ULL: goto x86_l_1c99;
	case 7324ULL: goto x86_l_1c9c;
	case 7330ULL: goto x86_l_1ca2;
	case 7333ULL: goto x86_l_1ca5;
	case 7335ULL: goto x86_l_1ca7;
	case 7338ULL: goto x86_l_1caa;
	case 7344ULL: goto x86_l_1cb0;
	case 7348ULL: goto x86_l_1cb4;
	case 7351ULL: goto x86_l_1cb7;
	case 7357ULL: goto x86_l_1cbd;
	case 7362ULL: goto x86_l_1cc2;
	case 7365ULL: goto x86_l_1cc5;
	case 7370ULL: goto x86_l_1cca;
	case 7376ULL: goto x86_l_1cd0;
	case 7380ULL: goto x86_l_1cd4;
	case 7383ULL: goto x86_l_1cd7;
	case 7389ULL: goto x86_l_1cdd;
	case 7394ULL: goto x86_l_1ce2;
	case 7396ULL: goto x86_l_1ce4;
	case 7401ULL: goto x86_l_1ce9;
	case 7406ULL: goto x86_l_1cee;
	case 7409ULL: goto x86_l_1cf1;
	case 7414ULL: goto x86_l_1cf6;
	case 7417ULL: goto x86_l_1cf9;
	case 7423ULL: goto x86_l_1cff;
	case 7427ULL: goto x86_l_1d03;
	case 7430ULL: goto x86_l_1d06;
	case 7432ULL: goto x86_l_1d08;
	case 7438ULL: goto x86_l_1d0e;
	case 7443ULL: goto x86_l_1d13;
	case 7446ULL: goto x86_l_1d16;
	case 7452ULL: goto x86_l_1d1c;
	case 7456ULL: goto x86_l_1d20;
	case 7459ULL: goto x86_l_1d23;
	case 7461ULL: goto x86_l_1d25;
	case 7467ULL: goto x86_l_1d2b;
	case 7472ULL: goto x86_l_1d30;
	case 7477ULL: goto x86_l_1d35;
	case 7480ULL: goto x86_l_1d38;
	case 7483ULL: goto x86_l_1d3b;
	case 7488ULL: goto x86_l_1d40;
	case 7491ULL: goto x86_l_1d43;
	case 7496ULL: goto x86_l_1d48;
	case 7501ULL: goto x86_l_1d4d;
	case 7506ULL: goto x86_l_1d52;
	case 7509ULL: goto x86_l_1d55;
	case 7512ULL: goto x86_l_1d58;
	case 7514ULL: goto x86_l_1d5a;
	case 7519ULL: goto x86_l_1d5f;
	case 7522ULL: goto x86_l_1d62;
	case 7525ULL: goto x86_l_1d65;
	case 7527ULL: goto x86_l_1d67;
	case 7530ULL: goto x86_l_1d6a;
	case 7535ULL: goto x86_l_1d6f;
	case 7538ULL: goto x86_l_1d72;
	case 7544ULL: goto x86_l_1d78;
	case 7551ULL: goto x86_l_1d7f;
	case 7555ULL: goto x86_l_1d83;
	case 7559ULL: goto x86_l_1d87;
	case 7563ULL: goto x86_l_1d8b;
	case 7568ULL: goto x86_l_1d90;
	case 7575ULL: goto x86_l_1d97;
	case 7580ULL: goto x86_l_1d9c;
	case 7583ULL: goto x86_l_1d9f;
	case 7585ULL: goto x86_l_1da1;
	case 7590ULL: goto x86_l_1da6;
	case 7595ULL: goto x86_l_1dab;
	case 7602ULL: goto x86_l_1db2;
	case 7605ULL: goto x86_l_1db5;
	case 7607ULL: goto x86_l_1db7;
	case 7613ULL: goto x86_l_1dbd;
	case 7619ULL: goto x86_l_1dc3;
	case 7624ULL: goto x86_l_1dc8;
	case 7627ULL: goto x86_l_1dcb;
	case 7632ULL: goto x86_l_1dd0;
	case 7637ULL: goto x86_l_1dd5;
	case 7642ULL: goto x86_l_1dda;
	case 7648ULL: goto x86_l_1de0;
	case 7651ULL: goto x86_l_1de3;
	case 7656ULL: goto x86_l_1de8;
	case 7662ULL: goto x86_l_1dee;
	case 7667ULL: goto x86_l_1df3;
	case 7670ULL: goto x86_l_1df6;
	case 7674ULL: goto x86_l_1dfa;
	case 7679ULL: goto x86_l_1dff;
	case 7681ULL: goto x86_l_1e01;
	case 7685ULL: goto x86_l_1e05;
	case 7687ULL: goto x86_l_1e07;
	case 7692ULL: goto x86_l_1e0c;
	case 7694ULL: goto x86_l_1e0e;
	case 7700ULL: goto x86_l_1e14;
	case 7705ULL: goto x86_l_1e19;
	case 7709ULL: goto x86_l_1e1d;
	case 7712ULL: goto x86_l_1e20;
	case 7714ULL: goto x86_l_1e22;
	case 7720ULL: goto x86_l_1e28;
	case 7725ULL: goto x86_l_1e2d;
	case 7730ULL: goto x86_l_1e32;
	case 7733ULL: goto x86_l_1e35;
	case 7735ULL: goto x86_l_1e37;
	case 7738ULL: goto x86_l_1e3a;
	case 7744ULL: goto x86_l_1e40;
	case 7748ULL: goto x86_l_1e44;
	case 7751ULL: goto x86_l_1e47;
	case 7757ULL: goto x86_l_1e4d;
	case 7762ULL: goto x86_l_1e52;
	case 7767ULL: goto x86_l_1e57;
	case 7771ULL: goto x86_l_1e5b;
	case 7774ULL: goto x86_l_1e5e;
	case 7776ULL: goto x86_l_1e60;
	case 7781ULL: goto x86_l_1e65;
	case 7785ULL: goto x86_l_1e69;
	case 7788ULL: goto x86_l_1e6c;
	case 7793ULL: goto x86_l_1e71;
	case 7797ULL: goto x86_l_1e75;
	case 7802ULL: goto x86_l_1e7a;
	case 7805ULL: goto x86_l_1e7d;
	case 7808ULL: goto x86_l_1e80;
	case 7811ULL: goto x86_l_1e83;
	case 7817ULL: goto x86_l_1e89;
	case 7822ULL: goto x86_l_1e8e;
	case 7826ULL: goto x86_l_1e92;
	case 7831ULL: goto x86_l_1e97;
	case 7835ULL: goto x86_l_1e9b;
	case 7838ULL: goto x86_l_1e9e;
	case 7841ULL: goto x86_l_1ea1;
	case 7844ULL: goto x86_l_1ea4;
	case 7850ULL: goto x86_l_1eaa;
	case 7855ULL: goto x86_l_1eaf;
	case 7859ULL: goto x86_l_1eb3;
	case 7864ULL: goto x86_l_1eb8;
	case 7868ULL: goto x86_l_1ebc;
	case 7871ULL: goto x86_l_1ebf;
	case 7874ULL: goto x86_l_1ec2;
	case 7877ULL: goto x86_l_1ec5;
	case 7883ULL: goto x86_l_1ecb;
	case 7888ULL: goto x86_l_1ed0;
	case 7891ULL: goto x86_l_1ed3;
	case 7896ULL: goto x86_l_1ed8;
	case 7899ULL: goto x86_l_1edb;
	case 7901ULL: goto x86_l_1edd;
	case 7903ULL: goto x86_l_1edf;
	case 7908ULL: goto x86_l_1ee4;
	case 7910ULL: goto x86_l_1ee6;
	case 7913ULL: goto x86_l_1ee9;
	case 7916ULL: goto x86_l_1eec;
	case 7921ULL: goto x86_l_1ef1;
	case 7925ULL: goto x86_l_1ef5;
	case 7930ULL: goto x86_l_1efa;
	case 7937ULL: goto x86_l_1f01;
	case 7942ULL: goto x86_l_1f06;
	case 7944ULL: goto x86_l_1f08;
	case 7947ULL: goto x86_l_1f0b;
	case 7953ULL: goto x86_l_1f11;
	case 7956ULL: goto x86_l_1f14;
	case 7961ULL: goto x86_l_1f19;
	case 7964ULL: goto x86_l_1f1c;
	case 7969ULL: goto x86_l_1f21;
	case 7971ULL: goto x86_l_1f23;
	case 7975ULL: goto x86_l_1f27;
	case 7977ULL: goto x86_l_1f29;
	case 7979ULL: goto x86_l_1f2b;
	case 7982ULL: goto x86_l_1f2e;
	case 7985ULL: goto x86_l_1f31;
	case 7988ULL: goto x86_l_1f34;
	case 7990ULL: goto x86_l_1f36;
	case 7992ULL: goto x86_l_1f38;
	case 7996ULL: goto x86_l_1f3c;
	case 7999ULL: goto x86_l_1f3f;
	case 8001ULL: goto x86_l_1f41;
	case 8005ULL: goto x86_l_1f45;
	case 8008ULL: goto x86_l_1f48;
	case 8010ULL: goto x86_l_1f4a;
	case 8014ULL: goto x86_l_1f4e;
	case 8016ULL: goto x86_l_1f50;
	case 8020ULL: goto x86_l_1f54;
	case 8024ULL: goto x86_l_1f58;
	case 8027ULL: goto x86_l_1f5b;
	case 8029ULL: goto x86_l_1f5d;
	case 8031ULL: goto x86_l_1f5f;
	case 8033ULL: goto x86_l_1f61;
	case 8039ULL: goto x86_l_1f67;
	case 8043ULL: goto x86_l_1f6b;
	case 8048ULL: goto x86_l_1f70;
	case 8050ULL: goto x86_l_1f72;
	case 8054ULL: goto x86_l_1f76;
	case 8057ULL: goto x86_l_1f79;
	case 8061ULL: goto x86_l_1f7d;
	case 8067ULL: goto x86_l_1f83;
	case 8069ULL: goto x86_l_1f85;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8082ULL: goto x86_l_1f92;
	case 8087ULL: goto x86_l_1f97;
	case 8092ULL: goto x86_l_1f9c;
	case 8098ULL: goto x86_l_1fa2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1983:
	/* 0x1983: cmovae edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_1986:
	/* 0x1986: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1989:
	/* 0x1989: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_198b:
	/* 0x198b: cmp    eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1990:
	/* 0x1990: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1993:
	/* 0x1993: xor    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 7ULL);
x86_l_1996:
	/* 0x1996: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1998:
	/* 0x1998: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_199b:
	/* 0x199b: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_19a0:
	/* 0x19a0: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_19a3:
	/* 0x19a3: je     2d14 <generic_fentry_filter_arg+0x2d14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11540ULL;
	}
x86_l_19a9:
	/* 0x19a9: mov    DWORD PTR [rsp+0x3c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_19ad:
	/* 0x19ad: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19b1:
	/* 0x19b1: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19b5:
	/* 0x19b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19ba:
	/* 0x19ba: mov    rdi,QWORD PTR [rip+0x1bbb9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_19c1:
	/* 0x19c1: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19c6:
	/* 0x19c6: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_19c9:
	/* 0x19c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19cb:
	/* 0x19cb: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_19ce:
	/* 0x19ce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19d3:
	/* 0x19d3: mov    rdi,QWORD PTR [rip+0x1bbb9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_19da:
	/* 0x19da: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_19dd:
	/* 0x19dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19df:
	/* 0x19df: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_19e2:
	/* 0x19e2: je     2d14 <generic_fentry_filter_arg+0x2d14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11540ULL;
	}
x86_l_19e8:
	/* 0x19e8: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_19ed:
	/* 0x19ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19f0:
	/* 0x19f0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19f5:
	/* 0x19f5: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19fa:
	/* 0x19fa: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19ff:
	/* 0x19ff: je     2d25 <generic_fentry_filter_arg+0x2d25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11557ULL;
	}
x86_l_1a05:
	/* 0x1a05: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1a08:
	/* 0x1a08: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a10:
	/* 0x1a10: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a14:
	/* 0x1a14: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a18:
	/* 0x1a18: movzx  ebx,WORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_1a1d:
	/* 0x1a1d: cmp    DWORD PTR [rsp+0x20],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953477ULL);
x86_l_1a22:
	/* 0x1a22: jg     239b <generic_fentry_filter_arg+0x239b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9115ULL;
	}
x86_l_1a28:
	/* 0x1a28: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_1a2b:
	/* 0x1a2b: mov    BYTE PTR [rcx],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a2e:
	/* 0x1a2e: lea    rdi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1a32:
	/* 0x1a32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a37:
	/* 0x1a37: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1a39:
	/* 0x1a39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3b:
	/* 0x1a3b: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_1a3d:
	/* 0x1a3d: jbe    23d6 <generic_fentry_filter_arg+0x23d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9174ULL;
	}
x86_l_1a43:
	/* 0x1a43: lea    rdi,[rbp*1+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 1ULL);
x86_l_1a4b:
	/* 0x1a4b: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a4e:
	/* 0x1a4e: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1a50:
	/* 0x1a50: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a56:
	/* 0x1a56: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a5b:
	/* 0x1a5b: jmp    23ca <generic_fentry_filter_arg+0x23ca> */
	return 9162ULL;
x86_l_1a60:
	/* 0x1a60: mov    rbx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R8, X86_WIDTH_64);
x86_l_1a63:
	/* 0x1a63: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_1a66:
	/* 0x1a66: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a6b:
	/* 0x1a6b: mov    eax,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a70:
	/* 0x1a70: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a74:
	/* 0x1a74: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a79:
	/* 0x1a79: mov    rdi,QWORD PTR [rip+0x1bbb9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_1a80:
	/* 0x1a80: lea    rsi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a85:
	/* 0x1a85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a87:
	/* 0x1a87: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a8a:
	/* 0x1a8a: je     1d30 <generic_fentry_filter_arg+0x1d30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d30;
	}
x86_l_1a90:
	/* 0x1a90: mov    DWORD PTR [rsp+0x80],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755814016ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    DWORD PTR [rsp+0x84],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_1aa3:
	/* 0x1aa3: mov    DWORD PTR [rsp+0x88],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1aaa:
	/* 0x1aaa: mov    DWORD PTR [rsp+0x8c],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_1ab1:
	/* 0x1ab1: shr    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1ab5:
	/* 0x1ab5: mov    DWORD PTR [rsp+0x90],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1abc:
	/* 0x1abc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ac1:
	/* 0x1ac1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ac4:
	/* 0x1ac4: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ac9:
	/* 0x1ac9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1acb:
	/* 0x1acb: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ad0:
	/* 0x1ad0: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_1ad3:
	/* 0x1ad3: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1ad6:
	/* 0x1ad6: jb     2084 <generic_fentry_filter_arg+0x2084> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8324ULL;
	}
x86_l_1adc:
	/* 0x1adc: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_1adf:
	/* 0x1adf: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ae2:
	/* 0x1ae2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1aec:
	/* 0x1aec: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1af1:
	/* 0x1af1: ja     1b01 <generic_fentry_filter_arg+0x1b01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b01;
	}
x86_l_1af3:
	/* 0x1af3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1af6:
	/* 0x1af6: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1af9:
	/* 0x1af9: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1afc:
	/* 0x1afc: jmp    299 <generic_fentry_filter_arg+0x299> */
	return 665ULL;
x86_l_1b01:
	/* 0x1b01: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b03:
	/* 0x1b03: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b06:
	/* 0x1b06: jmp    299 <generic_fentry_filter_arg+0x299> */
	return 665ULL;
x86_l_1b0b:
	/* 0x1b0b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b0f:
	/* 0x1b0f: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b12:
	/* 0x1b12: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1b15:
	/* 0x1b15: ja     1b20 <generic_fentry_filter_arg+0x1b20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b20;
	}
x86_l_1b17:
	/* 0x1b17: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1b1a:
	/* 0x1b1a: jbe    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 687ULL;
	}
x86_l_1b20:
	/* 0x1b20: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b25:
	/* 0x1b25: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1b28:
	/* 0x1b28: jb     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 262ULL;
	}
x86_l_1b2e:
	/* 0x1b2e: mov    rdi,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b33:
	/* 0x1b33: mov    rsi,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b38:
	/* 0x1b38: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1b3b:
	/* 0x1b3b: je     1b46 <generic_fentry_filter_arg+0x1b46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b46;
	}
x86_l_1b3d:
	/* 0x1b3d: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1b40:
	/* 0x1b40: jne    219d <generic_fentry_filter_arg+0x219d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8605ULL;
	}
x86_l_1b46:
	/* 0x1b46: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b49:
	/* 0x1b49: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b4e:
	/* 0x1b4e: jg     21b0 <generic_fentry_filter_arg+0x21b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8624ULL;
	}
x86_l_1b54:
	/* 0x1b54: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_1b57:
	/* 0x1b57: jle    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 687ULL;
	}
x86_l_1b5d:
	/* 0x1b5d: jmp    21b0 <generic_fentry_filter_arg+0x21b0> */
	return 8624ULL;
x86_l_1b62:
	/* 0x1b62: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b66:
	/* 0x1b66: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b69:
	/* 0x1b69: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1b6c:
	/* 0x1b6c: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1b70:
	/* 0x1b70: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1b73:
	/* 0x1b73: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1b76:
	/* 0x1b76: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1b79:
	/* 0x1b79: mov    esi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b7e:
	/* 0x1b7e: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_1b81:
	/* 0x1b81: jb     2d42 <generic_fentry_filter_arg+0x2d42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11586ULL;
	}
x86_l_1b87:
	/* 0x1b87: mov    r8,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b8c:
	/* 0x1b8c: mov    rdi,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b91:
	/* 0x1b91: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1b94:
	/* 0x1b94: je     1b9f <generic_fentry_filter_arg+0x1b9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b9f;
	}
x86_l_1b96:
	/* 0x1b96: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1b99:
	/* 0x1b99: jne    2155 <generic_fentry_filter_arg+0x2155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8533ULL;
	}
x86_l_1b9f:
	/* 0x1b9f: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_1ba2:
	/* 0x1ba2: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1ba6:
	/* 0x1ba6: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1ba9:
	/* 0x1ba9: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1bad:
	/* 0x1bad: jmp    2163 <generic_fentry_filter_arg+0x2163> */
	return 8547ULL;
x86_l_1bb2:
	/* 0x1bb2: movzx  ebx,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1bb6:
	/* 0x1bb6: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_1bb9:
	/* 0x1bb9: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1bbf:
	/* 0x1bbf: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1bc3:
	/* 0x1bc3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bc8:
	/* 0x1bc8: mov    rdi,QWORD PTR [rip+0x1bbb9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1bcf:
	/* 0x1bcf: lea    rsi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1bd4:
	/* 0x1bd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd6:
	/* 0x1bd6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bd9:
	/* 0x1bd9: je     2244 <generic_fentry_filter_arg+0x2244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8772ULL;
	}
x86_l_1bdf:
	/* 0x1bdf: movzx  ecx,bx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1be2:
	/* 0x1be2: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1bea:
	/* 0x1bea: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1bef:
	/* 0x1bef: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1bf2:
	/* 0x1bf2: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bf7:
	/* 0x1bf7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1bf9:
	/* 0x1bf9: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1bfe:
	/* 0x1bfe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c00:
	/* 0x1c00: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1c03:
	/* 0x1c03: ja     2b95 <generic_fentry_filter_arg+0x2b95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11157ULL;
	}
x86_l_1c09:
	/* 0x1c09: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1c0e:
	/* 0x1c0e: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1c11:
	/* 0x1c11: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c16:
	/* 0x1c16: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c1b:
	/* 0x1c1b: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_1c1e:
	/* 0x1c1e: jb     290 <generic_fentry_filter_arg+0x290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 656ULL;
	}
x86_l_1c24:
	/* 0x1c24: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1c29:
	/* 0x1c29: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1c2c:
	/* 0x1c2c: jae    296 <generic_fentry_filter_arg+0x296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 662ULL;
	}
x86_l_1c32:
	/* 0x1c32: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c35:
	/* 0x1c35: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1c38:
	/* 0x1c38: jmp    296 <generic_fentry_filter_arg+0x296> */
	return 662ULL;
x86_l_1c3d:
	/* 0x1c3d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c41:
	/* 0x1c41: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c44:
	/* 0x1c44: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_1c4a:
	/* 0x1c4a: jmp    1c59 <generic_fentry_filter_arg+0x1c59> */
	goto x86_l_1c59;
x86_l_1c4c:
	/* 0x1c4c: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c50:
	/* 0x1c50: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c53:
	/* 0x1c53: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_1c59:
	/* 0x1c59: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c5e:
	/* 0x1c5e: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1c61:
	/* 0x1c61: jb     322b <generic_fentry_filter_arg+0x322b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12843ULL;
	}
x86_l_1c67:
	/* 0x1c67: mov    rsi,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c6c:
	/* 0x1c6c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c6f:
	/* 0x1c6f: jle    1c90 <generic_fentry_filter_arg+0x1c90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1c90;
	}
x86_l_1c71:
	/* 0x1c71: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1c74:
	/* 0x1c74: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1c77:
	/* 0x1c77: jae    1cc2 <generic_fentry_filter_arg+0x1cc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1cc2;
	}
x86_l_1c79:
	/* 0x1c79: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c7d:
	/* 0x1c7d: cmp    QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c80:
	/* 0x1c80: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c85:
	/* 0x1c85: jne    27af <generic_fentry_filter_arg+0x27af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10159ULL;
	}
x86_l_1c8b:
	/* 0x1c8b: jmp    3115 <generic_fentry_filter_arg+0x3115> */
	return 12565ULL;
x86_l_1c90:
	/* 0x1c90: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c93:
	/* 0x1c93: je     1e32 <generic_fentry_filter_arg+0x1e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e32;
	}
x86_l_1c99:
	/* 0x1c99: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c9c:
	/* 0x1c9c: jne    27af <generic_fentry_filter_arg+0x27af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10159ULL;
	}
x86_l_1ca2:
	/* 0x1ca2: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1ca5:
	/* 0x1ca5: je     1cb0 <generic_fentry_filter_arg+0x1cb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cb0;
	}
x86_l_1ca7:
	/* 0x1ca7: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1caa:
	/* 0x1caa: jne    27a2 <generic_fentry_filter_arg+0x27a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10146ULL;
	}
x86_l_1cb0:
	/* 0x1cb0: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cb4:
	/* 0x1cb4: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cb7:
	/* 0x1cb7: jl     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 687ULL;
	}
x86_l_1cbd:
	/* 0x1cbd: jmp    27af <generic_fentry_filter_arg+0x27af> */
	return 10159ULL;
x86_l_1cc2:
	/* 0x1cc2: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1cc5:
	/* 0x1cc5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cca:
	/* 0x1cca: jne    27af <generic_fentry_filter_arg+0x27af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10159ULL;
	}
x86_l_1cd0:
	/* 0x1cd0: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cd4:
	/* 0x1cd4: test   QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cd7:
	/* 0x1cd7: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_1cdd:
	/* 0x1cdd: jmp    27af <generic_fentry_filter_arg+0x27af> */
	return 10159ULL;
x86_l_1ce2:
	/* 0x1ce2: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ce4:
	/* 0x1ce4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ce9:
	/* 0x1ce9: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cee:
	/* 0x1cee: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_1cf1:
	/* 0x1cf1: jmp    d1a <generic_fentry_filter_arg+0xd1a> */
	return 3354ULL;
x86_l_1cf6:
	/* 0x1cf6: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1cf9:
	/* 0x1cf9: jne    1ffd <generic_fentry_filter_arg+0x1ffd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8189ULL;
	}
x86_l_1cff:
	/* 0x1cff: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d03:
	/* 0x1d03: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1d06:
	/* 0x1d06: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1d08:
	/* 0x1d08: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_1d0e:
	/* 0x1d0e: jmp    1ffd <generic_fentry_filter_arg+0x1ffd> */
	return 8189ULL;
x86_l_1d13:
	/* 0x1d13: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d16:
	/* 0x1d16: jne    2048 <generic_fentry_filter_arg+0x2048> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8264ULL;
	}
x86_l_1d1c:
	/* 0x1d1c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d20:
	/* 0x1d20: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d23:
	/* 0x1d23: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1d25:
	/* 0x1d25: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_1d2b:
	/* 0x1d2b: jmp    2048 <generic_fentry_filter_arg+0x2048> */
	return 8264ULL;
x86_l_1d30:
	/* 0x1d30: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d35:
	/* 0x1d35: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1d38:
	/* 0x1d38: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1d3b:
	/* 0x1d3b: jmp    2087 <generic_fentry_filter_arg+0x2087> */
	return 8327ULL;
x86_l_1d40:
	/* 0x1d40: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1d43:
	/* 0x1d43: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1d48:
	/* 0x1d48: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_1d4d:
	/* 0x1d4d: mov    eax,0x1fe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 510ULL);
x86_l_1d52:
	/* 0x1d52: cmovae esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_1d55:
	/* 0x1d55: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1d58:
	/* 0x1d58: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d5a:
	/* 0x1d5a: cmp    eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1d5f:
	/* 0x1d5f: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1d62:
	/* 0x1d62: xor    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 7ULL);
x86_l_1d65:
	/* 0x1d65: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1d67:
	/* 0x1d67: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1d6a:
	/* 0x1d6a: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_1d6f:
	/* 0x1d6f: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_1d72:
	/* 0x1d72: je     2eb8 <generic_fentry_filter_arg+0x2eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11960ULL;
	}
x86_l_1d78:
	/* 0x1d78: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1d7f:
	/* 0x1d7f: mov    DWORD PTR [rsp+0x3c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1d83:
	/* 0x1d83: mov    DWORD PTR [rsp+0x40],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d87:
	/* 0x1d87: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d8b:
	/* 0x1d8b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d90:
	/* 0x1d90: mov    rdi,QWORD PTR [rip+0x1bbb9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_1d97:
	/* 0x1d97: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d9c:
	/* 0x1d9c: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1d9f:
	/* 0x1d9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da1:
	/* 0x1da1: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1da6:
	/* 0x1da6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dab:
	/* 0x1dab: mov    rdi,QWORD PTR [rip+0x1bbb9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1db2:
	/* 0x1db2: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1db5:
	/* 0x1db5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db7:
	/* 0x1db7: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1dbd:
	/* 0x1dbd: je     2eb8 <generic_fentry_filter_arg+0x2eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11960ULL;
	}
x86_l_1dc3:
	/* 0x1dc3: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1dc8:
	/* 0x1dc8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dcb:
	/* 0x1dcb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dd0:
	/* 0x1dd0: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dd5:
	/* 0x1dd5: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dda:
	/* 0x1dda: je     2ec9 <generic_fentry_filter_arg+0x2ec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11977ULL;
	}
x86_l_1de0:
	/* 0x1de0: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1de3:
	/* 0x1de3: cmp    DWORD PTR [rsp+0x40],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906949ULL);
x86_l_1de8:
	/* 0x1de8: jg     2688 <generic_fentry_filter_arg+0x2688> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9864ULL;
	}
x86_l_1dee:
	/* 0x1dee: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1df3:
	/* 0x1df3: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1df6:
	/* 0x1df6: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1dfa:
	/* 0x1dfa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dff:
	/* 0x1dff: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1e01:
	/* 0x1e01: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e05:
	/* 0x1e05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e07:
	/* 0x1e07: movzx  esi,WORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_1e0c:
	/* 0x1e0c: cmp    esi,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1e0e:
	/* 0x1e0e: jbe    26c9 <generic_fentry_filter_arg+0x26c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9929ULL;
	}
x86_l_1e14:
	/* 0x1e14: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e19:
	/* 0x1e19: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1e1d:
	/* 0x1e1d: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1e20:
	/* 0x1e20: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e22:
	/* 0x1e22: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e28:
	/* 0x1e28: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e2d:
	/* 0x1e2d: jmp    26c4 <generic_fentry_filter_arg+0x26c4> */
	return 9924ULL;
x86_l_1e32:
	/* 0x1e32: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1e35:
	/* 0x1e35: je     1e40 <generic_fentry_filter_arg+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e40;
	}
x86_l_1e37:
	/* 0x1e37: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1e3a:
	/* 0x1e3a: jne    2793 <generic_fentry_filter_arg+0x2793> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10131ULL;
	}
x86_l_1e40:
	/* 0x1e40: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e44:
	/* 0x1e44: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e47:
	/* 0x1e47: jg     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 687ULL;
	}
x86_l_1e4d:
	/* 0x1e4d: jmp    27af <generic_fentry_filter_arg+0x27af> */
	return 10159ULL;
x86_l_1e52:
	/* 0x1e52: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e57:
	/* 0x1e57: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e5b:
	/* 0x1e5b: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e5e:
	/* 0x1e5e: jmp    1e6c <generic_fentry_filter_arg+0x1e6c> */
	goto x86_l_1e6c;
x86_l_1e60:
	/* 0x1e60: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e65:
	/* 0x1e65: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e69:
	/* 0x1e69: movzx  ecx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e6c:
	/* 0x1e6c: cmp    DWORD PTR [r12+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e71:
	/* 0x1e71: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1e75:
	/* 0x1e75: cmp    DWORD PTR [r12+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e7a:
	/* 0x1e7a: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_1e7d:
	/* 0x1e7d: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e80:
	/* 0x1e80: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1e83:
	/* 0x1e83: jb     2d42 <generic_fentry_filter_arg+0x2d42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11586ULL;
	}
x86_l_1e89:
	/* 0x1e89: cmp    DWORD PTR [r12+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e8e:
	/* 0x1e8e: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1e92:
	/* 0x1e92: cmp    DWORD PTR [r12+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1e97:
	/* 0x1e97: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1e9b:
	/* 0x1e9b: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e9e:
	/* 0x1e9e: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1ea1:
	/* 0x1ea1: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1ea4:
	/* 0x1ea4: jb     2d3d <generic_fentry_filter_arg+0x2d3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11581ULL;
	}
x86_l_1eaa:
	/* 0x1eaa: cmp    DWORD PTR [r12+0x20],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1eaf:
	/* 0x1eaf: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1eb3:
	/* 0x1eb3: cmp    DWORD PTR [r12+0x24],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1eb8:
	/* 0x1eb8: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1ebc:
	/* 0x1ebc: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ebf:
	/* 0x1ebf: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1ec2:
	/* 0x1ec2: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1ec5:
	/* 0x1ec5: jb     2d3d <generic_fentry_filter_arg+0x2d3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11581ULL;
	}
x86_l_1ecb:
	/* 0x1ecb: cmp    DWORD PTR [r12+0x28],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ed0:
	/* 0x1ed0: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_1ed3:
	/* 0x1ed3: cmp    DWORD PTR [r12+0x2c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1ed8:
	/* 0x1ed8: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_1edb:
	/* 0x1edb: and    cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1edd:
	/* 0x1edd: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1edf:
	/* 0x1edf: jmp    2d3d <generic_fentry_filter_arg+0x2d3d> */
	return 11581ULL;
x86_l_1ee4:
	/* 0x1ee4: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ee6:
	/* 0x1ee6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ee9:
	/* 0x1ee9: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_1eec:
	/* 0x1eec: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ef5:
	/* 0x1ef5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1efa:
	/* 0x1efa: mov    rdi,QWORD PTR [rip+0x1bbb9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1f01:
	/* 0x1f01: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f06:
	/* 0x1f06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f08:
	/* 0x1f08: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f0b:
	/* 0x1f0b: je     28a2 <generic_fentry_filter_arg+0x28a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10402ULL;
	}
x86_l_1f11:
	/* 0x1f11: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_1f14:
	/* 0x1f14: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f19:
	/* 0x1f19: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_1f1c:
	/* 0x1f1c: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f21:
	/* 0x1f21: je     1f67 <generic_fentry_filter_arg+0x1f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f67;
	}
x86_l_1f23:
	/* 0x1f23: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f27:
	/* 0x1f27: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f29:
	/* 0x1f29: jmp    1f36 <generic_fentry_filter_arg+0x1f36> */
	goto x86_l_1f36;
x86_l_1f2b:
	/* 0x1f2b: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1f2e:
	/* 0x1f2e: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1f31:
	/* 0x1f31: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1f34:
	/* 0x1f34: je     1f67 <generic_fentry_filter_arg+0x1f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f67;
	}
x86_l_1f36:
	/* 0x1f36: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f38:
	/* 0x1f38: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1f3c:
	/* 0x1f3c: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1f3f:
	/* 0x1f3f: jae    1f2b <generic_fentry_filter_arg+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f2b;
	}
x86_l_1f41:
	/* 0x1f41: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1f45:
	/* 0x1f45: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_1f48:
	/* 0x1f48: je     1f5f <generic_fentry_filter_arg+0x1f5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f5f;
	}
x86_l_1f4a:
	/* 0x1f4a: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1f4e:
	/* 0x1f4e: ja     1f2b <generic_fentry_filter_arg+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f2b;
	}
x86_l_1f50:
	/* 0x1f50: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1f54:
	/* 0x1f54: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1f58:
	/* 0x1f58: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1f5b:
	/* 0x1f5b: je     1f38 <generic_fentry_filter_arg+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f38;
	}
x86_l_1f5d:
	/* 0x1f5d: jmp    1f2b <generic_fentry_filter_arg+0x1f2b> */
	goto x86_l_1f2b;
x86_l_1f5f:
	/* 0x1f5f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1f61:
	/* 0x1f61: jns    2bf3 <generic_fentry_filter_arg+0x2bf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11251ULL;
	}
x86_l_1f67:
	/* 0x1f67: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f6b:
	/* 0x1f6b: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1f70:
	/* 0x1f70: jae    1f83 <generic_fentry_filter_arg+0x1f83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f83;
	}
x86_l_1f72:
	/* 0x1f72: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1f76:
	/* 0x1f76: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1f79:
	/* 0x1f79: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_1f7d:
	/* 0x1f7d: jne    1ee9 <generic_fentry_filter_arg+0x1ee9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ee9;
	}
x86_l_1f83:
	/* 0x1f83: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f85:
	/* 0x1f85: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f8a:
	/* 0x1f8a: jmp    318c <generic_fentry_filter_arg+0x318c> */
	return 12684ULL;
x86_l_1f8f:
	/* 0x1f8f: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1f92:
	/* 0x1f92: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1f97:
	/* 0x1f97: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f9c:
	/* 0x1f9c: ja     245c <generic_fentry_filter_arg+0x245c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9308ULL;
	}
x86_l_1fa2:
	/* 0x1fa2: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
	return 8102ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8102ULL: goto x86_l_1fa6;
	case 8108ULL: goto x86_l_1fac;
	case 8111ULL: goto x86_l_1faf;
	case 8114ULL: goto x86_l_1fb2;
	case 8117ULL: goto x86_l_1fb5;
	case 8119ULL: goto x86_l_1fb7;
	case 8121ULL: goto x86_l_1fb9;
	case 8124ULL: goto x86_l_1fbc;
	case 8126ULL: goto x86_l_1fbe;
	case 8128ULL: goto x86_l_1fc0;
	case 8130ULL: goto x86_l_1fc2;
	case 8132ULL: goto x86_l_1fc4;
	case 8135ULL: goto x86_l_1fc7;
	case 8137ULL: goto x86_l_1fc9;
	case 8139ULL: goto x86_l_1fcb;
	case 8141ULL: goto x86_l_1fcd;
	case 8144ULL: goto x86_l_1fd0;
	case 8148ULL: goto x86_l_1fd4;
	case 8154ULL: goto x86_l_1fda;
	case 8158ULL: goto x86_l_1fde;
	case 8164ULL: goto x86_l_1fe4;
	case 8167ULL: goto x86_l_1fe7;
	case 8169ULL: goto x86_l_1fe9;
	case 8174ULL: goto x86_l_1fee;
	case 8178ULL: goto x86_l_1ff2;
	case 8181ULL: goto x86_l_1ff5;
	case 8183ULL: goto x86_l_1ff7;
	case 8189ULL: goto x86_l_1ffd;
	case 8194ULL: goto x86_l_2002;
	case 8197ULL: goto x86_l_2005;
	case 8203ULL: goto x86_l_200b;
	case 8208ULL: goto x86_l_2010;
	case 8211ULL: goto x86_l_2013;
	case 8217ULL: goto x86_l_2019;
	case 8220ULL: goto x86_l_201c;
	case 8223ULL: goto x86_l_201f;
	case 8229ULL: goto x86_l_2025;
	case 8233ULL: goto x86_l_2029;
	case 8236ULL: goto x86_l_202c;
	case 8238ULL: goto x86_l_202e;
	case 8244ULL: goto x86_l_2034;
	case 8249ULL: goto x86_l_2039;
	case 8253ULL: goto x86_l_203d;
	case 8256ULL: goto x86_l_2040;
	case 8258ULL: goto x86_l_2042;
	case 8264ULL: goto x86_l_2048;
	case 8269ULL: goto x86_l_204d;
	case 8272ULL: goto x86_l_2050;
	case 8278ULL: goto x86_l_2056;
	case 8283ULL: goto x86_l_205b;
	case 8286ULL: goto x86_l_205e;
	case 8292ULL: goto x86_l_2064;
	case 8295ULL: goto x86_l_2067;
	case 8298ULL: goto x86_l_206a;
	case 8304ULL: goto x86_l_2070;
	case 8308ULL: goto x86_l_2074;
	case 8311ULL: goto x86_l_2077;
	case 8313ULL: goto x86_l_2079;
	case 8319ULL: goto x86_l_207f;
	case 8324ULL: goto x86_l_2084;
	case 8327ULL: goto x86_l_2087;
	case 8330ULL: goto x86_l_208a;
	case 8335ULL: goto x86_l_208f;
	case 8340ULL: goto x86_l_2094;
	case 8345ULL: goto x86_l_2099;
	case 8348ULL: goto x86_l_209c;
	case 8353ULL: goto x86_l_20a1;
	case 8357ULL: goto x86_l_20a5;
	case 8359ULL: goto x86_l_20a7;
	case 8361ULL: goto x86_l_20a9;
	case 8363ULL: goto x86_l_20ab;
	case 8365ULL: goto x86_l_20ad;
	case 8371ULL: goto x86_l_20b3;
	case 8376ULL: goto x86_l_20b8;
	case 8379ULL: goto x86_l_20bb;
	case 8385ULL: goto x86_l_20c1;
	case 8390ULL: goto x86_l_20c6;
	case 8395ULL: goto x86_l_20cb;
	case 8398ULL: goto x86_l_20ce;
	case 8404ULL: goto x86_l_20d4;
	case 8410ULL: goto x86_l_20da;
	case 8414ULL: goto x86_l_20de;
	case 8420ULL: goto x86_l_20e4;
	case 8422ULL: goto x86_l_20e6;
	case 8427ULL: goto x86_l_20eb;
	case 8433ULL: goto x86_l_20f1;
	case 8435ULL: goto x86_l_20f3;
	case 8441ULL: goto x86_l_20f9;
	case 8446ULL: goto x86_l_20fe;
	case 8450ULL: goto x86_l_2102;
	case 8452ULL: goto x86_l_2104;
	case 8454ULL: goto x86_l_2106;
	case 8458ULL: goto x86_l_210a;
	case 8460ULL: goto x86_l_210c;
	case 8463ULL: goto x86_l_210f;
	case 8466ULL: goto x86_l_2112;
	case 8471ULL: goto x86_l_2117;
	case 8474ULL: goto x86_l_211a;
	case 8480ULL: goto x86_l_2120;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8493ULL: goto x86_l_212d;
	case 8499ULL: goto x86_l_2133;
	case 8505ULL: goto x86_l_2139;
	case 8509ULL: goto x86_l_213d;
	case 8515ULL: goto x86_l_2143;
	case 8518ULL: goto x86_l_2146;
	case 8522ULL: goto x86_l_214a;
	case 8524ULL: goto x86_l_214c;
	case 8528ULL: goto x86_l_2150;
	case 8533ULL: goto x86_l_2155;
	case 8536ULL: goto x86_l_2158;
	case 8540ULL: goto x86_l_215c;
	case 8543ULL: goto x86_l_215f;
	case 8547ULL: goto x86_l_2163;
	case 8550ULL: goto x86_l_2166;
	case 8553ULL: goto x86_l_2169;
	case 8556ULL: goto x86_l_216c;
	case 8562ULL: goto x86_l_2172;
	case 8567ULL: goto x86_l_2177;
	case 8572ULL: goto x86_l_217c;
	case 8575ULL: goto x86_l_217f;
	case 8577ULL: goto x86_l_2181;
	case 8580ULL: goto x86_l_2184;
	case 8586ULL: goto x86_l_218a;
	case 8589ULL: goto x86_l_218d;
	case 8593ULL: goto x86_l_2191;
	case 8596ULL: goto x86_l_2194;
	case 8600ULL: goto x86_l_2198;
	case 8605ULL: goto x86_l_219d;
	case 8608ULL: goto x86_l_21a0;
	case 8613ULL: goto x86_l_21a5;
	case 8615ULL: goto x86_l_21a7;
	case 8618ULL: goto x86_l_21aa;
	case 8624ULL: goto x86_l_21b0;
	case 8627ULL: goto x86_l_21b3;
	case 8633ULL: goto x86_l_21b9;
	case 8638ULL: goto x86_l_21be;
	case 8643ULL: goto x86_l_21c3;
	case 8646ULL: goto x86_l_21c6;
	case 8648ULL: goto x86_l_21c8;
	case 8651ULL: goto x86_l_21cb;
	case 8657ULL: goto x86_l_21d1;
	case 8660ULL: goto x86_l_21d4;
	case 8665ULL: goto x86_l_21d9;
	case 8671ULL: goto x86_l_21df;
	case 8674ULL: goto x86_l_21e2;
	case 8680ULL: goto x86_l_21e8;
	case 8685ULL: goto x86_l_21ed;
	case 8687ULL: goto x86_l_21ef;
	case 8690ULL: goto x86_l_21f2;
	case 8692ULL: goto x86_l_21f4;
	case 8695ULL: goto x86_l_21f7;
	case 8697ULL: goto x86_l_21f9;
	case 8701ULL: goto x86_l_21fd;
	case 8704ULL: goto x86_l_2200;
	case 8706ULL: goto x86_l_2202;
	case 8709ULL: goto x86_l_2205;
	case 8715ULL: goto x86_l_220b;
	case 8718ULL: goto x86_l_220e;
	case 8724ULL: goto x86_l_2214;
	case 8728ULL: goto x86_l_2218;
	case 8733ULL: goto x86_l_221d;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8747ULL: goto x86_l_222b;
	case 8750ULL: goto x86_l_222e;
	case 8752ULL: goto x86_l_2230;
	case 8754ULL: goto x86_l_2232;
	case 8762ULL: goto x86_l_223a;
	case 8767ULL: goto x86_l_223f;
	case 8772ULL: goto x86_l_2244;
	case 8774ULL: goto x86_l_2246;
	case 8779ULL: goto x86_l_224b;
	case 8784ULL: goto x86_l_2250;
	case 8787ULL: goto x86_l_2253;
	case 8792ULL: goto x86_l_2258;
	case 8796ULL: goto x86_l_225c;
	case 8798ULL: goto x86_l_225e;
	case 8804ULL: goto x86_l_2264;
	case 8806ULL: goto x86_l_2266;
	case 8810ULL: goto x86_l_226a;
	case 8812ULL: goto x86_l_226c;
	case 8818ULL: goto x86_l_2272;
	case 8823ULL: goto x86_l_2277;
	case 8826ULL: goto x86_l_227a;
	case 8832ULL: goto x86_l_2280;
	case 8837ULL: goto x86_l_2285;
	case 8840ULL: goto x86_l_2288;
	case 8842ULL: goto x86_l_228a;
	case 8845ULL: goto x86_l_228d;
	case 8848ULL: goto x86_l_2290;
	case 8850ULL: goto x86_l_2292;
	case 8854ULL: goto x86_l_2296;
	case 8856ULL: goto x86_l_2298;
	case 8861ULL: goto x86_l_229d;
	case 8867ULL: goto x86_l_22a3;
	case 8872ULL: goto x86_l_22a8;
	case 8875ULL: goto x86_l_22ab;
	case 8877ULL: goto x86_l_22ad;
	case 8880ULL: goto x86_l_22b0;
	case 8886ULL: goto x86_l_22b6;
	case 8889ULL: goto x86_l_22b9;
	case 8895ULL: goto x86_l_22bf;
	case 8901ULL: goto x86_l_22c5;
	case 8905ULL: goto x86_l_22c9;
	case 8911ULL: goto x86_l_22cf;
	case 8915ULL: goto x86_l_22d3;
	case 8918ULL: goto x86_l_22d6;
	case 8924ULL: goto x86_l_22dc;
	case 8929ULL: goto x86_l_22e1;
	case 8932ULL: goto x86_l_22e4;
	case 8937ULL: goto x86_l_22e9;
	case 8943ULL: goto x86_l_22ef;
	case 8947ULL: goto x86_l_22f3;
	case 8950ULL: goto x86_l_22f6;
	case 8956ULL: goto x86_l_22fc;
	case 8961ULL: goto x86_l_2301;
	case 8964ULL: goto x86_l_2304;
	case 8970ULL: goto x86_l_230a;
	case 8976ULL: goto x86_l_2310;
	case 8980ULL: goto x86_l_2314;
	case 8986ULL: goto x86_l_231a;
	case 8990ULL: goto x86_l_231e;
	case 8993ULL: goto x86_l_2321;
	case 8999ULL: goto x86_l_2327;
	case 9004ULL: goto x86_l_232c;
	case 9006ULL: goto x86_l_232e;
	case 9011ULL: goto x86_l_2333;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9024ULL: goto x86_l_2340;
	case 9026ULL: goto x86_l_2342;
	case 9029ULL: goto x86_l_2345;
	case 9034ULL: goto x86_l_234a;
	case 9039ULL: goto x86_l_234f;
	case 9042ULL: goto x86_l_2352;
	case 9048ULL: goto x86_l_2358;
	case 9051ULL: goto x86_l_235b;
	case 9057ULL: goto x86_l_2361;
	case 9061ULL: goto x86_l_2365;
	case 9064ULL: goto x86_l_2368;
	case 9066ULL: goto x86_l_236a;
	case 9072ULL: goto x86_l_2370;
	case 9077ULL: goto x86_l_2375;
	case 9080ULL: goto x86_l_2378;
	case 9086ULL: goto x86_l_237e;
	case 9089ULL: goto x86_l_2381;
	case 9095ULL: goto x86_l_2387;
	case 9099ULL: goto x86_l_238b;
	case 9102ULL: goto x86_l_238e;
	case 9104ULL: goto x86_l_2390;
	case 9110ULL: goto x86_l_2396;
	case 9115ULL: goto x86_l_239b;
	case 9118ULL: goto x86_l_239e;
	case 9121ULL: goto x86_l_23a1;
	case 9125ULL: goto x86_l_23a5;
	case 9130ULL: goto x86_l_23aa;
	case 9132ULL: goto x86_l_23ac;
	case 9134ULL: goto x86_l_23ae;
	case 9136ULL: goto x86_l_23b0;
	case 9138ULL: goto x86_l_23b2;
	case 9146ULL: goto x86_l_23ba;
	case 9149ULL: goto x86_l_23bd;
	case 9151ULL: goto x86_l_23bf;
	case 9157ULL: goto x86_l_23c5;
	case 9162ULL: goto x86_l_23ca;
	case 9164ULL: goto x86_l_23cc;
	case 9172ULL: goto x86_l_23d4;
	case 9174ULL: goto x86_l_23d6;
	case 9178ULL: goto x86_l_23da;
	case 9182ULL: goto x86_l_23de;
	case 9186ULL: goto x86_l_23e2;
	case 9189ULL: goto x86_l_23e5;
	case 9191ULL: goto x86_l_23e7;
	case 9194ULL: goto x86_l_23ea;
	case 9199ULL: goto x86_l_23ef;
	case 9204ULL: goto x86_l_23f4;
	case 9209ULL: goto x86_l_23f9;
	case 9215ULL: goto x86_l_23ff;
	case 9217ULL: goto x86_l_2401;
	case 9223ULL: goto x86_l_2407;
	case 9226ULL: goto x86_l_240a;
	case 9232ULL: goto x86_l_2410;
	case 9237ULL: goto x86_l_2415;
	case 9244ULL: goto x86_l_241c;
	case 9249ULL: goto x86_l_2421;
	case 9252ULL: goto x86_l_2424;
	case 9257ULL: goto x86_l_2429;
	case 9262ULL: goto x86_l_242e;
	case 9267ULL: goto x86_l_2433;
	case 9273ULL: goto x86_l_2439;
	case 9276ULL: goto x86_l_243c;
	case 9282ULL: goto x86_l_2442;
	case 9285ULL: goto x86_l_2445;
	case 9291ULL: goto x86_l_244b;
	case 9296ULL: goto x86_l_2450;
	case 9303ULL: goto x86_l_2457;
	case 9308ULL: goto x86_l_245c;
	case 9311ULL: goto x86_l_245f;
	case 9316ULL: goto x86_l_2464;
	case 9321ULL: goto x86_l_2469;
	case 9326ULL: goto x86_l_246e;
	case 9329ULL: goto x86_l_2471;
	case 9332ULL: goto x86_l_2474;
	case 9334ULL: goto x86_l_2476;
	case 9339ULL: goto x86_l_247b;
	case 9342ULL: goto x86_l_247e;
	case 9345ULL: goto x86_l_2481;
	case 9347ULL: goto x86_l_2483;
	case 9350ULL: goto x86_l_2486;
	case 9355ULL: goto x86_l_248b;
	case 9358ULL: goto x86_l_248e;
	case 9364ULL: goto x86_l_2494;
	case 9368ULL: goto x86_l_2498;
	case 9372ULL: goto x86_l_249c;
	case 9376ULL: goto x86_l_24a0;
	case 9380ULL: goto x86_l_24a4;
	case 9385ULL: goto x86_l_24a9;
	case 9392ULL: goto x86_l_24b0;
	case 9397ULL: goto x86_l_24b5;
	case 9400ULL: goto x86_l_24b8;
	case 9402ULL: goto x86_l_24ba;
	case 9405ULL: goto x86_l_24bd;
	case 9410ULL: goto x86_l_24c2;
	case 9417ULL: goto x86_l_24c9;
	case 9420ULL: goto x86_l_24cc;
	case 9422ULL: goto x86_l_24ce;
	case 9425ULL: goto x86_l_24d1;
	case 9431ULL: goto x86_l_24d7;
	case 9436ULL: goto x86_l_24dc;
	case 9439ULL: goto x86_l_24df;
	case 9444ULL: goto x86_l_24e4;
	case 9449ULL: goto x86_l_24e9;
	case 9454ULL: goto x86_l_24ee;
	case 9460ULL: goto x86_l_24f4;
	case 9463ULL: goto x86_l_24f7;
	case 9471ULL: goto x86_l_24ff;
	case 9476ULL: goto x86_l_2504;
	case 9481ULL: goto x86_l_2509;
	case 9487ULL: goto x86_l_250f;
	case 9490ULL: goto x86_l_2512;
	case 9493ULL: goto x86_l_2515;
	case 9497ULL: goto x86_l_2519;
	case 9502ULL: goto x86_l_251e;
	case 9504ULL: goto x86_l_2520;
	case 9508ULL: goto x86_l_2524;
	case 9510ULL: goto x86_l_2526;
	case 9512ULL: goto x86_l_2528;
	case 9518ULL: goto x86_l_252e;
	case 9526ULL: goto x86_l_2536;
	case 9529ULL: goto x86_l_2539;
	case 9531ULL: goto x86_l_253b;
	case 9537ULL: goto x86_l_2541;
	case 9542ULL: goto x86_l_2546;
	case 9547ULL: goto x86_l_254b;
	case 9550ULL: goto x86_l_254e;
	case 9554ULL: goto x86_l_2552;
	case 9556ULL: goto x86_l_2554;
	case 9560ULL: goto x86_l_2558;
	case 9563ULL: goto x86_l_255b;
	case 9566ULL: goto x86_l_255e;
	case 9569ULL: goto x86_l_2561;
	case 9575ULL: goto x86_l_2567;
	case 9580ULL: goto x86_l_256c;
	case 9585ULL: goto x86_l_2571;
	case 9588ULL: goto x86_l_2574;
	case 9594ULL: goto x86_l_257a;
	case 9600ULL: goto x86_l_2580;
	case 9604ULL: goto x86_l_2584;
	case 9610ULL: goto x86_l_258a;
	case 9613ULL: goto x86_l_258d;
	case 9617ULL: goto x86_l_2591;
	case 9619ULL: goto x86_l_2593;
	case 9623ULL: goto x86_l_2597;
	case 9628ULL: goto x86_l_259c;
	case 9630ULL: goto x86_l_259e;
	case 9635ULL: goto x86_l_25a3;
	case 9637ULL: goto x86_l_25a5;
	case 9639ULL: goto x86_l_25a7;
	case 9645ULL: goto x86_l_25ad;
	case 9648ULL: goto x86_l_25b0;
	case 9654ULL: goto x86_l_25b6;
	case 9659ULL: goto x86_l_25bb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1fa6:
	/* 0x1fa6: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1fac:
	/* 0x1fac: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1faf:
	/* 0x1faf: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1fb2:
	/* 0x1fb2: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1fb5:
	/* 0x1fb5: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1fb7:
	/* 0x1fb7: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1fb9:
	/* 0x1fb9: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1fbc:
	/* 0x1fbc: je     1fc4 <generic_fentry_filter_arg+0x1fc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fc4;
	}
x86_l_1fbe:
	/* 0x1fbe: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1fc0:
	/* 0x1fc0: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1fc2:
	/* 0x1fc2: je     1fda <generic_fentry_filter_arg+0x1fda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fda;
	}
x86_l_1fc4:
	/* 0x1fc4: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1fc7:
	/* 0x1fc7: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1fc9:
	/* 0x1fc9: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1fcb:
	/* 0x1fcb: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1fcd:
	/* 0x1fcd: add    esi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1fd0:
	/* 0x1fd0: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1fd4:
	/* 0x1fd4: ja     2471 <generic_fentry_filter_arg+0x2471> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2471;
	}
x86_l_1fda:
	/* 0x1fda: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1fde:
	/* 0x1fde: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1fe4:
	/* 0x1fe4: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1fe7:
	/* 0x1fe7: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1fe9:
	/* 0x1fe9: jmp    2481 <generic_fentry_filter_arg+0x2481> */
	goto x86_l_2481;
x86_l_1fee:
	/* 0x1fee: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ff2:
	/* 0x1ff2: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1ff5:
	/* 0x1ff5: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1ff7:
	/* 0x1ff7: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_1ffd:
	/* 0x1ffd: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2002:
	/* 0x2002: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_2005:
	/* 0x2005: jb     322b <generic_fentry_filter_arg+0x322b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12843ULL;
	}
x86_l_200b:
	/* 0x200b: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2010:
	/* 0x2010: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2013:
	/* 0x2013: jle    234f <generic_fentry_filter_arg+0x234f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_234f;
	}
x86_l_2019:
	/* 0x2019: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_201c:
	/* 0x201c: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_201f:
	/* 0x201f: jae    2833 <generic_fentry_filter_arg+0x2833> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10291ULL;
	}
x86_l_2025:
	/* 0x2025: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2029:
	/* 0x2029: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_202c:
	/* 0x202c: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_202e:
	/* 0x202e: jne    2930 <generic_fentry_filter_arg+0x2930> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10544ULL;
	}
x86_l_2034:
	/* 0x2034: jmp    3115 <generic_fentry_filter_arg+0x3115> */
	return 12565ULL;
x86_l_2039:
	/* 0x2039: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_203d:
	/* 0x203d: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2040:
	/* 0x2040: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2042:
	/* 0x2042: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_2048:
	/* 0x2048: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_204d:
	/* 0x204d: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_2050:
	/* 0x2050: jb     322b <generic_fentry_filter_arg+0x322b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12843ULL;
	}
x86_l_2056:
	/* 0x2056: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_205b:
	/* 0x205b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_205e:
	/* 0x205e: jle    2375 <generic_fentry_filter_arg+0x2375> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2375;
	}
x86_l_2064:
	/* 0x2064: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2067:
	/* 0x2067: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_206a:
	/* 0x206a: jae    2850 <generic_fentry_filter_arg+0x2850> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10320ULL;
	}
x86_l_2070:
	/* 0x2070: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2074:
	/* 0x2074: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2077:
	/* 0x2077: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2079:
	/* 0x2079: jne    2976 <generic_fentry_filter_arg+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10614ULL;
	}
x86_l_207f:
	/* 0x207f: jmp    3115 <generic_fentry_filter_arg+0x3115> */
	return 12565ULL;
x86_l_2084:
	/* 0x2084: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2087:
	/* 0x2087: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_208a:
	/* 0x208a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_208f:
	/* 0x208f: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2094:
	/* 0x2094: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2099:
	/* 0x2099: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_209c:
	/* 0x209c: jmp    299 <generic_fentry_filter_arg+0x299> */
	return 665ULL;
x86_l_20a1:
	/* 0x20a1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a5:
	/* 0x20a5: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a7:
	/* 0x20a7: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_20a9:
	/* 0x20a9: ja     20b3 <generic_fentry_filter_arg+0x20b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_20b3;
	}
x86_l_20ab:
	/* 0x20ab: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_20ad:
	/* 0x20ad: jbe    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 687ULL;
	}
x86_l_20b3:
	/* 0x20b3: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20b8:
	/* 0x20b8: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_20bb:
	/* 0x20bb: jb     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 262ULL;
	}
x86_l_20c1:
	/* 0x20c1: mov    edi,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20c6:
	/* 0x20c6: mov    esi,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20cb:
	/* 0x20cb: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_20ce:
	/* 0x20ce: ja     259c <generic_fentry_filter_arg+0x259c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_259c;
	}
x86_l_20d4:
	/* 0x20d4: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_20da:
	/* 0x20da: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_20de:
	/* 0x20de: jae    259c <generic_fentry_filter_arg+0x259c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_259c;
	}
x86_l_20e4:
	/* 0x20e4: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_20e6:
	/* 0x20e6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20eb:
	/* 0x20eb: jg     25ad <generic_fentry_filter_arg+0x25ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_25ad;
	}
x86_l_20f1:
	/* 0x20f1: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_20f3:
	/* 0x20f3: jle    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 687ULL;
	}
x86_l_20f9:
	/* 0x20f9: jmp    25ad <generic_fentry_filter_arg+0x25ad> */
	goto x86_l_25ad;
x86_l_20fe:
	/* 0x20fe: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2102:
	/* 0x2102: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2104:
	/* 0x2104: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2106:
	/* 0x2106: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_210a:
	/* 0x210a: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_210c:
	/* 0x210c: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_210f:
	/* 0x210f: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_2112:
	/* 0x2112: mov    esi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2117:
	/* 0x2117: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_211a:
	/* 0x211a: jb     2d42 <generic_fentry_filter_arg+0x2d42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11586ULL;
	}
x86_l_2120:
	/* 0x2120: mov    r8d,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2125:
	/* 0x2125: mov    edi,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_212a:
	/* 0x212a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_212d:
	/* 0x212d: ja     254b <generic_fentry_filter_arg+0x254b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_254b;
	}
x86_l_2133:
	/* 0x2133: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_2139:
	/* 0x2139: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_213d:
	/* 0x213d: jae    254b <generic_fentry_filter_arg+0x254b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_254b;
	}
x86_l_2143:
	/* 0x2143: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2146:
	/* 0x2146: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_214a:
	/* 0x214a: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_214c:
	/* 0x214c: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_2150:
	/* 0x2150: jmp    2558 <generic_fentry_filter_arg+0x2558> */
	goto x86_l_2558;
x86_l_2155:
	/* 0x2155: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_2158:
	/* 0x2158: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_215c:
	/* 0x215c: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_215f:
	/* 0x215f: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2163:
	/* 0x2163: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2166:
	/* 0x2166: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2169:
	/* 0x2169: cmp    esi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 41ULL);
x86_l_216c:
	/* 0x216c: jb     2d3d <generic_fentry_filter_arg+0x2d3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11581ULL;
	}
x86_l_2172:
	/* 0x2172: mov    r8,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2177:
	/* 0x2177: mov    rdi,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_217c:
	/* 0x217c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_217f:
	/* 0x217f: je     218a <generic_fentry_filter_arg+0x218a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_218a;
	}
x86_l_2181:
	/* 0x2181: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2184:
	/* 0x2184: jne    263e <generic_fentry_filter_arg+0x263e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9790ULL;
	}
x86_l_218a:
	/* 0x218a: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_218d:
	/* 0x218d: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2191:
	/* 0x2191: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2194:
	/* 0x2194: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_2198:
	/* 0x2198: jmp    264c <generic_fentry_filter_arg+0x264c> */
	return 9804ULL;
x86_l_219d:
	/* 0x219d: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_21a0:
	/* 0x21a0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21a5:
	/* 0x21a5: ja     21b0 <generic_fentry_filter_arg+0x21b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_21b0;
	}
x86_l_21a7:
	/* 0x21a7: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_21aa:
	/* 0x21aa: jbe    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 687ULL;
	}
x86_l_21b0:
	/* 0x21b0: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_21b3:
	/* 0x21b3: jb     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 262ULL;
	}
x86_l_21b9:
	/* 0x21b9: mov    rdi,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21be:
	/* 0x21be: mov    rsi,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21c3:
	/* 0x21c3: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_21c6:
	/* 0x21c6: je     21d1 <generic_fentry_filter_arg+0x21d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21d1;
	}
x86_l_21c8:
	/* 0x21c8: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_21cb:
	/* 0x21cb: jne    2748 <generic_fentry_filter_arg+0x2748> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10056ULL;
	}
x86_l_21d1:
	/* 0x21d1: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_21d4:
	/* 0x21d4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21d9:
	/* 0x21d9: jg     275b <generic_fentry_filter_arg+0x275b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10075ULL;
	}
x86_l_21df:
	/* 0x21df: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_21e2:
	/* 0x21e2: jle    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 687ULL;
	}
x86_l_21e8:
	/* 0x21e8: jmp    275b <generic_fentry_filter_arg+0x275b> */
	return 10075ULL;
x86_l_21ed:
	/* 0x21ed: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21ef:
	/* 0x21ef: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_21f2:
	/* 0x21f2: jne    21fd <generic_fentry_filter_arg+0x21fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21fd;
	}
x86_l_21f4:
	/* 0x21f4: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_21f7:
	/* 0x21f7: je     21fd <generic_fentry_filter_arg+0x21fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21fd;
	}
x86_l_21f9:
	/* 0x21f9: movzx  ebx,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_21fd:
	/* 0x21fd: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2200:
	/* 0x2200: je     220b <generic_fentry_filter_arg+0x220b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220b;
	}
x86_l_2202:
	/* 0x2202: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2205:
	/* 0x2205: jne    2681 <generic_fentry_filter_arg+0x2681> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9857ULL;
	}
x86_l_220b:
	/* 0x220b: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_220e:
	/* 0x220e: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2214:
	/* 0x2214: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2218:
	/* 0x2218: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_221d:
	/* 0x221d: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2224:
	/* 0x2224: lea    rsi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2229:
	/* 0x2229: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_222b:
	/* 0x222b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_222e:
	/* 0x222e: je     2244 <generic_fentry_filter_arg+0x2244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2244;
	}
x86_l_2230:
	/* 0x2230: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_2232:
	/* 0x2232: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_223a:
	/* 0x223a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_223f:
	/* 0x223f: jmp    1bef <generic_fentry_filter_arg+0x1bef> */
	return 7151ULL;
x86_l_2244:
	/* 0x2244: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2246:
	/* 0x2246: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_224b:
	/* 0x224b: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2250:
	/* 0x2250: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_2253:
	/* 0x2253: jmp    299 <generic_fentry_filter_arg+0x299> */
	return 665ULL;
x86_l_2258:
	/* 0x2258: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_225c:
	/* 0x225c: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_225e:
	/* 0x225e: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_2264:
	/* 0x2264: jmp    2272 <generic_fentry_filter_arg+0x2272> */
	goto x86_l_2272;
x86_l_2266:
	/* 0x2266: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_226a:
	/* 0x226a: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_226c:
	/* 0x226c: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_2272:
	/* 0x2272: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2277:
	/* 0x2277: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_227a:
	/* 0x227a: jb     322b <generic_fentry_filter_arg+0x322b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12843ULL;
	}
x86_l_2280:
	/* 0x2280: mov    esi,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2285:
	/* 0x2285: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2288:
	/* 0x2288: jle    22a8 <generic_fentry_filter_arg+0x22a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_22a8;
	}
x86_l_228a:
	/* 0x228a: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_228d:
	/* 0x228d: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2290:
	/* 0x2290: jae    22e1 <generic_fentry_filter_arg+0x22e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_22e1;
	}
x86_l_2292:
	/* 0x2292: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2296:
	/* 0x2296: cmp    DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2298:
	/* 0x2298: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_229d:
	/* 0x229d: jne    2a75 <generic_fentry_filter_arg+0x2a75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10869ULL;
	}
x86_l_22a3:
	/* 0x22a3: jmp    3115 <generic_fentry_filter_arg+0x3115> */
	return 12565ULL;
x86_l_22a8:
	/* 0x22a8: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22ab:
	/* 0x22ab: je     2301 <generic_fentry_filter_arg+0x2301> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2301;
	}
x86_l_22ad:
	/* 0x22ad: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_22b0:
	/* 0x22b0: jne    2a75 <generic_fentry_filter_arg+0x2a75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10869ULL;
	}
x86_l_22b6:
	/* 0x22b6: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_22b9:
	/* 0x22b9: ja     2a68 <generic_fentry_filter_arg+0x2a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10856ULL;
	}
x86_l_22bf:
	/* 0x22bf: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_22c5:
	/* 0x22c5: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_22c9:
	/* 0x22c9: jae    2a68 <generic_fentry_filter_arg+0x2a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10856ULL;
	}
x86_l_22cf:
	/* 0x22cf: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22d3:
	/* 0x22d3: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22d6:
	/* 0x22d6: jl     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 687ULL;
	}
x86_l_22dc:
	/* 0x22dc: jmp    2a75 <generic_fentry_filter_arg+0x2a75> */
	return 10869ULL;
x86_l_22e1:
	/* 0x22e1: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_22e4:
	/* 0x22e4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22e9:
	/* 0x22e9: jne    2a75 <generic_fentry_filter_arg+0x2a75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10869ULL;
	}
x86_l_22ef:
	/* 0x22ef: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22f3:
	/* 0x22f3: test   DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22f6:
	/* 0x22f6: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_22fc:
	/* 0x22fc: jmp    2a75 <generic_fentry_filter_arg+0x2a75> */
	return 10869ULL;
x86_l_2301:
	/* 0x2301: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2304:
	/* 0x2304: ja     2a59 <generic_fentry_filter_arg+0x2a59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10841ULL;
	}
x86_l_230a:
	/* 0x230a: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2310:
	/* 0x2310: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2314:
	/* 0x2314: jae    2a59 <generic_fentry_filter_arg+0x2a59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10841ULL;
	}
x86_l_231a:
	/* 0x231a: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_231e:
	/* 0x231e: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2321:
	/* 0x2321: jg     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 687ULL;
	}
x86_l_2327:
	/* 0x2327: jmp    2a75 <generic_fentry_filter_arg+0x2a75> */
	return 10869ULL;
x86_l_232c:
	/* 0x232c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_232e:
	/* 0x232e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2333:
	/* 0x2333: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_2336:
	/* 0x2336: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_233b:
	/* 0x233b: jmp    25f8 <generic_fentry_filter_arg+0x25f8> */
	return 9720ULL;
x86_l_2340:
	/* 0x2340: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2342:
	/* 0x2342: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_2345:
	/* 0x2345: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_234a:
	/* 0x234a: jmp    261b <generic_fentry_filter_arg+0x261b> */
	return 9755ULL;
x86_l_234f:
	/* 0x234f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2352:
	/* 0x2352: je     2921 <generic_fentry_filter_arg+0x2921> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10529ULL;
	}
x86_l_2358:
	/* 0x2358: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_235b:
	/* 0x235b: jne    2930 <generic_fentry_filter_arg+0x2930> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10544ULL;
	}
x86_l_2361:
	/* 0x2361: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2365:
	/* 0x2365: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2368:
	/* 0x2368: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_236a:
	/* 0x236a: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_2370:
	/* 0x2370: jmp    2930 <generic_fentry_filter_arg+0x2930> */
	return 10544ULL;
x86_l_2375:
	/* 0x2375: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2378:
	/* 0x2378: je     2967 <generic_fentry_filter_arg+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10599ULL;
	}
x86_l_237e:
	/* 0x237e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2381:
	/* 0x2381: jne    2976 <generic_fentry_filter_arg+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10614ULL;
	}
x86_l_2387:
	/* 0x2387: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_238b:
	/* 0x238b: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_238e:
	/* 0x238e: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2390:
	/* 0x2390: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_2396:
	/* 0x2396: jmp    2976 <generic_fentry_filter_arg+0x2976> */
	return 10614ULL;
x86_l_239b:
	/* 0x239b: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_239e:
	/* 0x239e: mov    WORD PTR [rcx],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23a1:
	/* 0x23a1: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_23a5:
	/* 0x23a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23aa:
	/* 0x23aa: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_23ac:
	/* 0x23ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ae:
	/* 0x23ae: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_23b0:
	/* 0x23b0: jbe    23d6 <generic_fentry_filter_arg+0x23d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_23d6;
	}
x86_l_23b2:
	/* 0x23b2: lea    rdi,[rbp*1+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 2ULL);
x86_l_23ba:
	/* 0x23ba: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23bd:
	/* 0x23bd: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_23bf:
	/* 0x23bf: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23c5:
	/* 0x23c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23ca:
	/* 0x23ca: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_23cc:
	/* 0x23cc: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_23d4:
	/* 0x23d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d6:
	/* 0x23d6: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_23da:
	/* 0x23da: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_23de:
	/* 0x23de: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23e2:
	/* 0x23e2: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_23e5:
	/* 0x23e5: jg     2421 <generic_fentry_filter_arg+0x2421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2421;
	}
x86_l_23e7:
	/* 0x23e7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23ea:
	/* 0x23ea: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ef:
	/* 0x23ef: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f4:
	/* 0x23f4: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23f9:
	/* 0x23f9: jg     28bb <generic_fentry_filter_arg+0x28bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10427ULL;
	}
x86_l_23ff:
	/* 0x23ff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2401:
	/* 0x2401: je     2cbb <generic_fentry_filter_arg+0x2cbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11451ULL;
	}
x86_l_2407:
	/* 0x2407: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_240a:
	/* 0x240a: jne    91e <generic_fentry_filter_arg+0x91e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2334ULL;
	}
x86_l_2410:
	/* 0x2410: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2415:
	/* 0x2415: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_241c:
	/* 0x241c: jmp    2cf1 <generic_fentry_filter_arg+0x2cf1> */
	return 11505ULL;
x86_l_2421:
	/* 0x2421: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2424:
	/* 0x2424: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2429:
	/* 0x2429: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_242e:
	/* 0x242e: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2433:
	/* 0x2433: jg     28de <generic_fentry_filter_arg+0x28de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10462ULL;
	}
x86_l_2439:
	/* 0x2439: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_243c:
	/* 0x243c: je     2cc9 <generic_fentry_filter_arg+0x2cc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11465ULL;
	}
x86_l_2442:
	/* 0x2442: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2445:
	/* 0x2445: jne    91e <generic_fentry_filter_arg+0x91e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2334ULL;
	}
x86_l_244b:
	/* 0x244b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2450:
	/* 0x2450: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2457:
	/* 0x2457: jmp    2cf1 <generic_fentry_filter_arg+0x2cf1> */
	return 11505ULL;
x86_l_245c:
	/* 0x245c: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_245f:
	/* 0x245f: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_2464:
	/* 0x2464: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_2469:
	/* 0x2469: mov    eax,0x1fe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 510ULL);
x86_l_246e:
	/* 0x246e: cmovae esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_2471:
	/* 0x2471: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2474:
	/* 0x2474: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2476:
	/* 0x2476: cmp    eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_247b:
	/* 0x247b: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_247e:
	/* 0x247e: xor    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 7ULL);
x86_l_2481:
	/* 0x2481: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2483:
	/* 0x2483: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2486:
	/* 0x2486: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_248b:
	/* 0x248b: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_248e:
	/* 0x248e: je     317b <generic_fentry_filter_arg+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12667ULL;
	}
x86_l_2494:
	/* 0x2494: mov    DWORD PTR [rsp+0x3c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2498:
	/* 0x2498: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_249c:
	/* 0x249c: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24a0:
	/* 0x24a0: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24a4:
	/* 0x24a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24a9:
	/* 0x24a9: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_24b0:
	/* 0x24b0: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24b5:
	/* 0x24b5: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_24b8:
	/* 0x24b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ba:
	/* 0x24ba: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_24bd:
	/* 0x24bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24c2:
	/* 0x24c2: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_24c9:
	/* 0x24c9: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_24cc:
	/* 0x24cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ce:
	/* 0x24ce: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_24d1:
	/* 0x24d1: je     317b <generic_fentry_filter_arg+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12667ULL;
	}
x86_l_24d7:
	/* 0x24d7: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_24dc:
	/* 0x24dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24df:
	/* 0x24df: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24e4:
	/* 0x24e4: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e9:
	/* 0x24e9: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24ee:
	/* 0x24ee: je     318c <generic_fentry_filter_arg+0x318c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12684ULL;
	}
x86_l_24f4:
	/* 0x24f4: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_24f7:
	/* 0x24f7: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_24ff:
	/* 0x24ff: movzx  ebx,WORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_2504:
	/* 0x2504: cmp    DWORD PTR [rsp+0x20],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953477ULL);
x86_l_2509:
	/* 0x2509: jg     2c14 <generic_fentry_filter_arg+0x2c14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11284ULL;
	}
x86_l_250f:
	/* 0x250f: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_2512:
	/* 0x2512: mov    BYTE PTR [rcx],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2515:
	/* 0x2515: lea    rdi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2519:
	/* 0x2519: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_251e:
	/* 0x251e: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2520:
	/* 0x2520: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2524:
	/* 0x2524: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2526:
	/* 0x2526: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_2528:
	/* 0x2528: jbe    2c53 <generic_fentry_filter_arg+0x2c53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11347ULL;
	}
x86_l_252e:
	/* 0x252e: lea    rdi,[rbp*1+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 1ULL);
x86_l_2536:
	/* 0x2536: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2539:
	/* 0x2539: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_253b:
	/* 0x253b: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2541:
	/* 0x2541: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2546:
	/* 0x2546: jmp    2c47 <generic_fentry_filter_arg+0x2c47> */
	return 11335ULL;
x86_l_254b:
	/* 0x254b: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_254e:
	/* 0x254e: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2552:
	/* 0x2552: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2554:
	/* 0x2554: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2558:
	/* 0x2558: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_255b:
	/* 0x255b: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_255e:
	/* 0x255e: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_2561:
	/* 0x2561: jb     2d3d <generic_fentry_filter_arg+0x2d3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11581ULL;
	}
x86_l_2567:
	/* 0x2567: mov    r8d,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_256c:
	/* 0x256c: mov    edi,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2571:
	/* 0x2571: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2574:
	/* 0x2574: ja     29b9 <generic_fentry_filter_arg+0x29b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10681ULL;
	}
x86_l_257a:
	/* 0x257a: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_2580:
	/* 0x2580: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_2584:
	/* 0x2584: jae    29b9 <generic_fentry_filter_arg+0x29b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10681ULL;
	}
x86_l_258a:
	/* 0x258a: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_258d:
	/* 0x258d: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2591:
	/* 0x2591: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2593:
	/* 0x2593: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_2597:
	/* 0x2597: jmp    29c6 <generic_fentry_filter_arg+0x29c6> */
	return 10694ULL;
x86_l_259c:
	/* 0x259c: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_259e:
	/* 0x259e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25a3:
	/* 0x25a3: ja     25ad <generic_fentry_filter_arg+0x25ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_25ad;
	}
x86_l_25a5:
	/* 0x25a5: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_25a7:
	/* 0x25a7: jbe    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 687ULL;
	}
x86_l_25ad:
	/* 0x25ad: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_25b0:
	/* 0x25b0: jb     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 262ULL;
	}
x86_l_25b6:
	/* 0x25b6: mov    edi,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25bb:
	/* 0x25bb: mov    esi,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
	return 9664ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9664ULL: goto x86_l_25c0;
	case 9667ULL: goto x86_l_25c3;
	case 9673ULL: goto x86_l_25c9;
	case 9679ULL: goto x86_l_25cf;
	case 9683ULL: goto x86_l_25d3;
	case 9689ULL: goto x86_l_25d9;
	case 9691ULL: goto x86_l_25db;
	case 9696ULL: goto x86_l_25e0;
	case 9702ULL: goto x86_l_25e6;
	case 9704ULL: goto x86_l_25e8;
	case 9710ULL: goto x86_l_25ee;
	case 9715ULL: goto x86_l_25f3;
	case 9720ULL: goto x86_l_25f8;
	case 9725ULL: goto x86_l_25fd;
	case 9730ULL: goto x86_l_2602;
	case 9735ULL: goto x86_l_2607;
	case 9739ULL: goto x86_l_260b;
	case 9745ULL: goto x86_l_2611;
	case 9750ULL: goto x86_l_2616;
	case 9755ULL: goto x86_l_261b;
	case 9760ULL: goto x86_l_2620;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9779ULL: goto x86_l_2633;
	case 9785ULL: goto x86_l_2639;
	case 9790ULL: goto x86_l_263e;
	case 9793ULL: goto x86_l_2641;
	case 9797ULL: goto x86_l_2645;
	case 9800ULL: goto x86_l_2648;
	case 9804ULL: goto x86_l_264c;
	case 9807ULL: goto x86_l_264f;
	case 9810ULL: goto x86_l_2652;
	case 9813ULL: goto x86_l_2655;
	case 9819ULL: goto x86_l_265b;
	case 9824ULL: goto x86_l_2660;
	case 9829ULL: goto x86_l_2665;
	case 9832ULL: goto x86_l_2668;
	case 9834ULL: goto x86_l_266a;
	case 9837ULL: goto x86_l_266d;
	case 9843ULL: goto x86_l_2673;
	case 9846ULL: goto x86_l_2676;
	case 9849ULL: goto x86_l_2679;
	case 9852ULL: goto x86_l_267c;
	case 9857ULL: goto x86_l_2681;
	case 9859ULL: goto x86_l_2683;
	case 9864ULL: goto x86_l_2688;
	case 9869ULL: goto x86_l_268d;
	case 9872ULL: goto x86_l_2690;
	case 9876ULL: goto x86_l_2694;
	case 9881ULL: goto x86_l_2699;
	case 9883ULL: goto x86_l_269b;
	case 9887ULL: goto x86_l_269f;
	case 9889ULL: goto x86_l_26a1;
	case 9894ULL: goto x86_l_26a6;
	case 9896ULL: goto x86_l_26a8;
	case 9898ULL: goto x86_l_26aa;
	case 9903ULL: goto x86_l_26af;
	case 9907ULL: goto x86_l_26b3;
	case 9911ULL: goto x86_l_26b7;
	case 9913ULL: goto x86_l_26b9;
	case 9919ULL: goto x86_l_26bf;
	case 9924ULL: goto x86_l_26c4;
	case 9927ULL: goto x86_l_26c7;
	case 9929ULL: goto x86_l_26c9;
	case 9936ULL: goto x86_l_26d0;
	case 9940ULL: goto x86_l_26d4;
	case 9944ULL: goto x86_l_26d8;
	case 9947ULL: goto x86_l_26db;
	case 9949ULL: goto x86_l_26dd;
	case 9952ULL: goto x86_l_26e0;
	case 9957ULL: goto x86_l_26e5;
	case 9962ULL: goto x86_l_26ea;
	case 9968ULL: goto x86_l_26f0;
	case 9970ULL: goto x86_l_26f2;
	case 9976ULL: goto x86_l_26f8;
	case 9979ULL: goto x86_l_26fb;
	case 9985ULL: goto x86_l_2701;
	case 9990ULL: goto x86_l_2706;
	case 9997ULL: goto x86_l_270d;
	case 10002ULL: goto x86_l_2712;
	case 10005ULL: goto x86_l_2715;
	case 10010ULL: goto x86_l_271a;
	case 10015ULL: goto x86_l_271f;
	case 10021ULL: goto x86_l_2725;
	case 10024ULL: goto x86_l_2728;
	case 10030ULL: goto x86_l_272e;
	case 10033ULL: goto x86_l_2731;
	case 10039ULL: goto x86_l_2737;
	case 10044ULL: goto x86_l_273c;
	case 10051ULL: goto x86_l_2743;
	case 10056ULL: goto x86_l_2748;
	case 10059ULL: goto x86_l_274b;
	case 10064ULL: goto x86_l_2750;
	case 10066ULL: goto x86_l_2752;
	case 10069ULL: goto x86_l_2755;
	case 10075ULL: goto x86_l_275b;
	case 10078ULL: goto x86_l_275e;
	case 10084ULL: goto x86_l_2764;
	case 10089ULL: goto x86_l_2769;
	case 10094ULL: goto x86_l_276e;
	case 10097ULL: goto x86_l_2771;
	case 10099ULL: goto x86_l_2773;
	case 10102ULL: goto x86_l_2776;
	case 10108ULL: goto x86_l_277c;
	case 10111ULL: goto x86_l_277f;
	case 10117ULL: goto x86_l_2785;
	case 10120ULL: goto x86_l_2788;
	case 10126ULL: goto x86_l_278e;
	case 10131ULL: goto x86_l_2793;
	case 10135ULL: goto x86_l_2797;
	case 10138ULL: goto x86_l_279a;
	case 10144ULL: goto x86_l_27a0;
	case 10146ULL: goto x86_l_27a2;
	case 10150ULL: goto x86_l_27a6;
	case 10153ULL: goto x86_l_27a9;
	case 10159ULL: goto x86_l_27af;
	case 10162ULL: goto x86_l_27b2;
	case 10168ULL: goto x86_l_27b8;
	case 10173ULL: goto x86_l_27bd;
	case 10176ULL: goto x86_l_27c0;
	case 10178ULL: goto x86_l_27c2;
	case 10181ULL: goto x86_l_27c5;
	case 10184ULL: goto x86_l_27c8;
	case 10186ULL: goto x86_l_27ca;
	case 10190ULL: goto x86_l_27ce;
	case 10193ULL: goto x86_l_27d1;
	case 10198ULL: goto x86_l_27d6;
	case 10204ULL: goto x86_l_27dc;
	case 10209ULL: goto x86_l_27e1;
	case 10212ULL: goto x86_l_27e4;
	case 10218ULL: goto x86_l_27ea;
	case 10221ULL: goto x86_l_27ed;
	case 10227ULL: goto x86_l_27f3;
	case 10230ULL: goto x86_l_27f6;
	case 10232ULL: goto x86_l_27f8;
	case 10235ULL: goto x86_l_27fb;
	case 10241ULL: goto x86_l_2801;
	case 10245ULL: goto x86_l_2805;
	case 10248ULL: goto x86_l_2808;
	case 10254ULL: goto x86_l_280e;
	case 10259ULL: goto x86_l_2813;
	case 10262ULL: goto x86_l_2816;
	case 10267ULL: goto x86_l_281b;
	case 10273ULL: goto x86_l_2821;
	case 10277ULL: goto x86_l_2825;
	case 10280ULL: goto x86_l_2828;
	case 10286ULL: goto x86_l_282e;
	case 10291ULL: goto x86_l_2833;
	case 10294ULL: goto x86_l_2836;
	case 10300ULL: goto x86_l_283c;
	case 10304ULL: goto x86_l_2840;
	case 10307ULL: goto x86_l_2843;
	case 10309ULL: goto x86_l_2845;
	case 10315ULL: goto x86_l_284b;
	case 10320ULL: goto x86_l_2850;
	case 10323ULL: goto x86_l_2853;
	case 10329ULL: goto x86_l_2859;
	case 10333ULL: goto x86_l_285d;
	case 10336ULL: goto x86_l_2860;
	case 10338ULL: goto x86_l_2862;
	case 10344ULL: goto x86_l_2868;
	case 10349ULL: goto x86_l_286d;
	case 10354ULL: goto x86_l_2872;
	case 10359ULL: goto x86_l_2877;
	case 10362ULL: goto x86_l_287a;
	case 10365ULL: goto x86_l_287d;
	case 10370ULL: goto x86_l_2882;
	case 10373ULL: goto x86_l_2885;
	case 10375ULL: goto x86_l_2887;
	case 10378ULL: goto x86_l_288a;
	case 10384ULL: goto x86_l_2890;
	case 10388ULL: goto x86_l_2894;
	case 10391ULL: goto x86_l_2897;
	case 10397ULL: goto x86_l_289d;
	case 10402ULL: goto x86_l_28a2;
	case 10404ULL: goto x86_l_28a4;
	case 10409ULL: goto x86_l_28a9;
	case 10412ULL: goto x86_l_28ac;
	case 10417ULL: goto x86_l_28b1;
	case 10422ULL: goto x86_l_28b6;
	case 10427ULL: goto x86_l_28bb;
	case 10430ULL: goto x86_l_28be;
	case 10436ULL: goto x86_l_28c4;
	case 10439ULL: goto x86_l_28c7;
	case 10445ULL: goto x86_l_28cd;
	case 10450ULL: goto x86_l_28d2;
	case 10457ULL: goto x86_l_28d9;
	case 10462ULL: goto x86_l_28de;
	case 10465ULL: goto x86_l_28e1;
	case 10471ULL: goto x86_l_28e7;
	case 10474ULL: goto x86_l_28ea;
	case 10480ULL: goto x86_l_28f0;
	case 10485ULL: goto x86_l_28f5;
	case 10492ULL: goto x86_l_28fc;
	case 10497ULL: goto x86_l_2901;
	case 10499ULL: goto x86_l_2903;
	case 10501ULL: goto x86_l_2905;
	case 10506ULL: goto x86_l_290a;
	case 10511ULL: goto x86_l_290f;
	case 10516ULL: goto x86_l_2914;
	case 10519ULL: goto x86_l_2917;
	case 10524ULL: goto x86_l_291c;
	case 10529ULL: goto x86_l_2921;
	case 10533ULL: goto x86_l_2925;
	case 10536ULL: goto x86_l_2928;
	case 10538ULL: goto x86_l_292a;
	case 10544ULL: goto x86_l_2930;
	case 10547ULL: goto x86_l_2933;
	case 10553ULL: goto x86_l_2939;
	case 10558ULL: goto x86_l_293e;
	case 10561ULL: goto x86_l_2941;
	case 10567ULL: goto x86_l_2947;
	case 10570ULL: goto x86_l_294a;
	case 10573ULL: goto x86_l_294d;
	case 10579ULL: goto x86_l_2953;
	case 10583ULL: goto x86_l_2957;
	case 10586ULL: goto x86_l_295a;
	case 10588ULL: goto x86_l_295c;
	case 10594ULL: goto x86_l_2962;
	case 10599ULL: goto x86_l_2967;
	case 10603ULL: goto x86_l_296b;
	case 10606ULL: goto x86_l_296e;
	case 10608ULL: goto x86_l_2970;
	case 10614ULL: goto x86_l_2976;
	case 10617ULL: goto x86_l_2979;
	case 10623ULL: goto x86_l_297f;
	case 10628ULL: goto x86_l_2984;
	case 10631ULL: goto x86_l_2987;
	case 10637ULL: goto x86_l_298d;
	case 10640ULL: goto x86_l_2990;
	case 10643ULL: goto x86_l_2993;
	case 10649ULL: goto x86_l_2999;
	case 10653ULL: goto x86_l_299d;
	case 10656ULL: goto x86_l_29a0;
	case 10658ULL: goto x86_l_29a2;
	case 10664ULL: goto x86_l_29a8;
	case 10669ULL: goto x86_l_29ad;
	case 10671ULL: goto x86_l_29af;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10684ULL: goto x86_l_29bc;
	case 10688ULL: goto x86_l_29c0;
	case 10690ULL: goto x86_l_29c2;
	case 10694ULL: goto x86_l_29c6;
	case 10697ULL: goto x86_l_29c9;
	case 10700ULL: goto x86_l_29cc;
	case 10703ULL: goto x86_l_29cf;
	case 10709ULL: goto x86_l_29d5;
	case 10714ULL: goto x86_l_29da;
	case 10719ULL: goto x86_l_29df;
	case 10722ULL: goto x86_l_29e2;
	case 10728ULL: goto x86_l_29e8;
	case 10734ULL: goto x86_l_29ee;
	case 10738ULL: goto x86_l_29f2;
	case 10744ULL: goto x86_l_29f8;
	case 10746ULL: goto x86_l_29fa;
	case 10749ULL: goto x86_l_29fd;
	case 10751ULL: goto x86_l_29ff;
	case 10754ULL: goto x86_l_2a02;
	case 10759ULL: goto x86_l_2a07;
	case 10761ULL: goto x86_l_2a09;
	case 10766ULL: goto x86_l_2a0e;
	case 10768ULL: goto x86_l_2a10;
	case 10770ULL: goto x86_l_2a12;
	case 10776ULL: goto x86_l_2a18;
	case 10779ULL: goto x86_l_2a1b;
	case 10785ULL: goto x86_l_2a21;
	case 10790ULL: goto x86_l_2a26;
	case 10795ULL: goto x86_l_2a2b;
	case 10798ULL: goto x86_l_2a2e;
	case 10804ULL: goto x86_l_2a34;
	case 10810ULL: goto x86_l_2a3a;
	case 10814ULL: goto x86_l_2a3e;
	case 10820ULL: goto x86_l_2a44;
	case 10822ULL: goto x86_l_2a46;
	case 10828ULL: goto x86_l_2a4c;
	case 10830ULL: goto x86_l_2a4e;
	case 10836ULL: goto x86_l_2a54;
	case 10841ULL: goto x86_l_2a59;
	case 10845ULL: goto x86_l_2a5d;
	case 10848ULL: goto x86_l_2a60;
	case 10854ULL: goto x86_l_2a66;
	case 10856ULL: goto x86_l_2a68;
	case 10860ULL: goto x86_l_2a6c;
	case 10863ULL: goto x86_l_2a6f;
	case 10869ULL: goto x86_l_2a75;
	case 10872ULL: goto x86_l_2a78;
	case 10878ULL: goto x86_l_2a7e;
	case 10883ULL: goto x86_l_2a83;
	case 10886ULL: goto x86_l_2a86;
	case 10888ULL: goto x86_l_2a88;
	case 10891ULL: goto x86_l_2a8b;
	case 10894ULL: goto x86_l_2a8e;
	case 10896ULL: goto x86_l_2a90;
	case 10900ULL: goto x86_l_2a94;
	case 10902ULL: goto x86_l_2a96;
	case 10907ULL: goto x86_l_2a9b;
	case 10913ULL: goto x86_l_2aa1;
	case 10918ULL: goto x86_l_2aa6;
	case 10921ULL: goto x86_l_2aa9;
	case 10923ULL: goto x86_l_2aab;
	case 10926ULL: goto x86_l_2aae;
	case 10932ULL: goto x86_l_2ab4;
	case 10935ULL: goto x86_l_2ab7;
	case 10941ULL: goto x86_l_2abd;
	case 10947ULL: goto x86_l_2ac3;
	case 10951ULL: goto x86_l_2ac7;
	case 10957ULL: goto x86_l_2acd;
	case 10961ULL: goto x86_l_2ad1;
	case 10964ULL: goto x86_l_2ad4;
	case 10970ULL: goto x86_l_2ada;
	case 10975ULL: goto x86_l_2adf;
	case 10978ULL: goto x86_l_2ae2;
	case 10983ULL: goto x86_l_2ae7;
	case 10989ULL: goto x86_l_2aed;
	case 10993ULL: goto x86_l_2af1;
	case 10996ULL: goto x86_l_2af4;
	case 11002ULL: goto x86_l_2afa;
	case 11007ULL: goto x86_l_2aff;
	case 11010ULL: goto x86_l_2b02;
	case 11016ULL: goto x86_l_2b08;
	case 11022ULL: goto x86_l_2b0e;
	case 11026ULL: goto x86_l_2b12;
	case 11032ULL: goto x86_l_2b18;
	case 11036ULL: goto x86_l_2b1c;
	case 11039ULL: goto x86_l_2b1f;
	case 11045ULL: goto x86_l_2b25;
	case 11050ULL: goto x86_l_2b2a;
	case 11053ULL: goto x86_l_2b2d;
	case 11056ULL: goto x86_l_2b30;
	case 11059ULL: goto x86_l_2b33;
	case 11064ULL: goto x86_l_2b38;
	case 11067ULL: goto x86_l_2b3b;
	case 11073ULL: goto x86_l_2b41;
	case 11076ULL: goto x86_l_2b44;
	case 11082ULL: goto x86_l_2b4a;
	case 11087ULL: goto x86_l_2b4f;
	case 11094ULL: goto x86_l_2b56;
	case 11099ULL: goto x86_l_2b5b;
	case 11102ULL: goto x86_l_2b5e;
	case 11108ULL: goto x86_l_2b64;
	case 11111ULL: goto x86_l_2b67;
	case 11117ULL: goto x86_l_2b6d;
	case 11122ULL: goto x86_l_2b72;
	case 11129ULL: goto x86_l_2b79;
	case 11134ULL: goto x86_l_2b7e;
	case 11137ULL: goto x86_l_2b81;
	case 11143ULL: goto x86_l_2b87;
	case 11146ULL: goto x86_l_2b8a;
	case 11152ULL: goto x86_l_2b90;
	case 11157ULL: goto x86_l_2b95;
	case 11162ULL: goto x86_l_2b9a;
	case 11167ULL: goto x86_l_2b9f;
	case 11170ULL: goto x86_l_2ba2;
	case 11175ULL: goto x86_l_2ba7;
	case 11178ULL: goto x86_l_2baa;
	case 11184ULL: goto x86_l_2bb0;
	case 11187ULL: goto x86_l_2bb3;
	case 11193ULL: goto x86_l_2bb9;
	case 11197ULL: goto x86_l_2bbd;
	case 11200ULL: goto x86_l_2bc0;
	case 11202ULL: goto x86_l_2bc2;
	case 11208ULL: goto x86_l_2bc8;
	case 11213ULL: goto x86_l_2bcd;
	case 11216ULL: goto x86_l_2bd0;
	case 11222ULL: goto x86_l_2bd6;
	case 11225ULL: goto x86_l_2bd9;
	case 11231ULL: goto x86_l_2bdf;
	case 11235ULL: goto x86_l_2be3;
	case 11238ULL: goto x86_l_2be6;
	case 11240ULL: goto x86_l_2be8;
	case 11246ULL: goto x86_l_2bee;
	case 11251ULL: goto x86_l_2bf3;
	case 11256ULL: goto x86_l_2bf8;
	case 11261ULL: goto x86_l_2bfd;
	case 11266ULL: goto x86_l_2c02;
	case 11271ULL: goto x86_l_2c07;
	case 11276ULL: goto x86_l_2c0c;
	case 11279ULL: goto x86_l_2c0f;
	case 11284ULL: goto x86_l_2c14;
	case 11287ULL: goto x86_l_2c17;
	case 11290ULL: goto x86_l_2c1a;
	case 11294ULL: goto x86_l_2c1e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_25c0:
	/* 0x25c0: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_25c3:
	/* 0x25c3: ja     2a07 <generic_fentry_filter_arg+0x2a07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2a07;
	}
x86_l_25c9:
	/* 0x25c9: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_25cf:
	/* 0x25cf: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_25d3:
	/* 0x25d3: jae    2a07 <generic_fentry_filter_arg+0x2a07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2a07;
	}
x86_l_25d9:
	/* 0x25d9: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_25db:
	/* 0x25db: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25e0:
	/* 0x25e0: jg     2a18 <generic_fentry_filter_arg+0x2a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2a18;
	}
x86_l_25e6:
	/* 0x25e6: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_25e8:
	/* 0x25e8: jle    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 687ULL;
	}
x86_l_25ee:
	/* 0x25ee: jmp    2a18 <generic_fentry_filter_arg+0x2a18> */
	goto x86_l_2a18;
x86_l_25f3:
	/* 0x25f3: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_25f8:
	/* 0x25f8: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25fd:
	/* 0x25fd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2602:
	/* 0x2602: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2607:
	/* 0x2607: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_260b:
	/* 0x260b: jbe    2ed8 <generic_fentry_filter_arg+0x2ed8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11992ULL;
	}
x86_l_2611:
	/* 0x2611: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_2616:
	/* 0x2616: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_261b:
	/* 0x261b: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2620:
	/* 0x2620: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2625:
	/* 0x2625: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_262a:
	/* 0x262a: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_262f:
	/* 0x262f: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2633:
	/* 0x2633: jbe    2ed8 <generic_fentry_filter_arg+0x2ed8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11992ULL;
	}
x86_l_2639:
	/* 0x2639: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_263e:
	/* 0x263e: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_2641:
	/* 0x2641: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2645:
	/* 0x2645: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2648:
	/* 0x2648: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_264c:
	/* 0x264c: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_264f:
	/* 0x264f: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2652:
	/* 0x2652: cmp    esi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 57ULL);
x86_l_2655:
	/* 0x2655: jb     2d3d <generic_fentry_filter_arg+0x2d3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11581ULL;
	}
x86_l_265b:
	/* 0x265b: mov    rdi,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2660:
	/* 0x2660: mov    rsi,QWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2665:
	/* 0x2665: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2668:
	/* 0x2668: je     2673 <generic_fentry_filter_arg+0x2673> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2673;
	}
x86_l_266a:
	/* 0x266a: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_266d:
	/* 0x266d: jne    2b2a <generic_fentry_filter_arg+0x2b2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b2a;
	}
x86_l_2673:
	/* 0x2673: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2676:
	/* 0x2676: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_2679:
	/* 0x2679: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_267c:
	/* 0x267c: jmp    29ff <generic_fentry_filter_arg+0x29ff> */
	goto x86_l_29ff;
x86_l_2681:
	/* 0x2681: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2683:
	/* 0x2683: jmp    299 <generic_fentry_filter_arg+0x299> */
	return 665ULL;
x86_l_2688:
	/* 0x2688: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_268d:
	/* 0x268d: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2690:
	/* 0x2690: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2694:
	/* 0x2694: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2699:
	/* 0x2699: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_269b:
	/* 0x269b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_269f:
	/* 0x269f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26a1:
	/* 0x26a1: movzx  esi,WORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_26a6:
	/* 0x26a6: cmp    esi,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_26a8:
	/* 0x26a8: jbe    26c9 <generic_fentry_filter_arg+0x26c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_26c9;
	}
x86_l_26aa:
	/* 0x26aa: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26af:
	/* 0x26af: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_26b3:
	/* 0x26b3: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_26b7:
	/* 0x26b7: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_26b9:
	/* 0x26b9: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26bf:
	/* 0x26bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26c4:
	/* 0x26c4: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_26c7:
	/* 0x26c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c9:
	/* 0x26c9: mov    eax,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_26d0:
	/* 0x26d0: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_26d4:
	/* 0x26d4: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26d8:
	/* 0x26d8: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_26db:
	/* 0x26db: jg     2712 <generic_fentry_filter_arg+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2712;
	}
x86_l_26dd:
	/* 0x26dd: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26e0:
	/* 0x26e0: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26e5:
	/* 0x26e5: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26ea:
	/* 0x26ea: jg     2b38 <generic_fentry_filter_arg+0x2b38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b38;
	}
x86_l_26f0:
	/* 0x26f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26f2:
	/* 0x26f2: je     2e5d <generic_fentry_filter_arg+0x2e5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11869ULL;
	}
x86_l_26f8:
	/* 0x26f8: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26fb:
	/* 0x26fb: jne    2ef1 <generic_fentry_filter_arg+0x2ef1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12017ULL;
	}
x86_l_2701:
	/* 0x2701: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2706:
	/* 0x2706: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_270d:
	/* 0x270d: jmp    2e93 <generic_fentry_filter_arg+0x2e93> */
	return 11923ULL;
x86_l_2712:
	/* 0x2712: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2715:
	/* 0x2715: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_271a:
	/* 0x271a: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_271f:
	/* 0x271f: jg     2b5b <generic_fentry_filter_arg+0x2b5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b5b;
	}
x86_l_2725:
	/* 0x2725: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2728:
	/* 0x2728: je     2e6b <generic_fentry_filter_arg+0x2e6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11883ULL;
	}
x86_l_272e:
	/* 0x272e: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2731:
	/* 0x2731: jne    2ef1 <generic_fentry_filter_arg+0x2ef1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12017ULL;
	}
x86_l_2737:
	/* 0x2737: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_273c:
	/* 0x273c: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2743:
	/* 0x2743: jmp    2e93 <generic_fentry_filter_arg+0x2e93> */
	return 11923ULL;
x86_l_2748:
	/* 0x2748: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_274b:
	/* 0x274b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2750:
	/* 0x2750: ja     275b <generic_fentry_filter_arg+0x275b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_275b;
	}
x86_l_2752:
	/* 0x2752: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_2755:
	/* 0x2755: jbe    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 687ULL;
	}
x86_l_275b:
	/* 0x275b: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_275e:
	/* 0x275e: jb     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 262ULL;
	}
x86_l_2764:
	/* 0x2764: mov    rsi,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2769:
	/* 0x2769: mov    rdx,QWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_276e:
	/* 0x276e: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2771:
	/* 0x2771: je     277c <generic_fentry_filter_arg+0x277c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_277c;
	}
x86_l_2773:
	/* 0x2773: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2776:
	/* 0x2776: jne    2b7e <generic_fentry_filter_arg+0x2b7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b7e;
	}
x86_l_277c:
	/* 0x277c: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_277f:
	/* 0x277f: jg     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 262ULL;
	}
x86_l_2785:
	/* 0x2785: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2788:
	/* 0x2788: jle    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 687ULL;
	}
x86_l_278e:
	/* 0x278e: jmp    106 <generic_fentry_filter_arg+0x106> */
	return 262ULL;
x86_l_2793:
	/* 0x2793: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2797:
	/* 0x2797: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_279a:
	/* 0x279a: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_27a0:
	/* 0x27a0: jmp    27af <generic_fentry_filter_arg+0x27af> */
	goto x86_l_27af;
x86_l_27a2:
	/* 0x27a2: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27a6:
	/* 0x27a6: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27a9:
	/* 0x27a9: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_27af:
	/* 0x27af: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_27b2:
	/* 0x27b2: jb     322b <generic_fentry_filter_arg+0x322b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12843ULL;
	}
x86_l_27b8:
	/* 0x27b8: mov    rsi,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27bd:
	/* 0x27bd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_27c0:
	/* 0x27c0: jle    27e1 <generic_fentry_filter_arg+0x27e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_27e1;
	}
x86_l_27c2:
	/* 0x27c2: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_27c5:
	/* 0x27c5: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_27c8:
	/* 0x27c8: jae    2813 <generic_fentry_filter_arg+0x2813> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2813;
	}
x86_l_27ca:
	/* 0x27ca: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ce:
	/* 0x27ce: cmp    QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27d1:
	/* 0x27d1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27d6:
	/* 0x27d6: jne    2d6b <generic_fentry_filter_arg+0x2d6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11627ULL;
	}
x86_l_27dc:
	/* 0x27dc: jmp    3115 <generic_fentry_filter_arg+0x3115> */
	return 12565ULL;
x86_l_27e1:
	/* 0x27e1: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27e4:
	/* 0x27e4: je     2882 <generic_fentry_filter_arg+0x2882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2882;
	}
x86_l_27ea:
	/* 0x27ea: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_27ed:
	/* 0x27ed: jne    2d6b <generic_fentry_filter_arg+0x2d6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11627ULL;
	}
x86_l_27f3:
	/* 0x27f3: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_27f6:
	/* 0x27f6: je     2801 <generic_fentry_filter_arg+0x2801> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2801;
	}
x86_l_27f8:
	/* 0x27f8: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_27fb:
	/* 0x27fb: jne    2d5e <generic_fentry_filter_arg+0x2d5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11614ULL;
	}
x86_l_2801:
	/* 0x2801: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2805:
	/* 0x2805: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2808:
	/* 0x2808: jl     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 687ULL;
	}
x86_l_280e:
	/* 0x280e: jmp    2d6b <generic_fentry_filter_arg+0x2d6b> */
	return 11627ULL;
x86_l_2813:
	/* 0x2813: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2816:
	/* 0x2816: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_281b:
	/* 0x281b: jne    2d6b <generic_fentry_filter_arg+0x2d6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11627ULL;
	}
x86_l_2821:
	/* 0x2821: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2825:
	/* 0x2825: test   QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2828:
	/* 0x2828: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_282e:
	/* 0x282e: jmp    2d6b <generic_fentry_filter_arg+0x2d6b> */
	return 11627ULL;
x86_l_2833:
	/* 0x2833: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2836:
	/* 0x2836: jne    2930 <generic_fentry_filter_arg+0x2930> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2930;
	}
x86_l_283c:
	/* 0x283c: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2840:
	/* 0x2840: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2843:
	/* 0x2843: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2845:
	/* 0x2845: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_284b:
	/* 0x284b: jmp    2930 <generic_fentry_filter_arg+0x2930> */
	goto x86_l_2930;
x86_l_2850:
	/* 0x2850: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2853:
	/* 0x2853: jne    2976 <generic_fentry_filter_arg+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2976;
	}
x86_l_2859:
	/* 0x2859: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_285d:
	/* 0x285d: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2860:
	/* 0x2860: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2862:
	/* 0x2862: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_2868:
	/* 0x2868: jmp    2976 <generic_fentry_filter_arg+0x2976> */
	goto x86_l_2976;
x86_l_286d:
	/* 0x286d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2872:
	/* 0x2872: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2877:
	/* 0x2877: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_287a:
	/* 0x287a: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_287d:
	/* 0x287d: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_2882:
	/* 0x2882: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2885:
	/* 0x2885: je     2890 <generic_fentry_filter_arg+0x2890> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2890;
	}
x86_l_2887:
	/* 0x2887: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_288a:
	/* 0x288a: jne    2d4f <generic_fentry_filter_arg+0x2d4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11599ULL;
	}
x86_l_2890:
	/* 0x2890: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2894:
	/* 0x2894: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2897:
	/* 0x2897: jg     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 687ULL;
	}
x86_l_289d:
	/* 0x289d: jmp    2d6b <generic_fentry_filter_arg+0x2d6b> */
	return 11627ULL;
x86_l_28a2:
	/* 0x28a2: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28a4:
	/* 0x28a4: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28a9:
	/* 0x28a9: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_28ac:
	/* 0x28ac: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28b1:
	/* 0x28b1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28b6:
	/* 0x28b6: jmp    318c <generic_fentry_filter_arg+0x318c> */
	return 12684ULL;
x86_l_28bb:
	/* 0x28bb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28be:
	/* 0x28be: je     2cd7 <generic_fentry_filter_arg+0x2cd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11479ULL;
	}
x86_l_28c4:
	/* 0x28c4: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_28c7:
	/* 0x28c7: jne    91e <generic_fentry_filter_arg+0x91e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2334ULL;
	}
x86_l_28cd:
	/* 0x28cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28d2:
	/* 0x28d2: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_28d9:
	/* 0x28d9: jmp    2cf1 <generic_fentry_filter_arg+0x2cf1> */
	return 11505ULL;
x86_l_28de:
	/* 0x28de: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_28e1:
	/* 0x28e1: je     2ce5 <generic_fentry_filter_arg+0x2ce5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11493ULL;
	}
x86_l_28e7:
	/* 0x28e7: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_28ea:
	/* 0x28ea: jne    91e <generic_fentry_filter_arg+0x91e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2334ULL;
	}
x86_l_28f0:
	/* 0x28f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28f5:
	/* 0x28f5: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_28fc:
	/* 0x28fc: jmp    2cf1 <generic_fentry_filter_arg+0x2cf1> */
	return 11505ULL;
x86_l_2901:
	/* 0x2901: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2903:
	/* 0x2903: jmp    290a <generic_fentry_filter_arg+0x290a> */
	goto x86_l_290a;
x86_l_2905:
	/* 0x2905: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_290a:
	/* 0x290a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_290f:
	/* 0x290f: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2914:
	/* 0x2914: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_2917:
	/* 0x2917: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_291c:
	/* 0x291c: jmp    318c <generic_fentry_filter_arg+0x318c> */
	return 12684ULL;
x86_l_2921:
	/* 0x2921: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2925:
	/* 0x2925: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2928:
	/* 0x2928: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_292a:
	/* 0x292a: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_2930:
	/* 0x2930: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2933:
	/* 0x2933: jb     322b <generic_fentry_filter_arg+0x322b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12843ULL;
	}
x86_l_2939:
	/* 0x2939: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_293e:
	/* 0x293e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2941:
	/* 0x2941: jle    2ba7 <generic_fentry_filter_arg+0x2ba7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2ba7;
	}
x86_l_2947:
	/* 0x2947: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_294a:
	/* 0x294a: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_294d:
	/* 0x294d: jae    2dee <generic_fentry_filter_arg+0x2dee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11758ULL;
	}
x86_l_2953:
	/* 0x2953: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2957:
	/* 0x2957: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_295a:
	/* 0x295a: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_295c:
	/* 0x295c: jne    2f5d <generic_fentry_filter_arg+0x2f5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12125ULL;
	}
x86_l_2962:
	/* 0x2962: jmp    3115 <generic_fentry_filter_arg+0x3115> */
	return 12565ULL;
x86_l_2967:
	/* 0x2967: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_296b:
	/* 0x296b: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_296e:
	/* 0x296e: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2970:
	/* 0x2970: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_2976:
	/* 0x2976: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2979:
	/* 0x2979: jb     322b <generic_fentry_filter_arg+0x322b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12843ULL;
	}
x86_l_297f:
	/* 0x297f: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2984:
	/* 0x2984: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2987:
	/* 0x2987: jle    2bcd <generic_fentry_filter_arg+0x2bcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2bcd;
	}
x86_l_298d:
	/* 0x298d: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2990:
	/* 0x2990: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2993:
	/* 0x2993: jae    2e0b <generic_fentry_filter_arg+0x2e0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11787ULL;
	}
x86_l_2999:
	/* 0x2999: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_299d:
	/* 0x299d: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29a0:
	/* 0x29a0: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_29a2:
	/* 0x29a2: jne    2faa <generic_fentry_filter_arg+0x2faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12202ULL;
	}
x86_l_29a8:
	/* 0x29a8: jmp    3115 <generic_fentry_filter_arg+0x3115> */
	return 12565ULL;
x86_l_29ad:
	/* 0x29ad: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29af:
	/* 0x29af: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_29b4:
	/* 0x29b4: jmp    318c <generic_fentry_filter_arg+0x318c> */
	return 12684ULL;
x86_l_29b9:
	/* 0x29b9: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_29bc:
	/* 0x29bc: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_29c0:
	/* 0x29c0: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_29c2:
	/* 0x29c2: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_29c6:
	/* 0x29c6: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_29c9:
	/* 0x29c9: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_29cc:
	/* 0x29cc: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_29cf:
	/* 0x29cf: jb     2d3d <generic_fentry_filter_arg+0x2d3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11581ULL;
	}
x86_l_29d5:
	/* 0x29d5: mov    edi,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29da:
	/* 0x29da: mov    esi,DWORD PTR [r12+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_29df:
	/* 0x29df: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_29e2:
	/* 0x29e2: ja     2d2f <generic_fentry_filter_arg+0x2d2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11567ULL;
	}
x86_l_29e8:
	/* 0x29e8: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_29ee:
	/* 0x29ee: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_29f2:
	/* 0x29f2: jae    2d2f <generic_fentry_filter_arg+0x2d2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11567ULL;
	}
x86_l_29f8:
	/* 0x29f8: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_29fa:
	/* 0x29fa: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_29fd:
	/* 0x29fd: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_29ff:
	/* 0x29ff: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_2a02:
	/* 0x2a02: jmp    2d39 <generic_fentry_filter_arg+0x2d39> */
	return 11577ULL;
x86_l_2a07:
	/* 0x2a07: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2a09:
	/* 0x2a09: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a0e:
	/* 0x2a0e: ja     2a18 <generic_fentry_filter_arg+0x2a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2a18;
	}
x86_l_2a10:
	/* 0x2a10: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_2a12:
	/* 0x2a12: jbe    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 687ULL;
	}
x86_l_2a18:
	/* 0x2a18: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2a1b:
	/* 0x2a1b: jb     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 262ULL;
	}
x86_l_2a21:
	/* 0x2a21: mov    esi,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a26:
	/* 0x2a26: mov    edx,DWORD PTR [r12+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2a2b:
	/* 0x2a2b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2a2e:
	/* 0x2a2e: ja     2e28 <generic_fentry_filter_arg+0x2e28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11816ULL;
	}
x86_l_2a34:
	/* 0x2a34: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2a3a:
	/* 0x2a3a: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2a3e:
	/* 0x2a3e: jae    2e28 <generic_fentry_filter_arg+0x2e28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11816ULL;
	}
x86_l_2a44:
	/* 0x2a44: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2a46:
	/* 0x2a46: jg     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 262ULL;
	}
x86_l_2a4c:
	/* 0x2a4c: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2a4e:
	/* 0x2a4e: jle    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 687ULL;
	}
x86_l_2a54:
	/* 0x2a54: jmp    106 <generic_fentry_filter_arg+0x106> */
	return 262ULL;
x86_l_2a59:
	/* 0x2a59: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a5d:
	/* 0x2a5d: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a60:
	/* 0x2a60: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_2a66:
	/* 0x2a66: jmp    2a75 <generic_fentry_filter_arg+0x2a75> */
	goto x86_l_2a75;
x86_l_2a68:
	/* 0x2a68: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a6c:
	/* 0x2a6c: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a6f:
	/* 0x2a6f: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_2a75:
	/* 0x2a75: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2a78:
	/* 0x2a78: jb     322b <generic_fentry_filter_arg+0x322b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12843ULL;
	}
x86_l_2a7e:
	/* 0x2a7e: mov    esi,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a83:
	/* 0x2a83: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a86:
	/* 0x2a86: jle    2aa6 <generic_fentry_filter_arg+0x2aa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2aa6;
	}
x86_l_2a88:
	/* 0x2a88: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2a8b:
	/* 0x2a8b: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2a8e:
	/* 0x2a8e: jae    2adf <generic_fentry_filter_arg+0x2adf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2adf;
	}
x86_l_2a90:
	/* 0x2a90: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a94:
	/* 0x2a94: cmp    DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a96:
	/* 0x2a96: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a9b:
	/* 0x2a9b: jne    300f <generic_fentry_filter_arg+0x300f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12303ULL;
	}
x86_l_2aa1:
	/* 0x2aa1: jmp    3115 <generic_fentry_filter_arg+0x3115> */
	return 12565ULL;
x86_l_2aa6:
	/* 0x2aa6: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2aa9:
	/* 0x2aa9: je     2aff <generic_fentry_filter_arg+0x2aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aff;
	}
x86_l_2aab:
	/* 0x2aab: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2aae:
	/* 0x2aae: jne    300f <generic_fentry_filter_arg+0x300f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12303ULL;
	}
x86_l_2ab4:
	/* 0x2ab4: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2ab7:
	/* 0x2ab7: ja     3002 <generic_fentry_filter_arg+0x3002> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12290ULL;
	}
x86_l_2abd:
	/* 0x2abd: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2ac3:
	/* 0x2ac3: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2ac7:
	/* 0x2ac7: jae    3002 <generic_fentry_filter_arg+0x3002> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12290ULL;
	}
x86_l_2acd:
	/* 0x2acd: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad1:
	/* 0x2ad1: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad4:
	/* 0x2ad4: jl     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 687ULL;
	}
x86_l_2ada:
	/* 0x2ada: jmp    300f <generic_fentry_filter_arg+0x300f> */
	return 12303ULL;
x86_l_2adf:
	/* 0x2adf: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2ae2:
	/* 0x2ae2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ae7:
	/* 0x2ae7: jne    300f <generic_fentry_filter_arg+0x300f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12303ULL;
	}
x86_l_2aed:
	/* 0x2aed: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2af1:
	/* 0x2af1: test   DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2af4:
	/* 0x2af4: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_2afa:
	/* 0x2afa: jmp    300f <generic_fentry_filter_arg+0x300f> */
	return 12303ULL;
x86_l_2aff:
	/* 0x2aff: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2b02:
	/* 0x2b02: ja     2ff3 <generic_fentry_filter_arg+0x2ff3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12275ULL;
	}
x86_l_2b08:
	/* 0x2b08: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2b0e:
	/* 0x2b0e: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2b12:
	/* 0x2b12: jae    2ff3 <generic_fentry_filter_arg+0x2ff3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12275ULL;
	}
x86_l_2b18:
	/* 0x2b18: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b1c:
	/* 0x2b1c: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b1f:
	/* 0x2b1f: jg     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 687ULL;
	}
x86_l_2b25:
	/* 0x2b25: jmp    300f <generic_fentry_filter_arg+0x300f> */
	return 12303ULL;
x86_l_2b2a:
	/* 0x2b2a: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2b2d:
	/* 0x2b2d: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2b30:
	/* 0x2b30: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_2b33:
	/* 0x2b33: jmp    2d36 <generic_fentry_filter_arg+0x2d36> */
	return 11574ULL;
x86_l_2b38:
	/* 0x2b38: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b3b:
	/* 0x2b3b: je     2e79 <generic_fentry_filter_arg+0x2e79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11897ULL;
	}
x86_l_2b41:
	/* 0x2b41: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2b44:
	/* 0x2b44: jne    2ef1 <generic_fentry_filter_arg+0x2ef1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12017ULL;
	}
x86_l_2b4a:
	/* 0x2b4a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b4f:
	/* 0x2b4f: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_2b56:
	/* 0x2b56: jmp    2e93 <generic_fentry_filter_arg+0x2e93> */
	return 11923ULL;
x86_l_2b5b:
	/* 0x2b5b: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2b5e:
	/* 0x2b5e: je     2e87 <generic_fentry_filter_arg+0x2e87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11911ULL;
	}
x86_l_2b64:
	/* 0x2b64: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2b67:
	/* 0x2b67: jne    2ef1 <generic_fentry_filter_arg+0x2ef1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12017ULL;
	}
x86_l_2b6d:
	/* 0x2b6d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b72:
	/* 0x2b72: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2b79:
	/* 0x2b79: jmp    2e93 <generic_fentry_filter_arg+0x2e93> */
	return 11923ULL;
x86_l_2b7e:
	/* 0x2b7e: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2b81:
	/* 0x2b81: ja     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 262ULL;
	}
x86_l_2b87:
	/* 0x2b87: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2b8a:
	/* 0x2b8a: jbe    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 687ULL;
	}
x86_l_2b90:
	/* 0x2b90: jmp    106 <generic_fentry_filter_arg+0x106> */
	return 262ULL;
x86_l_2b95:
	/* 0x2b95: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b9a:
	/* 0x2b9a: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b9f:
	/* 0x2b9f: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_2ba2:
	/* 0x2ba2: jmp    296 <generic_fentry_filter_arg+0x296> */
	return 662ULL;
x86_l_2ba7:
	/* 0x2ba7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2baa:
	/* 0x2baa: je     2f4e <generic_fentry_filter_arg+0x2f4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12110ULL;
	}
x86_l_2bb0:
	/* 0x2bb0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2bb3:
	/* 0x2bb3: jne    2f5d <generic_fentry_filter_arg+0x2f5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12125ULL;
	}
x86_l_2bb9:
	/* 0x2bb9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bbd:
	/* 0x2bbd: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2bc0:
	/* 0x2bc0: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2bc2:
	/* 0x2bc2: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_2bc8:
	/* 0x2bc8: jmp    2f5d <generic_fentry_filter_arg+0x2f5d> */
	return 12125ULL;
x86_l_2bcd:
	/* 0x2bcd: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bd0:
	/* 0x2bd0: je     2f9b <generic_fentry_filter_arg+0x2f9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12187ULL;
	}
x86_l_2bd6:
	/* 0x2bd6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2bd9:
	/* 0x2bd9: jne    2faa <generic_fentry_filter_arg+0x2faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12202ULL;
	}
x86_l_2bdf:
	/* 0x2bdf: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2be3:
	/* 0x2be3: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2be6:
	/* 0x2be6: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2be8:
	/* 0x2be8: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_2bee:
	/* 0x2bee: jmp    2faa <generic_fentry_filter_arg+0x2faa> */
	return 12202ULL;
x86_l_2bf3:
	/* 0x2bf3: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2bf8:
	/* 0x2bf8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bfd:
	/* 0x2bfd: jmp    318c <generic_fentry_filter_arg+0x318c> */
	return 12684ULL;
x86_l_2c02:
	/* 0x2c02: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c07:
	/* 0x2c07: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c0c:
	/* 0x2c0c: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_2c0f:
	/* 0x2c0f: jmp    296 <generic_fentry_filter_arg+0x296> */
	return 662ULL;
x86_l_2c14:
	/* 0x2c14: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_2c17:
	/* 0x2c17: mov    WORD PTR [rcx],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c1a:
	/* 0x2c1a: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2c1e:
	/* 0x2c1e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 11299ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11299ULL: goto x86_l_2c23;
	case 11301ULL: goto x86_l_2c25;
	case 11305ULL: goto x86_l_2c29;
	case 11307ULL: goto x86_l_2c2b;
	case 11309ULL: goto x86_l_2c2d;
	case 11311ULL: goto x86_l_2c2f;
	case 11319ULL: goto x86_l_2c37;
	case 11322ULL: goto x86_l_2c3a;
	case 11324ULL: goto x86_l_2c3c;
	case 11330ULL: goto x86_l_2c42;
	case 11335ULL: goto x86_l_2c47;
	case 11337ULL: goto x86_l_2c49;
	case 11345ULL: goto x86_l_2c51;
	case 11347ULL: goto x86_l_2c53;
	case 11351ULL: goto x86_l_2c57;
	case 11355ULL: goto x86_l_2c5b;
	case 11359ULL: goto x86_l_2c5f;
	case 11362ULL: goto x86_l_2c62;
	case 11364ULL: goto x86_l_2c64;
	case 11367ULL: goto x86_l_2c67;
	case 11373ULL: goto x86_l_2c6d;
	case 11375ULL: goto x86_l_2c6f;
	case 11381ULL: goto x86_l_2c75;
	case 11384ULL: goto x86_l_2c78;
	case 11390ULL: goto x86_l_2c7e;
	case 11395ULL: goto x86_l_2c83;
	case 11402ULL: goto x86_l_2c8a;
	case 11407ULL: goto x86_l_2c8f;
	case 11410ULL: goto x86_l_2c92;
	case 11416ULL: goto x86_l_2c98;
	case 11419ULL: goto x86_l_2c9b;
	case 11425ULL: goto x86_l_2ca1;
	case 11428ULL: goto x86_l_2ca4;
	case 11434ULL: goto x86_l_2caa;
	case 11439ULL: goto x86_l_2caf;
	case 11446ULL: goto x86_l_2cb6;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11463ULL: goto x86_l_2cc7;
	case 11465ULL: goto x86_l_2cc9;
	case 11470ULL: goto x86_l_2cce;
	case 11477ULL: goto x86_l_2cd5;
	case 11479ULL: goto x86_l_2cd7;
	case 11484ULL: goto x86_l_2cdc;
	case 11491ULL: goto x86_l_2ce3;
	case 11493ULL: goto x86_l_2ce5;
	case 11498ULL: goto x86_l_2cea;
	case 11505ULL: goto x86_l_2cf1;
	case 11510ULL: goto x86_l_2cf6;
	case 11512ULL: goto x86_l_2cf8;
	case 11515ULL: goto x86_l_2cfb;
	case 11517ULL: goto x86_l_2cfd;
	case 11522ULL: goto x86_l_2d02;
	case 11525ULL: goto x86_l_2d05;
	case 11528ULL: goto x86_l_2d08;
	case 11530ULL: goto x86_l_2d0a;
	case 11532ULL: goto x86_l_2d0c;
	case 11535ULL: goto x86_l_2d0f;
	case 11538ULL: goto x86_l_2d12;
	case 11540ULL: goto x86_l_2d14;
	case 11542ULL: goto x86_l_2d16;
	case 11547ULL: goto x86_l_2d1b;
	case 11552ULL: goto x86_l_2d20;
	case 11557ULL: goto x86_l_2d25;
	case 11562ULL: goto x86_l_2d2a;
	case 11567ULL: goto x86_l_2d2f;
	case 11569ULL: goto x86_l_2d31;
	case 11572ULL: goto x86_l_2d34;
	case 11574ULL: goto x86_l_2d36;
	case 11577ULL: goto x86_l_2d39;
	case 11579ULL: goto x86_l_2d3b;
	case 11581ULL: goto x86_l_2d3d;
	case 11586ULL: goto x86_l_2d42;
	case 11588ULL: goto x86_l_2d44;
	case 11594ULL: goto x86_l_2d4a;
	case 11599ULL: goto x86_l_2d4f;
	case 11603ULL: goto x86_l_2d53;
	case 11606ULL: goto x86_l_2d56;
	case 11612ULL: goto x86_l_2d5c;
	case 11614ULL: goto x86_l_2d5e;
	case 11618ULL: goto x86_l_2d62;
	case 11621ULL: goto x86_l_2d65;
	case 11627ULL: goto x86_l_2d6b;
	case 11630ULL: goto x86_l_2d6e;
	case 11636ULL: goto x86_l_2d74;
	case 11641ULL: goto x86_l_2d79;
	case 11644ULL: goto x86_l_2d7c;
	case 11646ULL: goto x86_l_2d7e;
	case 11649ULL: goto x86_l_2d81;
	case 11652ULL: goto x86_l_2d84;
	case 11654ULL: goto x86_l_2d86;
	case 11657ULL: goto x86_l_2d89;
	case 11663ULL: goto x86_l_2d8f;
	case 11666ULL: goto x86_l_2d92;
	case 11672ULL: goto x86_l_2d98;
	case 11676ULL: goto x86_l_2d9c;
	case 11679ULL: goto x86_l_2d9f;
	case 11685ULL: goto x86_l_2da5;
	case 11690ULL: goto x86_l_2daa;
	case 11693ULL: goto x86_l_2dad;
	case 11699ULL: goto x86_l_2db3;
	case 11702ULL: goto x86_l_2db6;
	case 11708ULL: goto x86_l_2dbc;
	case 11711ULL: goto x86_l_2dbf;
	case 11713ULL: goto x86_l_2dc1;
	case 11716ULL: goto x86_l_2dc4;
	case 11722ULL: goto x86_l_2dca;
	case 11726ULL: goto x86_l_2dce;
	case 11729ULL: goto x86_l_2dd1;
	case 11735ULL: goto x86_l_2dd7;
	case 11740ULL: goto x86_l_2ddc;
	case 11744ULL: goto x86_l_2de0;
	case 11747ULL: goto x86_l_2de3;
	case 11753ULL: goto x86_l_2de9;
	case 11758ULL: goto x86_l_2dee;
	case 11761ULL: goto x86_l_2df1;
	case 11767ULL: goto x86_l_2df7;
	case 11771ULL: goto x86_l_2dfb;
	case 11774ULL: goto x86_l_2dfe;
	case 11776ULL: goto x86_l_2e00;
	case 11782ULL: goto x86_l_2e06;
	case 11787ULL: goto x86_l_2e0b;
	case 11790ULL: goto x86_l_2e0e;
	case 11796ULL: goto x86_l_2e14;
	case 11800ULL: goto x86_l_2e18;
	case 11803ULL: goto x86_l_2e1b;
	case 11805ULL: goto x86_l_2e1d;
	case 11811ULL: goto x86_l_2e23;
	case 11816ULL: goto x86_l_2e28;
	case 11818ULL: goto x86_l_2e2a;
	case 11824ULL: goto x86_l_2e30;
	case 11826ULL: goto x86_l_2e32;
	case 11832ULL: goto x86_l_2e38;
	case 11837ULL: goto x86_l_2e3d;
	case 11840ULL: goto x86_l_2e40;
	case 11844ULL: goto x86_l_2e44;
	case 11846ULL: goto x86_l_2e46;
	case 11849ULL: goto x86_l_2e49;
	case 11855ULL: goto x86_l_2e4f;
	case 11858ULL: goto x86_l_2e52;
	case 11864ULL: goto x86_l_2e58;
	case 11869ULL: goto x86_l_2e5d;
	case 11874ULL: goto x86_l_2e62;
	case 11881ULL: goto x86_l_2e69;
	case 11883ULL: goto x86_l_2e6b;
	case 11888ULL: goto x86_l_2e70;
	case 11895ULL: goto x86_l_2e77;
	case 11897ULL: goto x86_l_2e79;
	case 11902ULL: goto x86_l_2e7e;
	case 11909ULL: goto x86_l_2e85;
	case 11911ULL: goto x86_l_2e87;
	case 11916ULL: goto x86_l_2e8c;
	case 11923ULL: goto x86_l_2e93;
	case 11928ULL: goto x86_l_2e98;
	case 11930ULL: goto x86_l_2e9a;
	case 11933ULL: goto x86_l_2e9d;
	case 11935ULL: goto x86_l_2e9f;
	case 11940ULL: goto x86_l_2ea4;
	case 11943ULL: goto x86_l_2ea7;
	case 11948ULL: goto x86_l_2eac;
	case 11950ULL: goto x86_l_2eae;
	case 11952ULL: goto x86_l_2eb0;
	case 11955ULL: goto x86_l_2eb3;
	case 11958ULL: goto x86_l_2eb6;
	case 11960ULL: goto x86_l_2eb8;
	case 11962ULL: goto x86_l_2eba;
	case 11967ULL: goto x86_l_2ebf;
	case 11972ULL: goto x86_l_2ec4;
	case 11977ULL: goto x86_l_2ec9;
	case 11982ULL: goto x86_l_2ece;
	case 11986ULL: goto x86_l_2ed2;
	case 11992ULL: goto x86_l_2ed8;
	case 12002ULL: goto x86_l_2ee2;
	case 12006ULL: goto x86_l_2ee6;
	case 12012ULL: goto x86_l_2eec;
	case 12017ULL: goto x86_l_2ef1;
	case 12019ULL: goto x86_l_2ef3;
	case 12024ULL: goto x86_l_2ef8;
	case 12029ULL: goto x86_l_2efd;
	case 12033ULL: goto x86_l_2f01;
	case 12035ULL: goto x86_l_2f03;
	case 12040ULL: goto x86_l_2f08;
	case 12043ULL: goto x86_l_2f0b;
	case 12049ULL: goto x86_l_2f11;
	case 12052ULL: goto x86_l_2f14;
	case 12058ULL: goto x86_l_2f1a;
	case 12063ULL: goto x86_l_2f1f;
	case 12070ULL: goto x86_l_2f26;
	case 12075ULL: goto x86_l_2f2b;
	case 12078ULL: goto x86_l_2f2e;
	case 12084ULL: goto x86_l_2f34;
	case 12087ULL: goto x86_l_2f37;
	case 12093ULL: goto x86_l_2f3d;
	case 12098ULL: goto x86_l_2f42;
	case 12105ULL: goto x86_l_2f49;
	case 12110ULL: goto x86_l_2f4e;
	case 12114ULL: goto x86_l_2f52;
	case 12117ULL: goto x86_l_2f55;
	case 12119ULL: goto x86_l_2f57;
	case 12125ULL: goto x86_l_2f5d;
	case 12128ULL: goto x86_l_2f60;
	case 12134ULL: goto x86_l_2f66;
	case 12139ULL: goto x86_l_2f6b;
	case 12142ULL: goto x86_l_2f6e;
	case 12148ULL: goto x86_l_2f74;
	case 12151ULL: goto x86_l_2f77;
	case 12154ULL: goto x86_l_2f7a;
	case 12160ULL: goto x86_l_2f80;
	case 12163ULL: goto x86_l_2f83;
	case 12169ULL: goto x86_l_2f89;
	case 12172ULL: goto x86_l_2f8c;
	case 12178ULL: goto x86_l_2f92;
	case 12182ULL: goto x86_l_2f96;
	case 12185ULL: goto x86_l_2f99;
	case 12187ULL: goto x86_l_2f9b;
	case 12191ULL: goto x86_l_2f9f;
	case 12194ULL: goto x86_l_2fa2;
	case 12196ULL: goto x86_l_2fa4;
	case 12202ULL: goto x86_l_2faa;
	case 12205ULL: goto x86_l_2fad;
	case 12211ULL: goto x86_l_2fb3;
	case 12216ULL: goto x86_l_2fb8;
	case 12219ULL: goto x86_l_2fbb;
	case 12225ULL: goto x86_l_2fc1;
	case 12228ULL: goto x86_l_2fc4;
	case 12231ULL: goto x86_l_2fc7;
	case 12237ULL: goto x86_l_2fcd;
	case 12240ULL: goto x86_l_2fd0;
	case 12246ULL: goto x86_l_2fd6;
	case 12249ULL: goto x86_l_2fd9;
	case 12255ULL: goto x86_l_2fdf;
	case 12259ULL: goto x86_l_2fe3;
	case 12262ULL: goto x86_l_2fe6;
	case 12264ULL: goto x86_l_2fe8;
	case 12270ULL: goto x86_l_2fee;
	case 12275ULL: goto x86_l_2ff3;
	case 12279ULL: goto x86_l_2ff7;
	case 12282ULL: goto x86_l_2ffa;
	case 12288ULL: goto x86_l_3000;
	case 12290ULL: goto x86_l_3002;
	case 12294ULL: goto x86_l_3006;
	case 12297ULL: goto x86_l_3009;
	case 12303ULL: goto x86_l_300f;
	case 12306ULL: goto x86_l_3012;
	case 12312ULL: goto x86_l_3018;
	case 12317ULL: goto x86_l_301d;
	case 12320ULL: goto x86_l_3020;
	case 12322ULL: goto x86_l_3022;
	case 12325ULL: goto x86_l_3025;
	case 12328ULL: goto x86_l_3028;
	case 12330ULL: goto x86_l_302a;
	case 12333ULL: goto x86_l_302d;
	case 12339ULL: goto x86_l_3033;
	case 12342ULL: goto x86_l_3036;
	case 12348ULL: goto x86_l_303c;
	case 12352ULL: goto x86_l_3040;
	case 12354ULL: goto x86_l_3042;
	case 12360ULL: goto x86_l_3048;
	case 12365ULL: goto x86_l_304d;
	case 12368ULL: goto x86_l_3050;
	case 12370ULL: goto x86_l_3052;
	case 12373ULL: goto x86_l_3055;
	case 12379ULL: goto x86_l_305b;
	case 12382ULL: goto x86_l_305e;
	case 12388ULL: goto x86_l_3064;
	case 12393ULL: goto x86_l_3069;
	case 12396ULL: goto x86_l_306c;
	case 12402ULL: goto x86_l_3072;
	case 12406ULL: goto x86_l_3076;
	case 12408ULL: goto x86_l_3078;
	case 12414ULL: goto x86_l_307e;
	case 12419ULL: goto x86_l_3083;
	case 12423ULL: goto x86_l_3087;
	case 12425ULL: goto x86_l_3089;
	case 12431ULL: goto x86_l_308f;
	case 12436ULL: goto x86_l_3094;
	case 12439ULL: goto x86_l_3097;
	case 12445ULL: goto x86_l_309d;
	case 12450ULL: goto x86_l_30a2;
	case 12453ULL: goto x86_l_30a5;
	case 12459ULL: goto x86_l_30ab;
	case 12463ULL: goto x86_l_30af;
	case 12465ULL: goto x86_l_30b1;
	case 12471ULL: goto x86_l_30b7;
	case 12476ULL: goto x86_l_30bc;
	case 12479ULL: goto x86_l_30bf;
	case 12485ULL: goto x86_l_30c5;
	case 12488ULL: goto x86_l_30c8;
	case 12494ULL: goto x86_l_30ce;
	case 12498ULL: goto x86_l_30d2;
	case 12501ULL: goto x86_l_30d5;
	case 12503ULL: goto x86_l_30d7;
	case 12506ULL: goto x86_l_30da;
	case 12512ULL: goto x86_l_30e0;
	case 12515ULL: goto x86_l_30e3;
	case 12521ULL: goto x86_l_30e9;
	case 12525ULL: goto x86_l_30ed;
	case 12528ULL: goto x86_l_30f0;
	case 12530ULL: goto x86_l_30f2;
	case 12536ULL: goto x86_l_30f8;
	case 12541ULL: goto x86_l_30fd;
	case 12545ULL: goto x86_l_3101;
	case 12548ULL: goto x86_l_3104;
	case 12550ULL: goto x86_l_3106;
	case 12554ULL: goto x86_l_310a;
	case 12557ULL: goto x86_l_310d;
	case 12559ULL: goto x86_l_310f;
	case 12565ULL: goto x86_l_3115;
	case 12567ULL: goto x86_l_3117;
	case 12570ULL: goto x86_l_311a;
	case 12573ULL: goto x86_l_311d;
	case 12578ULL: goto x86_l_3122;
	case 12583ULL: goto x86_l_3127;
	case 12590ULL: goto x86_l_312e;
	case 12592ULL: goto x86_l_3130;
	case 12597ULL: goto x86_l_3135;
	case 12604ULL: goto x86_l_313c;
	case 12606ULL: goto x86_l_313e;
	case 12611ULL: goto x86_l_3143;
	case 12618ULL: goto x86_l_314a;
	case 12620ULL: goto x86_l_314c;
	case 12625ULL: goto x86_l_3151;
	case 12632ULL: goto x86_l_3158;
	case 12637ULL: goto x86_l_315d;
	case 12639ULL: goto x86_l_315f;
	case 12642ULL: goto x86_l_3162;
	case 12644ULL: goto x86_l_3164;
	case 12649ULL: goto x86_l_3169;
	case 12652ULL: goto x86_l_316c;
	case 12655ULL: goto x86_l_316f;
	case 12657ULL: goto x86_l_3171;
	case 12659ULL: goto x86_l_3173;
	case 12662ULL: goto x86_l_3176;
	case 12665ULL: goto x86_l_3179;
	case 12667ULL: goto x86_l_317b;
	case 12669ULL: goto x86_l_317d;
	case 12674ULL: goto x86_l_3182;
	case 12679ULL: goto x86_l_3187;
	case 12684ULL: goto x86_l_318c;
	case 12689ULL: goto x86_l_3191;
	case 12693ULL: goto x86_l_3195;
	case 12699ULL: goto x86_l_319b;
	case 12709ULL: goto x86_l_31a5;
	case 12713ULL: goto x86_l_31a9;
	case 12718ULL: goto x86_l_31ae;
	case 12724ULL: goto x86_l_31b4;
	case 12726ULL: goto x86_l_31b6;
	case 12729ULL: goto x86_l_31b9;
	case 12732ULL: goto x86_l_31bc;
	case 12735ULL: goto x86_l_31bf;
	case 12740ULL: goto x86_l_31c4;
	case 12744ULL: goto x86_l_31c8;
	case 12747ULL: goto x86_l_31cb;
	case 12753ULL: goto x86_l_31d1;
	case 12755ULL: goto x86_l_31d3;
	case 12758ULL: goto x86_l_31d6;
	case 12764ULL: goto x86_l_31dc;
	case 12766ULL: goto x86_l_31de;
	case 12770ULL: goto x86_l_31e2;
	case 12773ULL: goto x86_l_31e5;
	case 12775ULL: goto x86_l_31e7;
	case 12779ULL: goto x86_l_31eb;
	case 12782ULL: goto x86_l_31ee;
	case 12784ULL: goto x86_l_31f0;
	case 12790ULL: goto x86_l_31f6;
	case 12792ULL: goto x86_l_31f8;
	case 12794ULL: goto x86_l_31fa;
	case 12799ULL: goto x86_l_31ff;
	case 12804ULL: goto x86_l_3204;
	case 12807ULL: goto x86_l_3207;
	case 12812ULL: goto x86_l_320c;
	case 12817ULL: goto x86_l_3211;
	case 12821ULL: goto x86_l_3215;
	case 12823ULL: goto x86_l_3217;
	case 12829ULL: goto x86_l_321d;
	case 12831ULL: goto x86_l_321f;
	case 12835ULL: goto x86_l_3223;
	case 12837ULL: goto x86_l_3225;
	case 12843ULL: goto x86_l_322b;
	case 12846ULL: goto x86_l_322e;
	case 12849ULL: goto x86_l_3231;
	case 12855ULL: goto x86_l_3237;
	case 12860ULL: goto x86_l_323c;
	case 12865ULL: goto x86_l_3241;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2c23:
	/* 0x2c23: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2c25:
	/* 0x2c25: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c29:
	/* 0x2c29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c2b:
	/* 0x2c2b: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_2c2d:
	/* 0x2c2d: jbe    2c53 <generic_fentry_filter_arg+0x2c53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2c53;
	}
x86_l_2c2f:
	/* 0x2c2f: lea    rdi,[rbp*1+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 2ULL);
x86_l_2c37:
	/* 0x2c37: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c3a:
	/* 0x2c3a: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c3c:
	/* 0x2c3c: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c42:
	/* 0x2c42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c47:
	/* 0x2c47: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_2c49:
	/* 0x2c49: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2c51:
	/* 0x2c51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c53:
	/* 0x2c53: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c57:
	/* 0x2c57: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2c5b:
	/* 0x2c5b: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c5f:
	/* 0x2c5f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2c62:
	/* 0x2c62: jg     2c8f <generic_fentry_filter_arg+0x2c8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2c8f;
	}
x86_l_2c64:
	/* 0x2c64: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c67:
	/* 0x2c67: jg     2f08 <generic_fentry_filter_arg+0x2f08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f08;
	}
x86_l_2c6d:
	/* 0x2c6d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c6f:
	/* 0x2c6f: je     3122 <generic_fentry_filter_arg+0x3122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3122;
	}
x86_l_2c75:
	/* 0x2c75: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c78:
	/* 0x2c78: jne    317b <generic_fentry_filter_arg+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_317b;
	}
x86_l_2c7e:
	/* 0x2c7e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c83:
	/* 0x2c83: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2c8a:
	/* 0x2c8a: jmp    3158 <generic_fentry_filter_arg+0x3158> */
	goto x86_l_3158;
x86_l_2c8f:
	/* 0x2c8f: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2c92:
	/* 0x2c92: jg     2f2b <generic_fentry_filter_arg+0x2f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f2b;
	}
x86_l_2c98:
	/* 0x2c98: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c9b:
	/* 0x2c9b: je     3130 <generic_fentry_filter_arg+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3130;
	}
x86_l_2ca1:
	/* 0x2ca1: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2ca4:
	/* 0x2ca4: jne    317b <generic_fentry_filter_arg+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_317b;
	}
x86_l_2caa:
	/* 0x2caa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2caf:
	/* 0x2caf: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2cb6:
	/* 0x2cb6: jmp    3158 <generic_fentry_filter_arg+0x3158> */
	goto x86_l_3158;
x86_l_2cbb:
	/* 0x2cbb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cc0:
	/* 0x2cc0: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2cc7:
	/* 0x2cc7: jmp    2cf1 <generic_fentry_filter_arg+0x2cf1> */
	goto x86_l_2cf1;
x86_l_2cc9:
	/* 0x2cc9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cce:
	/* 0x2cce: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2cd5:
	/* 0x2cd5: jmp    2cf1 <generic_fentry_filter_arg+0x2cf1> */
	goto x86_l_2cf1;
x86_l_2cd7:
	/* 0x2cd7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cdc:
	/* 0x2cdc: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2ce3:
	/* 0x2ce3: jmp    2cf1 <generic_fentry_filter_arg+0x2cf1> */
	goto x86_l_2cf1;
x86_l_2ce5:
	/* 0x2ce5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cea:
	/* 0x2cea: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2cf1:
	/* 0x2cf1: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2cf6:
	/* 0x2cf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cf8:
	/* 0x2cf8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cfb:
	/* 0x2cfb: je     2d14 <generic_fentry_filter_arg+0x2d14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d14;
	}
x86_l_2cfd:
	/* 0x2cfd: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2d02:
	/* 0x2d02: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d05:
	/* 0x2d05: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2d08:
	/* 0x2d08: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2d0a:
	/* 0x2d0a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d0c:
	/* 0x2d0c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d0f:
	/* 0x2d0f: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_2d12:
	/* 0x2d12: jmp    2d16 <generic_fentry_filter_arg+0x2d16> */
	goto x86_l_2d16;
x86_l_2d14:
	/* 0x2d14: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d16:
	/* 0x2d16: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d1b:
	/* 0x2d1b: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d20:
	/* 0x2d20: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d25:
	/* 0x2d25: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d2a:
	/* 0x2d2a: jmp    d1a <generic_fentry_filter_arg+0xd1a> */
	return 3354ULL;
x86_l_2d2f:
	/* 0x2d2f: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2d31:
	/* 0x2d31: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2d34:
	/* 0x2d34: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2d36:
	/* 0x2d36: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_2d39:
	/* 0x2d39: and    dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2d3b:
	/* 0x2d3b: or     al,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2d3d:
	/* 0x2d3d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d42:
	/* 0x2d42: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2d44:
	/* 0x2d44: je     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 687ULL;
	}
x86_l_2d4a:
	/* 0x2d4a: jmp    106 <generic_fentry_filter_arg+0x106> */
	return 262ULL;
x86_l_2d4f:
	/* 0x2d4f: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d53:
	/* 0x2d53: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d56:
	/* 0x2d56: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_2d5c:
	/* 0x2d5c: jmp    2d6b <generic_fentry_filter_arg+0x2d6b> */
	goto x86_l_2d6b;
x86_l_2d5e:
	/* 0x2d5e: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d62:
	/* 0x2d62: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d65:
	/* 0x2d65: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_2d6b:
	/* 0x2d6b: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2d6e:
	/* 0x2d6e: jb     322b <generic_fentry_filter_arg+0x322b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_322b;
	}
x86_l_2d74:
	/* 0x2d74: mov    rdx,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d79:
	/* 0x2d79: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d7c:
	/* 0x2d7c: jle    2daa <generic_fentry_filter_arg+0x2daa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2daa;
	}
x86_l_2d7e:
	/* 0x2d7e: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2d81:
	/* 0x2d81: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2d84:
	/* 0x2d84: jb     2ddc <generic_fentry_filter_arg+0x2ddc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ddc;
	}
x86_l_2d86:
	/* 0x2d86: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2d89:
	/* 0x2d89: je     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 687ULL;
	}
x86_l_2d8f:
	/* 0x2d8f: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2d92:
	/* 0x2d92: jne    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 262ULL;
	}
x86_l_2d98:
	/* 0x2d98: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d9c:
	/* 0x2d9c: test   QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d9f:
	/* 0x2d9f: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_2da5:
	/* 0x2da5: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_2daa:
	/* 0x2daa: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2dad:
	/* 0x2dad: je     2e3d <generic_fentry_filter_arg+0x2e3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e3d;
	}
x86_l_2db3:
	/* 0x2db3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2db6:
	/* 0x2db6: jne    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 262ULL;
	}
x86_l_2dbc:
	/* 0x2dbc: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2dbf:
	/* 0x2dbf: je     2dca <generic_fentry_filter_arg+0x2dca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dca;
	}
x86_l_2dc1:
	/* 0x2dc1: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2dc4:
	/* 0x2dc4: jne    31c4 <generic_fentry_filter_arg+0x31c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31c4;
	}
x86_l_2dca:
	/* 0x2dca: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dce:
	/* 0x2dce: cmp    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dd1:
	/* 0x2dd1: jl     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 687ULL;
	}
x86_l_2dd7:
	/* 0x2dd7: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_2ddc:
	/* 0x2ddc: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2de0:
	/* 0x2de0: cmp    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2de3:
	/* 0x2de3: je     3115 <generic_fentry_filter_arg+0x3115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3115;
	}
x86_l_2de9:
	/* 0x2de9: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_2dee:
	/* 0x2dee: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2df1:
	/* 0x2df1: jne    2f5d <generic_fentry_filter_arg+0x2f5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f5d;
	}
x86_l_2df7:
	/* 0x2df7: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dfb:
	/* 0x2dfb: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2dfe:
	/* 0x2dfe: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2e00:
	/* 0x2e00: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_2e06:
	/* 0x2e06: jmp    2f5d <generic_fentry_filter_arg+0x2f5d> */
	goto x86_l_2f5d;
x86_l_2e0b:
	/* 0x2e0b: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2e0e:
	/* 0x2e0e: jne    2faa <generic_fentry_filter_arg+0x2faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2faa;
	}
x86_l_2e14:
	/* 0x2e14: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e18:
	/* 0x2e18: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e1b:
	/* 0x2e1b: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2e1d:
	/* 0x2e1d: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_2e23:
	/* 0x2e23: jmp    2faa <generic_fentry_filter_arg+0x2faa> */
	goto x86_l_2faa;
x86_l_2e28:
	/* 0x2e28: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2e2a:
	/* 0x2e2a: ja     106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 262ULL;
	}
x86_l_2e30:
	/* 0x2e30: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2e32:
	/* 0x2e32: jbe    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 687ULL;
	}
x86_l_2e38:
	/* 0x2e38: jmp    106 <generic_fentry_filter_arg+0x106> */
	return 262ULL;
x86_l_2e3d:
	/* 0x2e3d: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2e40:
	/* 0x2e40: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e44:
	/* 0x2e44: je     2e4f <generic_fentry_filter_arg+0x2e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e4f;
	}
x86_l_2e46:
	/* 0x2e46: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2e49:
	/* 0x2e49: jne    31d3 <generic_fentry_filter_arg+0x31d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31d3;
	}
x86_l_2e4f:
	/* 0x2e4f: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e52:
	/* 0x2e52: jg     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 687ULL;
	}
x86_l_2e58:
	/* 0x2e58: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_2e5d:
	/* 0x2e5d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e62:
	/* 0x2e62: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2e69:
	/* 0x2e69: jmp    2e93 <generic_fentry_filter_arg+0x2e93> */
	goto x86_l_2e93;
x86_l_2e6b:
	/* 0x2e6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e70:
	/* 0x2e70: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2e77:
	/* 0x2e77: jmp    2e93 <generic_fentry_filter_arg+0x2e93> */
	goto x86_l_2e93;
x86_l_2e79:
	/* 0x2e79: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e7e:
	/* 0x2e7e: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2e85:
	/* 0x2e85: jmp    2e93 <generic_fentry_filter_arg+0x2e93> */
	goto x86_l_2e93;
x86_l_2e87:
	/* 0x2e87: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e8c:
	/* 0x2e8c: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2e93:
	/* 0x2e93: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2e98:
	/* 0x2e98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e9a:
	/* 0x2e9a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e9d:
	/* 0x2e9d: je     2eb8 <generic_fentry_filter_arg+0x2eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eb8;
	}
x86_l_2e9f:
	/* 0x2e9f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2ea4:
	/* 0x2ea4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2ea7:
	/* 0x2ea7: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2eac:
	/* 0x2eac: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2eae:
	/* 0x2eae: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2eb0:
	/* 0x2eb0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2eb3:
	/* 0x2eb3: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_2eb6:
	/* 0x2eb6: jmp    2eba <generic_fentry_filter_arg+0x2eba> */
	goto x86_l_2eba;
x86_l_2eb8:
	/* 0x2eb8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2eba:
	/* 0x2eba: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ebf:
	/* 0x2ebf: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ec4:
	/* 0x2ec4: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ec9:
	/* 0x2ec9: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ece:
	/* 0x2ece: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2ed2:
	/* 0x2ed2: ja     29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 670ULL;
	}
x86_l_2ed8:
	/* 0x2ed8: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_2ee2:
	/* 0x2ee2: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2ee6:
	/* 0x2ee6: jb     31b4 <generic_fentry_filter_arg+0x31b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_31b4;
	}
x86_l_2eec:
	/* 0x2eec: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_2ef1:
	/* 0x2ef1: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ef3:
	/* 0x2ef3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ef8:
	/* 0x2ef8: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2efd:
	/* 0x2efd: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2f01:
	/* 0x2f01: jbe    2ed8 <generic_fentry_filter_arg+0x2ed8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2ed8;
	}
x86_l_2f03:
	/* 0x2f03: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_2f08:
	/* 0x2f08: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f0b:
	/* 0x2f0b: je     313e <generic_fentry_filter_arg+0x313e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_313e;
	}
x86_l_2f11:
	/* 0x2f11: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2f14:
	/* 0x2f14: jne    317b <generic_fentry_filter_arg+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_317b;
	}
x86_l_2f1a:
	/* 0x2f1a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f1f:
	/* 0x2f1f: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_2f26:
	/* 0x2f26: jmp    3158 <generic_fentry_filter_arg+0x3158> */
	goto x86_l_3158;
x86_l_2f2b:
	/* 0x2f2b: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2f2e:
	/* 0x2f2e: je     314c <generic_fentry_filter_arg+0x314c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_314c;
	}
x86_l_2f34:
	/* 0x2f34: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2f37:
	/* 0x2f37: jne    317b <generic_fentry_filter_arg+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_317b;
	}
x86_l_2f3d:
	/* 0x2f3d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f42:
	/* 0x2f42: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2f49:
	/* 0x2f49: jmp    3158 <generic_fentry_filter_arg+0x3158> */
	goto x86_l_3158;
x86_l_2f4e:
	/* 0x2f4e: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f52:
	/* 0x2f52: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2f55:
	/* 0x2f55: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2f57:
	/* 0x2f57: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_2f5d:
	/* 0x2f5d: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_2f60:
	/* 0x2f60: jb     322b <generic_fentry_filter_arg+0x322b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_322b;
	}
x86_l_2f66:
	/* 0x2f66: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2f6b:
	/* 0x2f6b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f6e:
	/* 0x2f6e: jle    30bc <generic_fentry_filter_arg+0x30bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_30bc;
	}
x86_l_2f74:
	/* 0x2f74: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2f77:
	/* 0x2f77: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2f7a:
	/* 0x2f7a: jb     30fd <generic_fentry_filter_arg+0x30fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_30fd;
	}
x86_l_2f80:
	/* 0x2f80: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2f83:
	/* 0x2f83: je     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 687ULL;
	}
x86_l_2f89:
	/* 0x2f89: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2f8c:
	/* 0x2f8c: jne    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 262ULL;
	}
x86_l_2f92:
	/* 0x2f92: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f96:
	/* 0x2f96: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2f99:
	/* 0x2f99: jmp    2fe6 <generic_fentry_filter_arg+0x2fe6> */
	goto x86_l_2fe6;
x86_l_2f9b:
	/* 0x2f9b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f9f:
	/* 0x2f9f: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fa2:
	/* 0x2fa2: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2fa4:
	/* 0x2fa4: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_2faa:
	/* 0x2faa: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_2fad:
	/* 0x2fad: jb     322b <generic_fentry_filter_arg+0x322b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_322b;
	}
x86_l_2fb3:
	/* 0x2fb3: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2fb8:
	/* 0x2fb8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2fbb:
	/* 0x2fbb: jle    30d7 <generic_fentry_filter_arg+0x30d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_30d7;
	}
x86_l_2fc1:
	/* 0x2fc1: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2fc4:
	/* 0x2fc4: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2fc7:
	/* 0x2fc7: jb     3106 <generic_fentry_filter_arg+0x3106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3106;
	}
x86_l_2fcd:
	/* 0x2fcd: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2fd0:
	/* 0x2fd0: je     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 687ULL;
	}
x86_l_2fd6:
	/* 0x2fd6: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2fd9:
	/* 0x2fd9: jne    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 262ULL;
	}
x86_l_2fdf:
	/* 0x2fdf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fe3:
	/* 0x2fe3: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fe6:
	/* 0x2fe6: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2fe8:
	/* 0x2fe8: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_2fee:
	/* 0x2fee: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_2ff3:
	/* 0x2ff3: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ff7:
	/* 0x2ff7: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ffa:
	/* 0x2ffa: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_3000:
	/* 0x3000: jmp    300f <generic_fentry_filter_arg+0x300f> */
	goto x86_l_300f;
x86_l_3002:
	/* 0x3002: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3006:
	/* 0x3006: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3009:
	/* 0x3009: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_300f:
	/* 0x300f: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_3012:
	/* 0x3012: jb     322b <generic_fentry_filter_arg+0x322b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_322b;
	}
x86_l_3018:
	/* 0x3018: mov    edx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_301d:
	/* 0x301d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3020:
	/* 0x3020: jle    304d <generic_fentry_filter_arg+0x304d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_304d;
	}
x86_l_3022:
	/* 0x3022: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3025:
	/* 0x3025: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3028:
	/* 0x3028: jb     3083 <generic_fentry_filter_arg+0x3083> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3083;
	}
x86_l_302a:
	/* 0x302a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_302d:
	/* 0x302d: je     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 687ULL;
	}
x86_l_3033:
	/* 0x3033: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3036:
	/* 0x3036: jne    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 262ULL;
	}
x86_l_303c:
	/* 0x303c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3040:
	/* 0x3040: test   DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3042:
	/* 0x3042: jne    2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 687ULL;
	}
x86_l_3048:
	/* 0x3048: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_304d:
	/* 0x304d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3050:
	/* 0x3050: je     3094 <generic_fentry_filter_arg+0x3094> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3094;
	}
x86_l_3052:
	/* 0x3052: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3055:
	/* 0x3055: jne    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 262ULL;
	}
x86_l_305b:
	/* 0x305b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_305e:
	/* 0x305e: ja     3211 <generic_fentry_filter_arg+0x3211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3211;
	}
x86_l_3064:
	/* 0x3064: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_3069:
	/* 0x3069: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_306c:
	/* 0x306c: jae    3211 <generic_fentry_filter_arg+0x3211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3211;
	}
x86_l_3072:
	/* 0x3072: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3076:
	/* 0x3076: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3078:
	/* 0x3078: jl     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 687ULL;
	}
x86_l_307e:
	/* 0x307e: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_3083:
	/* 0x3083: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3087:
	/* 0x3087: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3089:
	/* 0x3089: je     3115 <generic_fentry_filter_arg+0x3115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3115;
	}
x86_l_308f:
	/* 0x308f: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_3094:
	/* 0x3094: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_3097:
	/* 0x3097: ja     321f <generic_fentry_filter_arg+0x321f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_321f;
	}
x86_l_309d:
	/* 0x309d: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_30a2:
	/* 0x30a2: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_30a5:
	/* 0x30a5: jae    321f <generic_fentry_filter_arg+0x321f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_321f;
	}
x86_l_30ab:
	/* 0x30ab: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30af:
	/* 0x30af: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30b1:
	/* 0x30b1: jg     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 687ULL;
	}
x86_l_30b7:
	/* 0x30b7: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_30bc:
	/* 0x30bc: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30bf:
	/* 0x30bf: je     31de <generic_fentry_filter_arg+0x31de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31de;
	}
x86_l_30c5:
	/* 0x30c5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_30c8:
	/* 0x30c8: jne    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 262ULL;
	}
x86_l_30ce:
	/* 0x30ce: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30d2:
	/* 0x30d2: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_30d5:
	/* 0x30d5: jmp    30f0 <generic_fentry_filter_arg+0x30f0> */
	goto x86_l_30f0;
x86_l_30d7:
	/* 0x30d7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30da:
	/* 0x30da: je     31e7 <generic_fentry_filter_arg+0x31e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31e7;
	}
x86_l_30e0:
	/* 0x30e0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_30e3:
	/* 0x30e3: jne    106 <generic_fentry_filter_arg+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 262ULL;
	}
x86_l_30e9:
	/* 0x30e9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30ed:
	/* 0x30ed: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30f0:
	/* 0x30f0: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_30f2:
	/* 0x30f2: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_30f8:
	/* 0x30f8: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_30fd:
	/* 0x30fd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3101:
	/* 0x3101: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3104:
	/* 0x3104: jmp    310d <generic_fentry_filter_arg+0x310d> */
	goto x86_l_310d;
x86_l_3106:
	/* 0x3106: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_310a:
	/* 0x310a: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_310d:
	/* 0x310d: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_310f:
	/* 0x310f: jne    322b <generic_fentry_filter_arg+0x322b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_322b;
	}
x86_l_3115:
	/* 0x3115: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3117:
	/* 0x3117: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_311a:
	/* 0x311a: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_311d:
	/* 0x311d: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_3122:
	/* 0x3122: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3127:
	/* 0x3127: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_312e:
	/* 0x312e: jmp    3158 <generic_fentry_filter_arg+0x3158> */
	goto x86_l_3158;
x86_l_3130:
	/* 0x3130: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3135:
	/* 0x3135: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_313c:
	/* 0x313c: jmp    3158 <generic_fentry_filter_arg+0x3158> */
	goto x86_l_3158;
x86_l_313e:
	/* 0x313e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3143:
	/* 0x3143: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_314a:
	/* 0x314a: jmp    3158 <generic_fentry_filter_arg+0x3158> */
	goto x86_l_3158;
x86_l_314c:
	/* 0x314c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3151:
	/* 0x3151: mov    rdi,QWORD PTR [rip+0x1bbc8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_3158:
	/* 0x3158: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_315d:
	/* 0x315d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_315f:
	/* 0x315f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3162:
	/* 0x3162: je     317b <generic_fentry_filter_arg+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_317b;
	}
x86_l_3164:
	/* 0x3164: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3169:
	/* 0x3169: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_316c:
	/* 0x316c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_316f:
	/* 0x316f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3171:
	/* 0x3171: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3173:
	/* 0x3173: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3176:
	/* 0x3176: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_3179:
	/* 0x3179: jmp    317d <generic_fentry_filter_arg+0x317d> */
	goto x86_l_317d;
x86_l_317b:
	/* 0x317b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_317d:
	/* 0x317d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3182:
	/* 0x3182: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3187:
	/* 0x3187: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_318c:
	/* 0x318c: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3191:
	/* 0x3191: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_3195:
	/* 0x3195: ja     299 <generic_fentry_filter_arg+0x299> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 665ULL;
	}
x86_l_319b:
	/* 0x319b: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_31a5:
	/* 0x31a5: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_31a9:
	/* 0x31a9: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_31ae:
	/* 0x31ae: jae    29e <generic_fentry_filter_arg+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 670ULL;
	}
x86_l_31b4:
	/* 0x31b4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31b6:
	/* 0x31b6: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_31b9:
	/* 0x31b9: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_31bc:
	/* 0x31bc: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_31bf:
	/* 0x31bf: jmp    29e <generic_fentry_filter_arg+0x29e> */
	return 670ULL;
x86_l_31c4:
	/* 0x31c4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31c8:
	/* 0x31c8: cmp    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31cb:
	/* 0x31cb: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_31d1:
	/* 0x31d1: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_31d3:
	/* 0x31d3: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31d6:
	/* 0x31d6: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_31dc:
	/* 0x31dc: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_31de:
	/* 0x31de: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31e2:
	/* 0x31e2: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_31e5:
	/* 0x31e5: jmp    31ee <generic_fentry_filter_arg+0x31ee> */
	goto x86_l_31ee;
x86_l_31e7:
	/* 0x31e7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31eb:
	/* 0x31eb: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31ee:
	/* 0x31ee: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_31f0:
	/* 0x31f0: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_31f6:
	/* 0x31f6: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_31f8:
	/* 0x31f8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31fa:
	/* 0x31fa: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31ff:
	/* 0x31ff: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3204:
	/* 0x3204: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_3207:
	/* 0x3207: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_320c:
	/* 0x320c: jmp    d1a <generic_fentry_filter_arg+0xd1a> */
	return 3354ULL;
x86_l_3211:
	/* 0x3211: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3215:
	/* 0x3215: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3217:
	/* 0x3217: jb     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 687ULL;
	}
x86_l_321d:
	/* 0x321d: jmp    322b <generic_fentry_filter_arg+0x322b> */
	goto x86_l_322b;
x86_l_321f:
	/* 0x321f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3223:
	/* 0x3223: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3225:
	/* 0x3225: ja     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 687ULL;
	}
x86_l_322b:
	/* 0x322b: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_322e:
	/* 0x322e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3231:
	/* 0x3231: je     2af <generic_fentry_filter_arg+0x2af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 687ULL;
	}
x86_l_3237:
	/* 0x3237: jmp    106 <generic_fentry_filter_arg+0x106> */
	return 262ULL;
x86_l_323c:
	/* 0x323c: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_3241:
	/* 0x3241: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
	return 12868ULL;
}

static __noinline __u64 tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12868ULL: goto x86_l_3244;
	case 12870ULL: goto x86_l_3246;
	case 12871ULL: goto x86_l_3247;
	case 12873ULL: goto x86_l_3249;
	case 12875ULL: goto x86_l_324b;
	case 12878ULL: goto x86_l_324e;
	case 12881ULL: goto x86_l_3251;
	case 12884ULL: goto x86_l_3254;
	case 12886ULL: goto x86_l_3256;
	case 12889ULL: goto x86_l_3259;
	case 12893ULL: goto x86_l_325d;
	case 12896ULL: goto x86_l_3260;
	case 12898ULL: goto x86_l_3262;
	case 12903ULL: goto x86_l_3267;
	case 12906ULL: goto x86_l_326a;
	case 12908ULL: goto x86_l_326c;
	case 12913ULL: goto x86_l_3271;
	case 12917ULL: goto x86_l_3275;
	case 12920ULL: goto x86_l_3278;
	case 12923ULL: goto x86_l_327b;
	case 12927ULL: goto x86_l_327f;
	case 12931ULL: goto x86_l_3283;
	case 12935ULL: goto x86_l_3287;
	case 12938ULL: goto x86_l_328a;
	case 12942ULL: goto x86_l_328e;
	case 12946ULL: goto x86_l_3292;
	case 12950ULL: goto x86_l_3296;
	case 12953ULL: goto x86_l_3299;
	case 12955ULL: goto x86_l_329b;
	case 12959ULL: goto x86_l_329f;
	case 12963ULL: goto x86_l_32a3;
	case 12966ULL: goto x86_l_32a6;
	case 12968ULL: goto x86_l_32a8;
	case 12970ULL: goto x86_l_32aa;
	case 12972ULL: goto x86_l_32ac;
	case 12973ULL: goto x86_l_32ad;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3244:
	/* 0x3244: je     32ad <native_bpf_strncasestr+0x71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ad;
	}
x86_l_3246:
	/* 0x3246: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3247:
	/* 0x3247: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3249:
	/* 0x3249: jmp    3256 <native_bpf_strncasestr+0x1a> */
	goto x86_l_3256;
x86_l_324b:
	/* 0x324b: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_324e:
	/* 0x324e: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3251:
	/* 0x3251: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3254:
	/* 0x3254: je     32ac <native_bpf_strncasestr+0x70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ac;
	}
x86_l_3256:
	/* 0x3256: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3259:
	/* 0x3259: lea    r9,[rcx+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_325d:
	/* 0x325d: cmp    r9,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RDX, X86_WIDTH_64);
x86_l_3260:
	/* 0x3260: jae    324b <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_324b;
	}
x86_l_3262:
	/* 0x3262: movsx  r9d,BYTE PTR [rsi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_3267:
	/* 0x3267: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_326a:
	/* 0x326a: je     32aa <native_bpf_strncasestr+0x6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32aa;
	}
x86_l_326c:
	/* 0x326c: movsx  r10d,BYTE PTR [rdi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_3271:
	/* 0x3271: lea    r11d,[r10-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_3275:
	/* 0x3275: mov    ebx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R10, X86_WIDTH_32);
x86_l_3278:
	/* 0x3278: or     ebx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_327b:
	/* 0x327b: cmp    r11d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 26ULL);
x86_l_327f:
	/* 0x327f: cmovae ebx,r10d */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R10, X86_WIDTH_32, X86_CC_AE);
x86_l_3283:
	/* 0x3283: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_3287:
	/* 0x3287: mov    r11d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_32);
x86_l_328a:
	/* 0x328a: or     r11d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_328e:
	/* 0x328e: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_3292:
	/* 0x3292: cmovae r11d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_3296:
	/* 0x3296: cmp    ebx,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R11, X86_WIDTH_32);
x86_l_3299:
	/* 0x3299: jne    324b <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_324b;
	}
x86_l_329b:
	/* 0x329b: lea    r9,[r8+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_329f:
	/* 0x329f: cmp    r8,0x63 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 99ULL);
x86_l_32a3:
	/* 0x32a3: mov    r8,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_64);
x86_l_32a6:
	/* 0x32a6: jb     3259 <native_bpf_strncasestr+0x1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3259;
	}
x86_l_32a8:
	/* 0x32a8: jmp    324b <native_bpf_strncasestr+0xf> */
	goto x86_l_324b;
x86_l_32aa:
	/* 0x32aa: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_32ac:
	/* 0x32ac: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_32ad:
	/* 0x32ad: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12432U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1741ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1747ULL && __x86_pc <= 3349ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3354ULL && __x86_pc <= 4950ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4954ULL && __x86_pc <= 6526ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6531ULL && __x86_pc <= 8098ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8102ULL && __x86_pc <= 9659ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9664ULL && __x86_pc <= 11294ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11299ULL && __x86_pc <= 12865ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 12868ULL && __x86_pc <= 12973ULL)
			__x86_pc = tetragon_bpf_generic_fentry_v53_generic_fentry_filter_arg_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
